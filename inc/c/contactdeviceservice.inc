' ########################################################################################
' Microsoft Windows
' File: ContactDeviceService.inc
' Contents: Declarations for the Contact Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CONTACTDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "SyncDeviceService.inc"

'/*****************************************************************************/
'/*  Contact Service Info                                                     */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(SERVICE_Contacts,
'    0xDD04D5FC, 0x9D6E, 0x4F76, 0x9D, 0xCF, 0xEC, 0xA6, 0x33, 0x9B, 0x73, 0x89);
$SERVICE_Contacts = GUID$("{DD04D5FC-9D6E-4F76-9DCF-ECA6339B7389}")

$$NAME_ContactsSvc = "Contacts"$$
%TYPE_ContactsSvc = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Contact Service Property                                                  /
'/*****************************************************************************/

'#define PKEY_ContactSvc_SyncWithPhoneOnly   PKEY_SyncSvc_FilterType
MACRO PKEY_ContactSvc_SyncWithPhoneOnly = PKEY_SyncSvc_FilterType
'#define NAME_ContactSvc_SyncWithPhoneOnly   NAME_SyncSvc_FilterType
$$NAME_ContactSvc_SyncWithPhoneOnly = $$NAME_SyncSvc_FilterType


'/*****************************************************************************/
'/*  Contact Service Object Formats                                           */
'/*****************************************************************************/

'/*  FORMAT_AbstractContact
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractContact,
'    0xBB810000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractContact = GUID$("{BB810000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractContact                = "AbstractContact"$$

'/*  FORMAT_VCard2Contact
' */

'DEFINE_DEVSVCGUID(FORMAT_VCard2Contact,
'    0xBB820000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_VCard2Contact = GUID$("{BB820000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_VCard2Contact                  = "VCard2Contact"$$

'/*  FORMAT_VCard3Contact
' */

'DEFINE_DEVSVCGUID(FORMAT_VCard3Contact,
'    0xBB830000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_VCard3Contact = GUID$("{BB830000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_VCard3Contact                  = "VCard3Contact"$$


'/*  FORMAT_AbstractContactGroup
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractContactGroup,
'    0xBA060000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractContactGroup = GUID$("{BA060000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractContactGroup           = "AbstractContactGroup"$$


'/*****************************************************************************/
'/*  Contact Service Object Property Keys                                     */
'/*****************************************************************************/


'DEFINE_DEVSVCGUID(NAMESPACE_ContactObj,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B);
$NAMESPACE_ContactObj = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}")

'/*  ContactObj.GivenName
' *
' *  MTP Property: Given Name (0xDD00)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_GivenName,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    3);
MACRO PKEY_ContactObj_GivenName = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(3)

$$NAME_ContactObj_GivenName           = "GivenName"$$


'/*  ContactObj.MiddleNames
' *
' *  MTP Property: Middle Names (0xDD01)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_MiddleNames,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    4);
MACRO PKEY_ContactObj_MiddleNames = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(4)

$$NAME_ContactObj_MiddleNames         = "MiddleNames"$$


'/*  ContactObj.FamilyName
' *
' *  MTP Property: Family Name (0xDD02)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_FamilyName,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    5);
MACRO PKEY_ContactObj_FamilyName = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(5)

$$NAME_ContactObj_FamilyName          = "FamilyName"$$


'/*  ContactObj.Title
' *
' *  MTP Property: Prefix (0xDD03)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Title,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    6);
MACRO PKEY_ContactObj_Title = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(6)

$$NAME_ContactObj_Title               = "Title"$$


'/*  ContactObj.Suffix
' *
' *  MTP Property: Suffix (0xDD04)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Suffix,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    7);
MACRO PKEY_ContactObj_Suffix = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(7)

$$NAME_ContactObj_Suffix              = "Suffix"$$


'/*  ContactObj.PhoneticGivenName
' *
' *  MTP Property: Phonetic Given Name (0xDD05)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PhoneticGivenName,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    8);
MACRO PKEY_ContactObj_PhoneticGivenName = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(8)

$$NAME_ContactObj_PhoneticGivenName   = "PhoneticGivenName"$$


