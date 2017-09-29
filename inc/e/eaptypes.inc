' ########################################################################################
' Microsoft Windows
' File: eaptypes.inc
' Contents: IDL source for interaction with EAPHost supplicants.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EAPTYPES_INC = 1

#INCLUDE ONCE "guiddef.inc"  ' // Used by EAP_ERROR structure.


'// Properties that EAP Methods support
%eapPropCipherSuiteNegotiation     = &H00000001???
%eapPropMutualAuth                 = &H00000002???
%eapPropIntegrity                  = &H00000004???
%eapPropReplayProtection           = &H00000008???
%eapPropConfidentiality            = &H00000010???
%eapPropKeyDerivation              = &H00000020???
%eapPropKeyStrength64              = &H00000040???
%eapPropKeyStrength128             = &H00000080???
%eapPropKeyStrength256             = &H00000100???
%eapPropKeyStrength512             = &H00000200???
%eapPropKeyStrength1024            = &H00000400???
%eapPropDictionaryAttackResistance = &H00000800???
%eapPropFastReconnect              = &H00001000???
%eapPropCryptoBinding              = &H00002000???
%eapPropSessionIndependence        = &H00004000???
%eapPropFragmentation              = &H00008000???
%eapPropChannelBinding             = &H00010000???
%eapPropNap                        = &H00020000???
%eapPropStandalone                 = &H00040000???
%eapPropMppeEncryption             = &H00080000???
%eapPropTunnelMethod               = &H00100000???
%eapPropSupportsConfig             = &H00200000???
%eapPropCertifiedMethod            = &H00400000???
%eapPropHiddenMethod               = &H00800000???
%eapPropMachineAuth                = &H01000000???
%eapPropUserAuth                   = &H02000000???
%eapPropIdentityPrivacy            = &H04000000???
%eapPropMethodChaining             = &H08000000???
%eapPropSharedStateEquivalence     = &H10000000???
%eapPropReserved                   = &H80000000???

'// Registry NameValue that stores Properties supported by EAP Method
'#define EAP_VALUENAME_PROPERTIES L"Properties"
$EAP_VALUENAME_PROPERTIES = "Properties"

'typedef DWORD EAP_SESSIONID;

'#IF %DEF(%USEPBDECL)
'' // Note: It's using a wrong alignment.
'TYPE EAP_TYPE
'    type         AS BYTE
'    dwVendorId   AS DWORD
'    dwVendorType AS DWORD
'END TYPE
'#ELSE
' // Size = 12 bytes
TYPE EAP_TYPE DWORD
   type         AS BYTE    ' BYTE
   dwVendorId   AS DWORD   ' DWORD
   dwVendorType AS DWORD   ' DWORD
END TYPE
'#ENDIF

' // Size = 16 bytes
TYPE EAP_METHOD_TYPE DWORD
   eapType    AS EAP_TYPE   ' EAP_TYPE
   dwAuthorId AS DWORD      ' DWORD
END TYPE

' // Size = 32 bytes
TYPE EAP_METHOD_INFO DWORD
   eaptype          AS EAP_METHOD_TYPE       ' EAP_METHOD_TYPE
   pwszAuthorName   AS WSTRINGZ PTR          ' LPWSTR
   pwszFriendlyName AS WSTRINGZ PTR          ' LPWSTR
   eapProperties    AS DWORD                 ' DWORD
   pInnerMethodInfo AS EAP_METHOD_INFO PTR   ' struct _EAP_METHOD_INFO*
END TYPE

'// EAPHost populates this array with the information for all the eap-methods installed
'// on machine and passes it to a supplicant

' // Size = 8 bytes
TYPE EAP_METHOD_INFO_ARRAY DWORD
   dwNumberOfMethods AS DWORD                 ' DWORD
   pEapMethods       AS EAP_METHOD_INFO PTR   ' EAP_METHOD_INFO*
END TYPE

' // Size = 32 bytes
TYPE EAP_METHOD_INFO_EX DWORD
   eaptype               AS EAP_METHOD_TYPE             ' EAP_METHOD_TYPE
   pwszAuthorName        AS WSTRINGZ PTR                ' LPWSTR
   pwszFriendlyName      AS WSTRINGZ PTR                ' LPWSTR
   eapProperties         AS DWORD                       ' DWORD
