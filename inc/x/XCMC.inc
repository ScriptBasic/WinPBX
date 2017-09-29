' ########################################################################################
' Microsoft Windows
' File: XCMC.inc
' Contents: CMC Common extensions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XCMC_INC = 1

'  /*BEGIN CMC INTERFACE */

'/*BASIC DATA TYPES*/
'#ifndef DIFFERENT_PLATFORM
'typedef char                CMC_sint8;
'typedef short               CMC_sint16;
'typedef long int            CMC_sint32;
'typedef unsigned short int  CMC_uint16;
'typedef unsigned long int   CMC_uint32;
'typedef void far *          CMC_buffer;
'typedef char far *          CMC_string;
'#endif

'typedef CMC_uint16          CMC_boolean;
'typedef CMC_sint32          CMC_enum;
'typedef CMC_uint32          CMC_return_code;
'typedef CMC_uint32          CMC_flags;
'typedef CMC_string          CMC_object_identifier;

%CMC_FALSE   = 0??
%CMC_TRUE    = 1??

'/*DATA STRUCTURES*/

'/*COUNTED STRING*/
' // Size = 8 bytes
TYPE CMC_counted_string DWORD
   length AS DWORD        ' CMC_uint32
   string AS ASCIIZ * 1   ' string[1] // variable size string
END TYPE

'/*SESSION ID*/
'typedef CMC_uint32      CMC_session_id;

'/*TIME*/
'/* unusedX fields needed to align struct on 4-byte boundary */
' // Size = 12 bytes
TYPE CMC_time BYTE
   second  AS BYTE      ' CMC_sint8
   minute  AS BYTE      ' CMC_sint8
   hour    AS BYTE      ' CMC_sint8
   day     AS BYTE      ' CMC_sint8
   month   AS BYTE      ' CMC_sint8
   year    AS BYTE      ' CMC_sint8
   isdst   AS BYTE      ' CMC_sint8
   unused1 AS BYTE      ' CMC_sint8
   tmzone  AS INTEGER   ' CMC_sint16
   unused2 AS INTEGER   ' CMC_sint16
END TYPE

%CMC_NO_TIMEZONE = &H8000&

'typedef CMC_uint32          CMC_ui_id;

'/*EXTENSION*/
' // Size = 16 bytes
TYPE CMC_extension DWORD
   item_code       AS DWORD   ' CMC_uint32
   item_data       AS DWORD   ' CMC_uint32
   item_reference  AS DWORD   ' CMC_buffer
   extension_flags AS DWORD   ' CMC_flags
END TYPE

'/* EXTENSION FLAGS */
%CMC_EXT_REQUIRED       = &H00010000???
%CMC_EXT_OUTPUT         = &H00020000???
%CMC_EXT_LAST_ELEMENT   = &H80000000???
%CMC_EXT_RSV_FLAG_MASK  = &HFFFF0000???
%CMC_EXT_ITEM_FLAG_MASK = &H0000FFFF???

'/*ATTACHMENT*/
' // Size = 20 bytes
TYPE CMC_attachment DWORD
   attach_title      AS ASCIIZ PTR          ' CMC_string
   attach_type       AS ASCIIZ PTR          ' CMC_object_identifier
   attach_filename   AS ASCIIZ PTR          ' CMC_string
   attach_flags      AS DWORD               ' CMC_flags
   attach_extensions AS CMC_extension PTR   ' CMC_extension FAR *
END TYPE

'/* ATTACHMENT FLAGS */
%CMC_ATT_APP_OWNS_FILE               = 1???
%CMC_ATT_LAST_ELEMENT                = &H80000000???

$CMC_ATT_OID_BINARY                  = "? ? ? ? ? ?"
$CMC_ATT_OID_TEXT                    = "? ? ? ? ? ?"

'/*MESSAGE REFERENCE*/
'typedef CMC_counted_string  CMC_message_reference;

' // Size = 8 bytes
TYPE CMC_message_reference DWORD
   length AS DWORD
   string AS ASCIIZ * 1   ' variable size string
END TYPE

