' ########################################################################################
' Microsoft Windows
' File: rdpencomapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: RDPCOMAPILib
' Version: 1.0, Locale ID = 0
' Description: rdpcomapi 1.0 Type Library
' Path: C:\Windows\system32\rdpencom.dll
' Library GUID: {CC802D05-AE07-4C15-B496-DB9D22AA0A84}
' ########################################################################################

#INCLUDE THIS ONCE
%RDPENCOMAPI_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' CLSID = {9B78F0E6-3E05-4A5B-B2E8-E743A8956B65}
$PROGID_RDPSession1 = "Rdpcomapi.RDPSession.1"
$PROGID_RDPSession = "Rdpcomapi.RDPSession"
' CLSID = {32BE5ED2-5C86-480F-A914-0FF8885A1B3F}
$PROGID_RDPViewer1 = "Rdpvcomapi.RDPViewer.1"
$PROGID_RDPViewer = "Rdpvcomapi.RDPViewer"

$LIBID_RDPCOMAPILib = GUID$("{CC802D05-AE07-4C15-B496-DB9D22AA0A84}")

$CLSID_RDPSRAPIApplication = GUID$("{C116A484-4B25-4B9F-8A54-B934B06E57FA}")
$CLSID_RDPSRAPIApplicationFilter = GUID$("{E35ACE89-C7E8-427E-A4F9-B9DA072826BD}")
$CLSID_RDPSRAPIApplicationList = GUID$("{9E31C815-7433-4876-97FB-ED59FE2BAA22}")
$CLSID_RDPSRAPIAttendee = GUID$("{74F93BB5-755F-488E-8A29-2390108AEF55}")
$CLSID_RDPSRAPIAttendeeDisconnectInfo = GUID$("{B47D7250-5BDB-405D-B487-CAAD9C56F4F8}")
$CLSID_RDPSRAPIAttendeeManager = GUID$("{D7B13A01-F7D4-42A6-8595-12FC8C24E851}")
$CLSID_RDPSRAPIInvitation = GUID$("{49174DC6-0731-4B5E-8EE1-83A63D3868FA}")
$CLSID_RDPSRAPIInvitationManager = GUID$("{53D9C9DB-75AB-4271-948A-4C4EB36A8F2B}")
$CLSID_RDPSRAPISessionProperties = GUID$("{DD7594FF-EA2A-4C06-8FDF-132DE48B6510}")
$CLSID_RDPSRAPITcpConnectionInfo = GUID$("{BE49DB3F-EBB6-4278-8CE0-D5455833EAEE}")
$CLSID_RDPSRAPIWindow = GUID$("{03CF46DB-CE45-4D36-86ED-ED28B74398BF}")
$CLSID_RDPSRAPIWindowList = GUID$("{9C21E2B8-5DD4-42CC-81BA-1C099852E6FA}")
$CLSID_RDPSession = GUID$("{9B78F0E6-3E05-4A5B-B2E8-E743A8956B65}")
$CLSID_RDPViewer = GUID$("{32BE5ED2-5C86-480F-A914-0FF8885A1B3F}")

