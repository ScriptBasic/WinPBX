' ########################################################################################
' Microsoft Windows
' File: slerror.inc
' Contents: Error code definitions for the Software Licensing
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SLERROR_INC = 1

%SL_SERVER_ZONE     = &HB000   ' // zone for SL server errors
%SL_MSCH_ZONE       = &HC000   ' // zone for SL clearing house errors
' // = &HD000 is reserved for SP
%SL_INTERNAL_ZONE   = &HE000   ' // zone for SL service internal errors
%SL_CLIENTAPI_ZONE  = &HF000   ' // zone for SL client API errors

MACRO IS_SL_SERVER_ERROR(hr)    = ((hr AND &HF000) = %SL_SERVER_ZONE)
MACRO IS_SL_MSCH_ERROR(hr)      = ((hr AND &HF000) = %SL_MSCH_ZONE)
MACRO IS_SL_INTERNAL_ERROR(hr)  = ((hr AND &HF000) = %SL_INTERNAL_ZONE)
MACRO IS_SL_SERVICE_ERROR(hr)   = ((hr AND &HF000) = %SL_SERVICE_ZONE)
MACRO IS_SL_CLIENTAPI_ERROR(hr) = ((hr AND &HF000) = %SL_CLIENTAPI_ZONE)

MACRO IS_SL_VGA_STRICT_ERROR(hr) = (((hr AND &HF000) = %SL_MSCH_ZONE) AND ((hr AND &HFFF) >= &H401) AND ((hr & &HFFF) <= &H496))
MACRO IS_SL_VGA_LITE_ERROR(hr)   = (((hr AND &HF000) = %SL_MSCH_ZONE) AND ((hr AND &HFFF) >= &H497) AND ((hr & &HFFF) <= &H600))


'//////////////////////////////////////////////////////////
'//     SL Server errors
'//     These error codes come from SL Server
'//////////////////////////////////////////////////////////

'//
'//  Values are 32 bit values laid out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//
%FACILITY_SL_ITF                  = &H4


'//
'// Define the severity codes
'//
%STATUS_SEVERITY_WARNING          = &H2
%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_INFORMATIONAL    = &H1
%STATUS_SEVERITY_ERROR            = &H3


'//
'// MessageId: SL_E_SRV_INVALID_PUBLISH_LICENSE
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_PUBLISH_LICENSE = &HC004B001&

'//
'// MessageId: SL_E_SRV_INVALID_PRODUCT_KEY_LICENSE
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_PRODUCT_KEY_LICENSE = &HC004B002&

'//
'// MessageId: SL_E_SRV_INVALID_RIGHTS_ACCOUNT_LICENSE
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_RIGHTS_ACCOUNT_LICENSE = &HC004B003&

'//
'// MessageId: SL_E_SRV_INVALID_LICENSE_STRUCTURE
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_LICENSE_STRUCTURE = &HC004B004&

'//
'// MessageId: SL_E_SRV_AUTHORIZATION_FAILED
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_AUTHORIZATION_FAILED    = &HC004B005&

'//
'// MessageId: SL_E_SRV_INVALID_BINDING
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_BINDING         = &HC004B006&

'//
'// MessageId: SL_E_SRV_SERVER_PONG
'//
'// MessageText:
'//
'// The activation server reported that the computer could not connect to the activation server.
'//
%SL_E_SRV_SERVER_PONG             = &HC004B007&

'//
'// MessageId: SL_E_SRV_INVALID_PAYLOAD
'//
'// MessageText:
'//
'// The activation server determined that the computer could not be activated.
'//
%SL_E_SRV_INVALID_PAYLOAD         = &HC004B008&

'//
'// MessageId: SL_E_SRV_TRIAL_KEY
'//
'// MessageText:
'//
'// The activation server determined that you are using a trial product key.  You must change your product key before you can activate.
'//
'// *** Changes in the Windows 7 SDK to SL_E_SRV_INVALID_SECURITY_PROCESSOR_LICENSE ***
'%SL_E_SRV_TRIAL_KEY               = &HC004B009&

'// MessageId: SL_E_SRV_INVALID_SECURITY_PROCESSOR_LICENSE
'//
'// MessageText:
'//
'// The activation server determined that the license is invalid.
'//
%SL_E_SRV_INVALID_SECURITY_PROCESSOR_LICENSE = &HC004B009&

'//
'// MessageId: SL_E_SRV_CLIENT_CLOCK_OUT_OF_SYNC
'//
'// MessageText:
'//
'// The activation server determined that your computer clock time is not correct. You must correct your clock before you can activate.
'//
%SL_E_SRV_CLIENT_CLOCK_OUT_OF_SYNC = &HC004B011&

'//
'// MessageId: SL_E_SRV_GENERAL_ERROR
'//
'// MessageText:
'//
'// The activation server determined that the computer could not be activated.
'//
%SL_E_SRV_GENERAL_ERROR           = &HC004B100&

'////////////////////////////////////////////////////////////////
'//     Clearing house errors
'//     These error codes come from MSCH PA Implementation
'////////////////////////////////////////////////////////////////

'//
'// MessageId: SL_E_CHPA_PRODUCT_KEY_OUT_OF_RANGE
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_PRODUCT_KEY_OUT_OF_RANGE = &HC004C001&

'//
'// MessageId: SL_E_CHPA_INVALID_BINDING
'//
'// MessageText:
'//
'// The activation server determined there is a problem with the specified product key.
'//
%SL_E_CHPA_INVALID_BINDING        = &HC004C002&

'//
'// MessageId: SL_E_CHPA_PRODUCT_KEY_BLOCKED
'//
'// MessageText:
'//
'// The activation server determined the specified product key has been blocked.
'//
%SL_E_CHPA_PRODUCT_KEY_BLOCKED    = &HC004C003&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_KEY
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_KEY    = &HC004C004&

'//
'// MessageId: SL_E_CHPA_BINDING_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_BINDING_NOT_FOUND      = &HC004C005&

'//
'// MessageId: SL_E_CHPA_BINDING_MAPPING_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_BINDING_MAPPING_NOT_FOUND = &HC004C006&

'//
'// MessageId: SL_E_CHPA_UNSUPPORTED_PRODUCT_KEY
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_UNSUPPORTED_PRODUCT_KEY = &HC004C007&

'//
'// MessageId: SL_E_CHPA_MAXIMUM_UNLOCK_EXCEEDED
'//
'// MessageText:
'//
'// The activation server determined that the specified product key could not be used.
'//
%SL_E_CHPA_MAXIMUM_UNLOCK_EXCEEDED = &HC004C008&

'//
'// MessageId: SL_E_CHPA_ACTCONFIG_ID_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_ACTCONFIG_ID_NOT_FOUND = &HC004C009&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_DATA_ID
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_DATA_ID = &HC004C00A&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_DATA
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_DATA   = &HC004C00B&

'//
'// MessageId: SL_E_CHPA_SYSTEM_ERROR
'//
'// MessageText:
'//
'// The activation server experienced an error.
'//
%SL_E_CHPA_SYSTEM_ERROR           = &HC004C00C&

'//
'// MessageId: SL_E_CHPA_INVALID_ACTCONFIG_ID
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_INVALID_ACTCONFIG_ID   = &HC004C00D&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_KEY_LENGTH
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_KEY_LENGTH = &HC004C00E&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_KEY_FORMAT
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_KEY_FORMAT = &HC004C00F&

'//
'// MessageId: SL_E_CHPA_INVALID_PRODUCT_KEY_CHAR
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHPA_INVALID_PRODUCT_KEY_CHAR = &HC004C010&

'//
'// MessageId: SL_E_CHPA_INVALID_BINDING_URI
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHPA_INVALID_BINDING_URI    = &HC004C011&

'//
'// MessageId: SL_E_CHPA_NETWORK_ERROR
'//
'// MessageText:
'//
'// The activation server experienced a network error.
'//
%SL_E_CHPA_NETWORK_ERROR          = &HC004C012&

