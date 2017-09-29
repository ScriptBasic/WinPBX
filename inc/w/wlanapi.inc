' ########################################################################################
' Microsoft Windows
' File: wlanapi.inc
' Contents: Definitions and data strcutures for wlan auto config client side API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WLANAPI_INC = 1

#INCLUDE ONCE "l2cmn.inc"
#INCLUDE ONCE "windot11.inc"
#INCLUDE ONCE "EapTypes.inc"

'// major version is in low-order WORD,
'// minor version is in high-order WORD
%WLAN_API_VERSION_1_0 = &H00000001???
%WLAN_API_VERSION_2_0 = &H00000002???

'#define WLAN_API_VERSION_MAJOR(_v)  ((_v) & 0xffff)
MACRO WLAN_API_VERSION_MAJOR(v_) = LO(WORD, v_)

'#define WLAN_API_VERSION_MINOR(_v)  (((DWORD)(_v)) >> 16)
MACRO WLAN_API_VERSION_MINOR(v_) = HI(WORD, v_)

'#define WLAN_API_MAKE_VERSION(_major, _minor)   (((DWORD)(_minor)) << 16 | (_major))
MACRO WLAN_API_MAKE_VERSION(vmajor_, vminor_) = MAK(DWORD, vminor_ , vmajor_)

'// WLAN API is version 1 in all WinXP
'// and version 2 in Longhorn Vista
'#if (_WIN32_WINNT >= 0x0600)
'#define WLAN_API_VERSION    WLAN_API_VERSION_2_0
'#else
'#define WLAN_API_VERSION    WLAN_API_VERSION_1_0
'#endif  // (_WIN32_WINNT <= 0x0600)

'// maximum length of name, in characters
%WLAN_MAX_NAME_LENGTH = %L2_PROFILE_MAX_NAME_LENGTH

'// profile flags
%WLAN_PROFILE_GROUP_POLICY                   = &H00000001???
%WLAN_PROFILE_USER                           = &H00000002???
%WLAN_PROFILE_GET_PLAINTEXT_KEY              = &H00000004???
'// the following flags are only used for WlanSaveTemporaryProfile API
%WLAN_PROFILE_CONNECTION_MODE_SET_BY_CLIENT  = &H00010000???
%WLAN_PROFILE_CONNECTION_MODE_AUTO           = &H00020000???

'// EAPHost data storage flags
%WLAN_SET_EAPHOST_DATA_ALL_USERS = &H00000001???


'// struct WLAN_PROFILE_INFO defines the basic information of an 802.11 network profile
' // Size = 516 bytes
TYPE WLAN_PROFILE_INFO DWORD
   strProfileName AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH   ' WCHAR
   dwFlags        AS DWORD   ' DWORD
END TYPE

' // Size = 40 bytes
TYPE DOT11_NETWORK DWORD
   dot11Ssid    AS DOT11_SSID
   dot11BssType AS LONG   ' DOT11_BSS_TYPE
END TYPE

'// proximity service discovery IE specific definitions

'// the maximum data size in one PSD IE data entry (payload), in bytes
%DOT11_PSD_IE_MAX_DATA_SIZE = 240
'// the maximum number of PSD IE data entries
%DOT11_PSD_IE_MAX_ENTRY_NUMBER = 5

' // Size = 8 bytes
TYPE WLAN_RAW_DATA DWORD
   ' // size of the data blob
   dwDataSize  AS DWORD   ' DWORD
   DataBlob(0) AS BYTE    ' BYTE
END TYPE

' // Size = 8 bytes
TYPE WLAN_RAW_DATA_LIST_DataList DWORD
   ' // the beginning of the data blob
   ' // the offset is w.r.t. the beginning of the entry
   dwDataOffset AS DWORD   ' DWORD
   ' // size of the data blob
   dwDataSize   AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE WLAN_RAW_DATA_LIST DWORD
   dwTotalSize     AS DWORD   ' DWORD
   dwNumberOfItems AS DWORD   ' DWORD
   DataList(0)     AS WLAN_RAW_DATA_LIST_DataList
END TYPE

' enum WLAN_CONNECTION_MODE {
%wlan_connection_mode_profile            = 0
%wlan_connection_mode_temporary_profile  = 1
%wlan_connection_mode_discovery_secure   = 2
%wlan_connection_mode_discovery_unsecure = 3
%wlan_connection_mode_auto               = 4
%wlan_connection_mode_invalid            = 5

'// Wlan reason code
'//
'// They are put in the following range:
'// each component got 0x1000 numbers, within which:
'// the first half is for capability mismatch reason,
'// the second half for connect/security error reason.
'//
'// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
'// IMPORTANT: If you add/remove a reason code, please
'// modify the corresponding entry in wlanres.h and wlanres.rc
'// and the corresponding mapping in wlanapi.c
'typedef DWORD WLAN_REASON_CODE, *PWLAN_REASON_CODE;
%WLAN_REASON_CODE_SUCCESS                = %L2_REASON_CODE_SUCCESS
'// general codes
%WLAN_REASON_CODE_UNKNOWN                = %L2_REASON_CODE_UNKNOWN

%WLAN_REASON_CODE_RANGE_SIZE             = %L2_REASON_CODE_GROUP_SIZE
%WLAN_REASON_CODE_BASE                   = %L2_REASON_CODE_DOT11_AC_BASE

'// range for Auto Config
'//
%WLAN_REASON_CODE_AC_BASE                = %L2_REASON_CODE_DOT11_AC_BASE
%WLAN_REASON_CODE_AC_CONNECT_BASE        = (%WLAN_REASON_CODE_AC_BASE + %WLAN_REASON_CODE_RANGE_SIZE \ 2)
%WLAN_REASON_CODE_AC_END                 = (%WLAN_REASON_CODE_AC_BASE + %WLAN_REASON_CODE_RANGE_SIZE - 1)

'// range for profile manager
'// it has profile adding failure reason codes, but may not have
'// connection reason codes
'//
%WLAN_REASON_CODE_PROFILE_BASE           = %L2_REASON_CODE_PROFILE_BASE
%WLAN_REASON_CODE_PROFILE_CONNECT_BASE   = (%WLAN_REASON_CODE_PROFILE_BASE + %WLAN_REASON_CODE_RANGE_SIZE \ 2)
%WLAN_REASON_CODE_PROFILE_END            = (%WLAN_REASON_CODE_PROFILE_BASE + %WLAN_REASON_CODE_RANGE_SIZE - 1)

'// range for MSM
'//
%WLAN_REASON_CODE_MSM_BASE               = %L2_REASON_CODE_DOT11_MSM_BASE
%WLAN_REASON_CODE_MSM_CONNECT_BASE       = (%WLAN_REASON_CODE_MSM_BASE + %WLAN_REASON_CODE_RANGE_SIZE \ 2)
%WLAN_REASON_CODE_MSM_END                = (%WLAN_REASON_CODE_MSM_BASE + %WLAN_REASON_CODE_RANGE_SIZE - 1)

'// range for MSMSEC
'//
%WLAN_REASON_CODE_MSMSEC_BASE            = %L2_REASON_CODE_DOT11_SECURITY_BASE
%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE    = (%WLAN_REASON_CODE_MSMSEC_BASE + %WLAN_REASON_CODE_RANGE_SIZE \ 2)
%WLAN_REASON_CODE_MSMSEC_END             = (%WLAN_REASON_CODE_MSMSEC_BASE + %WLAN_REASON_CODE_RANGE_SIZE - 1)

'// AC network incompatible reason codes
'//
%WLAN_REASON_CODE_NETWORK_NOT_COMPATIBLE = (%WLAN_REASON_CODE_AC_BASE +1)
%WLAN_REASON_CODE_PROFILE_NOT_COMPATIBLE = (%WLAN_REASON_CODE_AC_BASE +2)

'// AC connect reason code
'//
%WLAN_REASON_CODE_NO_AUTO_CONNECTION     = (%WLAN_REASON_CODE_AC_CONNECT_BASE +1)
%WLAN_REASON_CODE_NOT_VISIBLE            = (%WLAN_REASON_CODE_AC_CONNECT_BASE +2)
%WLAN_REASON_CODE_GP_DENIED              = (%WLAN_REASON_CODE_AC_CONNECT_BASE +3)
%WLAN_REASON_CODE_USER_DENIED            = (%WLAN_REASON_CODE_AC_CONNECT_BASE +4)
%WLAN_REASON_CODE_BSS_TYPE_NOT_ALLOWED   = (%WLAN_REASON_CODE_AC_CONNECT_BASE +5)
%WLAN_REASON_CODE_IN_FAILED_LIST         = (%WLAN_REASON_CODE_AC_CONNECT_BASE +6)
%WLAN_REASON_CODE_IN_BLOCKED_LIST        = (%WLAN_REASON_CODE_AC_CONNECT_BASE +7)
%WLAN_REASON_CODE_SSID_LIST_TOO_LONG     = (%WLAN_REASON_CODE_AC_CONNECT_BASE +8)
%WLAN_REASON_CODE_CONNECT_CALL_FAIL      = (%WLAN_REASON_CODE_AC_CONNECT_BASE +9)
%WLAN_REASON_CODE_SCAN_CALL_FAIL         = (%WLAN_REASON_CODE_AC_CONNECT_BASE +10)
%WLAN_REASON_CODE_NETWORK_NOT_AVAILABLE  = (%WLAN_REASON_CODE_AC_CONNECT_BASE +11)
%WLAN_REASON_CODE_PROFILE_CHANGED_OR_DELETED = (%WLAN_REASON_CODE_AC_CONNECT_BASE +12)
%WLAN_REASON_CODE_KEY_MISMATCH           = (%WLAN_REASON_CODE_AC_CONNECT_BASE + 13)
%WLAN_REASON_CODE_USER_NOT_RESPOND       = (%WLAN_REASON_CODE_AC_CONNECT_BASE + 14)
%WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED_FOR_CLIENT = (%WLAN_REASON_CODE_AC_CONNECT_BASE + 15)
%WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED = (%WLAN_REASON_CODE_AC_CONNECT_BASE + 16)

