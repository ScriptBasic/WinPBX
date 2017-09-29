' ########################################################################################
' Microsoft Windows
' File: MbnApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MbnApi
' Version: 1.0, Locale ID = 0
' Documentation string: Definition: UCM Extension API for MBN Type Library
' Library GUID: {DCBBBAB6-0001-4BBB-AAEE-338E368AF6FA}
' ########################################################################################

#INCLUDE THIS ONCE
%MBNAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_MbnApi = GUID$("{DCBBBAB6-0001-4BBB-AAEE-338E368AF6FA}")

' ########################################################################################
' Interface name = IDummyMBNUCMExt
' IID = DCBBBAB6-FFFF-4BBB-AAEE-338E368AF6FA
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDummyMBNUCMExt_INTERFACE_DEFINED)
    %IDummyMBNUCMExt_INTERFACE_DEFINED = 1

$IID_IDummyMBNUCMExt = GUID$("{DCBBBAB6-FFFF-4BBB-AAEE-338E368AF6FA}")

INTERFACE IDummyMBNUCMExt $IID_IDummyMBNUCMExt

   INHERIT IDispatch

END INTERFACE

#ENDIF   '   /* __IDummyMBNUCMExt_INTERFACE_DEFINED__ */

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MbnConnectionManager = GUID$("{BDFEE05C-4418-11DD-90ED-001C257CCFF1}")
$CLSID_MbnConnectionProfileManager = GUID$("{BDFEE05A-4418-11DD-90ED-001C257CCFF1}")
$CLSID_MbnInterfaceManager = GUID$("{BDFEE05B-4418-11DD-90ED-001C257CCFF1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IMbnConnection = GUID$("{DCBBBAB6-200D-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionContext = GUID$("{DCBBBAB6-200B-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionContextEvents = GUID$("{DCBBBAB6-200C-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionEvents = GUID$("{DCBBBAB6-200E-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionManager = GUID$("{DCBBBAB6-201D-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionManagerEvents = GUID$("{DCBBBAB6-201E-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionProfile = GUID$("{DCBBBAB6-2010-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionProfileEvents = GUID$("{DCBBBAB6-2011-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionProfileManager = GUID$("{DCBBBAB6-200F-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnConnectionProfileManagerEvents = GUID$("{DCBBBAB6-201F-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnInterface = GUID$("{DCBBBAB6-2001-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnInterfaceEvents = GUID$("{DCBBBAB6-2002-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnInterfaceManager = GUID$("{DCBBBAB6-201B-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnInterfaceManagerEvents = GUID$("{DCBBBAB6-201C-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnPin = GUID$("{DCBBBAB6-2007-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnPinEvents = GUID$("{DCBBBAB6-2008-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnPinManager = GUID$("{DCBBBAB6-2005-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnPinManagerEvents = GUID$("{DCBBBAB6-2006-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnRadio = GUID$("{DCCCCAB6-201F-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnRadioEvents = GUID$("{DCDDDAB6-201F-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnRegistration = GUID$("{DCBBBAB6-2009-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnRegistrationEvents = GUID$("{DCBBBAB6-200A-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnServiceActivation = GUID$("{DCBBBAB6-2017-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnServiceActivationEvents = GUID$("{DCBBBAB6-2018-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSignal = GUID$("{DCBBBAB6-2003-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSignalEvents = GUID$("{DCBBBAB6-2004-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSms = GUID$("{DCBBBAB6-2015-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSmsConfiguration = GUID$("{DCBBBAB6-2012-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSmsEvents = GUID$("{DCBBBAB6-2016-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSmsReadMsgPdu = GUID$("{DCBBBAB6-2013-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSmsReadMsgTextCdma = GUID$("{DCBBBAB6-2014-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnSubscriberInformation = GUID$("{459ECC43-BCF5-11DC-A8A8-001321F1405F}")
$IID_IMbnVendorSpecificEvents = GUID$("{DCBBBAB6-201A-4BBB-AAEE-338E368AF6FA}")
$IID_IMbnVendorSpecificOperation = GUID$("{DCBBBAB6-2019-4BBB-AAEE-338E368AF6FA}")

' ========================================================================================
' MBN_CELLULAR_CLASS enum
' IID: {DCBBBAB6-6002-4BBB-AAEE-338E368AF6FA}
' Supported cellular technology classes
' ========================================================================================

%MBN_CELLULAR_CLASS_NONE                                = 0???
%MBN_CELLULAR_CLASS_GSM                                 = &H1???
%MBN_CELLULAR_CLASS_CDMA                                = &H2???

' ========================================================================================
' MBN_DATA_CLASS enum
' IID: {83A34F4C-BDC4-11DC-A8A8-001321F1405F}
' ========================================================================================

%MBN_DATA_CLASS_NONE                                    = 0???
%MBN_DATA_CLASS_GPRS                                    = &H1???
%MBN_DATA_CLASS_EDGE                                    = &H2???
%MBN_DATA_CLASS_UMTS                                    = &H4???
%MBN_DATA_CLASS_HSDPA                                   = &H8???
%MBN_DATA_CLASS_HSUPA                                   = &H10???
%MBN_DATA_CLASS_LTE                                     = &H20???
%MBN_DATA_CLASS_1XRTT                                   = &H10000???
%MBN_DATA_CLASS_1XEVDO                                  = &H20000???
%MBN_DATA_CLASS_1XEVDO_REVA                             = &H40000???
%MBN_DATA_CLASS_1XEVDV                                  = &H80000???
%MBN_DATA_CLASS_3XRTT                                   = &H100000???
%MBN_DATA_CLASS_1XEVDO_REVB                             = &H200000???
%MBN_DATA_CLASS_UMB                                     = &H400000???
%MBN_DATA_CLASS_CUSTOM                                  = &H80000000???

' ========================================================================================
' MBN_BAND_CLASS enum
' IID: {5DB6A98B-BDC5-11DC-A8A8-001321F1405F}
' ========================================================================================

%MBN_BAND_CLASS_NONE                                    = 0???
%MBN_BAND_CLASS_0                                       = &H1???
%MBN_BAND_CLASS_I                                       = &H2???
%MBN_BAND_CLASS_II                                      = &H4???
%MBN_BAND_CLASS_III                                     = &H8???
%MBN_BAND_CLASS_IV                                      = &H10???
%MBN_BAND_CLASS_V                                       = &H20???
%MBN_BAND_CLASS_VI                                      = &H40???
%MBN_BAND_CLASS_VII                                     = &H80???
%MBN_BAND_CLASS_VIII                                    = &H100???
%MBN_BAND_CLASS_IX                                      = &H200???
%MBN_BAND_CLASS_X                                       = &H400???
%MBN_BAND_CLASS_XI                                      = &H800???
%MBN_BAND_CLASS_XII                                     = &H1000???
%MBN_BAND_CLASS_XIII                                    = &H2000???
%MBN_BAND_CLASS_XIV                                     = &H4000???
%MBN_BAND_CLASS_XV                                      = &H8000???
%MBN_BAND_CLASS_XVI                                     = &H10000???
%MBN_BAND_CLASS_XVII                                    = &H20000???
%MBN_BAND_CLASS_CUSTOM                                  = &H80000000???

' ========================================================================================
' MBN_VOICE_CLASS enum
' IID: {DCBBBAB6-6012-4BBB-AAEE-338E368AF6FA}
' Voice classes
' ========================================================================================

%MBN_VOICE_CLASS_NONE                                   = 0???
%MBN_VOICE_CLASS_NO_VOICE                               = &H1???
%MBN_VOICE_CLASS_SEPARATE_VOICE_DATA                    = &H2???
%MBN_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA                = &H3???

' ========================================================================================
' MBN_CTRL_CAPS enum
' IID: {2308C1F7-BDC8-11DC-A8A8-001321F1405F}
' CTRL Caps
' ========================================================================================

%MBN_CTRL_CAPS_NONE                                     = 0???
%MBN_CTRL_CAPS_REG_MANUAL                               = &H1???
%MBN_CTRL_CAPS_HW_RADIO_SWITCH                          = &H2???
%MBN_CTRL_CAPS_CDMA_MOBILE_IP                           = &H4???
%MBN_CTRL_CAPS_CDMA_SIMPLE_IP                           = &H8???
%MBN_CTRL_CAPS_PROTECT_UNIQUEID                         = &H10???

' ========================================================================================
' MBN_SMS_CAPS enum
' IID: {E4096459-BDC8-11DC-A8A8-001321F1405F}
' SMS Caps
' ========================================================================================

%MBN_SMS_CAPS_NONE                                      = 0???
%MBN_SMS_CAPS_PDU_RECEIVE                               = &H1???
%MBN_SMS_CAPS_PDU_SEND                                  = &H2???
%MBN_SMS_CAPS_TEXT_RECEIVE                              = &H4???
%MBN_SMS_CAPS_TEXT_SEND                                 = &H8???

' ========================================================================================
' MBN_INTERFACE_CAPS_CONSTANTS enum
' IID: {59C235E7-BDC9-11DC-A8A8-001321F1405F}
' Interface Caps Constants Type
' ========================================================================================

%MBN_DEVICEID_LEN                                       = 18
%MBN_MANUFACTURER_LEN                                   = 32
%MBN_MODEL_LEN                                          = 32
%MBN_FIRMWARE_LEN                                       = 32

' ========================================================================================
' MBN_INTERFACE_CAPS record
' IID = {CD1A4B17-BDC9-11DC-A8A8-001321F1405F}
' ========================================================================================

' // Size = 52 bytes
TYPE MBN_INTERFACE_CAPS DWORD
   cellularClass   AS LONG          ' MBN_CELLULAR_CLASS
   voiceClass      AS LONG          ' MBN_VOICE_CLASS
   dataClass       AS DWORD         ' ULONG
   customDataClass AS WSTRING PTR   ' BSTR
   gsmBandClass    AS DWORD         ' ULONG
   cdmaBandClass   AS DWORD         ' ULONG
   customBandClass AS WSTRING PTR   ' BSTR
   smsCaps         AS DWORD         ' ULONG
   controlCaps     AS DWORD         ' ULONG
   deviceID        AS WSTRING PTR   ' BSTR
   manufacturer    AS WSTRING PTR   ' BSTR
   model           AS WSTRING PTR   ' BSTR
   firmwareInfo    AS WSTRING PTR   ' BSTR
END TYPE

' ========================================================================================
' MBN_READY_STATE enum
' IID: {DCBBBAB6-6003-4BBB-AAEE-338E368AF6FA}
' Device Ready states
' ========================================================================================

%MBN_READY_STATE_OFF              = 0
%MBN_READY_STATE_INITIALIZED      = %MBN_READY_STATE_OFF              + 1
%MBN_READY_STATE_SIM_NOT_INSERTED = %MBN_READY_STATE_INITIALIZED      + 1
%MBN_READY_STATE_BAD_SIM          = %MBN_READY_STATE_SIM_NOT_INSERTED + 1
%MBN_READY_STATE_FAILURE          = %MBN_READY_STATE_BAD_SIM          + 1
%MBN_READY_STATE_NOT_ACTIVATED    = %MBN_READY_STATE_FAILURE          + 1
%MBN_READY_STATE_DEVICE_LOCKED    = %MBN_READY_STATE_NOT_ACTIVATED    + 1
%MBN_READY_STATE_DEVICE_BLOCKED   = %MBN_READY_STATE_DEVICE_LOCKED    + 1

' ========================================================================================
' MBN_PROVIDER_STATE enum
' IID: {6E1348BB-BDCB-11DC-A8A8-001321F1405F}
' Provider States
' ========================================================================================

%MBN_PROVIDER_STATE_NONE                                = 0???
%MBN_PROVIDER_STATE_HOME                                = &H1???
%MBN_PROVIDER_STATE_FORBIDDEN                           = &H2???
%MBN_PROVIDER_STATE_PREFERRED                           = &H4???
%MBN_PROVIDER_STATE_VISIBLE                             = &H8???
%MBN_PROVIDER_STATE_REGISTERED                          = &H10???

' ========================================================================================
' MBN_PROVIDER_CONSTANTS enum
' IID: {934092FD-BDCB-11DC-A8A8-001321F1405F}
' Provider Constants Type
' ========================================================================================

%MBN_PROVIDERNAME_LEN                                   = 20
%MBN_PROVIDERID_LEN                                     = 6

' ========================================================================================
' MBN_PROVIDER record
' IID = {DCBBBAB6-9005-4BBB-AAEE-338E368AF6FA}
' ========================================================================================

' // Size = 16 bytes
TYPE MBN_PROVIDER DWORD
   providerID    AS WSTRING PTR   ' BSTR
   providerState AS DWORD         ' ULONG
   providerName  AS WSTRING PTR   ' BSTR
   dataClass     AS DWORD         ' ULONG
END TYPE

' ========================================================================================
' MBN_SIGNAL_CONSTANTS enum
' IID: {42FAAC0B-BDCC-11DC-A8A8-001321F1405F}
' Signal Constants Type
' ========================================================================================

%MBN_RSSI_DEFAULT                                       = &HFFFFFFFF???
%MBN_RSSI_DISABLE                                       = 0
%MBN_RSSI_UNKNOWN                                       = 99
%MBN_ERROR_RATE_UNKNOWN                                 = 99

' ========================================================================================
' MBN_PIN_TYPE enum
' IID: {DCBBBAB6-6005-4BBB-AAEE-338E368AF6FA}
' Device Pin (Password) types
' ========================================================================================

%MBN_PIN_TYPE_NONE                 = 0
%MBN_PIN_TYPE_CUSTOM               = %MBN_PIN_TYPE_NONE                 + 1
%MBN_PIN_TYPE_PIN1                 = %MBN_PIN_TYPE_CUSTOM               + 1
%MBN_PIN_TYPE_PIN2                 = %MBN_PIN_TYPE_PIN1                 + 1
%MBN_PIN_TYPE_DEVICE_SIM_PIN       = %MBN_PIN_TYPE_PIN2                 + 1
%MBN_PIN_TYPE_DEVICE_FIRST_SIM_PIN = %MBN_PIN_TYPE_DEVICE_SIM_PIN       + 1
%MBN_PIN_TYPE_NETWORK_PIN          = %MBN_PIN_TYPE_DEVICE_FIRST_SIM_PIN + 1
%MBN_PIN_TYPE_NETWORK_SUBSET_PIN   = %MBN_PIN_TYPE_NETWORK_PIN          + 1
%MBN_PIN_TYPE_SVC_PROVIDER_PIN     = %MBN_PIN_TYPE_NETWORK_SUBSET_PIN   + 1
%MBN_PIN_TYPE_CORPORATE_PIN        = %MBN_PIN_TYPE_SVC_PROVIDER_PIN     + 1
%MBN_PIN_TYPE_SUBSIDY_LOCK         = %MBN_PIN_TYPE_CORPORATE_PIN        + 1

' ========================================================================================
' MBN_PIN_MODE enum
' IID: {BD8A2871-BDCD-11DC-A8A8-001321F1405F}
' Pin modes
' ========================================================================================

%MBN_PIN_MODE_ENABLED  = 1
%MBN_PIN_MODE_DISABLED = %MBN_PIN_MODE_ENABLED + 1

' ========================================================================================
' MBN_PIN_FORMAT enum
' IID: {C2A93665-BDCD-11DC-A8A8-001321F1405F}
' Pin Formats
' ========================================================================================

%MBN_PIN_FORMAT_NONE         = 0
%MBN_PIN_FORMAT_NUMERIC      = %MBN_PIN_FORMAT_NONE    + 1
%MBN_PIN_FORMAT_ALPHANUMERIC = %MBN_PIN_FORMAT_NUMERIC + 1

' ========================================================================================
' MBN_PIN_CONSTANTS enum
' IID: {C75E76F5-BDCD-11DC-A8A8-001321F1405F}
' Pin Constants Type
' ========================================================================================

%MBN_ATTEMPTS_REMAINING_UNKNOWN                         = &HFFFFFFFF???
%MBN_PIN_LENGTH_UNKNOWN                                 = &HFFFFFFFF???

' ========================================================================================
' MBN_PIN_STATE enum
' IID: {D11BD29D-BDCD-11DC-A8A8-001321F1405F}
' Pin States
' ========================================================================================

%MBN_PIN_STATE_NONE    = 0
%MBN_PIN_STATE_ENTER   = %MBN_PIN_STATE_NONE  + 1
%MBN_PIN_STATE_UNBLOCK = %MBN_PIN_STATE_ENTER + 1

' ========================================================================================
' MBN_PIN_INFO record
' IID = {DCBBBAB6-9006-4BBB-AAEE-338E368AF6FA}
' ========================================================================================

' // Size = 12 bytes
TYPE MBN_PIN_INFO DWORD
   pinState          AS LONG    ' MBN_PIN_STATE
   pinType           AS LONG    ' MBN_PIN_TYPE
   attemptsRemaining AS DWORD   ' ULONG
END TYPE

' ========================================================================================
' MBN_REGISTRATION_CONSTANTS enum
' IID: {D5F1726B-BDCE-11DC-A8A8-001321F1405F}
' Registration Constants
' ========================================================================================

%MBN_ROAMTEXT_LEN                                       = 64
%MBN_CDMA_DEFAULT_PROVIDER_ID                           = 0

' ========================================================================================
' MBN_REGISTER_STATE enum
' IID: {DCBBBAB6-6009-4BBB-AAEE-338E368AF6FA}
' Network Registration States
' ========================================================================================

%MBN_REGISTER_STATE_NONE         = 0
%MBN_REGISTER_STATE_DEREGISTERED = %MBN_REGISTER_STATE_NONE         + 1
%MBN_REGISTER_STATE_SEARCHING    = %MBN_REGISTER_STATE_DEREGISTERED + 1
%MBN_REGISTER_STATE_HOME         = %MBN_REGISTER_STATE_SEARCHING    + 1
%MBN_REGISTER_STATE_ROAMING      = %MBN_REGISTER_STATE_HOME         + 1
%MBN_REGISTER_STATE_PARTNER      = %MBN_REGISTER_STATE_ROAMING      + 1
%MBN_REGISTER_STATE_DENIED       = %MBN_REGISTER_STATE_PARTNER      + 1

' ========================================================================================
' MBN_REGISTER_MODE enum
' IID: {D7F73F35-BDCD-11DC-A8A8-001321F1405F}
' Registration modes
' ========================================================================================

%MBN_REGISTER_MODE_NONE      = 0
%MBN_REGISTER_MODE_AUTOMATIC = %MBN_REGISTER_MODE_NONE      + 1
%MBN_REGISTER_MODE_MANUAL    = %MBN_REGISTER_MODE_AUTOMATIC + 1

' ========================================================================================
' MBN_CONTEXT_CONSTANTS enum
' IID: {0E62803F-BDD0-11DC-A8A8-001321F1405F}
' Context Constants Type
' ========================================================================================

%MBN_ACCESSSTRING_LEN                                   = 100
%MBN_USERNAME_LEN                                       = 255
%MBN_PASSWORD_LEN                                       = 255
%MBN_CONTEXT_ID_APPEND                                  = &HFFFFFFFF???

' ========================================================================================
' MBN_AUTH_PROTOCOL enum
' IID: {E24B42EF-BDCD-11DC-A8A8-001321F1405F}
' Authentication Protocol Types
' ========================================================================================

%MBN_AUTH_PROTOCOL_NONE     = 0
%MBN_AUTH_PROTOCOL_PAP      = %MBN_AUTH_PROTOCOL_NONE + 1
%MBN_AUTH_PROTOCOL_CHAP     = %MBN_AUTH_PROTOCOL_PAP  + 1
%MBN_AUTH_PROTOCOL_MSCHAPV2 = %MBN_AUTH_PROTOCOL_CHAP + 1

' ========================================================================================
' MBN_COMPRESSION enum
' IID: {E6A360B9-BDCD-11DC-A8A8-001321F1405F}
' Compression Mode
' ========================================================================================

%MBN_COMPRESSION_NONE   = 0
%MBN_COMPRESSION_ENABLE = %MBN_COMPRESSION_NONE + 1

' ========================================================================================
' MBN_CONTEXT_TYPE enum
' IID: {EB4731EB-BDCD-11DC-A8A8-001321F1405F}
' Connection Context Types
' ========================================================================================

%MBN_CONTEXT_TYPE_NONE        = 0
%MBN_CONTEXT_TYPE_INTERNET    = %MBN_CONTEXT_TYPE_NONE        + 1
%MBN_CONTEXT_TYPE_VPN         = %MBN_CONTEXT_TYPE_INTERNET    + 1
%MBN_CONTEXT_TYPE_VOICE       = %MBN_CONTEXT_TYPE_VPN         + 1
%MBN_CONTEXT_TYPE_VIDEO_SHARE = %MBN_CONTEXT_TYPE_VOICE       + 1
%MBN_CONTEXT_TYPE_CUSTOM      = %MBN_CONTEXT_TYPE_VIDEO_SHARE + 1

' ========================================================================================
' MBN_CONTEXT record
' IID = {FE1F7B6F-BDCD-11DC-A8A8-001321F1405F}
' ========================================================================================

' // Size = 28 bytes
TYPE MBN_CONTEXT DWORD
   contextID    AS DWORD         ' ULONG
   contextType  AS LONG          ' MBN_CONTEXT_TYPE
   accessString AS WSTRING PTR   ' BSTR
   userName     AS WSTRING PTR   ' BSTR
   password     AS WSTRING PTR   ' BSTR
   compression  AS LONG          ' MBN_COMPRESSION
   authType     AS LONG          ' MBN_AUTH_PROTOCOL
END TYPE

' ========================================================================================
' MBN_ACTIVATION_STATE enum
' IID: {EFB7C00D-BDCD-11DC-A8A8-001321F1405F}
' Activation States
' ========================================================================================

%MBN_ACTIVATION_STATE_NONE         = 0
%MBN_ACTIVATION_STATE_ACTIVATED    = %MBN_ACTIVATION_STATE_NONE        + 1
%MBN_ACTIVATION_STATE_ACTIVATING   = %MBN_ACTIVATION_STATE_ACTIVATED   + 1
%MBN_ACTIVATION_STATE_DEACTIVATED  = %MBN_ACTIVATION_STATE_ACTIVATING  + 1
%MBN_ACTIVATION_STATE_DEACTIVATING = %MBN_ACTIVATION_STATE_DEACTIVATED + 1

' ========================================================================================
' MBN_CONNECTION_MODE enum
' IID: {F601E1EB-BDCD-11DC-A8A8-001321F1405F}
' Connection Modes
' ========================================================================================

%MBN_CONNECTION_MODE_PROFILE     = 0
%MBN_CONNECTION_MODE_TMP_PROFILE = %MBN_CONNECTION_MODE_PROFILE + 1

' ========================================================================================
' MBN_VOICE_CALL_STATE enum
' IID: {6D8846E5-BDD1-11DC-A8A8-001321F1405F}
' Voice Call States
' ========================================================================================

%MBN_VOICE_CALL_STATE_NONE        = 0
%MBN_VOICE_CALL_STATE_IN_PROGRESS = %MBN_VOICE_CALL_STATE_NONE        + 1
%MBN_VOICE_CALL_STATE_HANGUP      = %MBN_VOICE_CALL_STATE_IN_PROGRESS + 1

' ========================================================================================
' WWAEXT_SMS_CONSTANTS enum <alias> MBN_SMS_CONSTANTS
' SMS Constants Type
' ========================================================================================

%MBN_MESSAGE_INDEX_NONE                                 = 0
%MBN_CDMA_SHORT_MSG_SIZE_UNKNOWN                        = 0
%MBN_CDMA_SHORT_MSG_SIZE_MAX                            = 160

' ========================================================================================
' MBN_MSG_STATUS enum
' IID: {FC208FC1-BDE5-11DC-A8A8-001321F1405F}
' Message Status Types
' ========================================================================================

%MBN_MSG_STATUS_NEW   = 0
%MBN_MSG_STATUS_OLD   = %MBN_MSG_STATUS_NEW   + 1
%MBN_MSG_STATUS_DRAFT = %MBN_MSG_STATUS_OLD   + 1
%MBN_MSG_STATUS_SENT  = %MBN_MSG_STATUS_DRAFT + 1

' ========================================================================================
' MBN_SMS_CDMA_LANG enum
' IID: {29912B29-BDD4-11DC-A8A8-001321F1405F}
' SMS CDMA Language Types
' ========================================================================================

%MBN_SMS_CDMA_LANG_NONE     = 0
%MBN_SMS_CDMA_LANG_ENGLISH  = %MBN_SMS_CDMA_LANG_NONE     + 1
%MBN_SMS_CDMA_LANG_FRENCH   = %MBN_SMS_CDMA_LANG_ENGLISH  + 1
%MBN_SMS_CDMA_LANG_SPANISH  = %MBN_SMS_CDMA_LANG_FRENCH   + 1
%MBN_SMS_CDMA_LANG_JAPANESE = %MBN_SMS_CDMA_LANG_SPANISH  + 1
%MBN_SMS_CDMA_LANG_KOREAN   = %MBN_SMS_CDMA_LANG_JAPANESE + 1
%MBN_SMS_CDMA_LANG_CHINESE  = %MBN_SMS_CDMA_LANG_KOREAN   + 1
%MBN_SMS_CDMA_LANG_HEBREW   = %MBN_SMS_CDMA_LANG_CHINESE  + 1

' ========================================================================================
' MBN_SMS_CDMA_ENCODING enum
' IID: {7F8E74CB-BDD4-11DC-A8A8-001321F1405F}
' SMS CDMA Encoding Types
' ========================================================================================

%MBN_SMS_CDMA_ENCODING_OCTET        = 0
%MBN_SMS_CDMA_ENCODING_EPM          = %MBN_SMS_CDMA_ENCODING_OCTET        + 1
%MBN_SMS_CDMA_ENCODING_7BIT_ASCII   = %MBN_SMS_CDMA_ENCODING_EPM          + 1
%MBN_SMS_CDMA_ENCODING_IA5          = %MBN_SMS_CDMA_ENCODING_7BIT_ASCII   + 1
%MBN_SMS_CDMA_ENCODING_UNICODE      = %MBN_SMS_CDMA_ENCODING_IA5          + 1
%MBN_SMS_CDMA_ENCODING_SHIFT_JIS    = %MBN_SMS_CDMA_ENCODING_UNICODE      + 1
%MBN_SMS_CDMA_ENCODING_KOREAN       = %MBN_SMS_CDMA_ENCODING_SHIFT_JIS    + 1
%MBN_SMS_CDMA_ENCODING_LATIN_HEBREW = %MBN_SMS_CDMA_ENCODING_KOREAN       + 1
%MBN_SMS_CDMA_ENCODING_LATIN        = %MBN_SMS_CDMA_ENCODING_LATIN_HEBREW + 1
%MBN_SMS_CDMA_ENCODING_GSM_7BIT     = %MBN_SMS_CDMA_ENCODING_LATIN        + 1

' ========================================================================================
' MBN_SMS_FLAG enum
' IID: {0D42B514-BDDC-11DC-A8A8-001321F1405F}
' SMS Flags Types
' ========================================================================================

%MBN_SMS_FLAG_ALL   = 0
%MBN_SMS_FLAG_INDEX = %MBN_SMS_FLAG_ALL   + 1
%MBN_SMS_FLAG_NEW   = %MBN_SMS_FLAG_INDEX + 1
%MBN_SMS_FLAG_OLD   = %MBN_SMS_FLAG_NEW   + 1
%MBN_SMS_FLAG_SENT  = %MBN_SMS_FLAG_OLD   + 1
%MBN_SMS_FLAG_DRAFT = %MBN_SMS_FLAG_SENT  + 1

' ========================================================================================
' MBN_SMS_FILTER record
' IID = {406BFD60-BDDC-11DC-A8A8-001321F1405F}
' ========================================================================================

' // Size = 8 bytes
TYPE MBN_SMS_FILTER DWORD
   flag         AS LONG    ' MBN_SMS_FLAG
   messageIndex AS DWORD   ' ULONG
END TYPE

' ========================================================================================
' MBN_SMS_STATUS_FLAG enum
' IID: {8098009D-BDDC-11DC-A8A8-001321F1405F}
' SMS Status Flags Types
' ========================================================================================

%MBN_SMS_FLAG_NONE                                      = 0???
%MBN_SMS_FLAG_MESSAGE_STORE_FULL                        = &H1???
%MBN_SMS_FLAG_NEW_MESSAGE                               = &H2???

' ========================================================================================
' MBN_SMS_STATUS_INFO record
' IID = {1F6E9CA3-BDE6-11DC-A8A8-001321F1405F}
' ========================================================================================

' // Size = 8 bytes
TYPE MBN_SMS_STATUS_INFO DWORD
   flag         AS DWORD   ' ULONG
   messageIndex AS DWORD   ' ULONG
END TYPE

' ========================================================================================
' MBN_SMS_FORMAT enum
' IID: {4B0FE227-3709-41E2-8A78-E98C0CD0CB09}
' SMS Format
' ========================================================================================

%MBN_SMS_FORMAT_NONE                                    = 0???
%MBN_SMS_FORMAT_PDU                                     = &H1???
%MBN_SMS_FORMAT_TEXT                                    = &H2???

' ========================================================================================
' MBN_RADIO enum
' IID: {532A3FE4-BDE6-11DC-A8A8-001321F1405F}
' MBN Radio
' ========================================================================================

%MBN_RADIO_OFF = 0
%MBN_RADIO_ON  = %MBN_RADIO_OFF + 1

' ########################################################################################
' Interface name = IMbnInterface
' IID = {DCBBBAB6-2001-4BBB-AAEE-338E368AF6FA}
' Get/set the runtime configuration of a Wireless WAN interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnInterface_INTERFACE_DEFINED)
    %IMbnInterface_INTERFACE_DEFINED = 1

INTERFACE IMbnInterface $IID_IMbnInterface

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET InterfaceID ( _                         ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *InterfaceID
   ' =====================================================================================
   METHOD GetInterfaceCapability ( _                    ' VTable offset = 16
   ) AS MBN_INTERFACE_CAPS                              ' __retval_out MBN_INTERFACE_CAPS *interfaceCaps
   ' =====================================================================================
   METHOD GetSubscriberInformation ( _                  ' VTable offset = 20
   ) AS IMbnSubscriberInformation                       ' __retval_out IMbnSubscriberInformation **subscriberInformation
   ' =====================================================================================
   METHOD GetReadyState ( _                             ' VTable offset = 24
   ) AS LONG                                            ' __retval_out MBN_READY_STATE *readyState
   ' =====================================================================================
   METHOD InEmergencyMode ( _                           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *emergencyMode
   ' =====================================================================================
   METHOD GetHomeProvider ( _                           ' VTable offset = 32
   ) AS MBN_PROVIDER                                    ' __retval_out MBN_PROVIDER *homeProvider
   ' =====================================================================================
   METHOD GetPreferredProviders ( _                     ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out SAFEARRAY **preferredProviders
   ' =====================================================================================
   METHOD SetPreferredProviders ( _                     ' VTable offset = 40
     BYVAL preferredProviders AS DWORD _                ' __in SAFEARRAY *preferredProviders
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVisibleProviders ( _                       ' VTable offset = 44
     BYREF age AS DWORD _                               ' __out ULONG *age
   ) AS DWORD                                           ' __retval_out SAFEARRAY **visibleProviders
   ' =====================================================================================
   METHOD ScanNetwork ( _                               ' VTable offset = 48
     BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConnection ( _                             ' VTable offset = 52
   ) AS IMbnConnection                                  ' __retval_out IMbnConnection **mbnConnection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnInterface_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSubscriberInformation
' IID = {459ECC43-BCF5-11DC-A8A8-001321F1405F}
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSubscriberInformation_INTERFACE_DEFINED)
    %IMbnSubscriberInformation_INTERFACE_DEFINED = 1

INTERFACE IMbnSubscriberInformation $IID_IMbnSubscriberInformation

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET SubscriberID ( _                        ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *SubscriberID
   ' =====================================================================================
   PROPERTY GET SimIccID ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *SimIccID
   ' =====================================================================================
   PROPERTY GET TelephoneNumbers ( _                    ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out SAFEARRAY **TelephoneNumbers
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSubscriberInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnInterfaceEvents
' IID = {DCBBBAB6-2002-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnInterface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnInterfaceEvents_INTERFACE_DEFINED)
    %IMbnInterfaceEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnInterfaceEvents $IID_IMbnInterfaceEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnInterfaceCapabilityAvailable ( _            ' VTable offset = 12
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSubscriberInformationChange ( _             ' VTable offset = 16
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnReadyStateChange ( _                        ' VTable offset = 20
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnEmergencyModeChange ( _                     ' VTable offset = 24
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnHomeProviderAvailable ( _                   ' VTable offset = 28
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnPreferredProvidersChange ( _                ' VTable offset = 32
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetPreferredProvidersComplete ( _           ' VTable offset = 36
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnScanNetworkComplete ( _                     ' VTable offset = 40
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface*newInterface
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnInterfaceEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSignal
' IID = {DCBBBAB6-2003-4BBB-AAEE-338E368AF6FA}
' Get/set the Wireless WAN device signal quality information
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSignal_INTERFACE_DEFINED)
    %IMbnSignal_INTERFACE_DEFINED = 1

INTERFACE IMbnSignal $IID_IMbnSignal

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSignalStrength ( _                         ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *signalStrength
   ' =====================================================================================
   METHOD GetSignalError ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out ULONG *signalError
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSignal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSignalEvents
' IID = {DCBBBAB6-2004-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnSignal
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSignalEvents_INTERFACE_DEFINED)
    %IMbnSignalEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnSignalEvents $IID_IMbnSignalEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnSignalStateChange ( _                       ' VTable offset = 12
     BYVAL newInterface AS IMbnSignal _                 ' __in IMbnSignal *newInterface
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSignalEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnPinManager
' IID = {DCBBBAB6-2005-4BBB-AAEE-338E368AF6FA}
' Manages different device passwords
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnPinManager_INTERFACE_DEFINED)
    %IMbnPinManager_INTERFACE_DEFINED = 1

INTERFACE IMbnPinManager $IID_IMbnPinManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetPinList ( _                                ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pinList
   ' =====================================================================================
   METHOD GetPin ( _                                    ' VTable offset = 16
     BYVAL pinType AS LONG _                            ' __in MBN_PIN_TYPE pinType
   ) AS IMbnPin                                         ' __retval_out IMbnPin **pin
   ' =====================================================================================
   METHOD GetPinState ( _                               ' VTable offset = 20
     BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnPinManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnPinManagerEvents
' IID = {DCBBBAB6-2006-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnPinManager
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnPinManagerEvents_INTERFACE_DEFINED)
    %IMbnPinManagerEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnPinManagerEvents $IID_IMbnPinManagerEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnPinListAvailable ( _                        ' VTable offset = 12
     BYVAL pinManager AS IMbnPinManager _               ' __in IMbnPinManager *pinManager
   )                                                    ' void
   ' =====================================================================================
   METHOD OnGetPinStateComplete ( _                     ' VTable offset = 16
     BYVAL pinManager AS IMbnPinManager _               ' __in IMbnPinManager *pinManager
   , BYVAL pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnPinManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnPin
' IID = {DCBBBAB6-2007-4BBB-AAEE-338E368AF6FA}
' Pin-related functionality
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnPin_INTERFACE_DEFINED)
    %IMbnPin_INTERFACE_DEFINED = 1

INTERFACE IMbnPin $IID_IMbnPin

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET pinType ( _                             ' VTable offset = 12
   ) AS LONG                                            ' __retval_out MBN_PIN_TYPE *pinType
   ' =====================================================================================
   PROPERTY GET PinFormat ( _                           ' VTable offset = 16
   ) AS LONG                                            ' __retval_out MBN_PIN_FORMAT *PinFormat
   ' =====================================================================================
   PROPERTY GET PinLengthMin ( _                        ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out ULONG *PinLengthMin
   ' =====================================================================================
   PROPERTY GET PinLengthMax ( _                        ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out ULONG *PinLengthMax
   ' =====================================================================================
   PROPERTY GET PinMode ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out MBN_PIN_MODE *PinMode
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 32
     BYREF pin AS WSTRINGZ _                            ' __in LPCWSTR pin
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD Disable ( _                                   ' VTable offset = 36
     BYREF pin AS WSTRINGZ _                            ' __in LPCWSTR pin
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD Enter ( _                                     ' VTable offset = 40
     BYREF pin AS WSTRINGZ _                            ' __in LPCWSTR pin
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD Change ( _                                    ' VTable offset = 44
     BYREF pin AS WSTRINGZ _                            ' __in LPCWSTR pin
   , BYREF newPin AS WSTRINGZ _                         ' __in LPCWSTR newPin
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD Unblock ( _                                   ' VTable offset = 48
     BYREF puk AS WSTRINGZ _                            ' __in LPCWSTR puk
   , BYREF newPin AS WSTRINGZ _                         ' __in LPCWSTR newPin
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPinManager ( _                             ' VTable offset = 52
   ) AS IMbnPinManager                                  ' __retval_out IMbnPinManager **pinManager
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnPin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnPinEvents
' IID = {DCBBBAB6-2008-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnPin
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnPinEvents_INTERFACE_DEFINED)
    %IMbnPinEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnPinEvents $IID_IMbnPinEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnEnableComplete ( _                          ' VTable offset = 12
     BYVAL pin AS IMbnPin _                             ' __in IMbnPin *pin
   , BYREF pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO *pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDisableComplete ( _                         ' VTable offset = 16
     BYVAL pin AS IMbnPin _                             ' __in IMbnPin *pin
   , BYREF pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO *pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnEnterComplete ( _                           ' VTable offset = 20
     BYVAL pin AS IMbnPin _                             ' __in IMbnPin *pin
   , BYREF pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO *pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnChangeComplete ( _                          ' VTable offset = 24
     BYVAL pin AS IMbnPin _                             ' __in IMbnPin *pin
   , BYREF pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO *pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnUnblockComplete ( _                         ' VTable offset = 28
     BYVAL pin AS IMbnPin _                             ' __in IMbnPin *pin
   , BYREF pinInfo AS MBN_PIN_INFO _                    ' __in MBN_PIN_INFO *pinInfo
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnPinEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnRegistration
' IID = {DCBBBAB6-2009-4BBB-AAEE-338E368AF6FA}
' Get/Set Wireless WAN network registration mode
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnRegistration_INTERFACE_DEFINED)
    %IMbnRegistration_INTERFACE_DEFINED = 1

INTERFACE IMbnRegistration $IID_IMbnRegistration

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetRegisterState ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out MBN_REGISTER_STATE *registerState
   ' =====================================================================================
   METHOD GetRegisterMode ( _                           ' VTable offset = 16
   ) AS LONG                                            ' __retval_out MBN_REGISTER_MODE *registerMode
   ' =====================================================================================
   METHOD GetProviderID ( _                             ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *providerID
   ' =====================================================================================
   METHOD GetProviderName ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *providerName
   ' =====================================================================================
   METHOD GetRoamingText ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *roamingText
   ' =====================================================================================
   METHOD GetAvailableDataClasses ( _                   ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *availableDataClasses
   ' =====================================================================================
   METHOD GetCurrentDataClass ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *currentDataClass
   ' =====================================================================================
   METHOD GetRegistrationNetworkError ( _               ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out ULONG *registrationNetworkError
   ' =====================================================================================
   METHOD GetPacketAttachNetworkError ( _               ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG *packetAttachNetworkError
   ' =====================================================================================
   METHOD SetRegisterMode ( _                           ' VTable offset = 48
     BYVAL registerMode AS LONG _                       ' __in MBN_REGISTER_MODE registerMode
   , BYREF providerID AS WSTRINGZ _                     ' __in LPCWSTR providerID
   , BYVAL dataClass AS DWORD _                         ' __in ULONG dataClass
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnRegistration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnRegistrationEvents
' IID = {DCBBBAB6-200A-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnRegistration
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnRegistrationEvents_INTERFACE_DEFINED)
    %IMbnRegistrationEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnRegistrationEvents $IID_IMbnRegistrationEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnRegisterModeAvailable ( _                   ' VTable offset = 12
     BYVAL newInterface AS IMbnRegistration _           ' __in IMbnRegistration *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnRegisterStateChange ( _                     ' VTable offset = 16
     BYVAL newInterface AS IMbnRegistration _           ' __in IMbnRegistration *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnPacketServiceStateChange ( _                ' VTable offset = 20
     BYVAL newInterface AS IMbnRegistration _           ' __in IMbnRegistration *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetRegisterModeComplete ( _                 ' VTable offset = 24
     BYVAL newInterface AS IMbnRegistration _           ' __in IMbnRegistration *newInterface
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnRegistrationEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionContext
' IID = {DCBBBAB6-200B-4BBB-AAEE-338E368AF6FA}
' Get/Set Wireless WAN network information
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionContext_INTERFACE_DEFINED)
    %IMbnConnectionContext_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionContext $IID_IMbnConnectionContext

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetProvisionedContexts ( _                    ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY **provisionedContexts
   ' =====================================================================================
   METHOD SetProvisionedContext ( _                     ' VTable offset = 16
     BYVAL provisionedContexts AS MBN_CONTEXT _         ' __in MBN_CONTEXT provisionedContexts
   , BYREF providerID AS WSTRINGZ _                     ' __in LPCWSTR providerID
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionContextEvents
' IID = {DCBBBAB6-200C-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnNetwork
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionContextEvents_INTERFACE_DEFINED)
    %IMbnConnectionContextEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionContextEvents $IID_IMbnConnectionContextEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnProvisionedContextListChange ( _            ' VTable offset = 12
     BYVAL newInterface AS IMbnConnectionContext _      ' __in IMbnConnectionContext *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetProvisionedContextComplete ( _           ' VTable offset = 16
     BYVAL newInterface AS IMbnConnectionContext _      ' __in IMbnConnectionContext *newInterface
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionContextEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnection
' IID = {DCBBBAB6-200D-4BBB-AAEE-338E368AF6FA}
' Get/Set Wireless WAN connection information
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnection_INTERFACE_DEFINED)
    %IMbnConnection_INTERFACE_DEFINED = 1

INTERFACE IMbnConnection $IID_IMbnConnection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ConnectionID ( _                        ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *ConnectionID
   ' =====================================================================================
   PROPERTY GET InterfaceID ( _                         ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *InterfaceID
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 20
     BYVAL connectionMode AS LONG _                     ' __in MBN_CONNECTION_MODE connectionMode
   , BYREF strProfile AS WSTRINGZ _                     ' __in LPCWSTR strProfile
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 24
     BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetConnectionState ( _                        ' VTable offset = 28
     BYREF ConnectionState AS LONG _                    ' __out MBN_ACTIVATION_STATE *ConnectionState
   , BYREF ProfileName AS WSTRING _                     ' __out BSTR *ProfileName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVoiceCallState ( _                         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out MBN_VOICE_CALL_STATE *voiceCallState
   ' =====================================================================================
   METHOD GetActivationNetworkError ( _                 ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *networkError
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionEvents
' IID = {DCBBBAB6-200E-4BBB-AAEE-338E368AF6FA}
' Notifications on IMbnConnection
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionEvents_INTERFACE_DEFINED)
    %IMbnConnectionEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionEvents $IID_IMbnConnectionEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnConnectComplete ( _                         ' VTable offset = 12
     BYVAL newConnection AS IMbnConnection _            ' __in IMbnConnection *newConnection
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDisconnectComplete ( _                      ' VTable offset = 16
     BYVAL newConnection AS IMbnConnection _            ' __in IMbnConnection *newConnection
   , BYVAL reqeustID AS DWORD _                         ' __in ULONG reqeustID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnConnectStateChange ( _                      ' VTable offset = 20
     BYVAL newConnection AS IMbnConnection _            ' __in IMbnConnection *newConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD OnVoiceCallStateChange ( _                    ' VTable offset = 24
     BYVAL newConnection AS IMbnConnection _            ' __in IMbnConnection *newConnection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionProfileManager
' IID = {DCBBBAB6-200F-4BBB-AAEE-338E368AF6FA}
' Create a new connection profile or enumerate existing profiles
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionProfileManager_INTERFACE_DEFINED)
    %IMbnConnectionProfileManager_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionProfileManager $IID_IMbnConnectionProfileManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetConnectionProfiles ( _                     ' VTable offset = 12
     BYVAL mbnInterface AS IMbnInterface _              ' __in IMbnInterface *mbnInterface
   ) AS DWORD                                           ' __retval_out SAFEARRAY **connectionProfiles
   ' =====================================================================================
   METHOD GetConnectionProfile ( _                      ' VTable offset = 16
     BYVAL mbnInterface AS IMbnInterface _              ' __in IMbnInterface *mbnInterface
   , BYREF ProfileName AS WSTRINGZ _                    ' __in LPCWSTR ProfileName
   ) AS IMbnConnectionProfile                           ' __retval_out IMbnConnectionProfile **connectionProfile
   ' =====================================================================================
   METHOD CreateConnectionProfile ( _                   ' VTable offset = 20
     BYREF xmlProfile AS WSTRINGZ _                     ' __in LPCWSTR xmlProfile
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionProfileManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionProfile
' IID = {DCBBBAB6-2010-4BBB-AAEE-338E368AF6FA}
' Retrieves Connection parameters
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionProfile_INTERFACE_DEFINED)
    %IMbnConnectionProfile_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionProfile $IID_IMbnConnectionProfile

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetProfileXmlData ( _                         ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *profileData
   ' =====================================================================================
   METHOD UpdateProfile ( _                             ' VTable offset = 16
     BYREF strProfile AS WSTRINGZ _                     ' __in LPCWSTR strProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionProfile_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionProfileEvents
' IID = {DCBBBAB6-2011-4BBB-AAEE-338E368AF6FA}
' Events on IMbnConnectionProfile
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionProfileEvents_INTERFACE_DEFINED)
    %IMbnConnectionProfileEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionProfileEvents $IID_IMbnConnectionProfileEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnProfileUpdate ( _                           ' VTable offset = 12
     BYVAL newProfile AS IMbnConnectionProfile _        ' __in IMbnConnectionProfile *newProfile
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionProfileEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSmsConfiguration
' IID = {DCBBBAB6-2012-4BBB-AAEE-338E368AF6FA}
' SMS Configuration interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSmsConfiguration_INTERFACE_DEFINED)
    %IMbnSmsConfiguration_INTERFACE_DEFINED = 1

INTERFACE IMbnSmsConfiguration $IID_IMbnSmsConfiguration

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ServiceCenterAddress ( _                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *scAddress
   ' =====================================================================================
   PROPERTY SET ServiceCenterAddress ( _                ' VTable offset = 16
     BYREF scAddress AS WSTRINGZ _                      ' __in LPCWSTR scAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxMessageIndex ( _                     ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out ULONG *index
   ' =====================================================================================
   PROPERTY GET CdmaShortMsgSize ( _                    ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out ULONG *shortMsgSize
   ' =====================================================================================
   PROPERTY GET SmsFormat ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out MBN_SMS_FORMAT *SmsFormat
   ' =====================================================================================
   PROPERTY SET SmsFormat ( _                           ' VTable offset = 32
     BYVAL SmsFormat AS LONG _                          ' __in MBN_SMS_FORMAT SmsFormat
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSmsConfiguration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSmsReadMsgPdu
' IID = {DCBBBAB6-2013-4BBB-AAEE-338E368AF6FA}
' Represents SMS read in the PDU format
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSmsReadMsgPdu_INTERFACE_DEFINED)
    %IMbnSmsReadMsgPdu_INTERFACE_DEFINED = 1

INTERFACE IMbnSmsReadMsgPdu $IID_IMbnSmsReadMsgPdu

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET index ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *index
   ' =====================================================================================
   PROPERTY GET status ( _                              ' VTable offset = 16
   ) AS LONG                                            ' __retval_out MBN_MSG_STATUS *status
   ' =====================================================================================
   PROPERTY GET PduData ( _                             ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *PduData
   ' =====================================================================================
   PROPERTY GET Message ( _                             ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY **Message
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSmsReadMsgPdu_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSmsReadMsgTextCdma
' IID = {DCBBBAB6-2014-4BBB-AAEE-338E368AF6FA}
' Represents SMS read from CDMA device
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSmsReadMsgTextCdma_INTERFACE_DEFINED)
    %IMbnSmsReadMsgTextCdma_INTERFACE_DEFINED = 1

INTERFACE IMbnSmsReadMsgTextCdma $IID_IMbnSmsReadMsgTextCdma

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET index ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *index
   ' =====================================================================================
   PROPERTY GET status ( _                              ' VTable offset = 16
   ) AS LONG                                            ' __retval_out MBN_MSG_STATUS *status
   ' =====================================================================================
   PROPERTY GET Address ( _                             ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *Address
   ' =====================================================================================
   PROPERTY GET Timestamp ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *Timestamp
   ' =====================================================================================
   PROPERTY GET EncodingID ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out MBN_SMS_CDMA_ENCODING *EncodingID
   ' =====================================================================================
   PROPERTY GET LanguageID ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out MBN_SMS_CDMA_LANG *LanguageID
   ' =====================================================================================
   PROPERTY GET SizeInCharacters ( _                    ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *SizeInCharacters
   ' =====================================================================================
   PROPERTY GET Message ( _                             ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY **Message
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSmsReadMsgTextCdma_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSms
' IID = {DCBBBAB6-2015-4BBB-AAEE-338E368AF6FA}
' Use to send/recieve SMS
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSms_INTERFACE_DEFINED)
    %IMbnSms_INTERFACE_DEFINED = 1

INTERFACE IMbnSms $IID_IMbnSms

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSmsConfiguration ( _                       ' VTable offset = 12
   ) AS IMbnSmsConfiguration                            ' __retval_out IMbnSmsConfiguration **smsConfiguration
   ' =====================================================================================
   METHOD SetSmsConfiguration ( _                       ' VTable offset = 16
     BYVAL smsConfiguration AS IMbnSmsConfiguration _   ' __in IMbnSmsConfiguration *smsConfiguration
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD SmsSendPdu ( _                                ' VTable offset = 20
     BYREF PduData AS WSTRINGZ _                        ' __in LPCWSTR PduData
   , BYVAL size AS BYTE _                               ' __in BYTE size
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD SmsSendCdma ( _                               ' VTable offset = 24
     BYREF Address AS WSTRINGZ _                        ' __in LPCWSTR Address
   , BYVAL encoding AS LONG _                           ' __in MBN_SMS_CDMA_ENCODING encoding
   , BYVAL language AS LONG _                           ' __in MBN_SMS_CDMA_LANG language
   , BYVAL SizeInCharacters AS DWORD _                  ' __in ULONG SizeInCharacters
   , BYVAL Message AS DWORD _                           ' __in SAFEARRAY *Message
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD SmsSendCdmaPdu ( _                            ' VTable offset = 28
     BYVAL Message AS DWORD _                           ' __in SAFEARRAY *Message
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD SmsRead ( _                                   ' VTable offset = 32
     BYREF smsFilter AS MBN_SMS_FILTER _                ' __in MBN_SMS_FILTER *smsFilter
   , BYVAL SmsFormat AS LONG _                          ' __in MBN_SMS_FORMAT SmsFormat
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD SmsDelete ( _                                 ' VTable offset = 36
     BYREF smsFilter AS MBN_SMS_FILTER _                ' __in MBN_SMS_FILTER *smsFilter
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSmsStatus ( _                              ' VTable offset = 40
     BYREF smsStatusInfo AS MBN_SMS_STATUS_INFO _       ' __out MBN_SMS_STATUS_INFO *smsStatusInfo
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSms_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnSmsEvents
' IID = {DCBBBAB6-2016-4BBB-AAEE-338E368AF6FA}
' Notification on IMbnSms
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnSmsEvents_INTERFACE_DEFINED)
    %IMbnSmsEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnSmsEvents $IID_IMbnSmsEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnSmsConfigurationChange ( _                  ' VTable offset = 12
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetSmsConfigurationComplete ( _             ' VTable offset = 16
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSmsSendComplete ( _                         ' VTable offset = 20
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSmsReadComplete ( _                         ' VTable offset = 24
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   , BYVAL SmsFormat AS LONG _                          ' __in MBN_SMS_FORMAT SmsFormat
   , BYVAL readMsgs AS DWORD _                          ' __in SAFEARRAY *readMsgs
   , BYVAL moreMsgs AS INTEGER _                        ' __in VARIANT_BOOL moreMsgs
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSmsNewClass0Message ( _                     ' VTable offset = 28
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   , BYVAL SmsFormat AS LONG _                          ' __in MBN_SMS_FORMAT SmsFormat
   , BYVAL readMsgs AS DWORD _                          ' __in SAFEARRAY *readMsgs
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSmsDeleteComplete ( _                       ' VTable offset = 32
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSmsStatusChange ( _                         ' VTable offset = 36
     BYVAL sms AS IMbnSms _                             ' __in IMbnSms *sms
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnSmsEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnServiceActivation
' IID = {DCBBBAB6-2017-4BBB-AAEE-338E368AF6FA}
' Provides a pass through interface for cellular service activation operation
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnServiceActivation_INTERFACE_DEFINED)
    %IMbnServiceActivation_INTERFACE_DEFINED = 1

INTERFACE IMbnServiceActivation $IID_IMbnServiceActivation

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYVAL vendorSpecificData AS DWORD _                ' __in SAFEARRAY *vendorSpecificData
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnServiceActivation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnServiceActivationEvents
' IID = {DCBBBAB6-2018-4BBB-AAEE-338E368AF6FA}
' Events on IMbnServiceActivation interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnServiceActivationEvents_INTERFACE_DEFINED)
    %IMbnServiceActivationEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnServiceActivationEvents $IID_IMbnServiceActivationEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnActivationComplete ( _                      ' VTable offset = 12
     BYVAL serviceActivation AS IMbnServiceActivation _ ' __in IMbnServiceActivation *serviceActivation
   , BYVAL vendorSpecificData AS DWORD _                ' __in SAFEARRAY *vendorSpecificData
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   , BYVAL networkError AS DWORD _                      ' __in ULONG networkError
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnServiceActivationEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnVendorSpecificOperation
' IID = {DCBBBAB6-2019-4BBB-AAEE-338E368AF6FA}
' Provides support for passing Vendor specific request to the MBN device drivers
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnVendorSpecificOperation_INTERFACE_DEFINED)
    %IMbnVendorSpecificOperation_INTERFACE_DEFINED = 1

INTERFACE IMbnVendorSpecificOperation $IID_IMbnVendorSpecificOperation

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetVendorSpecific ( _                         ' VTable offset = 12
     BYVAL vendorSpecificData AS DWORD _                ' __in SAFEARRAY *vendorSpecificData
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnVendorSpecificOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnVendorSpecificEvents
' IID = {DCBBBAB6-201A-4BBB-AAEE-338E368AF6FA}
' Events on IMbnVendorSpecificOperation interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnVendorSpecificEvents_INTERFACE_DEFINED)
    %IMbnVendorSpecificEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnVendorSpecificEvents $IID_IMbnVendorSpecificEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnEventNotification ( _                       ' VTable offset = 12
     BYVAL vendorOperation AS IMbnVendorSpecificOperation _ ' __in IMbnVendorSpecificOperation *vendorOperation
   , BYVAL vendorSpecificData AS DWORD _                ' __in SAFEARRAY *vendorSpecificData
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetVendorSpecificComplete ( _               ' VTable offset = 16
     BYVAL vendorOperation AS IMbnVendorSpecificOperation _ ' __in IMbnVendorSpecificOperation *vendorOperation
   , BYVAL vendorSpecificData AS DWORD _                ' __in SAFEARRAY *vendorSpecificData
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnVendorSpecificEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnInterfaceManager
' IID = {DCBBBAB6-201B-4BBB-AAEE-338E368AF6FA}
' Events on IMbnInterfaceManager interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnInterfaceManager_INTERFACE_DEFINED)
    %IMbnInterfaceManager_INTERFACE_DEFINED = 1

INTERFACE IMbnInterfaceManager $IID_IMbnInterfaceManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 12
     BYREF InterfaceID AS WSTRINGZ _                    ' __in LPCWSTR InterfaceID
   ) AS IMbnInterface                                   ' __retval_out IMbnInterface **mbnInterface
   ' =====================================================================================
   METHOD GetInterfaces ( _                             ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY **mbnInterfaces
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnInterfaceManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnInterfaceManagerEvents
' IID = {DCBBBAB6-201C-4BBB-AAEE-338E368AF6FA}
' Events on IMbnInterfaceManagerEvents interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnInterfaceManagerEvents_INTERFACE_DEFINED)
    %IMbnInterfaceManagerEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnInterfaceManagerEvents $IID_IMbnInterfaceManagerEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnInterfaceArrival ( _                        ' VTable offset = 12
     BYVAL newInterface AS IMbnInterface _              ' __in IMbnInterface *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnInterfaceRemoval ( _                        ' VTable offset = 16
     BYVAL oldInterface AS IMbnInterface _              ' __in IMbnInterface *oldInterface
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnInterfaceManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionManager
' IID = {DCBBBAB6-201D-4BBB-AAEE-338E368AF6FA}
' Events on IMbnInterfaceManager interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionManager_INTERFACE_DEFINED)
    %IMbnConnectionManager_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionManager $IID_IMbnConnectionManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetConnection ( _                             ' VTable offset = 12
     BYREF ConnectionID AS WSTRINGZ _                   ' __in LPCWSTR ConnectionID
   ) AS IMbnConnection                                  ' __retval_out IMbnConnection **mbnConnection
   ' =====================================================================================
   METHOD GetConnections ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY **mbnConnections
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionManagerEvents
' IID = {DCBBBAB6-201E-4BBB-AAEE-338E368AF6FA}
' Events on IMbnConnectionManagerEvents interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionManagerEvents_INTERFACE_DEFINED)
    %IMbnConnectionManagerEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionManagerEvents $IID_IMbnConnectionManagerEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnConnectionArrival ( _                       ' VTable offset = 12
     BYVAL newConnection AS IMbnConnection _            ' __in IMbnConnection *newConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD OnConnectionRemoval ( _                       ' VTable offset = 16
     BYVAL oldConnection AS IMbnConnection _            ' __in IMbnConnection *oldConnection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnConnectionProfileManagerEvents
' IID = {DCBBBAB6-201F-4BBB-AAEE-338E368AF6FA}
' Events on IMbnProfileManagerEvents interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnConnectionProfileManagerEvents_INTERFACE_DEFINED)
    %IMbnConnectionProfileManagerEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnConnectionProfileManagerEvents $IID_IMbnConnectionProfileManagerEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnConnectionProfileArrival ( _                ' VTable offset = 12
     BYVAL newConnectionProfile AS IMbnConnectionProfile _ ' __in IMbnConnectionProfile *newConnectionProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD OnConnectionProfileRemoval ( _                ' VTable offset = 16
     BYVAL oldConnectionProfile AS IMbnConnectionProfile _ ' __in IMbnConnectionProfile *oldConnectionProfile
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnConnectionProfileManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnRadio
' IID = {DCCCCAB6-201F-4BBB-AAEE-338E368AF6FA}
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnRadio_INTERFACE_DEFINED)
    %IMbnRadio_INTERFACE_DEFINED = 1

INTERFACE IMbnRadio $IID_IMbnRadio

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET SoftwareRadioState ( _                  ' VTable offset = 12
   ) AS LONG                                            ' __retval_out MBN_RADIO *SoftwareRadioState
   ' =====================================================================================
   PROPERTY GET HardwareRadioState ( _                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out MBN_RADIO *HardwareRadioState
   ' =====================================================================================
   METHOD SetSoftwareRadioState ( _                     ' VTable offset = 20
     BYVAL radioState AS LONG _                         ' __in MBN_RADIO radioState
   , BYREF requestID AS DWORD _                         ' __out ULONG *requestID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnRadio_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMbnRadioEvents
' IID = {DCDDDAB6-201F-4BBB-AAEE-338E368AF6FA}
' Events on IMbnRadioEvents interface
' Attributes = 384 [&H180] [Nonextensible] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMbnRadioEvents_INTERFACE_DEFINED)
    %IMbnRadioEvents_INTERFACE_DEFINED = 1

INTERFACE IMbnRadioEvents $IID_IMbnRadioEvents

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnRadioStateChange ( _                        ' VTable offset = 12
     BYVAL newInterface AS IMbnRadio _                  ' __in IMbnRadio *newInterface
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSetSoftwareRadioStateComplete ( _           ' VTable offset = 16
     BYVAL newInterface AS IMbnRadio _                  ' __in IMbnRadio *newInterface
   , BYVAL requestID AS DWORD _                         ' __in ULONG requestID
   , BYVAL status AS LONG _                             ' __in HRESULT status
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMbnRadioEvents_INTERFACE_DEFINED__ */
