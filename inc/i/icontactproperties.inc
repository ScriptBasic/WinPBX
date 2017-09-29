' ########################################################################################
' Microsoft Windows
' File: IContactProperties.inc
' Contents: Defines how the contact schema is used to read and write contact properties
' via IContactProperties.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ICONTACTPROPERTIES_INC = 1

'// ===================================================================
'// Windows contact schema
'//
'// DESCRIPTION:
'//      This defines how the contact schema is used to read and write
'//  contact properties via IContactProperties.
'//
'//
'// STRUCTURE:
'//      Contact properties fall into one of two categories:
'//
'//  Category 1 - Single Value: These properties have a single simple value
'//                      and don't require a hierarchy structure.
'//
'//  Category 2 - Hierarchical: These properties have multiple values for any contact
'//                      and require labeling to differentiate individual values.
'//
'//                      PhoneNumber is one example of this type of property
'//                      Any given contact can have one or more home, work, and mobile phone numbers.
'//
'//
'// PROPERTY EXTENSIBILITY:
'//      All applications that use contacts need to have additional data available
'//      on contacts that the base schema does not provide for.
'//
'//      There are two ways supported by IContactProperties to extend the contact schema.
'//
'//      1) Labels (arbitrary strings) can be applied to any existing OS contact array node.
'//          Ex: phoneNumbers/PhoneNumber[1] can be labeled with the two labels: Preferred and Business.
'//
'//              The set of built-in labels for all multi value properties are:
'//                    Preferred
'//                    Personal
'//                    Business
'//                    Other
'//
'//                Some collections can have more labels set (PhoneNumber can have Mobile, Fax, ...)
'//
'//              Additional labels can be set.  Custom labels must be in the form of URIs.
'//
'//              Manipulation of labels can be done with IContactProperties::GetLabel / SetLabel / DeleteLabels
'//
'//              Filtering of data contact can be done with IContactProperties::GetPropertyCollection
'//
'//      2) New contact properties and array nodes can be defined by an application.
'//            The data contained in these properties can be enumerated by other users of IContactProperties
'//
'//          To create a new property for an application, the same interface is used as standard properties.
'//            Use the same property Set functions as built in properties.  The caller must prepend
'//            a string with a namespace (in braces) for the contact property.
'//
'//              **NB: make sure the selected namespace is unique to avoid conflicts with other applications**
'//
'//           For the application custom.exe to Get or Set a new string property, use:
'//              ex:   [CustomNameSpace]CustomStringProperty
'//
'//           Creating new multivalue properties is also supported.
'//            The above syntax is extended to include an array node name
'//            for the the call to IContactProperties::CreateArrayNode
'//
'//              ex:   [CustomNameSpace:CustomArrayNodeName]customArrayName
'//
'//            CreateArrayNode will return the new property name (as always) in the outbound arguments.
'//
'//===================================================================

'// ===================================================================
'// Single Value properties
'//
'// DESCRIPTION:
'//      These properties are simple and have no hierarchy.
'//

'//
'// String properties
'//

'// free text content
$$CONTACTPROP_PUB_NOTES                       = "Notes"$$

'// contact's email program
$$CONTACTPROP_PUB_MAILER                      = "Mailer"$$
'// ProgID
$$CONTACTPROP_PUB_PROGID                      = "ProgID"$$

'// gender of contact
'// Chooose one of L"Male", L"Female", L"Unspecified" (default)
$$CONTACTPROP_PUB_GENDER                      = "Gender"$$

$$CONTACTPROP_PUB_GENDER_UNSPECIFIED          = "Unspecified"$$
$$CONTACTPROP_PUB_GENDER_MALE                 = "Male"$$
$$CONTACTPROP_PUB_GENDER_FEMALE               = "Female"$$

'//
'// DateTime Properties
'//

'// The date and time the contact was created in the system
$$CONTACTPROP_PUB_CREATIONDATE                = "CreationDate"$$


