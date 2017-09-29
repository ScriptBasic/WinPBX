' ########################################################################################
' Microsoft Windows
' File: ComSvcs.inc
' Contents: Prototypes for the APIs and COM interface for applications using COM+ Services.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMSVCS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "comadmin.inc"
#INCLUDE ONCE "transact.inc"
#INCLUDE ONCE "txdtc.inc"
#INCLUDE ONCE "objbase.inc"

' ########################################################################################
' Library name: COMSVCSLib
' Version: 1.0, Locale ID = 0
' Documentation string: COM+ Services Type Library
' Path: C:\WINDOWS\system32\COMSVCS.DLL
' Library GUID: {2A005C00-A5DE-11CF-9E66-00AA00A3F464}
' Help file: C:\WINDOWS\system32\cossdk.chm
' ########################################################################################

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {ECABB0AA-7F19-11D2-978E-0000F8757E2A}
$PROGID_ByotServerExByotServerEx = "Byot.ByotServerEx"
' CLSID = {ECABB0C8-7F19-11D2-978E-0000F8757E2A}
$PROGID_CServiceConfig1 = "COMSVCS.CServiceConfig.1"
' CLSID = {ECABAFB9-7F19-11D2-978E-0000F8757E2A}
$PROGID_TrackerServerTrackerServer = "COMSVCS.TrackerServer"
' CLSID = {ECABB0BD-7F19-11D2-978E-0000F8757E2A}
$PROGID_CRMClerk1 = "CrmClerk.CrmClerk.1"
' CLSID = {ECABB0BE-7F19-11D2-978E-0000F8757E2A}
$PROGID_CRMRecoveryClerk1 = "CrmRecoveryClerk.CrmRecoveryClerk.1"
' CLSID = {ECABAFBC-7F19-11D2-978E-0000F8757E2A}
$PROGID_EventServerEventPublisher = "EventPublisher.EventPublisher"
' CLSID = {4B2E958D-0393-11D1-B1AB-00AA00BA3258}
$PROGID_MtsGrpMtsGrp = "Mts.MtsGrp"
' CLSID = {71E38F91-7E88-11CF-9EDE-0080C78B7F89}
$PROGID_AppServer1 = "MTxAS.AppServer.1"
' CLSID = {2A005C11-A5DE-11CF-9E66-00AA00A3F464}
$PROGID_SharedPropertyGroupManager1 = "MTxSpm.SharedPropertyGroupManager.1"
' CLSID = {ECABB0C5-7F19-11D2-978E-0000F8757E2A}
$PROGID_PartitionMoniker = "partition"
' CLSID = {ECABB0C4-7F19-11D2-978E-0000F8757E2A}
$PROGID_ProcessDumpProcessDump = "Pdump.ProcessDump"
' CLSID = {ECABB0BF-7F19-11D2-978E-0000F8757E2A}
$PROGID_MessageMover1 = "QC.MessageMover.1"
' CLSID = {ECABB0C7-7F19-11D2-978E-0000F8757E2A}
$PROGID_SoapMoniker = "soap"
' CLSID = {EF24F689-14F8-4D92-B4AF-D7B1F0E70FD4}
$PROGID_AppDomainHelperAppDomainHelper = "System.EnterpriseServices.Internal.AppDomainHelper"
' CLSID = {458AA3B5-265A-4B75-BC05-9BEA4630CF18}
$PROGID_ClrAssemblyLocatorAssemblyLocator = "System.EnterpriseServices.Internal.AssemblyLocator"
' CLSID = {7999FC25-D3C6-11CF-ACAB-00A024A55AEF}
$PROGID_TransactionContextTransactionContext = "TxCTx.TransactionContext"
' CLSID = {5CB66670-D3D4-11CF-ACAB-00A024A55AEF}
$PROGID_TransactionContextExTransactionContextEx = "TxCTx.TransactionContextEx"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {ECABB0C8-7F19-11D2-978E-0000F8757E2A}
$PROGID_CServiceConfig = "COMSVCS.CServiceConfig"
' CLSID = {ECABB0BD-7F19-11D2-978E-0000F8757E2A}
$PROGID_CRMClerk = "CrmClerk.CrmClerk"
' CLSID = {ECABB0BE-7F19-11D2-978E-0000F8757E2A}
$PROGID_CRMRecoveryClerk = "CrmRecoveryClerk.CrmRecoveryClerk"
' CLSID = {2A005C11-A5DE-11CF-9E66-00AA00A3F464}
$PROGID_SharedPropertyGroupManager = "MTxSpm.SharedPropertyGroupManager"
' CLSID = {ECABB0BF-7F19-11D2-978E-0000F8757E2A}
$PROGID_MessageMover = "QC.MessageMover"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Dummy30040732 = GUID$("{ECABB0A9-7F19-11D2-978E-0000F8757E2A}")
$CLSID_LBEvents = GUID$("{ECABB0C1-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SecurityCallContext = GUID$("{ECABB0A7-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SecurityCallers = GUID$("{ECABB0A6-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SecurityCertificate = GUID$("{ECABB0A4-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SecurityIdentity = GUID$("{ECABB0A5-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SharedProperty = GUID$("{2A005C05-A5DE-11CF-9E66-00AA00A3F464}")
$CLSID_SharedPropertyGroup = GUID$("{2A005C0B-A5DE-11CF-9E66-00AA00A3F464}")
$CLSID_ByotServerEx = GUID$("{ECABB0AA-7F19-11D2-978E-0000F8757E2A}")
$CLSID_ComServiceEvents = GUID$("{ECABB0C3-7F19-11D2-978E-0000F8757E2A}")
$CLSID_ComSystemAppEventData = GUID$("{ECABB0C6-7F19-11D2-978E-0000F8757E2A}")
$CLSID_CServiceConfig = GUID$("{ECABB0C8-7F19-11D2-978E-0000F8757E2A}")
$CLSID_DispenserManager = GUID$("{ECABB0C0-7F19-11D2-978E-0000F8757E2A}")
$CLSID_PoolMgr = GUID$("{ECABAFB5-7F19-11D2-978E-0000F8757E2A}")
$CLSID_TrackerServer = GUID$("{ECABAFB9-7F19-11D2-978E-0000F8757E2A}")
$CLSID_GetSecurityCallContextAppObject = GUID$("{ECABB0A8-7F19-11D2-978E-0000F8757E2A}")
$CLSID_CRMClerk = GUID$("{ECABB0BD-7F19-11D2-978E-0000F8757E2A}")
$CLSID_CRMRecoveryClerk = GUID$("{ECABB0BE-7F19-11D2-978E-0000F8757E2A}")
$CLSID_EventServer = GUID$("{ECABAFBC-7F19-11D2-978E-0000F8757E2A}")
$CLSID_COMEvents = GUID$("{ECABB0AB-7F19-11D2-978E-0000F8757E2A}")
$CLSID_MtsGrp = GUID$("{4B2E958D-0393-11D1-B1AB-00AA00BA3258}")
$CLSID_CoMTSLocator = GUID$("{ECABB0AC-7F19-11D2-978E-0000F8757E2A}")
$CLSID_AppServer = GUID$("{71E38F91-7E88-11CF-9EDE-0080C78B7F89}")
$CLSID_SharedPropertyGroupManager = GUID$("{2A005C11-A5DE-11CF-9E66-00AA00A3F464}")
$CLSID_PartitionMoniker = GUID$("{ECABB0C5-7F19-11D2-978E-0000F8757E2A}")
$CLSID_ProcessDump = GUID$("{ECABB0C4-7F19-11D2-978E-0000F8757E2A}")
$CLSID_MessageMover = GUID$("{ECABB0BF-7F19-11D2-978E-0000F8757E2A}")
$CLSID_SoapMoniker = GUID$("{ECABB0C7-7F19-11D2-978E-0000F8757E2A}")
$CLSID_TransactionContext = GUID$("{7999FC25-D3C6-11CF-ACAB-00A024A55AEF}")
$CLSID_TransactionContextEx = GUID$("{5CB66670-D3D4-11CF-ACAB-00A024A55AEF}")
$CLSID_ServicePool = GUID$("{ECABB0C9-7F19-11D2-978E-0000F8757E2A}")
$CLSID_ServicePoolConfig = GUID$("{ECABB0CA-7F19-11D2-978E-0000F8757E2A}")
$CLSID_AppDomainHelper = GUID$("{EF24F689-14F8-4D92-B4AF-D7B1F0E70FD4}")
$CLSID_ClrAssemblyLocator = GUID$("{458AA3B5-265A-4B75-BC05-9BEA4630CF18}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ContextInfo = GUID$("{19A5A02C-0AC8-11D2-B286-00C04F8EF934}")
$IID_ContextInfo2 = GUID$("{C99D6E75-2375-11D4-8331-00C04F605588}")
$IID_IAsyncErrorNotify = GUID$("{FE6777FB-A674-4177-8F32-6D707E113484}")
$IID_ICheckFusionConfig = GUID$("{0FF5A96F-11FC-47D1-BAA6-25DD347E7242}")
$IID_IComActivityEvents = GUID$("{683130B0-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComApp2Events = GUID$("{1290BC1A-B219-418D-B078-5934DED08242}")
$IID_IComAppEvents = GUID$("{683130A6-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComCRMEvents = GUID$("{683130B5-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComExceptionEvents = GUID$("{683130B3-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComIdentityEvents = GUID$("{683130B1-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComInstance2Events = GUID$("{20E3BF07-B506-4AD5-A50C-D2CA5B9C158E}")
$IID_IComInstanceEvents = GUID$("{683130A7-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComLTxEvents = GUID$("{605CF82C-578E-4298-975D-82BABCD9E053}")
$IID_IComMethod2Events = GUID$("{FB388AAA-567D-4024-AF8E-6E93EE748573}")
$IID_IComMethodEvents = GUID$("{683130A9-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComObjectConstruction2Events = GUID$("{4B5A7827-8DF2-45C0-8F6F-57EA1F856A9F}")
$IID_IComObjectConstructionEvents = GUID$("{683130AF-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComObjectEvents = GUID$("{683130AA-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComObjectPool2Events = GUID$("{65BF6534-85EA-4F64-8CF4-3D974B2AB1CF}")
$IID_IComObjectPoolEvents = GUID$("{683130AD-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComObjectPoolEvents2 = GUID$("{683130AE-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComQCEvents = GUID$("{683130B2-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComResourceEvents = GUID$("{683130AB-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComSecurityEvents = GUID$("{683130AC-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComThreadEvents = GUID$("{683130A5-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComTrackingInfoCollection = GUID$("{c266c677-c9ad-49ab-9fd9-d9661078588a}")
$IID_IComTrackingInfoObject = GUID$("{116e42c5-d8b1-47bf-ab1e-c895ed3e2372}")
$IID_IComTrackingInfoEvents = GUID$("{4E6CDCC9-FB25-4FD5-9CC5-C9F4B6559CEC}")
$IID_IComTrackingInfoProperties = GUID$("{789b42be-6f6b-443a-898e-67abf390aa14}")
$IID_IComTransaction2Events = GUID$("{A136F62A-2F94-4288-86E0-D8A1FA4C0299}")
$IID_IComTransactionEvents = GUID$("{683130A8-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IComUserEvent = GUID$("{683130A4-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IContextState = GUID$("{3C05E54B-A42A-11D2-AFC4-00C04F8EE1C4}")
$IID_ICreateWithLocalTransaction = GUID$("{227AC7A8-8423-42CE-B7CF-03061EC9AAA3}")
$IID_ICreateWithTipTransactionEx = GUID$("{455ACF59-5345-11D2-99CF-00C04F797BC9}")
$IID_ICreateWithTransactionEx = GUID$("{455ACF57-5345-11D2-99CF-00C04F797BC9}")
$IID_ICrmCompensator = GUID$("{BBC01830-8D3B-11D1-82EC-00A0C91EEDE9}")
$IID_ICrmCompensatorVariants = GUID$("{F0BAF8E4-7804-11D1-82E9-00A0C91EEDE9}")
$IID_ICrmFormatLogRecords = GUID$("{9C51D821-C98B-11D1-82FB-00A0C91EEDE9}")
$IID_ICrmLogControl = GUID$("{A0E174B3-D26E-11D2-8F84-00805FC7BCD9}")
$IID_ICrmMonitor = GUID$("{70C8E443-C7ED-11D1-82FB-00A0C91EEDE9}")
$IID_ICrmMonitorClerks = GUID$("{70C8E442-C7ED-11D1-82FB-00A0C91EEDE9}")
$IID_ICrmMonitorLogRecords = GUID$("{70C8E441-C7ED-11D1-82FB-00A0C91EEDE9}")
$IID_IDispenserDriver = GUID$("{208B3651-2B48-11CF-BE10-00AA00A2FA25}")
$IID_IDispenserManager = GUID$("{5CB31E10-2B5F-11CF-BE10-00AA00A2FA25}")
$IID_IDispenserManagerShutdownGuarantee = GUID$("{5CB31E11-2B5F-11CF-BE10-00AA00A2FA25}")
$IID_IEventServer = GUID$("{F1CB0608-EC04-11D1-93AE-00AA00BA3258}")
$IID_IEventServer2 = GUID$("{378F3CA7-BD24-481C-8DC3-5E5ECE1BCAD7}")
$IID_IEventServerTrace = GUID$("{9A9F12B8-80AF-47AB-A579-35EA57725370}")
$IID_IGetAppData = GUID$("{B60040E0-BCF3-11D1-861D-0080C729264D}")
$IID_IGetSecurityCallContext = GUID$("{CAFC823F-B441-11D1-B82B-0000F8757E2A}")
$IID_IHolder = GUID$("{BF6A1850-2B45-11CF-BE10-00AA00A2FA25}")
$IID_ILBEvents = GUID$("{683130B4-2E50-11D2-98A5-00C04F8EE1C4}")
$IID_IMessageMover = GUID$("{588A085A-B795-11D1-8054-00C04FC340EE}")
$IID_IMtsEventInfo = GUID$("{D56C3DC1-8482-11D0-B170-00AA00BA3258}")
$IID_IMtsEvents = GUID$("{BACEDF4D-74AB-11D0-B162-00AA00BA3258}")
$IID_IMtsGrp = GUID$("{4B2E958C-0393-11D1-B1AB-00AA00BA3258}")
$IID_IMTSLocator = GUID$("{D19B8BFD-7F88-11D0-B16E-00AA00BA3258}")
$IID_IMTxAS = GUID$("{74C08641-CEDB-11CF-8B49-00AA00B8A790}")
$IID_IObjectConstruct = GUID$("{41C4F8B3-7439-11D2-98CB-00C04F8EE1C4}")
$IID_IObjectConstructString = GUID$("{41C4F8B2-7439-11D2-98CB-00C04F8EE1C4}")
$IID_IObjectContext = GUID$("{51372AE0-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IObjectContextActivity = GUID$("{51372AFC-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IObjectContextInfo = GUID$("{75B52DDB-E8ED-11D1-93AD-00AA00BA3258}")
$IID_IObjectContextTip = GUID$("{92FD41CA-BAD9-11D2-9A2D-00C04F797BC9}")
$IID_IObjectControl = GUID$("{51372AEC-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IPlaybackControl = GUID$("{51372AFD-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IPoolManager = GUID$("{0A469861-5A91-43A0-99B6-D5E179BB0631}")
$IID_IProcessDump = GUID$("{23C9DD26-2355-4FE2-84DE-F779A238ADBD}")
$IID_IProcessTerminateNotify = GUID$("{3194B4CF-EF32-11D1-93AE-00AA00BA3258}")
$IID_IReceiveAppData = GUID$("{413DAFB0-BCF4-11D1-861D-0080C729264D}")
$IID_ISecurityCallContext = GUID$("{CAFC823E-B441-11D1-B82B-0000F8757E2A}")
$IID_ISecurityCallersColl = GUID$("{CAFC823D-B441-11D1-B82B-0000F8757E2A}")
$IID_ISecurityCertificateColl = GUID$("{CAFC823B-B441-11D1-B82B-0000F8757E2A}")
$IID_ISecurityIdentityColl = GUID$("{CAFC823C-B441-11D1-B82B-0000F8757E2A}")
$IID_ISecurityProperty = GUID$("{51372AEA-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IServiceActivity = GUID$("{67532E0C-9E2F-4450-A354-035633944E17}")
$IID_IServiceCall = GUID$("{BD3E2E12-42DD-40F4-A09A-95A50C58304B}")
$IID_IServiceComTIIntrinsicsConfig = GUID$("{09E6831E-04E1-4ED4-9D0F-E8B168BAFEAF}")
$IID_IServiceIISIntrinsicsConfig = GUID$("{1A0CF920-D452-46F4-BC36-48118D54EA52}")
$IID_IServiceInheritanceConfig = GUID$("{92186771-D3B4-4D77-A8EA-EE842D586F35}")
$IID_IServicePartitionConfig = GUID$("{80182D03-5EA4-4831-AE97-55BEFFC2E590}")
$IID_IServiceSxsConfig = GUID$("{C7CD7379-F3F2-4634-811B-703281D73E08}")
$IID_IServiceSynchronizationConfig = GUID$("{FD880E81-6DCE-4C58-AF83-A208846C0030}")
$IID_IServiceThreadPoolConfig = GUID$("{186D89BC-F277-4BCC-80D5-4DF7B836EF4A}")
$IID_IServiceTrackerConfig = GUID$("{6C3A3E1D-0BA6-4036-B76F-D0404DB816C9}")
$IID_IServiceTransactionConfig = GUID$("{59F4C2A3-D3D7-4A31-B6E4-6AB3177C50B9}")
$IID_IServiceTransactionConfigBase = GUID$("{772B3FBE-6FFD-42FB-B5F8-8F9B260F3810}")
$IID_ISharedProperty = GUID$("{2A005C01-A5DE-11CF-9E66-00AA00A3F464}")
$IID_ISharedPropertyGroup = GUID$("{2A005C07-A5DE-11CF-9E66-00AA00A3F464}")
$IID_ISharedPropertyGroupManager = GUID$("{2A005C0D-A5DE-11CF-9E66-00AA00A3F464}")
$IID_ISystemAppEventData = GUID$("{D6D48A3C-D5C5-49E7-8C74-99E4889ED52F}")
$IID_ITransactionContext = GUID$("{7999FC21-D3C6-11CF-ACAB-00A024A55AEF}")
$IID_ITransactionContextEx = GUID$("{7999FC22-D3C6-11CF-ACAB-00A024A55AEF}")
$IID_ITransactionStatus = GUID$("{61F589E8-3724-4898-A0A4-664AE9E1D1B4}")
$IID_ObjectContext = GUID$("{74C08646-CEDB-11CF-8B49-00AA00B8A790}")
$IID_ObjectControl = GUID$("{7DC41850-0C31-11D0-8B79-00AA00B8A790}")
$IID_SecurityProperty = GUID$("{E74A7215-014D-11D1-A63C-00A0C911B4E0}")

$IID_IEnumNames = GUID$("{51372af2-cae7-11cf-be81-00aa00a2fa25}")
$IID_IObjectContextInfo2 = GUID$("{594BE71A-4BC4-438b-9197-CFD176248B09}")
$IID_IGetContextProperties = GUID$("{51372af4-cae7-11cf-be81-00aa00a2fa25}")
$IID_ISelectCOMLBServer = GUID$("{dcf443f4-3f8a-4872-b9f0-369a796d12d6}")
$IID_ICOMLBArguments = GUID$("{3a0f150f-8ee5-4b94-b40e-aef2f9e42ed2}")
$IID_ICheckSxsConfig = GUID$("{0FF5A96F-11FC-47d1-BAA6-25DD347E7242}")
$IID_IThreadPoolKnobs = GUID$("{51372af7-cae7-11cf-be81-00aa00a2fa25}")
$IID_IComStaThreadPoolKnobs = GUID$("{324B64FA-33B6-11d2-98B7-00C04F8EE1C4}")
$IID_IComMtaThreadPoolKnobs = GUID$("{F9A76D2E-76A5-43eb-A0C4-49BEC8E48480}")
$IID_IComStaThreadPoolKnobs2 = GUID$("{73707523-FF9A-4974-BF84-2108DC213740}")
$IID_IProcessInitializer = GUID$("{1113f52d-dc7f-4943-aed6-88d04027e32a}")
$IID_IServicePoolConfig = GUID$("{a9690656-5bca-470c-8451-250c1f43a33e}")
$IID_IServicePool = GUID$("{b302df81-ea45-451e-99a2-09f9fd1b1e13}")
$IID_IManagedPooledObj = GUID$("{c5da4bea-1b42-4437-8926-b6a38860a770}")
$IID_IManagedPoolAction = GUID$("{da91b74e-5388-4783-949d-c1cd5fb00506}")
$IID_IManagedObjectInfo = GUID$("{1427c51a-4584-49d8-90a0-c50d8086cbe9}")
$IID_IAppDomainHelper = GUID$("{c7b67079-8255-42c6-9ec0-6994a3548780}")
$IID_IAssemblyLocator = GUID$("{391ffbb9-a8ee-432a-abc8-baa238dab90f}")
$IID_IManagedActivationEvents = GUID$("{a5f325af-572f-46da-b8ab-827c3d95d99e}")
$IID_ISendMethodEvents = GUID$("{2732fd59-b2b4-4d44-878c-8b8f09626008}")
$IID_ITransactionResourcePool = GUID$("{C5FEB7C1-346A-11D1-B1CC-00AA00BA3258}")
$IID_IMTSCall = GUID$("{51372AEF-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_IContextProperties = GUID$("{D396DA85-BF8F-11d1-BBAE-00C04FC2FA5F}")
$IID_IObjPool = GUID$("{7D8805A0-2EA7-11D1-B1CC-00AA00BA3258}")
$IID_ITransactionProperty = GUID$("{788ea814-87b1-11d1-bba6-00c04fc2fa5f}")
$IID_IMTSActivity = GUID$("{51372AF0-CAE7-11CF-BE81-00AA00A2FA25}")
$IID_ITransactionProxy = GUID$("{02558374-DF2E-4DAE-BD6B-1D5C994F9BDC}")
$IID_IContextSecurityPerimeter = GUID$("{A7549A29-A7C4-42E1-8DC1-7E3D748DC24A}")
$IID_ITxProxyHolder = GUID$("{13D86F31-0139-41AF-BCAD-C7D50435FE9F}")
$IID_IServiceSysTxnConfig = GUID$("{33CAF1A1-FCB8-472B-B45E-967448DED6D8}")
$IID_IGetAppTrackerData = GUID$("{507C3AC8-3E12-4CB0-9366-653D3E050638}")


' ########################################################################################
' Interface name = ISecurityIdentityColl
' IID = {CAFC823C-B441-11D1-B82B-0000F8757E2A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISecurityIdentityColl_INTERFACE_DEFINED)
    %ISecurityIdentityColl_INTERFACE_DEFINED = 1

INTERFACE ISecurityIdentityColl $IID_ISecurityIdentityColl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pItem
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityIdentityColl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISecurityCallersColl
' IID = {CAFC823D-B441-11D1-B82B-0000F8757E2A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISecurityCallersColl_INTERFACE_DEFINED)
    %ISecurityCallersColl_INTERFACE_DEFINED = 1

INTERFACE ISecurityCallersColl $IID_ISecurityCallersColl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS ISecurityIdentityColl                           ' __retval_out ISecurityIdentityColl **pObj
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityCallersColl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISecurityCallContext
' IID = {CAFC823E-B441-11D1-B82B-0000F8757E2A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISecurityCallContext_INTERFACE_DEFINED)
    %ISecurityCallContext_INTERFACE_DEFINED = 1

INTERFACE ISecurityCallContext $IID_ISecurityCallContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743813> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pItem
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD IsCallerInRole <1610743814> ( _               ' VTable offset = 40
     BYVAL bstrRole AS WSTRING _                        ' __in BSTR bstrRole
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfInRole
   ' =====================================================================================
   METHOD IsSecurityEnabled <1610743815> ( _            ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsEnabled
   ' =====================================================================================
   METHOD IsUserInRole <1610743816> ( _                 ' VTable offset = 48
     BYREF pUser AS VARIANT _                           ' __in VARIANT *pUser
   , BYVAL bstrRole AS WSTRING _                        ' __in BSTR bstrRole
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfInRole
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityCallContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetSecurityCallContext
' IID = {CAFC823F-B441-11D1-B82B-0000F8757E2A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGetSecurityCallContext_INTERFACE_DEFINED)
    %IGetSecurityCallContext_INTERFACE_DEFINED = 1

INTERFACE IGetSecurityCallContext $IID_IGetSecurityCallContext

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetSecurityCallContext <1610743808> ( _       ' VTable offset = 28
   ) AS ISecurityCallContext                            ' __retval_out ISecurityCallContext **ppObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetSecurityCallContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = SecurityProperty
' IID = {E74A7215-014D-11D1-A63C-00A0C911B4E0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%SecurityProperty_INTERFACE_DEFINED)
    %SecurityProperty_INTERFACE_DEFINED = 1

INTERFACE SecurityProperty $IID_SecurityProperty

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetDirectCallerName <1610743808> ( _          ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *bstrUserName
   ' =====================================================================================
   METHOD GetDirectCreatorName <1610743809> ( _         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *bstrUserName
   ' =====================================================================================
   METHOD GetOriginalCallerName <1610743810> ( _        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *bstrUserName
   ' =====================================================================================
   METHOD GetOriginalCreatorName <1610743811> ( _       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *bstrUserName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __SecurityProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ContextInfo
' IID = {19A5A02C-0AC8-11D2-B286-00C04F8EF934}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ContextInfo_INTERFACE_DEFINED)
    %ContextInfo_INTERFACE_DEFINED = 1

INTERFACE ContextInfo $IID_ContextInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsInTransaction <100671488> ( _               ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsInTx
   ' =====================================================================================
   METHOD GetTransaction <1610743811> ( _               ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppTx
   ' =====================================================================================
   METHOD GetTransactionId <1610743812> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTxId
   ' =====================================================================================
   METHOD GetActivityId <1610743813> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrActivityId
   ' =====================================================================================
   METHOD GetContextId <1610743814> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCtxId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ContextInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ContextInfo2
' IID = {C99D6E75-2375-11D4-8331-00C04F605588}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ContextInfo
' ########################################################################################

#IF NOT %DEF(%ContextInfo2_INTERFACE_DEFINED)
    %ContextInfo2_INTERFACE_DEFINED = 1

INTERFACE ContextInfo2 $IID_ContextInfo2

   INHERIT IDispatch

   ' =====================================================================================
   ' ContextInfo Methods
   ' =====================================================================================
   METHOD IsInTransaction <100671488> ( _               ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsInTx
   ' =====================================================================================
   METHOD GetTransaction <1610743811> ( _               ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppTx
   ' =====================================================================================
   METHOD GetTransactionId <1610743812> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTxId
   ' =====================================================================================
   METHOD GetActivityId <1610743813> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrActivityId
   ' =====================================================================================
   METHOD GetContextId <1610743814> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCtxId
   ' =====================================================================================

   ' =====================================================================================
   ' ContextInfo2 Methods
   ' =====================================================================================
   METHOD GetPartitionId <1610743815> ( _               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *__MIDL_0011
   ' =====================================================================================
   METHOD GetApplicationId <1610743816> ( _             ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *__MIDL_0012
   ' =====================================================================================
   METHOD GetApplicationInstanceId <1610743817> ( _     ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *__MIDL_0013
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ContextInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ObjectContext
' IID = {74C08646-CEDB-11CF-8B49-00AA00B8A790}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ObjectContext_INTERFACE_DEFINED)
    %ObjectContext_INTERFACE_DEFINED = 1

INTERFACE ObjectContext $IID_ObjectContext

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateInstance <1610743808> ( _               ' VTable offset = 28
     BYVAL bstrProgID AS WSTRING _                      ' __in BSTR bstrProgID
   ) AS VARIANT                                         ' __retval_out VARIANT *pObject
   ' =====================================================================================
   METHOD SetComplete <1610743809> ( _                  ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAbort <1610743810> ( _                     ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableCommit <1610743811> ( _                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableCommit <1610743812> ( _                ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD IsInTransaction <1610743813> ( _              ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsInTx
   ' =====================================================================================
   METHOD IsSecurityEnabled <1610743814> ( _            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsEnabled
   ' =====================================================================================
   METHOD IsCallerInRole <1610743815> ( _               ' VTable offset = 56
     BYVAL bstrRole AS WSTRING _                        ' __in BSTR bstrRole
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbInRole
   ' =====================================================================================
   PROPERTY GET Count <1610743840> ( _                  ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 64
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pItem
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 68
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   PROPERTY GET Security <1610743843> ( _               ' VTable offset = 72
   ) AS SecurityProperty                                ' __retval_out SecurityProperty **ppSecurityProperty
   ' =====================================================================================
   PROPERTY GET ContextInfo <1610743844> ( _            ' VTable offset = 76
   ) AS ContextInfo                                     ' __retval_out ContextInfo **ppContextInfo
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ObjectContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionContextEx
' IID = {7999FC22-D3C6-11CF-ACAB-00A024A55AEF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionContextEx_INTERFACE_DEFINED)
    %ITransactionContextEx_INTERFACE_DEFINED = 1

INTERFACE ITransactionContextEx $IID_ITransactionContextEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out void **pObject
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionContextEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionContext
' IID = {7999FC21-D3C6-11CF-ACAB-00A024A55AEF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITransactionContext_INTERFACE_DEFINED)
    %ITransactionContext_INTERFACE_DEFINED = 1

INTERFACE ITransactionContext $IID_ITransactionContext

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateInstance <0> ( _                        ' VTable offset = 28
     BYVAL pszProgId AS WSTRING _                       ' __in BSTR pszProgId
   ) AS VARIANT                                         ' __retval_out VARIANT *pObject
   ' =====================================================================================
   METHOD Commit <1> ( _                                ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort <2> ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICreateWithTransactionEx
' IID = {455ACF57-5345-11D2-99CF-00C04F797BC9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateWithTransactionEx_INTERFACE_DEFINED)
    %ICreateWithTransactionEx_INTERFACE_DEFINED = 1

INTERFACE ICreateWithTransactionEx $IID_ICreateWithTransactionEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL pTransaction AS ITransaction _                               ' __in ITransaction *pTransaction
   , BYREF rclsid AS GUID _                                       ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                                       ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out **pObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateWithTransactionEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICreateWithLocalTransaction
' IID = {227AC7A8-8423-42CE-B7CF-03061EC9AAA3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateWithLocalTransaction_INTERFACE_DEFINED)
    %ICreateWithLocalTransaction_INTERFACE_DEFINED = 1

INTERFACE ICreateWithLocalTransaction $IID_ICreateWithLocalTransaction

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateInstanceWithSysTx ( _                   ' VTable offset = 12
     BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   , BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out void **pObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateWithLocalTransaction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICreateWithTipTransactionEx
' IID = {455ACF59-5345-11D2-99CF-00C04F797BC9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateWithTipTransactionEx_INTERFACE_DEFINED)
    %ICreateWithTipTransactionEx_INTERFACE_DEFINED = 1

INTERFACE ICreateWithTipTransactionEx $IID_ICreateWithTipTransactionEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL bstrTipUrl AS WSTRING _                      ' __in BSTR bstrTipUrl
   , BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out void **pObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateWithTipTransactionEx_INTERFACE_DEFINED__ */


'#pragma deprecated (ICreateWithTipTransactionEx)
'typedef unsigned __int64 MTS_OBJID;
'typedef unsigned __int64 MTS_RESID;
'typedef unsigned __int64 ULONG64;

#IF NOT %DEF(%COMSVCSEVENTINFO_DEFINED)
%COMSVCSEVENTINFO_DEFINED = 1
' // Size = 56 bytes
TYPE COMSVCSEVENTINFO ' Must be 8 bytes aligned
   cbSize       AS DWORD          ' DWORD
   dwPid        AS DWORD          ' DWORD
   lTime        AS QUAD           ' LONGLONG
   lMicroTime   AS LONG           ' LONG
   filler1_     AS DWORD          ' // To keep 8 bytes alignment
   perfCount    AS QUAD           ' LONGLONG
   guidApp      AS GUID           ' GUID
   sMachineName AS WSTRINGZ PTR   ' LPOLESTR
   filler2_     AS DWORD          ' // To keep 8 bytes alignment
END TYPE
#ENDIF ' _COMSVCSEVENTINFO_


' ########################################################################################
' Interface name = IComLTxEvents
' IID = {605CF82C-578E-4298-975D-82BABCD9E053}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComLTxEvents_INTERFACE_DEFINED)
    %IComLTxEvents_INTERFACE_DEFINED = 1

INTERFACE IComLTxEvents $IID_IComLTxEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnLtxTransactionStart ( _                     ' VTable offset = 12
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO* pinfo
   , BYVAL guidLtx AS GUID _                            ' __in GUID guidLtx
   , BYVAL tsid AS GUID _                               ' __in GUID tsid
   , BYVAL fRoot AS LONG _                              ' __in long fRoot
   , BYVAL nIsolationLevel AS LONG _                    ' __in int nIsolationLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLtxTransactionPrepare ( _                   ' VTable offset = 16
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO* pinfo
   , BYVAL guidLtx AS GUID _                            ' __in GUID guidLtx
   , BYVAL fVote AS LONG _                              ' __in long fVote
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLtxTransactionAbort ( _                     ' VTable offset = 20
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO* pinfo
   , BYVAL guidLtx AS GUID _                            ' __in GUID guidLtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLtxTransactionCommit ( _                    ' VTable offset = 24
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO* pinfo
   , BYVAL guidLtx AS GUID _                            ' __in GUID guidLtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLtxTransactionPromote ( _                   ' VTable offset = 28
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO* pinfo
   , BYVAL guidLtx AS GUID _                            ' __in GUID guidLtx
   , BYVAL txnId AS GUID _                              ' __in GUID txnId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComLTxEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComUserEvent
' IID = {683130A4-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComUserEvent_INTERFACE_DEFINED)
    %IComUserEvent_INTERFACE_DEFINED = 1

INTERFACE IComUserEvent $IID_IComUserEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnUserEvent ( _                               ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF pvarEvent AS VARIANT _                       ' __in VARIANT *pvarEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComUserEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComThreadEvents
' IID = {683130A5-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComThreadEvents_INTERFACE_DEFINED)
    %IComThreadEvents_INTERFACE_DEFINED = 1

INTERFACE IComThreadEvents $IID_IComThreadEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnThreadStart ( _                             ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL dwTheadCnt AS DWORD _                        ' __in DWORD dwTheadCnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadTerminate ( _                         ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL dwTheadCnt AS DWORD _                        ' __in DWORD dwTheadCnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadBindToApartment ( _                   ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL AptID AS QUAD _                              ' __in ULONG64 AptID
   , BYVAL dwActCnt AS DWORD _                          ' __in DWORD dwActCnt
   , BYVAL dwLowCnt AS DWORD _                          ' __in DWORD dwLowCnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadUnBind ( _                            ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL AptID AS QUAD _                              ' __in ULONG64 AptID
   , BYVAL dwActCnt AS DWORD _                          ' __in DWORD dwActCnt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadWorkEnque ( _                         ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL MsgWorkID AS QUAD _                          ' __in ULONG64 MsgWorkID
   , BYVAL QueueLen AS DWORD _                          ' __in DWORD QueueLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadWorkPrivate ( _                       ' VTable offset = 32
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL MsgWorkID AS QUAD _                          ' __in ULONG64 MsgWorkID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadWorkPublic ( _                        ' VTable offset = 36
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL MsgWorkID AS QUAD _                          ' __in ULONG64 MsgWorkID
   , BYVAL QueueLen AS DWORD _                          ' __in DWORD QueueLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadWorkRedirect ( _                      ' VTable offset = 40
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL MsgWorkID AS QUAD _                          ' __in ULONG64 MsgWorkID
   , BYVAL QueueLen AS DWORD _                          ' __in DWORD QueueLen
   , BYVAL ThreadNum AS QUAD _                          ' __in ULONG64 ThreadNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadWorkReject ( _                        ' VTable offset = 44
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ThreadID AS QUAD _                           ' __in ULONG64 ThreadID
   , BYVAL MsgWorkID AS QUAD _                          ' __in ULONG64 MsgWorkID
   , BYVAL QueueLen AS DWORD _                          ' __in DWORD QueueLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadAssignApartment ( _                   ' VTable offset = 48
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYVAL AptID AS QUAD _                              ' __in ULONG64 AptID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnThreadUnassignApartment ( _                 ' VTable offset = 52
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL AptID AS QUAD _                              ' __in ULONG64 AptID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComThreadEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComAppEvents
' IID = {683130A6-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComAppEvents_INTERFACE_DEFINED)
    %IComAppEvents_INTERFACE_DEFINED = 1

INTERFACE IComAppEvents $IID_IComAppEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAppActivation ( _                           ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppShutdown ( _                             ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppForceShutdown ( _                        ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComAppEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComInstanceEvents
' IID = {683130A7-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComInstanceEvents_INTERFACE_DEFINED)
    %IComInstanceEvents_INTERFACE_DEFINED = 1

INTERFACE IComInstanceEvents $IID_IComInstanceEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjectCreate ( _                            ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYREF tsid AS GUID _                               ' __in REFGUID tsid
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjectDestroy ( _                           ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComInstanceEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComTransactionEvents
' IID = {683130A8-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTransactionEvents_INTERFACE_DEFINED)
    %IComTransactionEvents_INTERFACE_DEFINED = 1

INTERFACE IComTransactionEvents $IID_IComTransactionEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTransactionStart ( _                        ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYREF tsid AS GUID _                               ' __in REFGUID tsid
   , BYVAL fRoot AS LONG _                              ' __in BOOL fRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionPrepare ( _                      ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL fVoteYes AS LONG _                           ' __in BOOL fVoteYes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionAbort ( _                        ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionCommit ( _                       ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTransactionEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComMethodEvents
' IID = {683130A9-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComMethodEvents_INTERFACE_DEFINED)
    %IComMethodEvents_INTERFACE_DEFINED = 1

INTERFACE IComMethodEvents $IID_IComMethodEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnMethodCall ( _                              ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMethodReturn ( _                            ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   , BYVAL hresult AS LONG _                            ' __in HRESULT hresult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMethodException ( _                         ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComMethodEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectEvents
' IID = {683130AA-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectEvents_INTERFACE_DEFINED)
    %IComObjectEvents_INTERFACE_DEFINED = 1

INTERFACE IComObjectEvents $IID_IComObjectEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjectActivate ( _                          ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjectDeactivate ( _                        ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDisableCommit ( _                           ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEnableCommit ( _                            ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSetComplete ( _                             ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSetAbort ( _                                ' VTable offset = 32
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComResourceEvents
' IID = {683130AB-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComResourceEvents_INTERFACE_DEFINED)
    %IComResourceEvents_INTERFACE_DEFINED = 1

INTERFACE IComResourceEvents $IID_IComResourceEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnResourceCreate ( _                          ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCOLESTR pszType
   , BYVAL resId AS QUAD _                              ' __in ULONG64 resId
   , BYVAL enlisted AS LONG _                           ' __in BOOL enlisted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResourceAllocate ( _                        ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCOLESTR pszType
   , BYVAL resId AS QUAD _                              ' __in ULONG64 resId
   , BYVAL enlisted AS LONG _                           ' __in BOOL enlisted
   , BYVAL NumRated AS DWORD _                          ' __in DWORD NumRated
   , BYVAL Rating AS DWORD _                            ' __in DWORD Rating
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResourceRecycle ( _                         ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCOLESTR pszType
   , BYVAL resId AS QUAD _                              ' __in ULONG64 resId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResourceDestroy ( _                         ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCOLESTR pszType
   , BYVAL resId AS QUAD _                              ' __in ULONG64 resId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResourceTrack ( _                           ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF pszType AS WSTRINGZ _                        ' __in LPCOLESTR pszType
   , BYVAL resId AS QUAD _                              ' __in ULONG64 resId
   , BYVAL enlisted AS LONG _                           ' __in BOOL enlisted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComResourceEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComSecurityEvents
' IID = {683130AC-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComSecurityEvents_INTERFACE_DEFINED)
    %IComSecurityEvents_INTERFACE_DEFINED = 1

INTERFACE IComSecurityEvents $IID_IComSecurityEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAuthenticate ( _                            ' __in VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF guidIID AS GUID _                            ' __in REFGUID guidIID
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   , BYVAL cbByteOrig AS DWORD _                        ' __in ULONG cbByteOrig
   , BYVAL pSidOriginalUser AS BYTE PTR _               ' __in BYTE *pSidOriginalUser
   , BYVAL cbByteCur AS DWORD _                         ' __in ULONG cbByteCur
   , BYVAL pSidCurrentUser AS BYTE PTR _                ' __in BYTE *pSidCurrentUser
   , BYVAL bCurrentUserInpersonatingInProc AS LONG _    ' __in BOOL bCurrentUserInpersonatingInProc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAuthenticateFail ( _                        ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF guidIID AS GUID _                            ' __in REFGUID guidIID
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   , BYVAL cbByteOrig AS DWORD _                        ' __in ULONG cbByteOrig
   , BYVAL pSidOriginalUser AS BYTE PTR _               ' __in BYTE *pSidOriginalUser
   , BYVAL cbByteCur AS DWORD _                         ' __in ULONG cbByteCur
   , BYVAL pSidCurrentUser AS BYTE PTR _                ' __in BYTE *pSidCurrentUser
   , BYVAL bCurrentUserInpersonatingInProc AS LONG _    ' __in BOOL bCurrentUserInpersonatingInProc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComSecurityEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectPoolEvents
' IID = {683130AD-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectPoolEvents_INTERFACE_DEFINED)
    %IComObjectPoolEvents_INTERFACE_DEFINED = 1

INTERFACE IComObjectPoolEvents $IID_IComObjectPoolEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjPoolPutObject ( _                        ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL nReason AS LONG _                            ' __in int nReason
   , BYVAL dwAvailable AS DWORD _                       ' __in DWORD dwAvailable
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolGetObject ( _                        ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL dwAvailable AS DWORD _                       ' __in DWORD dwAvailable
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolRecycleToTx ( _                      ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolGetFromTx ( _                        ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectPoolEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectPoolEvents2
' IID = {683130AE-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectPoolEvents2_INTERFACE_DEFINED)
    %IComObjectPoolEvents2_INTERFACE_DEFINED = 1

INTERFACE IComObjectPoolEvents2 $IID_IComObjectPoolEvents2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjPoolCreateObject ( _                     ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL dwObjsCreated AS DWORD _                     ' __in DWORD dwObjsCreated
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolDestroyObject ( _                    ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL dwObjsCreated AS DWORD _                     ' __in DWORD dwObjsCreated
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolCreateDecision ( _                   ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL dwThreadsWaiting AS DWORD _                  ' __in DWORD dwThreadsWaiting
   , BYVAL dwAvail AS DWORD _                           ' __in DWORD dwAvail
   , BYVAL dwCreated AS DWORD _                         ' __in DWORD dwCreated
   , BYVAL dwMin AS DWORD _                             ' __in DWORD dwMin
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolTimeout ( _                          ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolCreatePool ( _                       ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL dwMin AS DWORD _                             ' __in DWORD dwMin
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectPoolEvents2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectConstructionEvents
' IID = {683130AF-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectConstructionEvents_INTERFACE_DEFINED)
    %IComObjectConstructionEvents_INTERFACE_DEFINED = 1

INTERFACE IComObjectConstructionEvents $IID_IComObjectConstructionEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjectConstruct ( _                         ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF sConstructString AS WSTRINGZ _               ' __in LPCOLESTR sConstructString
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectConstructionEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComActivityEvents
' IID = {683130B0-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComActivityEvents_INTERFACE_DEFINED)
    %IComActivityEvents_INTERFACE_DEFINED = 1

INTERFACE IComActivityEvents $IID_IComActivityEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnActivityCreate ( _                          ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityDestroy ( _                         ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityEnter ( _                           ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidCurrent AS GUID _                        ' __in REFGUID guidCurrent
   , BYREF guidEntered AS GUID _                        ' __in REFGUID guidEntered
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityTimeout ( _                         ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidCurrent AS GUID _                        ' __in REFGUID guidCurrent
   , BYREF guidEntered AS GUID _                        ' __in REFGUID guidEntered
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityReenter ( _                         ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidCurrent AS GUID _                        ' __in REFGUID guidCurrent
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL dwCallDepth AS DWORD _                       ' __in DWORD dwCallDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityLeave ( _                           ' VTable offset = 32
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidCurrent AS GUID _                        ' __in REFGUID guidCurrent
   , BYREF guidLeft AS GUID _                           ' __in REFGUID guidLeft
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnActivityLeaveSame ( _                       ' VTable offset = 36
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidCurrent AS GUID _                        ' __in REFGUID guidCurrent
   , BYVAL dwCallDepth AS DWORD _                       ' __in DWORD dwCallDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComActivityEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComIdentityEvents
' IID = {683130B1-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComIdentityEvents_INTERFACE_DEFINED)
    %IComIdentityEvents_INTERFACE_DEFINED = 1

INTERFACE IComIdentityEvents $IID_IComIdentityEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnIISRequestInfo ( _                          ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL ObjId AS QUAD _                              ' __in ULONG64 ObjId
   , BYREF pszClientIP AS WSTRINGZ _                    ' __in LPCOLESTR pszClientIP
   , BYREF pszServerIP AS WSTRINGZ _                    ' __in LPCOLESTR pszServerIP
   , BYREF pszURL AS WSTRINGZ _                         ' __in LPCOLESTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComIdentityEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComQCEvents
' IID = {683130B2-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComQCEvents_INTERFACE_DEFINED)
    %IComQCEvents_INTERFACE_DEFINED = 1

INTERFACE IComQCEvents $IID_IComQCEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnQCRecord ( _                                ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   , BYREF szQueue AS WSTRINGZ _                        ' __in WCHAR szQueue[ 60 ]
   , BYREF guidMsgId AS GUID _                          ' __in REFGUID guidMsgId
   , BYREF guidWorkFlowId AS GUID _                     ' __in REFGUID guidWorkFlowId
   , BYVAL msmqhr AS LONG _                             ' __in HRESULT msmqhr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCQueueOpen ( _                             ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF szQueue AS WSTRINGZ _                        ' __in WCHAR szQueue[ 60 ]
   , BYVAL QueueID AS QUAD _                            ' __in ULONG64 QueueID
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCReceive ( _                               ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL QueueID AS QUAD _                            ' __in ULONG64 QueueID
   , BYREF guidMsgId AS GUID _                          ' __in REFGUID guidMsgId
   , BYREF guidWorkFlowId AS GUID _                     ' __in REFGUID guidWorkFlowId
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCReceiveFail ( _                           ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL QueueID AS QUAD _                            ' __in ULONG64 QueueID
   , BYVAL msmqhr AS LONG _                             ' __in HRESULT msmqhr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCMoveToReTryQueue ( _                      ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidMsgId AS GUID _                          ' __in REFGUID guidMsgId
   , BYREF guidWorkFlowId AS GUID _                     ' __in REFGUID guidWorkFlowId
   , BYVAL RetryIndex AS DWORD _                        ' __in ULONG RetryIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCMoveToDeadQueue ( _                       ' VTable offset = 32
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidMsgId AS GUID _                          ' __in REFGUID guidMsgId
   , BYREF guidWorkFlowId AS GUID _                     ' __in REFGUID guidWorkFlowId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQCPlayback ( _                              ' VTable offset = 36
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   , BYREF guidMsgId AS GUID _                          ' __in REFGUID guidMsgId
   , BYREF guidWorkFlowId AS GUID _                     ' __in REFGUID guidWorkFlowId
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComQCEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComExceptionEvents
' IID = {683130B3-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComExceptionEvents_INTERFACE_DEFINED)
    %IComExceptionEvents_INTERFACE_DEFINED = 1

INTERFACE IComExceptionEvents $IID_IComExceptionEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnExceptionUser ( _                           ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL code AS DWORD _                              ' __in ULONG code
   , BYVAL address AS QUAD _                            ' __in ULONG64 address
   , BYREF pszStackTrace AS WSTRINGZ _                  ' __in LPCOLESTR pszStackTrace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComExceptionEvents_INTERFACE_DEFINED__ */



' ########################################################################################
' Interface name = ILBEvents
' IID = {683130B4-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILBEvents_INTERFACE_DEFINED)
    %ILBEvents_INTERFACE_DEFINED = 1

INTERFACE ILBEvents $IID_ILBEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TargetUp ( _                                  ' VTable offset = 12
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrClsidEng AS WSTRING _                    ' __in BSTR bstrClsidEng
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TargetDown ( _                                ' VTable offset = 16
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrClsidEng AS WSTRING _                    ' __in BSTR bstrClsidEng
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EngineDefined ( _                             ' VTable offset = 20
     BYVAL bstrPropName AS WSTRING _                    ' __in BSTR bstrPropName
   , BYREF varPropValue AS VARIANT _                    ' __in VARIANT *varPropValue
   , BYVAL bstrClsidEng AS WSTRING _                    ' __in BSTR bstrClsidEng
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILBEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComCRMEvents
' IID = {683130B5-2E50-11D2-98A5-00C04F8EE1C4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComCRMEvents_INTERFACE_DEFINED)
    %IComCRMEvents_INTERFACE_DEFINED = 1

INTERFACE IComCRMEvents $IID_IComCRMEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCRMRecoveryStart ( _                        ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMRecoveryDone ( _                         ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMCheckpoint ( _                           ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMBegin ( _                                ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   , BYVAL guidActivity AS GUID _                       ' __in GUID guidActivity
   , BYVAL guidTx AS GUID _                             ' __in GUID guidTx
   , BYREF szProgIdCompensator AS WSTRINGZ _            ' __in WCHAR szProgIdCompensator[ 64 ]
   , BYREF szDescription AS WSTRINGZ _                  ' __in WCHAR szDescription[ 64 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMPrepare ( _                              ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMCommit ( _                               ' VTable offset = 32
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMAbort ( _                                ' VTable offset = 36
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMIndoubt ( _                              ' VTable offset = 40
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMDone ( _                                 ' VTable offset = 44
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMRelease ( _                              ' VTable offset = 48
     BYREF pinfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pinfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMAnalyze ( _                              ' VTable offset = 52
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   , BYVAL dwCrmRecordType AS DWORD _                   ' __in DWORD dwCrmRecordType
   , BYVAL dwRecordSize AS DWORD _                      ' __in DWORD dwRecordSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMWrite ( _                                ' VTable offset = 56
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   , BYVAL fVariants AS LONG _                          ' __in BOOL fVariants
   , BYVAL dwRecordSize AS DWORD _                      ' __in DWORD dwRecordSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMForget ( _                               ' VTable offset = 60
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMForce ( _                                ' VTable offset = 64
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCRMDeliver ( _                              ' VTable offset = 68
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidClerkCLSID AS GUID _                     ' __in GUID guidClerkCLSID
   , BYVAL fVariants AS LONG _                          ' __in BOOL fVariants
   , BYVAL dwRecordSize AS DWORD _                      ' __in DWORD dwRecordSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComCRMEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComMethod2Events
' IID = {FB388AAA-567D-4024-AF8E-6E93EE748573}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComMethod2Events_INTERFACE_DEFINED)
    %IComMethod2Events_INTERFACE_DEFINED = 1

INTERFACE IComMethod2Events $IID_IComMethod2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnMethodCall2 ( _                             ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMethodReturn2 ( _                           ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   , BYVAL hresult AS LONG _                            ' __in HRESULT hresult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMethodException2 ( _                        ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidCid AS GUID _                            ' __in REFCLSID guidCid
   , BYREF guidRid AS GUID _                            ' __in REFIID guidRid
   , BYVAL dwThread AS DWORD _                          ' __in DWORD dwThread
   , BYVAL iMeth AS DWORD _                             ' __in ULONG iMeth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComMethod2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComTrackingInfoEvents
' IID = {4E6CDCC9-FB25-4FD5-9CC5-C9F4B6559CEC}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTrackingInfoEvents_INTERFACE_DEFINED)
    %IComTrackingInfoEvents_INTERFACE_DEFINED = 1

INTERFACE IComTrackingInfoEvents $IID_IComTrackingInfoEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNewTrackingInfo ( _                         ' VTable offset = 12
     BYVAL pToplevelCollection AS IUnknown _            ' __in IUnknown *pToplevelCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTrackingInfoEvents_INTERFACE_DEFINED__ */


' enum TRACKING_COLL_TYPE
%TRKCOLL_PROCESSES    = 0
%TRKCOLL_APPLICATIONS = %TRKCOLL_PROCESSES    + 1
%TRKCOLL_COMPONENTS   = %TRKCOLL_APPLICATIONS + 1


' ########################################################################################
' Interface name = IComTrackingInfoCollection
' IID = {c266c677-c9ad-49ab-9fd9-d9661078588a}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTrackingInfoCollection_INTERFACE_DEFINED)
    %IComTrackingInfoCollection_INTERFACE_DEFINED = 1

INTERFACE IComTrackingInfoCollection $IID_IComTrackingInfoCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Type ( _                                      ' VTable offset = 12
     BYREF pType AS LONG _                              ' __out TRACKING_COLL_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 16
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTrackingInfoCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComTrackingInfoObject
' IID = {116e42c5-d8b1-47bf-ab1e-c895ed3e2372}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTrackingInfoObject_INTERFACE_DEFINED)
    %IComTrackingInfoObject_INTERFACE_DEFINED = 1

INTERFACE IComTrackingInfoObject $IID_IComTrackingInfoObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 12
     BYREF szPropertyName AS WSTRINGZ _                 ' __in LPOLESTR szPropertyName
   , BYREF pvarOut AS VARIANT _                         ' __out VARIANT *pvarOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTrackingInfoObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComTrackingInfoProperties
' IID = {789b42be-6f6b-443a-898e-67abf390aa14}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTrackingInfoProperties_INTERFACE_DEFINED)
    %IComTrackingInfoProperties_INTERFACE_DEFINED = 1

INTERFACE IComTrackingInfoProperties $IID_IComTrackingInfoProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PropCount ( _                                 ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropName ( _                               ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppszPropName AS DWORD _                      ' __out LPOLESTR *ppszPropName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTrackingInfoProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComApp2Events
' IID = {1290BC1A-B219-418D-B078-5934DED08242}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComApp2Events_INTERFACE_DEFINED)
    %IComApp2Events_INTERFACE_DEFINED = 1

INTERFACE IComApp2Events $IID_IComApp2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAppActivation2 ( _                          ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   , BYVAL guidProcess AS GUID _                        ' __in GUID guidProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppShutdown2 ( _                            ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppForceShutdown2 ( _                       ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppPaused2 ( _                              ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   , BYVAL bPaused AS LONG _                            ' __in BOOL bPaused
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAppRecycle2 ( _                             ' VTable offset = 28
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL guidApp AS GUID _                            ' __in GUID guidApp
   , BYVAL guidProcess AS GUID _                        ' __in GUID guidProcess
   , BYVAL lReason AS LONG _                            ' __in long lReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComApp2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComTransaction2Events
' IID = {A136F62A-2F94-4288-86E0-D8A1FA4C0299}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComTransaction2Events_INTERFACE_DEFINED)
    %IComTransaction2Events_INTERFACE_DEFINED = 1

INTERFACE IComTransaction2Events $IID_IComTransaction2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTransactionStart2 ( _                       ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYREF tsid AS GUID _                               ' __in REFGUID tsid
   , BYVAL fRoot AS LONG _                              ' __in BOOL fRoot
   , BYVAL nIsolationLevel AS LONG _                    ' __in int nIsolationLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionPrepare2 ( _                     ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL fVoteYes AS LONG _                           ' __in BOOL fVoteYes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionAbort2 ( _                       ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTransactionCommit2 ( _                      ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComTransaction2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComInstance2Events
' IID = {20E3BF07-B506-4AD5-A50C-D2CA5B9C158E}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComInstance2Events_INTERFACE_DEFINED)
    %IComInstance2Events_INTERFACE_DEFINED = 1

INTERFACE IComInstance2Events $IID_IComInstance2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjectCreate2 ( _                           ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYREF tsid AS GUID _                               ' __in REFGUID tsid
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   , BYVAL ObjectID AS QUAD _                           ' __in ULONG64 ObjectID
   , BYREF guidPartition AS GUID _                      ' __in REFGUID guidPartition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjectDestroy2 ( _                          ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYVAL CtxtID AS QUAD _                             ' __in ULONG64 CtxtID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComInstance2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectPool2Events
' IID = {65BF6534-85EA-4F64-8CF4-3D974B2AB1CF}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectPool2Events_INTERFACE_DEFINED)
    %IComObjectPool2Events_INTERFACE_DEFINED = 1

INTERFACE IComObjectPool2Events $IID_IComObjectPool2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjPoolPutObject2 ( _                       ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL nReason AS LONG _                            ' __in int nReason
   , BYVAL dwAvailable AS DWORD _                       ' __in DWORD dwAvailable
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolGetObject2 ( _                       ' VTable offset = 16
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYVAL dwAvailable AS DWORD _                       ' __in DWORD dwAvailable
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidPartition AS GUID _                      ' __in REFGUID guidPartition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolRecycleToTx2 ( _                     ' VTable offset = 20
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnObjPoolGetFromTx2 ( _                       ' VTable offset = 24
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidActivity AS GUID _                       ' __in REFGUID guidActivity
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF guidTx AS GUID _                             ' __in REFGUID guidTx
   , BYVAL objid AS QUAD _                              ' __in ULONG64 objid
   , BYREF guidPartition AS GUID _                      ' __in REFGUID guidPartition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectPool2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComObjectConstruction2Events
' IID = {4B5A7827-8DF2-45C0-8F6F-57EA1F856A9F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComObjectConstruction2Events_INTERFACE_DEFINED)
    %IComObjectConstruction2Events_INTERFACE_DEFINED = 1

INTERFACE IComObjectConstruction2Events $IID_IComObjectConstruction2Events

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnObjectConstruct2 ( _                        ' VTable offset = 12
     BYREF pInfo AS COMSVCSEVENTINFO _                  ' __in COMSVCSEVENTINFO *pInfo
   , BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF sConstructString AS WSTRINGZ _               ' __in LPCOLESTR sConstructString
   , BYVAL oid AS QUAD _                                ' __in ULONG64 oid
   , BYREF guidPartition AS GUID _                      ' __in REFGUID guidPartition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComObjectConstruction2Events_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISystemAppEventData
' IID = {D6D48A3C-D5C5-49E7-8C74-99E4889ED52F}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISystemAppEventData_INTERFACE_DEFINED)
    %ISystemAppEventData_INTERFACE_DEFINED = 1

INTERFACE ISystemAppEventData $IID_ISystemAppEventData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Startup ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataChanged ( _                             ' VTable offset = 16
     BYVAL dwPID AS DWORD _                             ' __in DWORD dwPID
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   , BYVAL dwNumberSinks AS DWORD _                     ' __in DWORD dwNumberSinks
   , BYVAL bstrDwMethodMask AS WSTRING _                ' __in BSTR bstrDwMethodMask
   , BYVAL dwReason AS DWORD _                          ' __in DWORD dwReason
   , BYVAL u64TraceHandle AS QUAD _                     ' __in ULONG64 u64TraceHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISystemAppEventData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMtsEvents
' IID = {BACEDF4D-74AB-11D0-B162-00AA00BA3258}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMtsEvents_INTERFACE_DEFINED)
   %IMtsEvents_INTERFACE_DEFINED = 1

INTERFACE IMtsEvents $IID_IMtsEvents

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PackageName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET PackageGuid <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD PostEvent <5> ( _                             ' VTable offset = 36
     BYREF vEvent AS VARIANT _                          ' __in VARIANT *vEvent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FireEvents <6> ( _                      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   METHOD GetProcessID <7> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *id
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMtsEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMtsEventInfo
' IID = {D56C3DC1-8482-11D0-B170-00AA00BA3258}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMtsEventInfo_INTERFACE_DEFINED)
    %IMtsEventInfo_INTERFACE_DEFINED = 1

INTERFACE IMtsEventInfo $IID_IMtsEventInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Names <1610743808> ( _                  ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pUnk
   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *sDisplayName
   ' =====================================================================================
   PROPERTY GET EventID <1610743810> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *sGuidEventID
   ' =====================================================================================
   PROPERTY GET Count <1610743811> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET Value <1610743812> ( _                  ' VTable offset = 44
     BYVAL sKey AS WSTRING _                            ' __in BSTR sKey
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMtsEventInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMTSLocator
' IID = {D19B8BFD-7F88-11D0-B16E-00AA00BA3258}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMTSLocator_INTERFACE_DEFINED)
    %IMTSLocator_INTERFACE_DEFINED = 1

INTERFACE IMTSLocator $IID_IMTSLocator

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetEventDispatcher <1> ( _                    ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMTSLocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMtsGrp
' IID = {4B2E958C-0393-11D1-B1AB-00AA00BA3258}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMtsGrp_INTERFACE_DEFINED)
    %IMtsGrp_INTERFACE_DEFINED = 1

INTERFACE IMtsGrp $IID_IMtsGrp

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD Item <2> ( _                                  ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYREF ppUnkDispatcher AS IUnknown _                ' __out IUnknown **ppUnkDispatcher
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <3> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMtsGrp_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMessageMover
' IID = {588A085A-B795-11D1-8054-00C04FC340EE}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMessageMover_INTERFACE_DEFINED)
    %IMessageMover_INTERFACE_DEFINED = 1

INTERFACE IMessageMover $IID_IMessageMover

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SourcePath <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SourcePath <1> ( _                      ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestPath <2> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DestPath <2> ( _                        ' VTable offset = 40
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommitBatchSize <3> ( _                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CommitBatchSize <3> ( _                 ' VTable offset = 48
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveMessages <4> ( _                          ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plMessagesMoved
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMessageMover_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventServerTrace
' IID = {9A9F12B8-80AF-47AB-A579-35EA57725370}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEventServerTrace_INTERFACE_DEFINED)
    %IEventServerTrace_INTERFACE_DEFINED = 1

INTERFACE IEventServerTrace $IID_IEventServerTrace

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StartTraceGuid <1> ( _                        ' VTable offset = 28
     BYVAL bstrguidEvent AS WSTRING _                   ' __in BSTR bstrguidEvent
   , BYVAL bstrguidFilter AS WSTRING _                  ' __in BSTR bstrguidFilter
   , BYVAL lPidFilter AS LONG _                         ' __in LONG lPidFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD StopTraceGuid <2> ( _                         ' VTable offset = 32
     BYVAL bstrguidEvent AS WSTRING _                   ' __in BSTR bstrguidEvent
   , BYVAL bstrguidFilter AS WSTRING _                  ' __in BSTR bstrguidFilter
   , BYVAL lPidFilter AS LONG _                         ' __in LONG lPidFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumTraceGuid <3> ( _                         ' VTable offset = 36
     BYREF plCntGuids AS LONG _                         ' __out LONG *plCntGuids
   , BYREF pbstrGuidList AS WSTRING _                   ' __out BSTR *pbstrGuidList
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventServerTrace_INTERFACE_DEFINED__ */


' // Size = 40 bytes
TYPE RECYCLE_INFO   ' Must be 8 bytes aligned
   guidCombaseProcessIdentifier AS GUID    ' GUID
   ProcessStartTime             AS QUAD    ' LONGLONG
   dwRecycleLifetimeLimit       AS DWORD   ' DWORD
   dwRecycleMemoryLimit         AS DWORD   ' DWORD
   dwRecycleExpirationTimeout   AS DWORD   ' DWORD
   filler_                      AS DWORD   ' // To keep 8 bytes alignment
END TYPE

' enum tagDUMPTYPE
%DUMPTYPE_FULL   = 0
%DUMPTYPE_MINI   = %DUMPTYPE_FULL + 1
%DUMPTYPE_NONE   = %DUMPTYPE_MINI + 1

' enum COMPLUS_APPTYPE
%APPTYPE_UNKNOWN = &HFFFFFFFF???
%APPTYPE_SERVER  = 1
%APPTYPE_LIBRARY = 0
%APPTYPE_SWC     = 2

'//
'// Definition of global named event used to control starting and
'// stopping of tracker push data.
'//

'#define TRACKER_STARTSTOP_EVENT L"Global\\COM+ Tracker Push Event"
$TRACKER_STARTSTOP_EVENT = "Global\COM+ Tracker Push Event"

'//
'// Definition of global named event used to signal when the
'// system application has been restarted
'//

'#define TRACKER_INIT_EVENT L"Global\\COM+ Tracker Init Event"
$TRACKER_INIT_EVENT = "Global\COM+ Tracker Init Event"

#IF NOT %DEF(%GUID_STRING_SIZE)
%GUID_STRING_SIZE           = 40      ' // a couple over.
#ENDIF

' // Size = 16 bytes
TYPE APPSTATISTICS DWORD
   m_cTotalCalls     AS DWORD
   m_cTotalInstances AS DWORD
   m_cTotalClasses   AS DWORD
   m_cCallsPerSecond AS DWORD
END TYPE

MACRO CAppStatistics = APPSTATISTICS

' // Size = 104 bytes
TYPE APPDATA DWORD
   m_idApp          AS DWORD           ' DWORD
   m_szAppGuid      AS WSTRINGZ * 40   ' WCHAR m_szAppGuid[ 40 ]
   m_dwAppProcessId AS DWORD           ' DWORD
   m_AppStatistics  AS APPSTATISTICS   ' APPSTATISTICS
END TYPE

MACRO CAppData = APPDATA

' // Size = 44 bytes
TYPE CLSIDDATA DWORD
   m_clsid           AS GUID    ' CLSID
   m_cReferences     AS DWORD   ' DWORD
   m_cBound          AS DWORD   ' DWORD
   m_cPooled         AS DWORD   ' DWORD
   m_cInCall         AS DWORD   ' DWORD
   m_dwRespTime      AS DWORD   ' DWORD
   m_cCallsCompleted AS DWORD   ' DWORD
   m_cCallsFailed    AS DWORD   ' DWORD
END TYPE

MACRO CCLSIDData = CLSIDDATA

' // Size = 88 bytes
TYPE CLSIDDATA2 DWORD
   m_clsid           AS GUID           ' CLSID
   m_appid           AS GUID           ' GUID
   m_partid          AS GUID           ' GUID
   m_pwszAppName     AS WSTRINGZ PTR   ' WCHAR *
   m_pwszCtxName     AS WSTRINGZ PTR   ' WCHAR *
   m_eAppType        AS LONG           ' COMPLUS_APPTYPE enum
   m_cReferences     AS DWORD          ' DWORD
   m_cBound          AS DWORD          ' DWORD
   m_cPooled         AS DWORD          ' DWORD
   m_cInCall         AS DWORD          ' DWORD
   m_dwRespTime      AS DWORD          ' DWORD
   m_cCallsCompleted AS DWORD          ' DWORD
   m_cCallsFailed    AS DWORD          ' DWORD
END TYPE

MACRO CCLSIDData2 = CLSIDDATA2


' ########################################################################################
' Interface name = IGetAppTrackerData
' IID = 507C3AC8-3E12-4CB0-9366-653D3E050638
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetAppTrackerData_INTERFACE_DEFINED)
    %IGetAppTrackerData_INTERFACE_DEFINED = 1

%DATA_NOT_AVAILABLE = &Hffffffff???

' enum GetAppTrackerDataFlags
%GATD_INCLUDE_PROCESS_EXE_NAME = &H1???
%GATD_INCLUDE_LIBRARY_APPS     = &H2???
%GATD_INCLUDE_SWC              = &H4???
%GATD_INCLUDE_CLASS_NAME       = &H8???
%GATD_INCLUDE_APPLICATION_NAME = &H10???

' // Size = 72 bytes
TYPE ApplicationProcessSummary DWORD
   PartitionIdPrimaryApplication   AS GUID           ' GUID
   ApplicationIdPrimaryApplication AS GUID           ' GUID
   ApplicationInstanceId           AS GUID           ' GUID
   ProcessId                       AS DWORD          ' DWORD
   Type                            AS LONG           ' COMPLUS_APPTYPE
   ProcessExeName                  AS WSTRINGZ PTR   ' LPWSTR
   IsService                       AS LONG           ' BOOL
   IsPaused                        AS LONG           ' BOOL
   IsRecycled                      AS LONG           ' BOOL
END TYPE

' // Size = 32 bytes
TYPE ApplicationProcessStatistics DWORD
   NumCallsOutstanding   AS DWORD   ' ULONG
   NumTrackedComponents  AS DWORD   ' ULONG
   NumComponentInstances AS DWORD   ' ULONG
   AvgCallsPerSecond     AS DWORD   ' ULONG
   Reserved1             AS DWORD   ' ULONG
   Reserved2             AS DWORD   ' ULONG
   Reserved3             AS DWORD   ' ULONG
   Reserved4             AS DWORD   ' ULONG
END TYPE

' // Size = 68 bytes
TYPE ApplicationProcessRecycleInfo DWORD
   IsRecyclable                  AS LONG       ' BOOL
   IsRecycled                    AS LONG       ' BOOL
   TimeRecycled                  AS FILETIME
   TimeToTerminate               AS FILETIME
   RecycleReasonCode             AS LONG       ' long
   IsPendingRecycle              AS LONG       ' BOOL
   HasAutomaticLifetimeRecycling AS LONG       ' BOOL
   TimeForAutomaticRecycling     AS FILETIME
   MemoryLimitInKB               AS DWORD      ' ULONG
   MemoryUsageInKBLastCheck      AS DWORD      ' ULONG
   ActivationLimit               AS DWORD      ' ULONG
   NumActivationsLastReported    AS DWORD      ' ULONG
   CallLimit                     AS DWORD      ' ULONG
   NumCallsLastReported          AS DWORD      ' ULONG
END TYPE

' // Size = 64 bytes
TYPE ApplicationSummary DWORD
   ApplicationInstanceId AS GUID           ' GUID
   PartitionId           AS GUID           ' GUID
   ApplicationId         AS GUID           ' GUID
   Type                  AS LONG           ' COMPLUS_APPTYPE
   ApplicationName       AS WSTRINGZ PTR   ' LPWSTR
   NumTrackedComponents  AS DWORD          ' ULONG
   NumComponentInstances AS DWORD          ' ULONG
END TYPE

' // Size = 72 bytes
TYPE ComponentSummary DWORD
   ApplicationInstanceId AS GUID           ' GUID
   PartitionId           AS GUID           ' GUID
   ApplicationId         AS GUID           ' GUID
   Clsid                 AS GUID           ' CLSID
   ClassName             AS WSTRINGZ PTR   ' LPWSTR
   ApplicationName       AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 52 bytes
TYPE ComponentStatistics DWORD
   NumInstances            AS DWORD   ' ULONG
   NumBoundReferences      AS DWORD   ' ULONG
   NumPooledObjects        AS DWORD   ' ULONG
   NumObjectsInCall        AS DWORD   ' ULONG
   AvgResponseTimeInMs     AS DWORD   ' ULONG
   NumCallsCompletedRecent AS DWORD   ' ULONG
   NumCallsFailedRecent    AS DWORD   ' ULONG
   NumCallsCompletedTotal  AS DWORD   ' ULONG
   NumCallsFailedTotal     AS DWORD   ' ULONG
   Reserved1               AS DWORD   ' ULONG
   Reserved2               AS DWORD   ' ULONG
   Reserved3               AS DWORD   ' ULONG
   Reserved4               AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE ComponentHangMonitorInfo DWORD
   IsMonitored          AS LONG    ' BOOL
   TerminateOnHang      AS LONG    ' BOOL
   AvgCallThresholdInMs AS DWORD   ' ULONG
END TYPE

INTERFACE IGetAppTrackerData $IID_IGetAppTrackerData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetApplicationProcesses ( _                   ' VTable offset = 12
     BYREF PartitionId AS GUID _                        ' __in REFGUID PartitionId
   , BYREF ApplicationId AS GUID _                      ' __in REFGUID ApplicationId
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF NumApplicationProcesses AS DWORD _           ' __out ULONG *NumApplicationProcesses
   , BYREF ApplicationProcesses AS ApplicationProcessSummary _ ' __out ApplicationProcessSummary **ApplicationProcesses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplicationProcessDetails ( _              ' VTable offset = 16
     BYREF ApplicationInstanceId AS GUID _              ' __in REFGUID ApplicationInstanceId
   , BYVAL ProcessId AS DWORD _                         ' __in DWORD ProcessId
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , OPTIONAL BYREF Summary AS ApplicationProcessSummary _       ' __out_opt ApplicationProcessSummary *Summary
   , OPTIONAL BYREF Statistics AS ApplicationProcessStatistics _ ' __out_opt ApplicationProcessStatistics *Statistics
   , OPTIONAL BYREF RecycleInfo AS ApplicationProcessRecycleInfo _ ' __out_opt ApplicationProcessRecycleInfo *RecycleInfo
   , OPTIONAL BYREF AnyComponentsHangMonitored AS LONG _         ' __out_opt BOOL *AnyComponentsHangMonitored
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplicationsInProcess ( _                  ' VTable offset = 20
     BYREF ApplicationInstanceId AS GUID _              ' __in REFGUID ApplicationInstanceId
   , BYVAL ProcessId AS DWORD _                         ' __in DWORD ProcessId
   , BYREF PartitionId AS GUID _                        ' __in REFGUID PartitionId
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF NumApplicationsInProcess AS DWORD _          ' __out ULONG *NumApplicationsInProcess
   , BYREF Applications AS ApplicationSummary _         ' __out ApplicationSummary **Applications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentsInProcess ( _                    ' VTable offset = 24
     BYREF ApplicationInstanceId AS GUID _              ' __in REFGUID ApplicationInstanceId
   , BYVAL ProcessId AS DWORD _                         ' __in DWORD ProcessId
   , BYREF PartitionId AS GUID _                        ' __in REFGUID PartitionId
   , BYREF ApplicationId AS GUID _                      ' __in REFGUID ApplicationId
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF NumComponentsInProcess AS DWORD _            ' __out ULONG *NumComponentsInProcess
   , BYREF Components AS ComponentSummary _             ' __out ComponentSummary **Components
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComponentDetails ( _                       ' VTable offset = 28
     BYREF ApplicationInstanceId AS GUID _              ' __in REFGUID ApplicationInstanceId
   , BYVAL ProcessId AS DWORD _                         ' __in DWORD ProcessId
   , BYREF Clsid AS GUID _                              ' __in REFCLSID Clsid
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , OPTIONAL BYREF Summary AS ComponentSummary _       ' __out_opt ComponentSummary *Summary
   , OPTIONAL BYREF Statistics AS ComponentStatistics _ ' __out_opt ComponentStatistics *Statistics
   , OPTIONAL BYREF HangMonitorInfo AS ComponentHangMonitorInfo _ ' __out_opt ComponentHangMonitorInfo *HangMonitorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTrackerDataAsCollectionObject ( _          ' VTable offset = 32
     BYREF TopLevelCollection AS IUnknown _             ' __out_opt IUnknown **TopLevelCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSuggestedPollingInterval ( _               ' VTable offset = 36
     BYREF PollingIntervalInSeconds AS DWORD _          ' __out DWORD *PollingIntervalInSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetAppTrackerData_INTERFACE_DEFINED__ */

'//
'// Dispenser Manager interfaces
'//
'//  Copyright (C) 1995-1999 Microsoft Corporation.  All rights reserved.

'typedef DWORD_PTR RESTYPID;
'typedef DWORD_PTR RESID;
'typedef LPOLESTR SRESID;
'typedef LPCOLESTR constSRESID;
'typedef DWORD RESOURCERATING;
'typedef long TIMEINSECS;
'typedef DWORD_PTR INSTID;
'typedef DWORD_PTR TRANSID;


'//
'// Error Codes
'//

%MTXDM_E_ENLISTRESOURCEFAILED = &H8004E100&   ' // return from EnlistResource, is then returned by AllocResource

'//
'// IDispenserManager
'// Implemented by Dispenser Manager, called by all Dispensers.
'//

' ########################################################################################
' Interface name = IDispenserManager
' IID = {5CB31E10-2B5F-11CF-BE10-00AA00A2FA25}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDispenserManager_INTERFACE_DEFINED)
    %IDispenserManager_INTERFACE_DEFINED = 1

INTERFACE IDispenserManager $IID_IDispenserManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterDispenser ( _                         ' VTable offset = 12
     BYVAL pDispenserDriver AS IDispenserDriver _       ' __in IDispenserDriver *pDispenserDriver
   , BYREF szDispenserName AS WSTRINGZ _                ' __in LPCOLESTR szDispenserName
   , BYREF ppIHolder AS IHolder _                       ' __out IHolder **ppIHolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 16
     BYREF pInstId AS DWORD _                           ' __out INSTID *pInstId
   , BYREF pTransId AS DWORD _                          ' __out TRANSID *pTransId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispenserManager_INTERFACE_DEFINED__ */


'//
'// IHolder
'// Implemented by Dispenser Manager, called by one Dispenser.
'//


' ########################################################################################
' Interface name = IHolder
' IID = {BF6A1850-2B45-11CF-BE10-00AA00A2FA25}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHolder_INTERFACE_DEFINED)
    %IHolder_INTERFACE_DEFINED = 1

INTERFACE IHolder $IID_IHolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AllocResource ( _                             ' VTable offset = 12
     BYVAL ResTypId AS DWORD _                          ' __in const RESTYPID ResTypId
   , BYREF pResId AS DWORD _                            ' __out ULONG_PTR *pResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeResource ( _                              ' VTable offset = 16
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TrackResource ( _                             ' VTable offset = 20
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TrackResourceS ( _                            ' VTable offset = 24
     BYREF SResId AS WSTRINGZ _                         ' __in constSRESID SResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UntrackResource ( _                           ' VTable offset = 28
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   , BYVAL fDestroy AS LONG _                           ' __in const BOOL fDestroy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UntrackResourceS ( _                          ' VTable offset = 32
     BYREF SResId AS WSTRINGZ _                         ' __in constSRESID SResId
   , BYVAL fDestroy AS LONG _                           ' __in const BOOL fDestroy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestDestroyResource ( _                    ' VTable offset = 40
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHolder_INTERFACE_DEFINED__ */


'//
'// IDispenserDriver
'// Implemented by a Dispenser, called by Dispenser Manager.
'//


' ########################################################################################
' Interface name = IDispenserDriver
' IID = {208B3651-2B48-11CF-BE10-00AA00A2FA25}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDispenserDriver_INTERFACE_DEFINED)
    %IDispenserDriver_INTERFACE_DEFINED = 1

INTERFACE IDispenserDriver $IID_IDispenserDriver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateResource ( _                            ' VTable offset = 12
     BYVAL ResTypId AS DWORD _                          ' __in const RESTYPID ResTypId
   , BYREF pResId AS DWORD _                            ' __out RESID *pResId
   , BYREF pSecsFreeBeforeDestroy AS LONG _             ' __out TIMEINSECS *pSecsFreeBeforeDestroy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RateResource ( _                              ' VTable offset = 16
     BYVAL ResTypId AS DWORD _                          ' __in const RESTYPID ResTypId
   , BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   , BYVAL fRequiresTransactionEnlistment AS LONG _     ' __in const BOOL fRequiresTransactionEnlistment
   , BYREF pRating AS DWORD _                           ' __out RESOURCERATING *pRating
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnlistResource ( _                            ' VTable offset = 20
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   , BYVAL TransId AS DWORD _                           ' __in const TRANSID TransId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetResource ( _                             ' VTable offset = 24
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyResource ( _                           ' VTable offset = 28
     BYVAL ResId AS DWORD _                             ' __in const RESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyResourceS ( _                          ' VTable offset = 32
     BYREF ResId AS WSTRINGZ _                          ' __in constSRESID ResId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispenserDriver_INTERFACE_DEFINED__ */


'////////////////////////////////////////////////////////////
'// This is the list of Microsoft-allocated process recycling
'// reason codes.   These are typed as a long; all values with the
'// high bit set are reserved by Microsoft.    Users who have no
'// special information to add may use the CRR_NO_REASON_SUPPLIED
'// code for that purpose.   The value zero is reserved for the
'// CRR_NO_REASON_SUPPLIED code.


%CRR_NO_REASON_SUPPLIED  = &H00000000???
%CRR_LIFETIME_LIMIT      = &HFFFFFFFF???
%CRR_ACTIVATION_LIMIT    = &HFFFFFFFE???
%CRR_CALL_LIMIT          = &HFFFFFFFD???
%CRR_MEMORY_LIMIT        = &HFFFFFFFC???
%CRR_RECYCLED_FROM_UI    = &HFFFFFFFB???


'////////////////////////////////////////////////////////////


'EXTERN_C const CLSID CLSID_MTSPackage;
'EXTERN_C const GUID  GUID_DefaultAppPartition;
'EXTERN_C const GUID  GUID_FinalizerCID;
'EXTERN_C const GUID  IID_IEnterActivityWithNoLock;


' ########################################################################################
' Interface name = ITransactionProxy
' IID = {02558374-DF2E-4DAE-BD6B-1D5C994F9BDC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionProxy_INTERFACE_DEFINED)
    %ITransactionProxy_INTERFACE_DEFINED = 1

INTERFACE ITransactionProxy $IID_ITransactionProxy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL guid AS GUID _                               ' __in GUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Promote ( _                                   ' VTable offset = 20
     BYREF pTransaction AS ITransaction _               ' __out ITransaction **pTransaction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVoter ( _                               ' VTable offset = 24
     BYVAL pTxAsync AS ITransactionVoterNotifyAsync2 _  ' __in ITransactionVoterNotifyAsync2 *pTxAsync
   , BYREF ppBallot AS ITransactionVoterBallotAsync2 _  ' __out ITransactionVoterBallotAsync2 **ppBallot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIsolationLevel ( _                         ' VTable offset = 28
     BYREF pIsolationLevel AS LONG _                    ' __retval_out ISOLEVEL *pIsolationLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIdentifier ( _                             ' VTable offset = 32
     BYREF pbstrIdentifier AS GUID _                    ' __retval_out GUID *pbstrIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsReusable ( _                                ' VTable offset = 36
     BYREF pfIsReusable AS LONG _                       ' __out BOOL *pfIsReusable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionProxy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IContextSecurityPerimeter
' IID = {A7549A29-A7C4-42E1-8DC1-7E3D748DC24A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextSecurityPerimeter_INTERFACE_DEFINED)
    %IContextSecurityPerimeter_INTERFACE_DEFINED = 1

INTERFACE IContextSecurityPerimeter $IID_IContextSecurityPerimeter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPerimeterFlag ( _                          ' VTable offset = 12
     BYREF pFlag AS LONG _                              ' __out BOOL *pFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPerimeterFlag ( _                          ' VTable offset = 16
     BYVAL fFlag AS LONG _                              ' __in BOOL fFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextSecurityPerimeter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITxProxyHolder
' IID = {13D86F31-0139-41AF-BCAD-C7D50435FE9F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITxProxyHolder_INTERFACE_DEFINED)
    %ITxProxyHolder_INTERFACE_DEFINED = 1

INTERFACE ITxProxyHolder $IID_ITxProxyHolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIdentifier ( _                             ' VTable offset = 12
     BYREF pGuidLtx AS GUID _                           ' __out GUID *pGuidLtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITxProxyHolder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectContext
' IID = {51372AE0-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectContext_INTERFACE_DEFINED)
    %IObjectContext_INTERFACE_DEFINED = 1

INTERFACE IObjectContext $IID_IObjectContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __retval_out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetComplete ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAbort ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableCommit ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableCommit ( _                             ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInTransaction ( _                           ' VTable offset = 32
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsSecurityEnabled ( _                         ' VTable offset = 36
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsCallerInRole ( _                            ' VTable offset = 40
     BYVAL bstrRole AS WSTRING _                        ' __in BSTR bstrRole
   , BYREF pfIsInRole AS LONG _                         ' __retval_out BOOL *pfIsInRole
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectControl
' IID = {51372AEC-CAE7-11CF-BE81-00AA00A2FA25}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectControl_INTERFACE_DEFINED)
    %IObjectControl_INTERFACE_DEFINED = 1

INTERFACE IObjectControl $IID_IObjectControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanBePooled ( _                               ' VTable offset = 20
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumNames
' IID = {51372af2-cae7-11cf-be81-00aa00a2fa25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNames_INTERFACE_DEFINED)
    %IEnumNames_INTERFACE_DEFINED = 1

INTERFACE IEnumNames $IID_IEnumNames

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF rgname AS WSTRING _                          ' __out BSTR *rgname
   , BYREF pceltFetched AS DWORD _                      ' __retval_out unsigned long *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNames _                       ' __retval_out IEnumNames **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNames_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISecurityProperty
' IID = {51372AEA-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISecurityProperty_INTERFACE_DEFINED)
     %ISecurityProperty_INTERFACE_DEFINED = 1

INTERFACE ISecurityProperty $IID_ISecurityProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDirectCreatorSID ( _                       ' VTable offset = 12
     BYREF pSID AS DWORD _                              ' __out PSID *pSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalCreatorSID ( _                     ' VTable offset = 16
     BYREF pSID AS DWORD _                              ' __out PSID *pSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectCallerSID ( _                        ' VTable offset = 20
     BYREF pSID AS DWORD _                              ' __out PSID *pSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalCallerSID ( _                      ' VTable offset = 24
     BYREF pSID AS DWORD _                              ' __out PSID *pSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseSID ( _                                ' VTable offset = 28
     BYVAL pSID AS SID PTR _                            ' __in PSID pSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ObjectControl
' IID = {7DC41850-0C31-11D0-8B79-00AA00B8A790}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ObjectControl_INTERFACE_DEFINED)
    %ObjectControl_INTERFACE_DEFINED = 1

INTERFACE ObjectControl $IID_ObjectControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD CanBePooled ( _                               ' VTable offset = 20
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbPoolable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ObjectControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISharedProperty
' IID = {2A005C01-A5DE-11CF-9E66-00AA00A3F464}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISharedProperty_INTERFACE_DEFINED)
    %ISharedProperty_INTERFACE_DEFINED = 1

INTERFACE ISharedProperty $IID_ISharedProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL val AS VARIANT _                             ' __in VARIANT val
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISharedProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISharedPropertyGroup
' IID = {2A005C07-A5DE-11CF-9E66-00AA00A3F464}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISharedPropertyGroup_INTERFACE_DEFINED)
    %ISharedPropertyGroup_INTERFACE_DEFINED = 1

INTERFACE ISharedPropertyGroup $IID_ISharedPropertyGroup

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreatePropertyByPosition <1> ( _              ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in int Index
   , BYREF fExists AS INTEGER _                         ' __out VARIANT_BOOL *fExists
   ) AS ISharedProperty                                 ' __retval_out ISharedProperty **ppProp
   ' =====================================================================================
   PROPERTY GET PropertyByPosition <2> ( _              ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in int Index
   ) AS ISharedProperty                                 ' __retval_out ISharedProperty **ppProperty
   ' =====================================================================================
   METHOD CreateProperty <3> ( _                        ' VTable offset = 36
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYREF fExists AS INTEGER _                         ' __out VARIANT_BOOL *fExists
   ) AS ISharedProperty                                 ' __retval_out ISharedProperty **ppProp
   ' =====================================================================================
   PROPERTY GET Property <4> ( _                        ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS ISharedProperty                                 ' __retval_out ISharedProperty **ppProperty
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISharedPropertyGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISharedPropertyGroupManager
' IID = {2A005C0D-A5DE-11CF-9E66-00AA00A3F464}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISharedPropertyGroupManager_INTERFACE_DEFINED)
    %ISharedPropertyGroupManager_INTERFACE_DEFINED = 1

INTERFACE ISharedPropertyGroupManager $IID_ISharedPropertyGroupManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreatePropertyGroup <1> ( _                   ' VTable offset = 28
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYREF dwIsoMode AS LONG _                          ' __in_out LONG *dwIsoMode
   , BYREF dwRelMode AS LONG _                          ' __in_out LONG *dwRelMode
   , BYREF fExists AS INTEGER _                         ' __out VARIANT_BOOL *fExists
   ) AS ISharedPropertyGroup                            ' __retval_out ISharedPropertyGroup **ppGroup
   ' =====================================================================================
   PROPERTY GET Group <2> ( _                           ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS ISharedPropertyGroup                            ' __retval_out ISharedPropertyGroup **ppGroup
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISharedPropertyGroupManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectConstruct
' IID = {41C4F8B3-7439-11D2-98CB-00C04F8EE1C4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectConstruct_INTERFACE_DEFINED)
    %IObjectConstruct_INTERFACE_DEFINED = 1

INTERFACE IObjectConstruct $IID_IObjectConstruct

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Construct ( _                                 ' VTable offset = 12
     BYVAL pCtorObj AS IDispatch _                      ' __in IDispatch *pCtorObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectConstruct_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectConstructString
' IID = {41C4F8B2-7439-11D2-98CB-00C04F8EE1C4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IObjectConstructString_INTERFACE_DEFINED)
    %IObjectConstructString_INTERFACE_DEFINED = 1

INTERFACE IObjectConstructString $IID_IObjectConstructString

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConstructString <1> ( _                 ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectConstructString_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectContextActivity
' IID = {51372AFC-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectContextActivity_INTERFACE_DEFINED)
    %IObjectContextActivity_INTERFACE_DEFINED = 1

INTERFACE IObjectContextActivity $IID_IObjectContextActivity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetActivityId ( _                             ' VTable offset = 12
     BYREF pGUID AS GUID _                              ' __out GUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectContextActivity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectContextInfo
' IID = {75B52DDB-E8ED-11D1-93AD-00AA00BA3258}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectContextInfo_INTERFACE_DEFINED)
    %IObjectContextInfo_INTERFACE_DEFINED = 1

INTERFACE IObjectContextInfo $IID_IObjectContextInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsInTransaction ( _                           ' VTable offset = 12
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetTransaction ( _                            ' VTable offset = 16
     BYREF pptrans AS IUnknown _                        ' __out IUnknown **pptrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionId ( _                          ' VTable offset = 20
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityId ( _                             ' VTable offset = 24
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextId ( _                              ' VTable offset = 28
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectContextInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectContextInfo2
' IID = {594BE71A-4BC4-438b-9197-CFD176248B09}
' Inherited interface = IObjectContextInfo
' ########################################################################################

#IF NOT %DEF(%IObjectContextInfo2_INTERFACE_DEFINED)
    %IObjectContextInfo2_INTERFACE_DEFINED = 1

INTERFACE IObjectContextInfo2 $IID_IObjectContextInfo2

   INHERIT IUnknown

   ' =====================================================================================
   ' IObjectContextInfo Methods
   ' =====================================================================================
   METHOD IsInTransaction ( _                           ' VTable offset = 12
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetTransaction ( _                            ' VTable offset = 16
     BYREF pptrans AS IUnknown _                        ' __out IUnknown **pptrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionId ( _                          ' VTable offset = 20
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityId ( _                             ' VTable offset = 24
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextId ( _                              ' VTable offset = 28
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IObjectContextInfo2 Methods
   ' =====================================================================================
   METHOD GetPartitionId ( _                            ' VTable offset = 32
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplicationId ( _                          ' VTable offset = 36
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApplicationInstanceId ( _                  ' VTable offset = 40
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectContextInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionStatus
' IID = {61F589E8-3724-4898-A0A4-664AE9E1D1B4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionStatus_INTERFACE_DEFINED)
    %ITransactionStatus_INTERFACE_DEFINED = 1

INTERFACE ITransactionStatus $IID_ITransactionStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTransactionStatus ( _                      ' VTable offset = 12
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionStatus ( _                      ' VTable offset = 16
     BYREF pHrStatus AS LONG _                          ' __out HRESULT *pHrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectContextTip
' IID = {92FD41CA-BAD9-11D2-9A2D-00C04F797BC9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectContextTip_INTERFACE_DEFINED)
    %IObjectContextTip_INTERFACE_DEFINED = 1

INTERFACE IObjectContextTip $IID_IObjectContextTip

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetTipUrl ( _                                 ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pTipUrl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectContextTip_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPlaybackControl
' IID = {51372AFD-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPlaybackControl_INTERFACE_DEFINED)
    %IPlaybackControl_INTERFACE_DEFINED = 1

INTERFACE IPlaybackControl $IID_IPlaybackControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FinalClientRetry ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinalServerRetry ( _                          ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPlaybackControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetContextProperties
' IID = {51372af4-cae7-11cf-be81-00aa00a2fa25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetContextProperties_INTERFACE_DEFINED)
    %IGetContextProperties_INTERFACE_DEFINED = 1

INTERFACE IGetContextProperties $IID_IGetContextProperties

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pProperty
   ' =====================================================================================
   METHOD EnumNames ( _                                 ' VTable offset = 20
   ) AS IEnumNames                                      ' __retval_out IEnumNames **ppenum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetContextProperties_INTERFACE_DEFINED__ */


' enum TransactionVote
%TxCommit = 0
%TxAbort  = %TxCommit + 1


' ########################################################################################
' Interface name = IContextState
' IID = {3C05E54B-A42A-11D2-AFC4-00C04F8EE1C4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextState_INTERFACE_DEFINED)
    %IContextState_INTERFACE_DEFINED = 1

INTERFACE IContextState $IID_IContextState

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDeactivateOnReturn ( _                     ' VTable offset = 12
     BYVAL bDeactivate AS INTEGER _                     ' __in VARIANT_BOOL bDeactivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeactivateOnReturn ( _                     ' VTable offset = 16
     BYREF pbDeactivate AS INTEGER _                    ' __out VARIANT_BOOL *pbDeactivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMyTransactionVote ( _                      ' VTable offset = 20
     BYVAL txVote AS LONG _                             ' __in TransactionVote txVote
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMyTransactionVote ( _                      ' VTable offset = 24
     BYREF ptxVote AS LONG _                            ' __out TransactionVote *ptxVote
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextState_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPoolManager
' IID = {0A469861-5A91-43A0-99B6-D5E179BB0631}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPoolManager_INTERFACE_DEFINED)
    %IPoolManager_INTERFACE_DEFINED = 1

INTERFACE IPoolManager $IID_IPoolManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ShutdownPool <1> ( _                          ' VTable offset = 28
     BYVAL CLSIDOrProgID AS WSTRING _                   ' __in BSTR CLSIDOrProgID
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPoolManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISelectCOMLBServer
' IID = {dcf443f4-3f8a-4872-b9f0-369a796d12d6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISelectCOMLBServer_INTERFACE_DEFINED)
    %ISelectCOMLBServer_INTERFACE_DEFINED = 1

INTERFACE ISelectCOMLBServer $IID_ISelectCOMLBServer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLBServer ( _                               ' VTable offset = 16
     BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISelectCOMLBServer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICOMLBArguments
' IID = {"3a0f150f-8ee5-4b94-b40e-aef2f9e42ed2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICOMLBArguments_INTERFACE_DEFINED)
    %ICOMLBArguments_INTERFACE_DEFINED = 1

INTERFACE ICOMLBArguments $IID_ICOMLBArguments

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 12
     BYREF pCLSID AS GUID _                             ' __out CLSID *pCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCLSID ( _                                  ' VTable offset = 16
     BYREF pCLSID AS GUID _                             ' __out CLSID *pCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMachineName ( _                            ' VTable offset = 20
     BYVAL cchSvr AS DWORD _                            ' __in ULONG cchSvr
   , BYREF szServerName AS DWORD _                      ' __out WCHAR szServerName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMachineName ( _                            ' VTable offset = 24
     BYVAL cchSvr AS DWORD _                            ' __in ULONG cchSvr
   , BYVAL szServerName AS DWORD _                      ' __in WCHAR szServerName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICOMLBArguments_INTERFACE_DEFINED__ */


'#if (_WIN32_WINNT >= 0x0500)
'#define GetObjectContext(ppIOC) (CoGetObjectContext(IID_IObjectContext, (void **) (ppIOC)) == S_OK ? S_OK : CONTEXT_E_NOCONTEXT)
'#else
'extern HRESULT __cdecl GetObjectContext (IObjectContext** ppInstanceContext);
'#endif

DECLARE FUNCTION GetObjectContext CDECL IMPORT "comsvcs.dll" ALIAS "GetObjectContext" ( _
   BYREF ppInstanceContext AS IObjectContext _          ' __out IObjectContext ** ppInstanceContext
 ) AS LONG                                              ' HRESULT

'EXTERN_C HRESULT __stdcall CoCreateActivity(IUnknown* pIUnknown, REFIID riid, void** ppObj );
DECLARE FUNCTION CoCreateActivity IMPORT "comsvcs.dll" ALIAS "CoCreateActivity" ( _
   BYVAL pIUnknown AS IUnknown _                        ' __in  IUnknown* pIUnknown
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppObj AS ANY _                                 ' __out void** ppObj
 ) AS LONG                                              ' HRESULT

'EXTERN_C HRESULT __stdcall CoEnterServiceDomain(IUnknown* pConfigObject);
DECLARE FUNCTION CoEnterServiceDomain IMPORT "comsvcs.dll" ALIAS "CoEnterServiceDomain" ( _
   BYVAL pConfigObject AS IUnknown _                    ' __in IUnknown* pConfigObject
 ) AS LONG                                              ' HRESULT

'EXTERN_C void __stdcall CoLeaveServiceDomain(IUnknown *pUnkStatus);
DECLARE FUNCTION CoLeaveServiceDomain IMPORT "comsvcs.dll" ALIAS "CoLeaveServiceDomain" ( _
   BYVAL pUnkStatus AS IUnknown _                       ' __in IUnknown *pUnkStatus
 ) AS LONG                                              ' HRESULT

'EXTERN_C HRESULT __stdcall GetManagedExtensions(DWORD* dwExts);
' Note: Not exported in the version of comsvcs.dll installed in Windows XP
'DECLARE FUNCTION GetManagedExtensions IMPORT "comsvcs.dll" ALIAS "GetManagedExtensions" ( _
'   BYREF DWORD _                              ' __out DWORD* dwExts
' ) AS LONG                                              ' HRESULT

'extern void* __cdecl SafeRef(REFIID rid, IUnknown* pUnk);
DECLARE FUNCTION SafeRef CDECL IMPORT "comsvcs.dll" ALIAS "SafeRef" ( _
   BYREF rid AS GUID _                                  ' __in  REFIID rid
 , BYVAL pUnk AS IUnknown _                             ' __out IUnknown* pUnk
 ) AS LONG                                              ' HRESULT

'extern HRESULT __cdecl RecycleSurrogate(long lReasonCode);
DECLARE FUNCTION RecycleSurrogate CDECL IMPORT "comsvcs.dll" ALIAS "RecycleSurrogate" ( _
   BYVAL lReasonCode AS LONG _                          ' __in long lReasonCode
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = ICrmLogControl
' IID = {A0E174B3-D26E-11D2-8F84-00805FC7BCD9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmLogControl_INTERFACE_DEFINED)
    %ICrmLogControl_INTERFACE_DEFINED = 1

INTERFACE ICrmLogControl $IID_ICrmLogControl

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET TransactionUOW ( _                      ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD RegisterCompensator ( _                       ' VTable offset = 16
     BYREF lpcwstrProgIdCompensator AS WSTRINGZ _       ' __in LPCWSTR lpcwstrProgIdCompensator
   , BYREF lpcwstrDescription AS WSTRINGZ _             ' __in LPCWSTR lpcwstrDescription
   , BYVAL lCrmRegFlags AS LONG _                       ' __in LONG lCrmRegFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteLogRecordVariants ( _                    ' VTable offset = 20
     BYREF pLogRecord AS VARIANT _                      ' __in VARIANT *pLogRecord
   )                                                    ' void
   ' =====================================================================================
   METHOD ForceLog ( _                                  ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD ForgetLogRecord ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ForceTransactionToAbort ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteLogRecord ( _                            ' VTable offset = 36
     BYREF rgBlob AS BLOB _                             ' __in BLOB rgBlob[  ]
   , BYVAL cBlob AS DWORD _                             ' __in ULONG cBlob
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmLogControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICrmCompensatorVariants
' IID = {F0BAF8E4-7804-11D1-82E9-00A0C91EEDE9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmCompensatorVariants_INTERFACE_DEFINED)
   %ICrmCompensatorVariants_INTERFACE_DEFINED = 1

INTERFACE ICrmCompensatorVariants $IID_ICrmCompensatorVariants

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetLogControlVariants ( _                     ' VTable offset = 12
     BYVAL pLogControl AS ICrmLogControl _              ' __in ICrmLogControl *pLogControl
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginPrepareVariants ( _                      ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD PrepareRecordVariants ( _                     ' VTable offset = 20
     BYREF pLogRecord AS VARIANT _                      ' __in VARIANT *pLogRecord
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbForget
   ' =====================================================================================
   METHOD EndPrepareVariants ( _                        ' VTable offset = 24
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbOkToPrepare
   ' =====================================================================================
   METHOD BeginCommitVariants ( _                       ' VTable offset = 28
     BYVAL bRecovery AS INTEGER _                       ' __in VARIANT_BOOL bRecovery
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitRecordVariants ( _                      ' VTable offset = 32
     BYREF pLogRecord AS VARIANT _                      ' __in VARIANT *pLogRecord
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbForget
   ' =====================================================================================
   METHOD EndCommitVariants ( _                         ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginAbortVariants ( _                        ' VTable offset = 40
     BYVAL bRecovery AS INTEGER _                       ' __in VARIANT_BOOL bRecovery
   )                                                    ' void
   ' =====================================================================================
   METHOD AbortRecordVariants ( _                       ' VTable offset = 44
     BYREF pLogRecord AS VARIANT _                      ' __in VARIANT *pLogRecord
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbForget
   ' =====================================================================================
   METHOD EndAbortVariants ( _                          ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmCompensatorVariants_INTERFACE_DEFINED__ */


#IF NOT %DEF(%CrmLogRecordRead_DEFINED)
%CrmLogRecordRead_DEFINED = 1
' // Size = 16 bytes
TYPE CrmLogRecordRead DWORD
   dwCrmFlags       AS DWORD   ' DWORD
   dwSequenceNumber AS DWORD   ' DWORD
   blobUserData     AS BLOB    ' BLOB
END TYPE
#ENDIF


' ########################################################################################
' Interface name = ICrmCompensator
' IID = {BBC01830-8D3B-11D1-82EC-00A0C91EEDE9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmCompensator_INTERFACE_DEFINED)
    %ICrmCompensator_INTERFACE_DEFINED = 1

INTERFACE ICrmCompensator $IID_ICrmCompensator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetLogControl ( _                             ' VTable offset = 12
     BYVAL pLogControl AS ICrmLogControl _              ' __in ICrmLogControl *pLogControl
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginPrepare ( _                              ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD PrepareRecord ( _                             ' VTable offset = 20
     BYVAL crmLogRec AS CrmLogRecordRead _              ' __in CrmLogRecordRead crmLogRec
   ) AS LONG                                            ' __retval_out BOOL *pfForget
   ' =====================================================================================
   METHOD EndPrepare ( _                                ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *pfOkToPrepare
   ' =====================================================================================
   METHOD BeginCommit ( _                               ' VTable offset = 28
     BYVAL fRecovery AS LONG _                          ' __in BOOL fRecovery
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitRecord ( _                              ' VTable offset = 32
     BYVAL crmLogRec AS CrmLogRecordRead _              ' __in CrmLogRecordRead crmLogRec
   ) AS LONG                                            ' __retval_out BOOL *pfForget
   ' =====================================================================================
   METHOD EndCommit ( _                                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginAbort ( _                                ' VTable offset = 40
     BYVAL fRecovery AS LONG _                          ' __in BOOL fRecovery
   )                                                    ' void
   ' =====================================================================================
   METHOD AbortRecord ( _                               ' VTable offset = 44
     BYVAL crmLogRec AS CrmLogRecordRead _              ' __in CrmLogRecordRead crmLogRec
   ) AS LONG                                            ' __retval_out BOOL *pfForget
   ' =====================================================================================
   METHOD EndAbort ( _                                  ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmCompensator_INTERFACE_DEFINED__ */


#IF NOT %DEF(%tagCrmTransactionState_DEFINED)
%tagCrmTransactionState_DEFINED = 1
%TxState_Active    = 0
%TxState_Committed = %TxState_Active + 1
%TxState_Aborted   = %TxState_Committed + 1
%TxState_Indoubt   = %TxState_Aborted + 1
#ENDIF ' _tagCrmTransactionState_


' ########################################################################################
' Interface name = ICrmMonitorLogRecords
' IID = {70C8E441-C7ED-11D1-82FB-00A0C91EEDE9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmMonitorLogRecords_INTERFACE_DEFINED)
    %ICrmMonitorLogRecords_INTERFACE_DEFINED = 1

INTERFACE ICrmMonitorLogRecords $IID_ICrmMonitorLogRecords

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET TransactionState ( _                    ' VTable offset = 16
   ) AS LONG                                            ' __retval_out CrmTransactionState *pVal
   ' =====================================================================================
   PROPERTY GET StructuredRecords ( _                   ' VTable offset = 20
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   METHOD GetLogRecord ( _                              ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pCrmLogRec AS CrmLogRecordRead _             ' __in_out CrmLogRecordRead *pCrmLogRec
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLogRecordVariants ( _                      ' VTable offset = 28
     BYVAL IndexNumber AS VARIANT _                     ' __in VARIANT IndexNumber
   ) AS VARIANT                                         ' __retval_out LPVARIANT pLogRecord
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmMonitorLogRecords_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICrmMonitorClerks
' IID = {70C8E442-C7ED-11D1-82FB-00A0C91EEDE9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICrmMonitorClerks_INTERFACE_DEFINED)
    %ICrmMonitorClerks_INTERFACE_DEFINED = 1

INTERFACE ICrmMonitorClerks $IID_ICrmMonitorClerks

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD ProgIdCompensator <2> ( _                     ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================
   METHOD Description <3> ( _                           ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================
   METHOD TransactionUOW <4> ( _                        ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================
   METHOD ActivityId <5> ( _                            ' VTable offset = 52
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmMonitorClerks_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICrmMonitor
' IID = {70C8E443-C7ED-11D1-82FB-00A0C91EEDE9}
' ICrmMonitor Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmMonitor_INTERFACE_DEFINED)
    %ICrmMonitor_INTERFACE_DEFINED = 1

INTERFACE ICrmMonitor $IID_ICrmMonitor

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetClerks ( _                                 ' VTable offset = 12
   ) AS ICrmMonitorClerks                               ' __retval_out ICrmMonitorClerks **pClerks
   ' =====================================================================================
   METHOD HoldClerk ( _                                 ' VTable offset = 16
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out LPVARIANT pItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmMonitor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICrmFormatLogRecords
' IID = {9C51D821-C98B-11D1-82FB-00A0C91EEDE9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICrmFormatLogRecords_INTERFACE_DEFINED)
    %ICrmFormatLogRecords_INTERFACE_DEFINED = 1

INTERFACE ICrmFormatLogRecords $IID_ICrmFormatLogRecords

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColumnCount ( _                            ' VTable offset = 12
     BYREF plColumnCount AS LONG _                      ' __out long *plColumnCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnHeaders ( _                          ' VTable offset = 16
     BYREF pHeaders AS VARIANT _                        ' __out LPVARIANT pHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumn ( _                                 ' VTable offset = 20
     BYVAL CrmLogRec AS CrmLogRecordRead _              ' __in CrmLogRecordRead CrmLogRec
   , BYREF pFormattedLogRecord AS VARIANT _             ' __out LPVARIANT pFormattedLogRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnVariants ( _                         ' VTable offset = 24
     BYVAL LogRecord AS VARIANT _                       ' __in VARIANT LogRecord
   , BYREF pFormattedLogRecord AS VARIANT _             ' __out LPVARIANT pFormattedLogRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICrmFormatLogRecords_INTERFACE_DEFINED__ */


' enum CSC_InheritanceConfig
%CSC_Inherit = 0
%CSC_Ignore  = %CSC_Inherit + 1

' enum CSC_ThreadPool
%CSC_ThreadPoolNone    = 0
%CSC_ThreadPoolInherit = %CSC_ThreadPoolNone + 1
%CSC_STAThreadPool     = %CSC_ThreadPoolInherit + 1
%CSC_MTAThreadPool     = %CSC_STAThreadPool + 1

' enum CSC_Binding
%CSC_NoBinding        = 0
%CSC_BindToPoolThread = %CSC_NoBinding + 1

' enum CSC_TransactionConfig
%CSC_NoTransaction                = 0
%CSC_IfContainerIsTransactional   = %CSC_NoTransaction + 1
%CSC_CreateTransactionIfNecessary = %CSC_IfContainerIsTransactional + 1
%CSC_NewTransaction               = %CSC_CreateTransactionIfNecessary + 1

' enum CSC_SynchronizationConfig
%CSC_NoSynchronization             = 0
%CSC_IfContainerIsSynchronized     = %CSC_NoSynchronization + 1
%CSC_NewSynchronizationIfNecessary = %CSC_IfContainerIsSynchronized + 1
%CSC_NewSynchronization            = %CSC_NewSynchronizationIfNecessary + 1

' enum CSC_TrackerConfig
%CSC_DontUseTracker = 0
%CSC_UseTracker     = %CSC_DontUseTracker + 1

' enum tagCSC_PartitionConfig
%CSC_NoPartition      = 0
%CSC_InheritPartition = %CSC_NoPartition + 1
%CSC_NewPartition     = %CSC_InheritPartition + 1

' enum CSC_IISIntrinsicsConfig
%CSC_NoIISIntrinsics      = 0
%CSC_InheritIISIntrinsics = %CSC_NoIISIntrinsics + 1

' enum CSC_COMTIIntrinsicsConfig
%CSC_NoCOMTIIntrinsics      = 0
%CSC_InheritCOMTIIntrinsics = %CSC_NoCOMTIIntrinsics + 1

' enum CSC_SxsConfig
%CSC_NoSxs      = 0
%CSC_InheritSxs = %CSC_NoSxs + 1
%CSC_NewSxs     = %CSC_InheritSxs + 1


' ########################################################################################
' Interface name = IServiceIISIntrinsicsConfig
' IID = {1A0CF920-D452-46F4-BC36-48118D54EA52}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceIISIntrinsicsConfig_INTERFACE_DEFINED)
    %IServiceIISIntrinsicsConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceIISIntrinsicsConfig $IID_IServiceIISIntrinsicsConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IISIntrinsicsConfig ( _                       ' VTable offset = 12
     BYVAL iisIntrinsicsConfig AS LONG _                ' __in CSC_IISIntrinsicsConfig iisIntrinsicsConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceIISIntrinsicsConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceComTIIntrinsicsConfig
' IID = {09E6831E-04E1-4ED4-9D0F-E8B168BAFEAF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceComTIIntrinsicsConfig_INTERFACE_DEFINED)
    %IServiceComTIIntrinsicsConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceComTIIntrinsicsConfig $IID_IServiceComTIIntrinsicsConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ComTIIntrinsicsConfig ( _                     ' VTable offset = 12
     BYVAL comtiIntrinsicsConfig AS LONG _              ' __in CSC_COMTIIntrinsicsConfig comtiIntrinsicsConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceComTIIntrinsicsConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceSxsConfig
' IID = {C7CD7379-F3F2-4634-811B-703281D73E08}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceSxsConfig_INTERFACE_DEFINED)
    %IServiceSxsConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceSxsConfig $IID_IServiceSxsConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SxsConfig ( _                                 ' VTable offset = 12
     BYVAL scsConfig AS LONG _                          ' __in CSC_SxsConfig scsConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SxsName ( _                                   ' VTable offset = 16
     BYREF szSxsName AS WSTRINGZ _                      ' __in LPCWSTR szSxsName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SxsDirectory ( _                              ' VTable offset = 20
     BYREF szSxsDirectory AS WSTRINGZ _                 ' __in LPCWSTR szSxsDirectory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceSxsConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICheckSxsConfig
' IID = {0FF5A96F-11FC-47d1-BAA6-25DD347E7242}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICheckSxsConfig_INTERFACE_DEFINED)
    %ICheckSxsConfig_INTERFACE_DEFINED = 1

INTERFACE ICheckSxsConfig $IID_ICheckSxsConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSameSxsConfig ( _                           ' VTable offset = 12
     BYREF wszSxsName AS WSTRINGZ _                     ' __in LPCWSTR wszSxsName
   , BYREF wszSxsDirectory AS WSTRINGZ _                ' __in LPCWSTR wszSxsDirectory
   , BYREF wszSxsAppName AS WSTRINGZ _                  ' __in LPCWSTR wszSxsAppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICheckSxsConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceInheritanceConfig
' IID = {92186771-D3B4-4D77-A8EA-EE842D586F35}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceInheritanceConfig_INTERFACE_DEFINED)
    %IServiceInheritanceConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceInheritanceConfig $IID_IServiceInheritanceConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ContainingContextTreatment ( _                ' VTable offset = 12
     BYVAL inheritanceConfig AS LONG _                  ' __in CSC_InheritanceConfig inheritanceConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceInheritanceConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceThreadPoolConfig
' IID = {186D89BC-F277-4BCC-80D5-4DF7B836EF4A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceThreadPoolConfig_INTERFACE_DEFINED)
    %IServiceThreadPoolConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceThreadPoolConfig $IID_IServiceThreadPoolConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SelectThreadPool ( _                          ' VTable offset = 12
     BYVAL threadPool AS LONG _                         ' __in CSC_ThreadPool threadPool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBindingInfo ( _                            ' VTable offset = 16
     BYVAL binding AS LONG _                            ' __in CSC_Binding binding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceThreadPoolConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceTransactionConfigBase
' IID = {772B3FBE-6FFD-42FB-B5F8-8F9B260F3810}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceTransactionConfigBase_INTERFACE_DEFINED)
    %IServiceTransactionConfigBase_INTERFACE_DEFINED = 1

INTERFACE IServiceTransactionConfigBase $IID_IServiceTransactionConfigBase

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConfigureTransaction ( _                      ' VTable offset = 12
     BYVAL transactionConfig AS LONG _                  ' __in CSC_TransactionConfig transactionConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsolationLevel ( _                            ' VTable offset = 16
     BYVAL option AS LONG _                             ' __in COMAdminTxIsolationLevelOptions option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransactionTimeout ( _                        ' VTable offset = 20
     BYVAL ulTimeoutSec AS DWORD _                      ' __in ULONG ulTimeoutSec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringYourOwnTransaction ( _                   ' VTable offset = 24
     BYREF szTipURL AS WSTRINGZ _                       ' __in LPCWSTR szTipURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewTransactionDescription ( _                 ' VTable offset = 28
     BYREF szTxDesc AS WSTRINGZ _                       ' __in LPCWSTR szTxDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceTransactionConfigBase_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceTransactionConfig
' IID = {59F4C2A3-D3D7-4A31-B6E4-6AB3177C50B9}
' Inherited interface = IServiceTransactionConfigBase
' ########################################################################################

#IF NOT %DEF(%IServiceTransactionConfig_INTERFACE_DEFINED)
    %IServiceTransactionConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceTransactionConfig $IID_IServiceTransactionConfig

   INHERIT IUnknown

   ' =====================================================================================
   ' IServiceTransactionConfigBase Methods
   ' =====================================================================================
   METHOD ConfigureTransaction ( _                      ' VTable offset = 12
     BYVAL transactionConfig AS LONG _                  ' __in CSC_TransactionConfig transactionConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsolationLevel ( _                            ' VTable offset = 16
     BYVAL option AS LONG _                             ' __in COMAdminTxIsolationLevelOptions option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransactionTimeout ( _                        ' VTable offset = 20
     BYVAL ulTimeoutSec AS DWORD _                      ' __in ULONG ulTimeoutSec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringYourOwnTransaction ( _                   ' VTable offset = 24
     BYREF szTipURL AS WSTRINGZ _                       ' __in LPCWSTR szTipURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewTransactionDescription ( _                 ' VTable offset = 28
     BYREF szTxDesc AS WSTRINGZ _                       ' __in LPCWSTR szTxDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IServiceTransactionConfig Methods
   ' =====================================================================================
   METHOD ConfigureBYOT ( _                             ' VTable offset = 32
     BYVAL pITxByot AS ITransaction _                   ' __in ITransaction *pITxByot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceTransactionConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceSysTxnConfig
' IID = {33CAF1A1-FCB8-472B-B45E-967448DED6D8}
' Inherited interface = IServiceTransactionConfig
' ########################################################################################

#IF NOT %DEF(%IServiceSysTxnConfig_INTERFACE_DEFINED)
    %IServiceSysTxnConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceSysTxnConfig $IID_IServiceSysTxnConfig

   INHERIT IUnknown

   ' =====================================================================================
   ' IServiceTransactionConfigBase Methods
   ' =====================================================================================
   METHOD ConfigureTransaction ( _                      ' VTable offset = 12
     BYVAL transactionConfig AS LONG _                  ' __in CSC_TransactionConfig transactionConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsolationLevel ( _                            ' VTable offset = 16
     BYVAL option AS LONG _                             ' __in COMAdminTxIsolationLevelOptions option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransactionTimeout ( _                        ' VTable offset = 20
     BYVAL ulTimeoutSec AS DWORD _                      ' __in ULONG ulTimeoutSec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BringYourOwnTransaction ( _                   ' VTable offset = 24
     BYREF szTipURL AS WSTRINGZ _                       ' __in LPCWSTR szTipURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewTransactionDescription ( _                 ' VTable offset = 28
     BYREF szTxDesc AS WSTRINGZ _                       ' __in LPCWSTR szTxDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IServiceTransactionConfig Methods
   ' =====================================================================================
   METHOD ConfigureBYOT ( _                             ' VTable offset = 32
     BYVAL pITxByot AS ITransaction _                   ' __in ITransaction *pITxByot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IServiceSysTxnConfig methods
   ' =====================================================================================
   METHOD ConfigureBYOTSysTxn ( _                       ' VTable offset = 36
     BYVAL pTxProxy AS ITransactionProxy _              ' __in ITransactionProxy *pTxProxy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceSysTxnConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceSynchronizationConfig
' IID = {FD880E81-6DCE-4C58-AF83-A208846C0030}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceSynchronizationConfig_INTERFACE_DEFINED)
    %IServiceSynchronizationConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceSynchronizationConfig $IID_IServiceSynchronizationConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConfigureSynchronization ( _                  ' VTable offset = 12
     BYVAL synchConfig AS LONG _                        ' __in CSC_SynchronizationConfig synchConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceSynchronizationConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceTrackerConfig
' IID = {6C3A3E1D-0BA6-4036-B76F-D0404DB816C9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceTrackerConfig_INTERFACE_DEFINED)
    %IServiceTrackerConfig_INTERFACE_DEFINED = 1

INTERFACE IServiceTrackerConfig $IID_IServiceTrackerConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TrackerConfig ( _                             ' VTable offset = 12
     BYVAL trackerConfig AS LONG _                      ' __in CSC_TrackerConfig trackerConfig
   , BYREF szTrackerAppName AS WSTRINGZ _               ' __in LPCWSTR szTrackerAppName
   , BYREF szTrackerCtxName AS WSTRINGZ _               ' __in LPCWSTR szTrackerCtxName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceTrackerConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServicePartitionConfig
' IID = {80182D03-5EA4-4831-AE97-55BEFFC2E590}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServicePartitionConfig_INTERFACE_DEFINED)
    %IServicePartitionConfig_INTERFACE_DEFINED = 1

INTERFACE IServicePartitionConfig $IID_IServicePartitionConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PartitionConfig ( _                           ' VTable offset = 12
     BYVAL partitionConfig AS LONG _                    ' __in CSC_PartitionConfig partitionConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PartitionID ( _                               ' VTable offset = 16
     BYREF guidPartitionID AS GUID _                    ' __in REFGUID guidPartitionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServicePartitionConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceCall
' IID = {BD3E2E12-42DD-40F4-A09A-95A50C58304B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceCall_INTERFACE_DEFINED)
    %IServiceCall_INTERFACE_DEFINED = 1

INTERFACE IServiceCall $IID_IServiceCall

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCall ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceCall_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAsyncErrorNotify
' IID = {FE6777FB-A674-4177-8F32-6D707E113484}
' IAsyncErrorNotify Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAsyncErrorNotify_INTERFACE_DEFINED)
    %IAsyncErrorNotify_INTERFACE_DEFINED = 1

INTERFACE IAsyncErrorNotify $IID_IAsyncErrorNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnError ( _                                   ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncErrorNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServiceActivity
' IID = {67532E0C-9E2F-4450-A354-035633944E17}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceActivity_INTERFACE_DEFINED)
    %IServiceActivity_INTERFACE_DEFINED = 1

INTERFACE IServiceActivity $IID_IServiceActivity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SynchronousCall ( _                           ' VTable offset = 12
     BYVAL pIServiceCall AS IServiceCall _              ' __in IServiceCall *pIServiceCall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsynchronousCall ( _                          ' VTable offset = 16
     BYVAL pIServiceCall AS IServiceCall _              ' __in IServiceCall *pIServiceCall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToCurrentThread ( _                       ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnbindFromThread ( _                          ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceActivity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IThreadPoolKnobs
' IID = {51372af7-cae7-11cf-be81-00aa00a2fa25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThreadPoolKnobs_INTERFACE_DEFINED)
    %IThreadPoolKnobs_INTERFACE_DEFINED = 1

INTERFACE IThreadPoolKnobs $IID_IThreadPoolKnobs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMaxThreads ( _                             ' VTable offset = 12
     BYREF plcMaxThreads AS LONG _                      ' __out long *plcMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentThreads ( _                         ' VTable offset = 16
     BYREF plcCurrentThreads AS LONG _                  ' __out long *plcCurrentThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxThreads ( _                             ' VTable offset = 20
     BYVAL lcMaxThreads AS LONG _                       ' __in long lcMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeleteDelay ( _                            ' VTable offset = 24
     BYREF pmsecDeleteDelay AS LONG _                   ' __out long *pmsecDeleteDelay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeleteDelay ( _                            ' VTable offset = 28
     BYVAL msecDeleteDelay AS LONG _                    ' __in long msecDeleteDelay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxQueuedRequests ( _                      ' VTable offset = 32
     BYREF plcMaxQueuedRequests AS LONG _               ' __out long *plcMaxQueuedRequests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentQueuedRequests ( _                  ' VTable offset = 36
     BYREF plcCurrentQueuedRequests AS LONG _           ' __out long *plcCurrentQueuedRequests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxQueuedRequests ( _                      ' VTable offset = 40
     BYVAL lcMaxQueuedRequests AS LONG _                ' __in long lcMaxQueuedRequests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinThreads ( _                             ' VTable offset = 44
     BYVAL lcMinThreads AS LONG _                       ' __in long lcMinThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQueueDepth ( _                             ' VTable offset = 48
     BYVAL lcQueueDepth AS LONG _                       ' __in long lcQueueDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThreadPoolKnobs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComStaThreadPoolKnobs
' IID = {324B64FA-33B6-11d2-98B7-00C04F8EE1C4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComStaThreadPoolKnobs_INTERFACE_DEFINED)
    %IComStaThreadPoolKnobs_INTERFACE_DEFINED = 1

INTERFACE IComStaThreadPoolKnobs $IID_IComStaThreadPoolKnobs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMinThreadCount ( _                         ' VTable offset = 12
     BYVAL minThreads AS DWORD _                        ' __in DWORD minThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinThreadCount ( _                         ' VTable offset = 16
     BYREF minThreads AS DWORD _                        ' __out DWORD *minThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxThreadCount ( _                         ' VTable offset = 20
     BYVAL maxThreads AS DWORD _                        ' __in DWORD maxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxThreadCount ( _                         ' VTable offset = 24
     BYREF maxThreads AS DWORD _                        ' __out DWORD *maxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActivityPerThread ( _                      ' VTable offset = 28
     BYVAL activitiesPerThread AS DWORD _               ' __in DWORD activitiesPerThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityPerThread ( _                      ' VTable offset = 32
     BYREF activitiesPerThread AS DWORD _               ' __out DWORD *activitiesPerThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActivityRatio ( _                          ' VTable offset = 36
     BYVAL activityRatio AS DOUBLE _                    ' __in DOUBLE activityRatio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityRatio ( _                          ' VTable offset = 40
     BYREF activityRatio AS DOUBLE _                    ' __out DOUBLE *activityRatio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadCount ( _                            ' VTable offset = 44
     BYREF pdwThreads AS DWORD _                        ' __out DWORD *pdwThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueueDepth ( _                             ' VTable offset = 48
     BYREF pdwQDepth AS DWORD _                         ' __out DWORD *pdwQDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQueueDepth ( _                             ' VTable offset = 52
     BYVAL dwQDepth AS LONG _                           ' __in long dwQDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComStaThreadPoolKnobs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComMtaThreadPoolKnobs
' IID = {F9A76D2E-76A5-43eb-A0C4-49BEC8E48480}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComMtaThreadPoolKnobs_INTERFACE_DEFINED)
    %IComMtaThreadPoolKnobs_INTERFACE_DEFINED = 1

INTERFACE IComMtaThreadPoolKnobs $IID_IComMtaThreadPoolKnobs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MTASetMaxThreadCount ( _                      ' VTable offset = 12
     BYVAL dwMaxThreads AS DWORD _                      ' __in DWORD dwMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTAGetMaxThreadCount ( _                      ' VTable offset = 16
     BYREF pdwMaxThreads AS DWORD _                     ' __out DWORD *pdwMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTASetThrottleValue ( _                       ' VTable offset = 20
     BYVAL dwThrottle AS DWORD _                        ' __in DWORD dwThrottle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTAGetThrottleValue ( _                       ' VTable offset = 24
     BYREF pdwThrottle AS DWORD _                       ' __out DWORD *pdwThrottle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComMtaThreadPoolKnobs_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IComStaThreadPoolKnobs2
' IID = {324B64FA-33B6-11d2-98B7-00C04F8EE1C4}
' Inherited interface = IComStaThreadPoolKnobs
' ########################################################################################

#IF NOT %DEF(%IComStaThreadPoolKnobs2_INTERFACE_DEFINED)
    %IComStaThreadPoolKnobs2_INTERFACE_DEFINED = 1

INTERFACE IComStaThreadPoolKnobs2 $IID_IComStaThreadPoolKnobs2

   INHERIT IUnknown

   ' =====================================================================================
   ' IComStaThreadPoolKnobs Methods
   ' =====================================================================================
   METHOD MTASetMaxThreadCount ( _                      ' VTable offset = 12
     BYVAL dwMaxThreads AS DWORD _                      ' __in DWORD dwMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTAGetMaxThreadCount ( _                      ' VTable offset = 16
     BYREF pdwMaxThreads AS DWORD _                     ' __out DWORD *pdwMaxThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTASetThrottleValue ( _                       ' VTable offset = 20
     BYVAL dwThrottle AS DWORD _                        ' __in DWORD dwThrottle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MTAGetThrottleValue ( _                       ' VTable offset = 24
     BYREF pdwThrottle AS DWORD _                       ' __out DWORD *pdwThrottle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IComStaThreadPoolKnobs2 Methods
   ' =====================================================================================
   METHOD SetActivityPerThread ( _                      ' VTable offset = 28
     BYVAL activitiesPerThread AS DWORD _               ' __in DWORD activitiesPerThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityPerThread ( _                      ' VTable offset = 32
     BYREF activitiesPerThread AS DWORD _               ' __out DWORD *activitiesPerThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActivityRatio ( _                          ' VTable offset = 36
     BYVAL activityRatio AS DOUBLE _                    ' __in DOUBLE activityRatio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityRatio ( _                          ' VTable offset = 40
     BYREF activityRatio AS DOUBLE _                    ' __out DOUBLE *activityRatio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadCount ( _                            ' VTable offset = 44
     BYREF pdwThreads AS DWORD _                        ' __out DWORD *pdwThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueueDepth ( _                             ' VTable offset = 48
     BYREF pdwQDepth AS DWORD _                         ' __out DWORD *pdwQDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQueueDepth ( _                             ' VTable offset = 52
     BYVAL dwQDepth AS LONG _                           ' __in long dwQDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxCPULoad ( _                             ' VTable offset = 56
     BYREF pdwLoad AS DWORD _                           ' __out DWORD *pdwLoad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxCPULoad ( _                             ' VTable offset = 60
     BYVAL pdwLoad AS LONG _                            ' __in long pdwLoad
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCPUMetricEnabled ( _                       ' VTable offset = 64
     BYREF pbMetricEnabled AS LONG _                    ' __out BOOL *pbMetricEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCPUMetricEnabled ( _                       ' VTable offset = 68
     BYVAL bMetricEnabled AS LONG _                     ' __in BOOL bMetricEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreateThreadsAggressively ( _              ' VTable offset = 72
     BYREF pbMetricEnabled AS LONG _                    ' __out BOOL *pbMetricEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCreateThreadsAggressively ( _              ' VTable offset = 76
     BYVAL bMetricEnabled AS LONG _                     ' __in BOOL bMetricEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxCSR ( _                                 ' VTable offset = 80
     BYREF pdwCSR AS DWORD _                            ' __out DWORD *pdwCSR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxCSR ( _                                 ' VTable offset = 84
     BYVAL dwCSR AS LONG _                              ' __in long dwCSR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWaitTimeForThreadCleanup ( _               ' VTable offset = 88
     BYREF pdwThreadCleanupWaitTime AS DWORD _          ' __out DWORD *pdwThreadCleanupWaitTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWaitTimeForThreadCleanup ( _               ' VTable offset = 92
     BYVAL dwThreadCleanupWaitTime AS LONG _            ' __in long dwThreadCleanupWaitTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComStaThreadPoolKnobs2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IProcessInitializer
' IID = {1113f52d-dc7f-4943-aed6-88d04027e32a}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProcessInitializer_INTERFACE_DEFINED)
     %IProcessInitializer_INTERFACE_DEFINED = 1

INTERFACE IProcessInitializer $IID_IProcessInitializer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Startup ( _                                   ' VTable offset = 12
     BYVAL punkProcessControl AS IUnknown _             ' __in IUnknown *punkProcessControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessInitializer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServicePoolConfig
' IID = {a9690656-5bca-470c-8451-250c1f43a33e}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServicePoolConfig_INTERFACE_DEFINED)
    %IServicePoolConfig_INTERFACE_DEFINED = 1

INTERFACE IServicePoolConfig $IID_IServicePoolConfig

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY SET MaxPoolSize ( _                         ' VTable offset = 12
     BYVAL dwMaxPool AS DWORD _                         ' __in DWORD dwMaxPool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxPoolSize ( _                         ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out DWORD *pdwMaxPool
   ' =====================================================================================
   PROPERTY SET MinPoolSize ( _                         ' VTable offset = 20
     BYVAL dwMinPool AS DWORD _                         ' __in DWORD dwMinPool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinPoolSize ( _                         ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out DWORD *pdwMinPool
   ' =====================================================================================
   PROPERTY SET CreationTimeout ( _                     ' VTable offset = 28
     BYVAL dwCreationTimeout AS DWORD _                 ' __in DWORD dwCreationTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreationTimeout ( _                     ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out DWORD *pdwCreationTimeout
   ' =====================================================================================
   PROPERTY SET TransactionAffinity ( _                 ' VTable offset = 36
     BYVAL fTxAffinity AS LONG _                        ' __in BOOL fTxAffinity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransactionAffinity ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *pfTxAffinity
   ' =====================================================================================
   PROPERTY SET ClassFactory ( _                        ' VTable offset = 44
     BYVAL pFactory AS IClassFactory _                  ' __in IClassFactory *pFactory
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClassFactory ( _                        ' VTable offset = 48
   ) AS IClassFactory                                   ' __retval_out IClassFactory **pFactory
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServicePoolConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IServicePool
' IID = {b302df81-ea45-451e-99a2-09f9fd1b1e13}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServicePool_INTERFACE_DEFINED)
    %IServicePool_INTERFACE_DEFINED = 1

INTERFACE IServicePool $IID_IServicePool

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pPoolConfig AS IUnknown _                    ' __in IUnknown *pPoolConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServicePool_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IManagedPooledObj
' IID = {c5da4bea-1b42-4437-8926-b6a38860a770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IManagedPooledObj_INTERFACE_DEFINED)
    %IManagedPooledObj_INTERFACE_DEFINED = 1

INTERFACE IManagedPooledObj $IID_IManagedPooledObj

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHeld ( _                                   ' VTable offset = 12
     BYVAL m_bHeld AS LONG _                            ' __in BOOL m_bHeld
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManagedPooledObj_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IManagedPoolAction
' IID = {da91b74e-5388-4783-949d-c1cd5fb00506}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IManagedPoolAction_INTERFACE_DEFINED)
    %IManagedPoolAction_INTERFACE_DEFINED = 1

INTERFACE IManagedPoolAction $IID_IManagedPoolAction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LastRelease ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManagedPoolAction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IManagedObjectInfo
' IID = {1427c51a-4584-49d8-90a0-c50d8086cbe9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IManagedObjectInfo_INTERFACE_DEFINED)
    %IManagedObjectInfo_INTERFACE_DEFINED = 1

INTERFACE IManagedObjectInfo $IID_IManagedObjectInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIUnknown ( _                               ' VTable offset = 12
     BYREF pUnk AS IUnknown _                           ' __out IUnknown **pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIObjectControl ( _                         ' VTable offset = 16
     BYREF pCtrl AS IObjectControl _                    ' __out IObjectControl **pCtrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInPool ( _                                 ' VTable offset = 20
     BYVAL bInPool AS LONG _                            ' __in BOOL bInPool
   , BYVAL pPooledObj AS IManagedPooledObj _            ' __in IManagedPooledObj *pPooledObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWrapperStrength ( _                        ' VTable offset = 24
     BYVAL bStrong AS LONG _                            ' __in BOOL bStrong
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManagedObjectInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAppDomainHelper
' IID = {1427c51a-4584-49d8-90a0-c50d8086cbe9}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAppDomainHelper_INTERFACE_DEFINED)
    %IAppDomainHelper_INTERFACE_DEFINED = 1

INTERFACE IAppDomainHelper $IID_IAppDomainHelper

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL pUnkAD AS IUnknown _                         ' __in IUnknown *pUnkAD
   , BYVAL pfnShutdownCB AS DWORD _                     ' __in pfnShutdownCB
   , BYVAL pPool AS DWORD _                             ' __in void *pPool
   )                                                    ' void
   ' =====================================================================================
   METHOD DoCallback ( _                                ' VTable offset = 32
     BYVAL pUnkAD AS IUnknown _                         ' __in IUnknown *pUnkAD
   , BYVAL pfnCallbackCB AS DWORD _                     ' __in pfnCallbackCB
   , BYVAL pPool AS DWORD _                             ' __in void *pPool
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppDomainHelper_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAssemblyLocator
' IID = {391ffbb9-a8ee-432a-abc8-baa238dab90f}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAssemblyLocator_INTERFACE_DEFINED)
    %IAssemblyLocator_INTERFACE_DEFINED = 1

INTERFACE IAssemblyLocator $IID_IAssemblyLocator

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetModules ( _                                ' VTable offset = 28
     BYVAL applicationDir AS WSTRING _                  ' __in BSTR applicationDir
   , BYVAL applicationName AS WSTRING _                 ' __in BSTR applicationName
   , BYVAL assemblyName AS WSTRING _                    ' __in BSTR assemblyName
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pModules
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyLocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IManagedActivationEvents
' IID = {a5f325af-572f-46da-b8ab-827c3d95d99e}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IManagedActivationEvents_INTERFACE_DEFINED)
    %IManagedActivationEvents_INTERFACE_DEFINED = 1

INTERFACE IManagedActivationEvents $IID_IManagedActivationEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateManagedStub ( _                         ' VTable offset = 12
     BYVAL pInfo AS IManagedObjectInfo _                ' __in IManagedObjectInfo *pInfo
   , BYVAL fDist AS LONG _                              ' __in BOOL fDist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyManagedStub ( _                        ' VTable offset = 16
     BYVAL pInfo AS IManagedObjectInfo _                ' __in IManagedObjectInfo *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManagedActivationEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISendMethodEvents
' IID = {2732fd59-b2b4-4d44-878c-8b8f09626008}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISendMethodEvents_INTERFACE_DEFINED)
    %ISendMethodEvents_INTERFACE_DEFINED = 1

INTERFACE ISendMethodEvents $IID_ISendMethodEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SendMethodCall ( _                            ' VTable offset = 12
     BYVAL pIdentity AS DWORD _                         ' __in const void *pIdentity
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL dwMeth AS DWORD _                            ' __in DWORD dwMeth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendMethodReturn ( _                          ' VTable offset = 16
     BYVAL pIdentity AS DWORD _                         ' __in const void *pIdentity
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL dwMeth AS DWORD _                            ' __in DWORD dwMeth
   , BYVAL hrCall AS LONG _                             ' __in HRESULT hrCall
   , BYVAL hrServer AS LONG _                           ' __in HRESULT hrServer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISendMethodEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionResourcePool
' IID = {C5FEB7C1-346A-11D1-B1CC-00AA00BA3258}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionResourcePool_INTERFACE_DEFINED)
    %ITransactionResourcePool_INTERFACE_DEFINED = 1

INTERFACE ITransactionResourcePool $IID_ITransactionResourcePool

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PutResource ( _                               ' VTable offset = 12
     BYVAL pPool AS IObjPool _                          ' __in IObjPool *pPool
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 16
     BYVAL pPool AS IObjPool _                          ' __in IObjPool *pPool
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionResourcePool_INTERFACE_DEFINED__ */


DECLARE FUNCTION MTSCreateActivity CDECL IMPORT "comsvcs.dll" ALIAS "MTSCreateActivity" ( _
   BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppObj AS ANY _                                 ' __out void ** ppObj
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMTSCall
' IID = {51372AEF-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMTSCall_INTERFACE_DEFINED)
    %IMTSCall_INTERFACE_DEFINED = 1

INTERFACE IMTSCall $IID_IMTSCall

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCall ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMTSCall_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IContextProperties
' IID = {D396DA85-BF8F-11d1-BBAE-00C04FC2FA5F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextProperties_INTERFACE_DEFINED)
    %IContextProperties_INTERFACE_DEFINED = 1

INTERFACE IContextProperties $IID_IContextProperties

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT *pProperty
   ' =====================================================================================
   METHOD EnumNames ( _                                 ' VTable offset = 20
   ) AS IEnumNames                                      ' __retval_out IEnumNames **ppenum
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYVAL name AS WSTRING _                            ' __in BSTR name
   , BYVAL property AS VARIANT _                        ' __in VARIANT property
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveProperty ( _                            ' VTable offset = 28
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjPool
' IID = {7D8805A0-2EA7-11D1-B1CC-00AA00BA3258}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjPool_INTERFACE_DEFINED)
    %IObjPool_INTERFACE_DEFINED = 1

INTERFACE IObjPool $IID_IObjPool

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reserved1 ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved2 ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved3 ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved4 ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutEndTx ( _                                  ' VTable offset = 28
     BYVAL pObj AS IUnknown _                           ' __in IUnknown *pObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved5 ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved6 ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjPool_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITransactionProperty
' IID = {788ea814-87b1-11d1-bba6-00c04fc2fa5f}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionProperty_INTERFACE_DEFINED)
    %ITransactionProperty_INTERFACE_DEFINED = 1

INTERFACE ITransactionProperty $IID_ITransactionProperty

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reserved1 ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved2 ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved3 ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved4 ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved5 ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved6 ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved7 ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved8 ( _                                 ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved9 ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionResourcePool ( _                ' VTable offset = 48
     BYREF ppTxPool AS ITransactionResourcePool _       ' __out ITransactionResourcePool **ppTxPool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved10 ( _                                ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved11 ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved12 ( _                                ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved13 ( _                                ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved14 ( _                                ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved15 ( _                                ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved16 ( _                                ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved17 ( _                                ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMTSActivity
' IID = {51372AF0-CAE7-11CF-BE81-00AA00A2FA25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMTSActivity_INTERFACE_DEFINED)
    %IMTSActivity_INTERFACE_DEFINED = 1

INTERFACE IMTSActivity $IID_IMTSActivity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SynchronousCall ( _                           ' VTable offset = 12
     BYVAL pCall AS IMTSCall _                          ' __in IMTSCall *pCall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncCall ( _                                 ' VTable offset = 16
     BYVAL pCall AS IMTSCall _                          ' __in IMTSCall *pCall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved1 ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToCurrentThread ( _                       ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnbindFromThread ( _                          ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMTSActivity_INTERFACE_DEFINED__ */


' enum Error_Constants
%mtsErrCtxAborted                   = &H8004E002&   ' -2147164158
%mtsErrCtxAborting                  = &H8004E003&   ' -2147164157
%mtsErrCtxNoContext                 = &H8004E004&   ' -2147164156
%mtsErrCtxNotRegistered             = &H8004E005&   ' -2147164155
%mtsErrCtxSynchTimeout              = &H8004E006&   ' -2147164154
%mtsErrCtxOldReference              = &H8004E007&   ' -2147164153
%mtsErrCtxRoleNotFound              = &H8004E00C&   ' -2147164148
%mtsErrCtxNoSecurity                = &H8004E00D&   ' -2147164147
%mtsErrCtxWrongThread               = &H8004E00E&   ' -2147164146
%mtsErrCtxTMNotAvailable            = &H8004E00F&   ' -2147164145
%comQCErrApplicationNotQueued       = &H80110600&   ' -2146368000
%comQCErrNoQueueableInterfaces      = &H80110601&   ' -2146367999
%comQCErrQueuingServiceNotAvailable = &H80110602&   ' -2146367998
%comQCErrQueueTransactMismatch      = &H80110603&   ' -2146367997
%comqcErrRecorderMarshalled         = &H80110604&   ' -2146367996
%comqcErrOutParam                   = &H80110605&   ' -2146367995
%comqcErrRecorderNotTrusted         = &H80110606&   ' -2146367994
%comqcErrPSLoad                     = &H80110607&   ' -2146367993
%comqcErrMarshaledObjSameTxn        = &H80110608&   ' -2146367992
%comqcErrInvalidMessage             = &H80110650&   ' -2146367920
%comqcErrMsmqSidUnavailable         = &H80110651&   ' -2146367919
%comqcErrWrongMsgExtension          = &H80110652&   ' -2146367918
%comqcErrMsmqServiceUnavailable     = &H80110653&   ' -2146367917
%comqcErrMsgNotAuthenticated        = &H80110654&   ' -2146367916
%comqcErrMsmqConnectorUsed          = &H80110655&   ' -2146367915
%comqcErrBadMarshaledObject         = &H80110656&   ' -2146367914


' enum LockModes
%LockModes_LockSetGet = 0
%LockModes_LockMethod = %LockModes_LockSetGet + 1

' enum ReleaseModes
%ReleaseModes_Standard = 0
%ReleaseModes_Process  = %ReleaseModes_Standard + 1

#IF NOT %DEF(%tagCrmFlags_DEFINED)
%tagCrmFlags_DEFINED = 1
' enum CRMFLAGS
%CRMFLAG_FORGETTARGET          = &H1
%CRMFLAG_WRITTENDURINGPREPARE  = &H2
%CRMFLAG_WRITTENDURINGCOMMIT   = &H4
%CRMFLAG_WRITTENDURINGABORT    = &H8
%CRMFLAG_WRITTENDURINGRECOVERY = &H10
%CRMFLAG_WRITTENDURINGREPLAY   = &H20
%CRMFLAG_REPLAYINPROGRESS      = &H40
#ENDIF ' _tagCrmFlags_

#IF NOT %DEF(%tagCrmRegFlags_DEFINED)
%tagCrmRegFlags_DEFINED = 1
' enum CRMREGFLAGS
%CRMREGFLAG_PREPAREPHASE         = &H1
%CRMREGFLAG_COMMITPHASE          = &H2
%CRMREGFLAG_ABORTPHASE           = &H4
%CRMREGFLAG_ALLPHASES            = &H7
%CRMREGFLAG_FAILIFINDOUBTSREMAIN = &H10
#ENDIF ' _tagCrmRegFlags_

$LIBID_COMSVCSLib = GUID$("{2A005C00-A5DE-11CF-9E66-00AA00A3F464}")


' ########################################################################################
' The following interfaces are not included in the ComSvcs.h file distributed with the
' Windows SDK for Windows Server 2003 R2 or Windows Vista SDK.
' ########################################################################################

' ########################################################################################
' Interface name = ISecurityCertificateColl
' IID = {CAFC823B-B441-11D1-B82B-0000F8757E2A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISecurityCertificateColl_INTERFACE_DEFINED)
    %ISecurityCertificateColl_INTERFACE_DEFINED = 1

INTERFACE ISecurityCertificateColl $IID_ISecurityCertificateColl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* plCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS VARIANT                                         ' __retval_out VARIANT* pItem
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityCertificateColl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICheckFusionConfig
' IID = {0FF5A96F-11FC-47D1-BAA6-25DD347E7242}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICheckFusionConfig_INTERFACE_DEFINED)
    %ICheckFusionConfig_INTERFACE_DEFINED = 1

INTERFACE ICheckFusionConfig $IID_ICheckFusionConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSameFusionConfig ( _                        ' VTable offset = 12
     BYREF wszFusionName AS WSTRINGZ _                  ' __in LPWSTR wszFusionName
   , BYREF wszFusionDirectory AS WSTRINGZ _             ' __in LPWSTR wszFusionDirectory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICheckFusionConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMTxAS
' IID = {74C08641-CEDB-11CF-8B49-00AA00B8A790}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMTxAS_INTERFACE_DEFINED)
    %IMTxAS_INTERFACE_DEFINED = 1

INTERFACE IMTxAS $IID_IMTxAS

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetObjectContext <1610743808> ( _             ' VTable offset = 28
   ) AS ObjectContext                                   ' __retval_out ObjectContext** ppContext
   ' =====================================================================================
   METHOD SafeRef <1610743809> ( _                      ' VTable offset = 32
     BYVAL vRefIn AS VARIANT _                          ' __in VARIANT vRefIn
   ) AS VARIANT                                         ' __retval_out VARIANT* pvRefOut
   ' =====================================================================================
   METHOD RecycleSurrogate <1610743810> ( _             ' VTable offset = 36
     BYVAL lReasonCode AS LONG _                        ' __in long lReasonCode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMTxAS_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDispenserManagerShutdownGuarantee
' IID = {5CB31E11-2B5F-11CF-BE10-00AA00A2FA25}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDispenserManagerShutdownGuarantee_INTERFACE_DEFINED)
    %IDispenserManagerShutdownGuarantee_INTERFACE_DEFINED = 1

INTERFACE IDispenserManagerShutdownGuarantee $IID_IDispenserManagerShutdownGuarantee

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsComPlusApp ( _                              ' VTable offset = 12
     BYREF LONG _                                       ' __out long* pfIsComPlusApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispenserManagerShutdownGuarantee_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventServer
' IID = {F1CB0608-EC04-11D1-93AE-00AA00BA3258}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventServer_INTERFACE_DEFINED)
    %IEventServer_INTERFACE_DEFINED = 1

INTERFACE IEventServer $IID_IEventServer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DispatchManyEvents ( _                        ' VTable offset = 12
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF appGuid AS GUID _                            ' __in GUID* appGuid
   , BYVAL dwEvents AS DWORD _                          ' __in unsigned long dwEvents
   , BYVAL cbSize AS DWORD _                            ' __in unsigned long cbSize
   , BYVAL pBuf AS BYTE PTR _                           ' __in unsigned char* pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DispatchOneEvent ( _                          ' VTable offset = 16
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF appGuid AS GUID _                            ' __in GUID* appGuid
   , BYVAL cbSize AS DWORD _                            ' __in unsigned long cbSize
   , BYVAL pBuf AS BYTE PTR _                           ' __in unsigned char* pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddProcess ( _                                ' VTable offset = 20
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF guidApp AS GUID _                            ' __in GUID* guidApp
   , BYREF pdwInitialEventMask AS DWORD _               ' __out unsigned long* pdwInitialEventMask
   , BYREF ppUnkCallfactory AS IUnknown _               ' __out IUnknown** ppUnkCallfactory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProcess ( _                             ' VTable offset = 24
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallFactoryObject ( _                      ' VTable offset = 28
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF ppUnkCallfactory AS IUnknown _               ' __out IUnknown** ppUnkCallfactory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventServer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEventServer2
' IID = {378F3CA7-BD24-481C-8DC3-5E5ECE1BCAD7}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventServer2_INTERFACE_DEFINED)
    %IEventServer2_INTERFACE_DEFINED = 1

INTERFACE IEventServer2 $IID_IEventServer2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddProcess2 ( _                               ' VTable offset = 12
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF guidApp AS GUID _                            ' __in GUID* guidApp
   , BYREF guidAppInstance AS GUID _                    ' __in GUID* guidAppInstance
   , BYREF guidPartition AS GUID _                      ' __in GUID* guidPartition
   , BYVAL dwNumberSinks AS DWORD _                     ' __in unsigned long dwNumberSinks
   , BYREF pdwInitialEventMask AS DWORD _               ' __out unsigned long* pdwInitialEventMask
   , BYREF pdwInitialMetMasks AS DWORD _                ' __in_out unsigned long* pdwInitialMetMasks
   , BYREF ppUnkCallfactory AS IUnknown _               ' __out IUnknown** ppUnkCallfactory
   , BYREF pTraceHandle AS QUAD _                       ' __out uint64* pTraceHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveProcess2 ( _                            ' VTable offset = 16
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateEventMasks ( _                          ' VTable offset = 20
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYVAL dwNumberSinks AS DWORD _                     ' __in unsigned long dwNumberSinks
   , BYVAL dwEventMasksIn AS DWORD _                    ' __in unsigned long dwEventMasksIn
   , BYREF pdwEventMaskOut AS DWORD _                   ' __out unsigned long* pdwEventMaskOut
   , BYREF pdwMetMasksInOut AS DWORD _                  ' __in_out unsigned long* pdwMetMasksInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventServer2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IProcessTerminateNotify
' IID = {3194B4CF-EF32-11D1-93AE-00AA00BA3258}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProcessTerminateNotify_INTERFACE_DEFINED)
    %IProcessTerminateNotify_INTERFACE_DEFINED = 1

INTERFACE IProcessTerminateNotify $IID_IProcessTerminateNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProcessShutdown ( _                           ' VTable offset = 12
     BYVAL dwPid AS DWORD _                             ' __in unsigned long dwPid
   , BYREF guidAppInstance AS GUID _                    ' __in GUID* guidAppInstance
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessTerminateNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IReceiveAppData
' IID = {413DAFB0-BCF4-11D1-861D-0080C729264D}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReceiveAppData_INTERFACE_DEFINED)
    %IReceiveAppData_INTERFACE_DEFINED = 1

INTERFACE IReceiveAppData $IID_IReceiveAppData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYREF pApplId AS GUID _                            ' __in GUID* pApplId
   , BYREF pguidApplPartitionId AS GUID _               ' __in GUID* pguidApplPartitionId
   , BYREF pApplInstanceId AS GUID _                    ' __in GUID* pApplInstanceId
   , BYVAL pwszProcessName AS LONG _                    ' __in tagCOMPLUS_APPTYPE eAppType
   , BYREF pwszProcessName AS WSTRINGZ _                ' __in LPWSTR pwszProcessName
   , BYVAL pUnkPackageObject AS IUnknown _              ' __in IUnknown* pUnkPackageObject
   , BYVAL dwAppProcessId AS DWORD _                    ' __in unsigned long dwAppProcessId
   , BYVAL dwState AS DWORD _                           ' __in unsigned long dwState
   , BYREF pRecycleInfo AS RECYCLE_INFO _               ' __in RECYCLE_INFO* pRecycleInfo
   , BYREF pidApp AS DWORD _                            ' __out unsigned long* pidApp
   , BYREF pPushRate AS DWORD _                         ' __out unsigned long* pPushRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushAppData ( _                               ' VTable offset = 16
     BYVAL idApp AS DWORD _                             ' __in unsigned long idApp
   , BYVAL appData AS APPSTATISTICS _                   ' __in APPSTATISTICS appData
   , BYVAL dwAppState AS DWORD _                        ' __in unsigned long dwAppState
   , BYVAL nCLSIDs AS DWORD _                           ' __in unsigned long nCLSIDs
   , BYREF clsids AS CLSIDDATA2 _                       ' __in CLSIDDATA2* clsids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unregister ( _                                ' VTable offset = 20
     BYVAL idApp AS DWORD _                             ' __in unsigned long idApp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecycleCallingProcess ( _                     ' VTable offset = 24
     BYVAL idApp AS DWORD _                             ' __in unsigned long idApp
   , BYVAL lReasonCode AS LONG _                        ' __in long lReasonCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReceiveAppData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetAppData
' IID = {B60040E0-BCF3-11D1-861D-0080C729264D}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetAppData_INTERFACE_DEFINED)
    %IGetAppData_INTERFACE_DEFINED = 1

INTERFACE IGetAppData $IID_IGetAppData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPushRate ( _                               ' VTable offset = 12
     BYVAL dwPushRate AS DWORD _                        ' __in unsigned long dwPushRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApps ( _                                   ' VTable offset = 16
     BYREF nApps AS DWORD _                             ' __out unsigned long* nApps
   , BYREF aAppData AS APPDATA _                        ' __out appData** aAppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 20
     BYVAL idApp AS DWORD _                             ' __in unsigned long idApp
   , BYREF nCLSIDs AS DWORD _                           ' __out unsigned long* nCLSIDs
   , BYREF aAppData AS CLSIDDATA _                      ' __out CLSIDDATA** aAppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClsidData ( _                              ' VTable offset = 24
     BYVAL idApp AS DWORD _                             ' __in unsigned long idApp
   , BYVAL clsid AS GUID _                              ' __in GUID clsid
   , BYREF ppAppData AS CLSIDDATA _                     ' __out CLSIDDATA** ppAppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetAppData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IProcessDump
' IID = {23C9DD26-2355-4FE2-84DE-F779A238ADBD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IProcessDump_INTERFACE_DEFINED)
    %IProcessDump_INTERFACE_DEFINED = 1

INTERFACE IProcessDump $IID_IProcessDump

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsSupported <1> ( _                           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD DumpProcess <2> ( _                           ' VTable offset = 32
     BYVAL bstrInstanceID AS WSTRING _                  ' __in BSTR bstrInstanceID
   , BYVAL bstrDirectory AS WSTRING _                   ' __in BSTR bstrDirectory
   , BYVAL dwMaxImages AS DWORD _                       ' __in unsigned long dwMaxImages
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDumpFile
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProcessDump_INTERFACE_DEFINED__ */
