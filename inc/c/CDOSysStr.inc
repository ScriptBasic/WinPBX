' ########################################################################################
' Microsoft Windows
' File: CDOSysStr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDOSYSSTR_INC = 1

'//   __CdoCalendar_MODULE_DEFINED__
$$cdoTimeZoneIDURN = "urn:schemas:calendar:timezoneid"$$

'//   __CdoCharset_MODULE_DEFINED__
$$cdoBIG5        = "big5"$$
$$cdoEUC_JP      = "euc-jp"$$
$$cdoEUC_KR      = "euc-kr"$$
$$cdoGB2312      = "gb2312"$$
$$cdoISO_2022_JP = "iso-2022-jp"$$
$$cdoISO_2022_KR = "iso-2022-kr"$$
$$cdoISO_8859_1  = "iso-8859-1"$$
$$cdoISO_8859_2  = "iso-8859-2"$$
$$cdoISO_8859_3  = "iso-8859-3"$$
$$cdoISO_8859_4  = "iso-8859-4"$$
$$cdoISO_8859_5  = "iso-8859-5"$$
$$cdoISO_8859_6  = "iso-8859-6"$$
$$cdoISO_8859_7  = "iso-8859-7"$$
$$cdoISO_8859_8  = "iso-8859-8"$$
$$cdoISO_8859_9  = "iso-8859-9"$$
$$cdoKOI8_R      = "koi8-r"$$
$$cdoShift_JIS   = "shift-jis"$$
$$cdoUS_ASCII    = "us-ascii"$$
$$cdoUTF_7       = "utf-7"$$
$$cdoUTF_8       = "utf-8"$$
$$cdoISO_8859_15 = "iso-8859-15"$$


'//   __CdoConfiguration_MODULE_DEFINED__
$$cdoAutoPromoteBodyParts = "http://schemas.microsoft.com/cdo/configuration/autopromotebodyparts"$$
$$cdoFlushBuffersOnWrite = "http://schemas.microsoft.com/cdo/configuration/flushbuffersonwrite"$$
$$cdoHTTPCookies = "http://schemas.microsoft.com/cdo/configuration/httpcookies"$$
$$cdoLanguageCode = "http://schemas.microsoft.com/cdo/configuration/languagecode"$$
$$cdoNNTPAccountName = "http://schemas.microsoft.com/cdo/configuration/nntpaccountname"$$
$$cdoNNTPAuthenticate = "http://schemas.microsoft.com/cdo/configuration/nntpauthenticate"$$
$$cdoNNTPConnectionTimeout = "http://schemas.microsoft.com/cdo/configuration/nntpconnectiontimeout"$$
$$cdoNNTPServer = "http://schemas.microsoft.com/cdo/configuration/nntpserver"$$
$$cdoNNTPServerPickupDirectory = "http://schemas.microsoft.com/cdo/configuration/nntpserverpickupdirectory"$$
$$cdoNNTPServerPort = "http://schemas.microsoft.com/cdo/configuration/nntpserverport"$$
$$cdoNNTPUseSSL = "http://schemas.microsoft.com/cdo/configuration/nntpusessl"$$
$$cdoPostEmailAddress = "http://schemas.microsoft.com/cdo/configuration/postemailaddress"$$
$$cdoPostPassword = "http://schemas.microsoft.com/cdo/configuration/postpassword"$$
$$cdoPostUserName = "http://schemas.microsoft.com/cdo/configuration/postusername"$$
$$cdoPostUserReplyEmailAddress = "http://schemas.microsoft.com/cdo/configuration/postuserreplyemailaddress"$$
$$cdoPostUsingMethod = "http://schemas.microsoft.com/cdo/configuration/postusing"$$
$$cdoSaveSentItems = "http://schemas.microsoft.com/cdo/configuration/savesentitems"$$
$$cdoSendEmailAddress = "http://schemas.microsoft.com/cdo/configuration/sendemailaddress"$$
$$cdoSendPassword = "http://schemas.microsoft.com/cdo/configuration/sendpassword"$$
$$cdoSendUserName = "http://schemas.microsoft.com/cdo/configuration/sendusername"$$
$$cdoSendUserReplyEmailAddress = "http://schemas.microsoft.com/cdo/configuration/senduserreplyemailaddress"$$
$$cdoSendUsingMethod = "http://schemas.microsoft.com/cdo/configuration/sendusing"$$
$$cdoSMTPAccountName = "http://schemas.microsoft.com/cdo/configuration/smtpaccountname"$$
$$cdoSMTPAuthenticate = "http://schemas.microsoft.com/cdo/configuration/smtpauthenticate"$$
$$cdoSMTPConnectionTimeout = "http://schemas.microsoft.com/cdo/configuration/smtpconnectiontimeout"$$
$$cdoSMTPServer = "http://schemas.microsoft.com/cdo/configuration/smtpserver"$$
$$cdoSMTPServerPickupDirectory = "http://schemas.microsoft.com/cdo/configuration/smtpserverpickupdirectory"$$
$$cdoSMTPServerPort = "http://schemas.microsoft.com/cdo/configuration/smtpserverport"$$
$$cdoSMTPUseSSL = "http://schemas.microsoft.com/cdo/configuration/smtpusessl"$$
$$cdoURLGetLatestVersion = "http://schemas.microsoft.com/cdo/configuration/urlgetlatestversion"$$
$$cdoURLProxyBypass = "http://schemas.microsoft.com/cdo/configuration/urlproxybypass"$$
$$cdoURLProxyServer = "http://schemas.microsoft.com/cdo/configuration/urlproxyserver"$$
$$cdoUseMessageResponseText = "http://schemas.microsoft.com/cdo/configuration/usemessageresponsetext"$$

