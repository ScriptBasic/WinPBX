' ########################################################################################
' Microsoft Windows
' File: tuner.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TunerLib
' Version: 1.0
' Documentation string: Microsoft Tuner 1.0 Type Library
' Path: C:\WINDOWS\system32\msvidctl.dll\2
' Library GUID: {9B085638-018E-11D3-9D8E-00C04F72D980}
' ########################################################################################

#INCLUDE THIS ONCE
%TUNER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "comcat.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "bdatypes.inc"
#include ONCE "regbag.inc"

$LIBID_TunerLib = GUID$("{9B085638-018E-11D3-9D8E-00C04F72D980}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {28AB0005-E845-4FFA-AA9B-F4665236141C}
$PROGID_BDATunerAnalogAudioComponentType1 = "BDATuner.AnalogAudioComponentType.1"
' CLSID = {49638B91-48AB-48B7-A47A-7D0E75A08EDE}
$PROGID_BDATunerAnalogLocator1 = "BDATuner.AnalogLocator.1"
' CLSID = {8A674B4C-1F63-11D3-B64C-00C04F79498E}
$PROGID_BDATunerAnalogRadioTuningSpace1 = "BDATuner.AnalogRadioTuningSpace.1"
' CLSID = {8A674B4D-1F63-11D3-B64C-00C04F79498E}
$PROGID_BDATunerAnalogTVTuningSpace1 = "BDATuner.AnalogTVTuningSpace.1"
' CLSID = {0369B4E6-45B6-11D3-B650-00C04F79498E}
$PROGID_BDATunerATSCChannelTuneRequest1 = "BDATuner.ATSCChannelTuneRequest.1"
' CLSID = {A8DCF3D5-0780-4EF4-8A83-2CFFAACB8ACE}
$PROGID_BDATunerATSCComponentType1 = "BDATuner.ATSCComponentType.1"
' CLSID = {8872FF1B-98FA-4D7A-8D93-C9F1055F85BB}
$PROGID_BDATunerATSCLocator1 = "BDATuner.ATSCLocator.1"
' CLSID = {A2E30750-6C3D-11D3-B653-00C04F79498E}
$PROGID_BDATunerATSCTuningSpace1 = "BDATuner.ATSCTuningSpace.1"
' CLSID = {F9769A06-7ACA-4E39-9CFB-97BB35F0E77E}
$PROGID_BDATunerAuxiliaryInTuningSpace1 = "BDATuner.AuxiliaryInTuningSpace.1"
' CLSID = {3A9428A7-31A4-45E9-9EFB-E055BF7BB3DB}
$PROGID_BDATunerChannelIDTuneRequest1 = "BDATuner.ChannelIDTuneRequest.1"
' CLSID = {CC829A2F-3365-463F-AF13-81DBB6F3A555}
$PROGID_BDATunerChannelIDTuningSpace1 = "BDATuner.ChannelIDTuningSpace.1"
' CLSID = {0369B4E5-45B6-11D3-B650-00C04F79498E}
$PROGID_BDATunerChannelTuneRequest1 = "BDATuner.ChannelTuneRequest.1"
' CLSID = {59DC47A8-116C-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponent1 = "BDATuner.Component.1"
' CLSID = {809B6661-94C4-49E6-B6EC-3F0F862215AA}
$PROGID_BDATunerComponentes1 = "BDATuner.Componentes.1"
' CLSID = {823535A0-0318-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponentType1 = "BDATuner.ComponentType.1"
' CLSID = {A1A2B1C4-0E3A-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponentTypes1 = "BDATuner.ComponentTypes.1"
' CLSID = {03C06416-D127-407A-AB4C-FDD279ABBE5D}
$PROGID_BDATunerDigitalCableLocator1 = "BDATuner.DigitalCableLocator.1"
' CLSID = {26EC0B63-AA90-458A-8DF4-5659F2C8A18A}
$PROGID_BDATunerDigitalCableTuneRequest1 = "BDATuner.DigitalCableTuneRequest.1"
' CLSID = {D9BB4CEE-B87A-47F1-AC92-B08D9C7813FC}
$PROGID_BDATunerDigitalCableTuningSpace1 = "BDATuner.DigitalCableTuningSpace.1"
' CLSID = {C531D9FD-9685-4028-8B68-6E1232079F1E}
$PROGID_BDATunerDVBCLocator1 = "BDATuner.DVBCLocator.1"
' CLSID = {1DF7D126-4050-47F0-A7CF-4C4CA9241333}
$PROGID_BDATunerDVBSLocator1 = "BDATuner.DVBSLocator.1"
' CLSID = {B64016F3-C9A2-4066-96F0-BD9563314726}
$PROGID_BDATunerDVBSTuningSpace1 = "BDATuner.DVBSTuningSpace.1"
' CLSID = {9CD64701-BDF3-4D14-8E03-F12983D86664}
$PROGID_BDATunerDVBTLocator1 = "BDATuner.DVBTLocator.1"
' CLSID = {EFE3FA02-45D7-4920-BE96-53FA7F35B0E6}
$PROGID_BDATunerDVBTLocator221 = "BDATuner.DVBTLocator2.1"
' CLSID = {15D6504A-5494-499C-886C-973C9E53B9F1}
$PROGID_BDATunerDVBTuneRequest1 = "BDATuner.DVBTuneRequest.1"
' CLSID = {C6B14B32-76AA-4A86-A7AC-5C79AAF58DA7}
$PROGID_BDATunerDVBTuningSpace1 = "BDATuner.DVBTuningSpace.1"
' CLSID = {6504AFED-A629-455C-A7F1-04964DEA5CC4}
$PROGID_BDATunerISDBSLocator1 = "BDATuner.ISDBSLocator.1"
' CLSID = {1BE49F30-0E1B-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerLanguageComponentType1 = "BDATuner.LanguageComponentType.1"
' CLSID = {055CB2D7-2969-45CD-914B-76890722F112}
$PROGID_BDATunerMPEG2Component1 = "BDATuner.MPEG2Component.1"
' CLSID = {418008F3-CF67-4668-9628-10DC52BE1D08}
$PROGID_BDATunerMPEG2ComponentType1 = "BDATuner.MPEG2ComponentType.1"
' CLSID = {0955AC62-BF2E-4CBA-A2B9-A63F772D46CF}
$PROGID_BDATunerMPEG2TuneRequest1 = "BDATuner.MPEG2TuneRequest.1"
' CLSID = {2C63E4EB-4CEA-41B8-919C-E947EA19A77C}
$PROGID_BDATunerMPEG2TuneRequestFactory1 = "BDATuner.MPEG2TuneRequestFactory.1"
' CLSID = {D02AAC50-027E-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerSystemTuningSpaces1 = "BDATuner.SystemTuningSpaces.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {28AB0005-E845-4FFA-AA9B-F4665236141C}
$PROGID_BDATunerAnalogAudioComponentType = "BDATuner.AnalogAudioComponentType"
' CLSID = {49638B91-48AB-48B7-A47A-7D0E75A08EDE}
$PROGID_BDATunerAnalogLocator = "BDATuner.AnalogLocator"
' CLSID = {8A674B4C-1F63-11D3-B64C-00C04F79498E}
$PROGID_BDATunerAnalogRadioTuningSpace = "BDATuner.AnalogRadioTuningSpace"
' CLSID = {8A674B4D-1F63-11D3-B64C-00C04F79498E}
$PROGID_BDATunerAnalogTVTuningSpace = "BDATuner.AnalogTVTuningSpace"
' CLSID = {0369B4E6-45B6-11D3-B650-00C04F79498E}
$PROGID_BDATunerATSCChannelTuneRequest = "BDATuner.ATSCChannelTuneRequest"
' CLSID = {A8DCF3D5-0780-4EF4-8A83-2CFFAACB8ACE}
$PROGID_BDATunerATSCComponentType = "BDATuner.ATSCComponentType"
' CLSID = {8872FF1B-98FA-4D7A-8D93-C9F1055F85BB}
$PROGID_BDATunerATSCLocator = "BDATuner.ATSCLocator"
' CLSID = {A2E30750-6C3D-11D3-B653-00C04F79498E}
$PROGID_BDATunerATSCTuningSpace = "BDATuner.ATSCTuningSpace"
' CLSID = {F9769A06-7ACA-4E39-9CFB-97BB35F0E77E}
$PROGID_BDATunerAuxiliaryInTuningSpace = "BDATuner.AuxiliaryInTuningSpace"
' CLSID = {3A9428A7-31A4-45E9-9EFB-E055BF7BB3DB}
$PROGID_BDATunerChannelIDTuneRequest = "BDATuner.ChannelIDTuneRequest"
' CLSID = {CC829A2F-3365-463F-AF13-81DBB6F3A555}
$PROGID_BDATunerChannelIDTuningSpace = "BDATuner.ChannelIDTuningSpace"
' CLSID = {0369B4E5-45B6-11D3-B650-00C04F79498E}
$PROGID_BDATunerChannelTuneRequest = "BDATuner.ChannelTuneRequest"
' CLSID = {59DC47A8-116C-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponent = "BDATuner.Component"
' CLSID = {809B6661-94C4-49E6-B6EC-3F0F862215AA}
$PROGID_BDATunerComponentes = "BDATuner.Componentes"
' CLSID = {823535A0-0318-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponentType = "BDATuner.ComponentType"
' CLSID = {A1A2B1C4-0E3A-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerComponentTypes = "BDATuner.ComponentTypes"
' CLSID = {03C06416-D127-407A-AB4C-FDD279ABBE5D}
$PROGID_BDATunerDigitalCableLocator = "BDATuner.DigitalCableLocator"
' CLSID = {26EC0B63-AA90-458A-8DF4-5659F2C8A18A}
$PROGID_BDATunerDigitalCableTuneRequest = "BDATuner.DigitalCableTuneRequest"
' CLSID = {D9BB4CEE-B87A-47F1-AC92-B08D9C7813FC}
$PROGID_BDATunerDigitalCableTuningSpace = "BDATuner.DigitalCableTuningSpace"
' CLSID = {C531D9FD-9685-4028-8B68-6E1232079F1E}
$PROGID_BDATunerDVBCLocator = "BDATuner.DVBCLocator"
' CLSID = {1DF7D126-4050-47F0-A7CF-4C4CA9241333}
$PROGID_BDATunerDVBSLocator = "BDATuner.DVBSLocator"
' CLSID = {B64016F3-C9A2-4066-96F0-BD9563314726}
$PROGID_BDATunerDVBSTuningSpace = "BDATuner.DVBSTuningSpace"
' CLSID = {9CD64701-BDF3-4D14-8E03-F12983D86664}
$PROGID_BDATunerDVBTLocator = "BDATuner.DVBTLocator"
' CLSID = {EFE3FA02-45D7-4920-BE96-53FA7F35B0E6}
$PROGID_BDATunerDVBTLocator2 = "BDATuner.DVBTLocator2"
' CLSID = {15D6504A-5494-499C-886C-973C9E53B9F1}
$PROGID_BDATunerDVBTuneRequest = "BDATuner.DVBTuneRequest"
' CLSID = {C6B14B32-76AA-4A86-A7AC-5C79AAF58DA7}
$PROGID_BDATunerDVBTuningSpace = "BDATuner.DVBTuningSpace"
' CLSID = {6504AFED-A629-455C-A7F1-04964DEA5CC4}
$PROGID_BDATunerISDBSLocator = "BDATuner.ISDBSLocator"
' CLSID = {1BE49F30-0E1B-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerLanguageComponentType = "BDATuner.LanguageComponentType"
' CLSID = {055CB2D7-2969-45CD-914B-76890722F112}
$PROGID_BDATunerMPEG2Component = "BDATuner.MPEG2Component"
' CLSID = {418008F3-CF67-4668-9628-10DC52BE1D08}
$PROGID_BDATunerMPEG2ComponentType = "BDATuner.MPEG2ComponentType"
' CLSID = {0955AC62-BF2E-4CBA-A2B9-A63F772D46CF}
$PROGID_BDATunerMPEG2TuneRequest = "BDATuner.MPEG2TuneRequest"
' CLSID = {2C63E4EB-4CEA-41B8-919C-E947EA19A77C}
$PROGID_BDATunerMPEG2TuneRequestFactory = "BDATuner.MPEG2TuneRequestFactory"
' CLSID = {D02AAC50-027E-11D3-9D8E-00C04F72D980}
$PROGID_BDATunerSystemTuningSpaces = "BDATuner.SystemTuningSpaces"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_BroadcastEventService = GUID$("{0B3FFB92-0919-4934-9D5B-619C719D0202}")
$SID_BroadcastEventService = $CLSID_BroadcastEventService
$CLSID_CreatePropBagOnRegKey = GUID$("{8A674B49-1F63-11D3-B64C-00C04F79498E}")
$CLSID_DigitalLocator = GUID$("{6E50CC0D-C19B-4BF6-810B-5BD60761F5CC}")
$CLSID_ESEventFactory = GUID$("{8E8A07DA-71F8-40c1-A929-5E3A868AC2C6}")
$SID_ESEventFactory = $CLSID_ESEventFactory
$CLSID_ESEventService = GUID$("{C20447FC-EC60-475E-813F-D2B0A6DECEFE}")
$SID_ESEventService = $CLSID_ESEventService
$CLSID_Locator = GUID$("{0888C883-AC4F-4943-B516-2C38D9B34562}")
$CLSID_PersistTuneXmlUtility = GUID$("{E77026B0-B97F-4CBB-B7FB-F4F03AD69F11}")
$CLSID_TuneRequest = GUID$("{B46E0D38-AB35-4A06-A137-70576B01B39F}")
$CLSID_TunerMarshaler = GUID$("{6438570B-0C08-4A25-9504-8012BB4D50CF}")
$CLSID_TuningSpace = GUID$("{5FFDC5E6-B83A-4B55-B6E8-C69E765FE9DB}")
$CLSID_AnalogAudioComponentType = GUID$("{28AB0005-E845-4FFA-AA9B-F4665236141C}")
$CLSID_AnalogLocator = GUID$("{49638B91-48AB-48B7-A47A-7D0E75A08EDE}")
$CLSID_AnalogRadioTuningSpace = GUID$("{8A674B4C-1F63-11D3-B64C-00C04F79498E}")
$CLSID_AnalogTVTuningSpace = GUID$("{8A674B4D-1F63-11D3-B64C-00C04F79498E}")
$CLSID_ATSCChannelTuneRequest = GUID$("{0369B4E6-45B6-11D3-B650-00C04F79498E}")
$CLSID_ATSCComponentType = GUID$("{A8DCF3D5-0780-4EF4-8A83-2CFFAACB8ACE}")
$CLSID_ATSCLocator = GUID$("{8872FF1B-98FA-4D7A-8D93-C9F1055F85BB}")
$CLSID_ATSCTuningSpace = GUID$("{A2E30750-6C3D-11D3-B653-00C04F79498E}")
$CLSID_AuxInTuningSpace = GUID$("{F9769A06-7ACA-4E39-9CFB-97BB35F0E77E}")
$CLSID_ChannelIDTuningSpace = GUID$("{CC829A2F-3365-463F-AF13-81DBB6F3A555}")
$CLSID_ChannelIDTuneRequest = GUID$("{3A9428A7-31A4-45E9-9EFB-E055BF7BB3DB}")
$CLSID_ChannelTuneRequest = GUID$("{0369B4E5-45B6-11D3-B650-00C04F79498E}")
$CLSID_Component = GUID$("{59DC47A8-116C-11D3-9D8E-00C04F72D980}")
$CLSID_Components = GUID$("{809B6661-94C4-49E6-B6EC-3F0F862215AA}")
$CLSID_ComponentType = GUID$("{823535A0-0318-11D3-9D8E-00C04F72D980}")
$CLSID_ComponentTypes = GUID$("{A1A2B1C4-0E3A-11D3-9D8E-00C04F72D980}")
$CLSID_DigitalCableLocator = GUID$("{03C06416-D127-407A-AB4C-FDD279ABBE5D}")
$CLSID_DigitalCableTuneRequest = GUID$("{26EC0B63-AA90-458A-8DF4-5659F2C8A18A}")
$CLSID_DigitalCableTuningSpace = GUID$("{D9BB4CEE-B87A-47F1-AC92-B08D9C7813FC}")
$CLSID_DVBCLocator = GUID$("{C531D9FD-9685-4028-8B68-6E1232079F1E}")
$CLSID_DVBSLocator = GUID$("{1DF7D126-4050-47F0-A7CF-4C4CA9241333}")
$CLSID_DVBSTuningSpace = GUID$("{B64016F3-C9A2-4066-96F0-BD9563314726}")
$CLSID_DVBTLocator = GUID$("{9CD64701-BDF3-4D14-8E03-F12983D86664}")
$CLSID_DVBTLocator2 = GUID$("{EFE3FA02-45D7-4920-BE96-53FA7F35B0E6}")
$CLSID_DVBTuneRequest = GUID$("{15D6504A-5494-499C-886C-973C9E53B9F1}")
$CLSID_DVBTuningSpace = GUID$("{C6B14B32-76AA-4A86-A7AC-5C79AAF58DA7}")
$CLSID_ISDBSLocator = GUID$("{6504AFED-A629-455C-A7F1-04964DEA5CC4}")
$CLSID_LanguageComponentType = GUID$("{1BE49F30-0E1B-11D3-9D8E-00C04F72D980}")
$CLSID_MPEG2Component = GUID$("{055CB2D7-2969-45CD-914B-76890722F112}")
$CLSID_MPEG2ComponentType = GUID$("{418008F3-CF67-4668-9628-10DC52BE1D08}")
$CLSID_MPEG2TuneRequest = GUID$("{0955AC62-BF2E-4CBA-A2B9-A63F772D46CF}")
$CLSID_MPEG2TuneRequestFactory = GUID$("{2C63E4EB-4CEA-41B8-919C-E947EA19A77C}")
$CLSID_SystemTuningSpaces = GUID$("{D02AAC50-027E-11D3-9D8E-00C04F72D980}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAnalogAudioComponentType = GUID$("{2CFEB2A8-1787-4A24-A941-C6EAEC39C842}")
$IID_IAnalogLocator = GUID$("{34D1F26B-E339-430D-ABCE-738CB48984DC}")
$IID_IAnalogRadioTuningSpace = GUID$("{2A6E293B-2595-11D3-B64C-00C04F79498E}")
$IID_IAnalogRadioTuningSpace2 = GUID$("{39DD45DA-2DA8-46BA-8A8A-87E2B73D983A}")
$IID_IAnalogTVTuningSpace = GUID$("{2A6E293C-2595-11D3-B64C-00C04F79498E}")
$IID_IATSCChannelTuneRequest = GUID$("{0369B4E1-45B6-11D3-B650-00C04F79498E}")
$IID_IATSCComponentType = GUID$("{FC189E4D-7BD4-4125-B3B3-3A76A332CC96}")
$IID_IATSCLocator = GUID$("{BF8D986F-8C2B-4131-94D7-4D3D9FCC21EF}")
$IID_IATSCLocator2 = GUID$("{612AA885-66CF-4090-BA0A-566F5312E4CA}")
$IID_IATSCTuningSpace = GUID$("{0369B4E2-45B6-11D3-B650-00C04F79498E}")
$IID_IAuxInTuningSpace = GUID$("{E48244B8-7E17-4F76-A763-5090FF1E2F30}")
$IID_IAuxInTuningSpace2 = GUID$("{B10931ED-8BFE-4AB0-9DCE-E469C29A9729}")
$IID_IBDAComparable = GUID$("{B34505E0-2F0E-497B-80BC-D43F3B24ED7F}")
$IID_IBDACreateTuneRequestEx = GUID$("{C0A4A1D4-2B3C-491A-BA22-499FBADD4D12}")
$IID_IBroadcastEvent = GUID$("{3B21263F-26E8-489D-AAC4-924F7EFD9511}")
$IID_IChannelIDTuneRequest = GUID$("{156EFF60-86F4-4E28-89FC-109799FD57EE}")
$IID_IChannelTuneRequest = GUID$("{0369B4E0-45B6-11D3-B650-00C04F79498E}")
$IID_IComponent = GUID$("{1A5576FC-0E19-11D3-9D8E-00C04F72D980}")
$IID_IComponents = GUID$("{39A48091-FFFE-4182-A161-3FF802640E26}")
$IID_IComponentsOld = GUID$("{FCD01846-0E19-11D3-9D8E-00C04F72D980}")
$IID_IComponentType = GUID$("{6A340DC0-0311-11D3-9D8E-00C04F72D980}")
$IID_IComponentTypes = GUID$("{0DC13D4A-0313-11D3-9D8E-00C04F72D980}")
$IID_IDigitalCableLocator = GUID$("{48F66A11-171A-419A-9525-BEEECD51584C}")
$IID_IDigitalCableTuneRequest = GUID$("{BAD7753B-6B37-4810-AE57-3CE0C4A9E6CB}")
$IID_IDigitalCableTuningSpace = GUID$("{013F9F9C-B449-4EC7-A6D2-9D4F2FC70AE5}")
$IID_IDigitalLocator = GUID$("{19B595D8-839A-47F0-96DF-4F194F3C768C}")
$IID_IDVBCLocator = GUID$("{6E42F36E-1DD2-43C4-9F78-69D25AE39034}")
$IID_IDVBSLocator = GUID$("{3D7C353C-0D04-45F1-A742-F97CC1188DC8}")
$IID_IDVBSLocator2 = GUID$("{6044634A-1733-4F99-B982-5FB12AFCE4F0}")
$IID_IDVBSTuningSpace = GUID$("{CDF7BE60-D954-42FD-A972-78971958E470}")
$IID_IDVBTLocator = GUID$("{8664DA16-DDA2-42AC-926A-C18F9127C302}")
$IID_IDVBTLocator2 = GUID$("{448A2EDF-AE95-4B43-A3CC-747843C453D4}")
$IID_IDVBTuneRequest = GUID$("{0D6F567E-A636-42BB-83BA-CE4C1704AFA2}")
$IID_IDVBTuningSpace = GUID$("{ADA0B268-3B19-4E5B-ACC4-49F852BE13BA}")
$IID_IDVBTuningSpace2 = GUID$("{843188B4-CE62-43DB-966B-8145A094E040}")
$IID_IEnumComponents = GUID$("{2A6E2939-2595-11D3-B64C-00C04F79498E}")
$IID_IEnumComponentTypes = GUID$("{8A674B4A-1F63-11D3-B64C-00C04F79498E}")
$IID_IEnumTuningSpaces = GUID$("{8B8EB248-FC2B-11D2-9D8C-00C04F72D980}")
$IID_IESEvent = GUID$("{1F0E5357-AF43-44E6-8547-654C645145D2}")
$IID_IESEventFactory = GUID$("{506A09B8-7F86-4E04-AC05-3303BFE8FC49}")
$IID_IESEvents = GUID$("{ABD414BF-CFE5-4E5E-AF5B-4B4E49C5BFEB}")
$IID_IESEventService = GUID$("{ED89A619-4C06-4B2F-99EB-C7669B13047C}")
$IID_IISDBSLocator = GUID$("{C9897087-E29C-473F-9E4B-7072123DEA14}")
$IID_ILanguageComponentType = GUID$("{B874C8BA-0FA2-11D3-9D8E-00C04F72D980}")
$IID_ILocator = GUID$("{286D7F89-760C-4F89-80C4-66841D2507AA}")
$IID_IMPEG2Component = GUID$("{1493E353-1EB6-473C-802D-8E6B8EC9D2A9}")
$IID_IMPEG2ComponentType = GUID$("{2C073D84-B51C-48C9-AA9F-68971E1F6E38}")
$IID_IMPEG2TuneRequest = GUID$("{EB7D987F-8A01-42AD-B8AE-574DEEE44D1A}")
$IID_IMPEG2TuneRequestFactory = GUID$("{14E11ABD-EE37-4893-9EA1-6964DE933E39}")
$IID_IPersistTuneXmlUtility = GUID$("{990237AE-AC11-4614-BE8F-DD217A4CB4CB}")
$IID_IPersistTuneXmlUtility2 = GUID$("{992E165F-EA24-4B2F-9A1D-009D92120451}")
$IID_IRegisterTuner = GUID$("{359B3901-572C-4854-BB49-CDEF66606A25}")
$IID_ITuner = GUID$("{28C52640-018A-11D3-9D8E-00C04F72D980}")
$SID_SContentTuneRequest = $IID_ITuner
$IID_ITuneRequest = GUID$("{07DDC146-FC3D-11D2-9D8C-00C04F72D980}")
$IID_ITuningSpace = GUID$("{061C6E30-E622-11D2-9493-00C04F72D980}")
$IID_ITuningSpaceContainer = GUID$("{5B692E84-E2F1-11D2-9493-00C04F72D980}")
$IID_ITuningSpaces = GUID$("{901284E4-33FE-4B69-8D63-634A596F3756}")

$IID_IESOpenMmiEvent = GUID$("{BA4B6526-1A35-4635-8B56-3EC612746A8C}")
$IID_IESCloseMmiEvent = GUID$("{6B80E96F-55E2-45AA-B754-0C23C8E7D5C1}")
$IID_IESValueUpdatedEvent = GUID$("{8A24C46E-BB63-4664-8602-5D9C718C146D}")
$IID_IESRequestTunerEvent = GUID$("{54C7A5E8-C3BB-4F51-AF14-E0E2C0E34C6D}")
$IID_IESIsdbCasResponseEvent = GUID$("{2017CB03-DC0F-4C24-83CA-36307B2CD19F}")
$IID_IESLicenseRenewalResultEvent = GUID$("{D5A48EF5-A81B-4DF0-ACAA-5E35E7EA45D4}")
$IID_IESFileExpiryDateEvent = GUID$("{BA9EDCB6-4D36-4CFE-8C56-87A6B0CA48E1}")
$IID_IESEventServiceConfiguration = GUID$("{33B9DAAE-9309-491D-A051-BCAD2A70CD66}")
$IID_IGpnvsCommonBase = GUID$("{907E0B5C-E42D-4F04-91F0-26F401F36907}")
$IID_IPersistTuneXml = GUID$("{0754CD31-8D15-47A9-8215-D20064157244}")

' enum __MIDL___MIDL_itf_tuner_0000_0001
%DISPID_TUNER_TS_UNIQUENAME                        = 1
%DISPID_TUNER_TS_FRIENDLYNAME                      = 2
%DISPID_TUNER_TS_CLSID                             = 3
%DISPID_TUNER_TS_NETWORKTYPE                       = 4
%DISPID_TUNER_TS__NETWORKTYPE                      = 5
%DISPID_TUNER_TS_CREATETUNEREQUEST                 = 6
%DISPID_TUNER_TS_ENUMCATEGORYGUIDS                 = 7
%DISPID_TUNER_TS_ENUMDEVICEMONIKERS                = 8
%DISPID_TUNER_TS_DEFAULTPREFERREDCOMPONENTTYPES    = 9
%DISPID_TUNER_TS_FREQMAP                           = 10
%DISPID_TUNER_TS_DEFLOCATOR                        = 11
%DISPID_TUNER_TS_CLONE                             = 12
%DISPID_TUNER_TR_TUNINGSPACE                       = 1
%DISPID_TUNER_TR_COMPONENTS                        = 2
%DISPID_TUNER_TR_CLONE                             = 3
%DISPID_TUNER_TR_LOCATOR                           = 4
%DISPID_TUNER_CT_CATEGORY                          = 1
%DISPID_TUNER_CT_MEDIAMAJORTYPE                    = 2
%DISPID_TUNER_CT__MEDIAMAJORTYPE                   = 3
%DISPID_TUNER_CT_MEDIASUBTYPE                      = 4
%DISPID_TUNER_CT__MEDIASUBTYPE                     = 5
%DISPID_TUNER_CT_MEDIAFORMATTYPE                   = 6
%DISPID_TUNER_CT__MEDIAFORMATTYPE                  = 7
%DISPID_TUNER_CT_MEDIATYPE                         = 8
%DISPID_TUNER_CT_CLONE                             = 9
%DISPID_TUNER_LCT_LANGID                           = 100
%DISPID_TUNER_MP2CT_TYPE                           = 200
%DISPID_TUNER_ATSCCT_FLAGS                         = 300
%DISPID_TUNER_L_CARRFREQ                           = 1
%DISPID_TUNER_L_INNERFECMETHOD                     = 2
%DISPID_TUNER_L_INNERFECRATE                       = 3
%DISPID_TUNER_L_OUTERFECMETHOD                     = 4
%DISPID_TUNER_L_OUTERFECRATE                       = 5
%DISPID_TUNER_L_MOD                                = 6
%DISPID_TUNER_L_SYMRATE                            = 7
%DISPID_TUNER_L_CLONE                              = 8
%DISPID_TUNER_L_ATSC_PHYS_CHANNEL                  = 201
%DISPID_TUNER_L_ATSC_TSID                          = 202
%DISPID_TUNER_L_DVBT_BANDWIDTH                     = 301
%DISPID_TUNER_L_DVBT_LPINNERFECMETHOD              = 302
%DISPID_TUNER_L_DVBT_LPINNERFECRATE                = 303
%DISPID_TUNER_L_DVBT_GUARDINTERVAL                 = 304
%DISPID_TUNER_L_DVBT_HALPHA                        = 305
%DISPID_TUNER_L_DVBT_TRANSMISSIONMODE              = 306
%DISPID_TUNER_L_DVBT_INUSE                         = 307
%DISPID_TUNER_L_DVBT2_PHYSICALLAYERPIPEID          = 351
%DISPID_TUNER_L_DVBS_POLARISATION                  = 401
%DISPID_TUNER_L_DVBS_WEST                          = 402
%DISPID_TUNER_L_DVBS_ORBITAL                       = 403
%DISPID_TUNER_L_DVBS_AZIMUTH                       = 404
%DISPID_TUNER_L_DVBS_ELEVATION                     = 405
%DISPID_TUNER_L_DVBS2_DISEQ_LNB_SOURCE             = 406
%DISPID_TUNER_TS_DVBS2_LOW_OSC_FREQ_OVERRIDE       = 407
%DISPID_TUNER_TS_DVBS2_HI_OSC_FREQ_OVERRIDE        = 408
%DISPID_TUNER_TS_DVBS2_LNB_SWITCH_FREQ_OVERRIDE    = 409
%DISPID_TUNER_TS_DVBS2_SPECTRAL_INVERSION_OVERRIDE = 410
%DISPID_TUNER_L_DVBS2_ROLLOFF                      = 411
%DISPID_TUNER_L_DVBS2_PILOT                        = 412
%DISPID_TUNER_C_TYPE                               = 1
%DISPID_TUNER_C_STATUS                             = 2
%DISPID_TUNER_C_LANGID                             = 3
%DISPID_TUNER_C_DESCRIPTION                        = 4
%DISPID_TUNER_C_CLONE                              = 5
%DISPID_TUNER_C_MP2_PID                            = 101
%DISPID_TUNER_C_MP2_PCRPID                         = 102
%DISPID_TUNER_C_MP2_PROGNO                         = 103
%DISPID_TUNER_TS_DVB_SYSTEMTYPE                    = 101
%DISPID_TUNER_TS_DVB2_NETWORK_ID                   = 102
%DISPID_TUNER_TS_DVBS_LOW_OSC_FREQ                 = 1001
%DISPID_TUNER_TS_DVBS_HI_OSC_FREQ                  = 1002
%DISPID_TUNER_TS_DVBS_LNB_SWITCH_FREQ              = 1003
%DISPID_TUNER_TS_DVBS_INPUT_RANGE                  = 1004
%DISPID_TUNER_TS_DVBS_SPECTRAL_INVERSION           = 1005
%DISPID_TUNER_TS_AR_MINFREQUENCY                   = 101
%DISPID_TUNER_TS_AR_MAXFREQUENCY                   = 102
%DISPID_TUNER_TS_AR_STEP                           = 103
%DISPID_TUNER_TS_AR_COUNTRYCODE                    = 104
%DISPID_TUNER_TS_AUX_COUNTRYCODE                   = 101
%DISPID_TUNER_TS_ATV_MINCHANNEL                    = 101
%DISPID_TUNER_TS_ATV_MAXCHANNEL                    = 102
%DISPID_TUNER_TS_ATV_INPUTTYPE                     = 103
%DISPID_TUNER_TS_ATV_COUNTRYCODE                   = 104
%DISPID_TUNER_TS_ATSC_MINMINORCHANNEL              = 201
%DISPID_TUNER_TS_ATSC_MAXMINORCHANNEL              = 202
%DISPID_TUNER_TS_ATSC_MINPHYSCHANNEL               = 203
%DISPID_TUNER_TS_ATSC_MAXPHYSCHANNEL               = 204
%DISPID_CHTUNER_ATVAC_CHANNEL                      = 101
%DISPID_CHTUNER_ATVDC_SYSTEM                       = 101
%DISPID_CHTUNER_ATVDC_CONTENT                      = 102
%DISPID_CHTUNER_CTR_CHANNEL                        = 101
%DISPID_CHTUNER_CIDTR_CHANNELID                    = 101
%DISPID_CHTUNER_ACTR_MINOR_CHANNEL                 = 201
%DISPID_DVBTUNER_DVBC_ATTRIBUTESVALID              = 101
%DISPID_DVBTUNER_DVBC_PID                          = 102
%DISPID_DVBTUNER_DVBC_TAG                          = 103
%DISPID_DVBTUNER_DVBC_COMPONENTTYPE                = 104
%DISPID_DVBTUNER_ONID                              = 101
%DISPID_DVBTUNER_TSID                              = 102
%DISPID_DVBTUNER_SID                               = 103
%DISPID_MP2TUNER_TSID                              = 101
%DISPID_MP2TUNER_PROGNO                            = 102
%DISPID_MP2TUNERFACTORY_CREATETUNEREQUEST          = 1


' ########################################################################################
' Interface name = ITuningSpaces
' IID = {901284E4-33FE-4B69-8D63-634A596F3756}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITuningSpaces_INTERFACE_DEFINED)
    %ITuningSpaces_INTERFACE_DEFINED = 1

INTERFACE ITuningSpaces $IID_ITuningSpaces

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET EnumTuningSpaces <1610743811> ( _       ' VTable offset = 40
   ) AS IEnumTuningSpaces                               ' __retval_out IEnumTuningSpaces **NewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuningSpaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITuningSpaceContainer
' IID = {5B692E84-E2F1-11D2-9493-00C04F72D980}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITuningSpaceContainer_INTERFACE_DEFINED)
    %ITuningSpaceContainer_INTERFACE_DEFINED = 1

INTERFACE ITuningSpaceContainer $IID_ITuningSpaceContainer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **NewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 40
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   , BYVAL ITuningSpace _                               ' __in ITuningSpace *TuningSpace
   )                                                    ' void
   ' =====================================================================================
   METHOD TuningSpacesForCLSID <1610743812> ( _         ' VTable offset = 44
     BYVAL SpaceCLSID AS WSTRING _                      ' __in BSTR SpaceCLSID
   ) AS ITuningSpaces                                   ' __retval_out ITuningSpaces **NewColl
   ' =====================================================================================
   METHOD TuningSpacesForCLSID_ <1610743813> ( _        ' VTable offset = 48
     BYREF SpaceCLSID AS GUID _                         ' __in REFCLSID SpaceCLSID
   ) AS ITuningSpaces                                   ' __retval_out ITuningSpaces **NewColl
   ' =====================================================================================
   METHOD TuningSpacesForName <1610743814> ( _          ' VTable offset = 52
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS ITuningSpaces                                   ' __retval_out ITuningSpaces **NewColl
   ' =====================================================================================
   METHOD FindID <1610743815> ( _                       ' VTable offset = 56
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 60
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   ) AS VARIANT                                         ' __retval_out VARIANT *NewIndex
   ' =====================================================================================
   PROPERTY GET EnumTuningSpaces <1610743817> ( _       ' VTable offset = 64
   ) AS IEnumTuningSpaces                               ' __retval_out IEnumTuningSpaces **ppEnum
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 68
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxCount <1610743819> ( _               ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *MaxCount
   ' =====================================================================================
   PROPERTY SET MaxCount <1610743819> ( _               ' VTable offset = 76
     BYVAL MaxCount AS LONG _                           ' __in long MaxCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuningSpaceContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITuningSpace
' IID = {061C6E30-E622-11D2-9493-00C04F72D980}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITuningSpace_INTERFACE_DEFINED)
    %ITuningSpace_INTERFACE_DEFINED = 1

INTERFACE ITuningSpace $IID_ITuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumTuningSpaces
' IID = {8B8EB248-FC2B-11D2-9D8C-00C04F72D980}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumTuningSpaces_INTERFACE_DEFINED)
    %IEnumTuningSpaces_INTERFACE_DEFINED = 1

INTERFACE IEnumTuningSpaces $IID_IEnumTuningSpaces

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS ITuningSpace _                      ' __out ITuningSpace **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumTuningSpaces _                ' __out IEnumTuningSpaces **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumTuningSpaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBTuningSpace
' IID = {ADA0B268-3B19-4E5B-ACC4-49F852BE13BA}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuningSpace
' ########################################################################################

#IF NOT %DEF(%IDVBTuningSpace_INTERFACE_DEFINED)
    %IDVBTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IDVBTuningSpace $IID_IDVBTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET SystemType <101> ( _                    ' VTable offset = 104
   ) AS DVBSYSTEMTYPE_ENUM                              ' __retval_out DVBSystemType *SysType
   ' =====================================================================================
   PROPERTY SET SystemType <101> ( _                    ' VTable offset = 108
     BYVAL SysType AS DVBSYSTEMTYPE_ENUM _              ' __in DVBSystemType SysType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBTuningSpace2
' IID = {843188B4-CE62-43DB-966B-8145A094E040}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDVBTuningSpace
' ########################################################################################

#IF NOT %DEF(%IDVBTuningSpace2_INTERFACE_DEFINED)
    %IDVBTuningSpace2_INTERFACE_DEFINED = 1

INTERFACE IDVBTuningSpace2 $IID_IDVBTuningSpace2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET SystemType <101> ( _                    ' VTable offset = 104
   ) AS DVBSYSTEMTYPE_ENUM                              ' __retval_out DVBSystemType *SysType
   ' =====================================================================================
   PROPERTY SET SystemType <101> ( _                    ' VTable offset = 108
     BYVAL SysType AS DVBSYSTEMTYPE_ENUM _              ' __in DVBSystemType SysType
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuningSpace2 Methods
   ' =====================================================================================
   PROPERTY GET NetworkID <102> ( _                     ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *NetworkID
   ' =====================================================================================
   PROPERTY SET NetworkID <102> ( _                     ' VTable offset = 116
     BYVAL NetworkID AS LONG _                          ' __in long NetworkID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBTuningSpace2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBSTuningSpace
' IID = {CDF7BE60-D954-42FD-A972-78971958E470}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDVBTuningSpace2
' ########################################################################################

#IF NOT %DEF(%IDVBSTuningSpace_INTERFACE_DEFINED)
    %IDVBSTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IDVBSTuningSpace $IID_IDVBSTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET SystemType <101> ( _                    ' VTable offset = 104
   ) AS DVBSYSTEMTYPE_ENUM                              ' __retval_out DVBSystemType *SysType
   ' =====================================================================================
   PROPERTY SET SystemType <101> ( _                    ' VTable offset = 108
     BYVAL SysType AS DVBSYSTEMTYPE_ENUM _              ' __in DVBSystemType SysType
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuningSpace2 Methods
   ' =====================================================================================
   PROPERTY GET NetworkID <102> ( _                     ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *NetworkID
   ' =====================================================================================
   PROPERTY SET NetworkID <102> ( _                     ' VTable offset = 116
     BYVAL NetworkID AS LONG _                          ' __in long NetworkID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBSTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET LowOscillator <1001> ( _                ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *LowOscillator
   ' =====================================================================================
   PROPERTY SET LowOscillator <1001> ( _                ' VTable offset = 124
     BYVAL LowOscillator AS LONG _                      ' __in long LowOscillator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HighOscillator <1002> ( _               ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *HighOscillator
   ' =====================================================================================
   PROPERTY SET HighOscillator <1002> ( _               ' VTable offset = 132
     BYVAL HighOscillator AS LONG _                     ' __in long HighOscillator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LNBSwitch <1003> ( _                    ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *LNBSwitch
   ' =====================================================================================
   PROPERTY SET LNBSwitch <1003> ( _                    ' VTable offset = 140
     BYVAL LNBSwitch AS LONG _                          ' __in long LNBSwitch
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputRange <1004> ( _                   ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *InputRange
   ' =====================================================================================
   PROPERTY SET InputRange <1004> ( _                   ' VTable offset = 148
     BYVAL InputRange AS WSTRING _                      ' __in BSTR InputRange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SpectralInversion <1005> ( _            ' VTable offset = 152
   ) AS SPECTRALINVERSION_ENUM                          ' __retval_out SpectralInversion *SpectralInversionVal
   ' =====================================================================================
   PROPERTY SET SpectralInversion <1005> ( _            ' VTable offset = 156
     BYVAL SpectralInversionVal AS SPECTRALINVERSION_ENUM _ '  __in SpectralInversion SpectralInversionVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBSTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAuxInTuningSpace
' IID = {E48244B8-7E17-4F76-A763-5090FF1E2F30}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuningSpace
' ########################################################################################

#IF NOT %DEF(%IAuxInTuningSpace_INTERFACE_DEFINED)
    %IAuxInTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IAuxInTuningSpace $IID_IAuxInTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAuxInTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAuxInTuningSpace2
' IID = {B10931ED-8BFE-4AB0-9DCE-E469C29A9729}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAuxInTuningSpace
' ########################################################################################

#IF NOT %DEF(%IAuxInTuningSpace2_INTERFACE_DEFINED)
    %IAuxInTuningSpace2_INTERFACE_DEFINED = 1

INTERFACE IAuxInTuningSpace2 $IID_IAuxInTuningSpace2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAuxInTuningSpace2 Methods
   ' =====================================================================================
   PROPERTY GET CountryCode <101> ( _                   ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *CountryCodeVal
   ' =====================================================================================
   PROPERTY SET CountryCode <101> ( _                   ' VTable offset = 108
     BYVAL NewCountryCodeVal AS LONG _                  ' __in long NewCountryCodeVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAuxInTuningSpace2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalogTVTuningSpace
' IID = {2A6E293C-2595-11D3-B64C-00C04F79498E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuningSpace
' ########################################################################################

#IF NOT %DEF(%IAnalogTVTuningSpace_INTERFACE_DEFINED)
    %IAnalogTVTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IAnalogTVTuningSpace $IID_IAnalogTVTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogTVTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinChannel <101> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *MinChannelVal
   ' =====================================================================================
   PROPERTY SET MinChannel <101> ( _                    ' VTable offset = 108
     BYVAL NewMinChannelVal AS LONG _                   ' __in long NewMinChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxChannel <102> ( _                    ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *MaxChannelVal
   ' =====================================================================================
   PROPERTY SET MaxChannel <102> ( _                    ' VTable offset = 116
     BYVAL NewMaxChannelVal AS LONG _                   ' __in long NewMaxChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputType <103> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out TunerInputType *InputTypeVal
   ' =====================================================================================
   PROPERTY SET InputType <103> ( _                     ' VTable offset = 124
     BYVAL NewInputTypeVal AS LONG _                    ' __in TunerInputType NewInputTypeVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CountryCode <104> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *CountryCodeVal
   ' =====================================================================================
   PROPERTY SET CountryCode <104> ( _                   ' VTable offset = 132
     BYVAL NewCountryCodeVal AS LONG _                  ' __in long NewCountryCodeVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalogTVTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IATSCTuningSpace
' IID = {0369B4E2-45B6-11D3-B650-00C04F79498E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAnalogTVTuningSpace
' ########################################################################################

#IF NOT %DEF(%IATSCTuningSpace_INTERFACE_DEFINED)
    %IATSCTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IATSCTuningSpace $IID_IATSCTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogTVTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinChannel <101> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *MinChannelVal
   ' =====================================================================================
   PROPERTY SET MinChannel <101> ( _                    ' VTable offset = 108
     BYVAL NewMinChannelVal AS LONG _                   ' __in long NewMinChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxChannel <102> ( _                    ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *MaxChannelVal
   ' =====================================================================================
   PROPERTY SET MaxChannel <102> ( _                    ' VTable offset = 116
     BYVAL NewMaxChannelVal AS LONG _                   ' __in long NewMaxChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputType <103> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out TunerInputType *InputTypeVal
   ' =====================================================================================
   PROPERTY SET InputType <103> ( _                     ' VTable offset = 124
     BYVAL NewInputTypeVal AS LONG _                    ' __in TunerInputType NewInputTypeVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CountryCode <104> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *CountryCodeVal
   ' =====================================================================================
   PROPERTY SET CountryCode <104> ( _                   ' VTable offset = 132
     BYVAL NewCountryCodeVal AS LONG _                  ' __in long NewCountryCodeVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinMinorChannel <201> ( _               ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *MinMinorChannelVal
   ' =====================================================================================
   PROPERTY SET MinMinorChannel <201> ( _               ' VTable offset = 140
     BYVAL NewMinMinorChannelVal AS LONG _              ' __in long NewMinMinorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxMinorChannel <202> ( _               ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *MaxMinorChannelVal
   ' =====================================================================================
   PROPERTY SET MaxMinorChannel <202> ( _               ' VTable offset = 148
     BYVAL NewMaxMinorChannelVal AS LONG _              ' __in long NewMaxMinorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinPhysicalChannel <203> ( _            ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *MinPhysicalChannelVal
   ' =====================================================================================
   PROPERTY SET MinPhysicalChannel <203> ( _            ' VTable offset = 156
     BYVAL NewMinPhysicalChannelVal AS LONG _           ' __in long NewMinPhysicalChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxPhysicalChannel <204> ( _            ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *MaxPhysicalChannelVal
   ' =====================================================================================
   PROPERTY SET MaxPhysicalChannel <204> ( _            ' VTable offset = 164
     BYVAL NewMaxPhysicalChannelVal AS LONG _           ' __in long NewMaxPhysicalChannelVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSCTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDigitalCableTuningSpace
' IID = {013F9F9C-B449-4EC7-A6D2-9D4F2FC70AE5}
' Inherited interface = IATSCTuningSpace
' ########################################################################################

#IF NOT %DEF(%IDigitalCableTuningSpace_INTERFACE_DEFINED)
    %IDigitalCableTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IDigitalCableTuningSpace $IID_IDigitalCableTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogTVTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinChannel <101> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *MinChannelVal
   ' =====================================================================================
   PROPERTY SET MinChannel <101> ( _                    ' VTable offset = 108
     BYVAL NewMinChannelVal AS LONG _                   ' __in long NewMinChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxChannel <102> ( _                    ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *MaxChannelVal
   ' =====================================================================================
   PROPERTY SET MaxChannel <102> ( _                    ' VTable offset = 116
     BYVAL NewMaxChannelVal AS LONG _                   ' __in long NewMaxChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputType <103> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out TunerInputType *InputTypeVal
   ' =====================================================================================
   PROPERTY SET InputType <103> ( _                     ' VTable offset = 124
     BYVAL NewInputTypeVal AS LONG _                    ' __in TunerInputType NewInputTypeVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CountryCode <104> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *CountryCodeVal
   ' =====================================================================================
   PROPERTY SET CountryCode <104> ( _                   ' VTable offset = 132
     BYVAL NewCountryCodeVal AS LONG _                  ' __in long NewCountryCodeVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinMinorChannel <201> ( _               ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *MinMinorChannelVal
   ' =====================================================================================
   PROPERTY SET MinMinorChannel <201> ( _               ' VTable offset = 140
     BYVAL NewMinMinorChannelVal AS LONG _              ' __in long NewMinMinorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxMinorChannel <202> ( _               ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *MaxMinorChannelVal
   ' =====================================================================================
   PROPERTY SET MaxMinorChannel <202> ( _               ' VTable offset = 148
     BYVAL NewMaxMinorChannelVal AS LONG _              ' __in long NewMaxMinorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinPhysicalChannel <203> ( _            ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *MinPhysicalChannelVal
   ' =====================================================================================
   PROPERTY SET MinPhysicalChannel <203> ( _            ' VTable offset = 156
     BYVAL NewMinPhysicalChannelVal AS LONG _           ' __in long NewMinPhysicalChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxPhysicalChannel <204> ( _            ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *MaxPhysicalChannelVal
   ' =====================================================================================
   PROPERTY SET MaxPhysicalChannel <204> ( _            ' VTable offset = 164
     BYVAL NewMaxPhysicalChannelVal AS LONG _           ' __in long NewMaxPhysicalChannelVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDigitalCableTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinMajorChannel <301> ( _               ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *MinMajorChannelVal
   ' =====================================================================================
   PROPERTY SET MinMajorChannel <301> ( _               ' VTable offset = 172
     BYVAL NewMinMajorChannelVal AS LONG _              ' __in long NewMinMajorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxMajorChannel <302> ( _               ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long *MaxMajorChannelVal
   ' =====================================================================================
   PROPERTY SET MaxMajorChannel <302> ( _               ' VTable offset = 180
     BYVAL NewMaxMajorChannelVal AS LONG _              ' __in long NewMaxMajorChannelVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinSourceID <303> ( _                   ' VTable offset = 184
   ) AS LONG                                            ' __retval_out long *MinSourceIDVal
   ' =====================================================================================
   PROPERTY SET MinSourceID <303> ( _                   ' VTable offset = 192
     BYVAL NewMinSourceIDVal AS LONG _                  ' __in long NewMinSourceIDVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxSourceID <304> ( _                   ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long *MaxSourceIDVal
   ' =====================================================================================
   PROPERTY SET MaxSourceID <304> ( _                   ' VTable offset = 200
     BYVAL NewMaxSourceIDVal AS LONG _                  ' __in long NewMaxSourceIDVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ____IDigitalCableTuningSpace_INTERFACE_DEFINED____ */

' ########################################################################################
' Interface name = IAnalogRadioTuningSpace
' IID = {2A6E293B-2595-11D3-B64C-00C04F79498E}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuningSpace
' ########################################################################################

#IF NOT %DEF(%IAnalogRadioTuningSpace_INTERFACE_DEFINED)
    %IAnalogRadioTuningSpace_INTERFACE_DEFINED = 1

INTERFACE IAnalogRadioTuningSpace $IID_IAnalogRadioTuningSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogRadioTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinFrequency <101> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *MinFrequencyVal
   ' =====================================================================================
   PROPERTY SET MinFrequency <101> ( _                  ' VTable offset = 108
     BYVAL NewMinFrequencyVal AS LONG _                 ' __in long NewMinFrequencyVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxFrequency <102> ( _                  ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *MaxFrequencyVal
   ' =====================================================================================
   PROPERTY SET MaxFrequency <102> ( _                  ' VTable offset = 116
     BYVAL NewMaxFrequencyVal AS LONG _                 ' __in long NewMaxFrequencyVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Step <103> ( _                          ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *StepVal
   ' =====================================================================================
   PROPERTY SET Step <103> ( _                          ' VTable offset = 124
     BYVAL NewStepVal AS LONG _                         ' __in long NewStepVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalogRadioTuningSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalogRadioTuningSpace2
' IID = {39DD45DA-2DA8-46BA-8A8A-87E2B73D983A}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAnalogRadioTuningSpace
' ########################################################################################

#IF NOT %DEF(%IAnalogRadioTuningSpace2_INTERFACE_DEFINED)
    %IAnalogRadioTuningSpace2_INTERFACE_DEFINED = 1

INTERFACE IAnalogRadioTuningSpace2 $IID_IAnalogRadioTuningSpace2

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuningSpace Methods
   ' =====================================================================================
   PROPERTY GET UniqueName <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET UniqueName <1> ( _                      ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <2> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET FriendlyName <2> ( _                    ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <3> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SpaceCLSID
   ' =====================================================================================
   PROPERTY GET NetworkType <4> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType <4> ( _                     ' VTable offset = 52
     BYVAL NetworkTypeGuid AS WSTRING _                 ' __in BSTR NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkType_ <5> ( _                    ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *NetworkTypeGuid
   ' =====================================================================================
   PROPERTY SET NetworkType_ <5> ( _                    ' VTable offset = 60
     BYREF IN NetworkTypeGuid AS GUID _                 ' __in REFCLSID NetworkTypeGuid
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTuneRequest <6> ( _                     ' VTable offset = 64
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   METHOD EnumCategoryGUIDs <7> ( _                     ' VTable offset = 68
   ) AS IEnumGUID                                       ' __retval_out IEnumGUID **ppEnum
   ' =====================================================================================
   METHOD EnumDeviceMonikers <8> ( _                    ' VTable offset = 72
   ) AS IComponentTypes                                 ' __retval_out IEnumMoniker **ppEnum
   ' =====================================================================================
   PROPERTY GET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 76
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET DefaultPreferredComponentTypes <9> ( _  ' VTable offset = 80
     BYVAL NewComponentTypes AS IComponentTypes _       ' __in IComponentTypes *NewComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrequencyMapping <10> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pMapping
   ' =====================================================================================
   PROPERTY SET FrequencyMapping <10> ( _               ' VTable offset = 88
     BYVAL Mapping AS WSTRING _                         ' __in BSTR Mapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultLocator <11> ( _                 ' VTable offset = 92
   ) AS ILocator                                        ' __retval_out ILocator **LocatorVal
   ' =====================================================================================
   PROPERTY SET DefaultLocator <11> ( _                 ' VTable offset = 96
     BYVAL LocatorVal AS ILocator _                     ' __in ILocator *LocatorVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743826> ( _                        ' VTable offset = 100
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **NewTS
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogRadioTuningSpace Methods
   ' =====================================================================================
   PROPERTY GET MinFrequency <101> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *MinFrequencyVal
   ' =====================================================================================
   PROPERTY SET MinFrequency <101> ( _                  ' VTable offset = 108
     BYVAL NewMinFrequencyVal AS LONG _                 ' __in long NewMinFrequencyVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxFrequency <102> ( _                  ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *MaxFrequencyVal
   ' =====================================================================================
   PROPERTY SET MaxFrequency <102> ( _                  ' VTable offset = 116
     BYVAL NewMaxFrequencyVal AS LONG _                 ' __in long NewMaxFrequencyVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Step <103> ( _                          ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *StepVal
   ' =====================================================================================
   PROPERTY SET Step <103> ( _                          ' VTable offset = 124
     BYVAL NewStepVal AS LONG _                         ' __in long NewStepVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogRadioTuningSpace2 Methods
   ' =====================================================================================
   PROPERTY GET CountryCode <104> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *CountryCodeVal
   ' =====================================================================================
   PROPERTY SET CountryCode <104> ( _                   ' VTable offset = 132
     BYVAL NewCountryCodeVal AS LONG _                  ' __in long NewCountryCodeVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalogRadioTuningSpace2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITuneRequest
' IID = {07DDC146-FC3D-11D2-9D8C-00C04F72D980}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITuneRequest_INTERFACE_DEFINED)
    %ITuneRequest_INTERFACE_DEFINED = 1

INTERFACE ITuneRequest $IID_ITuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChannelIDTuneRequest
' IID = {156EFF60-86F4-4E28-89FC-109799FD57EE}
' Channel ID Tune Request Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuneRequest
' ########################################################################################

#IF NOT %DEF(%IChannelIDTuneRequest_INTERFACE_DEFINED)
    %IChannelIDTuneRequest_INTERFACE_DEFINED = 1

INTERFACE IChannelIDTuneRequest $IID_IChannelIDTuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IChannelIDTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET ChannelID <101> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *ChannelID
   ' =====================================================================================
   PROPERTY SET ChannelID <101> ( _                     ' VTable offset = 52
     BYVAL ChannelID AS WSTRING _                       ' __in BSTR ChannelID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChannelIDTuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChannelTuneRequest
' IID = {0369B4E0-45B6-11D3-B650-00C04F79498E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuneRequest
' ########################################################################################

#IF NOT %DEF(%IChannelTuneRequest_INTERFACE_DEFINED)
    %IChannelTuneRequest_INTERFACE_DEFINED = 1

INTERFACE IChannelTuneRequest $IID_IChannelTuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IChannelTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET Channel <101> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Channel
   ' =====================================================================================
   PROPERTY SET Channel <101> ( _                       ' VTable offset = 52
     BYVAL Channel AS LONG _                            ' __in long Channel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChannelTuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IATSCChannelTuneRequest
' IID = {0369B4E1-45B6-11D3-B650-00C04F79498E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IChannelTuneRequest
' ########################################################################################

#IF NOT %DEF(%IATSCChannelTuneRequest_INTERFACE_DEFINED)
    %IATSCChannelTuneRequest_INTERFACE_DEFINED = 1

INTERFACE IATSCChannelTuneRequest $IID_IATSCChannelTuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IChannelTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET Channel <101> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Channel
   ' =====================================================================================
   PROPERTY SET Channel <101> ( _                       ' VTable offset = 52
     BYVAL Channel AS LONG _                            ' __in long Channel
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCChannelTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET MinorChannel <201> ( _                  ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *MinorChannel
   ' =====================================================================================
   PROPERTY SET MinorChannel <201> ( _                  ' VTable offset = 60
     BYVAL MinorChannel AS LONG _                       ' __in long MinorChannel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSCChannelTuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDigitalCableTuneRequest
' IID = {BAD7753B-6B37-4810-AE57-3CE0C4A9E6CB}
' Inherited interface = IATSCChannelTuneRequest
' ########################################################################################

#IF NOT %DEF(%IDigitalCableTuneRequest_INTERFACE_DEFINED)
    %IDigitalCableTuneRequest_INTERFACE_DEFINED = 1

INTERFACE IDigitalCableTuneRequest $IID_IDigitalCableTuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IChannelTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET Channel <101> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Channel
   ' =====================================================================================
   PROPERTY SET Channel <101> ( _                       ' VTable offset = 52
     BYVAL Channel AS LONG _                            ' __in long Channel
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCChannelTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET MinorChannel <201> ( _                  ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *MinorChannel
   ' =====================================================================================
   PROPERTY SET MinorChannel <201> ( _                  ' VTable offset = 60
     BYVAL MinorChannel AS LONG _                       ' __in long MinorChannel
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDigitalCableTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET MajorChannel <301> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pMajorChannel
   ' =====================================================================================
   PROPERTY SET MajorChannel <301> ( _                  ' VTable offset = 68
     BYVAL MajorChannel AS LONG _                       ' __in long MajorChannel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceID <302> ( _                      ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pSourceID
   ' =====================================================================================
   PROPERTY SET SourceID <302> ( _                      ' VTable offset = 76
     BYVAL SourceID AS LONG _                           ' __in long SourceID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDigitalCableTuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBTuneRequest
' IID = {0D6F567E-A636-42BB-83BA-CE4C1704AFA2}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuneRequest
' ########################################################################################

#IF NOT %DEF(%IDVBTuneRequest_INTERFACE_DEFINED)
    %IDVBTuneRequest_INTERFACE_DEFINED = 1

INTERFACE IDVBTuneRequest $IID_IDVBTuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTuneRequest Methods
   ' =====================================================================================
   PROPERTY GET ONID <101> ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *ONID
   ' =====================================================================================
   PROPERTY SET ONID <101> ( _                          ' VTable offset = 52
     BYVAL ONID AS LONG _                               ' __in long ONID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <102> ( _                          ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *TSID
   ' =====================================================================================
   PROPERTY SET TSID <102> ( _                          ' VTable offset = 60
     BYVAL TSID AS LONG _                               ' __in long TSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SID <103> ( _                           ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *SID
   ' =====================================================================================
   PROPERTY SET SID <103> ( _                           ' VTable offset = 68
     BYVAL SID AS LONG _                                ' __in long SID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBTuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMPEG2TuneRequest
' IID = {EB7D987F-8A01-42AD-B8AE-574DEEE44D1A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITuneRequest
' ########################################################################################

#IF NOT %DEF(%IMPEG2TuneRequest_INTERFACE_DEFINED)
    %IMPEG2TuneRequest_INTERFACE_DEFINED = 1

INTERFACE IMPEG2TuneRequest $IID_IMPEG2TuneRequest

   INHERIT IDispatch

   ' =====================================================================================
   ' ITuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace <1> ( _                     ' VTable offset = 28
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 32
   ) AS IComponents                                     ' __retval_out IComponents **Components
   ' =====================================================================================
   METHOD Clone <3> ( _                                 ' VTable offset = 36
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **NewTuneRequest
   ' =====================================================================================
   PROPERTY GET Locator <4> ( _                         ' VTable offset = 40
   ) AS ILocator                                        ' __retval_out ILocator **Locator
   ' =====================================================================================
   PROPERTY SET Locator <4> ( _                         ' VTable offset = 44
     BYVAL Locator AS ILocator _                        ' __in ILocator *Locator
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMPEG2TuneRequest Methods
   ' =====================================================================================
   PROPERTY GET TSID <101> ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *TSID
   ' =====================================================================================
   PROPERTY SET TSID <101> ( _                          ' VTable offset = 52
     BYVAL TSID AS LONG _                               ' __in long TSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProgNo <102> ( _                        ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *ProgNo
   ' =====================================================================================
   PROPERTY SET ProgNo <102> ( _                        ' VTable offset = 60
     BYVAL ProgNo AS LONG _                             ' __in long ProgNo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2TuneRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMPEG2TuneRequestFactory
' IID = {14E11ABD-EE37-4893-9EA1-6964DE933E39}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMPEG2TuneRequestFactory_INTERFACE_DEFINED)
    %IMPEG2TuneRequestFactory_INTERFACE_DEFINED = 1

INTERFACE IMPEG2TuneRequestFactory $IID_IMPEG2TuneRequestFactory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateTuneRequest <1> ( _                     ' VTable offset = 28
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   ) AS IMPEG2TuneRequest                               ' __retval_out IMPEG2TuneRequest **TuneRequest
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2TuneRequestFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMPEG2TuneRequestSupport
' IID = {1B9D5FC3-5BBC-4B6C-BB18-B9D10E3EEEBF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMPEG2TuneRequestSupport_INTERFACE_DEFINED)
    %IMPEG2TuneRequestSupport_INTERFACE_DEFINED = 1

$IID_IMPEG2TuneRequestSupport = GUID$("{1B9D5FC3-5BBC-4B6C-BB18-B9D10E3EEEBF}")

INTERFACE IMPEG2TuneRequestSupport $IID_IMPEG2TuneRequestSupport

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IMPEG2TuneRequestSupport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITunerCap
' IID = {E60DFA45-8D56-4E65-A8AB-D6BE9412C249}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITunerCap_INTERFACE_DEFINED)
    %ITunerCap_INTERFACE_DEFINED = 1

$IID_ITunerCap = GUID$("{E60DFA45-8D56-4E65-A8AB-D6BE9412C249}")

INTERFACE ITunerCap $IID_ITunerCap

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SupportedNetworkTypes ( _                     ' VTable offset = 12
     BYVAL ulcNetworkTypesMax AS DWORD _                ' __in ULONG ulcNetworkTypesMax
   , BYREF pulcNetworkTypes AS DWORD _                  ' __out ULONG *pulcNetworkTypes
   , BYREF pguidNetworkTypes AS GUID _                  ' __inout GUID *pguidNetworkTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD SupportedVideoFormats ( _                     ' VTable offset = 16
     BYREF pulAMTunerModeType AS DWORD _                ' __out ULONG *pulAMTunerModeType
   , BYREF pulAnalogVideoStandard AS DWORD _            ' __out ULONG *pulAnalogVideoStandard
   )                                                    ' void
   ' =====================================================================================
   METHOD AuxInputCount ( _                             ' VTable offset = 20
     BYREF pulCompositeCount AS DWORD _                 ' __inout ULONG *pulCompositeCount
   , BYREF pulSvideoCount AS DWORD _                    ' __inout ULONG *pulSvideoCount
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITunerCap_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITunerCapEx
' IID = {ED3E0C66-18C8-4EA6-9300-F6841FDD35DC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITunerCapEx_INTERFACE_DEFINED)
    %ITunerCapEx_INTERFACE_DEFINED = 1

$IID_ITunerCapEx = GUID$("{ED3E0C66-18C8-4EA6-9300-F6841FDD35DC}")

INTERFACE ITunerCapEx $IID_ITunerCapEx

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Has608_708Caption ( _                   ' VTable offset = 12
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasCaption
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITunerCapEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITuner
' IID = {28C52640-018A-11D3-9D8E-00C04F72D980}
' Attributes = 144 [&H90] [Hidden] [Nonextensible]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITuner_INTERFACE_DEFINED)
    %ITuner_INTERFACE_DEFINED = 1

INTERFACE ITuner $IID_ITuner

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET TuningSpace ( _                         ' VTable offset = 12
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY SET TuningSpace ( _                         ' VTable offset = 16
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumTuningSpaces ( _                          ' VTable offset = 20
   ) AS IEnumTuningSpaces                               ' __retval_out IEnumTuningSpaces **ppEnum
   ' =====================================================================================
   PROPERTY GET TuneRequest ( _                         ' VTable offset = 24
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   PROPERTY SET TuneRequest ( _                         ' VTable offset = 28
     BYVAL ITuneRequest _                               ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 32
     BYVAL TuneRequest AS ITuneRequest _                ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredComponentTypes ( _             ' VTable offset = 36
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET PreferredComponentTypes ( _             ' VTable offset = 40
     BYVAL ComponentTypes AS IComponentTypes _          ' __in IComponentTypes *ComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignalStrength ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *Strength
   ' =====================================================================================
   METHOD TriggerSignalEvents ( _                       ' VTable offset = 48
     BYVAL Interval AS LONG _                           ' __in long Interval
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITuner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScanningTuner
' IID = {1DFD0A5C-0284-11D3-9D8E-00C04F72D980}
' Inherited interface = ITuner
' ########################################################################################

#IF NOT %DEF(%IScanningTuner_INTERFACE_DEFINED)
    %IScanningTuner_INTERFACE_DEFINED = 1

$IID_IScanningTuner = GUID$("{1DFD0A5C-0284-11D3-9D8E-00C04F72D980}")
$SID_ScanningTuner = $IID_IScanningTuner

INTERFACE IScanningTuner $IID_IScanningTuner

   INHERIT IAutomation

   ' =====================================================================================
   ' ITuner Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace ( _                         ' VTable offset = 12
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY SET TuningSpace ( _                         ' VTable offset = 16
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumTuningSpaces ( _                          ' VTable offset = 20
   ) AS IEnumTuningSpaces                               ' __retval_out IEnumTuningSpaces **ppEnum
   ' =====================================================================================
   PROPERTY GET TuneRequest ( _                         ' VTable offset = 24
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   PROPERTY SET TuneRequest ( _                         ' VTable offset = 28
     BYVAL ITuneRequest _                               ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 32
     BYVAL TuneRequest AS ITuneRequest _                ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredComponentTypes ( _             ' VTable offset = 36
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET PreferredComponentTypes ( _             ' VTable offset = 40
     BYVAL ComponentTypes AS IComponentTypes _          ' __in IComponentTypes *ComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignalStrength ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *Strength
   ' =====================================================================================
   METHOD TriggerSignalEvents ( _                       ' VTable offset = 48
     BYVAL Interval AS LONG _                           ' __in long Interval
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IScanningTuner Methods
   ' =====================================================================================
   METHOD SeekUp ( _                                    ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SeekDown ( _                                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD ScanUp ( _                                    ' VTable offset = 60
     BYVAL MillisecondsPause AS LONG _                  ' __in long MillisecondsPause
   )                                                    ' void
   ' =====================================================================================
   METHOD ScanDown ( _                                  ' VTable offset = 64
     BYVAL MillisecondsPause AS LONG _                  ' __in long MillisecondsPause
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoProgram ( _                               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScanningTuner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScanningTunerEx
' IID = {04BBD195-0E2D-4593-9BD5-4F908BC33CF5}
' Inherited interface = IScanningTuner
' ########################################################################################

#IF NOT %DEF(%IScanningTunerEx_INTERFACE_DEFINED)
    %IScanningTunerEx_INTERFACE_DEFINED = 1

$IID_IScanningTunerEx = GUID$("{04BBD195-0E2D-4593-9BD5-4F908BC33CF5}")
$SID_ScanningTunerEx = $IID_IScanningTunerEx

INTERFACE IScanningTunerEx $IID_IScanningTunerEx

   INHERIT IAutomation

   ' =====================================================================================
   ' ITuner Methods
   ' =====================================================================================
   PROPERTY GET TuningSpace ( _                         ' VTable offset = 12
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **TuningSpace
   ' =====================================================================================
   PROPERTY SET TuningSpace ( _                         ' VTable offset = 16
     BYVAL TuningSpace AS ITuningSpace _                ' __in ITuningSpace *TuningSpace
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumTuningSpaces ( _                          ' VTable offset = 20
   ) AS IEnumTuningSpaces                               ' __retval_out IEnumTuningSpaces **ppEnum
   ' =====================================================================================
   PROPERTY GET TuneRequest ( _                         ' VTable offset = 24
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================
   PROPERTY SET TuneRequest ( _                         ' VTable offset = 28
     BYVAL ITuneRequest _                               ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 32
     BYVAL TuneRequest AS ITuneRequest _                ' __in ITuneRequest *TuneRequest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredComponentTypes ( _             ' VTable offset = 36
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **ComponentTypes
   ' =====================================================================================
   PROPERTY SET PreferredComponentTypes ( _             ' VTable offset = 40
     BYVAL ComponentTypes AS IComponentTypes _          ' __in IComponentTypes *ComponentTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignalStrength ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *Strength
   ' =====================================================================================
   METHOD TriggerSignalEvents ( _                       ' VTable offset = 48
     BYVAL Interval AS LONG _                           ' __in long Interval
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IScanningTuner Methods
   ' =====================================================================================
   METHOD SeekUp ( _                                    ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD SeekDown ( _                                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD ScanUp ( _                                    ' VTable offset = 60
     BYVAL MillisecondsPause AS LONG _                  ' __in long MillisecondsPause
   )                                                    ' void
   ' =====================================================================================
   METHOD ScanDown ( _                                  ' VTable offset = 64
     BYVAL MillisecondsPause AS LONG _                  ' __in long MillisecondsPause
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoProgram ( _                               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IScanningTunerEx Methods
   ' =====================================================================================
   METHOD GetCurrentLocator ( _                         ' VTable offset = 72
     BYREF pILocator AS ILocator _                      ' __in_opt ILocator **pILocator
   )                                                    ' void
   ' =====================================================================================
   METHOD PerformExhaustiveScan ( _                     ' VTable offset = 76
     BYVAL dwLowerFreq AS LONG _                        ' __in long dwLowerFreq
   , BYVAL dwHigherFreq AS LONG _                       ' __in long dwHigherFreq
   , BYVAL bFineTune AS INTEGER _                       ' __in VARIANT_BOOL bFineTune
   , BYVAL hEvent AS DWORD _                            ' __in HEVENT hEvent
   )                                                    ' void
   ' =====================================================================================
   METHOD TerminateCurrentScan ( _                      ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *pcurrentFreq
   ' =====================================================================================
   METHOD ResumeCurrentScan ( _                         ' VTable offset = 84
     BYVAL hEvent AS DWORD _                            ' __in HEVENT hEvent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTunerScanningCapability ( _                ' VTable offset = 88
     BYREF HardwareAssistedScanning AS LONG _           ' __out long *HardwareAssistedScanning
   , BYREF NumStandardsSupported AS LONG _              ' __out long *NumStandardsSupported
   , BYREF BroadcastStandards AS GUID _                 ' __out GUID *BroadcastStandards
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTunerStatus ( _                            ' VTable offset = 92
     BYREF SecondsLeft AS LONG _                        ' __out long *SecondsLeft
   , BYREF CurrentLockType AS LONG _                    ' __out long *CurrentLockType
   , BYREF AutoDetect AS LONG _                         ' __out long *AutoDetect
   , BYREF CurrentFreq AS LONG _                        ' __out long *CurrentFreq
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentTunerStandardCapability ( _         ' VTable offset = 96
     BYREF CurrentBroadcastStandard AS GUID _           ' __in GUID CurrentBroadcastStandard
   , BYREF SettlingTime AS LONG _                       ' __out long *SettlingTime
   , BYREF TvStandardsSupported AS LONG _               ' __out long *TvStandardsSupported
   )                                                    ' void
   ' =====================================================================================
   METHOD SetScanSignalTypeFilter ( _                   ' VTable offset = 100
     BYVAL ScanModulationTypes AS LONG _                ' __in long ScanModulationTypes
   , BYVAL AnalogVideoStandard AS LONG _                ' __in long AnalogVideoStandard
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScanningTunerEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponentType
' IID = {6A340DC0-0311-11D3-9D8E-00C04F72D980}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IComponentType_INTERFACE_DEFINED)
    %IComponentType_INTERFACE_DEFINED = 1

INTERFACE IComponentType $IID_IComponentType

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Category <1> ( _                        ' VTable offset = 28
   ) AS COMPONENTCATEGORY_ENUM                          ' __retval_out ComponentCategory *Category
   ' =====================================================================================
   PROPERTY SET Category <1> ( _                        ' VTable offset = 32
     BYVAL Category AS COMPONENTCATEGORY_ENUM _         ' __in ComponentCategory Category
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *MediaMajorType
   ' =====================================================================================
   PROPERTY SET MediaMajorType <2> ( _                  ' VTable offset = 40
     BYVAL MediaMajorType AS WSTRING _                  ' __in BSTR MediaMajorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType_ <3> ( _                 ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *MediaMajorTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaMajorType_ <3> ( _                 ' VTable offset = 48
     BYREF IN MediaMajorTypeGuid AS GUID _              ' __in REFCLSID MediaMajorTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *MediaSubType
   ' =====================================================================================
   PROPERTY SET MediaSubType <4> ( _                    ' VTable offset = 56
     BYVAL MediaSubType AS WSTRING _                    ' __in BSTR MediaSubType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType_ <5> ( _                   ' VTable offset = 60
   ) AS GUID                                            ' __retval_out GUID *MediaSubTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaSubType_ <5> ( _                   ' VTable offset = 64
     BYREF IN MediaSubTypeGuid AS GUID _                ' __in REFCLSID MediaSubTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *MediaFormatType
   ' =====================================================================================
   PROPERTY SET MediaFormatType <6> ( _                 ' VTable offset = 72
     BYVAL MediaFormatType AS WSTRING _                 ' __in BSTR MediaFormatType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType_ <7> ( _                ' VTable offset = 76
   ) AS GUID                                            ' __retval_out GUID *MediaFormatTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaFormatType_ <7> ( _                ' VTable offset = 80
     BYREF IN MediaFormatTypeGuid AS GUID _             ' __in REFCLSID MediaFormatTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaType <8> ( _                       ' VTable offset = 84
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *MediaType
   ' =====================================================================================
   PROPERTY SET MediaType <8> ( _                       ' VTable offset = 88
     BYREF IN MediaType AS AM_MEDIA_TYPE _              ' __in AM_MEDIA_TYPE *MediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <9> ( _                                 ' VTable offset = 92
   ) AS IComponentType                                  ' __retval_out IComponentType **NewCT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComponentType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILanguageComponentType
' IID = {B874C8BA-0FA2-11D3-9D8E-00C04F72D980}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IComponentType
' ########################################################################################

#IF NOT %DEF(%ILanguageComponentType_INTERFACE_DEFINED)
    %ILanguageComponentType_INTERFACE_DEFINED = 1

INTERFACE ILanguageComponentType $IID_ILanguageComponentType

   INHERIT IDispatch

   ' =====================================================================================
   ' IComponentType Methods
   ' =====================================================================================
   PROPERTY GET Category <1> ( _                        ' VTable offset = 28
   ) AS COMPONENTCATEGORY_ENUM                          ' __retval_out ComponentCategory *Category
   ' =====================================================================================
   PROPERTY SET Category <1> ( _                        ' VTable offset = 32
     BYVAL Category AS COMPONENTCATEGORY_ENUM _         ' __in ComponentCategory Category
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *MediaMajorType
   ' =====================================================================================
   PROPERTY SET MediaMajorType <2> ( _                  ' VTable offset = 40
     BYVAL MediaMajorType AS WSTRING _                  ' __in BSTR MediaMajorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType_ <3> ( _                 ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *MediaMajorTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaMajorType_ <3> ( _                 ' VTable offset = 48
     BYREF IN MediaMajorTypeGuid AS GUID _              ' __in REFCLSID MediaMajorTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *MediaSubType
   ' =====================================================================================
   PROPERTY SET MediaSubType <4> ( _                    ' VTable offset = 56
     BYVAL MediaSubType AS WSTRING _                    ' __in BSTR MediaSubType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType_ <5> ( _                   ' VTable offset = 60
   ) AS GUID                                            ' __retval_out GUID *MediaSubTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaSubType_ <5> ( _                   ' VTable offset = 64
     BYREF IN MediaSubTypeGuid AS GUID _                ' __in REFCLSID MediaSubTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *MediaFormatType
   ' =====================================================================================
   PROPERTY SET MediaFormatType <6> ( _                 ' VTable offset = 72
     BYVAL MediaFormatType AS WSTRING _                 ' __in BSTR MediaFormatType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType_ <7> ( _                ' VTable offset = 76
   ) AS GUID                                            ' __retval_out GUID *MediaFormatTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaFormatType_ <7> ( _                ' VTable offset = 80
     BYREF IN MediaFormatTypeGuid AS GUID _             ' __in REFCLSID MediaFormatTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaType <8> ( _                       ' VTable offset = 84
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *MediaType
   ' =====================================================================================
   PROPERTY SET MediaType <8> ( _                       ' VTable offset = 88
     BYREF IN MediaType AS AM_MEDIA_TYPE _              ' __in AM_MEDIA_TYPE *MediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <9> ( _                                 ' VTable offset = 92
   ) AS IComponentType                                  ' __retval_out IComponentType **NewCT
   ' =====================================================================================

   ' =====================================================================================
   ' ILanguageComponentType Methods
   ' =====================================================================================
   PROPERTY GET LangID <100> ( _                        ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *LangID
   ' =====================================================================================
   PROPERTY SET LangID <100> ( _                        ' VTable offset = 100
     BYVAL LangID AS LONG _                             ' __in long LangID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILanguageComponentType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMPEG2ComponentType
' IID = {2C073D84-B51C-48C9-AA9F-68971E1F6E38}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILanguageComponentType
' ########################################################################################

#IF NOT %DEF(%IMPEG2ComponentType_INTERFACE_DEFINED)
    %IMPEG2ComponentType_INTERFACE_DEFINED = 1

INTERFACE IMPEG2ComponentType $IID_IMPEG2ComponentType

   INHERIT IDispatch

   ' =====================================================================================
   ' IComponentType Methods
   ' =====================================================================================
   PROPERTY GET Category <1> ( _                        ' VTable offset = 28
   ) AS COMPONENTCATEGORY_ENUM                          ' __retval_out ComponentCategory *Category
   ' =====================================================================================
   PROPERTY SET Category <1> ( _                        ' VTable offset = 32
     BYVAL Category AS COMPONENTCATEGORY_ENUM _         ' __in ComponentCategory Category
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *MediaMajorType
   ' =====================================================================================
   PROPERTY SET MediaMajorType <2> ( _                  ' VTable offset = 40
     BYVAL MediaMajorType AS WSTRING _                  ' __in BSTR MediaMajorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType_ <3> ( _                 ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *MediaMajorTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaMajorType_ <3> ( _                 ' VTable offset = 48
     BYREF IN MediaMajorTypeGuid AS GUID _              ' __in REFCLSID MediaMajorTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *MediaSubType
   ' =====================================================================================
   PROPERTY SET MediaSubType <4> ( _                    ' VTable offset = 56
     BYVAL MediaSubType AS WSTRING _                    ' __in BSTR MediaSubType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType_ <5> ( _                   ' VTable offset = 60
   ) AS GUID                                            ' __retval_out GUID *MediaSubTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaSubType_ <5> ( _                   ' VTable offset = 64
     BYREF IN MediaSubTypeGuid AS GUID _                ' __in REFCLSID MediaSubTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *MediaFormatType
   ' =====================================================================================
   PROPERTY SET MediaFormatType <6> ( _                 ' VTable offset = 72
     BYVAL MediaFormatType AS WSTRING _                 ' __in BSTR MediaFormatType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType_ <7> ( _                ' VTable offset = 76
   ) AS GUID                                            ' __retval_out GUID *MediaFormatTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaFormatType_ <7> ( _                ' VTable offset = 80
     BYREF IN MediaFormatTypeGuid AS GUID _             ' __in REFCLSID MediaFormatTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaType <8> ( _                       ' VTable offset = 84
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *MediaType
   ' =====================================================================================
   PROPERTY SET MediaType <8> ( _                       ' VTable offset = 88
     BYREF IN MediaType AS AM_MEDIA_TYPE _              ' __in AM_MEDIA_TYPE *MediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <9> ( _                                 ' VTable offset = 92
   ) AS IComponentType                                  ' __retval_out IComponentType **NewCT
   ' =====================================================================================

   ' =====================================================================================
   ' ILanguageComponentType Methods
   ' =====================================================================================
   PROPERTY GET LangID <100> ( _                        ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *LangID
   ' =====================================================================================
   PROPERTY SET LangID <100> ( _                        ' VTable offset = 100
     BYVAL LangID AS LONG _                             ' __in long LangID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMPEG2ComponentType Methods
   ' =====================================================================================
   PROPERTY GET StreamType <200> ( _                    ' VTable offset = 104
   ) AS MPEG2STREAMTYPE_ENUM                            ' __retval_out MPEG2StreamType *MP2StreamType
   ' =====================================================================================
   PROPERTY SET StreamType <200> ( _                    ' VTable offset = 108
     BYVAL MP2StreamType AS MPEG2STREAMTYPE_ENUM _      ' __in MPEG2StreamType MP2StreamType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2ComponentType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IATSCComponentType
' IID = {FC189E4D-7BD4-4125-B3B3-3A76A332CC96}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IMPEG2ComponentType
' ########################################################################################

#IF NOT %DEF(%IATSCComponentType_INTERFACE_DEFINED)
    %IATSCComponentType_INTERFACE_DEFINED = 1

INTERFACE IATSCComponentType $IID_IATSCComponentType

   INHERIT IDispatch

   ' =====================================================================================
   ' IComponentType Methods
   ' =====================================================================================
   PROPERTY GET Category <1> ( _                        ' VTable offset = 28
   ) AS COMPONENTCATEGORY_ENUM                          ' __retval_out ComponentCategory *Category
   ' =====================================================================================
   PROPERTY SET Category <1> ( _                        ' VTable offset = 32
     BYVAL Category AS COMPONENTCATEGORY_ENUM _         ' __in ComponentCategory Category
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *MediaMajorType
   ' =====================================================================================
   PROPERTY SET MediaMajorType <2> ( _                  ' VTable offset = 40
     BYVAL MediaMajorType AS WSTRING _                  ' __in BSTR MediaMajorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType_ <3> ( _                 ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *MediaMajorTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaMajorType_ <3> ( _                 ' VTable offset = 48
     BYREF IN MediaMajorTypeGuid AS GUID _              ' __in REFCLSID MediaMajorTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *MediaSubType
   ' =====================================================================================
   PROPERTY SET MediaSubType <4> ( _                    ' VTable offset = 56
     BYVAL MediaSubType AS WSTRING _                    ' __in BSTR MediaSubType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType_ <5> ( _                   ' VTable offset = 60
   ) AS GUID                                            ' __retval_out GUID *MediaSubTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaSubType_ <5> ( _                   ' VTable offset = 64
     BYREF IN MediaSubTypeGuid AS GUID _                ' __in REFCLSID MediaSubTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *MediaFormatType
   ' =====================================================================================
   PROPERTY SET MediaFormatType <6> ( _                 ' VTable offset = 72
     BYVAL MediaFormatType AS WSTRING _                 ' __in BSTR MediaFormatType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType_ <7> ( _                ' VTable offset = 76
   ) AS GUID                                            ' __retval_out GUID *MediaFormatTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaFormatType_ <7> ( _                ' VTable offset = 80
     BYREF IN MediaFormatTypeGuid AS GUID _             ' __in REFCLSID MediaFormatTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaType <8> ( _                       ' VTable offset = 84
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *MediaType
   ' =====================================================================================
   PROPERTY SET MediaType <8> ( _                       ' VTable offset = 88
     BYREF IN MediaType AS AM_MEDIA_TYPE _              ' __in AM_MEDIA_TYPE *MediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <9> ( _                                 ' VTable offset = 92
   ) AS IComponentType                                  ' __retval_out IComponentType **NewCT
   ' =====================================================================================

   ' =====================================================================================
   ' ILanguageComponentType Methods
   ' =====================================================================================
   PROPERTY GET LangID <100> ( _                        ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *LangID
   ' =====================================================================================
   PROPERTY SET LangID <100> ( _                        ' VTable offset = 100
     BYVAL LangID AS LONG _                             ' __in long LangID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMPEG2ComponentType Methods
   ' =====================================================================================
   PROPERTY GET StreamType <200> ( _                    ' VTable offset = 104
   ) AS MPEG2STREAMTYPE_ENUM                            ' __retval_out MPEG2StreamType *MP2StreamType
   ' =====================================================================================
   PROPERTY SET StreamType <200> ( _                    ' VTable offset = 108
     BYVAL MP2StreamType AS MPEG2STREAMTYPE_ENUM _      ' __in MPEG2StreamType MP2StreamType
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCComponentType Methods
   ' =====================================================================================
   PROPERTY GET Flags <300> ( _                         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *Flags
   ' =====================================================================================
   PROPERTY SET Flags <300> ( _                         ' VTable offset = 116
     BYVAL flags AS LONG _                              ' __in long flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSCComponentType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumComponentTypes
' IID = {8A674B4A-1F63-11D3-B64C-00C04F79498E}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumComponentTypes_INTERFACE_DEFINED)
    %IEnumComponentTypes_INTERFACE_DEFINED = 1

INTERFACE IEnumComponentTypes $IID_IEnumComponentTypes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IComponentType _                    ' __out IComponentType **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumComponentTypes _              ' __out IEnumComponentTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumComponentTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponentTypes
' IID = {0DC13D4A-0313-11D3-9D8E-00C04F72D980}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IComponentTypes_INTERFACE_DEFINED)
    %IComponentTypes_INTERFACE_DEFINED = 1

INTERFACE IComponentTypes $IID_IComponentTypes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppNewEnum
   ' =====================================================================================
   METHOD EnumComponentTypes <1610743810> ( _           ' VTable offset = 36
   ) AS IEnumComponentTypes                             ' __retval_out IEnumComponentTypes **ppNewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IComponentType                                  ' __retval_out IComponentType **ComponentType
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL ComponentType AS IComponentType _            ' __in IComponentType *ComponentType
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 48
     BYVAL ComponentType AS IComponentType _            ' __in IComponentType *ComponentType
   ) AS VARIANT                                         ' __retval_out VARIANT *NewIndex
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 52
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743815> ( _                        ' VTable offset = 56
   ) AS IComponentTypes                                 ' __retval_out IComponentTypes **NewList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComponentTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponent
' IID = {1A5576FC-0E19-11D3-9D8E-00C04F72D980}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IComponent_INTERFACE_DEFINED)
    %IComponent_INTERFACE_DEFINED = 1

INTERFACE IComponent $IID_IComponent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS IComponentType                                  ' __retval_out IComponentType **CT
   ' =====================================================================================
   PROPERTY SET Type ( _                                ' VTable offset = 32
     BYVAL CT AS IComponentType _                       ' __in IComponentType *CT
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DescLangID <3> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *LangID
   ' =====================================================================================
   PROPERTY SET DescLangID <3> ( _                      ' VTable offset = 40
     BYVAL LangID AS LONG _                             ' __in long LangID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <2> ( _                          ' VTable offset = 44
   ) AS COMPONENTSTATUS_ENUM                            ' __retval_out ComponentStatus *Status
   ' =====================================================================================
   PROPERTY SET Status <2> ( _                          ' VTable offset = 48
     BYVAL Status AS COMPONENTSTATUS_ENUM _             ' __in ComponentStatus Status
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <4> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY SET Description <4> ( _                     ' VTable offset = 56
     BYVAL Description AS WSTRING _                     ' __in BSTR Description
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <5> ( _                                 ' VTable offset = 60
   ) AS IComponent                                      ' __retval_out IComponent **NewComponent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComponent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalogAudioComponentType
' IID = {2CFEB2A8-1787-4A24-A941-C6EAEC39C842}
' Inherited interface = IComponentType
' ########################################################################################

#IF NOT %DEF(%IAnalogAudioComponentType_INTERFACE_DEFINED)
    %IAnalogAudioComponentType_INTERFACE_DEFINED = 1

INTERFACE IAnalogAudioComponentType $IID_IAnalogAudioComponentType

   INHERIT IDispatch

   ' =====================================================================================
   ' IComponentType Methods
   ' =====================================================================================
   PROPERTY GET Category <1> ( _                        ' VTable offset = 28
   ) AS COMPONENTCATEGORY_ENUM                          ' __retval_out ComponentCategory *Category
   ' =====================================================================================
   PROPERTY SET Category <1> ( _                        ' VTable offset = 32
     BYVAL Category AS COMPONENTCATEGORY_ENUM _         ' __in ComponentCategory Category
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType <2> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *MediaMajorType
   ' =====================================================================================
   PROPERTY SET MediaMajorType <2> ( _                  ' VTable offset = 40
     BYVAL MediaMajorType AS WSTRING _                  ' __in BSTR MediaMajorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaMajorType_ <3> ( _                 ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *MediaMajorTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaMajorType_ <3> ( _                 ' VTable offset = 48
     BYREF IN MediaMajorTypeGuid AS GUID _              ' __in REFCLSID MediaMajorTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *MediaSubType
   ' =====================================================================================
   PROPERTY SET MediaSubType <4> ( _                    ' VTable offset = 56
     BYVAL MediaSubType AS WSTRING _                    ' __in BSTR MediaSubType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaSubType_ <5> ( _                   ' VTable offset = 60
   ) AS GUID                                            ' __retval_out GUID *MediaSubTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaSubType_ <5> ( _                   ' VTable offset = 64
     BYREF IN MediaSubTypeGuid AS GUID _                ' __in REFCLSID MediaSubTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *MediaFormatType
   ' =====================================================================================
   PROPERTY SET MediaFormatType <6> ( _                 ' VTable offset = 72
     BYVAL MediaFormatType AS WSTRING _                 ' __in BSTR MediaFormatType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaFormatType_ <7> ( _                ' VTable offset = 76
   ) AS GUID                                            ' __retval_out GUID *MediaFormatTypeGuid
   ' =====================================================================================
   PROPERTY SET MediaFormatType_ <7> ( _                ' VTable offset = 80
     BYREF IN MediaFormatTypeGuid AS GUID _             ' __in REFCLSID MediaFormatTypeGuid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaType <8> ( _                       ' VTable offset = 84
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *MediaType
   ' =====================================================================================
   PROPERTY SET MediaType <8> ( _                       ' VTable offset = 88
     BYREF IN MediaType AS AM_MEDIA_TYPE _              ' __in AM_MEDIA_TYPE *MediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <9> ( _                                 ' VTable offset = 92
   ) AS IComponentType                                  ' __retval_out IComponentType **NewCT
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogAudioComponentType Methods
   ' =====================================================================================
   PROPERTY GET AnalogAudioMode <201> ( _               ' VTable offset = 96
   ) AS LONG                                            ' __retval_out TVAudioMode *Mode
   ' =====================================================================================
   PROPERTY SET AnalogAudioMode <201> ( _               ' VTable offset = 100
     BYVAL Mode AS LONG _                               ' __in TVAudioMode Mode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalogAudioComponentType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMPEG2Component
' IID = {1493E353-1EB6-473C-802D-8E6B8EC9D2A9}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IComponent
' ########################################################################################

#IF NOT %DEF(%IMPEG2Component_INTERFACE_DEFINED)
    %IMPEG2Component_INTERFACE_DEFINED = 1

INTERFACE IMPEG2Component $IID_IMPEG2Component

   INHERIT IDispatch

   ' =====================================================================================
   ' IComponent Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS IComponentType                                  ' __retval_out IComponentType **CT
   ' =====================================================================================
   PROPERTY SET Type ( _                                ' VTable offset = 32
     BYVAL CT AS IComponentType _                       ' __in IComponentType *CT
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DescLangID <3> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *LangID
   ' =====================================================================================
   PROPERTY SET DescLangID <3> ( _                      ' VTable offset = 40
     BYVAL LangID AS LONG _                             ' __in long LangID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <2> ( _                          ' VTable offset = 44
   ) AS COMPONENTSTATUS_ENUM                            ' __retval_out ComponentStatus *Status
   ' =====================================================================================
   PROPERTY SET Status <2> ( _                          ' VTable offset = 48
     BYVAL Status AS COMPONENTSTATUS_ENUM _             ' __in ComponentStatus Status
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <4> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *Description
   ' =====================================================================================
   PROPERTY SET Description <4> ( _                     ' VTable offset = 56
     BYVAL Description AS WSTRING _                     ' __in BSTR Description
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <5> ( _                                 ' VTable offset = 60
   ) AS IComponent                                      ' __retval_out IComponent **NewComponent
   ' =====================================================================================

   ' =====================================================================================
   ' IMPEG2Component Methods
   ' =====================================================================================
   PROPERTY GET PID <101> ( _                           ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *PID
   ' =====================================================================================
   PROPERTY SET PID <101> ( _                           ' VTable offset = 68
     BYVAL PID AS LONG _                                ' __in long PID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PCRPID <102> ( _                        ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *PCRPID
   ' =====================================================================================
   PROPERTY SET PCRPID <102> ( _                        ' VTable offset = 76
     BYVAL PCRPID AS LONG _                             ' __in long PCRPID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProgramNumber <103> ( _                 ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *ProgramNumber
   ' =====================================================================================
   PROPERTY SET ProgramNumber <103> ( _                 ' VTable offset = 84
     BYVAL ProgramNumber AS LONG _                      ' __in long ProgramNumber
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2Component_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumComponents
' IID = {2A6E2939-2595-11D3-B64C-00C04F79498E}
' Attributes = 528 [&H210] [Hidden] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumComponents_INTERFACE_DEFINED)
    %IEnumComponents_INTERFACE_DEFINED = 1

INTERFACE IEnumComponents $IID_IEnumComponents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IComponent _                        ' __out IComponent **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumComponents _                  ' __out IEnumComponents **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumComponents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponents
' IID = {39A48091-FFFE-4182-A161-3FF802640E26}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IComponents_INTERFACE_DEFINED)
    %IComponents_INTERFACE_DEFINED = 1

INTERFACE IComponents $IID_IComponents

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppNewEnum
   ' =====================================================================================
   METHOD EnumComponents <1610743810> ( _               ' VTable offset = 36
   ) AS IEnumComponents                                 ' __retval_out IEnumComponents **ppNewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IComponent                                      ' __retval_out IComponent **ppComponent
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 44
     BYVAL Component AS IComponent _                    ' __in IComponent *Component
   ) AS VARIANT                                         ' __retval_out VARIANT *NewIndex
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743814> ( _                        ' VTable offset = 52
   ) AS IComponents                                     ' __retval_out IComponents **NewList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComponents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComponentsOld
' IID = {FCD01846-0E19-11D3-9D8E-00C04F72D980}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IComponentsOld_INTERFACE_DEFINED)
    %IComponentsOld_INTERFACE_DEFINED = 1

INTERFACE IComponentsOld $IID_IComponentsOld

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppNewEnum
   ' =====================================================================================
   METHOD EnumComponents <1610743810> ( _               ' VTable offset = 36
   ) AS IEnumComponents                                 ' __retval_out IEnumComponents **ppNewEnum
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IComponent                                      ' __retval_out IComponent **ppComponent
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 44
     BYVAL Component AS IComponent _                    ' __in IComponent *Component
   ) AS VARIANT                                         ' __retval_out VARIANT *NewIndex
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <1610743814> ( _                        ' VTable offset = 52
   ) AS IComponents                                     ' __retval_out IComponents **NewList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComponentsOld_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILocator
' IID = {286D7F89-760C-4F89-80C4-66841D2507AA}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ILocator_INTERFACE_DEFINED)
    %ILocator_INTERFACE_DEFINED = 1

INTERFACE ILocator $IID_ILocator

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalogLocator
' IID = {34D1F26B-E339-430D-ABCE-738CB48984DC}
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IAnalogLocator_INTERFACE_DEFINED)
    %IAnalogLocator_INTERFACE_DEFINED = 1

INTERFACE IAnalogLocator $IID_IAnalogLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IAnalogLocator Methods
   ' =====================================================================================
   PROPERTY GET VideoStandard <601> ( _                 ' VTable offset = 88
   ) AS LONG                                            ' __retval_out AnalogVideoStandard *AVS
   ' =====================================================================================
   PROPERTY SET VideoStandard <601> ( _                 ' VTable offset = 92
     BYVAL AVS AS LONG _                                ' __in AnalogVideoStandard AVS
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalogLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDigitalLocator
' IID = {19B595D8-839A-47F0-96DF-4F194F3C768C}
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IDigitalLocator_INTERFACE_DEFINED)
    %IDigitalLocator_INTERFACE_DEFINED = 1

INTERFACE IDigitalLocator $IID_IDigitalLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDigitalLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IATSCLocator
' IID = {BF8D986F-8C2B-4131-94D7-4D3D9FCC21EF}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IATSCLocator_INTERFACE_DEFINED)
    %IATSCLocator_INTERFACE_DEFINED = 1

INTERFACE IATSCLocator $IID_IATSCLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCLocator Methods
   ' =====================================================================================
   PROPERTY GET PhysicalChannel <201> ( _               ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *PhysicalChannel
   ' =====================================================================================
   PROPERTY SET PhysicalChannel <201> ( _               ' VTable offset = 92
     BYVAL PhysicalChannel AS LONG _                    ' __in long PhysicalChannel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <202> ( _                          ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *TSID
   ' =====================================================================================
   PROPERTY SET TSID <202> ( _                          ' VTable offset = 100
     BYVAL TSID AS LONG _                               ' __in long TSID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSCLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IATSCLocator2
' IID = {612AA885-66CF-4090-BA0A-566F5312E4CA}
' Inherited interface = IATSCLocator
' ########################################################################################

#IF NOT %DEF(%IATSCLocator2_INTERFACE_DEFINED)
    %IATSCLocator2_INTERFACE_DEFINED = 1

INTERFACE IATSCLocator2 $IID_IATSCLocator2

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCLocator Methods
   ' =====================================================================================
   PROPERTY GET PhysicalChannel <201> ( _               ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *PhysicalChannel
   ' =====================================================================================
   PROPERTY SET PhysicalChannel <201> ( _               ' VTable offset = 92
     BYVAL PhysicalChannel AS LONG _                    ' __in long PhysicalChannel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <202> ( _                          ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *TSID
   ' =====================================================================================
   PROPERTY SET TSID <202> ( _                          ' VTable offset = 100
     BYVAL TSID AS LONG _                               ' __in long TSID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCLocator2 Methods
   ' =====================================================================================
   PROPERTY GET ProgramNumber <203> ( _                 ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *ProgramNumber
   ' =====================================================================================
   PROPERTY SET ProgramNumber <203> ( _                 ' VTable offset = 108
     BYVAL ProgramNumber AS LONG _                      ' __in long ProgramNumber
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IATSCLocator2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDigitalCableLocator
' IID = {48F66A11-171A-419A-9525-BEEECD51584C}
' Inherited interface = IATSCLocator2
' ########################################################################################

#IF NOT %DEF(%IDigitalCableLocator_INTERFACE_DEFINED)
    %IDigitalCableLocator_INTERFACE_DEFINED = 1

INTERFACE IDigitalCableLocator $IID_IDigitalCableLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCLocator Methods
   ' =====================================================================================
   PROPERTY GET PhysicalChannel <201> ( _               ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *PhysicalChannel
   ' =====================================================================================
   PROPERTY SET PhysicalChannel <201> ( _               ' VTable offset = 92
     BYVAL PhysicalChannel AS LONG _                    ' __in long PhysicalChannel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TSID <202> ( _                          ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *TSID
   ' =====================================================================================
   PROPERTY SET TSID <202> ( _                          ' VTable offset = 100
     BYVAL TSID AS LONG _                               ' __in long TSID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IATSCLocator2 Methods
   ' =====================================================================================
   PROPERTY GET ProgramNumber <203> ( _                 ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *ProgramNumber
   ' =====================================================================================
   PROPERTY SET ProgramNumber <203> ( _                 ' VTable offset = 108
     BYVAL ProgramNumber AS LONG _                      ' __in long ProgramNumber
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDigitalCableLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBTLocator
' IID = {8664DA16-DDA2-42AC-926A-C18F9127C302}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IDVBTLocator_INTERFACE_DEFINED)
    %IDVBTLocator_INTERFACE_DEFINED = 1

INTERFACE IDVBTLocator $IID_IDVBTLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTLocator Methods
   ' =====================================================================================
   PROPERTY GET Bandwidth <301> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *BandWidthVal
   ' =====================================================================================
   PROPERTY SET Bandwidth <301> ( _                     ' VTable offset = 92
     BYVAL BandwidthVal AS LONG _                       ' __in long BandwidthVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LPInnerFEC <302> ( _                    ' VTable offset = 96
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET LPInnerFEC <302> ( _                    ' VTable offset = 100
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LPInnerFECRate <303> ( _                ' VTable offset = 104
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET LPInnerFECRate <303> ( _                ' VTable offset = 108
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HAlpha <305> ( _                        ' VTable offset = 112
   ) AS HIERARCHYALPHA_ENUM                             ' __retval_out HierarchyAlpha *Alpha
   ' =====================================================================================
   PROPERTY SET HAlpha <305> ( _                        ' VTable offset = 116
     BYVAL Alpha AS HIERARCHYALPHA_ENUM _               ' __in HierarchyAlpha Alpha
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Guard <304> ( _                         ' VTable offset = 120
   ) AS GUARDINTERVAL_ENUM                              ' __retval_out GuardInterval *GI
   ' =====================================================================================
   PROPERTY SET Guard <304> ( _                         ' VTable offset = 124
     BYVAL GI AS GUARDINTERVAL_ENUM _                   ' __in GuardInterval GI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <306> ( _                          ' VTable offset = 128
   ) AS TRANSMISSIONMODE_ENUM                           ' __retval_out TransmissionMode *mode
   ' =====================================================================================
   PROPERTY SET Mode <306> ( _                          ' VTable offset = 132
     BYVAL mode AS TRANSMISSIONMODE_ENUM _              ' __in TransmissionMode mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OtherFrequencyInUse <307> ( _           ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *OtherFrequencyInUseVal
   ' =====================================================================================
   PROPERTY SET OtherFrequencyInUse <307> ( _           ' VTable offset = 140
     BYVAL OtherFrequencyInUseVal AS INTEGER _          ' __in VARIANT_BOOL OtherFrequencyInUseVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBTLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBTLocator2
' IID = {448A2EDF-AE95-4B43-A3CC-747843C453D4}
' DVB Terrestrial 2 Locator Information
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDVBTLocator
' ########################################################################################

#IF NOT %DEF(%IDVBTLocator2_INTERFACE_DEFINED)
    %IDVBTLocator2_INTERFACE_DEFINED = 1

INTERFACE IDVBTLocator2 $IID_IDVBTLocator2

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTLocator Methods
   ' =====================================================================================
   PROPERTY GET Bandwidth <301> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *BandWidthVal
   ' =====================================================================================
   PROPERTY SET Bandwidth <301> ( _                     ' VTable offset = 92
     BYVAL BandwidthVal AS LONG _                       ' __in long BandwidthVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LPInnerFEC <302> ( _                    ' VTable offset = 96
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET LPInnerFEC <302> ( _                    ' VTable offset = 100
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LPInnerFECRate <303> ( _                ' VTable offset = 104
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET LPInnerFECRate <303> ( _                ' VTable offset = 108
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HAlpha <305> ( _                        ' VTable offset = 112
   ) AS HIERARCHYALPHA_ENUM                             ' __retval_out HierarchyAlpha *Alpha
   ' =====================================================================================
   PROPERTY SET HAlpha <305> ( _                        ' VTable offset = 116
     BYVAL Alpha AS HIERARCHYALPHA_ENUM _               ' __in HierarchyAlpha Alpha
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Guard <304> ( _                         ' VTable offset = 120
   ) AS GUARDINTERVAL_ENUM                              ' __retval_out GuardInterval *GI
   ' =====================================================================================
   PROPERTY SET Guard <304> ( _                         ' VTable offset = 124
     BYVAL GI AS GUARDINTERVAL_ENUM _                   ' __in GuardInterval GI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <306> ( _                          ' VTable offset = 128
   ) AS TRANSMISSIONMODE_ENUM                           ' __retval_out TransmissionMode *mode
   ' =====================================================================================
   PROPERTY SET Mode <306> ( _                          ' VTable offset = 132
     BYVAL mode AS TRANSMISSIONMODE_ENUM _              ' __in TransmissionMode mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OtherFrequencyInUse <307> ( _           ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *OtherFrequencyInUseVal
   ' =====================================================================================
   PROPERTY SET OtherFrequencyInUse <307> ( _           ' VTable offset = 140
     BYVAL OtherFrequencyInUseVal AS INTEGER _          ' __in VARIANT_BOOL OtherFrequencyInUseVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBTLocator2 Methods
   ' =====================================================================================
   PROPERTY GET PhysicalLayerPipeId <351> ( _           ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *PhysicalLayerPipeIdVal
   ' =====================================================================================
   PROPERTY SET PhysicalLayerPipeId <351> ( _           ' VTable offset = 148
     BYVAL PhysicalLayerPipeIdVal AS LONG _             ' __in long PhysicalLayerPipeIdVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBTLocator2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBSLocator
' IID = {3D7C353C-0D04-45F1-A742-F97CC1188DC8}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IDVBSLocator_INTERFACE_DEFINED)
    %IDVBSLocator_INTERFACE_DEFINED = 1

INTERFACE IDVBSLocator $IID_IDVBSLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBSLocator Methods
   ' =====================================================================================
   PROPERTY GET SignalPolarisation <401> ( _            ' VTable offset = 88
   ) AS POLARISATION_ENUM                               ' __retval_out Polarisation *PolarisationVal
   ' =====================================================================================
   PROPERTY SET SignalPolarisation <401> ( _            ' VTable offset = 92
     BYVAL PolarisationVal AS POLARISATION_ENUM _       ' __in Polarisation PolarisationVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WestPosition <402> ( _                  ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *WestLongitude
   ' =====================================================================================
   PROPERTY SET WestPosition <402> ( _                  ' VTable offset = 100
     BYVAL WestLongitude AS INTEGER _                   ' __in VARIANT_BOOL WestLongitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OrbitalPosition <403> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *longitude
   ' =====================================================================================
   PROPERTY SET OrbitalPosition <403> ( _               ' VTable offset = 108
     BYVAL longitude AS LONG _                          ' __in long longitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Azimuth <404> ( _                       ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *Azimuth
   ' =====================================================================================
   PROPERTY SET Azimuth <404> ( _                       ' VTable offset = 116
     BYVAL Azimuth AS LONG _                            ' __in long Azimuth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Elevation <405> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *Elevation
   ' =====================================================================================
   PROPERTY SET Elevation <405> ( _                     ' VTable offset = 124
     BYVAL Elevation AS LONG _                          ' __in long Elevation
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBSLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBSLocator2
' IID = {6044634A-1733-4F99-B982-5FB12AFCE4F0}
' DVB Satellite Locator2 Information
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDVBSLocator
' ########################################################################################

#IF NOT %DEF(%IDVBSLocator2_INTERFACE_DEFINED)
    %IDVBSLocator2_INTERFACE_DEFINED = 1

INTERFACE IDVBSLocator2 $IID_IDVBSLocator2

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBSLocator Methods
   ' =====================================================================================
   PROPERTY GET SignalPolarisation <401> ( _            ' VTable offset = 88
   ) AS POLARISATION_ENUM                               ' __retval_out Polarisation *PolarisationVal
   ' =====================================================================================
   PROPERTY SET SignalPolarisation <401> ( _            ' VTable offset = 92
     BYVAL PolarisationVal AS POLARISATION_ENUM _       ' __in Polarisation PolarisationVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WestPosition <402> ( _                  ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *WestLongitude
   ' =====================================================================================
   PROPERTY SET WestPosition <402> ( _                  ' VTable offset = 100
     BYVAL WestLongitude AS INTEGER _                   ' __in VARIANT_BOOL WestLongitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OrbitalPosition <403> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *longitude
   ' =====================================================================================
   PROPERTY SET OrbitalPosition <403> ( _               ' VTable offset = 108
     BYVAL longitude AS LONG _                          ' __in long longitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Azimuth <404> ( _                       ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *Azimuth
   ' =====================================================================================
   PROPERTY SET Azimuth <404> ( _                       ' VTable offset = 116
     BYVAL Azimuth AS LONG _                            ' __in long Azimuth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Elevation <405> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *Elevation
   ' =====================================================================================
   PROPERTY SET Elevation <405> ( _                     ' VTable offset = 124
     BYVAL Elevation AS LONG _                          ' __in long Elevation
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBSLocator2 Methods
   ' =====================================================================================
   PROPERTY GET DiseqLNBSource <406> ( _                ' VTable offset = 128
   ) AS LNB_SOURCE_ENUM                                 ' __retval_out LNB_Source *DiseqLNBSourceVal
   ' =====================================================================================
   PROPERTY SET DiseqLNBSource <406> ( _                ' VTable offset = 132
     BYVAL DiseqLNBSourceVal AS LNB_SOURCE_ENUM _       ' __in LNB_Source DiseqLNBSourceVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalOscillatorOverrideLow <407> ( _    ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *LocalOscillatorOverrideLowVal
   ' =====================================================================================
   PROPERTY SET LocalOscillatorOverrideLow <407> ( _    ' VTable offset = 140
     BYVAL LocalOscillatorOverrideLowVal AS LONG _      ' __in long LocalOscillatorOverrideLowVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalOscillatorOverrideHigh <408> ( _   ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *LocalOscillatorOverrideHighVal
   ' =====================================================================================
   PROPERTY SET LocalOscillatorOverrideHigh <408> ( _   ' VTable offset = 148
     BYVAL LocalOscillatorOverrideHighVal AS LONG _     ' __in long LocalOscillatorOverrideHighVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalLNBSwitchOverride <409> ( _        ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *LocalLNBSwitchOverrideVal
   ' =====================================================================================
   PROPERTY SET LocalLNBSwitchOverride <409> ( _        ' VTable offset = 156
     BYVAL LocalLNBSwitchOverrideVal AS LONG _          ' __in long LocalLNBSwitchOverrideVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalSpectralInversionOverride <410> ( _  ' VTable offset = 160
   ) AS SPECTRALINVERSION_ENUM                          ' __retval_out SpectralInversion *LocalSpectralInversionOverrideVal
   ' =====================================================================================
   PROPERTY SET LocalSpectralInversionOverride <410> ( _  ' VTable offset = 164
     BYVAL LocalSpectralInversionOverrideVal AS SPECTRALINVERSION_ENUM _ ' __in SpectralInversion LocalSpectralInversionOverrideVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignalRollOff <411> ( _                 ' VTable offset = 168
   ) AS ROLLOFF_ENUM                                    ' __retval_out RollOff *RollOffVal
   ' =====================================================================================
   PROPERTY SET SignalRollOff <411> ( _                 ' VTable offset = 172
     BYVAL RollOffVal AS ROLLOFF_ENUM _                 ' __in RollOff RollOffVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SignalPilot <412> ( _                   ' VTable offset = 176
   ) AS PILOT_ENUM                                      ' __retval_out Pilot *PilotVal
   ' =====================================================================================
   PROPERTY SET SignalPilot <412> ( _                   ' VTable offset = 180
     BYVAL PilotVal AS PILOT_ENUM _                     ' __in Pilot PilotVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBSLocator2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDVBCLocator
' IID = {6E42F36E-1DD2-43C4-9F78-69D25AE39034}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ILocator
' ########################################################################################

#IF NOT %DEF(%IDVBCLocator_INTERFACE_DEFINED)
    %IDVBCLocator_INTERFACE_DEFINED = 1

INTERFACE IDVBCLocator $IID_IDVBCLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Frequency
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in long Frequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out FECMethod *FEC
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FECMethod FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out BinaryConvolutionCodeRate *FEC
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in BinaryConvolutionCodeRate FEC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out ModulationType *Modulation
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in ModulationType Modulation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *Rate
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out ILocator **NewLocator
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVBCLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IISDBSLocator
' IID = {C9897087-E29C-473F-9E4B-7072123DEA14}
' ISDB Satellite Locator Information
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDVBSLocator
' ########################################################################################

#IF NOT %DEF(%IISDBSLocator_INTERFACE_DEFINED)
    %IISDBSLocator_INTERFACE_DEFINED = 1

INTERFACE IISDBSLocator $IID_IISDBSLocator

   INHERIT IDispatch

   ' =====================================================================================
   ' ILocator Methods
   ' =====================================================================================
   PROPERTY GET CarrierFrequency <1> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *Frequency VT_I4 <Long>
   ' =====================================================================================
   PROPERTY SET CarrierFrequency <1> ( _                ' VTable offset = 32
     BYVAL Frequency AS LONG _                          ' __in Frequency VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFEC <2> ( _                        ' VTable offset = 36
   ) AS FECMETHOD_ENUM                                  ' __retval_out *FEC FECMethod <enum>
   ' =====================================================================================
   PROPERTY SET InnerFEC <2> ( _                        ' VTable offset = 40
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FEC FECMethod <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InnerFECRate <3> ( _                    ' VTable offset = 44
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out *FEC BinaryConvolutionCodeRate <enum>
   ' =====================================================================================
   PROPERTY SET InnerFECRate <3> ( _                    ' VTable offset = 48
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in FEC BinaryConvolutionCodeRate <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFEC <4> ( _                        ' VTable offset = 52
   ) AS FECMETHOD_ENUM                                  ' __retval_out *FEC FECMethod <enum>
   ' =====================================================================================
   PROPERTY SET OuterFEC <4> ( _                        ' VTable offset = 56
     BYVAL FEC AS FECMETHOD_ENUM _                      ' __in FEC FECMethod <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OuterFECRate <5> ( _                    ' VTable offset = 60
   ) AS BINARYCONVOLUTIONCODERATE_ENUM                  ' __retval_out *FEC BinaryConvolutionCodeRate <enum>
   ' =====================================================================================
   PROPERTY SET OuterFECRate <5> ( _                    ' VTable offset = 64
     BYVAL FEC AS BINARYCONVOLUTIONCODERATE_ENUM _      ' __in FEC BinaryConvolutionCodeRate <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Modulation <6> ( _                      ' VTable offset = 68
   ) AS MODULATIONTYPE_ENUM                             ' __retval_out *Modulation ModulationType <enum>
   ' =====================================================================================
   PROPERTY SET Modulation <6> ( _                      ' VTable offset = 72
     BYVAL Modulation AS MODULATIONTYPE_ENUM _          ' __in Modulation ModulationType <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SymbolRate <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out *Rate VT_I4 <Long>
   ' =====================================================================================
   PROPERTY SET SymbolRate <7> ( _                      ' VTable offset = 80
     BYVAL Rate AS LONG _                               ' __in Rate VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <8> ( _                                 ' VTable offset = 84
   ) AS ILocator                                        ' __retval_out **NewLocator ILocator <dispinterface>
   ' =====================================================================================

   ' =====================================================================================
   ' IDVBSLocator Methods
   ' =====================================================================================
   PROPERTY GET SignalPolarisation <401> ( _            ' VTable offset = 88
   ) AS POLARISATION_ENUM                               ' __retval_out *PolarisationVal Polarisation <enum>
   ' =====================================================================================
   PROPERTY SET SignalPolarisation <401> ( _            ' VTable offset = 92
     BYVAL PolarisationVal AS POLARISATION_ENUM _       ' __in PolarisationVal Polarisation <enum>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WestPosition <402> ( _                  ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out *WestLongitude VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY SET WestPosition <402> ( _                  ' VTable offset = 100
     BYVAL WestLongitude AS INTEGER _                   ' __in WestLongitude VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OrbitalPosition <403> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out *longitude VT_I4 <Long>
   ' =====================================================================================
   PROPERTY SET OrbitalPosition <403> ( _               ' VTable offset = 108
     BYVAL longitude AS LONG _                          ' __in longitude VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Azimuth <404> ( _                       ' VTable offset = 112
   ) AS LONG                                            ' __retval_out *Azimuth VT_I4 <Long>
   ' =====================================================================================
   PROPERTY SET Azimuth <404> ( _                       ' VTable offset = 116
     BYVAL Azimuth AS LONG _                            ' __in Azimuth VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Elevation <405> ( _                     ' VTable offset = 120
   ) AS LONG                                            ' __retval_out *Elevation VT_I4 <Long>
   ' =====================================================================================
   PROPERTY SET Elevation <405> ( _                     ' VTable offset = 124
     BYVAL Elevation AS LONG _                          ' __in Elevation VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IISDBSLocator Methods
   ' =====================================================================================

   ' This interface has not additional methods

END INTERFACE

#ENDIF   ' /* __IISDBSLocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESEvent
' IID = {1F0E5357-AF43-44E6-8547-654C645145D2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IESEvent_INTERFACE_DEFINED)
    %IESEvent_INTERFACE_DEFINED = 1

INTERFACE IESEvent $IID_IESEvent

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESOpenMmiEvent
' IID = {BA4B6526-1A35-4635-8B56-3EC612746A8C}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESOpenMmiEvent_INTERFACE_DEFINED)
    %IESOpenMmiEvent_INTERFACE_DEFINED = 1

INTERFACE IESOpenMmiEvent $IID_IESOpenMmiEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESOpenMmiEvent Methods
   ' =====================================================================================
   METHOD GetDialogNumber ( _                           ' VTable offset = 32
     BYREF pDialogRequest AS DWORD _                    ' __out DWORD *pDialogRequest
   ) AS DWORD                                           ' __retval_out DWORD *pDialogNumber
   ' =====================================================================================
   METHOD GetDialogType ( _                             ' VTable offset = 36
   ) AS GUID                                            ' __retval_out GUID *guidDialogType
   ' =====================================================================================
   METHOD GetDialogData ( _                             ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pbData
   ' =====================================================================================
   METHOD GetDialogStringData ( _                       ' VTable offset = 44
     BYREF pbstrBaseUrl AS WSTRING _                    ' __out BSTR *pbstrBaseUrl
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESOpenMmiEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESCloseMmiEvent
' IID = {6B80E96F-55E2-45AA-B754-0C23C8E7D5C1}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESCloseMmiEvent_INTERFACE_DEFINED)
    %IESCloseMmiEvent_INTERFACE_DEFINED = 1

INTERFACE IESCloseMmiEvent $IID_IESCloseMmiEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESCloseMmiEvent Methods
   ' =====================================================================================
   METHOD GetDialogNumber ( _                           ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out DWORD *pDialogNumbe
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESCloseMmiEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESValueUpdatedEvent
' IID = {8A24C46E-BB63-4664-8602-5D9C718C146D}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESValueUpdatedEvent_INTERFACE_DEFINED)
    %IESValueUpdatedEvent_INTERFACE_DEFINED = 1

INTERFACE IESValueUpdatedEvent $IID_IESValueUpdatedEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESValueUpdatedEvent Methods
   ' =====================================================================================
   METHOD GetValueNames ( _                             ' VTable offset = 32
   ) AS DWORD                                          ' __retval_out SAFEARRAY * *pbstrNames
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESValueUpdatedEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESRequestTunerEvent
' IID = {54C7A5E8-C3BB-4F51-AF14-E0E2C0E34C6D}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESRequestTunerEvent_INTERFACE_DEFINED)
    %IESRequestTunerEvent_INTERFACE_DEFINED = 1

INTERFACE IESRequestTunerEvent $IID_IESRequestTunerEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESRequestTunerEvent Methods
   ' =====================================================================================
   METHOD GetPriority ( _                              ' VTable offset = 32
   ) AS DWORD                                          ' __retval_out BYTE *pbyPriority
   ' =====================================================================================
   METHOD GetReason ( _                                ' VTable offset = 36
   ) AS DWORD                                          ' __retval_out BYTE *pbyReason
   ' =====================================================================================
   METHOD GetConsequences ( _                          ' VTable offset = 40
   ) AS DWORD                                          ' __retval_out BYTE *pbyConsequences
   ' =====================================================================================
   METHOD GetEstimatedTime ( _                         ' VTable offset = 44
   ) AS DWORD                                          ' __retval_out DWORD *pdwEstimatedTime
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESRequestTunerEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESIsdbCasResponseEvent
' IID = {2017CB03-DC0F-4C24-83CA-36307B2CD19F}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESIsdbCasResponseEvent_INTERFACE_DEFINED)
    %IESIsdbCasResponseEvent_INTERFACE_DEFINED = 1

INTERFACE IESIsdbCasResponseEvent $IID_IESIsdbCasResponseEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESIsdbCasResponseEvent Methods
   ' =====================================================================================
   METHOD GetRequestId ( _                             ' VTable offset = 32
   ) AS DWORD                                          ' __retval_out DWORD *pRequestId
   ' =====================================================================================
   METHOD GetStatus ( _                                ' VTable offset = 36
   ) AS DWORD                                          ' __retval_out DWORD *pStatus
   ' =====================================================================================
   METHOD GetDataLength ( _                            ' VTable offset = 36
   ) AS DWORD                                          ' __retval_out DWORD *pRequestLength
   ' =====================================================================================
   METHOD GetResponseData ( _                          ' VTable offset = 40
   ) AS DWORD                                          ' __retval_out SAFEARRAY * *pbData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESIsdbCasResponseEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGpnvsCommonBase
' IID = {907E0B5C-E42D-4F04-91F0-26F401F36907}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGpnvsCommonBase_INTERFACE_DEFINED)
    %IGpnvsCommonBase_INTERFACE_DEFINED = 1

INTERFACE IGpnvsCommonBase $IID_IGpnvsCommonBase

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetValueUpdateName ( _                       ' VTable offset = 12
   ) AS DWORD                                          ' __retval_out BSTR *pbstrName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGpnvsCommonBase_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESEventFactory
' IID = {506A09B8-7F86-4E04-AC05-3303BFE8FC49}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IESEventFactory_INTERFACE_DEFINED)
    %IESEventFactory_INTERFACE_DEFINED = 1

INTERFACE IESEventFactory $IID_IESEventFactory

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateESEvent ( _                             ' VTable offset = 12
     BYVAL pServiceProvider AS IUnknown _               ' __in IUnknown *pServiceProvider
   , BYVAL dwEventId AS DWORD _                         ' __in DWORD dwEventId
   , BYVAL guidEventType AS GUID _                      ' __in GUID guidEventType
   , BYVAL dwEventDataLength AS DWORD _                 ' __in DWORD dwEventDataLength
   , BYREF pEventData AS BYTE _                         ' __in BYTE *pEventData
   , BYVAL bstrBaseUrl AS WSTRING _                     ' __in BSTR bstrBaseUrl
   , BYVAL pInitContext AS IUnknown _                   ' __in IUnknown *pInitContext
   ) AS IESEvent                                        ' __retval_out IESEvent **ppESEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESEventFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESLicenseRenewalResultEvent
' IID = {D5A48EF5-A81B-4DF0-ACAA-5E35E7EA45D4}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESLicenseRenewalResultEvent_INTERFACE_DEFINED)
    %IESLicenseRenewalResultEvent_INTERFACE_DEFINED = 1

INTERFACE IESLicenseRenewalResultEvent $IID_IESLicenseRenewalResultEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESLicenseRenewalResultEvent Methods
   ' =====================================================================================
   METHOD GetCallersId ( _                             ' VTable offset = 32
   ) AS DWORD                                          ' __retval_out DWORD *pdwCallersId
   ' =====================================================================================
   METHOD GetFileName ( _                              ' VTable offset = 36
   ) AS DWORD                                          ' __retval_out BSTR *pbstrFilename
   ' =====================================================================================
   METHOD IsRenewalSuccessful ( _                      ' VTable offset = 40
   ) AS LONG                                           ' __retval_out BOOL *pfRenewalSuccessful
   ' =====================================================================================
   METHOD IsCheckEntitlementCallRequired ( _           ' VTable offset = 44
   ) AS LONG                                           ' __retval_out BOOL *pfCheckEntTokenCallNeeded
   ' =====================================================================================
   METHOD GetDescrambledStatus ( _                     ' VTable offset = 48
   ) AS DWORD                                          ' __retval_out DWORD *pDescrambledStatus
   ' =====================================================================================
   METHOD GetRenewalResultCode ( _                     ' VTable offset = 52
   ) AS DWORD                                          ' __retval_out DWORD *pdwRenewalResultCode
   ' =====================================================================================
   METHOD GetCASFailureCode ( _                        ' VTable offset = 56
   ) AS DWORD                                          ' __retval_out DWORD *pdwCASFailureCode
   ' =====================================================================================
   METHOD GetRenewalHResult ( _                        ' VTable offset = 60
   ) AS LONG                                           ' __retval_out HRESULT *phr
   ' =====================================================================================
   METHOD GetEntitlementTokenLength ( _                ' VTable offset = 64
   ) AS DWORD                                          ' __retval_out DWORD *pdwLength
   ' =====================================================================================
   METHOD GetEntitlementToken ( _                      ' VTable offset = 68
   ) AS DWORD                                          ' __retval_out SAFEARRAY * *pbData
   ' =====================================================================================
   METHOD GetExpiryDate ( _                            ' VTable offset = 72
   ) AS QUAD                                           ' __retval_out DWORD64 *pqwExpiryDate
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESLicenseRenewalResultEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESFileExpiryDateEvent
' IID = {BA9EDCB6-4D36-4CFE-8C56-87A6B0CA48E1}
' Inherited interface = IESEvent
' ########################################################################################

#IF NOT %DEF(%IESFileExpiryDateEvent_INTERFACE_DEFINED)
    %IESFileExpiryDateEvent_INTERFACE_DEFINED = 1

INTERFACE IESFileExpiryDateEvent $IID_IESFileExpiryDateEvent

   INHERIT IAutomation

   ' =====================================================================================
   ' IESEvent Methods
   ' =====================================================================================
   METHOD GetEventId ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pdwEventId
   ' =====================================================================================
   METHOD GetEventType ( _                              ' VTable offset = 16
   ) AS GUID                                            ' __retval_out GUID *pguidEventType
   ' =====================================================================================
   METHOD SetCompletionStatus ( _                       ' VTable offset = 20
     BYVAL dwResult AS DWORD _                          ' __in DWORD dwResult
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pbData
   ' =====================================================================================
   METHOD GetStringData ( _                             ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================

   ' =====================================================================================
   ' IESFileExpiryDateEvent Methods
   ' =====================================================================================
   METHOD GetTunerId ( _                               ' VTable offset = 32
   ) AS GUID                                           ' __retval_out GUID *pguidTunerId
   ' =====================================================================================
   METHOD GetExpiryDate ( _                            ' VTable offset = 36
   ) AS QUAD                                           ' __retval_out DWORD64 *pqwExpiryDate
   ' =====================================================================================
   METHOD GetFinalExpiryDate ( _                       ' VTable offset = 40
   ) AS QUAD                                           ' __retval_out DWORD64 *pqwExpiryDate
   ' =====================================================================================
   METHOD GetMaxRenewalCount ( _                       ' VTable offset = 44
   ) AS DWORD                                          ' __retval_out DWORD *dwMaxRenewalCount
   ' =====================================================================================
   METHOD IsEntitlementTokenPresent ( _                ' VTable offset = 48
   ) AS LONG                                           ' __retval_out BOOL *pfEntTokenPresent
   ' =====================================================================================
   METHOD DoesExpireAfterFirstUse ( _                  ' VTable offset = 52
   ) AS LONG                                           ' __retval_out BOOL *pfExpireAfterFirstUse
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESFileExpiryDateEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESEvents
' IID = {ABD414BF-CFE5-4E5E-AF5B-4B4E49C5BFEB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IESEvents_INTERFACE_DEFINED)
    %IESEvents_INTERFACE_DEFINED = 1

INTERFACE IESEvents $IID_IESEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnESEventReceived ( _                         ' VTable offset = 12
     BYVAL guidEventType AS GUID _                      ' __in GUID guidEventType
   , BYVAL pESEvent AS IESEvent _                       ' __in IESEvent *pESEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESEventService
' IID = {ED89A619-4C06-4B2F-99EB-C7669B13047C}
' Extensible eventing service interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IESEventService_INTERFACE_DEFINED)
    %IESEventService_INTERFACE_DEFINED = 1

INTERFACE IESEventService $IID_IESEventService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FireESEvent ( _                               ' VTable offset = 12
     BYVAL pESEvent AS IESEvent _                       ' __in IESEvent *pESEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESEventService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IESEventServiceConfiguration
' IID = {33B9DAAE-9309-491D-A051-BCAD2A70CD66}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IESEventServiceConfiguration_INTERFACE_DEFINED)
    %IESEventServiceConfiguration_INTERFACE_DEFINED = 1

INTERFACE IESEventServiceConfiguration $IID_IESEventServiceConfiguration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetParent ( _                                 ' VTable offset = 12
     BYVAL pEventService AS IESEventService _           ' __in IESEventService *pEventService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveParent ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOwner ( _                                  ' VTable offset = 20
     BYVAL pESEvents AS IESEvents _                     ' __in IESEvents *pESEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveOwner ( _                               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGraph ( _                                  ' VTable offset = 28
     BYVAL pGraph AS IFilterGraph _                     ' __in IFilterGraph *pGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveGraph ( _                               ' VTable offset = 32
     BYVAL pGraph AS IFilterGraph _                     ' __in IFilterGraph *pGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IESEventServiceConfiguration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBroadcastEvent
' IID = {3B21263F-26E8-489D-AAC4-924F7EFD9511}
' Attributes = 144 [&H90] [Hidden] [Nonextensible]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBroadcastEvent_INTERFACE_DEFINED)
    %IBroadcastEvent_INTERFACE_DEFINED = 1

INTERFACE IBroadcastEvent $IID_IBroadcastEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Fire ( _                                      ' VTable offset = 12
     BYVAL EventID AS GUID _                            ' __in GUID EventID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBroadcastEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBroadcastEventEx
' IID = {3D9E3887-1929-423F-8021-43682DE95448}
' Inherited interface = IBroadcastEvent
' ########################################################################################

#IF NOT %DEF(%IBroadcastEventEx_INTERFACE_DEFINED)
    %IBroadcastEventEx_INTERFACE_DEFINED = 1

$IID_IBroadcastEventEx = GUID$("{3D9E3887-1929-423F-8021-43682DE95448}")

INTERFACE IBroadcastEventEx $IID_IBroadcastEventEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IBroadcastEvent Method
   ' =====================================================================================
   METHOD Fire ( _                                      ' VTable offset = 12
     BYVAL EventID AS GUID _                            ' __in GUID EventID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBroadcastEventEx Method
   ' =====================================================================================
   METHOD FireEx ( _                                    ' VTable offset = 12
     BYVAL EventID AS GUID _                            ' __in GUID EventID
   , BYVAL Param1 AS DWORD _                            ' __in ULONG Param1
   , BYVAL Param2 AS DWORD _                            ' __in ULONG Param2
   , BYVAL Param3 AS DWORD _                            ' __in ULONG Param3
   , BYVAL Param4 AS DWORD _                            ' __in ULONG Param4
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBroadcastEventEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegisterTuner
' IID = {359B3901-572C-4854-BB49-CDEF66606A25}
' Attributes = 144 [&H90] [Hidden] [Nonextensible]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRegisterTuner_INTERFACE_DEFINED)
    %IRegisterTuner_INTERFACE_DEFINED = 1

INTERFACE IRegisterTuner $IID_IRegisterTuner

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL pTuner AS ITuner _                           ' __in ITuner *pTuner
   , BYVAL pGraph AS IGraphBuilder _                    ' __in  IGraphBuilder *pGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unregister ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegisterTuner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBDAComparable
' IID = {B34505E0-2F0E-497B-80BC-D43F3B24ED7F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDAComparable_INTERFACE_DEFINED)
    %IBDAComparable_INTERFACE_DEFINED = 1

INTERFACE IBDAComparable $IID_IBDAComparable

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CompareExact ( _                              ' VTable offset = 12
     BYVAL CompareTo AS IDispatch _                     ' __in IDispatch *CompareTo
   ) AS LONG                                            ' __retval_out long *Result
   ' =====================================================================================
   METHOD CompareEquivalent ( _                         ' VTable offset = 16
     BYVAL CompareTo AS IDispatch _                     ' __in IDispatch *CompareTo
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' __retval_out long *Result
   ' =====================================================================================
   METHOD HashExact ( _                                 ' VTable offset = 20
   ) AS QUAD                                            ' __retval_out __int64 *Result
   ' =====================================================================================
   METHOD HashExactIncremental ( _                      ' VTable offset = 24
     BYVAL PartialResult AS QUAD _                      ' __in __int64 PartialResult
   ) AS QUAD                                            ' __retval_out __int64 *Result
   ' =====================================================================================
   METHOD HashEquivalent ( _                            ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS QUAD                                            ' __retval_out __int64 *Result
   ' =====================================================================================
   METHOD HashEquivalentIncremental ( _                 ' VTable offset = 32
     BYVAL PartialResult AS QUAD _                      ' __in __int64 PartialResult
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS QUAD                                            ' __retval_out __int64 *Result
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDAComparable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPersistTuneXml
' IID = {0754CD31-8D15-47A9-8215-D20064157244}
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistTuneXml_INTERFACE_DEFINED)
    %IPersistTuneXml_INTERFACE_DEFINED = 1

INTERFACE IPersistTuneXml $IID_IPersistTuneXml

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistTuneXml methods
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYREF pvarFragment AS VARIANT _                    ' __in VARIANT pvarFragment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistTuneXml_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPersistTuneXmlUtility
' IID = {990237AE-AC11-4614-BE8F-DD217A4CB4CB}
' Attributes = 144 [&H90] [Hidden] [Nonextensible]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPersistTuneXmlUtility_INTERFACE_DEFINED)
    %IPersistTuneXmlUtility_INTERFACE_DEFINED = 1

INTERFACE IPersistTuneXmlUtility $IID_IPersistTuneXmlUtility

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Deserialize ( _                               ' VTable offset = 12
     BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS IUnknown                                        ' __retval_out IUnknown **ppObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistTuneXmlUtility_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPersistTuneXmlUtility2
' IID = {992E165F-EA24-4B2F-9A1D-009D92120451}
' IPersistTuneXmlUtility2 Interface
' Attributes = 144 [&H90] [Hidden] [Nonextensible]
' Inherited interface = IPersistTuneXmlUtility
' ########################################################################################

#IF NOT %DEF(%IPersistTuneXmlUtility2_INTERFACE_DEFINED)
    %IPersistTuneXmlUtility2_INTERFACE_DEFINED = 1

INTERFACE IPersistTuneXmlUtility2 $IID_IPersistTuneXmlUtility2

   INHERIT IAutomation

   ' =====================================================================================
   ' IPersistTuneXmlUtility Methods
   ' =====================================================================================
   METHOD Deserialize ( _                               ' VTable offset = 12
     BYVAL varValue AS VARIANT _                        ' __in VARIANT varValue
   ) AS IUnknown                                        ' __retval_out IUnknown **ppObject
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistTuneXmlUtility2 Methods
   ' =====================================================================================
   METHOD Serialize ( _                                 ' VTable offset = 16
     BYVAL piTuneRequest AS ITuneRequest _              ' __in ITuneRequest *piTuneRequest
   ) AS WSTRING                                         ' __retval_out BSTR *pString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistTuneXmlUtility2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBDACreateTuneRequestEx
' IID = {C0A4A1D4-2B3C-491A-BA22-499FBADD4D12}
' BDA Create Tune RequestEx interface, implemented by Tuning Spaces
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBDACreateTuneRequestEx_INTERFACE_DEFINED)
    %IBDACreateTuneRequestEx_INTERFACE_DEFINED = 1

INTERFACE IBDACreateTuneRequestEx $IID_IBDACreateTuneRequestEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateTuneRequestEx ( _                       ' VTable offset = 12
     BYREF TuneRequestIID AS GUID _                     ' __in REFCLSID *TuneRequestIID
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **TuneRequest
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBDACreateTuneRequestEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CIESEvents
' Interface name = IESEvents
' IID = {ABD414BF-CFE5-4E5E-AF5B-4B4E49C5BFEB}
' Eventing out-going client interface
' ########################################################################################

'CLASS CIESEvents GUID$("{61BA54F7-249D-4A2F-8360-9DF5AC666D62}")

'INTERFACE IESEventsImpl GUID$("{ABD414BF-CFE5-4E5E-AF5B-4B4E49C5BFEB}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD OnESEventReceived ( _
'     BYVAL guidEventType AS GUID _                      ' __in GUID guidEventType
'   , BYVAL pESEvent AS IESEvent _                       ' __in IESEvent *pESEvent
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
