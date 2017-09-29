' ########################################################################################
' Microsoft Windows
' File: taskschd.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TaskScheduler
' Version: 1.0, Locale ID = 0
' Description: TaskScheduler 1.1 Type Library
' Path: C:\Windows\SysWOW64\taskschd.dll
' Library GUID: {E34CB9F1-C7F7-424C-BE29-027DCC09363A}
' ########################################################################################

#INCLUDE THIS ONCE
%TASKSCHD_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_TaskScheduler = GUID$("{E34CB9F1-C7F7-424C-BE29-027DCC09363A}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0F87369F-A4E5-4CFC-BD3E-73E6154572DD}
$PROGID_TaskScheduler1 = "Schedule.Service.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {0F87369F-A4E5-4CFC-BD3E-73E6154572DD}
$PROGID_TaskScheduler = "Schedule.Service"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_TaskHandlerPS            = GUID$("{F2A69DB7-DA2C-4352-9066-86FEE6DACAC9}")
$CLSID_TaskHandlerStatusPS      = GUID$("{9F15266D-D7BA-48F0-93C1-E6895F6FE5AC}")
$CLSID_TaskScheduler            = GUID$("{0F87369F-A4E5-4CFC-BD3E-73E6154572DD}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAction                    = GUID$("{BAE54997-48B1-4CBE-9965-D6BE263EBEA4}")
$IID_IActionCollection          = GUID$("{02820E19-7B98-4ED2-B2E8-FDCCCEFF619B}")
$IID_IBootTrigger               = GUID$("{2A9C35DA-D357-41F4-BBC1-207AC1B1F3CB}")
$IID_IComHandlerAction          = GUID$("{6D2FD252-75C5-4F66-90BA-2A7D8CC3039F}")
$IID_IDailyTrigger              = GUID$("{126C5CD8-B288-41D5-8DBF-E491446ADC5C}")
$IID_IEmailAction               = GUID$("{10F62C64-7E16-4314-A0C2-0C3683F99D40}")
$IID_IEventTrigger              = GUID$("{D45B0167-9653-4EEF-B94F-0732CA7AF251}")
$IID_IExecAction                = GUID$("{4C3D624D-FD6B-49A3-B9B7-09CB3CD3F047}")
$IID_IIdleSettings              = GUID$("{84594461-0053-4342-A8FD-088FABF11F32}")
$IID_IIdleTrigger               = GUID$("{D537D2B0-9FB3-4D34-9739-1FF5CE7B1EF3}")
$IID_ILogonTrigger              = GUID$("{72DADE38-FAE4-4B3E-BAF4-5D009AF02B1C}")
$IID_IMonthlyDOWTrigger         = GUID$("{77D025A3-90FA-43AA-B52E-CDA5499B946A}")
$IID_IMonthlyTrigger            = GUID$("{97C45EF1-6B02-4A1A-9C0E-1EBFBA1500AC}")
$IID_INetworkSettings           = GUID$("{9F7DEA84-C30B-4245-80B6-00E9F646F1B4}")
$IID_IPrincipal                 = GUID$("{D98D51E5-C9B4-496A-A9C1-18980261CF0F}")
$IID_IPrincipal2                = GUID$("{248919AE-E345-4A6D-8AEB-E0D3165C904E}")
$IID_IRegisteredTask            = GUID$("{9C86F320-DEE3-4DD1-B972-A303F26B061E}")
$IID_IRegisteredTaskCollection  = GUID$("{86627EB4-42A7-41E4-A4D9-AC33A72F2D52}")
$IID_IRegistrationInfo          = GUID$("{416D8B73-CB41-4EA1-805C-9BE9A5AC4A74}")
$IID_IRegistrationTrigger       = GUID$("{4C8FEC3A-C218-4E0C-B23D-629024DB91A2}")
$IID_IRepetitionPattern         = GUID$("{7FB9ACF1-26BE-400E-85B5-294B9C75DFD6}")
$IID_IRunningTask               = GUID$("{653758FB-7B9A-4F1E-A471-BEEB8E9B834E}")
$IID_IRunningTaskCollection     = GUID$("{6A67614B-6828-4FEC-AA54-6D52E8F1F2DB}")
$IID_ISessionStateChangeTrigger = GUID$("{754DA71B-4385-4475-9DD9-598294FA3641}")
$IID_IShowMessageAction         = GUID$("{505E9E68-AF89-46B8-A30F-56162A83D537}")
$IID_ITaskDefinition            = GUID$("{F5BC8FC5-536D-4F77-B852-FBC1356FDEB6}")
$IID_ITaskFolder                = GUID$("{8CFAC062-A080-4C15-9A88-AA7C2AF80DFC}")
$IID_ITaskFolderCollection      = GUID$("{79184A66-8664-423F-97F1-637356A5D812}")
$IID_ITaskHandler               = GUID$("{839D7762-5121-4009-9234-4F0D19394F04}")
$IID_ITaskHandlerStatus         = GUID$("{EAEC7A8F-27A0-4DDC-8675-14726A01A38A}")
$IID_ITaskNamedValueCollection  = GUID$("{B4EF826B-63C3-46E4-A504-EF69E4F7EA4D}")
$IID_ITaskNamedValuePair        = GUID$("{39038068-2B46-4AFD-8662-7BB6F868D221}")
$IID_ITaskService               = GUID$("{2FABA4C7-4DA9-4013-9697-20CC3FD40F85}")
$IID_ITaskSettings              = GUID$("{8FD4711D-2D02-4C8C-87E3-EFF699DE127E}")
$IID_ITaskSettings2             = GUID$("{2C05C3F0-6EED-4C05-A15F-ED7D7A98A369}")
$IID_ITaskVariables             = GUID$("{3E4C9351-D966-4B8B-BB87-CEBA68BB0107}")
$IID_ITimeTrigger               = GUID$("{B45747E0-EBA7-4276-9F29-85C5BB300006}")
$IID_ITrigger                   = GUID$("{09941815-EA89-4B5B-89E0-2A773801FAC3}")
$IID_ITriggerCollection         = GUID$("{85DF5081-1B24-4F32-878A-D9D14DF4CB77}")
$IID_IWeeklyTrigger             = GUID$("{5038FC98-82FF-436D-8728-A512A57C9DC1}")

' ========================================================================================
' TASK_RUN_FLAGS enum
' ========================================================================================

%TASK_RUN_NO_FLAGS                                      = 0
%TASK_RUN_AS_SELF                                       = &H1
%TASK_RUN_IGNORE_CONSTRAINTS                            = &H2
%TASK_RUN_USE_SESSION_ID                                = &H4
%TASK_RUN_USER_SID                                      = &H8

' ========================================================================================
' TASK_ENUM_FLAGS enum
' ========================================================================================

%TASK_ENUM_HIDDEN                                       = &H1

' ========================================================================================
' TASK_LOGON_TYPE enum
' ========================================================================================

%TASK_LOGON_NONE                                        = 0
%TASK_LOGON_PASSWORD                                    = 1
%TASK_LOGON_S4U                                         = 2
%TASK_LOGON_INTERACTIVE_TOKEN                           = 3
%TASK_LOGON_GROUP                                       = 4
%TASK_LOGON_SERVICE_ACCOUNT                             = 5
%TASK_LOGON_INTERACTIVE_TOKEN_OR_PASSWORD               = 6

' ========================================================================================
' TASK_RUNLEVEL enum
' ========================================================================================

%TASK_RUNLEVEL_LUA                                      = 0
%TASK_RUNLEVEL_HIGHEST                                  = 1

' ========================================================================================
' TASK_PROCESSTOKENSID_TYPE enum
' ========================================================================================

%TASK_PROCESSTOKENSID_NONE                              = 0
%TASK_PROCESSTOKENSID_UNRESTRICTED                      = 1
%TASK_PROCESSTOKENSID_DEFAULT                           = 2

' ========================================================================================
' TASK_STATE enum
' ========================================================================================

%TASK_STATE_UNKNOWN                                     = 0
%TASK_STATE_DISABLED                                    = 1
%TASK_STATE_QUEUED                                      = 2
%TASK_STATE_READY                                       = 3
%TASK_STATE_RUNNING                                     = 4

' ========================================================================================
' TASK_CREATION enum
' ========================================================================================

%TASK_VALIDATE_ONLY                                     = &H1
%TASK_CREATE                                            = &H2
%TASK_UPDATE                                            = &H4
%TASK_CREATE_OR_UPDATE                                  = %TASK_CREATE OR %TASK_UPDATE
%TASK_DISABLE                                           = &H8
%TASK_DONT_ADD_PRINCIPAL_ACE                            = &H10
%TASK_IGNORE_REGISTRATION_TRIGGERS                      = &H20

' ========================================================================================
' TASK_TRIGGER_TYPE2 enum
' ========================================================================================

%TASK_TRIGGER_EVENT                                     = 0
%TASK_TRIGGER_TIME                                      = 1
%TASK_TRIGGER_DAILY                                     = 2
%TASK_TRIGGER_WEEKLY                                    = 3
%TASK_TRIGGER_MONTHLY                                   = 4
%TASK_TRIGGER_MONTHLYDOW                                = 5
%TASK_TRIGGER_IDLE                                      = 6
%TASK_TRIGGER_REGISTRATION                              = 7
%TASK_TRIGGER_BOOT                                      = 8
%TASK_TRIGGER_LOGON                                     = 9
%TASK_TRIGGER_SESSION_STATE_CHANGE                      = 11

' ========================================================================================
' TASK_SESSION_STATE_CHANGE_TYPE enum
' ========================================================================================

%TASK_CONSOLE_CONNECT                                   = 1
%TASK_CONSOLE_DISCONNECT                                = 2
%TASK_REMOTE_CONNECT                                    = 3
%TASK_REMOTE_DISCONNECT                                 = 4
%TASK_SESSION_LOCK                                      = 7
%TASK_SESSION_UNLOCK                                    = 8

' ========================================================================================
' TASK_ACTION_TYPE enum
' ========================================================================================

%TASK_ACTION_EXEC                                       = 0
%TASK_ACTION_COM_HANDLER                                = 5
%TASK_ACTION_SEND_EMAIL                                 = 6
%TASK_ACTION_SHOW_MESSAGE                               = 7

' ========================================================================================
' TASK_INSTANCES_POLICY enum
' ========================================================================================

%TASK_INSTANCES_PARALLEL                                = 0
%TASK_INSTANCES_QUEUE                                   = 1
%TASK_INSTANCES_IGNORE_NEW                              = 2
%TASK_INSTANCES_STOP_EXISTING                           = 3

' ========================================================================================
' TASK_COMPATIBILITY enum
' ========================================================================================

%TASK_COMPATIBILITY_AT                                  = 0
%TASK_COMPATIBILITY_V1                                  = 1
%TASK_COMPATIBILITY_V2                                  = 2
%TASK_COMPATIBILITY_V2_1                                = 3

' ########################################################################################
' Interface name = ITaskFolderCollection
' IID = {79184A66-8664-423F-97F1-637356A5D812}
' Container for ITaskFolders
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskFolderCollection_INTERFACE_DEFINED)
    %ITaskFolderCollection_INTERFACE_DEFINED = 1

INTERFACE ITaskFolderCollection $IID_ITaskFolderCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS ITaskFolder                                     ' __retval_out ITaskFolder **ppFolder
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskFolderCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskService
' IID = {2FABA4C7-4DA9-4013-9697-20CC3FD40F85}
' Communicate with the Task Scheduler service
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskService_INTERFACE_DEFINED)
    %ITaskService_INTERFACE_DEFINED = 1

