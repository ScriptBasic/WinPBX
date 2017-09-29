' ########################################################################################
' Microsoft Windows
' File: cdoex.inc
' Library name: CDO
' Version: 1.0
' Library GUID: {CD000000-8B95-11D1-82DB-00C04FB1625D}
' Help file: cdo.chm
' Contents: Microsoft CDO For Exchange 2000 Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CDOEX_INC = 1

' Use %CDO_INC as constant to exclude other CDO includes such cdosys.inc
#IF NOT %DEF(%CDO_INC)
    %CDO_INC = 1

#INCLUDE ONCE "cdoexstr.inc"

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

$CLSID_CDO_Addressee = GUID$("{CD000110-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Appointment = GUID$("{CD000100-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Attendee = GUID$("{CD00010D-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_CalendarMessage = GUID$("{CD000102-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Folder = GUID$("{CD00010E-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Item = GUID$("{CD000112-8B95-11D1-82DB-00C04FB1625D}")
$CLSID_CDO_Person = GUID$("{CD000107-8B95-11D1-82DB-00C04FB1625D}")
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

$IID_CDO_IAddressee = GUID$("{CD000139-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IAddressees = GUID$("{CD000142-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IAppointment = GUID$("{CD000120-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IAttendee = GUID$("{CD000135-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IAttendees = GUID$("{CD000136-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IBodyPart = GUID$("{CD000021-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IBodyParts = GUID$("{CD000023-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ICalendarMessage = GUID$("{CD000122-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ICalendarPart = GUID$("{CD000133-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ICalendarParts = GUID$("{CD000130-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IConfiguration = GUID$("{CD000022-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IDataSource = GUID$("{CD000029-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IDropDirectory = GUID$("{CD000024-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IException = GUID$("{CD000124-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IExceptions = GUID$("{CD00012D-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IFolder = GUID$("{CD000132-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IIntegers = GUID$("{CD00012E-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IItem = GUID$("{CD000126-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IMailbox = GUID$("{CD000125-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IMessage = GUID$("{CD000020-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IMessages = GUID$("{CD000025-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPEarlyScriptConnector = GUID$("{CD000034-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPFinalScriptConnector = GUID$("{CD000032-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPost = GUID$("{CD000027-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPostEarly = GUID$("{CD000033-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPOnPostFinal = GUID$("{CD000028-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_INNTPPostScriptConnector = GUID$("{CD000031-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IPerson = GUID$("{CD000127-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IRecurrencePattern = GUID$("{CD000123-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IRecurrencePatterns = GUID$("{CD00012C-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ISMTPOnArrival = GUID$("{CD000026-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_ISMTPScriptConnector = GUID$("{CD000030-8B95-11D1-82DB-00C04FB1625D}")
$IID_CDO_IVariants = GUID$("{CD00012F-8B95-11D1-82DB-00C04FB1625D}")

' ========================================================================================
' CdoAttendeeRoleValues enum
' ========================================================================================

%cdoRequiredParticipant = 0
%cdoOptionalParticipant = 1
%cdoNonParticipant      = 2
%cdoChair               = 3

' ========================================================================================
' CdoAttendeeStatusValues enum
' ========================================================================================

%cdoAccepted                = 0
%cdoDeclined                = 1
%cdoAttendeeStatusTentative = 2
%cdoNeedsAction             = 3
%cdoDelegated               = 4
%cdoCompleted               = 5
%cdoInProgress              = 6

' ========================================================================================
' CdoComponentType enum
' ========================================================================================

%cdoComponentTypeUnknown     = 0
%cdoComponentTypeAppointment = 1

' ========================================================================================
' CdoConfigSource enum
' ========================================================================================

%cdoDefaults       = -1
%cdoIIS            = 1
%cdoOutlookExpress = 2
%cdoDirectory      = 3

' ========================================================================================
' CdoDayOfWeek enum
' ========================================================================================

%cdoSunday    = 0
%cdoMonday    = 1
%cdoTuesday   = 2
%cdoWednesday = 3
%cdoThursday  = 4
%cdoFriday    = 5
%cdoSaturday  = 6

' ========================================================================================
' CdoDSNOptions enum
' ========================================================================================

%cdoDSNDefault            = 0
%cdoDSNNever              = 1
%cdoDSNFailure            = 2
%cdoDSNSuccess            = 4
%cdoDSNDelay              = 8
%cdoDSNSuccessFailOrDelay = 14

' ========================================================================================
' CdoEventStatus enum
' ========================================================================================

%cdoRunNextSink        = 0
%cdoSkipRemainingSinks = 1

' ========================================================================================
' CdoEventType enum
' ========================================================================================

%cdoSMTPOnArrival   = 1
%cdoNNTPOnPostEarly = 2
%cdoNNTPOnPost      = 3
%cdoNNTPOnPostFinal = 4

' ========================================================================================
' CdoFileAsMappingId enum
' ========================================================================================

%cdoMapToNone         = 0
%cdoMapToLastFirst    = 1
%cdoMapToFirstLast    = 2
%cdoMapToOrg          = 3
%cdoMapToLastFirstOrg = 4
%cdoMapToOrgLastFirst = 5

' ========================================================================================
' CdoFrequency enum
' ========================================================================================

%cdoSecondly = 1
%cdoMinutely = 2
%cdoHourly   = 3
%cdoDaily    = 4
%cdoWeekly   = 5
%cdoMonthly  = 6
%cdoYearly   = 7

' ========================================================================================
' CdoGenderValues enum
' ========================================================================================

%cdoGenderUnspecified = 0
%cdoFemale            = 1
%cdoMale              = 2

' ========================================================================================
' cdoImportanceValues enum
' ========================================================================================

%cdoLow    = 0
%cdoNormal = 1
%cdoHigh   = 2

' ========================================================================================
' CdoInstanceTypes enum
' ========================================================================================

%cdoSingle    = 0
%cdoMaster    = 1
%cdoInstance  = 2
%cdoException = 3

' ========================================================================================
' CdoMailingAddressIdValues enum
' ========================================================================================

%cdoNoAddress       = 0
%cdoHomeAddress     = 1
%cdoBusinessAddress = 2
%cdoOtherAddress    = 3

' ========================================================================================
' CdoMHTMLFlags enum
' ========================================================================================

%cdoSuppressNone        = 0
%cdoSuppressImages      = 1
%cdoSuppressBGSounds    = 2
%cdoSuppressFrames      = 4
%cdoSuppressObjects     = 8
%cdoSuppressStyleSheets = 16
%cdoSuppressAll         = 31

' ========================================================================================
' CdoNNTPProcessingField enum
' ========================================================================================

%cdoPostMessage      = 1
%cdoProcessControl   = 2
%cdoProcessModerator = 4

' ========================================================================================
' CdoPatternEndType enum
' ========================================================================================

%cdoNoEndDate      = 0
%cdoEndByInstances = 1
%cdoEndByDate      = 2

' ========================================================================================
' CdoPostUsing enum
' ========================================================================================

%cdoPostUsingPickup   = 1
%cdoPostUsingPort     = 2
%cdoPostUsingExchange = 3

' ========================================================================================
' cdoPriorityValues enum
' ========================================================================================

%cdoPriorityNonUrgent = -1
%cdoPriorityNormal    = 0
%cdoPriorityUrgent    = 1

' ========================================================================================
' CdoProtocolsAuthentication enum
' ========================================================================================

%cdoAnonymous = 0
%cdoBasic     = 1
%cdoNTLM      = 2

' ========================================================================================
' CdoReferenceType enum
' ========================================================================================

%cdoRefTypeId       = 0
%cdoRefTypeLocation = 1

' ========================================================================================
' CdoResolvedStatus enum
' ========================================================================================

%cdoUnresolved = 0
%cdoResolved   = 1
%cdoAmbiguous  = 2

' ========================================================================================
' CdoSendUsing enum
' ========================================================================================

%cdoSendUsingPickup   = 1
%cdoSendUsingPort     = 2
%cdoSendUsingExchange = 3

' ========================================================================================
' cdoSensitivityValues enum
' ========================================================================================

%cdoSensitivityNone     = 0
%cdoPersonal            = 1
%cdoPrivate             = 2
%cdoCompanyConfidential = 3

' ========================================================================================
' CdoTimeZoneId enum
' ========================================================================================

%cdoUTC               = 0
%cdoGMT               = 1
%cdoSarajevo          = 2
%cdoParis             = 3
%cdoBerlin            = 4
%cdoEasternEurope     = 5
%cdoPrague            = 6
%cdoAthens            = 7
%cdoBrasilia          = 8
%cdoAtlanticCanada    = 9
%cdoEastern           = 10
%cdoCentral           = 11
%cdoMountain          = 12
%cdoPacific           = 13
%cdoAlaska            = 14
%cdoHawaii            = 15
%cdoMidwayIsland      = 16
%cdoWellington        = 17
%cdoBrisbane          = 18
%cdoAdelaide          = 19
%cdoTokyo             = 20
%cdoSingapore         = 21
%cdoBangkok           = 22
%cdoBombay            = 23
%cdoAbuDhabi          = 24
%cdoTehran            = 25
%cdoBaghdad           = 26
%cdoIsrael            = 27
%cdoNewfoundland      = 28
%cdoAzores            = 29
%cdoMidAtlantic       = 30
%cdoMonrovia          = 31
%cdoBuenosAires       = 32
%cdoCaracas           = 33
%cdoIndiana           = 34
%cdoBogota            = 35
%cdoSaskatchewan      = 36
%cdoMexicoCity        = 37
%cdoArizona           = 38
%cdoEniwetok          = 39
%cdoFiji              = 40
%cdoMagadan           = 41
%cdoHobart            = 42
%cdoGuam              = 43
%cdoDarwin            = 44
%cdoBeijing           = 45
%cdoAlmaty            = 46
%cdoIslamabad         = 47
%cdoKabul             = 48
%cdoCairo             = 49
%cdoHarare            = 50
%cdoMoscow            = 51
%cdoFloating          = 52
%cdoCapeVerde         = 53
%cdoCaucasus          = 54
%cdoCentralAmerica    = 55
%cdoEastAfrica        = 56
%cdoMelbourne         = 57
%cdoEkaterinburg      = 58
%cdoHelsinki          = 59
%cdoGreenland         = 60
%cdoRangoon           = 61
%cdoNepal             = 62
%cdoIrkutsk           = 63
%cdoKrasnoyarsk       = 64
%cdoSantiago          = 65
%cdoSriLanka          = 66
%cdoTonga             = 67
%cdoVladivostok       = 68
%cdoWestCentralAfrica = 69
%cdoYakutsk           = 70
%cdoDhaka             = 71
%cdoSeoul             = 72
%cdoPerth             = 73
%cdoArab              = 74
%cdoTaipei            = 75
%cdoSydney2000        = 76
%cdoInvalidTimeZone   = 77
' Note: cdoInvalidTimeZone is defined as 82 in the Windows Server 2008 SDK version of cdosys.h

' ========================================================================================
' cdoURLSourceValues enum
' ========================================================================================

%cdoExchangeServerURL = 0
%cdoClientStoreURL    = 1

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
     BYVAL Msg AS CDO_IMessage _                        ' __in IMessage *Msg
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
' Interface name = IItem
' IID = {CD000126-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage an item.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IItem_INTERFACE_DEFINED)
    %CDO_IItem_INTERFACE_DEFINED = 1

INTERFACE CDO_IItem $IID_CDO_IItem

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetInterface <1> ( _                          ' VTable offset = 28
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD GetStream <2> ( _                             ' VTable offset = 32
   ) AS ADOStream                                       ' __retval_out _Stream **ppStream
   ' =====================================================================================
   PROPERTY GET ChildCount <3> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *varChildCount
   ' =====================================================================================
   PROPERTY GET Configuration <4> ( _                   ' VTable offset = 40
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <4> ( _                   ' VTable offset = 44
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <4> ( _            ' VTable offset = 48
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentClass <5> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pContentClass
   ' =====================================================================================
   PROPERTY SET ContentClass <5> ( _                    ' VTable offset = 56
     BYVAL varContentClass AS WSTRING _                 ' __in BSTR varContentClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreationDate <6> ( _                    ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE *varCreationDate
   ' =====================================================================================
   PROPERTY GET DataSource <7> ( _                      ' VTable offset = 64
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET DisplayName <8> ( _                     ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *varDisplayName
   ' =====================================================================================
   PROPERTY GET Fields <9> ( _                          ' VTable offset = 72
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET IsCollection <10> ( _                   ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *varIsCollection
   ' =====================================================================================
   PROPERTY GET IsHidden <11> ( _                       ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsHidden
   ' =====================================================================================
   PROPERTY SET IsHidden <11> ( _                       ' VTable offset = 84
     BYVAL varIsHidden AS INTEGER _                     ' __in VARIANT_BOOL varIsHidden
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsStructuredDocument <12> ( _           ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *varIsStructuredDocument
   ' =====================================================================================
   PROPERTY GET LastModified <13> ( _                   ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *varLastModified
   ' =====================================================================================
   PROPERTY GET ObjectCount <14> ( _                    ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *varObjectCount
   ' =====================================================================================
   PROPERTY GET ParentURL <15> ( _                      ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *varParentURL
   ' =====================================================================================
   PROPERTY GET VisibleCount <16> ( _                   ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *varVisibleCount
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IItem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAppointment
' IID = {CD000120-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage information about appointments.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IAppointment_INTERFACE_DEFINED)
    %CDO_IAppointment_INTERFACE_DEFINED = 1

INTERFACE CDO_IAppointment $IID_CDO_IAppointment

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Attachments <2> ( _                     ' VTable offset = 28
   ) AS CDO_IBodyParts                                  ' __retval_out IBodyParts **varAttachments
   ' =====================================================================================
   PROPERTY GET Attendees <3> ( _                       ' VTable offset = 32
   ) AS CDO_IAttendees                                  ' __retval_out IAttendees **varAttendees
   ' =====================================================================================
   PROPERTY GET BusyStatus <5> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pBusyStatus
   ' =====================================================================================
   PROPERTY SET BusyStatus <5> ( _                      ' VTable offset = 40
     BYVAL varBusyStatus AS WSTRING _                   ' __in BSTR varBusyStatus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Keywords <6> ( _                        ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pKeywords
   ' =====================================================================================
   PROPERTY SET Keywords <6> ( _                        ' VTable offset = 48
     BYVAL varKeywords AS VARIANT _                     ' __in VARIANT varKeywords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <8> ( _                   ' VTable offset = 52
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <8> ( _                   ' VTable offset = 56
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <8> ( _            ' VTable offset = 60
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Contact <9> ( _                         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pContact
   ' =====================================================================================
   PROPERTY SET Contact <9> ( _                         ' VTable offset = 68
     BYVAL varContact AS WSTRING _                      ' __in BSTR varContact
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContactURL <10> ( _                     ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pContactURL
   ' =====================================================================================
   PROPERTY SET ContactURL <10> ( _                     ' VTable offset = 76
     BYVAL varContactURL AS WSTRING _                   ' __in BSTR varContactURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <15> ( _                     ' VTable offset = 80
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET EndTime <18> ( _                        ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pEndTime
   ' =====================================================================================
   PROPERTY SET EndTime <18> ( _                        ' VTable offset = 88
     BYVAL varEndTime AS DOUBLE _                       ' __in DATE varEndTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Exceptions <19> ( _                     ' VTable offset = 92
   ) AS CDO_IExceptions                                 ' __retval_out IExceptions **varExceptions
   ' =====================================================================================
   PROPERTY GET Duration <21> ( _                       ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *pDuration
   ' =====================================================================================
   PROPERTY SET Duration <21> ( _                       ' VTable offset = 100
     BYVAL varDuration AS LONG _                        ' __in long varDuration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <22> ( _                         ' VTable offset = 104
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Location <27> ( _                       ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pLocation
   ' =====================================================================================
   PROPERTY SET Location <27> ( _                       ' VTable offset = 112
     BYVAL varLocation AS WSTRING _                     ' __in BSTR varLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationURL <28> ( _                    ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pLocationURL
   ' =====================================================================================
   PROPERTY SET LocationURL <28> ( _                    ' VTable offset = 120
     BYVAL varLocationURL AS WSTRING _                  ' __in BSTR varLocationURL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <34> ( _                       ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *pPriority
   ' =====================================================================================
   PROPERTY SET Priority <34> ( _                       ' VTable offset = 128
     BYVAL varPriority AS LONG _                        ' __in long varPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplyTime <38> ( _                      ' VTable offset = 132
   ) AS DOUBLE                                          ' __retval_out DATE *varReplyTime
   ' =====================================================================================
   PROPERTY GET Resources <39> ( _                      ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *pResourcesVT_BSTR
   ' =====================================================================================
   PROPERTY SET Resources <39> ( _                      ' VTable offset = 140
     BYVAL varResources AS WSTRING _                    ' __in BSTR varResources
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseRequested <40> ( _              ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pResponseRequested
   ' =====================================================================================
   PROPERTY SET ResponseRequested <40> ( _              ' VTable offset = 148
     BYVAL varResponseRequested AS INTEGER _            ' __in VARIANT_BOOL varResponseRequested
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecurrencePatterns <41> ( _             ' VTable offset = 152
   ) AS CDO_IRecurrencePatterns                         ' __retval_out IRecurrencePatterns **varRecurrencePatterns
   ' =====================================================================================
   PROPERTY GET Sensitivity <42> ( _                    ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long *pSensitivity
   ' =====================================================================================
   PROPERTY SET Sensitivity <42> ( _                    ' VTable offset = 160
     BYVAL varSensitivity AS LONG _                     ' __in long varSensitivity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <44> ( _                      ' VTable offset = 164
   ) AS DOUBLE                                          ' __retval_out DATE *pStartTime
   ' =====================================================================================
   PROPERTY SET StartTime <44> ( _                      ' VTable offset = 168
     BYVAL varStartTime AS DOUBLE _                     ' __in DATE varStartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MeetingStatus <45> ( _                  ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *pMeetingStatus
   ' =====================================================================================
   PROPERTY SET MeetingStatus <45> ( _                  ' VTable offset = 176
     BYVAL varMeetingStatus AS WSTRING _                ' __in BSTR varMeetingStatus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Subject <46> ( _                        ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pSubject
   ' =====================================================================================
   PROPERTY SET Subject <46> ( _                        ' VTable offset = 184
     BYVAL varSubject AS WSTRING _                      ' __in BSTR varSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transparent <48> ( _                    ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *pTransparent
   ' =====================================================================================
   PROPERTY SET Transparent <48> ( _                    ' VTable offset = 192
     BYVAL varTransparent AS WSTRING _                  ' __in BSTR varTransparent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BodyPart <52> ( _                       ' VTable offset = 196
   ) AS CDO_IBodyPart                                   ' __retval_out IBodyPart **varBodyPart
   ' =====================================================================================
   PROPERTY GET GEOLatitude <54> ( _                    ' VTable offset = 200
   ) AS DOUBLE                                          ' __retval_out double *pGEOLatitude
   ' =====================================================================================
   PROPERTY SET GEOLatitude <54> ( _                    ' VTable offset = 204
     BYVAL varGEOLatitude AS DOUBLE _                   ' __in double varGEOLatitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GEOLongitude <55> ( _                   ' VTable offset = 208
   ) AS DOUBLE                                          ' __retval_out double *pGEOLongitude
   ' =====================================================================================
   PROPERTY SET GEOLongitude <55> ( _                   ' VTable offset = 212
     BYVAL varGEOLongitude AS DOUBLE _                  ' __in double varGEOLongitude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllDayEvent <56> ( _                    ' VTable offset = 216
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pAllDayEvent
   ' =====================================================================================
   PROPERTY SET AllDayEvent <56> ( _                    ' VTable offset = 220
     BYVAL varAllDayEvent AS INTEGER _                  ' __in VARIANT_BOOL varAllDayEvent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextBody <61> ( _                       ' VTable offset = 224
   ) AS WSTRING                                         ' __retval_out BSTR *pTextBody
   ' =====================================================================================
   PROPERTY SET TextBody <61> ( _                       ' VTable offset = 228
     BYVAL varTextBody AS WSTRING _                     ' __in BSTR varTextBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseText <62> ( _                   ' VTable offset = 232
   ) AS WSTRING                                         ' __retval_out BSTR *pResponseText
   ' =====================================================================================
   PROPERTY SET ResponseText <62> ( _                   ' VTable offset = 236
     BYVAL varResponseText AS WSTRING _                 ' __in BSTR varResponseText
   )                                                    ' void
   ' =====================================================================================
   METHOD Accept <201> ( _                              ' VTable offset = 240
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Response
   ' =====================================================================================
   METHOD AcceptTentative <202> ( _                     ' VTable offset = 244
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Response
   ' =====================================================================================
   METHOD Cancel <203> ( _                              ' VTable offset = 248
     OPTIONAL BYVAL EmailList AS WSTRING _              ' __opt_in BSTR EmailList
   , OPTIONAL BYVAL CleanupCalendar AS INTEGER _        ' __opt_in VARIANT_BOOL CleanupCalendar
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Request
   ' =====================================================================================
   METHOD CreateRequest <205> ( _                       ' VTable offset = 252
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Request
   ' =====================================================================================
   METHOD Decline <206> ( _                             ' VTable offset = 256
     OPTIONAL BYVAL CleanupCalendar AS INTEGER _        ' __opt_in VARIANT_BOOL CleanupCalendar
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Response
   ' =====================================================================================
   METHOD Invite <211> ( _                              ' VTable offset = 260
     BYVAL EmailList AS WSTRING _                       ' __in BSTR EmailList
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Request
   ' =====================================================================================
   METHOD Publish <212> ( _                             ' VTable offset = 264
   ) AS CDO_ICalendarMessage                            ' __retval_out ICalendarMessage **Request
   ' =====================================================================================
   METHOD GetFirstInstance <217> ( _                    ' VTable offset = 268
     BYVAL MinDate AS DOUBLE _                          ' __in DATE MinDate
   , BYVAL MaxDate AS DOUBLE _                          ' __in DATE MaxDate
   ) AS CDO_IAppointment                                ' __retval_out IAppointment **Appointment
   ' =====================================================================================
   METHOD GetNextInstance <218> ( _                     ' VTable offset = 272
   ) AS CDO_IAppointment                                ' __retval_out IAppointment **Appointment
   ' =====================================================================================
   METHOD GetInterface <219> ( _                        ' VTable offset = 276
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD GetRecurringMaster <220> ( _                  ' VTable offset = 280
     OPTIONAL BYVAL CalendarLocation AS WSTRING _       ' __opt_in BSTR CalendarLocation
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS CDO_IAppointment                                ' __retval_out IAppointment **Appointment
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IAppointment_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICalendarMessage
' IID = {CD000122-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to create and process meeting requests.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_ICalendarMessage_INTERFACE_DEFINED)
    %CDO_ICalendarMessage_INTERFACE_DEFINED = 1


INTERFACE CDO_ICalendarMessage $IID_CDO_ICalendarMessage

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetInterface <2> ( _                          ' VTable offset = 28
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   PROPERTY GET CalendarParts <3> ( _                   ' VTable offset = 32
   ) AS CDO_ICalendarParts                              ' __retval_out ICalendarParts **varCalendarParts
   ' =====================================================================================
   PROPERTY GET Message <5> ( _                         ' VTable offset = 36
   ) AS CDO_IMessage                                    ' __retval_out IMessage **varMessage
   ' =====================================================================================
   PROPERTY GET DataSource <6> ( _                      ' VTable offset = 40
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 44
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 48
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <7> ( _            ' VTable offset = 52
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_ICalendarMessage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IIntegers
' IID = {CD00012E-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of integers. Used in recurrence patterns.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IIntegers_INTERFACE_DEFINED)
    %CDO_IIntegers_INTERFACE_DEFINED = 1

INTERFACE CDO_IIntegers $IID_CDO_IIntegers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS LONG                                            ' __retval_out long *Value
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYREF Value AS LONG _                              ' __in long *Value
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL NewValue AS LONG _                           ' __in long NewValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IIntegers_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVariants
' IID = {CD00012F-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of Variants. Used in recurrence patterns.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IVariants_INTERFACE_DEFINED)
    %CDO_IVariants_INTERFACE_DEFINED = 1

INTERFACE CDO_IVariants $IID_CDO_IVariants

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYREF Value AS VARIANT _                           ' __in VARIANT *Value
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL NewValue AS VARIANT _                        ' __in VARIANT NewValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IVariants_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRecurrencePattern
' IID = {CD000123-8B95-11D1-82DB-00C04FB1625D}
' Provides scheduling properties for specifying recurrence pattern rules.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IRecurrencePattern_INTERFACE_DEFINED)
    %CDO_IRecurrencePattern_INTERFACE_DEFINED = 1

INTERFACE CDO_IRecurrencePattern $IID_CDO_IRecurrencePattern

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Interval <1> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pInterval
   ' =====================================================================================
   PROPERTY SET Interval <1> ( _                        ' VTable offset = 32
     BYVAL varInterval AS LONG _                        ' __in long varInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Instances <2> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pInstances
   ' =====================================================================================
   PROPERTY SET Instances <2> ( _                       ' VTable offset = 40
     BYVAL varInstances AS LONG _                       ' __in long varInstances
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Frequency <3> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CdoFrequency *pFrequency
   ' =====================================================================================
   PROPERTY SET Frequency <3> ( _                       ' VTable offset = 48
     BYVAL varFrequency AS LONG _                       ' __in CdoFrequency varFrequency
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PatternEndDate <4> ( _                  ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out DATE *pPatternEndDate
   ' =====================================================================================
   PROPERTY SET PatternEndDate <4> ( _                  ' VTable offset = 56
     BYVAL varPatternEndDate AS DOUBLE _                ' __in DATE varPatternEndDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <6> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *varType
   ' =====================================================================================
   PROPERTY GET EndType <7> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out CdoPatternEndType *pEndType
   ' =====================================================================================
   PROPERTY SET EndType <7> ( _                         ' VTable offset = 68
     BYVAL varEndType AS LONG _                         ' __in CdoPatternEndType varEndType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstDayOfWeek <8> ( _                  ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CdoDayOfWeek *pFirstDayOfWeek
   ' =====================================================================================
   PROPERTY SET FirstDayOfWeek <8> ( _                  ' VTable offset = 76
     BYVAL varFirstDayOfWeek AS LONG _                  ' __in CdoDayOfWeek varFirstDayOfWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DaysOfMonth <9> ( _                     ' VTable offset = 80
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varDaysOfMonth
   ' =====================================================================================
   PROPERTY GET DaysOfWeek <10> ( _                     ' VTable offset = 84
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varDaysOfWeek
   ' =====================================================================================
   PROPERTY GET DaysOfYear <11> ( _                     ' VTable offset = 88
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varDaysOfYear
   ' =====================================================================================
   PROPERTY GET SecondsOfMinute <12> ( _                ' VTable offset = 92
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varSecondsOfMinute
   ' =====================================================================================
   PROPERTY GET MinutesOfHour <13> ( _                  ' VTable offset = 96
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varMinutesOfHour
   ' =====================================================================================
   PROPERTY GET HoursOfDay <14> ( _                     ' VTable offset = 100
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varHoursOfDay
   ' =====================================================================================
   PROPERTY GET WeekDays <15> ( _                       ' VTable offset = 104
   ) AS CDO_IVariants                                   ' __retval_out IVariants **varWeekDays
   ' =====================================================================================
   PROPERTY GET WeeksOfYear <16> ( _                    ' VTable offset = 108
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varWeeksOfYear
   ' =====================================================================================
   PROPERTY GET MonthsOfYear <17> ( _                   ' VTable offset = 112
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varMonthsOfYear
   ' =====================================================================================
   PROPERTY GET ByPosition <18> ( _                     ' VTable offset = 116
   ) AS CDO_IIntegers                                   ' __retval_out IIntegers **varByPosition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IRecurrencePattern_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IException
' IID = {CD000124-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage exceptions to a recurring meeting.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IException_INTERFACE_DEFINED)
    %CDO_IException_INTERFACE_DEFINED = 1

INTERFACE CDO_IException $IID_CDO_IException

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *varType
   ' =====================================================================================
   PROPERTY GET RecurrenceIDRange <2> ( _               ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pRecurrenceIDRange
   ' =====================================================================================
   PROPERTY SET RecurrenceIDRange <2> ( _               ' VTable offset = 36
     BYVAL varRecurrenceIDRange AS WSTRING _            ' __in BSTR varRecurrenceIDRange
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecurrenceID <3> ( _                    ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out DATE *pRecurrenceID
   ' =====================================================================================
   PROPERTY SET RecurrenceID <3> ( _                    ' VTable offset = 44
     BYVAL varRecurrenceID AS DOUBLE _                  ' __in DATE varRecurrenceID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <4> ( _                       ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pStartTime
   ' =====================================================================================
   PROPERTY SET StartTime <4> ( _                       ' VTable offset = 52
     BYVAL varStartTime AS DOUBLE _                     ' __in DATE varStartTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndTime <5> ( _                         ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out DATE *pEndTime
   ' =====================================================================================
   PROPERTY SET EndTime <5> ( _                         ' VTable offset = 60
     BYVAL varEndTime AS DOUBLE _                       ' __in DATE varEndTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <101> ( _                        ' VTable offset = 64
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IException_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRecurrencePatterns
' IID = {CD00012C-8B95-11D1-82DB-00C04FB1625D}
' Defines properties and methods used to manage a collection of RecurrencePattern objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IRecurrencePatterns_INTERFACE_DEFINED)
    %CDO_IRecurrencePatterns_INTERFACE_DEFINED = 1

INTERFACE CDO_IRecurrencePatterns $IID_CDO_IRecurrencePatterns

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS CDO_IRecurrencePattern                          ' __retval_out IRecurrencePattern **RecurrencePattern
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL Type AS WSTRING _                            ' __in BSTR Type
   ) AS CDO_IRecurrencePattern                          ' __retval_out IRecurrencePattern **RecurrencePattern
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IRecurrencePatterns_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IExceptions
' IID = {CD00012D-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of Exception objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IExceptions_INTERFACE_DEFINED)
    %CDO_IExceptions_INTERFACE_DEFINED = 1

INTERFACE CDO_IExceptions $IID_CDO_IExceptions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS CDO_IException                                  ' __retval_out IException **Exception
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL Type AS WSTRING _                            ' __in BSTR Type
   ) AS CDO_IException                                  ' __retval_out IException **Exception
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IExceptions_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICalendarPart
' IID = {CD000133-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage calendar-related body parts in a CalendarMessage object.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_ICalendarPart_INTERFACE_DEFINED)
    %CDO_ICalendarPart_INTERFACE_DEFINED = 1

INTERFACE CDO_ICalendarPart $IID_CDO_ICalendarPart

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetAssociatedItem <301> ( _                   ' VTable offset = 28
     OPTIONAL BYVAL CalendarLocation AS WSTRING _       ' __opt_in BSTR CalendarLocation
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS IDispatch                                       ' __retval_out IDispatch **Item
   ' =====================================================================================
   METHOD GetInterface <302> ( _                        ' VTable offset = 32
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   PROPERTY GET ComponentType <303> ( _                 ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CdoComponentType *varComponentType
   ' =====================================================================================
   PROPERTY GET ProdID <304> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *varProdID
   ' =====================================================================================
   PROPERTY GET CalendarVersion <305> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *varCalendarVersion
   ' =====================================================================================
   PROPERTY GET CalendarMethod <307> ( _                ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *varCalendarMethod
   ' =====================================================================================
   METHOD GetUpdatedItem <309> ( _                      ' VTable offset = 52
     OPTIONAL BYVAL CalendarLocation AS WSTRING _       ' __opt_in BSTR CalendarLocation
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS IDispatch                                       ' __retval_out IDispatch **Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICalendarPart_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICalendarParts
' IID = {CD000130-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of CalendarPart objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_ICalendarParts_INTERFACE_DEFINED)
    %CDO_ICalendarParts_INTERFACE_DEFINED = 1

INTERFACE CDO_ICalendarParts $IID_CDO_ICalendarParts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS CDO_ICalendarPart                               ' __retval_out ICalendarPart **CalendarPart
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL CalendarPart AS IUnknown _                   ' __in IUnknown *CalendarPart
   , BYVAL ComponentType AS LONG _                      ' __in CdoComponentType ComponentType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICalendarParts_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAttendee
' IID = {CD000135-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties and collections use to manage appointment attendees.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IAttendee_INTERFACE_DEFINED)
    %CDO_IAttendee_INTERFACE_DEFINED = 1

INTERFACE CDO_IAttendee $IID_CDO_IAttendee

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <1> ( _                     ' VTable offset = 32
     BYVAL varDisplayName AS WSTRING _                  ' __in BSTR varDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pType
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 40
     BYVAL varType AS WSTRING _                         ' __in BSTR varType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Address <3> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pAddress
   ' =====================================================================================
   PROPERTY SET Address <3> ( _                         ' VTable offset = 48
     BYVAL varAddress AS WSTRING _                      ' __in BSTR varAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsOrganizer <4> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pIsOrganizer
   ' =====================================================================================
   PROPERTY SET IsOrganizer <4> ( _                     ' VTable offset = 56
     BYVAL varIsOrganizer AS INTEGER _                  ' __in VARIANT_BOOL varIsOrganizer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Role <6> ( _                            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CdoAttendeeRoleValues *pRole
   ' =====================================================================================
   PROPERTY SET Role <6> ( _                            ' VTable offset = 64
     BYVAL varRole AS LONG _                            ' __in CdoAttendeeRoleValues varRole
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <7> ( _                          ' VTable offset = 68
   ) AS LONG                                            ' __retval_out CdoAttendeeStatusValues *pStatus
   ' =====================================================================================
   PROPERTY SET Status <7> ( _                          ' VTable offset = 72
     BYVAL varStatus AS LONG _                          ' __in CdoAttendeeStatusValues varStatus
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IAttendee_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAttendees
' IID = {CD000136-8B95-11D1-82DB-00C04FB1625D}
' Defines properties and methods used to manage a collection of Attendee objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IAttendees_INTERFACE_DEFINED)
    %CDO_IAttendees_INTERFACE_DEFINED = 1

INTERFACE CDO_IAttendees $IID_CDO_IAttendees

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS CDO_IAttendee                                   ' __retval_out IAttendee **Attendee
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     OPTIONAL BYVAL Address AS WSTRING _                ' __opt_in BSTR Address
   ) AS CDO_IAttendee                                   ' __retval_out IAttendee **Attendee
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAttendees_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMailbox
' IID = {CD000125-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to access information about a user's mailbox folders.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IMailbox_INTERFACE_DEFINED)
    %CDO_IMailbox_INTERFACE_DEFINED = 1

INTERFACE CDO_IMailbox $IID_CDO_IMailbox

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BaseFolder <1> ( _                      ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *varBaseFolder
   ' =====================================================================================
   PROPERTY GET RootFolder <2> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *varRootFolder
   ' =====================================================================================
   PROPERTY GET Inbox <3> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *varInbox
   ' =====================================================================================
   PROPERTY GET Outbox <4> ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *varOutbox
   ' =====================================================================================
   PROPERTY GET SentItems <5> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *varSentItems
   ' =====================================================================================
   PROPERTY GET Drafts <6> ( _                          ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *varDrafts
   ' =====================================================================================
   PROPERTY GET DeletedItems <7> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *varDeletedItems
   ' =====================================================================================
   PROPERTY GET Calendar <8> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *varCalendar
   ' =====================================================================================
   PROPERTY GET Tasks <9> ( _                           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *varTasks
   ' =====================================================================================
   PROPERTY GET Contacts <10> ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *varContacts
   ' =====================================================================================
   PROPERTY GET Notes <11> ( _                          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *varNotes
   ' =====================================================================================
   PROPERTY GET Journal <12> ( _                        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *varJournal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IMailbox_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFolder
' IID = {CD000132-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage a folder.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IFolder_INTERFACE_DEFINED)
    %CDO_IFolder_INTERFACE_DEFINED = 1

INTERFACE CDO_IFolder $IID_CDO_IFolder

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *varDisplayName
   ' =====================================================================================
   PROPERTY GET Configuration <2> ( _                   ' VTable offset = 32
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <2> ( _                   ' VTable offset = 36
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <2> ( _            ' VTable offset = 40
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <3> ( _                      ' VTable offset = 44
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET EmailAddress <5> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *varEmailAddress
   ' =====================================================================================
   PROPERTY GET UnreadItemCount <6> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *varUnreadItemCount
   ' =====================================================================================
   PROPERTY GET VisibleCount <7> ( _                    ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG *varVisibleCount
   ' =====================================================================================
   PROPERTY GET ItemCount <8> ( _                       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *varItemCount
   ' =====================================================================================
   PROPERTY GET HasSubFolders <9> ( _                   ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *varHasSubFolders
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 72
     BYVAL varDescription AS WSTRING _                  ' __in BSTR varDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <13> ( _                         ' VTable offset = 76
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET ContentClass <14> ( _                   ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pContentClass
   ' =====================================================================================
   PROPERTY SET ContentClass <14> ( _                   ' VTable offset = 84
     BYVAL varContentClass AS WSTRING _                 ' __in BSTR varContentClass
   )                                                    ' void
   ' =====================================================================================
   METHOD GetInterface <15> ( _                         ' VTable offset = 88
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IFolder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IContactGroupMembers
' IID = CD000138-8B95-11D1-82DB-00C04FB1625D
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IContactGroupMembers_INTERFACE_DEFINED)
    %CDO_IContactGroupMembers_INTERFACE_DEFINED = 1

$IID_CDO_IContactGroupMembers = GUID$("{CD000138-8B95-11D1-82DB-00C04FB1625D}")

INTERFACE CDO_IContactGroupMembers $IID_CDO_IContactGroupMembers

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' long Index
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Delete <2> ( _                                ' VTable offset = 36
     BYVAL Member AS WSTRING _                          ' __in BSTR *Member
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 40
     BYVAL val AS WSTRING _                             ' __in BSTR val
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IContactGroupMembers_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPerson
' IID = {CD000127-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage information about a person.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IPerson_INTERFACE_DEFINED)
    %CDO_IPerson_INTERFACE_DEFINED = 1

INTERFACE CDO_IPerson $IID_CDO_IPerson

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource <1> ( _                      ' VTable offset = 28
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET Configuration <3> ( _                   ' VTable offset = 32
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <3> ( _                   ' VTable offset = 36
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <3> ( _            ' VTable offset = 40
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <4> ( _                          ' VTable offset = 44
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET MailingAddressID <5> ( _                ' VTable offset = 48
   ) AS LONG                                            ' __retval_out CdoMailingAddressIdValues *pMailingAddressID
   ' =====================================================================================
   PROPERTY SET MailingAddressID <5> ( _                ' VTable offset = 52
     BYVAL varMailingAddressID AS LONG _                ' __in CdoMailingAddressIdValues varMailingAddressID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MailingAddress <6> ( _                  ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *varMailingAddress
   ' =====================================================================================
   PROPERTY GET FileAsMapping <7> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out CdoFileAsMappingId *pFileAsMapping
   ' =====================================================================================
   PROPERTY SET FileAsMapping <7> ( _                   ' VTable offset = 64
     BYVAL varFileAsMapping AS LONG _                   ' __in CdoFileAsMappingId varFileAsMapping
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FileAs <8> ( _                          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pFileAs
   ' =====================================================================================
   PROPERTY SET FileAs <8> ( _                          ' VTable offset = 72
     BYVAL varFileAs AS WSTRING _                       ' __in BSTR varFileAs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkPhone <9> ( _                       ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkPhone
   ' =====================================================================================
   PROPERTY SET WorkPhone <9> ( _                       ' VTable offset = 80
     BYVAL varWorkPhone AS WSTRING _                    ' __in BSTR varWorkPhone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkFax <10> ( _                        ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkFax
   ' =====================================================================================
   PROPERTY SET WorkFax <10> ( _                        ' VTable offset = 88
     BYVAL varWorkFax AS WSTRING _                      ' __in BSTR varWorkFax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePhone <11> ( _                      ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pHomePhone
   ' =====================================================================================
   PROPERTY SET HomePhone <11> ( _                      ' VTable offset = 96
     BYVAL varHomePhone AS WSTRING _                    ' __in BSTR varHomePhone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MobilePhone <12> ( _                    ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pMobilePhone
   ' =====================================================================================
   PROPERTY SET MobilePhone <12> ( _                    ' VTable offset = 104
     BYVAL varMobilePhone AS WSTRING _                  ' __in BSTR varMobilePhone
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FirstName <13> ( _                      ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pFirstName
   ' =====================================================================================
   PROPERTY SET FirstName <13> ( _                      ' VTable offset = 112
     BYVAL varFirstName AS WSTRING _                    ' __in BSTR varFirstName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastName <14> ( _                       ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pLastName
   ' =====================================================================================
   PROPERTY SET LastName <14> ( _                       ' VTable offset = 120
     BYVAL varLastName AS WSTRING _                     ' __in BSTR varLastName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NamePrefix <15> ( _                     ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pNamePrefix
   ' =====================================================================================
   PROPERTY SET NamePrefix <15> ( _                     ' VTable offset = 128
     BYVAL varNamePrefix AS WSTRING _                   ' __in BSTR varNamePrefix
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NameSuffix <16> ( _                     ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pNameSuffix
   ' =====================================================================================
   PROPERTY SET NameSuffix <16> ( _                     ' VTable offset = 136
     BYVAL varNameSuffix AS WSTRING _                   ' __in BSTR varNameSuffix
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Email <17> ( _                          ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pEmail
   ' =====================================================================================
   PROPERTY SET Email <17> ( _                          ' VTable offset = 144
     BYVAL varEmail AS WSTRING _                        ' __in BSTR varEmail
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Email2 <18> ( _                         ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pEmail2
   ' =====================================================================================
   PROPERTY SET Email2 <18> ( _                         ' VTable offset = 152
     BYVAL varEmail2 AS WSTRING _                       ' __in BSTR varEmail2
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Email3 <19> ( _                         ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pEmail3
   ' =====================================================================================
   PROPERTY SET Email3 <19> ( _                         ' VTable offset = 160
     BYVAL varEmail3 AS WSTRING _                       ' __in BSTR varEmail3
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVCardStream <20> ( _                       ' VTable offset = 164
   ) AS ADOStream                                       ' __retval_out _Stream **Stream
   ' =====================================================================================
   METHOD GetInterface <21> ( _                         ' VTable offset = 168
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   PROPERTY GET WorkStreet <22> ( _                     ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkStreet
   ' =====================================================================================
   PROPERTY SET WorkStreet <22> ( _                     ' VTable offset = 176
     BYVAL varWorkStreet AS WSTRING _                   ' __in BSTR varWorkStreet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkCity <23> ( _                       ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkCity
   ' =====================================================================================
   PROPERTY SET WorkCity <23> ( _                       ' VTable offset = 184
     BYVAL varWorkCity AS WSTRING _                     ' __in BSTR varWorkCity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkCountry <24> ( _                    ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkCountry
   ' =====================================================================================
   PROPERTY SET WorkCountry <24> ( _                    ' VTable offset = 192
     BYVAL varWorkCountry AS WSTRING _                  ' __in BSTR varWorkCountry
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkPostalCode <25> ( _                 ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkPostalCode
   ' =====================================================================================
   PROPERTY SET WorkPostalCode <25> ( _                 ' VTable offset = 200
     BYVAL varWorkPostalCode AS WSTRING _               ' __in BSTR varWorkPostalCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkPostOfficeBox <26> ( _              ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkPostOfficeBox
   ' =====================================================================================
   PROPERTY SET WorkPostOfficeBox <26> ( _              ' VTable offset = 208
     BYVAL varWorkPostOfficeBox AS WSTRING _            ' __in BSTR varWorkPostOfficeBox
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkPostalAddress <27> ( _              ' VTable offset = 212
   ) AS WSTRING                                         ' __retval_out BSTR *varWorkPostalAddress
   ' =====================================================================================
   PROPERTY GET WorkState <28> ( _                      ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkState
   ' =====================================================================================
   PROPERTY SET WorkState <28> ( _                      ' VTable offset = 220
     BYVAL varWorkState AS WSTRING _                    ' __in BSTR varWorkState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkPager <29> ( _                      ' VTable offset = 224
   ) AS WSTRING                                         ' __retval_out BSTR *pWorkPager
   ' =====================================================================================
   PROPERTY SET WorkPager <29> ( _                      ' VTable offset = 228
     BYVAL varWorkPager AS WSTRING _                    ' __in BSTR varWorkPager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeStreet <30> ( _                     ' VTable offset = 232
   ) AS WSTRING                                         ' __retval_out BSTR *pHomeStreet
   ' =====================================================================================
   PROPERTY SET HomeStreet <30> ( _                     ' VTable offset = 236
     BYVAL varHomeStreet AS WSTRING _                   ' __in BSTR varHomeStreet
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeCity <31> ( _                       ' VTable offset = 240
   ) AS WSTRING                                         ' __retval_out BSTR *pHomeCity
   ' =====================================================================================
   PROPERTY SET HomeCity <31> ( _                       ' VTable offset = 244
     BYVAL varHomeCity AS WSTRING _                     ' __in BSTR varHomeCity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeCountry <32> ( _                    ' VTable offset = 248
   ) AS WSTRING                                         ' __retval_out BSTR *pHomeCountry
   ' =====================================================================================
   PROPERTY SET HomeCountry <32> ( _                    ' VTable offset = 252
     BYVAL varHomeCountry AS WSTRING _                  ' __in BSTR varHomeCountry
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePostalCode <33> ( _                 ' VTable offset = 256
   ) AS WSTRING                                         ' __retval_out BSTR *pHomePostalCode
   ' =====================================================================================
   PROPERTY SET HomePostalCode <33> ( _                 ' VTable offset = 260
     BYVAL varHomePostalCode AS WSTRING _               ' __in BSTR varHomePostalCode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePostOfficeBox <34> ( _              ' VTable offset = 264
   ) AS WSTRING                                         ' __retval_out BSTR *pHomePostOfficeBox
   ' =====================================================================================
   PROPERTY SET HomePostOfficeBox <34> ( _              ' VTable offset = 268
     BYVAL varHomePostOfficeBox AS WSTRING _            ' __in BSTR varHomePostOfficeBox
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomePostalAddress <35> ( _              ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *varHomePostalAddress
   ' =====================================================================================
   PROPERTY GET HomeState <36> ( _                      ' VTable offset = 276
   ) AS WSTRING                                         ' __retval_out BSTR *pHomeState
   ' =====================================================================================
   PROPERTY SET HomeState <36> ( _                      ' VTable offset = 280
     BYVAL varHomeState AS WSTRING _                    ' __in BSTR varHomeState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HomeFax <37> ( _                        ' VTable offset = 284
   ) AS WSTRING                                         ' __retval_out BSTR *pHomeFax
   ' =====================================================================================
   PROPERTY SET HomeFax <37> ( _                        ' VTable offset = 288
     BYVAL varHomeFax AS WSTRING _                      ' __in BSTR varHomeFax
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MiddleName <38> ( _                     ' VTable offset = 292
   ) AS WSTRING                                         ' __retval_out BSTR *pMiddleName
   ' =====================================================================================
   PROPERTY SET MiddleName <38> ( _                     ' VTable offset = 296
     BYVAL varMiddleName AS WSTRING _                   ' __in BSTR varMiddleName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Initials <39> ( _                       ' VTable offset = 300
   ) AS WSTRING                                         ' __retval_out BSTR *pInitials
   ' =====================================================================================
   PROPERTY SET Initials <39> ( _                       ' VTable offset = 304
     BYVAL varInitials AS WSTRING _                     ' __in BSTR varInitials
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmailAddresses <40> ( _                 ' VTable offset = 308
   ) AS VARIANT                                         '__retval_out VARIANT *pEmailAddresses
   ' =====================================================================================
   PROPERTY SET EmailAddresses <40> ( _                 ' VTable offset = 312
     BYVAL varEmailAddresses AS VARIANT _               ' __in VARIANT varEmailAddresses
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Company <41> ( _                        ' VTable offset = 316
   ) AS WSTRING                                         ' __retval_out BSTR *pCompany
   ' =====================================================================================
   PROPERTY SET Company <41> ( _                        ' VTable offset = 320
     BYVAL varCompany AS WSTRING _                      ' __in BSTR varCompany
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Title <42> ( _                          ' VTable offset = 324
   ) AS WSTRING                                         ' __retval_out BSTR *pTitle
   ' =====================================================================================
   PROPERTY SET Title <42> ( _                          ' VTable offset = 328
     BYVAL varTitle AS WSTRING _                        ' __in BSTR varTitle
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IPerson_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAddressee
' IID = {CD000139-8B95-11D1-82DB-00C04FB1625D}
' Defines methods, properties, and collections used to manage address resolution and free/busy information for addressees.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IAddressee_INTERFACE_DEFINED)
    %CDO_IAddressee_INTERFACE_DEFINED = 1

INTERFACE CDO_IAddressee $IID_CDO_IAddressee

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Fields <1> ( _                          ' VTable offset = 28
   ) AS ADOFields                                       ' __retval_out Fields **varFields
   ' =====================================================================================
   PROPERTY GET Configuration <2> ( _                   ' VTable offset = 32
   ) AS CDO_IConfiguration                              ' __retval_out IConfiguration **pConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <2> ( _                   ' VTable offset = 36
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Configuration <2> ( _            ' VTable offset = 40
     BYVAL varConfiguration AS CDO_IConfiguration _     ' __in IConfiguration *varConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <3> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pDisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <3> ( _                     ' VTable offset = 48
     BYVAL varDisplayName AS WSTRING _                  ' __in BSTR varDisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmailAddress <4> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pEmailAddress
   ' =====================================================================================
   PROPERTY SET EmailAddress <4> ( _                    ' VTable offset = 56
     BYVAL varEmailAddress AS WSTRING _                 ' __in BSTR varEmailAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <5> ( _                      ' VTable offset = 60
   ) AS CDO_IDataSource                                 ' __retval_out IDataSource **varDataSource
   ' =====================================================================================
   PROPERTY GET DirURL <6> ( _                          ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *varDirURL
   ' =====================================================================================
   PROPERTY GET ResolvedStatus <7> ( _                  ' VTable offset = 68
   ) AS LONG                                            ' __retval_out CdoResolvedStatus *pResolvedStatus
   ' =====================================================================================
   PROPERTY SET ResolvedStatus <7> ( _                  ' VTable offset = 72
     BYVAL varResolvedStatus AS LONG _                  ' __in CdoResolvedStatus varResolvedStatus
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentClass <8> ( _                    ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *varContentClass
   ' =====================================================================================
   PROPERTY GET AmbiguousNames <9> ( _                  ' VTable offset = 80
   ) AS CDO_IAddressees                                 ' __retval_out IAddressees **varAmbiguousNames
   ' =====================================================================================
   METHOD GetInterface <10> ( _                         ' VTable offset = 84
     BYVAL Interface AS WSTRING _                       ' __in BSTR Interface
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnknown
   ' =====================================================================================
   METHOD GetFreeBusy <11> ( _                          ' VTable offset = 88
     BYVAL StartTime AS DOUBLE _                        ' __in DATE StartTime
   , BYVAL EndTime AS DOUBLE _                          ' __in DATE EndTime
   , BYVAL Interval AS LONG _                           ' __in long Interval
   , OPTIONAL BYVAL HTTPHost AS WSTRING _               ' __opt_in BSTR HTTPHost
   , OPTIONAL BYVAL VRoot AS WSTRING _                  ' __opt_in BSTR VRoot
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrRet
   ' =====================================================================================
   METHOD CheckName <12> ( _                            ' VTable offset = 92
     BYVAL Directory AS WSTRING _                       ' __in BSTR Directory
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBRet
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CDO_IAddressee_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAddressees
' IID = {CD000142-8B95-11D1-82DB-00C04FB1625D}
' Defines methods and properties used to manage a collection of Addressee objects.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%CDO_IAddressees_INTERFACE_DEFINED)
    %CDO_IAddressees_INTERFACE_DEFINED = 1

INTERFACE CDO_IAddressees $IID_CDO_IAddressees

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS CDO_IAddressee                                  ' __retval_out IAddressee **Value
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **Unknown
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAddressees_INTERFACE_DEFINED__ */


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
