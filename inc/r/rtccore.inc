' ########################################################################################
' Microsoft Windows
' File: rtccore.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RTCCORELib
' Version: 1.2
' Documentation string: RTCCore 1.2 Type Library
' Included as a resource rtcdll.dll
' Library GUID: {CD260094-DE10-4AEE-AC73-EF87F6E12683}
' ########################################################################################

#INCLUDE THIS ONCE
%RTCCORE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "control.inc"
#INCLUDE ONCE "rtcerr.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_RTCClient = GUID$("{7A42EA29-A2B7-40C4-B091-F6F024AA89BE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IRTCBuddy = GUID$("{FCB136C8-7B90-4E0C-BEFE-56EDF0BA6F1C}")
$IID_IRTCBuddy2 = GUID$("{102F9588-23E7-40E3-954D-CD7A1D5C0361}")
$IID_IRTCBuddyEvent = GUID$("{F36D755D-17E6-404E-954F-0FC07574C78D}")
$IID_IRTCBuddyEvent2 = GUID$("{484A7F1E-73F0-4990-BFC2-60BC3978A720}")
$IID_IRTCBuddyGroup = GUID$("{60361E68-9164-4389-A4C6-D0B3925BDA5E}")
$IID_IRTCBuddyGroupEvent = GUID$("{3A79E1D1-B736-4414-96F8-BBC7F08863E4}")
$IID_IRTCClient = GUID$("{07829E45-9A34-408E-A011-BDDF13487CD1}")
$IID_IRTCClient2 = GUID$("{0C91D71D-1064-42DA-BFA5-572BEB8EEA84}")
$IID_IRTCClientEvent = GUID$("{2B493B7A-3CBA-4170-9C8B-76A9DACDD644}")
$IID_IRTCClientPortManagement = GUID$("{D5DF3F03-4BDE-4417-AEFE-71177BDAEA66}")
$IID_IRTCClientPresence = GUID$("{11C3CBCC-0744-42D1-968A-51AA1BB274C6}")
$IID_IRTCClientPresence2 = GUID$("{AD1809E8-62F7-4783-909A-29C9D2CB1D34}")
$IID_IRTCClientProvisioning = GUID$("{B9F5CF06-65B9-4A80-A0E6-73CAE3EF3822}")
$IID_IRTCClientProvisioning2 = GUID$("{A70909B5-F40E-4587-BB75-E6BC0845023E}")
$IID_IRTCCollection = GUID$("{EC7C8096-B918-4044-94F1-E4FBA0361D5C}")
$IID_IRTCDispatchEventNotification = GUID$("{176DDFBE-FEC0-4D55-BC87-84CFF1EF7F91}")
$IID_IRTCEnumBuddies = GUID$("{F7296917-5569-4B3B-B3AF-98D1144B2B87}")
$IID_IRTCEnumGroups = GUID$("{742378D6-A141-4415-8F27-35D99076CF5D}")
$IID_IRTCEnumParticipants = GUID$("{FCD56F29-4A4F-41B2-BA5C-F5BCCC060BF6}")
$IID_IRTCEnumPresenceDevices = GUID$("{708C2AB7-8BF8-42F8-8C7D-635197AD5539}")
$IID_IRTCEnumProfiles = GUID$("{29B7C41C-ED82-4BCA-84AD-39D5101B58E3}")
$IID_IRTCEnumUserSearchResults = GUID$("{83D4D877-AA5D-4A5B-8D0E-002A8067E0E8}")
$IID_IRTCEnumWatchers = GUID$("{A87D55D7-DB74-4ED1-9CA4-77A0E41B413E}")
$IID_IRTCEventNotification = GUID$("{13FA24C7-5748-4B21-91F5-7397609CE747}")
$IID_IRTCInfoEvent = GUID$("{4E1D68AE-1912-4F49-B2C3-594FADFD425F}")
$IID_IRTCIntensityEvent = GUID$("{4C23BF51-390C-4992-A41D-41EEC05B2A4B}")
$IID_IRTCMediaEvent = GUID$("{099944FB-BCDA-453E-8C41-E13DA2ADF7F3}")
$IID_IRTCMediaRequestEvent = GUID$("{52572D15-148C-4D97-A36C-2DA55C289D63}")
$IID_IRTCMessagingEvent = GUID$("{D3609541-1B29-4DE5-A4AD-5AEBAF319512}")
$IID_IRTCParticipant = GUID$("{AE86ADD5-26B1-4414-AF1D-B94CD938D739}")
$IID_IRTCParticipantStateChangeEvent = GUID$("{09BCB597-F0FA-48F9-B420-468CEA7FDE04}")
$IID_IRTCPortManager = GUID$("{DA77C14B-6208-43CA-8DDF-5B60A0A69FAC}")
$IID_IRTCPresenceContact = GUID$("{8B22F92C-CD90-42DB-A733-212205C3E3DF}")
$IID_IRTCPresenceDataEvent = GUID$("{38F0E78C-8B87-4C04-A82D-AEDD83C909BB}")
$IID_IRTCPresenceDevice = GUID$("{BC6A90DD-AD9A-48DA-9B0C-2515E38521AD}")
$IID_IRTCPresencePropertyEvent = GUID$("{F777F570-A820-49D5-86BD-E099493F1518}")
$IID_IRTCPresenceStatusEvent = GUID$("{78673F32-4A0F-462C-89AA-EE7706707678}")
$IID_IRTCProfile = GUID$("{D07ECA9E-4062-4DD4-9E7D-722A49BA7303}")
$IID_IRTCProfile2 = GUID$("{4B81F84E-BDC7-4184-9154-3CB2DD7917FB}")
$IID_IRTCProfileEvent = GUID$("{D6D5AB3B-770E-43E8-800A-79B062395FCA}")
$IID_IRTCProfileEvent2 = GUID$("{62E56EDC-03FA-4121-94FB-23493FD0AE64}")
$IID_IRTCRegistrationStateChangeEvent = GUID$("{62D0991B-50AB-4F02-B948-CA94F26F8F95}")
$IID_IRTCReInviteEvent = GUID$("{11558D84-204C-43E7-99B0-2034E9417F7D}")
$IID_IRTCRoamingEvent = GUID$("{79960A6B-0CB1-4DC8-A805-7318E99902E8}")
$IID_IRTCSession = GUID$("{387C8086-99BE-42FB-9973-7C0FC0CA9FA8}")
$IID_IRTCSession2 = GUID$("{17D7CDFC-B007-484C-99D2-86A8A820991D}")
$IID_IRTCSessionCallControl = GUID$("{E9A50D94-190B-4F82-9530-3B8EBF60758A}")
$IID_IRTCSessionDescriptionManager = GUID$("{BA7F518E-D336-4070-93A6-865395C843F9}")
$IID_IRTCSessionOperationCompleteEvent = GUID$("{A6BFF4C0-F7C8-4D3C-9A41-3550F78A95B0}")
$IID_IRTCSessionOperationCompleteEvent2 = GUID$("{F6FC2A9B-D5BC-4241-B436-1B8460C13832}")
$IID_IRTCSessionPortManagement = GUID$("{A072F1D6-0286-4E1F-85F2-17A2948456EC}")
$IID_IRTCSessionReferredEvent = GUID$("{176A6828-4FCC-4F28-A862-04597A6CF1C4}")
$IID_IRTCSessionReferStatusEvent = GUID$("{3D8FC2CD-5D76-44AB-BB68-2A80353B34A2}")
$IID_IRTCSessionStateChangeEvent = GUID$("{B5BAD703-5952-48B3-9321-7F4500521506}")
$IID_IRTCSessionStateChangeEvent2 = GUID$("{4F933171-6F95-4880-80D9-2EC8D495D261}")
$IID_IRTCUserSearch = GUID$("{B619882B-860C-4DB4-BE1B-693B6505BBE5}")
$IID_IRTCUserSearchQuery = GUID$("{288300F5-D23A-4365-9A73-9985C98C2881}")
$IID_IRTCUserSearchResult = GUID$("{851278B2-9592-480F-8DB5-2DE86B26B54D}")
$IID_IRTCUserSearchResultsEvent = GUID$("{D8C8C3CD-7FAC-4088-81C5-C24CBC0938E3}")
$IID_IRTCWatcher = GUID$("{C7CEDAD8-346B-4D1B-AC02-A2088DF9BE4F}")
$IID_IRTCWatcher2 = GUID$("{D4D9967F-D011-4B1D-91E3-ABA78F96393D}")
$IID_IRTCWatcherEvent = GUID$("{F30D7261-587A-424F-822C-312788F43548}")
$IID_IRTCWatcherEvent2 = GUID$("{E52891E8-188C-49AF-B005-98ED13F83F9C}")
$IID_IVideoWindow = GUID$("{56A868B4-0AD4-11CE-B03A-0020AF0BA770}")

' ========================================================================================
' enum RTC_AUDIO_DEVICE
' ========================================================================================

%RTCAD_SPEAKER    = 0
%RTCAD_MICROPHONE = %RTCAD_SPEAKER + 1

' ========================================================================================
' enum RTC_VIDEO_DEVICE
' ========================================================================================

%RTCVD_RECEIVE   = 0
%RTCVD_PREVIEW   = %RTCVD_RECEIVE + 1

' ========================================================================================
' enum RTC_EVENT
' ========================================================================================

%RTCE_CLIENT                     = 0
%RTCE_REGISTRATION_STATE_CHANGE  = %RTCE_CLIENT                     + 1
%RTCE_SESSION_STATE_CHANGE       = %RTCE_REGISTRATION_STATE_CHANGE  + 1
%RTCE_SESSION_OPERATION_COMPLETE = %RTCE_SESSION_STATE_CHANGE       + 1
%RTCE_PARTICIPANT_STATE_CHANGE   = %RTCE_SESSION_OPERATION_COMPLETE + 1
%RTCE_MEDIA                      = %RTCE_PARTICIPANT_STATE_CHANGE   + 1
%RTCE_INTENSITY                  = %RTCE_MEDIA                      + 1
%RTCE_MESSAGING                  = %RTCE_INTENSITY                  + 1
%RTCE_BUDDY                      = %RTCE_MESSAGING                  + 1
%RTCE_WATCHER                    = %RTCE_BUDDY                      + 1
%RTCE_PROFILE                    = %RTCE_WATCHER                    + 1
%RTCE_USERSEARCH                 = %RTCE_PROFILE                    + 1
%RTCE_INFO                       = %RTCE_USERSEARCH                 + 1
%RTCE_GROUP                      = %RTCE_INFO                       + 1
%RTCE_MEDIA_REQUEST              = %RTCE_GROUP                      + 1
%RTCE_ROAMING                    = %RTCE_MEDIA_REQUEST              + 1
%RTCE_PRESENCE_PROPERTY          = %RTCE_ROAMING                    + 1
%RTCE_PRESENCE_DATA              = %RTCE_PRESENCE_PROPERTY          + 1
%RTCE_PRESENCE_STATUS            = %RTCE_PRESENCE_DATA              + 1
%RTCE_SESSION_REFER_STATUS       = %RTCE_PRESENCE_STATUS            + 1
%RTCE_SESSION_REFERRED           = %RTCE_SESSION_REFER_STATUS       + 1
%RTCE_REINVITE                   = %RTCE_SESSION_REFERRED           + 1

' ========================================================================================
' enum RTC_LISTEN_MODE
' ========================================================================================

%RTCLM_NONE    = 0
%RTCLM_DYNAMIC = %RTCLM_NONE    + 1
%RTCLM_BOTH    = %RTCLM_DYNAMIC + 1

' ========================================================================================
' enum RTC_CLIENT_EVENT_TYPE
' ========================================================================================

%RTCCET_VOLUME_CHANGE          = 0
%RTCCET_DEVICE_CHANGE          = %RTCCET_VOLUME_CHANGE          + 1
%RTCCET_NETWORK_QUALITY_CHANGE = %RTCCET_DEVICE_CHANGE          + 1
%RTCCET_ASYNC_CLEANUP_DONE     = %RTCCET_NETWORK_QUALITY_CHANGE + 1

' ========================================================================================
' enum RTC_BUDDY_EVENT_TYPE
' ========================================================================================

%RTCBET_BUDDY_ADD          = 0
%RTCBET_BUDDY_REMOVE       = %RTCBET_BUDDY_ADD          + 1
%RTCBET_BUDDY_UPDATE       = %RTCBET_BUDDY_REMOVE       + 1
%RTCBET_BUDDY_STATE_CHANGE = %RTCBET_BUDDY_UPDATE       + 1
%RTCBET_BUDDY_ROAMED       = %RTCBET_BUDDY_STATE_CHANGE + 1
%RTCBET_BUDDY_SUBSCRIBED   = %RTCBET_BUDDY_ROAMED       + 1

' ========================================================================================
' enum RTC_WATCHER_EVENT_TYPE
' ========================================================================================

%RTCWET_WATCHER_ADD      = 0
%RTCWET_WATCHER_REMOVE   = %RTCWET_WATCHER_ADD      + 1
%RTCWET_WATCHER_UPDATE   = %RTCWET_WATCHER_REMOVE   + 1
%RTCWET_WATCHER_OFFERING = %RTCWET_WATCHER_UPDATE   + 1
%RTCWET_WATCHER_ROAMED   = %RTCWET_WATCHER_OFFERING + 1

' ========================================================================================
' enum RTC_GROUP_EVENT_TYPE
' ========================================================================================

