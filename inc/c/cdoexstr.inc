' ########################################################################################
' Microsoft Windows
' File: cdoexstr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDOEXSTR_INC = 1

' ========================================================================================
' CdoBusyStatusValues
' ========================================================================================

' //   __CdoBusyStatusValues_MODULE_DEFINED__
$$cdoBusy      = "Busy"$$
$$cdoFree      = "Free"$$
$$cdoOOF       = "OOF"$$
$$cdoTentative = "Tentative"$$

' ========================================================================================
' CdoCalendar
' ========================================================================================

' //   __CdoCalendar_MODULE_DEFINED__
$$cdoAllDayEvent               = "urn:schemas:calendar:alldayevent"$$
$$cdoAttendeeRole              = "urn:schemas:calendar:attendeerole"$$
$$cdoAttendeeStatus            = "urn:schemas:calendar:attendeestatus"$$
$$cdoBusyStatus                = "urn:schemas:calendar:busystatus"$$
$$cdoCalendarLastModified      = "urn:schemas:calendar:lastmodified"$$
$$cdoCalendarUID               = "urn:schemas:calendar:uid"$$
$$cdoContact                   = "urn:schemas:calendar:contact"$$
$$cdoContactURL                = "urn:schemas:calendar:contacturl"$$
$$cdoCreated                   = "urn:schemas:calendar:created"$$
$$cdoDelegatedFrom             = "urn:schemas:calendar:delegated-from"$$
$$cdoDelegatedTo               = "urn:schemas:calendar:delegated-to"$$
$$cdoDescriptionURL            = "urn:schemas:calendar:descriptionurl"$$
$$cdoDTEnd                     = "urn:schemas:calendar:dtend"$$
$$cdoDTStamp                   = "urn:schemas:calendar:dtstamp"$$
$$cdoDTStart                   = "urn:schemas:calendar:dtstart"$$
$$cdoDuration                  = "urn:schemas:calendar:duration"$$
$$cdoExDate                    = "urn:schemas:calendar:exdate"$$
$$cdoExRule                    = "urn:schemas:calendar:exrule"$$
$$cdoFburl                     = "urn:schemas:calendar:fburl"$$
$$cdoGEOLatitude               = "urn:schemas:calendar:geolatitude"$$
$$cdoGEOLongitude              = "urn:schemas:calendar:geolongitude"$$
$$cdoInstanceType              = "urn:schemas:calendar:instancetype"$$
$$cdoIsOrganizer               = "urn:schemas:calendar:isorganizer"$$
$$cdoLastModifiedTime          = "urn:schemas:calendar:lastmodifiedtime"$$
$$cdoLocation                  = "urn:schemas:calendar:location"$$
$$cdoLocationURL               = "urn:schemas:calendar:locationurl"$$
$$cdoMeetingStatus             = "urn:schemas:calendar:meetingstatus"$$
$$cdoMethod                    = "urn:schemas:calendar:method"$$
$$cdoProdId                    = "urn:schemas:calendar:prodid"$$
$$cdoRDate                     = "urn:schemas:calendar:rdate"$$
$$cdoRecurrenceId              = "urn:schemas:calendar:recurrenceid"$$
$$cdoRecurrenceIdRange         = "urn:schemas:calendar:recurrenceidrange"$$
$$cdoReminderOffset            = "urn:schemas:calendar:reminderoffset"$$
$$cdoReplyTime                 = "urn:schemas:calendar:replytime"$$
$$cdoResources                 = "urn:schemas:calendar:resources"$$
$$cdoResponseRequested         = "urn:schemas:calendar:responserequested"$$
$$cdoRRule                     = "urn:schemas:calendar:rrule"$$
$$cdoRSVP                      = "urn:schemas:calendar:rsvp"$$
$$cdoSentBy                    = "urn:schemas:calendar:sent-by"$$
$$cdoSequence                  = "urn:schemas:calendar:sequence"$$
$$cdoTimeZoneIDURN             = "urn:schemas:calendar:timezoneid"$$
$$cdoTimeZoneURN               = "urn:schemas:calendar:timezone"$$
$$cdoTransparency              = "urn:schemas:calendar:transparent"$$
$$cdoVersion                   = "urn:schemas:calendar:version"$$