#IF %DEF(%USEPBDECL)
   pInnerMethodInfoArray AS DWORD  ' EAP_METHOD_INFO_ARRAY_EX PTR
#ELSE
   pInnerMethodInfoArray AS EAP_METHOD_INFO_ARRAY PTR   ' struct _EAP_METHOD_INFO_ARRAY_EX*
#ENDIF
END TYPE

'// EAPHost populates this error structs with appropriate information and passes it to
'// supplicant, which can use this information for error reporting and troubleshooting

' // Size = 8 bytes
TYPE EAP_METHOD_INFO_ARRAY_EX DWORD
   dwNumberOfMethods AS DWORD                   ' DWORD
   pEapMethods       AS EAP_METHOD_INFO_EX PTR   ' EAP_METHOD_INFO_EX*
END TYPE

' // Size = 80 bytes
TYPE EAP_ERROR DWORD
   dwWinError       AS DWORD             ' DWORD
   type             AS EAP_METHOD_TYPE   ' EAP_METHOD_TYPE
   dwReasonCode     AS DWORD             ' DWORD
   rootCauseGuid    AS GUID              ' GUID
   repairGuid       AS GUID              ' GUID
   helpLinkGuid     AS GUID              ' GUID
   pRootCauseString AS WSTRINGZ PTR      ' LPWSTR
   pRepairString    AS WSTRINGZ PTR      ' LPWSTR
END TYPE


$GUID_EapHost_Default = GUID$("{00000000-0000-0000-0000-000000000000}")
$GUID_EapHost_Cause_MethodDLLNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000001}")
$GUID_EapHost_Cause_EapNegotiationFailed = GUID$("{9612fc67-6150-4209-a85e-a8d80000001C}")
$GUID_EapHost_Cause_ThirdPartyMethod_Host_Reset = GUID$("{9612fc67-6150-4209-a85e-a8d800000212}")
$GUID_EapHost_Cause_XmlMalformed = GUID$("{9612fc67-6150-4209-a85e-a8d80000001D}")
$GUID_EapHost_Cause_MethodDoesNotSupportOperation = GUID$("{9612fc67-6150-4209-a85e-a8d80000001E}")
$GUID_EapHost_Cause_EapQecInaccessible = GUID$("{9612fc67-6150-4209-a85e-a8d800000312}")
$GUID_EapHost_Cause_Generic_AuthFailure = GUID$("{9612fc67-6150-4209-a85e-a8d800000104}")
$GUID_EapHost_Cause_IdentityUnknown = GUID$("{9612fc67-6150-4209-a85e-a8d800000204}")
$GUID_EapHost_Cause_CertStoreInaccessible = GUID$("{9612fc67-6150-4209-a85e-a8d800000004}")
$GUID_EapHost_Cause_User_CertExpired = GUID$("{9612fc67-6150-4209-a85e-a8d800000009}")
$GUID_EapHost_Cause_User_CertInvalid = GUID$("{9612fc67-6150-4209-a85e-a8d80000000A}")
$GUID_EapHost_Cause_User_CertNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d80000000B}")
$GUID_EapHost_Cause_User_CertOtherError = GUID$("{9612fc67-6150-4209-a85e-a8d80000000C}")
$GUID_EapHost_Cause_User_CertRejected = GUID$("{9612fc67-6150-4209-a85e-a8d80000000D}")
$GUID_EapHost_Cause_User_CertRevoked = GUID$("{9612fc67-6150-4209-a85e-a8d80000000E}")
$GUID_EapHost_Cause_User_Account_OtherProblem = GUID$("{9612fc67-6150-4209-a85e-a8d80000010E}")
$GUID_EapHost_Cause_User_CredsRejected = GUID$("{9612fc67-6150-4209-a85e-a8d80000020E}")
$GUID_EapHost_Cause_Server_CertExpired = GUID$("{9612fc67-6150-4209-a85e-a8d800000005}")
$GUID_EapHost_Cause_Server_CertInvalid = GUID$("{9612fc67-6150-4209-a85e-a8d800000006}")
$GUID_EapHost_Cause_Server_CertNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000007}")
$GUID_EapHost_Cause_Server_CertOtherError = GUID$("{9612fc67-6150-4209-a85e-a8d800000108}")
$GUID_EapHost_Cause_Server_CertRevoked = GUID$("{9612fc67-6150-4209-a85e-a8d800000008}")
$GUID_EapHost_Cause_User_Root_CertExpired = GUID$("{9612fc67-6150-4209-a85e-a8d80000000F}")
$GUID_EapHost_Cause_User_Root_CertInvalid = GUID$("{9612fc67-6150-4209-a85e-a8d800000010}")
$GUID_EapHost_Cause_User_Root_CertNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000011}")
$GUID_EapHost_Cause_Server_Root_CertNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000112}")
$GUID_EapHost_Cause_Server_Root_CertNameRequired = GUID$("{9612fc67-6150-4209-a85e-a8d800000012}")
$GUID_EapHost_Cause_No_SmartCardReader_Found = GUID$("{9612fc67-6150-4209-a85e-a8d80000002B}")

