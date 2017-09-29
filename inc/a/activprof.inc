' ########################################################################################
' Microsoft Windows
' File: ActivProf.inc
' Contents: Declarations for ActiveX Scripting profiling.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACTIVPROF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

%ACTIVPROF_E_PROFILER_PRESENT       = &H80040200&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200);
%ACTIVPROF_E_PROFILER_ABSENT        = &H80040201&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0201);
%ACTIVPROF_E_UNABLE_TO_APPLY_ACTION = &H80040202&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202);

' Enum PROFILER_SCRIPT_TYPE
MACRO PROFILER_SCRIPT_TYPE_ENUM = LONG
%PROFILER_SCRIPT_TYPE_USER    = 0
%PROFILER_SCRIPT_TYPE_DYNAMIC = %PROFILER_SCRIPT_TYPE_USER    + 1
%PROFILER_SCRIPT_TYPE_NATIVE  = %PROFILER_SCRIPT_TYPE_DYNAMIC + 1

' Enum PROFILER_EVENT_MASK
%PROFILER_EVENT_MASK_TRACE_SCRIPT_FUNCTION_CALL = &H1???
%PROFILER_EVENT_MASK_TRACE_NATIVE_FUNCTION_CALL = &H2???
%PROFILER_EVENT_MASK_TRACE_ALL = %PROFILER_EVENT_MASK_TRACE_SCRIPT_FUNCTION_CALL OR %PROFILER_EVENT_MASK_TRACE_NATIVE_FUNCTION_CALL

'typedef LONG PROFILER_TOKEN;
MACRO PROFILER_TOKEN = LONG

' ########################################################################################
' Interface name = IActiveScriptProfilerControl
' IID = 784b5ff0-69b0-47d1-a7dc-2518f4230e90
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptProfilerControl_INTERFACE_DEFINED)
    %IActiveScriptProfilerControl_INTERFACE_DEFINED = 1

$IID_IActiveScriptProfilerControl = GUID$("{784b5ff0-69b0-47d1-a7dc-2518f4230e90}")

INTERFACE IActiveScriptProfilerControl $IID_IActiveScriptProfilerControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartProfiling ( _                            ' VTable offset = 12
     BYREF clsidProfilerObject AS GUID _                ' __in REFCLSID clsidProfilerObject
   , BYVAL dwEventMask AS DWORD _                       ' __in DWORD dwEventMask
   , BYVAL dwContext AS DWORD _                         ' __in DWORD dwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProfilerEventMask ( _                      ' VTable offset = 16
     BYVAL dwEventMask AS DWORD _                       ' __in DWORD dwEventMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopProfiling ( _                             ' VTable offset = 20
     BYVAL hrShutdownReason AS LONG _                   ' __in HRESULT hrShutdownReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptProfilerControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IActiveScriptProfilerCallback
' IID = 740eca23-7d9d-42e5-ba9d-f8b24b1c7a9b
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveScriptProfilerCallback_INTERFACE_DEFINED)
    %IActiveScriptProfilerCallback_INTERFACE_DEFINED = 1

$IID_IActiveScriptProfilerCallback = GUID$("{740eca23-7d9d-42e5-ba9d-f8b24b1c7a9b}")

INTERFACE IActiveScriptProfilerCallback $IID_IActiveScriptProfilerCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL dwContext AS DWORD _                         ' __in DWORD dwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 16
     BYVAL hrReason AS LONG _                           ' __in HRESULT hrReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScriptCompiled ( _                            ' VTable offset = 20
     BYVAL scriptId AS PROFILER_TOKEN _                 ' __in PROFILER_TOKEN scriptId
   , BYVAL type AS PROFILER_SCRIPT_TYPE_ENUM _          ' __in PROFILER_SCRIPT_TYPE type
   , BYVAL pIDebugDocumentContext AS IUnknown _         ' __in IUnknown *pIDebugDocumentContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FunctionCompiled ( _                          ' VTable offset = 24
     BYVAL functionId AS PROFILER_TOKEN _               ' __in PROFILER_TOKEN functionId
   , BYVAL scriptId AS PROFILER_TOKEN _                 ' __in PROFILER_TOKEN scriptId
   , BYREF pwszFunctionName AS WSTRINGZ _               ' __in const WCHAR *pwszFunctionName
   , BYREF pwszFunctionNameHint AS WSTRINGZ _           ' __in const WCHAR *pwszFunctionNameHint
   , BYVAL pIDebugDocumentContext AS IUnknown _         ' __in IUnknown *pIDebugDocumentContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFunctionEnter ( _                           ' VTable offset = 28
     BYVAL scriptId AS PROFILER_TOKEN _                 ' __in PROFILER_TOKEN scriptId
   , BYVAL functionId AS PROFILER_TOKEN _               ' __in PROFILER_TOKEN functionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFunctionExit ( _                            ' VTable offset = 32
     BYVAL scriptId AS PROFILER_TOKEN _                 ' __in PROFILER_TOKEN scriptId
   , BYVAL functionId AS PROFILER_TOKEN _               ' __in PROFILER_TOKEN functionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveScriptProfilerCallback_INTERFACE_DEFINED__ */
