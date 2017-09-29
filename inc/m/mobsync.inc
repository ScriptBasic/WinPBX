' ########################################################################################
' Microsoft Windows
' File: mobsync.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SyncObjects
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Legacy Sync Objects
' Library GUID: {6E586F48-379C-459C-9BEB-624A7E8316EB}
' ########################################################################################

#INCLUDE THIS ONCE
%MOBSYNC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "shobjidl.inc"

'#define SYNCMGRITEMID        GUID
'#define REFSYNCMGRITEMID     REFGUID
'#define SYNCMGRERRORID       GUID
'#define REFSYNCMGRERRORID    REFGUID

%S_SYNCMGR_MISSINGITEMS = &H00040201???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0201)
%S_SYNCMGR_RETRYSYNC    = &H00040202???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0202)
%S_SYNCMGR_CANCELITEM   = &H00040203???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0203)
%S_SYNCMGR_CANCELALL    = &H00040204???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0204)
%S_SYNCMGR_ITEMDELETED  = &H00040210???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0210)
%S_SYNCMGR_ENUMITEMS    = &H00040211???   ' MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0211)

$LIBID_SyncObjects = GUID$("{6E586F48-379C-459C-9BEB-624A7E8316EB}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SyncMgr = GUID$("{6295DF27-35EE-11D1-8707-00C04FD93327}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISyncMgrEnumItems = GUID$("{6295DF2A-35EE-11d1-8707-00C04FD93327}")
$IID_ISyncMgrSynchronizeCallback = GUID$("{6295DF41-35EE-11D1-8707-00C04FD93327}")
$IID_ISyncMgrSynchronize = GUID$("{6295DF40-35EE-11d1-8707-00C04FD93327}")
$IID_ISyncMgrSynchronizeInvoke = GUID$("{6295DF2C-35EE-11D1-8707-00C04FD93327}")
$IID_ISyncMgrRegister = GUID$("{6295DF42-35EE-11D1-8707-00C04FD93327}")

' ########################################################################################
' Interface name = ISyncMgrSynchronizeCallback
' IID = 6295DF41-35EE-11d1-8707-00C04FD93327
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSynchronizeCallback_INTERFACE_DEFINED)
    %ISyncMgrSynchronizeCallback_INTERFACE_DEFINED = 1

%SYNCMGRPROGRESSITEM_STATUSTEXT = &H0001???
%SYNCMGRPROGRESSITEM_STATUSTYPE = &H0002???
%SYNCMGRPROGRESSITEM_PROGVALUE  = &H0004???
%SYNCMGRPROGRESSITEM_MAXVALUE   = &H0008???

' enum SYNCMGRSTATUS
%SYNCMGRSTATUS_STOPPED                = 0???
%SYNCMGRSTATUS_SKIPPED                = &H1???
%SYNCMGRSTATUS_PENDING                = &H2???
%SYNCMGRSTATUS_UPDATING               = &H3???
%SYNCMGRSTATUS_SUCCEEDED              = &H4???
%SYNCMGRSTATUS_FAILED                 = &H5???
%SYNCMGRSTATUS_PAUSED                 = &H6???
%SYNCMGRSTATUS_RESUMING               = &H7???
%SYNCMGRSTATUS_UPDATING_INDETERMINATE = &H8???
%SYNCMGRSTATUS_DELETED                = &H100???

' // Size = 24 bytes
TYPE SYNCMGRPROGRESSITEM DWORD
   cbSize        AS DWORD          ' DWORD
   mask          AS DWORD          ' UINT
   lpcStatusText AS WSTRINGZ PTR   ' LPCWSTR
   dwStatusType  AS DWORD          ' DWORD
   iProgValue    AS LONG           ' int
   iMaxValue     AS LONG           ' int
END TYPE

' enum SYNCMGRLOGLEVEL
%SYNCMGRLOGLEVEL_INFORMATION = &H1
%SYNCMGRLOGLEVEL_WARNING     = &H2
%SYNCMGRLOGLEVEL_ERROR       = &H3
%SYNCMGRLOGLEVEL_LOGLEVELMAX = &H3

%SYNCMGRLOGERROR_ERRORFLAGS = &H0001???
%SYNCMGRLOGERROR_ERRORID    = &H0002???
%SYNCMGRLOGERROR_ITEMID     = &H0004???

' enum SYNCMGRERRORFLAGS
%SYNCMGRERRORFLAG_ENABLEJUMPTEXT = &H1???

' // Size = 44 bytes
TYPE SYNCMGRLOGERRORINFO DWORD
   cbSize              AS DWORD   ' DWORD
   mask                AS DWORD   ' DWORD
   dwSyncMgrErrorFlags AS DWORD   ' DWORD
   ErrorID             AS GUID    ' GUID
   ItemID              AS GUID    ' GUID