' ========================================================================================
' CdoCharset
' ========================================================================================

' //   __CdoCharset_MODULE_DEFINED__
$$cdoBIG5                      = "big5"$$
$$cdoEUC_JP                    = "euc-jp"$$
$$cdoEUC_KR                    = "euc-kr"$$
$$cdoGB2312                    = "gb2312"$$
$$cdoISO_2022_JP               = "iso-2022-jp"$$
$$cdoISO_2022_KR               = "iso-2022-kr"$$
$$cdoISO_8859_1                = "iso-8859-1"$$
$$cdoISO_8859_2                = "iso-8859-2"$$
$$cdoISO_8859_3                = "iso-8859-3"$$
$$cdoISO_8859_4                = "iso-8859-4"$$
$$cdoISO_8859_5                = "iso-8859-5"$$
$$cdoISO_8859_6                = "iso-8859-6"$$
$$cdoISO_8859_7                = "iso-8859-7"$$
$$cdoISO_8859_8                = "iso-8859-8"$$
$$cdoISO_8859_9                = "iso-8859-9"$$
$$cdoKOI8_R                    = "koi8-r"$$
$$cdoShift_JIS                 = "shift-jis"$$
$$cdoUS_ASCII                  = "us-ascii"$$
$$cdoUTF_7                     = "utf-7"$$
$$cdoUTF_8                     = "utf-8"$$

' ========================================================================================
' CdoConfiguration
' ========================================================================================

' //   __CdoConfiguration_MODULE_DEFINED__
$$cdoActiveConnection          = "http://schemas.microsoft.com/cdo/configuration/activeconnection"$$
$$cdoAutoPromoteBodyParts      = "http://schemas.microsoft.com/cdo/configuration/autopromotebodyparts"$$
$$cdoFlushBuffersOnWrite       = "http://schemas.microsoft.com/cdo/configuration/flushbuffersonwrite"$$
$$cdoHTTPCookies               = "http://schemas.microsoft.com/cdo/configuration/httpcookies"$$
$$cdoLanguageCode              = "http://schemas.microsoft.com/cdo/configuration/languagecode"$$
$$cdoMailboxURL                = "http://schemas.microsoft.com/cdo/configuration/mailboxurl"$$
$$cdoNNTPAccountName           = "http://schemas.microsoft.com/cdo/configuration/nntpaccountname"$$
$$cdoNNTPAuthenticate          = "http://schemas.microsoft.com/cdo/configuration/nntpauthenticate"$$
$$cdoNNTPConnectionTimeout     = "http://schemas.microsoft.com/cdo/configuration/nntpconnectiontimeout"$$
$$cdoNNTPServer                = "http://schemas.microsoft.com/cdo/configuration/nntpserver"$$
$$cdoNNTPServerPickupDirectory = "http://schemas.microsoft.com/cdo/configuration/nntpserverpickupdirectory"$$
$$cdoNNTPServerPort            = "http://schemas.microsoft.com/cdo/configuration/nntpserverport"$$
$$cdoNNTPUseSSL                = "http://schemas.microsoft.com/cdo/configuration/nntpusessl"$$
$$cdoPostEmailAddress          = "http://schemas.microsoft.com/cdo/configuration/postemailaddress"$$
$$cdoPostPassword              = "http://schemas.microsoft.com/cdo/configuration/postpassword"$$
$$cdoPostUserName              = "http://schemas.microsoft.com/cdo/configuration/postusername"$$
$$cdoPostUserReplyEmailAddress = "http://schemas.microsoft.com/cdo/configuration/postuserreplyemailaddress"$$
$$cdoPostUsingMethod           = "http://schemas.microsoft.com/cdo/configuration/postusing"$$
$$cdoSaveSentItems             = "http://schemas.microsoft.com/cdo/configuration/savesentitems"$$
$$cdoSendEmailAddress          = "http://schemas.microsoft.com/cdo/configuration/sendemailaddress"$$
$$cdoSendPassword              = "http://schemas.microsoft.com/cdo/configuration/sendpassword"$$
$$cdoSendUserName              = "http://schemas.microsoft.com/cdo/configuration/sendusername"$$
$$cdoSendUserReplyEmailAddress = "http://schemas.microsoft.com/cdo/configuration/senduserreplyemailaddress"$$
$$cdoSendUsingMethod           = "http://schemas.microsoft.com/cdo/configuration/sendusing"$$
$$cdoSMTPAccountName           = "http://schemas.microsoft.com/cdo/configuration/smtpaccountname"$$
$$cdoSMTPAuthenticate          = "http://schemas.microsoft.com/cdo/configuration/smtpauthenticate"$$
$$cdoSMTPConnectionTimeout     = "http://schemas.microsoft.com/cdo/configuration/smtpconnectiontimeout"$$
$$cdoSMTPServer                = "http://schemas.microsoft.com/cdo/configuration/smtpserver"$$
$$cdoSMTPServerPickupDirectory = "http://schemas.microsoft.com/cdo/configuration/smtpserverpickupdirectory"$$
$$cdoSMTPServerPort            = "http://schemas.microsoft.com/cdo/configuration/smtpserverport"$$
$$cdoSMTPUseSSL                = "http://schemas.microsoft.com/cdo/configuration/smtpusessl"$$
$$cdoURLGetLatestVersion       = "http://schemas.microsoft.com/cdo/configuration/urlgetlatestversion"$$
$$cdoURLProxyBypass            = "http://schemas.microsoft.com/cdo/configuration/urlproxybypass"$$
$$cdoURLProxyServer            = "http://schemas.microsoft.com/cdo/configuration/urlproxyserver"$$
$$cdoURLSource                 = "http://schemas.microsoft.com/cdo/configuration/urlsource"$$
$$cdoUseMessageResponseText    = "http://schemas.microsoft.com/cdo/configuration/usemessageresponsetext"$$