'/*  ContactObj.PhoneticFamilyName
' *
' *  MTP Property: Phonetic Family Name (0xDD06)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PhoneticFamilyName,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    9);
MACRO PKEY_ContactObj_PhoneticFamilyName = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(9)

$$NAME_ContactObj_PhoneticFamilyName  = "PhoneticFamilyName"$$


'/*  ContactObj.PersonalAddressFull
' *
' *  MTP Property: Postal Address Personal Full (0xDD1F)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressFull,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    10);
MACRO PKEY_ContactObj_PersonalAddressFull = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(10)

$$NAME_ContactObj_PersonalAddressFull = "PersonalAddressFull"$$


'/*  ContactObj.PersonalAddressStreet
' *
' *  MTP Property: Postal Address Line 1 (0xDD20)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressStreet,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    11);
MACRO PKEY_ContactObj_PersonalAddressStreet = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(11)

$$NAME_ContactObj_PersonalAddressStreet       = "PersonalAddressStreet"$$


'/*  ContactObj.PersonalAddressLine2
' *
' *  MTP Property: Postal Address Line 2 (0xDD21)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressLine2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    12);
MACRO PKEY_ContactObj_PersonalAddressLine2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(12)

$$NAME_ContactObj_PersonalAddressLine2        = "PersonalAddressLine2"$$

'/*  ContactObj.PersonalAddressCity
' *
' *  MTP Property: Postal Address Personal City (0xDD22)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressCity,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    13);
MACRO PKEY_ContactObj_PersonalAddressCity = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(13)

$$NAME_ContactObj_PersonalAddressCity         = "PersonalAddressCity"$$


'/*  ContactObj.PersonalAddressRegion
' *
' *  MTP Property: Postal Address Personal Region (0xDD23)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressRegion,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    14);
MACRO PKEY_ContactObj_PersonalAddressRegion = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(14)

$$NAME_ContactObj_PersonalAddressRegion       =  "PersonalAddressRegion"$$


'/*  ContactObj.PersonalAddressPostalCode
' *
' *  MTP Property: Postal Address Personal Postal Code (0xDD24)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressPostalCode,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    15);
MACRO PKEY_ContactObj_PersonalAddressPostalCode = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(15)

$$NAME_ContactObj_PersonalAddressPostalCode = "PersonalAddressPostalCode"$$


'/*  ContactObj.PersonalAddressCountry
' *
' *  MTP Property: Postal Address Personal Country (0xDD25)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalAddressCountry,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    16);
MACRO PKEY_ContactObj_PersonalAddressCountry = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(16)

$$NAME_ContactObj_PersonalAddressCountry = "PersonalAddressCountry"$$


'/*  ContactObj.BusinessAddressFull
' *
' *  MTP Property: Postal Address Business Full (0xDD26)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressFull,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    17);
MACRO PKEY_ContactObj_BusinessAddressFull = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(17)

$$NAME_ContactObj_BusinessAddressFull = "BusinessAddressFull"$$


'/*  ContactObj.BusinessAddressStreet
' *
' *  MTP Property: Postal Address Line 1 (0xDD27)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressStreet,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    18);
MACRO PKEY_ContactObj_BusinessAddressStreet = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(18)

$$NAME_ContactObj_BusinessAddressStreet = "BusinessAddressStreet"$$


'/*  ContactObj.BusinessAddressLine2
' *
' *  MTP Property: Postal Address Line 2 (0xDD28)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressLine2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    19);
MACRO PKEY_ContactObj_BusinessAddressLine2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(19)

$$NAME_ContactObj_BusinessAddressLine2 = "BusinessAddressLine2"$$


'/*  ContactObj.BusinessAddressCity
' *
' *  MTP Property: Postal Address Business City (0xDD29)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressCity,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    20);
MACRO PKEY_ContactObj_BusinessAddressCity = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(20)

$$NAME_ContactObj_BusinessAddressCity = "BusinessAddressCity"$$


'/*  ContactObj.BusinessAddressRegion
' *
' *  MTP Property: Postal Address Business Region (0xDD2A)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressRegion,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    21);
MACRO PKEY_ContactObj_BusinessAddressRegion = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(21)

$$NAME_ContactObj_BusinessAddressRegion = "BusinessAddressRegion"$$