%DISPID_RDPSRAPI_METHOD_OPEN                              = 100
%DISPID_RDPSRAPI_METHOD_CLOSE                             = 101
%DISPID_RDPSRAPI_METHOD_SETSHAREDRECT                     = 102
%DISPID_RDPSRAPI_METHOD_GETSHAREDRECT                     = 103
%DISPID_RDPSRAPI_METHOD_VIEWERCONNECT                     = 104
%DISPID_RDPSRAPI_METHOD_VIEWERDISCONNECT                  = 105
%DISPID_RDPSRAPI_METHOD_TERMINATE_CONNECTION              = 106
%DISPID_RDPSRAPI_METHOD_CREATE_INVITATION                 = 107
%DISPID_RDPSRAPI_METHOD_REQUEST_CONTROL                   = 108
%DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_CREATE            = 109
%DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_SEND_DATA         = 110
%DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_SET_ACCESS        = 111
%DISPID_RDPSRAPI_METHOD_PAUSE                             = 112
%DISPID_RDPSRAPI_METHOD_RESUME                            = 113
%DISPID_RDPSRAPI_METHOD_SHOW_WINDOW                       = 114
%DISPID_RDPSRAPI_METHOD_REQUEST_COLOR_DEPTH_CHANGE        = 115
%DISPID_RDPSRAPI_METHOD_STARTREVCONNECTLISTENER           = 116
%DISPID_RDPSRAPI_METHOD_CONNECTTOCLIENT                   = 117
%DISPID_RDPSRAPI_PROP_DISPIDVALUE                         = 200
%DISPID_RDPSRAPI_PROP_ID                                  = 201
%DISPID_RDPSRAPI_PROP_SESSION_PROPERTIES                  = 202
%DISPID_RDPSRAPI_PROP_ATTENDEES                           = 203
%DISPID_RDPSRAPI_PROP_INVITATIONS                         = 204
%DISPID_RDPSRAPI_PROP_INVITATION                          = 205
%DISPID_RDPSRAPI_PROP_CHANNELMANAGER                      = 206
%DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETNAME             = 207
%DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETFLAGS            = 208
%DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETPRIORITY         = 209
%DISPID_RDPSRAPI_PROP_WINDOWID                            = 210
%DISPID_RDPSRAPI_PROP_APPLICATION                         = 211
%DISPID_RDPSRAPI_PROP_WINDOWSHARED                        = 212
%DISPID_RDPSRAPI_PROP_WINDOWNAME                          = 213
%DISPID_RDPSRAPI_PROP_APPNAME                             = 214
%DISPID_RDPSRAPI_PROP_APPLICATION_FILTER                  = 215
%DISPID_RDPSRAPI_PROP_WINDOW_LIST                         = 216
%DISPID_RDPSRAPI_PROP_APPLICATION_LIST                    = 217
%DISPID_RDPSRAPI_PROP_APPFILTER_ENABLED                   = 218
%DISPID_RDPSRAPI_PROP_APPFILTERENABLED                    = 219
%DISPID_RDPSRAPI_PROP_SHARED                              = 220
%DISPID_RDPSRAPI_PROP_INVITATIONITEM                      = 221
%DISPID_RDPSRAPI_PROP_DBG_CLX_CMDLINE                     = 222
%DISPID_RDPSRAPI_PROP_APPFLAGS                            = 223
%DISPID_RDPSRAPI_PROP_WNDFLAGS                            = 224
%DISPID_RDPSRAPI_PROP_PROTOCOL_TYPE                       = 225
%DISPID_RDPSRAPI_PROP_LOCAL_PORT                          = 226
%DISPID_RDPSRAPI_PROP_LOCAL_IP                            = 227
%DISPID_RDPSRAPI_PROP_PEER_PORT                           = 228
%DISPID_RDPSRAPI_PROP_PEER_IP                             = 229
%DISPID_RDPSRAPI_PROP_ATTENDEE_FLAGS                      = 230
%DISPID_RDPSRAPI_PROP_CONINFO                             = 231
%DISPID_RDPSRAPI_PROP_CONNECTION_STRING                   = 232
%DISPID_RDPSRAPI_PROP_GROUP_NAME                          = 233
%DISPID_RDPSRAPI_PROP_PASSWORD                            = 234
%DISPID_RDPSRAPI_PROP_ATTENDEELIMIT                       = 235
%DISPID_RDPSRAPI_PROP_REVOKED                             = 236
%DISPID_RDPSRAPI_PROP_DISCONNECTED_STRING                 = 237
%DISPID_RDPSRAPI_PROP_USESMARTSIZING                      = 238
%DISPID_RDPSRAPI_PROP_SESSION_COLORDEPTH                  = 239
%DISPID_RDPSRAPI_PROP_REASON                              = 240
%DISPID_RDPSRAPI_PROP_CODE                                = 241
%DISPID_RDPSRAPI_PROP_CTRL_LEVEL                          = 242
%DISPID_RDPSRAPI_PROP_REMOTENAME                          = 243
%DISPID_RDPSRAPI_PROP_COUNT                               = 244
%DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_CONNECTED              = 301
%DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_DISCONNECTED           = 302
%DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_UPDATE                 = 303
%DISPID_RDPSRAPI_EVENT_ON_ERROR                           = 304
%DISPID_RDPSRAPI_EVENT_ON_VIEWER_CONNECTED                = 305
%DISPID_RDPSRAPI_EVENT_ON_VIEWER_DISCONNECTED             = 306
%DISPID_RDPSRAPI_EVENT_ON_VIEWER_AUTHENTICATED            = 307
%DISPID_RDPSRAPI_EVENT_ON_VIEWER_CONNECTFAILED            = 308
%DISPID_RDPSRAPI_EVENT_ON_CTRLLEVEL_CHANGE_REQUEST        = 309
%DISPID_RDPSRAPI_EVENT_ON_GRAPHICS_STREAM_PAUSED          = 310
%DISPID_RDPSRAPI_EVENT_ON_GRAPHICS_STREAM_RESUMED         = 311
%DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_JOIN            = 312
%DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_LEAVE           = 313
%DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_DATARECEIVED    = 314
%DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_SENDCOMPLETED   = 315
%DISPID_RDPSRAPI_EVENT_ON_APPLICATION_OPEN                = 316
%DISPID_RDPSRAPI_EVENT_ON_APPLICATION_CLOSE               = 317
%DISPID_RDPSRAPI_EVENT_ON_APPLICATION_UPDATE              = 318
%DISPID_RDPSRAPI_EVENT_ON_WINDOW_OPEN                     = 319
%DISPID_RDPSRAPI_EVENT_ON_WINDOW_CLOSE                    = 320
%DISPID_RDPSRAPI_EVENT_ON_WINDOW_UPDATE                   = 321
%DISPID_RDPSRAPI_EVENT_ON_APPFILTER_UPDATE                = 322
%DISPID_RDPSRAPI_EVENT_ON_SHARED_RECT_CHANGED             = 323
%DISPID_RDPSRAPI_EVENT_ON_FOCUSRELEASED                   = 324
%DISPID_RDPSRAPI_EVENT_ON_SHARED_DESKTOP_SETTINGS_CHANGED = 325