' ========================================================================================
' CdoContacts
' ========================================================================================

' //   __CdoContacts_MODULE_DEFINED__
$$cdoAccount                   = "urn:schemas:contacts:account"$$
$$cdoBirthday                  = "urn:schemas:contacts:bday"$$
$$cdoCallbackPhone             = "urn:schemas:contacts:callbackphone"$$
$$cdoChildrensNames            = "urn:schemas:contacts:childrensnames"$$
$$cdoCommonName                = "urn:schemas:contacts:cn"$$
$$cdoComputerNetworkName       = "urn:schemas:contacts:computernetworkname"$$
$$cdoCustomerId                = "urn:schemas:contacts:customerid"$$
$$cdoDepartment                = "urn:schemas:contacts:department"$$
$$cdoDistinguishedName         = "urn:schemas:contacts:dn"$$
$$cdoEmail1Address             = "urn:schemas:contacts:email1"$$
$$cdoEmail2Address             = "urn:schemas:contacts:email2"$$
$$cdoEmail3Address             = "urn:schemas:contacts:email3"$$
$$cdoEmployeeNumber            = "urn:schemas:contacts:employeenumber"$$
$$cdoFileAs                    = "urn:schemas:contacts:fileas"$$
$$cdoFileAsId                  = "urn:schemas:contacts:fileasid"$$
$$cdoFirstName                 = "urn:schemas:contacts:givenName"$$
$$cdoFtpSite                   = "urn:schemas:contacts:ftpsite"$$
$$cdoGender                    = "urn:schemas:contacts:gender"$$
$$cdoGovernmentId              = "urn:schemas:contacts:governmentid"$$
$$cdoHobbies                   = "urn:schemas:contacts:hobbies"$$
$$cdoHomeCity                  = "urn:schemas:contacts:homeCity"$$
$$cdoHomeCountry               = "urn:schemas:contacts:homeCountry"$$
$$cdoHomeFax                   = "urn:schemas:contacts:homefax"$$
$$cdoHomeLatitude              = "urn:schemas:contacts:homelatitude"$$
$$cdoHomeLongitude             = "urn:schemas:contacts:homelongitude"$$
$$cdoHomePhone                 = "urn:schemas:contacts:homePhone"$$
$$cdoHomePhone2                = "urn:schemas:contacts:homephone2"$$
$$cdoHomePostalAddress         = "urn:schemas:contacts:homepostaladdress"$$
$$cdoHomePostalCode            = "urn:schemas:contacts:homePostalCode"$$
$$cdoHomePostOfficeBox         = "urn:schemas:contacts:homepostofficebox"$$
$$cdoHomeState                 = "urn:schemas:contacts:homeState"$$
$$cdoHomeStreet                = "urn:schemas:contacts:homeStreet"$$
$$cdoHomeTimeZone              = "urn:schemas:contacts:hometimezone"$$
$$cdoInitials                  = "urn:schemas:contacts:initials"$$
$$cdoInternationalISDNNumber   = "urn:schemas:contacts:internationalisdnnumber"$$
$$cdoLanguage                  = "urn:schemas:contacts:language"$$
$$cdoLastName                  = "urn:schemas:contacts:sn"$$
$$cdoMailingAddressId          = "urn:schemas:contacts:mailingaddressid"$$
$$cdoMailingCity               = "urn:schemas:contacts:mailingcity"$$
$$cdoMailingCountry            = "urn:schemas:contacts:mailingcountry"$$
$$cdoMailingPostalAddress      = "urn:schemas:contacts:mailingpostaladdress"$$
$$cdoMailingPostalCode         = "urn:schemas:contacts:mailingpostalcode"$$
$$cdoMailingPostOfficeBox      = "urn:schemas:contacts:mailingpostofficebox"$$
$$cdoMailingState              = "urn:schemas:contacts:mailingstate"$$
$$cdoMailingStreet             = "urn:schemas:contacts:mailingstreet"$$
$$cdoManager                   = "urn:schemas:contacts:manager"$$
$$cdoMapURL                    = "urn:schemas:contacts:mapurl"$$
$$cdoMiddleName                = "urn:schemas:contacts:middlename"$$
$$cdoNamePrefix                = "urn:schemas:contacts:personaltitle"$$
$$cdoNameSuffix                = "urn:schemas:contacts:namesuffix"$$
$$cdoNickname                  = "urn:schemas:contacts:nickname"$$
$$cdoOrganizationName          = "urn:schemas:contacts:o"$$
$$cdoOriginalAuthor            = "urn:schemas:contacts:authorig"$$
$$cdoOtherCity                 = "urn:schemas:contacts:othercity"$$
$$cdoOtherCountry              = "urn:schemas:contacts:othercountry"$$
$$cdoOtherCountryCode          = "urn:schemas:contacts:othercountrycode"$$
$$cdoOtherFax                  = "urn:schemas:contacts:otherfax"$$
$$cdoOtherMobile               = "urn:schemas:contacts:othermobile"$$
$$cdoOtherPager                = "urn:schemas:contacts:otherpager"$$
$$cdoOtherPostalAddress        = "urn:schemas:contacts:otherpostaladdress"$$
$$cdoOtherPostalCode           = "urn:schemas:contacts:otherpostalcode"$$
$$cdoOtherPostOfficeBox        = "urn:schemas:contacts:otherpostofficebox"$$
$$cdoOtherState                = "urn:schemas:contacts:otherstate"$$
$$cdoOtherStreet               = "urn:schemas:contacts:otherstreet"$$
$$cdoOtherTimeZone             = "urn:schemas:contacts:othertimezone"$$
$$cdoOtherWorkPhone            = "urn:schemas:contacts:otherTelephone"$$
$$cdoPersonalURL               = "urn:schemas:contacts:personalHomePage"$$
$$cdoProfession                = "urn:schemas:contacts:profession"$$
$$cdoProxyAddresses            = "urn:schemas:contacts:proxyaddresses"$$
$$cdoRoomNumber                = "urn:schemas:contacts:roomnumber"$$
$$cdoSecretary                 = "urn:schemas:contacts:secretary"$$
$$cdoSecretaryCommonName       = "urn:schemas:contacts:secretarycn"$$
$$cdoSecretaryURL              = "urn:schemas:contacts:secretaryurl"$$
$$cdoSourceURL                 = "urn:schemas:contacts:sourceurl"$$
$$cdoSpouseCommonName          = "urn:schemas:contacts:spousecn"$$
$$cdoSubmissionContLength      = "urn:schemas:contacts:submissioncontlength"$$
$$cdoTelexNumber               = "urn:schemas:contacts:telexnumber"$$
$$cdoTitle                     = "urn:schemas:contacts:title"$$
$$cdoUserCertificate           = "urn:schemas:contacts:usercertificate"$$
$$cdoWeddingAnniversary        = "urn:schemas:contacts:weddinganniversary"$$
$$cdoWorkAddress               = "urn:schemas:contacts:workaddress"$$
$$cdoWorkCity                  = "urn:schemas:contacts:l"$$
$$cdoWorkCountry               = "urn:schemas:contacts:co"$$
$$cdoWorkCountryAbbreviation   = "urn:schemas:contacts:c"$$
$$cdoWorkFax                   = "urn:schemas:contacts:facsimiletelephonenumber"$$
$$cdoWorkMobilePhone           = "urn:schemas:contacts:mobile"$$
$$cdoWorkPager                 = "urn:schemas:contacts:pager"$$
$$cdoWorkPhone                 = "urn:schemas:contacts:telephoneNumber"$$
$$cdoWorkPhone2                = "urn:schemas:contacts:telephonenumber2"$$
$$cdoWorkPostalCode            = "urn:schemas:contacts:postalcode"$$
$$cdoWorkPostOfficeBox         = "urn:schemas:contacts:postofficebox"$$
$$cdoWorkState                 = "urn:schemas:contacts:st"$$
$$cdoWorkStreet                = "urn:schemas:contacts:street"$$

