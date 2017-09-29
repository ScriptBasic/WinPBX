' ########################################################################################
' Microsoft Windows
' File: Bits3_0.inc
' Library name: BackgroundCopyManager3_0
' Version: 1.0, Locale ID = 0
' Library GUID: {659CDEA6-489E-11D9-A9CD-000D56965251}
' Contents: Microsoft Background Copy Manager 3.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITS3_0_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "bits.inc"
#INCLUDE ONCE "bits1_5.inc"
#INCLUDE ONCE "bits2_0.inc"
#INCLUDE ONCE "bits2_5.inc"

$CLSID_BackgroundCopyManager3_0 = GUID$("{659CDEA7-489E-11D9-A9CD-000D56965251}")

' ########################################################################################
' IBitsPeerCacheRecord interface
' IID = 659CDEAF-489E-11D9-A9CD-000D56965251
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBitsPeerCacheRecord_INTERFACE_DEFINED)
    %IBitsPeerCacheRecord_INTERFACE_DEFINED = 1

$IID_IBitsPeerCacheRecord = GUID$("{659CDEAF-489E-11D9-A9CD-000D56965251}")

INTERFACE IBitsPeerCacheRecord $IID_IBitsPeerCacheRecord

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 12
     BYREF pVal AS GUID _                               ' __out GUID *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginUrl ( _                              ' VTable offset = 16
     BYREF pVal AS DWORD _                              ' __out LPWSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileSize ( _                               ' VTable offset = 20
     BYREF pVal AS QUAD _                               ' __out UINT64 *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileModificationTime ( _                   ' VTable offset = 24
     BYREF pVal AS FILETIME _                           ' __out FILETIME *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastAccessTime ( _                         ' VTable offset = 28
     BYREF pVal AS FILETIME _                           ' __out FILETIME *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFileValidated ( _                           ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileRanges ( _                             ' VTable offset = 36
     BYREF pRangeCount AS DWORD _                       ' __out DWORD *pRangeCount
   , BYREF ppRanges AS DWORD _                          ' __out BG_FILE_RANGE **ppRanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBitsPeerCacheRecord_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumBitsPeerCacheRecords interface
' IID = 659CDEA4-489E-11D9-A9CD-000D56965251
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBitsPeerCacheRecords_INTERFACE_DEFINED)
    %IEnumBitsPeerCacheRecords_INTERFACE_DEFINED = 1

$IID_IEnumBitsPeerCacheRecords = GUID$("{659CDEA4-489E-11D9-A9CD-000D56965251}")

INTERFACE IEnumBitsPeerCacheRecords $IID_IEnumBitsPeerCacheRecords

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IBitsPeerCacheRecord _              ' __out IBitsPeerCacheRecord **rgelt
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
     BYREF ppenum AS IEnumBitsPeerCacheRecords _        ' __out IEnumBitsPeerCacheRecords **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBitsPeerCacheRecords_INTERFACE_DEFINED__ */

' ########################################################################################
' IBitsPeer interface
' IID = 659CDEA2-489E-11D9-A9CD-000D56965251
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBitsPeer_INTERFACE_DEFINED)
    %IBitsPeer_INTERFACE_DEFINED = 1

$IID_IBitsPeer = GUID$("{659CDEA2-489E-11D9-A9CD-000D56965251}")

INTERFACE IBitsPeer $IID_IBitsPeer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPeerName ( _                               ' VTable offset = 12
     BYREF pName AS DWORD _                             ' __out LPWSTR *pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAuthenticated ( _                           ' VTable offset = 16
     BYREF pAuth AS LONG _                              ' __out BOOL *pAuth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAvailable ( _                               ' VTable offset = 20
     BYREF pOnline AS LONG _                            ' __out BOOL *pOnline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBitsPeer_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumBitsPeers interface
' IID = 659CDEA5-489E-11D9-A9CD-000D56965251
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumBitsPeers_INTERFACE_DEFINED)
    %IEnumBitsPeers_INTERFACE_DEFINED = 1

$IID_IEnumBitsPeers = GUID$("{659CDEA5-489E-11D9-A9CD-000D56965251}")

INTERFACE IEnumBitsPeers $IID_IEnumBitsPeers

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IBitsPeer _                         ' __out IBitsPeer **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in ULONG *pceltFetched
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
     BYREF ppenum AS IEnumBitsPeers _                   ' __out IEnumBitsPeers **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumBitsPeers_INTERFACE_DEFINED__ */

' ########################################################################################
' IBitsPeerCacheAdministration interface
' IID = 659CDEAD-489E-11D9-A9CD-000D56965251
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBitsPeerCacheAdministration_INTERFACE_DEFINED)
    %IBitsPeerCacheAdministration_INTERFACE_DEFINED = 1

