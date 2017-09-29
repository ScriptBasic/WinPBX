' ########################################################################################
' Microsoft Windows
' File: Sens.inc
' Contents: This file is the master header file for Event System events published
' and subscribed by the System Event Notification service (SENS).
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SENS_INC = 1

'//
'// Constants
'//

%CONNECTION_LAN   = &H00000001
%CONNECTION_WAN   = &H00000002
%CONNECTION_AOL   = &H00000004

'//
'// SENS Guids related to Event System
'//

$SENSGUID_PUBLISHER          = GUID$("{5fee1bd6-5b9b-11d1-8dd2-00aa004abd5e}")
$SENSGUID_SUBSCRIBER_LCE     = GUID$("{d3938ab0-5b9d-11d1-8dd2-00aa004abd5e}")
$SENSGUID_SUBSCRIBER_WININET = GUID$("{d3938ab5-5b9d-11d1-8dd2-00aa004abd5e}")

'//
'// Classes of Events published by SENS
'//

$SENSGUID_EVENTCLASS_NETWORK = GUID$("{d5978620-5b9f-11d1-8dd2-00aa004abd5e}")
$SENSGUID_EVENTCLASS_LOGON   = GUID$("{d5978630-5b9f-11d1-8dd2-00aa004abd5e}")
$SENSGUID_EVENTCLASS_ONNOW   = GUID$("{d5978640-5b9f-11d1-8dd2-00aa004abd5e}")
$SENSGUID_EVENTCLASS_LOGON2  = GUID$("{d5978650-5b9f-11d1-8dd2-00aa004abd5e}")
