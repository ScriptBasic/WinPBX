' ########################################################################################
' Microsoft Windows
' File: werapi.inc
' Contents: This file contains the function prototypes for Windows Error Reporting (WER)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WERAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'//////////////////////// Defines //////////////////////////////////////////////

'typedef HANDLE HREPORT;

'//
'// Do not add heap dumps for reports for the process
'//
%WER_FAULT_REPORTING_FLAG_NOHEAP = 1

'//
'// Queue critical reports for this process
'//
%WER_FAULT_REPORTING_FLAG_QUEUE = 2

'//
'// Do not suspend the process before error reporting
'//
%WER_FAULT_REPORTING_FLAG_DISABLE_THREAD_SUSPENSION = 4

'//
'// Queue critical reports for this process and upload from the queue
'//
%WER_FAULT_REPORTING_FLAG_QUEUE_UPLOAD = 8

'//
'// Fault reporting UI should always be shown. This is only applicable for interactive processes
'//
%WER_FAULT_REPORTING_ALWAYS_SHOW_UI = 16

'//
'// Maximum length of the report event name
'//
%WER_MAX_EVENT_NAME_LENGTH = 64

'//
'// Maximum length of the name of a signature element
'//
%WER_MAX_SIGNATURE_NAME_LENGTH = 128

'//
'// This is the maximum length of any created URL
'//
%WER_MAX_TOTAL_PARAM_LENGTH = 1720

'//
'// This is the maximum length of any parameter including the NULL character
'//
%WER_MAX_PARAM_LENGTH = %MAX_PATH

'//
'// Number of extra modules that we can select to get extra data in the minidump
'//
%WER_MAX_PREFERRED_MODULES        = 128
%WER_MAX_PREFERRED_MODULES_BUFFER = 256

'//
'// Maximum number of parameters for a report
'//
%WER_MAX_PARAM_COUNT = 10

'//
'// The maximum size of memory block that can be registered
'//
%WER_MAX_MEM_BLOCK_SIZE = (64 * 1024)

'//
'// Event Type constant for application crashes
'//
'#define APPCRASH_EVENT          L"APPCRASH"
$APPCRASH_EVENT = "APPCRASH"

'// Indexes for the parameter ids
%WER_P0 = 0
%WER_P1 = 1
%WER_P2 = 2
%WER_P3 = 3
%WER_P4 = 4
%WER_P5 = 5
%WER_P6 = 6
%WER_P7 = 7
%WER_P8 = 8
%WER_P9 = 9

'//
'// Custom error HRESULTS
'//
'//  This error occurs if we are adding some parameter and this will cause the URL string to
'//  exceed the maximum length

%WER_ERROR_START = &Hff00&

'#define WER_E_INSUFFICIENT_BUFFER           (HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER))
%WER_E_INSUFFICIENT_BUFFER = &H8007007A&

'#define WER_E_NOT_FOUND                     (HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
%WER_E_NOT_FOUND = &H80070490&

'#define WER_E_LENGTH_EXCEEDED               (HRESULT_FROM_WIN32(ERROR_PARAMETER_QUOTA_EXCEEDED))
%WER_E_LENGTH_EXCEEDED = &H80070503&

'//
'// The API was called when it should not have been called. E.g trying to report the same
'// event twice when the first reportign is still going on
'#define WER_E_INVALID_STATE                 (HRESULT_FROM_WIN32(ERROR_INVALID_STATE))
%WER_E_INVALID_STATE = &H8007139F&

'// The store was disabled
'#define WER_E_STORE_DISABLED                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WINDOWS, WER_ERROR_START + 3)
%WER_E_STORE_DISABLED = &H8008FF03&

'//
'// There were some params that were missing, i.e the coniditon index A < B < C and parameter at B is null
'// but parameters at A and C are not
'#define WER_E_MISSING_PARAM                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WINDOWS, WER_ERROR_START + 5)
%WER_E_MISSING_PARAM = &H8008FF05&

'///////////////////////////////////////////////////////////////////////////////

'//
'// The enum that describes the indexes of the customizable UI strings
'//
' enum WER_REPORT_UI
%WerUIAdditionalDataDlgHeader  = 1
%WerUIIconFilePath             = 2
%WerUIConsentDlgHeader         = 3
%WerUIConsentDlgBody           = 4
%WerUIOnlineSolutionCheckText  = 5
%WerUIOfflineSolutionCheckText = 6
%WerUICloseText                = 7
%WerUICloseDlgHeader           = 8
%WerUICloseDlgBody             = 9
%WerUICloseDlgButtonText       = 10
%WerUICustomActionButtonText   = 11
%WerUIMax                      = 12

