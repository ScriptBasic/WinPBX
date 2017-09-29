' ########################################################################################
' Microsoft Windows
' File: Tapi3Err.inc
' Contents: Error Notifications for TAPI 3.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TAPI3ERR_INC = 1

'//--------------------------------------------------------------------------
'//     Core TAPI Error messages
'//--------------------------------------------------------------------------

'//
'//  Values are 32 bit values layed out as follows:
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


'//
'// Define the severity codes
'//


'//
'// MessageId: TAPI_E_NOTENOUGHMEMORY
'//
'// MessageText:
'//
'//  The buffer passed in to this method was not big enough.
'//
%TAPI_E_NOTENOUGHMEMORY           = &H80040001&

'//
'// MessageId: TAPI_E_NOITEMS
'//
'// MessageText:
'//
'//  No items exist that match the request.
'//
%TAPI_E_NOITEMS                   = &H80040002&

'//
'// MessageId: TAPI_E_NOTSUPPORTED
'//
'// MessageText:
'//
'//  This method is not supported.
'//
%TAPI_E_NOTSUPPORTED              = &H80040003&

'//
'// MessageId: TAPI_E_INVALIDMEDIATYPE
'//
'// MessageText:
'//
'//  The MEDIATYPE passed in to this method was invalid.
'//
%TAPI_E_INVALIDMEDIATYPE          = &H80040004&

'//
'// MessageId: TAPI_E_OPERATIONFAILED
'//
'// MessageText:
'//
'//  The operation failed for an unspecified reason.
'//
%TAPI_E_OPERATIONFAILED           = &H80040005&

'//
'// MessageId: TAPI_E_ALLOCATED
'//
'// MessageText:
'//
'//  The device is already in use.
'//
%TAPI_E_ALLOCATED                 = &H80040006&

'//
'// MessageId: TAPI_E_CALLUNAVAIL
'//
'// MessageText:
'//
'//  No call appearance available.
'//
%TAPI_E_CALLUNAVAIL               = &H80040007&

'//
'// MessageId: TAPI_E_COMPLETIONOVERRUN
'//
'// MessageText:
'//
'//  Too many call completions outstanding.
'//
%TAPI_E_COMPLETIONOVERRUN         = &H80040008&

'//
'// MessageId: TAPI_E_CONFERENCEFULL
'//
'// MessageText:
'//
'//  The conference is full.
'//
%TAPI_E_CONFERENCEFULL            = &H80040009&

'//
'// MessageId: TAPI_E_DIALMODIFIERNOTSUPPORTED
'//
'// MessageText:
'//
'//  The dial modifier is not supported.
'//
%TAPI_E_DIALMODIFIERNOTSUPPORTED  = &H8004000A&

'//
'// MessageId: TAPI_E_INUSE
'//
'// MessageText:
'//
'//  The device is already in use.
'//
%TAPI_E_INUSE                     = &H8004000B&

'//
'// MessageId: TAPI_E_INVALADDRESS
'//
'// MessageText:
'//
'//  The phone number is invalid or not properly formatted.
'//
%TAPI_E_INVALADDRESS              = &H8004000C&

'//
'// MessageId: TAPI_E_INVALADDRESSSTATE
'//
'// MessageText:
'//
'//  Operation not permitted in current address state.
'//
%TAPI_E_INVALADDRESSSTATE         = &H8004000D&

'//
'// MessageId: TAPI_E_INVALCALLPARAMS
'//
'// MessageText:
'//
'//  Invalid LINECALLPARAMS structure.
'//
%TAPI_E_INVALCALLPARAMS           = &H8004000E&

'//
'// MessageId: TAPI_E_INVALCALLPRIVILEGE
'//
'// MessageText:
'//
'//  Invalid call privilege.
'//
%TAPI_E_INVALCALLPRIVILEGE        = &H8004000F&

'//
'// MessageId: TAPI_E_INVALCALLSTATE
'//
'// MessageText:
'//
'//  Operation not permitted in current call state.
'//
%TAPI_E_INVALCALLSTATE            = &H80040010&

'//
'// MessageId: TAPI_E_INVALCARD
'//
'// MessageText:
'//
'//  Invalid calling card.
'//
%TAPI_E_INVALCARD                 = &H80040011&

