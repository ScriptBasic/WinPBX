' ########################################################################################
' Microsoft Windows
' File: EhStorMsg.inc
' Contents: Message definitions for Enhanced Storage APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EHSTORMSG_INC = 1

'//
'// --------------------------------------------------------------------------
'// Enhanced Storage error codes will use FACILITY_ITF. According to MSDN doc,
'// it is recommended that code values start at 0x0200 as COM FACILITY_ITF
'// will use the code values from 0x0000 - 0x01FF.
'//
'// The code value range is partition based on the following scheme:
'//
'// 0x0200 - 0x03FF: general error codes
'// 0x0400 - 0x04FF: authentication related error codes
'// 0x0500 - 0x0FFF: reserved for other high level feature related error codes
'// 0x1000 - 0x10FF: certificate silo related error codes
'// 0x1100 - 0x11FF: password silo related error codes
'// 0x1200 - 0xBFFF: reserved for other silo specific error codes
'// 0xC000 - 0xFFFF: reserved for 3rd party silo specific error codes
'//
'// --------------------------------------------------------------------------
'//

%ES_RESERVED_COM_ERROR_START            = &H0000
%ES_RESERVED_COM_ERROR_END              = &H01FF
%ES_GENERAL_ERROR_START                 = &H0200
%ES_GENERAL_ERROR_END                   = &H03FF
%ES_AUTHN_ERROR_START                   = &H0400
%ES_AUTHN_ERROR_END                     = &H04FF
%ES_RESERVED_SILO_ERROR_START           = &H0500
%ES_RESERVED_SILO_ERROR_END             = &H0FFF
%ES_CERT_SILO_ERROR_START               = &H1000
%ES_CERT_SILO_ERROR_END                 = &H10FF
%ES_PW_SILO_ERROR_START                 = &H1100
%ES_PW_SILO_ERROR_END                   = &H11FF
%ES_RESERVED_SILO_SPECIFIC_ERROR_START  = &H1200
%ES_RESERVED_SILO_SPECIFIC_ERROR_END    = &HBFFF
%ES_VENDOR_ERROR_START                  = &HC000
%ES_VENDOR_ERROR_END                    = &HFFFF

'// -----------------------------------
'// Error code related macros
'// -----------------------------------

MACRO IS_ENHANCED_STORAGE_GENERAL_ERROR(x) = (x >= %ES_GENERAL_ERROR_START AND x <= %ES_GENERAL_ERROR_END)
MACRO IS_ENHANCED_STORAGE_AUTHN_ERROR(x) = (x >= %ES_AUTHN_ERROR_START AND x <= %ES_AUTHN_ERROR_END)
MACRO IS_ENHANCED_STORAGE_CERT_SILO_ERROR(x) = (x >= %ES_CERT_SILO_ERROR_START AND x <= %ES_CERT_SILO_ERROR_END)
MACRO IS_ENHANCED_STORAGE_PW_SILO_ERROR(x) = (x >= %ES_PW_SILO_ERROR_START AND x <= %ES_PW_SILO_ERROR_END)
MACRO IS_ENHANCED_STORAGE_VENDOR_ERROR(x) = (x >= %ES_VENDOR_ERROR_START AND x <= %ES_VENDOR_ERROR_END)

MACRO IS_ENHANCED_STORAGE_RESERVED_ERROR(x) = (x >= %ES_RESERVED_SILO_ERROR_START AND x <= %ES_RESERVED_SILO_ERROR_END) OR _
      (x >= %ES_RESERVED_SILO_SPECIFIC_ERROR_START AND x <= %ES_RESERVED_SILO_SPECIFIC_ERROR_END) OR _
      (x >= %ES_RESERVED_COM_ERROR_START AND x <= %ES_RESERVED_COM_ERROR_END)

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
%FACILITY_ENHANCED_STORAGE        = &H4


'//
'// Define the severity codes
'//
%STATUS_SEVERITY_WARNING          = &H2
%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_INFORMATIONAL    = &H1
%STATUS_SEVERITY_ERROR            = &H3


'//
'// MessageId: ES_E_INVALID_RESPONSE
'//
'// MessageText:
'//
'// Hardware return invalid response.
'//
%ES_E_INVALID_RESPONSE            = &HC0040200&