$GUID_EapHost_Repair_ContactSysadmin = GUID$("{9612fc67-6150-4209-a85e-a8d800000002}")
$GUID_EapHost_Repair_Retry_Authentication = GUID$("{9612fc67-6150-4209-a85e-a8d80000011B}")
$GUID_EapHost_Repair_User_AuthFailure = GUID$("{9612fc67-6150-4209-a85e-a8d800000019}")
$GUID_EapHost_Repair_User_GetNewCert = GUID$("{9612fc67-6150-4209-a85e-a8d80000001A}")
$GUID_EapHost_Repair_User_SelectValidCert = GUID$("{9612fc67-6150-4209-a85e-a8d80000001B}")
$GUID_EapHost_Repair_Server_ClientSelectServerCert = GUID$("{9612fc67-6150-4209-a85e-a8d800000019}")

$GUID_EapHost_Repair_ContactAdmin_AuthFailure = GUID$("{9612fc67-6150-4209-a85e-a8d80000001F}")
$GUID_EapHost_Repair_ContactAdmin_IdentityUnknown = GUID$("{9612fc67-6150-4209-a85e-a8d800000020}")
$GUID_EapHost_Repair_ContactAdmin_NegotiationFailed = GUID$("{9612fc67-6150-4209-a85e-a8d800000021}")
$GUID_EapHost_Repair_ContactAdmin_MethodNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000022}")
$GUID_EapHost_Repair_RestartNap = GUID$("{9612fc67-6150-4209-a85e-a8d800000023}")
$GUID_EapHost_Repair_ContactAdmin_CertStoreInaccessible = GUID$("{9612fc67-6150-4209-a85e-a8d800000024}")
$GUID_EapHost_Repair_ContactAdmin_InvalidUserAccount = GUID$("{9612fc67-6150-4209-a85e-a8d800000025}")
$GUID_EapHost_Repair_ContactAdmin_InvalidUserCert = GUID$("{9612fc67-6150-4209-a85e-a8d80000002C}")
$GUID_EapHost_Repair_ContactAdmin_RootCertInvalid = GUID$("{9612fc67-6150-4209-a85e-a8d800000026}")
$GUID_EapHost_Repair_ContactAdmin_RootCertNotFound = GUID$("{9612fc67-6150-4209-a85e-a8d800000027}")
$GUID_EapHost_Repair_ContactAdmin_RootExpired = GUID$("{9612fc67-6150-4209-a85e-a8d800000028}")
$GUID_EapHost_Repair_ContactAdmin_CertNameAbsent = GUID$("{9612fc67-6150-4209-a85e-a8d800000029}")
$GUID_EapHost_Repair_ContactAdmin_NoSmartCardReader = GUID$("{9612fc67-6150-4209-a85e-a8d80000002A}")
$GUID_EapHost_Repair_Method_Not_Support_Sso = GUID$("{9612fc67-6150-4209-a85e-a8d80000002D}")

$GUID_EapHost_Help_ObtainingCerts = GUID$("{f535eea3-1bdd-46ca-a2fc-a6655939b7e8}")
$GUID_EapHost_Help_Troubleshooting = GUID$("{33307acf-0698-41ba-b014-ea0a2eb8d0a8}")
$GUID_EapHost_Cause_Method_Config_Does_Not_Support_Sso = GUID$("{da18bd32-004f-41fa-ae08-0bc85e5845ac}")