%BG_ENABLE_PEERCACHING_CLIENT = &H0001
%BG_ENABLE_PEERCACHING_SERVER = &H0002
%BG_DISABLE_BRANCH_CACHE      = &H0004

$IID_IBitsPeerCacheAdministration = GUID$("{659CDEAD-489E-11D9-A9CD-000D56965251}")

INTERFACE IBitsPeerCacheAdministration $IID_IBitsPeerCacheAdministration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMaximumCacheSize ( _                       ' VTable offset = 12
     BYREF pBytes AS DWORD _                            ' __out DWORD *pBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaximumCacheSize ( _                       ' VTable offset = 16
     BYVAL Bytes AS DWORD _                             ' __in DWORD Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumContentAge ( _                      ' VTable offset = 20
     BYREF pSeconds AS DWORD _                          ' __out ULONG *pSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaximumContentAge ( _                      ' VTable offset = 24
     BYVAL Seconds AS DWORD _                           ' __in ULONG Seconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConfigurationFlags ( _                     ' VTable offset = 28
     BYREF pFlags AS DWORD _                            ' __out DWORD *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConfigurationFlags ( _                     ' VTable offset = 32
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRecords ( _                               ' VTable offset = 36
     BYREF ppEnum AS IEnumBitsPeerCacheRecords _        ' __out IEnumBitsPeerCacheRecords **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecord ( _                                 ' VTable offset = 40
     BYREF id AS GUID _                                 ' __in REFGUID id
   , BYREF ppRecord AS IBitsPeerCacheRecord _           ' __out IBitsPeerCacheRecord **ppRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRecords ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteRecord ( _                              ' VTable offset = 48
     BYREF id AS GUID _                                 ' __in REFGUID id
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteUrl ( _                                 ' VTable offset = 52
     BYREF url AS WSTRINGZ _                            ' __in LPCWSTR url
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumPeers ( _                                 ' VTable offset = 56
     BYREF ppEnum AS IEnumBitsPeers _                   ' __out IEnumBitsPeers **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearPeers ( _                                ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscoverPeers ( _                             ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBitsPeerCacheAdministration_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyJob4 interface
' IID = 659CDEAE-489E-11D9-A9CD-000D56965251
' Inherited interface = IBackgroundCopyJob3
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyJob4_INTERFACE_DEFINED)
    %IBackgroundCopyJob4_INTERFACE_DEFINED = 1

%BG_JOB_ENABLE_PEERCACHING_CLIENT = &H0001
%BG_JOB_ENABLE_PEERCACHING_SERVER = &H0002
%BG_JOB_DISABLE_BRANCH_CACHE      = &H0004

$IID_IBackgroundCopyJob4 = GUID$("{659CDEAE-489E-11D9-A9CD-000D56965251}")

INTERFACE IBackgroundCopyJob4 $IID_IBackgroundCopyJob4

   INHERIT IUnknown

   ' =====================================================================================
   ' IBackgroundCopyJob Methods
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

   ' =====================================================================================
   ' IBackgroundCopyJob2 Methods
   ' =====================================================================================
   METHOD SetNotifyCmdLine ( _                          ' VTable offset = 140
     BYREF Program AS WSTRINGZ _                        ' __in LPCWSTR Program
   , BYREF Parameters AS WSTRINGZ _                     ' __in LPCWSTR Parameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyCmdLine ( _                          ' VTable offset = 144
     BYREF pProgram AS DWORD _                          ' __out LPWSTR *pProgram
   , BYREF pParameters AS DWORD _                       ' __out LPWSTR *pParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReplyProgress ( _                          ' VTable offset = 148
     BYREF pProgress AS BG_JOB_REPLY_PROGRESS _         ' __in_out BG_JOB_REPLY_PROGRESS *pProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReplyData ( _                              ' VTable offset = 152
     BYREF ppBuffer AS DWORD _                          ' __out byte **ppBuffer
   , BYREF pLength AS QUAD _                            ' __in_out UINT64 *pLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReplyFileName ( _                          ' VTable offset = 156
     BYREF ReplyFileName AS WSTRINGZ _                  ' __in LPCWSTR ReplyFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReplyFileName ( _                          ' VTable offset = 160
     BYREF pReplyFileName AS DWORD _                    ' __out LPWSTR *pReplyFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCredentials ( _                            ' VTable offset = 164
     BYREF credentials AS BG_AUTH_CREDENTIALS _         ' __in BG_AUTH_CREDENTIALS *credentials
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveCredentials ( _                         ' VTable offset = 168
     BYVAL Target AS BG_AUTH_TARGET_ENUM _              ' __in BG_AUTH_TARGET Target
   , BYVAL Scheme AS BG_AUTH_SCHEME_ENUM _              ' __in BG_AUTH_SCHEME Scheme
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBackgroundCopyJob3 Methods
   ' =====================================================================================
   METHOD ReplaceRemotePrefix ( _                       ' VTable offset = 172
     BYREF OldPrefix AS WSTRINGZ _                      ' __in LPCWSTR OldPrefix
   , BYREF NewPrefix AS WSTRINGZ _                      ' __in LPCWSTR NewPrefix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFileWithRanges ( _                         ' VTable offset = 176
     BYREF RemoteUrl AS WSTRINGZ _                      ' __in LPCWSTR RemoteUrl
   , BYREF LocalName AS WSTRINGZ _                      ' __in LPCWSTR LocalName
   , BYVAL RangeCount AS DWORD _                        ' __in DWORD RangeCount
   , BYREF Ranges AS BG_FILE_RANGE _                    ' __in BG_FILE_RANGE Ranges[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileACLFlags ( _                           ' VTable offset = 180
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileACLFlags ( _                           ' VTable offset = 184
     BYREF Flags AS DWORD _                             ' __out DWORD *Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBackgroundCopyJob4 Methods
   ' =====================================================================================
   METHOD SetPeerCachingFlags ( _                       ' VTable offset = 188
     BYVAL Flags AS DWORD _                             ' DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPeerCachingFlags ( _                       ' VTable offset = 192
     BYREF pFlags AS DWORD _                            ' __out DWORD *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOwnerIntegrityLevel ( _                    ' VTable offset = 196
     BYREF pLevel AS DWORD _                            ' __out ULONG *pLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOwnerElevationState ( _                    ' VTable offset = 200
     BYREF pElevated AS LONG _                          ' __out BOOL *pElevated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaximumDownloadTime ( _                    ' VTable offset = 204
     BYVAL Timeout AS DWORD _                           ' __in ULONG Timeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaximumDownloadTime ( _                    ' VTable offset = 208
     BYREF pTimeout AS DWORD _                          ' __out ULONG *pTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyJob4_INTERFACE_DEFINED__ */

' ########################################################################################
' IBackgroundCopyFile3 interface
' IID = 659CDEAA-489E-11D9-A9CD-000D56965251
' Inherited interface = IBackgroundCopyFile2
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyFile3_INTERFACE_DEFINED)
    %IBackgroundCopyFile3_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyFile3 = GUID$("{659CDEAA-489E-11D9-A9CD-000D56965251}")

INTERFACE IBackgroundCopyFile3 $IID_IBackgroundCopyFile3

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
   METHOD GetFileRanges ( _                             ' VTable offset = 24
     BYVAL RangeCount AS DWORD _                        ' __in_out DWORD *RangeCount
   , BYREF Ranges AS BG_FILE_RANGE _                    ' __out BG_FILE_RANGE **Ranges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRemoteName ( _                             ' VTable offset = 28
     BYREF Val AS WSTRINGZ _                            ' __in LPCWSTR Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTemporaryName ( _                          ' VTable offset = 32
     BYREF pFilename AS DWORD _                         ' __out LPWSTR *pFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValidationState ( _                        ' VTable offset = 36
     BYVAL state AS LONG _                              ' __in BOOL state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValidationState ( _                        ' VTable offset = 40
     BYREF pState AS LONG _                             ' __out BOOL *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDownloadedFromPeer ( _                      ' VTable offset = 44
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyFile3_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyCallback2 interface
' IID = 659CDEAC-489E-11D9-A9CD-000D56965251
' Inherited interface = IBackgroundCopyCallback
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyCallback2_INTERFACE_DEFINED)
    %IBackgroundCopyCallback2_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyCallback2 = GUID$("{659CDEAC-489E-11D9-A9CD-000D56965251}")

INTERFACE IBackgroundCopyCallback2 $IID_IBackgroundCopyCallback2

   INHERIT IUnknown

   ' =====================================================================================
   ' IBackgroundCopyCallback Methods
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

   ' =====================================================================================
   ' IBackgroundCopyCallback Methods
   ' =====================================================================================
   METHOD FileTransferred ( _                           ' VTable offset = 24
     BYVAL pJob AS IBackgroundCopyJob _                 ' __in IBackgroundCopyJob *pJob
   , BYVAL pFile AS IBackgroundCopyFile _               ' __in IBackgroundCopyFile *pFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyCallback2_INTERFACE_DEFINED__ */

#INCLUDE ONCE "bits4_0.inc"
