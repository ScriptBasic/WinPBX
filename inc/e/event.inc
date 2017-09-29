' ########################################################################################
' Microsoft Windows
' File: event.inc
' Contents: Microsoft Windows Media Technologies
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVENT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "WMSContext.inc"
#INCLUDE ONCE "WMSEvent.inc"

$IID_IWMSEventNotificationPlugin    = GUID$("{BE185FF0-6932-11D2-8B3B-006097B01206}")
$IID_IWMSEventAuthorizationPlugin   = GUID$("{BE185FF1-6932-11D2-8B3B-006097B01206}")
$IID_IWMSEventAuthorizationCallback = GUID$("{BE185FF2-6932-11D2-8B3B-006097B01206}")
$IID_IWMSCustomEventCallback        = GUID$("{8FBD4D04-970D-4D37-BBC6-6FBBB74EAC9D}")

' WMS_SERVER_EVENT_TYPE enum
%WMS_EVENT_SERVER_ONLINE                          = 0
%WMS_EVENT_SERVER_OFFLINE                         = 1
%WMS_EVENT_SERVER_CRITICAL_ERROR                  = 2
%WMS_EVENT_SERVER_PROPERTY_CHANGE                 = 3
%WMS_EVENT_SERVER_ALLOW_CLIENTS_TO_CONNECT_CHANGE = 4
%WMS_EVENT_SERVER_PLUGIN_LOAD_TYPE_CHANGE         = 5
%WMS_EVENT_SERVER_REVERSE_PROXY_MODE_CHANGE       = 6
%WMS_EVENT_SERVER_DOWNLOAD_START                  = 7
%WMS_EVENT_SERVER_DOWNLOAD_COMPLETE               = 8
%WMS_NUM_SERVER_EVENTS                            = 9

' WMS_PUBLISHING_POINT_EVENT_TYPE enum
%WMS_EVENT_PUBLISHING_POINT_ADD                                            = 0
%WMS_EVENT_PUBLISHING_POINT_REMOVE                                         = 1
%WMS_EVENT_PUBLISHING_POINT_ALLOW_CLIENTS_TO_CONNECT_CHANGE                = 2
%WMS_EVENT_PUBLISHING_POINT_START_WITHOUT_DATA                             = 3
%WMS_EVENT_PUBLISHING_POINT_START                                          = 4
%WMS_EVENT_PUBLISHING_POINT_STOP                                           = 5
%WMS_EVENT_PUBLISHING_POINT_START_ARCHIVE                                  = 6
%WMS_EVENT_PUBLISHING_POINT_STOP_ARCHIVE                                   = 7
%WMS_EVENT_PUBLISHING_POINT_NAME_CHANGE                                    = 8
%WMS_EVENT_PUBLISHING_POINT_PATH_CHANGE                                    = 9
%WMS_EVENT_PUBLISHING_POINT_ALLOW_CLIENT_TO_START_AND_STOP_CHANGE          = 10
%WMS_EVENT_PUBLISHING_POINT_PROPERTY_CHANGE                                = 11
%WMS_EVENT_PUBLISHING_POINT_WRAPPER_PATH_CHANGE                            = 12
%WMS_EVENT_PUBLISHING_POINT_ENABLE_WRAPPER_PATH_CHANGE                     = 13
%WMS_EVENT_PUBLISHING_POINT_ALLOW_CONTENT_CACHING_CHANGE                   = 14
%WMS_EVENT_PUBLISHING_POINT_STREAM_END                                     = 15
%WMS_EVENT_PUBLISHING_POINT_CRITICAL_ERROR                                 = 16
%WMS_EVENT_PUBLISHING_POINT_ENABLE_CLIENT_WILDCARD_DIRECTORY_ACCESS_CHANGE = 17
%WMS_EVENT_PUBLISHING_POINT_DISTRIBUTION_USER_NAME_CHANGE                  = 18
%WMS_EVENT_PUBLISHING_POINT_DISTRIBUTION_PASSWORD_CHANGE                   = 19
%WMS_EVENT_PUBLISHING_POINT_ALLOW_PLAYER_SIDE_DISK_CACHING_CHANGE          = 20
%WMS_EVENT_PUBLISHING_POINT_BUFFER_SETTING_CHANGE                          = 21
%WMS_EVENT_PUBLISHING_POINT_ENABLE_FEC_CHANGE                              = 22
%WMS_EVENT_PUBLISHING_POINT_ENABLE_STARTUPPROFILE_CHANGE                   = 23
%WMS_EVENT_PUBLISHING_POINT_ENABLE_VROOT_START_CHANGE                      = 24
%WMS_NUM_PUBLISHINGPOINT_EVENTS                                            = 25