%RTCGET_GROUP_ADD          = 0
%RTCGET_GROUP_REMOVE       = %RTCGET_GROUP_ADD          + 1
%RTCGET_GROUP_UPDATE       = %RTCGET_GROUP_REMOVE       + 1
%RTCGET_GROUP_BUDDY_ADD    = %RTCGET_GROUP_UPDATE       + 1
%RTCGET_GROUP_BUDDY_REMOVE = %RTCGET_GROUP_BUDDY_ADD    + 1
%RTCGET_GROUP_ROAMED       = %RTCGET_GROUP_BUDDY_REMOVE + 1

' ========================================================================================
' enum RTC_TERMINATE_REASON
' ========================================================================================

%RTCTR_NORMAL                      = 0
%RTCTR_DND                         = %RTCTR_NORMAL                      + 1
%RTCTR_BUSY                        = %RTCTR_DND                         + 1
%RTCTR_REJECT                      = %RTCTR_BUSY                        + 1
%RTCTR_TIMEOUT                     = %RTCTR_REJECT                      + 1
%RTCTR_SHUTDOWN                    = %RTCTR_TIMEOUT                     + 1
%RTCTR_INSUFFICIENT_SECURITY_LEVEL = %RTCTR_SHUTDOWN                    + 1
%RTCTR_NOT_SUPPORTED               = %RTCTR_INSUFFICIENT_SECURITY_LEVEL + 1

' ========================================================================================
' enum RTC_REGISTRATION_STATE
' ========================================================================================

%RTCRS_NOT_REGISTERED       = 0
%RTCRS_REGISTERING          = %RTCRS_NOT_REGISTERED      + 1
%RTCRS_REGISTERED           = %RTCRS_REGISTERING         + 1
%RTCRS_REJECTED             = %RTCRS_REGISTERED          + 1
%RTCRS_UNREGISTERING        = %RTCRS_REJECTED            + 1
%RTCRS_ERROR                = %RTCRS_UNREGISTERING       + 1
%RTCRS_LOGGED_OFF           = %RTCRS_ERROR               + 1
%RTCRS_LOCAL_PA_LOGGED_OFF  = %RTCRS_LOGGED_OFF          + 1
%RTCRS_REMOTE_PA_LOGGED_OFF = %RTCRS_LOCAL_PA_LOGGED_OFF + 1

' ========================================================================================
' enum RTC_SESSION_STATE
' ========================================================================================

%RTCSS_IDLE         = 0
%RTCSS_INCOMING     = %RTCSS_IDLE         + 1
%RTCSS_ANSWERING    = %RTCSS_INCOMING     + 1
%RTCSS_INPROGRESS   = %RTCSS_ANSWERING    + 1
%RTCSS_CONNECTED    = %RTCSS_INPROGRESS   + 1
%RTCSS_DISCONNECTED = %RTCSS_CONNECTED    + 1
%RTCSS_HOLD         = %RTCSS_DISCONNECTED + 1
%RTCSS_REFER        = %RTCSS_HOLD         + 1

' ========================================================================================
' enum RTC_PARTICIPANT_STATE
' ========================================================================================

%RTCPS_IDLE          = 0
%RTCPS_PENDING       = %RTCPS_IDLE          + 1
%RTCPS_INCOMING      = %RTCPS_PENDING       + 1
%RTCPS_ANSWERING     = %RTCPS_INCOMING      + 1
%RTCPS_INPROGRESS    = %RTCPS_ANSWERING     + 1
%RTCPS_ALERTING      = %RTCPS_INPROGRESS    + 1
%RTCPS_CONNECTED     = %RTCPS_ALERTING      + 1
%RTCPS_DISCONNECTING = %RTCPS_CONNECTED     + 1
%RTCPS_DISCONNECTED  = %RTCPS_DISCONNECTING + 1

' ========================================================================================
' enum RTC_WATCHER_STATE
' ========================================================================================

%RTCWS_UNKNOWN  = 0
%RTCWS_OFFERING = %RTCWS_UNKNOWN  + 1
%RTCWS_ALLOWED  = %RTCWS_OFFERING + 1
%RTCWS_BLOCKED  = %RTCWS_ALLOWED  + 1
%RTCWS_DENIED   = %RTCWS_BLOCKED  + 1
%RTCWS_PROMPT   = %RTCWS_DENIED   + 1

' ========================================================================================
' enum RTC_ACE_SCOPE
' ========================================================================================

%RTCAS_SCOPE_USER   = 0
%RTCAS_SCOPE_DOMAIN = %RTCAS_SCOPE_USER   + 1
%RTCAS_SCOPE_ALL    = %RTCAS_SCOPE_DOMAIN + 1

' ========================================================================================
' enum RTC_OFFER_WATCHER_MODE
' ========================================================================================

%RTCOWM_OFFER_WATCHER_EVENT       = 0
%RTCOWM_AUTOMATICALLY_ADD_WATCHER = %RTCOWM_OFFER_WATCHER_EVENT + 1

' ========================================================================================
' enum RTC_WATCHER_MATCH_MODE
' ========================================================================================

%RTCWMM_EXACT_MATCH    = 0
%RTCWMM_BEST_ACE_MATCH = %RTCWMM_EXACT_MATCH + 1

' ========================================================================================
' enum RTC_PRIVACY_MODE
' ========================================================================================

%RTCPM_BLOCK_LIST_EXCLUDED = 0
%RTCPM_ALLOW_LIST_ONLY     = %RTCPM_BLOCK_LIST_EXCLUDED + 1

' ========================================================================================
' enum RTC_SESSION_TYPE
' ========================================================================================

%RTCST_PC_TO_PC       = 0
%RTCST_PC_TO_PHONE    = %RTCST_PC_TO_PC       + 1
%RTCST_PHONE_TO_PHONE = %RTCST_PC_TO_PHONE    + 1
%RTCST_IM             = %RTCST_PHONE_TO_PHONE + 1
%RTCST_MULTIPARTY_IM  = %RTCST_IM             + 1
%RTCST_APPLICATION    = %RTCST_MULTIPARTY_IM  + 1

' ========================================================================================
' enum RTC_PRESENCE_STATUS
' ========================================================================================

%RTCXS_PRESENCE_OFFLINE       = 0
%RTCXS_PRESENCE_ONLINE        = %RTCXS_PRESENCE_OFFLINE       + 1
%RTCXS_PRESENCE_AWAY          = %RTCXS_PRESENCE_ONLINE        + 1
%RTCXS_PRESENCE_IDLE          = %RTCXS_PRESENCE_AWAY          + 1
%RTCXS_PRESENCE_BUSY          = %RTCXS_PRESENCE_IDLE          + 1
%RTCXS_PRESENCE_BE_RIGHT_BACK = %RTCXS_PRESENCE_BUSY          + 1
%RTCXS_PRESENCE_ON_THE_PHONE  = %RTCXS_PRESENCE_BE_RIGHT_BACK + 1
%RTCXS_PRESENCE_OUT_TO_LUNCH  = %RTCXS_PRESENCE_ON_THE_PHONE  + 1

' ========================================================================================
' enum RTC_BUDDY_SUBSCRIPTION_TYPE
' ========================================================================================

%RTCBT_SUBSCRIBED     = 0
%RTCBT_ALWAYS_OFFLINE = %RTCBT_SUBSCRIBED     + 1
%RTCBT_ALWAYS_ONLINE  = %RTCBT_ALWAYS_OFFLINE + 1
%RTCBT_POLL           = %RTCBT_ALWAYS_ONLINE  + 1

' ========================================================================================
' enum RTC_MEDIA_EVENT_TYPE
' ========================================================================================

%RTCMET_STOPPED = 0
%RTCMET_STARTED = %RTCMET_STOPPED + 1
%RTCMET_FAILED  = %RTCMET_STARTED + 1

' ========================================================================================
' enum RTC_MEDIA_EVENT_REASON
' ========================================================================================

%RTCMER_NORMAL              = 0
%RTCMER_HOLD                = %RTCMER_NORMAL              + 1
%RTCMER_TIMEOUT             = %RTCMER_HOLD                + 1
%RTCMER_BAD_DEVICE          = %RTCMER_TIMEOUT             + 1
%RTCMER_NO_PORT             = %RTCMER_BAD_DEVICE          + 1
%RTCMER_PORT_MAPPING_FAILED = %RTCMER_NO_PORT             + 1
%RTCMER_REMOTE_REQUEST      = %RTCMER_PORT_MAPPING_FAILED + 1

' ========================================================================================
' enum RTC_MESSAGING_EVENT_TYPE
' ========================================================================================

%RTCMSET_MESSAGE = 0
%RTCMSET_STATUS  = %RTCMSET_MESSAGE + 1

' ========================================================================================
' enum RTC_MESSAGING_USER_STATUS
' ========================================================================================

%RTCMUS_IDLE   = 0
%RTCMUS_TYPING = %RTCMUS_IDLE + 1

' ========================================================================================
' enum RTC_DTMF
' ========================================================================================

%RTC_DTMF_0     = 0
%RTC_DTMF_1     = %RTC_DTMF_0     + 1
%RTC_DTMF_2     = %RTC_DTMF_1     + 1
%RTC_DTMF_3     = %RTC_DTMF_2     + 1
%RTC_DTMF_4     = %RTC_DTMF_3     + 1
%RTC_DTMF_5     = %RTC_DTMF_4     + 1
%RTC_DTMF_6     = %RTC_DTMF_5     + 1
%RTC_DTMF_7     = %RTC_DTMF_6     + 1
%RTC_DTMF_8     = %RTC_DTMF_7     + 1
%RTC_DTMF_9     = %RTC_DTMF_8     + 1
%RTC_DTMF_STAR  = %RTC_DTMF_9     + 1
%RTC_DTMF_POUND = %RTC_DTMF_STAR  + 1
%RTC_DTMF_A     = %RTC_DTMF_POUND + 1
%RTC_DTMF_B     = %RTC_DTMF_A     + 1
%RTC_DTMF_C     = %RTC_DTMF_B     + 1
%RTC_DTMF_D     = %RTC_DTMF_C     + 1
%RTC_DTMF_FLASH = %RTC_DTMF_D     + 1

' ========================================================================================
' enum RTC_PROVIDER_URI
' ========================================================================================

%RTCPU_URIHOMEPAGE          = 0
%RTCPU_URIHELPDESK          = %RTCPU_URIHOMEPAGE          + 1
%RTCPU_URIPERSONALACCOUNT   = %RTCPU_URIHELPDESK          + 1
%RTCPU_URIDISPLAYDURINGCALL = %RTCPU_URIPERSONALACCOUNT   + 1
%RTCPU_URIDISPLAYDURINGIDLE = %RTCPU_URIDISPLAYDURINGCALL + 1

' ========================================================================================
' enum RTC_RING_TYPE
' ========================================================================================

%RTCRT_PHONE    = 0
%RTCRT_MESSAGE  = %RTCRT_PHONE   + 1
%RTCRT_RINGBACK = %RTCRT_MESSAGE + 1

' ========================================================================================
' enum RTC_T120_APPLET
' ========================================================================================

%RTCTA_WHITEBOARD = 0
%RTCTA_APPSHARING = %RTCTA_WHITEBOARD + 1

' ========================================================================================
' enum RTC_PORT_TYPE
' ========================================================================================

%RTCPT_AUDIO_RTP  = 0
%RTCPT_AUDIO_RTCP = %RTCPT_AUDIO_RTP  + 1
%RTCPT_VIDEO_RTP  = %RTCPT_AUDIO_RTCP + 1
%RTCPT_VIDEO_RTCP = %RTCPT_VIDEO_RTP  + 1
%RTCPT_SIP        = %RTCPT_VIDEO_RTCP + 1

' ========================================================================================
' enum RTC_USER_SEARCH_COLUMN
' ========================================================================================

%RTCUSC_URI         = 0
%RTCUSC_DISPLAYNAME = %RTCUSC_URI         + 1
%RTCUSC_TITLE       = %RTCUSC_DISPLAYNAME + 1
%RTCUSC_OFFICE      = %RTCUSC_TITLE       + 1
%RTCUSC_PHONE       = %RTCUSC_OFFICE      + 1
%RTCUSC_COMPANY     = %RTCUSC_PHONE       + 1
%RTCUSC_CITY        = %RTCUSC_COMPANY     + 1
%RTCUSC_STATE       = %RTCUSC_CITY        + 1
%RTCUSC_COUNTRY     = %RTCUSC_STATE       + 1
%RTCUSC_EMAIL       = %RTCUSC_COUNTRY     + 1

' ========================================================================================
' enum RTC_USER_SEARCH_PREFERENCE
' ========================================================================================

%RTCUSP_MAX_MATCHES = 0
%RTCUSP_TIME_LIMIT  = %RTCUSP_MAX_MATCHES + 1

' ========================================================================================
' enum RTC_ROAMING_EVENT_TYPE
' ========================================================================================

%RTCRET_BUDDY_ROAMING    = 0
%RTCRET_WATCHER_ROAMING  = %RTCRET_BUDDY_ROAMING    + 1
%RTCRET_PRESENCE_ROAMING = %RTCRET_WATCHER_ROAMING  + 1
%RTCRET_PROFILE_ROAMING  = %RTCRET_PRESENCE_ROAMING + 1
%RTCRET_WPENDING_ROAMING = %RTCRET_PROFILE_ROAMING  + 1

' ========================================================================================
' enum RTC_PROFILE_EVENT_TYPE
' ========================================================================================

%RTCPFET_PROFILE_GET    = 0
%RTCPFET_PROFILE_UPDATE = %RTCPFET_PROFILE_GET + 1