'//
'// MessageId: ES_E_UNSUPPORTED_CERTIFICATE
'//
'// MessageText:
'//
'// Request used a unsupported certificate.
'//
%ES_E_UNSUPPORTED_CERTIFICATE     = &HC0040201&

'//
'// MessageId: ES_E_INVALID_CERTIFICATE
'//
'// MessageText:
'//
'// Request used an invalid certificate.
'//
%ES_E_INVALID_CERTIFICATE         = &HC0040202&

'//
'// MessageId: ES_E_UNPROVISIONED_HARDWARE
'//
'// MessageText:
'//
'// Hardware is not provision.
'//
%ES_E_UNPROVISIONED_HARDWARE      = &HC0040204&

'//
'// MessageId: ES_E_UNSUPPORTED_HARDWARE
'//
'// MessageText:
'//
'// Hardware is not supported.
'//
%ES_E_UNSUPPORTED_HARDWARE        = &HC0040205&

'//
'// MessageId: ES_E_INCOMPLETE_COMMAND
'//
'// MessageText:
'//
'// An incomplete command was received.
'//
%ES_E_INCOMPLETE_COMMAND          = &HC0040206&

'//
'// MessageId: ES_E_BAD_SEQUENCE
'//
'// MessageText:
'//
'// Command rejected for being out of sequence.
'//
%ES_E_BAD_SEQUENCE                = &HC0040207&

'//
'// MessageId: ES_E_NO_PROBE
'//
'// MessageText:
'//
'// Non-Probe command received before Probe command.
'//
%ES_E_NO_PROBE                    = &HC0040208&

'//
'// MessageId: ES_E_INVALID_SILO
'//
'// MessageText:
'//
'// Invalid silo specified.
'//
%ES_E_INVALID_SILO                = &HC0040209&

'//
'// MessageId: ES_E_INVALID_CAPABILITY
'//
'// MessageText:
'//
'// Invalid capability requested.
'//
%ES_E_INVALID_CAPABILITY          = &HC004020A&

'//
'// MessageId: ES_E_GROUP_POLICY_FORBIDDEN_USE
'//
'// MessageText:
'//
'// Group policy setting forbids use.
'//
%ES_E_GROUP_POLICY_FORBIDDEN_USE  = &HC004020B&

'//
'// MessageId: ES_E_GROUP_POLICY_FORBIDDEN_OPERATION
'//
'// MessageText:
'//
'// Group policy setting forbids operation.
'//
%ES_E_GROUP_POLICY_FORBIDDEN_OPERATION = &HC004020C&

'//
'// MessageId: ES_E_INVALID_PARAM_COMBINATION
'//
'// MessageText:
'//
'// Invalid combination of parameters specified in input data.
'//
%ES_E_INVALID_PARAM_COMBINATION   = &HC004020D&

'//
'// MessageId: ES_E_INVALID_PARAM_LENGTH
'//
'// MessageText:
'//
'// Parameter Byte Length specified in the payload is invalid.
'//
%ES_E_INVALID_PARAM_LENGTH        = &HC004020E&

'//
'// MessageId: ES_E_INCONSISTENT_PARAM_LENGTH
'//
'// MessageText:
'//
'// Parameter Byte Length specified in the payload is not consistent with the number of bytes transferred.
'//
%ES_E_INCONSISTENT_PARAM_LENGTH   = &HC004020F&


'// -----------------------------------------
'// Authentication silo related error codes
'// -----------------------------------------

'//
'// MessageId: ES_E_NO_AUTHENTICATION_REQUIRED
'//
'// MessageText:
'//
'// Hardware does not require authentication.
'//
%ES_E_NO_AUTHENTICATION_REQUIRED  = &HC0040400&


'// --------------------------------------
'// Certificate silo related error codes
'// --------------------------------------

'//
'// MessageId: ES_E_WRONG_CERTIFICATE_TYPE
'//
'// MessageText:
'//
'// Wrong certificate type used in the request.
'//
%ES_E_WRONG_CERTIFICATE_TYPE      = &HC0041000&

'//
'// MessageId: ES_E_INDEX_OCCUPIED
'//
'// MessageText:
'//
'// Index location occupied.
'//
%ES_E_INDEX_OCCUPIED              = &HC0041001&

'//
'// MessageId: ES_E_INVALID_SIGNER_CERT_INDEX
'//
'// MessageText:
'//
'// Invalid signer certificate index.
'//
%ES_E_INVALID_SIGNER_CERT_INDEX   = &HC0041002&