'//
'// MessageId: SL_E_CHPA_DATABASE_ERROR
'//
'// MessageText:
'//
'// The activation server experienced an error.
'//
%SL_E_CHPA_DATABASE_ERROR         = &HC004C013&

'//
'// MessageId: SL_E_CHPA_INVALID_ARGUMENT
'//
'// MessageText:
'//
'// The activation server experienced an error.
'//
%SL_E_CHPA_INVALID_ARGUMENT       = &HC004C014&

'//
'// MessageId: SL_E_CHPA_DMAK_LIMIT_EXCEEDED
'//
'// MessageText:
'//
'// The activation server reported that the Multiple Activation Key has exceeded its limit.
'//
%SL_E_CHPA_DMAK_LIMIT_EXCEEDED    = &HC004C020&

'//
'// MessageId: SL_E_CHPA_DMAK_EXTENSION_LIMIT_EXCEEDED
'//
'// MessageText:
'//
'// The activation server reported that the Multiple Activation Key extension limit has been exceeded.
'//
%SL_E_CHPA_DMAK_EXTENSION_LIMIT_EXCEEDED = &HC004C021&

'//
'// MessageId: SL_E_CHPA_REISSUANCE_LIMIT_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server reported that the re-issuance limit was not found.
'//
%SL_E_CHPA_REISSUANCE_LIMIT_NOT_FOUND = &HC004C022&

'//
'// MessageId: SL_E_CHPA_OVERRIDE_REQUEST_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server reported that the override request was not found.
'//
%SL_E_CHPA_OVERRIDE_REQUEST_NOT_FOUND = &HC004C023&

'//
'// MessageId: SL_E_CHPA_OEM_SLP_COA0
'//
'// MessageText:
'//
'// The activation server reported that the specified product key cannot be used for online activation.
'//
%SL_E_CHPA_OEM_SLP_COA0           = &HC004C016&

'// MessageId: SL_E_CHPA_PRODUCT_KEY_BLOCKED_IPLOCATION
'//
'// MessageText:
'//
'// The activation server determined the specified product key has been blocked for this geographic location.
'//
%SL_E_CHPA_PRODUCT_KEY_BLOCKED_IPLOCATION = &HC004C017&

'//
'// MessageId: SL_E_CHPA_RESPONSE_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The activation server experienced an error.
'//
%SL_E_CHPA_RESPONSE_NOT_AVAILABLE = &HC004C015&

'//
'// MessageId: SL_E_CHPA_GENERAL_ERROR
'//
'// MessageText:
'//
'// The activation server experienced a general error.
'//
%SL_E_CHPA_GENERAL_ERROR          = &HC004C050&

'//
'// MessageId: SL_E_CHPA_TIMEBASED_ACTIVATION_BEFORE_START_DATE
'//
'// MessageText:
'//
'// The activation server reported that time based activation attempted before start date.
'//
%SL_E_CHPA_TIMEBASED_ACTIVATION_BEFORE_START_DATE = &HC004C030&

'//
'// MessageId: SL_E_CHPA_TIMEBASED_ACTIVATION_AFTER_END_DATE
'//
'// MessageText:
'//
'// The activation server reported that time based activation attempted after end date.
'//
%SL_E_CHPA_TIMEBASED_ACTIVATION_AFTER_END_DATE = &HC004C031&

'//
'// MessageId: SL_E_CHPA_TIMEBASED_ACTIVATION_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The activation server reported that new time based activation not available.
'//
%SL_E_CHPA_TIMEBASED_ACTIVATION_NOT_AVAILABLE = &HC004C032&

'//
'// MessageId: SL_E_CHPA_TIMEBASED_PRODUCT_KEY_NOT_CONFIGURED
'//
'// MessageText:
'//
'// The activation server reported that time based product key not configured for activation.
'//
%SL_E_CHPA_TIMEBASED_PRODUCT_KEY_NOT_CONFIGURED = &HC004C033&

'//
'// MessageId: SL_E_CHPA_NO_RULES_TO_ACTIVATE
'//
'// MessageText:
'//
'// The activation server reported that no business rules available to activate specified product key.
'//
%SL_E_CHPA_NO_RULES_TO_ACTIVATE   = &HC004C04F&

'//
'// MessageId: SL_E_CHPA_BUSINESS_RULE_INPUT_NOT_FOUND
'//
'// MessageText:
'//
'// The activation server reported that business rule cound not find required input.
'//
%SL_E_CHPA_BUSINESS_RULE_INPUT_NOT_FOUND = &HC004C700&

'//
'// MessageId: SL_E_CHPA_NULL_VALUE_FOR_PROPERTY_NAME_OR_ID
'//
'// MessageText:
'//
'// The activation server reported that NULL value specified for business property name and Id.
'//
%SL_E_CHPA_NULL_VALUE_FOR_PROPERTY_NAME_OR_ID = &HC004C750&

'//
'// MessageId: SL_E_CHPA_UNKNOWN_PROPERTY_NAME
'//
'// MessageText:
'//
'// The activation server reported that property name specifies unknown property.
'//
%SL_E_CHPA_UNKNOWN_PROPERTY_NAME  = &HC004C751&

'//
'// MessageId: SL_E_CHPA_UNKNOWN_PROPERTY_ID
'//
'// MessageText:
'//
'// The activation server reported that property Id specifies unknown property.
'//
%SL_E_CHPA_UNKNOWN_PROPERTY_ID    = &HC004C752&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_UPDATE_PRODUCTKEY_BINDING
'//
'// MessageText:
'//
'// The activation server reported that it failed to update product key binding.
'//
%SL_E_CHPA_FAILED_TO_UPDATE_PRODUCTKEY_BINDING = &HC004C755&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_INSERT_PRODUCTKEY_BINDING
'//
'// MessageText:
'//
'// The activation server reported that it failed to insert product key binding.
'//
%SL_E_CHPA_FAILED_TO_INSERT_PRODUCTKEY_BINDING = &HC004C756&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_DELETE_PRODUCTKEY_BINDING
'//
'// MessageText:
'//
'// The activation server reported that it failed to delete product key binding.
'//
%SL_E_CHPA_FAILED_TO_DELETE_PRODUCTKEY_BINDING = &HC004C757&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_PROCESS_PRODUCT_KEY_BINDINGS_XML
'//
'// MessageText:
'//
'// The activation server reported that it failed to process input XML for product key bindings.
'//
%SL_E_CHPA_FAILED_TO_PROCESS_PRODUCT_KEY_BINDINGS_XML = &HC004C758&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_INSERT_PRODUCT_KEY_PROPERTY
'//
'// MessageText:
'//
'// The activation server reported that it failed to insert product key property.
'//
%SL_E_CHPA_FAILED_TO_INSERT_PRODUCT_KEY_PROPERTY = &HC004C75A&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_UPDATE_PRODUCT_KEY_PROPERTY
'//
'// MessageText:
'//
'// The activation server reported that it failed to update product key property.
'//
%SL_E_CHPA_FAILED_TO_UPDATE_PRODUCT_KEY_PROPERTY = &HC004C75B&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_DELETE_PRODUCT_KEY_PROPERTY
'//
'// MessageText:
'//
'// The activation server reported that it failed to delete product key property.
'//
%SL_E_CHPA_FAILED_TO_DELETE_PRODUCT_KEY_PROPERTY = &HC004C75C&

'//
'// MessageId: SL_E_CHPA_UNKNOWN_PRODUCT_KEY_TYPE
'//
'// MessageText:
'//
'// The activation server reported that the product key type is unknown.
'//
%SL_E_CHPA_UNKNOWN_PRODUCT_KEY_TYPE = &HC004C764&

'//
'// MessageId: SL_E_CHPA_PRODUCT_KEY_BEING_USED
'//
'// MessageText:
'//
'// The activation server reported that the product key type is being used by another user.
'//
%SL_E_CHPA_PRODUCT_KEY_BEING_USED = &HC004C770&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_INSERT_PRODUCT_KEY_RECORD
'//
'// MessageText:
'//
'// The activation server reported that it failed to insert product key record.
'//
%SL_E_CHPA_FAILED_TO_INSERT_PRODUCT_KEY_RECORD = &HC004C780&