' ========================================================================================
' CdoContentTypeValues
' ========================================================================================

' //   __CdoContentTypeValues_MODULE_DEFINED__
$$cdoGif                       = "image/gif"$$
$$cdoJpeg                      = "image/jpeg"$$
$$cdoMessageExternalBody       = "message/external-body"$$
$$cdoMessagePartial            = "message/partial"$$
$$cdoMessageRFC822             = "message/rfc822"$$
$$cdoMultipartAlternative      = "multipart/alternative"$$
$$cdoMultipartDigest           = "multipart/digest"$$
$$cdoMultipartMixed            = "multipart/mixed"$$
$$cdoMultipartRelated          = "multipart/related"$$
$$cdoTextHTML                  = "text/html"$$
$$cdoTextPlain                 = "text/plain"$$

' ========================================================================================
' CdoDAV
' ========================================================================================

' //   __CdoDAV_MODULE_DEFINED__
$$cdoAbstract                  = "DAV:abstract"$$
$$cdoChildCount                = "DAV:childcount"$$
$$cdoContentClass              = "DAV:contentclass"$$
$$cdoCreationDate              = "DAV:creationdate"$$
$$cdoDAVComment                = "DAV:comment"$$
$$cdoDefaultDocument           = "DAV:defaultdocument"$$
$$cdoDisplayName               = "DAV:displayname"$$
$$cdoGetContentLanguage        = "DAV:getcontentlanguage"$$
$$cdoGetContentLength          = "DAV:getcontentlength"$$
$$cdoGetContentType            = "DAV:getcontenttype"$$
$$cdoGetEtag                   = "DAV:getetag"$$
$$cdoGetLastModified           = "DAV:getlastmodified"$$
$$cdoHasChildren               = "DAV:haschildren"$$
$$cdoHasSubs                   = "DAV:hassubs"$$
$$cdoHref                      = "DAV:href"$$
$$cdoId                        = "DAV:id"$$
$$cdoIsCollection              = "DAV:iscollection"$$
$$cdoIsFolder                  = "DAV:isfolder"$$
$$cdoIsHidden                  = "DAV:ishidden"$$
$$cdoIsRoot                    = "DAV:isroot"$$
$$cdoIsStructuredDocument      = "DAV:isstructureddocument"$$
$$cdoLastAccessed              = "DAV:lastaccessed"$$
$$cdoLastModified              = "DAV:lastmodified"$$
$$cdoLockDiscovery             = "DAV:lockdiscovery"$$
$$cdoNoSubs                    = "DAV:nosubs"$$
$$cdoObjectCount               = "DAV:objectcount"$$
$$cdoParentName                = "DAV:parentname"$$
$$cdoResourceType              = "DAV:resourcetype"$$
$$cdoSupportedLock             = "DAV:supportedlock"$$
$$cdoUID                       = "DAV:uid"$$
$$cdoVisibleCount              = "DAV:visiblecount"$$