' WMS_LIMIT_CHANGE_EVENT_TYPE enum
%WMS_EVENT_LIMIT_CHANGE_CONNECTED_PLAYERS                 = 0
%WMS_EVENT_LIMIT_CHANGE_PLAYER_BANDWIDTH                  = 1
%WMS_EVENT_LIMIT_CHANGE_PLAYER_CONNECTION_BANDWIDTH       = 2
%WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_CONNECTIONS          = 3
%WMS_EVENT_LIMIT_CHANGE_PLAYER_INACTIVITY_TIMEOUT         = 4
%WMS_EVENT_LIMIT_CHANGE_PLAYER_ACKNOWLEDGEMENT_TIMEOUT    = 5
%WMS_EVENT_LIMIT_CHANGE_CONNECTION_RATE                   = 6
%WMS_EVENT_LIMIT_CHANGE_CPU_UTILIZATION_DURING_CONNECTION = 7
%WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_BANDWIDTH            = 8
%WMS_EVENT_LIMIT_CHANGE_DISTRIBUTION_CONNECTION_BANDWIDTH = 9
%WMS_EVENT_LIMIT_CHANGE_DIAGNOSTIC_EVENTS                 = 10
%WMS_EVENT_LIMIT_CHANGE_PLAYER_CACHE_DELIVERY_RATE        = 11
%WMS_EVENT_LIMIT_CHANGE_FEC_PACKET_SPAN                   = 12
%WMS_EVENT_LIMIT_CHANGE_INCOMING_BANDWIDTH                = 13
%WMS_NUM_LIMIT_CHANGE_EVENTS                              = 14

' WMS_LIMIT_HIT_EVENT_TYPE enum
%WMS_EVENT_LIMIT_HIT_CONNECTED_PLAYERS                  = 0
%WMS_EVENT_LIMIT_HIT_PLAYER_BANDWIDTH                   = 1
%WMS_EVENT_LIMIT_HIT_PLAYER_CONNECTION_BANDWIDTH        = 2
%WMS_EVENT_LIMIT_HIT_DISTRIBUTION_CONNECTIONS           = 3
%WMS_EVENT_LIMIT_HIT_PLAYER_INACTIVITY_TIMEOUT          = 4
%WMS_EVENT_LIMIT_HIT_PLAYER_ACKNOWLEDGEMENT_TIMEOUT     = 5
%WMS_EVENT_LIMIT_HIT_CONNECTION_RATE                    = 6
%WMS_EVENT_LIMIT_HIT_CPU_UTILIZATION_DURING_CONNECTION  = 7
%WMS_EVENT_LIMIT_HIT_DISTRIBUTION_BANDWIDTH             = 8
%WMS_EVENT_LIMIT_HIT_DISTRIBUTION_CONNECTION_BANDWIDTH  = 9
%WMS_EVENT_LIMIT_HIT_INCOMING_BANDWIDTH                 = 10
%WMS_NUM_LIMIT_HIT_EVENTS                               = 11

' WMS_PLUGIN_EVENT_TYPE enum
%WMS_EVENT_PLUGIN_ADD                    = 0
%WMS_EVENT_PLUGIN_REMOVE                 = 1
%WMS_EVENT_PLUGIN_ENABLE                 = 2
%WMS_EVENT_PLUGIN_DISABLE                = 3
%WMS_EVENT_PLUGIN_PROPERTY_CHANGE        = 4
%WMS_EVENT_PLUGIN_ERROR                  = 5
%WMS_EVENT_PLUGIN_NAME_CHANGE            = 6
%WMS_EVENT_PLUGIN_LOAD_TYPE_CHANGE       = 7
%WMS_EVENT_PLUGIN_SELECTION_ORDER_CHANGE = 8
%WMS_NUM_PLUGIN_EVENTS                   = 9

