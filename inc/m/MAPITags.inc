' ########################################################################################
' Microsoft Windows
' File: MAPITags.inc
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPITAGS_INC = 1

'/*
' *   M A P I T A G S . H
' *
' *   Property tag definitions for standard properties of MAPI
' *   objects.
' *
' *   The following ranges should be used for all property IDs. Note that
' *   property IDs for objects other than messages and recipients should
' *   all fall in the range 0x3000 to 0x3FFF:
' *
' *   From   To      Kind of property
' *   --------------------------------
' *   0001   0BFF   MAPI_defined envelope property
' *   0C00   0DFF   MAPI_defined per-recipient property
' *   0E00   0FFF   MAPI_defined non-transmittable property
' *   1000   2FFF   MAPI_defined message content property
' *
' *   3000   3FFF   MAPI_defined property (usually not message or recipient)
' *
' *   4000   57FF   Transport-defined envelope property
' *   5800   5FFF   Transport-defined per-recipient property
' *   6000   65FF   User-defined non-transmittable property
' *   6600   67FF   Provider-defined internal non-transmittable property
' *   6800   7BFF   Message class-defined content property
' *   7C00   7FFF   Message class-defined non-transmittable
' *               property
' *
' *   8000   FFFE   User-defined Name-to-id mapped property
' *
' *   The 3000-3FFF range is further subdivided as follows:
' *
' *   From   To      Kind of property
' *   --------------------------------
' *   3000   33FF   Common property such as display name, entry ID
' *   3400   35FF   Message store object
' *   3600   36FF   Folder or AB container
' *   3700   38FF   Attachment
' *   3900   39FF   Address book object
' *   3A00   3BFF   Mail user
' *   3C00   3CFF   Distribution list
' *   3D00   3DFF   Profile section
' *   3E00   3FFF   Status object
' *
' *  Copyright 1986-1999 Microsoft Corporation. All Rights Reserved.
' */

#INCLUDE ONCE "mapidefs.inc"

'/* Determine if a property is transmittable. */

'#define FIsTransmittable(ulPropTag) \
'   ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
'   (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
'   ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
'   ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))

FUNCTION FIsTransmittable(BYVAL ulPropTag AS DWORD) AS LONG
   FUNCTION = (PROP_ID(ulPropTag) <  &H0E00??? OR _
               PROP_ID(ulPropTag) >= &H8000??? OR _
              (PROP_ID(ulPropTag) >= &H1000??? AND PROP_ID(ulPropTag) < &H6000???) OR _
              (PROP_ID(ulPropTag) >= &H6800??? AND PROP_ID(ulPropTag) < &H7C00???))
END FUNCTION

'/*
' *   Message envelope properties
' */

%PR_ACKNOWLEDGEMENT_MODE                       = &H00010003???   ' // PROP_TAG(PT_LONG,               0x0001)
%PR_ALTERNATE_RECIPIENT_ALLOWED                = &H0002000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0002)
%PR_AUTHORIZING_USERS                          = &H00030102???   ' // PROP_TAG(PT_BINARY,             0x0003)
%PR_AUTO_FORWARD_COMMENT                       = &H0004001E???   ' // PROP_TAG(PT_TSTRING,            0x0004)
%PR_AUTO_FORWARD_COMMENT_W                     = &H0004001F???   ' // PROP_TAG(PT_UNICODE,            0x0004)
%PR_AUTO_FORWARD_COMMENT_A                     = &H0004001E???   ' // PROP_TAG(PT_STRING8,            0x0004)
%PR_AUTO_FORWARDED                             = &H0005000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0005)
%PR_CONTENT_CONFIDENTIALITY_ALGORITHM_ID       = &H00060102???   ' // PROP_TAG(PT_BINARY,             0x0006)
%PR_CONTENT_CORRELATOR                         = &H00070102???   ' // PROP_TAG(PT_BINARY,             0x0007)
%PR_CONTENT_IDENTIFIER                         = &H0008001E???   ' // PROP_TAG(PT_TSTRING,            0x0008)
%PR_CONTENT_IDENTIFIER_W                       = &H0008001F???   ' // PROP_TAG(PT_UNICODE,            0x0008)
%PR_CONTENT_IDENTIFIER_A                       = &H0008001E???   ' // PROP_TAG(PT_STRING8,            0x0008)
%PR_CONTENT_LENGTH                             = &H00090003???   ' // PROP_TAG(PT_LONG,               0x0009)
%PR_CONTENT_RETURN_REQUESTED                   = &H000A000B???   ' // PROP_TAG(PT_BOOLEAN,            0x000A)

%PR_CONVERSATION_KEY                           = &H000B0102???   ' // PROP_TAG(PT_BINARY,             0x000B)

%PR_CONVERSION_EITS                            = &H000C0102???   ' // PROP_TAG(PT_BINARY,             0x000C)
%PR_CONVERSION_WITH_LOSS_PROHIBITED            = &H000D000B???   ' // PROP_TAG(PT_BOOLEAN,            0x000D)
%PR_CONVERTED_EITS                             = &H000E0102???   ' // PROP_TAG(PT_BINARY,             0x000E)
%PR_DEFERRED_DELIVERY_TIME                     = &H000F0040???   ' // PROP_TAG(PT_SYSTIME,            0x000F)
%PR_DELIVER_TIME                               = &H00100040???   ' // PROP_TAG(PT_SYSTIME,            0x0010)
%PR_DISCARD_REASON                             = &H00110003???   ' // PROP_TAG(PT_LONG,               0x0011)
%PR_DISCLOSURE_OF_RECIPIENTS                   = &H0012000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0012)
%PR_DL_EXPANSION_HISTORY                       = &H00130102???   ' // PROP_TAG(PT_BINARY,             0x0013)
%PR_DL_EXPANSION_PROHIBITED                    = &H0014000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0014)
%PR_EXPIRY_TIME                                = &H00150040???   ' // PROP_TAG(PT_SYSTIME,            0x0015)
%PR_IMPLICIT_CONVERSION_PROHIBITED             = &H0016000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0016)
%PR_IMPORTANCE                                 = &H00170003???   ' // PROP_TAG(PT_LONG,               0x0017)
%PR_IPM_ID                                     = &H00180102???   ' // PROP_TAG(PT_BINARY,             0x0018)
%PR_LATEST_DELIVERY_TIME                       = &H00190040???   ' // PROP_TAG(PT_SYSTIME,            0x0019)
%PR_MESSAGE_CLASS                              = &H001A001E???   ' // PROP_TAG(PT_TSTRING,            0x001A)
%PR_MESSAGE_CLASS_W                            = &H001A001F???   ' // PROP_TAG(PT_UNICODE,            0x001A)
%PR_MESSAGE_CLASS_A                            = &H001A001E???   ' // PROP_TAG(PT_STRING8,            0x001A)
%PR_MESSAGE_DELIVERY_ID                        = &H001B0102???   ' // PROP_TAG(PT_BINARY,             0x001B)

%PR_MESSAGE_SECURITY_LABEL                     = &H001E0102???   ' // PROP_TAG(PT_BINARY,             0x001E)
%PR_OBSOLETED_IPMS                             = &H001F0102???   ' // PROP_TAG(PT_BINARY,             0x001F)
%PR_ORIGINALLY_INTENDED_RECIPIENT_NAME         = &H00200102???   ' // PROP_TAG(PT_BINARY,             0x0020)
%PR_ORIGINAL_EITS                              = &H00210102???   ' // PROP_TAG(PT_BINARY,             0x0021)
%PR_ORIGINATOR_CERTIFICATE                     = &H00220102???   ' // PROP_TAG(PT_BINARY,             0x0022)
%PR_ORIGINATOR_DELIVERY_REPORT_REQUESTED       = &H0023000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0023)
%PR_ORIGINATOR_RETURN_ADDRESS                  = &H00240102???   ' // PROP_TAG(PT_BINARY,             0x0024)

%PR_PARENT_KEY                                 = &H00250102???   ' // PROP_TAG(PT_BINARY,             0x0025)
%PR_PRIORITY                                   = &H00260003???   ' // PROP_TAG(PT_LONG,               0x0026)

%PR_ORIGIN_CHECK                               = &H00270102???   ' // PROP_TAG(PT_BINARY,             0x0027)
%PR_PROOF_OF_SUBMISSION_REQUESTED              = &H0028000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0028)
%PR_READ_RECEIPT_REQUESTED                     = &H0029000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0029)
%PR_RECEIPT_TIME                               = &H002A0040???   ' // PROP_TAG(PT_SYSTIME,            0x002A)
%PR_RECIPIENT_REASSIGNMENT_PROHIBITED          = &H002B000B???   ' // PROP_TAG(PT_BOOLEAN,            0x002B)
%PR_REDIRECTION_HISTORY                        = &H002C0102???   ' // PROP_TAG(PT_BINARY,             0x002C)
%PR_RELATED_IPMS                               = &H002D0102???   ' // PROP_TAG(PT_BINARY,             0x002D)
%PR_ORIGINAL_SENSITIVITY                       = &H002E0003???   ' // PROP_TAG(PT_LONG,               0x002E)
%PR_LANGUAGES                                  = &H002F001E???   ' // PROP_TAG(PT_TSTRING,            0x002F)
%PR_LANGUAGES_W                                = &H002F001F???   ' // PROP_TAG(PT_UNICODE,            0x002F)
%PR_LANGUAGES_A                                = &H002F001E???   ' // PROP_TAG(PT_STRING8,            0x002F)
%PR_REPLY_TIME                                 = &H00300040???   ' // PROP_TAG(PT_SYSTIME,            0x0030)
%PR_REPORT_TAG                                 = &H00310102???   ' // PROP_TAG(PT_BINARY,             0x0031)
%PR_REPORT_TIME                                = &H00320040???   ' // PROP_TAG(PT_SYSTIME,            0x0032)
%PR_RETURNED_IPM                               = &H0033000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0033)
%PR_SECURITY                                   = &H00340003???   ' // PROP_TAG(PT_LONG,               0x0034)
%PR_INCOMPLETE_COPY                            = &H0035000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0035)
%PR_SENSITIVITY                                = &H00360003???   ' // PROP_TAG(PT_LONG,               0x0036)
%PR_SUBJECT                                    = &H0037001E???   ' // PROP_TAG(PT_TSTRING,            0x0037)
%PR_SUBJECT_W                                  = &H0037001F???   ' // PROP_TAG(PT_UNICODE,            0x0037)
%PR_SUBJECT_A                                  = &H0037001E???   ' // PROP_TAG(PT_STRING8,            0x0037)
%PR_SUBJECT_IPM                                = &H00380102???   ' // PROP_TAG(PT_BINARY,             0x0038)
%PR_CLIENT_SUBMIT_TIME                         = &H00390040???   ' // PROP_TAG(PT_SYSTIME,            0x0039)
%PR_REPORT_NAME                                = &H003A001E???   ' // PROP_TAG(PT_TSTRING,            0x003A)
%PR_REPORT_NAME_W                              = &H003A001F???   ' // PROP_TAG(PT_UNICODE,            0x003A)
%PR_REPORT_NAME_A                              = &H003A001E???   ' // PROP_TAG(PT_STRING8,            0x003A)
%PR_SENT_REPRESENTING_SEARCH_KEY               = &H003B0102???   ' // PROP_TAG(PT_BINARY,             0x003B)
%PR_X400_CONTENT_TYPE                          = &H003C0102???   ' // PROP_TAG(PT_BINARY,             0x003C)
%PR_SUBJECT_PREFIX                             = &H003D001E???   ' // PROP_TAG(PT_TSTRING,            0x003D)
%PR_SUBJECT_PREFIX_W                           = &H003D001F???   ' // PROP_TAG(PT_UNICODE,            0x003D)
%PR_SUBJECT_PREFIX_A                           = &H003D001E???   ' // PROP_TAG(PT_STRING8,            0x003D)
%PR_NON_RECEIPT_REASON                         = &H003E0003???   ' // PROP_TAG(PT_LONG,               0x003E)
%PR_RECEIVED_BY_ENTRYID                        = &H003F0102???   ' // PROP_TAG(PT_BINARY,             0x003F)
%PR_RECEIVED_BY_NAME                           = &H0040001E???   ' // PROP_TAG(PT_TSTRING,            0x0040)
%PR_RECEIVED_BY_NAME_W                         = &H0040001F???   ' // PROP_TAG(PT_UNICODE,            0x0040)
%PR_RECEIVED_BY_NAME_A                         = &H0040001E???   ' // PROP_TAG(PT_STRING8,            0x0040)
%PR_SENT_REPRESENTING_ENTRYID                  = &H00410102???   ' // PROP_TAG(PT_BINARY,             0x0041)
%PR_SENT_REPRESENTING_NAME                     = &H0042001E???   ' // PROP_TAG(PT_TSTRING,            0x0042)
%PR_SENT_REPRESENTING_NAME_W                   = &H0042001F???   ' // PROP_TAG(PT_UNICODE,            0x0042)
%PR_SENT_REPRESENTING_NAME_A                   = &H0042001E???   ' // PROP_TAG(PT_STRING8,            0x0042)
%PR_RCVD_REPRESENTING_ENTRYID                  = &H00430102???   ' // PROP_TAG(PT_BINARY,             0x0043)
%PR_RCVD_REPRESENTING_NAME                     = &H0044001E???   ' // PROP_TAG(PT_TSTRING,            0x0044)
%PR_RCVD_REPRESENTING_NAME_W                   = &H0044001F???   ' // PROP_TAG(PT_UNICODE,            0x0044)
%PR_RCVD_REPRESENTING_NAME_A                   = &H0044001E???   ' // PROP_TAG(PT_STRING8,            0x0044)
%PR_REPORT_ENTRYID                             = &H00450102???   ' // PROP_TAG(PT_BINARY,             0x0045)
%PR_READ_RECEIPT_ENTRYID                       = &H00460102???   ' // PROP_TAG(PT_BINARY,             0x0046)
%PR_MESSAGE_SUBMISSION_ID                      = &H00470102???   ' // PROP_TAG(PT_BINARY,             0x0047)
%PR_PROVIDER_SUBMIT_TIME                       = &H00480040???   ' // PROP_TAG(PT_SYSTIME,            0x0048)
%PR_ORIGINAL_SUBJECT                           = &H0049001E???   ' // PROP_TAG(PT_TSTRING,            0x0049)
%PR_ORIGINAL_SUBJECT_W                         = &H0049001F???   ' // PROP_TAG(PT_UNICODE,            0x0049)
%PR_ORIGINAL_SUBJECT_A                         = &H0049001E???   ' // PROP_TAG(PT_STRING8,            0x0049)
%PR_DISC_VAL                                   = &H004A000B???   ' // PROP_TAG(PT_BOOLEAN,            0x004A)
%PR_ORIG_MESSAGE_CLASS                         = &H004B001E???   ' // PROP_TAG(PT_TSTRING,            0x004B)
%PR_ORIG_MESSAGE_CLASS_W                       = &H004B001F???   ' // PROP_TAG(PT_UNICODE,            0x004B)
%PR_ORIG_MESSAGE_CLASS_A                       = &H004B001E???   ' // PROP_TAG(PT_STRING8,            0x004B)
%PR_ORIGINAL_AUTHOR_ENTRYID                    = &H004C0102???   ' // PROP_TAG(PT_BINARY,             0x004C)
%PR_ORIGINAL_AUTHOR_NAME                       = &H004D001E???   ' // PROP_TAG(PT_TSTRING,            0x004D)
%PR_ORIGINAL_AUTHOR_NAME_W                     = &H004D001F???   ' // PROP_TAG(PT_UNICODE,            0x004D)
%PR_ORIGINAL_AUTHOR_NAME_A                     = &H004D001E???   ' // PROP_TAG(PT_STRING8,            0x004D)
%PR_ORIGINAL_SUBMIT_TIME                       = &H004E0040???   ' // PROP_TAG(PT_SYSTIME,            0x004E)
%PR_REPLY_RECIPIENT_ENTRIES                    = &H004F0102???   ' // PROP_TAG(PT_BINARY,             0x004F)
%PR_REPLY_RECIPIENT_NAMES                      = &H0050001E???   ' // PROP_TAG(PT_TSTRING,            0x0050)
%PR_REPLY_RECIPIENT_NAMES_W                    = &H0050001F???   ' // PROP_TAG(PT_UNICODE,            0x0050)
%PR_REPLY_RECIPIENT_NAMES_A                    = &H0050001E???   ' // PROP_TAG(PT_STRING8,            0x0050)