' ========================================================================================
' CdoEncodingType
' ========================================================================================

' //   __CdoEncodingType_MODULE_DEFINED__
$$cdo7bit                      = "7bit"$$
$$cdo8bit                      = "8bit"$$
$$cdoBase64                    = "base64"$$
$$cdoBinary                    = "binary"$$
$$cdoMacBinHex40               = "mac-binhex40"$$
$$cdoQuotedPrintable           = "quoted-printable"$$
$$cdoUuencode                  = "uuencode"$$

' ========================================================================================
' CdoExchange
' ========================================================================================

' //   __CdoExchange_MODULE_DEFINED__
$$cdoAltRecipient              = "http://schemas.microsoft.com/exchange/altrecipient"$$
$$cdoCompanies                 = "http://schemas.microsoft.com/exchange/companies"$$
$$cdoFolderSize                = "http://schemas.microsoft.com/exchange/foldersize"$$
$$cdoHardLinkList              = "http://schemas.microsoft.com/exchange/hardlinklist"$$
$$cdoSensitivity               = "http://schemas.microsoft.com/exchange/sensitivity"$$

' ========================================================================================
' CdoHTTPMail
' ========================================================================================

' //   __CdoHTTPMail_MODULE_DEFINED__
$$cdoAttachmentFilename        = "urn:schemas:httpmail:attachmentfilename"$$
$$cdoBcc                       = "urn:schemas:httpmail:bcc"$$
$$cdoCalendarFolderURL         = "urn:schemas:httpmail:calendar"$$
$$cdoCc                        = "urn:schemas:httpmail:cc"$$
$$cdoContactFolderURL          = "urn:schemas:httpmail:contacts"$$
$$cdoContentDispositionType    = "urn:schemas:httpmail:content-disposition-type"$$
$$cdoContentMediaType          = "urn:schemas:httpmail:content-media-type"$$
$$cdoDate                      = "urn:schemas:httpmail:date"$$
$$cdoDateReceived              = "urn:schemas:httpmail:datereceived"$$
$$cdoDeletedItems              = "urn:schemas:httpmail:deleteditems"$$
$$cdoFrom                      = "urn:schemas:httpmail:from"$$
$$cdoHasAttachment             = "urn:schemas:httpmail:hasattachment"$$
$$cdoHTMLDescription           = "urn:schemas:httpmail:htmldescription"$$
$$cdoImportance                = "urn:schemas:httpmail:importance"$$
$$cdoInbox                     = "urn:schemas:httpmail:inbox"$$
$$cdoJournal                   = "urn:schemas:httpmail:journal"$$
$$cdoMsgFolderRoot             = "urn:schemas:httpmail:msgfolderroot"$$
$$cdoNormalizedSubject         = "urn:schemas:httpmail:normalizedsubject"$$
$$cdoNotes                     = "urn:schemas:httpmail:notes"$$
$$cdoOutbox                    = "urn:schemas:httpmail:outbox"$$
$$cdoPriority                  = "urn:schemas:httpmail:priority"$$
$$cdoRead                      = "urn:schemas:httpmail:read"$$
$$cdoReplyTo                   = "urn:schemas:httpmail:reply-to"$$
$$cdoSender                    = "urn:schemas:httpmail:sender"$$
$$cdoSendMsg                   = "urn:schemas:httpmail:sendmsg"$$
$$cdoSentItems                 = "urn:schemas:httpmail:sentitems"$$
$$cdoSpecial                   = "urn:schemas:httpmail:special"$$
$$cdoSubject                   = "urn:schemas:httpmail:subject"$$
$$cdoSubmitted                 = "urn:schemas:httpmail:submitted"$$
$$cdoTasks                     = "urn:schemas:httpmail:tasks"$$
$$cdoTextDescription           = "urn:schemas:httpmail:textdescription"$$
$$cdoThreadTopic               = "urn:schemas:httpmail:thread-topic"$$
$$cdoTo                        = "urn:schemas:httpmail:to"$$
$$cdoUnreadCount               = "urn:schemas:httpmail:unreadcount"$$