'//
'// The type of the registered files
'//
' enum WER_REGISTER_FILE_TYPE
%WerRegFileTypeUserDocument = 1
%WerRegFileTypeOther        = 2
%WerRegFileTypeMax          = 3

'//
'// The type of files that can be added to the report
'//
' enum WER_FILE_TYPE
%WerFileTypeMicrodump    = 1
%WerFileTypeMinidump     = 2
%WerFileTypeHeapdump     = 3
%WerFileTypeUserDocument = 4
%WerFileTypeOther        = 5
%WerFileTypeMax          = 6

' enum WER_SUBMIT_RESULT
%WerReportQueued    = 1
%WerReportUploaded  = 2
%WerReportDebug     = 3
%WerReportFailed    = 4
%WerDisabled        = 5
%WerReportCancelled = 6
%WerDisabledQueue   = 7
%WerReportAsync     = 8
%WerCustomAction    = 9

'//
'// The type of the report
'//
' enum WER_REPORT_TYPE
%WerReportNonCritical      = 0
%WerReportCritical         = 1
%WerReportApplicationCrash = 2
%WerReportApplicationHang  = 3
%WerReportKernel           = 4
%WerReportInvalid          = 5

'//
'// Flags that can be specified when adding a file to the report.
'//
'// NOTE: These should always occupy the lower 16 bits of the file flag dword.
'// The upper 16 bits are reserved for internal use and get cleared by WerAddFile.
'//
%WER_FILE_DELETE_WHEN_DONE      = 1???      ' // Delete the file once WER is done
%WER_FILE_ANONYMOUS_DATA        = 2???      ' // This file does not contain any PII

'//
'// Report submission flags.
'//
%WER_SUBMIT_HONOR_RECOVERY          = 1???      ' // show recovery option
%WER_SUBMIT_HONOR_RESTART           = 2???      ' // show application restart option
%WER_SUBMIT_QUEUE                   = 4???      ' // report directly to queue
%WER_SUBMIT_SHOW_DEBUG              = 8???      ' // show the debug button
%WER_SUBMIT_ADD_REGISTERED_DATA     = 16???     ' // Add registered data to the WER report
%WER_SUBMIT_OUTOFPROCESS            = 32???     ' // Force the report to go out of process
%WER_SUBMIT_NO_CLOSE_UI             = 64???     ' // Do not show the close dialog for the critical report
%WER_SUBMIT_NO_QUEUE                = 128???    ' // Do not queue the report
%WER_SUBMIT_NO_ARCHIVE              = 256???    ' // Do not archive the report
%WER_SUBMIT_START_MINIMIZED         = 512???    ' // The initial reporting UI is minimized and will flash
%WER_SUBMIT_OUTOFPROCESS_ASYNC      = 1024???  ' // The initial reporting UI is minimized and will flash
%WER_SUBMIT_BYPASS_DATA_THROTTLING  = 2048???   ' // Bypass data throttling for the report
%WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY = 4096???   ' // Archive only the parameters; the cab is discarded
%WER_SUBMIT_REPORT_MACHINE_ID       = 8192???   ' // Always send the machine ID, regardless of the consent the report was submitted with

' // Size = 2196 bytes
TYPE WER_REPORT_INFORMATION DWORD
   dwSize              AS DWORD                  ' DWORD
   hProcess            AS DWORD                  ' HANDLE
   wzConsentKey        AS WSTRINGZ * 64          ' WCHAR[64]
   wzFriendlyEventName AS WSTRINGZ * 128         ' WCHAR[128]
   wzApplicationName   AS WSTRINGZ * 128         ' WCHAR[128]
   wzApplicationPath   AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   wzDescription       AS WSTRINGZ * 512         ' WCHAR[512]
   hwndParent          AS DWORD
END TYPE

' // Size = 552 bytes
TYPE WER_DUMP_CUSTOM_OPTIONS DWORD
   dwSize                       AS DWORD   ' DWORD
   dwMask                       AS DWORD   ' DWORD
   dwDumpFlags                  AS DWORD   ' DWORD
   bOnlyThisThread              AS LONG    ' BOOL
   dwExceptionThreadFlags       AS DWORD   ' DWORD
   dwOtherThreadFlags           AS DWORD   ' DWORD
   dwExceptionThreadExFlags     AS DWORD   ' DWORD
   dwOtherThreadExFlags         AS DWORD   ' DWORD
   dwPreferredModuleFlags       AS DWORD   ' DWORD
   dwOtherModuleFlags           AS DWORD   ' DWORD
   wzPreferredModuleList AS STRING * %WER_MAX_PREFERRED_MODULES_BUFFER * 2   ' WCHAR