'//
'// MessageId: ES_E_FAIL_VALIDATION
'//
'// MessageText:
'//
'// Data does not meet validation policy requirements.
'//
%ES_E_FAIL_VALIDATION             = &HC0041003&

'//
'// MessageId: ES_E_UNSUPPORTED_VALIDATION
'//
'// MessageText:
'//
'// Validation policy is not supported.
'//
%ES_E_UNSUPPORTED_VALIDATION      = &HC0041004&

'//
'// MessageId: ES_E_INVALID_VALIDATION_OPERATION
'//
'// MessageText:
'//
'// An invalid validation policy operation is specified.
'//
%ES_E_INVALID_VALIDATION_OPERATION = &HC0041005&


'// -----------------------------------
'// Password silo related error codes
'// -----------------------------------

'//
'// MessageId: ES_E_INVALID_FIELD_IDENTIFIER
'//
'// MessageText:
'//
'// An invalid field identifier was found in the data provided by the device.
'//
%ES_E_INVALID_FIELD_IDENTIFIER    = &HC0041100&

'//
'// MessageId: ES_E_CHALLENGE_MISMATCH
'//
'// MessageText:
'//
'// The challenge provided by the device does not match the one provided in an earlier step in the authentication sequence.
'//
%ES_E_CHALLENGE_MISMATCH          = &HC0041101&

'//
'// MessageId: ES_E_CHALLENGE_SIZE_MISMATCH
'//
'// MessageText:
'//
'// The size of the challenge specified by the device does not match the choice of the digest algorithm.
'//
%ES_E_CHALLENGE_SIZE_MISMATCH     = &HC0041102&

'//
'// MessageId: ES_E_FRIENDLY_NAME_TOO_LONG
'//
'// MessageText:
'//
'// The friendly name specified for User is too long.
'//
%ES_E_FRIENDLY_NAME_TOO_LONG      = &HC0041103&

'//
'// MessageId: ES_E_SILO_NAME_TOO_LONG
'//
'// MessageText:
'//
'// The silo name specified is too long.
'//
%ES_E_SILO_NAME_TOO_LONG          = &HC0041104&

'//
'// MessageId: ES_E_PASSWORD_TOO_LONG
'//
'// MessageText:
'//
'// The password specified is too long.
'//
%ES_E_PASSWORD_TOO_LONG           = &HC0041105&

'//
'// MessageId: ES_E_PASSWORD_HINT_TOO_LONG
'//
'// MessageText:
'//
'// The password hint specified is too long.
'//
%ES_E_PASSWORD_HINT_TOO_LONG      = &HC0041106&

'//
'// MessageId: ES_E_OTHER_SECURITY_PROTOCOL_ACTIVE
'//
'// MessageText:
'//
'// Cannot enable IEEE 1667 password security since another security protocol is still active on the device.
'//
%ES_E_OTHER_SECURITY_PROTOCOL_ACTIVE = &HC0041107&

'//
'// MessageId: ES_E_DEVICE_DIGEST_MISSING
'//
'// MessageText:
'//
'// Device digest was expected but was not found in the payload.
'//
%ES_E_DEVICE_DIGEST_MISSING       = &HC0041108&

'//
'// MessageId: ES_E_NOT_AUTHORIZED_UNEXPECTED
'//
'// MessageText:
'//
'// Expected the silo to be in Authorized state, but it was not.
'//
%ES_E_NOT_AUTHORIZED_UNEXPECTED   = &HC0041109&

'//
'// MessageId: ES_E_AUTHORIZED_UNEXPECTED
'//
'// MessageText:
'//
'// Expected the silo to be in Not Authorized state, but it was not.
'//
%ES_E_AUTHORIZED_UNEXPECTED       = &HC004110A&

'//
'// MessageId: ES_E_PROVISIONED_UNEXPECTED
'//
'// MessageText:
'//
'// Expected the silo to be in Not Provisioned state, but it was not.
'//
%ES_E_PROVISIONED_UNEXPECTED      = &HC004110B&

'//
'// MessageId: ES_E_UNKNOWN_DIGEST_ALGORITHM
'//
'// MessageText:
'//
'// The digest algorithm supported by the device is not supported in Windows.
'//
%ES_E_UNKNOWN_DIGEST_ALGORITHM    = &HC004110C&