'//
'// MessageId: TAPI_E_INVALCOMPLETIONID
'//
'// MessageText:
'//
'//  Invalid call completion ID.
'//
%TAPI_E_INVALCOMPLETIONID         = &H80040012&

'//
'// MessageId: TAPI_E_INVALCOUNTRYCODE
'//
'// MessageText:
'//
'//  Invalid country code.
'//
%TAPI_E_INVALCOUNTRYCODE          = &H80040013&

'//
'// MessageId: TAPI_E_INVALDEVICECLASS
'//
'// MessageText:
'//
'//  Invalid device class identifier
'//
%TAPI_E_INVALDEVICECLASS          = &H80040014&

'//
'// MessageId: TAPI_E_INVALDIALPARAMS
'//
'// MessageText:
'//
'//  Invalid dialing parameters
'//
%TAPI_E_INVALDIALPARAMS           = &H80040015&

'//
'// MessageId: TAPI_E_INVALDIGITS
'//
'// MessageText:
'//
'//  Invalid digits.
'//
%TAPI_E_INVALDIGITS               = &H80040016&

'//
'// MessageId: TAPI_E_INVALGROUPID
'//
'// MessageText:
'//
'//  Invalid group pickup ID.
'//
%TAPI_E_INVALGROUPID              = &H80040017&

'//
'// MessageId: TAPI_E_INVALLOCATION
'//
'// MessageText:
'//
'//  Invalid location ID.
'//
%TAPI_E_INVALLOCATION             = &H80040018&

'//
'// MessageId: TAPI_E_INVALMESSAGEID
'//
'// MessageText:
'//
'//  Invalid message ID.
'//
%TAPI_E_INVALMESSAGEID            = &H80040019&

'//
'// MessageId: TAPI_E_INVALPARKID
'//
'// MessageText:
'//
'//  Invalid park ID.
'//
%TAPI_E_INVALPARKID               = &H8004001A&

'//
'// MessageId: TAPI_E_INVALRATE
'//
'// MessageText:
'//
'//  Invalid rate.
'//
%TAPI_E_INVALRATE                 = &H8004001B&

'//
'// MessageId: TAPI_E_INVALTIMEOUT
'//
'// MessageText:
'//
'//  Invalid timeout value.
'//
%TAPI_E_INVALTIMEOUT              = &H8004001C&

'//
'// MessageId: TAPI_E_INVALTONE
'//
'// MessageText:
'//
'//  Invalid tone.
'//
%TAPI_E_INVALTONE                 = &H8004001D&

'//
'// MessageId: TAPI_E_INVALLIST
'//
'// MessageText:
'//
'//  Invalid list passed as a parameter
'//
%TAPI_E_INVALLIST                 = &H8004001E&

'//
'// MessageId: TAPI_E_INVALMODE
'//
'// MessageText:
'//
'//  Invalid mode passed as a parameter
'//
%TAPI_E_INVALMODE                 = &H8004001F&

'//
'// MessageId: TAPI_E_NOCONFERENCE
'//
'// MessageText:
'//
'//  The call is not part of a conference.
'//
%TAPI_E_NOCONFERENCE              = &H80040020&

'//
'// MessageId: TAPI_E_NODEVICE
'//
'// MessageText:
'//
'//  The device was removed, or the device class is not recognized.
'//
%TAPI_E_NODEVICE                  = &H80040021&

'//
'// MessageId: TAPI_E_NOREQUEST
'//
'// MessageText:
'//
'//  No Assisted Telephony requests are pending.
'//
%TAPI_E_NOREQUEST                 = &H80040022&

'//
'// MessageId: TAPI_E_NOTOWNER
'//
'// MessageText:
'//
'//  The application is does not have OWNER privilege on the call.
'//
%TAPI_E_NOTOWNER                  = &H80040023&

'//
'// MessageId: TAPI_E_NOTREGISTERED
'//
'// MessageText:
'//
'//  The application is not registered to handle requests.
'//
%TAPI_E_NOTREGISTERED             = &H80040024&

'//
'// MessageId: TAPI_E_REQUESTOVERRUN
'//
'// MessageText:
'//
'//  The request queue is already full.
'//
%TAPI_E_REQUESTOVERRUN            = &H80040025&

