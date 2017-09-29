' ########################################################################################
' Microsoft Windows
' File: dot1x.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DOT1X_INC = 1

#INCLUDE ONCE "l2cmn.inc"
#INCLUDE ONCE "eaptypes.inc"

'/*
'    The identity that is being used by the 1X module. This is a function of the
'    onex auth mode and system triggers (e.g. user logon/logoff)
'    */
' enum ONEX_AUTH_IDENTITY
%OneXAuthIdentityNone         = 0
%OneXAuthIdentityMachine      = 1
%OneXAuthIdentityUser         = 2
%OneXAuthIdentityExplicitUser = 3
%OneXAuthIdentityGuest        = 4
%OneXAuthIdentityInvalid      = 5

'/*
'    The 1X authentication status. Each of the auth status corresponds to one or
'    more of the internal 1X states.
'    */
' enum ONEX_AUTH_STATUS
%OneXAuthNotStarted           = 0
%OneXAuthInProgress           = 1
%OneXAuthNoAuthenticatorFound = 2
%OneXAuthSuccess              = 3
%OneXAuthFailure              = 4
%OneXAuthInvalid              = 5

'/*
'    1X specific reason codes
'    */
' enum ONEX_REASON_CODE
%ONEX_REASON_CODE_SUCCESS = 0
%ONEX_REASON_START = %L2_REASON_CODE_ONEX_BASE
%ONEX_UNABLE_TO_IDENTIFY_USER = %ONEX_REASON_START + 1
%ONEX_IDENTITY_NOT_FOUND = %ONEX_UNABLE_TO_IDENTIFY_USER + 1
%ONEX_UI_DISABLED = %ONEX_IDENTITY_NOT_FOUND + 1
%ONEX_UI_FAILURE = %ONEX_UI_DISABLED + 1
%ONEX_EAP_FAILURE_RECEIVED = %ONEX_UI_FAILURE + 1
%ONEX_AUTHENTICATOR_NO_LONGER_PRESENT = %ONEX_EAP_FAILURE_RECEIVED + 1
%ONEX_NO_RESPONSE_TO_IDENTITY = %ONEX_AUTHENTICATOR_NO_LONGER_PRESENT + 1
%ONEX_PROFILE_VERSION_NOT_SUPPORTED = %ONEX_NO_RESPONSE_TO_IDENTITY + 1
%ONEX_PROFILE_INVALID_LENGTH = %ONEX_PROFILE_VERSION_NOT_SUPPORTED + 1
%ONEX_PROFILE_DISALLOWED_EAP_TYPE = %ONEX_PROFILE_INVALID_LENGTH + 1
%ONEX_PROFILE_INVALID_EAP_TYPE_OR_FLAG = %ONEX_PROFILE_DISALLOWED_EAP_TYPE + 1
%ONEX_PROFILE_INVALID_ONEX_FLAGS = %ONEX_PROFILE_INVALID_EAP_TYPE_OR_FLAG + 1
%ONEX_PROFILE_INVALID_TIMER_VALUE = %ONEX_PROFILE_INVALID_ONEX_FLAGS + 1
%ONEX_PROFILE_INVALID_SUPPLICANT_MODE = %ONEX_PROFILE_INVALID_TIMER_VALUE + 1
%ONEX_PROFILE_INVALID_AUTH_MODE = %ONEX_PROFILE_INVALID_SUPPLICANT_MODE + 1
%ONEX_PROFILE_INVALID_EAP_CONNECTION_PROPERTIES = %ONEX_PROFILE_INVALID_AUTH_MODE + 1
%ONEX_UI_CANCELLED = %ONEX_PROFILE_INVALID_EAP_CONNECTION_PROPERTIES + 1
%ONEX_PROFILE_INVALID_EXPLICIT_CREDENTIALS = %ONEX_UI_CANCELLED + 1
%ONEX_PROFILE_EXPIRED_EXPLICIT_CREDENTIALS = %ONEX_PROFILE_INVALID_EXPLICIT_CREDENTIALS + 1
%ONEX_UI_NOT_PERMITTED = %ONEX_PROFILE_EXPIRED_EXPLICIT_CREDENTIALS + 1

'/*
'    Events for which 1X sends notifications to MSM

'    On getting an event notification the callee should switch on the dwEvent.

'    If dwEvent =  OneXNotificationTypeResultUpdate, pvEventData points to an
'    ONEX_RESULT_UPDATE_DATA structure

'    If dwEvent = OneXNotificationTypeOneXUserIdentified, pvEventData points to
'    a ONEX_USER_INFO structure

'    If dwEvent = OneXNotificationTypeGotOneXIdentityString, pvEventData points to
'    the identity (LPWSTR) being used for the 1X authentication