'//
'// MessageId: SL_E_CHPA_FAILED_TO_UPDATE_PRODUCT_KEY_RECORD
'//
'// MessageText:
'//
'// The activation server reported that it failed to update product key record.
'//
%SL_E_CHPA_FAILED_TO_UPDATE_PRODUCT_KEY_RECORD = &HC004C781&

'////////////////////////////////////////////////////////////////
'//     VGA (Vista Genuine Advantage) error code range
'////////////////////////////////////////////////////////////////
'//
'// MessageId: SL_E_VGA_NON_GENUINE_STATUS_FIRST
'//
'// MessageText:
'//
'// The Vista Genuine Advantage Service determined that the installation is not genuine.
'//
%SL_E_VGA_NON_GENUINE_STATUS_FIRST = &HC004C401&

'//
'// MessageId: SL_E_VGA_NON_GENUINE_STATUS_LAST
'//
'// MessageText:
'//
'// The Vista Genuine Advantage Service determined that the installation is not genuine.
'//
%SL_E_VGA_NON_GENUINE_STATUS_LAST = &HC004C600&

'////////////////////////////////////////////////////////////////
'//     Clearing house errors
'//     These error codes come from MSCH Reference Implementation
'////////////////////////////////////////////////////////////////

'//
'// MessageId: SL_E_CHREF_INVALID_PRODUCT_KEY
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_INVALID_PRODUCT_KEY   = &HC004C801&

'//
'// MessageId: SL_E_CHREF_EXCLUDED_PRODUCT_KEY
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_EXCLUDED_PRODUCT_KEY  = &HC004C802&

'//
'// MessageId: SL_E_CHREF_PRODUCT_KEY_REVOKED
'//
'// MessageText:
'//
'// The activation server determined the specified product key has been revoked.
'//
%SL_E_CHREF_PRODUCT_KEY_REVOKED   = &HC004C803&

'//
'// MessageId: SL_E_CHREF_INVALID_PRODUCT_KEY_ALGORITHM
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_INVALID_PRODUCT_KEY_ALGORITHM = &HC004C804&

'//
'// MessageId: SL_E_CHREF_INVALID_PRODUCT_KEY_UNIQUEID
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_INVALID_PRODUCT_KEY_UNIQUEID = &HC004C805&

'//
'// MessageId: SL_E_CHREF_INVALID_PRODUCT_DATA
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_INVALID_PRODUCT_DATA  = &HC004C810&

'//
'// MessageId: SL_E_CHREF_CANNOT_CREATE_BINDING_ASSOC
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHREF_CANNOT_CREATE_BINDING_ASSOC = &HC004C811&

'//
'// MessageId: SL_E_CHREF_BINDING_OUT_OF_TOLERANCE
'//
'// MessageText:
'//
'// The activation server determined that the specified product key has exceeded its activation count.
'//
%SL_E_CHREF_BINDING_OUT_OF_TOLERANCE = &HC004C812&

'//
'// MessageId: SL_E_CHREF_PRODUCT_KEY_POLICY_MISSING
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHREF_PRODUCT_KEY_POLICY_MISSING = &HC004C813&

'//
'// MessageId: SL_E_CHREF_PRODUCT_KEY_POLICY_OVERLAPPED
'//
'// MessageText:
'//
'// The activation server determined the specified product key is invalid.
'//
%SL_E_CHREF_PRODUCT_KEY_POLICY_OVERLAPPED = &HC004C814&

'//
'// MessageId: SL_E_CHREF_PRODUCT_KEY_BINDING_MISMATCH
'//
'// MessageText:
'//
'// The activation server determined the license is invalid.
'//
%SL_E_CHREF_PRODUCT_KEY_BINDING_MISMATCH = &HC004C815&

'//
'// MessageId: SL_E_CHREF_OEM_SLP_COA0
'//
'// MessageText:
'//
'// The activation server reported that the specified product key cannot be used for online activation.
'//
%SL_E_CHREF_OEM_SLP_COA0          = &HC004C816&

'//////////////////////////////////////////////////////////
'// SL service internal error
'//     Internal program errors for SL develpers
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_E_INVALID_CONTEXT
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the specified context is invalid.
'//
%SL_E_INVALID_CONTEXT             = &HC004E001&

'//
'// MessageId: SL_E_TOKEN_STORE_INVALID_STATE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store contains inconsistent data.
'//
%SL_E_TOKEN_STORE_INVALID_STATE   = &HC004E002&

'//
'// MessageId: SL_E_EVALUATION_FAILED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that license evaluation failed.
'//
%SL_E_EVALUATION_FAILED           = &HC004E003&

'//
'// MessageId: SL_E_NOT_EVALUATED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license has not been evaluated.
'//
%SL_E_NOT_EVALUATED               = &HC004E004&

'//
'// MessageId: SL_E_NOT_ACTIVATED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is not activated.
'//
%SL_E_NOT_ACTIVATED               = &HC004E005&

'//
'// MessageId: SL_E_INVALID_GUID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license contains invalid data.
'//
%SL_E_INVALID_GUID                = &HC004E006&

'//
'// MessageId: SL_E_TOKSTO_TOKEN_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store does not contain the requested license.
'//
%SL_E_TOKSTO_TOKEN_NOT_FOUND      = &HC004E007&

'//
'// MessageId: SL_E_TOKSTO_NO_PROPERTIES
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license property is invalid.
'//
%SL_E_TOKSTO_NO_PROPERTIES        = &HC004E008&

'//
'// MessageId: SL_E_TOKSTO_NOT_INITIALIZED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store is not initialized.
'//
%SL_E_TOKSTO_NOT_INITIALIZED      = &HC004E009&

'//
'// MessageId: SL_E_TOKSTO_ALREADY_INITIALIZED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store is already initialized.
'//
%SL_E_TOKSTO_ALREADY_INITIALIZED  = &HC004E00A&

'//
'// MessageId: SL_E_TOKSTO_NO_ID_SET
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license property is invalid.
'//
%SL_E_TOKSTO_NO_ID_SET            = &HC004E00B&

'//
'// MessageId: SL_E_TOKSTO_CANT_CREATE_FILE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license could not be opened or created.
'//
%SL_E_TOKSTO_CANT_CREATE_FILE     = &HC004E00C&

'//
'// MessageId: SL_E_TOKSTO_CANT_WRITE_TO_FILE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license could not be written.
'//
%SL_E_TOKSTO_CANT_WRITE_TO_FILE   = &HC004E00D&

'//
'// MessageId: SL_E_TOKSTO_CANT_READ_FILE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store could not read the license file.
'//
%SL_E_TOKSTO_CANT_READ_FILE       = &HC004E00E&

'//
'// MessageId: SL_E_TOKSTO_CANT_PARSE_PROPERTIES
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license property is corrupted.
'//
%SL_E_TOKSTO_CANT_PARSE_PROPERTIES = &HC004E00F&

'//
'// MessageId: SL_E_TOKSTO_PROPERTY_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license property is missing.
'//
%SL_E_TOKSTO_PROPERTY_NOT_FOUND   = &HC004E010&

'//
'// MessageId: SL_E_TOKSTO_INVALID_FILE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store contains an invalid license file.
'//
%SL_E_TOKSTO_INVALID_FILE         = &HC004E011&

'//
'// MessageId: SL_E_TOKSTO_CANT_CREATE_MUTEX
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store failed to start synchronization properly.
'//
%SL_E_TOKSTO_CANT_CREATE_MUTEX    = &HC004E012&

'//
'// MessageId: SL_E_TOKSTO_CANT_ACQUIRE_MUTEX
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license store failed to synchronize properly.
'//
%SL_E_TOKSTO_CANT_ACQUIRE_MUTEX   = &HC004E013&

'//
'// MessageId: SL_E_TOKSTO_NO_TOKEN_DATA
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license property is invalid.
'//
%SL_E_TOKSTO_NO_TOKEN_DATA        = &HC004E014&