' ========================================================================================
' CdoInterfaces
' ========================================================================================

' //   __CdoInterfaces_MODULE_DEFINED__
$$cdoAdoRecord                 = "_Record"$$
$$cdoAdoRecordset              = "_Recordset"$$
$$cdoAdoStream                 = "_Stream"$$
$$cdoIAddressee                = "IAddressee"$$
$$cdoIAppointment              = "IAppointment"$$
$$cdoIBodyPart                 = "IBodyPart"$$
$$cdoICalendarMessage          = "ICalendarMessage"$$
$$cdoICalendarPart             = "ICalendarPart"$$
$$cdoICalendarParts            = "ICalendarParts"$$
$$cdoIConfiguration            = "IConfiguration"$$
$$cdoIDataSource               = "IDataSource"$$
$$cdoIFolder                   = "IFolder"$$
$$cdoIItem                     = "IItem"$$
$$cdoIMailbox                  = "IMailbox"$$
$$cdoIMessage                  = "IMessage"$$
$$cdoIPerson                   = "IPerson"$$
$$cdoIRow                      = "IRow"$$
$$cdoIRowset                   = "IRowset"$$
$$cdoIStream                   = "IStream"$$

' ========================================================================================
' CdoMailHeader
' ========================================================================================

' //   __CdoMailHeader_MODULE_DEFINED__
$$cdoApproved                  = "urn:schemas:mailheader:approved"$$
$$cdoComment                   = "urn:schemas:mailheader:comment"$$
$$cdoContentBase               = "urn:schemas:mailheader:content-base"$$
$$cdoContentDescription        = "urn:schemas:mailheader:content-description"$$
$$cdoContentDisposition        = "urn:schemas:mailheader:content-disposition"$$
$$cdoContentId                 = "urn:schemas:mailheader:content-id"$$
$$cdoContentLanguage           = "urn:schemas:mailheader:content-language"$$
$$cdoContentLocation           = "urn:schemas:mailheader:content-location"$$
$$cdoContentTransferEncoding   = "urn:schemas:mailheader:content-transfer-encoding"$$
$$cdoContentType               = "urn:schemas:mailheader:content-type"$$
$$cdoControl                   = "urn:schemas:mailheader:control"$$
$$cdoDisposition               = "urn:schemas:mailheader:disposition"$$
$$cdoDispositionNotificationTo = "urn:schemas:mailheader:disposition-notification-to"$$
$$cdoDistribution              = "urn:schemas:mailheader:distribution"$$
$$cdoExpires                   = "urn:schemas:mailheader:expires"$$
$$cdoFollowupTo                = "urn:schemas:mailheader:followup-to"$$
$$cdoInReplyTo                 = "urn:schemas:mailheader:in-reply-to"$$
$$cdoLines                     = "urn:schemas:mailheader:lines"$$
$$cdoMessageId                 = "urn:schemas:mailheader:message-id"$$
$$cdoMIMEVersion               = "urn:schemas:mailheader:mime-version"$$
$$cdoNewsgroups                = "urn:schemas:mailheader:newsgroups"$$
$$cdoOrganization              = "urn:schemas:mailheader:organization"$$
$$cdoOriginalRecipient         = "urn:schemas:mailheader:original-recipient"$$
$$cdoPath                      = "urn:schemas:mailheader:path"$$
$$cdoPostingVersion            = "urn:schemas:mailheader:posting-version"$$
$$cdoReceived                  = "urn:schemas:mailheader:received"$$
$$cdoReferences                = "urn:schemas:mailheader:references"$$
$$cdoRelayVersion              = "urn:schemas:mailheader:relay-version"$$
$$cdoReturnPath                = "urn:schemas:mailheader:return-path"$$
$$cdoReturnReceiptTo           = "urn:schemas:mailheader:return-receipt-to"$$
$$cdoSummary                   = "urn:schemas:mailheader:summary"$$
$$cdoThreadIndex               = "urn:schemas:mailheader:thread-index"$$
$$cdoXMailer                   = "urn:schemas:mailheader:x-mailer"$$
$$cdoXref                      = "urn:schemas:mailheader:xref"$$
$$cdoXUnsent                   = "urn:schemas:mailheader:x-unsent"$$