'// Profile validation errors
'//
%WLAN_REASON_CODE_INVALID_PROFILE_SCHEMA = (%WLAN_REASON_CODE_PROFILE_BASE +1)
%WLAN_REASON_CODE_PROFILE_MISSING        = (%WLAN_REASON_CODE_PROFILE_BASE +2)
%WLAN_REASON_CODE_INVALID_PROFILE_NAME   = (%WLAN_REASON_CODE_PROFILE_BASE +3)
%WLAN_REASON_CODE_INVALID_PROFILE_TYPE   = (%WLAN_REASON_CODE_PROFILE_BASE +4)
%WLAN_REASON_CODE_INVALID_PHY_TYPE       = (%WLAN_REASON_CODE_PROFILE_BASE +5)
%WLAN_REASON_CODE_MSM_SECURITY_MISSING   = (%WLAN_REASON_CODE_PROFILE_BASE +6)
%WLAN_REASON_CODE_IHV_SECURITY_NOT_SUPPORTED = (%WLAN_REASON_CODE_PROFILE_BASE +7)
%WLAN_REASON_CODE_IHV_OUI_MISMATCH       = (%WLAN_REASON_CODE_PROFILE_BASE +8)
'        // IHV OUI not present but there is IHV settings in profile
%WLAN_REASON_CODE_IHV_OUI_MISSING        = (%WLAN_REASON_CODE_PROFILE_BASE +9)
'        // IHV OUI is present but there is no IHV settings in profile
%WLAN_REASON_CODE_IHV_SETTINGS_MISSING   = (%WLAN_REASON_CODE_PROFILE_BASE +10)
'        // both/conflict MSMSec and IHV security settings exist in profile
%WLAN_REASON_CODE_CONFLICT_SECURITY      = (%WLAN_REASON_CODE_PROFILE_BASE +11)
'        // no IHV or MSMSec security settings in profile
%WLAN_REASON_CODE_SECURITY_MISSING       = (%WLAN_REASON_CODE_PROFILE_BASE +12)
%WLAN_REASON_CODE_INVALID_BSS_TYPE       = (%WLAN_REASON_CODE_PROFILE_BASE +13)
%WLAN_REASON_CODE_INVALID_ADHOC_CONNECTION_MODE = (%WLAN_REASON_CODE_PROFILE_BASE +14)
%WLAN_REASON_CODE_NON_BROADCAST_SET_FOR_ADHOC = (%WLAN_REASON_CODE_PROFILE_BASE +15)
%WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_ADHOC = (%WLAN_REASON_CODE_PROFILE_BASE +16)
%WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_MANUAL_CONNECTION = (%WLAN_REASON_CODE_PROFILE_BASE +17)
%WLAN_REASON_CODE_IHV_SECURITY_ONEX_MISSING = (%WLAN_REASON_CODE_PROFILE_BASE +18)
%WLAN_REASON_CODE_PROFILE_SSID_INVALID   = (%WLAN_REASON_CODE_PROFILE_BASE +19)
%WLAN_REASON_CODE_TOO_MANY_SSID          = (%WLAN_REASON_CODE_PROFILE_BASE +20)
%WLAN_REASON_CODE_IHV_CONNECTIVITY_NOT_SUPPORTED = (%WLAN_REASON_CODE_PROFILE_BASE +21)
%WLAN_REASON_CODE_BAD_MAX_NUMBER_OF_CLIENTS_FOR_AP = (%WLAN_REASON_CODE_PROFILE_BASE +22)
%WLAN_REASON_CODE_INVALID_CHANNEL        = (%WLAN_REASON_CODE_PROFILE_BASE +23)
%WLAN_REASON_CODE_OPERATION_MODE_NOT_SUPPORTED = (%WLAN_REASON_CODE_PROFILE_BASE +24)
%WLAN_REASON_CODE_AUTO_AP_PROFILE_NOT_ALLOWED = (%WLAN_REASON_CODE_PROFILE_BASE +25)
%WLAN_REASON_CODE_AUTO_CONNECTION_NOT_ALLOWED = (%WLAN_REASON_CODE_PROFILE_BASE +26)


'// MSM network incompatible reasons
'//
%WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET_BY_OS = (%WLAN_REASON_CODE_MSM_BASE +1)
%WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET = (%WLAN_REASON_CODE_MSM_BASE +2)
%WLAN_REASON_CODE_BSS_TYPE_UNMATCH       = (%WLAN_REASON_CODE_MSM_BASE +3)
%WLAN_REASON_CODE_PHY_TYPE_UNMATCH       = (%WLAN_REASON_CODE_MSM_BASE +4)
%WLAN_REASON_CODE_DATARATE_UNMATCH       = (%WLAN_REASON_CODE_MSM_BASE +5)

'// MSM connection failure reasons, to be defined
'// failure reason codes
'//
'        // user called to disconnect
%WLAN_REASON_CODE_USER_CANCELLED         = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+1)
'        // got disconnect while associating
%WLAN_REASON_CODE_ASSOCIATION_FAILURE    = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+2)
'        // timeout for association
%WLAN_REASON_CODE_ASSOCIATION_TIMEOUT    = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+3)
'        // pre-association security completed with failure
%WLAN_REASON_CODE_PRE_SECURITY_FAILURE   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+4)
'        // fail to start post-association security
%WLAN_REASON_CODE_START_SECURITY_FAILURE = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+5)
'        // post-association security completed with failure
%WLAN_REASON_CODE_SECURITY_FAILURE       = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+6)
'        // security watchdog timeout
%WLAN_REASON_CODE_SECURITY_TIMEOUT       = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+7)
'        // got disconnect from driver when roaming
%WLAN_REASON_CODE_ROAMING_FAILURE        = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+8)
'        // failed to start security for roaming
%WLAN_REASON_CODE_ROAMING_SECURITY_FAILURE   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+9)
'        // failed to start security for adhoc-join
%WLAN_REASON_CODE_ADHOC_SECURITY_FAILURE     = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+10)
'        // got disconnection from driver
%WLAN_REASON_CODE_DRIVER_DISCONNECTED        = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+11)
'        // driver operation failed
%WLAN_REASON_CODE_DRIVER_OPERATION_FAILURE   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+12)
'        // Ihv service is not available
%WLAN_REASON_CODE_IHV_NOT_AVAILABLE    = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+13)
'        // Response from ihv timed out
%WLAN_REASON_CODE_IHV_NOT_RESPONDING   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+14)
'        // Timed out waiting for driver to disconnect
%WLAN_REASON_CODE_DISCONNECT_TIMEOUT   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+15)
'        // An internal error prevented the operation from being completed.
%WLAN_REASON_CODE_INTERNAL_FAILURE     = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+16)
'        // UI Request timed out.
%WLAN_REASON_CODE_UI_REQUEST_TIMEOUT   = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+17)
'        // Roaming too often, post security is not completed after 5 times.
%WLAN_REASON_CODE_TOO_MANY_SECURITY_ATTEMPTS = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+18)
'        // Failed to start AP
%WLAN_REASON_CODE_AP_STARTING_FAILURE  = (%WLAN_REASON_CODE_MSM_CONNECT_BASE+19)

'// MSMSEC reason codes
'//

%WLAN_REASON_CODE_MSMSEC_MIN                         = %WLAN_REASON_CODE_MSMSEC_BASE

'// Key index specified is not valid
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_KEY_INDEX   = (%WLAN_REASON_CODE_MSMSEC_BASE+1)
'// Key required, PSK present
%WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_PRESENT         = (%WLAN_REASON_CODE_MSMSEC_BASE+2)
'// Invalid key length
%WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_LENGTH          = (%WLAN_REASON_CODE_MSMSEC_BASE+3)
'// Invalid PSK length
%WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_LENGTH          = (%WLAN_REASON_CODE_MSMSEC_BASE+4)
'// No auth/cipher specified
%WLAN_REASON_CODE_MSMSEC_PROFILE_NO_AUTH_CIPHER_SPECIFIED        = (%WLAN_REASON_CODE_MSMSEC_BASE+5)
'// Too many auth/cipher specified
%WLAN_REASON_CODE_MSMSEC_PROFILE_TOO_MANY_AUTH_CIPHER_SPECIFIED  = (%WLAN_REASON_CODE_MSMSEC_BASE+6)
'// Profile contains duplicate auth/cipher
%WLAN_REASON_CODE_MSMSEC_PROFILE_DUPLICATE_AUTH_CIPHER           = (%WLAN_REASON_CODE_MSMSEC_BASE+7)
'// Profile raw data is invalid (1x or key data)
%WLAN_REASON_CODE_MSMSEC_PROFILE_RAWDATA_INVALID                 = (%WLAN_REASON_CODE_MSMSEC_BASE+8)
'// Invalid auth/cipher combination
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_AUTH_CIPHER             = (%WLAN_REASON_CODE_MSMSEC_BASE+9)
'// 802.1x disabled when it's required to be enabled
%WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_DISABLED                   = (%WLAN_REASON_CODE_MSMSEC_BASE+10)
'// 802.1x enabled when it's required to be disabled
%WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_ENABLED                    = (%WLAN_REASON_CODE_MSMSEC_BASE+11)
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_MODE           = (%WLAN_REASON_CODE_MSMSEC_BASE+12)
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_SIZE           = (%WLAN_REASON_CODE_MSMSEC_BASE+13)
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_TTL            = (%WLAN_REASON_CODE_MSMSEC_BASE+14)
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_MODE            = (%WLAN_REASON_CODE_MSMSEC_BASE+15)
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_THROTTLE        = (%WLAN_REASON_CODE_MSMSEC_BASE+16)
'// PreAuth enabled when PMK cache is disabled
%WLAN_REASON_CODE_MSMSEC_PROFILE_PREAUTH_ONLY_ENABLED            = (%WLAN_REASON_CODE_MSMSEC_BASE+17)
'// Capability matching failed at network
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_NETWORK          = (%WLAN_REASON_CODE_MSMSEC_BASE+18)
'// Capability matching failed at NIC
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_NIC              = (%WLAN_REASON_CODE_MSMSEC_BASE+19)
'// Capability matching failed at profile
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE          = (%WLAN_REASON_CODE_MSMSEC_BASE+20)
'// Network does not support specified discovery type
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_DISCOVERY        = (%WLAN_REASON_CODE_MSMSEC_BASE+21)
'// Passphrase contains invalid character
%WLAN_REASON_CODE_MSMSEC_PROFILE_PASSPHRASE_CHAR     = (%WLAN_REASON_CODE_MSMSEC_BASE+22)
'// Key material contains invalid character
%WLAN_REASON_CODE_MSMSEC_PROFILE_KEYMATERIAL_CHAR     = (%WLAN_REASON_CODE_MSMSEC_BASE+23)
'// Wrong key type specified for the auth/cipher pair
%WLAN_REASON_CODE_MSMSEC_PROFILE_WRONG_KEYTYPE     = (%WLAN_REASON_CODE_MSMSEC_BASE+24)
'// "Mixed cell" suspected (AP not beaconing privacy, we have privacy enabled profile)
%WLAN_REASON_CODE_MSMSEC_MIXED_CELL                = (%WLAN_REASON_CODE_MSMSEC_BASE+25)
'// Auth timers or number of timeouts in profile is incorrect
%WLAN_REASON_CODE_MSMSEC_PROFILE_AUTH_TIMERS_INVALID = (%WLAN_REASON_CODE_MSMSEC_BASE+26)
'// Group key update interval in profile is incorrect
%WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_GKEY_INTV   = (%WLAN_REASON_CODE_MSMSEC_BASE+27)
'// "Transition network" suspected, trying legacy 802.11 security
%WLAN_REASON_CODE_MSMSEC_TRANSITION_NETWORK          = (%WLAN_REASON_CODE_MSMSEC_BASE+28)
'// Key contains characters which do not map to ASCII
%WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_UNMAPPED_CHAR   = (%WLAN_REASON_CODE_MSMSEC_BASE+29)
'// Capability matching failed at profile (auth not found)
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_AUTH     = (%WLAN_REASON_CODE_MSMSEC_BASE+30)
'// Capability matching failed at profile (cipher not found)
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_CIPHER   = (%WLAN_REASON_CODE_MSMSEC_BASE+31)
'// Safe mode value is invalid
%WLAN_REASON_CODE_MSMSEC_PROFILE_SAFE_MODE           = (%WLAN_REASON_CODE_MSMSEC_BASE+32)
'// Profile requires safe mode, not supported by NIC
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NIC = (%WLAN_REASON_CODE_MSMSEC_BASE+33)
'// Profile requires safe mode, not supported by network
%WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NW = (%WLAN_REASON_CODE_MSMSEC_BASE+34)
'// Profile has unsupported auth
%WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_AUTH    = (%WLAN_REASON_CODE_MSMSEC_BASE+35)
'// Profile has unsupported cipher
%WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_CIPHER  = (%WLAN_REASON_CODE_MSMSEC_BASE+36)

