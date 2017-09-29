' ########################################################################################
' Microsoft Windows
' File: dts.inc
' Library name: DTSLib
' Version: 1.0, Locale ID = 0
' Library GUID: {D1D9A51E-B4FE-420B-97B1-28A383EF9168}
' Path: C:\Archivos de programa\Microsoft SQL Server\90\DTS\Binn\DTS.dll
' Contents: Microsoft DTS Runtime 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DTS_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {4CF60474-BA87-4AC2-B9F3-B7B9179D4183}
$PROGID_ConnectionManagerAdo1 = "DTS.ConnectionManagerAdo.1"
' CLSID = {72692A11-F5CC-42B8-869D-84E7C8E48B14}
$PROGID_ConnectionManagerAdoNet1 = "DTS.ConnectionManagerAdoNet.1"
' CLSID = {95FEC9EF-02F1-4BC9-8AB3-0FC55DA05C86}
$PROGID_ConnectionManagerExcel1 = "DTS.ConnectionManagerExcel.1"
' CLSID = {41F5EFE4-E91A-4EB0-BF10-D40FD48B3C03}
$PROGID_ConnectionManagerFile1 = "DTS.ConnectionManagerFile.1"
' CLSID = {CFADE22A-6C79-42E7-81B6-DE1BC35CEE55}
$PROGID_ConnectionManagerFlatFile1 = "DTS.ConnectionManagerFlatFile.1"
' CLSID = {E9C37981-F683-4961-ACAB-97B161F87194}
$PROGID_ConnectionManagerFtp1 = "DTS.ConnectionManagerFtp.1"
' CLSID = {EF760105-812C-4D97-AF60-872FA0BAE543}
$PROGID_ConnectionManagerHttp1 = "DTS.ConnectionManagerHttp.1"
' CLSID = {B29B7D68-F066-446E-9F48-D4C0E8047708}
$PROGID_ConnectionManagerMultiFile1 = "DTS.ConnectionManagerMultiFile.1"
' CLSID = {470CE484-8202-44FF-8DB0-451A60CC77A8}
$PROGID_ConnectionManagerMultiFlatFile1 = "DTS.ConnectionManagerMultiFlatFile.1"
' CLSID = {5F2826BC-648B-4F3E-B930-587F4EF331D4}
$PROGID_ConnectionManagerOdbc1 = "DTS.ConnectionManagerOdbc.1"
' CLSID = {D71D1AA0-D9D7-46C4-8993-61191E25F133}
$PROGID_ConnectionManagerOLAP1 = "DTS.ConnectionManagerOlap.1"
' CLSID = {9B5D63AB-A629-4A56-9F3E-B1044134B649}
$PROGID_ConnectionManagerOleDb1 = "DTS.ConnectionManagerOleDb.1"
' CLSID = {449D17F6-57B4-4CA8-98FD-4838B0157A1B}
$PROGID_ConnectionManagerSqlMobile1 = "DTS.ConnectionManagerSqlMobile.1"
' CLSID = {8EB8005E-EF8C-492D-8848-C24FDE5CA0B2}
$PROGID_ExpressionEvaluator1 = "DTS.DTSExprEvaluator.1"
' CLSID = {62C3D0DC-C6A3-4A08-84F3-6028B2452F41}
$PROGID_ForEachItemEnumerator1 = "DTS.ForEachItemEnumerator.1"
' CLSID = {97634F75-1DC7-4F1F-8A4C-DAF0E13AAA22}
$PROGID_LogProviderEventLog1 = "DTS.LogProviderEventLog.1"
' CLSID = {5C0B8D21-E9AA-462E-BA34-30FF5F7A42A1}
$PROGID_LogProviderSQLProfiler1 = "DTS.LogProviderSQLProfiler.1"
' CLSID = {6AA833A1-E4B2-4431-831B-DE695049DC61}
$PROGID_LogProviderSQLServer1 = "DTS.LogProviderSQLServer.1"
' CLSID = {59B2C6A5-663F-4C20-8863-C83F9B72E2EB}
$PROGID_LogProviderTextFile1 = "DTS.LogProviderTextFile.1"
' CLSID = {AFED6884-619C-484F-9A09-F42D56E1A7EA}
$PROGID_LogProviderXMLFile1 = "DTS.LogProviderXMLFile.1"
' CLSID = {E80FE1DB-D1AA-4D6B-BA7E-040D424A925C}
$PROGID_PackageNeutral1 = "DTS.PackageNeutral.1"
' CLSID = {1838B317-D927-4ED4-8B5C-A0A52D6F6CBE}
$PROGID_PackageRemote1 = "DTS.PackageRemote.1"
' CLSID = {0DE981B0-ED8A-423C-8CF6-AE5E1FE8295A}
$PROGID_TaskCreator1 = "DTS.TaskCreator.1"
' CLSID = {E44847F1-FD8C-4251-B5DA-B04BB22E236E}
$PROGID_Application1 = "MSDTS.Application.1"
' CLSID = {697AC67E-FDD5-46D1-90D7-F3D0DF1B2A47}
$PROGID_Package1 = "MSDTS.Package.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {4CF60474-BA87-4AC2-B9F3-B7B9179D4183}
$PROGID_ConnectionManagerAdo = "DTS.ConnectionManagerAdo"
' CLSID = {72692A11-F5CC-42B8-869D-84E7C8E48B14}
$PROGID_ConnectionManagerAdoNet = "DTS.ConnectionManagerAdoNet"
' CLSID = {95FEC9EF-02F1-4BC9-8AB3-0FC55DA05C86}
$PROGID_ConnectionManagerExcel = "DTS.ConnectionManagerExcel"
' CLSID = {41F5EFE4-E91A-4EB0-BF10-D40FD48B3C03}
$PROGID_ConnectionManagerFile = "DTS.ConnectionManagerFile"
' CLSID = {CFADE22A-6C79-42E7-81B6-DE1BC35CEE55}
$PROGID_ConnectionManagerFlatFile = "DTS.ConnectionManagerFlatFile"
' CLSID = {E9C37981-F683-4961-ACAB-97B161F87194}
$PROGID_ConnectionManagerFtp = "DTS.ConnectionManagerFtp"
' CLSID = {EF760105-812C-4D97-AF60-872FA0BAE543}
$PROGID_ConnectionManagerHttp = "DTS.ConnectionManagerHttp"
' CLSID = {B29B7D68-F066-446E-9F48-D4C0E8047708}
$PROGID_ConnectionManagerMultiFile = "DTS.ConnectionManagerMultiFile"
' CLSID = {470CE484-8202-44FF-8DB0-451A60CC77A8}
$PROGID_ConnectionManagerMultiFlatFile = "DTS.ConnectionManagerMultiFlatFile"
' CLSID = {5F2826BC-648B-4F3E-B930-587F4EF331D4}
$PROGID_ConnectionManagerOdbc = "DTS.ConnectionManagerOdbc"
' CLSID = {D71D1AA0-D9D7-46C4-8993-61191E25F133}
$PROGID_ConnectionManagerOLAP = "DTS.ConnectionManagerOlap"
' CLSID = {9B5D63AB-A629-4A56-9F3E-B1044134B649}
$PROGID_ConnectionManagerOleDb = "DTS.ConnectionManagerOleDb"
' CLSID = {449D17F6-57B4-4CA8-98FD-4838B0157A1B}
$PROGID_ConnectionManagerSqlMobile = "DTS.ConnectionManagerSqlMobile"
' CLSID = {8EB8005E-EF8C-492D-8848-C24FDE5CA0B2}
$PROGID_ExpressionEvaluator = "DTS.DTSExprEvaluator"
' CLSID = {62C3D0DC-C6A3-4A08-84F3-6028B2452F41}
$PROGID_ForEachItemEnumerator = "DTS.ForEachItemEnumerator"
' CLSID = {97634F75-1DC7-4F1F-8A4C-DAF0E13AAA22}
$PROGID_LogProviderEventLog = "DTS.LogProviderEventLog"
' CLSID = {5C0B8D21-E9AA-462E-BA34-30FF5F7A42A1}
$PROGID_LogProviderSQLProfiler = "DTS.LogProviderSQLProfiler"
' CLSID = {6AA833A1-E4B2-4431-831B-DE695049DC61}
$PROGID_LogProviderSQLServer = "DTS.LogProviderSQLServer"
' CLSID = {59B2C6A5-663F-4C20-8863-C83F9B72E2EB}
$PROGID_LogProviderTextFile = "DTS.LogProviderTextFile"
' CLSID = {AFED6884-619C-484F-9A09-F42D56E1A7EA}
$PROGID_LogProviderXMLFile = "DTS.LogProviderXMLFile"
' CLSID = {E80FE1DB-D1AA-4D6B-BA7E-040D424A925C}
$PROGID_PackageNeutral = "DTS.PackageNeutral"
' CLSID = {1838B317-D927-4ED4-8B5C-A0A52D6F6CBE}
$PROGID_PackageRemote = "DTS.PackageRemote"
' CLSID = {0DE981B0-ED8A-423C-8CF6-AE5E1FE8295A}
$PROGID_TaskCreator = "DTS.TaskCreator"
' CLSID = {E44847F1-FD8C-4251-B5DA-B04BB22E236E}
$PROGID_Application = "MSDTS.Application"
' CLSID = {697AC67E-FDD5-46D1-90D7-F3D0DF1B2A47}
$PROGID_Package = "MSDTS.Package"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ConnectionManagerHost = GUID$("{26589CED-C535-4F78-9BDB-70AF0E47F6B7}")
$CLSID_EventHandler = GUID$("{26A1FF19-9E51-4559-AA34-863CA538A312}")
$CLSID_ForEachEnumeratorHost = GUID$("{62C3D0AA-C6A3-4A08-84F3-6028B2452F41}")
$CLSID_ForEachLoop = GUID$("{B5573329-4553-43DD-A69B-32BC62DAC2E8}")
$CLSID_ForLoop = GUID$("{B5573329-4553-43DD-A69B-32BC62DAC2E9}")
$CLSID_FTPClientConnection90 = GUID$("{DF080E50-E19C-49BF-A9FB-8827728076E2}")
$CLSID_HttpClientConnection90 = GUID$("{CFD736A9-18A5-4B15-B789-3DC16BD34B49}")
$CLSID_LogProviderHost = GUID$("{8C944A9F-20E0-45BC-BE0B-1BD48BD48082}")
$CLSID_PrecedenceConstraint = GUID$("{40E6E566-0673-47AB-8AC5-9F03DE6E214D}")
$CLSID_Sequence = GUID$("{8BB6C57F-0A67-4EFA-BEA8-A1DABB606079}")
$CLSID_TaskHost = GUID$("{873FD67B-C60A-46A9-9301-86FA553184A8}")
$CLSID_Variable = GUID$("{7D70894F-4655-48C6-97F1-C50FD8DAEB9C}")
$CLSID_VariableDispenser = GUID$("{061266F2-C852-4E0B-9E2F-2A2FCC863CBC}")
$CLSID_ConnectionManagerAdo = GUID$("{4CF60474-BA87-4AC2-B9F3-B7B9179D4183}")
$CLSID_ConnectionManagerAdoNet = GUID$("{72692A11-F5CC-42B8-869D-84E7C8E48B14}")
$CLSID_ConnectionManagerExcel = GUID$("{95FEC9EF-02F1-4BC9-8AB3-0FC55DA05C86}")
$CLSID_ConnectionManagerFile = GUID$("{41F5EFE4-E91A-4EB0-BF10-D40FD48B3C03}")
$CLSID_ConnectionManagerFlatFile = GUID$("{CFADE22A-6C79-42E7-81B6-DE1BC35CEE55}")
$CLSID_ConnectionManagerFtp = GUID$("{E9C37981-F683-4961-ACAB-97B161F87194}")
$CLSID_ConnectionManagerHttp = GUID$("{EF760105-812C-4D97-AF60-872FA0BAE543}")
$CLSID_ConnectionManagerMultiFile = GUID$("{B29B7D68-F066-446E-9F48-D4C0E8047708}")
$CLSID_ConnectionManagerMultiFlatFile = GUID$("{470CE484-8202-44FF-8DB0-451A60CC77A8}")
$CLSID_ConnectionManagerOdbc = GUID$("{5F2826BC-648B-4F3E-B930-587F4EF331D4}")
$CLSID_ConnectionManagerOLAP = GUID$("{D71D1AA0-D9D7-46C4-8993-61191E25F133}")
$CLSID_ConnectionManagerOleDb = GUID$("{9B5D63AB-A629-4A56-9F3E-B1044134B649}")
$CLSID_ConnectionManagerSqlMobile = GUID$("{449D17F6-57B4-4CA8-98FD-4838B0157A1B}")
$CLSID_ExpressionEvaluator = GUID$("{8EB8005E-EF8C-492D-8848-C24FDE5CA0B2}")
$CLSID_ForEachItemEnumerator = GUID$("{62C3D0DC-C6A3-4A08-84F3-6028B2452F41}")
$CLSID_LogProviderEventLog = GUID$("{97634F75-1DC7-4F1F-8A4C-DAF0E13AAA22}")
$CLSID_LogProviderSQLProfiler = GUID$("{5C0B8D21-E9AA-462E-BA34-30FF5F7A42A1}")
$CLSID_LogProviderSQLServer = GUID$("{6AA833A1-E4B2-4431-831B-DE695049DC61}")
$CLSID_LogProviderTextFile = GUID$("{59B2C6A5-663F-4C20-8863-C83F9B72E2EB}")
$CLSID_LogProviderXMLFile = GUID$("{AFED6884-619C-484F-9A09-F42D56E1A7EA}")
$CLSID_PackageNeutral = GUID$("{E80FE1DB-D1AA-4D6B-BA7E-040D424A925C}")
$CLSID_PackageRemote = GUID$("{1838B317-D927-4ED4-8B5C-A0A52D6F6CBE}")
$CLSID_TaskCreator = GUID$("{0DE981B0-ED8A-423C-8CF6-AE5E1FE8295A}")
$CLSID_Application = GUID$("{E44847F1-FD8C-4251-B5DA-B04BB22E236E}")
$CLSID_Package = GUID$("{697AC67E-FDD5-46D1-90D7-F3D0DF1B2A47}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDTSApplication90 = GUID$("{7591CC39-276A-4973-97C7-4EFEA5A5788F}")
$IID_IDTSBreakpointManager90 = GUID$("{584E430E-94F6-42BF-877A-65441CA39D1F}")
$IID_IDTSBreakpointSite90 = GUID$("{8BDFE911-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSBreakpointTarget90 = GUID$("{8BDFE913-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSBreakpointTargets90 = GUID$("{6073F7A8-2734-44B7-926B-95272CF154AD}")
$IID_IDTSCloneVariableDispenser90 = GUID$("{349368C4-4FEA-466C-850F-ABF932B504E4}")
$IID_IDTSComponentEvents90 = GUID$("{155915CC-3357-4A05-8646-FAB301213A85}")
$IID_IDTSComponentPersist90 = GUID$("{8BDFE800-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSConfiguration90 = GUID$("{8BDFE930-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSConfigurations90 = GUID$("{8BDFE854-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSConnectionInfo90 = GUID$("{1DA5C5C2-896E-4DB7-A2CD-2668094A0830}")
$IID_IDTSConnectionInfos90 = GUID$("{8BDFEBD5-E9D8-4D23-9739-DA807BCDACDC}")
$IID_IDTSConnectionManager90 = GUID$("{8BDFE931-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSConnectionManagerDatabaseParameters90 = GUID$("{59F35B9C-E557-474E-A71E-F57CFDCCF9E5}")
$IID_IDTSConnectionManagerExcel90 = GUID$("{4790DB35-116B-4596-8C1B-B2A710B1C8B0}")
$IID_IDTSConnectionManagerFile90 = GUID$("{58E8FEA2-F11F-4504-A830-546ACE7D0578}")
$IID_IDTSConnectionManagerFlatFile90 = GUID$("{58E8FEA2-F11F-4504-A830-546ACE7D0577}")
$IID_IDTSConnectionManagerFlatFileColumn90 = GUID$("{A26F9326-F710-4F37-B01B-43704B80842A}")
$IID_IDTSConnectionManagerFlatFileColumns90 = GUID$("{0546E1DE-9B41-4CF0-8FE3-090F42F3F140}")
$IID_IDTSConnectionManagerFtp90 = GUID$("{E605DF53-DBB8-4C13-A484-77E51440961D}")
$IID_IDTSConnectionManagerInit90 = GUID$("{E99491DE-E9DF-49F8-B6C2-71D22907121E}")
$IID_IDTSConnectionManagerMarshalControl90 = GUID$("{A1E01755-CE4A-4817-BEA3-0964E6ECC43B}")
$IID_IDTSConnections90 = GUID$("{8BDFE864-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSContainer90 = GUID$("{8BDFE892-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSDataTypeInfo90 = GUID$("{D60254C6-24A5-4FBE-B55A-3F79D8F1AFF0}")
$IID_IDTSDataTypeInfos90 = GUID$("{14F1E549-5026-4A07-B7EB-EAE3694AFFFE}")
$IID_IDTSDBProviderInfo90 = GUID$("{8BDFE938-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSDBProviderInfos90 = GUID$("{8BDFE856-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSEnumReferencedObjects90 = GUID$("{DC87DC7B-2415-4E65-9F71-AA545811A0E2}")
$IID_IDTSError90 = GUID$("{8BDFE926-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSErrors90 = GUID$("{8BDFE861-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSEventHandler90 = GUID$("{8BDFE927-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSEventHandlers90 = GUID$("{8BDFE860-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSEventInfo90 = GUID$("{84D64EAF-4E2B-4531-B3E3-25AFA6E19F05}")
$IID_IDTSEventInfos90 = GUID$("{2F4D9809-2F62-4D26-A6E9-E11F71B18225}")
$IID_IDTSEvents90 = GUID$("{8BDFE900-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSEventsProvider90 = GUID$("{8BDFE903-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSExecutable90 = GUID$("{8BDFE890-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSExecutables90 = GUID$("{8BDFE850-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSExecutionLocation90 = GUID$("{1E79E9DE-4495-4200-A8E1-7484FB62A85C}")
$IID_IDTSExecutionMetrics90 = GUID$("{8BDFE802-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSExpression90 = GUID$("{8BDFE8B4-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSExpressionEvaluator90 = GUID$("{01B4DAD0-B645-4671-9D78-8675E0610B22}")
$IID_IDTSExtendedProperties90 = GUID$("{8BDFE863-E9D8-4D23-9739-DA807BCDC2AD}")
$IID_IDTSExtendedProperty90 = GUID$("{8BDFE925-E9D8-4D23-9739-DA807BCDC2AD}")
$IID_IDTSForEachEnumerator90 = GUID$("{8BDFE764-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachEnumeratorInfo90 = GUID$("{8BDFE766-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachEnumeratorInfos90 = GUID$("{8BDFE767-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachItem90 = GUID$("{8BDFE869-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachItemEnumerator90 = GUID$("{8BDFE872-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachItems90 = GUID$("{8BDFE870-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachItemsProvider90 = GUID$("{CAAEDBD2-20BC-4E9C-AEBA-FFE202F0DDFE}")
$IID_IDTSForEachItemValue90 = GUID$("{8BDFE871-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachLoop90 = GUID$("{8BDFE898-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSForEachVariableMapping90 = GUID$("{02AF8FB2-1B29-47FF-A2CC-CEF7F0560DAE}")
$IID_IDTSForEachVariableMappings90 = GUID$("{990A227C-14E8-4DF8-817E-E3C2727FD031}")
$IID_IDTSForLoop90 = GUID$("{8BDFE898-E9D8-4D23-9739-DA807BCDC2DC}")
$IID_IDTSFtpClientConnection90 = GUID$("{13B22329-842F-404D-BDFD-6192A7463EAB}")
$IID_IDTSHasInternalProperties90 = GUID$("{46825CC9-C6DB-475A-8CB1-4CF5ADB2F867}")
$IID_IDTSHttpClientConnection90 = GUID$("{70E8D509-6DF6-4722-9A60-2201CD7129E3}")
$IID_IDTSInfoEvents90 = GUID$("{1C24C8D6-2DA4-48CE-821B-B16637A4C9A2}")
$IID_IDTSLogEntryInfo90 = GUID$("{95BE8310-2CE0-4E9C-8D3E-6EF453AC14F9}")
$IID_IDTSLogEntryInfos90 = GUID$("{8D97B739-0074-4380-BA10-13F4DCCCD031}")
$IID_IDTSLogging90 = GUID$("{8BDFE901-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSLoggingOptions90 = GUID$("{807F1904-EB59-4C12-B529-6CBA55EC3B95}")
$IID_IDTSLogProvider90 = GUID$("{A932F020-A8AD-45F5-A3FB-343D365ECAD2}")
$IID_IDTSLogProviderInfo90 = GUID$("{1DA5C5C2-896E-4DB7-A2CD-2668094A082F}")
$IID_IDTSLogProviderInfos90 = GUID$("{8A292295-8275-4FEE-8D2B-9452819B0964}")
$IID_IDTSLogProviderInit90 = GUID$("{3E174C4D-B8F1-48E6-9758-4907125A4957}")
$IID_IDTSLogProviders90 = GUID$("{0D5A41C8-6D25-4928-A62D-EBF1C71E5CC1}")
$IID_IDTSManagedForEachEnumeratorWrapper90 = GUID$("{17D9F1B3-0461-4424-AA18-021E5EE94FCB}")
$IID_IDTSManagedHelper90 = GUID$("{CCA4E38C-0733-44B1-A612-4BABCF35658E}")
$IID_IDTSManagedPropertyHelper90 = GUID$("{CCA4E38D-0733-44B1-A612-4BABCF35658E}")
$IID_IDTSManagedSerializer90 = GUID$("{0461D531-27EC-4F4C-956F-F62F9C44C80F}")
$IID_IDTSManagedTask90 = GUID$("{728190BE-DB8D-4A64-A0C1-A4DA1688F73B}")
$IID_IDTSManagedWrapper90 = GUID$("{17D9F1B2-0461-4424-AA18-021E5EE94FCB}")
$IID_IDTSName90 = GUID$("{8BDFE8B3-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSObjectHost90 = GUID$("{23BB0025-DB78-4D3F-B8B9-2DD3150E0BC4}")
$IID_IDTSObjectReferenceTracker90 = GUID$("{DBBD6258-4E30-429B-9454-C18598677CD9}")
$IID_IDTSObjectVersionUpdate90 = GUID$("{5C71228D-8D83-4E2C-BC46-A0ED82F62979}")
$IID_IDTSODBCHandles90 = GUID$("{38023A12-56DA-47FA-AA47-2F65BF6E68B6}")
$IID_IDTSPackage90 = GUID$("{8BDFE8B2-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSPackageInfo90 = GUID$("{8BDFE921-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSPackageInfos90 = GUID$("{8BDFE855-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSPackagePath90 = GUID$("{8BDFE920-E9D8-4D23-9739-DA8073CDC2AD}")
$IID_IDTSPackagePersist90 = GUID$("{9C55492D-2A79-410C-AECF-9822EE6DE478}")
$IID_IDTSPackageVersionUpdate90 = GUID$("{0D677D21-9F75-4671-9008-96B21649C556}")
$IID_IDTSPersist90 = GUID$("{D8AACE70-3218-4510-918C-74F0E0119EF0}")
$IID_IDTSPipelineComponentInfo90 = GUID$("{BA36E16C-5853-4D63-87B3-0FC1530851A0}")
$IID_IDTSPipelineComponentInfos90 = GUID$("{2210DE77-8EAC-459F-8475-F803B0D01132}")
$IID_IDTSPrecedenceConstraint90 = GUID$("{8BDFE8B5-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSPrecedenceConstraints90 = GUID$("{8BDFE865-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSProductLevel90 = GUID$("{9757BF8A-1B3E-430E-A2BA-48E86FEAEF21}")
$IID_IDTSProperties90 = GUID$("{8BDFE852-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSPropertiesProvider90 = GUID$("{8BDFE891-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSProperty90 = GUID$("{8BDFE920-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSRunningPackage90 = GUID$("{8260DFAE-0AD3-4B5E-B331-BABACB4FE603}")
$IID_IDTSRunningPackages90 = GUID$("{2207E791-B9D4-4CBB-952D-61BC12FA0472}")
$IID_IDTSRuntimeObject90 = GUID$("{D16B6D17-D788-432A-BDF1-654F871AA6CB}")
$IID_IDTSSelectedLogProviders90 = GUID$("{B5B2B265-7EE7-4C01-91B6-596861DD3476}")
$IID_IDTSSequence90 = GUID$("{8BDFE894-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSServerUsageControl90 = GUID$("{D0FFBFA6-7247-48DD-BEF0-A758F9C7856C}")
$IID_IDTSSuspend90 = GUID$("{8BDFE910-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSTask90 = GUID$("{8BDFE893-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSTaskCreator90 = GUID$("{8F6FC678-DE12-4A44-8558-EBE6508F5073}")
$IID_IDTSTaskHost90 = GUID$("{8BDFE889-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSTaskInfo90 = GUID$("{8BDFE924-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSTaskInfos90 = GUID$("{8BDFE858-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSTaskInit90 = GUID$("{F0E5CEE6-C0CC-4ABD-B02A-C41F1EB88603}")
$IID_IDTSUnsafeVariables90 = GUID$("{49B7A561-A9DF-4F1D-8EE5-60FD89BC7993}")
$IID_IDTSVariable90 = GUID$("{8BDFE925-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSVariableDispenser90 = GUID$("{9BCD80CB-235D-414F-8821-CF3F20F0F65B}")
$IID_IDTSVariableLock90 = GUID$("{B06CFF7F-0482-4F9A-AEDF-93428E08F017}")
$IID_IDTSVariables90 = GUID$("{8BDFE863-E9D8-4D23-9739-DA807BCDC2AC}")
$IID_IDTSWaitForMe90 = GUID$("{2C8B1A1F-0C81-4AF6-AFEA-A903ED486A10}")
$IID_IDTSWarning90 = GUID$("{8BDFE926-E9D8-4D23-9739-DA807BCDC2AD}")
$IID_IDTSWarnings90 = GUID$("{8BDFE862-E9D8-4D23-9739-DA807BCDC2AC}")

' ========================================================================================
' Internal DTS components
' ========================================================================================

$CLSID_DTSManagedWrapper = GUID$("{D542C248-A028-4ABC-9E57-58B5ED151C3F}")
$CLSID_DTSManagedForEachEnumeratorWrapper = GUID$("{D542C249-A028-4ABC-9E57-58B5ED151C3F}")
$CLSID_DTSManagedHelper = GUID$("{F90A4B58-A6F9-416D-B791-CC54468681BB}")
$CLSID_DTSManagedPropertyHelper = GUID$("{A90A4B58-A6F9-416D-B791-CC54468681BB}")
$CLSID_DTSManagedSerializer = GUID$("{94FE2F7E-8616-4E3A-8A60-76728C17033C}")

' ========================================================================================
' DTS component categories
' ========================================================================================

$CATID_DTSConnectionManager = GUID$("{CDABAE8D-6318-4376-94DD-FBE562F55A9C}")
$CATID_DTSLogProvider = GUID$("{3E6132B1-B090-411A-A4D8-0C0747D3B162}")
$CATID_DTSTask = GUID$("{CD0DB111-958E-440D-9111-7D70D1490063}")
$CATID_DTSPipelineComponent = GUID$("{97A2F007-B37A-4B33-87C7-874F46F2D690}")
$CATID_DTSForEachEnumerator = GUID$("{AC24AFEF-E3CC-43B2-A166-6CB114536EDE}")

$CLSID_BreakpointManager = GUID$("{9CC2002F-3702-4965-9180-E63D1F043260}")
$CLSID_Breakpoint = GUID$("{0BD1B903-02AD-4640-8CB7-151063541321}")
$CLSID_Breakpoints = GUID$("{FD659DAA-BF7D-4D42-812A-3A568519BB08}")
$CLSID_GenericContainerEvents = GUID$("{49A5E8F9-AA4D-4691-BF7C-30E8EE4AB9E0}")
$CLSID_TaskHostEvents = GUID$("{7970D783-6D32-4B07-9478-F23D284C8858}")
$CLSID_EventHandlerEvents = GUID$("{5628F933-634C-4F0B-841D-8D01353A291F}")

%DISPID_DTS_BASE           = 0
%DISPID_DTSCOLLECTION_BASE = %DISPID_VALUE
%DISPOFFSET_ITEM           = 0
%DISPOFFSET_COUNT          = 1
%DISPOFFSET_ADD            = 2
%DISPOFFSET_JOIN           = 3
%DISPOFFSET_REMOVE         = 4
%DISPOFFSET_USECACHE       = 5
%DISPOFFSET_REFRESH        = 6
%DISPOFFSET_MOVEBEFORE     = 7
%DISPOFFSET_MOVEAFTER      = 8
%DISPOFFSET_PREPEND        = 9
%DISPOFFSET_APPEND         = 10
%DISPOFFSET_CLEAR          = 11

' ========================================================================================
' DTSFileConnectionUsageType enum
' ========================================================================================

%DTSFCU_FILEEXISTS   = 0
%DTSFCU_CREATEFILE   = %DTSFCU_FILEEXISTS + 1
%DTSFCU_FOLDEREXISTS = %DTSFCU_CREATEFILE + 1
%DTSFCU_CREATEFOLDER = %DTSFCU_FOLDEREXISTS + 1

' ========================================================================================
' DTSSignatureStatus enum
' ========================================================================================

%DTSSS_INVALID    = 0
%DTSSS_NOTPRESENT = %DTSSS_INVALID + 1
%DTSSS_GOOD       = %DTSSS_NOTPRESENT + 1
%DTSSS_UNTRUSTED  = %DTSSS_GOOD + 1

' ========================================================================================
' DTSPipelineComponentType enum
' ========================================================================================

%DTSPCT_TRANSFORM          = 0
%DTSPCT_SOURCEADAPTER      = %DTSPCT_TRANSFORM + 1
%DTSPCT_DESTINATIONADAPTER = %DTSPCT_SOURCEADAPTER + 1
%DTSPCT_VIEW               = %DTSPCT_DESTINATIONADAPTER + 1

' ========================================================================================
' DTSExecResult enum
' ========================================================================================

%DTSER_FAILURE    = 1
%DTSER_SUCCESS    = 0
%DTSER_COMPLETION = 2
%DTSER_CANCELED   = 3

' ========================================================================================
' DTSForcedExecResult enum
' ========================================================================================

%DTSFER_FAILURE    = %DTSER_FAILURE
%DTSFER_SUCCESS    = %DTSER_SUCCESS
%DTSFER_COMPLETION = %DTSER_COMPLETION
%DTSFER_NONE       = -1

' ========================================================================================
' DTSCheckpointUsage enum
' ========================================================================================

%DTSCU_NEVER    = 0
%DTSCU_IFEXISTS = 1
%DTSCU_ALWAYS   = 2

' ========================================================================================
' DTSTransactionOption enum
' ========================================================================================

%DTSTO_NotSupported = 0
%DTSTO_Supported    = %DTSTO_NotSupported + 1
%DTSTO_Required     = %DTSTO_Supported + 1

' ========================================================================================
' DTSExecStatus enum
' ========================================================================================

%DTSES_NONE       = 1
%DTSES_VALIDATING = 2
%DTSES_EXECUTING  = 3
%DTSES_SUSPENDED  = 4
%DTSES_COMPLETED  = 5
%DTSES_ABEND      = 6

' ========================================================================================
' DTSPackageType enum
' ========================================================================================

%DTSPKT_DEFAULT       = 0
%DTSPKT_DTSWIZARD     = 1
%DTSPKT_DTSDESIGNER   = 2
%DTSPKT_SQLREPL       = 3
%DTSPKT_DTSDESIGNER90 = 5
%DTSPKT_SQLDBMAINT    = 6

' ========================================================================================
' DTSLoggingMode enum
' ========================================================================================

%DTSLM_USEPARENTSETTING = 0
%DTSLM_ENABLED          = %DTSLM_USEPARENTSETTING + 1
%DTSLM_DISABLED         = %DTSLM_ENABLED + 1

' ========================================================================================
' DTSEventFilterKind enum
' ========================================================================================

%DTSEFK_INCLUSION = 0
%DTSEFK_EXCLUSION = %DTSEFK_INCLUSION + 1

' ========================================================================================
' DTSProviderType enum
' ========================================================================================

%DTSPT_OLEDB      = -1
%DTSPT_ODBC       = -2
%DTSPT_DTS_SOURCE = -3
%DTSPT_DTS_DEST   = -4
%DTSPT_UNKNOWN    = 0

' ========================================================================================
' DTSProviderSubType enum
' ========================================================================================

%DTSPST_ACCESS    = -1
%DTSPST_EXCEL     = -2
%DTSPST_PARADOX   = -3
%DTSPST_SQLSERVER = -4
%DTSPST_DBASE     = -5
%DTSPST_FLATFILE  = -6
%DTSPST_ORACLE    = -7
%DTSPST_DB2       = -8
%DTSPST_NONE      = 0

' ========================================================================================
' DTSConfigurationType enum
' ========================================================================================

%DTSCT_PARENTVARIABLE  = 0
%DTSCT_CONFIGFILE      = %DTSCT_PARENTVARIABLE + 1
%DTSCT_ENVVARIABLE     = %DTSCT_CONFIGFILE + 1
%DTSCT_REGENTRY        = %DTSCT_ENVVARIABLE + 1
%DTSCT_IPARENTVARIABLE = %DTSCT_REGENTRY + 1
%DTSCT_ICONFIGFILE     = %DTSCT_IPARENTVARIABLE + 1
%DTSCT_IREGENTRY       = %DTSCT_ICONFIGFILE + 1
%DTSCT_SQLSERVER       = %DTSCT_IREGENTRY + 1
%DTSCT_INIFILE         = %DTSCT_SQLSERVER + 1
%DTSCT_ISQLSERVER      = %DTSCT_INIFILE + 1
%DTSCT_IINIFILE        = %DTSCT_ISQLSERVER + 1

' ========================================================================================
' DTSBreakpointHitTest enum
' ========================================================================================

%DTSBHT_ALWAYS           = 0
%DTSBHT_GREATER_OR_EQUAL = %DTSBHT_ALWAYS + 1
%DTSBHT_EQUAL            = %DTSBHT_GREATER_OR_EQUAL + 1
%DTSBHT_MULTIPLE         = %DTSBHT_EQUAL + 1
%DTSBHT_EXPRESSION       = %DTSBHT_MULTIPLE + 1

' ========================================================================================
' DTSExecutionLocation enum
' ========================================================================================

%DTSEL_INPROC_SERVER = 0
%DTSEL_LOCAL_SERVER  = %DTSEL_INPROC_SERVER + 1
%DTSEL_REMOTE_SERVER = %DTSEL_LOCAL_SERVER + 1

' ========================================================================================
' DTSPrecedenceEvalOp enum
' ========================================================================================

%DTSPEO_EXPRESSION              = 1
%DTSPEO_CONSTRAINT              = 2
%DTSPEO_EXPRESSIONANDCONSTRAINT = 3
%DTSPEO_EXPRESSIONORCONSTRAINT  = 4

' ========================================================================================
' DTSPriorityClass enum
' ========================================================================================

%DTSPC_DEFAULT      = 0
%DTSPC_ABOVE_NORMAL = 1
%DTSPC_NORMAL       = 2
%DTSPC_BELOW_NORMAL = 3
%DTSPC_IDLE         = 4

' ========================================================================================
' DTSProtectionLevel enum
' ========================================================================================

%DTSPL_DONTSAVESENSITIVE         = 0
%DTSPL_ENCRYPTSENSITIVE_USERKEY  = %DTSPL_DONTSAVESENSITIVE + 1
%DTSPL_ENCRYPTSENSITIVE_PASSWORD = %DTSPL_ENCRYPTSENSITIVE_USERKEY + 1
%DTSPL_ENCRYPTALL_PASSWORD       = %DTSPL_ENCRYPTSENSITIVE_PASSWORD + 1
%DTSPL_ENCRYPTALL_USERKEY        = %DTSPL_ENCRYPTALL_PASSWORD + 1
%DTSPL_SERVERSTORAGE             = %DTSPL_ENCRYPTALL_USERKEY + 1

' ========================================================================================
' DTSPackageInformationFlags enum
' ========================================================================================

%DTSPIF_FOLDER  = 0
%DTSPIF_PACKAGE = %DTSPIF_FOLDER + 1

' ========================================================================================
' DTSObjectHostType enum
' ========================================================================================

%DTSOHT_TASK              = 0
%DTSOHT_CONNECTIONMANAGER = %DTSOHT_TASK + 1
%DTSOHT_LOGPROVIDER       = %DTSOHT_CONNECTIONMANAGER + 1
%DTSOHT_FOREACHENUMERATOR = %DTSOHT_LOGPROVIDER + 1

' ========================================================================================
' DTSLogEntryFrequency enum
' ========================================================================================

%DTSLEF_OCCASIONAL   = 0
%DTSLEF_CONSISTENT   = %DTSLEF_OCCASIONAL + 1
%DTSLEF_PROPORTIONAL = %DTSLEF_CONSISTENT + 1

' ========================================================================================
' DTSPropertyKind enum
' ========================================================================================

%DTSPK_OTHER              = 0
%DTSPK_VARIABLE_READONLY  = %DTSPK_OTHER + 1
%DTSPK_VARIABLE_READWRITE = %DTSPK_VARIABLE_READONLY + 1
%DTSPK_CONNECTION         = %DTSPK_VARIABLE_READWRITE + 1
%DTSPK_SENSITIVE          = %DTSPK_CONNECTION + 1

' ========================================================================================
' DTSObjectReferenceType enum
' ========================================================================================

%DTSORT_VARIABLE_READONLY  = 0
%DTSORT_VARIABLE_READWRITE = %DTSORT_VARIABLE_READONLY + 1
%DTSORT_CONNECTION         = %DTSORT_VARIABLE_READWRITE + 1

' ========================================================================================
' DTSExcelVersion enum
' ========================================================================================

%DTSExcelVer_3 = 0
%DTSExcelVer_4 = 1
%DTSExcelVer_5 = 2
%DTSExcelVer_8 = 3

' ========================================================================================
' DTSProductLevel enum
' ========================================================================================

%DTSPL_NONE       = 0
%DTSPL_WORKGROUP  = 10
%DTSPL_STANDARD   = 20
%DTSPL_ENTERPRISE = 30

' ========================================================================================
' DataType enum
' ========================================================================================

%DT_EMPTY             = 0
%DT_NULL              = 1
%DT_I2                = 2
%DT_I4                = 3
%DT_R4                = 4
%DT_R8                = 5
%DT_CY                = 6
%DT_DATE              = 7
%DT_BOOL              = 11
%DT_DECIMAL           = 14
%DT_I1                = 16
%DT_UI1               = 17
%DT_UI2               = 18
%DT_UI4               = 19
%DT_I8                = 20
%DT_UI8               = 21
%DT_FILETIME          = 64
%DT_GUID              = 72
%DT_BYTES             = 128
%DT_STR               = 129
%DT_WSTR              = 130
%DT_NUMERIC           = 131
%DT_DBDATE            = 133
%DT_DBTIME            = 134
%DT_DBTIMESTAMP       = 135
%DT_IMAGE             = 301
%DT_TEXT              = 302
%DT_NTEXT             = 303
%DT_BYREF_I2          = 16386
%DT_BYREF_I4          = 16387
%DT_BYREF_R4          = 16388
%DT_BYREF_R8          = 16389
%DT_BYREF_CY          = 16390
%DT_BYREF_DATE        = 16391
%DT_BYREF_BOOL        = 16395
%DT_BYREF_DECIMAL     = 16398
%DT_BYREF_I1          = 16400
%DT_BYREF_UI1         = 16401
%DT_BYREF_UI2         = 16402
%DT_BYREF_UI4         = 16403
%DT_BYREF_I8          = 16404
%DT_BYREF_UI8         = 16405
%DT_BYREF_FILETIME    = 16448
%DT_BYREF_GUID        = 16456
%DT_BYREF_NUMERIC     = 16515
%DT_BYREF_DBDATE      = 16517
%DT_BYREF_DBTIME      = 16518
%DT_BYREF_DBTIMESTAMP = 16519

' ========================================================================================
' DTS_MANAGED_INFO_TYPE enum
' ========================================================================================

%TypeTask              = 0
%TypeComponent         = %TypeTask + 1
%TypeForEachEnumerator = %TypeComponent + 1
%TypeLogProvider       = %TypeForEachEnumerator + 1
%TypeConnection        = %TypeLogProvider + 1

' ========================================================================================
' DTP_FILETIME structure
' ========================================================================================

' // Size = 8 bytes
TYPE DTP_FILETIME DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

' ========================================================================================
' DTP_BYTES structure
' ========================================================================================

' // Size = 8 bytes
TYPE DTP_BYTES DWORD
   lLength AS LONG       ' LONG
   pBytes  AS BYTE PTR   '  /* [size_is][length_is] */ BYTE *
END TYPE

' ========================================================================================
' DTP_DBDATE structure
' ========================================================================================

' // Size = 6 bytes
TYPE DTP_DBDATE WORD
   year  AS INTEGER   ' SHORT
   month AS WORD      ' USHORT
   day   AS WORD      ' USHORT
END TYPE

' ========================================================================================
' DTP_DBTIME structure
' ========================================================================================

' // Size = 6 bytes
TYPE DTP_DBTIME WORD
   hour   AS WORD   ' USHORT
   minute AS WORD   ' USHORT
   second AS WORD   ' USHORT
END TYPE

' ========================================================================================
' DTP_DBTIMESTAMP structure
' ========================================================================================

' // Size = 14 bytes
TYPE DTP_DBTIMESTAMP WORD
   year     AS INTEGER   ' SHORT
   month    AS WORD      ' USHORT
   day      AS WORD      ' USHORT
   hour     AS WORD      ' USHORT
   minute   AS WORD      ' USHORT
   second   AS WORD      ' USHORT
   fraction AS WORD      ' USHORT
END TYPE

' ========================================================================================
' DTP_NUMERIC structure
' ========================================================================================

' // Size = 19 bytes
TYPE DTP_NUMERIC BYTE
   Precision AS BYTE   ' BYTE
   Scale     AS BYTE   ' BYTE
   sign      AS BYTE   ' BYTE
   val(15)   AS BYTE   ' BYTE[16]
END TYPE

' ========================================================================================
' DTS_EVENT_COLUMN_FILTER structure
' ========================================================================================

' // Size = 14 bytes
TYPE DTS_EVENT_COLUMN_FILTER WORD
   Computer    AS INTEGER   ' VARIANT_BOOL
   Operator    AS INTEGER   ' VARIANT_BOOL
   SourceName  AS INTEGER   ' VARIANT_BOOL
   SourceID    AS INTEGER   ' VARIANT_BOOL
   ExecutionID AS INTEGER   ' VARIANT_BOOL
   MessageText AS INTEGER   ' VARIANT_BOOL
   DataBytes   AS INTEGER   ' VARIANT_BOOL
END TYPE

' ========================================================================================
' DTP_DATA_UNION union
' ========================================================================================

' // Size = 19 bytes
UNION DTP_DATA_UNION BYTE
   shortVal        AS INTEGER               ' SHORT shortVal
   pshortVal       AS INTEGER PTR           ' SHORT *pshortVal
   intVal          AS LONG                  ' LONG intVal
   pintVal         AS LONG PTR              ' INT *pintVal
   floatVal        AS SINGLE                ' float floatVal
   pfloatVal       AS SINGLE PTR            ' float *pfloatVal
   doubleVal       AS DOUBLE                ' double doubleVal
   pdoubleVal      AS DOUBLE PTR            ' double *pdoubleVal
   cyVal           AS CUR                   ' CY cyVal
   pcyVal          AS CUR PTR               ' CY *pcyVal
   dateVal         AS DOUBLE                ' DATE dateVal
   pdateVal        AS DOUBLE PTR            ' DATE *pdateVal
   boolVal         AS INTEGER               ' VARIANT_BOOL boolVal
   pboolVal        AS INTEGER PTR           ' VARIANT_BOOL *pboolVal
   decVal          AS DECIMAL               ' DECIMAL
   pdecVal         AS DECIMAL PTR           ' DECIMAL *pdecVal
   byteVal         AS BYTE                  ' BYTE byteVal
   pbyteVal        AS BYTE PTR              ' BYTE *pbyteVal
   charVal         AS BYTE                  ' CHAR charVal
   pcharVal        AS BYTE PTR              ' CHAR *pcharVal
   ushortVal       AS WORD                  ' USHORT ushortVal
   pushortVal      AS WORD PTR              ' USHORT *pushortVal
   dwVal           AS DWORD                 ' DWORD dwVal
   pdwVal          AS DWORD PTR             ' DWORD *pdwVal
   llVal           AS QUAD                  ' LONGLONG llVal
   pllVal          AS QUAD PTR              ' LONGLONG *pllVal
   ullVal          AS QUAD                  ' ULONGLONG ullVal
   pullVal         AS QUAD PTR              ' ULONGLONG *pullVal
   guidVal         AS GUID                  ' GUID guidVal
   bytesVal        AS BYTE PTR              ' BYTE *bytesVal
   numericVal      AS DTP_NUMERIC           ' struct DTP_NUMERIC numericVal
   pnumericVal     AS DTP_NUMERIC PTR       ' struct DTP_NUMERIC *pnumericVal
   dbdateVal       AS DTP_DBDATE            ' struct DTP_DBDATE dbdateVal
   pdbdateVal      AS DTP_DBDATE PTR        ' struct DTP_DBDATE *pdbdateVal
   dbtimeVal       AS DTP_DBTIME            ' struct DTP_DBTIME dbtimeVal
   pdbtimeVal      AS DTP_DBTIME PTR        ' struct DTP_DBTIME *pdbtimeVal
   dbtimestampVal  AS DTP_DBTIMESTAMP       ' struct DTP_DBTIMESTAMP dbtimestampVal
   pdbtimestampVal AS DTP_DBTIMESTAMP PTR   ' struct DTP_DBTIMESTAMP *pdbtimestampVal
   imageVal        AS BYTE PTR              ' BYTE *imageVal
   textVal         AS ASCIIZ PTR            ' LPSTR textVal
   ntextVal        AS WSTRINGZ PTR          ' LPWSTR ntextVal
   strVal          AS ASCIIZ PTR            ' LPSTR strVal
   wstrVal         AS WSTRINGZ PTR          ' LPWSTR wstrVal
   filetimeVal     AS DTP_FILETIME          ' struct DTP_FILETIME filetimeVal
   pfiletimeVal    AS DTP_FILETIME PTR      ' struct DTP_FILETIME *pfiletimeVal
END UNION

' ========================================================================================
' DTP_VARIANT structure
' ========================================================================================

' // Size = 27 bytes
TYPE DTP_VARIANT BYTE
   vt       AS LONG    ' enum DataType vt
   dwLength AS DWORD   ' DWORD dwLength
   DTP_DATA_UNION      ' /* [switch_is] */ DTP_DATA_UNION u
END TYPE

' ========================================================================================
' DTS_MANAGED_INFO structure
' IID = {23D2BA8B-7748-43E9-B760-154BAE9C2FEA}
' ========================================================================================

' // Size = 56 bytes
TYPE DTS_MANAGED_INFO DWORD
   mitType                   AS LONG    ' DTS_MANAGED_INFO_TYPE
   pctType                   AS LONG    ' DTSPipelineComponentType
   bstrName                  AS DWORD   ' BSTR
   bstrDescription           AS DWORD   ' BSTR
   bstrClassID               AS DWORD   ' BSTR
   bstrFileName              AS DWORD   ' BSTR
   bstrFileNameVersionString AS DWORD   ' BSTR
   bstrUITypeName            AS DWORD   ' BSTR
   bstrShapeProgId           AS DWORD   ' BSTR
   bstrIconFile              AS DWORD   ' BSTR
   bstrIconResource          AS DWORD   ' BSTR
   bstrObjectType            AS DWORD   ' BSTR
   bstrContactInfo           AS DWORD   ' BSTR
   lNoEditor                 AS LONG    ' LONG
END TYPE

' ========================================================================================
' DTS_MANAGED_PROPERTY structure
' ========================================================================================

' // Size = 48 bytes
TYPE DTS_MANAGED_PROPERTY BYTE
   bstrName           AS DWORD        ' BSTR
   vValue             AS tagVARIANT   ' VARIANT
   bGet               AS INTEGER      ' VARIANT_BOOL
   bSet               AS INTEGER      ' VARIANT_BOOL
   Index              AS LONG         ' int
   vtTYPE             AS WORD         ' USHORT
   bstrUITypeEditor   AS DWORD        ' BSTR
   bstrTypeConverter  AS DWORD        ' BSTR
   ePropertyKind      AS LONG         ' DTSPropertyKind
   bstrConnectionType AS DWORD        ' BSTR
   bSensitive         AS INTEGER      ' VARIANT_BOOL
END TYPE

' ########################################################################################
' Interface name = IDTSPackageVersionUpdate90
' IID = {0D677D21-9F75-4671-9008-96B21649C556}
' Attributes = 4688 [&H1250] [Hidden] [Dual] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPackageVersionUpdate90_INTERFACE_DEFINED)
    %IDTSPackageVersionUpdate90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackageVersionUpdate90 $IID_IDTSPackageVersionUpdate90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD UpdateVersion <0> ( _                         ' VTable offset = 28
     BYVAL PackageVersion AS LONG _                     ' __in long PackageVersion
   , BYVAL TargetVersion AS LONG _                      ' __in long TargetVersion
   , BYVAL Events AS IDTSInfoEvents90 _                 ' __in IDTSInfoEvents90 *Events
   , BYREF XmlDocument AS WSTRING _                     ' __inout BSTR *XmlDocument
   , BYVAL PackagePassword AS WSTRING _                 ' __in BSTR PackagePassword
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackageVersionUpdate90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSObjectVersionUpdate90
' IID = {5C71228D-8D83-4E2C-BC46-A0ED82F62979}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSObjectVersionUpdate90_INTERFACE_DEFINED)
    %IDTSObjectVersionUpdate90_INTERFACE_DEFINED = 1

INTERFACE IDTSObjectVersionUpdate90 $IID_IDTSObjectVersionUpdate90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CanUpdate <0> ( _                             ' VTable offset = 28
     BYVAL ObjectCreationName AS WSTRING _              ' __in BSTR ObjectCreationName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbCanUpdate
   ' =====================================================================================
   METHOD Update <1> ( _                                ' VTable offset = 32
     BYREF pbstrObjectXML AS WSTRING _                  ' __inout BSTR *pbstrObjectXML
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <2> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSObjectVersionUpdate90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedWrapper90
' IID = {17D9F1B2-0461-4424-AA18-021E5EE94FCB}
' Attributes = 4688 [&H1250] [Hidden] [Dual] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSManagedWrapper90_INTERFACE_DEFINED)
    %IDTSManagedWrapper90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedWrapper90 $IID_IDTSManagedWrapper90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetManagedObject <1> ( _                      ' VTable offset = 28
     BYVAL assemblyName AS WSTRING _                    ' __in BSTR assemblyName
   , BYVAL className AS WSTRING _                       ' __in BSTR className
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrappedTask <2> ( _                     ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkManagedTask
   ' =====================================================================================
   PROPERTY SET WrappedTask <2> ( _                     ' VTable offset = 36
     BYVAL ppunkManagedTask AS IUnknown _               ' __in IUnknown *ppunkManagedTask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrappedConnection <3> ( _               ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkManagedConnection
   ' =====================================================================================
   PROPERTY SET WrappedConnection <3> ( _               ' VTable offset = 44
     BYVAL ppunkManagedConnection AS IUnknown _         ' __in IUnknown *ppunkManagedConnection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrappedLogProvider <4> ( _              ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkManagedLogProvider
   ' =====================================================================================
   PROPERTY SET WrappedLogProvider <4> ( _              ' VTable offset = 52
     BYVAL ppunkManagedLogProvider AS IUnknown _        ' __in IUnknown *ppunkManagedLogProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrappedForEachEnumerator <5> ( _        ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkManagedForEachEnum
   ' =====================================================================================
   PROPERTY SET WrappedForEachEnumerator <5> ( _        ' VTable offset = 60
     BYVAL ppunkManagedForEachEnum AS IUnknown _        ' __in IUnknown *ppunkManagedForEachEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManagedForEachEnumeratorQualifiedName <6> ( _ ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *ClassName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedWrapper90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedForEachEnumeratorWrapper90
' IID = {17D9F1B3-0461-4424-AA18-021E5EE94FCB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSManagedForEachEnumeratorWrapper90_INTERFACE_DEFINED)
    %IDTSManagedForEachEnumeratorWrapper90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedForEachEnumeratorWrapper90 $IID_IDTSManagedForEachEnumeratorWrapper90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetManagedForEachEnumerator <1> ( _           ' VTable offset = 28
     BYVAL className AS WSTRING _                       ' __in BSTR className
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WrappedForEachEnumerator <2> ( _        ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkManagedForEachEnum
   ' =====================================================================================
   PROPERTY SET WrappedForEachEnumerator <2> ( _        ' VTable offset = 36
     BYVAL ppunkManagedForEachEnum AS IUnknown _        ' __in IUnknown *ppunkManagedForEachEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ManagedForEachEnumeratorQualifiedName <3> ( _ ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ClassName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedForEachEnumeratorWrapper90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExpressionEvaluator90
' IID = {01B4DAD0-B645-4671-9D78-8675E0610B22}
' Attributes = 4688 [&H1250] [Hidden] [Dual] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExpressionEvaluator90_INTERFACE_DEFINED)
    %IDTSExpressionEvaluator90_INTERFACE_DEFINED = 1

INTERFACE IDTSExpressionEvaluator90 $IID_IDTSExpressionEvaluator90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Expression <1> ( _                      ' VTable offset = 28
     BYVAL bstrExpression AS WSTRING _                  ' __in BSTR bstrExpression
   )                                                    ' void
   ' =====================================================================================
   METHOD Evaluate <2> ( _                              ' VTable offset = 32
     BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYREF pvResult AS VARIANT _                        ' __out VARIANT *pvResult
   , BYVAL vbSetVariable AS INTEGER _                   ' __in VARIANT_BOOL vbSetVariable
   )                                                    ' void
   ' =====================================================================================
   METHOD IsBooleanExpression <3> ( _                   ' VTable offset = 36
     BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYREF pvbIsBoolean AS INTEGER _                    ' __out VARIANT_BOOL *pvbIsBoolean
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocaleID <4> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plLocaleID
   ' =====================================================================================
   PROPERTY SET LocaleID <4> ( _                        ' VTable offset = 44
     BYVAL lLocaleID AS LONG _                          ' __in long lLocaleID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Events <5> ( _                          ' VTable offset = 48
     BYVAL pInfoEvents AS IDTSInfoEvents90 _            ' __in IDTSInfoEvents90 *pInfoEvents
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExpressionEvaluator90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedTask90
' IID = {728190BE-DB8D-4A64-A0C1-A4DA1688F73B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSManagedTask90_INTERFACE_DEFINED)
    %IDTSManagedTask90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedTask90 $IID_IDTSManagedTask90

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IDTSManagedTask90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedHelper90
' IID = {CCA4E38C-0733-44B1-A612-4BABCF35658E}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSManagedHelper90_INTERFACE_DEFINED)
    %IDTSManagedHelper90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedHelper90 $IID_IDTSManagedHelper90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetManagedConnection ( _                      ' VTable offset = 12
     BYVAL bstrAssemblyQualifiedName AS WSTRING _       ' __in BSTR bstrAssemblyQualifiedName
   , BYVAL bstrConnectionString AS WSTRING _            ' __in BSTR bstrConnectionString
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkRet
   ' =====================================================================================
   METHOD CloseManagedConnection ( _                    ' VTable offset = 16
     BYVAL pManagedConnection AS IUnknown _             ' __in IUnknown *pManagedConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenAssembly ( _                              ' VTable offset = 20
     BYREF pwszAssemblyName AS WSTRINGZ _               ' __in LPWSTR pwszAssemblyName
   , BYVAL mitType AS LONG _                            ' __in DTS_MANAGED_INFO_TYPE mitType
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNextManagedInfo ( _                        ' VTable offset = 24
     BYREF pNextComponentInfo AS DTS_MANAGED_INFO _     ' __out DTS_MANAGED_INFO *pNextComponentInfo
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSucceeded
   ' =====================================================================================
   METHOD MakeCertObject ( _                            ' VTable offset = 28
     BYVAL hCertContext AS QUAD _                       ' __in LONG64 hCertContext
   ) AS IUnknown                                        ' __retval_out IUnknown **ppCertObject
   ' =====================================================================================
   METHOD GetRawCertData ( _                            ' VTable offset = 32
     BYVAL pCertObj AS IUnknown _                       ' __in IUnknown *pCertObj
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaRawData
   ' =====================================================================================
   METHOD SignDocument ( _                              ' VTable offset = 36
     BYREF pbstrDocument AS WSTRING _                   ' __inout BSTR *pbstrDocument
   , BYVAL hCertContext AS QUAD _                       ' __in LONG64 hCertContext
   , BYVAL bstrKeyContainer AS WSTRING _                ' __in BSTR bstrKeyContainer
   , BYVAL iKeyNumber AS LONG _                         ' __in int iKeyNumber
   , BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   , BYVAL iProviderType AS LONG _                      ' __in int iProviderType
   )                                                    ' void
   ' =====================================================================================
   METHOD VerifyDocument ( _                            ' VTable offset = 40
     BYVAL bstrDocument AS WSTRING _                    ' __in BSTR bstrDocument
   , BYREF bstrDocument AS DWORD _                      ' __out SAFEARRAY * *ppsaRawCertData
   , BYREF ppsaSignerPublicKeyBlob AS DWORD _           ' __out SAFEARRAY * *ppsaSignerPublicKeyBlob
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbSigValid
   ' =====================================================================================
   METHOD EncryptDocument ( _                           ' VTable offset = 44
     BYREF pbstrDocument AS WSTRING _                   ' __inout BSTR *pbstrDocument
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD DecryptDocument ( _                           ' VTable offset = 48
     BYREF pbstrDocument AS WSTRING _                   ' __inout BSTR *pbstrDocument
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedHelper90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedPropertyHelper90
' IID = {CCA4E38D-0733-44B1-A612-4BABCF35658E}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSManagedPropertyHelper90_INTERFACE_DEFINED)
    %IDTSManagedPropertyHelper90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedPropertyHelper90 $IID_IDTSManagedPropertyHelper90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ReflectOnObject ( _                           ' VTable offset = 12
     BYVAL oObjectToReflect AS IUnknown _               ' __in IUnknown *oObjectToReflect
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNextManagedProperty ( _                    ' VTable offset = 16
     BYREF nextManagedProperty AS DTS_MANAGED_PROPERTY _ ' __out DTS_MANAGED_PROPERTY *nextManagedProperty
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSucceeded
   ' =====================================================================================
   METHOD GetPropertyValue ( _                          ' VTable offset = 20
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL Index AS LONG _                              ' __in int Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   METHOD SetPropertyValue ( _                          ' VTable offset = 24
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL Index AS LONG _                              ' __in int Index
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedPropertyHelper90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedSerializer90
' IID = {0461D531-27EC-4F4C-956F-F62F9C44C80F}
' Attributes = 4624 [&H1210] [Hidden] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSManagedSerializer90_INTERFACE_DEFINED)
    %IDTSManagedSerializer90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedSerializer90 $IID_IDTSManagedSerializer90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD IsSerializable <1> ( _                        ' VTable offset = 28
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsSerializable
   ' =====================================================================================
   METHOD Serialize <2> ( _                             ' VTable offset = 32
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS WSTRING                                         ' __retval_out BSTR *pXML
   ' =====================================================================================
   METHOD DeSerialize <3> ( _                           ' VTable offset = 36
     BYVAL xml AS WSTRING _                             ' __in BSTR xml
   ) AS IUnknown                                        ' __retval_out IUnknown **ppObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedSerializer90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTaskCreator90
' IID = {8F6FC678-DE12-4A44-8558-EBE6508F5073}
' Attributes = 784 [&H310] [Hidden] [Oleautomation] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSTaskCreator90_INTERFACE_DEFINED)
    %IDTSTaskCreator90_INTERFACE_DEFINED = 1

INTERFACE IDTSTaskCreator90 $IID_IDTSTaskCreator90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateTask ( _                                ' VTable offset = 12
     BYVAL bstrMoniker AS WSTRING _                     ' __in BSTR bstrMoniker
   , BYVAL bstrTaskData AS WSTRING _                    ' __in BSTR bstrTaskData
   , BYVAL pBreakpointManager AS IDTSBreakpointManager90 _ ' __in IDTSBreakpointManager90 *pBreakpointManager
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYREF pdwCancelEvent AS DWORD _                    ' __out DWORD *pdwCancelEvent
   , BYREF ppTask AS IDTSTask90 _                       ' __out IDTSTask90 **ppTask
   )                                                    ' void
   ' =====================================================================================
   METHOD MarshalConnections ( _                        ' VTable offset = 16
     BYVAL pIn AS IDTSConnections90 _                   ' __in IDTSConnections90 *pIn
   , BYREF ppOut AS IDTSConnections90 _                 ' __out IDTSConnections90 **ppOut
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTaskCreator90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRuntimeObject90
' IID = {D16B6D17-D788-432A-BDF1-654F871AA6CB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSRuntimeObject90_INTERFACE_DEFINED)
    %IDTSRuntimeObject90_INTERFACE_DEFINED = 1

INTERFACE IDTSRuntimeObject90 $IID_IDTSRuntimeObject90

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IDTSRuntimeObject90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExecutables90
' IID = {8BDFE850-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExecutables90_INTERFACE_DEFINED)
    %IDTSExecutables90_INTERFACE_DEFINED = 1

INTERFACE IDTSExecutables90 $IID_IDTSExecutables90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSExecutable90                                ' __retval_out IDTSExecutable90 **ppDTSExecutable
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrMoniker AS WSTRING _                     ' __in BSTR bstrMoniker
   ) AS IDTSExecutable90                                ' __retval_out IDTSExecutable90 **ppDTSExecutable
   ' =====================================================================================
   METHOD Join <3> ( _                                  ' VTable offset = 44
     BYVAL IDTSExecutable90 _                           ' __in IDTSExecutable90 *pDTSExecutable
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Contains <1610743814> ( _                     ' VTable offset = 52
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExecutables90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSProperties90
' IID = {8BDFE852-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSProperties90_INTERFACE_DEFINED)
    %IDTSProperties90_INTERFACE_DEFINED = 1

INTERFACE IDTSProperties90 $IID_IDTSProperties90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSProperty90                                  ' __retval_out IDTSProperty90 **ppDTSProperty
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pProperty AS IDTSProperty90 _                ' __in IDTSProperty90 *pProperty
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSProperties90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConfigurations90
' IID = {8BDFE854-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConfigurations90_INTERFACE_DEFINED)
    %IDTSConfigurations90_INTERFACE_DEFINED = 1

INTERFACE IDTSConfigurations90 $IID_IDTSConfigurations90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSConfiguration90                             ' __retval_out IDTSConfiguration90 **ppDTSConfiguration
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
   ) AS IDTSConfiguration90                             ' __retval_out IDTSConfiguration90 **ppConfig
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveBefore <7> ( _                            ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL pConfig AS IDTSConfiguration90 _             ' __in IDTSConfiguration90 *pConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveAfter <8> ( _                             ' VTable offset = 52
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL pConfig AS IDTSConfiguration90 _             ' __in IDTSConfiguration90 *pConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertBefore <9> ( _                          ' VTable offset = 56
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL pConfig AS IDTSConfiguration90 _             ' __in IDTSConfiguration90 *pConfig
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertAfter <10> ( _                          ' VTable offset = 60
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL pConfig AS IDTSConfiguration90 _             ' __in IDTSConfiguration90 *pConfig
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConfigurations90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPackageInfos90
' IID = {8BDFE855-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPackageInfos90_INTERFACE_DEFINED)
    %IDTSPackageInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackageInfos90 $IID_IDTSPackageInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSPackageInfo90                               ' __retval_out IDTSPackageInfo90 **ppDTSPackageInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackageInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSDBProviderInfos90
' IID = {8BDFE856-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSDBProviderInfos90_INTERFACE_DEFINED)
    %IDTSDBProviderInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSDBProviderInfos90 $IID_IDTSDBProviderInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSDBProviderInfo90                            ' __retval_out IDTSDBProviderInfo90 **ppDTSDBProviderInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSDBProviderInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTaskInfos90
' IID = {8BDFE858-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSTaskInfos90_INTERFACE_DEFINED)
    %IDTSTaskInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSTaskInfos90 $IID_IDTSTaskInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSTaskInfo90                                  ' __retval_out IDTSTaskInfo90 **ppDTSTaskInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTaskInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPipelineComponentInfos90
' IID = {2210DE77-8EAC-459F-8475-F803B0D01132}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPipelineComponentInfos90_INTERFACE_DEFINED)
    %IDTSPipelineComponentInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSPipelineComponentInfos90 $IID_IDTSPipelineComponentInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSPipelineComponentInfo90                     ' __retval_out IDTSPipelineComponentInfo90 **ppDTSPipelineComponentInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPipelineComponentInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionInfo90
' IID = {1DA5C5C2-896E-4DB7-A2CD-2668094A0830}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionInfo90_INTERFACE_DEFINED)
    %IDTSConnectionInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionInfo90 $IID_IDTSConnectionInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <1610743808> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET FileNameVersionString <1610743809> ( _  ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVersionString
   ' =====================================================================================
   PROPERTY GET UITypeName <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET IconFile <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET IconResource <1610743812> ( _           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIconResource
   ' =====================================================================================
   PROPERTY GET ConnectionType <1610743813> ( _         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConnectionType
   ' =====================================================================================
   PROPERTY GET ConnectionContact <1610743814> ( _      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConnectionContact
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionInfos90
' IID = {8BDFEBD5-E9D8-4D23-9739-DA807BCDACDC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionInfos90_INTERFACE_DEFINED)
    %IDTSConnectionInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionInfos90 $IID_IDTSConnectionInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSConnectionInfo90                            ' __retval_out IDTSConnectionInfo90 **ppDTSConnectionInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEventHandlers90
' IID = {8BDFE860-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEventHandlers90_INTERFACE_DEFINED)
    %IDTSEventHandlers90_INTERFACE_DEFINED = 1

INTERFACE IDTSEventHandlers90 $IID_IDTSEventHandlers90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSEventHandler90                              ' __retval_out IDTSEventHandler90 **ppDTSEventHandler
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   ) AS IDTSEventHandler90                              ' __retval_out IDTSEventHandler90 **ppDTSeventHandler
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEventHandlers90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSErrors90
' IID = {8BDFE861-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSErrors90_INTERFACE_DEFINED)
    %IDTSErrors90_INTERFACE_DEFINED = 1

INTERFACE IDTSErrors90 $IID_IDTSErrors90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSError90                                     ' __retval_out IDTSError90 **ppDTSError
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Clear <11> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSErrors90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSWarnings90
' IID = {8BDFE862-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSWarnings90_INTERFACE_DEFINED)
    %IDTSWarnings90_INTERFACE_DEFINED = 1

INTERFACE IDTSWarnings90 $IID_IDTSWarnings90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSWarning90                                   ' __retval_out IDTSWarning90 **ppDTSWarning
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Clear <11> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSWarnings90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVariables90
' IID = {8BDFE863-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSVariables90_INTERFACE_DEFINED)
    %IDTSVariables90_INTERFACE_DEFINED = 1

INTERFACE IDTSVariables90 $IID_IDTSVariables90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSVariable90                                  ' __retval_out IDTSVariable90 **ppDTSVariable
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bReadOnly AS INTEGER _                       ' __in VARIANT_BOOL bReadOnly
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSVariable90                                  ' __retval_out IDTSVariable90 **ppDTSVariable
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Unlock <1610743813> ( _                       ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Locked <1610743814> ( _                 ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   METHOD Contains <1610743815> ( _                     ' VTable offset = 56
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVariables90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVariableDispenser90
' IID = {9BCD80CB-235D-414F-8821-CF3F20F0F65B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSVariableDispenser90_INTERFACE_DEFINED)
    %IDTSVariableDispenser90_INTERFACE_DEFINED = 1

INTERFACE IDTSVariableDispenser90 $IID_IDTSVariableDispenser90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LockForRead <1610743808> ( _                  ' VTable offset = 28
     BYVAL Variable AS WSTRING _                                    ' __in BSTR Variable
   )                                                    ' void
   ' =====================================================================================
   METHOD LockForWrite <1610743809> ( _                 ' VTable offset = 32
     BYVAL Variable AS WSTRING _                                    ' __in BSTR Variable
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVariables <1610743810> ( _                 ' VTable offset = 36
     BYREF ppVariables AS IDTSVariables90 _                            ' __out IDTSVariables90 **ppVariables
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743811> ( _                        ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD LockOneForRead <1610743812> ( _               ' VTable offset = 44
     BYVAL Variable AS WSTRING _                        ' __in BSTR Variable
   , BYREF IDTSVariables90 _                            ' __inout IDTSVariables90 **ppVariables
   )                                                    ' void
   ' =====================================================================================
   METHOD LockOneForWrite <1610743813> ( _              ' VTable offset = 48
     BYVAL Variable AS WSTRING _                        ' __in BSTR Variable
   , BYREF ppVariables AS IDTSVariables90 _             ' __inout IDTSVariables90 **ppVariables
   )                                                    ' void
   ' =====================================================================================
   METHOD Contains <1610743814> ( _                     ' VTable offset = 52
     BYVAL Variable AS WSTRING _                        ' __in BSTR Variable
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbContains
   ' =====================================================================================
   METHOD GetQualifiedName <1610743815> ( _             ' VTable offset = 56
     BYVAL Variable AS WSTRING _                        ' __in BSTR Variable
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrQualifiedName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVariableDispenser90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSUnsafeVariables90
' IID = {49B7A561-A9DF-4F1D-8EE5-60FD89BC7993}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSUnsafeVariables90_INTERFACE_DEFINED)
    %IDTSUnsafeVariables90_INTERFACE_DEFINED = 1

INTERFACE IDTSUnsafeVariables90 $IID_IDTSUnsafeVariables90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetUnsafeVariables ( _                        ' VTable offset = 12
   ) AS IDTSVariables90                                 ' __retval_out IDTSVariables90 **ppUnsafeVariables
   ' =====================================================================================
   METHOD SetUnsafeVariables ( _                        ' VTable offset = 16
     BYVAL pUnsafeVariables AS IDTSVariables90 _        ' __in IDTSVariables90 *pUnsafeVariables
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSUnsafeVariables90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSCloneVariableDispenser90
' IID = {349368C4-4FEA-466C-850F-ABF932B504E4}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSCloneVariableDispenser90_INTERFACE_DEFINED)
    %IDTSCloneVariableDispenser90_INTERFACE_DEFINED = 1

INTERFACE IDTSCloneVariableDispenser90 $IID_IDTSCloneVariableDispenser90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CloneVariableDispenser ( _                    ' VTable offset = 12
   ) AS IDTSVariableDispenser90                         ' __retval_out IDTSVariableDispenser90 **ppNewDispenser
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSCloneVariableDispenser90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExtendedProperties90
' IID = {8BDFE863-E9D8-4D23-9739-DA807BCDC2AD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExtendedProperties90_INTERFACE_DEFINED)
    %IDTSExtendedProperties90_INTERFACE_DEFINED = 1

INTERFACE IDTSExtendedProperties90 $IID_IDTSExtendedProperties90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSExtendedProperty90                          ' __retval_out IDTSExtendedProperty90 **ppDTSExtendedProperty
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSExtendedProperty90                          ' __retval_out IDTSExtendedProperty90 **ppDTSExtendedProperty
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExtendedProperties90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnections90
' IID = {8BDFE864-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnections90_INTERFACE_DEFINED)
    %IDTSConnections90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnections90 $IID_IDTSConnections90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS IDTSConnectionManager90                         ' __retval_out IDTSConnectionManager90 **ppDTSConnectionManager
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrConnectionType AS WSTRING _              ' __in BSTR bstrConnectionType
   ) AS IDTSConnectionManager90                         ' __retval_out IDTSConnectionManager90 **ppDTSConnectionManager
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   )                                                    ' void
   ' =====================================================================================
   METHOD Contains <1610743813> ( _                     ' VTable offset = 48
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnections90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPrecedenceConstraints90
' IID = {8BDFE865-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPrecedenceConstraints90_INTERFACE_DEFINED)
    %IDTSPrecedenceConstraints90_INTERFACE_DEFINED = 1

INTERFACE IDTSPrecedenceConstraints90 $IID_IDTSPrecedenceConstraints90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSPrecedenceConstraint90                      ' __retval_out IDTSPrecedenceConstraint90 **ppDTSPC
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pExecFrom AS IDTSExecutable90 _              ' IDTSExecutable90 *pExecFrom
   , BYVAL pExecTo AS IDTSExecutable90 _                ' IDTSExecutable90 *pExecTo
   ) AS IDTSPrecedenceConstraint90                      ' __retval_out IDTSPrecedenceConstraint90 **ppDTSPC
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPrecedenceConstraints90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManager90
' IID = {8BDFE931-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManager90_INTERFACE_DEFINED)
    %IDTSConnectionManager90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManager90 $IID_IDTSConnectionManager90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConnectionString <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConnectionString
   ' =====================================================================================
   PROPERTY SET ConnectionString <1> ( _                ' VTable offset = 32
     BYVAL bstrConnectionString AS WSTRING _            ' __in BSTR bstrConnectionString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProtectionLevel <2> ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DTSProtectionLevel *RetVal
   ' =====================================================================================
   PROPERTY SET ProtectionLevel <2> ( _                 ' VTable offset = 40
     BYVAL NewVal AS LONG _                             ' __in DTSProtectionLevel NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SupportsDTCTransactions <3> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbSupportsDTCTransactions
   ' =====================================================================================
   METHOD AcquireConnection <4> ( _                     ' VTable offset = 48
     BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarConnection
   ' =====================================================================================
   METHOD Validate <5> ( _                              ' VTable offset = 52
     BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD SetQualifier <6> ( _                          ' VTable offset = 56
     BYVAL bstrQualifier AS WSTRING _                   ' __in BSTR bstrQualifier
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseConnection <7> ( _                     ' VTable offset = 60
     BYVAL varConnection AS VARIANT _                   ' __in VARIANT varConnection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManager90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerInit90
' IID = {E99491DE-E9DF-49F8-B6C2-71D22907121E}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerInit90_INTERFACE_DEFINED)
    %IDTSConnectionManagerInit90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerInit90 $IID_IDTSConnectionManagerInit90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InitializeConnectionManager ( _               ' VTable offset = 12
     BYVAL bstrQualifier AS WSTRING _                   ' __in BSTR bstrQualifier
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerInit90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerMarshalControl90
' IID = {A1E01755-CE4A-4817-BEA3-0964E6ECC43B}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerMarshalControl90_INTERFACE_DEFINED)
    %IDTSConnectionManagerMarshalControl90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerMarshalControl90 $IID_IDTSConnectionManagerMarshalControl90

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET CanMarshal ( _                          ' VTable offset = 12
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY GET CanClone ( _                            ' VTable offset = 16
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   METHOD ConfigureClone ( _                            ' VTable offset = 20
     BYVAL pConnectionManager AS IDTSConnectionManager90 _ ' __in IDTSConnectionManager90 *pConnectionManager
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerMarshalControl90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerDatabaseParameters90
' IID = {59F35B9C-E557-474E-A71E-F57CFDCCF9E5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerDatabaseParameters90_INTERFACE_DEFINED)
    %IDTSConnectionManagerDatabaseParameters90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerDatabaseParameters90 $IID_IDTSConnectionManagerDatabaseParameters90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServerName <21> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrServerName
   ' =====================================================================================
   PROPERTY SET ServerName <21> ( _                     ' VTable offset = 32
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserName <22> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   PROPERTY SET UserName <22> ( _                       ' VTable offset = 40
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Password <23> ( _                       ' VTable offset = 44
     BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InitialCatalog <24> ( _                 ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInitialCatalog
   ' =====================================================================================
   PROPERTY SET InitialCatalog <24> ( _                 ' VTable offset = 52
     BYVAL bstrInitialCatalog AS WSTRING _              ' __in BSTR bstrInitialCatalog
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetainSameConnection <25> ( _           ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbRetain
   ' =====================================================================================
   PROPERTY SET RetainSameConnection <25> ( _           ' VTable offset = 60
     BYVAL vbRetain AS INTEGER _                        ' __in VARIANT_BOOL vbRetain
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConnectionForSchema <26> ( _               ' VTable offset = 64
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkConnection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerDatabaseParameters90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerFile90
' IID = {58E8FEA2-F11F-4504-A830-546ACE7D0578}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerFile90_INTERFACE_DEFINED)
    %IDTSConnectionManagerFile90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerFile90 $IID_IDTSConnectionManagerFile90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileUsageType <1> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSFileConnectionUsageType *RetVal
   ' =====================================================================================
   PROPERTY SET FileUsageType <1> ( _                   ' VTable offset = 32
     BYVAL NewVal AS LONG _                             ' __in DTSFileConnectionUsageType NewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerFile90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerFlatFile90
' IID = {58E8FEA2-F11F-4504-A830-546ACE7D0577}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerFlatFile90_INTERFACE_DEFINED)
    %IDTSConnectionManagerFlatFile90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerFlatFile90 $IID_IDTSConnectionManagerFlatFile90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Format <1> ( _                          ' VTable offset = 28
     BYVAL bstrFormat AS WSTRING _                      ' __in BSTR bstrFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormat
   ' =====================================================================================
   PROPERTY SET LocaleID <2> ( _                        ' VTable offset = 36
     BYVAL lLocaleID AS LONG _                          ' __in long lLocaleID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocaleID <2> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plLocaleID
   ' =====================================================================================
   PROPERTY SET Unicode <3> ( _                         ' VTable offset = 44
     BYVAL vbUnicode AS INTEGER _                       ' __in VARIANT_BOOL vbUnicode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Unicode <3> ( _                         ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbUnicode
   ' =====================================================================================
   PROPERTY SET HeaderRowsToSkip <4> ( _                ' VTable offset = 52
     BYVAL lRowsToSkip AS LONG _                        ' __in long lRowsToSkip
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HeaderRowsToSkip <4> ( _                ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plRowsToSkip
   ' =====================================================================================
   PROPERTY SET HeaderRowDelimiter <5> ( _              ' VTable offset = 60
     BYVAL bstrDelimiter AS WSTRING _                   ' __in BSTR bstrDelimiter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HeaderRowDelimiter <5> ( _              ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDelimiter
   ' =====================================================================================
   PROPERTY SET ColumnNamesInFirstDataRow <6> ( _       ' VTable offset = 68
     BYVAL vbColumnNamesInFirstDataRow AS INTEGER _     ' __in VARIANT_BOOL vbColumnNamesInFirstDataRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnNamesInFirstDataRow <6> ( _       ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbColumnNamesInFirstDataRow
   ' =====================================================================================
   PROPERTY SET RowDelimiter <7> ( _                    ' VTable offset = 76
     BYVAL bstrDelimiter AS WSTRING _                   ' __in BSTR bstrDelimiter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowDelimiter <7> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDelimiter
   ' =====================================================================================
   PROPERTY SET DataRowsToSkip <8> ( _                  ' VTable offset = 84
     BYVAL lRowsToSkip AS LONG _                        ' __in long lRowsToSkip
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataRowsToSkip <8> ( _                  ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plRowsToSkip
   ' =====================================================================================
   PROPERTY SET TextQualifier <9> ( _                   ' VTable offset = 92
     BYVAL bstrTextQualifier AS WSTRING _               ' __in BSTR bstrTextQualifier
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextQualifier <9> ( _                   ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTextQualifier
   ' =====================================================================================
   PROPERTY SET CodePage <10> ( _                       ' VTable offset = 100
     BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <10> ( _                       ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plCodePage
   ' =====================================================================================
   PROPERTY GET Columns <11> ( _                        ' VTable offset = 108
   ) AS IDTSConnectionManagerFlatFileColumns90          ' __retval_out IDTSConnectionManagerFlatFileColumns90 **ppColumns
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerFlatFile90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerFlatFileColumn90
' IID = {A26F9326-F710-4F37-B01B-43704B80842A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerFlatFileColumn90_INTERFACE_DEFINED)
    %IDTSConnectionManagerFlatFileColumn90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerFlatFileColumn90 $IID_IDTSConnectionManagerFlatFileColumn90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET ColumnType <2> ( _                      ' VTable offset = 28
     BYVAL bstrColumnType AS WSTRING _                  ' __in BSTR bstrColumnType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnType <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrColumnType
   ' =====================================================================================
   PROPERTY SET ColumnDelimiter <3> ( _                 ' VTable offset = 36
     BYVAL bstrColumnDelimiter AS WSTRING _             ' __in BSTR bstrColumnDelimiter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnDelimiter <3> ( _                 ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrColumnDelimiter
   ' =====================================================================================
   PROPERTY SET ColumnWidth <4> ( _                     ' VTable offset = 44
     BYVAL lWidth AS LONG _                             ' __in long lWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnWidth <4> ( _                     ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plWidth
   ' =====================================================================================
   PROPERTY SET MaximumWidth <5> ( _                    ' VTable offset = 52
     BYVAL lWidth AS LONG _                             ' __in long lWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaximumWidth <5> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plWidth
   ' =====================================================================================
   PROPERTY SET DataType <6> ( _                        ' VTable offset = 60
     BYVAL eDataType AS LONG _                          ' __in enum DataType eDataType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataType <6> ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out enum DataType *peDataType
   ' =====================================================================================
   PROPERTY SET DataPrecision <7> ( _                   ' VTable offset = 68
     BYVAL lDataPrecision AS LONG _                     ' __in long lDataPrecision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataPrecision <7> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plDataPrecision
   ' =====================================================================================
   PROPERTY SET DataScale <8> ( _                       ' VTable offset = 76
     BYVAL lDataScale AS LONG _                         ' __in long lDataScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataScale <8> ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plDataScale
   ' =====================================================================================
   PROPERTY SET TextQualified <9> ( _                   ' VTable offset = 84
     BYVAL vbTextQualified AS INTEGER _                 ' __in VARIANT_BOOL vbTextQualified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextQualified <9> ( _                   ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbTextQualified
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerFlatFileColumn90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerFlatFileColumns90
' IID = {0546E1DE-9B41-4CF0-8FE3-090F42F3F140}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerFlatFileColumns90_INTERFACE_DEFINED)
    %IDTSConnectionManagerFlatFileColumns90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerFlatFileColumns90 $IID_IDTSConnectionManagerFlatFileColumns90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   ) AS IDTSConnectionManagerFlatFileColumn90           ' __retval_out IDTSConnectionManagerFlatFileColumn90 **ppColumn
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
   ) AS IDTSConnectionManagerFlatFileColumn90           ' __retval_out IDTSConnectionManagerFlatFileColumn90 **ppColumn
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveBefore <7> ( _                            ' VTable offset = 48
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   , BYVAL Column AS IDTSConnectionManagerFlatFileColumn90 _ ' __in IDTSConnectionManagerFlatFileColumn90 *Column
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveAfter <8> ( _                             ' VTable offset = 52
     BYVAL Key AS VARIANT _                             ' __in VARIANT Key
   , BYVAL Column AS IDTSConnectionManagerFlatFileColumn90 _ ' __in IDTSConnectionManagerFlatFileColumn90 *Column
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerFlatFileColumns90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSODBCHandles90
' IID = {38023A12-56DA-47FA-AA47-2F65BF6E68B6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSODBCHandles90_INTERFACE_DEFINED)
    %IDTSODBCHandles90_INTERFACE_DEFINED = 1

INTERFACE IDTSODBCHandles90 $IID_IDTSODBCHandles90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET henv <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plhenv
   ' =====================================================================================
   PROPERTY GET hdbc <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plhdbc
   ' =====================================================================================
   PROPERTY GET cstr <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCompletedConnectionString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSODBCHandles90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachEnumerator90
' IID = {8BDFE764-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachEnumerator90_INTERFACE_DEFINED)
    %IDTSForEachEnumerator90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachEnumerator90 $IID_IDTSForEachEnumerator90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeForEachEnumerator <1610743808> ( _  ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL IDTSObjectReferenceTracker90 _               ' __in IDTSObjectReferenceTracker90 *pRefTracker
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnumerator <1610743809> ( _                ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnumUnk
   ' =====================================================================================
   PROPERTY GET CollectionEnumerator <1> ( _            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbIsCollectionEnumerator
   ' =====================================================================================
   PROPERTY SET CollectionEnumerator <1> ( _            ' VTable offset = 40
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL vbIsCollectionEnumerator
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate <1610743812> ( _                     ' VTable offset = 44
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachEnumerator90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachEnumeratorInfo90
' IID = {8BDFE766-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachEnumeratorInfo90_INTERFACE_DEFINED)
    %IDTSForEachEnumeratorInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachEnumeratorInfo90 $IID_IDTSForEachEnumeratorInfo90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateNew <0> ( _                             ' VTable offset = 28
   ) AS IDTSForEachEnumerator90                         ' __retval_out IDTSForEachEnumerator90 **ppEnum
   ' =====================================================================================
   PROPERTY GET FileName <1610743809> ( _               ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET FileNameVersionString <1610743810> ( _  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVersionString
   ' =====================================================================================
   PROPERTY GET UITypeName <1610743811> ( _             ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET ForEachEnumeratorContact <1610743812> ( _ ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFEEContact
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachEnumeratorInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachEnumeratorInfos90
' IID = {8BDFE767-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachEnumeratorInfos90_INTERFACE_DEFINED)
    %IDTSForEachEnumeratorInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachEnumeratorInfos90 $IID_IDTSForEachEnumeratorInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSForEachEnumeratorInfo90                     ' __retval_out IDTSForEachEnumeratorInfo90 **ppForEachEnum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachEnumeratorInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachVariableMappings90
' IID = {990A227C-14E8-4DF8-817E-E3C2727FD031}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachVariableMappings90_INTERFACE_DEFINED)
    %IDTSForEachVariableMappings90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachVariableMappings90 $IID_IDTSForEachVariableMappings90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSForEachVariableMapping90                    ' __retval_out IDTSForEachVariableMapping90 **RetVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *RetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
   ) AS IDTSForEachVariableMapping90                    ' __retval_out IDTSForEachVariableMapping90 **RetVal
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachVariableMappings90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachVariableMapping90
' IID = {02AF8FB2-1B29-47FF-A2CC-CEF7F0560DAE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachVariableMapping90_INTERFACE_DEFINED)
    %IDTSForEachVariableMapping90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachVariableMapping90 $IID_IDTSForEachVariableMapping90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET VariableName <0> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET VariableName <0> ( _                    ' VTable offset = 32
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueIndex <1> ( _                      ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *RetVal
   ' =====================================================================================
   PROPERTY SET ValueIndex <1> ( _                      ' VTable offset = 40
     BYVAL NewVal AS VARIANT _                          ' __in VARIANT NewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachVariableMapping90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachItemValue90
' IID = {8BDFE871-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachItemValue90_INTERFACE_DEFINED)
    %IDTSForEachItemValue90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachItemValue90 $IID_IDTSForEachItemValue90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachItemValue90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachItem90
' IID = {8BDFE869-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachItem90_INTERFACE_DEFINED)
    %IDTSForEachItem90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachItem90 $IID_IDTSForEachItem90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSForEachItemValue90                          ' __retval_out IDTSForEachItemValue90 **ppForEachItemValue
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
   ) AS IDTSForEachItemValue90                          ' __retval_out IDTSForEachItemValue90 **ppForEachItemValue
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachItem90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachItems90
' IID = {8BDFE870-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachItems90_INTERFACE_DEFINED)
    %IDTSForEachItems90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachItems90 $IID_IDTSForEachItems90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSForEachItem90                               ' __retval_out IDTSForEachItem90 **ppForEachItem
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
   ) AS IDTSForEachItem90                               ' __retval_out IDTSForEachItem90 **ppForEachItem
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachItems90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachItemEnumerator90
' IID = {8BDFE872-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachItemEnumerator90_INTERFACE_DEFINED)
    %IDTSForEachItemEnumerator90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachItemEnumerator90 $IID_IDTSForEachItemEnumerator90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Items <0> ( _                           ' VTable offset = 28
   ) AS IDTSForEachItems90                              ' __retval_out IDTSForEachItems90 **ppItems
   ' =====================================================================================
   PROPERTY SET Items <0> ( _                           ' VTable offset = 32
     BYVAL pItems AS IDTSForEachItems90 _               ' __in IDTSForEachItems90 *pItems
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportXML <1> ( _                             ' VTable offset = 36
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   )                                                    ' void
   ' =====================================================================================
   METHOD ExportXML <2> ( _                             ' VTable offset = 40
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachItemEnumerator90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSObjectHost90
' IID = {23BB0025-DB78-4D3F-B8B9-2DD3150E0BC4}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSObjectHost90_INTERFACE_DEFINED)
    %IDTSObjectHost90_INTERFACE_DEFINED = 1

INTERFACE IDTSObjectHost90 $IID_IDTSObjectHost90

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET InnerObject ( _                         ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out IUnknown **RetVal
   ' =====================================================================================
   PROPERTY GET HostType ( _                            ' VTable offset = 16
   ) AS LONG                                            ' __retval_out DTSObjectHostType *RetVal
   ' =====================================================================================
   PROPERTY GET DelayValidation ( _                     ' VTable offset = 20
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET DelayValidation ( _                     ' VTable offset = 24
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSObjectHost90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTaskHost90
' IID = {8BDFE889-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSTaskHost90_INTERFACE_DEFINED)
    %IDTSTaskHost90_INTERFACE_DEFINED = 1

INTERFACE IDTSTaskHost90 $IID_IDTSTaskHost90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ExecValueVariable <0> ( _               ' VTable offset = 28
   ) AS IDTSVariable90                                  ' __retval_out IDTSVariable90 **ppVar
   ' =====================================================================================
   PROPERTY SET ExecValueVariable <0> ( _               ' VTable offset = 32
     BYVAL pVar AS IDTSVariable90 _                     ' __in IDTSVariable90 *pVar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApartmentThreaded <1> ( _               ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsApartmentThreaded
   ' =====================================================================================
   PROPERTY GET ExecutionValue <2> ( _                  ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTaskHost90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExecutable90
' IID = {8BDFE890-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' Note I have added an underscore to Validate and Execute because the Execute method
' conflicts with the method of the same name of the IDTSPackage90.
' ########################################################################################

#IF NOT %DEF(%IDTSExecutable90_INTERFACE_DEFINED)
    %IDTSExecutable90_INTERFACE_DEFINED = 1

INTERFACE IDTSExecutable90 $IID_IDTSExecutable90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Validate_ <4> ( _                             ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD Execute_ <5> ( _                              ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS LONG                                            ' __retval_out DTSExecResult *pExecResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExecutable90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPropertiesProvider90
' IID = {8BDFE891-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPropertiesProvider90_INTERFACE_DEFINED)
    %IDTSPropertiesProvider90_INTERFACE_DEFINED = 1

INTERFACE IDTSPropertiesProvider90 $IID_IDTSPropertiesProvider90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Properties <6> ( _                      ' VTable offset = 28
   ) AS IDTSProperties90                                ' __retval_out IDTSProperties90 **pProperties
   ' =====================================================================================
   METHOD GetExpression <7> ( _                         ' VTable offset = 32
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpression
   ' =====================================================================================
   METHOD SetExpression <8> ( _                         ' VTable offset = 36
     BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYVAL bstrExpression AS WSTRING _                  ' __in BSTR bstrExpression
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPropertiesProvider90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSContainer90
' IID = {8BDFE892-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSContainer90_INTERFACE_DEFINED)
    %IDTSContainer90_INTERFACE_DEFINED = 1

INTERFACE IDTSContainer90 $IID_IDTSContainer90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Variables <9> ( _                       ' VTable offset = 28
   ) AS IDTSVariables90                                 ' __retval_out IDTSVariables90 **ppVariables
   ' =====================================================================================
   PROPERTY GET VariableDispenser <10> ( _              ' VTable offset = 32
   ) AS IDTSVariableDispenser90                         ' __retval_out IDTSVariableDispenser90 **ppVariableDispenser
   ' =====================================================================================
   PROPERTY GET ExecutionStatus <12> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out DTSExecStat *pStatus
   ' =====================================================================================
   PROPERTY GET ExecutionResult <13> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out DTSExecResult *plResult
   ' =====================================================================================
   PROPERTY GET Disable <16> ( _                        ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET Disable <16> ( _                        ' VTable offset = 48
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForceExecutionResult <17> ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out DTSForcedExecResult *RetVal
   ' =====================================================================================
   PROPERTY SET ForceExecutionResult <17> ( _           ' VTable offset = 56
     BYVAL NewVal AS LONG _                             ' __in DTSForcedExecResult NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FailPackageOnFailure <19> ( _           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET FailPackageOnFailure <19> ( _           ' VTable offset = 64
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FailParentOnFailure <20> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET FailParentOnFailure <20> ( _            ' VTable offset = 72
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaximumErrorCount <21> ( _              ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plCountErrors
   ' =====================================================================================
   PROPERTY SET MaximumErrorCount <21> ( _              ' VTable offset = 80
     BYVAL lCountErrors AS LONG _                       ' __in long lCountErrors
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <22> ( _                         ' VTable offset = 84
   ) AS IDTSContainer90                                 ' __retval_out IDTSContainer90 **ppContainer
   ' =====================================================================================
   PROPERTY SET IsolationLevel <23> ( _                 ' VTable offset = 88
     BYVAL lIsolationLevel AS LONG _                    ' __in long lIsolationLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsolationLevel <23> ( _                 ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pIsolationLevel
   ' =====================================================================================
   PROPERTY SET TransactionOption <24> ( _              ' VTable offset = 96
     BYVAL NewVal AS LONG _                             ' __in DTSTransactionOption NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransactionOption <24> ( _              ' VTable offset = 100
   ) AS LONG                                            ' __retval_out DTSTransactionOption *RetVal
   ' =====================================================================================
   PROPERTY GET LoggingOptions <25> ( _                 ' VTable offset = 104
   ) AS IDTSLoggingOptions90                            ' __retval_out IDTSLoggingOptions90 **ppLoggingOptions
   ' =====================================================================================
   PROPERTY GET LoggingMode <26> ( _                    ' VTable offset = 108
   ) AS LONG                                            ' __retval_out DTSLoggingMode *pMode
   ' =====================================================================================
   PROPERTY SET LoggingMode <26> ( _                    ' VTable offset = 112
     BYVAL Mode AS LONG _                               ' __in DTSLoggingMode Mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsDefaultLocaleID <27> ( _              ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsDefaultLocaleID
   ' =====================================================================================
   PROPERTY GET LocaleID <28> ( _                       ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *plLCID
   ' =====================================================================================
   PROPERTY SET LocaleID <28> ( _                       ' VTable offset = 124
     BYVAL lLCID AS LONG _                              ' __in long lLCID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DelayValidation <29> ( _                ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET DelayValidation <29> ( _                ' VTable offset = 132
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogEntryInfos <30> ( _                  ' VTable offset = 136
   ) AS IDTSLogEntryInfos90                             ' __retval_out IDTSLogEntryInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET ForceExecutionValue <31> ( _            ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET ForceExecutionValue <31> ( _            ' VTable offset = 144
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForcedExecutionValue <32> ( _           ' VTable offset = 148
   ) AS VARIANT                                         ' __retval_out VARIANT *RetVal
   ' =====================================================================================
   PROPERTY SET ForcedExecutionValue <32> ( _           ' VTable offset = 152
     BYVAL NewVal AS VARIANT _                          ' __in VARIANT NewVal
   )                                                    ' void
   ' =====================================================================================
   METHOD RegenerateID <33> ( _                         ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSContainer90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExecutionLocation90
' IID = {1E79E9DE-4495-4200-A8E1-7484FB62A85C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExecutionLocation90_INTERFACE_DEFINED)
    %IDTSExecutionLocation90_INTERFACE_DEFINED = 1

INTERFACE IDTSExecutionLocation90 $IID_IDTSExecutionLocation90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ExecutionLocation <31> ( _              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSExecutionLocation *RetVal
   ' =====================================================================================
   PROPERTY SET ExecutionLocation <31> ( _              ' VTable offset = 32
     BYVAL NewVal AS LONG _                             ' __in DTSExecutionLocation NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionAddress <32> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET ExecutionAddress <32> ( _               ' VTable offset = 40
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExecutionLocation90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTask90
' IID = {8BDFE893-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSTask90_INTERFACE_DEFINED)
    %IDTSTask90_INTERFACE_DEFINED = 1

INTERFACE IDTSTask90 $IID_IDTSTask90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Validate_ <4> ( _                             ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pEvents AS IDTSComponentEvents90 _           ' __in IDTSComponentEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD Execute_ <5> ( _                              ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pEvents AS IDTSComponentEvents90 _           ' __in IDTSComponentEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL vTransaction AS VARIANT _                    ' __in VARIANT vTransaction
   ) AS LONG                                            ' __retval_out DTSExecResult *pExecResult
   ' =====================================================================================
   PROPERTY GET ExecutionValue <35> ( _                 ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTask90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSProductLevel90
' IID = {9757BF8A-1B3E-430E-A2BA-48E86FEAEF21}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSProductLevel90_INTERFACE_DEFINED)
    %IDTSProductLevel90_INTERFACE_DEFINED = 1

INTERFACE IDTSProductLevel90 $IID_IDTSProductLevel90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RequiredProductLevel <1610743808> ( _   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSProductLevel *eProductLevel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSProductLevel90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSWaitForMe90
' IID = {2C8B1A1F-0C81-4AF6-AFEA-A903ED486A10}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSWaitForMe90_INTERFACE_DEFINED)
    %IDTSWaitForMe90_INTERFACE_DEFINED = 1

INTERFACE IDTSWaitForMe90 $IID_IDTSWaitForMe90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET WaitForMe <1610743808> ( _              ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSWaitForMe90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTaskInit90
' IID = {F0E5CEE6-C0CC-4ABD-B02A-C41F1EB88603}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSTaskInit90_INTERFACE_DEFINED)
    %IDTSTaskInit90_INTERFACE_DEFINED = 1

INTERFACE IDTSTaskInit90 $IID_IDTSTaskInit90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD InitializeTask <1610743808> ( _               ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL pEventInfos AS IDTSEventInfos90 _            ' __in IDTSEventInfos90 *pEventInfos
   , BYVAL pLogEntryInfos AS IDTSLogEntryInfos90 _      ' __in IDTSLogEntryInfos90 *pLogEntryInfos
   , BYVAL pRefTracker AS IDTSObjectReferenceTracker90 _ ' __in IDTSObjectReferenceTracker90 *pRefTracker
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTaskInit90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogProviderInit90
' IID = {3E174C4D-B8F1-48E6-9758-4907125A4957}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSLogProviderInit90_INTERFACE_DEFINED)
    %IDTSLogProviderInit90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogProviderInit90 $IID_IDTSLogProviderInit90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD InitializeLogProvider ( _                     ' VTable offset = 12
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   , BYVAL pRefTracker AS IDTSObjectReferenceTracker90 _ ' __in IDTSObjectReferenceTracker90 *pRefTracker
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogProviderInit90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSSequence90
' IID = {8BDFE894-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSSequence90_INTERFACE_DEFINED)
    %IDTSSequence90_INTERFACE_DEFINED = 1

INTERFACE IDTSSequence90 $IID_IDTSSequence90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Executables <31> ( _                    ' VTable offset = 28
   ) AS IDTSExecutables90                               ' __retval_out IDTSExecutables90 **ppDTSExecutables
   ' =====================================================================================
   PROPERTY GET PrecedenceConstraints <32> ( _          ' VTable offset = 32
   ) AS IDTSPrecedenceConstraints90                     ' __retval_out IDTSPrecedenceConstraints90 **ppDTSPrecedenceConstraints
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSSequence90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachLoop90
' IID = {8BDFE898-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSExecutable90
' ########################################################################################

#IF NOT %DEF(%IDTSForEachLoop90_INTERFACE_DEFINED)
    %IDTSForEachLoop90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachLoop90 $IID_IDTSForEachLoop90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSExecutable90 Methods
   ' =====================================================================================
   METHOD Validate_ <4> ( _                             ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD Execute_ <5> ( _                              ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS LONG                                            ' __retval_out DTSExecResult *pExecResult
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSForEachLoop90 Methods
   ' =====================================================================================
   PROPERTY GET ForEachEnumerator <32> ( _              ' VTable offset = 36
   ) AS IDTSForEachEnumerator90                         ' __retval_out IDTSForEachEnumerator90 **ppEnum
   ' =====================================================================================
   PROPERTY SET ForEachEnumerator <32> ( _              ' VTable offset = 40
     BYVAL pEnum AS IDTSForEachEnumerator90 _           ' __in IDTSForEachEnumerator90 *pEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VariableMappings <33> ( _               ' VTable offset = 44
   ) AS IDTSForEachVariableMappings90                   ' __retval_out IDTSForEachVariableMappings90 **RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachLoop90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForLoop90
' IID = {8BDFE898-E9D8-4D23-9739-DA807BCDC2DC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSExecutable90
' ########################################################################################

#IF NOT %DEF(%IDTSForLoop90_INTERFACE_DEFINED)
    %IDTSForLoop90_INTERFACE_DEFINED = 1

INTERFACE IDTSForLoop90 $IID_IDTSForLoop90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSExecutable90 Methods
   ' =====================================================================================
   METHOD Validate_ <4> ( _                             ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD Execute_ <5> ( _                              ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS LONG                                            ' __retval_out DTSExecResult *pExecResult
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSForLoop90 Methods
   ' =====================================================================================
   PROPERTY GET InitExpression <31> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpr
   ' =====================================================================================
   PROPERTY SET InitExpression <31> ( _                 ' VTable offset = 40
     BYVAL bstrExpr AS WSTRING _                        ' __in BSTR bstrExpr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EvalExpression <32> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpr
   ' =====================================================================================
   PROPERTY SET EvalExpression <32> ( _                 ' VTable offset = 48
     BYVAL bstrExpr AS WSTRING _                        ' __in BSTR bstrExpr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AssignExpression <33> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpr
   ' =====================================================================================
   PROPERTY SET AssignExpression <33> ( _               ' VTable offset = 56
     BYVAL bstrExpr AS WSTRING _                        ' __in BSTR bstrExpr
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForLoop90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPackage90
' IID = {8BDFE8B2-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSExecutable90
' ########################################################################################

#IF NOT %DEF(%IDTSPackage90_INTERFACE_DEFINED)
    %IDTSPackage90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackage90 $IID_IDTSPackage90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSExecutable90 Methods
   ' =====================================================================================
   METHOD Validate_ <4> ( _                             ' VTable offset = 28
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================
   METHOD Execute_ <5> ( _                              ' VTable offset = 32
     BYVAL pConnections AS IDTSConnections90 _          ' __in IDTSConnections90 *pConnections
   , BYVAL pVariables AS IDTSVariables90 _              ' __in IDTSVariables90 *pVariables
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL pLog AS IDTSLogging90 _                      ' __in IDTSLogging90 *pLog
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   ) AS LONG                                            ' __retval_out DTSExecResult *pExecResult
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSPackage90 Methods
   ' =====================================================================================
   PROPERTY GET Connections <32> ( _                    ' VTable offset = 36
   ) AS IDTSConnections90                               ' __retval_out IDTSConnections90 **DTSConnections
   ' =====================================================================================
   PROPERTY GET Configurations <33> ( _                 ' VTable offset = 40
   ) AS IDTSConfigurations90                            ' __retval_out IDTSConfigurations90 **DTSConfigurations
   ' =====================================================================================
   PROPERTY GET PackageType <35> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out DTSPackageType *PackageType
   ' =====================================================================================
   PROPERTY SET PackageType <35> ( _                    ' VTable offset = 48
     BYVAL PackageType AS LONG _                        '  __in DTSPackageType PackageType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreatorName <36> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET CreatorName <36> ( _                    ' VTable offset = 56
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreatorComputerName <37> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET CreatorComputerName <37> ( _            ' VTable offset = 64
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreationDate <38> ( _                   ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE *RetVal
   ' =====================================================================================
   PROPERTY SET CreationDate <38> ( _                   ' VTable offset = 72
     BYVAL NewVal AS DOUBLE _                           ' __in DATE NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxConcurrentExecutables <39> ( _       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *RetVal
   ' =====================================================================================
   PROPERTY SET MaxConcurrentExecutables <39> ( _       ' VTable offset = 80
     BYVAL NewVal AS LONG _                             ' __in long NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PackagePriorityClass <40> ( _           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out DTSPriorityClass *RetVal
   ' =====================================================================================
   PROPERTY SET PackagePriorityClass <40> ( _           ' VTable offset = 88
     BYVAL NewVal AS LONG _                             ' __in DTSPriorityClass NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionMajor <41> ( _                   ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *RetVal
   ' =====================================================================================
   PROPERTY SET VersionMajor <41> ( _                   ' VTable offset = 96
     BYVAL NewVal AS LONG _                             ' __in long NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionMinor <42> ( _                   ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *RetVal
   ' =====================================================================================
   PROPERTY SET VersionMinor <42> ( _                   ' VTable offset = 104
     BYVAL LONG _                                       ' __in long NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionBuild <43> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *RetVal
   ' =====================================================================================
   PROPERTY SET VersionBuild <43> ( _                   ' VTable offset = 112
     BYVAL NewVal AS LONG _                             ' __in long NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionComments <44> ( _                ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET VersionComments <44> ( _                ' VTable offset = 120
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionGUID <57> ( _                    ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   METHOD Execute <45> ( _                              ' VTable offset = 128
   ) AS LONG                                            ' __retval_out DTSExecResult *plExecResult
   ' =====================================================================================
   METHOD ExportConfigurationFile <46> ( _              ' VTable offset = 132
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportConfigurationFile <47> ( _              ' VTable offset = 136
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableConfigurations <48> ( _           ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbEnable
   ' =====================================================================================
   PROPERTY SET EnableConfigurations <48> ( _           ' VTable offset = 144
     BYVAL vbEnable AS INTEGER _                                    ' __in VARIANT_BOOL vbEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBreakpointTargets <49> ( _                 ' VTable offset = 148
     BYVAL pBreakpointSite AS IDTSBreakpointSite90 _    ' __in IDTSBreakpointSite90 *pBreakpointSite
   , BYVAL onlyEnabled AS INTEGER _                     ' __in VARIANT_BOOL onlyEnabled
   ) AS IDTSBreakpointTargets90                         ' __retval_out IDTSBreakpointTargets90 **ppBreakpointTargets
   ' =====================================================================================
   PROPERTY GET LogProviders <50> ( _                   ' VTable offset = 152
   ) AS IDTSLogProviders90                              ' __retval_out IDTSLogProviders90 **ppLogProviders
   ' =====================================================================================
   PROPERTY GET CertificateObject <51> ( _              ' VTable offset = 156
   ) AS IUnknown                                        ' __retval_out IUnknown **ppCertObj
   ' =====================================================================================
   PROPERTY SET CertificateObject <51> ( _              ' VTable offset = 160
     BYVAL pCertObj AS IUnknown _                       ' __in IUnknown *pCertObj
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CertificateContext <52> ( _             ' VTable offset = 164
   ) AS QUAD                                            ' __retval_out LONG64 *phCertContext
   ' =====================================================================================
   PROPERTY SET CertificateContext <52> ( _             ' VTable offset = 168
     BYVAL hCertContext AS QUAD _                       ' __in LONG64 hCertContext
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckSignature <53> ( _                       ' VTable offset = 172
   ) AS LONG                                            ' __retval_out DTSSignatureStatus *RetVal
   ' =====================================================================================
   METHOD LoadUserCertificateByName <54> ( _            ' VTable offset = 176
     BYVAL SubjectName AS WSTRING _                     ' __in BSTR SubjectName
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadUserCertificateByHash <55> ( _            ' VTable offset = 180
     BYREF ppsaCertHash AS DWORD _                      ' __in SAFEARRAY * *ppsaCertHash
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckSignatureOnLoad <56> ( _           ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbCheckSigOnLoad
   ' =====================================================================================
   PROPERTY SET CheckSignatureOnLoad <56> ( _           ' VTable offset = 188
     BYVAL vbCheckSigOnLoad AS INTEGER _                ' __in VARIANT_BOOL vbCheckSigOnLoad
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtendedProperties <58> ( _             ' VTable offset = 192
   ) AS IDTSExtendedProperties90                        ' __retval_out IDTSExtendedProperties90 **RetVal
   ' =====================================================================================
   PROPERTY GET CheckpointFileName <61> ( _             ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY SET CheckpointFileName <61> ( _             ' VTable offset = 200
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptCheckpoints <62> ( _             ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET EncryptCheckpoints <62> ( _             ' VTable offset = 208
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SaveCheckpoints <63> ( _                ' VTable offset = 212
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET SaveCheckpoints <63> ( _                ' VTable offset = 216
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckpointUsage <64> ( _                ' VTable offset = 220
   ) AS LONG                                            ' __retval_out DTSCheckpointUsage *RetVal
   ' =====================================================================================
   PROPERTY SET CheckpointUsage <64> ( _                ' VTable offset = 224
     BYVAL NewVal AS LONG _                             ' __in DTSCheckpointUsage NewVal
   )                                                    ' void
   ' =====================================================================================
   METHOD ProcessConfiguration <65> ( _                 ' VTable offset = 228
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectFromPackagePath <66> ( _             ' VTable offset = 232
     BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   , BYREF ppProperty AS IDTSProperty90 _               ' __out IDTSProperty90 **ppProperty
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObj
   ' =====================================================================================
   PROPERTY GET Errors <70> ( _                         ' VTable offset = 236
   ) AS IDTSErrors90                                    ' __retval_out IDTSErrors90 **RetVal
   ' =====================================================================================
   PROPERTY GET Warnings <71> ( _                       ' VTable offset = 240
   ) AS IDTSWarnings90                                  ' __retval_out IDTSWarnings90 **RetVal
   ' =====================================================================================
   PROPERTY GET ProtectionLevel <73> ( _                ' VTable offset = 244
   ) AS LONG                                            ' __retval_out DTSProtectionLevel *RetVal
   ' =====================================================================================
   PROPERTY SET ProtectionLevel <73> ( _                ' VTable offset = 248
     BYVAL NewVal AS LONG _                             ' __in DTSProtectionLevel NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PackagePassword <74> ( _                ' VTable offset = 252
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SQLFolder <75> ( _                      ' VTable offset = 256
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFolder
   ' =====================================================================================
   PROPERTY SET SQLFolder <75> ( _                      ' VTable offset = 260
     BYVAL bstrFolder AS WSTRING _                      ' __in BSTR bstrFolder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InteractiveMode <76> ( _                ' VTable offset = 264
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET InteractiveMode <76> ( _                ' VTable offset = 268
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfflineMode <77> ( _                    ' VTable offset = 272
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET OfflineMode <77> ( _                    ' VTable offset = 276
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DesignEvents <78> ( _                   ' VTable offset = 280
   ) AS IDTSEvents90                                    ' __retval_out IDTSEvents90 **RetVal
   ' =====================================================================================
   PROPERTY SET DesignEvents <78> ( _                   ' VTable offset = 284
     BYVAL NewVal AS IDTSEvents90 _                     ' __in IDTSEvents90 *NewVal
   )                                                    ' void
   ' =====================================================================================
   METHOD FindReferencedObjects <79> ( _                ' VTable offset = 288
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS IDTSEnumReferencedObjects90                     ' __retval_out IDTSEnumReferencedObjects90 **RetVal
   ' =====================================================================================
   PROPERTY GET PackageFormatVersion <80> ( _           ' VTable offset = 292
   ) AS LONG                                            ' __retval_out LONG *plPackageFormatVersion
   ' =====================================================================================
   PROPERTY SET UpdatePackage <81> ( _                  ' VTable offset = 296
     BYVAL vbUpdatePackage AS INTEGER _                 ' __in VARIANT_BOOL vbUpdatePackage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdatePackage <81> ( _                  ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbUpdatePackage
   ' =====================================================================================
   PROPERTY SET UpdateObjects <82> ( _                  ' VTable offset = 304
     BYVAL vbUpdateObjects AS INTEGER _                 ' __in VARIANT_BOOL vbUpdateObjects
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateObjects <82> ( _                  ' VTable offset = 308
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbUpdateObjects
   ' =====================================================================================
   PROPERTY SET SuppressConfigurationWarnings <83> ( _  ' VTable offset = 312
     BYVAL vbSuppressConfigWarns AS INTEGER _           ' __in VARIANT_BOOL vbSuppressConfigWarns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressConfigurationWarnings <83> ( _  ' VTable offset = 316
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbSuppressConfigWarns
   ' =====================================================================================
   METHOD PermitUnencryptedSave <1610809415> ( _        ' VTable offset = 320
     BYVAL vbPermit AS INTEGER _                        ' __in VARIANT_BOOL vbPermit
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackage90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSName90
' IID = {8BDFE8B3-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSName90_INTERFACE_DEFINED)
    %IDTSName90_INTERFACE_DEFINED = 1

INTERFACE IDTSName90 $IID_IDTSName90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <81> ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrID
   ' =====================================================================================
   PROPERTY GET Name <82> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <82> ( _                           ' VTable offset = 36
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreationName <83> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY GET Description <84> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <84> ( _                    ' VTable offset = 48
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSName90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExpression90
' IID = {8BDFE8B4-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExpression90_INTERFACE_DEFINED)
    %IDTSExpression90_INTERFACE_DEFINED = 1

INTERFACE IDTSExpression90 $IID_IDTSExpression90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Expression <35> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpression
   ' =====================================================================================
   PROPERTY SET Expression <35> ( _                     ' VTable offset = 32
     BYVAL bstrExpression AS WSTRING _                  ' __in BSTR bstrExpression
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExpression90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPrecedenceConstraint90
' IID = {8BDFE8B5-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPrecedenceConstraint90_INTERFACE_DEFINED)
    %IDTSPrecedenceConstraint90_INTERFACE_DEFINED = 1

INTERFACE IDTSPrecedenceConstraint90 $IID_IDTSPrecedenceConstraint90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <32> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSExecResult *plExecResult
   ' =====================================================================================
   PROPERTY SET Value <32> ( _                          ' VTable offset = 32
     BYVAL ExecResult AS LONG _                         ' __in DTSExecResult ExecResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrecedenceExecutable <33> ( _           ' VTable offset = 36
   ) AS IDTSExecutable90                                ' __retval_out IDTSExecutable90 **ppExec
   ' =====================================================================================
   PROPERTY GET ConstrainedExecutable <34> ( _          ' VTable offset = 40
   ) AS IDTSExecutable90                                ' __retval_out IDTSExecutable90 **ppExec
   ' =====================================================================================
   PROPERTY GET LogicalAnd <35> ( _                     ' VTable offset = 44
   ) AS INTEGER                                         ' VARIANT_BOOL
   ' =====================================================================================
   PROPERTY SET LogicalAnd <35> ( _                     ' VTable offset = 48
     BYVAL isAnd AS INTEGER _                           ' __in VARIANT_BOOL isAnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EvaluatesTrue <36> ( _                  ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVar
   ' =====================================================================================
   PROPERTY SET EvalOp <37> ( _                         ' VTable offset = 56
     BYVAL EvalOp AS LONG _                             ' __in DTSPrecedenceEvalOp EvalOp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EvalOp <37> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DTSPrecedenceEvalOp *pEvalOp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPrecedenceConstraint90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSForEachItemsProvider90
' IID = {CAAEDBD2-20BC-4E9C-AEBA-FFE202F0DDFE}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSForEachItemsProvider90_INTERFACE_DEFINED)
    %IDTSForEachItemsProvider90_INTERFACE_DEFINED = 1

INTERFACE IDTSForEachItemsProvider90 $IID_IDTSForEachItemsProvider90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ForEachItems <0> ( _                    ' VTable offset = 28
   ) AS IDTSForEachItems90                              ' __retval_out IDTSForEachItems90 **pDepInfos
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSForEachItemsProvider90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSInfoEvents90
' IID = {1C24C8D6-2DA4-48CE-821B-B16637A4C9A2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSInfoEvents90_INTERFACE_DEFINED)
    %IDTSInfoEvents90_INTERFACE_DEFINED = 1

INTERFACE IDTSInfoEvents90 $IID_IDTSInfoEvents90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FireWarning <0> ( _                           ' VTable offset = 28
     BYVAL WarningCode AS LONG _                        ' __in long WarningCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   )                                                    ' void
   ' =====================================================================================
   METHOD FireInformation <1> ( _                       ' VTable offset = 32
     BYVAL InformationCode AS LONG _                    ' __in long InformationCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD FireError <2> ( _                             ' VTable offset = 36
     BYVAL ErrorCode AS LONG _                          ' __in long ErrorCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSInfoEvents90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSComponentEvents90
' IID = {155915CC-3357-4A05-8646-FAB301213A85}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSInfoEvents90
' ########################################################################################

#IF NOT %DEF(%IDTSComponentEvents90_INTERFACE_DEFINED)
    %IDTSComponentEvents90_INTERFACE_DEFINED = 1

INTERFACE IDTSComponentEvents90 $IID_IDTSComponentEvents90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSInfoEvents90 Methods
   ' =====================================================================================
   METHOD FireWarning <0> ( _                           ' VTable offset = 28
     BYVAL WarningCode AS LONG _                        ' __in long WarningCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   )                                                    ' void
   ' =====================================================================================
   METHOD FireInformation <1> ( _                       ' VTable offset = 32
     BYVAL InformationCode AS LONG _                    ' __in long InformationCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD FireError <2> ( _                             ' VTable offset = 36
     BYVAL ErrorCode AS LONG _                          ' __in long ErrorCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSComponentEvents90 Methods
   ' =====================================================================================
   METHOD FireQueryCancel <3> ( _                       ' VTable offset = 40
     BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================
   METHOD FireBreakpointHit <4> ( _                     ' VTable offset = 44
     BYVAL pBreakpointTarget AS IDTSBreakpointTarget90 _ ' __in IDTSBreakpointTarget90 *pBreakpointTarget
   )                                                    ' void
   ' =====================================================================================
   METHOD FireProgress <5> ( _                          ' VTable offset = 48
     BYVAL ProgressDescription AS WSTRING _             ' __in BSTR ProgressDescription
   , BYVAL PercentComplete AS LONG _                    ' __in long PercentComplete
   , BYVAL ProgressCountLow AS LONG _                   ' __in long ProgressCountLow
   , BYVAL ProgressCountHigh AS LONG _                  ' __in long ProgressCountHigh
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD FireCustomEvent <6> ( _                       ' VTable offset = 52
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL EventText AS WSTRING _                       ' __in BSTR EventText
   , BYREF ppsaArguments AS DWORD _                     ' __in SAFEARRAY * *ppsaArguments
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSComponentEvents90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEvents90
' IID = {8BDFE900-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEvents90_INTERFACE_DEFINED)
    %IDTSEvents90_INTERFACE_DEFINED = 1

INTERFACE IDTSEvents90 $IID_IDTSEvents90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnPreExecute <0> ( _                          ' VTable offset = 28
     BYVAL pExec AS IDTSExecutable90 _                  ' __in IDTSExecutable90 *pExec
   , BYREF pbFireAgain AS INTEGER _                     ' __in VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnPostExecute <1> ( _                         ' VTable offset = 32
     BYVAL pExec AS IDTSExecutable90 _                  ' __in IDTSExecutable90 *pExec
   , BYREF pbFireAgain AS INTEGER _                     ' __in VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnPreValidate <2> ( _                         ' VTable offset = 36
     BYVAL pExec AS IDTSExecutable90 _                  ' __in IDTSExecutable90 *pExec
   , BYREF pbFireAgain AS INTEGER _                     ' __in VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnPostValidate <3> ( _                        ' VTable offset = 40
     BYVAL pExec AS IDTSExecutable90 _                  ' __in IDTSExecutable90 *pExec
   , BYREF pbFireAgain AS INTEGER _                     ' __in VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnWarning <4> ( _                             ' VTable offset = 44
     BYVAL pSource AS IDTSRuntimeObject90 _             ' __in IDTSRuntimeObject90 *pSource
   , BYVAL WarningCode AS LONG _                        ' __in long WarningCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYVAL IDOfInterfaceWithError AS WSTRING _          ' __in BSTR IDOfInterfaceWithError
   )                                                    ' void
   ' =====================================================================================
   METHOD OnInformation <5> ( _                         ' VTable offset = 48
     BYVAL pSource AS IDTSRuntimeObject90 _             ' __in IDTSRuntimeObject90 *pSource
   , BYVAL InformationCode AS LONG _                    ' __in long InformationCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYVAL IDOfInterfaceWithError AS WSTRING _          ' __in BSTR IDOfInterfaceWithError
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnError <6> ( _                               ' VTable offset = 52
     BYVAL IDTSRuntimeObject90 _                        ' __in IDTSRuntimeObject90 *pSource
   , BYVAL ErrorCode AS LONG _                          ' __in long ErrorCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYVAL IDOfInterfaceWithError AS WSTRING _          ' __in BSTR IDOfInterfaceWithError
   , BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================
   METHOD OnTaskFailed <7> ( _                          ' VTable offset = 56
     BYVAL pTaskHost AS IDTSTaskHost90 _                ' __in IDTSTaskHost90 *pTaskHost
   )                                                    ' void
   ' =====================================================================================
   METHOD OnProgress <8> ( _                            ' VTable offset = 60
     BYVAL pTaskHost AS IDTSTaskHost90 _                ' __in IDTSTaskHost90 *pTaskHost
   , BYVAL ProgressDescription AS WSTRING _             ' __in BSTR ProgressDescription
   , BYVAL PercentComplete AS LONG _                    ' __in long PercentComplete
   , BYVAL ProgressCountLow AS LONG _                   ' __in long ProgressCountLow
   , BYVAL ProgressCountHigh AS LONG _                  ' __in long ProgressCountHigh
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnQueryCancel <9> ( _                         ' VTable offset = 64
     BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================
   METHOD OnBreakpointHit <10> ( _                      ' VTable offset = 68
     BYVAL pBreakpointSite AS IDTSBreakpointSite90 _    ' __in IDTSBreakpointSite90 *pBreakpointSite
   , BYVAL pBreakpointTarget AS IDTSBreakpointTarget90 _ ' __in IDTSBreakpointTarget90 *pBreakpointTarget
   )                                                    ' void
   ' =====================================================================================
   METHOD OnExecutionStatusChanged <11> ( _             ' VTable offset = 72
     BYVAL pExec AS IDTSExecutable90 _                  ' __in IDTSExecutable90 *pExec
   , BYVAL newStatus AS LONG _                          ' __in DTSExecStat newStatus
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnVariableValueChanged <12> ( _               ' VTable offset = 76
     BYVAL pContainer AS IDTSContainer90 _              ' __in IDTSContainer90 *pContainer
   , BYVAL pVariable AS IDTSVariable90 _                ' __in IDTSVariable90 *pVariable
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD OnCustomEvent <13> ( _                        ' VTable offset = 80
     BYVAL pTaskHost AS IDTSTaskHost90 _                ' __in IDTSTaskHost90 *pTaskHost
   , BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL EventText AS WSTRING _                       ' __in BSTR EventText
   , BYREF ppsaArguments AS DWORD _                     ' __in SAFEARRAY * *ppsaArguments
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEvents90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLoggingOptions90
' IID = {807F1904-EB59-4C12-B529-6CBA55EC3B95}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLoggingOptions90_INTERFACE_DEFINED)
    %IDTSLoggingOptions90_INTERFACE_DEFINED = 1

INTERFACE IDTSLoggingOptions90 $IID_IDTSLoggingOptions90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SelectedLogProviders <1610743808> ( _   ' VTable offset = 28
   ) AS IDTSSelectedLogProviders90                      ' __retval_out IDTSSelectedLogProviders90 **ppLogProviders
   ' =====================================================================================
   PROPERTY GET EventFilterKind <1610743809> ( _        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out DTSEventFilterKind *pFilterKind
   ' =====================================================================================
   PROPERTY SET EventFilterKind <1610743809> ( _        ' VTable offset = 36
     BYVAL FilterKind AS LONG _                         ' __in DTSEventFilterKind FilterKind
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventFilter <1610743811> ( _            ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaEventNames
   ' =====================================================================================
   PROPERTY SET EventFilter <1610743811> ( _            ' VTable offset = 44
     BYREF IN ppsaEventNames AS DWORD _                 ' __in SAFEARRAY * *ppsaEventNames
   )                                                    ' void
   ' =====================================================================================
   METHOD SetColumnFilter <1610743813> ( _              ' VTable offset = 48
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL ColumnFilter AS DTS_EVENT_COLUMN_FILTER _    ' __in DTS_EVENT_COLUMN_FILTER ColumnFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColumnFilter <1610743814> ( _              ' VTable offset = 52
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYREF ColumnFilter AS DTS_EVENT_COLUMN_FILTER _    ' __out DTS_EVENT_COLUMN_FILTER *ColumnFilter
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColumnFilteredEvents <1610743815> ( _      ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaEventNames
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLoggingOptions90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogging90
' IID = {8BDFE901-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogging90_INTERFACE_DEFINED)
    %IDTSLogging90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogging90 $IID_IDTSLogging90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Log <1610743808> ( _                          ' VTable offset = 28
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL Computer AS WSTRING _                        ' __in BSTR Computer
   , BYVAL Operator AS WSTRING _                        ' __in BSTR Operator
   , BYVAL SourceName AS WSTRING _                      ' __in BSTR SourceName
   , BYVAL SourceID AS WSTRING _                        ' __in BSTR SourceID
   , BYVAL ExecutionID AS WSTRING _                     ' __in BSTR ExecutionID
   , BYVAL MessageText AS WSTRING _                     ' __in BSTR MessageText
   , BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   , BYVAL EndTime AS DOUBLE _                          ' __in DATE EndTime
   , BYVAL DataCode AS LONG _                           ' __in long DataCode
   , BYREF DataBytes AS DWORD _                         ' __in SAFEARRAY * *DataBytes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <1610743809> ( _                ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   METHOD GetFilterStatus <1610743810> ( _              ' VTable offset = 36
     BYREF EventNames AS DWORD _                        ' __in SAFEARRAY * *EventNames
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaStatus
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogging90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogProvider90
' IID = {A932F020-A8AD-45F5-A3FB-343D365ECAD2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogProvider90_INTERFACE_DEFINED)
    %IDTSLogProvider90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogProvider90 $IID_IDTSLogProvider90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConfigString <1610743808> ( _           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConfigString
   ' =====================================================================================
   PROPERTY SET ConfigString <1610743808> ( _           ' VTable offset = 32
     BYVAL bstrConfigString AS WSTRING _                ' __in BSTR bstrConfigString
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenLog <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseLog <1610743811> ( _                     ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate <1610743812> ( _                     ' VTable offset = 44
     BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   ) AS LONG                                            ' __retval_out DTSExecResult *pValidateResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogProvider90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogProviders90
' IID = {0D5A41C8-6D25-4928-A62D-EBF1C71E5CC1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogProviders90_INTERFACE_DEFINED)
    %IDTSLogProviders90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogProviders90 $IID_IDTSLogProviders90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSLogProvider90                               ' __retval_out IDTSLogProvider90 **ppLogProvider
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL LogProviderClsidOrProgId AS WSTRING _        ' __in BSTR LogProviderClsidOrProgId
   ) AS IDTSLogProvider90                               ' __retval_out IDTSLogProvider90 **ppLogProvider
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogProviders90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSSelectedLogProviders90
' IID = {B5B2B265-7EE7-4C01-91B6-596861DD3476}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSSelectedLogProviders90_INTERFACE_DEFINED)
    %IDTSSelectedLogProviders90_INTERFACE_DEFINED = 1

INTERFACE IDTSSelectedLogProviders90 $IID_IDTSSelectedLogProviders90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSLogProvider90                               ' __retval_out IDTSLogProvider90 **ppLogProvider
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL pLogProvider AS IDTSLogProvider90 _          ' __in IDTSLogProvider90 *pLogProvider
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSSelectedLogProviders90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogProviderInfo90
' IID = {1DA5C5C2-896E-4DB7-A2CD-2668094A082F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogProviderInfo90_INTERFACE_DEFINED)
    %IDTSLogProviderInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogProviderInfo90 $IID_IDTSLogProviderInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <1610743808> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET FileNameVersionString <1610743809> ( _  ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVersionString
   ' =====================================================================================
   PROPERTY GET UITypeName <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET IconFile <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET IconResource <1610743812> ( _           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIconResource
   ' =====================================================================================
   PROPERTY GET LogProviderType <1610743813> ( _        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLogProvType
   ' =====================================================================================
   PROPERTY GET LogProviderContact <1610743814> ( _     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLogProvContact
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogProviderInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogProviderInfos90
' IID = {8A292295-8275-4FEE-8D2B-9452819B0964}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogProviderInfos90_INTERFACE_DEFINED)
    %IDTSLogProviderInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogProviderInfos90 $IID_IDTSLogProviderInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSLogProviderInfo90                           ' __retval_out IDTSLogProviderInfo90 **ppDTSLogProviderInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogProviderInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEventsProvider90
' IID = {8BDFE903-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEventsProvider90_INTERFACE_DEFINED)
    %IDTSEventsProvider90_INTERFACE_DEFINED = 1

INTERFACE IDTSEventsProvider90 $IID_IDTSEventsProvider90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventHandlers <9> ( _                   ' VTable offset = 28
   ) AS IDTSEventHandlers90                             ' __retval_out IDTSEventHandlers90 **ppEventHandlers
   ' =====================================================================================
   PROPERTY GET EventInfos <10> ( _                     ' VTable offset = 32
   ) AS IDTSEventInfos90                                ' __retval_out IDTSEventInfos90 **ppEventInfos
   ' =====================================================================================
   PROPERTY GET DisableEventHandlers <11> ( _           ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *RetVal
   ' =====================================================================================
   PROPERTY SET DisableEventHandlers <11> ( _           ' VTable offset = 40
     BYVAL NewVal AS INTEGER _                          ' __in VARIANT_BOOL NewVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEventsProvider90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEventInfos90
' IID = {2F4D9809-2F62-4D26-A6E9-E11F71B18225}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEventInfos90_INTERFACE_DEFINED)
    %IDTSEventInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSEventInfos90 $IID_IDTSEventInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSEventInfo90                                 ' __retval_out IDTSEventInfo90 **ppDTSEventInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL AllowEventHandlers AS INTEGER _              ' __in VARIANT_BOOL AllowEventHandlers
   , BYREF ParamNames AS DWORD _                        ' __in SAFEARRAY * *ParamNames
   , BYREF ParamTypes AS DWORD _                        ' __in SAFEARRAY * *ParamTypes
   , BYREF ParamDescs AS DWORD _                        ' __in SAFEARRAY * *ParamDescs
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEventInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEventInfo90
' IID = {84D64EAF-4E2B-4531-B3E3-25AFA6E19F05}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEventInfo90_INTERFACE_DEFINED)
    %IDTSEventInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSEventInfo90 $IID_IDTSEventInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AllowEventHandlers <1610743808> ( _     ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbAllowEventHandlers
   ' =====================================================================================
   PROPERTY GET ParameterCount <1610743809> ( _         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   PROPERTY GET ParameterNames <1610743810> ( _         ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaParamNames
   ' =====================================================================================
   PROPERTY GET ParameterTypes <1610743811> ( _         ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaParamTypes
   ' =====================================================================================
   PROPERTY GET ParameterDescriptions <1610743812> ( _  ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaParamDescs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEventInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogEntryInfos90
' IID = {8D97B739-0074-4380-BA10-13F4DCCCD031}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogEntryInfos90_INTERFACE_DEFINED)
    %IDTSLogEntryInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogEntryInfos90 $IID_IDTSLogEntryInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSLogEntryInfo90                              ' __retval_out IDTSLogEntryInfo90 **ppDTSLogEntryInfo
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL LogEntryName AS WSTRING _                    ' __in BSTR LogEntryName
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL FrequencyHint AS LONG _                      ' __in DTSLogEntryFrequency FrequencyHint
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogEntryInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSLogEntryInfo90
' IID = {95BE8310-2CE0-4E9C-8D3E-6EF453AC14F9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSLogEntryInfo90_INTERFACE_DEFINED)
    %IDTSLogEntryInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSLogEntryInfo90 $IID_IDTSLogEntryInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FrequencyHint <1610743808> ( _          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSLogEntryFrequency *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSLogEntryInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSProperty90
' IID = {8BDFE920-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSProperty90_INTERFACE_DEFINED)
    %IDTSProperty90_INTERFACE_DEFINED = 1

INTERFACE IDTSProperty90 $IID_IDTSProperty90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   METHOD GetValue <2> ( _                              ' VTable offset = 32
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================
   METHOD SetValue <3> ( _                              ' VTable offset = 36
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL NewValue AS VARIANT _                        ' __in VARIANT NewValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataType <4> ( _                        ' VTable offset = 40
   ) AS WORD                                            ' __retval_out USHORT *plType
   ' =====================================================================================
   PROPERTY GET Get <5> ( _                             ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbGet
   ' =====================================================================================
   PROPERTY GET Set <6> ( _                             ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbSet
   ' =====================================================================================
   PROPERTY GET TypeConverter <7> ( _                   ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeConverter
   ' =====================================================================================
   PROPERTY GET UITypeEditor <8> ( _                    ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUITypeEditor
   ' =====================================================================================
   PROPERTY GET PropertyKind <9> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DTSPropertyKind *RetVal
   ' =====================================================================================
   PROPERTY GET ConnectionType <10> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   METHOD GetExport <12> ( _                            ' VTable offset = 68
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbExport
   ' =====================================================================================
   METHOD SetExport <13> ( _                            ' VTable offset = 72
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL vbExport AS INTEGER _                        ' __in VARIANT_BOOL vbExport
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPackagePath <14> ( _                       ' VTable offset = 76
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPackagePath
   ' =====================================================================================
   METHOD GetExpression <15> ( _                        ' VTable offset = 80
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExpression
   ' =====================================================================================
   METHOD SetExpression <16> ( _                        ' VTable offset = 84
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL bstrExpression AS WSTRING _                  ' __in BSTR bstrExpression
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSProperty90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSHasInternalProperties90
' IID = {46825CC9-C6DB-475A-8CB1-4CF5ADB2F867}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSHasInternalProperties90_INTERFACE_DEFINED)
    %IDTSHasInternalProperties90_INTERFACE_DEFINED = 1

INTERFACE IDTSHasInternalProperties90 $IID_IDTSHasInternalProperties90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetInternalProperties <1610743808> ( _        ' VTable offset = 28
     BYVAL pProperties AS IDTSProperties90 _            ' __in IDTSProperties90 *pProperties
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSHasInternalProperties90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPackagePath90
' IID = {8BDFE920-E9D8-4D23-9739-DA8073CDC2AD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPackagePath90_INTERFACE_DEFINED)
    %IDTSPackagePath90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackagePath90 $IID_IDTSPackagePath90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetPackagePath <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackagePath90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPackageInfo90
' IID = {8BDFE921-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPackageInfo90_INTERFACE_DEFINED)
    %IDTSPackageInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackageInfo90 $IID_IDTSPackageInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET PackageGuid <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Folder <3> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <4> ( _                     ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET CreationDate <5> ( _                    ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out DATE *pDate
   ' =====================================================================================
   PROPERTY GET PackageDataSize <6> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plDataSize
   ' =====================================================================================
   PROPERTY GET VersionMajor <7> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plVerMajor
   ' =====================================================================================
   PROPERTY GET VersionMinor <8> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plVerMinor
   ' =====================================================================================
   PROPERTY GET VersionBuild <9> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plVerBuild
   ' =====================================================================================
   PROPERTY GET VersionComments <10> ( _                ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *plVerComments
   ' =====================================================================================
   PROPERTY GET VersionGUID <11> ( _                    ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVerGUID
   ' =====================================================================================
   PROPERTY GET Flags <12> ( _                          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out DTSPackageInformationFlags *peFlags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackageInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSTaskInfo90
' IID = {8BDFE924-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSTaskInfo90_INTERFACE_DEFINED)
    %IDTSTaskInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSTaskInfo90 $IID_IDTSTaskInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <1610743808> ( _               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET FileNameVersionString <1610743809> ( _  ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVersionString
   ' =====================================================================================
   PROPERTY GET UITypeName <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET IconFile <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET IconResource <1610743812> ( _           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIconResource
   ' =====================================================================================
   PROPERTY GET TaskType <1610743813> ( _               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTaskType
   ' =====================================================================================
   PROPERTY GET TaskContact <1610743814> ( _            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTaskContact
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSTaskInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPipelineComponentInfo90
' IID = {BA36E16C-5853-4D63-87B3-0FC1530851A0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPipelineComponentInfo90_INTERFACE_DEFINED)
    %IDTSPipelineComponentInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSPipelineComponentInfo90 $IID_IDTSPipelineComponentInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ComponentType <1610743808> ( _          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSPipelineComponentType *ptype
   ' =====================================================================================
   PROPERTY GET ComponentContact <1610743809> ( _       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContact
   ' =====================================================================================
   PROPERTY GET FileName <1610743810> ( _               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET FileNameVersionString <1610743811> ( _  ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVersionString
   ' =====================================================================================
   PROPERTY GET UITypeName <1610743812> ( _             ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET ShapeProgID <1610743813> ( _            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProgID
   ' =====================================================================================
   PROPERTY GET IconFile <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET IconResource <1610743815> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIconResource
   ' =====================================================================================
   PROPERTY GET NoEditor <1610743816> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbNoEditor
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPipelineComponentInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVariable90
' IID = {8BDFE925-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSVariable90_INTERFACE_DEFINED)
    %IDTSVariable90_INTERFACE_DEFINED = 1

INTERFACE IDTSVariable90 $IID_IDTSVariable90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ReadOnly <1> ( _                        ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbReadOnly
   ' =====================================================================================
   PROPERTY SET ReadOnly <1> ( _                        ' VTable offset = 32
     BYVAL bReadOnly AS INTEGER _                       ' __in VARIANT_BOOL bReadOnly
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Namespace <2> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNamespace
   ' =====================================================================================
   PROPERTY SET Namespace <2> ( _                       ' VTable offset = 40
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 48
     BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataType <4> ( _                        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int *nType
   ' =====================================================================================
   PROPERTY GET QualifiedName <7> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pQualifiedName
   ' =====================================================================================
   PROPERTY GET RaiseChangedEvent <8> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRaiseEvent
   ' =====================================================================================
   PROPERTY SET RaiseChangedEvent <8> ( _               ' VTable offset = 64
     BYVAL bRaiseEvent AS INTEGER _                     ' __in VARIANT_BOOL bRaiseEvent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EvaluateAsExpression <9> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEvalAsExp
   ' =====================================================================================
   PROPERTY SET EvaluateAsExpression <9> ( _            ' VTable offset = 72
     BYVAL bEvalAsExp AS INTEGER _                      ' __in VARIANT_BOOL bEvalAsExp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SystemVariable <10> ( _                 ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSystemVariable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVariable90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVariableLock90
' IID = {B06CFF7F-0482-4F9A-AEDF-93428E08F017}
' Attributes = 784 [&H310] [Hidden] [Oleautomation] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSVariableLock90_INTERFACE_DEFINED)
    %IDTSVariableLock90_INTERFACE_DEFINED = 1

INTERFACE IDTSVariableLock90 $IID_IDTSVariableLock90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AcquireLock ( _                               ' VTable offset = 12
     BYVAL vbExclusive AS INTEGER _                     ' __in VARIANT_BOOL vbExclusive
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseLock ( _                               ' VTable offset = 16
     BYVAL vbExclusive AS INTEGER _                     ' __in VARIANT_BOOL vbExclusive
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVariableLock90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExtendedProperty90
' IID = {8BDFE925-E9D8-4D23-9739-DA807BCDC2AD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExtendedProperty90_INTERFACE_DEFINED)
    %IDTSExtendedProperty90_INTERFACE_DEFINED = 1

INTERFACE IDTSExtendedProperty90 $IID_IDTSExtendedProperty90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Namespace <2> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNamespace
   ' =====================================================================================
   PROPERTY SET Namespace <2> ( _                       ' VTable offset = 40
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET QualifiedName <3> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pQualifiedName
   ' =====================================================================================
   PROPERTY GET DataType <4> ( _                        ' VTable offset = 48
   ) AS LONG                                            ' __retval_out int *nType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExtendedProperty90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSError90
' IID = {8BDFE926-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSError90_INTERFACE_DEFINED)
    %IDTSError90_INTERFACE_DEFINED = 1

INTERFACE IDTSError90 $IID_IDTSError90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ErrorCode <0> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plErrCode
   ' =====================================================================================
   PROPERTY SET ErrorCode <0> ( _                       ' VTable offset = 32
     BYVAL lErrCode AS LONG _                           ' __in long lErrCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSource
   ' =====================================================================================
   PROPERTY SET Source <1> ( _                          ' VTable offset = 40
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeStamp <2> ( _                       ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTimeStamp
   ' =====================================================================================
   PROPERTY GET Description <3> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================
   PROPERTY SET Description <3> ( _                     ' VTable offset = 52
     BYVAL bstrDesc AS WSTRING _                        ' __in BSTR bstrDesc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFile <4> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrHelpFile
   ' =====================================================================================
   PROPERTY SET HelpFile <4> ( _                        ' VTable offset = 60
     BYVAL bstrHelpFile AS WSTRING _                    ' __in BSTR bstrHelpFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContext <5> ( _                     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plHelpContext
   ' =====================================================================================
   PROPERTY SET HelpContext <5> ( _                     ' VTable offset = 68
     BYVAL lHelpContext AS LONG _                       ' __in long lHelpContext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IDOfInterfaceWithError <6> ( _          ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIID
   ' =====================================================================================
   PROPERTY SET IDOfInterfaceWithError <6> ( _          ' VTable offset = 76
     BYVAL bstrIID AS WSTRING _                         ' __in BSTR bstrIID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceID <7> ( _                        ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSourceID
   ' =====================================================================================
   PROPERTY SET SourceID <7> ( _                        ' VTable offset = 84
     BYVAL bstrSourceID AS WSTRING _                    ' __in BSTR bstrSourceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubComponent <8> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubComponent
   ' =====================================================================================
   PROPERTY SET SubComponent <8> ( _                    ' VTable offset = 92
     BYVAL bstrSubComponent AS WSTRING _                ' __in BSTR bstrSubComponent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSError90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSWarning90
' IID = {8BDFE926-E9D8-4D23-9739-DA807BCDC2AD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSWarning90_INTERFACE_DEFINED)
    %IDTSWarning90_INTERFACE_DEFINED = 1

INTERFACE IDTSWarning90 $IID_IDTSWarning90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET WarningCode <0> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plErrCode
   ' =====================================================================================
   PROPERTY SET WarningCode <0> ( _                     ' VTable offset = 32
     BYVAL lErrCode AS LONG _                           ' __in long lErrCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSource
   ' =====================================================================================
   PROPERTY SET Source <1> ( _                          ' VTable offset = 40
     BYVAL bstrSource AS WSTRING _                      ' __in BSTR bstrSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TimeStamp <2> ( _                       ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pvTimeStamp
   ' =====================================================================================
   PROPERTY GET Description <3> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================
   PROPERTY SET Description <3> ( _                     ' VTable offset = 52
     BYVAL bstrDesc AS WSTRING _                        ' __in BSTR bstrDesc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpFile <4> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrHelpFile
   ' =====================================================================================
   PROPERTY SET HelpFile <4> ( _                        ' VTable offset = 60
     BYVAL bstrHelpFile AS WSTRING _                    ' __in BSTR bstrHelpFile
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HelpContext <5> ( _                     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plHelpContext
   ' =====================================================================================
   PROPERTY SET HelpContext <5> ( _                     ' VTable offset = 68
     BYVAL lHelpContext AS LONG _                       ' __in long lHelpContext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IDOfInterfaceWithWarning <6> ( _        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIID
   ' =====================================================================================
   PROPERTY SET IDOfInterfaceWithWarning <6> ( _        ' VTable offset = 76
     BYVAL bstrIID AS WSTRING _                         ' __in BSTR bstrIID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceID <7> ( _                        ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSourceID
   ' =====================================================================================
   PROPERTY SET SourceID <7> ( _                        ' VTable offset = 84
     BYVAL bstrSourceID AS WSTRING _                    ' __in BSTR bstrSourceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubComponent <8> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubComponent
   ' =====================================================================================
   PROPERTY SET SubComponent <8> ( _                    ' VTable offset = 92
     BYVAL bstrSubComponent AS WSTRING _                ' __in BSTR bstrSubComponent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSWarning90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConfiguration90
' IID = {8BDFE930-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConfiguration90_INTERFACE_DEFINED)
    %IDTSConfiguration90_INTERFACE_DEFINED = 1

INTERFACE IDTSConfiguration90 $IID_IDTSConfiguration90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConfigurationType <0> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out DTSConfigurationType *pctType
   ' =====================================================================================
   PROPERTY SET ConfigurationType <0> ( _               ' VTable offset = 32
     BYVAL ctType AS LONG _                             ' __in DTSConfigurationType ctType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfigurationString <1> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConfig
   ' =====================================================================================
   PROPERTY SET ConfigurationString <1> ( _             ' VTable offset = 40
     BYVAL bstrConfig AS WSTRING _                      ' __in BSTR bstrConfig
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PackagePath <2> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPackagePath
   ' =====================================================================================
   PROPERTY SET PackagePath <2> ( _                     ' VTable offset = 48
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConfiguration90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSDBProviderInfo90
' IID = {8BDFE938-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSDBProviderInfo90_INTERFACE_DEFINED)
    %IDTSDBProviderInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSDBProviderInfo90 $IID_IDTSDBProviderInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *bstrName
   ' =====================================================================================
   PROPERTY GET ParseName <2> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *bstrParseName
   ' =====================================================================================
   PROPERTY GET Description <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *bstrDescription
   ' =====================================================================================
   PROPERTY GET ProviderType <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out DTSProviderType *pType
   ' =====================================================================================
   PROPERTY GET ProviderSubType <5> ( _                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out DTSProviderSubType *pType
   ' =====================================================================================
   PROPERTY GET UseFullTableName <6> ( _                ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseFullTableName
   ' =====================================================================================
   PROPERTY GET SupportsNullColumns <7> ( _             ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pSupportsNullColumns
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSDBProviderInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSDataTypeInfo90
' IID = {D60254C6-24A5-4FBE-B55A-3F79D8F1AFF0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSDataTypeInfo90_INTERFACE_DEFINED)
    %IDTSDataTypeInfo90_INTERFACE_DEFINED = 1

INTERFACE IDTSDataTypeInfo90 $IID_IDTSDataTypeInfo90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TypeName <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeName
   ' =====================================================================================
   PROPERTY GET TypeEnumName <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeEnumName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSDataTypeInfo90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSDataTypeInfos90
' IID = {14F1E549-5026-4A07-B7EB-EAE3694AFFFE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSDataTypeInfos90_INTERFACE_DEFINED)
    %IDTSDataTypeInfos90_INTERFACE_DEFINED = 1

INTERFACE IDTSDataTypeInfos90 $IID_IDTSDataTypeInfos90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <1> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSDataTypeInfo90                              ' __retval_out IDTSDataTypeInfo90 **pIDTSDataTypeInfo
   ' =====================================================================================
   PROPERTY GET Count <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSDataTypeInfos90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSApplication90
' IID = {7591CC39-276A-4973-97C7-4EFEA5A5788F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSApplication90_INTERFACE_DEFINED)
    %IDTSApplication90_INTERFACE_DEFINED = 1

INTERFACE IDTSApplication90 $IID_IDTSApplication90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ForEachEnumeratorInfos <1> ( _          ' VTable offset = 28
   ) AS IDTSForEachEnumeratorInfos90                    ' __retval_out IDTSForEachEnumeratorInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET TaskInfos <2> ( _                       ' VTable offset = 32
   ) AS IDTSTaskInfos90                                 ' __retval_out IDTSTaskInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET LogProviderInfos <3> ( _                ' VTable offset = 36
   ) AS IDTSLogProviderInfos90                          ' __retval_out IDTSLogProviderInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET ConnectionInfos <4> ( _                 ' VTable offset = 40
   ) AS IDTSConnectionInfos90                           ' __retval_out IDTSConnectionInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET DBProviderInfos <5> ( _                 ' VTable offset = 44
   ) AS IDTSDBProviderInfos90                           ' __retval_out IDTSDBProviderInfos90 **RetVal
   ' =====================================================================================
   METHOD GetPackageInfos <6> ( _                       ' VTable offset = 48
     BYVAL bstrPackageFolder AS WSTRING _               ' __in BSTR bstrPackageFolder
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   ) AS IDTSPackageInfos90                              ' __retval_out IDTSPackageInfos90 **ppRetVal
   ' =====================================================================================
   PROPERTY GET PipelineComponentInfos <7> ( _          ' VTable offset = 52
   ) AS IDTSPipelineComponentInfos90                    ' __retval_out IDTSPipelineComponentInfos90 **RetVal
   ' =====================================================================================
   PROPERTY GET ComponentStorePath <8> ( _              ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   METHOD LoadPackage <9> ( _                           ' VTable offset = 60
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , BYVAL loadNeutral AS INTEGER _                     ' __in VARIANT_BOOL loadNeutral
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   ) AS IDTSPackage90                                   ' __retval_out IDTSPackage90 **ppPackage
   ' =====================================================================================
   METHOD SaveToXML <10> ( _                            ' VTable offset = 64
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , BYVAL pPersistObj AS IDTSPersist90 _               ' __in IDTSPersist90 *pPersistObj
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromSQLServer <11> ( _                  ' VTable offset = 68
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToSQLServer <12> ( _                      ' VTable offset = 72
     BYVAL Package AS IDTSPackage90 _                   ' __in IDTSPackage90 *Package
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL ServerName AS WSTRING _                      ' __in BSTR ServerName
   , BYVAL ServerUserName AS WSTRING _                  ' __in BSTR ServerUserName
   , BYVAL ServerPassword AS WSTRING _                  ' __in BSTR ServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToSQLServerAs <13> ( _                    ' VTable offset = 76
     BYVAL pPackage AS IDTSPackage90 _                  ' __in IDTSPackage90 *pPackage
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadFromSQLServer <14> ( _                    ' VTable offset = 80
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   , BYVAL bLoadNeutral AS INTEGER _                    ' __in VARIANT_BOOL bLoadNeutral
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   ) AS IDTSPackage90                                   ' __retval_out IDTSPackage90 **ppPackage
   ' =====================================================================================
   METHOD ExistsOnSQLServer <15> ( _                    ' VTable offset = 84
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExists
   ' =====================================================================================
   PROPERTY GET CheckSignatureOnLoad <18> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbCheckSigOnLoad
   ' =====================================================================================
   PROPERTY SET CheckSignatureOnLoad <18> ( _           ' VTable offset = 92
     BYVAL vbCheckSigOnLoad AS INTEGER _                ' __in VARIANT_BOOL vbCheckSigOnLoad
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFolderOnSQLServer <19> ( _              ' VTable offset = 96
     BYVAL bstrParent AS WSTRING _                      ' __in BSTR bstrParent
   , BYVAL bstrNewFolderName AS WSTRING _               ' __in BSTR bstrNewFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD RenameFolderOnSQLServer <20> ( _              ' VTable offset = 100
     BYVAL bstrParent AS WSTRING _                      ' __in BSTR bstrParent
   , BYVAL bstrOldName AS WSTRING _                     ' __in BSTR bstrOldName
   , BYVAL bstrNewName AS WSTRING _                     ' __in BSTR bstrNewName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFolderFromSQLServer <21> ( _            ' VTable offset = 104
     BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderExistsOnSQLServer <22> ( _              ' VTable offset = 108
     BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExists
   ' =====================================================================================
   METHOD SavePackage <23> ( _                          ' VTable offset = 112
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   , BYVAL pPackage AS IDTSPackage90 _                  ' __in IDTSPackage90 *pPackage
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderFromPath <24> ( _                       ' VTable offset = 116
     BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrServerUserName AS WSTRING _              ' __in BSTR bstrServerUserName
   , BYVAL bstrServerPassword AS WSTRING _              ' __in BSTR bstrServerPassword
   ) AS GUID                                            ' __retval_out GUID *pguidFolder
   ' =====================================================================================
   PROPERTY GET DataTypeInfos <25> ( _                  ' VTable offset = 120
   ) AS IDTSDataTypeInfos90                             ' __retval_out IDTSDataTypeInfos90 **pIDTSDataTypeInfos
   ' =====================================================================================
   METHOD DataTypeInfoFromDataType <26> ( _             ' VTable offset = 124
     BYVAL dt AS LONG _                                 ' __in enum DataType dt
   ) AS IDTSDataTypeInfo90                              ' __retval_out IDTSDataTypeInfo90 **pIDTSDataTypeInfo
   ' =====================================================================================
   METHOD GetRunningPackages <37> ( _                   ' VTable offset = 128
     BYVAL bstrMachineName AS WSTRING _                 ' __in BSTR bstrMachineName
   ) AS IDTSRunningPackages90                           ' __retval_out IDTSRunningPackages90 **pRunningPackages
   ' =====================================================================================
   PROPERTY GET UpdateObjects <38> ( _                  ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbUpdateTasks
   ' =====================================================================================
   PROPERTY SET UpdateObjects <38> ( _                  ' VTable offset = 136
     BYVAL pvbUpdateTasks AS INTEGER _                  ' __in VARIANT_BOOL pvbUpdateTasks
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdatePackage <39> ( _                  ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbUpdatePackage
   ' =====================================================================================
   PROPERTY SET UpdatePackage <39> ( _                  ' VTable offset = 144
     BYVAL pvbUpdatePackage AS INTEGER _                ' __in VARIANT_BOOL pvbUpdatePackage
   )                                                    ' void
   ' =====================================================================================
   METHOD GetServerInfo <40> ( _                        ' VTable offset = 148
     BYVAL bstrMachineName AS WSTRING _                 ' __in BSTR bstrMachineName
   , BYREF serverVersion AS WSTRING _                   ' __out BSTR *serverVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PackagePassword <41> ( _                ' VTable offset = 152
     BYVAL NewVal AS WSTRING _                          ' __in BSTR NewVal
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFolderOnDtsServer <42> ( _              ' VTable offset = 156
     BYVAL bstrParent AS WSTRING _                      ' __in BSTR bstrParent
   , BYVAL bstrNewFolderName AS WSTRING _               ' __in BSTR bstrNewFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD RenameFolderOnDtsServer <43> ( _              ' VTable offset = 160
     BYVAL bstrParent AS WSTRING _                      ' __in BSTR bstrParent
   , BYVAL bstrOldName AS WSTRING _                     ' __in BSTR bstrOldName
   , BYVAL bstrNewName AS WSTRING _                     ' __in BSTR bstrNewName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFolderFromDtsServer <45> ( _            ' VTable offset = 164
     BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderExistsOnDtsServer <46> ( _              ' VTable offset = 168
     BYVAL bstrFolderName AS WSTRING _                  ' __in BSTR bstrFolderName
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExists
   ' =====================================================================================
   METHOD SaveToDtsServer <47> ( _                      ' VTable offset = 172
     BYVAL pPackage AS IDTSPackage90 _                  ' __in IDTSPackage90 *pPackage
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   , BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromDtsServer <48> ( _                  ' VTable offset = 176
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadFromDtsServer <49> ( _                    ' VTable offset = 180
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bLoadNeutral AS INTEGER _                    ' __in VARIANT_BOOL bLoadNeutral
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   ) AS IDTSPackage90                                   ' __retval_out IDTSPackage90 **ppPackage
   ' =====================================================================================
   METHOD ExistsOnDtsServer <50> ( _                    ' VTable offset = 184
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbExists
   ' =====================================================================================
   METHOD GetDtsServerPackageInfos <51> ( _             ' VTable offset = 188
     BYVAL bstrPackageFolder AS WSTRING _               ' __in BSTR bstrPackageFolder
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   ) AS IDTSPackageInfos90                              ' __retval_out IDTSPackageInfos90 **ppRetVal
   ' =====================================================================================
   METHOD GetDtsServerRoles <52> ( _                    ' VTable offset = 192
     BYVAL bstrFolderPath AS WSTRING _                  ' __in BSTR bstrFolderPath
   , BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppRetVal
   ' =====================================================================================
   METHOD GetPackageInfos2 <61> ( _                     ' VTable offset = 196
     BYVAL bstrPackageFolder AS WSTRING _               ' __in BSTR bstrPackageFolder
   , BYVAL vConnectionObject AS VARIANT _               ' __in VARIANT vConnectionObject
   ) AS IDTSPackageInfos90                              ' __retval_out IDTSPackageInfos90 **ppRetVal
   ' =====================================================================================
   METHOD LoadFromSQLServer2 <62> ( _                   ' VTable offset = 200
     BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL vConnectionObject AS VARIANT _               ' __in VARIANT vConnectionObject
   , BYVAL bLoadNeutral AS INTEGER _                    ' __in VARIANT_BOOL bLoadNeutral
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   ) AS IDTSPackage90                                   ' __retval_out IDTSPackage90 **ppPackage
   ' =====================================================================================
   METHOD SetPackageRoles <63> ( _                      ' VTable offset = 204
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYVAL bstrReaderRole AS WSTRING _                  ' __in BSTR bstrReaderRole
   , BYVAL bstrWriterRole AS WSTRING _                  ' __in BSTR bstrWriterRole
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPackageRoles <64> ( _                      ' VTable offset = 208
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYVAL bstrPackagePath AS WSTRING _                 ' __in BSTR bstrPackagePath
   , BYREF pbstrReaderRole AS WSTRING _                 ' __out BSTR *pbstrReaderRole
   , BYREF pbstrWriterRole AS WSTRING _                 ' __out BSTR *pbstrWriterRole
   )                                                    ' void
   ' =====================================================================================
   METHOD GetServerVersionEx <65> ( _                   ' VTable offset = 212
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   , BYREF pdwEditionID AS DWORD _                      ' __out DWORD *pdwEditionID
   , BYREF peSsisEditionID AS LONG _                    ' __out enum DTSProductLevel *peSsisEditionID
   , BYREF pbstrProductVersion AS WSTRING _             ' __out BSTR *pbstrProductVersion
   , BYREF pbstrProductLevel AS WSTRING _               ' __out BSTR *pbstrProductLevel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSApplication90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBreakpointManager90
' IID = {584E430E-94F6-42BF-877A-65441CA39D1F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBreakpointManager90_INTERFACE_DEFINED)
    %IDTSBreakpointManager90_INTERFACE_DEFINED = 1

INTERFACE IDTSBreakpointManager90 $IID_IDTSBreakpointManager90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateBreakpointTarget <0> ( _                ' VTable offset = 28
     BYVAL breakpointID AS LONG _                       ' __in int breakpointID
   , BYVAL description AS WSTRING _                     ' __in BSTR description
   ) AS IDTSBreakpointTarget90                          ' __retval_out IDTSBreakpointTarget90 **ppBreakpoint
   ' =====================================================================================
   METHOD RemoveBreakpointTarget <1> ( _                ' VTable offset = 32
     BYVAL breakpointID AS LONG _                       ' __in int breakpointID
   )                                                    ' void
   ' =====================================================================================
   METHOD IsBreakpointTargetEnabled <2> ( _             ' VTable offset = 36
     BYVAL breakpointID AS LONG _                       ' __in int breakpointID
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsEnabled
   ' =====================================================================================
   METHOD GetBreakpointTarget <3> ( _                   ' VTable offset = 40
     BYVAL breakpointID AS LONG _                       ' __in int breakpointID
   ) AS IDTSBreakpointTarget90                          ' __retval_out IDTSBreakpointTarget90 **ppBreakpoint
   ' =====================================================================================
   METHOD ClearBreakpointTargets <4> ( _                ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBreakpointManager90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSSuspend90
' IID = {8BDFE910-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSSuspend90_INTERFACE_DEFINED)
    %IDTSSuspend90_INTERFACE_DEFINED = 1

INTERFACE IDTSSuspend90 $IID_IDTSSuspend90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SuspendExecution <0> ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ResumeExecution <1> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuspendRequired <2> ( _                 ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pSuspendRequired
   ' =====================================================================================
   PROPERTY SET SuspendRequired <2> ( _                 ' VTable offset = 40
     BYVAL suspendRequired AS INTEGER _                 ' __in VARIANT_BOOL suspendRequired
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSSuspend90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBreakpointSite90
' IID = {8BDFE911-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSSuspend90
' ########################################################################################

#IF NOT %DEF(%IDTSBreakpointSite90_INTERFACE_DEFINED)
    %IDTSBreakpointSite90_INTERFACE_DEFINED = 1

INTERFACE IDTSBreakpointSite90 $IID_IDTSBreakpointSite90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSSuspend90 Methods
   ' =====================================================================================
   METHOD SuspendExecution <0> ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ResumeExecution <1> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuspendRequired <2> ( _                 ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pSuspendRequired
   ' =====================================================================================
   PROPERTY SET SuspendRequired <2> ( _                 ' VTable offset = 40
     BYVAL suspendRequired AS INTEGER _                 ' __in VARIANT_BOOL suspendRequired
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSBreakpointSite90 Methods
   ' =====================================================================================
   METHOD AcceptBreakpointManager <3> ( _               ' VTable offset = 44
     BYVAL pBreakpointManager AS IDTSBreakpointManager90 _ ' __in IDTSBreakpointManager90 *pBreakpointManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DebugMode <4> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsInDebugMode
   ' =====================================================================================
   PROPERTY SET DebugMode <4> ( _                       ' VTable offset = 52
     BYVAL isInDebugMode AS INTEGER _                   ' __in VARIANT_BOOL isInDebugMode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBreakpointSite90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBreakpointTarget90
' IID = {8BDFE913-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBreakpointTarget90_INTERFACE_DEFINED)
    %IDTSBreakpointTarget90_INTERFACE_DEFINED = 1

INTERFACE IDTSBreakpointTarget90 $IID_IDTSBreakpointTarget90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Owner <0> ( _                           ' VTable offset = 28
   ) AS IDTSBreakpointSite90                            ' __retval_out IDTSBreakpointSite90 **ppBreakpointSite
   ' =====================================================================================
   PROPERTY GET Description <1> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pDescription
   ' =====================================================================================
   PROPERTY GET Enabled <2> ( _                         ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <2> ( _                         ' VTable offset = 40
     BYVAL isEnabled AS INTEGER _                       ' __in VARIANT_BOOL isEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HitCount <3> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pHitCount
   ' =====================================================================================
   PROPERTY GET ID <4> ( _                              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY GET HitTarget <5> ( _                       ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pHitTarget
   ' =====================================================================================
   PROPERTY SET HitTarget <5> ( _                       ' VTable offset = 56
     BYVAL hitTarget AS LONG _                          ' __in long hitTarget
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HitTest <6> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DTSBreakpointHitTest *pHitTest
   ' =====================================================================================
   PROPERTY SET HitTest <6> ( _                         ' VTable offset = 64
     BYVAL hitTest AS LONG _                            ' __in DTSBreakpointHitTest hitTest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BreakOnExpressionChange <7> ( _         ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBreak
   ' =====================================================================================
   PROPERTY SET BreakOnExpressionChange <7> ( _         ' VTable offset = 72
     BYVAL bBreak AS INTEGER _                          ' __in VARIANT_BOOL bBreak
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetHitCount <8> ( _                         ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBreakpointTarget90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBreakpointTargets90
' IID = {6073F7A8-2734-44B7-926B-95272CF154AD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBreakpointTargets90_INTERFACE_DEFINED)
    %IDTSBreakpointTargets90_INTERFACE_DEFINED = 1

INTERFACE IDTSBreakpointTargets90 $IID_IDTSBreakpointTargets90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSBreakpointTarget90                          ' __retval_out IDTSBreakpointTarget90 **ppBreakpointTarget
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBreakpointTargets90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSComponentPersist90
' IID = {8BDFE800-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSComponentPersist90_INTERFACE_DEFINED)
    %IDTSComponentPersist90_INTERFACE_DEFINED = 1

INTERFACE IDTSComponentPersist90 $IID_IDTSComponentPersist90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LoadFromXML <0> ( _                           ' VTable offset = 28
     BYVAL pDOMElement AS IDispatch _                   ' __in IDispatch *pDOMElement
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToXML <1> ( _                             ' VTable offset = 32
     BYVAL pDOMDocument AS IDispatch _                  ' __in IDispatch *pDOMDocument
   , BYVAL pEvents AS IDTSInfoEvents90 _                ' __in IDTSInfoEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSComponentPersist90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExecutionMetrics90
' IID = {8BDFE802-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExecutionMetrics90_INTERFACE_DEFINED)
    %IDTSExecutionMetrics90_INTERFACE_DEFINED = 1

INTERFACE IDTSExecutionMetrics90 $IID_IDTSExecutionMetrics90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StartTime <0> ( _                       ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out DATE *RetVal
   ' =====================================================================================
   PROPERTY GET StopTime <1> ( _                        ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out DATE *RetVal
   ' =====================================================================================
   PROPERTY GET ExecutionDuration <2> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExecutionMetrics90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEventHandler90
' IID = {8BDFE927-E9D8-4D23-9739-DA807BCDC2AC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEventHandler90_INTERFACE_DEFINED)
    %IDTSEventHandler90_INTERFACE_DEFINED = 1

INTERFACE IDTSEventHandler90 $IID_IDTSEventHandler90

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IDTSEventHandler90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSHttpClientConnection90
' IID = {70E8D509-6DF6-4722-9A60-2201CD7129E3}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSHttpClientConnection90_INTERFACE_DEFINED)
    %IDTSHttpClientConnection90_INTERFACE_DEFINED = 1

INTERFACE IDTSHttpClientConnection90 $IID_IDTSHttpClientConnection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServerURL <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pServerURL
   ' =====================================================================================
   PROPERTY SET ServerURL <1> ( _                       ' VTable offset = 32
     BYVAL serverURL AS WSTRING _                       ' __in BSTR serverURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseServerCredentials <3> ( _            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseServerCredentials
   ' =====================================================================================
   PROPERTY SET UseServerCredentials <3> ( _            ' VTable offset = 40
     BYVAL useServerCredentials AS INTEGER _            ' __in VARIANT_BOOL useServerCredentials
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerUserName <4> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pServerUserName
   ' =====================================================================================
   PROPERTY SET ServerUserName <4> ( _                  ' VTable offset = 48
     BYVAL serverUserName AS WSTRING _                  ' __in BSTR serverUserName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ServerPassword <5> ( _                  ' VTable offset = 52
     BYVAL serverPassword AS WSTRING _                  ' __in BSTR serverPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerDomain <6> ( _                    ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pServerDomain
   ' =====================================================================================
   PROPERTY SET ServerDomain <6> ( _                    ' VTable offset = 60
     BYVAL serverDomain AS WSTRING _                    ' __in BSTR serverDomain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseProxy <7> ( _                        ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseProxy
   ' =====================================================================================
   PROPERTY SET UseProxy <7> ( _                        ' VTable offset = 68
     BYVAL useProxy AS INTEGER _                        ' __in VARIANT_BOOL useProxy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProxyURL <8> ( _                        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pProxyURL
   ' =====================================================================================
   PROPERTY SET ProxyURL <8> ( _                        ' VTable offset = 76
     BYVAL proxyURL AS WSTRING _                        ' __in BSTR proxyURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BypassProxyOnLocal <10> ( _             ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBypassProxyOnLocal
   ' =====================================================================================
   PROPERTY SET BypassProxyOnLocal <10> ( _             ' VTable offset = 84
     BYVAL bypassProxyOnLocal AS INTEGER _              ' __in VARIANT_BOOL bypassProxyOnLocal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProxyUserName <12> ( _                  ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pProxyUserName
   ' =====================================================================================
   PROPERTY SET ProxyUserName <12> ( _                  ' VTable offset = 92
     BYVAL proxyUserName AS WSTRING _                   ' __in BSTR proxyUserName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ProxyPassword <13> ( _                  ' VTable offset = 96
     BYVAL proxyPassword AS WSTRING _                   ' __in BSTR proxyPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProxyDomain <14> ( _                    ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pProxyDomain
   ' =====================================================================================
   PROPERTY SET ProxyDomain <14> ( _                    ' VTable offset = 104
     BYVAL proxyDomain AS WSTRING _                     ' __in BSTR proxyDomain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Timeout <15> ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out int *pTimeout
   ' =====================================================================================
   PROPERTY SET Timeout <15> ( _                        ' VTable offset = 112
     BYVAL timeout AS LONG _                            ' __in int timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProxyBypassList <17> ( _                ' VTable offset = 116
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pProxyBypassList
   ' =====================================================================================
   PROPERTY SET ProxyBypassList <17> ( _                ' VTable offset = 120
     BYVAL proxyBypassList AS DWORD _                   ' __in SAFEARRAY * proxyBypassList
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Certificate <18> ( _                    ' VTable offset = 124
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pCertificate
   ' =====================================================================================
   PROPERTY SET Certificate <18> ( _                    ' VTable offset = 128
     BYVAL certificate AS DWORD _                       ' __in SAFEARRAY * certificate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseProxyCredentials <19> ( _            ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseProxyCredentials
   ' =====================================================================================
   PROPERTY SET UseProxyCredentials <19> ( _            ' VTable offset = 136
     BYVAL useProxyCredentials AS INTEGER _             ' __in VARIANT_BOOL useProxyCredentials
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CertificateIdentifier <20> ( _          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pCertificateIdentifier
   ' =====================================================================================
   PROPERTY SET CertificateIdentifier <20> ( _          ' VTable offset = 144
     BYVAL certificateIdentifier AS WSTRING _           '  __in BSTR certificateIdentifier
   )                                                    ' void
   ' =====================================================================================
   METHOD DownloadFile <21> ( _                         ' VTable offset = 148
     BYVAL fileName AS WSTRING _                        ' __in BSTR fileName
   , BYVAL vbOverwriteDestination AS INTEGER _          ' __in VARIANT_BOOL vbOverwriteDestination
   )                                                    ' void
   ' =====================================================================================
   METHOD DownloadData <22> ( _                         ' VTable offset = 152
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppData
   ' =====================================================================================
   METHOD OpenRead <23> ( _                             ' VTable offset = 156
   ) AS IStream                                         ' __retval_out IStream **ppFileStream
   ' =====================================================================================
   PROPERTY GET UseSecureConnection <24> ( _            ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseSecureConnection
   ' =====================================================================================
   PROPERTY SET UseSecureConnection <24> ( _            ' VTable offset = 164
     BYVAL useSecureConnection AS INTEGER _             ' __in VARIANT_BOOL useSecureConnection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChunkSize <25> ( _                      ' VTable offset = 168
   ) AS LONG                                            ' __retval_out int *pChunkSize
   ' =====================================================================================
   PROPERTY SET ChunkSize <25> ( _                      ' VTable offset = 172
     BYVAL chunkSize AS LONG _                          ' __in int chunkSize
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowCertificateDialog <26> ( _                ' VTable offset = 176
     BYVAL hWnd AS QUAD _                               ' __in LONGLONG hWnd
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <27> ( _                                ' VTable offset = 180
   ) AS IUnknown                                        ' __retval_out IUnknown **punkClone
   ' =====================================================================================
   METHOD GetServerPassword <28> ( _                    ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   METHOD GetProxyPassword <29> ( _                     ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSHttpClientConnection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerFtp90
' IID = {E605DF53-DBB8-4C13-A484-77E51440961D}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerFtp90_INTERFACE_DEFINED)
    %IDTSConnectionManagerFtp90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerFtp90 $IID_IDTSConnectionManagerFtp90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServerName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pServerName
   ' =====================================================================================
   PROPERTY SET ServerName <1> ( _                      ' VTable offset = 32
     BYVAL serverName AS WSTRING _                      ' __in BSTR serverName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerPort <2> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int *pServerPort
   ' =====================================================================================
   PROPERTY SET ServerPort <2> ( _                      ' VTable offset = 40
     BYVAL serverPort AS LONG _                         ' __in int serverPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerUserName <3> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pServerUsername
   ' =====================================================================================
   PROPERTY SET ServerUserName <3> ( _                  ' VTable offset = 48
     BYVAL serverUsername AS WSTRING _                  ' __in BSTR serverUsername
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ServerPassword <4> ( _                  ' VTable offset = 52
     BYVAL serverPassword AS WSTRING _                  ' __in BSTR serverPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Timeout <5> ( _                         ' VTable offset = 56
   ) AS LONG                                            ' __retval_out int *pTimeout
   ' =====================================================================================
   PROPERTY SET Timeout <5> ( _                         ' VTable offset = 60
     BYVAL timeout As LONG _                            ' __in int timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Retries <6> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out int *pRetries
   ' =====================================================================================
   PROPERTY SET Retries <6> ( _                         ' VTable offset = 68
     BYVAL retries AS LONG _                            ' __in int retries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsePassiveMode <7> ( _                  ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUsePassiveMode
   ' =====================================================================================
   PROPERTY SET UsePassiveMode <7> ( _                  ' VTable offset = 76
     BYVAL usePassiveMode AS INTEGER _                  ' __in VARIANT_BOOL usePassiveMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChunkSize <8> ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out int *pChunkSize
   ' =====================================================================================
   PROPERTY SET ChunkSize <8> ( _                       ' VTable offset = 84
     BYVAL chunkSize As LONG _                          ' __in int chunkSize
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerFtp90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSFtpClientConnection90
' IID = {13B22329-842F-404D-BDFD-6192A7463EAB}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSFtpClientConnection90_INTERFACE_DEFINED)
    %IDTSFtpClientConnection90_INTERFACE_DEFINED = 1

INTERFACE IDTSFtpClientConnection90 $IID_IDTSFtpClientConnection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServerName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pServerName
   ' =====================================================================================
   PROPERTY SET ServerName <1> ( _                      ' VTable offset = 32
     BYVAL serverName AS WSTRING _                      ' __in BSTR serverName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerPort <2> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int *pServerPort
   ' =====================================================================================
   PROPERTY SET ServerPort <2> ( _                      ' VTable offset = 40
     BYVAL serverPort AS LONG _                         ' __in int serverPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerUserName <3> ( _                  ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pServerUsername
   ' =====================================================================================
   PROPERTY SET ServerUserName <3> ( _                  ' VTable offset = 48
     BYVAL serverUsername AS WSTRING _                  ' __in BSTR serverUsername
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ServerPassword <4> ( _                  ' VTable offset = 52
     BYVAL serverPassword AS WSTRING _                  ' __in BSTR serverPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Timeout <5> ( _                         ' VTable offset = 56
   ) AS LONG                                            ' __retval_out int *pTimeout
   ' =====================================================================================
   PROPERTY SET Timeout <5> ( _                         ' VTable offset = 60
     BYVAL timeout AS LONG _                            ' __in int timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Retries <6> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out int *pRetries
   ' =====================================================================================
   PROPERTY SET Retries <6> ( _                         ' VTable offset = 68
     BYVAL retries AS LONG _                            ' __in int retries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsePassiveMode <7> ( _                  ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUsePassiveMode
   ' =====================================================================================
   PROPERTY SET UsePassiveMode <7> ( _                  ' VTable offset = 76
     BYVAL usePassiveMode AS INTEGER _                  ' __in VARIANT_BOOL usePassiveMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ChunkSize <8> ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out int *pChunkSize
   ' =====================================================================================
   PROPERTY SET ChunkSize <8> ( _                       ' VTable offset = 84
     BYVAL chunkSize AS LONG _                          ' __in int chunkSize
   )                                                    ' void
   ' =====================================================================================
   METHOD Connect <11> ( _                              ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bConnected
   ' =====================================================================================
   METHOD CreateRemoteDirectory <12> ( _                ' VTable offset = 92
     BYVAL remoteDirectoryPath AS WSTRING _             ' __in BSTR remoteDirectoryPath
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteRemoteDirectory <13> ( _                ' VTable offset = 96
     BYVAL remoteDirectoryPath AS WSTRING _             ' __in BSTR remoteDirectoryPath
   )                                                    ' void
   ' =====================================================================================
   METHOD GetWorkingDirectory <15> ( _                  ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pCurrentDirectory
   ' =====================================================================================
   METHOD DeleteFiles <16> ( _                          ' VTable offset = 104
     BYVAL remoteFiles AS DWORD _                       ' __in SAFEARRAY * remoteFiles
   )                                                    ' void
   ' =====================================================================================
   METHOD ReceiveFiles <17> ( _                         ' VTable offset = 108
     BYVAL remoteFileNames AS DWORD _                   ' __in SAFEARRAY * remoteFileNames
   , BYVAL localPath AS WSTRING _                       ' __in BSTR localPath
   , BYVAL overWrite AS INTEGER _                       ' __in VARIANT_BOOL overWrite
   , BYVAL transferASCII AS INTEGER _                   ' __in VARIANT_BOOL transferASCII
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWorkingDirectory <18> ( _                  ' VTable offset = 112
     BYVAL currentDirectory AS WSTRING _                ' __in BSTR currentDirectory
   )                                                    ' void
   ' =====================================================================================
   METHOD SendFiles <19> ( _                            ' VTable offset = 116
     BYVAL localFileNames As DWORD _                    ' __in SAFEARRAY * localFileNames
   , BYVAL remotePath AS WSTRING _                      ' __in BSTR remotePath
   , BYVAL overWrite AS INTEGER _                       ' __in VARIANT_BOOL overWrite
   , BYVAL transferASCII AS INTEGER _                   ' __in VARIANT_BOOL transferASCII
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <21> ( _                                ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD GetListing <22> ( _                           ' VTable offset = 124
     BYREF pFolderNames AS DWORD _                      ' __out SAFEARRAY * *pFolderNames
   , BYREF pFileNames AS DWORD _                        ' __out SAFEARRAY * *pFileNames
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSFtpClientConnection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPersist90
' IID = {D8AACE70-3218-4510-918C-74F0E0119EF0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPersist90_INTERFACE_DEFINED)
    %IDTSPersist90_INTERFACE_DEFINED = 1

INTERFACE IDTSPersist90 $IID_IDTSPersist90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SaveToXML <1> ( _                             ' VTable offset = 28
     BYVAL pDoc AS IDispatch _                          ' __in IDispatch *pDoc
   , BYVAL pNode AS IDispatch _                         ' __in IDispatch *pNode
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadFromXML <2> ( _                           ' VTable offset = 32
     BYVAL pNode AS IDispatch _                         ' __in IDispatch *pNode
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPersist90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPackagePersist90
' IID = {9C55492D-2A79-410C-AECF-9822EE6DE478}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPackagePersist90_INTERFACE_DEFINED)
    %IDTSPackagePersist90_INTERFACE_DEFINED = 1

INTERFACE IDTSPackagePersist90 $IID_IDTSPackagePersist90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SavePackageToXML <1> ( _                      ' VTable offset = 28
     BYREF pvDestination AS VARIANT _                   ' __out VARIANT *pvDestination
   , BYVAL vbReturnDOM AS INTEGER _                     ' __in VARIANT_BOOL vbReturnDOM
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadPackageFromXML <2> ( _                    ' VTable offset = 32
     BYVAL vSource AS VARIANT _                         ' __in VARIANT vSource
   , BYVAL vbSourceIsLocation AS INTEGER _              ' __in VARIANT_BOOL vbSourceIsLocation
   , BYVAL pEvents AS IDTSEvents90 _                    ' __in IDTSEvents90 *pEvents
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPackagePersist90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSObjectReferenceTracker90
' IID = {DBBD6258-4E30-429B-9454-C18598677CD9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSObjectReferenceTracker90_INTERFACE_DEFINED)
    %IDTSObjectReferenceTracker90_INTERFACE_DEFINED = 1

INTERFACE IDTSObjectReferenceTracker90 $IID_IDTSObjectReferenceTracker90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddReference <1610743808> ( _                 ' VTable offset = 28
     BYVAL ObjectNameOrID AS WSTRING _                  ' __in BSTR ObjectNameOrID
   , BYVAL RefType AS LONG _                            ' __in DTSObjectReferenceType RefType
   , BYREF RefListID AS LONG _                          ' __inout long *RefListID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveReference <1610743809> ( _              ' VTable offset = 32
     BYVAL ObjectNameOrID AS WSTRING _                  ' __in BSTR ObjectNameOrID
   , BYVAL RefType As LONG _                            ' __in DTSObjectReferenceType RefType
   , BYREF RefListID AS LONG _                          ' __inout long *RefListID
   )                                                    ' void
   ' =====================================================================================
   METHOD DestroyList <1610743810> ( _                  ' VTable offset = 36
     BYVAL RefListID AS LONG _                          ' __in long RefListID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetListInfo <1610743811> ( _                  ' VTable offset = 40
     BYVAL RefListID AS LONG _                          ' __in long RefListID
   , BYVAL UsageLocation AS WSTRING _                   ' __in BSTR UsageLocation
   , BYVAL UsageDescription AS WSTRING _                ' __in BSTR UsageDescription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSObjectReferenceTracker90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSEnumReferencedObjects90
' IID = {DC87DC7B-2415-4E65-9F71-AA545811A0E2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSEnumReferencedObjects90_INTERFACE_DEFINED)
    %IDTSEnumReferencedObjects90_INTERFACE_DEFINED = 1

INTERFACE IDTSEnumReferencedObjects90 $IID_IDTSEnumReferencedObjects90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Object <1610743808> ( _                 ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **RetVal
   ' =====================================================================================
   PROPERTY GET ReferenceType <1610743809> ( _          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out DTSObjectReferenceType *RetVal
   ' =====================================================================================
   PROPERTY GET UsageLocation <1610743810> ( _          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   PROPERTY GET UsageDescription <1610743811> ( _       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *RetVal
   ' =====================================================================================
   METHOD Next <1610743812> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSEnumReferencedObjects90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSServerUsageControl90
' IID = {D0FFBFA6-7247-48DD-BEF0-A758F9C7856C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSServerUsageControl90_INTERFACE_DEFINED)
    %IDTSServerUsageControl90_INTERFACE_DEFINED = 1

INTERFACE IDTSServerUsageControl90 $IID_IDTSServerUsageControl90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET UseServerForFeatureEnumeration <1610743808> ( _ ' VTable offset = 28
     BYVAL useServer AS INTEGER _                       ' __in VARIANT_BOOL useServer
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSServerUsageControl90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRunningPackage90
' IID = {8260DFAE-0AD3-4B5E-B331-BABACB4FE603}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSRunningPackage90_INTERFACE_DEFINED)
    %IDTSRunningPackage90_INTERFACE_DEFINED = 1

INTERFACE IDTSRunningPackage90 $IID_IDTSRunningPackage90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET InstanceID <1610743808> ( _             ' VTable offset = 28
   ) AS GUID                                            ' __retval_out GUID *instID
   ' =====================================================================================
   PROPERTY GET UserName <1610743809> ( _               ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *userName
   ' =====================================================================================
   PROPERTY GET PackageID <1610743810> ( _              ' VTable offset = 36
   ) AS GUID                                            ' __retval_out GUID *packageID
   ' =====================================================================================
   PROPERTY GET PackageName <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *packageName
   ' =====================================================================================
   PROPERTY GET PackageDescription <1610743812> ( _     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *packageDescription
   ' =====================================================================================
   METHOD Stop <1610743813> ( _                         ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionStartTime <1610743814> ( _     ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pStartTime
   ' =====================================================================================
   PROPERTY GET ExecutionDuration <1610743815> ( _      ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *pExecutionDuration
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSRunningPackage90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRunningPackages90
' IID = {2207E791-B9D4-4CBB-952D-61BC12FA0472}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSRunningPackages90_INTERFACE_DEFINED)
    %IDTSRunningPackages90_INTERFACE_DEFINED = 1

INTERFACE IDTSRunningPackages90 $IID_IDTSRunningPackages90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSRunningPackage90                            ' __retval_out IDTSRunningPackage90 **ppBreakpointTarget
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSRunningPackages90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSConnectionManagerExcel90
' IID = {4790DB35-116B-4596-8C1B-B2A710B1C8B0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSConnectionManagerExcel90_INTERFACE_DEFINED)
    %IDTSConnectionManagerExcel90_INTERFACE_DEFINED = 1

INTERFACE IDTSConnectionManagerExcel90 $IID_IDTSConnectionManagerExcel90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET FirstRowHasColumnName <1> ( _           ' VTable offset = 28
     BYVAL vbFirstRowHasColumnName AS INTEGER _         ' __in VARIANT_BOOL vbFirstRowHasColumnName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstRowHasColumnName <1> ( _           ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbFirstRowHasColumnName
   ' =====================================================================================
   PROPERTY SET ExcelFilePath <2> ( _                   ' VTable offset = 36
     BYVAL bstrExcelFilePath AS WSTRING _               ' __in BSTR bstrExcelFilePath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExcelFilePath <2> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExcelFilePath
   ' =====================================================================================
   PROPERTY SET ExcelVersionNumber <3> ( _              ' VTable offset = 44
     BYVAL enumExcelVersionNumber AS LONG _             ' __in DTSExcelVersion enumExcelVersionNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExcelVersionNumber <3> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DTSExcelVersion *penumExcelVersionNumber
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSConnectionManagerExcel90_INTERFACE_DEFINED__ */