' // The following guids are mentioned in the MSDN documentation about the ONEX_EAP_ERROR structure,
' // but not included in eatypes.h
$GUID_EapHost_Help_EapConfigureTypes = GUID$("{9612fc67-6150-4209-a85e-a8d800000003}")
$GUID_EapHost_Help_FailedAuth = GUID$("{9612fc67-6150-4209-a85e-a8d800000013}")
$GUID_EapHost_Help_SelectingCerts = GUID$("{9612fc67-6150-4209-a85e-a8d800000015}")
$GUID_EapHost_Help_SetupEapServer = GUID$("{9612fc67-6150-4209-a85e-a8d800000016}")


'//--------------------------

' enum EAP_ATTRIBUTE_TYPE
%eatMinimum                = 0               ' // Undefined
%eatUserName               = 1               ' // Value field is a Pointer
%eatUserPassword           = 2               ' // Value field is a Pointer
%eatMD5CHAPPassword        = 3               ' // Value field is a Pointer
%eatNASIPAddress           = 4               ' // Value field is a 32 bit integral value
%eatNASPort                = 5               ' // Value field is a 32 bit integral value
%eatServiceType            = 6               ' // Value field is a 32 bit integral value
%eatFramedProtocol         = 7               ' // Value field is a 32 bit integral value
%eatFramedIPAddress        = 8               ' // Value field is a 32 bit integral value
%eatFramedIPNetmask        = 9               ' // Value field is a 32 bit integral value
%eatFramedRouting          = 10              ' // Value field is a 32 bit integral value
%eatFilterId               = 11              ' // Value field is a Pointer
%eatFramedMTU              = 12              ' // Value field is a 32 bit integral value
%eatFramedCompression      = 13              ' // Value field is a 32 bit integral value
%eatLoginIPHost            = 14              ' // Value field is a 32 bit integral value
%eatLoginService           = 15              ' // Value field is a 32 bit integral value
%eatLoginTCPPort           = 16              ' // Value field is a 32 bit integral value
%eatUnassigned17           = 17              ' // Undefined
%eatReplyMessage           = 18              ' // Value field is a Pointer
%eatCallbackNumber         = 19              ' // Value field is a Pointer
%eatCallbackId             = 20              ' // Value field is a Pointer
%eatUnassigned21           = 21              ' // Undefined
%eatFramedRoute            = 22              ' // Value field is a Pointer
%eatFramedIPXNetwork       = 23              ' // Value field is a 32 bit integral value
%eatState                  = 24              ' // Value field is a Pointer
%eatClass                  = 25              ' // Value field is a Pointer
%eatVendorSpecific         = 26              ' // Value field is a Pointer
%eatSessionTimeout         = 27              ' // Value field is a 32 bit integral value
%eatIdleTimeout            = 28              ' // Value field is a 32 bit integral value
%eatTerminationAction      = 29              ' // Value field is a 32 bit integral value
%eatCalledStationId        = 30              ' // Value field is a Pointer
%eatCallingStationId       = 31              ' // Value field is a Pointer
%eatNASIdentifier          = 32              ' // Value field is a Pointer
%eatProxyState             = 33              ' // Value field is a Pointer
%eatLoginLATService        = 34              ' // Value field is a Pointer
%eatLoginLATNode           = 35              ' // Value field is a Pointer
%eatLoginLATGroup          = 36              ' // Value field is a Pointer
%eatFramedAppleTalkLink    = 37              ' // Value field is a 32 bit integral value
%eatFramedAppleTalkNetwork = 38              ' // Value field is a 32 bit integral value
%eatFramedAppleTalkZone    = 39              ' // Value field is a Pointer
%eatAcctStatusType         = 40              ' // Value field is a 32 bit integral value
%eatAcctDelayTime          = 41              ' // Value field is a 32 bit integral value
%eatAcctInputOctets        = 42              ' // Value field is a 32 bit integral value
%eatAcctOutputOctets       = 43              ' // Value field is a 32 bit integral value
%eatAcctSessionId          = 44              ' // Value field is a Pointer
%eatAcctAuthentic          = 45              ' // Value field is a 32 bit integral value
%eatAcctSessionTime        = 46              ' // Value field is a 32 bit integral value
%eatAcctInputPackets       = 47              ' // Value field is a 32 bit integral value
%eatAcctOutputPackets      = 48              ' // Value field is a 32 bit integral value
%eatAcctTerminateCause     = 49              ' // Value field is a 32 bit integral value
%eatAcctMultiSessionId     = 50              ' // Value field is a Pointer
%eatAcctLinkCount          = 51              ' // Value field is a 32 bit integral value
%eatAcctEventTimeStamp     = 55              ' // Value field is a 32 bit integral value
%eatMD5CHAPChallenge       = 60              ' // Value field is a Pointer
%eatNASPortType            = 61              ' // Value field is a 32 bit integral value
%eatPortLimit              = 62              ' // Value field is a 32 bit integral value
%eatLoginLATPort           = 63              ' // Value field is a Pointer
%eatTunnelType             = 64              ' // Value field is a 32 bit integral value
%eatTunnelMediumType       = 65              ' // Value field is a 32 bit integral value
%eatTunnelClientEndpoint   = 66              ' // Value field is a Pointer
%eatTunnelServerEndpoint   = 67              ' // Value field is a Pointer
%eatARAPPassword           = 70              ' // Value field is a Pointer
%eatARAPFeatures           = 71              ' // Value field is a Pointer
%eatARAPZoneAccess         = 72              ' // Value field is a 32 bit integral value
%eatARAPSecurity           = 73              ' // Value field is a 32 bit integral value
%eatARAPSecurityData       = 74              ' // Value field is a Pointer
%eatPasswordRetry          = 75              ' // Value field is a 32 bit integral value
%eatPrompt                 = 76              ' // Value field is a 32 bit integral value
%eatConnectInfo            = 77              ' // Value field is a Pointer
%eatConfigurationToken     = 78              ' // Value field is a Pointer
%eatEAPMessage             = 79              ' // Value field is a Pointer
%eatSignature              = 80              ' // Value field is a Pointer
%eatARAPChallengeResponse  = 84              ' // Value field is a Pointer
%eatAcctInterimInterval    = 85              ' // Value field is a 32 bit integral value
%eatNASIPv6Address         = 95              ' // Value field is a Pointer
%eatFramedInterfaceId      = 96              ' // Value field is a Pointer
%eatFramedIPv6Prefix       = 97              ' // Value field is a Pointer
%eatLoginIPv6Host          = 98              ' // Value field is a Pointer
%eatFramedIPv6Route        = 99              ' // Value field is a Pointer
%eatFramedIPv6Pool         = 100             ' // Value field is a Pointer
%eatARAPGuestLogon         = 8096            ' // Value field is a 32 bit integral value
%eatCertificateOID         = 8097            ' // Value field is a Pointer
%eatEAPConfiguration       = 8098            ' // Value field is a Pointer
%eatPEAPEmbeddedEAPTypeId  = 8099            ' // Value field is a 32 bit integral value
%eatPEAPFastRoamedSession  = 8100            ' // Value field is a 32 bit integral value
%eatEAPTLV                 = 8102            ' // Value field is a Pointer
%eatCredentialsChanged     = 8103            ' // Value field is a Integer with boolean
                                            ' // semantics