%PR_RECEIVED_BY_SEARCH_KEY                     = &H00510102???   ' // PROP_TAG(PT_BINARY,             0x0051)
%PR_RCVD_REPRESENTING_SEARCH_KEY               = &H00520102???   ' // PROP_TAG(PT_BINARY,             0x0052)
%PR_READ_RECEIPT_SEARCH_KEY                    = &H00530102???   ' // PROP_TAG(PT_BINARY,             0x0053)
%PR_REPORT_SEARCH_KEY                          = &H00540102???   ' // PROP_TAG(PT_BINARY,             0x0054)
%PR_ORIGINAL_DELIVERY_TIME                     = &H00550040???   ' // PROP_TAG(PT_SYSTIME,            0x0055)
%PR_ORIGINAL_AUTHOR_SEARCH_KEY                 = &H00560102???   ' // PROP_TAG(PT_BINARY,             0x0056)

%PR_MESSAGE_TO_ME                              = &H0057000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0057)
%PR_MESSAGE_CC_ME                              = &H0058000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0058)
%PR_MESSAGE_RECIP_ME                           = &H0059000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0059)

%PR_ORIGINAL_SENDER_NAME                       = &H005A001E???   ' // PROP_TAG(PT_TSTRING,            0x005A)
%PR_ORIGINAL_SENDER_NAME_W                     = &H005A001F???   ' // PROP_TAG(PT_UNICODE,            0x005A)
%PR_ORIGINAL_SENDER_NAME_A                     = &H005A001E???   ' // PROP_TAG(PT_STRING8,            0x005A)
%PR_ORIGINAL_SENDER_ENTRYID                    = &H005B0102???   ' // PROP_TAG(PT_BINARY,             0x005B)
%PR_ORIGINAL_SENDER_SEARCH_KEY                 = &H005C0102???   ' // PROP_TAG(PT_BINARY,             0x005C)
%PR_ORIGINAL_SENT_REPRESENTING_NAME            = &H005D001E???   ' // PROP_TAG(PT_TSTRING,            0x005D)
%PR_ORIGINAL_SENT_REPRESENTING_NAME_W          = &H005D001F???   ' // PROP_TAG(PT_UNICODE,            0x005D)
%PR_ORIGINAL_SENT_REPRESENTING_NAME_A          = &H005D001E???   ' // PROP_TAG(PT_STRING8,            0x005D)
%PR_ORIGINAL_SENT_REPRESENTING_ENTRYID         = &H005E0102???   ' // PROP_TAG(PT_BINARY,             0x005E)
%PR_ORIGINAL_SENT_REPRESENTING_SEARCH_KEY      = &H005F0102???   ' // PROP_TAG(PT_BINARY,             0x005F)

%PR_START_DATE                                 = &H00600040???   ' // PROP_TAG(PT_SYSTIME,            0x0060)
%PR_END_DATE                                   = &H00610040???   ' // PROP_TAG(PT_SYSTIME,            0x0061)
%PR_OWNER_APPT_ID                              = &H00620003???   ' // PROP_TAG(PT_LONG,               0x0062)
%PR_RESPONSE_REQUESTED                         = &H0063000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0063)

%PR_SENT_REPRESENTING_ADDRTYPE                 = &H0064001E???   ' // PROP_TAG(PT_TSTRING,            0x0064)
%PR_SENT_REPRESENTING_ADDRTYPE_W               = &H0064001F???   ' // PROP_TAG(PT_UNICODE,            0x0064)
%PR_SENT_REPRESENTING_ADDRTYPE_A               = &H0064001E???   ' // PROP_TAG(PT_STRING8,            0x0064)
%PR_SENT_REPRESENTING_EMAIL_ADDRESS            = &H0065001E???   ' // PROP_TAG(PT_TSTRING,            0x0065)
%PR_SENT_REPRESENTING_EMAIL_ADDRESS_W          = &H0065001F???   ' // PROP_TAG(PT_UNICODE,            0x0065)
%PR_SENT_REPRESENTING_EMAIL_ADDRESS_A          = &H0065001E???   ' // PROP_TAG(PT_STRING8,            0x0065)

%PR_ORIGINAL_SENDER_ADDRTYPE                   = &H0066001E???   ' // PROP_TAG(PT_TSTRING,            0x0066)
%PR_ORIGINAL_SENDER_ADDRTYPE_W                 = &H0066001F???   ' // PROP_TAG(PT_UNICODE,            0x0066)
%PR_ORIGINAL_SENDER_ADDRTYPE_A                 = &H0066001E???   ' // PROP_TAG(PT_STRING8,            0x0066)
%PR_ORIGINAL_SENDER_EMAIL_ADDRESS              = &H0067001E???   ' // PROP_TAG(PT_TSTRING,            0x0067)
%PR_ORIGINAL_SENDER_EMAIL_ADDRESS_W            = &H0067001F???   ' // PROP_TAG(PT_UNICODE,            0x0067)
%PR_ORIGINAL_SENDER_EMAIL_ADDRESS_A            = &H0067001E???   ' // PROP_TAG(PT_STRING8,            0x0067)

%PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE        = &H0068001E???   ' // PROP_TAG(PT_TSTRING,            0x0068)
%PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_W      = &H0068001F???   ' // PROP_TAG(PT_UNICODE,            0x0068)
%PR_ORIGINAL_SENT_REPRESENTING_ADDRTYPE_A      = &H0068001E???   ' // PROP_TAG(PT_STRING8,            0x0068)
%PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS   = &H0069001E???   ' // PROP_TAG(PT_TSTRING,            0x0069)
%PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_W = &H0069001F???   ' // PROP_TAG(PT_UNICODE,            0x0069)
%PR_ORIGINAL_SENT_REPRESENTING_EMAIL_ADDRESS_A = &H0069001E???   ' // PROP_TAG(PT_STRING8,            0x0069)

%PR_CONVERSATION_TOPIC                         = &H0070001E???   ' // PROP_TAG(PT_TSTRING,            0x0070)
%PR_CONVERSATION_TOPIC_W                       = &H0070001F???   ' // PROP_TAG(PT_UNICODE,            0x0070)
%PR_CONVERSATION_TOPIC_A                       = &H0070001E???   ' // PROP_TAG(PT_STRING8,            0x0070)
%PR_CONVERSATION_INDEX                         = &H00710102???   ' // PROP_TAG(PT_BINARY,             0x0071)

%PR_ORIGINAL_DISPLAY_BCC                       = &H0072001E???   ' // PROP_TAG(PT_TSTRING,            0x0072)
%PR_ORIGINAL_DISPLAY_BCC_W                     = &H0072001F???   ' // PROP_TAG(PT_UNICODE,            0x0072)
%PR_ORIGINAL_DISPLAY_BCC_A                     = &H0072001E???   ' // PROP_TAG(PT_STRING8,            0x0072)
%PR_ORIGINAL_DISPLAY_CC                        = &H0073001E???   ' // PROP_TAG(PT_TSTRING,            0x0073)
%PR_ORIGINAL_DISPLAY_CC_W                      = &H0073001F???   ' // PROP_TAG(PT_UNICODE,            0x0073)
%PR_ORIGINAL_DISPLAY_CC_A                      = &H0073001E???   ' // PROP_TAG(PT_STRING8,            0x0073)
%PR_ORIGINAL_DISPLAY_TO                        = &H0074001E???   ' // PROP_TAG(PT_TSTRING,            0x0074)
%PR_ORIGINAL_DISPLAY_TO_W                      = &H0074001F???   ' // PROP_TAG(PT_UNICODE,            0x0074)
%PR_ORIGINAL_DISPLAY_TO_A                      = &H0074001E???   ' // PROP_TAG(PT_STRING8,            0x0074)

%PR_RECEIVED_BY_ADDRTYPE                       = &H0075001E???   ' // PROP_TAG(PT_TSTRING,            0x0075)
%PR_RECEIVED_BY_ADDRTYPE_W                     = &H0075001F???   ' // PROP_TAG(PT_UNICODE,            0x0075)
%PR_RECEIVED_BY_ADDRTYPE_A                     = &H0075001E???   ' // PROP_TAG(PT_STRING8,            0x0075)
%PR_RECEIVED_BY_EMAIL_ADDRESS                  = &H0076001E???   ' // PROP_TAG(PT_TSTRING,            0x0076)
%PR_RECEIVED_BY_EMAIL_ADDRESS_W                = &H0076001F???   ' // PROP_TAG(PT_UNICODE,            0x0076)
%PR_RECEIVED_BY_EMAIL_ADDRESS_A                = &H0076001E???   ' // PROP_TAG(PT_STRING8,            0x0076)

%PR_RCVD_REPRESENTING_ADDRTYPE                 = &H0077001E???   ' // PROP_TAG(PT_TSTRING,            0x0077)
%PR_RCVD_REPRESENTING_ADDRTYPE_W               = &H0077001F???   ' // PROP_TAG(PT_UNICODE,            0x0077)
%PR_RCVD_REPRESENTING_ADDRTYPE_A               = &H0077001E???   ' // PROP_TAG(PT_STRING8,            0x0077)
%PR_RCVD_REPRESENTING_EMAIL_ADDRESS            = &H0078001E???   ' // PROP_TAG(PT_TSTRING,            0x0078)
%PR_RCVD_REPRESENTING_EMAIL_ADDRESS_W          = &H0078001F???   ' // PROP_TAG(PT_UNICODE,            0x0078)
%PR_RCVD_REPRESENTING_EMAIL_ADDRESS_A          = &H0078001E???   ' // PROP_TAG(PT_STRING8,            0x0078)

