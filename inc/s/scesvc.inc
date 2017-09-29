' ########################################################################################
' Microsoft Windows
' File: scesvc.inc
' Contents: Wrapper APIs for services
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SCESVC_INC = 1

$cNodetypeSceTemplateServices     = GUID$("{24A7F717-1F0C-11D1-AFFB-00C04FB984F9}")
$cNodetypeSceAnalysisServices     = GUID$("{678050C7-1FF8-11D1-AFFB-00C04FB984F9}")
$cNodetypeSceEventLog             = GUID$("{2CE06698-4BF3-11D1-8C30-00C04FB984F9}")
$IID_ISceSvcAttachmentPersistInfo = GUID$("{6D90E0D0-200D-11D1-AFFB-00C04FB984F9}")
$IID_ISceSvcAttachmentData        = GUID$("{17C35FDE-200D-11D1-AFFB-00C04FB984F9}")

'#ifndef _SCE_SHARED_HEADER
'#define _SCE_SHARED_HEADER

'typedef DWORD                   SCESTATUS;

%SCESTATUS_SUCCESS              = 0???
%SCESTATUS_INVALID_PARAMETER    = 1???
%SCESTATUS_RECORD_NOT_FOUND     = 2???
%SCESTATUS_INVALID_DATA         = 3???
%SCESTATUS_OBJECT_EXIST         = 4???
%SCESTATUS_BUFFER_TOO_SMALL     = 5???
%SCESTATUS_PROFILE_NOT_FOUND    = 6???
%SCESTATUS_BAD_FORMAT           = 7???
%SCESTATUS_NOT_ENOUGH_RESOURCE  = 8???
%SCESTATUS_ACCESS_DENIED        = 9???
%SCESTATUS_CANT_DELETE          = 10???
%SCESTATUS_PREFIX_OVERFLOW      = 11???
%SCESTATUS_OTHER_ERROR          = 12???
%SCESTATUS_ALREADY_RUNNING      = 13???
%SCESTATUS_SERVICE_NOT_SUPPORT  = 14???
%SCESTATUS_MOD_NOT_FOUND        = 15???
%SCESTATUS_EXCEPTION_IN_SERVER  = 16???
%SCESTATUS_NO_TEMPLATE_GIVEN    = 17???
%SCESTATUS_NO_MAPPING           = 18???
%SCESTATUS_TRUST_FAIL           = 19???

' // Size = 12 bytes
TYPE SCESVC_CONFIGURATION_LINE DWORD
   Key      AS ASCIIZ PTR   ' LPTSTR
   Value    AS ASCIIZ PTR   ' LPTSTR
   ValueLen AS DWORD        ' DWORD // number of bytes
END TYPE

' // Size = 8 bytes
TYPE SCESVC_CONFIGURATION_INFO DWORD
   Count AS DWORD                           ' DWORD
   Lines AS SCESVC_CONFIGURATION_LINE PTR   ' PSCESVC_CONFIGURATION_LINE
END TYPE

'typedef PVOID SCE_HANDLE;
'typedef ULONG SCE_ENUMERATION_CONTEXT, *PSCE_ENUMERATION_CONTEXT;

' enum SCESVC_INFO_TYPE
%SceSvcConfigurationInfo = 0
%SceSvcMergedPolicyInfo  = 1
%SceSvcAnalysisInfo      = 2
%SceSvcInternalUse       = 3   ' // !!!do not use this type!!!

'#define SCE_ROOT_PATH TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\SeCEdit")
$SCE_ROOT_PATH = "Software\Microsoft\Windows NT\CurrentVersion\SeCEdit"

'#define SCE_ROOT_SERVICE_PATH   \
'            SCE_ROOT_PATH TEXT("\\SvcEngs")
$SCE_ROOT_SERVICE_PATH = $SCE_ROOT_PATH & "\SvcEngs"

'#endif

'typedef PVOID SCESVC_HANDLE;

' // Size = 12 bytes
TYPE SCESVC_ANALYSIS_LINE DWORD
   Key      AS ASCIIZ PTR   ' LPTSTR
   Value    AS BYTE PTR     ' PBYTE
   ValueLen AS DWORD        ' DWORD // number of bytes
END TYPE

' // Size = 8 bytes
TYPE SCESVC_ANALYSIS_INFO DWORD
   Count AS DWORD                      ' DWORD
   Lines AS SCESVC_ANALYSIS_LINE PTR   ' PSCESVC_ANALYSIS_LINE
END TYPE

%SCESVC_ENUMERATION_MAX = 100???