%eatInnerEapMethodType     = 8104            ' // Value field is a pointer
                                            ' // EapMethodType of the inner method in
                                            ' // case of Tunnelled method
%eatClearTextPassword      = 8107            ' // Value field is a pointer
                                            ' // Clear text password that can be used
                                            ' // by certain password based eap methods
                                            ' // to authenticate a user.
%eatQuarantineSoH          = 8150            ' // Value field is a pointer
%eatPeerId                 = 9000            ' // Value field is a pointer
%eatServerId               = 9001            ' // Value field is a pointer
%eatMethodId               = 9002            ' // Value field is a pointer
%eatEMSK                   = 9003            ' // Value field is a pointer
%eatSessionId              = 9004            ' // Value field is a pointer
%eatReserved               = &HFFFFFFFF???   ' // Undefined


' // Size = 12 bytes
TYPE EAP_ATTRIBUTE DWORD
   eaType   AS LONG       ' EAP_ATTRIBUTE_TYPE
   dwLength AS DWORD      ' DWORD
   pValue   AS BYTE PTR   ' BYTE *
END TYPE

MACRO EapAttribute = EAP_ATTRIBUTE


' // Size = 8 bytes
TYPE EAP_ATTRIBUTES DWORD
   dwNumberOfAttributes AS DWORD               ' DWORD
   pAttribs             AS EAP_ATTRIBUTE PTR   ' EAP_ATTRIBUTE *
