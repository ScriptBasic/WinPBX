' ########################################################################################
' Microsoft Windows
' File: SyncMgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SyncMgrObjects
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Sync Center Objects
' Library GUID: {BFF8075E-5A75-4C59-B35A-BD4804636DD4}
' ########################################################################################

#INCLUDE THIS ONCE
%SYNCMGR_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "shobjidl.inc"
#INCLUDE ONCE "Ole2Utils.inc"

%MAX_SYNCMGR_ID           = 64
%MAX_SYNCMGR_PROGRESSTEXT = 260
%MAX_SYNCMGR_NAME         = 128

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ConflictFolder = GUID$("{289978AC-A101-4341-A817-21EBA7FD046D}")
$CLSID_SimpleConflictPresenter = GUID$("{7A0F6AB7-ED84-46B6-B47E-02AA159A152B}")
$CLSID_SyncMgrClient = GUID$("{1202DB60-1DAC-42C5-AED5-1ABDD432248E}")
$CLSID_SyncMgrControl = GUID$("{1A1F4206-0688-4E7F-BE03-D82EC69DF9A5}")
$CLSID_SyncMgrFolder = GUID$("{9C73F5E5-7AE7-4E32-A8E8-8D23B85255BF}")
$CLSID_SyncMgrScheduleWizard = GUID$("{8D8B8E30-C451-421B-8553-D2976AFA648C}")
$CLSID_SyncResultsFolder = GUID$("{71D99464-3B6B-475C-B241-E15883207529}")
$CLSID_SyncSetupFolder = GUID$("{2E9E59C0-B437-4981-A647-9C34B9B90891}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISyncMgrHandlerCollection = GUID$("{A7F337A3-D20B-45CB-9ED7-87D094CA5045}")
$IID_ISyncMgrHandler = GUID$("{04EC2E43-AC77-49F9-9B98-0307EF7A72A2}")
$IID_ISyncMgrHandlerInfo = GUID$("{4FF1D798-ECF7-4524-AA81-1E362A0AEF3A}")
$IID_ISyncMgrSyncItemContainer = GUID$("{90701133-BE32-4129-A65C-99E616CAFFF4}")
$IID_ISyncMgrSyncItem = GUID$("{B20B24CE-2593-4F04-BD8B-7AD6C45051CD}")
$IID_ISyncMgrSyncItemInfo = GUID$("{E7FD9502-BE0C-4464-90A1-2B5277031232}")
$IID_IEnumSyncMgrSyncItems = GUID$("{54B3ABF3-F085-4181-B546-E29C403C726B}")
$IID_ISyncMgrSessionCreator = GUID$("{17F48517-F305-4321-A08D-B25A834918FD}")
$IID_ISyncMgrSyncCallback = GUID$("{884CCD87-B139-4937-A4BA-4F8E19513FBE}")
$IID_ISyncMgrUIOperation = GUID$("{FC7CFA47-DFE1-45B5-A049-8CFD82BEC271}")
$IID_ISyncMgrEventLinkUIOperation = GUID$("{64522E52-848B-4015-89CE-5A36F00B94FF}")
$IID_ISyncMgrScheduleWizardUIOperation = GUID$("{459A6C84-21D2-4DDC-8A53-F023A46066F2}")
$IID_ISyncMgrSyncResult = GUID$("{2B90F17E-5A3E-4B33-BB7F-1BC48056B94D}")
$IID_ISyncMgrControl = GUID$("{9B63616C-36B2-46BC-959F-C1593952D19B}")
$IID_ISyncMgrEventStore = GUID$("{37E412F9-016E-44C2-81FF-DB3ADD774266}")
$IID_ISyncMgrEvent = GUID$("{FEE0EF8B-46BD-4DB4-B7E6-FF2C687313BC}")
$IID_IEnumSyncMgrEvents = GUID$("{C81A1D4E-8CF7-4683-80E0-BCAE88D677B6}")
$IID_ISyncMgrConflictStore = GUID$("{CF8FC579-C396-4774-85F1-D908A831156E}")
$IID_IEnumSyncMgrConflict = GUID$("{82705914-DDA3-4893-BA99-49DE6C8C8036}")
$IID_ISyncMgrConflict = GUID$("{9C204249-C443-4BA4-85ED-C972681DB137}")
$IID_ISyncMgrResolutionHandler = GUID$("{40A3D052-8BFF-4C4B-A338-D4A395700DE9}")
$IID_ISyncMgrConflictPresenter = GUID$("{0B4F5353-FD2B-42CD-8763-4779F2D508A3}")
$IID_ISyncMgrConflictResolveInfo = GUID$("{C405A219-25A2-442E-8743-B845A2CEE93F}")
$IID_ISyncMgrConflictFolder = GUID$("{59287F5E-BC81-4FCA-A7F1-E5A8ECDB1D69}")
$IID_ISyncMgrConflictItems = GUID$("{9C7EAD52-8023-4936-A4DB-D2A9A99E436A}")
$IID_ISyncMgrConflictResolutionItems = GUID$("{458725B9-129D-4135-A998-9CEAFEC27007}")

' ########################################################################################
' ISyncMgrHandlerCollection interface
' IID = A7F337A3-D20B-45CB-9ED7-87D094CA5045
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrHandlerCollection_INTERFACE_DEFINED)
    %ISyncMgrHandlerCollection_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrHandlerCollection $IID_ISyncMgrHandlerCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHandlerEnumerator ( _                      ' VTable offset = 12
     BYREF ppenum AS IEnumString _                      ' __out IEnumString **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToHandler ( _                             ' VTable offset = 16
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrHandlerCollection_INTERFACE_DEFINED__ */

' enum SYNCMGR_HANDLER_CAPABILITIES
%SYNCMGR_HCM_NONE                         = 0???
%SYNCMGR_HCM_PROVIDES_ICON                = &H1???
%SYNCMGR_HCM_EVENT_STORE                  = &H2???
%SYNCMGR_HCM_CONFLICT_STORE               = &H4???
%SYNCMGR_HCM_SUPPORTS_CONCURRENT_SESSIONS = &H10???
%SYNCMGR_HCM_CAN_BROWSE_CONTENT           = &H10000???
%SYNCMGR_HCM_CAN_SHOW_SCHEDULE            = &H20000???
%SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE        = &H100000???
%SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE      = &H200000???
%SYNCMGR_HCM_QUERY_BEFORE_ENABLE          = &H400000???
%SYNCMGR_HCM_QUERY_BEFORE_DISABLE         = &H800000???
%SYNCMGR_HCM_VALID_MASK                   = &Hf30017???

' enum %SYNCMGR_HANDLER_POLICIES
%SYNCMGR_HPM_NONE                         = 0???
%SYNCMGR_HPM_PREVENT_ACTIVATE             = &H1???
%SYNCMGR_HPM_PREVENT_DEACTIVATE           = &H2???
%SYNCMGR_HPM_PREVENT_ENABLE               = &H4???
%SYNCMGR_HPM_PREVENT_DISABLE              = &H8???
%SYNCMGR_HPM_PREVENT_START_SYNC           = &H10???
%SYNCMGR_HPM_PREVENT_STOP_SYNC            = &H20???
%SYNCMGR_HPM_DISABLE_ENABLE               = &H100???
%SYNCMGR_HPM_DISABLE_DISABLE              = &H200???
%SYNCMGR_HPM_DISABLE_START_SYNC           = &H400???
%SYNCMGR_HPM_DISABLE_STOP_SYNC            = &H800???
%SYNCMGR_HPM_DISABLE_BROWSE               = &H1000???
%SYNCMGR_HPM_DISABLE_SCHEDULE             = &H2000???
%SYNCMGR_HPM_HIDDEN_BY_DEFAULT            = &H10000???
%SYNCMGR_HPM_BACKGROUND_SYNC_ONLY         = %SYNCMGR_HPM_PREVENT_START_SYNC OR %SYNCMGR_HPM_PREVENT_STOP_SYNC
%SYNCMGR_HPM_VALID_MASK                   = &H12f3f???


' ########################################################################################
' ISyncMgrHandler interface
' IID = 04EC2E43-AC77-49F9-9B98-0307EF7A72A2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrHandler_INTERFACE_DEFINED)
    %ISyncMgrHandler_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrHandler $IID_ISyncMgrHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandlerInfo ( _                            ' VTable offset = 16
     BYREF ppHandlerInfo AS ISyncMgrHandlerInfo _       ' __out ISyncMgrHandlerInfo **ppHandlerInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 20
     BYREF rguidObjectID AS GUID _                      ' __in REFGUID rguidObjectID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 24
     BYREF pmCapabilities AS DWORD _                    ' __out SYNCMGR_HANDLER_CAPABILITIES *pmCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicies ( _                               ' VTable offset = 28
     BYREF pmPolicies AS DWORD _                        ' __out SYNCMGR_HANDLER_POLICIES *pmPolicies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 32
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 36
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Synchronize ( _                               ' VTable offset = 40
     BYVAL ppszItemIDs AS DWORD _                       ' __in LPCWSTR *ppszItemIDs
   , BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL pSessionCreator AS ISyncMgrSessionCreator _  ' __in ISyncMgrSessionCreator *pSessionCreator
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrHandler_INTERFACE_DEFINED__ */


' enum SYNCMGR_HANDLER_TYPE
%SYNCMGR_HT_UNSPECIFIED = 0
%SYNCMGR_HT_APPLICATION = 1
%SYNCMGR_HT_DEVICE      = 2
%SYNCMGR_HT_FOLDER      = 3
%SYNCMGR_HT_SERVICE     = 4
%SYNCMGR_HT_COMPUTER    = 5
%SYNCMGR_HT_MIN         = 0
%SYNCMGR_HT_MAX         = %SYNCMGR_HT_COMPUTER


' ########################################################################################
' ISyncMgrHandlerInfo interface
' IID = 4FF1D798-ECF7-4524-AA81-1E362A0AEF3A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrHandlerInfo_INTERFACE_DEFINED)
    %ISyncMgrHandlerInfo_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrHandlerInfo $IID_ISyncMgrHandlerInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pnType AS LONG _                             ' __out SYNCMGR_HANDLER_TYPE *pnType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeLabel ( _                              ' VTable offset = 16
     BYREF ppszTypeLabel AS DWORD _                     ' __out LPWSTR *ppszTypeLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComment ( _                                ' VTable offset = 20
     BYREF ppszComment AS DWORD _                       ' __out LPWSTR *ppszComment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastSyncTime ( _                           ' VTable offset = 24
     BYREF pftLastSync AS FILETIME _                    ' __out FILETIME *pftLastSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEnabled ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrHandlerInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrSyncItemContainer interface
' IID = 90701133-BE32-4129-A65C-99E616CAFFF4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSyncItemContainer_INTERFACE_DEFINED)
    %ISyncMgrSyncItemContainer_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSyncItemContainer $IID_ISyncMgrSyncItemContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSyncItem ( _                               ' VTable offset = 12
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYREF ppItem AS ISyncMgrSyncItem _                 ' __out ISyncMgrSyncItem **ppItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncItemEnumerator ( _                     ' VTable offset = 16
     BYREF ppenum AS IEnumSyncMgrSyncItems _            ' __out IEnumSyncMgrSyncItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncItemCount ( _                          ' VTable offset = 20
     BYREF pcItems AS DWORD _                           ' __out ULONG *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSyncItemContainer_INTERFACE_DEFINED__ */


' enum SYNCMGR_ITEM_CAPABILITIES
%SYNCMGR_ICM_NONE                 = 0???
%SYNCMGR_ICM_PROVIDES_ICON        = &H1???
%SYNCMGR_ICM_EVENT_STORE          = &H2???
%SYNCMGR_ICM_CONFLICT_STORE       = &H4???
%SYNCMGR_ICM_CAN_DELETE           = &H10???
%SYNCMGR_ICM_CAN_BROWSE_CONTENT   = &H10000???
%SYNCMGR_ICM_QUERY_BEFORE_ENABLE  = &H100000???
%SYNCMGR_ICM_QUERY_BEFORE_DISABLE = &H200000???
%SYNCMGR_ICM_QUERY_BEFORE_DELETE  = &H400000???
%SYNCMGR_ICM_VALID_MASK           = &H710017???

' enum SYNCMGR_ITEM_POLICIES
%SYNCMGR_IPM_NONE                 = 0???
%SYNCMGR_IPM_PREVENT_ENABLE       = &H1???
%SYNCMGR_IPM_PREVENT_DISABLE      = &H2???
%SYNCMGR_IPM_PREVENT_START_SYNC   = &H4???
%SYNCMGR_IPM_PREVENT_STOP_SYNC    = &H8???
%SYNCMGR_IPM_DISABLE_ENABLE       = &H10???
%SYNCMGR_IPM_DISABLE_DISABLE      = &H20???
%SYNCMGR_IPM_DISABLE_START_SYNC   = &H40???
%SYNCMGR_IPM_DISABLE_STOP_SYNC    = &H80???
%SYNCMGR_IPM_DISABLE_BROWSE       = &H100???
%SYNCMGR_IPM_DISABLE_DELETE       = &H200???
%SYNCMGR_IPM_HIDDEN_BY_DEFAULT    = &H10000???
%SYNCMGR_IPM_VALID_MASK           = &H102ff???


' ########################################################################################
' ISyncMgrSyncItem interface
' IID = B20B24CE-2593-4F04-BD8B-7AD6C45051CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSyncItem_INTERFACE_DEFINED)
    %ISyncMgrSyncItem_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSyncItem $IID_ISyncMgrSyncItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItemID ( _                                 ' VTable offset = 12
     BYREF ppszItemID AS DWORD _                        ' __out LPWSTR *ppszItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemInfo ( _                               ' VTable offset = 20
     BYREF ppItemInfo AS ISyncMgrSyncItemInfo _         ' __out ISyncMgrSyncItemInfo *ppItemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 24
     BYREF rguidObjectID AS GUID _                      ' __in REFGUID rguidObjectID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 28
     BYREF pmCapabilities AS DWORD _                    ' __out SYNCMGR_ITEM_CAPABILITIES *pmCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicies ( _                               ' VTable offset = 32
     BYREF pmPolicies AS DWORD _                        ' __out SYNCMGR_ITEM_POLICIES *pmPolicies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 36
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSyncItem_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrSyncItemInfo interface
' IID = E7FD9502-BE0C-4464-90A1-2B5277031232
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSyncItemInfo_INTERFACE_DEFINED)
    %ISyncMgrSyncItemInfo_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSyncItemInfo $IID_ISyncMgrSyncItemInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTypeLabel ( _                              ' VTable offset = 12
     BYREF ppszTypeLabel AS DWORD _                     ' __out LPWSTR *ppszTypeLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetComment ( _                                ' VTable offset = 16
     BYREF ppszComment AS DWORD _                       ' __out LPWSTR *ppszComment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastSyncTime ( _                           ' VTable offset = 20
     BYREF pftLastSync AS FILETIME _                    ' __out FILETIME *pftLastSync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEnabled ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSyncItemInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumSyncMgrSyncItems interface
' IID = 54B3ABF3-F085-4181-B546-E29C403C726B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSyncMgrSyncItems_INTERFACE_DEFINED)
    %IEnumSyncMgrSyncItems_INTERFACE_DEFINED = 1

INTERFACE IEnumSyncMgrSyncItems $IID_IEnumSyncMgrSyncItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS ISyncMgrSyncItem _                  ' __out ISyncMgrSyncItem **rgelt
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
     BYREF ppenum AS IEnumSyncMgrSyncItems _            ' __out IEnumSyncMgrSyncItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSyncMgrSyncItems_INTERFACE_DEFINED__ */


' enum SYNCMGR_PROGRESS_STATUS
%SYNCMGR_PS_UPDATING               = 1
%SYNCMGR_PS_UPDATING_INDETERMINATE = 2
%SYNCMGR_PS_SUCCEEDED              = 3
%SYNCMGR_PS_FAILED                 = 4
%SYNCMGR_PS_CANCELED               = 5
%SYNCMGR_PS_DISCONNECTED           = 6
%SYNCMGR_PS_MAX                    = %SYNCMGR_PS_DISCONNECTED

' enum SYNCMGR_CANCEL_REQUEST
%SYNCMGR_CR_NONE                   = 0
%SYNCMGR_CR_CANCEL_ITEM            = 1
%SYNCMGR_CR_CANCEL_ALL             = 2
%SYNCMGR_CR_MAX                    = %SYNCMGR_CR_CANCEL_ALL

' enum SYNCMGR_EVENT_LEVEL
%SYNCMGR_EL_INFORMATION            = 1
%SYNCMGR_EL_WARNING                = 2
%SYNCMGR_EL_ERROR                  = 3
%SYNCMGR_EL_MAX                    = %SYNCMGR_EL_ERROR

' enum SYNCMGR_EVENT_FLAGS
%SYNCMGR_EF_NONE                   = 0
%SYNCMGR_EF_VALID                  = 0


' ########################################################################################
' ISyncMgrSessionCreator interface
' IID = 17F48517-F305-4321-A08D-B25A834918FD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSessionCreator_INTERFACE_DEFINED)
    %ISyncMgrSessionCreator_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSessionCreator $IID_ISyncMgrSessionCreator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateSession ( _                             ' VTable offset = 12
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF ppszItemIDs AS WSTRINGZ _                    ' __in LPCWSTR *ppszItemIDs
   , BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   , BYREF ppCallback AS ISyncMgrSyncCallback _         ' __out ISyncMgrSyncCallback **ppCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSessionCreator_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrSyncCallback interface
' IID = 884CCD87-B139-4937-A4BA-4F8E19513FBE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSyncCallback_INTERFACE_DEFINED)
    %ISyncMgrSyncCallback_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSyncCallback $IID_ISyncMgrSyncCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReportProgress ( _                            ' VTable offset = 12
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYREF pszProgressText AS WSTRINGZ _                ' __in LPCWSTR pszProgressText
   , BYVAL nStatus AS LONG _                            ' __in SYNCMGR_PROGRESS_STATUS nStatus
   , BYVAL uCurrentStep AS DWORD _                      ' __in ULONG uCurrentStep
   , BYVAL uMaxStep AS DWORD _                          ' __in ULONG uMaxStep
   , BYREF pnCancelRequest AS LONG _                    ' __in_out SYNCMGR_CANCEL_REQUEST *pnCancelRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHandlerProgressText ( _                    ' VTable offset = 16
     BYREF pszProgressText AS WSTRINGZ _                ' __in LPCWSTR pszProgressText
   , BYREF pnCancelRequest AS LONG _                    ' __in_out SYNCMGR_CANCEL_REQUEST *pnCancelRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportEvent ( _                               ' VTable offset = 20
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL nLevel AS LONG _                             ' __in SYNCMGR_EVENT_LEVEL nLevel
   , BYVAL nFlags AS DWORD _                            ' __in SYNCMGR_EVENT_FLAGS nFlags
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszDescription AS WSTRINGZ _                 ' __in LPCWSTR pszDescription
   , BYREF pszLinkText AS WSTRINGZ _                    ' __in LPCWSTR pszLinkText
   , BYREF pszLinkReference AS WSTRINGZ _               ' __in LPCWSTR pszLinkReference
   , BYREF pszContext AS WSTRINGZ _                     ' __in LPCWSTR pszContext
   , BYREF pguidEventID AS GUID _                       ' __out GUID *pguidEventID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanContinue ( _                               ' VTable offset = 24
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryForAdditionalItems ( _                   ' VTable offset = 28
     BYREF ppenumItemIDs AS IEnumString _               ' __out IEnumString **ppenumItemIDs
   , BYREF ppenumPunks AS IEnumUnknown _                ' __out IEnumUnknown **ppenumPunks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddItemToSession ( _                          ' VTable offset = 32
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddIUnknownToSession ( _                      ' VTable offset = 36
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProposeItem ( _                               ' VTable offset = 40
     BYVAL pNewItem AS ISyncMgrSyncItem _               ' __in ISyncMgrSyncItem *pNewItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitItem ( _                                ' VTable offset = 44
     BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReportManualSync ( _                          ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSyncCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrUIOperation interface
' IID = FC7CFA47-DFE1-45B5-A049-8CFD82BEC271
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrUIOperation_INTERFACE_DEFINED)
    %ISyncMgrUIOperation_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrUIOperation $IID_ISyncMgrUIOperation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 12
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrUIOperation_INTERFACE_DEFINED__ */


' ########################################################################################
' ISyncMgrEventLinkUIOperation interface
' IID = 64522E52-848B-4015-89CE-5A36F00B94FF
' Inherited interface = ISyncMgrUIOperation
' ########################################################################################

#IF NOT %DEF(%ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED)
    %ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrEventLinkUIOperation $IID_ISyncMgrEventLinkUIOperation

   INHERIT IUnknown

   ' =====================================================================================
   ' ISyncMgrUIOperation Method
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 12
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISyncMgrEventLinkUIOperation Method
   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 16
     BYREF rguidEventID AS GUID _                       ' __in REFGUID rguidEventID
   , BYVAL pEvent AS ISyncMgrEvent _                    ' __in ISyncMgrEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrEventLinkUIOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrScheduleWizardUIOperation interface
' IID = 459A6C84-21D2-4DDC-8A53-F023A46066F2
' Inherited interface = ISyncMgrUIOperation
' ########################################################################################

#IF NOT %DEF(%ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED)
    %ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrScheduleWizardUIOperation $IID_ISyncMgrScheduleWizardUIOperation

   INHERIT IUnknown

   ' =====================================================================================
   ' ISyncMgrUIOperation Method
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 12
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISyncMgrScheduleWizardUIOperation Method
   ' =====================================================================================
   METHOD InitWizard ( _                                ' VTable offset = 16
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrScheduleWizardUIOperation_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrSyncResult interface
' IID = 2B90F17E-5A3E-4B33-BB7F-1BC48056B94D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrSyncResult_INTERFACE_DEFINED)
    %ISyncMgrSyncResult_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrSyncResult $IID_ISyncMgrSyncResult

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Result ( _                                    ' VTable offset = 12
     BYVAL nStatus AS LONG _                            ' __in SYNCMGR_PROGRESS_STATUS nStatus
   , BYVAL cError AS DWORD _                            ' __in UINT cError
   , BYVAL cConflicts AS DWORD _                        ' __in UINT cConflicts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrSyncResult_INTERFACE_DEFINED__ */


' enum SYNCMGR_CONTROL_FLAGS
%SYNCMGR_CF_NONE                       = 0???
%SYNCMGR_CF_NOWAIT                     = 0???
%SYNCMGR_CF_WAIT                       = &H1???
%SYNCMGR_CF_NOUI                       = &H2???
%SYNCMGR_CF_VALID                      = &H3???

' enum SYNCMGR_SYNC_CONTROL_FLAGS
%SYNCMGR_SCF_NONE                      = 0???
%SYNCMGR_SCF_IGNORE_IF_ALREADY_SYNCING = &H1???
%SYNCMGR_SCF_VALID                     = &H1???

' enum SYNCMGR_UPDATE_REASON
%SYNCMGR_UR_ADDED                      = 0
%SYNCMGR_UR_CHANGED                    = 1
%SYNCMGR_UR_REMOVED                    = 2
%SYNCMGR_UR_MAX                        = %SYNCMGR_UR_REMOVED


' ########################################################################################
' ISyncMgrControl interface
' IID = 9B63616C-36B2-46BC-959F-C1593952D19B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrControl_INTERFACE_DEFINED)
    %ISyncMgrControl_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrControl $IID_ISyncMgrControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartHandlerSync ( _                          ' VTable offset = 12
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL nSyncControlFlags AS DWORD _                 ' __in SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags
   , BYVAL pResult AS ISyncMgrSyncResult _              ' __in ISyncMgrSyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartItemSync ( _                             ' VTable offset = 16
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL ppszItemIDs AS DWORD _                       ' __in LPCWSTR *ppszItemIDs
   , BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL nSyncControlFlags AS DWORD _                 ' __in SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags
   , BYVAL pResult AS ISyncMgrSyncResult _              ' __in ISyncMgrSyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartSyncAll ( _                              ' VTable offset = 20
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopHandlerSync ( _                           ' VTable offset = 24
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopItemSync ( _                              ' VTable offset = 28
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL ppszItemIDs AS DWORD _                       ' __in LPCWSTR *ppszItemIDs
   , BYVAL cItems AS DWORD _                            ' __in ULONG cItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopSyncAll ( _                               ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateHandlerCollection ( _                   ' VTable offset = 36
     BYREF rclsidCollectionID AS GUID _                 ' __in REFCLSID rclsidCollectionID
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateHandler ( _                             ' VTable offset = 40
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateItem ( _                                ' VTable offset = 44
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateEvents ( _                              ' VTable offset = 48
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateConflict ( _                            ' VTable offset = 52
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL pConflict AS ISyncMgrConflict _              ' __in ISyncMgrConflict *pConflict
   , BYVAL nReason AS LONG _                            ' __in SYNCMGR_UPDATE_REASON nReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateConflicts ( _                           ' VTable offset = 56
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateHandler ( _                           ' VTable offset = 60
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   , BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableHandler ( _                             ' VTable offset = 64
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   , BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableItem ( _                                ' VTable offset = 68
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   , BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL nControlFlags AS DWORD _                     ' __in SYNCMGR_CONTROL_FLAGS nControlFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrControl_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrEventStore interface
' IID = 37E412F9-016E-44C2-81FF-DB3ADD774266
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrEventStore_INTERFACE_DEFINED)
    %ISyncMgrEventStore_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrEventStore $IID_ISyncMgrEventStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEventEnumerator ( _                        ' VTable offset = 12
     BYREF ppenum AS IEnumSyncMgrEvents _               ' __out IEnumSyncMgrEvents **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventCount ( _                             ' VTable offset = 16
     BYREF pcEvents AS DWORD _                          ' __out ULONG *pcEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 20
     BYREF rguidEventID AS GUID _                       ' __in REFGUID rguidEventID
   , BYREF ppEvent AS ISyncMgrEvent _                   ' __out ISyncMgrEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveEvent ( _                               ' VTable offset = 24
     BYREF pguidEventIDs AS GUID _                      ' __in GUID *pguidEventIDs
   , BYVAL cEvents AS DWORD _                           ' __in ULONG cEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrEventStore_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrEvent interface
' IID = FEE0EF8B-46BD-4DB4-B7E6-FF2C687313BC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrEvent_INTERFACE_DEFINED)
    %ISyncMgrEvent_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrEvent $IID_ISyncMgrEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEventID ( _                                ' VTable offset = 12
     BYREF pguidEventID AS GUID _                       ' __out GUID *pguidEventID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandlerID ( _                              ' VTable offset = 16
     BYREF ppszHandlerID AS DWORD _                     ' __out LPWSTR *ppszHandlerID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemID ( _                                 ' VTable offset = 20
     BYREF ppszItemID AS DWORD _                        ' __out LPWSTR *ppszItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLevel ( _                                  ' VTable offset = 24
     BYREF pnLevel AS LONG _                            ' __out SYNCMGR_EVENT_LEVEL *pnLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 28
     BYREF pnFlags AS DWORD _                           ' __out SYNCMGR_EVENT_FLAGS *pnFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 32
     BYREF pfCreationTime AS FILETIME _                 ' __out FILETIME *pfCreationTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 36
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 40
     BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkText ( _                               ' VTable offset = 44
     BYREF ppszLinkText AS DWORD _                      ' __out LPWSTR *ppszLinkText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkReference ( _                          ' VTable offset = 48
     BYREF ppszLinkReference AS DWORD _                 ' __out LPWSTR *ppszLinkReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 52
     BYREF ppszContext AS DWORD _                       ' __out LPWSTR *ppszContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumSyncMgrEvents interface
' IID = C81A1D4E-8CF7-4683-80E0-BCAE88D677B6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSyncMgrEvents_INTERFACE_DEFINED)
    %IEnumSyncMgrEvents_INTERFACE_DEFINED = 1

INTERFACE IEnumSyncMgrEvents $IID_IEnumSyncMgrEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS ISyncMgrEvent _                     ' __out ISyncMgrEvent **rgelt
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
     BYREF ppenum AS IEnumSyncMgrEvents _               ' __out IEnumSyncMgrEvents **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSyncMgrEvents_INTERFACE_DEFINED__ */

' // Size = 8 bytes
TYPE SYNCMGR_CONFLICT_ID_INFO DWORD
   pblobID    AS BYTE_BLOB PTR   ' BYTE_BLOB *
   pblobExtra AS BYTE_BLOB PTR   ' BYTE_BLOB *
END TYPE


' ########################################################################################
' ISyncMgrConflictStore interface
' IID = CF8FC579-C396-4774-85F1-D908A831156E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictStore_INTERFACE_DEFINED)
    %ISyncMgrConflictStore_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictStore $IID_ISyncMgrConflictStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumConflicts ( _                             ' VTable offset = 12
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYREF ppEnum AS IEnumSyncMgrConflict _             ' __out IEnumSyncMgrConflict **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToConflict ( _                            ' VTable offset = 16
     BYREF pConflictIdInfo AS SYNCMGR_CONFLICT_ID_INFO _ ' __in const SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveConflicts ( _                           ' VTable offset = 20
     BYREF rgConflictIdInfo AS SYNCMGR_CONFLICT_ID_INFO _ ' __in const SYNCMGR_CONFLICT_ID_INFO *rgConflictIdInfo
   , BYVAL cConflicts AS DWORD _                        ' __in DWORD cConflicts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pszHandlerID AS WSTRINGZ _                   ' __in LPCWSTR pszHandlerID
   , BYREF pszItemID AS WSTRINGZ _                      ' __in LPCWSTR pszItemID
   , BYREF pnConflicts AS DWORD _                       ' __out DWORD *pnConflicts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictStore_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumSyncMgrConflict interface
' IID = 82705914-DDA3-4893-BA99-49DE6C8C8036
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSyncMgrConflict_INTERFACE_DEFINED)
    %IEnumSyncMgrConflict_INTERFACE_DEFINED = 1

INTERFACE IEnumSyncMgrConflict $IID_IEnumSyncMgrConflict

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS ISyncMgrConflict _                  ' __out ISyncMgrConflict **rgelt
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
     BYREF ppenum AS IEnumSyncMgrConflict _             ' __out IEnumSyncMgrConflict **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSyncMgrConflict_INTERFACE_DEFINED__ */


' enum SYNCMGR_CONFLICT_ITEM_TYPE
%SYNCMGR_CIT_UPDATED   = &H1
%SYNCMGR_CIT_DELETED   = &H2

'typedef DWORD SYNCMGR_CONFLICT_ITEM_TYPE_FLAG;

' ########################################################################################
' ISyncMgrConflict interface
' IID = 9C204249-C443-4BA4-85ED-C972681DB137
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflict_INTERFACE_DEFINED)
    %ISyncMgrConflict_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflict $IID_ISyncMgrConflict

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 12
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConflictIdInfo ( _                         ' VTable offset = 16
     BYREF pConflictIdInfo AS SYNCMGR_CONFLICT_ID_INFO _ ' __out SYNCMGR_CONFLICT_ID_INFO *pConflictIdInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemsArray ( _                             ' VTable offset = 20
     BYREF ppArray AS ISyncMgrConflictItems _           ' __out ISyncMgrConflictItems **ppArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 24
     BYVAL pResolveInfo AS ISyncMgrConflictResolveInfo _ ' __in ISyncMgrConflictResolveInfo *pResolveInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolutionHandler ( _                      ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvResolutionHandler AS IUnknown _           ' __out void **ppvResolutionHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflict_INTERFACE_DEFINED__ */


' enum SYNCMGR_RESOLUTION_ABILITIES
%SYNCMGR_RA_KEEPOTHER         = &H1
%SYNCMGR_RA_KEEPRECENT        = &H2
%SYNCMGR_RA_REMOVEFROMSYNCSET = &H4
%SYNCMGR_RA_KEEP_SINGLE       = &H8
%SYNCMGR_RA_KEEP_MULTIPLE     = &H10
%SYNCMGR_RA_VALID             = &H1f

'typedef DWORD SYNCMGR_RESOLUTION_ABILITIES_FLAGS;

' enum SYNCMGR_RESOLUTION_FEEDBACK
%SYNCMGR_RF_CONTINUE          = 0
%SYNCMGR_RF_REFRESH           = %SYNCMGR_RF_CONTINUE + 1
%SYNCMGR_RF_CANCEL            = %SYNCMGR_RF_REFRESH  + 1


' ########################################################################################
' ISyncMgrResolutionHandler interface
' IID = 40A3D052-8BFF-4C4B-A338-D4A395700DE9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrResolutionHandler_INTERFACE_DEFINED)
    %ISyncMgrResolutionHandler_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrResolutionHandler $IID_ISyncMgrResolutionHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryAbilities ( _                            ' VTable offset = 12
     BYREF pdwAbilities AS DWORD _                      ' __out SYNCMGR_RESOLUTION_ABILITIES_FLAGS *pdwAbilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeepOther ( _                                 ' VTable offset = 16
     BYVAL psiOther AS IShellItem _                     ' __in IShellItem *psiOther
   , BYREF pFeedback AS LONG _                          ' __out SYNCMGR_RESOLUTION_FEEDBACK *pFeedback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeepRecent ( _                                ' VTable offset = 20
     BYREF pFeedback AS LONG _                          ' __out SYNCMGR_RESOLUTION_FEEDBACK *pFeedback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFromSyncSet ( _                         ' VTable offset = 24
     BYREF pFeedback AS LONG _                          ' __out SYNCMGR_RESOLUTION_FEEDBACK *pFeedback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeepItems ( _                                 ' VTable offset = 28
     BYVAL pArray AS ISyncMgrConflictResolutionItems _  ' __in ISyncMgrConflictResolutionItems *pArray
   , BYREF pFeedback AS LONG _                          ' __out SYNCMGR_RESOLUTION_FEEDBACK *pFeedback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrResolutionHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrConflictPresenter interface
' IID = 0B4F5353-FD2B-42CD-8763-4779F2D508A3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictPresenter_INTERFACE_DEFINED)
    %ISyncMgrConflictPresenter_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictPresenter $IID_ISyncMgrConflictPresenter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PresentConflict ( _                           ' VTable offset = 12
     BYVAL pConflict AS ISyncMgrConflict _              ' __in ISyncMgrConflict *pConflict
   , BYVAL pResolveInfo AS ISyncMgrConflictResolveInfo _ ' __in ISyncMgrConflictResolveInfo *pResolveInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictPresenter_INTERFACE_DEFINED__ */


' enum SYNCMGR_PRESENTER_NEXT_STEP
%SYNCMGR_PNS_CONTINUE            = 0
%SYNCMGR_PNS_DEFAULT             = %SYNCMGR_PNS_CONTINUE            + 1
%SYNCMGR_PNS_CANCEL              = %SYNCMGR_PNS_DEFAULT             + 1

' enum SYNCMGR_PRESENTER_CHOICE
%SYNCMGR_PC_NO_CHOICE            = 0
%SYNCMGR_PC_KEEP_ONE             = %SYNCMGR_PC_NO_CHOICE            + 1
%SYNCMGR_PC_KEEP_MULTIPLE        = %SYNCMGR_PC_KEEP_ONE             + 1
%SYNCMGR_PC_KEEP_RECENT          = %SYNCMGR_PC_KEEP_MULTIPLE        + 1
%SYNCMGR_PC_REMOVE_FROM_SYNC_SET = %SYNCMGR_PC_KEEP_RECENT          + 1
%SYNCMGR_PC_SKIP                 = %SYNCMGR_PC_REMOVE_FROM_SYNC_SET + 1


' ########################################################################################
' ISyncMgrConflictResolveInfo interface
' IID = C405A219-25A2-442E-8743-B845A2CEE93F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictResolveInfo_INTERFACE_DEFINED)
    %ISyncMgrConflictResolveInfo_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictResolveInfo $IID_ISyncMgrConflictResolveInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIterationInfo ( _                          ' VTable offset = 12
     BYREF pnCurrentConflict AS DWORD _                 ' __out UINT *pnCurrentConflict
   , BYREF pcConflicts AS DWORD _                       ' __out UINT *pcConflicts
   , BYREF pcRemainingForApplyToAll AS DWORD _          ' __out UINT *pcRemainingForApplyToAll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresenterNextStep ( _                      ' VTable offset = 16
     BYREF pnPresenterNextStep AS LONG _                ' __out SYNCMGR_PRESENTER_NEXT_STEP *pnPresenterNextStep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresenterChoice ( _                        ' VTable offset = 20
     BYREF pnPresenterChoice AS LONG _                  ' __out SYNCMGR_PRESENTER_CHOICE *pnPresenterChoice
   , BYREF pfApplyToAll AS LONG _                       ' __out BOOL *pfApplyToAll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemChoiceCount ( _                        ' VTable offset = 24
     BYREF pcChoices AS DWORD _                         ' __out UINT *pcChoices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemChoice ( _                             ' VTable offset = 28
     BYVAL iChoice AS DWORD _                           ' __in UINT iChoice
   , BYREF piChoiceIndex AS DWORD _                     ' __out UINT *piChoiceIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPresenterNextStep ( _                      ' VTable offset = 32
     BYVAL nPresenterNextStep AS LONG _                 ' __in SYNCMGR_PRESENTER_NEXT_STEP nPresenterNextStep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPresenterChoice ( _                        ' VTable offset = 36
     BYVAL nPresenterChoice AS LONG _                   ' __in SYNCMGR_PRESENTER_CHOICE nPresenterChoice
   , BYVAL fApplyToAll AS LONG _                        ' __in BOOL fApplyToAll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemChoices ( _                            ' VTable offset = 40
     BYVAL prgiConflictItemIndexes AS DWORD _           ' __in UINT *prgiConflictItemIndexes
   , BYVAL cChoices AS DWORD _                          ' __in UINT cChoices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictResolveInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrConflictFolder interface
' IID = 59287F5E-BC81-4FCA-A7F1-E5A8ECDB1D69
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictFolder_INTERFACE_DEFINED)
    %ISyncMgrConflictFolder_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictFolder $IID_ISyncMgrConflictFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetConflictIDList ( _                         ' VTable offset = 12
     BYVAL pConflict AS ISyncMgrConflict _              ' __in ISyncMgrConflict *pConflict
   , BYREF ppidlConflict AS DWORD _                     ' __out PIDLIST_RELATIVE *ppidlConflict
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictFolder_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE CONFIRM_CONFLICT_ITEM DWORD
   pShellItem       AS DWORD PTR      ' IShellItem2*
   pszOriginalName  AS WSTRINGZ PTR   ' LPWSTR
   pszAlternateName AS WSTRINGZ PTR   ' LPWSTR
   pszLocationShort AS WSTRINGZ PTR   ' LPWSTR
   pszLocationFull  AS WSTRINGZ PTR   ' LPWSTR
   nType            AS LONG           ' SYNCMGR_CONFLICT_ITEM_TYPE
END TYPE

'#if defined(__cplusplus)
'_inline void FreeConfirmConflictItem(__inout CONFIRM_CONFLICT_ITEM *pcci)
'{
'    if (pcci->pShellItem)
'    {
'        pcci->pShellItem->Release();
'    }
'    ::CoTaskMemFree(pcci->pszOriginalName);
'    ::CoTaskMemFree(pcci->pszAlternateName);
'    ::CoTaskMemFree(pcci->pszLocationShort);
'    ::CoTaskMemFree(pcci->pszLocationFull);
'    ::ZeroMemory(pcci, sizeof(*pcci));
'}
'#endif // defined(__cplusplus)

SUB FreeConfirmConflictItem (BYREF pcci AS CONFIRM_CONFLICT_ITEM)
   IF VARPTR(pcci) = 0 THEN EXIT SUB
   IF pcci.pShellItem THEN IUnknown_Release pcci.pShellItem
   IF pcci.pszOriginalName THEN CoTaskMemFree(BYVAL pcci.pszOriginalName)
   IF pcci.pszAlternateName THEN CoTaskMemFree(BYVAL pcci.pszAlternateName)
   IF pcci.pszLocationShort THEN CoTaskMemFree(BYVAL pcci.pszLocationShort)
   IF pcci.pszLocationFull THEN CoTaskMemFree(BYVAL pcci.pszLocationFull)
   ZeroMemory(VARPTR(pcci), SIZEOF(pcci))
END SUB

' // Size = 8 bytes
TYPE CONFIRM_CONFLICT_RESULT_INFO DWORD
   pszNewName AS WSTRINGZ PTR   ' LPWSTR
   iItemIndex AS DWORD          ' UINT
END TYPE


' ########################################################################################
' ISyncMgrConflictItems interface
' IID = 9C7EAD52-8023-4936-A4DB-D2A9A99E436A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictItems_INTERFACE_DEFINED)
    %ISyncMgrConflictItems_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictItems $IID_ISyncMgrConflictItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYVAL iIndex AS DWORD _                            ' __in UINT iIndex
   , BYREF pItemInfo AS CONFIRM_CONFLICT_ITEM _         ' __out CONFIRM_CONFLICT_ITEM *pItemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictItems_INTERFACE_DEFINED__ */

' ########################################################################################
' ISyncMgrConflictResolutionItems interface
' IID = 458725B9-129D-4135-A998-9CEAFEC27007
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISyncMgrConflictResolutionItems_INTERFACE_DEFINED)
    %ISyncMgrConflictResolutionItems_INTERFACE_DEFINED = 1

INTERFACE ISyncMgrConflictResolutionItems $IID_ISyncMgrConflictResolutionItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYVAL iIndex AS DWORD _                            ' __in UINT iIndex
   , BYREF pItemInfo AS CONFIRM_CONFLICT_RESULT_INFO _  ' __out CONFIRM_CONFLICT_RESULT_INFO *pItemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISyncMgrConflictResolutionItems_INTERFACE_DEFINED__ */
