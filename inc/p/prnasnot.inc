' ########################################################################################
' Microsoft Windows
' File: prnasnot.inc
' Contents: Header file for Print APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PRNASNOT_INC = 1

'#if (NTDDI_VERSION >= NTDDI_VISTA)

#INCLUDE ONCE "initguid.inc"
#INCLUDE ONCE "objbase.inc"

$IID_IPrintAsyncNotifyChannel      = GUID$("{4A5031B1-1F3F-4DB0-A462-4530ED8B0451}")
$IID_IPrintAsyncNotifyCallback     = GUID$("{7DEF34C1-9D92-4C99-B3B3-DB94A9D4191B}")
$IID_IPrintAsyncNotifyDataObject   = GUID$("{77CF513E-5D49-4789-9F30-D0822B335C0D}")
$NOTIFICATION_RELEASE              = GUID$("{BA9A5027-A70E-4AE7-9B7D-EB3E06AD4157}")

'//
'// Global Application Bidi Notification Channel
'//   All Apps interested in Bidi Notifications from the Print subsystem should register for
'//   notifications on this Channel GUID
'//
'// {2ABAD223-B994-4ACA-82FC-4571B1B585AC}
$PRINT_APP_BIDI_NOTIFY_CHANNEL     = GUID$("{2ABAD223-B994-4ACA-82FC-4571B1B585AC}")

'//
'// Global Port Monitor Bidi Notification Channel
'//   This is the Global Channel GUID that all Bidi enabled Port Monitor should open to send
'//   Bidi Schema notifications up
'//
'// {25DF3B0E-74A9-47F5-80CE-79B4B1EB5C58}
$PRINT_PORT_MONITOR_NOTIFY_CHANNEL = GUID$("{25DF3B0E-74A9-47F5-80CE-79B4B1EB5C58}")

' enum PrintAsyncNotifyUserFilter
%kPerUser  = 0
%kAllUsers = 1

' enum PrintAsyncNotifyConversationStyle
%kBiDirectional  = 0
%kUniDirectional = 1

'typedef GUID PrintAsyncNotificationType;

' ########################################################################################
' IPrintAsyncNotifyDataObject interface
' IID = 77CF513E-5D49-4789-9F30-D0822B335C0D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrintAsyncNotifyDataObject_INTERFACE_DEFINED)
    %IPrintAsyncNotifyDataObject_INTERFACE_DEFINED = 1

INTERFACE IPrintAsyncNotifyDataObject $IID_IPrintAsyncNotifyDataObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AcquireData ( _                               ' VTable offset = 12
     BYREF ppNotificationData AS DWORD _                ' __out BYTE **ppNotificationData
   , BYREF pSize AS DWORD _                             ' __out ULONG *pSize
   , BYREF ppSchema AS GUID _                           ' __out PrintAsyncNotificationType **ppSchema
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseData ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrintAsyncNotifyDataObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IPrintAsyncNotifyChannel interface
' IID = 4A5031B1-1F3F-4DB0-A462-4530ED8B0451
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrintAsyncNotifyChannel_INTERFACE_DEFINED)
    %IPrintAsyncNotifyChannel_INTERFACE_DEFINED = 1