END TYPE

MACRO EapAttributes = EAP_ATTRIBUTES

'// No UI should be displayed
%EAP_FLAG_Reserved1              = &H00000001???
%EAP_FLAG_NON_INTERACTIVE        = &H00000002???

'// The user data was obtained from Winlogon
%EAP_FLAG_LOGON                  = &H00000004???

'// Show the Credentails UI before authenticating even if cached creds are present
%EAP_FLAG_PREVIEW                = &H00000008???

%EAP_FLAG_Reserved2              = &H00000010???

'// Authentication is for machine, i.e. not for user. Not setting this flag means
'// it is user authentication.
%EAP_FLAG_MACHINE_AUTH           = &H00000020???

'// Request to provide guest access
%EAP_FLAG_GUEST_ACCESS           = &H00000040???

%EAP_FLAG_Reserved3              = &H00000080???

%EAP_FLAG_Reserved4              = &H00000100???

'// Indicates this is the first call after m/c resumed from hibernation.
%EAP_FLAG_RESUME_FROM_HIBERNATE  = &H00000200???

%EAP_FLAG_Reserved5              = &H00000400???

%EAP_FLAG_Reserved6              = &H00000800???

'// Should have this or make it reserved?
%EAP_FLAG_FULL_AUTH              = &H00001000???

'///   New EapHost Flags

'// Prefer Credentails passed in BeginSession instead of other form of
'// credentials, even if config says use certain way of cred retrieval. If this fails, fallback to
'// Method specific credentail retrieval
%EAP_FLAG_PREFER_ALT_CREDENTIALS     = &H00002000???

%EAP_FLAG_Reserved7                  = &H00004000???

'// To inform the cause of reauth is a NAP callback
%EAP_PEER_FLAG_HEALTH_STATE_CHANGE   = &H00008000???

'// Continue authentication with information available. If can not proceed, fail
'// the authentication
%EAP_FLAG_SUPRESS_UI                 = &H00010000???

'// Pre logon scenario like PLAP
%EAP_FLAG_PRE_LOGON                  = &H00020000???

'// User Authentication. For legacy Methods not setting EAP_FLAG_MACHINE_AUTH
'// also means user authentication.
%EAP_FLAG_USER_AUTH                  = &H00040000???

'// Config can be viewed but not updated
%EAP_FLAG_CONFG_READONLY             = &H00080000???

%EAP_FLAG_Reserved8                  = &H00100000???

'// the various states of the input fields
%EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT         = 0
%EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE = 1

'// This specifies that supplicant should cache this field data
%EAP_CONFIG_INPUT_FIELD_PROPS_NON_PERSIST = &H00000002???

'// default property value for entries field to be shown in UI
%EAP_UI_INPUT_FIELD_PROPS_DEFAULT = %EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT
'// To qualify certain entry data on UI is non-displayable (e.g. password)
%EAP_UI_INPUT_FIELD_PROPS_NON_DISPLAYABLE = %EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE
'// This specifies that supplicant should cache this field data
%EAP_UI_INPUT_FIELD_PROPS_NON_PERSIST = &H00000002???
'// This specifies that following field is read only (non-editable)
%EAP_UI_INPUT_FIELD_PROPS_READ_ONLY = &H00000004???

'// the types of fileds that eap can request to show
' enum EAP_CONFIG_INPUT_FIELD_TYPE {
%EapConfigInputUsername        = 0
%EapConfigInputPassword        = 1
%EapConfigInputNetworkUsername = 2
%EapConfigInputNetworkPassword = 3
%EapConfigInputPin             = 4
%EapConfigInputPSK             = 5
%EapConfigInputEdit            = 6
%EapConfigSmartCardUsername    = 7
%EapConfigSmartCardError       = 8

%EAP_CREDENTIAL_VERSION                  = 1
%EAP_INTERACTIVE_UI_DATA_VERSION         = 1
%EAPHOST_PEER_API_VERSION                = 1
%EAPHOST_METHOD_API_VERSION              = 1
%MAX_EAP_CONFIG_INPUT_FIELD_LENGTH       = 256
%MAX_EAP_CONFIG_INPUT_FIELD_VALUE_LENGTH = 1024

