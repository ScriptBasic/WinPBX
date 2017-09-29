' ########################################################################################
' Microsoft Windows
' File: CertEnroll.inc
' Library name: CERTENROLLLib
' Version: 1.0, Locale ID = 0
' Library GUID: {728AB348-217D-11DA-B2A4-000E7BBB2B09}
' Path: C:\Windows\system32\CertEnroll.dll
' Contents: CertEnroll 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTENROLL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "certcli.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {884E2013-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CAlternativeName1 = "X509Enrollment.CAlternativeName.1"
' CLSID = {884E2014-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CAlternativeNames1 = "X509Enrollment.CAlternativeNames.1"
' CLSID = {884E2002-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CBinaryConverter1 = "X509Enrollment.CBinaryConverter.1"
' CLSID = {884E201F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertificatePolicies1 = "X509Enrollment.CCertificatePolicies.1"
' CLSID = {884E201E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertificatePolicy1 = "X509Enrollment.CCertificatePolicy.1"
' CLSID = {884E202F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertProperties1 = "X509Enrollment.CCertProperties.1"
' CLSID = {884E202E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertProperty1 = "X509Enrollment.CCertProperty.1"
' CLSID = {884E2037-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyArchived1 = "X509Enrollment.CCertPropertyArchived.1"
' CLSID = {884E203B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyArchivedKeyHash1 = "X509Enrollment.CCertPropertyArchivedKeyHash.1"
' CLSID = {884E2032-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyAutoEnroll1 = "X509Enrollment.CCertPropertyAutoEnroll.1"
' CLSID = {884E2038-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyBackedUp1 = "X509Enrollment.CCertPropertyBackedUp.1"
' CLSID = {884E2031-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyDescription1 = "X509Enrollment.CCertPropertyDescription.1"
' CLSID = {884E2039-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyEnrollment1 = "X509Enrollment.CCertPropertyEnrollment.1"
' CLSID = {884E2030-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyFriendlyName1 = "X509Enrollment.CCertPropertyFriendlyName.1"
' CLSID = {884E2036-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyKeyProvInfo1 = "X509Enrollment.CCertPropertyKeyProvInfo.1"
' CLSID = {884E203A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyRenewal1 = "X509Enrollment.CCertPropertyRenewal.1"
' CLSID = {884E2033-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyRequestOriginator1 = "X509Enrollment.CCertPropertyRequestOriginator.1"
' CLSID = {884E2034-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertySHA1Hash1 = "X509Enrollment.CCertPropertySHA1Hash.1"
' CLSID = {884E202C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCryptAttribute1 = "X509Enrollment.CCryptAttribute.1"
' CLSID = {884E202D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCryptAttributes1 = "X509Enrollment.CCryptAttributes.1"
' CLSID = {884E2007-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspInformation1 = "X509Enrollment.CCspInformation.1"
' CLSID = {884E2008-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspInformations1 = "X509Enrollment.CCspInformations.1"
' CLSID = {884E2009-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspStatus1 = "X509Enrollment.CCspStatus.1"
' CLSID = {884E2000-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CObjectId1 = "X509Enrollment.CObjectId.1"
' CLSID = {884E2001-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CObjectIds1 = "X509Enrollment.CObjectIds.1"
' CLSID = {884E201C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CPolicyQualifier1 = "X509Enrollment.CPolicyQualifier.1"
' CLSID = {884E201D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CPolicyQualifiers1 = "X509Enrollment.CPolicyQualifiers.1"
' CLSID = {884E203D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSignerCertificate1 = "X509Enrollment.CSignerCertificate.1"
' CLSID = {884E201A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSmimeCapabilities1 = "X509Enrollment.CSmimeCapabilities.1"
' CLSID = {884E2019-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSmimeCapability1 = "X509Enrollment.CSmimeCapability.1"
' CLSID = {884E2003-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX500DistinguishedName1 = "X509Enrollment.CX500DistinguishedName.1"
' CLSID = {884E2022-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Attribute1 = "X509Enrollment.CX509Attribute.1"
' CLSID = {884E2027-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeArchiveKey1 = "X509Enrollment.CX509AttributeArchiveKey.1"
' CLSID = {884E2028-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeArchiveKeyHash1 = "X509Enrollment.CX509AttributeArchiveKeyHash.1"
' CLSID = {884E2025-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeClientId1 = "X509Enrollment.CX509AttributeClientId.1"
' CLSID = {884E202B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeCspProvider1 = "X509Enrollment.CX509AttributeCspProvider.1"
' CLSID = {884E2024-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeExtensions1 = "X509Enrollment.CX509AttributeExtensions.1"
' CLSID = {884E202A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeOSVersion1 = "X509Enrollment.CX509AttributeOSVersion.1"
' CLSID = {884E2026-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeRenewalCertificate1 = "X509Enrollment.CX509AttributeRenewalCertificate.1"
' CLSID = {884E2023-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Attributes1 = "X509Enrollment.CX509Attributes.1"
' CLSID = {884E2043-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestCertificate1 = "X509Enrollment.CX509CertificateRequestCertificate.1"
' CLSID = {884E2045-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestCmc1 = "X509Enrollment.CX509CertificateRequestCmc.1"
' CLSID = {884E2042-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestPkcs101 = "X509Enrollment.CX509CertificateRequestPkcs10.1"
' CLSID = {884E2044-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestPkcs71 = "X509Enrollment.CX509CertificateRequestPkcs7.1"
' CLSID = {884E2046-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Enrollment1 = "X509Enrollment.CX509Enrollment.1"
' CLSID = {884E2049-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509EnrollmentWebClassFactory1 = "X509Enrollment.CX509EnrollmentWebClassFactory.1"
' CLSID = {884E200D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Extension1 = "X509Enrollment.CX509Extension.1"
' CLSID = {884E2015-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionAlternativeNames1 = "X509Enrollment.CX509ExtensionAlternativeNames.1"
' CLSID = {884E2018-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionAuthorityKeyIdentifier1 = "X509Enrollment.CX509ExtensionAuthorityKeyIdentifier.1"
' CLSID = {884E2016-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionBasicConstraints1 = "X509Enrollment.CX509ExtensionBasicConstraints.1"
' CLSID = {884E2020-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionCertificatePolicies1 = "X509Enrollment.CX509ExtensionCertificatePolicies.1"
' CLSID = {884E2010-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionEnhancedKeyUsage1 = "X509Enrollment.CX509ExtensionEnhancedKeyUsage.1"
' CLSID = {884E200F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionKeyUsage1 = "X509Enrollment.CX509ExtensionKeyUsage.1"
' CLSID = {884E2021-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionMSApplicationPolicies1 = "X509Enrollment.CX509ExtensionMSApplicationPolicies.1"
' CLSID = {884E200E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Extensions1 = "X509Enrollment.CX509Extensions.1"
' CLSID = {884E201B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionSmimeCapabilities1 = "X509Enrollment.CX509ExtensionSmimeCapabilities.1"
' CLSID = {884E2017-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionSubjectKeyIdentifier1 = "X509Enrollment.CX509ExtensionSubjectKeyIdentifier.1"
' CLSID = {884E2012-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionTemplate1 = "X509Enrollment.CX509ExtensionTemplate.1"
' CLSID = {884E2011-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionTemplateName1 = "X509Enrollment.CX509ExtensionTemplateName.1"
' CLSID = {884E203F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509NameValuePair1 = "X509Enrollment.CX509NameValuePair.1"
' CLSID = {884E200C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509PrivateKey1 = "X509Enrollment.CX509PrivateKey.1"
' CLSID = {884E200B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509PublicKey1 = "X509Enrollment.CX509PublicKey.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {884E2013-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CAlternativeName = "X509Enrollment.CAlternativeName"
' CLSID = {884E2014-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CAlternativeNames = "X509Enrollment.CAlternativeNames"
' CLSID = {884E2002-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CBinaryConverter = "X509Enrollment.CBinaryConverter"
' CLSID = {884E201F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertificatePolicies = "X509Enrollment.CCertificatePolicies"
' CLSID = {884E201E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertificatePolicy = "X509Enrollment.CCertificatePolicy"
' CLSID = {884E202F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertProperties = "X509Enrollment.CCertProperties"
' CLSID = {884E202E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertProperty = "X509Enrollment.CCertProperty"
' CLSID = {884E2037-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyArchived = "X509Enrollment.CCertPropertyArchived"
' CLSID = {884E203B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyArchivedKeyHash = "X509Enrollment.CCertPropertyArchivedKeyHash"
' CLSID = {884E2032-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyAutoEnroll = "X509Enrollment.CCertPropertyAutoEnroll"
' CLSID = {884E2038-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyBackedUp = "X509Enrollment.CCertPropertyBackedUp"
' CLSID = {884E2031-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyDescription = "X509Enrollment.CCertPropertyDescription"
' CLSID = {884E2039-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyEnrollment = "X509Enrollment.CCertPropertyEnrollment"
' CLSID = {884E2030-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyFriendlyName = "X509Enrollment.CCertPropertyFriendlyName"
' CLSID = {884E2036-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyKeyProvInfo = "X509Enrollment.CCertPropertyKeyProvInfo"
' CLSID = {884E203A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyRenewal = "X509Enrollment.CCertPropertyRenewal"
' CLSID = {884E2033-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertyRequestOriginator = "X509Enrollment.CCertPropertyRequestOriginator"
' CLSID = {884E2034-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCertPropertySHA1Hash = "X509Enrollment.CCertPropertySHA1Hash"
' CLSID = {884E202C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCryptAttribute = "X509Enrollment.CCryptAttribute"
' CLSID = {884E202D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCryptAttributes = "X509Enrollment.CCryptAttributes"
' CLSID = {884E2007-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspInformation = "X509Enrollment.CCspInformation"
' CLSID = {884E2008-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspInformations = "X509Enrollment.CCspInformations"
' CLSID = {884E2009-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CCspStatus = "X509Enrollment.CCspStatus"
' CLSID = {884E2000-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CObjectId = "X509Enrollment.CObjectId"
' CLSID = {884E2001-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CObjectIds = "X509Enrollment.CObjectIds"
' CLSID = {884E201C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CPolicyQualifier = "X509Enrollment.CPolicyQualifier"
' CLSID = {884E201D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CPolicyQualifiers = "X509Enrollment.CPolicyQualifiers"
' CLSID = {884E203D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSignerCertificate = "X509Enrollment.CSignerCertificate"
' CLSID = {884E201A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSmimeCapabilities = "X509Enrollment.CSmimeCapabilities"
' CLSID = {884E2019-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CSmimeCapability = "X509Enrollment.CSmimeCapability"
' CLSID = {884E2003-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX500DistinguishedName = "X509Enrollment.CX500DistinguishedName"
' CLSID = {884E2022-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Attribute = "X509Enrollment.CX509Attribute"
' CLSID = {884E2027-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeArchiveKey = "X509Enrollment.CX509AttributeArchiveKey"
' CLSID = {884E2028-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeArchiveKeyHash = "X509Enrollment.CX509AttributeArchiveKeyHash"
' CLSID = {884E2025-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeClientId = "X509Enrollment.CX509AttributeClientId"
' CLSID = {884E202B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeCspProvider = "X509Enrollment.CX509AttributeCspProvider"
' CLSID = {884E2024-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeExtensions = "X509Enrollment.CX509AttributeExtensions"
' CLSID = {884E202A-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeOSVersion = "X509Enrollment.CX509AttributeOSVersion"
' CLSID = {884E2026-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509AttributeRenewalCertificate = "X509Enrollment.CX509AttributeRenewalCertificate"
' CLSID = {884E2023-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Attributes = "X509Enrollment.CX509Attributes"
' CLSID = {884E2043-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestCertificate = "X509Enrollment.CX509CertificateRequestCertificate"
' CLSID = {884E2045-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestCmc = "X509Enrollment.CX509CertificateRequestCmc"
' CLSID = {884E2042-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestPkcs10 = "X509Enrollment.CX509CertificateRequestPkcs10"
' CLSID = {884E2044-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509CertificateRequestPkcs7 = "X509Enrollment.CX509CertificateRequestPkcs7"
' CLSID = {884E2046-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Enrollment = "X509Enrollment.CX509Enrollment"
' CLSID = {884E2049-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509EnrollmentWebClassFactory = "X509Enrollment.CX509EnrollmentWebClassFactory"
' CLSID = {884E200D-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Extension = "X509Enrollment.CX509Extension"
' CLSID = {884E2015-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionAlternativeNames = "X509Enrollment.CX509ExtensionAlternativeNames"
' CLSID = {884E2018-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionAuthorityKeyIdentifier = "X509Enrollment.CX509ExtensionAuthorityKeyIdentifier"
' CLSID = {884E2016-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionBasicConstraints = "X509Enrollment.CX509ExtensionBasicConstraints"
' CLSID = {884E2020-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionCertificatePolicies = "X509Enrollment.CX509ExtensionCertificatePolicies"
' CLSID = {884E2010-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionEnhancedKeyUsage = "X509Enrollment.CX509ExtensionEnhancedKeyUsage"
' CLSID = {884E200F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionKeyUsage = "X509Enrollment.CX509ExtensionKeyUsage"
' CLSID = {884E2021-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionMSApplicationPolicies = "X509Enrollment.CX509ExtensionMSApplicationPolicies"
' CLSID = {884E200E-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509Extensions = "X509Enrollment.CX509Extensions"
' CLSID = {884E201B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionSmimeCapabilities = "X509Enrollment.CX509ExtensionSmimeCapabilities"
' CLSID = {884E2017-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionSubjectKeyIdentifier = "X509Enrollment.CX509ExtensionSubjectKeyIdentifier"
' CLSID = {884E2012-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionTemplate = "X509Enrollment.CX509ExtensionTemplate"
' CLSID = {884E2011-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509ExtensionTemplateName = "X509Enrollment.CX509ExtensionTemplateName"
' CLSID = {884E203F-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509NameValuePair = "X509Enrollment.CX509NameValuePair"
' CLSID = {884E200C-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509PrivateKey = "X509Enrollment.CX509PrivateKey"
' CLSID = {884E200B-217D-11DA-B2A4-000E7BBB2B09}
$PROGID_CX509PublicKey = "X509Enrollment.CX509PublicKey"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CAlternativeName = GUID$("{884E2013-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CAlternativeNames = GUID$("{884E2014-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CBinaryConverter = GUID$("{884E2002-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertificatePolicies = GUID$("{884E201F-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertificatePolicy = GUID$("{884E201E-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertProperties = GUID$("{884E202F-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertProperty = GUID$("{884E202E-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyArchived = GUID$("{884E2037-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyArchivedKeyHash = GUID$("{884E203B-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyAutoEnroll = GUID$("{884E2032-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyBackedUp = GUID$("{884E2038-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyDescription = GUID$("{884E2031-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyEnrollment = GUID$("{884E2039-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyEnrollmentPolicyServer = GUID$("{884E204C-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyFriendlyName = GUID$("{884E2030-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyKeyProvInfo = GUID$("{884E2036-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyRenewal = GUID$("{884E203A-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertyRequestOriginator = GUID$("{884E2033-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCertPropertySHA1Hash = GUID$("{884E2034-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCryptAttribute = GUID$("{884E202C-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCryptAttributes = GUID$("{884E202D-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCspInformation = GUID$("{884E2007-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCspInformations = GUID$("{884E2008-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CCspStatus = GUID$("{884E2009-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CObjectId = GUID$("{884E2000-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CObjectIds = GUID$("{884E2001-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CPolicyQualifier = GUID$("{884E201C-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CPolicyQualifiers = GUID$("{884E201D-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CSignerCertificate = GUID$("{884E203D-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CSmimeCapabilities = GUID$("{884E201A-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CSmimeCapability = GUID$("{884E2019-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX500DistinguishedName = GUID$("{884E2003-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509Attribute = GUID$("{884E2022-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeArchiveKey = GUID$("{884E2027-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeArchiveKeyHash = GUID$("{884E2028-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeClientId = GUID$("{884E2025-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeCspProvider = GUID$("{884E202B-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeExtensions = GUID$("{884E2024-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeOSVersion = GUID$("{884E202A-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509AttributeRenewalCertificate = GUID$("{884E2026-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509Attributes = GUID$("{884E2023-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509CertificateRequestCertificate = GUID$("{884E2043-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509CertificateRequestCmc = GUID$("{884E2045-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509CertificateRequestPkcs10 = GUID$("{884E2042-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509CertificateRequestPkcs7 = GUID$("{884E2044-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509CertificateTemplateADWritable = GUID$("{8336E323-2E6A-4A04-937C-548F681839B3}")
$CLSID_CX509Enrollment = GUID$("{884E2046-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509EnrollmentHelper = GUID$("{884E2050-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509EnrollmentPolicyActiveDirectory = GUID$("{91F39027-217F-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509EnrollmentPolicyWebService = GUID$("{91F39028-217F-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509EnrollmentWebClassFactory = GUID$("{884E2049-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509Extension = GUID$("{884E200D-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionAlternativeNames = GUID$("{884E2015-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionAuthorityKeyIdentifier = GUID$("{884E2018-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionBasicConstraints = GUID$("{884E2016-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionCertificatePolicies = GUID$("{884E2020-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionEnhancedKeyUsage = GUID$("{884E2010-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionKeyUsage = GUID$("{884E200F-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionMSApplicationPolicies = GUID$("{884E2021-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509Extensions = GUID$("{884E200E-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionSmimeCapabilities = GUID$("{884E201B-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionSubjectKeyIdentifier = GUID$("{884E2017-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionTemplate = GUID$("{884E2012-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509ExtensionTemplateName = GUID$("{884E2011-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509MachineEnrollmentFactory = GUID$("{884E2051-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509NameValuePair = GUID$("{884E203F-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509PolicyServerListManager = GUID$("{91F39029-217F-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509PolicyServerUrl = GUID$("{91F3902A-217F-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509PrivateKey = GUID$("{884E200C-217D-11DA-B2A4-000E7BBB2B09}")
$CLSID_CX509PublicKey = GUID$("{884E200B-217D-11DA-B2A4-000E7BBB2B09}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAlternativeName = GUID$("{728AB313-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IAlternativeNames = GUID$("{728AB314-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IBinaryConverter = GUID$("{728AB302-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertificatePolicies = GUID$("{728AB31F-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertificatePolicy = GUID$("{728AB31E-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertificationAuthorities = GUID$("{13B79005-2181-11DA-B2A4-000E7BBB2B09}")
$IID_ICertificationAuthority = GUID$("{835D1F61-1E95-4BC8-B4D3-976C42B968F7}")
$IID_ICertProperties = GUID$("{728AB32F-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertProperty = GUID$("{728AB32E-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyArchived = GUID$("{728AB337-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyArchivedKeyHash = GUID$("{728AB33B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyAutoEnroll = GUID$("{728AB332-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyBackedUp = GUID$("{728AB338-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyDescription = GUID$("{728AB331-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyEnrollment = GUID$("{728AB339-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyEnrollmentPolicyServer = GUID$("{728AB34A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyFriendlyName = GUID$("{728AB330-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyKeyProvInfo = GUID$("{728AB336-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyRenewal = GUID$("{728AB33A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertyRequestOriginator = GUID$("{728AB333-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICertPropertySHA1Hash = GUID$("{728AB334-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICryptAttribute = GUID$("{728AB32C-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICryptAttributes = GUID$("{728AB32D-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspAlgorithm = GUID$("{728AB305-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspAlgorithms = GUID$("{728AB306-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspInformation = GUID$("{728AB307-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspInformations = GUID$("{728AB308-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspStatus = GUID$("{728AB309-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ICspStatuses = GUID$("{728AB30A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IObjectId = GUID$("{728AB300-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IObjectIds = GUID$("{728AB301-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IPolicyQualifier = GUID$("{728AB31C-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IPolicyQualifiers = GUID$("{728AB31D-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ISignerCertificate = GUID$("{728AB33D-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ISignerCertificates = GUID$("{728AB33E-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ISmimeCapabilities = GUID$("{728AB31A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_ISmimeCapability = GUID$("{728AB319-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX500DistinguishedName = GUID$("{728AB303-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509Attribute = GUID$("{728AB322-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeArchiveKey = GUID$("{728AB327-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeArchiveKeyHash = GUID$("{728AB328-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeClientId = GUID$("{728AB325-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeCspProvider = GUID$("{728AB32B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeExtensions = GUID$("{728AB324-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeOSVersion = GUID$("{728AB32A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509AttributeRenewalCertificate = GUID$("{728AB326-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509Attributes = GUID$("{728AB323-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequest = GUID$("{728AB341-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestCertificate = GUID$("{728AB343-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestCertificate2 = GUID$("{728AB35A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestCmc = GUID$("{728AB345-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestCmc2 = GUID$("{728AB35D-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestPkcs7 = GUID$("{728AB344-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestPkcs7V2 = GUID$("{728AB35C-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestPkcs10 = GUID$("{728AB342-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateRequestPkcs10V2 = GUID$("{728AB35B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateTemplate = GUID$("{54244A13-555A-4E22-896D-1B0E52F76406}")
$IID_IX509CertificateTemplates = GUID$("{13B79003-2181-11DA-B2A4-000E7BBB2B09}")
$IID_IX509CertificateTemplateWritable = GUID$("{F49466A7-395A-4E9E-B6E7-32B331600DC0}")
$IID_IX509Enrollment = GUID$("{728AB346-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509Enrollment2 = GUID$("{728AB350-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509EnrollmentHelper = GUID$("{728AB351-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509EnrollmentPolicyServer = GUID$("{13B79026-2181-11DA-B2A4-000E7BBB2B09}")
$IID_IX509EnrollmentStatus = GUID$("{728AB304-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509EnrollmentWebClassFactory = GUID$("{728AB349-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509Extension = GUID$("{728AB30D-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionAlternativeNames = GUID$("{728AB315-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionAuthorityKeyIdentifier = GUID$("{728AB318-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionBasicConstraints = GUID$("{728AB316-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionCertificatePolicies = GUID$("{728AB320-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionEnhancedKeyUsage = GUID$("{728AB310-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionKeyUsage = GUID$("{728AB30F-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionMSApplicationPolicies = GUID$("{728AB321-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509Extensions = GUID$("{728AB30E-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionSmimeCapabilities = GUID$("{728AB31B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionSubjectKeyIdentifier = GUID$("{728AB317-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionTemplate = GUID$("{728AB312-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509ExtensionTemplateName = GUID$("{728AB311-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509MachineEnrollmentFactory = GUID$("{728AB352-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509NameValuePair = GUID$("{728AB33F-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509NameValuePairs = GUID$("{728AB340-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509PolicyServerListManager = GUID$("{884E204B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509PolicyServerUrl = GUID$("{884E204A-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509PrivateKey = GUID$("{728AB30C-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509PublicKey = GUID$("{728AB30B-217D-11DA-B2A4-000E7BBB2B09}")
$IID_IX509SignatureInformation = GUID$("{728AB33C-217D-11DA-B2A4-000E7BBB2B09}")

' ========================================================================================
' CERTENROLL_OBJECTID enum
' ========================================================================================

%XCN_OID_NONE                                           = 0
%XCN_OID_RSA                                            = 1
%XCN_OID_PKCS                                           = 2
%XCN_OID_RSA_HASH                                       = 3
%XCN_OID_RSA_ENCRYPT                                    = 4
%XCN_OID_PKCS_1                                         = 5
%XCN_OID_PKCS_2                                         = 6
%XCN_OID_PKCS_3                                         = 7
%XCN_OID_PKCS_4                                         = 8
%XCN_OID_PKCS_5                                         = 9
%XCN_OID_PKCS_6                                         = 10
%XCN_OID_PKCS_7                                         = 11
%XCN_OID_PKCS_8                                         = 12
%XCN_OID_PKCS_9                                         = 13
%XCN_OID_PKCS_10                                        = 14
%XCN_OID_PKCS_12                                        = 15
%XCN_OID_RSA_RSA                                        = 16
%XCN_OID_RSA_MD2RSA                                     = 17
%XCN_OID_RSA_MD4RSA                                     = 18
%XCN_OID_RSA_MD5RSA                                     = 19
%XCN_OID_RSA_SHA1RSA                                    = 20
%XCN_OID_RSA_SETOAEP_RSA                                = 21
%XCN_OID_RSA_DH                                         = 22
%XCN_OID_RSA_data                                       = 23
%XCN_OID_RSA_signedData                                 = 24
%XCN_OID_RSA_envelopedData                              = 25
%XCN_OID_RSA_signEnvData                                = 26
%XCN_OID_RSA_digestedData                               = 27
%XCN_OID_RSA_hashedData                                 = 28
%XCN_OID_RSA_encryptedData                              = 29
%XCN_OID_RSA_emailAddr                                  = 30
%XCN_OID_RSA_unstructName                               = 31
%XCN_OID_RSA_contentType                                = 32
%XCN_OID_RSA_messageDigest                              = 33
%XCN_OID_RSA_signingTime                                = 34
%XCN_OID_RSA_counterSign                                = 35
%XCN_OID_RSA_challengePwd                               = 36
%XCN_OID_RSA_unstructAddr                               = 37
%XCN_OID_RSA_extCertAttrs                               = 38
%XCN_OID_RSA_certExtensions                             = 39
%XCN_OID_RSA_SMIMECapabilities                          = 40
%XCN_OID_RSA_preferSignedData                           = 41
%XCN_OID_RSA_SMIMEalg                                   = 42
%XCN_OID_RSA_SMIMEalgESDH                               = 43
%XCN_OID_RSA_SMIMEalgCMS3DESwrap                        = 44
%XCN_OID_RSA_SMIMEalgCMSRC2wrap                         = 45
%XCN_OID_RSA_MD2                                        = 46
%XCN_OID_RSA_MD4                                        = 47
%XCN_OID_RSA_MD5                                        = 48
%XCN_OID_RSA_RC2CBC                                     = 49
%XCN_OID_RSA_RC4                                        = 50
%XCN_OID_RSA_DES_EDE3_CBC                               = 51
%XCN_OID_RSA_RC5_CBCPad                                 = 52
%XCN_OID_ANSI_X942                                      = 53
%XCN_OID_ANSI_X942_DH                                   = 54
%XCN_OID_X957                                           = 55
%XCN_OID_X957_DSA                                       = 56
%XCN_OID_X957_SHA1DSA                                   = 57
%XCN_OID_DS                                             = 58
%XCN_OID_DSALG                                          = 59
%XCN_OID_DSALG_CRPT                                     = 60
%XCN_OID_DSALG_HASH                                     = 61
%XCN_OID_DSALG_SIGN                                     = 62
%XCN_OID_DSALG_RSA                                      = 63
%XCN_OID_OIW                                            = 64
%XCN_OID_OIWSEC                                         = 65
%XCN_OID_OIWSEC_md4RSA                                  = 66
%XCN_OID_OIWSEC_md5RSA                                  = 67
%XCN_OID_OIWSEC_md4RSA2                                 = 68
%XCN_OID_OIWSEC_desECB                                  = 69
%XCN_OID_OIWSEC_desCBC                                  = 70
%XCN_OID_OIWSEC_desOFB                                  = 71
%XCN_OID_OIWSEC_desCFB                                  = 72
%XCN_OID_OIWSEC_desMAC                                  = 73
%XCN_OID_OIWSEC_rsaSign                                 = 74
%XCN_OID_OIWSEC_dsa                                     = 75
%XCN_OID_OIWSEC_shaDSA                                  = 76
%XCN_OID_OIWSEC_mdc2RSA                                 = 77
%XCN_OID_OIWSEC_shaRSA                                  = 78
%XCN_OID_OIWSEC_dhCommMod                               = 79
%XCN_OID_OIWSEC_desEDE                                  = 80
%XCN_OID_OIWSEC_sha                                     = 81
%XCN_OID_OIWSEC_mdc2                                    = 82
%XCN_OID_OIWSEC_dsaComm                                 = 83
%XCN_OID_OIWSEC_dsaCommSHA                              = 84
%XCN_OID_OIWSEC_rsaXchg                                 = 85
%XCN_OID_OIWSEC_keyHashSeal                             = 86
%XCN_OID_OIWSEC_md2RSASign                              = 87
%XCN_OID_OIWSEC_md5RSASign                              = 88
%XCN_OID_OIWSEC_sha1                                    = 89
%XCN_OID_OIWSEC_dsaSHA1                                 = 90
%XCN_OID_OIWSEC_dsaCommSHA1                             = 91
%XCN_OID_OIWSEC_sha1RSASign                             = 92
%XCN_OID_OIWDIR                                         = 93
%XCN_OID_OIWDIR_CRPT                                    = 94
%XCN_OID_OIWDIR_HASH                                    = 95
%XCN_OID_OIWDIR_SIGN                                    = 96
%XCN_OID_OIWDIR_md2                                     = 97
%XCN_OID_OIWDIR_md2RSA                                  = 98
%XCN_OID_INFOSEC                                        = 99
%XCN_OID_INFOSEC_sdnsSignature                          = 100
%XCN_OID_INFOSEC_mosaicSignature                        = 101
%XCN_OID_INFOSEC_sdnsConfidentiality                    = 102
%XCN_OID_INFOSEC_mosaicConfidentiality                  = 103
%XCN_OID_INFOSEC_sdnsIntegrity                          = 104
%XCN_OID_INFOSEC_mosaicIntegrity                        = 105
%XCN_OID_INFOSEC_sdnsTokenProtection                    = 106
%XCN_OID_INFOSEC_mosaicTokenProtection                  = 107
%XCN_OID_INFOSEC_sdnsKeyManagement                      = 108
%XCN_OID_INFOSEC_mosaicKeyManagement                    = 109
%XCN_OID_INFOSEC_sdnsKMandSig                           = 110
%XCN_OID_INFOSEC_mosaicKMandSig                         = 111
%XCN_OID_INFOSEC_SuiteASignature                        = 112
%XCN_OID_INFOSEC_SuiteAConfidentiality                  = 113
%XCN_OID_INFOSEC_SuiteAIntegrity                        = 114
%XCN_OID_INFOSEC_SuiteATokenProtection                  = 115
%XCN_OID_INFOSEC_SuiteAKeyManagement                    = 116
%XCN_OID_INFOSEC_SuiteAKMandSig                         = 117
%XCN_OID_INFOSEC_mosaicUpdatedSig                       = 118
%XCN_OID_INFOSEC_mosaicKMandUpdSig                      = 119
%XCN_OID_INFOSEC_mosaicUpdatedInteg                     = 120
%XCN_OID_COMMON_NAME                                    = 121
%XCN_OID_SUR_NAME                                       = 122
%XCN_OID_DEVICE_SERIAL_NUMBER                           = 123
%XCN_OID_COUNTRY_NAME                                   = 124
%XCN_OID_LOCALITY_NAME                                  = 125
%XCN_OID_STATE_OR_PROVINCE_NAME                         = 126
%XCN_OID_STREET_ADDRESS                                 = 127
%XCN_OID_ORGANIZATION_NAME                              = 128
%XCN_OID_ORGANIZATIONAL_UNIT_NAME                       = 129
%XCN_OID_TITLE                                          = 130
%XCN_OID_DESCRIPTION                                    = 131
%XCN_OID_SEARCH_GUIDE                                   = 132
%XCN_OID_BUSINESS_CATEGORY                              = 133
%XCN_OID_POSTAL_ADDRESS                                 = 134
%XCN_OID_POSTAL_CODE                                    = 135
%XCN_OID_POST_OFFICE_BOX                                = 136
%XCN_OID_PHYSICAL_DELIVERY_OFFICE_NAME                  = 137
%XCN_OID_TELEPHONE_NUMBER                               = 138
%XCN_OID_TELEX_NUMBER                                   = 139
%XCN_OID_TELETEXT_TERMINAL_IDENTIFIER                   = 140
%XCN_OID_FACSIMILE_TELEPHONE_NUMBER                     = 141
%XCN_OID_X21_ADDRESS                                    = 142
%XCN_OID_INTERNATIONAL_ISDN_NUMBER                      = 143
%XCN_OID_REGISTERED_ADDRESS                             = 144
%XCN_OID_DESTINATION_INDICATOR                          = 145
%XCN_OID_PREFERRED_DELIVERY_METHOD                      = 146
%XCN_OID_PRESENTATION_ADDRESS                           = 147
%XCN_OID_SUPPORTED_APPLICATION_CONTEXT                  = 148
%XCN_OID_MEMBER                                         = 149
%XCN_OID_OWNER                                          = 150
%XCN_OID_ROLE_OCCUPANT                                  = 151
%XCN_OID_SEE_ALSO                                       = 152
%XCN_OID_USER_PASSWORD                                  = 153
%XCN_OID_USER_CERTIFICATE                               = 154
%XCN_OID_CA_CERTIFICATE                                 = 155
%XCN_OID_AUTHORITY_REVOCATION_LIST                      = 156
%XCN_OID_CERTIFICATE_REVOCATION_LIST                    = 157
%XCN_OID_CROSS_CERTIFICATE_PAIR                         = 158
%XCN_OID_GIVEN_NAME                                     = 159
%XCN_OID_INITIALS                                       = 160
%XCN_OID_DN_QUALIFIER                                   = 161
%XCN_OID_DOMAIN_COMPONENT                               = 162
%XCN_OID_PKCS_12_FRIENDLY_NAME_ATTR                     = 163
%XCN_OID_PKCS_12_LOCAL_KEY_ID                           = 164
%XCN_OID_PKCS_12_KEY_PROVIDER_NAME_ATTR                 = 165
%XCN_OID_LOCAL_MACHINE_KEYSET                           = 166
%XCN_OID_PKCS_12_EXTENDED_ATTRIBUTES                    = 167
%XCN_OID_KEYID_RDN                                      = 168
%XCN_OID_AUTHORITY_KEY_IDENTIFIER                       = 169
%XCN_OID_KEY_ATTRIBUTES                                 = 170
%XCN_OID_CERT_POLICIES_95                               = 171
%XCN_OID_KEY_USAGE_RESTRICTION                          = 172
%XCN_OID_SUBJECT_ALT_NAME                               = 173
%XCN_OID_ISSUER_ALT_NAME                                = 174
%XCN_OID_BASIC_CONSTRAINTS                              = 175
%XCN_OID_KEY_USAGE                                      = 176
%XCN_OID_PRIVATEKEY_USAGE_PERIOD                        = 177
%XCN_OID_BASIC_CONSTRAINTS2                             = 178
%XCN_OID_CERT_POLICIES                                  = 179
%XCN_OID_ANY_CERT_POLICY                                = 180
%XCN_OID_AUTHORITY_KEY_IDENTIFIER2                      = 181
%XCN_OID_SUBJECT_KEY_IDENTIFIER                         = 182
%XCN_OID_SUBJECT_ALT_NAME2                              = 183
%XCN_OID_ISSUER_ALT_NAME2                               = 184
%XCN_OID_CRL_REASON_CODE                                = 185
%XCN_OID_REASON_CODE_HOLD                               = 186
%XCN_OID_CRL_DIST_POINTS                                = 187
%XCN_OID_ENHANCED_KEY_USAGE                             = 188
%XCN_OID_CRL_NUMBER                                     = 189
%XCN_OID_DELTA_CRL_INDICATOR                            = 190
%XCN_OID_ISSUING_DIST_POINT                             = 191
%XCN_OID_FRESHEST_CRL                                   = 192
%XCN_OID_NAME_CONSTRAINTS                               = 193
%XCN_OID_POLICY_MAPPINGS                                = 194
%XCN_OID_LEGACY_POLICY_MAPPINGS                         = 195
%XCN_OID_POLICY_CONSTRAINTS                             = 196
%XCN_OID_RENEWAL_CERTIFICATE                            = 197
%XCN_OID_ENROLLMENT_NAME_VALUE_PAIR                     = 198
%XCN_OID_ENROLLMENT_CSP_PROVIDER                        = 199
%XCN_OID_OS_VERSION                                     = 200
%XCN_OID_ENROLLMENT_AGENT                               = 201
%XCN_OID_PKIX                                           = 202
%XCN_OID_PKIX_PE                                        = 203
%XCN_OID_AUTHORITY_INFO_ACCESS                          = 204
%XCN_OID_BIOMETRIC_EXT                                  = 205
%XCN_OID_LOGOTYPE_EXT                                   = 206
%XCN_OID_CERT_EXTENSIONS                                = 207
%XCN_OID_NEXT_UPDATE_LOCATION                           = 208
%XCN_OID_REMOVE_CERTIFICATE                             = 209
%XCN_OID_CROSS_CERT_DIST_POINTS                         = 210
%XCN_OID_CTL                                            = 211
%XCN_OID_SORTED_CTL                                     = 212
%XCN_OID_SERIALIZED                                     = 213
%XCN_OID_NT_PRINCIPAL_NAME                              = 214
%XCN_OID_PRODUCT_UPDATE                                 = 215
%XCN_OID_ANY_APPLICATION_POLICY                         = 216
%XCN_OID_AUTO_ENROLL_CTL_USAGE                          = 217
%XCN_OID_ENROLL_CERTTYPE_EXTENSION                      = 218
%XCN_OID_CERT_MANIFOLD                                  = 219
%XCN_OID_CERTSRV_CA_VERSION                             = 220
%XCN_OID_CERTSRV_PREVIOUS_CERT_HASH                     = 221
%XCN_OID_CRL_VIRTUAL_BASE                               = 222
%XCN_OID_CRL_NEXT_PUBLISH                               = 223
%XCN_OID_KP_CA_EXCHANGE                                 = 224
%XCN_OID_KP_KEY_RECOVERY_AGENT                          = 225
%XCN_OID_CERTIFICATE_TEMPLATE                           = 226
%XCN_OID_ENTERPRISE_OID_ROOT                            = 227
%XCN_OID_RDN_DUMMY_SIGNER                               = 228
%XCN_OID_APPLICATION_CERT_POLICIES                      = 229
%XCN_OID_APPLICATION_POLICY_MAPPINGS                    = 230
%XCN_OID_APPLICATION_POLICY_CONSTRAINTS                 = 231
%XCN_OID_ARCHIVED_KEY_ATTR                              = 232
%XCN_OID_CRL_SELF_CDP                                   = 233
%XCN_OID_REQUIRE_CERT_CHAIN_POLICY                      = 234
%XCN_OID_ARCHIVED_KEY_CERT_HASH                         = 235
%XCN_OID_ISSUED_CERT_HASH                               = 236
%XCN_OID_DS_EMAIL_REPLICATION                           = 237
%XCN_OID_REQUEST_CLIENT_INFO                            = 238
%XCN_OID_ENCRYPTED_KEY_HASH                             = 239
%XCN_OID_CERTSRV_CROSSCA_VERSION                        = 240
%XCN_OID_NTDS_REPLICATION                               = 241
%XCN_OID_SUBJECT_DIR_ATTRS                              = 242
%XCN_OID_PKIX_KP                                        = 243
%XCN_OID_PKIX_KP_SERVER_AUTH                            = 244
%XCN_OID_PKIX_KP_CLIENT_AUTH                            = 245
%XCN_OID_PKIX_KP_CODE_SIGNING                           = 246
%XCN_OID_PKIX_KP_EMAIL_PROTECTION                       = 247
%XCN_OID_PKIX_KP_IPSEC_END_SYSTEM                       = 248
%XCN_OID_PKIX_KP_IPSEC_TUNNEL                           = 249
%XCN_OID_PKIX_KP_IPSEC_USER                             = 250
%XCN_OID_PKIX_KP_TIMESTAMP_SIGNING                      = 251
%XCN_OID_PKIX_KP_OCSP_SIGNING                           = 252
%XCN_OID_PKIX_OCSP_NOCHECK                              = 253
%XCN_OID_IPSEC_KP_IKE_INTERMEDIATE                      = 254
%XCN_OID_KP_CTL_USAGE_SIGNING                           = 255
%XCN_OID_KP_TIME_STAMP_SIGNING                          = 256
%XCN_OID_SERVER_GATED_CRYPTO                            = 257
%XCN_OID_SGC_NETSCAPE                                   = 258
%XCN_OID_KP_EFS                                         = 259
%XCN_OID_EFS_RECOVERY                                   = 260
%XCN_OID_WHQL_CRYPTO                                    = 261
%XCN_OID_NT5_CRYPTO                                     = 262
%XCN_OID_OEM_WHQL_CRYPTO                                = 263
%XCN_OID_EMBEDDED_NT_CRYPTO                             = 264
%XCN_OID_ROOT_LIST_SIGNER                               = 265
%XCN_OID_KP_QUALIFIED_SUBORDINATION                     = 266
%XCN_OID_KP_KEY_RECOVERY                                = 267
%XCN_OID_KP_DOCUMENT_SIGNING                            = 268
%XCN_OID_KP_LIFETIME_SIGNING                            = 269
%XCN_OID_KP_MOBILE_DEVICE_SOFTWARE                      = 270
%XCN_OID_KP_SMART_DISPLAY                               = 271
%XCN_OID_KP_CSP_SIGNATURE                               = 272
%XCN_OID_DRM                                            = 273
%XCN_OID_DRM_INDIVIDUALIZATION                          = 274
%XCN_OID_LICENSES                                       = 275
%XCN_OID_LICENSE_SERVER                                 = 276
%XCN_OID_KP_SMARTCARD_LOGON                             = 277
%XCN_OID_YESNO_TRUST_ATTR                               = 278
%XCN_OID_PKIX_POLICY_QUALIFIER_CPS                      = 279
%XCN_OID_PKIX_POLICY_QUALIFIER_USERNOTICE               = 280
%XCN_OID_CERT_POLICIES_95_QUALIFIER1                    = 281
%XCN_OID_PKIX_ACC_DESCR                                 = 282
%XCN_OID_PKIX_OCSP                                      = 283
%XCN_OID_PKIX_CA_ISSUERS                                = 284
%XCN_OID_VERISIGN_PRIVATE_6_9                           = 285
%XCN_OID_VERISIGN_ONSITE_JURISDICTION_HASH              = 286
%XCN_OID_VERISIGN_BITSTRING_6_13                        = 287
%XCN_OID_VERISIGN_ISS_STRONG_CRYPTO                     = 288
%XCN_OID_NETSCAPE                                       = 289
%XCN_OID_NETSCAPE_CERT_EXTENSION                        = 290
%XCN_OID_NETSCAPE_CERT_TYPE                             = 291
%XCN_OID_NETSCAPE_BASE_URL                              = 292
%XCN_OID_NETSCAPE_REVOCATION_URL                        = 293
%XCN_OID_NETSCAPE_CA_REVOCATION_URL                     = 294
%XCN_OID_NETSCAPE_CERT_RENEWAL_URL                      = 295
%XCN_OID_NETSCAPE_CA_POLICY_URL                         = 296
%XCN_OID_NETSCAPE_SSL_SERVER_NAME                       = 297
%XCN_OID_NETSCAPE_COMMENT                               = 298
%XCN_OID_NETSCAPE_DATA_TYPE                             = 299
%XCN_OID_NETSCAPE_CERT_SEQUENCE                         = 300
%XCN_OID_CT_PKI_DATA                                    = 301
%XCN_OID_CT_PKI_RESPONSE                                = 302
%XCN_OID_PKIX_NO_SIGNATURE                              = 303
%XCN_OID_CMC                                            = 304
%XCN_OID_CMC_STATUS_INFO                                = 305
%XCN_OID_CMC_IDENTIFICATION                             = 306
%XCN_OID_CMC_IDENTITY_PROOF                             = 307
%XCN_OID_CMC_DATA_RETURN                                = 308
%XCN_OID_CMC_TRANSACTION_ID                             = 309
%XCN_OID_CMC_SENDER_NONCE                               = 310
%XCN_OID_CMC_RECIPIENT_NONCE                            = 311
%XCN_OID_CMC_ADD_EXTENSIONS                             = 312
%XCN_OID_CMC_ENCRYPTED_POP                              = 313
%XCN_OID_CMC_DECRYPTED_POP                              = 314
%XCN_OID_CMC_LRA_POP_WITNESS                            = 315
%XCN_OID_CMC_GET_CERT                                   = 316
%XCN_OID_CMC_GET_CRL                                    = 317
%XCN_OID_CMC_REVOKE_REQUEST                             = 318
%XCN_OID_CMC_REG_INFO                                   = 319
%XCN_OID_CMC_RESPONSE_INFO                              = 320
%XCN_OID_CMC_QUERY_PENDING                              = 321
%XCN_OID_CMC_ID_POP_LINK_RANDOM                         = 322
%XCN_OID_CMC_ID_POP_LINK_WITNESS                        = 323
%XCN_OID_CMC_ID_CONFIRM_CERT_ACCEPTANCE                 = 324
%XCN_OID_CMC_ADD_ATTRIBUTES                             = 325
%XCN_OID_LOYALTY_OTHER_LOGOTYPE                         = 326
%XCN_OID_BACKGROUND_OTHER_LOGOTYPE                      = 327
%XCN_OID_PKIX_OCSP_BASIC_SIGNED_RESPONSE                = 328
%XCN_OID_PKCS_7_DATA                                    = 329
%XCN_OID_PKCS_7_SIGNED                                  = 330
%XCN_OID_PKCS_7_ENVELOPED                               = 331
%XCN_OID_PKCS_7_SIGNEDANDENVELOPED                      = 332
%XCN_OID_PKCS_7_DIGESTED                                = 333
%XCN_OID_PKCS_7_ENCRYPTED                               = 334
%XCN_OID_PKCS_9_CONTENT_TYPE                            = 335
%XCN_OID_PKCS_9_MESSAGE_DIGEST                          = 336
%XCN_OID_CERT_PROP_ID_PREFIX                            = 337
%XCN_OID_CERT_KEY_IDENTIFIER_PROP_ID                    = 338
%XCN_OID_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID     = 339
%XCN_OID_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID             = 340
%XCN_OID_CERT_MD5_HASH_PROP_ID                          = 341
%XCN_OID_RSA_SHA256RSA                                  = 342
%XCN_OID_RSA_SHA384RSA                                  = 343
%XCN_OID_RSA_SHA512RSA                                  = 344
%XCN_OID_NIST_sha256                                    = 345
%XCN_OID_NIST_sha384                                    = 346
%XCN_OID_NIST_sha512                                    = 347
%XCN_OID_RSA_MGF1                                       = 348
%XCN_OID_ECC_PUBLIC_KEY                                 = 349
%XCN_OID_RSA_SSA_PSS                                    = 353
%XCN_OID_ECDSA_SHA1                                     = 354
%XCN_OID_ECDSA_SPECIFIED                                = 354

' ========================================================================================
' WebSecurityLevel enum
' ========================================================================================

%LevelUnsafe = 0
%LevelSafe   = 1

%CERTENROLL_INDEX_BASE = 0

' ========================================================================================
' EncodingType enum
' ========================================================================================

%XCN_CRYPT_STRING_BASE64HEADER                          = 0???
%XCN_CRYPT_STRING_BASE64                                = &H1???
%XCN_CRYPT_STRING_BINARY                                = &H2???
%XCN_CRYPT_STRING_BASE64REQUESTHEADER                   = &H3???
%XCN_CRYPT_STRING_HEX                                   = &H4???
%XCN_CRYPT_STRING_HEXASCII                              = &H5???
%XCN_CRYPT_STRING_BASE64_ANY                            = &H6???
%XCN_CRYPT_STRING_ANY                                   = &H7???
%XCN_CRYPT_STRING_HEX_ANY                               = &H8???
%XCN_CRYPT_STRING_BASE64X509CRLHEADER                   = &H9???
%XCN_CRYPT_STRING_HEXADDR                               = &HA???
%XCN_CRYPT_STRING_HEXASCIIADDR                          = &HB???
%XCN_CRYPT_STRING_HEXRAW                                = &HC???
%XCN_CRYPT_STRING_HASHDATA                              = &H10000000???
%XCN_CRYPT_STRING_STRICT                                = &H20000000???
%XCN_CRYPT_STRING_NOCRLF                                = &H40000000???
%XCN_CRYPT_STRING_NOCR                                  = &H80000000???

' ========================================================================================
' PFXExportOptions enum
' ========================================================================================

%PFXExportEEOnly                                        = 0
%PFXExportChainNoRoot                                   = 1
%PFXExportChainWithRoot                                 = 2

' ========================================================================================
' ObjectIdGroupId enum
' ========================================================================================

%XCN_CRYPT_ANY_GROUP_ID                                 = 0
%XCN_CRYPT_HASH_ALG_OID_GROUP_ID                        = 1
%XCN_CRYPT_ENCRYPT_ALG_OID_GROUP_ID                     = 2
%XCN_CRYPT_PUBKEY_ALG_OID_GROUP_ID                      = 3
%XCN_CRYPT_SIGN_ALG_OID_GROUP_ID                        = 4
%XCN_CRYPT_RDN_ATTR_OID_GROUP_ID                        = 5
%XCN_CRYPT_EXT_OR_ATTR_OID_GROUP_ID                     = 6
%XCN_CRYPT_ENHKEY_USAGE_OID_GROUP_ID                    = 7
%XCN_CRYPT_POLICY_OID_GROUP_ID                          = 8
%XCN_CRYPT_TEMPLATE_OID_GROUP_ID                        = 9
%XCN_CRYPT_LAST_OID_GROUP_ID                            = 10
%XCN_CRYPT_FIRST_ALG_OID_GROUP_ID                       = 1
%XCN_CRYPT_LAST_ALG_OID_GROUP_ID                        = 4
%XCN_CRYPT_GROUP_ID_MASK                                = &HFFFF???
%XCN_CRYPT_OID_PREFER_CNG_ALGID_FLAG                    = &H40000000???
%XCN_CRYPT_OID_DISABLE_SEARCH_DS_FLAG                   = &H80000000???
%XCN_CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK              = &HFFF0000???
%XCN_CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT             = 16
%XCN_CRYPT_KEY_LENGTH_MASK                              = &HFFF0000???

' ========================================================================================
' ObjectIdPublicKeyFlags enum
' ========================================================================================

%XCN_CRYPT_OID_INFO_PUBKEY_ANY                          = 0
%XCN_CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG                = &H80000000???
%XCN_CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG             = &H40000000???

' ========================================================================================
' AlgorithmFlags enum
' ========================================================================================

%AlgorithmFlagsNone                                     = 0???
%AlgorithmFlagsWrap                                     = &H1???

' ========================================================================================
' X500NameFlags enum
' ========================================================================================

%XCN_CERT_NAME_STR_NONE                                 = 0
%XCN_CERT_SIMPLE_NAME_STR                               = 1
%XCN_CERT_OID_NAME_STR                                  = 2
%XCN_CERT_X500_NAME_STR                                 = 3
%XCN_CERT_XML_NAME_STR                                  = 4
%XCN_CERT_NAME_STR_SEMICOLON_FLAG                       = &H40000000???
%XCN_CERT_NAME_STR_NO_PLUS_FLAG                         = &H20000000???
%XCN_CERT_NAME_STR_NO_QUOTING_FLAG                      = &H10000000???
%XCN_CERT_NAME_STR_CRLF_FLAG                            = &H8000000???
%XCN_CERT_NAME_STR_COMMA_FLAG                           = &H4000000???
%XCN_CERT_NAME_STR_REVERSE_FLAG                         = &H2000000???
%XCN_CERT_NAME_STR_FORWARD_FLAG                         = &H1000000???
%XCN_CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG                = &H10000???
%XCN_CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG              = &H20000???
%XCN_CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG             = &H40000???
%XCN_CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG              = &H80000???
%XCN_CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG            = &H100000???
%XCN_CERT_NAME_STR_ENABLE_PUNYCODE_FLAG                 = &H200000???

' ========================================================================================
' X509ProviderType enum
' ========================================================================================

%XCN_PROV_NONE                                          = 0
%XCN_PROV_RSA_FULL                                      = 1
%XCN_PROV_RSA_SIG                                       = 2
%XCN_PROV_DSS                                           = 3
%XCN_PROV_FORTEZZA                                      = 4
%XCN_PROV_MS_EXCHANGE                                   = 5
%XCN_PROV_SSL                                           = 6
%XCN_PROV_RSA_SCHANNEL                                  = 12
%XCN_PROV_DSS_DH                                        = 13
%XCN_PROV_EC_ECDSA_SIG                                  = 14
%XCN_PROV_EC_ECNRA_SIG                                  = 15
%XCN_PROV_EC_ECDSA_FULL                                 = 16
%XCN_PROV_EC_ECNRA_FULL                                 = 17
%XCN_PROV_DH_SCHANNEL                                   = 18
%XCN_PROV_SPYRUS_LYNKS                                  = 20
%XCN_PROV_RNG                                           = 21
%XCN_PROV_INTEL_SEC                                     = 22
%XCN_PROV_REPLACE_OWF                                   = 23
%XCN_PROV_RSA_AES                                       = 24

' ========================================================================================
' AlgorithmType enum
' ========================================================================================

'// XCN_BCRYPT_SIGNATURE_INTERFACE: RSA, DSA, ECDSA_P* signature
'// XCN_BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE: RSA encryption
'// XCN_BCRYPT_CIPHER_INTERFACE: RC2, RC4, DES, 3DES, AES symmetric encryption
'// XCN_BCRYPT_HASH_INTERFACE: MD2, MD4, SHA1, SHA256, SHA384, SHA512 MAC, HMAC Hash
'// XCN_BCRYPT_SECRET_AGREEMENT_INTERFACE: DH, ECDH_P* key agreement
'// XCN_BCRYPT_RNG_INTERFACE: RNG

%XCN_BCRYPT_UNKNOWN_INTERFACE                           = 0???
%XCN_BCRYPT_SIGNATURE_INTERFACE                         = &H5???
%XCN_BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE             = &H3???
%XCN_BCRYPT_CIPHER_INTERFACE                            = &H1???
%XCN_BCRYPT_HASH_INTERFACE                              = &H2???
%XCN_BCRYPT_SECRET_AGREEMENT_INTERFACE                  = &H4???
%XCN_BCRYPT_RNG_INTERFACE                               = &H6???

' ========================================================================================
' AlgorithmOperationFlags enum
' ========================================================================================

%XCN_NCRYPT_NO_OPERATION                                = 0???
%XCN_NCRYPT_CIPHER_OPERATION                            = &H1???
%XCN_NCRYPT_HASH_OPERATION                              = &H2???
%XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION             = &H4???
%XCN_NCRYPT_SECRET_AGREEMENT_OPERATION                  = &H8???
%XCN_NCRYPT_SIGNATURE_OPERATION                         = &H10???
%XCN_NCRYPT_RNG_OPERATION                               = &H20???
%XCN_NCRYPT_ANY_ASYMMETRIC_OPERATION                    = &H1C???   ' (&H4 OR &H8 ) OR &H10
%XCN_NCRYPT_PREFER_SIGNATURE_ONLY_OPERATION             = &H200000???
%XCN_NCRYPT_PREFER_NON_SIGNATURE_OPERATION              = &H400000???
%XCN_NCRYPT_EXACT_MATCH_OPERATION                       = &H800000???
%XCN_NCRYPT_PREFERENCE_MASK_OPERATION                   = &HE00000???

' ========================================================================================
' X509KeySpec enum
' ========================================================================================

%XCN_AT_NONE                                            = 0
%XCN_AT_KEYEXCHANGE                                     = 1
%XCN_AT_SIGNATURE                                       = 2

' ========================================================================================
' X509CertificateEnrollmentContext enum
' ========================================================================================

%ContextUser                                            = &H1???
%ContextMachine                                         = &H2???
%ContextAdministratorForceMachine                       = &H3???

' ========================================================================================
' EnrollmentEnrollStatus enum
' ========================================================================================

%Enrolled                                               = &H1???
%EnrollPended                                           = &H2???
%EnrollUIDeferredEnrollmentRequired                     = &H4???
%EnrollError                                            = &H10???
%EnrollUnknown                                          = &H20???
%EnrollSkipped                                          = &H40???
%EnrollDenied                                           = &H100???

' ========================================================================================
' EnrollmentSelectionStatus enum
' ========================================================================================

%SelectedNo                                             = 0
%SelectedYes                                            = 1

' ========================================================================================
' EnrollmentDisplayStatus enum
' ========================================================================================

%DisplayNo                                              = 0
%DisplayYes                                             = 1

' ========================================================================================
' KeyIdentifierHashAlgorithm enum
' ========================================================================================

%SKIHashDefault                                         = 0
%SKIHashSha1                                            = 1
%SKIHashCapiSha1                                        = 2

' ========================================================================================
' X509PrivateKeyExportFlags enum
' ========================================================================================

%XCN_NCRYPT_ALLOW_EXPORT_NONE                           = 0???
%XCN_NCRYPT_ALLOW_EXPORT_FLAG                           = &H1???
%XCN_NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG                 = &H2???
%XCN_NCRYPT_ALLOW_ARCHIVING_FLAG                        = &H4???
%XCN_NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG              = &H8???

' ========================================================================================
' X509PrivateKeyUsageFlags enum
' ========================================================================================

%XCN_NCRYPT_ALLOW_USAGES_NONE                           = 0???
%XCN_NCRYPT_ALLOW_DECRYPT_FLAG                          = &H1???
%XCN_NCRYPT_ALLOW_SIGNING_FLAG                          = &H2???
%XCN_NCRYPT_ALLOW_KEY_AGREEMENT_FLAG                    = &H4???
%XCN_NCRYPT_ALLOW_ALL_USAGES                            = &HFFFFFF???

' ========================================================================================
' X509PrivateKeyProtection enum
' ========================================================================================

%XCN_NCRYPT_UI_NO_PROTECTION_FLAG                       = 0???
%XCN_NCRYPT_UI_PROTECT_KEY_FLAG                         = &H1???
%XCN_NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG               = &H2???

' ========================================================================================
' X509PrivateKeyVerify enum
' ========================================================================================

%VerifyNone                                             = 0
%VerifySilent                                           = 1
%VerifySmartCardNone                                    = 2
%VerifySmartCardSilent                                  = 3
%VerifyAllowUI                                          = 4

' ========================================================================================
' X509KeyUsageFlags enum
' ========================================================================================

%XCN_CERT_NO_KEY_USAGE                                  = 0???
%XCN_CERT_DIGITAL_SIGNATURE_KEY_USAGE                   = &H80???
%XCN_CERT_NON_REPUDIATION_KEY_USAGE                     = &H40???
%XCN_CERT_KEY_ENCIPHERMENT_KEY_USAGE                    = &H20???
%XCN_CERT_DATA_ENCIPHERMENT_KEY_USAGE                   = &H10???
%XCN_CERT_KEY_AGREEMENT_KEY_USAGE                       = &H8???
%XCN_CERT_KEY_CERT_SIGN_KEY_USAGE                       = &H4???
%XCN_CERT_OFFLINE_CRL_SIGN_KEY_USAGE                    = &H2???
%XCN_CERT_CRL_SIGN_KEY_USAGE                            = &H2???
%XCN_CERT_ENCIPHER_ONLY_KEY_USAGE                       = &H1???
%XCN_CERT_DECIPHER_ONLY_KEY_USAGE                       = &H8000???   ' 0x80 << 8

' ========================================================================================
' AlternativeNameType enum
' ========================================================================================

%XCN_CERT_ALT_NAME_UNKNOWN                              = 0
%XCN_CERT_ALT_NAME_OTHER_NAME                           = 1
%XCN_CERT_ALT_NAME_RFC822_NAME                          = 2
%XCN_CERT_ALT_NAME_DNS_NAME                             = 3
%XCN_CERT_ALT_NAME_DIRECTORY_NAME                       = 5
%XCN_CERT_ALT_NAME_URL                                  = 7
%XCN_CERT_ALT_NAME_IP_ADDRESS                           = 8
%XCN_CERT_ALT_NAME_REGISTERED_ID                        = 9
%XCN_CERT_ALT_NAME_GUID                                 = 10
%XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME                  = 11

' ========================================================================================
' PolicyQualifierType enum
' ========================================================================================

%PolicyQualifierTypeUnknown                             = 0
%PolicyQualifierTypeUrl                                 = 1
%PolicyQualifierTypeUserNotice                          = 2

' ========================================================================================
' RequestClientInfoClientId enum
' ========================================================================================

%ClientIdNone                                           = 0
%ClientIdXEnroll2003                                    = 1
%ClientIdAutoEnroll2003                                 = 2
%ClientIdWizard2003                                     = 3
%ClientIdCertReq2003                                    = 4
%ClientIdDefaultRequest                                 = 5
%ClientIdAutoEnroll                                     = 6
%ClientIdRequestWizard                                  = 7
%ClientIdEOBO                                           = 8
%ClientIdCertReq                                        = 9
%ClientIdTest                                           = 10
%ClientIdUserStart                                      = 1000

' ========================================================================================
' CERTENROLL_PROPERTYID enum
' ========================================================================================

%XCN_PROPERTYID_NONE                                    = 0
%XCN_CERT_KEY_PROV_HANDLE_PROP_ID                       = 1
%XCN_CERT_KEY_PROV_INFO_PROP_ID                         = 2
%XCN_CERT_SHA1_HASH_PROP_ID                             = 3
%XCN_CERT_MD5_HASH_PROP_ID                              = 4
%XCN_CERT_HASH_PROP_ID                                  = 3
%XCN_CERT_KEY_CONTEXT_PROP_ID                           = 5
%XCN_CERT_KEY_SPEC_PROP_ID                              = 6
%XCN_CERT_IE30_RESERVED_PROP_ID                         = 7
%XCN_CERT_PUBKEY_HASH_RESERVED_PROP_ID                  = 8
%XCN_CERT_ENHKEY_USAGE_PROP_ID                          = 9
%XCN_CERT_CTL_USAGE_PROP_ID                             = 9
%XCN_CERT_NEXT_UPDATE_LOCATION_PROP_ID                  = 10
%XCN_CERT_FRIENDLY_NAME_PROP_ID                         = 11
%XCN_CERT_PVK_FILE_PROP_ID                              = 12
%XCN_CERT_DESCRIPTION_PROP_ID                           = 13
%XCN_CERT_ACCESS_STATE_PROP_ID                          = 14
%XCN_CERT_SIGNATURE_HASH_PROP_ID                        = 15
%XCN_CERT_SMART_CARD_DATA_PROP_ID                       = 16
%XCN_CERT_EFS_PROP_ID                                   = 17
%XCN_CERT_FORTEZZA_DATA_PROP_ID                         = 18
%XCN_CERT_ARCHIVED_PROP_ID                              = 19
%XCN_CERT_KEY_IDENTIFIER_PROP_ID                        = 20
%XCN_CERT_AUTO_ENROLL_PROP_ID                           = 21
%XCN_CERT_PUBKEY_ALG_PARA_PROP_ID                       = 22
%XCN_CERT_CROSS_CERT_DIST_POINTS_PROP_ID                = 23
%XCN_CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID            = 24
%XCN_CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID           = 25
%XCN_CERT_ENROLLMENT_PROP_ID                            = 26
%XCN_CERT_DATE_STAMP_PROP_ID                            = 27
%XCN_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID         = 28
%XCN_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID                 = 29
%XCN_CERT_EXTENDED_ERROR_INFO_PROP_ID                   = 30
%XCN_CERT_RENEWAL_PROP_ID                               = 64
%XCN_CERT_ARCHIVED_KEY_HASH_PROP_ID                     = 65
%XCN_CERT_AUTO_ENROLL_RETRY_PROP_ID                     = 66
%XCN_CERT_AIA_URL_RETRIEVED_PROP_ID                     = 67
%XCN_CERT_AUTHORITY_INFO_ACCESS_PROP_ID                 = 68
%XCN_CERT_BACKED_UP_PROP_ID                             = 69
%XCN_CERT_OCSP_RESPONSE_PROP_ID                         = 70
%XCN_CERT_REQUEST_ORIGINATOR_PROP_ID                    = 71
%XCN_CERT_SOURCE_LOCATION_PROP_ID                       = 72
%XCN_CERT_SOURCE_URL_PROP_ID                            = 73
%XCN_CERT_NEW_KEY_PROP_ID                               = 74
%XCN_CERT_FIRST_RESERVED_PROP_ID                        = 92
%XCN_CERT_LAST_RESERVED_PROP_ID                         = &H7FFF???
%XCN_CERT_FIRST_USER_PROP_ID                            = &H8000???
%XCN_CERT_LAST_USER_PROP_ID                             = &HFFFF???
%XCN_CERT_STORE_LOCALIZED_NAME_PROP_ID                  = &H1000???
%XCN_CERT_CEP_PROP_ID                                   = 87

' ========================================================================================
' EnrollmentPolicyServerPropertyFlags enum
' ========================================================================================

%DefaultNone                                            = 0???
%DefaultPolicyServer                                    = &H1???

' ========================================================================================
' PolicyServerUrlFlags enum
' ========================================================================================

%PsfNone                                                = 0???
%PsfLocationGroupPolicy                                 = 1???
%PsfLocationRegistry                                    = 2???
%PsfUseClientId                                         = 4???
%PsfAutoEnrollmentEnabled                               = 16???
%PsfAllowUnTrustedCA                                    = 32???

' ========================================================================================
' X509CertificateTemplateGeneralFlag enum
' ========================================================================================

%GeneralMachineType  = &H40???
%GeneralCA           = &H80???
%GeneralCrossCA      = &H800???
%GeneralDefault      = &H10000???
%GeneralModified     = &H20000???
%GeneralDonotPersist = &H1000???

' ========================================================================================
' X509CertificateTemplateEnrollmentFlag enum
' ========================================================================================

%EnrollmentIncludeSymmetricAlgorithms                = &H1???
%EnrollmentPendAllRequests                           = &H2???
%EnrollmentPublishToKRAContainer                     = &H4???
%EnrollmentPublishToDS                               = &H8???
%EnrollmentAutoEnrollmentCheckUserDSCertificate      = &H10???
%EnrollmentAutoEnrollment                            = &H20???
%EnrollmentDomainAuthenticationNotRequired           = &H80???
%EnrollmentPreviousApprovalValidateReEnrollment      = &H40???
%EnrollmentUserInteractionRequired                   = &H100???
%EnrollmentAddTemplateName                           = &H200???
%EnrollmentRemoveInvalidCertificateFromPersonalStore = &H400???
%EnrollmentAllowEnrollOnBehalfOf                     = &H800???
%EnrollmentAddOCSPNoCheck                            = &H1000???
%EnrollmentReuseKeyOnFullSmartCard                   = &H2000???
%EnrollmentNoRevocationInfoInCerts                   = &H4000???
%EnrollmentIncludeBasicConstraintsForEECerts         = &H8000???

' ========================================================================================
' X509CertificateTemplateSubjectNameFlag enum
' ========================================================================================

%SubjectNameEnrolleeSupplies                  = &H1???
%SubjectNameRequireDirectoryPath              = &H80000000???
%SubjectNameRequireCommonName                 = &H40000000???
%SubjectNameRequireEmail                      = &H20000000???
%SubjectNameRequireDNS                        = &H10000000???
%SubjectNameAndAlternativeNameOldCertSupplies = &H8???
%SubjectAlternativeNameEnrolleeSupplies       = &H10000???
%SubjectAlternativeNameRequireDirectoryGUID   = &H1000000???
%SubjectAlternativeNameRequireUPN             = &H2000000???
%SubjectAlternativeNameRequireEmail           = &H4000000???
%SubjectAlternativeNameRequireSPN             = &H800000???
%SubjectAlternativeNameRequireDNS             = &H8000000???
%SubjectAlternativeNameRequireDomainDNS       = &H400000???

' ========================================================================================
' X509CertificateTemplatePrivateKeyFlag enum
' ========================================================================================

%PrivateKeyRequireArchival                    = &H1???
%PrivateKeyExportable                         = &H10???
%PrivateKeyRequireStrongKeyProtection         = &H20???
%PrivateKeyRequireAlternateSignatureAlgorithm = &H40???


' ========================================================================================
' X509RequestType enum
' ========================================================================================

%TypeAny                                                = 0
%TypePkcs10                                             = 1
%TypePkcs7                                              = 2
%TypeCmc                                                = 3
%TypeCertificate                                        = 4

' ========================================================================================
' X509RequestInheritOptions enum
' ========================================================================================

%InheritDefault                                         = 0???
%InheritNewDefaultKey                                   = &H1???
%InheritNewSimilarKey                                   = &H2???
%InheritPrivateKey                                      = &H3???
%InheritPublicKey                                       = &H4???
%InheritKeyMask                                         = &HF???
%InheritNone                                            = &H10???
%InheritRenewalCertificateFlag                          = &H20???
%InheritTemplateFlag                                    = &H40???
%InheritSubjectFlag                                     = &H80???
%InheritExtensionsFlag                                  = &H100???
%InheritSubjectAltNameFlag                              = &H200???
%InheritValidityPeriodFlag                              = &H400???

' ========================================================================================
' InnerRequestLevel enum
' ========================================================================================

%LevelInnermost                                         = 0
%LevelNext                                              = 1

' ========================================================================================
' Pkcs10AllowedSignatureTypes enum
' ========================================================================================

%AllowedKeySignature                                    = &H1???
%AllowedNullSignature                                   = &H2???

' ========================================================================================
' X509EnrollmentPolicyLoadOption enum
' ========================================================================================

%LoadOptionDefault                                      = 0
%LoadOptionCacheOnly                                    = 1
%LoadOptionReload                                       = 2
%LoadOptionRegisterForADChanges                         = 4

' ========================================================================================
' EnrollmentPolicyFlags enum
' ========================================================================================

%DisableGroupPolicyList                                 = &H2???
%DisableUserServerList                                  = &H4???

' ========================================================================================
' PolicyServerUrlPropertyID enum
' ========================================================================================

%PsPolicyID                                             = 0
%PsFriendlyName                                         = %PsPolicyID + 1

' ========================================================================================
' X509EnrollmentPolicyExportFlags enum
' ========================================================================================

%ExportTemplates                                        = &H1???
%ExportOIDs                                             = &H2???
%ExportCAs                                              = &H4???

' ========================================================================================
' EnrollmentTemplateProperty enum
' ========================================================================================

%TemplatePropCommonName            = 1
%TemplatePropFriendlyName          = %TemplatePropCommonName            + 1
%TemplatePropEKUs                  = %TemplatePropFriendlyName          + 1
%TemplatePropCryptoProviders       = %TemplatePropEKUs                  + 1
%TemplatePropMajorRevision         = %TemplatePropCryptoProviders       + 1
%TemplatePropDescription           = %TemplatePropMajorRevision         + 1
%TemplatePropKeySpec               = %TemplatePropDescription           + 1
%TemplatePropSchemaVersion         = %TemplatePropKeySpec               + 1
%TemplatePropMinorRevision         = %TemplatePropSchemaVersion         + 1
%TemplatePropRASignatureCount      = %TemplatePropMinorRevision         + 1
%TemplatePropMinimumKeySize        = %TemplatePropRASignatureCount      + 1
%TemplatePropOID                   = %TemplatePropMinimumKeySize        + 1
%TemplatePropSupersede             = %TemplatePropOID                   + 1
%TemplatePropRACertificatePolicies = %TemplatePropSupersede             + 1
%TemplatePropRAEKUs                = %TemplatePropRACertificatePolicies + 1
%TemplatePropCertificatePolicies   = %TemplatePropRAEKUs                + 1
%TemplatePropV1ApplicationPolicy   = %TemplatePropCertificatePolicies   + 1
%TemplatePropAsymmetricAlgorithm   = %TemplatePropV1ApplicationPolicy   + 1
%TemplatePropKeySecurityDescriptor = %TemplatePropAsymmetricAlgorithm   + 1
%TemplatePropSymmetricAlgorithm    = %TemplatePropKeySecurityDescriptor + 1
%TemplatePropSymmetricKeyLength    = %TemplatePropSymmetricAlgorithm    + 1
%TemplatePropHashAlgorithm         = %TemplatePropSymmetricKeyLength    + 1
%TemplatePropKeyUsage              = %TemplatePropHashAlgorithm         + 1
%TemplatePropEnrollmentFlags       = %TemplatePropKeyUsage              + 1
%TemplatePropSubjectNameFlags      = %TemplatePropEnrollmentFlags       + 1
%TemplatePropPrivateKeyFlags       = %TemplatePropSubjectNameFlags      + 1
%TemplatePropGeneralFlags          = %TemplatePropPrivateKeyFlags       + 1
%TemplatePropSecurityDescriptor    = %TemplatePropGeneralFlags          + 1
%TemplatePropExtensions            = %TemplatePropSecurityDescriptor    + 1
%TemplatePropValidityPeriod        = %TemplatePropExtensions            + 1
%TemplatePropRenewalPeriod         = %TemplatePropValidityPeriod        + 1

' ========================================================================================
' EnrollmentCAProperty enum
' ========================================================================================

%CAPropCommonName         = 1
%CAPropDistinguishedName  = %CAPropCommonName         + 1
%CAPropSanitizedName      = %CAPropDistinguishedName  + 1
%CAPropSanitizedShortName = %CAPropSanitizedName      + 1
%CAPropDNSName            = %CAPropSanitizedShortName + 1
%CAPropCertificateTypes   = %CAPropDNSName            + 1
%CAPropCertificate        = %CAPropCertificateTypes   + 1
%CAPropDescription        = %CAPropCertificate        + 1
%CAPropWebServers         = %CAPropDescription        + 1
%CAPropSiteName           = %CAPropWebServers         + 1
%CAPropSecurity           = %CAPropSiteName           + 1
%CAPropRenewalOnly        = %CAPropSecurity           + 1

' ========================================================================================
' InstallResponseRestrictionFlags enum
' ========================================================================================

%AllowNone                                              = 0???
%AllowNoOutstandingRequest                              = &H1???
%AllowUntrustedCertificate                              = &H2???
%AllowUntrustedRoot                                     = &H4???

' ========================================================================================
' WebEnrollmentFlags enum
' ========================================================================================

%EnrollPrompt = &H1???

' ========================================================================================
' CommitTemplateFlags enum
' ========================================================================================

%CommitFlagSaveTemplateGenerateOID   = 1???
%CommitFlagSaveTemplateUseCurrentOID = 2???
%CommitFlagSaveTemplateOverwrite     = 3???
%CommitFlagDeleteTemplate            = 4???


' ########################################################################################
' Interface name = IObjectId
' IID = {728AB300-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IObjectId_INTERFACE_DEFINED)
    %IObjectId_INTERFACE_DEFINED = 1

INTERFACE IObjectId $IID_IObjectId

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeFromName <1610743808> ( _           ' VTable offset = 28
     BYVAL Name AS LONG _                               ' __in CERTENROLL_OBJECTID Name
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromValue <1610743809> ( _          ' VTable offset = 32
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromAlgorithmName <1610743810> ( _  ' VTable offset = 36
     BYVAL GroupId AS LONG _                            ' __in ObjectIdGroupId GroupId
   , BYVAL KeyFlags AS LONG _                           ' __in ObjectIdPublicKeyFlags KeyFlags
   , BYVAL AlgFlags AS LONG _                           ' __in AlgorithmFlags AlgFlags
   , BYVAL strAlgorithmName AS WSTRING _                ' __in BSTR strAlgorithmName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610743811> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out CERTENROLL_OBJECTID *pValue
   ' =====================================================================================
   PROPERTY GET FriendlyName <1610743812> ( _           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET FriendlyName <1610743812> ( _           ' VTable offset = 48
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1610743814> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetAlgorithmName <1610743815> ( _             ' VTable offset = 56
     BYVAL GroupId AS LONG _                            ' __in ObjectIdGroupId GroupId
   , BYVAL KeyFlags AS LONG _                           ' __in ObjectIdPublicKeyFlags KeyFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrAlgorithmName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectId_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IObjectIds
' IID = {728AB301-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IObjectIds_INTERFACE_DEFINED)
    %IObjectIds_INTERFACE_DEFINED = 1

INTERFACE IObjectIds $IID_IObjectIds

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IObjectId                                       ' __retval_out IObjectId **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IObjectId _                          ' __in IObjectId *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRange <1610743814> ( _                     ' VTable offset = 52
     BYVAL pValue AS IObjectIds _                       ' __in IObjectIds *pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectIds_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBinaryConverter
' IID = {728AB302-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBinaryConverter_INTERFACE_DEFINED)
    %IBinaryConverter_INTERFACE_DEFINED = 1

INTERFACE IBinaryConverter $IID_IBinaryConverter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StringToString <1610743808> ( _               ' VTable offset = 28
     BYVAL strEncodedIn AS WSTRING _                    ' __in BSTR strEncodedIn
   , BYVAL EncodingIn AS LONG _                         ' __in EncodingType EncodingIn
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pstrEncoded
   ' =====================================================================================
   METHOD VariantByteArrayToString <1610743809> ( _     ' VTable offset = 32
     BYREF pvarByteArray AS VARIANT _                   ' __in VARIANT *pvarByteArray
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pstrEncoded
   ' =====================================================================================
   METHOD StringToVariantByteArray <1610743810> ( _     ' VTable offset = 36
     BYVAL strEncoded AS WSTRING _                      ' __in BSTR strEncoded
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarByteArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBinaryConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX500DistinguishedName
' IID = {728AB303-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX500DistinguishedName_INTERFACE_DEFINED)
    %IX500DistinguishedName_INTERFACE_DEFINED = 1

INTERFACE IX500DistinguishedName $IID_IX500DistinguishedName

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Decode <1610743808> ( _                       ' VTable offset = 28
     BYVAL strEncodedName AS WSTRING _                  ' __in BSTR strEncodedName
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL NameFlags AS LONG _                 ' __opt_in X500NameFlags NameFlags = XCN_CERT_NAME_STR_NONE
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL NameFlags AS LONG _                 ' __opt_in X500NameFlags NameFlags = XCN_CERT_NAME_STR_NONE
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610743810> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET EncodedName <1610743811> ( _            ' VTable offset = 40
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX500DistinguishedName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509EnrollmentStatus
' IID = {728AB304-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509EnrollmentStatus_INTERFACE_DEFINED)
    %IX509EnrollmentStatus_INTERFACE_DEFINED = 1

INTERFACE IX509EnrollmentStatus $IID_IX509EnrollmentStatus

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AppendText <1610743808> ( _                   ' VTable offset = 28
     BYVAL strText AS WSTRING _                         ' __in BSTR strText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <1610743809> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET Text <1610743809> ( _                   ' VTable offset = 36
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selected <1610743811> ( _               ' VTable offset = 40
   ) AS LONG                                            ' __retval_out EnrollmentSelectionStatus *pValue
   ' =====================================================================================
   PROPERTY SET Selected <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS LONG _                              ' __in EnrollmentSelectionStatus Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Display <1610743813> ( _                ' VTable offset = 48
   ) AS LONG                                            ' __retval_out EnrollmentDisplayStatus *pValue
   ' =====================================================================================
   PROPERTY SET Display <1610743813> ( _                ' VTable offset = 52
     BYVAL Value AS LONG _                              ' __in EnrollmentDisplayStatus Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <1610743815> ( _                 ' VTable offset = 56
   ) AS LONG                                            ' __retval_out EnrollmentEnrollStatus *pValue
   ' =====================================================================================
   PROPERTY SET Status <1610743815> ( _                 ' VTable offset = 60
     BYVAL Value AS LONG _                              ' __in EnrollmentEnrollStatus Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Error <1610743817> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out HRESULT *pValue
   ' =====================================================================================
   PROPERTY SET Error <1610743817> ( _                  ' VTable offset = 68
     BYVAL Value AS LONG _                              ' __in HRESULT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorText <1610743819> ( _              ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509EnrollmentStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspAlgorithm
' IID = {728AB305-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspAlgorithm_INTERFACE_DEFINED)
    %ICspAlgorithm_INTERFACE_DEFINED = 1

INTERFACE ICspAlgorithm $IID_ICspAlgorithm

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetAlgorithmOid <1610743808> ( _              ' VTable offset = 28
     BYVAL Length AS LONG _                             ' __in LONG Length
   , BYVAL AlgFlags AS LONG _                           ' __in AlgorithmFlags AlgFlags
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET DefaultLength <1610743809> ( _          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET IncrementLength <1610743810> ( _        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET LongName <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Valid <1610743812> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET MaxLength <1610743813> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET MinLength <1610743814> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET Name <1610743815> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Type <1610743816> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out AlgorithmType *pValue
   ' =====================================================================================
   PROPERTY GET Operations <1610743817> ( _             ' VTable offset = 64
   ) AS LONG                                            ' __retval_out AlgorithmOperationFlags *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspAlgorithm_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspAlgorithms
' IID = {728AB306-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspAlgorithms_INTERFACE_DEFINED)
    %ICspAlgorithms_INTERFACE_DEFINED = 1

INTERFACE ICspAlgorithms $IID_ICspAlgorithms

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICspAlgorithm                                   ' __retval_out ICspAlgorithm **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICspAlgorithm _                      ' __in ICspAlgorithm *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemByName <1610743814> ( _             ' VTable offset = 52
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   ) AS ICspAlgorithm                                   ' __retval_out ICspAlgorithm **ppValue
   ' =====================================================================================
   PROPERTY GET IndexByObjectId <1610743815> ( _        ' VTable offset = 56
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspAlgorithms_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspInformation
' IID = {728AB307-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspInformation_INTERFACE_DEFINED)
    %ICspInformation_INTERFACE_DEFINED = 1

INTERFACE ICspInformation $IID_ICspInformation

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeFromName <1610743808> ( _           ' VTable offset = 28
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromType <1610743809> ( _           ' VTable offset = 32
     BYVAL Type AS LONG _                               ' __in X509ProviderType Type
   , BYVAL pAlgorithm AS IObjectId _                    ' __in IObjectId *pAlgorithm
   , BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspAlgorithms <1610743810> ( _          ' VTable offset = 36
   ) AS ICspAlgorithms                                  ' __retval_out ICspAlgorithms **ppValue
   ' =====================================================================================
   PROPERTY GET HasHardwareRandomNumberGenerator <1610743811> ( _ ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET IsHardwareDevice <1610743812> ( _       ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET IsRemovable <1610743813> ( _            ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET IsSoftwareDevice <1610743814> ( _       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET Valid <1610743815> ( _                  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET MaxKeyContainerNameLength <1610743816> ( _ ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET Name <1610743817> ( _                   ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Type <1610743818> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __retval_out X509ProviderType *pValue
   ' =====================================================================================
   PROPERTY GET Version <1610743819> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743820> ( _                ' VTable offset = 76
   ) AS LONG                                            ' __retval_out X509KeySpec *pValue
   ' =====================================================================================
   PROPERTY GET IsSmartCard <1610743821> ( _            ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD GetDefaultSecurityDescriptor <1610743822> ( _ ' VTable offset = 84
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET LegacyCsp <1610743823> ( _              ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD GetCspStatusFromOperations <1610743824> ( _   ' VTable offset = 92
     BYVAL pAlgorithm AS IObjectId _                    ' __in IObjectId *pAlgorithm
   , BYVAL Operations AS LONG _                         ' __in AlgorithmOperationFlags Operations
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspInformations
' IID = {728AB308-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspInformations_INTERFACE_DEFINED)
    %ICspInformations_INTERFACE_DEFINED = 1

INTERFACE ICspInformations $IID_ICspInformations

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICspInformation                                 ' __retval_out ICspInformation **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICspInformation _                    ' __in ICspInformation *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAvailableCsps <1610743814> ( _             ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemByName <1610743815> ( _             ' VTable offset = 56
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   ) AS ICspInformation                                 ' __retval_out ICspInformation **ppCspInformation
   ' =====================================================================================
   METHOD GetCspStatusFromProviderName <1610743816> ( _ ' VTable offset = 60
     BYVAL strProviderName AS WSTRING _                 ' __in BSTR strProviderName
   , BYVAL LegacyKeySpec AS LONG _                      ' __in X509KeySpec LegacyKeySpec
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================
   METHOD GetCspStatusesFromOperations <1610743817> ( _ ' VTable offset = 64
     BYVAL Operations AS LONG _                         ' __in AlgorithmOperationFlags Operations
   , BYVAL pCspInformation AS ICspInformation _         ' __in ICspInformation *pCspInformation
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppValue
   ' =====================================================================================
   METHOD GetEncryptionCspAlgorithms <1610743818> ( _   ' VTable offset = 68
     BYVAL pCspInformation AS ICspInformation _         ' __in ICspInformation *pCspInformation
   ) AS ICspAlgorithms                                  ' __retval_out ICspAlgorithms **ppValue
   ' =====================================================================================
   METHOD GetHashAlgorithms <1610743819> ( _            ' VTable offset = 72
     BYVAL pCspInformation AS ICspInformation _         ' __in ICspInformation *pCspInformation
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspInformations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspStatus
' IID = {728AB309-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspStatus_INTERFACE_DEFINED)
    %ICspStatus_INTERFACE_DEFINED = 1

INTERFACE ICspStatus $IID_ICspStatus

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pCsp AS ICspInformation _                    ' __in ICspInformation *pCsp
   , BYVAL pAlgorithm AS ICspAlgorithm _                ' __in ICspAlgorithm *pAlgorithm
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ordinal <1610743809> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET Ordinal <1610743809> ( _                ' VTable offset = 36
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspAlgorithm <1610743811> ( _           ' VTable offset = 40
   ) AS ICspAlgorithm                                   ' __retval_out ICspAlgorithm **ppValue
   ' =====================================================================================
   PROPERTY GET CspInformation <1610743812> ( _         ' VTable offset = 44
   ) AS ICspInformation                                 ' __retval_out ICspInformation **ppValue
   ' =====================================================================================
   PROPERTY GET EnrollmentStatus <1610743813> ( _       ' VTable offset = 48
   ) AS IX509EnrollmentStatus                           ' __retval_out IX509EnrollmentStatus **ppValue
   ' =====================================================================================
   PROPERTY GET DisplayName <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICspStatuses
' IID = {728AB30A-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICspStatuses_INTERFACE_DEFINED)
    %ICspStatuses_INTERFACE_DEFINED = 1

INTERFACE ICspStatuses $IID_ICspStatuses

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICspStatus                                      ' __retval_out ICspStatus **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        '  __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICspStatus _                         ' __in ICspStatus *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemByName <1610743814> ( _             ' VTable offset = 52
     BYVAL strCspName AS WSTRING _                      ' __in BSTR strCspName
   , BYVAL strAlgorithmName AS WSTRING _                ' __in BSTR strAlgorithmName
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================
   PROPERTY GET ItemByOrdinal <1610743815> ( _          ' VTable offset = 56
     BYVAL Ordinal AS LONG _                            ' __in LONG Ordinal
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================
   PROPERTY GET ItemByOperations <1610743816> ( _       ' VTable offset = 60
     BYVAL strCspName AS WSTRING _                      ' __in BSTR strCspName
   , BYVAL strAlgorithmName AS WSTRING _                ' __in BSTR strAlgorithmName
   , BYVAL Operations AS LONG _                         ' __in AlgorithmOperationFlags Operations
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================
   PROPERTY GET ItemByProvider <1610743817> ( _         ' VTable offset = 64
     BYVAL pCspStatus AS ICspStatus _                   ' __in ICspStatus *pCspStatus
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICspStatuses_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509PublicKey
' IID = {728AB30B-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509PublicKey_INTERFACE_DEFINED)
    %IX509PublicKey_INTERFACE_DEFINED = 1

INTERFACE IX509PublicKey $IID_IX509PublicKey

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL strEncodedKey AS WSTRING _                   ' __in BSTR strEncodedKey
   , BYVAL strEncodedParameters AS WSTRING _            ' __in BSTR strEncodedParameters
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromEncodedPublicKeyInfo <1610743809> ( _ ' VTable offset = 32
     BYVAL strEncodedPublicKeyInfo AS WSTRING _         ' __in BSTR strEncodedPublicKeyInfo
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Algorithm <1610743810> ( _              ' VTable offset = 36
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET Length <1610743811> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET EncodedKey <1610743812> ( _             ' VTable offset = 44
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET EncodedParameters <1610743813> ( _      ' VTable offset = 48
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD ComputeKeyIdentifier <1610743814> ( _         ' VTable offset = 52
     BYVAL Algorithm AS LONG _                          ' __in KeyIdentifierHashAlgorithm Algorithm
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509PublicKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509PrivateKey
' IID = {728AB30C-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509PrivateKey_INTERFACE_DEFINED)
    %IX509PrivateKey_INTERFACE_DEFINED = 1

INTERFACE IX509PrivateKey $IID_IX509PrivateKey

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Open <1610743808> ( _                         ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Create <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1610743810> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743811> ( _                       ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Verify <1610743812> ( _                       ' VTable offset = 44
     BYVAL VerifyType AS LONG _                         ' __in X509PrivateKeyVerify VerifyType
   )                                                    ' void
   ' =====================================================================================
   METHOD Import <1610743813> ( _                       ' VTable offset = 48
     BYVAL strExportType AS WSTRING _                   ' __in BSTR strExportType
   , BYVAL strEncodedKey AS WSTRING _                   ' __in BSTR strEncodedKey
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <1610743814> ( _                       ' VTable offset = 52
     BYVAL strExportType AS WSTRING _                   ' __in BSTR strExportType
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pstrEncodedKey
   ' =====================================================================================
   METHOD ExportPublicKey <1610743815> ( _              ' VTable offset = 56
   ) AS IX509PublicKey                                  ' __retval_out IX509PublicKey **ppPublicKey
   ' =====================================================================================
   PROPERTY GET ContainerName <1610743816> ( _          ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET ContainerName <1610743816> ( _          ' VTable offset = 64
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerNamePrefix <1610743818> ( _    ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET ContainerNamePrefix <1610743818> ( _    ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReaderName <1610743820> ( _             ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET ReaderName <1610743820> ( _             ' VTable offset = 80
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743822> ( _        ' VTable offset = 84
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743822> ( _        ' VTable offset = 88
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspStatus <1610743824> ( _              ' VTable offset = 92
   ) AS ICspStatus                                      ' __retval_out ICspStatus **ppValue
   ' =====================================================================================
   PROPERTY SET CspStatus <1610743824> ( _              ' VTable offset = 96
     BYVAL pValue AS ICspStatus _                       ' __in ICspStatus *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderName <1610743826> ( _           ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET ProviderName <1610743826> ( _           ' VTable offset = 104
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderType <1610743828> ( _           ' VTable offset = 108
   ) AS LONG                                            ' __retval_out X509ProviderType *pValue
   ' =====================================================================================
   PROPERTY SET ProviderType <1610743828> ( _           ' VTable offset = 112
     BYVAL Value AS LONG _                              ' __in X509ProviderType Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LegacyCsp <1610743830> ( _              ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET LegacyCsp <1610743830> ( _              ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Algorithm <1610743832> ( _              ' VTable offset = 124
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET Algorithm <1610743832> ( _              ' VTable offset = 128
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743834> ( _                ' VTable offset = 132
   ) AS LONG                                            ' __retval_out X509KeySpec *pValue
   ' =====================================================================================
   PROPERTY SET KeySpec <1610743834> ( _                ' VTable offset = 136
     BYVAL Value AS LONG _                              ' __in X509KeySpec Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Length <1610743836> ( _                 ' VTable offset = 140
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET Length <1610743836> ( _                 ' VTable offset = 144
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExportPolicy <1610743838> ( _           ' VTable offset = 148
   ) AS LONG                                            ' __retval_out X509PrivateKeyExportFlags *pValue
   ' =====================================================================================
   PROPERTY SET ExportPolicy <1610743838> ( _           ' VTable offset = 152
     BYVAL Value AS LONG _                              ' __in X509PrivateKeyExportFlags Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyUsage <1610743840> ( _               ' VTable offset = 156
   ) AS LONG                                            ' __retval_out X509PrivateKeyUsageFlags *pValue
   ' =====================================================================================
   PROPERTY SET KeyUsage <1610743840> ( _               ' VTable offset = 160
     BYVAL Value AS LONG _                              ' __in X509PrivateKeyUsageFlags Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyProtection <1610743842> ( _          ' VTable offset = 164
   ) AS LONG                                            ' __retval_out X509PrivateKeyProtection *pValue
   ' =====================================================================================
   PROPERTY SET KeyProtection <1610743842> ( _          ' VTable offset = 168
     BYVAL Value AS LONG _                              ' __in X509PrivateKeyProtection Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MachineContext <1610743844> ( _         ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET MachineContext <1610743844> ( _         ' VTable offset = 176
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecurityDescriptor <1610743846> ( _     ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET SecurityDescriptor <1610743846> ( _     ' VTable offset = 184
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Certificate <1610743848> ( _            ' VTable offset = 188
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET Certificate <1610743848> ( _            ' VTable offset = 192
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UniqueContainerName <1610743850> ( _    ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Opened <1610743851> ( _                 ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET DefaultContainer <1610743852> ( _       ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET Existing <1610743853> ( _               ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Existing <1610743853> ( _               ' VTable offset = 212
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Silent <1610743855> ( _                 ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743855> ( _                 ' VTable offset = 220
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743857> ( _           ' VTable offset = 224
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743857> ( _           ' VTable offset = 228
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743859> ( _       ' VTable offset = 232
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743859> ( _       ' VTable offset = 236
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Pin <1610743861> ( _                    ' VTable offset = 240
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <1610743862> ( _           ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET FriendlyName <1610743862> ( _           ' VTable offset = 248
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743864> ( _            ' VTable offset = 252
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET Description <1610743864> ( _            ' VTable offset = 256
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509PrivateKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Extension
' IID = {728AB30D-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509Extension_INTERFACE_DEFINED)
    %IX509Extension_INTERFACE_DEFINED = 1

INTERFACE IX509Extension $IID_IX509Extension

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Extension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Extensions
' IID = {728AB30E-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509Extensions_INTERFACE_DEFINED)
    %IX509Extensions_INTERFACE_DEFINED = 1

INTERFACE IX509Extensions $IID_IX509Extensions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IX509Extension                                  ' __retval_out IX509Extension **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IX509Extension _                     ' __in IX509Extension *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IndexByObjectId <1610743814> ( _        ' VTable offset = 52
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD AddRange <1610743815> ( _                     ' VTable offset = 56
     BYVAL pValue AS IX509Extensions _                  ' __in IX509Extensions *pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Extensions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionKeyUsage
' IID = {728AB30F-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionKeyUsage_INTERFACE_DEFINED)
    %IX509ExtensionKeyUsage_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionKeyUsage $IID_IX509ExtensionKeyUsage

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionKeyUsage Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL UsageFlags AS LONG _                         ' __in X509KeyUsageFlags UsageFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyUsage <1610809346> ( _               ' VTable offset = 56
   ) AS LONG                                            ' __retval_out X509KeyUsageFlags *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionKeyUsage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionEnhancedKeyUsage
' IID = {728AB310-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionEnhancedKeyUsage_INTERFACE_DEFINED)
    %IX509ExtensionEnhancedKeyUsage_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionEnhancedKeyUsage $IID_IX509ExtensionEnhancedKeyUsage

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionEnhancedKeyUsage Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pValue AS IObjectIds _                       ' __in IObjectIds *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnhancedKeyUsage <1610809346> ( _       ' VTable offset = 56
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionEnhancedKeyUsage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionTemplateName
' IID = {728AB311-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionTemplateName_INTERFACE_DEFINED)
    %IX509ExtensionTemplateName_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionTemplateName $IID_IX509ExtensionTemplateName

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionTemplateName Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemplateName <1610809346> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionTemplateName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionTemplate
' IID = {728AB312-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionTemplate_INTERFACE_DEFINED)
    %IX509ExtensionTemplate_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionTemplate $IID_IX509ExtensionTemplate

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionTemplate Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pTemplateOid AS IObjectId _                  ' __in IObjectId *pTemplateOid
   , BYVAL MajorVersion AS LONG _                       ' __in LONG MajorVersion
   , BYVAL MinorVersion AS LONG _                       ' __in LONG MinorVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemplateOid <1610809346> ( _            ' VTable offset = 56
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET MajorVersion <1610809347> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET MinorVersion <1610809348> ( _           ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionTemplate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAlternativeName
' IID = {728AB313-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAlternativeName_INTERFACE_DEFINED)
    %IAlternativeName_INTERFACE_DEFINED = 1

INTERFACE IAlternativeName $IID_IAlternativeName

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeFromString <1610743808> ( _         ' VTable offset = 28
     BYVAL Type AS LONG _                               ' __in AlternativeNameType Type
   , BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromRawData <1610743809> ( _        ' VTable offset = 32
     BYVAL Type AS LONG _                               ' __in AlternativeNameType Type
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strRawData AS WSTRING _                      ' __in BSTR strRawData
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromOtherName <1610743810> ( _      ' VTable offset = 36
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strRawData AS WSTRING _                      ' __in BSTR strRawData
   , BYVAL ToBeWrapped AS INTEGER _                     ' __in VARIANT_BOOL ToBeWrapped
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610743811> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out AlternativeNameType *pValue
   ' =====================================================================================
   PROPERTY GET strValue <1610743812> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743813> ( _               ' VTable offset = 48
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743814> ( _                ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAlternativeName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAlternativeNames
' IID = {728AB314-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAlternativeNames_INTERFACE_DEFINED)
    %IAlternativeNames_INTERFACE_DEFINED = 1

INTERFACE IAlternativeNames $IID_IAlternativeNames

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IAlternativeName                                ' __retval_out IAlternativeName **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IAlternativeName _                   ' __in IAlternativeName *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAlternativeNames_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionAlternativeNames
' IID = {728AB315-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionAlternativeNames_INTERFACE_DEFINED)
    %IX509ExtensionAlternativeNames_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionAlternativeNames $IID_IX509ExtensionAlternativeNames

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionAlternativeNames Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pValue AS IAlternativeNames _                ' __in IAlternativeNames *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternativeNames <1610809346> ( _       ' VTable offset = 56
   ) AS IAlternativeNames                               ' __retval_out IAlternativeNames **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionAlternativeNames_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionBasicConstraints
' IID = {728AB316-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionBasicConstraints_INTERFACE_DEFINED)
    %IX509ExtensionBasicConstraints_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionBasicConstraints $IID_IX509ExtensionBasicConstraints

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionBasicConstraints Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL IsCA AS INTEGER _                            ' __in VARIANT_BOOL IsCA
   , BYVAL PathLenConstraint AS LONG _                  ' __in LONG PathLenConstraint
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsCA <1610809346> ( _                   ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET PathLenConstraint <1610809347> ( _      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionBasicConstraints_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionSubjectKeyIdentifier
' IID = {728AB317-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionSubjectKeyIdentifier_INTERFACE_DEFINED)
    %IX509ExtensionSubjectKeyIdentifier_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionSubjectKeyIdentifier $IID_IX509ExtensionSubjectKeyIdentifier

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionSubjectKeyIdentifier Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strKeyIdentifier AS WSTRING _                ' __in BSTR strKeyIdentifier
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubjectKeyIdentifier <1610809346> ( _   ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionSubjectKeyIdentifier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionAuthorityKeyIdentifier
' IID = {728AB318-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionAuthorityKeyIdentifier_INTERFACE_DEFINED)
    %IX509ExtensionAuthorityKeyIdentifier_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionAuthorityKeyIdentifier $IID_IX509ExtensionAuthorityKeyIdentifier

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionAuthorityKeyIdentifier Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strKeyIdentifier AS WSTRING _                ' __in BSTR strKeyIdentifier
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthorityKeyIdentifier <1610809346> ( _ ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionAuthorityKeyIdentifier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISmimeCapability
' IID = {728AB319-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISmimeCapability_INTERFACE_DEFINED)
    %ISmimeCapability_INTERFACE_DEFINED = 1

INTERFACE ISmimeCapability $IID_ISmimeCapability

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL BitCount AS LONG _                           ' __in LONG BitCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET BitCount <1610743810> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISmimeCapability_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISmimeCapabilities
' IID = {728AB31A-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISmimeCapabilities_INTERFACE_DEFINED)
    %ISmimeCapabilities_INTERFACE_DEFINED = 1

INTERFACE ISmimeCapabilities $IID_ISmimeCapabilities

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ISmimeCapability                                ' __retval_out ISmimeCapability **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ISmimeCapability _                   ' __in ISmimeCapability *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFromCsp <1610743814> ( _                   ' VTable offset = 52
     BYVAL pValue AS ICspInformation _                  ' __in ICspInformation *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAvailableSmimeCapabilities <1610743815> ( _ ' VTable offset = 56
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISmimeCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionSmimeCapabilities
' IID = {728AB31B-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionSmimeCapabilities_INTERFACE_DEFINED)
    %IX509ExtensionSmimeCapabilities_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionSmimeCapabilities $IID_IX509ExtensionSmimeCapabilities

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionSmimeCapabilities Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pValue AS ISmimeCapabilities _               ' __in ISmimeCapabilities *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmimeCapabilities <1610809346> ( _      ' VTable offset = 56
   ) AS ISmimeCapabilities                              ' __retval_out ISmimeCapabilities **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionSmimeCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPolicyQualifier
' IID = {728AB31C-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPolicyQualifier_INTERFACE_DEFINED)
    %IPolicyQualifier_INTERFACE_DEFINED = 1

INTERFACE IPolicyQualifier $IID_IPolicyQualifier

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeEncode <1610743808> ( _             ' VTable offset = 28
     BYVAL strQualifier AS WSTRING _                    ' __in BSTR strQualifier
   , BYVAL PolicyQualifierType AS LONG _                ' __in PolicyQualifierType Type
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET Qualifier <1610743810> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Type <1610743811> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out PolicyQualifierType *pValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPolicyQualifier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPolicyQualifiers
' IID = {728AB31D-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPolicyQualifiers_INTERFACE_DEFINED)
    %IPolicyQualifiers_INTERFACE_DEFINED = 1

INTERFACE IPolicyQualifiers $IID_IPolicyQualifiers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IPolicyQualifier                                ' __retval_out IPolicyQualifier **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IPolicyQualifier _                   ' __in IPolicyQualifier *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPolicyQualifiers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificatePolicy
' IID = {728AB31E-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificatePolicy_INTERFACE_DEFINED)
    %ICertificatePolicy_INTERFACE_DEFINED = 1

INTERFACE ICertificatePolicy $IID_ICertificatePolicy

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET PolicyQualifiers <1610743810> ( _       ' VTable offset = 36
   ) AS IPolicyQualifiers                               ' __retval_out IPolicyQualifiers **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificatePolicy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificatePolicies
' IID = {728AB31F-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificatePolicies_INTERFACE_DEFINED)
    %ICertificatePolicies_INTERFACE_DEFINED = 1

INTERFACE ICertificatePolicies $IID_ICertificatePolicies

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICertificatePolicy                              ' __retval_out ICertificatePolicy **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICertificatePolicy _                 ' __in ICertificatePolicy *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificatePolicies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionCertificatePolicies
' IID = {728AB320-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionCertificatePolicies_INTERFACE_DEFINED)
    %IX509ExtensionCertificatePolicies_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionCertificatePolicies $IID_IX509ExtensionCertificatePolicies

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionCertificatePolicies Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pValue AS ICertificatePolicies _             ' __in ICertificatePolicies *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Policies <1610809346> ( _               ' VTable offset = 56
   ) AS ICertificatePolicies                            ' __retval_out ICertificatePolicies **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionCertificatePolicies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509ExtensionMSApplicationPolicies
' IID = {728AB321-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Extension
' ########################################################################################

#IF NOT %DEF(%IX509ExtensionMSApplicationPolicies_INTERFACE_DEFINED)
    %IX509ExtensionMSApplicationPolicies_INTERFACE_DEFINED = 1

INTERFACE IX509ExtensionMSApplicationPolicies $IID_IX509ExtensionMSApplicationPolicies

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Extension Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Critical <1610743811> ( _               ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Critical <1610743811> ( _               ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509ExtensionMSApplicationPolicies Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 48
     BYVAL pValue AS ICertificatePolicies _             ' __in ICertificatePolicies *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 52
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Policies <1610809346> ( _               ' VTable offset = 56
   ) AS ICertificatePolicies                            '__retval_out ICertificatePolicies **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509ExtensionMSApplicationPolicies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Attribute
' IID = {728AB322-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509Attribute_INTERFACE_DEFINED)
    %IX509Attribute_INTERFACE_DEFINED = 1

INTERFACE IX509Attribute $IID_IX509Attribute

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL IObjectId _                                  ' __in IObjectId *pObjectId
   , BYVAL EncodingType AS LONG _                       ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Attribute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Attributes
' IID = {728AB323-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509Attributes_INTERFACE_DEFINED)
    %IX509Attributes_INTERFACE_DEFINED = 1

INTERFACE IX509Attributes $IID_IX509Attributes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IX509Attribute                                  ' __retval_out IX509Attribute **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IX509Attribute _                     ' __in IX509Attribute *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Attributes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeExtensions
' IID = {728AB324-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeExtensions_INTERFACE_DEFINED)
    %IX509AttributeExtensions_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeExtensions $IID_IX509AttributeExtensions

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeExtensions Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL pExtensions AS IX509Extensions _             ' __in IX509Extensions *pExtensions
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610809346> ( _         ' VTable offset = 48
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeExtensions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeClientId
' IID = {728AB325-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeClientId_INTERFACE_DEFINED)
    %IX509AttributeClientId_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeClientId $IID_IX509AttributeClientId

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeClientId Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL ClientId AS LONG _                           ' __in RequestClientInfoClientId ClientId
   , BYVAL strMachineDnsName AS WSTRING _               ' __in BSTR strMachineDnsName
   , BYVAL strUserSamName AS WSTRING _                  ' __in BSTR strUserSamName
   , BYVAL strProcessName AS WSTRING _                  ' __in BSTR strProcessName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610809346> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY GET MachineDnsName <1610809347> ( _         ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET UserSamName <1610809348> ( _            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET ProcessName <1610809349> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeClientId_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeRenewalCertificate
' IID = {728AB326-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeRenewalCertificate_INTERFACE_DEFINED)
    %IX509AttributeRenewalCertificate_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeRenewalCertificate $IID_IX509AttributeRenewalCertificate

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeRenewalCertificate Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCert AS WSTRING _                         ' __in BSTR strCert
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610809346> ( _     ' VTable offset = 48
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeRenewalCertificate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeArchiveKey
' IID = {728AB327-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeArchiveKey_INTERFACE_DEFINED)
    %IX509AttributeArchiveKey_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeArchiveKey $IID_IX509AttributeArchiveKey

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeArchiveKey Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL pKey AS IX509PrivateKey _                    ' __in IX509PrivateKey *pKey
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCAXCert AS WSTRING _                      ' __in BSTR strCAXCert
   , BYVAL pAlgorithm AS IObjectId _                    ' __in IObjectId *pAlgorithm
   , BYVAL EncryptionStrength AS LONG _                 ' __in LONG EncryptionStrength
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptedKeyBlob <1610809346> ( _       ' VTable offset = 48
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET EncryptionAlgorithm <1610809347> ( _    ' VTable offset = 52
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET EncryptionStrength <1610809348> ( _     ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeArchiveKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeArchiveKeyHash
' IID = {728AB328-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeArchiveKeyHash_INTERFACE_DEFINED)
    %IX509AttributeArchiveKeyHash_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeArchiveKeyHash $IID_IX509AttributeArchiveKeyHash

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeArchiveKeyHash Methods
   ' =====================================================================================
   METHOD InitializeEncodeFromEncryptedKeyBlob <1610809344> ( _ ' VTable offset = 40
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncryptedKeyBlob AS WSTRING _             ' __in BSTR strEncryptedKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptedKeyHashBlob <1610809346> ( _   ' VTable offset = 48
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeArchiveKeyHash_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeOSVersion
' IID = {728AB32A-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeOSVersion_INTERFACE_DEFINED)
    %IX509AttributeOSVersion_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeOSVersion $IID_IX509AttributeOSVersion

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeOSVersion Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL strOSVersion AS WSTRING _                    ' __in BSTR strOSVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OSVersion <1610809346> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeOSVersion_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509AttributeCspProvider
' IID = {728AB32B-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Attribute
' ########################################################################################

#IF NOT %DEF(%IX509AttributeCspProvider_INTERFACE_DEFINED)
    %IX509AttributeCspProvider_INTERFACE_DEFINED = 1

INTERFACE IX509AttributeCspProvider $IID_IX509AttributeCspProvider

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Attribute Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743809> ( _               ' VTable offset = 32
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET RawData <1610743810> ( _                ' VTable offset = 36
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509AttributeCspProvider Methods
   ' =====================================================================================
   METHOD InitializeEncode <1610809344> ( _             ' VTable offset = 40
     BYVAL KeySpec AS LONG _                            ' __in X509KeySpec KeySpec
   , BYVAL strProviderName AS WSTRING _                 ' __in BSTR strProviderName
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strSignature AS WSTRING _                    ' __in BSTR strSignature
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809345> ( _             ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610809346> ( _                ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509KeySpec *pValue
   ' =====================================================================================
   PROPERTY GET ProviderName <1610809347> ( _           ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Signature <1610809348> ( _              ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509AttributeCspProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICryptAttribute
' IID = {728AB32C-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICryptAttribute_INTERFACE_DEFINED)
    %ICryptAttribute_INTERFACE_DEFINED = 1

INTERFACE ICryptAttribute $IID_ICryptAttribute

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeFromObjectId <1610743808> ( _       ' VTable offset = 28
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromValues <1610743809> ( _         ' VTable offset = 32
     BYVAL pAttributes AS IX509Attributes _             ' __in IX509Attributes *pAttributes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectId <1610743810> ( _               ' VTable offset = 36
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET Values <1610743811> ( _                 ' VTable offset = 40
   ) AS IX509Attributes                                 ' __retval_out IX509Attributes **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICryptAttribute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICryptAttributes
' IID = {728AB32D-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICryptAttributes_INTERFACE_DEFINED)
    %ICryptAttributes_INTERFACE_DEFINED = 1

INTERFACE ICryptAttributes $IID_ICryptAttributes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICryptAttribute                                 ' __retval_out ICryptAttribute **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICryptAttribute _                    ' __in ICryptAttribute *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IndexByObjectId <1610743814> ( _        ' VTable offset = 52
     BYVAL pObjectId AS IObjectId _                     ' __in IObjectId *pObjectId
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD AddRange <1610743815> ( _                     ' VTable offset = 56
     BYVAL pValue AS ICryptAttributes _                 ' __in ICryptAttributes *pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICryptAttributes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertProperty
' IID = {728AB32E-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertProperty_INTERFACE_DEFINED)
    %ICertProperty_INTERFACE_DEFINED = 1

INTERFACE ICertProperty $IID_ICertProperty

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertProperties
' IID = {728AB32F-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertProperties_INTERFACE_DEFINED)
    %ICertProperties_INTERFACE_DEFINED = 1

INTERFACE ICertProperties $IID_ICertProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICertProperty                                   ' __retval_out ICertProperty **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICertProperty _                      ' __in ICertProperty *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743814> ( _    ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyFriendlyName
' IID = {728AB330-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyFriendlyName_INTERFACE_DEFINED)
    %ICertPropertyFriendlyName_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyFriendlyName $IID_ICertPropertyFriendlyName

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyFriendlyName Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL strFriendlyName AS WSTRING _                 ' __in BSTR strFriendlyName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <1610809345> ( _           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyFriendlyName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyDescription
' IID = {728AB331-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyDescription_INTERFACE_DEFINED)
    %ICertPropertyDescription_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyDescription $IID_ICertPropertyDescription

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyDescription Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL strDescription AS WSTRING _                  ' __in BSTR strDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610809345> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyDescription_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyAutoEnroll
' IID = {728AB332-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyAutoEnroll_INTERFACE_DEFINED)
    %ICertPropertyAutoEnroll_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyAutoEnroll $IID_ICertPropertyAutoEnroll

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyAutoEnroll Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemplateName <1610809345> ( _           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyAutoEnroll_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyRequestOriginator
' IID = {728AB333-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyRequestOriginator_INTERFACE_DEFINED)
    %ICertPropertyRequestOriginator_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyRequestOriginator $IID_ICertPropertyRequestOriginator

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyRequestOriginator Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL strRequestOriginator AS WSTRING _            ' __in BSTR strRequestOriginator
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromLocalRequestOriginator <1610809345> ( _ ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestOriginator <1610809346> ( _      ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyRequestOriginator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertySHA1Hash
' IID = {728AB334-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertySHA1Hash_INTERFACE_DEFINED)
    %ICertPropertySHA1Hash_INTERFACE_DEFINED = 1

INTERFACE ICertPropertySHA1Hash $IID_ICertPropertySHA1Hash

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertySHA1Hash Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strRenewalValue AS WSTRING _                 ' __in BSTR strRenewalValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SHA1Hash <1610809345> ( _               ' VTable offset = 60
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertySHA1Hash_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyKeyProvInfo
' IID = {728AB336-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyKeyProvInfo_INTERFACE_DEFINED)
    %ICertPropertyKeyProvInfo_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyKeyProvInfo $IID_ICertPropertyKeyProvInfo

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyKeyProvInfo Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL pValue AS IX509PrivateKey _                  ' __in IX509PrivateKey *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610809345> ( _             ' VTable offset = 60
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyKeyProvInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyArchived
' IID = {728AB337-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyArchived_INTERFACE_DEFINED)
    %ICertPropertyArchived_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyArchived $IID_ICertPropertyArchived

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyArchived Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL ArchivedValue AS INTEGER _                   ' __in VARIANT_BOOL ArchivedValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Archived <1610809345> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyArchived_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyBackedUp
' IID = {728AB338-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyBackedUp_INTERFACE_DEFINED)
    %ICertPropertyBackedUp_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyBackedUp $IID_ICertPropertyBackedUp

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyBackedUp Methods
   ' =====================================================================================
   METHOD InitializeFromCurrentTime <1610809344> ( _    ' VTable offset = 56
     BYVAL BackedUpValue AS INTEGER _                   ' __in VARIANT_BOOL BackedUpValue
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610809345> ( _                   ' VTable offset = 60
     BYVAL BackedUpValue AS INTEGER _                   ' __in VARIANT_BOOL BackedUpValue
   , BYVAL Date AS DOUBLE _                             ' __in DATE Date
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackedUpValue <1610809346> ( _          ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET BackedUpTime <1610809347> ( _           ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyBackedUp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyEnrollment
' IID = {728AB339-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyEnrollment_INTERFACE_DEFINED)
    %ICertPropertyEnrollment_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyEnrollment $IID_ICertPropertyEnrollment

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyEnrollment Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strCADnsName AS WSTRING _                    ' __in BSTR strCADnsName
   , BYVAL strCAName AS WSTRING _                       ' __in BSTR strCAName
   , OPTIONAL BYVAL strFriendlyName AS WSTRING _        ' __opt_in BSTR strFriendlyName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestId <1610809345> ( _              ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET CADnsName <1610809346> ( _              ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET CAName <1610809347> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET FriendlyName <1610809348> ( _           ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyEnrollment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyRenewal
' IID = {728AB33A-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyRenewal_INTERFACE_DEFINED)
    %ICertPropertyRenewal_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyRenewal $IID_ICertPropertyRenewal

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyRenewal Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strRenewalValue AS WSTRING _                 ' __in BSTR strRenewalValue
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificateHash <1610809345> ( _ ' VTable offset = 60
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Renewal <1610809346> ( _                ' VTable offset = 64
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyRenewal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyArchivedKeyHash
' IID = {728AB33B-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyArchivedKeyHash_INTERFACE_DEFINED)
    %ICertPropertyArchivedKeyHash_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyArchivedKeyHash $IID_ICertPropertyArchivedKeyHash

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyArchivedKeyHash Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strArchivedKeyHashValue AS WSTRING _         ' __in BSTR strArchivedKeyHashValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchivedKeyHash <1610809345> ( _        ' VTable offset = 60
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyArchivedKeyHash_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertPropertyEnrollmentPolicyServer
' IID = 728AB34A-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertProperty
' ########################################################################################

#IF NOT %DEF(%ICertPropertyEnrollmentPolicyServer_INTERFACE_DEFINED)
    %ICertPropertyEnrollmentPolicyServer_INTERFACE_DEFINED = 1

INTERFACE ICertPropertyEnrollmentPolicyServer $IID_ICertPropertyEnrollmentPolicyServer

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertProperty Methods
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610743808> ( _    ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610743809> ( _             ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyId <1610743810> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CERTENROLL_PROPERTYID *pValue
   ' =====================================================================================
   PROPERTY SET PropertyId <1610743810> ( _             ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in CERTENROLL_PROPERTYID Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743812> ( _                ' VTable offset = 44
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD RemoveFromCertificate <1610743813> ( _        ' VTable offset = 48
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValueOnCertificate <1610743814> ( _        ' VTable offset = 52
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertPropertyEnrollmentPolicyServer Methods
   ' =====================================================================================
   METHOD Initialize <1610809344> ( _                   ' VTable offset = 56
     BYVAL PropertyFlags AS DWORD _                     ' __in EnrollmentPolicyServerPropertyFlags PropertyFlags
   , BYVAL AuthFlags AS DWORD _                         ' __in X509EnrollmentAuthFlags AuthFlags
   , BYVAL EnrollmentServerAuthFlags AS DWORD _         ' __in X509EnrollmentAuthFlags EnrollmentServerAuthFlags
   , BYVAL UrlFlags AS DWORD _                          ' __in PolicyServerUrlFlags UrlFlags
   , BYVAL strRequestId AS WSTRING _                    ' __in BSTR strRequestId
   , BYVAL strUrl AS WSTRING _                          ' __in BSTR strUrl
   , BYVAL strId AS WSTRING _                           ' __in BSTR strId
   , BYVAL strEnrollmentServerUrl AS WSTRING _          ' __in BSTR strEnrollmentServerUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPolicyServerUrl <1610809345> ( _           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetPolicyServerId <1610809346> ( _            ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetEnrollmentServerUrl <1610809347> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetRequestIdString <1610809348> ( _           ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetPropertyFlags <1610809349> ( _             ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out EnrollmentPolicyServerPropertyFlags *pValue
   ' =====================================================================================
   METHOD GetUrlFlags <1610809350> ( _                  ' VTable offset = 80
   ) AS DWORD                                           ' __retval_out PolicyServerUrlFlags *pValue
   ' =====================================================================================
   METHOD GetAuthentication <1610809351> ( _            ' VTable offset = 84
   ) AS DWORD                                           ' __retval_out X509EnrollmentAuthFlags *pValue
   ' =====================================================================================
   METHOD GetEnrollmentServerAuthentication <1610809352> ( _ ' VTable offset = 88
   ) AS DWORD                                           ' __retval_out X509EnrollmentAuthFlags *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertPropertyEnrollmentPolicyServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509SignatureInformation
' IID = {728AB33C-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509SignatureInformation_INTERFACE_DEFINED)
    %IX509SignatureInformation_INTERFACE_DEFINED = 1

INTERFACE IX509SignatureInformation $IID_IX509SignatureInformation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743808> ( _          ' VTable offset = 28
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743808> ( _          ' VTable offset = 32
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PublicKeyAlgorithm <1610743810> ( _     ' VTable offset = 36
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET PublicKeyAlgorithm <1610743810> ( _     ' VTable offset = 40
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parameters <1610743812> ( _             ' VTable offset = 44
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET Parameters <1610743812> ( _             ' VTable offset = 48
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743814> ( _ ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743814> ( _ ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithmSet <1610743816> ( _ ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610743817> ( _             ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET NullSigned <1610743817> ( _             ' VTable offset = 68
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSignatureAlgorithm <1610743819> ( _        ' VTable offset = 72
     BYVAL Pkcs7Signature AS INTEGER _                  ' __in VARIANT_BOOL Pkcs7Signature
   , BYVAL SignatureKey AS INTEGER _                    ' __in VARIANT_BOOL SignatureKey
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   METHOD SetDefaultValues <1610743820> ( _             ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509SignatureInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISignerCertificate
' IID = {728AB33D-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISignerCertificate_INTERFACE_DEFINED)
    %ISignerCertificate_INTERFACE_DEFINED = 1

INTERFACE ISignerCertificate $IID_ISignerCertificate

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL MachineContext AS INTEGER _                  ' __in VARIANT_BOOL MachineContext
   , BYVAL VerifyType AS LONG _                         ' __in X509PrivateKeyVerify VerifyType
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strCertifcate AS WSTRING _                   ' __in BSTR strCertifcate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Certificate <1610743809> ( _            ' VTable offset = 32
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610743810> ( _             ' VTable offset = 36
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743811> ( _                 ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743811> ( _                 ' VTable offset = 44
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743813> ( _           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743813> ( _           ' VTable offset = 52
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743815> ( _       ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743815> ( _       ' VTable offset = 60
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Pin <1610743817> ( _                    ' VTable offset = 64
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610743818> ( _   ' VTable offset = 68
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISignerCertificate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISignerCertificates
' IID = {728AB33E-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISignerCertificates_INTERFACE_DEFINED)
    %ISignerCertificates_INTERFACE_DEFINED = 1

INTERFACE ISignerCertificates $IID_ISignerCertificates

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ISignerCertificate _                 ' __in ISignerCertificate *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <1610743814> ( _                         ' VTable offset = 52
     BYVAL pSignerCert AS ISignerCertificate _          ' __in ISignerCertificate *pSignerCert
   ) AS LONG                                            ' __retval_out LONG *piSignerCert
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISignerCertificates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509NameValuePair
' IID = {728AB33F-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509NameValuePair_INTERFACE_DEFINED)
    %IX509NameValuePair_INTERFACE_DEFINED = 1

INTERFACE IX509NameValuePair $IID_IX509NameValuePair

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1610743809> ( _                  ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Name <1610743810> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509NameValuePair_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509NameValuePairs
' IID = {728AB340-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509NameValuePairs_INTERFACE_DEFINED)
    %IX509NameValuePairs_INTERFACE_DEFINED = 1

INTERFACE IX509NameValuePairs $IID_IX509NameValuePairs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IX509NameValuePair                              ' __retval_out IX509NameValuePair **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IX509NameValuePair _                 ' __in IX509NameValuePair *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509NameValuePairs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateTemplate
' IID = 54244A13-555A-4E22-896D-1B0E52F76406
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509CertificateTemplate_INTERFACE_DEFINED)
    %IX509CertificateTemplate_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateTemplate $IID_IX509CertificateTemplate

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Property <1610743808> ( _               ' VTable offset = 28
     BYVAL property AS LONG _                           ' __in enum EnrollmentTemplateProperty property
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateTemplate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateTemplates
' IID = 13B79003-2181-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509CertificateTemplates_INTERFACE_DEFINED)
    %IX509CertificateTemplates_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateTemplates $IID_IX509CertificateTemplates

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IX509CertificateTemplate _           ' __in IX509CertificateTemplate *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemByName <1610743814> ( _             ' VTable offset = 52
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppValue
   ' =====================================================================================
   PROPERTY GET ItemByOid <1610743815> ( _              ' VTable offset = 56
     BYVAL pOid AS IObjectId _                          ' __in IObjectId *pOid
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateTemplates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateTemplateWritable
' IID = F49466A7-395A-4E9E-B6E7-32B331600DC0
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509CertificateTemplateWritable_INTERFACE_DEFINED)
    %IX509CertificateTemplateWritable_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateTemplateWritable $IID_IX509CertificateTemplateWritable

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL pValue AS IX509CertificateTemplate _         ' __in IX509CertificateTemplate *pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <1610743809> ( _                       ' VTable offset = 32
     BYVAL commitFlags AS DWORD _                       ' __in CommitTemplateFlags commitFlags
   , BYVAL strServerContext AS WSTRING _                ' __in BSTR strServerContext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Property <1610743810> ( _               ' VTable offset = 36
     BYVAL property AS LONG _                           ' __in enum EnrollmentTemplateProperty property
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   PROPERTY SET Property <1610743810> ( _               ' VTable offset = 40
     BYVAL property AS LONG _                           ' __in enum EnrollmentTemplateProperty property
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Template <1610743812> ( _               ' VTable offset = 44
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateTemplateWritable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificationAuthority
' IID = 835D1F61-1E95-4BC8-B4D3-976C42B968F7
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificationAuthority_INTERFACE_DEFINED)
    %ICertificationAuthority_INTERFACE_DEFINED = 1

INTERFACE ICertificationAuthority $IID_ICertificationAuthority

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Property <1610743808> ( _               ' VTable offset = 28
     BYVAL property AS LONG _                           ' __in enum EnrollmentCAProperty property
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificationAuthority_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificationAuthorities
' IID = 835D1F61-1E95-4BC8-B4D3-976C42B968F7
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificationAuthorities_INTERFACE_DEFINED)
    %ICertificationAuthorites_INTERFACE_DEFINED = 1

INTERFACE ICertificationAuthorities $IID_ICertificationAuthorities

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS ICertificationAuthority                         ' __retval_out ICertificationAuthority **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICertificationAuthority _            ' __in ICertificationAuthority *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD ComputeSiteCosts <1610743814> ( _             ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ItemByName <1610743815> ( _             ' VTable offset = 56
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   ) AS ICertificationAuthority                         ' __retval_out ICertificationAuthority **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificationAuthorities_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509EnrollmentPolicyServer
' IID = 13B79026-2181-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509EnrollmentPolicyServer_INTERFACE_DEFINED)
    %IX509EnrollmentPolicyServer_INTERFACE_DEFINED = 1

INTERFACE IX509EnrollmentPolicyServer $IID_IX509EnrollmentPolicyServer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL bstrPolicyServerUrl AS WSTRING _             ' __in BSTR bstrPolicyServerUrl
   , BYVAL bstrPolicyServerId AS WSTRING _              ' __in BSTR bstrPolicyServerId
   , BYVAL authFlags AS DWORD _                         ' __in X509EnrollmentAuthFlags authFlags
   , BYVAL fIsUnTrusted AS INTEGER _                    ' __in VARIANT_BOOL fIsUnTrusted
   , BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadPolicy <1610743809> ( _                   ' VTable offset = 32
     BYVAL option AS LONG _                             ' __in X509EnrollmentPolicyLoadOption option
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTemplates <1610743810> ( _                 ' VTable offset = 36
   ) AS IX509CertificateTemplates                       ' __retval_out IX509CertificateTemplates **pTemplates
   ' =====================================================================================
   METHOD GetCAsForTemplate <1610743811> ( _            ' VTable offset = 40
     BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   ) AS ICertificationAuthorities                       ' __retval_out ICertificationAuthorities **ppCAs
   ' =====================================================================================
   METHOD GetCAs <1610743812> ( _                       ' VTable offset = 44
   ) AS ICertificationAuthorities                       ' __retval_out ICertificationAuthorities **ppCAs
   ' =====================================================================================
   METHOD Validate <1610743813> ( _                     ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCustomOids <1610743814> ( _                ' VTable offset = 52
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppObjectIds
   ' =====================================================================================
   METHOD GetNextUpdateTime <1610743815> ( _            ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   METHOD GetLastUpdateTime <1610743816> ( _            ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   METHOD GetPolicyServerUrl <1610743817> ( _           ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetPolicyServerId <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetFriendlyName <1610743819> ( _              ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetIsDefaultCEP <1610743820> ( _              ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD GetUseClientId <1610743821> ( _               ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD GetAllowUnTrustedCA <1610743822> ( _          ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD GetCachePath <1610743823> ( _                 ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetCacheDir <1610743824> ( _                  ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetAuthFlags <1610743825> ( _                 ' VTable offset = 96
   ) AS DWORD                                            ' __retval_out X509EnrollmentAuthFlags *pValue
   ' =====================================================================================
   METHOD SetCredential <1610743826> ( _                ' VTable offset = 100
     BYVAL hWndParent AS LONG _                         ' __in LONG hWndParent
   , BYVAL flag AS DWORD _                              ' __in X509EnrollmentAuthFlags flag
   , BYVAL strCredential AS WSTRING _                   ' __in BSTR strCredential
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryChanges <1610743827> ( _                 ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   METHOD InitializeImport <1610743828> ( _             ' VTable offset = 108
     BYVAL val AS VARIANT _                             ' __in VARIANT val
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <1610743829> ( _                       ' VTable offset = 112
     BYVAL exportFlags AS DWORD _                       ' __in X509EnrollmentPolicyExportFlags exportFlags
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET Cost <1610743830> ( _                   ' VTable offset = 116
   ) AS DWORD                                          ' __retval_out DWORD *pValue
   ' =====================================================================================
   PROPERTY SET Cost <1610743830> ( _                   ' VTable offset = 120
     BYVAL value AS DWORD _                             ' __in DWORD value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509EnrollmentPolicyServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509PolicyServerUrl
' IID = 884E204A-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509PolicyServerUrl_INTERFACE_DEFINED)
    %IX509PolicyServerUrl_INTERFACE_DEFINED = 1

INTERFACE IX509PolicyServerUrl $IID_IX509PolicyServerUrl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Url <1610743809> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *ppValue
   ' =====================================================================================
   PROPERTY SET Url <1610743809> ( _                    ' VTable offset = 36
     BYVAL pValue AS WSTRING _                          ' __in BSTR pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Default <1610743811> ( _                ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Default <1610743811> ( _                ' VTable offset = 44
     BYVAL value AS INTEGER _                           ' __in VARIANT_BOOL value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <1610743813> ( _                  ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out PolicyServerUrlFlags *pValue
   ' =====================================================================================
   PROPERTY SET Flags <1610743813> ( _                  ' VTable offset = 52
     BYVAL Flags AS DWORD _                             ' __in PolicyServerUrlFlags Flags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthFlags <1610743815> ( _              ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out X509EnrollmentAuthFlags *pValue
   ' =====================================================================================
   PROPERTY SET AuthFlags <1610743815> ( _              ' VTable offset = 60
     BYVAL Flags AS DWORD _                             ' __in X509EnrollmentAuthFlags Flags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cost <1610743817> ( _                   ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out DWORD *pValue
   ' =====================================================================================
   PROPERTY SET Cost <1610743817> ( _                   ' VTable offset = 68
     BYVAL value AS DWORD _                             ' __in DWORD value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringProperty <1610743819> ( _            ' VTable offset = 72
     BYVAL propertyId AS LONG _                         ' __in PolicyServerUrlPropertyID propertyId
   ) AS WSTRING                                         ' __retval_out BSTR *ppValue
   ' =====================================================================================
   METHOD SetStringProperty <1610743820> ( _            ' VTable offset = 76
     BYVAL propertyId AS LONG _                         ' __in PolicyServerUrlPropertyID propertyId
   , BYVAL pValue AS WSTRING _                          ' __in BSTR pValue
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateRegistry <1610743821> ( _               ' VTable offset = 80
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromRegistry <1610743822> ( _           ' VTable offset = 84
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509PolicyServerUrl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509PolicyServerListManager
' IID = 884E204B-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509PolicyServerListManager_INTERFACE_DEFINED)
    %IX509PolicyServerListManager_INTERFACE_DEFINED = 1

INTERFACE IX509PolicyServerListManager $IID_IX509PolicyServerListManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemByIndex <0> ( _                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS IX509PolicyServerUrl                            ' __retval_out IX509PolicyServerUrl **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IX509PolicyServerUrl _               ' __in IX509PolicyServerUrl *pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in LONG Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610743814> ( _                   ' VTable offset = 52
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL Flags AS DWORD _                             ' __in PolicyServerUrlFlags Flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509PolicyServerListManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequest
' IID = {728AB341-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequest_INTERFACE_DEFINED)
    %IX509CertificateRequest_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequest $IID_IX509CertificateRequest

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestPkcs10
' IID = {728AB342-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequest
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestPkcs10_INTERFACE_DEFINED)
    %IX509CertificateRequestPkcs10_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestPkcs10 $IID_IX509CertificateRequestPkcs10

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs10 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKey <1610809345> ( _     ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPublicKey <1610809346> ( _      ' VTable offset = 136
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809347> ( _    ' VTable offset = 140
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809348> ( _             ' VTable offset = 144
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckSignature <1610809349> ( _               ' VTable offset = 148
     OPTIONAL BYVAL AllowedSignatureTypes AS LONG _     ' __opt_in Pkcs10AllowedSignatureTypes AllowedSignatureTypes = AllowedKeySignature
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSmartCard <1610809350> ( _                  ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610809351> ( _       ' VTable offset = 156
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET PublicKey <1610809352> ( _              ' VTable offset = 160
   ) AS IX509PublicKey                                  ' __retval_out IX509PublicKey **ppValue
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610809353> ( _             ' VTable offset = 164
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610809354> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET ReuseKey <1610809355> ( _               ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET OldCertificate <1610809356> ( _         ' VTable offset = 176
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Subject <1610809357> ( _                ' VTable offset = 180
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Subject <1610809357> ( _                ' VTable offset = 184
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspStatuses <1610809359> ( _            ' VTable offset = 188
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppValue
   ' =====================================================================================
   PROPERTY GET SmimeCapabilities <1610809360> ( _      ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SmimeCapabilities <1610809360> ( _      ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610809362> ( _   ' VTable offset = 200
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 208
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610809365> ( _        ' VTable offset = 212
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610809366> ( _         ' VTable offset = 216
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610809367> ( _     ' VTable offset = 220
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610809368> ( _           ' VTable offset = 224
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET RawDataToBeSigned <1610809369> ( _      ' VTable offset = 228
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Signature <1610809370> ( _              ' VTable offset = 232
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetCspStatuses <1610809371> ( _               ' VTable offset = 236
     BYVAL KeySpec AS LONG _                            ' __in X509KeySpec KeySpec
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppCspStatuses
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestPkcs10_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestPkcs10V2
' IID = 728AB35B-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestPkcs10
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestPkcs10V2_INTERFACE_DEFINED)
    %IX509CertificateRequestPkcs10V2_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestPkcs10V2 $IID_IX509CertificateRequestPkcs10V2

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs10 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKey <1610809345> ( _     ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPublicKey <1610809346> ( _      ' VTable offset = 136
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809347> ( _    ' VTable offset = 140
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809348> ( _             ' VTable offset = 144
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckSignature <1610809349> ( _               ' VTable offset = 148
     OPTIONAL BYVAL AllowedSignatureTypes AS LONG _     ' __opt_in Pkcs10AllowedSignatureTypes AllowedSignatureTypes = AllowedKeySignature
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSmartCard <1610809350> ( _                  ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610809351> ( _       ' VTable offset = 156
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET PublicKey <1610809352> ( _              ' VTable offset = 160
   ) AS IX509PublicKey                                  ' __retval_out IX509PublicKey **ppValue
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610809353> ( _             ' VTable offset = 164
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610809354> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET ReuseKey <1610809355> ( _               ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET OldCertificate <1610809356> ( _         ' VTable offset = 176
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Subject <1610809357> ( _                ' VTable offset = 180
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Subject <1610809357> ( _                ' VTable offset = 184
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspStatuses <1610809359> ( _            ' VTable offset = 188
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppValue
   ' =====================================================================================
   PROPERTY GET SmimeCapabilities <1610809360> ( _      ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SmimeCapabilities <1610809360> ( _      ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610809362> ( _   ' VTable offset = 200
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 208
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610809365> ( _        ' VTable offset = 212
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610809366> ( _         ' VTable offset = 216
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610809367> ( _     ' VTable offset = 220
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610809368> ( _           ' VTable offset = 224
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET RawDataToBeSigned <1610809369> ( _      ' VTable offset = 228
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Signature <1610809370> ( _              ' VTable offset = 232
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetCspStatuses <1610809371> ( _               ' VTable offset = 236
     BYVAL KeySpec AS LONG _                            ' __in X509KeySpec KeySpec
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppCspStatuses
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs10V2 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplate <1610874880> ( _       ' VTable offset = 240
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKeyTemplate <1610874881> ( _ ' VTable offset = 244
     BYVAL Context AS DWORD _                           ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPublicKeyTemplate <1610874882> ( _ ' VTable offset = 248
     BYVAL Context AS DWORD _                           ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyServer <1610874883> ( _           ' VTable offset = 252
   ) AS IX509EnrollmentPolicyServer                     ' __retval_out IX509EnrollmentPolicyServer **ppPolicyServer
   ' =====================================================================================
   PROPERTY GET Template <1610874884> ( _               ' VTable offset = 256
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppTemplate
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestPkcs10V2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestCertificate
' IID = {728AB343-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestPkcs10
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestCertificate_INTERFACE_DEFINED)
    %IX509CertificateRequestCertificate_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestCertificate $IID_IX509CertificateRequestCertificate

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs10 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKey <1610809345> ( _     ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPublicKey <1610809346> ( _      ' VTable offset = 136
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809347> ( _    ' VTable offset = 140
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809348> ( _             ' VTable offset = 144
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckSignature <1610809349> ( _               ' VTable offset = 148
     OPTIONAL BYVAL AllowedSignatureTypes AS LONG _     ' __opt_in Pkcs10AllowedSignatureTypes AllowedSignatureTypes = AllowedKeySignature
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSmartCard <1610809350> ( _                  ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610809351> ( _       ' VTable offset = 156
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET PublicKey <1610809352> ( _              ' VTable offset = 160
   ) AS IX509PublicKey                                  ' __retval_out IX509PublicKey **ppValue
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610809353> ( _             ' VTable offset = 164
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610809354> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET ReuseKey <1610809355> ( _               ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET OldCertificate <1610809356> ( _         ' VTable offset = 176
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Subject <1610809357> ( _                ' VTable offset = 180
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Subject <1610809357> ( _                ' VTable offset = 184
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspStatuses <1610809359> ( _            ' VTable offset = 188
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppValue
   ' =====================================================================================
   PROPERTY GET SmimeCapabilities <1610809360> ( _      ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SmimeCapabilities <1610809360> ( _      ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610809362> ( _   ' VTable offset = 200
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 208
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610809365> ( _        ' VTable offset = 212
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610809366> ( _         ' VTable offset = 216
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610809367> ( _     ' VTable offset = 220
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610809368> ( _           ' VTable offset = 224
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET RawDataToBeSigned <1610809369> ( _      ' VTable offset = 228
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Signature <1610809370> ( _              ' VTable offset = 232
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetCspStatuses <1610809371> ( _               ' VTable offset = 236
     BYVAL KeySpec AS LONG _                            ' __in X509KeySpec KeySpec
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppCspStatuses
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCertificate Methods
   ' =====================================================================================
   METHOD CheckPublicKeySignature <1610874880> ( _      ' VTable offset = 240
     BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Issuer <1610874881> ( _                 ' VTable offset = 244
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Issuer <1610874881> ( _                 ' VTable offset = 248
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotBefore <1610874883> ( _              ' VTable offset = 252
   ) AS DOUBLE                                          ' __retval_out DATE *pValue
   ' =====================================================================================
   PROPERTY SET NotBefore <1610874883> ( _              ' VTable offset = 256
     BYVAL Value AS DOUBLE _                            ' __in DATE Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotAfter <1610874885> ( _               ' VTable offset = 260
   ) AS DOUBLE                                          ' __retval_out DATE *pValue
   ' =====================================================================================
   PROPERTY SET NotAfter <1610874885> ( _               ' VTable offset = 264
     BYVAL Value AS DOUBLE _                            ' __in DATE Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SerialNumber <1610874887> ( _           ' VTable offset = 268
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET SerialNumber <1610874887> ( _           ' VTable offset = 272
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610874889> ( _      ' VTable offset = 276
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610874889> ( _      ' VTable offset = 280
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestCertificate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestCertificate2
' IID = 728AB35A-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestCertificate
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestCertificate2_INTERFACE_DEFINED)
    %IX509CertificateRequestCertificate2_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestCertificate2 $IID_IX509CertificateRequestCertificate2

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs10 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKey <1610809345> ( _     ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPublicKey <1610809346> ( _      ' VTable offset = 136
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809347> ( _    ' VTable offset = 140
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809348> ( _             ' VTable offset = 144
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckSignature <1610809349> ( _               ' VTable offset = 148
     OPTIONAL BYVAL AllowedSignatureTypes AS LONG _     ' __opt_in Pkcs10AllowedSignatureTypes AllowedSignatureTypes = AllowedKeySignature
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSmartCard <1610809350> ( _                  ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610809351> ( _       ' VTable offset = 156
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET PublicKey <1610809352> ( _              ' VTable offset = 160
   ) AS IX509PublicKey                                  ' __retval_out IX509PublicKey **ppValue
   ' =====================================================================================
   PROPERTY GET PrivateKey <1610809353> ( _             ' VTable offset = 164
   ) AS IX509PrivateKey                                 ' __retval_out IX509PrivateKey **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610809354> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET ReuseKey <1610809355> ( _               ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET OldCertificate <1610809356> ( _         ' VTable offset = 176
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Subject <1610809357> ( _                ' VTable offset = 180
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Subject <1610809357> ( _                ' VTable offset = 184
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspStatuses <1610809359> ( _            ' VTable offset = 188
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppValue
   ' =====================================================================================
   PROPERTY GET SmimeCapabilities <1610809360> ( _      ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SmimeCapabilities <1610809360> ( _      ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610809362> ( _   ' VTable offset = 200
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyContainerNamePrefix <1610809363> ( _ ' VTable offset = 208
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610809365> ( _        ' VTable offset = 212
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610809366> ( _         ' VTable offset = 216
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610809367> ( _     ' VTable offset = 220
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610809368> ( _           ' VTable offset = 224
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET RawDataToBeSigned <1610809369> ( _      ' VTable offset = 228
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Signature <1610809370> ( _              ' VTable offset = 232
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD GetCspStatuses <1610809371> ( _               ' VTable offset = 236
     BYVAL KeySpec AS LONG _                            ' __in X509KeySpec KeySpec
   ) AS ICspStatuses                                    ' __retval_out ICspStatuses **ppCspStatuses
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCertificate Methods
   ' =====================================================================================
   METHOD CheckPublicKeySignature <1610874880> ( _      ' VTable offset = 240
     BYVAL pPublicKey AS IX509PublicKey _               ' __in IX509PublicKey *pPublicKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Issuer <1610874881> ( _                 ' VTable offset = 244
   ) AS IX500DistinguishedName                          ' __retval_out IX500DistinguishedName **ppValue
   ' =====================================================================================
   PROPERTY SET Issuer <1610874881> ( _                 ' VTable offset = 248
     BYVAL pValue AS IX500DistinguishedName _           ' __in IX500DistinguishedName *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotBefore <1610874883> ( _              ' VTable offset = 252
   ) AS DOUBLE                                          ' __retval_out DATE *pValue
   ' =====================================================================================
   PROPERTY SET NotBefore <1610874883> ( _              ' VTable offset = 256
     BYVAL Value AS DOUBLE _                            ' __in DATE Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotAfter <1610874885> ( _               ' VTable offset = 260
   ) AS DOUBLE                                          ' __retval_out DATE *pValue
   ' =====================================================================================
   PROPERTY SET NotAfter <1610874885> ( _               ' VTable offset = 264
     BYVAL Value AS DOUBLE _                            ' __in DATE Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SerialNumber <1610874887> ( _           ' VTable offset = 268
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET SerialNumber <1610874887> ( _           ' VTable offset = 272
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610874889> ( _      ' VTable offset = 276
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610874889> ( _      ' VTable offset = 280
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCertificate2 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplate <1610940416> ( _       ' VTable offset = 284
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromPrivateKeyTemplate <1610940417> ( _ ' VTable offset = 288
     BYVAL Context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPrivateKey AS IX509PrivateKey _             ' __in IX509PrivateKey *pPrivateKey
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyServer <1610940418> ( _           ' VTable offset = 292
   ) AS IX509EnrollmentPolicyServer                     ' __retval_out ISignerCertificate **ppPolicyServer
   ' =====================================================================================
   PROPERTY GET Template <1610940419> ( _               ' VTable offset = 296
   ) AS IX509CertificateTemplate                        ' __retval_out ISignerCertificate **ppTemplate
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestCertificate2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestPkcs7
' IID = {728AB344-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequest
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestPkcs7_INTERFACE_DEFINED)
    %IX509CertificateRequestPkcs7_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestPkcs7 $IID_IX509CertificateRequestPkcs7

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs7 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809345> ( _    ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL RenewalRequest AS INTEGER _                  ' __in VARIANT_BOOL RenewalRequest
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromInnerRequest <1610809346> ( _   ' VTable offset = 136
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809347> ( _             ' VTable offset = 140
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequesterName <1610809348> ( _          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RequesterName <1610809348> ( _          ' VTable offset = 148
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610809350> ( _      ' VTable offset = 152
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610809350> ( _      ' VTable offset = 156
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestPkcs7_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestPkcs7V2
' IID = 728AB35C-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestPkcs7
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestPkcs7V2_INTERFACE_DEFINED)
    %IX509CertificateRequestPkcs7V2_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestPkcs7V2 $IID_IX509CertificateRequestPkcs7V2

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs7 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809345> ( _    ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL RenewalRequest AS INTEGER _                  ' __in VARIANT_BOOL RenewalRequest
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromInnerRequest <1610809346> ( _   ' VTable offset = 136
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809347> ( _             ' VTable offset = 140
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequesterName <1610809348> ( _          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RequesterName <1610809348> ( _          ' VTable offset = 148
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610809350> ( _      ' VTable offset = 152
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610809350> ( _      ' VTable offset = 156
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs7V2 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplate <1610874880> ( _       ' VTable offset = 160
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyServer <1610874881> ( _           ' VTable offset = 164
   ) AS IX509EnrollmentPolicyServer                     ' __retval_out IX509EnrollmentPolicyServer **ppPolicyServer
   ' =====================================================================================
   PROPERTY GET Template <1610874882> ( _               ' VTable offset = 168
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppTemplate
   ' =====================================================================================
   METHOD CheckCertificateSignature <1610874883> ( _    ' VTable offset = 172
     BYVAL ValidateCertificateChain AS INTEGER _        ' __in VARIANT_BOOL ValidateCertificateChain
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestPkcs7V2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestCmc
' IID = {728AB345-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestPkcs7
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestCmc_INTERFACE_DEFINED)
    %IX509CertificateRequestCmc_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestCmc $IID_IX509CertificateRequestCmc

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs7 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809345> ( _    ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL RenewalRequest AS INTEGER _                  ' __in VARIANT_BOOL RenewalRequest
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromInnerRequest <1610809346> ( _   ' VTable offset = 136
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809347> ( _             ' VTable offset = 140
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequesterName <1610809348> ( _          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RequesterName <1610809348> ( _          ' VTable offset = 148
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610809350> ( _      ' VTable offset = 152
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610809350> ( _      ' VTable offset = 156
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCmc Methods
   ' =====================================================================================
   METHOD InitializeFromInnerRequestTemplateName <1610874880> ( _ ' VTable offset = 160
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610874881> ( _       ' VTable offset = 164
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610874882> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610874883> ( _        ' VTable offset = 172
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET NameValuePairs <1610874884> ( _         ' VTable offset = 176
   ) AS IX509NameValuePairs                             ' __retval_out IX509NameValuePairs **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610874885> ( _         ' VTable offset = 180
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610874886> ( _     ' VTable offset = 184
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610874887> ( _           ' VTable offset = 188
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET TransactionId <1610874888> ( _          ' VTable offset = 192
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET TransactionId <1610874888> ( _          ' VTable offset = 196
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderNonce <1610874890> ( _            ' VTable offset = 200
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET SenderNonce <1610874890> ( _            ' VTable offset = 204
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   , BYVAL pValue AS WSTRING _                          ' __in BSTR pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610874892> ( _   ' VTable offset = 208
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET ArchivePrivateKey <1610874893> ( _      ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET ArchivePrivateKey <1610874893> ( _      ' VTable offset = 216
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyArchivalCertificate <1610874895> ( _ ' VTable offset = 220
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyArchivalCertificate <1610874895> ( _ ' VTable offset = 224
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptionAlgorithm <1610874897> ( _    ' VTable offset = 228
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET EncryptionAlgorithm <1610874897> ( _    ' VTable offset = 232
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptionStrength <1610874899> ( _     ' VTable offset = 236
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET EncryptionStrength <1610874899> ( _     ' VTable offset = 240
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptedKeyHash <1610874901> ( _       ' VTable offset = 244
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET SignerCertificates <1610874902> ( _     ' VTable offset = 248
   ) AS ISignerCertificates                             ' __retval_out ISignerCertificates **ppValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestCmc_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509CertificateRequestCmc2
' IID = 728AB35D-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509CertificateRequestCmc
' ########################################################################################

#IF NOT %DEF(%IX509CertificateRequestCmc2_INTERFACE_DEFINED)
    %IX509CertificateRequestCmc2_INTERFACE_DEFINED = 1

INTERFACE IX509CertificateRequestCmc2 $IID_IX509CertificateRequestCmc2

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509CertificateRequest Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD Encode <1610743809> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetForEncode <1610743810> ( _               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInnerRequest <1610743811> ( _              ' VTable offset = 40
     BYVAL Level AS LONG _                              ' __in InnerRequestLevel Level
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **ppValue
   ' =====================================================================================
   PROPERTY GET Type <1610743812> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out X509RequestType *pValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743813> ( _      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743814> ( _                 ' VTable offset = 56
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743816> ( _           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743816> ( _           ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UIContextMessage <1610743818> ( _       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET UIContextMessage <1610743818> ( _       ' VTable offset = 72
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressDefaults <1610743820> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET SuppressDefaults <1610743820> ( _       ' VTable offset = 80
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RenewalCertificate <1610743822> ( _     ' VTable offset = 84
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RenewalCertificate <1610743822> ( _     ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610743824> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out RequestClientInfoClientId *pValue
   ' =====================================================================================
   PROPERTY SET ClientId <1610743824> ( _               ' VTable offset = 96
     BYVAL Value AS LONG _                              ' __in RequestClientInfoClientId Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CspInformations <1610743826> ( _        ' VTable offset = 100
   ) AS ICspInformations                                ' __retval_out ICspInformations **ppValue
   ' =====================================================================================
   PROPERTY SET CspInformations <1610743826> ( _        ' VTable offset = 104
     BYVAL pValue AS ICspInformations _                 ' __in ICspInformations *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743828> ( _          ' VTable offset = 108
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743828> ( _          ' VTable offset = 112
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET AlternateSignatureAlgorithm <1610743830> ( _ ' VTable offset = 120
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RawData <1610743832> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestPkcs7 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610809344> ( _   ' VTable offset = 128
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromCertificate <1610809345> ( _    ' VTable offset = 132
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL RenewalRequest AS INTEGER _                  ' __in VARIANT_BOOL RenewalRequest
   , BYVAL strCertificate AS WSTRING _                  ' __in BSTR strCertificate
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   , OPTIONAL BYVAL InheritOptions AS LONG _            ' __opt_in X509RequestInheritOptions InheritOptions = InheritDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromInnerRequest <1610809346> ( _   ' VTable offset = 136
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeDecode <1610809347> ( _             ' VTable offset = 140
     BYVAL strEncodedData AS WSTRING _                  ' __in BSTR strEncodedData
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = XCN_CRYPT_STRING_BASE64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequesterName <1610809348> ( _          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET RequesterName <1610809348> ( _          ' VTable offset = 148
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignerCertificate <1610809350> ( _      ' VTable offset = 152
   ) AS ISignerCertificate                              ' __retval_out ISignerCertificate **ppValue
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610809350> ( _      ' VTable offset = 156
     BYVAL pValue AS ISignerCertificate _               ' __in ISignerCertificate *pValue
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCmc Methods
   ' =====================================================================================
   METHOD InitializeFromInnerRequestTemplateName <1610874880> ( _ ' VTable offset = 160
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemplateObjectId <1610874881> ( _       ' VTable offset = 164
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY GET NullSigned <1610874882> ( _             ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY GET CryptAttributes <1610874883> ( _        ' VTable offset = 172
   ) AS ICryptAttributes                                ' __retval_out ICryptAttributes **ppValue
   ' =====================================================================================
   PROPERTY GET NameValuePairs <1610874884> ( _         ' VTable offset = 176
   ) AS IX509NameValuePairs                             ' __retval_out IX509NameValuePairs **ppValue
   ' =====================================================================================
   PROPERTY GET X509Extensions <1610874885> ( _         ' VTable offset = 180
   ) AS IX509Extensions                                 ' __retval_out IX509Extensions **ppValue
   ' =====================================================================================
   PROPERTY GET CriticalExtensions <1610874886> ( _     ' VTable offset = 184
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET SuppressOids <1610874887> ( _           ' VTable offset = 188
   ) AS IObjectIds                                      ' __retval_out IObjectIds **ppValue
   ' =====================================================================================
   PROPERTY GET TransactionId <1610874888> ( _          ' VTable offset = 192
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET TransactionId <1610874888> ( _          ' VTable offset = 196
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderNonce <1610874890> ( _            ' VTable offset = 200
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET SenderNonce <1610874890> ( _            ' VTable offset = 204
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   , BYVAL pValue AS WSTRING _                          ' __in BSTR pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignatureInformation <1610874892> ( _   ' VTable offset = 208
   ) AS IX509SignatureInformation                       ' __retval_out IX509SignatureInformation **ppValue
   ' =====================================================================================
   PROPERTY GET ArchivePrivateKey <1610874893> ( _      ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET ArchivePrivateKey <1610874893> ( _      ' VTable offset = 216
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyArchivalCertificate <1610874895> ( _ ' VTable offset = 220
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET KeyArchivalCertificate <1610874895> ( _ ' VTable offset = 224
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptionAlgorithm <1610874897> ( _    ' VTable offset = 228
   ) AS IObjectId                                       ' __retval_out IObjectId **ppValue
   ' =====================================================================================
   PROPERTY SET EncryptionAlgorithm <1610874897> ( _    ' VTable offset = 232
     BYVAL pValue AS IObjectId _                        ' __in IObjectId *pValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptionStrength <1610874899> ( _     ' VTable offset = 236
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET EncryptionStrength <1610874899> ( _     ' VTable offset = 240
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptedKeyHash <1610874901> ( _       ' VTable offset = 244
     BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET SignerCertificates <1610874902> ( _     ' VTable offset = 248
   ) AS ISignerCertificates                             ' __retval_out ISignerCertificates **ppValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509CertificateRequestCmc2 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplate <1610940416> ( _       ' VTable offset = 252
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromInnerRequestTemplate <1610940417> ( _ ' VTable offset = 256
     BYVAL pInnerRequest AS IX509CertificateRequest _   ' __in IX509CertificateRequest *pInnerRequest
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyServer <1610940418> ( _           ' VTable offset = 260
   ) AS IX509EnrollmentPolicyServer                     ' __retval_out IX509EnrollmentPolicyServer **ppPolicyServer
   ' =====================================================================================
   PROPERTY GET Template <1610940419> ( _               ' VTable offset = 264
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppTemplate
   ' =====================================================================================
   METHOD CheckSignature <1610940420> ( _               ' VTable offset = 268
     BYVAL AllowedSignatureTypes AS DWORD _             ' __in Pkcs10AllowedSignatureTypes AllowedSignatureTypes = AllowedKeySignature
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckCertificateSignature <1610940421> ( _    ' VTable offset = 272
     BYVAL pSignerCertificate AS ISignerCertificate _   ' __in ISignerCertificate *pSignerCertificate
   , BYVAL ValidateCertificateChain AS INTEGER _        ' __in VARIANT_BOOL ValidateCertificateChain
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509CertificateRequestCmc2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Enrollment
' IID = {728AB346-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509Enrollment_INTERFACE_DEFINED)
    %IX509Enrollment_INTERFACE_DEFINED = 1

INTERFACE IX509Enrollment $IID_IX509Enrollment

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610743809> ( _   ' VTable offset = 32
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromRequest <1610743810> ( _        ' VTable offset = 36
     BYVAL pRequest AS IX509CertificateRequest _        ' __in IX509CertificateRequest *pRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRequest <1610743811> ( _                ' VTable offset = 40
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD Enroll <1610743812> ( _                       ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallResponse <1610743813> ( _              ' VTable offset = 48
     BYVAL Restrictions AS LONG _                       ' __in InstallResponseRestrictionFlags Restrictions
   , BYVAL strResponse AS WSTRING _                     ' __in BSTR strResponse
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD CreatePFX <1610743814> ( _                    ' VTable offset = 52
     BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL ExportOptions AS LONG _                      ' __in PFXExportOptions ExportOptions
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Request <1610743815> ( _                ' VTable offset = 56
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743816> ( _                 ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743816> ( _                 ' VTable offset = 64
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743818> ( _           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743818> ( _           ' VTable offset = 72
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NameValuePairs <1610743820> ( _         ' VTable offset = 76
   ) AS IX509NameValuePairs                             ' __retval_out IX509NameValuePairs **ppValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743821> ( _      ' VTable offset = 80
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Status <1610743822> ( _                 ' VTable offset = 84
   ) AS IX509EnrollmentStatus                           ' __retval_out IX509EnrollmentStatus **ppValue
   ' =====================================================================================
   PROPERTY GET Certificate <1610743823> ( _            ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Response <1610743824> ( _               ' VTable offset = 92
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET CertificateFriendlyName <1610743825> ( _ ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET CertificateFriendlyName <1610743825> ( _ ' VTable offset = 100
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CertificateDescription <1610743827> ( _ ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET CertificateDescription <1610743827> ( _ ' VTable offset = 108
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestId <1610743829> ( _              ' VTable offset = 112
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET CAConfigString <1610743830> ( _         ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Enrollment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509Enrollment2
' IID = 728AB350-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IX509Enrollment
' ########################################################################################

#IF NOT %DEF(%IX509Enrollment2_INTERFACE_DEFINED)
    %IX509Enrollment2_INTERFACE_DEFINED = 1

INTERFACE IX509Enrollment2 $IID_IX509Enrollment2

   INHERIT IDispatch

   ' =====================================================================================
   ' IX509Enrollment Methods
   ' =====================================================================================
   METHOD Initialize <1610743808> ( _                   ' VTable offset = 28
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromTemplateName <1610743809> ( _   ' VTable offset = 32
     BYVAL Context AS LONG _                            ' __in X509CertificateEnrollmentContext Context
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeFromRequest <1610743810> ( _        ' VTable offset = 36
     BYVAL pRequest AS IX509CertificateRequest _        ' __in IX509CertificateRequest *pRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRequest <1610743811> ( _                ' VTable offset = 40
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding = 1
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   METHOD Enroll <1610743812> ( _                       ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallResponse <1610743813> ( _              ' VTable offset = 48
     BYVAL Restrictions AS LONG _                       ' __in InstallResponseRestrictionFlags Restrictions
   , BYVAL strResponse AS WSTRING _                     ' __in BSTR strResponse
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD CreatePFX <1610743814> ( _                    ' VTable offset = 52
     BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL ExportOptions AS LONG _                      ' __in PFXExportOptions ExportOptions
   , OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Request <1610743815> ( _                ' VTable offset = 56
   ) AS IX509CertificateRequest                         ' __retval_out IX509CertificateRequest **pValue
   ' =====================================================================================
   PROPERTY GET Silent <1610743816> ( _                 ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================
   PROPERTY SET Silent <1610743816> ( _                 ' VTable offset = 64
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentWindow <1610743818> ( _           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY SET ParentWindow <1610743818> ( _           ' VTable offset = 72
     BYVAL Value AS LONG _                              ' __in LONG Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NameValuePairs <1610743820> ( _         ' VTable offset = 76
   ) AS IX509NameValuePairs                             ' __retval_out IX509NameValuePairs **ppValue
   ' =====================================================================================
   PROPERTY GET EnrollmentContext <1610743821> ( _      ' VTable offset = 80
   ) AS LONG                                            ' __retval_out X509CertificateEnrollmentContext *pValue
   ' =====================================================================================
   PROPERTY GET Status <1610743822> ( _                 ' VTable offset = 84
   ) AS IX509EnrollmentStatus                           ' __retval_out IX509EnrollmentStatus **ppValue
   ' =====================================================================================
   PROPERTY GET Certificate <1610743823> ( _            ' VTable offset = 88
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET Response <1610743824> ( _               ' VTable offset = 92
     OPTIONAL BYVAL Encoding AS LONG _                  ' __opt_in EncodingType Encoding
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY GET CertificateFriendlyName <1610743825> ( _ ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET CertificateFriendlyName <1610743825> ( _ ' VTable offset = 100
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CertificateDescription <1610743827> ( _ ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================
   PROPERTY SET CertificateDescription <1610743827> ( _ ' VTable offset = 108
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestId <1610743829> ( _              ' VTable offset = 112
   ) AS LONG                                            ' __retval_out LONG *pValue
   ' =====================================================================================
   PROPERTY GET CAConfigString <1610743830> ( _         ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

   ' =====================================================================================
   ' IX509Enrollment2 Methods
   ' =====================================================================================
   METHOD InitializeFromTemplate <1610809344> ( _       ' VTable offset = 120
     BYVAL context AS DWORD _                           ' __in X509CertificateEnrollmentContext context
   , BYVAL pPolicyServer AS IX509EnrollmentPolicyServer _ ' __in IX509EnrollmentPolicyServer *pPolicyServer
   , BYVAL pTemplate AS IX509CertificateTemplate _      ' __in IX509CertificateTemplate *pTemplate
   )                                                    ' void
   ' =====================================================================================
   METHOD InstallResponse2 <1610809345> ( _             ' VTable offset = 124
     BYVAL Restrictions AS LONG _                       ' __in InstallResponseRestrictionFlags Restrictions
   , BYVAL strResponse AS WSTRING _                     ' __in BSTR strResponse
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL strEnrollmentPolicyServerUrl AS WSTRING _    ' __in BSTR strEnrollmentPolicyServerUrl
   , BYVAL strEnrollmentPolicyServerID AS WSTRING _     ' __in BSTR strEnrollmentPolicyServerID
   , BYVAL EnrollmentPolicyServerFlags AS DWORD _       ' __in PolicyServerUrlFlags EnrollmentPolicyServerFlags
   , BYVAL authFlags AS DWORD _                         ' __in X509EnrollmentAuthFlags authFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyServer <1610809346> ( _           ' VTable offset = 128
   ) AS IX509EnrollmentPolicyServer                     ' __retval_out IX509EnrollmentPolicyServer **ppPolicyServer
   ' =====================================================================================
   PROPERTY GET Template <1610809347> ( _               ' VTable offset = 132
   ) AS IX509CertificateTemplate                        ' __retval_out IX509CertificateTemplate **ppTemplate
   ' =====================================================================================
   PROPERTY GET RequestIdString <1610809348> ( _        ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509Enrollment2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509EnrollmentHelper
' IID = 728AB351-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509EnrollmentHelper_INTERFACE_DEFINED)
    %IX509EnrollmentHelper_INTERFACE_DEFINED = 1

INTERFACE IX509EnrollmentHelper $IID_IX509EnrollmentHelper

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddPolicyServer <1610743808> ( _              ' VTable offset = 28
     BYVAL strEnrollmentPolicyServerURI AS WSTRING _    ' __in BSTR strEnrollmentPolicyServerURI
   , BYVAL strEnrollmentPolicyID AS WSTRING _           ' __in BSTR strEnrollmentPolicyID
   , BYVAL EnrollmentPolicyServerFlags AS DWORD _       ' __in PolicyServerUrlFlags EnrollmentPolicyServerFlags
   , BYVAL authFlags AS DWORD _                         ' __in X509EnrollmentAuthFlags authFlags
   , BYVAL strCredential AS WSTRING _                   ' __in BSTR strCredential
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD AddEnrollmentServer <1610743809> ( _          ' VTable offset = 32
     BYVAL strEnrollmentServerURI AS WSTRING _          ' __in BSTR strEnrollmentServerURI
   , BYVAL authFlags AS DWORD _                         ' __in X509EnrollmentAuthFlags authFlags
   , BYVAL strCredential AS WSTRING _                   ' __in BSTR strCredential
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Enroll <1610743810> ( _                       ' VTable offset = 36
     BYVAL strEnrollmentPolicyServerURI AS WSTRING _    ' __in BSTR strEnrollmentPolicyServerURI
   , BYVAL strTemplateName AS WSTRING _                 ' __in BSTR strTemplateName
   , BYVAL Encoding AS LONG _                           ' __in EncodingType Encoding
   , BYVAL enrollFlags AS DWORD _                       ' __in WebEnrollmentFlags enrollFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================
   METHOD Initialize <1610743811> ( _                   ' VTable offset = 40
     BYVAL Context AS DWORD _                           ' __in X509CertificateEnrollmentContext Context
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509EnrollmentHelper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509EnrollmentWebClassFactory
' IID = {728AB349-217D-11DA-B2A4-000E7BBB2B09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509EnrollmentWebClassFactory_INTERFACE_DEFINED)
    %IX509EnrollmentWebClassFactory_INTERFACE_DEFINED = 1

INTERFACE IX509EnrollmentWebClassFactory $IID_IX509EnrollmentWebClassFactory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateObject <1610743808> ( _                 ' VTable offset = 28
     BYVAL strProgID AS WSTRING _                       ' __in BSTR strProgID
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509EnrollmentWebClassFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IX509MachineEnrollmentFactory
' IID = 728AB352-217D-11DA-B2A4-000E7BBB2B09
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IX509MachineEnrollmentFactory_INTERFACE_DEFINED)
    %IX509MachineEnrollmentFactory_INTERFACE_DEFINED = 1

INTERFACE IX509MachineEnrollmentFactory $IID_IX509MachineEnrollmentFactory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateObject <1610743808> ( _                 ' VTable offset = 28
     BYVAL strProgID AS WSTRING _                       ' __in BSTR strProgID
   ) AS IX509EnrollmentHelper                           ' __retval_out IX509EnrollmentHelper **ppIHelper
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IX509MachineEnrollmentFactory_INTERFACE_DEFINED__ */
