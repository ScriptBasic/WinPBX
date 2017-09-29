' ########################################################################################
' Microsoft Windows
' File: Tapi3.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TAPI3Lib
' Version: 1.0
' Documentation string: Microsoft TAPI 3.0 Type Library
' Path: C:\WINDOWS\system32\tapi3.dll
' Library GUID: {21D6D480-A88B-11D0-83DD-00AA003CCABD}
' ########################################################################################

#INCLUDE THIS ONCE
%TGAPI3_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {E9225296-C759-11D1-A02B-00C04FB6809F}
$PROGID_DispatchMapperDispatchMapper1 = "DispatchMapper.DispatchMapper.1"
' CLSID = {AC48FFE0-F8C4-11D1-A030-00C04FB6809F}
$PROGID_RequestMakeCallRequestMakeCall1 = "RequestMakeCall.RequestMakeCall.1"
' CLSID = {21D6D48E-A88B-11D0-83DD-00AA003CCABD}
$PROGID_TAPITAPI1 = "TAPI.TAPI.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {E9225296-C759-11D1-A02B-00C04FB6809F}
$PROGID_DispatchMapperDispatchMapper = "DispatchMapper.DispatchMapper"
' CLSID = {AC48FFE0-F8C4-11D1-A030-00C04FB6809F}
$PROGID_RequestMakeCallRequestMakeCall = "RequestMakeCall.RequestMakeCall"
' CLSID = {21D6D48E-A88B-11D0-83DD-00AA003CCABD}
$PROGID_TAPITAPI = "TAPI.TAPI"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DispatchMapper = GUID$("{E9225296-C759-11D1-A02B-00C04FB6809F}")
$CLSID_RequestMakeCall = GUID$("{AC48FFE0-F8C4-11D1-A030-00C04FB6809F}")
$CLSID_TAPI = GUID$("{21D6D48E-A88B-11D0-83DD-00AA003CCABD}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumACDGroup = GUID$("{5AFC3157-4BCC-11D1-BF80-00805FC147D3}")
$IID_IEnumAddress = GUID$("{1666FCA1-9363-11D0-835C-00AA003CCABD}")
$IID_IEnumAgentHandler = GUID$("{587E8C28-9802-11D1-A0A4-00805FC147D3}")
$IID_IEnumAgentSession = GUID$("{5AFC314E-4BCC-11D1-BF80-00805FC147D3}")
$IID_IEnumBstr = GUID$("{35372049-0BC6-11D2-A033-00C04FB6809F}")
$IID_IEnumCall = GUID$("{AE269CF6-935E-11D0-835C-00AA003CCABD}")
$IID_IEnumCallHub = GUID$("{A3C15450-5B92-11D1-8F4E-00C04FB6809F}")
$IID_IEnumCallingCard = GUID$("{0C4D8F02-8DDB-11D1-A09E-00805FC147D3}")
$IID_IEnumLocation = GUID$("{0C4D8F01-8DDB-11D1-A09E-00805FC147D3}")
$IID_IEnumPhone = GUID$("{F15B7669-4780-4595-8C89-FB369C8CF7AA}")
$IID_IEnumPluggableSuperclassInfo = GUID$("{E9586A80-89E6-4CFF-931D-478D5751F4C0}")
$IID_IEnumPluggableTerminalClassInfo = GUID$("{4567450C-DBEE-4E3F-AAF5-37BF9EBF5E29}")
$IID_IEnumQueue = GUID$("{5AFC3158-4BCC-11D1-BF80-00805FC147D3}")
$IID_IEnumStream = GUID$("{EE3BD606-3868-11D2-A045-00C04FB6809F}")
$IID_IEnumSubStream = GUID$("{EE3BD609-3868-11D2-A045-00C04FB6809F}")
$IID_IEnumTerminal = GUID$("{AE269CF4-935E-11D0-835C-00AA003CCABD}")
$IID_IEnumTerminalClass = GUID$("{AE269CF5-935E-11D0-835C-00AA003CCABD}")
$IID_ITACDGroup = GUID$("{5AFC3148-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITACDGroupEvent = GUID$("{297F3032-BD11-11D1-A0A7-00805FC147D3}")
$IID_ITAddress = GUID$("{B1EFC386-9355-11D0-835C-00AA003CCABD}")
$IID_ITAddress2 = GUID$("{B0AE5D9B-BE51-46C9-B0F7-DFA8A22A8BC4}")
$IID_ITAddressCapabilities = GUID$("{8DF232F5-821B-11D1-BB5C-00C04FB6809F}")
$IID_ITAddressDeviceSpecificEvent = GUID$("{3ACB216B-40BD-487A-8672-5CE77BD7E3A3}")
$IID_ITAddressEvent = GUID$("{831CE2D1-83B5-11D1-BB5C-00C04FB6809F}")
$IID_ITAddressTranslation = GUID$("{0C4D8F03-8DDB-11D1-A09E-00805FC147D3}")
$IID_ITAddressTranslationInfo = GUID$("{AFC15945-8D40-11D1-A09E-00805FC147D3}")
$IID_ITAgent = GUID$("{5770ECE5-4B27-11D1-BF80-00805FC147D3}")
$IID_ITAgentEvent = GUID$("{5AFC314A-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITAgentHandler = GUID$("{587E8C22-9802-11D1-A0A4-00805FC147D3}")
$IID_ITAgentHandlerEvent = GUID$("{297F3034-BD11-11D1-A0A7-00805FC147D3}")
$IID_ITAgentSession = GUID$("{5AFC3147-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITAgentSessionEvent = GUID$("{5AFC314B-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITASRTerminalEvent = GUID$("{EE016A02-4FA9-467C-933F-5A15B12377D7}")
$IID_ITAutomatedPhoneControl = GUID$("{1EE1AF0E-6159-4A61-B79B-6A4BA3FC9DFC}")
$IID_ITBasicAudioTerminal = GUID$("{B1EFC38D-9355-11D0-835C-00AA003CCABD}")
$IID_ITBasicCallControl = GUID$("{B1EFC389-9355-11D0-835C-00AA003CCABD}")
$IID_ITBasicCallControl2 = GUID$("{161A4A56-1E99-4B3F-A46A-168F38A5EE4C}")
$IID_ITCallHub = GUID$("{A3C1544E-5B92-11D1-8F4E-00C04FB6809F}")
$IID_ITCallHubEvent = GUID$("{A3C15451-5B92-11D1-8F4E-00C04FB6809F}")
$IID_ITCallInfo = GUID$("{350F85D1-1227-11D3-83D4-00C04FB6809F}")
$IID_ITCallInfo2 = GUID$("{94D70CA6-7AB0-4DAA-81CA-B8F8643FAEC1}")
$IID_ITCallInfoChangeEvent = GUID$("{5D4B65F9-E51C-11D1-A02F-00C04FB6809F}")
$IID_ITCallingCard = GUID$("{0C4D8F00-8DDB-11D1-A09E-00805FC147D3}")
$IID_ITCallMediaEvent = GUID$("{FF36B87F-EC3A-11D0-8EE4-00C04FB6809F}")
$IID_ITCallNotificationEvent = GUID$("{895801DF-3DD6-11D1-8F30-00C04FB6809F}")
$IID_ITCallStateEvent = GUID$("{62F47097-95C9-11D0-835D-00AA003CCABD}")
$IID_ITCollection = GUID$("{5EC5ACF2-9C02-11D0-8362-00AA003CCABD}")
$IID_ITCollection2 = GUID$("{E6DDDDA5-A6D3-48FF-8737-D32FC4D95477}")
$IID_ITCustomTone = GUID$("{357AD764-B3C6-4B2A-8FA5-0722827A9254}")
$IID_ITDetectTone = GUID$("{961F79BD-3097-49DF-A1D6-909B77E89CA0}")
$IID_ITDigitDetectionEvent = GUID$("{80D3BFAC-57D9-11D2-A04A-00C04FB6809F}")
$IID_ITDigitGenerationEvent = GUID$("{80D3BFAD-57D9-11D2-A04A-00C04FB6809F}")
$IID_ITDigitsGatheredEvent = GUID$("{E52EC4C1-CBA3-441A-9E6A-93CB909E9724}")
$IID_ITDispatchMapper = GUID$("{E9225295-C759-11D1-A02B-00C04FB6809F}")
$IID_ITFileTerminalEvent = GUID$("{E4A7FBAC-8C17-4427-9F55-9F589AC8AF00}")
$IID_ITFileTrack = GUID$("{31CA6EA9-C08A-4BEA-8811-8E9C1BA3EA3A}")
$IID_ITForwardInformation = GUID$("{449F659E-88A3-11D1-BB5D-00C04FB6809F}")
$IID_ITForwardInformation2 = GUID$("{5229B4ED-B260-4382-8E1A-5DF3A8A4CCC0}")
$IID_ITLegacyAddressMediaControl = GUID$("{AB493640-4C0B-11D2-A046-00C04FB6809F}")
$IID_ITLegacyAddressMediaControl2 = GUID$("{B0EE512B-A531-409E-9DD9-4099FE86C738}")
$IID_ITLegacyCallMediaControl = GUID$("{D624582F-CC23-4436-B8A5-47C625C8045D}")
$IID_ITLegacyCallMediaControl2 = GUID$("{57CA332D-7BC2-44F1-A60C-936FE8D7CE73}")
$IID_ITLegacyWaveSupport = GUID$("{207823EA-E252-11D2-B77E-0080C7135381}")
$IID_ITLocationInfo = GUID$("{0C4D8EFF-8DDB-11D1-A09E-00805FC147D3}")
$IID_ITMediaControl = GUID$("{C445DDE8-5199-4BC7-9807-5FFB92E42E09}")
$IID_ITMediaPlayback = GUID$("{627E8AE6-AE4C-4A69-BB63-2AD625404B77}")
$IID_ITMediaRecord = GUID$("{F5DD4592-5476-4CC1-9D4D-FAD3EEFE7DB2}")
$IID_ITMediaSupport = GUID$("{B1EFC384-9355-11D0-835C-00AA003CCABD}")
$IID_ITMultiTrackTerminal = GUID$("{FE040091-ADE8-4072-95C9-BF7DE8C54B44}")
$IID_ITPhone = GUID$("{09D48DB4-10CC-4388-9DE7-A8465618975A}")
$IID_ITPhoneDeviceSpecificEvent = GUID$("{63FFB2A6-872B-4CD3-A501-326E8FB40AF7}")
$IID_ITPhoneEvent = GUID$("{8F942DD8-64ED-4AAF-A77D-B23DB0837EAD}")
$IID_ITPluggableTerminalClassInfo = GUID$("{41757F4A-CF09-4B34-BC96-0A79D2390076}")
$IID_ITPluggableTerminalSuperclassInfo = GUID$("{6D54E42C-4625-4359-A6F7-631999107E05}")
$IID_ITPrivateEvent = GUID$("{0E269CD0-10D4-4121-9C22-9C85D625650D}")
$IID_ITQOSEvent = GUID$("{CFA3357C-AD77-11D1-BB68-00C04FB6809F}")
$IID_ITQueue = GUID$("{5AFC3149-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITQueueEvent = GUID$("{297F3033-BD11-11D1-A0A7-00805FC147D3}")
$IID_ITRequest = GUID$("{AC48FFDF-F8C4-11D1-A030-00C04FB6809F}")
$IID_ITRequestEvent = GUID$("{AC48FFDE-F8C4-11D1-A030-00C04FB6809F}")
$IID_ITScriptableAudioFormat = GUID$("{B87658BD-3C59-4F64-BE74-AEDE3E86A81E}")
$IID_ITStaticAudioTerminal = GUID$("{A86B7871-D14C-48E6-922E-A8D15F984800}")
$IID_ITStream = GUID$("{EE3BD605-3868-11D2-A045-00C04FB6809F}")
$IID_ITStreamControl = GUID$("{EE3BD604-3868-11D2-A045-00C04FB6809F}")
$IID_ITSubStream = GUID$("{EE3BD608-3868-11D2-A045-00C04FB6809F}")
$IID_ITSubStreamControl = GUID$("{EE3BD607-3868-11D2-A045-00C04FB6809F}")
$IID_ITTAPI = GUID$("{B1EFC382-9355-11D0-835C-00AA003CCABD}")
$IID_ITTAPI2 = GUID$("{54FBDC8C-D90F-4DAD-9695-B373097F094B}")
$IID_ITTAPICallCenter = GUID$("{5AFC3154-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITTAPIDispatchEventNotification = GUID$("{9F34325B-7E62-11D2-9457-00C04F8EC888}")
$IID_ITTAPIEventNotification = GUID$("{EDDB9426-3B91-11D1-8F30-00C04FB6809F}")
$IID_ITTAPIObjectEvent = GUID$("{F4854D48-937A-11D1-BB58-00C04FB6809F}")
$IID_ITTAPIObjectEvent2 = GUID$("{359DDA6E-68CE-4383-BF0B-169133C41B46}")
$IID_ITTerminal = GUID$("{B1EFC38A-9355-11D0-835C-00AA003CCABD}")
$IID_ITTerminalSupport = GUID$("{B1EFC385-9355-11D0-835C-00AA003CCABD}")
$IID_ITTerminalSupport2 = GUID$("{F3EB39BC-1B1F-4E99-A0C0-56305C4DD591}")
$IID_ITToneDetectionEvent = GUID$("{407E0FAF-D047-4753-B0C6-8E060373FECD}")
$IID_ITToneTerminalEvent = GUID$("{E6F56009-611F-4945-BBD2-2D0CE5612056}")
$IID_ITTTSTerminalEvent = GUID$("{D964788F-95A5-461D-AB0C-B9900A6C2713}")

$IID_IEnumAgent = GUID$("{5AFC314D-4BCC-11D1-BF80-00805FC147D3}")
$IID_ITAMMediaFormat = GUID$("{0364EB00-4A77-11D1-A671-006097C9A2E8}")
$IID_ITAllocatorProperties = GUID$("{C1BC3C90-BCFE-11D1-9745-00C04FD91AC0}")
$IID_ITPluggableTerminalEventSink = GUID$("{6E0887BE-BA1A-492E-BD10-4020EC5E33E0}")
$IID_ITPluggableTerminalEventSinkRegistration = GUID$("{F7115709-A216-4957-A759-060AB32A90D1}")
$IID_ITMSPAddress = GUID$("{EE3BD600-3868-11D2-A045-00C04FB6809F}")

' enum AGENT_EVENT
%AE_NOT_READY     = 0
%AE_READY         = %AE_NOT_READY     + 1
%AE_BUSY_ACD      = %AE_READY         + 1
%AE_BUSY_INCOMING = %AE_BUSY_ACD      + 1
%AE_BUSY_OUTGOING = %AE_BUSY_INCOMING + 1
%AE_UNKNOWN       = %AE_BUSY_OUTGOING + 1

' enum AGENT_STATE
%AS_NOT_READY     = 0
%AS_READY         = %AS_NOT_READY     + 1
%AS_BUSY_ACD      = %AS_READY         + 1
%AS_BUSY_INCOMING = %AS_BUSY_ACD      + 1
%AS_BUSY_OUTGOING = %AS_BUSY_INCOMING + 1
%AS_UNKNOWN       = %AS_BUSY_OUTGOING + 1

' enum AGENT_SESSION_EVENT
%ASE_NEW_SESSION = 0
%ASE_NOT_READY   = %ASE_NEW_SESSION + 1
%ASE_READY       = %ASE_NOT_READY   + 1
%ASE_BUSY        = %ASE_READY       + 1
%ASE_WRAPUP      = %ASE_BUSY        + 1
%ASE_END         = %ASE_WRAPUP      + 1

' enum AGENT_SESSION_STATE
%ASST_NOT_READY     = 0
%ASST_READY         = %ASST_NOT_READY    + 1
%ASST_BUSY_ON_CALL  = %ASST_READY        + 1
%ASST_BUSY_WRAPUP   = %ASST_BUSY_ON_CALL + 1
%ASST_SESSION_ENDED = %ASST_BUSY_WRAPUP  + 1

' enum AGENTHANDLER_EVENT
%AHE_NEW_AGENTHANDLER     = 0
%AHE_AGENTHANDLER_REMOVED = %AHE_NEW_AGENTHANDLER + 1

' enum ACDGROUP_EVENT
%ACDGE_NEW_GROUP     = 0
%ACDGE_GROUP_REMOVED = %ACDGE_NEW_GROUP + 1

' enum ACDQUEUE_EVENT
%ACDQE_NEW_QUEUE     = 0
%ACDQE_QUEUE_REMOVED = %ACDQE_NEW_QUEUE + 1

#INCLUDE ONCE "ole2.inc"
'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "tapi3if.inc"

' ########################################################################################
' Interface name = ITAgent
' IID = {5770ECE5-4B27-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgent_INTERFACE_DEFINED)
    %ITAgent_INTERFACE_DEFINED = 1

INTERFACE ITAgent $IID_ITAgent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EnumerateAgentSessions <1> ( _                ' VTable offset = 28
   ) AS IEnumAgentSession                               ' __retval_out IEnumAgentSession **ppEnumAgentSession
   ' =====================================================================================
   METHOD CreateSession <2> ( _                         ' VTable offset = 32
     BYVAL pACDGroup AS ITACDGroup _                    ' __in ITACDGroup *pACDGroup
   , BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   ) AS ITAgentSession                                  ' __retval_out ITAgentSession **ppAgentSession
   ' =====================================================================================
   METHOD CreateSessionWithPIN <3> ( _                  ' VTable offset = 36
     BYVAL pACDGroup AS ITACDGroup _                    ' __in ITACDGroup *pACDGroup
   , BYVAL pAddress AS ITAddress _                      ' __in ITAddress *pAddress
   , BYVAL pPIN AS WSTRING _                            ' __in BSTR pPIN
   ) AS ITAgentSession                                  ' __retval_out ITAgentSession **ppAgentSession
   ' =====================================================================================
   PROPERTY GET ID <4> ( _                              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *ppID
   ' =====================================================================================
   PROPERTY GET User <5> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *ppUser
   ' =====================================================================================
   PROPERTY SET State <6> ( _                           ' VTable offset = 48
     BYVAL AgentState AS LONG _                         ' __in AGENT_STATE AgentState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <6> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out AGENT_STATE *pAgentState
   ' =====================================================================================
   PROPERTY SET MeasurementPeriod <7> ( _               ' VTable offset = 56
     BYVAL lPeriod AS LONG _                            ' __in long lPeriod
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MeasurementPeriod <7> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plPeriod
   ' =====================================================================================
   PROPERTY GET OverallCallRate <8> ( _                 ' VTable offset = 64
   ) AS CUR                                             ' __retval_out CURRENCY *pcyCallrate
   ' =====================================================================================
   PROPERTY GET NumberOfACDCalls <9> ( _                ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET NumberOfIncomingCalls <10> ( _          ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET NumberOfOutgoingCalls <11> ( _          ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET TotalACDTalkTime <12> ( _               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plTalkTime
   ' =====================================================================================
   PROPERTY GET TotalACDCallTime <13> ( _               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plCallTime
   ' =====================================================================================
   PROPERTY GET TotalWrapUpTime <14> ( _                ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plWrapUpTime
   ' =====================================================================================
   PROPERTY GET AgentSessions <15> ( _                  ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAgentSession
' IID = {5AFC3147-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgentSession_INTERFACE_DEFINED)
    %ITAgentSession_INTERFACE_DEFINED = 1

INTERFACE ITAgentSession $IID_ITAgentSession

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Agent <1> ( _                           ' VTable offset = 28
   ) AS ITAgent                                         ' __retval_out ITAgent **ppAgent
   ' =====================================================================================
   PROPERTY GET Address <2> ( _                         ' VTable offset = 32
   ) AS ITAddress                                       ' __retval_out ITAddress **ppAddress
   ' =====================================================================================
   PROPERTY GET ACDGroup <3> ( _                        ' VTable offset = 36
   ) AS ITACDGroup                                      ' __retval_out ITACDGroup **ppACDGroup
   ' =====================================================================================
   PROPERTY SET State <4> ( _                           ' VTable offset = 40
     BYVAL SessionState AS LONG _                       ' __in AGENT_SESSION_STATE SessionState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <4> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out AGENT_SESSION_STATE *pSessionState
   ' =====================================================================================
   PROPERTY GET SessionStartTime <5> ( _                ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pdateSessionStart
   ' =====================================================================================
   PROPERTY GET SessionDuration <6> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plDuration
   ' =====================================================================================
   PROPERTY GET NumberOfCalls <7> ( _                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET TotalTalkTime <8> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plTalkTime
   ' =====================================================================================
   PROPERTY GET AverageTalkTime <9> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plTalkTime
   ' =====================================================================================
   PROPERTY GET TotalCallTime <10> ( _                  ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plCallTime
   ' =====================================================================================
   PROPERTY GET AverageCallTime <11> ( _                ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plCallTime
   ' =====================================================================================
   PROPERTY GET TotalWrapUpTime <12> ( _                ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plWrapUpTime
   ' =====================================================================================
   PROPERTY GET AverageWrapUpTime <13> ( _              ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plWrapUpTime
   ' =====================================================================================
   PROPERTY GET ACDCallRate <14> ( _                    ' VTable offset = 84
   ) AS CUR                                             ' __retval_out CURRENCY *pcyCallrate
   ' =====================================================================================
   PROPERTY GET LongestTimeToAnswer <15> ( _            ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plAnswerTime
   ' =====================================================================================
   PROPERTY GET AverageTimeToAnswer <16> ( _            ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAnswerTime
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgentSession_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITACDGroup
' IID = {5AFC3148-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITACDGroup_INTERFACE_DEFINED)
    %ITACDGroup_INTERFACE_DEFINED = 1

INTERFACE ITACDGroup $IID_ITACDGroup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   METHOD EnumerateQueues <2> ( _                       ' VTable offset = 32
   ) AS IEnumQueue                                      ' __retval_out IEnumQueue **ppEnumQueue
   ' =====================================================================================
   PROPERTY GET Queues <3> ( _                          ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITACDGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITQueue
' IID = {5AFC3149-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITQueue_INTERFACE_DEFINED)
    %ITQueue_INTERFACE_DEFINED = 1

INTERFACE ITQueue $IID_ITQueue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET MeasurementPeriod <1> ( _               ' VTable offset = 28
     BYVAL lPeriod AS LONG _                            ' __in long lPeriod
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MeasurementPeriod <1> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPeriod
   ' =====================================================================================
   PROPERTY GET TotalCallsQueued <2> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET CurrentCallsQueued <3> ( _              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET TotalCallsAbandoned <4> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET TotalCallsFlowedIn <5> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET TotalCallsFlowedOut <6> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET LongestEverWaitTime <7> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plWaitTime
   ' =====================================================================================
   PROPERTY GET CurrentLongestWaitTime <8> ( _          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plWaitTime
   ' =====================================================================================
   PROPERTY GET AverageWaitTime <9> ( _                 ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plWaitTime
   ' =====================================================================================
   PROPERTY GET FinalDisposition <10> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plCalls
   ' =====================================================================================
   PROPERTY GET Name <11> ( _                           ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITQueue_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAgentEvent
' IID = {5AFC314A-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgentEvent_INTERFACE_DEFINED)
    %ITAgentEvent_INTERFACE_DEFINED = 1

INTERFACE ITAgentEvent $IID_ITAgentEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Agent <1> ( _                           ' VTable offset = 28
   ) AS ITAgent                                         ' __retval_out ITAgent **ppAgent
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out AGENT_EVENT *pEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgentEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAgentSessionEvent
' IID = {5AFC314B-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgentSessionEvent_INTERFACE_DEFINED)
    %ITAgentSessionEvent_INTERFACE_DEFINED = 1

INTERFACE ITAgentSessionEvent $IID_ITAgentSessionEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session <1> ( _                         ' VTable offset = 28
   ) AS ITAgentSession                                  ' __retval_out ITAgentSession **ppSession
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out AGENT_SESSION_EVENT *pEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgentSessionEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITACDGroupEvent
' IID = {297F3032-BD11-11D1-A0A7-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITACDGroupEvent_INTERFACE_DEFINED)
    %ITACDGroupEvent_INTERFACE_DEFINED = 1

INTERFACE ITACDGroupEvent $IID_ITACDGroupEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Group <1> ( _                           ' VTable offset = 28
   ) AS ITACDGroup                                      ' __retval_out ITACDGroup **ppGroup
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ACDGROUP_EVENT *pEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITACDGroupEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITQueueEvent
' IID = {297F3033-BD11-11D1-A0A7-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITQueueEvent_INTERFACE_DEFINED)
    %ITQueueEvent_INTERFACE_DEFINED = 1

INTERFACE ITQueueEvent $IID_ITQueueEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Queue <1> ( _                           ' VTable offset = 28
   ) AS ITQueue                                         ' __retval_out ITQueue **ppQueue
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ACDQUEUE_EVENT *pEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITQueueEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAgentHandlerEvent
' IID = {297F3034-BD11-11D1-A0A7-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgentHandlerEvent_INTERFACE_DEFINED)
    %ITAgentHandlerEvent_INTERFACE_DEFINED = 1

INTERFACE ITAgentHandlerEvent $IID_ITAgentHandlerEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AgentHandler <1> ( _                    ' VTable offset = 28
   ) AS ITAgentHandler                                  ' __retval_out ITAgentHandler **ppAgentHandler
   ' =====================================================================================
   PROPERTY GET Event <2> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out AGENTHANDLER_EVENT *pEvent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgentHandlerEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTAPICallCenter
' IID = {5AFC3154-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITTAPICallCenter_INTERFACE_DEFINED)
    %ITTAPICallCenter_INTERFACE_DEFINED = 1

INTERFACE ITTAPICallCenter $IID_ITTAPICallCenter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EnumerateAgentHandlers <131073> ( _           ' VTable offset = 28
   ) AS IEnumAgentHandler                               ' __retval_out IEnumAgentHandler **ppEnumHandler
   ' =====================================================================================
   PROPERTY GET AgentHandlers <131074> ( _              ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTAPICallCenter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAgentHandler
' IID = {587E8C22-9802-11D1-A0A4-00805FC147D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITAgentHandler_INTERFACE_DEFINED)
    %ITAgentHandler_INTERFACE_DEFINED = 1

INTERFACE ITAgentHandler $IID_ITAgentHandler

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *ppName
   ' =====================================================================================
   METHOD CreateAgent <2> ( _                           ' VTable offset = 32
   ) AS ITAgent                                         ' __retval_out ITAgent **ppAgent
   ' =====================================================================================
   METHOD CreateAgentWithID <3> ( _                     ' VTable offset = 36
     BYVAL pID AS WSTRING _                             ' __in BSTR pID
   , BYVAL pPIN AS WSTRING _                            ' __in BSTR pPIN
   ) AS ITAgent                                         ' __retval_out ITAgent **ppAgent
   ' =====================================================================================
   METHOD EnumerateACDGroups <4> ( _                    ' VTable offset = 40
   ) AS IEnumACDGroup                                   ' __retval_out IEnumACDGroup **ppEnumACDGroup
   ' =====================================================================================
   METHOD EnumerateUsableAddresses <5> ( _              ' VTable offset = 44
   ) AS IEnumAddress                                    ' __retval_out IEnumAddress **ppEnumAddress
   ' =====================================================================================
   PROPERTY GET ACDGroups <6> ( _                       ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   PROPERTY GET UsableAddresses <7> ( _                 ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAgentHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumAgent
' IID = {5AFC314D-4BCC-11D1-BF80-00805FC147D3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAgent_INTERFACE_DEFINED)
    %IEnumAgent_INTERFACE_DEFINED = 1

INTERFACE IEnumAgent $IID_IEnumAgent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITAgent _                      ' __out ITAgent **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS DWORD _                            ' __retval_out IEnumAgent **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAgent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumAgentSession
' IID = {5AFC314E-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAgentSession_INTERFACE_DEFINED)
    %IEnumAgentSession_INTERFACE_DEFINED = 1

INTERFACE IEnumAgentSession $IID_IEnumAgentSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITAgentSession _               ' __out ITAgentSession **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumAgentSession _                ' __retval_out IEnumAgentSession **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAgentSession_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumQueue
' IID = {5AFC3158-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumQueue_INTERFACE_DEFINED)
    %IEnumQueue_INTERFACE_DEFINED = 1

INTERFACE IEnumQueue $IID_IEnumQueue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITQueue _                      ' __out ITQueue **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumQueue _                       ' __retval_out IEnumQueue **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumQueue_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumACDGroup
' IID = {5AFC3157-4BCC-11D1-BF80-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumACDGroup_INTERFACE_DEFINED)
    %IEnumACDGroup_INTERFACE_DEFINED = 1

INTERFACE IEnumACDGroup $IID_IEnumACDGroup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITACDGroup _                   ' __out ITACDGroup **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumACDGroup _                    ' __retval_out IEnumACDGroup **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumACDGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumAgentHandler
' IID = {587E8C28-9802-11D1-A0A4-00805FC147D3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAgentHandler_INTERFACE_DEFINED)
    %IEnumAgentHandler_INTERFACE_DEFINED = 1

INTERFACE IEnumAgentHandler $IID_IEnumAgentHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS ITAgentHandler _               ' __out ITAgentHandler **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumAgentHandler _                ' __retval_out IEnumAgentHandler **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAgentHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAMMediaFormat
' IID = {0364EB00-4A77-11D1-A671-006097C9A2E8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITAMMediaFormat_INTERFACE_DEFINED)
    %ITAMMediaFormat_INTERFACE_DEFINED = 1

INTERFACE ITAMMediaFormat $IID_ITAMMediaFormat

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_MediaFormat ( _                           ' VTable offset = 12
     BYREF ppmt AS AM_MEDIA_TYPE _                      ' __retval_out AM_MEDIA_TYPE **ppmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MediaFormat ( _                           ' VTable offset = 16
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __in const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAMMediaFormat_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITAllocatorProperties
' IID = {C1BC3C90-BCFE-11D1-9745-00C04FD91AC0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITAllocatorProperties_INTERFACE_DEFINED)
    %ITAllocatorProperties_INTERFACE_DEFINED = 1

INTERFACE ITAllocatorProperties $IID_ITAllocatorProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllocatorProperties ( _                    ' VTable offset = 12
     BYREF pAllocProperties AS ALLOCATOR_PROPERTIES _   ' __in ALLOCATOR_PROPERTIES *pAllocProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatorProperties ( _                    ' VTable offset = 16
     BYREF pAllocProperties AS ALLOCATOR_PROPERTIES _   ' __out ALLOCATOR_PROPERTIES *pAllocProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllocateBuffers ( _                        ' VTable offset = 20
     BYVAL bAllocBuffers AS LONG _                      ' __in BOOL bAllocBuffers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocateBuffers ( _                        ' VTable offset = 24
     BYREF pbAllocBuffers AS LONG _                     ' __out BOOL *pbAllocBuffers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferSize ( _                             ' VTable offset = 28
     BYVAL BufferSize AS DWORD _                        ' __in DWORD BufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferSize ( _                             ' VTable offset = 32
     BYREF pBufferSize AS DWORD _                       ' __out DWORD *pBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAllocatorProperties_INTERFACE_DEFINED__ */


'typedef long *MSP_HANDLE;

' enum MSP_ADDRESS_EVENT
%ADDRESS_TERMINAL_AVAILABLE   = 0
%ADDRESS_TERMINAL_UNAVAILABLE = %ADDRESS_TERMINAL_AVAILABLE + 1

' enum MSP_CALL_EVENT
%CALL_NEW_STREAM      = 0
%CALL_STREAM_FAIL     = %CALL_NEW_STREAM      + 1
%CALL_TERMINAL_FAIL   = %CALL_STREAM_FAIL     + 1
%CALL_STREAM_NOT_USED = %CALL_TERMINAL_FAIL   + 1
%CALL_STREAM_ACTIVE   = %CALL_STREAM_NOT_USED + 1
%CALL_STREAM_INACTIVE = %CALL_STREAM_ACTIVE   + 1

' enum MSP_CALL_EVENT_CAUSE
%CALL_CAUSE_UNKNOWN            = 0
%CALL_CAUSE_BAD_DEVICE         = %CALL_CAUSE_UNKNOWN         + 1
%CALL_CAUSE_CONNECT_FAIL       = %CALL_CAUSE_BAD_DEVICE      + 1
%CALL_CAUSE_LOCAL_REQUEST      = %CALL_CAUSE_CONNECT_FAIL    + 1
%CALL_CAUSE_REMOTE_REQUEST     = %CALL_CAUSE_LOCAL_REQUEST   + 1
%CALL_CAUSE_MEDIA_TIMEOUT      = %CALL_CAUSE_REMOTE_REQUEST  + 1
%CALL_CAUSE_MEDIA_RECOVERED    = %CALL_CAUSE_MEDIA_TIMEOUT   + 1
%CALL_CAUSE_QUALITY_OF_SERVICE = %CALL_CAUSE_MEDIA_RECOVERED + 1

' enum MSP_EVENT
%ME_ADDRESS_EVENT       = 0
%ME_CALL_EVENT          = %ME_ADDRESS_EVENT       + 1
%ME_TSP_DATA            = %ME_CALL_EVENT          + 1
%ME_PRIVATE_EVENT       = %ME_TSP_DATA            + 1
%ME_ASR_TERMINAL_EVENT  = %ME_PRIVATE_EVENT       + 1
%ME_TTS_TERMINAL_EVENT  = %ME_ASR_TERMINAL_EVENT  + 1
%ME_FILE_TERMINAL_EVENT = %ME_TTS_TERMINAL_EVENT  + 1
%ME_TONE_TERMINAL_EVENT = %ME_FILE_TERMINAL_EVENT + 1

'typedef /* [public][public] */ struct __MIDL___MIDL_itf_tapi3_0524_0005
'    {
'    DWORD dwSize;
'    MSP_EVENT Event;
'    MSP_HANDLE hCall;
'    /* [switch_is][switch_type] */ union
'        {
'        /* [case()] */ struct
'            {
'            MSP_ADDRESS_EVENT Type;
'            ITTerminal *pTerminal;
'            }    MSP_ADDRESS_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            MSP_CALL_EVENT Type;
'            MSP_CALL_EVENT_CAUSE Cause;
'            ITStream *pStream;
'            ITTerminal *pTerminal;
'            HRESULT hrError;
'            }    MSP_CALL_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            DWORD dwBufferSize;
'            BYTE pBuffer[ 1 ];
'            }    MSP_TSP_DATA;
'        /* [case()] */ struct
'            {
'            IDispatch *pEvent;
'            long lEventCode;
'            }    MSP_PRIVATE_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            ITTerminal *pParentFileTerminal;
'            ITFileTrack *pFileTrack;
'            TERMINAL_MEDIA_STATE TerminalMediaState;
'            FT_STATE_EVENT_CAUSE ftecEventCause;
'            HRESULT hrErrorCode;
'            }    MSP_FILE_TERMINAL_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            ITTerminal *pASRTerminal;
'            HRESULT hrErrorCode;
'            }    MSP_ASR_TERMINAL_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            ITTerminal *pTTSTerminal;
'            HRESULT hrErrorCode;
'            }    MSP_TTS_TERMINAL_EVENT_INFO;
'        /* [case()] */ struct
'            {
'            ITTerminal *pToneTerminal;
'            HRESULT hrErrorCode;
'            }    MSP_TONE_TERMINAL_EVENT_INFO;
'        }    ;
'    }    MSP_EVENT_INFO;

' // Size = 8 bytes
TYPE MSP_ADDRESS_EVENT_INFO DWORD
   Type      AS LONG        ' MSP_ADDRESS_EVENT enum
   pTerminal AS DWORD PTR   ' ITTerminal *
END TYPE

' // Size = 20 bytes
TYPE MSP_CALL_EVENT_INFO DWORD
   Type      AS LONG        ' MSP_CALL_EVENT enum
   Cause     AS LONG        ' MSP_CALL_EVENT_CAUSE enum
   pStream   AS DWORD PTR   ' ITStream *
   pTerminal AS DWORD PTR   ' ITTerminal *
   hrError   AS LONG        ' HRESULT
END TYPE

' // Size = 8 bytes
TYPE MSP_TSP_DATA DWORD
   dwBufferSize AS DWORD
   pBuffer(0)   AS BYTE
END TYPE

' // Size = 8 bytes
TYPE MSP_PRIVATE_EVENT_INFO DWORD
   pEvent     AS DWORD PTR   ' IDispatch *
   lEventCode AS LONG
END TYPE

' // Size = 20 bytes
TYPE MSP_FILE_TERMINAL_EVENT_INFO DWORD
   pParentFileTerminal AS DWORD PTR   ' ITTerminal *
   pFileTrack          AS DWORD PTR   ' ITFileTrack *
   TerminalMediaState  AS LONG        ' TERMINAL_MEDIA_STATE enum
   ftecEventCause      AS LONG        ' FT_STATE_EVENT_CAUSE enum
   hrErrorCode         AS LONG        ' HRESULT
END TYPE

' // Size = 8 bytes
TYPE MSP_ASR_TERMINAL_EVENT_INFO DWORD
   pASRTerminal AS DWORD PTR   ' ITTerminal *
   hrErrorCode  AS LONG        ' HRESULT
END TYPE

' // Size = 8 bytes
TYPE MSP_TTS_TERMINAL_EVENT_INFO DWORD
   pTTSTerminal AS DWORD PTR   ' ITTerminal *
   hrErrorCode  AS LONG        ' HRESULT
END TYPE

' // Size = 8 bytes
TYPE MSP_TONE_TERMINAL_EVENT_INFO DWORD
   pToneTerminal AS DWORD PTR   ' ITTerminal *
   hrErrorCode   AS LONG        ' HRESULT
END TYPE

' // Size = 20 bytes
UNION MSP_EVENT_INFO_UNION DWORD
   MspAddressEventInfo      AS MSP_ADDRESS_EVENT_INFO
   MspCallEventInfo         AS MSP_CALL_EVENT_INFO
   MspTspData               AS MSP_TSP_DATA
   MspPrivateEventInfo      AS MSP_PRIVATE_EVENT_INFO
   MspFileTerminalEventInfo AS MSP_FILE_TERMINAL_EVENT_INFO
   MspAsrTerminalEventInfo  AS MSP_ASR_TERMINAL_EVENT_INFO
   MspTtsTerminalEventInfo  AS MSP_TTS_TERMINAL_EVENT_INFO
   MspToneTerminalEventInfo AS MSP_TONE_TERMINAL_EVENT_INFO
END UNION

' // Size = 32 bytes
TYPE MSP_EVENT_INFO DWORD
   dwSize AS DWORD
   Event  AS LONG          ' MSP_EVENT enum
   hCall  AS LONG          ' MSP_HANDLE
   MSP_EVENT_INFO_UNION
END TYPE

' ########################################################################################
' Interface name = ITPluggableTerminalEventSink
' IID = {6E0887BE-BA1A-492E-BD10-4020EC5E33E0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalEventSink_INTERFACE_DEFINED)
    %ITPluggableTerminalEventSink_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalEventSink $IID_ITPluggableTerminalEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FireEvent ( _                                 ' VTable offset = 12
     BYREF pMspEventInfo AS MSP_EVENT_INFO _            ' __in const MSP_EVENT_INFO *pMspEventInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalEventSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalEventSinkRegistration
' IID = {F7115709-A216-4957-A759-060AB32A90D1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalEventSinkRegistration_INTERFACE_DEFINED)
    %ITPluggableTerminalEventSinkRegistration_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalEventSinkRegistration $IID_ITPluggableTerminalEventSinkRegistration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterSink ( _                              ' VTable offset = 12
     BYVAL pEventSink AS IUnknown _                     ' __in ITPluggableTerminalEventSink *pEventSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterSink ( _                            ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalEventSinkRegistration_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITMSPAddress
' IID = {EE3BD600-3868-11D2-A045-00C04FB6809F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITMSPAddress_INTERFACE_DEFINED)
    %ITMSPAddress_INTERFACE_DEFINED = 1

INTERFACE ITMSPAddress $IID_ITMSPAddress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hEvent AS LONG _                             ' __in MSP_HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMSPCall ( _                             ' VTable offset = 20
     BYVAL hCall AS LONG _                              ' __in MSP_HANDLE hCall
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL dwMediaType AS DWORD _                       ' __in DWORD dwMediaType
   , BYVAL pOuterUnknown AS IUnknown _                  ' __in IUnknown *pOuterUnknown
   , BYREF ppStreamControl AS IUnknown _                ' __out IUnknown **ppStreamControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShutdownMSPCall ( _                           ' VTable offset = 24
     BYVAL pStreamControl AS IUnknown _                 ' __in IUnknown *pStreamControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReceiveTSPData ( _                            ' VTable offset = 28
     BYVAL pMSPCall AS IUnknown _                       ' __in IUnknown *pMSPCall
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 32
     BYREF pdwSize AS DWORD _                           ' __inout DWORD *pdwSize
   , BYVAL pEventBuffer AS BYTE PTR _                   ' __inout byte *pEventBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITMSPAddress_INTERFACE_DEFINED__ */


#IF NOT %DEF(%TAPI3Lib_LIBRARY_DEFINED)
    %TAPI3Lib_LIBRARY_DEFINED = 1

$LIBID_TAPI3Lib = GUID$("{21D6D480-A88B-11D0-83DD-00AA003CCABD}")


' ========================================================================================
' TapiConstants
' IID: {05B96A7A-DD39-11D0-8ED3-00C04FB6809F}
' ========================================================================================

#IF NOT %DEF(%TapiConstants_MODULE_DEFINED)
    %TapiConstants_MODULE_DEFINED = 1

$$CLSID_String_VideoWindowTerm       = "{F7438990-D6EB-11D0-82A6-00AA00B5CA1B}"$$
$$CLSID_String_VideoInputTerminal    = "{AAF578EC-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_HandsetTerminal       = "{AAF578EB-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_HeadsetTerminal       = "{AAF578ED-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_SpeakerphoneTerminal  = "{AAF578EE-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_MicrophoneTerminal    = "{AAF578EF-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_SpeakersTerminal      = "{AAF578F0-DC70-11D0-8ED3-00C04FB6809F}"$$
$$CLSID_String_MediaStreamTerminal   = "{E2F7AEF7-4971-11D1-A671-006097C9A2E8}"$$
$$CLSID_String_FileRecordingTerminal = "{521F3D06-C3D0-4511-8617-86B9A783DA77}"$$
$$CLSID_String_FilePlaybackTerminal  = "{0CB9914C-79CD-47DC-ADB0-327F47CEFB20}"$$
$$TAPIPROTOCOL_String_PSTN           = "{831CE2D6-83B5-11D1-BB5C-00C04FB6809F}"$$
$$TAPIPROTOCOL_String_H323           = "{831CE2D7-83B5-11D1-BB5C-00C04FB6809F}"$$
$$TAPIPROTOCOL_String_Multicast      = "{831CE2D8-83B5-11D1-BB5C-00C04FB6809F}"$$

' Also defined in Tapi.inc
'%LINEADDRESSTYPE_PHONENUMBER             = &H00000001???
'%LINEADDRESSTYPE_SDP                     = &H00000002???
'%LINEADDRESSTYPE_EMAILNAME               = &H00000004???
'%LINEADDRESSTYPE_DOMAINNAME              = &H00000008???
'%LINEADDRESSTYPE_IPADDRESS               = &H00000010???
'%LINEDIGITMODE_PULSE                     = &H00000001???
'%LINEDIGITMODE_DTMF                      = &H00000002???
'%LINEDIGITMODE_DTMFEND                   = &H00000004???

' Also defined in Tapi3if.inc
'%TAPIMEDIATYPE_AUDIO         = &H8
'%TAPIMEDIATYPE_VIDEO         = &H8000
'%TAPIMEDIATYPE_DATAMODEM     = &H10
'%TAPIMEDIATYPE_G3FAX         = &H20
'%TAPIMEDIATYPE_MULTITRACK    = &H10000

#ENDIF   ' /* __TapiConstants_MODULE_DEFINED__ */

#ENDIF   ' /* __TAPI3Lib_LIBRARY_DEFINED__ */


%TAPI_CURRENT_VERSION = &H00030001
#INCLUDE ONCE "tapi.inc"
#INCLUDE ONCE "tapi3err.inc"