' ########################################################################################
' Interface name = IRDPSRAPIDebug
' IID = AA1E42B5-496D-4CA4-A690-348DCB2EC4AD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIDebug_INTERFACE_DEFINED)
    %IRDPSRAPIDebug_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIDebug = GUID$("{AA1E42B5-496D-4CA4-A690-348DCB2EC4AD}")

INTERFACE IRDPSRAPIDebug $IID_IRDPSRAPIDebug

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY SET CLXCmdLine ( _                          ' VTable offset = 12
     BYVAL CLXCmdLine AS WSTRING _                      ' __in BSTR CLXCmdLine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLXCmdLine ( _                          ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pCLXCmdLine
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIDebug_INTERFACE_DEFINED__ */

' enum CTRL_LEVEL
%CTRL_LEVEL_MIN         = 0
%CTRL_LEVEL_INVALID     = 0
%CTRL_LEVEL_NONE        = 1
%CTRL_LEVEL_VIEW        = 2
%CTRL_LEVEL_INTERACTIVE = 3
%CTRL_LEVEL_MAX         = 3

' enum ATTENDEE_DISCONNECT_REASON
%ATTENDEE_DISCONNECT_REASON_MIN = 0
%ATTENDEE_DISCONNECT_REASON_APP = 0
%ATTENDEE_DISCONNECT_REASON_ERR = 1
%ATTENDEE_DISCONNECT_REASON_CLI = 2
%ATTENDEE_DISCONNECT_REASON_MAX = 2

' enum CHANNEL_PRIORITY
%CHANNEL_PRIORITY_LO  = 0
%CHANNEL_PRIORITY_MED = %CHANNEL_PRIORITY_LO + 1
%CHANNEL_PRIORITY_HI  = %CHANNEL_PRIORITY_MED + 1

' enum CHANNEL_FLAGS
%CHANNEL_FLAGS_LEGACY       = &H1
%CHANNEL_FLAGS_UNCOMPRESSED = &H2

' enum CHANNEL_ACCESS_ENUM
%CHANNEL_ACCESS_ENUM_NONE        = 0
%CHANNEL_ACCESS_ENUM_SENDRECEIVE = %CHANNEL_ACCESS_ENUM_NONE + 1

' enum RDPENCOMAPI_CONSTANTS
%CONST_MAX_CHANNEL_MESSAGE_SIZE        = 1024
%CONST_MAX_CHANNEL_NAME_LEN            = 8
%CONST_MAX_LEGACY_CHANNEL_MESSAGE_SIZE = 409600
%CONST_ATTENDEE_ID_EVERYONE            = -1
%CONST_ATTENDEE_ID_HOST                = 0
%CONST_CONN_INTERVAL                   = 50

' enum RDPENCOMAPI_ATTENDEE_FLAGS
%ATTENDEE_FLAGS_LOCAL = 1

' enum RDPSRAPI_WND_FLAGS
%WND_FLAG_PRIVILEGED = 1

' enum RDPSRAPI_APP_FLAGS
%APP_FLAG_PRIVILEGED = 1

' ########################################################################################
' Interface name = _IRDPSessionEvents
' IID = 98A97042-6698-40E9-8EFD-B3200990004B
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSessionEvents_DISPINTERFACE_DEFINED)
    %IRDPSessionEvents_DISPINTERFACE_DEFINED = 1