%PR_ORIGINAL_AUTHOR_ADDRTYPE                   = &H0079001E???   ' // PROP_TAG(PT_TSTRING,            0x0079)
%PR_ORIGINAL_AUTHOR_ADDRTYPE_W                 = &H0079001F???   ' // PROP_TAG(PT_UNICODE,            0x0079)
%PR_ORIGINAL_AUTHOR_ADDRTYPE_A                 = &H0079001E???   ' // PROP_TAG(PT_STRING8,            0x0079)
%PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS              = &H007A001E???   ' // PROP_TAG(PT_TSTRING,            0x007A)
%PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_W            = &H007A001F???   ' // PROP_TAG(PT_UNICODE,            0x007A)
%PR_ORIGINAL_AUTHOR_EMAIL_ADDRESS_A            = &H007A001E???   ' // PROP_TAG(PT_STRING8,            0x007A)

%PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE         = &H007B001E???   ' // PROP_TAG(PT_TSTRING,            0x007B)
%PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_W       = &H007B001F???   ' // PROP_TAG(PT_UNICODE,            0x007B)
%PR_ORIGINALLY_INTENDED_RECIP_ADDRTYPE_A       = &H007B001E???   ' // PROP_TAG(PT_STRING8,            0x007B)
%PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS    = &H007C001E???   ' // PROP_TAG(PT_TSTRING,            0x007C)
%PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_W  = &H007C001F???   ' // PROP_TAG(PT_UNICODE,            0x007C)
%PR_ORIGINALLY_INTENDED_RECIP_EMAIL_ADDRESS_A  = &H007C001E???   ' // PROP_TAG(PT_STRING8,            0x007C)

%PR_TRANSPORT_MESSAGE_HEADERS                  = &H007D001E???   ' // PROP_TAG(PT_TSTRING,            0x007D)
%PR_TRANSPORT_MESSAGE_HEADERS_W                = &H007D001F???   ' // PROP_TAG(PT_UNICODE,            0x007D)
%PR_TRANSPORT_MESSAGE_HEADERS_A                = &H007D001E???   ' // PROP_TAG(PT_STRING8,            0x007D)

%PR_DELEGATION                                 = &H007E0102???   ' // PROP_TAG(PT_BINARY,             0x007E)

%PR_TNEF_CORRELATION_KEY                       = &H007F0102???   ' // PROP_TAG(PT_BINARY,             0x007F)



'/*
' *   Message content properties
' */

%PR_BODY                                = &H1000001E???   ' // PROP_TAG(PT_TSTRING,            0x1000)
%PR_BODY_W                              = &H1000001F???   ' // PROP_TAG(PT_UNICODE,            0x1000)
%PR_BODY_A                              = &H1000001E???   ' // PROP_TAG(PT_STRING8,            0x1000)
%PR_REPORT_TEXT                         = &H1001001E???   ' // PROP_TAG(PT_TSTRING,            0x1001)
%PR_REPORT_TEXT_W                       = &H1001001F???   ' // PROP_TAG(PT_UNICODE,            0x1001)
%PR_REPORT_TEXT_A                       = &H1001001E???   ' // PROP_TAG(PT_STRING8,            0x1001)
%PR_ORIGINATOR_AND_DL_EXPANSION_HISTORY = &H10020102???   ' // PROP_TAG(PT_BINARY,             0x1002)
%PR_REPORTING_DL_NAME                   = &H10030102???   ' // PROP_TAG(PT_BINARY,             0x1003)
%PR_REPORTING_MTA_CERTIFICATE           = &H10040102???   ' // PROP_TAG(PT_BINARY,             0x1004)

'/*  Removed PR_REPORT_ORIGIN_AUTHENTICATION_CHECK with DCR 3865, use PR_ORIGIN_CHECK */

%PR_RTF_SYNC_BODY_CRC                 = &H10060003???   ' // PROP_TAG(PT_LONG,               0x1006)
%PR_RTF_SYNC_BODY_COUNT               = &H10070003???   ' // PROP_TAG(PT_LONG,               0x1007)
%PR_RTF_SYNC_BODY_TAG                 = &H1008001E???   ' // PROP_TAG(PT_TSTRING,            0x1008)
%PR_RTF_SYNC_BODY_TAG_W               = &H1008001F???   ' // PROP_TAG(PT_UNICODE,            0x1008)
%PR_RTF_SYNC_BODY_TAG_A               = &H1008001E???   ' // PROP_TAG(PT_STRING8,            0x1008)
%PR_RTF_COMPRESSED                    = &H10090102???   ' // PROP_TAG(PT_BINARY,             0x1009)
%PR_RTF_SYNC_PREFIX_COUNT             = &H10100003???   ' // PROP_TAG(PT_LONG,               0x1010)
%PR_RTF_SYNC_TRAILING_COUNT           = &H10110003???   ' // PROP_TAG(PT_LONG,               0x1011)
%PR_ORIGINALLY_INTENDED_RECIP_ENTRYID = &H10120102???   ' // PROP_TAG(PT_BINARY,             0x1012)

'/*
' *  Reserved 0x1100-0x1200
' */


'/*
' *   Message recipient properties
' */

%PR_CONTENT_INTEGRITY_CHECK                  = &H0C000102???   ' // PROP_TAG(PT_BINARY,             0x0C00)
%PR_EXPLICIT_CONVERSION                      = &H0C010003???   ' // PROP_TAG(PT_LONG,               0x0C01)
%PR_IPM_RETURN_REQUESTED                     = &H0C02000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C02)
%PR_MESSAGE_TOKEN                            = &H0C030102???   ' // PROP_TAG(PT_BINARY,             0x0C03)
%PR_NDR_REASON_CODE                          = &H0C040003???   ' // PROP_TAG(PT_LONG,               0x0C04)
%PR_NDR_DIAG_CODE                            = &H0C050003???   ' // PROP_TAG(PT_LONG,               0x0C05)
%PR_NON_RECEIPT_NOTIFICATION_REQUESTED       = &H0C06000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C06)
%PR_DELIVERY_POINT                           = &H0C070003???   ' // PROP_TAG(PT_LONG,               0x0C07)

%PR_ORIGINATOR_NON_DELIVERY_REPORT_REQUESTED = &H0C08000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C08)
%PR_ORIGINATOR_REQUESTED_ALTERNATE_RECIPIENT = &H0C090102???   ' // PROP_TAG(PT_BINARY,             0x0C09)
%PR_PHYSICAL_DELIVERY_BUREAU_FAX_DELIVERY    = &H0C0A000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C0A)
%PR_PHYSICAL_DELIVERY_MODE                   = &H0C0B0003???   ' // PROP_TAG(PT_LONG,               0x0C0B)
%PR_PHYSICAL_DELIVERY_REPORT_REQUEST         = &H0C0C0003???   ' // PROP_TAG(PT_LONG,               0x0C0C)
%PR_PHYSICAL_FORWARDING_ADDRESS              = &H0C0D0102???   ' // PROP_TAG(PT_BINARY,             0x0C0D)
%PR_PHYSICAL_FORWARDING_ADDRESS_REQUESTED    = &H0C0E000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C0E)
%PR_PHYSICAL_FORWARDING_PROHIBITED           = &H0C0F000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C0F)
%PR_PHYSICAL_RENDITION_ATTRIBUTES            = &H0C100102???   ' // PROP_TAG(PT_BINARY,             0x0C10)
%PR_PROOF_OF_DELIVERY                        = &H0C110102???   ' // PROP_TAG(PT_BINARY,             0x0C11)
%PR_PROOF_OF_DELIVERY_REQUESTED              = &H0C12000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C12)
%PR_RECIPIENT_CERTIFICATE                    = &H0C130102???   ' // PROP_TAG(PT_BINARY,             0x0C13)
%PR_RECIPIENT_NUMBER_FOR_ADVICE              = &H0C14001E???   ' // PROP_TAG(PT_TSTRING,            0x0C14)
%PR_RECIPIENT_NUMBER_FOR_ADVICE_W            = &H0C14001F???   ' // PROP_TAG(PT_UNICODE,            0x0C14)
%PR_RECIPIENT_NUMBER_FOR_ADVICE_A            = &H0C14001E???   ' // PROP_TAG(PT_STRING8,            0x0C14)
%PR_RECIPIENT_TYPE                           = &H0C150003???   ' // PROP_TAG(PT_LONG,               0x0C15)
%PR_REGISTERED_MAIL_TYPE                     = &H0C160003???   ' // PROP_TAG(PT_LONG,               0x0C16)
%PR_REPLY_REQUESTED                          = &H0C17000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0C17)
%PR_REQUESTED_DELIVERY_METHOD                = &H0C180003???   ' // PROP_TAG(PT_LONG,               0x0C18)
%PR_SENDER_ENTRYID                           = &H0C190102???   ' // PROP_TAG(PT_BINARY,             0x0C19)
%PR_SENDER_NAME                              = &H0C1A001E???   ' // PROP_TAG(PT_TSTRING,            0x0C1A)
%PR_SENDER_NAME_W                            = &H0C1A001F???   ' // PROP_TAG(PT_UNICODE,            0x0C1A)
%PR_SENDER_NAME_A                            = &H0C1A001E???   ' // PROP_TAG(PT_STRING8,            0x0C1A)
%PR_SUPPLEMENTARY_INFO                       = &H0C1B001E???   ' // PROP_TAG(PT_TSTRING,            0x0C1B)
%PR_SUPPLEMENTARY_INFO_W                     = &H0C1B001F???   ' // PROP_TAG(PT_UNICODE,            0x0C1B)
%PR_SUPPLEMENTARY_INFO_A                     = &H0C1B001E???   ' // PROP_TAG(PT_STRING8,            0x0C1B)
%PR_TYPE_OF_MTS_USER                         = &H0C1C0003???   ' // PROP_TAG(PT_LONG,               0x0C1C)
%PR_SENDER_SEARCH_KEY                        = &H0C1D0102???   ' // PROP_TAG(PT_BINARY,             0x0C1D)
%PR_SENDER_ADDRTYPE                          = &H0C1E001E???   ' // PROP_TAG(PT_TSTRING,            0x0C1E)
%PR_SENDER_ADDRTYPE_W                        = &H0C1E001F???   ' // PROP_TAG(PT_UNICODE,            0x0C1E)
%PR_SENDER_ADDRTYPE_A                        = &H0C1E001E???   ' // PROP_TAG(PT_STRING8,            0x0C1E)
%PR_SENDER_EMAIL_ADDRESS                     = &H0C1F001E???   ' // PROP_TAG(PT_TSTRING,            0x0C1F)
%PR_SENDER_EMAIL_ADDRESS_W                   = &H0C1F001F???   ' // PROP_TAG(PT_UNICODE,            0x0C1F)
%PR_SENDER_EMAIL_ADDRESS_A                   = &H0C1F001E???   ' // PROP_TAG(PT_STRING8,            0x0C1F)

'/*
' *   Message non-transmittable properties
' */

'/*
' * The two tags, PR_MESSAGE_RECIPIENTS and PR_MESSAGE_ATTACHMENTS,
' * are to be used in the exclude list passed to
' * IMessage::CopyTo when the caller wants either the recipients or attachments
' * of the message to not get copied.  It is also used in the ProblemArray
' * return from IMessage::CopyTo when an error is encountered copying them
' */