'//
'// MessageId: SL_E_EUL_CONSUMPTION_FAILED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that license consumption failed.
'//
%SL_E_EUL_CONSUMPTION_FAILED      = &HC004E015&

'//
'// MessageId: SL_E_PKEY_INVALID_CONFIG
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is invalid.
'//
%SL_E_PKEY_INVALID_CONFIG         = &HC004E016&

'//
'// MessageId: SL_E_PKEY_INVALID_UNIQUEID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is invalid.
'//
%SL_E_PKEY_INVALID_UNIQUEID       = &HC004E017&

'//
'// MessageId: SL_E_PKEY_INVALID_ALGORITHM
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is invalid.
'//
%SL_E_PKEY_INVALID_ALGORITHM      = &HC004E018&

'//
'// MessageId: SL_E_PKEY_INTERNAL_ERROR
'//
'// MessageText:
'//
'// The Software Licensing Service determined that validation of the specified product key failed.
'//
%SL_E_PKEY_INTERNAL_ERROR         = &HC004E019&

'//
'// MessageId: SL_E_LICENSE_INVALID_ADDON_INFO
'//
'// MessageText:
'//
'// The Software Licensing Service reported that invalid add-on information was found.
'//
%SL_E_LICENSE_INVALID_ADDON_INFO  = &HC004E01A&

'//
'// MessageId: SL_E_HWID_ERROR
'//
'// MessageText:
'//
'// The Software Licensing Service reported that not all hardware information could be collected.
'//
%SL_E_HWID_ERROR                  = &HC004E01B&

'//
'// MessageId: SL_E_PKEY_INVALID_KEYCHANGE1
'//
'// MessageText:
'//
'// This evaluation product key is no longer valid.
'//
%SL_E_PKEY_INVALID_KEYCHANGE1     = &HC004E01C&

'//
'// MessageId: SL_E_PKEY_INVALID_KEYCHANGE2
'//
'// MessageText:
'//
'// The new product key cannot be used on this installation of Windows. Type a different product key. (CD-AB)
'//
%SL_E_PKEY_INVALID_KEYCHANGE2     = &HC004E01D&

'//
'// MessageId: SL_E_PKEY_INVALID_KEYCHANGE3
'//
'// MessageText:
'//
'// The new product key cannot be used on this installation of Windows. Type a different product key. (AB-AB)
'//
%SL_E_PKEY_INVALID_KEYCHANGE3     = &HC004E01E&

'//
'// MessageId: SL_E_PKEY_INVALID_KEYCHANGE4
'//
'// MessageText:
'//
'// The new product key cannot be used on this installation of Windows. Type a different product key. (AB-CD)
'//
%SL_E_PKEY_INVALID_KEYCHANGE4     = &HC004E01F&

'//
'// MessageId: SL_E_POLICY_OTHERINFO_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that there is a mismatched between a policy value and information stored in the OtherInfo section.
'//
%SL_E_POLICY_OTHERINFO_MISMATCH   = &HC004E020&

'//
'// MessageId: SL_E_PRODUCT_UNIQUENESS_GROUP_ID_INVALID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Genuine information contained in the license is not consistent.
'//
%SL_E_PRODUCT_UNIQUENESS_GROUP_ID_INVALID = &HC004E021&

'//
'// MessageId: SL_E_SECURE_STORE_ID_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the secure store id value in license does not match with the current value.
'//
%SL_E_SECURE_STORE_ID_MISMATCH    = &HC004E022&

'////////////////////////////////////////////////////////////////
'//     Internal Token Store errors
'//     0xE1xx is reserved for Token Store internal errors
'////////////////////////////////////////////////////////////////

'//
'// MessageId: SL_E_SFS_INVALID_FS_VERSION
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store file version is invalid.
'//
%SL_E_SFS_INVALID_FS_VERSION      = &H8004E101&

'//
'// MessageId: SL_E_SFS_INVALID_FD_TABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store contains an invalid descriptor table.
'//
%SL_E_SFS_INVALID_FD_TABLE        = &H8004E102&

'//
'// MessageId: SL_E_SFS_INVALID_SYNC
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store contains a token with an invalid header/footer.
'//
%SL_E_SFS_INVALID_SYNC            = &H8004E103&

'//
'// MessageId: SL_E_SFS_BAD_TOKEN_NAME
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a Token Store token has an invalid name.
'//
%SL_E_SFS_BAD_TOKEN_NAME          = &H8004E104&

'//
'// MessageId: SL_E_SFS_BAD_TOKEN_EXT
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a Token Store token has an invalid extension.
'//
%SL_E_SFS_BAD_TOKEN_EXT           = &H8004E105&

'//
'// MessageId: SL_E_SFS_DUPLICATE_TOKEN_NAME
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store contains a duplicate token.
'//
%SL_E_SFS_DUPLICATE_TOKEN_NAME    = &H8004E106&

'//
'// MessageId: SL_E_SFS_TOKEN_SIZE_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a token in the Token Store has a size mismatch.
'//
%SL_E_SFS_TOKEN_SIZE_MISMATCH     = &H8004E107&

'//
'// MessageId: SL_E_SFS_INVALID_TOKEN_DATA_HASH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a token in the Token Store contains an invalid hash.
'//
%SL_E_SFS_INVALID_TOKEN_DATA_HASH = &H8004E108&

'//
'// MessageId: SL_E_SFS_FILE_READ_ERROR
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store was unable to read a token.
'//
%SL_E_SFS_FILE_READ_ERROR         = &H8004E109&

'//
'// MessageId: SL_E_SFS_FILE_WRITE_ERROR
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store was unable to write a token.
'//
%SL_E_SFS_FILE_WRITE_ERROR        = &H8004E10A&

'//
'// MessageId: SL_E_SFS_INVALID_FILE_POSITION
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store attempted an invalid file operation.
'//
%SL_E_SFS_INVALID_FILE_POSITION   = &H8004E10B&

'//
'// MessageId: SL_E_SFS_NO_ACTIVE_TRANSACTION
'//
'// MessageText:
'//
'// The Software Licensing Service reported that there is no active transaction.
'//
%SL_E_SFS_NO_ACTIVE_TRANSACTION   = &H8004E10C&

'//
'// MessageId: SL_E_SFS_INVALID_FS_HEADER
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the Token Store file header is invalid.
'//
%SL_E_SFS_INVALID_FS_HEADER       = &H8004E10D&

'//
'// MessageId: SL_E_SFS_INVALID_TOKEN_DESCRIPTOR
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a Token Store token descriptor is invalid.
'//
%SL_E_SFS_INVALID_TOKEN_DESCRIPTOR = &H8004E10E&


'//////////////////////////////////////////////////////////
'// Extended SL Client API error, license evaluation errors
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_E_INTERNAL_ERROR
'//
'// MessageText:
'//
'// The Software Licensing Service reported an internal error.
'//
%SL_E_INTERNAL_ERROR              = &HC004F001&

'//
'// MessageId: SL_E_RIGHT_NOT_CONSUMED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that rights consumption failed.
'//
%SL_E_RIGHT_NOT_CONSUMED          = &HC004F002&

'//
'// MessageId: SL_E_USE_LICENSE_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the required license could not be found.
'//
%SL_E_USE_LICENSE_NOT_INSTALLED   = &HC004F003&

'//
'// MessageId: SL_E_MISMATCHED_PKEY_RANGE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key does not match the range defined in the license.
'//
%SL_E_MISMATCHED_PKEY_RANGE       = &HC004F004&

'//
'// MessageId: SL_E_MISMATCHED_PID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key does not match the product key for the license.
'//
%SL_E_MISMATCHED_PID              = &HC004F005&

'//
'// MessageId: SL_E_EXTERNAL_SIGNATURE_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the signature file for the license is not available.
'//
%SL_E_EXTERNAL_SIGNATURE_NOT_FOUND = &HC004F006&

'//
'// MessageId: SL_E_RAC_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license could not be found.
'//
%SL_E_RAC_NOT_AVAILABLE           = &HC004F007&

