' ########################################################################################
' Microsoft Windows
' File: sapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SpeechLib
' Version: 5.4
' Documentation string: Microsoft Speech Object Library
' Path: C:\Windows\System32\Speech\Common\sapi.dll
' Library GUID: {C866CA3A-32F7-11D2-9602-00C04F8EE628}
' ########################################################################################

#INCLUDE THIS ONCE
%SAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mmsystem.inc"
#INCLUDE ONCE "sperror.inc"

$LIBID_SpeechLib = GUID$("{C866CA3A-32F7-11D2-9602-00C04F8EE628}")

'#ifndef _SAPI_VER
'// Use SAPI 5.4 by default if target Windows 7
'#if _WIN32_WINNT >= 0x0601
'#define _SAPI_VER 0x054
'#elif _WIN32_WINNT >= 0x0600
'#define _SAPI_VER 0x053
'#else // _WIN32_WINNT < 0x0600
'#define _SAPI_VER 0x051
'#endif // _WIN32_WINNT >= 0x0601
'#endif // _SAPI_VER

#IF NOT %DEF(%SAPI_VER)
   '// Use SAPI 5.4 by default if target Windows 7
   #IF %WIN32_WINNT >= &H0601
      %SAPI_VER = &H054
   #ELSEIF %WIN32_WINNT >= &H0600
      %SAPI_VER = &H053
   #ELSE   ' // _WIN32_WINNT < 0x0600
      %SAPI_VER = &H051
   #ENDIF   ' // _WIN32_WINNT >= 0x0601