'// ===================================================================
'// Hierarchical properties
'//
'// DESCRIPTION:
'//      These properties contain many values differentiated by labels
'//
'//      Individual properties are accessed via IContactProperties by index
'//
'//      examples property names include:
'//          PhoneNumberCollection/PhoneNumber[1]/Number
'//              for the 1st phone number on the contact
'//
'//          EmailAddressCollection/EmailAddress[4]/Address
'//              for the 4th email address on the contact
'//
'//      Labels differentiate second level entries(L2) entries.
'//          Programmatic access for labels is via IContactProperties (see icontact.idl)
'//

'//
'// collection of ContactIDs associated with this contact
'//
$$CONTACTPROP_PUB_L1_CONTACTIDCOLLECTION      = "ContactIDCollection"$$
'// an entry in the collection of IDs
$$CONTACTPROP_PUB_L2_CONTACTID                = "/ContactID"$$
'// one of the unique identifiers for this contact (as a string)
$$CONTACTPROP_PUB_L3_VALUE                    = "/Value"$$

'//
'// collection of names associated with this contact
'//
$$CONTACTPROP_PUB_L1_NAMECOLLECTION           = "NameCollection"$$
'// an entry in the collection of names
$$CONTACTPROP_PUB_L2_NAME                     = "/Name"$$

'//
'// Contact data related to names
'//

'// as displayed
$$CONTACTPROP_PUB_L3_FORMATTEDNAME                    = "/FormattedName"$$
'// as pronounced
$$CONTACTPROP_PUB_L3_PHONETIC                         = "/Phonetic"$$

$$CONTACTPROP_PUB_L3_PREFIX                           = "/Prefix"$$
$$CONTACTPROP_PUB_L3_TITLE                            = "/Title"$$
$$CONTACTPROP_PUB_L3_GIVENNAME                        = "/GivenName"$$
$$CONTACTPROP_PUB_L3_FAMILYNAME                       = "/FamilyName"$$
$$CONTACTPROP_PUB_L3_MIDDLENAME                       = "/MiddleName"$$
$$CONTACTPROP_PUB_L3_GENERATION                       = "/Generation"$$
$$CONTACTPROP_PUB_L3_SUFFIX                           = "/Suffix"$$
$$CONTACTPROP_PUB_L3_NICKNAME                         = "/NickName"$$

'//
'// Contact data relating to positions a contact holds
'//
$$CONTACTPROP_PUB_L1_POSITIONCOLLECTION       = "PositionCollection"$$
'// an entry in the collection of names
$$CONTACTPROP_PUB_L2_POSITION                 = "/Position"$$

'// the organization ex: IEEE
$$CONTACTPROP_PUB_L3_ORGANIZATION                     = "/Organization"$$
'// the company ex: Microsoft
$$CONTACTPROP_PUB_L3_COMPANY                          = "/Company"$$
'// the department ex: Windows
$$CONTACTPROP_PUB_L3_DEPARTMENT                       = "/Department"$$
'// the office ex: Building A / Office 1234
$$CONTACTPROP_PUB_L3_OFFICE                           = "/Office"$$
'// any job title ex: Software Engineer
$$CONTACTPROP_PUB_L3_JOB_TITLE                        = "/JobTitle"$$
'// the line of work ex: Engineering
$$CONTACTPROP_PUB_L3_PROFESSION                       = "/Profession"$$
'// the role in the organization ex: Quality Assurance
$$CONTACTPROP_PUB_L3_ROLE                             = "/Role"$$

'//
'// people associated with the contact
'//
$$CONTACTPROP_PUB_L1_PERSONCOLLECTION         = "PersonCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_PERSON                   = "/Person"$$
'//
'// Use labels to indicate the relationship to contact
'// ex:
'//      wab:Spouse
'//      wab:Child
'//      wab:Manager
'//      wab:Assistant

'// person's formatted (display) name - (as string)
$$CONTACTPROP_PUB_L3_FORMATTEDNAME            = "/FormattedName"$$

'// a unique identifier for this person (optional),
'// which may be one of the ContactIDs contained in an IContact
$$CONTACTPROP_PUB_L3_PERSONID                 = "/PersonID"$$