'// Failed to queue UI request
%WLAN_REASON_CODE_MSMSEC_UI_REQUEST_FAILURE          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+1)
'// 802.1x authentication did not start within configured time
%WLAN_REASON_CODE_MSMSEC_AUTH_START_TIMEOUT          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+2)
'// 802.1x authentication did not complete within configured time
%WLAN_REASON_CODE_MSMSEC_AUTH_SUCCESS_TIMEOUT        = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+3)
'// Dynamic key exchange did not start within configured time
%WLAN_REASON_CODE_MSMSEC_KEY_START_TIMEOUT           = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+4)
'// Dynamic key exchange did not succeed within configured time
%WLAN_REASON_CODE_MSMSEC_KEY_SUCCESS_TIMEOUT         = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+5)
'// Message 3 of 4 way handshake has no key data (RSN/WPA)
%WLAN_REASON_CODE_MSMSEC_M3_MISSING_KEY_DATA         = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+6)
'// Message 3 of 4 way handshake has no IE (RSN/WPA)
%WLAN_REASON_CODE_MSMSEC_M3_MISSING_IE               = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+7)
'// Message 3 of 4 way handshake has no Group Key (RSN)
%WLAN_REASON_CODE_MSMSEC_M3_MISSING_GRP_KEY          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+8)
'// Matching security capabilities of IE in M3 failed (RSN/WPA)
%WLAN_REASON_CODE_MSMSEC_PR_IE_MATCHING              = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+9)
'// Matching security capabilities of Secondary IE in M3 failed (RSN)
%WLAN_REASON_CODE_MSMSEC_SEC_IE_MATCHING             = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+10)
'// Required a pairwise key but AP configured only group keys
%WLAN_REASON_CODE_MSMSEC_NO_PAIRWISE_KEY             = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+11)
'// Message 1 of group key handshake has no key data (RSN/WPA)
%WLAN_REASON_CODE_MSMSEC_G1_MISSING_KEY_DATA         = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+12)
'// Message 1 of group key handshake has no group key
%WLAN_REASON_CODE_MSMSEC_G1_MISSING_GRP_KEY          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+13)
'// AP reset secure bit after connection was secured
%WLAN_REASON_CODE_MSMSEC_PEER_INDICATED_INSECURE     = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+14)
'// 802.1x indicated there is no authenticator but profile requires 802.1x
%WLAN_REASON_CODE_MSMSEC_NO_AUTHENTICATOR            = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+15)
'// Plumbing settings to NIC failed
%WLAN_REASON_CODE_MSMSEC_NIC_FAILURE                 = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+16)
'// Operation was cancelled by caller
%WLAN_REASON_CODE_MSMSEC_CANCELLED                   = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+17)
'// Key was in incorrect format
%WLAN_REASON_CODE_MSMSEC_KEY_FORMAT                  = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+18)
'// Security downgrade detected
%WLAN_REASON_CODE_MSMSEC_DOWNGRADE_DETECTED          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+19)
'// PSK mismatch suspected
%WLAN_REASON_CODE_MSMSEC_PSK_MISMATCH_SUSPECTED      = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+20)
'// Forced failure because connection method was not secure
%WLAN_REASON_CODE_MSMSEC_FORCED_FAILURE              = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+21)
'// Message 3 of 4 way handshake contains too many RSN IE (RSN)
%WLAN_REASON_CODE_MSMSEC_M3_TOO_MANY_RSNIE           = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+22)
'// Message 2 of 4 way handshake has no key data (RSN Adhoc)
%WLAN_REASON_CODE_MSMSEC_M2_MISSING_KEY_DATA         = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+23)
'// Message 2 of 4 way handshake has no IE (RSN Adhoc)
%WLAN_REASON_CODE_MSMSEC_M2_MISSING_IE               = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+24)
%WLAN_REASON_CODE_MSMSEC_AUTH_WCN_COMPLETED          = (%WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+25)

%WLAN_REASON_CODE_MSMSEC_MAX                         = %WLAN_REASON_CODE_MSMSEC_END

'typedef ULONG WLAN_SIGNAL_QUALITY, *PWLAN_SIGNAL_QUALITY;

'// available network flags
%WLAN_AVAILABLE_NETWORK_CONNECTED                    = &H00000001???  ' // This network is currently connected
%WLAN_AVAILABLE_NETWORK_HAS_PROFILE                  = &H00000002???  ' // There is a profile for this network
%WLAN_AVAILABLE_NETWORK_CONSOLE_USER_PROFILE         = &H00000004???  ' // The profile is the active console user's per user profile

'// flags that control the list returned by WlanGetAvailableNetworkList
'// include all ad hoc network profiles in the available network list, regardless they are visible or not
%WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_ADHOC_PROFILES           = &H00000001???
'// include all hidden network profiles in the available network list, regardless they are visible or not
%WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_MANUAL_HIDDEN_PROFILES   = &H00000002???

' // Size = 256 bytes
TYPE WLAN_RATE_SET DWORD
   uRateSetLength                            AS DWORD   ' ULONG
   usRateSet(%DOT11_RATE_SET_MAX_LENGTH - 1) AS WORD   ' USHORT
END TYPE

%WLAN_MAX_PHY_TYPE_NUMBER = 8
'//
'// struct WLAN_AVAILABLE_NETWORK defines information needed for an available network
' // Size = 628 bytes
TYPE WLAN_AVAILABLE_NETWORK DWORD
   strProfileName              AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH   ' WCHAR
   dot11Ssid                   AS DOT11_SSID
   dot11BssType                AS LONG    ' DOT11_BSS_TYPE
   uNumberOfBssids             AS DWORD   ' ULONG
   bNetworkConnectable         AS LONG    ' BOOL
   wlanNotConnectableReason    AS DWORD   ' WLAN_REASON_CODE
   uNumberOfPhyTypes           AS DWORD   ' ULONG
   dot11PhyTypes(%WLAN_MAX_PHY_TYPE_NUMBER - 1) AS DWORD   ' DOT11_PHY_TYPE
   ' // bMorePhyTypes is set to TRUE if the PHY types for the network
   ' // exceeds WLAN_MAX_PHY_TYPE_NUMBER.
   ' // In this case, uNumerOfPhyTypes is WLAN_MAX_PHY_TYPE_NUMBER and the
   ' // first WLAN_MAX_PHY_TYPE_NUMBER PHY types are returned.
   bMorePhyTypes               AS LONG    ' BOOL
   wlanSignalQuality           AS DWORD   ' WLAN_SIGNAL_QUALITY
   bSecurityEnabled            AS LONG    ' BOOL
   dot11DefaultAuthAlgorithm   AS LONG    ' DOT11_AUTH_ALGORITHM
   dot11DefaultCipherAlgorithm AS LONG    ' DOT11_CIPHER_ALGORITHM
   dwFlags                     AS DWORD   ' DWORD
   dwReserved                  AS DWORD   ' DWORD
END TYPE

' // Size = 360 bytes
TYPE WLAN_BSS_ENTRY DWORD
   dot11Ssid               AS DOT11_SSID
   uPhyId                  AS DWORD   ' ULONG
   dot11Bssid              AS DOT11_MAC_ADDRESS
   dot11BssType            AS LONG    ' DOT11_BSS_TYPE
   dot11BssPhyType         AS DWORD   ' DOT11_PHY_TYPE
   lRssi                   AS LONG    ' LONG
   uLinkQuality            AS DWORD   ' ULONG
   bInRegDomain            AS BYTE    ' BOOLEAN
   usBeaconPeriod          AS WORD    ' USHORT
   ullTimestamp            AS QUAD    ' ULONGLONG
   ullHostTimestamp        AS QUAD    ' ULONGLONG
   usCapabilityInformation AS WORD    ' ULONG
   ulChCenterFrequency     AS DWORD   ' ULONG
   wlanRateSet             AS WLAN_RATE_SET
   ' // the beginning of the IE blob
   ' // the offset is w.r.t. the beginning of the entry
   ulIeOffset              AS DWORD   ' ULONG
   ' // size of the IE blob
   ulIeSize                AS DWORD   ' ULONG
END TYPE

'// struct WLAN_VARIABLE_SIZE_ARRAY defines a list of entries,
'// each of which may have different size
' // Size = 368 bytes
TYPE WLAN_BSS_LIST DWORD
   ' // The total size of the data in BYTE
   dwTotalSize       AS DWORD   ' DWORD
   dwNumberOfItems   AS DWORD   ' DWORD
   wlanBssEntries(0) AS WLAN_BSS_ENTRY
END TYPE

' // the states of the network (interface)
' enum WLAN_INTERFACE_STATE
%wlan_interface_state_not_ready             = 0
%wlan_interface_state_connected             = 1
%wlan_interface_state_ad_hoc_network_formed = 2
%wlan_interface_state_disconnecting         = 3
%wlan_interface_state_disconnected          = 4
%wlan_interface_state_associating           = 5
%wlan_interface_state_discovering           = 6
%wlan_interface_state_authenticating        = 7

'// Adhoc network states
' enum WLAN_ADHOC_NETWORK_STATE {
%wlan_adhoc_network_state_formed    = 0
%wlan_adhoc_network_state_connected = 1

'// struct WLAN_INTERFACE_INFO defines the basic information for an interface
' // Size = 532 bytes
TYPE WLAN_INTERFACE_INFO DWORD
   InterfaceGuid           AS GUID   ' GUID
   strInterfaceDescription AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH   ' WCHAR
   isState                 AS LONG   ' WLAN_INTERFACE_STATE
END TYPE

'// structure WLAN_ASSOCIATION_ATTRIBUTES defines attributes of a wireless
'// association. The unit for Rx/Tx rate is Kbits/second.
' // Size = 68 bytes
TYPE WLAN_ASSOCIATION_ATTRIBUTES DWORD
   dot11Ssid         AS DOT11_SSID
   dot11BssType      AS LONG                ' DOT11_BSS_TYPE
   dot11Bssid        AS DOT11_MAC_ADDRESS
   dot11PhyType      AS DWORD               ' DOT11_PHY_TYPE
   uDot11PhyIndex    AS DWORD               ' ULONG
   wlanSignalQuality AS DWORD               ' WLAN_SIGNAL_QUALITY
   ulRxRate          AS DWORD               ' ULONG
   ulTxRate          AS DWORD               ' ULONG
END TYPE

' // Size = 16 bytes
TYPE WLAN_SECURITY_ATTRIBUTES DWORD
   bSecurityEnabled     AS LONG   ' BOOL
   bOneXEnabled         AS LONG   ' BOOL
   dot11AuthAlgorithm   AS LONG   ' DOT11_AUTH_ALGORITHM
   dot11CipherAlgorithm AS LONG   ' DOT11_CIPHER_ALGORITHM
END TYPE

'// structure WLAN_CONNECTION_ATTRIBUTES defines attributes of a wireless connection
' // Size = 604 bytes
TYPE WLAN_CONNECTION_ATTRIBUTES DWORD
   isState                   AS LONG   ' WLAN_INTERFACE_STATE
   wlanConnectionMode        AS LONG   ' WLAN_CONNECTION_MODE
   strProfileName            AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH   ' WCHAR
   wlanAssociationAttributes AS WLAN_ASSOCIATION_ATTRIBUTES
   wlanSecurityAttributes    AS WLAN_SECURITY_ATTRIBUTES
END TYPE

'// use the 4-byte enum
' enum _DOT11_RADIO_STATE
%dot11_radio_state_unknown = 0
%dot11_radio_state_on      = 1
%dot11_radio_state_off     = 2

'// the maximum number of PHYs supported by a NIC
%WLAN_MAX_PHY_INDEX = 64

' // Size = 12 bytes
TYPE WLAN_PHY_RADIO_STATE DWORD
   dwPhyIndex              AS DWORD
   dot11SoftwareRadioState AS LONG    ' DOT11_RADIO_STATE
   dot11HardwareRadioState AS LONG    ' DOT11_RADIO_STATE
END TYPE

' // Size = 772 bytes
TYPE WLAN_RADIO_STATE DWORD
   dwNumberOfPhys AS DWORD
   PhyRadioState(%WLAN_MAX_PHY_INDEX - 1) AS WLAN_PHY_RADIO_STATE
END TYPE

' enum WLAN_INTERFACE_TYPE
%wlan_interface_type_emulated_802_11 = 0
%wlan_interface_type_native_802_11   = 1
%wlan_interface_type_invalid         = 2