' ========================================================================================
' CdoMeetingStatusValues
' ========================================================================================

' //   __CdoMeetingStatusValues_MODULE_DEFINED__
$$cdoMeetingStatusCancelled    = "Cancelled"$$
$$cdoMeetingStatusConfirmed    = "Confirmed"$$
$$cdoMeetingStatusTentative    = "Tentative"$$

' ========================================================================================
' CdoMethodValues
' ========================================================================================

' //   __CdoMethodValues_MODULE_DEFINED__
$$cdoAdd                       = "Add"$$
$$cdoCancel                    = "Cancel"$$
$$cdoCounter                   = "Counter"$$
$$cdoDeclineCounter            = "DeclineCounter"$$
$$cdoPublish                   = "Publish"$$
$$cdoRefresh                   = "Refresh"$$
$$cdoReply                     = "Reply"$$
$$cdoRequest                   = "Request"$$

' ========================================================================================
' CdoNamespace
' ========================================================================================

' //   __CdoNamespace_MODULE_DEFINED__
$$cdoNSCalendar                = "urn:schemas:calendar:"$$
$$cdoNSConfiguration           = "http://schemas.microsoft.com/cdo/configuration/"$$
$$cdoNSContacts                = "urn:schemas:contacts:"$$
$$cdoNSDAV                     = "DAV:"$$
$$cdoNSHTTPMail                = "urn:schemas:httpmail:"$$
$$cdoNSMailHeader              = "urn:schemas:mailheader:"$$
$$cdoNSNNTPEnvelope            = "http://schemas.microsoft.com/cdo/nntpenvelope/"$$
$$cdoNSSMTPEnvelope            = "http://schemas.microsoft.com/cdo/smtpenvelope/"$$
$$cdoNSVCAL                    = "urn:schemas:vcal:"$$