' ========================================================================================
' enum RTC_ANSWER_MODE
' ========================================================================================

%RTCAM_OFFER_SESSION_EVENT  = 0
%RTCAM_AUTOMATICALLY_ACCEPT = %RTCAM_OFFER_SESSION_EVENT  + 1
%RTCAM_AUTOMATICALLY_REJECT = %RTCAM_AUTOMATICALLY_ACCEPT + 1
%RTCAM_NOT_SUPPORTED        = %RTCAM_AUTOMATICALLY_REJECT + 1

' ========================================================================================
' enum RTC_SESSION_REFER_STATUS
' ========================================================================================

%RTCSRS_REFERRING = 0
%RTCSRS_ACCEPTED  = %RTCSRS_REFERRING + 1
%RTCSRS_ERROR     = %RTCSRS_ACCEPTED  + 1
%RTCSRS_REJECTED  = %RTCSRS_ERROR     + 1
%RTCSRS_DROPPED   = %RTCSRS_REJECTED  + 1
%RTCSRS_DONE      = %RTCSRS_DROPPED   + 1

' ========================================================================================
' enum RTC_PRESENCE_PROPERTY
' ========================================================================================

%RTCPP_PHONENUMBER = 0
%RTCPP_DISPLAYNAME = %RTCPP_PHONENUMBER + 1
%RTCPP_EMAIL       = %RTCPP_DISPLAYNAME + 1
%RTCPP_DEVICE_NAME = %RTCPP_EMAIL       + 1
%RTCPP_MULTIPLE    = %RTCPP_DEVICE_NAME + 1

' ========================================================================================
' enum RTC_SECURITY_TYPE
' ========================================================================================

%RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION = 0
%RTCSECT_T120_MEDIA_ENCRYPTION        = %RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION + 1

' ========================================================================================
' enum RTC_SECURITY_LEVEL
' ========================================================================================

%RTCSECL_UNSUPPORTED = 1
%RTCSECL_SUPPORTED   = %RTCSECL_UNSUPPORTED + 1
%RTCSECL_REQUIRED    = %RTCSECL_SUPPORTED   + 1

' ========================================================================================
' enum RTC_REINVITE_STATE
' ========================================================================================

%RTCRIN_INCOMING  = 0
%RTCRIN_SUCCEEDED = %RTCRIN_INCOMING  + 1
%RTCRIN_FAIL      = %RTCRIN_SUCCEEDED + 1

' ========================================================================================
' Constants
' ========================================================================================

%RTCCS_FORCE_PROFILE              =  &H00000001&
%RTCCS_FAIL_ON_REDIRECT           =  &H00000002&
%RTCMT_AUDIO_SEND                 =  &H00000001&
%RTCMT_AUDIO_RECEIVE              =  &H00000002&
%RTCMT_VIDEO_SEND                 =  &H00000004&
%RTCMT_VIDEO_RECEIVE              =  &H00000008&
%RTCMT_T120_SENDRECV              =  &H00000010&

%RTCMT_ALL_RTP = %RTCMT_AUDIO_SEND OR _
                 %RTCMT_AUDIO_RECEIVE OR _
                 %RTCMT_VIDEO_SEND OR _
                 %RTCMT_VIDEO_RECEIVE

%RTCMT_ALL     = %RTCMT_ALL_RTP OR %RTCMT_T120_SENDRECV

%RTCSI_PC_TO_PC                   =  &H00000001&
%RTCSI_PC_TO_PHONE                =  &H00000002&
%RTCSI_PHONE_TO_PHONE             =  &H00000004&
%RTCSI_IM                         =  &H00000008&
%RTCSI_MULTIPARTY_IM              =  &H00000010&
%RTCSI_APPLICATION                =  &H00000020&

%RTCTR_UDP                        =  &H00000001&
%RTCTR_TCP                        =  &H00000002&
%RTCTR_TLS                        =  &H00000004&

%RTCAU_BASIC                      =  &H00000001&
%RTCAU_DIGEST                     =  &H00000002&
%RTCAU_NTLM                       =  &H00000004&
%RTCAU_KERBEROS                   =  &H00000008&
%RTCAU_USE_LOGON_CRED             =  &H00010000&

%RTCRF_REGISTER_INVITE_SESSIONS   =  &H00000001&
%RTCRF_REGISTER_MESSAGE_SESSIONS  =  &H00000002&
%RTCRF_REGISTER_PRESENCE          =  &H00000004&
%RTCRF_REGISTER_NOTIFY            =  &H00000008&
%RTCRF_REGISTER_ALL               =  &H0000000F&

%RTCRMF_BUDDY_ROAMING             =  &H00000001&
%RTCRMF_WATCHER_ROAMING           =  &H00000002&
%RTCRMF_PRESENCE_ROAMING          =  &H00000004&
%RTCRMF_PROFILE_ROAMING           =  &H00000008&
%RTCRMF_ALL_ROAMING               =  &H0000000F&

%RTCEF_CLIENT                     =  &H00000001&
%RTCEF_REGISTRATION_STATE_CHANGE  =  &H00000002&
%RTCEF_SESSION_STATE_CHANGE       =  &H00000004&
%RTCEF_SESSION_OPERATION_COMPLETE =  &H00000008&
%RTCEF_PARTICIPANT_STATE_CHANGE   =  &H00000010&
%RTCEF_MEDIA                      =  &H00000020&
%RTCEF_INTENSITY                  =  &H00000040&
%RTCEF_MESSAGING                  =  &H00000080&
%RTCEF_BUDDY                      =  &H00000100&
%RTCEF_WATCHER                    =  &H00000200&
%RTCEF_PROFILE                    =  &H00000400&
%RTCEF_USERSEARCH                 =  &H00000800&
%RTCEF_INFO                       =  &H00001000&
%RTCEF_GROUP                      =  &H00002000&
%RTCEF_MEDIA_REQUEST              =  &H00004000&
%RTCEF_ROAMING                    =  &H00010000&
%RTCEF_PRESENCE_PROPERTY          =  &H00020000&
%RTCEF_BUDDY2                     =  &H00040000&
%RTCEF_WATCHER2                   =  &H00080000&
%RTCEF_SESSION_REFER_STATUS       =  &H00100000&
%RTCEF_SESSION_REFERRED           =  &H00200000&
%RTCEF_REINVITE                   =  &H00400000&
%RTCEF_PRESENCE_DATA              =  &H00800000&
%RTCEF_PRESENCE_STATUS            =  &H01000000&
%RTCEF_ALL                        =  &H01FFFFFF&

%RTCIF_DISABLE_MEDIA              =  &H00000001&
%RTCIF_DISABLE_UPNP               =  &H00000002&
%RTCIF_ENABLE_SERVER_CLASS        =  &H00000004&
%RTCIF_DISABLE_STRICT_DNS         =  &H00000008&


' ########################################################################################
' IRTCClient interface
' IID = 07829E45-9A34-408E-A011-BDDF13487CD1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCClient_INTERFACE_DEFINED)
    %IRTCClient_INTERFACE_DEFINED = 1