'//   __CdoContentTypeValues_MODULE_DEFINED__
$$cdoGif = "image/gif"$$
$$cdoJpeg = "image/jpeg"$$
$$cdoMessageExternalBody = "message/external-body"$$
$$cdoMessagePartial = "message/partial"$$
$$cdoMessageRFC822 = "message/rfc822"$$
$$cdoMultipartAlternative = "multipart/alternative"$$
$$cdoMultipartDigest = "multipart/digest"$$
$$cdoMultipartMixed = "multipart/mixed"$$
$$cdoMultipartRelated = "multipart/related"$$
$$cdoTextHTML = "text/html"$$
$$cdoTextPlain = "text/plain"$$

'//   __CdoDAV_MODULE_DEFINED__
$$cdoContentClass   = "DAV:contentclass"$$
$$cdoGetContentType = "DAV:getcontenttype"$$

'//   __CdoEncodingType_MODULE_DEFINED__
$$cdo7bit            = "7bit"$$
$$cdo8bit            = "8bit"$$
$$cdoBase64          = "base64"$$
$$cdoBinary          = "binary"$$
$$cdoMacBinHex40     = "mac-binhex40"$$
$$cdoQuotedPrintable = "quoted-printable"$$
$$cdoUuencode        = "uuencode"$$

'//   __CdoExchange_MODULE_DEFINED__
$$cdoSensitivity = "http://schemas.microsoft.com/exchange/sensitivity"$$

'//   __CdoHTTPMail_MODULE_DEFINED__
$$cdoAttachmentFilename = "urn:schemas:httpmail:attachmentfilename"$$
$$cdoBcc = "urn:schemas:httpmail:bcc"$$
$$cdoCc = "urn:schemas:httpmail:cc"$$
$$cdoContentDispositionType = "urn:schemas:httpmail:content-disposition-type"$$
$$cdoContentMediaType = "urn:schemas:httpmail:content-media-type"$$
$$cdoDate = "urn:schemas:httpmail:date"$$
$$cdoDateReceived = "urn:schemas:httpmail:datereceived"$$
$$cdoFrom = "urn:schemas:httpmail:from"$$
$$cdoHasAttachment = "urn:schemas:httpmail:hasattachment"$$
$$cdoHTMLDescription = "urn:schemas:httpmail:htmldescription"$$
$$cdoImportance = "urn:schemas:httpmail:importance"$$
$$cdoNormalizedSubject = "urn:schemas:httpmail:normalizedsubject"$$
$$cdoPriority = "urn:schemas:httpmail:priority"$$
$$cdoReplyTo = "urn:schemas:httpmail:reply-to"$$
$$cdoSender = "urn:schemas:httpmail:sender"$$
$$cdoSubject = "urn:schemas:httpmail:subject"$$
$$cdoTextDescription = "urn:schemas:httpmail:textdescription"$$
$$cdoThreadTopic = "urn:schemas:httpmail:thread-topic"$$
$$cdoTo = "urn:schemas:httpmail:to"$$

'//   __CdoInterfaces_MODULE_DEFINED__
$$cdoAdoStream      = "_Stream"$$
$$cdoIBodyPart      = "IBodyPart"$$
$$cdoIConfiguration = "IConfiguration"$$
$$cdoIDataSource    = "IDataSource"$$
$$cdoIMessage       = "IMessage"$$
$$cdoIStream        = "IStream"$$