'//
'// MessageId: SL_E_SPC_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license could not be found.
'//
%SL_E_SPC_NOT_AVAILABLE           = &HC004F008&

'//
'// MessageId: SL_E_GRACE_TIME_EXPIRED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the grace period expired.
'//
%SL_E_GRACE_TIME_EXPIRED          = &HC004F009&

'//
'// MessageId: SL_E_MISMATCHED_APPID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application ID does not match the application ID for the license.
'//
%SL_E_MISMATCHED_APPID            = &HC004F00A&

'//
'// MessageId: SL_E_NO_PID_CONFIG_DATA
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product identification data is not available.
'//
%SL_E_NO_PID_CONFIG_DATA          = &HC004F00B&

'//
'// MessageId: SL_I_OOB_GRACE_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the valid grace period.
'//
%SL_I_OOB_GRACE_PERIOD            = &H4004F00C&

'//
'// MessageId: SL_I_OOT_GRACE_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the valid out of tolerance grace period.
'//
%SL_I_OOT_GRACE_PERIOD            = &H4004F00D&

'//
'// MessageId: SL_E_MISMATCHED_SECURITY_PROCESSOR
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the license could not be used by the current version of the security processor component.
'//
%SL_E_MISMATCHED_SECURITY_PROCESSOR = &HC004F00E&

'//
'// MessageId: SL_E_OUT_OF_TOLERANCE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the hardware ID binding is beyond the level of tolerance.
'//
%SL_E_OUT_OF_TOLERANCE            = &HC004F00F&

'//
'// MessageId: SL_E_INVALID_PKEY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is invalid.
'//
%SL_E_INVALID_PKEY                = &HC004F010&

'//
'// MessageId: SL_E_LICENSE_FILE_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license file is not installed.
'//
%SL_E_LICENSE_FILE_NOT_INSTALLED  = &HC004F011&

'//
'// MessageId: SL_E_VALUE_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the call has failed because the value for the input key was not found.
'//
%SL_E_VALUE_NOT_FOUND             = &HC004F012&

'//
'// MessageId: SL_E_RIGHT_NOT_GRANTED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that there is no permission to run the software.
'//
%SL_E_RIGHT_NOT_GRANTED           = &HC004F013&

'//
'// MessageId: SL_E_PKEY_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is not available.
'//
%SL_E_PKEY_NOT_INSTALLED          = &HC004F014&

'//
'// MessageId: SL_E_PRODUCT_SKU_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is not installed.
'//
%SL_E_PRODUCT_SKU_NOT_INSTALLED   = &HC004F015&

'//
'// MessageId: SL_E_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the request is not supported.
'//
%SL_E_NOT_SUPPORTED               = &HC004F016&

'//
'// MessageId: SL_E_PUBLISHING_LICENSE_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is not installed.
'//
%SL_E_PUBLISHING_LICENSE_NOT_INSTALLED = &HC004F017&

'//
'// MessageId: SL_E_LICENSE_SERVER_URL_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license does not contain valid location data for the activation server.
'//
%SL_E_LICENSE_SERVER_URL_NOT_FOUND = &HC004F018&

'//
'// MessageId: SL_E_INVALID_EVENT_ID
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the requested event ID is invalid.
'//
%SL_E_INVALID_EVENT_ID            = &HC004F019&

'//
'// MessageId: SL_E_EVENT_NOT_REGISTERED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the requested event is not registered with the service.
'//
%SL_E_EVENT_NOT_REGISTERED        = &HC004F01A&

'//
'// MessageId: SL_E_EVENT_ALREADY_REGISTERED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the event ID is already registered.
'//
%SL_E_EVENT_ALREADY_REGISTERED    = &HC004F01B&

'//
'// MessageId: SL_E_DECRYPTION_LICENSES_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is not installed.
'//
%SL_E_DECRYPTION_LICENSES_NOT_AVAILABLE = &HC004F01C&

'//
'// MessageId: SL_E_LICENSE_SIGNATURE_VERIFICATION_FAILED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the verification of the license failed.
'//
%SL_E_LICENSE_SIGNATURE_VERIFICATION_FAILED = &HC004F01D&

'//
'// MessageId: SL_E_DATATYPE_MISMATCHED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the input data type does not match the data type in the license.
'//
%SL_E_DATATYPE_MISMATCHED         = &HC004F01E&

'//
'// MessageId: SL_E_INVALID_LICENSE
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the license is invalid.
'//
%SL_E_INVALID_LICENSE             = &HC004F01F&

'//
'// MessageId: SL_E_INVALID_PACKAGE
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the license package is invalid.
'//
%SL_E_INVALID_PACKAGE             = &HC004F020&

'//
'// MessageId: SL_E_VALIDITY_TIME_EXPIRED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the validity period of the license has expired.
'//
%SL_E_VALIDITY_TIME_EXPIRED       = &HC004F021&

'//
'// MessageId: SL_E_LICENSE_AUTHORIZATION_FAILED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license authorization failed.
'//
%SL_E_LICENSE_AUTHORIZATION_FAILED = &HC004F022&

'//
'// MessageId: SL_E_LICENSE_DECRYPTION_FAILED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is invalid.
'//
%SL_E_LICENSE_DECRYPTION_FAILED   = &HC004F023&

'//
'// MessageId: SL_E_WINDOWS_INVALID_LICENSE_STATE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is invalid.
'//
%SL_E_WINDOWS_INVALID_LICENSE_STATE = &HC004F024&

'//
'// MessageId: SL_E_LUA_ACCESSDENIED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the action requires administrator privilege.
'//
%SL_E_LUA_ACCESSDENIED            = &HC004F025&

'//
'// MessageId: SL_E_PROXY_KEY_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the required data is not found.
'//
%SL_E_PROXY_KEY_NOT_FOUND         = &HC004F026&

'//
'// MessageId: SL_E_TAMPER_DETECTED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is tampered.
'//
%SL_E_TAMPER_DETECTED             = &HC004F027&

'//
'// MessageId: SL_E_POLICY_CACHE_INVALID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the policy cache is invalid.
'//
%SL_E_POLICY_CACHE_INVALID        = &HC004F028&

'//
'// MessageId: SL_E_INVALID_RUNNING_MODE
'//
'// MessageText:
'//
'// The Software Licensing Service cannot be started in the current OS mode.
'//
%SL_E_INVALID_RUNNING_MODE        = &HC004F029&

'//
'// MessageId: SL_E_SLP_NOT_SIGNED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license is invalid.
'//
%SL_E_SLP_NOT_SIGNED              = &HC004F02A&

'//
'// MessageId: SL_I_LICENSE_FILE_NOT_DELETED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the license could not be deleted.
'//
' // *** Removed in the Windows 7 SDK ***
'%SL_I_LICENSE_FILE_NOT_DELETED    = &H4004F02B&

'//
'// MessageId: SL_E_CIDIID_INVALID_DATA
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the format for the offline activation data is incorrect.
'//
%SL_E_CIDIID_INVALID_DATA         = &HC004F02C&

'//
'// MessageId: SL_E_CIDIID_INVALID_VERSION
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the version of the offline Confirmation ID (CID) is incorrect.
'//
%SL_E_CIDIID_INVALID_VERSION      = &HC004F02D&

'//
'// MessageId: SL_E_CIDIID_VERSION_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the version of the offline Confirmation ID (CID) is not supported.
'//
%SL_E_CIDIID_VERSION_NOT_SUPPORTED = &HC004F02E&

'//
'// MessageId: SL_E_CIDIID_INVALID_DATA_LENGTH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the length of the offline Confirmation ID (CID) is incorrect.
'//
%SL_E_CIDIID_INVALID_DATA_LENGTH  = &HC004F02F&

'//
'// MessageId: SL_E_CIDIID_NOT_DEPOSITED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the Installation ID (IID) or the Confirmation ID (CID) could not been saved.
'//
%SL_E_CIDIID_NOT_DEPOSITED        = &HC004F030&

