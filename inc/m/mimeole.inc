' ########################################################################################
' Microsoft Windows
' File: mimeole.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MIMEOLE
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft MIMEOLE Type Library 1.0
' Library GUID: {E4B28371-83B0-11D0-8259-00C04FD85AB4}
' ########################################################################################

' ########################################################################################
' Deprecated. Do not use.
' Outlook Express and Windows Mail have been replaced with Windows Live.
' ########################################################################################

'//--------------------------------------------------------------------------------
'// MIMEOLE.H
'//--------------------------------------------------------------------------------
'// (C) Copyright 1995-1998 Microsoft Corporation.  All Rights Reserved.
'//
'// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
'// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
'// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'// PARTICULAR PURPOSE.
'//--------------------------------------------------------------------------------

#INCLUDE THIS ONCE
%MIMEOLE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "propidl.inc"

'// --------------------------------------------------------------------------------
'// GUIDS
'// --------------------------------------------------------------------------------
$LIBID_MIMEOLE              = GUID$("{E4B28371-83B0-11D0-8259-00C04FD85AB4}")
$CLSID_IMimeHtmlProtocol    = GUID$("{05300401-BCBC-11D0-85E3-00C04FD85AB4}")
$IID_IMimeEnumAddressTypes  = GUID$("{C5588354-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeWebDocument       = GUID$("{EE519F11-851A-11D0-825C-00C04FD85AB4}")
$IID_IUnicodeStream         = GUID$("{FD853CEF-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeAddressTable      = GUID$("{C558834A-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeAddressTableW     = GUID$("{11C8D742-0FB4-11D3-A01E-00A0C90C9BB6}")
$IID_IMimeAddressInfo       = GUID$("{C558834B-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeEnumHeaderRows    = GUID$("{C558834D-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeInlineSupport     = GUID$("{C558834E-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeEnumMessageParts  = GUID$("{C5588350-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeInternational   = GUID$("{FD853CD9-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeInternational     = GUID$("{C5588349-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeBody            = GUID$("{FD853CDB-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeBody              = GUID$("{C558834C-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeBodyW           = GUID$("{2F38042A-D02F-11d2-A004-00A0C90C9BB6}")
$IID_IMimeBodyW             = GUID$("{2F38042B-D02F-11D2-A004-00A0C90C9BB6}")
$CLSID_IMimeMessageParts    = GUID$("{FD853CDC-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeMessageParts      = GUID$("{C558834F-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeAllocator       = GUID$("{FD853CDD-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeAllocator         = GUID$("{C5588351-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeSecurity        = GUID$("{FD853CDE-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeSecurity          = GUID$("{C5588353-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IVirtualStream       = GUID$("{FD853CDF-7F86-11D0-8252-00C04FD85AB4}")
$IID_IVirtualStream         = GUID$("{C5588359-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeHeaderTable     = GUID$("{FD853CE0-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeHeaderTable       = GUID$("{FD853CD1-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimePropertySet     = GUID$("{FD853CE1-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimePropertySet       = GUID$("{FD853CD3-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeMessageTree     = GUID$("{FD853CE2-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeMessageTree       = GUID$("{FD853CD4-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeMessage         = GUID$("{FD853CE3-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeMessage           = GUID$("{FD853CD5-7F86-11D0-8252-00C04FD85AB4}")
$CLSID_IMimeMessageW        = GUID$("{F90ADFEE-D01F-11d2-A004-00A0C90C9BB6}")
$IID_IMimeMessageW          = GUID$("{F90ADFEF-D01F-11D2-A004-00A0C90C9BB6}")
$CLSID_IMimePropertySchema  = GUID$("{FD853CED-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimePropertySchema    = GUID$("{FD853CEC-7F86-11D0-8252-00C04FD85AB4}")
$IID_IMimeEnumProperties    = GUID$("{FD853CEE-7F86-11D0-8252-00C04FD85AB4}")
$IID_IPersistMime           = GUID$("{DE4AD8DA-555F-11D1-8DD0-00C04FB951F9}")
$IID_IMimeMessageCallback   = GUID$("{761AA641-7BDA-11D1-8AA9-00C04FB951F3}")
'#if (_WIN32_OE >= 0x0500)
$CLSID_MimeEdit             = GUID$("{1C82EAD9-508E-11D1-8DCF-00C04FB951F9}")
$CMDSETID_MimeEdit          = GUID$("{1C82EADA-508E-11D1-8DCF-00C04FB951F9}")
$CMDSETID_MimeEditHost      = GUID$("{1C82EADB-508E-11D1-8DCF-00C04FB951F9}")
$IID_IHashTable             = GUID$("{64577981-86D7-11D1-BDFC-00C04FA31009}")
$CLSID_IHashTable           = GUID$("{64577982-86D7-11D1-BDFC-00C04FA31009}")
$CLSID_IFontCache           = GUID$("{B0D17FC2-7BC4-11D1-BDFA-00C04FA31009}")
$IID_IFontCache             = GUID$("{B0D17FC4-7BC4-11D1-BDFA-00C04FA31009}")
$IID_IFontCacheNotify       = GUID$("{B0D17FC5-7BC4-11D1-BDFA-00C04FA31009}")
$CLSID_IMimeObjResolver     = GUID$("{35461E30-C488-11D1-960E-00C04FBD7C09}")
$IID_IMimeObjResolver       = GUID$("{FECEAFFD-C441-11D1-960E-00C04FBD7C09}")
$IID_IMimeEditTag           = GUID$("{70183210-7B36-11D2-8C12-00C04FA31009}")
$IID_IMimeEditTagCollection = GUID$("{D09EE528-7B38-11D2-8C12-00C04FA31009}")
$IID_IMimeSecurityCallback  = GUID$("{ba715ae0-a740-11d2-8b22-0080c76b34c6}")
$CLSID_INewsgroupHelp       = GUID$("{7A0CC021-2939-4379-AA82-12AECC3538F6}")
$IID_INewsgroupHelp         = GUID$("{0887C54F-4F42-4937-81DA-BC9C97494627}")
$IID_IHashTableW            = GUID$("{71d6b38c-7a15-42c6-af84-b2a5dc242ceb}")
$CLSID_IHashTableW          = GUID$("{71d6b38d-7a15-42c6-af84-b2a5dc242ceb}")
$IID_IMimeEditTagCollection = GUID$("{d09ee528-7b38-11d2-8c12-00c04fa31009}")
$CLSID_PreviewEmail         = GUID$("{b9815375-5d7f-4ce2-9245-c9d4da436930}")
$CLSID_PreviewHtml          = GUID$("{f8b8412b-dea3-4130-b36c-5e8be73106ac}")
$CLSID_PreviewMime          = GUID$("{92dbad9f-5025-49b0-9078-2d78f935e341}")
$CLSID_PreviewUrl           = GUID$("{BFD468D2-D0A0-4bdc-878C-E69C2F5B435D}")
'#endif //_WIN32_OE

'// --------------------------------------------------------------------------------
'// Errors
'// Also defined in msoeapi.inc
'// --------------------------------------------------------------------------------

#IF NOT %DEF(%FACILITY_INTERNET)
%FACILITY_INTERNET = 12
#ENDIF

#IF NOT %DEF(%HR_E_DEFINED)
%HR_E_DEFINED = 1
MACRO HR_E(n) = MAKE_SCODE(%SEVERITY_ERROR, %FACILITY_INTERNET, n)
#ENDIF

#IF NOT %DEF(%HR_S_DEFINED)
%HR_S_DEFINED = 1
MACRO HR_S(n) = MAKE_SCODE(%SEVERITY_ERROR, %FACILITY_INTERNET, n)
#ENDIF

#IF NOT %DEF(%HR_CODE_DEFINED)
%HR_CODE_DEFINED = 1
MACRO HR_CODE(hr) = (hr AND &Hffff)
#ENDIF


'// --------------------------------------------------------------------------------
'// MIMEOLE Failure Return Values
'// --------------------------------------------------------------------------------
%MIME_E_REG_CREATE_KEY                         = &HFFFFCE01&   ' HR_E(0xCE01)
%MIME_E_REG_QUERY_INFO                         = &HFFFFCE02&   ' HR_E(0xCE02)
%MIME_E_INVALID_ENCTYPE                        = &HFFFFCE03&   ' HR_E(0xCE03)
%MIME_E_BOUNDARY_MISMATCH                      = &HFFFFCE04&   ' HR_E(0xCE04)
%MIME_E_NOT_FOUND                              = &HFFFFCE05&   ' HR_E(0xCE05)
%MIME_E_NO_DATA                                = &HFFFFCE05&   ' HR_E(0xCE05)
%MIME_E_BUFFER_TOO_SMALL                       = &HFFFFCE06&   ' HR_E(0xCE06)
%MIME_E_INVALID_ITEM_FLAGS                     = &HFFFFCE07&   ' HR_E(0xCE07)
%MIME_E_ONE_LINE_ITEM                          = &HFFFFCE08&   ' HR_E(0xCE08)
%MIME_E_INVALID_HANDLE                         = &HFFFFCE09&   ' HR_E(0xCE09)
%MIME_E_CHARSET_TRANSLATE                      = &HFFFFCE0A&   ' HR_E(0xCE0A)
%MIME_E_NOT_INITIALIZED                        = &HFFFFCE0B&   ' HR_E(0xCE0B)
%MIME_E_NO_MORE_ROWS                           = &HFFFFCE0C&   ' HR_E(0xCE0C)
%MIME_E_ALREADY_BOUND                          = &HFFFFCE0D&   ' HR_E(0xCE0D)
%MIME_E_CANT_RESET_ROOT                        = &HFFFFCE0E&   ' HR_E(0xCE0E)
%MIME_E_INSERT_NOT_ALLOWED                     = &HFFFFCE0F&   ' HR_E(0xCE0F)
%MIME_E_BAD_BODY_LOCATION                      = &HFFFFCE10&   ' HR_E(0xCE10)
%MIME_E_NOT_MULTIPART                          = &HFFFFCE11&   ' HR_E(0xCE11)
%MIME_E_NO_MULTIPART_BOUNDARY                  = &HFFFFCE12&   ' HR_E(0xCE12)
%MIME_E_CONVERT_NOT_NEEDED                     = &HFFFFCE13&   ' HR_E(0xCE13)
%MIME_E_CANT_MOVE_BODY                         = &HFFFFCE14&   ' HR_E(0xCE14)
%MIME_E_UNKNOWN_BODYTREE_VERSION               = &HFFFFCE15&   ' HR_E(0xCE15)
%MIME_E_NOTHING_TO_SAVE                        = &HFFFFCE16&   ' HR_E(0xCE16)
%MIME_E_NEED_SAVE_MESSAGE                      = &HFFFFCE17&   ' HR_E(0xCE17)
%MIME_E_NOTHING_TO_REVERT                      = &HFFFFCE18&   ' HR_E(0xCE18)
%MIME_E_MSG_SIZE_DIFF                          = &HFFFFCE19&   ' HR_E(0xCE19)
%MIME_E_CANT_RESET_PARENT                      = &HFFFFCE1A&   ' HR_E(0xCE1A)
%MIME_E_CORRUPT_CACHE_TREE                     = &HFFFFCE1B&   ' HR_E(0xCE1B)
%MIME_E_BODYTREE_OUT_OF_SYNC                   = &HFFFFCE1C&   ' HR_E(0xCE1C)
%MIME_E_INVALID_ENCODINGTYPE                   = &HFFFFCE1D&   ' HR_E(0xCE1D)
%MIME_E_MULTIPART_NO_DATA                      = &HFFFFCE1E&   ' HR_E(0xCE1E)
%MIME_E_INVALID_OPTION_VALUE                   = &HFFFFCE1F&   ' HR_E(0xCE1F)
%MIME_E_INVALID_OPTION_ID                      = &HFFFFCE20&   ' HR_E(0xCE20)
%MIME_E_INVALID_HEADER_NAME                    = &HFFFFCE21&   ' HR_E(0xCE21)
%MIME_E_NOT_BOUND                              = &HFFFFCE22&   ' HR_E(0xCE22)
%MIME_E_MAX_SIZE_TOO_SMALL                     = &HFFFFCE23&   ' HR_E(0xCE23)
%MIME_E_MULTIPART_HAS_CHILDREN                 = &HFFFFCE25&   ' HR_E(0xCE25)
%MIME_E_INVALID_PROP_FLAGS                     = &HFFFFCE26&   ' HR_E(0xCE26)
%MIME_E_INVALID_ADDRESS_TYPE                   = &HFFFFCE27&   ' HR_E(0xCE27)
%MIME_E_INVALID_OBJECT_IID                     = &HFFFFCE28&   ' HR_E(0xCE28)
%MIME_E_MLANG_DLL_NOT_FOUND                    = &HFFFFCE29&   ' HR_E(0xCE29)
%MIME_E_ROOT_NOT_EMPTY                         = &HFFFFCE2A&   ' HR_E(0xCE2A)
%MIME_E_MLANG_BAD_DLL                          = &HFFFFCE2B&   ' HR_E(0xCE2B)
%MIME_E_REG_OPEN_KEY                           = &HFFFFCE2C&   ' HR_E(0xCE2C)
%MIME_E_INVALID_INET_DATE                      = &HFFFFCE2D&   ' HR_E(0xCE2D)
%MIME_E_INVALID_BODYTYPE                       = &HFFFFCE2E&   ' HR_E(0xCE2E)
%MIME_E_INVALID_DELETE_TYPE                    = &HFFFFCE2F&   ' HR_E(0xCE2F)
%MIME_E_OPTION_HAS_NO_VALUE                    = &HFFFFCE30&   ' HR_E(0xCE30)
%MIME_E_INVALID_CHARSET_TYPE                   = &HFFFFCE31&   ' HR_E(0xCE31)
%MIME_E_VARTYPE_NO_CONVERT                     = &HFFFFCE32&   ' HR_E(0xCE32)
%MIME_E_INVALID_VARTYPE                        = &HFFFFCE33&   ' HR_E(0xCE33)
%MIME_E_NO_MORE_ADDRESS_TYPES                  = &HFFFFCE34&   ' HR_E(0xCE34)
%MIME_E_INVALID_ENCODING_TYPE                  = &HFFFFCE35&   ' HR_E(0xCE35)
%MIME_S_ILLEGAL_LINES_FOUND                    = &HFFFFCE36&   ' HR_S(0xCE36)
%MIME_S_MIME_VERSION                           = &HFFFFCE37&   ' HR_S(0xCE37)
%MIME_E_INVALID_TEXT_TYPE                      = &HFFFFCE38&   ' HR_E(0xCE38)
%MIME_E_READ_ONLY                              = &HFFFFCE39&   ' HR_E(0xCE39)
%MIME_S_INVALID_MESSAGE                        = &HFFFFCE3A&   ' HR_S(0xCE3A)
%MIME_S_CHARSET_CONFLICT                       = &HFFFFCE3B&   ' HR_S(0xCE3B)
%MIME_E_UNSUPPORTED_VARTYPE                    = &HFFFFCE3C&   ' HR_E(0xCE3C)
%MIME_S_NO_CHARSET_CONVERT                     = &HFFFFCE3D&   ' HR_S(0xCE3D)
%MIME_E_URL_NOTFOUND                           = &HFFFFCE3E&   ' HR_E(0xCE3E)
%MIME_E_BAD_TEXT_DATA                          = &HFFFFCE3F&   ' HR_E(0xCE3F)
%MIME_E_NO_SIGNER                              = &HFFFFCE40&   ' HR_S(0xCE40)

'// ---------------------------------------------------------------------------
'// MIMEOLE Security Error Return Values
'// ---------------------------------------------------------------------------
%MIME_E_SECURITY_NOTINIT                       = &HFFFFCEA0&   ' HR_E(0xCEA0)
%MIME_E_SECURITY_LOADCRYPT32                   = &HFFFFCEA1&   ' HR_E(0xCEA1)
%MIME_E_SECURITY_BADPROCADDR                   = &HFFFFCEA2&   ' HR_E(0xCEA2)
%MIME_E_SECURITY_NODEFAULT                     = &HFFFFCEB0&   ' HR_E(0xCEB0)
%MIME_E_SECURITY_NOOP                          = &HFFFFCEB1&   ' HR_E(0xCEB1)
%MIME_S_SECURITY_NOOP                          = &HFFFFCEB1&   ' HR_S(0xCEB1)
%MIME_S_SECURITY_NONE                          = &HFFFFCEB2&   ' HR_S(0xCEB2)
%MIME_S_SECURITY_ERROROCCURED                  = &HFFFFCEB3&   ' HR_S(0xCEB3)
%MIME_E_SECURITY_USERCHOICE                    = &HFFFFCEB4&   ' HR_E(0xCEB4)
%MIME_E_SECURITY_UNKMSGTYPE                    = &HFFFFCEB5&   ' HR_E(0xCEB5)
%MIME_E_SECURITY_BADMESSAGE                    = &HFFFFCEB6&   ' HR_E(0xCEB6)
%MIME_E_SECURITY_BADCONTENT                    = &HFFFFCEB7&   ' HR_E(0xCEB7)
%MIME_E_SECURITY_BADSECURETYPE                 = &HFFFFCEB8&   ' HR_E(0xCEB8)
%MIME_E_SECURITY_CLASSNOTSUPPORTED             = &HFFFFCEB9&   ' HR_E(0xCEB9)
%MIME_S_SECURITY_RECURSEONLY                   = &HFFFFCEBA&   ' HR_S(0xCEBA)
%MIME_E_SECURITY_BADSTORE                      = &HFFFFCED0&   ' HR_E(0xCED0)
%MIME_S_SECURITY_NOCERT                        = &HFFFFCED1&   ' HR_S(0xCED1)
%MIME_E_SECURITY_NOCERT                        = &HFFFFCED1&   ' HR_E(0xCED1)
%MIME_E_SECURITY_CERTERROR                     = &HFFFFCED2&   ' HR_E(0xCED2)
%MIME_S_SECURITY_CERTERROR                     = &HFFFFCED2&   ' HR_S(0xCED2)
%MIME_S_SECURITY_NODEFCERT                     = &HFFFFCED3&   ' HR_S(0xCED3)
%MIME_E_SECURITY_BADSIGNATURE                  = &HFFFFCEE0&   ' HR_E(0xCEE0)
%MIME_E_SECURITY_MULTSIGNERS                   = &HFFFFCEE1&   ' HR_E(0xCEE1)
%MIME_E_SECURITY_NOSIGNINGCERT                 = &HFFFFCEE2&   ' HR_E(0xCEE2)
%MIME_E_SECURITY_CANTDECRYPT                   = &HFFFFCEF0&   ' HR_E(0xCEF0)
%MIME_E_SECURITY_ENCRYPTNOSENDERCERT           = &HFFFFCEF1&   ' HR_E(0xCEF1)
%MIME_S_SECURITY_NOSENDERCERT                  = &HFFFFCEF2&   ' HR_S(0xCEF2)
%MIME_E_SECURITY_LABELACCESSDENIED             = &HFFFFCEF3&   ' HR_E(0xCEF3)
%MIME_E_SECURITY_LABELACCESSCANCELLED          = &HFFFFCEF4&   ' HR_E(0xCEF4)
%MIME_E_SECURITY_LABELCORRUPT                  = &HFFFFCEF5&   ' HR_E(0xCEF5)
%MIME_E_SECURITY_UIREQUIRED                    = &HFFFFCEF6&   ' HR_E(0xCEF6)
%MIME_E_SECURITY_RECEIPT_NOMATCHINGRECEIPTBODY = &HFFFFCEF7&   ' HR_E(0xCEF7)
%MIME_E_SECURITY_RECEIPT_MSGHASHMISMATCH       = &HFFFFCEF8&   ' HR_E(0xCEF8)
%MIME_E_SECURITY_RECEIPT_CANTDECODE            = &HFFFFCEF9&   ' HR_E(0xCEF9)
%MIME_E_SECURITY_RECEIPT_CANTFINDSENTITEM      = &HFFFFCEFA&   ' HR_E(0xCEFA)
%MIME_E_SECURITY_RECEIPT_CANTFINDORGMSG        = &HFFFFCEFB&   ' HR_E(0xCEFB)
%MIME_E_SECURITY_LABELUIREQUIRED               = &HFFFFCEFC&   ' HR_E(0xCEFC)
%MIME_S_RECEIPT_FROMMYSELF                     = &HFFFFCEFC&   ' HR_S(0xCEFC)
%MIME_E_SECURITY_NOTIMPLEMENTED                = &HFFFFCEFD&   ' HR_E(0xCEFD)

'#if (_WIN32_OE >= 0x0500)
'// --------------------------------------------------------------------------------
'// MIMEEDIT Failure Return Values
'// --------------------------------------------------------------------------------
%MIMEEDIT_E_UNEXPECTED                         = &H800C1700&   ' HR_E(0x1700)
%MIMEEDIT_E_DODEFAULT                          = &H800C1701&   ' HR_E(0x1701)
%MIMEEDIT_E_LOADLIBRARYFAILURE                 = &H800C1702&   ' HR_E(0x1702)
%MIMEEDIT_E_USERCANCEL                         = &H800C1703&   ' HR_E(0x1703)
%MIMEEDIT_E_CHARSETNOTFOUND                    = &H800C1704&   ' HR_E(0x1704)
%MIMEEDIT_E_ILLEGALBODYFORMAT                  = &H800C1705&   ' HR_E(0x1705)
%MIMEEDIT_E_CANNOTSAVEUNTILPARSECOMPLETE       = &H800C1706&   ' HR_E(0x1706)
%MIMEEDIT_E_CANNOTSAVEWHILESOURCEEDITING       = &H800C1707&   ' HR_E(0x1707)

'// --------------------------------------------------------------------------------
'// MIMEEDIT Success Return Values
'// --------------------------------------------------------------------------------
%MIMEEDIT_S_OPENFILE                           = &H000C1750&   ' HR_S(0x1750)
%MIMEEDIT_S_SAVEFILE                           = &H000C1751&   ' HR_S(0x1751)

'// --------------------------------------------------------------------------------
'// MIMEEDIT Warning Return Values
'// --------------------------------------------------------------------------------
%MIMEEDIT_W_DOWNLOADNOTCOMPLETE                = &H000C1760&   ' HR_S(0x1760)
%MIMEEDIT_W_BADURLSNOTATTACHED                 = &H000C1761&   ' HR_S(0x1761)

'#endif //_WIN32_OE

'// --------------------------------------------------------------------------------
'// String Definition Macros
'// --------------------------------------------------------------------------------

'#ifndef STRCONSTA
'#ifdef DEFINE_STRCONST
'#define STRCONSTA(x,y)    EXTERN_C const char x[] = y
'#define STRCONSTW(x,y)    EXTERN_C const WCHAR x[] = L##y
'#else
'#define STRCONSTA(x,y)    EXTERN_C const char x[]
'#define STRCONSTW(x,y)    EXTERN_C const WCHAR x[]
'#endif
'#endif

'// --------------------------------------------------------------------------------
'// rfc822 Headers
'// --------------------------------------------------------------------------------
$STR_HDR_FROM       = "From"                        ' STRCONSTA(STR_HDR_FROM,              "From");
$STR_HDR_TO         = "To"                          ' STRCONSTA(STR_HDR_TO,                "To");
$STR_HDR_CC         = "Cc"                          ' STRCONSTA(STR_HDR_CC,                "Cc");
$STR_HDR_BCC        = "Bcc"                         ' STRCONSTA(STR_HDR_BCC,               "Bcc");
$STR_HDR_SENDER     = "Sender"                      ' STRCONSTA(STR_HDR_SENDER,            "Sender");
$STR_HDR_REPLYTO    = "Reply-To"                    ' STRCONSTA(STR_HDR_REPLYTO,           "Reply-To");
$STR_HDR_RETURNPATH = "Return-Path"                 ' STRCONSTA(STR_HDR_RETURNPATH,        "Return-Path");
$STR_HDR_RR         = "Rr"                          ' STRCONSTA(STR_HDR_RR,                "Rr");
$STR_HDR_RETRCPTTO  = "Return-Receipt-To"           ' STRCONSTA(STR_HDR_RETRCPTTO,         "Return-Receipt-To");
$STR_HDR_APPARTO    = "Apparently-To"               ' STRCONSTA(STR_HDR_APPARTO,           "Apparently-To");
$STR_HDR_DATE       = "Date"                        ' STRCONSTA(STR_HDR_DATE,              "Date");
$STR_HDR_RECEIVED   = "Received"                    ' STRCONSTA(STR_HDR_RECEIVED,          "Received");
$STR_HDR_MESSAGEID  = "Message-ID"                  ' STRCONSTA(STR_HDR_MESSAGEID,         "Message-ID");
$STR_HDR_XMAILER    = "X-Mailer"                    ' STRCONSTA(STR_HDR_XMAILER,           "X-Mailer");
$STR_HDR_ENCODING   = "Encoding"                    ' STRCONSTA(STR_HDR_ENCODING,          "Encoding");
$STR_HDR_ENCRYPTED  = "Encrypted"                   ' STRCONSTA(STR_HDR_ENCRYPTED,         "Encrypted");
$STR_HDR_COMMENT    = "Comment"                     ' STRCONSTA(STR_HDR_COMMENT,           "Comment");
$STR_HDR_SUBJECT    = "Subject"                     ' STRCONSTA(STR_HDR_SUBJECT,           "Subject");
$STR_HDR_MIMEVER    = "MIME-Version"                ' STRCONSTA(STR_HDR_MIMEVER,           "MIME-Version");
$STR_HDR_CNTTYPE    = "Content-Type"                ' STRCONSTA(STR_HDR_CNTTYPE,           "Content-Type");
$STR_HDR_CNTXFER    = "Content-Transfer-Encoding"   ' STRCONSTA(STR_HDR_CNTXFER,           "Content-Transfer-Encoding");
$STR_HDR_CNTID      = "Content-ID"                  ' STRCONSTA(STR_HDR_CNTID,             "Content-ID");
$STR_HDR_CNTDESC    = "Content-Description"         ' STRCONSTA(STR_HDR_CNTDESC,           "Content-Description");
$STR_HDR_CNTDISP    = "Content-Disposition"         ' STRCONSTA(STR_HDR_CNTDISP,           "Content-Disposition");
$STR_HDR_CNTBASE    = "Content-Base"                ' STRCONSTA(STR_HDR_CNTBASE,           "Content-Base");
$STR_HDR_CNTLOC     = "Content-Location"            ' STRCONSTA(STR_HDR_CNTLOC,            "Content-Location");
$STR_HDR_NEWSGROUPS = "Newsgroups"                  ' STRCONSTA(STR_HDR_NEWSGROUPS,        "Newsgroups");
$STR_HDR_PATH       = "Path"                        ' STRCONSTA(STR_HDR_PATH,              "Path");
$STR_HDR_FOLLOWUPTO = "Followup-To"                 ' STRCONSTA(STR_HDR_FOLLOWUPTO,        "Followup-To");
$STR_HDR_EXPIRES    = "Expires"                     ' STRCONSTA(STR_HDR_EXPIRES,           "Expires");
$STR_HDR_REFS       = "References"                  ' STRCONSTA(STR_HDR_REFS,              "References");
'#if _WIN32_WINNT >= 0x0600
$STR_HDR_INREPLYTO  = "In-Reply-To"                 ' STRCONSTA(STR_HDR_INREPLYTO,         "In-Reply-To");
$STR_HDR_CONTROL    = "Control"                     ' STRCONSTA(STR_HDR_CONTROL,           "Control");
'#endif // _WIN32_WINNT >= 0x0600
$STR_HDR_DISTRIB    = "Distribution"                ' STRCONSTA(STR_HDR_DISTRIB,           "Distribution");
$STR_HDR_KEYWORDS   = "Keywords"                    ' STRCONSTA(STR_HDR_KEYWORDS,          "Keywords");
$STR_HDR_SUMMARY    = "Summary"                     ' STRCONSTA(STR_HDR_SUMMARY,           "Summary");
$STR_HDR_APPROVED   = "Approved"                    ' STRCONSTA(STR_HDR_APPROVED,          "Approved");
$STR_HDR_LINES      = "Lines"                       ' STRCONSTA(STR_HDR_LINES,             "Lines");
$STR_HDR_XREF       = "Xref"                        ' STRCONSTA(STR_HDR_XREF,              "Xref");
$STR_HDR_ORG        = "Organization"                ' STRCONSTA(STR_HDR_ORG,               "Organization");
$STR_HDR_XNEWSRDR   = "X-Newsreader"                ' STRCONSTA(STR_HDR_XNEWSRDR,          "X-Newsreader");
$STR_HDR_XPRI       = "X-Priority"                  ' STRCONSTA(STR_HDR_XPRI,              "X-Priority");
$STR_HDR_XMSPRI     = "X-MSMail-Priority"           ' STRCONSTA(STR_HDR_XMSPRI,            "X-MSMail-Priority");
$STR_HDR_OFFSETS    = "X-Offsets"                   ' STRCONSTA(STR_HDR_OFFSETS,           "X-Offsets");
$STR_HDR_XUNSENT    = "X-Unsent"                    ' STRCONSTA(STR_HDR_XUNSENT,           "X-Unsent");
$STR_HDR_ARTICLEID  = "X-ArticleId"                 ' STRCONSTA(STR_HDR_ARTICLEID,         "X-ArticleId");
$STR_HDR_NEWSGROUP  = "X-Newsgroup"                 ' STRCONSTA(STR_HDR_NEWSGROUP,         "X-Newsgroup");
$STR_HDR_XVOICEMAIL = "X-VoiceMail"                 ' STRCONSTA(STR_HDR_XVOICEMAIL,        "X-VoiceMail");
$STR_HDR_XMSOESREC  = "X-MSOESRec"                  ' STRCONSTA(STR_HDR_XMSOESREC,         "X-MSOESRec")

'// --------------------------------------------------------------------------------
'// rfc2646 Headers
'// --------------------------------------------------------------------------------
$STR_HDR_XRFC2646          = "X-RFC2646"           ' STRCONSTA(STR_HDR_XRFC2646,          "X-RFC2646")
$STR_HDR_XRFC2646_FLOWED   = "Format=Flowed"       ' STRCONSTA(STR_HDR_XRFC2646_FLOWED,   "Format=Flowed")
$STR_HDR_XRFC2646_RESPONSE = "Response"            ' STRCONSTA(STR_HDR_XRFC2646_RESPONSE, "Response")
$STR_HDR_XRFC2646_NEW      = "Original"            ' STRCONSTA(STR_HDR_XRFC2646_NEW,      "Original")

'// --------------------------------------------------------------------------------
'// Communities Headers
'// --------------------------------------------------------------------------------
$STR_HDR_POSTID          = "X-MS-CommunityGroup-PostID"            ' STRCONSTA(STR_HDR_POSTID,            "X-MS-CommunityGroup-PostID")
$STR_HDR_MESSAGECATEGORY = "X-MS-CommunityGroup-MessageCategory"   ' STRCONSTA(STR_HDR_MESSAGECATEGORY,   "X-MS-CommunityGroup-MessageCategory")
$STR_HDR_THREADID        = "X-MS-CommunityGroup-ThreadID"          ' STRCONSTA(STR_HDR_THREADID,          "X-MS-CommunityGroup-ThreadID")
$STR_HDR_PARENTID        = "X-MS-CommunityGroup-ParentID"          ' STRCONSTA(STR_HDR_PARENTID,          "X-MS-CommunityGroup-ParentID")

'// --------------------------------------------------------------------------------
'// Parameters Available through IMimePropertySet/IMimeBody
'// --------------------------------------------------------------------------------
$STR_PAR_CHARSET    = "par:content-type:charset"           ' STRCONSTA(STR_PAR_CHARSET,           "par:content-type:charset");
$STR_PAR_NUMBER     = "par:content-type:number"            ' STRCONSTA(STR_PAR_NUMBER,            "par:content-type:number");
$STR_PAR_TOTAL      = "par:content-type:total"             ' STRCONSTA(STR_PAR_TOTAL,             "par:content-type:total");
$STR_PAR_ID         = "par:content-type:id"                ' STRCONSTA(STR_PAR_ID,                "par:content-type:id");
$STR_PAR_BOUNDARY   = "par:content-type:boundary"          ' STRCONSTA(STR_PAR_BOUNDARY,          "par:content-type:boundary");
$STR_PAR_NAME       = "par:content-type:name"              ' STRCONSTA(STR_PAR_NAME,              "par:content-type:name");
$STR_PAR_PROTOCOL   = "par:content-type:protocol"          ' STRCONSTA(STR_PAR_PROTOCOL,          "par:content-type:protocol");
$STR_PAR_MICALG     = "par:content-type:micalg"            ' STRCONSTA(STR_PAR_MICALG,            "par:content-type:micalg");
$STR_PAR_FILENAME   = "par:content-disposition:filename"   ' STRCONSTA(STR_PAR_FILENAME,          "par:content-disposition:filename");
$STR_PAR_TYPE       = "par:content-type:type"              ' STRCONSTA(STR_PAR_TYPE,              "par:content-type:type");
$STR_PAR_START      = "par:content-type:start"             ' STRCONSTA(STR_PAR_START,             "par:content-type:start");
'#if (_WIN32_OE >= 0x0500)
$STR_PAR_ACCESSTYPE = "par:content-type:access-type"       ' STRCONSTA(STR_PAR_ACCESSTYPE,        "par:content-type:access-type");
$STR_PAR_XURL       = "par:content-type:X-URL"             ' STRCONSTA(STR_PAR_XURL,              "par:content-type:X-URL");
$STR_PAR_SIZE       = "par:content-type:size"              ' STRCONSTA(STR_PAR_SIZE,              "par:content-type:size");
$STR_PAR_SMIMETYPE  = "par:content-type:smime-type"        ' STRCONSTA(STR_PAR_SMIMETYPE,         "par:content-type:smime-type");
$STR_PAR_REPORTTYPE = "par:Content-Type:report-type"  ' STRCONSTA(STR_PAR_REPORTTYPE,        "par:Content-Type:report-type")
$STR_PAR_FORMAT     = "par:Content-Type:format"       ' STRCONSTA(STR_PAR_FORMAT,            "par:Content-Type:format")
$STR_PAR_REPLYTYPE  = "par:Content-Type:reply-type"   ' STRCONSTA(STR_PAR_REPLYTYPE,         "par:Content-Type:reply-type")
'#endif

'// --------------------------------------------------------------------------------
'// Attributes Available through IMimePropertySet/IMimeBody
'// --------------------------------------------------------------------------------
$STR_ATT_FILENAME      = "att:filename"              ' STRCONSTA(STR_ATT_FILENAME,          "att:filename");
$STR_ATT_GENFNAME      = "att:generated-filename"    ' STRCONSTA(STR_ATT_GENFNAME,          "att:generated-filename");
$STR_ATT_PRITYPE       = "att:pri-content-type"      ' STRCONSTA(STR_ATT_PRITYPE,           "att:pri-content-type");
$STR_ATT_SUBTYPE       = "att:sub-content-type"      ' STRCONSTA(STR_ATT_SUBTYPE,           "att:sub-content-type");
$STR_ATT_NORMSUBJ      = "att:normalized-subject"    ' STRCONSTA(STR_ATT_NORMSUBJ,          "att:normalized-subject");
$STR_ATT_ILLEGAL       = "att:illegal-lines"         ' STRCONSTA(STR_ATT_ILLEGAL,           "att:illegal-lines");
$STR_ATT_RENDERED      = "att:rendered"              ' STRCONSTA(STR_ATT_RENDERED,          "att:rendered"); // VT_UI4 - TRUE or FALSE
$STR_ATT_AUTOINLINED   = "att:auto-inlined"          ' STRCONSTA(STR_ATT_AUTOINLINED,       "att:auto-inlined"); // VT_UI4 - TRUE or FALSE
$STR_ATT_SENTTIME      = "att:sent-time"             ' STRCONSTA(STR_ATT_SENTTIME,          "att:sent-time");
$STR_ATT_RECVTIME      = "att:received-time"         ' STRCONSTA(STR_ATT_RECVTIME,          "att:received-time");
$STR_ATT_PRIORITY      = "att:priority"              ' STRCONSTA(STR_ATT_PRIORITY,          "att:priority");
$STR_ATT_SERVER        = "att:athena-server"         ' STRCONSTA(STR_ATT_SERVER,            "att:athena-server"); // VT_LPSTR
$STR_ATT_FORMAT        = "att:format"                ' STRCONSTA(STR_ATT_FORMAT,            "att:format") // VT_LPSTR
$STR_ATT_ACCOUNTNAME   = "att:athena-account-name"   ' STRCONSTA(STR_ATT_ACCOUNTNAME,       "att:athena-account-name"); // VT_LPSTR
$STR_ATT_UIDL          = "att:athena-pop3-uidl"      ' STRCONSTA(STR_ATT_UIDL,              "att:athena-pop3-uidl"); // VT_LPSTR
$STR_ATT_STOREMSGID    = "att:athena-store-msgid"    ' STRCONSTA(STR_ATT_STOREMSGID,        "att:athena-store-msgid"); // VT_UI4
$STR_ATT_USERNAME      = "att:athena-user-name"      ' STRCONSTA(STR_ATT_USERNAME,          "att:athena-user-name"); // VT_LPSTR
$STR_ATT_FORWARDTO     = "att:athena-forward-to"     ' STRCONSTA(STR_ATT_FORWARDTO,         "att:athena-forward-to"); // VT_LPSTR
$STR_ATT_STOREFOLDERID = "att:athena-store-fdrid"    ' STRCONSTA(STR_ATT_STOREFOLDERID,     "att:athena-store-fdrid"); // VT_UI4
$STR_ATT_GHOSTED       = "att:athena-ghosted"        ' STRCONSTA(STR_ATT_GHOSTED,           "att:athena-ghosted"); // VT_I4
$STR_ATT_UNCACHEDSIZE  = "att:athena-uncachedsize"   ' STRCONSTA(STR_ATT_UNCACHEDSIZE,      "att:athena-uncachedsize"); // VT_UI4
$STR_ATT_COMBINED      = "att:athena-combined"       ' STRCONSTA(STR_ATT_COMBINED,          "att:athena-combined"); // VT_UI4
$STR_ATT_ACCOUNTID     = "att:athena-account-id"     ' STRCONSTA(STR_ATT_ACCOUNTID,         "att:athena-account-id"); // VT_LPSTR

'// --------------------------------------------------------------------------------
'// MIME Content Types
'// --------------------------------------------------------------------------------
$STR_MIME_TEXT_PLAIN      = "text/plain"                      ' STRCONSTA(STR_MIME_TEXT_PLAIN,       "text/plain");
$STR_MIME_TEXT_HTML       = "text/html"                       ' STRCONSTA(STR_MIME_TEXT_HTML,        "text/html");
$STR_MIME_APPL_STREAM     = "application/octet-stream"        ' STRCONSTA(STR_MIME_APPL_STREAM,      "application/octet-stream");
$STR_MIME_MPART_MIXED     = "multipart/mixed"                 ' STRCONSTA(STR_MIME_MPART_MIXED,      "multipart/mixed");
$STR_MIME_MPART_ALT       = "multipart/alternative"           ' STRCONSTA(STR_MIME_MPART_ALT,        "multipart/alternative");
$STR_MIME_MPART_RELATED   = "multipart/related"               ' STRCONSTA(STR_MIME_MPART_RELATED,    "multipart/related");
$STR_MIME_MSG_PART        = "message/partial"                 ' STRCONSTA(STR_MIME_MSG_PART,         "message/partial");
$STR_MIME_MSG_RFC822      = "message/rfc822"                  ' STRCONSTA(STR_MIME_MSG_RFC822,       "message/rfc822");
$STR_MIME_APPLY_MSTNEF    = "application/ms-tnef"             ' STRCONSTA(STR_MIME_APPLY_MSTNEF,     "application/ms-tnef");
$STR_MIME_APPL_PKCS7SIG   = "application/x-pkcs7-signature"   ' STRCONSTA(STR_MIME_APPL_PKCS7SIG,    "application/x-pkcs7-signature");
$STR_MIME_APPL_PKCS7SIG_1 = "application/pkcs7-signature"     ' STRCONSTA(STR_MIME_APPL_PKCS7SIG_1,  "application/pkcs7-signature");
$STR_MIME_TEXT_ENRCICHED  = "text/enriched"                   ' STRCONSTA(STR_MIME_TEXT_ENRCICHED,   "text/enriched");

'// --------------------------------------------------------------------------------
'// MIME Primary Content Types
'// --------------------------------------------------------------------------------
$STR_CNT_TEXT         = "text"          ' STRCONSTA(STR_CNT_TEXT,               "text");
$STR_CNT_MULTIPART    = "multipart"     ' STRCONSTA(STR_CNT_MULTIPART,          "multipart");
$STR_CNT_MESSAGE      = "message"       ' STRCONSTA(STR_CNT_MESSAGE,            "message");
$STR_CNT_IMAGE        = "image"         ' STRCONSTA(STR_CNT_IMAGE,              "image");
$STR_CNT_AUDIO        = "audio"         ' STRCONSTA(STR_CNT_AUDIO,              "audio");
$STR_CNT_VIDEO        = "video"         ' STRCONSTA(STR_CNT_VIDEO,              "video");
$STR_CNT_APPLICATION  = "application"   ' STRCONSTA(STR_CNT_APPLICATION,        "application");
'$STR_CNT_APPLICATIONW = "application"   ' STRCONSTW(STR_CNT_APPLICATIONW,      "application")

'// --------------------------------------------------------------------------------
'// MIME Secondary Content Types
'// --------------------------------------------------------------------------------
$STR_SUB_PLAIN        = "plain"               ' STRCONSTA(STR_SUB_PLAIN,             "plain");
$STR_SUB_HTML         = "html"                ' STRCONSTA(STR_SUB_HTML,              "html");
$STR_SUB_ENRICHED     = "enriched"            ' STRCONSTA(STR_SUB_ENRICHED,          "enriched");
$STR_SUB_RTF          = "ms-rtf"              ' STRCONSTA(STR_SUB_RTF,               "ms-rtf");
$STR_SUB_MIXED        = "mixed"               ' STRCONSTA(STR_SUB_MIXED,             "mixed");
$STR_SUB_PARALLEL     = "parallel"            ' STRCONSTA(STR_SUB_PARALLEL,          "parallel");
$STR_SUB_DIGEST       = "digest"              ' STRCONSTA(STR_SUB_DIGEST,            "digest");
$STR_SUB_RELATED      = "related"             ' STRCONSTA(STR_SUB_RELATED,           "related");
$STR_SUB_ALTERNATIVE  = "alternative"         ' STRCONSTA(STR_SUB_ALTERNATIVE,       "alternative");
$STR_SUB_RFC822       = "rfc822"              ' STRCONSTA(STR_SUB_RFC822,            "rfc822");
$STR_SUB_PARTIAL      = "partial"             ' STRCONSTA(STR_SUB_PARTIAL,           "partial");
$STR_SUB_EXTERNAL     = "external-body"       ' STRCONSTA(STR_SUB_EXTERNAL,          "external-body");
$STR_SUB_OCTETSTREAM  = "octet-stream"        ' STRCONSTA(STR_SUB_OCTETSTREAM,       "octet-stream");
'$STR_SUB_OCTETSTREAMW = "octet-stream"        ' STRCONSTW(STR_SUB_OCTETSTREAM,       "octet-stream");
$STR_SUB_POSTSCRIPT   = "postscript"          ' STRCONSTA(STR_SUB_POSTSCRIPT,        "postscript");
$STR_SUB_GIF          = "gif"                 ' STRCONSTA(STR_SUB_GIF,               "gif");
$STR_SUB_JPEG         = "jpeg"                ' STRCONSTA(STR_SUB_JPEG,              "jpeg");
$STR_SUB_BASIC        = "basic"               ' STRCONSTA(STR_SUB_BASIC,             "basic");
$STR_SUB_MPEG         = "mpeg"                ' STRCONSTA(STR_SUB_MPEG,              "mpeg");
$STR_SUB_MSTNEF       = "ms-tnef"             ' STRCONSTA(STR_SUB_MSTNEF,            "ms-tnef");
$STR_SUB_MSWORD       = "msword"              ' STRCONSTA(STR_SUB_MSWORD,            "msword");
$STR_SUB_WAV          = "wav"                 ' STRCONSTA(STR_SUB_WAV,               "wav");
$STR_SUB_PKCS7MIME    = "pkcs7-mime"          ' STRCONSTA(STR_SUB_PKCS7MIME,         "pkcs7-mime"); // non-standard
$STR_SUB_PKCS7SIG     = "pkcs7-signature"     ' STRCONSTA(STR_SUB_PKCS7SIG,          "pkcs7-signature"); // non-standard
$STR_SUB_XPKCS7MIME   = "x-pkcs7-mime"        ' STRCONSTA(STR_SUB_XPKCS7MIME,        "x-pkcs7-mime");
$STR_SUB_XPKCS7SIG    = "x-pkcs7-signature"   ' STRCONSTA(STR_SUB_XPKCS7SIG,         "x-pkcs7-signature");
$STR_SUB_SIGNED       = "signed"              ' STRCONSTA(STR_SUB_SIGNED,            "signed");
$STR_SUB_BINHEX       = "mac-binhex40"        ' STRCONSTA(STR_SUB_BINHEX,            "mac-binhex40");
$STR_SUB_VCARD        = "x-vcard"             ' STRCONSTA(STR_SUB_VCARD,             "x-vcard");

'// --------------------------------------------------------------------------------
'// MIME Content-Transfer-Encoding Types
'// --------------------------------------------------------------------------------
$STR_ENC_7BIT      = "7bit"               ' STRCONSTA(STR_ENC_7BIT,              "7bit");
$STR_ENC_QP        = "quoted-printable"   ' STRCONSTA(STR_ENC_QP,                "quoted-printable");
$STR_ENC_BASE64    = "base64"             ' STRCONSTA(STR_ENC_BASE64,            "base64");
$STR_ENC_8BIT      = "8bit"               ' STRCONSTA(STR_ENC_8BIT,              "8bit");
$STR_ENC_BINARY    = "binary"             ' STRCONSTA(STR_ENC_BINARY,            "binary");
$STR_ENC_UUENCODE  = "uuencode"           ' STRCONSTA(STR_ENC_UUENCODE,          "uuencode");
$STR_ENC_XUUENCODE = "x-uuencode"         ' STRCONSTA(STR_ENC_XUUENCODE,         "x-uuencode");
$STR_ENC_XUUE      = "x-uue"              ' STRCONSTA(STR_ENC_XUUE,              "x-uue");
$STR_ENC_BINHEX40  = "mac-binhex40"       ' STRCONSTA(STR_ENC_BINHEX40,          "mac-binhex40");

'// --------------------------------------------------------------------------------
'// MIME Content-Type Format and ReplyType Values
'// --------------------------------------------------------------------------------
$STR_FORMAT_FLOWED      = "flowed"        ' STRCONSTA(STR_FORMAT_FLOWED,         "flowed")
$STR_REPLYTYPE_ORIGINAL = "original"      ' STRCONSTA(STR_REPLYTYPE_ORIGINAL,    "original")
$STR_REPLYTYPE_RESPONSE = "response"      ' STRCONSTA(STR_REPLYTYPE_RESPONSE,    "response")

'// --------------------------------------------------------------------------------
'// MIME Content-Disposition Types
'// --------------------------------------------------------------------------------
$STR_DIS_INLINE      = "inline"       ' STRCONSTA(STR_DIS_INLINE,            "inline");
$STR_DIS_ATTACHMENT  = "attachment"   ' STRCONSTA(STR_DIS_ATTACHMENT,        "attachment");
$STR_DIS_ATTACHMENTW = "attachment"   ' STRCONSTW(STR_DIS_ATTACHMENTW,       "attachment")

'// --------------------------------------------------------------------------------
'// MIME Protocol Types
'// --------------------------------------------------------------------------------
$STR_PRO_SHA1 = "sha1"      ' STRCONSTA(STR_PRO_SHA1,              "sha1");
$STR_PRO_MD5  = "rsa-md5"   ' STRCONSTA(STR_PRO_MD5,               "rsa-md5");

'// --------------------------------------------------------------------------------
'// Known Priority Strings
'// --------------------------------------------------------------------------------
$STR_PRI_MS_HIGH             = "High"                           ' STRCONSTA(STR_PRI_MS_HIGH,           "High");
$STR_PRI_MS_NORMAL           = "Normal"                         ' STRCONSTA(STR_PRI_MS_NORMAL,         "Normal");
$STR_PRI_MS_LOW              = "Low"                            ' STRCONSTA(STR_PRI_MS_LOW,            "Low");
$STR_PRI_HIGH                = "1"                              ' STRCONSTA(STR_PRI_HIGH,              "1");
$STR_PRI_NORMAL              = "3"                              ' STRCONSTA(STR_PRI_NORMAL,            "3");
$STR_PRI_LOW                 = "5"                              ' STRCONSTA(STR_PRI_LOW,               "5");
$STR_HDR_ORIG_RECIPIENT       = "Original-Recipient"            ' STRCONSTA(STR_HDR_ORIG_RECIPIENT,    "Original-Recipient")
$STR_HDR_DISP_NOTIFICATION_TO = "Disposition-Notification-To"   ' STRCONSTA(STR_HDR_DISP_NOTIFICATION_TO, "Disposition-Notification-To")

'// --------------------------------------------------------------------------------
'// IMimeMessage IDataObject clipboard formats (also include CF_TEXT)
'// --------------------------------------------------------------------------------
$STR_CF_HTML    = "HTML Format"                         ' STRCONSTA(STR_CF_HTML,               "HTML Format");
$STR_CF_INETMSG = "Internet Message (rfc822/rfc1522)"   ' STRCONSTA(STR_CF_INETMSG,            "Internet Message (rfc822/rfc1522)");
$STR_CF_RFC822  = "message/rfc822"                      ' STRCONSTA(STR_CF_RFC822,             "message/rfc822");

'// --------------------------------------------------------------------------------
'// SMime-Type strings
'// --------------------------------------------------------------------------------
$STR_SMT_SIGNEDDATA    = "signed-data"      ' STRCONSTA(STR_SMT_SIGNEDDATA,        "signed-data")
$STR_SMT_ENVELOPEDDATA = "enveloped-data"   ' STRCONSTA(STR_SMT_ENVELOPEDDATA,     "enveloped-data")
$STR_SMT_SIGNEDRECEIPT = "signed-receipt"   ' STRCONSTA(STR_SMT_SIGNEDRECEIPT,     "signed-receipt")

'// --------------------------------------------------------------------------------
'// PIDSTRING - Use in GetProp, SetProp, QueryProp, DeleteProp
'// --------------------------------------------------------------------------------
'#define PID_BASE                     2
'#define PIDTOSTR(_dwPropId)          ((LPCSTR)((DWORD_PTR)(_dwPropId)))
'#define STRTOPID(_pszName)           ((DWORD)((DWORD_PTR)((LPCSTR)(_pszName))))
'#define ISPIDSTR(_pszName)           ((HIWORD((DWORD_PTR)(_pszName)) == 0))
'#define ISKNOWNPID(_dwPropId)        (_dwPropId >= PID_BASE && _dwPropId < PID_LAST)

%PID_BASE = 2

'// --------------------------------------------------------------------------------
'// Mime Property Ids
'// --------------------------------------------------------------------------------

' MIMEPROPID enum
%PID_HDR_NEWSGROUP            = 2
%PID_HDR_NEWSGROUPS           = 3
%PID_HDR_REFS                 = 4
%PID_HDR_SUBJECT              = 5
%PID_HDR_FROM                 = 6
%PID_HDR_MESSAGEID            = 7
%PID_HDR_RETURNPATH           = 8
%PID_HDR_RR                   = 9
%PID_HDR_RETRCPTTO            = 10
%PID_HDR_APPARTO              = 11
%PID_HDR_DATE                 = 12
%PID_HDR_RECEIVED             = 13
%PID_HDR_REPLYTO              = 14
%PID_HDR_XMAILER              = 15
%PID_HDR_BCC                  = 16
%PID_HDR_MIMEVER              = 17
%PID_HDR_CNTTYPE              = 18
%PID_HDR_CNTXFER              = 19
%PID_HDR_CNTID                = 20
%PID_HDR_CNTDESC              = 21
%PID_HDR_CNTDISP              = 22
%PID_HDR_CNTBASE              = 23
%PID_HDR_CNTLOC               = 24
%PID_HDR_TO                   = 25
%PID_HDR_PATH                 = 26
%PID_HDR_FOLLOWUPTO           = 27
%PID_HDR_EXPIRES              = 28
%PID_HDR_CC                   = 29
%PID_HDR_CONTROL              = 30
%PID_HDR_DISTRIB              = 31
%PID_HDR_KEYWORDS             = 32
%PID_HDR_SUMMARY              = 33
%PID_HDR_APPROVED             = 34
%PID_HDR_LINES                = 35
%PID_HDR_XREF                 = 36
%PID_HDR_ORG                  = 37
%PID_HDR_XNEWSRDR             = 38
%PID_HDR_XPRI                 = 39
%PID_HDR_XMSPRI               = 40
%PID_PAR_FILENAME             = 41
%PID_PAR_BOUNDARY             = 42
%PID_PAR_CHARSET              = 43
%PID_PAR_NAME                 = 44
%PID_ATT_FILENAME             = 45
%PID_ATT_GENFNAME             = 46
%PID_ATT_PRITYPE              = 47
%PID_ATT_SUBTYPE              = 48
%PID_ATT_NORMSUBJ             = 49
%PID_ATT_ILLEGAL              = 50
%PID_ATT_RENDERED             = 51
%PID_ATT_SENTTIME             = 52
%PID_ATT_RECVTIME             = 53
%PID_ATT_PRIORITY             = 54
%PID_HDR_COMMENT              = 55
%PID_HDR_ENCODING             = 56
%PID_HDR_ENCRYPTED            = 57
%PID_HDR_OFFSETS              = 58
%PID_HDR_XUNSENT              = 59
%PID_HDR_ARTICLEID            = 60
%PID_HDR_SENDER               = 61
%PID_ATT_SERVER               = 62
%PID_ATT_ACCOUNT              = 63
%PID_ATT_UIDL                 = 64
%PID_ATT_STOREMSGID           = 65
%PID_ATT_USERNAME             = 66
%PID_ATT_FORWARDTO            = 67
%PID_ATT_STOREFOLDERID        = 68
%PID_ATT_GHOSTED              = 69
%PID_ATT_UNCACHEDSIZE         = 70
%PID_ATT_COMBINED             = 71
%PID_ATT_AUTOINLINED          = 72
%PID_HDR_DISP_NOTIFICATION_TO = 73
%PID_PAR_REPLYTYPE            = 74
%PID_PAR_FORMAT               = 75
%PID_ATT_FORMAT               = 76
#IF %WINVER >= &H0600
%PID_HDR_INREPLYTO            = 77
%PID_ATT_ACCOUNTNAME          = 78
%PID_LAST                     = 79
#ELSE
%PID_LAST                     = 77
#ENDIF   ' // _WIN32_WINNT >= 0x0600

'// --------------------------------------------------------------------------------
'// Variant Typed Identifiers
'// --------------------------------------------------------------------------------
'#define TYPEDID_MASK                     ((ULONG)0x0000FFFF)
'#define TYPEDID_TYPE(_typedid)           (VARTYPE)(((ULONG)(_typedid)) & TYPEDID_MASK)
'#define TYPEDID_ID(_typedid)             (((ULONG)(_typedid))>>16)
'#define TYPEDID(_vartype,_id)            ((((TYPEDID)(_id))<<16)|((ULONG)(_vartype)))

%TYPEDID_MASK                = &H0000FFFF???

MACRO TYPEDID_TYPE(typedid_) = (typedid_ AND %TYPEDID_MASK)

'#define TYPEDID_ID(_typedid)                (((ULONG)(_typedid))>>16)
FUNCTION TYPEDID_ID (BYVAL typedid_ AS DWORD) AS DWORD
   SHIFT RIGHT typedid_, 16
   FUNCTION = typedid_
END FUNCTION

FUNCTION TYPEDID (BYVAL vartype AS DWORD, BYVAL id AS DWORD) AS DWORD
   SHIFT LEFT id, 16
   FUNCTION = id OR vartype
END FUNCTION

'// --------------------------------------------------------------------------------
'// Options Ids
'// --------------------------------------------------------------------------------
%OID_ALLOW_8BIT_HEADER            = &H0001000B???   ' #define OID_ALLOW_8BIT_HEADER            TYPEDID(VT_BOOL,    0x0001) // TRUE or FALSE
%OID_CBMAX_HEADER_LINE            = &H00020013???   ' #define OID_CBMAX_HEADER_LINE            TYPEDID(VT_UI4,     0x0002) // Bytes
%OID_SAVE_FORMAT                  = &H00030013???   ' #define OID_SAVE_FORMAT                  TYPEDID(VT_UI4,     0x0003) // SAVE_RFC822 or SAVE_RFC1521 (mime)
%OID_WRAP_BODY_TEXT               = &H0004000B???   ' #define OID_WRAP_BODY_TEXT               TYPEDID(VT_BOOL,    0x0004) // TRUE or FALSE
%OID_CBMAX_BODY_LINE              = &H00050013???   ' #define OID_CBMAX_BODY_LINE              TYPEDID(VT_UI4,     0x0005) // Bytes
%OID_TRANSMIT_BODY_ENCODING       = &H00060013???   ' #define OID_TRANSMIT_BODY_ENCODING       TYPEDID(VT_UI4,     0x0006) // ENCODINGTYPE
%OID_TRANSMIT_TEXT_ENCODING       = &H00070013???   ' #define OID_TRANSMIT_TEXT_ENCODING       TYPEDID(VT_UI4,     0x0007) // ENCODINGTYPE, IMimeMessageTree
%OID_GENERATE_MESSAGE_ID          = &H0008000B???   ' #define OID_GENERATE_MESSAGE_ID          TYPEDID(VT_BOOL,    0x0008) // TRUE or FALSE
%OID_HIDE_TNEF_ATTACHMENTS        = &H000E000B???   ' #define OID_HIDE_TNEF_ATTACHMENTS        TYPEDID(VT_BOOL,    0X000E) // TRUE or FALSE
%OID_CLEANUP_TREE_ON_SAVE         = &H000F000B???   ' #define OID_CLEANUP_TREE_ON_SAVE         TYPEDID(VT_BOOL,    0X000F) // TRUE or FALSE
%OID_BODY_REMOVE_NBSP             = &H0014000B???   ' #define OID_BODY_REMOVE_NBSP             TYPEDID(VT_BOOL,    0x0014) // TRUE or FALSE
%OID_DEFAULT_BODY_CHARSET         = &H00150013???   ' #define OID_DEFAULT_BODY_CHARSET         TYPEDID(VT_UI4,     0x0015) // HCHARSET
%OID_DEFAULT_HEADER_CHARSET       = &H00160013???   ' #define OID_DEFAULT_HEADER_CHARSET       TYPEDID(VT_UI4,     0x0016) // HCHARSET
%OID_DBCS_ESCAPE_IS_8BIT          = &H0017000B???   ' #define OID_DBCS_ESCAPE_IS_8BIT          TYPEDID(VT_BOOL,    0x0017) // TRUE or FALSE
%OID_SECURITY_TYPE                = &H00180013???   ' #define OID_SECURITY_TYPE                TYPEDID(VT_UI4,     0x0018)
%OID_SECURITY_ALG_HASH            = &H0019000B???   ' #define OID_SECURITY_ALG_HASH            TYPEDID(VT_BLOB,    0x0019)
%OID_SECURITY_ALG_BULK            = &H0020000B???   ' #define OID_SECURITY_ALG_BULK            TYPEDID(VT_BLOB,    0x0020)
'#ifndef _WIN64
%OID_SECURITY_CERT_SIGNING        = &H00210013???   ' #define OID_SECURITY_CERT_SIGNING        TYPEDID(VT_UI4,     0x0021)
%OID_SECURITY_CERT_DECRYPTION     = &H00220013???   ' #define OID_SECURITY_CERT_DECRYPTION     TYPEDID(VT_UI4,     0x0022)
%OID_SECURITY_RG_CERT_ENCRYPT     = &H00231013???   ' #define OID_SECURITY_RG_CERT_ENCRYPT     TYPEDID(VT_VECTOR | VT_UI4, 0x0023)
%OID_SECURITY_HCERTSTORE          = &H00240013???   ' #define OID_SECURITY_HCERTSTORE          TYPEDID(VT_UI4,     0x0024)
%OID_SECURITY_RG_CERT_BAG         = &H00251013???   ' #define OID_SECURITY_RG_CERT_BAG         TYPEDID(VT_VECTOR | VT_UI4, 0x0025)
%OID_SECURITY_HCRYPTPROV          = &H00260013???   ' #define OID_SECURITY_HCRYPTPROV          TYPEDID(VT_UI4,     0x0026)
%OID_SECURITY_SEARCHSTORES        = &H00271013???   ' #define OID_SECURITY_SEARCHSTORES        TYPEDID(VT_VECTOR | VT_UI4, 0x0027)
%OID_SECURITY_RG_IASN             = &H00281013???   ' #define OID_SECURITY_RG_IASN             TYPEDID(VT_VECTOR | VT_UI4, 0x0028)
'#else // _WIN64
%OID_SECURITY_CERT_SIGNING_64     = &H00210015???   ' #define OID_SECURITY_CERT_SIGNING_64     TYPEDID(VT_UI8,     0x0021)
%OID_SECURITY_CERT_DECRYPTION_64  = &H00220015???   ' #define OID_SECURITY_CERT_DECRYPTION_64  TYPEDID(VT_UI8,     0x0022)
%OID_SECURITY_RG_CERT_ENCRYPT_64  = &H00231015???   ' #define OID_SECURITY_RG_CERT_ENCRYPT_64  TYPEDID(VT_VECTOR | VT_UI8, 0x0023)
%OID_SECURITY_HCERTSTORE_64       = &H00240015???   ' #define OID_SECURITY_HCERTSTORE_64       TYPEDID(VT_UI8,     0x0024)
%OID_SECURITY_RG_CERT_BAG_64      = &H00251015???   ' #define OID_SECURITY_RG_CERT_BAG_64      TYPEDID(VT_VECTOR | VT_UI8, 0x0025)
%OID_SECURITY_HCRYPTPROV_64       = &H00260015???   ' #define OID_SECURITY_HCRYPTPROV_64       TYPEDID(VT_UI8,     0x0026)
%OID_SECURITY_SEARCHSTORES_64     = &H00271013???   ' #define OID_SECURITY_SEARCHSTORES_64     TYPEDID(VT_VECTOR | VT_UI4, 0x0027)
%OID_SECURITY_RG_IASN_64          = &H00281013???   ' #define OID_SECURITY_RG_IASN_64          TYPEDID(VT_VECTOR | VT_UI4, 0x0028)
'#endif // _WIN64
%OID_SECURITY_SYMCAPS             = &H00290041???   ' #define OID_SECURITY_SYMCAPS             TYPEDID(VT_BLOB,    0x0029)
%OID_SECURITY_AUTHATTR            = &H002A0041???   ' #define OID_SECURITY_AUTHATTR            TYPEDID(VT_BLOB,    0x002A)
%OID_SECURITY_UNAUTHATTR          = &H002B0041???   ' #define OID_SECURITY_UNAUTHATTR          TYPEDID(VT_BLOB,    0x002B)
%OID_SECURITY_SIGNTIME            = &H002C0040???   ' #define OID_SECURITY_SIGNTIME            TYPEDID(VT_FILETIME,0x002C)
%OID_SECURITY_USER_VALIDITY       = &H002D0013???   ' #define OID_SECURITY_USER_VALIDITY       TYPEDID(VT_UI4,     0x002D)
%OID_SECURITY_RO_MSG_VALIDITY     = &H002E0013???   ' #define OID_SECURITY_RO_MSG_VALIDITY     TYPEDID(VT_UI4,     0x002E) // read-only
%OID_SECURITY_CRL                 = &H00260041???   ' #define OID_SECURITY_CRL                 TYPEDID(VT_BLOB,    0x002F)
%OID_SECURITY_ENCODE_FLAGS        = &H00300013???   ' #define OID_SECURITY_ENCODE_FLAGS        TYPEDID(VT_UI4,     0x0030)
%OID_SECURITY_CERT_INCLUDED       = &H0031000B???   ' #define OID_SECURITY_CERT_INCLUDED       TYPEDID(VT_BOOL,    0x0031) // read-only
'#ifndef _WIN64
%OID_SECURITY_HWND_OWNER          = &H00320013???   ' #define OID_SECURITY_HWND_OWNER          TYPEDID(VT_UI4,     0x0032)
'#endif // _WIN64
%OID_SECURITY_REQUESTED_CTE       = &H00330003???   ' #define OID_SECURITY_REQUESTED_CTE       TYPEDID(VT_I4,      0x0033)
%OID_NO_DEFAULT_CNTTYPE           = &H0034000B???   ' #define OID_NO_DEFAULT_CNTTYPE           TYPEDID(VT_BOOL,    0x0034)
%OID_XMIT_PLAIN_TEXT_ENCODING     = &H00350013???   ' #define OID_XMIT_PLAIN_TEXT_ENCODING     TYPEDID(VT_UI4,     0x0035) // ENCODINGTYPE, IMimeMessageTree
%OID_XMIT_HTML_TEXT_ENCODING      = &H00360013???   ' #define OID_XMIT_HTML_TEXT_ENCODING      TYPEDID(VT_UI4,     0x0036) // ENCODINGTYPE, IMimeMessageTree
%OID_HEADER_RELOAD_TYPE           = &H00370013???   ' #define OID_HEADER_RELOAD_TYPE           TYPEDID(VT_UI4,     0x0037) // RELOADTYPE IMimeMessageTree or IMimeBody or IMimePropertySet
%OID_CAN_INLINE_TEXT_BODIES       = &H0038000B???   ' #define OID_CAN_INLINE_TEXT_BODIES       TYPEDID(VT_BOOL,    0x0038) // TRUE or FALSE
%OID_SHOW_MACBINARY               = &H0039000B???   ' #define OID_SHOW_MACBINARY               TYPEDID(VT_BOOL,    0x0039) // TRUE or FALSE
%OID_SAVEBODY_KEEPBOUNDARY        = &H0040000B???   ' #define OID_SAVEBODY_KEEPBOUNDARY        TYPEDID(VT_BOOL,    0x0040) // TRUE or FALSE
'#if (_WIN32_OE >= 0x0500)
%OID_SECURITY_ALG_HASH_RG         = &H0019100C???   ' #define OID_SECURITY_ALG_HASH_RG         TYPEDID(VT_VECTOR | VT_VARIANT,    0x0019)
'#ifndef _WIN64
%OID_SECURITY_CERT_SIGNING_RG     = &H00211013???   ' #define OID_SECURITY_CERT_SIGNING_RG     TYPEDID(VT_VECTOR | VT_UI4,        0x0021)
'#else
%ID_SECURITY_CERT_SIGNING_RG_64   = &H00211015???   ' #define OID_SECURITY_CERT_SIGNING_RG_64  TYPEDID(VT_VECTOR | VT_UI8,        0x0021)
'#endif //_WIN64
%OID_SECURITY_SYMCAPS_RG          = &H0029100C???   ' #define OID_SECURITY_SYMCAPS_RG          TYPEDID(VT_VECTOR | VT_VARIANT,    0x0029)
%OID_SECURITY_AUTHATTR_RG         = &H002A100C???   ' #define OID_SECURITY_AUTHATTR_RG         TYPEDID(VT_VECTOR | VT_VARIANT,    0x002A)
%OID_SECURITY_UNAUTHATTR_RG       = &H002B100C???   ' #define OID_SECURITY_UNAUTHATTR_RG       TYPEDID(VT_VECTOR | VT_VARIANT,    0x002B)
%OID_SECURITY_SIGNTIME_RG         = &H002C1040???   ' #define OID_SECURITY_SIGNTIME_RG         TYPEDID(VT_VECTOR | VT_FILETIME,   0x002C)
%OID_SECURITY_USER_VALIDITY_RG    = &H002D1013???   ' #define OID_SECURITY_USER_VALIDITY_RG    TYPEDID(VT_VECTOR | VT_UI4,        0x002D)
%OID_SECURITY_RO_MSG_VALIDITY_RG  = &H002E1013???   ' #define OID_SECURITY_RO_MSG_VALIDITY_RG  TYPEDID(VT_VECTOR | VT_UI4,        0x002E) // read-only
%OID_SUPPORT_EXTERNAL_BODY        = &H0041000B???   ' #define OID_SUPPORT_EXTERNAL_BODY        TYPEDID(VT_BOOL,    0x0041) // TRUE or FALSE
%OID_LOAD_USE_BIND_FILE           = &H0042000B???   ' #define OID_LOAD_USE_BIND_FILE           TYPEDID(VT_BOOL,    0x0042) // TRUE or FALSE
%OID_SECURITY_SIGNATURE_COUNT     = &H00430013???   ' #define OID_SECURITY_SIGNATURE_COUNT     TYPEDID(VT_UI4,     0x0043) // Size of SECURITY LAYER arrays
%OID_HANDSOFF_ONSAVE              = &H00440041???   ' #define OID_HANDSOFF_ONSAVE              TYPEDID(VT_BOOL,    0x0044) // TRUE or FALSE
'%OID_SECURITY_RECEIPT             = &H00450041???   ' #define OID_SECURITY_RECEIPT             TYPEDID(VT_BLOB,    0x0045) // Receipt body
%OID_SECURITY_RECEIPT_RG          = &H0045100C???   ' #define OID_SECURITY_RECEIPT_RG          TYPEDID(VT_VECTOR | VT_VARIANT,    0x0045) // Receipt body
%OID_NOSECURITY_ONSAVE            = &H0046000B???   ' #define OID_NOSECURITY_ONSAVE            TYPEDID(VT_BOOL,    0x0046) // TRUE or FALSE
%OID_DECODE_RFC1154               = &H0047000B???   ' #define OID_DECODE_RFC1154               TYPEDID(VT_BOOL,    0x0047) // TRUE or FALSE
'#endif
%OID_SECURITY_MESSAGE_HASH_RG     = &H004A100C???   ' #define OID_SECURITY_MESSAGE_HASH_RG     TYPEDID(VT_VECTOR | VT_VARIANT,    0x004A) // Message Hash
%OID_SECURITY_KEY_PROMPT          = &H004B001F???   ' #define OID_SECURITY_KEY_PROMPT          TYPEDID(VT_LPWSTR,  0x004B) // Key Prompt
'#ifndef _WIN64
%OID_SECURITY_ENCRYPT_CERT_BAG    = &H004C0013???   ' #define OID_SECURITY_ENCRYPT_CERT_BAG    TYPEDID(VT_UI4, 0x004C) // HCERTSTORE
'#else //_WIN64
%OID_SECURITY_ENCRYPT_CERT_BAG_64 = &H004C0015???   ' #define OID_SECURITY_ENCRYPT_CERT_BAG_64 TYPEDID(VT_UI8, 0x004C) // HCERTSTORE
'#endif // WIN64
'#endif // _WIN32_OE
'#ifdef _WIN64
%OID_SECURITY_HWND_OWNER_64       = &H00570015???   ' #define OID_SECURITY_HWND_OWNER_64         TYPEDID(VT_UI8,   0x0057)
'#endif // WIN64
'#ifndef _WIN64
%OID_SECURITY_2KEY_CERT_BAG       = &H00591013???   ' #define OID_SECURITY_2KEY_CERT_BAG        TYPEDID(VT_VECTOR | VT_UI4, 0x0059)
'#else //_WIN64
%OID_SECURITY_2KEY_CERT_BAG_64    = &H00591015???   ' #define OID_SECURITY_2KEY_CERT_BAG_64    TYPEDID(VT_VECTOR | VT_UI8, 0x0059)
'#endif // WIN64


'// --------------------------------------------------------------------------------
'// Default Option Values
'// --------------------------------------------------------------------------------
%DEF_ALLOW_8BIT_HEADER            = %FALSE
%DEF_CBMAX_HEADER_LINE            = 1000
%DEF_SAVE_FORMAT                  = 1   ' %SAVE_RFC1521
%DEF_WRAP_BODY_TEXT               = %TRUE
%DEF_CBMAX_BODY_LINE              = 74
%DEF_GENERATE_MESSAGE_ID          = %FALSE
%DEF_HASH_ALG_ID                  = &H8004  ' //SHA //N needed?
%DEF_ENCRYPTION_ALG_ID            = &H6602  ' //RC2 //N needed?
%DEF_INCLUDE_SENDER_CERT          = %FALSE
%DEF_HIDE_TNEF_ATTACHMENTS        = %TRUE
%DEF_CLEANUP_TREE_ON_SAVE         = %TRUE
%DEF_BODY_REMOVE_NBSP             = %TRUE
%DEF_SECURITY_IGNOREMASK          = 0
%DEF_DBCS_ESCAPE_IS_8BIT          = %FALSE
%DEF_TRANSMIT_BODY_ENCODING       = 11   ' %IET_UNKNOWN
%DEF_TRANSMIT_TEXT_ENCODING       = 11   ' %IET_UNKNOWN
%DEF_XMIT_PLAIN_TEXT_ENCODING     = 11   ' %IET_UNKNOWN
%DEF_XMIT_HTML_TEXT_ENCODING      = 11   ' %IET_UNKNOWN
%DEF_NO_DEFAULT_CNTTYPE           = %FALSE
%DEF_HEADER_RELOAD_TYPE_TREE      = 1   ' %RELOAD_HEADER_RESET
%DEF_HEADER_RELOAD_TYPE_PROPSET   = 0   ' %RELOAD_HEADER_NONE
%DEF_CAN_INLINE_TEXT_BODIES       = %FALSE
%DEF_SHOW_MACBINARY               = %FALSE
%DEF_SAVEBODY_KEEPBOUNDARY        = %FALSE
'#if (_WIN32_OE >= 0x0500)
%DEF_SUPPORT_EXTERNAL_BODY        = %FALSE
%DEF_LOAD_USE_BIND_FILE           = %FALSE
%DEF_HANDSOFF_ONSAVE              = %FALSE
%DEF_DECODE_RFC1154               = %FALSE
'#endif // _WIN32_OE

'// --------------------------------------------------------------------------------
'// Min-Max Option Values
'// --------------------------------------------------------------------------------
%MAX_CBMAX_HEADER_LINE            = &HFFFFFFFF???
%MIN_CBMAX_HEADER_LINE            = 76
%MAX_CBMAX_BODY_LINE              = &HFFFFFFFF???
%MIN_CBMAX_BODY_LINE              = 30

'// --------------------------------------------------------------------------------
'// LIBID_MIMEOLE
'// --------------------------------------------------------------------------------

#IF NOT %DEF(%MIMEOLE_LIBRARY_DEFINED)
    %MIMEOLE_LIBRARY_DEFINED = 1

'struct  HCHARSET__
'    {
'    DWORD unused;
'    };
'typedef struct HCHARSET__ *HCHARSET;

'TYPE HCHARSET
'   unused AS DWORD
'END TYPE

'struct  HBODY__
'    {
'    DWORD unused;
'    };

'TYPE HBODY
'   unused AS DWORD
'END TYPE

'struct  HHEADERROW__
'    {
'    DWORD unused;
'    };

'TYPE HHEADERROW
'   unused AS DWORD
'END TYPE

' typedef DWORD TYPEDID;
' MACRO TYPEDID = DWORD


' RELOADTYPE enum
%RELOAD_HEADER_NONE    = 0
%RELOAD_HEADER_RESET   = %RELOAD_HEADER_NONE + 1
%RELOAD_HEADER_APPEND  = %RELOAD_HEADER_RESET + 1
%RELOAD_HEADER_REPLACE = %RELOAD_HEADER_APPEND + 1

' MIMESAVETYPE enum
%SAVE_RFC822  = 0
%SAVE_RFC1521 = %SAVE_RFC822 + 1

' CSETAPPLYTYPE enum
%CSET_APPLY_UNTAGGED = 0
%CSET_APPLY_ALL      = %CSET_APPLY_UNTAGGED + 1
%CSET_APPLY_TAG_ALL  = %CSET_APPLY_ALL      + 1

' ENCODINGTYPE enum
%IET_BINARY   = 0
%IET_BASE64   = %IET_BINARY + 1
%IET_UUENCODE = %IET_BASE64 + 1
%IET_QP       = %IET_UUENCODE + 1
%IET_7BIT     = %IET_QP + 1
%IET_8BIT     = %IET_7BIT + 1
%IET_INETCSET = %IET_8BIT + 1
%IET_UNICODE  = %IET_INETCSET + 1
%IET_RFC1522  = %IET_UNICODE + 1
%IET_ENCODED  = %IET_RFC1522 + 1
%IET_CURRENT  = %IET_ENCODED + 1
%IET_UNKNOWN  = %IET_CURRENT + 1
%IET_BINHEX40 = %IET_UNKNOWN + 1
%IET_LAST     = %IET_BINHEX40 + 1

%IET_DECODED  = %IET_BINARY

%CCHMAX_HEADER_LINE = 1000

' ########################################################################################
' Interface name = IMimeInternational
' IID = {C5588349-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeInternational_INTERFACE_DEFINED)
    %IMimeInternational_INTERFACE_DEFINED = 1

'typedef DWORD CODEPAGEID;

%CP_USASCII       = 1252???
%CP_UNICODE       = 1200???
%CP_JAUTODETECT   = 50932???
%CP_KAUTODETECT   = 50949???
%CP_ISO2022JPESC  = 50221???
%CP_ISO2022JPSIO  = 50222???
%CCHMAX_CSET_NAME = 128???
%CCHMAX_LANG_NAME = 128???
%CCHMAX_FACE_NAME = 128???

' // Size = 144 bytes
TYPE INETCSETINFO DWORD
   szName      AS ASCIIZ * %CCHMAX_CSET_NAME   ' CHAR
   hCharset    AS DWORD                        ' HCHARSET
   cpiWindows  AS DWORD                        ' CODEPAGEID
   cpiInternet AS DWORD                        ' CODEPAGEID
   dwReserved1 AS DWORD                        ' DWORD
END TYPE

' INETLANGMASK enum
%ILM_FAMILY       = &H1
%ILM_NAME         = &H2
%ILM_BODYCSET     = &H4
%ILM_HEADERCSET   = &H8
%ILM_WEBCSET      = &H10
%ILM_FIXEDFONT    = &H20
%ILM_VARIABLEFONT = &H40

' // Size = 804 bytes
TYPE CODEPAGEINFO DWORD
   dwMask           AS DWORD
   cpiCodePage      AS DWORD                        ' CODEPAGEID
   fIsValidCodePage AS LONG
   ulMaxCharSize    AS DWORD
   fInternetCP      AS LONG
   cpiFamily        AS DWORD                        ' CODEPAGEID
   szName           AS ASCIIZ * %CCHMAX_LANG_NAME   ' CHAR
   szBodyCset       AS ASCIIZ * %CCHMAX_LANG_NAME   ' CHAR
   szHeaderCset     AS ASCIIZ * %CCHMAX_LANG_NAME   ' CHAR
   szWebCset        AS ASCIIZ * %CCHMAX_LANG_NAME   ' CHAR
   szFixedFont      AS ASCIIZ * %CCHMAX_FACE_NAME   ' CHAR
   szVariableFont   AS ASCIIZ * %CCHMAX_FACE_NAME   ' CHAR
   ietNewsDefault   AS LONG                         ' ENCODINGTYPE enum
   ietMailDefault   AS LONG                         ' ENCODINGTYPE enum
   dwReserved1      AS DWORD
END TYPE

' // Size = 16 bytes
TYPE RFC1522INFO DWORD
   fRfc1522Allowed AS LONG
   fRfc1522Used    AS LONG
   fAllow8bit      AS LONG
   hRfc1522Cset    AS DWORD   ' // HCHARSET
END TYPE

' CHARSETTYPE enum
%CHARSET_BODY   = 0
%CHARSET_HEADER = %CHARSET_BODY   + 1
%CHARSET_WEB    = %CHARSET_HEADER + 1

INTERFACE IMimeInternational $IID_IMimeInternational

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDefaultCharset ( _                         ' VTable offset = 12
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultCharset ( _                         ' VTable offset = 16
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageCharset ( _                        ' VTable offset = 20
     BYVAL cpiCodePage AS DWORD _                       ' __in CODEPAGEID cpiCodePage
   , BYVAL ctCsetType AS LONG _                         ' __in CHARSETTYPE ctCsetType
   , BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindCharset ( _                               ' VTable offset = 24
     BYREF pszCharset AS ASCIIZ _                       ' __in LPCSTR pszCharset
   , BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharsetInfo ( _                            ' VTable offset = 28
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYREF pCsetInfo AS INETCSETINFO _                  ' __in_out LPINETCSETINFO pCsetInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageInfo ( _                           ' VTable offset = 32
     BYVAL cpiCodePage AS DWORD _                       ' __in CODEPAGEID cpiCodePage
   , BYREF pCodePageInfo AS CODEPAGEINFO _              ' __in_out LPCODEPAGEINFO pCodePageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanConvertCodePages ( _                       ' VTable offset = 36
     BYVAL cpiSource AS DWORD _                         ' __in CODEPAGEID cpiSource
   , BYVAL cpiDest AS DWORD _                           ' __in CODEPAGEID cpiDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecodeHeader ( _                              ' VTable offset = 40
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYREF pszData AS ASCIIZ _                          ' __in LPCSTR pszData
   , BYREF pDecoded AS PROPVARIANT _                    ' __in_out LPPROPVARIANT pDecoded
   , BYREF pRfc1522Info AS RFC1522INFO _                ' __in_out LPRFC1522INFO pRfc1522Info
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncodeHeader ( _                              ' VTable offset = 44
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYREF pData AS PROPVARIANT _                       ' __in LPPROPVARIANT pData
   , BYREF ppszEncoded AS DWORD _                       ' __out LPSTR *ppszEncoded
   , BYREF pRfc1522Info AS RFC1522INFO _                ' __in_out LPRFC1522INFO pRfc1522Info
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertBuffer ( _                             ' VTable offset = 48
     BYVAL cpiSource AS DWORD _                         ' __in CODEPAGEID cpiSource
   , BYVAL cpiDest AS DWORD _                           ' __in CODEPAGEID cpiDest
   , BYREF pIn AS BLOB _                                ' __in LPBLOB pIn
   , BYREF pOut AS BLOB _                               ' __in_out LPBLOB pOut
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertString ( _                             ' VTable offset = 52
     BYVAL cpiSource AS DWORD _                         ' __in CODEPAGEID cpiSource
   , BYVAL cpiDest AS DWORD _                           ' __in CODEPAGEID cpiDest
   , BYREF pIn AS PROPVARIANT _                         ' __in LPPROPVARIANT pIn
   , BYREF pOut AS PROPVARIANT _                        ' __in_out LPPROPVARIANT pOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MLANG_ConvertInetReset ( _                    ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MLANG_ConvertInetString ( _                   ' VTable offset = 60
     BYVAL cpiSource AS DWORD _                         ' __in CODEPAGEID cpiSource
   , BYVAL cpiDest AS DWORD _                           ' __in CODEPAGEID cpiDest
   , BYREF pSource AS ASCIIZ _                          ' __in LPCSTR pSource
   , BYREF pnSizeOfSource AS LONG _                     ' __in int *pnSizeOfSource
   , BYREF pDestination AS DWORD _                      ' __out LPSTR pDestination
   , BYREF pnDstSize AS LONG _                          ' __in int *pnDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rfc1522Decode ( _                             ' VTable offset = 64
     BYREF pszValue AS ASCIIZ _                         ' __in LPCSTR pszValue
   , BYREF pszCharset AS ASCIIZ _                       ' __in LPSTR pszCharset
   , BYVAL cchmax AS DWORD _                            ' __in ULONG cchmax
   , BYREF ppszDecoded AS DWORD _                       ' __out LPSTR *ppszDecoded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rfc1522Encode ( _                             ' VTable offset = 68
     BYREF pszValue AS ASCIIZ _                         ' __in LPCSTR pszValue
   , BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYREF ppszEncoded AS DWORD _                       ' __out LPSTR *ppszEncoded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeInternational_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeSecurity
' IID = {C5588353-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeSecurity_INTERFACE_DEFINED)
    %IMimeSecurity_INTERFACE_DEFINED = 1

'typedef BLOB THUMBBLOB;
' // Size = 8 bytes
TYPE THUMBBLOB DWORD
   cbSize    AS DWORD
   pBlobData AS BYTE PTR
END TYPE

'typedef void *HCAPICERTSTORE;

'#ifndef __WINCRYPT_H__
'typedef const void *PCX509CERT;
'typedef void *HCERTSTORE;
'#else
'typedef PCCERT_CONTEXT PCX509CERT;
'#endif
'#ifndef IMS_ALGIDDEF
'#define IMS_ALGIDDEF
'typedef unsigned int ALG_ID;

'#endif // IMS_ALGIDDEF

'// -------------------------------------------------------------------
'// ITT_* - thumbprint types
'// -------------------------------------------------------------------
'typedef DWORD ITHUMBPRINTTYPE;

%ITT_SIGNING    = &H00000001???
%ITT_ENCRYPTION = &H00000002???

'// -------------------------------------------------------------------
'// SEF_* - Secure Encoding Flags
'// must not overlap the EBF flags
'// -------------------------------------------------------------------

%SEF_ENCRYPTWITHNOSENDERCERT = &H00000001???
%SEF_SENDERSCERTPROVIDED     = &H00000002???
%SEF_NOUI                    = &H00000004???
%SEF_MASK                    = &H0000FFFF???

'// -------------------------------------------------------------------
'// EBF_* - Enchanted Broccoli Forest, also Encode Body Flags
'// must not overlap the SEF flags
'// -------------------------------------------------------------------

%EBF_RECURSE       = &H00010000???
%EBF_COMMITIFDIRTY = &H00020000???
%EBF_MASK          = &HFFFF0000???

'// -------------------------------------------------------------------
'// MSV_* - MIME Security Validity
'// -------------------------------------------------------------------

%MSV_OK                  = &H00000000???
%MSV_BADSIGNATURE        = &H00000001???
%MSV_UNVERIFIABLE        = &H00000002???
%MSV_UNKHASH             = &H00000004???
%MSV_MALFORMEDSIG        = &H00000080???
%MSV_SIGNATURE_MASK      = &H000000ff???
%MSV_EXPIRED_SIGNINGCERT = &H00000100???
%MSV_SIGNING_MASK        = &H00000f00???
%MSV_CANTDECRYPT         = &H00001000???
%MSV_ENC_FOR_EXPIREDCERT = &H00002000???
%MSV_ENCRYPT_MASK        = &H000ff000???
%MSV_INVALID             = &H01000000???
%MSV_MSG_MASK            = &H0f000000???

'// -------------------------------------------------------------------
'// MST_* - MIME Security Type
'// -------------------------------------------------------------------

%MST_NONE                         = &H00000000???
%MST_THIS_SIGN                    = &H00000001???
%MST_THIS_ENCRYPT                 = &H00000002???
%MST_THIS_BLOBSIGN                = &H00000005???  ' // %MST_BLOB_FLAG OR %MST_THIS_SIGN
%MST_CHILD_SIGN                   = &H00000100???
%MST_CHILD_ENCRYPT                = &H00000200???
%MST_SUBMSG_SIGN                  = &H00001000???
%MST_SUBMSG_ENCRYPT               = &H00002000???
%MST_THIS_MASK                    = &H000000ff???
%MST_CHILD_MASK                   = &H00000f00???
%MST_SUBMSG_MASK                  = &H0000f000???
%MST_DESCENDENT_MASK              = &H0000ff00???  ' // %MST_CHILD OR %MST_SUBMSG
%MST_SIGN_MASK                    = &H00001101???
%MST_ENCRYPT_MASK                 = &H00002202???
%MST_BLOB_FLAG                    = &H00000004???
%MST_TYPE_MASK                    = &H0000ffff???
%MST_RECEIPT_REQUEST              = &H00010000???
%MST_SUPPRESS_UI                  = &H00020000???
%MST_CLASS_SMIME_V1               = &H00000000???
%MST_CLASS_PGP                    = &H01000000???
%MST_CLASS_MASK                   = &Hff000000???

' CERTSTATE enum
%CERTIFICATE_OK             = 0
%CERTIFICATE_NOT_PRESENT    = %CERTIFICATE_OK             + 1
%CERTIFICATE_EXPIRED        = %CERTIFICATE_NOT_PRESENT    + 1
%CERTIFICATE_CHAIN_TOO_LONG = %CERTIFICATE_EXPIRED        + 1
%CERTIFICATE_MISSING_ISSUER = %CERTIFICATE_CHAIN_TOO_LONG + 1
%CERTIFICATE_CRL_LISTED     = %CERTIFICATE_MISSING_ISSUER + 1
%CERTIFICATE_NOT_TRUSTED    = %CERTIFICATE_CRL_LISTED     + 1
%CERTIFICATE_INVALID        = %CERTIFICATE_NOT_TRUSTED    + 1
%CERTIFICATE_ERROR          = %CERTIFICATE_INVALID        + 1
%CERTIFICATE_NOPRINT        = %CERTIFICATE_ERROR          + 1
%CERTIFICATE_UNKNOWN        = %CERTIFICATE_NOPRINT        + 1

' CERTNAMETYPE enum
%SIMPLE = 0
%OID    = %SIMPLE + 1
%X500   = %OID    + 1

' CERTDATAID enum
%CDID_EMAIL     = 0
%CDID_ALT_EMAIL = %CDID_EMAIL + 1
%CDID_MAX       = %CDID_ALT_EMAIL + 1

' // Size = 12 bytes
TYPE X509CERTRESULT DWORD
   cEntries AS DWORD   ' DWORD cEntries
   rgcs     AS DWORD   ' CERTSTATE *rgcs // Array of CERTSTATE values
   rgpCert  AS DWORD   ' PCX509CERT *rgpCert // PCX509CERT - Pointer to an array of CERT_CONTEXT certificate values
END TYPE

INTERFACE IMimeSecurity $IID_IMimeSecurity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckInit ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncodeMessage ( _                             ' VTable offset = 20
     BYVAL pTree AS IMimeMessageTree _                  ' __in IMimeMessageTree *const pTree
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EncodeBody ( _                                ' VTable offset = 24
     BYVAL pTree AS IMimeMessageTree _                  ' __in IMimeMessageTree *const pTree
   , BYVAL hEncodeRoot AS DWORD _                       ' __in HBODY hEncodeRoot
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecodeMessage ( _                             ' VTable offset = 28
     BYVAL pTree AS IMimeMessageTree _                  ' __in IMimeMessageTree *const pTree
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecodeBody ( _                                ' VTable offset = 32
     BYVAL pTree AS IMimeMessageTree _                  ' __in IMimeMessageTree *const pTree
   , BYVAL hDecodeRoot AS DWORD _                       ' __in HBODY hDecodeRoot
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCertificates ( _                          ' VTable offset = 36
     BYVAL hc AS DWORD _                                ' __in HCAPICERTSTORE hc
   , BYVAL dwUsage AS DWORD _                           ' __in DWORD dwUsage
   , BYVAL pPrev AS DWORD _                             ' __in PCX509CERT pPrev
   , BYREF ppCert AS DWORD _                            ' __out PCX509CERT *ppCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificateName ( _                        ' VTable offset = 40
     BYVAL pX509Cert AS DWORD _                         ' __in const PCX509CERT pX509Cert
   , BYVAL cn AS LONG _                                 ' __in const CERTNAMETYPE cn
   , BYREF ppszName AS DWORD _                          ' __out LPSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageType ( _                            ' VTable offset = 44
     BYVAL hwndParent AS DWORD _                        ' __in const HWND hwndParent
   , BYVAL pBody AS IMimeBody _                         ' __in IMimeBody *const pBody
   , BYREF pdwSecType AS DWORD _                        ' __out DWORD *const pdwSecType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertData ( _                               ' VTable offset = 48
     BYVAL pX509Cert AS DWORD _                         ' __in const PCX509CERT pX509Cert
   , BYVAL dataid AS LONG _                             ' __in const CERTDATAID dataid
   , BYREF pValue AS PROPVARIANT _                      ' __out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeSecurity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeHeaderTable
' IID = {FD853CD1-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IPersistStream
' ########################################################################################

#IF NOT %DEF(%IMimeHeaderTable_INTERFACE_DEFINED)
    %IMimeHeaderTable_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE FINDHEADER DWORD
   pszHeader  AS ASCIIZ PTR
   dwReserved AS DWORD
END TYPE

' // Size = 16 bytes
TYPE HEADERROWINFO DWORD
   dwRowNumber AS DWORD
   cboffStart  AS DWORD
   cboffColon  AS DWORD
   cboffEnd    AS DWORD
END TYPE

' HEADERTABLEFLAGS enum
%HTF_NAMEINDATA      = &H1
%HTF_ENUMHANDLESONLY = &H2


INTERFACE IMimeHeaderTable $IID_IMimeHeaderTable

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersistStream methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeHeaderTable methods
   ' =====================================================================================
   METHOD FindFirstRow ( _                              ' VTable offset = 32
     BYREF pFindHeader AS FINDHEADER _                  ' __in LPFINDHEADER pFindHeader
   , BYREF phRow AS DWORD _                             ' __out LPHHEADERROW phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNextRow ( _                               ' VTable offset = 36
     BYREF pFindHeader AS FINDHEADER _                  ' __in LPFINDHEADER pFindHeader
   , BYREF phRow AS DWORD _                             ' __out LPHHEADERROW phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountRows ( _                                 ' VTable offset = 40
     BYREF pszHeader AS ASCIIZ _                        ' __in LPCSTR pszHeader
   , BYREF pcRows AS DWORD _                            ' __out ULONG *pcRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRow ( _                                 ' VTable offset = 44
     BYREF pszHeader AS ASCIIZ _                        ' __in LPCSTR pszHeader
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszData AS ASCIIZ _                          ' __in LPCSTR pszData
   , BYVAL cchData AS DWORD _                           ' __in ULONG cchData
   , BYREF phRow AS DWORD _                             ' __out LPHHEADERROW phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteRow ( _                                 ' VTable offset = 48
     BYVAL hRow AS DWORD _                              ' __in HHEADERROW hRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowData ( _                                ' VTable offset = 52
     BYVAL hRow AS DWORD _                              ' __in HHEADERROW hRow
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppszData AS DWORD _                          ' __out LPSTR *ppszData
   , BYREF pcchData AS DWORD _                          ' __out ULONG *pcchData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRowData ( _                                ' VTable offset = 56
     BYVAL hRow AS DWORD _                              ' __in HHEADERROW hRow
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszData AS ASCIIZ _                          ' __in LPCSTR pszData
   , BYVAL cchData AS DWORD _                           ' __in ULONG cchData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowInfo ( _                                ' VTable offset = 60
     BYVAL hRow AS DWORD _                              ' __in HHEADERROW hRow
   , BYREF pInfo AS HEADERROWINFO _                     ' __in_out LPHEADERROWINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRowNumber ( _                              ' VTable offset = 64
     BYVAL hRow AS DWORD _                              ' __in HHEADERROW hRow
   , BYVAL dwRowNumber AS DWORD _                       ' __in DWORD dwRowNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRows ( _                                  ' VTable offset = 68
     BYREF pszHeader AS ASCIIZ _                        ' __in LPCSTR pszHeader
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IMimeEnumHeaderRows _              ' __out IMimeEnumHeaderRows **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 72
     BYREF ppTable AS IMimeHeaderTable _                ' __out IMimeHeaderTable **ppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeHeaderTable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimePropertySchema
' IID = {FD853CEC-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimePropertySchema_INTERFACE_DEFINED)
    %IMimePropertySchema_INTERFACE_DEFINED = 1

' MIMEPROPFLAGS enum
%MPF_INETCSET  = &H1
%MPF_RFC1522   = &H2
%MPF_ADDRESS   = &H4
%MPF_HASPARAMS = &H8
%MPF_MIME      = &H10
%MPF_READONLY  = &H20

INTERFACE IMimePropertySchema $IID_IMimePropertySchema

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterProperty ( _                          ' VTable offset = 12
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwRowNumber AS DWORD _                       ' __in DWORD dwRowNumber
   , BYVAL vtDefault AS WORD _                          ' __in VARTYPE vtDefault
   , BYREF pdwPropId AS DWORD _                         ' __out LPDWORD pdwPropId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyProperty ( _                            ' VTable offset = 16
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwRowNumber AS DWORD _                       ' __in DWORD dwRowNumber
   , BYVAL vtDefault AS WORD _                          ' __in VARTYPE vtDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyId ( _                             ' VTable offset = 20
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pdwPropId AS DWORD _                         ' __out LPDWORD pdwPropId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyName ( _                           ' VTable offset = 24
     BYVAL dwPropId AS DWORD _                          ' __in DWORD dwPropId
   , BYREF ppszName AS DWORD _                          ' __out LPSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAddressType ( _                       ' VTable offset = 28
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pdwAdrType AS DWORD _                        ' __out LPDWORD pdwAdrType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimePropertySchema_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimePropertySet
' IID = {FD853CD3-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IPersistStreamInit
' ########################################################################################

#IF NOT %DEF(%IMimePropertySet_INTERFACE_DEFINED)
    %IMimePropertySet_INTERFACE_DEFINED = 1

%PDF_ENCODED              = &H00000001???
%PDF_NAMEINDATA           = &H00000002???
%PDF_HEADERFORMAT         = &H00000004??? OR %PDF_ENCODED
%PDF_NOCOMMENTS           = &H00000008???
%PDF_SAVENOENCODE         = &H00000010???
%PDF_VECTOR               = &H00000020???

' // Size = 8 bytes
TYPE MIMEPARAMINFO DWORD
   pszName AS ASCIIZ PTR
   pszData AS ASCIIZ PTR
END TYPE

' PROPINFOMASK enum
%PIM_CHARSET      = &H1
%PIM_ENCODINGTYPE = &H2
%PIM_ROWNUMBER    = &H4
%PIM_FLAGS        = &H8
%PIM_PROPID       = &H10
%PIM_VALUES       = &H20
%PIM_VTDEFAULT    = &H40
%PIM_VTCURRENT    = &H80

' // Size = 32 bytes
TYPE MIMEPROPINFO DWORD FILL
   dwMask      AS DWORD
   hCharset    AS DWORD   ' // HCHARSET
   ietEncoding AS LONG    ' // ENCODINGTYPE enum
   dwRowNumber AS DWORD
   dwFlags     AS DWORD
   dwPropId    AS DWORD
   cValues     AS DWORD
   vtDefault   AS WORD    ' // VARTYPE
   vtCurrent   AS WORD    ' // VARTYPE
END TYPE

%EPF_NONAME = &H00000001???

INTERFACE IMimePropertySet $IID_IMimePropertySet

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimePropertySet methods
   ' =====================================================================================
   METHOD GetPropInfo ( _                               ' VTable offset = 36
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in_out LPMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropInfo ( _                               ' VTable offset = 40
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in LPCMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 44
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 48
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendProp ( _                                ' VTable offset = 52
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProp ( _                                ' VTable offset = 56
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offset = 60
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveProps ( _                                 ' VTable offset = 64
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteExcept ( _                              ' VTable offset = 68
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProp ( _                                 ' VTable offset = 72
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 76
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 80
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 84
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pcParams AS DWORD _                          ' __out ULONG *pcParams
   , BYREF pprgParam AS MIMEPARAMINFO _                 ' __out LPMIMEPARAMINFO *pprgParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 88
     BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 92
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 96
     BYREF ppPropertySet AS IMimePropertySet _          ' __out IMimePropertySet **ppPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 100
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 104
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumProps ( _                                 ' VTable offset = 108
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IMimeEnumProperties _              ' __out IMimeEnumProperties **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimePropertySet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeAddressTable
' IID = {C558834A-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeAddressTable_INTERFACE_DEFINED)
    %IMimeAddressTable_INTERFACE_DEFINED = 1

'typedef DWORD IADDRESSTYPE;

'struct  HADDRESS__
'    {
'    DWORD unused;
'    };
'typedef struct HADDRESS__ *HADDRESS;
'typedef HADDRESS *LPHADDRESS;

'TYPE HADDRESS
'   unused AS DWORD
'END TYPE

%IAT_UNKNOWN              = &H00000000???
%IAT_FROM                 = &H00000001???
%IAT_SENDER               = &H00000002???
%IAT_TO                   = &H00000004???
%IAT_CC                   = &H00000008???
%IAT_BCC                  = &H00000010???
%IAT_REPLYTO              = &H00000020???
%IAT_RETURNPATH           = &H00000040???
%IAT_RETRCPTTO            = &H00000080???
%IAT_RR                   = &H00000100???
%IAT_APPARTO              = &H00000200???
%IAT_ALL                  = &HFFFFFFFF???
%IAT_KNOWN                = %IAT_FROM OR %IAT_TO OR %IAT_CC OR %IAT_BCC OR %IAT_REPLYTO OR %IAT_SENDER
%IAT_RECIPS               = %IAT_TO OR %IAT_CC OR %IAT_BCC

' ADDRESSFORMAT enum
%AFT_DISPLAY_FRIENDLY = 0
%AFT_DISPLAY_EMAIL    = %AFT_DISPLAY_FRIENDLY + 1
%AFT_DISPLAY_BOTH     = %AFT_DISPLAY_EMAIL    + 1
%AFT_RFC822_DECODED   = %AFT_DISPLAY_BOTH     + 1
%AFT_RFC822_ENCODED   = %AFT_RFC822_DECODED   + 1
%AFT_RFC822_TRANSMIT  = %AFT_RFC822_ENCODED   + 1

%IAP_CHARSET              = &H00000001???
%IAP_HANDLE               = &H00000002???
%IAP_ADRTYPE              = &H00000004???
%IAP_FRIENDLY             = &H00000008???
%IAP_EMAIL                = &H00000020???
%IAP_CERTSTATE            = &H00000100???
%IAP_SIGNING_PRINT        = &H00000200???
%IAP_ENCRYPTION_PRINT     = &H00000400???
%IAP_ENCODING             = &H00000800???
%IAP_COOKIE               = &H00001000???
%IAP_FRIENDLYW            = &H00002000???
%IAP_ALL                  = &HFFFFFFFF???

' // Size = 64 bytes
TYPE ADDRESSPROPS DWORD
   dwProps      AS DWORD
   hAddress     AS DWORD           ' // HADDRESS
   ietFriendly  AS LONG            ' // ENCODINGTYPE enum
   hCharset     AS DWORD           ' // HCHARSET
   dwAdrType    AS DWORD
   pszFriendly  AS ASCIIZ PTR      ' // LPSTR
   pszFriendlyW AS WSTRINGZ PTR    ' // LPWSTR
   pszEmail     AS ASCIIZ PTR      ' // LPSTR
   certstate    AS LONG            ' // CERTSTATE enum
   tbSigning    AS THUMBBLOB
   tbEncryption AS THUMBBLOB
   dwCookie     AS DWORD
   dwReserved1  AS DWORD
   dwReserved2  AS DWORD
END TYPE

' // Size = 8 bytes
TYPE ADDRESSLIST DWORD
   cAdrs  AS DWORD
   prgAdr AS ADDRESSPROPS PTR
END TYPE

INTERFACE IMimeAddressTable $IID_IMimeAddressTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 12
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietFriendly AS LONG _                        ' __in ENCODINGTYPE ietFriendly
   , BYREF pszFriendly AS ASCIIZ _                      ' __in LPCSTR pszFriendly
   , BYREF pszEmail AS ASCIIZ _                         ' __in LPCSTR pszEmail
   , BYREF phAddress AS DWORD _                         ' __out LPHADDRESS phAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 16
     BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   , BYREF phAddress AS DWORD _                         ' __out LPHADDRESS phAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offset = 20
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   , BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offset = 24
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   , BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSender ( _                                 ' VTable offset = 28
     BYREF pAddress AS ADDRESSPROPS _                   ' __in_out LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountTypes ( _                                ' VTable offset = 32
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYREF pcAdrs AS DWORD _                            ' __out ULONG *pcAdrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypes ( _                                  ' VTable offset = 36
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumTypes ( _                                 ' VTable offset = 40
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF ppEnum AS IMimeEnumAddressTypes _            ' __out IMimeEnumAddressTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 44
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTypes ( _                               ' VTable offset = 48
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 52
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppszFormat AS DWORD _                        ' __out LPSTR *ppszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRfc822 ( _                              ' VTable offset = 56
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszRfc822Adr AS ASCIIZ _                     ' __in LPCSTR pszRfc822Adr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseRfc822 ( _                               ' VTable offset = 60
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszRfc822Adr AS ASCIIZ _                     ' __in LPCSTR pszRfc822Adr
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 64
     BYREF ppTable AS IMimeAddressTable _               ' __out IMimeAddressTable **ppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 68
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeAddressTable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeAddressTableW
' IID = {11C8D742-0FB4-11D3-A01E-00A0C90C9BB6}
' Inherited interface = IMimeAddressTable
' ########################################################################################

#IF NOT %DEF(%IMimeAddressTableW_INTERFACE_DEFINED)
    %IMimeAddressTableW_INTERFACE_DEFINED = 1

INTERFACE IMimeAddressTableW $IID_IMimeAddressTableW

   INHERIT IUnknown

   ' =====================================================================================
   ' IMimeAddressTable Methods
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 12
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietFriendly AS LONG _                        ' __in ENCODINGTYPE ietFriendly
   , BYREF pszFriendly AS ASCIIZ _                      ' __in LPCSTR pszFriendly
   , BYREF pszEmail AS ASCIIZ _                         ' __in LPCSTR pszEmail
   , BYREF phAddress AS DWORD _                         ' __out LPHADDRESS phAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 16
     BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   , BYREF phAddress AS DWORD _                         ' __out LPHADDRESS phAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offset = 20
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   , BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offset = 24
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   , BYREF pAddress AS ADDRESSPROPS _                   ' __in LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSender ( _                                 ' VTable offset = 28
     BYREF pAddress AS ADDRESSPROPS _                   ' __in_out LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountTypes ( _                                ' VTable offset = 32
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYREF pcAdrs AS DWORD _                            ' __out ULONG *pcAdrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypes ( _                                  ' VTable offset = 36
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumTypes ( _                                 ' VTable offset = 40
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF ppEnum AS IMimeEnumAddressTypes _            ' __out IMimeEnumAddressTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 44
     BYVAL hAddress AS DWORD _                          ' __in HADDRESS hAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTypes ( _                               ' VTable offset = 48
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 52
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppszFormat AS DWORD _                        ' __out LPSTR *ppszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRfc822 ( _                              ' VTable offset = 56
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszRfc822Adr AS ASCIIZ _                     ' __in LPCSTR pszRfc822Adr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseRfc822 ( _                               ' VTable offset = 60
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszRfc822Adr AS ASCIIZ _                     ' __in LPCSTR pszRfc822Adr
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 64
     BYREF ppTable AS IMimeAddressTable _               ' __out IMimeAddressTable **ppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 68
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeAddressTableW Methods
   ' =====================================================================================
   METHOD AppendW ( _                                   ' VTable offset = 72
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietFriendly AS LONG _                        ' __in ENCODINGTYPE ietFriendly
   , BYREF pwszFriendly AS DWORD _                      ' __in LPCWSTR *pwszFriendly
   , BYREF pwszEmail AS DWORD _                         ' __in LPCWSTR *pwszEmail
   , BYREF phAddress AS DWORD _                         ' __inout LPHADDRESS phAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormatW ( _                                ' VTable offset = 76
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppwszFormat AS DWORD _                       ' __out LPWSTR **ppwszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRfc822W ( _                             ' VTable offset = 80
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pwszRfc822Adr AS DWORD _                     ' __in LPCWSTR *pwszRfc822Adr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseRfc822W ( _                              ' VTable offset = 84
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYREF pwszRfc822Adr AS DWORD _                     ' __in LPCWSTR *pwszRfc822Adr
   , BYREF pList AS ADDRESSLIST _                       ' __inout ADDRESSLIST *pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeAddressTableW_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeWebDocument
' IID = {EE519F11-851A-11D0-825C-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeWebDocument_INTERFACE_DEFINED)
    %IMimeWebDocument_INTERFACE_DEFINED = 1

INTERFACE IMimeWebDocument $IID_IMimeWebDocument

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetURL ( _                                    ' VTable offset = 12
     BYREF ppszURL AS DWORD _                           ' __out LPSTR *ppszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStorage ( _                             ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeWebDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeBody
' IID = {C558834C-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IMimePropertySet
' ########################################################################################

#IF NOT %DEF(%IMimeBody_INTERFACE_DEFINED)
    %IMimeBody_INTERFACE_DEFINED = 1

' IMSGBODYTYPE enum
%IBT_SECURE     = 0
%IBT_ATTACHMENT = %IBT_SECURE     + 1
%IBT_EMPTY      = %IBT_ATTACHMENT + 1
%IBT_CSETTAGGED = %IBT_EMPTY      + 1
%IBT_AUTOATTACH = %IBT_CSETTAGGED + 1

' // Size = 16 bytes
TYPE BODYOFFSETS DWORD
   cbBoundaryStart AS DWORD
   cbHeaderStart   AS DWORD
   cbBodyStart     AS DWORD
   cbBodyEnd       AS DWORD
END TYPE

' // Size = 32 bytes
TYPE TRANSMITINFO DWORD
   ietCurrent    AS LONG    ' // ENCODINGTYPE
   ietXmitMime   AS LONG    ' // ENCODINGTYPE
   ietXmit822    AS LONG    ' // ENCODINGTYPE
   cbLongestLine AS DWORD
   cExtended     AS DWORD
   ulPercentExt  AS DWORD
   cbSize        AS DWORD
   cLines        AS DWORD
END TYPE

INTERFACE IMimeBody $IID_IMimeBody

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimePropertySet methods
   ' =====================================================================================
   METHOD GetPropInfo ( _                               ' VTable offset = 36
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in_out LPMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropInfo ( _                               ' VTable offset = 40
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in LPCMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 44
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 48
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendProp ( _                                ' VTable offset = 52
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProp ( _                                ' VTable offset = 56
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offset = 60
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveProps ( _                                 ' VTable offset = 64
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteExcept ( _                              ' VTable offset = 68
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProp ( _                                 ' VTable offset = 72
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 76
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 80
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 84
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pcParams AS DWORD _                          ' __out ULONG *pcParams
   , BYREF pprgParam AS MIMEPARAMINFO _                 ' __out LPMIMEPARAMINFO *pprgParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 88
     BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 92
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 96
     BYREF ppPropertySet AS IMimePropertySet _          ' __out IMimePropertySet **ppPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 100
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 104
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumProps ( _                                 ' VTable offset = 108
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IMimeEnumProperties _              ' __out IMimeEnumProperties **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeBody methods
   ' =====================================================================================
   METHOD IsType ( _                                    ' VTable offset = 112
     BYVAL bodytype AS LONG _                           ' __in IMSGBODYTYPE bodytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 116
     BYREF pszDisplay AS ASCIIZ _                       ' __in LPCSTR pszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 120
     BYREF ppszDisplay AS DWORD _                       ' __out LPSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOffsets ( _                                ' VTable offset = 124
     BYREF pOffsets AS BODYOFFSETS _                    ' __out LPBODYOFFSETS pOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentEncoding ( _                        ' VTable offset = 128
     BYREF pietEncoding AS LONG _                       ' __out ENCODINGTYPE *pietEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentEncoding ( _                        ' VTable offset = 132
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEstimatedSize ( _                          ' VTable offset = 136
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataHere ( _                               ' VTable offset = 140
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 144
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 148
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pvObject AS IUnknown _                       ' __in LPVOID pvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EmptyData ( _                                 ' VTable offset = 152
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 156
     BYVAL pBody AS IMimeBody _                         ' __in IMimeBody *pBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransmitInfo ( _                           ' VTable offset = 160
     BYREF pTransmitInfo AS TRANSMITINFO _              ' __in_out LPTRANSMITINFO pTransmitInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveToFile ( _                                ' VTable offset = 164
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 168
     BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeBody_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeBodyW
' IID = {2F38042B-D02F-11D2-A004-00A0C90C9BB6}
' Inherited interface = IMimeBody
' ########################################################################################

#IF NOT %DEF(%IMimeBodyW_INTERFACE_DEFINED)
    %IMimeBodyW_INTERFACE_DEFINED = 1

INTERFACE IMimeBodyW $IID_IMimeBodyW

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimePropertySet methods
   ' =====================================================================================
   METHOD GetPropInfo ( _                               ' VTable offset = 36
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in_out LPMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropInfo ( _                               ' VTable offset = 40
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pInfo AS MIMEPROPINFO _                      ' __in LPCMIMEPROPINFO pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 44
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 48
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendProp ( _                                ' VTable offset = 52
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProp ( _                                ' VTable offset = 56
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offset = 60
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveProps ( _                                 ' VTable offset = 64
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   , BYVAL pPropertySet AS IMimePropertySet _           ' __in IMimePropertySet *pPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteExcept ( _                              ' VTable offset = 68
     BYVAL cNames AS DWORD _                            ' __in ULONG cNames
   , BYREF prgszName AS ASCIIZ _                        ' __in LPCSTR *prgszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProp ( _                                 ' VTable offset = 72
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 76
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 80
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 84
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pcParams AS DWORD _                          ' __out ULONG *pcParams
   , BYREF pprgParam AS MIMEPARAMINFO _                 ' __out LPMIMEPARAMINFO *pprgParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 88
     BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 92
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 96
     BYREF ppPropertySet AS IMimePropertySet _          ' __out IMimePropertySet **ppPropertySet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 100
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 104
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumProps ( _                                 ' VTable offset = 108
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IMimeEnumProperties _              ' __out IMimeEnumProperties **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeBody methods
   ' =====================================================================================
   METHOD IsType ( _                                    ' VTable offset = 112
     BYVAL bodytype AS LONG _                           ' __in IMSGBODYTYPE bodytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 116
     BYREF pszDisplay AS ASCIIZ _                       ' __in LPCSTR pszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 120
     BYREF ppszDisplay AS DWORD _                       ' __out LPSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOffsets ( _                                ' VTable offset = 124
     BYREF pOffsets AS BODYOFFSETS _                    ' __out LPBODYOFFSETS pOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentEncoding ( _                        ' VTable offset = 128
     BYREF pietEncoding AS LONG _                       ' __out ENCODINGTYPE *pietEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentEncoding ( _                        ' VTable offset = 132
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEstimatedSize ( _                          ' VTable offset = 136
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataHere ( _                               ' VTable offset = 140
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 144
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 148
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pvObject AS IUnknown _                       ' __in LPVOID pvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EmptyData ( _                                 ' VTable offset = 152
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 156
     BYVAL pBody AS IMimeBody _                         ' __in IMimeBody *pBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransmitInfo ( _                           ' VTable offset = 160
     BYREF pTransmitInfo AS TRANSMITINFO _              ' __in_out LPTRANSMITINFO pTransmitInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveToFile ( _                                ' VTable offset = 164
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 168
     BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeBodyW Methods
   ' =====================================================================================
   METHOD SetDisplayNameW ( _                           ' VTable offset = 172
     BYREF pwszDisplay AS DWORD _                       ' __in LPCWSTR *pwszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayNameW ( _                           ' VTable offset = 176
     BYREF ppwszDisplay AS DWORD _                      ' __out LPWSTR **ppwszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataW ( _                                  ' VTable offset = 180
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pwszPriType AS DWORD _                       ' __in LPCWSTR *pwszPriType
   , BYREF pwszSubType AS DWORD _                       ' __in LPCWSTR *pwszSubType
   , BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYVAL pvObject AS DWORD _                          ' __in LPVOID pvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveToFileW ( _                               ' VTable offset = 184
     BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF pwszFilePath AS DWORD _                      ' __in LPCWSTR *pwszFilePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeBodyW_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeMessageTree
' IID = {FD853CD4-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IPersistStreamInit
' ########################################################################################

#IF NOT %DEF(%IMimeMessageTree_INTERFACE_DEFINED)
    %IMimeMessageTree_INTERFACE_DEFINED = 1

%HBODY_ROOT = &HFFFFFFFF???   ' ( ( HBODY  )-1 )

' BODYLOCATION enum
%IBL_ROOT     = 0
%IBL_PARENT   = %IBL_ROOT   + 1
%IBL_FIRST    = %IBL_PARENT + 1
%IBL_LAST     = %IBL_FIRST  + 1
%IBL_NEXT     = %IBL_LAST   + 1
%IBL_PREVIOUS = %IBL_NEXT   + 1

' // Size = 12 bytes
TYPE FINDBODY DWORD
   pszPriType AS ASCIIZ PTR
   pszSubType AS ASCIIZ PTR
   dwReserved AS DWORD
END TYPE

%COMMIT_ONLYIFDIRTY         = &H00000001???
%COMMIT_REUSESTORAGE        = &H00000002???
%COMMIT_SMIMETRANSFERENCODE = &H00000004???
%SAVEBODY_KEEPBOUNDARY      = &H00000001???
%DELETE_PROMOTE_CHILDREN    = &H00000001???
%DELETE_CHILDREN_ONLY       = &H00000002???

INTERFACE IMimeMessageTree $IID_IMimeMessageTree

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessageTree methods
   ' =====================================================================================
   METHOD GetMessageSource ( _                          ' VTable offset = 36
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageSize ( _                            ' VTable offset = 40
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadOffsetTable ( _                           ' VTable offset = 44
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveOffsetTable ( _                           ' VTable offset = 48
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 52
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffStorage ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 64
     BYVAL hBody AS DWORD _                             ' __in const HBODY hBody
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveBody ( _                                  ' VTable offset = 68
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertBody ( _                                ' VTable offset = 72
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 76
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBody ( _                                ' VTable offset = 80
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveBody ( _                                  ' VTable offset = 84
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL location AS LONG _                           ' __in BODYLOCATION location
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountBodies ( _                               ' VTable offset = 88
     BYVAL hParent AS DWORD _                           ' __in HBODY hParent
   , BYVAL fRecurse AS BYTE _                           ' __in boolean fRecurse
   , BYREF pcBodies AS DWORD _                          ' __out ULONG *pcBodies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFirst ( _                                 ' VTable offset = 92
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNext ( _                                  ' VTable offset = 96
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveURL ( _                                ' VTable offset = 100
     BYVAL hRelated AS DWORD _                          ' __in HBODY hRelated
   , BYREF pszBase AS ASCIIZ _                          ' __in LPCSTR pszBase
   , BYREF pszURL AS ASCIIZ _                           ' __in LPCSTR pszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ToMultipart ( _                               ' VTable offset = 104
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   , BYREF phMultipart AS DWORD _                       ' __out LPHBODY phMultipart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyOffsets ( _                            ' VTable offset = 108
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pOffsets AS BODYOFFSETS _                    ' __in_out LPBODYOFFSETS pOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 112
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 116
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsBodyType ( _                                ' VTable offset = 120
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL bodytype AS LONG _                           ' __in IMSGBODYTYPE bodytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 124
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryBodyProp ( _                             ' VTable offset = 128
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyProp ( _                               ' VTable offset = 132
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBodyProp ( _                               ' VTable offset = 136
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBodyProp ( _                            ' VTable offset = 140
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 144
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 148
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeMessageTree_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeMessage
' IID = {FD853CD5-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IMimeMessageTree
' ########################################################################################

#IF NOT %DEF(%IMimeMessage_INTERFACE_DEFINED)
    %IMimeMessage_INTERFACE_DEFINED = 1

'typedef DWORD TEXTTYPE;

' IMSGFLAGS enum
%IMF_ATTACHMENTS  = &H1
%IMF_MULTIPART    = &H2
%IMF_SUBMULTIPART = &H4
%IMF_MIME         = &H8
%IMF_HTML         = &H10
%IMF_PLAIN        = &H20
%IMF_PARTIAL      = &H40
%IMF_SIGNED       = &H80
%IMF_ENCRYPTED    = &H100
%IMF_TNEF         = &H200
%IMF_MHTML        = &H400
%IMF_SECURE       = &H800
%IMF_TEXT         = &H1000
%IMF_CSETTAGGED   = &H2000
%IMF_NEWS         = &H4000
%IMF_VOICEMAIL    = &H8000
%IMF_HASVCARD     = &H10000
%IMF_RFC1154      = &H20000

' IMSGPRIORITY enum
%IMSG_PRI_LOW    = 5
%IMSG_PRI_NORMAL = 3
%IMSG_PRI_HIGH   = 1

%WPF_HTML          = &H00000001???
%WPF_AUTOINLINE    = &H00000002???
%WPF_SLIDESHOW     = &H00000004???
%WPF_ATTACHLINKS   = &H00000008???
%WPF_IMAGESONLY    = &H00000010???
%WPF_NOMETACHARSET = &H00000020???
%WPF_TEXTONLY      = &H00000040???

' // Size = 20 bytes
TYPE WEBPAGEOPTIONS DWORD
   cbSize       AS DWORD
   dwFlags      AS DWORD
   dwDelay      AS DWORD
   wchQuote     AS WORD    ' // WCHAR
   fQuoteSpaces AS LONG    ' BOOL
END TYPE

%TXT_PLAIN               = &H00000001???
%TXT_HTML                = &H00000002???
%URL_ATTACH_INTO_MIXED   = &H00000001???
%URL_ATTACH_GENERATE_CID = &H00000002???
%URL_ATTACH_SET_CNTTYPE  = &H00000004???
%URL_RESOLVE_RENDERED    = &H00000001???
%URL_RESULVE_NO_BASE     = &H00000002???

INTERFACE IMimeMessage $IID_IMimeMessage

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessageTree methods
   ' =====================================================================================
   METHOD GetMessageSource ( _                          ' VTable offset = 36
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageSize ( _                            ' VTable offset = 40
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadOffsetTable ( _                           ' VTable offset = 44
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveOffsetTable ( _                           ' VTable offset = 48
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 52
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffStorage ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 64
     BYVAL hBody AS DWORD _                             ' __in const HBODY hBody
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveBody ( _                                  ' VTable offset = 68
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertBody ( _                                ' VTable offset = 72
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 76
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBody ( _                                ' VTable offset = 80
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveBody ( _                                  ' VTable offset = 84
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL location AS LONG _                           ' __in BODYLOCATION location
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountBodies ( _                               ' VTable offset = 88
     BYVAL hParent AS DWORD _                           ' __in HBODY hParent
   , BYVAL fRecurse AS BYTE _                           ' __in boolean fRecurse
   , BYREF pcBodies AS DWORD _                          ' __out ULONG *pcBodies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFirst ( _                                 ' VTable offset = 92
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNext ( _                                  ' VTable offset = 96
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveURL ( _                                ' VTable offset = 100
     BYVAL hRelated AS DWORD _                          ' __in HBODY hRelated
   , BYREF pszBase AS ASCIIZ _                          ' __in LPCSTR pszBase
   , BYREF pszURL AS ASCIIZ _                           ' __in LPCSTR pszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ToMultipart ( _                               ' VTable offset = 104
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   , BYREF phMultipart AS DWORD _                       ' __out LPHBODY phMultipart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyOffsets ( _                            ' VTable offset = 108
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pOffsets AS BODYOFFSETS _                    ' __in_out LPBODYOFFSETS pOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 112
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 116
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsBodyType ( _                                ' VTable offset = 120
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL bodytype AS LONG _                           ' __in IMSGBODYTYPE bodytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 124
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryBodyProp ( _                             ' VTable offset = 128
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyProp ( _                               ' VTable offset = 132
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBodyProp ( _                               ' VTable offset = 136
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBodyProp ( _                            ' VTable offset = 140
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 144
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 148
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessage methods
   ' =====================================================================================
   METHOD CreateWebPage ( _                             ' VTable offset = 152
     BYVAL pRootStm AS IStream _                        ' __in IStream *pRootStm
   , BYREF pOptions AS WEBPAGEOPTIONS _                 ' __in LPWEBPAGEOPTIONS pOptions
   , BYVAL pCallback AS IMimeMessageCallback _          ' __in IMimeMessageCallback *pCallback
   , BYREF ppMoniker AS IMoniker _                      ' __out IMoniker **ppMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 156
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 160
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProp ( _                                ' VTable offset = 164
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProp ( _                                 ' VTable offset = 168
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextBody ( _                               ' VTable offset = 172
     BYVAL dwTxtType AS DWORD _                         ' __in DWORD dwTxtType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextBody ( _                               ' VTable offset = 176
     BYVAL dwTxtType AS DWORD _                         ' __in DWORD dwTxtType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYVAL hAlternative AS DWORD _                      ' __in HBODY hAlternative
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 180
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pvObject AS IUnknown _                       ' __in void *pvObject
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachFile ( _                                ' VTable offset = 184
     BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   , BYVAL pstmFile AS IStream _                        ' __in IStream *pstmFile
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachURL ( _                                 ' VTable offset = 188
     BYREF pszBase AS ASCIIZ _                          ' __in LPCSTR pszBase
   , BYREF pszURL AS ASCIIZ _                           ' __in LPCSTR pszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pstmURL AS IStream _                         ' __in IStream *pstmURL
   , BYREF ppszCIDURL AS DWORD _                        ' __out LPSTR *ppszCIDURL
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachments ( _                            ' VTable offset = 192
     BYREF pcAttach AS DWORD _                          ' __out ULONG *pcAttach
   , BYREF pprghAttach AS DWORD _                       ' __out LPHBODY *pprghAttach
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressTable ( _                           ' VTable offset = 196
     BYREF ppTable AS IMimeAddressTable _               ' __out IMimeAddressTable **ppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSender ( _                                 ' VTable offset = 200
     BYREF pAddress AS ADDRESSPROPS _                   ' __in_out LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressTypes ( _                           ' VTable offset = 204
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressFormat ( _                          ' VTable offset = 208
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppszFormat AS DWORD _                        ' __out LPSTR *ppszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAddressTypes ( _                          ' VTable offset = 212
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF ppEnum AS IMimeEnumAddressTypes _            ' __out IMimeEnumAddressTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SplitMessage ( _                              ' VTable offset = 216
     BYVAL cbMaxPart AS DWORD _                         ' __in ULONG cbMaxPart
   , BYREF ppParts AS IMimeMessageParts _               ' __out IMimeMessageParts **ppParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootMoniker ( _                            ' VTable offset = 220
     BYREF ppMoniker AS IMoniker _                      ' __out IMoniker **ppMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeMessage_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeMessageW
' IID = {F90ADFEF-D01F-11D2-A004-00A0C90C9BB6}
' Inherited interface = IMimeMessage
' ########################################################################################

#IF NOT %DEF(%IMimeMessageW_INTERFACE_DEFINED)
    %IMimeMessageW_INTERFACE_DEFINED = 1

INTERFACE IMimeMessageW $IID_IMimeMessageW

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistStreamInit methods
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pStm AS IStream _                            ' __in IStream * pStm
   , BYVAL fClearDirty AS LONG _                        ' __in BOOL fClearDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSizeMax ( _                                ' VTable offset = 28
     BYREF pcbSize AS QUAD _                            ' __out  ULARGE_INTEGER * pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessageTree methods
   ' =====================================================================================
   METHOD GetMessageSource ( _                          ' VTable offset = 36
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageSize ( _                            ' VTable offset = 40
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadOffsetTable ( _                           ' VTable offset = 44
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveOffsetTable ( _                           ' VTable offset = 48
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 52
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandsOffStorage ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 64
     BYVAL hBody AS DWORD _                             ' __in const HBODY hBody
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveBody ( _                                  ' VTable offset = 68
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertBody ( _                                ' VTable offset = 72
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBody ( _                                   ' VTable offset = 76
     BYVAL location AS LONG _                           ' __in BODYLOCATION location
   , BYVAL hPivot AS DWORD _                            ' __in HBODY hPivot
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBody ( _                                ' VTable offset = 80
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveBody ( _                                  ' VTable offset = 84
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL location AS LONG _                           ' __in BODYLOCATION location
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountBodies ( _                               ' VTable offset = 88
     BYVAL hParent AS DWORD _                           ' __in HBODY hParent
   , BYVAL fRecurse AS BYTE _                           ' __in boolean fRecurse
   , BYREF pcBodies AS DWORD _                          ' __out ULONG *pcBodies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFirst ( _                                 ' VTable offset = 92
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNext ( _                                  ' VTable offset = 96
     BYREF pFindBody AS FINDBODY _                      ' __in_out LPFINDBODY pFindBody
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveURL ( _                                ' VTable offset = 100
     BYVAL hRelated AS DWORD _                          ' __in HBODY hRelated
   , BYREF pszBase AS ASCIIZ _                          ' __in LPCSTR pszBase
   , BYREF pszURL AS ASCIIZ _                           ' __in LPCSTR pszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ToMultipart ( _                               ' VTable offset = 104
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   , BYREF phMultipart AS DWORD _                       ' __out LPHBODY phMultipart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyOffsets ( _                            ' VTable offset = 108
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pOffsets AS BODYOFFSETS _                    ' __in_out LPBODYOFFSETS pOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharset ( _                                ' VTable offset = 112
     BYREF phCharset AS DWORD _                         ' __out LPHCHARSET phCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCharset ( _                                ' VTable offset = 116
     BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYVAL applytype AS LONG _                          ' __in CSETAPPLYTYPE applytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsBodyType ( _                                ' VTable offset = 120
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYVAL bodytype AS LONG _                           ' __in IMSGBODYTYPE bodytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsContentType ( _                             ' VTable offset = 124
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszPriType AS ASCIIZ _                       ' __in LPCSTR pszPriType
   , BYREF pszSubType AS ASCIIZ _                       ' __in LPCSTR pszSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryBodyProp ( _                             ' VTable offset = 128
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBodyProp ( _                               ' VTable offset = 132
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBodyProp ( _                               ' VTable offset = 136
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteBodyProp ( _                            ' VTable offset = 140
     BYVAL hBody AS DWORD _                             ' __in HBODY hBody
   , BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 144
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOption ( _                                 ' VTable offset = 148
     BYVAL oid AS DWORD _                               ' __in const TYPEDID oid
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessage methods
   ' =====================================================================================
   METHOD CreateWebPage ( _                             ' VTable offset = 152
     BYVAL pRootStm AS IStream _                        ' __in IStream *pRootStm
   , BYREF pOptions AS WEBPAGEOPTIONS _                 ' __in LPWEBPAGEOPTIONS pOptions
   , BYVAL pCallback AS IMimeMessageCallback _          ' __in IMimeMessageCallback *pCallback
   , BYREF ppMoniker AS IMoniker _                      ' __out IMoniker **ppMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 156
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProp ( _                                   ' VTable offset = 160
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProp ( _                                ' VTable offset = 164
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryProp ( _                                 ' VTable offset = 168
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   , BYREF pszCriteria AS ASCIIZ _                      ' __in LPCSTR pszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextBody ( _                               ' VTable offset = 172
     BYVAL dwTxtType AS DWORD _                         ' __in DWORD dwTxtType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextBody ( _                               ' VTable offset = 176
     BYVAL dwTxtType AS DWORD _                         ' __in DWORD dwTxtType
   , BYVAL ietEncoding AS LONG _                        ' __in ENCODINGTYPE ietEncoding
   , BYVAL hAlternative AS DWORD _                      ' __in HBODY hAlternative
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachObject ( _                              ' VTable offset = 180
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pvObject AS IUnknown _                       ' __in void *pvObject
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachFile ( _                                ' VTable offset = 184
     BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   , BYVAL pstmFile AS IStream _                        ' __in IStream *pstmFile
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachURL ( _                                 ' VTable offset = 188
     BYREF pszBase AS ASCIIZ _                          ' __in LPCSTR pszBase
   , BYREF pszURL AS ASCIIZ _                           ' __in LPCSTR pszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pstmURL AS IStream _                         ' __in IStream *pstmURL
   , BYREF ppszCIDURL AS DWORD _                        ' __out LPSTR *ppszCIDURL
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttachments ( _                            ' VTable offset = 192
     BYREF pcAttach AS DWORD _                          ' __out ULONG *pcAttach
   , BYREF pprghAttach AS DWORD _                       ' __out LPHBODY *pprghAttach
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressTable ( _                           ' VTable offset = 196
     BYREF ppTable AS IMimeAddressTable _               ' __out IMimeAddressTable **ppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSender ( _                                 ' VTable offset = 200
     BYREF pAddress AS ADDRESSPROPS _                   ' __in_out LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressTypes ( _                           ' VTable offset = 204
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressFormat ( _                          ' VTable offset = 208
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppszFormat AS DWORD _                        ' __out LPSTR *ppszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAddressTypes ( _                          ' VTable offset = 212
     BYVAL dwAdrTypes AS DWORD _                        ' __in DWORD dwAdrTypes
   , BYVAL dwProps AS DWORD _                           ' __in DWORD dwProps
   , BYREF ppEnum AS IMimeEnumAddressTypes _            ' __out IMimeEnumAddressTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SplitMessage ( _                              ' VTable offset = 216
     BYVAL cbMaxPart AS DWORD _                         ' __in ULONG cbMaxPart
   , BYREF ppParts AS IMimeMessageParts _               ' __out IMimeMessageParts **ppParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootMoniker ( _                            ' VTable offset = 220
     BYREF ppMoniker AS IMoniker _                      ' __out IMoniker **ppMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeMessageW Methods
   ' =====================================================================================
   METHOD GetPropW ( _                                  ' VTable offset = 224
     BYREF pwszName AS DWORD _                          ' __in LPCWSTR *pwszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in_out LPPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropW ( _                                  ' VTable offset = 228
     BYREF pwszName AS DWORD _                          ' __in LPCWSTR *pwszName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValue AS PROPVARIANT _                      ' __in LPCPROPVARIANT pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePropW ( _                               ' VTable offset = 232
     BYREF pwszName AS DWORD _                          ' __in LPCWSTR *pwszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPropW ( _                                ' VTable offset = 236
     BYREF pwszName AS DWORD _                          ' __in LPCWSTR *pwszName
   , BYREF pwszCriteria AS DWORD _                      ' __in LPCWSTR *pwszCriteria
   , BYVAL fSubString AS BYTE _                         ' __in boolean fSubString
   , BYVAL fCaseSensitive AS BYTE _                     ' __in boolean fCaseSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachFileW ( _                               ' VTable offset = 240
     BYREF pwszFilePath AS DWORD _                      ' __in LPCWSTR *pwszFilePath
   , BYVAL pstmFile AS IStream _                        ' __in IStream *pstmFile
   , BYREF phBody AS DWORD _                            ' __inout LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachURLW ( _                                ' VTable offset = 244
     BYREF pwszBase AS DWORD _                          ' __in LPCWSTR *pwszBase
   , BYREF pwszURL AS DWORD _                           ' __in LPCWSTR *pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pstmURL AS IStream _                         ' __in IStream *pstmURL
   , BYREF ppwszCIDURL AS DWORD _                       ' __out LPWSTR *ppwszCIDURL
   , BYREF phBody AS DWORD _                            ' __out LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddressFormatW ( _                         ' VTable offset = 248
     BYVAL dwAdrType AS DWORD _                         ' __in DWORD dwAdrType
   , BYVAL format AS LONG _                             ' __in ADDRESSFORMAT format
   , BYREF ppwszFormat AS DWORD _                       ' __out LPWSTR *ppwszFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveURLW ( _                               ' VTable offset = 252
     BYVAL hRelated AS DWORD _                          ' __in HBODY hRelated hRelated
   , BYREF pwszBase AS DWORD _                          ' __in LPCWSTR *pwszBase
   , BYREF pwszURL AS DWORD _                           ' __in LPCWSTR *pwszURL
   , BYREF dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF phBody AS DWORD _                            ' __inout LPHBODY phBody
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeMessageW_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeMessageCallback
' IID = {761AA641-7BDA-11D1-8AA9-00C04FB951F3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeMessageCallback_INTERFACE_DEFINED)
    %IMimeMessageCallback_INTERFACE_DEFINED = 1

INTERFACE IMimeMessageCallback $IID_IMimeMessageCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnWebPageSplitter ( _                         ' VTable offset = 12
     BYVAL cInlined AS DWORD _                          ' __in DWORD cInlined
   , BYVAL ppStream AS IStream _                        ' __in IStream *ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeMessageCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPersistMime
' IID = {DE4AD8DA-555F-11D1-8DD0-00C04FB951F9}
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistMime_INTERFACE_DEFINED)
    %IPersistMime_INTERFACE_DEFINED = 1

%PMS_HTML = &H00000001???
%PMS_TEXT = &H00000002???

INTERFACE IPersistMime $IID_IPersistMime

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistMime methods
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 16
     BYVAL pMsg AS IMimeMessage _                       ' __in IMimeMessage *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 20
     BYVAL pMsg AS IMimeMessage _                       ' __in IMimeMessage *pMsg
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistMime_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeMessageParts
' IID = {C558834F-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeMessageParts_INTERFACE_DEFINED)
    %IMimeMessageParts_INTERFACE_DEFINED = 1

INTERFACE IMimeMessageParts $IID_IMimeMessageParts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CombineParts ( _                              ' VTable offset = 12
     BYREF ppMessage AS IMimeMessage _                  ' __out IMimeMessage **ppMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPart ( _                                   ' VTable offset = 16
     BYVAL pMessage AS IMimeMessage _                   ' __in IMimeMessage *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxParts ( _                               ' VTable offset = 20
     BYVAL cParts AS DWORD _                            ' __in ULONG cParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountParts ( _                                ' VTable offset = 24
     BYREF pcParts AS DWORD _                           ' __out ULONG *pcParts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumParts ( _                                 ' VTable offset = 28
     BYREF ppEnum AS IMimeEnumMessageParts _            ' __out IMimeEnumMessageParts **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeMessageParts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEnumHeaderRows
' IID = {C558834D-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEnumHeaderRows_INTERFACE_DEFINED)
    %IMimeEnumHeaderRows_INTERFACE_DEFINED = 1

' // Size = 20 bytes
TYPE ENUMHEADERROW DWORD
   hRow       AS DWORD        ' HHEADERROW
   pszHeader  AS ASCIIZ PTR   ' LPSTR
   pszData    AS ASCIIZ PTR   ' LPSTR
   cchData    AS DWORD        ' ULONG
   dwReserved AS DWORD        ' DWORD_PTR
END TYPE

INTERFACE IMimeEnumHeaderRows $IID_IMimeEnumHeaderRows

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF prgRow AS ENUMHEADERROW _                    ' __in_out LPENUMHEADERROW prgRow
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IMimeEnumHeaderRows _              ' __out IMimeEnumHeaderRows **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 28
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEnumHeaderRows_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEnumProperties
' IID = {FD853CEE-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEnumProperties_INTERFACE_DEFINED)
    %IMimeEnumProperties_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE ENUMPROPERTY DWORD
   pszName  AS ASCIIZ PTR   ' LPSTR
   hRow     AS DWORD        ' HHEADERROW
   dwPropId AS DWORD        ' DWORD
END TYPE

INTERFACE IMimeEnumProperties $IID_IMimeEnumProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF prgProp AS ENUMPROPERTY _                    ' __in_out LPENUMPROPERTY prgProp
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IMimeEnumProperties _              ' __out IMimeEnumProperties **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 28
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEnumProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEnumAddressTypes
' IID = {C5588354-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEnumAddressTypes_INTERFACE_DEFINED)
    %IMimeEnumAddressTypes_INTERFACE_DEFINED = 1

INTERFACE IMimeEnumAddressTypes $IID_IMimeEnumAddressTypes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF prgAdr AS ADDRESSPROPS _                     ' __in_out LPADDRESSPROPS prgAdr
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IMimeEnumAddressTypes _            ' __out IMimeEnumAddressTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 28
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEnumAddressTypes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEnumMessageParts
' IID = {C5588350-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEnumMessageParts_INTERFACE_DEFINED)
    %IMimeEnumMessageParts_INTERFACE_DEFINED = 1

INTERFACE IMimeEnumMessageParts $IID_IMimeEnumMessageParts

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF prgpMessage AS IMimeMessage _                ' __in_out IMimeMessage **prgpMessage
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IMimeEnumMessageParts _            ' __out IMimeEnumMessageParts **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 28
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEnumMessageParts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHashTable
' IID = {64577981-86D7-11D1-BDFC-00C04FA31009}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHashTable_INTERFACE_DEFINED)
    %IHashTable_INTERFACE_DEFINED = 1

%HF_NO_DUPLICATES   = &H1

INTERFACE IHashTable $IID_IHashTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYVAL fDupeKeys AS LONG _                          ' __in BOOL fDupeKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 16
     BYREF psz AS ASCIIZ _                              ' __in LPSTR psz
   , BYVAL pv AS DWORD _                                ' __in LPVOID pv
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Replace ( _                                   ' VTable offset = 20
     BYREF psz AS ASCIIZ _                              ' __in LPSTR psz
   , BYVAL pv AS DWORD _                                ' __in LPVOID pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Find ( _                                      ' VTable offset = 24
     BYREF psz AS ASCIIZ _                              ' __in LPSTR psz
   , BYVAL fRemove AS LONG _                            ' __in BOOL fRemove
   , BYREF ppv AS DWORD _                               ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 32
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF prgpv AS DWORD _                             ' __in_out LPVOID **prgpv
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHashTable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeAllocator
' IID = {C5588351-7F86-11D0-8252-00C04FD85AB4}
' Inherited interface = IMalloc
' ########################################################################################

#IF NOT %DEF(%IMimeAllocator_INTERFACE_DEFINED)
    %IMimeAllocator_INTERFACE_DEFINED = 1

INTERFACE IMimeAllocator $IID_IMimeAllocator

   INHERIT IUnknown

   ' =====================================================================================
   ' IMalloc methods
   ' =====================================================================================
   METHOD Alloc ( _                                     ' VTable offset = 12
     BYVAL cb AS DWORD _                                ' __in ULONG cb
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD Realloc ( _                                   ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void * pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   ) AS DWORD                                           ' void *
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 20
     BYVAL pv AS DWORD _                                ' __in void * pv
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 24
     BYVAL pv AS DWORD _                                ' __in void * pv
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================
   METHOD DidAlloc ( _                                  ' VTable offset = 28
     BYVAL pv AS DWORD _                                ' __in void * pv
   ) AS LONG                                            ' int
   ' =====================================================================================
   METHOD HeapMinimize ( _                              ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMimeAllocator methods
   ' =====================================================================================
   METHOD FreeParamInfoArray ( _                        ' VTable offset = 36
     BYVAL cParams AS DWORD _                           ' __in ULONG cParams
   , BYREF prgParam AS MIMEPARAMINFO _                  ' __in LPMIMEPARAMINFO prgParam
   , BYVAL fFreeArray AS BYTE _                         ' __in boolean fFreeArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeAddressList ( _                           ' VTable offset = 40
     BYREF pList AS ADDRESSLIST _                       ' __in_out LPADDRESSLIST pList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeAddressProps ( _                          ' VTable offset = 44
     BYREF pAddress AS ADDRESSPROPS _                   ' __in_out LPADDRESSPROPS pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseObjects ( _                            ' VTable offset = 48
     BYVAL cObjects AS DWORD _                          ' __in ULONG cObjects
   , BYREF prgpUnknown AS IUnknown _                    ' __in IUnknown **prgpUnknown
   , BYVAL fFreeArray AS BYTE _                         ' __in boolean fFreeArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeEnumHeaderRowArray ( _                    ' VTable offset = 52
     BYVAL cRows AS DWORD _                             ' __in ULONG cRows
   , BYREF prgRow AS ENUMHEADERROW _                    ' __in LPENUMHEADERROW prgRow
   , BYVAL fFreeArray AS BYTE _                         ' __in boolean fFreeArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeEnumPropertyArray ( _                     ' VTable offset = 56
     BYVAL cProps AS DWORD _                            ' __in ULONG cProps
   , BYREF prgProp AS ENUMPROPERTY _                    ' __in LPENUMPROPERTY prgProp
   , BYVAL fFreeArray AS BYTE _                         ' __in boolean fFreeArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeThumbprint ( _                            ' VTable offset = 60
     BYREF pthumbprint AS BLOB _                        ' __in THUMBBLOB *pthumbprint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PropVariantClear ( _                          ' VTable offset = 64
     BYREF pProp AS PROPVARIANT _                       ' __in LPPROPVARIANT pProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeAllocator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeObjResolver
' IID = {FECEAFFD-C441-11D1-960E-00C04FBD7C09}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeObjResolver_INTERFACE_DEFINED)
    %IMimeObjResolver_INTERFACE_DEFINED = 1

INTERFACE IMimeObjResolver $IID_IMimeObjResolver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MimeOleObjectFromMoniker ( _                  ' VTable offset = 12
     BYVAL bindf AS LONG _                              ' __in BINDF bindf
   , BYVAL pmkOriginal AS IMoniker _                    ' __in IMoniker *pmkOriginal
   , BYVAL pBindCtx AS IBindCtx _                       ' __in IBindCtx *pBindCtx
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   , BYREF ppmkNew AS IMoniker _                        ' __out IMoniker **ppmkNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeObjResolver_INTERFACE_DEFINED__ */


#ENDIF   ' /* __MIMEOLE_LIBRARY_DEFINED__ */

' FNTSYSTYPE enum
%FNT_SYS_ICON           = 0
%FNT_SYS_ICON_BOLD      = %FNT_SYS_ICON           + 1
%FNT_SYS_MENU           = %FNT_SYS_ICON_BOLD      + 1
%FNT_SYS_ICON_STRIKEOUT = %FNT_SYS_MENU           + 1
%FNT_SYS_LAST           = %FNT_SYS_ICON_STRIKEOUT + 1

' ########################################################################################
' Interface name = IFontCache
' IID = B0D17FC2-7BC4-11d1-BDFA-00C04FA31009
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFontCache_INTERFACE_DEFINED)
    %IFontCache_INTERFACE_DEFINED = 1

INTERFACE IFontCache $IID_IFontCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL hkey AS DWORD _                              ' __in HKEY hkey
   , BYREF pszIntlKey AS ASCIIZ _                       ' __in LPCSTR pszIntlKey
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFont ( _                                   ' VTable offset = 16
     BYVAL fntType AS LONG _                            ' __in FNTSYSTYPE fntType
   , BYVAL hCharset AS DWORD _                          ' __in HCHARSET hCharset
   , BYREF phFont AS DWORD _                            ' __out HFONT *phFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnOptionChange ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJP_ISOControl ( _                          ' VTable offset = 24
     BYREF pfUseSIO AS LONG _                           ' __out BOOL *pfUseSIO
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFontCache_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFontCacheNotify
' IID = B0D17FC5-7BC4-11d1-BDFA-00C04FA31009
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFontCacheNotify_INTERFACE_DEFINED)
    %IFontCacheNotify_INTERFACE_DEFINED = 1

INTERFACE IFontCacheNotify $IID_IFontCacheNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnPreFontChange ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPostFontChange ( _                          ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFontCacheNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEditTag
' IID = 70183210-7b36-11d2-8c12-00c04fa31009
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEditTag_INTERFACE_DEFINED)
    %IMimeEditTag_INTERFACE_DEFINED = 1

INTERFACE IMimeEditTag $IID_IMimeEditTag

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSrc ( _                                    ' VTable offset = 12
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSrc ( _                                    ' VTable offset = 16
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDest ( _                                   ' VTable offset = 20
     BYREF pbstr AS WSTRING _                           ' __out BSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDest ( _                                   ' VTable offset = 24
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPreSave ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPostSave ( _                                ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanPackage ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValidMimeType ( _                           ' VTable offset = 40
     BYREF pszTypeW AS WSTRINGZ _                       ' __in LPWSTR pszTypeW
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEditTag_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeEditTagCollection
' IID = d09ee528-7b38-11d2-8c12-00c04fa31009
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeEditTagCollection_INTERFACE_DEFINED)
    %IMimeEditTagCollection_INTERFACE_DEFINED = 1

INTERFACE IMimeEditTagCollection $IID_IMimeEditTagCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL pHtmlDoc AS IUnknown _                       ' __in IUnknown *pHtmlDoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL cFetch AS DWORD _                            ' __in ULONG cFetch
   , BYREF ppTag AS IMimeEditTag _                      ' __out IMimeEditTag **ppTag
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 24
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeEditTagCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMimeSecurityCallback
' IID = BA715AE0-A740-11D2-8B22-0080C76B34C6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeSecurityCallback_INTERFACE_DEFINED)
   %IMimeSecurityCallback_INTERFACE_DEFINED = 1

%CMS_RECIPIENT_INFO_TYPE_UNKNOWN              = 0
%CMS_RECIPIENT_INFO_TYPE_KEYTRANS             = 1
%CMS_RECIPIENT_INFO_TYPE_KEYAGREE             = 2
%CMS_RECIPIENT_INFO_TYPE_MAIL_LIST            = 3

%CMS_RECIPIENT_INFO_PUBKEY_CERTIFICATE        = 0
%CMS_RECIPIENT_INFO_PUBKEY_KEYTRANS           = 1
%CMS_RECIPIENT_INFO_PUBKEY_PROVIDER           = 2
%CMS_RECIPIENT_INFO_PUBKEY_EPHEMERAL_KEYAGREE = 3
%CMS_RECIPIENT_INFO_PUBKEY_STATIC_KEYAGREE    = 4

%CMS_RECIPIENT_INFO_KEYID_CERTIFICATE         = 0
%CMS_RECIPIENT_INFO_KEYID_ISSUERSERIAL        = 1
%CMS_RECIPIENT_INFO_KEYID_KEY_ID              = 2

'typedef struct tagCMS_RECIPIENT_INFO
'    {
'    DWORD dwRecipientType;
'    PCCERT_CONTEXT pccert;
'    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
'    void *pvKeyEncryptionAuxInfo;
'    DWORD cbKeyEncryptionAuxInfo;
'    CRYPT_ALGORITHM_IDENTIFIER KeyWrapAlgorithm;
'    void *pvKeyWrapAuxInfo;
'    DWORD cbKeyWrapAuxInfo;
'    DWORD dwU1;
'    union
'        {
'        CRYPT_BIT_BLOB SubjectPublicKey;
'        struct
'            {
'            HCRYPTPROV hprov;
'            HCRYPTKEY hkey;
'            } 	u2;
'        struct
'            {
'            CRYPT_DATA_BLOB UserKeyingMaterial;
'            CRYPT_ALGORITHM_IDENTIFIER EphemeralAlgorithm;
'            CRYPT_BIT_BLOB SubjectPublicKey;
'            } 	u3;
'        struct
'            {
'            CRYPT_DATA_BLOB UserKeyingMaterial;
'            HCRYPTPROV hprov;
'            DWORD dwKeySpec;
'            CERT_ID senderCertId;
'            CRYPT_BIT_BLOB SubjectPublicKey;
'            } 	u4;
'        } 	u1;
'    DWORD dwU3;
'    union
'        {
'        CERT_ISSUER_SERIAL_NUMBER IssuerSerial;
'        CRYPT_DATA_BLOB KeyId;
'        } 	u3;
'    FILETIME filetime;
'    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
'    } 	CMS_RECIPIENT_INFO;

'typedef struct tagCMS_RECIPIENT_INFO *PCMS_RECIPIENT_INFO;

'typedef union tagCMS_CTRL_DECRYPT_INFO
'    {
'    CMSG_CTRL_KEY_TRANS_DECRYPT_PARA trans;
'    CMSG_CTRL_KEY_AGREE_DECRYPT_PARA agree;
'    CMSG_CTRL_MAIL_LIST_DECRYPT_PARA maillist;
'    } 	CMS_CTRL_DECRYPT_INFO;

'typedef union tagCMS_CTRL_DECRYPT_INFO *PCMS_CTRL_DECYRPT_INFO;

TYPE CMS_RECIPIENT_INFO_t1_STRUCT DWORD
   hprov AS DWORD   ' HCRYPTPROV
   hkey  AS DWORD   ' HCRYPTKEY
END TYPE

TYPE CMS_RECIPIENT_INFO_t2_STRUCT DWORD
   UserKeyingMaterial AS CRYPT_DATA_BLOB
   EphemeralAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   SubjectPublicKey   AS CRYPT_BIT_BLOB
END TYPE

TYPE CMS_RECIPIENT_INFO_t3_STRUCT DWORD
   UserKeyingMaterial AS CRYPT_DATA_BLOB
   hprov              AS DWORD   ' HCRYPTPROV
   dwKeySpec          AS DWORD   ' DWORD
   senderCertId       AS CERT_ID
   SubjectPublicKey   AS CRYPT_BIT_BLOB
END TYPE

UNION CMS_RECIPIENT_INFO_u1_UNION DWORD
   SubjectPublicKey AS CRYPT_BIT_BLOB
   t1 AS CMS_RECIPIENT_INFO_t1_STRUCT
   t2 AS CMS_RECIPIENT_INFO_t2_STRUCT
   t3 AS CMS_RECIPIENT_INFO_t3_STRUCT
END UNION

UNION CMS_RECIPIENT_INFO_u2_UNION DWORD
   IssuerSerial AS CERT_ISSUER_SERIAL_NUMBER
   KeyId        AS CRYPT_DATA_BLOB
END UNION

' // Size = 132 bytes
TYPE CMS_RECIPIENT_INFO DWORD
   dwRecipientType        AS DWORD                            ' DWORD
   pccert                 AS CERT_CONTEXT PTR                 ' PCCERT_CONTEXT
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyEncryptionAuxInfo AS DWORD                            ' void *
   cbKeyEncryptionAuxInfo AS DWORD                            ' DWORD
   KeyWrapAlgorithm       AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyWrapAuxInfo       AS DWORD                            ' void *
   cbKeyWrapAuxInfo       AS DWORD                            ' DWORD
   dwU1                   AS DWORD                            ' DWORD
   CMS_RECIPIENT_INFO_u1_UNION
   dwU3                   AS DWORD                            ' DWORD
   CMS_RECIPIENT_INFO_u2_UNION
   filetime               AS FILETIME
   pOtherAttr             AS CRYPT_ATTRIBUTE_TYPE_VALUE PTR   ' PCRYPT_ATTRIBUTE_TYPE_VALUE
END TYPE

' // Size = 36 bytes
UNION CMS_CTRL_DECRYPT_INFO DWORD
   trans    AS CMSG_CTRL_KEY_TRANS_DECRYPT_PARA
   agree    AS CMSG_CTRL_KEY_AGREE_DECRYPT_PARA
   maillist AS CMSG_CTRL_MAIL_LIST_DECRYPT_PARA
END UNION

$IID_IMimeSecurityCallback = GUID$("{BA715AE0-A740-11D2-8B22-0080C76B34C6}")

INTERFACE IMimeSecurityCallback $IID_IMimeSecurityCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindKeyFor ( _                                ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwRecipientIndex AS DWORD _                  ' __in DWORD dwRecipientIndex
   , BYREF pRecipInfo AS CMSG_CMS_RECIPIENT_INFO _      ' __in const CMSG_CMS_RECIPIENT_INFO *pRecipInfo
   , BYREF pdwCtrl AS DWORD _                           ' __out DWORD *pdwCtrl
   , BYREF pDecryptInfo AS CMS_CTRL_DECRYPT_INFO _      ' __inout CMS_CTRL_DECRYPT_INFO *pDecryptInfo
   , BYREF ppccert AS CERT_CONTEXT _                    ' __out PCCERT_CONTEXT *ppccert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 16
     BYREF pccert AS CERT_CONTEXT _                     ' __in PCCERT_CONTEXT pccert
   , BYVAL hstoreMsg AS DWORD _                         ' __in HCERTSTORE hstoreMsg
   , BYREF pcbParams AS DWORD _                         ' __inout DWORD *pcbParams
   , BYREF pbParams AS DWORD _                          ' __inout BYTE **pbParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeSecurityCallback_INTERFACE_DEFINED__ */

'// {80830b40-962c-11d2-8af6-0080c76b34c6}
'DEFINE_GUID(IID_IMimeSecurity2, 0x80830b40, 0x962c, 0x11d2, 0x8a, 0xf6, 0x00, 0x80, 0xc7, 0x6b, 0x34, 0xc6);
$IID_IMimeSecurity2 = GUID$("{80830b40-962c-11d2-8af6-0080c76b34c6}")

%SMIME_RECIPIENT_REPLACE_ALL                  = &H00000001???

%SMIME_ATTRIBUTE_SET_SIGNED                   = 0
%SMIME_ATTRIBUTE_SET_UNSIGNED                 = 1
%SMIME_ATTRIBUTE_SET_UNPROTECTED              = 2

%SMIME_ATTR_REPLACE_EXISTING                  = 0
%SMIME_ATTR_ADD_TO_EXISTING                   = 1
%SMIME_ATTR_ADD_IF_NOT_EXISTS                 = 2

%SMIME_SUPPORT_LABELS                         = &H00000001???
%SMIME_SUPPORT_RECEIPTS                       = &H00000002???
%SMIME_SUPPORT_MAILLIST                       = &H00000004???
%SMIME_SUPPORT_KEY_AGREE                      = &H00000008???


' ########################################################################################
' Interface name = IMimeSecurity2
' IID = 80830B40-962C-11D2-8AF6-0080C76B34C6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMimeSecurity2_INTERFACE_DEFINED)
    %IMimeSecurity2_INTERFACE_DEFINED = 1

$IID_IMimeSecurity2 = GUID$("{80830B40-962C-11D2-8AF6-0080C76B34C6}")

INTERFACE IMimeSecurity2 $IID_IMimeSecurity2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Encode ( _                                    ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Decode ( _                                    ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pCallback AS IMimeSecurityCallback _         ' __in IMimeSecurityCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecipientCount ( _                         ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwRecipCount AS DWORD _                     ' __out DWORD *pdwRecipCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRecipient ( _                              ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cRecipData AS DWORD _                        ' __in DWORD cRecipData
   , BYREF recipData AS CMS_RECIPIENT_INFO _            ' __in PCMS_RECIPIENT_INFO recipData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecipient ( _                              ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL iRecipient AS DWORD _                        ' __in DWORD iRecipient
   , BYVAL cRecipients AS DWORD _                       ' __in DWORD cRecipients
   , BYREF pRecipData AS CMS_RECIPIENT_INFO _           ' __inout PCMS_RECIPIENT_INFO pRecipData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteRecipient ( _                           ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL iRecipient AS DWORD _                        ' __in DWORD iRecipient
   , BYVAL cRecipients AS DWORD _                       ' __in DWORD cRecipients
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL iSigner AS DWORD _                           ' __in DWORD iSigner
   , BYVAL iAttributeSet AS DWORD _                     ' __in DWORD iAttributeSet
   , BYVAL iInstance AS DWORD _                         ' __in DWORD iInstance
   , BYREF pszObjectId AS ASCIIZ _                      ' __in LPCSTR pszObjectId
   , BYREF ppattr AS CRYPT_ATTRIBUTE _                  ' __out CRYPT_ATTRIBUTE **ppattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttribute ( _                              ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL iSigner AS DWORD _                           ' __in DWORD iSigner
   , BYVAL iAttributeSet AS DWORD _                     ' __in DWORD iAttributeSet
   , BYREF pattr AS CRYPT_ATTRIBUTE _                   ' __in const CRYPT_ATTRIBUTE *pattr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttribute ( _                           ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL iSigner AS DWORD _                           ' __in DWORD iSigner
   , BYVAL iAttributeSet AS DWORD _                     ' __in DWORD iAttributeSet
   , BYVAL iInstance AS DWORD _                         ' __in DWORD iInstance
   , BYREF pszObjId AS ASCIIZ _                         ' __in LPCSTR pszObjId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateReceipt ( _                             ' VTable offset = 48
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cbFromNames AS DWORD _                       ' __in DWORD cbFromNames
   , BYVAL pbFromNames AS BYTE PTR _                    ' __in const BYTE *pbFromNames
   , BYVAL cSignerCertificates AS DWORD _               ' __in DWORD cSignerCertificates
   , BYREF rgSignerCertificates AS CERT_CONTEXT _       ' __in PCCERT_CONTEXT *rgSignerCertificates
   , BYREF ppMimeMessageReceipt AS IMimeMessage _       ' __out IMimeMessage **ppMimeMessageReceipt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReceiptSendersList ( _                     ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pcSendersList AS DWORD _                     ' __out DWORD *pcSendersList
   , BYREF rgSendersList AS CERT_NAME_BLOB _            ' __out CERT_NAME_BLOB **rgSendersList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VerifyReceipt ( _                             ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pMimeMessageReceipt AS IMimeMessage _        ' __in IMimeMessage *pMimeMessageReceipt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CapabilitiesSupported ( _                     ' VTable offset = 60
      BYREF pdwFeatures AS DWORD _                      ' __inout DWORD *pdwFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMimeSecurity2_INTERFACE_DEFINED__ */

%NGH_DEFAULT    = &H00000000???   ' // Display the default newsgroup view for a product type
%NGH_FULLSEARCH = &H00000001???   ' // Execute the query against available newsgroups, and display results.

' ########################################################################################
' Interface name = INewsgroupHelp
' IID = 0887C54F-4F42-4937-81DA-BC9C97494627
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INewsgroupHelp_INTERFACE_DEFINED)
    %INewsgroupHelp_INTERFACE_DEFINED = 1

INTERFACE INewsgroupHelp $IID_INewsgroupHelp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUrl ( _                                    ' VTable offset = 12
     BYREF pwszProductGroup AS WSTRINGZ _               ' __in LPCWSTR pwszProductGroup
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pwszSearchText AS WSTRINGZ _                 ' __in LPCWSTR pwszSearchText
   , BYREF pLangID AS WORD _                            ' __in LANGID *pLangID
   , BYREF ppwszUrl AS DWORD _                          ' __out LPWSTR *ppwszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewsgroupHelp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHashTableW
' IID = 71D6B38C-7A15-42C6-AF84-B2A5DC242CEB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHashTableW_INTERFACE_DEFINED)
    %IHashTableW_INTERFACE_DEFINED = 1

INTERFACE IHashTableW $IID_IHashTableW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertW ( _                                   ' VTable offset = 12
     BYREF pwsz AS WSTRINGZ _                           ' __in LPCWSTR pwsz
   , BYVAL pv AS DWORD _                                ' __in LPVOID pv
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceW ( _                                  ' VTable offset = 16
     BYREF pwsz AS WSTRINGZ _                           ' __in LPCWSTR pwsz
   , BYVAL pv AS DWORD _                                ' __in LPVOID pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindW ( _                                     ' VTable offset = 20
     BYREF pwsz AS WSTRINGZ _                           ' __in LPCWSTR pwsz
   , BYVAL fRemove AS LONG _                            ' __in BOOL fRemove
   , BYREF ppv AS DWORD _                               ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHashTableW_INTERFACE_DEFINED__ */

'#if (_WIN32_OE >= 0x0500)

'// --------------------------------------------------------------------------------
'// CMDSETID_MimeEdit commands
'// --------------------------------------------------------------------------------
%MECMDID_DIRTY                    = 1
%MECMDID_EMPTY                    = 2
%MECMDID_STYLE                    = 3
%MECMDID_EDITHTML                 = 4
%MECMDID_DOWNGRADEPLAINTEXT       = 5
%MECMDID_SETTEXT                  = 6
%MECMDID_ROT13                    = 7
%MECMDID_INSERTTEXTFILE           = 8
%MECMDID_VIEWSOURCE               = 9
%MECMDID_FORMATFONT               = 10
%MECMDID_PREVIEWFORMAT            = 11
%MECMDID_EDITMODE                 = 12
%MECMDID_CHARSET                  = 13
%MECMDID_SAVEASSTATIONERY         = 14
%MECMDID_BACKGROUNDIMAGE          = 15
%MECMDID_INSERTTEXT               = 16
%MECMDID_INSERTHTML               = 17
%MECMDID_BACKGROUNDCOLOR          = 18
%MECMDID_APPLYDOCUMENT            = 19
%MECMDID_SAVEATTACHMENTS          = 20
%MECMDID_BACKGROUNDSOUND          = 21
%MECMDID_INSERTBGSOUND            = 22
%MECMDID_SHOWSOURCETABS           = 23
%MECMDID_SETSOURCETAB             = 24
%MECMDID_TABLINKS                 = 25
%MECMDID_FORMATPARAGRAPH          = 26
%MECMDID_CANENCODETEXT            = 27
%MECMDID_RELOAD_EXTERNAL_CONTENT  = 28
%MECMDID_EXTERNAL_CONTENT_BLOCKED = 29

'// --------------------------------------------------------------------------------
'// MEO_FLAGS
'// --------------------------------------------------------------------------------
%MEO_FLAGS_INCLUDEMSG           = &H0001
%MEO_FLAGS_HTML                 = &H0002
%MEO_FLAGS_AUTOINLINE           = &H0004
%MEO_FLAGS_SLIDESHOW            = &H0008
%MEO_FLAGS_AUTOTEXT             = &H0010
%MEO_FLAGS_BLOCKQUOTE           = &H0020
%MEO_FLAGS_SENDIMAGES           = &H0040
%MEO_FLAGS_DONTSPELLCHECKQUOTED = &H0080
%MEO_FLAGS_SENDEXTERNALIMGSRC   = &H0100
%MEO_FLAGS_REPLYATEND           = &H0200

'// --------------------------------------------------------------------------------
'// MECMDID_VIEWSOURCE options
'// --------------------------------------------------------------------------------
%MECMD_VS_HTML    = &H0001
%MECMD_VS_MESSAGE = &H0002

'// --------------------------------------------------------------------------------
'// MEST_
'// --------------------------------------------------------------------------------
%MEST_EDIT     = 0
%MEST_SOURCE   = 1
%MEST_PREVIEW  = 2
%MEST_NEXT     = 3
%MEST_PREVIOUS = 4

'// --------------------------------------------------------------------------------
'// MECMDID_STYLE options
'// --------------------------------------------------------------------------------
%MESTYLE_NOHEADER   = 0
%MESTYLE_PREVIEW    = 1
%MESTYLE_FORMATBAR  = 2
%MESTYLE_MINIHEADER = 3

'// --------------------------------------------------------------------------------
'// MECMDID_HEADER_TYLE options
'// --------------------------------------------------------------------------------
%MEHEADER_NONE          = &H00
%MEHEADER_NEWS          = &H01
%MEHEADER_MAIL          = &H02
%MEHEADER_FORCE_ENGLISH = &H04

'// --------------------------------------------------------------------------------
'// MECMDID_SIGNATURE_ENABLED options
'// --------------------------------------------------------------------------------
%MESIG_AUTO   = &H0001
%MESIG_MANUAL = &H0002

'// --------------------------------------------------------------------------------
'// MECMDID_SIGNATURE_OPTIONS options
'// --------------------------------------------------------------------------------
%MESIGOPT_PLAIN  = &H0001
%MESIGOPT_TOP    = &H0002
%MESIGOPT_PREFIX = &H0004
%MESIGOPT_BOTTOM = &H0008
%MESIGOPT_HTML   = &H0010

'// --------------------------------------------------------------------------------
'// MEHOSTCMDID_BORDERFLAGS options
'// --------------------------------------------------------------------------------
%MEBF_OUTERCLIENTEDGE = &H0001
%MEBF_INNERCLIENTEDGE = &H0002
%MEBF_FORMATBARSEP    = &H0004
%MEBF_NOSCROLL        = &H0008

'// --------------------------------------------------------------------------------
'// MEHOSTCMDID_SPELL_OPTIONS options
'// --------------------------------------------------------------------------------
%MESPELLOPT_IGNORENUMBER  = &H0001
%MESPELLOPT_IGNOREUPPER   = &H0002
%MESPELLOPT_IGNOREDBCS    = &H0004
%MESPELLOPT_IGNOREPROTECT = &H0008
%MESPELLOPT_IGNOREURL     = &H0010
%MESPELLOPT_ALWAYSSUGGEST = &H0020
%MESPELLOPT_CHECKONSEND   = &H0040
%MESPELLOPT_CHECKONTYPE   = &H0080

'// -------------------------------------------------------------------------------
'// MEHOSTCMDID_MESSAGE_TYPE options
'// -------------------------------------------------------------------------------
%MEMESSAGETYPE_NEWS = &H0001
%MEMESSAGETYPE_MAIL = &H0002

'// --------------------------------------------------------------------------------
'// MEHOSTCMDID_SOURCEEDIT_FLAGS options
'// --------------------------------------------------------------------------------
%MESRCFLAGS_COLOR = &H0001

'// --------------------------------------------------------------------------------
'// CMDSETID_MimeEditHost commands
'// --------------------------------------------------------------------------------
%MEHOSTCMDID_SIGNATURE_ENABLED            = 1
%MEHOSTCMDID_SIGNATURE_OPTIONS            = 2
%MEHOSTCMDID_SIGNATURE                    = 3
%MEHOSTCMDID_HEADER_TYPE                  = 4
%MEHOSTCMDID_ONPARSECOMPLETE              = 5
%MEHOSTCMDID_FLAGS                        = 6
%MEHOSTCMDID_QUOTE_CHAR                   = 7
%MEHOSTCMDID_REPLY_TICK_COLOR             = 8
%MEHOSTCMDID_COMPOSE_FONT                 = 9
%MEHOSTCMDID_ADD_TO_ADDRESSBOOK           = 10
%MEHOSTCMDID_ADD_TO_FAVORITES             = 11
%MEHOSTCMDID_SLIDESHOW_DELAY              = 12
%MEHOSTCMDID_FONTCACHE                    = 13
%MEHOSTCMDID_BORDERFLAGS                  = 14
%MEHOSTCMDID_SECURITY_ZONE                = 15
%MEHOSTCMDID_SPELL_OPTIONS                = 16
%MEHOSTCMDID_SAVEATTACH_PATH              = 17
%MEHOSTCMDID_SOURCEEDIT_FLAGS             = 18
%MEHOSTCMDID_SPELL_LANGUAGE               = 19
%MEHOSTCMDID_HTML_HELP                    = 20
%MEHOSTCMDID_UNSAFEATTACHMENTS            = 21
%MEHOSTCMDID_IS_READ_IN_TEXT_ONLY         = 22
%MEHOSTCMDID_QUOTE_SPACES                 = 23
%MEHOSTCMDID_BLOCK_EXTERNAL_CONTENT       = 24
%MEHOSTCMDID_RELOAD_WITH_EXTERNAL_CONTENT = 25
%MEHOSTCMDID_GETCOMPOSEFONT               = 26
%MEHOSTCMDID_RESETSETTINGS                = 27
%MEHOSTCMDID_GETREADFONT                  = 28
%MEHOSTCMDID_MESSAGE_TYPE                 = 29
%MEHOSTCMDID_COMMUNITIES                  = 30
%MEHOSTCMDID_COMMUNITIES_SERVER           = 31
%MEHOSTCMDID_PASSPORT_AUTHENTICATED       = 32
%MEHOSTCMDID_COMMUNITYSITE                = 33
%MEHOSTCMDID_PASSPORT_MANAGER             = 34
%MEHOSTCMDID_COMMUNITY_VOTE               = 35
%MEHOSTCMDID_PHISHING_SITE                = 36
%MEHOSTCMDID_CHARSET                      = 37
%MEHOSTCMDID_USE_WEBPREVIEW_SECURITY      = 38

'#endif //_WIN32_OE

'// --------------------------------------------------------------------------------
'// MimeOLE Exported C API Functions
'// --------------------------------------------------------------------------------

'// --------------------------------------------------------------------------------
'// Depends
'// --------------------------------------------------------------------------------
#INCLUDE ONCE "urlmon.inc"

'// --------------------------------------------------------------------------------
'// Constants
'// --------------------------------------------------------------------------------
%NOFLAGS                 = 0
%CCHMAX_CID              = 255
%CCHMAX_MID              = 255
%CCHMAX_INTERNET_DATE    = 50

%MECD_HTML               = &H0001
%MECD_PLAINTEXT          = &H0002
%MECD_ENCODEIMAGES       = &H0004
%MECD_ENCODEFILEURLSONLY = &H0008
%MECD_ENCODESOUNDS       = &H0010
%MECD_ENCODEVIDEO        = &H0020
%MECD_ENCODEPLUGINS      = &H0040

'// --------------------------------------------------------------------------------
'// Macros
'// --------------------------------------------------------------------------------
'#define MimeOleVariantInit(_pProp) \
'    ZeroMemory(_pProp, sizeof(PROPVARIANT))

MACRO MimeOleVariantInit(pProp)
   ZeroMemory(pProp, SIZEOF(PROPVARIANT))
END MACRO

'// --------------------------------------------------------------------------------
'// MimeOLE API Prototypes
'// --------------------------------------------------------------------------------

%MIMEOLE_COMPAT_OE5    = &H00000001???
%MIMEOLE_COMPAT_MLANG2 = &H00000002???

' ========================================================================================
' Sets the MIMEOLE compatibility mode.
' ========================================================================================
DECLARE FUNCTION MimeOleSetCompatMode IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetCompatMode" ( _
   BYVAL dwMode AS DWORD _                              ' __in DWORD dwMode
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns the Content-Type for the specified URL.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleContentTypeFromUrl IMPORT "INETCOMM.DLL" ALIAS "MimeOleContentTypeFromUrl" ( _
   BYREF pszBase AS ASCIIZ _                            ' __in  LPCSTR  pszBase
 , BYREF pszUrl AS ASCIIZ _                             ' __in  LPCSTR  pszUrl
 , BYREF ppszCntType AS ASCIIZ _                        ' __out LPSTR  *ppszCntType
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, supplied MHTML URL is parsed into root and body.
' ========================================================================================
DECLARE FUNCTION MimeOleParseMhtmlUrl IMPORT "INETCOMM.DLL" ALIAS "MimeOleParseMhtmlUrl" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in  LPSTR pszUrl
 , BYREF ppszRootUrl AS ASCIIZ _                        ' __out LPSTR *ppszRootUrl
 , BYREF ppszBodyUrl AS ASCIIZ _                        ' __out LPSTR *ppszBodyUrl
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a new message object and loads its state from the supplied URL (on success).
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleObjectFromUrl IMPORT "INETCOMM.DLL" ALIAS "MimeOleObjectFromUrl" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in  LPCSTR   pszUrl
 , BYVAL fCreate AS LONG _                              ' __in  BOOL     fCreate
 , BYREF riid AS GUID _                                 ' __in  REFIID   riid
 , BYREF ppvObject AS IUnknown _                        ' __out LPVOID   *ppvObject
 , BYREF ppUnkKeepAlive AS IUnknown _                   ' __out IUnknown **ppUnkKeepAlive
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Deprecated. Creates a new message object and loads its state from the supplied moniker.
' ========================================================================================
DECLARE FUNCTION MimeOleObjectFromMoniker IMPORT "INETCOMM.DLL" ALIAS "MimeOleObjectFromMoniker" ( _
   BYVAL bindf AS LONG _                                ' __in  BINDF    bindf
 , BYVAL pmkOriginal AS IMoniker _                      ' __in  IMoniker *pmkOriginal
 , BYVAL pBindCtx AS IBindCtx _                         ' __in  IBindCtx *pBindCtx
 , BYREF riid AS GUID _                                 ' __in  REFIID   riid
 , BYREF ppvObject AS IUnknown _                        ' __out LPVOID   *ppvObject
 , BYREF ppmkNew AS IMoniker _                          ' __out IMoniker **ppmkNew
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, combines base and relative URL.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleCombineURL IMPORT "INETCOMM.DLL" ALIAS "MimeOleCombineURL" ( _
   BYREF pszBase AS ASCIIZ _                            ' __in  LPCSTR pszBase
 , BYVAL cchBase AS DWORD _                             ' __in  ULONG  cchBase
 , BYREF pszURL AS ASCIIZ _                             ' __in  LPCSTR pszURL
 , BYVAL cchURL AS DWORD _                              ' __in  ULONG  cchURL
 , BYVAL fUnEscape AS LONG _                            ' __in  BOOL   fUnEscape
 , BYREF ppszAbsolute AS ASCIIZ _                       ' __out LPSTR  *ppszAbsolute
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns E_FAIL.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleGetSubjectFileName IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetSubjectFileName" ( _
   BYVAL pPropertySet AS IMimePropertySet _             ' __in     IMimePropertySet *pPropertySet
 , BYREF pulPart AS DWORD _                             ' __out    ULONG            *pulPart
 , BYREF pulTotal AS DWORD _                            ' __out    ULONG            *pulTotal
 , BYREF pszFileName AS ASCIIZ _                        ' __in_out LPSTR            pszFileName
 , BYVAL cchMax AS DWORD _                              ' __in     ULONG            cchMax
  ) AS LONG

' ========================================================================================
' On success, creates and initializes a new Web document.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleCreateWebDocument IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateWebDocument" ( _
   BYREF pszBase AS ASCIIZ _                            ' __in  LPCSTR           pszBase
 , BYREF pszURL AS ASCIIZ _                             ' __in  LPCSTR           pszURL
 , BYREF ppDocument AS IMimeWebDocument _               ' __out IMimeWebDocument **ppDocument
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns handle to the first body in the message tree that has the related content type.
' Also returns whether other instances were found. If related content type is not found,
' method argument specifies whether it should be created.
' ========================================================================================
DECLARE FUNCTION MimeOleGetRelatedSection IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetRelatedSection" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in   IMimeMessageTree *pTree
 , BYVAL fCreate AS BYTE _                              ' __in   boolean          fCreate
 , BYREF phRelated AS DWORD _                           ' __out  LPHBODY          phRelated
 , BYREF pfMultiple AS BYTE _                           ' __out  boolean          *pfMultiple
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns a handle to the first body in the message tree that has the mixed content type.
' Also returns whether other instances were found. If mixed content type is not found,
' method argument specifies whether it should be created.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleGetMixedSection IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetMixedSection" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in  IMimeMessageTree *pTree
 , BYVAL fCreate AS BYTE _                              ' __in  boolean          fCreate
 , BYVAL phMixed AS DWORD _                             ' __out LPHBODY          phMixed
 , BYREF pfMultiple AS BYTE _                           ' __out boolean          *pfMultiple
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns handle to the first body in the message tree that has the alternative content
' type. Also returns whether other instances were found.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleGetAlternativeSection IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetAlternativeSection" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in  IMimeMessageTree *pTree
 , BYVAL phAlternative AS DWORD _                       ' __out LPHBODY          phAlternative
 , BYREF pfMultiple AS BYTE _                           ' __out boolean          *pfMultiple
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a content ID as a string.
' ========================================================================================
DECLARE FUNCTION MimeOleGenerateCID IMPORT "INETCOMM.DLL" ALIAS "MimeOleGenerateCID" ( _
   BYREF pszCID AS ASCIIZ _                             ' __in_out LPSTR   pszCID
 , BYVAL cchMax AS DWORD _                              ' __in     ULONG   cchMax
 , BYVAL fAbsolute AS BYTE _                            ' __in     boolean fAbsolute
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a message ID as a string.
' ========================================================================================
DECLARE FUNCTION MimeOleGenerateMID IMPORT "INETCOMM.DLL" ALIAS "MimeOleGenerateMID" ( _
   BYREF pszMID AS ASCIIZ _                             ' __in_out LPSTR   pszMID
 , BYVAL cchMax AS DWORD _                              ' __in     ULONG   cchMax
 , BYVAL fAbsolute AS BYTE _                            ' __in     boolean fAbsolute
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a new byte stream.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateByteStream IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateByteStream" ( _
   BYREF ppStream AS IStream _                          ' __out IStream **ppStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns an interface used to manipulate MimeOLE's global property schema.
' MIMEOLEAPI MimeOleGetPropertySchema(
'            /* out */       IMimePropertySchema **ppSchema);
' ========================================================================================
DECLARE FUNCTION MimeOleGetPropertySchema IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetPropertySchema" ( _
   BYREF ppSchema AS IMimePropertySchema _              ' __out IMimePropertySchema **ppSchema
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Queries a specified string for a qualified match.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleQueryString IMPORT "INETCOMM.DLL" ALIAS "MimeOleQueryString" ( _
   BYREF pszSearchMe AS ASCIIZ _                        ' __in LPCSTR  pszSearchMe
 , BYREF pszCriteria AS ASCIIZ _                        ' __in LPCSTR  pszCriteria
 , BYVAL fSubString AS BYTE _                           ' __in boolean fSubString
 , BYVAL fCaseSensitive AS BYTE _                       ' __in boolean fCaseSensitive
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Gets the value of the specified property.
' ========================================================================================
DECLARE FUNCTION MimeOleGetPropA IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetPropA" ( _
   BYVAL pPropertyset AS IMimePropertySet _             ' __in  IMimePropertySet *pPropertyset
 , BYREF pszName AS ASCIIZ _                            ' __in  LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD            dwFlags
 , BYREF ppszData AS ASCIIZ _                           ' __out LPSTR            *ppszData
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Gets the Unicode value of the specified property.
' ========================================================================================
DECLARE FUNCTION MimeOleGetPropW IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetPropW" ( _
   BYVAL pPropertyset AS IMimePropertySet _             ' __in  IMimePropertySet *pPropertyset
 , BYREF pszName AS ASCIIZ _                            ' __in  LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD            dwFlags
 , BYREF ppszData AS WSTRINGZ _                         ' __out LPWSTR           *ppszData
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleGetProp = MimeOleGetPropW
#ELSE
   MACRO MimeOleGetProp = MimeOleGetPropA
#ENDIF

' ========================================================================================
' Sets the value of the specified property.
' ========================================================================================
DECLARE FUNCTION MimeOleSetPropA IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetPropA" ( _
   BYVAL pPropertyset AS IMimePropertySet _             ' __in IMimePropertySet *pPropertyset
 , BYREF pszName AS ASCIIZ _                            ' __in LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 , BYREF pszData AS ASCIIZ _                            ' __in LPCSTR           pszData
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Sets the Unicode value of the specified property.
' ========================================================================================
DECLARE FUNCTION MimeOleSetPropW IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetPropW" ( _
   BYVAL pPropertyset AS IMimePropertySet _             ' __in IMimePropertySet *pPropertyset
 , BYREF pszName AS ASCIIZ _                            ' __in LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 , BYREF pszData AS WSTRINGZ _                          ' __in LPWSTR           pszData
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleSetProp = MimeOleSetPropW
#ELSE
   MACRO MimeOleSetProp = MimeOleSetPropA
#ENDIF

' ========================================================================================
' Gets the value of a property for a specified body.
' ========================================================================================
DECLARE FUNCTION MimeOleGetBodyPropA IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetBodyPropA" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in  IMimeMessageTree *pTree
 , BYVAL hBody AS DWORD _                               ' __in  HBODY            hBody
 , BYREF pszName AS ASCIIZ _                            ' __in  LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD            dwFlags
 , BYREF ppszData AS ASCIIZ _                           ' __out LPSTR            *ppszData
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Gets the value of a property for a specified body as Unicode.
' ========================================================================================
DECLARE FUNCTION MimeOleGetBodyPropW IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetBodyPropW" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in  IMimeMessageTree *pTree
 , BYVAL hBody AS DWORD _                               ' __in  HBODY            hBody
 , BYREF pszName AS ASCIIZ _                            ' __in  LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD            dwFlags
 , BYREF ppszData AS WSTRINGZ _                         ' __out LPWSTR           *ppszData
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleGetBodyProp = MimeOleGetBodyPropW
#ELSE
   MACRO MimeOleGetBodyProp = MimeOleGetBodyPropA
#ENDIF

' ========================================================================================
' Sets the value of a property for a specified body.
' ========================================================================================
DECLARE FUNCTION MimeOleSetBodyPropA IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetBodyPropA" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in IMimeMessageTree *pTree
 , BYVAL hBody AS DWORD _                               ' __in HBODY            hBody
 , BYREF pszName AS ASCIIZ _                            ' __in LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 , BYREF pszData AS ASCIIZ _                            ' __in LPCSTR           pszData
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Sets the value of a property for a specified body.
' ========================================================================================
DECLARE FUNCTION MimeOleSetBodyPropW IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetBodyPropW" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in IMimeMessageTree *pTree
 , BYVAL hBody AS DWORD _                               ' __in HBODY            hBody
 , BYREF pszName AS ASCIIZ _                            ' __in LPCSTR           pszName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD            dwFlags
 , BYREF pszData AS WSTRINGZ _                          ' __in LPCWSTR          pszData
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleSetBodyProp = MimeOleSetBodyPropW
#ELSE
   MACRO MimeOleSetBodyProp = MimeOleSetBodyPropA
#ENDIF

' ========================================================================================
' On success, creates and initializes a header table.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateHeaderTable IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateHeaderTable" ( _
   BYREF ppTable AS IMimeHeaderTable _                  ' __out IMimeHeaderTable **ppTable
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Frees any memory pointed to by the variant.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleVariantFree IMPORT "INETCOMM.DLL" ALIAS "MimeOleVariantFree" ( _
   BYREF pProp AS PROPVARIANT _                         ' __in_out LPPROPVARIANT pProp
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Copies memory pointed to by the source variant and allocates new memory for the
' destination variant.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleVariantCopy IMPORT "INETCOMM.DLL" ALIAS "MimeOleVariantCopy" ( _
   BYREF pDest AS PROPVARIANT _                         ' __out LPPROPVARIANT pDest
 , BYREF pSource AS PROPVARIANT _                       ' __in  LPPROPVARIANT pSource
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, returns the class ID for a given file extension string.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleGetExtClassId IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetExtClassId" ( _
   BYREF pszExtension AS ASCIIZ _                       ' __in  LPCSTR  pszExtension
 , BYREF pclsid AS GUID _                               ' __out LPCLSID pclsid
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Encodes a message header string.
' ========================================================================================
DECLARE FUNCTION MimeOleEncodeHeader IMPORT "INETCOMM.DLL" ALIAS "MimeOleEncodeHeader" ( _
   BYVAL hCharset AS DWORD _                            ' __in     HCHARSET      hCharset
 , BYREF pData AS ANY _                                 ' __in     LPPROPVARIANT pData
 , BYREF ppszEncoded AS ASCIIZ _                        ' __out    LPSTR         *ppszEncoded
 , BYREF pRfc1522Info AS RFC1522INFO _                  ' __in_out LPRFC1522INFO pRfc1522Info
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Decodes a message header string.
' ========================================================================================
DECLARE FUNCTION MimeOleDecodeHeader IMPORT "INETCOMM.DLL" ALIAS "MimeOleDecodeHeader" ( _
   BYVAL hCharset AS DWORD _                            ' __in     HCHARSET      hCharset
 , BYREF pszData AS ASCIIZ _                            ' __in     LPCSTR        pszData
 , BYREF pDecoded AS ANY _                              ' __out    LPPROPVARIANT pDecoded
 , BYREF pRfc1522Info AS RFC1522INFO _                  ' __in_out LPRFC1522INFO pRfc1522Info
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Decodes an RFC 1522 World Wide Web link encoded string and, if found, stores the name of
' the character set contained in the encoded string.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleRfc1522Decode IMPORT "INETCOMM.DLL" ALIAS "MimeOleRfc1522Decode" ( _
   BYREF pszValue AS ASCIIZ _                           ' __in  LPCSTR pszValue
 , BYVAL pszCharset AS DWORD _                          ' __in  LPSTR  pszCharset
 , BYVAL cchmax AS DWORD _                              ' __in  ULONG  cchmax
 , BYREF ppszDecoded AS ASCIIZ _                        ' __out LPSTR  *ppszDecoded
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Encodes a string using RFC 1522 World Wide Web link format.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleRfc1522Encode IMPORT "INETCOMM.DLL" ALIAS "MimeOleRfc1522Encode" ( _
   BYREF pszValue AS ASCIIZ _                           ' __in  LPCSTR   pszValue
 , BYVAL hCharset AS DWORD _                            ' __in  HCHARSET hCharset
 , BYREF ppszEncoded AS ASCIIZ _                        ' __out LPSTR    *ppszEncoded
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns an interface used to perform character-set conversions and query information
' about character sets and codepages.
' ========================================================================================
DECLARE FUNCTION MimeOleGetInternat IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetInternat" ( _
   BYREF ppInternat AS IMimeInternational _             ' __out IMimeInternational **ppInternat
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, finds handle of specified character set.
' ========================================================================================
DECLARE FUNCTION MimeOleFindCharset IMPORT "INETCOMM.DLL" ALIAS "MimeOleFindCharset" ( _
   BYREF pszCharset AS ASCIIZ _                         ' __in  LPCSTR     pszCharset
 , BYREF phCharset AS DWORD _                           ' __out LPHCHARSET phCharset
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Gets information about the specified character set.
' ========================================================================================
DECLARE FUNCTION MimeOleGetCharsetInfo IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetCharsetInfo" ( _
   BYVAL hCharset AS DWORD _                            ' __in  HCHARSET       hCharset
 , BYREF pCsetInfo AS INETCSETINFO _                    ' __out LPINETCSETINFO pCsetInfo
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns a specified CODEPAGEINFO struct.
' ========================================================================================
DECLARE FUNCTION MimeOleGetCodePageInfo IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetCodePageInfo" ( _
   BYVAL cpiCodePage AS DWORD _                         ' __in  CODEPAGEID     cpiCodePage
 , BYREF pCodePageInfo AS DWORD _                       ' __out LPCODEPAGEINFO pCodePageInfo
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns the default charset.
' ========================================================================================
DECLARE FUNCTION MimeOleGetDefaultCharset IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetDefaultCharset" ( _
   BYREF phCharset AS DWORD _                           ' __out LPHCHARSET phCharset
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Sets default character set to the specified value (on success).
' ========================================================================================
DECLARE FUNCTION MimeOleSetDefaultCharset IMPORT "INETCOMM.DLL" ALIAS "MimeOleSetDefaultCharset" ( _
   BYVAL hCharset AS DWORD _                            ' __in HCHARSET hCharset
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Finds a character set for the specified code page.
' ========================================================================================
DECLARE FUNCTION MimeOleGetCodePageCharset IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetCodePageCharset" ( _
   BYVAL cpiCodePage AS LONG _                          ' __in   CODEPAGEID  cpiCodePage
 , BYVAL ctCsetType AS LONG _                           ' __in   CHARSETTYPE ctCsetType
 , BYREF phCharset AS DWORD _                           ' __out  LPHCHARSET  phCharset
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a new virtual stream.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateVirtualStream IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateVirtualStream" ( _
   BYREF ppStream AS IStream _                          ' __out IStream **ppStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Opens or, if non-existing, creates a file stream with specified read/write properties.
' ========================================================================================
DECLARE FUNCTION MimeOleOpenFileStream IMPORT "INETCOMM.DLL" ALIAS "MimeOleOpenFileStream" ( _
   BYREF pszFilePath AS ASCIIZ _                        ' __in   LPCSTR  pszFilePath
 , BYVAL dwCreationDistribution AS DWORD _              ' __in   DWORD   dwCreationDistribution
 , BYVAL dwAccess AS DWORD _                            ' __in   DWORD   dwAccess
 , BYREF ppstmFile AS IStream _                         ' __out  IStream **ppstmFile
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Reads the first four bytes to determine whether data stream is Transport Neutral
' Encapsulation Format (TNEF).
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleIsTnefStream IMPORT "INETCOMM.DLL" ALIAS "MimeOleIsTnefStream" ( _
   BYVAL pStream AS IStream _                           ' __in IStream *pStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates a file name.
' ========================================================================================
DECLARE FUNCTION MimeOleGenerateFileName IMPORT "INETCOMM.DLL" ALIAS "MimeOleGenerateFileName" ( _
   BYREF pszContentType AS ASCIIZ _                     ' __in     LPCSTR pszContentType
 , BYREF pszSuggest AS ASCIIZ _                         ' __in     LPCSTR pszSuggest
 , BYREF pszDefaultExt AS ASCIIZ _                      ' __in     LPCSTR pszDefaultExt
 , BYREF ppszFileName AS ASCIIZ _                       ' __in_out LPSTR  *ppszFileName
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Gets the file extension for the specified file.
' ========================================================================================
DECLARE FUNCTION MimeOleGetFileExtension IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetFileExtension" ( _
   BYREF pszFilePath AS ASCIIZ _                        ' __in      LPCSTR pszFilePath
 , BYREF pszExt AS ASCIIZ _                             ' __in_out  LPSTR  pszExt
 , BYVAL cchMax AS DWORD _                              ' __in      ULONG  cchMax
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates a new Secure/Multipurpose Internet Mail Extensions (S/MIME) object.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateSecurity IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateSecurity" ( _
   BYREF ppSecurity AS IMimeSecurity _                  ' __out IMimeSecurity **ppSecurity
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates a file time from a specified Internet date. Input is in RFC822
' format: "ddd, dd mmm yyyy hh:mm:ss +/- hhmm\0", such as "Tue, 21 Jan 1997 18:25:40 GMT".
' On failure, created file time defaults to current system time.
' ========================================================================================
DECLARE FUNCTION MimeOleInetDateToFileTime IMPORT "INETCOMM.DLL" ALIAS "MimeOleInetDateToFileTime" ( _
   BYREF pszDate AS ASCIIZ _                            ' __in   LPCSTR     pszDate
 , BYREF pft AS FILETIME _                              ' __out  LPFILETIME pft
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates an internet date from a specified file time. Output is in RFC822 format:
' "ddd, dd mmm yyyy hh:mm:ss +/- hhmm\0", such as "Tue, 21 Jan 1997 18:25:40 GMT".
' ========================================================================================
DECLARE FUNCTION MimeOleFileTimeToInetDate IMPORT "INETCOMM.DLL" ALIAS "MimeOleFileTimeToInetDate" ( _
   BYREF pft AS FILETIME _                              ' __in      LPFILETIME pft
 , BYREF pszDate AS ASCIIZ _                            ' __in_out  LPSTR      pszDate
 , BYVAL cchMax AS DWORD _                              ' __in      ULONG      cchMax
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates and initializes a message parts.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateMessageParts IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateMessageParts" ( _
   BYREF ppParts AS IMimeMessageParts _                 ' __out IMimeMessageParts **ppParts
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a new IMimeAllocator object.
' ========================================================================================
DECLARE FUNCTION MimeOleGetAllocator IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetAllocator" ( _
   BYREF ppAllocator AS IMimeAllocator _                ' __out IMimeAllocator **ppAllocator
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Parses the specified address string (on success).
' ========================================================================================
DECLARE FUNCTION MimeOleParseRfc822AddressA IMPORT "INETCOMM.DLL" ALIAS "MimeOleParseRfc822Address" ( _
   BYVAL dwAdrType AS DWORD _                           ' __in   DWORD         dwAdrType
 , BYVAL ietEncoding AS LONG _                          ' __in   ENCODINGTYPE  ietEncoding
 , BYREF pszRfc822Adr AS ASCIIZ _                       ' __in   LPCSTR        pszRfc822Adr
 , BYREF pList AS ADDRESSLIST _                         ' __out  LPADDRESSLIST pList
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates and initializes a message.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateMessage IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateMessage" ( _
   BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown     *pUnkOuter
 , BYREF ppMessage AS IMimeMessage _                    ' __out IMimeMessage **ppMessage
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Merges partial headers. The resulting stream should contain the headers for the first
' message (using normal RFC822 rules), then a blank line, and then the headers for the
' second message (again following RFC822 rules).
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleMergePartialHeaders IMPORT "INETCOMM.DLL" ALIAS "MimeOleMergePartialHeaders" ( _
   BYVAL pstmIn AS IStream _                            ' __in IStream *pstmIn
 , BYVAL pstmOut AS IStream _                           ' __in IStream *pstmOut
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Adds escape character ('\') to otherwise-invalid characters, such as backslash, quote
' and parens, in supplied zero-terminated string.
' ========================================================================================
DECLARE FUNCTION MimeOleEscapeString IMPORT "INETCOMM.DLL" ALIAS "MimeOleEscapeString" ( _
   BYVAL cpiCodePage AS DWORD _                         ' __in  CODEPAGEID cpiCodePage
 , BYREF pszIn AS ASCIIZ _                              ' __in  LPCSTR     pszIn
 , BYREF ppszOut AS ASCIIZ _                            ' __out LPSTR      *ppszOut
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns the Content-Type of the specified file extension.
' ========================================================================================
DECLARE FUNCTION MimeOleGetExtContentTypeA IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetExtContentType" ( _
   BYREF pszExtension AS ASCIIZ _                       ' __in  LPCSTR pszExtension
 , BYREF ppszContentType AS ASCIIZ _                    ' __out LPSTR  *ppszContentType
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns the Content-Type of the specified file extension.
' ========================================================================================
DECLARE FUNCTION MimeOleGetExtContentTypeW IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetExtContentTypeW" ( _
   BYREF pszExtension AS ASCIIZ _                       ' __in  LPCSTR pszExtension
 , BYREF ppszContentType AS DWORD _                     ' __out LPWSTR *ppszContentType
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleGetExtContentType = MimeOleGetExtContentTypeW
#ELSE
   MACRO MimeOleGetExtContentType = MimeOleGetExtContentTypeA
#ENDIF

' ========================================================================================
' Returns the file extension for a supplied content type.
' ========================================================================================
DECLARE FUNCTION MimeOleGetContentTypeExt IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetContentTypeExt" ( _
   BYREF pszContentType AS ASCIIZ _                     ' __in  LPCSTR pszContentType
 , BYREF ppszExtension AS ASCIIZ _                      ' __out LPSTR  *ppszExtension
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns file information for a supplied file path string.
' ========================================================================================
DECLARE FUNCTION MimeOleGetFileInfoA IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetFileInfoA" ( _
   BYREF pszFilePath AS ASCIIZ _                        ' __in  LPSTR pszFilePath
 , BYREF ppszCntType AS ASCIIZ _                        ' __out LPSTR *ppszCntType
 , BYREF ppszSubType AS ASCIIZ _                        ' __out LPSTR *ppszSubType
 , BYREF ppszCntDesc AS ASCIIZ _                        ' __out LPSTR *ppszCntDesc
 , BYREF ppszFileName AS ASCIIZ _                       ' __out LPSTR *ppszFileName
 , BYREF ppszExtension AS ASCIIZ _                      ' __out LPSTR *ppszExtension
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns file information for a supplied file path string.
' ========================================================================================
DECLARE FUNCTION MimeOleGetFileInfoW IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetFileInfoW" ( _
   BYREF pszFilePath AS WSTRINGZ _                      ' __in  LPWSTR pszFilePath
 , BYREF ppszCntType AS DWORD _                         ' __out LPWSTR *ppszCntType
 , BYREF ppszSubType AS DWORD _                         ' __out LPWSTR *ppszSubType
 , BYREF ppszCntDesc AS DWORD _                         ' __out LPWSTR *ppszCntDesc
 , BYREF ppszFileName AS DWORD _                        ' __out LPWSTR *ppszFileName
 , BYREF ppszExtension AS DWORD _                       ' __out LPWSTR *ppszExtension
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleGetFileInfo = MimeOleGetFileInfoW
#ELSE
   MACRO MimeOleGetFileInfo = MimeOleGetFileInfoA
#ENDIF

' ========================================================================================
' On success, creates a new message body.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateBody IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateBody" ( _
   BYREF ppBody AS IMimeBody _                          ' __out IMimeBody **ppBody
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates a new property set object.
' ========================================================================================
DECLARE FUNCTION MimeOleCreatePropertySet IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreatePropertySet" ( _
   BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown         *pUnkOuter
 , BYREF ppPropertySet AS IMimePropertySet _            ' __out IMimePropertySet **ppPropertySet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' On success, creates and initializes a message tree.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateMessageTree IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateMessageTree" ( _
   BYVAL pUnkOuter AS IUnknown _                        ' __in  IUnknown         *pUnkOuter
 , BYREF ppMessageTree AS IMimeMessageTree _            ' __out IMimeMessageTree **ppMessageTree
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Given a set of thumbprints, returns an equivalent set of certificates.
' ========================================================================================
DECLARE FUNCTION MimeOleGetCertsFromThumbprints IMPORT "INETCOMM.DLL" ALIAS "MimeOleGetCertsFromThumbprints" ( _
   BYREF rgThumbprint AS THUMBBLOB _                    ' __in     THUMBBLOB        *const rgThumbprint
 , BYREF pResults AS X509CERTRESULT _                   ' __in_out X509CERTRESULT   *const pResults
 , BYREF rghCertStore AS DWORD _                        ' __in     const HCERTSTORE *const rghCertStore
 , BYVAL cCertStore AS DWORD _                          ' __in     const DWORD      cCertStore
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Splits message into a collection of parts, as determined by a specified maximum part size.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleSplitMessage IMPORT "INETCOMM.DLL" ALIAS "MimeOleSplitMessage" ( _
   BYVAL pMessage AS IMimeMessage _                     ' __in  IMimeMessage      *pMessage
 , BYVAL cbMaxPart AS DWORD _                           ' __in  ULONG             cbMaxPart
 , BYREF ppParts AS IMimeMessageParts _                 ' __out IMimeMessageParts **ppParts
 ) AS LONG

' ========================================================================================
' Clears dirty tree flag and any dirty body flags for the specified message tree object.
' ========================================================================================
DECLARE FUNCTION MimeOleClearDirtyTree IMPORT "INETCOMM.DLL" ALIAS "MimeOleClearDirtyTree" ( _
   BYVAL pTree AS IMimeMessageTree _                    ' __in IMimeMessageTree *pTree
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Converts text/enriched to text/html.
' ========================================================================================
DECLARE FUNCTION MimeOleConvertEnrichedToHTML IMPORT "INETCOMM.DLL" ALIAS "MimeOleConvertEnrichedToHTML" ( _
   BYVAL codepage AS DWORD _                            ' __in CODEPAGEID codepage
 , BYVAL pIn AS IStream _                               ' __in IStream    *pIn
 , BYVAL pOut AS IStream _                              ' __in IStream    *pOut
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Checks whether stream is enriched, as indicated by existence of "c_szXRich" in stream.
' Note: Doesn't appear in the export list of INETCOMM.DLL 6.0
' ========================================================================================
DECLARE FUNCTION MimeOleIsEnrichedStream IMPORT "INETCOMM.DLL" ALIAS "MimeOleIsEnrichedStream" ( _
   BYVAL pStream AS IStream _                           ' __in IStream *pStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Outputs supplied Secure/Multipurpose Internet Mail Extensions (S/MIME) capabilities to
' supplied dialog.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapsToDlg IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapsToDlg" ( _
   BYVAL pbSMimeCaps AS BYTE PTR _                      ' __in LPBYTE       pbSMimeCaps
 , BYVAL cbSMimeCaps AS DWORD _                         ' __in DWORD        cbSMimeCaps
 , BYVAL cCerts AS DWORD _                              ' __in DWORD        cCerts
 , BYVAL rgCerts AS DWORD _                             ' __in PCX509CERT * rgCerts
 , BYVAL hwndDlg AS DWORD _                             ' __in HWND         hwndDlg
 , BYVAL idEncAlgs AS DWORD _                           ' __in DWORD        idEncAlgs
 , BYVAL idSignAlgs AS DWORD _                          ' __in DWORD        idSignAlgs
 , BYVAL idBlob AS DWORD _                              ' __in DWORD        idBlob
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Reads a combo box of encryption algorithm IDs (Using the handle passed in), to select a
' default encryption algorithm and reads a combo box of signature algorithm IDs to select
' a default signing algorithm. A list of capabilities for each is built from the combo box
' items. Without combo boxes, the defaults are 40-bit RC2 and SHA-1. Optionally, if a
' checkbox with a blob item ID is checked, the capabilities list is generated as a blob.
' The results are used to encode an Secure/Multipurpose Internet Mail Extensions (S/MIME)
' capabilities array object of the specified size.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapsFromDlg IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapsFromDlg" ( _
   BYVAL hwnd AS DWORD _                                ' __in     HWND    hwnd
 , BYVAL idEncAlgs AS DWORD _                           ' __in     DWORD   idEncAlgs
 , BYVAL idSignAlgs AS DWORD _                          ' __in     DWORD   idSignAlgs
 , BYVAL idBlob AS DWORD _                              ' __in     DWORD   idBlob
 , BYREF pbSMimeCaps AS DWORD _                         ' __in_out LPBYTE  pbSMimeCaps
 , BYREF pcbSmimeCaps AS DWORD _                        ' __in_out DWORD * pcbSmimeCaps
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Returns an equivalent of the cookie returned by MimeOleSMimeCapAddSMimeCap when an array
' of CRYPT_SMIME_CAPABILITIES is passed in; otherwise, the function attempts to match
' MimeOle encryption capabilities to a Microsoft-enhanced provider (CryptoAPI), and flags
' matching algorithms in the returned cookie.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapInit IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapInit" ( _
   BYVAL pbSMimeCap AS BYTE PTR _                       ' __in  LPBYTE   pbSMimeCap
 , BYVAL cbSMimeCap AS DWORD _                          ' __in  DWORD    cbSMimeCap
 , BYREF ppv AS ANY _                                   ' __out LPVOID * ppv
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Receives an array of CRYPT_SMIME_CAPABILITIES allocated by MimeOleSMimeCapInit and
' returns a cookie flagged with a filtered list of available algorithms. See wincrypt.h.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapAddSMimeCap IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapAddSMimeCap" ( _
   BYVAL pbSMimeCap AS BYTE PTR _                       ' __in     LPBYTE pbSMimeCap
 , BYVAL cbSMimeCap AS DWORD _                          ' __in     DWORD  cbSMimeCap
 , BYREF pv AS ANY _                                    ' __in_out LPVOID pv
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Sets a passed-in cookie with a flag indicating the encryption algorithm to be used.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapAddCert IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapAddCert" ( _
   BYVAL pbCert AS BYTE PTR _                           ' __in     LPBYTE pbCert
 , BYVAL cbCert AS DWORD _                              ' __in     DWORD  cbCert
 , BYVAL fParanoid AS LONG _                            ' __in     BOOL   fParanoid
 , BYREF pv AS ANY _                                    ' __in_out LPVOID pv
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Encodes an object of a specified size, using the best encryption algorithm flagged in
' the cookie. On success, returns the number of bits used for the encryption.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapGetEncAlg IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapGetEncAlg" ( _
   BYVAL pv AS BYTE PTR _                               ' __in     LPVOID  pv
 , BYREF pbEncode AS DWORD _                            ' __in_out LPBYTE  pbEncode
 , BYREF pcbEncode AS DWORD _                           ' __in_out DWORD * pcbEncode
 , BYREF pdwBits AS DWORD _                             ' __in_out DWORD * pdwBits
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Encodes an object of specified size using the best hash algorithm flagged in the cookie.
' On success, returns the number of bits used for the hash signing.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapGetHashAlg IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapGetHashAlg" ( _
   BYVAL pv AS DWORD _                                  ' __in     LPVOID  pv
 , BYREF pbEncode AS DWORD _                            ' __in_out LPBYTE  pbEncode
 , BYREF pcbEncode AS DWORD _                           ' __in_out DWORD * pcbEncode
 , BYREF pfBlobSign AS DWORD _                          ' __in_out DWORD * pfBlobSign
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Clears allocated capabilities memory.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapRelease IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapRelease" ( _
   BYVAL pv AS DWORD _                                  ' __in LPVOID pv
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Obtains algorithm name from supplied Secure/Multipurpose Internet Mail Extensions
' (S/MIME) capabilities array.
' ========================================================================================
DECLARE FUNCTION MimeOleAlgNameFromSMimeCap IMPORT "INETCOMM.DLL" ALIAS "MimeOleAlgNameFromSMimeCap" ( _
   BYVAL pb AS BYTE PTR _                               ' __in  LPBYTE  pb
 , BYVAL cb AS DWORD _                                  ' __in  DWORD   cb
 , BYREF ppzProtocol AS ASCIIZ _                        ' __out LPCSTR *ppzProtocol
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Used to obtain the bit strength of an encryption algorithm.
' ========================================================================================
DECLARE FUNCTION MimeOleAlgStrengthFromSMimeCap IMPORT "INETCOMM.DLL" ALIAS "MimeOleAlgStrengthFromSMimeCap" ( _
   BYVAL pb AS BYTE PTR _                               ' __in  LPBYTE  pb
 , BYVAL cb AS DWORD _                                  ' __in  DWORD   cb
 , BYVAL fEncryption AS LONG _                          ' __in  BOOL    fEncryption
 , BYREF pdwStrength AS DWORD _                         ' __out DWORD * pdwStrength
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Builds a list of encryption capabilities (if all encryption algorithms are to be
' supported) from the passed-in cookie, or defaults to 40-bit RC2. Similarly, if all
' signature algorithms are to be supported, builds a list of signing capabilities from the
' cookie, or defaults to SHA-1. The results are used to encode an Secure/Multipurpose
' Internet Mail Extensions (S/MIME) capabilities array object of the specified size.
' ========================================================================================
DECLARE FUNCTION MimeOleSMimeCapsFull IMPORT "INETCOMM.DLL" ALIAS "MimeOleSMimeCapsFull" ( _
   BYVAL pv AS DWORD _                                  ' __in     LPVOID  pv
 , BYVAL fFullEncryption AS LONG _                      ' __in     BOOL    fFullEncryption
 , BYVAL fFullSigning AS LONG _                         ' __in     BOOL    fFullSigning
 , BYREF pbSymCaps AS DWORD _                           ' __in_out LPBYTE  pbSymCaps
 , BYREF pcbSymCaps AS DWORD _                          ' __in_out DWORD * pcbSymCaps
 ) AS LONG                                              ' HRESULT


'#if (_WIN32_OE >= 0x0500)

' ========================================================================================
' On success, creates and initializes a hash table.
' ========================================================================================
DECLARE FUNCTION MimeOleCreateHashTable IMPORT "INETCOMM.DLL" ALIAS "MimeOleCreateHashTable" ( _
   BYVAL dwSize AS DWORD _                              ' __in  DWORD      dwSize
 , BYVAL fDupeKeys AS LONG _                            ' __in  BOOL       fDupeKeys
 , BYREF ppHashTable AS IHashTable _                    ' __out IHashTable **ppHashTable
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Strips and adds a message header.
' ========================================================================================
DECLARE FUNCTION MimeOleStripHeaders IMPORT "INETCOMM.DLL" ALIAS "MimeOleStripHeaders" ( _
   BYVAL pMessage AS IMimeMessage _                     ' __in IMimeMessage *pMessage
 , BYVAL hBody AS DWORD _                               ' __in HBODY        hBody
 , BYREF pszNameDelete AS ASCIIZ _                      ' __in LPCSTR       pszNameDelete
 , BYREF pszHeaderAdd AS ASCIIZ _                       ' __in LPCSTR       pszHeaderAdd
 , BYREF ppStream AS IStream _                          ' __in IStream      **ppStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Parses the specified RFC 822 address string.
' ========================================================================================
DECLARE FUNCTION MimeOleParseRfc822AddressW IMPORT "INETCOMM.DLL" ALIAS "MimeOleParseRfc822AddressW" ( _
   BYVAL dwAdrType AS DWORD _                           ' __in   DWORD         dwAdrType
 , BYREF pszRfc822Adr AS WSTRINGZ _                     ' __in   LPCWSTR       pszRfc822Adr
 , BYREF pList AS ADDRESSLIST _                         ' __out  LPADDRESSLIST pList
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO MimeOleParseRfc822Address = MimeOleParseRfc822AddressW
#ELSE
   MACRO MimeOleParseRfc822Address = MimeOleParseRfc822AddressA
#ENDIF

'#endif //_WIN32_OE

'#if (_WIN32_OE >= 0x0500)
'// --------------------------------------------------------------------------------
'// MimeEdit API Prototypes
'// --------------------------------------------------------------------------------

DECLARE FUNCTION MimeEditViewSource IMPORT "INETCOMM.DLL" ALIAS "MimeEditViewSource" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND         hwndParent
 , BYVAL pMsg AS IMimeMessage _                         ' __in IMimeMessage *pMsg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeEditIsSafeToRun IMPORT "INETCOMM.DLL" ALIAS "MimeEditIsSafeToRun" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPCSTR lpszFileName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeEditVerifyTrust IMPORT "INETCOMM.DLL" ALIAS "MimeEditVerifyTrust" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPCSTR lpszFileName
 , BYREF lpszPathName AS ASCIIZ _                       ' __in LPCSTR lpszPathName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeEditCreateMimeDocument IMPORT "INETCOMM.DLL" ALIAS "MimeEditCreateMimeDocument" ( _
   BYVAL pDoc AS IUnknown _                             ' __in  IUnknown     *pDoc
 , BYVAL pMsgSrc AS IMimeMessage _                      ' __in  IMimeMessage *pMsgSrc
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD        dwFlags
 , BYREF ppMsg AS IMimeMessage _                        ' __out IMimeMessage **ppMsg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeEditGetBackgroundImageUrl IMPORT "INETCOMM.DLL" ALIAS "MimeEditGetBackgroundImageUrl" ( _
   BYVAL pDoc AS IUnknown _                             ' __in  IUnknown *pDoc
 , BYREF pbstr AS WSTRING _                             ' __out BSTR     *pbstr
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeEditDocumentFromStream IMPORT "INETCOMM.DLL" ALIAS "MimeEditDocumentFromStream" ( _
   BYVAL pstm AS IStream _                              ' __in  IStream *pstm
 , BYREF riid AS GUID _                                 ' __in  REFIID  riid
 , BYREF ppDoc AS IUnknown _                            ' __out void    **ppDoc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MimeGetAddressFormatW IMPORT "INETCOMM.DLL" ALIAS "MimeGetAddressFormatW" ( _
   BYREF riid AS GUID _                                 ' __in REFIID        riid
 , BYVAL pvObject AS DWORD _                            ' __in LPVOID        pvObject
 , BYVAL dwAdrType AS DWORD _                           ' __in DWORD         dwAdrType
 , BYVAL format AS LONG _                               ' __in ADDRESSFORMAT format
 , BYREF ppszFormat AS WSTRINGZ _                       ' __out LPWSTR       *ppszFormat
 ) AS LONG                                              ' HRESULT

MACRO MimeGetAddressFormat = MimeGetAddressFormatW

'#if (_WIN32_OE >= 0x501)
'#ifdef __WINCRYPT_H__
'//+-------------------------------------------------------------------------
'//  RecipientID
'//
'//  The value of dwRecepintType MUST be 0.
'//--------------------------------------------------------------------------

$szOID_Microsoft_Encryption_Cert = "1.3.6.1.4.1.311.16.4"

' // Size = 20 bytes
TYPE CRYPT_RECIPIENT_ID DWORD
   dwRecipientType AS DWORD
   Issuer          AS CERT_NAME_BLOB
   SerialNumber    AS CRYPT_INTEGER_BLOB
END TYPE

'#endif // __WINCRYPT_H__
'#endif //_WIN32_OE