'/*  ContactObj.BusinessAddressPostalCode
' *
' *  MTP Property: Postal Address Business Postal Code (0xDD2B)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressPostalCode,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    22);
MACRO PKEY_ContactObj_BusinessAddressPostalCode = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(22)

$$NAME_ContactObj_BusinessAddressPostalCode = "BusinessAddressPostalCode"$$


'/*  ContactObj.BusinessAddressCountry
' *
' *  MTP Property: Postal Address Business Country (0xDD2C)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessAddressCountry,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    23);
MACRO PKEY_ContactObj_BusinessAddressCountry = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(23)

$$NAME_ContactObj_BusinessAddressCountry = "BusinessAddressCountry"$$

'/*  ContactObj.OtherAddressFull
' *
' *  MTP Property: Postal Address Other Full (0xDD2D)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressFull,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    24);
MACRO PKEY_ContactObj_OtherAddressFull = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(24)

$$NAME_ContactObj_OtherAddressFull = "OtherAddressFull"$$


'/*  ContactObj.OtherAddressStreet
' *
' *  MTP Property: Postal Address Line 1 (0xDD2E)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressStreet,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    25);
MACRO PKEY_ContactObj_OtherAddressStreet = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(25)

$$NAME_ContactObj_OtherAddressStreet = "OtherAddressStreet"$$


'/*  ContactObj.OtherAddressLine2
' *
' *  MTP Property: Postal Address Line 2 (0xDD2F)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressLine2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    26);
MACRO PKEY_ContactObj_OtherAddressLine2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(26)

$$NAME_ContactObj_OtherAddressLine2 = "OtherAddressLine2"$$


'/*  ContactObj.OtherAddressCity
' *
' *  MTP Property: Postal Address Other City (0xDD30)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressCity,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    27);
MACRO PKEY_ContactObj_OtherAddressCity = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(27)

$$NAME_ContactObj_OtherAddressCity = "OtherAddressCity"$$


'/*  ContactObj.OtherAddressRegion
' *
' *  MTP Property: Postal Address Other Region (0xDD31)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressRegion,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    28);
MACRO PKEY_ContactObj_OtherAddressRegion = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(28)

$$NAME_ContactObj_OtherAddressRegion = "OtherAddressRegion"$$


'/*  ContactObj.OtherAddressPostalCode
' *
' *  MTP Property: Postal Address Other Postal Code (0xDD32)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressPostalCode,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    29);
MACRO PKEY_ContactObj_OtherAddressPostalCode = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(29)

$$NAME_ContactObj_OtherAddressPostalCode = "OtherAddressPostalCode"$$


'/*  ContactObj.OtherAddressCountry
' *
' *  MTP Property: Postal Address Other Country (0xDD33)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherAddressCountry,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    30);
MACRO PKEY_ContactObj_OtherAddressCountry = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(30)

$$NAME_ContactObj_OtherAddressCountry = "OtherAddressCountry"$$


'/*  ContactObj.Email
' *
' *  MTP Property: Email Primary (0xDD07)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Email,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    31);
MACRO PKEY_ContactObj_Email = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(31)

$$NAME_ContactObj_Email = "Email"$$


'/*  ContactObj.PersonalEmail
' *
' *  MTP Property: Email Personal 1 (0xDD08)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalEmail,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    32);
MACRO PKEY_ContactObj_PersonalEmail = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(32)

$$NAME_ContactObj_PersonalEmail = "PersonalEmail"$$


'/*  ContactObj.PersonalEmail2
' *
' *  MTP Property: Email Personal 2 (0xDD09)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalEmail2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    33);
MACRO PKEY_ContactObj_PersonalEmail2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(33)

$$NAME_ContactObj_PersonalEmail2 = "PersonalEmail2"$$


'/*  ContactObj.BusinessEmail
' *
' *  MTP Property: Email Business 1 (0xDD0A)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessEmail,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    34);
MACRO PKEY_ContactObj_BusinessEmail = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(34)

$$NAME_ContactObj_BusinessEmail = "BusinessEmail"$$


