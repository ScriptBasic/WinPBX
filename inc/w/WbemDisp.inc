' ########################################################################################
' Microsoft Windows
' File: WbemDisp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WbemScripting
' Version: 1.2, Locale ID = 0
' Documentation string: Microsoft WMI Scripting V1.2 Library
' Path: C:\WINDOWS\system32\wbem\wbemdisp.TLB
' Library GUID: {565783C6-CB41-11D1-8B02-00600806D9B6}
' ########################################################################################

#INCLUDE THIS ONCE
%WBEMDISP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wbemcli.inc"
#INCLUDE ONCE "dispex.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {47DFBE54-CF76-11D3-B38F-00105A1F473A}
$PROGID_SWbemDateTime1 = "WbemScripting.SWbemDateTime.1"
' CLSID = {C2FEEEAC-CFCD-11D1-8B05-00600806D9B6}
$PROGID_SWbemLastError1 = "WbemScripting.SWbemLastError.1"
' CLSID = {76A64158-CB41-11D1-8B02-00600806D9B6}
$PROGID_SWbemLocator1 = "WbemScripting.SWbemLocator.1"
' CLSID = {9AED384E-CE8B-11D1-8B05-00600806D9B6}
$PROGID_SWbemNamedValueSet1 = "WbemScripting.SWbemNamedValueSet.1"
' CLSID = {5791BC26-CE9C-11D1-97BF-0000F81E849C}
$PROGID_SWbemObjectPath1 = "WbemScripting.SWbemObjectPath.1"
' CLSID = {D269BF5C-D9C1-11D3-B38F-00105A1F473A}
$PROGID_SWbemRefresher1 = "WbemScripting.SWbemRefresher.1"
' CLSID = {75718C9A-F029-11D1-A1AC-00C04FB6C223}
$PROGID_SWbemSink1 = "WbemScripting.SWbemSink.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {47DFBE54-CF76-11D3-B38F-00105A1F473A}
$PROGID_SWbemDateTime = "WbemScripting.SWbemDateTime"
' CLSID = {C2FEEEAC-CFCD-11D1-8B05-00600806D9B6}
$PROGID_SWbemLastError = "WbemScripting.SWbemLastError"
' CLSID = {76A64158-CB41-11D1-8B02-00600806D9B6}
$PROGID_SWbemLocator = "WbemScripting.SWbemLocator"
' CLSID = {9AED384E-CE8B-11D1-8B05-00600806D9B6}
$PROGID_SWbemNamedValueSet = "WbemScripting.SWbemNamedValueSet"
' CLSID = {5791BC26-CE9C-11D1-97BF-0000F81E849C}
$PROGID_SWbemObjectPath = "WbemScripting.SWbemObjectPath"
' CLSID = {D269BF5C-D9C1-11D3-B38F-00105A1F473A}
$PROGID_SWbemRefresher = "WbemScripting.SWbemRefresher"
' CLSID = {75718C9A-F029-11D1-A1AC-00C04FB6C223}
$PROGID_SWbemSink = "WbemScripting.SWbemSink"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SWbemEventSource = GUID$("{04B83D58-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemMethod = GUID$("{04B83D5B-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemMethodSet = GUID$("{04B83D5A-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemNamedValue = GUID$("{04B83D60-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemObject = GUID$("{04B83D62-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemObjectEx = GUID$("{D6BDAFB2-9435-491F-BB87-6AA0F0BC31A2}")
$CLSID_SWbemObjectSet = GUID$("{04B83D61-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemPrivilege = GUID$("{26EE67BC-5804-11D2-8B4A-00600806D9B6}")
$CLSID_SWbemPrivilegeSet = GUID$("{26EE67BE-5804-11D2-8B4A-00600806D9B6}")
$CLSID_SWbemProperty = GUID$("{04B83D5D-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemPropertySet = GUID$("{04B83D5C-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemQualifier = GUID$("{04B83D5F-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemQualifierSet = GUID$("{04B83D5E-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemRefreshableItem = GUID$("{8C6854BC-DE4B-11D3-B390-00105A1F473A}")
$CLSID_SWbemSecurity = GUID$("{B54D66E9-2287-11D2-8B33-00600806D9B6}")
$CLSID_SWbemServices = GUID$("{04B83D63-21AE-11D2-8B33-00600806D9B6}")
$CLSID_SWbemServicesEx = GUID$("{62E522DC-8CF3-40A8-8B2E-37D595651E40}")
$CLSID_SWbemDateTime = GUID$("{47DFBE54-CF76-11D3-B38F-00105A1F473A}")
$CLSID_SWbemLastError = GUID$("{C2FEEEAC-CFCD-11D1-8B05-00600806D9B6}")
$CLSID_SWbemLocator = GUID$("{76A64158-CB41-11D1-8B02-00600806D9B6}")
$CLSID_SWbemNamedValueSet = GUID$("{9AED384E-CE8B-11D1-8B05-00600806D9B6}")
$CLSID_SWbemObjectPath = GUID$("{5791BC26-CE9C-11D1-97BF-0000F81E849C}")
$CLSID_SWbemRefresher = GUID$("{D269BF5C-D9C1-11D3-B38F-00105A1F473A}")
$CLSID_SWbemSink = GUID$("{75718C9A-F029-11D1-A1AC-00C04FB6C223}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISWbemDateTime = GUID$("{5E97458A-CF77-11D3-B38F-00105A1F473A}")
$IID_ISWbemEventSource = GUID$("{27D54D92-0EBE-11D2-8B22-00600806D9B6}")
$IID_ISWbemLastError = GUID$("{D962DB84-D4BB-11D1-8B09-00600806D9B6}")
$IID_ISWbemLocator = GUID$("{76A6415B-CB41-11D1-8B02-00600806D9B6}")
$IID_ISWbemMethod = GUID$("{422E8E90-D955-11D1-8B09-00600806D9B6}")
$IID_ISWbemMethodSet = GUID$("{C93BA292-D955-11D1-8B09-00600806D9B6}")
$IID_ISWbemNamedValue = GUID$("{76A64164-CB41-11D1-8B02-00600806D9B6}")
$IID_ISWbemNamedValueSet = GUID$("{CF2376EA-CE8C-11D1-8B05-00600806D9B6}")
$IID_ISWbemObject = GUID$("{76A6415A-CB41-11D1-8B02-00600806D9B6}")
$IID_ISWbemObjectEx = GUID$("{269AD56A-8A67-4129-BC8C-0506DCFE9880}")
$IID_ISWbemObjectPath = GUID$("{5791BC27-CE9C-11D1-97BF-0000F81E849C}")
$IID_ISWbemObjectSet = GUID$("{76A6415F-CB41-11D1-8B02-00600806D9B6}")
$IID_ISWbemPrivilege = GUID$("{26EE67BD-5804-11D2-8B4A-00600806D9B6}")
$IID_ISWbemPrivilegeSet = GUID$("{26EE67BF-5804-11D2-8B4A-00600806D9B6}")
$IID_ISWbemProperty = GUID$("{1A388F98-D4BA-11D1-8B09-00600806D9B6}")
$IID_ISWbemPropertySet = GUID$("{DEA0A7B2-D4BA-11D1-8B09-00600806D9B6}")
$IID_ISWbemQualifier = GUID$("{79B05932-D3B7-11D1-8B06-00600806D9B6}")
$IID_ISWbemQualifierSet = GUID$("{9B16ED16-D3DF-11D1-8B08-00600806D9B6}")
$IID_ISWbemRefreshableItem = GUID$("{5AD4BF92-DAAB-11D3-B38F-00105A1F473A}")
$IID_ISWbemRefresher = GUID$("{14D8250E-D9C2-11D3-B38F-00105A1F473A}")
$IID_ISWbemSecurity = GUID$("{B54D66E6-2287-11D2-8B33-00600806D9B6}")
$IID_ISWbemServices = GUID$("{76A6415C-CB41-11D1-8B02-00600806D9B6}")
$IID_ISWbemServicesEx = GUID$("{D2F68443-85DC-427E-91D8-366554CC754C}")
$IID_ISWbemSink = GUID$("{75718C9F-F029-11D1-A1AC-00C04FB6C223}")
$IID_ISWbemSinkEvents = GUID$("{75718CA0-F029-11D1-A1AC-00C04FB6C223}")

%WBEMS_DISPID_OBJECT_READY     = 1
%WBEMS_DISPID_COMPLETED        = 2
%WBEMS_DISPID_PROGRESS         = 3
%WBEMS_DISPID_OBJECT_PUT       = 4
%WBEMS_DISPID_CONNECTION_READY = 5

' ========================================================================================
' WbemChangeFlagEnum enum
' IID: {4A249B72-FC9A-11D1-8B1E-00600806D9B6}
' Defines semantics of putting a Class or Instance
' ========================================================================================

%wbemChangeFlagCreateOrUpdate                           = 0
%wbemChangeFlagUpdateOnly                               = &H1
%wbemChangeFlagCreateOnly                               = &H2
%wbemChangeFlagUpdateCompatible                         = &H0
%wbemChangeFlagUpdateSafeMode                           = &H20
%wbemChangeFlagUpdateForceMode                          = &H40
%wbemChangeFlagStrongValidation                         = &H80
%wbemChangeFlagAdvisory                                 = &H10000

' ========================================================================================
' WbemFlagEnum enum
' IID: {4A249B73-FC9A-11D1-8B1E-00600806D9B6}
' Defines behavior of various interface calls
' ========================================================================================

%wbemFlagReturnImmediately                              = &H10
%wbemFlagReturnWhenComplete                             = 0
%wbemFlagBidirectional                                  = 0
%wbemFlagForwardOnly                                    = &H20
%wbemFlagNoErrorObject                                  = &H40
%wbemFlagReturnErrorObject                              = 0
%wbemFlagSendStatus                                     = &H80
%wbemFlagDontSendStatus                                 = 0
%wbemFlagEnsureLocatable                                = &H100
%wbemFlagDirectRead                                     = &H200
%wbemFlagSendOnlySelected                               = 0
%wbemFlagUseAmendedQualifiers                           = &H20000
%wbemFlagGetDefault                                     = 0
%wbemFlagSpawnInstance                                  = &H1
%wbemFlagUseCurrentTime                                 = &H1

' ========================================================================================
' WbemQueryFlagEnum enum
' IID: {4A249B76-FC9A-11D1-8B1E-00600806D9B6}
' Defines depth of enumeration or query
' ========================================================================================

%wbemQueryFlagDeep                                      = 0
%wbemQueryFlagShallow                                   = 1
%wbemQueryFlagPrototype                                 = 2

' ========================================================================================
' WbemTextFlagEnum enum
' IID: {4A249B78-FC9A-11D1-8B1E-00600806D9B6}
' Defines content of generated object text
' ========================================================================================

%wbemTextFlagNoFlavors                                  = &H1

' ========================================================================================
' WbemTimeout enum
' IID: {BF078C2A-07D9-11D2-8B21-00600806D9B6}
' Defines timeout constants
' ========================================================================================

%wbemTimeoutInfinite                                    = &HFFFFFFFF???

' ========================================================================================
' WbemComparisonFlagEnum enum
' IID: {4A249B79-FC9A-11D1-8B1E-00600806D9B6}
' Defines settings for object comparison
' ========================================================================================

%wbemComparisonFlagIncludeAll                           = 0
%wbemComparisonFlagIgnoreQualifiers                     = &H1
%wbemComparisonFlagIgnoreObjectSource                   = &H2
%wbemComparisonFlagIgnoreDefaultValues                  = &H4
%wbemComparisonFlagIgnoreClass                          = &H8
%wbemComparisonFlagIgnoreCase                           = &H10
%wbemComparisonFlagIgnoreFlavor                         = &H20

' ========================================================================================
' WbemCimtypeEnum enum
' IID: {4A249B7B-FC9A-11D1-8B1E-00600806D9B6}
' Defines the valid CIM Types of a Property value
' ========================================================================================

%wbemCimtypeSint8                                       = 16
%wbemCimtypeUint8                                       = 17
%wbemCimtypeSint16                                      = 2
%wbemCimtypeUint16                                      = 18
%wbemCimtypeSint32                                      = 3
%wbemCimtypeUint32                                      = 19
%wbemCimtypeSint64                                      = 20
%wbemCimtypeUint64                                      = 21
%wbemCimtypeReal32                                      = 4
%wbemCimtypeReal64                                      = 5
%wbemCimtypeBoolean                                     = 11
%wbemCimtypeString                                      = 8
%wbemCimtypeDatetime                                    = 101
%wbemCimtypeReference                                   = 102
%wbemCimtypeChar16                                      = 103
%wbemCimtypeObject                                      = 13

' ========================================================================================
' WbemErrorEnum enum
' IID: {4A249B7C-FC9A-11D1-8B1E-00600806D9B6}
' Defines the errors that may be returned by the WBEM Scripting library
' ========================================================================================

%wbemNoErr                                              = 0&
%wbemErrFailed                                          = &H80041001&
%wbemErrNotFound                                        = &H80041002&
%wbemErrAccessDenied                                    = &H80041003&
%wbemErrProviderFailure                                 = &H80041004&
%wbemErrTypeMismatch                                    = &H80041005&
%wbemErrOutOfMemory                                     = &H80041006&
%wbemErrInvalidContext                                  = &H80041007&
%wbemErrInvalidParameter                                = &H80041008&
%wbemErrNotAvailable                                    = &H80041009&
%wbemErrCriticalError                                   = &H8004100A&
%wbemErrInvalidStream                                   = &H8004100B&
%wbemErrNotSupported                                    = &H8004100C&
%wbemErrInvalidSuperclass                               = &H8004100D&
%wbemErrInvalidNamespace                                = &H8004100E&
%wbemErrInvalidObject                                   = &H8004100F&
%wbemErrInvalidClass                                    = &H80041010&
%wbemErrProviderNotFound                                = &H80041011&
%wbemErrInvalidProviderRegistration                     = &H80041012&
%wbemErrProviderLoadFailure                             = &H80041013&
%wbemErrInitializationFailure                           = &H80041014&
%wbemErrTransportFailure                                = &H80041015&
%wbemErrInvalidOperation                                = &H80041016&
%wbemErrInvalidQuery                                    = &H80041017&
%wbemErrInvalidQueryType                                = &H80041018&
%wbemErrAlreadyExists                                   = &H80041019&
%wbemErrOverrideNotAllowed                              = &H8004101A&
%wbemErrPropagatedQualifier                             = &H8004101B&
%wbemErrPropagatedProperty                              = &H8004101C&
%wbemErrUnexpected                                      = &H8004101D&
%wbemErrIllegalOperation                                = &H8004101E&
%wbemErrCannotBeKey                                     = &H8004101F&
%wbemErrIncompleteClass                                 = &H80041020&
%wbemErrInvalidSyntax                                   = &H80041021&
%wbemErrNondecoratedObject                              = &H80041022&
%wbemErrReadOnly                                        = &H80041023&
%wbemErrProviderNotCapable                              = &H80041024&
%wbemErrClassHasChildren                                = &H80041025&
%wbemErrClassHasInstances                               = &H80041026&
%wbemErrQueryNotImplemented                             = &H80041027&
%wbemErrIllegalNull                                     = &H80041028&
%wbemErrInvalidQualifierType                            = &H80041029&
%wbemErrInvalidPropertyType                             = &H8004102A&
%wbemErrValueOutOfRange                                 = &H8004102B&
%wbemErrCannotBeSingleton                               = &H8004102C&
%wbemErrInvalidCimType                                  = &H8004102D&
%wbemErrInvalidMethod                                   = &H8004102E&
%wbemErrInvalidMethodParameters                         = &H8004102F&
%wbemErrSystemProperty                                  = &H80041030&
%wbemErrInvalidProperty                                 = &H80041031&
%wbemErrCallCancelled                                   = &H80041032&
%wbemErrShuttingDown                                    = &H80041033&
%wbemErrPropagatedMethod                                = &H80041034&
%wbemErrUnsupportedParameter                            = &H80041035&
%wbemErrMissingParameter                                = &H80041036&
%wbemErrInvalidParameterId                              = &H80041037&
%wbemErrNonConsecutiveParameterIds                      = &H80041038&
%wbemErrParameterIdOnRetval                             = &H80041039&
%wbemErrInvalidObjectPath                               = &H8004103A&
%wbemErrOutOfDiskSpace                                  = &H8004103B&
%wbemErrBufferTooSmall                                  = &H8004103C&
%wbemErrUnsupportedPutExtension                         = &H8004103D&
%wbemErrUnknownObjectType                               = &H8004103E&
%wbemErrUnknownPacketType                               = &H8004103F&
%wbemErrMarshalVersionMismatch                          = &H80041040&
%wbemErrMarshalInvalidSignature                         = &H80041041&
%wbemErrInvalidQualifier                                = &H80041042&
%wbemErrInvalidDuplicateParameter                       = &H80041043&
%wbemErrTooMuchData                                     = &H80041044&
%wbemErrServerTooBusy                                   = &H80041045&
%wbemErrInvalidFlavor                                   = &H80041046&
%wbemErrCircularReference                               = &H80041047&
%wbemErrUnsupportedClassUpdate                          = &H80041048&
%wbemErrCannotChangeKeyInheritance                      = &H80041049&
%wbemErrCannotChangeIndexInheritance                    = &H80041050&
%wbemErrTooManyProperties                               = &H80041051&
%wbemErrUpdateTypeMismatch                              = &H80041052&
%wbemErrUpdateOverrideNotAllowed                        = &H80041053&
%wbemErrUpdatePropagatedMethod                          = &H80041054&
%wbemErrMethodNotImplemented                            = &H80041055&
%wbemErrMethodDisabled                                  = &H80041056&
%wbemErrRefresherBusy                                   = &H80041057&
%wbemErrUnparsableQuery                                 = &H80041058&
%wbemErrNotEventClass                                   = &H80041059&
%wbemErrMissingGroupWithin                              = &H8004105A&
%wbemErrMissingAggregationList                          = &H8004105B&
%wbemErrPropertyNotAnObject                             = &H8004105C&
%wbemErrAggregatingByObject                             = &H8004105D&
%wbemErrUninterpretableProviderQuery                    = &H8004105F&
%wbemErrBackupRestoreWinmgmtRunning                     = &H80041060&
%wbemErrQueueOverflow                                   = &H80041061&
%wbemErrPrivilegeNotHeld                                = &H80041062&
%wbemErrInvalidOperator                                 = &H80041063&
%wbemErrLocalCredentials                                = &H80041064&
%wbemErrCannotBeAbstract                                = &H80041065&
%wbemErrAmendedObject                                   = &H80041066&
%wbemErrClientTooSlow                                   = &H80041067&
%wbemErrNullSecurityDescriptor                          = &H80041068&
%wbemErrTimeout                                         = &H80041069&
%wbemErrInvalidAssociation                              = &H8004106A&
%wbemErrAmbiguousOperation                              = &H8004106B&
%wbemErrQuotaViolation                                  = &H8004106C&
%wbemErrTransactionConflict                             = &H8004106D&
%wbemErrForcedRollback                                  = &H8004106E&
%wbemErrUnsupportedLocale                               = &H8004106F&
%wbemErrHandleOutOfDate                                 = &H80041070&
%wbemErrConnectionFailed                                = &H80041071&
%wbemErrInvalidHandleRequest                            = &H80041072&
%wbemErrPropertyNameTooWide                             = &H80041073&
%wbemErrClassNameTooWide                                = &H80041074&
%wbemErrMethodNameTooWide                               = &H80041075&
%wbemErrQualifierNameTooWide                            = &H80041076&
%wbemErrRerunCommand                                    = &H80041077&
%wbemErrDatabaseVerMismatch                             = &H80041078&
%wbemErrVetoPut                                         = &H80041079&
%wbemErrVetoDelete                                      = &H8004107A&
%wbemErrInvalidLocale                                   = &H80041080&
%wbemErrProviderSuspended                               = &H80041081&
%wbemErrSynchronizationRequired                         = &H80041082&
%wbemErrNoSchema                                        = &H80041083&
%wbemErrProviderAlreadyRegistered                       = &H80041084&
%wbemErrProviderNotRegistered                           = &H80041085&
%wbemErrFatalTransportError                             = &H80041086&
%wbemErrEncryptedConnectionRequired                     = &H80041087&
%wbemErrRegistrationTooBroad                            = &H80042001&
%wbemErrRegistrationTooPrecise                          = &H80042002&
%wbemErrTimedout                                        = &H80043001&
%wbemErrResetToDefault                                  = &H80043002&

' ========================================================================================
' WbemAuthenticationLevelEnum enum
' IID: {B54D66E7-2287-11D2-8B33-00600806D9B6}
' Defines the security authentication level
' ========================================================================================

%wbemAuthenticationLevelDefault                         = 0
%wbemAuthenticationLevelNone                            = 1
%wbemAuthenticationLevelConnect                         = 2
%wbemAuthenticationLevelCall                            = 3
%wbemAuthenticationLevelPkt                             = 4
%wbemAuthenticationLevelPktIntegrity                    = 5
%wbemAuthenticationLevelPktPrivacy                      = 6

' ========================================================================================
' WbemImpersonationLevelEnum enum
' IID: {B54D66E8-2287-11D2-8B33-00600806D9B6}
' Defines the security impersonation level
' ========================================================================================

%wbemImpersonationLevelAnonymous                        = 1
%wbemImpersonationLevelIdentify                         = 2
%wbemImpersonationLevelImpersonate                      = 3
%wbemImpersonationLevelDelegate                         = 4

' ========================================================================================
' WbemPrivilegeEnum enum
' IID: {176D2F70-5AF3-11D2-8B4A-00600806D9B6}
' Defines a privilege
' ========================================================================================

%wbemPrivilegeCreateToken                               = 1
%wbemPrivilegePrimaryToken                              = 2
%wbemPrivilegeLockMemory                                = 3
%wbemPrivilegeIncreaseQuota                             = 4
%wbemPrivilegeMachineAccount                            = 5
%wbemPrivilegeTcb                                       = 6
%wbemPrivilegeSecurity                                  = 7
%wbemPrivilegeTakeOwnership                             = 8
%wbemPrivilegeLoadDriver                                = 9
%wbemPrivilegeSystemProfile                             = 10
%wbemPrivilegeSystemtime                                = 11
%wbemPrivilegeProfileSingleProcess                      = 12
%wbemPrivilegeIncreaseBasePriority                      = 13
%wbemPrivilegeCreatePagefile                            = 14
%wbemPrivilegeCreatePermanent                           = 15
%wbemPrivilegeBackup                                    = 16
%wbemPrivilegeRestore                                   = 17
%wbemPrivilegeShutdown                                  = 18
%wbemPrivilegeDebug                                     = 19
%wbemPrivilegeAudit                                     = 20
%wbemPrivilegeSystemEnvironment                         = 21
%wbemPrivilegeChangeNotify                              = 22
%wbemPrivilegeRemoteShutdown                            = 23
%wbemPrivilegeUndock                                    = 24
%wbemPrivilegeSyncAgent                                 = 25
%wbemPrivilegeEnableDelegation                          = 26
%wbemPrivilegeManageVolume                              = 27

' ========================================================================================
' WbemObjectTextFormatEnum enum
' IID: {09FF1992-EA0E-11D3-B391-00105A1F473A}
' Defines object text formats
' ========================================================================================

%wbemObjectTextFormatCIMDTD20                           = 1
%wbemObjectTextFormatWMIDTD20                           = 2

' ========================================================================================
' WbemConnectOptionsEnum enum
' Used to define connection behavior
' ========================================================================================

%wbemConnectFlagUseMaxWait                              = &H80


' ########################################################################################
' Interface name = ISWbemServices
' IID = {76A6415C-CB41-11D1-8B02-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemServices_INTERFACE_DEFINED)
    %ISWbemServices_INTERFACE_DEFINED = 1

INTERFACE ISWbemServices $IID_ISWbemServices

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Get <1> ( _                                   ' VTable offset = 28
     OPTIONAL BYVAL strObjectPath AS WSTRING _          ' __in_opt BSTR strObjectPath = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD GetAsync <2> ( _                              ' VTable offset = 32
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strObjectPath AS WSTRING _          ' __in_opt BSTR strObjectPath = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <3> ( _                                ' VTable offset = 36
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAsync <4> ( _                           ' VTable offset = 40
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD InstancesOf <5> ( _                           ' VTable offset = 44
     BYVAL strClass AS WSTRING _                        ' __in BSTR strClass
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD InstancesOfAsync <6> ( _                      ' VTable offset = 48
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strClass AS WSTRING _                        ' __in BSTR strClass
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SubclassesOf <7> ( _                          ' VTable offset = 52
     OPTIONAL BYVAL strSuperclass AS WSTRING _          ' __in_opt BSTR strSuperclass = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD SubclassesOfAsync <8> ( _                     ' VTable offset = 56
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strSuperclass AS WSTRING _          ' __in_opt BSTR strSuperclass = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemQueryFlagDeep
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecQuery <9> ( _                             ' VTable offset = 60
     BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ExecQueryAsync <10> ( _                       ' VTable offset = 64
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL lFlags AS LONG _                    ' __in_opt long lFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD AssociatorsOf <11> ( _                        ' VTable offset = 68
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD AssociatorsOfAsync <12> ( _                   ' VTable offset = 72
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ReferencesTo <13> ( _                         ' VTable offset = 76
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ReferencesToAsync <14> ( _                    ' VTable offset = 80
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecNotificationQuery <15> ( _                ' VTable offset = 84
     BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagForwardOnly + wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet
   ) AS ISWbemEventSource                               ' __out_retval ISWbemEventSource **objWbemEventSource
   ' =====================================================================================
   METHOD ExecNotificationQueryAsync <16> ( _           ' VTable offset = 88
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecMethod <17> ( _                           ' VTable offset = 92
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   METHOD ExecMethodAsync <18> ( _                      ' VTable offset = 96
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Security_ <19> ( _                      ' VTable offset = 100
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemServices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemLocator
' IID = {76A6415B-CB41-11D1-8B02-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemLocator_INTERFACE_DEFINED)
    %ISWbemLocator_INTERFACE_DEFINED = 1

INTERFACE ISWbemLocator $IID_ISWbemLocator

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ConnectServer <1> ( _                         ' VTable offset = 28
     OPTIONAL BYVAL strServer AS WSTRING _              ' __in_opt BSTR strServer
   , OPTIONAL BYVAL strNamespace AS WSTRING _           ' __in_opt BSTR strNamespace
   , OPTIONAL BYVAL strUser AS WSTRING _                ' __in_opt BSTR strUser
   , OPTIONAL BYVAL strPassword AS WSTRING _            ' __in_opt BSTR strPassword
   , OPTIONAL BYVAL strLocale AS WSTRING _              ' __in_opt BSTR strLocale
   , OPTIONAL BYVAL strAuthority AS WSTRING _           ' __in_opt BSTR strAuthority
   , OPTIONAL BYVAL iSecurityFlags AS LONG _            ' __in_opt long iSecurityFlags
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet
   ) AS ISWbemServices                                  ' __out_retval ISWbemServices **objWbemServices
   ' =====================================================================================
   PROPERTY GET Security_ <2> ( _                       ' VTable offset = 32
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemLocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemObject
' IID = {76A6415A-CB41-11D1-8B02-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemObject_INTERFACE_DEFINED)
    %ISWbemObject_INTERFACE_DEFINED = 1

%WBEMS_DISPID_DERIVATION = 23

INTERFACE ISWbemObject $IID_ISWbemObject

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Put_ <1> ( _                                  ' VTable offset = 28
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   METHOD PutAsync_ <2> ( _                             ' VTable offset = 32
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemChangeFlagCreateOrUpdate
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete_ <3> ( _                               ' VTable offset = 36
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAsync_ <4> ( _                          ' VTable offset = 40
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Instances_ <5> ( _                            ' VTable offset = 44
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD InstancesAsync_ <6> ( _                       ' VTable offset = 48
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Subclasses_ <7> ( _                           ' VTable offset = 52
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD SubclassesAsync_ <8> ( _                      ' VTable offset = 56
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemQueryFlagDeep
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Associators_ <9> ( _                          ' VTable offset = 60
     OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD AssociatorsAsync_ <10> ( _                    ' VTable offset = 64
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD References_ <11> ( _                          ' VTable offset = 68
     OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ReferencesAsync_ <12> ( _                     ' VTable offset = 72
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecMethod_ <13> ( _                          ' VTable offset = 76
     BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   METHOD ExecMethodAsync_ <14> ( _                     ' VTable offset = 80
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters =  = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet =  = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext =  = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone_ <15> ( _                               ' VTable offset = 84
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD GetObjectText_ <16> ( _                       ' VTable offset = 88
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS WSTRING                                         ' __out_retval BSTR *strObjectText
   ' =====================================================================================
   METHOD SpawnDerivedClass_ <17> ( _                   ' VTable offset = 92
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD SpawnInstance_ <18> ( _                       ' VTable offset = 96
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD CompareTo_ <19> ( _                           ' VTable offset = 100
     BYVAL objWbemObject AS IDispatch _                 ' __in IDispatch *objWbemObject = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bResult
   ' =====================================================================================
   PROPERTY GET Qualifiers_ <20> ( _                    ' VTable offset = 104
   ) AS ISWbemQualifierSet                              ' __out_retval ISWbemQualifierSet **objWbemQualifierSet
   ' =====================================================================================
   PROPERTY GET Properties_ <21> ( _                    ' VTable offset = 108
   ) AS ISWbemPropertySet                               ' __out_retval ISWbemPropertySet **objWbemPropertySet
   ' =====================================================================================
   PROPERTY GET Methods_ <22> ( _                       ' VTable offset = 112
   ) AS ISWbemMethodSet                                 ' __out_retval ISWbemMethodSet **objWbemMethodSet
   ' =====================================================================================
   PROPERTY GET Derivation_ <23> ( _                    ' VTable offset = 116
   ) AS VARIANT                                         ' __out_retval VARIANT *strClassNameArray
   ' =====================================================================================
   PROPERTY GET Path_ <24> ( _                          ' VTable offset = 120
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   PROPERTY GET Security_ <25> ( _                      ' VTable offset = 124
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemObjectSet
' IID = {76A6415F-CB41-11D1-8B02-00600806D9B6}
' A collection of Classes or Instances
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemObjectSet_INTERFACE_DEFINED)
    %ISWbemObjectSet_INTERFACE_DEFINED = 1

INTERFACE ISWbemObjectSet $IID_ISWbemObjectSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   PROPERTY GET Security_ <4> ( _                       ' VTable offset = 40
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================
   METHOD ItemIndex <5> ( _                             ' VTable offset = 44
     BYVAL iFlags AS LONG _                             ' __in long lIndex
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemObjectSet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISWbemNamedValue
' IID = {76A64164-CB41-11D1-8B02-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemNamedValue_INTERFACE_DEFINED)
    %ISWbemNamedValue_INTERFACE_DEFINED = 1

INTERFACE ISWbemNamedValue $IID_ISWbemNamedValue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __out_retval VARIANT *varValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYREF IN varValue AS VARIANT _                     ' __in VARIANT *varValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *strName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemNamedValue_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemNamedValueSet
' IID = {CF2376EA-CE8C-11D1-8B05-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemNamedValueSet_INTERFACE_DEFINED)
    %ISWbemNamedValueSet_INTERFACE_DEFINED = 1

INTERFACE ISWbemNamedValueSet $IID_ISWbemNamedValueSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemNamedValue                                ' __out_retval ISWbemNamedValue **objWbemNamedValue
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYREF varValue AS VARIANT _                        ' __in VARIANT *varValue
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemNamedValue                                ' __out_retval ISWbemNamedValue **objWbemNamedValue
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <4> ( _                                 ' VTable offset = 48
   ) AS ISWbemNamedValueSet                             ' __out_retval ISWbemNamedValueSet **objWbemNamedValueSet
   ' =====================================================================================
   METHOD DeleteAll <5> ( _                             ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemNamedValueSet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemQualifier
' IID = {79B05932-D3B7-11D1-8B06-00600806D9B6}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemQualifier_INTERFACE_DEFINED)
    %ISWbemQualifier_INTERFACE_DEFINED = 1

INTERFACE ISWbemQualifier $IID_ISWbemQualifier

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __out_retval VARIANT *varValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYREF IN varValue AS VARIANT _                     ' __in VARIANT *varValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *strName
   ' =====================================================================================
   PROPERTY GET IsLocal <2> ( _                         ' VTable offset = 40
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsLocal
   ' =====================================================================================
   PROPERTY GET PropagatesToSubclass <3> ( _            ' VTable offset = 44
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bPropagatesToSubclass
   ' =====================================================================================
   PROPERTY SET PropagatesToSubclass <3> ( _            ' VTable offset = 48
     BYVAL bPropagatesToSubclass AS INTEGER _           ' __in VARIANT_BOOL bPropagatesToSubclass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropagatesToInstance <4> ( _            ' VTable offset = 52
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bPropagatesToInstance
   ' =====================================================================================
   PROPERTY SET PropagatesToInstance <4> ( _            ' VTable offset = 56
     BYVAL bPropagatesToInstance AS INTEGER _           ' __in VARIANT_BOOL bPropagatesToInstance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsOverridable <5> ( _                   ' VTable offset = 60
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsOverridable
   ' =====================================================================================
   PROPERTY SET IsOverridable <5> ( _                   ' VTable offset = 64
     BYVAL bIsOverridable AS INTEGER _                  ' __in VARIANT_BOOL bIsOverridable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAmended <6> ( _                       ' VTable offset = 68
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsAmended
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemQualifier_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemQualifierSet
' IID = {9B16ED16-D3DF-11D1-8B08-00600806D9B6}
' A collection of Qualifiers
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemQualifierSet_INTERFACE_DEFINED)
    %ISWbemQualifierSet_INTERFACE_DEFINED = 1

INTERFACE ISWbemQualifierSet $IID_ISWbemQualifierSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL name AS WSTRING _                                    ' __in BSTR name
   , OPTIONAL BYVAL iFlags AS LONG _                              ' __in_opt long iFlags = 0
   ) AS ISWbemQualifier                                 ' __out_retval ISWbemQualifier **objWbemQualifier
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYREF varVal AS VARIANT _                          ' __in VARIANT *varVal
   , OPTIONAL BYVAL bPropagatesToSubclass AS INTEGER _  ' __in_opt VARIANT_BOOL bPropagatesToSubclass = TRUE
   , OPTIONAL BYVAL bPropagatesToInstance AS INTEGER _  ' __in_opt VARIANT_BOOL bPropagatesToInstance = TRUE
   , OPTIONAL BYVAL bIsOverridable AS INTEGER _         ' __in_opt VARIANT_BOOL bIsOverridable = TRUE
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemQualifier                                 ' __out_retval ISWbemQualifier **objWbemQualifier
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemQualifierSet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemProperty
' IID = {1A388F98-D4BA-11D1-8B09-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemProperty_INTERFACE_DEFINED)
    %ISWbemProperty_INTERFACE_DEFINED = 1

INTERFACE ISWbemProperty $IID_ISWbemProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __out_retval VARIANT *varValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYREF IN varValue AS VARIANT _                     ' __in VARIANT *varValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *strName
   ' =====================================================================================
   PROPERTY GET IsLocal <2> ( _                         ' VTable offset = 40
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsLocal
   ' =====================================================================================
   PROPERTY GET Origin <3> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *strOrigin
   ' =====================================================================================
   PROPERTY GET CIMType <4> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __out_retval WbemCimtypeEnum *iCimType
   ' =====================================================================================
   PROPERTY GET Qualifiers_ <5> ( _                     ' VTable offset = 52
   ) AS ISWbemQualifierSet                              ' __out_retval ISWbemQualifierSet **objWbemQualifierSet
   ' =====================================================================================
   PROPERTY GET IsArray <6> ( _                         ' VTable offset = 56
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemPropertySet
' IID = {DEA0A7B2-D4BA-11D1-8B09-00600806D9B6}
' A collection of Properties
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemPropertySet_INTERFACE_DEFINED)
    %ISWbemPropertySet_INTERFACE_DEFINED = 1

INTERFACE ISWbemPropertySet $IID_ISWbemPropertySet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemProperty                                  ' __out_retval ISWbemProperty **objWbemProperty
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYVAL iCIMType AS LONG _                           ' __in WbemCimtypeEnum iCIMType
   , OPTIONAL BYVAL bIsArray AS INTEGER _               ' __in_opt VARIANT_BOOL bIsArray = FALSE
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemProperty                                  ' __out_retval ISWbemProperty **objWbemProperty
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemPropertySet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemMethod
' IID = {422E8E90-D955-11D1-8B09-00600806D9B6}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemMethod_INTERFACE_DEFINED)
    %ISWbemMethod_INTERFACE_DEFINED = 1

INTERFACE ISWbemMethod $IID_ISWbemMethod

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *strName
   ' =====================================================================================
   PROPERTY GET Origin <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __out_retval BSTR *strOrigin
   ' =====================================================================================
   PROPERTY GET InParameters <3> ( _                    ' VTable offset = 36
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemInParameters
   ' =====================================================================================
   PROPERTY GET OutParameters <4> ( _                   ' VTable offset = 40
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   PROPERTY GET Qualifiers_ <5> ( _                     ' VTable offset = 44
   ) AS ISWbemQualifierSet                              ' __out_retval ISWbemQualifierSet **objWbemQualifierSet
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemMethod_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemMethodSet
' IID = {C93BA292-D955-11D1-8B09-00600806D9B6}
' A collection of Methods
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemMethodSet_INTERFACE_DEFINED)
    %ISWbemMethodSet_INTERFACE_DEFINED = 1

INTERFACE ISWbemMethodSet $IID_ISWbemMethodSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemMethod                                    ' __out_retval ISWbemMethod **objWbemMethod
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemMethodSet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemEventSource
' IID = {27D54D92-0EBE-11D2-8B22-00600806D9B6}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemEventSource_INTERFACE_DEFINED)
    %ISWbemEventSource_INTERFACE_DEFINED = 1

INTERFACE ISWbemEventSource $IID_ISWbemEventSource

   INHERIT IDispatch

   ' =====================================================================================
   METHOD NextEvent <1> ( _                             ' VTable offset = 28
     OPTIONAL BYVAL iTimeoutMs AS LONG _                ' __in_opt long iTimeoutMs = wbemTimeoutInfinite
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   PROPERTY GET Security_ <2> ( _                       ' VTable offset = 32
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemEventSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemObjectPath
' IID = {5791BC27-CE9C-11D1-97BF-0000F81E849C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemObjectPath_INTERFACE_DEFINED)
    %ISWbemObjectPath_INTERFACE_DEFINED = 1

INTERFACE ISWbemObjectPath $IID_ISWbemObjectPath

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *strPath
   ' =====================================================================================
   PROPERTY SET Path <0> ( _                            ' VTable offset = 32
     BYVAL strPath AS WSTRING _                         ' __in BSTR strPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RelPath <1> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *strRelPath
   ' =====================================================================================
   PROPERTY SET RelPath <1> ( _                         ' VTable offset = 40
     BYVAL strRelPath AS WSTRING _                      ' __in BSTR strRelPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Server <2> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __out_retval BSTR *strServer
   ' =====================================================================================
   PROPERTY SET Server <2> ( _                          ' VTable offset = 48
     BYVAL strServer AS WSTRING _                       ' __in BSTR strServer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Namespace <3> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __out_retval BSTR *strNamespace
   ' =====================================================================================
   PROPERTY SET Namespace <3> ( _                       ' VTable offset = 56
     BYVAL strNamespace AS WSTRING _                    ' __in BSTR strNamespace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentNamespace <4> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __out_retval BSTR *strParentNamespace
   ' =====================================================================================
   PROPERTY GET DisplayName <5> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __out_retval BSTR *strDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <5> ( _                     ' VTable offset = 68
     BYVAL strDisplayName AS WSTRING _                  ' __in BSTR strDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Class <6> ( _                           ' VTable offset = 72
   ) AS WSTRING                                         ' __out_retval BSTR *strClass
   ' =====================================================================================
   PROPERTY SET Class <6> ( _                           ' VTable offset = 76
     BYVAL strClass AS WSTRING _                        ' __in BSTR strClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsClass <7> ( _                         ' VTable offset = 80
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsClass
   ' =====================================================================================
   METHOD SetAsClass <8> ( _                            ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsSingleton <9> ( _                     ' VTable offset = 88
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsSingleton
   ' =====================================================================================
   METHOD SetAsSingleton <10> ( _                       ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Keys <11> ( _                           ' VTable offset = 96
   ) AS ISWbemNamedValueSet                             ' __out_retval ISWbemNamedValueSet **objWbemNamedValueSet
   ' =====================================================================================
   PROPERTY GET Security_ <12> ( _                      ' VTable offset = 100
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================
   PROPERTY GET Locale <13> ( _                         ' VTable offset = 104
   ) AS WSTRING                                         ' __out_retval BSTR *strLocale
   ' =====================================================================================
   PROPERTY SET Locale <13> ( _                         ' VTable offset = 108
     BYVAL strLocale AS WSTRING _                       ' __in BSTR strLocale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Authority <14> ( _                      ' VTable offset = 112
   ) AS WSTRING                                         ' __out_retval BSTR *strAuthority
   ' =====================================================================================
   PROPERTY SET Authority <14> ( _                      ' VTable offset = 116
     BYVAL strAuthority AS WSTRING _                    ' __in BSTR strAuthority
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemObjectPath_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemLastError
' IID = {D962DB84-D4BB-11D1-8B09-00600806D9B6}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = ISWbemObject
' ########################################################################################

#IF NOT %DEF(%ISWbemLastError_INTERFACE_DEFINED)
    %ISWbemLastError_INTERFACE_DEFINED = 1

INTERFACE ISWbemLastError $IID_ISWbemLastError

   INHERIT IDispatch

   ' =====================================================================================
   ' ISWbemObject Methods
   ' =====================================================================================
   METHOD Put_ <1> ( _                                  ' VTable offset = 28
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   METHOD PutAsync_ <2> ( _                             ' VTable offset = 32
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemChangeFlagCreateOrUpdate
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete_ <3> ( _                               ' VTable offset = 36
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAsync_ <4> ( _                          ' VTable offset = 40
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Instances_ <5> ( _                            ' VTable offset = 44
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD InstancesAsync_ <6> ( _                       ' VTable offset = 48
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Subclasses_ <7> ( _                           ' VTable offset = 52
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD SubclassesAsync_ <8> ( _                      ' VTable offset = 56
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemQueryFlagDeep
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Associators_ <9> ( _                          ' VTable offset = 60
     OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD AssociatorsAsync_ <10> ( _                    ' VTable offset = 64
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD References_ <11> ( _                          ' VTable offset = 68
     OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ReferencesAsync_ <12> ( _                     ' VTable offset = 72
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecMethod_ <13> ( _                          ' VTable offset = 76
     BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   METHOD ExecMethodAsync_ <14> ( _                     ' VTable offset = 80
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters =  = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet =  = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext =  = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone_ <15> ( _                               ' VTable offset = 84
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD GetObjectText_ <16> ( _                       ' VTable offset = 88
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS WSTRING                                         ' __out_retval BSTR *strObjectText
   ' =====================================================================================
   METHOD SpawnDerivedClass_ <17> ( _                   ' VTable offset = 92
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD SpawnInstance_ <18> ( _                       ' VTable offset = 96
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD CompareTo_ <19> ( _                           ' VTable offset = 100
     BYVAL objWbemObject AS IDispatch _                 ' __in IDispatch *objWbemObject = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bResult
   ' =====================================================================================
   PROPERTY GET Qualifiers_ <20> ( _                    ' VTable offset = 104
   ) AS ISWbemQualifierSet                              ' __out_retval ISWbemQualifierSet **objWbemQualifierSet
   ' =====================================================================================
   PROPERTY GET Properties_ <21> ( _                    ' VTable offset = 108
   ) AS ISWbemPropertySet                               ' __out_retval ISWbemPropertySet **objWbemPropertySet
   ' =====================================================================================
   PROPERTY GET Methods_ <22> ( _                       ' VTable offset = 112
   ) AS ISWbemMethodSet                                 ' __out_retval ISWbemMethodSet **objWbemMethodSet
   ' =====================================================================================
   PROPERTY GET Derivation_ <23> ( _                    ' VTable offset = 116
   ) AS VARIANT                                         ' __out_retval VARIANT *strClassNameArray
   ' =====================================================================================
   PROPERTY GET Path_ <24> ( _                          ' VTable offset = 120
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   PROPERTY GET Security_ <25> ( _                      ' VTable offset = 124
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemLastError_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemSink
' IID = {75718C9F-F029-11D1-A1AC-00C04FB6C223}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemSink_INTERFACE_DEFINED)
    %ISWbemSink_INTERFACE_DEFINED = 1

INTERFACE ISWbemSink $IID_ISWbemSink

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Cancel <1> ( _                                ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemSecurity
' IID = {B54D66E6-2287-11D2-8B33-00600806D9B6}
' A Security Configurator
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemSecurity_INTERFACE_DEFINED)
    %ISWbemSecurity_INTERFACE_DEFINED = 1

INTERFACE ISWbemSecurity $IID_ISWbemSecurity

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ImpersonationLevel <1> ( _              ' VTable offset = 28
   ) AS LONG                                            ' __out_retval WbemImpersonationLevelEnum *iImpersonationLevel
   ' =====================================================================================
   PROPERTY SET ImpersonationLevel <1> ( _              ' VTable offset = 32
     BYVAL LONG _                                       ' __in WbemImpersonationLevelEnum iImpersonationLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationLevel <2> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __out_retval WbemAuthenticationLevelEnum *iAuthenticationLevel
   ' =====================================================================================
   PROPERTY SET AuthenticationLevel <2> ( _             ' VTable offset = 40
     BYVAL iAuthenticationLevel AS LONG _               ' __in WbemAuthenticationLevelEnum iAuthenticationLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Privileges <3> ( _                      ' VTable offset = 44
   ) AS ISWbemPrivilegeSet                              ' __out_retval ISWbemPrivilegeSet **objWbemPrivilegeSet
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemSecurity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemPrivilege
' IID = {26EE67BD-5804-11D2-8B4A-00600806D9B6}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemPrivilege_INTERFACE_DEFINED)
    %ISWbemPrivilege_INTERFACE_DEFINED = 1

INTERFACE ISWbemPrivilege $IID_ISWbemPrivilege

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsEnabled <0> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsEnabled
   ' =====================================================================================
   PROPERTY SET IsEnabled <0> ( _                       ' VTable offset = 32
     BYVAL bIsEnabled AS INTEGER _                      ' __in VARIANT_BOOL bIsEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __out_retval BSTR *strDisplayName
   ' =====================================================================================
   PROPERTY GET DisplayName <2> ( _                     ' VTable offset = 40
   ) AS WSTRING                                         ' __out_retval BSTR *strDisplayName
   ' =====================================================================================
   PROPERTY GET Identifier <3> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __out_retval WbemPrivilegeEnum *iPrivilege
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemPrivilege_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemPrivilegeSet
' IID = {26EE67BF-5804-11D2-8B4A-00600806D9B6}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemPrivilegeSet_INTERFACE_DEFINED)
    %ISWbemPrivilegeSet_INTERFACE_DEFINED = 1

INTERFACE ISWbemPrivilegeSet $IID_ISWbemPrivilegeSet

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL iPrivilege AS LONG _                         ' __in WbemPrivilegeEnum iPrivilege
   ) AS ISWbemPrivilege                                 ' __out_retval ISWbemPrivilege **objWbemPrivilege
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL iPrivilege AS LONG _                         ' __in WbemPrivilegeEnum iPrivilege
   , OPTIONAL BYVAL bIsEnabled AS INTEGER _             ' __in_opt VARIANT_BOOL bIsEnabled = TRUE
   ) AS ISWbemPrivilege                                 ' __out_retval ISWbemPrivilege **objWbemPrivilege
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL iPrivilege AS LONG _                         ' __in WbemPrivilegeEnum iPrivilege
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAll <4> ( _                             ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAsString <5> ( _                           ' VTable offset = 52
     BYVAL strPrivilege AS WSTRING _                    ' __in BSTR strPrivilege
   , OPTIONAL BYVAL bIsEnabled AS INTEGER _             ' __in_opt VARIANT_BOOL bIsEnabled = TRUE
   ) AS ISWbemPrivilege                                 ' __out_retval ISWbemPrivilege **objWbemPrivilege
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemPrivilegeSet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemServicesEx
' IID = {D2F68443-85DC-427E-91D8-366554CC754C}
' A connection to a Namespace
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISWbemServices
' ########################################################################################

#IF NOT %DEF(%ISWbemServicesEx_INTERFACE_DEFINED)
    %ISWbemServicesEx_INTERFACE_DEFINED = 1

INTERFACE ISWbemServicesEx $IID_ISWbemServicesEx

   INHERIT IDispatch

   ' =====================================================================================
   ' ISWbemServices Methods
   ' =====================================================================================
   METHOD Get <1> ( _                                   ' VTable offset = 28
     OPTIONAL BYVAL strObjectPath AS WSTRING _          ' __in_opt BSTR strObjectPath = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD GetAsync <2> ( _                              ' VTable offset = 32
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strObjectPath AS WSTRING _          ' __in_opt BSTR strObjectPath = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <3> ( _                                ' VTable offset = 36
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAsync <4> ( _                           ' VTable offset = 40
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD InstancesOf <5> ( _                           ' VTable offset = 44
     BYVAL strClass AS WSTRING _                        ' __in BSTR strClass
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD InstancesOfAsync <6> ( _                      ' VTable offset = 48
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strClass AS WSTRING _                        ' __in BSTR strClass
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD SubclassesOf <7> ( _                          ' VTable offset = 52
     OPTIONAL BYVAL strSuperclass AS WSTRING _          ' __in_opt BSTR strSuperclass = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD SubclassesOfAsync <8> ( _                     ' VTable offset = 56
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strSuperclass AS WSTRING _          ' __in_opt BSTR strSuperclass = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemQueryFlagDeep
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecQuery <9> ( _                             ' VTable offset = 60
     BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ExecQueryAsync <10> ( _                       ' VTable offset = 64
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL lFlags AS LONG _                    ' __in_opt long lFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD AssociatorsOf <11> ( _                        ' VTable offset = 68
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD AssociatorsOfAsync <12> ( _                   ' VTable offset = 72
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ReferencesTo <13> ( _                         ' VTable offset = 76
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnWhenComplete
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ReferencesToAsync <14> ( _                    ' VTable offset = 80
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecNotificationQuery <15> ( _                ' VTable offset = 84
     BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagForwardOnly + wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet
   ) AS ISWbemEventSource                               ' __out_retval ISWbemEventSource **objWbemEventSource
   ' =====================================================================================
   METHOD ExecNotificationQueryAsync <16> ( _           ' VTable offset = 88
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , OPTIONAL BYVAL strQueryLanguage AS WSTRING _       ' __in_opt BSTR strQueryLanguage = L"WQL"
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecMethod <17> ( _                           ' VTable offset = 92
     BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   METHOD ExecMethodAsync <18> ( _                      ' VTable offset = 96
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strObjectPath AS WSTRING _                   ' __in BSTR strObjectPath
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Security_ <19> ( _                      ' VTable offset = 100
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

   ' =====================================================================================
   ' ISWbemServicesEx Methods
   ' =====================================================================================
   METHOD Put <20> ( _                                  ' VTable offset = 104
     BYVAL objWbemObject AS ISWbemObjectEx _            ' __in ISWbemObjectEx *objWbemObject
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemChangeFlagCreateOrUpdate
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   METHOD PutAsync <21> ( _                             ' VTable offset = 108
     BYVAL objWbemSink AS ISWbemSink _                  ' __in ISWbemSink *objWbemSink
   , BYVAL objWbemObject AS ISWbemObjectEx _            ' __in ISWbemObjectEx *objWbemObject
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemChangeFlagCreateOrUpdate
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemServicesEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemObjectEx
' IID = {269AD56A-8A67-4129-BC8C-0506DCFE9880}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = ISWbemObject
' ########################################################################################

#IF NOT %DEF(%ISWbemObjectEx_INTERFACE_DEFINED)
    %ISWbemObjectEx_INTERFACE_DEFINED = 1

INTERFACE ISWbemObjectEx $IID_ISWbemObjectEx

   INHERIT IDispatch

   ' =====================================================================================
   ' ISWbemObject Methods
   ' =====================================================================================
   METHOD Put_ <1> ( _                                  ' VTable offset = 28
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   METHOD PutAsync_ <2> ( _                             ' VTable offset = 32
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemChangeFlagCreateOrUpdate
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete_ <3> ( _                               ' VTable offset = 36
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAsync_ <4> ( _                          ' VTable offset = 40
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Instances_ <5> ( _                            ' VTable offset = 44
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD InstancesAsync_ <6> ( _                       ' VTable offset = 48
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Subclasses_ <7> ( _                           ' VTable offset = 52
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD SubclassesAsync_ <8> ( _                      ' VTable offset = 56
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemQueryFlagDeep
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Associators_ <9> ( _                          ' VTable offset = 60
     OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD AssociatorsAsync_ <10> ( _                    ' VTable offset = 64
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strAssocClass AS WSTRING _          ' __in_opt BSTR strAssocClass = L""
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strResultRole AS WSTRING _          ' __in_opt BSTR strResultRole = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredAssocQualifier AS WSTRING _ ' __in_opt BSTR strRequiredAssocQualifier = L""
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD References_ <11> ( _                          ' VTable offset = 68
     OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = wbemFlagReturnImmediately
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD ReferencesAsync_ <12> ( _                     ' VTable offset = 72
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , OPTIONAL BYVAL strResultClass AS WSTRING _         ' __in_opt BSTR strResultClass = L""
   , OPTIONAL BYVAL strRole AS WSTRING _                ' __in_opt BSTR strRole = L""
   , OPTIONAL BYVAL bClassesOnly AS INTEGER _           ' __in_opt VARIANT_BOOL bClassesOnly = FALSE
   , OPTIONAL BYVAL bSchemaOnly AS INTEGER _            ' __in_opt VARIANT_BOOL bSchemaOnly = FALSE
   , OPTIONAL BYVAL strRequiredQualifier AS WSTRING _   ' __in_opt BSTR strRequiredQualifier = L""
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = 0
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecMethod_ <13> ( _                          ' VTable offset = 76
     BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemOutParameters
   ' =====================================================================================
   METHOD ExecMethodAsync_ <14> ( _                     ' VTable offset = 80
     BYVAL objWbemSink AS IDispatch _                   ' __in IDispatch *objWbemSink
   , BYVAL strMethodName AS WSTRING _                   ' __in BSTR strMethodName
   , OPTIONAL BYVAL objWbemInParameters AS IDispatch _  ' __in_opt IDispatch *objWbemInParameters =  = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet =  = NULL
   , OPTIONAL BYVAL objWbemAsyncContext AS IDispatch _  ' __in_opt IDispatch *objWbemAsyncContext =  = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone_ <15> ( _                               ' VTable offset = 84
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD GetObjectText_ <16> ( _                       ' VTable offset = 88
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS WSTRING                                         ' __out_retval BSTR *strObjectText
   ' =====================================================================================
   METHOD SpawnDerivedClass_ <17> ( _                   ' VTable offset = 92
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD SpawnInstance_ <18> ( _                       ' VTable offset = 96
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS ISWbemObject                                    ' __out_retval ISWbemObject **objWbemObject
   ' =====================================================================================
   METHOD CompareTo_ <19> ( _                           ' VTable offset = 100
     BYVAL objWbemObject AS IDispatch _                 ' __in IDispatch *objWbemObject = NULL
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bResult
   ' =====================================================================================
   PROPERTY GET Qualifiers_ <20> ( _                    ' VTable offset = 104
   ) AS ISWbemQualifierSet                              ' __out_retval ISWbemQualifierSet **objWbemQualifierSet
   ' =====================================================================================
   PROPERTY GET Properties_ <21> ( _                    ' VTable offset = 108
   ) AS ISWbemPropertySet                               ' __out_retval ISWbemPropertySet **objWbemPropertySet
   ' =====================================================================================
   PROPERTY GET Methods_ <22> ( _                       ' VTable offset = 112
   ) AS ISWbemMethodSet                                 ' __out_retval ISWbemMethodSet **objWbemMethodSet
   ' =====================================================================================
   PROPERTY GET Derivation_ <23> ( _                    ' VTable offset = 116
   ) AS VARIANT                                         ' __out_retval VARIANT *strClassNameArray
   ' =====================================================================================
   PROPERTY GET Path_ <24> ( _                          ' VTable offset = 120
   ) AS ISWbemObjectPath                                ' __out_retval ISWbemObjectPath **objWbemObjectPath
   ' =====================================================================================
   PROPERTY GET Security_ <25> ( _                      ' VTable offset = 124
   ) AS ISWbemSecurity                                  ' __out_retval ISWbemSecurity **objWbemSecurity
   ' =====================================================================================

   ' =====================================================================================
   ' ISWbemObjectEx Methods
   ' =====================================================================================
   METHOD Refresh_ <26> ( _                             ' VTable offset = 128
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SystemProperties_ <27> ( _              ' VTable offset = 132
   ) AS ISWbemPropertySet                               ' __out_retval ISWbemPropertySet **objWbemPropertySet
   ' =====================================================================================
   METHOD GetText_ <28> ( _                             ' VTable offset = 136
     BYVAL iObjectTextFormat AS LONG _                  ' __in WbemObjectTextFormatEnum iObjectTextFormat
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS WSTRING                                         ' __out_retval BSTR *bsText
   ' =====================================================================================
   METHOD SetFromText_ <29> ( _                         ' VTable offset = 140
     BYVAL bsText AS WSTRING _                          ' __in BSTR bsText
   , BYVAL iObjectTextFormat AS LONG _                  ' __in WbemObjectTextFormatEnum iObjectTextFormat
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemObjectEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemDateTime
' IID = {5E97458A-CF77-11D3-B38F-00105A1F473A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemDateTime_INTERFACE_DEFINED)
    %ISWbemDateTime_INTERFACE_DEFINED = 1

INTERFACE ISWbemDateTime $IID_ISWbemDateTime

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __out_retval BSTR *strValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Year <1> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iYear
   ' =====================================================================================
   PROPERTY SET Year <1> ( _                            ' VTable offset = 40
     BYVAL iYear AS LONG _                              ' __in long iYear
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET YearSpecified <2> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bYearSpecified
   ' =====================================================================================
   PROPERTY SET YearSpecified <2> ( _                   ' VTable offset = 48
     BYVAL bYearSpecified AS INTEGER _                  ' __in VARIANT_BOOL bYearSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Month <3> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __out_retval long *iMonth
   ' =====================================================================================
   PROPERTY SET Month <3> ( _                           ' VTable offset = 56
     BYVAL iMonth AS LONG _                             ' __in long iMonth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthSpecified <4> ( _                  ' VTable offset = 60
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bMonthSpecified
   ' =====================================================================================
   PROPERTY SET MonthSpecified <4> ( _                  ' VTable offset = 64
     BYVAL bMonthSpecified AS INTEGER _                 ' __in VARIANT_BOOL bMonthSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Day <5> ( _                             ' VTable offset = 68
   ) AS LONG                                            ' __out_retval long *iDay
   ' =====================================================================================
   PROPERTY SET Day <5> ( _                             ' VTable offset = 72
     BYVAL iDay AS LONG _                               ' __in long iDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaySpecified <6> ( _                    ' VTable offset = 76
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bDaySpecified
   ' =====================================================================================
   PROPERTY SET DaySpecified <6> ( _                    ' VTable offset = 80
     BYVAL bDaySpecified AS INTEGER _                   ' __in VARIANT_BOOL bDaySpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hours <7> ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __out_retval long *iHours
   ' =====================================================================================
   PROPERTY SET Hours <7> ( _                           ' VTable offset = 88
     BYVAL iHours AS LONG _                             ' __in long iHours
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HoursSpecified <8> ( _                  ' VTable offset = 92
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bHoursSpecified
   ' =====================================================================================
   PROPERTY SET HoursSpecified <8> ( _                  ' VTable offset = 96
     BYVAL bHoursSpecified AS INTEGER _                 ' __in VARIANT_BOOL bHoursSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Minutes <9> ( _                         ' VTable offset = 100
   ) AS LONG                                            ' __out_retval long *iMinutes
   ' =====================================================================================
   PROPERTY SET Minutes <9> ( _                         ' VTable offset = 104
     BYVAL iMinutes AS LONG _                           ' __in long iMinutes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinutesSpecified <10> ( _               ' VTable offset = 108
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bMinutesSpecified
   ' =====================================================================================
   PROPERTY SET MinutesSpecified <10> ( _               ' VTable offset = 112
     BYVAL bMinutesSpecified AS INTEGER _               ' __in VARIANT_BOOL bMinutesSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Seconds <11> ( _                        ' VTable offset = 116
   ) AS LONG                                            ' __out_retval long *iSeconds
   ' =====================================================================================
   PROPERTY SET Seconds <11> ( _                        ' VTable offset = 120
     BYVAL iSeconds AS LONG _                           ' __in long iSeconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecondsSpecified <12> ( _               ' VTable offset = 124
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bSecondsSpecified
   ' =====================================================================================
   PROPERTY SET SecondsSpecified <12> ( _               ' VTable offset = 128
     BYVAL bSecondsSpecified AS INTEGER _               ' __in VARIANT_BOOL bSecondsSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Microseconds <13> ( _                   ' VTable offset = 132
   ) AS LONG                                            ' __out_retval long *iMicroseconds
   ' =====================================================================================
   PROPERTY SET Microseconds <13> ( _                   ' VTable offset = 136
     BYVAL iMicroseconds AS LONG _                      ' __in long iMicroseconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MicrosecondsSpecified <14> ( _          ' VTable offset = 140
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bMicrosecondsSpecified
   ' =====================================================================================
   PROPERTY SET MicrosecondsSpecified <14> ( _          ' VTable offset = 144
     BYVAL bMicrosecondsSpecified AS INTEGER _          ' __in VARIANT_BOOL bMicrosecondsSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UTC <15> ( _                            ' VTable offset = 148
   ) AS LONG                                            ' __out_retval long *iUTC
   ' =====================================================================================
   PROPERTY SET UTC <15> ( _                            ' VTable offset = 152
     BYVAL iUTC AS LONG _                               ' __in long iUTC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UTCSpecified <16> ( _                   ' VTable offset = 156
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bUTCSpecified
   ' =====================================================================================
   PROPERTY SET UTCSpecified <16> ( _                   ' VTable offset = 160
     BYVAL bUTCSpecified AS INTEGER _                   ' __in VARIANT_BOOL bUTCSpecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsInterval <17> ( _                     ' VTable offset = 164
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsInterval
   ' =====================================================================================
   PROPERTY SET IsInterval <17> ( _                     ' VTable offset = 168
     BYVAL bIsInterval AS INTEGER _                     ' __in VARIANT_BOOL bIsInterval
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVarDate <18> ( _                           ' VTable offset = 172
     OPTIONAL BYVAL bIsLocal AS INTEGER _               ' __in_opt VARIANT_BOOL bIsLocal
   ) AS DOUBLE                                          ' __out_retval DATE *dVarDate
   ' =====================================================================================
   METHOD SetVarDate <19> ( _                           ' VTable offset = 176
     BYVAL dVarDate AS DOUBLE _                         ' __in DATE dVarDate
   , OPTIONAL BYVAL bIsLocal AS INTEGER _               ' __in_opt VARIANT_BOOL bIsLocal = TRUE
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFileTime <20> ( _                          ' VTable offset = 180
     OPTIONAL BYVAL bIsLocal AS INTEGER _               ' __in_opt VARIANT_BOOL bIsLocal = TRUE
   ) AS WSTRING                                         ' __out_retval BSTR *strFileTime
   ' =====================================================================================
   METHOD SetFileTime <21> ( _                          ' VTable offset = 184
     BYVAL strFileTime AS WSTRING _                     ' __in BSTR strFileTime
   , OPTIONAL BYVAL bIsLocal AS INTEGER _               ' __in_opt VARIANT_BOOL bIsLocal = TRUE
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemDateTime_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemRefresher
' IID = {14D8250E-D9C2-11D3-B38F-00105A1F473A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemRefresher_INTERFACE_DEFINED)
    %ISWbemRefresher_INTERFACE_DEFINED = 1

INTERFACE ISWbemRefresher $IID_ISWbemRefresher

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __out_retval IUnknown **pUnk
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL iIndex AS LONG _                             ' __in long iIndex
   ) AS ISWbemRefreshableItem                           ' __out_retval ISWbemRefreshableItem **objWbemRefreshableItem
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __out_retval long *iCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL objWbemServices AS ISWbemServicesEx _        ' __in ISWbemServicesEx *objWbemServices
   , BYVAL bsInstancePath AS WSTRING _                  ' __in BSTR bsInstancePath
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemRefreshableItem                           ' __out_retval ISWbemRefreshableItem **objWbemRefreshableItem
   ' =====================================================================================
   METHOD AddEnum ( _                                   ' VTable offset = 44
     BYVAL objWbemServices AS ISWbemServicesEx _        ' __in ISWbemServicesEx *objWbemServices
   , BYVAL bsClassName AS WSTRING _                     ' __in BSTR bsClassName
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   , OPTIONAL BYVAL objWbemNamedValueSet AS IDispatch _ ' __in_opt IDispatch *objWbemNamedValueSet = NULL
   ) AS ISWbemRefreshableItem                           ' __out_retval ISWbemRefreshableItem **objWbemRefreshableItem
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 48
     BYVAL iIndex AS LONG _                             ' __in long iIndex
   , OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <5> ( _                               ' VTable offset = 52
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoReconnect <6> ( _                   ' VTable offset = 56
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bCount
   ' =====================================================================================
   PROPERTY SET AutoReconnect <6> ( _                   ' VTable offset = 60
     BYVAL bCount AS INTEGER _                          ' __in VARIANT_BOOL bCount
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAll <7> ( _                             ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemRefresher_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISWbemRefreshableItem
' IID = {5AD4BF92-DAAB-11D3-B38F-00105A1F473A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISWbemRefreshableItem_INTERFACE_DEFINED)
    %ISWbemRefreshableItem_INTERFACE_DEFINED = 1

INTERFACE ISWbemRefreshableItem $IID_ISWbemRefreshableItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Index <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __out_retval long *iIndex
   ' =====================================================================================
   PROPERTY GET Refresher <2> ( _                       ' VTable offset = 32
   ) AS ISWbemRefresher                                 ' __out_retval ISWbemRefresher **objWbemRefresher
   ' =====================================================================================
   PROPERTY GET IsSet <3> ( _                           ' VTable offset = 36
   ) AS INTEGER                                         ' __out_retval VARIANT_BOOL *bIsSet
   ' =====================================================================================
   PROPERTY GET Object <4> ( _                          ' VTable offset = 40
   ) AS ISWbemObjectEx                                  ' __out_retval ISWbemObjectEx **objWbemObject
   ' =====================================================================================
   PROPERTY GET ObjectSet <5> ( _                       ' VTable offset = 44
   ) AS ISWbemObjectSet                                 ' __out_retval ISWbemObjectSet **objWbemObjectSet
   ' =====================================================================================
   METHOD Remove <6> ( _                                ' VTable offset = 48
     OPTIONAL BYVAL iFlags AS LONG _                    ' __in_opt long iFlags = 0
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISWbemRefreshableItem_INTERFACE_DEFINED__ */