INTERFACE IRTCClient $IID_IRTCClient

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD PrepareForShutdown ( _                        ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EventFilter ( _                         ' VTable offset = 24
     BYVAL lFilter AS LONG _                            ' __in long lFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventFilter ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plFilter
   ' =====================================================================================
   METHOD SetPreferredMediaTypes ( _                    ' VTable offset = 32
     BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredMediaTypes ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   PROPERTY GET MediaCapabilities ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   METHOD CreateSession ( _                             ' VTable offset = 44
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   , BYVAL bstrLocalPhoneURI AS WSTRING _               ' __in BSTR bstrLocalPhoneURI
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY SET ListenForIncomingSessions ( _           ' VTable offset = 48
     BYVAL enListen AS LONG _                           ' __in RTC_LISTEN_MODE enListen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListenForIncomingSessions ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out RTC_LISTEN_MODE *penListen
   ' =====================================================================================
   PROPERTY GET NetworkAddresses ( _                    ' VTable offset = 56
     BYVAL fTCP AS INTEGER _                            ' __in VARIANT_BOOL fTCP
   , BYVAL fExternal AS INTEGER _                       ' __in VARIANT_BOOL fExternal
   ) AS VARIANT                                         ' __retval_out VARIANT *pvAddresses
   ' =====================================================================================
   PROPERTY SET Volume ( _                              ' VTable offset = 60
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume ( _                              ' VTable offset = 64
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET AudioMuted ( _                          ' VTable offset = 68
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL fMuted AS INTEGER _                          ' __in VARIANT_BOOL fMuted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioMuted ( _                          ' VTable offset = 72
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMuted
   ' =====================================================================================
   PROPERTY GET IVideoWindow ( _                        ' VTable offset = 76
     BYVAL enDevice AS LONG _                           ' __in RTC_VIDEO_DEVICE enDevice
   ) AS IVideoWindow                                    ' __retval_out IVideoWindow **ppIVideoWindow
   ' =====================================================================================
   PROPERTY SET PreferredAudioDevice ( _                ' VTable offset = 80
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL bstrDeviceName AS WSTRING _                  ' __in BSTR bstrDeviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredAudioDevice ( _                ' VTable offset = 84
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY SET PreferredVolume ( _                     ' VTable offset = 88
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredVolume ( _                     ' VTable offset = 92
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET PreferredAEC ( _                        ' VTable offset = 96
     BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL bEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredAEC ( _                        ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET PreferredVideoDevice ( _                ' VTable offset = 104
     BYVAL bstrDeviceName AS WSTRING _                  ' __in BSTR bstrDeviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredVideoDevice ( _                ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET ActiveMedia ( _                         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================
   PROPERTY SET MaxBitrate ( _                          ' VTable offset = 116
     BYVAL lMaxBitrate AS LONG _                        ' __in long lMaxBitrate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxBitrate ( _                          ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *plMaxBitrate
   ' =====================================================================================
   PROPERTY SET TemporalSpatialTradeOff ( _             ' VTable offset = 124
     BYVAL lValue AS LONG _                             ' __in long lValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemporalSpatialTradeOff ( _             ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY GET NetworkQuality ( _                      ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plNetworkQuality
   ' =====================================================================================
   METHOD StartT120Applet ( _                           ' VTable offset = 136
     BYVAL enApplet AS LONG _                           ' __in RTC_T120_APPLET enApplet
   )                                                    ' void
   ' =====================================================================================
   METHOD StopT120Applets ( _                           ' VTable offset = 140
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET IsT120AppletRunning ( _                 ' VTable offset = 144
     BYVAL enApplet AS LONG _                           ' __in RTC_T120_APPLET enApplet
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRunning
   ' =====================================================================================
   PROPERTY GET LocalUserURI ( _                        ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY SET LocalUserURI ( _                        ' VTable offset = 152
     BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalUserName ( _                       ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   PROPERTY SET LocalUserName ( _                       ' VTable offset = 160
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayRing ( _                                  ' VTable offset = 164
     BYVAL enType AS LONG _                             ' __in RTC_RING_TYPE enType
   , BYVAL bPlay AS INTEGER _                           ' __in VARIANT_BOOL bPlay
   )                                                    ' void
   ' =====================================================================================
   METHOD SendDTMF ( _                                  ' VTable offset = 168
     BYVAL enDTMF AS LONG _                             ' __in RTC_DTMF enDTMF
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeTuningWizard ( _                        ' VTable offset = 172
     BYVAL hwndParent AS DWORD _                        ' __in OAHWND hwndParent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTuned ( _                             ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfTuned
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClient_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClient2 interface
' IID = 0C91D71D-1064-42DA-BFA5-572BEB8EEA84
' Inherited interface = IRTCClient
' ########################################################################################

#IF NOT %DEF(%IRTCClient2_INTERFACE_DEFINED)
    %IRTCClient2_INTERFACE_DEFINED = 1

INTERFACE IRTCClient2 $IID_IRTCClient2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCClient Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD PrepareForShutdown ( _                        ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EventFilter ( _                         ' VTable offset = 24
     BYVAL lFilter AS LONG _                            ' __in long lFilter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EventFilter ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plFilter
   ' =====================================================================================
   METHOD SetPreferredMediaTypes ( _                    ' VTable offset = 32
     BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredMediaTypes ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   PROPERTY GET MediaCapabilities ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   METHOD CreateSession ( _                             ' VTable offset = 44
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   , BYVAL bstrLocalPhoneURI AS WSTRING _               ' __in BSTR bstrLocalPhoneURI
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY SET ListenForIncomingSessions ( _           ' VTable offset = 48
     BYVAL enListen AS LONG _                           ' __in RTC_LISTEN_MODE enListen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListenForIncomingSessions ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out RTC_LISTEN_MODE *penListen
   ' =====================================================================================
   PROPERTY GET NetworkAddresses ( _                    ' VTable offset = 56
     BYVAL fTCP AS INTEGER _                            ' __in VARIANT_BOOL fTCP
   , BYVAL fExternal AS INTEGER _                       ' __in VARIANT_BOOL fExternal
   ) AS VARIANT                                         ' __retval_out VARIANT *pvAddresses
   ' =====================================================================================
   PROPERTY SET Volume ( _                              ' VTable offset = 60
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume ( _                              ' VTable offset = 64
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET AudioMuted ( _                          ' VTable offset = 68
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL fMuted AS INTEGER _                          ' __in VARIANT_BOOL fMuted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioMuted ( _                          ' VTable offset = 72
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMuted
   ' =====================================================================================
   PROPERTY GET IVideoWindow ( _                        ' VTable offset = 76
     BYVAL enDevice AS LONG _                           ' __in RTC_VIDEO_DEVICE enDevice
   ) AS IVideoWindow                                    ' __retval_out IVideoWindow **ppIVideoWindow
   ' =====================================================================================
   PROPERTY SET PreferredAudioDevice ( _                ' VTable offset = 80
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL bstrDeviceName AS WSTRING _                  ' __in BSTR bstrDeviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredAudioDevice ( _                ' VTable offset = 84
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY SET PreferredVolume ( _                     ' VTable offset = 88
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   , BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredVolume ( _                     ' VTable offset = 92
     BYVAL enDevice AS LONG _                           ' __in RTC_AUDIO_DEVICE enDevice
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET PreferredAEC ( _                        ' VTable offset = 96
     BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL bEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredAEC ( _                        ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET PreferredVideoDevice ( _                ' VTable offset = 104
     BYVAL bstrDeviceName AS WSTRING _                  ' __in BSTR bstrDeviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredVideoDevice ( _                ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET ActiveMedia ( _                         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================
   PROPERTY SET MaxBitrate ( _                          ' VTable offset = 116
     BYVAL lMaxBitrate AS LONG _                        ' __in long lMaxBitrate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxBitrate ( _                          ' VTable offset = 120
   ) AS LONG                                            ' __retval_out long *plMaxBitrate
   ' =====================================================================================
   PROPERTY SET TemporalSpatialTradeOff ( _             ' VTable offset = 124
     BYVAL lValue AS LONG _                             ' __in long lValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TemporalSpatialTradeOff ( _             ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY GET NetworkQuality ( _                      ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plNetworkQuality
   ' =====================================================================================
   METHOD StartT120Applet ( _                           ' VTable offset = 136
     BYVAL enApplet AS LONG _                           ' __in RTC_T120_APPLET enApplet
   )                                                    ' void
   ' =====================================================================================
   METHOD StopT120Applets ( _                           ' VTable offset = 140
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET IsT120AppletRunning ( _                 ' VTable offset = 144
     BYVAL enApplet AS LONG _                           ' __in RTC_T120_APPLET enApplet
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRunning
   ' =====================================================================================
   PROPERTY GET LocalUserURI ( _                        ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY SET LocalUserURI ( _                        ' VTable offset = 152
     BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalUserName ( _                       ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   PROPERTY SET LocalUserName ( _                       ' VTable offset = 160
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayRing ( _                                  ' VTable offset = 164
     BYVAL enType AS LONG _                             ' __in RTC_RING_TYPE enType
   , BYVAL bPlay AS INTEGER _                           ' __in VARIANT_BOOL bPlay
   )                                                    ' void
   ' =====================================================================================
   METHOD SendDTMF ( _                                  ' VTable offset = 168
     BYVAL enDTMF AS LONG _                             ' __in RTC_DTMF enDTMF
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeTuningWizard ( _                        ' VTable offset = 172
     BYVAL hwndParent AS DWORD _                        ' __in OAHWND hwndParent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTuned ( _                             ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfTuned
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCClient2 Methods
   ' =====================================================================================
   PROPERTY SET AnswerMode ( _                          ' VTable offset = 180
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   , BYVAL enMode AS LONG _                             ' __in RTC_ANSWER_MODE enMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AnswerMode ( _                          ' VTable offset = 184
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   ) AS LONG                                            ' __retval_out RTC_ANSWER_MODE *penMode
   ' =====================================================================================
   METHOD InvokeTuningWizardEx ( _                      ' VTable offset = 188
     BYVAL hwndParent AS DWORD _                        ' __in OAHWND hwndParent
   , BYVAL fAllowAudio AS INTEGER _                     ' __in VARIANT_BOOL fAllowAudio
   , BYVAL fAllowVideo AS INTEGER _                     ' __in VARIANT_BOOL fAllowVideo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version ( _                             ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *plVersion
   ' =====================================================================================
   PROPERTY SET ClientName ( _                          ' VTable offset = 196
     BYVAL bstrClientName AS WSTRING _                  ' __in BSTR bstrClientName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ClientCurVer ( _                        ' VTable offset = 200
     BYVAL bstrClientCurVer AS WSTRING _                ' __in BSTR bstrClientCurVer
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeEx ( _                              ' VTable offset = 204
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateSessionWithDescription ( _              ' VTable offset = 208
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   , BYVAL bstrSessionDescription AS WSTRING _          ' __in BSTR bstrSessionDescription
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession2
   ' =====================================================================================
   METHOD SetSessionDescriptionManager ( _              ' VTable offset = 212
     BYVAL pSessionDescriptionManager AS IRTCSessionDescriptionManager _ ' __in IRTCSessionDescriptionManager *pSessionDescriptionManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PreferredSecurityLevel ( _              ' VTable offset = 216
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   , BYVAL enSecurityLevel AS LONG _                    ' __in RTC_SECURITY_LEVEL enSecurityLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredSecurityLevel ( _              ' VTable offset = 220
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   ) AS LONG                                            ' __retval_out RTC_SECURITY_LEVEL *penSecurityLevel
   ' =====================================================================================
   PROPERTY SET AllowedPorts ( _                        ' VTable offset = 224
     BYVAL lTransport AS LONG _                         ' __in long lTransport
   , BYVAL enListenMode AS LONG _                       ' __in RTC_LISTEN_MODE enListenMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowedPorts ( _                        ' VTable offset = 228
     BYVAL lTransport AS LONG _                         ' __in long lTransport
   ) AS LONG                                            ' __retval_out RTC_LISTEN_MODE *penListenMode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClient2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClientPresence interface
' IID = 11C3CBCC-0744-42D1-968A-51AA1BB274C6
' Inherited interface = IRTCClient
' ########################################################################################

#IF NOT %DEF(%IRTCClientPresence_INTERFACE_DEFINED)
    %IRTCClientPresence_INTERFACE_DEFINED = 1

INTERFACE IRTCClientPresence $IID_IRTCClientPresence

   INHERIT IAutomation

   ' =====================================================================================
   METHOD EnablePresence ( _                            ' VTable offset = 12
     BYVAL fUseStorage AS INTEGER _                     ' __in VARIANT_BOOL fUseStorage
   , BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   )                                                    ' void
   ' =====================================================================================
   METHOD Export ( _                                    ' VTable offset = 16
     BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   )                                                    ' void
   ' =====================================================================================
   METHOD Import ( _                                    ' VTable offset = 20
     BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   , BYVAL fReplaceAll AS INTEGER _                     ' __in VARIANT_BOOL fReplaceAll
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateBuddies ( _                          ' VTable offset = 24
   ) AS IRTCEnumBuddies                                 ' __retval_out IRTCEnumBuddies **ppEnum
   ' =====================================================================================
   PROPERTY GET Buddies ( _                             ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Buddy ( _                               ' VTable offset = 32
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   ) AS IRTCBuddy                                       ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================
   METHOD AddBuddy ( _                                  ' VTable offset = 36
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCBuddy                                       ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================
   METHOD RemoveBuddy ( _                               ' VTable offset = 40
     BYVAL pBuddy AS IRTCBuddy _                        ' __in IRTCBuddy *pBuddy
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateWatchers ( _                         ' VTable offset = 44
   ) AS IRTCEnumWatchers                                ' __retval_out IRTCEnumWatchers **ppEnum
   ' =====================================================================================
   PROPERTY GET Watchers ( _                            ' VTable offset = 48
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Watcher ( _                             ' VTable offset = 52
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================
   METHOD AddWatcher ( _                                ' VTable offset = 56
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL fBlocked AS INTEGER _                        ' __in VARIANT_BOOL fBlocked
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================
   METHOD RemoveWatcher ( _                             ' VTable offset = 60
     BYVAL pWatcher AS IRTCWatcher _                    ' __in IRTCWatcher *pWatcher
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLocalPresenceInfo ( _                      ' VTable offset = 64
     BYVAL enStatus AS LONG _                           ' __in RTC_PRESENCE_STATUS enStatus
   , BYVAL bstrNotes AS WSTRING _                       ' __in BSTR bstrNotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfferWatcherMode ( _                    ' VTable offset = 68
   ) AS LONG                                            ' __retval_out RTC_OFFER_WATCHER_MODE *penMode
   ' =====================================================================================
   PROPERTY SET OfferWatcherMode ( _                    ' VTable offset = 72
     BYVAL enMode AS LONG _                             ' __in RTC_OFFER_WATCHER_MODE enMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivacyMode ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out RTC_PRIVACY_MODE *penMode
   ' =====================================================================================
   PROPERTY SET PrivacyMode ( _                         ' VTable offset = 80
     BYVAL enMode AS LONG _                             ' __in RTC_PRIVACY_MODE enMode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientPresence_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClientPresence2 interface
' IID = AD1809E8-62F7-4783-909A-29C9D2CB1D34
' Inherited interface = IRTCClientPresence
' ########################################################################################

#IF NOT %DEF(%IRTCClientPresence2_INTERFACE_DEFINED)
    %IRTCClientPresence2_INTERFACE_DEFINED = 1

INTERFACE IRTCClientPresence2 $IID_IRTCClientPresence2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCClientPresence Methods
   ' =====================================================================================
   METHOD EnablePresence ( _                            ' VTable offset = 12
     BYVAL fUseStorage AS INTEGER _                     ' __in VARIANT_BOOL fUseStorage
   , BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   )                                                    ' void
   ' =====================================================================================
   METHOD Export ( _                                    ' VTable offset = 16
     BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   )                                                    ' void
   ' =====================================================================================
   METHOD Import ( _                                    ' VTable offset = 20
     BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   , BYVAL fReplaceAll AS INTEGER _                     ' __in VARIANT_BOOL fReplaceAll
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateBuddies ( _                          ' VTable offset = 24
   ) AS IRTCEnumBuddies                                 ' __retval_out IRTCEnumBuddies **ppEnum
   ' =====================================================================================
   PROPERTY GET Buddies ( _                             ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Buddy ( _                               ' VTable offset = 32
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   ) AS IRTCBuddy                                       ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================
   METHOD AddBuddy ( _                                  ' VTable offset = 36
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCBuddy                                       ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================
   METHOD RemoveBuddy ( _                               ' VTable offset = 40
     BYVAL pBuddy AS IRTCBuddy _                        ' __in IRTCBuddy *pBuddy
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateWatchers ( _                         ' VTable offset = 44
   ) AS IRTCEnumWatchers                                ' __retval_out IRTCEnumWatchers **ppEnum
   ' =====================================================================================
   PROPERTY GET Watchers ( _                            ' VTable offset = 48
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Watcher ( _                             ' VTable offset = 52
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================
   METHOD AddWatcher ( _                                ' VTable offset = 56
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL fBlocked AS INTEGER _                        ' __in VARIANT_BOOL fBlocked
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================
   METHOD RemoveWatcher ( _                             ' VTable offset = 60
     BYVAL pWatcher AS IRTCWatcher _                    ' __in IRTCWatcher *pWatcher
   )                                                    ' void
   ' =====================================================================================
   METHOD SetLocalPresenceInfo ( _                      ' VTable offset = 64
     BYVAL enStatus AS LONG _                           ' __in RTC_PRESENCE_STATUS enStatus
   , BYVAL bstrNotes AS WSTRING _                       ' __in BSTR bstrNotes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OfferWatcherMode ( _                    ' VTable offset = 68
   ) AS LONG                                            ' __retval_out RTC_OFFER_WATCHER_MODE *penMode
   ' =====================================================================================
   PROPERTY SET OfferWatcherMode ( _                    ' VTable offset = 72
     BYVAL enMode AS LONG _                             ' __in RTC_OFFER_WATCHER_MODE enMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivacyMode ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out RTC_PRIVACY_MODE *penMode
   ' =====================================================================================
   PROPERTY SET PrivacyMode ( _                         ' VTable offset = 80
     BYVAL enMode AS LONG _                             ' __in RTC_PRIVACY_MODE enMode
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCClientPresence2 Methods
   ' =====================================================================================
   METHOD EnablePresenceEx ( _                          ' VTable offset = 84
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL varStorage AS VARIANT _                      ' __in VARIANT varStorage
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD DisablePresence ( _                           ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD AddGroup ( _                                  ' VTable offset = 92
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCBuddyGroup                                  ' __retval_out IRTCBuddyGroup **ppGroup
   ' =====================================================================================
   METHOD RemoveGroup ( _                               ' VTable offset = 96
     BYVAL pGroup AS IRTCBuddyGroup _                   ' __in IRTCBuddyGroup *pGroup
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateGroups ( _                           ' VTable offset = 100
   ) AS IRTCEnumGroups                                  ' __retval_out IRTCEnumGroups **ppEnum
   ' =====================================================================================
   PROPERTY GET Groups ( _                              ' VTable offset = 104
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Group ( _                               ' VTable offset = 108
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   ) AS IRTCBuddyGroup                                  ' __retval_out IRTCBuddyGroup **ppGroup
   ' =====================================================================================
   METHOD AddWatcherEx ( _                              ' VTable offset = 112
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL enState AS LONG _                            ' __in RTC_WATCHER_STATE enState
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   , BYVAL enScope AS LONG _                            ' __in RTC_ACE_SCOPE enScope
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCWatcher2                                    ' __retval_out IRTCWatcher2 **ppWatcher
   ' =====================================================================================
   PROPERTY GET WatcherEx ( _                           ' VTable offset = 116
     BYVAL enMode AS LONG _                             ' __in RTC_WATCHER_MATCH_MODE enMode
   , BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   ) AS IRTCWatcher2                                    ' __retval_out IRTCWatcher2 **ppWatcher
   ' =====================================================================================
   PROPERTY SET PresenceProperty ( _                    ' VTable offset = 120
     BYVAL enProperty AS LONG _                         ' __in RTC_PRESENCE_PROPERTY enProperty
   , BYVAL bstrProperty AS WSTRING _                    ' __in BSTR bstrProperty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PresenceProperty ( _                    ' VTable offset = 124
     BYVAL enProperty AS LONG _                         ' __in RTC_PRESENCE_PROPERTY enProperty
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProperty
   ' =====================================================================================
   METHOD SetPresenceData ( _                           ' VTable offset = 128
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPresenceData ( _                           ' VTable offset = 132
     BYREF pbstrNamespace AS WSTRING _                  ' __out BSTR *pbstrNamespace
   , BYREF pbstrData AS WSTRING _                       ' __out BSTR *pbstrData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetLocalPresenceInfo ( _                      ' VTable offset = 136
     BYREF penStatus AS LONG _                          ' __out RTC_PRESENCE_STATUS *penStatus
   , BYREF pbstrNotes AS WSTRING _                      ' __out BSTR *pbstrNotes
   )                                                    ' void
   ' =====================================================================================
   METHOD AddBuddyEx ( _                                ' VTable offset = 140
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   , BYVAL enSubscriptionType AS LONG _                 ' __in RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS IRTCBuddy2                                      ' __retval_out IRTCBuddy2 **ppBuddy
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientPresence2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClientProvisioning interface
' IID = B9F5CF06-65B9-4A80-A0E6-73CAE3EF3822
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCClientProvisioning_INTERFACE_DEFINED)
    %IRTCClientProvisioning_INTERFACE_DEFINED = 1

INTERFACE IRTCClientProvisioning $IID_IRTCClientProvisioning

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateProfile ( _                             ' VTable offset = 12
     BYVAL bstrProfileXML AS WSTRING _                  ' __in BSTR bstrProfileXML
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   METHOD EnableProfile ( _                             ' VTable offset = 16
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lRegisterFlags AS LONG _                     ' __in long lRegisterFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableProfile ( _                            ' VTable offset = 20
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateProfiles ( _                         ' VTable offset = 24
   ) AS IRTCEnumProfiles                                ' __retval_out IRTCEnumProfiles **ppEnum
   ' =====================================================================================
   PROPERTY GET Profiles ( _                            ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   METHOD GetProfile ( _                                ' VTable offset = 32
     BYVAL bstrUserAccount AS WSTRING _                 ' __in BSTR bstrUserAccount
   , BYVAL bstrUserPassword AS WSTRING _                ' __in BSTR bstrUserPassword
   , BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   , BYVAL bstrServer AS WSTRING _                      ' __in BSTR bstrServer
   , BYVAL lTransport AS LONG _                         ' __in long lTransport
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET SessionCapabilities ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSupportedSessions
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientProvisioning_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClientProvisioning2 interface
' IID = A70909B5-F40E-4587-BB75-E6BC0845023E
' Inherited interface = IRTCClientProvisioning
' ########################################################################################

#IF NOT %DEF(%IRTCClientProvisioning2_INTERFACE_DEFINED)
    %IRTCClientProvisioning2_INTERFACE_DEFINED = 1

INTERFACE IRTCClientProvisioning2 $IID_IRTCClientProvisioning2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCClientProvisioning Methods
   ' =====================================================================================
   METHOD CreateProfile ( _                             ' VTable offset = 12
     BYVAL bstrProfileXML AS WSTRING _                  ' __in BSTR bstrProfileXML
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   METHOD EnableProfile ( _                             ' VTable offset = 16
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lRegisterFlags AS LONG _                     ' __in long lRegisterFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableProfile ( _                            ' VTable offset = 20
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateProfiles ( _                         ' VTable offset = 24
   ) AS IRTCEnumProfiles                                ' __retval_out IRTCEnumProfiles **ppEnum
   ' =====================================================================================
   PROPERTY GET Profiles ( _                            ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   METHOD GetProfile ( _                                ' VTable offset = 32
     BYVAL bstrUserAccount AS WSTRING _                 ' __in BSTR bstrUserAccount
   , BYVAL bstrUserPassword AS WSTRING _                ' __in BSTR bstrUserPassword
   , BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   , BYVAL bstrServer AS WSTRING _                      ' __in BSTR bstrServer
   , BYVAL lTransport AS LONG _                         ' __in long lTransport
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET SessionCapabilities ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSupportedSessions
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCClientProvisioning2 methods
   ' =====================================================================================
   METHOD EnableProfileEx ( _                           ' VTable offset = 40
     BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lRegisterFlags AS LONG _                     ' __in long lRegisterFlags
   , BYVAL lRoamingFlags AS LONG _                      ' __in long lRoamingFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientProvisioning2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCProfile interface
' IID = D07ECA9E-4062-4DD4-9E7D-722A49BA7303
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCProfile_INTERFACE_DEFINED)
    %IRTCProfile_INTERFACE_DEFINED = 1

INTERFACE IRTCProfile $IID_IRTCProfile

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Key ( _                                 ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET XML ( _                                 ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrXML
   ' =====================================================================================
   PROPERTY GET ProviderName ( _                        ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET ProviderURI ( _                         ' VTable offset = 28
     BYVAL enURI AS LONG _                              ' __in RTC_PROVIDER_URI enURI
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrURI
   ' =====================================================================================
   PROPERTY GET ProviderData ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY GET ClientName ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET ClientBanner ( _                        ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfBanner
   ' =====================================================================================
   PROPERTY GET ClientMinVer ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMinVer
   ' =====================================================================================
   PROPERTY GET ClientCurVer ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCurVer
   ' =====================================================================================
   PROPERTY GET ClientUpdateURI ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUpdateURI
   ' =====================================================================================
   PROPERTY GET ClientData ( _                          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY GET UserURI ( _                             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY GET UserName ( _                            ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   PROPERTY GET UserAccount ( _                         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserAccount
   ' =====================================================================================
   METHOD SetCredentials ( _                            ' VTable offset = 72
     BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   , BYVAL bstrUserAccount AS WSTRING _                 ' __in BSTR bstrUserAccount
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SessionCapabilities ( _                 ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plSupportedSessions
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out RTC_REGISTRATION_STATE *penState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCProfile_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCProfile2 interface
' IID = 4B81F84E-BDC7-4184-9154-3CB2DD7917FB
' Inherited interface = IRTCProfile
' ########################################################################################

#IF NOT %DEF(%IRTCProfile2_INTERFACE_DEFINED)
    %IRTCProfile2_INTERFACE_DEFINED = 1

INTERFACE IRTCProfile2 $IID_IRTCProfile2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCProfile Methods
   ' =====================================================================================
   PROPERTY GET Key ( _                                 ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrKey
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET XML ( _                                 ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrXML
   ' =====================================================================================
   PROPERTY GET ProviderName ( _                        ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET ProviderURI ( _                         ' VTable offset = 28
     BYVAL enURI AS LONG _                              ' __in RTC_PROVIDER_URI enURI
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrURI
   ' =====================================================================================
   PROPERTY GET ProviderData ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY GET ClientName ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET ClientBanner ( _                        ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfBanner
   ' =====================================================================================
   PROPERTY GET ClientMinVer ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMinVer
   ' =====================================================================================
   PROPERTY GET ClientCurVer ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCurVer
   ' =====================================================================================
   PROPERTY GET ClientUpdateURI ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUpdateURI
   ' =====================================================================================
   PROPERTY GET ClientData ( _                          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY GET UserURI ( _                             ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY GET UserName ( _                            ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   PROPERTY GET UserAccount ( _                         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserAccount
   ' =====================================================================================
   METHOD SetCredentials ( _                            ' VTable offset = 72
     BYVAL bstrUserURI AS WSTRING _                     ' __in BSTR bstrUserURI
   , BYVAL bstrUserAccount AS WSTRING _                 ' __in BSTR bstrUserAccount
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SessionCapabilities ( _                 ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plSupportedSessions
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 80
   ) AS LONG                                            ' __retval_out RTC_REGISTRATION_STATE *penState
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCProfile2 Methods
   ' =====================================================================================
   PROPERTY GET Realm ( _                               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRealm
   ' =====================================================================================
   PROPERTY SET Realm ( _                               ' VTable offset = 88
     BYVAL bstrRealm AS WSTRING _                       ' __in BSTR bstrRealm
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowedAuth ( _                         ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAllowedAuth
   ' =====================================================================================
   PROPERTY SET AllowedAuth ( _                         ' VTable offset = 96
     BYVAL lAllowedAuth AS LONG _                       ' __in long lAllowedAuth
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCProfile2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCSession interface
' IID = 387C8086-99BE-42FB-9973-7C0FC0CA9FA8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCSession_INTERFACE_DEFINED)
    %IRTCSession_INTERFACE_DEFINED = 1

INTERFACE IRTCSession $IID_IRTCSession

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Client ( _                              ' VTable offset = 12
   ) AS IRTCClient                                      ' __retval_out IRTCClient **ppClient
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 16
   ) AS LONG                                            ' __retval_out RTC_SESSION_STATE *penState
   ' =====================================================================================
   PROPERTY GET Type ( _                                ' VTable offset = 20
   ) AS LONG                                            ' __retval_out RTC_SESSION_TYPE *penType
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 24
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   PROPERTY GET Participants ( _                        ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   METHOD Answer ( _                                    ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 36
     BYVAL enReason AS LONG _                           ' __in RTC_TERMINATE_REASON enReason
   )                                                    ' void
   ' =====================================================================================
   METHOD Redirect ( _                                  ' VTable offset = 40
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   , BYVAL bstrLocalPhoneURI AS WSTRING _               ' __in BSTR bstrLocalPhoneURI
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD AddParticipant ( _                            ' VTable offset = 44
     BYVAL bstrAddress AS WSTRING _                     ' __in BSTR bstrAddress
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   METHOD RemoveParticipant ( _                         ' VTable offset = 48
     BYVAL pParticipant AS IRTCParticipant _            ' __in IRTCParticipant *pParticipant
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateParticipants ( _                     ' VTable offset = 52
   ) AS IRTCEnumParticipants                            ' __retval_out IRTCEnumParticipants **ppEnum
   ' =====================================================================================
   PROPERTY GET CanAddParticipants ( _                  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCanAdd
   ' =====================================================================================
   PROPERTY GET RedirectedUserURI ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY GET RedirectedUserName ( _                  ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   METHOD NextRedirectedUser ( _                        ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD SendMessage ( _                               ' VTable offset = 72
     BYVAL bstrMessageHeader AS WSTRING _               ' __in BSTR bstrMessageHeader
   , BYVAL bstrMessage AS WSTRING _                     ' __in BSTR bstrMessage
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD SendMessageStatus ( _                         ' VTable offset = 76
     BYVAL enUserStatus AS LONG _                       ' __in RTC_MESSAGING_USER_STATUS enUserStatus
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStream ( _                                 ' VTable offset = 80
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveStream ( _                              ' VTable offset = 84
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EncryptionKey ( _                       ' VTable offset = 88
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL EncryptionKey AS WSTRING _                   ' __in BSTR EncryptionKey
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSession_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCSession2 interface
' IID = 17D7CDFC-B007-484C-99D2-86A8A820991D
' Inherited interface = IRTCSession
' ########################################################################################

#IF NOT %DEF(%IRTCSession2_INTERFACE_DEFINED)
    %IRTCSession2_INTERFACE_DEFINED = 1

INTERFACE IRTCSession2 $IID_IRTCSession2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCSession Methods
   ' =====================================================================================
   PROPERTY GET Client ( _                              ' VTable offset = 12
   ) AS IRTCClient                                      ' __retval_out IRTCClient **ppClient
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 16
   ) AS LONG                                            ' __retval_out RTC_SESSION_STATE *penState
   ' =====================================================================================
   PROPERTY GET Type ( _                                ' VTable offset = 20
   ) AS LONG                                            ' __retval_out RTC_SESSION_TYPE *penType
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 24
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   PROPERTY GET Participants ( _                        ' VTable offset = 28
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   METHOD Answer ( _                                    ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 36
     BYVAL enReason AS LONG _                           ' __in RTC_TERMINATE_REASON enReason
   )                                                    ' void
   ' =====================================================================================
   METHOD Redirect ( _                                  ' VTable offset = 40
     BYVAL enType AS LONG _                             ' __in RTC_SESSION_TYPE enType
   , BYVAL bstrLocalPhoneURI AS WSTRING _               ' __in BSTR bstrLocalPhoneURI
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD AddParticipant ( _                            ' VTable offset = 44
     BYVAL bstrAddress AS WSTRING _                     ' __in BSTR bstrAddress
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   METHOD RemoveParticipant ( _                         ' VTable offset = 48
     BYVAL pParticipant AS IRTCParticipant _            ' __in IRTCParticipant *pParticipant
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateParticipants ( _                     ' VTable offset = 52
   ) AS IRTCEnumParticipants                            ' __retval_out IRTCEnumParticipants **ppEnum
   ' =====================================================================================
   PROPERTY GET CanAddParticipants ( _                  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCanAdd
   ' =====================================================================================
   PROPERTY GET RedirectedUserURI ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY GET RedirectedUserName ( _                  ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserName
   ' =====================================================================================
   METHOD NextRedirectedUser ( _                        ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD SendMessage ( _                               ' VTable offset = 72
     BYVAL bstrMessageHeader AS WSTRING _               ' __in BSTR bstrMessageHeader
   , BYVAL bstrMessage AS WSTRING _                     ' __in BSTR bstrMessage
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD SendMessageStatus ( _                         ' VTable offset = 76
     BYVAL enUserStatus AS LONG _                       ' __in RTC_MESSAGING_USER_STATUS enUserStatus
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStream ( _                                 ' VTable offset = 80
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveStream ( _                              ' VTable offset = 84
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EncryptionKey ( _                       ' VTable offset = 88
     BYVAL lMediaType AS LONG _                         ' __in long lMediaType
   , BYVAL EncryptionKey AS WSTRING _                   ' __in BSTR EncryptionKey
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCSession2 Methods
   ' =====================================================================================
   METHOD SendInfo ( _                                  ' VTable offset = 92
     BYVAL bstrInfoHeader AS WSTRING _                  ' __in BSTR bstrInfoHeader
   , BYVAL bstrInfo AS WSTRING _                        ' __in BSTR bstrInfo
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PreferredSecurityLevel ( _              ' VTable offset = 96
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   , BYVAL enSecurityLevel AS LONG _                    ' __in RTC_SECURITY_LEVEL enSecurityLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredSecurityLevel ( _              ' VTable offset = 100
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   ) AS LONG                                            ' __retval_out RTC_SECURITY_LEVEL *penSecurityLevel
   ' =====================================================================================
   METHOD IsSecurityEnabled ( _                         ' VTable offset = 104
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSecurityEnabled
   ' =====================================================================================
   METHOD AnswerWithSessionDescription ( _              ' VTable offset = 108
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   , BYVAL bstrSessionDescription AS WSTRING _          ' __in BSTR bstrSessionDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD ReInviteWithSessionDescription ( _            ' VTable offset = 112
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   , BYVAL bstrSessionDescription AS WSTRING _          ' __in BSTR bstrSessionDescription
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSession2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCSessionCallControl interface
' IID = E9A50D94-190B-4F82-9530-3B8EBF60758A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCSessionCallControl_INTERFACE_DEFINED)
    %IRTCSessionCallControl_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionCallControl $IID_IRTCSessionCallControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Hold ( _                                      ' VTable offset = 12
     BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD UnHold ( _                                    ' VTable offset = 16
     BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD Forward ( _                                   ' VTable offset = 20
     BYVAL bstrForwardToURI AS WSTRING _                ' __in BSTR bstrForwardToURI
   )                                                    ' void
   ' =====================================================================================
   METHOD Refer ( _                                     ' VTable offset = 24
     BYVAL bstrReferToURI AS WSTRING _                  ' __in BSTR bstrReferToURI
   , BYVAL bstrReferCookie AS WSTRING _                 ' __in BSTR bstrReferCookie
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ReferredByURI ( _                       ' VTable offset = 28
     BYVAL bstrReferredByURI AS WSTRING _               ' __in BSTR bstrReferredByURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReferredByURI ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReferredByURI
   ' =====================================================================================
   PROPERTY SET ReferCookie ( _                         ' VTable offset = 36
     BYVAL bstrReferCookie AS WSTRING _                 ' __in BSTR bstrReferCookie
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReferCookie ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReferCookie
   ' =====================================================================================
   PROPERTY GET IsReferred ( _                          ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsReferred
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionCallControl_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCParticipant interface
' IID = AE86ADD5-26B1-4414-AF1D-B94CD938D739
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCParticipant_INTERFACE_DEFINED)
    %IRTCParticipant_INTERFACE_DEFINED = 1

INTERFACE IRTCParticipant $IID_IRTCParticipant

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET UserURI ( _                             ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUserURI
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Removable ( _                           ' VTable offset = 20
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRemovable
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 24
   ) AS LONG                                            ' __retval_out RTC_PARTICIPANT_STATE *penState
   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCParticipant_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCRoamingEvent interface
' IID = 79960A6B-0CB1-4DC8-A805-7318E99902E8
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCRoamingEvent_INTERFACE_DEFINED)
    %IRTCRoamingEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCRoamingEvent $IID_IRTCRoamingEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out RTC_ROAMING_EVENT_TYPE *pEventType
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 32
   ) AS IRTCProfile2                                    ' __retval_out IRTCProfile2 **ppProfile
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCRoamingEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCProfileEvent interface
' IID = D6D5AB3B-770E-43E8-800A-79B062395FCA
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCProfileEvent_INTERFACE_DEFINED)
    %IRTCProfileEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCProfileEvent $IID_IRTCProfileEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 28
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   PROPERTY GET Cookie ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG_PTR *plCookie
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCProfileEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCProfileEvent2 interface
' IID = 62E56EDC-03FA-4121-94FB-23493FD0AE64
' Inherited interface = IRTCProfileEvent
' ########################################################################################

#IF NOT %DEF(%IRTCProfileEvent2_INTERFACE_DEFINED)
    %IRTCProfileEvent2_INTERFACE_DEFINED = 1

INTERFACE IRTCProfileEvent2 $IID_IRTCProfileEvent2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 28
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   PROPERTY GET Cookie ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG_PTR *plCookie
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out RTC_PROFILE_EVENT_TYPE *pEventType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCProfileEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCClientEvent interface
' IID = 2B493B7A-3CBA-4170-9C8B-76A9DACDD644
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCClientEvent_INTERFACE_DEFINED)
    %IRTCClientEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCClientEvent $IID_IRTCClientEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out RTC_CLIENT_EVENT_TYPE *penEventType
   ' =====================================================================================
   PROPERTY GET Client ( _                              ' VTable offset = 32
   ) AS IRTCClient                                      ' __retval_out IRTCClient **ppClient
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCRegistrationStateChangeEvent interface
' IID = 62D0991B-50AB-4F02-B948-CA94F26F8F95
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED)
    %IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCRegistrationStateChangeEvent $IID_IRTCRegistrationStateChangeEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 28
   ) AS IRTCProfile                                     ' __retval_out IRTCProfile **ppProfile
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_REGISTRATION_STATE *penState
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' IRTCSessionStateChangeEvent interface
' IID = B5BAD703-5952-48B3-9321-7F4500521506
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCSessionStateChangeEvent_INTERFACE_DEFINED)
    %IRTCSessionStateChangeEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionStateChangeEvent $IID_IRTCSessionStateChangeEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_SESSION_STATE *penState
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionStateChangeEvent2
' IID = {4F933171-6F95-4880-80D9-2EC8D495D261}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IRTCSessionStateChangeEvent
' ########################################################################################

#IF NOT %DEF(%IRTCSessionStateChangeEvent2_INTERFACE_DEFINED)
    %IRTCSessionStateChangeEvent2_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionStateChangeEvent2 $IID_IRTCSessionStateChangeEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IRTCSessionStateChangeEvent Methods
   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_SESSION_STATE *penState
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCSessionStateChangeEvent2 Methods
   ' =====================================================================================
   PROPERTY GET MediaTypes ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pMediaTypes
   ' =====================================================================================
   PROPERTY GET RemotePreferredSecurityLevel ( _        ' VTable offset = 48
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   ) AS LONG                                            ' __retval_out RTC_SECURITY_LEVEL *penSecurityLevel
   ' =====================================================================================
   PROPERTY GET IsForked ( _                            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsForked
   ' =====================================================================================
   METHOD GetRemoteSessionDescription ( _               ' VTable offset = 56
     BYREF pbstrContentType AS WSTRING _                ' __out BSTR *pbstrContentType
   , BYREF pbstrSessionDescription AS WSTRING _         ' __out BSTR *pbstrSessionDescription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionOperationCompleteEvent
' IID = {A6BFF4C0-F7C8-4D3C-9A41-3550F78A95B0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED)
    %IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionOperationCompleteEvent $IID_IRTCSessionOperationCompleteEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY GET Cookie ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG_PTR *plCookie
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionOperationCompleteEvent2
' IID = {F6FC2A9B-D5BC-4241-B436-1B8460C13832}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IRTCSessionOperationCompleteEvent
' ########################################################################################

#IF NOT %DEF(%IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED)
    %IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionOperationCompleteEvent2 $IID_IRTCSessionOperationCompleteEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IRTCSessionOperationCompleteEvent Methods
   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY GET Cookie ( _                              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG_PTR *plCookie
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCSessionOperationCompleteEvent2 Methods
   ' =====================================================================================
   PROPERTY GET Participant ( _                         ' VTable offset = 44
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   METHOD GetRemoteSessionDescription ( _               ' VTable offset = 48
     BYREF pbstrContentType AS WSTRING _                ' __out BSTR *pbstrContentType
   , BYREF pbstrSessionDescription AS WSTRING _         ' __out BSTR *pbstrSessionDescription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCParticipantStateChangeEvent
' IID = {09BCB597-F0FA-48F9-B420-468CEA7FDE04}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCParticipantStateChangeEvent_INTERFACE_DEFINED)
    %IRTCParticipantStateChangeEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCParticipantStateChangeEvent $IID_IRTCParticipantStateChangeEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Participant ( _                         ' VTable offset = 28
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_PARTICIPANT_STATE *penState
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCMediaEvent
' IID = {099944FB-BCDA-453E-8C41-E13DA2ADF7F3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCMediaEvent_INTERFACE_DEFINED)
    %IRTCMediaEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCMediaEvent $IID_IRTCMediaEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MediaType ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pMediaType
   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_MEDIA_EVENT_TYPE *penEventType
   ' =====================================================================================
   PROPERTY GET EventReason ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out RTC_MEDIA_EVENT_REASON *penEventReason
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCMediaEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCIntensityEvent
' IID = {4C23BF51-390C-4992-A41D-41EEC05B2A4B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCIntensityEvent_INTERFACE_DEFINED)
    %IRTCIntensityEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCIntensityEvent $IID_IRTCIntensityEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Level ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plLevel
   ' =====================================================================================
   PROPERTY GET Min ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plMin
   ' =====================================================================================
   PROPERTY GET Max ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMax
   ' =====================================================================================
   PROPERTY GET Direction ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out RTC_AUDIO_DEVICE *penDirection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCIntensityEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCMessagingEvent
' IID = {D3609541-1B29-4DE5-A4AD-5AEBAF319512}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCMessagingEvent_INTERFACE_DEFINED)
    %IRTCMessagingEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCMessagingEvent $IID_IRTCMessagingEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession                                     ' __retval_out IRTCSession **ppSession
   ' =====================================================================================
   PROPERTY GET Participant ( _                         ' VTable offset = 32
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out RTC_MESSAGING_EVENT_TYPE <enum>
   ' =====================================================================================
   PROPERTY GET Message ( _                             ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMessage
   ' =====================================================================================
   PROPERTY GET MessageHeader ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMessageHeader
   ' =====================================================================================
   PROPERTY GET UserStatus ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out RTC_MESSAGING_USER_STATUS *penUserStatus
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCMessagingEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddyEvent
' IID = {F36D755D-17E6-404E-954F-0FC07574C78D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCBuddyEvent_INTERFACE_DEFINED)
    %IRTCBuddyEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddyEvent $IID_IRTCBuddyEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Buddy ( _                                ' VTable offset = 28
   ) AS IRTCBuddy                                        ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddyEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddyEvent2
' IID = {484A7F1E-73F0-4990-BFC2-60BC3978A720}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IRTCBuddyEvent
' ########################################################################################

#IF NOT %DEF(%IRTCBuddyEvent2_INTERFACE_DEFINED)
    %IRTCBuddyEvent2_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddyEvent2 $IID_IRTCBuddyEvent2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Buddy ( _                               ' VTable offset = 28
   ) AS IRTCBuddy                                       ' __retval_out IRTCBuddy **ppBuddy
   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_BUDDY_EVENT_TYPE *pEventType
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddyEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCWatcherEvent
' IID = {F30D7261-587A-424F-822C-312788F43548}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCWatcherEvent_INTERFACE_DEFINED)
    %IRTCWatcherEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCWatcherEvent $IID_IRTCWatcherEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Watcher ( _                             ' VTable offset = 28
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCWatcherEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCWatcherEvent2
' IID = {E52891E8-188C-49AF-B005-98ED13F83F9C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IRTCWatcherEvent
' ########################################################################################

#IF NOT %DEF(%IRTCWatcherEvent2_INTERFACE_DEFINED)
    %IRTCWatcherEvent2_INTERFACE_DEFINED = 1

INTERFACE IRTCWatcherEvent2 $IID_IRTCWatcherEvent2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Watcher ( _                             ' VTable offset = 28
   ) AS IRTCWatcher                                     ' __retval_out IRTCWatcher **ppWatcher
   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_WATCHER_EVENT_TYPE *pEventType
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCWatcherEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddyGroupEvent
' IID = {3A79E1D1-B736-4414-96F8-BBC7F08863E4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCBuddyGroupEvent_INTERFACE_DEFINED)
    %IRTCBuddyGroupEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddyGroupEvent $IID_IRTCBuddyGroupEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventType ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out RTC_GROUP_EVENT_TYPE *pEventType
   ' =====================================================================================
   PROPERTY GET Group ( _                               ' VTable offset = 32
   ) AS IRTCBuddyGroup                                  ' __retval_out IRTCBuddyGroup **ppGroup
   ' =====================================================================================
   PROPERTY GET Buddy ( _                               ' VTable offset = 36
   ) AS IRTCBuddy2                                      ' __retval_out IRTCBuddy2 **ppBuddy
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddyGroupEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCInfoEvent
' IID = {4E1D68AE-1912-4F49-B2C3-594FADFD425F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCInfoEvent_INTERFACE_DEFINED)
    %IRTCInfoEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCInfoEvent $IID_IRTCInfoEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession
   ' =====================================================================================
   PROPERTY GET Participant ( _                         ' VTable offset = 32
   ) AS IRTCParticipant                                 ' __retval_out IRTCParticipant **ppParticipant
   ' =====================================================================================
   PROPERTY GET Info ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInfo
   ' =====================================================================================
   PROPERTY GET InfoHeader ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrInfoHeader
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCInfoEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCMediaRequestEvent
' IID = {52572D15-148C-4D97-A36C-2DA55C289D63}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCMediaRequestEvent_INTERFACE_DEFINED)
    %IRTCMediaRequestEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCMediaRequestEvent $IID_IRTCMediaRequestEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession
   ' =====================================================================================
   PROPERTY GET ProposedMedia ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   PROPERTY GET CurrentMedia ( _                        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plMediaTypes
   ' =====================================================================================
   METHOD Accept ( _                                    ' VTable offset = 40
     BYVAL lMediaTypes AS LONG _                        ' __in long lMediaTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemotePreferredSecurityLevel ( _        ' VTable offset = 44
     BYVAL enSecurityType AS LONG _                     ' __in RTC_SECURITY_TYPE enSecurityType
   ) AS LONG                                            ' __retval_out RTC_SECURITY_LEVEL *penSecurityLevel
   ' =====================================================================================
   METHOD Reject ( _                                    ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 52
   ) AS LONG                                            ' __retval_out RTC_REINVITE_STATE *pState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCMediaRequestEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCReInviteEvent
' IID = {11558D84-204C-43E7-99B0-2034E9417F7D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCReInviteEvent_INTERFACE_DEFINED)
    %IRTCReInviteEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCReInviteEvent $IID_IRTCReInviteEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession2
   ' =====================================================================================
   METHOD Accept ( _                                    ' VTable offset = 32
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   , BYVAL bstrSessionDescription AS WSTRING _          ' __in BSTR bstrSessionDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD Reject ( _                                    ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 40
   ) AS LONG                                            ' __retval_out RTC_REINVITE_STATE *pState
   ' =====================================================================================
   METHOD GetRemoteSessionDescription ( _               ' VTable offset = 44
     BYREF pbstrContentType AS WSTRING _                ' __out BSTR *pbstrContentType
   , BYREF pbstrSessionDescription AS WSTRING _         ' __out BSTR *pbstrSessionDescription
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCReInviteEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPresencePropertyEvent
' IID = {F777F570-A820-49D5-86BD-E099493F1518}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCPresencePropertyEvent_INTERFACE_DEFINED)
    %IRTCPresencePropertyEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCPresencePropertyEvent $IID_IRTCPresencePropertyEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================
   PROPERTY GET PresenceProperty ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out RTC_PRESENCE_PROPERTY *penPresProp
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPresencePropertyEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPresenceDataEvent
' IID = {38F0E78C-8B87-4C04-A82D-AEDD83C909BB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCPresenceDataEvent_INTERFACE_DEFINED)
    %IRTCPresenceDataEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCPresenceDataEvent $IID_IRTCPresenceDataEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================
   METHOD GetPresenceData ( _                           ' VTable offset = 36
     BYREF pbstrNamespace AS WSTRING _                  ' __out BSTR *pbstrNamespace
   , BYREF pbstrData AS WSTRING _                       ' __out BSTR *pbstrData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPresenceDataEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPresenceStatusEvent
' IID = {78673F32-4A0F-462C-89AA-EE7706707678}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCPresenceStatusEvent_INTERFACE_DEFINED)
    %IRTCPresenceStatusEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCPresenceStatusEvent $IID_IRTCPresenceStatusEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================
   METHOD GetLocalPresenceInfo ( _                      ' VTable offset = 36
     BYREF penStatus AS LONG _                          ' __out RTC_PRESENCE_STATUS *penStatus
   , BYREF pbstrNotes AS WSTRING _                      ' __out BSTR *pbstrNotes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPresenceStatusEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCCollection
' IID = {EC7C8096-B918-4044-94F1-E4FBA0361D5C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCCollection_INTERFACE_DEFINED)
    %IRTCCollection_INTERFACE_DEFINED = 1

INTERFACE IRTCCollection $IID_IRTCCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD NewEnum_ ( _                                  ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppNewEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumParticipants
' IID = {FCD56F29-4A4F-41B2-BA5C-F5BCCC060BF6}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumParticipants_INTERFACE_DEFINED)
    %IRTCEnumParticipants_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumParticipants $IID_IRTCEnumParticipants

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCParticipant _              ' __out IRTCParticipant **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumParticipants                            ' __retval_out IRTCEnumParticipants **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumParticipants_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumProfiles
' IID = {29B7C41C-ED82-4BCA-84AD-39D5101B58E3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumProfiles_INTERFACE_DEFINED)
    %IRTCEnumProfiles_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumProfiles $IID_IRTCEnumProfiles

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCProfile _                  ' __out IRTCProfile **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumProfiles                                ' __retval_out IRTCEnumProfiles **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumProfiles_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumBuddies
' IID = {F7296917-5569-4B3B-B3AF-98D1144B2B87}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumBuddies_INTERFACE_DEFINED)
    %IRTCEnumBuddies_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumBuddies $IID_IRTCEnumBuddies

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCBuddy _                    ' __out IRTCBuddy **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumBuddies                                 ' __retval_out IRTCEnumBuddies **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumBuddies_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumWatchers
' IID = {A87D55D7-DB74-4ED1-9CA4-77A0E41B413E}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumWatchers_INTERFACE_DEFINED)
    %IRTCEnumWatchers_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumWatchers $IID_IRTCEnumWatchers

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCWatcher _                  ' __out IRTCWatcher **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumWatchers                                ' __retval_out IRTCEnumWatchers **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumWatchers_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumGroups
' IID = {742378D6-A141-4415-8F27-35D99076CF5D}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumGroups_INTERFACE_DEFINED)
    %IRTCEnumGroups_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumGroups $IID_IRTCEnumGroups

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCBuddyGroup _               ' __out IRTCBuddyGroup **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumGroups                                  ' __retval_out IRTCEnumGroups **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumGroups_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPresenceContact
' IID = {8B22F92C-CD90-42DB-A733-212205C3E3DF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCPresenceContact_INTERFACE_DEFINED)
    %IRTCPresenceContact_INTERFACE_DEFINED = 1

INTERFACE IRTCPresenceContact $IID_IRTCPresenceContact

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET PresentityURI ( _                       ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPresentityURI
   ' =====================================================================================
   PROPERTY SET PresentityURI ( _                       ' VTable offset = 16
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 32
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Persistent ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPersistent
   ' =====================================================================================
   PROPERTY SET Persistent ( _                          ' VTable offset = 40
     BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPresenceContact_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddy
' IID = {FCB136C8-7B90-4E0C-BEFE-56EDF0BA6F1C}
' Inherited interface = IRTCPresenceContact
' ########################################################################################

#IF NOT %DEF(%IRTCBuddy_INTERFACE_DEFINED)
    %IRTCBuddy_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddy $IID_IRTCBuddy

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET PresentityURI ( _                       ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPresentityURI
   ' =====================================================================================
   PROPERTY SET PresentityURI ( _                       ' VTable offset = 16
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 32
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Persistent ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPersistent
   ' =====================================================================================
   PROPERTY SET Persistent ( _                          ' VTable offset = 40
     BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status ( _                              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out RTC_PRESENCE_STATUS *penStatus
   ' =====================================================================================
   PROPERTY GET Notes ( _                               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNotes
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddy2
' IID = {102F9588-23E7-40E3-954D-CD7A1D5C0361}
' Inherited interface = IRTCBuddy
' ########################################################################################

#IF NOT %DEF(%IRTCBuddy2_INTERFACE_DEFINED)
    %IRTCBuddy2_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddy2 $IID_IRTCBuddy2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCBuddy Methods
   ' =====================================================================================
   PROPERTY GET PresentityURI ( _                       ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPresentityURI
   ' =====================================================================================
   PROPERTY SET PresentityURI ( _                       ' VTable offset = 16
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 32
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Persistent ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPersistent
   ' =====================================================================================
   PROPERTY SET Persistent ( _                          ' VTable offset = 40
     BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status ( _                              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out RTC_PRESENCE_STATUS *penStatus
   ' =====================================================================================
   PROPERTY GET Notes ( _                               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNotes
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCBuddy2 Methods
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 52
   ) AS IRTCProfile2                                    ' __retval_out IRTCProfile2 **ppProfile
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateGroups ( _                           ' VTable offset = 60
   ) AS IRTCEnumGroups                                  ' __retval_out IRTCEnumGroups **ppEnum
   ' =====================================================================================
   PROPERTY GET Groups ( _                              ' VTable offset = 64
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET PresenceProperty ( _                    ' VTable offset = 68
     BYVAL enProperty AS LONG _                         ' __in RTC_PRESENCE_PROPERTY enProperty
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProperty
   ' =====================================================================================
   METHOD EnumeratePresenceDevices ( _                  ' VTable offset = 72
   ) AS IRTCEnumPresenceDevices                         ' __retval_out IRTCEnumPresenceDevices **ppEnumDevices
   ' =====================================================================================
   PROPERTY GET PresenceDevices ( _                     ' VTable offset = 76
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppDevicesCollection
   ' =====================================================================================
   PROPERTY GET SubscriptionType ( _                    ' VTable offset = 80
   ) AS LONG                                            ' __retval_out RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddy2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCWatcher
' IID = {C7CEDAD8-346B-4D1B-AC02-A2088DF9BE4F}
' IRTCWatcher Interface
' Inherited interface = IRTCPresenceContact
' ########################################################################################

#IF NOT %DEF(%IRTCWatcher_INTERFACE_DEFINED)
    %IRTCWatcher_INTERFACE_DEFINED = 1

INTERFACE IRTCWatcher $IID_IRTCWatcher

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET PresentityURI ( _                       ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPresentityURI
   ' =====================================================================================
   PROPERTY SET PresentityURI ( _                       ' VTable offset = 16
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 32
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Persistent ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPersistent
   ' =====================================================================================
   PROPERTY SET Persistent ( _                          ' VTable offset = 40
     BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out RTC_WATCHER_STATE *penState
   ' =====================================================================================
   PROPERTY SET State ( _                               ' VTable offset = 48
     BYVAL enState AS LONG _                            ' __in RTC_WATCHER_STATE enState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCWatcher_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCWatcher2
' IID = {D4D9967F-D011-4B1D-91E3-ABA78F96393D}
' Inherited interface = IRTCWatcher
' ########################################################################################

#IF NOT %DEF(%IRTCWatcher2_INTERFACE_DEFINED)
    %IRTCWatcher2_INTERFACE_DEFINED = 1

INTERFACE IRTCWatcher2 $IID_IRTCWatcher2

   INHERIT IAutomation

   ' =====================================================================================
   ' IRTCWatcher methods
   ' =====================================================================================
   PROPERTY GET PresentityURI ( _                       ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPresentityURI
   ' =====================================================================================
   PROPERTY SET PresentityURI ( _                       ' VTable offset = 16
     BYVAL bstrPresentityURI AS WSTRING _               ' __in BSTR bstrPresentityURI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 24
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 32
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Persistent ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPersistent
   ' =====================================================================================
   PROPERTY SET Persistent ( _                          ' VTable offset = 40
     BYVAL fPersistent AS INTEGER _                     ' __in VARIANT_BOOL fPersistent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 44
   ) AS LONG                                            ' __retval_out RTC_WATCHER_STATE *penState
   ' =====================================================================================
   PROPERTY SET State ( _                               ' VTable offset = 48
     BYVAL enState AS LONG _                            ' __in RTC_WATCHER_STATE enState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IRTCWatcher2 methods
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 52
   ) AS IRTCProfile2                                    ' __retval_out IRTCProfile2 **ppProfile
   ' =====================================================================================
   PROPERTY GET Scope ( _                               ' VTable offset = 56
   ) AS LONG                                            ' __retval_out RTC_ACE_SCOPE *penScope
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCWatcher2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCBuddyGroup
' IID = {60361E68-9164-4389-A4C6-D0B3925BDA5E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCBuddyGroup_INTERFACE_DEFINED)
    %IRTCBuddyGroup_INTERFACE_DEFINED = 1

INTERFACE IRTCBuddyGroup $IID_IRTCBuddyGroup

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGroupName
   ' =====================================================================================
   PROPERTY SET Name ( _                                ' VTable offset = 16
     BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   )                                                    ' void
   ' =====================================================================================
   METHOD AddBuddy ( _                                  ' VTable offset = 20
     BYVAL pBuddy AS IRTCBuddy _                        ' __in IRTCBuddy *pBuddy
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveBuddy ( _                               ' VTable offset = 24
     BYVAL pBuddy AS IRTCBuddy _                        ' __in IRTCBuddy *pBuddy
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateBuddies ( _                          ' VTable offset = 28
   ) AS IRTCEnumBuddies                                 ' __retval_out IRTCEnumBuddies **ppEnum
   ' =====================================================================================
   PROPERTY GET Buddies ( _                             ' VTable offset = 32
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Data ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrData
   ' =====================================================================================
   PROPERTY SET Data ( _                                ' VTable offset = 40
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 44
   ) AS IRTCProfile2                                    ' __retval_out IRTCProfile2 **ppProfile
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCBuddyGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEventNotification
' IID = {13FA24C7-5748-4B21-91F5-7397609CE747}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEventNotification_INTERFACE_DEFINED)
    %IRTCEventNotification_INTERFACE_DEFINED = 1

INTERFACE IRTCEventNotification $IID_IRTCEventNotification

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Event ( _                                     ' VTable offset = 12
     BYVAL RTCEvent AS LONG _                           ' __in RTC_EVENT RTCEvent
   , BYVAL pEvent AS IDispatch _                        ' __in IDispatch *pEvent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEventNotification_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPortManager
' IID = {DA77C14B-6208-43CA-8DDF-5B60A0A69FAC}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCPortManager_INTERFACE_DEFINED)
    %IRTCPortManager_INTERFACE_DEFINED = 1

INTERFACE IRTCPortManager $IID_IRTCPortManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetMapping ( _                                ' VTable offset = 12
     BYVAL bstrRemoteAddress AS WSTRING _               ' __in BSTR bstrRemoteAddress
   , BYVAL enPortType AS LONG _                         ' __in RTC_PORT_TYPE enPortType
   , BYREF pbstrInternalLocalAddress AS WSTRING _       ' __inout BSTR *pbstrInternalLocalAddress
   , BYREF plInternalLocalPort AS LONG _                ' __inout long *plInternalLocalPort
   , BYREF pbstrExternalLocalAddress AS WSTRING _       ' __inout BSTR *pbstrExternalLocalAddress
   , BYREF plExternalLocalPort AS LONG _                ' __inout long *plExternalLocalPort
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateRemoteAddress ( _                       ' VTable offset = 16
     BYVAL bstrRemoteAddress AS WSTRING _               ' __in BSTR bstrRemoteAddress
   , BYVAL bstrInternalLocalAddress AS WSTRING _        ' __in BSTR bstrInternalLocalAddress
   , BYVAL lInternalLocalPort AS LONG _                 ' __in long lInternalLocalPort
   , BYVAL bstrExternalLocalAddress AS WSTRING _        ' __in BSTR bstrExternalLocalAddress
   , BYVAL lExternalLocalPort AS LONG _                 ' __in long lExternalLocalPort
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseMapping ( _                            ' VTable offset = 20
     BYVAL bstrInternalLocalAddress AS WSTRING _        ' __in BSTR bstrInternalLocalAddress
   , BYVAL lInternalLocalPort AS LONG _                 ' __in long lInternalLocalPort
   , BYVAL bstrExternalLocalAddress AS WSTRING _        ' __in BSTR bstrExternalLocalAddress
   , BYVAL lExternalLocalAddress AS LONG _              ' __in long lExternalLocalAddress
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPortManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionPortManagement
' IID = {A072F1D6-0286-4E1F-85F2-17A2948456EC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCSessionPortManagement_INTERFACE_DEFINED)
    %IRTCSessionPortManagement_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionPortManagement $IID_IRTCSessionPortManagement

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetPortManager ( _                            ' VTable offset = 12
     BYVAL pPortManager AS IRTCPortManager _            ' __in IRTCPortManager *pPortManager
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionPortManagement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCClientPortManagement
' IID = {D5DF3F03-4BDE-4417-AEFE-71177BDAEA66}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCClientPortManagement_INTERFACE_DEFINED)
    %IRTCClientPortManagement_INTERFACE_DEFINED = 1

INTERFACE IRTCClientPortManagement $IID_IRTCClientPortManagement

   INHERIT IAutomation

   ' =====================================================================================
   METHOD StartListenAddressAndPort ( _                 ' VTable offset = 12
     BYVAL bstrInternalLocalAddress AS WSTRING _        ' __in BSTR bstrInternalLocalAddress
   , BYVAL lInternalLocalPort AS LONG _                 ' __in long lInternalLocalPort
   )                                                    ' void
   ' =====================================================================================
   METHOD StopListenAddressAndPort ( _                  ' VTable offset = 16
     BYVAL bstrInternalLocalAddress AS WSTRING _        ' __in BSTR bstrInternalLocalAddress
   , BYVAL lInternalLocalPort AS LONG _                 ' __in long lInternalLocalPort
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPortRange ( _                              ' VTable offset = 20
     BYVAL enPortType AS LONG _                         ' __in RTC_PORT_TYPE enPortType
   , BYREF plMinValue AS LONG _                         ' __out long *plMinValue
   , BYREF plMaxValue AS LONG _                         ' __out long *plMaxValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCClientPortManagement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCUserSearch
' IID = {B619882B-860C-4DB4-BE1B-693B6505BBE5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCUserSearch_INTERFACE_DEFINED)
    %IRTCUserSearch_INTERFACE_DEFINED = 1

INTERFACE IRTCUserSearch $IID_IRTCUserSearch

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateQuery ( _                               ' VTable offset = 12
   ) AS IRTCUserSearchQuery                             ' __retval_out IRTCUserSearchQuery **ppQuery
   ' =====================================================================================
   METHOD ExecuteSearch ( _                             ' VTable offset = 16
     BYVAL pQuery AS IRTCUserSearchQuery _              ' __in IRTCUserSearchQuery *pQuery
   , BYVAL pProfile AS IRTCProfile _                    ' __in IRTCProfile *pProfile
   , BYVAL lCookie AS LONG _                            ' __in LONG_PTR lCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCUserSearch_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCUserSearchQuery
' IID = {288300F5-D23A-4365-9A73-9985C98C2881}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCUserSearchQuery_INTERFACE_DEFINED)
    %IRTCUserSearchQuery_INTERFACE_DEFINED = 1

INTERFACE IRTCUserSearchQuery $IID_IRTCUserSearchQuery

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY SET SearchTerm ( _                          ' VTable offset = 12
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SearchTerm ( _                          ' VTable offset = 16
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY GET SearchTerms ( _                         ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNames
   ' =====================================================================================
   PROPERTY SET SearchPreference ( _                    ' VTable offset = 24
     BYVAL enPreference AS LONG _                       ' __in RTC_USER_SEARCH_PREFERENCE enPreference
   , BYVAL lValue AS LONG _                             ' __in long lValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SearchPreference ( _                    ' VTable offset = 28
     BYVAL enPreference AS LONG _                       ' __in RTC_USER_SEARCH_PREFERENCE enPreference
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================
   PROPERTY SET SearchDomain ( _                        ' VTable offset = 32
     BYVAL bstrDomain AS WSTRING _                      ' __in BSTR bstrDomain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SearchDomain ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDomain
   ' =====================================================================================

END INTERFACE


#ENDIF   ' /* __IRTCUserSearchQuery_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCUserSearchResult
' IID = {851278B2-9592-480F-8DB5-2DE86B26B54D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCUserSearchResult_INTERFACE_DEFINED)
    %IRTCUserSearchResult_INTERFACE_DEFINED = 1

INTERFACE IRTCUserSearchResult $IID_IRTCUserSearchResult

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 12
     BYVAL enColumn AS LONG _                           ' __in RTC_USER_SEARCH_COLUMN enColumn
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCUserSearchResult_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumUserSearchResults
' IID = {83D4D877-AA5D-4A5B-8D0E-002A8067E0E8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumUserSearchResults_INTERFACE_DEFINED)
    %IRTCEnumUserSearchResults_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumUserSearchResults $IID_IRTCEnumUserSearchResults

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCUserSearchResult _         ' __out IRTCUserSearchResult **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumUserSearchResults                       ' __retval_out IRTCEnumUserSearchResults **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumUserSearchResults_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCUserSearchResultsEvent
' IID = {D8C8C3CD-7FAC-4088-81C5-C24CBC0938E3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCUserSearchResultsEvent_INTERFACE_DEFINED)
    %IRTCUserSearchResultsEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCUserSearchResultsEvent $IID_IRTCUserSearchResultsEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EnumerateResults ( _                          ' VTable offset = 28
   ) AS IRTCEnumUserSearchResults                       ' __retval_out IRTCEnumUserSearchResults **ppEnum
   ' =====================================================================================
   PROPERTY GET Results ( _                             ' VTable offset = 32
   ) AS IRTCCollection                                  ' __retval_out IRTCCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Profile ( _                             ' VTable offset = 36
   ) AS IRTCProfile2                                    ' __retval_out IRTCProfile2 **ppProfile
   ' =====================================================================================
   PROPERTY GET Query ( _                               ' VTable offset = 40
   ) AS IRTCUserSearchQuery                             ' __retval_out IRTCUserSearchQuery **ppQuery
   ' =====================================================================================
   PROPERTY GET Cookie ( _                              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG_PTR *plCookie
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET MoreAvailable ( _                       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMoreAvailable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionReferStatusEvent
' IID = {3D8FC2CD-5D76-44AB-BB68-2A80353B34A2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCSessionReferStatusEvent_INTERFACE_DEFINED)
    %IRTCSessionReferStatusEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionReferStatusEvent $IID_IRTCSessionReferStatusEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession
   ' =====================================================================================
   PROPERTY GET ReferStatus ( _                         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out RTC_SESSION_REFER_STATUS *penReferStatus
   ' =====================================================================================
   PROPERTY GET StatusCode ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plStatusCode
   ' =====================================================================================
   PROPERTY GET StatusText ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrStatusText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionReferredEvent
' IID = {176A6828-4FCC-4F28-A862-04597A6CF1C4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCSessionReferredEvent_INTERFACE_DEFINED)
    %IRTCSessionReferredEvent_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionReferredEvent $IID_IRTCSessionReferredEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 28
   ) AS IRTCSession2                                    ' __retval_out IRTCSession2 **ppSession
   ' =====================================================================================
   PROPERTY GET ReferredByURI ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReferredByURI
   ' =====================================================================================
   PROPERTY GET ReferToURI ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReferoURI
   ' =====================================================================================
   PROPERTY GET ReferCookie ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReferCookie
   ' =====================================================================================
   METHOD Accept ( _                                    ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Reject ( _                                    ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD SetReferredSessionState ( _                   ' VTable offset = 52
     BYVAL enState AS LONG _                            ' __in RTC_SESSION_STATE enState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionReferredEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCSessionDescriptionManager
' IID = {BA7F518E-D336-4070-93A6-865395C843F9}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCSessionDescriptionManager_INTERFACE_DEFINED)
    %IRTCSessionDescriptionManager_INTERFACE_DEFINED = 1

INTERFACE IRTCSessionDescriptionManager $IID_IRTCSessionDescriptionManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD EvaluateSessionDescription ( _                ' VTable offset = 12
     BYVAL bstrContentType AS WSTRING _                 ' __in BSTR bstrContentType
   , BYVAL bstrSessionDescription AS WSTRING _          ' __in BSTR bstrSessionDescription
   , BYREF pfApplicationSession AS INTEGER _            ' __inout VARIANT_BOOL *pfApplicationSession
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCSessionDescriptionManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCEnumPresenceDevices
' IID = {708C2AB7-8BF8-42F8-8C7D-635197AD5539}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCEnumPresenceDevices_INTERFACE_DEFINED)
    %IRTCEnumPresenceDevices_INTERFACE_DEFINED = 1

INTERFACE IRTCEnumPresenceDevices $IID_IRTCEnumPresenceDevices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF ppElements AS IRTCPresenceDevice _           ' __out IRTCPresenceDevice **ppElements
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
   ) AS IRTCEnumPresenceDevices                         ' __retval_out IRTCEnumPresenceDevices **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCEnumPresenceDevices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRTCPresenceDevice
' IID = {BC6A90DD-AD9A-48DA-9B0C-2515E38521AD}
' IRTCPresenceDevice Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRTCPresenceDevice_INTERFACE_DEFINED)
    %IRTCPresenceDevice_INTERFACE_DEFINED = 1

INTERFACE IRTCPresenceDevice $IID_IRTCPresenceDevice

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Status ( _                              ' VTable offset = 12
   ) AS LONG                                            ' __retval_out RTC_PRESENCE_STATUS *penStatus
   ' =====================================================================================
   PROPERTY GET Notes ( _                               ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNotes
   ' =====================================================================================
   PROPERTY GET PresenceProperty ( _                    ' VTable offset = 20
     BYVAL enProperty AS LONG _                         ' __in RTC_PRESENCE_PROPERTY enProperty
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProperty
   ' =====================================================================================
   METHOD GetPresenceData ( _                           ' VTable offset = 24
     BYREF pbstrNamespace AS WSTRING _                  ' __out BSTR *pbstrNamespace
   , BYREF pbstrData AS WSTRING _                       ' __out BSTR *pbstrData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRTCPresenceDevice_INTERFACE_DEFINED__ */


#IF NOT %DEF(%RTCCORELib_LIBRARY_DEFINED)
    %RTCCORELib_LIBRARY_DEFINED = 1

$LIBID_RTCCORELib = GUID$("{CD260094-DE10-4AEE-AC73-EF87F6E12683}")

' ########################################################################################
' IRTCDispatchEventNotification interface
' IID = 176DDFBE-FEC0-4D55-BC87-84CFF1EF7F91
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRTCDispatchEventNotification_DISPINTERFACE_DEFINED)
    %IRTCDispatchEventNotification_DISPINTERFACE_DEFINED = 1

INTERFACE IRTCDispatchEventNotification $IID_IRTCDispatchEventNotification

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__ */

$CLSID_RTCClient = GUID$("{7A42EA29-A2B7-40C4-B091-F6F024AA89BE}")

#ENDIF   ' /* __RTCCORELib_LIBRARY_DEFINED__ */