$IID__IRDPSessionEvents = GUID$("{98A97042-6698-40E9-8EFD-B3200990004B}")

'INTERFACE IRDPSessionEvents $IID__IRDPSessionEvents

'   INHERIT IDispatch

'END INTERFACE

#ENDIF   ' /* __IRDPSessionEvents_DISPINTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIApplication
' IID = {41E7A09D-EB7A-436E-935D-780CA2628324}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIApplication_INTERFACE_DEFINED)
    %IRDPSRAPIApplication_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIApplication = GUID$("{41E7A09D-EB7A-436E-935D-780CA2628324}")

INTERFACE IRDPSRAPIApplication $IID_IRDPSRAPIApplication

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Windows <0> ( _                         ' VTable offset = 28
   ) AS IRDPSRAPIWindowList                             ' __retval_out IRDPSRAPIWindowList **pWindowList
   ' =====================================================================================
   PROPERTY GET Id <201> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pRetVal
   ' =====================================================================================
   PROPERTY GET Shared <220> ( _                        ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY SET Shared <220> ( _                        ' VTable offset = 40
     BYVAL pRetVal AS INTEGER _                         ' __in VARIANT_BOOL pRetVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <214> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   PROPERTY GET Flags <223> ( _                         ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out unsigned long *pdwFlags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIApplication_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIWindow
' IID = {BEAFE0F9-C77B-4933-BA9F-A24CDDCC27CF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIWindow_INTERFACE_DEFINED)
    %IRDPSRAPIWindow_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIWindow = GUID$("{BEAFE0F9-C77B-4933-BA9F-A24CDDCC27CF}")

INTERFACE IRDPSRAPIWindow $IID_IRDPSRAPIWindow

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <201> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pRetVal
   ' =====================================================================================
   PROPERTY GET Application <211> ( _                   ' VTable offset = 32
   ) AS IRDPSRAPIApplication                            ' __retval_out IRDPSRAPIApplication **pApplication
   ' =====================================================================================
   PROPERTY GET Shared <220> ( _                        ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pRetVal
   ' =====================================================================================
   PROPERTY SET Shared <220> ( _                        ' VTable offset = 40
     BYVAL pRetVal AS INTEGER _                         ' __in VARIANT_BOOL pRetVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <213> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pRetVal
   ' =====================================================================================
   METHOD Show <114> ( _                                ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <224> ( _                         ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out unsigned long *pdwFlags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIWindow_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIWindowList
' IID = {8A05CE44-715A-4116-A189-A118F30A07BD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIWindowList_INTERFACE_DEFINED)
    %IRDPSRAPIWindowList_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIWindowList = GUID$("{8A05CE44-715A-4116-A189-A118F30A07BD}")

INTERFACE IRDPSRAPIWindowList $IID_IRDPSRAPIWindowList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS IRDPSRAPIWindow                                 ' __retval_out IRDPSRAPIWindow **pWindow
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIWindowList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIApplicationList
' IID = {D4B4AEB3-22DC-4837-B3B6-42EA2517849A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIApplicationList_INTERFACE_DEFINED)
    %IRDPSRAPIApplicationList_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIApplicationList = GUID$("{D4B4AEB3-22DC-4837-B3B6-42EA2517849A}")

INTERFACE IRDPSRAPIApplicationList $IID_IRDPSRAPIApplicationList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Item AS LONG _                               ' __in long Item
   ) AS IRDPSRAPIApplication                            ' __retval_out IRDPSRAPIApplication **pApplication
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIApplicationList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIApplicationFilter
' IID = {D20F10CA-6637-4F06-B1D5-277EA7E5160D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIApplicationFilter_INTERFACE_DEFINED)
    %IRDPSRAPIApplicationFilter_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIApplicationFilter = GUID$("{D20F10CA-6637-4F06-B1D5-277EA7E5160D}")

INTERFACE IRDPSRAPIApplicationFilter $IID_IRDPSRAPIApplicationFilter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Applications <217> ( _                  ' VTable offset = 28
   ) AS IRDPSRAPIApplicationList                        ' __retval_out IRDPSRAPIApplicationList **pApplications
   ' =====================================================================================
   PROPERTY GET Windows <216> ( _                       ' VTable offset = 32
   ) AS IRDPSRAPIWindowList                             ' __retval_out IRDPSRAPIWindowList **pWindows
   ' =====================================================================================
   PROPERTY GET Enabled <219> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY SET Enabled <219> ( _                       ' VTable offset = 40
     BYVAL pRetVal AS INTEGER _                         ' __in VARIANT_BOOL pRetVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIApplicationFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPISessionProperties
' IID = {339B24F2-9BC0-4F16-9AAC-F165433D13D4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPISessionProperties_INTERFACE_DEFINED)
    %IRDPSRAPISessionProperties_INTERFACE_DEFINED = 1

$IID_IRDPSRAPISessionProperties = GUID$("{339B24F2-9BC0-4F16-9AAC-F165433D13D4}")

INTERFACE IRDPSRAPISessionProperties $IID_IRDPSRAPISessionProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Property <0> ( _                        ' VTable offset = 28
     BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET Property <0> ( _                        ' VTable offset = 32
     BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL pVal AS VARIANT _                            ' __in VARIANT pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPISessionProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIInvitation
' IID = {4FAC1D43-FC51-45BB-B1B4-2B53AA562FA3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIInvitation_INTERFACE_DEFINED)
    %IRDPSRAPIInvitation_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIInvitation = GUID$("{4FAC1D43-FC51-45BB-B1B4-2B53AA562FA3}")

INTERFACE IRDPSRAPIInvitation $IID_IRDPSRAPIInvitation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConnectionString <232> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVal
   ' =====================================================================================
   PROPERTY GET GroupName <233> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVal
   ' =====================================================================================
   PROPERTY GET Password <234> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrVal
   ' =====================================================================================
   PROPERTY GET AttendeeLimit <235> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pRetVal
   ' =====================================================================================
   PROPERTY SET AttendeeLimit <235> ( _                 ' VTable offset = 44
     BYVAL pRetVal AS LONG _                            ' __in long pRetVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Revoked <236> ( _                       ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pRetVal
   ' =====================================================================================
   PROPERTY SET Revoked <236> ( _                       ' VTable offset = 52
     BYVAL pRetVal AS INTEGER _                         ' __in VARIANT_BOOL pRetVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIInvitation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIInvitationManager
' IID = {4722B049-92C3-4C2D-8A65-F7348F644DCF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIInvitationManager_INTERFACE_DEFINED)
    %IRDPSRAPIInvitationManager_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIInvitationManager = GUID$("{4722B049-92C3-4C2D-8A65-F7348F644DCF}")

INTERFACE IRDPSRAPIInvitationManager $IID_IRDPSRAPIInvitationManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS IRDPSRAPIInvitation                             ' __retval_out IRDPSRAPIInvitation **ppInvitation
   ' =====================================================================================
   PROPERTY GET Count <244> ( _                         ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* pRetVal
   ' =====================================================================================
   METHOD CreateInvitation <107> ( _                    ' VTable offset = 40
     BYVAL bstrAuthString AS WSTRING _                  ' __in BSTR bstrAuthString
   , BYVAL bstrGroupName AS WSTRING _                   ' __in BSTR bstrGroupName
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   , BYVAL AttendeeLimit AS LONG _                      ' __in long AttendeeLimit
   ) AS IRDPSRAPIInvitation                             ' __retval_out IRDPSRAPIInvitation **ppInvitation
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIInvitationManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPITcpConnectionInfo
' IID = {F74049A4-3D06-4028-8193-0A8C29BC2452}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPITcpConnectionInfo_INTERFACE_DEFINED)
    %IRDPSRAPITcpConnectionInfo_INTERFACE_DEFINED = 1

$IID_IRDPSRAPITcpConnectionInfo = GUID$("{F74049A4-3D06-4028-8193-0A8C29BC2452}")

INTERFACE IRDPSRAPITcpConnectionInfo $IID_IRDPSRAPITcpConnectionInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Protocol <225> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plProtocol
   ' =====================================================================================
   PROPERTY GET LocalPort <226> ( _                     ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPort
   ' =====================================================================================
   PROPERTY GET LocalIP <227> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbsrLocalIP
   ' =====================================================================================
   PROPERTY GET PeerPort <228> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plPort
   ' =====================================================================================
   PROPERTY GET PeerIP <229> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIP
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPITcpConnectionInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIAttendee
' IID = {EC0671B3-1B78-4B80-A464-9132247543E3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIAttendee_INTERFACE_DEFINED)
    %IRDPSRAPIAttendee_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIAttendee = GUID$("{EC0671B3-1B78-4B80-A464-9132247543E3}")

INTERFACE IRDPSRAPIAttendee $IID_IRDPSRAPIAttendee

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <201> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pId
   ' =====================================================================================
   PROPERTY GET RemoteName <243> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ControlLevel <242> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out CTRL_LEVEL *pVal
   ' =====================================================================================
   PROPERTY SET ControlLevel <242> ( _                  ' VTable offset = 40
     BYVAL pVal AS LONG _                               ' __in CTRL_LEVEL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Invitation <205> ( _                    ' VTable offset = 44
   ) AS IRDPSRAPIInvitation                             ' __retval_out IRDPSRAPIInvitation **ppVal
   ' =====================================================================================
   METHOD TerminateConnection <106> ( _                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <230> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* plFlags
   ' =====================================================================================
   PROPERTY GET ConnectivityInfo <231> ( _              ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **ppVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIAttendee_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIAttendeeManager
' IID = {BA3A37E8-33DA-4749-8DA0-07FA34DA7944}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIAttendeeManager_INTERFACE_DEFINED)
    %IRDPSRAPIAttendeeManager_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIAttendeeManager = GUID$("{BA3A37E8-33DA-4749-8DA0-07FA34DA7944}")

INTERFACE IRDPSRAPIAttendeeManager $IID_IRDPSRAPIAttendeeManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Id AS LONG _                                 ' __in long Id
   ) AS IRDPSRAPIAttendee                               ' __retval_out IRDPSRAPIAttendee **ppItem
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIAttendeeManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIAttendeeDisconnectInfo
' IID = {C187689F-447C-44A1-9C14-FFFBB3B7EC17}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIAttendeeDisconnectInfo_INTERFACE_DEFINED)
    %IRDPSRAPIAttendeeDisconnectInfo_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIAttendeeDisconnectInfo = GUID$("{C187689F-447C-44A1-9C14-FFFBB3B7EC17}")

INTERFACE IRDPSRAPIAttendeeDisconnectInfo $IID_IRDPSRAPIAttendeeDisconnectInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Attendee <0> ( _                        ' VTable offset = 28
   ) AS IRDPSRAPIAttendee                               ' __retval_out IRDPSRAPIAttendee **retval
   ' =====================================================================================
   PROPERTY GET Reason <240> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ATTENDEE_DISCONNECT_REASON *pReason
   ' =====================================================================================
   PROPERTY GET Code <241> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIAttendeeDisconnectInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIVirtualChannel
' IID = {05E12F95-28B3-4C9A-8780-D0248574A1E0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIVirtualChannel_INTERFACE_DEFINED)
    %IRDPSRAPIVirtualChannel_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIVirtualChannel = GUID$("{05E12F95-28B3-4C9A-8780-D0248574A1E0}")

INTERFACE IRDPSRAPIVirtualChannel $IID_IRDPSRAPIVirtualChannel

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SendData <110> ( _                            ' VTable offset = 28
     BYVAL bstrData AS WSTRING _                        ' __in BSTR bstrData
   , BYVAL lAttendeeId AS LONG _                        ' __in long lAttendeeId
   , BYVAL ChannelSendFlags AS DWORD _                  ' __in unsigned long ChannelSendFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAccess <111> ( _                           ' VTable offset = 32
     BYVAL lAttendeeId AS LONG _                        ' __in long lAttendeeId
   , BYVAL AccessType AS LONG _                         ' __in CHANNEL_ACCESS_ENUM AccessType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <207> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Flags <208> ( _                         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* plFlags
   ' =====================================================================================
   PROPERTY GET Priority <209> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out CHANNEL_PRIORITY *pPriority
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIVirtualChannel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIVirtualChannelManager
' IID = {0D11C661-5D0D-4EE4-89DF-2166AE1FDFED}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIVirtualChannelManager_INTERFACE_DEFINED)
    %IRDPSRAPIVirtualChannelManager_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIVirtualChannelManager = GUID$("{0D11C661-5D0D-4EE4-89DF-2166AE1FDFED}")

INTERFACE IRDPSRAPIVirtualChannelManager $IID_IRDPSRAPIVirtualChannelManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS IRDPSRAPIVirtualChannel                         ' __retval_out IRDPSRAPIVirtualChannel **pChannel
   ' =====================================================================================
   METHOD CreateVirtualChannel <109> ( _                ' VTable offset = 36
     BYVAL bstrChannelName AS WSTRING _                 ' __in BSTR bstrChannelName
   , BYVAL Priority AS LONG _                           ' __in CHANNEL_PRIORITY Priority
   , BYVAL ChannelFlags AS DWORD _                      ' __in unsigned long ChannelFlags
   ) AS IRDPSRAPIVirtualChannel                         ' __retval_out IRDPSRAPIVirtualChannel **ppChannel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIVirtualChannelManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPISharingSession
' IID = {EEB20886-E470-4CF6-842B-2739C0EC5CFB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPISharingSession_INTERFACE_DEFINED)
    %IRDPSRAPISharingSession_INTERFACE_DEFINED = 1

$IID_IRDPSRAPISharingSession = GUID$("{EEB20886-E470-4CF6-842B-2739C0EC5CFB}")

INTERFACE IRDPSRAPISharingSession $IID_IRDPSRAPISharingSession

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Open <100> ( _                                ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <101> ( _                               ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET colordepth <239> ( _                    ' VTable offset = 36
     BYVAL pColorDepth AS LONG _                        ' __in long pColorDepth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET colordepth <239> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pColorDepth
   ' =====================================================================================
   PROPERTY GET Properties <202> ( _                    ' VTable offset = 44
   ) AS IRDPSRAPISessionProperties                      ' __retval_out IRDPSRAPISessionProperties **ppVal
   ' =====================================================================================
   PROPERTY GET Attendees <203> ( _                     ' VTable offset = 48
   ) AS IRDPSRAPIAttendeeManager                        ' __retval_out IRDPSRAPIAttendeeManager **ppVal
   ' =====================================================================================
   PROPERTY GET Invitations <204> ( _                   ' VTable offset = 52
   ) AS IRDPSRAPIInvitationManager                      ' __retval_out IRDPSRAPIInvitationManager **ppVal
   ' =====================================================================================
   PROPERTY GET ApplicationFilter <215> ( _             ' VTable offset = 56
   ) AS IRDPSRAPIApplicationFilter                      ' __retval_out IRDPSRAPIApplicationFilter **ppVal
   ' =====================================================================================
   PROPERTY GET VirtualChannelManager <206> ( _         ' VTable offset = 60
   ) AS IRDPSRAPIVirtualChannelManager                  ' __retval_out IRDPSRAPIVirtualChannelManager **ppVal
   ' =====================================================================================
   METHOD Pause <112> ( _                               ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <113> ( _                              ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectToClient <117> ( _                     ' VTable offset = 72
     BYVAL bstrConnectionString AS WSTRING _            ' __in BSTR bstrConnectionString
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDesktopSharedRect <102> ( _                ' VTable offset = 76
     BYVAL left AS LONG _                               ' __in long left
   , BYVAL top AS LONG _                                ' __in long top
   , BYVAL right AS LONG _                              ' __in long right
   , BYVAL bottom AS LONG _                             ' __in long bottom
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesktopSharedRect <103> ( _                ' VTable offset = 80
     BYREF pleft AS LONG _                              ' __out long *pleft
   , BYREF ptop AS LONG _                               ' __out long *ptop
   , BYREF pright AS LONG _                             ' __out long *pright
   , BYREF pbottom AS LONG _                            ' __out long *pbottom
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPISharingSession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRDPSRAPIViewer
' IID = {C6BFCD38-8CE9-404D-8AE8-F31D00C65CB5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRDPSRAPIViewer_INTERFACE_DEFINED)
    %IRDPSRAPIViewer_INTERFACE_DEFINED = 1

$IID_IRDPSRAPIViewer = GUID$("{C6BFCD38-8CE9-404D-8AE8-F31D00C65CB5}")

INTERFACE IRDPSRAPIViewer $IID_IRDPSRAPIViewer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Connect <104> ( _                             ' VTable offset = 28
     BYVAL bstrConnectionString AS WSTRING _            ' __in BSTR bstrConnectionString
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <105> ( _                          ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attendees <203> ( _                     ' VTable offset = 36
   ) AS IRDPSRAPIAttendeeManager                        ' __retval_out IRDPSRAPIAttendeeManager **ppVal
   ' =====================================================================================
   PROPERTY GET Invitations <204> ( _                   ' VTable offset = 40
   ) AS IRDPSRAPIInvitationManager                      ' __retval_out IRDPSRAPIInvitationManager **ppVal
   ' =====================================================================================
   PROPERTY GET ApplicationFilter <215> ( _             ' VTable offset = 44
   ) AS IRDPSRAPIApplicationFilter                      ' __retval_out IRDPSRAPIApplicationFilter **ppVal
   ' =====================================================================================
   PROPERTY GET VirtualChannelManager <206> ( _         ' VTable offset = 48
   ) AS IRDPSRAPIVirtualChannelManager                  ' __retval_out IRDPSRAPIVirtualChannelManager **ppVal
   ' =====================================================================================
   PROPERTY SET SmartSizing <238> ( _                   ' VTable offset = 52
     BYVAL pvbSmartSizing AS INTEGER _                  ' __in VARIANT_BOOL pvbSmartSizing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SmartSizing <238> ( _                   ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvbSmartSizing
   ' =====================================================================================
   METHOD RequestControl <108> ( _                      ' VTable offset = 60
     BYVAL CtrlLevel AS LONG _                          ' __in CTRL_LEVEL CtrlLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DisconnectedText <237> ( _              ' VTable offset = 64
     BYVAL pbstrDisconnectedText AS WSTRING _           ' __in BSTR pbstrDisconnectedText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisconnectedText <237> ( _              ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDisconnectedText
   ' =====================================================================================
   METHOD RequestColorDepthChange <115> ( _             ' VTable offset = 72
     BYVAL Bpp AS LONG _                                ' __in long Bpp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <202> ( _                    ' VTable offset = 76
   ) AS IRDPSRAPISessionProperties                      ' __retval_out IRDPSRAPISessionProperties **ppVal
   ' =====================================================================================
   METHOD StartReverseConnectListener <116> ( _         ' VTable offset = 80
     BYVAL bstrConnectionString AS WSTRING _            ' __in BSTR bstrConnectionString
   , BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrReverseConnectString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRDPSRAPIViewer_INTERFACE_DEFINED__ */