'/*RECIPIENT*/
' // Size = 24 bytes
TYPE CMC_recipient DWORD
   name             AS ASCIIZ PTR          ' CMC_string
   name_type        AS LONG                ' CMC_enum
   address          AS ASCIIZ PTR          ' CMC_string
   role             AS LONG                ' CMC_enum
   recip_flags      AS DWORD               ' CMC_flags
   recip_extensions AS CMC_extension PTR   ' CMC_extension FAR
END TYPE

'/* NAME TYPES */
%CMC_TYPE_UNKNOWN                    = 0&
%CMC_TYPE_INDIVIDUAL                 = 1&
%CMC_TYPE_GROUP                      = 2&

'/* ROLES */
%CMC_ROLE_TO                         = 0&
%CMC_ROLE_CC                         = 1&
%CMC_ROLE_BCC                        = 2&
%CMC_ROLE_ORIGINATOR                 = 3&
%CMC_ROLE_AUTHORIZING_USER           = 4&

'/* RECIPIENT FLAGS */
%CMC_RECIP_IGNORE                    = 1???
%CMC_RECIP_LIST_TRUNCATED            = 2???
%CMC_RECIP_LAST_ELEMENT              = &H80000000???

'/*MESSAGE*/
' // Size = 24 bytes
TYPE CMC_message DWORD
   message_reference  AS CMC_message_reference PTR   ' CMC_message_reference FAR *
   message_type       AS ASCIIZ PTR                  ' CMC_string
   subject            AS ASCIIZ PTR                  ' CMC_string
   time_sent          AS CMC_time                    ' CMC_time
   text_note          AS ASCIIZ PTR                  ' CMC_string
   recipients         AS CMC_recipient PTR           ' CMC_recipient FAR *
   attachments        AS CMC_attachment PTR          ' CMC_attachment FAR *
   message_flags      AS DWORD                       ' CMC_flags
   message_extensions AS CMC_extension PTR           ' CMC_extension FAR *
END TYPE

'/* MESSAGE FLAGS */
%CMC_MSG_READ                        =  1???
%CMC_MSG_TEXT_NOTE_AS_FILE           =  2???
%CMC_MSG_UNSENT                      =  4???
%CMC_MSG_LAST_ELEMENT                =  &H80000000???

'/*MESSAGE SUMMARY*/
' // Size = 40 bytes
TYPE CMC_message_summary
   message_reference          AS CMC_message_reference PTR   ' CMC_message_reference FAR *
   message_type               AS ASCIIZ PTR                  ' CMC_string
   subject                    AS ASCIIZ PTR                  ' CMC_string
   time_sent                  AS CMC_time                    ' CMC_time
   byte_length                AS DWORD                       ' CMC_uint32
   originator                 AS CMC_recipient PTR           ' CMC_recipient FAR *
   summary_flags              AS DWORD                       ' CMC_flags
   message_summary_extensions AS CMC_extension PTR           ' CMC_extension FAR
END TYPE

'/* MESSAGE SUMMARY FLAGS */
%CMC_SUM_READ                        =  1???
%CMC_SUM_UNSENT                      =  2???
%CMC_SUM_LAST_ELEMENT                =  &H80000000???

'/*CMC FUNCTIONS */

'/*CROSS FUNCTION FLAGS */
%CMC_ERROR_UI_ALLOWED                =  &H01000000???
%CMC_LOGON_UI_ALLOWED                =  &H02000000???
%CMC_COUNTED_STRING_TYPE             =  &H04000000???

'/*SEND*/
DECLARE FUNCTION cmc_send IMPORT "MAPI32.DLL" ALIAS "cmc_send" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id     session
 , BYREF message AS CMC_message _                       ' __in     CMC_message FAR   *message
 , BYVAL send_flags AS DWORD _                          ' __in     CMC_flags          send_flags
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id          ui_id
 , BYVAL send_extensions AS CMC_extension PTR _         ' __in_out CMC_extension FAR *send_extensions
 ) AS DWORD                                             ' CMC_return_code

%CMC_SEND_UI_REQUESTED               = 1???