' // Size = 276 bytes
TYPE WLAN_INTERFACE_CAPABILITY DWORD
   interfaceType             AS LONG   ' WLAN_INTERFACE_TYPE
   bDot11DSupported          AS LONG   ' BOOL
   dwMaxDesiredSsidListSize  AS DWORD   ' DWORD
   dwMaxDesiredBssidListSize AS DWORD   ' DWORD
   dwNumberOfSupportedPhys   AS DWORD   ' DWORD
   dot11PhyTypes(%WLAN_MAX_PHY_INDEX - 1) AS DWORD   ' DOT11_PHY_TYPE
END TYPE

' // Size = 12 bytes
TYPE WLAN_AUTH_CIPHER_PAIR_LIST DWORD
   dwNumberOfItems AS DWORD   ' DWORD
   pAuthCipherPairList(0) AS DOT11_AUTH_CIPHER_PAIR
END TYPE

' // Size = 8 bytes
TYPE WLAN_COUNTRY_OR_REGION_STRING_LIST DWORD
   dwNumberOfItems AS DWORD
   pCountryOrRegionStringList(0) AS DOT11_COUNTRY_OR_REGION_STRING
END TYPE

' // Size = 524 bytes
TYPE WLAN_PROFILE_INFO_LIST DWORD
   dwNumberOfItems AS DWORD   ' DWORD
   dwIndex         AS DWORD   ' DWORD
   ProfileInfo(0)  AS WLAN_PROFILE_INFO
END TYPE

' // Size = 636 bytes
TYPE WLAN_AVAILABLE_NETWORK_LIST DWORD
   dwNumberOfItems AS DWORD   ' DWORD
   dwIndex         AS DWORD   ' DWORD
   Network(0)      AS WLAN_AVAILABLE_NETWORK
END TYPE

' // Size = 540 bytes
TYPE WLAN_INTERFACE_INFO_LIST DWORD
   dwNumberOfItems  AS DWORD   ' DWORD
   dwIndex          AS DWORD   ' DWORD
   InterfaceInfo(0) AS WLAN_INTERFACE_INFO
END TYPE

'// network list
' // Size = 48 bytes
TYPE DOT11_NETWORK_LIST DWORD
   dwNumberOfItems AS DWORD   ' DWORD
   dwIndex         AS DWORD   ' DWORD
   Network(0)      AS DOT11_NETWORK
END TYPE

'// power settings
' enum WLAN_POWER_SETTING
%wlan_power_setting_no_saving      = 0
%wlan_power_setting_low_saving     = 1
%wlan_power_setting_medium_saving  = 2
%wlan_power_setting_maximum_saving = 3
%wlan_power_setting_invalid        = 4

'// Wlan connection flags used in WLAN_CONNECTION_PARAMETERS
'// The network to be connected is a hidden network
'// This flag cannnot be set if the network to connected is an ad hoc network
%WLAN_CONNECTION_HIDDEN_NETWORK      = &H00000001???

'// Only join an ad hoc network, do not form it if it doesn't exist
'// This flag cannnot be set if the network to connected is not an ad hoc network
%WLAN_CONNECTION_ADHOC_JOIN_ONLY     = &H00000002???

'// Ignore the privacy bit for the association. This is used to support easy config.
'// This flag is valid only for wlan_connection_mode_temporary_profile and infrastructure networks.
%WLAN_CONNECTION_IGNORE_PRIVACY_BIT  = &H00000004???

'// Exempt EAPOL traffic from encryption/decryption. This is used to
'// support an application that needs to send EAPOL traffic in non-802.1x WEP
'// networks. This flag is valid only for wlan_connection_mode_temporary_profile
'// in infrastructure networks when using authentication algorithm Open and
'// Cipher WEP with 802.1x disabled
%WLAN_CONNECTION_EAPOL_PASSTHROUGH   = &H00000008???

'// connection parameters
' // Size = 24 bytes
TYPE WLAN_CONNECTION_PARAMETERS DWORD
   wlanConnectionMode AS LONG                   ' WLAN_CONNECTION_MODE
   strProfile         AS WSTRINGZ PTR           ' LPCWSTR
   pDot11Ssid         AS DOT11_SSID PTR         ' PDOT11_SSID
   pDesiredBssidList  AS DOT11_BSSID_LIST PTR   ' PDOT11_BSSID_LIST
   dot11BssType       AS LONG                   ' DOT11_BSS_TYPE
   dwFlags            AS DWORD                  ' DWORD
END TYPE

'// data structure for connection-related notifications.
' // Size = 580 bytes
TYPE WLAN_MSM_NOTIFICATION_DATA DWORD
   wlanConnectionMode AS LONG                                 ' WLAN_CONNECTION_MODE
   strProfileName     AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH     ' WCHAR
   dot11Ssid          AS DOT11_SSID
   dot11BssType       AS LONG                                 ' DOT11_BSS_TYPE
   dot11MacAddr       AS DOT11_MAC_ADDRESS
   bSecurityEnabled   AS LONG                                 ' BOOL
   bFirstPeer         AS LONG                                 ' BOOL
   bLastPeer          AS LONG                                 ' BOOL
   wlanReasonCode     AS DWORD                                ' WLAN_REASON_CODE
END TYPE

'// flags for connection notifications
'// whether an adhoc network is formed or joined
%WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED = &H00000001???    ' // Formed ad hoc network
%WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE = &H00000004???    ' // The profile is the active console user's per user profile

' // Size = 572 bytes
TYPE WLAN_CONNECTION_NOTIFICATION_DATA DWORD
   wlanConnectionMode AS LONG                               ' WLAN_CONNECTION_MODE
   strProfileName     AS WSTRINGZ * %WLAN_MAX_NAME_LENGTH   ' WCHAR
   dot11Ssid          AS DOT11_SSID
   dot11BssType       AS LONG                               ' DOT11_BSS_TYPE
   bSecurityEnabled   AS LONG                               ' BOOL
   wlanReasonCode     AS DWORD                              ' WLAN_REASON_CODE
   dwFlags            AS DWORD                              ' DWORD
   strProfileXml      AS WSTRINGZ * 1                       ' WCHAR   ' variable-length
END TYPE

'// the types of notification
'// compatible with L2_NOTIFICATION_SOURCE
%WLAN_NOTIFICATION_SOURCE_NONE         = %L2_NOTIFICATION_SOURCE_NONE
%WLAN_NOTIFICATION_SOURCE_ALL          = %L2_NOTIFICATION_SOURCE_ALL

%WLAN_NOTIFICATION_SOURCE_ACM          = %L2_NOTIFICATION_SOURCE_WLAN_ACM
%WLAN_NOTIFICATION_SOURCE_MSM          = %L2_NOTIFICATION_SOURCE_WLAN_MSM
%WLAN_NOTIFICATION_SOURCE_SECURITY     = %L2_NOTIFICATION_SOURCE_WLAN_SECURITY
%WLAN_NOTIFICATION_SOURCE_IHV          = %L2_NOTIFICATION_SOURCE_WLAN_IHV
%WLAN_NOTIFICATION_SOURCE_HNWK         = %L2_NOTIFICATION_SOURCE_WLAN_HNWK
%WLAN_NOTIFICATION_SOURCE_ONEX         = %L2_NOTIFICATION_SOURCE_ONEX

' enum _WLAN_NOTIFICATION_ACM
%wlan_notification_acm_start = %L2_NOTIFICATION_CODE_PUBLIC_BEGIN
%wlan_notification_acm_autoconf_enabled = %wlan_notification_acm_start + 1
%wlan_notification_acm_autoconf_disabled = %wlan_notification_acm_autoconf_enabled + 1
%wlan_notification_acm_background_scan_enabled = %wlan_notification_acm_autoconf_disabled + 1
%wlan_notification_acm_background_scan_disabled = %wlan_notification_acm_background_scan_enabled + 1
%wlan_notification_acm_bss_type_change = %wlan_notification_acm_background_scan_disabled + 1
%wlan_notification_acm_power_setting_change = %wlan_notification_acm_bss_type_change + 1
%wlan_notification_acm_scan_complete = %wlan_notification_acm_power_setting_change + 1
%wlan_notification_acm_scan_fail = %wlan_notification_acm_scan_complete + 1
%wlan_notification_acm_connection_start = %wlan_notification_acm_scan_fail + 1
%wlan_notification_acm_connection_complete = %wlan_notification_acm_connection_start + 1
%wlan_notification_acm_connection_attempt_fail = %wlan_notification_acm_connection_complete + 1
%wlan_notification_acm_filter_list_change = %wlan_notification_acm_connection_attempt_fail + 1
%wlan_notification_acm_interface_arrival = %wlan_notification_acm_filter_list_change + 1
%wlan_notification_acm_interface_removal = %wlan_notification_acm_interface_arrival + 1
%wlan_notification_acm_profile_change = %wlan_notification_acm_interface_removal + 1
%wlan_notification_acm_profile_name_change = %wlan_notification_acm_profile_change + 1
%wlan_notification_acm_profiles_exhausted = %wlan_notification_acm_profile_name_change + 1
%wlan_notification_acm_network_not_available = %wlan_notification_acm_profiles_exhausted + 1
%wlan_notification_acm_network_available = %wlan_notification_acm_network_not_available + 1
%wlan_notification_acm_disconnecting = %wlan_notification_acm_network_available + 1
%wlan_notification_acm_disconnected = %wlan_notification_acm_disconnecting + 1
%wlan_notification_acm_adhoc_network_state_change = %wlan_notification_acm_disconnected + 1
%wlan_notification_acm_end = %wlan_notification_acm_adhoc_network_state_change + 1

' enum _WLAN_NOTIFICATION_MSM
%wlan_notification_msm_start = %L2_NOTIFICATION_CODE_PUBLIC_BEGIN
%wlan_notification_msm_associating = %wlan_notification_msm_start + 1
%wlan_notification_msm_associated = %wlan_notification_msm_associating + 1
%wlan_notification_msm_authenticating = %wlan_notification_msm_associated + 1
%wlan_notification_msm_connected = %wlan_notification_msm_authenticating + 1
%wlan_notification_msm_roaming_start = %wlan_notification_msm_connected + 1
%wlan_notification_msm_roaming_end = %wlan_notification_msm_roaming_start + 1
%wlan_notification_msm_radio_state_change = %wlan_notification_msm_roaming_end + 1
%wlan_notification_msm_signal_quality_change = %wlan_notification_msm_radio_state_change + 1
%wlan_notification_msm_disassociating = %wlan_notification_msm_signal_quality_change + 1
%wlan_notification_msm_disconnected = %wlan_notification_msm_disassociating + 1
%wlan_notification_msm_peer_join = %wlan_notification_msm_disconnected + 1
%wlan_notification_msm_peer_leave = %wlan_notification_msm_peer_join + 1
%wlan_notification_msm_adapter_removal = %wlan_notification_msm_peer_leave + 1
%wlan_notification_msm_adapter_operation_mode_change = %wlan_notification_msm_adapter_removal + 1
%wlan_notification_msm_end = %wlan_notification_msm_adapter_operation_mode_change + 1

' enum WLAN_NOTIFICATION_SECURITY
%wlan_notification_security_start = %L2_NOTIFICATION_CODE_PUBLIC_BEGIN
%wlan_notification_security_end   = %wlan_notification_security_start + 1

'typedef L2_NOTIFICATION_DATA WLAN_NOTIFICATION_DATA, *PWLAN_NOTIFICATION_DATA;
MACRO WLAN_NOTIFICATION_DATA = L2_NOTIFICATION_DATA

'// the callback function for notifications
'typedef VOID (WINAPI *WLAN_NOTIFICATION_CALLBACK) (PWLAN_NOTIFICATION_DATA, PVOID);
'SUB WLAN_NOTIFICATION_CALLBACK (BYREF WLAN_NOTIFICATION_DATA, BYVAL DWORD)