%PR_CURRENT_VERSION       = &H0E000014???   ' // PROP_TAG(PT_I8,                 0x0E00)
%PR_DELETE_AFTER_SUBMIT   = &H0E01000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E01)
%PR_DISPLAY_BCC           = &H0E02001E???   ' // PROP_TAG(PT_TSTRING,            0x0E02)
%PR_DISPLAY_BCC_W         = &H0E02001F???   ' // PROP_TAG(PT_UNICODE,            0x0E02)
%PR_DISPLAY_BCC_A         = &H0E02001E???   ' // PROP_TAG(PT_STRING8,            0x0E02)
%PR_DISPLAY_CC            = &H0E03001E???   ' // PROP_TAG(PT_TSTRING,            0x0E03)
%PR_DISPLAY_CC_W          = &H0E03001F???   ' // PROP_TAG(PT_UNICODE,            0x0E03)
%PR_DISPLAY_CC_A          = &H0E03001E???   ' // PROP_TAG(PT_STRING8,            0x0E03)
%PR_DISPLAY_TO            = &H0E04001E???   ' // PROP_TAG(PT_TSTRING,            0x0E04)
%PR_DISPLAY_TO_W          = &H0E04001F???   ' // PROP_TAG(PT_UNICODE,            0x0E04)
%PR_DISPLAY_TO_A          = &H0E04001E???   ' // PROP_TAG(PT_STRING8,            0x0E04)
%PR_PARENT_DISPLAY        = &H0E05001E???   ' // PROP_TAG(PT_TSTRING,            0x0E05)
%PR_PARENT_DISPLAY_W      = &H0E05001F???   ' // PROP_TAG(PT_UNICODE,            0x0E05)
%PR_PARENT_DISPLAY_A      = &H0E05001E???   ' // PROP_TAG(PT_STRING8,            0x0E05)
%PR_MESSAGE_DELIVERY_TIME = &H0E060040???   ' // PROP_TAG(PT_SYSTIME,            0x0E06)
%PR_MESSAGE_FLAGS         = &H0E070003???   ' // PROP_TAG(PT_LONG,               0x0E07)
%PR_MESSAGE_SIZE          = &H0E080003???   ' // PROP_TAG(PT_LONG,               0x0E08)
%PR_PARENT_ENTRYID        = &H0E090102???   ' // PROP_TAG(PT_BINARY,             0x0E09)
%PR_SENTMAIL_ENTRYID      = &H0E0A0102???   ' // PROP_TAG(PT_BINARY,             0x0E0A)
%PR_CORRELATE             = &H0E0C000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E0C)
%PR_CORRELATE_MTSID       = &H0E0D0102???   ' // PROP_TAG(PT_BINARY,             0x0E0D)
%PR_DISCRETE_VALUES       = &H0E0E000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E0E)
%PR_RESPONSIBILITY        = &H0E0F000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E0F)
%PR_SPOOLER_STATUS        = &H0E100003???   ' // PROP_TAG(PT_LONG,               0x0E10)
%PR_TRANSPORT_STATUS      = &H0E110003???   ' // PROP_TAG(PT_LONG,               0x0E11)
%PR_MESSAGE_RECIPIENTS    = &H0E12000D???   ' // PROP_TAG(PT_OBJECT,             0x0E12)
%PR_MESSAGE_ATTACHMENTS   = &H0E13000D???   ' // PROP_TAG(PT_OBJECT,             0x0E13)
%PR_SUBMIT_FLAGS          = &H0E140003???   ' // PROP_TAG(PT_LONG,               0x0E14)
%PR_RECIPIENT_STATUS      = &H0E150003???   ' // PROP_TAG(PT_LONG,               0x0E15)
%PR_TRANSPORT_KEY         = &H0E160003???   ' // PROP_TAG(PT_LONG,               0x0E16)
%PR_MSG_STATUS            = &H0E170003???   ' // PROP_TAG(PT_LONG,               0x0E17)
%PR_MESSAGE_DOWNLOAD_TIME = &H0E180003???   ' // PROP_TAG(PT_LONG,               0x0E18)
%PR_CREATION_VERSION      = &H0E190014???   ' // PROP_TAG(PT_I8,                 0x0E19)
%PR_MODIFY_VERSION        = &H0E1A0014???   ' // PROP_TAG(PT_I8,                 0x0E1A)
%PR_HASATTACH             = &H0E1B000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E1B)
%PR_BODY_CRC              = &H0E1C0003???   ' // PROP_TAG(PT_LONG,               0x0E1C)
%PR_NORMALIZED_SUBJECT    = &H0E1D001E???   ' // PROP_TAG(PT_TSTRING,            0x0E1D)
%PR_NORMALIZED_SUBJECT_W  = &H0E1D001F???   ' // PROP_TAG(PT_UNICODE,            0x0E1D)
%PR_NORMALIZED_SUBJECT_A  = &H0E1D001E???   ' // PROP_TAG(PT_STRING8,            0x0E1D)
%PR_RTF_IN_SYNC           = &H0E1F000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E1F)
%PR_ATTACH_SIZE           = &H0E200003???   ' // PROP_TAG(PT_LONG,               0x0E20)
%PR_ATTACH_NUM            = &H0E210003???   ' // PROP_TAG(PT_LONG,               0x0E21)
%PR_PREPROCESS            = &H0E22000B???   ' // PROP_TAG(PT_BOOLEAN,            0x0E22)

'/* PR_ORIGINAL_DISPLAY_TO, _CC, and _BCC moved to transmittible range 03/09/95 */

%PR_ORIGINATING_MTA_CERTIFICATE = &H0E250102???   ' // PROP_TAG(PT_BINARY,             0x0E25)
%PR_PROOF_OF_SUBMISSION         = &H0E260102???   ' // PROP_TAG(PT_BINARY,             0x0E26)

'/*
' * The range of non-message and non-recipient property IDs (0x3000 - 0x3FFF) is
' * further broken down into ranges to make assigning new property IDs easier.
' *
' *   From   To      Kind of property
' *   --------------------------------
' *   3000   32FF   MAPI_defined common property
' *   3200   33FF   MAPI_defined form property
' *   3400   35FF   MAPI_defined message store property
' *   3600   36FF   MAPI_defined Folder or AB Container property
' *   3700   38FF   MAPI_defined attachment property
' *   3900   39FF   MAPI_defined address book property
' *   3A00   3BFF   MAPI_defined mailuser property
' *   3C00   3CFF   MAPI_defined DistList property
' *   3D00   3DFF   MAPI_defined Profile Section property
' *   3E00   3EFF   MAPI_defined Status property
' *   3F00   3FFF   MAPI_defined display table property
' */

'/*
' *   Properties common to numerous MAPI objects.
' *
' *   Those properties that can appear on messages are in the
' *   non-transmittable range for messages. They start at the high
' *   end of that range and work down.
' *
' *   Properties that never appear on messages are defined in the common
' *   property range (see above).
' */

'/*
' * properties that are common to multiple objects (including message objects)
' * -- these ids are in the non-transmittable range
' */

%PR_ENTRYID           = &H0FFF0102???   ' // PROP_TAG(PT_BINARY,             0x0FFF)
%PR_OBJECT_TYPE       = &H0FFE0003???   ' // PROP_TAG(PT_LONG,               0x0FFE)
%PR_ICON              = &H0FFD0102???   ' // PROP_TAG(PT_BINARY,             0x0FFD)
%PR_MINI_ICON         = &H0FFC0102???   ' // PROP_TAG(PT_BINARY,             0x0FFC)
%PR_STORE_ENTRYID     = &H0FFB0102???   ' // PROP_TAG(PT_BINARY,             0x0FFB)
%PR_STORE_RECORD_KEY  = &H0FFA0102???   ' // PROP_TAG(PT_BINARY,             0x0FFA)
%PR_RECORD_KEY        = &H0FF90102???   ' // PROP_TAG(PT_BINARY,             0x0FF9)
%PR_MAPPING_SIGNATURE = &H0FF80102???   ' // PROP_TAG(PT_BINARY,             0x0FF8)
%PR_ACCESS_LEVEL      = &H0FF70003???   ' // PROP_TAG(PT_LONG,               0x0FF7)
%PR_INSTANCE_KEY      = &H0FF60102???   ' // PROP_TAG(PT_BINARY,             0x0FF6)
%PR_ROW_TYPE          = &H0FF50003???   ' // PROP_TAG(PT_LONG,               0x0FF5)
%PR_ACCESS            = &H0FF40003???   ' // PROP_TAG(PT_LONG,               0x0FF4)

'/*
' * properties that are common to multiple objects (usually not including message objects)
' * -- these ids are in the transmittable range
' */

%PR_ROWID                  = &H30000003???   ' // PROP_TAG(PT_LONG,               0x3000)
%PR_DISPLAY_NAME           = &H3001001E???   ' // PROP_TAG(PT_TSTRING,            0x3001)
%PR_DISPLAY_NAME_W         = &H3001001F???   ' // PROP_TAG(PT_UNICODE,            0x3001)
%PR_DISPLAY_NAME_A         = &H3001001E???   ' // PROP_TAG(PT_STRING8,            0x3001)
%PR_ADDRTYPE               = &H3002001E???   ' // PROP_TAG(PT_TSTRING,            0x3002)
%PR_ADDRTYPE_W             = &H3002001F???   ' // PROP_TAG(PT_UNICODE,            0x3002)
%PR_ADDRTYPE_A             = &H3002001E???   ' // PROP_TAG(PT_STRING8,            0x3002)
%PR_EMAIL_ADDRESS          = &H3003001E???   ' // PROP_TAG(PT_TSTRING,            0x3003)
%PR_EMAIL_ADDRESS_W        = &H3003001F???   ' // PROP_TAG(PT_UNICODE,            0x3003)
%PR_EMAIL_ADDRESS_A        = &H3003001E???   ' // PROP_TAG(PT_STRING8,            0x3003)
%PR_COMMENT                = &H3004001E???   ' // PROP_TAG(PT_TSTRING,            0x3004)
%PR_COMMENT_W              = &H3004001F???   ' // PROP_TAG(PT_UNICODE,            0x3004)
%PR_COMMENT_A              = &H3004001E???   ' // PROP_TAG(PT_STRING8,            0x3004)
%PR_DEPTH                  = &H30050003???   ' // PROP_TAG(PT_LONG,               0x3005)
%PR_PROVIDER_DISPLAY       = &H3006001E???   ' // PROP_TAG(PT_TSTRING,            0x3006)
%PR_PROVIDER_DISPLAY_W     = &H3006001F???   ' // PROP_TAG(PT_UNICODE,            0x3006)
%PR_PROVIDER_DISPLAY_A     = &H3006001E???   ' // PROP_TAG(PT_STRING8,            0x3006)
%PR_CREATION_TIME          = &H30070040???   ' // PROP_TAG(PT_SYSTIME,            0x3007)
%PR_LAST_MODIFICATION_TIME = &H30080040???   ' // PROP_TAG(PT_SYSTIME,            0x3008)
%PR_RESOURCE_FLAGS         = &H30090003???   ' // PROP_TAG(PT_LONG,               0x3009)
%PR_PROVIDER_DLL_NAME      = &H300A001E???   ' // PROP_TAG(PT_TSTRING,            0x300A)
%PR_PROVIDER_DLL_NAME_W    = &H300A001F???   ' // PROP_TAG(PT_UNICODE,            0x300A)
%PR_PROVIDER_DLL_NAME_A    = &H300A001E???   ' // PROP_TAG(PT_STRING8,            0x300A)
%PR_SEARCH_KEY             = &H300B0102???   ' // PROP_TAG(PT_BINARY,             0x300B)
%PR_PROVIDER_UID           = &H300C0102???   ' // PROP_TAG(PT_BINARY,             0x300C)
%PR_PROVIDER_ORDINAL       = &H300D0003???   ' // PROP_TAG(PT_LONG,               0x300D)

'/*
' *  MAPI Form properties
' */
%PR_FORM_VERSION          = &H3301001E???   ' // PROP_TAG(PT_TSTRING,            0x3301)
%PR_FORM_VERSION_W        = &H3301001F???   ' // PROP_TAG(PT_UNICODE,            0x3301)
%PR_FORM_VERSION_A        = &H3301001E???   ' // PROP_TAG(PT_STRING8,            0x3301)
%PR_FORM_CLSID            = &H33020048???   ' // PROP_TAG(PT_CLSID,              0x3302)
%PR_FORM_CONTACT_NAME     = &H3303001E???   ' // PROP_TAG(PT_TSTRING,            0x3303)
%PR_FORM_CONTACT_NAME_W   = &H3303001F???   ' // PROP_TAG(PT_UNICODE,            0x3303)
%PR_FORM_CONTACT_NAME_A   = &H3303001E???   ' // PROP_TAG(PT_STRING8,            0x3303)
%PR_FORM_CATEGORY         = &H3304001E???   ' // PROP_TAG(PT_TSTRING,            0x3304)
%PR_FORM_CATEGORY_W       = &H3304001F???   ' // PROP_TAG(PT_UNICODE,            0x3304)
%PR_FORM_CATEGORY_A       = &H3304001E???   ' // PROP_TAG(PT_STRING8,            0x3304)
%PR_FORM_CATEGORY_SUB     = &H3305001E???   ' // PROP_TAG(PT_TSTRING,            0x3305)
%PR_FORM_CATEGORY_SUB_W   = &H3305001F???   ' // PROP_TAG(PT_UNICODE,            0x3305)
%PR_FORM_CATEGORY_SUB_A   = &H3305001E???   ' // PROP_TAG(PT_STRING8,            0x3305)
%PR_FORM_HOST_MAP         = &H33061003???   ' // PROP_TAG(PT_MV_LONG,            0x3306)
%PR_FORM_HIDDEN           = &H3307000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3307)
%PR_FORM_DESIGNER_NAME    = &H3308001E???   ' // PROP_TAG(PT_TSTRING,            0x3308)
%PR_FORM_DESIGNER_NAME_W  = &H3308001F???   ' // PROP_TAG(PT_UNICODE,            0x3308)
%PR_FORM_DESIGNER_NAME_A  = &H3308001E???   ' // PROP_TAG(PT_STRING8,            0x3308)
%PR_FORM_DESIGNER_GUID    = &H33090048???   ' // PROP_TAG(PT_CLSID,              0x3309)
%PR_FORM_MESSAGE_BEHAVIOR = &H330A0003???   ' // PROP_TAG(PT_LONG,               0x330A)

'/*
' *   Message store properties
' */

%PR_DEFAULT_STORE              = &H3400000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3400)
%PR_STORE_SUPPORT_MASK         = &H340D0003???   ' // PROP_TAG(PT_LONG,               0x340D)
%PR_STORE_STATE                = &H340E0003???   ' // PROP_TAG(PT_LONG,               0x340E)

%PR_IPM_SUBTREE_SEARCH_KEY     = &H34100102???   ' // PROP_TAG(PT_BINARY,             0x3410)
%PR_IPM_OUTBOX_SEARCH_KEY      = &H34110102???   ' // PROP_TAG(PT_BINARY,             0x3411)
%PR_IPM_WASTEBASKET_SEARCH_KEY = &H34120102???   ' // PROP_TAG(PT_BINARY,             0x3412)
%PR_IPM_SENTMAIL_SEARCH_KEY    = &H34130102???   ' // PROP_TAG(PT_BINARY,             0x3413)
%PR_MDB_PROVIDER               = &H34140102???   ' // PROP_TAG(PT_BINARY,             0x3414)
%PR_RECEIVE_FOLDER_SETTINGS    = &H3415000D???   ' // PROP_TAG(PT_OBJECT,             0x3415)