'//
'// MessageId: TAPI_E_TARGETNOTFOUND
'//
'// MessageText:
'//
'//  The call handoff failed because the specified target was not found.
'//
%TAPI_E_TARGETNOTFOUND            = &H80040026&

'//
'// MessageId: TAPI_E_TARGETSELF
'//
'// MessageText:
'//
'//  No higher priority target exists for the call handoff.
'//
%TAPI_E_TARGETSELF                = &H80040027&

'//
'// MessageId: TAPI_E_USERUSERINFOTOOBIG
'//
'// MessageText:
'//
'//  The amount of user-user info exceeds the maximum permitted.
'//
%TAPI_E_USERUSERINFOTOOBIG        = &H80040028&

'//
'// MessageId: TAPI_E_REINIT
'//
'// MessageText:
'//
'//  The operation cannot be completed until all TAPI applications shutdown and reinitialize.
'//
%TAPI_E_REINIT                    = &H80040029&

'//
'// MessageId: TAPI_E_ADDRESSBLOCKED
'//
'// MessageText:
'//
'//  You are not permitted to call this number.
'//
%TAPI_E_ADDRESSBLOCKED            = &H8004002A&

'//
'// MessageId: TAPI_E_BILLINGREJECTED
'//
'// MessageText:
'//
'//  The calling card number or other billing information was rejected.
'//
%TAPI_E_BILLINGREJECTED           = &H8004002B&

'//
'// MessageId: TAPI_E_INVALFEATURE
'//
'// MessageText:
'//
'//  Invalid device-specific feature.
'//
%TAPI_E_INVALFEATURE              = &H8004002C&

'//
'// MessageId: TAPI_E_INVALBUTTONLAMPID
'//
'// MessageText:
'//
'//  Invalid button or lamp ID.
'//
%TAPI_E_INVALBUTTONLAMPID         = &H8004002D&

'//
'// MessageId: TAPI_E_INVALBUTTONSTATE
'//
'// MessageText:
'//
'//  Invalid button state.
'//
%TAPI_E_INVALBUTTONSTATE          = &H8004002E&

'//
'// MessageId: TAPI_E_INVALDATAID
'//
'// MessageText:
'//
'//  Invalid data segment ID.
'//
%TAPI_E_INVALDATAID               = &H8004002F&

'//
'// MessageId: TAPI_E_INVALHOOKSWITCHDEV
'//
'// MessageText:
'//
'//  Invalid hookswitch device ID.
'//
%TAPI_E_INVALHOOKSWITCHDEV        = &H80040030&

'//
'// MessageId: TAPI_E_DROPPED
'//
'// MessageText:
'//
'//  The call was disconnected.
'//
%TAPI_E_DROPPED                   = &H80040031&

'//
'// MessageId: TAPI_E_NOREQUESTRECIPIENT
'//
'// MessageText:
'//
'//  No program is available to handle the request.
'//
%TAPI_E_NOREQUESTRECIPIENT        = &H80040032&

'//
'// MessageId: TAPI_E_REQUESTQUEUEFULL
'//
'// MessageText:
'//
'//  The queue of call requests is full.
'//
%TAPI_E_REQUESTQUEUEFULL          = &H80040033&

'//
'// MessageId: TAPI_E_DESTBUSY
'//
'// MessageText:
'//
'//  The called number is busy.
'//
%TAPI_E_DESTBUSY                  = &H80040034&

'//
'// MessageId: TAPI_E_DESTNOANSWER
'//
'// MessageText:
'//
'//  The called party does not answer.
'//
%TAPI_E_DESTNOANSWER              = &H80040035&

'//
'// MessageId: TAPI_E_DESTUNAVAIL
'//
'// MessageText:
'//
'//  The called number could not be reached
'//
%TAPI_E_DESTUNAVAIL               = &H80040036&

'//
'// MessageId: TAPI_E_REQUESTFAILED
'//
'// MessageText:
'//
'//  The request failed for unspecified reasons.
'//
%TAPI_E_REQUESTFAILED             = &H80040037&

'//
'// MessageId: TAPI_E_REQUESTCANCELLED
'//
'// MessageText:
'//
'//  The request was cancelled.
'//
%TAPI_E_REQUESTCANCELLED          = &H80040038&