END TYPE

' // Size = 8 bytes
TYPE WER_EXCEPTION_INFORMATION DWORD
   pExceptionPointers AS EXCEPTION_POINTERS PTR   ' PEXCEPTION_POINTERS
   bClientPointers    AS LONG                     ' BOOL
END TYPE

' enum WER_CONSENT
%WerConsentNotAsked     = 1
%WerConsentApproved     = 2
%WerConsentDenied       = 3
%WerConsentAlwaysPrompt = 4
%WerConsentMax          = 5

DECLARE FUNCTION WerReportCreate IMPORT "WER.DLL" ALIAS "WerReportCreate" ( _
   BYREF pwzEventType AS WSTRINGZ _                     ' __in PCWSTR pwzEventType
 , BYVAL repType AS LONG _                              ' __in WER_REPORT_TYPE repType
 , BYREF pReportInformation AS WER_REPORT_INFORMATION _ ' __in_opt PWER_REPORT_INFORMATION pReportInformation
 , BYREF phReportHandle AS DWORD _                      ' __out HREPORT *phReportHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerReportSetParameter IMPORT "WER.DLL" ALIAS "WerReportSetParameter" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 , BYVAL dwparamID AS DWORD _                           ' __in DWORD dwparamID
 , BYREF pwzName AS WSTRINGZ _                          ' __in_opt PCWSTR pwzName
 , BYREF pwzValue AS WSTRINGZ _                         ' __in PCWSTR pwzValue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerReportAddFile IMPORT "WER.DLL" ALIAS "WerReportAddFile" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 , BYREF pwzPath AS WSTRINGZ _                          ' __in PCWSTR pwzPath
 , BYVAL repFileType AS LONG _                          ' __in WER_FILE_TYPE repFileType
 , BYVAL dwFileFlags AS DWORD _                         ' __in DWORD  dwFileFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerReportSetUIOption IMPORT "WER.DLL" ALIAS "WerReportSetUIOption" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 , BYVAL repUITypeID AS LONG _                          ' __in WER_REPORT_UI repUITypeID
 , BYREF pwzValue AS WSTRINGZ _                         ' __in PCWSTR pwzValue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerReportSubmit IMPORT "WER.DLL" ALIAS "WerReportSubmit" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 , BYVAL consent AS LONG _                              ' __in WER_CONSENT consent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYREF pSubmitResult AS LONG _                        ' __out_opt PWER_SUBMIT_RESULT pSubmitResult
 ) AS LONG                                              ' HRESULT

'//
'// Masks to be used for customizing the dump
'//
%WER_DUMP_MASK_START                  = 1???       ' 1
%WER_DUMP_MASK_DUMPTYPE               = &H1???     ' (WER_DUMP_MASK_START << 0)
%WER_DUMP_MASK_ONLY_THISTHREAD        = &H2???     ' (WER_DUMP_MASK_START << 1)
%WER_DUMP_MASK_THREADFLAGS            = &H4???     ' (WER_DUMP_MASK_START << 2)
%WER_DUMP_MASK_THREADFLAGS_EX         = &H8???     ' (WER_DUMP_MASK_START << 3)
%WER_DUMP_MASK_OTHERTHREADFLAGS       = &H10???    ' (WER_DUMP_MASK_START << 4)
%WER_DUMP_MASK_OTHERTHREADFLAGS_EX    = &H20???    ' (WER_DUMP_MASK_START << 5)
%WER_DUMP_MASK_PREFERRED_MODULESFLAGS = &H40???    ' (WER_DUMP_MASK_START << 6)
%WER_DUMP_MASK_OTHER_MODULESFLAGS     = &H80???    ' (WER_DUMP_MASK_START << 7)
%WER_DUMP_MASK_PREFERRED_MODULE_LIST  = &H100???   ' (WER_DUMP_MASK_START << 8)

'//
'// WER dump flags
'//
%WER_DUMP_NOHEAP_ONQUEUE = 1