%PR_VALID_FOLDER_MASK          = &H35DF0003???   ' // PROP_TAG(PT_LONG,               0x35DF)
%PR_IPM_SUBTREE_ENTRYID        = &H35E00102???   ' // PROP_TAG(PT_BINARY,             0x35E0)

%PR_IPM_OUTBOX_ENTRYID         = &H35E20102???   ' // PROP_TAG(PT_BINARY,             0x35E2)
%PR_IPM_WASTEBASKET_ENTRYID    = &H35E30102???   ' // PROP_TAG(PT_BINARY,             0x35E3)
%PR_IPM_SENTMAIL_ENTRYID       = &H35E40102???   ' // PROP_TAG(PT_BINARY,             0x35E4)
%PR_VIEWS_ENTRYID              = &H35E50102???   ' // PROP_TAG(PT_BINARY,             0x35E5)
%PR_COMMON_VIEWS_ENTRYID       = &H35E60102???   ' // PROP_TAG(PT_BINARY,             0x35E6)
%PR_FINDER_ENTRYID             = &H35E70102???   ' // PROP_TAG(PT_BINARY,             0x35E7)

'/* Proptags 0x35E8-0x35FF reserved for folders "guaranteed" by PR_VALID_FOLDER_MASK */


'/*
' *   Folder and AB Container properties
' */

%PR_CONTAINER_FLAGS            = &H36000003???   ' // PROP_TAG(PT_LONG,               0x3600)
%PR_FOLDER_TYPE                = &H36010003???   ' // PROP_TAG(PT_LONG,               0x3601)
%PR_CONTENT_COUNT              = &H36020003???   ' // PROP_TAG(PT_LONG,               0x3602)
%PR_CONTENT_UNREAD             = &H36030003???   ' // PROP_TAG(PT_LONG,               0x3603)
%PR_CREATE_TEMPLATES           = &H3604000D???   ' // PROP_TAG(PT_OBJECT,             0x3604)
%PR_DETAILS_TABLE              = &H3605000D???   ' // PROP_TAG(PT_OBJECT,             0x3605)
%PR_SEARCH                     = &H3607000D???   ' // PROP_TAG(PT_OBJECT,             0x3607)
%PR_SELECTABLE                 = &H3609000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3609)
%PR_SUBFOLDERS                 = &H360A000B???   ' // PROP_TAG(PT_BOOLEAN,            0x360A)
%PR_STATUS                     = &H360B0003???   ' // PROP_TAG(PT_LONG,               0x360B)
%PR_ANR                        = &H360C001E???   ' // PROP_TAG(PT_TSTRING,            0x360C)
%PR_ANR_W                      = &H360C001F???   ' // PROP_TAG(PT_UNICODE,            0x360C)
%PR_ANR_A                      = &H360C001E???   ' // PROP_TAG(PT_STRING8,            0x360C)
%PR_CONTENTS_SORT_ORDER        = &H360D1003???   ' // PROP_TAG(PT_MV_LONG,            0x360D)
%PR_CONTAINER_HIERARCHY        = &H360E000D???   ' // PROP_TAG(PT_OBJECT,             0x360E)
%PR_CONTAINER_CONTENTS         = &H360F000D???   ' // PROP_TAG(PT_OBJECT,             0x360F)
%PR_FOLDER_ASSOCIATED_CONTENTS = &H3610000D???   ' // PROP_TAG(PT_OBJECT,             0x3610)
%PR_DEF_CREATE_DL              = &H36110102???   ' // PROP_TAG(PT_BINARY,             0x3611)
%PR_DEF_CREATE_MAILUSER        = &H36120102???   ' // PROP_TAG(PT_BINARY,             0x3612)
%PR_CONTAINER_CLASS            = &H3613001E???   ' // PROP_TAG(PT_TSTRING,            0x3613)
%PR_CONTAINER_CLASS_W          = &H3613001F???   ' // PROP_TAG(PT_UNICODE,            0x3613)
%PR_CONTAINER_CLASS_A          = &H3613001E???   ' // PROP_TAG(PT_STRING8,            0x3613)
%PR_CONTAINER_MODIFY_VERSION   = &H36140014???   ' // PROP_TAG(PT_I8,                 0x3614)
%PR_AB_PROVIDER_ID             = &H36150102???   ' // PROP_TAG(PT_BINARY,             0x3615)
%PR_DEFAULT_VIEW_ENTRYID       = &H36160102???   ' // PROP_TAG(PT_BINARY,             0x3616)
%PR_ASSOC_CONTENT_COUNT        = &H36170003???   ' // PROP_TAG(PT_LONG,               0x3617)

'/* Reserved 0x36C0-0x36FF */

'/*
' *   Attachment properties
' */

%PR_ATTACHMENT_X400_PARAMETERS = &H37000102???   ' // PROP_TAG(PT_BINARY,             0x3700)
%PR_ATTACH_DATA_OBJ            = &H3701000D???   ' // PROP_TAG(PT_OBJECT,             0x3701)
%PR_ATTACH_DATA_BIN            = &H37010102???   ' // PROP_TAG(PT_BINARY,             0x3701)
%PR_ATTACH_ENCODING            = &H37020102???   ' // PROP_TAG(PT_BINARY,             0x3702)
%PR_ATTACH_EXTENSION           = &H3703001E???   ' // PROP_TAG(PT_TSTRING,            0x3703)
%PR_ATTACH_EXTENSION_W         = &H3703001F???   ' // PROP_TAG(PT_UNICODE,            0x3703)
%PR_ATTACH_EXTENSION_A         = &H3703001E???   ' // PROP_TAG(PT_STRING8,            0x3703)
%PR_ATTACH_FILENAME            = &H3704001E???   ' // PROP_TAG(PT_TSTRING,            0x3704)
%PR_ATTACH_FILENAME_W          = &H3704001F???   ' // PROP_TAG(PT_UNICODE,            0x3704)
%PR_ATTACH_FILENAME_A          = &H3704001E???   ' // PROP_TAG(PT_STRING8,            0x3704)
%PR_ATTACH_METHOD              = &H37050003???   ' // PROP_TAG(PT_LONG,               0x3705)
%PR_ATTACH_LONG_FILENAME       = &H3707001E???   ' // PROP_TAG(PT_TSTRING,            0x3707)
%PR_ATTACH_LONG_FILENAME_W     = &H3707001F???   ' // PROP_TAG(PT_UNICODE,            0x3707)
%PR_ATTACH_LONG_FILENAME_A     = &H3707001E???   ' // PROP_TAG(PT_STRING8,            0x3707)
%PR_ATTACH_PATHNAME            = &H3708001E???   ' // PROP_TAG(PT_TSTRING,            0x3708)
%PR_ATTACH_PATHNAME_W          = &H3708001F???   ' // PROP_TAG(PT_UNICODE,            0x3708)
%PR_ATTACH_PATHNAME_A          = &H3708001E???   ' // PROP_TAG(PT_STRING8,            0x3708)
%PR_ATTACH_RENDERING           = &H37090102???   ' // PROP_TAG(PT_BINARY,             0x3709)
%PR_ATTACH_TAG                 = &H370A0102???   ' // PROP_TAG(PT_BINARY,             0x370A)
%PR_RENDERING_POSITION         = &H370B0003???   ' // PROP_TAG(PT_LONG,               0x370B)
%PR_ATTACH_TRANSPORT_NAME      = &H370C001E???   ' // PROP_TAG(PT_TSTRING,            0x370C)
%PR_ATTACH_TRANSPORT_NAME_W    = &H370C001F???   ' // PROP_TAG(PT_UNICODE,            0x370C)
%PR_ATTACH_TRANSPORT_NAME_A    = &H370C001E???   ' // PROP_TAG(PT_STRING8,            0x370C)
%PR_ATTACH_LONG_PATHNAME       = &H370D001E???   ' // PROP_TAG(PT_TSTRING,            0x370D)
%PR_ATTACH_LONG_PATHNAME_W     = &H370D001F???   ' // PROP_TAG(PT_UNICODE,            0x370D)
%PR_ATTACH_LONG_PATHNAME_A     = &H370D001E???   ' // PROP_TAG(PT_STRING8,            0x370D)
%PR_ATTACH_MIME_TAG            = &H370E001E???   ' // PROP_TAG(PT_TSTRING,            0x370E)
%PR_ATTACH_MIME_TAG_W          = &H370E001F???   ' // PROP_TAG(PT_UNICODE,            0x370E)
%PR_ATTACH_MIME_TAG_A          = &H370E001E???   ' // PROP_TAG(PT_STRING8,            0x370E)
%PR_ATTACH_ADDITIONAL_INFO     = &H370F0102???   ' // PROP_TAG(PT_BINARY,             0x370F)

'/*
' *  AB Object properties
' */

%PR_DISPLAY_TYPE       = &H39000003???   ' // PROP_TAG(PT_LONG,               0x3900)
%PR_TEMPLATEID         = &H39020102???   ' // PROP_TAG(PT_BINARY,             0x3902)
%PR_PRIMARY_CAPABILITY = &H39040102???   ' // PROP_TAG(PT_BINARY,             0x3904)

'/*
' *   Mail user properties
' */