#ENDIF   ' // _SAPI_VER

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {9EF96870-E160-4792-820D-48CF0649E4EC}
$PROGID_SpAudioFormat1 = "SAPI.SpAudioFormat.1"
' CLSID = {90903716-2F42-11D3-9C26-00C04F8EF87C}
$PROGID_SpCompressedLexicon1 = "SAPI.SpCompressedLexicon.1"
' CLSID = {8DBEF13F-1948-4AA8-8CF0-048EEBED95D8}
$PROGID_SpCustomStream1 = "SAPI.SpCustomStream.1"
' CLSID = {947812B3-2AE1-4644-BA86-9E90DED7EC91}
$PROGID_SpFileStream1 = "SAPI.SpFileStream.1"
' CLSID = {73AD6842-ACE0-45E8-A4DD-8795881A2C2A}
$PROGID_SpInProcRecoContext1 = "SAPI.SpInProcRecoContext.1"
' CLSID = {41B89B6B-9399-11D2-9623-00C04F8EE628}
$PROGID_SpInprocRecognizer1 = "Sapi.SpInprocRecognizer.1"
' CLSID = {0655E396-25D0-11D3-9C26-00C04F8EF87C}
$PROGID_SpLexicon1 = "SAPI.SpLexicon.1"
' CLSID = {5FB7EF7D-DFF4-468A-B6B7-2FCBD188F994}
$PROGID_SpMemoryStream1 = "SAPI.SpMemoryStream.1"
' CLSID = {AB1890A0-E91F-11D2-BB91-00C04F8EE6C0}
$PROGID_SpMMAudioEnum1 = "SAPI.SpMMAudioEnum.1"
' CLSID = {CF3D2E50-53F2-11D2-960C-00C04F8EE628}
$PROGID_SpMMAudioIn1 = "SAPI.SpMMAudioIn.1"
' CLSID = {A8C680EB-3D32-11D2-9EE7-00C04F797396}
$PROGID_SpMMAudioOut1 = "SAPI.SpMMAudioOut.1"
' CLSID = {E2AE5372-5D40-11D2-960E-00C04F8EE628}
$PROGID_SpNotifyTranslator1 = "SAPI.SpNotifyTranslator.1"
' CLSID = {455F24E9-7396-4A16-9715-7C0FDBE3EFE3}
$PROGID_SpNullPhoneConverter1 = "SAPI.SpNullPhoneConverter.1"
' CLSID = {EF411752-3736-4CB4-9C8C-8EF4CCB58EFE}
$PROGID_SpObjectToken1 = "SAPI.SpObjectToken.1"
' CLSID = {A910187F-0C7A-45AC-92CC-59EDAFB77B53}
$PROGID_SpObjectTokenCategory1 = "SAPI.SpObjectTokenCategory.1"
' CLSID = {9185F743-1143-4C28-86B5-BFF14F20E5C8}
$PROGID_SpPhoneConverter1 = "SAPI.SpPhoneConverter.1"
' CLSID = {C23FC28D-C55F-4720-8B32-91F73C2BD5D1}
$PROGID_SpPhraseInfoBuilder1 = "SAPI.SpPhraseInfoBuilder.1"
' CLSID = {96749373-3391-11D2-9EE3-00C04F797396}
$PROGID_SpResourceManager1 = "SAPI.SpResourceManager.1"
' CLSID = {47206204-5ECA-11D2-960F-00C04F8EE628}
$PROGID_SpSharedRecoContext1 = "SAPI.SpSharedRecoContext.1"
' CLSID = {3BEE4890-4FE9-4A37-8C1E-5E7E12791C1F}
$PROGID_SpSharedRecognizer1 = "Sapi.SpSharedRecognizer.1"
' CLSID = {0D722F1A-9FCF-4E62-96D8-6DF8F01A26AA}
$PROGID_SpShortcut1 = "SAPI.SpShortcut.1"
' CLSID = {715D9C59-4442-11D2-9605-00C04F8EE628}
$PROGID_SpStream1 = "SAPI.SpStream.1"
' CLSID = {7013943A-E2EC-11D2-A086-00C04F8EF9B5}
$PROGID_SpStreamFormatConverter1 = "SAPI.SpStreamFormatConverter.1"
' CLSID = {0F92030A-CBFD-4AB8-A164-FF5985547FF6}
$PROGID_SpTextSelectionInformation1 = "SAPI.SpTextSelectionInformation.1"
' CLSID = {C9E37C15-DF92-4727-85D6-72E5EEB6995A}
$PROGID_SpUnCompressedLexicon1 = "SAPI.SpUncompressedLexicon.1"
' CLSID = {96749377-3391-11D2-9EE3-00C04F797396}
$PROGID_SpVoice1 = "SAPI.SpVoice.1"
' CLSID = {C79A574C-63BE-44B9-801F-283F87F898BE}
$PROGID_SpWaveFormatEx1 = "SAPI.SpWaveFormatEx.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {9EF96870-E160-4792-820D-48CF0649E4EC}
$PROGID_SpAudioFormat = "SAPI.SpAudioFormat"
' CLSID = {90903716-2F42-11D3-9C26-00C04F8EF87C}
$PROGID_SpCompressedLexicon = "SAPI.SpCompressedLexicon"
' CLSID = {8DBEF13F-1948-4AA8-8CF0-048EEBED95D8}
$PROGID_SpCustomStream = "SAPI.SpCustomStream"
' CLSID = {947812B3-2AE1-4644-BA86-9E90DED7EC91}
$PROGID_SpFileStream = "SAPI.SpFileStream"
' CLSID = {73AD6842-ACE0-45E8-A4DD-8795881A2C2A}
$PROGID_SpInProcRecoContext = "SAPI.SpInProcRecoContext"
' CLSID = {41B89B6B-9399-11D2-9623-00C04F8EE628}
$PROGID_SpInprocRecognizer = "Sapi.SpInprocRecognizer"
' CLSID = {0655E396-25D0-11D3-9C26-00C04F8EF87C}
$PROGID_SpLexicon = "SAPI.SpLexicon"
' CLSID = {5FB7EF7D-DFF4-468A-B6B7-2FCBD188F994}
$PROGID_SpMemoryStream = "SAPI.SpMemoryStream"
' CLSID = {AB1890A0-E91F-11D2-BB91-00C04F8EE6C0}
$PROGID_SpMMAudioEnum = "SAPI.SpMMAudioEnum"
' CLSID = {CF3D2E50-53F2-11D2-960C-00C04F8EE628}
$PROGID_SpMMAudioIn = "SAPI.SpMMAudioIn"
' CLSID = {A8C680EB-3D32-11D2-9EE7-00C04F797396}
$PROGID_SpMMAudioOut = "SAPI.SpMMAudioOut"
' CLSID = {E2AE5372-5D40-11D2-960E-00C04F8EE628}
$PROGID_SpNotifyTranslator = "SAPI.SpNotifyTranslator"
' CLSID = {455F24E9-7396-4A16-9715-7C0FDBE3EFE3}
$PROGID_SpNullPhoneConverter = "SAPI.SpNullPhoneConverter"
' CLSID = {EF411752-3736-4CB4-9C8C-8EF4CCB58EFE}
$PROGID_SpObjectToken = "SAPI.SpObjectToken"
' CLSID = {A910187F-0C7A-45AC-92CC-59EDAFB77B53}
$PROGID_SpObjectTokenCategory = "SAPI.SpObjectTokenCategory"
' CLSID = {9185F743-1143-4C28-86B5-BFF14F20E5C8}
$PROGID_SpPhoneConverter = "SAPI.SpPhoneConverter"
' CLSID = {C23FC28D-C55F-4720-8B32-91F73C2BD5D1}
$PROGID_SpPhraseInfoBuilder = "SAPI.SpPhraseInfoBuilder"
' CLSID = {96749373-3391-11D2-9EE3-00C04F797396}
$PROGID_SpResourceManager = "SAPI.SpResourceManager"
' CLSID = {47206204-5ECA-11D2-960F-00C04F8EE628}
$PROGID_SpSharedRecoContext = "SAPI.SpSharedRecoContext"
' CLSID = {3BEE4890-4FE9-4A37-8C1E-5E7E12791C1F}
$PROGID_SpSharedRecognizer = "Sapi.SpSharedRecognizer"
' CLSID = {0D722F1A-9FCF-4E62-96D8-6DF8F01A26AA}
$PROGID_SpShortcut = "SAPI.SpShortcut"
' CLSID = {715D9C59-4442-11D2-9605-00C04F8EE628}
$PROGID_SpStream = "SAPI.SpStream"
' CLSID = {7013943A-E2EC-11D2-A086-00C04F8EF9B5}
$PROGID_SpStreamFormatConverter = "SAPI.SpStreamFormatConverter"
' CLSID = {0F92030A-CBFD-4AB8-A164-FF5985547FF6}
$PROGID_SpTextSelectionInformation = "SAPI.SpTextSelectionInformation"
' CLSID = {C9E37C15-DF92-4727-85D6-72E5EEB6995A}
$PROGID_SpUnCompressedLexicon = "SAPI.SpUncompressedLexicon"
' CLSID = {96749377-3391-11D2-9EE3-00C04F797396}
$PROGID_SpVoice = "SAPI.SpVoice"
' CLSID = {C79A574C-63BE-44B9-801F-283F87F898BE}
$PROGID_SpWaveFormatEx = "SAPI.SpWaveFormatEx"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SpAudioFormat = GUID$("{9EF96870-E160-4792-820D-48CF0649E4EC}")
$CLSID_SpCompressedLexicon = GUID$("{90903716-2F42-11D3-9C26-00C04F8EF87C}")
$CLSID_SpCustomStream = GUID$("{8DBEF13F-1948-4AA8-8CF0-048EEBED95D8}")
$CLSID_SpFileStream = GUID$("{947812B3-2AE1-4644-BA86-9E90DED7EC91}")
$CLSID_SpInProcRecoContext = GUID$("{73AD6842-ACE0-45E8-A4DD-8795881A2C2A}")
$CLSID_SpInprocRecognizer = GUID$("{41B89B6B-9399-11D2-9623-00C04F8EE628}")
$CLSID_SpLexicon = GUID$("{0655E396-25D0-11D3-9C26-00C04F8EF87C}")
$CLSID_SpMemoryStream = GUID$("{5FB7EF7D-DFF4-468A-B6B7-2FCBD188F994}")
$CLSID_SpMMAudioEnum = GUID$("{AB1890A0-E91F-11D2-BB91-00C04F8EE6C0}")
$CLSID_SpMMAudioIn = GUID$("{CF3D2E50-53F2-11D2-960C-00C04F8EE628}")
$CLSID_SpMMAudioOut = GUID$("{A8C680EB-3D32-11D2-9EE7-00C04F797396}")
$CLSID_SpNotifyTranslator = GUID$("{E2AE5372-5D40-11D2-960E-00C04F8EE628}")
$CLSID_SpNullPhoneConverter = GUID$("{455F24E9-7396-4A16-9715-7C0FDBE3EFE3}")
$CLSID_SpObjectToken = GUID$("{EF411752-3736-4CB4-9C8C-8EF4CCB58EFE}")
$CLSID_SpObjectTokenCategory = GUID$("{A910187F-0C7A-45AC-92CC-59EDAFB77B53}")
$CLSID_SpPhoneConverter = GUID$("{9185F743-1143-4C28-86B5-BFF14F20E5C8}")
$CLSID_SpPhoneticAlphabetConverter = GUID$("{4F414126-DFE3-4629-99EE-797978317EAD}")
$CLSID_SpPhraseInfoBuilder = GUID$("{C23FC28D-C55F-4720-8B32-91F73C2BD5D1}")
$CLSID_SpResourceManager = GUID$("{96749373-3391-11D2-9EE3-00C04F797396}")
$CLSID_SpSharedRecoContext = GUID$("{47206204-5ECA-11D2-960F-00C04F8EE628}")
$CLSID_SpSharedRecognizer = GUID$("{3BEE4890-4FE9-4A37-8C1E-5E7E12791C1F}")
$CLSID_SpShortcut = GUID$("{0D722F1A-9FCF-4E62-96D8-6DF8F01A26AA}")
$CLSID_SpStream = GUID$("{715D9C59-4442-11D2-9605-00C04F8EE628}")
$CLSID_SpStreamFormatConverter = GUID$("{7013943A-E2EC-11D2-A086-00C04F8EF9B5}")
$CLSID_SpTextSelectionInformation = GUID$("{0F92030A-CBFD-4AB8-A164-FF5985547FF6}")
$CLSID_SpUnCompressedLexicon = GUID$("{C9E37C15-DF92-4727-85D6-72E5EEB6995A}")
$CLSID_SpVoice = GUID$("{96749377-3391-11D2-9EE3-00C04F797396}")
$CLSID_SpWaveFormatEx = GUID$("{C79A574C-63BE-44B9-801F-283F87F898BE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumSpObjectTokens = GUID$("{06B64F9E-7FDA-11D2-B4F2-00C04F797396}")
$IID_ISpAudio = GUID$("{C05C768F-FAE8-4EC2-8E07-338321C12452}")
$IID_ISpContainerLexicon = GUID$("{8565572F-C094-41CC-B56E-10BD9C3FF044}")
$IID_ISpDataKey = GUID$("{14056581-E16C-11D2-BB90-00C04F8EE6C0}")
$IID_ISpeechAudio = GUID$("{CFF8E175-019E-11D3-A08E-00C04F8EF9B5}")
$IID_ISpeechAudioBufferInfo = GUID$("{11B103D8-1142-4EDF-A093-82FB3915F8CC}")
$IID_ISpeechAudioFormat = GUID$("{E6E9C590-3E18-40E3-8299-061F98BDE7C7}")
$IID_ISpeechAudioStatus = GUID$("{C62D9C91-7458-47F6-862D-1EF86FB0B278}")
$IID_ISpeechBaseStream = GUID$("{6450336F-7D49-4CED-8097-49D6DEE37294}")
$IID_ISpeechCustomStream = GUID$("{1A9E9F4F-104F-4DB8-A115-EFD7FD0C97AE}")
$IID_ISpeechDataKey = GUID$("{CE17C09B-4EFA-44D5-A4C9-59D9585AB0CD}")
$IID_ISpeechFileStream = GUID$("{AF67F125-AB39-4E93-B4A2-CC2E66E182A7}")
$IID_ISpeechGrammarRule = GUID$("{AFE719CF-5DD1-44F2-999C-7A399F1CFCCC}")
$IID_ISpeechGrammarRules = GUID$("{6FFA3B44-FC2D-40D1-8AFC-32911C7F1AD1}")
$IID_ISpeechGrammarRuleState = GUID$("{D4286F2C-EE67-45AE-B928-28D695362EDA}")
$IID_ISpeechGrammarRuleStateTransition = GUID$("{CAFD1DB1-41D1-4A06-9863-E2E81DA17A9A}")
$IID_ISpeechGrammarRuleStateTransitions = GUID$("{EABCE657-75BC-44A2-AA7F-C56476742963}")
$IID_ISpeechLexicon = GUID$("{3DA7627A-C7AE-4B23-8708-638C50362C25}")
$IID_ISpeechLexiconPronunciation = GUID$("{95252C5D-9E43-4F4A-9899-48EE73352F9F}")
$IID_ISpeechLexiconPronunciations = GUID$("{72829128-5682-4704-A0D4-3E2BB6F2EAD3}")
$IID_ISpeechLexiconWord = GUID$("{4E5B933C-C9BE-48ED-8842-1EE51BB1D4FF}")
$IID_ISpeechLexiconWords = GUID$("{8D199862-415E-47D5-AC4F-FAA608B424E6}")
$IID_ISpeechMemoryStream = GUID$("{EEB14B68-808B-4ABE-A5EA-B51DA7588008}")
$IID_ISpeechMMSysAudio = GUID$("{3C76AF6D-1FD7-4831-81D1-3B71D5A13C44}")
$IID_ISpeechObjectToken = GUID$("{C74A3ADC-B727-4500-A84A-B526721C8B8C}")
$IID_ISpeechObjectTokenCategory = GUID$("{CA7EAC50-2D01-4145-86D4-5AE7D70F4469}")
$IID_ISpeechObjectTokens = GUID$("{9285B776-2E7B-4BC0-B53E-580EB6FA967F}")
$IID_ISpeechPhoneConverter = GUID$("{C3E4F353-433F-43D6-89A1-6A62A7054C3D}")
$IID_ISpeechPhraseAlternate = GUID$("{27864A2A-2B9F-4CB8-92D3-0D2722FD1E73}")
$IID_ISpeechPhraseAlternates = GUID$("{B238B6D5-F276-4C3D-A6C1-2974801C3CC2}")
$IID_ISpeechPhraseElement = GUID$("{E6176F96-E373-4801-B223-3B62C068C0B4}")
$IID_ISpeechPhraseElements = GUID$("{0626B328-3478-467D-A0B3-D0853B93DDA3}")
$IID_ISpeechPhraseInfo = GUID$("{961559CF-4E67-4662-8BF0-D93F1FCD61B3}")
$IID_ISpeechPhraseInfoBuilder = GUID$("{3B151836-DF3A-4E0A-846C-D2ADC9334333}")
$IID_ISpeechPhraseProperties = GUID$("{08166B47-102E-4B23-A599-BDB98DBFD1F4}")
$IID_ISpeechPhraseProperty = GUID$("{CE563D48-961E-4732-A2E1-378A42B430BE}")
$IID_ISpeechPhraseReplacement = GUID$("{2890A410-53A7-4FB5-94EC-06D4998E3D02}")
$IID_ISpeechPhraseReplacements = GUID$("{38BC662F-2257-4525-959E-2069D2596C05}")
$IID_ISpeechPhraseRule = GUID$("{A7BFE112-A4A0-48D9-B602-C313843F6964}")
$IID_ISpeechPhraseRules = GUID$("{9047D593-01DD-4B72-81A3-E4A0CA69F407}")
$IID_ISpeechRecoContext = GUID$("{580AA49D-7E1E-4809-B8E2-57DA806104B8}")
$IID_ISpeechRecognizer = GUID$("{2D5F1C0C-BD75-4B08-9478-3B11FEA2586C}")
$IID_ISpeechRecognizerStatus = GUID$("{BFF9E781-53EC-484E-BB8A-0E1B5551E35C}")
$IID_ISpeechRecoGrammar = GUID$("{B6D6F79F-2158-4E50-B5BC-9A9CCD852A09}")
$IID_ISpeechRecoResult = GUID$("{ED2879CF-CED9-4EE6-A534-DE0191D5468D}")
$IID_ISpeechRecoResult2 = GUID$("{8E0A246D-D3C8-45DE-8657-04290C458C3C}")
$IID_ISpeechRecoResultDispatch = GUID$("{6D60EB64-ACED-40A6-BBF3-4E557F71DEE2}")
$IID_ISpeechRecoResultTimes = GUID$("{62B3B8FB-F6E7-41BE-BDCB-056B1C29EFC0}")
$IID_ISpeechResourceLoader = GUID$("{B9AC5783-FCD0-4B21-B119-B4F8DA8FD2C3}")
$IID_ISpeechTextSelectionInformation = GUID$("{3B9C7E7A-6EEE-4DED-9092-11657279ADBE}")
$IID_ISpeechVoice = GUID$("{269316D8-57BD-11D2-9EEE-00C04F797396}")
$IID_ISpeechVoiceStatus = GUID$("{8BE47B07-57F6-11D2-9EEE-00C04F797396}")
$IID_ISpeechWaveFormatEx = GUID$("{7A1EF0D5-1581-4741-88E4-209A49F11A10}")
$IID_ISpeechXMLRecoResult = GUID$("{AAEC54AF-8F85-4924-944D-B79D39D72E19}")
$IID_ISpEnginePronunciation = GUID$("{C360CE4B-76D1-4214-AD68-52657D5083DA}")
$IID_ISpEventSink = GUID$("{BE7A9CC9-5F9E-11D2-960F-00C04F8EE628}")
$IID_ISpEventSource = GUID$("{BE7A9CCE-5F9E-11D2-960F-00C04F8EE628}")
$IID_ISpEventSource2 = GUID$("{2373A435-6A4B-429E-A6AC-D4231A61975B}")
$IID_ISpGrammarBuilder = GUID$("{8137828F-591A-4A42-BE58-49EA7EBAAC68}")
$IID_ISpGrammarBuilder2 = GUID$("{8AB10026-20CC-4B20-8C22-A49C9BA78F60}")
$IID_ISpLexicon = GUID$("{DA41A7C2-5383-4DB2-916B-6C1719E3DB58}")
$IID_ISpMMSysAudio = GUID$("{15806F6E-1D70-4B48-98E6-3B1A007509AB}")
$IID_ISpNotifySink = GUID$("{259684DC-37C3-11D2-9603-00C04F8EE628}")
$IID_ISpNotifySource = GUID$("{5EFF4AEF-8487-11D2-961C-00C04F8EE628}")
$IID_ISpNotifyTranslator = GUID$("{ACA16614-5D3D-11D2-960E-00C04F8EE628}")
$IID_ISpObjectToken = GUID$("{14056589-E16C-11D2-BB90-00C04F8EE6C0}")
$IID_ISpObjectTokenCategory = GUID$("{2D3D3845-39AF-4850-BBF9-40B49780011D}")
$IID_ISpObjectTokenInit = GUID$("{B8AAB0CF-346F-49D8-9499-C8B03F161D51}")
$IID_ISpObjectWithToken = GUID$("{5B559F40-E952-11D2-BB91-00C04F8EE6C0}")
$IID_ISpPhoneConverter = GUID$("{8445C581-0CAC-4A38-ABFE-9B2CE2826455}")
$IID_ISpPhoneticAlphabetConverter = GUID$("{133ADCD4-19B4-4020-9FDC-842E78253B17}")
$IID_ISpPhoneticAlphabetSelection = GUID$("{B2745EFD-42CE-48CA-81F1-A96E02538A90}")
$IID_ISpPhrase = GUID$("{1A5C0354-B621-4B5A-8791-D306ED379E53}")
$IID_ISpPhrase2 = GUID$("{F264DA52-E457-4696-B856-A737B717AF79}")
$IID_ISpPhraseAlt = GUID$("{8FCEBC98-4E49-4067-9C6C-D86A0E092E3D}")
$IID_ISpProperties = GUID$("{5B4FB971-B115-4DE1-AD97-E482E3BF6EE4}")
$IID_ISpRecoCategory = GUID$("{DA0CD0F9-14A2-4F09-8C2A-85CC48979345}")
$IID_ISpRecoContext = GUID$("{F740A62F-7C15-489E-8234-940A33D9272D}")
$IID_ISpRecoContext2 = GUID$("{BEAD311C-52FF-437F-9464-6B21054CA73D}")
$IID_ISpRecognizer = GUID$("{C2B5F241-DAA0-4507-9E16-5A1EAA2B7A5C}")
$IID_ISpRecognizer2 = GUID$("{8FC6D974-C81E-4098-93C5-0147F61ED4D3}")
$IID_ISpRecognizer3 = GUID$("{DF1B943C-5838-4AA2-8706-D7CD5B333499}")
$IID_ISpRecoGrammar = GUID$("{2177DB29-7F45-47D0-8554-067E91C80502}")
$IID_ISpRecoGrammar2 = GUID$("{4B37BC9E-9ED6-44A3-93D3-18F022B79EC3}")
$IID_ISpRecoResult = GUID$("{20B053BE-E235-43CD-9A2A-8D17A48B7842}")
$IID_ISpRecoResult2 = GUID$("{27CAC6C4-88F2-41F2-8817-0C95E59F1E6E}")
$IID_ISpRegDataKey = GUID$("{92A66E2B-C830-4149-83DF-6FC2BA1E7A5B}")
$IID_ISpResourceManager = GUID$("{93384E18-5014-43D5-ADBB-A78E055926BD}")
$IID_ISpSerializeState = GUID$("{21B501A0-0EC7-46C9-92C3-A2BC784C54B9}")
$IID_ISpShortcut = GUID$("{3DF681E2-EA56-11D9-8BDE-F66BAD1E3F3A}")
$IID_ISpStream = GUID$("{12E3CCA9-7518-44C5-A5E7-BA5A79CB929E}")
$IID_ISpStreamFormat = GUID$("{BED530BE-2606-4F4D-A1C0-54C5CDA5566F}")
$IID_ISpStreamFormatConverter = GUID$("{678A932C-EA71-4446-9B41-78FDA6280A29}")
$IID_ISpTranscript = GUID$("{10F63BCE-201A-11D3-AC70-00C04F8EE6C0}")
$IID_ISpVoice = GUID$("{6C44DF74-72B9-4992-A1EC-EF996E0422D4}")
$IID_ISpXMLRecoResult = GUID$("{AE39362B-45A8-4074-9B9E-CCF49AA2D0B6}")
$IID__ISpeechRecoContextEvents = GUID$("{7B8FCB42-0E9D-4F00-A048-7B04D6179D3D}")
$IID__ISpeechVoiceEvents = GUID$("{A372ACD1-3BEF-4BBD-8FFB-CB3E2B416AF8}")

' enum SPDATAKEYLOCATION
%SPDKL_DefaultLocation = 0
%SPDKL_CurrentUser     = 1
%SPDKL_LocalMachine    = 2
%SPDKL_CurrentConfig   = 5

$$SPDUI_EngineProperties      = "EngineProperties"$$
$$SPDUI_AddRemoveWord         = "AddRemoveWord"$$
$$SPDUI_UserTraining          = "UserTraining"$$
$$SPDUI_MicTraining           = "MicTraining"$$
$$SPDUI_RecoProfileProperties = "RecoProfileProperties"$$
$$SPDUI_AudioProperties       = "AudioProperties"$$
$$SPDUI_AudioVolume           = "AudioVolume"$$
$$SPDUI_UserEnrollment        = "UserEnrollment"$$
$$SPDUI_ShareData             = "ShareData"$$
$$SPDUI_Tutorial              = "Tutorial"$$

' enum SPSTREAMFORMAT
%SPSF_Default                 = -1
%SPSF_NoAssignedFormat        = 0
%SPSF_Text                    = %SPSF_NoAssignedFormat        + 1
%SPSF_NonStandardFormat       = %SPSF_Text                    + 1
%SPSF_ExtendedAudioFormat     = %SPSF_NonStandardFormat       + 1
%SPSF_8kHz8BitMono            = %SPSF_ExtendedAudioFormat     + 1
%SPSF_8kHz8BitStereo          = %SPSF_8kHz8BitMono            + 1
%SPSF_8kHz16BitMono           = %SPSF_8kHz8BitStereo          + 1
%SPSF_8kHz16BitStereo         = %SPSF_8kHz16BitMono           + 1
%SPSF_11kHz8BitMono           = %SPSF_8kHz16BitStereo         + 1
%SPSF_11kHz8BitStereo         = %SPSF_11kHz8BitMono           + 1
%SPSF_11kHz16BitMono          = %SPSF_11kHz8BitStereo         + 1
%SPSF_11kHz16BitStereo        = %SPSF_11kHz16BitMono          + 1
%SPSF_12kHz8BitMono           = %SPSF_11kHz16BitStereo        + 1
%SPSF_12kHz8BitStereo         = %SPSF_12kHz8BitMono           + 1
%SPSF_12kHz16BitMono          = %SPSF_12kHz8BitStereo         + 1
%SPSF_12kHz16BitStereo        = %SPSF_12kHz16BitMono          + 1
%SPSF_16kHz8BitMono           = %SPSF_12kHz16BitStereo        + 1
%SPSF_16kHz8BitStereo         = %SPSF_16kHz8BitMono           + 1
%SPSF_16kHz16BitMono          = %SPSF_16kHz8BitStereo         + 1
%SPSF_16kHz16BitStereo        = %SPSF_16kHz16BitMono          + 1
%SPSF_22kHz8BitMono           = %SPSF_16kHz16BitStereo        + 1
%SPSF_22kHz8BitStereo         = %SPSF_22kHz8BitMono           + 1
%SPSF_22kHz16BitMono          = %SPSF_22kHz8BitStereo         + 1
%SPSF_22kHz16BitStereo        = %SPSF_22kHz16BitMono          + 1
%SPSF_24kHz8BitMono           = %SPSF_22kHz16BitStereo        + 1
%SPSF_24kHz8BitStereo         = %SPSF_24kHz8BitMono           + 1
%SPSF_24kHz16BitMono          = %SPSF_24kHz8BitStereo         + 1
%SPSF_24kHz16BitStereo        = %SPSF_24kHz16BitMono          + 1
%SPSF_32kHz8BitMono           = %SPSF_24kHz16BitStereo        + 1
%SPSF_32kHz8BitStereo         = %SPSF_32kHz8BitMono           + 1
%SPSF_32kHz16BitMono          = %SPSF_32kHz8BitStereo         + 1
%SPSF_32kHz16BitStereo        = %SPSF_32kHz16BitMono          + 1
%SPSF_44kHz8BitMono           = %SPSF_32kHz16BitStereo        + 1
%SPSF_44kHz8BitStereo         = %SPSF_44kHz8BitMono           + 1
%SPSF_44kHz16BitMono          = %SPSF_44kHz8BitStereo         + 1
%SPSF_44kHz16BitStereo        = %SPSF_44kHz16BitMono          + 1
%SPSF_48kHz8BitMono           = %SPSF_44kHz16BitStereo        + 1
%SPSF_48kHz8BitStereo         = %SPSF_48kHz8BitMono           + 1
%SPSF_48kHz16BitMono          = %SPSF_48kHz8BitStereo         + 1
%SPSF_48kHz16BitStereo        = %SPSF_48kHz16BitMono          + 1
%SPSF_TrueSpeech_8kHz1BitMono = %SPSF_48kHz16BitStereo        + 1
%SPSF_CCITT_ALaw_8kHzMono     = %SPSF_TrueSpeech_8kHz1BitMono + 1
%SPSF_CCITT_ALaw_8kHzStereo   = %SPSF_CCITT_ALaw_8kHzMono     + 1
%SPSF_CCITT_ALaw_11kHzMono    = %SPSF_CCITT_ALaw_8kHzStereo   + 1
%SPSF_CCITT_ALaw_11kHzStereo  = %SPSF_CCITT_ALaw_11kHzMono    + 1
%SPSF_CCITT_ALaw_22kHzMono    = %SPSF_CCITT_ALaw_11kHzStereo  + 1
%SPSF_CCITT_ALaw_22kHzStereo  = %SPSF_CCITT_ALaw_22kHzMono    + 1
%SPSF_CCITT_ALaw_44kHzMono    = %SPSF_CCITT_ALaw_22kHzStereo  + 1
%SPSF_CCITT_ALaw_44kHzStereo  = %SPSF_CCITT_ALaw_44kHzMono    + 1
%SPSF_CCITT_uLaw_8kHzMono     = %SPSF_CCITT_ALaw_44kHzStereo  + 1
%SPSF_CCITT_uLaw_8kHzStereo   = %SPSF_CCITT_uLaw_8kHzMono     + 1
%SPSF_CCITT_uLaw_11kHzMono    = %SPSF_CCITT_uLaw_8kHzStereo   + 1
%SPSF_CCITT_uLaw_11kHzStereo  = %SPSF_CCITT_uLaw_11kHzMono    + 1
%SPSF_CCITT_uLaw_22kHzMono    = %SPSF_CCITT_uLaw_11kHzStereo  + 1
%SPSF_CCITT_uLaw_22kHzStereo  = %SPSF_CCITT_uLaw_22kHzMono    + 1
%SPSF_CCITT_uLaw_44kHzMono    = %SPSF_CCITT_uLaw_22kHzStereo  + 1
%SPSF_CCITT_uLaw_44kHzStereo  = %SPSF_CCITT_uLaw_44kHzMono    + 1
%SPSF_ADPCM_8kHzMono          = %SPSF_CCITT_uLaw_44kHzStereo  + 1
%SPSF_ADPCM_8kHzStereo        = %SPSF_ADPCM_8kHzMono          + 1
%SPSF_ADPCM_11kHzMono         = %SPSF_ADPCM_8kHzStereo        + 1
%SPSF_ADPCM_11kHzStereo       = %SPSF_ADPCM_11kHzMono         + 1
%SPSF_ADPCM_22kHzMono         = %SPSF_ADPCM_11kHzStereo       + 1
%SPSF_ADPCM_22kHzStereo       = %SPSF_ADPCM_22kHzMono         + 1
%SPSF_ADPCM_44kHzMono         = %SPSF_ADPCM_22kHzStereo       + 1
%SPSF_ADPCM_44kHzStereo       = %SPSF_ADPCM_44kHzMono         + 1
%SPSF_GSM610_8kHzMono         = %SPSF_ADPCM_44kHzStereo       + 1
%SPSF_GSM610_11kHzMono        = %SPSF_GSM610_8kHzMono         + 1
%SPSF_GSM610_22kHzMono        = %SPSF_GSM610_11kHzMono        + 1
%SPSF_GSM610_44kHzMono        = %SPSF_GSM610_22kHzMono        + 1
%SPSF_NUM_FORMATS             = %SPSF_GSM610_44kHzMono        + 1

'EXTERN_C const GUID SPDFID_Text;
'EXTERN_C const GUID SPDFID_WaveFormatEx;

' Must be used as unicode
$$SPREG_USER_ROOT                            = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech"$$
$$SPREG_LOCAL_MACHINE_ROOT                   = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech"$$
$$SPCAT_AUDIOOUT                             = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput"$$
$$SPCAT_AUDIOIN                              = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput"$$
$$SPCAT_VOICES                               = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices"$$
$$SPCAT_RECOGNIZERS                          = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers"$$
$$SPCAT_APPLEXICONS                          = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons"$$
$$SPCAT_PHONECONVERTERS                      = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters"$$
$$SPCAT_RECOPROFILES                         = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles"$$
$$SPMMSYS_AUDIO_IN_TOKEN_ID                  = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput\TokenEnums\MMAudioIn\"$$
$$SPMMSYS_AUDIO_OUT_TOKEN_ID                 = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput\TokenEnums\MMAudioOut\"$$
$$SPCURRENT_USER_LEXICON_TOKEN_ID            = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon"$$
$$SPCURRENT_USER_SHORTCUT_TOKEN_ID           = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserShortcut"$$
$$SPTOKENVALUE_CLSID                         = "CLSID"$$
$$SPTOKENKEY_FILES                           = "Files"$$
$$SPTOKENKEY_UI                              = "UI"$$
$$SPTOKENKEY_ATTRIBUTES                      = "Attributes"$$
$$SPTOKENKEY_RETAINEDAUDIO                   = "SecondsPerRetainedAudioEvent"$$
$$SPVOICECATEGORY_TTSRATE                    = "DefaultTTSRate"$$
$$SPPROP_RESOURCE_USAGE                      = "ResourceUsage"$$
$$SPPROP_HIGH_CONFIDENCE_THRESHOLD           = "HighConfidenceThreshold"$$
$$SPPROP_NORMAL_CONFIDENCE_THRESHOLD         = "NormalConfidenceThreshold"$$
$$SPPROP_LOW_CONFIDENCE_THRESHOLD            = "LowConfidenceThreshold"$$
$$SPPROP_RESPONSE_SPEED                      = "ResponseSpeed"$$
$$SPPROP_COMPLEX_RESPONSE_SPEED              = "ComplexResponseSpeed"$$
$$SPPROP_ADAPTATION_ON                       = "AdaptationOn"$$
$$SPPROP_PERSISTED_BACKGROUND_ADAPTATION     = "PersistedBackgroundAdaptation"$$
$$SPPROP_PERSISTED_LANGUAGE_MODEL_ADAPTATION = "PersistedLanguageModelAdaptation"$$
$$SPPROP_UX_IS_LISTENING                     = "UXIsListening"$$
$$SPTOPIC_SPELLING                           = "Spelling"$$
$$SPWILDCARD                                 = "..."$$
$$SPDICTATION                                = "*"$$
$$SPINFDICTATION                             = "*+"$$
$$SPREG_SAFE_USER_TOKENS                     = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\UserTokens"$$

%SP_LOW_CONFIDENCE    = -1
%SP_NORMAL_CONFIDENCE = 0
%SP_HIGH_CONFIDENCE   = +1
%DEFAULT_WEIGHT       = 1
%SP_MAX_WORD_LENGTH   = 128
%SP_MAX_PRON_LENGTH   = 384
%SP_EMULATE_RESULT    = &H40000000???

'typedef void __stdcall SPNOTIFYCALLBACK(WPARAM wParam, LPARAM lParam);
'SUB SPNOTIFYCALLBACK (BYVAL wParam AS DWORD, BYVAL lParam AS LONG)

' ########################################################################################
' Interface name = ISpNotifySource
' IID = {5EFF4AEF-8487-11D2-961C-00C04F8EE628}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpNotifySource_INTERFACE_DEFINED)
    %ISpNotifySource_INTERFACE_DEFINED = 1

INTERFACE ISpNotifySource $IID_ISpNotifySource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNotifySink ( _                             ' VTable offset = 12
     BYVAL pNotifySink AS ISpNotifySink _               ' __in ISpNotifySink *pNotifySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWindowMessage ( _                    ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackFunction ( _                 ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackInterface ( _                ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWin32Event ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNotifyEvent ( _                        ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyEventHandle ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpNotifySource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpNotifySink
' IID = {259684DC-37C3-11D2-9603-00C04F8EE628}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpNotifySink_INTERFACE_DEFINED)
    %ISpNotifySink_INTERFACE_DEFINED = 1

INTERFACE ISpNotifySink $IID_ISpNotifySink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpNotifySink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpNotifyTranslator
' IID = {ACA16614-5D3D-11D2-960E-00C04F8EE628}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpNotifySink
' ########################################################################################

#IF NOT %DEF(%ISpNotifyTranslator_INTERFACE_DEFINED)
    %ISpNotifyTranslator_INTERFACE_DEFINED = 1

INTERFACE ISpNotifyTranslator $IID_ISpNotifyTranslator

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySink Methods
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpNotifyTranslator Methods
   ' =====================================================================================
   METHOD InitWindowMessage ( _                         ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitCallback ( _                              ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitSpNotifyCallback ( _                      ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitWin32Event ( _                            ' VTable offset = 28
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   , BYVAL fCloseHandleOnRelease AS LONG _              ' __in BOOL fCloseHandleOnRelease
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventHandle ( _                            ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpNotifyTranslator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpDataKey
' IID = {14056581-E16C-11D2-BB90-00C04F8EE6C0}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpDataKey_INTERFACE_DEFINED)
    %ISpDataKey_INTERFACE_DEFINED = 1

INTERFACE ISpDataKey $IID_ISpDataKey

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 12
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL cbData AS DWORD _                            ' __in ULONG cbData
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pcbData AS DWORD _                           ' __in ULONG *pcbData
   , BYVAL pData AS BYTE PTR _                          ' __out BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 20
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszValue AS WSTRINGZ _                       ' __in const WCHAR *pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 24
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF ppszValue AS DWORD _                         ' __out WCHAR **ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDWORD ( _                                  ' VTable offset = 28
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDWORD ( _                                  ' VTable offset = 32
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenKey ( _                                   ' VTable offset = 36
     BYREF pszSubKeyName AS WSTRINGZ _                  ' __in const WCHAR *pszSubKeyName
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateKey ( _                                 ' VTable offset = 40
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 44
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 48
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumKeys ( _                                  ' VTable offset = 52
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszSubKeyName AS DWORD _                    ' __out WCHAR **ppszSubKeyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumValues ( _                                ' VTable offset = 56
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszValueName AS DWORD _                     ' __out WCHAR **ppszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpDataKey_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpRegDataKey
' IID = {92A66E2B-C830-4149-83DF-6FC2BA1E7A5B}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpDataKey
' ########################################################################################

#IF NOT %DEF(%ISpRegDataKey_INTERFACE_DEFINED)
    %ISpRegDataKey_INTERFACE_DEFINED = 1

INTERFACE ISpRegDataKey $IID_ISpRegDataKey

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpDataKey methods
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 12
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL cbData AS DWORD _                            ' __in ULONG cbData
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pcbData AS DWORD _                           ' __in ULONG *pcbData
   , BYVAL pData AS BYTE PTR _                          ' __out BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 20
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszValue AS WSTRINGZ _                       ' __in const WCHAR *pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 24
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF ppszValue AS DWORD _                         ' __out WCHAR **ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDWORD ( _                                  ' VTable offset = 28
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDWORD ( _                                  ' VTable offset = 32
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenKey ( _                                   ' VTable offset = 36
     BYREF pszSubKeyName AS WSTRINGZ _                  ' __in const WCHAR *pszSubKeyName
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateKey ( _                                 ' VTable offset = 40
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 44
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 48
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumKeys ( _                                  ' VTable offset = 52
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszSubKeyName AS DWORD _                    ' __out WCHAR **ppszSubKeyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumValues ( _                                ' VTable offset = 56
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszValueName AS DWORD _                     ' __out WCHAR **ppszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRegDataKey method
   ' =====================================================================================
   METHOD SetKey ( _                                    ' VTable offset = 60
     BYVAL hkey AS DWORD _                              ' __in HKEY hkey
   , BYVAL fReadOnly AS DWORD _                         ' __in BOOL fReadOnly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRegDataKey_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpObjectTokenCategory
' IID = {2D3D3845-39AF-4850-BBF9-40B49780011D}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpDataKey
' ########################################################################################

#IF NOT %DEF(%ISpObjectTokenCategory_INTERFACE_DEFINED)
    %ISpObjectTokenCategory_INTERFACE_DEFINED = 1

INTERFACE ISpObjectTokenCategory $IID_ISpObjectTokenCategory

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpDataKey methods
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 12
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL cbData AS DWORD _                            ' __in ULONG cbData
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pcbData AS DWORD _                           ' __in ULONG *pcbData
   , BYVAL pData AS BYTE PTR _                          ' __out BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 20
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszValue AS WSTRINGZ _                       ' __in const WCHAR *pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 24
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF ppszValue AS DWORD _                         ' __out WCHAR **ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDWORD ( _                                  ' VTable offset = 28
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDWORD ( _                                  ' VTable offset = 32
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenKey ( _                                   ' VTable offset = 36
     BYREF pszSubKeyName AS WSTRINGZ _                  ' __in const WCHAR *pszSubKeyName
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateKey ( _                                 ' VTable offset = 40
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 44
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 48
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumKeys ( _                                  ' VTable offset = 52
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszSubKeyName AS DWORD _                    ' __out WCHAR **ppszSubKeyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumValues ( _                                ' VTable offset = 56
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszValueName AS DWORD _                     ' __out WCHAR **ppszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpObjectTokenCategory methods
   ' =====================================================================================
   METHOD SetId ( _                                     ' VTable offset = 60
     BYREF pszCategoryId AS WSTRINGZ _                  ' __in const WCHAR *pszCategoryId
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 64
     BYREF ppszCoMemCategoryId AS DWORD _               ' __out WCHAR **ppszCoMemCategoryId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataKey ( _                                ' VTable offset = 68
     BYVAL spdkl AS LONG _                              ' __in SPDATAKEYLOCATION spdkl
   , BYREF ppDataKey AS ISpDataKey _                    ' __out ISpDataKey **ppDataKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumTokens ( _                                ' VTable offset = 72
     BYREF pzsReqAttribs AS WSTRINGZ _                  ' __in const WCHAR *pzsReqAttribs
   , BYREF pszOptAttribs AS WSTRINGZ _                  ' __in const WCHAR *pszOptAttribs
   , BYREF ppEnum AS IEnumSpObjectTokens _              ' __out IEnumSpObjectTokens **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultTokenId ( _                         ' VTable offset = 76
     BYREF pszTokenId AS WSTRINGZ _                     ' __in const WCHAR *pszTokenId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultTokenId ( _                         ' VTable offset = 80
     BYREF ppszCoMemTokenId AS DWORD _                  ' __out WCHAR **ppszCoMemTokenId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpObjectTokenCategory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpObjectToken
' IID = {14056589-E16C-11D2-BB90-00C04F8EE6C0}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpDataKey
' ########################################################################################

#IF NOT %DEF(%ISpObjectToken_INTERFACE_DEFINED)
    %ISpObjectToken_INTERFACE_DEFINED = 1

INTERFACE ISpObjectToken $IID_ISpObjectToken

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpDataKey methods
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 12
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL cbData AS DWORD _                            ' __in ULONG cbData
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pcbData AS DWORD _                           ' __in ULONG *pcbData
   , BYVAL pData AS BYTE PTR _                          ' __out BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 20
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszValue AS WSTRINGZ _                       ' __in const WCHAR *pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 24
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF ppszValue AS DWORD _                         ' __out WCHAR **ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDWORD ( _                                  ' VTable offset = 28
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDWORD ( _                                  ' VTable offset = 32
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenKey ( _                                   ' VTable offset = 36
     BYREF pszSubKeyName AS WSTRINGZ _                  ' __in const WCHAR *pszSubKeyName
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateKey ( _                                 ' VTable offset = 40
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 44
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 48
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumKeys ( _                                  ' VTable offset = 52
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszSubKeyName AS DWORD _                    ' __out WCHAR **ppszSubKeyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumValues ( _                                ' VTable offset = 56
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszValueName AS DWORD _                     ' __out WCHAR **ppszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpObjectToken methods
   ' =====================================================================================
   METHOD SetId ( _                                     ' VTable offset = 60
     BYREF pszCategoryId AS WSTRINGZ _                  ' __in const WCHAR *pszCategoryId
   , BYREF pszTokenId AS WSTRINGZ _                     ' __in const WCHAR *pszTokenId
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 64
     BYREF ppszCoMemTokenId AS DWORD _                  ' __out WCHAR **ppszCoMemTokenId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 68
     BYREF ppTokenCategory AS ISpObjectTokenCategory _  ' __out ISpObjectTokenCategory **ppTokenCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 72
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStorageFileName ( _                        ' VTable offset = 76
     BYREF clsidCaller AS GUID _                        ' __in REFCLSID clsidCaller
   , BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszFileNameSpecifier AS WSTRINGZ _           ' __in const WCHAR *pszFileNameSpecifier
   , BYVAL nFolder AS DWORD _                           ' __in ULONG nFolder
   , BYREF ppszFilePath AS DWORD _                      ' __out WCHAR **ppszFilePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStorageFileName ( _                     ' VTable offset = 80
     BYREF clsidCaller AS GUID _                        ' __in REFCLSID clsidCaller
   , BYREF pszKeyName AS WSTRINGZ _                     ' __in const WCHAR *pszKeyName
   , BYVAL fDeleteFile AS LONG _                        ' __in BOOL fDeleteFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 84
     BYREF pclsidCaller AS GUID _                       ' __in const CLSID *pclsidCaller
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUISupported ( _                             ' VTable offset = 88
     BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   , BYREF pfSupported AS LONG _                        ' __out BOOL *pfSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayUI ( _                                 ' VTable offset = 92
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pszTitle AS WSTRINGZ _                       ' __in const WCHAR *pszTitle
   , BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD PTR _                   ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesAttributes ( _                         ' VTable offset = 96
     BYREF pszAttributes AS WSTRINGZ _                  ' __in const WCHAR *pszAttributes
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpObjectToken_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpObjectTokenInit
' IID = {B8AAB0CF-346F-49D8-9499-C8B03F161D51}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpObjectToken
' ########################################################################################

#IF NOT %DEF(%ISpObjectTokenInit_INTERFACE_DEFINED)
    %ISpObjectTokenInit_INTERFACE_DEFINED = 1

INTERFACE ISpObjectTokenInit $IID_ISpObjectTokenInit

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpDataKey methods
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 12
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL cbData AS DWORD _                            ' __in ULONG cbData
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pcbData AS DWORD _                           ' __in ULONG *pcbData
   , BYVAL pData AS BYTE PTR _                          ' __out BYTE *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringValue ( _                            ' VTable offset = 20
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszValue AS WSTRINGZ _                       ' __in const WCHAR *pszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 24
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF ppszValue AS DWORD _                         ' __out WCHAR **ppszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDWORD ( _                                  ' VTable offset = 28
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDWORD ( _                                  ' VTable offset = 32
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenKey ( _                                   ' VTable offset = 36
     BYREF pszSubKeyName AS WSTRINGZ _                  ' __in const WCHAR *pszSubKeyName
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateKey ( _                                 ' VTable offset = 40
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   , BYREF ppSubKey AS ISpDataKey _                     ' __out ISpDataKey **ppSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteKey ( _                                 ' VTable offset = 44
     BYREF pszSubKey AS WSTRINGZ _                      ' __in const WCHAR *pszSubKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteValue ( _                               ' VTable offset = 48
     BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumKeys ( _                                  ' VTable offset = 52
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszSubKeyName AS DWORD _                    ' __out WCHAR **ppszSubKeyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumValues ( _                                ' VTable offset = 56
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppszValueName AS DWORD _                     ' __out WCHAR **ppszValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpObjectToken methods
   ' =====================================================================================
   METHOD SetId ( _                                     ' VTable offset = 60
     BYREF pszCategoryId AS WSTRINGZ _                  ' __in const WCHAR *pszCategoryId
   , BYREF pszTokenId AS WSTRINGZ _                     ' __in const WCHAR *pszTokenId
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 64
     BYREF ppszCoMemTokenId AS DWORD _                  ' __out WCHAR **ppszCoMemTokenId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 68
     BYREF ppTokenCategory AS ISpObjectTokenCategory _  ' __out ISpObjectTokenCategory **ppTokenCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 72
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStorageFileName ( _                        ' VTable offset = 76
     BYREF clsidCaller AS GUID _                        ' __in REFCLSID clsidCaller
   , BYREF pszValueName AS WSTRINGZ _                   ' __in const WCHAR *pszValueName
   , BYREF pszFileNameSpecifier AS WSTRINGZ _           ' __in const WCHAR *pszFileNameSpecifier
   , BYVAL nFolder AS DWORD _                           ' __in ULONG nFolder
   , BYREF ppszFilePath AS DWORD _                      ' __out WCHAR **ppszFilePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStorageFileName ( _                     ' VTable offset = 80
     BYREF clsidCaller AS GUID _                        ' __in REFCLSID clsidCaller
   , BYREF pszKeyName AS WSTRINGZ _                     ' __in const WCHAR *pszKeyName
   , BYVAL fDeleteFile AS LONG _                        ' __in BOOL fDeleteFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 84
     BYREF pclsidCaller AS GUID _                       ' __in const CLSID *pclsidCaller
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUISupported ( _                             ' VTable offset = 88
     BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   , BYREF pfSupported AS LONG _                        ' __out BOOL *pfSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayUI ( _                                 ' VTable offset = 92
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pszTitle AS WSTRINGZ _                       ' __in const WCHAR *pszTitle
   , BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD PTR _                   ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesAttributes ( _                         ' VTable offset = 96
     BYREF pszAttributes AS WSTRINGZ _                  ' __in const WCHAR *pszAttributes
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpObjectTokenInit methods
   ' =====================================================================================
   METHOD InitFromDataKey ( _                           ' VTable offset = 100
     BYREF pszCategoryId AS WSTRINGZ _                  ' __in const WCHAR *pszCategoryId
   , BYREF pszTokenId AS WSTRINGZ _                     ' __in const WCHAR *pszTokenId
   , BYVAL pDataKey AS ISpDataKey _                     ' __in ISpDataKey *pDataKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpObjectTokenInit_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumSpObjectTokens
' IID = {06B64F9E-7FDA-11D2-B4F2-00C04F797396}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSpObjectTokens_INTERFACE_DEFINED)
    %IEnumSpObjectTokens_INTERFACE_DEFINED = 1

INTERFACE IEnumSpObjectTokens $IID_IEnumSpObjectTokens

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pelt AS ISpObjectToken _                     ' __out ISpObjectToken **pelt
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
     BYREF ppEnum AS IEnumSpObjectTokens _              ' __out IEnumSpObjectTokens **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 32
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSpObjectTokens_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpObjectWithToken
' IID = {5B559F40-E952-11D2-BB91-00C04F8EE6C0}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpObjectWithToken_INTERFACE_DEFINED)
    %ISpObjectWithToken_INTERFACE_DEFINED = 1

INTERFACE ISpObjectWithToken $IID_ISpObjectWithToken

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetObjectToken ( _                            ' VTable offset = 12
     BYVAL pToken AS ISpObjectToken _                   ' __in ISpObjectToken *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectToken ( _                            ' VTable offset = 16
     BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpObjectWithToken_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpResourceManager
' IID = {93384E18-5014-43D5-ADBB-A78E055926BD}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IServiceProvider
' ########################################################################################

#IF NOT %DEF(%ISpResourceManager_INTERFACE_DEFINED)
    %ISpResourceManager_INTERFACE_DEFINED = 1

INTERFACE ISpResourceManager $IID_ISpResourceManager

   INHERIT IUnknown

   ' =====================================================================================
   ' IServiceProvider methods
   ' =====================================================================================
   METHOD QueryService ( _                              ' VTable offset = 12
     BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpResourceManager Methods
   ' =====================================================================================
   METHOD SetObject ( _                                 ' VTable offset = 16
     BYREF guidServiceId AS GUID _                      ' __in REFGUID guidServiceId
   , BYVAL pUnkObject AS IUnknown _                     ' __in IUnknown *pUnkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 20
     BYREF guidServiceId AS GUID _                      ' __in REFGUID guidServiceId
   , BYREF ObjectCLSID AS GUID _                        ' __in REFCLSID ObjectCLSID
   , BYREF ObjectIID AS GUID _                          ' __in REFIID ObjectIID
   , BYVAL fReleaseWhenLastExternalRefReleased AS LONG _ ' __in BOOL fReleaseWhenLastExternalRefReleased
   , BYREF ppObject AS DWORD _                          ' __out void **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpResourceManager_INTERFACE_DEFINED__ */


' enum SPEVENTLPARAMTYPE
%SPET_LPARAM_IS_UNDEFINED = 0
%SPET_LPARAM_IS_TOKEN     = %SPET_LPARAM_IS_UNDEFINED + 1
%SPET_LPARAM_IS_OBJECT    = %SPET_LPARAM_IS_TOKEN     + 1
%SPET_LPARAM_IS_POINTER   = %SPET_LPARAM_IS_OBJECT    + 1
%SPET_LPARAM_IS_STRING    = %SPET_LPARAM_IS_POINTER   + 1

' enum SPEVENTENUM
%SPEI_UNDEFINED               = 0
%SPEI_START_INPUT_STREAM      = 1
%SPEI_END_INPUT_STREAM        = 2
%SPEI_VOICE_CHANGE            = 3
%SPEI_TTS_BOOKMARK            = 4
%SPEI_WORD_BOUNDARY           = 5
%SPEI_PHONEME                 = 6
%SPEI_SENTENCE_BOUNDARY       = 7
%SPEI_VISEME                  = 8
%SPEI_TTS_AUDIO_LEVEL         = 9
%SPEI_TTS_PRIVATE             = 15
%SPEI_MIN_TTS                 = 1
%SPEI_MAX_TTS                 = 15
%SPEI_END_SR_STREAM           = 34
%SPEI_SOUND_START             = 35
%SPEI_SOUND_END               = 36
%SPEI_PHRASE_START            = 37
%SPEI_RECOGNITION             = 38
%SPEI_HYPOTHESIS              = 39
%SPEI_SR_BOOKMARK             = 40
%SPEI_PROPERTY_NUM_CHANGE     = 41
%SPEI_PROPERTY_STRING_CHANGE  = 42
%SPEI_FALSE_RECOGNITION       = 43
%SPEI_INTERFERENCE            = 44
%SPEI_REQUEST_UI              = 45
%SPEI_RECO_STATE_CHANGE       = 46
%SPEI_ADAPTATION              = 47
%SPEI_START_SR_STREAM         = 48
%SPEI_RECO_OTHER_CONTEXT      = 49
%SPEI_SR_AUDIO_LEVEL          = 50
%SPEI_SR_RETAINEDAUDIO        = 51
%SPEI_SR_PRIVATE              = 52
%SPEI_ACTIVE_CATEGORY_CHANGED = 53
%SPEI_RESERVED5               = 54
%SPEI_RESERVED6               = 55
%SPEI_MIN_SR                  = 34
%SPEI_MAX_SR                  = 55
%SPEI_RESERVED1               = 30
%SPEI_RESERVED2               = 33
%SPEI_RESERVED3               = 63

'#define SPFEI_FLAGCHECK ( (1ui64 << SPEI_RESERVED1) | (1ui64 << SPEI_RESERVED2) )
'#define SPFEI_ALL_TTS_EVENTS (0x000000000000FFFEui64 | SPFEI_FLAGCHECK)
'#define SPFEI_ALL_SR_EVENTS  (0x001FFFFC00000000ui64 | SPFEI_FLAGCHECK)
'#define SPFEI_ALL_EVENTS      0xEFFFFFFFFFFFFFFFui64
'#define SPFEI(SPEI_ord) ((1ui64 << SPEI_ord) | SPFEI_FLAGCHECK)

%SPFEI_FLAGCHECK =  9663676416&&
%SPFEI_ALL_TTS_EVENTS =  9663741950&&
%SPFEI_ALL_SR_EVENTS =  9007191738548224&&
%SPFEI_ALL_EVENTS = &HEFFFFFFFFFFFFFFF&&

FUNCTION SPFEI (BYVAL SPEI_ord AS QUAD) AS QUAD
   LOCAL q AS QUAD
   q = 1
   SHIFT LEFT q, SPEI_ord
   FUNCTION = q OR %SPFEI_FLAGCHECK
END FUNCTION

' // Size = 24 bytes
TYPE SPEVENT   ' Must be 8 byte aligned
   eEventId             AS WORD    ' SPEVENTENUM
   elParamType          AS WORD    ' SPEVENTLPARAMTYPE
   ulStreamNum          AS DWORD   ' ULONG
   ullAudioStreamOffset AS QUAD    ' ULONGLONG
   wParam               AS DWORD   ' WPARAM
   lParam               AS LONG    ' LPARAM
END TYPE

' // Size = 24 bytes
TYPE SPSERIALIZEDEVENT   ' Must be 8 byte aligned
   eEventId             AS WORD    ' SPEVENTENUM
   elParamType          AS WORD    ' SPEVENTLPARAMTYPE
   ulStreamNum          AS DWORD   ' ULONG
   ullAudioStreamOffset AS QUAD    ' ULONGLONG
   SerializedwParam     AS DWORD   ' ULONG
   SerializedlParam     AS LONG    ' LONG
END TYPE

' // Size = 32 bytes
TYPE SPSERIALIZEDEVENT64   ' Must be 8 byte aligned
   eEventId             AS WORD    ' SPEVENTENUM
   elParamType          AS WORD    ' SPEVENTLPARAMTYPE
   ulStreamNum          AS DWORD   ' ULONG
   ullAudioStreamOffset AS QUAD    ' ULONGLONG
   SerializedwParam     AS QUAD    ' ULONGLONG
   SerializedlParam     AS QUAD    ' LONGLONG
END TYPE

' // Size = 32 bytes
TYPE SPEVENTEX   ' Must be 8 byte aligned
   eEventId             AS BIT * 16 IN DWORD   ' SPEVENTENUM
   elParamType          AS BIT * 16            ' SPEVENTLPARAMTYPE
   ulStreamNum          AS DWORD               ' ULONG
   ullAudioStreamOffset AS QUAD                ' ULONGLONG
   wParam               AS DWORD               ' WPARAM
   lParam               AS LONG                ' LPARAM
   ullAudioTimeOffset   AS QUAD                ' ULONGLONG
END TYPE

' enum SPINTERFERENCE
%SPINTERFERENCE_NONE     = 0
%SPINTERFERENCE_NOISE    = %SPINTERFERENCE_NONE     + 1
%SPINTERFERENCE_NOSIGNAL = %SPINTERFERENCE_NOISE    + 1
%SPINTERFERENCE_TOOLOUD  = %SPINTERFERENCE_NOSIGNAL + 1
%SPINTERFERENCE_TOOQUIET = %SPINTERFERENCE_TOOLOUD  + 1
%SPINTERFERENCE_TOOFAST  = %SPINTERFERENCE_TOOQUIET + 1
%SPINTERFERENCE_TOOSLOW  = %SPINTERFERENCE_TOOFAST  + 1

' enum SPENDSRSTREAMFLAGS
%SPESF_NONE            = 0
%SPESF_STREAM_RELEASED = 1   ' 1 << 0
%SPESF_EMULATED        =  2   ' 1 << 1

' enum SPVFEATURE
%SPVFEATURE_STRESSED   = 1   ' 1L << 0
%SPVFEATURE_EMPHASIS   = 2   ' 1L << 1

' enum SPVISEMES
%SP_VISEME_0  = 0
%SP_VISEME_1  = %SP_VISEME_0  + 1
%SP_VISEME_2  = %SP_VISEME_1  + 1
%SP_VISEME_3  = %SP_VISEME_2  + 1
%SP_VISEME_4  = %SP_VISEME_3  + 1
%SP_VISEME_5  = %SP_VISEME_4  + 1
%SP_VISEME_6  = %SP_VISEME_5  + 1
%SP_VISEME_7  = %SP_VISEME_6  + 1
%SP_VISEME_8  = %SP_VISEME_7  + 1
%SP_VISEME_9  = %SP_VISEME_8  + 1
%SP_VISEME_10 = %SP_VISEME_9  + 1
%SP_VISEME_11 = %SP_VISEME_10 + 1
%SP_VISEME_12 = %SP_VISEME_11 + 1
%SP_VISEME_13 = %SP_VISEME_12 + 1
%SP_VISEME_14 = %SP_VISEME_13 + 1
%SP_VISEME_15 = %SP_VISEME_14 + 1
%SP_VISEME_16 = %SP_VISEME_15 + 1
%SP_VISEME_17 = %SP_VISEME_16 + 1
%SP_VISEME_18 = %SP_VISEME_17 + 1
%SP_VISEME_19 = %SP_VISEME_18 + 1
%SP_VISEME_20 = %SP_VISEME_19 + 1
%SP_VISEME_21 = %SP_VISEME_20 + 1

' // Size = 24 bytes
TYPE SPEVENTSOURCEINFO QWORD
   ullEventInterest  AS QUAD    ' ULONGLONG
   ullQueuedInterest AS QUAD    ' ULONGLONG
   ulCount           AS DWORD   ' ULONG
END TYPE

' ########################################################################################
' Interface name = ISpEventSource
' IID = {BE7A9CCE-5F9E-11D2-960F-00C04F8EE628}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpNotifySource
' ########################################################################################

#IF NOT %DEF(%ISpEventSource_INTERFACE_DEFINED)
    %ISpEventSource_INTERFACE_DEFINED = 1

INTERFACE ISpEventSource $IID_ISpEventSource

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySource Methods
   ' =====================================================================================
   METHOD SetNotifySink ( _                             ' VTable offset = 12
     BYVAL pNotifySink AS ISpNotifySink _               ' __in ISpNotifySink *pNotifySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWindowMessage ( _                    ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackFunction ( _                 ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackInterface ( _                ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWin32Event ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNotifyEvent ( _                        ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyEventHandle ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

   ' =====================================================================================
   ' ISpEventSource Methods
   ' =====================================================================================
   METHOD SetInterest ( _                               ' VTable offset = 40
     BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   , BYVAL ullQueuedInterest AS QUAD _                  ' __in ULONGLONG ullQueuedInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvents ( _                                 ' VTable offset = 44
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pEventArray AS SPEVENT _                     ' __out SPEVENT *pEventArray
   , BYREF pulFetched AS DWORD _                        ' __out ULONG *pulFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 48
     BYREF pInfo AS SPEVENTSOURCEINFO _                 ' __out SPEVENTSOURCEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpEventSource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpEventSource2
' IID = 2373A435-6A4B-429E-A6AC-D4231A61975B
' Inherited interface = ISpEventSource
' ########################################################################################

#IF NOT %DEF(%ISpEventSource2_INTERFACE_DEFINED)
    %ISpEventSource2_INTERFACE_DEFINED = 1

INTERFACE ISpEventSource2 $IID_ISpEventSource2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySource Methods
   ' =====================================================================================
   METHOD SetNotifySink ( _                             ' VTable offset = 12
     BYVAL pNotifySink AS ISpNotifySink _               ' __in ISpNotifySink *pNotifySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWindowMessage ( _                    ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackFunction ( _                 ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackInterface ( _                ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWin32Event ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNotifyEvent ( _                        ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyEventHandle ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

   ' =====================================================================================
   ' ISpEventSource Methods
   ' =====================================================================================
   METHOD SetInterest ( _                               ' VTable offset = 40
     BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   , BYVAL ullQueuedInterest AS QUAD _                  ' __in ULONGLONG ullQueuedInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvents ( _                                 ' VTable offset = 44
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pEventArray AS SPEVENT _                     ' __out SPEVENT *pEventArray
   , BYREF pulFetched AS DWORD _                        ' __out ULONG *pulFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 48
     BYREF pInfo AS SPEVENTSOURCEINFO _                 ' __out SPEVENTSOURCEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpEventSource2 Method
   ' =====================================================================================
   METHOD GetEventsEx ( _                               ' VTable offset = 52
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pEventArray AS SPEVENTEX _                   ' __out SPEVENTEX *pEventArray
   , BYREF pulFetched AS DWORD _                        ' __out ULONG *pulFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpEventSource2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpEventSink
' IID = {BE7A9CC9-5F9E-11D2-960F-00C04F8EE628}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpEventSink_INTERFACE_DEFINED)
    %ISpEventSink_INTERFACE_DEFINED = 1

INTERFACE ISpEventSink $IID_ISpEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddEvents ( _                                 ' VTable offset = 12
     BYREF pEventArray AS SPEVENT _                     ' __in const SPEVENT *pEventArray
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventInterest ( _                          ' VTable offset = 16
     BYREF pullEventInterest AS QUAD _                  ' __out ULONGLONG *pullEventInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpEventSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpStreamFormat
' IID = {BED530BE-2606-4F4D-A1C0-54C5CDA5566F}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%ISpStreamFormat_INTERFACE_DEFINED)
    %ISpStreamFormat_INTERFACE_DEFINED = 1

INTERFACE ISpStreamFormat $IID_ISpStreamFormat

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormat Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 56
     BYREF pguidFormatId AS GUID _                      ' __in GUID *pguidFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpStreamFormat_INTERFACE_DEFINED__ */


' enum SPFILEMODE
%SPFM_OPEN_READONLY  = 0
%SPFM_OPEN_READWRITE = %SPFM_OPEN_READONLY  + 1
%SPFM_CREATE         = %SPFM_OPEN_READWRITE + 1
%SPFM_CREATE_ALWAYS  = %SPFM_CREATE         + 1
%SPFM_NUM_MODES      = %SPFM_CREATE_ALWAYS   + 1


' ########################################################################################
' Interface name = ISpStream
' IID = {12E3CCA9-7518-44C5-A5E7-BA5A79CB929E}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpStreamFormat
' ########################################################################################

#IF NOT %DEF(%ISpStream_INTERFACE_DEFINED)
    %ISpStream_INTERFACE_DEFINED = 1

INTERFACE ISpStream $IID_ISpStream

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormat Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 56
     BYREF pguidFormatId AS GUID _                      ' __in GUID *pguidFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStream Methods
   ' =====================================================================================
   METHOD SetBaseStream ( _                             ' VTable offset = 60
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF rguidFormat AS GUID _                        ' __in REFGUID rguidFormat
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaseStream ( _                             ' VTable offset = 64
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToFile ( _                                ' VTable offset = 68
     BYREF pszFileName AS WSTRINGZ _                    ' __in const WCHAR *pszFileName
   , BYVAL eMode AS LONG _                              ' __in SPFILEMODE eMode
   , BYREF pFormatId AS GUID _                          ' __in const GUID *pFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   , BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpStreamFormatConverter
' IID = {678A932C-EA71-4446-9B41-78FDA6280A29}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpStreamFormat
' ########################################################################################

#IF NOT %DEF(%ISpStreamFormatConverter_INTERFACE_DEFINED)
    %ISpStreamFormatConverter_INTERFACE_DEFINED = 1

INTERFACE ISpStreamFormatConverter $IID_ISpStreamFormatConverter

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormat Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 56
     BYREF pguidFormatId AS GUID _                      ' __in GUID *pguidFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormatConverter Methods
   ' =====================================================================================
   METHOD SetBaseStream ( _                             ' VTable offset = 60
     BYVAL pStream AS ISpStreamFormat _                 ' __in ISpStreamFormat *pStream
   , BYVAL fSetFormatToBaseStreamFormat AS LONG _       ' __in BOOL fSetFormatToBaseStreamFormat
   , BYVAL fWriteToBaseStream AS LONG _                 ' __in BOOL fWriteToBaseStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaseStream ( _                             ' VTable offset = 64
     BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 68
     BYREF rguidFormatIdOfConvertedStream AS GUID _     ' __in REFGUID rguidFormatIdOfConvertedStream
   , BYREF pWaveFormatExOfConvertedStream AS WAVEFORMATEX _ ' __in const WAVEFORMATEX *pWaveFormatExOfConvertedStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetSeekPosition ( _                         ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleConvertedToBaseOffset ( _                ' VTable offset = 76
     BYVAL ullOffsetConvertedStream AS QUAD _           ' __in ULONGLONG ullOffsetConvertedStream
   , BYREF pullOffsetBaseStream AS QUAD _               ' __out ULONGLONG *pullOffsetBaseStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleBaseToConvertedOffset ( _                ' VTable offset = 80
     BYVAL ullOffsetBaseStream AS QUAD _                ' __in ULONGLONG ullOffsetBaseStream
   , BYREF pullOffsetConvertedStream AS QUAD _          ' __out ULONGLONG *pullOffsetConvertedStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpStreamFormatConverter_INTERFACE_DEFINED__ */


' enum _SPAUDIOSTATE
%SPAS_CLOSED = 0
%SPAS_STOP   = %SPAS_CLOSED + 1
%SPAS_PAUSE  = %SPAS_STOP   + 1
%SPAS_RUN    = %SPAS_PAUSE  + 1

' // Size = 40 bytes
TYPE SPAUDIOSTATUS   ' Must be 8 byte aligned
   cbFreeBuffSpace AS LONG    ' long
   cbNonBlockingIO AS DWORD   ' ULONG
   State           AS LONG    ' SPAUDIOSTATE enum
   alignment__     AS DWORD
   CurSeekPos      AS QUAD    ' ULONGLONG
   CurDevicePos    AS QUAD    ' ULONGLONG
   dwReserved1     AS DWORD   ' DWORD
   dwReserved2     AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE SPAUDIOBUFFERINFO DWORD
   ulMsMinNotification AS DWORD   ' ULONG
   ulMsBufferSize      AS DWORD   ' ULONG
   ulMsEventBias       AS DWORD   ' ULONG
END TYPE


' ########################################################################################
' Interface name = ISpAudio
' IID = {C05C768F-FAE8-4EC2-8E07-338321C12452}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpStreamFormat
' ########################################################################################

#IF NOT %DEF(%ISpAudio_INTERFACE_DEFINED)
    %ISpAudio_INTERFACE_DEFINED = 1

INTERFACE ISpAudio $IID_ISpAudio

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormat Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 56
     BYREF pguidFormatId AS GUID _                      ' __in GUID *pguidFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpAudio Methods
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 60
     BYVAL NewState AS LONG _                           ' __in SPAUDIOSTATE NewState
   , BYVAL ullReserved AS QUAD _                        ' __in ULONGLONG ullReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 64
     BYREF rguidFmtId AS GUID _                         ' __in REFGUID rguidFmtId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 68
     BYREF pStatus AS SPAUDIOSTATUS _                   ' __out SPAUDIOSTATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferInfo ( _                             ' VTable offset = 72
     BYREF pBuffInfo AS SPAUDIOBUFFERINFO _             ' __in const SPAUDIOBUFFERINFO *pBuffInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferInfo ( _                             ' VTable offset = 76
     BYREF pBuffInfo AS SPAUDIOBUFFERINFO _             ' __out SPAUDIOBUFFERINFO *pBuffInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultFormat ( _                          ' VTable offset = 80
     BYREF pFormatId AS GUID _                          ' __out GUID *pFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EventHandle ( _                               ' VTable offset = 84
   ) AS DWORD                                           ' void
   ' =====================================================================================
   METHOD GetVolumeLevel ( _                            ' VTable offset = 88
     BYREF pLevel AS DWORD _                            ' __out ULONG *pLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVolumeLevel ( _                            ' VTable offset = 92
     BYVAL Level AS DWORD _                             ' __in ULONG Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferNotifySize ( _                       ' VTable offset = 96
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferNotifySize ( _                       ' VTable offset = 100
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpAudio_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpMMSysAudio
' IID = {15806F6E-1D70-4B48-98E6-3B1A007509AB}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpAudio
' ########################################################################################

#IF NOT %DEF(%ISpMMSysAudio_INTERFACE_DEFINED)
    %ISpMMSysAudio_INTERFACE_DEFINED = 1

INTERFACE ISpMMSysAudio $IID_ISpMMSysAudio

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpStreamFormat Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 56
     BYREF pguidFormatId AS GUID _                      ' __in GUID *pguidFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpAudio Methods
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 60
     BYVAL NewState AS LONG _                           ' __in SPAUDIOSTATE NewState
   , BYVAL ullReserved AS QUAD _                        ' __in ULONGLONG ullReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 64
     BYREF rguidFmtId AS GUID _                         ' __in REFGUID rguidFmtId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 68
     BYREF pStatus AS SPAUDIOSTATUS _                   ' __out SPAUDIOSTATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferInfo ( _                             ' VTable offset = 72
     BYREF pBuffInfo AS SPAUDIOBUFFERINFO _             ' __in const SPAUDIOBUFFERINFO *pBuffInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferInfo ( _                             ' VTable offset = 76
     BYREF pBuffInfo AS SPAUDIOBUFFERINFO _             ' __out SPAUDIOBUFFERINFO *pBuffInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultFormat ( _                          ' VTable offset = 80
     BYREF pFormatId AS GUID _                          ' __out GUID *pFormatId
   , BYREF ppCoMemWaveFormatEx AS WAVEFORMATEX _        ' __out WAVEFORMATEX **ppCoMemWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EventHandle ( _                               ' VTable offset = 84
   ) AS DWORD                                           ' void
   ' =====================================================================================
   METHOD GetVolumeLevel ( _                            ' VTable offset = 88
     BYREF pLevel AS DWORD _                            ' __out ULONG *pLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVolumeLevel ( _                            ' VTable offset = 92
     BYVAL Level AS DWORD _                             ' __in ULONG Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferNotifySize ( _                       ' VTable offset = 96
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferNotifySize ( _                       ' VTable offset = 100
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpMMSysAudio Methods
   ' =====================================================================================
   METHOD GetDeviceId ( _                               ' VTable offset = 104
     BYREF puDeviceId AS DWORD _                        ' __out UINT *puDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeviceId ( _                               ' VTable offset = 108
     BYVAL uDeviceId AS DWORD _                         ' __in UINT uDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMMHandle ( _                               ' VTable offset = 112
     BYVAL pHandle AS DWORD _                           ' __out void **pHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineId ( _                                 ' VTable offset = 116
     BYREF puLineId AS DWORD _                          ' __out UINT *puLineId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLineId ( _                                 ' VTable offset = 120
     BYVAL uLineId AS DWORD _                           ' __in UINT uLineId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpMMSysAudio_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpTranscript
' IID = {CE17C09B-4EFA-44D5-A4C9-59D9585AB0CD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpTranscript_INTERFACE_DEFINED)
    %ISpTranscript_INTERFACE_DEFINED = 1

INTERFACE ISpTranscript $IID_ISpTranscript

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTranscript ( _                             ' VTable offset = 12
     BYREF ppszTranscript AS DWORD _                    ' __out WCHAR **ppszTranscript
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendTranscript ( _                          ' VTable offset = 16
     BYREF pszTranscript AS WSTRINGZ _                  ' __in const WCHAR *pszTranscript
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpTranscript_INTERFACE_DEFINED__ */


' enum SPDISPLYATTRIBUTES
%SPAF_ONE_TRAILING_SPACE     = &H2
%SPAF_TWO_TRAILING_SPACES    = &H4
%SPAF_CONSUME_LEADING_SPACES = &H8
%SPAF_ALL                    = &Hf
%SPAF_USER_SPECIFIED         = &H80

'typedef WCHAR SPPHONEID;
'typedef LPWSTR PSPPHONEID;
'typedef LPCWSTR PCSPPHONEID;

' // Size = 44 bytes
TYPE SPPHRASEELEMENT DWORD FILL
   ulAudioTimeOffset      AS DWORD          ' ULONG
   ulAudioSizeTime        AS DWORD          ' ULONG
   ulAudioStreamOffset    AS DWORD          ' ULONG
   ulAudioSizeBytes       AS DWORD          ' ULONG
   ulRetainedStreamOffset AS DWORD          ' ULONG
   ulRetainedSizeBytes    AS DWORD          ' ULONG
   pszDisplayText         AS WSTRINGZ PTR   ' const WCHAR *
   pszLexicalForm         AS WSTRINGZ PTR   ' const WCHAR *
   pszPronunciation       AS WSTRINGZ PTR   ' const SPPHONEID *
   bDisplayAttributes     AS BYTE           ' BYTE
   RequiredConfidence     AS BYTE           ' signed char
   ActualConfidence       AS BYTE           ' signed char
   Reserved               AS BYTE           ' BYTE
   SREngineConfidence     AS SINGLE         ' float
END TYPE

' // Size = 32 bytes
TYPE SPPHRASERULE DWORD
   pszName            AS WSTRINGZ PTR       ' const WCHAR *
   ulId               AS DWORD              ' ULONG
   ulFirstElement     AS DWORD              ' ULONG
   ulCountOfElements  AS DWORD              ' ULONG
   pNextSibling       AS SPPHRASERULE PTR   ' const SPPHRASERULE *
   pFirstChild        AS SPPHRASERULE PTR   ' const SPPHRASERULE *
   SREngineConfidence AS SINGLE             ' float
   Confidence         AS BYTE               ' signed char
END TYPE

' enum SPPHRASEPROPERTYUNIONTYPE
%SPPPUT_UNUSED      = 0
%SPPPUT_ARRAY_INDEX = %SPPPUT_UNUSED + 1

' // Size = 4 bytes
TYPE SPPHRASEPROPERTY_UNION_STRUCT BYTE
   bType        AS BYTE   ' byte
   bReserved    AS BYTE   ' byte
   usArrayIndex AS WORD   ' unsigned short
END TYPE

' // Size = 4 bytes
UNION SPPHRASEPROPERTY_UNION
   ulId AS DWORD   ' ULONG
   SPPHRASEPROPERTY_UNION_STRUCT
END UNION

' // Size = 56 bytes
TYPE SPPHRASEPROPERTY   ' Must be 8 byte aligned
   pszName            AS WSTRINGZ PTR           ' const WCHAR *
   SPPHRASEPROPERTY_UNION
   pszValue           AS WSTRINGZ PTR           ' const WCHAR *
   alignment1__       AS DWORD
   vValue             AS tagVARIANT             ' VARIANT
   ulFirstElement     AS DWORD                  ' ULONG
   ulCountOfElements  AS DWORD                  ' ULONG
   pNextSibling       AS SPPHRASEPROPERTY PTR   ' const SPPHRASEPROPERTY *
   pFirstChild        AS SPPHRASEPROPERTY PTR   ' const SPPHRASEPROPERTY *
   SREngineConfidence AS SINGLE                 ' float
   Confidence         AS BYTE                   ' signed char
   alignment2__(2)    AS BYTE
END TYPE

' // Size = 16 bytes
TYPE SPPHRASEREPLACEMENT DWORD
   bDisplayAttributes AS BYTE           ' BYTE
   pszReplacementText AS WSTRINGZ PTR   ' const WCHAR *
   ulFirstElement     AS DWORD          ' ULONG
   ulCountOfElements  AS DWORD          ' ULONG
END TYPE

' // Size = 20 bytes
TYPE SPSEMANTICERRORINFO
   ulLineNumber   AS DWORD          ' ULONG
   pszScriptLine  AS WSTRINGZ PTR   ' LPWSTR
   pszSource      AS WSTRINGZ PTR   ' LPWSTR
   pszDescription AS WSTRINGZ PTR   ' LPWSTR
   hrResultCode   AS LONG           ' HRESULT
END TYPE

' enum SPSEMANTICFORMAT
%SPSMF_SAPI_PROPERTIES                 = 0
%SPSMF_SRGS_SEMANTICINTERPRETATION_MS  = 1
%SPSMF_SRGS_SAPIPROPERTIES             = 2
%SPSMF_UPS                             = 4
%SPSMF_SRGS_SEMANTICINTERPRETATION_W3C = 8

' // Size = 120 bytes
TYPE SPPHRASE_50   ' Must be 8 byte aligned
   cbSize                    AS DWORD                     ' ULONG
   LangId                    AS WORD                      ' WORD
   wHomophoneGroupId         AS WORD                      ' WORD
   ullGrammarID              AS QUAD                      ' ULONGLONG
   ftStartTime               AS QUAD                      ' ULONGLONG
   ullAudioStreamPosition    AS QUAD                      ' ULONGLONG
   ulAudioSizeBytes          AS DWORD                     ' ULONG
   ulRetainedSizeBytes       AS DWORD                     ' ULONG
   ulAudioSizeTime           AS DWORD                     ' ULONG
   Rule                      AS SPPHRASERULE              ' SPPHRASERULE
   pProperties               AS SPPHRASEPROPERTY PTR      ' const SPPHRASEPROPERTY *
   pElements                 AS SPPHRASEELEMENT PTR       ' const SPPHRASEELEMENT *
   cReplacements             AS DWORD                     ' ULONG
   pReplacements             AS SPPHRASEREPLACEMENT PTR   ' const SPPHRASEREPLACEMENT *
   alignment__               AS DWORD                     ' // To keep 8 byte alignment
   SREngineID                AS GUID                      ' GUID
   ulSREnginePrivateDataSize AS DWORD                     ' ULONG
   pSREnginePrivateData      AS BYTE PTR                  ' const BYTE *
END TYPE

' // Size = 128 bytes
TYPE SPPHRASE_53   ' Must be 8 byte aligned
   cbSize                    AS DWORD                     ' ULONG
   LangId                    AS WORD                      ' WORD
   wHomophoneGroupId         AS WORD                      ' WORD
   ullGrammarID              AS QUAD                      ' ULONGLONG
   ftStartTime               AS QUAD                      ' ULONGLONG
   ullAudioStreamPosition    AS QUAD                      ' ULONGLONG
   ulAudioSizeBytes          AS DWORD                     ' ULONG
   ulRetainedSizeBytes       AS DWORD                     ' ULONG
   ulAudioSizeTime           AS DWORD                     ' ULONG
   Rule                      AS SPPHRASERULE              ' SPPHRASERULE
   pProperties               AS SPPHRASEPROPERTY PTR      ' const SPPHRASEPROPERTY *
   pElements                 AS SPPHRASEELEMENT PTR       ' const SPPHRASEELEMENT *
   cReplacements             AS DWORD                     ' ULONG
   pReplacements             AS SPPHRASEREPLACEMENT PTR   ' const SPPHRASEREPLACEMENT *
   alignment__               AS DWORD                     ' // To keep 8 byte alignment
   SREngineID                AS GUID                      ' GUID
   ulSREnginePrivateDataSize AS DWORD                     ' ULONG
   pSREnginePrivateData      AS BYTE PTR                  ' const BYTE *
   pSML                      AS WSTRINGZ PTR              ' LPWSTR pSML
   pSemanticErrorInfo        AS SPSEMANTICERRORINFO PTR   ' SPSEMANTICERRORINFO *pSemanticErrorInfo
END TYPE

' // Size = 136 bytes
TYPE SPPHRASE_54   ' Must be 8 byte aligned
   cbSize                    AS DWORD                     ' ULONG
   LangId                    AS WORD                      ' WORD
   wHomophoneGroupId         AS WORD                      ' WORD
   ullGrammarID              AS QUAD                      ' ULONGLONG
   ftStartTime               AS QUAD                      ' ULONGLONG
   ullAudioStreamPosition    AS QUAD                      ' ULONGLONG
   ulAudioSizeBytes          AS DWORD                     ' ULONG
   ulRetainedSizeBytes       AS DWORD                     ' ULONG
   ulAudioSizeTime           AS DWORD                     ' ULONG
   Rule                      AS SPPHRASERULE              ' SPPHRASERULE
   pProperties               AS SPPHRASEPROPERTY PTR      ' const SPPHRASEPROPERTY *
   pElements                 AS SPPHRASEELEMENT PTR       ' const SPPHRASEELEMENT *
   cReplacements             AS DWORD                     ' ULONG
   pReplacements             AS SPPHRASEREPLACEMENT PTR   ' const SPPHRASEREPLACEMENT *
   alignment__               AS DWORD                     ' // To keep 8 byte alignment
   SREngineID                AS GUID                      ' GUID
   ulSREnginePrivateDataSize AS DWORD                     ' ULONG
   pSREnginePrivateData      AS BYTE PTR                  ' const BYTE *
   pSML                      AS WSTRINGZ PTR              ' LPWSTR pSML
   pSemanticErrorInfo        AS SPSEMANTICERRORINFO PTR   ' SPSEMANTICERRORINFO *pSemanticErrorInfo
   SemanticTagFormat         AS LONG                      ' SPSEMANTICFORMAT <enum>
   alignment2__              AS DWORD                     ' // To keep 8 byte alignment
END TYPE

#IF %SAPI_VER =< &H051
   MACRO SPPHRASE = SPPHRASE_50
#ELSEIF %SAPI_VER = &H053
   MACRO SPPHRASE = SPPHRASE_53
#ELSE
   MACRO SPPHRASE = SPPHRASE_54
#ENDIF

' // Size = 4 bytes
TYPE SPSERIALIZEDPHRASE DWORD
   ulSerializedSize AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE SPRULE DWORD
   pszRuleName  AS WSTRINGZ PTR   ' LPCWSTR
   ulRuleId     AS DWORD          ' ULONG
   dwAttributes AS DWORD          ' DWORD
END TYPE

' enum SPVALUETYPE
%SPDF_PROPERTY      = &H1
%SPDF_REPLACEMENT   = &H2
%SPDF_RULE          = &H4
%SPDF_DISPLAYTEXT   = &H8
%SPDF_LEXICALFORM   = &H10
%SPDF_PRONUNCIATION = &H20
%SPDF_AUDIO         = &H40
%SPDF_ALTERNATES    = &H80
%SPDF_ALL           = &Hff

' // Size = 4 bytes
TYPE SPBINARYGRAMMAR DWORD
   ulTotalSerializedSize AS DWORD   ' ULONG
END TYPE

' enum SPPHRASERNG
%SPPR_ALL_ELEMENTS  = -1

%SP_GETWHOLEPHRASE = %SPPR_ALL_ELEMENTS
%SPRR_ALL_ELEMENTS = %SPPR_ALL_ELEMENTS

'typedef void *SPSTATEHANDLE;

' enum SPRECOEVENTFLAGS
%SPREF_AutoPause        = 1    ' 1 << 0
%SPREF_Emulated         = 2    ' 1 << 1
%SPREF_SMLTimeout       = 4    ' 1 << 2
%SPREF_ExtendableParse  = 8    ' 1 << 3
%SPREF_ReSent           = 16   ' 1 << 4
%SPREF_Hypothesis       = 32   ' 1 << 5
%SPREF_FalseRecognition = 64   ' 1 << 6

' enum SPPARTOFSPEECH
%SPPS_NotOverriden = -1
%SPPS_Unknown      = 0
%SPPS_Noun         = &H1000
%SPPS_Verb         = &H2000
%SPPS_Modifier     = &H3000
%SPPS_Function     = &H4000
%SPPS_Interjection = &H5000
%SPPS_Noncontent   = &H6000
%SPPS_LMA          = &H7000
%SPPS_SuppressWord = &Hf000

' enum SPLEXICONTYPE
%eLEXTYPE_USER       = &H1          ' 1L << 0
%eLEXTYPE_APP        = &H2          ' 1L << 1
%eLEXTYPE_RESERVED1  = &H4          ' 1L << 2
%eLEXTYPE_RESERVED2  = &H8          ' 1L << 3
%eLEXTYPE_RESERVED3  = &H10         ' 1L << 4
%eLEXTYPE_RESERVED4  = &H20         ' 1L << 5
%eLEXTYPE_RESERVED5  = &H40         ' 1L << 6
%eLEXTYPE_RESERVED6  = &H80         ' 1L << 7
%eLEXTYPE_RESERVED7  = &H100        ' 1L << 8
%eLEXTYPE_RESERVED8  = &H200        ' 1L << 9
%eLEXTYPE_RESERVED9  = &H400        ' 1L << 10
%eLEXTYPE_RESERVED10 = &H800        ' 1L << 11
%eLEXTYPE_PRIVATE1   = &H1000       ' 1L << 12
%eLEXTYPE_PRIVATE2   = &H2000       ' 1L << 13
%eLEXTYPE_PRIVATE3   = &H4000       ' 1L << 14
%eLEXTYPE_PRIVATE4   = &H8000       ' 1L << 15
%eLEXTYPE_PRIVATE5   = &H10000      ' 1L << 16
%eLEXTYPE_PRIVATE6   = &H20000      ' 1L << 17
%eLEXTYPE_PRIVATE7   = &H40000      ' 1L << 18
%eLEXTYPE_PRIVATE8   = &H80000      ' 1L << 19
%eLEXTYPE_PRIVATE9   = &H100000     ' 1L << 20
%eLEXTYPE_PRIVATE10  = &H200000     ' 1L << 21
%eLEXTYPE_PRIVATE11  = &H400000     ' 1L << 22
%eLEXTYPE_PRIVATE12  = &H800000     ' 1L << 23
%eLEXTYPE_PRIVATE13  = &H1000000    ' 1L << 24
%eLEXTYPE_PRIVATE14  = &H2000000    ' 1L << 25
%eLEXTYPE_PRIVATE15  = &H4000000    ' 1L << 26
%eLEXTYPE_PRIVATE16  = &H8000000    ' 1L << 27
%eLEXTYPE_PRIVATE17  = &H10000000   ' 1L << 28
%eLEXTYPE_PRIVATE18  = &H20000000   ' 1L << 29
%eLEXTYPE_PRIVATE19  = &H40000000   ' 1L << 30
%eLEXTYPE_PRIVATE20  = &H80000000   ' 1L << 31   ' -2147483648

' enum SPWORDTYPE
%eWORDTYPE_ADDED   = 1   ' 1L << 0
%eWORDTYPE_DELETED = 2   ' 1L << 1

'enum SPPRONUNCIATIONFLAGS
%ePRONFLAG_USED    = 1   '  1 << 0

' // Size = 20 bytes
TYPE SPWORDPRONUNCIATION
   pNextWordPronunciation AS  SPWORDPRONUNCIATION PTR    ' struct SPWORDPRONUNCIATION *
   eLexiconType           AS  LONG                       ' SPLEXICONTYPE enum
   LangId                 AS  WORD                       ' WORD
   wReserved              AS  WORD                       ' WORD
   ePartOfSpeech          AS  LONG                       ' SPPARTOFSPEECH enum
   szPronunciation        AS  WSTRINGZ * 2               ' SPPHONEID szPronunciation[ 1 ]
   ' Note: We are using AS WSTRINGZ * 2 to keep DWORD alignment. The length is variable.
END TYPE

' // Size = 12 bytes
TYPE SPWORDPRONUNCIATIONLIST DWORD
   ulSize                  AS DWORD                      ' ULONG
   pvBuffer                AS BYTE PTR                   ' BYTE *
   pFirstWordPronunciation AS SPWORDPRONUNCIATION PTR    ' SPWORDPRONUNCIATION *
END TYPE

' // Size = 20 bytes
TYPE SPWORD DWORD FILL
   pNextWord               AS SPWORD PTR                 ' struct SPWORD *
   LangId                  AS WORD                       ' WORD
   wReserved               AS WORD                       ' WORD
   eWordType               AS LONG                       ' SPWORDTYPE enum
   pszWord                 AS WSTRINGZ PTR               ' WCHAR *
   pFirstWordPronunciation AS SPWORDPRONUNCIATION PTR    ' SPWORDPRONUNCIATION *
END TYPE

' // Size = 12 bytes
TYPE SPWORDLIST DWORD
   ulSize     AS DWORD        ' ULONG
   pvBuffer   AS BYTE PTR     ' BYTE *
   pFirstWord AS SPWORD PTR   ' SPWORD *
END TYPE


' ########################################################################################
' Interface name = ISpLexicon
' IID = {DA41A7C2-5383-4DB2-916B-6C1719E3DB58}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpLexicon_INTERFACE_DEFINED)
    %ISpLexicon_INTERFACE_DEFINED = 1

INTERFACE ISpLexicon $IID_ISpLexicon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPronunciations ( _                         ' VTable offset = 12
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pWordPronunciationList AS SPWORDPRONUNCIATIONLIST _ ' __in_out SPWORDPRONUNCIATIONLIST *pWordPronunciationList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPronunciation ( _                          ' VTable offset = 16
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL ePartOfSpeech AS LONG _                      ' __in SPPARTOFSPEECH ePartOfSpeech
   , BYREF pszPronunciation AS WSTRINGZ _               ' __in const SPPHONEID *pszPronunciation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePronunciation ( _                       ' VTable offset = 20
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL ePartOfSpeech AS LONG _                      ' __in SPPARTOFSPEECH ePartOfSpeech
   , BYREF pszPronunciation AS WSTRINGZ _               ' __in const SPPHONEID *pszPronunciation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGeneration ( _                             ' VTable offset = 24
     BYREF pdwGeneration AS DWORD _                     ' __out DWORD *pdwGeneration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGenerationChange ( _                       ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWords ( _                                  ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pdwCookie AS DWORD _                         ' __in_out DWORD *pdwCookie
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpLexicon_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpContainerLexicon
' IID = {8565572F-C094-41CC-B56E-10BD9C3FF044}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpLexicon
' ########################################################################################

#IF NOT %DEF(%ISpContainerLexicon_INTERFACE_DEFINED)
    %ISpContainerLexicon_INTERFACE_DEFINED = 1

INTERFACE ISpContainerLexicon $IID_ISpContainerLexicon

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpLexicon methods
   ' =====================================================================================
   METHOD GetPronunciations ( _                         ' VTable offset = 12
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pWordPronunciationList AS SPWORDPRONUNCIATIONLIST _ ' __in_out SPWORDPRONUNCIATIONLIST *pWordPronunciationList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPronunciation ( _                          ' VTable offset = 16
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL ePartOfSpeech AS LONG _                      ' __in SPPARTOFSPEECH ePartOfSpeech
   , BYREF pszPronunciation AS WSTRINGZ _               ' __in const SPPHONEID *pszPronunciation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePronunciation ( _                       ' VTable offset = 20
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYVAL ePartOfSpeech AS LONG _                      ' __in SPPARTOFSPEECH ePartOfSpeech
   , BYREF pszPronunciation AS WSTRINGZ _               ' __in const SPPHONEID *pszPronunciation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGeneration ( _                             ' VTable offset = 24
     BYREF pdwGeneration AS DWORD _                     ' __out DWORD *pdwGeneration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGenerationChange ( _                       ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWords ( _                                  ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pdwCookie AS DWORD _                         ' __in_out DWORD *pdwCookie
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpContainerLexicon method
   ' =====================================================================================
   METHOD AddLexicon ( _                                ' VTable offset = 36
     BYVAL pAddLexicon AS ISpLexicon _                  ' __in ISpLexicon *pAddLexicon
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpContainerLexicon_INTERFACE_DEFINED__ */

' enum SPSHORTCUTTYPE
%SPSHT_NotOverriden = -1
%SPSHT_Unknown      = 0
%SPSHT_EMAIL        = &H1000
%SPSHT_OTHER        = &H2000
%SPPS_RESERVED1     = &H3000
%SPPS_RESERVED2     = &H4000
%SPPS_RESERVED3     = &H5000
%SPPS_RESERVED4     = &Hf000

' // Size = 20 bytes
TYPE SPSHORTCUTPAIR DWORD FILL
   pNextSHORTCUTPAIR AS SPSHORTCUTPAIR PTR   ' struct SPSHORTCUTPAIR *
   LangID            AS WORD                 ' WORD
   shType            AS LONG                 ' SPSHORTCUTTYPE enum
   pszDisplay        AS WSTRINGZ PTR         ' LPWSTR
   pszSpoken         AS WSTRINGZ PTR         ' LPWSTR
END TYPE

' // Size = 12 bytes
TYPE SPSHORTCUTPAIRLIST DWORD
   ulSize             AS DWORD                ' ULONG
   pvBuffer           AS BYTE PTR             ' BYTE *
   pFirstShortcutPair AS SPSHORTCUTPAIR PTR   ' SPSHORTCUTPAIR *
END TYPE

' ########################################################################################
' Interface name = ISpShortcut
' IID = 3DF681E2-EA56-11D9-8BDE-F66BAD1E3F3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpShortcut_INTERFACE_DEFINED)
    %ISpShortcut_INTERFACE_DEFINED = 1

INTERFACE ISpShortcut $IID_ISpShortcut

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddShortcut ( _                               ' VTable offset = 12
     BYREF pszDisplay AS WSTRINGZ _                     ' __in LPCWSTR pszDisplay
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYREF pszSpoken AS WSTRINGZ _                      ' __in LPCWSTR pszSpoken
   , BYVAL shType AS LONG _                             ' __in SPSHORTCUTTYPE shType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveShortcut ( _                            ' VTable offset = 16
     BYREF pszDisplay AS WSTRINGZ _                     ' __in LPCWSTR pszDisplay
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYREF pszSpoken AS WSTRINGZ _                      ' __in LPCWSTR pszSpoken
   , BYVAL shType AS LONG _                             ' __in SPSHORTCUTTYPE shType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShortcuts ( _                              ' VTable offset = 20
     BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYREF pShortcutpairList AS SPSHORTCUTPAIRLIST _    ' __in_out SPSHORTCUTPAIRLIST *pShortcutpairList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGeneration ( _                             ' VTable offset = 24
     BYVAL pdwGeneration AS DWORD _                     ' __in DWORD *pdwGeneration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWordsFromGenerationChange ( _              ' VTable offset = 28
     BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWords ( _                                  ' VTable offset = 32
     BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pdwCookie AS DWORD _                         ' __in_out DWORD *pdwCookie
   , BYREF pWordList AS SPWORDLIST _                    ' __in_out SPWORDLIST *pWordList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShortcutsForGeneration ( _                 ' VTable offset = 36
     BYREF pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pdwCookie AS DWORD _                         ' __in_out DWORD *pdwCookie
   , BYREF pShortcutpairList AS SPSHORTCUTPAIRLIST _    ' __in_out SPSHORTCUTPAIRLIST *pShortcutpairList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGenerationChange ( _                       ' VTable offset = 40
     BYVAL pdwGeneration AS DWORD _                     ' __in_out DWORD *pdwGeneration
   , BYREF pShortcutpairList AS SPSHORTCUTPAIRLIST _    ' __in_out SPSHORTCUTPAIRLIST *pShortcutpairList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpShortcut_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpPhoneConverter
' IID = {8445C581-0CAC-4A38-ABFE-9B2CE2826455}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpObjectWithToken
' ########################################################################################

#IF NOT %DEF(%ISpPhoneConverter_INTERFACE_DEFINED)
    %ISpPhoneConverter_INTERFACE_DEFINED = 1

INTERFACE ISpPhoneConverter $IID_ISpPhoneConverter

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpObjectWithToken Methods
   ' =====================================================================================
   METHOD SetObjectToken ( _                            ' VTable offset = 12
     BYVAL pToken AS ISpObjectToken _                   ' __in ISpObjectToken *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectToken ( _                            ' VTable offset = 16
     BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpPhoneConverter Methods
   ' =====================================================================================
   METHOD PhoneToId ( _                                 ' VTable offset = 20
     BYREF pszPhone AS WSTRINGZ _                       ' __in const WCHAR *pszPhone
   , BYREF pId AS WSTRINGZ _                            ' __out SPPHONEID *pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IdToPhone ( _                                 ' VTable offset = 24
     BYREF pId AS WSTRINGZ _                            ' __in const SPPHONEID *pId
   , BYREF pszPhone AS WSTRINGZ _                       ' __out WCHAR *pszPhone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhoneConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpPhoneticAlphabetConverter
' IID = 133ADCD4-19B4-4020-9FDC-842E78253B17
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpPhoneticAlphabetConverter_INTERFACE_DEFINED)
    %ISpPhoneticAlphabetConverter_INTERFACE_DEFINED = 1

INTERFACE ISpPhoneticAlphabetConverter $IID_ISpPhoneticAlphabetConverter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLangId ( _                                 ' VTable offset = 12
     BYREF pLangID AS WORD _                            ' __out WORD *pLangID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLangId ( _                                 ' VTable offset = 16
     BYVAL LangID AS WORD _                             ' __in WORD LangID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SAPI2UPS ( _                                  ' VTable offset = 20
     BYREF pszSAPIId AS WSTRINGZ _                      ' __in const SPPHONEID *pszSAPIId
   , BYREF pszUPSId AS DWORD _                          ' __out SPPHONEID *pszUPSId
   , BYVAL cMaxLength AS DWORD _                        ' __in DWORD cMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UPS2SAPI ( _                                  ' VTable offset = 24
     BYREF pszUPSId AS WSTRINGZ _                       ' __in const SPPHONEID *pszUPSId
   , BYREF pszSAPIId AS WSTRINGZ _                      ' __out SPPHONEID *pszSAPIId
   , BYVAL cMaxLength AS DWORD _                        ' __in DWORD cMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxConvertLength ( _                       ' VTable offset = 28
     BYVAL cSrcLength AS DWORD _                        ' __in DWORD cSrcLength
   , BYVAL bSAPI2UPS AS LONG _                          ' __in BOOL bSAPI2UPS
   , BYREF pcMaxDestLength AS DWORD _                   ' __out DWORD *pcMaxDestLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhoneticAlphabetConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpPhoneticAlphabetSelection
' IID = B2745EFD-42CE-48CA-81F1-A96E02538A90
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpPhoneticAlphabetSelection_INTERFACE_DEFINED)
    %ISpPhoneticAlphabetSelection_INTERFACE_DEFINED = 1

INTERFACE ISpPhoneticAlphabetSelection $IID_ISpPhoneticAlphabetSelection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsAlphabetUPS ( _                             ' VTable offset = 12
     BYREF pfIsUPS AS LONG _                            ' __out BOOL *pfIsUPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAlphabetToUPS ( _                          ' VTable offset = 16
     BYVAL fForceUPS AS LONG _                          ' __in BOOL fForceUPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhoneticAlphabetSelection_INTERFACE_DEFINED__ */


' // Size = 8 bytes
TYPE SPVPITCH DWORD
   MiddleAdj AS LONG
   RangeAdj  AS LONG
END TYPE

' enum SPVACTIONS
%SPVA_Speak           = 0
%SPVA_Silence         = %SPVA_Speak     + 1
%SPVA_Pronounce       = %SPVA_Silence   + 1
%SPVA_Bookmark        = %SPVA_Pronounce + 1
%SPVA_SpellOut        = %SPVA_Bookmark  + 1
%SPVA_Section         = %SPVA_SpellOut  + 1
%SPVA_ParseUnknownTag = %SPVA_Section   + 1

' // Size = 12 bytes
TYPE SPVCONTEXT DWORD
   pCategory AS WSTRINGZ PTR   ' LPCWSTR
   pBefore   AS WSTRINGZ PTR   ' LPCWSTR
   pAfter    AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 52 bytes
TYPE SPVSTATE DWORD FILL
   eAction       AS LONG           ' SPVACTIONS
   LangID        AS WORD           ' WORD
   wReserved     AS WORD           ' WORD
   EmphAdj       AS LONG           ' long
   RateAdj       AS LONG           ' long
   Volume        AS DWORD          ' ULONG
   PitchAdj      AS SPVPITCH       ' SPVPITCH
   SilenceMSecs  AS DWORD          ' ULONG
   pPhoneIds     AS WSTRINGZ PTR   ' SPPHONEID *
   ePartOfSpeech AS LONG           ' SPPARTOFSPEECH enum
   Context       AS SPVCONTEXT     ' SPVCONTEXT
END TYPE

' enum SPRUNSTATE
%SPRS_DONE        = 1   ' 1L << 0
%SPRS_IS_SPEAKING = 2   ' 1L << 1

' enum SPVLIMITS
%SPMIN_VOLUME = 0
%SPMAX_VOLUME = 100
%SPMIN_RATE   = -10
%SPMAX_RATE   = 10

' enum SPVPRIORITY
%SPVPRI_NORMAL = 0
%SPVPRI_ALERT  = 1   ' 1L << 0
%SPVPRI_OVER   = 2   ' 1L << 1

' // Size = 52 bytes
TYPE SPVOICESTATUS DWORD FILL
   ulCurrentStream    AS DWORD     ' ULONG
   ulLastStreamQueued AS DWORD     ' ULONG
   hrLastResult       AS LONG      ' HRESULT
   dwRunningState     AS DWORD     ' DWORD
   ulInputWordPos     AS DWORD     ' ULONG
   ulInputWordLen     AS DWORD     ' ULONG
   ulInputSentPos     AS DWORD     ' ULONG
   ulInputSentLen     AS DWORD     ' ULONG
   lBookmarkId        AS LONG      ' LONG
   PhonemeId          AS INTEGER   ' SPPHONEID
   VisemeId           AS LONG      ' SPVISEMES
   dwReserved1        AS DWORD     ' DWORD
   dwReserved2        AS DWORD     ' DWORD
END TYPE

' enum SPEAKFLAGS
%SPF_DEFAULT          = 0
%SPF_ASYNC            = &H1                                                                                                                                                             ' 1L << 0
%SPF_PURGEBEFORESPEAK = &H2                                                                                                                                                             ' 1L << 1
%SPF_IS_FILENAME      = &H4                                                                                                                                                             ' 1L << 2
%SPF_IS_XML           = &H8                                                                                                                                                             ' 1L << 3
%SPF_IS_NOT_XML       = &H10                                                                                                                                                            ' 1L << 4
%SPF_PERSIST_XML      = &H20                                                                                                                                                            ' 1L << 5
%SPF_NLP_SPEAK_PUNC   = &H40                                                                                                                                                            ' 1L << 6
%SPF_NLP_MASK         = %SPF_NLP_SPEAK_PUNC
%SPF_VOICE_MASK       = %SPF_ASYNC OR %SPF_PURGEBEFORESPEAK OR %SPF_IS_FILENAME OR %SPF_IS_XML OR %SPF_IS_NOT_XML OR %SPF_NLP_MASK OR %SPF_PERSIST_XML
%SPF_UNUSED_FLAGS     = NOT %SPF_VOICE_MASK


' ########################################################################################
' Interface name = ISpVoice
' IID = {6C44DF74-72B9-4992-A1EC-EF996E0422D4}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpEventSource
' ########################################################################################

#IF NOT %DEF(%ISpVoice_INTERFACE_DEFINED)
    %ISpVoice_INTERFACE_DEFINED = 1

INTERFACE ISpVoice $IID_ISpVoice

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySource Methods
   ' =====================================================================================
   METHOD SetNotifySink ( _                             ' VTable offset = 12
     BYVAL pNotifySink AS ISpNotifySink _               ' __in ISpNotifySink *pNotifySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWindowMessage ( _                    ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackFunction ( _                 ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackInterface ( _                ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWin32Event ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNotifyEvent ( _                        ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyEventHandle ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

   ' =====================================================================================
   ' ISpEventSource Methods
   ' =====================================================================================
   METHOD SetInterest ( _                               ' VTable offset = 40
     BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   , BYVAL ullQueuedInterest AS QUAD _                  ' __in ULONGLONG ullQueuedInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvents ( _                                 ' VTable offset = 44
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pEventArray AS SPEVENT _                     ' __out SPEVENT *pEventArray
   , BYREF pulFetched AS DWORD _                        ' __out ULONG *pulFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 48
     BYREF pInfo AS SPEVENTSOURCEINFO _                 ' __out SPEVENTSOURCEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpVoice Methods
   ' =====================================================================================
   METHOD SetOutput ( _                                 ' VTable offset = 52
     BYVAL pUnkOutput AS IUnknown _                     ' __in IUnknown *pUnkOutput
   , BYVAL fAllowFormatChanges AS LONG _                ' __in BOOL fAllowFormatChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputObjectToken ( _                      ' VTable offset = 56
     BYREF ppObjectToken AS ISpObjectToken _            ' __out ISpObjectToken **ppObjectToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStream ( _                           ' VTable offset = 60
     BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVoice ( _                                  ' VTable offset = 72
     BYVAL pToken AS ISpObjectToken _                   ' __in ISpObjectToken *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVoice ( _                                  ' VTable offset = 76
     BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Speak ( _                                     ' VTable offset = 80
     BYREF pwcs AS WSTRINGZ _                           ' __in const WCHAR *pwcs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulStreamNumber AS DWORD _                   ' __out ULONG *pulStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpeakStream ( _                               ' VTable offset = 84
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulStreamNumber AS DWORD _                   ' __out ULONG *pulStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 88
     BYREF pStatus AS SPVOICESTATUS _                   ' __out SPVOICESTATUS *pStatus
   , BYREF ppszLastBookmark AS DWORD _                  ' __out WCHAR **ppszLastBookmark
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 92
     BYREF pItemType AS WSTRINGZ _                      ' __in WCHAR *pItemType
   , BYVAL lNumItems AS LONG _                          ' __in long lNumItems
   , BYREF pulNumSkipped AS DWORD _                     ' __out ULONG *pulNumSkipped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 96
     BYVAL ePriority AS LONG _                          ' __in SPVPRIORITY ePriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 100
     BYREF pePriority AS LONG _                         ' __out SPVPRIORITY *pePriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAlertBoundary ( _                          ' VTable offset = 104
     BYVAL eBoundary AS LONG _                          ' __in SPEVENTENUM eBoundary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlertBoundary ( _                          ' VTable offset = 108
     BYREF peBoundary AS LONG _                         ' __out SPEVENTENUM *peBoundary
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRate ( _                                   ' VTable offset = 112
     BYVAL RateAdjust AS LONG _                         ' __in long RateAdjust
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 116
     BYREF pRateAdjust AS LONG _                        ' __out long *pRateAdjust
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVolume ( _                                 ' VTable offset = 120
     BYVAL usVolume AS WORD _                           ' __in USHORT usVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolume ( _                                 ' VTable offset = 124
     BYREF pusVolume AS WORD _                          ' __out USHORT *pusVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitUntilDone ( _                             ' VTable offset = 128
     BYVAL msTimeout AS DWORD _                         ' __in ULONG msTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSpeakTimeout ( _                       ' VTable offset = 132
     BYVAL msTimeout AS DWORD _                         ' __in ULONG msTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncSpeakTimeout ( _                       ' VTable offset = 136
     BYREF pmsTimeout AS DWORD _                        ' __out ULONG *pmsTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpeakCompleteEvent ( _                        ' VTable offset = 140
   ) AS DWORD                                           ' void
   ' =====================================================================================
   METHOD IsUISupported ( _                             ' VTable offset = 144
     BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYREF pfSupported AS LONG _                        ' __out BOOL *pfSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayUI ( _                                 ' VTable offset = 148
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pszTitle AS WSTRINGZ _                       ' __in const WCHAR *pszTitle
   , BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpVoice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpPhrase
' IID = {1A5C0354-B621-4B5A-8791-D306ED379E53}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpPhrase_INTERFACE_DEFINED)
    %ISpPhrase_INTERFACE_DEFINED = 1

INTERFACE ISpPhrase $IID_ISpPhrase

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhrase_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpPhraseAlt
' IID = {8FCEBC98-4E49-4067-9C6C-D86A0E092E3D}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpPhrase
' ########################################################################################

#IF NOT %DEF(%ISpPhraseAlt_INTERFACE_DEFINED)
    %ISpPhraseAlt_INTERFACE_DEFINED = 1

INTERFACE ISpPhraseAlt $IID_ISpPhraseAlt

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase Methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpPhraseAlt Methods
   ' =====================================================================================
   METHOD GetAltInfo ( _                                ' VTable offset = 28
     BYREF ppParent AS ISpPhrase _                      ' __out ISpPhrase **ppParent
   , BYREF pulStartElementInParent AS DWORD _           ' __out ULONG *pulStartElementInParent
   , BYREF pcElementsInParent AS DWORD _                ' __out ULONG *pcElementsInParent
   , BYREF pcElementsInAlt AS DWORD _                   ' __out ULONG *pcElementsInAlt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhraseAlt_INTERFACE_DEFINED__ */

' enum SPXMLRESULTOPTIONS
%SPXRO_SML            = 0
%SPXRO_Alternates_SML = 1

' ########################################################################################
' Interface name = ISpPhrase2
' IID = F264DA52-E457-4696-B856-A737B717AF79
' Inherited interface = ISpPhrase
' ########################################################################################

#IF NOT %DEF(%ISpPhrase2_INTERFACE_DEFINED)
    %ISpPhrase2_INTERFACE_DEFINED = 1

INTERFACE ISpPhrase2 $IID_ISpPhrase2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpPhrase2 methods
   ' =====================================================================================
   METHOD GetXMLResult ( _                              ' VTable offset = 28
     BYREF ppszCoMemXMLResult AS DWORD _                ' __out LPWSTR *ppszCoMemXMLResult
   , BYVAL Options AS LONG _                            ' __in SPXMLRESULTOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXMLErrorInfo ( _                           ' VTable offset = 32
     BYREF pSemanticErrorInfo AS SPSEMANTICERRORINFO _  ' __out SPSEMANTICERRORINFO *pSemanticErrorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudio ( _                                  ' VTable offset = 36
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhrase2_INTERFACE_DEFINED__ */

' // Size = 32 bytes
TYPE SPRECORESULTTIMES   ' Must be 8 byte aligned
   ftStreamTime AS FILETIME   ' FILETIME
   ullLength    AS QUAD       ' ULONGLONG
   dwTickCount  AS DWORD      ' DWORD
   alignment__  AS DWORD      ' // To keep 8 byte alignment
   ullStart     AS QUAD       ' ULONGLONG
END TYPE

' // Size = 4 bytes
TYPE SPSERIALIZEDRESULT DWORD
   ulSerializedSize AS DWORD   ' ULONG
END TYPE


' ########################################################################################
' Interface name = ISpRecoResult
' IID = {20B053BE-E235-43CD-9A2A-8D17A48B7842}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpPhrase
' ########################################################################################

#IF NOT %DEF(%ISpRecoResult_INTERFACE_DEFINED)
    %ISpRecoResult_INTERFACE_DEFINED = 1

INTERFACE ISpRecoResult $IID_ISpRecoResult

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase Methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoResult Methods
   ' =====================================================================================
   METHOD GetResultTimes ( _                            ' VTable offset = 28
     BYREF pTimes AS SPRECORESULTTIMES _                ' __out SPRECORESULTTIMES *pTimes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 32
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL ulRequestCount AS DWORD _                    ' __in ULONG ulRequestCount
   , BYREF ppPhrases AS ISpPhraseAlt _                  ' __out ISpPhraseAlt **ppPhrases
   , BYREF pcPhrasesReturned AS DWORD _                 ' __out ULONG *pcPhrasesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudio ( _                                  ' VTable offset = 36
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpeakAudio ( _                                ' VTable offset = 40
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulStreamNumber AS DWORD _                   ' __out ULONG *pulStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Serialize ( _                                 ' VTable offset = 44
     BYREF ppCoMemSerializedResult AS SPSERIALIZEDRESULT _ ' __out SPSERIALIZEDRESULT **ppCoMemSerializedResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleAudio ( _                                ' VTable offset = 48
     BYREF pAudioFormatId AS GUID _                     ' __in const GUID *pAudioFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoContext ( _                            ' VTable offset = 52
     BYREF ppRecoContext AS ISpRecoContext _            ' __out ISpRecoContext **ppRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoResult_INTERFACE_DEFINED__ */

' enum SPCOMMITFLAGS
%SPCF_NONE                = 0
%SPCF_ADD_TO_USER_LEXICON = 1   ' 1 << 0
%SPCF_DEFINITE_CORRECTION = 2   ' 1 << 1

' ########################################################################################
' Interface name = ISpRecoResult2
' IID = 27CAC6C4-88F2-41F2-8817-0C95E59F1E6E
' Inherited interface = ISpRecoResult
' ########################################################################################

#IF NOT %DEF(%ISpRecoResult2_INTERFACE_DEFINED)
    %ISpRecoResult2_INTERFACE_DEFINED = 1

INTERFACE ISpRecoResult2 $IID_ISpRecoResult2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoResult Methods
   ' =====================================================================================
   METHOD GetResultTimes ( _                            ' VTable offset = 28
     BYREF pTimes AS SPRECORESULTTIMES _                ' __out SPRECORESULTTIMES *pTimes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 32
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL ulRequestCount AS DWORD _                    ' __in ULONG ulRequestCount
   , BYREF ppPhrases AS ISpPhraseAlt _                  ' __out ISpPhraseAlt **ppPhrases
   , BYREF pcPhrasesReturned AS DWORD _                 ' __out ULONG *pcPhrasesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudio ( _                                  ' VTable offset = 36
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpeakAudio ( _                                ' VTable offset = 40
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulStreamNumber AS DWORD _                   ' __out ULONG *pulStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Serialize ( _                                 ' VTable offset = 44
     BYREF ppCoMemSerializedResult AS SPSERIALIZEDRESULT _ ' __out SPSERIALIZEDRESULT **ppCoMemSerializedResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleAudio ( _                                ' VTable offset = 48
     BYREF pAudioFormatId AS GUID _                     ' __in const GUID *pAudioFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoContext ( _                            ' VTable offset = 52
     BYREF ppRecoContext AS ISpRecoContext _            ' __out ISpRecoContext **ppRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoResult2 Methods
   ' =====================================================================================
   METHOD CommitAlternate ( _                           ' VTable offset = 56
     BYVAL pPhraseAlt AS ISpPhraseAlt _                 ' __in ISpPhraseAlt *pPhraseAlt
   , BYREF ppNewResult AS ISpRecoResult _               ' __out ISpRecoResult **ppNewResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitText ( _                                ' VTable offset = 60
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF pszCorrectedData AS WSTRINGZ _               ' __in_opt LPCWSTR pszCorrectedData
   , BYVAL eCommitFlags AS DWORD _                      ' __in DWORD eCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextFeedback ( _                           ' VTable offset = 64
     BYREF pszFeedback AS WSTRINGZ _                    ' __in LPCWSTR pszFeedback
   , BYVAL fSuccessful AS LONG _                        ' __in BOOL fSuccessful
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoResult2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpXMLRecoResult
' IID = AE39362B-45A8-4074-9B9E-CCF49AA2D0B6
' Inherited interface = ISpRecoResult
' ########################################################################################

#IF NOT %DEF(%ISpXMLRecoResult_INTERFACE_DEFINED)
    %ISpXMLRecoResult_INTERFACE_DEFINED = 1

INTERFACE ISpXMLRecoResult $IID_ISpXMLRecoResult

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoResult Methods
   ' =====================================================================================
   METHOD GetResultTimes ( _                            ' VTable offset = 28
     BYREF pTimes AS SPRECORESULTTIMES _                ' __out SPRECORESULTTIMES *pTimes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 32
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL ulRequestCount AS DWORD _                    ' __in ULONG ulRequestCount
   , BYREF ppPhrases AS ISpPhraseAlt _                  ' __out ISpPhraseAlt **ppPhrases
   , BYREF pcPhrasesReturned AS DWORD _                 ' __out ULONG *pcPhrasesReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudio ( _                                  ' VTable offset = 36
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpeakAudio ( _                                ' VTable offset = 40
     BYVAL ulStartElement AS DWORD _                    ' __in ULONG ulStartElement
   , BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulStreamNumber AS DWORD _                   ' __out ULONG *pulStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Serialize ( _                                 ' VTable offset = 44
     BYREF ppCoMemSerializedResult AS SPSERIALIZEDRESULT _ ' __out SPSERIALIZEDRESULT **ppCoMemSerializedResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleAudio ( _                                ' VTable offset = 48
     BYREF pAudioFormatId AS GUID _                     ' __in const GUID *pAudioFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoContext ( _                            ' VTable offset = 52
     BYREF ppRecoContext AS ISpRecoContext _            ' __out ISpRecoContext **ppRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpXMLRecoResult Methods
   ' =====================================================================================
   METHOD GetXMLResult ( _                              ' VTable offset = 56
     BYVAL ppszCoMemXMLResult AS DWORD _                ' __out LPWSTR *ppszCoMemXMLResult
   , BYVAL Options AS LONG _                            ' __in SPXMLRESULTOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXMLErrorInfo ( _                           ' VTable offset = 60
     BYREF pSemanticErrorInfo AS SPSEMANTICERRORINFO _  ' __out SPSEMANTICERRORINFO *pSemanticErrorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpXMLRecoResult_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE SPTEXTSELECTIONINFO DWORD
   ulStartActiveOffset AS DWORD   ' ULONG
   cchActiveChars      AS DWORD   ' ULONG
   ulStartSelection    AS DWORD   ' ULONG
   cchSelection        AS DWORD   ' ULONG
END TYPE

' enum SPWORDPRONOUNCEABLE
%SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE = 0
%SPWP_UNKNOWN_WORD_PRONOUNCEABLE   = 1
%SPWP_KNOWN_WORD_PRONOUNCEABLE     = 2

' enum SPGRAMMARSTATE
%SPGS_DISABLED  = 0
%SPGS_ENABLED   = 1
%SPGS_EXCLUSIVE = 3

' enum SPCONTEXTSTATE
%SPCS_DISABLED = 0
%SPCS_ENABLED  = 1

' enum SPRULESTATE
%SPRS_INACTIVE               = 0
%SPRS_ACTIVE                 = 1
%SPRS_ACTIVE_WITH_AUTO_PAUSE = 3
%SPRS_ACTIVE_USER_DELIMITED  = 4

%SP_STREAMPOS_ASAP = 0
%SP_STREAMPOS_REALTIME = -1

%SPRULETRANS_TEXTBUFFER = &HFFFFFFFF???   ' (SPSTATEHANDLE)(-1)
%SPRULETRANS_WILDCARD   = &HFFFFFFFE???   ' (SPSTATEHANDLE)(-2)
%SPRULETRANS_DICTATION  = &HFFFFFFFD???   ' (SPSTATEHANDLE)(-3)

' enum SPGRAMMARWORDTYPE
%SPWT_DISPLAY       = 0
%SPWT_LEXICAL       = %SPWT_DISPLAY + 1
%SPWT_PRONUNCIATION = %SPWT_LEXICAL + 1
%SPWT_LEXICAL_NO_SPECIAL_CHARS = %SPWT_PRONUNCIATION + 1

' // Size = 32 bytes
TYPE SPPROPERTYINFO   ' Must be 8 byte aligned
   pszName     AS WSTRINGZ PTR   ' const WCHAR *
   ulId        AS DWORD          ' ULONG
   pszValue    AS WSTRINGZ PTR   ' const WCHAR *
   alignment__ AS DWORD          ' // To keep 8 byte alignment
   vValue      AS tagVARIANT     ' VARIANT
END TYPE

' enum SPCFGRULEATTRIBUTES
%SPRAF_TopLevel      = &H1       ' 1 << 0
%SPRAF_Active        = &H2       ' 1 << 1
%SPRAF_Export        = &H4       ' 1 << 2
%SPRAF_Import        = &H8       ' 1 << 3
%SPRAF_Interpreter   = &H10      ' 1 << 4
%SPRAF_Dynamic       = &H20      ' 1 << 5
%SPRAF_Root          = &H40      ' 1 << 6
%SPRAF_AutoPause     = &H10000   ' 1 << 16
%SPRAF_UserDelimited = &H20000   ' 1 << 17


' ########################################################################################
' Interface name = ISpGrammarBuilder
' IID = {8137828F-591A-4A42-BE58-49EA7EBAAC68}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpGrammarBuilder_INTERFACE_DEFINED)
    %ISpGrammarBuilder_INTERFACE_DEFINED = 1

INTERFACE ISpGrammarBuilder $IID_ISpGrammarBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResetGrammar ( _                              ' VTable offset = 12
     BYVAL NewLanguage AS WORD _                        ' __in WORD NewLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRule ( _                                   ' VTable offset = 16
     BYREF pszRuleName AS WSTRINGZ _                    ' __in const WCHAR *pszRuleName
   , BYVAL dwRuleId AS DWORD _                          ' __in DWORD dwRuleId
   , BYVAL dwAttributes AS DWORD _                      ' __in DWORD dwAttributes
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   , BYREF phInitialState AS DWORD _                    ' __out SPSTATEHANDLE *phInitialState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRule ( _                                 ' VTable offset = 20
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNewState ( _                            ' VTable offset = 24
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   , BYREF phState AS DWORD _                           ' __out SPSTATEHANDLE *phState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddWordTransition ( _                         ' VTable offset = 28
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYREF psz AS WSTRINGZ _                            ' __in const WCHAR *psz
   , BYREF pszSeparators AS WSTRINGZ _                  ' __in const WCHAR *pszSeparators
   , BYVAL eWordType AS LONG _                          ' __in SPGRAMMARWORDTYPE eWordType
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRuleTransition ( _                         ' VTable offset = 32
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYVAL hRule AS DWORD _                             ' __in SPSTATEHANDLE hRule
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddResource ( _                               ' VTable offset = 36
     BYVAL hRuleState AS DWORD _                        ' __in SPSTATEHANDLE hRuleState
   , BYREF pszResourceName AS WSTRINGZ _                ' __in const WCHAR *pszResourceName
   , BYREF pszResourceValue AS WSTRINGZ _               ' __in const WCHAR *pszResourceValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 40
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpGrammarBuilder_INTERFACE_DEFINED__ */


' enum SPLOADOPTIONS
%SPLO_STATIC  = 0
%SPLO_DYNAMIC = 1


' ########################################################################################
' Interface name = ISpRecoGrammar
' IID = {2177DB29-7F45-47D0-8554-067E91C80502}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpGrammarBuilder
' ########################################################################################

#IF NOT %DEF(%ISpRecoGrammar_INTERFACE_DEFINED)
    %ISpRecoGrammar_INTERFACE_DEFINED = 1

INTERFACE ISpRecoGrammar $IID_ISpRecoGrammar

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpGrammarBuilder Methods
   ' =====================================================================================
   METHOD ResetGrammar ( _                              ' VTable offset = 12
     BYVAL NewLanguage AS WORD _                        ' __in WORD NewLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRule ( _                                   ' VTable offset = 16
     BYREF pszRuleName AS WSTRINGZ _                    ' __in const WCHAR *pszRuleName
   , BYVAL dwRuleId AS DWORD _                          ' __in DWORD dwRuleId
   , BYVAL dwAttributes AS DWORD _                      ' __in DWORD dwAttributes
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   , BYREF phInitialState AS DWORD _                    ' __out SPSTATEHANDLE *phInitialState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRule ( _                                 ' VTable offset = 20
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNewState ( _                            ' VTable offset = 24
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   , BYREF phState AS DWORD _                           ' __out SPSTATEHANDLE *phState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddWordTransition ( _                         ' VTable offset = 28
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYREF psz AS WSTRINGZ _                            ' __in const WCHAR *psz
   , BYREF pszSeparators AS WSTRINGZ _                  ' __in const WCHAR *pszSeparators
   , BYVAL eWordType AS LONG _                          ' __in SPGRAMMARWORDTYPE eWordType
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRuleTransition ( _                         ' VTable offset = 32
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYVAL hRule AS DWORD _                             ' __in SPSTATEHANDLE hRule
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddResource ( _                               ' VTable offset = 36
     BYVAL hRuleState AS DWORD _                        ' __in SPSTATEHANDLE hRuleState
   , BYREF pszResourceName AS WSTRINGZ _                ' __in const WCHAR *pszResourceName
   , BYREF pszResourceValue AS WSTRINGZ _               ' __in const WCHAR *pszResourceValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 40
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoGrammar Methods
   ' =====================================================================================
   METHOD GetGrammarId ( _                              ' VTable offset = 44
     BYREF pullGrammarId AS QUAD _                      ' __out ULONGLONG *pullGrammarId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoContext ( _                            ' VTable offset = 48
     BYREF ppRecoCtxt AS ISpRecoContext _               ' __out ISpRecoContext **ppRecoCtxt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromFile ( _                           ' VTable offset = 52
     BYREF pszFileName AS WSTRINGZ _                    ' __in const WCHAR *pszFileName
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromObject ( _                         ' VTable offset = 56
     BYREF rcid AS GUID _                               ' __in REFCLSID rcid
   , BYREF pszGrammarName AS WSTRINGZ _                 ' __in const WCHAR *pszGrammarName
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromResource ( _                       ' VTable offset = 60
     BYVAL hModule AS DWORD _                           ' __in HMODULE hModule
   , BYREF pszResourceName AS WSTRINGZ _                ' __in const WCHAR *pszResourceName
   , BYREF pszResourceType AS WSTRINGZ _                ' __in const WCHAR *pszResourceType
   , BYVAL wLanguage AS WORD _                          ' __in WORD wLanguage
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromMemory ( _                         ' VTable offset = 64
     BYREF pGrammar AS SPBINARYGRAMMAR _                ' __in const SPBINARYGRAMMAR *pGrammar
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromProprietaryGrammar ( _             ' VTable offset = 68
     BYREF rguidParam AS GUID _                         ' __in REFGUID rguidParam
   , BYREF pszStringParam AS WSTRINGZ _                 ' __in const WCHAR *pszStringParam
   , BYVAL pvDataPrarm AS DWORD _                       ' __in const void *pvDataPrarm
   , BYVAL cbDataSize AS DWORD _                        ' __in ULONG cbDataSize
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleState ( _                              ' VTable offset = 72
     BYREF pszName AS WSTRINGZ _                        ' __in const WCHAR *pszName
   , BYVAL pReserved AS DWORD _                         ' __in void *pReserved
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleIdState ( _                            ' VTable offset = 76
     BYVAL ulRuleId AS DWORD _                          ' __in ULONG ulRuleId
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadDictation ( _                             ' VTable offset = 80
     BYREF pszTopicName AS WSTRINGZ _                   ' __in const WCHAR *pszTopicName
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadDictation ( _                           ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictationState ( _                         ' VTable offset = 88
     BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordSequenceData ( _                       ' VTable offset = 92
     BYREF pText AS WSTRINGZ _                          ' __in const WCHAR *pText
   , BYVAL cchText AS DWORD _                           ' __in ULONG cchText
   , BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextSelection ( _                          ' VTable offset = 96
     BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPronounceable ( _                           ' VTable offset = 100
     BYREF pszWord AS WSTRINGZ _                        ' __in const WCHAR *pszWord
   , BYREF pWordPronounceable AS LONG _                 ' __out SPWORDPRONOUNCEABLE *pWordPronounceable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGrammarState ( _                           ' VTable offset = 104
     BYVAL eGrammarState AS LONG _                      ' __in SPGRAMMARSTATE eGrammarState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCmd ( _                                   ' VTable offset = 108
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , OPTIONAL BYREF ppszCoMemErrorText AS DWORD _       ' __out WCHAR **ppszCoMemErrorText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGrammarState ( _                           ' VTable offset = 112
     BYREF peGrammarState AS LONG _                     ' __out SPGRAMMARSTATE *peGrammarState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoGrammar_INTERFACE_DEFINED__ */

' enum SPMATCHINGMODE
%AllWords                     = 0
%Subsequence                  = 1
%OrderedSubset                = 3
%SubsequenceContentRequired   = 5
%OrderedSubsetContentRequired = 7

' enum PHONETICALPHABET
%PA_Ipa   = 0
%PA_Ups   = 1
%PA_Sapi  = 2

' ########################################################################################
' Interface name = ISpGrammarBuilder2
' IID = 8AB10026-20CC-4B20-8C22-A49C9BA78F60
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpGrammarBuilder2_INTERFACE_DEFINED)
    %ISpGrammarBuilder2_INTERFACE_DEFINED = 1

INTERFACE ISpGrammarBuilder2 $IID_ISpGrammarBuilder2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddTextSubset ( _                             ' VTable offset = 12
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYREF psz AS WSTRINGZ _                            ' __in LPCWSTR psz
   , BYVAL eMatchMode AS LONG _                         ' __in SPMATCHINGMODE eMatchMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPhoneticAlphabet ( _                       ' VTable offset = 16
     BYVAL phoneticALphabet AS LONG _                   ' __in PHONETICALPHABET phoneticALphabet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpGrammarBuilder2_INTERFACE_DEFINED__ */

%SPRP_NORMAL = 0

' ########################################################################################
' Interface name = ISpRecoGrammar2
' IID = 4B37BC9E-9ED6-44A3-93D3-18F022B79EC3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpRecoGrammar2_INTERFACE_DEFINED)
    %ISpRecoGrammar2_INTERFACE_DEFINED = 1

INTERFACE ISpRecoGrammar2 $IID_ISpRecoGrammar2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRules ( _                                  ' VTable offset = 12
     BYREF ppCoMemRules AS SPRULE _                     ' __out SPRULE **ppCoMemRules
   , BYREF puNumRules AS DWORD _                        ' __out UINT *puNumRules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromFile2 ( _                          ' VTable offset = 16
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCWSTR pszFileName
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   , BYREF pszSharingUri AS WSTRINGZ _                  ' __in LPCWSTR pszSharingUri
   , BYREF pszBaseUri AS WSTRINGZ _                     ' __in LPCWSTR pszBaseUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCmdFromMemory2 ( _                        ' VTable offset = 20
     BYREF pGrammar AS SPBINARYGRAMMAR _                ' __in const SPBINARYGRAMMAR *pGrammar
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   , BYREF pszSharingUri AS WSTRINGZ _                  ' __in LPCWSTR pszSharingUri
   , BYREF pszBaseUri AS WSTRINGZ _                     ' __in LPCWSTR pszBaseUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRulePriority ( _                           ' VTable offset = 24
     BYREF pszRuleName AS WSTRINGZ _                    ' __in LPCWSTR pszRuleName
   , BYVAL ulRuleId AS DWORD _                          ' __in ULONG ulRuleId
   , BYVAL nRulePriority AS DWORD _                     ' __in int nRulePriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleWeight ( _                             ' VTable offset = 28
     BYREF pszRuleName AS WSTRINGZ _                    ' __in LPCWSTR pszRuleName
   , BYVAL ulRuleId AS DWORD _                          ' __in ULONG ulRuleId
   , BYVAL flWeight AS SINGLE _                         ' __in float flWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDictationWeight ( _                        ' VTable offset = 32
     BYVAL flWeight AS SINGLE _                         ' __in float flWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGrammarLoader ( _                          ' VTable offset = 36
     BYVAL pLoader AS ISpeechResourceLoader _           ' __in ISpeechResourceLoader *pLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSMLSecurityManager ( _                     ' VTable offset = 40
     BYVAL pSMLSecurityManager AS IInternetSecurityManager _ ' __in IInternetSecurityManager *pSMLSecurityManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoGrammar2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpeechResourceLoader
' IID = B9AC5783-FCD0-4B21-B119-B4F8DA8FD2C3
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechResourceLoader_INTERFACE_DEFINED)
    %ISpeechResourceLoader_INTERFACE_DEFINED = 1

INTERFACE ISpeechResourceLoader $IID_ISpeechResourceLoader

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LoadResource <1> ( _                          ' VTable offset = 28
     BYVAL bstrResourceUri AS WSTRING _                 ' __in BSTR bstrResourceUri
   , BYVAL fAlwaysReload AS INTEGER _                   ' __in VARIANT_BOOL fAlwaysReload
   , BYREF pStream AS IStream _                         ' __out IUnknown **pStream
   , BYREF pbstrMIMEType AS WSTRING _                   ' __out BSTR *pbstrMIMEType
   , BYREF pfModified AS INTEGER _                      ' __out VARIANT_BOOL *pfModified
   , BYREF pbstrRedirectUrl AS WSTRING _                ' __out BSTR *pbstrRedirectUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLocalCopy <2> ( _                          ' VTable offset = 32
     BYVAL bstrResourceUri AS WSTRING _                 ' __in BSTR bstrResourceUri
   , BYREF pbstrLocalPath AS WSTRING _                  ' __out BSTR *pbstrLocalPath
   , BYREF pbstrMIMEType AS WSTRING _                   ' __out BSTR *pbstrMIMEType
   , BYREF pbstrRedirectUrl AS WSTRING _                ' __out BSTR *pbstrRedirectUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseLocalCopy <3> ( _                      ' VTable offset = 36
     BYVAL pbstrLocalPath AS WSTRING _                  ' __in BSTR pbstrLocalPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechResourceLoader_INTERFACE_DEFINED__ */

' // Size = 524 bytes
TYPE SPRECOCONTEXTSTATUS DWORD
   eInterference     AS LONG             ' SPINTERFERENCE enum
   szRequestTypeOfUI AS WSTRINGZ * 255   ' WCHAR [ 255 ]
   dwReserved1       AS DWORD            ' DWORD
   dwReserved2       AS DWORD            ' DWORD
END TYPE

' enum SPBOOKMARKOPTIONS
%SPBO_NONE       = 0
%SPBO_PAUSE      = 1   ' 1 << 0
%SPBO_AHEAD      = 2   ' 1 << 1
%SPBO_TIME_UNITS = 4   ' 1 << 2

' enum SPAUDIOOPTIONS
%SPAO_NONE         = 0
%SPAO_RETAIN_AUDIO = 1   ' 1 << 0


' ########################################################################################
' Interface name = ISpRecoContext
' IID = {F740A62F-7C15-489E-8234-940A33D9272D}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpEventSource
' ########################################################################################

#IF NOT %DEF(%ISpRecoContext_INTERFACE_DEFINED)
    %ISpRecoContext_INTERFACE_DEFINED = 1

INTERFACE ISpRecoContext $IID_ISpRecoContext

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySource Methods
   ' =====================================================================================
   METHOD SetNotifySink ( _                             ' VTable offset = 12
     BYVAL pNotifySink AS ISpNotifySink _               ' __in ISpNotifySink *pNotifySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWindowMessage ( _                    ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL Msg AS DWORD _                               ' __in UINT Msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackFunction ( _                 ' VTable offset = 20
     BYVAL pfnCallback AS DWORD _                       ' __in SPNOTIFYCALLBACK *pfnCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyCallbackInterface ( _                ' VTable offset = 24
     BYVAL pSpCallback AS DWORD _                       ' __in ISpNotifyCallback *pSpCallback
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyWin32Event ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNotifyEvent ( _                        ' VTable offset = 32
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyEventHandle ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

   ' =====================================================================================
   ' ISpEventSource Methods
   ' =====================================================================================
   METHOD SetInterest ( _                               ' VTable offset = 40
     BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   , BYVAL ullQueuedInterest AS QUAD _                  ' __in ULONGLONG ullQueuedInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvents ( _                                 ' VTable offset = 44
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF pEventArray AS SPEVENT _                     ' __out SPEVENT *pEventArray
   , BYREF pulFetched AS DWORD _                        ' __out ULONG *pulFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 48
     BYREF pInfo AS SPEVENTSOURCEINFO _                 ' __out SPEVENTSOURCEINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecoContext Methods
   ' =====================================================================================
   METHOD GetRecognizer ( _                             ' VTable offset = 52
     BYREF ppRecognizer AS ISpRecognizer _              ' __out ISpRecognizer **ppRecognizer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGrammar ( _                             ' VTable offset = 56
     BYVAL ullGrammarId AS QUAD _                       ' __in ULONGLONG ullGrammarId
   , BYREF ppGrammar AS ISpRecoGrammar _                ' __out ISpRecoGrammar **ppGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 60
     BYREF pStatus AS SPRECOCONTEXTSTATUS _             ' __out SPRECOCONTEXTSTATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxAlternates ( _                          ' VTable offset = 64
     BYREF pcAlternates AS DWORD _                      ' __in ULONG *pcAlternates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxAlternates ( _                          ' VTable offset = 68
     BYVAL cAlternates AS DWORD _                       ' __in ULONG cAlternates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAudioOptions ( _                           ' VTable offset = 72
     BYVAL Options AS LONG _                            ' __in SPAUDIOOPTIONS Options
   , BYREF pAudioFormatId AS GUID _                     ' __in const GUID *pAudioFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioOptions ( _                           ' VTable offset = 76
     BYVAL pOptions AS LONG _                           ' __in SPAUDIOOPTIONS *pOptions
   , BYREF pAudioFormatId AS GUID _                     ' __out GUID *pAudioFormatId
   , BYREF ppCoMemWFEX AS WAVEFORMATEX _                ' __out WAVEFORMATEX **ppCoMemWFEX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeserializeResult ( _                         ' VTable offset = 80
     BYREF pSerializedResult AS SPSERIALIZEDRESULT _    ' __in const SPSERIALIZEDRESULT *pSerializedResult
   , BYREF ppResult AS ISpRecoResult _                  ' __out ISpRecoResult **ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Bookmark ( _                                  ' VTable offset = 84
     BYVAL Options AS LONG _                            ' __in SPBOOKMARKOPTIONS Options
   , BYVAL ullStreamPosition AS QUAD _                  ' __in ULONGLONG ullStreamPosition
   , BYVAL lparamEvent AS LONG _                        ' __in LPARAM lparamEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdaptationData ( _                         ' VTable offset = 88
     BYREF pAdaptationData AS WSTRINGZ _                ' __in const WCHAR *pAdaptationData
   , BYVAL cch AS DWORD _                               ' __in const ULONG cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 92
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 96
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVoice ( _                                  ' VTable offset = 100
     BYVAL pVoice AS ISpVoice _                         ' __in ISpVoice *pVoice
   , BYVAL fAllowFormatChanges AS LONG _                ' __in BOOL fAllowFormatChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVoice ( _                                  ' VTable offset = 104
     BYREF ppVoice AS ISpVoice _                        ' __out ISpVoice **ppVoice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVoicePurgeEvent ( _                        ' VTable offset = 108
     BYVAL ullEventInterest AS QUAD _                   ' __in ULONGLONG ullEventInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVoicePurgeEvent ( _                        ' VTable offset = 112
     BYREF pullEventInterest AS QUAD _                  ' __out ULONGLONG *pullEventInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContextState ( _                           ' VTable offset = 116
     BYVAL eContextState AS LONG _                      ' __in SPCONTEXTSTATE eContextState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextState ( _                           ' VTable offset = 120
     BYVAL peContextState AS LONG _                     ' __in SPCONTEXTSTATE *peContextState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoContext_INTERFACE_DEFINED__ */

' enum SPGRAMMAROPTIONS
%SPGO_SAPI            = &H1
%SPGO_SRGS            = &H2
%SPGO_UPS             = &H4
%SPGO_SRGS_MS_SCRIPT  = &H8
%SPGO_SRGS_W3C_SCRIPT = &H100
%SPGO_SRGS_STG_SCRIPT = &H200
%SPGO_SRGS_SCRIPT     = (((%SPGO_SRGS OR %SPGO_SRGS_MS_SCRIPT) OR %SPGO_SRGS_W3C_SCRIPT) OR %SPGO_SRGS_STG_SCRIPT)
%SPGO_FILE            = &H10
%SPGO_HTTP            = &H20
%SPGO_RES             = &H40
%SPGO_OBJECT          = &H80
%SPGO_DEFAULT         = &H3fb
%SPGO_ALL             = &H3ff

' enum SPADAPTATIONSETTINGS
%SPADS_Default              = 0
%SPADS_CurrentRecognizer    = &H1
%SPADS_RecoProfile          = &H2
%SPADS_Immediate            = &H4
%SPADS_Reset                = &H8
%SPADS_HighVolumeDataSource = &H10

' enum SPADAPTATIONRELEVANCE
%SPAR_Unknown = 0
%SPAR_Low     = 1
%SPAR_Medium  = 2
%SPAR_High    = 3

' ########################################################################################
' Interface name = ISpRecoContext2
' IID = BEAD311C-52FF-437F-9464-6B21054CA73D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpRecoContext2_INTERFACE_DEFINED)
    %ISpRecoContext2_INTERFACE_DEFINED = 1

INTERFACE ISpRecoContext2 $IID_ISpRecoContext2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGrammarOptions ( _                         ' VTable offset = 12
     BYVAL eGrammarOptions AS DWORD _                   ' __in DWORD eGrammarOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGrammarOptions ( _                         ' VTable offset = 16
     BYREF peGrammarOptions AS DWORD _                  ' __out DWORD *peGrammarOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdaptationData2 ( _                        ' VTable offset = 20
     BYREF pAdaptationData AS WSTRINGZ _                ' __in LPCWSTR pAdaptationData
   , BYVAL cch AS DWORD _                               ' __in const ULONG cch
   , BYREF pTopicName AS WSTRINGZ _                     ' __in LPCWSTR pTopicName
   , BYVAL eAdaptationSettings AS DWORD _               ' __in DWORD eAdaptationSettings
   , BYVAL eRelevance AS LONG _                         ' __in SPADAPTATIONRELEVANCE eRelevance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoContext2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpProperties
' IID = {5B4FB971-B115-4DE1-AD97-E482E3BF6EE4}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpProperties_INTERFACE_DEFINED)
    %ISpProperties_INTERFACE_DEFINED = 1

INTERFACE ISpProperties $IID_ISpProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPropertyNum ( _                            ' VTable offset = 12
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYVAL lValue AS LONG _                             ' __in LONG lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyNum ( _                            ' VTable offset = 16
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF plValue AS LONG _                            ' __out LONG *plValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyString ( _                         ' VTable offset = 20
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF pValue AS WSTRINGZ _                         ' __in const WCHAR *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyString ( _                         ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF ppCoMemValue AS DWORD _                      ' __out WCHAR **ppCoMemValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpProperties_INTERFACE_DEFINED__ */


%SP_MAX_LANGIDS = 20

' // Size = 128 bytes
TYPE SPRECOGNIZERSTATUS   ' Must be 8 byte aligned
   AudioStatus              AS SPAUDIOSTATUS   ' SPAUDIOSTATUS
   ullRecognitionStreamPos  AS QUAD            ' ULONGLONG
   ulStreamNumber           AS DWORD           ' ULONG
   ulNumActive              AS DWORD           ' ULONG
   ClsidEngine              AS GUID            ' GUID
   cLangIDs                 AS DWORD           ' ULONG
   alignment__              AS DWORD           ' // To keep 8 byte alignment
   aLangID(19)              AS WORD            ' WORD [ 20 ]
   ullRecognitionStreamTime AS QUAD            ' ULONGLONG
END TYPE

' enum SPWAVEFORMATTYPE
%SPWF_INPUT    = 0
%SPWF_SRENGINE = %SPWF_INPUT + 1

' enum SPRECOSTATE
%SPRST_INACTIVE            = 0
%SPRST_ACTIVE              = %SPRST_INACTIVE            + 1
%SPRST_ACTIVE_ALWAYS       = %SPRST_ACTIVE              + 1
%SPRST_INACTIVE_WITH_PURGE = %SPRST_ACTIVE_ALWAYS       + 1
%SPRST_NUM_STATES          = %SPRST_INACTIVE_WITH_PURGE + 1


' ########################################################################################
' Interface name = ISpRecognizer
' IID = {C2B5F241-DAA0-4507-9E16-5A1EAA2B7A5C}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpProperties
' ########################################################################################

#IF NOT %DEF(%ISpRecognizer_INTERFACE_DEFINED)
    %ISpRecognizer_INTERFACE_DEFINED = 1

INTERFACE ISpRecognizer $IID_ISpRecognizer

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpProperties Methods
   ' =====================================================================================
   METHOD SetPropertyNum ( _                            ' VTable offset = 12
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYVAL lValue AS LONG _                             ' __in LONG lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyNum ( _                            ' VTable offset = 16
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF plValue AS LONG _                            ' __out LONG *plValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyString ( _                         ' VTable offset = 20
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF pValue AS WSTRINGZ _                         ' __in const WCHAR *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyString ( _                         ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF ppCoMemValue AS DWORD _                      ' __out WCHAR **ppCoMemValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpRecognizer Methods
   ' =====================================================================================
   METHOD SetRecognizer ( _                             ' VTable offset = 28
     BYVAL pRecognizer AS ISpObjectToken _              ' __in ISpObjectToken *pRecognizer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecognizer ( _                             ' VTable offset = 32
     BYREF ppRecognizer AS ISpObjectToken _             ' __out ISpObjectToken **ppRecognizer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInput ( _                                  ' VTable offset = 36
     BYVAL pUnkInput AS IUnknown _                      ' __in IUnknown *pUnkInput
   , BYVAL fAllowFormatChanges AS LONG _                ' __in BOOL fAllowFormatChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputObjectToken ( _                       ' VTable offset = 40
     BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStream ( _                            ' VTable offset = 44
     BYREF ppStream AS ISpStreamFormat _                ' __out ISpStreamFormat **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRecoContext ( _                         ' VTable offset = 48
     BYREF ppNewCtxt AS ISpRecoContext _                ' __out ISpRecoContext **ppNewCtxt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoProfile ( _                            ' VTable offset = 52
     BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecoProfile ( _                            ' VTable offset = 56
     BYVAL pToken AS ISpObjectToken _                   ' __in ISpObjectToken *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSharedInstance ( _                          ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecoState ( _                              ' VTable offset = 64
     BYREF pState AS LONG _                             ' __out SPRECOSTATE *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecoState ( _                              ' VTable offset = 68
     BYVAL NewState AS LONG _                           ' __in SPRECOSTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 72
     BYREF pStatus AS SPRECOGNIZERSTATUS _              ' __out SPRECOGNIZERSTATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 76
     BYVAL WaveFormatType AS LONG _                     ' __in SPSTREAMFORMATTYPE WaveFormatType
   , BYREF pFormatId AS GUID _                          ' __out GUID *pFormatId
   , BYREF ppCoMemWFEX AS WAVEFORMATEX _                ' __out WAVEFORMATEX **ppCoMemWFEX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUISupported ( _                             ' VTable offset = 80
     BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYREF pfSupported AS LONG _                        ' __out BOOL *pfSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayUI ( _                                 ' VTable offset = 84
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pszTitle AS WSTRINGZ _                       ' __in const WCHAR *pszTitle
   , BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in const WCHAR *pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EmulateRecognition ( _                        ' VTable offset = 88
     BYVAL pPhrase AS ISpPhrase _                       ' __in ISpPhrase *pPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecognizer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpSerializeState
' IID = 21B501A0-0EC7-46C9-92C3-A2BC784C54B9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpSerializeState_INTERFACE_DEFINED)
    %ISpSerializeState_INTERFACE_DEFINED = 1

INTERFACE ISpSerializeState $IID_ISpSerializeState

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSerializedState ( _                        ' VTable offset = 12
     BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pulSize AS DWORD _                           ' __out ULONG *pulSize
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSerializedState ( _                        ' VTable offset = 16
     BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYVAL ulSize AS DWORD _                            ' __in ULONG ulSize
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSerializeState_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpRecognizer2
' IID = 8FC6D974-C81E-4098-93C5-0147F61ED4D3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpRecognizer2_INTERFACE_DEFINED)
    %ISpRecognizer2_INTERFACE_DEFINED = 1

INTERFACE ISpRecognizer2 $IID_ISpRecognizer2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EmulateRecognitionEx ( _                      ' VTable offset = 12
     BYVAL pPhrase AS ISpPhrase _                       ' __in ISpPhrase *pPhrase
   , BYVAL dwCompareFlags AS DWORD _                    ' __in DWORD dwCompareFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrainingState ( _                          ' VTable offset = 16
     BYVAL fDoingTraining AS LONG _                     ' __in BOOL fDoingTraining
   , BYVAL fAdaptFromTrainingData AS LONG _             ' __in BOOL fAdaptFromTrainingData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetAcousticModelAdaptation ( _              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecognizer2_INTERFACE_DEFINED__ */

' enum SPCATEGORYTYPE
%SPCT_COMMAND	       = 0
%SPCT_DICTATION      = %SPCT_COMMAND     + 1
%SPCT_SLEEP	         = %SPCT_DICTATION   + 1
%SPCT_SUB_COMMAND	   = %SPCT_SLEEP       + 1
%SPCT_SUB_DICTATION	 = %SPCT_SUB_COMMAND + 1

' ########################################################################################
' Interface name = ISpRecoCategory
' IID = {DA0CD0F9-14A2-4F09-8C2A-85CC48979345}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpRecoCategory_INTERFACE_DEFINED)
    %ISpRecoCategory_INTERFACE_DEFINED = 1

INTERFACE ISpRecoCategory $IID_ISpRecoCategory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF peCategoryType AS LONG _                     ' __out SPCATEGORYTYPE *peCategoryType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecoCategory_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpRecognizer3
' IID = {DF1B943C-5838-4AA2-8706-D7CD5B333499}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpRecognizer3_INTERFACE_DEFINED)
    %ISpRecognizer3_INTERFACE_DEFINED = 1

INTERFACE ISpRecognizer3 $IID_ISpRecognizer3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 12
     BYVAL categoryType AS LONG _                       ' __in SPCATEGORYTYPE categoryType
   , BYREF ppCategory AS ISpRecoCategory _              ' __out ISpRecoCategory **ppCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveCategory ( _                         ' VTable offset = 16
     BYVAL pCategory AS ISpRecoCategory _               ' __in ISpRecoCategory *pCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveCategory ( _                         ' VTable offset = 20
     BYREF ppCategory AS ISpRecoCategory _              ' __out ISpRecoCategory **ppCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpRecognizer3_INTERFACE_DEFINED__ */

' // Size = 8 bytes
TYPE SPNORMALIZATIONLIST DWORD
   ulSize              AS DWORD          ' ULONG
   ppszzNormalizedList AS WSTRINGZ PTR   ' WCHAR **
END TYPE


' ########################################################################################
' Interface name = ISpEnginePronunciation
' IID = C360CE4B-76D1-4214-AD68-52657D5083DA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpEnginePronunciation_INTERFACE_DEFINED)
    %ISpEnginePronunciation_INTERFACE_DEFINED = 1

INTERFACE ISpEnginePronunciation $IID_ISpEnginePronunciation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Normalize ( _                                 ' VTable offset = 12
     BYREF pszWord AS WSTRINGZ _                        ' __in LPCWSTR pszWord
   , BYREF pszLeftContext AS WSTRINGZ _                 ' __in LPCWSTR pszLeftContext
   , BYREF pszRightContext AS WSTRINGZ _                ' __in LPCWSTR pszRightContext
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYREF pNormalizationList AS SPNORMALIZATIONLIST _  ' __out SPNORMALIZATIONLIST *pNormalizationList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPronunciations ( _                         ' VTable offset = 16
     BYREF pszWord AS WSTRINGZ _                        ' __in LPCWSTR pszWord
   , BYREF pszLeftContext AS WSTRINGZ _                 ' __in LPCWSTR pszLeftContext
   , BYREF pszRightContext AS WSTRINGZ _                ' __in LPCWSTR pszRightContext
   , BYVAL LangID AS WORD _                             ' __in WORD LangID
   , BYREF pEnginePronunciationList AS SPWORDPRONUNCIATIONLIST _ ' __in_out SPWORDPRONUNCIATIONLIST *pEnginePronunciationList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpEnginePronunciation_INTERFACE_DEFINED__ */

#IF NOT %DEF(%SpeechLib_LIBRARY_DEFINED)
    %SpeechLib_LIBRARY_DEFINED = 1

'typedef long SpeechLanguageId;

' enum DISPID_SpeechDataKey
%DISPID_SDKSetBinaryValue = 1
%DISPID_SDKGetBinaryValue = %DISPID_SDKSetBinaryValue + 1
%DISPID_SDKSetStringValue = %DISPID_SDKGetBinaryValue + 1
%DISPID_SDKGetStringValue = %DISPID_SDKSetStringValue + 1
%DISPID_SDKSetLongValue   = %DISPID_SDKGetStringValue + 1
%DISPID_SDKGetlongValue   = %DISPID_SDKSetLongValue   + 1
%DISPID_SDKOpenKey        = %DISPID_SDKGetlongValue   + 1
%DISPID_SDKCreateKey      = %DISPID_SDKOpenKey        + 1
%DISPID_SDKDeleteKey      = %DISPID_SDKCreateKey      + 1
%DISPID_SDKDeleteValue    = %DISPID_SDKDeleteKey      + 1
%DISPID_SDKEnumKeys       = %DISPID_SDKDeleteValue    + 1
%DISPID_SDKEnumValues     = %DISPID_SDKEnumKeys       + 1

' enum DISPID_SpeechObjectToken
%DISPID_SOTId                    = 1
%DISPID_SOTDataKey               = %DISPID_SOTId                    + 1
%DISPID_SOTCategory              = %DISPID_SOTDataKey               + 1
%DISPID_SOTGetDescription        = %DISPID_SOTCategory              + 1
%DISPID_SOTSetId                 = %DISPID_SOTGetDescription        + 1
%DISPID_SOTGetAttribute          = %DISPID_SOTSetId                 + 1
%DISPID_SOTCreateInstance        = %DISPID_SOTGetAttribute          + 1
%DISPID_SOTRemove                = %DISPID_SOTCreateInstance        + 1
%DISPID_SOTGetStorageFileName    = %DISPID_SOTRemove                + 1
%DISPID_SOTRemoveStorageFileName = %DISPID_SOTGetStorageFileName    + 1
%DISPID_SOTIsUISupported         = %DISPID_SOTRemoveStorageFileName + 1
%DISPID_SOTDisplayUI             = %DISPID_SOTIsUISupported         + 1
%DISPID_SOTMatchesAttributes     = %DISPID_SOTDisplayUI             + 1

' enum SpeechDataKeyLocation
%SDKLDefaultLocation = %SPDKL_DefaultLocation
%SDKLCurrentUser     = %SPDKL_CurrentUser
%SDKLLocalMachine    = %SPDKL_LocalMachine
%SDKLCurrentConfig   = %SPDKL_CurrentConfig

' enum SpeechTokenContext
%STCInprocServer  = %CLSCTX_INPROC_SERVER
%STCInprocHandler = %CLSCTX_INPROC_HANDLER
%STCLocalServer   = %CLSCTX_LOCAL_SERVER
%STCRemoteServer  = %CLSCTX_REMOTE_SERVER
%STCAll           = %CLSCTX_INPROC_SERVER OR %CLSCTX_INPROC_HANDLER OR %CLSCTX_LOCAL_SERVER OR %CLSCTX_REMOTE_SERVER

' enum SpeechTokenShellFolder
%STSF_AppData       = &H1a
%STSF_LocalAppData  = &H1c
%STSF_CommonAppData = &H23
%STSF_FlagCreate    = &H8000

' enum DISPID_SpeechObjectTokens
%DISPID_SOTsCount    = 1
%DISPID_SOTsItem     = %DISPID_VALUE
%DISPID_SOTs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechObjectTokenCategory
%DISPID_SOTCId              = 1
%DISPID_SOTCDefault         = %DISPID_SOTCId         + 1
%DISPID_SOTCSetId           = %DISPID_SOTCDefault    + 1
%DISPID_SOTCGetDataKey      = %DISPID_SOTCSetId      + 1
%DISPID_SOTCEnumerateTokens = %DISPID_SOTCGetDataKey + 1

' enum SpeechAudioFormatType
%SAFTDefault                 = -1
%SAFTNoAssignedFormat        = 0
%SAFTText                    = %SAFTNoAssignedFormat        + 1
%SAFTNonStandardFormat       = %SAFTText                    + 1
%SAFTExtendedAudioFormat     = %SAFTNonStandardFormat       + 1
%SAFT8kHz8BitMono            = %SAFTExtendedAudioFormat     + 1
%SAFT8kHz8BitStereo          = %SAFT8kHz8BitMono            + 1
%SAFT8kHz16BitMono           = %SAFT8kHz8BitStereo          + 1
%SAFT8kHz16BitStereo         = %SAFT8kHz16BitMono           + 1
%SAFT11kHz8BitMono           = %SAFT8kHz16BitStereo         + 1
%SAFT11kHz8BitStereo         = %SAFT11kHz8BitMono           + 1
%SAFT11kHz16BitMono          = %SAFT11kHz8BitStereo         + 1
%SAFT11kHz16BitStereo        = %SAFT11kHz16BitMono          + 1
%SAFT12kHz8BitMono           = %SAFT11kHz16BitStereo        + 1
%SAFT12kHz8BitStereo         = %SAFT12kHz8BitMono           + 1
%SAFT12kHz16BitMono          = %SAFT12kHz8BitStereo         + 1
%SAFT12kHz16BitStereo        = %SAFT12kHz16BitMono          + 1
%SAFT16kHz8BitMono           = %SAFT12kHz16BitStereo        + 1
%SAFT16kHz8BitStereo         = %SAFT16kHz8BitMono           + 1
%SAFT16kHz16BitMono          = %SAFT16kHz8BitStereo         + 1
%SAFT16kHz16BitStereo        = %SAFT16kHz16BitMono          + 1
%SAFT22kHz8BitMono           = %SAFT16kHz16BitStereo        + 1
%SAFT22kHz8BitStereo         = %SAFT22kHz8BitMono           + 1
%SAFT22kHz16BitMono          = %SAFT22kHz8BitStereo         + 1
%SAFT22kHz16BitStereo        = %SAFT22kHz16BitMono          + 1
%SAFT24kHz8BitMono           = %SAFT22kHz16BitStereo        + 1
%SAFT24kHz8BitStereo         = %SAFT24kHz8BitMono           + 1
%SAFT24kHz16BitMono          = %SAFT24kHz8BitStereo         + 1
%SAFT24kHz16BitStereo        = %SAFT24kHz16BitMono          + 1
%SAFT32kHz8BitMono           = %SAFT24kHz16BitStereo        + 1
%SAFT32kHz8BitStereo         = %SAFT32kHz8BitMono           + 1
%SAFT32kHz16BitMono          = %SAFT32kHz8BitStereo         + 1
%SAFT32kHz16BitStereo        = %SAFT32kHz16BitMono          + 1
%SAFT44kHz8BitMono           = %SAFT32kHz16BitStereo        + 1
%SAFT44kHz8BitStereo         = %SAFT44kHz8BitMono           + 1
%SAFT44kHz16BitMono          = %SAFT44kHz8BitStereo         + 1
%SAFT44kHz16BitStereo        = %SAFT44kHz16BitMono          + 1
%SAFT48kHz8BitMono           = %SAFT44kHz16BitStereo        + 1
%SAFT48kHz8BitStereo         = %SAFT48kHz8BitMono           + 1
%SAFT48kHz16BitMono          = %SAFT48kHz8BitStereo         + 1
%SAFT48kHz16BitStereo        = %SAFT48kHz16BitMono          + 1
%SAFTTrueSpeech_8kHz1BitMono = %SAFT48kHz16BitStereo        + 1
%SAFTCCITT_ALaw_8kHzMono     = %SAFTTrueSpeech_8kHz1BitMono + 1
%SAFTCCITT_ALaw_8kHzStereo   = %SAFTCCITT_ALaw_8kHzMono     + 1
%SAFTCCITT_ALaw_11kHzMono    = %SAFTCCITT_ALaw_8kHzStereo   + 1
%SAFTCCITT_ALaw_11kHzStereo  = %SAFTCCITT_ALaw_11kHzMono    + 1
%SAFTCCITT_ALaw_22kHzMono    = %SAFTCCITT_ALaw_11kHzStereo  + 1
%SAFTCCITT_ALaw_22kHzStereo  = %SAFTCCITT_ALaw_22kHzMono    + 1
%SAFTCCITT_ALaw_44kHzMono    = %SAFTCCITT_ALaw_22kHzStereo  + 1
%SAFTCCITT_ALaw_44kHzStereo  = %SAFTCCITT_ALaw_44kHzMono    + 1
%SAFTCCITT_uLaw_8kHzMono     = %SAFTCCITT_ALaw_44kHzStereo  + 1
%SAFTCCITT_uLaw_8kHzStereo   = %SAFTCCITT_uLaw_8kHzMono     + 1
%SAFTCCITT_uLaw_11kHzMono    = %SAFTCCITT_uLaw_8kHzStereo   + 1
%SAFTCCITT_uLaw_11kHzStereo  = %SAFTCCITT_uLaw_11kHzMono    + 1
%SAFTCCITT_uLaw_22kHzMono    = %SAFTCCITT_uLaw_11kHzStereo  + 1
%SAFTCCITT_uLaw_22kHzStereo  = %SAFTCCITT_uLaw_22kHzMono    + 1
%SAFTCCITT_uLaw_44kHzMono    = %SAFTCCITT_uLaw_22kHzStereo  + 1
%SAFTCCITT_uLaw_44kHzStereo  = %SAFTCCITT_uLaw_44kHzMono    + 1
%SAFTADPCM_8kHzMono          = %SAFTCCITT_uLaw_44kHzStereo  + 1
%SAFTADPCM_8kHzStereo        = %SAFTADPCM_8kHzMono          + 1
%SAFTADPCM_11kHzMono         = %SAFTADPCM_8kHzStereo        + 1
%SAFTADPCM_11kHzStereo       = %SAFTADPCM_11kHzMono         + 1
%SAFTADPCM_22kHzMono         = %SAFTADPCM_11kHzStereo       + 1
%SAFTADPCM_22kHzStereo       = %SAFTADPCM_22kHzMono         + 1
%SAFTADPCM_44kHzMono         = %SAFTADPCM_22kHzStereo       + 1
%SAFTADPCM_44kHzStereo       = %SAFTADPCM_44kHzMono         + 1
%SAFTGSM610_8kHzMono         = %SAFTADPCM_44kHzStereo       + 1
%SAFTGSM610_11kHzMono        = %SAFTGSM610_8kHzMono         + 1
%SAFTGSM610_22kHzMono        = %SAFTGSM610_11kHzMono        + 1
%SAFTGSM610_44kHzMono        = %SAFTGSM610_22kHzMono        + 1

' enum DISPID_SpeechAudioFormat
%DISPID_SAFType            = 1
%DISPID_SAFGuid            = %DISPID_SAFType            + 1
%DISPID_SAFGetWaveFormatEx = %DISPID_SAFGuid            + 1
%DISPID_SAFSetWaveFormatEx = %DISPID_SAFGetWaveFormatEx + 1

' enum DISPID_SpeechBaseStream
%DISPID_SBSFormat = 1
%DISPID_SBSRead   = %DISPID_SBSFormat + 1
%DISPID_SBSWrite  = %DISPID_SBSRead   + 1
%DISPID_SBSSeek   = %DISPID_SBSWrite  + 1

' enum SpeechStreamSeekPositionType
%SSSPTRelativeToStart           = %STREAM_SEEK_SET
%SSSPTRelativeToCurrentPosition = %STREAM_SEEK_CUR
%SSSPTRelativeToEnd             = %STREAM_SEEK_END

' enum DISPID_SpeechAudio
%DISPID_SAStatus           = 200
%DISPID_SABufferInfo       = %DISPID_SAStatus           + 1
%DISPID_SADefaultFormat    = %DISPID_SABufferInfo       + 1
%DISPID_SAVolume           = %DISPID_SADefaultFormat    + 1
%DISPID_SABufferNotifySize = %DISPID_SAVolume           + 1
%DISPID_SAEventHandle      = %DISPID_SABufferNotifySize + 1
%DISPID_SASetState         = %DISPID_SAEventHandle      + 1

' enum SpeechAudioState
%SASClosed = %SPAS_CLOSED
%SASStop   = %SPAS_STOP
%SASPause  = %SPAS_PAUSE
%SASRun    = %SPAS_RUN

' enum DISPID_SpeechMMSysAudio
%DISPID_SMSADeviceId = 300
%DISPID_SMSALineId   = %DISPID_SMSADeviceId + 1
%DISPID_SMSAMMHandle = %DISPID_SMSALineId   + 1

' enum DISPID_SpeechFileStream
%DISPID_SFSOpen  = 100
%DISPID_SFSClose = %DISPID_SFSOpen + 1

' enum SpeechStreamFileMode
%SSFMOpenForRead    = %SPFM_OPEN_READONLY
%SSFMOpenReadWrite  = %SPFM_OPEN_READWRITE
%SSFMCreate         = %SPFM_CREATE
%SSFMCreateForWrite = %SPFM_CREATE_ALWAYS

' enum DISPID_SpeechCustomStream
%DISPID_SCSBaseStream = 100

' enum DISPID_SpeechMemoryStream
%DISPID_SMSSetData = 100
%DISPID_SMSGetData = %DISPID_SMSSetData + 1

' enum DISPID_SpeechAudioStatus
%DISPID_SASFreeBufferSpace       = 1
%DISPID_SASNonBlockingIO         = %DISPID_SASFreeBufferSpace     + 1
%DISPID_SASState                 = %DISPID_SASNonBlockingIO       + 1
%DISPID_SASCurrentSeekPosition   = %DISPID_SASState               + 1
%DISPID_SASCurrentDevicePosition = %DISPID_SASCurrentSeekPosition + 1

' enum DISPID_SpeechAudioBufferInfo
%DISPID_SABIMinNotification = 1
%DISPID_SABIBufferSize      = %DISPID_SABIMinNotification + 1
%DISPID_SABIEventBias       = %DISPID_SABIBufferSize      + 1

' enum DISPID_SpeechWaveFormatEx
%DISPID_SWFEFormatTag      = 1
%DISPID_SWFEChannels       = %DISPID_SWFEFormatTag      + 1
%DISPID_SWFESamplesPerSec  = %DISPID_SWFEChannels       + 1
%DISPID_SWFEAvgBytesPerSec = %DISPID_SWFESamplesPerSec  + 1
%DISPID_SWFEBlockAlign     = %DISPID_SWFEAvgBytesPerSec + 1
%DISPID_SWFEBitsPerSample  = %DISPID_SWFEBlockAlign     + 1
%DISPID_SWFEExtraData      = %DISPID_SWFEBitsPerSample  + 1

' enum DISPID_SpeechVoice
%DISPID_SVStatus                                = 1
%DISPID_SVVoice                                 = %DISPID_SVStatus                                + 1
%DISPID_SVAudioOutput                           = %DISPID_SVVoice                                 + 1
%DISPID_SVAudioOutputStream                     = %DISPID_SVAudioOutput                           + 1
%DISPID_SVRate                                  = %DISPID_SVAudioOutputStream                     + 1
%DISPID_SVVolume                                = %DISPID_SVRate                                  + 1
%DISPID_SVAllowAudioOuputFormatChangesOnNextSet = %DISPID_SVVolume                                + 1
%DISPID_SVEventInterests                        = %DISPID_SVAllowAudioOuputFormatChangesOnNextSet + 1
%DISPID_SVPriority                              = %DISPID_SVEventInterests                        + 1
%DISPID_SVAlertBoundary                         = %DISPID_SVPriority                              + 1
%DISPID_SVSyncronousSpeakTimeout                = %DISPID_SVAlertBoundary                         + 1
%DISPID_SVSpeak                                 = %DISPID_SVSyncronousSpeakTimeout                + 1
%DISPID_SVSpeakStream                           = %DISPID_SVSpeak                                 + 1
%DISPID_SVPause                                 = %DISPID_SVSpeakStream                           + 1
%DISPID_SVResume                                = %DISPID_SVPause                                 + 1
%DISPID_SVSkip                                  = %DISPID_SVResume                                + 1
%DISPID_SVGetVoices                             = %DISPID_SVSkip                                  + 1
%DISPID_SVGetAudioOutputs                       = %DISPID_SVGetVoices                             + 1
%DISPID_SVWaitUntilDone                         = %DISPID_SVGetAudioOutputs                       + 1
%DISPID_SVSpeakCompleteEvent                    = %DISPID_SVWaitUntilDone                         + 1
%DISPID_SVIsUISupported                         = %DISPID_SVSpeakCompleteEvent                    + 1
%DISPID_SVDisplayUI                             = %DISPID_SVIsUISupported                         + 1

' enum SpeechVoicePriority
%SVPNormal = %SPVPRI_NORMAL
%SVPAlert  = %SPVPRI_ALERT
%SVPOver   = %SPVPRI_OVER

' enum SpeechVoiceSpeakFlags
%SVSFDefault          = %SPF_DEFAULT
%SVSFlagsAsync        = %SPF_ASYNC
%SVSFPurgeBeforeSpeak = %SPF_PURGEBEFORESPEAK
%SVSFIsFilename       = %SPF_IS_FILENAME
%SVSFIsXML            = %SPF_IS_XML
%SVSFIsNotXML         = %SPF_IS_NOT_XML
%SVSFPersistXML       = %SPF_PERSIST_XML
%SVSFNLPSpeakPunc     = %SPF_NLP_SPEAK_PUNC
%SVSFNLPMask          = %SPF_NLP_MASK
%SVSFVoiceMask        = %SPF_VOICE_MASK
%SVSFUnusedFlags      = %SPF_UNUSED_FLAGS

' enum SpeechVoiceEvents
%SVEStartInputStream = &H2      ' 1L << 1
%SVEEndInputStream   = &H4      ' 1L << 2
%SVEVoiceChange      = &H8      ' 1L << 3
%SVEBookmark         = &H10     ' 1L << 4
%SVEWordBoundary     = &H20     ' 1L << 5
%SVEPhoneme          = &H40     ' 1L << 6
%SVESentenceBoundary = &H80     ' 1L << 7
%SVEViseme           = &H100    ' 1L << 8
%SVEAudioLevel       = &H200    ' 1L << 9
%SVEPrivate          = &H8000   ' 1L << 15
%SVEAllEvents        = &H83FE

' enum DISPID_SpeechVoiceStatus
%DISPID_SVSCurrentStreamNumber    = 1
%DISPID_SVSLastStreamNumberQueued = %DISPID_SVSCurrentStreamNumber    + 1
%DISPID_SVSLastResult             = %DISPID_SVSLastStreamNumberQueued + 1
%DISPID_SVSRunningState           = %DISPID_SVSLastResult             + 1
%DISPID_SVSInputWordPosition      = %DISPID_SVSRunningState           + 1
%DISPID_SVSInputWordLength        = %DISPID_SVSInputWordPosition      + 1
%DISPID_SVSInputSentencePosition  = %DISPID_SVSInputWordLength        + 1
%DISPID_SVSInputSentenceLength    = %DISPID_SVSInputSentencePosition  + 1
%DISPID_SVSLastBookmark           = %DISPID_SVSInputSentenceLength    + 1
%DISPID_SVSLastBookmarkId         = %DISPID_SVSLastBookmark           + 1
%DISPID_SVSPhonemeId              = %DISPID_SVSLastBookmarkId         + 1
%DISPID_SVSVisemeId               = %DISPID_SVSPhonemeId              + 1

' enum SpeechRunState
%SRSEDone       = %SPRS_DONE
%SRSEIsSpeaking = %SPRS_IS_SPEAKING

' enum SpeechVisemeType
%SVP_0  = 0
%SVP_1  = %SVP_0  + 1
%SVP_2  = %SVP_1  + 1
%SVP_3  = %SVP_2  + 1
%SVP_4  = %SVP_3  + 1
%SVP_5  = %SVP_4  + 1
%SVP_6  = %SVP_5  + 1
%SVP_7  = %SVP_6  + 1
%SVP_8  = %SVP_7  + 1
%SVP_9  = %SVP_8  + 1
%SVP_10 = %SVP_9  + 1
%SVP_11 = %SVP_10 + 1
%SVP_12 = %SVP_11 + 1
%SVP_13 = %SVP_12 + 1
%SVP_14 = %SVP_13 + 1
%SVP_15 = %SVP_14 + 1
%SVP_16 = %SVP_15 + 1
%SVP_17 = %SVP_16 + 1
%SVP_18 = %SVP_17 + 1
%SVP_19 = %SVP_18 + 1
%SVP_20 = %SVP_19 + 1
%SVP_21 = %SVP_20 + 1

' enum SpeechVisemeFeature
%SVF_None     = 0
%SVF_Stressed = %SPVFEATURE_STRESSED
%SVF_Emphasis = %SPVFEATURE_EMPHASIS

' enum DISPID_SpeechVoiceEvent
%DISPID_SVEStreamStart      = 1
%DISPID_SVEStreamEnd        = %DISPID_SVEStreamStart      + 1
%DISPID_SVEVoiceChange      = %DISPID_SVEStreamEnd        + 1
%DISPID_SVEBookmark         = %DISPID_SVEVoiceChange      + 1
%DISPID_SVEWord             = %DISPID_SVEBookmark         + 1
%DISPID_SVEPhoneme          = %DISPID_SVEWord             + 1
%DISPID_SVESentenceBoundary = %DISPID_SVEPhoneme          + 1
%DISPID_SVEViseme           = %DISPID_SVESentenceBoundary + 1
%DISPID_SVEAudioLevel       = %DISPID_SVEViseme           + 1
%DISPID_SVEEnginePrivate    = %DISPID_SVEAudioLevel       + 1

' enum DISPID_SpeechRecognizer
%DISPID_SRRecognizer                            = 1
%DISPID_SRAllowAudioInputFormatChangesOnNextSet = %DISPID_SRRecognizer                            + 1
%DISPID_SRAudioInput                            = %DISPID_SRAllowAudioInputFormatChangesOnNextSet + 1
%DISPID_SRAudioInputStream                      = %DISPID_SRAudioInput                            + 1
%DISPID_SRIsShared                              = %DISPID_SRAudioInputStream                      + 1
%DISPID_SRState                                 = %DISPID_SRIsShared                              + 1
%DISPID_SRStatus                                = %DISPID_SRState                                 + 1
%DISPID_SRProfile                               = %DISPID_SRStatus                                + 1
%DISPID_SREmulateRecognition                    = %DISPID_SRProfile                               + 1
%DISPID_SRCreateRecoContext                     = %DISPID_SREmulateRecognition                    + 1
%DISPID_SRGetFormat                             = %DISPID_SRCreateRecoContext                     + 1
%DISPID_SRSetPropertyNumber                     = %DISPID_SRGetFormat                             + 1
%DISPID_SRGetPropertyNumber                     = %DISPID_SRSetPropertyNumber                     + 1
%DISPID_SRSetPropertyString                     = %DISPID_SRGetPropertyNumber                     + 1
%DISPID_SRGetPropertyString                     = %DISPID_SRSetPropertyString                     + 1
%DISPID_SRIsUISupported                         = %DISPID_SRGetPropertyString                     + 1
%DISPID_SRDisplayUI                             = %DISPID_SRIsUISupported                         + 1
%DISPID_SRGetRecognizers                        = %DISPID_SRDisplayUI                             + 1
%DISPID_SVGetAudioInputs                        = %DISPID_SRGetRecognizers                        + 1
%DISPID_SVGetProfiles                           = %DISPID_SVGetAudioInputs                        + 1

' enum SpeechRecognizerState
%SRSInactive          = %SPRST_INACTIVE
%SRSActive            = %SPRST_ACTIVE
%SRSActiveAlways      = %SPRST_ACTIVE_ALWAYS
%SRSInactiveWithPurge = %SPRST_INACTIVE_WITH_PURGE

' enum SpeechDisplayAttributes
%SDA_No_Trailing_Space      = 0
%SDA_One_Trailing_Space     = %SPAF_ONE_TRAILING_SPACE
%SDA_Two_Trailing_Spaces    = %SPAF_TWO_TRAILING_SPACES
%SDA_Consume_Leading_Spaces = %SPAF_CONSUME_LEADING_SPACES

' enum SpeechFormatType
%SFTInput    = %SPWF_INPUT
%SFTSREngine = %SPWF_SRENGINE

' enum SpeechEmulationCompareFlags
%SECFIgnoreCase     = &H1
%SECFIgnoreKanaType = &H10000
%SECFIgnoreWidth    = &H20000
%SECFNoSpecialChars = &H20000000
%SECFEmulateResult  = &H40000000
%SECFDefault        = ((%SECFIgnoreCase OR %SECFIgnoreKanaType) OR %SECFIgnoreWidth)

' enum DISPID_SpeechRecognizerStatus
%DISPID_SRSAudioStatus           = 1
%DISPID_SRSCurrentStreamPosition = %DISPID_SRSAudioStatus           + 1
%DISPID_SRSCurrentStreamNumber   = %DISPID_SRSCurrentStreamPosition + 1
%DISPID_SRSNumberOfActiveRules   = %DISPID_SRSCurrentStreamNumber   + 1
%DISPID_SRSClsidEngine           = %DISPID_SRSNumberOfActiveRules   + 1
%DISPID_SRSSupportedLanguages    = %DISPID_SRSClsidEngine           + 1

' enum DISPID_SpeechRecoContext
%DISPID_SRCRecognizer                       = 1
%DISPID_SRCAudioInInterferenceStatus        = %DISPID_SRCRecognizer                       + 1
%DISPID_SRCRequestedUIType                  = %DISPID_SRCAudioInInterferenceStatus        + 1
%DISPID_SRCVoice                            = %DISPID_SRCRequestedUIType                  + 1
%DISPID_SRAllowVoiceFormatMatchingOnNextSet = %DISPID_SRCVoice                            + 1
%DISPID_SRCVoicePurgeEvent                  = %DISPID_SRAllowVoiceFormatMatchingOnNextSet + 1
%DISPID_SRCEventInterests                   = %DISPID_SRCVoicePurgeEvent                  + 1
%DISPID_SRCCmdMaxAlternates                 = %DISPID_SRCEventInterests                   + 1
%DISPID_SRCState                            = %DISPID_SRCCmdMaxAlternates                 + 1
%DISPID_SRCRetainedAudio                    = %DISPID_SRCState                            + 1
%DISPID_SRCRetainedAudioFormat              = %DISPID_SRCRetainedAudio                    + 1
%DISPID_SRCPause                            = %DISPID_SRCRetainedAudioFormat              + 1
%DISPID_SRCResume                           = %DISPID_SRCPause                            + 1
%DISPID_SRCCreateGrammar                    = %DISPID_SRCResume                           + 1
%DISPID_SRCCreateResultFromMemory           = %DISPID_SRCCreateGrammar                    + 1
%DISPID_SRCBookmark                         = %DISPID_SRCCreateResultFromMemory           + 1
%DISPID_SRCSetAdaptationData                = %DISPID_SRCBookmark                         + 1

' enum SpeechRetainedAudioOptions
%SRAONone        = %SPAO_NONE
%SRAORetainAudio = %SPAO_RETAIN_AUDIO

' enum SpeechBookmarkOptions
%SBONone  = %SPBO_NONE
%SBOPause = %SPBO_PAUSE

' enum SpeechInterference
%SINone      = %SPINTERFERENCE_NONE
%SINoise     = %SPINTERFERENCE_NOISE
%SINoSignal  = %SPINTERFERENCE_NOSIGNAL
%SITooLoud   = %SPINTERFERENCE_TOOLOUD
%SITooQuiet  = %SPINTERFERENCE_TOOQUIET
%SITooFast   = %SPINTERFERENCE_TOOFAST
%SITooSlow   = %SPINTERFERENCE_TOOSLOW

' enum SpeechRecoEvents
%SREStreamEnd            = &H1       ' 1L << 0
%SRESoundStart           = &H2       ' 1L << 1
%SRESoundEnd             = &H4       ' 1L << 2
%SREPhraseStart          = &H8       ' 1L << 3
%SRERecognition          = &H10      ' 1L << 4
%SREHypothesis           = &H20      ' 1L << 5
%SREBookmark             = &H40      ' 1L << 6
%SREPropertyNumChange    = &H80      ' 1L << 7
%SREPropertyStringChange = &H100     ' 1L << 8
%SREFalseRecognition     = &H200     ' 1L << 9
%SREInterference         = &H400     ' 1L << 10
%SRERequestUI            = &H800     ' 1L << 11
%SREStateChange          = &H1000    ' 1L << 12
%SREAdaptation           = &H2000    ' 1L << 13
%SREStreamStart          = &H4000    ' 1L << 14
%SRERecoOtherContext     = &H8000    ' 1L << 15
%SREAudioLevel           = &H10000   ' 1L << 16
%SREPrivate              = &H40000   ' 1L << 18
%SREAllEvents            = &H5FFFF

' enum SpeechRecoContextState
%SRCS_Disabled = %SPCS_DISABLED
%SRCS_Enabled  = %SPCS_ENABLED

' enum DISPIDSPRG
%DISPID_SRGId                            = 1
%DISPID_SRGRecoContext                   = %DISPID_SRGId                            + 1
%DISPID_SRGState                         = %DISPID_SRGRecoContext                   + 1
%DISPID_SRGRules                         = %DISPID_SRGState                         + 1
%DISPID_SRGReset                         = %DISPID_SRGRules                         + 1
%DISPID_SRGCommit                        = %DISPID_SRGReset                         + 1
%DISPID_SRGCmdLoadFromFile               = %DISPID_SRGCommit                        + 1
%DISPID_SRGCmdLoadFromObject             = %DISPID_SRGCmdLoadFromFile               + 1
%DISPID_SRGCmdLoadFromResource           = %DISPID_SRGCmdLoadFromObject             + 1
%DISPID_SRGCmdLoadFromMemory             = %DISPID_SRGCmdLoadFromResource           + 1
%DISPID_SRGCmdLoadFromProprietaryGrammar = %DISPID_SRGCmdLoadFromMemory             + 1
%DISPID_SRGCmdSetRuleState               = %DISPID_SRGCmdLoadFromProprietaryGrammar + 1
%DISPID_SRGCmdSetRuleIdState             = %DISPID_SRGCmdSetRuleState               + 1
%DISPID_SRGDictationLoad                 = %DISPID_SRGCmdSetRuleIdState             + 1
%DISPID_SRGDictationUnload               = %DISPID_SRGDictationLoad                 + 1
%DISPID_SRGDictationSetState             = %DISPID_SRGDictationUnload               + 1
%DISPID_SRGSetWordSequenceData           = %DISPID_SRGDictationSetState             + 1
%DISPID_SRGSetTextSelection              = %DISPID_SRGSetWordSequenceData           + 1
%DISPID_SRGIsPronounceable               = %DISPID_SRGSetTextSelection              + 1

' enum SpeechLoadOption
%SLOStatic  = %SPLO_STATIC
%SLODynamic = %SPLO_DYNAMIC

' enum SpeechWordPronounceable
%SWPUnknownWordUnpronounceable = %SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE
%SWPUnknownWordPronounceable   = %SPWP_UNKNOWN_WORD_PRONOUNCEABLE
%SWPKnownWordPronounceable     = %SPWP_KNOWN_WORD_PRONOUNCEABLE

' enum SpeechGrammarState
%SGSEnabled   = %SPGS_ENABLED
%SGSDisabled  = %SPGS_DISABLED
%SGSExclusive = %SPGS_EXCLUSIVE

' enum SpeechRuleState
%SGDSInactive            = %SPRS_INACTIVE
%SGDSActive              = %SPRS_ACTIVE
%SGDSActiveWithAutoPause = %SPRS_ACTIVE_WITH_AUTO_PAUSE
%SGDSActiveUserDelimited = %SPRS_ACTIVE_USER_DELIMITED

' enum SpeechRuleAttributes
%SRATopLevel        = %SPRAF_TopLevel
%SRADefaultToActive = %SPRAF_Active
%SRAExport          = %SPRAF_Export
%SRAImport          = %SPRAF_Import
%SRAInterpreter     = %SPRAF_Interpreter
%SRADynamic         = %SPRAF_Dynamic
%SRARoot            = %SPRAF_Root

' enum SpeechGrammarWordType
%SGDisplay               = %SPWT_DISPLAY
%SGLexical               = %SPWT_LEXICAL
%SGPronounciation        = %SPWT_PRONUNCIATION
%SGLexicalNoSpecialChars = %SPWT_LEXICAL_NO_SPECIAL_CHARS

' enum DISPID_SpeechRecoContextEvents
%DISPID_SRCEStartStream                = 1
%DISPID_SRCEEndStream                  = %DISPID_SRCEStartStream                + 1
%DISPID_SRCEBookmark                   = %DISPID_SRCEEndStream                  + 1
%DISPID_SRCESoundStart                 = %DISPID_SRCEBookmark                   + 1
%DISPID_SRCESoundEnd                   = %DISPID_SRCESoundStart                 + 1
%DISPID_SRCEPhraseStart                = %DISPID_SRCESoundEnd                   + 1
%DISPID_SRCERecognition                = %DISPID_SRCEPhraseStart                + 1
%DISPID_SRCEHypothesis                 = %DISPID_SRCERecognition                + 1
%DISPID_SRCEPropertyNumberChange       = %DISPID_SRCEHypothesis                 + 1
%DISPID_SRCEPropertyStringChange       = %DISPID_SRCEPropertyNumberChange       + 1
%DISPID_SRCEFalseRecognition           = %DISPID_SRCEPropertyStringChange       + 1
%DISPID_SRCEInterference               = %DISPID_SRCEFalseRecognition           + 1
%DISPID_SRCERequestUI                  = %DISPID_SRCEInterference               + 1
%DISPID_SRCERecognizerStateChange      = %DISPID_SRCERequestUI                  + 1
%DISPID_SRCEAdaptation                 = %DISPID_SRCERecognizerStateChange      + 1
%DISPID_SRCERecognitionForOtherContext = %DISPID_SRCEAdaptation                 + 1
%DISPID_SRCEAudioLevel                 = %DISPID_SRCERecognitionForOtherContext + 1
%DISPID_SRCEEnginePrivate              = %DISPID_SRCEAudioLevel                 + 1

' enum SpeechRecognitionType
%SRTStandard        = 0
%SRTAutopause       = %SPREF_AutoPause
%SRTEmulated        = %SPREF_Emulated
%SRTSMLTimeout      = %SPREF_SMLTimeout
%SRTExtendableParse = %SPREF_ExtendableParse
%SRTReSent          = %SPREF_ReSent

' enum DISPID_SpeechGrammarRule
%DISPID_SGRAttributes   = 1
%DISPID_SGRInitialState = %DISPID_SGRAttributes   + 1
%DISPID_SGRName         = %DISPID_SGRInitialState + 1
%DISPID_SGRId           = %DISPID_SGRName         + 1
%DISPID_SGRClear        = %DISPID_SGRId           + 1
%DISPID_SGRAddResource  = %DISPID_SGRClear        + 1
%DISPID_SGRAddState     = %DISPID_SGRAddResource  + 1

' enum DISPID_SpeechGrammarRules
%DISPID_SGRsCount         = 1
%DISPID_SGRsDynamic       = %DISPID_SGRsCount         + 1
%DISPID_SGRsAdd           = %DISPID_SGRsDynamic       + 1
%DISPID_SGRsCommit        = %DISPID_SGRsAdd           + 1
%DISPID_SGRsCommitAndSave = %DISPID_SGRsCommit        + 1
%DISPID_SGRsFindRule      = %DISPID_SGRsCommitAndSave + 1
%DISPID_SGRsItem          = %DISPID_VALUE
%DISPID_SGRs_NewEnum      = %DISPID_NEWENUM

' enum DISPID_SpeechGrammarRuleState
%DISPID_SGRSRule                 = 1
%DISPID_SGRSTransitions          = %DISPID_SGRSRule              + 1
%DISPID_SGRSAddWordTransition    = %DISPID_SGRSTransitions       + 1
%DISPID_SGRSAddRuleTransition    = %DISPID_SGRSAddWordTransition + 1
%DISPID_SGRSAddSpecialTransition = %DISPID_SGRSAddRuleTransition + 1

' enum SpeechSpecialTransitionType
%SSTTWildcard   = 1
%SSTTDictation  = %SSTTWildcard  + 1
%SSTTTextBuffer = %SSTTDictation + 1

' enum DISPID_SpeechGrammarRuleStateTransitions
%DISPID_SGRSTsCount    = 1
%DISPID_SGRSTsItem     = %DISPID_VALUE
%DISPID_SGRSTs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechGrammarRuleStateTransition
%DISPID_SGRSTType          = 1
%DISPID_SGRSTText          = %DISPID_SGRSTType          + 1
%DISPID_SGRSTRule          = %DISPID_SGRSTText          + 1
%DISPID_SGRSTWeight        = %DISPID_SGRSTRule          + 1
%DISPID_SGRSTPropertyName  = %DISPID_SGRSTWeight        + 1
%DISPID_SGRSTPropertyId    = %DISPID_SGRSTPropertyName  + 1
%DISPID_SGRSTPropertyValue = %DISPID_SGRSTPropertyId    + 1
%DISPID_SGRSTNextState     = %DISPID_SGRSTPropertyValue + 1

' enum SpeechGrammarRuleStateTransitionType
%SGRSTTEpsilon    = 0
%SGRSTTWord       = %SGRSTTEpsilon   + 1
%SGRSTTRule       = %SGRSTTWord      + 1
%SGRSTTDictation  = %SGRSTTRule      + 1
%SGRSTTWildcard   = %SGRSTTDictation + 1
%SGRSTTTextBuffer = %SGRSTTWildcard  + 1

' enum DISPIDSPTSI
%DISPIDSPTSI_ActiveOffset    = 1
%DISPIDSPTSI_ActiveLength    = %DISPIDSPTSI_ActiveOffset    + 1
%DISPIDSPTSI_SelectionOffset = %DISPIDSPTSI_ActiveLength    + 1
%DISPIDSPTSI_SelectionLength = %DISPIDSPTSI_SelectionOffset + 1

' enum DISPID_SpeechRecoResult
%DISPID_SRRRecoContext       = 1
%DISPID_SRRTimes             = %DISPID_SRRRecoContext  + 1
%DISPID_SRRAudioFormat       = %DISPID_SRRTimes        + 1
%DISPID_SRRPhraseInfo        = %DISPID_SRRAudioFormat  + 1
%DISPID_SRRAlternates        = %DISPID_SRRPhraseInfo   + 1
%DISPID_SRRAudio             = %DISPID_SRRAlternates   + 1
%DISPID_SRRSpeakAudio        = %DISPID_SRRAudio        + 1
%DISPID_SRRSaveToMemory      = %DISPID_SRRSpeakAudio   + 1
%DISPID_SRRDiscardResultInfo = %DISPID_SRRSaveToMemory + 1

' enum SpeechDiscardType
%SDTProperty      = %SPDF_PROPERTY
%SDTReplacement   = %SPDF_REPLACEMENT
%SDTRule          = %SPDF_RULE
%SDTDisplayText   = %SPDF_DISPLAYTEXT
%SDTLexicalForm   = %SPDF_LEXICALFORM
%SDTPronunciation = %SPDF_PRONUNCIATION
%SDTAudio         = %SPDF_AUDIO
%SDTAlternates    = %SPDF_ALTERNATES
%SDTAll           = %SPDF_ALL

' enum DISPID_SpeechXMLRecoResult
%DISPID_SRRGetXMLResult    = %DISPID_SRRDiscardResultInfo + 1
%DISPID_SRRGetXMLErrorInfo = %DISPID_SRRGetXMLResult      + 1

' enum DISPID_SpeechRecoResult2
%DISPID_SRRSetTextFeedback = %DISPID_SRRGetXMLErrorInfo + 1

' enum DISPID_SpeechPhraseBuilder
%DISPID_SPPBRestorePhraseFromMemory = 1

' enum DISPID_SpeechRecoResultTimes
%DISPID_SRRTStreamTime      = 1
%DISPID_SRRTLength          = %DISPID_SRRTStreamTime + 1
%DISPID_SRRTTickCount       = %DISPID_SRRTLength     + 1
%DISPID_SRRTOffsetFromStart = %DISPID_SRRTTickCount  + 1

' enum DISPID_SpeechPhraseAlternate
%DISPID_SPARecoResult               = 1
%DISPID_SPAStartElementInResult     = %DISPID_SPARecoResult               + 1
%DISPID_SPANumberOfElementsInResult = %DISPID_SPAStartElementInResult     + 1
%DISPID_SPAPhraseInfo               = %DISPID_SPANumberOfElementsInResult + 1
%DISPID_SPACommit                   = %DISPID_SPAPhraseInfo               + 1

' enum DISPID_SpeechPhraseAlternates
%DISPID_SPAsCount    = 1
%DISPID_SPAsItem     = %DISPID_VALUE
%DISPID_SPAs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechPhraseInfo
%DISPID_SPILanguageId           = 1
%DISPID_SPIGrammarId            = %DISPID_SPILanguageId          + 1
%DISPID_SPIStartTime            = %DISPID_SPIGrammarId           + 1
%DISPID_SPIAudioStreamPosition  = %DISPID_SPIStartTime           + 1
%DISPID_SPIAudioSizeBytes       = %DISPID_SPIAudioStreamPosition + 1
%DISPID_SPIRetainedSizeBytes    = %DISPID_SPIAudioSizeBytes      + 1
%DISPID_SPIAudioSizeTime        = %DISPID_SPIRetainedSizeBytes   + 1
%DISPID_SPIRule                 = %DISPID_SPIAudioSizeTime       + 1
%DISPID_SPIProperties           = %DISPID_SPIRule                + 1
%DISPID_SPIElements             = %DISPID_SPIProperties          + 1
%DISPID_SPIReplacements         = %DISPID_SPIElements            + 1
%DISPID_SPIEngineId             = %DISPID_SPIReplacements        + 1
%DISPID_SPIEnginePrivateData    = %DISPID_SPIEngineId            + 1
%DISPID_SPISaveToMemory         = %DISPID_SPIEnginePrivateData   + 1
%DISPID_SPIGetText              = %DISPID_SPISaveToMemory        + 1
%DISPID_SPIGetDisplayAttributes = %DISPID_SPIGetText             + 1

' enum DISPID_SpeechPhraseElement
%DISPID_SPEAudioTimeOffset      = 1
%DISPID_SPEAudioSizeTime        = %DISPID_SPEAudioTimeOffset      + 1
%DISPID_SPEAudioStreamOffset    = %DISPID_SPEAudioSizeTime        + 1
%DISPID_SPEAudioSizeBytes       = %DISPID_SPEAudioStreamOffset    + 1
%DISPID_SPERetainedStreamOffset = %DISPID_SPEAudioSizeBytes       + 1
%DISPID_SPERetainedSizeBytes    = %DISPID_SPERetainedStreamOffset + 1
%DISPID_SPEDisplayText          = %DISPID_SPERetainedSizeBytes    + 1
%DISPID_SPELexicalForm          = %DISPID_SPEDisplayText          + 1
%DISPID_SPEPronunciation        = %DISPID_SPELexicalForm          + 1
%DISPID_SPEDisplayAttributes    = %DISPID_SPEPronunciation        + 1
%DISPID_SPERequiredConfidence   = %DISPID_SPEDisplayAttributes    + 1
%DISPID_SPEActualConfidence     = %DISPID_SPERequiredConfidence   + 1
%DISPID_SPEEngineConfidence     = %DISPID_SPEActualConfidence     + 1

' enum SpeechEngineConfidence
%SECLowConfidence    = -1
%SECNormalConfidence = 0
%SECHighConfidence   = 1

' enum DISPID_SpeechPhraseElements
%DISPID_SPEsCount    = 1
%DISPID_SPEsItem     = %DISPID_VALUE
%DISPID_SPEs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechPhraseReplacement
%DISPID_SPRDisplayAttributes = 1
%DISPID_SPRText              = %DISPID_SPRDisplayAttributes + 1
%DISPID_SPRFirstElement      = %DISPID_SPRText              + 1
%DISPID_SPRNumberOfElements  = %DISPID_SPRFirstElement      + 1

' enum DISPID_SpeechPhraseReplacements
%DISPID_SPRsCount    = 1
%DISPID_SPRsItem     = %DISPID_VALUE
%DISPID_SPRs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechPhraseProperty
%DISPID_SPPName             = 1
%DISPID_SPPId               = %DISPID_SPPName             + 1
%DISPID_SPPValue            = %DISPID_SPPId               + 1
%DISPID_SPPFirstElement     = %DISPID_SPPValue            + 1
%DISPID_SPPNumberOfElements = %DISPID_SPPFirstElement     + 1
%DISPID_SPPEngineConfidence = %DISPID_SPPNumberOfElements + 1
%DISPID_SPPConfidence       = %DISPID_SPPEngineConfidence + 1
%DISPID_SPPParent           = %DISPID_SPPConfidence       + 1
%DISPID_SPPChildren         = %DISPID_SPPParent           + 1

' enum DISPID_SpeechPhraseProperties
%DISPID_SPPsCount    = 1
%DISPID_SPPsItem     = %DISPID_VALUE
%DISPID_SPPs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechPhraseRule
%DISPID_SPRuleName             = 1
%DISPID_SPRuleId               = %DISPID_SPRuleName             + 1
%DISPID_SPRuleFirstElement     = %DISPID_SPRuleId               + 1
%DISPID_SPRuleNumberOfElements = %DISPID_SPRuleFirstElement     + 1
%DISPID_SPRuleParent           = %DISPID_SPRuleNumberOfElements + 1
%DISPID_SPRuleChildren         = %DISPID_SPRuleParent           + 1
%DISPID_SPRuleConfidence       = %DISPID_SPRuleChildren         + 1
%DISPID_SPRuleEngineConfidence = %DISPID_SPRuleConfidence       + 1

' enum DISPID_SpeechPhraseRules
%DISPID_SPRulesCount    = 1
%DISPID_SPRulesItem     = %DISPID_VALUE
%DISPID_SPRules_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechLexicon
%DISPID_SLGenerationId                  = 1
%DISPID_SLGetWords                      = %DISPID_SLGenerationId                  + 1
%DISPID_SLAddPronunciation              = %DISPID_SLGetWords                      + 1
%DISPID_SLAddPronunciationByPhoneIds    = %DISPID_SLAddPronunciation              + 1
%DISPID_SLRemovePronunciation           = %DISPID_SLAddPronunciationByPhoneIds    + 1
%DISPID_SLRemovePronunciationByPhoneIds = %DISPID_SLRemovePronunciation           + 1
%DISPID_SLGetPronunciations             = %DISPID_SLRemovePronunciationByPhoneIds + 1
%DISPID_SLGetGenerationChange           = %DISPID_SLGetPronunciations             + 1

' enum SpeechLexiconType
%SLTUser = %eLEXTYPE_USER
%SLTApp  = %eLEXTYPE_APP

' enum SpeechPartOfSpeech
%SPSNotOverriden = %SPPS_NotOverriden
%SPSUnknown      = %SPPS_Unknown
%SPSNoun         = %SPPS_Noun
%SPSVerb         = %SPPS_Verb
%SPSModifier     = %SPPS_Modifier
%SPSFunction     = %SPPS_Function
%SPSInterjection = %SPPS_Interjection
%SPSLMA          = %SPPS_LMA
%SPSSuppressWord = %SPPS_SuppressWord

' enum DISPID_SpeechLexiconWords
%DISPID_SLWsCount    = 1
%DISPID_SLWsItem     = %DISPID_VALUE
%DISPID_SLWs_NewEnum = %DISPID_NEWENUM

' enum SpeechWordType
%SWTAdded   = %eWORDTYPE_ADDED
%SWTDeleted = %eWORDTYPE_DELETED

' enum DISPID_SpeechLexiconWord
%DISPID_SLWLangId         = 1
%DISPID_SLWType           = %DISPID_SLWLangId + 1
%DISPID_SLWWord           = %DISPID_SLWType   + 1
%DISPID_SLWPronunciations = %DISPID_SLWWord   + 1

' enum DISPID_SpeechLexiconProns
%DISPID_SLPsCount    = 1
%DISPID_SLPsItem     = %DISPID_VALUE
%DISPID_SLPs_NewEnum = %DISPID_NEWENUM

' enum DISPID_SpeechLexiconPronunciation
%DISPID_SLPType         = 1
%DISPID_SLPLangId       = %DISPID_SLPType         + 1
%DISPID_SLPPartOfSpeech = %DISPID_SLPLangId       + 1
%DISPID_SLPPhoneIds     = %DISPID_SLPPartOfSpeech + 1
%DISPID_SLPSymbolic     = %DISPID_SLPPhoneIds     + 1

' enum DISPID_SpeechPhoneConverter
%DISPID_SPCLangId    = 1
%DISPID_SPCPhoneToId = %DISPID_SPCLangId    + 1
%DISPID_SPCIdToPhone = %DISPID_SPCPhoneToId + 1


' ########################################################################################
' Interface name = ISpeechDataKey
' IID = {CE17C09B-4EFA-44D5-A4C9-59D9585AB0CD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechDataKey_INTERFACE_DEFINED)
    %ISpeechDataKey_INTERFACE_DEFINED = 1

INTERFACE ISpeechDataKey $IID_ISpeechDataKey

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetBinaryValue <1> ( _                        ' VTable offset = 28
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBinaryValue <2> ( _                        ' VTable offset = 32
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   ) AS VARIANT                                         ' __retval_out VARIANT* Value
   ' =====================================================================================
   METHOD SetStringValue <3> ( _                        ' VTable offset = 36
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStringValue <4> ( _                        ' VTable offset = 40
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   ) AS WSTRING                                         ' __retval_out BSTR* Value
   ' =====================================================================================
   METHOD SetLongValue <5> ( _                          ' VTable offset = 44
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   , BYVAL Value AS LONG _                              ' __in long Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLongValue <6> ( _                          ' VTable offset = 48
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   ) AS LONG                                            ' __retval_out long* Value
   ' =====================================================================================
   METHOD OpenKey <7> ( _                               ' VTable offset = 52
     BYVAL SubKeyName AS WSTRING _                      ' __in BSTR SubKeyName
   ) AS ISpeechDataKey                                  ' __retval_out ISpeechDataKey** SubKey
   ' =====================================================================================
   METHOD CreateKey <8> ( _                             ' VTable offset = 56
     BYVAL SubKeyName AS WSTRING _                      ' __in BSTR SubKeyName
   ) AS ISpeechDataKey                                  ' __retval_out ISpeechDataKey** SubKey
   ' =====================================================================================
   METHOD DeleteKey <9> ( _                             ' VTable offset = 60
     BYVAL SubKeyName AS WSTRING _                      ' __in BSTR SubKeyName
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteValue <10> ( _                          ' VTable offset = 64
     BYVAL ValueName AS WSTRING _                       ' __in BSTR ValueName
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumKeys <11> ( _                             ' VTable offset = 68
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WSTRING                                         ' __retval_out BSTR* SubKeyName
   ' =====================================================================================
   METHOD EnumValues <12> ( _                           ' VTable offset = 72
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WSTRING                                         ' __retval_out BSTR* ValueName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechDataKey_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechObjectToken
' IID = {C74A3ADC-B727-4500-A84A-B526721C8B8C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechObjectToken_INTERFACE_DEFINED)
    %ISpeechObjectToken_INTERFACE_DEFINED = 1

INTERFACE ISpeechObjectToken $IID_ISpeechObjectToken

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* ObjectId
   ' =====================================================================================
   PROPERTY GET DataKey <2> ( _                         ' VTable offset = 32
   ) AS ISpeechDataKey                                  ' __retval_out ISpeechDataKey** DataKey
   ' =====================================================================================
   PROPERTY GET Category <3> ( _                        ' VTable offset = 36
   ) AS ISpeechObjectTokenCategory                      ' __retval_out ISpeechObjectTokenCategory** Category
   ' =====================================================================================
   METHOD GetDescription <4> ( _                        ' VTable offset = 40
     OPTIONAL BYVAL Locale AS LONG _                    ' __opt_in long Locale = 0
   ) AS WSTRING                                         ' __retval_out BSTR* Description
   ' =====================================================================================
   METHOD SetId <5> ( _                                 ' VTable offset = 44
     BYVAL Id AS WSTRING _                              ' __in BSTR Id
   , OPTIONAL BYVAL CategoryID AS WSTRING _             ' __opt_in BSTR CategoryID = L""
   , OPTIONAL BYVAL CreateIfNotExist AS INTEGER _       ' __opt_in VARIANT_BOOL CreateIfNotExist = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttribute <6> ( _                          ' VTable offset = 48
     BYVAL AttributeName AS WSTRING _                   ' __in BSTR AttributeName
   ) AS WSTRING                                         ' __retval_out BSTR* AttributeValue
   ' =====================================================================================
   METHOD CreateInstance <7> ( _                        ' VTable offset = 52
     OPTIONAL BYVAL pUnkOuter AS IUnknown _             ' __opt_in IUnknown *pUnkOuter = NULL
   , OPTIONAL BYVAL ClsContext AS LONG _                ' __opt_in SpeechTokenContext ClsContext = 23
   ) AS IUnknown                                        ' __retval_out IUnknown** Object
   ' =====================================================================================
   METHOD Remove <8> ( _                                ' VTable offset = 56
     BYVAL ObjectStorageCLSID AS WSTRING _              ' __in BSTR ObjectStorageCLSID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStorageFileName <9> ( _                    ' VTable offset = 60
     BYVAL ObjectStorageCLSID AS WSTRING _              ' __in BSTR ObjectStorageCLSID
   , BYVAL KeyName AS WSTRING _                         ' __in BSTR KeyName
   , BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , BYVAL Folder AS LONG _                             ' __in SpeechTokenShellFolder Folder
   ) AS WSTRING                                         ' __retval_out BSTR* FilePath
   ' =====================================================================================
   METHOD RemoveStorageFileName <10> ( _                ' VTable offset = 64
     BYVAL ObjectStorageCLSID AS WSTRING _              ' __in BSTR ObjectStorageCLSID
   , BYVAL KeyName AS WSTRING _                         ' __in BSTR KeyName
   , BYVAL DeleteFile AS INTEGER _                      ' __in VARIANT_BOOL DeleteFile
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUISupported <11> ( _                        ' VTable offset = 68
     BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData = ""
   , OPTIONAL BYVAL Object AS IUnknown _                ' __opt_in IUnknown *Object = NULL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD DisplayUI <12> ( _                            ' VTable offset = 72
     BYVAL hWnd AS LONG _                               ' __in long hWnd
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData = ""
   , OPTIONAL BYVAL Object AS IUnknown _                ' __opt_in IUnknown *Object = NULL
   )                                                    ' void
   ' =====================================================================================
   METHOD MatchesAttributes <13> ( _                    ' VTable offset = 76
     BYVAL Attributes AS WSTRING _                      ' __in BSTR Attributes
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Matches
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechObjectToken_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechObjectTokens
' IID = {9285B776-2E7B-4BC0-B53E-580EB6FA967F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechObjectTokens_INTERFACE_DEFINED)
    %ISpeechObjectTokens_INTERFACE_DEFINED = 1

INTERFACE ISpeechObjectTokens $IID_ISpeechObjectTokens

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken** Token
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechObjectTokens_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechObjectTokenCategory
' IID = {CA7EAC50-2D01-4145-86D4-5AE7D70F4469}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechObjectTokenCategory_INTERFACE_DEFINED)
    %ISpeechObjectTokenCategory_INTERFACE_DEFINED = 1

INTERFACE ISpeechObjectTokenCategory $IID_ISpeechObjectTokenCategory

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* Id
   ' =====================================================================================
   PROPERTY SET Default <2> ( _                         ' VTable offset = 32
     BYVAL TokenId AS WSTRING _                         ' __in BSTR TokenId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Default <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* TokenId
   ' =====================================================================================
   METHOD SetId <3> ( _                                 ' VTable offset = 40
     BYVAL Id AS WSTRING _                              ' __in BSTR Id
   , OPTIONAL BYVAL CreateIfNotExist AS INTEGER _       ' __opt_in VARIANT_BOOL CreateIfNotExist = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDataKey <4> ( _                            ' VTable offset = 44
     OPTIONAL BYVAL Location AS LONG _                  ' __opt_in SpeechDataKeyLocation Location = 0
   ) AS ISpeechDataKey                                  ' __retval_out ISpeechDataKey** DataKey
   ' =====================================================================================
   METHOD EnumerateTokens <5> ( _                       ' VTable offset = 48
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** Tokens
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechObjectTokenCategory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechAudioBufferInfo
' IID = {11B103D8-1142-4EDF-A093-82FB3915F8CC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechAudioBufferInfo_INTERFACE_DEFINED)
    %ISpeechAudioBufferInfo_INTERFACE_DEFINED = 1

INTERFACE ISpeechAudioBufferInfo $IID_ISpeechAudioBufferInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MinNotification <1> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* MinNotification
   ' =====================================================================================
   PROPERTY SET MinNotification <1> ( _                 ' VTable offset = 32
     BYVAL MinNotification AS LONG _                    ' __in long MinNotification
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferSize <2> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* BufferSize
   ' =====================================================================================
   PROPERTY SET BufferSize <2> ( _                      ' VTable offset = 40
     BYVAL BufferSize AS LONG _                         ' __in long BufferSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventBias <3> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* EventBias
   ' =====================================================================================
   PROPERTY SET EventBias <3> ( _                       ' VTable offset = 48
     BYVAL EventBias AS LONG _                          ' __in long EventBias
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechAudioBufferInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechAudioStatus
' IID = {C62D9C91-7458-47F6-862D-1EF86FB0B278}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechAudioStatus_INTERFACE_DEFINED)
    %ISpeechAudioStatus_INTERFACE_DEFINED = 1

INTERFACE ISpeechAudioStatus $IID_ISpeechAudioStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FreeBufferSpace <1> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* FreeBufferSpace
   ' =====================================================================================
   PROPERTY GET NonBlockingIO <2> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* NonBlockingIO
   ' =====================================================================================
   PROPERTY GET State <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out SpeechAudioState* State
   ' =====================================================================================
   PROPERTY GET CurrentSeekPosition <4> ( _             ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT* CurrentSeekPosition
   ' =====================================================================================
   PROPERTY GET CurrentDevicePosition <5> ( _           ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT* CurrentDevicePosition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechAudioStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechAudioFormat
' IID = {E6E9C590-3E18-40E3-8299-061F98BDE7C7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechAudioFormat_INTERFACE_DEFINED)
    %ISpeechAudioFormat_INTERFACE_DEFINED = 1

INTERFACE ISpeechAudioFormat $IID_ISpeechAudioFormat

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out SpeechAudioFormatType* AudioFormat
   ' =====================================================================================
   PROPERTY SET Type <1> ( _                            ' VTable offset = 32
     BYVAL AudioFormat AS LONG _                        ' __in SpeechAudioFormatType AudioFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Guid <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* Guid
   ' =====================================================================================
   PROPERTY SET Guid <2> ( _                            ' VTable offset = 40
     BYVAL Guid AS WSTRING _                            ' __in BSTR Guid
   )                                                    ' void
   ' =====================================================================================
   METHOD GetWaveFormatEx <3> ( _                       ' VTable offset = 44
   ) AS ISpeechWaveFormatEx                             ' __retval_out ISpeechWaveFormatEx** WaveFormatEx
   ' =====================================================================================
   METHOD SetWaveFormatEx <4> ( _                       ' VTable offset = 48
     BYVAL WaveFormatEx AS ISpeechWaveFormatEx _        ' __in ISpeechWaveFormatEx* WaveFormatEx
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechAudioFormat_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechWaveFormatEx
' IID = {7A1EF0D5-1581-4741-88E4-209A49F11A10}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechWaveFormatEx_INTERFACE_DEFINED)
    %ISpeechWaveFormatEx_INTERFACE_DEFINED = 1

INTERFACE ISpeechWaveFormatEx $IID_ISpeechWaveFormatEx

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FormatTag <1> ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* FormatTag
   ' =====================================================================================
   PROPERTY SET FormatTag <1> ( _                       ' VTable offset = 32
     BYVAL FormatTag AS INTEGER _                       ' __in short FormatTag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Channels <2> ( _                        ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* Channels
   ' =====================================================================================
   PROPERTY SET Channels <2> ( _                        ' VTable offset = 40
     BYVAL Channels AS INTEGER _                        ' __in short Channels
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SamplesPerSec <3> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* SamplesPerSec
   ' =====================================================================================
   PROPERTY SET SamplesPerSec <3> ( _                   ' VTable offset = 48
     BYVAL SamplesPerSec AS LONG _                      ' __in long SamplesPerSec
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvgBytesPerSec <4> ( _                  ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* AvgBytesPerSec
   ' =====================================================================================
   PROPERTY SET AvgBytesPerSec <4> ( _                  ' VTable offset = 56
     BYVAL AvgBytesPerSec AS LONG _                     ' __in long AvgBytesPerSec
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockAlign <5> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* BlockAlign
   ' =====================================================================================
   PROPERTY SET BlockAlign <5> ( _                      ' VTable offset = 64
     BYVAL BlockAlign AS INTEGER _                      ' __in short BlockAlign
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BitsPerSample <6> ( _                   ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short* BitsPerSample
   ' =====================================================================================
   PROPERTY SET BitsPerSample <6> ( _                   ' VTable offset = 72
     BYVAL BitsPerSample AS INTEGER _                   ' __in short BitsPerSample
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExtraData <7> ( _                       ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT* ExtraData
   ' =====================================================================================
   PROPERTY SET ExtraData <7> ( _                       ' VTable offset = 80
     BYVAL ExtraData AS VARIANT _                       ' __in VARIANT ExtraData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechWaveFormatEx_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechBaseStream
' IID = {6450336F-7D49-4CED-8097-49D6DEE37294}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechBaseStream_INTERFACE_DEFINED)
    %ISpeechBaseStream_INTERFACE_DEFINED = 1

INTERFACE ISpeechBaseStream $IID_ISpeechBaseStream

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechBaseStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechFileStream
' IID = {AF67F125-AB39-4E93-B4A2-CC2E66E182A7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISpeechBaseStream
' ########################################################################################

#IF NOT %DEF(%ISpeechFileStream_INTERFACE_DEFINED)
    %ISpeechFileStream_INTERFACE_DEFINED = 1

INTERFACE ISpeechFileStream $IID_ISpeechFileStream

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechBaseStream Methods
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechFileStream Methods
   ' =====================================================================================
   METHOD Open <100> ( _                                ' VTable offset = 48
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL FileMode AS LONG _                  ' __opt_in SpeechStreamFileMode FileMode = 0
   , OPTIONAL BYVAL DoEvents AS INTEGER _               ' __opt_in VARIANT_BOOL DoEvents = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <101> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechFileStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechMemoryStream
' IID = {EEB14B68-808B-4ABE-A5EA-B51DA7588008}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISpeechBaseStream
' ########################################################################################

#IF NOT %DEF(%ISpeechMemoryStream_INTERFACE_DEFINED)
    %ISpeechMemoryStream_INTERFACE_DEFINED = 1

INTERFACE ISpeechMemoryStream $IID_ISpeechMemoryStream

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechBaseStream Methods
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechMemoryStream Methods
   ' =====================================================================================
   METHOD SetData <100> ( _                             ' VTable offset = 48
     BYVAL Data AS VARIANT _                            ' __in VARIANT Data
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData <101> ( _                             ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT* pData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechMemoryStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechCustomStream
' IID = {1A9E9F4F-104F-4DB8-A115-EFD7FD0C97AE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISpeechBaseStream
' ########################################################################################

#IF NOT %DEF(%ISpeechCustomStream_INTERFACE_DEFINED)
    %ISpeechCustomStream_INTERFACE_DEFINED = 1

INTERFACE ISpeechCustomStream $IID_ISpeechCustomStream

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechBaseStream Methods
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechCustomStream Methods
   ' =====================================================================================
   PROPERTY GET BaseStream <100> ( _                    ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown** ppUnkStream
   ' =====================================================================================
   PROPERTY SET putref_BaseStream <100> ( _             ' VTable offset = 52
     BYVAL ppUnkStream AS IUnknown _                    ' __in IUnknown ppUnkStream
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechCustomStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechAudio
' IID = {CFF8E175-019E-11D3-A08E-00C04F8EF9B5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISpeechBaseStream
' ########################################################################################

#IF NOT %DEF(%ISpeechAudio_INTERFACE_DEFINED)
    %ISpeechAudio_INTERFACE_DEFINED = 1

INTERFACE ISpeechAudio $IID_ISpeechAudio

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechBaseStream Methods
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechAudio Methods
   ' =====================================================================================
   PROPERTY GET Status <200> ( _                        ' VTable offset = 48
   ) AS ISpeechAudioStatus                              ' __retval_out ISpeechAudioStatus** Status
   ' =====================================================================================
   PROPERTY GET BufferInfo <201> ( _                    ' VTable offset = 52
   ) AS ISpeechAudioBufferInfo                          ' __retval_out ISpeechAudioBufferInfo** BufferInfo
   ' =====================================================================================
   PROPERTY GET DefaultFormat <202> ( _                 ' VTable offset = 56
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** StreamFormat
   ' =====================================================================================
   PROPERTY GET Volume <203> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long* Volume
   ' =====================================================================================
   PROPERTY SET Volume <203> ( _                        ' VTable offset = 64
     BYVAL Volume AS LONG _                             ' __in long Volume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferNotifySize <204> ( _              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long* BufferNotifySize
   ' =====================================================================================
   PROPERTY SET BufferNotifySize <204> ( _              ' VTable offset = 72
     BYVAL BufferNotifySize AS LONG _                   ' __in long BufferNotifySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventHandle <205> ( _                   ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* EventHandle
   ' =====================================================================================
   METHOD SetState <206> ( _                            ' VTable offset = 80
     BYVAL State AS LONG _                              ' __in SpeechAudioState State
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechAudio_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechMMSysAudio
' IID = {3C76AF6D-1FD7-4831-81D1-3B71D5A13C44}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ISpeechAudio
' ########################################################################################

#IF NOT %DEF(%ISpeechMMSysAudio_INTERFACE_DEFINED)
    %ISpeechMMSysAudio_INTERFACE_DEFINED = 1

INTERFACE ISpeechMMSysAudio $IID_ISpeechMMSysAudio

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechBaseStream Methods
   ' =====================================================================================
   PROPERTY GET Format <1> ( _                          ' VTable offset = 28
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** AudioFormat
   ' =====================================================================================
   PROPERTY SET putref_Format <1> ( _                   ' VTable offset = 32
     BYVAL AudioFormat AS ISpeechAudioFormat _          ' __in ISpeechAudioFormat* AudioFormat
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <2> ( _                                  ' VTable offset = 36
     BYREF Buffer AS VARIANT _                          ' __out VARIANT* Buffer
   , BYVAL NumberOfBytes AS LONG _                      ' __in long NumberOfBytes
   ) AS LONG                                            ' __retval_out long* BytesRead
   ' =====================================================================================
   METHOD Write <3> ( _                                 ' VTable offset = 40
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   ) AS LONG                                            ' __retval_out long* BytesWritten
   ' =====================================================================================
   METHOD Seek <4> ( _                                  ' VTable offset = 44
     BYVAL Position AS VARIANT _                        ' __in VARIANT Position
   , OPTIONAL BYVAL Origin AS LONG _                    ' __opt_in SpeechStreamSeekPositionType Origin = 0
   ) AS VARIANT                                         ' __retval_out VARIANT* NewPosition
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechAudio Methods
   ' =====================================================================================
   PROPERTY GET Status <200> ( _                        ' VTable offset = 48
   ) AS ISpeechAudioStatus                              ' __retval_out ISpeechAudioStatus** Status
   ' =====================================================================================
   PROPERTY GET BufferInfo <201> ( _                    ' VTable offset = 52
   ) AS ISpeechAudioBufferInfo                          ' __retval_out ISpeechAudioBufferInfo** BufferInfo
   ' =====================================================================================
   PROPERTY GET DefaultFormat <202> ( _                 ' VTable offset = 56
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** StreamFormat
   ' =====================================================================================
   PROPERTY GET Volume <203> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long* Volume
   ' =====================================================================================
   PROPERTY SET Volume <203> ( _                        ' VTable offset = 64
     BYVAL Volume AS LONG _                             ' __in long Volume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferNotifySize <204> ( _              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long* BufferNotifySize
   ' =====================================================================================
   PROPERTY SET BufferNotifySize <204> ( _              ' VTable offset = 72
     BYVAL BufferNotifySize AS LONG _                   ' __in long BufferNotifySize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventHandle <205> ( _                   ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* EventHandle
   ' =====================================================================================
   METHOD SetState <206> ( _                            ' VTable offset = 80
     BYVAL State AS LONG _                              ' __in SpeechAudioState State
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechMMSysAudio Methods
   ' =====================================================================================
   PROPERTY GET DeviceId <300> ( _                      ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* DeviceId
   ' =====================================================================================
   PROPERTY SET DeviceId <300> ( _                      ' VTable offset = 88
     BYVAL DeviceId AS LONG _                           ' __in long DeviceId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineId <301> ( _                        ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* LineId
   ' =====================================================================================
   PROPERTY SET LineId <301> ( _                        ' VTable offset = 96
     BYVAL LineId AS LONG _                             ' __in long LineId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MMHandle <302> ( _                      ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long* Handle
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechMMSysAudio_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechVoice
' IID = {269316D8-57BD-11D2-9EEE-00C04F797396}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechVoice_INTERFACE_DEFINED)
    %ISpeechVoice_INTERFACE_DEFINED = 1

INTERFACE ISpeechVoice $IID_ISpeechVoice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 28
   ) AS ISpeechVoiceStatus                              ' __retval_out ISpeechVoiceStatus** Status
   ' =====================================================================================
   PROPERTY GET Voice <2> ( _                           ' VTable offset = 32
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken** Voice
   ' =====================================================================================
   PROPERTY SET putref_Voice <2> ( _                    ' VTable offset = 36
     BYVAL Voice AS ISpeechObjectToken _                ' __in ISpeechObjectToken* Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioOutput <3> ( _                     ' VTable offset = 40
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken** AudioOutput
   ' =====================================================================================
   PROPERTY SET putref_AudioOutput <3> ( _              ' VTable offset = 44
     BYVAL AudioOutput AS ISpeechObjectToken _          ' __in ISpeechObjectToken* AudioOutput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioOutputStream <4> ( _               ' VTable offset = 48
   ) AS ISpeechBaseStream                               ' __retval_out ISpeechBaseStream** AudioOutputStream
   ' =====================================================================================
   PROPERTY SET putref_AudioOutputStream <4> ( _        ' VTable offset = 52
     BYVAL AudioOutputStream AS ISpeechBaseStream _     ' __in ISpeechBaseStream* AudioOutputStream
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <5> ( _                            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* Rate
   ' =====================================================================================
   PROPERTY SET Rate <5> ( _                            ' VTable offset = 60
     BYVAL Rate AS LONG _                               ' __in long Rate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <6> ( _                          ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* Volume
   ' =====================================================================================
   PROPERTY SET Volume <6> ( _                          ' VTable offset = 68
     BYVAL Volume AS LONG _                             ' __in long Volume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET AllowAudioOutputFormatChangesOnNextSet <7> ( _ ' VTable offset = 72
     BYVAL Allow AS INTEGER _                           ' __in VARIANT_BOOL Allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowAudioOutputFormatChangesOnNextSet <7> ( _ ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Allow
   ' =====================================================================================
   PROPERTY GET EventInterests <8> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out SpeechVoiceEvents* EventInterestFlags
   ' =====================================================================================
   PROPERTY SET EventInterests <8> ( _                  ' VTable offset = 84
     BYVAL EventInterestFlags AS LONG _                 ' __in SpeechVoiceEvents EventInterestFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Priority <9> ( _                        ' VTable offset = 88
     BYVAL Priority AS LONG _                           ' __in SpeechVoicePriority Priority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <9> ( _                        ' VTable offset = 92
   ) AS LONG                                            ' __retval_out SpeechVoicePriority* Priority
   ' =====================================================================================
   PROPERTY SET AlertBoundary <10> ( _                  ' VTable offset = 96
     BYVAL Boundary AS LONG _                           ' __in SpeechVoiceEvents Boundary
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlertBoundary <10> ( _                  ' VTable offset = 100
   ) AS LONG                                            ' __retval_out SpeechVoiceEvents* Boundary
   ' =====================================================================================
   PROPERTY SET SynchronousSpeakTimeout <11> ( _        ' VTable offset = 104
     BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SynchronousSpeakTimeout <11> ( _        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long* msTimeout
   ' =====================================================================================
   METHOD Speak <12> ( _                                ' VTable offset = 112
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechVoiceSpeakFlags Flags = 0
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   METHOD SpeakStream <13> ( _                          ' VTable offset = 116
     BYVAL Stream AS ISpeechBaseStream _                ' __in ISpeechBaseStream* Stream
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechVoiceSpeakFlags Flags = 0
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   METHOD Pause <14> ( _                                ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <15> ( _                               ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip <16> ( _                                 ' VTable offset = 128
     BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , BYVAL NumItems AS LONG _                           ' __in long NumItems
   ) AS LONG                                            ' __retval_out long* NumSkipped
   ' =====================================================================================
   METHOD GetVoices <17> ( _                            ' VTable offset = 132
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** ObjectTokens
   ' =====================================================================================
   METHOD GetAudioOutputs <18> ( _                      ' VTable offset = 136
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** ObjectTokens
   ' =====================================================================================
   METHOD WaitUntilDone <19> ( _                        ' VTable offset = 140
     BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Done
   ' =====================================================================================
   METHOD SpeakCompleteEvent <20> ( _                   ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long* Handle
   ' =====================================================================================
   METHOD IsUISupported <21> ( _                        ' VTable offset = 148
     BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD DisplayUI <22> ( _                            ' VTable offset = 152
     BYVAL hWndParent AS LONG _                         ' __in long hWndParent
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData = ""
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechVoice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechVoiceStatus
' IID = {8BE47B07-57F6-11D2-9EEE-00C04F797396}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechVoiceStatus_INTERFACE_DEFINED)
    %ISpeechVoiceStatus_INTERFACE_DEFINED = 1

INTERFACE ISpeechVoiceStatus $IID_ISpeechVoiceStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CurrentStreamNumber <1> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   PROPERTY GET LastStreamNumberQueued <2> ( _          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *StreamNumber
   ' =====================================================================================
   PROPERTY GET LastHResult <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* HResult
   ' =====================================================================================
   PROPERTY GET RunningState <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out SpeechRunState* State
   ' =====================================================================================
   PROPERTY GET InputWordPosition <5> ( _               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* Position
   ' =====================================================================================
   PROPERTY GET InputWordLength <6> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* Length
   ' =====================================================================================
   PROPERTY GET InputSentencePosition <7> ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* Position
   ' =====================================================================================
   PROPERTY GET InputSentenceLength <8> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* Length
   ' =====================================================================================
   PROPERTY GET LastBookmark <9> ( _                    ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* Bookmark
   ' =====================================================================================
   PROPERTY GET LastBookmarkId <10> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* BookmarkId
   ' =====================================================================================
   PROPERTY GET PhonemeId <11> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out short* PhoneId
   ' =====================================================================================
   PROPERTY GET VisemeId <12> ( _                       ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out short* VisemeId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechVoiceStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecognizer
' IID = {2D5F1C0C-BD75-4B08-9478-3B11FEA2586C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecognizer_INTERFACE_DEFINED)
    %ISpeechRecognizer_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecognizer $IID_ISpeechRecognizer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET putref_Recognizer <1> ( _               ' VTable offset = 28
     BYVAL ISpeechObjectToken _                         ' __in ISpeechObjectToken* Recognizer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Recognizer <1> ( _                      ' VTable offset = 32
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken** Recognizer
   ' =====================================================================================
   PROPERTY SET AllowAudioInputFormatChangesOnNextSet <2> ( _ ' VTable offset = 36
     BYVAL Allow AS INTEGER _                           ' __in VARIANT_BOOL Allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowAudioInputFormatChangesOnNextSet <2> ( _ ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Allow
   ' =====================================================================================
   PROPERTY SET putref_AudioInput <3> ( _               ' VTable offset = 44
     OPTIONAL BYVAL AudioInput AS ISpeechObjectToken _  ' __opt_in ISpeechObjectToken* AudioInput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioInput <3> ( _                      ' VTable offset = 48
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken* *AudioInput
   ' =====================================================================================
   PROPERTY SET putref_AudioInputStream <4> ( _         ' VTable offset = 52
     OPTIONAL BYVAL AudioInputStream AS ISpeechBaseStream _ ' __opt_in ISpeechBaseStream* AudioInputStream = NULL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioInputStream <4> ( _                ' VTable offset = 56
   ) AS ISpeechBaseStream                               ' __retval_out ISpeechBaseStream** AudioInputStream
   ' =====================================================================================
   PROPERTY GET IsShared <5> ( _                        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Shared
   ' =====================================================================================
   PROPERTY SET State <6> ( _                           ' VTable offset = 64
     BYVAL State AS LONG _                              ' __in SpeechRecognizerState State
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <6> ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out SpeechRecognizerState* State
   ' =====================================================================================
   PROPERTY GET Status <7> ( _                          ' VTable offset = 72
   ) AS ISpeechRecognizerStatus                         ' __retval_out ISpeechRecognizerStatus** Status
   ' =====================================================================================
   PROPERTY SET putref_Profile <8> ( _                  ' VTable offset = 76
     OPTIONAL BYVAL Profile AS ISpeechObjectToken _     ' __opt_in ISpeechObjectToken* Profile = NULL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profile <8> ( _                         ' VTable offset = 80
   ) AS ISpeechObjectToken                              ' __retval_out ISpeechObjectToken** Profile
   ' =====================================================================================
   METHOD EmulateRecognition <9> ( _                    ' VTable offset = 84
     BYVAL TextElements AS VARIANT _                    ' __in VARIANT TextElements
   , OPTIONAL BYREF ElementDisplayAttributes AS VARIANT _ ' __opt_in VARIANT* ElementDisplayAttributes = ""
   , OPTIONAL BYVAL LanguageId AS LONG _                ' __opt_in long LanguageId = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateRecoContext <10> ( _                    ' VTable offset = 88
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext** NewContext
   ' =====================================================================================
   METHOD GetFormat <11> ( _                            ' VTable offset = 92
     BYVAL Type AS LONG _                               ' __in SpeechFormatType Type
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** Format
   ' =====================================================================================
   METHOD SetPropertyNumber <12> ( _                    ' VTable offset = 96
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS LONG _                              ' __in long Value
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD GetPropertyNumber <13> ( _                    ' VTable offset = 100
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYREF Value AS LONG _                              ' __in_out long* Value
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD SetPropertyString <14> ( _                    ' VTable offset = 104
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD GetPropertyString <15> ( _                    ' VTable offset = 108
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYREF Value AS WSTRING _                           ' __in_out BSTR* Value
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD IsUISupported <16> ( _                        ' VTable offset = 112
     BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData = ""
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Supported
   ' =====================================================================================
   METHOD DisplayUI <17> ( _                            ' VTable offset = 116
     BYVAL hWndParent AS LONG _                         ' __in long hWndParent
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , BYVAL TypeOfUI AS WSTRING _                        ' __in BSTR TypeOfUI
   , OPTIONAL BYREF ExtraData AS VARIANT _              ' __opt_in VARIANT* ExtraData ""
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRecognizers <18> ( _                       ' VTable offset = 120
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** ObjectTokens
   ' =====================================================================================
   METHOD GetAudioInputs <19> ( _                       ' VTable offset = 124
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** ObjectTokens
   ' =====================================================================================
   METHOD GetProfiles <20> ( _                          ' VTable offset = 128
     OPTIONAL BYVAL RequiredAttributes AS WSTRING _     ' __opt_in BSTR RequiredAttributes = L""
   , OPTIONAL BYVAL OptionalAttributes AS WSTRING _     ' __opt_in BSTR OptionalAttributes = L""
   ) AS ISpeechObjectTokens                             ' __retval_out ISpeechObjectTokens** ObjectTokens
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecognizer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecognizerStatus
' IID = {BFF9E781-53EC-484E-BB8A-0E1B5551E35C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecognizerStatus_INTERFACE_DEFINED)
    %ISpeechRecognizerStatus_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecognizerStatus $IID_ISpeechRecognizerStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AudioStatus <1> ( _                     ' VTable offset = 28
   ) AS ISpeechAudioStatus                              ' __retval_out ISpeechAudioStatus** AudioStatus
   ' =====================================================================================
   PROPERTY GET CurrentStreamPosition <2> ( _           ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT* pCurrentStreamPos
   ' =====================================================================================
   PROPERTY GET CurrentStreamNumber <3> ( _             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   PROPERTY GET NumberOfActiveRules <4> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* NumberOfActiveRules
   ' =====================================================================================
   PROPERTY GET ClsidEngine <5> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* ClsidEngine
   ' =====================================================================================
   PROPERTY GET SupportedLanguages <6> ( _              ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT* SupportedLanguages
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecognizerStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecoContext
' IID = {580AA49D-7E1E-4809-B8E2-57DA806104B8}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoContext_INTERFACE_DEFINED)
    %ISpeechRecoContext_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoContext $IID_ISpeechRecoContext

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Recognizer <1> ( _                      ' VTable offset = 28
   ) AS ISpeechRecognizer                               ' __retval_out ISpeechRecognizer** Recognizer
   ' =====================================================================================
   PROPERTY GET AudioInputInterferenceStatus <2> ( _    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out SpeechInterference* Interference
   ' =====================================================================================
   PROPERTY GET RequestedUIType <3> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* UIType
   ' =====================================================================================
   PROPERTY SET putref_Voice <4> ( _                    ' VTable offset = 40
     BYVAL Voice AS ISpeechVoice _                      ' __in ISpeechVoice* Voice
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Voice <4> ( _                           ' VTable offset = 44
   ) AS ISpeechVoice                                    ' __retval_out ISpeechVoice** Voice
   ' =====================================================================================
   PROPERTY SET AllowVoiceFormatMatchingOnNextSet <5> ( _ ' VTable offset = 48
     BYVAL pAllow AS INTEGER _                          ' __in VARIANT_BOOL pAllow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowVoiceFormatMatchingOnNextSet <5> ( _ ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllow
   ' =====================================================================================
   PROPERTY SET VoicePurgeEvent <6> ( _                 ' VTable offset = 56
     BYVAL EventInterest AS LONG _                      ' __in SpeechRecoEvents EventInterest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VoicePurgeEvent <6> ( _                 ' VTable offset = 60
   ) AS LONG                                            ' __retval_out SpeechRecoEvents* EventInterest
   ' =====================================================================================
   PROPERTY SET EventInterests <7> ( _                  ' VTable offset = 64
     BYVAL EventInterest AS LONG _                      ' __in SpeechRecoEvents EventInterest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventInterests <7> ( _                  ' VTable offset = 68
   ) AS LONG                                            ' __retval_out SpeechRecoEvents* EventInterest
   ' =====================================================================================
   PROPERTY SET CmdMaxAlternates <8> ( _                ' VTable offset = 72
     BYVAL MaxAlternates AS LONG _                      ' __in long MaxAlternates
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CmdMaxAlternates <8> ( _                ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* MaxAlternates
   ' =====================================================================================
   PROPERTY SET State <9> ( _                           ' VTable offset = 80
     BYVAL State AS LONG _                              ' __in SpeechRecoContextState State
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <9> ( _                           ' VTable offset = 84
   ) AS LONG                                            ' __retval_out SpeechRecoContextState* State
   ' =====================================================================================
   PROPERTY SET RetainedAudio <10> ( _                  ' VTable offset = 88
     BYVAL Option AS LONG _                             ' __in SpeechRetainedAudioOptions Option
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetainedAudio <10> ( _                  ' VTable offset = 92
   ) AS LONG                                            ' __retval_out SpeechRetainedAudioOptions* Option
   ' =====================================================================================
   PROPERTY SET putref_RetainedAudioFormat <11> ( _     ' VTable offset = 96
     BYVAL Format AS ISpeechAudioFormat _               ' __in ISpeechAudioFormat* Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetainedAudioFormat <11> ( _            ' VTable offset = 100
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** Format
   ' =====================================================================================
   METHOD Pause <12> ( _                                ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <13> ( _                               ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateGrammar <14> ( _                        ' VTable offset = 112
     OPTIONAL BYVAL GrammarId AS VARIANT _              ' __opt_in VARIANT GrammarId = 0
   ) AS ISpeechRecoGrammar                              ' __retval_out ISpeechRecoGrammar** Grammar
   ' =====================================================================================
   METHOD CreateResultFromMemory <15> ( _               ' VTable offset = 116
     BYREF ResultBlock AS VARIANT _                     ' __in VARIANT* ResultBlock
   ) AS ISpeechRecoResult                               ' __retval_out ISpeechRecoResult** Result
   ' =====================================================================================
   METHOD Bookmark <16> ( _                             ' VTable offset = 120
     BYVAL Options AS LONG _                            ' __in SpeechBookmarkOptions Options
   , BYVAL StreamPos AS VARIANT _                       ' __in VARIANT StreamPos
   , BYVAL bookmarkId AS VARIANT _                      ' __inB VARIANT bookmarkId
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAdaptationData <17> ( _                    ' VTable offset = 124
     BYVAL AdaptationString AS WSTRING _                ' __in BSTR AdaptationString
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecoGrammar
' IID = {B6D6F79F-2158-4E50-B5BC-9A9CCD852A09}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoGrammar_INTERFACE_DEFINED)
    %ISpeechRecoGrammar_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoGrammar $IID_ISpeechRecoGrammar

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT* Id
   ' =====================================================================================
   PROPERTY GET RecoContext <2> ( _                     ' VTable offset = 32
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext** RecoContext
   ' =====================================================================================
   PROPERTY SET State <3> ( _                           ' VTable offset = 36
     BYVAL State AS LONG _                              ' __in SpeechGrammarState State
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <3> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out SpeechGrammarState* State
   ' =====================================================================================
   PROPERTY GET Rules <4> ( _                           ' VTable offset = 44
   ) AS ISpeechGrammarRules                             ' __retval_out ISpeechGrammarRules** Rules
   ' =====================================================================================
   METHOD Reset <5> ( _                                 ' VTable offset = 48
     OPTIONAL BYVAL NewLanguage AS LONG _               ' __opt_in long NewLanguage = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdLoadFromFile <7> ( _                       ' VTable offset = 52
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL LoadOption AS LONG _                ' __opt_in SpeechLoadOption LoadOption = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdLoadFromObject <8> ( _                     ' VTable offset = 56
     BYVAL ClassId AS WSTRING _                         ' __in BSTR ClassId
   , BYVAL GrammarName AS WSTRING _                     ' __in BSTR GrammarName
   , OPTIONAL BYVAL LoadOption AS LONG _                ' __opt_in SpeechLoadOption LoadOption = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdLoadFromResource <9> ( _                   ' VTable offset = 60
     BYVAL hModule AS LONG _                                       ' __in long hModule
   , BYVAL ResourceName AS VARIANT _                                    ' __in VARIANT ResourceName
   , BYVAL ResourceType AS VARIANT _                                    ' __in VARIANT ResourceType
   , BYVAL LanguageId AS LONG _                                       ' __in long LanguageId
   , OPTIONAL BYVAL LoadOption AS LONG _                              ' __opt_in SpeechLoadOption LoadOption = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdLoadFromMemory <10> ( _                    ' VTable offset = 64
     BYVAL GrammarData AS VARIANT _                                    ' __in VARIANT GrammarData
   , OPTIONAL BYVAL LoadOption AS LONG _                              ' __opt_in SpeechLoadOption LoadOption = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdLoadFromProprietaryGrammar <11> ( _        ' VTable offset = 68
     BYVAL ProprietaryGuid AS WSTRING _                 ' __in BSTR ProprietaryGuid
   , BYVAL ProprietaryString AS WSTRING _               ' __in BSTR ProprietaryString
   , BYVAL ProprietaryData AS VARIANT _                 ' __in VARIANT ProprietaryData
   , OPTIONAL BYVAL LoadOption AS LONG _                ' __opt_in SpeechLoadOption LoadOption= 0
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdSetRuleState <12> ( _                      ' VTable offset = 72
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL State AS LONG _                              ' __in SpeechRuleState State
   )                                                    ' void
   ' =====================================================================================
   METHOD CmdSetRuleIdState <13> ( _                    ' VTable offset = 76
     BYVAL RuleId AS LONG _                             ' __in long RuleId
   , BYVAL State AS LONG _                              ' __in SpeechRuleState State
   )                                                    ' void
   ' =====================================================================================
   METHOD DictationLoad <14> ( _                        ' VTable offset = 80
     OPTIONAL BYVAL TopicName AS WSTRING _              ' __opt_in BSTR TopicName = L""
   , OPTIONAL BYVAL LoadOption AS LONG _                ' __opt_in SpeechLoadOption LoadOption = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD DictationUnload <15> ( _                      ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD DictationSetState <16> ( _                    ' VTable offset = 88
     BYVAL State AS LONG _                              ' __in SpeechRuleState State
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWordSequenceData <17> ( _                  ' VTable offset = 92
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   , BYVAL TextLength AS LONG _                         ' __in long TextLength
   , BYVAL Info AS ISpeechTextSelectionInformation _    ' __in ISpeechTextSelectionInformation* Info
   )                                                    ' void
   ' =====================================================================================
   METHOD SetTextSelection <18> ( _                     ' VTable offset = 96
     BYVAL Info AS ISpeechTextSelectionInformation _    ' __in ISpeechTextSelectionInformation* Info
   )                                                    ' void
   ' =====================================================================================
   METHOD IsPronounceable <19> ( _                      ' VTable offset = 100
     BYVAL Word AS WSTRING _                            ' __in BSTR Word
   ) AS LONG                                            ' __retval_out SpeechWordPronounceable* WordPronounceable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoGrammar_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechGrammarRule
' IID = {AFE719CF-5DD1-44F2-999C-7A399F1CFCCC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechGrammarRule_INTERFACE_DEFINED)
    %ISpeechGrammarRule_INTERFACE_DEFINED = 1

INTERFACE ISpeechGrammarRule $IID_ISpeechGrammarRule

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Attributes <1> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out SpeechRuleAttributes* Attributes
   ' =====================================================================================
   PROPERTY GET InitialState <2> ( _                    ' VTable offset = 32
   ) AS ISpeechGrammarRuleState                         ' __retval_out ISpeechGrammarRuleState** State
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* Name
   ' =====================================================================================
   PROPERTY GET Id <4> ( _                              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* Id
   ' =====================================================================================
   METHOD Clear <5> ( _                                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD AddResource <6> ( _                           ' VTable offset = 48
     BYVAL ResourceName AS WSTRING _                    ' __in BSTR ResourceName
   , BYVAL ResourceValue AS WSTRING _                   ' __in BSTR ResourceValue
   )                                                    ' void
   ' =====================================================================================
   METHOD AddState <7> ( _                              ' VTable offset = 52
   ) AS ISpeechGrammarRuleState                         ' __retval_out ISpeechGrammarRuleState** State
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechGrammarRule_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechGrammarRules
' IID = {6FFA3B44-FC2D-40D1-8AFC-32911C7F1AD1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechGrammarRules_INTERFACE_DEFINED)
    %ISpeechGrammarRules_INTERFACE_DEFINED = 1

INTERFACE ISpeechGrammarRules $IID_ISpeechGrammarRules

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD FindRule <6> ( _                              ' VTable offset = 32
     BYVAL RuleNameOrId AS VARIANT _                    ' __in VARIANT RuleNameOrId
   ) AS ISpeechGrammarRule                              ' __retval_out ISpeechGrammarRule** Rule
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechGrammarRule                              ' __retval_out ISpeechGrammarRule** Rule
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================
   PROPERTY GET Dynamic <2> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Dynamic
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 48
     BYVAL RuleName AS WSTRING _                        ' __in BSTR RuleName
   , BYVAL Attributes AS LONG _                         ' __in SpeechRuleAttributes Attributes
   , OPTIONAL BYVAL RuleId AS LONG _                    ' __opt_in long RuleId = 0
   ) AS ISpeechGrammarRule                              ' __retval_out ISpeechGrammarRule** Rule
   ' =====================================================================================
   METHOD Commit <4> ( _                                ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitAndSave <5> ( _                         ' VTable offset = 56
     BYREF ErrorText AS WSTRING _                       ' __out BSTR* ErrorText
   ) AS VARIANT                                         ' __retval_out VARIANT* SaveStream
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechGrammarRules_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechGrammarRuleState
' IID = {D4286F2C-EE67-45AE-B928-28D695362EDA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechGrammarRuleState_INTERFACE_DEFINED)
    %ISpeechGrammarRuleState_INTERFACE_DEFINED = 1

INTERFACE ISpeechGrammarRuleState $IID_ISpeechGrammarRuleState

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Rule <1> ( _                            ' VTable offset = 28
   ) AS ISpeechGrammarRule                              ' __retval_out ISpeechGrammarRule** Rule
   ' =====================================================================================
   PROPERTY GET Transitions <2> ( _                     ' VTable offset = 32
   ) AS ISpeechGrammarRuleStateTransitions              ' __retval_out ISpeechGrammarRuleStateTransitions** Transitions
   ' =====================================================================================
   METHOD AddWordTransition <3> ( _                     ' VTable offset = 36
     BYVAL DestState AS ISpeechGrammarRuleState _       ' __in ISpeechGrammarRuleState* DestState
   , BYVAL Words AS WSTRING _                           ' __in BSTR Words
   , OPTIONAL BYVAL Separators AS WSTRING _             ' __opt_in BSTR Separators = L" "
   , OPTIONAL BYVAL Type AS LONG _                      ' __opt_in SpeechGrammarWordType Type = 1
   , OPTIONAL BYVAL PropertyName AS WSTRING _           ' __opt_in BSTR PropertyName = L""
   , OPTIONAL BYVAL PropertyId AS LONG _                ' __opt_in long PropertyId = 0
   , OPTIONAL BYREF PropertyValue AS VARIANT _          ' __opt_in VARIANT* PropertyValue = ""
   , OPTIONAL BYVAL Weight AS SINGLE _                  ' __opt_in float Weight = 1
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRuleTransition <4> ( _                     ' VTable offset = 40
     BYVAL DestinationState AS ISpeechGrammarRuleState _ ' __in ISpeechGrammarRuleState* DestinationState
   , BYVAL Rule AS ISpeechGrammarRule _                 ' __in ISpeechGrammarRule* Rule
   , OPTIONAL BYVAL PropertyName AS WSTRING _           ' __opt_in BSTR PropertyName = L""
   , OPTIONAL BYVAL PropertyId AS LONG _                ' __opt_in long PropertyId = 0
   , OPTIONAL BYREF PropertyValue AS VARIANT _          ' __opt_in VARIANT* PropertyValue = ""
   , OPTIONAL BYVAL Weight AS SINGLE _                  ' __opt_in float Weight = 1
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSpecialTransition <5> ( _                  ' VTable offset = 44
     BYVAL DestinationState AS ISpeechGrammarRuleState _ ' __in ISpeechGrammarRuleState* DestinationState
   , BYVAL Type AS LONG _                               ' __in SpeechSpecialTransitionType Type
   , OPTIONAL BYVAL PropertyName AS WSTRING _           ' __opt_in BSTR PropertyName = L""
   , OPTIONAL BYVAL PropertyId AS LONG _                ' __opt_in long PropertyId = 0
   , OPTIONAL BYREF PropertyValue AS VARIANT _          ' __opt_in VARIANT* PropertyValue ""
   , OPTIONAL BYVAL Weight AS SINGLE _                  ' __opt_in float Weight = 1
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechGrammarRuleState_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechGrammarRuleStateTransition
' IID = {CAFD1DB1-41D1-4A06-9863-E2E81DA17A9A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED)
    %ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED = 1

INTERFACE ISpeechGrammarRuleStateTransition $IID_ISpeechGrammarRuleStateTransition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out SpeechGrammarRuleStateTransitionType* Type
   ' =====================================================================================
   PROPERTY GET Text <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY GET Rule <3> ( _                            ' VTable offset = 36
   ) AS ISpeechGrammarRule                              ' __retval_out ISpeechGrammarRule** Rule
   ' =====================================================================================
   PROPERTY GET Weight <4> ( _                          ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT* Weight
   ' =====================================================================================
   PROPERTY GET PropertyName <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* PropertyName
   ' =====================================================================================
   PROPERTY GET PropertyId <6> ( _                      ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* PropertyId
   ' =====================================================================================
   PROPERTY GET PropertyValue <7> ( _                   ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT* PropertyValue
   ' =====================================================================================
   PROPERTY GET NextState <8> ( _                       ' VTable offset = 56
   ) AS ISpeechGrammarRuleState                         ' __retval_out ISpeechGrammarRuleState** NextState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechGrammarRuleStateTransitions
' IID = {EABCE657-75BC-44A2-AA7F-C56476742963}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED)
    %ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED = 1

INTERFACE ISpeechGrammarRuleStateTransitions $IID_ISpeechGrammarRuleStateTransitions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechGrammarRuleStateTransition               ' __retval_out ISpeechGrammarRuleStateTransition** Transition
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechTextSelectionInformation
' IID = {3B9C7E7A-6EEE-4DED-9092-11657279ADBE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechTextSelectionInformation_INTERFACE_DEFINED)
    %ISpeechTextSelectionInformation_INTERFACE_DEFINED = 1

INTERFACE ISpeechTextSelectionInformation $IID_ISpeechTextSelectionInformation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET ActiveOffset <1> ( _                    ' VTable offset = 28
     BYVAL ActiveOffset AS LONG _                       ' __in long ActiveOffset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveOffset <1> ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* ActiveOffset
   ' =====================================================================================
   PROPERTY SET ActiveLength <2> ( _                    ' VTable offset = 36
     BYVAL ActiveLength AS LONG _                       ' __in long ActiveLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveLength <2> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* ActiveLength
   ' =====================================================================================
   PROPERTY SET SelectionOffset <3> ( _                 ' VTable offset = 44
     BYVAL SelectionOffset AS LONG _                    ' __in long SelectionOffset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionOffset <3> ( _                 ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* SelectionOffset
   ' =====================================================================================
   PROPERTY SET SelectionLength <4> ( _                 ' VTable offset = 52
     BYVAL SelectionLength AS LONG _                    ' __in long SelectionLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectionLength <4> ( _                 ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* SelectionLength
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechTextSelectionInformation_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecoResult
' IID = {ED2879CF-CED9-4EE6-A534-DE0191D5468D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoResult_INTERFACE_DEFINED)
    %ISpeechRecoResult_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoResult $IID_ISpeechRecoResult

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RecoContext <1> ( _                     ' VTable offset = 28
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext** RecoContext
   ' =====================================================================================
   PROPERTY GET Times <2> ( _                           ' VTable offset = 32
   ) AS ISpeechRecoResultTimes                          ' __retval_out ISpeechRecoResultTimes** Times
   ' =====================================================================================
   PROPERTY SET putref_AudioFormat <3> ( _              ' VTable offset = 36
     BYVAL Format AS ISpeechAudioFormat _               ' __in ISpeechAudioFormat* Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioFormat <3> ( _                     ' VTable offset = 40
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** Format
   ' =====================================================================================
   PROPERTY GET PhraseInfo <4> ( _                      ' VTable offset = 44
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo** PhraseInfo
   ' =====================================================================================
   METHOD Alternates <5> ( _                            ' VTable offset = 48
     BYVAL RequestCount AS LONG _                       ' __in long RequestCount
   , OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechPhraseAlternates                         ' __retval_out ISpeechPhraseAlternates** Alternates
   ' =====================================================================================
   METHOD Audio <6> ( _                                 ' VTable offset = 52
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechMemoryStream                             ' __retval_out ISpeechMemoryStream** Stream
   ' =====================================================================================
   METHOD SpeakAudio <7> ( _                            ' VTable offset = 56
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechVoiceSpeakFlags Flags = 0
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   METHOD SaveToMemory <8> ( _                          ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT* ResultBlock
   ' =====================================================================================
   METHOD DiscardResultInfo <9> ( _                     ' VTable offset = 64
     BYVAL ValueTypes AS LONG _                         ' __in SpeechDiscardType ValueTypes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoResult_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecoResult2
' IID = 8E0A246D-D3C8-45DE-8657-04290C458C3C
' Inherited interface = ISpeechRecoResult
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoResult2_INTERFACE_DEFINED)
    %ISpeechRecoResult2_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoResult2 $IID_ISpeechRecoResult2

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechRecoResult Methods
   ' =====================================================================================
   PROPERTY GET RecoContext <1> ( _                     ' VTable offset = 28
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext** RecoContext
   ' =====================================================================================
   PROPERTY GET Times <2> ( _                           ' VTable offset = 32
   ) AS ISpeechRecoResultTimes                          ' __retval_out ISpeechRecoResultTimes** Times
   ' =====================================================================================
   PROPERTY SET putref_AudioFormat <3> ( _              ' VTable offset = 36
     BYVAL Format AS ISpeechAudioFormat _               ' __in ISpeechAudioFormat* Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioFormat <3> ( _                     ' VTable offset = 40
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** Format
   ' =====================================================================================
   PROPERTY GET PhraseInfo <4> ( _                      ' VTable offset = 44
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo** PhraseInfo
   ' =====================================================================================
   METHOD Alternates <5> ( _                            ' VTable offset = 48
     BYVAL RequestCount AS LONG _                       ' __in long RequestCount
   , OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechPhraseAlternates                         ' __retval_out ISpeechPhraseAlternates** Alternates
   ' =====================================================================================
   METHOD Audio <6> ( _                                 ' VTable offset = 52
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechMemoryStream                             ' __retval_out ISpeechMemoryStream** Stream
   ' =====================================================================================
   METHOD SpeakAudio <7> ( _                            ' VTable offset = 56
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechVoiceSpeakFlags Flags = 0
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   METHOD SaveToMemory <8> ( _                          ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT* ResultBlock
   ' =====================================================================================
   METHOD DiscardResultInfo <9> ( _                     ' VTable offset = 64
     BYVAL ValueTypes AS LONG _                         ' __in SpeechDiscardType ValueTypes
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechRecoResult2 Methods
   ' =====================================================================================
   METHOD SetTextFeedback <12> ( _                      ' VTable offset = 68
     BYVAL Feedback AS WSTRING _                        ' __in BSTR Feedback
   , BYVAL WasSuccessful AS INTEGER _                   ' __in VARIANT_BOOL WasSuccessful
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoResult2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechRecoResultTimes
' IID = {62B3B8FB-F6E7-41BE-BDCB-056B1C29EFC0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoResultTimes_INTERFACE_DEFINED)
    %ISpeechRecoResultTimes_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoResultTimes $IID_ISpeechRecoResultTimes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StreamTime <1> ( _                      ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT* Time
   ' =====================================================================================
   PROPERTY GET Length <2> ( _                          ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT* Length
   ' =====================================================================================
   PROPERTY GET TickCount <3> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* TickCount
   ' =====================================================================================
   PROPERTY GET OffsetFromStart <4> ( _                 ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT* OffsetFromStart
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoResultTimes_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseAlternate
' IID = {27864A2A-2B9F-4CB8-92D3-0D2722FD1E73}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseAlternate_INTERFACE_DEFINED)
    %ISpeechPhraseAlternate_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseAlternate $IID_ISpeechPhraseAlternate

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RecoResult <1> ( _                      ' VTable offset = 28
   ) AS ISpeechRecoResult                               ' __retval_out ISpeechRecoResult** RecoResult
   ' =====================================================================================
   PROPERTY GET StartElementInResult <2> ( _            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* StartElement
   ' =====================================================================================
   PROPERTY GET NumberOfElementsInResult <3> ( _        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* NumberOfElements
   ' =====================================================================================
   PROPERTY GET PhraseInfo <4> ( _                      ' VTable offset = 40
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo** PhraseInfo
   ' =====================================================================================
   METHOD Commit <5> ( _                                ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseAlternate_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseAlternates
' IID = {B238B6D5-F276-4C3D-A6C1-2974801C3CC2}
' ISpeechPhraseAlternates Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseAlternates_INTERFACE_DEFINED)
    %ISpeechPhraseAlternates_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseAlternates $IID_ISpeechPhraseAlternates

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechPhraseAlternate                          ' __retval_out ISpeechPhraseAlternate** PhraseAlternate
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseAlternates_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseInfo
' IID = {961559CF-4E67-4662-8BF0-D93F1FCD61B3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseInfo_INTERFACE_DEFINED)
    %ISpeechPhraseInfo_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseInfo $IID_ISpeechPhraseInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LanguageId <1> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* LanguageId
   ' =====================================================================================
   PROPERTY GET GrammarId <2> ( _                       ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT* GrammarId
   ' =====================================================================================
   PROPERTY GET StartTime <3> ( _                       ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* StartTime
   ' =====================================================================================
   PROPERTY GET AudioStreamPosition <4> ( _             ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT* AudioStreamPosition
   ' =====================================================================================
   PROPERTY GET AudioSizeBytes <5> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pAudioSizeBytes
   ' =====================================================================================
   PROPERTY GET RetainedSizeBytes <6> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* RetainedSizeBytes
   ' =====================================================================================
   PROPERTY GET AudioSizeTime <7> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* AudioSizeTime
   ' =====================================================================================
   PROPERTY GET Rule <8> ( _                            ' VTable offset = 56
   ) AS ISpeechPhraseRule                               ' __retval_out ISpeechPhraseRule** Rule
   ' =====================================================================================
   PROPERTY GET Properties <9> ( _                      ' VTable offset = 60
   ) AS ISpeechPhraseProperties                         ' __retval_out ISpeechPhraseProperties** Properties
   ' =====================================================================================
   PROPERTY GET Elements <10> ( _                       ' VTable offset = 64
   ) AS ISpeechPhraseElements                           ' __retval_out ISpeechPhraseElements** Elements
   ' =====================================================================================
   PROPERTY GET Replacements <11> ( _                   ' VTable offset = 68
   ) AS ISpeechPhraseReplacements                       ' __retval_out ISpeechPhraseReplacements** Replacements
   ' =====================================================================================
   PROPERTY GET EngineId <12> ( _                       ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR* EngineIdGuid
   ' =====================================================================================
   PROPERTY GET EnginePrivateData <13> ( _              ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT* PrivateData
   ' =====================================================================================
   METHOD SaveToMemory <14> ( _                         ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT* PhraseBlock
   ' =====================================================================================
   METHOD GetText <15> ( _                              ' VTable offset = 84
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   , OPTIONAL BYVAL UseReplacements AS INTEGER _        ' __opt_in VARIANT_BOOL UseReplacements = -1
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   METHOD GetDisplayAttributes <16> ( _                 ' VTable offset = 88
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   , OPTIONAL BYVAL DisplayAttributes AS INTEGER _      ' __opt_in VARIANT_BOOL UseReplacements = -1
   ) AS LONG                                            ' __retval_out SpeechDisplayAttributes* DisplayAttributes
   ' =====================================================================================

END INTERFACE


#ENDIF   ' /* __ISpeechPhraseInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseElement
' IID = {E6176F96-E373-4801-B223-3B62C068C0B4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseElement_INTERFACE_DEFINED)
    %ISpeechPhraseElement_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseElement $IID_ISpeechPhraseElement

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AudioTimeOffset <1> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* AudioTimeOffset
   ' =====================================================================================
   PROPERTY GET AudioSizeTime <2> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* AudioSizeTime
   ' =====================================================================================
   PROPERTY GET AudioStreamOffset <3> ( _               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* AudioStreamOffset
   ' =====================================================================================
   PROPERTY GET AudioSizeBytes <4> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* AudioSizeBytes
   ' =====================================================================================
   PROPERTY GET RetainedStreamOffset <5> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* RetainedStreamOffset
   ' =====================================================================================
   PROPERTY GET RetainedSizeBytes <6> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* RetainedSizeBytes
   ' =====================================================================================
   PROPERTY GET DisplayText <7> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* DisplayText
   ' =====================================================================================
   PROPERTY GET LexicalForm <8> ( _                     ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* LexicalForm
   ' =====================================================================================
   PROPERTY GET Pronunciation <9> ( _                   ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT* Pronunciation
   ' =====================================================================================
   PROPERTY GET DisplayAttributes <10> ( _              ' VTable offset = 64
   ) AS LONG                                            ' __retval_out SpeechDisplayAttributes* DisplayAttributes
   ' =====================================================================================
   PROPERTY GET RequiredConfidence <11> ( _             ' VTable offset = 68
   ) AS LONG                                            ' __retval_out SpeechEngineConfidence* RequiredConfidence
   ' =====================================================================================
   PROPERTY GET ActualConfidence <12> ( _               ' VTable offset = 72
   ) AS LONG                                            ' __retval_out SpeechEngineConfidence* ActualConfidence
   ' =====================================================================================
   PROPERTY GET EngineConfidence <13> ( _               ' VTable offset = 76
   ) AS SINGLE                                          ' __retval_out float* EngineConfidence
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseElement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseElements
' IID = {0626B328-3478-467D-A0B3-D0853B93DDA3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseElements_INTERFACE_DEFINED)
    %ISpeechPhraseElements_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseElements $IID_ISpeechPhraseElements

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechPhraseElement                            ' __retval_out ISpeechPhraseElement** Element
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseElements_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseReplacement
' IID = {2890A410-53A7-4FB5-94EC-06D4998E3D02}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseReplacement_INTERFACE_DEFINED)
    %ISpeechPhraseReplacement_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseReplacement $IID_ISpeechPhraseReplacement

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayAttributes <1> ( _               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out SpeechDisplayAttributes* DisplayAttributes
   ' =====================================================================================
   PROPERTY GET Text <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY GET FirstElement <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* FirstElement
   ' =====================================================================================
   PROPERTY GET NumberOfElements <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* NumberOfElements
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseReplacement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseReplacements
' IID = {38BC662F-2257-4525-959E-2069D2596C05}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseReplacements_INTERFACE_DEFINED)
    %ISpeechPhraseReplacements_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseReplacements $IID_ISpeechPhraseReplacements

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechPhraseReplacement                        ' __retval_out ISpeechPhraseReplacement** Reps
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseReplacements_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseProperty
' IID = {CE563D48-961E-4732-A2E1-378A42B430BE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseProperty_INTERFACE_DEFINED)
    %ISpeechPhraseProperty_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseProperty $IID_ISpeechPhraseProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Id
   ' =====================================================================================
   PROPERTY GET Value <3> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* Value
   ' =====================================================================================
   PROPERTY GET FirstElement <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* FirstElement
   ' =====================================================================================
   PROPERTY GET NumberOfElements <5> ( _                ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* NumberOfElements
   ' =====================================================================================
   PROPERTY GET EngineConfidence <6> ( _                ' VTable offset = 48
   ) AS SINGLE                                          ' __retval_out float* Confidence
   ' =====================================================================================
   PROPERTY GET Confidence <7> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out SpeechEngineConfidence* Confidence
   ' =====================================================================================
   PROPERTY GET Parent <8> ( _                          ' VTable offset = 56
   ) AS ISpeechPhraseProperty                           ' __retval_out ISpeechPhraseProperty** ParentProperty
   ' =====================================================================================
   PROPERTY GET Children <9> ( _                        ' VTable offset = 60
   ) AS ISpeechPhraseProperties                         ' __retval_out ISpeechPhraseProperties** Children
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseProperty_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseProperties
' IID = {08166B47-102E-4B23-A599-BDB98DBFD1F4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseProperties_INTERFACE_DEFINED)
    %ISpeechPhraseProperties_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseProperties $IID_ISpeechPhraseProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechPhraseProperty                           ' __retval_out ISpeechPhraseProperty** Property
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseRule
' IID = {A7BFE112-A4A0-48D9-B602-C313843F6964}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseRule_INTERFACE_DEFINED)
    %ISpeechPhraseRule_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseRule $IID_ISpeechPhraseRule

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* Name
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Id
   ' =====================================================================================
   PROPERTY GET FirstElement <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* FirstElement
   ' =====================================================================================
   PROPERTY GET NumberOfElements <4> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* NumberOfElements
   ' =====================================================================================
   PROPERTY GET Parent <5> ( _                          ' VTable offset = 44
   ) AS ISpeechPhraseRule                               ' __retval_out ISpeechPhraseRule** Parent
   ' =====================================================================================
   PROPERTY GET Children <6> ( _                        ' VTable offset = 48
   ) AS ISpeechPhraseRules                              ' __retval_out ISpeechPhraseRules** Children
   ' =====================================================================================
   PROPERTY GET Confidence <7> ( _                      ' VTable offset = 52
   ) AS LONG                                            ' __retval_out SpeechEngineConfidence* ActualConfidence
   ' =====================================================================================
   PROPERTY GET EngineConfidence <8> ( _                ' VTable offset = 56
   ) AS SINGLE                                          ' __retval_out float* EngineConfidence
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseRule_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseRules
' IID = {9047D593-01DD-4B72-81A3-E4A0CA69F407}
' ISpeechPhraseRules Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseRules_INTERFACE_DEFINED)
    %ISpeechPhraseRules_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseRules $IID_ISpeechPhraseRules

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechPhraseRule                               ' __retval_out ISpeechPhraseRule** Rule
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseRules_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechLexicon
' IID = {3DA7627A-C7AE-4B23-8708-638C50362C25}
' ISpeechLexicon Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechLexicon_INTERFACE_DEFINED)
    %ISpeechLexicon_INTERFACE_DEFINED = 1


INTERFACE ISpeechLexicon $IID_ISpeechLexicon

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET GenerationId <1> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* GenerationId
   ' =====================================================================================
   METHOD GetWords <2> ( _                              ' VTable offset = 32
     OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechLexiconType Flags = 3
   , OPTIONAL BYREF GenerationId AS LONG _              ' __opt_out long* GenerationId = 0
   ) AS ISpeechLexiconWords                             ' __retval_out ISpeechLexiconWords** Words
   ' =====================================================================================
   METHOD AddPronunciation <3> ( _                      ' VTable offset = 36
     BYVAL bstrWord AS WSTRING _                        ' __in BSTR bstrWord
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , OPTIONAL BYVAL PartOfSpeech AS LONG _              ' __opt_in SpeechPartOfSpeech PartOfSpeech = 0
   , OPTIONAL BYVAL bstrPronunciation AS WSTRING _      ' __opt_in BSTR bstrPronunciation = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPronunciationByPhoneIds <4> ( _            ' VTable offset = 40
     BYVAL bstrWord AS WSTRING _                        ' __in BSTR bstrWord
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , OPTIONAL BYVAL PartOfSpeech AS LONG _              ' __opt_in SpeechPartOfSpeech PartOfSpeech = 0
   , OPTIONAL BYREF VARIANT _                           ' __opt_in VARIANT* PhoneIds = ""
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePronunciation <5> ( _                   ' VTable offset = 44
     BYVAL bstrWord AS WSTRING _                        ' __in BSTR bstrWord
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , OPTIONAL BYVAL PartOfSpeech AS LONG _              ' __opt_in SpeechPartOfSpeech PartOfSpeech= 0
   , OPTIONAL BYVAL bstrPronunciation AS WSTRING _      ' __opt_in BSTR bstrPronunciation = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePronunciationByPhoneIds <6> ( _         ' VTable offset = 48
     BYVAL bstrWord AS WSTRING _                        ' __in BSTR bstrWord
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , OPTIONAL BYVAL PartOfSpeech AS LONG _              ' __opt_in SpeechPartOfSpeech PartOfSpeech= 0
   , OPTIONAL BYREF PhoneIds AS VARIANT _               ' __opt_in VARIANT* PhoneIds = ""
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPronunciations <7> ( _                     ' VTable offset = 52
     BYVAL bstrWord AS WSTRING _                        ' __in BSTR bstrWord
   , OPTIONAL BYVAL LangId AS LONG _                    ' __opt_in long LangId = 0
   , OPTIONAL BYVAL TypeFlags AS LONG _                 ' __opt_in SpeechLexiconType TypeFlags = 3
   ) AS ISpeechLexiconPronunciations                    ' __retval_out ISpeechLexiconPronunciations** ppPronunciations
   ' =====================================================================================
   METHOD GetGenerationChange <8> ( _                   ' VTable offset = 56
     BYREF GenerationId AS LONG _                       ' __in_out long* GenerationId
   ) AS ISpeechLexiconWords                             ' __retval_out ISpeechLexiconWords** ppWords
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechLexicon_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechLexiconWords
' IID = {8D199862-415E-47D5-AC4F-FAA608B424E6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechLexiconWords_INTERFACE_DEFINED)
    %ISpeechLexiconWords_INTERFACE_DEFINED = 1

INTERFACE ISpeechLexiconWords $IID_ISpeechLexiconWords

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechLexiconWord                              ' __retval_out ISpeechLexiconWord** Word
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechLexiconWords_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechLexiconWord
' IID = {4E5B933C-C9BE-48ED-8842-1EE51BB1D4FF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechLexiconWord_INTERFACE_DEFINED)
    %ISpeechLexiconWord_INTERFACE_DEFINED = 1

INTERFACE ISpeechLexiconWord $IID_ISpeechLexiconWord

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LangId <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* LangId
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out SpeechWordType* WordType
   ' =====================================================================================
   PROPERTY GET Word <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* Word
   ' =====================================================================================
   PROPERTY GET Pronunciations <4> ( _                  ' VTable offset = 40
   ) AS ISpeechLexiconPronunciations                    ' __retval_out ISpeechLexiconPronunciations** Pronunciations
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechLexiconWord_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechLexiconPronunciations
' IID = {72829128-5682-4704-A0D4-3E2BB6F2EAD3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechLexiconPronunciations_INTERFACE_DEFINED)
    %ISpeechLexiconPronunciations_INTERFACE_DEFINED = 1

INTERFACE ISpeechLexiconPronunciations $IID_ISpeechLexiconPronunciations

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS ISpeechLexiconPronunciation                     ' __retval_out ISpeechLexiconPronunciation** Pronunciation
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** EnumVARIANT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechLexiconPronunciations_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechLexiconPronunciation
' IID = {95252C5D-9E43-4F4A-9899-48EE73352F9F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechLexiconPronunciation_INTERFACE_DEFINED)
    %ISpeechLexiconPronunciation_INTERFACE_DEFINED = 1

INTERFACE ISpeechLexiconPronunciation $IID_ISpeechLexiconPronunciation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out SpeechLexiconType* LexiconType
   ' =====================================================================================
   PROPERTY GET LangId <2> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* LangId
   ' =====================================================================================
   PROPERTY GET PartOfSpeech <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out SpeechPartOfSpeech* PartOfSpeech
   ' =====================================================================================
   PROPERTY GET PhoneIds <4> ( _                        ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT* PhoneIds
   ' =====================================================================================
   PROPERTY GET Symbolic <5> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* Symbolic
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechLexiconPronunciation_INTERFACE_DEFINED__ */



' IID: {E58442E4-0C80-402C-9559-867337A39765}

#IF NOT %DEF(%SpeechStringConstants_MODULE_DEFINED)
    %SpeechStringConstants_MODULE_DEFINED = 1

$$SpeechRegistryUserRoot                  = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech"$$
$$SpeechRegistryLocalMachineRoot          = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech"$$
$$SpeechCategoryAudioOut                  = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput"$$
$$SpeechCategoryAudioIn                   = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput"$$
$$SpeechCategoryVoices                    = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices"$$
$$SpeechCategoryRecognizers               = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers"$$
$$SpeechCategoryAppLexicons               = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons"$$
$$SpeechCategoryPhoneConverters           = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters"$$
$$SpeechCategoryRecoProfiles              = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles"$$
$$SpeechTokenIdUserLexicon                = "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon"$$
$$SpeechTokenValueCLSID                   = "CLSID"$$
$$SpeechTokenKeyFiles                     = "Files"$$
$$SpeechTokenKeyUI                        = "UI"$$
$$SpeechTokenKeyAttributes                = "Attributes"$$
$$SpeechVoiceCategoryTTSRate              = "DefaultTTSRate"$$
$$SpeechPropertyResourceUsage             = "ResourceUsage"$$
$$SpeechPropertyHighConfidenceThreshold   = "HighConfidenceThreshold"$$
$$SpeechPropertyNormalConfidenceThreshold = "NormalConfidenceThreshold"$$
$$SpeechPropertyLowConfidenceThreshold    = "LowConfidenceThreshold"$$
$$SpeechPropertyResponseSpeed             = "ResponseSpeed"$$
$$SpeechPropertyComplexResponseSpeed      = "ComplexResponseSpeed"$$
$$SpeechPropertyAdaptationOn              = "AdaptationOn"$$
$$SpeechDictationTopicSpelling            = "Spelling"$$
$$SpeechGrammarTagWildcard                = "..."$$
$$SpeechGrammarTagDictation               = "*"$$
$$SpeechGrammarTagUnlimitedDictation      = "*+"$$
$$SpeechEngineProperties                  = "EngineProperties"$$
$$SpeechAddRemoveWord                     = "AddRemoveWord"$$
$$SpeechUserTraining                      = "UserTraining"$$
$$SpeechMicTraining                       = "MicTraining"$$
$$SpeechRecoProfileProperties             = "RecoProfileProperties"$$
$$SpeechAudioProperties                   = "AudioProperties"$$
$$SpeechAudioVolume                       = "AudioVolume"$$
$$SpeechVoiceSkipTypeSentence             = "Sentence"$$
$$SpeechAudioFormatGUIDWave               = "{C31ADBAE-527F-4ff5-A230-F62BB61FF70C}"$$
$$SpeechAudioFormatGUIDText               = "{7CEEF9F9-3D13-11d2-9EE7-00C04F797396}"$$

#ENDIF   ' /* __SpeechStringConstants_MODULE_DEFINED__ */


' IID: {F3E092B2-6BDC-410F-BCB2-4C5ED4424180}
#IF NOT %DEF(%SpeechConstants_MODULE_DEFINED)
    %SpeechConstants_MODULE_DEFINED = 1

%Speech_Default_Weight     = %DEFAULT_WEIGHT
%Speech_Max_Word_Length    = %SP_MAX_WORD_LENGTH
%Speech_Max_Pron_Length    = %SP_MAX_PRON_LENGTH
%Speech_StreamPos_Asap     = %SP_STREAMPOS_ASAP
%Speech_StreamPos_RealTime = %SP_STREAMPOS_REALTIME
%SpeechAllElements         = %SPPR_ALL_ELEMENTS

#ENDIF   ' /* __SpeechConstants_MODULE_DEFINED__ */

' ########################################################################################
' Interface name = ISpeechXMLRecoResult
' IID = AAEC54AF-8F85-4924-944D-B79D39D72E19
' Inherited interface = ISpeechRecoResult
' ########################################################################################

#IF NOT %DEF(%ISpeechXMLRecoResult_INTERFACE_DEFINED)
    %ISpeechXMLRecoResult_INTERFACE_DEFINED = 1

INTERFACE ISpeechXMLRecoResult $IID_ISpeechXMLRecoResult

   INHERIT IDispatch

   ' =====================================================================================
   ' ISpeechRecoResult Methods
   ' =====================================================================================
   PROPERTY GET RecoContext <1> ( _                     ' VTable offset = 28
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext** RecoContext
   ' =====================================================================================
   PROPERTY GET Times <2> ( _                           ' VTable offset = 32
   ) AS ISpeechRecoResultTimes                          ' __retval_out ISpeechRecoResultTimes** Times
   ' =====================================================================================
   PROPERTY SET putref_AudioFormat <3> ( _              ' VTable offset = 36
     BYVAL Format AS ISpeechAudioFormat _               ' __in ISpeechAudioFormat* Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioFormat <3> ( _                     ' VTable offset = 40
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat** Format
   ' =====================================================================================
   PROPERTY GET PhraseInfo <4> ( _                      ' VTable offset = 44
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo** PhraseInfo
   ' =====================================================================================
   METHOD Alternates <5> ( _                            ' VTable offset = 48
     BYVAL RequestCount AS LONG _                       ' __in long RequestCount
   , OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechPhraseAlternates                         ' __retval_out ISpeechPhraseAlternates** Alternates
   ' =====================================================================================
   METHOD Audio <6> ( _                                 ' VTable offset = 52
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   ) AS ISpeechMemoryStream                             ' __retval_out ISpeechMemoryStream** Stream
   ' =====================================================================================
   METHOD SpeakAudio <7> ( _                            ' VTable offset = 56
     OPTIONAL BYVAL StartElement AS LONG _              ' __opt_in long StartElement = 0
   , OPTIONAL BYVAL Elements AS LONG _                  ' __opt_in long Elements = -1
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in SpeechVoiceSpeakFlags Flags = 0
   ) AS LONG                                            ' __retval_out long* StreamNumber
   ' =====================================================================================
   METHOD SaveToMemory <8> ( _                          ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT* ResultBlock
   ' =====================================================================================
   METHOD DiscardResultInfo <9> ( _                     ' VTable offset = 64
     BYVAL ValueTypes AS LONG _                         ' __in SpeechDiscardType ValueTypes
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISpeechXMLRecoResult Methods
   ' =====================================================================================
   METHOD GetXMLResult <10> ( _                         ' VTable offset = 68
     BYVAL Options AS LONG _                            ' __in SPXMLRESULTOPTIONS Options
   ) AS WSTRING                                         ' __retval_out BSTR *pResult
   ' =====================================================================================
   METHOD GetXMLErrorInfo <11> ( _                      ' VTable offset = 72
     BYREF LineNumber AS LONG _                         ' __out long *LineNumber
   , BYREF ScriptLine AS WSTRING _                      ' __out BSTR *ScriptLine
   , BYREF Source AS WSTRING _                          ' __out BSTR *Source
   , BYREF Description AS WSTRING _                     ' __out BSTR *Description
   , BYREF ResultCode AS LONG _                         ' __out long *ResultCode
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsError
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechXMLRecoResult_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpeechRecoResultDispatch
' IID = 6D60EB64-ACED-40A6-BBF3-4E557F71DEE2
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechRecoResultDispatch_INTERFACE_DEFINED)
    %ISpeechRecoResultDispatch_INTERFACE_DEFINED = 1

INTERFACE ISpeechRecoResultDispatch $IID_ISpeechRecoResultDispatch

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RecoContext <1> ( _                     ' VTable offset = 28
   ) AS ISpeechRecoContext                              ' __retval_out ISpeechRecoContext **RecoContext
   ' =====================================================================================
   PROPERTY GET Times <2> ( _                           ' VTable offset = 32
   ) AS ISpeechRecoResultTimes                          ' __retval_out ISpeechRecoResultTimes **Times
   ' =====================================================================================
   PROPERTY SET putref_AudioFormat <3> ( _              ' VTable offset = 36
     BYVAL Format AS ISpeechAudioFormat _               ' __in ISpeechAudioFormat *Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioFormat <3> ( _                     ' VTable offset = 40
   ) AS ISpeechAudioFormat                              ' __retval_out ISpeechAudioFormat **Format
   ' =====================================================================================
   PROPERTY GET PhraseInfo <4> ( _                      ' VTable offset = 44
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo **PhraseInfo
   ' =====================================================================================
   METHOD Alternates <5> ( _                            ' VTable offset = 48
     BYVAL RequestCount AS LONG _                       ' __in long RequestCount
   , BYVAL StartElement AS LONG _                       ' __in long StartElement
   , BYVAL Elements AS LONG _                           ' __in long Elements
   ) AS ISpeechPhraseAlternates                         ' __retval_out ISpeechPhraseAlternates **Alternates
   ' =====================================================================================
   METHOD Audio <6> ( _                                 ' VTable offset = 52
     BYVAL StartElement AS LONG _                       ' __in long StartElement
   , BYVAL Elements AS LONG _                           ' __in long Elements
   ) AS ISpeechMemoryStream                             ' __retval_out ISpeechMemoryStream **Stream
   ' =====================================================================================
   METHOD SpeakAudio <7> ( _                            ' VTable offset = 56
     BYVAL StartElement AS LONG _                       ' __in long StartElement
   , BYVAL Elements AS LONG _                           ' __in long Elements
   , BYVAL Flags AS DWORD _                             ' __in SpeechVoiceSpeakFlags Flags
   ) AS LONG                                            ' __retval_out long *StreamNumber
   ' =====================================================================================
   METHOD SaveToMemory <8> ( _                          ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *ResultBlock
   ' =====================================================================================
   METHOD DiscardResultInfo <9> ( _                     ' VTable offset = 64
     BYVAL ValueTypes AS LONG _                         ' __in SpeechDiscardType ValueTypes
   )                                                    '  void
   ' =====================================================================================
   METHOD GetXMLResult <10> ( _                         ' VTable offset = 68
     BYVAL Options AS LONG _                            ' __in SPXMLRESULTOPTIONS Options
   ) AS WSTRING                                         ' __retval_out BSTR *pResult
   ' =====================================================================================
   METHOD GetXMLErrorInfo <11> ( _                      ' VTable offset = 72
     BYREF LineNumber AS LONG _                         ' __out long *LineNumber
   , BYREF ScriptLine AS WSTRING _                      ' __out BSTR *ScriptLine
   , BYREF Source AS WSTRING _                          ' __out BSTR *Source
   , BYREF Description AS WSTRING _                     ' __out BSTR *Description
   , BYREF ResultCode AS LONG _                         ' __out HRESULT *ResultCode
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsError
   ' =====================================================================================
   METHOD SetTextFeedback <12> ( _                      ' VTable offset = 76
     BYVAL Feedback AS WSTRING _                        ' __in BSTR Feedback
   , BYVAL WasSuccessful AS INTEGER _                   ' __in VARIANT_BOOL WasSuccessful
   )                                                    '  void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechRecoResultDispatch_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhraseInfoBuilder
' IID = {3B151836-DF3A-4E0A-846C-D2ADC9334333}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhraseInfoBuilder_INTERFACE_DEFINED)
    %ISpeechPhraseInfoBuilder_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhraseInfoBuilder $IID_ISpeechPhraseInfoBuilder

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RestorePhraseFromMemory <1> ( _               ' VTable offset = 28
     BYREF PhraseInMemory AS VARIANT _                  ' __in VARIANT* PhraseInMemory
   ) AS ISpeechPhraseInfo                               ' __retval_out ISpeechPhraseInfo** PhraseInfo
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISpeechPhoneConverter
' IID = {C3E4F353-433F-43D6-89A1-6A62A7054C3D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISpeechPhoneConverter_INTERFACE_DEFINED)
    %ISpeechPhoneConverter_INTERFACE_DEFINED = 1

INTERFACE ISpeechPhoneConverter $IID_ISpeechPhoneConverter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LanguageId <1> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* LanguageId
   ' =====================================================================================
   PROPERTY SET LanguageId <1> ( _                      ' VTable offset = 32
     BYVAL LanguageId AS LONG _                         ' __in long LanguageId
   )                                                    ' void
   ' =====================================================================================
   METHOD PhoneToId <2> ( _                             ' VTable offset = 36
     BYVAL Phonemes AS WSTRING _                        ' __in BSTR Phonemes
   ) AS VARIANT                                         ' __retval_out VARIANT* IdArray
   ' =====================================================================================
   METHOD IdToPhone <3> ( _                             ' VTable offset = 40
     BYVAL IdArray AS VARIANT _                         ' __in VARIANT IdArray
   ) AS WSTRING                                         ' __retval_out BSTR* Phonemes
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpeechPhoneConverter_INTERFACE_DEFINED__ */

#ENDIF   ' #IF NOT %DEF(%SpeechLib_LIBRARY_DEFINED)

' ########################################################################################
' Class CISpeechVoiceEvents
' Interface name = _ISpeechVoiceEvents
' IID = {A372ACD1-3BEF-4BBD-8FFB-CB3E2B416AF8}
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CISpeechVoiceEvents GUID$("{505F4104-7159-401D-BBE2-3CCBADD34BA8}") AS EVENT

'INTERFACE ISpeechVoiceEventsImpl GUID$("{A372ACD1-3BEF-4BBD-8FFB-CB3E2B416AF8}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD StartStream <1> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EndStream <2> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long  StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD VoiceChange <3> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL VoiceObjectToken AS ISpeechObjectToken _     ' __in ISpeechObjectToken *VoiceObjectToken
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Bookmark <4> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Bookmark AS WSTRING _                        ' __in BSTR Bookmark
'   , BYVAL BookmarkId AS LONG _                         ' __in long BookmarkId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Word <5> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL CharacterPosition AS LONG _                  ' __in long CharacterPosition
'   , BYVAL Length AS LONG _                             ' __in long Length
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Sentence <7> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL CharacterPosition AS LONG _                  ' __in long CharacterPosition
'   , BYVAL Length AS LONG _                             ' __in long Length
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Phoneme <6> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Duration AS LONG _                           ' __in long Duration
'   , BYVAL NextPhoneId AS INTEGER _                     ' __in short NextPhoneId
'   , BYVAL Feature AS LONG _                            ' __in SpeechVisemeFeature Feature
'   , BYVAL CurrentPhoneId AS INTEGER _                  ' __in short CurrentPhoneId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Viseme <8> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Duration AS LONG _                           ' __in long Duration
'   , BYVAL NextVisemeId AS LONG _                       ' __in SpeechVisemeType NextVisemeId
'   , BYVAL Feature AS LONG _                            ' __in SpeechVisemeFeature Feature
'   , BYVAL CurrentVisemeId AS LONG _                    ' __in SpeechVisemeType CurrentVisemeId
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AudioLevel <9> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL AudioLevel AS LONG _                         ' __in long AudioLevel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EnginePrivate <10> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS LONG _                     ' __in long StreamPosition
'   , BYVAL EngineData AS VARIANT _                      ' __in VARIANT EngineData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CISpeechRecoContextEvents
' Interface name = _ISpeechRecoContextEvents
' IID = {7B8FCB42-0E9D-4F00-A048-7B04D6179D3D}
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CISpeechRecoContextEvents GUID$("{E1221561-3429-4A4B-A055-B00BBD98A2FC}") AS EVENT

'INTERFACE ISpeechRecoContextEventsImpl GUID$("{7B8FCB42-0E9D-4F00-A048-7B04D6179D3D}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD StartStream <1> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EndStream <2> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL StreamReleased AS INTEGER _                  ' __in VARIANT_BOOL StreamReleased
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Bookmark <3> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL BookmarkId AS VARIANT _                      ' __in VARIANT BookmarkId
'   , BYVAL Options AS LONG _                            ' __in SpeechBookmarkOptions Options
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SoundStart <4> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SoundEnd <5> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PhraseStart <6> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Recognition <7> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL RecognitionType AS LONG _                    ' __in SpeechRecognitionType RecognitionType
'   , BYVAL Result AS ISpeechRecoResult _                ' __in ISpeechRecoResult *Result
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Hypothesis <8> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Result AS ISpeechRecoResult _                ' __in ISpeechRecoResult *Result
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PropertyNumberChange <9> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
'   , BYVAL NewNumberValue AS LONG _                     ' __in long NewNumberValue
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PropertyStringChange <10> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
'   , BYVAL NewStringValue AS WSTRING _                  ' __in BSTR NewStringValue
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FalseRecognition <11> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Result AS ISpeechRecoResult _                ' __in ISpeechRecoResult *Result
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Interference <12> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL Interference AS LONG _                       ' __in SpeechInterference Interference
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RequestUI <13> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL UIType AS WSTRING _                          ' __in BSTR UIType
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecognizerStateChange <14> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL NewState AS LONG _                           ' __in SpeechRecognizerState NewState
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Adaptation <15> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD RecognitionForOtherContext <16> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AudioLevel <17> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL AudioLevel AS LONG _                         ' __in long AudioLevel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD EnginePrivate <18> ( _
'     BYVAL StreamNumber AS LONG _                       ' __in long StreamNumber
'   , BYVAL StreamPosition AS VARIANT _                  ' __in VARIANT StreamPosition
'   , BYVAL EngineData AS VARIANT _                      ' __in VARIANT EngineData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

'#elif _SAPI_VER >= 0x053
'#include "sapi53.h"
'#else // _SAPI_VER < 0x053
'#include "sapi51.h"
'#endif  // _SAPI_VER >= 0x054


' ########################################################################################
'                           H E L P E R    F U N C T I O N S
' ########################################################################################

' ========================================================================================
' SpGetUserDefaultUILanguage
' ========================================================================================
'   Description:
'       Returns the default user interface language, using a method
'       appropriate to the platform (Windows 9x, Windows NT, or Windows 2000)
'   Returns:
'       Default UI language
' ========================================================================================
FUNCTION SpGetUserDefaultUILanguage () AS WORD

   LOCAL hr AS LONG
   LOCAL wUILang AS WORD
   LOCAL Osv AS OSVERSIONINFO
#IF %DEF(%UNICODE)
   LOCAL szData AS WSTRINGZ * 32
#ELSE
   LOCAL szData AS ASCIIZ * 32
#ENDIF
   LOCAL dwSize AS DWORD
   LOCAL hKey AS DWORD

   hr = %S_OK

   Osv.dwOSVersionInfoSize = SIZEOF(Osv)
   IF GetVersionEx(Osv) = 0 THEN
      hr = GetLastError()
      ' // Get the UI language by one of three methods, depending on the system
   ELSEIF Osv.dwPlatformId <> %VER_PLATFORM_WIN32_NT THEN
      ' // Case 1: Running on Windows 9x. Get the system UI language from registry:
      dwSize = SIZEOF(szData)
      hr = RegOpenKeyEx(%HKEY_USERS, ".Default\Control Panel\desktop\ResourceLocale", _
             0, %KEY_READ, hKey)
      IF hr = %ERROR_SUCCESS THEN
         hr = RegQueryValueEx(hKey, "", BYVAL %NULL, BYVAL %NULL, szData, dwSize)
         RegCloseKey hKey
         IF hr = %ERROR_SUCCESS THEN
            ' // Convert string to number
            wUILang = VAL("&H" & szData)
         END IF
      END IF
   ELSEIF Osv.dwMajorVersion >= 5.0 THEN
      ' // Case 2: Running on Windows 2000 or later. Use GetUserDefaultUILanguage to find
      ' // the user's prefered UI language
      wUILang = GetUserDefaultUILanguage()
   ELSE
      ' // Case 3: Running on Windows NT 4.0 or earlier. Get UI language
      ' // from locale of .default user in registry:
      ' // HKEY_USERS\.DEFAULT\Control Panel\International\Locale
      dwSize = SIZEOF(szData)
      hr = RegOpenKeyEx(%HKEY_USERS, ".DEFAULT\Control Panel\International", _
             0, %KEY_READ, hKey)
      IF hr = %ERROR_SUCCESS THEN
         hr = RegQueryValueEx(hKey, "Locale", BYVAL %NULL, BYVAL %NULL, szData, dwSize)
         RegCloseKey hKey
         IF hr = %ERROR_SUCCESS THEN
            ' // Convert string to number
            wUILang = VAL("&H" & szData)
            IF wUILang = &H0401 OR _  ' // Arabic
               wUILang = &H040d OR _  ' // Hebrew
               wUILang = &H041e THEN  ' // Thai
               ' // Special case these to the English UI.
               ' // These versions of Windows NT 4.0 were enabled only, i.e., the
               ' // UI was English. However, the registry setting
               ' // HKEY_USERS\.DEFAULT\Control Panel\International\Locale was set
               ' // to the respective locale for application compatibility.
               wUILang = MAKELANGID(%LANG_ENGLISH, %SUBLANG_ENGLISH_US)
            END IF
         END IF
      END IF
   END IF

   ' // In failure case, try our best!
   IF wUILang = 0 THEN wUILang = GetUserDefaultUILanguage()

   FUNCTION = wUILang

END FUNCTION
' ========================================================================================

' ========================================================================================
' SpGetDescription
' Passes back the textual description associated with the specified token.
' ========================================================================================
FUNCTION SpGetDescription ( _
   BYVAL pObjToken AS ISpObjectToken, _       ' *ISpObjectToken
   BYREF ppszDescription AS DWORD _           ' **WCHAR
   ) AS LONG                                  ' HRESULT

   LOCAL hr AS LONG
   LOCAL wszLangId AS WSTRINGZ * 10

   IF ISFALSE ISOBJECT(pObjToken) THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF VARPTR(ppszDescription) = %NULL THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   wszLangId = HEX$(SpGetUserDefaultUILanguage, 4)
   hr = pObjToken.GetStringValue(wszLangId, ppszDescription)
   IF hr = %SPERR_NOT_FOUND THEN
      hr = pObjToken.GetStringValue(BYVAL %NULL, ppszDescription)
   END IF
   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' SpGetCategoryFromId
' Auxiliar function used by other functions.
' ========================================================================================
FUNCTION SpGetCategoryFromId ( _
   BYREF pszCategoryId AS WSTRINGZ, _             ' *const WCHAR
   BYREF ppCategory AS ISpObjectTokenCategory, _  ' **ISpObjectTokenCategory
   OPTIONAL BYVAL fCreateIfNotExist AS LONG _     ' BOOL
   ) AS LONG                                      ' HRESULT

   LOCAL hr AS LONG

   IF VARPTR(ppCategory) = %NULL THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   ppCategory = NEWCOM CLSID $CLSID_SpObjectTokenCategory
   IF ISNOTHING(ppCategory) THEN FUNCTION = %E_NOINTERFACE : EXIT FUNCTION
   hr = ppCategory.SetId(pszCategoryId, fCreateIfNotExist)

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' SpEnumTokens
' Enumerates the tokens for the specified category.
' ========================================================================================
FUNCTION SpEnumTokens ( _
   BYREF pszCategoryId AS WSTRINGZ, _        ' *const WCHAR
   BYREF pszReqAttribs AS WSTRINGZ, _        ' *const WCHAR
   BYREF pszOptAttribs AS WSTRINGZ, _        ' *const WCHAR
   BYREF ppEnum AS IEnumSpObjectTokens _     ' **IEnumSpObjectTokens
   ) AS LONG                                 ' HRESULT

   LOCAL hr AS LONG
   LOCAL pCategory AS ISpObjectTokenCategory

   IF VARPTR(ppEnum) = %NULL THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   hr = SpGetCategoryFromId(pszCategoryId, pCategory)
   IF SUCCEEDED(hr) THEN
      hr = pCategory.EnumTokens(pszReqAttribs, pszOptAttribs, ppEnum)
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' SpSetVoice
' Sets the voice used by the speech engine.
' ========================================================================================
FUNCTION SpSetVoice ( _
   BYVAL pISpVoice AS ISpVoice, _         ' Reference to the IspVoice interface
   BYVAL bstrVoice AS WSTRING _           ' Voice to set, e.g. "Microsoft Mary"
   ) AS LONG                              ' HRESULT

   LOCAL hr AS LONG
   LOCAL pIEnumSpObjectTokens AS IEnumSpObjectTokens
   LOCAL nCount AS DWORD
   LOCAL i AS DWORD
   LOCAL pISpObjectToken AS ISpObjectToken
   LOCAL celtFetched AS DWORD
   LOCAL pszValue AS WSTRINGZ PTR
   LOCAL bstrDesc AS WSTRING

   IF ISNOTHING(pISpVoice) THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   ' // Get a reference to an enumerator for the voices collection
   ' // using the helper function SpEnumTokens
   hr = SpEnumTokens($$SPCAT_VOICES, BYVAL %NULL, BYVAL %NULL, pIEnumSpObjectTokens)
   ' // Parse the collection
   IF SUCCEEDED(hr) THEN
      pIEnumSpObjectTokens.GetCount(nCount)
      FOR i = 0 TO nCount - 1
         hr = pIEnumSpObjectTokens.Next(1, pISpObjectToken, celtFetched)
         IF FAILED(hr) OR celtFetched = 0 THEN EXIT FOR
         hr = SpGetDescription(pISpObjectToken, pszValue)
         IF hr = %S_OK AND pszValue <> %NULL THEN
            bstrDesc = @pszValue
            CoTaskMemFree BYVAL pszValue
            IF UCASE$(bstrDesc) = UCASE$(bstrVoice) THEN
               pISpVoice.SetVoice pISpObjectToken
               pISpObjectToken = NOTHING
               EXIT FOR
            END IF
         END IF
         pISpObjectToken = NOTHING
      NEXT
      pIEnumSpObjectTokens = NOTHING
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Initiates the speaking of a text string.
' - wcs = The text to be spoken, or the path to a text file, or the url of a web page, or
'         the path to a .wav file, or the path to a .xml file.
' - dwFlags = one or more of the following values values should be combined with a bitwise OR.
' SPF_DEFAULT
'    Specifies that the default settings should be used.  The defaults are:
'        Speak the given text string synchronously
'        Not purge pending speak requests
'        Parse the text as XML only if the first character is a left-angle-bracket (<)
'        Not persist global XML state changes across speak calls
'        Not expand punctuation characters into words.
'    To override this default, use the other flag values given below.
' SPF_ASYNC
'    Specifies that the Speak call should be asynchronous. That is, it will return immediately
'    after the speak request is queued.
' SPF_PURGEBEFORESPEAK
'    Purges all pending speak requests prior to this speak call.
' SPF_IS_FILENAME
'    The string passed to ISpVoice::Speak is a file name, and the file text should be spoken.
' SPF_IS_XML
'    The input text will be parsed for XML markup.
' SPF_IS_NOT_XML
'    The input text will not be parsed for XML markup.
' SPF_PERSIST_XML
'    Global state changes in the XML markup will persist across speak calls.
' SPF_NLP_SPEAK_PUNC
'    Punctuation characters should be expanded into words (e.g. "This is a sentence." would
'    become "This is a sentence period").
' SPF_PARSE_SAPI
'    Force XML parsing As MS SAPI.
' SPF_PARSE_SSML
'    Force XML parsing As W3C SSML.
' SPF_PARSE_AUTODETECT
'    The TTS XML format is auto-detected. This is the default if none of these TTS XML format
'    values are present in the bit-field.
' SPF_NLP_MASK
'    This mask is used to remove the SAPI handled flags before ISpTTSEngine::Speak is called.
'    The only flag which the TTS engine must handle is SPF_NLP_SPEAK_PUNC.
' SPF_PARSE_MASK
'    SPF_PARSE_SAPI|SPF_PARSE_SSML.
' SPF_VOICE_MASK
'    This is an existing 5.1 mask, which has every flag bit set. In version 5.3, it has
'    been extended to contain SPF_PARSE_MASK.
' SPF_UNUSED_FLAGS
'    This mask has every unused bit set.
' Return Value: An object reference to the ISpVoice interface.
' ========================================================================================
FUNCTION SpSpeak (BYVAL wcs AS WSTRING, OPTIONAL BYVAL dwFlags AS DWORD) AS ISpVoice

   LOCAL pISpVoice AS ISpVoice
   LOCAL ulStreamNumber AS DWORD

   ' // Create an instance of the ISpVoice interface
   pISpVoice = NEWCOM CLSID $CLSID_SpVoice
   IF ISNOTHING(pISpVoice) THEN EXIT FUNCTION

   ' // Speak the text
   pISpVoice.Speak(BYVAL STRPTR(wcs), dwFlags, ulStreamNumber)

   FUNCTION = pISpVoice

END FUNCTION
' ========================================================================================