' WMS_CACHE_EVENT_TYPE enum
%WMS_EVENT_CACHE_HIT               = 0
%WMS_EVENT_CACHE_MISS              = 1
%WMS_EVENT_CACHE_DOWNLOAD_START    = 2
%WMS_EVENT_CACHE_DOWNLOAD_COMPLETE = 3
%WMS_EVENT_CACHE_REDIRECT          = 4
%WMS_EVENT_CACHE_REDIRECT_TO_PROXY = 5
%WMS_EVENT_CACHE_PRESTUFF_COMPLETE = 6
%WMS_NUM_CACHE_EVENTS              = 7

' WMS_PLAYLIST_EVENT_TYPE enum
%WMS_EVENT_PLAYLIST_SWITCH   = 0
%WMS_EVENT_PLAYLIST_CUE      = 1
%WMS_EVENT_PLAYLIST_MODIFY   = 2
%WMS_EVENT_PLAYLIST_FAILOVER = 3
%WMS_NUM_PLAYLIST_EVENTS     = 4

' WMS_RECORD_PROGRESS_OPCODE enum
%WMS_RECORD_PROGRESS_ARCHIVE_STARTED  = 0
%WMS_RECORD_PROGRESS_ARCHIVE_FINISHED = 1

' ########################################################################################
' Interface name = IWMSEventNotificationPlugin
' IID = {BE185FF0-6932-11D2-8B3B-006097B01206}
' Provides methods to retrieve the notification events that a plug-in subscribes to and to indicate when these events are fired.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSEventNotificationPlugin_INTERFACE_DEFINED)
    %IWMSEventNotificationPlugin_INTERFACE_DEFINED = 1

INTERFACE IWMSEventNotificationPlugin $IID_IWMSEventNotificationPlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHandledEvents ( _                          ' VTable offset = 12
     BYREF pvarEvents AS VARIANT _                      ' __retval_out VARIANT *pvarEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 16
     BYREF pEvent AS WMS_EVENT _                        ' __in WMS_EVENT *pEvent
   , BYVAL pUserCtx AS IWMSContext _                    ' __in IWMSContext *pUserCtx
   , BYVAL pPresentationCtx AS IWMSContext _            ' __in IWMSContext *pPresentationCtx
   , BYVAL pCommandCtx AS IWMSCommandContext _          ' __in IWMSCommandContext *pCommandCtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSEventNotificationPlugin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSEventAuthorizationPlugin
' IID = {BE185FF1-6932-11D2-8B3B-006097B01206}
' Provides methods to retrieve the authorization events that a plugin subscribes to and to indicate when these events are fired.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSEventAuthorizationPlugin_INTERFACE_DEFINED)
    %IWMSEventAuthorizationPlugin_INTERFACE_DEFINED = 1

INTERFACE IWMSEventAuthorizationPlugin $IID_IWMSEventAuthorizationPlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAuthorizedEvents ( _                       ' VTable offset = 12
     BYREF pvarEvents AS VARIANT _                      ' __retval_out VARIANT *pvarEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AuthorizeEvent ( _                            ' VTable offset = 16
     BYREF pEvent AS WMS_EVENT _                        ' __in WMS_EVENT *pEvent
   , BYVAL pUserCtx AS IWMSContext _                    ' __in IWMSContext *pUserCtx
   , BYVAL pPresentationCtx AS IWMSContext _            ' __in IWMSContext *pPresentationCtx
   , BYVAL pCommandCtx AS IWMSCommandContext _          ' __in IWMSCommandContext *pCommandCtx
   , BYVAL pCallback AS IWMSEventAuthorizationCallback _ ' __in IWMSEventAuthorizationCallback *pCallback
   , BYVAL Context AS VARIANT _                         ' __in VARIANT Context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSEventAuthorizationPlugin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSEventAuthorizationCallback
' IID = {BE185FF2-6932-11D2-8B3B-006097B01206}
' Provides a method to report the results of an event authorization.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSEventAuthorizationCallback_INTERFACE_DEFINED)
    %IWMSEventAuthorizationCallback_INTERFACE_DEFINED = 1

INTERFACE IWMSEventAuthorizationCallback $IID_IWMSEventAuthorizationCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAuthorizeEvent ( _                          ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in long hr
   , BYVAL Context AS VARIANT _                         ' __in VARIANT Context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSEventAuthorizationCallback_INTERFACE_DEFINED__ */