'    If dwEvent = OneXNotificationTypeFallenBackOnGuest pvEventData is NULL

'    if dwEvent = OneXNotificationTypeAuthRestarted, pvEventData points
'    to the restart reason
'    */

' enum ONEX_NOTIFICATION_TYPE
%OneXPublicNotificationBase = 0
%OneXNotificationTypeResultUpdate = 1
%OneXNotificationTypeAuthRestarted = 2
%OneXNotificationTypeEventInvalid = 3
%OneXNumNotifications = %OneXNotificationTypeEventInvalid

'/*
'    The following list enumerates the reason for the 1X authentication process
'    getting restarted
'    */

' enum ONEX_AUTH_RESTART_REASON
%OneXRestartReasonPeerInitiated = 0
%OneXRestartReasonMsmInitiated = 1
%OneXRestartReasonOneXHeldStateTimeout = 2
%OneXRestartReasonOneXAuthTimeout = 3
%OneXRestartReasonOneXConfigurationChanged = 4
%OneXRestartReasonOneXUserChanged = 5
%OneXRestartReasonQuarantineStateChanged = 6
%OneXRestartReasonAltCredsTrial = 7
%OneXRestartReasonInvalid = 8

' // Size = 8 bytes
TYPE ONEX_VARIABLE_BLOB DWORD
   dwSize   AS DWORD   ' DWORD
   dwOffset AS DWORD   ' DWORD
END TYPE

'/*
'    The set of parameters that define the authentication context for 1X
'    */

' // Size = 64 bytes
TYPE ONEX_AUTH_PARAMS DWORD
   fUpdatePending    AS LONG                 ' BOOL
   oneXConnProfile   AS ONEX_VARIABLE_BLOB
   authIdentity      AS LONG                 ' ONEX_AUTH_IDENTITY
   dwQuarantineState AS DWORD                ' DWORD
   fSessionId        AS BIT * 1 IN DWORD
   fhUserToken       AS BIT * 1
   fOnexUserProfile  AS BIT * 1
   fIdentity         AS BIT * 1
   fUserName         AS BIT * 1
   fDomain           AS BIT * 1
   dwSessionId       AS DWORD                ' DWORD
   hUserToken        AS DWORD                ' HANDLE
   OneXUserProfile   AS ONEX_VARIABLE_BLOB
   Identity          AS ONEX_VARIABLE_BLOB
   UserName          AS ONEX_VARIABLE_BLOB
   Domain            AS ONEX_VARIABLE_BLOB
END TYPE

' // Size = 92 bytes
TYPE ONEX_EAP_ERROR DWORD
   dwWinError       AS DWORD   ' DWORD
   type             AS EAP_METHOD_TYPE
   dwReasonCode     AS DWORD   ' DWORD
   rootCauseGuid    AS GUID    ' GUID
   repairGuid       AS GUID    ' GUID
   helpLinkGuid     AS GUID    ' GUID
   fRootCauseString AS BIT * 1 IN DWORD
   fRepairString    AS BIT * 1
   RootCauseString  AS ONEX_VARIABLE_BLOB
   RepairString     AS ONEX_VARIABLE_BLOB
END TYPE

' // Size = 12 bytes
TYPE ONEX_STATUS DWORD
   authStatus AS LONG   ' ONEX_AUTH_STATUS
   ' /*
   '     Any errors that happened during the authentication are indicated as
   '     error and reason codes below
   '     */
   dwReason  AS DWORD   ' DWORD
   dwError   AS DWORD   ' DWORD
END TYPE

' enum ONEX_EAP_METHOD_BACKEND_SUPPORT
%OneXEapMethodBackendSupportUnknown = 0
%OneXEapMethodBackendSupported = 1
%OneXEapMethodBackendUnsupported = 2

' // Size = 40 bytes
TYPE ONEX_RESULT_UPDATE_DATA DWORD
   oneXStatus      AS ONEX_STATUS
   BackendSupport  AS LONG   ' ONEX_EAP_METHOD_BACKEND_SUPPORT
   fBackendEngaged AS LONG   ' BOOL
   fOneXAuthParams AS BIT * 1 IN DWORD
   fEapError       AS BIT * 1
   authParams      AS ONEX_VARIABLE_BLOB
   eapError        AS ONEX_VARIABLE_BLOB
END TYPE

' // Size = 24 bytes
TYPE ONEX_USER_INFO DWORD
   authIdentity AS LONG   ' ONEX_AUTH_IDENTITY
   fUserName    AS BIT * 1 IN DWORD
   fDomainName  AS BIT * 1
   UserName     AS ONEX_VARIABLE_BLOB
   DomainName   AS ONEX_VARIABLE_BLOB
END TYPE