' enum WER_DUMP_TYPE
%WerDumpTypeMicroDump = 1
%WerDumpTypeMiniDump  = 2
%WerDumpTypeHeapDump  = 3
%WerDumpTypeMax       = 4

DECLARE FUNCTION WerReportAddDump IMPORT "WER.DLL" ALIAS "WerReportAddDump" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 , BYVAL hProcess AS DWORD _                            ' __in HANDLE  hProcess
 , BYVAL hThread AS DWORD _                             ' __in_opt HANDLE hThread
 , BYVAL dumpType AS LONG _                             ' __in WER_DUMP_TYPE dumpType
 , BYREF pExceptionParam AS WER_EXCEPTION_INFORMATION _ ' __in_opt  PWER_EXCEPTION_INFORMATION pExceptionParam
 , BYREF WER_DUMP_CUSTOM_OPTIONS _                      ' __in_opt PWER_DUMP_CUSTOM_OPTIONS pDumpCustomOptions
 , BYVAL pDumpCustomOptions AS DWORD _                  ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerReportCloseHandle IMPORT "WER.DLL" ALIAS "WerReportCloseHandle" ( _
   BYVAL hReportHandle AS DWORD _                       ' __in HREPORT hReportHandle
 ) AS LONG                                              ' HRESULT

'//
'// ++++++++++++++++++++++++++ Registration APIs ++++++++++++++++++++++++++++++++++++++
'//

%WER_MAX_REGISTERED_ENTRIES = 512