'//
'// MessageId: TAPI_E_INVALPRIVILEGE
'//
'// MessageText:
'//
'//  Invalid privilege.
'//
%TAPI_E_INVALPRIVILEGE            = &H80040039&

'//
'// MessageId: TAPI_E_INVALIDDIRECTION
'//
'// MessageText:
'//
'//  The TERMINAL_DIRECTION passed in was invalid.
'//
%TAPI_E_INVALIDDIRECTION          = &H8004003A&

'//
'// MessageId: TAPI_E_INVALIDTERMINAL
'//
'// MessageText:
'//
'//  The Terminal passed in was invalid for this operation.
'//
%TAPI_E_INVALIDTERMINAL           = &H8004003B&

'//
'// MessageId: TAPI_E_INVALIDTERMINALCLASS
'//
'// MessageText:
'//
'//  The Terminal Class is invalid.
'//
%TAPI_E_INVALIDTERMINALCLASS      = &H8004003C&

'//
'// MessageId: TAPI_E_NODRIVER
'//
'// MessageText:
'//
'//  The service provider was removed.
'//
%TAPI_E_NODRIVER                  = &H8004003D&

'//
'// MessageId: TAPI_E_MAXSTREAMS
'//
'// MessageText:
'//
'//  The maximum number of streams was reached.
'//
%TAPI_E_MAXSTREAMS                = &H8004003E&

'//
'// MessageId: TAPI_E_NOTERMINALSELECTED
'//
'// MessageText:
'//
'//  The operation could not be performed because it requires terminals to be selected.
'//
%TAPI_E_NOTERMINALSELECTED        = &H8004003F&

'//
'// MessageId: TAPI_E_TERMINALINUSE
'//
'// MessageText:
'//
'//  The operation could not be performed because the terminal is in use.
'//
%TAPI_E_TERMINALINUSE             = &H80040040&

'//
'// MessageId: TAPI_E_NOTSTOPPED
'//
'// MessageText:
'//
'//  The operation could not be performed because it requires the stream to be stopped.
'//
%TAPI_E_NOTSTOPPED                = &H80040041&

'//
'// MessageId: TAPI_E_MAXTERMINALS
'//
'// MessageText:
'//
'//  The maximum number of terminals has been reached.
'//
%TAPI_E_MAXTERMINALS              = &H80040042&

'//
'// MessageId: TAPI_E_INVALIDSTREAM
'//
'// MessageText:
'//
'//  The Stream passed in was invalid for this operation.
'//
%TAPI_E_INVALIDSTREAM             = &H80040043&

'//
'// MessageId: TAPI_E_TIMEOUT
'//
'// MessageText:
'//
'//  The call failed due to a timeout.
'//
%TAPI_E_TIMEOUT                   = &H80040044&

'//--------------------------------------------------------------------------
'//     Call Center Error messages
'//--------------------------------------------------------------------------

'//
'// MessageId: TAPI_E_CALLCENTER_GROUP_REMOVED
'//
'// MessageText:
'//
'//  The ACD Proxy has removed this Group. Operations on this object are invalid.
'//
%TAPI_E_CALLCENTER_GROUP_REMOVED  = &H80040045&

'//
'// MessageId: TAPI_E_CALLCENTER_QUEUE_REMOVED
'//
'// MessageText:
'//
'//  The ACD Proxy has removed this Queue. Operations on this object are invalid.
'//
%TAPI_E_CALLCENTER_QUEUE_REMOVED  = &H80040046&

'//
'// MessageId: TAPI_E_CALLCENTER_NO_AGENT_ID
'//
'// MessageText:
'//
'//  The Agent object was created with CreateAgent. It does not have an ID, use CreateAgentWithID.
'//
%TAPI_E_CALLCENTER_NO_AGENT_ID    = &H80040047&

'//
'// MessageId: TAPI_E_CALLCENTER_INVALAGENTID
'//
'// MessageText:
'//
'//  Invalid agent ID.
'//
%TAPI_E_CALLCENTER_INVALAGENTID   = &H80040048&

'//
'// MessageId: TAPI_E_CALLCENTER_INVALAGENTGROUP
'//
'// MessageText:
'//
'//  Invalid agent group.
'//
%TAPI_E_CALLCENTER_INVALAGENTGROUP = &H80040049&

