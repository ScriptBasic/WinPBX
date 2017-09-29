' ########################################################################################
' Microsoft Windows
' File: bits2_0.inc
' Library name: BackgroundCopyManager2_0
' Version: 1.0, Locale ID = 0
' Library GUID: {2289A9AF-DC96-486E-B268-89C9E3397C3D}
' Contents: Microsoft Background Copy Manager 2.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITS2_0_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "bits.inc"
#INCLUDE ONCE "bits1_5.inc"

%BG_LENGTH_TO_EOF    = -1&&   ' (UINT64)(-1)

' // Size = 16 bytes
TYPE BG_FILE_RANGE QWORD
   InitialOffset AS QUAD   ' UINT64
   Length        AS QUAD   ' UINT64
END TYPE

%BG_COPY_FILE_OWNER = 1
%BG_COPY_FILE_GROUP = 2
%BG_COPY_FILE_DACL  = 4
%BG_COPY_FILE_SACL  = 8
%BG_COPY_FILE_ALL   = 15

'EXTERN_C const IID LIBID_BackgroundCopyManager2_0;
$CLSID_BackgroundCopyManager2_0 = GUID$("{6D18AD12-BDE3-4393-B311-099C346E6DF9}")

' ########################################################################################
' IBackgroundCopyJob3 interface
' IID = 443C8934-90FF-48ED-BCDE-26F5C7450042
' Inherited interface = IBackgroundCopyJob2
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyJob3_INTERFACE_DEFINED)
    %IBackgroundCopyJob3_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyJob3 = GUID$("{443C8934-90FF-48ED-BCDE-26F5C7450042}")

INTERFACE IBackgroundCopyJob3 $IID_IBackgroundCopyJob3

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

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyJob3_INTERFACE_DEFINED__ */


' ########################################################################################
' IBackgroundCopyFile2 interface
' IID = 83E81B93-0873-474D-8A8C-F2018B1A939C
' Inherited interface = IBackgroundCopyFile
' ########################################################################################

#IF NOT %DEF(%IBackgroundCopyFile2_INTERFACE_DEFINED)
    %IBackgroundCopyFile2_INTERFACE_DEFINED = 1

$IID_IBackgroundCopyFile2 = GUID$("{83E81B93-0873-474D-8A8C-F2018B1A939C}")

INTERFACE IBackgroundCopyFile2 $IID_IBackgroundCopyFile2

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

END INTERFACE

#ENDIF   ' /* __IBackgroundCopyFile2_INTERFACE_DEFINED__ */