' enum WLAN_OPCODE_VALUE_TYPE
%wlan_opcode_value_type_query_only          = 0
%wlan_opcode_value_type_set_by_group_policy = 1
%wlan_opcode_value_type_set_by_user         = 2
%wlan_opcode_value_type_invalid             = 3

'// OpCodes for set/query interfaces
' enum WLAN_INTF_OPCODE
%wlan_intf_opcode_autoconf_start = &H000000000???
%wlan_intf_opcode_autoconf_enabled = %wlan_intf_opcode_autoconf_start + 1
%wlan_intf_opcode_background_scan_enabled = %wlan_intf_opcode_autoconf_enabled + 1
%wlan_intf_opcode_media_streaming_mode = %wlan_intf_opcode_background_scan_enabled + 1
%wlan_intf_opcode_radio_state = %wlan_intf_opcode_media_streaming_mode + 1
%wlan_intf_opcode_bss_type = %wlan_intf_opcode_radio_state + 1
%wlan_intf_opcode_interface_state = %wlan_intf_opcode_bss_type + 1
%wlan_intf_opcode_current_connection = %wlan_intf_opcode_interface_state + 1
%wlan_intf_opcode_channel_number = %wlan_intf_opcode_current_connection + 1
%wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs = %wlan_intf_opcode_channel_number + 1
%wlan_intf_opcode_supported_adhoc_auth_cipher_pairs = %wlan_intf_opcode_supported_infrastructure_auth_cipher_pairs + 1
%wlan_intf_opcode_supported_country_or_region_string_list = %wlan_intf_opcode_supported_adhoc_auth_cipher_pairs + 1
%wlan_intf_opcode_current_operation_mode = %wlan_intf_opcode_supported_country_or_region_string_list + 1
%wlan_intf_opcode_supported_safe_mode = %wlan_intf_opcode_current_operation_mode + 1
%wlan_intf_opcode_certified_safe_mode = %wlan_intf_opcode_supported_safe_mode + 1
%wlan_intf_opcode_hosted_network_capable = %wlan_intf_opcode_certified_safe_mode + 1
%wlan_intf_opcode_autoconf_end = &H0fffffff???
%wlan_intf_opcode_msm_start = &H10000100???
%wlan_intf_opcode_statistics = %wlan_intf_opcode_msm_start + 1
%wlan_intf_opcode_rssi = %wlan_intf_opcode_statistics + 1
%wlan_intf_opcode_msm_end = &H1fffffff???
%wlan_intf_opcode_security_start = &H20010000???
%wlan_intf_opcode_security_end = &H2fffffff???
%wlan_intf_opcode_ihv_start = &H30000000???
%wlan_intf_opcode_ihv_end = &H3fffffff???

'// OpCodes for set/query auto config parameters
' enum WLAN_AUTOCONF_OPCODE
%wlan_autoconf_opcode_start                                     = 0
%wlan_autoconf_opcode_show_denied_networks                      = 1
%wlan_autoconf_opcode_power_setting                             = 2
%wlan_autoconf_opcode_only_use_gp_profiles_for_allowed_networks = 3
%wlan_autoconf_opcode_allow_explicit_creds                      = 4
%wlan_autoconf_opcode_block_period                              = 5
%wlan_autoconf_opcode_allow_virtual_station_extensibility       = 6
%wlan_autoconf_opcode_end                                       = 7

'// IHV control types
' enum WLAN_IHV_CONTROL_TYPE
%wlan_ihv_control_type_service = 0
%wlan_ihv_control_type_driver  = 1

' enum _WLAN_FILTER_LIST_TYPE
%wlan_filter_list_type_gp_permit   = 0
%wlan_filter_list_type_gp_deny     = 1
%wlan_filter_list_type_user_permit = 2
%wlan_filter_list_type_user_deny   = 3

'// Driver statistics
' // Size = 144 bytes
TYPE WLAN_PHY_FRAME_STATISTICS QWORD
   ' // TX counters (MSDU/MMPDU)
   ullTransmittedFrameCount            AS QUAD   ' ULONGLONG
   ullMulticastTransmittedFrameCount   AS QUAD   ' ULONGLONG
   ullFailedCount                      AS QUAD   ' ULONGLONG
   ullRetryCount                       AS QUAD   ' ULONGLONG
   ullMultipleRetryCount               AS QUAD   ' ULONGLONG
   ullMaxTXLifetimeExceededCount       AS QUAD   ' ULONGLONG

   ' // TX counters (MPDU)
   ullTransmittedFragmentCount         AS QUAD   ' ULONGLONG
   ullRTSSuccessCount                  AS QUAD   ' ULONGLONG
   ullRTSFailureCount                  AS QUAD   ' ULONGLONG
   ullACKFailureCount                  AS QUAD   ' ULONGLONG

   ' // RX counters (MSDU/MMPDU)
   ullReceivedFrameCount               AS QUAD   ' ULONGLONG
   ullMulticastReceivedFrameCount      AS QUAD   ' ULONGLONG
   ullPromiscuousReceivedFrameCount    AS QUAD   ' ULONGLONG
   ullMaxRXLifetimeExceededCount       AS QUAD   ' ULONGLONG

   ' // RX counters (MPDU)
   ullFrameDuplicateCount              AS QUAD   ' ULONGLONG
   ullReceivedFragmentCount            AS QUAD   ' ULONGLONG
   ullPromiscuousReceivedFragmentCount AS QUAD   ' ULONGLONG
   ullFCSErrorCount                    AS QUAD   ' ULONGLONG
END TYPE

' // Size = 96 bytes
TYPE WLAN_MAC_FRAME_STATISTICS QWORD
   ullTransmittedFrameCount AS QUAD   ' ULONGLONG
   ullReceivedFrameCount    AS QUAD   ' ULONGLONG
   ullWEPExcludedCount      AS QUAD   ' ULONGLONG
   ullTKIPLocalMICFailures  AS QUAD   ' ULONGLONG
   ullTKIPReplays           AS QUAD   ' ULONGLONG
   ullTKIPICVErrorCount     AS QUAD   ' ULONGLONG
   ullCCMPReplays           AS QUAD   ' ULONGLONG
   ullCCMPDecryptErrors     AS QUAD   ' ULONGLONG
   ullWEPUndecryptableCount AS QUAD   ' ULONGLONG
   ullWEPICVErrorCount      AS QUAD   ' ULONGLONG
   ullDecryptSuccessCount   AS QUAD   ' ULONGLONG
   ullDecryptFailureCount   AS QUAD   ' ULONGLONG
END TYPE

' // Size = 368 bytes
TYPE WLAN_STATISTICS QWORD
   ullFourWayHandshakeFailures   AS QUAD   ' ULONGLONG
   ullTKIPCounterMeasuresInvoked AS QUAD   ' ULONGLONG
   ullReserved                   AS QUAD   ' ULONGLONG
   MacUcastCounters              AS WLAN_MAC_FRAME_STATISTICS
   MacMcastCounters              AS WLAN_MAC_FRAME_STATISTICS
   dwNumberOfPhys                AS DWORD   ' DWORD
   PhyCounters(0)                AS WLAN_PHY_FRAME_STATISTICS
END TYPE

'// API protection settings

'// Definition of access masks for setting non-default security
'// settings on WLAN configuration objects and connection profiles.

%WLAN_READ_ACCESS    = %STANDARD_RIGHTS_READ OR %FILE_READ_DATA
%WLAN_EXECUTE_ACCESS = %WLAN_READ_ACCESS OR %STANDARD_RIGHTS_EXECUTE OR %FILE_EXECUTE
%WLAN_WRITE_ACCESS   = %WLAN_READ_ACCESS OR %WLAN_EXECUTE_ACCESS OR %STANDARD_RIGHTS_WRITE OR %FILE_WRITE_DATA OR %DELETE OR %WRITE_DAC

' enum WLAN_SECURABLE_OBJECT
%wlan_secure_permit_list                    = 0
%wlan_secure_deny_list                      = 1
%wlan_secure_ac_enabled                     = 2
%wlan_secure_bc_scan_enabled                = 3
%wlan_secure_bss_type                       = 4
%wlan_secure_show_denied                    = 5
%wlan_secure_interface_properties           = 6
%wlan_secure_ihv_control                    = 7
%wlan_secure_all_user_profiles_order        = 8
%wlan_secure_add_new_all_user_profiles      = 9
%wlan_secure_add_new_per_user_profiles      = 10
%wlan_secure_media_streaming_mode_enabled   = 11
%wlan_secure_current_operation_mode         = 12
%wlan_secure_get_plaintext_key              = 13
%wlan_secure_hosted_network_elevated_access = 14
%wlan_secure_virtual_station_extensibility  = 15