'//
'// MessageId: SL_E_CIDIID_MISMATCHED
'//
'// MessageText:
'//
'// The Installation ID (IID) and the Confirmation ID (CID) do not match. Please confirm the IID and reacquire a new CID if necessary.
'//
%SL_E_CIDIID_MISMATCHED           = &HC004F031&

'//
'// MessageId: SL_E_INVALID_BINDING_BLOB
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the binding data is invalid.
'//
%SL_E_INVALID_BINDING_BLOB        = &HC004F032&

'//
'// MessageId: SL_E_PRODUCT_KEY_INSTALLATION_NOT_ALLOWED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is not allowed to be installed. Please see the eventlog for details.
'//
%SL_E_PRODUCT_KEY_INSTALLATION_NOT_ALLOWED = &HC004F033&

'//
'// MessageId: SL_E_EUL_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license could not be found or was invalid.
'//
%SL_E_EUL_NOT_AVAILABLE           = &HC004F034&

'//
'// MessageId: SL_E_VL_NOT_WINDOWS_SLP
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated with a Volume license product key. Volume-licensed systems
'// require upgrading from a qualifying operating system. Please contact your system administrator or use a different type of key.
'//
%SL_E_VL_NOT_WINDOWS_SLP          = &HC004F035&

'//
'// MessageId: SL_E_VL_NOT_ENOUGH_COUNT
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The count reported by your Key Management Service (KMS) is insufficient. Please contact your system administrator.
'//
%SL_E_VL_NOT_ENOUGH_COUNT         = &HC004F038&

'//
'// MessageId: SL_E_VL_BINDING_SERVICE_NOT_ENABLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated.  The Key Management Service (KMS) is not enabled.
'//
%SL_E_VL_BINDING_SERVICE_NOT_ENABLED = &HC004F039&

'//
'// MessageId: SL_E_VL_INFO_PRODUCT_USER_RIGHT
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer was activated but the owner should verify the Product Use Rights.
'//
%SL_E_VL_INFO_PRODUCT_USER_RIGHT  = &H4004F040&

'//
'// MessageId: SL_E_VL_KEY_MANAGEMENT_SERVICE_NOT_ACTIVATED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the Key Management Service (KMS) is not activated. KMS needs to be activated. Please contact system administrator.
'//
%SL_E_VL_KEY_MANAGEMENT_SERVICE_NOT_ACTIVATED = &HC004F041&

'//
'// MessageId: SL_E_VL_KEY_MANAGEMENT_SERVICE_ID_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the specified Key Management Service (KMS) cannot be used.
'//
%SL_E_VL_KEY_MANAGEMENT_SERVICE_ID_MISMATCH = &HC004F042&

'//
'// MessageId: SL_E_PROXY_POLICY_NOT_UPDATED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the proxy policy has not been updated.
'//
%SL_E_PROXY_POLICY_NOT_UPDATED    = &HC004F047&

'//
'// MessageId: SL_E_CIDIID_INVALID_CHECK_DIGITS
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the Installation ID (IID) or the Confirmation ID (CID) is invalid.
'//
%SL_E_CIDIID_INVALID_CHECK_DIGITS = &HC004F04D&

'//
'// MessageId: SL_E_LICENSE_MANAGEMENT_DATA_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that license management information was not found in the licenses.
'//
%SL_E_LICENSE_MANAGEMENT_DATA_NOT_FOUND = &HC004F04F&

'//
'// MessageId: SL_E_INVALID_PRODUCT_KEY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is invalid.
'//
%SL_E_INVALID_PRODUCT_KEY         = &HC004F050&

'//
'// MessageId: SL_E_BLOCKED_PRODUCT_KEY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product key is blocked.
'//
%SL_E_BLOCKED_PRODUCT_KEY         = &HC004F051&

'//
'// MessageId: SL_E_DUPLICATE_POLICY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the licenses contain duplicated properties.
'//
%SL_E_DUPLICATE_POLICY            = &HC004F052&

'//
'// MessageId: SL_E_MISSING_OVERRIDE_ONLY_ATTRIBUTE
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the license is invalid. The license contains an override policy that is not configured properly.
'//
%SL_E_MISSING_OVERRIDE_ONLY_ATTRIBUTE = &HC004F053&

'//
'// MessageId: SL_E_LICENSE_MANAGEMENT_DATA_DUPLICATED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that license management information has duplicated data.
'//
%SL_E_LICENSE_MANAGEMENT_DATA_DUPLICATED = &HC004F054&

'//
'// MessageId: SL_E_BASE_SKU_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the base SKU is not available.
'//
%SL_E_BASE_SKU_NOT_AVAILABLE      = &HC004F055&

'//
'// MessageId: SL_E_VL_MACHINE_NOT_BOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated using the Key Management Service (KMS).
'//
%SL_E_VL_MACHINE_NOT_BOUND        = &HC004F056&

'//
'// MessageId: SL_E_SLP_MISSING_ACPI_SLIC
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer BIOS is missing a required license.
'//
%SL_E_SLP_MISSING_ACPI_SLIC       = &HC004F057&

'//
'// MessageId: SL_E_SLP_MISSING_SLP_MARKER
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer BIOS is missing a required license.
'//
%SL_E_SLP_MISSING_SLP_MARKER      = &HC004F058&

'//
'// MessageId: SL_E_SLP_BAD_FORMAT
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a license in the computer BIOS is invalid.
'//
%SL_E_SLP_BAD_FORMAT              = &HC004F059&

'//
'// MessageId: SL_E_INVALID_PACKAGE_VERSION
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the version of the license package is invalid.
'//
%SL_E_INVALID_PACKAGE_VERSION     = &HC004F060&

'//
'// MessageId: SL_E_PKEY_INVALID_UPGRADE
'//
'// MessageText:
'//
'// The Software Licensing Service determined that this specified product key can only be used for upgrading, not for clean installations.
'//
%SL_E_PKEY_INVALID_UPGRADE        = &HC004F061&

'//
'// MessageId: SL_E_ISSUANCE_LICENSE_NOT_INSTALLED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that a required license could not be found.
'//
%SL_E_ISSUANCE_LICENSE_NOT_INSTALLED = &HC004F062&

'//
'// MessageId: SL_E_SLP_OEM_CERT_MISSING
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer BIOS is missing a required license.
'//
%SL_E_SLP_OEM_CERT_MISSING        = &HC004F063&

'//
'// MessageId: SL_E_NONGENUINE_GRACE_TIME_EXPIRED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the non-genuine grace period expired.
'//
%SL_E_NONGENUINE_GRACE_TIME_EXPIRED = &HC004F064&

'//
'// MessageId: SL_I_NONGENUINE_GRACE_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the valid non-genuine grace period.
'//
%SL_I_NONGENUINE_GRACE_PERIOD     = &H4004F065&

'//
'// MessageId: SL_E_DEPENDENT_PROPERTY_NOT_SET
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the genuine information property can not be set before dependent property been set.
'//
%SL_E_DEPENDENT_PROPERTY_NOT_SET  = &HC004F066&

'//
'// MessageId: SL_E_NONGENUINE_GRACE_TIME_EXPIRED_2
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the non-genuine grace period expired (type 2).
'//
%SL_E_NONGENUINE_GRACE_TIME_EXPIRED_2 = &HC004F067&

'//
'// MessageId: SL_I_NONGENUINE_GRACE_PERIOD_2
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the valid non-genuine grace period (type 2).
'//
%SL_I_NONGENUINE_GRACE_PERIOD_2   = &H4004F068&

'//
'// MessageId: SL_E_MISMATCHED_PRODUCT_SKU
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the product SKU is not found.
'//
%SL_E_MISMATCHED_PRODUCT_SKU      = &HC004F069&

'//
'// MessageId: SL_E_OPERATION_NOT_ALLOWED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the requested operation is not allowed.
'//
%SL_E_OPERATION_NOT_ALLOWED       = &HC004F06A&

