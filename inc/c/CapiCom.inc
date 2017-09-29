' ########################################################################################
' Microsoft Windows
' File: CapiCom.inc
' Library name: CAPICOM
' Version: 2.1, Locale ID = 0
' Library GUID: {BD26B198-EE42-4725-9B23-AFA912434229}
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\CAPICOM\CapiCom.dll
' Contents: CAPICOM v2.1 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAPICOM_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {54BA1E8F-818D-407F-949D-BAE1692C5C18}
$PROGID_Attribute1 = "CAPICOM.Attribute.1"
' CLSID = {9171C115-7DD9-46BA-B1E5-0ED50AFFC1B8}
$PROGID_Certificate3 = "CAPICOM.Certificate.3"
' CLSID = {17E3A1C3-EA8A-4970-AF29-7F54610B1D4C}
$PROGID_Certificates3 = "CAPICOM.Certificates.3"
' CLSID = {550C8FFB-4DC0-4756-828C-862E6D0AE74F}
$PROGID_Chain3 = "CAPICOM.Chain.3"
' CLSID = {A440BD76-CFE1-4D46-AB1F-15F238437A3D}
$PROGID_EncryptedData1 = "CAPICOM.EncryptedData.1"
' CLSID = {F3A12E08-EDE9-4160-8B51-334D982A9AD0}
$PROGID_EnvelopedData1 = "CAPICOM.EnvelopedData.1"
' CLSID = {9E7EA907-5810-4FCA-B817-CD0BBA8496FC}
$PROGID_ExtendedProperty1 = "CAPICOM.ExtendedProperty.1"
' CLSID = {CE32ABF6-475D-41F6-BF82-D27F03E3D38B}
$PROGID_HashedData1 = "CAPICOM.HashedData.1"
' CLSID = {7BF3AC5C-CC84-429A-ACA5-74D916AD6B8C}
$PROGID_OID1 = "CAPICOM.OID.1"
' CLSID = {03ACC284-B757-4B8F-9951-86E600D2CD06}
$PROGID_PrivateKey1 = "CAPICOM.PrivateKey.1"
' CLSID = {A996E48C-D3DC-4244-89F7-AFA33EC60679}
$PROGID_Settings1 = "CAPICOM.Settings.1"
' CLSID = {8C3E4934-9FA4-4693-9253-A29A05F99186}
$PROGID_SignedCode1 = "CAPICOM.SignedCode.1"
' CLSID = {94AFFFCC-6C05-4814-B123-A941105AA77F}
$PROGID_SignedData1 = "CAPICOM.SignedData.1"
' CLSID = {60A9863A-11FD-4080-850E-A8E184FC3A3C}
$PROGID_Signer2 = "CAPICOM.Signer.2"
' CLSID = {91D221C4-0CD4-461C-A728-01D509321556}
$PROGID_Store3 = "CAPICOM.Store.3"
' CLSID = {22A85CE1-F011-4231-B9E4-7E7A0438F71B}
$PROGID_Utilities1 = "CAPICOM.Utilities.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {54BA1E8F-818D-407F-949D-BAE1692C5C18}
$PROGID_Attribute = "CAPICOM.Attribute"
' CLSID = {9171C115-7DD9-46BA-B1E5-0ED50AFFC1B8}
$PROGID_Certificate = "CAPICOM.Certificate"
' CLSID = {17E3A1C3-EA8A-4970-AF29-7F54610B1D4C}
$PROGID_Certificates = "CAPICOM.Certificates"
' CLSID = {550C8FFB-4DC0-4756-828C-862E6D0AE74F}
$PROGID_Chain = "CAPICOM.Chain"
' CLSID = {A440BD76-CFE1-4D46-AB1F-15F238437A3D}
$PROGID_EncryptedData = "CAPICOM.EncryptedData"
' CLSID = {F3A12E08-EDE9-4160-8B51-334D982A9AD0}
$PROGID_EnvelopedData = "CAPICOM.EnvelopedData"
' CLSID = {9E7EA907-5810-4FCA-B817-CD0BBA8496FC}
$PROGID_ExtendedProperty = "CAPICOM.ExtendedProperty"
' CLSID = {CE32ABF6-475D-41F6-BF82-D27F03E3D38B}
$PROGID_HashedData = "CAPICOM.HashedData"
' CLSID = {7BF3AC5C-CC84-429A-ACA5-74D916AD6B8C}
$PROGID_OID = "CAPICOM.OID"
' CLSID = {03ACC284-B757-4B8F-9951-86E600D2CD06}
$PROGID_PrivateKey = "CAPICOM.PrivateKey"
' CLSID = {A996E48C-D3DC-4244-89F7-AFA33EC60679}
$PROGID_Settings = "CAPICOM.Settings"
' CLSID = {8C3E4934-9FA4-4693-9253-A29A05F99186}
$PROGID_SignedCode = "CAPICOM.SignedCode"
' CLSID = {94AFFFCC-6C05-4814-B123-A941105AA77F}
$PROGID_SignedData = "CAPICOM.SignedData"
' CLSID = {60A9863A-11FD-4080-850E-A8E184FC3A3C}
$PROGID_Signer = "CAPICOM.Signer"
' CLSID = {91D221C4-0CD4-461C-A728-01D509321556}
$PROGID_Store = "CAPICOM.Store"
' CLSID = {22A85CE1-F011-4231-B9E4-7E7A0438F71B}
$PROGID_Utilities = "CAPICOM.Utilities"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Algorithm = GUID$("{A1EEF42F-5026-4A32-BC5C-2E552B70FD96}")
$CLSID_Attributes = GUID$("{933013A9-64C8-4485-ACEF-4908C3692A33}")
$CLSID_BasicConstraints = GUID$("{C05AAC6E-3A58-45A9-A203-56952E961E48}")
$CLSID_CertificatePolicies = GUID$("{988583C2-00C7-4D22-9241-E810E35EED1B}")
$CLSID_CertificateStatus = GUID$("{0EF24D18-BD9B-47D4-9458-E05B489FB7BA}")
$CLSID_EKU = GUID$("{8535F9A1-738A-40D0-8FB1-10CC8F74E7D3}")
$CLSID_EKUs = GUID$("{F1800663-5BFC-4D1A-8D44-56CE02DDA34F}")
$CLSID_EncodedData = GUID$("{7083C0AA-E7B9-48A4-8EFB-D6A109EBEC13}")
$CLSID_ExtendedKeyUsage = GUID$("{42C18607-1B4B-4126-8F1B-76E2DC7F631A}")
$CLSID_ExtendedProperties = GUID$("{90E7143D-1A07-438D-8F85-3DBB0B73D314}")
$CLSID_Extension = GUID$("{D2359E2C-82D6-458F-BB6F-41559155E693}")
$CLSID_Extensions = GUID$("{7C92E131-C1DC-4CA1-B02C-F513A08B41ED}")
$CLSID_KeyUsage = GUID$("{9226C95C-38BE-4CC4-B3A2-A867F5199C13}")
$CLSID_NoticeNumbers = GUID$("{A6FDF22A-8E00-464B-B15D-1A891D88B6ED}")
$CLSID_OIDs = GUID$("{FD661131-D716-4D15-A187-AEAAB161C8AD}")
$CLSID_PolicyInformation = GUID$("{0AAF88F4-1C22-4F65-A0E3-289D97DCE994}")
$CLSID_PublicKey = GUID$("{301FC658-4055-4D76-9703-AA38E6D7236A}")
$CLSID_Qualifier = GUID$("{E5F29B74-0902-4654-8A9A-21C5201DFA61}")
$CLSID_Qualifiers = GUID$("{6C8006C0-F649-4783-B4A6-617DD0B270C7}")
$CLSID_Recipients = GUID$("{96A1B8B0-8F9A-436A-84DE-E23CD6818DA5}")
$CLSID_Signers = GUID$("{1314C1D8-D3A8-4F8A-BED0-811FD7A8A633}")
$CLSID_Template = GUID$("{61F0D2BD-373E-4F3C-962E-59B7C42C1B22}")
$CLSID_Attribute = GUID$("{54BA1E8F-818D-407F-949D-BAE1692C5C18}")
$CLSID_Certificate = GUID$("{9171C115-7DD9-46BA-B1E5-0ED50AFFC1B8}")
$CLSID_Certificates = GUID$("{17E3A1C3-EA8A-4970-AF29-7F54610B1D4C}")
$CLSID_Chain = GUID$("{550C8FFB-4DC0-4756-828C-862E6D0AE74F}")
$CLSID_EncryptedData = GUID$("{A440BD76-CFE1-4D46-AB1F-15F238437A3D}")
$CLSID_EnvelopedData = GUID$("{F3A12E08-EDE9-4160-8B51-334D982A9AD0}")
$CLSID_ExtendedProperty = GUID$("{9E7EA907-5810-4FCA-B817-CD0BBA8496FC}")
$CLSID_HashedData = GUID$("{CE32ABF6-475D-41F6-BF82-D27F03E3D38B}")
$CLSID_OID = GUID$("{7BF3AC5C-CC84-429A-ACA5-74D916AD6B8C}")
$CLSID_PrivateKey = GUID$("{03ACC284-B757-4B8F-9951-86E600D2CD06}")
$CLSID_Settings = GUID$("{A996E48C-D3DC-4244-89F7-AFA33EC60679}")
$CLSID_SignedCode = GUID$("{8C3E4934-9FA4-4693-9253-A29A05F99186}")
$CLSID_SignedData = GUID$("{94AFFFCC-6C05-4814-B123-A941105AA77F}")
$CLSID_Signer = GUID$("{60A9863A-11FD-4080-850E-A8E184FC3A3C}")
$CLSID_Store = GUID$("{91D221C4-0CD4-461C-A728-01D509321556}")
$CLSID_Utilities = GUID$("{22A85CE1-F011-4231-B9E4-7E7A0438F71B}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAlgorithm = GUID$("{BF3D04A9-B0DA-4153-B45E-6CCFA5AC715B}")
$IID_IAttribute = GUID$("{B17A8D78-B5A6-45F7-BA21-01AB94B08415}")
$IID_IAttributes = GUID$("{6ADC653E-D5B9-422A-991A-A2B0119CEDAC}")
$IID_IBasicConstraints = GUID$("{4E298C47-ABA6-459E-851B-993D6C626EAD}")
$IID_ICCertificates = GUID$("{EBDC6DC2-684D-4425-BBB7-CB4D15A088A7}")
$IID_ICertContext = GUID$("{9E7D3477-4F63-423E-8A45-E13B2BB851A2}")
$IID_ICertificate = GUID$("{0BBA0B86-766C-4755-A443-243FF2BD8D29}")
$IID_ICertificate2 = GUID$("{6FE450DC-AD32-48D4-A366-01EE7E0B1374}")
$IID_ICertificatePolicies = GUID$("{CC7A72A7-C83A-4049-85F4-4292DE9DBFD3}")
$IID_ICertificates = GUID$("{68646716-BDA0-4046-AB82-4444BC93B84A}")
$IID_ICertificates2 = GUID$("{7B57C04B-1786-4B30-A7B6-36235CD58A14}")
$IID_ICertificateStatus = GUID$("{AB769053-6D38-49D4-86EF-5FA85ED3AF27}")
$IID_ICertificateStatus2 = GUID$("{BF95660E-F743-4EAC-9DE5-960787A4606C}")
$IID_ICertificateStatus3 = GUID$("{A4EAB890-0786-406B-9B31-2746F31F8D87}")
$IID_ICertStore = GUID$("{BB3ECB9C-A83A-445C-BDB5-EFBEF691B731}")
$IID_IChain = GUID$("{77F6F881-5D3A-4F2F-AEF0-E4A2F9AA689D}")
$IID_IChain2 = GUID$("{CA65D842-2110-4073-AEE3-D0AA5F56C421}")
$IID_IChainContext = GUID$("{B27FFB30-432E-4585-A3FD-72530108CBFD}")
$IID_ICPrivateKey = GUID$("{50F241B7-A8F2-4E0A-B982-4BD7DF0CCF3C}")
$IID_ICSigner = GUID$("{8F83F792-014C-4E22-BD57-5C381E622F34}")
$IID_IEKU = GUID$("{976B7E6D-1002-4051-BFD4-824A74BD74E2}")
$IID_IEKUs = GUID$("{47C87CEC-8C4B-4E3C-8D22-34280274EFD1}")
$IID_IEncodedData = GUID$("{D3D460F2-E7F3-4AF3-8EC6-8EB68C61C567}")
$IID_IEncryptedData = GUID$("{C4778A66-972F-42E4-87C5-5CC16F7931CA}")
$IID_IEnvelopedData = GUID$("{F6CB6A20-CC18-4424-AE57-6F2AA3DC2059}")
$IID_IExtendedKeyUsage = GUID$("{7289D408-987D-45D1-8DEE-CF9E91C2E90E}")
$IID_IExtendedProperties = GUID$("{3B096E87-6218-4A3B-A880-F6CB951E7805}")
$IID_IExtendedProperty = GUID$("{ECB8A5C8-562C-4989-B49D-FA37D40F8FC4}")
$IID_IExtension = GUID$("{ED4E4ED4-FDD8-476E-AED9-5239E7948257}")
$IID_IExtensions = GUID$("{BC530D61-E692-4225-9E7A-07B90B45856A}")
$IID_IHashedData = GUID$("{9F7F23E8-06F4-42E8-B965-5CBD044BF27F}")
$IID_IKeyUsage = GUID$("{41DD35A8-9FF9-45A6-9A7C-F65B2F085D1F}")
$IID_INoticeNumbers = GUID$("{EE2C051D-33A1-4157-86B4-9280E29782F2}")
$IID_IOID = GUID$("{208E5E9B-58B1-4086-970F-161B582A846F}")
$IID_IOIDs = GUID$("{DA55E8FC-8E27-451B-AEA8-1470D80FAD42}")
$IID_IPolicyInformation = GUID$("{8973710C-8411-4951-9E65-D45FD524FFDF}")
$IID_IPrivateKey = GUID$("{659DEDC3-6C85-42DB-8527-EFCB21742862}")
$IID_IPublicKey = GUID$("{72BF9ADA-6817-4C31-B43E-25F7C7B091F4}")
$IID_IQualifier = GUID$("{3604C9DD-A22E-4A15-A469-8181C0C113DE}")
$IID_IQualifiers = GUID$("{6B5A8AB6-597D-4398-AC63-1036EF546348}")
$IID_IRecipients = GUID$("{A694C896-FC38-4C34-AE61-3B1A95984C14}")
$IID_ISettings = GUID$("{A24104F5-46D0-4C0F-926D-665565908E91}")
$IID_ISignedCode = GUID$("{84FBCB95-5600-404C-9187-AC25B4CD6E94}")
$IID_ISignedData = GUID$("{AE9C454B-FC65-4C10-B130-CD9B45BA948B}")
$IID_ISigner = GUID$("{51017B88-1913-49AD-82BE-6BB7C417DCF2}")
$IID_ISigner2 = GUID$("{625B1F55-C720-41D6-9ECF-BA59F9B85F17}")
$IID_ISigners = GUID$("{5A0780F8-9E6B-4BB0-BF54-87CD9627A8B4}")
$IID_IStore = GUID$("{E860EF75-1B63-4254-AF47-960DAA3DD337}")
$IID_IStore2 = GUID$("{4DA6ABC4-BDCD-4317-B650-262075B93A9C}")
$IID_IStore3 = GUID$("{F701F8EC-31C7-48FB-B621-5DE417C3A607}")
$IID_ITemplate = GUID$("{5F10FFCE-C922-476F-AA76-DF99D5BDFA2C}")
$IID_IUtilities = GUID$("{EB166CF6-2AE6-44DA-BD96-0C1635D183FE}")

' ========================================================================================
' CAPICOM_ERROR_CODE enum
' ========================================================================================

MACRO CAPICOM_ERROR_CODE = LONG
%CAPICOM_E_ENCODE_INVALID_TYPE                          = &H80880100&
%CAPICOM_E_EKU_INVALID_OID                              = &H80880200&
%CAPICOM_E_EKU_OID_NOT_INITIALIZED                      = &H80880201&
%CAPICOM_E_CERTIFICATE_NOT_INITIALIZED                  = &H80880210&
%CAPICOM_E_CERTIFICATE_NO_PRIVATE_KEY                   = &H80880211&
%CAPICOM_E_CHAIN_NOT_BUILT                              = &H80880220&
%CAPICOM_E_STORE_NOT_OPENED                             = &H80880230&
%CAPICOM_E_STORE_EMPTY                                  = &H80880231&
%CAPICOM_E_STORE_INVALID_OPEN_MODE                      = &H80880232&
%CAPICOM_E_STORE_INVALID_SAVE_AS_TYPE                   = &H80880233&
%CAPICOM_E_ATTRIBUTE_NAME_NOT_INITIALIZED               = &H80880240&
%CAPICOM_E_ATTRIBUTE_VALUE_NOT_INITIALIZED              = &H80880241&
%CAPICOM_E_ATTRIBUTE_INVALID_NAME                       = &H80880242&
%CAPICOM_E_ATTRIBUTE_INVALID_VALUE                      = &H80880243&
%CAPICOM_E_SIGNER_NOT_INITIALIZED                       = &H80880250&
%CAPICOM_E_SIGNER_NOT_FOUND                             = &H80880251&
%CAPICOM_E_SIGNER_NO_CHAIN                              = &H80880252&
%CAPICOM_E_SIGNER_INVALID_USAGE                         = &H80880253&
%CAPICOM_E_SIGN_NOT_INITIALIZED                         = &H80880260&
%CAPICOM_E_SIGN_INVALID_TYPE                            = &H80880261&
%CAPICOM_E_SIGN_NOT_SIGNED                              = &H80880262&
%CAPICOM_E_INVALID_ALGORITHM                            = &H80880270&
%CAPICOM_E_INVALID_KEY_LENGTH                           = &H80880271&
%CAPICOM_E_ENVELOP_NOT_INITIALIZED                      = &H80880280&
%CAPICOM_E_ENVELOP_INVALID_TYPE                         = &H80880281&
%CAPICOM_E_ENVELOP_NO_RECIPIENT                         = &H80880282&
%CAPICOM_E_ENVELOP_RECIPIENT_NOT_FOUND                  = &H80880283&
%CAPICOM_E_ENCRYPT_NOT_INITIALIZED                      = &H80880290&
%CAPICOM_E_ENCRYPT_INVALID_TYPE                         = &H80880291&
%CAPICOM_E_ENCRYPT_NO_SECRET                            = &H80880292&
%CAPICOM_E_NOT_SUPPORTED                                = &H80880900&
%CAPICOM_E_UI_DISABLED                                  = &H80880901&
%CAPICOM_E_CANCELLED                                    = &H80880902&
%CAPICOM_E_NOT_ALLOWED                                  = &H80880903&
%CAPICOM_E_OUT_OF_RESOURCE                              = &H80880904&
%CAPICOM_E_INTERNAL                                     = &H80880911&
%CAPICOM_E_UNKNOWN                                      = &H80880999&
%CAPICOM_E_PRIVATE_KEY_NOT_INITIALIZED                  = &H80880300&
%CAPICOM_E_PRIVATE_KEY_NOT_EXPORTABLE                   = &H80880301&
%CAPICOM_E_ENCODE_NOT_INITIALIZED                       = &H80880320&
%CAPICOM_E_EXTENSION_NOT_INITIALIZED                    = &H80880330&
%CAPICOM_E_PROPERTY_NOT_INITIALIZED                     = &H80880340&
%CAPICOM_E_FIND_INVALID_TYPE                            = &H80880350&
%CAPICOM_E_FIND_INVALID_PREDEFINED_POLICY               = &H80880351&
%CAPICOM_E_CODE_NOT_INITIALIZED                         = &H80880360&
%CAPICOM_E_CODE_NOT_SIGNED                              = &H80880361&
%CAPICOM_E_CODE_DESCRIPTION_NOT_INITIALIZED             = &H80880362&
%CAPICOM_E_CODE_DESCRIPTION_URL_NOT_INITIALIZED         = &H80880363&
%CAPICOM_E_CODE_INVALID_TIMESTAMP_URL                   = &H80880364&
%CAPICOM_E_HASH_NO_DATA                                 = &H80880370&
%CAPICOM_E_INVALID_CONVERT_TYPE                         = &H80880380&

' ========================================================================================
' CAPICOM_ENCODING_TYPE enum
' ========================================================================================

MACRO CAPICOM_ENCODING_TYPE = DWORD
%CAPICOM_ENCODE_BASE64                                  = 0???
%CAPICOM_ENCODE_BINARY                                  = 1???
%CAPICOM_ENCODE_ANY                                     = &HFFFFFFFF???

' ========================================================================================
' CAPICOM_EKU enum
' ========================================================================================

MACRO CAPICOM_EKU = LONG
%CAPICOM_EKU_OTHER                                      = 0&
%CAPICOM_EKU_SERVER_AUTH                                = 1&
%CAPICOM_EKU_CLIENT_AUTH                                = 2&
%CAPICOM_EKU_CODE_SIGNING                               = 3&
%CAPICOM_EKU_EMAIL_PROTECTION                           = 4&
%CAPICOM_EKU_SMARTCARD_LOGON                            = 5&
%CAPICOM_EKU_ENCRYPTING_FILE_SYSTEM                     = 6&

' ========================================================================================
' CAPICOM_CHECK_FLAG enum
' ========================================================================================

MACRO CAPICOM_CHECK_FLAG = LONG
%CAPICOM_CHECK_NONE                                     = 0&
%CAPICOM_CHECK_TRUSTED_ROOT                             = 1&
%CAPICOM_CHECK_TIME_VALIDITY                            = 2&
%CAPICOM_CHECK_SIGNATURE_VALIDITY                       = 4&
%CAPICOM_CHECK_ONLINE_REVOCATION_STATUS                 = 8&
%CAPICOM_CHECK_OFFLINE_REVOCATION_STATUS                = 16&
%CAPICOM_CHECK_COMPLETE_CHAIN                           = 32&
%CAPICOM_CHECK_NAME_CONSTRAINTS                         = 64&
%CAPICOM_CHECK_BASIC_CONSTRAINTS                        = 128&
%CAPICOM_CHECK_NESTED_VALIDITY_PERIOD                   = 256&
%CAPICOM_CHECK_ONLINE_ALL                               = 495&
%CAPICOM_CHECK_OFFLINE_ALL                              = 503&

' ========================================================================================
' CAPICOM_CERT_INFO_TYPE enum
' ========================================================================================

MACRO CAPICOM_CERT_INFO_TYPE = LONG
%CAPICOM_CERT_INFO_SUBJECT_SIMPLE_NAME                  = 0&
%CAPICOM_CERT_INFO_ISSUER_SIMPLE_NAME                   = 1&
%CAPICOM_CERT_INFO_SUBJECT_EMAIL_NAME                   = 2&
%CAPICOM_CERT_INFO_ISSUER_EMAIL_NAME                    = 3&
%CAPICOM_CERT_INFO_SUBJECT_UPN                          = 4&
%CAPICOM_CERT_INFO_ISSUER_UPN                           = 5&
%CAPICOM_CERT_INFO_SUBJECT_DNS_NAME                     = 6&
%CAPICOM_CERT_INFO_ISSUER_DNS_NAME                      = 7&

' ========================================================================================
' CAPICOM_STORE_LOCATION enum
' ========================================================================================

MACRO CAPICOM_STORE_LOCATION = LONG
%CAPICOM_MEMORY_STORE                                   = 0&
%CAPICOM_LOCAL_MACHINE_STORE                            = 1&
%CAPICOM_CURRENT_USER_STORE                             = 2&
%CAPICOM_ACTIVE_DIRECTORY_USER_STORE                    = 3&
%CAPICOM_SMART_CARD_USER_STORE                          = 4&

' ========================================================================================
' CAPICOM_STORE_OPEN_MODE enum
' ========================================================================================

MACRO CAPICOM_STORE_OPEN_MODE = LONG
%CAPICOM_STORE_OPEN_READ_ONLY                           = 0&
%CAPICOM_STORE_OPEN_READ_WRITE                          = 1&
%CAPICOM_STORE_OPEN_MAXIMUM_ALLOWED                     = 2&
%CAPICOM_STORE_OPEN_EXISTING_ONLY                       = 128&
%CAPICOM_STORE_OPEN_INCLUDE_ARCHIVED                    = 256&

' ========================================================================================
' CAPICOM_ACTIVE_DIRECTORY_SEARCH_LOCATION enum
' ========================================================================================

MACRO CAPICOM_ACTIVE_DIRECTORY_SEARCH_LOCATION = LONG
%CAPICOM_SEARCH_ANY                                     = 0&
%CAPICOM_SEARCH_GLOBAL_CATALOG                          = 1&
%CAPICOM_SEARCH_DEFAULT_DOMAIN                          = 2&

' ========================================================================================
' CAPICOM_STORE_SAVE_AS_TYPE enum
' ========================================================================================

MACRO CAPICOM_STORE_SAVE_AS_TYPE = LONG
%CAPICOM_STORE_SAVE_AS_SERIALIZED                       = 0&
%CAPICOM_STORE_SAVE_AS_PKCS7                            = 1&

' ========================================================================================
' CAPICOM_ATTRIBUTE enum
' ========================================================================================

MACRO CAPICOM_ATTRIBUTE = LONG
%CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME           = 0&
%CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_NAME          = 1&
%CAPICOM_AUTHENTICATED_ATTRIBUTE_DOCUMENT_DESCRIPTION   = 2&

' ========================================================================================
' CAPICOM_SIGNED_DATA_VERIFY_FLAG enum
' ========================================================================================

MACRO CAPICOM_SIGNED_DATA_VERIFY_FLAG = LONG
%CAPICOM_VERIFY_SIGNATURE_ONLY                          = 0&
%CAPICOM_VERIFY_SIGNATURE_AND_CERTIFICATE               = 1&

' ========================================================================================
' CAPICOM_ENCRYPTION_ALGORITHM enum
' ========================================================================================

MACRO CAPICOM_ENCRYPTION_ALGORITHM = LONG
%CAPICOM_ENCRYPTION_ALGORITHM_RC2                       = 0&
%CAPICOM_ENCRYPTION_ALGORITHM_RC4                       = 1&
%CAPICOM_ENCRYPTION_ALGORITHM_DES                       = 2&
%CAPICOM_ENCRYPTION_ALGORITHM_3DES                      = 3&
%CAPICOM_ENCRYPTION_ALGORITHM_AES                       = 4&

' ========================================================================================
' CAPICOM_ENCRYPTION_KEY_LENGTH enum
' ========================================================================================

MACRO CAPICOM_ENCRYPTION_KEY_LENGTH = LONG
%CAPICOM_ENCRYPTION_KEY_LENGTH_MAXIMUM                  = 0&
%CAPICOM_ENCRYPTION_KEY_LENGTH_40_BITS                  = 1&
%CAPICOM_ENCRYPTION_KEY_LENGTH_56_BITS                  = 2&
%CAPICOM_ENCRYPTION_KEY_LENGTH_128_BITS                 = 3&
%CAPICOM_ENCRYPTION_KEY_LENGTH_192_BITS                 = 4&
%CAPICOM_ENCRYPTION_KEY_LENGTH_256_BITS                 = 5&

' ========================================================================================
' CAPICOM_SECRET_TYPE enum
' ========================================================================================

MACRO CAPICOM_SECRET_TYPE = LONG
%CAPICOM_SECRET_PASSWORD                                = 0&

' ========================================================================================
' CAPICOM_KEY_ALGORITHM enum
' ========================================================================================

MACRO CAPICOM_KEY_ALGORITHM = LONG
%CAPICOM_KEY_ALGORITHM_OTHER                            = 0&
%CAPICOM_KEY_ALGORITHM_RSA                              = 1&
%CAPICOM_KEY_ALGORITHM_DSS                              = 2&

' ========================================================================================
' CAPICOM_OID enum
' ========================================================================================

MACRO CAPICOM_OID = LONG
%CAPICOM_OID_OTHER                                      = 0&
%CAPICOM_OID_AUTHORITY_KEY_IDENTIFIER_EXTENSION         = 1&
%CAPICOM_OID_KEY_ATTRIBUTES_EXTENSION                   = 2&
%CAPICOM_OID_CERT_POLICIES_95_EXTENSION                 = 3&
%CAPICOM_OID_KEY_USAGE_RESTRICTION_EXTENSION            = 4&
%CAPICOM_OID_LEGACY_POLICY_MAPPINGS_EXTENSION           = 5&
%CAPICOM_OID_SUBJECT_ALT_NAME_EXTENSION                 = 6&
%CAPICOM_OID_ISSUER_ALT_NAME_EXTENSION                  = 7&
%CAPICOM_OID_BASIC_CONSTRAINTS_EXTENSION                = 8&
%CAPICOM_OID_SUBJECT_KEY_IDENTIFIER_EXTENSION           = 9&
%CAPICOM_OID_KEY_USAGE_EXTENSION                        = 10&
%CAPICOM_OID_PRIVATEKEY_USAGE_PERIOD_EXTENSION          = 11&
%CAPICOM_OID_SUBJECT_ALT_NAME2_EXTENSION                = 12&
%CAPICOM_OID_ISSUER_ALT_NAME2_EXTENSION                 = 13&
%CAPICOM_OID_BASIC_CONSTRAINTS2_EXTENSION               = 14&
%CAPICOM_OID_NAME_CONSTRAINTS_EXTENSION                 = 15&
%CAPICOM_OID_CRL_DIST_POINTS_EXTENSION                  = 16&
%CAPICOM_OID_CERT_POLICIES_EXTENSION                    = 17&
%CAPICOM_OID_POLICY_MAPPINGS_EXTENSION                  = 18&
%CAPICOM_OID_AUTHORITY_KEY_IDENTIFIER2_EXTENSION        = 19&
%CAPICOM_OID_POLICY_CONSTRAINTS_EXTENSION               = 20&
%CAPICOM_OID_ENHANCED_KEY_USAGE_EXTENSION               = 21&
%CAPICOM_OID_CERTIFICATE_TEMPLATE_EXTENSION             = 22&
%CAPICOM_OID_APPLICATION_CERT_POLICIES_EXTENSION        = 23&
%CAPICOM_OID_APPLICATION_POLICY_MAPPINGS_EXTENSION      = 24&
%CAPICOM_OID_APPLICATION_POLICY_CONSTRAINTS_EXTENSION   = 25&
%CAPICOM_OID_AUTHORITY_INFO_ACCESS_EXTENSION            = 26&
%CAPICOM_OID_SERVER_AUTH_EKU                            = 100&
%CAPICOM_OID_CLIENT_AUTH_EKU                            = 101&
%CAPICOM_OID_CODE_SIGNING_EKU                           = 102&
%CAPICOM_OID_EMAIL_PROTECTION_EKU                       = 103&
%CAPICOM_OID_IPSEC_END_SYSTEM_EKU                       = 104&
%CAPICOM_OID_IPSEC_TUNNEL_EKU                           = 105&
%CAPICOM_OID_IPSEC_USER_EKU                             = 106&
%CAPICOM_OID_TIME_STAMPING_EKU                          = 107&
%CAPICOM_OID_CTL_USAGE_SIGNING_EKU                      = 108&
%CAPICOM_OID_TIME_STAMP_SIGNING_EKU                     = 109&
%CAPICOM_OID_SERVER_GATED_CRYPTO_EKU                    = 110&
%CAPICOM_OID_ENCRYPTING_FILE_SYSTEM_EKU                 = 111&
%CAPICOM_OID_EFS_RECOVERY_EKU                           = 112&
%CAPICOM_OID_WHQL_CRYPTO_EKU                            = 113&
%CAPICOM_OID_NT5_CRYPTO_EKU                             = 114&
%CAPICOM_OID_OEM_WHQL_CRYPTO_EKU                        = 115&
%CAPICOM_OID_EMBEDED_NT_CRYPTO_EKU                      = 116&
%CAPICOM_OID_ROOT_LIST_SIGNER_EKU                       = 117&
%CAPICOM_OID_QUALIFIED_SUBORDINATION_EKU                = 118&
%CAPICOM_OID_KEY_RECOVERY_EKU                           = 119&
%CAPICOM_OID_DIGITAL_RIGHTS_EKU                         = 120&
%CAPICOM_OID_LICENSES_EKU                               = 121&
%CAPICOM_OID_LICENSE_SERVER_EKU                         = 122&
%CAPICOM_OID_SMART_CARD_LOGON_EKU                       = 123&
%CAPICOM_OID_PKIX_POLICY_QUALIFIER_CPS                  = 124&
%CAPICOM_OID_PKIX_POLICY_QUALIFIER_USERNOTICE           = 125&

' ========================================================================================
' CAPICOM_PROPID enum
' ========================================================================================

MACRO CAPICOM_PROPID = LONG
%CAPICOM_PROPID_UNKNOWN                                 = 0&
%CAPICOM_PROPID_KEY_PROV_HANDLE                         = 1&
%CAPICOM_PROPID_KEY_PROV_INFO                           = 2&
%CAPICOM_PROPID_SHA1_HASH                               = 3&
%CAPICOM_PROPID_HASH_PROP                               = 3&
%CAPICOM_PROPID_MD5_HASH                                = 4&
%CAPICOM_PROPID_KEY_CONTEXT                             = 5&
%CAPICOM_PROPID_KEY_SPEC                                = 6&
%CAPICOM_PROPID_IE30_RESERVED                           = 7&
%CAPICOM_PROPID_PUBKEY_HASH_RESERVED                    = 8&
%CAPICOM_PROPID_ENHKEY_USAGE                            = 9&
%CAPICOM_PROPID_CTL_USAGE                               = 9&
%CAPICOM_PROPID_NEXT_UPDATE_LOCATION                    = 10&
%CAPICOM_PROPID_FRIENDLY_NAME                           = 11&
%CAPICOM_PROPID_PVK_FILE                                = 12&
%CAPICOM_PROPID_DESCRIPTION                             = 13&
%CAPICOM_PROPID_ACCESS_STATE                            = 14&
%CAPICOM_PROPID_SIGNATURE_HASH                          = 15&
%CAPICOM_PROPID_SMART_CARD_DATA                         = 16&
%CAPICOM_PROPID_EFS                                     = 17&
%CAPICOM_PROPID_FORTEZZA_DATA                           = 18&
%CAPICOM_PROPID_ARCHIVED                                = 19&
%CAPICOM_PROPID_KEY_IDENTIFIER                          = 20&
%CAPICOM_PROPID_AUTO_ENROLL                             = 21&
%CAPICOM_PROPID_PUBKEY_ALG_PARA                         = 22&
%CAPICOM_PROPID_CROSS_CERT_DIST_POINTS                  = 23&
%CAPICOM_PROPID_ISSUER_PUBLIC_KEY_MD5_HASH              = 24&
%CAPICOM_PROPID_SUBJECT_PUBLIC_KEY_MD5_HASH             = 25&
%CAPICOM_PROPID_ENROLLMENT                              = 26&
%CAPICOM_PROPID_DATE_STAMP                              = 27&
%CAPICOM_PROPID_ISSUER_SERIAL_NUMBER_MD5_HASH           = 28&
%CAPICOM_PROPID_SUBJECT_NAME_MD5_HASH                   = 29&
%CAPICOM_PROPID_EXTENDED_ERROR_INFO                     = 30&
%CAPICOM_PROPID_RENEWAL                                 = 64&
%CAPICOM_PROPID_ARCHIVED_KEY_HASH                       = 65&
%CAPICOM_PROPID_FIRST_RESERVED                          = 66&
%CAPICOM_PROPID_LAST_RESERVED                           = 32767&
%CAPICOM_PROPID_FIRST_USER                              = 32768&
%CAPICOM_PROPID_LAST_USER                               = 65535&

' ========================================================================================
' CAPICOM_PROV_TYPE enum
' ========================================================================================

MACRO CAPICOM_PROV_TYPE = LONG
%CAPICOM_PROV_RSA_FULL                                  = 1&
%CAPICOM_PROV_RSA_SIG                                   = 2&
%CAPICOM_PROV_DSS                                       = 3&
%CAPICOM_PROV_FORTEZZA                                  = 4&
%CAPICOM_PROV_MS_EXCHANGE                               = 5&
%CAPICOM_PROV_SSL                                       = 6&
%CAPICOM_PROV_RSA_SCHANNEL                              = 12&
%CAPICOM_PROV_DSS_DH                                    = 13&
%CAPICOM_PROV_EC_ECDSA_SIG                              = 14&
%CAPICOM_PROV_EC_ECNRA_SIG                              = 15&
%CAPICOM_PROV_EC_ECDSA_FULL                             = 16&
%CAPICOM_PROV_EC_ECNRA_FULL                             = 17&
%CAPICOM_PROV_DH_SCHANNEL                               = 18&
%CAPICOM_PROV_SPYRUS_LYNKS                              = 20&
%CAPICOM_PROV_RNG                                       = 21&
%CAPICOM_PROV_INTEL_SEC                                 = 22&
%CAPICOM_PROV_REPLACE_OWF                               = 23&
%CAPICOM_PROV_RSA_AES                                   = 24&

' ========================================================================================
' CAPICOM_CERTIFICATE_SAVE_AS_TYPE enum
' ========================================================================================

MACRO CAPICOM_CERTIFICATE_SAVE_AS_TYPE = LONG
%CAPICOM_CERTIFICATE_SAVE_AS_PFX                        = 0&
%CAPICOM_CERTIFICATE_SAVE_AS_CER                        = 1&

' ========================================================================================
' CAPICOM_CERTIFICATES_SAVE_AS_TYPE enum
' ========================================================================================

MACRO CAPICOM_CERTIFICATES_SAVE_AS_TYPE = LONG
%CAPICOM_CERTIFICATES_SAVE_AS_SERIALIZED                = 0&
%CAPICOM_CERTIFICATES_SAVE_AS_PKCS7                     = 1&
%CAPICOM_CERTIFICATES_SAVE_AS_PFX                       = 2&

' ========================================================================================
' CAPICOM_CERTIFICATE_INCLUDE_OPTION enum
' ========================================================================================

MACRO CAPICOM_CERTIFICATE_INCLUDE_OPTION = LONG
%CAPICOM_CERTIFICATE_INCLUDE_CHAIN_EXCEPT_ROOT          = 0&
%CAPICOM_CERTIFICATE_INCLUDE_WHOLE_CHAIN                = 1&
%CAPICOM_CERTIFICATE_INCLUDE_END_ENTITY_ONLY            = 2&

' ========================================================================================
' CAPICOM_KEY_SPEC enum
' ========================================================================================

MACRO CAPICOM_KEY_SPEC = LONG
%CAPICOM_KEY_SPEC_KEYEXCHANGE                           = 1&
%CAPICOM_KEY_SPEC_SIGNATURE                             = 2&

' ========================================================================================
' CAPICOM_KEY_LOCATION enum
' ========================================================================================

MACRO CAPICOM_KEY_LOCATION = LONG
%CAPICOM_CURRENT_USER_KEY                               = 0&
%CAPICOM_LOCAL_MACHINE_KEY                              = 1&

' ========================================================================================
' CAPICOM_KEY_STORAGE_FLAG enum
' ========================================================================================

MACRO CAPICOM_KEY_STORAGE_FLAG = LONG
%CAPICOM_KEY_STORAGE_DEFAULT                            = 0&
%CAPICOM_KEY_STORAGE_EXPORTABLE                         = 1&
%CAPICOM_KEY_STORAGE_USER_PROTECTED                     = 2&

' ========================================================================================
' CAPICOM_EXPORT_FLAG enum
' ========================================================================================

MACRO CAPICOM_EXPORT_FLAG = LONG
%CAPICOM_EXPORT_DEFAULT                                 = 0&
%CAPICOM_EXPORT_IGNORE_PRIVATE_KEY_NOT_EXPORTABLE_ERROR = 1&

' ========================================================================================
' CAPICOM_KEY_USAGE enum
' ========================================================================================

MACRO CAPICOM_KEY_USAGE = LONG
%CAPICOM_DIGITAL_SIGNATURE_KEY_USAGE                    = 128&
%CAPICOM_NON_REPUDIATION_KEY_USAGE                      = 64&
%CAPICOM_KEY_ENCIPHERMENT_KEY_USAGE                     = 32&
%CAPICOM_DATA_ENCIPHERMENT_KEY_USAGE                    = 16&
%CAPICOM_KEY_AGREEMENT_KEY_USAGE                        = 8&
%CAPICOM_KEY_CERT_SIGN_KEY_USAGE                        = 4&
%CAPICOM_OFFLINE_CRL_SIGN_KEY_USAGE                     = 2&
%CAPICOM_CRL_SIGN_KEY_USAGE                             = 2&
%CAPICOM_ENCIPHER_ONLY_KEY_USAGE                        = 1&
%CAPICOM_DECIPHER_ONLY_KEY_USAGE                        = 32768&

' ========================================================================================
' CAPICOM_CERTIFICATE_FIND_TYPE enum
' ========================================================================================

MACRO CAPICOM_CERTIFICATE_FIND_TYPE = LONG
%CAPICOM_CERTIFICATE_FIND_SHA1_HASH                     = 0&
%CAPICOM_CERTIFICATE_FIND_SUBJECT_NAME                  = 1&
%CAPICOM_CERTIFICATE_FIND_ISSUER_NAME                   = 2&
%CAPICOM_CERTIFICATE_FIND_ROOT_NAME                     = 3&
%CAPICOM_CERTIFICATE_FIND_TEMPLATE_NAME                 = 4&
%CAPICOM_CERTIFICATE_FIND_EXTENSION                     = 5&
%CAPICOM_CERTIFICATE_FIND_EXTENDED_PROPERTY             = 6&
%CAPICOM_CERTIFICATE_FIND_APPLICATION_POLICY            = 7&
%CAPICOM_CERTIFICATE_FIND_CERTIFICATE_POLICY            = 8&
%CAPICOM_CERTIFICATE_FIND_TIME_VALID                    = 9&
%CAPICOM_CERTIFICATE_FIND_TIME_NOT_YET_VALID            = 10&
%CAPICOM_CERTIFICATE_FIND_TIME_EXPIRED                  = 11&
%CAPICOM_CERTIFICATE_FIND_KEY_USAGE                     = 12&

' ========================================================================================
' CAPICOM_HASH_ALGORITHM enum
' ========================================================================================

MACRO CAPICOM_HASH_ALGORITHM = LONG
%CAPICOM_HASH_ALGORITHM_SHA1                            = 0&
%CAPICOM_HASH_ALGORITHM_MD2                             = 1&
%CAPICOM_HASH_ALGORITHM_MD4                             = 2&
%CAPICOM_HASH_ALGORITHM_MD5                             = 3&
%CAPICOM_HASH_ALGORITHM_SHA_256                         = 4&
%CAPICOM_HASH_ALGORITHM_SHA_384                         = 5&
%CAPICOM_HASH_ALGORITHM_SHA_512                         = 6&

' ========================================================================================
' Module constants
' Note: Strings constants are ANSI (LPSTR).
' ========================================================================================
%CAPICOM_MAJOR_VERSION                                  = 2&
%CAPICOM_MINOR_VERSION                                  = 1&
%CAPICOM_RELEASE_NUMBER                                 = 0&
%CAPICOM_BUILD_NUMBER                                   = 1&
$CAPICOM_VERSION_INFO                                   = "CAPICOM v2.1"
$CAPICOM_COPY_RIGHT                                     = "Copyright (c) Microsoft Corporation 1999-2004. All rights reserved."
$CAPICOM_MY_STORE                                       = "My"
$CAPICOM_CA_STORE                                       = "Ca"
$CAPICOM_ROOT_STORE                                     = "Root"
$CAPICOM_OTHER_STORE                                    = "AddressBook"
$CAPICOM_OID_SERVER_AUTH                                = "1.3.6.1.5.5.7.3.1"
$CAPICOM_OID_CLIENT_AUTH                                = "1.3.6.1.5.5.7.3.2"
$CAPICOM_OID_CODE_SIGNING                               = "1.3.6.1.5.5.7.3.3"
$CAPICOM_OID_EMAIL_PROTECTION                           = "1.3.6.1.5.5.7.3.4"
$CAPICOM_OID_IPSEC_END_SYSTEM                           = "1.3.6.1.5.5.7.3.5"
$CAPICOM_OID_IPSEC_TUNNEL                               = "1.3.6.1.5.5.7.3.6"
$CAPICOM_OID_IPSEC_USER                                 = "1.3.6.1.5.5.7.3.7"
$CAPICOM_OID_TIME_STAMPING                              = "1.3.6.1.5.5.7.3.8"
$CAPICOM_OID_CTL_USAGE_SIGNING                          = "1.3.6.1.4.1.311.10.3.1"
$CAPICOM_OID_TIME_STAMP_SIGNING                         = "1.3.6.1.4.1.311.10.3.2"
$CAPICOM_OID_SERVER_GATED_CRYPTO                        = "1.3.6.1.4.1.311.10.3.3"
$CAPICOM_OID_ENCRYPTING_FILE_SYSTEM                     = "1.3.6.1.4.1.311.10.3.4"
$CAPICOM_OID_EFS_RECOVERY                               = "1.3.6.1.4.1.311.10.3.4.1"
$CAPICOM_OID_WHQL_CRYPTO                                = "1.3.6.1.4.1.311.10.3.5"
$CAPICOM_OID_NT5_CRYPTO                                 = "1.3.6.1.4.1.311.10.3.6"
$CAPICOM_OID_OEM_WHQL_CRYPTO                            = "1.3.6.1.4.1.311.10.3.7"
$CAPICOM_OID_EMBEDED_NT_CRYPTO                          = "1.3.6.1.4.1.311.10.3.8"
$CAPICOM_OID_ROOT_LIST_SIGNER                           = "1.3.6.1.4.1.311.10.3.9"
$CAPICOM_OID_QUALIFIED_SUBORDINATION                    = "1.3.6.1.4.1.311.10.3.10"
$CAPICOM_OID_KEY_RECOVERY                               = "1.3.6.1.4.1.311.10.3.11"
$CAPICOM_OID_DIGITAL_RIGHTS                             = "1.3.6.1.4.1.311.10.5.1"
$CAPICOM_OID_LICENSES                                   = "1.3.6.1.4.1.311.10.6.1"
$CAPICOM_OID_LICENSE_SERVER                             = "1.3.6.1.4.1.311.10.6.2"
$CAPICOM_OID_SMART_CARD_LOGON                           = "1.3.6.1.4.1.311.20.2.2"
$CAPICOM_SERVER_AUTH_OID                                = "1.3.6.1.5.5.7.3.1"
$CAPICOM_CLIENT_AUTH_OID                                = "1.3.6.1.5.5.7.3.2"
$CAPICOM_CODE_SIGNING_OID                               = "1.3.6.1.5.5.7.3.3"
$CAPICOM_EMAIL_PROTECTION_OID                           = "1.3.6.1.5.5.7.3.4"
$CAPICOM_IPSEC_END_SYSTEM_OID                           = "1.3.6.1.5.5.7.3.5"
$CAPICOM_IPSEC_TUNNEL_OID                               = "1.3.6.1.5.5.7.3.6"
$CAPICOM_IPSEC_USER_OID                                 = "1.3.6.1.5.5.7.3.7"
$CAPICOM_TIME_STAMPING_OID                              = "1.3.6.1.5.5.7.3.8"
$CAPICOM_CTL_USAGE_SIGNING_OID                          = "1.3.6.1.4.1.311.10.3.1"
$CAPICOM_TIME_STAMP_SIGNING_OID                         = "1.3.6.1.4.1.311.10.3.2"
$CAPICOM_SERVER_GATED_CRYPTO_OID                        = "1.3.6.1.4.1.311.10.3.3"
$CAPICOM_ENCRYPTING_FILE_SYSTEM_OID                     = "1.3.6.1.4.1.311.10.3.4"
$CAPICOM_EFS_RECOVERY_OID                               = "1.3.6.1.4.1.311.10.3.4.1"
$CAPICOM_WHQL_CRYPTO_OID                                = "1.3.6.1.4.1.311.10.3.5"
$CAPICOM_NT5_CRYPTO_OID                                 = "1.3.6.1.4.1.311.10.3.6"
$CAPICOM_OEM_WHQL_CRYPTO_OID                            = "1.3.6.1.4.1.311.10.3.7"
$CAPICOM_EMBEDED_NT_CRYPTO_OID                          = "1.3.6.1.4.1.311.10.3.8"
$CAPICOM_ROOT_LIST_SIGNER_OID                           = "1.3.6.1.4.1.311.10.3.9"
$CAPICOM_QUALIFIED_SUBORDINATION_OID                    = "1.3.6.1.4.1.311.10.3.10"
$CAPICOM_KEY_RECOVERY_OID                               = "1.3.6.1.4.1.311.10.3.11"
$CAPICOM_DIGITAL_RIGHTS_OID                             = "1.3.6.1.4.1.311.10.5.1"
$CAPICOM_LICENSES_OID                                   = "1.3.6.1.4.1.311.10.6.1"
$CAPICOM_LICENSE_SERVER_OID                             = "1.3.6.1.4.1.311.10.6.2"
$CAPICOM_SMART_CARD_LOGON_OID                           = "1.3.6.1.4.1.311.20.2.2"
$CAPICOM_ANY_APPLICATION_POLICY_OID                     = "1.3.6.1.4.1.311.10.12.1"
$CAPICOM_ANY_CERT_POLICY_OID                            = "2.5.29.32.0"
$CAPICOM_AUTHORITY_KEY_IDENTIFIER_OID                   = "2.5.29.1"
$CAPICOM_KEY_ATTRIBUTES_OID                             = "2.5.29.2"
$CAPICOM_CERT_POLICIES_95_OID                           = "2.5.29.3"
$CAPICOM_KEY_USAGE_RESTRICTION_OID                      = "2.5.29.4"
$CAPICOM_LEGACY_POLICY_MAPPINGS_OID                     = "2.5.29.5"
$CAPICOM_SUBJECT_ALT_NAME_OID                           = "2.5.29.7"
$CAPICOM_ISSUER_ALT_NAME_OID                            = "2.5.29.8"
$CAPICOM_BASIC_CONSTRAINTS_OID                          = "2.5.29.10"
$CAPICOM_SUBJECT_KEY_IDENTIFIER_OID                     = "2.5.29.14"
$CAPICOM_KEY_USAGE_OID                                  = "2.5.29.15"
$CAPICOM_PRIVATEKEY_USAGE_PERIOD_OID                    = "2.5.29.16"
$CAPICOM_SUBJECT_ALT_NAME2_OID                          = "2.5.29.17"
$CAPICOM_ISSUER_ALT_NAME2_OID                           = "2.5.29.18"
$CAPICOM_BASIC_CONSTRAINTS2_OID                         = "2.5.29.19"
$CAPICOM_NAME_CONSTRAINTS_OID                           = "2.5.29.30"
$CAPICOM_CRL_DIST_POINTS_OID                            = "2.5.29.31"
$CAPICOM_CERT_POLICIES_OID                              = "2.5.29.32"
$CAPICOM_POLICY_MAPPINGS_OID                            = "2.5.29.33"
$CAPICOM_AUTHORITY_KEY_IDENTIFIER2_OID                  = "2.5.29.35"
$CAPICOM_POLICY_CONSTRAINTS_OID                         = "2.5.29.36"
$CAPICOM_ENHANCED_KEY_USAGE_OID                         = "2.5.29.37"
$CAPICOM_CERTIFICATE_TEMPLATE_OID                       = "1.3.6.1.4.1.311.21.7"
$CAPICOM_APPLICATION_CERT_POLICIES_OID                  = "1.3.6.1.4.1.311.21.10"
$CAPICOM_APPLICATION_POLICY_MAPPINGS_OID                = "1.3.6.1.4.1.311.21.11"
$CAPICOM_APPLICATION_POLICY_CONSTRAINTS_OID             = "1.3.6.1.4.1.311.21.12"
$CAPICOM_AUTHORITY_INFO_ACCESS_OID                      = "1.3.6.1.5.5.7.1.1"
$CAPICOM_PKIX_POLICY_QUALIFIER_CPS_OID                  = "1.3.6.1.5.5.7.2.1"
$CAPICOM_PKIX_POLICY_QUALIFIER_USERNOTICE_OID           = "1.3.6.1.5.5.7.2.2"
%CAPICOM_TRUST_IS_NOT_TIME_VALID                        = 1&
%CAPICOM_TRUST_IS_NOT_TIME_NESTED                       = 2&
%CAPICOM_TRUST_IS_REVOKED                               = 4&
%CAPICOM_TRUST_IS_NOT_SIGNATURE_VALID                   = 8&
%CAPICOM_TRUST_IS_NOT_VALID_FOR_USAGE                   = 16&
%CAPICOM_TRUST_IS_UNTRUSTED_ROOT                        = 32&
%CAPICOM_TRUST_REVOCATION_STATUS_UNKNOWN                = 64&
%CAPICOM_TRUST_IS_CYCLIC                                = 128&
%CAPICOM_TRUST_INVALID_EXTENSION                        = 256&
%CAPICOM_TRUST_INVALID_POLICY_CONSTRAINTS               = 512&
%CAPICOM_TRUST_INVALID_BASIC_CONSTRAINTS                = 1024&
%CAPICOM_TRUST_INVALID_NAME_CONSTRAINTS                 = 2048&
%CAPICOM_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT        = 4096&
%CAPICOM_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT          = 8192&
%CAPICOM_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT        = 16384&
%CAPICOM_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT             = 32768&
%CAPICOM_TRUST_IS_OFFLINE_REVOCATION                    = &H01000000&
%CAPICOM_TRUST_NO_ISSUANCE_CHAIN_POLICY                 = &H02000000&
%CAPICOM_TRUST_IS_PARTIAL_CHAIN                         = &H00010000&
%CAPICOM_TRUST_CTL_IS_NOT_TIME_VALID                    = &H00020000&
%CAPICOM_TRUST_CTL_IS_NOT_SIGNATURE_VALID               = &H00040000&
%CAPICOM_TRUST_CTL_IS_NOT_VALID_FOR_USAGE               = &H00080000&
$CAPICOM_PROV_MS_DEF_PROV                               = "Microsoft Base Cryptographic Provider v1.0"
$CAPICOM_PROV_MS_ENHANCED_PROV                          = "Microsoft Enhanced Cryptographic Provider v1.0"
$CAPICOM_PROV_MS_STRONG_PROV                            = "Microsoft Strong Cryptographic Provider"
$CAPICOM_PROV_MS_DEF_RSA_SIG_PROV                       = "Microsoft RSA Signature Cryptographic Provider"
$CAPICOM_PROV_MS_DEF_RSA_SCHANNEL_PROV                  = "Microsoft RSA SChannel Cryptographic Provider"
$CAPICOM_PROV_MS_DEF_DSS_PROV                           = "Microsoft Base DSS Cryptographic Provider"
$CAPICOM_PROV_MS_DEF_DSS_DH_PROV                        = "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
$CAPICOM_PROV_MS_ENH_DSS_DH_PROV                        = "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
$CAPICOM_PROV_MS_DEF_DH_SCHANNEL_PROV                   = "Microsoft DH SChannel Cryptographic Provider"
$CAPICOM_PROV_MS_SCARD_PROV                             = "Microsoft Base Smart Card Crypto Provider"
$CAPICOM_PROV_MS_ENH_RSA_AES_PROV                       = "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"

' ========================================================================================
' _CRYPT_KEY_PROV_PARAM structure
' ========================================================================================

' // Size = 16 bytes
TYPE CRYPT_KEY_PROV_PARAM DWORD
   dwParam AS DWORD      ' unsigned long dwParam
   pbData  AS BYTE PTR   ' unsigned char* pbData
   cbData  AS DWORD      ' unsigned long cbData
   dwFlags AS DWORD      ' unsigned long dwFlags
END TYPE

' ========================================================================================
' _CRYPT_KEY_PROV_INFO structure
' ========================================================================================

' // Size = 28 bytes
TYPE CRYPT_KEY_PROV_INFO DWORD
   pwszContainerName AS WSTRINGZ PTR               ' LPWSTR pwszContainerName
   pwszProvName      AS WSTRINGZ PTR               ' LPWSTR pwszProvName
   dwProvType        AS DWORD                      ' unsigned long dwProvType
   dwFlags           AS DWORD                      ' unsigned long dwFlags
   cProvParam        AS DWORD                      ' unsigned long cProvParam
   rgProvParam       AS CRYPT_KEY_PROV_PARAM PTR   ' _CRYPT_KEY_PROV_PARAM* rgProvParam
   dwKeySpec         AS DWORD                      ' unsigned long dwKeySpec
END TYPE

' ========================================================================================
' _CERT_KEY_CONTEXT structure
' ========================================================================================

' // Size = 12 bytes
TYPE CERT_KEY_CONTEXT DWORD
   cbSize     AS DWORD   ' unsigned long cbSize
   hCryptProv AS DWORD   ' unsigned long hCryptProv
   dwKeySpec  AS DWORD   ' unsigned long dwKeySpec
END TYPE

' ########################################################################################
' Interface name = ISettings
' IID = {A24104F5-46D0-4C0F-926D-665565908E91}
' ISettings Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISettings_INTERFACE_DEFINED)
    %ISettings_INTERFACE_DEFINED = 1

INTERFACE ISettings $IID_ISettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EnablePromptForCertificateUI <1> ( _    ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET EnablePromptForCertificateUI <1> ( _    ' VTable offset = 32
     OPTIONAL BYVAL pVal AS INTEGER _                   ' __opt_in VARIANT_BOOL pVal [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveDirectorySearchLocation <2> ( _   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CAPICOM_ACTIVE_DIRECTORY_SEARCH_LOCATION* pVal
   ' =====================================================================================
   PROPERTY SET ActiveDirectorySearchLocation <2> ( _   ' VTable offset = 40
     OPTIONAL BYVAL pVal AS LONG _                      ' __opt_in CAPICOM_ACTIVE_DIRECTORY_SEARCH_LOCATION pVal [default value = 0]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEKU
' IID = {976B7E6D-1002-4051-BFD4-824A74BD74E2}
' IEKU Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEKU_INTERFACE_DEFINED)
    %IEKU_INTERFACE_DEFINED = 1

INTERFACE IEKU $IID_IEKU

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CAPICOM_EKU* pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in CAPICOM_EKU pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OID <1> ( _                             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET OID <1> ( _                             ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEKU_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEKUs
' IID = {47C87CEC-8C4B-4E3C-8D22-34280274EFD1}
' IEKUs Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEKUs_INTERFACE_DEFINED)
    %IEKUs_INTERFACE_DEFINED = 1

INTERFACE IEKUs $IID_IEKUs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEKUs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IKeyUsage
' IID = {41DD35A8-9FF9-45A6-9A7C-F65B2F085D1F}
' IKeyUsage Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IKeyUsage_INTERFACE_DEFINED)
    %IKeyUsage_INTERFACE_DEFINED = 1

INTERFACE IKeyUsage $IID_IKeyUsage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsPresent <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCritical <2> ( _                      ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsDigitalSignatureEnabled <3> ( _       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsNonRepudiationEnabled <4> ( _         ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsKeyEnciphermentEnabled <5> ( _        ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsDataEnciphermentEnabled <6> ( _       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsKeyAgreementEnabled <7> ( _           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsKeyCertSignEnabled <8> ( _            ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCRLSignEnabled <9> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsEncipherOnlyEnabled <10> ( _          ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsDecipherOnlyEnabled <11> ( _          ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKeyUsage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExtendedKeyUsage
' IID = {7289D408-987D-45D1-8DEE-CF9E91C2E90E}
' IExtendedKeyUsage Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExtendedKeyUsage_INTERFACE_DEFINED)
    %IExtendedKeyUsage_INTERFACE_DEFINED = 1

INTERFACE IExtendedKeyUsage $IID_IExtendedKeyUsage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsPresent <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCritical <2> ( _                      ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET EKUs <3> ( _                            ' VTable offset = 36
   ) AS IEKUs                                           ' __retval_out IEKUs** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtendedKeyUsage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBasicConstraints
' IID = {4E298C47-ABA6-459E-851B-993D6C626EAD}
' IBasicConstraints Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBasicConstraints_INTERFACE_DEFINED)
    %IBasicConstraints_INTERFACE_DEFINED = 1

INTERFACE IBasicConstraints $IID_IBasicConstraints

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsPresent <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCritical <2> ( _                      ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCertificateAuthority <3> ( _          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsPathLenConstraintPresent <4> ( _      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET PathLenConstraint <5> ( _               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBasicConstraints_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificateStatus3
' IID = {A4EAB890-0786-406B-9B31-2746F31F8D87}
' ICertificateStatus3 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertificateStatus2
' ########################################################################################

#IF NOT %DEF(%ICertificateStatus3_INTERFACE_DEFINED)
    %ICertificateStatus3_INTERFACE_DEFINED = 1

INTERFACE ICertificateStatus3 $IID_ICertificateStatus3

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertificateStatus Methods
   ' =====================================================================================
   PROPERTY GET Result <0> ( _                          ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET CheckFlag <1> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CAPICOM_CHECK_FLAG* pVal
   ' =====================================================================================
   PROPERTY SET CheckFlag <1> ( _                       ' VTable offset = 36
     BYVAL LONG _                                       ' __in CAPICOM_CHECK_FLAG pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD EKU <2> ( _                                   ' VTable offset = 40
   ) AS IEKU                                            ' __retval_out IEKU** pVal
   ' =====================================================================================

   ' =====================================================================================
   ' ICertificateStatus2 Methods
   ' =====================================================================================
   PROPERTY GET VerificationTime <3> ( _                ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY SET VerificationTime <3> ( _                ' VTable offset = 48
     BYVAL pVal AS DOUBLE _                             ' __in DATE pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UrlRetrievalTimeout <4> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY SET UrlRetrievalTimeout <4> ( _             ' VTable offset = 56
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificatePolicies <5> ( _                   ' VTable offset = 60
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================
   METHOD ApplicationPolicies <6> ( _                   ' VTable offset = 64
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================

   ' =====================================================================================
   ' ICertificateStatus3 Methods
   ' =====================================================================================
   PROPERTY GET ValidationCertificates <7> ( _          ' VTable offset = 68
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificateStatus3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificateStatus2
' IID = {BF95660E-F743-4EAC-9DE5-960787A4606C}
' ICertificateStatus2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertificateStatus
' ########################################################################################

#IF NOT %DEF(%ICertificateStatus2_INTERFACE_DEFINED)
    %ICertificateStatus2_INTERFACE_DEFINED = 1

INTERFACE ICertificateStatus2 $IID_ICertificateStatus2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertificateStatus Methods
   ' =====================================================================================
   PROPERTY GET Result <0> ( _                          ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET CheckFlag <1> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CAPICOM_CHECK_FLAG* pVal
   ' =====================================================================================
   PROPERTY SET CheckFlag <1> ( _                       ' VTable offset = 36
     BYVAL LONG _                                       ' __in CAPICOM_CHECK_FLAG pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD EKU <2> ( _                                   ' VTable offset = 40
   ) AS IEKU                                            ' __retval_out IEKU** pVal IEKU
   ' =====================================================================================

   ' =====================================================================================
   ' ICertificateStatus2 Methods
   ' =====================================================================================
   PROPERTY GET VerificationTime <3> ( _                ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY SET VerificationTime <3> ( _                ' VTable offset = 48
     BYVAL pVal AS DOUBLE _                             ' __in DATE pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UrlRetrievalTimeout <4> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY SET UrlRetrievalTimeout <4> ( _             ' VTable offset = 56
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificatePolicies <5> ( _                   ' VTable offset = 60
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================
   METHOD ApplicationPolicies <6> ( _                   ' VTable offset = 64
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificateStatus2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificateStatus
' IID = {AB769053-6D38-49D4-86EF-5FA85ED3AF27}
' ICertificateStatus Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificateStatus_INTERFACE_DEFINED)
    %ICertificateStatus_INTERFACE_DEFINED = 1

INTERFACE ICertificateStatus $IID_ICertificateStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Result <0> ( _                          ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET CheckFlag <1> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CAPICOM_CHECK_FLAG* pVal
   ' =====================================================================================
   PROPERTY SET CheckFlag <1> ( _                       ' VTable offset = 36
     BYVAL pVal AS LONG _                               ' __in CAPICOM_CHECK_FLAG pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD EKU <2> ( _                                   ' VTable offset = 40
   ) AS IEKU                                            ' __retval_out IEKU** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificateStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IOIDs
' IID = {DA55E8FC-8E27-451B-AEA8-1470D80FAD42}
' IOIDs Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOIDs_INTERFACE_DEFINED)
    %IOIDs_INTERFACE_DEFINED = 1

INTERFACE IOIDs $IID_IOIDs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IOID _                               ' __in IOID* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOIDs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IOID
' IID = {208E5E9B-58B1-4086-970F-161B582A846F}
' IOID Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IOID_INTERFACE_DEFINED)
    %IOID_INTERFACE_DEFINED = 1

INTERFACE IOID $IID_IOID

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CAPICOM_OID* pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in CAPICOM_OID pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <1> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET FriendlyName <1> ( _                    ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <2> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Value <2> ( _                           ' VTable offset = 48
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOID_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificates
' IID = {68646716-BDA0-4046-AB82-4444BC93B84A}
' ICertificates Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificates_INTERFACE_DEFINED)
    %ICertificates_INTERFACE_DEFINED = 1

INTERFACE ICertificates $IID_ICertificates

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificate2
' IID = {6FE450DC-AD32-48D4-A366-01EE7E0B1374}
' ICertificate2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertificate
' ########################################################################################

#IF NOT %DEF(%ICertificate2_INTERFACE_DEFINED)
    %ICertificate2_INTERFACE_DEFINED = 1

INTERFACE ICertificate2 $IID_ICertificate2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertificate Methods
   ' =====================================================================================
   PROPERTY GET Version <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET SerialNumber <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET SubjectName <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET IssuerName <4> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET ValidFromDate <5> ( _                   ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY GET ValidToDate <6> ( _                     ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY GET Thumbprint <7> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD HasPrivateKey <10> ( _                        ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD GetInfo <11> ( _                              ' VTable offset = 60
     BYVAL InfoType AS LONG _                           ' __in CAPICOM_CERT_INFO_TYPE InfoType
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD IsValid <12> ( _                              ' VTable offset = 64
   ) AS ICertificateStatus                              ' __retval_out ICertificateStatus** pVal
   ' =====================================================================================
   METHOD KeyUsage <13> ( _                             ' VTable offset = 68
   ) AS IKeyUsage                                       ' __retval_out IKeyUsage** pVal
   ' =====================================================================================
   METHOD ExtendedKeyUsage <14> ( _                     ' VTable offset = 72
   ) AS IExtendedKeyUsage                               ' __retval_out IExtendedKeyUsage** pVal
   ' =====================================================================================
   METHOD BasicConstraints <15> ( _                     ' VTable offset = 76
   ) AS IBasicConstraints                               ' __retval_out IBasicConstraints** pVal
   ' =====================================================================================
   METHOD Export <16> ( _                               ' VTable offset = 80
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Import <17> ( _                               ' VTable offset = 84
     BYVAL EncodedCertificate AS WSTRING _              ' __in BSTR EncodedCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD Display <18> ( _                              ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICertificate2 Methods
   ' =====================================================================================
   PROPERTY GET Archived <19> ( _                       ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY SET Archived <19> ( _                       ' VTable offset = 96
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Template <20> ( _                             ' VTable offset = 100
   ) AS ITemplate                                       ' __retval_out ITemplate** pVal
   ' =====================================================================================
   METHOD PublicKey <21> ( _                            ' VTable offset = 104
   ) AS IPublicKey                                      ' __retval_out IPublicKey** pVal
   ' =====================================================================================
   PROPERTY GET PrivateKey <22> ( _                     ' VTable offset = 108
   ) AS IPrivateKey                                     ' __retval_out IPrivateKey** pVal
   ' =====================================================================================
   PROPERTY SET PrivateKey <22> ( _                     ' VTable offset = 112
     BYVAL pVal AS IPrivateKey _                        ' __in IPrivateKey* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Extensions <23> ( _                           ' VTable offset = 116
   ) AS IExtensions                                     ' __retval_out IExtensions** pVal
   ' =====================================================================================
   METHOD ExtendedProperties <24> ( _                   ' VTable offset = 120
   ) AS IExtendedProperties                             ' __retval_out IExtendedProperties** pVal
   ' =====================================================================================
   METHOD Load <25> ( _                                 ' VTable offset = 124
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   , OPTIONAL BYVAL KeyStorageFlag AS LONG _            ' __opt_in CAPICOM_KEY_STORAGE_FLAG KeyStorageFlag [default value = 0]
   , OPTIONAL BYVAL KeyLocation AS LONG _               ' __opt_in CAPICOM_KEY_LOCATION KeyLocation [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <26> ( _                                 ' VTable offset = 128
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   , OPTIONAL BYVAL SaveAs AS LONG _                    ' __opt_in CAPICOM_CERTIFICATE_SAVE_AS_TYPE SaveAs [default value = 1]
   , OPTIONAL BYVAL IncludeOption AS LONG _             ' __opt_in CAPICOM_CERTIFICATE_INCLUDE_OPTION IncludeOption [default value = 2]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificate2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificate
' IID = {0BBA0B86-766C-4755-A443-243FF2BD8D29}
' ICertificate Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificate_INTERFACE_DEFINED)
    %ICertificate_INTERFACE_DEFINED = 1

INTERFACE ICertificate $IID_ICertificate

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Version <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET SerialNumber <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET SubjectName <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET IssuerName <4> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET ValidFromDate <5> ( _                   ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY GET ValidToDate <6> ( _                     ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   PROPERTY GET Thumbprint <7> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD HasPrivateKey <10> ( _                        ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD GetInfo <11> ( _                              ' VTable offset = 60
     BYVAL InfoType AS LONG _                           ' __in CAPICOM_CERT_INFO_TYPE InfoType
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD IsValid <12> ( _                              ' VTable offset = 64
   ) AS ICertificateStatus                              ' __retval_out ICertificateStatus** pVal
   ' =====================================================================================
   METHOD KeyUsage <13> ( _                             ' VTable offset = 68
   ) AS IKeyUsage                                       ' __retval_out IKeyUsage** pVal
   ' =====================================================================================
   METHOD ExtendedKeyUsage <14> ( _                     ' VTable offset = 72
   ) AS IExtendedKeyUsage                               ' __retval_out IExtendedKeyUsage** pVal
   ' =====================================================================================
   METHOD BasicConstraints <15> ( _                     ' VTable offset = 76
   ) AS IBasicConstraints                               ' __retval_out IBasicConstraints** pVal
   ' =====================================================================================
   METHOD Export <16> ( _                               ' VTable offset = 80
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Import <17> ( _                               ' VTable offset = 84
     BYVAL EncodedCertificate AS WSTRING _              ' __in BSTR EncodedCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD Display <18> ( _                              ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITemplate
' IID = {5F10FFCE-C922-476F-AA76-DF99D5BDFA2C}
' ITemplate Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITemplate_INTERFACE_DEFINED)
    %ITemplate_INTERFACE_DEFINED = 1

INTERFACE ITemplate $IID_ITemplate

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsPresent <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET IsCritical <2> ( _                      ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET OID <4> ( _                             ' VTable offset = 40
   ) AS IOID                                            ' __retval_out IOID** pVal
   ' =====================================================================================
   PROPERTY GET MajorVersion <5> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET MinorVersion <6> ( _                    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITemplate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPublicKey
' IID = {72BF9ADA-6817-4C31-B43E-25F7C7B091F4}
' IPublicKey Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPublicKey_INTERFACE_DEFINED)
    %IPublicKey_INTERFACE_DEFINED = 1

INTERFACE IPublicKey $IID_IPublicKey

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Algorithm <0> ( _                       ' VTable offset = 28
   ) AS IOID                                            ' __retval_out IOID** pVal
   ' =====================================================================================
   PROPERTY GET Length <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET EncodedKey <2> ( _                      ' VTable offset = 36
   ) AS IEncodedData                                    ' __retval_out IEncodedData** pVal
   ' =====================================================================================
   PROPERTY GET EncodedParameters <3> ( _               ' VTable offset = 40
   ) AS IEncodedData                                    ' __retval_out IEncodedData** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPublicKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEncodedData
' IID = {D3D460F2-E7F3-4AF3-8EC6-8EB68C61C567}
' IEncodedData Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEncodedData_INTERFACE_DEFINED)
    %IEncodedData_INTERFACE_DEFINED = 1

INTERFACE IEncodedData $IID_IEncodedData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Format <1> ( _                                ' VTable offset = 32
     OPTIONAL BYVAL bMultiLines AS INTEGER _            ' __opt_in VARIANT_BOOL bMultiLines [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Decoder <2> ( _                               ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEncodedData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrivateKey
' IID = {659DEDC3-6C85-42DB-8527-EFCB21742862}
' IPrivateKey Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPrivateKey_INTERFACE_DEFINED)
    %IPrivateKey_INTERFACE_DEFINED = 1

INTERFACE IPrivateKey $IID_IPrivateKey

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ContainerName <0> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET UniqueContainerName <1> ( _             ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET ProviderName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET ProviderType <3> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out CAPICOM_PROV_TYPE* pVal
   ' =====================================================================================
   PROPERTY GET KeySpec <4> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CAPICOM_KEY_SPEC* pVal
   ' =====================================================================================
   METHOD IsAccessible <5> ( _                          ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD IsProtected <6> ( _                           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD IsExportable <7> ( _                          ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD IsRemovable <8> ( _                           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD IsMachineKeyset <9> ( _                       ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD IsHardwareDevice <10> ( _                     ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD Open <11> ( _                                 ' VTable offset = 72
     BYVAL ContainerName AS WSTRING _                   ' __in BSTR ContainerName
   , OPTIONAL BYVAL ProviderName AS WSTRING _           ' __opt_in BSTR ProviderName [default value = "Microsoft Enhanced Cryptographic Provider v1.0"]
   , OPTIONAL BYVAL ProviderType AS LONG _              ' __opt_in CAPICOM_PROV_TYPE ProviderType [default value = 1]
   , OPTIONAL BYVAL KeySpec AS LONG _                   ' __opt_in CAPICOM_KEY_SPEC KeySpec [default value = 2]
   , OPTIONAL BYVAL StoreLocation AS LONG _             ' __opt_in CAPICOM_STORE_LOCATION StoreLocation [default value = 2]
   , OPTIONAL BYVAL bCheckExistence AS INTEGER _        ' __opt_in VARIANT_BOOL bCheckExistence [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <12> ( _                               ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrivateKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExtensions
' IID = {BC530D61-E692-4225-9E7A-07B90B45856A}
' IExtensions Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExtensions_INTERFACE_DEFINED)
    %IExtensions_INTERFACE_DEFINED = 1

INTERFACE IExtensions $IID_IExtensions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtensions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExtendedProperties
' IID = {3B096E87-6218-4A3B-A880-F6CB951E7805}
' IExtendedProperties Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExtendedProperties_INTERFACE_DEFINED)
    %IExtendedProperties_INTERFACE_DEFINED = 1

INTERFACE IExtendedProperties $IID_IExtendedProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IExtendedProperty _                  ' __in IExtendedProperty* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL PropID AS LONG _                             ' __in CAPICOM_PROPID PropID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtendedProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExtendedProperty
' IID = {ECB8A5C8-562C-4989-B49D-FA37D40F8FC4}
' IExtendedProperty Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExtendedProperty_INTERFACE_DEFINED)
    %IExtendedProperty_INTERFACE_DEFINED = 1

INTERFACE IExtendedProperty $IID_IExtendedProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PropID <0> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CAPICOM_PROPID* pVal
   ' =====================================================================================
   PROPERTY SET PropID <0> ( _                          ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in CAPICOM_PROPID pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1> ( _                           ' VTable offset = 36
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Value <1> ( _                           ' VTable offset = 40
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   , BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtendedProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertContext
' IID = {9E7D3477-4F63-423E-8A45-E13B2BB851A2}
' ICertContext Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICertContext_INTERFACE_DEFINED)
    %ICertContext_INTERFACE_DEFINED = 1

INTERFACE ICertContext $IID_ICertContext

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET CertContext ( _                         ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long* ppCertContext
   ' =====================================================================================
   PROPERTY SET CertContext ( _                         ' VTable offset = 16
     BYVAL ppCertContext AS LONG _                      ' __in long ppCertContext
   )                                                    ' void
   ' =====================================================================================
   METHOD FreeContext ( _                               ' VTable offset = 20
     BYVAL pCertContext AS LONG _                       ' __in long pCertContext
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificates2
' IID = {7B57C04B-1786-4B30-A7B6-36235CD58A14}
' ICertificates2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertificates
' ########################################################################################

#IF NOT %DEF(%ICertificates2_INTERFACE_DEFINED)
    %ICertificates2_INTERFACE_DEFINED = 1

INTERFACE ICertificates2 $IID_ICertificates2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertificates Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

   ' =====================================================================================
   ' ICertificates2 Methods
   ' =====================================================================================
   METHOD Find <2> ( _                                  ' VTable offset = 40
     BYVAL FindType AS LONG _                           ' __in CAPICOM_CERTIFICATE_FIND_TYPE FindType
   , OPTIONAL BYVAL varCriteria AS VARIANT _            ' __opt_in VARIANT varCriteria [default value = 0]
   , OPTIONAL BYVAL bFindValidOnly AS INTEGER _         ' __opt_in VARIANT_BOOL bFindValidOnly [default value = 0]
   ) AS ICertificates2                                  ' __retval_out ICertificates2** pVal
   ' =====================================================================================
   METHOD Select <3> ( _                                ' VTable offset = 44
     OPTIONAL BYVAL Title AS WSTRING _                  ' __opt_in BSTR Title [default value = ""]
   , OPTIONAL BYVAL DisplayString AS WSTRING _          ' __opt_in BSTR DisplayString [default value = ""]
   , OPTIONAL BYVAL bMultiSelect AS INTEGER _           ' __opt_in VARIANT_BOOL bMultiSelect [default value = 0]
   ) AS ICertificates2                                  ' __retval_out ICertificates2** pVal
   ' =====================================================================================
   METHOD Add <4> ( _                                   ' VTable offset = 48
     BYVAL pVal AS ICertificate2 _                      ' __in ICertificate2* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <5> ( _                                ' VTable offset = 52
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <6> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <7> ( _                                  ' VTable offset = 60
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   , OPTIONAL BYVAL SaveAs AS LONG _                    ' __opt_in CAPICOM_CERTIFICATES_SAVE_AS_TYPE SaveAs [default value = 2]
   , OPTIONAL BYVAL ExportFlag AS LONG _                ' __opt_in CAPICOM_EXPORT_FLAG ExportFlag [default value = 0]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificates2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICCertificates
' IID = {EBDC6DC2-684D-4425-BBB7-CB4D15A088A7}
' ICCertificates Interface
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICCertificates_INTERFACE_DEFINED)
    %ICCertificates_INTERFACE_DEFINED = 1

INTERFACE ICCertificates $IID_ICCertificates

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ExportToStore_ ( _                            ' VTable offset = 12
     BYVAL hCertStore AS DWORD _                        ' __in void* hCertStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICCertificates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChain2
' IID = {CA65D842-2110-4073-AEE3-D0AA5F56C421}
' IChain2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IChain
' ########################################################################################

#IF NOT %DEF(%IChain2_INTERFACE_DEFINED)
    %IChain2_INTERFACE_DEFINED = 1

INTERFACE IChain2 $IID_IChain2

   INHERIT IDispatch

   ' =====================================================================================
   ' IChain Methods
   ' =====================================================================================
   PROPERTY GET Certificates <0> ( _                    ' VTable offset = 28
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
     OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index [default value = 0]
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   METHOD Build <2> ( _                                 ' VTable offset = 36
     BYVAL pICertificate AS ICertificate _              ' __in ICertificate* pICertificate
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IChain2 Methods
   ' =====================================================================================
   METHOD CertificatePolicies <3> ( _                   ' VTable offset = 40
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================
   METHOD ApplicationPolicies <4> ( _                   ' VTable offset = 44
   ) AS IOIDs                                           ' __retval_out IOIDs** pVal
   ' =====================================================================================
   METHOD ExtendedErrorInfo <5> ( _                     ' VTable offset = 48
     OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index [default value = 1]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChain2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChain
' IID = {77F6F881-5D3A-4F2F-AEF0-E4A2F9AA689D}
' IChain Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IChain_INTERFACE_DEFINED)
    %IChain_INTERFACE_DEFINED = 1

INTERFACE IChain $IID_IChain

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Certificates <0> ( _                    ' VTable offset = 28
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
     OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index [default value = 0]
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   METHOD Build <2> ( _                                 ' VTable offset = 36
     BYVAL pICertificate AS ICertificate _              ' __in ICertificate* pICertificate
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChainContext
' IID = {B27FFB30-432E-4585-A3FD-72530108CBFD}
' IChainContext Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IChainContext_INTERFACE_DEFINED)
    %IChainContext_INTERFACE_DEFINED = 1

INTERFACE IChainContext $IID_IChainContext

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ChainContext ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long* pChainContext
   ' =====================================================================================
   PROPERTY SET ChainContext ( _                        ' VTable offset = 16
     BYVAL pChainContext AS LONG _                      ' __in long pChainContext
   )                                                    ' void
   ' =====================================================================================
   METHOD FreeContext ( _                               ' VTable offset = 20
     BYVAL pChainContext AS LONG _                      ' __in long pChainContext
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChainContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStore3
' IID = {F701F8EC-31C7-48FB-B621-5DE417C3A607}
' IStore3 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IStore2
' ########################################################################################

#IF NOT %DEF(%IStore3_INTERFACE_DEFINED)
    %IStore3_INTERFACE_DEFINED = 1

INTERFACE IStore3 $IID_IStore3

   INHERIT IDispatch

   ' =====================================================================================
   ' IStore Methods
   ' =====================================================================================
   PROPERTY GET Certificates <0> ( _                    ' VTable offset = 28
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   METHOD Open <1> ( _                                  ' VTable offset = 32
     OPTIONAL BYVAL StoreLocation AS LONG _             ' __opt_in CAPICOM_STORE_LOCATION StoreLocation [default value = 2]
   , OPTIONAL BYVAL StoreName AS WSTRING _              ' __opt_in BSTR StoreName [default value = "My"]
   , OPTIONAL BYVAL OpenMode AS LONG _                  ' __opt_in CAPICOM_STORE_OPEN_MODE OpenMode [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 40
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <4> ( _                                ' VTable offset = 44
     OPTIONAL BYVAL SaveAs AS LONG _                    ' __opt_in CAPICOM_STORE_SAVE_AS_TYPE SaveAs [default value = 0]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Import <5> ( _                                ' VTable offset = 48
     BYVAL EncodedStore AS WSTRING _                    ' __in BSTR EncodedStore
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IStore2 Methods
   ' =====================================================================================
   METHOD Load <6> ( _                                  ' VTable offset = 52
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   , OPTIONAL BYVAL KeyStorageFlag AS LONG _            ' __opt_in CAPICOM_KEY_STORAGE_FLAG KeyStorageFlag [default value = 0]
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IStore3 Methods
   ' =====================================================================================
   PROPERTY GET Name <7> ( _                            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Location <8> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CAPICOM_STORE_LOCATION* pStoreLocation
   ' =====================================================================================
   METHOD Delete <9> ( _                                ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   METHOD Close <10> ( _                                ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStore3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStore2
' IID = {4DA6ABC4-BDCD-4317-B650-262075B93A9C}
' IStore2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IStore
' ########################################################################################

#IF NOT %DEF(%IStore2_INTERFACE_DEFINED)
    %IStore2_INTERFACE_DEFINED = 1

INTERFACE IStore2 $IID_IStore2

   INHERIT IDispatch

   ' =====================================================================================
   ' IStore Methods
   ' =====================================================================================
   PROPERTY GET Certificates <0> ( _                    ' VTable offset = 28
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   METHOD Open <1> ( _                                  ' VTable offset = 32
     OPTIONAL BYVAL StoreLocation AS LONG _             ' __opt_in CAPICOM_STORE_LOCATION StoreLocation [default value = 2]
   , OPTIONAL BYVAL StoreName AS WSTRING _              ' __opt_in BSTR StoreName [default value = "My"]
   , OPTIONAL BYVAL OpenMode AS LONG _                  ' __opt_in CAPICOM_STORE_OPEN_MODE OpenMode [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 40
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <4> ( _                                ' VTable offset = 44
     OPTIONAL BYVAL SaveAs AS LONG _                    ' __opt_in CAPICOM_STORE_SAVE_AS_TYPE SaveAs [default value = 0]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Import <5> ( _                                ' VTable offset = 48
     BYVAL EncodedStore AS WSTRING _                    ' __in BSTR EncodedStore
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IStore2 Methods
   ' =====================================================================================
   METHOD Load <6> ( _                                  ' VTable offset = 52
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   , OPTIONAL BYVAL KeyStorageFlag AS LONG _            ' __opt_in CAPICOM_KEY_STORAGE_FLAG KeyStorageFlag [default value = 0]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStore2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStore
' IID = {E860EF75-1B63-4254-AF47-960DAA3DD337}
' IStore Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IStore_INTERFACE_DEFINED)
    %IStore_INTERFACE_DEFINED = 1

INTERFACE IStore $IID_IStore

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Certificates <0> ( _                    ' VTable offset = 28
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   METHOD Open <1> ( _                                  ' VTable offset = 32
     OPTIONAL BYVAL StoreLocation AS LONG _             ' __opt_in CAPICOM_STORE_LOCATION StoreLocation [default value = 2]
   , OPTIONAL BYVAL StoreName AS WSTRING _              ' __opt_in BSTR StoreName [default value = "My"]
   , OPTIONAL BYVAL OpenMode AS LONG _                  ' __opt_in CAPICOM_STORE_OPEN_MODE OpenMode [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 40
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <4> ( _                                ' VTable offset = 44
     OPTIONAL BYVAL SaveAs AS LONG _                    ' __opt_in CAPICOM_STORE_SAVE_AS_TYPE SaveAs [default value = 0]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD Import <5> ( _                                ' VTable offset = 48
     BYVAL EncodedStore AS WSTRING _                    ' __in BSTR EncodedStore
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStore_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertStore
' IID = {BB3ECB9C-A83A-445C-BDB5-EFBEF691B731}
' ICertStore Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICertStore_INTERFACE_DEFINED)
    %ICertStore_INTERFACE_DEFINED = 1

INTERFACE ICertStore $IID_ICertStore

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET StoreHandle ( _                         ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long* phCertStore
   ' =====================================================================================
   PROPERTY SET StoreHandle ( _                         ' VTable offset = 16
     BYVAL phCertStore AS LONG _                        ' __in long phCertStore
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StoreLocation ( _                       ' VTable offset = 20
   ) AS LONG                                            ' __retval_out CAPICOM_STORE_LOCATION* pStoreLocation
   ' =====================================================================================
   PROPERTY SET StoreLocation ( _                       ' VTable offset = 24
     BYVAL pStoreLocation AS LONG _                     ' __in CAPICOM_STORE_LOCATION pStoreLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseHandle ( _                               ' VTable offset = 28
     BYVAL hCertStore AS LONG _                         ' __in long hCertStore
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertStore_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAttribute
' IID = {B17A8D78-B5A6-45F7-BA21-01AB94B08415}
' IAttribute Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAttribute_INTERFACE_DEFINED)
    %IAttribute_INTERFACE_DEFINED = 1

INTERFACE IAttribute $IID_IAttribute

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CAPICOM_ATTRIBUTE* pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in CAPICOM_ATTRIBUTE pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY SET Value <1> ( _                           ' VTable offset = 40
     BYVAL pVal AS VARIANT _                            ' __in VARIANT pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAttribute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAttributes
' IID = {6ADC653E-D5B9-422A-991A-A2B0119CEDAC}
' IAttributes Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAttributes_INTERFACE_DEFINED)
    %IAttributes_INTERFACE_DEFINED = 1

INTERFACE IAttributes $IID_IAttributes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS IAttribute _                         ' __in IAttribute* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAttributes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISigner2
' IID = {625B1F55-C720-41D6-9ECF-BA59F9B85F17}
' ISigner2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISigner
' ########################################################################################

#IF NOT %DEF(%ISigner2_INTERFACE_DEFINED)
    %ISigner2_INTERFACE_DEFINED = 1

INTERFACE ISigner2 $IID_ISigner2

   INHERIT IDispatch

   ' =====================================================================================
   ' ISigner Methods
   ' =====================================================================================
   PROPERTY GET Certificate <0> ( _                     ' VTable offset = 28
   ) AS ICertificate                                    ' __retval_out ICertificate** pVal
   ' =====================================================================================
   PROPERTY SET Certificate <0> ( _                     ' VTable offset = 32
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticatedAttributes <1> ( _         ' VTable offset = 36
   ) AS IAttributes                                     ' __retval_out IAttributes** pVal
   ' =====================================================================================

   ' =====================================================================================
   ' ISigner2 Methods
   ' =====================================================================================
   PROPERTY GET Chain <2> ( _                           ' VTable offset = 40
   ) AS IChain                                          ' __retval_out IChain** pVal
   ' =====================================================================================
   PROPERTY GET Options <3> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CAPICOM_CERTIFICATE_INCLUDE_OPTION* pVal
   ' =====================================================================================
   PROPERTY SET Options <3> ( _                         ' VTable offset = 48
     OPTIONAL BYVAL pVal AS LONG _                      ' __opt_in CAPICOM_CERTIFICATE_INCLUDE_OPTION pVal [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Load <4> ( _                                  ' VTable offset = 52
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password [default value = ""]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISigner2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISigner
' IID = {51017B88-1913-49AD-82BE-6BB7C417DCF2}
' ISigner Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISigner_INTERFACE_DEFINED)
    %ISigner_INTERFACE_DEFINED = 1

INTERFACE ISigner $IID_ISigner

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Certificate <0> ( _                     ' VTable offset = 28
   ) AS ICertificate                                    ' __retval_out ICertificate** pVal
   ' =====================================================================================
   PROPERTY SET Certificate <0> ( _                     ' VTable offset = 32
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticatedAttributes <1> ( _         ' VTable offset = 36
   ) AS IAttributes                                     ' __retval_out IAttributes** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISigner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICSigner
' IID = {8F83F792-014C-4E22-BD57-5C381E622F34}
' ICSigner Interface
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICSigner_INTERFACE_DEFINED)
    %ICSigner_INTERFACE_DEFINED = 1

INTERFACE ICSigner $IID_ICSigner

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET AdditionalStore ( _                     ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long* phAdditionalStore
   ' =====================================================================================
   PROPERTY SET AdditionalStore ( _                     ' VTable offset = 16
     BYVAL phAdditionalStore AS LONG _                  ' __in long phAdditionalStore
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICSigner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISigners
' IID = {5A0780F8-9E6B-4BB0-BF54-87CD9627A8B4}
' ISigners Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISigners_INTERFACE_DEFINED)
    %ISigners_INTERFACE_DEFINED = 1

INTERFACE ISigners $IID_ISigners

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISigners_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISignedData
' IID = {AE9C454B-FC65-4C10-B130-CD9B45BA948B}
' ISignedData Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISignedData_INTERFACE_DEFINED)
    %ISignedData_INTERFACE_DEFINED = 1

INTERFACE ISignedData $IID_ISignedData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Content <0> ( _                         ' VTable offset = 28
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Content <0> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Signers <1> ( _                         ' VTable offset = 36
   ) AS ISigners                                        ' __retval_out ISigners** pVal
   ' =====================================================================================
   PROPERTY GET Certificates <2> ( _                    ' VTable offset = 40
   ) AS ICertificates                                   ' __retval_out ICertificates** pVal
   ' =====================================================================================
   METHOD Sign <3> ( _                                  ' VTable offset = 44
     OPTIONAL BYVAL pSigner AS ISigner _                ' __opt_in ISigner* pSigner [default value = 0]
   , OPTIONAL BYVAL bDetached AS INTEGER _              ' __opt_in VARIANT_BOOL bDetached [default value = 0]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD CoSign <4> ( _                                ' VTable offset = 48
     OPTIONAL BYVAL pSigner AS ISigner _                ' __opt_in ISigner* pSigner [default value = 0]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Verify <5> ( _                                ' VTable offset = 52
     BYVAL SignedMessage AS WSTRING _                   ' __in BSTR SignedMessage
   , OPTIONAL BYVAL bDetached AS INTEGER _              ' __opt_in VARIANT_BOOL bDetached [default value = 0]
   , OPTIONAL BYVAL VerifyFlag AS LONG _                ' __opt_in CAPICOM_SIGNED_DATA_VERIFY_FLAG VerifyFlag [default value = 1]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISignedData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAlgorithm
' IID = {BF3D04A9-B0DA-4153-B45E-6CCFA5AC715B}
' IAlgorithm Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAlgorithm_INTERFACE_DEFINED)
    %IAlgorithm_INTERFACE_DEFINED = 1

INTERFACE IAlgorithm $IID_IAlgorithm

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out CAPICOM_ENCRYPTION_ALGORITHM* pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in CAPICOM_ENCRYPTION_ALGORITHM pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeyLength <1> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CAPICOM_ENCRYPTION_KEY_LENGTH* pVal
   ' =====================================================================================
   PROPERTY SET KeyLength <1> ( _                       ' VTable offset = 40
     BYVAL pVal AS LONG _                               ' __in CAPICOM_ENCRYPTION_KEY_LENGTH pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAlgorithm_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRecipients
' IID = {A694C896-FC38-4C34-AE61-3B1A95984C14}
' IRecipients Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRecipients_INTERFACE_DEFINED)
    %IRecipients_INTERFACE_DEFINED = 1

INTERFACE IRecipients $IID_IRecipients

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pVal AS ICertificate _                       ' __in ICertificate* pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <4> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRecipients_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnvelopedData
' IID = {F6CB6A20-CC18-4424-AE57-6F2AA3DC2059}
' IEnvelopedData Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnvelopedData_INTERFACE_DEFINED)
    %IEnvelopedData_INTERFACE_DEFINED = 1

INTERFACE IEnvelopedData $IID_IEnvelopedData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Content <0> ( _                         ' VTable offset = 28
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Content <0> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Algorithm <1> ( _                       ' VTable offset = 36
   ) AS IAlgorithm                                      ' __retval_out IAlgorithm** pVal
   ' =====================================================================================
   PROPERTY GET Recipients <2> ( _                      ' VTable offset = 40
   ) AS IRecipients                                     ' __retval_out IRecipients** pVal
   ' =====================================================================================
   METHOD Encrypt <3> ( _                               ' VTable offset = 44
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Decrypt <4> ( _                               ' VTable offset = 48
     BYVAL EnvelopedMessage AS WSTRING _                ' __in BSTR EnvelopedMessage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnvelopedData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEncryptedData
' IID = {C4778A66-972F-42E4-87C5-5CC16F7931CA}
' IEncryptedData Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEncryptedData_INTERFACE_DEFINED)
    %IEncryptedData_INTERFACE_DEFINED = 1

INTERFACE IEncryptedData $IID_IEncryptedData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Content <0> ( _                         ' VTable offset = 28
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Content <0> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Algorithm <1> ( _                       ' VTable offset = 36
   ) AS IAlgorithm                                      ' __retval_out IAlgorithm** pVal
   ' =====================================================================================
   METHOD SetSecret <2> ( _                             ' VTable offset = 40
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   , OPTIONAL BYVAL SecretType AS LONG _                ' __opt_in CAPICOM_SECRET_TYPE SecretType [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Encrypt <3> ( _                               ' VTable offset = 44
     OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 0]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Decrypt <4> ( _                               ' VTable offset = 48
     BYVAL EncryptedMessage AS WSTRING _                ' __in BSTR EncryptedMessage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEncryptedData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INoticeNumbers
' IID = {EE2C051D-33A1-4157-86B4-9280E29782F2}
' INoticeNumbers Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INoticeNumbers_INTERFACE_DEFINED)
    %INoticeNumbers_INTERFACE_DEFINED = 1

INTERFACE INoticeNumbers $IID_INoticeNumbers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INoticeNumbers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQualifier
' IID = {3604C9DD-A22E-4A15-A469-8181C0C113DE}
' IQualifier Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IQualifier_INTERFACE_DEFINED)
    %IQualifier_INTERFACE_DEFINED = 1

INTERFACE IQualifier $IID_IQualifier

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OID <0> ( _                             ' VTable offset = 28
   ) AS IOID                                            ' __retval_out IOID** pVal
   ' =====================================================================================
   PROPERTY GET CPSPointer <1> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET OrganizationName <2> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET NoticeNumbers <3> ( _                   ' VTable offset = 40
   ) AS INoticeNumbers                                  ' __retval_out INoticeNumbers** pVal
   ' =====================================================================================
   PROPERTY GET ExplicitText <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQualifier_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQualifiers
' IID = {6B5A8AB6-597D-4398-AC63-1036EF546348}
' IQualifiers Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IQualifiers_INTERFACE_DEFINED)
    %IQualifiers_INTERFACE_DEFINED = 1

INTERFACE IQualifiers $IID_IQualifiers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQualifiers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPolicyInformation
' IID = {8973710C-8411-4951-9E65-D45FD524FFDF}
' IPolicyInformation Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPolicyInformation_INTERFACE_DEFINED)
    %IPolicyInformation_INTERFACE_DEFINED = 1

INTERFACE IPolicyInformation $IID_IPolicyInformation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OID <0> ( _                             ' VTable offset = 28
   ) AS IOID                                            ' __retval_out IOID** pVal
   ' =====================================================================================
   PROPERTY GET Qualifiers <1> ( _                      ' VTable offset = 32
   ) AS IQualifiers                                     ' __retval_out IQualifiers** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPolicyInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertificatePolicies
' IID = {CC7A72A7-C83A-4049-85F4-4292DE9DBFD3}
' ICertificatePolicies Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificatePolicies_INTERFACE_DEFINED)
    %ICertificatePolicies_INTERFACE_DEFINED = 1

INTERFACE ICertificatePolicies $IID_ICertificatePolicies

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificatePolicies_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExtension
' IID = {ED4E4ED4-FDD8-476E-AED9-5239E7948257}
' IExtension Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExtension_INTERFACE_DEFINED)
    %IExtension_INTERFACE_DEFINED = 1

INTERFACE IExtension $IID_IExtension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OID <0> ( _                             ' VTable offset = 28
   ) AS IOID                                            ' __retval_out IOID** pVal
   ' =====================================================================================
   PROPERTY GET IsCritical <1> ( _                      ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pVal
   ' =====================================================================================
   PROPERTY GET EncodedData <2> ( _                     ' VTable offset = 36
   ) AS IEncodedData                                    ' __retval_out IEncodedData** pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICPrivateKey
' IID = {50F241B7-A8F2-4E0A-B982-4BD7DF0CCF3C}
' ICPrivateKey Interface
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICPrivateKey_INTERFACE_DEFINED)
    %ICPrivateKey_INTERFACE_DEFINED = 1

INTERFACE ICPrivateKey $IID_ICPrivateKey

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetKeyProvInfo_ ( _                           ' VTable offset = 12
     BYREF pKeyProvInfo AS CRYPT_KEY_PROV_INFO _        ' __retval_out _CRYPT_KEY_PROV_INFO** pKeyProvInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyContext_ ( _                            ' VTable offset = 16
     BYREF pKeyContext AS CERT_KEY_CONTEXT _            ' __retval_out _CERT_KEY_CONTEXT** pKeyContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICPrivateKey_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISignedCode
' IID = {84FBCB95-5600-404C-9187-AC25B4CD6E94}
' ISignedCode Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISignedCode_INTERFACE_DEFINED)
    %ISignedCode_INTERFACE_DEFINED = 1

INTERFACE ISignedCode $IID_ISignedCode

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <0> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET FileName <0> ( _                        ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET Description <1> ( _                     ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DescriptionURL <2> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY SET DescriptionURL <2> ( _                  ' VTable offset = 48
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Signer <3> ( _                          ' VTable offset = 52
   ) AS ISigner2                                        ' __retval_out ISigner2** pVal
   ' =====================================================================================
   PROPERTY GET TimeStamper <4> ( _                     ' VTable offset = 56
   ) AS ISigner2                                        ' __retval_out ISigner2** pVal
   ' =====================================================================================
   PROPERTY GET Certificates <5> ( _                    ' VTable offset = 60
   ) AS ICertificates2                                  ' __retval_out ICertificates2** pVal
   ' =====================================================================================
   METHOD Sign <6> ( _                                  ' VTable offset = 64
     OPTIONAL BYVAL pISigner2 AS ISigner2 _             ' __opt_in ISigner2* pISigner2 [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   METHOD Timestamp <7> ( _                             ' VTable offset = 68
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD Verify <8> ( _                                ' VTable offset = 72
     OPTIONAL BYVAL bUIAllowed AS INTEGER _             ' __opt_in VARIANT_BOOL bUIAllowed [default value = 0]
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISignedCode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHashedData
' IID = {9F7F23E8-06F4-42E8-B965-5CBD044BF27F}
' IHashedData Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHashedData_INTERFACE_DEFINED)
    %IHashedData_INTERFACE_DEFINED = 1

INTERFACE IHashedData $IID_IHashedData

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Algorithm <1> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out CAPICOM_HASH_ALGORITHM* pVal
   ' =====================================================================================
   PROPERTY SET Algorithm <1> ( _                       ' VTable offset = 36
     BYVAL pVal AS LONG _                               ' __in CAPICOM_HASH_ALGORITHM pVal
   )                                                    ' void
   ' =====================================================================================
   ' Note: Although the newVal parameter has been declared as a BSTR in the type library.
   ' you must not pass it in Unicode format.
   ' =====================================================================================
   METHOD Hash <2> ( _                                  ' VTable offset = 40
     BYVAL newVal AS STRING _                           ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHashedData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUtilities
' IID = {EB166CF6-2AE6-44DA-BD96-0C1635D183FE}
' IUtilities Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUtilities_INTERFACE_DEFINED)
    %IUtilities_INTERFACE_DEFINED = 1

INTERFACE IUtilities $IID_IUtilities

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetRandom <1> ( _                             ' VTable offset = 28
     OPTIONAL BYVAL Length AS LONG _                    ' __opt_in long Length [default value = 8]
   , OPTIONAL BYVAL EncodingType AS DWORD _             ' __opt_in CAPICOM_ENCODING_TYPE EncodingType [default value = 1]
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Base64Encode <2> ( _                          ' VTable offset = 32
     BYVAL SrcString AS WSTRING _                       ' __in BSTR SrcString
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD Base64Decode <3> ( _                          ' VTable offset = 36
     BYVAL EncodedString AS WSTRING _                   ' __in BSTR EncodedString
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD BinaryToHex <4> ( _                           ' VTable offset = 40
     BYVAL BinaryString AS WSTRING _                    ' __in BSTR BinaryString
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD HexToBinary <5> ( _                           ' VTable offset = 44
     BYVAL HexString AS WSTRING _                       ' __in BSTR HexString
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD BinaryStringToByteArray <6> ( _               ' VTable offset = 48
     BYVAL BinaryString AS WSTRING _                    ' __in BSTR BinaryString
   ) AS VARIANT                                         ' __retval_out VARIANT* pVal
   ' =====================================================================================
   METHOD ByteArrayToBinaryString <7> ( _               ' VTable offset = 52
     BYVAL varByteArray AS VARIANT _                    ' __in VARIANT varByteArray
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   METHOD LOCALTimeToUTCTime <8> ( _                    ' VTable offset = 56
     BYVAL LOCALTime AS DOUBLE _                        ' __in DATE LOCALTime
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================
   METHOD UTCTimeToLOCALTime <9> ( _                    ' VTable offset = 60
     BYVAL UTCTime AS DOUBLE _                          ' __in DATE UTCTime
   ) AS DOUBLE                                          ' __retval_out DATE* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUtilities_INTERFACE_DEFINED__ */