'// public APIs

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanOpenHandle LIB "WLanApi.dll" ALIAS "WlanOpenHandle" ( _
    BYVAL dwClientVersion AS DWORD, _
    pReserved             AS ANY, _    ' PVOID
    pdwNegotiatedVersion  AS DWORD , _
    phClientHandle        AS DWORD _   ' PHANDLE
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanOpenHandle IMPORT "Wlanapi.dll" ALIAS "WlanOpenHandle" ( _
   BYVAL dwClientVersion AS DWORD _                     ' __in DWORD dwClientVersion
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwNegotiatedVersion AS DWORD _                ' __out PDWORD pdwNegotiatedVersion
 , BYREF phClientHandle AS DWORD _                      ' __out PHANDLE phClientHandle
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanCloseHandle LIB "WLanApi.dll" ALIAS "WlanCloseHandle" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanCloseHandle IMPORT "Wlanapi.dll" ALIAS "WlanCloseHandle" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanEnumInterfaces LIB "WLanApi.dll" _
    ALIAS "WlanEnumInterfaces" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pReserved           AS ANY, _    ' PVOID
    ppInterfaceList     AS ANY _     ' PWLAN_INTERFACE_INFO_LIST *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanEnumInterfaces IMPORT "Wlanapi.dll" ALIAS "WlanEnumInterfaces" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppInterfaceList AS DWORD _                     ' __out PWLAN_INTERFACE_INFO_LIST *ppInterfaceList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetAutoConfigParameter LIB "WLanApi.dll" _
    ALIAS "WlanSetAutoConfigParameter" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    BYVAL OpCode        AS LONG, _
    BYVAL dwDataSize    AS DWORD, _
    pData               AS ANY, _    ' PVOID
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetAutoConfigParameter IMPORT "Wlanapi.dll" ALIAS "WlanSetAutoConfigParameter" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL OpCode AS LONG _                               ' __in WLAN_AUTOCONF_OPCODE OpCode
 , BYVAL dwDataSize AS DWORD _                          ' __in DWORD dwDataSize
 , BYREF pData AS ANY _                                 ' __in CONST PVOID pData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanQueryAutoConfigParameter LIB "WLanApi.dll" _
    ALIAS "WlanQueryAutoConfigParameter" ( _
    BYVAL hClientHandle  AS DWORD, _  ' HANDLE
    BYVAL OpCode         AS LONG, _
    pReserved            AS ANY, _    ' PVOID
    pdwDataSize          AS DWORD, _
    ppData               AS ANY, _    ' PVOID *
    pWlanOpcodeValueType AS LONG  _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanQueryAutoConfigParameter IMPORT "Wlanapi.dll" ALIAS "WlanQueryAutoConfigParameter" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL OpCode AS LONG _                               ' __in WLAN_AUTOCONF_OPCODE OpCode
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwDataSize AS DWORD _                         ' __out PDWORD pdwDataSize
 , BYREF ppData AS ANY _                                ' __out PVOID *ppData
 , BYREF pWlanOpcodeValueType AS LONG _                 ' __out_opt PWLAN_OPCODE_VALUE_TYPE pWlanOpcodeValueType
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetInterfaceCapability LIB "WLanApi.dll" _
    ALIAS "WlanGetInterfaceCapability" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    pReserved           AS ANY, _    ' PVOID
    ppCapability        AS ANY _     ' PWLAN_INTERFACE_CAPABILITY *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetInterfaceCapability IMPORT "Wlanapi.dll" ALIAS "WlanGetInterfaceCapability" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppCapability AS WLAN_INTERFACE_CAPABILITY _    ' __out PWLAN_INTERFACE_CAPABILITY *ppCapability
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetInterface LIB "WLanApi.dll" _
    ALIAS "WlanSetInterface" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    BYVAL OpCode        AS LONG, _
    BYVAL dwDataSize    AS DWORD, _
    pData               AS ANY, _    ' PVOID
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetInterface IMPORT "Wlanapi.dll" ALIAS "WlanSetInterface" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL OpCode AS DWORD _                              ' __in WLAN_INTF_OPCODE OpCode
 , BYVAL dwDataSize AS DWORD _                          ' __in DWORD dwDataSize
 , BYREF pData AS ANY _                                 ' __in CONST PVOID pData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanQueryInterface LIB "WLanApi.dll" _
    ALIAS "WlanQueryInterface" ( _
    BYVAL hClientHandle  AS DWORD, _  ' HANDLE
    pInterfaceGuid       AS GUID, _
    BYVAL OpCode         AS LONG, _
    pReserved            AS ANY, _  ' PVOID
    pdwDataSize          AS DWORD, _
    ppData               AS ANY, _  ' PVOID *
    pWlanOpcodeValueType AS LONG _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanQueryInterface IMPORT "Wlanapi.dll" ALIAS "WlanQueryInterface" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL OpCode AS DWORD _                              ' __in WLAN_INTF_OPCODE OpCode
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwDataSize AS DWORD _                         ' __out PDWORD pdwDataSize
 , BYREF ppData AS ANY _                                ' __out PVOID *ppData
 , BYREF pWlanOpcodeValueType AS LONG _                 ' __out_opt PWLAN_OPCODE_VALUE_TYPE pWlanOpcodeValueType
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION WlanIhvControl IMPORT "Wlanapi.dll" ALIAS "WlanIhvControl" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL Type AS LONG _                                 ' __in WLAN_IHV_CONTROL_TYPE Type
 , BYVAL dwInBufferSize AS DWORD _                      ' __in DWORD dwInBufferSize
 , BYREF pInBuffer AS ANY _                             ' __in PVOID pInBuffer
 , BYVAL dwOutBufferSize AS DWORD _                     ' __in DWORD dwOutBufferSize
 , BYREF pOutBuffer AS ANY _                            ' __in_out PVOID pOutBuffer
 , BYREF pdwBytesReturned AS DWORD _                    ' __out PDWORD pdwBytesReturned
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanScan LIB "WLanApi.dll" ALIAS "WlanScan" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    pDot11Ssid          AS DOT11_SSID, _
    pIeData             AS WLAN_RAW_DATA, _
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanScan IMPORT "Wlanapi.dll" ALIAS "WlanScan" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF pDot11Ssid AS DOT11_SSID _                     ' __in_opt CONST PDOT11_SSID pDot11Ssid
 , BYREF pIeData AS WLAN_RAW_DATA _                     ' __in_opt CONST PWLAN_RAW_DATA pIeData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetAvailableNetworkList LIB "WLanApi.dll" _
    ALIAS "WlanGetAvailableNetworkList" ( _
    BYVAL hClientHandle    AS DWORD, _  ' HANDLE
    pInterfaceGuid         AS GUID, _
    BYVAL dwFlags          AS DWORD , _
    pReserved              AS ANY, _    ' PVOID
    ppAvailableNetworkList AS ANY _     ' PWLAN_AVAILABLE_NETWORK_LIST *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetAvailableNetworkList IMPORT "Wlanapi.dll" ALIAS "WlanGetAvailableNetworkList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppAvailableNetworkList AS WLAN_AVAILABLE_NETWORK_LIST _ ' __out PWLAN_AVAILABLE_NETWORK_LIST *ppAvailableNetworkList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetNetworkBssList LIB "WLanApi.dll" _
    ALIAS "WlanGetNetworkBssList" ( _
    BYVAL hClientHandle    AS DWORD, _  ' HANDLE
    pInterfaceGuid         AS GUID, _
    pDot11Ssid             AS DOT11_SSID, _
    BYVAL dot11BssType     AS LONG, _
    BYVAL bSecurityEnabled AS LONG, _   ' BOOL
    pReserved              AS ANY, _    ' PVOID
    ppWlanBssList          AS ANY _     ' PWLAN_BSS_LIST *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetNetworkBssList IMPORT "Wlanapi.dll" ALIAS "WlanGetNetworkBssList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF pDot11Ssid AS DOT11_SSID _                     ' __in_opt CONST PDOT11_SSID pDot11Ssid
 , BYVAL dot11BssType AS LONG _                         ' __in DOT11_BSS_TYPE dot11BssType
 , BYVAL bSecurityEnabled AS LONG _                     ' __in BOOL bSecurityEnabled
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppWlanBssList AS WLAN_BSS_LIST _               ' __out PWLAN_BSS_LIST *ppWlanBssList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanConnect LIB "WLanApi.dll" ALIAS "WlanConnect" ( _
    BYVAL hClientHandle   AS DWORD, _  '  HANDLE
    pInterfaceGuid        AS GUID, _
    pConnectionParameters AS WLAN_CONNECTION_PARAMETERS, _
    pReserved             AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanConnect IMPORT "Wlanapi.dll" ALIAS "WlanConnect" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF pConnectionParameters AS WLAN_CONNECTION_PARAMETERS _ ' __in CONST PWLAN_CONNECTION_PARAMETERS pConnectionParameters
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanDisconnect LIB "WLanApi.dll" ALIAS "WlanDisconnect" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanDisconnect IMPORT "Wlanapi.dll" ALIAS "WlanDisconnect" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanRegisterNotification LIB "WLanApi.dll" _
    ALIAS "WlanRegisterNotification" ( _
    BYVAL hClientHandle    AS DWORD, _  ' HANDLE
    BYVAL dwNotifSource    AS DWORD, _
    BYVAL bIgnoreDuplicate AS LONG, _   ' BOOL
    BYVAL funcCallback     AS DWORD, _  ' WLAN_NOTIFICATION_CALLBACK
    pCallbackContext       AS ANY, _    ' PVOID
    pReserved              AS ANY, _    ' PVOID
    pdwPrevNotifSource     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanRegisterNotification IMPORT "Wlanapi.dll" ALIAS "WlanRegisterNotification" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL dwNotifSource AS DWORD _                       ' __in DWORD dwNotifSource
 , BYVAL bIgnoreDuplicate AS LONG _                     ' __in BOOL bIgnoreDuplicate
 , BYVAL funcCallback AS DWORD _                        ' __in_opt WLAN_NOTIFICATION_CALLBACK funcCallback
 , BYVAL pCallbackContext AS DWORD _                    ' __in_opt PVOID pCallbackContext
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwPrevNotifSource AS DWORD _                  ' __out_opt PDWORD pdwPrevNotifSource
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetProfile LIB "WLanApi.dll" ALIAS "WlanGetProfile" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    pReserved           AS ANY, _    ' PVOID
    pstrProfileXml      AS ANY, _    ' LPWSTR
    pdwFlags            AS DWORD, _
    pdwGrantedAccess    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetProfile IMPORT "Wlanapi.dll" ALIAS "WlanGetProfile" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pstrProfileXml AS DWORD _                      ' __out LPWSTR *pstrProfileXml
 , BYREF pdwFlags AS DWORD _                            ' __inout_opt DWORD *pdwFlags
 , BYREF pdwGrantedAccess AS DWORD _                    ' __out_opt DWORD *pdwGrantedAccess
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfileEapUserData LIB "WLanApi.dll" _
    ALIAS "WlanSetProfileEapUserData" ( _
    BYVAL hClientHandle     AS DWORD, _  ' HANDLE
    pInterfaceGuid          AS GUID, _
    strProfileName          AS WSTRINGZ, _
    BYVAL eapType           AS EAP_METHOD_TYPE, _
    BYVAL dwFlags           AS DWORD, _
    BYVAL dwEapUserDataSize AS DWORD, _
    BYVAL pbEapUserData     AS BYTE PTR, _
    pReserved               AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfileEapUserData IMPORT "Wlanapi.dll" ALIAS "WlanSetProfileEapUserData" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL eapType AS EAP_METHOD_TYPE _                   ' __in EAP_METHOD_TYPE eapType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwEapUserDataSize AS DWORD _                   ' __in DWORD dwEapUserDataSize
 , BYVAL pbEapUserData AS BYTE PTR _                    ' __in const LPBYTE pbEapUserData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfileEapXmlUserData LIB "WLanApi.dll" _
    ALIAS "WlanSetProfileEapXmlUserData" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    BYVAL dwFlags       AS DWORD, _
    strEapXmlUserData   AS WSTRINGZ, _
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfileEapXmlUserData IMPORT "Wlanapi.dll" ALIAS "WlanSetProfileEapXmlUserData" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF strEapXmlUserData AS WSTRINGZ _                ' __in LPCWSTR strEapXmlUserData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfile LIB "WLanApi.dll" ALIAS "WlanSetProfile" ( _
    BYVAL hClientHandle       AS DWORD, _  ' HANDLE
    pInterfaceGuid            AS GUID, _
    BYVAL dwFlags             AS DWORD, _
    strProfileXml             AS WSTRINGZ, _
    strAllUserProfileSecurity AS WSTRINGZ, _
    BYVAL bOverwrite          AS LONG, _   ' BOOL
    pReserved                 AS ANY, _    ' PVOID
    pdwReasonCode             AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfile IMPORT "Wlanapi.dll" ALIAS "WlanSetProfile" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF strProfileXml AS WSTRINGZ _                    ' __in LPCWSTR strProfileXml
 , BYREF strAllUserProfileSecurity AS WSTRINGZ _        ' __in_opt LPCWSTR strAllUserProfileSecurity
 , BYVAL bOverwrite AS LONG _                           ' __in BOOL bOverwrite
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwReasonCode AS DWORD _                       ' __out DWORD *pdwReasonCode
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanDeleteProfile LIB "WLanApi.dll" _
    ALIAS "WlanDeleteProfile" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    pReserved           AS ANY _     ' PVOID
) AS DWORD
#ELSE
DECLARE FUNCTION WlanDeleteProfile IMPORT "Wlanapi.dll" ALIAS "WlanDeleteProfile" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanRenameProfile LIB "WLanApi.dll" _
    ALIAS "WlanRenameProfile" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strOldProfileName   AS WSTRINGZ, _
    strNewProfileName   AS WSTRINGZ, _
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanRenameProfile IMPORT "Wlanapi.dll" ALIAS "WlanRenameProfile" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strOldProfileName AS WSTRINGZ _                ' __in LPCWSTR strOldProfileName
 , BYREF strNewProfileName AS WSTRINGZ _                ' __in LPCWSTR strNewProfileName
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetProfileList LIB "WLanApi.dll" _
    ALIAS "WlanGetProfileList" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    pReserved           AS ANY, _    ' PVOID
    BYVAL ppProfileList AS WLAN_PROFILE_INFO_LIST PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetProfileList IMPORT "Wlanapi.dll" ALIAS "WlanGetProfileList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppProfileList AS WLAN_PROFILE_INFO_LIST _      ' __out PWLAN_PROFILE_INFO_LIST *ppProfileList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfileList LIB "WLanApi.dll" _
    ALIAS "WlanSetProfileList" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    BYVAL dwItems       AS DWORD, _
    strProfileNames     AS ANY, _    ' LPCWSTR *
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfileList IMPORT "Wlanapi.dll" ALIAS "WlanSetProfileList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYVAL dwItems AS DWORD _                             ' __in DWORD dwItems
 , BYREF strProfileNames AS WSTRINGZ _                  ' __in LPCWSTR *strProfileNames
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfilePosition LIB "WLanApi.dll" _
    ALIAS "WlanSetProfilePosition" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    BYVAL dwPosition    AS DWORD, _
    pReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfilePosition IMPORT "Wlanapi.dll" ALIAS "WlanSetProfilePosition" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL dwPosition AS DWORD _                          ' __in DWORD dwPosition
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetProfileCustomUserData LIB "WLanApi.dll" _
    ALIAS "WlanSetProfileCustomUserData" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    BYVAL dwDataSize    AS DWORD, _
    BYVAL pData         AS BYTE PTR, _
    pReserved           AS ANY _  ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetProfileCustomUserData IMPORT "Wlanapi.dll" ALIAS "WlanSetProfileCustomUserData" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL dwDataSize AS DWORD _                          ' __in DWORD dwDataSize
 , BYVAL pData AS BYTE PTR _                            ' __in CONST PBYTE pData
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetProfileCustomUserData LIB "WLanApi.dll" _
    ALIAS "WlanGetProfileCustomUserData" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pInterfaceGuid      AS GUID, _
    strProfileName      AS WSTRINGZ, _
    pReserved           AS ANY, _    ' PVOID
    pdwDataSize         AS DWORD, _
    ppData              AS ANY _     ' PBYTE *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetProfileCustomUserData IMPORT "Wlanapi.dll" ALIAS "WlanGetProfileCustomUserData" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pdwDataSize AS DWORD _                         ' __out DWORD pdwDataSize
 , BYREF ppData AS ANY _                                ' __out PBYTE *ppData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetFilterList LIB "WLanApi.dll" _
    ALIAS "WlanSetFilterList" ( _
    BYVAL hClientHandle      AS DWORD, _ ' HANDLE
    BYVAL wlanFilterListType AS LONG, _
    BYVAL pNetworkList       AS DOT11_NETWORK_LIST PTR, _
    pReserved                AS ANY _    ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetFilterList IMPORT "Wlanapi.dll" ALIAS "WlanSetFilterList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL wlanFilterListType AS LONG _                   ' __in WLAN_FILTER_LIST_TYPE wlanFilterListType
 , BYREF pNetworkList AS DOT11_NETWORK_LIST _           ' __in_opt CONST PDOT11_NETWORK_LIST pNetworkList
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetFilterList LIB "WLanApi.dll" _
    ALIAS "WlanGetFilterList" ( _
    BYVAL hClientHandle      AS DWORD, _  ' HANDLE
    BYVAL wlanFilterListType AS LONG, _
    pReserved                AS ANY, _    ' PVOID
    ppNetworkList            AS ANY _     ' PDOT11_NETWORK_LIST *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetFilterList IMPORT "Wlanapi.dll" ALIAS "WlanGetFilterList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL wlanFilterListType AS LONG _                   ' __in WLAN_FILTER_LIST_TYPE wlanFilterListType
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppNetworkList AS DOT11_NETWORK_LIST _          ' __out PDOT11_NETWORK_LIST *ppNetworkList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSetPsdIEDataList LIB "WLanApi.dll" _
    ALIAS "WlanSetPsdIEDataList" ( _
    BYVAL hClientHandle  AS DWORD, _  ' HANDLE
    strFormat            AS WSTRINGZ, _
    BYVAL pPsdIEDataList AS WLAN_RAW_DATA_LIST PTR, _
    pReserved            AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSetPsdIEDataList IMPORT "Wlanapi.dll" ALIAS "WlanSetPsdIEDataList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF strFormat AS WSTRINGZ _                        ' __in_opt LPCWSTR strFormat
 , BYREF pPsdIEDataList AS WLAN_RAW_DATA_LIST _         ' __in_opt CONST PWLAN_RAW_DATA_LIST pPsdIEDataList
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanSaveTemporaryProfile LIB "WLanApi.dll" _
    ALIAS "WlanSaveTemporaryProfile" ( _
    BYVAL hClientHandle       AS DWORD, _  ' HANDLE
    pInterfaceGuid            AS GUID, _
    strProfileName            AS WSTRINGZ, _
    strAllUserProfileSecurity AS WSTRINGZ, _
    BYVAL dwFlags             AS DWORD, _
    BYVAL bOverWrite          AS LONG, _   ' BOOL
    pReserved                 AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanSaveTemporaryProfile IMPORT "Wlanapi.dll" ALIAS "WlanSaveTemporaryProfile" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF pInterfaceGuid AS GUID _                       ' __in CONST GUID *pInterfaceGuid
 , BYREF strProfileName AS WSTRINGZ _                   ' __in LPCWSTR strProfileName
 , BYREF strAllUserProfileSecurity AS WSTRINGZ _        ' __in_opt LPCWSTR strAllUserProfileSecurity
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL bOverWrite AS LONG _                           ' __in BOOL bOverWrite
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'// client side APIs

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanExtractPsdIEDataList LIB "WLanApi.dll" _
    ALIAS "WlanExtractPsdIEDataList" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE,
    BYVAL dwIeDataSize  AS DWORD, _
    BYVAL pRawIeData    AS BYTE PTR, _
    strFormat           AS WSTRINGZ, _
    pReserved           AS ANY, _    ' PVOID,
    ppPsdIEDataList     AS ANY _     ' PWLAN_RAW_DATA_LIST *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanExtractPsdIEDataList IMPORT "Wlanapi.dll" ALIAS "WlanExtractPsdIEDataList" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL dwIeDataSize AS DWORD _                        ' __in DWORD dwIeDataSize
 , BYVAL pRawIeData AS BYTE PTR _                       ' __in CONST PBYTE pRawIeData
 , BYREF strFormat AS WSTRINGZ _                        ' __in LPCWSTR strFormat
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF ppPsdIEDataList AS WLAN_RAW_DATA_LIST _        ' __out PWLAN_RAW_DATA_LIST *ppPsdIEDataList
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanReasonCodeToString LIB "WLanApi.dll" _
    ALIAS "WlanReasonCodeToString" ( _
    BYVAL dwReasonCode  AS DWORD, _
    BYVAL dwBufferSize  AS DWORD, _
    pStringBuffer       AS WSTRINGZ, _
    pReserved           AS ANY _  ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanReasonCodeToString IMPORT "Wlanapi.dll" ALIAS "WlanReasonCodeToString" ( _
   BYVAL dwReasonCode AS DWORD _                        ' __in DWORD dwReasonCode
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD dwBufferSize
 , BYREF pStringBuffer AS WSTRINGZ _                    ' __in PWCHAR pStringBuffer
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION WlanAllocateMemory IMPORT "Wlanapi.dll" ALIAS "WlanAllocateMemory" ( _
   BYVAL dwMemorySize AS DWORD _                        ' __in DWORD dwMemorySize
 ) AS DWORD                                             ' PVOID

#IF %DEF(%USEPBDECL)
DECLARE SUB WlanFreeMemory LIB "WLanApi.dll" ALIAS "WlanFreeMemory" ( _
    pMemory AS ANY _  ' PVOID
    )
#ELSE
DECLARE SUB WlanFreeMemory IMPORT "Wlanapi.dll" ALIAS "WlanFreeMemory" ( _
   BYVAL pMemory AS DWORD _                             ' __in PVOID pMemory
 )                                                      ' VOID
#ENDIF

DECLARE FUNCTION WlanSetSecuritySettings IMPORT "Wlanapi.dll" ALIAS "WlanSetSecuritySettings" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL SecurableObject AS LONG _                      ' __in WLAN_SECURABLE_OBJECT SecurableObject
 , BYREF strModifiedSDDL AS WSTRINGZ _                  ' __in LPCWSTR strModifiedSDDL
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanGetSecuritySettings LIB "WLanApi.dll" _
    ALIAS "WlanGetSecuritySettings" ( _
    BYVAL hClientHandle   AS DWORD, _  ' HANDLE
    BYVAL SecurableObject AS LONG, _
    pValueType            AS LONG, _
    pstrCurrentSDDL       AS ANY, _    ' LPWSTR*,
    pdwGrantedAccess      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanGetSecuritySettings IMPORT "Wlanapi.dll" ALIAS "WlanGetSecuritySettings" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL SecurableObject AS LONG _                      ' __in WLAN_SECURABLE_OBJECT SecurableObject
 , BYREF pValueType AS LONG _                           ' __out_opt PWLAN_OPCODE_VALUE_TYPE pValueType
 , BYREF pstrCurrentSDDL AS DWORD _                     ' __out LPWSTR* pstrCurrentSDDL
 , BYREF pdwGrantedAccess AS DWORD _                    ' __out PDWORD pdwGrantedAccess
 ) AS DWORD                                             ' DWORD
#ENDIF


'// the following structures and defs are
'// for the UI related functions

'// current version
%WLAN_UI_API_VERSION         = 1
'// earliest version supported
%WLAN_UI_API_INITIAL_VERSION = 1

'// The list of pages displayed by the wireless profile UI
' enum WL_DISPLAY_PAGES
%WLConnectionPage = 0
%WLSecurityPage   = 1
%WLAdvPage        = 2

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanUIEditProfile LIB "WLanUI.dll" _
    ALIAS "WlanUIEditProfile" ( _
    BYVAL dwClientVersion AS DWORD, _
    wstrProfileName       AS WSTRINGZ, _
    pInterfaceGuid        AS GUID, _
    BYVAL hWnd            AS DWORD, _  ' HWND
    BYVAL wlStartPage     AS LONG, _
    pReserved             AS ANY, _    ' PVOID
    pWlanReasonCode       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanUIEditProfile IMPORT "Wlanapi.dll" ALIAS "WlanUIEditProfile" ( _
   BYVAL dwClientVersion AS DWORD _                     ' __in DWORD dwClientVersion
 , BYREF wstrProfileName AS WSTRINGZ _                  ' __in LPCWSTR wstrProfileName
 , BYREF pInterfaceGuid AS GUID _                       ' __in GUID *pInterfaceGuid
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wlStartPage AS LONG _                          ' __in WL_DISPLAY_PAGES wlStartPage
 , BYVAL pReserved AS DWORD _                           ' __reserved PVOID pReserved
 , BYREF pWlanReasonCode AS DWORD _                     ' __out_opt PWLAN_REASON_CODE pWlanReasonCode
 ) AS DWORD                                             ' DWORD
#ENDIF

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

'// Hosted Network APIs

' enum WLAN_HOSTED_NETWORK_STATE
%wlan_hosted_network_unavailable = 0
%wlan_hosted_network_idle        = 1
%wlan_hosted_network_active      = 2

' enum _WLAN_HOSTED_NETWORK_REASON
%wlan_hosted_network_reason_success                              = 0
%wlan_hosted_network_reason_unspecified                          = 1
%wlan_hosted_network_reason_bad_parameters                       = 2
%wlan_hosted_network_reason_service_shutting_down                = 3
%wlan_hosted_network_reason_insufficient_resources               = 4
%wlan_hosted_network_reason_elevation_required                   = 5
%wlan_hosted_network_reason_read_only                            = 6
%wlan_hosted_network_reason_persistence_failed                   = 7
%wlan_hosted_network_reason_crypt_error                          = 8
%wlan_hosted_network_reason_impersonation                        = 9
%wlan_hosted_network_reason_stop_before_start                    = 10

%wlan_hosted_network_reason_interface_available                  = 11
%wlan_hosted_network_reason_interface_unavailable                = 12
%wlan_hosted_network_reason_miniport_stopped                     = 13
%wlan_hosted_network_reason_miniport_started                     = 14
%wlan_hosted_network_reason_incompatible_connection_started      = 15
%wlan_hosted_network_reason_incompatible_connection_stopped      = 16
%wlan_hosted_network_reason_user_action                          = 17
%wlan_hosted_network_reason_client_abort                         = 18
%wlan_hosted_network_reason_ap_start_failed                      = 19

%wlan_hosted_network_reason_peer_arrived                         = 20
%wlan_hosted_network_reason_peer_departed                        = 21
%wlan_hosted_network_reason_peer_timeout                         = 22
%wlan_hosted_network_reason_gp_denied                            = 23
%wlan_hosted_network_reason_service_unavailable                  = 24
%wlan_hosted_network_reason_device_change                        = 25
%wlan_hosted_network_reason_properties_change                    = 26
%wlan_hosted_network_reason_virtual_station_blocking_use         = 27
%wlan_hosted_network_reason_service_available_on_virtual_station = 28

' enum _WLAN_HOSTED_NETWORK_PEER_AUTH_STATE
%wlan_hosted_network_peer_state_invalid       = 0
%wlan_hosted_network_peer_state_authenticated = 1

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkStartUsing LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkStartUsing" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkStartUsing IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkStartUsing" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in       HANDLE                      hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt  PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID                       pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkStopUsing LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkStopUsing" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkStopUsing IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkStopUsing" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in       HANDLE                      hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt  PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID                       pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkForceStart LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkForceStart" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkForceStart IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkForceStart" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in       HANDLE                      hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt  PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID                       pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkForceStop LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkForceStop" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkForceStop IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkForceStop" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in       HANDLE                      hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt  PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID                       pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

' // Size = 12 bytes
TYPE WLAN_HOSTED_NETWORK_PEER_STATE DWORD FILL
   PeerMacAddress AS DOT11_MAC_ADDRESS
   PeerAuthState  AS LONG   ' WLAN_HOSTED_NETWORK_PEER_AUTH_STATE
END TYPE

' // Size = 8 bytes
TYPE WLAN_HOSTED_NETWORK_RADIO_STATE DWORD
   dot11SoftwareRadioState AS LONG   ' DOT11_RADIO_STATE
   dot11HardwareRadioState AS LONG   ' DOT11_RADIO_STATE
END TYPE

'// Definitions required for calling WlanRegisterNotification
'// Notification source - L2_NOTIFICATION_SOURCE_WLAN_HNWK

'// Notification code
' enum _WLAN_HOSTED_NETWORK_NOTIFICATION_CODE
%wlan_hosted_network_state_change       = %L2_NOTIFICATION_CODE_V2_BEGIN
%wlan_hosted_network_peer_state_change  = %wlan_hosted_network_state_change + 1
%wlan_hosted_network_radio_state_change = %wlan_hosted_network_peer_state_change + 1

'// Notification data associated with wlan_hosted_network_state_change
' // Size = 12 bytes
TYPE WLAN_HOSTED_NETWORK_STATE_CHANGE DWORD
   OldState          AS LONG   ' WLAN_HOSTED_NETWORK_STATE
   NewState          AS LONG   ' WLAN_HOSTED_NETWORK_STATE
   StateChangeReason AS LONG   ' WLAN_HOSTED_NETWORK_REASON
END TYPE

'// Notification data associated with wlan_hosted_network_peer_state_change
' // Size = 28 bytes
TYPE WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE DWORD
   OldState              AS WLAN_HOSTED_NETWORK_PEER_STATE
   NewState              AS WLAN_HOSTED_NETWORK_PEER_STATE
   PeerStateChangeReason AS LONG   ' WLAN_HOSTED_NETWORK_REASON
END TYPE

'// Notification data associated with wlan_hosted_network_radio_state_change
'// WLAN_HOSTED_NETWORK_RADIO_STATE

'// Definitions required for calling WlanHostedNetworkQueryProperty and WlanHostedNetworkSetProperty

' enum WLAN_HOSTED_NETWORK_OPCODE
%wlan_hosted_network_opcode_connection_settings = 0
%wlan_hosted_network_opcode_security_settings   = 1
%wlan_hosted_network_opcode_station_profile     = 2
%wlan_hosted_network_opcode_enable              = 3

'// Data structure associated with wlan_hosted_network_opcode_connection_settings
'// can be used for query and set
' // Size = 40 bytes
TYPE WLAN_HOSTED_NETWORK_CONNECTION_SETTINGS DWORD
   hostedNetworkSSID  AS DOT11_SSID
   dwMaxNumberOfPeers AS DWORD   ' DWORD
END TYPE

'// Data structure associated with wlan_hosted_network_opcode_security_settings
'// can be used for query only
' // Size = 8 bytes
TYPE WLAN_HOSTED_NETWORK_SECURITY_SETTINGS DWORD
   dot11AuthAlgo   AS LONG   ' DOT11_AUTH_ALGORITHM
   dot11CipherAlgo AS LONG   ' DOT11_CIPHER_ALGORITHM
END TYPE

'// Data structure associated with wlan_hosted_network_opcode_station_profile
'// can be used for query only
'// LPWSTR

'// Data structure associated with wlan_hosted_network_opcode_enable
'// can be used for query and set
'// BOOL

'//
'// This function queries the static properties of the hosted network
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkQueryProperty LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkQueryProperty" ( _
    BYVAL hClientHandle  AS DWORD, _  ' HANDLE
    BYVAL OpCode         AS LONG, _
    pdwDataSize          AS DWORD, _
    ppvData              AS ANY, _    ' PVOID*
    pWlanOpcodeValueType AS LONG, _
    pvReserved           AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkQueryProperty IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkQueryProperty" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in  HANDLE  hClientHandle
 , BYVAL OpCode AS LONG _                               ' __in  WLAN_HOSTED_NETWORK_OPCODE OpCode
 , BYREF pdwDataSize AS DWORD _                         ' __out PDWORD pdwDataSize
 , BYREF ppvData AS ANY _                               ' __out PVOID* ppvData
 , BYREF pWlanOpcodeValueType AS LONG _                 ' __out PWLAN_OPCODE_VALUE_TYPE pWlanOpcodeValueType
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'//
'// This function sets the static properties of the hosted network
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkSetProperty LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkSetProperty" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    BYVAL OpCode        AS LONG, _
    BYVAL dwDataSize    AS DWORD, _
    pvData              AS ANY, _    ' PVOID
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkSetProperty IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkSetProperty" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in  HANDLE  hClientHandle
 , BYVAL OpCode AS LONG _                               ' __in  WLAN_HOSTED_NETWORK_OPCODE OpCode
 , BYVAL dwDataSize AS DWORD _                          ' __in  DWORD dwDataSize
 , BYVAL pvData AS DWORD _                              ' __in  PVOID pvData
 , BYREF pFailReason AS LONG _                          ' __out PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'//
'// This function initializes hosted network configuration
'// on a machine. There are no effects if an initial
'// configuration has already been created.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkInitSettings LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkInitSettings" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _  ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkInitSettings IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkInitSettings" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE  hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkRefreshSecuritySettings LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkRefreshSecuritySettings" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pFailReason         AS LONG, _
    pvReserved          AS ANY _  ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkRefreshSecuritySettings IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkRefreshSecuritySettings" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE  hClientHandle
 , BYREF pFailReason AS LONG _                          ' __out_opt PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

' // Size = 52 bytes
TYPE WLAN_HOSTED_NETWORK_STATUS DWORD
   HostedNetworkState     AS LONG                             ' WLAN_HOSTED_NETWORK_STATE
   IPDeviceID             AS GUID                             ' GUID
   wlanHostedNetworkBSSID AS DOT11_MAC_ADDRESS                ' DOT11_MAC_ADDRESS
   dot11PhyType           AS LONG                             ' DOT11_PHY_TYPE
   ulChannelFrequency     AS DWORD                            ' ULONG
   dwNumberOfPeers        AS DWORD                            ' DWORD
   PeerList(0)            AS WLAN_HOSTED_NETWORK_PEER_STATE   ' WLAN_HOSTED_NETWORK_PEER_STATE[1]
END TYPE

'//
'// This function queries the runtime status of the hosted network
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkQueryStatus LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkQueryStatus" ( _
    BYVAL hClientHandle       AS DWORD, _  ' HANDLE
    ppWlanHostedNetworkStatus AS ANY, _  ' PWLAN_HOSTED_NETWORK_STATUS*
    pvReserved                AS ANY _  ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkQueryStatus IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkQueryStatus" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYREF ppWlanHostedNetworkStatus AS WLAN_HOSTED_NETWORK_STATUS _ ' __out_opt PWLAN_HOSTED_NETWORK_STATUS* ppWlanHostedNetworkStatus
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'//
'// This function set the additional security key used by hosted network
'// if it is passphrase, key length includes the terminating '\0',
'// if not, key length is the number of bytes in the key data array.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkSetSecondaryKey LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkSetSecondaryKey" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    BYVAL dwKeyLength   AS DWORD, _
    pucKeyData          AS ANY, _    ' PUCHAR
    BYVAL bIsPassPhrase AS LONG, _   ' BOOL
    BYVAL bPersistent   AS LONG, _   ' BOOL
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkSetSecondaryKey IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkSetSecondaryKey" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL dwKeyLength AS DWORD _                         ' __in DWORD dwKeyLength
 , BYVAL pucKeyData AS BYTE PTR _                       ' __in PUCHAR pucKeyData
 , BYVAL bIsPassPhrase AS LONG _                        ' __in BOOL bIsPassPhrase
 , BYVAL bPersistent AS LONG _                          ' __in BOOL bPersistent
 , BYREF pFailReason AS LONG _                          ' __out_opt PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'//
'// This function query the additional security key used by hosted network
'// If it is passphrase, key length includes the terminating '\0',
'// if not, key length is the number of bytes in the key data array.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanHostedNetworkQuerySecondaryKey LIB "WLanApi.dll" _
    ALIAS "WlanHostedNetworkQuerySecondaryKey" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    pdwKeyLength        AS DWORD, _  ' DWORD
    ppucKeyData         AS ANY, _    ' PUCHAR*
    pbIsPassPhrase      AS LONG, _   ' BOOL
    pbPersistent        AS LONG, _   ' BOOL
    pFailReason         AS LONG, _
    pvReserved          AS ANY _     ' PVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION WlanHostedNetworkQuerySecondaryKey IMPORT "Wlanapi.dll" ALIAS "WlanHostedNetworkQuerySecondaryKey" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in  HANDLE hClientHandle
 , BYREF pdwKeyLength AS DWORD _                        ' __out DWORD pdwKeyLength
 , BYVAL pucKeyData AS BYTE PTR _                       ' __out PUCHAR *ppucKeyData
 , BYVAL bIsPassPhrase AS LONG _                        ' __in  BOOL bIsPassPhrase
 , BYVAL bPersistent AS LONG _                          ' __in  BOOL bPersistent
 , BYREF pFailReason AS LONG _                          ' __out_opt PWLAN_HOSTED_NETWORK_REASON pFailReason
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'//
'// This function is used to register and unregister notifications on virtual station.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WlanRegisterVirtualStationNotification LIB "WLanApi.dll" _
    ALIAS "WlanRegisterVirtualStationNotification" ( _
    BYVAL hClientHandle AS DWORD, _  ' HANDLE
    BYVAL bRegister     AS LONG, _   ' BOOL
    pReserved           AS ANY _     ' PVOID
) AS DWORD
#ELSE
DECLARE FUNCTION WlanRegisterVirtualStationNotification IMPORT "Wlanapi.dll" ALIAS "WlanRegisterVirtualStationNotification" ( _
   BYVAL hClientHandle AS DWORD _                       ' __in HANDLE hClientHandle
 , BYVAL bRegister AS LONG _                            ' __in BOOL bRegister
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