'typedef
'SCESTATUS
'(CALLBACK *PFSCE_QUERY_INFO)(
'    IN SCE_HANDLE           sceHandle,
'    IN SCESVC_INFO_TYPE     sceType,
'    IN LPTSTR               lpPrefix OPTIONAL,
'    IN BOOL                 bExact,
'    OUT PVOID               *ppvInfo,
'    OUT PSCE_ENUMERATION_CONTEXT psceEnumHandle
');

'FUNCTION FSCE_QUERY_INFO ( _
'   BYVAL sceHandle AS DWORD _        ' __in SCE_HANDLE
' , BYVAL sceType AS LONG _           ' __in SCESVC_INFO_TYPE
' , BYREF lpPrefix ASCIIZ _           ' __in LPTSTR
' , BYVAL bExact AS LONG _            ' __in BOOL
' , BYREF ppvInfo AS DWORD _          ' __out PVOID
' , BYREF psceEnumHandle AS DWORD _   ' __out PSCE_ENUMERATION_CONTEXT
' ) AS DWORD                          ' SCESTATUS

'typedef
'SCESTATUS
'(CALLBACK *PFSCE_SET_INFO)(
'    IN SCE_HANDLE           sceHandle,
'    IN SCESVC_INFO_TYPE     sceType,
'    IN LPTSTR               lpPrefix OPTIONAL,
'    IN BOOL                 bExact,
'    IN PVOID                pvInfo
');

'FUNCTION FSCE_SET_INFO ( _
'   BYVAL sceHandle AS DWORD _        ' __in SCE_HANDLE
' , BYVAL sceType AS LONG _           ' __in SCESVC_INFO_TYPE
' , BYREF lpPrefix ASCIIZ _           ' __in LPTSTR
' , BYVAL bExact AS LONG _            ' __in BOOL
' , BYVAL pvInfo AS DWORD _           ' __in PVOID
' ) AS DWORD                          ' SCESTATUS

'typedef
'SCESTATUS
'(CALLBACK *PFSCE_FREE_INFO)(
'    IN PVOID                pvServiceInfo
');

'FUNCTION FSCE_FREE_INFO ( _
'   BYVAL pvServiceInfo AS DWORD _    ' __in PVOID
' ) AS DWORD                          ' SCESTATUS

%SCE_LOG_LEVEL_ALWAYS     = 0
%SCE_LOG_LEVEL_ERROR      = 1
%SCE_LOG_LEVEL_DETAIL     = 2
%SCE_LOG_LEVEL_DEBUG      = 3

'typedef
'SCESTATUS
'(CALLBACK *PFSCE_LOG_INFO)(
'    IN INT ErrLevel,
'    IN DWORD  Win32rc,
'    IN LPTSTR pErrFmt,
'    ...
');

' // Size = 20 bytes
TYPE SCESVC_CALLBACK_INFO DWORD
   sceHandle   AS DWORD   ' SCE_HANDLE
   pfQueryInfo AS DWORD   ' PFSCE_QUERY_INFO
   pfSetInfo   AS DWORD   ' PFSCE_SET_INFO
   pfFreeInfo  AS DWORD   ' PFSCE_FREE_INFO
   pfLogInfo   AS DWORD   ' PFSCE_LOG_INFO
END TYPE


'typedef
'SCESTATUS
'(*PF_ConfigAnalyzeService)(
'    IN PSCESVC_CALLBACK_INFO pSceCbInfo
');

'FUNCTION PF_ConfigAnalyzeService ( _
'   BYVAL pSceCbInfo AS DWORD _       ' __in PSCESVC_CALLBACK_INFO
' ) AS DWORD                          ' SCESTATUS

'typedef
'SCESTATUS
'(*PF_UpdateService)(
'    IN PSCESVC_CALLBACK_INFO      pSceCbInfo,
'    IN PSCESVC_CONFIGURATION_INFO ServiceInfo
');

'FUNCTION PF_UpdateService ( _
'   BYVAL pSceCbInfo AS DWORD _       ' __in PSCESVC_CALLBACK_INFO
' , BYVAL ServiceInfo AS DWORD _      ' __in PSCESVC_CONFIGURATION_INFO
' ) AS DWORD                          ' SCESTATUS

'#endif

'//#if _WIN32_WINNT==0x0500
'//
'// headers for extension snap-ins
'// only define this for NT5
'//

'#ifndef _UUIDS_SCE_ATTACHMENT_
'#define _UUIDS_SCE_ATTACHMENT_

'#define struuidNodetypeSceTemplateServices      "{24a7f717-1f0c-11d1-affb-00c04fb984f9}"
'#define lstruuidNodetypeSceTemplateServices      L"{24a7f717-1f0c-11d1-affb-00c04fb984f9}"