'/*  ContactObj.BuisnessEmail2
' *
' *  MTP Property: Email Business 2 (0xDD0B)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessEmail2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    35);
MACRO PKEY_ContactObj_BusinessEmail2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(35)

$$NAME_ContactObj_BusinessEmail2 = "BusinessEmail2"$$


'/*  ContactObj.OtherEmail
' *
' *  MTP Property: Email Others (0xDD0C)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherEmail,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    36);
MACRO PKEY_ContactObj_OtherEmail = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(36)

$$NAME_ContactObj_OtherEmail = "OtherEmail"$$


'/*  ContactObj.Phone
' *
' *  MTP Property: Phone Primary (0xDD0D)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Phone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    37);
MACRO PKEY_ContactObj_Phone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(37)

$$NAME_ContactObj_Phone = "Phone"$$


'/*  ContactObj.PersonalPhone
' *
' *  MTP Property: Phone Number Personal 1 (0xDD0E)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalPhone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    38);
MACRO PKEY_ContactObj_PersonalPhone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(38)

$$NAME_ContactObj_PersonalPhone = "PersonalPhone"$$


'/*  ContactObj.PersonalPhone2
' *
' *  MTP Property: Phone Number Personal 2 (0xDD0F)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalPhone2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    39);
MACRO PKEY_ContactObj_PersonalPhone2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(39)

$$NAME_ContactObj_PersonalPhone2 = "PersonalPhone2"$$


'/*  ContactObj.BusinessPhone
' *
' *  MTP Property: Phone Number Business 1 (0xDD10)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessPhone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    40);
MACRO PKEY_ContactObj_BusinessPhone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(40)

$$NAME_ContactObj_BusinessPhone = "BusinessPhone"$$


'/*  ContactObj.BusinessPhone2
' *
' *  MTP Property: Phone Number Business 2 (0xDD11)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessPhone2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    41);
MACRO PKEY_ContactObj_BusinessPhone2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(41)

$$NAME_ContactObj_BusinessPhone2 = "BusinessPhone2"$$


'/*  ContactObj.MobilePhone
' *
' *  MTP Property: Phone Number Mobile 1 (0xDD12)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_MobilePhone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    42);
MACRO PKEY_ContactObj_MobilePhone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(42)

$$NAME_ContactObj_MobilePhone = "MobilePhone"$$


'/*  ContactObj.MobilePhone2
' *
' *  MTP Property: Phone Number Mobile 2 (0xDD13)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_MobilePhone2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    43);
MACRO PKEY_ContactObj_MobilePhone2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(43)

$$NAME_ContactObj_MobilePhone2 = "MobilePhone2"$$


'/*  ContactObj.PersonalFax
' *
' *  MTP Property: Fax Number Personal (0xDD15)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalFax,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    44);
MACRO PKEY_ContactObj_PersonalFax = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(44)

$$NAME_ContactObj_PersonalFax = "PersonalFax"$$


'/*  ContactObj.BusinessFax
' *
' *  MTP Property: Fax Number Business (0xDD16)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessFax,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    45);
MACRO PKEY_ContactObj_BusinessFax = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(45)

$$NAME_ContactObj_BusinessFax = "BusinessFax"$$


'/*  ContactObj.Pager
' *
' *  MTP Property: Pager Number (0xDD17)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Pager,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    46);
MACRO PKEY_ContactObj_Pager = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(46)

$$NAME_ContactObj_Pager = "Pager"$$


'/*  ContactObj.OtherPhone
' *
' *  MTP Property: Phone Number Others (0xDD18)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_OtherPhone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    47);
MACRO PKEY_ContactObj_OtherPhone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(47)

$$NAME_ContactObj_OtherPhone = "OtherPhone"$$


'/*  ContactObj.WebAddress
' *
' *  MTP Property: Primary Web Address (0xDD19)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_WebAddress,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    48);
MACRO PKEY_ContactObj_WebAddress = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(48)

$$NAME_ContactObj_WebAddress = "WebAddress"$$


'/*  ContactObj.PersonalWebAddress
' *
' *  MTP Property: Personal Web Address (0xDD1A)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PersonalWebAddress,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    49);
MACRO PKEY_ContactObj_PersonalWebAddress = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(49)

$$NAME_ContactObj_PersonalWebAddress = "PersonalWebAddress"$$


