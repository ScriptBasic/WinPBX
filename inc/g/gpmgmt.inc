' ########################################################################################
' Microsoft Windows
' File: gpmgmt.inc
' Library name: GPMGMTLib
' Version: 1.0, Locale ID = 0
' Library GUID: {C2F48CC2-305B-4672-BAA7-76A57738F48A}
' Library name: gpmgmt.dll
' Contents: gpmgmt 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GPMGMT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_GPM = GUID$("{F5694708-88FE-4B35-BABF-E56162D5FBC8}")
$CLSID_GPMAsyncCancel = GUID$("{372796A9-76EC-479D-AD6C-556318ED5F9D}")
$CLSID_GPMBackup = GUID$("{ED1A54B8-5EFA-482A-93C0-8AD86F0D68C3}")
$CLSID_GPMBackupCollection = GUID$("{EB8F035B-70DB-4A9F-9676-37C25994E9DC}")
$CLSID_GPMBackupDir = GUID$("{FCE4A59D-0F21-4AFA-B859-E6D0C62CD10C}")
$CLSID_GPMBackupDirEx = GUID$("{E8C0988A-CF03-4C5B-8BE2-2AA9AD32AADA}")
$CLSID_GPMClientSideExtension = GUID$("{C1A2E70E-659C-4B1A-940B-F88B0AF9C8A4}")
$CLSID_GPMConstants = GUID$("{3855E880-CD9E-4D0C-9EAF-1579283A1888}")
$CLSID_GPMCSECollection = GUID$("{CF92B828-2D44-4B61-B10A-B327AFD42DA8}")
$CLSID_GPMDomain = GUID$("{710901BE-1050-4CB1-838A-C5CFF259E183}")
$CLSID_GPMGPO = GUID$("{D2CE2994-59B5-4064-B581-4D68486A16C4}")
$CLSID_GPMGPOCollection = GUID$("{7A057325-832D-4DE3-A41F-C780436A4E09}")
$CLSID_GPMGPOLink = GUID$("{C1DF9880-5303-42C6-8A3C-0488E1BF7364}")
$CLSID_GPMGPOLinksCollection = GUID$("{F6ED581A-49A5-47E2-B771-FD8DC02B6259}")
$CLSID_GPMMapEntry = GUID$("{8C975253-5431-4471-B35D-0626C928258A}")
$CLSID_GPMMapEntryCollection = GUID$("{0CF75D5B-A3A1-4C55-B4FE-9E149C41F66D}")
$CLSID_GPMMigrationTable = GUID$("{55AF4043-2A06-4F72-ABEF-631B44079C76}")
$CLSID_GPMPermission = GUID$("{5871A40A-E9C0-46EC-913E-944EF9225A94}")
$CLSID_GPMResult = GUID$("{92101AC0-9287-4206-A3B2-4BDB73D225F6}")
$CLSID_GPMRSOP = GUID$("{489B0CAF-9EC2-4EB7-91F5-B6F71D43DA8C}")
$CLSID_GPMSearchCriteria = GUID$("{17AACA26-5CE0-44FA-8CC0-5259E6483566}")
$CLSID_GPMSecurityInfo = GUID$("{547A5E8F-9162-4516-A4DF-9DDB9686D846}")
$CLSID_GPMSitesContainer = GUID$("{229F5C42-852C-4B30-945F-C522BE9BD386}")
$CLSID_GPMSOM = GUID$("{32D93FAC-450E-44CF-829C-8B22FF6BDAE1}")
$CLSID_GPMSOMCollection = GUID$("{24C1F147-3720-4F5B-A9C3-06B4E4F931D2}")
$CLSID_GPMStarterGPOBackup = GUID$("{389E400A-D8EF-455B-A861-5F9CA34A6A02}")
$CLSID_GPMStarterGPOBackupCollection = GUID$("{E75EA59D-1AEB-4CB5-A78A-281DAA582406}")
$CLSID_GPMStarterGPOCollection = GUID$("{82F8AA8B-49BA-43B2-956E-3397F9B94C3A}")
$CLSID_GPMStatusMessage = GUID$("{4B77CC94-D255-409B-BC62-370881715A19}")
$CLSID_GPMStatusMsgCollection = GUID$("{2824E4BE-4BCC-4CAC-9E60-0E3ED7F12496}")
$CLSID_GPMTemplate = GUID$("{ECF1D454-71DA-4E2F-A8C0-8185465911D9}")
$CLSID_GPMTrustee = GUID$("{C54A700D-19B6-4211-BCB0-E8E2475E471E}")
$CLSID_GPMWMIFilter = GUID$("{626745D8-0DEA-4062-BF60-CFC5B1CA1286}")
$CLSID_GPMWMIFilterCollection = GUID$("{74DC6D28-E820-47D6-A0B8-F08D93D7FA33}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IGPM = GUID$("{F5FAE809-3BD6-4DA9-A65E-17665B41D763}")
$IID_IGPM2 = GUID$("{00238F8A-3D86-41AC-8F5E-06A6638A634A}")
$IID_IGPMAsyncProgress = GUID$("{6AAC29F8-5948-4324-BF70-423818942DBC}")
$IID_IGPMAsyncCancel = GUID$("{DDC67754-BE67-4541-8166-F48166868C9C}")
$IID_IGPMBackup = GUID$("{D8A16A35-3B0D-416B-8D02-4DF6F95A7119}")
$IID_IGPMBackupCollection = GUID$("{C786FC0F-26D8-4BAB-A745-39CA7E800CAC}")
$IID_IGPMBackupDir = GUID$("{B1568BED-0A93-4ACC-810F-AFE7081019B9}")
$IID_IGPMBackupDirEx = GUID$("{F8DC55ED-3BA0-4864-AAD4-D365189EE1D5}")
$IID_IGPMClientSideExtension = GUID$("{69DA7488-B8DB-415E-9266-901BE4D49928}")
$IID_IGPMConstants = GUID$("{50EF73E6-D35C-4C8D-BE63-7EA5D2AAC5C4}")
$IID_IGPMConstants2 = GUID$("{05AE21B0-AC09-4032-A26F-9E7DA786DC19}")
$IID_IGPMCSECollection = GUID$("{2E52A97D-0A4A-4A6F-85DB-201622455DA0}")
$IID_IGPMDomain = GUID$("{6B21CC14-5A00-4F44-A738-FEEC8A94C7E3}")
$IID_IGPMDomain2 = GUID$("{7CA6BB8B-F1EB-490A-938D-3C4E51C768E6}")
$IID_IGPMGPO = GUID$("{58CC4352-1CA3-48E5-9864-1DA4D6E0D60F}")
$IID_IGPMGPO2 = GUID$("{8A66A210-B78B-4D99-88E2-C306A817C925}")
$IID_IGPMGPOCollection = GUID$("{F0F0D5CF-70CA-4C39-9E29-B642F8726C01}")
$IID_IGPMGPOLink = GUID$("{434B99BD-5DE7-478A-809C-C251721DF70C}")
$IID_IGPMGPOLinksCollection = GUID$("{189D7B68-16BD-4D0D-A2EC-2E6AA2288C7F}")
$IID_IGPMMapEntry = GUID$("{8E79AD06-2381-4444-BE4C-FF693E6E6F2B}")
$IID_IGPMMapEntryCollection = GUID$("{BB0BF49B-E53F-443F-B807-8BE22BFB6D42}")
$IID_IGPMMigrationTable = GUID$("{48F823B1-EFAF-470B-B6ED-40D14EE1A4EC}")
$IID_IGPMPermission = GUID$("{35EBCA40-E1A1-4A02-8905-D79416FB464A}")
$IID_IGPMResult = GUID$("{86DFF7E9-F76F-42AB-9570-CEBC6BE8A52D}")
$IID_IGPMRSOP = GUID$("{49ED785A-3237-4FF2-B1F0-FDF5A8D5A1EE}")
$IID_IGPMSearchCriteria = GUID$("{D6F11C42-829B-48D4-83F5-3615B67DFC22}")
$IID_IGPMSecurityInfo = GUID$("{B6C31ED4-1C93-4D3E-AE84-EB6D61161B60}")
$IID_IGPMSitesContainer = GUID$("{4725A899-2782-4D27-A6BB-D499246FFD72}")
$IID_IGPMSOM = GUID$("{C0A7F09E-05A1-4F0C-8158-9E5C33684F6B}")
$IID_IGPMSOMCollection = GUID$("{ADC1688E-00E4-4495-ABBA-BED200DF0CAB}")
$IID_IGPMStarterGPO = GUID$("{DFC3F61B-8880-4490-9337-D29C7BA8C2F0}")
$IID_IGPMStarterGPOBackup = GUID$("{51D98EDA-A87E-43DD-B80A-0B66EF1938D6}")
$IID_IGPMStarterGPOBackupCollection = GUID$("{C998031D-ADD0-4BB5-8DEA-298505D8423B}")
$IID_IGPMStarterGPOCollection = GUID$("{2E522729-2219-44AD-933A-64DFD650C423}")
$IID_IGPMStatusMessage = GUID$("{8496C22F-F3DE-4A1F-8F58-603CAAA93D7B}")
$IID_IGPMStatusMsgCollection = GUID$("{9B6E1AF0-1A92-40F3-A59D-F36AC1F728B7}")
$IID_IGPMTrustee = GUID$("{3B466DA8-C1A4-4B2A-999A-BEFCDD56CEFB}")
$IID_IGPMWMIFilter = GUID$("{EF2FF9B4-3C27-459A-B979-038305CEC75D}")
$IID_IGPMWMIFilterCollection = GUID$("{5782D582-1A36-4661-8A94-C3C32551945B}")

' enum GPMRSOPMode
%rsopUnknown  = 0
%rsopPlanning = %rsopUnknown + 1
%rsopLogging  = %rsopPlanning + 1

' enum GPMPermissionType
%permGPOApply                 = &H10000
%permGPORead                  = &H10100
%permGPOEdit                  = &H10101
%permGPOEditSecurityAndDelete = &H10102
%permGPOCustom                = &H10103
%permWMIFilterEdit            = &H20000
%permWMIFilterFullControl     = &H20001
%permWMIFilterCustom          = &H20002
%permSOMLink                  = &H1C0000
%permSOMLogging               = &H180100
%permSOMPlanning              = &H180200
%permSOMWMICreate             = &H100300
%permSOMWMIFullControl        = &H100301
%permSOMGPOCreate             = &H100400
%permStarterGPORead           = &H30500
%permStarterGPOEdit           = &H30501
%permStarterGPOFullControl    = &H30502
%permStarterGPOCustom         = &H30503
%permSOMStarterGPOCreate      = &H100500

' enum GPMSearchProperty
%gpoPermissions                 = 0
%gpoEffectivePermissions        = %gpoPermissions                 + 1
%GPODisplayName                 = %gpoEffectivePermissions        + 1
%gpoWMIFilter                   = %GPODisplayName                 + 1
%GPOID                          = %gpoWMIFilter                   + 1
%gpoComputerExtensions          = %GPOID                          + 1
%gpoUserExtensions              = %gpoComputerExtensions          + 1
%somLinks                       = %gpoUserExtensions              + 1
%GPODomain                      = %somLinks                       + 1
%backupMostRecent               = %GPODomain                      + 1
%starterGPOPermissions          = %backupMostRecent               + 1
%starterGPOEffectivePermissions = %starterGPOPermissions          + 1
%starterGPODisplayName          = %starterGPOEffectivePermissions + 1
%starterGPOID                   = %starterGPODisplayName          + 1
%starterGPODomain               = %starterGPOID                   + 1

' enum GPMSearchOperation
%opEquals      = 0
%opContains    = %opEquals + 1
%opNotContains = %opContains + 1
%opNotEquals   = %opNotContains + 1

' enum GPMReportType
%repXML  = 0
%repHTML = %repXML + 1

' enum GPMEntryType
%typeUser           = 0
%typeComputer       = %typeUser + 1
%typeLocalGroup     = %typeComputer + 1
%typeGlobalGroup    = %typeLocalGroup + 1
%typeUniversalGroup = %typeGlobalGroup + 1
%typeUNCPath        = %typeUniversalGroup + 1
%typeUnknown        = %typeUNCPath + 1

' enum GPMDestinationOption
%opDestinationSameAsSource   = 0
%opDestinationNone           = %opDestinationSameAsSource + 1
%opDestinationByRelativeName = %opDestinationNone + 1
%opDestinationSet            = %opDestinationByRelativeName + 1

' enum GPMReportingOptions
%opReportLegacy   = 0
%opReportComments = 1

%GPM_USE_PDC                              = 0
%GPM_USE_ANYDC                            = 1
%GPM_DONOTUSE_W2KDC                       = 2
%GPM_DONOT_VALIDATEDC                     = 1
%GPM_MIGRATIONTABLE_ONLY                  = &H1
%GPM_PROCESS_SECURITY                     = &H2
%RSOP_NO_COMPUTER                         = &H10000
%RSOP_NO_USER                             = &H20000
%RSOP_PLANNING_ASSUME_SLOW_LINK           = &H1
%RSOP_PLANNING_ASSUME_LOOPBACK_MERGE      = &H2
%RSOP_PLANNING_ASSUME_LOOPBACK_REPLACE    = &H4
%RSOP_PLANNING_ASSUME_USER_WQLFILTER_TRUE = &H8
%RSOP_PLANNING_ASSUME_COMP_WQLFILTER_TRUE = &H10

' ########################################################################################
' Interface name = IGPM
' IID = {F5FAE809-3BD6-4DA9-A65E-17665B41D763}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPM_INTERFACE_DEFINED)
    %IGPM_INTERFACE_DEFINED = 1

INTERFACE IGPM $IID_IGPM

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetDomain <1> ( _                             ' VTable offset = 28
     BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   , BYVAL bstrDomainController AS WSTRING _            ' __in BSTR bstrDomainController
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   ) AS IGPMDomain                                      ' __retval_out IGPMDomain **pIGPMDomain
   ' =====================================================================================
   METHOD GetBackupDir <2> ( _                          ' VTable offset = 32
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   ) AS IGPMBackupDir                                   ' __retval_out IGPMBackupDir **pIGPMBackupDir
   ' =====================================================================================
   METHOD GetSitesContainer <3> ( _                     ' VTable offset = 36
     BYVAL bstrForest AS WSTRING _                      ' __in BSTR bstrForest
   , BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   , BYVAL bstrDomainController AS WSTRING _            ' __in BSTR bstrDomainController
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   ) AS IGPMSitesContainer                              ' __retval_out IGPMSitesContainer **ppIGPMSitesContainer
   ' =====================================================================================
   METHOD GetRSOP <4> ( _                               ' VTable offset = 40
     BYVAL GPMRSOPMode AS LONG _                        ' __in GPMRSOPMode GPMRSOPMode
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IGPMRSOP                                        ' __retval_out IGPMRSOP **ppIGPMRSOP
   ' =====================================================================================
   METHOD CreatePermission <5> ( _                      ' VTable offset = 44
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   , BYVAL GPMPermissionType AS LONG _                  ' __in GPMPermissionType
   , BYVAL bInheritable AS INTEGER _                    ' __in VARIANT_BOOL bInheritable
   ) AS IGPMPermission                                  ' __retval_out IGPMPermission **ppPerm
   ' =====================================================================================
   METHOD CreateSearchCriteria <6> ( _                  ' VTable offset = 48
   ) AS IGPMSearchCriteria                              ' __retval_out IGPMSearchCriteria **ppIGPMSearchCriteria
   ' =====================================================================================
   METHOD CreateTrustee <7> ( _                         ' VTable offset = 52
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   ) AS IGPMTrustee                                     ' __retval_out IGPMTrustee **ppIGPMTrustee
   ' =====================================================================================
   METHOD GetClientSideExtensions <8> ( _               ' VTable offset = 56
   ) AS IGPMCSECollection                               ' __retval_out IGPMCSECollection **ppIGPMCSECollection
   ' =====================================================================================
   METHOD GetConstants <9> ( _                          ' VTable offset = 60
   ) AS IGPMConstants                                   ' __retval_out IGPMConstants **ppIGPMConstants
   ' =====================================================================================
   METHOD GetMigrationTable <10> ( _                    ' VTable offset = 64
     BYVAL bstrMigrationTablePath AS WSTRING _          ' __in BSTR bstrMigrationTablePath
   ) AS IGPMMigrationTable                              ' __retval_out IGPMMigrationTable **ppMigrationTable
   ' =====================================================================================
   METHOD CreateMigrationTable <11> ( _                 ' VTable offset = 68
   ) AS IGPMMigrationTable                              ' __retval_out **ppMigrationTable IGPMMigrationTable
   ' =====================================================================================
   METHOD InitializeReporting <12> ( _                  ' VTable offset = 72
     BYVAL bstrAdmPath AS WSTRING _                     ' __in BSTR bstrAdmPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPM_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMDomain
' IID = {6B21CC14-5A00-4F44-A738-FEEC8A94C7E3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMDomain_INTERFACE_DEFINED)
    %IGPMDomain_INTERFACE_DEFINED = 1

INTERFACE IGPMDomain $IID_IGPMDomain

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DomainController <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Domain <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD CreateGPO <4> ( _                             ' VTable offset = 36
   ) AS IGPMGPO                                         ' __retval_out IGPMGPO **ppNewGPO
   ' =====================================================================================
   METHOD GetGPO <5> ( _                                ' VTable offset = 40
     BYVAL bstrGuid AS WSTRING _                        ' __in BSTR bstrGuid
   ) AS IGPMGPO                                         ' __retval_out IGPMGPO **ppGPO
   ' =====================================================================================
   METHOD SearchGPOs <6> ( _                            ' VTable offset = 44
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMGPOCollection                               ' __retval_out IGPMGPOCollection **ppIGPMGPOCollection
   ' =====================================================================================
   METHOD RestoreGPO <7> ( _                            ' VTable offset = 48
     BYVAL pIGPMBackup AS IGPMBackup _                  ' __in IGPMBackup *pIGPMBackup
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GetSOM <8> ( _                                ' VTable offset = 52
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IGPMSOM                                         ' __retval_out IGPMSOM **ppSOM
   ' =====================================================================================
   METHOD SearchSOMs <9> ( _                            ' VTable offset = 56
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMSOMCollection                               ' __retval_out IGPMSOMCollection **ppIGPMSOMCollection
   ' =====================================================================================
   METHOD GetWMIFilter <10> ( _                         ' VTable offset = 60
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IGPMWMIFilter                                   ' __retval_out IGPMWMIFilter **ppWMIFilter
   ' =====================================================================================
   METHOD SearchWMIFilters <11> ( _                     ' VTable offset = 64
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMWMIFilterCollection                         ' __retval_out IGPMWMIFilterCollection **ppIGPMWMIFilterCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMDomain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMBackupDir
' IID = {B1568BED-0A93-4ACC-810F-AFE7081019B9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMBackupDir_INTERFACE_DEFINED)
    %IGPMBackupDir_INTERFACE_DEFINED = 1

INTERFACE IGPMBackupDir $IID_IGPMBackupDir

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BackupDirectory <1> ( _                 ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD GetBackup <2> ( _                             ' VTable offset = 32
     BYVAL bstrID AS WSTRING _                          ' __in BSTR bstrID
   ) AS IGPMBackup                                      ' __retval_out IGPMBackup **ppBackup
   ' =====================================================================================
   METHOD SearchBackups <3> ( _                         ' VTable offset = 36
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMBackupCollection                            ' __retval_out IGPMBackupCollection **ppIGPMBackupCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMBackupDir_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMSitesContainer
' IID = {4725A899-2782-4D27-A6BB-D499246FFD72}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMSitesContainer_INTERFACE_DEFINED)
    %IGPMSitesContainer_INTERFACE_DEFINED = 1

INTERFACE IGPMSitesContainer $IID_IGPMSitesContainer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DomainController <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Domain <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Forest <3> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD GetSite <4> ( _                               ' VTable offset = 40
     BYVAL bstrSiteName AS WSTRING _                    ' __in BSTR bstrSiteName
   ) AS IGPMSOM                                         ' __retval_out IGPMSOM **ppSOM
   ' =====================================================================================
   METHOD SearchSites <5> ( _                           ' VTable offset = 44
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMSOMCollection                               ' __retval_out IGPMSOMCollection **ppIGPMSOMCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMSitesContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMSearchCriteria
' IID = {D6F11C42-829B-48D4-83F5-3615B67DFC22}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMSearchCriteria_INTERFACE_DEFINED)
    %IGPMSearchCriteria_INTERFACE_DEFINED = 1

INTERFACE IGPMSearchCriteria $IID_IGPMSearchCriteria

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Add <1> ( _                                   ' VTable offset = 28
     BYVAL searchProperty AS LONG _                     ' __in GPMSearchProperty searchProperty
   , BYVAL searchOperation AS LONG _                    ' __in GPMSearchOperation searchOperation
   , BYVAL VARIANT _                                    ' __in VARIANT varValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMSearchCriteria_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMTrustee
' IID = {3B466DA8-C1A4-4B2A-999A-BEFCDD56CEFB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMTrustee_INTERFACE_DEFINED)
    %IGPMTrustee_INTERFACE_DEFINED = 1

INTERFACE IGPMTrustee $IID_IGPMTrustee

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TrusteeSid <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY GET TrusteeName <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY GET TrusteeDomain <3> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY GET TrusteeDSPath <4> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET TrusteeType <5> ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *lVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMTrustee_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMPermission
' IID = {35EBCA40-E1A1-4A02-8905-D79416FB464A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMPermission_INTERFACE_DEFINED)
    %IGPMPermission_INTERFACE_DEFINED = 1

INTERFACE IGPMPermission $IID_IGPMPermission

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Inherited <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET Inheritable <2> ( _                     ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET Denied <3> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY GET Permission <4> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET Trustee <5> ( _                         ' VTable offset = 44
   ) AS IGPMTrustee                                     ' __retval_out IGPMTrustee **ppIGPMTrustee
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMPermission_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMSecurityInfo
' IID = {B6C31ED4-1C93-4D3E-AE84-EB6D61161B60}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMSecurityInfo_INTERFACE_DEFINED)
    %IGPMSecurityInfo_INTERFACE_DEFINED = 1

INTERFACE IGPMSecurityInfo $IID_IGPMSecurityInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppEnum
   ' =====================================================================================
   METHOD Add <5> ( _                                   ' VTable offset = 40
     BYVAL pPerm AS IGPMPermission _                    ' __in IGPMPermission *pPerm
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <6> ( _                                ' VTable offset = 44
     BYVAL pPerm AS IGPMPermission _                    ' __in IGPMPermission *pPerm
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveTrustee <7> ( _                         ' VTable offset = 48
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMSecurityInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMBackup
' IID = {D8A16A35-3B0D-416B-8D02-4DF6F95A7119}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMBackup_INTERFACE_DEFINED)
    %IGPMBackup_INTERFACE_DEFINED = 1

INTERFACE IGPMBackup $IID_IGPMBackup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET GPOID <2> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET GPODomain <3> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET GPODisplayName <4> ( _                  ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Timestamp <5> ( _                       ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY GET Comment <6> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET BackupDir <7> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD Delete <8> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateReport <9> ( _                        ' VTable offset = 60
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <10> ( _                 ' VTable offset = 64
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMBackup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMBackupCollection
' IID = {C786FC0F-26D8-4BAB-A745-39CA7E800CAC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMBackupCollection_INTERFACE_DEFINED)
    %IGPMBackupCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMBackupCollection $IID_IGPMBackupCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMBackup
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMBackupCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMSOM
' IID = {C0A7F09E-05A1-4F0C-8158-9E5C33684F6B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMSOM_INTERFACE_DEFINED)
    %IGPMSOM_INTERFACE_DEFINED = 1

' enum GPMSOMType
%somSite   = 0
%somDomain = %somSite + 1
%somOU     = %somDomain + 1

INTERFACE IGPMSOM $IID_IGPMSOM

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET GPOInheritanceBlocked <1> ( _           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL*pVal
   ' =====================================================================================
   PROPERTY SET GPOInheritanceBlocked <1> ( _           ' VTable offset = 32
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Path <4> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD CreateGPOLink <5> ( _                         ' VTable offset = 44
     BYVAL lLinkPos AS LONG _                           ' __in long lLinkPos
   , BYVAL pGPO AS IGPMGPO _                            ' __in IGPMGPO *pGPO
   ) AS IGPMGPOLink                                     ' __retval_out IGPMGPOLink **ppNewGPOLink
   ' =====================================================================================
   PROPERTY GET Type <6> ( _                            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   METHOD GetGPOLinks <7> ( _                           ' VTable offset = 52
   ) AS IGPMGPOLinksCollection                          ' __retval_out IGPMGPOLinksCollection **ppGPOLinks
   ' =====================================================================================
   METHOD GetInheritedGPOLinks <8> ( _                  ' VTable offset = 56
   ) AS IGPMGPOLinksCollection                          ' __retval_out IGPMGPOLinksCollection **ppGPOLinks
   ' =====================================================================================
   METHOD GetSecurityInfo <9> ( _                       ' VTable offset = 60
   ) AS IGPMSecurityInfo                                ' __retval_out IGPMSecurityInfo **ppSecurityInfo
   ' =====================================================================================
   METHOD SetSecurityInfo <10> ( _                      ' VTable offset = 64
     BYVAL pSecurityInfo AS IGPMSecurityInfo _          ' __in IGPMSecurityInfo *pSecurityInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMSOM_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMSOMCollection
' IID = {ADC1688E-00E4-4495-ABBA-BED200DF0CAB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMSOMCollection_INTERFACE_DEFINED)
    %IGPMSOMCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMSOMCollection $IID_IGPMSOMCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMSOM
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMSOMCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMWMIFilter
' IID = {EF2FF9B4-3C27-459A-B979-038305CEC75D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMWMIFilter_INTERFACE_DEFINED)
    %IGPMWMIFilter_INTERFACE_DEFINED = 1

INTERFACE IGPMWMIFilter $IID_IGPMWMIFilter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <2> ( _                            ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Description <3> ( _                     ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <3> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD GetQueryList <4> ( _                          ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pQryList
   ' =====================================================================================
   METHOD GetSecurityInfo <5> ( _                       ' VTable offset = 52
   ) AS IGPMSecurityInfo                                ' __retval_out IGPMSecurityInfo **ppSecurityInfo
   ' =====================================================================================
   METHOD SetSecurityInfo <6> ( _                       ' VTable offset = 56
     BYVAL pSecurityInfo AS IGPMSecurityInfo _          ' __in IGPMSecurityInfo *pSecurityInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMWMIFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMWMIFilterCollection
' IID = {5782D582-1A36-4661-8A94-C3C32551945B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMWMIFilterCollection_INTERFACE_DEFINED)
    %IGPMWMIFilterCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMWMIFilterCollection $IID_IGPMWMIFilterCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMWMIFilterCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMRSOP
' IID = {49ED785A-3237-4FF2-B1F0-FDF5A8D5A1EE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMRSOP_INTERFACE_DEFINED)
    %IGPMRSOP_INTERFACE_DEFINED = 1

INTERFACE IGPMRSOP $IID_IGPMRSOP

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Mode <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET Namespace <2> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET LoggingComputer <3> ( _                 ' VTable offset = 36
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoggingComputer <3> ( _                 ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET LoggingUser <4> ( _                     ' VTable offset = 44
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoggingUser <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET LoggingFlags <5> ( _                    ' VTable offset = 52
     BYVAL LONG _                                       ' __in long lVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoggingFlags <5> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *lVal
   ' =====================================================================================
   PROPERTY SET PlanningFlags <6> ( _                   ' VTable offset = 60
     BYVAL lVal AS LONG _                               ' __in long lVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningFlags <6> ( _                   ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *lVal
   ' =====================================================================================
   PROPERTY SET PlanningDomainController <7> ( _        ' VTable offset = 68
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningDomainController <7> ( _        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningSiteName <8> ( _                ' VTable offset = 76
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningSiteName <8> ( _                ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningUser <9> ( _                    ' VTable offset = 84
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningUser <9> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningUserSOM <10> ( _                ' VTable offset = 92
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningUserSOM <10> ( _                ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningUserWMIFilters <11> ( _         ' VTable offset = 100
     BYVAL varVal AS VARIANT _                          ' __in VARIANT varVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningUserWMIFilters <11> ( _         ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *varVal
   ' =====================================================================================
   PROPERTY SET PlanningUserSecurityGroups <12> ( _     ' VTable offset = 108
     BYVAL varVal AS VARIANT _                          ' __in VARIANT varVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningUserSecurityGroups <12> ( _     ' VTable offset = 112
   ) AS VARIANT                                         ' __retval_out VARIANT *varVal
   ' =====================================================================================
   PROPERTY SET PlanningComputer <13> ( _               ' VTable offset = 116
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningComputer <13> ( _               ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningComputerSOM <14> ( _            ' VTable offset = 124
     BYVAL bstrVal AS WSTRING _                         ' __in BSTR bstrVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningComputerSOM <14> ( _            ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *bstrVal
   ' =====================================================================================
   PROPERTY SET PlanningComputerWMIFilters <15> ( _     ' VTable offset = 132
     BYVAL varVal AS VARIANT _                          ' __in VARIANT varVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningComputerWMIFilters <15> ( _     ' VTable offset = 136
   ) AS VARIANT                                         ' __retval_out VARIANT *varVal
   ' =====================================================================================
   PROPERTY SET PlanningComputerSecurityGroups <16> ( _ ' VTable offset = 140
     BYVAL varVal AS VARIANT _                          ' __in VARIANT varVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PlanningComputerSecurityGroups <16> ( _ ' VTable offset = 144
   ) AS VARIANT                                         ' __retval_out VARIANT *varVal
   ' =====================================================================================
   METHOD LoggingEnumerateUsers <17> ( _                ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *varVal
   ' =====================================================================================
   METHOD CreateQueryResults <18> ( _                   ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseQueryResults <19> ( _                  ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateReport <20> ( _                       ' VTable offset = 160
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <21> ( _                 ' VTable offset = 164
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMRSOP_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMGPO
' IID = {58CC4352-1CA3-48E5-9864-1DA4D6E0D60F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMGPO_INTERFACE_DEFINED)
    %IGPMGPO_INTERFACE_DEFINED = 1

INTERFACE IGPMGPO $IID_IGPMGPO

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DisplayName <1> ( _                     ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ID <4> ( _                              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DomainName <5> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <6> ( _                    ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY GET ModificationTime <7> ( _                ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY GET UserDSVersionNumber <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ComputerDSVersionNumber <9> ( _         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET UserSysvolVersionNumber <10> ( _        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ComputerSysvolVersionNumber <11> ( _    ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD GetWMIFilter <12> ( _                         ' VTable offset = 72
   ) AS IGPMWMIFilter                                   ' __retval_out IGPMWMIFilter **ppIGPMWMIFilter
   ' =====================================================================================
   METHOD SetWMIFilter <13> ( _                         ' VTable offset = 76
     BYVAL pIGPMWMIFilter AS IGPMWMIFilter _            ' __in IGPMWMIFilter *pIGPMWMIFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUserEnabled <14> ( _                       ' VTable offset = 80
     BYVAL vbEnabled AS INTEGER _                       ' __in VARIANT_BOOL vbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SetComputerEnabled <15> ( _                   ' VTable offset = 84
     BYVAL vbEnabled AS INTEGER _                       ' __in VARIANT_BOOL vbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUserEnabled <16> ( _                        ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD IsComputerEnabled <17> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD GetSecurityInfo <18> ( _                      ' VTable offset = 96
   ) AS IGPMSecurityInfo                                ' __retval_out IGPMSecurityInfo **ppSecurityInfo
   ' =====================================================================================
   METHOD SetSecurityInfo <19> ( _                      ' VTable offset = 100
     BYVAL pSecurityInfo AS IGPMSecurityInfo _          ' __in IGPMSecurityInfo *pSecurityInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <20> ( _                               ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD Backup <21> ( _                               ' VTable offset = 108
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   , BYVAL bstrComment AS WSTRING _                     ' __in BSTR bstrComment
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD Import <22> ( _                               ' VTable offset = 112
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pIGPMBackup AS IGPMBackup _                  ' __in IGPMBackup *pIGPMBackup
   , OPTIONAL BYREF pvarMigrationTable AS VARIANT _     ' __in_opt VARIANT *pvarMigrationTable
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReport <23> ( _                       ' VTable offset = 116
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <24> ( _                 ' VTable offset = 120
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD CopyTo <25> ( _                               ' VTable offset = 124
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pIGPMDomain AS IGPMDomain _                  ' __in IGPMDomain *pIGPMDomain
   , OPTIONAL BYREF pvarNewDisplayName AS VARIANT _     ' __in_opt VARIANT *pvarNewDisplayName
   , OPTIONAL BYREF pvarMigrationTable AS VARIANT _     ' __in_opt VARIANT *pvarMigrationTable
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt  VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD SetSecurityDescriptor <26> ( _                ' VTable offset = 128
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pSD AS IDispatch _                           ' __in IDispatch *pSD
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSecurityDescriptor <27> ( _                ' VTable offset = 132
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IDispatch                                       ' __retval_out IDispatch **ppSD
   ' =====================================================================================
   METHOD IsACLConsistent <28> ( _                      ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbConsistent
   ' =====================================================================================
   METHOD MakeACLConsistent <29> ( _                    ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMGPO_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMGPOCollection
' IID = {F0F0D5CF-70CA-4C39-9E29-B642F8726C01}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMGPOCollection_INTERFACE_DEFINED)
    %IGPMGPOCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMGPOCollection $IID_IGPMGPOCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMGPOs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMGPOCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMGPOLink
' IID = {434B99BD-5DE7-478A-809C-C251721DF70C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMGPOLink_INTERFACE_DEFINED)
    %IGPMGPOLink_INTERFACE_DEFINED = 1

INTERFACE IGPMGPOLink $IID_IGPMGPOLink

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET GPOID <1> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET GPODomain <2> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Enabled <3> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Enabled <3> ( _                         ' VTable offset = 40
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enforced <4> ( _                        ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Enforced <4> ( _                        ' VTable offset = 48
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SOMLinkOrder <5> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *lVal
   ' =====================================================================================
   PROPERTY GET SOM <6> ( _                             ' VTable offset = 56
   ) AS IGPMSOM                                         ' __retval_out IGPMSOM **ppIGPMSOM
   ' =====================================================================================
   METHOD Delete <7> ( _                                ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMGPOLink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMGPOLinksCollection
' IID = {189D7B68-16BD-4D0D-A2EC-2E6AA2288C7F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMGPOLinksCollection_INTERFACE_DEFINED)
    %IGPMGPOLinksCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMGPOLinksCollection $IID_IGPMGPOLinksCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMLinks
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMGPOLinksCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMCSECollection
' IID = {2E52A97D-0A4A-4A6F-85DB-201622455DA0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMCSECollection_INTERFACE_DEFINED)
    %IGPMCSECollection_INTERFACE_DEFINED = 1

INTERFACE IGPMCSECollection $IID_IGPMCSECollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMCSEs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMCSECollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMClientSideExtension
' IID = {69DA7488-B8DB-415E-9266-901BE4D49928}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMClientSideExtension_INTERFACE_DEFINED)
    %IGPMClientSideExtension_INTERFACE_DEFINED = 1

INTERFACE IGPMClientSideExtension $IID_IGPMClientSideExtension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DisplayName <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD IsUserEnabled <3> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD IsComputerEnabled <4> ( _                     ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMClientSideExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMAsyncCancel
' IID = {DDC67754-BE67-4541-8166-F48166868C9C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMAsyncCancel_INTERFACE_DEFINED)
    %IGPMAsyncCancel_INTERFACE_DEFINED = 1

INTERFACE IGPMAsyncCancel $IID_IGPMAsyncCancel

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Cancel <1> ( _                                ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMAsyncCancel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMAsyncProgress
' IID = {6AAC29F8-5948-4324-BF70-423818942DBC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ========================================================================================
' The IGPMAsyncProgress interface can be implemented by the client and passed as an input
' parameter to the Group Policy Management Console (GPMC) methods that can execute
' asynchronously. The server will then notify the client about the progress of the
' operation. This object cannot be accessed through scripting.
' Complex GPMC operations, such as backup, restore, import, and copy operations, can
' execute asynchronously. To use this interface with asynchronous operations, follow
' these steps.
' - To use this interface with asynchronous operations
'   1. Implement the IGPMAsyncProgress interface.
'   2. Pass the IGPMAsyncProgress interface pointer to the GPMC method.
'      For example, pass the interface pointer to the RestoreGPO method or to the Import method.
' The server will call the Status method to notify the client about the progress of the
' operation. This method also returns an IGPMAsyncCancel interface pointer so that the
' caller can cancel the operation by calling the Cancel method.
' ========================================================================================

#IF NOT %DEF(%IGPMAsyncProgress_INTERFACE_DEFINED)
    %IGPMAsyncProgress_INTERFACE_DEFINED = 1

$IID_IGPMAsyncProgress = GUID$("{6AAC29F8-5948-4324-BF70-423818942DBC}")

INTERFACE IGPMAsyncProgress $IID_IGPMAsyncProgress

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Status ( _                                    ' VTable offset = 28
     BYVAL lProgressNumerator AS LONG _                 ' __in long lProgressNumerator
   , BYVAL lProgressDenominator AS LONG _               ' __in long lProgressDenominator
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pResult AS VARIANT _                         ' __in VARIANT *pResult
   , BYVAL ppIGPMStatusMsgCollection AS IGPMStatusMsgCollection _ ' __in IGPMStatusMsgCollection *ppIGPMStatusMsgCollection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMAsyncProgress_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStatusMsgCollection
' IID = {9B6E1AF0-1A92-40F3-A59D-F36AC1F728B7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStatusMsgCollection_INTERFACE_DEFINED)
    %IGPMStatusMsgCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMStatusMsgCollection $IID_IGPMStatusMsgCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStatusMsgCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStatusMessage
' IID = {8496C22F-F3DE-4A1F-8F58-603CAAA93D7B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStatusMessage_INTERFACE_DEFINED)
    %IGPMStatusMessage_INTERFACE_DEFINED = 1

INTERFACE IGPMStatusMessage $IID_IGPMStatusMessage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ObjectPath <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD ErrorCode <2> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtensionName <3> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SettingsName <4> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD OperationCode <5> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Message <6> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStatusMessage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMConstants
' IID = {50EF73E6-D35C-4C8D-BE63-7EA5D2AAC5C4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMConstants_INTERFACE_DEFINED)
    %IGPMConstants_INTERFACE_DEFINED = 1

INTERFACE IGPMConstants $IID_IGPMConstants

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET permGPOApply <1> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPORead <2> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOEdit <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOEditSecurityAndDelete <4> ( _    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOCustom <5> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterEdit <6> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterFullControl <7> ( _        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterCustom <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMLink <9> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMLogging <10> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMPlanning <11> ( _                ' VTable offset = 68
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMGPOCreate <12> ( _               ' VTable offset = 72
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMWMICreate <13> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMWMIFullControl <14> ( _          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOPermissions <15> ( _   ' VTable offset = 84
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOEffectivePermissions <16> ( _ ' VTable offset = 88
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPODisplayName <17> ( _   ' VTable offset = 92
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOWMIFilter <18> ( _     ' VTable offset = 96
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOID <19> ( _            ' VTable offset = 100
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOComputerExtensions <20> ( _ ' VTable offset = 104
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOUserExtensions <21> ( _ ' VTable offset = 108
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertySOMLinks <22> ( _         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPODomain <23> ( _        ' VTable offset = 116
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyBackupMostRecent <24> ( _ ' VTable offset = 120
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpEquals <25> ( _                 ' VTable offset = 124
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpContains <26> ( _               ' VTable offset = 128
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpNotContains <27> ( _            ' VTable offset = 132
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpNotEquals <28> ( _              ' VTable offset = 136
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET UsePDC <29> ( _                         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET UseAnyDC <30> ( _                       ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DoNotUseW2KDC <31> ( _                  ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET somSite <32> ( _                        ' VTable offset = 152
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET somDomain <33> ( _                      ' VTable offset = 156
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET somOU <34> ( _                          ' VTable offset = 160
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET SecurityFlags <35> ( _                  ' VTable offset = 164
     BYVAL vbOwner AS INTEGER _                         ' __in VARIANT_BOOL vbOwner
   , BYVAL vbGroup AS INTEGER _                         ' __in VARIANT_BOOL vbGroup
   , BYVAL vbDACL AS INTEGER _                          ' __in VARIANT_BOOL vbDACL
   , BYVAL vbSACL AS INTEGER _                          ' __in VARIANT_BOOL vbSACL
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DoNotValidateDC <36> ( _                ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ReportHTML <37> ( _                     ' VTable offset = 172
   ) AS LONG                                            ' __retval_out GPMReportType *pVal
   ' =====================================================================================
   PROPERTY GET ReportXML <38> ( _                      ' VTable offset = 176
   ) AS LONG                                            ' __retval_out GPMReportType *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModeUnknown <39> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModePlanning <40> ( _               ' VTable offset = 184
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModeLogging <41> ( _                ' VTable offset = 188
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUser <42> ( _                  ' VTable offset = 192
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeComputer <43> ( _              ' VTable offset = 196
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeLocalGroup <44> ( _            ' VTable offset = 200
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeGlobalGroup <45> ( _           ' VTable offset = 204
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUniversalGroup <46> ( _        ' VTable offset = 208
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUNCPath <47> ( _               ' VTable offset = 212
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUnknown <48> ( _               ' VTable offset = 216
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionSameAsSource <49> ( _  ' VTable offset = 220
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionNone <50> ( _          ' VTable offset = 224
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionByRelativeName <51> ( _ ' VTable offset = 228
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionSet <52> ( _           ' VTable offset = 232
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET MigrationTableOnly <53> ( _             ' VTable offset = 236
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ProcessSecurity <54> ( _                ' VTable offset = 240
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopLoggingNoComputer <55> ( _          ' VTable offset = 244
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopLoggingNoUser <56> ( _              ' VTable offset = 248
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeSlowLink <57> ( _     ' VTable offset = 252
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningLoopbackOption <58> ( _     ' VTable offset = 256
     BYVAL vbMerge AS INTEGER _                         ' __in VARIANT_BOOL vbMerge
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeUserWQLFilterTrue <59> ( _ ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeCompWQLFilterTrue <60> ( _ ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMConstants_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMResult
' IID = {86DFF7E9-F76F-42AB-9570-CEBC6BE8A52D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMResult_INTERFACE_DEFINED)
    %IGPMResult_INTERFACE_DEFINED = 1

INTERFACE IGPMResult $IID_IGPMResult

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 28
   ) AS IGPMStatusMsgCollection                         ' __retval_out IGPMStatusMsgCollection **ppIGPMStatusMsgCollection
   ' =====================================================================================
   PROPERTY GET Result <2> ( _                          ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResult
   ' =====================================================================================
   METHOD OverallStatus <3> ( _                         ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMResult_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMMapEntryCollection
' IID = {BB0BF49B-E53F-443F-B807-8BE22BFB6D42}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMMapEntryCollection_INTERFACE_DEFINED)
    %IGPMMapEntryCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMMapEntryCollection $IID_IGPMMapEntryCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMMapEntryCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMMapEntry
' IID = {8E79AD06-2381-4444-BE4C-FF693E6E6F2B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMMapEntry_INTERFACE_DEFINED)
    %IGPMMapEntry_INTERFACE_DEFINED = 1

INTERFACE IGPMMapEntry $IID_IGPMMapEntry

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Source <1> ( _                          ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSource
   ' =====================================================================================
   PROPERTY GET Destination <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDestination
   ' =====================================================================================
   PROPERTY GET DestinationOption <3> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pgpmDestOption
   ' =====================================================================================
   PROPERTY GET EntryType <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out GPMEntryType *pgpmEntryType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMMapEntry_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMMigrationTable
' IID = {48F823B1-EFAF-470B-B6ED-40D14EE1A4EC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMMigrationTable_INTERFACE_DEFINED)
    %IGPMMigrationTable_INTERFACE_DEFINED = 1

INTERFACE IGPMMigrationTable $IID_IGPMMigrationTable

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Save <1> ( _                                  ' VTable offset = 28
     BYVAL bstrMigrationTablePath AS WSTRING _          ' __in BSTR bstrMigrationTablePath
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   METHOD AddEntry <3> ( _                              ' VTable offset = 36
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   , BYVAL GPMEntryType AS LONG _                       ' __in GPMEntryType GPMEntryType
   , OPTIONAL BYREF pvarDestination AS VARIANT _        ' __in_opt VARIANT *pvarDestination
   ) AS IGPMMapEntry                                    ' __retval_out IGPMMapEntry **ppEntry
   ' =====================================================================================
   METHOD GetEntry <4> ( _                              ' VTable offset = 40
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   ) AS IGPMMapEntry                                    ' __retval_out IGPMMapEntry **ppEntry
   ' =====================================================================================
   METHOD DeleteEntry <5> ( _                           ' VTable offset = 44
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateDestination <6> ( _                     ' VTable offset = 48
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   , OPTIONAL BYREF pvarDestination AS VARIANT _        ' __in_opt VARIANT *pvarDestination
   ) AS IGPMMapEntry                                    ' __retval_out IGPMMapEntry **ppEntry
   ' =====================================================================================
   METHOD Validate <7> ( _                              ' VTable offset = 52
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppResult
   ' =====================================================================================
   METHOD GetEntries <8> ( _                            ' VTable offset = 56
   ) AS IGPMMapEntryCollection                          ' __retval_out IGPMMapEntryCollection **ppEntries
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMMigrationTable_INTERFACE_DEFINED__ */

' enum GPMBackupType
%typeGPO        = 0
%typeStarterGPO = %typeGPO + 1

' enum GPMStarterGPOType
%typeSystem = 0
%typeCustom = %typeSystem + 1

' ########################################################################################
' Interface name = IGPMBackupDirEx
' IID = {F8DC55ED-3BA0-4864-AAD4-D365189EE1D5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMBackupDirEx_INTERFACE_DEFINED)
    %IGPMBackupDirEx_INTERFACE_DEFINED = 1

INTERFACE IGPMBackupDirEx $IID_IGPMBackupDirEx

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BackupDir <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBackupDir
   ' =====================================================================================
   PROPERTY GET BackupType <2> ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out GPMBackupType *pgpmBackupType
   ' =====================================================================================
   METHOD GetBackup <3> ( _                             ' VTable offset = 36
     BYVAL bstrID AS WSTRING _                          ' __in BSTR bstrID
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBackup
   ' =====================================================================================
   METHOD SearchBackups <4> ( _                         ' VTable offset = 40
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBackupCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMBackupDirEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStarterGPOBackupCollection
' IID = {C998031D-ADD0-4BB5-8DEA-298505D8423B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStarterGPOBackupCollection_INTERFACE_DEFINED)
    %IGPMStarterGPOBackupCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMStarterGPOBackupCollection $IID_IGPMStarterGPOBackupCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMTmplBackup
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStarterGPOBackupCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStarterGPOBackup
' IID = {51D98EDA-A87E-43DD-B80A-0B66EF1938D6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStarterGPOBackup_INTERFACE_DEFINED)
    %IGPMStarterGPOBackup_INTERFACE_DEFINED = 1

INTERFACE IGPMStarterGPOBackup $IID_IGPMStarterGPOBackup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BackupDir <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBackupDir
   ' =====================================================================================
   PROPERTY GET Comment <2> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrComment
   ' =====================================================================================
   PROPERTY GET DisplayName <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDisplayName
   ' =====================================================================================
   PROPERTY GET Domain <4> ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTemplateDomain
   ' =====================================================================================
   PROPERTY GET starterGPOID <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTemplateID
   ' =====================================================================================
   PROPERTY GET ID <6> ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrID
   ' =====================================================================================
   PROPERTY GET Timestamp <7> ( _                       ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pTimestamp
   ' =====================================================================================
   PROPERTY GET Type <8> ( _                            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out GPMStarterGPOType *pType
   ' =====================================================================================
   METHOD Delete <9> ( _                                ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateReport <10> ( _                       ' VTable offset = 64
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType gpmReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_iout VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <11> ( _                 ' VTable offset = 68
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType gpmReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStarterGPOBackup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPM2
' IID = {00238F8A-3D86-41AC-8F5E-06A6638A634A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IGPM
' ########################################################################################

#IF NOT %DEF(%IGPM2_INTERFACE_DEFINED)
    %IGPM2_INTERFACE_DEFINED = 1

INTERFACE IGPM2 $IID_IGPM2

   INHERIT IDispatch

   ' =====================================================================================
   ' IGPM Methods
   ' =====================================================================================
   METHOD GetDomain <1> ( _                             ' VTable offset = 28
     BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   , BYVAL bstrDomainController AS WSTRING _            ' __in BSTR bstrDomainController
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   ) AS IGPMDomain                                      ' __retval_out IGPMDomain **pIGPMDomain
   ' =====================================================================================
   METHOD GetBackupDir <2> ( _                          ' VTable offset = 32
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   ) AS IGPMBackupDir                                   ' __retval_out IGPMBackupDir **pIGPMBackupDir
   ' =====================================================================================
   METHOD GetSitesContainer <3> ( _                     ' VTable offset = 36
     BYVAL bstrForest AS WSTRING _                      ' __in BSTR bstrForest
   , BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   , BYVAL bstrDomainController AS WSTRING _            ' __in BSTR bstrDomainController
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   ) AS IGPMSitesContainer                              ' __retval_out IGPMSitesContainer **ppIGPMSitesContainer
   ' =====================================================================================
   METHOD GetRSOP <4> ( _                               ' VTable offset = 40
     BYVAL GPMRSOPMode AS LONG _                        ' __in GPMRSOPMode GPMRSOPMode
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IGPMRSOP                                        ' __retval_out IGPMRSOP **ppIGPMRSOP
   ' =====================================================================================
   METHOD CreatePermission <5> ( _                      ' VTable offset = 44
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   , BYVAL GPMPermissionType AS LONG _                  ' __in GPMPermissionType
   , BYVAL bInheritable AS INTEGER _                    ' __in VARIANT_BOOL bInheritable
   ) AS IGPMPermission                                  ' __retval_out IGPMPermission **ppPerm
   ' =====================================================================================
   METHOD CreateSearchCriteria <6> ( _                  ' VTable offset = 48
   ) AS IGPMSearchCriteria                              ' __retval_out IGPMSearchCriteria **ppIGPMSearchCriteria
   ' =====================================================================================
   METHOD CreateTrustee <7> ( _                         ' VTable offset = 52
     BYVAL bstrTrustee AS WSTRING _                     ' __in BSTR bstrTrustee
   ) AS IGPMTrustee                                     ' __retval_out IGPMTrustee **ppIGPMTrustee
   ' =====================================================================================
   METHOD GetClientSideExtensions <8> ( _               ' VTable offset = 56
   ) AS IGPMCSECollection                               ' __retval_out IGPMCSECollection **ppIGPMCSECollection
   ' =====================================================================================
   METHOD GetConstants <9> ( _                          ' VTable offset = 60
   ) AS IGPMConstants                                   ' __retval_out IGPMConstants **ppIGPMConstants
   ' =====================================================================================
   METHOD GetMigrationTable <10> ( _                    ' VTable offset = 64
     BYVAL bstrMigrationTablePath AS WSTRING _          ' __in BSTR bstrMigrationTablePath
   ) AS IGPMMigrationTable                              ' __retval_out IGPMMigrationTable **ppMigrationTable
   ' =====================================================================================
   METHOD CreateMigrationTable <11> ( _                 ' VTable offset = 68
   ) AS IGPMMigrationTable                              ' __retval_out **ppMigrationTable IGPMMigrationTable
   ' =====================================================================================
   METHOD InitializeReporting <12> ( _                  ' VTable offset = 72
     BYVAL bstrAdmPath AS WSTRING _                     ' __in BSTR bstrAdmPath
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IGPM2 Methods
   ' =====================================================================================
   METHOD GetBackupDirEx <13> ( _                       ' VTable offset = 76
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   , BYVAL backupDirType AS LONG _                      ' __in GPMBackupType backupDirType
   ) AS IGPMBackupDirEx                                 ' __retval_out IGPMBackupDirEx **ppIGPMBackupDirEx
   ' =====================================================================================
   METHOD InitializeReportingEx <14> ( _                ' VTable offset = 80
     BYVAL bstrAdmPath AS WSTRING _                     ' __in BSTR bstrAdmPath
   , BYVAL reportingOptions AS LONG _                   ' __in LONG reportingOptions
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPM2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStarterGPO
' IID = {DFC3F61B-8880-4490-9337-D29C7BA8C2F0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStarterGPO_INTERFACE_DEFINED)
    %IGPMStarterGPO_INTERFACE_DEFINED = 1

INTERFACE IGPMStarterGPO $IID_IGPMStarterGPO

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DisplayName <1> ( _                     ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Description <2> ( _                     ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Author <3> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Product <4> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <5> ( _                    ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY GET ID <6> ( _                              ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ModifiedTime <7> ( _                    ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY GET Type <8> ( _                            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out GPMStarterGPOType *pVal
   ' =====================================================================================
   PROPERTY GET ComputerVersion <9> ( _                 ' VTable offset = 68
   ) AS WORD                                            ' __retval_out USHORT *pVal
   ' =====================================================================================
   PROPERTY GET UserVersion <10> ( _                    ' VTable offset = 72
   ) AS WORD                                            ' __retval_out USHORT *pVal
   ' =====================================================================================
   PROPERTY GET StarterGPOVersion <11> ( _              ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD Delete <12> ( _                               ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <13> ( _                                 ' VTable offset = 84
     BYVAL bstrSaveFile AS WSTRING _                    ' __in BSTR bstrSaveFile
   , BYVAL bOverwrite AS INTEGER _                      ' __in VARIANT_BOOL bOverwrite
   , BYVAL bSaveAsSystem AS INTEGER _                   ' __in VARIANT_BOOL bSaveAsSystem
   , OPTIONAL BYREF bstrLanguage AS VARIANT _           ' __opt_in VARIANT *bstrLanguage
   , OPTIONAL BYREF bstrAuthor AS VARIANT _             ' __opt_in VARIANT *bstrAuthor
   , OPTIONAL BYREF bstrProduct AS VARIANT _            ' __opt_in VARIANT *bstrProduct
   , OPTIONAL BYREF bstrUniqueID AS VARIANT _           ' __opt_in VARIANT *bstrUniqueID
   , OPTIONAL BYREF bstrVersion AS VARIANT _            ' __opt_in VARIANT *bstrVersion
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_iout VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD Backup <14> ( _                               ' VTable offset = 88
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   , BYVAL bstrComment AS WSTRING _                     ' __in BSTR bstrComment
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_iout VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD CopyTo <15> ( _                               ' VTable offset = 92
     OPTIONAL BYREF pvarNewDisplayName AS VARIANT _     ' __opt_in VARIANT *pvarNewDisplayName
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_in VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReport <16> ( _                       ' VTable offset = 96
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType gpmReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_in VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <17> ( _                 ' VTable offset = 100
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType gpmReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GetSecurityInfo <18> ( _                      ' VTable offset = 104
   ) AS IGPMSecurityInfo                                ' __retval_out IGPMSecurityInfo **ppSecurityInfo
   ' =====================================================================================
   METHOD SetSecurityInfo <19> ( _                      ' VTable offset = 108
     BYVAL pSecurityInfo AS IGPMSecurityInfo _          ' __in IGPMSecurityInfo *pSecurityInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStarterGPO_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMStarterGPOCollection
' IID = {2E522729-2219-44AD-933A-64DFD650C423}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGPMStarterGPOCollection_INTERFACE_DEFINED)
    %IGPMStarterGPOCollection_INTERFACE_DEFINED = 1

INTERFACE IGPMStarterGPOCollection $IID_IGPMStarterGPOCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppIGPMTemplates
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMStarterGPOCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMDomain2
' IID = {7CA6BB8B-F1EB-490A-938D-3C4E51C768E6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IGPMDomain
' ########################################################################################

#IF NOT %DEF(%IGPMDomain2_INTERFACE_DEFINED)
    %IGPMDomain2_INTERFACE_DEFINED = 1

INTERFACE IGPMDomain2 $IID_IGPMDomain2

   INHERIT IDispatch

   ' =====================================================================================
   ' IGPMDomain Methods
   ' =====================================================================================
   PROPERTY GET DomainController <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Domain <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD CreateGPO <4> ( _                             ' VTable offset = 36
   ) AS IGPMGPO                                         ' __retval_out IGPMGPO **ppNewGPO
   ' =====================================================================================
   METHOD GetGPO <5> ( _                                ' VTable offset = 40
     BYVAL bstrGuid AS WSTRING _                        ' __in BSTR bstrGuid
   ) AS IGPMGPO                                         ' __retval_out IGPMGPO **ppGPO
   ' =====================================================================================
   METHOD SearchGPOs <6> ( _                            ' VTable offset = 44
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMGPOCollection                               ' __retval_out IGPMGPOCollection **ppIGPMGPOCollection
   ' =====================================================================================
   METHOD RestoreGPO <7> ( _                            ' VTable offset = 48
     BYVAL pIGPMBackup AS IGPMBackup _                  ' __in IGPMBackup *pIGPMBackup
   , BYVAL lDCFlags AS LONG _                           ' __in long lDCFlags
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GetSOM <8> ( _                                ' VTable offset = 52
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IGPMSOM                                         ' __retval_out IGPMSOM **ppSOM
   ' =====================================================================================
   METHOD SearchSOMs <9> ( _                            ' VTable offset = 56
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMSOMCollection                               ' __retval_out IGPMSOMCollection **ppIGPMSOMCollection
   ' =====================================================================================
   METHOD GetWMIFilter <10> ( _                         ' VTable offset = 60
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IGPMWMIFilter                                   ' __retval_out IGPMWMIFilter **ppWMIFilter
   ' =====================================================================================
   METHOD SearchWMIFilters <11> ( _                     ' VTable offset = 64
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMWMIFilterCollection                         ' __retval_out IGPMWMIFilterCollection **ppIGPMWMIFilterCollection
   ' =====================================================================================

   ' =====================================================================================
   ' IGPMDomain2 Methods
   ' =====================================================================================
   METHOD CreateStarterGPO <12> ( _                     ' VTable offset = 68
   ) AS IGPMStarterGPO                                  ' __retval_out IGPMStarterGPO **ppnewTemplate
   ' =====================================================================================
   METHOD CreateGPOFromStarterGPO <13> ( _              ' VTable offset = 72
     BYVAL pGPOTemplate AS IGPMStarterGPO _             ' __in IGPMStarterGPO *pGPOTemplate
   ) AS IGPMGPO                                         ' __retval_out IGPMGPO **ppNewGPO
   ' =====================================================================================
   METHOD GetStarterGPO <14> ( _                        ' VTable offset = 76
     BYVAL bstrGuid AS WSTRING _                        ' __in BSTR bstrGuid
   ) AS IGPMStarterGPO                                  ' __retval_out IGPMStarterGPO **ppTemplate
   ' =====================================================================================
   METHOD SearchStarterGPOs <15> ( _                    ' VTable offset = 80
     BYVAL pIGPMSearchCriteria AS IGPMSearchCriteria _  ' __in IGPMSearchCriteria *pIGPMSearchCriteria
   ) AS IGPMStarterGPOCollection                        ' __retval_out IGPMStarterGPOCollection **ppIGPMTemplateCollection
   ' =====================================================================================
   METHOD LoadStarterGPO <16> ( _                       ' VTable offset = 84
     BYVAL bstrLoadFile AS WSTRING _                    ' __in BSTR bstrLoadFile
   , BYVAL bOverwrite AS INTEGER _                      ' __in VARIANT_BOOL bOverwrite
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_iout VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD RestoreStarterGPO <17> ( _                    ' VTable offset = 88
     BYVAL pIGPMTmplBackup AS IGPMStarterGPOBackup _    ' __in IGPMStarterGPOBackup *pIGPMTmplBackup
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __opt_in VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __opt_iout VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMDomain2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMConstants2
' IID = {05AE21B0-AC09-4032-A26F-9E7DA786DC19}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IGPMConstants
' ########################################################################################

#IF NOT %DEF(%IGPMConstants2_INTERFACE_DEFINED)
    %IGPMConstants2_INTERFACE_DEFINED = 1

INTERFACE IGPMConstants2 $IID_IGPMConstants2

   INHERIT IDispatch

   ' =====================================================================================
   ' IGPMConstants Methods
   ' =====================================================================================
   PROPERTY GET permGPOApply <1> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPORead <2> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOEdit <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOEditSecurityAndDelete <4> ( _    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permGPOCustom <5> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterEdit <6> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterFullControl <7> ( _        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permWMIFilterCustom <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMLink <9> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMLogging <10> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMPlanning <11> ( _                ' VTable offset = 68
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMGPOCreate <12> ( _               ' VTable offset = 72
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMWMICreate <13> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permSOMWMIFullControl <14> ( _          ' VTable offset = 80
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOPermissions <15> ( _   ' VTable offset = 84
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOEffectivePermissions <16> ( _ ' VTable offset = 88
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPODisplayName <17> ( _   ' VTable offset = 92
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOWMIFilter <18> ( _     ' VTable offset = 96
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOID <19> ( _            ' VTable offset = 100
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOComputerExtensions <20> ( _ ' VTable offset = 104
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPOUserExtensions <21> ( _ ' VTable offset = 108
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertySOMLinks <22> ( _         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyGPODomain <23> ( _        ' VTable offset = 116
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyBackupMostRecent <24> ( _ ' VTable offset = 120
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpEquals <25> ( _                 ' VTable offset = 124
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpContains <26> ( _               ' VTable offset = 128
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpNotContains <27> ( _            ' VTable offset = 132
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET SearchOpNotEquals <28> ( _              ' VTable offset = 136
   ) AS LONG                                            ' __retval_out GPMSearchOperation *pVal
   ' =====================================================================================
   PROPERTY GET UsePDC <29> ( _                         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET UseAnyDC <30> ( _                       ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DoNotUseW2KDC <31> ( _                  ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET somSite <32> ( _                        ' VTable offset = 152
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET somDomain <33> ( _                      ' VTable offset = 156
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET somOU <34> ( _                          ' VTable offset = 160
   ) AS LONG                                            ' __retval_out GPMSOMType *pVal
   ' =====================================================================================
   PROPERTY GET SecurityFlags <35> ( _                  ' VTable offset = 164
     BYVAL vbOwner AS INTEGER _                         ' __in VARIANT_BOOL vbOwner
   , BYVAL vbGroup AS INTEGER _                         ' __in VARIANT_BOOL vbGroup
   , BYVAL vbDACL AS INTEGER _                          ' __in VARIANT_BOOL vbDACL
   , BYVAL vbSACL AS INTEGER _                          ' __in VARIANT_BOOL vbSACL
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DoNotValidateDC <36> ( _                ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ReportHTML <37> ( _                     ' VTable offset = 172
   ) AS LONG                                            ' __retval_out GPMReportType *pVal
   ' =====================================================================================
   PROPERTY GET ReportXML <38> ( _                      ' VTable offset = 176
   ) AS LONG                                            ' __retval_out GPMReportType *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModeUnknown <39> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModePlanning <40> ( _               ' VTable offset = 184
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET RSOPModeLogging <41> ( _                ' VTable offset = 188
   ) AS LONG                                            ' __retval_out GPMRSOPMode *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUser <42> ( _                  ' VTable offset = 192
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeComputer <43> ( _              ' VTable offset = 196
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeLocalGroup <44> ( _            ' VTable offset = 200
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeGlobalGroup <45> ( _           ' VTable offset = 204
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUniversalGroup <46> ( _        ' VTable offset = 208
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUNCPath <47> ( _               ' VTable offset = 212
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET EntryTypeUnknown <48> ( _               ' VTable offset = 216
   ) AS LONG                                            ' __retval_out GPMEntryType *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionSameAsSource <49> ( _  ' VTable offset = 220
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionNone <50> ( _          ' VTable offset = 224
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionByRelativeName <51> ( _ ' VTable offset = 228
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET DestinationOptionSet <52> ( _           ' VTable offset = 232
   ) AS LONG                                            ' __retval_out GPMDestinationOption *pVal
   ' =====================================================================================
   PROPERTY GET MigrationTableOnly <53> ( _             ' VTable offset = 236
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ProcessSecurity <54> ( _                ' VTable offset = 240
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopLoggingNoComputer <55> ( _          ' VTable offset = 244
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopLoggingNoUser <56> ( _              ' VTable offset = 248
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeSlowLink <57> ( _     ' VTable offset = 252
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningLoopbackOption <58> ( _     ' VTable offset = 256
     BYVAL vbMerge AS INTEGER _                         ' __in VARIANT_BOOL vbMerge
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeUserWQLFilterTrue <59> ( _ ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET RsopPlanningAssumeCompWQLFilterTrue <60> ( _ ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

   ' =====================================================================================
   ' IGPMConstants2 Methods
   ' =====================================================================================
   PROPERTY GET BackupTypeGPO <61> ( _                  ' VTable offset = 268
   ) AS LONG                                            ' __retval_out GPMBackupType *pVal
   ' =====================================================================================
   PROPERTY GET BackupTypeStarterGPO <62> ( _           ' VTable offset = 272
   ) AS LONG                                            ' __retval_out GPMBackupType *pVal
   ' =====================================================================================
   PROPERTY GET StarterGPOTypeSystem <63> ( _           ' VTable offset = 276
   ) AS LONG                                            ' __retval_out GPMStarterGPOType *pVal
   ' =====================================================================================
   PROPERTY GET StarterGPOTypeCustom <64> ( _           ' VTable offset = 280
   ) AS LONG                                            ' __retval_out GPMStarterGPOType *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyStarterGPOPermissions <65> ( _ ' VTable offset = 284
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyStarterGPOEffectivePermissions <66> ( _ ' VTable offset = 288
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyStarterGPODisplayName <67> ( _ ' VTable offset = 292
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyStarterGPOID <69> ( _     ' VTable offset = 296
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET SearchPropertyStarterGPODomain <70> ( _ ' VTable offset = 300
   ) AS LONG                                            ' __retval_out GPMSearchProperty *pVal
   ' =====================================================================================
   PROPERTY GET permStarterGPORead <71> ( _             ' VTable offset = 304
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permStarterGPOEdit <72> ( _             ' VTable offset = 308
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permStarterGPOFullControl <73> ( _      ' VTable offset = 312
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET permStarterGPOCustom <74> ( _           ' VTable offset = 316
   ) AS LONG                                            ' __retval_out GPMPermissionType *pVal
   ' =====================================================================================
   PROPERTY GET ReportLegacy <75> ( _                   ' VTable offset = 320
   ) AS LONG                                            ' __retval_out GPMReportingOptions *pVal
   ' =====================================================================================
   PROPERTY GET ReportComments <76> ( _                 ' VTable offset = 324
   ) AS LONG                                            ' __retval_out GPMReportingOptions *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMConstants2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGPMGPO2
' IID = {8A66A210-B78B-4D99-88E2-C306A817C925}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IGPMGPO
' ########################################################################################

#IF NOT %DEF(%IGPMGPO2_INTERFACE_DEFINED)
    %IGPMGPO2_INTERFACE_DEFINED = 1

INTERFACE IGPMGPO2 $IID_IGPMGPO2

   INHERIT IDispatch

   ' =====================================================================================
   ' IGPMGPO Methods
   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DisplayName <1> ( _                     ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Path <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ID <4> ( _                              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DomainName <5> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CreationTime <6> ( _                    ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY GET ModificationTime <7> ( _                ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY GET UserDSVersionNumber <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ComputerDSVersionNumber <9> ( _         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET UserSysvolVersionNumber <10> ( _        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET ComputerSysvolVersionNumber <11> ( _    ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD GetWMIFilter <12> ( _                         ' VTable offset = 72
   ) AS IGPMWMIFilter                                   ' __retval_out IGPMWMIFilter **ppIGPMWMIFilter
   ' =====================================================================================
   METHOD SetWMIFilter <13> ( _                         ' VTable offset = 76
     BYVAL pIGPMWMIFilter AS IGPMWMIFilter _            ' __in IGPMWMIFilter *pIGPMWMIFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUserEnabled <14> ( _                       ' VTable offset = 80
     BYVAL vbEnabled AS INTEGER _                       ' __in VARIANT_BOOL vbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SetComputerEnabled <15> ( _                   ' VTable offset = 84
     BYVAL vbEnabled AS INTEGER _                       ' __in VARIANT_BOOL vbEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUserEnabled <16> ( _                        ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD IsComputerEnabled <17> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnabled
   ' =====================================================================================
   METHOD GetSecurityInfo <18> ( _                      ' VTable offset = 96
   ) AS IGPMSecurityInfo                                ' __retval_out IGPMSecurityInfo **ppSecurityInfo
   ' =====================================================================================
   METHOD SetSecurityInfo <19> ( _                      ' VTable offset = 100
     BYVAL pSecurityInfo AS IGPMSecurityInfo _          ' __in IGPMSecurityInfo *pSecurityInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <20> ( _                               ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD Backup <21> ( _                               ' VTable offset = 108
     BYVAL bstrBackupDir AS WSTRING _                   ' __in BSTR bstrBackupDir
   , BYVAL bstrComment AS WSTRING _                     ' __in BSTR bstrComment
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD Import <22> ( _                               ' VTable offset = 112
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pIGPMBackup AS IGPMBackup _                  ' __in IGPMBackup *pIGPMBackup
   , OPTIONAL BYREF pvarMigrationTable AS VARIANT _     ' __in_opt VARIANT *pvarMigrationTable
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReport <23> ( _                       ' VTable offset = 116
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD GenerateReportToFile <24> ( _                 ' VTable offset = 120
     BYVAL GPMReportType AS LONG _                      ' __in GPMReportType GPMReportType
   , BYVAL bstrTargetFilePath AS WSTRING _              ' __in BSTR bstrTargetFilePath
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD CopyTo <25> ( _                               ' VTable offset = 124
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pIGPMDomain AS IGPMDomain _                  ' __in IGPMDomain *pIGPMDomain
   , OPTIONAL BYREF pvarNewDisplayName AS VARIANT _     ' __in_opt VARIANT *pvarNewDisplayName
   , OPTIONAL BYREF pvarMigrationTable AS VARIANT _     ' __in_opt VARIANT *pvarMigrationTable
   , OPTIONAL BYREF pvarGPMProgress AS VARIANT _        ' __in_opt  VARIANT *pvarGPMProgress
   , OPTIONAL BYREF pvarGPMCancel AS VARIANT _          ' __out_opt VARIANT *pvarGPMCancel
   ) AS IGPMResult                                      ' __retval_out IGPMResult **ppIGPMResult
   ' =====================================================================================
   METHOD SetSecurityDescriptor <26> ( _                ' VTable offset = 128
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pSD AS IDispatch _                           ' __in IDispatch *pSD
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSecurityDescriptor <27> ( _                ' VTable offset = 132
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IDispatch                                       ' __retval_out IDispatch **ppSD
   ' =====================================================================================
   METHOD IsACLConsistent <28> ( _                      ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbConsistent
   ' =====================================================================================
   METHOD MakeACLConsistent <29> ( _                    ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IGPMGPO2 Methods
   ' =====================================================================================
   PROPERTY GET Description <30> ( _                    ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Description <30> ( _                    ' VTable offset = 148
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPMGPO2_INTERFACE_DEFINED__ */