'//
'// MessageId: TAPI_E_CALLCENTER_INVALPASSWORD
'//
'// MessageText:
'//
'//  Invalid agent password.
'//
%TAPI_E_CALLCENTER_INVALPASSWORD  = &H8004004A&

'//
'// MessageId: TAPI_E_CALLCENTER_INVALAGENTSTATE
'//
'// MessageText:
'//
'//  Invalid agent state
'//
%TAPI_E_CALLCENTER_INVALAGENTSTATE = &H8004004B&

'//
'// MessageId: TAPI_E_CALLCENTER_INVALAGENTACTIVITY
'//
'// MessageText:
'//
'//  Invalid agent activity.
'//
%TAPI_E_CALLCENTER_INVALAGENTACTIVITY = &H8004004C&

'//
'// MessageId: TAPI_E_REGISTRY_SETTING_CORRUPT
'//
'// MessageText:
'//
'//  Registry Setting is Corrupt.
'//
%TAPI_E_REGISTRY_SETTING_CORRUPT  = &H8004004D&

'//--------------------------------------------------------------------------
'//     Terminal Specific Error messages
'//--------------------------------------------------------------------------

'//
'// MessageId: TAPI_E_TERMINAL_PEER
'//
'// MessageText:
'//
'//  The peer for one of these bridge terminals has already been assigned.
'//
%TAPI_E_TERMINAL_PEER             = &H8004004E&

'//
'// MessageId: TAPI_E_PEER_NOT_SET
'//
'// MessageText:
'//
'//  The peer for this bridge terminal must be set to complete this operation.
'//
%TAPI_E_PEER_NOT_SET              = &H8004004F&


'//--------------------------------------------------------------------------
'//     Media Service Provider Error messages
'//--------------------------------------------------------------------------
'//
'// MessageId: TAPI_E_NOEVENT
'//
'// MessageText:
'//
'//  There is no event in the MSP's event queue.
'//
%TAPI_E_NOEVENT                   = &H80040050&

'//--------------------------------------------------------------------------
'//     Core TAPI Error messages
'//--------------------------------------------------------------------------

'//
'// MessageId: TAPI_E_INVALADDRESSTYPE
'//
'// MessageText:
'//
'//  The specified address type is not supported by this address.
'//
%TAPI_E_INVALADDRESSTYPE          = &H80040051&

'//
'// MessageId: TAPI_E_RESOURCEUNAVAIL
'//
'// MessageText:
'//
'//  A resource needed to fulfill the request is not available.
'//
%TAPI_E_RESOURCEUNAVAIL           = &H80040052&

'//
'// MessageId: TAPI_E_PHONENOTOPEN
'//
'// MessageText:
'//
'//  The phone is not open.
'//
%TAPI_E_PHONENOTOPEN              = &H80040053&

'//
'// MessageId: TAPI_E_CALLNOTSELECTED
'//
'// MessageText:
'//
'//  The specified call is not currently selected.
'//
%TAPI_E_CALLNOTSELECTED           = &H80040054&

'//
'// MessageId: TAPI_E_WRONGEVENT
'//
'// MessageText:
'//
'//  This information is not available for this type of event.
'//
%TAPI_E_WRONGEVENT                = &H80040055&

'//
'// MessageId: TAPI_E_NOFORMAT
'//
'// MessageText:
'//
'//  The format is unknown
'//
%TAPI_E_NOFORMAT                  = &H80040056&

'//
'// MessageId: TAPI_E_INVALIDSTREAMSTATE
'//
'// MessageText:
'//
'//  The operation is not permitted in current stream state.
'//
%TAPI_E_INVALIDSTREAMSTATE        = &H80040057&

'//
'// MessageId: TAPI_E_WRONG_STATE
'//
'// MessageText:
'//
'//  The operation requested is not permitted for the current state.
'//
%TAPI_E_WRONG_STATE               = &H80040058&

'//
'// MessageId: TAPI_E_NOT_INITIALIZED
'//
'// MessageText:
'//
'//  The object has not been initialized.
'//
%TAPI_E_NOT_INITIALIZED           = &H80040059&

'//
'// MessageId: TAPI_E_SERVICE_NOT_RUNNING
'//
'// MessageText:
'//
'//  The Telephony Service could not be contacted.
'//
%TAPI_E_SERVICE_NOT_RUNNING       = &H8004005A&