' // Size = 28 bytes
TYPE EAP_CONFIG_INPUT_FIELD_DATA DWORD
   dwSize          AS DWORD          ' DWORD
   Type            AS LONG           ' EAP_CONFIG_INPUT_FIELD_TYPE
   dwFlagProps     AS DWORD          ' DWORD
   pwszLabel       AS WSTRINGZ PTR   ' LPWSTR
   pwszData        AS WSTRINGZ PTR   ' LPWSTR
   dwMinDataLength AS DWORD          ' DWORD
   dwMaxDataLength AS DWORD          ' DWORD
END TYPE

' // Size = 12 bytes
TYPE EAP_CONFIG_INPUT_FIELD_ARRAY DWORD
   dwVersion        AS DWORD   ' DWORD // used for versioning
   dwNumberOfFields AS DWORD   ' DWORD
   pFields          AS EAP_CONFIG_INPUT_FIELD_DATA PTR   ' EAP_CONFIG_INPUT_FIELD_DATA *
END TYPE

'// provides type of data, EAP_INTERACTIVE_UI_DATA can carry
' enum EAP_INTERACTIVE_UI_DATA_TYPE
%EapCredReq = 0            ' // Credential request during retry
%EapCredResp = 1           ' // Credential response during retry
%EapCredExpiryReq = 2      ' // Credential request during cred expiry
%EapCredExpiryResp = 3     ' // Credential response during cred expiry
%EapCredLogonReq = 4       ' // Initial credential request during auth
%EapCredLogonResp = 5      ' // Initial credential response during auth

'// following determine type of data blob that can be pointed by
'// pbUiData member of EAP_INTERACTIVE_UI_DATA
MACRO EAP_CRED_REQ = EAP_CONFIG_INPUT_FIELD_ARRAY
MACRO EAP_CRED_RESP = EAP_CONFIG_INPUT_FIELD_ARRAY
MACRO EAP_CRED_LOGON_REQ = EAP_CONFIG_INPUT_FIELD_ARRAY
MACRO EAP_CRED_LOGON_RESP = EAP_CONFIG_INPUT_FIELD_ARRAY

'// pNewCreds can be NULL in case of EAP_CRED_EXPIRY_REQ
'// in case of REQ, pNewCreds can be empty (will not be looked at)
' // Size = 24 bytes
TYPE EAP_CRED_EXPIRY_REQ DWORD
   curCreds AS EAP_CONFIG_INPUT_FIELD_ARRAY
   newCreds AS EAP_CONFIG_INPUT_FIELD_ARRAY
END TYPE

' // Size = 4 bytes
UNION EAP_UI_DATA_FORMAT DWORD
   credData       AS EAP_CRED_REQ PTR          ' EAP_CRED_REQ*
   credExpiryData AS EAP_CRED_EXPIRY_REQ PTR   ' EAP_CRED_EXPIRY_REQ*
   credLogonData  AS EAP_CRED_LOGON_REQ PTR    ' EAP_CRED_LOGON_REQ*
END UNION

'// Data carried from EAP-method to supplicant for interactive UI to raised
' // Size = 20 bytes
TYPE EAP_INTERACTIVE_UI_DATA DWORD
   ' //specifies version of data structure. It must be 0.
   dwVersion AS DWORD   ' DWORD
   ' //specifies size of the entire structure.
   dwSize AS DWORD   ' DWORD
   ' // this determines what kind of interactive data is passed.
   dwDataType AS LONG   ' EAP_INTERACTIVE_UI_DATA_TYPE
   ' // specifies size of the data pointed by pbUiByte.
   cbUiData AS DWORD   ' DWORD
   ' // pointer to a data blob of a type determined by dwDataType above.
   ' // This can be of type EAP_CRED_REQ/EAP_CRED_RESP or
   ' // EAP_CRED_EXPIRY_REQ/EAP_CRED_EXPIRY_RESP or
   ' // EAP_CRED_LOGON_REQ/EAP_CRED_LOGON_RESP depending on uiDataType above
   pbUiData AS EAP_UI_DATA_FORMAT
END TYPE