'//
'// calendar dates associated with the contact
'//
$$CONTACTPROP_PUB_L1_DATECOLLECTION           = "DateCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_DATE                     = "/Date"$$
'//
'// Use labels to indicate the type of data being expressed.
'// ex:
'//    wab:Birthday - the date of birth for the contact
'//    wab:Anniversary - the spouse anniversary date for the contact

'// value for this date, as a DateTime
$$CONTACTPROP_PUB_L3_VALUE                    = "/Value"$$

'//
'// email addresses
'//
$$CONTACTPROP_PUB_L1_EMAILADDRESSCOLLECTION   = "EmailAddressCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_EMAILADDRESS             = "/EmailAddress"$$
'// example@microsoft.com (as string)
$$CONTACTPROP_PUB_L3_ADDRESS                  = "/Address"$$
'// type of address (e.g. SMTP, x509)
$$CONTACTPROP_PUB_L3_TYPE                     = "/Type"$$


'//
'// certificate data and thumbprints
'//

$$CONTACTPROP_PUB_L1_CERTIFICATECOLLECTION        = "CertificateCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_CERTIFICATE                  = "/Certificate"$$
'// certificate value
$$CONTACTPROP_PUB_L3_VALUE                        = "/Value"$$
'// thumbprint value
$$CONTACTPROP_PUB_L3_THUMBPRINT                   = "/ThumbPrint"$$

'//
'// phone numbers
'//
$$CONTACTPROP_PUB_L1_PHONENUMBERCOLLECTION    = "PhoneNumberCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_PHONENUMBER              = "/PhoneNumber"$$
'// normal number to display (as string)
$$CONTACTPROP_PUB_L3_NUMBER                   = "/Number"$$
'// alternate number (tty) (as string)
$$CONTACTPROP_PUB_L3_ALTERNATE                = "/Alternate"$$


'//
'// physical addresses
'//
$$CONTACTPROP_PUB_L1_PHYSICALADDRESSCOLLECTION    = "PhysicalAddressCollection"$$
'// entry in the collection
$$CONTACTPROP_PUB_L2_PHYSICALADDRESS              = "/PhysicalAddress"$$
'// the exact data that a mailing label should have
$$CONTACTPROP_PUB_L3_ADDRESSLABEL                 = "/AddressLabel"$$
'// number and street
$$CONTACTPROP_PUB_L3_STREET                       = "/Street"$$
'// City
$$CONTACTPROP_PUB_L3_LOCALITY                     = "/Locality"$$
'// State/Providence
$$CONTACTPROP_PUB_L3_REGION                       = "/Region"$$
'// Zip / PostalCode
$$CONTACTPROP_PUB_L3_POSTALCODE                   = "/PostalCode"$$
'// the country
$$CONTACTPROP_PUB_L3_COUNTRY                      = "/Country"$$
'// any POBox number
$$CONTACTPROP_PUB_L3_POBOX                        = "/POBox"$$
'// any extra information
$$CONTACTPROP_PUB_L3_EXTENDEDADDRESS              = "/ExtendedAddress"$$

'//
'// Instant Messaging Addresess and protocols
'//
$$CONTACTPROP_PUB_L1_IMADDRESSCOLLECTION          = "IMAddressCollection"$$
$$CONTACTPROP_PUB_L2_IMADDRESSENTRY               = "/IMAddress"$$
'// the identifing data for this ImAddress (ex: username@microsoft.com)
$$CONTACTPROP_PUB_L3_VALUE                        = "/Value"$$
'// the string protocol used for this ImAddress (ex: Messenger Protocol)
$$CONTACTPROP_PUB_L3_PROTOCOL                     = "/Protocol"$$

'//
'// collection of URLs associated with this contact
'//
$$CONTACTPROP_PUB_L1_URLCOLLECTION            = "UrlCollection"$$
'// an entry in the collection of url
$$CONTACTPROP_PUB_L2_URL                      = "/Url"$$
'// the actual URL data
$$CONTACTPROP_PUB_L3_VALUE                    = "/Value"$$

