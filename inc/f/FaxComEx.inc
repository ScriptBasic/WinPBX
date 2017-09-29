' ########################################################################################
' Microsoft Windows
' File: FaxComEx.inc
' Library name: FAXCOMEXLib
' Version: 1.0, Locale ID = 0
' Library GUID: {2BF34C1A-8CAC-419F-8547-32FDF6505DB8}
' Library name: FXSCOMEX.dll
' Contents: Microsoft Fax Service Extended COM Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FAXCOMEX_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_FaxAccount = GUID$("{A7E0647F-4524-4464-A56D-B9FE666F715E}")
$CLSID_FaxAccountFolders = GUID$("{85398F49-C034-4A3F-821C-DB7D685E8129}")
$CLSID_FaxAccountIncomingArchive = GUID$("{14B33DB5-4C40-4ECF-9EF8-A360CBE809ED}")
$CLSID_FaxAccountIncomingQueue = GUID$("{9BCF6094-B4DA-45F4-B8D6-DDEB2186652C}")
$CLSID_FaxAccountOutgoingArchive = GUID$("{851E7AF5-433A-4739-A2DF-AD245C2CB98E}")
$CLSID_FaxAccountOutgoingQueue = GUID$("{FEECEEFB-C149-48BA-BAB8-B791E101F62F}")
$CLSID_FaxAccounts = GUID$("{DA1F94AA-EE2C-47C0-8F4F-2A217075B76E}")
$CLSID_FaxAccountSet = GUID$("{FBC23C4B-79E0-4291-BC56-C12E253BBF3A}")
$CLSID_FaxActivity = GUID$("{CFEF5D0E-E84D-462E-AABB-87D31EB04FEF}")
$CLSID_FaxActivityLogging = GUID$("{F0A0294E-3BBD-48B8-8F13-8C591A55BDBC}")
$CLSID_FaxConfiguration = GUID$("{5857326F-E7B3-41A7-9C19-A91B463E2D56}")
$CLSID_FaxDevice = GUID$("{59E3A5B2-D676-484B-A6DE-720BFA89B5AF}")
$CLSID_FaxDeviceIds = GUID$("{CDC539EA-7277-460E-8DE0-48A0A5760D1F}")
$CLSID_FaxDeviceProvider = GUID$("{17CF1AA3-F5EB-484A-9C9A-4440A5BAABFC}")
$CLSID_FaxDeviceProviders = GUID$("{EB8FE768-875A-4F5F-82C5-03F23AAC1BD7}")
$CLSID_FaxDevices = GUID$("{5589E28E-23CB-4919-8808-E6101846E80D}")
$CLSID_FaxDocument = GUID$("{0F3F9F91-C838-415E-A4F3-3E828CA445E0}")
$CLSID_FaxEventLogging = GUID$("{A6850930-A0F6-4A6F-95B7-DB2EBF3D02E3}")
$CLSID_FaxFolders = GUID$("{C35211D7-5776-48CB-AF44-C31BE3B2CFE5}")
$CLSID_FaxInboundRouting = GUID$("{E80248ED-AD65-4218-8108-991924D4E7ED}")
$CLSID_FaxInboundRoutingExtension = GUID$("{1D7DFB51-7207-4436-A0D9-24E32EE56988}")
$CLSID_FaxInboundRoutingExtensions = GUID$("{189A48ED-623C-4C0D-80F2-D66C7B9EFEC2}")
$CLSID_FaxInboundRoutingMethod = GUID$("{4B9FD75C-0194-4B72-9CE5-02A8205AC7D4}")
$CLSID_FaxInboundRoutingMethods = GUID$("{25FCB76A-B750-4B82-9266-FBBBAE8922BA}")
$CLSID_FaxIncomingArchive = GUID$("{8426C56A-35A1-4C6F-AF93-FC952422E2C2}")
$CLSID_FaxIncomingJob = GUID$("{C47311EC-AE32-41B8-AE4B-3EAE0629D0C9}")
$CLSID_FaxIncomingJobs = GUID$("{A1BB8A43-8866-4FB7-A15D-6266C875A5CC}")
$CLSID_FaxIncomingMessage = GUID$("{1932FCF7-9D43-4D5A-89FF-03861B321736}")
$CLSID_FaxIncomingMessageIterator = GUID$("{6088E1D8-3FC8-45C2-87B1-909A29607EA9}")
$CLSID_FaxIncomingQueue = GUID$("{69131717-F3F1-40E3-809D-A6CBF7BD85E5}")
$CLSID_FaxJobStatus = GUID$("{7BF222F4-BE8D-442F-841D-6132742423BB}")
$CLSID_FaxLoggingOptions = GUID$("{1BF9EEA6-ECE0-4785-A18B-DE56E9EEF96A}")
$CLSID_FaxOutboundRouting = GUID$("{C81B385E-B869-4AFD-86C0-616498ED9BE2}")
$CLSID_FaxOutboundRoutingGroup = GUID$("{0213F3E0-6791-4D77-A271-04D2357C50D6}")
$CLSID_FaxOutboundRoutingGroups = GUID$("{CCBEA1A5-E2B4-4B57-9421-B04B6289464B}")
$CLSID_FaxOutboundRoutingRule = GUID$("{6549EEBF-08D1-475A-828B-3BF105952FA0}")
$CLSID_FaxOutboundRoutingRules = GUID$("{D385BECA-E624-4473-BFAA-9F4000831F54}")
$CLSID_FaxOutgoingArchive = GUID$("{43C28403-E04F-474D-990C-B94669148F59}")
$CLSID_FaxOutgoingJob = GUID$("{71BB429C-0EF9-4915-BEC5-A5D897A3E924}")
$CLSID_FaxOutgoingJobs = GUID$("{92BF2A6C-37BE-43FA-A37D-CB0E5F753B35}")
$CLSID_FaxOutgoingMessage = GUID$("{91B4A378-4AD8-4AEF-A4DC-97D96E939A3A}")
$CLSID_FaxOutgoingMessageIterator = GUID$("{8A3224D0-D30B-49DE-9813-CB385790FBBB}")
$CLSID_FaxOutgoingQueue = GUID$("{7421169E-8C43-4B0D-BB16-645C8FA40357}")
$CLSID_FaxReceiptOptions = GUID$("{6982487B-227B-4C96-A61C-248348B05AB6}")
$CLSID_FaxRecipient = GUID$("{60BF3301-7DF8-4BD8-9148-7B5801F9EFDF}")
$CLSID_FaxRecipients = GUID$("{EA9BDF53-10A9-4D4F-A067-63C8F84F01B0}")
$CLSID_FaxSecurity = GUID$("{10C4DDDE-ABF0-43DF-964F-7F3AC21A4C7B}")
$CLSID_FaxSecurity2 = GUID$("{735C1248-EC89-4C30-A127-656E92E3C4EA}")
$CLSID_FaxSender = GUID$("{265D84D0-1850-4360-B7C8-758BBB5F0B96}")
$CLSID_FaxServer = GUID$("{CDA8ACB0-8CF5-4F6C-9BA2-5931D40C8CAE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IFaxAccount = GUID$("{68535B33-5DC4-4086-BE26-B76F9B711006}")
$IID_IFaxAccountFolders = GUID$("{6463F89D-23D8-46A9-8F86-C47B77CA7926}")
$IID_IFaxAccountIncomingArchive = GUID$("{A8A5B6EF-E0D6-4AEE-955C-91625BEC9DB4}")
$IID_IFaxAccountIncomingQueue = GUID$("{DD142D92-0186-4A95-A090-CBC3EADBA6B4}")
$IID_IFaxAccountNotify = GUID$("{0B5E5BD1-B8A9-47A0-A323-EF4A293BA06A}")
$IID_IFaxAccountOutgoingArchive = GUID$("{5463076D-EC14-491F-926E-B3CEDA5E5662}")
$IID_IFaxAccountOutgoingQueue = GUID$("{0F1424E9-F22D-4553-B7A5-0D24BD0D7E46}")
$IID_IFaxAccounts = GUID$("{93EA8162-8BE7-42D1-AE7B-EC74E2D989DA}")
$IID_IFaxAccountSet = GUID$("{7428FBAE-841E-47B8-86F4-2288946DCA1B}")
$IID_IFaxActivity = GUID$("{4B106F97-3DF5-40F2-BC3C-44CB8115EBDF}")
$IID_IFaxActivityLogging = GUID$("{1E29078B-5A69-497B-9592-49B7E7FADDB5}")
$IID_IFaxConfiguration = GUID$("{10F4D0F7-0994-4543-AB6E-506949128C40}")
$IID_IFaxDevice = GUID$("{49306C59-B52E-4867-9DF4-CA5841C956D0}")
$IID_IFaxDeviceIds = GUID$("{2F0F813F-4CE9-443E-8CA1-738CFAEEE149}")
$IID_IFaxDeviceProvider = GUID$("{290EAC63-83EC-449C-8417-F148DF8C682A}")
$IID_IFaxDeviceProviders = GUID$("{9FB76F62-4C7E-43A5-B6FD-502893F7E13E}")
$IID_IFaxDevices = GUID$("{9E46783E-F34F-482E-A360-0416BECBBD96}")
$IID_IFaxDocument = GUID$("{B207A246-09E3-4A4E-A7DC-FEA31D29458F}")
$IID_IFaxDocument2 = GUID$("{E1347661-F9EF-4D6D-B4A5-C0A068B65CFF}")
$IID_IFaxEventLogging = GUID$("{0880D965-20E8-42E4-8E17-944F192CAAD4}")
$IID_IFaxFolders = GUID$("{DCE3B2A8-A7AB-42BC-9D0A-3149457261A0}")
$IID_IFaxInboundRouting = GUID$("{8148C20F-9D52-45B1-BF96-38FC12713527}")
$IID_IFaxInboundRoutingExtension = GUID$("{885B5E08-C26C-4EF9-AF83-51580A750BE1}")
$IID_IFaxInboundRoutingExtensions = GUID$("{2F6C9673-7B26-42DE-8EB0-915DCD2A4F4C}")
$IID_IFaxInboundRoutingMethod = GUID$("{45700061-AD9D-4776-A8C4-64065492CF4B}")
$IID_IFaxInboundRoutingMethods = GUID$("{783FCA10-8908-4473-9D69-F67FBEA0C6B9}")
$IID_IFaxIncomingArchive = GUID$("{76062CC7-F714-4FBD-AA06-ED6E4A4B70F3}")
$IID_IFaxIncomingJob = GUID$("{207529E6-654A-4916-9F88-4D232EE8A107}")
$IID_IFaxIncomingJobs = GUID$("{011F04E9-4FD6-4C23-9513-B6B66BB26BE9}")
$IID_IFaxIncomingMessage = GUID$("{7CAB88FA-2EF9-4851-B2F3-1D148FED8447}")
$IID_IFaxIncomingMessage2 = GUID$("{F9208503-E2BC-48F3-9EC0-E6236F9B509A}")
$IID_IFaxIncomingMessageIterator = GUID$("{FD73ECC4-6F06-4F52-82A8-F7BA06AE3108}")
$IID_IFaxIncomingQueue = GUID$("{902E64EF-8FD8-4B75-9725-6014DF161545}")
$IID_IFaxJobStatus = GUID$("{8B86F485-FD7F-4824-886B-40C5CAA617CC}")
$IID_IFaxLoggingOptions = GUID$("{34E64FB9-6B31-4D32-8B27-D286C0C33606}")
$IID_IFaxOutboundRouting = GUID$("{25DC05A4-9909-41BD-A95B-7E5D1DEC1D43}")
$IID_IFaxOutboundRoutingGroup = GUID$("{CA6289A1-7E25-4F87-9A0B-93365734962C}")
$IID_IFaxOutboundRoutingGroups = GUID$("{235CBEF7-C2DE-4BFD-B8DA-75097C82C87F}")
$IID_IFaxOutboundRoutingRule = GUID$("{E1F795D5-07C2-469F-B027-ACACC23219DA}")
$IID_IFaxOutboundRoutingRules = GUID$("{DCEFA1E7-AE7D-4ED6-8521-369EDCCA5120}")
$IID_IFaxOutgoingArchive = GUID$("{C9C28F40-8D80-4E53-810F-9A79919B49FD}")
$IID_IFaxOutgoingJob = GUID$("{6356DAAD-6614-4583-BF7A-3AD67BBFC71C}")
$IID_IFaxOutgoingJob2 = GUID$("{418A8D96-59A0-4789-B176-EDF3DC8FA8F7}")
$IID_IFaxOutgoingJobs = GUID$("{2C56D8E6-8C2F-4573-944C-E505F8F5AEED}")
$IID_IFaxOutgoingMessage = GUID$("{F0EA35DE-CAA5-4A7C-82C7-2B60BA5F2BE2}")
$IID_IFaxOutgoingMessage2 = GUID$("{B37DF687-BC88-4B46-B3BE-B458B3EA9E7F}")
$IID_IFaxOutgoingMessageIterator = GUID$("{F5EC5D4F-B840-432F-9980-112FE42A9B7A}")
$IID_IFaxOutgoingQueue = GUID$("{80B1DF24-D9AC-4333-B373-487CEDC80CE5}")
$IID_IFaxReceiptOptions = GUID$("{378EFAEB-5FCB-4AFB-B2EE-E16E80614487}")
$IID_IFaxRecipient = GUID$("{9A3DA3A0-538D-42B6-9444-AAA57D0CE2BC}")
$IID_IFaxRecipients = GUID$("{B9C9DE5A-894E-4492-9FA3-08C627C11D5D}")
$IID_IFaxSecurity = GUID$("{77B508C1-09C0-47A2-91EB-FCE7FDF2690E}")
$IID_IFaxSecurity2 = GUID$("{17D851F4-D09B-48FC-99C9-8F24C4DB9AB1}")
$IID_IFaxSender = GUID$("{0D879D7D-F57A-4CC6-A6F9-3EE5D527B46A}")
$IID_IFaxServer = GUID$("{475B6469-90A5-4878-A577-17A86E8E3462}")
$IID_IFaxServer2 = GUID$("{571CED0F-5609-4F40-9176-547E3A72CA7C}")
$IID_IFaxServerNotify = GUID$("{2E037B27-CF8A-4ABD-B1E0-5704943BEA6F}")
$IID_IFaxServerNotify2 = GUID$("{616CA8D6-A77A-4062-ABFD-0E471241C7AA}")
$IID__IFaxAccountNotify = GUID$("{B9B3BC81-AC1B-46F3-B39D-0ADC30E1B788}")
$IID__IFaxServerNotify2 = GUID$("{EC9C69B9-5FE7-4805-9467-82FCD96AF903}")

%prv_DEFAULT_PREFETCH_SIZE	= 100

' enum FAX_ROUTING_RULE_CODE_ENUM
%frrcANY_CODE = 0   ' &H0

' ########################################################################################
' Interface name = IFaxServer
' IID = {475B6469-90A5-4878-A577-17A86E8E3462}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxServer_INTERFACE_DEFINED)
    %IFaxServer_INTERFACE_DEFINED = 1

' enum FAX_SERVER_EVENTS_TYPE_ENUM enum
%fsetNONE          = 0
%fsetIN_QUEUE      = &H1
%fsetOUT_QUEUE     = &H2
%fsetCONFIG        = &H4
%fsetACTIVITY      = &H8
%fsetQUEUE_STATE   = &H10
%fsetIN_ARCHIVE    = &H20
%fsetOUT_ARCHIVE   = &H40
%fsetFXSSVC_ENDED  = &H80
%fsetDEVICE_STATUS = &H100
%fsetINCOMING_CALL = &H200

' enum FAX_SERVER_APIVERSION_ENUM
%fsAPI_VERSION_0 = 0
%fsAPI_VERSION_1 = &H10000
%fsAPI_VERSION_2 = &H20000
%fsAPI_VERSION_3 = &H30000

INTERFACE IFaxServer $IID_IFaxServer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Connect <1> ( _                               ' VTable offset = 28
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerName <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrServerName
   ' =====================================================================================
   METHOD GetDeviceProviders <3> ( _                    ' VTable offset = 36
   ) AS IFaxDeviceProviders                             ' __retval_out IFaxDeviceProviders **ppFaxDeviceProviders
   ' =====================================================================================
   METHOD GetDevices <4> ( _                            ' VTable offset = 40
   ) AS IFaxDevices                                     ' __retval_out IFaxDevices **ppFaxDevices
   ' =====================================================================================
   PROPERTY GET InboundRouting <5> ( _                  ' VTable offset = 44
   ) AS IFaxInboundRouting                              ' __retval_out IFaxInboundRouting **ppFaxInboundRouting
   ' =====================================================================================
   PROPERTY GET Folders <6> ( _                         ' VTable offset = 48
   ) AS IFaxFolders                                     ' __retval_out IFaxFolders **pFaxFolders
   ' =====================================================================================
   PROPERTY GET LoggingOptions <7> ( _                  ' VTable offset = 52
   ) AS IFaxLoggingOptions                              ' __retval_out IFaxLoggingOptions **ppFaxLoggingOptions
   ' =====================================================================================
   PROPERTY GET MajorVersion <8> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <9> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   PROPERTY GET MajorBuild <10> ( _                     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plMajorBuild
   ' =====================================================================================
   PROPERTY GET MinorBuild <11> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plMinorBuild
   ' =====================================================================================
   PROPERTY GET Debug <12> ( _                          ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDebug
   ' =====================================================================================
   PROPERTY GET Activity <13> ( _                       ' VTable offset = 76
   ) AS IFaxActivity                                    ' __retval_out IFaxActivity **ppFaxActivity
   ' =====================================================================================
   PROPERTY GET OutboundRouting <14> ( _                ' VTable offset = 80
   ) AS IFaxOutboundRouting                             ' __retval_out IFaxOutboundRouting **ppFaxOutboundRouting
   ' =====================================================================================
   PROPERTY GET ReceiptOptions <15> ( _                 ' VTable offset = 84
   ) AS IFaxReceiptOptions                              ' __retval_out IFaxReceiptOptions **ppFaxReceiptOptions
   ' =====================================================================================
   PROPERTY GET Security <16> ( _                       ' VTable offset = 88
   ) AS IFaxSecurity                                    ' __retval_out IFaxSecurity **ppFaxSecurity
   ' =====================================================================================
   METHOD Disconnect <17> ( _                           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtensionProperty <18> ( _                 ' VTable offset = 96
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProperty
   ' =====================================================================================
   METHOD SetExtensionProperty <19> ( _                 ' VTable offset = 100
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   , BYVAL vProperty AS VARIANT _                       ' __in VARIANT vProperty
   )                                                    ' void
   ' =====================================================================================
   METHOD ListenToServerEvents <20> ( _                 ' VTable offset = 104
     BYVAL EventTypes AS LONG _                         ' __in FAX_SERVER_EVENTS_TYPE_ENUM EventTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterDeviceProvider <21> ( _               ' VTable offset = 108
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   , BYVAL bstrImageName AS WSTRING _                   ' __in BSTR bstrImageName
   , BYVAL TspName AS WSTRING _                         ' __in BSTR TspName
   , BYVAL lFSPIVersion AS LONG _                       ' __in long lFSPIVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterDeviceProvider <22> ( _             ' VTable offset = 112
     BYVAL bstrUniqueName AS WSTRING _                  ' __in BSTR bstrUniqueName
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterInboundRoutingExtension <23> ( _      ' VTable offset = 116
     BYVAL bstrExtensionName AS WSTRING _               ' __in BSTR bstrExtensionName
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   , BYVAL bstrImageName AS WSTRING _                   ' __in BSTR bstrImageName
   , BYVAL vMethods AS VARIANT _                        ' __in VARIANT vMethods
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterInboundRoutingExtension <24> ( _    ' VTable offset = 120
     BYVAL bstrExtensionUniqueName AS WSTRING _         ' __in BSTR bstrExtensionUniqueName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegisteredEvents <25> ( _               ' VTable offset = 124
   ) AS LONG                                            ' __retval_out FAX_SERVER_EVENTS_TYPE_ENUM *pEventTypes
   ' =====================================================================================
   PROPERTY GET APIVersion <26> ( _                     ' VTable offset = 128
   ) AS LONG                                            ' __retval_out FAX_SERVER_APIVERSION_ENUM *pAPIVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDeviceProviders
' IID = {9FB76F62-4C7E-43A5-B6FD-502893F7E13E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDeviceProviders_INTERFACE_DEFINED)
    %IFaxDeviceProviders_INTERFACE_DEFINED = 1

INTERFACE IFaxDeviceProviders $IID_IFaxDeviceProviders

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxDeviceProvider                              ' __retval_out IFaxDeviceProvider **pFaxDeviceProvider
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDeviceProviders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDeviceProvider
' IID = {290EAC63-83EC-449C-8417-F148DF8C682A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDeviceProvider_INTERFACE_DEFINED)
    %IFaxDeviceProvider_INTERFACE_DEFINED = 1

' enum FAX_PROVIDER_STATUS_ENUM
%fpsSUCCESS      = 0
%fpsSERVER_ERROR = %fpsSUCCESS + 1
%fpsBAD_GUID     = %fpsSERVER_ERROR + 1
%fpsBAD_VERSION  = %fpsBAD_GUID + 1
%fpsCANT_LOAD    = %fpsBAD_VERSION + 1
%fpsCANT_LINK    = %fpsCANT_LOAD + 1
%fpsCANT_INIT    = %fpsCANT_LINK + 1

INTERFACE IFaxDeviceProvider $IID_IFaxDeviceProvider

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FriendlyName <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFriendlyName
   ' =====================================================================================
   PROPERTY GET ImageName <2> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrImageName
   ' =====================================================================================
   PROPERTY GET UniqueName <3> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUniqueName
   ' =====================================================================================
   PROPERTY GET TapiProviderName <4> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTapiProviderName
   ' =====================================================================================
   PROPERTY GET MajorVersion <5> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <6> ( _                    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   PROPERTY GET MajorBuild <7> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plMajorBuild
   ' =====================================================================================
   PROPERTY GET MinorBuild <8> ( _                      ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plMinorBuild
   ' =====================================================================================
   PROPERTY GET Debug <9> ( _                           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDebug
   ' =====================================================================================
   PROPERTY GET Status <10> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_PROVIDER_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET InitErrorCode <11> ( _                  ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plInitErrorCode
   ' =====================================================================================
   PROPERTY GET DeviceIds <12> ( _                      ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvDeviceIds
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDeviceProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDevices
' IID = {9E46783E-F34F-482E-A360-0416BECBBD96}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDevices_INTERFACE_DEFINED)
    %IFaxDevices_INTERFACE_DEFINED = 1

INTERFACE IFaxDevices $IID_IFaxDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxDevice                                      ' __retval_out IFaxDevice **pFaxDevice
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET ItemById <2> ( _                        ' VTable offset = 40
     BYVAL lId AS LONG _                                ' __in long lId
   ) AS IFaxDevice                                      ' __retval_out IFaxDevice **ppFaxDevice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDevices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDevice
' IID = {49306C59-B52E-4867-9DF4-CA5841C956D0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDevice_INTERFACE_DEFINED)
    %IFaxDevice_INTERFACE_DEFINED = 1

' enum FAX_DEVICE_RECEIVE_MODE_ENUM
%fdrmNO_ANSWER     = 0
%fdrmAUTO_ANSWER   = %fdrmNO_ANSWER + 1
%fdrmMANUAL_ANSWER = %fdrmAUTO_ANSWER + 1

' enum FAX_LOG_LEVEL_ENUM
%fllNONE = 0
%fllMIN  = %fllNONE + 1
%fllMED  = %fllMIN + 1
%fllMAX  = %fllMED + 1

INTERFACE IFaxDevice $IID_IFaxDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plId
   ' =====================================================================================
   PROPERTY GET DeviceName <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET ProviderUniqueName <3> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProviderUniqueName
   ' =====================================================================================
   PROPERTY GET PoweredOff <4> ( _                      ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbPoweredOff
   ' =====================================================================================
   PROPERTY GET ReceivingNow <5> ( _                    ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbReceivingNow
   ' =====================================================================================
   PROPERTY GET SendingNow <6> ( _                      ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSendingNow
   ' =====================================================================================
   PROPERTY GET UsedRoutingMethods <7> ( _              ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvUsedRoutingMethods
   ' =====================================================================================
   PROPERTY GET Description <8> ( _                     ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <8> ( _                     ' VTable offset = 60
     BYVAL pbstrDescription AS WSTRING _                ' __in BSTR pbstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendEnabled <9> ( _                     ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSendEnabled
   ' =====================================================================================
   PROPERTY SET SendEnabled <9> ( _                     ' VTable offset = 68
     BYVAL pbSendEnabled AS INTEGER _                   ' __in VARIANT_BOOL pbSendEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceiveMode <10> ( _                    ' VTable offset = 72
   ) AS LONG                                            ' __retval_out FAX_DEVICE_RECEIVE_MODE_ENUM *pReceiveMode
   ' =====================================================================================
   PROPERTY SET ReceiveMode <10> ( _                    ' VTable offset = 76
     BYVAL pReceiveMode AS LONG _                       ' __in FAX_DEVICE_RECEIVE_MODE_ENUM pReceiveMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RingsBeforeAnswer <11> ( _              ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plRingsBeforeAnswer
   ' =====================================================================================
   PROPERTY SET RingsBeforeAnswer <11> ( _              ' VTable offset = 84
     BYVAL plRingsBeforeAnswer AS LONG _                ' __in long plRingsBeforeAnswer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CSID <12> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY SET CSID <12> ( _                           ' VTable offset = 92
     BYVAL pbstrCSID AS WSTRING _                       ' __in BSTR pbstrCSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <13> ( _                           ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY SET TSID <13> ( _                           ' VTable offset = 100
     BYVAL pbstrTSID AS WSTRING _                       ' __in BSTR pbstrTSID
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <14> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <15> ( _                                 ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtensionProperty <16> ( _                 ' VTable offset = 112
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProperty
   ' =====================================================================================
   METHOD SetExtensionProperty <17> ( _                 ' VTable offset = 116
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   , BYVAL vProperty AS VARIANT _                       ' __in VARIANT vProperty
   )                                                    ' void
   ' =====================================================================================
   METHOD UseRoutingMethod <18> ( _                     ' VTable offset = 120
     BYVAL bstrMethodGUID AS WSTRING _                  ' __in BSTR bstrMethodGUID
   , BYVAL bUse AS INTEGER _                            ' __in VARIANT_BOOL bUse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RingingNow <19> ( _                     ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRingingNow
   ' =====================================================================================
   METHOD AnswerCall <20> ( _                           ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxInboundRouting
' IID = {8148C20F-9D52-45B1-BF96-38FC12713527}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxInboundRouting_INTERFACE_DEFINED)
    %IFaxInboundRouting_INTERFACE_DEFINED = 1

INTERFACE IFaxInboundRouting $IID_IFaxInboundRouting

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetExtensions <1> ( _                         ' VTable offset = 28
   ) AS IFaxInboundRoutingExtensions                    ' __retval_out IFaxInboundRoutingExtensions **pFaxInboundRoutingExtensions
   ' =====================================================================================
   METHOD GetMethods <2> ( _                            ' VTable offset = 32
   ) AS IFaxInboundRoutingMethods                       ' __retval_out IFaxInboundRoutingMethods **pFaxInboundRoutingMethods
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxInboundRouting_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxInboundRoutingExtensions
' IID = {2F6C9673-7B26-42DE-8EB0-915DCD2A4F4C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxInboundRoutingExtensions_INTERFACE_DEFINED)
    %IFaxInboundRoutingExtensions_INTERFACE_DEFINED = 1

INTERFACE IFaxInboundRoutingExtensions $IID_IFaxInboundRoutingExtensions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxInboundRoutingExtension                     ' __retval_out IFaxInboundRoutingExtension **pFaxInboundRoutingExtension
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxInboundRoutingExtensions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxInboundRoutingExtension
' IID = {885B5E08-C26C-4EF9-AF83-51580A750BE1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxInboundRoutingExtension_INTERFACE_DEFINED)
    %IFaxInboundRoutingExtension_INTERFACE_DEFINED = 1

INTERFACE IFaxInboundRoutingExtension $IID_IFaxInboundRoutingExtension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FriendlyName <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFriendlyName
   ' =====================================================================================
   PROPERTY GET ImageName <2> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrImageName
   ' =====================================================================================
   PROPERTY GET UniqueName <3> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUniqueName
   ' =====================================================================================
   PROPERTY GET MajorVersion <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <5> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   PROPERTY GET MajorBuild <6> ( _                      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plMajorBuild
   ' =====================================================================================
   PROPERTY GET MinorBuild <7> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plMinorBuild
   ' =====================================================================================
   PROPERTY GET Debug <8> ( _                           ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDebug
   ' =====================================================================================
   PROPERTY GET Status <9> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out FAX_PROVIDER_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET InitErrorCode <10> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plInitErrorCode
   ' =====================================================================================
   PROPERTY GET Methods <11> ( _                        ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvMethods
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxInboundRoutingExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxInboundRoutingMethods
' IID = {783FCA10-8908-4473-9D69-F67FBEA0C6B9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxInboundRoutingMethods_INTERFACE_DEFINED)
    %IFaxInboundRoutingMethods_INTERFACE_DEFINED = 1

INTERFACE IFaxInboundRoutingMethods $IID_IFaxInboundRoutingMethods

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxInboundRoutingMethod                        ' __retval_out IFaxInboundRoutingMethod **pFaxInboundRoutingMethod
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxInboundRoutingMethods_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxInboundRoutingMethod
' IID = {45700061-AD9D-4776-A8C4-64065492CF4B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxInboundRoutingMethod_INTERFACE_DEFINED)
    %IFaxInboundRoutingMethod_INTERFACE_DEFINED = 1

INTERFACE IFaxInboundRoutingMethod $IID_IFaxInboundRoutingMethod

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET GUID <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGUID
   ' =====================================================================================
   PROPERTY GET FunctionName <3> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFunctionName
   ' =====================================================================================
   PROPERTY GET ExtensionFriendlyName <4> ( _           ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtensionFriendlyName
   ' =====================================================================================
   PROPERTY GET ExtensionImageName <5> ( _              ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtensionImageName
   ' =====================================================================================
   PROPERTY GET Priority <6> ( _                        ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plPriority
   ' =====================================================================================
   PROPERTY SET Priority <6> ( _                        ' VTable offset = 52
     BYVAL plPriority AS LONG _                         ' __in long plPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <7> ( _                               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <8> ( _                                  ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxInboundRoutingMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxFolders
' IID = {DCE3B2A8-A7AB-42BC-9D0A-3149457261A0}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxFolders_INTERFACE_DEFINED)
    %IFaxFolders_INTERFACE_DEFINED = 1

INTERFACE IFaxFolders $IID_IFaxFolders

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OutgoingQueue <1> ( _                   ' VTable offset = 28
   ) AS IFaxOutgoingQueue                               ' __retval_out IFaxOutgoingQueue **pFaxOutgoingQueue
   ' =====================================================================================
   PROPERTY GET IncomingQueue <2> ( _                   ' VTable offset = 32
   ) AS IFaxIncomingQueue                               ' __retval_out IFaxIncomingQueue **pFaxIncomingQueue
   ' =====================================================================================
   PROPERTY GET IncomingArchive <3> ( _                 ' VTable offset = 36
   ) AS IFaxIncomingArchive                             ' __retval_out IFaxIncomingArchive **pFaxIncomingArchive
   ' =====================================================================================
   PROPERTY GET OutgoingArchive <4> ( _                 ' VTable offset = 40
   ) AS IFaxOutgoingArchive                             ' __retval_out IFaxOutgoingArchive **pFaxOutgoingArchive
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxFolders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingQueue
' IID = {80B1DF24-D9AC-4333-B373-487CEDC80CE5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingQueue_INTERFACE_DEFINED)
    %IFaxOutgoingQueue_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingQueue $IID_IFaxOutgoingQueue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Blocked <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBlocked
   ' =====================================================================================
   PROPERTY SET Blocked <1> ( _                         ' VTable offset = 32
     BYVAL pbBlocked AS INTEGER _                       ' __in VARIANT_BOOL pbBlocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Paused <2> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbPaused
   ' =====================================================================================
   PROPERTY SET Paused <2> ( _                          ' VTable offset = 40
     BYVAL pbPaused AS INTEGER _                        ' __in VARIANT_BOOL pbPaused
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowPersonalCoverPages <3> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowPersonalCoverPages
   ' =====================================================================================
   PROPERTY SET AllowPersonalCoverPages <3> ( _         ' VTable offset = 48
     BYVAL pbAllowPersonalCoverPages AS INTEGER _       ' __in VARIANT_BOOL pbAllowPersonalCoverPages
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseDeviceTSID <4> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseDeviceTSID
   ' =====================================================================================
   PROPERTY SET UseDeviceTSID <4> ( _                   ' VTable offset = 56
     BYVAL pbUseDeviceTSID AS INTEGER _                 ' __in VARIANT_BOOL pbUseDeviceTSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Retries <5> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY SET Retries <5> ( _                         ' VTable offset = 64
     BYVAL plRetries AS LONG _                          ' __in long plRetries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetryDelay <6> ( _                      ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plRetryDelay
   ' =====================================================================================
   PROPERTY SET RetryDelay <6> ( _                      ' VTable offset = 72
     BYVAL plRetryDelay AS LONG _                       ' __in long plRetryDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateStart <7> ( _               ' VTable offset = 76
   ) AS DOUBLE                                          ' __retval_out DATE *pdateDiscountRateStart
   ' =====================================================================================
   PROPERTY SET DiscountRateStart <7> ( _               ' VTable offset = 80
     BYVAL pdateDiscountRateStart AS DOUBLE _           ' __in DATE pdateDiscountRateStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateEnd <8> ( _                 ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pdateDiscountRateEnd
   ' =====================================================================================
   PROPERTY SET DiscountRateEnd <8> ( _                 ' VTable offset = 88
     BYVAL pdateDiscountRateEnd AS DOUBLE _             ' __in DATE pdateDiscountRateEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AgeLimit <9> ( _                        ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAgeLimit
   ' =====================================================================================
   PROPERTY SET AgeLimit <9> ( _                        ' VTable offset = 96
     BYVAL plAgeLimit AS LONG _                         ' __in long plAgeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Branding <10> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBranding
   ' =====================================================================================
   PROPERTY SET Branding <10> ( _                       ' VTable offset = 104
     BYVAL pbBranding AS INTEGER _                      ' __in VARIANT_BOOL pbBranding
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <11> ( _                              ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <12> ( _                                 ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD GetJobs <13> ( _                              ' VTable offset = 116
   ) AS IFaxOutgoingJobs                                ' __retval_out IFaxOutgoingJobs **pFaxOutgoingJobs
   ' =====================================================================================
   METHOD GetJob <14> ( _                               ' VTable offset = 120
     BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
   ) AS IFaxOutgoingJob                                 ' __retval_out IFaxOutgoingJob **pFaxOutgoingJob
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingJobs
' IID = {2C56D8E6-8C2F-4573-944C-E505F8F5AEED}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingJobs_INTERFACE_DEFINED)
    %IFaxOutgoingJobs_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingJobs $IID_IFaxOutgoingJobs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxOutgoingJob                                 ' __retval_out IFaxOutgoingJob **pFaxOutgoingJob
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingJobs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingJob
' IID = {6356DAAD-6614-4583-BF7A-3AD67BBFC71C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingJob_INTERFACE_DEFINED)
    %IFaxOutgoingJob_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingJob $IID_IFaxOutgoingJob

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Subject <1> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY GET DocumentName <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY GET Pages <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <4> ( _                            ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET SubmissionId <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubmissionId
   ' =====================================================================================
   PROPERTY GET Id <6> ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET OriginalScheduledTime <7> ( _           ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pdateOriginalScheduledTime
   ' =====================================================================================
   PROPERTY GET SubmissionTime <8> ( _                  ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSubmissionTime
   ' =====================================================================================
   PROPERTY GET ReceiptType <9> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pReceiptType
   ' =====================================================================================
   PROPERTY GET Priority <10> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY GET Sender <11> ( _                         ' VTable offset = 68
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipient <12> ( _                      ' VTable offset = 72
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   PROPERTY GET CurrentPage <13> ( _                    ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plCurrentPage
   ' =====================================================================================
   PROPERTY GET DeviceId <14> ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY GET Status <15> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out FAX_JOB_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET ExtendedStatusCode <16> ( _             ' VTable offset = 88
   ) AS LONG                                            ' __retval_out FAX_JOB_EXTENDED_STATUS_ENUM *pExtendedStatusCode
   ' =====================================================================================
   PROPERTY GET ExtendedStatus <17> ( _                 ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtendedStatus
   ' =====================================================================================
   PROPERTY GET AvailableOperations <18> ( _            ' VTable offset = 96
   ) AS LONG                                            ' __retval_out FAX_JOB_OPERATIONS_ENUM *pAvailableOperations
   ' =====================================================================================
   PROPERTY GET Retries <19> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET ScheduledTime <20> ( _                  ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out DATE *pdateScheduledTime
   ' =====================================================================================
   PROPERTY GET TransmissionStart <21> ( _              ' VTable offset = 108
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <22> ( _                ' VTable offset = 112
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <23> ( _                           ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <24> ( _                           ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET GroupBroadcastReceipts <25> ( _         ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbGroupBroadcastReceipts
   ' =====================================================================================
   METHOD Pause <26> ( _                                ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <27> ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Restart <28> ( _                              ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyTiff <29> ( _                             ' VTable offset = 140
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <30> ( _                              ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <31> ( _                               ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingJob_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxSender
' IID = {0D879D7D-F57A-4CC6-A6F9-3EE5D527B46A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxSender_INTERFACE_DEFINED)
    %IFaxSender_INTERFACE_DEFINED = 1

INTERFACE IFaxSender $IID_IFaxSender

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BillingCode <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBillingCode
   ' =====================================================================================
   PROPERTY SET BillingCode <1> ( _                     ' VTable offset = 32
     BYVAL pbstrBillingCode AS WSTRING _                ' __in BSTR pbstrBillingCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET City <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCity
   ' =====================================================================================
   PROPERTY SET City <2> ( _                            ' VTable offset = 40
     BYVAL pbstrCity AS WSTRING _                       ' __in BSTR pbstrCity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Company <3> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCompany
   ' =====================================================================================
   PROPERTY SET Company <3> ( _                         ' VTable offset = 48
     BYVAL pbstrCompany AS WSTRING _                    ' __in BSTR pbstrCompany
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Country <4> ( _                         ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCountry
   ' =====================================================================================
   PROPERTY SET Country <4> ( _                         ' VTable offset = 56
     BYVAL pbstrCountry AS WSTRING _                    ' __in BSTR pbstrCountry
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Department <5> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDepartment
   ' =====================================================================================
   PROPERTY SET Department <5> ( _                      ' VTable offset = 64
     BYVAL pbstrDepartment AS WSTRING _                 ' __in BSTR pbstrDepartment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Email <6> ( _                           ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrEmail
   ' =====================================================================================
   PROPERTY SET Email <6> ( _                           ' VTable offset = 72
     BYVAL pbstrEmail AS WSTRING _                      ' __in BSTR pbstrEmail
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FaxNumber <7> ( _                       ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFaxNumber
   ' =====================================================================================
   PROPERTY SET FaxNumber <7> ( _                       ' VTable offset = 80
     BYVAL pbstrFaxNumber AS WSTRING _                  ' __in BSTR pbstrFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePhone <8> ( _                       ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrHomePhone
   ' =====================================================================================
   PROPERTY SET HomePhone <8> ( _                       ' VTable offset = 88
     BYVAL pbstrHomePhone AS WSTRING _                  ' __in BSTR pbstrHomePhone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <9> ( _                            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <9> ( _                            ' VTable offset = 96
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <10> ( _                           ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY SET TSID <10> ( _                           ' VTable offset = 104
     BYVAL pbstrTSID AS WSTRING _                       ' __in BSTR pbstrTSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfficePhone <11> ( _                    ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOfficePhone
   ' =====================================================================================
   PROPERTY SET OfficePhone <11> ( _                    ' VTable offset = 112
     BYVAL pbstrOfficePhone AS WSTRING _                ' __in BSTR pbstrOfficePhone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfficeLocation <12> ( _                 ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOfficeLocation
   ' =====================================================================================
   PROPERTY SET OfficeLocation <12> ( _                 ' VTable offset = 120
     BYVAL pbstrOfficeLocation AS WSTRING _             ' __in BSTR pbstrOfficeLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <13> ( _                          ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrState
   ' =====================================================================================
   PROPERTY SET State <13> ( _                          ' VTable offset = 128
     BYVAL pbstrState AS WSTRING _                      ' __in BSTR pbstrState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StreetAddress <14> ( _                  ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStreetAddress
   ' =====================================================================================
   PROPERTY SET StreetAddress <14> ( _                  ' VTable offset = 136
     BYVAL pbstrStreetAddress AS WSTRING _              ' __in BSTR pbstrStreetAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Title <15> ( _                          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTitle
   ' =====================================================================================
   PROPERTY SET Title <15> ( _                          ' VTable offset = 144
     BYVAL pbstrTitle AS WSTRING _                      ' __in BSTR pbstrTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ZipCode <16> ( _                        ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrZipCode
   ' =====================================================================================
   PROPERTY SET ZipCode <16> ( _                        ' VTable offset = 152
     BYVAL pbstrZipCode AS WSTRING _                    ' __in BSTR pbstrZipCode
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadDefaultSender <17> ( _                    ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveDefaultSender <18> ( _                    ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxSender_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxRecipient
' IID = {9A3DA3A0-538D-42B6-9444-AAA57D0CE2BC}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxRecipient_INTERFACE_DEFINED)
    %IFaxRecipient_INTERFACE_DEFINED = 1

INTERFACE IFaxRecipient $IID_IFaxRecipient

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FaxNumber <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFaxNumber
   ' =====================================================================================
   PROPERTY SET FaxNumber <1> ( _                       ' VTable offset = 32
     BYVAL pbstrFaxNumber AS WSTRING _                  ' __in BSTR pbstrFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <2> ( _                            ' VTable offset = 40
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxRecipient_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingQueue
' IID = {902E64EF-8FD8-4B75-9725-6014DF161545}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingQueue_INTERFACE_DEFINED)
    %IFaxIncomingQueue_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingQueue $IID_IFaxIncomingQueue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Blocked <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBlocked
   ' =====================================================================================
   PROPERTY SET Blocked <1> ( _                         ' VTable offset = 32
     BYVAL pbBlocked AS INTEGER _                       ' __in VARIANT_BOOL pbBlocked
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <3> ( _                                  ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD GetJobs <4> ( _                               ' VTable offset = 44
   ) AS IFaxIncomingJobs                                ' __retval_out IFaxIncomingJobs **pFaxIncomingJobs
   ' =====================================================================================
   METHOD GetJob <5> ( _                                ' VTable offset = 48
     BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
   ) AS IFaxIncomingJob                                 ' __retval_out IFaxIncomingJob **pFaxIncomingJob
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingJobs
' IID = {011F04E9-4FD6-4C23-9513-B6B66BB26BE9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingJobs_INTERFACE_DEFINED)
    %IFaxIncomingJobs_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingJobs $IID_IFaxIncomingJobs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxIncomingJob                                 ' __retval_out IFaxIncomingJob **pFaxIncomingJob
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingJobs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingJob
' IID = {207529E6-654A-4916-9F88-4D232EE8A107}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingJob_INTERFACE_DEFINED)
    %IFaxIncomingJob_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingJob $IID_IFaxIncomingJob

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Size <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET CurrentPage <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCurrentPage
   ' =====================================================================================
   PROPERTY GET DeviceId <4> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY GET Status <5> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out FAX_JOB_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET ExtendedStatusCode <6> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out FAX_JOB_EXTENDED_STATUS_ENUM *pExtendedStatusCode
   ' =====================================================================================
   PROPERTY GET ExtendedStatus <7> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtendedStatus
   ' =====================================================================================
   PROPERTY GET AvailableOperations <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out FAX_JOB_OPERATIONS_ENUM *pAvailableOperations
   ' =====================================================================================
   PROPERTY GET Retries <9> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET TransmissionStart <10> ( _              ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <11> ( _                ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <12> ( _                           ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <13> ( _                           ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET CallerId <14> ( _                       ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCallerId
   ' =====================================================================================
   PROPERTY GET RoutingInformation <15> ( _             ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRoutingInformation
   ' =====================================================================================
   PROPERTY GET JobType <16> ( _                        ' VTable offset = 88
   ) AS LONG                                            ' __retval_out FAX_JOB_TYPE_ENUM *pJobType
   ' =====================================================================================
   METHOD Cancel <17> ( _                               ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <18> ( _                              ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyTiff <19> ( _                             ' VTable offset = 100
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingJob_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingArchive
' IID = {76062CC7-F714-4FBD-AA06-ED6E4A4B70F3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingArchive_INTERFACE_DEFINED)
    %IFaxIncomingArchive_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingArchive $IID_IFaxIncomingArchive

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UseArchive <1> ( _                      ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseArchive
   ' =====================================================================================
   PROPERTY SET UseArchive <1> ( _                      ' VTable offset = 32
     BYVAL pbUseArchive AS INTEGER _                    ' __in VARIANT_BOOL pbUseArchive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveFolder <2> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrArchiveFolder
   ' =====================================================================================
   PROPERTY SET ArchiveFolder <2> ( _                   ' VTable offset = 40
     BYVAL pbstrArchiveFolder AS WSTRING _              ' __in BSTR pbstrArchiveFolder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeQuotaWarning <3> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSizeQuotaWarning
   ' =====================================================================================
   PROPERTY SET SizeQuotaWarning <3> ( _                ' VTable offset = 48
     BYVAL pbSizeQuotaWarning AS INTEGER _              ' __in VARIANT_BOOL pbSizeQuotaWarning
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighQuotaWaterMark <4> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plHighQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET HighQuotaWaterMark <4> ( _              ' VTable offset = 56
     BYVAL plHighQuotaWaterMark AS LONG _               ' __in long plHighQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LowQuotaWaterMark <5> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plLowQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET LowQuotaWaterMark <5> ( _               ' VTable offset = 64
     BYVAL plLowQuotaWaterMark AS LONG _                ' __in long plLowQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AgeLimit <6> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plAgeLimit
   ' =====================================================================================
   PROPERTY SET AgeLimit <6> ( _                        ' VTable offset = 72
     BYVAL plAgeLimit AS LONG _                         ' __in long plAgeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeLow <7> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plSizeLow
   ' =====================================================================================
   PROPERTY GET SizeHigh <8> ( _                        ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plSizeHigh
   ' =====================================================================================
   METHOD Refresh <9> ( _                               ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <10> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessages <11> ( _                          ' VTable offset = 92
     OPTIONAL BYVAL lPrefetchSize AS LONG _             ' __in_opt long lPrefetchSize [default value = 100]
   ) AS IFaxIncomingMessageIterator                     ' __retval_out IFaxIncomingMessageIterator **pFaxIncomingMessageIterator
   ' =====================================================================================
   METHOD GetMessage <12> ( _                           ' VTable offset = 96
     BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
   ) AS IFaxIncomingMessage                             ' __retval_out IFaxIncomingMessage **pFaxIncomingMessage
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingArchive_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingMessageIterator
' IID = {FD73ECC4-6F06-4F52-82A8-F7BA06AE3108}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingMessageIterator_INTERFACE_DEFINED)
    %IFaxIncomingMessageIterator_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingMessageIterator $IID_IFaxIncomingMessageIterator

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Message <1> ( _                         ' VTable offset = 28
   ) AS IFaxIncomingMessage                             ' __retval_out IFaxIncomingMessage **pFaxIncomingMessage
   ' =====================================================================================
   PROPERTY GET PrefetchSize <2> ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPrefetchSize
   ' =====================================================================================
   PROPERTY SET PrefetchSize <2> ( _                    ' VTable offset = 36
     BYVAL plPrefetchSize AS LONG _                     ' __in long plPrefetchSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AtEOF <3> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEOF
   ' =====================================================================================
   METHOD MoveFirst <4> ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <5> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingMessageIterator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingMessage
' IID = {7CAB88FA-2EF9-4851-B2F3-1D148FED8447}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingMessage_INTERFACE_DEFINED)
    %IFaxIncomingMessage_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingMessage $IID_IFaxIncomingMessage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET Pages <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <3> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET DeviceName <4> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET Retries <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET TransmissionStart <6> ( _               ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <7> ( _                 ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <8> ( _                            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <9> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET CallerId <10> ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCallerId
   ' =====================================================================================
   PROPERTY GET RoutingInformation <11> ( _             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRoutingInformation
   ' =====================================================================================
   METHOD CopyTiff <12> ( _                             ' VTable offset = 72
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <13> ( _                               ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingMessage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingArchive
' IID = {C9C28F40-8D80-4E53-810F-9A79919B49FD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingArchive_INTERFACE_DEFINED)
    %IFaxOutgoingArchive_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingArchive $IID_IFaxOutgoingArchive

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UseArchive <1> ( _                      ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseArchive
   ' =====================================================================================
   PROPERTY SET UseArchive <1> ( _                      ' VTable offset = 32
     BYVAL pbUseArchive AS INTEGER _                    ' __in VARIANT_BOOL pbUseArchive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveFolder <2> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrArchiveFolder
   ' =====================================================================================
   PROPERTY SET ArchiveFolder <2> ( _                   ' VTable offset = 40
     BYVAL pbstrArchiveFolder AS WSTRING _              ' __in BSTR pbstrArchiveFolder
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeQuotaWarning <3> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSizeQuotaWarning
   ' =====================================================================================
   PROPERTY SET SizeQuotaWarning <3> ( _                ' VTable offset = 48
     BYVAL pbSizeQuotaWarning AS INTEGER _              ' __in VARIANT_BOOL pbSizeQuotaWarning
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighQuotaWaterMark <4> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plHighQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET HighQuotaWaterMark <4> ( _              ' VTable offset = 56
     BYVAL plHighQuotaWaterMark AS LONG _               ' __in long plHighQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LowQuotaWaterMark <5> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plLowQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET LowQuotaWaterMark <5> ( _               ' VTable offset = 64
     BYVAL plLowQuotaWaterMark AS LONG _                ' __in long plLowQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AgeLimit <6> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plAgeLimit
   ' =====================================================================================
   PROPERTY SET AgeLimit <6> ( _                        ' VTable offset = 72
     BYVAL plAgeLimit AS LONG _                         ' __in long plAgeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeLow <7> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plSizeLow
   ' =====================================================================================
   PROPERTY GET SizeHigh <8> ( _                        ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plSizeHigh
   ' =====================================================================================
   METHOD Refresh <9> ( _                               ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <10> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessages <11> ( _                          ' VTable offset = 92
     OPTIONAL BYVAL lPrefetchSize AS LONG _             ' __in_opt long lPrefetchSize [default value = 100]
   ) AS IFaxOutgoingMessageIterator                     ' __retval_out IFaxOutgoingMessageIterator **pFaxOutgoingMessageIterator
   ' =====================================================================================
   METHOD GetMessage <12> ( _                           ' VTable offset = 96
     BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
   ) AS IFaxOutgoingMessage                             ' __retval_out IFaxOutgoingMessage **pFaxOutgoingMessage
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingArchive_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingMessageIterator
' IID = {F5EC5D4F-B840-432F-9980-112FE42A9B7A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingMessageIterator_INTERFACE_DEFINED)
    %IFaxOutgoingMessageIterator_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingMessageIterator $IID_IFaxOutgoingMessageIterator

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Message <1> ( _                         ' VTable offset = 28
   ) AS IFaxOutgoingMessage                             ' __retval_out IFaxOutgoingMessage **pFaxOutgoingMessage
   ' =====================================================================================
   PROPERTY GET AtEOF <2> ( _                           ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEOF
   ' =====================================================================================
   PROPERTY GET PrefetchSize <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plPrefetchSize
   ' =====================================================================================
   PROPERTY SET PrefetchSize <3> ( _                    ' VTable offset = 40
     BYVAL plPrefetchSize AS LONG _                     ' __in long plPrefetchSize
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <4> ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <5> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingMessageIterator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingMessage
' IID = {F0EA35DE-CAA5-4A7C-82C7-2B60BA5F2BE2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingMessage_INTERFACE_DEFINED)
    %IFaxOutgoingMessage_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingMessage $IID_IFaxOutgoingMessage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SubmissionId <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubmissionId
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET Subject <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY GET DocumentName <4> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY GET Retries <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET Pages <6> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <7> ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET OriginalScheduledTime <8> ( _           ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pdateOriginalScheduledTime
   ' =====================================================================================
   PROPERTY GET SubmissionTime <9> ( _                  ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSubmissionTime
   ' =====================================================================================
   PROPERTY GET Priority <10> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_PRIORITY_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY GET Sender <11> ( _                         ' VTable offset = 68
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipient <12> ( _                      ' VTable offset = 72
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   PROPERTY GET DeviceName <13> ( _                     ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET TransmissionStart <14> ( _              ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <15> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <16> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <17> ( _                           ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   METHOD CopyTiff <18> ( _                             ' VTable offset = 96
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <19> ( _                               ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingMessage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxLoggingOptions
' IID = {34E64FB9-6B31-4D32-8B27-D286C0C33606}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxLoggingOptions_INTERFACE_DEFINED)
    %IFaxLoggingOptions_INTERFACE_DEFINED = 1

INTERFACE IFaxLoggingOptions $IID_IFaxLoggingOptions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventLogging <1> ( _                    ' VTable offset = 28
   ) AS IFaxEventLogging                                ' __retval_out IFaxEventLogging **pFaxEventLogging
   ' =====================================================================================
   PROPERTY GET ActivityLogging <2> ( _                 ' VTable offset = 32
   ) AS IFaxActivityLogging                             ' __retval_out IFaxActivityLogging **pFaxActivityLogging
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxLoggingOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxEventLogging
' IID = {0880D965-20E8-42E4-8E17-944F192CAAD4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxEventLogging_INTERFACE_DEFINED)
    %IFaxEventLogging_INTERFACE_DEFINED = 1

' enum FAX_GROUP_STATUS_ENUM
%fgsALL_DEV_VALID      = 0
%fgsEMPTY              = %fgsALL_DEV_VALID + 1
%fgsALL_DEV_NOT_VALID  = %fgsEMPTY + 1
%fgsSOME_DEV_NOT_VALID = %fgsALL_DEV_NOT_VALID + 1

INTERFACE IFaxEventLogging $IID_IFaxEventLogging

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET InitEventsLevel <1> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out FAX_LOG_LEVEL_ENUM *pInitEventLevel
   ' =====================================================================================
   PROPERTY SET InitEventsLevel <1> ( _                 ' VTable offset = 32
     BYVAL pInitEventLevel AS LONG _                    ' __in FAX_LOG_LEVEL_ENUM pInitEventLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InboundEventsLevel <2> ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out FAX_LOG_LEVEL_ENUM *pInboundEventLevel
   ' =====================================================================================
   PROPERTY SET InboundEventsLevel <2> ( _              ' VTable offset = 40
     BYVAL pInboundEventLevel AS LONG _                 ' __in FAX_LOG_LEVEL_ENUM pInboundEventLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutboundEventsLevel <3> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out FAX_LOG_LEVEL_ENUM *pOutboundEventLevel
   ' =====================================================================================
   PROPERTY SET OutboundEventsLevel <3> ( _             ' VTable offset = 48
     BYVAL pOutboundEventLevel AS LONG _                ' __in FAX_LOG_LEVEL_ENUM pOutboundEventLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GeneralEventsLevel <4> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out FAX_LOG_LEVEL_ENUM *pGeneralEventLevel
   ' =====================================================================================
   PROPERTY SET GeneralEventsLevel <4> ( _              ' VTable offset = 56
     BYVAL pGeneralEventLevel AS LONG _                 ' __in FAX_LOG_LEVEL_ENUM pGeneralEventLevel
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <5> ( _                               ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <6> ( _                                  ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxEventLogging_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxActivityLogging
' IID = {1E29078B-5A69-497B-9592-49B7E7FADDB5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxActivityLogging_INTERFACE_DEFINED)
    %IFaxActivityLogging_INTERFACE_DEFINED = 1

INTERFACE IFaxActivityLogging $IID_IFaxActivityLogging

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LogIncoming <1> ( _                     ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbLogIncoming
   ' =====================================================================================
   PROPERTY SET LogIncoming <1> ( _                     ' VTable offset = 32
     BYVAL pbLogIncoming AS INTEGER _                   ' __in VARIANT_BOOL pbLogIncoming
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogOutgoing <2> ( _                     ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbLogOutgoing
   ' =====================================================================================
   PROPERTY SET LogOutgoing <2> ( _                     ' VTable offset = 40
     BYVAL pbLogOutgoing AS INTEGER _                   ' __in VARIANT_BOOL pbLogOutgoing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DatabasePath <3> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDatabasePath
   ' =====================================================================================
   PROPERTY SET DatabasePath <3> ( _                    ' VTable offset = 48
     BYVAL pbstrDatabasePath AS WSTRING _               ' __in BSTR pbstrDatabasePath
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <4> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <5> ( _                                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxActivityLogging_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxActivity
' IID = {4B106F97-3DF5-40F2-BC3C-44CB8115EBDF}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxActivity_INTERFACE_DEFINED)
    %IFaxActivity_INTERFACE_DEFINED = 1

INTERFACE IFaxActivity $IID_IFaxActivity

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IncomingMessages <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plIncomingMessages
   ' =====================================================================================
   PROPERTY GET RoutingMessages <2> ( _                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plRoutingMessages
   ' =====================================================================================
   PROPERTY GET OutgoingMessages <3> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plOutgoingMessages
   ' =====================================================================================
   PROPERTY GET QueuedMessages <4> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plQueuedMessages
   ' =====================================================================================
   METHOD Refresh <5> ( _                               ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxActivity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutboundRouting
' IID = {25DC05A4-9909-41BD-A95B-7E5D1DEC1D43}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutboundRouting_INTERFACE_DEFINED)
    %IFaxOutboundRouting_INTERFACE_DEFINED = 1

INTERFACE IFaxOutboundRouting $IID_IFaxOutboundRouting

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetGroups <1> ( _                             ' VTable offset = 28
   ) AS IFaxOutboundRoutingGroups                       ' __retval_out IFaxOutboundRoutingGroups **pFaxOutboundRoutingGroups
   ' =====================================================================================
   METHOD GetRules <2> ( _                              ' VTable offset = 32
   ) AS IFaxOutboundRoutingRules                        ' __retval_out IFaxOutboundRoutingRules **pFaxOutboundRoutingRules
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutboundRouting_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutboundRoutingGroups
' IID = {235CBEF7-C2DE-4BFD-B8DA-75097C82C87F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutboundRoutingGroups_INTERFACE_DEFINED)
    %IFaxOutboundRoutingGroups_INTERFACE_DEFINED = 1

INTERFACE IFaxOutboundRoutingGroups $IID_IFaxOutboundRoutingGroups

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxOutboundRoutingGroup                        ' __retval_out IFaxOutboundRoutingGroup **pFaxOutboundRoutingGroup
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IFaxOutboundRoutingGroup                        ' __retval_out IFaxOutboundRoutingGroup **pFaxOutboundRoutingGroup
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutboundRoutingGroups_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutboundRoutingGroup
' IID = {CA6289A1-7E25-4F87-9A0B-93365734962C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutboundRoutingGroup_INTERFACE_DEFINED)
    %IFaxOutboundRoutingGroup_INTERFACE_DEFINED = 1

' enum FAX_RULE_STATUS_ENUM
%frsVALID                    = 0
%frsEMPTY_GROUP              = %frsVALID + 1
%frsALL_GROUP_DEV_NOT_VALID  = %frsEMPTY_GROUP + 1
%frsSOME_GROUP_DEV_NOT_VALID = %frsALL_GROUP_DEV_NOT_VALID + 1
%frsBAD_DEVICE               = %frsSOME_GROUP_DEV_NOT_VALID + 1

INTERFACE IFaxOutboundRoutingGroup $IID_IFaxOutboundRoutingGroup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Status <2> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out FAX_GROUP_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET DeviceIds <3> ( _                       ' VTable offset = 36
   ) AS IFaxDeviceIds                                   ' __retval_out IFaxDeviceIds **pFaxDeviceIds
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutboundRoutingGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDeviceIds
' IID = {2F0F813F-4CE9-443E-8CA1-738CFAEEE149}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDeviceIds_INTERFACE_DEFINED)
    %IFaxDeviceIds_INTERFACE_DEFINED = 1

INTERFACE IFaxDeviceIds $IID_IFaxDeviceIds

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOrder <4> ( _                              ' VTable offset = 48
     BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
   , BYVAL lNewOrder AS LONG _                          ' __in long lNewOrder
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDeviceIds_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutboundRoutingRules
' IID = {DCEFA1E7-AE7D-4ED6-8521-369EDCCA5120}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutboundRoutingRules_INTERFACE_DEFINED)
    %IFaxOutboundRoutingRules_INTERFACE_DEFINED = 1

' enum FAX_ACCOUNT_EVENTS_TYPE_ENUM
%faetNONE         = 0
%faetIN_QUEUE     = &H1
%faetOUT_QUEUE    = &H2
%faetIN_ARCHIVE   = &H4
%faetOUT_ARCHIVE  = &H8
%faetFXSSVC_ENDED = &H10

INTERFACE IFaxOutboundRoutingRules $IID_IFaxOutboundRoutingRules

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IFaxOutboundRoutingRule                         ' __retval_out IFaxOutboundRoutingRule **pFaxOutboundRoutingRule
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD ItemByCountryAndArea <2> ( _                  ' VTable offset = 40
     BYVAL lCountryCode AS LONG _                       ' __in long lCountryCode
   , BYVAL lAreaCode AS LONG _                          ' __in long lAreaCode
   ) AS IFaxOutboundRoutingRule                         ' __retval_out IFaxOutboundRoutingRule **pFaxOutboundRoutingRule
   ' =====================================================================================
   METHOD RemoveByCountryAndArea <3> ( _                ' VTable offset = 44
     BYVAL lCountryCode AS LONG _                       ' __in long lCountryCode
   , BYVAL lAreaCode AS LONG _                          ' __in long lAreaCode
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 48
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <5> ( _                                   ' VTable offset = 52
     BYVAL lCountryCode AS LONG _                       ' __in long lCountryCode
   , BYVAL lAreaCode AS LONG _                          ' __in long lAreaCode
   , BYVAL bUseDevice AS INTEGER _                      ' __in VARIANT_BOOL bUseDevice
   , BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
   ) AS IFaxOutboundRoutingRule                         ' __retval_out IFaxOutboundRoutingRule **pFaxOutboundRoutingRule
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutboundRoutingRules_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutboundRoutingRule
' IID = {E1F795D5-07C2-469F-B027-ACACC23219DA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxOutboundRoutingRule_INTERFACE_DEFINED)
    %IFaxOutboundRoutingRule_INTERFACE_DEFINED = 1

INTERFACE IFaxOutboundRoutingRule $IID_IFaxOutboundRoutingRule

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CountryCode <1> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCountryCode
   ' =====================================================================================
   PROPERTY GET AreaCode <2> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plAreaCode
   ' =====================================================================================
   PROPERTY GET Status <3> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out FAX_RULE_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET UseDevice <4> ( _                       ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseDevice
   ' =====================================================================================
   PROPERTY SET UseDevice <4> ( _                       ' VTable offset = 44
     BYVAL pbUseDevice AS INTEGER _                     ' __in VARIANT_BOOL pbUseDevice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeviceId <5> ( _                        ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY SET DeviceId <5> ( _                        ' VTable offset = 52
     BYVAL plDeviceId AS LONG _                         ' __in long plDeviceId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GroupName <6> ( _                       ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGroupName
   ' =====================================================================================
   PROPERTY SET GroupName <6> ( _                       ' VTable offset = 60
     BYVAL pbstrGroupName AS WSTRING _                  ' __in BSTR pbstrGroupName
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <7> ( _                               ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <8> ( _                                  ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutboundRoutingRule_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxReceiptOptions
' IID = {378EFAEB-5FCB-4AFB-B2EE-E16E80614487}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxReceiptOptions_INTERFACE_DEFINED)
    %IFaxReceiptOptions_INTERFACE_DEFINED = 1

' enum FAX_SMTP_AUTHENTICATION_TYPE_ENUM enum
%fsatANONYMOUS = 0
%fsatBASIC     = %fsatANONYMOUS + 1
%fsatNTLM      = %fsatBASIC + 1

' enum FAX_RECEIPT_TYPE_ENUM enum
%frtNONE   = 0
%frtMAIL   = &H1
%frtMSGBOX = &H4

INTERFACE IFaxReceiptOptions $IID_IFaxReceiptOptions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AuthenticationType <1> ( _              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out FAX_SMTP_AUTHENTICATION_TYPE_ENUM *pType
   ' =====================================================================================
   PROPERTY SET AuthenticationType <1> ( _              ' VTable offset = 32
     BYVAL pType AS LONG _                              ' __in FAX_SMTP_AUTHENTICATION_TYPE_ENUM pType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPServer <2> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSMTPServer
   ' =====================================================================================
   PROPERTY SET SMTPServer <2> ( _                      ' VTable offset = 40
     BYVAL pbstrSMTPServer AS WSTRING _                 ' __in BSTR pbstrSMTPServer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPPort <3> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plSMTPPort
   ' =====================================================================================
   PROPERTY SET SMTPPort <3> ( _                        ' VTable offset = 48
     BYVAL plSMTPPort AS LONG _                         ' __in long plSMTPPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPSender <4> ( _                      ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSMTPSender
   ' =====================================================================================
   PROPERTY SET SMTPSender <4> ( _                      ' VTable offset = 56
     BYVAL pbstrSMTPSender AS WSTRING _                 ' __in BSTR pbstrSMTPSender
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPUser <5> ( _                        ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSMTPUser
   ' =====================================================================================
   PROPERTY SET SMTPUser <5> ( _                        ' VTable offset = 64
     BYVAL pbstrSMTPUser AS WSTRING _                   ' __in BSTR pbstrSMTPUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowedReceipts <6> ( _                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pAllowedReceipts
   ' =====================================================================================
   PROPERTY SET AllowedReceipts <6> ( _                 ' VTable offset = 72
     BYVAL pAllowedReceipts AS LONG _                   ' __in FAX_RECEIPT_TYPE_ENUM pAllowedReceipts
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SMTPPassword <7> ( _                    ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSMTPPassword
   ' =====================================================================================
   PROPERTY SET SMTPPassword <7> ( _                    ' VTable offset = 80
     BYVAL pbstrSMTPPassword AS WSTRING _               ' __in BSTR pbstrSMTPPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <8> ( _                               ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <9> ( _                                  ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseForInboundRouting <10> ( _           ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseForInboundRouting
   ' =====================================================================================
   PROPERTY SET UseForInboundRouting <10> ( _           ' VTable offset = 96
     BYVAL pbUseForInboundRouting AS INTEGER _          ' __in VARIANT_BOOL pbUseForInboundRouting
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxReceiptOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxSecurity
' IID = {77B508C1-09C0-47A2-91EB-FCE7FDF2690E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxSecurity_INTERFACE_DEFINED)
    %IFaxSecurity_INTERFACE_DEFINED = 1

' enum FAX_ACCESS_RIGHTS_ENUM enum
%farSUBMIT_LOW         = &H1
%farSUBMIT_NORMAL      = &H2
%farSUBMIT_HIGH        = &H4
%farQUERY_JOBS         = &H8
%farMANAGE_JOBS        = &H10
%farQUERY_CONFIG       = &H20
%farMANAGE_CONFIG      = &H40
%farQUERY_IN_ARCHIVE   = &H80
%farMANAGE_IN_ARCHIVE  = &H100
%farQUERY_OUT_ARCHIVE  = &H200
%farMANAGE_OUT_ARCHIVE = &H400

INTERFACE IFaxSecurity $IID_IFaxSecurity

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Descriptor <1> ( _                      ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvDescriptor
   ' =====================================================================================
   PROPERTY SET Descriptor <1> ( _                      ' VTable offset = 32
     BYVAL pvDescriptor AS VARIANT _                    ' __in VARIANT pvDescriptor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GrantedRights <2> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out FAX_ACCESS_RIGHTS_ENUM *pGrantedRights
   ' =====================================================================================
   METHOD Refresh <3> ( _                               ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <4> ( _                                  ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InformationType <5> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plInformationType
   ' =====================================================================================
   PROPERTY SET InformationType <5> ( _                 ' VTable offset = 52
     BYVAL plInformationType AS LONG _                  ' __in long plInformationType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxSecurity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxJobStatus
' IID = {8B86F485-FD7F-4824-886B-40C5CAA617CC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxJobStatus_INTERFACE_DEFINED)
    %IFaxJobStatus_INTERFACE_DEFINED = 1

' enum FAX_JOB_STATUS_ENUM enum
%fjsPENDING          = &H1
%fjsINPROGRESS       = &H2
%fjsFAILED           = &H8
%fjsPAUSED           = &H10
%fjsNOLINE           = &H20
%fjsRETRYING         = &H40
%fjsRETRIES_EXCEEDED = &H80
%fjsCOMPLETED        = &H100
%fjsCANCELED         = &H200
%fjsCANCELING        = &H400
%fjsROUTING          = &H800

' enum FAX_JOB_EXTENDED_STATUS_ENUM enum
%fjesNONE               = 0
%fjesDISCONNECTED       = %fjesNONE + 1
%fjesINITIALIZING       = %fjesDISCONNECTED + 1
%fjesDIALING            = %fjesINITIALIZING + 1
%fjesTRANSMITTING       = %fjesDIALING + 1
%fjesANSWERED           = %fjesTRANSMITTING + 1
%fjesRECEIVING          = %fjesANSWERED + 1
%fjesLINE_UNAVAILABLE   = %fjesRECEIVING + 1
%fjesBUSY               = %fjesLINE_UNAVAILABLE + 1
%fjesNO_ANSWER          = %fjesBUSY + 1
%fjesBAD_ADDRESS        = %fjesNO_ANSWER + 1
%fjesNO_DIAL_TONE       = %fjesBAD_ADDRESS + 1
%fjesFATAL_ERROR        = %fjesNO_DIAL_TONE + 1
%fjesCALL_DELAYED       = %fjesFATAL_ERROR + 1
%fjesCALL_BLACKLISTED   = %fjesCALL_DELAYED + 1
%fjesNOT_FAX_CALL       = %fjesCALL_BLACKLISTED + 1
%fjesPARTIALLY_RECEIVED = %fjesNOT_FAX_CALL + 1
%fjesHANDLED            = %fjesPARTIALLY_RECEIVED + 1
%fjesCALL_COMPLETED     = %fjesHANDLED + 1
%fjesCALL_ABORTED       = %fjesCALL_COMPLETED + 1

%fjesPROPRIETARY        = &H1000000

' enum FAX_JOB_OPERATIONS_ENUM
%fjoVIEW           = &H1
%fjoPAUSE          = &H2
%fjoRESUME         = &H4
%fjoRESTART        = &H8
%fjoDELETE         = &H10
%fjoRECIPIENT_INFO = &H20
%fjoSENDER_INFO    = &H40

' enum FAX_JOB_TYPE_ENUM
%fjtSEND    = 0
%fjtRECEIVE = %fjtSEND + 1
%fjtROUTING = %fjtRECEIVE + 1

INTERFACE IFaxJobStatus $IID_IFaxJobStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out FAX_JOB_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET Pages <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <3> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET CurrentPage <4> ( _                     ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCurrentPage
   ' =====================================================================================
   PROPERTY GET DeviceId <5> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY GET CSID <6> ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <7> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET ExtendedStatusCode <8> ( _              ' VTable offset = 56
   ) AS LONG                                            ' __retval_out FAX_JOB_EXTENDED_STATUS_ENUM *pExtendedStatusCode
   ' =====================================================================================
   PROPERTY GET ExtendedStatus <9> ( _                  ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtendedStatus
   ' =====================================================================================
   PROPERTY GET AvailableOperations <10> ( _            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_JOB_OPERATIONS_ENUM *pAvailableOperations
   ' =====================================================================================
   PROPERTY GET Retries <11> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET JobType <12> ( _                        ' VTable offset = 72
   ) AS LONG                                            ' __retval_out FAX_JOB_TYPE_ENUM *pJobType
   ' =====================================================================================
   PROPERTY GET ScheduledTime <13> ( _                  ' VTable offset = 76
   ) AS DOUBLE                                          ' __retval_out DATE *pdateScheduledTime
   ' =====================================================================================
   PROPERTY GET TransmissionStart <14> ( _              ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <15> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CallerId <16> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCallerId
   ' =====================================================================================
   PROPERTY GET RoutingInformation <17> ( _             ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRoutingInformation
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxJobStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _IFaxServerNotify2
' IID = {EC9C69B9-5FE7-4805-9467-82FCD96AF903}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%IFaxServerNotify2_INTERFACE_DEFINED)
'    %IFaxServerNotify2_INTERFACE_DEFINED = 1

'INTERFACE IFaxServerNotify2 $IID__IFaxServerNotify2

'   INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnIncomingJobAdded <1> ( _                    ' VTable offset = 28
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingJobRemoved <2> ( _                  ' VTable offset = 32
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingJobChanged <3> ( _                  ' VTable offset = 36
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobAdded <4> ( _                    ' VTable offset = 40
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobRemoved <5> ( _                  ' VTable offset = 44
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobChanged <6> ( _                  ' VTable offset = 48
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingMessageAdded <7> ( _                ' VTable offset = 52
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingMessageRemoved <8> ( _              ' VTable offset = 56
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingMessageAdded <9> ( _                ' VTable offset = 60
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingMessageRemoved <10> ( _             ' VTable offset = 64
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnReceiptOptionsChange <11> ( _               ' VTable offset = 68
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnActivityLoggingConfigChange <12> ( _        ' VTable offset = 72
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnSecurityConfigChange <13> ( _               ' VTable offset = 76
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnEventLoggingConfigChange <14> ( _           ' VTable offset = 80
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingQueueConfigChange <15> ( _          ' VTable offset = 84
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingArchiveConfigChange <16> ( _        ' VTable offset = 88
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingArchiveConfigChange <17> ( _        ' VTable offset = 92
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnDevicesConfigChange <18> ( _                ' VTable offset = 96
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutboundRoutingGroupsConfigChange <19> ( _  ' VTable offset = 100
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutboundRoutingRulesConfigChange <20> ( _   ' VTable offset = 104
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnServerActivityChange <21> ( _               ' VTable offset = 108
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lIncomingMessages AS LONG _                  ' __in long lIncomingMessages
'   , BYVAL lRoutingMessages AS LONG _                   ' __in long lRoutingMessages
'   , BYVAL lOutgoingMessages AS LONG _                  ' __in long lOutgoingMessages
'   , BYVAL lQueuedMessages AS LONG _                    ' __in long lQueuedMessages
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnQueuesStatusChange <22> ( _                 ' VTable offset = 112
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bOutgoingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bOutgoingQueueBlocked
'   , BYVAL bOutgoingQueuePaused AS INTEGER _            ' __in VARIANT_BOOL bOutgoingQueuePaused
'   , BYVAL bIncomingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bIncomingQueueBlocked
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnNewCall <23> ( _                            ' VTable offset = 116
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lCallId AS LONG _                            ' __in long lCallId
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bstrCallerId AS WSTRING _                    ' __in BSTR bstrCallerId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnServerShutDown <24> ( _                     ' VTable offset = 120
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnDeviceStatusChange <25> ( _                 ' VTable offset = 124
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bPoweredOff AS INTEGER _                     ' __in VARIANT_BOOL bPoweredOff
'   , BYVAL bSending AS INTEGER _                        ' __in VARIANT_BOOL bSending
'   , BYVAL bReceiving AS INTEGER _                      ' __in VARIANT_BOOL bReceiving
'   , BYVAL bRinging AS INTEGER _                        ' __in VARIANT_BOOL bRinging
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnGeneralServerConfigChanged <26> ( _         ' VTable offset = 128
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IFaxServerNotify2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxServer2
' IID = {571CED0F-5609-4F40-9176-547E3A72CA7C}
' IFaxServer2 interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFaxServer
' ########################################################################################

#IF NOT %DEF(%IFaxServer2_INTERFACE_DEFINED)
    %IFaxServer2_INTERFACE_DEFINED = 1

INTERFACE IFaxServer2 $IID_IFaxServer2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFaxServer Methods
   ' =====================================================================================
   METHOD Connect <1> ( _                               ' VTable offset = 28
     BYVAL bstrServerName AS WSTRING _                  ' __in BSTR bstrServerName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerName <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrServerName
   ' =====================================================================================
   METHOD GetDeviceProviders <3> ( _                    ' VTable offset = 36
   ) AS IFaxDeviceProviders                             ' __retval_out IFaxDeviceProviders **ppFaxDeviceProviders
   ' =====================================================================================
   METHOD GetDevices <4> ( _                            ' VTable offset = 40
   ) AS IFaxDevices                                     ' __retval_out IFaxDevices **ppFaxDevices
   ' =====================================================================================
   PROPERTY GET InboundRouting <5> ( _                  ' VTable offset = 44
   ) AS IFaxInboundRouting                              ' __retval_out IFaxInboundRouting **ppFaxInboundRouting
   ' =====================================================================================
   PROPERTY GET Folders <6> ( _                         ' VTable offset = 48
   ) AS IFaxFolders                                     ' __retval_out IFaxFolders **pFaxFolders
   ' =====================================================================================
   PROPERTY GET LoggingOptions <7> ( _                  ' VTable offset = 52
   ) AS IFaxLoggingOptions                              ' __retval_out IFaxLoggingOptions **ppFaxLoggingOptions
   ' =====================================================================================
   PROPERTY GET MajorVersion <8> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plMajorVersion
   ' =====================================================================================
   PROPERTY GET MinorVersion <9> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plMinorVersion
   ' =====================================================================================
   PROPERTY GET MajorBuild <10> ( _                     ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plMajorBuild
   ' =====================================================================================
   PROPERTY GET MinorBuild <11> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plMinorBuild
   ' =====================================================================================
   PROPERTY GET Debug <12> ( _                          ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDebug
   ' =====================================================================================
   PROPERTY GET Activity <13> ( _                       ' VTable offset = 76
   ) AS IFaxActivity                                    ' __retval_out IFaxActivity **ppFaxActivity
   ' =====================================================================================
   PROPERTY GET OutboundRouting <14> ( _                ' VTable offset = 80
   ) AS IFaxOutboundRouting                             ' __retval_out IFaxOutboundRouting **ppFaxOutboundRouting
   ' =====================================================================================
   PROPERTY GET ReceiptOptions <15> ( _                 ' VTable offset = 84
   ) AS IFaxReceiptOptions                              ' __retval_out IFaxReceiptOptions **ppFaxReceiptOptions
   ' =====================================================================================
   PROPERTY GET Security <16> ( _                       ' VTable offset = 88
   ) AS IFaxSecurity                                    ' __retval_out IFaxSecurity **ppFaxSecurity
   ' =====================================================================================
   METHOD Disconnect <17> ( _                           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD GetExtensionProperty <18> ( _                 ' VTable offset = 96
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   ) AS VARIANT                                         ' __retval_out VARIANT *pvProperty
   ' =====================================================================================
   METHOD SetExtensionProperty <19> ( _                 ' VTable offset = 100
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   , BYVAL vProperty AS VARIANT _                       ' __in VARIANT vProperty
   )                                                    ' void
   ' =====================================================================================
   METHOD ListenToServerEvents <20> ( _                 ' VTable offset = 104
     BYVAL EventTypes AS LONG _                         ' __in FAX_SERVER_EVENTS_TYPE_ENUM EventTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterDeviceProvider <21> ( _               ' VTable offset = 108
     BYVAL bstrGUID AS WSTRING _                        ' __in BSTR bstrGUID
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   , BYVAL bstrImageName AS WSTRING _                   ' __in BSTR bstrImageName
   , BYVAL TspName AS WSTRING _                         ' __in BSTR TspName
   , BYVAL lFSPIVersion AS LONG _                       ' __in long lFSPIVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterDeviceProvider <22> ( _             ' VTable offset = 112
     BYVAL bstrUniqueName AS WSTRING _                  ' __in BSTR bstrUniqueName
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterInboundRoutingExtension <23> ( _      ' VTable offset = 116
     BYVAL bstrExtensionName AS WSTRING _               ' __in BSTR bstrExtensionName
   , BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   , BYVAL bstrImageName AS WSTRING _                   ' __in BSTR bstrImageName
   , BYVAL vMethods AS VARIANT _                        ' __in VARIANT vMethods
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterInboundRoutingExtension <24> ( _    ' VTable offset = 120
     BYVAL bstrExtensionUniqueName AS WSTRING _         ' __in BSTR bstrExtensionUniqueName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegisteredEvents <25> ( _               ' VTable offset = 124
   ) AS LONG                                            ' __retval_out FAX_SERVER_EVENTS_TYPE_ENUM *pEventTypes
   ' =====================================================================================
   PROPERTY GET APIVersion <26> ( _                     ' VTable offset = 128
   ) AS LONG                                            ' __retval_out FAX_SERVER_APIVERSION_ENUM *pAPIVersion
   ' =====================================================================================

   ' =====================================================================================
   ' IFaxServer2 Methods
   ' =====================================================================================
   PROPERTY GET Configuration <27> ( _                  ' VTable offset = 132
   ) AS IFaxConfiguration                               ' __retval_out IFaxConfiguration **ppFaxConfiguration
   ' =====================================================================================
   PROPERTY GET CurrentAccount <28> ( _                 ' VTable offset = 136
   ) AS IFaxAccount                                     ' __retval_out IFaxAccount **ppCurrentAccount
   ' =====================================================================================
   PROPERTY GET FaxAccountSet <29> ( _                  ' VTable offset = 140
   ) AS IFaxAccountSet                                  ' __retval_out IFaxAccountSet **ppFaxAccountSet
   ' =====================================================================================
   PROPERTY GET Security2 <30> ( _                      ' VTable offset = 144
   ) AS IFaxSecurity2                                   ' __retval_out IFaxSecurity2 **ppFaxSecurity2
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxServer2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxConfiguration
' IID = {10F4D0F7-0994-4543-AB6E-506949128C40}
' IFaxConfiguration interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxConfiguration_INTERFACE_DEFINED)
    %IFaxConfiguration_INTERFACE_DEFINED = 1

INTERFACE IFaxConfiguration $IID_IFaxConfiguration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UseArchive <1> ( _                      ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseArchive
   ' =====================================================================================
   PROPERTY SET UseArchive <1> ( _                      ' VTable offset = 32
     BYVAL pbUseArchive AS INTEGER _                    ' __in VARIANT_BOOL pbUseArchive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveLocation <2> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrArchiveLocation
   ' =====================================================================================
   PROPERTY SET ArchiveLocation <2> ( _                 ' VTable offset = 40
     BYVAL pbstrArchiveLocation AS WSTRING _            ' __in BSTR pbstrArchiveLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SizeQuotaWarning <3> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSizeQuotaWarning
   ' =====================================================================================
   PROPERTY SET SizeQuotaWarning <3> ( _                ' VTable offset = 48
     BYVAL pbSizeQuotaWarning AS INTEGER _              ' __in VARIANT_BOOL pbSizeQuotaWarning
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighQuotaWaterMark <4> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plHighQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET HighQuotaWaterMark <4> ( _              ' VTable offset = 56
     BYVAL plHighQuotaWaterMark AS LONG _               ' __in long plHighQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LowQuotaWaterMark <5> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plLowQuotaWaterMark
   ' =====================================================================================
   PROPERTY SET LowQuotaWaterMark <5> ( _               ' VTable offset = 64
     BYVAL plLowQuotaWaterMark AS LONG _                ' __in long plLowQuotaWaterMark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveAgeLimit <6> ( _                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plArchiveAgeLimit
   ' =====================================================================================
   PROPERTY SET ArchiveAgeLimit <6> ( _                 ' VTable offset = 72
     BYVAL plArchiveAgeLimit AS LONG _                  ' __in long plArchiveAgeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveSizeLow <7> ( _                  ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plSizeLow
   ' =====================================================================================
   PROPERTY GET ArchiveSizeHigh <8> ( _                 ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plSizeHigh
   ' =====================================================================================
   PROPERTY GET OutgoingQueueBlocked <9> ( _            ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbOutgoingBlocked
   ' =====================================================================================
   PROPERTY SET OutgoingQueueBlocked <9> ( _            ' VTable offset = 88
     BYVAL pbOutgoingBlocked AS INTEGER _               ' __in VARIANT_BOOL pbOutgoingBlocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutgoingQueuePaused <10> ( _            ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbOutgoingPaused
   ' =====================================================================================
   PROPERTY SET OutgoingQueuePaused <10> ( _            ' VTable offset = 96
     BYVAL pbOutgoingPaused AS INTEGER _                ' __in VARIANT_BOOL pbOutgoingPaused
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowPersonalCoverPages <11> ( _        ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowPersonalCoverPages
   ' =====================================================================================
   PROPERTY SET AllowPersonalCoverPages <11> ( _        ' VTable offset = 104
     BYVAL pbAllowPersonalCoverPages AS INTEGER _       ' __in VARIANT_BOOL pbAllowPersonalCoverPages
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseDeviceTSID <12> ( _                  ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseDeviceTSID
   ' =====================================================================================
   PROPERTY SET UseDeviceTSID <12> ( _                  ' VTable offset = 112
     BYVAL pbUseDeviceTSID AS INTEGER _                 ' __in VARIANT_BOOL pbUseDeviceTSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Retries <13> ( _                        ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY SET Retries <13> ( _                        ' VTable offset = 120
     BYVAL plRetries AS LONG _                          ' __in long plRetries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetryDelay <14> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *plRetryDelay
   ' =====================================================================================
   PROPERTY SET RetryDelay <14> ( _                     ' VTable offset = 128
     BYVAL plRetryDelay AS LONG _                       ' __in long plRetryDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateStart <15> ( _              ' VTable offset = 132
   ) AS DOUBLE                                          ' __retval_out DATE *pdateDiscountRateStart
   ' =====================================================================================
   PROPERTY SET DiscountRateStart <15> ( _              ' VTable offset = 136
     BYVAL pdateDiscountRateStart AS DOUBLE _           ' __in DATE pdateDiscountRateStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateEnd <16> ( _                ' VTable offset = 140
   ) AS DOUBLE                                          ' __retval_out DATE *pdateDiscountRateEnd
   ' =====================================================================================
   PROPERTY SET DiscountRateEnd <16> ( _                ' VTable offset = 144
     BYVAL pdateDiscountRateEnd AS DOUBLE _             ' __in DATE pdateDiscountRateEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutgoingQueueAgeLimit <17> ( _          ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *plOutgoingQueueAgeLimit
   ' =====================================================================================
   PROPERTY SET OutgoingQueueAgeLimit <17> ( _          ' VTable offset = 152
     BYVAL plOutgoingQueueAgeLimit AS LONG _            ' __in long plOutgoingQueueAgeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Branding <18> ( _                       ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbBranding
   ' =====================================================================================
   PROPERTY SET Branding <18> ( _                       ' VTable offset = 160
     BYVAL pbBranding AS INTEGER _                      ' __in VARIANT_BOOL pbBranding
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IncomingQueueBlocked <19> ( _           ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIncomingBlocked
   ' =====================================================================================
   PROPERTY SET IncomingQueueBlocked <19> ( _           ' VTable offset = 168
     BYVAL pbIncomingBlocked AS INTEGER _               ' __in VARIANT_BOOL pbIncomingBlocked
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoCreateAccountOnConnect <20> ( _     ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAutoCreateAccountOnConnect
   ' =====================================================================================
   PROPERTY SET AutoCreateAccountOnConnect <20> ( _     ' VTable offset = 176
     BYVAL pbAutoCreateAccountOnConnect AS INTEGER _    ' __in VARIANT_BOOL pbAutoCreateAccountOnConnect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IncomingFaxesArePublic <21> ( _         ' VTable offset = 180
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIncomingFaxesArePublic
   ' =====================================================================================
   PROPERTY SET IncomingFaxesArePublic <21> ( _         ' VTable offset = 184
     BYVAL pbIncomingFaxesArePublic AS INTEGER _        ' __in VARIANT_BOOL pbIncomingFaxesArePublic
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <22> ( _                              ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <23> ( _                                 ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxConfiguration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccount
' IID = {68535B33-5DC4-4086-BE26-B76F9B711006}
' IFaxAccount interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccount_INTERFACE_DEFINED)
    %IFaxAccount_INTERFACE_DEFINED = 1

' enum FAX_ACCESS_RIGHTS_ENUM_2
%far2SUBMIT_LOW            = &H1
%far2SUBMIT_NORMAL         = &H2
%far2SUBMIT_HIGH           = &H4
%far2QUERY_OUT_JOBS        = &H8
%far2MANAGE_OUT_JOBS       = &H10
%far2QUERY_CONFIG          = &H20
%far2MANAGE_CONFIG         = &H40
%far2QUERY_ARCHIVES        = &H80
%far2MANAGE_ARCHIVES       = &H100
%far2MANAGE_RECEIVE_FOLDER = &H200

INTERFACE IFaxAccount $IID_IFaxAccount

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AccountName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAccountName
   ' =====================================================================================
   PROPERTY GET Folders <2> ( _                         ' VTable offset = 32
   ) AS IFaxAccountFolders                              ' __retval_out IFaxAccountFolders **ppFolders
   ' =====================================================================================
   METHOD ListenToAccountEvents <3> ( _                 ' VTable offset = 36
     BYVAL EventTypes AS LONG _                         ' __in FAX_ACCOUNT_EVENTS_TYPE_ENUM EventTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegisteredEvents <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out FAX_ACCOUNT_EVENTS_TYPE_ENUM *pRegisteredEvents
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccount_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountFolders
' IID = {6463F89D-23D8-46A9-8F86-C47B77CA7926}
' IFaxAccountFolders interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountFolders_INTERFACE_DEFINED)
    %IFaxAccountFolders_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountFolders $IID_IFaxAccountFolders

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET OutgoingQueue <1> ( _                   ' VTable offset = 28
   ) AS IFaxAccountOutgoingQueue                        ' __retval_out IFaxAccountOutgoingQueue **pFaxOutgoingQueue
   ' =====================================================================================
   PROPERTY GET IncomingQueue <2> ( _                   ' VTable offset = 32
   ) AS IFaxAccountIncomingQueue                        ' __retval_out IFaxAccountIncomingQueue **pFaxIncomingQueue
   ' =====================================================================================
   PROPERTY GET IncomingArchive <3> ( _                 ' VTable offset = 36
   ) AS IFaxAccountIncomingArchive                      ' __retval_out IFaxAccountIncomingArchive **pFaxIncomingArchive
   ' =====================================================================================
   PROPERTY GET OutgoingArchive <4> ( _                 ' VTable offset = 40
   ) AS IFaxAccountOutgoingArchive                      ' __retval_out IFaxAccountOutgoingArchive **pFaxOutgoingArchive
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountFolders_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountOutgoingQueue
' IID = {0F1424E9-F22D-4553-B7A5-0D24BD0D7E46}
' IFaxAccountOutgoingQueue interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountOutgoingQueue_INTERFACE_DEFINED)
    %IFaxAccountOutgoingQueue_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountOutgoingQueue $IID_IFaxAccountOutgoingQueue

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetJobs <1> ( _                               ' VTable offset = 28
   ) AS IFaxOutgoingJobs                                ' __retval_out IFaxOutgoingJobs **pFaxOutgoingJobs
   ' =====================================================================================
   METHOD GetJob <2> ( _                                ' VTable offset = 32
     BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
   ) AS IFaxOutgoingJob                                 ' __retval_out IFaxOutgoingJob **pFaxOutgoingJob
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountOutgoingQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountIncomingQueue
' IID = {DD142D92-0186-4A95-A090-CBC3EADBA6B4}
' IFaxAccountIncomingQueue interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountIncomingQueue_INTERFACE_DEFINED)
    %IFaxAccountIncomingQueue_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountIncomingQueue $IID_IFaxAccountIncomingQueue

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetJobs <1> ( _                               ' VTable offset = 28
   ) AS IFaxIncomingJobs                                ' __retval_out IFaxIncomingJobs **pFaxIncomingJobs
   ' =====================================================================================
   METHOD GetJob <2> ( _                                ' VTable offset = 32
     BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
   ) AS IFaxIncomingJob                                 ' __retval_out IFaxIncomingJob **pFaxIncomingJob
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountIncomingQueue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountIncomingArchive
' IID = {A8A5B6EF-E0D6-4AEE-955C-91625BEC9DB4}
' IFaxAccountIncomingArchive interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountIncomingArchive_INTERFACE_DEFINED)
    %IFaxAccountIncomingArchive_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountIncomingArchive $IID_IFaxAccountIncomingArchive

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SizeLow <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plSizeLow
   ' =====================================================================================
   PROPERTY GET SizeHigh <2> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plSizeHigh
   ' =====================================================================================
   METHOD Refresh <3> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessages <4> ( _                           ' VTable offset = 40
     OPTIONAL BYVAL lPrefetchSize AS LONG _             ' __in_opt long lPrefetchSize [default value = 100]
   ) AS IFaxIncomingMessageIterator                     ' __retval_out IFaxIncomingMessageIterator **pFaxIncomingMessageIterator
   ' =====================================================================================
   METHOD GetMessage <5> ( _                            ' VTable offset = 44
     BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
   ) AS IFaxIncomingMessage                             ' __retval_out IFaxIncomingMessage **pFaxIncomingMessage
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountIncomingArchive_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountOutgoingArchive
' IID = {5463076D-EC14-491F-926E-B3CEDA5E5662}
' IFaxAccountOutgoingArchive interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountOutgoingArchive_INTERFACE_DEFINED)
    %IFaxAccountOutgoingArchive_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountOutgoingArchive $IID_IFaxAccountOutgoingArchive

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SizeLow <1> ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plSizeLow
   ' =====================================================================================
   PROPERTY GET SizeHigh <2> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plSizeHigh
   ' =====================================================================================
   METHOD Refresh <3> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMessages <4> ( _                           ' VTable offset = 40
     OPTIONAL BYVAL lPrefetchSize AS LONG _             ' __in_opt long lPrefetchSize [default value = 100]
   ) AS IFaxOutgoingMessageIterator                     ' __retval_out IFaxOutgoingMessageIterator **pFaxOutgoingMessageIterator
   ' =====================================================================================
   METHOD GetMessage <5> ( _                            ' VTable offset = 44
     BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
   ) AS IFaxOutgoingMessage                             ' __retval_out IFaxOutgoingMessage **pFaxOutgoingMessage
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountOutgoingArchive_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccountSet
' IID = {7428FBAE-841E-47B8-86F4-2288946DCA1B}
' IFaxAccountSet interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccountSet_INTERFACE_DEFINED)
    %IFaxAccountSet_INTERFACE_DEFINED = 1

INTERFACE IFaxAccountSet $IID_IFaxAccountSet

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetAccounts <1> ( _                           ' VTable offset = 28
   ) AS IFaxAccounts                                    ' __retval_out IFaxAccounts **ppFaxAccounts
   ' =====================================================================================
   METHOD GetAccount <2> ( _                            ' VTable offset = 32
     BYVAL bstrAccountName AS WSTRING _                 ' __in BSTR bstrAccountName
   ) AS IFaxAccount                                     ' __retval_out IFaxAccount **pFaxAccount
   ' =====================================================================================
   METHOD AddAccount <3> ( _                            ' VTable offset = 36
     BYVAL bstrAccountName AS WSTRING _                 ' __in BSTR bstrAccountName
   ) AS IFaxAccount                                     ' __retval_out IFaxAccount **pFaxAccount
   ' =====================================================================================
   METHOD RemoveAccount <4> ( _                         ' VTable offset = 40
     BYVAL bstrAccountName AS WSTRING _                 ' __in BSTR bstrAccountName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccountSet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxAccounts
' IID = {93EA8162-8BE7-42D1-AE7B-EC74E2D989DA}
' IFaxAccounts interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxAccounts_INTERFACE_DEFINED)
    %IFaxAccounts_INTERFACE_DEFINED = 1

INTERFACE IFaxAccounts $IID_IFaxAccounts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   ) AS IFaxAccount                                     ' __retval_out IFaxAccount **pFaxAccount
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxAccounts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxSecurity2
' IID = {17D851F4-D09B-48FC-99C9-8F24C4DB9AB1}
' IFaxSecurity2 interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxSecurity2_INTERFACE_DEFINED)
    %IFaxSecurity2_INTERFACE_DEFINED = 1

INTERFACE IFaxSecurity2 $IID_IFaxSecurity2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Descriptor <1> ( _                      ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvDescriptor
   ' =====================================================================================
   PROPERTY SET Descriptor <1> ( _                      ' VTable offset = 32
     BYVAL pvDescriptor AS VARIANT _                    ' __in VARIANT pvDescriptor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GrantedRights <2> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out FAX_ACCESS_RIGHTS_ENUM_2 *pGrantedRights
   ' =====================================================================================
   METHOD Refresh <3> ( _                               ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <4> ( _                                  ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InformationType <5> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plInformationType
   ' =====================================================================================
   PROPERTY SET InformationType <5> ( _                 ' VTable offset = 52
     BYVAL plInformationType AS LONG _                  ' __in long plInformationType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxSecurity2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _IFaxAccountNotify
' IID = {B9B3BC81-AC1B-46F3-B39D-0ADC30E1B788}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

'#IF NOT %DEF(%IFaxAccountNotify_INTERFACE_DEFINED)
'    %IFaxAccountNotify_INTERFACE_DEFINED = 1

'INTERFACE IFaxAccountNotify $IID__IFaxAccountNotify

'   INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnIncomingJobAdded <1> ( _                    ' VTable offset = 28
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingJobRemoved <2> ( _                  ' VTable offset = 32
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingJobChanged <3> ( _                  ' VTable offset = 36
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobAdded <4> ( _                    ' VTable offset = 40
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobRemoved <5> ( _                  ' VTable offset = 44
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingJobChanged <6> ( _                  ' VTable offset = 48
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingMessageAdded <7> ( _                ' VTable offset = 52
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   , BYVAL fAddedToReceiveFolder AS INTEGER _           ' __in VARIANT_BOOL fAddedToReceiveFolder
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnIncomingMessageRemoved <8> ( _              ' VTable offset = 56
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   , BYVAL INTEGER _                                    ' __in VARIANT_BOOL fRemovedFromReceiveFolder
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingMessageAdded <9> ( _                ' VTable offset = 60
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnOutgoingMessageRemoved <10> ( _             ' VTable offset = 64
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD OnServerShutDown <11> ( _                     ' VTable offset = 68
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IFaxAccountNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDocument2
' IID = {E1347661-F9EF-4D6D-B4A5-C0A068B65CFF}
' IFaxDocument2 interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IFaxDocument
' ########################################################################################

#IF NOT %DEF(%IFaxDocument2_INTERFACE_DEFINED)
    %IFaxDocument2_INTERFACE_DEFINED = 1

INTERFACE IFaxDocument2 $IID_IFaxDocument2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFaxDocument Methods
   ' =====================================================================================
   PROPERTY GET Body <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBody
   ' =====================================================================================
   PROPERTY SET Body <1> ( _                            ' VTable offset = 32
     BYVAL pbstrBody AS WSTRING _                       ' __in BSTR pbstrBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sender <2> ( _                          ' VTable offset = 36
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipients <3> ( _                      ' VTable offset = 40
   ) AS IFaxRecipients                                  ' __retval_out IFaxRecipients **ppFaxRecipients
   ' =====================================================================================
   PROPERTY GET CoverPage <4> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCoverPage
   ' =====================================================================================
   PROPERTY SET CoverPage <4> ( _                       ' VTable offset = 48
     BYVAL pbstrCoverPage AS WSTRING _                  ' __in BSTR pbstrCoverPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Subject <5> ( _                         ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY SET Subject <5> ( _                         ' VTable offset = 56
     BYVAL pbstrSubject AS WSTRING _                    ' __in BSTR pbstrSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Note <6> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNote
   ' =====================================================================================
   PROPERTY SET Note <6> ( _                            ' VTable offset = 64
     BYVAL pbstrNote AS WSTRING _                       ' __in BSTR pbstrNote
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScheduleTime <7> ( _                    ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE *pdateScheduleTime
   ' =====================================================================================
   PROPERTY SET ScheduleTime <7> ( _                    ' VTable offset = 72
     BYVAL pdateScheduleTime AS DOUBLE _                ' __in DATE pdateScheduleTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceiptAddress <8> ( _                  ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReceiptAddress
   ' =====================================================================================
   PROPERTY SET ReceiptAddress <8> ( _                  ' VTable offset = 80
     BYVAL pbstrReceiptAddress AS WSTRING _             ' __in BSTR pbstrReceiptAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocumentName <9> ( _                    ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY SET DocumentName <9> ( _                    ' VTable offset = 88
     BYVAL pbstrDocumentName AS WSTRING _               ' __in BSTR pbstrDocumentName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallHandle <10> ( _                     ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plCallHandle
   ' =====================================================================================
   PROPERTY SET CallHandle <10> ( _                     ' VTable offset = 96
     BYVAL plCallHandle AS LONG _                       ' __in long plCallHandle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CoverPageType <11> ( _                  ' VTable offset = 100
   ) AS LONG                                            ' __retval_out FAX_COVERPAGE_TYPE_ENUM *pCoverPageType
   ' =====================================================================================
   PROPERTY SET CoverPageType <11> ( _                  ' VTable offset = 104
     BYVAL pCoverPageType AS LONG _                     ' __in FAX_COVERPAGE_TYPE_ENUM pCoverPageType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScheduleType <12> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out FAX_SCHEDULE_TYPE_ENUM *pScheduleType
   ' =====================================================================================
   PROPERTY SET ScheduleType <12> ( _                   ' VTable offset = 112
     BYVAL pScheduleType AS LONG _                      ' __in FAX_SCHEDULE_TYPE_ENUM pScheduleType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceiptType <13> ( _                    ' VTable offset = 116
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pReceiptType
   ' =====================================================================================
   PROPERTY SET ReceiptType <13> ( _                    ' VTable offset = 120
     BYVAL pReceiptType AS LONG _                       ' __in FAX_RECEIPT_TYPE_ENUM pReceiptType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GroupBroadcastReceipts <14> ( _         ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseGrouping
   ' =====================================================================================
   PROPERTY SET GroupBroadcastReceipts <14> ( _         ' VTable offset = 128
     BYVAL pbUseGrouping AS INTEGER _                   ' __in VARIANT_BOOL pbUseGrouping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <15> ( _                       ' VTable offset = 132
   ) AS LONG                                            ' __retval_out FAX_PRIORITY_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY SET Priority <15> ( _                       ' VTable offset = 136
     BYVAL pPriority AS LONG _                          ' __in FAX_PRIORITY_TYPE_ENUM pPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TapiConnection <16> ( _                 ' VTable offset = 140
   ) AS IDispatch                                       ' __retval_out IDispatch **ppTapiConnection
   ' =====================================================================================
   PROPERTY SET putref_TapiConnection <16> ( _          ' VTable offset = 144
     BYVAL ppTapiConnection AS IDispatch _              ' __in IDispatch *ppTapiConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <17> ( _                               ' VTable offset = 148
     BYVAL bstrFaxServerName AS WSTRING _               ' __in BSTR bstrFaxServerName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFaxOutgoingJobIDs
   ' =====================================================================================
   METHOD ConnectedSubmit <18> ( _                      ' VTable offset = 152
     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFaxOutgoingJobIDs
   ' =====================================================================================
   PROPERTY GET AttachFaxToReceipt <19> ( _             ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAttachFax
   ' =====================================================================================
   PROPERTY SET AttachFaxToReceipt <19> ( _             ' VTable offset = 160
     BYVAL pbAttachFax AS INTEGER _                     ' __in VARIANT_BOOL pbAttachFax
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFaxDocument2 Methods
   ' =====================================================================================
   PROPERTY GET SubmissionId <20> ( _                   ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubmissionId
   ' =====================================================================================
   PROPERTY GET Bodies <21> ( _                         ' VTable offset = 168
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBodies
   ' =====================================================================================
   PROPERTY SET Bodies <21> ( _                         ' VTable offset = 172
     BYVAL pvBodies AS VARIANT _                        ' __in VARIANT pvBodies
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit2 <22> ( _                              ' VTable offset = 176
     BYVAL bstrFaxServerName AS WSTRING _               ' __in BSTR bstrFaxServerName
   , BYREF pvFaxOutgoingJobIDs AS VARIANT _             ' __out VARIANT *pvFaxOutgoingJobIDs
   ) AS LONG                                            ' __retval_out long *plErrorBodyFile
   ' =====================================================================================
   METHOD ConnectedSubmit2 <23> ( _                     ' VTable offset = 180
     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
   , BYREF pvFaxOutgoingJobIDs AS VARIANT _             ' __out VARIANT *pvFaxOutgoingJobIDs
   ) AS LONG                                            ' __retval_out long *plErrorBodyFile
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDocument2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDocument
' IID = {B207A246-09E3-4A4E-A7DC-FEA31D29458F}
' IFaxDocument interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDocument_INTERFACE_DEFINED)
    %IFaxDocument_INTERFACE_DEFINED = 1

' enum FAX_PRIORITY_TYPE_ENUM
%fptLOW    = 0
%fptNORMAL = %fptLOW + 1
%fptHIGH   = %fptNORMAL + 1

' enum FAX_COVERPAGE_TYPE_ENUM
%fcptNONE   = 0
%fcptLOCAL  = %fcptNONE + 1
%fcptSERVER = %fcptLOCAL + 1

' enum FAX_SCHEDULE_TYPE_ENUM
%fstNOW             = 0
%fstSPECIFIC_TIME   = %fstNOW + 1
%fstDISCOUNT_PERIOD = %fstSPECIFIC_TIME + 1

INTERFACE IFaxDocument $IID_IFaxDocument

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Body <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBody
   ' =====================================================================================
   PROPERTY SET Body <1> ( _                            ' VTable offset = 32
     BYVAL pbstrBody AS WSTRING _                       ' __in BSTR pbstrBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sender <2> ( _                          ' VTable offset = 36
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipients <3> ( _                      ' VTable offset = 40
   ) AS IFaxRecipients                                  ' __retval_out IFaxRecipients **ppFaxRecipients
   ' =====================================================================================
   PROPERTY GET CoverPage <4> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCoverPage
   ' =====================================================================================
   PROPERTY SET CoverPage <4> ( _                       ' VTable offset = 48
     BYVAL pbstrCoverPage AS WSTRING _                  ' __in BSTR pbstrCoverPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Subject <5> ( _                         ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY SET Subject <5> ( _                         ' VTable offset = 56
     BYVAL pbstrSubject AS WSTRING _                    ' __in BSTR pbstrSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Note <6> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNote
   ' =====================================================================================
   PROPERTY SET Note <6> ( _                            ' VTable offset = 64
     BYVAL pbstrNote AS WSTRING _                       ' __in BSTR pbstrNote
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScheduleTime <7> ( _                    ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out DATE *pdateScheduleTime
   ' =====================================================================================
   PROPERTY SET ScheduleTime <7> ( _                    ' VTable offset = 72
     BYVAL pdateScheduleTime AS DOUBLE _                ' __in DATE pdateScheduleTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceiptAddress <8> ( _                  ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReceiptAddress
   ' =====================================================================================
   PROPERTY SET ReceiptAddress <8> ( _                  ' VTable offset = 80
     BYVAL pbstrReceiptAddress AS WSTRING _             ' __in BSTR pbstrReceiptAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocumentName <9> ( _                    ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY SET DocumentName <9> ( _                    ' VTable offset = 88
     BYVAL pbstrDocumentName AS WSTRING _               ' __in BSTR pbstrDocumentName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallHandle <10> ( _                     ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plCallHandle
   ' =====================================================================================
   PROPERTY SET CallHandle <10> ( _                     ' VTable offset = 96
     BYVAL plCallHandle AS LONG _                       ' __in long plCallHandle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CoverPageType <11> ( _                  ' VTable offset = 100
   ) AS LONG                                            ' __retval_out FAX_COVERPAGE_TYPE_ENUM *pCoverPageType
   ' =====================================================================================
   PROPERTY SET CoverPageType <11> ( _                  ' VTable offset = 104
     BYVAL pCoverPageType AS LONG _                     ' __in FAX_COVERPAGE_TYPE_ENUM pCoverPageType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScheduleType <12> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out FAX_SCHEDULE_TYPE_ENUM *pScheduleType
   ' =====================================================================================
   PROPERTY SET ScheduleType <12> ( _                   ' VTable offset = 112
     BYVAL pScheduleType AS LONG _                      ' __in FAX_SCHEDULE_TYPE_ENUM pScheduleType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceiptType <13> ( _                    ' VTable offset = 116
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pReceiptType
   ' =====================================================================================
   PROPERTY SET ReceiptType <13> ( _                    ' VTable offset = 120
     BYVAL pReceiptType AS LONG _                       ' __in FAX_RECEIPT_TYPE_ENUM pReceiptType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GroupBroadcastReceipts <14> ( _         ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUseGrouping
   ' =====================================================================================
   PROPERTY SET GroupBroadcastReceipts <14> ( _         ' VTable offset = 128
     BYVAL pbUseGrouping AS INTEGER _                   ' __in VARIANT_BOOL pbUseGrouping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <15> ( _                       ' VTable offset = 132
   ) AS LONG                                            ' __retval_out FAX_PRIORITY_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY SET Priority <15> ( _                       ' VTable offset = 136
     BYVAL pPriority AS LONG _                          ' __in FAX_PRIORITY_TYPE_ENUM pPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TapiConnection <16> ( _                 ' VTable offset = 140
   ) AS IDispatch                                       ' __retval_out IDispatch **ppTapiConnection
   ' =====================================================================================
   PROPERTY SET putref_TapiConnection <16> ( _          ' VTable offset = 144
     BYVAL ppTapiConnection AS IDispatch _              ' __in IDispatch *ppTapiConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD Submit <17> ( _                               ' VTable offset = 148
     BYVAL bstrFaxServerName AS WSTRING _               ' __in BSTR bstrFaxServerName
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFaxOutgoingJobIDs
   ' =====================================================================================
   METHOD ConnectedSubmit <18> ( _                      ' VTable offset = 152
     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
   ) AS VARIANT                                         ' __retval_out VARIANT *pvFaxOutgoingJobIDs
   ' =====================================================================================
   PROPERTY GET AttachFaxToReceipt <19> ( _             ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAttachFax
   ' =====================================================================================
   PROPERTY SET AttachFaxToReceipt <19> ( _             ' VTable offset = 160
     BYVAL pbAttachFax AS INTEGER _                     ' __in VARIANT_BOOL pbAttachFax
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxRecipients
' IID = {B9C9DE5A-894E-4492-9FA3-08C627C11D5D}
' IFaxRecipients interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxRecipients_INTERFACE_DEFINED)
    %IFaxRecipients_INTERFACE_DEFINED = 1

INTERFACE IFaxRecipients $IID_IFaxRecipients

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out **IUnknown ppUnk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL LONG _                                       ' __in long lIndex
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL bstrFaxNumber AS WSTRING _                   ' __in BSTR bstrFaxNumber
   , OPTIONAL BYVAL bstrRecipientName AS WSTRING _      ' __in_opt BSTR bstrRecipientName [default value = ""]
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxRecipients_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxIncomingMessage2
' IID = {F9208503-E2BC-48F3-9EC0-E6236F9B509A}
' IFaxIncomingMessage2 interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFaxIncomingMessage
' ########################################################################################

#IF NOT %DEF(%IFaxIncomingMessage2_INTERFACE_DEFINED)
    %IFaxIncomingMessage2_INTERFACE_DEFINED = 1

INTERFACE IFaxIncomingMessage2 $IID_IFaxIncomingMessage2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFaxIncomingMessage Methods
   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET Pages <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <3> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET DeviceName <4> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET Retries <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET TransmissionStart <6> ( _               ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <7> ( _                 ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <8> ( _                            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <9> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET CallerId <10> ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCallerId
   ' =====================================================================================
   PROPERTY GET RoutingInformation <11> ( _             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRoutingInformation
   ' =====================================================================================
   METHOD CopyTiff <12> ( _                             ' VTable offset = 72
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <13> ( _                               ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFaxIncomingMessage2 Methods
   ' =====================================================================================
   PROPERTY GET Subject <14> ( _                        ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY SET Subject <14> ( _                        ' VTable offset = 84
     BYVAL pbstrSubject AS WSTRING _                    ' __in BSTR pbstrSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderName <15> ( _                     ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSenderName
   ' =====================================================================================
   PROPERTY SET SenderName <15> ( _                     ' VTable offset = 92
     BYVAL pbstrSenderName AS WSTRING _                 ' __in BSTR pbstrSenderName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderFaxNumber <16> ( _                ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSenderFaxNumber
   ' =====================================================================================
   PROPERTY SET SenderFaxNumber <16> ( _                ' VTable offset = 100
     BYVAL pbstrSenderFaxNumber AS WSTRING _            ' __in BSTR pbstrSenderFaxNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HasCoverPage <17> ( _                   ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasCoverPage
   ' =====================================================================================
   PROPERTY SET HasCoverPage <17> ( _                   ' VTable offset = 108
     BYVAL pbHasCoverPage AS INTEGER _                  ' __in VARIANT_BOOL pbHasCoverPage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recipients <18> ( _                     ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRecipients
   ' =====================================================================================
   PROPERTY SET Recipients <18> ( _                     ' VTable offset = 116
     BYVAL pbstrRecipients AS WSTRING _                 ' __in BSTR pbstrRecipients
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WasReAssigned <19> ( _                  ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbWasReAssigned
   ' =====================================================================================
   PROPERTY GET Read <20> ( _                           ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRead
   ' =====================================================================================
   PROPERTY SET Read <20> ( _                           ' VTable offset = 128
     BYVAL pbRead AS INTEGER _                          ' __in VARIANT_BOOL pbRead
   )                                                    ' void
   ' =====================================================================================
   METHOD ReAssign <21> ( _                             ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <22> ( _                                 ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <23> ( _                              ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxIncomingMessage2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingJob2
' IID = {418A8D96-59A0-4789-B176-EDF3DC8FA8F7}
' IFaxOutgoingJob2 interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFaxOutgoingJob
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingJob2_INTERFACE_DEFINED)
    %IFaxOutgoingJob2_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingJob2 $IID_IFaxOutgoingJob2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFaxOutgoingJob Methods
   ' =====================================================================================
   PROPERTY GET Subject <1> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY GET DocumentName <2> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY GET Pages <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <4> ( _                            ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET SubmissionId <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubmissionId
   ' =====================================================================================
   PROPERTY GET Id <6> ( _                              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET OriginalScheduledTime <7> ( _           ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pdateOriginalScheduledTime
   ' =====================================================================================
   PROPERTY GET SubmissionTime <8> ( _                  ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSubmissionTime
   ' =====================================================================================
   PROPERTY GET ReceiptType <9> ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pReceiptType
   ' =====================================================================================
   PROPERTY GET Priority <10> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_PRIORITY_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY GET Sender <11> ( _                         ' VTable offset = 68
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipient <12> ( _                      ' VTable offset = 72
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   PROPERTY GET CurrentPage <13> ( _                    ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plCurrentPage
   ' =====================================================================================
   PROPERTY GET DeviceId <14> ( _                       ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plDeviceId
   ' =====================================================================================
   PROPERTY GET Status <15> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out FAX_JOB_STATUS_ENUM *pStatus
   ' =====================================================================================
   PROPERTY GET ExtendedStatusCode <16> ( _             ' VTable offset = 88
   ) AS LONG                                            ' __retval_out FAX_JOB_EXTENDED_STATUS_ENUM *pExtendedStatusCode
   ' =====================================================================================
   PROPERTY GET ExtendedStatus <17> ( _                 ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrExtendedStatus
   ' =====================================================================================
   PROPERTY GET AvailableOperations <18> ( _            ' VTable offset = 96
   ) AS LONG                                            ' __retval_out FAX_JOB_OPERATIONS_ENUM *pAvailableOperations
   ' =====================================================================================
   PROPERTY GET Retries <19> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET ScheduledTime <20> ( _                  ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out DATE *pdateScheduledTime
   ' =====================================================================================
   PROPERTY GET TransmissionStart <21> ( _              ' VTable offset = 108
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <22> ( _                ' VTable offset = 112
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <23> ( _                           ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <24> ( _                           ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   PROPERTY GET GroupBroadcastReceipts <25> ( _         ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbGroupBroadcastReceipts
   ' =====================================================================================
   METHOD Pause <26> ( _                                ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <27> ( _                               ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Restart <28> ( _                              ' VTable offset = 136
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyTiff <29> ( _                             ' VTable offset = 140
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <30> ( _                              ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <31> ( _                               ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFaxOutgoingJob2 Methods
   ' =====================================================================================
   PROPERTY GET HasCoverPage <32> ( _                   ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasCoverPage
   ' =====================================================================================
   PROPERTY GET ReceiptAddress <33> ( _                 ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReceiptAddress
   ' =====================================================================================
   PROPERTY GET ScheduleType <34> ( _                   ' VTable offset = 160
   ) AS LONG                                            ' __retval_out FAX_SCHEDULE_TYPE_ENUM *pScheduleType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingJob2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxOutgoingMessage2
' IID = {B37DF687-BC88-4B46-B3BE-B458B3EA9E7F}
' IFaxOutgoingMessage2 interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFaxOutgoingMessage
' ########################################################################################

#IF NOT %DEF(%IFaxOutgoingMessage2_INTERFACE_DEFINED)
    %IFaxOutgoingMessage2_INTERFACE_DEFINED = 1

INTERFACE IFaxOutgoingMessage2 $IID_IFaxOutgoingMessage2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFaxOutgoingMessage Methods
   ' =====================================================================================
   PROPERTY GET SubmissionId <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubmissionId
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET Subject <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSubject
   ' =====================================================================================
   PROPERTY GET DocumentName <4> ( _                    ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocumentName
   ' =====================================================================================
   PROPERTY GET Retries <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plRetries
   ' =====================================================================================
   PROPERTY GET Pages <6> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plPages
   ' =====================================================================================
   PROPERTY GET Size <7> ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plSize
   ' =====================================================================================
   PROPERTY GET OriginalScheduledTime <8> ( _           ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pdateOriginalScheduledTime
   ' =====================================================================================
   PROPERTY GET SubmissionTime <9> ( _                  ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSubmissionTime
   ' =====================================================================================
   PROPERTY GET Priority <10> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out FAX_PRIORITY_TYPE_ENUM *pPriority
   ' =====================================================================================
   PROPERTY GET Sender <11> ( _                         ' VTable offset = 68
   ) AS IFaxSender                                      ' __retval_out IFaxSender **ppFaxSender
   ' =====================================================================================
   PROPERTY GET Recipient <12> ( _                      ' VTable offset = 72
   ) AS IFaxRecipient                                   ' __retval_out IFaxRecipient **ppFaxRecipient
   ' =====================================================================================
   PROPERTY GET DeviceName <13> ( _                     ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET TransmissionStart <14> ( _              ' VTable offset = 80
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionStart
   ' =====================================================================================
   PROPERTY GET TransmissionEnd <15> ( _                ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pdateTransmissionEnd
   ' =====================================================================================
   PROPERTY GET CSID <16> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCSID
   ' =====================================================================================
   PROPERTY GET TSID <17> ( _                           ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTSID
   ' =====================================================================================
   METHOD CopyTiff <18> ( _                             ' VTable offset = 96
     BYVAL bstrTiffPath AS WSTRING _                    ' __in BSTR bstrTiffPath
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <19> ( _                               ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IFaxOutgoingMessage2 Methods
   ' =====================================================================================
   PROPERTY GET HasCoverPage <20> ( _                   ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasCoverPage
   ' =====================================================================================
   PROPERTY GET ReceiptType <21> ( _                    ' VTable offset = 108
   ) AS LONG                                            ' __retval_out FAX_RECEIPT_TYPE_ENUM *pReceiptType
   ' =====================================================================================
   PROPERTY GET ReceiptAddress <22> ( _                 ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReceiptAddress
   ' =====================================================================================
   PROPERTY GET Read <23> ( _                           ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRead
   ' =====================================================================================
   PROPERTY SET Read <23> ( _                           ' VTable offset = 120
     BYVAL pbRead AS INTEGER _                          ' __in VARIANT_BOOL pbRead
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <24> ( _                                 ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <25> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxOutgoingMessage2_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CIFaxServerNotify
' Interface name = IFaxServerNotify
' IID = {2E037B27-CF8A-4ABD-B1E0-5704943BEA6F}
' _IFaxServerNotify Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CIFaxServerNotify GUID$("{226728B4-078B-4474-88DF-2E2264B0233C}") AS EVENT

'INTERFACE IFaxServerNotifyImpl GUID$("{2E037B27-CF8A-4ABD-B1E0-5704943BEA6F}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnIncomingJobAdded <1> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobRemoved <2> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobChanged <3> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobAdded <4> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobRemoved <5> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobChanged <6> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageAdded <7> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageRemoved <8> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageAdded <9> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageRemoved <10> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnReceiptOptionsChange <11> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnActivityLoggingConfigChange <12> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnSecurityConfigChange <13> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnEventLoggingConfigChange <14> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingQueueConfigChange <15> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingArchiveConfigChange <16> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingArchiveConfigChange <17> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDevicesConfigChange <18> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutboundRoutingGroupsConfigChange <19> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutboundRoutingRulesConfigChange <20> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnServerActivityChange <21> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL lIncomingMessages AS LONG _                  ' __in long lIncomingMessages
'   , BYVAL lRoutingMessages AS LONG _                   ' __in long lRoutingMessages
'   , BYVAL lOutgoingMessages AS LONG _                  ' __in long lOutgoingMessages
'   , BYVAL lQueuedMessages AS LONG _                    ' __in long lQueuedMessagess
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnQueuesStatusChange <22> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL bOutgoingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bOutgoingQueueBlocked
'   , BYVAL bOutgoingQueuePaused AS INTEGER _            ' __in VARIANT_BOOL bOutgoingQueuePaused
'   , BYVAL bIncomingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bIncomingQueueBlocked
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnNewCall <23> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL lCallId AS LONG _                            ' __in long lCallId
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bstrCallerId AS WSTRING _                    ' __in BSTR bstrCallerId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnServerShutDown <24> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDeviceStatusChange <25> ( _
'     BYVAL pFaxServer AS IFaxServer _                   ' __in IFaxServer *pFaxServer
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bPoweredOff AS INTEGER _                     ' __in VARIANT_BOOL bPoweredOff
'   , BYVAL bSending AS INTEGER _                        ' __in VARIANT_BOOL bSending
'   , BYVAL bReceiving AS INTEGER _                      ' __in VARIANT_BOOL bReceiving
'   , BYVAL bRinging AS INTEGER _                        ' __in VARIANT_BOOL bRinging
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CIFaxServerNotify2
' Interface name = IFaxServerNotify2
' IID = {616CA8D6-A77A-4062-ABFD-0E471241C7AA}
' IFaxServerNotify2 Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CIFaxServerNotify2 GUID$("{77F0EBCC-6263-4783-8FB3-2897C5B11C18}") AS EVENT

'INTERFACE IFaxServerNotify2Impl GUID$("{616CA8D6-A77A-4062-ABFD-0E471241C7AA}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnIncomingJobAdded <1> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobRemoved <2> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in bstrJobId VT_BSTR
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobChanged <3> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobAdded <4> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobRemoved <5> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobChanged <6> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus  <dispinterface>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageAdded <7> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageRemoved <8> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageAdded <9> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageRemoved <10> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnReceiptOptionsChange <11> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnActivityLoggingConfigChange <12> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnSecurityConfigChange <13> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnEventLoggingConfigChange <14> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingQueueConfigChange <15> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingArchiveConfigChange <16> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingArchiveConfigChange <17> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDevicesConfigChange <18> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutboundRoutingGroupsConfigChange <19> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutboundRoutingRulesConfigChange <20> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnServerActivityChange <21> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lIncomingMessages AS LONG _                  ' __in long lIncomingMessages
'   , BYVAL lRoutingMessages AS LONG _                   ' __in long lRoutingMessages
'   , BYVAL lOutgoingMessages AS LONG _                  ' __in long lOutgoingMessages
'   , BYVAL lQueuedMessages AS LONG _                    ' __in long lQueuedMessages
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnQueuesStatusChange <22> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL bOutgoingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bOutgoingQueueBlocked
'   , BYVAL bOutgoingQueuePaused AS INTEGER _            ' __in VARIANT_BOOL bOutgoingQueuePaused
'   , BYVAL bIncomingQueueBlocked AS INTEGER _           ' __in VARIANT_BOOL bIncomingQueueBlocked
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnNewCall <23> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lCallId AS LONG _                            ' __in long lCallId
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bstrCallerId AS WSTRING _                    ' __in BSTR bstrCallerId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnServerShutDown <24> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDeviceStatusChange <25> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   , BYVAL lDeviceId AS LONG _                          ' __in long lDeviceId
'   , BYVAL bPoweredOff AS INTEGER _                     ' __in VARIANT_BOOL bPoweredOff
'   , BYVAL bSending AS INTEGER _                        ' __in VARIANT_BOOL bSending
'   , BYVAL bReceiving AS INTEGER _                      ' __in VARIANT_BOOL bReceiving
'   , BYVAL bRinging AS INTEGER _                        ' __in VARIANT_BOOL bRinging
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnGeneralServerConfigChanged <26> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CIFaxAccountNotify
' Interface name = IFaxAccountNotify
' IID = {0B5E5BD1-B8A9-47A0-A323-EF4A293BA06A}
' IFaxAccountNotify Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CIFaxAccountNotify GUID$("{451BFB4D-26C0-494A-9C68-17FA775FE550}") AS EVENT

'INTERFACE IFaxAccountNotifyImpl GUID$("{0B5E5BD1-B8A9-47A0-A323-EF4A293BA06A}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnIncomingJobAdded <1> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobRemoved <2> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingJobChanged <3> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobAdded <4> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobRemoved <5> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingJobChanged <6> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrJobId AS WSTRING _                       ' __in BSTR bstrJobId
'   , BYVAL pJobStatus AS IFaxJobStatus _                ' __in IFaxJobStatus *pJobStatus
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageAdded <7> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   , BYVAL fAddedToReceiveFolder AS INTEGER _           ' __in VARIANT_BOOL fAddedToReceiveFolder
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnIncomingMessageRemoved <8> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   , BYVAL fRemovedFromReceiveFolder AS INTEGER _       ' __in VARIANT_BOOL fRemovedFromReceiveFolder
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageAdded <9> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnOutgoingMessageRemoved <10> ( _
'     BYVAL pFaxAccount AS IFaxAccount _                 ' __in IFaxAccount *pFaxAccount
'   , BYVAL bstrMessageId AS WSTRING _                   ' __in BSTR bstrMessageId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnServerShutDown <11> ( _
'     BYVAL pFaxServer AS IFaxServer2 _                  ' __in IFaxServer2 *pFaxServer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