'/*  ContactObj.BusinessWebAddress
' *
' *  MTP Property: Business Web Address (0xDD1B)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_BusinessWebAddress,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    50);
MACRO PKEY_ContactObj_BusinessWebAddress = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(50)

$$NAME_ContactObj_BusinessWebAddress = "BusinessWebAddress"$$


'/*  ContactObj.IMAddress
' *
' *  MTP Property: Instant Messanger Address (0xDD1C)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_IMAddress,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    51);
MACRO PKEY_ContactObj_IMAddress = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(51)

$$NAME_ContactObj_IMAddress = "IMAddress"$$


'/*  ContactObj.IMAddress2
' *
' *  MTP Property: Instant Messanger Address 2 (0xDD1D)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_IMAddress2,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    52);
MACRO PKEY_ContactObj_IMAddress2 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(52)

$$NAME_ContactObj_IMAddress2 = "IMAddress2"$$


'/*  ContactObj.IMAddress3
' *
' *  MTP Property: Instant Messanger Address 3 (0xDD1E)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_IMAddress3,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    53);
MACRO PKEY_ContactObj_IMAddress3 = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(53)

$$NAME_ContactObj_IMAddress3 = "IMAddress3"$$


'/*  ContactObj.Organization
' *
' *  MTP Property: Organization Name (0xDD34)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Organization,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    54);
MACRO PKEY_ContactObj_Organization = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(54)

$$NAME_ContactObj_Organization = "Organization"$$


'/*  ContactObj.PhoneticOrganization
' *
' *  MTP Property: Phonetic Organization Name (0xDD35)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_PhoneticOrganization,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    55);
MACRO PKEY_ContactObj_PhoneticOrganization = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(55)

$$NAME_ContactObj_PhoneticOrganization = "PhoneticOrganization"$$


'/*  ContactObj.Role
' *
' *  MTP Property: Role (0xDD36)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Role,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    56);
MACRO PKEY_ContactObj_Role = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(56)

$$NAME_ContactObj_Role = "Role"$$


'/*  ContactObj.Fax
' *
' *  MTP Property: Fax Number Primary (0xDD14)
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Fax,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    58);
MACRO PKEY_ContactObj_Fax = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(58)

$$NAME_ContactObj_Fax = "Fax"$$


'/*  ContactObj.Spouse
' *
' *  MTP Property:  ()
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Spouse,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    59);
MACRO PKEY_ContactObj_Spouse = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(59)

$$NAME_ContactObj_Spouse = "Spouse"$$


'/*  ContactObj.Children
' *
' *  MTP Property:  ()
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Children,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    60);
MACRO PKEY_ContactObj_Children = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(60)

$$NAME_ContactObj_Children = "Children"$$


'/*  ContactObj.Assistant
' *
' *  MTP Property:  ()
' *  Type: String/AUInt16
' *  Form: None/RegEx/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Assistant,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    61);
MACRO PKEY_ContactObj_Assistant = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(61)

$$NAME_ContactObj_Assistant = "Assistant"$$


'/*  ContactObj.Ringtone
' *
' *  MTP Property:  ()
' *  Type: UInt32
' *  Form: ObjectID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Ringtone,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    63);
MACRO PKEY_ContactObj_Ringtone = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(63)

$$NAME_ContactObj_Ringtone = "Ringtone"$$


'/*  ContactObj.Birthdate
' *
' *  MTP Property:  (0xDD37)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_Birthdate,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    65);
MACRO PKEY_ContactObj_Birthdate = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(65)

$$NAME_ContactObj_Birthdate = "Birthdate"$$


'/*  ContactObj.AnniversaryDate
' *
' *  MTP Property:  ()
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ContactObj_AnniversaryDate,
'    0xFBD4FDAB, 0x987D, 0x4777, 0xB3, 0xF9, 0x72, 0x61, 0x85, 0xA9, 0x31, 0x2B,
'    66);
MACRO PKEY_ContactObj_AnniversaryDate = GUID$("{FBD4FDAB-987D-4777-B3F9-726185A9312B}") & MKDWD$(66)

$$NAME_ContactObj_AnniversaryDate = "AnniversaryDate"$$