'// Property types that EAP methods support
' enum EAP_METHOD_PROPERTY_TYPE
%emptPropCipherSuiteNegotiation = 0       ' // value field is boolean
%emptPropMutualAuth = 1                   ' // value field is boolean
%emptPropIntegrity = 2                    ' // value field is boolean
%emptPropReplayProtection = 3             ' // value field is boolean
%emptPropConfidentiality = 4              ' // value field is boolean
%emptPropKeyDerivation = 5                ' // value field is boolean
%emptPropKeyStrength64 = 6                ' // value field is boolean
%emptPropKeyStrength128 = 7               ' // value field is boolean
%emptPropKeyStrength256 = 8               ' // value field is boolean
%emptPropKeyStrength512 = 9               ' // value field is boolean
%emptPropKeyStrength1024 = 10             ' // value field is boolean
%emptPropDictionaryAttackResistance = 11  ' // value field is boolean
%emptPropFastReconnect = 12               ' // value field is boolean
%emptPropCryptoBinding = 13               ' // value field is boolean
%emptPropSessionIndependence = 14         ' // value field is boolean
%emptPropFragmentation = 15               ' // value field is boolean
%emptPropChannelBinding = 16              ' // value field is boolean
%emptPropNap = 17                         ' // value field is boolean
%emptPropStandalone = 18                  ' // value field is boolean
%emptPropMppeEncryption = 19              ' // value field is boolean
%emptPropTunnelMethod = 20                ' // value field is boolean
%emptPropSupportsConfig = 21              ' // value field is boolean
%emptPropCertifiedMethod = 22             ' // value field is boolean
%emptPropHiddenMethod = 23                ' // value field is boolean
%emptPropMachineAuth = 24                 ' // value field is boolean
%emptPropUserAuth = 25                    ' // value field is boolean
%emptPropIdentityPrivacy = 26             ' // value field is boolean
%emptPropMethodChaining = 27              ' // value field is boolean
%emptPropSharedStateEquivalence = 28      ' // value field is boolean
%emptLegacyMethodPropertyFlag = 31        ' // value field is dword
%emptPropVendorSpecific = 255             ' // value field is string

'// Method property value types that EAP methods support
' enum EAP_METHOD_PROPERTY_VALUE_TYPE
%empvtBool   = 0   ' // value type is boolean
%empvtDword  = 1   ' // value type is dword
%empvtString = 2   ' // value type is string

' // Size = 8 bytes
TYPE EAP_METHOD_PROPERTY_VALUE_BOOL DWORD
   length AS DWORD   ' DWORD
   value  AS LONG    ' BOOL
END TYPE

' // Size = 8 bytes
TYPE EAP_METHOD_PROPERTY_VALUE_DWORD DWORD
   length AS DWORD   ' DWORD
   value  AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE EAP_METHOD_PROPERTY_VALUE_STRING DWORD
   length AS DWORD      ' DWORD
   value  AS BYTE PTR   ' BYTE*
END TYPE

' // Size = 8 bytes
UNION EAP_METHOD_PROPERTY_VALUE DWORD
   empvBool   AS EAP_METHOD_PROPERTY_VALUE_BOOL     ' // value is boolean type
   empvDword  AS EAP_METHOD_PROPERTY_VALUE_DWORD    ' // value is dword type
   empvString AS EAP_METHOD_PROPERTY_VALUE_STRING   ' // value is string type
END UNION

'// Structure to represent a method property
' // Size = 16 bytes
TYPE EAP_METHOD_PROPERTY DWORD
   ' // specifies the method property type
   eapMethodPropertyType      AS LONG   ' EAP_METHOD_PROPERTY_TYPE
   ' // specifies the data type of value
   eapMethodPropertyValueType AS LONG   ' EAP_METHOD_PROPERTY_VALUE_TYPE
   ' // specifies the value of the method property
   eapMethodPropertyValue     AS EAP_METHOD_PROPERTY_VALUE
END TYPE

'// Structure to represent an array of method properties
' // Size = 8 bytes
TYPE EAP_METHOD_PROPERTY_ARRAY DWORD
   ' // specifies the number of method properties in array
   dwNumberOfProperties AS DWORD                     ' DWORD
   ' // specifies the array of method property
   pMethodProperty      AS EAP_METHOD_PROPERTY PTR   ' EAP_METHOD_PROPERTY*
END TYPE