END TYPE

INTERFACE ISyncMgrSynchronizeCallback $IID_ISyncMgrSynchronizeCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowPropertiesCompleted ( _                   ' VTable offset = 12
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareForSyncCompleted ( _                   ' VTable offset = 16
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SynchronizeCompleted ( _                      ' VTable offset = 20
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowErrorCompleted ( _                        ' VTable offset = 24
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   , BYREF pItemIDs AS GUID _                           ' __in const GUID *pItemIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 28
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Progress ( _                                  ' VTable offset = 32
     BYREF ItemID AS GUID _                             ' __in REFGUID ItemID
   , BYREF pSyncProgressItem AS SYNCMGRPROGRESSITEM _   ' __in const SYNCMGRPROGRESSITEM *pSyncProgressItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogError ( _                                  ' VTable offset = 36
     BYVAL dwErrorLevel AS DWORD _                      ' __in DWORD dwErrorLevel
   , BYREF pszErrorText AS WSTRINGZ _                   ' __in LPCWSTR pszErrorText
   , BYREF pSyncLogError AS SYNCMGRLOGERRORINFO _       ' __in const SYNCMGRLOGERRORINFO *pSyncLogError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteLogError ( _                            ' VTable offset = 40
     BYREF ErrorID AS GUID _                            ' __in REFGUID ErrorID
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EstablishConnection ( _                       ' VTable offset = 44
     BYREF pwszConnection AS WSTRINGZ _                 ' __in LPCWSTR pwszConnection
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSynchronizeCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISyncMgrEnumItems
' IID = 6295DF2A-35EE-11D1-8707-00C04FD93327
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrEnumItems_INTERFACE_DEFINED)
    %ISyncMgrEnumItems_INTERFACE_DEFINED = 1

' enum SYNCMGRITEMFLAGS
%SYNCMGRITEM_HASPROPERTIES  = &H1
%SYNCMGRITEM_TEMPORARY      = &H2
%SYNCMGRITEM_ROAMINGUSER    = &H4
%SYNCMGRITEM_LASTUPDATETIME = &H8
%SYNCMGRITEM_MAYDELETEITEM  = &H10
%SYNCMGRITEM_HIDDEN         = &H20

%SYNCMGRITEM_ITEMFLAGMASK = &H007F???
%MAX_SYNCMGRITEMNAME = 128

' // Size = 296 bytes
TYPE SYNCMGRITEM DWORD
   cbSize       AS DWORD            ' DWORD
   dwFlags      AS DWORD            ' DWORD
   ItemID       AS GUID             ' GUID
   dwItemState  AS DWORD            ' DWORD
   hIcon        AS DWORD            ' HICON
   wszItemName  AS WSTRINGZ * 128   ' WCHAR wszItemName[128]
   ftLastUpdate AS FILETIME         ' FILETIME
END TYPE

INTERFACE ISyncMgrEnumItems $IID_ISyncMgrEnumItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS SYNCMGRITEM _                       ' __out SYNCMGRITEM *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS ISyncMgrEnumItems _                ' __out ISyncMgrEnumItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrEnumItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISyncMgrSynchronize
' IID = 6295DF40-35EE-11d1-8707-00C04FD93327
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSynchronize_INTERFACE_DEFINED)
    %ISyncMgrSynchronize_INTERFACE_DEFINED = 1

' enum SYNCMGRFLAG
%SYNCMGRFLAG_CONNECT           = &H1???
%SYNCMGRFLAG_PENDINGDISCONNECT = &H2???
%SYNCMGRFLAG_MANUAL            = &H3???
%SYNCMGRFLAG_IDLE              = &H4???
%SYNCMGRFLAG_INVOKE            = &H5???
%SYNCMGRFLAG_SCHEDULED         = &H6???
%SYNCMGRFLAG_EVENTMASK         = &Hff???
%SYNCMGRFLAG_SETTINGS          = &H100???
%SYNCMGRFLAG_MAYBOTHERUSER     = &H200???

' enum SYNCMGRHANDLERFLAGS
%SYNCMGRHANDLER_HASPROPERTIES          = &H1
%SYNCMGRHANDLER_MAYESTABLISHCONNECTION = &H2
%SYNCMGRHANDLER_ALWAYSLISTHANDLER      = &H4
%SYNCMGRHANDLER_HIDDEN                 = &H8

%SYNCMGRHANDLERFLAG_MASK = &H000f???
%MAX_SYNCMGRHANDLERNAME = 32

' // Size = 76 bytes
TYPE SYNCMGRHANDLERINFO DWORD
   cbSize              AS DWORD           ' DWORD
   hIcon               AS DWORD           ' HICON
   SyncMgrHandlerFlags AS DWORD           ' DWORD
   wszHandlerName      AS WSTRINGZ * 32   ' WCHAR wszHandlerName[32]
END TYPE

' enum SYNCMGRITEMSTATE
%SYNCMGRITEMSTATE_UNCHECKED = 0???
%SYNCMGRITEMSTATE_CHECKED   = &H1???

INTERFACE ISyncMgrSynchronize $IID_ISyncMgrSynchronize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL dwSyncMgrFlags AS DWORD _                    ' __in DWORD dwSyncMgrFlags
   , BYVAL cbCookie AS DWORD _                          ' __in DWORD cbCookie
   , BYVAL lpCookie AS BYTE PTR _                       ' __in const BYTE *lpCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandlerInfo ( _                            ' VTable offset = 16
     BYREF ppSyncMgrHandlerInfo AS SYNCMGRHANDLERINFO _ ' __out SYNCMGRHANDLERINFO **ppSyncMgrHandlerInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSyncMgrItems ( _                          ' VTable offset = 20
     BYREF ppSyncMgrEnumItems AS ISyncMgrEnumItems _    ' __out ISyncMgrEnumItems **ppSyncMgrEnumItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemObject ( _                             ' VTable offset = 24
     BYREF ItemID AS GUID _                             ' __in REFGUID ItemID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowProperties ( _                            ' VTable offset = 28
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF ItemID AS GUID _                             ' __in REFGUID ItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressCallback ( _                       ' VTable offset = 32
     BYVAL lpCallBack AS DWORD _                        ' __in ISyncMgrSynchronizeCallback *lpCallBack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareForSync ( _                            ' VTable offset = 36
     BYVAL cbNumItems AS DWORD _                        ' __in ULONG cbNumItems
   , BYREF pItemIDs AS GUID _                           ' __in GUID *pItemIDs
   , BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Synchronize ( _                               ' VTable offset = 40
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemStatus ( _                             ' VTable offset = 44
     BYREF pItemID AS GUID _                            ' __in REFGUID pItemID
   , BYVAL dwSyncMgrStatus AS DWORD _                   ' __in DWORD dwSyncMgrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowError ( _                                 ' VTable offset = 48
     BYVAL hWndParent AS DWORD _                        ' __in HWND hWndParent
   , BYREF ErrorID AS GUID _                            ' __in REFGUID ErrorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSynchronize_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISyncMgrSynchronizeInvoke
' IID = {6295DF2C-35EE-11D1-8707-00C04FD93327}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED)
    %ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED = 1

' enum SYNCMGRINVOKEFLAGS
%SYNCMGRINVOKE_STARTSYNC = &H2???
%SYNCMGRINVOKE_MINIMIZED = &H4???

INTERFACE ISyncMgrSynchronizeInvoke $IID_ISyncMgrSynchronizeInvoke

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UpdateItems ( _                               ' VTable offset = 12
     BYVAL dwInvokeFlags AS DWORD _                     ' __in DWORD dwInvokeFlags
   , BYREF clsid AS GUID _                              ' __in REFCLSID *clsid
   , BYVAL cbCookie AS DWORD _                          ' __in DWORD cbCookie
   , BYVAL pCookie AS BYTE PTR _                        ' __in const BYTE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAll ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSynchronizeInvoke_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISyncMgrRegister
' IID = 6295DF42-35EE-11D1-8707-00C04FD93327
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrRegister_INTERFACE_DEFINED)
    %ISyncMgrRegister_INTERFACE_DEFINED = 1

' enum SYNCMGRREGISTERFLAGS
%SYNCMGRREGISTERFLAG_CONNECT           = &H1???
%SYNCMGRREGISTERFLAG_PENDINGDISCONNECT = &H2???
%SYNCMGRREGISTERFLAG_IDLE              = &H4???

%SYNCMGRREGISTERFLAGS_MASK = &H07???

INTERFACE ISyncMgrRegister $IID_ISyncMgrRegister

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterSyncMgrHandler ( _                    ' VTable offset = 12
     BYREF clsidHandler AS GUID _                       ' __in REFCLSID clsidHandler
   , BYREF pwszDescription AS WSTRINGZ _                ' __in LPCWSTR pwszDescription
   , BYVAL dwSyncMgrRegisterFlags AS DWORD _            ' __in DWORD dwSyncMgrRegisterFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterSyncMgrHandler ( _                  ' VTable offset = 16
     BYREF clsidHandler AS GUID _                       ' __in REFCLSID clsidHandler
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandlerRegistrationInfo ( _                ' VTable offset = 20
     BYREF clsidHandler AS GUID _                       ' __in REFCLSID clsidHandler
   , BYREF pdwSyncMgrRegisterFlags AS DWORD _           ' __out LPDWORD pdwSyncMgrRegisterFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrRegister_INTERFACE_DEFINED__ */