INTERFACE IPrintAsyncNotifyChannel $IID_IPrintAsyncNotifyChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SendNotification ( _                          ' VTable offset = 12
     BYVAL pData AS IPrintAsyncNotifyDataObject _       ' __in IPrintAsyncNotifyDataObject *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseChannel ( _                              ' VTable offset = 16
     BYVAL pData AS IPrintAsyncNotifyDataObject _       ' __in IPrintAsyncNotifyDataObject *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrintAsyncNotifyChannel_INTERFACE_DEFINED__ */


' ########################################################################################
' IPrintAsyncNotifyCallback interface
' IID = 7DEF34C1-9D92-4C99-B3B3-DB94A9D4191B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrintAsyncNotifyCallback_INTERFACE_DEFINED)
    %IPrintAsyncNotifyCallback_INTERFACE_DEFINED = 1

INTERFACE IPrintAsyncNotifyCallback $IID_IPrintAsyncNotifyCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEventNotify ( _                             ' VTable offset = 12
     BYVAL pChannel AS IPrintAsyncNotifyChannel _       ' __in IPrintAsyncNotifyChannel *pChannel
   , BYVAL pData AS IPrintAsyncNotifyDataObject _       ' __in IPrintAsyncNotifyDataObject *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChannelClosed ( _                             ' VTable offset = 16
     BYVAL pChannel AS IPrintAsyncNotifyChannel _       ' __in IPrintAsyncNotifyChannel *pChannel
   , BYVAL pData AS IPrintAsyncNotifyDataObject _       ' __in IPrintAsyncNotifyDataObject *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrintAsyncNotifyCallback_INTERFACE_DEFINED__ */


DECLARE FUNCTION RegisterForPrintAsyncNotifications IMPORT "WINSPOOL.DRV" ALIAS "RegisterForPrintAsyncNotifications" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in_opt PCWSTR                            pszName
 , BYREF pNotificationType AS GUID _                    ' __in     PrintAsyncNotificationType*       pNotificationType
 , BYVAL eUserFilter AS DWORD _                         ' __in     PrintAsyncNotifyUserFilter        eUserFilter
 , BYVAL eConversationStyle AS DWORD _                  ' __in     PrintAsyncNotifyConversationStyle eConversationStyle
 , BYVAL pCallback AS IPrintAsyncNotifyCallback _       ' __in_opt IPrintAsyncNotifyCallback*        pCallback
 , BYREF phNotify AS DWORD _                            ' __out    HANDLE*                           phNotify
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UnRegisterForPrintAsyncNotifications IMPORT "WINSPOOL.DRV" ALIAS "UnRegisterForPrintAsyncNotifications" ( _
   BYVAL pszName AS DWORD _                             ' __in     HANDLE                            pszName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreatePrintAsyncNotifyChannel IMPORT "WINSPOOL.DRV" ALIAS "CreatePrintAsyncNotifyChannel" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in_opt PCWSTR                            pszName
 , BYREF pNotificationType AS GUID _                    ' __in     PrintAsyncNotificationType*       pNotificationType
 , BYVAL eUserFilter AS DWORD _                         ' __in     PrintAsyncNotifyUserFilter        eUserFilter
 , BYVAL eConversationStyle AS DWORD _                  ' __in     PrintAsyncNotifyConversationStyle eConversationStyle
 , BYVAL pCallback AS IPrintAsyncNotifyCallback _       ' __in_opt IPrintAsyncNotifyCallback*        pCallback
 , BYREF ppIAsynchNotification AS IPrintAsyncNotifyChannel _ ' __out    IPrintAsyncNotifyChannel**        ppIAsynchNotification
 ) AS LONG                                              ' HRESULT

' enum PrintAsyncNotifyError
%CHANNEL_CLOSED_BY_SERVER                    = &H01
%CHANNEL_CLOSED_BY_ANOTHER_LISTENER          = &H02
%CHANNEL_CLOSED_BY_SAME_LISTENER             = &H03
%CHANNEL_RELEASED_BY_LISTENER                = &H04
%UNIRECTIONAL_NOTIFICATION_LOST              = &H05
%ASYNC_NOTIFICATION_FAILURE                  = &H06
%NO_LISTENERS                                = &H07
%CHANNEL_ALREADY_CLOSED                      = &H08
%CHANNEL_ALREADY_OPENED                      = &H09
%CHANNEL_WAITING_FOR_CLIENT_NOTIFICATION     = &H0a
%CHANNEL_NOT_OPENED                          = &H0b
%ASYNC_CALL_ALREADY_PARKED                   = &H0c
%NOT_REGISTERED                              = &H0d
%ALREADY_UNREGISTERED                        = &H0e
%ALREADY_REGISTERED                          = &H0f
%CHANNEL_ACQUIRED                            = &H10
%ASYNC_CALL_IN_PROGRESS                      = &H11
%MAX_NOTIFICATION_SIZE_EXCEEDED              = &H12
%INTERNAL_NOTIFICATION_QUEUE_IS_FULL         = &H13
%INVALID_NOTIFICATION_TYPE                   = &H14
%MAX_REGISTRATION_COUNT_EXCEEDED             = &H15
%MAX_CHANNEL_COUNT_EXCEEDED                  = &H16
%LOCAL_ONLY_REGISTRATION                     = &H17
%REMOTE_ONLY_REGISTRATION                    = &H18

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