' ========================================================================================
' CdoNNTPEnvelope
' ========================================================================================

' //   __CdoNNTPEnvelope_MODULE_DEFINED__
$$cdoNewsgroupList             = "http://schemas.microsoft.com/cdo/nntpenvelope/newsgrouplist"$$
$$cdoNNTPProcessing            = "http://schemas.microsoft.com/cdo/nntpenvelope/nntpprocessing"$$

' ========================================================================================
' CdoOffice
' ========================================================================================

' //   __CdoOffice_MODULE_DEFINED__
$$cdoKeywords                  = "urn:schemas-microsoft-com:office:office#Keywords"$$

' ========================================================================================
' CdoRecurrenceIdRangeValues
' ========================================================================================

' //   __CdoRecurrenceIdRangeValues_MODULE_DEFINED__
$$cdoNone                      = "None"$$
$$cdoThisAndFuture             = "ThisAndFuture"$$
$$cdoThisAndPrior              = "ThisAndPrior"$$

' ========================================================================================
' CdoSMTPEnvelope
' ========================================================================================

' //   __CdoSMTPEnvelope_MODULE_DEFINED__
$$cdoArrivalTime               = "http://schemas.microsoft.com/cdo/smtpenvelope/arrivaltime"$$
$$cdoClientIPAddress           = "http://schemas.microsoft.com/cdo/smtpenvelope/clientipaddress"$$
$$cdoMessageStatus             = "http://schemas.microsoft.com/cdo/smtpenvelope/messagestatus"$$
$$cdoPickupFileName            = "http://schemas.microsoft.com/cdo/smtpenvelope/pickupfilename"$$
$$cdoRecipientList             = "http://schemas.microsoft.com/cdo/smtpenvelope/recipientlist"$$
$$cdoSenderEmailAddress        = "http://schemas.microsoft.com/cdo/smtpenvelope/senderemailaddress"$$

' ========================================================================================
' CdoTransparentValues
' ========================================================================================

' //   __CdoTransparentValues_MODULE_DEFINED__
$$cdoOpaque                    = "Opaque"$$
$$cdoTransparent               = "Transparent"$$

' //   __CdoErrors_MODULE_DEFINED__