%PR_7BIT_DISPLAY_NAME                    = &H39FF001F???   ' // PROP_TAG(PT_STRING8,            0x39FF)
%PR_ACCOUNT                              = &H3A00001E???   ' // PROP_TAG(PT_TSTRING,            0x3A00)
%PR_ACCOUNT_W                            = &H3A00001F???   ' // PROP_TAG(PT_UNICODE,            0x3A00)
%PR_ACCOUNT_A                            = &H3A00001E???   ' // PROP_TAG(PT_STRING8,            0x3A00)
%PR_ALTERNATE_RECIPIENT                  = &H3A010102???   ' // PROP_TAG(PT_BINARY,             0x3A01)
%PR_CALLBACK_TELEPHONE_NUMBER            = &H3A02001E???   ' // PROP_TAG(PT_TSTRING,            0x3A02)
%PR_CALLBACK_TELEPHONE_NUMBER_W          = &H3A02001F???   ' // PROP_TAG(PT_UNICODE,            0x3A02)
%PR_CALLBACK_TELEPHONE_NUMBER_A          = &H3A02001E???   ' // PROP_TAG(PT_STRING8,            0x3A02)
%PR_CONVERSION_PROHIBITED                = &H3A03000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3A03)
%PR_DISCLOSE_RECIPIENTS                  = &H3A04000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3A04)
%PR_GENERATION                           = &H3A05001E???   ' // PROP_TAG(PT_TSTRING,            0x3A05)
%PR_GENERATION_W                         = &H3A05001F???   ' // PROP_TAG(PT_UNICODE,            0x3A05)
%PR_GENERATION_A                         = &H3A05001E???   ' // PROP_TAG(PT_STRING8,            0x3A05)
%PR_GIVEN_NAME                           = &H3A06001E???   ' // PROP_TAG(PT_TSTRING,            0x3A06)
%PR_GIVEN_NAME_W                         = &H3A06001F???   ' // PROP_TAG(PT_UNICODE,            0x3A06)
%PR_GIVEN_NAME_A                         = &H3A06001E???   ' // PROP_TAG(PT_STRING8,            0x3A06)
%PR_GOVERNMENT_ID_NUMBER                 = &H3A07001E???   ' // PROP_TAG(PT_TSTRING,            0x3A07)
%PR_GOVERNMENT_ID_NUMBER_W               = &H3A07001F???   ' // PROP_TAG(PT_UNICODE,            0x3A07)
%PR_GOVERNMENT_ID_NUMBER_A               = &H3A07001E???   ' // PROP_TAG(PT_STRING8,            0x3A07)
%PR_BUSINESS_TELEPHONE_NUMBER            = &H3A08001E???   ' // PROP_TAG(PT_TSTRING,            0x3A08)
%PR_BUSINESS_TELEPHONE_NUMBER_W          = &H3A08001F???   ' // PROP_TAG(PT_UNICODE,            0x3A08)
%PR_BUSINESS_TELEPHONE_NUMBER_A          = &H3A08001E???   ' // PROP_TAG(PT_STRING8,            0x3A08)
%PR_OFFICE_TELEPHONE_NUMBER              = &H3A08001E???   ' // PR_BUSINESS_TELEPHONE_NUMBER
%PR_OFFICE_TELEPHONE_NUMBER_W            = &H3A08001F???   ' // PR_BUSINESS_TELEPHONE_NUMBER_W
%PR_OFFICE_TELEPHONE_NUMBER_A            = &H3A08001E???   ' // PR_BUSINESS_TELEPHONE_NUMBER_A
%PR_HOME_TELEPHONE_NUMBER                = &H3A09001E???   ' // PROP_TAG(PT_TSTRING,            0x3A09)
%PR_HOME_TELEPHONE_NUMBER_W              = &H3A09001F???   ' // PROP_TAG(PT_UNICODE,            0x3A09)
%PR_HOME_TELEPHONE_NUMBER_A              = &H3A09001E???   ' // PROP_TAG(PT_STRING8,            0x3A09)
%PR_INITIALS                             = &H3A0A001E???   ' // PROP_TAG(PT_TSTRING,            0x3A0A)
%PR_INITIALS_W                           = &H3A0A001F???   ' // PROP_TAG(PT_UNICODE,            0x3A0A)
%PR_INITIALS_A                           = &H3A0A001E???   ' // PROP_TAG(PT_STRING8,            0x3A0A)
%PR_KEYWORD                              = &H3A0B001E???   ' // PROP_TAG(PT_TSTRING,            0x3A0B)
%PR_KEYWORD_W                            = &H3A0B001F???   ' // PROP_TAG(PT_UNICODE,            0x3A0B)
%PR_KEYWORD_A                            = &H3A0B001E???   ' // PROP_TAG(PT_STRING8,            0x3A0B)
%PR_LANGUAGE                             = &H3A0C001E???   ' // PROP_TAG(PT_TSTRING,            0x3A0C)
%PR_LANGUAGE_W                           = &H3A0C001F???   ' // PROP_TAG(PT_UNICODE,            0x3A0C)
%PR_LANGUAGE_A                           = &H3A0C001E???   ' // PROP_TAG(PT_STRING8,            0x3A0C)
%PR_LOCATION                             = &H3A0D001E???   ' // PROP_TAG(PT_TSTRING,            0x3A0D)
%PR_LOCATION_W                           = &H3A0D001F???   ' // PROP_TAG(PT_UNICODE,            0x3A0D)
%PR_LOCATION_A                           = &H3A0D001E???   ' // PROP_TAG(PT_STRING8,            0x3A0D)
%PR_MAIL_PERMISSION                      = &H3A0E000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3A0E)
%PR_MHS_COMMON_NAME                      = &H3A0F001E???   ' // PROP_TAG(PT_TSTRING,            0x3A0F)
%PR_MHS_COMMON_NAME_W                    = &H3A0F001F???   ' // PROP_TAG(PT_UNICODE,            0x3A0F)
%PR_MHS_COMMON_NAME_A                    = &H3A0F001E???   ' // PROP_TAG(PT_STRING8,            0x3A0F)
%PR_ORGANIZATIONAL_ID_NUMBER             = &H3A10001E???   ' // PROP_TAG(PT_TSTRING,            0x3A10)
%PR_ORGANIZATIONAL_ID_NUMBER_W           = &H3A10001F???   ' // PROP_TAG(PT_UNICODE,            0x3A10)
%PR_ORGANIZATIONAL_ID_NUMBER_A           = &H3A10001E???   ' // PROP_TAG(PT_STRING8,            0x3A10)
%PR_SURNAME                              = &H3A11001E???   ' // PROP_TAG(PT_TSTRING,            0x3A11)
%PR_SURNAME_W                            = &H3A11001F???   ' // PROP_TAG(PT_UNICODE,            0x3A11)
%PR_SURNAME_A                            = &H3A11001E???   ' // PROP_TAG(PT_STRING8,            0x3A11)
%PR_ORIGINAL_ENTRYID                     = &H3A120102???   ' // PROP_TAG(PT_BINARY,             0x3A12)
%PR_ORIGINAL_DISPLAY_NAME                = &H3A13001E???   ' // PROP_TAG(PT_TSTRING,            0x3A13)
%PR_ORIGINAL_DISPLAY_NAME_W              = &H3A13001F???   ' // PROP_TAG(PT_UNICODE,            0x3A13)
%PR_ORIGINAL_DISPLAY_NAME_A              = &H3A13001E???   ' // PROP_TAG(PT_STRING8,            0x3A13)
%PR_ORIGINAL_SEARCH_KEY                  = &H3A140102???   ' // PROP_TAG(PT_BINARY,             0x3A14)
%PR_POSTAL_ADDRESS                       = &H3A15001E???   ' // PROP_TAG(PT_TSTRING,            0x3A15)
%PR_POSTAL_ADDRESS_W                     = &H3A15001F???   ' // PROP_TAG(PT_UNICODE,            0x3A15)
%PR_POSTAL_ADDRESS_A                     = &H3A15001E???   ' // PROP_TAG(PT_STRING8,            0x3A15)
%PR_COMPANY_NAME                         = &H3A16001E???   ' // PROP_TAG(PT_TSTRING,            0x3A16)
%PR_COMPANY_NAME_W                       = &H3A16001F???   ' // PROP_TAG(PT_UNICODE,            0x3A16)
%PR_COMPANY_NAME_A                       = &H3A16001E???   ' // PROP_TAG(PT_STRING8,            0x3A16)
%PR_TITLE                                = &H3A17001E???   ' // PROP_TAG(PT_TSTRING,            0x3A17)
%PR_TITLE_W                              = &H3A17001F???   ' // PROP_TAG(PT_UNICODE,            0x3A17)
%PR_TITLE_A                              = &H3A17001E???   ' // PROP_TAG(PT_STRING8,            0x3A17)
%PR_DEPARTMENT_NAME                      = &H3A18001E???   ' // PROP_TAG(PT_TSTRING,            0x3A18)
%PR_DEPARTMENT_NAME_W                    = &H3A18001F???   ' // PROP_TAG(PT_UNICODE,            0x3A18)
%PR_DEPARTMENT_NAME_A                    = &H3A18001E???   ' // PROP_TAG(PT_STRING8,            0x3A18)
%PR_OFFICE_LOCATION                      = &H3A19001E???   ' // PROP_TAG(PT_TSTRING,            0x3A19)
%PR_OFFICE_LOCATION_W                    = &H3A19001F???   ' // PROP_TAG(PT_UNICODE,            0x3A19)
%PR_OFFICE_LOCATION_A                    = &H3A19001E???   ' // PROP_TAG(PT_STRING8,            0x3A19)
%PR_PRIMARY_TELEPHONE_NUMBER             = &H3A1A001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1A)
%PR_PRIMARY_TELEPHONE_NUMBER_W           = &H3A1A001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1A)
%PR_PRIMARY_TELEPHONE_NUMBER_A           = &H3A1A001E???   ' // PROP_TAG(PT_STRING8,            0x3A1A)
%PR_BUSINESS2_TELEPHONE_NUMBER           = &H3A1B001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1B)
%PR_BUSINESS2_TELEPHONE_NUMBER_W         = &H3A1B001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1B)
%PR_BUSINESS2_TELEPHONE_NUMBER_A         = &H3A1B001E???   ' // PROP_TAG(PT_STRING8,            0x3A1B)
%PR_OFFICE2_TELEPHONE_NUMBER             = &H3A1B001E???   ' // PR_BUSINESS2_TELEPHONE_NUMBER
%PR_OFFICE2_TELEPHONE_NUMBER_W           = &H3A1B001F???   ' // PR_BUSINESS2_TELEPHONE_NUMBER_W
%PR_OFFICE2_TELEPHONE_NUMBER_A           = &H3A1B001E???   ' // PR_BUSINESS2_TELEPHONE_NUMBER_A
%PR_MOBILE_TELEPHONE_NUMBER              = &H3A1C001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1C)
%PR_MOBILE_TELEPHONE_NUMBER_W            = &H3A1C001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1C)
%PR_MOBILE_TELEPHONE_NUMBER_A            = &H3A1C001E???   ' // PROP_TAG(PT_STRING8,            0x3A1C)
%PR_CELLULAR_TELEPHONE_NUMBER            = %PR_MOBILE_TELEPHONE_NUMBER     ' // PR_MOBILE_TELEPHONE_NUMBER
%PR_CELLULAR_TELEPHONE_NUMBER_W          = %PR_MOBILE_TELEPHONE_NUMBER_W   ' // PR_MOBILE_TELEPHONE_NUMBER_W
%PR_CELLULAR_TELEPHONE_NUMBER_A          = %PR_MOBILE_TELEPHONE_NUMBER_A   ' // PR_MOBILE_TELEPHONE_NUMBER_A
%PR_RADIO_TELEPHONE_NUMBER               = &H3A1D001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1D)
%PR_RADIO_TELEPHONE_NUMBER_W             = &H3A1D001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1D)
%PR_RADIO_TELEPHONE_NUMBER_A             = &H3A1D001E???   ' // PROP_TAG(PT_STRING8,            0x3A1D)
%PR_CAR_TELEPHONE_NUMBER                 = &H3A1E001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1E)
%PR_CAR_TELEPHONE_NUMBER_W               = &H3A1E001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1E)
%PR_CAR_TELEPHONE_NUMBER_A               = &H3A1E001E???   ' // PROP_TAG(PT_STRING8,            0x3A1E)
%PR_OTHER_TELEPHONE_NUMBER               = &H3A1F001E???   ' // PROP_TAG(PT_TSTRING,            0x3A1F)
%PR_OTHER_TELEPHONE_NUMBER_W             = &H3A1F001F???   ' // PROP_TAG(PT_UNICODE,            0x3A1F)
%PR_OTHER_TELEPHONE_NUMBER_A             = &H3A1F001E???   ' // PROP_TAG(PT_STRING8,            0x3A1F)
%PR_TRANSMITTABLE_DISPLAY_NAME           = &H3A20001E???   ' // PROP_TAG(PT_TSTRING,            0x3A20)
%PR_TRANSMITTABLE_DISPLAY_NAME_W         = &H3A20001F???   ' // PROP_TAG(PT_UNICODE,            0x3A20)
%PR_TRANSMITTABLE_DISPLAY_NAME_A         = &H3A20001E???   ' // PROP_TAG(PT_STRING8,            0x3A20)
%PR_PAGER_TELEPHONE_NUMBER               = &H3A21001E???   ' // PROP_TAG(PT_TSTRING,            0x3A21)
%PR_PAGER_TELEPHONE_NUMBER_W             = &H3A21001F???   ' // PROP_TAG(PT_UNICODE,            0x3A21)
%PR_PAGER_TELEPHONE_NUMBER_A             = &H3A21001E???   ' // PROP_TAG(PT_STRING8,            0x3A21)
%PR_BEEPER_TELEPHONE_NUMBER              = %PR_PAGER_TELEPHONE_NUMBER
%PR_BEEPER_TELEPHONE_NUMBER_W            = %PR_PAGER_TELEPHONE_NUMBER_W
%PR_BEEPER_TELEPHONE_NUMBER_A            = %PR_PAGER_TELEPHONE_NUMBER_A
%PR_USER_CERTIFICATE                     = &H3A220102???   ' // PROP_TAG(PT_BINARY,             0x3A22)
%PR_PRIMARY_FAX_NUMBER                   = &H3A23001E???   ' // PROP_TAG(PT_TSTRING,            0x3A23)
%PR_PRIMARY_FAX_NUMBER_W                 = &H3A23001F???   ' // PROP_TAG(PT_UNICODE,            0x3A23)
%PR_PRIMARY_FAX_NUMBER_A                 = &H3A23001E???   ' // PROP_TAG(PT_STRING8,            0x3A23)
%PR_BUSINESS_FAX_NUMBER                  = &H3A24001E???   ' // PROP_TAG(PT_TSTRING,            0x3A24)
%PR_BUSINESS_FAX_NUMBER_W                = &H3A24001F???   ' // PROP_TAG(PT_UNICODE,            0x3A24)
%PR_BUSINESS_FAX_NUMBER_A                = &H3A24001E???   ' // PROP_TAG(PT_STRING8,            0x3A24)
%PR_HOME_FAX_NUMBER                      = &H3A25001E???   ' // PROP_TAG(PT_TSTRING,            0x3A25)
%PR_HOME_FAX_NUMBER_W                    = &H3A25001F???   ' // PROP_TAG(PT_UNICODE,            0x3A25)
%PR_HOME_FAX_NUMBER_A                    = &H3A25001E???   ' // PROP_TAG(PT_STRING8,            0x3A25)
%PR_COUNTRY                              = &H3A26001E???   ' // PROP_TAG(PT_TSTRING,            0x3A26)
%PR_COUNTRY_W                            = &H3A26001F???   ' // PROP_TAG(PT_UNICODE,            0x3A26)
%PR_COUNTRY_A                            = &H3A26001E???   ' // PROP_TAG(PT_STRING8,            0x3A26)
%PR_BUSINESS_ADDRESS_COUNTRY             = &H3A26001E???   ' // PR_COUNTRY
%PR_BUSINESS_ADDRESS_COUNTRY_W           = &H3A26001F???   ' // PR_COUNTRY_W
%PR_BUSINESS_ADDRESS_COUNTRY_A           = &H3A26001E???   ' // PR_COUNTRY_A

%PR_LOCALITY                             = &H3A27001E???   ' // PROP_TAG(PT_TSTRING,            0x3A27)
%PR_LOCALITY_W                           = &H3A27001F???   ' // PROP_TAG(PT_UNICODE,            0x3A27)
%PR_LOCALITY_A                           = &H3A27001E???   ' // PROP_TAG(PT_STRING8,            0x3A27)
%PR_BUSINESS_ADDRESS_CITY                = &H3A27001E???   ' // PR_LOCALITY
%PR_BUSINESS_ADDRESS_CITY_W              = &H3A27001F???   ' // PR_LOCALITY_W
%PR_BUSINESS_ADDRESS_CITY_A              = &H3A27001E???   ' // PR_LOCALITY_A