DECLARE FUNCTION WerRegisterFile IMPORT "KERNEL32.DLL" ALIAS "WerRegisterFile" ( _
   BYREF pwzFile AS WSTRINGZ _                          ' __in PCWSTR pwzFile
 , BYVAL regFileType AS LONG _                          ' __in WER_REGISTER_FILE_TYPE regFileType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerUnregisterFile IMPORT "KERNEL32.DLL" ALIAS "WerUnregisterFile" ( _
   BYREF pwzFilePath AS WSTRINGZ _                      ' __in PCWSTR pwzFilePath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerRegisterMemoryBlock IMPORT "KERNEL32.DLL" ALIAS "WerRegisterMemoryBlock" ( _
   BYVAL pvAddress AS DWORD _                           ' __in PVOID pvAddress
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerUnregisterMemoryBlock IMPORT "KERNEL32.DLL" ALIAS "WerUnregisterMemoryBlock" ( _
   BYVAL pvAddress AS DWORD _                           ' __in PVOID pvAddress
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerSetFlags IMPORT "KERNEL32.DLL" ALIAS "WerSetFlags" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerGetFlags IMPORT "KERNEL32.DLL" ALIAS "WerGetFlags" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF pdwFlags AS DWORD _                            ' __out PDWORD pdwFlags
 ) AS LONG                                              ' HRESULT

'//
'// ++++++++++++++++++++++++++ Application Setup APIs ++++++++++++++++++++++++++++++++++++++
'//

DECLARE FUNCTION WerAddExcludedApplication IMPORT "WER.DLL" ALIAS "WerAddExcludedApplication" ( _
   BYREF pwzExeName AS WSTRINGZ _                       ' __in PCWSTR pwzExeName
 , BYVAL bAllUsers AS LONG _                            ' __in BOOL bAllUsers
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerRemoveExcludedApplication IMPORT "WER.DLL" ALIAS "WerRemoveExcludedApplication" ( _
   BYREF pwzExeName AS WSTRINGZ _                       ' __in PCWSTR pwzExeName
 , BYVAL bAllUsers AS LONG _                            ' __in BOOL bAllUsers
 ) AS LONG                                              ' HRESULT

'//
'// ++++++++++++++++++++++++++ Run time handler APIs +++++++++++++++++++++++++++
'//

%WER_MAX_REGISTERED_RUNTIME_EXCEPTION_MODULES = 16

DECLARE FUNCTION WerRegisterRuntimeExceptionModule IMPORT "KERNEL32.DLL" ALIAS "WerRegisterRuntimeExceptionModule" ( _
   BYREF pwszOutOfProcessCallbackDll AS WSTRINGZ _      ' __in PCWSTR pwszOutOfProcessCallbackDll
 , BYVAL pContext AS DWORD _                            ' __in PVOID pContext
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WerUnregisterRuntimeExceptionModule IMPORT "KERNEL32.DLL" ALIAS "WerUnregisterRuntimeExceptionModule" ( _
   BYREF pwszOutOfProcessCallbackDll AS WSTRINGZ _      ' __in PCWSTR pwszOutOfProcessCallbackDll
 , BYVAL pContext AS DWORD _                            ' __in PVOID pContext
 ) AS LONG                                              ' HRESULT

$WER_RUNTIME_EXCEPTION_EVENT_FUNCTION           = "OutOfProcessExceptionEventCallback"
$WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE_FUNCTION = "OutOfProcessExceptionEventSignatureCallback"
$WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH          = "OutOfProcessExceptionEventDebuggerLaunchCallback"

' // Size = 812 bytes
TYPE WER_RUNTIME_EXCEPTION_INFORMATION DWORD
   dwSize          AS DWORD                  ' DWORD
   hProcess        AS DWORD                  ' HANDLE
   hThread         AS DWORD                  ' HANDLE
   exceptionRecord AS EXCEPTION_RECORD       ' EXCEPTION_RECORD
   context         AS CONTEXT                ' CONTEXT
   pwszReportId    AS WSTRINGZ PTR           ' PCWSTR
END TYPE

'typedef
'HRESULT
'(* PFN_WER_RUNTIME_EXCEPTION_EVENT)(
'    __in PVOID pContext,
'    __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
'    __out BOOL * pbOwnershipClaimed,
'    __out_ecount(*pchSize) PWSTR pwszEventName,
'    __inout PDWORD  pchSize,
'    __out PDWORD  pdwSignatureCount
'    );

'FUNCTION WER_RUNTIME_EXCEPTION_EVENT ( _
'   BYVAL pContext AS DWORD _                            ' __in PVOID pContext
' , BYREF pExceptionInformation AS WER_RUNTIME_EXCEPTION_INFORMATION _ ' __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation
' , BYREF pbOwnershipClaimed AS LONG _                   ' __out BOOL * pbOwnershipClaimed
' , BYREF pwszEventName AS WSTRINGZ _                    ' __out_ecount(*pchSize) PWSTR pwszEventName
' , BYREF pchSize AS DWORD _                             ' __inout PDWORD pchSize
' , BYREF pdwSignatureCount AS DWORD _                   ' __out PDWORD pdwSignatureCount
' ) AS LONG                                              ' HRESULT

'typedef
'HRESULT
'(* PFN_WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE)(
'    __in PVOID pContext,
'    __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
'    __in DWORD dwIndex,
'    __out_ecount(*pchName) PWSTR pwszName,
'    __inout PDWORD  pchName,
'    __out_ecount(*pchValue) PWSTR pwszValue,
'    __inout PDWORD  pchValue
'    );

'FUNCTION WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE ( _
'   BYVAL pContext AS DWORD _                            ' __in PVOID pContext
' , BYREF pExceptionInformation AS WER_RUNTIME_EXCEPTION_INFORMATION _ ' __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation
' , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
' , BYREF pwszName AS WSTRINGZ _                         ' __out_ecount(*pchName) PWSTR pwszName
' , BYREF pchName AS DWORD _                             ' __inout PDWORD pchName
' , BYREF pwszValue AS WSTRINGZ _                        ' __out_ecount(*pchValue) PWSTR pwszValue
' , BYREF pchValue AS DWORD _                            ' __inout PDWORD pchValue
' ) AS LONG                                              ' HRESULT

'typedef
'HRESULT
'(* PFN_WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH)(
'    __in PVOID pContext,
'    __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
'    __out PBOOL pbIsCustomDebugger,
'    __out_ecount(*pchName) PWSTR pwszDebuggerLaunch,
'    __inout PDWORD  pchDebuggerLaunch,
'    __out PBOOL pbIsDebuggerAutolaunch
'    );

'FUNCTION WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH ( _
'   BYVAL pContext AS DWORD _                            ' __in PVOID pContext
' , BYREF pExceptionInformation AS WER_RUNTIME_EXCEPTION_INFORMATION _ ' __in const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation
' , BYREF pbIsCustomDebugger AS LONG _                   ' __out PBOOL pbIsCustomDebugger
' , BYREF pwszDebuggerLaunch AS WSTRINGZ _               ' __out_ecount(*pchName) PWSTR pwszDebuggerLaunch
' , BYREF pchDebuggerLaunch AS DWORD _                   ' __inout PDWORD pchDebuggerLaunch
' , BYREF pbIsDebuggerAutolaunch AS LONG _               ' __out PBOOL pbIsDebuggerAutolaunch
' ) AS LONG                                              ' HRESULT
