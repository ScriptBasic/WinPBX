' ########################################################################################
' Microsoft Windows
' File: exevtsnk.inc
' Library name: ExevtsnkLib
' Version: 1.0, Locale ID = 0
' Library GUID: {1F28FCC2-8B0D-11D2-9C95-00C04F79F1DB}
' Contents: EXOLEDB Event Sink Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EXECTSNK_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "oledb.inc"

'//
'// Exchange Store OLEDB CLSIDs
'//

$CLSID_CExoledbDataSource = GUID$("{9da0e0fa-86ce-11d1-8699-00c04fb98036}")
$CLSID_CExoledbBinder = GUID$("{9da0e0f3-86ce-11d1-8699-00c04fb98036}")
$CLSID_CExoledbDataSourceLS = GUID$("{9da0e120-86ce-11d1-8699-00c04fb98036}")
$CLSID_CExoledbBinderLS = GUID$("{9da0e11f-86ce-11d1-8699-00c04fb98036}")


'// Interface GUID
'//
$IID_IExStoreEventInfo = GUID$("{9DA0E100-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreDispEventInfo = GUID$("{9DA0E110-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreEventLogonInfo = GUID$("{9DA0E111-86CE-11D1-8699-00C04FB98036}")
$IID_IGetSourceURL = GUID$("{9DA0E10B-86CE-11D1-8699-00C04FB98036}")
$IID_IGetLockRow = GUID$("{9DA0E0EF-86CE-11D1-8699-00C04FB98036}")
$IID_IAsyncNotify = GUID$("{9DA0E10A-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreAsyncEvents = GUID$("{9DA0E0FE-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreSyncEvents = GUID$("{9DA0E0FF-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreSystemEvents = GUID$("{9DA0E101-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreLockEvents = GUID$("{9DA0E10E-86CE-11D1-8699-00C04FB98036}")
$IID_IStoreGuidFromUrl = GUID$("{9DA0E10C-86CE-11D1-8699-00C04FB98036}")
$IID_IExStoreEventRegistrationURL = GUID$("{9DA0E117-86CE-11D1-8699-00C04FB98036}")
$IID_IUserData = GUID$("{9DA0E116-86CE-11D1-8699-00C04FB98036}")
$IID_IEventSinkIsCacheable = GUID$("{9DA0E118-86CE-11D1-8699-00C04FB98036}")
$IID_ICreateRegistration = GUID$("{9DA0E11C-86CE-11D1-8699-00C04FB98036}")

$CLSID_StoreGuidFromUrl = GUID$("{9da0e10d-86ce-11d1-8699-00c04fb98036}")
$CLSID_StoreGuidFromUrlLS = GUID$("{9da0e123-86ce-11d1-8699-00c04fb98036}")

$LIBID_ExevtsnkLib = GUID$("{1F28FCC2-8B0D-11D2-9C95-00C04F79F1DB}")

' ########################################################################################
' Interface name = IExStoreEventInfo
' IID = {9DA0E100-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreEventInfo_INTERFACE_DEFINED)
    %IExStoreEventInfo_INTERFACE_DEFINED = 1

INTERFACE IExStoreEventInfo $IID_IExStoreEventInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RemoteGetEventItem ( _                        ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF pdwBindStatus AS DWORD _                     ' __out DWORD *pdwBindStatus
   , BYREF ppunkEventItem AS IUnknown _                 ' __out IUnknown **ppunkEventItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoteGetEventSession ( _                     ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppSession AS IUnknown _                      ' __out IUnknown **ppSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 20
     OPTIONAL BYVAL lErrorCode AS LONG _                ' __in_opt LONG lErrorCode [default value = 0]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreEventInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreDispEventInfo
' IID = {9DA0E110-86CE-11D1-8699-00C04FB98036}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExStoreDispEventInfo_INTERFACE_DEFINED)
    %IExStoreDispEventInfo_INTERFACE_DEFINED = 1

INTERFACE IExStoreDispEventInfo $IID_IExStoreDispEventInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventConnection <1610743808> ( _        ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppConnection
   ' =====================================================================================
   PROPERTY GET EventRecord <1610743809> ( _            ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppRecord
   ' =====================================================================================
   METHOD AbortChange <1610743810> ( _                  ' VTable offset = 36
     OPTIONAL BYVAL lErrorCode AS LONG _                ' __in_opt LONG lErrorCode [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceURL <1610743811> ( _              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrURL
   ' =====================================================================================
   PROPERTY GET UserGuid <1610743812> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pvarUserGuid
   ' =====================================================================================
   PROPERTY GET StoreGuid <1610743813> ( _              ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pvarStoreGuid
   ' =====================================================================================
   PROPERTY GET UserSid <1610743814> ( _                ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSid
   ' =====================================================================================
   PROPERTY GET Data <1610743815> ( _                   ' VTable offset = 56
   ) AS LONG                                            ' __retval_out LONG_PTR *plData
   ' =====================================================================================
   PROPERTY SET Data <1610743815> ( _                   ' VTable offset = 60
     BYVAL plData AS LONG _                             ' __in LONG_PTR plData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreDispEventInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreEventRegistrationURL
' IID = {9DA0E117-86CE-11D1-8699-00C04FB98036}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IExStoreEventRegistrationURL_INTERFACE_DEFINED)
    %IExStoreEventRegistrationURL_INTERFACE_DEFINED = 1

INTERFACE IExStoreEventRegistrationURL $IID_IExStoreEventRegistrationURL

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventRegistrationURL <1610743808> ( _   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrURL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreEventRegistrationURL_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IStoreGuidFromUrl
' IID = {9DA0E10C-86CE-11D1-8699-00C04FB98036}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IStoreGuidFromUrl_INTERFACE_DEFINED)
    %IStoreGuidFromUrl_INTERFACE_DEFINED = 1

INTERFACE IStoreGuidFromUrl $IID_IStoreGuidFromUrl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StoreGuidFromUrl <1610743808> ( _             ' VTable offset = 28
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuid
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStoreGuidFromUrl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreEventLogonInfo
' IID = {9DA0E111-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreEventLogonInfo_INTERFACE_DEFINED)
    %IExStoreEventLogonInfo_INTERFACE_DEFINED = 1

INTERFACE IExStoreEventLogonInfo $IID_IExStoreEventLogonInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUserGuid ( _                               ' VTable offset = 12
     BYREF pguid AS GUID _                              ' __inout GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStoreGuid ( _                              ' VTable offset = 16
     BYREF pguid AS GUID _                              ' __inout GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserSid ( _                                ' VTable offset = 20
     BYVAL ppsid AS SID PTR _                           ' __out SID **ppsid _SID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreEventLogonInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGetSourceURL
' IID = {9DA0E10B-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetSourceURL_INTERFACE_DEFINED)
    %IGetSourceURL_INTERFACE_DEFINED = 1

INTERFACE IGetSourceURL $IID_IGetSourceURL

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSourceURL ( _                              ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out *pbstrURL VT_BSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetSourceURL_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGetLockRow
' IID = {9DA0E0EF-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetLockRow_INTERFACE_DEFINED)
    %IGetLockRow_INTERFACE_DEFINED = 1

INTERFACE IGetLockRow $IID_IGetLockRow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLockRow ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF pdwBindStatus AS DWORD _                     ' __out DWORD *pdwBindStatus
   , BYREF ppunkLockRow AS IUnknown _                   ' __out IUnknown **ppunkLockRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetLockRow_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAsyncNotify
' IID = {9DA0E10A-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAsyncNotify_INTERFACE_DEFINED)
    %IAsyncNotify_INTERFACE_DEFINED = 1

INTERFACE IAsyncNotify $IID_IAsyncNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Completed ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreAsyncEvents
' IID = {9DA0E0FE-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreAsyncEvents_INTERFACE_DEFINED)
    %IExStoreAsyncEvents_INTERFACE_DEFINED = 1

INTERFACE IExStoreAsyncEvents $IID_IExStoreAsyncEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSave ( _                                    ' VTable offset = 12
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDelete ( _                                  ' VTable offset = 16
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreAsyncEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreSyncEvents
' IID = {9DA0E0FF-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreSyncEvents_INTERFACE_DEFINED)
    %IExStoreSyncEvents_INTERFACE_DEFINED = 1

INTERFACE IExStoreSyncEvents $IID_IExStoreSyncEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSyncSave ( _                                ' VTable offset = 12
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSyncDelete ( _                              ' VTable offset = 16
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreSyncEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreSystemEvents
' IID = {9DA0E101-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreSystemEvents_INTERFACE_DEFINED)
    %IExStoreSystemEvents_INTERFACE_DEFINED = 1

INTERFACE IExStoreSystemEvents $IID_IExStoreSystemEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTimer ( _                                   ' VTable offset = 12
     BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMDBStartUp ( _                              ' VTable offset = 16
     BYVAL bstrMDBGuid AS WSTRING _                     ' __in BSTR bstrMDBGuid
   , BYVAL bstrMDBName AS WSTRING _                     ' __in BSTR bstrMDBName
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMDBShutDown ( _                             ' VTable offset = 20
     BYVAL bstrMDBGuid AS WSTRING _                     ' __in BSTR bstrMDBGuid
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreSystemEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExStoreLockEvents
' IID = {9DA0E10E-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExStoreLockEvents_INTERFACE_DEFINED)
    %IExStoreLockEvents_INTERFACE_DEFINED = 1

INTERFACE IExStoreLockEvents $IID_IExStoreLockEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSyncLock ( _                                ' VTable offset = 12
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSyncUnlock ( _                              ' VTable offset = 16
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExStoreLockEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUserData
' IID = {9DA0E116-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserData_INTERFACE_DEFINED)
    %IUserData_INTERFACE_DEFINED = 1

INTERFACE IUserData $IID_IUserData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYREF plData AS LONG _                             ' __out LONG_PTR *plData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 16
     BYVAL lData AS LONG _                              ' __in LONG_PTR lData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserData_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEventSinkIsCacheable
' IID = {9DA0E118-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEventSinkIsCacheable_INTERFACE_DEFINED)
    %IEventSinkIsCacheable_INTERFACE_DEFINED = 1

INTERFACE IEventSinkIsCacheable $IID_IEventSinkIsCacheable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsCacheable ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEventSinkIsCacheable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICreateRegistration
' IID = {9DA0E11C-86CE-11D1-8699-00C04FB98036}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateRegistration_INTERFACE_DEFINED)
    %ICreateRegistration_INTERFACE_DEFINED = 1

INTERFACE ICreateRegistration $IID_ICreateRegistration

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL pEventInfo AS IExStoreEventInfo _            ' __in IExStoreEventInfo *pEventInfo
   , BYVAL bstrURLItem AS WSTRING _                     ' __in BSTR bstrURLItem
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' __retval_out long *phr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateRegistration_INTERFACE_DEFINED__ */

'//
'// Place a "#define INITGUID" in just ONE of your projects source files BEFORE
'// including this header file to define the IIDs below.
'//

'//
'//   Bit flags passed to event handlers in the 'lFlags' parameter
'//

' enum EVT_SINK_FLAGS
%EVT_NEW_ITEM                   = &H1???
%EVT_IS_COLLECTION              = &H2???
%EVT_REPLICATED_ITEM            = &H4???
%EVT_IS_DELIVERED               = &H8???
%EVT_SYNC_BEGIN                 = &H1000000???
%EVT_SYNC_COMMITTED             = &H2000000???
%EVT_SYNC_ABORTED               = &H4000000???
%EVT_SOFTDELETE                 = &H10???
%EVT_HARDDELETE                 = &H20???
%EVT_INITNEW                    = &H40???
%EVT_MOVE                       = &H100???
%EVT_COPY                       = &H200???
%EVT_DRAFT_CREATE               = &H400???
%EVT_DRAFT_SAVE                 = &H800???
%EVT_DRAFT_CHECKIN              = &H1000???
%EVT_INVALID_SOURCE_URL         = &H20000000???
%EVT_INVALID_URL                = &H40000000???
%EVT_ERROR                      = &H80000000???
%EVT_LOCKTYPE_READ              = &H10000???
%EVT_LOCKTYPE_WRITE             = &H20000???
%EVT_LOCKTYPE_CHECKOUT          = &H40000???
%EVT_LOCKTYPE_READWRITE         = &H30000???
%EVT_LOCKSCOPE_SHARED           = &H80000???
%EVT_LOCKSCOPE_EXCLUSIVE        = &H100000???
%EVT_UNLOCK_CHECKIN_ABORT       = &H200000???
%EVT_UNLOCK_CHECKIN_KEEP_LOCKED = &H400000???
%EVT_LOCKDEPTH_DEEP             = &H800000???
%EVT_LOCK_TRANSIENT             = &H2000???

'//
'//   Event binding property names
'//
'// To register event, DAV:contentclass should have the following value
$$EVTPROPVAL_EVENTREG            = "urn:content-class:storeeventreg"$$

'// Required event registration properties
$$EVTPROP_EVENTMETHOD           = "http://schemas.microsoft.com/exchange/events/EventMethod"$$
%EVTPROP_EVENTMETHOD_TYPE       = %DBTYPE_WSTR
'#define   EVTPROP_SINKCLASS              L"http://schemas.microsoft.com/exchange/events/SinkClass"
$$EVTPROP_SINKCLASS             = "http://schemas.microsoft.com/exchange/events/SinkClass"$$
%EVTPROP_SINKCLASS_TYPE         = %DBTYPE_WSTR

'// Optional event registration properties
$$EVTPROP_PRIORITY              = "http://schemas.microsoft.com/exchange/events/Priority"$$
%EVTPROP_PRIORITY_TYPE          = %DBTYPE_I4
$$EVTPROP_MATCHSCOPE            = "http://schemas.microsoft.com/exchange/events/MatchScope"$$
%EVTPROP_MATCHSCOPE_TYPE        = %DBTYPE_WSTR
$$EVTPROP_CRITERIA              = "http://schemas.microsoft.com/exchange/events/Criteria"$$
%EVTPROP_CRITERIA_TYPE          = %DBTYPE_WSTR
$$EVTPROP_TIMERINTERVAL         = "http://schemas.microsoft.com/exchange/events/TimerInterval"$$
%EVTPROP_TIMERINTERVAL_TYPE     = %DBTYPE_I4
$$EVTPROP_TIMERSTARTTIME        = "http://schemas.microsoft.com/exchange/events/TimerStartTime"$$
%EVTPROP_TIMERSTARTTIME_TYPE    = %DBTYPE_FILETIME
$$EVTPROP_TIMEREXPIRYTIME       = "http://schemas.microsoft.com/exchange/events/TimerExpiryTime"$$
%EVTPROP_TIMEREXPIRYTIME_TYPE   = %DBTYPE_FILETIME
$$EVTPROP_SCRIPTURL             = "http://schemas.microsoft.com/exchange/events/ScriptUrl"$$
%EVTPROP_SCRIPTURL_TYPE         = %DBTYPE_WSTR
$$EVTPROP_ENABLED               = "http://schemas.microsoft.com/exchange/events/Enabled"$$
%EVTPROP_ENABLED_TYPE           = %DBTYPE_BOOL

'//
'//   EVTPROP_MATCHSCOPE parameter values
'//
$$EVT_MATCHSCOPE_DEEP           = "DEEP"$$
$$EVT_MATCHSCOPE_SHALLOW        = "SHALLOW"$$
$$EVT_MATCHSCOPE_EXACT          = "EXACT"$$
$$EVT_MATCHSCOPE_ANY            = "ANY"$$

'//
'//   Event names for the EVTPROP_EVENTMETHOD property
'//
$$EVT_ON_SAVE                   = "OnSave"$$
$$EVT_ON_DELETE                 = "OnDelete"$$
$$EVT_ON_TIMER                  = "OnTimer"$$
$$EVT_ON_MDB_STARTUP            = "OnMDBStartUp"$$
$$EVT_ON_MDB_SHUTDOWN           = "OnMDBShutDown"$$
$$EVT_ON_SYNC_SAVE              = "OnSyncSave"$$
$$EVT_ON_SYNC_DELETE            = "OnSyncDelete"$$
$$EVT_ON_SYNC_LOCK              = "OnSyncLock"$$
$$EVT_ON_SYNC_UNLOCK            = "OnSyncUnlock"$$

'//
'// Return code for Reliable async event
%S_PENDING = &H00000002&
'//
'//
'// Return code for IEventSinkIsCacheable
%S_CACHE_PER_BINDING = %S_OK