%PR_STATE_OR_PROVINCE                    = &H3A28001E???   ' // PROP_TAG(PT_TSTRING,            0x3A28)
%PR_STATE_OR_PROVINCE_W                  = &H3A28001F???   ' // PROP_TAG(PT_UNICODE,            0x3A28)
%PR_STATE_OR_PROVINCE_A                  = &H3A28001E???   ' // PROP_TAG(PT_STRING8,            0x3A28)
%PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE   = %PR_STATE_OR_PROVINCE     ' // PR_STATE_OR_PROVINCE
%PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_W = %PR_STATE_OR_PROVINCE_W   ' // PR_STATE_OR_PROVINCE_W
%PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE_A = %PR_STATE_OR_PROVINCE_A   ' // PR_STATE_OR_PROVINCE_A

%PR_STREET_ADDRESS                       = &H3A29001E???   ' // PROP_TAG(PT_TSTRING,            0x3A29)
%PR_STREET_ADDRESS_W                     = &H3A29001F???   ' // PROP_TAG(PT_UNICODE,            0x3A29)
%PR_STREET_ADDRESS_A                     = &H3A29001E???   ' // PROP_TAG(PT_STRING8,            0x3A29)
%PR_BUSINESS_ADDRESS_STREET              = %PR_STREET_ADDRESS     ' // PR_STREET_ADDRESS
%PR_BUSINESS_ADDRESS_STREET_W            = %PR_STREET_ADDRESS_W   ' // PR_STREET_ADDRESS_W
%PR_BUSINESS_ADDRESS_STREET_A            = %PR_STREET_ADDRESS_A   ' // PR_STREET_ADDRESS_A

%PR_POSTAL_CODE                          = &H3A2A001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2A)
%PR_POSTAL_CODE_W                        = &H3A2A001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2A)
%PR_POSTAL_CODE_A                        = &H3A2A001E???   ' // PROP_TAG(PT_STRING8,            0x3A2A)
%PR_BUSINESS_ADDRESS_POSTAL_CODE         = %PR_POSTAL_CODE     ' // PR_POSTAL_CODE
%PR_BUSINESS_ADDRESS_POSTAL_CODE_W       = %PR_POSTAL_CODE_W   ' // PR_POSTAL_CODE_W
%PR_BUSINESS_ADDRESS_POSTAL_CODE_A       = %PR_POSTAL_CODE_A   ' // PR_POSTAL_CODE_A

%PR_POST_OFFICE_BOX                      = &H3A2B001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2B)
%PR_POST_OFFICE_BOX_W                    = &H3A2B001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2B)
%PR_POST_OFFICE_BOX_A                    = &H3A2B001E???   ' // PROP_TAG(PT_STRING8,            0x3A2B)
%PR_BUSINESS_ADDRESS_POST_OFFICE_BOX     = %PR_POST_OFFICE_BOX     ' // PR_POST_OFFICE_BOX
%PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_W   = %PR_POST_OFFICE_BOX_W   ' // PR_POST_OFFICE_BOX_W
%PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_A   = %PR_POST_OFFICE_BOX_A   ' // PR_POST_OFFICE_BOX_A

%PR_TELEX_NUMBER                         = &H3A2C001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2C)
%PR_TELEX_NUMBER_W                       = &H3A2C001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2C)
%PR_TELEX_NUMBER_A                       = &H3A2C001E???   ' // PROP_TAG(PT_STRING8,            0x3A2C)
%PR_ISDN_NUMBER                          = &H3A2D001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2D)
%PR_ISDN_NUMBER_W                        = &H3A2D001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2D)
%PR_ISDN_NUMBER_A                        = &H3A2D001E???   ' // PROP_TAG(PT_STRING8,            0x3A2D)
%PR_ASSISTANT_TELEPHONE_NUMBER           = &H3A2E001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2E)
%PR_ASSISTANT_TELEPHONE_NUMBER_W         = &H3A2E001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2E)
%PR_ASSISTANT_TELEPHONE_NUMBER_A         = &H3A2E001E???   ' // PROP_TAG(PT_STRING8,            0x3A2E)
%PR_HOME2_TELEPHONE_NUMBER               = &H3A2F001E???   ' // PROP_TAG(PT_TSTRING,            0x3A2F)
%PR_HOME2_TELEPHONE_NUMBER_W             = &H3A2F001F???   ' // PROP_TAG(PT_UNICODE,            0x3A2F)
%PR_HOME2_TELEPHONE_NUMBER_A             = &H3A2F001E???   ' // PROP_TAG(PT_STRING8,            0x3A2F)
%PR_ASSISTANT                            = &H3A30001E???   ' // PROP_TAG(PT_TSTRING,            0x3A30)
%PR_ASSISTANT_W                          = &H3A30001F???   ' // PROP_TAG(PT_UNICODE,            0x3A30)
%PR_ASSISTANT_A                          = &H3A30001E???   ' // PROP_TAG(PT_STRING8,            0x3A30)
%PR_SEND_RICH_INFO                       = &H3A40000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3A40)

%PR_WEDDING_ANNIVERSARY                  = &H3A410040???   ' // PROP_TAG(PT_SYSTIME,            0x3A41)
%PR_BIRTHDAY                             = &H3A420040???   ' // PROP_TAG(PT_SYSTIME,            0x3A42)

%PR_HOBBIES                              = &H3A43001E???   ' // PROP_TAG(PT_TSTRING,            0x3A43)
%PR_HOBBIES_W                            = &H3A43001F???   ' // PROP_TAG(PT_UNICODE,            0x3A43)
%PR_HOBBIES_A                            = &H3A43001E???   ' // PROP_TAG(PT_STRING8,            0x3A43)

%PR_MIDDLE_NAME                          = &H3A44001E???   ' // PROP_TAG(PT_TSTRING,            0x3A44)
%PR_MIDDLE_NAME_W                        = &H3A44001F???   ' // PROP_TAG(PT_UNICODE,            0x3A44)
%PR_MIDDLE_NAME_A                        = &H3A44001E???   ' // PROP_TAG(PT_STRING8,            0x3A44)

%PR_DISPLAY_NAME_PREFIX                  = &H3A45001E???   ' // PROP_TAG(PT_TSTRING,            0x3A45)
%PR_DISPLAY_NAME_PREFIX_W                = &H3A45001F???   ' // PROP_TAG(PT_UNICODE,            0x3A45)
%PR_DISPLAY_NAME_PREFIX_A                = &H3A45001E???   ' // PROP_TAG(PT_STRING8,            0x3A45)

%PR_PROFESSION                           = &H3A46001E???   ' // PROP_TAG(PT_TSTRING,            0x3A46)
%PR_PROFESSION_W                         = &H3A46001F???   ' // PROP_TAG(PT_UNICODE,            0x3A46)
%PR_PROFESSION_A                         = &H3A46001E???   ' // PROP_TAG(PT_STRING8,            0x3A46)

%PR_PREFERRED_BY_NAME                    = &H3A47001E???   ' // PROP_TAG(PT_TSTRING,            0x3A47)
%PR_PREFERRED_BY_NAME_W                  = &H3A47001F???   ' // PROP_TAG(PT_UNICODE,            0x3A47)
%PR_PREFERRED_BY_NAME_A                  = &H3A47001E???   ' // PROP_TAG(PT_STRING8,            0x3A47)

%PR_SPOUSE_NAME                          = &H3A48001E???   ' // PROP_TAG(PT_TSTRING,            0x3A48)
%PR_SPOUSE_NAME_W                        = &H3A48001F???   ' // PROP_TAG(PT_UNICODE,            0x3A48)
%PR_SPOUSE_NAME_A                        = &H3A48001E???   ' // PROP_TAG(PT_STRING8,            0x3A48)

%PR_COMPUTER_NETWORK_NAME                = &H3A49001E???   ' // PROP_TAG(PT_TSTRING,            0x3A49)
%PR_COMPUTER_NETWORK_NAME_W              = &H3A49001F???   ' // PROP_TAG(PT_UNICODE,            0x3A49)
%PR_COMPUTER_NETWORK_NAME_A              = &H3A49001E???   ' // PROP_TAG(PT_STRING8,            0x3A49)

%PR_CUSTOMER_ID                          = &H3A4A001E???   ' // PROP_TAG(PT_TSTRING,            0x3A4A)
%PR_CUSTOMER_ID_W                        = &H3A4A001F???   ' // PROP_TAG(PT_UNICODE,            0x3A4A)
%PR_CUSTOMER_ID_A                        = &H3A4A001E???   ' // PROP_TAG(PT_STRING8,            0x3A4A)

%PR_TTYTDD_PHONE_NUMBER                  = &H3A4B001E???   ' // PROP_TAG(PT_TSTRING,            0x3A4B)
%PR_TTYTDD_PHONE_NUMBER_W                = &H3A4B001F???   ' // PROP_TAG(PT_UNICODE,            0x3A4B)
%PR_TTYTDD_PHONE_NUMBER_A                = &H3A4B001E???   ' // PROP_TAG(PT_STRING8,            0x3A4B)

%PR_FTP_SITE                             = &H3A4C001E???   ' // PROP_TAG(PT_TSTRING,            0x3A4C)
%PR_FTP_SITE_W                           = &H3A4C001F???   ' // PROP_TAG(PT_UNICODE,            0x3A4C)
%PR_FTP_SITE_A                           = &H3A4C001E???   ' // PROP_TAG(PT_STRING8,            0x3A4C)

%PR_GENDER                               = &H3A4D0002???   ' // PROP_TAG(PT_SHORT,              0x3A4D)

%PR_MANAGER_NAME                         = &H3A4E001E???   ' // PROP_TAG(PT_TSTRING,            0x3A4E)
%PR_MANAGER_NAME_W                       = &H3A4E001F???   ' // PROP_TAG(PT_UNICODE,            0x3A4E)
%PR_MANAGER_NAME_A                       = &H3A4E001E???   ' // PROP_TAG(PT_STRING8,            0x3A4E)

%PR_NICKNAME                             = &H3A4F001E???   ' // PROP_TAG(PT_TSTRING,            0x3A4F)
%PR_NICKNAME_W                           = &H3A4F001F???   ' // PROP_TAG(PT_UNICODE,            0x3A4F)
%PR_NICKNAME_A                           = &H3A4F001E???   ' // PROP_TAG(PT_STRING8,            0x3A4F)

%PR_PERSONAL_HOME_PAGE                   = &H3A50001E???   ' // PROP_TAG(PT_TSTRING,            0x3A50)
%PR_PERSONAL_HOME_PAGE_W                 = &H3A50001F???   ' // PROP_TAG(PT_UNICODE,            0x3A50)
%PR_PERSONAL_HOME_PAGE_A                 = &H3A50001E???   ' // PROP_TAG(PT_STRING8,            0x3A50)

%PR_BUSINESS_HOME_PAGE                   = &H3A51001E???   ' // PROP_TAG(PT_TSTRING,            0x3A51)
%PR_BUSINESS_HOME_PAGE_W                 = &H3A51001F???   ' // PROP_TAG(PT_UNICODE,            0x3A51)
%PR_BUSINESS_HOME_PAGE_A                 = &H3A51001E???   ' // PROP_TAG(PT_STRING8,            0x3A51)

%PR_CONTACT_VERSION                      = &H3A520048???   ' // PROP_TAG(PT_CLSID,              0x3A52)
%PR_CONTACT_ENTRYIDS                     = &H3A531102???   ' // PROP_TAG(PT_MV_BINARY,          0x3A53)

%PR_CONTACT_ADDRTYPES                    = &H3A54101E???   ' // PROP_TAG(PT_MV_TSTRING,         0x3A54)
%PR_CONTACT_ADDRTYPES_W                  = &H3A54101F???   ' // PROP_TAG(PT_MV_UNICODE,         0x3A54)
%PR_CONTACT_ADDRTYPES_A                  = &H3A54101E???   ' // PROP_TAG(PT_MV_STRING8,         0x3A54)

%PR_CONTACT_DEFAULT_ADDRESS_INDEX        = &H3A550003???   ' // PROP_TAG(PT_LONG,               0x3A55)

%PR_CONTACT_EMAIL_ADDRESSES              = &H3A56101E???   ' // PROP_TAG(PT_MV_TSTRING,         0x3A56)
%PR_CONTACT_EMAIL_ADDRESSES_W            = &H3A56101F???   ' // PROP_TAG(PT_MV_UNICODE,         0x3A56)
%PR_CONTACT_EMAIL_ADDRESSES_A            = &H3A56101E???   ' // PROP_TAG(PT_MV_STRING8,         0x3A56)

%PR_COMPANY_MAIN_PHONE_NUMBER            = &H3A57001E???   ' // PROP_TAG(PT_TSTRING,            0x3A57)
%PR_COMPANY_MAIN_PHONE_NUMBER_W          = &H3A57001F???   ' // PROP_TAG(PT_UNICODE,            0x3A57)
%PR_COMPANY_MAIN_PHONE_NUMBER_A          = &H3A57001E???   ' // PROP_TAG(PT_STRING8,            0x3A57)

%PR_CHILDRENS_NAMES                      = &H3A58101E???   ' // PROP_TAG(PT_MV_TSTRING,         0x3A58)
%PR_CHILDRENS_NAMES_W                    = &H3A58101F???   ' // PROP_TAG(PT_MV_UNICODE,         0x3A58)
%PR_CHILDRENS_NAMES_A                    = &H3A58101E???   ' // PROP_TAG(PT_MV_STRING8,         0x3A58)