'//   __CdoMailHeader_MODULE_DEFINED__
$$cdoApproved = "urn:schemas:mailheader:approved"$$
$$cdoComment = "urn:schemas:mailheader:comment"$$
$$cdoContentBase = "urn:schemas:mailheader:content-base"$$
$$cdoContentDescription = "urn:schemas:mailheader:content-description"$$
$$cdoContentDisposition = "urn:schemas:mailheader:content-disposition"$$
$$cdoContentId = "urn:schemas:mailheader:content-id"$$
$$cdoContentLanguage = "urn:schemas:mailheader:content-language"$$
$$cdoContentLocation = "urn:schemas:mailheader:content-location"$$
$$cdoContentTransferEncoding = "urn:schemas:mailheader:content-transfer-encoding"$$
$$cdoContentType = "urn:schemas:mailheader:content-type"$$
$$cdoControl = "urn:schemas:mailheader:control"$$
$$cdoDisposition = "urn:schemas:mailheader:disposition"$$
$$cdoDispositionNotificationTo = "urn:schemas:mailheader:disposition-notification-to"$$
$$cdoDistribution = "urn:schemas:mailheader:distribution"$$
$$cdoExpires = "urn:schemas:mailheader:expires"$$
$$cdoFollowupTo = "urn:schemas:mailheader:followup-to"$$
$$cdoInReplyTo = "urn:schemas:mailheader:in-reply-to"$$
$$cdoLines = "urn:schemas:mailheader:lines"$$
$$cdoMessageId = "urn:schemas:mailheader:message-id"$$
$$cdoMIMEVersion = "urn:schemas:mailheader:mime-version"$$
$$cdoNewsgroups = "urn:schemas:mailheader:newsgroups"$$
$$cdoOrganization = "urn:schemas:mailheader:organization"$$
$$cdoOriginalRecipient = "urn:schemas:mailheader:original-recipient"$$
$$cdoPath = "urn:schemas:mailheader:path"$$
$$cdoPostingVersion = "urn:schemas:mailheader:posting-version"$$
$$cdoReceived = "urn:schemas:mailheader:received"$$
$$cdoReferences = "urn:schemas:mailheader:references"$$
$$cdoRelayVersion = "urn:schemas:mailheader:relay-version"$$
$$cdoReturnPath = "urn:schemas:mailheader:return-path"$$
$$cdoReturnReceiptTo = "urn:schemas:mailheader:return-receipt-to"$$
$$cdoSummary = "urn:schemas:mailheader:summary"$$
$$cdoThreadIndex = "urn:schemas:mailheader:thread-index"$$
$$cdoXMailer = "urn:schemas:mailheader:x-mailer"$$
$$cdoXref = "urn:schemas:mailheader:xref"$$
$$cdoXUnsent = "urn:schemas:mailheader:x-unsent"$$
$$cdoXFidelity = "urn:schemas:mailheader:x-cdostreamhighfidelity"$$

'//   __CdoNamespace_MODULE_DEFINED__
$$cdoNSConfiguration = "http://schemas.microsoft.com/cdo/configuration/"$$
$$cdoNSContacts = "urn:schemas:contacts:"$$
$$cdoNSHTTPMail = "urn:schemas:httpmail:"$$
$$cdoNSMailHeader = "urn:schemas:mailheader:"$$
$$cdoNSNNTPEnvelope = "http://schemas.microsoft.com/cdo/nntpenvelope/"$$
$$cdoNSSMTPEnvelope = "http://schemas.microsoft.com/cdo/smtpenvelope/"$$

'//   __CdoNNTPEnvelope_MODULE_DEFINED__
$$cdoNewsgroupList = "http://schemas.microsoft.com/cdo/nntpenvelope/newsgrouplist"$$
$$cdoNNTPProcessing = "http://schemas.microsoft.com/cdo/nntpenvelope/nntpprocessing"$$

'//   __CdoOffice_MODULE_DEFINED__
$$cdoKeywords = "urn:schemas-microsoft-com:office:office#Keywords"$$

'//   __CdoSMTPEnvelope_MODULE_DEFINED__
$$cdoArrivalTime = "http://schemas.microsoft.com/cdo/smtpenvelope/arrivaltime"$$
$$cdoClientIPAddress = "http://schemas.microsoft.com/cdo/smtpenvelope/clientipaddress"$$
$$cdoMessageStatus = "http://schemas.microsoft.com/cdo/smtpenvelope/messagestatus"$$
$$cdoPickupFileName = "http://schemas.microsoft.com/cdo/smtpenvelope/pickupfilename"$$
$$cdoRecipientList = "http://schemas.microsoft.com/cdo/smtpenvelope/recipientlist"$$
$$cdoSenderEmailAddress = "http://schemas.microsoft.com/cdo/smtpenvelope/senderemailaddress"$$

'//   __CdoErrors_MODULE_DEFINED__
