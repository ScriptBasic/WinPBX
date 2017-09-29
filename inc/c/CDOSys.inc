' ########################################################################################
' Microsoft Windows
' File: CDOSys.inc
' Library name: CDO
' Version: 1.0, Locale ID = 0
' Library GUID: {CD000000-8B95-11D1-82DB-00C04FB1625D}
' Path: C:\WINDOWS\system32\cdosys.dll
' Help file: C:\WINDOWS\system32\cdosys.chm
' Contents: Microsoft CDO for Windows 2000 Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDOSYS_INC = 1

' Use %CDO_INC as constant to exclude other CDO includes such cdoex.inc
#IF NOT %DEF(%CDO_INC)
    %CDO_INC = 1

#INCLUDE ONCE "cdosysstr.inc"
#INCLUDE ONCE "cdosyserr.inc"

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "adoint.inc"

$LIBID_CDO = GUID$("{CD000000-8B95-11D1-82DB-00C04FB1625D}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {CD000002-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOConfiguration1 = "CDO.Configuration.1"
' CLSID = {CD000004-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDODropDirectory1 = "CDO.DropDirectory.1"
' CLSID = {CD000001-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOMessage1 = "CDO.Message.1"
' CLSID = {CD000011-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPEarlyConnector1 = "CDO.NNTPEarlyConnector.1"
' CLSID = {CD000010-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPFinalConnector1 = "CDO.NNTPFinalConnector.1"
' CLSID = {CD000009-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPPostConnector1 = "CDO.NNTPPostConnector.1"
' CLSID = {CD000008-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOSMTPConnector1 = "CDO.SMTPConnector.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {CD000002-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOConfiguration = "CDO.Configuration"
' CLSID = {CD000004-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDODropDirectory = "CDO.DropDirectory"
' CLSID = {CD000001-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOMessage = "CDO.Message"
' CLSID = {CD000011-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPEarlyConnector = "CDO.NNTPEarlyConnector"
' CLSID = {CD000010-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPFinalConnector = "CDO.NNTPFinalConnector"
' CLSID = {CD000009-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDONNTPPostConnector = "CDO.NNTPPostConnector"
' CLSID = {CD000008-8B95-11D1-82DB-00C04FB1625D}
$PROGID_CDOSMTPConnector = "CDO.SMTPConnector"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CDO_Configuration = GUID$("{CD000002-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_DropDirectory = GUID$("{CD000004-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Message = GUID$("{CD000001-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_NNTPEarlyConnector = GUID$("{CD000011-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_NNTPFinalConnector = GUID$("{CD000010-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_NNTPPostConnector = GUID$("{CD000009-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_SMTPConnector = GUID$("{CD000008-8B95-11D1-82DB-00C04FB1625D}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_CDO_IBodyPart = GUID$("{CD000021-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IBodyParts = GUID$("{CD000023-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IConfiguration = GUID$("{CD000022-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IDataSource = GUID$("{CD000029-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IDropDirectory = GUID$("{CD000024-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IMessage = GUID$("{CD000020-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IMessages = GUID$("{CD000025-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPEarlyScriptConnector = GUID$("{CD000034-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPFinalScriptConnector = GUID$("{CD000032-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPost = GUID$("{CD000027-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPostEarly = GUID$("{CD000033-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPostFinal = GUID$("{CD000028-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPPostScriptConnector = GUID$("{CD000031-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ISMTPOnArrival = GUID$("{CD000026-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ISMTPScriptConnector = GUID$("{CD000030-8B95-11D1-82DB-00C04FB1625D}")

' ========================================================================================
' enum CdoConfigSource
' ========================================================================================

%cdoDefaults              = -1
%cdoIIS                   = 1
%cdoOutlookExpress        = 2

' ========================================================================================
' enum CdoDSNOptions
' ========================================================================================

%cdoDSNDefault            = 0
%cdoDSNNever              = 1
%cdoDSNFailure            = 2
%cdoDSNSuccess            = 4
%cdoDSNDelay              = 8
%cdoDSNSuccessFailOrDelay = 14

' ========================================================================================
' enum CdoEventStatus
' ========================================================================================

%cdoRunNextSink           = 0
%cdoSkipRemainingSinks    = 1

' ========================================================================================
' enum CdoEventType
' ========================================================================================

%cdoSMTPOnArrival         = 1
%cdoNNTPOnPostEarly       = 2
%cdoNNTPOnPost            = 3
%cdoNNTPOnPostFinal       = 4

' ========================================================================================
' enum cdoImportanceValues
' ========================================================================================

%cdoLow                   = 0
%cdoNormal                = 1
%cdoHigh                  = 2

' ========================================================================================
' enum CdoMessageStat
' ========================================================================================

%cdoStatSuccess           = 0
%cdoStatAbortDelivery     = 2
%cdoStatBadMail           = 3

' ========================================================================================
' enum CdoMHTMLFlags
' ========================================================================================

%cdoSuppressNone          = 0
%cdoSuppressImages        = 1
%cdoSuppressBGSounds      = 2
%cdoSuppressFrames        = 4
%cdoSuppressObjects       = 8
%cdoSuppressStyleSheets   = 16
%cdoSuppressAll           = 31

' ========================================================================================
' enum CdoNNTPProcessingField
' ========================================================================================

%cdoPostMessage           = 1
%cdoProcessControl        = 2
%cdoProcessModerator      = 4

' ========================================================================================
' enum CdoPostUsing
' ========================================================================================

%cdoPostUsingPickup       = 1
%cdoPostUsingPort         = 2

' ========================================================================================
' enum CdoPriorityValues
' ========================================================================================

%cdoPriorityNonUrgent     = -1
%cdoPriorityNormal        = 0
%cdoPriorityUrgent        = 1

' ========================================================================================
' enum CdoProtocolsAuthentication
' ========================================================================================

%cdoAnonymous             = 0
%cdoBasic                 = 1
%cdoNTLM                  = 2

' ========================================================================================
' enum CdoReferenceType
' ========================================================================================

%cdoRefTypeId             = 0
%cdoRefTypeLocation       = 1

' ========================================================================================
' enum CdoSendUsing
' ========================================================================================

%cdoSendUsingPickup       = 1
%cdoSendUsingPort         = 2

' ========================================================================================
' enum cdoSensitivityValues
' ========================================================================================

%cdoSensitivityNone       = 0
%cdoPersonal              = 1
%cdoPrivate               = 2
%cdoCompanyConfidential   = 3

' ========================================================================================
' enum CdoTimeZoneId
' ========================================================================================

%cdoUTC                           = 0
%cdoGMT                           = 1
%cdoSarajevo                      = 2
%cdoParis                         = 3
%cdoBerlin                        = 4
%cdoEasternEurope                 = 5
%cdoPrague                        = 6
%cdoAthens                        = 7
%cdoBrasilia                      = 8
%cdoAtlanticCanada                = 9
%cdoEastern                       = 10
%cdoCentral                       = 11
%cdoMountain                      = 12
%cdoPacific                       = 13
%cdoAlaska                        = 14
%cdoHawaii                        = 15
%cdoMidwayIsland                  = 16
%cdoWellington                    = 17
%cdoBrisbane                      = 18
%cdoAdelaide                      = 19
%cdoTokyo                         = 20
%cdoSingapore                     = 21
%cdoBangkok                       = 22
%cdoBombay                        = 23
%cdoAbuDhabi                      = 24
%cdoTehran                        = 25
%cdoBaghdad                       = 26
%cdoIsrael                        = 27
%cdoNewfoundland                  = 28
%cdoAzores                        = 29
%cdoMidAtlantic                   = 30
%cdoMonrovia                      = 31
%cdoBuenosAires                   = 32
%cdoCaracas                       = 33
%cdoIndiana                       = 34
%cdoBogota                        = 35
%cdoSaskatchewan                  = 36
%cdoMexicoCity                    = 37
%cdoArizona                       = 38
%cdoEniwetok                      = 39
%cdoFiji                          = 40
%cdoMagadan                       = 41
%cdoHobart                        = 42
%cdoGuam                          = 43
%cdoDarwin                        = 44
%cdoBeijing                       = 45
%cdoAlmaty                        = 46
%cdoIslamabad                     = 47
%cdoKabul                         = 48
%cdoCairo                         = 49
%cdoHarare                        = 50
%cdoMoscow                        = 51
%cdoFloating                      = 52
%cdoCapeVerde                     = 53
%cdoCaucasus                      = 54
%cdoCentralAmerica                = 55
%cdoEastAfrica                    = 56
%cdoMelbourne                     = 57
%cdoEkaterinburg                  = 58
%cdoHelsinki                      = 59
%cdoGreenland                     = 60
%cdoRangoon                       = 61
%cdoNepal                         = 62
%cdoIrkutsk                       = 63
%cdoKrasnoyarsk                   = 64
%cdoSantiago                      = 65
%cdoSriLanka                      = 66
%cdoTonga                         = 67
%cdoVladivostok                   = 68
%cdoWestCentralAfrica             = 69
%cdoYakutsk                       = 70
%cdoDhaka                         = 71
%cdoSeoul                         = 72
%cdoPerth                         = 73
%cdoArab                          = 74
%cdoTaipei                        = 75
%cdoSydney2000                    = 76
%cdoChihuahua                     = 77
%cdoCanberraCommonwealthGames2006 = 78
%cdoAdelaideCommonwealthGames2006 = 79
%cdoHobartCommonwealthGames2006   = 80
%cdoTijuana	                      = 81
%cdoInvalidTimeZone               = 82
' Note: cdoInvalidTimeZone was defined as 78 in SDKs prior to Windows Server 2008 in
' cdosys.h and as 77 in cdoex.h

' ########################################################################################
' Interface name = IDataSource
' IID = {CD000029-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to extract messages from or embed messages into other CDO message body parts.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IDataSource_INTERFACE_DEFINED)
    %CDO_IDataSource_INTERFACE_DEFINED = 1

INTERFACE CDO_IDataSource $IID_CDO_IDataSource

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SourceClass <207> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *varSourceClass
   ' =====================================================================================
   PROPERTY GET Source <208> ( _                        ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **varSource
   ' =====================================================================================
   PROPERTY GET IsDirty <209> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsDirty
   ' =====================================================================================
   PROPERTY SET IsDirty <209> ( _                       ' VTable offset = 40
     BYVAL varIsDirty AS INTEGER _                      ' __in VARIANT_BOOL varIsDirty
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceURL <210> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *varSourceURL
   ' =====================================================================================
   PROPERTY GET ActiveConnection <211> ( _              ' VTable offset = 48
   ) AS ADOConnection                                   ' __retval_out _Connection **varActiveConnection
   ' =====================================================================================
   METHOD SaveToObject <251> ( _                        ' VTable offset = 52
     BYVAL Source AS IUnknown _                         ' __in IUnknown *Source
   , BYVAL InterfaceName AS WSTRING _                   ' __in BSTR InterfaceName
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenObject <252> ( _                          ' VTable offset = 56
     BYVAL Source AS IUnknown _                         ' __in IUnknown *Source
   , BYVAL InterfaceName AS WSTRING _                   ' __in BSTR InterfaceName
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveTo <253> ( _                              ' VTable offset = 60
     BYVAL SourceURL AS WSTRING _                       ' __in BSTR SourceURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <254> ( _                                ' VTable offset = 64
     BYVAL SourceURL AS WSTRING _                       ' __in BSTR SourceURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <255> ( _                                ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToContainer <256> ( _                     ' VTable offset = 72
     BYVAL ContainerURL AS WSTRING _                    ' __in BSTR ContainerURL
   , OPTIONAL BYVAL ActiveConnection AS IDispatch _     ' __opt_in IDispatch *ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IDataSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMessage
' IID = {CD000020-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage a message.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMessage_INTERFACE_DEFINED)
    %CDO_IMessage_INTERFACE_DEFINED = 1

INTERFACE CDO_IMessage $IID_CDO_IMessage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BCC <101> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pBCC
   ' =====================================================================================
   PROPERTY SET BCC <101> ( _                           ' VTable offset = 32
     BYVAL varBCC AS WSTRING _                          ' __in BSTR varBCC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CC <103> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pCC
   ' =====================================================================================
   PROPERTY SET CC <103> ( _                            ' VTable offset = 40
     BYVAL varCC AS WSTRING _                           ' __in BSTR varCC
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FollowUpTo <105> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pFollowUpTo
   ' =====================================================================================
   PROPERTY SET FollowUpTo <105> ( _                    ' VTable offset = 48
     BYVAL varFollowUpTo AS WSTRING _                   ' __in BSTR varFollowUpTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET From <106> ( _                          ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pFrom
   ' =====================================================================================
   PROPERTY SET From <106> ( _                          ' VTable offset = 56
     BYVAL varFrom AS WSTRING _                         ' __in BSTR varFrom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Keywords <107> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pKeywords
   ' =====================================================================================
   PROPERTY SET Keywords <107> ( _                      ' VTable offset = 64
     BYVAL varKeywords AS WSTRING _                     ' __in BSTR varKeywords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MimeFormatted <110> ( _                 ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pMimeFormatted
   ' =====================================================================================
   PROPERTY SET MimeFormatted <110> ( _                 ' VTable offset = 72
     BYVAL varMimeFormatted AS INTEGER _                ' __in VARIANT_BOOL varMimeFormatted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Newsgroups <111> ( _                    ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pNewsgroups
   ' =====================================================================================
   PROPERTY SET Newsgroups <111> ( _                    ' VTable offset = 80
     BYVAL varNewsgroups AS WSTRING _                   ' __in BSTR varNewsgroups
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Organization <112> ( _                  ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pOrganization
   ' =====================================================================================
   PROPERTY SET Organization <112> ( _                  ' VTable offset = 88
     BYVAL varOrganization AS WSTRING _                 ' __in BSTR varOrganization
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedTime <114> ( _                  ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *varReceivedTime
   ' =====================================================================================
   PROPERTY GET ReplyTo <115> ( _                       ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pReplyTo
   ' =====================================================================================
   PROPERTY SET ReplyTo <115> ( _                       ' VTable offset = 100
     BYVAL varReplyTo AS WSTRING _                      ' __in BSTR varReplyTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DSNOptions <116> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out CdoDSNOptions *pDSNOptions
   ' =====================================================================================
   PROPERTY SET DSNOptions <116> ( _                    ' VTable offset = 108
     BYVAL varDSNOptions AS LONG _                      ' __in CdoDSNOptions varDSNOptions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SentOn <119> ( _                        ' VTable offset = 112
   ) AS DOUBLE                                          ' __retval_out DATE *varSentOn
   ' =====================================================================================
   PROPERTY GET Subject <120> ( _                       ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pSubject
   ' =====================================================================================
   PROPERTY SET Subject <120> ( _                       ' VTable offset = 120
     BYVAL varSubject AS WSTRING _                      ' __in BSTR varSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET To <121> ( _                            ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pTo
   ' =====================================================================================
   PROPERTY SET To <121> ( _                            ' VTable offset = 128
     BYVAL varTo AS WSTRING _                           ' __in BSTR varTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextBody <123> ( _                      ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pTextBody
   ' =====================================================================================
   PROPERTY SET TextBody <123> ( _                      ' VTable offset = 136
     BYVAL varTextBody AS WSTRING _                     ' __in BSTR varTextBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HTMLBody <124> ( _                      ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pHTMLBody
   ' =====================================================================================
   PROPERTY SET HTMLBody <124> ( _                      ' VTable offset = 144
     BYVAL varHTMLBody AS WSTRING _                     ' __in BSTR varHTMLBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attachments <125> ( _                   ' VTable offset = 148
   ) AS CDO_IBodyParts                                  ' __retval_out IBodyParts **varAttachments
   ' =====================================================================================
   PROPERTY GET Sender <126> ( _                        ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *pSender
   ' =====================================================================================
   PROPERTY SET Sender <126> ( _                        ' VTable offset = 156
     BYVAL varSender AS WSTRING _                       ' __in BSTR varSender
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <127> ( _                 ' VTable offset = 160
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <127> ( _                 ' VTable offset = 164
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <127> ( _          ' VTable offset = 168
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoGenerateTextBody <128> ( _          ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pAutoGenerateTextBody
   ' =====================================================================================
   PROPERTY SET AutoGenerateTextBody <128> ( _          ' VTable offset = 176
     BYVAL varAutoGenerateTextBody AS INTEGER _         ' __in VARIANT_BOOL varAutoGenerateTextBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnvelopeFields <129> ( _                ' VTable offset = 180
   ) AS ADOFields                                       ' __retval_out Fields **varEnvelopeFields
   ' =====================================================================================
   PROPERTY GET TextBodyPart <130> ( _                  ' VTable offset = 184
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **varTextBodyPart
   ' =====================================================================================
   PROPERTY GET HTMLBodyPart <131> ( _                  ' VTable offset = 188
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **varHTMLBodyPart
   ' =====================================================================================
   PROPERTY GET BodyPart <132> ( _                      ' VTable offset = 192
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **varBodyPart
   ' =====================================================================================
   PROPERTY GET DataSource <133> ( _                    ' VTable offset = 196
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET Fields <134> ( _                        ' VTable offset = 200
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET MDNRequested <135> ( _                  ' VTable offset = 204
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pMDNRequested
   ' =====================================================================================
   PROPERTY SET MDNRequested <135> ( _                  ' VTable offset = 208
     BYVAL varMDNRequested AS INTEGER _                 ' __in VARIANT_BOOL varMDNRequested
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRelatedBodyPart <150> ( _                  ' VTable offset = 212
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Reference AS WSTRING _                       ' __in BSTR Reference
   , BYVAL ReferenceType AS LONG _                      ' __in CdoReferenceType ReferenceType
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **ppBody
   ' =====================================================================================
   METHOD AddAttachment <151> ( _                       ' VTable offset = 216
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **ppBody
   ' =====================================================================================
   METHOD CreateMHTMLBody <152> ( _                     ' VTable offset = 220
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in CdoMHTMLFlags Flags
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD Forward <153> ( _                             ' VTable offset = 224
   ) AS CDO_IMessage                                    ' __retval_out IMessage **ppMsg
   ' =====================================================================================
   METHOD Post <154> ( _                                ' VTable offset = 228
   )                                                    ' void
   ' =====================================================================================
   METHOD PostReply <155> ( _                           ' VTable offset = 232
   ) AS CDO_IMessage                                    ' __retval_out IMessage **ppMsg
   ' =====================================================================================
   METHOD Reply <156> ( _                               ' VTable offset = 236
   ) AS CDO_IMessage                                    ' __retval_out IMessage **ppMsg
   ' =====================================================================================
   METHOD ReplyAll <157> ( _                            ' VTable offset = 240
   ) AS CDO_IMessage                                    ' __retval_out IMessage **ppMsg
   ' =====================================================================================
   METHOD Send <158> ( _                                ' VTable offset = 244
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStream <159> ( _                           ' VTable offset = 248
   ) AS ADOStream                                       ' __retval_out _Stream **ppStream
   ' =====================================================================================
   METHOD GetInterface <160> ( _                        ' VTable offset = 252
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMessage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IBodyPart
' IID = {CD000021-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage a message body part.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IBodyPart_INTERFACE_DEFINED)
    %CDO_IBodyPart_INTERFACE_DEFINED = 1

INTERFACE CDO_IBodyPart $IID_CDO_IBodyPart

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BodyParts <200> ( _                     ' VTable offset = 28
   ) AS CDO_IBodyParts                                  ' __retval_out IBodyParts **varBodyParts
   ' =====================================================================================
   PROPERTY GET ContentTransferEncoding <201> ( _       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pContentTransferEncoding
   ' =====================================================================================
   PROPERTY SET ContentTransferEncoding <201> ( _       ' VTable offset = 36
     BYVAL varContentTransferEncoding AS WSTRING _      ' __in BSTR varContentTransferEncoding
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentMediaType <202> ( _              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pContentMediaType
   ' =====================================================================================
   PROPERTY SET ContentMediaType <202> ( _              ' VTable offset = 44
     BYVAL varContentMediaType AS WSTRING _             ' __in BSTR varContentMediaType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <203> ( _                        ' VTable offset = 48
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Charset <204> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pCharset
   ' =====================================================================================
   PROPERTY SET Charset <204> ( _                       ' VTable offset = 56
     BYVAL varCharset AS WSTRING _                      ' __in BSTR varCharset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileName <205> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *varFileName
   ' =====================================================================================
   PROPERTY GET DataSource <207> ( _                    ' VTable offset = 64
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET ContentClass <208> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pContentClass
   ' =====================================================================================
   PROPERTY SET ContentClass <208> ( _                  ' VTable offset = 72
     BYVAL varContentClass AS WSTRING _                 ' __in BSTR varContentClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentClassName <209> ( _              ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pContentClassName
   ' =====================================================================================
   PROPERTY SET ContentClassName <209> ( _              ' VTable offset = 80
     BYVAL varContentClassName AS WSTRING _             ' __in BSTR varContentClassName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Parent <210> ( _                        ' VTable offset = 84
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **varParent
   ' =====================================================================================
   METHOD AddBodyPart <250> ( _                         ' VTable offset = 88
     OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **ppPart
   ' =====================================================================================
   METHOD SaveToFile <251> ( _                          ' VTable offset = 92
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEncodedContentStream <252> ( _             ' VTable offset = 96
   ) AS ADOStream                                       ' __retval_out _Stream **ppStream
   ' =====================================================================================
   METHOD GetDecodedContentStream <253> ( _             ' VTable offset = 100
   ) AS ADOStream                                       ' __retval_out _Stream **ppStream
   ' =====================================================================================
   METHOD GetStream <254> ( _                           ' VTable offset = 104
   ) AS ADOStream                                       ' __retval_out _Stream **ppStream
   ' =====================================================================================
   METHOD GetFieldParameter <255> ( _                   ' VTable offset = 108
     BYVAL FieldName AS WSTRING _                       ' __in BSTR FieldName
   , BYVAL Parameter AS WSTRING _                       ' __in BSTR Parameter
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   METHOD GetInterface <160> ( _                        ' VTable offset = 112
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IBodyPart_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IConfiguration
' IID = {CD000022-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage configuration information for CDO objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IConfiguration_INTERFACE_DEFINED)
    %CDO_IConfiguration_INTERFACE_DEFINED = 1

INTERFACE CDO_IConfiguration $IID_CDO_IConfiguration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 28
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   METHOD Load <50> ( _                                 ' VTable offset = 32
     BYVAL LoadFrom AS LONG _                           ' __in CdoConfigSource LoadFrom
   , OPTIONAL BYVAL URL AS WSTRING _                    ' __opt_in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterface <160> ( _                        ' VTable offset = 36
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IConfiguration_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMessages
' IID = {CD000025-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of Message objects on the file system. Returned by IDropDirectory.GetMessages.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMessages_INTERFACE_DEFINED)
    %CDO_IMessages_INTERFACE_DEFINED = 1

INTERFACE CDO_IMessages $IID_CDO_IMessages

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS CDO_IMessage                                    ' __retval_out IMessage **ppMessage
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *varCount
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAll <3> ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET FileName <5> ( _                        ' VTable offset = 48
     BYVAL var AS VARIANT _                             ' VARIANT var
   ) AS WSTRING                                         ' __retval_out BSTR *Filename
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMessages_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDropDirectory
' IID = {CD000024-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage a collection of messages on the file system.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IDropDirectory_INTERFACE_DEFINED)
    %CDO_IDropDirectory_INTERFACE_DEFINED = 1

INTERFACE CDO_IDropDirectory $IID_CDO_IDropDirectory

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetMessages <200> ( _                         ' VTable offset = 28
     OPTIONAL BYVAL DirName AS WSTRING _                ' __opt_in BSTR DirName
   ) AS CDO_IMessages                                   ' __retval_out IMessages **Msgs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IDropDirectory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IBodyParts
' IID = {CD000023-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of BodyPart objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IBodyParts_INTERFACE_DEFINED)
    %CDO_IBodyParts_INTERFACE_DEFINED = 1

INTERFACE CDO_IBodyParts $IID_CDO_IBodyParts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *varCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **ppBody
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 40
     BYVAL varBP AS VARIANT _                           ' __in VARIANT varBP
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAll <3> ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <4> ( _                                   ' VTable offset = 48
     OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **ppPart
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IBodyParts_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISMTPScriptConnector
' IID = {CD000030-8B95-11D1-82DB-00C04FB1625D}
' ISMTPScriptConnector interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_ISMTPScriptConnector_INTERFACE_DEFINED)
    %CDO_ISMTPScriptConnector_INTERFACE_DEFINED = 1

INTERFACE CDO_ISMTPScriptConnector $IID_CDO_ISMTPScriptConnector

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __CDO_ISMTPScriptConnector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPEarlyScriptConnector
' IID = {CD000034-8B95-11D1-82DB-00C04FB1625D}
' INNTPFinalScriptConnector interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPEarlyScriptConnector_INTERFACE_DEFINED)
    %CDO_INNTPEarlyScriptConnector_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPEarlyScriptConnector $IID_CDO_INNTPEarlyScriptConnector

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __CDO_INNTPEarlyScriptConnector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPPostScriptConnector
' IID = {CD000031-8B95-11D1-82DB-00C04FB1625D}
' INNTPPostScriptConnector interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPPostScriptConnector_INTERFACE_DEFINED)
    %CDO_INNTPPostScriptConnector_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPPostScriptConnector $IID_CDO_INNTPPostScriptConnector

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __CDO_INNTPPostScriptConnector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPFinalScriptConnector
' IID = {CD000032-8B95-11D1-82DB-00C04FB1625D}
' INNTPFinalScriptConnector interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPFinalScriptConnector_INTERFACE_DEFINED)
    %CDO_INNTPFinalScriptConnector_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPFinalScriptConnector $IID_CDO_INNTPFinalScriptConnector

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __CDO_INNTPFinalScriptConnector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISMTPOnArrival
' IID = {CD000026-8B95-11D1-82DB-00C04FB1625D}
' Implement when creating SMTP OnArrival event sinks.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_ISMTPOnArrival_INTERFACE_DEFINED)
    %CDO_ISMTPOnArrival_INTERFACE_DEFINED = 1

INTERFACE CDO_ISMTPOnArrival $IID_CDO_ISMTPOnArrival

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnArrival <256> ( _                           ' VTable offset = 28
     BYVAL Msg AS CDO_IMessage _                        ' __in IMessage *Msg
   , BYREF EventStatus AS LONG _                        ' __in_out CdoEventStatus *EventStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_ISMTPOnArrival_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPOnPostEarly
' IID = {CD000033-8B95-11D1-82DB-00C04FB1625D}
' Implement when creating NNTP OnPostEarly event sinks.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPOnPostEarly_INTERFACE_DEFINED)
    %CDO_INNTPOnPostEarly_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPOnPostEarly $IID_CDO_INNTPOnPostEarly

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnPostEarly <256> ( _                         ' VTable offset = 28
     BYVAL Msg AS IDispatch _                           ' __in IMessage *Msg
   , BYREF EventStatus AS LONG _                        ' __in_out CdoEventStatus *EventStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_INNTPOnPostEarly_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPOnPost
' IID = {CD000027-8B95-11D1-82DB-00C04FB1625D}
' Implement when creating NNTP OnPost event sinks.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPOnPost_INTERFACE_DEFINED)
    %CDO_INNTPOnPost_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPOnPost $IID_CDO_INNTPOnPost

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnPost <256> ( _                              ' VTable offset = 28
     BYVAL Msg AS CDO_IMessage _                        ' __in IMessage *Msg
   , BYREF EventStatus AS LONG _                        ' __in_out CdoEventStatus *EventStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_INNTPOnPost_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INNTPOnPostFinal
' IID = {CD000028-8B95-11D1-82DB-00C04FB1625D}
' Implement when creating NNTP OnPostFinal event sinks.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_INNTPOnPostFinal_INTERFACE_DEFINED)
    %CDO_INNTPOnPostFinal_INTERFACE_DEFINED = 1

INTERFACE CDO_INNTPOnPostFinal $IID_CDO_INNTPOnPostFinal

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnPostFinal <256> ( _                         ' VTable offset = 28
     BYVAL Msg AS CDO_IMessage _                        ' __in IMessage *Msg
   , BYREF EventStatus AS LONG _                        ' __in_out CdoEventStatus *EventStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_INNTPOnPostFinal_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IProxyObject
' IID = {CD000083-8B95-11D1-82DB-00C04FB1625D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%CDO_IProxyObject_INTERFACE_DEFINED)
    %CDO_IProxyObject_INTERFACE_DEFINED = 1

$IID_CDO_IProxyObject = GUID$("{CD000083-8B95-11D1-82DB-00C04FB1625D}")

INTERFACE CDO_IProxyObject $IID_CDO_IProxyObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Object ( _                                ' VTable offset = 12
     BYREF ppParent AS IUnknown _                       ' __out IUnknown **ppParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IProxyObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetInterface
' IID = {CD0FF000-8B95-11D1-82DB-00C04FB1625D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%CDO_IGetInterface_INTERFACE_DEFINED)
    %CDO_IGetInterface_INTERFACE_DEFINED = 1

$IID_CDO_IGetInterface = GUID$("{CD0FF000-8B95-11D1-82DB-00C04FB1625D}")

INTERFACE CDO_IGetInterface $IID_CDO_IGetInterface

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 12
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD GetInterfaceInner ( _                         ' VTable offset = 16
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IGetInterface_INTERFACE_DEFINED__ */

#IF NOT %DEF(%CdoErrors_MODULE_DEFINED)
    %CdoErrors_MODULE_DEFINED = 1

%CDO_E_UNCAUGHT_EXCEPTION                               = &H80040201&   ' -2147220991
%CDO_E_NOT_OPENED                                       = &H80040202&   ' -2147220990
%CDO_E_UNSUPPORTED_DATASOURCE                           = &H80040203&   ' -2147220989
%CDO_E_INVALID_PROPERTYNAME                             = &H80040204&   ' -2147220988
%CDO_E_PROP_UNSUPPORTED                                 = &H80040205&   ' -2147220987
%CDO_E_INACTIVE                                         = &H80040206&   ' -2147220986
%CDO_E_NO_SUPPORT_FOR_OBJECTS                           = &H80040207&   ' -2147220985
%CDO_E_NOT_AVAILABLE                                    = &H80040208&   ' -2147220984
%CDO_E_NO_DEFAULT_DROP_DIR                              = &H80040209&   ' -2147220983
%CDO_E_SMTP_SERVER_REQUIRED                             = &H8004020A&   ' -2147220982
%CDO_E_NNTP_SERVER_REQUIRED                             = &H8004020B&   ' -2147220981
%CDO_E_RECIPIENT_MISSING                                = &H8004020C&   ' -2147220980
%CDO_E_FROM_MISSING                                     = &H8004020D&   ' -2147220979
%CDO_E_SENDER_REJECTED                                  = &H8004020E&   ' -2147220978
%CDO_E_RECIPIENTS_REJECTED                              = &H8004020F&   ' -2147220977
%CDO_E_NNTP_POST_FAILED                                 = &H80040210&   ' -2147220976
%CDO_E_SMTP_SEND_FAILED                                 = &H80040211&   ' -2147220975
%CDO_E_CONNECTION_DROPPED                               = &H80040212&   ' -2147220974
%CDO_E_FAILED_TO_CONNECT                                = &H80040213&   ' -2147220973
%CDO_E_INVALID_POST                                     = &H80040214&   ' -2147220972
%CDO_E_AUTHENTICATION_FAILURE                           = &H80040215&   ' -2147220971
%CDO_E_INVALID_CONTENT_TYPE                             = &H80040216&   ' -2147220970
%CDO_E_LOGON_FAILURE                                    = &H80040217&   ' -2147220969
%CDO_E_HTTP_NOT_FOUND                                   = &H80040218&   ' -2147220968
%CDO_E_HTTP_FORBIDDEN                                   = &H80040219&   ' -2147220967
%CDO_E_HTTP_FAILED                                      = &H8004021A&   ' -2147220966
%CDO_E_MULTIPART_NO_DATA                                = &H8004021B&   ' -2147220965
%CDO_E_INVALID_ENCODING_FOR_MULTIPART                   = &H8004021C&   ' -2147220964
%CDO_E_UNSAFE_OPERATION                                 = &H8004021D&   ' -2147220963
%CDO_E_PROP_NOT_FOUND                                   = &H8004021E&   ' -2147220962
%CDO_E_INVALID_SEND_OPTION                              = &H80040220&   ' -2147220960
%CDO_E_INVALID_POST_OPTION                              = &H80040221&   ' -2147220959
%CDO_E_NO_PICKUP_DIR                                    = &H80040222&   ' -2147220958
%CDO_E_NOT_ALL_DELETED                                  = &H80040223&   ' -2147220957
%CDO_E_NO_METHOD                                        = &H80040224&   ' -2147220956
%CDO_E_PROP_READONLY                                    = &H80040227&   ' -2147220953
%CDO_E_PROP_CANNOT_DELETE                               = &H80040228&   ' -2147220952
%CDO_E_BAD_DATA                                         = &H80040229&   ' -2147220951
%CDO_E_PROP_NONHEADER                                   = &H8004022A&   ' -2147220950
%CDO_E_INVALID_CHARSET                                  = &H8004022B&   ' -2147220949
%CDO_E_ADOSTREAM_NOT_BOUND                              = &H8004022C&   ' -2147220948
%CDO_E_CONTENTPROPXML_NOT_FOUND                         = &H8004022D&   ' -2147220947
%CDO_E_CONTENTPROPXML_WRONG_CHARSET                     = &H8004022E&   ' -2147220946
%CDO_E_CONTENTPROPXML_PARSE_FAILED                      = &H8004022F&   ' -2147220945
%CDO_E_CONTENTPROPXML_CONVERT_FAILED                    = &H80040230&   ' -2147220944
%CDO_E_NO_DIRECTORIES_SPECIFIED                         = &H80040231&   ' -2147220943
%CDO_E_DIRECTORIES_UNREACHABLE                          = &H80040232&   ' -2147220942
%CDO_E_BAD_SENDER                                       = &H80040233&   ' -2147220941
%CDO_E_SELF_BINDING                                     = &H80040234&   ' -2147220940
%CDO_E_BAD_ATTENDEE_DATA                                = &H80040235&   ' -2147220939
%CDO_E_ARGUMENT1                                        = &H80044000&   ' -2147205120
%CDO_E_ARGUMENT2                                        = &H80044001&   ' -2147205119
%CDO_E_ARGUMENT3                                        = &H80044002&   ' -2147205118
%CDO_E_ARGUMENT4                                        = &H80044003&   ' -2147205117
%CDO_E_ARGUMENT5                                        = &H80044004&   ' -2147205116
%CDO_E_NOT_FOUND                                        = &H800CCE05&   ' -2146644475
%CDO_E_INVALID_ENCODING_TYPE                            = &H800CCE1D&   ' -2146644451

#ENDIF   ' /* __CdoErrors_MODULE_DEFINED__ */

#ENDIF   ' #IF NOT %DEF(%CDO_INC)