'//
'// MessageId: SL_E_VL_KEY_MANAGEMENT_SERVICE_VM_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The Software Licensing Service determined that it is running in a virtual machine. The Key Management Service (KMS) is not supported in this mode.
'//
%SL_E_VL_KEY_MANAGEMENT_SERVICE_VM_NOT_SUPPORTED = &HC004F06B&

'//
'// MessageId: SL_E_VL_INVALID_TIMESTAMP
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The Key Management Service (KMS) determined that the request timestamp is invalid.
'//
%SL_E_VL_INVALID_TIMESTAMP        = &HC004F06C&

'//
'// MessageId: SL_E_PLUGIN_INVALID_MANIFEST
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the plug-in manifest file is incorrect.
'//
%SL_E_PLUGIN_INVALID_MANIFEST     = &HC004F071&

'//
'// MessageId: SL_E_APPLICATION_POLICIES_MISSING
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license policies for fast query could not be found.
'//
%SL_E_APPLICATION_POLICIES_MISSING = &HC004F072&

'//
'// MessageId: SL_E_APPLICATION_POLICIES_NOT_LOADED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the license policies for fast query have not been loaded.
'//
%SL_E_APPLICATION_POLICIES_NOT_LOADED = &HC004F073&

'//
'// MessageId: SL_E_VL_BINDING_SERVICE_UNAVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. No Key Management Service (KMS) could be contacted. Please see the Application Event Log for additional information.
'//
%SL_E_VL_BINDING_SERVICE_UNAVAILABLE = &HC004F074&

'//
'// MessageId: SL_E_SERVICE_STOPPING
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the operation cannot be completed because the service is stopping.
'//
%SL_E_SERVICE_STOPPING            = &HC004F075&

'//
'// MessageId: SL_E_PLUGIN_NOT_REGISTERED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the requested plug-in cannot be found.
'//
%SL_E_PLUGIN_NOT_REGISTERED       = &HC004F076&

'//
'// MessageId: SL_E_AUTHN_WRONG_VERSION
'//
'// MessageText:
'//
'// The Software Licensing Service determined incompatible version of authentication data.
'//
%SL_E_AUTHN_WRONG_VERSION         = &HC004F077&

'//
'// MessageId: SL_E_AUTHN_MISMATCHED_KEY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the key is mismatched.
'//
%SL_E_AUTHN_MISMATCHED_KEY        = &HC004F078&

'//
'// MessageId: SL_E_AUTHN_CHALLENGE_NOT_SET
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the authentication data is not set.
'//
%SL_E_AUTHN_CHALLENGE_NOT_SET     = &HC004F079&

'//
'// MessageId: SL_E_AUTHN_CANT_VERIFY
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the verification could not be done.
'//
%SL_E_AUTHN_CANT_VERIFY           = &HC004F07A&

'//
'// MessageId: SL_E_SERVICE_RUNNING
'//
'// MessageText:
'//
'// The requested operation is unavailable while the Software Licensing Service is running.
'//
%SL_E_SERVICE_RUNNING             = &HC004F07B&

'//
'// MessageId: SL_E_SLP_INVALID_MARKER_VERSION
'//
'// MessageText:
'//
'// The Software Licensing Service determined that the version of the computer BIOS is invalid.
'//
%SL_E_SLP_INVALID_MARKER_VERSION  = &HC004F07C&

'//
'// MessageId: SL_E_NOT_GENUINE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that current state is not genuine.
'//
%SL_E_NOT_GENUINE                 = &HC004F200&

'//
'// 0xF300 - 0xF3FF reserved for token-based activation
'//
'//
'// MessageId: SL_E_TKA_CHALLENGE_EXPIRED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The token-based activation challenge has expired.
'//
%SL_E_TKA_CHALLENGE_EXPIRED       = &HC004F301&

'//
'// MessageId: SL_E_TKA_SILENT_ACTIVATION_FAILURE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that Silent Activation failed. The Software Licensing Service reported that there are no certificates found in the system that could activate the product without user interaction.
'//
%SL_E_TKA_SILENT_ACTIVATION_FAILURE = &HC004F302&

'//
'// MessageId: SL_E_TKA_INVALID_CERT_CHAIN
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the certificate chain could not be built or failed validation.
'//
%SL_E_TKA_INVALID_CERT_CHAIN      = &HC004F303&

'//
'// MessageId: SL_E_TKA_GRANT_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that required license could not be found.
'//
%SL_E_TKA_GRANT_NOT_FOUND         = &HC004F304&

'//
'// MessageId: SL_E_TKA_CERT_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that there are no certificates found in the system that could activate the product.
'//
%SL_E_TKA_CERT_NOT_FOUND          = &HC004F305&

'//
'// MessageId: SL_E_TKA_INVALID_SKU_ID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that this software edition does not support token-based activation.
'//
%SL_E_TKA_INVALID_SKU_ID          = &HC004F306&

'//
'// MessageId: SL_E_TKA_INVALID_BLOB
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. Activation data is invalid.
'//
%SL_E_TKA_INVALID_BLOB            = &HC004F307&

'//
'// MessageId: SL_E_TKA_TAMPERED_CERT_CHAIN
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. Activation data is tampered.
'//
%SL_E_TKA_TAMPERED_CERT_CHAIN     = &HC004F308&

'//
'// MessageId: SL_E_TKA_CHALLENGE_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. Activation challenge and response do not match.
'//
%SL_E_TKA_CHALLENGE_MISMATCH      = &HC004F309&

'//
'// MessageId: SL_E_TKA_INVALID_CERTIFICATE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The certificate does not match the conditions in the license.
'//
%SL_E_TKA_INVALID_CERTIFICATE     = &HC004F30A&

'//
'// MessageId: SL_E_TKA_INVALID_SMARTCARD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the inserted smartcard could not be used to activate the product.
'//
%SL_E_TKA_INVALID_SMARTCARD       = &HC004F30B&

'//
'// MessageId: SL_E_TKA_FAILED_GRANT_PARSING
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the token-based activation license content is invalid.
'//
%SL_E_TKA_FAILED_GRANT_PARSING    = &HC004F30C&

'//
'// MessageId: SL_E_TKA_INVALID_THUMBPRINT
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The thumbprint is invalid.
'//
%SL_E_TKA_INVALID_THUMBPRINT      = &HC004F30D&

'//
'// MessageId: SL_E_TKA_THUMBPRINT_CERT_NOT_FOUND
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The thumbprint does not match any certificate.
'//
%SL_E_TKA_THUMBPRINT_CERT_NOT_FOUND = &HC004F30E&

'//
'// MessageId: SL_E_TKA_CRITERIA_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The certificate does not match the criteria specified in the issuance license.
'//
%SL_E_TKA_CRITERIA_MISMATCH       = &HC004F30F&

'//
'// MessageId: SL_E_TKA_TPID_MISMATCH
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The certificate does not match the trust point identifier (TPID) specified in the issuance license.
'//
%SL_E_TKA_TPID_MISMATCH           = &HC004F310&

'//
'// MessageId: SL_E_TKA_SOFT_CERT_DISALLOWED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. A soft token cannot be used for activation.
'//
%SL_E_TKA_SOFT_CERT_DISALLOWED    = &HC004F311&

'//
'// MessageId: SL_E_TKA_SOFT_CERT_INVALID
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the computer could not be activated. The certificate cannot be used because its private key is exportable.
'//
%SL_E_TKA_SOFT_CERT_INVALID       = &HC004F312&

'//
'// MessageId: SL_E_TKA_CERT_CNG_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the CNG encryption library could not be loaded.  The current certificate may not be available on this version of Windows.
'//
%SL_E_TKA_CERT_CNG_NOT_AVAILABLE  = &HC004F313&

'//
'// MessageId: E_RM_UNKNOWN_ERROR
'//
'// MessageText:
'//
'// A networking problem has occurred while activating your copy of Windows.
'//
%E_RM_UNKNOWN_ERROR               = &HC004FC03&

'//
'// MessageId: SL_I_TIMEBASED_VALIDITY_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the timebased validity period.
'//
%SL_I_TIMEBASED_VALIDITY_PERIOD   = &H4004FC04&