INTERFACE ITaskService $IID_ITaskService

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetFolder <1> ( _                             ' VTable offset = 28
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS ITaskFolder                                     ' __retval_out ITaskFolder** ppFolder
   ' =====================================================================================
   METHOD GetRunningTasks <2> ( _                       ' VTable offset = 32
     BYVAL flags AS LONG _                              ' __in LONG flags
   ) AS IRunningTaskCollection                          ' __retval_out IRunningTaskCollection** ppRunningTasks
   ' =====================================================================================
   METHOD NewTask <3> ( _                               ' VTable offset = 36
     BYVAL flags AS DWORD _                             ' __in DWORD flags
   ) AS ITaskDefinition                                 ' __retval_out ITaskDefinition** ppDefinition
   ' =====================================================================================
   METHOD Connect <4> ( _                               ' VTable offset = 40
     OPTIONAL BYVAL serverName AS VARIANT _             ' __opt_in VARIANT serverName
   , OPTIONAL BYVAL user AS VARIANT _                   ' __opt_in VARIANT user
   , OPTIONAL BYVAL domain AS VARIANT _                 ' __opt_in VARIANT domain
   , OPTIONAL BYVAL password AS VARIANT _               ' __opt_in VARIANT password
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Connected <5> ( _                       ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pConnected
   ' =====================================================================================
   PROPERTY GET TargetServer <0> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pServer
   ' =====================================================================================
   PROPERTY GET ConnectedUser <6> ( _                   ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pUser
   ' =====================================================================================
   PROPERTY GET ConnectedDomain <7> ( _                 ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pDomain
   ' =====================================================================================
   PROPERTY GET HighestVersion <8> ( _                  ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out DWORD* pVersion
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskHandler
' IID = {839D7762-5121-4009-9234-4F0D19394F04}
' an extension to the actions that a task can execute
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITaskHandler_INTERFACE_DEFINED)
    %ITaskHandler_INTERFACE_DEFINED = 1

INTERFACE ITaskHandler $IID_ITaskHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYVAL pHandlerServices AS IUnknown _               ' __in IUnknown* pHandlerServices
   , BYVAL Data AS WSTRING _                            ' __in BSTR Data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
     BYREF pRetCode AS LONG _                           ' __out HRESULT* pRetCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskHandlerStatus
' IID = {EAEC7A8F-27A0-4DDC-8675-14726A01A38A}
' Allow handler to send status information to task engine
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITaskHandlerStatus_INTERFACE_DEFINED)
    %ITaskHandlerStatus_INTERFACE_DEFINED = 1

INTERFACE ITaskHandlerStatus $IID_ITaskHandlerStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UpdateStatus ( _                              ' VTable offset = 12
     BYVAL percentComplete AS INTEGER _                 ' __in short percentComplete
   , BYVAL statusMessage AS WSTRING _                   ' __in BSTR statusMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TaskCompleted ( _                             ' VTable offset = 16
     BYVAL taskErrCode AS LONG _                        ' __in HRESULT taskErrCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskHandlerStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskVariables
' IID = {3E4C9351-D966-4B8B-BB87-CEBA68BB0107}
' Allows task handler to share information with task
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITaskVariables_INTERFACE_DEFINED)
    %ITaskVariables_INTERFACE_DEFINED = 1

INTERFACE ITaskVariables $IID_ITaskVariables

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInput ( _                                  ' VTable offset = 12
     BYREF pInput AS WSTRING _                          ' __retval_out BSTR* pInput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutput ( _                                 ' VTable offset = 16
     BYVAL input AS WSTRING _                           ' __in BSTR input
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 20
     BYREF pContext AS WSTRING _                        ' __retval_out BSTR* pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskVariables_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskNamedValuePair
' IID = {39038068-2B46-4AFD-8662-7BB6F868D221}
' Container for named strings
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskNamedValuePair_INTERFACE_DEFINED)
    %ITaskNamedValuePair_INTERFACE_DEFINED = 1

INTERFACE ITaskNamedValuePair $IID_ITaskNamedValuePair

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <1> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pValue
   ' =====================================================================================
   PROPERTY SET Value <1> ( _                           ' VTable offset = 40
     BYVAL pValue AS WSTRING _                          ' __in BSTR pValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskNamedValuePair_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskNamedValueCollection
' IID = {B4EF826B-63C3-46E4-A504-EF69E4F7EA4D}
' Group of ITaskNamedValuePairs
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskNamedValueCollection_INTERFACE_DEFINED)
    %ITaskNamedValueCollection_INTERFACE_DEFINED = 1

INTERFACE ITaskNamedValueCollection $IID_ITaskNamedValueCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in LONG index
   ) AS ITaskNamedValuePair                             ' __retval_out ITaskNamedValuePair** ppPair
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   METHOD Create <2> ( _                                ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   ) AS ITaskNamedValuePair                             ' __retval_out ITaskNamedValuePair** ppPair
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL index AS LONG _                              ' __in LONG index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <5> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskNamedValueCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRunningTask
' IID = {653758FB-7B9A-4F1E-A471-BEEB8E9B834E}
' A Task that is currently executing
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRunningTask_INTERFACE_DEFINED)
    %IRunningTask_INTERFACE_DEFINED = 1

INTERFACE IRunningTask $IID_IRunningTask

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY GET InstanceGuid <0> ( _                    ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pGuid
   ' =====================================================================================
   PROPERTY GET Path <2> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pPath
   ' =====================================================================================
   PROPERTY GET State <3> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out TASK_STATE* pState
   ' =====================================================================================
   PROPERTY GET CurrentAction <4> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   METHOD Stop <5> ( _                                  ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <6> ( _                               ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnginePID <7> ( _                       ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out DWORD* pPID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRunningTask_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRunningTaskCollection
' IID = {6A67614B-6828-4FEC-AA54-6D52E8F1F2DB}
' Group of tasks which are currently executing
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRunningTaskCollection_INTERFACE_DEFINED)
    %IRunningTaskCollection_INTERFACE_DEFINED = 1

INTERFACE IRunningTaskCollection $IID_IRunningTaskCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG* pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IRunningTask                                    ' __retval_out IRunningTask** ppRunningTask
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRunningTaskCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegisteredTask
' IID = {9C86F320-DEE3-4DD1-B972-A303F26B061E}
' A task that has been given to the Task Scheduler service
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegisteredTask_INTERFACE_DEFINED)
    %IRegisteredTask_INTERFACE_DEFINED = 1

INTERFACE IRegisteredTask $IID_IRegisteredTask

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pPath
   ' =====================================================================================
   PROPERTY GET State <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_STATE* pState
   ' =====================================================================================
   PROPERTY GET Enabled <3> ( _                         ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <3> ( _                         ' VTable offset = 44
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <5> ( _                                   ' VTable offset = 48
     BYVAL params AS VARIANT _                          ' __in VARIANT params
   ) AS IRunningTask                                    ' __retval_out IRunningTask** ppRunningTask
   ' =====================================================================================
   METHOD RunEx <6> ( _                                 ' VTable offset = 52
     BYVAL params AS VARIANT _                          ' __in VARIANT params
   , BYVAL flags AS LONG _                              ' __in LONG flags
   , BYVAL sessionID AS LONG _                          ' __in LONG sessionID
   , BYVAL user AS WSTRING _                            ' __in BSTR user
   ) AS IRunningTask                                    ' __retval_out IRunningTask** ppRunningTask
   ' =====================================================================================
   METHOD GetInstances <7> ( _                          ' VTable offset = 56
     BYVAL flags AS LONG _                              ' __in LONG flags
   ) AS IRunningTaskCollection                          ' __retval_out IRunningTaskCollection** ppRunningTasks
   ' =====================================================================================
   PROPERTY GET LastRunTime <8> ( _                     ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out DATE* pLastRunTime
   ' =====================================================================================
   PROPERTY GET LastTaskResult <9> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG* pLastTaskResult
   ' =====================================================================================
   PROPERTY GET NumberOfMissedRuns <11> ( _             ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LONG* pNumberOfMissedRuns
   ' =====================================================================================
   PROPERTY GET NextRunTime <12> ( _                    ' VTable offset = 72
   ) AS DOUBLE                                          ' __retval_out DATE* pNextRunTime
   ' =====================================================================================
   PROPERTY GET Definition <13> ( _                     ' VTable offset = 76
   ) AS ITaskDefinition                                 ' __retval_out ITaskDefinition** ppDefinition
   ' =====================================================================================
   PROPERTY GET Xml <14> ( _                            ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pXml
   ' =====================================================================================
   METHOD GetSecurityDescriptor <15> ( _                ' VTable offset = 84
     BYVAL securityInformation AS LONG _                ' __in LONG securityInformation
   ) AS WSTRING                                         ' __retval_out BSTR* pSddl
   ' =====================================================================================
   METHOD SetSecurityDescriptor <16> ( _                ' VTable offset = 88
     BYVAL sddl AS WSTRING _                            ' __in BSTR sddl
   , BYVAL flags AS LONG _                              ' __in LONG flags
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <17> ( _                                 ' VTable offset = 92
     BYVAL flags AS LONG _                              ' __in LONG flags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRunTimes <1610743825> ( _                  ' VTable offset = 96
     BYREF pstStart AS SYSTEMTIME _                     ' __in const LPSYSTEMTIME* pstStart
   , BYREF pstEnd AS SYSTEMTIME _                       ' __in const LPSYSTEMTIME* pstEnd
   , BYREF pCount AS DWORD _                            ' __in_out DWORD* pCount
   , BYREF pRunTimes AS SYSTEMTIME _                    ' __out LPSYSTEMTIME** pRunTimes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegisteredTask_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITrigger
' IID = {09941815-EA89-4B5B-89E0-2A773801FAC3}
' Specify when the task is started
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITrigger_INTERFACE_DEFINED)
    %ITrigger_INTERFACE_DEFINED = 1

INTERFACE ITrigger $IID_ITrigger

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIdleTrigger
' IID = {D537D2B0-9FB3-4D34-9739-1FF5CE7B1EF3}
' Run task when machine becomes idle
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IIdleTrigger_INTERFACE_DEFINED)
    %IIdleTrigger_INTERFACE_DEFINED = 1

INTERFACE IIdleTrigger $IID_IIdleTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdleTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILogonTrigger
' IID = {72DADE38-FAE4-4B3E-BAF4-5D009AF02B1C}
' Run task when user logs on
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%ILogonTrigger_INTERFACE_DEFINED)
    %ILogonTrigger_INTERFACE_DEFINED = 1

INTERFACE ILogonTrigger $IID_ILogonTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ILogonTrigger Methods
   ' =====================================================================================
   PROPERTY GET Delay <20> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET Delay <20> ( _                          ' VTable offset = 84
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserId <21> ( _                         ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pUser
   ' =====================================================================================
   PROPERTY SET UserId <21> ( _                         ' VTable offset = 92
     BYVAL pUser AS WSTRING _                           ' __in BSTR pUser
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ILogonTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISessionStateChangeTrigger
' IID = {754DA71B-4385-4475-9DD9-598294FA3641}
' Run task when login session state changes
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%ISessionStateChangeTrigger_INTERFACE_DEFINED)
    %ISessionStateChangeTrigger_INTERFACE_DEFINED = 1

INTERFACE ISessionStateChangeTrigger $IID_ISessionStateChangeTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISessionStateChangeTrigger Methods
   ' =====================================================================================
   PROPERTY GET Delay <20> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET Delay <20> ( _                          ' VTable offset = 84
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserId <21> ( _                         ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pUser
   ' =====================================================================================
   PROPERTY SET UserId <21> ( _                         ' VTable offset = 92
     BYVAL pUser AS WSTRING _                           ' __in BSTR pUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StateChange <22> ( _                    ' VTable offset = 96
   ) AS LONG                                            ' __retval_out TASK_SESSION_STATE_CHANGE_TYPE* pType
   ' =====================================================================================
   PROPERTY SET StateChange <22> ( _                    ' VTable offset = 100
     BYVAL pType AS LONG _                              ' __in TASK_SESSION_STATE_CHANGE_TYPE pType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISessionStateChangeTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventTrigger
' IID = {D45B0167-9653-4EEF-B94F-0732CA7AF251}
' Start task in response to an event log event
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IEventTrigger_INTERFACE_DEFINED)
    %IEventTrigger_INTERFACE_DEFINED = 1

INTERFACE IEventTrigger $IID_IEventTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IEventTrigger Methods
   ' =====================================================================================
   PROPERTY GET Subscription <20> ( _                   ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pQuery
   ' =====================================================================================
   PROPERTY SET Subscription <20> ( _                   ' VTable offset = 84
     BYVAL pQuery AS WSTRING _                          ' __in BSTR pQuery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Delay <21> ( _                          ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET Delay <21> ( _                          ' VTable offset = 92
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueQueries <22> ( _                   ' VTable offset = 96
   ) AS ITaskNamedValueCollection                       ' __retval_out ITaskNamedValueCollection** ppNamedXPaths
   ' =====================================================================================
   PROPERTY SET ValueQueries <22> ( _                   ' VTable offset = 100
     BYVAL ppNamedXPaths AS ITaskNamedValueCollection _ ' __in ITaskNamedValueCollection* ppNamedXPaths
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITimeTrigger
' IID = {B45747E0-EBA7-4276-9F29-85C5BB300006}
' Start task at a specific time
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%ITimeTrigger_INTERFACE_DEFINED)
    %ITimeTrigger_INTERFACE_DEFINED = 1

INTERFACE ITimeTrigger $IID_ITimeTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITimeTrigger Methods
   ' =====================================================================================
   PROPERTY GET RandomDelay <20> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pRandomDelay
   ' =====================================================================================
   PROPERTY SET RandomDelay <20> ( _                    ' VTable offset = 84
     BYVAL pRandomDelay AS WSTRING _                    ' __in BSTR pRandomDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimeTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDailyTrigger
' IID = {126C5CD8-B288-41D5-8DBF-E491446ADC5C}
' Run task every day, or every N days
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IDailyTrigger_INTERFACE_DEFINED)
    %IDailyTrigger_INTERFACE_DEFINED = 1

INTERFACE IDailyTrigger $IID_IDailyTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDailyTrigger Methods
   ' =====================================================================================
   PROPERTY GET DaysInterval <25> ( _                   ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short* pDays
   ' =====================================================================================
   PROPERTY SET DaysInterval <25> ( _                   ' VTable offset = 84
     BYVAL pDays AS INTEGER _                           ' __in short pDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RandomDelay <20> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pRandomDelay
   ' =====================================================================================
   PROPERTY SET RandomDelay <20> ( _                    ' VTable offset = 92
     BYVAL pRandomDelay AS WSTRING _                    ' __in BSTR pRandomDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDailyTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWeeklyTrigger
' IID = {5038FC98-82FF-436D-8728-A512A57C9DC1}
' Run task every week, or every N weeks
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IWeeklyTrigger_INTERFACE_DEFINED)
    %IWeeklyTrigger_INTERFACE_DEFINED = 1

INTERFACE IWeeklyTrigger $IID_IWeeklyTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWeeklyTrigger Methods
   ' =====================================================================================
   PROPERTY GET DaysOfWeek <25> ( _                     ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short* pDays
   ' =====================================================================================
   PROPERTY SET DaysOfWeek <25> ( _                     ' VTable offset = 84
     BYVAL pDays AS INTEGER _                           ' __in short pDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WeeksInterval <26> ( _                  ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out short* pWeeks
   ' =====================================================================================
   PROPERTY SET WeeksInterval <26> ( _                  ' VTable offset = 92
     BYVAL pWeeks AS INTEGER _                          ' __in short pWeeks
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RandomDelay <20> ( _                    ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR* pRandomDelay
   ' =====================================================================================
   PROPERTY SET RandomDelay <20> ( _                    ' VTable offset = 100
     BYVAL pRandomDelay AS WSTRING _                    ' __in BSTR pRandomDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWeeklyTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMonthlyTrigger
' IID = {97C45EF1-6B02-4A1A-9C0E-1EBFBA1500AC}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IMonthlyTrigger_INTERFACE_DEFINED)
    %IMonthlyTrigger_INTERFACE_DEFINED = 1

INTERFACE IMonthlyTrigger $IID_IMonthlyTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMonthlyTrigger Methods
   ' =====================================================================================
   PROPERTY GET DaysOfMonth <25> ( _                    ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long* pDays
   ' =====================================================================================
   PROPERTY SET DaysOfMonth <25> ( _                    ' VTable offset = 84
     BYVAL pDays AS LONG _                              ' __in long pDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthsOfYear <26> ( _                   ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out short* pMonths
   ' =====================================================================================
   PROPERTY SET MonthsOfYear <26> ( _                   ' VTable offset = 92
     BYVAL pMonths AS INTEGER _                         ' __in short pMonths
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunOnLastDayOfMonth <27> ( _            ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pLastDay
   ' =====================================================================================
   PROPERTY SET RunOnLastDayOfMonth <27> ( _            ' VTable offset = 100
     BYVAL pLastDay AS INTEGER _                        ' __in VARIANT_BOOL pLastDay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RandomDelay <20> ( _                    ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR* pRandomDelay
   ' =====================================================================================
   PROPERTY SET RandomDelay <20> ( _                    ' VTable offset = 108
     BYVAL pRandomDelay AS WSTRING _                    ' __in BSTR pRandomDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMonthlyTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMonthlyDOWTrigger
' IID = {77D025A3-90FA-43AA-B52E-CDA5499B946A}
' Run task on specific day of week, e.g. 'Second Tuesday in March'
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IMonthlyDOWTrigger_INTERFACE_DEFINED)
    %IMonthlyDOWTrigger_INTERFACE_DEFINED = 1

INTERFACE IMonthlyDOWTrigger $IID_IMonthlyDOWTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMonthlyDOWTrigger Methods
   ' =====================================================================================
   PROPERTY GET DaysOfWeek <25> ( _                     ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out short* pDays
   ' =====================================================================================
   PROPERTY SET DaysOfWeek <25> ( _                     ' VTable offset = 84
     BYVAL pDays AS INTEGER _                           ' __in short pDays
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WeeksOfMonth <26> ( _                   ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out short* pWeeks
   ' =====================================================================================
   PROPERTY SET WeeksOfMonth <26> ( _                   ' VTable offset = 92
     BYVAL pWeeks AS INTEGER _                          ' __in short pWeeks
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MonthsOfYear <27> ( _                   ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out short* pMonths
   ' =====================================================================================
   PROPERTY SET MonthsOfYear <27> ( _                   ' VTable offset = 100
     BYVAL pMonths AS INTEGER _                         ' __in short pMonths
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunOnLastWeekOfMonth <28> ( _           ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pLastWeek
   ' =====================================================================================
   PROPERTY SET RunOnLastWeekOfMonth <28> ( _           ' VTable offset = 108
     BYVAL pLastWeek AS INTEGER _                       ' __in VARIANT_BOOL pLastWeek
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RandomDelay <20> ( _                    ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR* pRandomDelay
   ' =====================================================================================
   PROPERTY SET RandomDelay <20> ( _                    ' VTable offset = 116
     BYVAL pRandomDelay AS WSTRING _                    ' __in BSTR pRandomDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMonthlyDOWTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBootTrigger
' IID = {2A9C35DA-D357-41F4-BBC1-207AC1B1F3CB}
' Run task when machine starts up
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IBootTrigger_INTERFACE_DEFINED)
    %IBootTrigger_INTERFACE_DEFINED = 1

INTERFACE IBootTrigger $IID_IBootTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IBootTrigger Methods
   ' =====================================================================================
   PROPERTY GET Delay <20> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET Delay <20> ( _                          ' VTable offset = 84
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBootTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegistrationTrigger
' IID = {4C8FEC3A-C218-4E0C-B23D-629024DB91A2}
' Run task as soon as it is registered
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ITrigger
' ########################################################################################

#IF NOT %DEF(%IRegistrationTrigger_INTERFACE_DEFINED)
    %IRegistrationTrigger_INTERFACE_DEFINED = 1

INTERFACE IRegistrationTrigger $IID_IRegistrationTrigger

   INHERIT IDispatch

   ' =====================================================================================
   ' ITrigger Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_TRIGGER_TYPE2* pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 36
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repetition <3> ( _                      ' VTable offset = 40
   ) AS IRepetitionPattern                              ' __retval_out IRepetitionPattern** ppRepeat
   ' =====================================================================================
   PROPERTY SET Repetition <3> ( _                      ' VTable offset = 44
     BYVAL ppRepeat AS IRepetitionPattern _             ' __in IRepetitionPattern* ppRepeat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <4> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <4> ( _              ' VTable offset = 52
     BYVAL pTimeLimit AS WSTRING _                      ' __in BSTR pTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartBoundary <5> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pStart
   ' =====================================================================================
   PROPERTY SET StartBoundary <5> ( _                   ' VTable offset = 60
     BYVAL pStart AS WSTRING  _                         ' __in BSTR pStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndBoundary <6> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pEnd
   ' =====================================================================================
   PROPERTY SET EndBoundary <6> ( _                     ' VTable offset = 68
     BYVAL pEnd AS WSTRING _                            ' __in BSTR pEnd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 76
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IRegistrationTrigger Methods
   ' =====================================================================================
   PROPERTY GET Delay <20> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET Delay <20> ( _                          ' VTable offset = 84
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegistrationTrigger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAction
' IID = {BAE54997-48B1-4CBE-9965-D6BE263EBEA4}
' A single operation to be performed
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAction_INTERFACE_DEFINED)
    %IAction_INTERFACE_DEFINED = 1

INTERFACE IAction $IID_IAction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_ACTION_TYPE* pType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExecAction
' IID = {4C3D624D-FD6B-49A3-B9B7-09CB3CD3F047}
' Run a program
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAction
' ########################################################################################

#IF NOT %DEF(%IExecAction_INTERFACE_DEFINED)
    %IExecAction_INTERFACE_DEFINED = 1

INTERFACE IExecAction $IID_IExecAction

   INHERIT IDispatch

   ' =====================================================================================
   ' IAction Methods
   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_ACTION_TYPE* pType
   ' =====================================================================================

   ' =====================================================================================
   ' IExecAction Methods
   ' =====================================================================================
   PROPERTY GET Path <10> ( _                           ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pPath
   ' =====================================================================================
   PROPERTY SET Path <10> ( _                           ' VTable offset = 44
     BYVAL pPath AS WSTRING _                           ' __in BSTR pPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Arguments <11> ( _                      ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pArgument
   ' =====================================================================================
   PROPERTY SET Arguments <11> ( _                      ' VTable offset = 52
     BYVAL pArgument AS WSTRING _                       ' __in BSTR pArgument
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WorkingDirectory <12> ( _               ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pWorkingDirectory
   ' =====================================================================================
   PROPERTY SET WorkingDirectory <12> ( _               ' VTable offset = 60
     BYVAL pWorkingDirectory AS WSTRING _               ' __in BSTR pWorkingDirectory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExecAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IShowMessageAction
' IID = {505E9E68-AF89-46B8-A30F-56162A83D537}
' Show a message to the user
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAction
' ########################################################################################

#IF NOT %DEF(%IShowMessageAction_INTERFACE_DEFINED)
    %IShowMessageAction_INTERFACE_DEFINED = 1

INTERFACE IShowMessageAction $IID_IShowMessageAction

   INHERIT IDispatch

   ' =====================================================================================
   ' IAction Methods
   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_ACTION_TYPE* pType
   ' =====================================================================================

   ' =====================================================================================
   ' IShowMessageAction Methods
   ' =====================================================================================
   PROPERTY GET Title <10> ( _                          ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pTitle
   ' =====================================================================================
   PROPERTY SET Title <10> ( _                          ' VTable offset = 44
     BYVAL pTitle AS WSTRING _                          ' __in BSTR pTitle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageBody <11> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pMessageBody
   ' =====================================================================================
   PROPERTY SET MessageBody <11> ( _                    ' VTable offset = 52
     BYVAL pMessageBody AS WSTRING _                    ' __in BSTR pMessageBody
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShowMessageAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IComHandlerAction
' IID = {6D2FD252-75C5-4F66-90BA-2A7D8CC3039F}
' Execute a Task Handler
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAction
' ########################################################################################

#IF NOT %DEF(%IComHandlerAction_INTERFACE_DEFINED)
    %IComHandlerAction_INTERFACE_DEFINED = 1

INTERFACE IComHandlerAction $IID_IComHandlerAction

   INHERIT IDispatch

   ' =====================================================================================
   ' IAction Methods
   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_ACTION_TYPE* pType
   ' =====================================================================================

   ' =====================================================================================
   ' IComHandlerAction Methods
   ' =====================================================================================
   PROPERTY GET ClassId <10> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pClsid
   ' =====================================================================================
   PROPERTY SET ClassId <10> ( _                        ' VTable offset = 44
     BYVAL pClsid AS WSTRING _                          ' __in BSTR pClsid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data <11> ( _                           ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pData
   ' =====================================================================================
   PROPERTY SET Data <11> ( _                           ' VTable offset = 52
     BYVAL pData AS WSTRING _                           ' __in BSTR pData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComHandlerAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEmailAction
' IID = {10F62C64-7E16-4314-A0C2-0C3683F99D40}
' Send an email
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IAction
' ########################################################################################

#IF NOT %DEF(%IEmailAction_INTERFACE_DEFINED)
    %IEmailAction_INTERFACE_DEFINED = 1

INTERFACE IEmailAction $IID_IEmailAction

   INHERIT IDispatch

   ' =====================================================================================
   ' IAction Methods
   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out TASK_ACTION_TYPE* pType
   ' =====================================================================================

   ' =====================================================================================
   ' IEmailAction Methods
   ' =====================================================================================
   PROPERTY GET Server <10> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pServer
   ' =====================================================================================
   PROPERTY SET Server <10> ( _                         ' VTable offset = 44
     BYVAL pServer AS WSTRING _                         ' __in BSTR pServer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Subject <11> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pSubject
   ' =====================================================================================
   PROPERTY SET Subject <11> ( _                        ' VTable offset = 52
     BYVAL pSubject AS WSTRING _                        ' __in BSTR pSubject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET To <12> ( _                             ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pTo
   ' =====================================================================================
   PROPERTY SET To <12> ( _                             ' VTable offset = 60
     BYVAL pTo AS WSTRING _                             ' __in BSTR pTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cc <13> ( _                             ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pCc
   ' =====================================================================================
   PROPERTY SET Cc <13> ( _                             ' VTable offset = 68
     BYVAL pCc AS WSTRING _                             ' __in BSTR pCc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bcc <14> ( _                            ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR* pBcc
   ' =====================================================================================
   PROPERTY SET Bcc <14> ( _                            ' VTable offset = 76
     BYVAL pBcc AS WSTRING _                            ' __in BSTR pBcc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplyTo <15> ( _                        ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pReplyTo
   ' =====================================================================================
   PROPERTY SET ReplyTo <15> ( _                        ' VTable offset = 84
     BYVAL pReplyTo AS WSTRING _                        ' __in BSTR pReplyTo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET From <16> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pFrom
   ' =====================================================================================
   PROPERTY SET From <16> ( _                           ' VTable offset = 92
     BYVAL pFrom AS WSTRING _                           ' __in BSTR pFrom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HeaderFields <17> ( _                   ' VTable offset = 96
   ) AS ITaskNamedValueCollection                       ' __retval_out ITaskNamedValueCollection** ppHeaderFields
   ' =====================================================================================
   PROPERTY SET HeaderFields <17> ( _                   ' VTable offset = 100
     BYVAL ppHeaderFields AS ITaskNamedValueCollection _ ' __in ITaskNamedValueCollection* ppHeaderFields
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Body <18> ( _                           ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR* pBody
   ' =====================================================================================
   PROPERTY SET Body <18> ( _                           ' VTable offset = 108
     BYVAL pBody AS WSTRING _                           ' __in BSTR pBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attachments <19> ( _                    ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out SAFEARRAY* pAttachements
   ' =====================================================================================
   PROPERTY SET Attachments <19> ( _                    ' VTable offset = 116
     BYVAL pAttachements AS DWORD _                     ' __in SAFEARRAY pAttachements
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEmailAction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITriggerCollection
' IID = {85DF5081-1B24-4F32-878A-D9D14DF4CB77}
' Container for ITriggers
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITriggerCollection_INTERFACE_DEFINED)
    %ITriggerCollection_INTERFACE_DEFINED = 1

INTERFACE ITriggerCollection $IID_ITriggerCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS ITrigger                                        ' __retval_out ITrigger** ppTrigger
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   METHOD Create <2> ( _                                ' VTable offset = 40
     BYVAL Type AS LONG _                               ' __in TASK_TRIGGER_TYPE2 Type
   ) AS ITrigger                                        ' __retval_out ITrigger** ppTrigger
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <5> ( _                                 ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITriggerCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActionCollection
' IID = {02820E19-7B98-4ED2-B2E8-FDCCCEFF619B}
' Container for IActions
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IActionCollection_INTERFACE_DEFINED)
    %IActionCollection_INTERFACE_DEFINED = 1

INTERFACE IActionCollection $IID_IActionCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IAction                                         ' __retval_out IAction** ppAction
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   PROPERTY GET XmlText <2> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pText
   ' =====================================================================================
   PROPERTY SET XmlText <2> ( _                         ' VTable offset = 44
     BYVAL pText AS WSTRING _                           ' __in BSTR pText
   )                                                    ' void
   ' =====================================================================================
   METHOD Create <3> ( _                                ' VTable offset = 48
     BYVAL Type AS LONG _                               ' __in TASK_ACTION_TYPE Type
   ) AS IAction                                         ' __retval_out IAction** ppAction
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 52
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <5> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Context <6> ( _                         ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pContext
   ' =====================================================================================
   PROPERTY SET Context <6> ( _                         ' VTable offset = 64
     BYVAL pContext AS WSTRING _                        ' __in BSTR pContext
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrincipal
' IID = {D98D51E5-C9B4-496A-A9C1-18980261CF0F}
' User associated with task
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPrincipal_INTERFACE_DEFINED)
    %IPrincipal_INTERFACE_DEFINED = 1

INTERFACE IPrincipal $IID_IPrincipal

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Id <1> ( _                              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <1> ( _                              ' VTable offset = 32
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY SET DisplayName <2> ( _                     ' VTable offset = 40
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserId <3> ( _                          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pUser
   ' =====================================================================================
   PROPERTY SET UserId <3> ( _                          ' VTable offset = 48
     BYVAL pUser AS WSTRING _                           ' __in BSTR pUser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogonType <4> ( _                       ' VTable offset = 52
   ) AS LONG                                            ' __retval_out TASK_LOGON_TYPE* pLogon
   ' =====================================================================================
   PROPERTY SET LogonType <4> ( _                       ' VTable offset = 56
     BYVAL pLogon AS LONG _                             ' __in TASK_LOGON_TYPE pLogon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GroupId <5> ( _                         ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pGroup
   ' =====================================================================================
   PROPERTY SET GroupId <5> ( _                         ' VTable offset = 64
     BYVAL pGroup AS WSTRING _                          ' __in BSTR pGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunLevel <6> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out TASK_RUNLEVEL_TYPE* pRunLevel
   ' =====================================================================================
   PROPERTY SET RunLevel <6> ( _                        ' VTable offset = 72
     BYVAL pRunLevel AS LONG _                          ' __in TASK_RUNLEVEL_TYPE pRunLevel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrincipal_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegistrationInfo
' IID = {416D8B73-CB41-4EA1-805C-9BE9A5AC4A74}
' Information about the task
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegistrationInfo_INTERFACE_DEFINED)
    %IRegistrationInfo_INTERFACE_DEFINED = 1

INTERFACE IRegistrationInfo $IID_IRegistrationInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Description <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pDescription
   ' =====================================================================================
   PROPERTY SET Description <1> ( _                     ' VTable offset = 32
     BYVAL pDescription AS WSTRING _                    ' __in BSTR pDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Author <2> ( _                          ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pAuthor
   ' =====================================================================================
   PROPERTY SET Author <2> ( _                          ' VTable offset = 40
     BYVAL pAuthor AS WSTRING _                         ' __in BSTR pAuthor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <4> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pVersion
   ' =====================================================================================
   PROPERTY SET Version <4> ( _                         ' VTable offset = 48
     BYVAL pVersion AS WSTRING _                        ' __in BSTR pVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Date <5> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pDate
   ' =====================================================================================
   PROPERTY SET Date <5> ( _                            ' VTable offset = 56
     BYVAL pDate AS WSTRING _                           ' __in BSTR pDate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Documentation <6> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pDocumentation
   ' =====================================================================================
   PROPERTY SET Documentation <6> ( _                   ' VTable offset = 64
     BYVAL pDocumentation AS WSTRING _                  ' __in BSTR pDocumentation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET XmlText <9> ( _                         ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pText
   ' =====================================================================================
   PROPERTY SET XmlText <9> ( _                         ' VTable offset = 72
     BYVAL pText AS WSTRING _                           ' __in BSTR pText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URI <10> ( _                            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pUri
   ' =====================================================================================
   PROPERTY SET URI <10> ( _                            ' VTable offset = 80
     BYVAL pUri AS WSTRING _                            ' __in BSTR pUri
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecurityDescriptor <11> ( _             ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT* pSddl
   ' =====================================================================================
   PROPERTY SET SecurityDescriptor <11> ( _             ' VTable offset = 88
     BYVAL pSddl AS VARIANT _                           ' __in VARIANT pSddl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <12> ( _                         ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pSource
   ' =====================================================================================
   PROPERTY SET Source <12> ( _                         ' VTable offset = 96
     BYVAL pSource AS WSTRING _                         ' __in BSTR pSource
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegistrationInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskDefinition
' IID = {F5BC8FC5-536D-4F77-B852-FBC1356FDEB6}
' Describe task to be run by the Task Scheduler service
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskDefinition_INTERFACE_DEFINED)
    %ITaskDefinition_INTERFACE_DEFINED = 1

INTERFACE ITaskDefinition $IID_ITaskDefinition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RegistrationInfo <1> ( _                ' VTable offset = 28
   ) AS IRegistrationInfo                               ' __retval_out IRegistrationInfo** ppRegistrationInfo
   ' =====================================================================================
   PROPERTY SET RegistrationInfo <1> ( _                ' VTable offset = 32
     BYVAL ppRegistrationInfo AS IRegistrationInfo _    ' __in IRegistrationInfo* ppRegistrationInfo
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Triggers <2> ( _                        ' VTable offset = 36
   ) AS ITriggerCollection                              ' __retval_out ITriggerCollection** ppTriggers
   ' =====================================================================================
   PROPERTY SET Triggers <2> ( _                        ' VTable offset = 40
     BYVAL ppTriggers AS ITriggerCollection _           ' __in ITriggerCollection* ppTriggers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Settings <7> ( _                        ' VTable offset = 44
   ) AS ITaskSettings                                   ' __retval_out ITaskSettings** ppSettings
   ' =====================================================================================
   PROPERTY SET Settings <7> ( _                        ' VTable offset = 48
     BYVAL ppSettings AS ITaskSettings _                ' __in ITaskSettings* ppSettings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data <11> ( _                           ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pData
   ' =====================================================================================
   PROPERTY SET Data <11> ( _                           ' VTable offset = 56
     BYVAL pData AS WSTRING _                           ' __in BSTR pData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Principal <12> ( _                      ' VTable offset = 60
   ) AS IPrincipal                                      ' __retval_out IPrincipal** ppPrincipal
   ' =====================================================================================
   PROPERTY SET Principal <12> ( _                      ' VTable offset = 64
     BYVAL ppPrincipal AS IPrincipal _                  ' __in IPrincipal* ppPrincipal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Actions <13> ( _                        ' VTable offset = 68
   ) AS IActionCollection                               ' __retval_out IActionCollection** ppActions
   ' =====================================================================================
   PROPERTY SET Actions <13> ( _                        ' VTable offset = 72
     BYVAL ppActions AS IActionCollection _             ' __in IActionCollection* ppActions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET XmlText <14> ( _                        ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pXml
   ' =====================================================================================
   PROPERTY SET XmlText <14> ( _                        ' VTable offset = 80
     BYVAL pXml AS WSTRING _                            ' __in BSTR pXml
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskDefinition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskSettings
' IID = {8FD4711D-2D02-4C8C-87E3-EFF699DE127E}
' Control execution of the task
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskSettings_INTERFACE_DEFINED)
    %ITaskSettings_INTERFACE_DEFINED = 1

INTERFACE ITaskSettings $IID_ITaskSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AllowDemandStart <3> ( _                ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowDemandStart
   ' =====================================================================================
   PROPERTY SET AllowDemandStart <3> ( _                ' VTable offset = 32
     BYVAL pAllowDemandStart AS INTEGER _               ' __in VARIANT_BOOL pAllowDemandStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RestartInterval <4> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pRestartInterval
   ' =====================================================================================
   PROPERTY SET RestartInterval <4> ( _                 ' VTable offset = 40
     BYVAL pRestartInterval AS WSTRING _                ' __in BSTR pRestartInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RestartCount <5> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int* pRestartCount
   ' =====================================================================================
   PROPERTY SET RestartCount <5> ( _                    ' VTable offset = 48
     BYVAL pRestartCount AS LONG _                      ' __in int pRestartCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultipleInstances <6> ( _               ' VTable offset = 52
   ) AS LONG                                            ' __retval_out TASK_INSTANCES_POLICY* pPolicy
   ' =====================================================================================
   PROPERTY SET MultipleInstances <6> ( _               ' VTable offset = 56
     BYVAL pPolicy AS LONG _                            ' __in TASK_INSTANCES_POLICY pPolicy
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopIfGoingOnBatteries <7> ( _          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStopIfOnBatteries
   ' =====================================================================================
   PROPERTY SET StopIfGoingOnBatteries <7> ( _          ' VTable offset = 64
     BYVAL pStopIfOnBatteries AS INTEGER _              ' __in VARIANT_BOOL pStopIfOnBatteries
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisallowStartIfOnBatteries <8> ( _      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pDisallowStart
   ' =====================================================================================
   PROPERTY SET DisallowStartIfOnBatteries <8> ( _      ' VTable offset = 72
     BYVAL pDisallowStart AS INTEGER _                  ' __in VARIANT_BOOL pDisallowStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowHardTerminate <9> ( _              ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pAllowHardTerminate
   ' =====================================================================================
   PROPERTY SET AllowHardTerminate <9> ( _              ' VTable offset = 80
     BYVAL pAllowHardTerminate AS INTEGER _             ' __in VARIANT_BOOL pAllowHardTerminate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartWhenAvailable <10> ( _             ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStartWhenAvailable
   ' =====================================================================================
   PROPERTY SET StartWhenAvailable <10> ( _             ' VTable offset = 88
     BYVAL pStartWhenAvailable AS INTEGER _             ' __in VARIANT_BOOL pStartWhenAvailable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET XmlText <11> ( _                        ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pText
   ' =====================================================================================
   PROPERTY SET XmlText <11> ( _                        ' VTable offset = 96
     BYVAL pText AS WSTRING _                           ' __in BSTR pText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunOnlyIfNetworkAvailable <12> ( _      ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pRunOnlyIfNetworkAvailable
   ' =====================================================================================
   PROPERTY SET RunOnlyIfNetworkAvailable <12> ( _      ' VTable offset = 104
     BYVAL pRunOnlyIfNetworkAvailable AS INTEGER _      ' __in VARIANT_BOOL pRunOnlyIfNetworkAvailable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExecutionTimeLimit <13> ( _             ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* pExecutionTimeLimit
   ' =====================================================================================
   PROPERTY SET ExecutionTimeLimit <13> ( _             ' VTable offset = 112
     BYVAL pExecutionTimeLimit AS WSTRING _             ' __in BSTR pExecutionTimeLimit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <14> ( _                        ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <14> ( _                        ' VTable offset = 120
     BYVAL pEnabled AS INTEGER _                        ' __in VARIANT_BOOL pEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteExpiredTaskAfter <15> ( _         ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pExpirationDelay
   ' =====================================================================================
   PROPERTY SET DeleteExpiredTaskAfter <15> ( _         ' VTable offset = 128
     BYVAL pExpirationDelay AS WSTRING _                ' __in BSTR pExpirationDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <16> ( _                       ' VTable offset = 132
   ) AS LONG                                            ' __retval_out int* pPriority
   ' =====================================================================================
   PROPERTY SET Priority <16> ( _                       ' VTable offset = 136
     BYVAL pPriority AS LONG _                          ' __in int pPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Compatibility <17> ( _                  ' VTable offset = 140
   ) AS LONG                                            ' __retval_out TASK_COMPATIBILITY* pCompatLevel
   ' =====================================================================================
   PROPERTY SET Compatibility <17> ( _                  ' VTable offset = 144
     BYVAL pCompatLevel AS LONG _                       ' __in TASK_COMPATIBILITY pCompatLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hidden <18> ( _                         ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pHidden
   ' =====================================================================================
   PROPERTY SET Hidden <18> ( _                         ' VTable offset = 152
     BYVAL pHidden AS INTEGER _                         ' __in VARIANT_BOOL pHidden
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IdleSettings <19> ( _                   ' VTable offset = 156
   ) AS IIdleSettings                                   ' __retval_out IIdleSettings** ppIdleSettings
   ' =====================================================================================
   PROPERTY SET IdleSettings <19> ( _                   ' VTable offset = 160
     BYVAL ppIdleSettings AS IIdleSettings _            ' __in IIdleSettings* ppIdleSettings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunOnlyIfIdle <20> ( _                  ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pRunOnlyIfIdle
   ' =====================================================================================
   PROPERTY SET RunOnlyIfIdle <20> ( _                  ' VTable offset = 168
     BYVAL pRunOnlyIfIdle AS INTEGER _                  ' __in VARIANT_BOOL pRunOnlyIfIdle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WakeToRun <21> ( _                      ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pWake
   ' =====================================================================================
   PROPERTY SET WakeToRun <21> ( _                      ' VTable offset = 176
     BYVAL pWake AS INTEGER _                           ' __in VARIANT_BOOL pWake
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkSettings <22> ( _                ' VTable offset = 180
   ) AS INetworkSettings                                ' __retval_out INetworkSettings** ppNetworkSettings
   ' =====================================================================================
   PROPERTY SET NetworkSettings <22> ( _                ' VTable offset = 184
     BYVAL ppNetworkSettings AS INetworkSettings _      ' __in INetworkSettings* ppNetworkSettings
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskSettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskSettings2
' IID = {2C05C3F0-6EED-4C05-A15F-ED7D7A98A369}
' Extended control execution of the task.
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskSettings2_INTERFACE_DEFINED)
    %ITaskSettings2_INTERFACE_DEFINED = 1

INTERFACE ITaskSettings2 $IID_ITaskSettings2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisallowStartOnRemoteAppSession <30> ( _ ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pDisallowStart
   ' =====================================================================================
   PROPERTY SET DisallowStartOnRemoteAppSession <30> ( _ ' VTable offset = 32
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pDisallowStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseUnifiedSchedulingEngine <31> ( _     ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pUseUnifiedEngine
   ' =====================================================================================
   PROPERTY SET UseUnifiedSchedulingEngine <31> ( _     ' VTable offset = 40
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL pUseUnifiedEngine
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskSettings2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegisteredTaskCollection
' IID = {86627EB4-42A7-41E4-A4D9-AC33A72F2D52}
' Group of IRegisteredTasks
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegisteredTaskCollection_INTERFACE_DEFINED)
    %IRegisteredTaskCollection_INTERFACE_DEFINED = 1

INTERFACE IRegisteredTaskCollection $IID_IRegisteredTaskCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG* pCount
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IRegisteredTask                                 ' __retval_out IRegisteredTask** ppRegisteredTask
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegisteredTaskCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITaskFolder
' IID = {8CFAC062-A080-4C15-9A88-AA7C2AF80DFC}
' Container (directory) for tasks
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITaskFolder_INTERFACE_DEFINED)
    %ITaskFolder_INTERFACE_DEFINED = 1

INTERFACE ITaskFolder $IID_ITaskFolder

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY GET Path <0> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pPath
   ' =====================================================================================
   METHOD GetFolder <3> ( _                             ' VTable offset = 36
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS ITaskFolder                                     ' __retval_out ITaskFolder** ppFolder
   ' =====================================================================================
   METHOD GetFolders <4> ( _                            ' VTable offset = 40
     BYVAL flags AS LONG _                              ' __in LONG flags
   ) AS ITaskFolderCollection                           ' __retval_out ITaskFolderCollection** ppFolders
   ' =====================================================================================
   METHOD CreateFolder <5> ( _                          ' VTable offset = 44
     BYVAL subFolderName AS WSTRING _                   ' __in BSTR subFolderName
   , OPTIONAL BYVAL sddl AS VARIANT _                   ' __opt_in VARIANT sddl
   ) AS ITaskFolder                                     ' __retval_out ITaskFolder** ppFolder
   ' =====================================================================================
   METHOD DeleteFolder <6> ( _                          ' VTable offset = 48
     BYVAL subFolderName AS WSTRING _                   ' __in BSTR subFolderName
   , BYVAL flags AS LONG _                              ' __in LONG flags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTask <7> ( _                               ' VTable offset = 52
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   ) AS IRegisteredTask                                 ' __retval_out IRegisteredTask** ppTask
   ' =====================================================================================
   METHOD GetTasks <8> ( _                              ' VTable offset = 56
     BYVAL flags AS LONG _                              ' __in LONG flags
   ) AS IRegisteredTaskCollection                       ' __retval_out IRegisteredTaskCollection** ppTasks
   ' =====================================================================================
   METHOD DeleteTask <9> ( _                            ' VTable offset = 60
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL flags AS LONG _                              ' __in LONG flags
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterTask <10> ( _                         ' VTable offset = 64
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL XmlText AS WSTRING _                         ' __in BSTR XmlText
   , BYVAL flags AS LONG _                              ' __in LONG flags
   , BYVAL UserId AS VARIANT _                          ' __in VARIANT UserId
   , BYVAL password AS VARIANT _                        ' __in VARIANT password
   , BYVAL LogonType AS LONG _                          ' __in TASK_LOGON_TYPE LogonType
   , OPTIONAL BYVAL sddl AS VARIANT _                   ' __opt_in VARIANT sddl
   ) AS IRegisteredTask                                 ' __retval_out IRegisteredTask** ppTask
   ' =====================================================================================
   METHOD RegisterTaskDefinition <11> ( _               ' VTable offset = 68
     BYVAL Path AS WSTRING _                            ' __in BSTR Path
   , BYVAL pDefinition AS ITaskDefinition _             ' __in ITaskDefinition* pDefinition
   , BYVAL flags AS LONG _                              ' __in LONG flags
   , BYVAL UserId AS VARIANT _                          ' __in VARIANT UserId
   , BYVAL password AS VARIANT _                        ' __in VARIANT password
   , BYVAL LogonType AS LONG _                          ' __in TASK_LOGON_TYPE LogonType
   , OPTIONAL BYVAL sddl AS VARIANT _                   ' __opt_in VARIANT sddl
   ) AS IRegisteredTask                                 ' __retval_out IRegisteredTask** ppTask
   ' =====================================================================================
   METHOD GetSecurityDescriptor <12> ( _                ' VTable offset = 72
     BYVAL securityInformation AS LONG _                ' __in LONG securityInformation
   ) AS WSTRING                                         ' __retval_out BSTR* pSddl
   ' =====================================================================================
   METHOD SetSecurityDescriptor <13> ( _                ' VTable offset = 76
     BYVAL sddl AS WSTRING _                            ' __in BSTR sddl
   , BYVAL flags AS LONG _                              ' __in LONG flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskFolder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IIdleSettings
' IID = {84594461-0053-4342-A8FD-088FABF11F32}
' Parameters which specify idle state required for task to run
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IIdleSettings_INTERFACE_DEFINED)
    %IIdleSettings_INTERFACE_DEFINED = 1

INTERFACE IIdleSettings $IID_IIdleSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IdleDuration <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pDelay
   ' =====================================================================================
   PROPERTY SET IdleDuration <1> ( _                    ' VTable offset = 32
     BYVAL pDelay AS WSTRING _                          ' __in BSTR pDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WaitTimeout <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pTimeout
   ' =====================================================================================
   PROPERTY SET WaitTimeout <2> ( _                     ' VTable offset = 40
     BYVAL pTimeout AS WSTRING _                        ' __in BSTR pTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopOnIdleEnd <3> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStop
   ' =====================================================================================
   PROPERTY SET StopOnIdleEnd <3> ( _                   ' VTable offset = 48
     BYVAL pStop AS INTEGER _                           ' __in VARIANT_BOOL pStop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RestartOnIdle <4> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pRestart
   ' =====================================================================================
   PROPERTY SET RestartOnIdle <4> ( _                   ' VTable offset = 56
     BYVAL pRestart AS INTEGER _                        ' __in VARIANT_BOOL pRestart
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIdleSettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetworkSettings
' IID = {9F7DEA84-C30B-4245-80B6-00E9F646F1B4}
' Specify network settings required to run task
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetworkSettings_INTERFACE_DEFINED)
    %INetworkSettings_INTERFACE_DEFINED = 1

INTERFACE INetworkSettings $IID_INetworkSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pName
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL pName AS WSTRING _                           ' __in BSTR pName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pId
   ' =====================================================================================
   PROPERTY SET Id <2> ( _                              ' VTable offset = 40
     BYVAL pId AS WSTRING _                             ' __in BSTR pId
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetworkSettings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRepetitionPattern
' IID = {7FB9ACF1-26BE-400E-85B5-294B9C75DFD6}
' Specify how often a task is to repeat
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRepetitionPattern_INTERFACE_DEFINED)
    %IRepetitionPattern_INTERFACE_DEFINED = 1

INTERFACE IRepetitionPattern $IID_IRepetitionPattern

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Interval <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pInterval
   ' =====================================================================================
   PROPERTY SET Interval <1> ( _                        ' VTable offset = 32
     BYVAL pInterval AS WSTRING _                       ' __in BSTR pInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <2> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pDuration
   ' =====================================================================================
   PROPERTY SET Duration <2> ( _                        ' VTable offset = 40
     BYVAL pDuration AS WSTRING _                       ' __in BSTR pDuration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopAtDurationEnd <3> ( _               ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStop
   ' =====================================================================================
   PROPERTY SET StopAtDurationEnd <3> ( _               ' VTable offset = 48
     BYVAL pStop AS INTEGER _                           ' __in VARIANT_BOOL pStop
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRepetitionPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrincipal2
' IID = {D98D51E5-C9B4-496A-A9C1-18980261CF0F}
' Inherited interface = IPrincipal
' ########################################################################################

#IF NOT %DEF(%IPrincipal2_INTERFACE_DEFINED)
    %IPrincipal2_INTERFACE_DEFINED = 1

INTERFACE IPrincipal2 $IID_IPrincipal2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ProcessTokenSidType ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out TASK_PROCESSTOKENSID_TYPE *pProcessTokenSidType
   ' =====================================================================================
   PROPERTY SET ProcessTokenSidType ( _                 ' VTable offset = 32
     BYVAL processTokenSidType AS LONG _                ' __in TASK_PROCESSTOKENSID_TYPE processTokenSidType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequiredPrivilegeCount ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   PROPERTY GET RequiredPrivilege ( _                   ' VTable offset = 40
     BYVAL index AS LONG _                              ' __in long index
   ) AS WSTRING                                         ' __retval_out BSTR *pPrivilege
   ' =====================================================================================
   METHOD AddRequiredPrivilege ( _                      ' VTable offset = 44
     BYVAL privilege AS WSTRING _                       ' __in BSTR privilege
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrincipal2_INTERFACE_DEFINED__ */