$struuidNodetypeSceTemplateServices = "{24a7f717-1f0c-11d1-affb-00c04fb984f9}"

'#define struuidNodetypeSceAnalysisServices      "{678050c7-1ff8-11d1-affb-00c04fb984f9}"
'#define lstruuidNodetypeSceAnalysisServices      L"{678050c7-1ff8-11d1-affb-00c04fb984f9}"

$struuidNodetypeSceAnalysisServices = "{678050c7-1ff8-11d1-affb-00c04fb984f9}"

'#define struuidNodetypeSceEventLog      "{2ce06698-4bf3-11d1-8c30-00c04fb984f9}"
'#define lstruuidNodetypeSceEventLog      L"{2ce06698-4bf3-11d1-8c30-00c04fb984f9}"

$struuidNodetypeSceEventLog = "{2ce06698-4bf3-11d1-8c30-00c04fb984f9}"

'#define CCF_SCESVC_ATTACHMENT        L"CCF_SCESVC_ATTACHMENT"
'#define CCF_SCESVC_ATTACHMENT_DATA   L"CCF_SCESVC_ATTACHMENT_DATA"

$CCF_SCESVC_ATTACHMENT      = "CCF_SCESVC_ATTACHMENT"
$CCF_SCESVC_ATTACHMENT_DATA = "CCF_SCESVC_ATTACHMENT_DATA"

'//
'// implemented by service attachment
'//

' ########################################################################################
' ISceSvcAttachmentPersistInfo interface
' IID = 6D90E0D0-200D-11D1-AFFB-00C04FB984F9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISceSvcAttachmentPersistInfo_INTERFACE_DEFINED)
    %ISceSvcAttachmentPersistInfo_INTERFACE_DEFINED = 1

$IID_ISceSvcAttachmentPersistInfo = GUID$("{6D90E0D0-200D-11D1-AFFB-00C04FB984F9}")

INTERFACE ISceSvcAttachmentPersistInfo $IID_ISceSvcAttachmentPersistInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 12
     BYREF lpTemplateName AS ASCIIZ _                   ' __in  LPTSTR lpTemplateName
   , BYREF scesvcHandle AS DWORD _                      ' __out SCESVC_HANDLE *scesvcHandle
   , BYREF ppvData AS DWORD _                           ' __out PVOID *ppvData
   , BYREF pbOverwriteAll AS LONG _                     ' __out PBOOL pbOverwriteAll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
     BYREF lpTemplateName AS ASCIIZ _                   ' __in  LPTSTR lpTemplateName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYVAL pvData AS DWORD _                            ' __in PVOID pvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISceSvcAttachmentPersistInfo_INTERFACE_DEFINED__ */

'//
'// implemented by SecEdit
'//

' ########################################################################################
' ISceSvcAttachmentData interface
' IID = 17C35FDE-200D-11D1-AFFB-00C04FB984F9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISceSvcAttachmentData_INTERFACE_DEFINED)
    %ISceSvcAttachmentData_INTERFACE_DEFINED = 1

$IID_ISceSvcAttachmentData = GUID$("{17C35FDE-200D-11D1-AFFB-00C04FB984F9}")

INTERFACE ISceSvcAttachmentData $IID_ISceSvcAttachmentData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYVAL scesvcHandle AS DWORD _                      ' __in SCESVC_HANDLE scesvcHandle
   , BYVAL sceType AS LONG _                            ' __in SCESVC_INFO_TYPE sceType
   , BYREF ppvData AS DWORD _                           ' __out PVOID *ppvData
   , BYREF psceEnumHandle AS DWORD _                    ' __in_out PSCE_ENUMERATION_CONTEXT psceEnumHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 16
     BYREF lpServiceName AS ASCIIZ _                    ' __in LPCTSTR lpServiceName
   , BYREF lpTemplateName AS ASCIIZ _                   ' __in LPCTSTR lpTemplateName
   , BYVAL lpSceSvcPersistInfo AS ISceSvcAttachmentPersistInfo _ ' __in LPSCESVCATTACHMENTPERSISTINFO lpSceSvcPersistInfo
   , BYREF pscesvcHandle AS DWORD _                     ' __out SCESVC_HANDLE *pscesvcHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBuffer ( _                                ' VTable offset = 20
     BYVAL pvData AS DWORD _                            ' __in PVOID pvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseHandle ( _                               ' VTable offset = 24
     BYVAL scesvcHandle AS DWORD _                      ' __in SCESVC_HANDLE scesvcHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISceSvcAttachmentData_INTERFACE_DEFINED__ */

'#endif // _UUIDS_COMPUTER_MANAGEMENT_