%PR_HOME_ADDRESS_CITY                    = &H3A59001E???   ' // PROP_TAG(PT_TSTRING,            0x3A59)
%PR_HOME_ADDRESS_CITY_W                  = &H3A59001F???   ' // PROP_TAG(PT_UNICODE,            0x3A59)
%PR_HOME_ADDRESS_CITY_A                  = &H3A59001E???   ' // PROP_TAG(PT_STRING8,            0x3A59)

%PR_HOME_ADDRESS_COUNTRY                 = &H3A5A001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5A)
%PR_HOME_ADDRESS_COUNTRY_W               = &H3A5A001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5A)
%PR_HOME_ADDRESS_COUNTRY_A               = &H3A5A001E???   ' // PROP_TAG(PT_STRING8,            0x3A5A)

%PR_HOME_ADDRESS_POSTAL_CODE             = &H3A5B001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5B)
%PR_HOME_ADDRESS_POSTAL_CODE_W           = &H3A5B001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5B)
%PR_HOME_ADDRESS_POSTAL_CODE_A           = &H3A5B001E???   ' // PROP_TAG(PT_STRING8,            0x3A5B)

%PR_HOME_ADDRESS_STATE_OR_PROVINCE       = &H3A5C001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5C)
%PR_HOME_ADDRESS_STATE_OR_PROVINCE_W     = &H3A5C001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5C)
%PR_HOME_ADDRESS_STATE_OR_PROVINCE_A     = &H3A5C001E???   ' // PROP_TAG(PT_STRING8,            0x3A5C)

%PR_HOME_ADDRESS_STREET                  = &H3A5D001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5D)
%PR_HOME_ADDRESS_STREET_W                = &H3A5D001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5D)
%PR_HOME_ADDRESS_STREET_A                = &H3A5D001E???   ' // PROP_TAG(PT_STRING8,            0x3A5D)

%PR_HOME_ADDRESS_POST_OFFICE_BOX         = &H3A5E001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5E)
%PR_HOME_ADDRESS_POST_OFFICE_BOX_W       = &H3A5E001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5E)
%PR_HOME_ADDRESS_POST_OFFICE_BOX_A       = &H3A5E001E???   ' // PROP_TAG(PT_STRING8,            0x3A5E)

%PR_OTHER_ADDRESS_CITY                   = &H3A5F001E???   ' // PROP_TAG(PT_TSTRING,            0x3A5F)
%PR_OTHER_ADDRESS_CITY_W                 = &H3A5F001F???   ' // PROP_TAG(PT_UNICODE,            0x3A5F)
%PR_OTHER_ADDRESS_CITY_A                 = &H3A5F001E???   ' // PROP_TAG(PT_STRING8,            0x3A5F)

%PR_OTHER_ADDRESS_COUNTRY                = &H3A60001E???   ' // PROP_TAG(PT_TSTRING,            0x3A60)
%PR_OTHER_ADDRESS_COUNTRY_W              = &H3A60001F???   ' // PROP_TAG(PT_UNICODE,            0x3A60)
%PR_OTHER_ADDRESS_COUNTRY_A              = &H3A60001E???   ' // PROP_TAG(PT_STRING8,            0x3A60)

%PR_OTHER_ADDRESS_POSTAL_CODE            = &H3A61001E???   ' // PROP_TAG(PT_TSTRING,            0x3A61)
%PR_OTHER_ADDRESS_POSTAL_CODE_W          = &H3A61001F???   ' // PROP_TAG(PT_UNICODE,            0x3A61)
%PR_OTHER_ADDRESS_POSTAL_CODE_A          = &H3A61001E???   ' // PROP_TAG(PT_STRING8,            0x3A61)

%PR_OTHER_ADDRESS_STATE_OR_PROVINCE      = &H3A62001E???   ' // PROP_TAG(PT_TSTRING,            0x3A62)
%PR_OTHER_ADDRESS_STATE_OR_PROVINCE_W    = &H3A62001F???   ' // PROP_TAG(PT_UNICODE,            0x3A62)
%PR_OTHER_ADDRESS_STATE_OR_PROVINCE_A    = &H3A62001E???   ' // PROP_TAG(PT_STRING8,            0x3A62)

%PR_OTHER_ADDRESS_STREET                 = &H3A63001E???   ' // PROP_TAG(PT_TSTRING,            0x3A63)
%PR_OTHER_ADDRESS_STREET_W               = &H3A63001F???   ' // PROP_TAG(PT_UNICODE,            0x3A63)
%PR_OTHER_ADDRESS_STREET_A               = &H3A63001E???   ' // PROP_TAG(PT_STRING8,            0x3A63)

%PR_OTHER_ADDRESS_POST_OFFICE_BOX        = &H3A64001E???   ' // PROP_TAG(PT_TSTRING,            0x3A64)
%PR_OTHER_ADDRESS_POST_OFFICE_BOX_W      = &H3A64001F???   ' // PROP_TAG(PT_UNICODE,            0x3A64)
%PR_OTHER_ADDRESS_POST_OFFICE_BOX_A      = &H3A64001E???   ' // PROP_TAG(PT_STRING8,            0x3A64)

'/*
' *   Profile section properties
' */

%PR_STORE_PROVIDERS         = &H3D000102???   ' // PROP_TAG(PT_BINARY,             0x3D00)
%PR_AB_PROVIDERS            = &H3D010102???   ' // PROP_TAG(PT_BINARY,             0x3D01)
%PR_TRANSPORT_PROVIDERS     = &H3D020102???   ' // PROP_TAG(PT_BINARY,             0x3D02)

%PR_DEFAULT_PROFILE         = &H3D04000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3D04)
%PR_AB_SEARCH_PATH          = &H3D051102???   ' // PROP_TAG(PT_MV_BINARY,          0x3D05)
%PR_AB_DEFAULT_DIR          = &H3D060102???   ' // PROP_TAG(PT_BINARY,             0x3D06)
%PR_AB_DEFAULT_PAB          = &H3D070102???   ' // PROP_TAG(PT_BINARY,             0x3D07)

%PR_FILTERING_HOOKS         = &H3D080102???   ' // PROP_TAG(PT_BINARY,             0x3D08)
%PR_SERVICE_NAME            = &H3D09001E???   ' // PROP_TAG(PT_TSTRING,            0x3D09)
%PR_SERVICE_NAME_W          = &H3D09001F???   ' // PROP_TAG(PT_UNICODE,            0x3D09)
%PR_SERVICE_NAME_A          = &H3D09001E???   ' // PROP_TAG(PT_STRING8,            0x3D09)
%PR_SERVICE_DLL_NAME        = &H3D0A001E???   ' // PROP_TAG(PT_TSTRING,            0x3D0A)
%PR_SERVICE_DLL_NAME_W      = &H3D0A001F???   ' // PROP_TAG(PT_UNICODE,            0x3D0A)
%PR_SERVICE_DLL_NAME_A      = &H3D0A001E???   ' // PROP_TAG(PT_STRING8,            0x3D0A)
%PR_SERVICE_ENTRY_NAME      = &H3D0B001F???   ' // PROP_TAG(PT_STRING8,            0x3D0B)
%PR_SERVICE_UID             = &H3D0C0102???   ' // PROP_TAG(PT_BINARY,             0x3D0C)
%PR_SERVICE_EXTRA_UIDS      = &H3D0D0102???   ' // PROP_TAG(PT_BINARY,             0x3D0D)
%PR_SERVICES                = &H3D0E0102???   ' // PROP_TAG(PT_BINARY,             0x3D0E)
%PR_SERVICE_SUPPORT_FILES   = &H3D0F101E???   ' // PROP_TAG(PT_MV_TSTRING,         0x3D0F)
%PR_SERVICE_SUPPORT_FILES_W = &H3D0F101F???   ' // PROP_TAG(PT_MV_UNICODE,         0x3D0F)
%PR_SERVICE_SUPPORT_FILES_A = &H3D0F101E???   ' // PROP_TAG(PT_MV_STRING8,         0x3D0F)
%PR_SERVICE_DELETE_FILES    = &H3D10101E???   ' // PROP_TAG(PT_MV_TSTRING,         0x3D10)
%PR_SERVICE_DELETE_FILES_W  = &H3D10101F???   ' // PROP_TAG(PT_MV_UNICODE,         0x3D10)
%PR_SERVICE_DELETE_FILES_A  = &H3D10101E???   ' // PROP_TAG(PT_MV_STRING8,         0x3D10)
%PR_AB_SEARCH_PATH_UPDATE   = &H3D110102???   ' // PROP_TAG(PT_BINARY,             0x3D11)
%PR_PROFILE_NAME            = &H3D12001E???   ' // PROP_TAG(PT_TSTRING,            0x3D12)
%PR_PROFILE_NAME_A          = &H3D12001E???   ' // PROP_TAG(PT_STRING8,            0x3D12)
%PR_PROFILE_NAME_W          = &H3D12001F???   ' // PROP_TAG(PT_UNICODE,            0x3D12)

'/*
' *   Status object properties
' */

%PR_IDENTITY_DISPLAY              = &H3E00001E???   ' // PROP_TAG(PT_TSTRING,            0x3E00)
%PR_IDENTITY_DISPLAY_W            = &H3E00001F???   ' // PROP_TAG(PT_UNICODE,            0x3E00)
%PR_IDENTITY_DISPLAY_A            = &H3E00001E???   ' // PROP_TAG(PT_STRING8,            0x3E00)
%PR_IDENTITY_ENTRYID              = &H3E010102???   ' // PROP_TAG(PT_BINARY,             0x3E01)
%PR_RESOURCE_METHODS              = &H3E020003???   ' // PROP_TAG(PT_LONG,               0x3E02)
%PR_RESOURCE_TYPE                 = &H3E030003???   ' // PROP_TAG(PT_LONG,               0x3E03)
%PR_STATUS_CODE                   = &H3E040003???   ' // PROP_TAG(PT_LONG,               0x3E04)
%PR_IDENTITY_SEARCH_KEY           = &H3E050102???   ' // PROP_TAG(PT_BINARY,             0x3E05)
%PR_OWN_STORE_ENTRYID             = &H3E060102???   ' // PROP_TAG(PT_BINARY,             0x3E06)
%PR_RESOURCE_PATH                 = &H3E07001E???   ' // PROP_TAG(PT_TSTRING,            0x3E07)
%PR_RESOURCE_PATH_W               = &H3E07001F???   ' // PROP_TAG(PT_UNICODE,            0x3E07)
%PR_RESOURCE_PATH_A               = &H3E07001E???   ' // PROP_TAG(PT_STRING8,            0x3E07)
%PR_STATUS_STRING                 = &H3E08001E???   ' // PROP_TAG(PT_TSTRING,            0x3E08)
%PR_STATUS_STRING_W               = &H3E08001F???   ' // PROP_TAG(PT_UNICODE,            0x3E08)
%PR_STATUS_STRING_A               = &H3E08001E???   ' // PROP_TAG(PT_STRING8,            0x3E08)
%PR_X400_DEFERRED_DELIVERY_CANCEL = &H3E09000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3E09)
%PR_HEADER_FOLDER_ENTRYID         = &H3E0A0102???   ' // PROP_TAG(PT_BINARY,             0x3E0A)
%PR_REMOTE_PROGRESS               = &H3E0B0003???   ' // PROP_TAG(PT_LONG,               0x3E0B)
%PR_REMOTE_PROGRESS_TEXT          = &H3E0C001E???   ' // PROP_TAG(PT_TSTRING,            0x3E0C)
%PR_REMOTE_PROGRESS_TEXT_W        = &H3E0C001F???   ' // PROP_TAG(PT_UNICODE,            0x3E0C)
%PR_REMOTE_PROGRESS_TEXT_A        = &H3E0C001E???   ' // PROP_TAG(PT_STRING8,            0x3E0C)
%PR_REMOTE_VALIDATE_OK            = &H3E0D000B???   ' // PROP_TAG(PT_BOOLEAN,            0x3E0D)

'/*
' * Display table properties
' */

%PR_CONTROL_FLAGS        = &H3F000003???   ' // PROP_TAG(PT_LONG,               0x3F00)
%PR_CONTROL_STRUCTURE    = &H3F010102???   ' // PROP_TAG(PT_BINARY,             0x3F01)
%PR_CONTROL_TYPE         = &H3F020003???   ' // PROP_TAG(PT_LONG,               0x3F02)
%PR_DELTAX               = &H3F030003???   ' // PROP_TAG(PT_LONG,               0x3F03)
%PR_DELTAY               = &H3F040003???   ' // PROP_TAG(PT_LONG,               0x3F04)
%PR_XPOS                 = &H3F050003???   ' // PROP_TAG(PT_LONG,               0x3F05)
%PR_YPOS                 = &H3F060003???   ' // PROP_TAG(PT_LONG,               0x3F06)
%PR_CONTROL_ID           = &H3F070102???   ' // PROP_TAG(PT_BINARY,             0x3F07)
%PR_INITIAL_DETAILS_PANE = &H3F080003???   ' // PROP_TAG(PT_LONG,               0x3F08)

'/*
' * Secure property id range
' */

%PROP_ID_SECURE_MIN = &H67F0???
%PROP_ID_SECURE_MAX = &H67FF???
