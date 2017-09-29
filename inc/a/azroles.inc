' ########################################################################################
' Microsoft Windows
' File: azroles.inc
' Library name: AZROLESLib
' Version: 1.0, Locale ID = 0
' Contents: azroles 1.0 Type Library
' Library GUID: {11A8B8EE-BF30-409A-8EF7-3A143EF70332}
' Path: C:\Windows\system32\azroles.dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AZROLES_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {B2BCFF59-A757-4B0B-A1BC-EA69981DA69E}
$PROGID_AzAuthorizationStore1 = "AzRoles.AzAuthorizationStore.1"
' CLSID = {5C2DC96F-8D51-434B-B33C-379BCCAE77C3}
$PROGID_AzBizRuleContext1 = "AzRoles.AzBizRuleContext.1"
' CLSID = {483AFB5D-70DF-4E16-ABDC-A1DE4D015A3E}
$PROGID_AzPrincipalLocator1 = "AzRoles.AzPrincipalLocator.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {B2BCFF59-A757-4B0B-A1BC-EA69981DA69E}
$PROGID_AzAuthorizationStore = "AzRoles.AzAuthorizationStore"
' CLSID = {5C2DC96F-8D51-434B-B33C-379BCCAE77C3}
$PROGID_AzBizRuleContext = "AzRoles.AzBizRuleContext"
' CLSID = {483AFB5D-70DF-4E16-ABDC-A1DE4D015A3E}
$PROGID_AzPrincipalLocator = "AzRoles.AzPrincipalLocator"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AzAuthorizationStore = GUID$("{B2BCFF59-A757-4B0B-A1BC-EA69981DA69E}")
$CLSID_AzBizRuleContext     = GUID$("{5C2DC96F-8D51-434B-B33C-379BCCAE77C3}")
$CLSID_AzPrincipalLocator   = GUID$("{483AFB5D-70DF-4E16-ABDC-A1DE4D015A3E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAzApplication         = GUID$("{987BC7C7-B813-4D27-BEDE-6BA5AE867E95}")
$IID_IAzApplication2        = GUID$("{086A68AF-A249-437C-B18D-D4D86D6A9660}")
$IID_IAzApplication3        = GUID$("{181C845E-7196-4A7D-AC2E-020C0BB7A303}")
$IID_IAzApplicationGroup    = GUID$("{F1B744CD-58A6-4E06-9FBF-36F6D779E21E}")
$IID_IAzApplicationGroup2   = GUID$("{3F0613FC-B71A-464E-A11D-5B881A56CEFA}")
$IID_IAzApplicationGroups   = GUID$("{4CE66AD5-9F3C-469D-A911-B99887A7E685}")
$IID_IAzApplications        = GUID$("{929B11A9-95C5-4A84-A29A-20AD42C2F16C}")
$IID_IAzAuthorizationStore  = GUID$("{EDBD9CA9-9B82-4F6A-9E8B-98301E450F14}")
$IID_IAzAuthorizationStore2 = GUID$("{B11E5584-D577-4273-B6C5-0973E0F8E80D}")
$IID_IAzAuthorizationStore3 = GUID$("{ABC08425-0C86-4FA0-9BE3-7189956C926E}")
$IID_IAzBizRuleContext      = GUID$("{E192F17D-D59F-455E-A152-940316CD77B2}")
$IID_IAzBizRuleInterfaces   = GUID$("{E94128C7-E9DA-44CC-B0BD-53036F3AAB3D}")
$IID_IAzBizRuleParameters   = GUID$("{FC17685F-E25D-4DCD-BAE1-276EC9533CB5}")
$IID_IAzClientContext       = GUID$("{EFF1F00B-488A-466D-AFD9-A401C5F9EEF5}")
$IID_IAzClientContext2      = GUID$("{2B0C92B8-208A-488A-8F81-E4EDB22111CD}")
$IID_IAzClientContext3      = GUID$("{11894FDE-1DEB-4B4B-8907-6D1CDA1F5D4F}")
$IID_IAzNameResolver        = GUID$("{504D0F15-73E2-43DF-A870-A64F40714F53}")
$IID_IAzObjectPicker        = GUID$("{63130A48-699A-42D8-BF01-C62AC3FB79F9}")
$IID_IAzOperation           = GUID$("{5E56B24F-EA01-4D61-BE44-C49B5E4EAF74}")
$IID_IAzOperation2          = GUID$("{1F5EA01F-44A2-4184-9C48-A75B4DCC8CCC}")
$IID_IAzOperations          = GUID$("{90EF9C07-9706-49D9-AF80-0438A5F3EC35}")
$IID_IAzPrincipalLocator    = GUID$("{E5C3507D-AD6A-4992-9C7F-74AB480B44CC}")
$IID_IAzRole                = GUID$("{859E0D8D-62D7-41D8-A034-C0CD5D43FDFA}")
$IID_IAzRoleAssignment      = GUID$("{55647D31-0D5A-4FA3-B4AC-2B5F9AD5AB76}")
$IID_IAzRoleAssignments     = GUID$("{9C80B900-FCEB-4D73-A0F4-C83B0BBF2481}")
$IID_IAzRoleDefinition      = GUID$("{D97FCEA1-2599-44F1-9FC3-58E9FBE09466}")
$IID_IAzRoleDefinitions     = GUID$("{881F25A5-D755-4550-957A-D503A3B34001}")
$IID_IAzRoles               = GUID$("{95E0F119-13B4-4DAE-B65F-2F7D60D822E4}")
$IID_IAzScope               = GUID$("{00E52487-E08D-4514-B62E-877D5645F5AB}")
$IID_IAzScope2              = GUID$("{EE9FE8C9-C9F3-40E2-AA12-D1D8599727FD}")
$IID_IAzScopes              = GUID$("{78E14853-9F5E-406D-9B91-6BDBA6973510}")
$IID_IAzTask                = GUID$("{CB94E592-2E0E-4A6C-A336-B89A6DC1E388}")
$IID_IAzTask2               = GUID$("{03A9A5EE-48C8-4832-9025-AAD503C46526}")
$IID_IAzTasks               = GUID$("{B338CCAB-4C85-4388-8C0A-C58592BAD398}")

' ========================================================================================
' AZ_PROP_CONSTANTS enum
' ========================================================================================

%AZ_PROP_NAME                                           = 1
%AZ_PROP_DESCRIPTION                                    = 2
%AZ_PROP_WRITABLE                                       = 3
%AZ_PROP_APPLICATION_DATA                               = 4
%AZ_PROP_CHILD_CREATE                                   = 5
%AZ_MAX_APPLICATION_NAME_LENGTH                         = 512
%AZ_MAX_OPERATION_NAME_LENGTH                           = 64
%AZ_MAX_TASK_NAME_LENGTH                                = 64
%AZ_MAX_SCOPE_NAME_LENGTH                               = 65536
%AZ_MAX_GROUP_NAME_LENGTH                               = 64
%AZ_MAX_ROLE_NAME_LENGTH                                = 64
%AZ_MAX_NAME_LENGTH                                     = 65536
%AZ_MAX_DESCRIPTION_LENGTH                              = 1024
%AZ_MAX_APPLICATION_DATA_LENGTH                         = 4096
%AZ_SUBMIT_FLAG_ABORT                                   = &H1
%AZ_SUBMIT_FLAG_FLUSH                                   = &H2
%AZ_MAX_POLICY_URL_LENGTH                               = 65536
%AZ_AZSTORE_FLAG_CREATE                                 = &H1
%AZ_AZSTORE_FLAG_MANAGE_STORE_ONLY                      = &H2
%AZ_AZSTORE_FLAG_BATCH_UPDATE                           = &H4
%AZ_AZSTORE_FLAG_AUDIT_IS_CRITICAL                      = &H8
%AZ_AZSTORE_FORCE_APPLICATION_CLOSE                     = &H10
%AZ_AZSTORE_NT6_FUNCTION_LEVEL                          = &H20
%AZ_AZSTORE_FLAG_MANAGE_ONLY_PASSIVE_SUBMIT             = &H8000
%AZ_PROP_AZSTORE_DOMAIN_TIMEOUT                         = 100
%AZ_AZSTORE_DEFAULT_DOMAIN_TIMEOUT                      = 15 * 1000
%AZ_PROP_AZSTORE_SCRIPT_ENGINE_TIMEOUT                  = 101
%AZ_AZSTORE_MIN_DOMAIN_TIMEOUT                          = 500
%AZ_AZSTORE_MIN_SCRIPT_ENGINE_TIMEOUT                   = 5 * 1000
%AZ_AZSTORE_DEFAULT_SCRIPT_ENGINE_TIMEOUT               = 45 * 1000
%AZ_PROP_AZSTORE_MAX_SCRIPT_ENGINES                     = 102
%AZ_AZSTORE_DEFAULT_MAX_SCRIPT_ENGINES                  = 120
%AZ_PROP_AZSTORE_MAJOR_VERSION                          = 103
%AZ_PROP_AZSTORE_MINOR_VERSION                          = 104
%AZ_PROP_AZSTORE_TARGET_MACHINE                         = 105
%AZ_PROP_AZTORE_IS_ADAM_INSTANCE                        = 106
%AZ_PROP_OPERATION_ID                                   = 200
%AZ_PROP_TASK_OPERATIONS                                = 300
%AZ_PROP_TASK_BIZRULE                                   = 301
%AZ_PROP_TASK_BIZRULE_LANGUAGE                          = 302
%AZ_PROP_TASK_TASKS                                     = 303
%AZ_PROP_TASK_BIZRULE_IMPORTED_PATH                     = 304
%AZ_PROP_TASK_IS_ROLE_DEFINITION                        = 305
%AZ_MAX_TASK_BIZRULE_LENGTH                             = 65536
%AZ_MAX_TASK_BIZRULE_LANGUAGE_LENGTH                    = 64
%AZ_MAX_TASK_BIZRULE_IMPORTED_PATH_LENGTH               = 512
%AZ_MAX_BIZRULE_STRING                                  = 65536
%AZ_PROP_GROUP_TYPE                                     = 400
%AZ_GROUPTYPE_LDAP_QUERY                                = 1
%AZ_GROUPTYPE_BASIC                                     = 2
%AZ_GROUPTYPE_BIZRULE                                   = 3
%AZ_PROP_GROUP_APP_MEMBERS                              = 401
%AZ_PROP_GROUP_APP_NON_MEMBERS                          = 402
%AZ_PROP_GROUP_LDAP_QUERY                               = 403
%AZ_MAX_GROUP_LDAP_QUERY_LENGTH                         = 4096
%AZ_PROP_GROUP_MEMBERS                                  = 404
%AZ_PROP_GROUP_NON_MEMBERS                              = 405
%AZ_PROP_GROUP_MEMBERS_NAME                             = 406
%AZ_PROP_GROUP_NON_MEMBERS_NAME                         = 407
%AZ_PROP_GROUP_BIZRULE                                  = 408
%AZ_PROP_GROUP_BIZRULE_LANGUAGE                         = 409
%AZ_PROP_GROUP_BIZRULE_IMPORTED_PATH                    = 410
%AZ_MAX_GROUP_BIZRULE_LENGTH                            = 65536
%AZ_MAX_GROUP_BIZRULE_LANGUAGE_LENGTH                   = 64
%AZ_MAX_GROUP_BIZRULE_IMPORTED_PATH_LENGTH              = 512
%AZ_PROP_ROLE_APP_MEMBERS                               = 500
%AZ_PROP_ROLE_MEMBERS                                   = 501
%AZ_PROP_ROLE_OPERATIONS                                = 502
%AZ_PROP_ROLE_TASKS                                     = 504
%AZ_PROP_ROLE_MEMBERS_NAME                              = 505
%AZ_PROP_SCOPE_BIZRULES_WRITABLE                        = 600
%AZ_PROP_SCOPE_CAN_BE_DELEGATED                         = 601
%AZ_PROP_CLIENT_CONTEXT_USER_DN                         = 700
%AZ_PROP_CLIENT_CONTEXT_USER_SAM_COMPAT                 = 701
%AZ_PROP_CLIENT_CONTEXT_USER_DISPLAY                    = 702
%AZ_PROP_CLIENT_CONTEXT_USER_GUID                       = 703
%AZ_PROP_CLIENT_CONTEXT_USER_CANONICAL                  = 704
%AZ_PROP_CLIENT_CONTEXT_USER_UPN                        = 705
%AZ_PROP_CLIENT_CONTEXT_USER_DNS_SAM_COMPAT             = 707
%AZ_PROP_CLIENT_CONTEXT_ROLE_FOR_ACCESS_CHECK           = 708
%AZ_PROP_CLIENT_CONTEXT_LDAP_QUERY_DN                   = 709
%AZ_PROP_APPLICATION_AUTHZ_INTERFACE_CLSID              = 800
%AZ_PROP_APPLICATION_VERSION                            = 801
%AZ_MAX_APPLICATION_VERSION_LENGTH                      = 512
%AZ_PROP_APPLICATION_NAME                               = 802
%AZ_PROP_APPLICATION_BIZRULE_ENABLED                    = 803
%AZ_PROP_APPLY_STORE_SACL                               = 900
%AZ_PROP_GENERATE_AUDITS                                = 901
%AZ_PROP_POLICY_ADMINS                                  = 902
%AZ_PROP_POLICY_READERS                                 = 903
%AZ_PROP_DELEGATED_POLICY_USERS                         = 904
%AZ_PROP_POLICY_ADMINS_NAME                             = 905
%AZ_PROP_POLICY_READERS_NAME                            = 906
%AZ_PROP_DELEGATED_POLICY_USERS_NAME                    = 907
%AZ_CLIENT_CONTEXT_SKIP_GROUP                           = 1
%AZ_CLIENT_CONTEXT_SKIP_LDAP_QUERY                      = 1
%AZ_CLIENT_CONTEXT_GET_GROUP_RECURSIVE                  = 2
%AZ_CLIENT_CONTEXT_GET_GROUPS_STORE_LEVEL_ONLY          = 2

' ########################################################################################
' Interface name = IAzAuthorizationStore
' IID = {EDBD9CA9-9B82-4F6A-9E8B-98301E450F14}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzAuthorizationStore_INTERFACE_DEFINED)
    %IAzAuthorizationStore_INTERFACE_DEFINED = 1

INTERFACE IAzAuthorizationStore $IID_IAzAuthorizationStore

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Description <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743808> ( _            ' VTable offset = 32
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743810> ( _        ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743810> ( _        ' VTable offset = 40
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DomainTimeout <1610743812> ( _          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET DomainTimeout <1610743812> ( _          ' VTable offset = 48
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 56
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxScriptEngines <1610743816> ( _       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET MaxScriptEngines <1610743816> ( _       ' VTable offset = 64
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743820> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743821> ( _                  ' VTable offset = 80
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743822> ( _                  ' VTable offset = 84
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743823> ( _              ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743824> ( _           ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610743831> ( _                   ' VTable offset = 120
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrPolicyURL AS WSTRING _                   ' __in BSTR bstrPolicyURL
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateCache <1610743832> ( _                  ' VTable offset = 124
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Applications <1610743834> ( _           ' VTable offset = 132
   ) AS IAzApplications                                 ' __retval_out IAzApplications **ppAppCollection
   ' =====================================================================================
   METHOD OpenApplication <1610743835> ( _              ' VTable offset = 136
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD CreateApplication <1610743836> ( _            ' VTable offset = 140
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD DeleteApplication <1610743837> ( _            ' VTable offset = 144
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743838> ( _      ' VTable offset = 148
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743839> ( _       ' VTable offset = 152
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743840> ( _         ' VTable offset = 156
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743841> ( _       ' VTable offset = 160
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743842> ( _                       ' VTable offset = 164
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743843> ( _   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743844> ( _       ' VTable offset = 172
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743845> ( _    ' VTable offset = 176
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TargetMachine <1610743846> ( _          ' VTable offset = 180
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrTargetMachine
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 184
   ) AS LONG                                            ' __retval_out BOOL *pbApplyStoreSacl
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 188
     BYVAL bApplyStoreSacl AS LONG _                    ' __in BOOL bApplyStoreSacl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743849> ( _ ' VTable offset = 192
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743850> ( _      ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743851> ( _   ' VTable offset = 200
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743852> ( _ ' VTable offset = 204
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743853> ( _          ' VTable offset = 208
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743854> ( _       ' VTable offset = 212
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743855> ( _ ' VTable offset = 216
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743856> ( _   ' VTable offset = 220
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743857> ( _ ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseApplication <1610743858> ( _             ' VTable offset = 228
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , BYVAL lFlag AS LONG _                              ' __in LONG lFlag
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzAuthorizationStore_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplications
' IID = {929B11A9-95C5-4A84-A29A-20AD42C2F16C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzApplications_INTERFACE_DEFINED)
    %IAzApplications_INTERFACE_DEFINED = 1

INTERFACE IAzApplications $IID_IAzApplications

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplications_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplication
' IID = {987BC7C7-B813-4D27-BEDE-6BA5AE867E95}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzApplication_INTERFACE_DEFINED)
    %IAzApplication_INTERFACE_DEFINED = 1

INTERFACE IAzApplication $IID_IAzApplication

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <1610743816> ( _                ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET Version <1610743816> ( _                ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 80
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743823> ( _                  ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743824> ( _                  ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scopes <1610743831> ( _                 ' VTable offset = 120
   ) AS IAzScopes                                       ' __retval_out IAzScopes **ppScopeCollection
   ' =====================================================================================
   METHOD OpenScope <1610743832> ( _                    ' VTable offset = 124
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD CreateScope <1610743833> ( _                  ' VTable offset = 128
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD DeleteScope <1610743834> ( _                  ' VTable offset = 132
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743835> ( _             ' VTable offset = 136
   ) AS IAzOperations                                   ' __retval_out IAzOperations **ppOperationCollection
   ' =====================================================================================
   METHOD OpenOperation <1610743836> ( _                ' VTable offset = 140
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD CreateOperation <1610743837> ( _              ' VTable offset = 144
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD DeleteOperation <1610743838> ( _              ' VTable offset = 148
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tasks <1610743839> ( _                  ' VTable offset = 152
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   METHOD OpenTask <1610743840> ( _                     ' VTable offset = 156
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD CreateTask <1610743841> ( _                   ' VTable offset = 160
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD DeleteTask <1610743842> ( _                   ' VTable offset = 164
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743843> ( _      ' VTable offset = 168
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743844> ( _         ' VTable offset = 172
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743845> ( _       ' VTable offset = 176
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743846> ( _       ' VTable offset = 180
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Roles <1610743847> ( _                  ' VTable offset = 184
   ) AS IAzRoles                                        ' __retval_out IAzRoles **ppRoleCollection
   ' =====================================================================================
   METHOD OpenRole <1610743848> ( _                     ' VTable offset = 188
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD CreateRole <1610743849> ( _                   ' VTable offset = 192
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD DeleteRole <1610743850> ( _                   ' VTable offset = 196
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromToken <1610743851> ( _ ' VTable offset = 200
     BYVAL ullTokenHandle AS QUAD _                     ' __in ULONGLONG ullTokenHandle
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   METHOD AddPropertyItem <1610743852> ( _              ' VTable offset = 204
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743853> ( _           ' VTable offset = 208
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743854> ( _                       ' VTable offset = 212
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromName <1610743855> ( _ ' VTable offset = 216
     BYVAL ClientName AS WSTRING _                      ' __in BSTR ClientName
   , OPTIONAL BYVAL DomainName AS WSTRING _             ' __opt_in BSTR DomainName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743856> ( _   ' VTable offset = 220
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743857> ( _       ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743858> ( _    ' VTable offset = 228
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromStringSid <1610743859> ( _ ' VTable offset = 232
     BYVAL SidString AS WSTRING _                       ' __in BSTR SidString
   , BYVAL lOptions AS LONG _                           ' __in LONG lOptions
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743860> ( _ ' VTable offset = 236
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743861> ( _      ' VTable offset = 240
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743862> ( _   ' VTable offset = 244
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743863> ( _ ' VTable offset = 248
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743864> ( _          ' VTable offset = 252
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743865> ( _       ' VTable offset = 256
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743866> ( _ ' VTable offset = 260
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743867> ( _   ' VTable offset = 264
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743868> ( _ ' VTable offset = 268
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzScopes
' IID = {78E14853-9F5E-406D-9B91-6BDBA6973510}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzScopes_INTERFACE_DEFINED)
    %IAzScopes_INTERFACE_DEFINED = 1

INTERFACE IAzScopes $IID_IAzScopes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzScopes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzScope
' IID = {00E52487-E08D-4514-B62E-877D5645F5AB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzScope_INTERFACE_DEFINED)
    %IAzScope_INTERFACE_DEFINED = 1

INTERFACE IAzScope $IID_IAzScope

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743814> ( _               ' VTable offset = 52
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743815> ( _                  ' VTable offset = 56
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743816> ( _                  ' VTable offset = 60
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743817> ( _              ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743818> ( _           ' VTable offset = 68
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743819> ( _   ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743820> ( _          ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743821> ( _       ' VTable offset = 80
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743822> ( _    ' VTable offset = 84
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743823> ( _              ' VTable offset = 88
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743824> ( _           ' VTable offset = 92
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743825> ( _      ' VTable offset = 96
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743826> ( _         ' VTable offset = 100
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743828> ( _       ' VTable offset = 108
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Roles <1610743829> ( _                  ' VTable offset = 112
   ) AS IAzRoles                                        ' __retval_out IAzRoles **ppRoleCollection
   ' =====================================================================================
   METHOD OpenRole <1610743830> ( _                     ' VTable offset = 116
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD CreateRole <1610743831> ( _                   ' VTable offset = 120
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD DeleteRole <1610743832> ( _                   ' VTable offset = 124
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tasks <1610743833> ( _                  ' VTable offset = 128
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   METHOD OpenTask <1610743834> ( _                     ' VTable offset = 132
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD CreateTask <1610743835> ( _                   ' VTable offset = 136
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD DeleteTask <1610743836> ( _                   ' VTable offset = 140
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743837> ( _                       ' VTable offset = 144
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanBeDelegated <1610743838> ( _         ' VTable offset = 148
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY GET BizrulesWritable <1610743839> ( _       ' VTable offset = 152
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743840> ( _ ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743841> ( _      ' VTable offset = 160
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743842> ( _   ' VTable offset = 164
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743843> ( _ ' VTable offset = 168
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743844> ( _          ' VTable offset = 172
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743845> ( _       ' VTable offset = 176
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzScope_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplicationGroups
' IID = {4CE66AD5-9F3C-469D-A911-B99887A7E685}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzApplicationGroups_INTERFACE_DEFINED)
    %IAzApplicationGroups_INTERFACE_DEFINED = 1

INTERFACE IAzApplicationGroups $IID_IAzApplicationGroups

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplicationGroups_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplicationGroup
' IID = {F1B744CD-58A6-4E06-9FBF-36F6D779E21E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzApplicationGroup_INTERFACE_DEFINED)
    %IAzApplicationGroup_INTERFACE_DEFINED = 1

INTERFACE IAzApplicationGroup $IID_IAzApplicationGroup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610743810> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET Type <1610743810> ( _                   ' VTable offset = 40
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LdapQuery <1610743812> ( _              ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET LdapQuery <1610743812> ( _              ' VTable offset = 48
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppMembers <1610743814> ( _             ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET AppNonMembers <1610743815> ( _          ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Members <1610743816> ( _                ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET NonMembers <1610743817> ( _             ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Description <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppMember <1610743820> ( _                 ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppMember <1610743821> ( _              ' VTable offset = 80
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppNonMember <1610743822> ( _              ' VTable offset = 84
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppNonMember <1610743823> ( _           ' VTable offset = 88
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMember <1610743824> ( _                    ' VTable offset = 92
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMember <1610743825> ( _                 ' VTable offset = 96
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNonMember <1610743826> ( _                 ' VTable offset = 100
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNonMember <1610743827> ( _              ' VTable offset = 104
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743829> ( _                  ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743830> ( _                  ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743831> ( _              ' VTable offset = 120
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743832> ( _           ' VTable offset = 124
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMemberName <1610743834> ( _                ' VTable offset = 132
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberName <1610743835> ( _             ' VTable offset = 136
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNonMemberName <1610743836> ( _             ' VTable offset = 140
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNonMemberName <1610743837> ( _          ' VTable offset = 144
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MembersName <1610743838> ( _            ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET NonMembersName <1610743839> ( _         ' VTable offset = 152
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplicationGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRoles
' IID = {95E0F119-13B4-4DAE-B65F-2F7D60D822E4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzRoles_INTERFACE_DEFINED)
    %IAzRoles_INTERFACE_DEFINED = 1

INTERFACE IAzRoles $IID_IAzRoles

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRoles_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRole
' IID = {859E0D8D-62D7-41D8-A034-C0CD5D43FDFA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzRole_INTERFACE_DEFINED)
    %IAzRole_INTERFACE_DEFINED = 1

INTERFACE IAzRole $IID_IAzRole

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppMember <1610743814> ( _                 ' VTable offset = 52
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppMember <1610743815> ( _              ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTask <1610743816> ( _                      ' VTable offset = 60
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteTask <1610743817> ( _                   ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddOperation <1610743818> ( _                 ' VTable offset = 68
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOperation <1610743819> ( _              ' VTable offset = 72
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMember <1610743820> ( _                    ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMember <1610743821> ( _                 ' VTable offset = 80
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743823> ( _                  ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743824> ( _                  ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppMembers <1610743825> ( _             ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Members <1610743826> ( _                ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Operations <1610743827> ( _             ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Tasks <1610743828> ( _                  ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD AddPropertyItem <1610743829> ( _              ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743830> ( _           ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743831> ( _                       ' VTable offset = 120
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMemberName <1610743832> ( _                ' VTable offset = 124
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberName <1610743833> ( _             ' VTable offset = 128
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MembersName <1610743834> ( _            ' VTable offset = 132
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRole_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzTasks
' IID = {B338CCAB-4C85-4388-8C0A-C58592BAD398}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzTasks_INTERFACE_DEFINED)
    %IAzTasks_INTERFACE_DEFINED = 1

INTERFACE IAzTasks $IID_IAzTasks

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzTasks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzTask
' IID = {CB94E592-2E0E-4A6C-A336-B89A6DC1E388}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzTask_INTERFACE_DEFINED)
    %IAzTask_INTERFACE_DEFINED = 1

INTERFACE IAzTask $IID_IAzTask

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRule <1610743814> ( _                ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRule <1610743814> ( _                ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleLanguage <1610743816> ( _        ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleLanguage <1610743816> ( _        ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 68
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 72
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRoleDefinition <1610743820> ( _       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY SET IsRoleDefinition <1610743820> ( _       ' VTable offset = 80
     BYVAL fProp AS LONG _                              ' __in BOOL fProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743822> ( _             ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Tasks <1610743823> ( _                  ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD AddOperation <1610743824> ( _                 ' VTable offset = 92
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOperation <1610743825> ( _              ' VTable offset = 96
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTask <1610743826> ( _                      ' VTable offset = 100
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteTask <1610743827> ( _                   ' VTable offset = 104
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743829> ( _                  ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743830> ( _                  ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743831> ( _              ' VTable offset = 120
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743832> ( _           ' VTable offset = 124
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzTask_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzOperations
' IID = {90EF9C07-9706-49D9-AF80-0438A5F3EC35}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzOperations_INTERFACE_DEFINED)
    %IAzOperations_INTERFACE_DEFINED = 1

INTERFACE IAzOperations $IID_IAzOperations

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzOperations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzOperation
' IID = {5E56B24F-EA01-4D61-BE44-C49B5E4EAF74}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzOperation_INTERFACE_DEFINED)
    %IAzOperation_INTERFACE_DEFINED = 1

INTERFACE IAzOperation $IID_IAzOperation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OperationID <1610743814> ( _            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET OperationID <1610743814> ( _            ' VTable offset = 56
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743816> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743817> ( _                  ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743818> ( _                  ' VTable offset = 68
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743819> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzClientContext
' IID = {EFF1F00B-488A-466D-AFD9-A401C5F9EEF5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzClientContext_INTERFACE_DEFINED)
    %IAzClientContext_INTERFACE_DEFINED = 1

INTERFACE IAzClientContext $IID_IAzClientContext

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AccessCheck <1610743808> ( _                  ' VTable offset = 28
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   , BYVAL varScopeNames AS VARIANT _                   ' __in VARIANT varScopeNames
   , BYVAL varOperations AS VARIANT _                   ' __in VARIANT varOperations
   , OPTIONAL BYVAL varParameterNames AS VARIANT _      ' __opt_in VARIANT varParameterNames
   , OPTIONAL BYVAL varParameterValues AS VARIANT _     ' __opt_in VARIANT varParameterValues
   , OPTIONAL BYVAL varInterfaceNames AS VARIANT _      ' __opt_in VARIANT varInterfaceNames
   , OPTIONAL BYVAL varInterfaceFlags AS VARIANT _      ' __opt_in VARIANT varInterfaceFlags
   , OPTIONAL BYVAL varInterfaces AS VARIANT _          ' __opt_in VARIANT varInterfaces
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResults
   ' =====================================================================================
   METHOD GetBusinessRuleString <1610743809> ( _        ' VTable offset = 32
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrBusinessRuleString
   ' =====================================================================================
   PROPERTY GET UserDn <1610743810> ( _                 ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserSamCompat <1610743811> ( _          ' VTable offset = 40
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDisplay <1610743812> ( _            ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserGuid <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserCanonical <1610743814> ( _          ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserUpn <1610743815> ( _                ' VTable offset = 56
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDnsSamCompat <1610743816> ( _       ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   METHOD GetProperty <1610743817> ( _                  ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD GetRoles <1610743818> ( _                     ' VTable offset = 68
     OPTIONAL BYVAL bstrScopeName AS WSTRING _          ' __opt_in BSTR bstrScopeName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRoleNames
   ' =====================================================================================
   PROPERTY GET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 72
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzClientContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzAuthorizationStore2
' IID = {B11E5584-D577-4273-B6C5-0973E0F8E80D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzAuthorizationStore
' ########################################################################################

#IF NOT %DEF(%IAzAuthorizationStore2_INTERFACE_DEFINED)
    %IAzAuthorizationStore2_INTERFACE_DEFINED = 1

INTERFACE IAzAuthorizationStore2 $IID_IAzAuthorizationStore2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzAuthorizationStore Methods
   ' =====================================================================================
   PROPERTY GET Description <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743808> ( _            ' VTable offset = 32
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743810> ( _        ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743810> ( _        ' VTable offset = 40
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DomainTimeout <1610743812> ( _          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET DomainTimeout <1610743812> ( _          ' VTable offset = 48
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 56
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxScriptEngines <1610743816> ( _       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET MaxScriptEngines <1610743816> ( _       ' VTable offset = 64
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743820> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743821> ( _                  ' VTable offset = 80
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743822> ( _                  ' VTable offset = 84
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743823> ( _              ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743824> ( _           ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610743831> ( _                   ' VTable offset = 120
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrPolicyURL AS WSTRING _                   ' __in BSTR bstrPolicyURL
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateCache <1610743832> ( _                  ' VTable offset = 124
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Applications <1610743834> ( _           ' VTable offset = 132
   ) AS IAzApplications                                 ' __retval_out IAzApplications **ppAppCollection
   ' =====================================================================================
   METHOD OpenApplication <1610743835> ( _              ' VTable offset = 136
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD CreateApplication <1610743836> ( _            ' VTable offset = 140
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD DeleteApplication <1610743837> ( _            ' VTable offset = 144
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743838> ( _      ' VTable offset = 148
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743839> ( _       ' VTable offset = 152
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743840> ( _         ' VTable offset = 156
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743841> ( _       ' VTable offset = 160
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743842> ( _                       ' VTable offset = 164
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743843> ( _   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743844> ( _       ' VTable offset = 172
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743845> ( _    ' VTable offset = 176
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TargetMachine <1610743846> ( _          ' VTable offset = 180
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrTargetMachine
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 184
   ) AS LONG                                            ' __retval_out BOOL *pbApplyStoreSacl
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 188
     BYVAL bApplyStoreSacl AS LONG _                    ' __in BOOL bApplyStoreSacl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743849> ( _ ' VTable offset = 192
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743850> ( _      ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743851> ( _   ' VTable offset = 200
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743852> ( _ ' VTable offset = 204
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743853> ( _          ' VTable offset = 208
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743854> ( _       ' VTable offset = 212
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743855> ( _ ' VTable offset = 216
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743856> ( _   ' VTable offset = 220
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743857> ( _ ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseApplication <1610743858> ( _             ' VTable offset = 228
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , BYVAL lFlag AS LONG _                              ' __in LONG lFlag
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzAuthorizationStore2 Methods
   ' =====================================================================================
   METHOD OpenApplication2 <1610809344> ( _             ' VTable offset = 232
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication2                                 ' __retval_out IAzApplication2 **ppApplication
   ' =====================================================================================
   METHOD CreateApplication2 <1610809345> ( _           ' VTable offset = 236
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication2                                 ' __retval_out IAzApplication2 **ppApplication
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzAuthorizationStore2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplication2
' IID = {086A68AF-A249-437C-B18D-D4D86D6A9660}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzApplication
' ########################################################################################

#IF NOT %DEF(%IAzApplication2_INTERFACE_DEFINED)
    %IAzApplication2_INTERFACE_DEFINED = 1

INTERFACE IAzApplication2 $IID_IAzApplication2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzApplication Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <1610743816> ( _                ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET Version <1610743816> ( _                ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 80
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743823> ( _                  ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743824> ( _                  ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scopes <1610743831> ( _                 ' VTable offset = 120
   ) AS IAzScopes                                       ' __retval_out IAzScopes **ppScopeCollection
   ' =====================================================================================
   METHOD OpenScope <1610743832> ( _                    ' VTable offset = 124
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD CreateScope <1610743833> ( _                  ' VTable offset = 128
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD DeleteScope <1610743834> ( _                  ' VTable offset = 132
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743835> ( _             ' VTable offset = 136
   ) AS IAzOperations                                   ' __retval_out IAzOperations **ppOperationCollection
   ' =====================================================================================
   METHOD OpenOperation <1610743836> ( _                ' VTable offset = 140
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD CreateOperation <1610743837> ( _              ' VTable offset = 144
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD DeleteOperation <1610743838> ( _              ' VTable offset = 148
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tasks <1610743839> ( _                  ' VTable offset = 152
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   METHOD OpenTask <1610743840> ( _                     ' VTable offset = 156
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD CreateTask <1610743841> ( _                   ' VTable offset = 160
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD DeleteTask <1610743842> ( _                   ' VTable offset = 164
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743843> ( _      ' VTable offset = 168
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743844> ( _         ' VTable offset = 172
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743845> ( _       ' VTable offset = 176
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743846> ( _       ' VTable offset = 180
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Roles <1610743847> ( _                  ' VTable offset = 184
   ) AS IAzRoles                                        ' __retval_out IAzRoles **ppRoleCollection
   ' =====================================================================================
   METHOD OpenRole <1610743848> ( _                     ' VTable offset = 188
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD CreateRole <1610743849> ( _                   ' VTable offset = 192
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD DeleteRole <1610743850> ( _                   ' VTable offset = 196
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromToken <1610743851> ( _ ' VTable offset = 200
     BYVAL ullTokenHandle AS QUAD _                     ' __in ULONGLONG ullTokenHandle
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   METHOD AddPropertyItem <1610743852> ( _              ' VTable offset = 204
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743853> ( _           ' VTable offset = 208
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743854> ( _                       ' VTable offset = 212
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromName <1610743855> ( _ ' VTable offset = 216
     BYVAL ClientName AS WSTRING _                      ' __in BSTR ClientName
   , OPTIONAL BYVAL DomainName AS WSTRING _             ' __opt_in BSTR DomainName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743856> ( _   ' VTable offset = 220
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743857> ( _       ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743858> ( _    ' VTable offset = 228
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromStringSid <1610743859> ( _ ' VTable offset = 232
     BYVAL SidString AS WSTRING _                       ' __in BSTR SidString
   , BYVAL lOptions AS LONG _                           ' __in LONG lOptions
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743860> ( _ ' VTable offset = 236
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743861> ( _      ' VTable offset = 240
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743862> ( _   ' VTable offset = 244
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743863> ( _ ' VTable offset = 248
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743864> ( _          ' VTable offset = 252
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743865> ( _       ' VTable offset = 256
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743866> ( _ ' VTable offset = 260
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743867> ( _   ' VTable offset = 264
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743868> ( _ ' VTable offset = 268
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzApplication2 Methods
   ' =====================================================================================
   METHOD InitializeClientContextFromToken2 <1610809344> ( _ ' VTable offset = 272
     BYVAL ulTokenHandleLowPart AS DWORD _              ' __in ULONG ulTokenHandleLowPart
   , BYVAL ulTokenHandleHighPart AS DWORD _             ' __in ULONG ulTokenHandleHighPart
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext2                               ' __retval_out IAzClientContext2 **ppClientContext
   ' =====================================================================================
   METHOD InitializeClientContext2 <1610809345> ( _     ' VTable offset = 276
     BYVAL IdentifyingString AS WSTRING _               ' __in BSTR IdentifyingString
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext2                               ' __retval_out IAzClientContext2 **ppClientContext
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplication2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzClientContext2
' IID = {2B0C92B8-208A-488A-8F81-E4EDB22111CD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzClientContext
' ########################################################################################

#IF NOT %DEF(%IAzClientContext2_INTERFACE_DEFINED)
    %IAzClientContext2_INTERFACE_DEFINED = 1

INTERFACE IAzClientContext2 $IID_IAzClientContext2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzClientContext Methods
   ' =====================================================================================
   METHOD AccessCheck <1610743808> ( _                  ' VTable offset = 28
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   , BYVAL varScopeNames AS VARIANT _                   ' __in VARIANT varScopeNames
   , BYVAL varOperations AS VARIANT _                   ' __in VARIANT varOperations
   , OPTIONAL BYVAL varParameterNames AS VARIANT _      ' __opt_in VARIANT varParameterNames
   , OPTIONAL BYVAL varParameterValues AS VARIANT _     ' __opt_in VARIANT varParameterValues
   , OPTIONAL BYVAL varInterfaceNames AS VARIANT _      ' __opt_in VARIANT varInterfaceNames
   , OPTIONAL BYVAL varInterfaceFlags AS VARIANT _      ' __opt_in VARIANT varInterfaceFlags
   , OPTIONAL BYVAL varInterfaces AS VARIANT _          ' __opt_in VARIANT varInterfaces
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResults
   ' =====================================================================================
   METHOD GetBusinessRuleString <1610743809> ( _        ' VTable offset = 32
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrBusinessRuleString
   ' =====================================================================================
   PROPERTY GET UserDn <1610743810> ( _                 ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserSamCompat <1610743811> ( _          ' VTable offset = 40
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDisplay <1610743812> ( _            ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserGuid <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserCanonical <1610743814> ( _          ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserUpn <1610743815> ( _                ' VTable offset = 56
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDnsSamCompat <1610743816> ( _       ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   METHOD GetProperty <1610743817> ( _                  ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD GetRoles <1610743818> ( _                     ' VTable offset = 68
     OPTIONAL BYVAL bstrScopeName AS WSTRING _          ' __opt_in BSTR bstrScopeName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRoleNames
   ' =====================================================================================
   PROPERTY GET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 72
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzClientContext2 Methods
   ' =====================================================================================
   METHOD GetAssignedScopesPage <1610809344> ( _        ' VTable offset = 80
     BYVAL lOptions AS LONG _                           ' __in LONG lOptions
   , BYVAL PageSize AS LONG _                           ' __in LONG PageSize
   , BYREF pvarCursor AS VARIANT _                      ' __in_out VARIANT *pvarCursor
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarScopeNames
   ' =====================================================================================
   METHOD AddRoles <1610809345> ( _                     ' VTable offset = 84
     BYVAL varRoles AS VARIANT _                        ' __in VARIANT varRoles
   , BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   )                                                    ' void
   ' =====================================================================================
   METHOD AddApplicationGroups <1610809346> ( _         ' VTable offset = 88
     BYVAL varApplicationGroups AS VARIANT _            ' __in VARIANT varApplicationGroups
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStringSids <1610809347> ( _                ' VTable offset = 92
     BYVAL varStringSids AS VARIANT _                   ' __in VARIANT varStringSids
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LDAPQueryDN <1610809348> ( _            ' VTable offset = 96
     BYVAL bstrLDAPQueryDN AS WSTRING _                 ' __in BSTR bstrLDAPQueryDN
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LDAPQueryDN <1610809348> ( _            ' VTable offset = 100
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrLDAPQueryDN
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzClientContext2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzAuthorizationStore3
' IID = {ABC08425-0C86-4FA0-9BE3-7189956C926E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzAuthorizationStore2
' ########################################################################################

#IF NOT %DEF(%IAzAuthorizationStore3_INTERFACE_DEFINED)
    %IAzAuthorizationStore3_INTERFACE_DEFINED = 1

INTERFACE IAzAuthorizationStore3 $IID_IAzAuthorizationStore3

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzAuthorizationStore Methods
   ' =====================================================================================
   PROPERTY GET Description <1610743808> ( _            ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743808> ( _            ' VTable offset = 32
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743810> ( _        ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743810> ( _        ' VTable offset = 40
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DomainTimeout <1610743812> ( _          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET DomainTimeout <1610743812> ( _          ' VTable offset = 48
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET ScriptEngineTimeout <1610743814> ( _    ' VTable offset = 56
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxScriptEngines <1610743816> ( _       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET MaxScriptEngines <1610743816> ( _       ' VTable offset = 64
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743820> ( _               ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743821> ( _                  ' VTable offset = 80
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743822> ( _                  ' VTable offset = 84
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743823> ( _              ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743824> ( _           ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Initialize <1610743831> ( _                   ' VTable offset = 120
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL bstrPolicyURL AS WSTRING _                   ' __in BSTR bstrPolicyURL
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateCache <1610743832> ( _                  ' VTable offset = 124
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Applications <1610743834> ( _           ' VTable offset = 132
   ) AS IAzApplications                                 ' __retval_out IAzApplications **ppAppCollection
   ' =====================================================================================
   METHOD OpenApplication <1610743835> ( _              ' VTable offset = 136
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD CreateApplication <1610743836> ( _            ' VTable offset = 140
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication                                  ' __retval_out IAzApplication **ppApplication
   ' =====================================================================================
   METHOD DeleteApplication <1610743837> ( _            ' VTable offset = 144
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743838> ( _      ' VTable offset = 148
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743839> ( _       ' VTable offset = 152
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743840> ( _         ' VTable offset = 156
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743841> ( _       ' VTable offset = 160
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743842> ( _                       ' VTable offset = 164
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743843> ( _   ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743844> ( _       ' VTable offset = 172
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743845> ( _    ' VTable offset = 176
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TargetMachine <1610743846> ( _          ' VTable offset = 180
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrTargetMachine
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 184
   ) AS LONG                                            ' __retval_out BOOL *pbApplyStoreSacl
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743847> ( _         ' VTable offset = 188
     BYVAL bApplyStoreSacl AS LONG _                    ' __in BOOL bApplyStoreSacl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743849> ( _ ' VTable offset = 192
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743850> ( _      ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743851> ( _   ' VTable offset = 200
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743852> ( _ ' VTable offset = 204
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743853> ( _          ' VTable offset = 208
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743854> ( _       ' VTable offset = 212
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743855> ( _ ' VTable offset = 216
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743856> ( _   ' VTable offset = 220
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743857> ( _ ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseApplication <1610743858> ( _             ' VTable offset = 228
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , BYVAL lFlag AS LONG _                              ' __in LONG lFlag
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzAuthorizationStore2 Methods
   ' =====================================================================================
   METHOD OpenApplication2 <1610809344> ( _             ' VTable offset = 232
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication2                                 ' __retval_out IAzApplication2 **ppApplication
   ' =====================================================================================
   METHOD CreateApplication2 <1610809345> ( _           ' VTable offset = 236
     BYVAL bstrApplicationName AS WSTRING _             ' __in BSTR bstrApplicationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplication2                                 ' __retval_out IAzApplication2 **ppApplication
   ' =====================================================================================

   ' =====================================================================================
   ' IAzAuthorizationStore3 Methods
   ' =====================================================================================
   METHOD IsUpdateNeeded <1610874880> ( _               ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsUpdateNeeded
   ' =====================================================================================
   METHOD BizruleGroupSupported <1610874881> ( _        ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSupported
   ' =====================================================================================
   METHOD UpgradeStoresFunctionalLevel <1610874882> ( _ ' VTable offset = 248
     BYVAL LONG _                                       ' __in LONG lFunctionalLevel
   )                                                    ' void
   ' =====================================================================================
   METHOD IsFunctionalLevelUpgradeSupported <1610874883> ( _ ' VTable offset = 252
     BYVAL lFunctionalLevel AS LONG _                   ' __in LONG lFunctionalLevel
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSupported
   ' =====================================================================================
   METHOD GetSchemaVersion <1610874884> ( _             ' VTable offset = 256
     BYREF plMajorVersion AS LONG _                     ' __out LONG *plMajorVersion
   , BYREF plMinorVersion AS LONG _                     ' __out LONG *plMinorVersion
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzAuthorizationStore3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplication3
' IID = {181C845E-7196-4A7D-AC2E-020C0BB7A303}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzApplication2
' ########################################################################################

#IF NOT %DEF(%IAzApplication3_INTERFACE_DEFINED)
    %IAzApplication3_INTERFACE_DEFINED = 1

INTERFACE IAzApplication3 $IID_IAzApplication3

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzApplication Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET AuthzInterfaceClsid <1610743814> ( _    ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <1610743816> ( _                ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET Version <1610743816> ( _                ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenerateAudits <1610743818> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET GenerateAudits <1610743818> ( _         ' VTable offset = 72
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pbProp
   ' =====================================================================================
   PROPERTY SET ApplyStoreSacl <1610743820> ( _         ' VTable offset = 80
     BYVAL bProp AS LONG _                              ' __in BOOL bProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743823> ( _                  ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743824> ( _                  ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743825> ( _   ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743826> ( _          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743828> ( _    ' VTable offset = 108
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743829> ( _              ' VTable offset = 112
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743830> ( _           ' VTable offset = 116
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scopes <1610743831> ( _                 ' VTable offset = 120
   ) AS IAzScopes                                       ' __retval_out IAzScopes **ppScopeCollection
   ' =====================================================================================
   METHOD OpenScope <1610743832> ( _                    ' VTable offset = 124
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD CreateScope <1610743833> ( _                  ' VTable offset = 128
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================
   METHOD DeleteScope <1610743834> ( _                  ' VTable offset = 132
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743835> ( _             ' VTable offset = 136
   ) AS IAzOperations                                   ' __retval_out IAzOperations **ppOperationCollection
   ' =====================================================================================
   METHOD OpenOperation <1610743836> ( _                ' VTable offset = 140
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD CreateOperation <1610743837> ( _              ' VTable offset = 144
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzOperation                                    ' __retval_out IAzOperation **ppOperation
   ' =====================================================================================
   METHOD DeleteOperation <1610743838> ( _              ' VTable offset = 148
     BYVAL bstrOperationName AS WSTRING _               ' __in BSTR bstrOperationName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tasks <1610743839> ( _                  ' VTable offset = 152
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   METHOD OpenTask <1610743840> ( _                     ' VTable offset = 156
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD CreateTask <1610743841> ( _                   ' VTable offset = 160
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD DeleteTask <1610743842> ( _                   ' VTable offset = 164
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743843> ( _      ' VTable offset = 168
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743844> ( _         ' VTable offset = 172
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743845> ( _       ' VTable offset = 176
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743846> ( _       ' VTable offset = 180
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Roles <1610743847> ( _                  ' VTable offset = 184
   ) AS IAzRoles                                        ' __retval_out IAzRoles **ppRoleCollection
   ' =====================================================================================
   METHOD OpenRole <1610743848> ( _                     ' VTable offset = 188
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD CreateRole <1610743849> ( _                   ' VTable offset = 192
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD DeleteRole <1610743850> ( _                   ' VTable offset = 196
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromToken <1610743851> ( _ ' VTable offset = 200
     BYVAL ullTokenHandle AS QUAD _                     ' __in ULONGLONG ullTokenHandle
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   METHOD AddPropertyItem <1610743852> ( _              ' VTable offset = 204
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743853> ( _           ' VTable offset = 208
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743854> ( _                       ' VTable offset = 212
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromName <1610743855> ( _ ' VTable offset = 216
     BYVAL ClientName AS WSTRING _                      ' __in BSTR ClientName
   , OPTIONAL BYVAL DomainName AS WSTRING _             ' __opt_in BSTR DomainName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsers <1610743856> ( _   ' VTable offset = 220
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUser <1610743857> ( _       ' VTable offset = 224
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUser <1610743858> ( _    ' VTable offset = 228
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeClientContextFromStringSid <1610743859> ( _ ' VTable offset = 232
     BYVAL SidString AS WSTRING _                       ' __in BSTR SidString
   , BYVAL lOptions AS LONG _                           ' __in LONG lOptions
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext                                ' __retval_out IAzClientContext **ppClientContext
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743860> ( _ ' VTable offset = 236
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743861> ( _      ' VTable offset = 240
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743862> ( _   ' VTable offset = 244
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743863> ( _ ' VTable offset = 248
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743864> ( _          ' VTable offset = 252
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743865> ( _       ' VTable offset = 256
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelegatedPolicyUsersName <1610743866> ( _ ' VTable offset = 260
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDelegatedPolicyUsers
   ' =====================================================================================
   METHOD AddDelegatedPolicyUserName <1610743867> ( _   ' VTable offset = 264
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteDelegatedPolicyUserName <1610743868> ( _ ' VTable offset = 268
     BYVAL bstrDelegatedPolicyUser AS WSTRING _         ' __in BSTR bstrDelegatedPolicyUser
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzApplication2 Methods
   ' =====================================================================================
   METHOD InitializeClientContextFromToken2 <1610809344> ( _ ' VTable offset = 272
     BYVAL ulTokenHandleLowPart AS DWORD _              ' __in ULONG ulTokenHandleLowPart
   , BYVAL ulTokenHandleHighPart AS DWORD _             ' __in ULONG ulTokenHandleHighPart
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext2                               ' __retval_out IAzClientContext2 **ppClientContext
   ' =====================================================================================
   METHOD InitializeClientContext2 <1610809345> ( _     ' VTable offset = 276
     BYVAL IdentifyingString AS WSTRING _               ' __in BSTR IdentifyingString
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzClientContext2                               ' __retval_out IAzClientContext2 **ppClientContext
   ' =====================================================================================

   ' =====================================================================================
   ' IAzApplication3 Methods
   ' =====================================================================================
   METHOD ScopeExists <1610874880> ( _                  ' VTable offset = 280
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExist
   ' =====================================================================================
   METHOD OpenScope2 <1610874881> ( _                   ' VTable offset = 284
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   ) AS IAzScope2                                       ' __retval_out IAzScope2 **ppScope2
   ' =====================================================================================
   METHOD CreateScope2 <1610874882> ( _                 ' VTable offset = 288
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   ) AS IAzScope2                                       ' __retval_out IAzScope2 **ppScope2
   ' =====================================================================================
   METHOD DeleteScope2 <1610874883> ( _                 ' VTable offset = 292
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RoleDefinitions <1610874884> ( _        ' VTable offset = 296
   ) AS IAzRoleDefinitions                              ' __retval_out IAzRoleDefinitions **ppRoleDefinitions
   ' =====================================================================================
   METHOD CreateRoleDefinition <1610874885> ( _         ' VTable offset = 300
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   ) AS IAzRoleDefinition                               ' __retval_out IAzRoleDefinition **ppRoleDefinitions
   ' =====================================================================================
   METHOD OpenRoleDefinition <1610874886> ( _           ' VTable offset = 304
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   ) AS IAzRoleDefinition                               ' __retval_out IAzRoleDefinition **ppRoleDefinitions
   ' =====================================================================================
   METHOD DeleteRoleDefinition <1610874887> ( _         ' VTable offset = 308
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RoleAssignments <1610874888> ( _        ' VTable offset = 312
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================
   METHOD CreateRoleAssignment <1610874889> ( _         ' VTable offset = 316
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   ) AS IAzRoleAssignment                               ' __retval_out IAzRoleAssignment **ppRoleAssignment
   ' =====================================================================================
   METHOD OpenRoleAssignment <1610874890> ( _           ' VTable offset = 320
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   ) AS IAzRoleAssignment                               ' __retval_out IAzRoleAssignment **ppRoleAssignment
   ' =====================================================================================
   METHOD DeleteRoleAssignment <1610874891> ( _         ' VTable offset = 324
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRulesEnabled <1610874892> ( _        ' VTable offset = 328
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET BizRulesEnabled <1610874892> ( _        ' VTable offset = 332
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplication3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzScope2
' IID = {EE9FE8C9-C9F3-40E2-AA12-D1D8599727FD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzScope
' ########################################################################################

#IF NOT %DEF(%IAzScope2_INTERFACE_DEFINED)
    %IAzScope2_INTERFACE_DEFINED = 1

INTERFACE IAzScope2 $IID_IAzScope2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzScope Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743814> ( _               ' VTable offset = 52
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743815> ( _                  ' VTable offset = 56
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743816> ( _                  ' VTable offset = 60
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743817> ( _              ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743818> ( _           ' VTable offset = 68
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PolicyAdministrators <1610743819> ( _   ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReaders <1610743820> ( _          ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministrator <1610743821> ( _       ' VTable offset = 80
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministrator <1610743822> ( _    ' VTable offset = 84
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReader <1610743823> ( _              ' VTable offset = 88
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReader <1610743824> ( _           ' VTable offset = 92
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationGroups <1610743825> ( _      ' VTable offset = 96
   ) AS IAzApplicationGroups                            ' __retval_out IAzApplicationGroups **ppGroupCollection
   ' =====================================================================================
   METHOD OpenApplicationGroup <1610743826> ( _         ' VTable offset = 100
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD CreateApplicationGroup <1610743827> ( _       ' VTable offset = 104
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzApplicationGroup                             ' __retval_out IAzApplicationGroup **ppGroup
   ' =====================================================================================
   METHOD DeleteApplicationGroup <1610743828> ( _       ' VTable offset = 108
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Roles <1610743829> ( _                  ' VTable offset = 112
   ) AS IAzRoles                                        ' __retval_out IAzRoles **ppRoleCollection
   ' =====================================================================================
   METHOD OpenRole <1610743830> ( _                     ' VTable offset = 116
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD CreateRole <1610743831> ( _                   ' VTable offset = 120
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzRole                                         ' __retval_out IAzRole **ppRole
   ' =====================================================================================
   METHOD DeleteRole <1610743832> ( _                   ' VTable offset = 124
     BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tasks <1610743833> ( _                  ' VTable offset = 128
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   METHOD OpenTask <1610743834> ( _                     ' VTable offset = 132
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD CreateTask <1610743835> ( _                   ' VTable offset = 136
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS IAzTask                                         ' __retval_out IAzTask **ppTask
   ' =====================================================================================
   METHOD DeleteTask <1610743836> ( _                   ' VTable offset = 140
     BYVAL bstrTaskName AS WSTRING _                    ' __in BSTR bstrTaskName
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743837> ( _                       ' VTable offset = 144
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanBeDelegated <1610743838> ( _         ' VTable offset = 148
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY GET BizrulesWritable <1610743839> ( _       ' VTable offset = 152
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY GET PolicyAdministratorsName <1610743840> ( _ ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarAdmins
   ' =====================================================================================
   PROPERTY GET PolicyReadersName <1610743841> ( _      ' VTable offset = 160
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarReaders
   ' =====================================================================================
   METHOD AddPolicyAdministratorName <1610743842> ( _   ' VTable offset = 164
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyAdministratorName <1610743843> ( _ ' VTable offset = 168
     BYVAL bstrAdmin AS WSTRING _                       ' __in BSTR bstrAdmin
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPolicyReaderName <1610743844> ( _          ' VTable offset = 172
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePolicyReaderName <1610743845> ( _       ' VTable offset = 176
     BYVAL bstrReader AS WSTRING _                      ' __in BSTR bstrReader
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzScope2 Methods
   ' =====================================================================================
   PROPERTY GET RoleDefinitions <1610809344> ( _        ' VTable offset = 180
   ) AS IAzRoleDefinitions                              ' __retval_out IAzRoleDefinitions **ppRoleDefinitions
   ' =====================================================================================
   METHOD CreateRoleDefinition <1610809345> ( _         ' VTable offset = 184
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   ) AS IAzRoleDefinition                               ' __retval_out IAzRoleDefinition **ppRoleDefinitions
   ' =====================================================================================
   METHOD OpenRoleDefinition <1610809346> ( _           ' VTable offset = 188
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   ) AS IAzRoleDefinition                               ' __retval_out IAzRoleDefinition **ppRoleDefinitions
   ' =====================================================================================
   METHOD DeleteRoleDefinition <1610809347> ( _         ' VTable offset = 192
     BYVAL bstrRoleDefinitionName AS WSTRING _          ' __in BSTR bstrRoleDefinitionName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RoleAssignments <1610809348> ( _        ' VTable offset = 196
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================
   METHOD CreateRoleAssignment <1610809349> ( _         ' VTable offset = 200
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   ) AS IAzRoleAssignment                               ' __retval_out IAzRoleAssignment **ppRoleAssignment
   ' =====================================================================================
   METHOD OpenRoleAssignment <1610809350> ( _           ' VTable offset = 204
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   ) AS IAzRoleAssignment                               ' __retval_out IAzRoleAssignment **ppRoleAssignment
   ' =====================================================================================
   METHOD DeleteRoleAssignment <1610809351> ( _         ' VTable offset = 208
     BYVAL bstrRoleAssignmentName AS WSTRING _          ' __in BSTR bstrRoleAssignmentName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzScope2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRoleDefinitions
' IID = {881F25A5-D755-4550-957A-D503A3B34001}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzRoleDefinitions_INTERFACE_DEFINED)
    %IAzRoleDefinitions_INTERFACE_DEFINED = 1

INTERFACE IAzRoleDefinitions $IID_IAzRoleDefinitions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRoleDefinitions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRoleDefinition
' IID = {D97FCEA1-2599-44F1-9FC3-58E9FBE09466}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzTask
' ########################################################################################

#IF NOT %DEF(%IAzRoleDefinition_INTERFACE_DEFINED)
    %IAzRoleDefinition_INTERFACE_DEFINED = 1

INTERFACE IAzRoleDefinition $IID_IAzRoleDefinition

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzTask Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRule <1610743814> ( _                ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRule <1610743814> ( _                ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleLanguage <1610743816> ( _        ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleLanguage <1610743816> ( _        ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 68
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 72
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRoleDefinition <1610743820> ( _       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY SET IsRoleDefinition <1610743820> ( _       ' VTable offset = 80
     BYVAL fProp AS LONG _                              ' __in BOOL fProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743822> ( _             ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Tasks <1610743823> ( _                  ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD AddOperation <1610743824> ( _                 ' VTable offset = 92
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOperation <1610743825> ( _              ' VTable offset = 96
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTask <1610743826> ( _                      ' VTable offset = 100
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteTask <1610743827> ( _                   ' VTable offset = 104
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743829> ( _                  ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743830> ( _                  ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743831> ( _              ' VTable offset = 120
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743832> ( _           ' VTable offset = 124
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzRoleDefinition Methods
   ' =====================================================================================
   METHOD RoleAssignments <1610809344> ( _              ' VTable offset = 132
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL bRecursive AS INTEGER _                      ' __in VARIANT_BOOL bRecursive
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================
   METHOD AddRoleDefinition <1610809345> ( _            ' VTable offset = 136
     BYVAL bstrRoleDefinition AS WSTRING _              ' __in BSTR bstrRoleDefinition
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteRoleDefinition <1610809346> ( _         ' VTable offset = 140
     BYVAL bstrRoleDefinition AS WSTRING _              ' __in BSTR bstrRoleDefinition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RoleDefinitions <1610809347> ( _        ' VTable offset = 144
   ) AS IAzRoleDefinitions                              ' __retval_out IAzRoleDefinitions **ppRoleDefinitions
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRoleDefinition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRoleAssignments
' IID = {9C80B900-FCEB-4D73-A0F4-C83B0BBF2481}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzRoleAssignments_INTERFACE_DEFINED)
    %IAzRoleAssignments_INTERFACE_DEFINED = 1

INTERFACE IAzRoleAssignments $IID_IAzRoleAssignments

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarObtPtr
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppEnumPtr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRoleAssignments_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzRoleAssignment
' IID = {55647D31-0D5A-4FA3-B4AC-2B5F9AD5AB76}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzRole
' ########################################################################################

#IF NOT %DEF(%IAzRoleAssignment_INTERFACE_DEFINED)
    %IAzRoleAssignment_INTERFACE_DEFINED = 1

INTERFACE IAzRoleAssignment $IID_IAzRoleAssignment

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzRole Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppMember <1610743814> ( _                 ' VTable offset = 52
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppMember <1610743815> ( _              ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTask <1610743816> ( _                      ' VTable offset = 60
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteTask <1610743817> ( _                   ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddOperation <1610743818> ( _                 ' VTable offset = 68
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOperation <1610743819> ( _              ' VTable offset = 72
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMember <1610743820> ( _                    ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMember <1610743821> ( _                 ' VTable offset = 80
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743822> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743823> ( _                  ' VTable offset = 88
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743824> ( _                  ' VTable offset = 92
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppMembers <1610743825> ( _             ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Members <1610743826> ( _                ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Operations <1610743827> ( _             ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Tasks <1610743828> ( _                  ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD AddPropertyItem <1610743829> ( _              ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743830> ( _           ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743831> ( _                       ' VTable offset = 120
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMemberName <1610743832> ( _                ' VTable offset = 124
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberName <1610743833> ( _             ' VTable offset = 128
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MembersName <1610743834> ( _            ' VTable offset = 132
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================

   ' =====================================================================================
   ' IAzRoleAssignment Methods
   ' =====================================================================================
   METHOD AddRoleDefinition <1610809344> ( _            ' VTable offset = 136
     BYVAL bstrRoleDefinition AS WSTRING _              ' __in BSTR bstrRoleDefinition
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteRoleDefinition <1610809345> ( _         ' VTable offset = 140
     BYVAL bstrRoleDefinition AS WSTRING _              ' __in BSTR bstrRoleDefinition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RoleDefinitions <1610809346> ( _        ' VTable offset = 144
   ) AS IAzRoleDefinitions                              ' __retval_out IAzRoleDefinitions **ppRoleDefinitions
   ' =====================================================================================
   PROPERTY GET Scope <1610809347> ( _                  ' VTable offset = 148
   ) AS IAzScope                                        ' __retval_out IAzScope **ppScope
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzRoleAssignment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzOperation2
' IID = {1F5EA01F-44A2-4184-9C48-A75B4DCC8CCC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzOperation
' ########################################################################################

#IF NOT %DEF(%IAzOperation2_INTERFACE_DEFINED)
    %IAzOperation2_INTERFACE_DEFINED = 1

INTERFACE IAzOperation2 $IID_IAzOperation2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzOperation Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OperationID <1610743814> ( _            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET OperationID <1610743814> ( _            ' VTable offset = 56
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743816> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743817> ( _                  ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743818> ( _                  ' VTable offset = 68
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743819> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzOperation2 Methods
   ' =====================================================================================
   METHOD RoleAssignments <1610809344> ( _              ' VTable offset = 76
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL bRecursive AS INTEGER _                      ' __in VARIANT_BOOL bRecursive
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzOperation2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzTask2
' IID = {03A9A5EE-48C8-4832-9025-AAD503C46526}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzTask
' ########################################################################################

#IF NOT %DEF(%IAzTask2_INTERFACE_DEFINED)
    %IAzTask2_INTERFACE_DEFINED = 1

INTERFACE IAzTask2 $IID_IAzTask2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzTask Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743810> ( _            ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationData <1610743812> ( _        ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrApplicationData
   ' =====================================================================================
   PROPERTY SET ApplicationData <1610743812> ( _        ' VTable offset = 48
     BYVAL bstrApplicationData AS WSTRING _             ' __in BSTR bstrApplicationData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRule <1610743814> ( _                ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRule <1610743814> ( _                ' VTable offset = 56
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleLanguage <1610743816> ( _        ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleLanguage <1610743816> ( _        ' VTable offset = 64
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 68
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleImportedPath <1610743818> ( _    ' VTable offset = 72
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRoleDefinition <1610743820> ( _       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   PROPERTY SET IsRoleDefinition <1610743820> ( _       ' VTable offset = 80
     BYVAL fProp AS LONG _                              ' __in BOOL fProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Operations <1610743822> ( _             ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Tasks <1610743823> ( _                  ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD AddOperation <1610743824> ( _                 ' VTable offset = 92
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOperation <1610743825> ( _              ' VTable offset = 96
     BYVAL bstrOp AS WSTRING _                          ' __in BSTR bstrOp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddTask <1610743826> ( _                      ' VTable offset = 100
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteTask <1610743827> ( _                   ' VTable offset = 104
     BYVAL bstrTask AS WSTRING _                        ' __in BSTR bstrTask
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743829> ( _                  ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743830> ( _                  ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743831> ( _              ' VTable offset = 120
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743832> ( _           ' VTable offset = 124
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzTask2 Methods
   ' =====================================================================================
   METHOD RoleAssignments <1610809344> ( _              ' VTable offset = 132
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL bRecursive AS INTEGER _                      ' __in VARIANT_BOOL bRecursive
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzTask2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzApplicationGroup2
' IID = {3F0613FC-B71A-464E-A11D-5B881A56CEFA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzApplicationGroup
' ########################################################################################

#IF NOT %DEF(%IAzApplicationGroup2_INTERFACE_DEFINED)
    %IAzApplicationGroup2_INTERFACE_DEFINED = 1

INTERFACE IAzApplicationGroup2 $IID_IAzApplicationGroup2

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzApplicationGroup Methods
   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <1610743808> ( _                   ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610743810> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *plProp
   ' =====================================================================================
   PROPERTY SET Type <1610743810> ( _                   ' VTable offset = 40
     BYVAL lProp AS LONG _                              ' __in LONG lProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LdapQuery <1610743812> ( _              ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET LdapQuery <1610743812> ( _              ' VTable offset = 48
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppMembers <1610743814> ( _             ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET AppNonMembers <1610743815> ( _          ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Members <1610743816> ( _                ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET NonMembers <1610743817> ( _             ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET Description <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppMember <1610743820> ( _                 ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppMember <1610743821> ( _              ' VTable offset = 80
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAppNonMember <1610743822> ( _              ' VTable offset = 84
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAppNonMember <1610743823> ( _           ' VTable offset = 88
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMember <1610743824> ( _                    ' VTable offset = 92
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMember <1610743825> ( _                 ' VTable offset = 96
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNonMember <1610743826> ( _                 ' VTable offset = 100
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNonMember <1610743827> ( _              ' VTable offset = 104
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Writable <1610743828> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *pfProp
   ' =====================================================================================
   METHOD GetProperty <1610743829> ( _                  ' VTable offset = 112
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD SetProperty <1610743830> ( _                  ' VTable offset = 116
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyItem <1610743831> ( _              ' VTable offset = 120
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeletePropertyItem <1610743832> ( _           ' VTable offset = 124
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , BYVAL varProp AS VARIANT _                         ' __in VARIANT varProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYVAL lFlags AS LONG _                    ' __opt_in LONG lFlags
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddMemberName <1610743834> ( _                ' VTable offset = 132
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteMemberName <1610743835> ( _             ' VTable offset = 136
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNonMemberName <1610743836> ( _             ' VTable offset = 140
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNonMemberName <1610743837> ( _          ' VTable offset = 144
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MembersName <1610743838> ( _            ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   PROPERTY GET NonMembersName <1610743839> ( _         ' VTable offset = 152
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================

   ' =====================================================================================
   ' IAzApplicationGroup2 Methods
   ' =====================================================================================
   PROPERTY GET BizRule <1610809344> ( _                ' VTable offset = 156
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRule <1610809344> ( _                ' VTable offset = 160
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleLanguage <1610809346> ( _        ' VTable offset = 164
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleLanguage <1610809346> ( _        ' VTable offset = 168
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BizRuleImportedPath <1610809348> ( _    ' VTable offset = 172
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET BizRuleImportedPath <1610809348> ( _    ' VTable offset = 176
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================
   METHOD RoleAssignments <1610809350> ( _              ' VTable offset = 180
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL bRecursive AS INTEGER _                      ' __in VARIANT_BOOL bRecursive
   ) AS IAzRoleAssignments                              ' __retval_out IAzRoleAssignments **ppRoleAssignments
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzApplicationGroup2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzClientContext3
' IID = {11894FDE-1DEB-4B4B-8907-6D1CDA1F5D4F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAzClientContext2
' ########################################################################################

#IF NOT %DEF(%IAzClientContext3_INTERFACE_DEFINED)
    %IAzClientContext3_INTERFACE_DEFINED = 1

INTERFACE IAzClientContext3 $IID_IAzClientContext3

   INHERIT IDispatch

   ' =====================================================================================
   ' IAzClientContext Methods
   ' =====================================================================================
   METHOD AccessCheck <1610743808> ( _                  ' VTable offset = 28
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   , BYVAL varScopeNames AS VARIANT _                   ' __in VARIANT varScopeNames
   , BYVAL varOperations AS VARIANT _                   ' __in VARIANT varOperations
   , OPTIONAL BYVAL varParameterNames AS VARIANT _      ' __opt_in VARIANT varParameterNames
   , OPTIONAL BYVAL varParameterValues AS VARIANT _     ' __opt_in VARIANT varParameterValues
   , OPTIONAL BYVAL varInterfaceNames AS VARIANT _      ' __opt_in VARIANT varInterfaceNames
   , OPTIONAL BYVAL varInterfaceFlags AS VARIANT _      ' __opt_in VARIANT varInterfaceFlags
   , OPTIONAL BYVAL varInterfaces AS VARIANT _          ' __opt_in VARIANT varInterfaces
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarResults
   ' =====================================================================================
   METHOD GetBusinessRuleString <1610743809> ( _        ' VTable offset = 32
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrBusinessRuleString
   ' =====================================================================================
   PROPERTY GET UserDn <1610743810> ( _                 ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserSamCompat <1610743811> ( _          ' VTable offset = 40
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDisplay <1610743812> ( _            ' VTable offset = 44
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserGuid <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserCanonical <1610743814> ( _          ' VTable offset = 52
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserUpn <1610743815> ( _                ' VTable offset = 56
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY GET UserDnsSamCompat <1610743816> ( _       ' VTable offset = 60
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   METHOD GetProperty <1610743817> ( _                  ' VTable offset = 64
     BYVAL lPropId AS LONG _                            ' __in LONG lPropId
   , OPTIONAL BYVAL varReserved AS VARIANT _            ' __opt_in VARIANT varReserved
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProp
   ' =====================================================================================
   METHOD GetRoles <1610743818> ( _                     ' VTable offset = 68
     OPTIONAL BYVAL bstrScopeName AS WSTRING _          ' __opt_in BSTR bstrScopeName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRoleNames
   ' =====================================================================================
   PROPERTY GET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 72
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrProp
   ' =====================================================================================
   PROPERTY SET RoleForAccessCheck <1610743819> ( _     ' VTable offset = 76
     BYVAL bstrProp AS WSTRING _                        ' __in BSTR bstrProp
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAzClientContext2 Methods
   ' =====================================================================================
   METHOD GetAssignedScopesPage <1610809344> ( _        ' VTable offset = 80
     BYVAL lOptions AS LONG _                           ' __in LONG lOptions
   , BYVAL PageSize AS LONG _                           ' __in LONG PageSize
   , BYREF pvarCursor AS VARIANT _                      ' __in_out VARIANT *pvarCursor
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarScopeNames
   ' =====================================================================================
   METHOD AddRoles <1610809345> ( _                     ' VTable offset = 84
     BYVAL varRoles AS VARIANT _                        ' __in VARIANT varRoles
   , BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   )                                                    ' void
   ' =====================================================================================
   METHOD AddApplicationGroups <1610809346> ( _         ' VTable offset = 88
     BYVAL varApplicationGroups AS VARIANT _            ' __in VARIANT varApplicationGroups
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStringSids <1610809347> ( _                ' VTable offset = 92
     BYVAL varStringSids AS VARIANT _                   ' __in VARIANT varStringSids
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LDAPQueryDN <1610809348> ( _            ' VTable offset = 96
     BYVAL bstrLDAPQueryDN AS WSTRING _                 ' __in BSTR bstrLDAPQueryDN
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LDAPQueryDN <1610809348> ( _            ' VTable offset = 100
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrLDAPQueryDN
   ' =====================================================================================

   ' =====================================================================================
   ' IAzClientContext3 Methods
   ' =====================================================================================
   METHOD AccessCheck2 <1610874880> ( _                 ' VTable offset = 104
     BYVAL bstrObjectName AS WSTRING _                  ' __in BSTR bstrObjectName
   , BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL lOperation AS LONG _                         ' __in long lOperation
   ) AS DWORD                                           ' __retval_out unsigned long *plResult
   ' =====================================================================================
   METHOD IsInRoleAssignment <1610874881> ( _           ' VTable offset = 108
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL bstrRoleName AS WSTRING _                    ' __in BSTR bstrRoleName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsInRole
   ' =====================================================================================
   METHOD GetOperations <1610874882> ( _                ' VTable offset = 112
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   ) AS IAzOperations                                   ' __retval_out IAzOperations **ppOperationCollection
   ' =====================================================================================
   METHOD GetTasks <1610874883> ( _                     ' VTable offset = 116
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   ) AS IAzTasks                                        ' __retval_out IAzTasks **ppTaskCollection
   ' =====================================================================================
   PROPERTY GET BizRuleParameters <1610874884> ( _      ' VTable offset = 120
   ) AS IAzBizRuleParameters                            ' __retval_out IAzBizRuleParameters **ppBizRuleParam
   ' =====================================================================================
   PROPERTY GET BizRuleInterfaces <1610874885> ( _      ' VTable offset = 124
   ) AS IAzBizRuleInterfaces                            ' __retval_out IAzBizRuleInterfaces **ppBizRuleInterfaces
   ' =====================================================================================
   METHOD GetGroups <1610874886> ( _                    ' VTable offset = 128
     BYVAL bstrScopeName AS WSTRING _                   ' __in BSTR bstrScopeName
   , BYVAL ulOptions AS DWORD _                         ' __in ULONG ulOptions
   ) AS VARIANT                                         ' __retval_out VARIANT *pGroupArray
   ' =====================================================================================
   PROPERTY GET Sids <1610874887> ( _                   ' VTable offset = 132
   ) AS VARIANT                                         ' __retval_out VARIANT *pStringSidArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzClientContext3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzBizRuleParameters
' IID = {FC17685F-E25D-4DCD-BAE1-276EC9533CB5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzBizRuleParameters_INTERFACE_DEFINED)
    %IAzBizRuleParameters_INTERFACE_DEFINED = 1

INTERFACE IAzBizRuleParameters $IID_IAzBizRuleParameters

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddParameter <1610743808> ( _                 ' VTable offset = 28
     BYVAL bstrParameterName AS WSTRING _               ' __in BSTR bstrParameterName
   , BYVAL varParameterValue AS VARIANT _               ' __in VARIANT varParameterValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AddParameters <1610743809> ( _                ' VTable offset = 32
     BYVAL varParameterNames AS VARIANT _               ' __in VARIANT varParameterNames
   , BYVAL varParameterValues AS VARIANT _              ' __in VARIANT varParameterValues
   )                                                    ' void
   ' =====================================================================================
   METHOD GetParameterValue <1610743810> ( _            ' VTable offset = 36
     BYVAL bstrParameterName AS WSTRING _               ' __in BSTR bstrParameterName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarParameterValue
   ' =====================================================================================
   METHOD Remove <1610743811> ( _                       ' VTable offset = 40
     BYVAL varParameterName AS WSTRING _                ' __in BSTR varParameterName
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <1610743812> ( _                    ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743813> ( _                  ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out unsigned long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzBizRuleParameters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzBizRuleInterfaces
' IID = {E94128C7-E9DA-44CC-B0BD-53036F3AAB3D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzBizRuleInterfaces_INTERFACE_DEFINED)
    %IAzBizRuleInterfaces_INTERFACE_DEFINED = 1

INTERFACE IAzBizRuleInterfaces $IID_IAzBizRuleInterfaces

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddInterface <1610743808> ( _                 ' VTable offset = 28
     BYVAL bstrInterfaceName AS WSTRING _               ' __in BSTR bstrInterfaceName
   , BYVAL lInterfaceFlag AS LONG _                     ' __in LONG lInterfaceFlag
   , BYVAL varInterface AS VARIANT _                    ' __in VARIANT varInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD AddInterfaces <1610743809> ( _                ' VTable offset = 32
     BYVAL varInterfaceNames AS VARIANT _               ' __in VARIANT varInterfaceNames
   , BYVAL varInterfaceFlags AS VARIANT _               ' __in VARIANT varInterfaceFlags
   , BYVAL varInterfaces AS VARIANT _                   ' __in VARIANT varInterfaces
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterfaceValue <1610743810> ( _            ' VTable offset = 36
     BYVAL bstrInterfaceName AS WSTRING _               ' __in BSTR bstrInterfaceName
   , BYREF lInterfaceFlag AS LONG _                     ' __out LONG *lInterfaceFlag
   , BYREF varInterface AS VARIANT _                    ' __out VARIANT *varInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <1610743811> ( _                       ' VTable offset = 40
     BYVAL bstrInterfaceName AS WSTRING _               ' __in BSTR bstrInterfaceName
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <1610743812> ( _                    ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743813> ( _                  ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out unsigned long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzBizRuleInterfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzBizRuleContext
' IID = {E192F17D-D59F-455E-A152-940316CD77B2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzBizRuleContext_INTERFACE_DEFINED)
    %IAzBizRuleContext_INTERFACE_DEFINED = 1

INTERFACE IAzBizRuleContext $IID_IAzBizRuleContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET BusinessRuleResult <1610743808> ( _     ' VTable offset = 28
     BYVAL bResult AS LONG _                            ' __in BOOL bResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BusinessRuleString <1610743809> ( _     ' VTable offset = 32
     BYVAL bstrBusinessRuleString AS WSTRING _          ' __in BSTR bstrBusinessRuleString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BusinessRuleString <1610743809> ( _     ' VTable offset = 36
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrBusinessRuleString
   ' =====================================================================================
   METHOD GetParameter <1610743811> ( _                 ' VTable offset = 40
     BYVAL bstrParameterName AS WSTRING _               ' __in BSTR bstrParameterName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarParameterValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzBizRuleContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzPrincipalLocator
' IID = {E5C3507D-AD6A-4992-9C7F-74AB480B44CC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzPrincipalLocator_INTERFACE_DEFINED)
    %IAzPrincipalLocator_INTERFACE_DEFINED = 1

INTERFACE IAzPrincipalLocator $IID_IAzPrincipalLocator

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NameResolver <1610743808> ( _           ' VTable offset = 28
   ) AS IAzNameResolver                                 ' __retval_out IAzNameResolver **ppNameResolver
   ' =====================================================================================
   PROPERTY GET ObjectPicker <1610743809> ( _           ' VTable offset = 32
   ) AS IAzObjectPicker                                 ' __retval_out IAzObjectPicker **ppObjectPicker
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzPrincipalLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzNameResolver
' IID = {504D0F15-73E2-43DF-A870-A64F40714F53}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzNameResolver_INTERFACE_DEFINED)
    %IAzNameResolver_INTERFACE_DEFINED = 1

INTERFACE IAzNameResolver $IID_IAzNameResolver

   INHERIT IDispatch

   ' =====================================================================================
   METHOD NameFromSid <1610743808> ( _                  ' VTable offset = 28
     BYVAL bstrSid AS WSTRING _                         ' __in BSTR bstrSid
   , BYREF pSidType AS LONG _                           ' __out long *pSidType
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   METHOD NamesFromSids <1610743809> ( _                ' VTable offset = 32
     BYVAL vSids AS VARIANT _                           ' __in VARIANT vSids
   , BYREF pvSidTypes AS VARIANT _                      ' __out VARIANT *pvSidTypes
   ) AS VARIANT                                         ' __retval_out VARIANT *pvNames
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzNameResolver_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAzObjectPicker
' IID = {63130A48-699A-42D8-BF01-C62AC3FB79F9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAzObjectPicker_INTERFACE_DEFINED)
    %IAzObjectPicker_INTERFACE_DEFINED = 1

INTERFACE IAzObjectPicker $IID_IAzObjectPicker

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetPrincipals <1610743808> ( _                ' VTable offset = 28
     BYVAL hParentWnd AS DWORD _                        ' __in HWND hParentWnd
   , BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   , BYREF pvSidTypes AS VARIANT _                      ' __out VARIANT *pvSidTypes
   , BYREF pvNames AS VARIANT _                         ' __out VARIANT *pvNames
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSids
   ' =====================================================================================
   PROPERTY GET Name <1610743809> ( _                   ' VTable offset = 32
   ) AS WSTRING                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAzObjectPicker_INTERFACE_DEFINED__ */