'//
'// collection of images associated with this contact
'//
$$CONTACTPROP_PUB_L1_PHOTOCOLLECTION          = "PhotoCollection"$$
'// an entry in the collection of photos
$$CONTACTPROP_PUB_L2_PHOTO                    = "/Photo"$$
'// an image to use for representing the contact - as binary, with MIME type
$$CONTACTPROP_PUB_L3_VALUE                    = "/Value"$$
'// a URL for retrieving the image - as a string
$$CONTACTPROP_PUB_L3_URL                      = "/Url"$$


'// ===================================================================
'//
'// Common Labels that may be associated with any contact properties.
'//

'//
'// Labels can also be URIs.  See comment at beginning of this file
'//

'// NOTE: many entries in a set may have this "Preferred" label set
$$CONTACTLABEL_PUB_PREFERRED                   = "Preferred"$$

'// Home related data
$$CONTACTLABEL_PUB_PERSONAL                    = "Personal"$$

'// Work related data
$$CONTACTLABEL_PUB_BUSINESS                    = "Business"$$

'// other, non specified label
$$CONTACTLABEL_PUB_OTHER                       = "Other"$$

'//
'// Labels that can be associated with PhoneNumber elements
'//

'// number supports voice conversation
$$CONTACTLABEL_PUB_VOICE                       = "Voice"$$

'// mobile phone number
$$CONTACTLABEL_PUB_MOBILE                      = "Mobile"$$

'// PCS support
$$CONTACTLABEL_PUB_PCS                         = "PCS"$$

'// cell phone support
$$CONTACTLABEL_PUB_CELLULAR                    = "Cellular"$$

'// number travel with the Car
$$CONTACTLABEL_PUB_CAR                         = "Car"$$

'// pager number
$$CONTACTLABEL_PUB_PAGER                       = "Pager"$$

'// tty machine
$$CONTACTLABEL_PUB_TTY                         = "TTY"$$

'// fax machine
$$CONTACTLABEL_PUB_FAX                         = "Fax"$$

'// number supports video conversation
$$CONTACTLABEL_PUB_VIDEO                       = "Video"$$

'// number for modem connection
$$CONTACTLABEL_PUB_MODEM                       = "Modem"$$

'// number for BBS connection
$$CONTACTLABEL_PUB_BBS                         = "BBS"$$

'// number for ISDN
$$CONTACTLABEL_PUB_ISDN                        = "ISDN"$$


'//
'// Labels that can be associated with Person elements
'//

'// to indicate this person is allowed to work on behalf of the contact
$$CONTACTLABEL_PUB_AGENT                       = "Agent"$$

'//
'// Labels that can be associated with PhysicalAddress elements
'//

'// a domestic mailing address
$$CONTACTLABEL_PUB_DOMESTIC                    = "Domestic"$$

'// an international mailing address
$$CONTACTLABEL_PUB_INTERNATIONAL               = "International"$$

'// a mailing address which accepts mail
$$CONTACTLABEL_PUB_POSTAL                      = "Postal"$$

'// a mailing address that accepts packages
$$CONTACTLABEL_PUB_PARCEL                      = "Parcel"$$


'//
'// Labels that can be associated with Photo elements
'//

'// an image used to represent the contact
$$CONTACTLABEL_PUB_USERTILE                    = "UserTile"$$

'// a logo associated with the contact (ex: image for organization)
$$CONTACTLABEL_PUB_LOGO                        = "Logo"$$

'//
'// windows address book specific labels
'//

'// for PersonCollection
$$CONTACTLABEL_WAB_SPOUSE                      = "wab:Spouse"$$
$$CONTACTLABEL_WAB_CHILD                       = "wab:Child"$$
$$CONTACTLABEL_WAB_MANAGER                     = "wab:Manager"$$
$$CONTACTLABEL_WAB_ASSISTANT                   = "wab:Assistant"$$

'// for DateCollection
$$CONTACTLABEL_WAB_BIRTHDAY                    = "wab:Birthday"$$
$$CONTACTLABEL_WAB_ANNIVERSARY                 = "wab:Anniversary"$$

'// for UrlCollection
$$CONTACTLABEL_WAB_SOCIALNETWORK               = "wab:SocialNetwork"$$
$$CONTACTLABEL_WAB_SCHOOL                      = "wab:School"$$
$$CONTACTLABEL_WAB_WISHLIST                    = "wab:WishList"$$
