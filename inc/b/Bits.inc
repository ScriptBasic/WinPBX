' ########################################################################################
' Microsoft Windows
' File: Bits.inc
' Library name: BackgroundCopyManager
' Version: 1.0, Locale ID = 0
' Library GUID: {1DEEB74F-7915-4560-B558-918C83F176A6}
' Contents: Microsoft Background Copy Queue Manager 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "bitsmsg.inc"

%BG_SIZE_UNKNOWN     = -1&&   ' (UINT64)(-1)

'EXTERN_C const IID LIBID_BackgroundCopyManager;
$CLSID_BackgroundCopyManager = GUID$("{4991D34B-80A1-4291-83B6-3328366B9097}")

' ########################################################################################
' IBackgroundCopyFile interface
' IID = 01B7BD23-FB88-4A77-8490-5891D3E4653A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyFile_INTERFACE_DEFINED)
    %IBackgroundCopyFile_INTERFACE_DEFINED = 1

' // Size = 24 bytes
TYPE BG_FILE_PROGRESS QWORD
   BytesTotal       AS QUAD   ' UINT64
   BytesTransferred AS QUAD   ' UINT64
   Completed        AS LONG   ' BOOL
END TYPE

$IID_IBackgroundCopyFile = GUID$("{01B7BD23-FB88-4A77-8490-5891D3E4653A}")