'//
'// MessageId: SL_I_PERPETUAL_OOB_GRACE_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application has a perpetual grace period.
'//
%SL_I_PERPETUAL_OOB_GRACE_PERIOD  = &H4004FC05&

'//
'// MessageId: SL_I_TIMEBASED_EXTENDED_GRACE_PERIOD
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the application is running within the valid extended grace period.
'//
%SL_I_TIMEBASED_EXTENDED_GRACE_PERIOD = &H4004FC06&

'//
'// MessageId: SL_E_VALIDITY_PERIOD_EXPIRED
'//
'// MessageText:
'//
'// The Software Licensing Service reported that the validity period expired.
'//
%SL_E_VALIDITY_PERIOD_EXPIRED     = &HC004FC07&

'//
'// MessageId: SL_E_TAMPER_RECOVERY_REQUIRES_ACTIVATION
'//
'// MessageText:
'//
'// The Software Licensing Service reported that activation is required to recover from tampering of SL Service trusted store.
'//
%SL_E_TAMPER_RECOVERY_REQUIRES_ACTIVATION = &HC004FE00&

'// ******************
'// ******************
'//
'// The following errors are mappings to the SPAPI error strings for UX messaging
'//
'// ******************
'// ******************

'//////////////////////////////////////////////////////////
'//SP_PUB_GENERAL_ZONE
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_REMAPPING_SP_PUB_GENERAL_NOT_INITIALIZED
'//
'// MessageText:
'//
'// The security processor reported an initialization error.
'//
%SL_REMAPPING_SP_PUB_GENERAL_NOT_INITIALIZED = &HC004D101&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_SYSTEM_TIME_SKEWED
'//
'// MessageText:
'//
'// The security processor reported that the machine time is inconsistent with the trusted time.
'//
%SL_REMAPPING_SP_STATUS_SYSTEM_TIME_SKEWED = &H8004D102&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_GENERIC_FAILURE
'//
'// MessageText:
'//
'// The security processor reported that an error has occurred.
'//
%SL_REMAPPING_SP_STATUS_GENERIC_FAILURE = &HC004D103&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_INVALIDARG
'//
'// MessageText:
'//
'// The security processor reported that invalid data was used.
'//
%SL_REMAPPING_SP_STATUS_INVALIDARG = &HC004D104&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The security processor reported that the value already exists.
'//
%SL_REMAPPING_SP_STATUS_ALREADY_EXISTS = &HC004D105&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_INSUFFICIENT_BUFFER
'//
'// MessageText:
'//
'// The security processor reported that an insufficient buffer was used.
'//
%SL_REMAPPING_SP_STATUS_INSUFFICIENT_BUFFER = &HC004D107&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_INVALIDDATA
'//
'// MessageText:
'//
'// The security processor reported that invalid data was used.
'//
%SL_REMAPPING_SP_STATUS_INVALIDDATA = &HC004D108&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_INVALID_SPAPI_CALL
'//
'// MessageText:
'//
'// The security processor reported that an invalid call was made.
'//
%SL_REMAPPING_SP_STATUS_INVALID_SPAPI_CALL = &HC004D109&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_INVALID_SPAPI_VERSION
'//
'// MessageText:
'//
'// The security processor reported a version mismatch error.
'//
%SL_REMAPPING_SP_STATUS_INVALID_SPAPI_VERSION = &HC004D10A&

'//
'// MessageId: SL_REMAPPING_SP_STATUS_DEBUGGER_DETECTED
'//
'// MessageText:
'//
'// The security processor cannot operate while a debugger is attached.
'//
%SL_REMAPPING_SP_STATUS_DEBUGGER_DETECTED = &H8004D10B&


'//////////////////////////////////////////////////////////
'// SP_PUB_TS_ZONE
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_TAMPERED
'//
'// MessageText:
'//
'// The security processor reported that the trusted data store was tampered.
'//
%SL_REMAPPING_SP_PUB_TS_TAMPERED  = &HC004D301&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_REARMED
'//
'// MessageText:
'//
'// The security processor reported that the trusted data store was rearmed.
'//
%SL_REMAPPING_SP_PUB_TS_REARMED   = &HC004D302&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_RECREATED
'//
'// MessageText:
'//
'// The security processor reported that the trusted store has been recreated.
'//
%SL_REMAPPING_SP_PUB_TS_RECREATED = &HC004D303&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_NOT_FOUND
'//
'// MessageText:
'//
'// The security processor reported that entry key was not found in the trusted data store.
'//
%SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_NOT_FOUND = &HC004D304&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The security processor reported that the entry key already exists in the trusted data store.
'//
%SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_ALREADY_EXISTS = &HC004D305&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_SIZE_TOO_BIG
'//
'// MessageText:
'//
'// The security processor reported that the entry key is too big to fit in the trusted data store.
'//
%SL_REMAPPING_SP_PUB_TS_ENTRY_KEY_SIZE_TOO_BIG = &HC004D306&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_MAX_REARM_REACHED
'//
'// MessageText:
'//
'// The security processor reported that the maximum allowed number of re-arms has been exceeded.  You must re-install the OS before trying to re-arm again.
'//
%SL_REMAPPING_SP_PUB_TS_MAX_REARM_REACHED = &HC004D307&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_DATA_SIZE_TOO_BIG
'//
'// MessageText:
'//
'// The security processor has reported that entry data size is too big to fit in the trusted data store.
'//
%SL_REMAPPING_SP_PUB_TS_DATA_SIZE_TOO_BIG = &HC004D308&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_INVALID_HW_BINDING
'//
'// MessageText:
'//
'// The security processor has reported that the machine has gone out of hardware tolerance.
'//
%SL_REMAPPING_SP_PUB_TS_INVALID_HW_BINDING = &HC004D309&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TIMER_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The security processor has reported that the secure timer already exists.
'//
%SL_REMAPPING_SP_PUB_TIMER_ALREADY_EXISTS = &HC004D30A&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TIMER_NOT_FOUND
'//
'// MessageText:
'//
'// The security processor has reported that the secure timer was not found.
'//
%SL_REMAPPING_SP_PUB_TIMER_NOT_FOUND = &HC004D30B&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TIMER_EXPIRED
'//
'// MessageText:
'//
'// The security processor has reported that the secure timer has expired.
'//
%SL_REMAPPING_SP_PUB_TIMER_EXPIRED = &HC004D30C&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TIMER_NAME_SIZE_TOO_BIG
'//
'// MessageText:
'//
'// The security processor has reported that the secure timer name is too long.
'//
%SL_REMAPPING_SP_PUB_TIMER_NAME_SIZE_TOO_BIG = &HC004D30D&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TS_FULL
'//
'// MessageText:
'//
'// The security processor reported that the trusted data store is full.
'//
%SL_REMAPPING_SP_PUB_TS_FULL      = &HC004D30E&


'//////////////////////////////////////////////////////////
'// SP_PUB_MODAUTH_ZONE
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_REMAPPING_SP_PUB_TAMPER_MODULE_AUTHENTICATION
'//
'// MessageText:
'//
'// The security processor reported a system file mismatch error.
'//
%SL_REMAPPING_SP_PUB_TAMPER_MODULE_AUTHENTICATION = &HC004D401&

'//
'// MessageId: SL_REMAPPING_SP_PUB_TAMPER_SECURITY_PROCESSOR_PATCHED
'//
'// MessageText:
'//
'// The security processor reported a system file mismatch error.
'//
%SL_REMAPPING_SP_PUB_TAMPER_SECURITY_PROCESSOR_PATCHED = &HC004D402&


'//////////////////////////////////////////////////////////
'// SP_PUB_KM_CACHE_ZONE (Error codes)
'//////////////////////////////////////////////////////////

'//
'// MessageId: SL_REMAPPING_SP_PUB_KM_CACHE_TAMPER
'//
'// MessageText:
'//
'// The security processor reported an error with the kernel data.
'//
%SL_REMAPPING_SP_PUB_KM_CACHE_TAMPER = &HC004D501&