'/*SEND DOCUMENT*/
DECLARE FUNCTION cmc_send_documents IMPORT "MAPI32.DLL" ALIAS "cmc_send_documents" ( _
   BYREF recipient_addresses AS ASCIIZ _                ' __in CMC_string recipient_addresses
 , BYREF subject AS ASCIIZ _                            ' __in CMC_string subject
 , BYREF text_note AS ASCIIZ _                          ' __in CMC_string text_note
 , BYVAL send_doc_flags AS DWORD _                      ' __in CMC_flags  send_doc_flags
 , BYREF file_paths AS ASCIIZ _                         ' __in CMC_string file_paths
 , BYREF file_names AS ASCIIZ _                         ' __in CMC_string file_names
 , BYREF delimiter AS ASCIIZ _                          ' __in CMC_string delimiter
 , BYVAL ui_id AS DWORD _                               ' __in CMC_ui_id  ui_id
 ) AS DWORD                                             ' CMC_return_code


%CMC_FIRST_ATTACH_AS_TEXT_NOTE       = 2???

'/*ACT ON*/
DECLARE FUNCTION cmc_act_on IMPORT "MAPI32.DLL" ALIAS "cmc_act_on" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id             session
 , BYVAL message_reference AS CMC_message_reference PTR _ ' __in     CMC_message_reference FAR *message_reference
 , BYVAL operation AS LONG _                            ' __in     CMC_enum                   operation
 , BYVAL act_on_flags AS DWORD _                        ' __in     CMC_flags                  act_on_flags
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id                  ui_id
 , BYVAL act_on_extensions AS CMC_extension PTR _       ' __in_out CMC_extension FAR         *act_on_extensions
 ) AS DWORD                                             ' CMC_return_code

%CMC_ACT_ON_EXTENDED                 = 0&
%CMC_ACT_ON_DELETE                   = 1&

'/*LIST*/
DECLARE FUNCTION cmc_list IMPORT "MAPI32.DLL" ALIAS "cmc_list" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id                 session
 , BYREF message_type AS ASCIIZ _                       ' __in     CMC_string                     message_type
 , BYVAL list_flags AS DWORD _                          ' __in     CMC_flags                      list_flags
 , BYVAL seed AS CMC_message_reference PTR _            ' __in     CMC_message_reference FAR     *seed
 , BYREF count AS DWORD _                               ' __in_out CMC_uint32 FAR                *count
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id                      ui_id
 , BYVAL result AS CMC_message_summary PTR _            ' __out    CMC_message_summary FAR * FAR *result
 , BYVAL list_extensions AS CMC_extension PTR _         ' __in_out CMC_extension FAR             *list_extensions
 ) AS DWORD                                             ' CMC_return_code


%CMC_LIST_UNREAD_ONLY                = 1???
%CMC_LIST_MSG_REFS_ONLY              = 2???
%CMC_LIST_COUNT_ONLY                 = 4???

%CMC_LENGTH_UNKNOWN                  = &HFFFFFFFF???

'/*READ*/
DECLARE FUNCTION cmc_read IMPORT "MAPI32.DLL" ALIAS "cmc_read" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id             session
 , BYVAL message_reference AS CMC_message_reference PTR _ ' __in     CMC_message_reference FAR *message_reference
 , BYVAL read_flags AS DWORD _                          ' __in     CMC_flags                  read_flags
 , BYREF message AS CMC_message _                       ' __out    CMC_message FAR * FAR     *message
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id                  ui_id
 , BYVAL read_extensions AS CMC_extension PTR _         ' __in_out CMC_extension FAR         *read_extensions
 ) AS DWORD                                             ' CMC_return_code

%CMC_DO_NOT_MARK_AS_READ             = 1???
%CMC_MSG_AND_ATT_HDRS_ONLY           = 2???
%CMC_READ_FIRST_UNREAD_MESSAGE       = 4???