INTERFACE IBackgroundCopyFile $IID_IBackgroundCopyFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRemoteName ( _                             ' VTable offset = 12
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalName ( _                              ' VTable offset = 16
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgress ( _                               ' VTable offset = 20
     BYREF pVal AS BG_FILE_PROGRESS _                   ' __out BG_FILE_PROGRESS *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyFile_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumBackgroundCopyFiles interface
' IID = CA51E165-C365-424C-8D41-24AAA4FF3C40
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBackgroundCopyFiles_INTERFACE_DEFINED)
    %IEnumBackgroundCopyFiles_INTERFACE_DEFINED = 1

$IID_IEnumBackgroundCopyFiles = GUID$("{CA51E165-C365-424C-8D41-24AAA4FF3C40}")

INTERFACE IEnumBackgroundCopyFiles $IID_IEnumBackgroundCopyFiles

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IBackgroundCopyFile _               ' __out IBackgroundCopyFile **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
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
      BYREF ppenum AS IEnumBackgroundCopyFiles _        ' __out IEnumBackgroundCopyFiles **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
      BYREF puCount AS DWORD _                          ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBackgroundCopyFiles_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyError interface
' IID = 19C613A0-FCB8-4F28-81AE-897C3D078F81
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyError_INTERFACE_DEFINED)
    %IBackgroundCopyError_INTERFACE_DEFINED = 1

' enum BG_ERROR_CONTEXT
MACRO BG_ERROR_CONTEXT_ENUM = LONG
%BG_ERROR_CONTEXT_NONE                       = 0
%BG_ERROR_CONTEXT_UNKNOWN                    = 1
%BG_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER      = 2
%BG_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION = 3
%BG_ERROR_CONTEXT_LOCAL_FILE                 = 4
%BG_ERROR_CONTEXT_REMOTE_FILE                = 5
%BG_ERROR_CONTEXT_GENERAL_TRANSPORT          = 6
%BG_ERROR_CONTEXT_REMOTE_APPLICATION         = 7

$IID_IBackgroundCopyError = GUID$("{19C613A0-FCB8-4F28-81AE-897C3D078F81}")

INTERFACE IBackgroundCopyError $IID_IBackgroundCopyError

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetError ( _                                  ' VTable offset = 12
     BYREF pContext AS BG_ERROR_CONTEXT_ENUM _          ' __out BG_ERROR_CONTEXT *pContext
   , BYREF pCode AS DWORD _                             ' __out HRESULT *pCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFile ( _                                   ' VTable offset = 16
     BYREF pVal AS IBackgroundCopyFile _                ' __out IBackgroundCopyFile **pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorDescription ( _                       ' VTable offset = 20
     BYVAL LanguageId AS DWORD _                        ' __in DWORD LanguageId
   , BYREF pErrorDescription AS DWORD _                 ' __out LPWSTR *pErrorDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorContextDescription ( _                ' VTable offset = 24
     BYVAL LanguageId AS DWORD _                        ' __in DWORD LanguageId
   , BYREF pContextDescription AS DWORD _               ' __out LPWSTR *pContextDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocol ( _                               ' VTable offset = 28
     BYREF pProtocol AS DWORD _                         ' __out LPWSTR *pProtocol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyError_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyJob interface
' IID = 37668D37-507E-4160-9316-26306D150B12
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyJob_INTERFACE_DEFINED)
    %IBackgroundCopyJob_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE BG_FILE_INFO DWORD
   RemoteName AS WSTRINGZ PTR   ' LPWSTR
   LocalName  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 24 bytes
TYPE BG_JOB_PROGRESS QWORD FILL
   BytesTotal       AS QUAD    ' UINT64
   BytesTransferred AS QUAD    ' UINT64
   FilesTotal       AS DWORD   ' ULONG
   FilesTransferred AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
TYPE BG_JOB_TIMES DWORD
   CreationTime           AS FILETIME
   ModificationTime       AS FILETIME
   TransferCompletionTime AS FILETIME
END TYPE

' enum BG_JOB_PRIORITY
MACRO BG_JOB_PRIORITY_ENUM = LONG
%BG_JOB_PRIORITY_FOREGROUND = 0
%BG_JOB_PRIORITY_HIGH       = %BG_JOB_PRIORITY_FOREGROUND + 1
%BG_JOB_PRIORITY_NORMAL     = %BG_JOB_PRIORITY_HIGH       + 1
%BG_JOB_PRIORITY_LOW        = %BG_JOB_PRIORITY_NORMAL     + 1

' enum BG_JOB_STATE
MACRO BG_JOB_STATE_ENUM = LONG
%BG_JOB_STATE_QUEUED          = 0
%BG_JOB_STATE_CONNECTING      = %BG_JOB_STATE_QUEUED          + 1
%BG_JOB_STATE_TRANSFERRING    = %BG_JOB_STATE_CONNECTING      + 1
%BG_JOB_STATE_SUSPENDED       = %BG_JOB_STATE_TRANSFERRING    + 1
%BG_JOB_STATE_ERROR           = %BG_JOB_STATE_SUSPENDED       + 1
%BG_JOB_STATE_TRANSIENT_ERROR = %BG_JOB_STATE_ERROR           + 1
%BG_JOB_STATE_TRANSFERRED     = %BG_JOB_STATE_TRANSIENT_ERROR + 1
%BG_JOB_STATE_ACKNOWLEDGED    = %BG_JOB_STATE_TRANSFERRED     + 1
%BG_JOB_STATE_CANCELLED       = %BG_JOB_STATE_ACKNOWLEDGED    + 1

' enum BG_JOB_TYPE
MACRO BG_JOB_TYPE_ENUM = LONG
%BG_JOB_TYPE_DOWNLOAD     = 0
%BG_JOB_TYPE_UPLOAD       = %BG_JOB_TYPE_DOWNLOAD + 1
%BG_JOB_TYPE_UPLOAD_REPLY = %BG_JOB_TYPE_UPLOAD   + 1

' enum BG_JOB_PROXY_USAGE
MACRO BG_JOB_PROXY_USAGE_ENUM = LONG
%BG_JOB_PROXY_USAGE_PRECONFIG  = 0
%BG_JOB_PROXY_USAGE_NO_PROXY   = %BG_JOB_PROXY_USAGE_PRECONFIG + 1
%BG_JOB_PROXY_USAGE_OVERRIDE   = %BG_JOB_PROXY_USAGE_NO_PROXY  + 1
%BG_JOB_PROXY_USAGE_AUTODETECT = %BG_JOB_PROXY_USAGE_OVERRIDE  + 1

$IID_IBackgroundCopyJob = GUID$("{37668D37-507E-4160-9316-26306D150B12}")

INTERFACE IBackgroundCopyJob $IID_IBackgroundCopyJob

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddFileSet ( _                                ' VTable offset = 12
     BYVAL cFileCount AS DWORD _                        ' __in ULONG cFileCount
   , BYREF pFileSet AS BG_FILE_INFO _                   ' __in BG_FILE_INFO *pFileSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFile ( _                                   ' VTable offset = 16
     BYREF RemoteUrl AS WSTRINGZ _                      ' __in LPCWSTR RemoteUrl
   , BYREF LocalName AS WSTRINGZ _                      ' __in LPCWSTR LocalName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFiles ( _                                 ' VTable offset = 20
     BYREF pEnum AS IEnumBackgroundCopyFiles _          ' __out IEnumBackgroundCopyFiles **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Complete ( _                                  ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 40
     BYREF pVal AS GUID _                               ' __out GUID *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 44
     BYREF pVal AS BG_JOB_TYPE_ENUM _                   ' __out BG_JOB_TYPE *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgress ( _                               ' VTable offset = 48
     BYREF pVal AS BG_JOB_PROGRESS _                    ' __out BG_JOB_PROGRESS *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimes ( _                                  ' VTable offset = 52
     BYREF pVal AS BG_JOB_TIMES _                       ' __out BG_JOB_TIMES *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 56
     BYREF pVal AS BG_JOB_STATE_ENUM _                  ' __out BG_JOB_STATE *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetError ( _                                  ' VTable offset = 60
     BYREF ppError AS IBackgroundCopyError _            ' __out IBackgroundCopyError **ppError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOwner ( _                                  ' VTable offset = 64
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 68
     BYREF Val AS WSTRINGZ _                            ' __in LPCWSTR Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 72
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 76
     BYREF Val AS WSTRINGZ _                            ' __in LPCWSTR Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 80
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 84
     BYREF Val AS BG_JOB_PRIORITY_ENUM _                ' __in BG_JOB_PRIORITY Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 88
     BYREF Val AS BG_JOB_PRIORITY_ENUM _                ' __in BG_JOB_PRIORITY Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyFlags ( _                            ' VTable offset = 92
     BYVAL Val AS DWORD _                               ' __in ULONG Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyFlags ( _                            ' VTable offset = 96
     BYREF pVal AS DWORD _                              ' __out ULONG *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyInterface ( _                        ' VTable offset = 100
     BYVAL Val AS IUnknown _                            ' __in IUnknown *Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyInterface ( _                        ' VTable offset = 104
     BYREF pVal AS IUnknown _                           ' __out IUnknown **pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinimumRetryDelay ( _                      ' VTable offset = 108
     BYVAL Seconds AS DWORD _                           ' __in ULONG Seconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinimumRetryDelay ( _                      ' VTable offset = 112
     BYREF Seconds AS DWORD _                           ' __out ULONG *Seconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNoProgressTimeout ( _                      ' VTable offset = 116
     BYVAL Seconds AS DWORD _                           ' __in ULONG Seconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNoProgressTimeout ( _                      ' VTable offset = 120
     BYREF Seconds AS DWORD _                           ' __out ULONG *Seconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorCount ( _                             ' VTable offset = 124
     BYREF Errors AS DWORD _                            ' __out ULONG *Errors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProxySettings ( _                          ' VTable offset = 128
     BYREF ProxyUsage AS BG_JOB_PROXY_USAGE_ENUM _      ' __in BG_JOB_PROXY_USAGE ProxyUsage
   , BYREF ProxyList AS WSTRINGZ _                      ' __in const WCHAR *ProxyList
   , BYREF ProxyBypassList AS WSTRINGZ _                ' __in const WCHAR *ProxyBypassList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProxySettings ( _                          ' VTable offset = 132
     BYREF pProxyUsage AS BG_JOB_PROXY_USAGE_ENUM _     ' __out BG_JOB_PROXY_USAGE *pProxyUsage
   , BYREF pProxyList AS DWORD _                        ' __out LPWSTR *pProxyList
   , BYREF pProxyBypassList AS DWORD _                  ' __out LPWSTR *pProxyBypassList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TakeOwnership ( _                             ' VTable offset = 136
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyJob_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumBackgroundCopyJobs interface
' IID = 1AF4F612-3B71-466F-8F58-7B6F73AC57AD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBackgroundCopyJobs_INTERFACE_DEFINED)
    %IEnumBackgroundCopyJobs_INTERFACE_DEFINED = 1

$IID_IEnumBackgroundCopyJobs = GUID$("{1AF4F612-3B71-466F-8F58-7B6F73AC57AD}")

INTERFACE IEnumBackgroundCopyJobs $IID_IEnumBackgroundCopyJobs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFileCount AS DWORD _                        ' __in ULONG cFileCount
   , BYREF rgelt AS IBackgroundCopyJob _                ' __out IBackgroundCopyJob **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cFileCount AS DWORD _                        ' __in ULONG cFileCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumBackgroundCopyJobs _          ' __out IEnumBackgroundCopyJobs **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBackgroundCopyJobs_INTERFACE_DEFINED__ */

%BG_NOTIFY_JOB_TRANSFERRED    = &H0001
%BG_NOTIFY_JOB_ERROR          = &H0002
%BG_NOTIFY_DISABLE            = &H0004
%BG_NOTIFY_JOB_MODIFICATION   = &H0008
%BG_NOTIFY_FILE_TRANSFERRED   = &H0010

' ########################################################################################
' IBackgroundCopyCallback interface
' IID = 97EA99C7-0186-4AD4-8DF9-C5B4E0ED6B22
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyCallback_INTERFACE_DEFINED)
    %IBackgroundCopyCallback_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyCallback = GUID$("{97EA99C7-0186-4AD4-8DF9-C5B4E0ED6B22}")

INTERFACE IBackgroundCopyCallback $IID_IBackgroundCopyCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD JobTransferred ( _                            ' VTable offset = 12
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JobError ( _                                  ' VTable offset = 16
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   , BYVAL pError AS IBackgroundCopyError _             ' __in IBackgroundCopyError *pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JobModification ( _                           ' VTable offset = 20
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' AsyncIBackgroundCopyCallback interface
' IID = CA29D251-B4BB-4679-A3D9-AE8006119D54
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIBackgroundCopyCallback_INTERFACE_DEFINED)
    %AsyncIBackgroundCopyCallback_INTERFACE_DEFINED = 1

$IID_AsyncIBackgroundCopyCallback = GUID$("{CA29D251-B4BB-4679-A3D9-AE8006119D54}")

INTERFACE AsyncIBackgroundCopyCallback $IID_AsyncIBackgroundCopyCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin_JobTransferred ( _                      ' VTable offset = 12
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_JobTransferred ( _                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_JobError ( _                            ' VTable offset = 20
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   , BYVAL pError AS IBackgroundCopyError _             ' __in IBackgroundCopyError *pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_JobError ( _                           ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin_JobModification ( _                     ' VTable offset = 28
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finish_JobModification ( _                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IBackgroundCopyManager interface
' IID = 5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyManager_INTERFACE_DEFINED)
    %IBackgroundCopyManager_INTERFACE_DEFINED = 1

%BG_JOB_ENUM_ALL_USERS  = &H0001

$IID_IBackgroundCopyManager = GUID$("{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}")

INTERFACE IBackgroundCopyManager $IID_IBackgroundCopyManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateJob ( _                                 ' VTable offset = 12
     BYREF DisplayName AS WSTRINGZ _                    ' __in LPCWSTR DisplayName
   , BYVAL Type AS BG_JOB_TYPE_ENUM _                   ' __in BG_JOB_TYPE Type
   , BYREF pJobId AS GUID _                             ' __out GUID *pJobId
   , BYREF ppJob AS IBackgroundCopyJob _                ' __out IBackgroundCopyJob **ppJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJob ( _                                    ' VTable offset = 16
     BYREF jobID AS GUID _                              ' __in REFGUID jobID
   , BYREF ppJob AS IBackgroundCopyJob _                ' __out IBackgroundCopyJob **ppJob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumJobs ( _                                  ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEnum AS IEnumBackgroundCopyJobs _          ' __out IEnumBackgroundCopyJobs **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorDescription ( _                       ' VTable offset = 24
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL LanguageId AS DWORD _                        ' __in DWORD LanguageId
   , BYREF pErrorDescription AS DWORD _                 ' __out LPWSTR *pErrorDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyManager_INTERFACE_DEFINED__ */

#INCLUDE ONCE "bits1_5.inc"
