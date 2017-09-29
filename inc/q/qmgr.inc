' ########################################################################################
' Microsoft Windows
' File: qmgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: BackgroundCopyQMgr
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Background Copy Queue Manager 1.0
' Library GUID: {F5B26DCB-B37E-4D7C-AE7A-1CB3FBEB183E}
' ########################################################################################

#INCLUDE THIS ONCE
%QMGR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "docobj.inc"

$LIBID_BackgroundCopyQMgr = GUID$("{F5B26DCB-B37E-4D7C-AE7A-1CB3FBEB183E}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_BackgroundCopyQMgr = GUID$("{69AD4AEE-51BE-439B-A92C-86AE490E8B30}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IBackgroundCopyGroup = GUID$("{1DED80A7-53EA-424F-8A04-17FEA9ADC4F5}")
$IID_IBackgroundCopyJob1 = GUID$("{59F5553C-2031-4629-BB18-2645A6970947}")
$IID_IBackgroundCopyQMgr = GUID$("{16F41C69-09F5-41D2-8CD8-3C08C47BC8A8}")
$IID_IEnumBackgroundCopyGroups = GUID$("{D993E603-4AA4-47C5-8665-C20D39C2BA4F}")
$IID_IEnumBackgroundCopyJobs1 = GUID$("{8BAEBA9D-8F1C-42C4-B82C-09AE79980D25}")
$IID_IBackgroundCopyCallback1 = GUID$("{084F6593-3800-4E08-9B59-99FA59ADDF82}")

'// Background Copy QMgr Public Interface
%QM_NOTIFY_FILE_DONE         = &H00000001???
%QM_NOTIFY_JOB_DONE          = &H00000002???
%QM_NOTIFY_GROUP_DONE        = &H00000004???
%QM_NOTIFY_DISABLE_NOTIFY    = &H00000040???
%QM_NOTIFY_USE_PROGRESSEX    = &H00000080???
%QM_STATUS_FILE_COMPLETE     = &H00000001???
%QM_STATUS_FILE_INCOMPLETE   = &H00000002???
%QM_STATUS_JOB_COMPLETE      = &H00000004???
%QM_STATUS_JOB_INCOMPLETE    = &H00000008???
%QM_STATUS_JOB_ERROR         = &H00000010???
%QM_STATUS_JOB_FOREGROUND    = &H00000020???
%QM_STATUS_GROUP_COMPLETE    = &H00000040???
%QM_STATUS_GROUP_INCOMPLETE  = &H00000080???
%QM_STATUS_GROUP_SUSPENDED   = &H00000100???
%QM_STATUS_GROUP_ERROR       = &H00000200???
%QM_STATUS_GROUP_FOREGROUND  = &H00000400???
%QM_PROTOCOL_HTTP            = 1???
%QM_PROTOCOL_FTP             = 2???
%QM_PROTOCOL_SMB             = 3???
%QM_PROTOCOL_CUSTOM          = 4???
%QM_PROGRESS_PERCENT_DONE    = 1???
%QM_PROGRESS_TIME_DONE       = 2???
%QM_PROGRESS_SIZE_DONE       = 3???
%QM_E_INVALID_STATE          = &H81001001???
%QM_E_SERVICE_UNAVAILABLE    = &H81001002???
%QM_E_DOWNLOADER_UNAVAILABLE = &H81001003???
%QM_E_ITEM_NOT_FOUND         = &H81001004???

' ########################################################################################
' Interface name = IBackgroundCopyJob1
' IID = {59F5553C-2031-4629-BB18-2645A6970947}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyJob1_INTERFACE_DEFINED)
    %IBackgroundCopyJob1_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE FILESETINFO DWORD
   bstrRemoteFile AS DWORD   ' BSTR
   bstrLocalFile  AS DWORD   ' BSTR
   dwSizeHint     AS DWORD   ' DWORD
END TYPE

INTERFACE IBackgroundCopyJob1 $IID_IBackgroundCopyJob1

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CancelJob ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgress ( _                               ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwProgress AS DWORD _                       ' __out DWORD *pdwProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 20
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   , BYREF pdwWin32Result AS DWORD _                    ' __out DWORD *pdwWin32Result
   , BYREF pdwTransportResult AS DWORD _                ' __out DWORD *pdwTransportResult
   , BYREF pdwNumOfRetries AS DWORD _                   ' __out DWORD *pdwNumOfRetries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFiles ( _                                  ' VTable offset = 24
     BYVAL cFileCount AS DWORD _                        ' __in ULONG cFileCount
   , BYREF ppFileSet AS FILESETINFO _                   ' __in FILESETINFO **ppFileSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFile ( _                                   ' VTable offset = 28
     BYVAL cFileIndex AS DWORD _                        ' __in ULONG cFileIndex
   , BYREF pFileInfo AS FILESETINFO _                   ' __out FILESETINFO *pFileInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileCount ( _                              ' VTable offset = 32
     BYREF pdwFileCount AS DWORD _                      ' __out DWORD *pdwFileCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchToForeground ( _                        ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_JobID ( _                                 ' VTable offset = 40
     BYREF pguidJobID AS GUID _                         ' __out GUID *pguidJobID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyJob1_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumBackgroundCopyJobs1
' IID = {8BAEBA9D-8F1C-42C4-B82C-09AE79980D25}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBackgroundCopyJobs1_INTERFACE_DEFINED)
    %IEnumBackgroundCopyJobs1_INTERFACE_DEFINED = 1

INTERFACE IEnumBackgroundCopyJobs1 $IID_IEnumBackgroundCopyJobs1

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS GUID _                              ' __out GUID *rgelt
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
     BYREF ppenum AS IEnumBackgroundCopyJobs1 _         ' __out IEnumBackgroundCopyJobs1 **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBackgroundCopyJobs1_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBackgroundCopyGroup
' IID = {1DED80A7-53EA-424F-8A04-17FEA9ADC4F5}
' Inherited interface = IUnknown
' ########################################################################################

' GROUPPROP enum
%GROUPPROP_PRIORITY        = 0
%GROUPPROP_REMOTEUSERID    = 1
%GROUPPROP_REMOTEUSERPWD   = 2
%GROUPPROP_LOCALUSERID     = 3
%GROUPPROP_LOCALUSERPWD    = 4
%GROUPPROP_PROTOCOLFLAGS   = 5
%GROUPPROP_NOTIFYFLAGS     = 6
%GROUPPROP_NOTIFYCLSID     = 7
%GROUPPROP_PROGRESSSIZE    = 8
%GROUPPROP_PROGRESSPERCENT = 9
%GROUPPROP_PROGRESSTIME    = 10
%GROUPPROP_DISPLAYNAME     = 11
%GROUPPROP_DESCRIPTION     = 12

#IF NOT %DEF(%IBackgroundCopyGroup_INTERFACE_DEFINED)
    %IBackgroundCopyGroup_INTERFACE_DEFINED = 1

INTERFACE IBackgroundCopyGroup $IID_IBackgroundCopyGroup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProp ( _                                   ' VTable offset = 12
     BYVAL propID AS LONG _                             ' __in GROUPPROP propID
   , BYREF pvarVal AS VARIANT _                         ' __out VARIANT *pvarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InternalSetProp ( _                           ' VTable offset = 16
     BYVAL propID AS LONG _                             ' __in GROUPPROP propID
   , BYREF pvarVal AS VARIANT _                         ' __in VARIANT *pvarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgress ( _                               ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwProgress AS DWORD _                       ' __out DWORD *pdwProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   , BYREF pdwJobIndex AS DWORD _                       ' __out DWORD *pdwJobIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJob ( _                                    ' VTable offset = 28
     BYVAL jobID AS GUID _                              ' __in GUID jobID
   , BYREF ppJob AS IBackgroundCopyJob1 _               ' __out IBackgroundCopyJob1 **ppJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SuspendGroup ( _                              ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResumeGroup ( _                               ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelGroup ( _                               ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Size ( _                                  ' VTable offset = 44
     BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GroupID ( _                               ' VTable offset = 48
     BYREF pguidGroupID AS GUID _                       ' __out GUID *pguidGroupID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateJob ( _                                 ' VTable offset = 52
     BYVAL guidJobID AS GUID _                          ' __in GUID guidJobID
   , BYREF ppJob AS IBackgroundCopyJob1 _               ' __out IBackgroundCopyJob1 **ppJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumJobs ( _                                  ' VTable offset = 56
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnumJobs AS IEnumBackgroundCopyJobs1 _     ' __out IEnumBackgroundCopyJobs1 **ppEnumJobs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchToForeground ( _                        ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryNewJobInterface ( _                      ' VTable offset = 64
     BYREF iid AS GUID _                                ' __in GUID *iid
   , BYREF pUnk AS IUnknown _                           ' __out IUnknown **pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotificationPointer ( _                    ' VTable offset = 68
     BYREF iid AS GUID _                                ' __in GUID *iid
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumBackgroundCopyGroups
' IID = {D993E603-4AA4-47C5-8665-C20D39C2BA4F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBackgroundCopyGroups_INTERFACE_DEFINED)
    %IEnumBackgroundCopyGroups_INTERFACE_DEFINED = 1

INTERFACE IEnumBackgroundCopyGroups $IID_IEnumBackgroundCopyGroups

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS GUID _                              ' __out GUID *rgelt
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
     BYREF ppenum AS IEnumBackgroundCopyGroups _        ' __out IEnumBackgroundCopyGroups **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBackgroundCopyGroups_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBackgroundCopyCallback1
' IID = {084F6593-3800-4E08-9B59-99FA59ADDF82}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyCallback1_INTERFACE_DEFINED)
    %IBackgroundCopyCallback1_INTERFACE_DEFINED = 1

INTERFACE IBackgroundCopyCallback1 $IID_IBackgroundCopyCallback1

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStatus ( _                                  ' VTable offset = 12
     BYVAL pGroup AS IBackgroundCopyGroup _             ' __in IBackgroundCopyGroup *pGroup
   , BYVAL pJob AS IBackgroundCopyJob1 _                ' __in IBackgroundCopyJob1 *pJob
   , BYVAL dwFileIndex AS DWORD _                       ' __in DWORD dwFileIndex
   , BYVAL dwStatus AS DWORD _                          ' __in DWORD dwStatus
   , BYVAL dwNumOfRetries AS DWORD _                    ' __in DWORD dwNumOfRetries
   , BYVAL dwWin32Result AS DWORD _                     ' __in DWORD dwWin32Result
   , BYVAL dwTransportResult AS DWORD _                 ' __in DWORD dwTransportResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 16
     BYVAL ProgressType AS DWORD _                      ' __in DWORD ProgressType
   , BYVAL pGroup AS IBackgroundCopyGroup _             ' __in IBackgroundCopyGroup *pGroup
   , BYVAL pJob AS IBackgroundCopyJob1 _                ' __in IBackgroundCopyJob1 *pJob
   , BYVAL dwFileIndex AS DWORD _                       ' __in DWORD dwFileIndex
   , BYVAL dwProgressValue AS DWORD _                   ' __in DWORD dwProgressValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgressEx ( _                              ' VTable offset = 20
     BYVAL ProgressType AS DWORD _                      ' __in DWORD ProgressType
   , BYVAL pGroup AS IBackgroundCopyGroup _             ' __in IBackgroundCopyGroup *pGroup
   , BYVAL pJob AS IBackgroundCopyJob1 _                ' __in IBackgroundCopyJob1 *pJob
   , BYVAL dwFileIndex AS DWORD _                       ' __in DWORD dwFileIndex
   , BYVAL dwProgressValue AS DWORD _                   ' __in DWORD dwProgressValue
   , BYVAL dwByteArraySize AS DWORD _                   ' __in DWORD dwByteArraySize
   , BYVAL pByte AS BYTE PTR _                          ' __in BYTE *pByte
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyCallback1_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBackgroundCopyQMgr
' IID = {16F41C69-09F5-41D2-8CD8-3C08C47BC8A8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyQMgr_INTERFACE_DEFINED)
    %IBackgroundCopyQMgr_INTERFACE_DEFINED = 1

INTERFACE IBackgroundCopyQMgr $IID_IBackgroundCopyQMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateGroup ( _                               ' VTable offset = 12
     BYVAL guidGroupID AS GUID _                        ' __in GUID guidGroupID
   , BYREF ppGroup AS IBackgroundCopyGroup _            ' __out IBackgroundCopyGroup **ppGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroup ( _                                  ' VTable offset = 16
     BYVAL groupID AS GUID _                            ' __in GUID groupID
   , BYREF ppGroup AS IBackgroundCopyGroup _            ' __out IBackgroundCopyGroup **ppGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumGroups ( _                                ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnumGroups AS IEnumBackgroundCopyGroups _  ' __out IEnumBackgroundCopyGroups **ppEnumGroups
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyQMgr_INTERFACE_DEFINED__ */