'/*LOOK UP*/
DECLARE FUNCTION cmc_look_up IMPORT "MAPI32.DLL" ALIAS "cmc_look_up" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id           session
 , BYVAL recipient_in AS CMC_recipient PTR _            ' __in     CMC_recipient FAR       *recipient_in
 , BYVAL look_up_flags AS DWORD _                       ' __in     CMC_flags                look_up_flags
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id                ui_id
 , BYREF count AS DWORD _                               ' __in_out CMC_uint32 FAR          *count
 , BYVAL recipient_out AS CMC_recipient PTR  _          ' __out    CMC_recipient FAR * FAR *recipient_out
 , BYVAL look_up_extensions AS CMC_extension PTR _      ' __in_out CMC_extension FAR       *look_up_extensions
 ) AS DWORD                                             ' CMC_return_code


%CMC_LOOKUP_RESOLVE_PREFIX_SEARCH    = 1???
%CMC_LOOKUP_RESOLVE_IDENTITY         = 2???
%CMC_LOOKUP_RESOLVE_UI               = 4???
%CMC_LOOKUP_DETAILS_UI               = 8???
%CMC_LOOKUP_ADDRESSING_UI            = 16???

'/*FREE*/
DECLARE FUNCTION cmc_free IMPORT "MAPI32.DLL" ALIAS "cmc_free" ( _
   BYVAL memory AS DWORD _                              ' __in CMC_buffer memory
 ) AS DWORD                                             ' CMC_return_code

'/* LOGOFF */
DECLARE FUNCTION cmc_logoff IMPORT "MAPI32.DLL" ALIAS "cmc_logoff" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id     session
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id          ui_id
 , BYVAL logoff_flags AS DWORD _                        ' __in     CMC_flags          logoff_flags
 , BYVAL logoff_extensions AS CMC_extension PTR _       ' __in_out CMC_extension FAR *logoff_extensions
 ) AS DWORD                                             ' CMC_return_code

%CMC_LOGOFF_UI_ALLOWED               = 1???

'/* LOGON */
DECLARE FUNCTION cmc_logon IMPORT "MAPI32.DLL" ALIAS "cmc_logon" ( _
   BYREF service AS ASCIIZ _                            ' __in     CMC_string             service
 , BYREF user AS ASCIIZ _                               ' __in     CMC_string             user
 , BYREF password AS ASCIIZ _                           ' __in     CMC_string             password
 , BYREF character_set AS ASCIIZ _                      ' __in     CMC_object_identifier  character_set
 , BYVAL ui_id AS DWORD _                               ' __in     CMC_ui_id              ui_id
 , BYVAL caller_cmc_version AS WORD _                   ' __in     CMC_uint16             caller_cmc_version
 , BYVAL logon_flags AS DWORD _                         ' __in     CMC_flags              logon_flags
 , BYREF session AS DWORD _                             ' __out    CMC_session_id FAR    *session
 , BYVAL logon_extensions AS CMC_extension PTR _        ' __in_out CMC_extension FAR     *logon_extensions
 ) AS DWORD                                             ' CMC_return_code

%CMC_VERSION         = 100??

'/* QUERY CONFIGURATION */
DECLARE FUNCTION cmc_query_configuration IMPORT "MAPI32.DLL" ALIAS "cmc_query_configuration" ( _
   BYVAL session AS DWORD _                             ' __in     CMC_session_id     session
 , BYVAL item AS LONG _                                 ' __in     CMC_enum           item
 , BYVAL reference AS DWORD _                           ' __out    CMC_buffer         reference
 , BYVAL config_extensions AS CMC_extension PTR _       ' __in_out CMC_extension FAR *config_extensions
 ) AS DWORD                                             ' CMC_return_code

'/*QUERY CONFIGURATION ENUMS */
%CMC_CONFIG_CHARACTER_SET            = 1&
%CMC_CONFIG_LINE_TERM                = 2&
%CMC_CONFIG_DEFAULT_SERVICE          = 3&
%CMC_CONFIG_DEFAULT_USER             = 4&
%CMC_CONFIG_REQ_PASSWORD             = 5&
%CMC_CONFIG_REQ_SERVICE              = 6&
%CMC_CONFIG_REQ_USER                 = 7&
%CMC_CONFIG_UI_AVAIL                 = 8&
%CMC_CONFIG_SUP_NOMKMSGREAD          = 9&
%CMC_CONFIG_SUP_COUNTED_STR          = 10&
%CMC_CONFIG_VER_IMPLEM               = 11&
%CMC_CONFIG_VER_SPEC                 = 12&

'/* CONFIG LINE TERM ENUM */
%CMC_LINE_TERM_CRLF                  = 0&
%CMC_LINE_TERM_CR                    = 1&
%CMC_LINE_TERM_LF                    = 2&

'/* CONFIG REQUIRED LOGON PARAMETER ENUM */
%CMC_REQUIRED_NO                     = 0&
%CMC_REQUIRED_YES                    = 1&
%CMC_REQUIRED_OPT                    = 2&

'/* DEFINED OBJECT ID'S FOR CHARACTER SETS */
$CMC_CHAR_CP437                      = "1 2 840 113556 3 2 437"
$CMC_CHAR_CP850                      = "1 2 840 113556 3 2 850"
$CMC_CHAR_CP1252                     = "1 2 840 113556 3 2 1252"
$CMC_CHAR_ISTRING                    = "1 2 840 113556 3 2 0"
$CMC_CHAR_UNICODE                    = "1 2 840 113556 3 2 1"

'/* RETURN CODE FLAGS */
%CMC_ERROR_DISPLAYED                 =  &H00008000???
%CMC_ERROR_RSV_MASK                  =  &H0000FFFF???
%CMC_ERROR_IMPL_MASK                 =  &HFFFF0000???

'/* RETURN CODES */
%CMC_SUCCESS                         =  0???

%CMC_E_AMBIGUOUS_RECIPIENT           =  1???
%CMC_E_ATTACHMENT_NOT_FOUND          =  2???
%CMC_E_ATTACHMENT_OPEN_FAILURE       =  3???
%CMC_E_ATTACHMENT_READ_FAILURE       =  4???
%CMC_E_ATTACHMENT_WRITE_FAILURE      =  5???
%CMC_E_COUNTED_STRING_UNSUPPORTED    =  6???
%CMC_E_DISK_FULL                     =  7???
%CMC_E_FAILURE                       =  8???
%CMC_E_INSUFFICIENT_MEMORY           =  9???
%CMC_E_INVALID_CONFIGURATION         =  10???
%CMC_E_INVALID_ENUM                  =  11???
%CMC_E_INVALID_FLAG                  =  12???
%CMC_E_INVALID_MEMORY                =  13???
%CMC_E_INVALID_MESSAGE_PARAMETER     =  14???
%CMC_E_INVALID_MESSAGE_REFERENCE     =  15???
%CMC_E_INVALID_PARAMETER             =  16???
%CMC_E_INVALID_SESSION_ID            =  17???
%CMC_E_INVALID_UI_ID                 =  18???
%CMC_E_LOGON_FAILURE                 =  19???
%CMC_E_MESSAGE_IN_USE                =  20???
%CMC_E_NOT_SUPPORTED                 =  21???
%CMC_E_PASSWORD_REQUIRED             =  22???
%CMC_E_RECIPIENT_NOT_FOUND           =  23???
%CMC_E_SERVICE_UNAVAILABLE           =  24???
%CMC_E_TEXT_TOO_LARGE                =  25???
%CMC_E_TOO_MANY_FILES                =  26???
%CMC_E_TOO_MANY_RECIPIENTS           =  27???
%CMC_E_UNABLE_TO_NOT_MARK_AS_READ    =  28???
%CMC_E_UNRECOGNIZED_MESSAGE_TYPE     =  29???
%CMC_E_UNSUPPORTED_ACTION            =  30???
%CMC_E_UNSUPPORTED_CHARACTER_SET     =  31???
%CMC_E_UNSUPPORTED_DATA_EXT          =  32???
%CMC_E_UNSUPPORTED_FLAG              =  33???
%CMC_E_UNSUPPORTED_FUNCTION_EXT      =  34???
%CMC_E_UNSUPPORTED_VERSION           =  35???
%CMC_E_USER_CANCEL                   =  36???
%CMC_E_USER_NOT_LOGGED_ON            =  37???

' include the other cmc related files
#INCLUDE ONCE "xcmcext.inc"
#INCLUDE ONCE "xcmcmsx2.inc"
