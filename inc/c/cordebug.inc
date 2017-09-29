' ########################################################################################
' Microsoft Windows
' File: cordebug.inc
' Library name: CORDBLib
' Version: 1.0, Locale ID = 0
' Library GUID: {53D13620-F417-11D1-9762-A63826A4F255}
' Contents: Common Language Runtime Debugging 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Note: Added the prefix %CORDEBUG_ to the equates to avoid name conflicts.
' ########################################################################################

#INCLUDE THIS ONCE
%CORDEBUG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"

$LIBID_CORDBLib = GUID$("{53D13620-F417-11D1-9762-A63826A4F255}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_CorDebug1 = "ComPlusDebug.CorDebug.1"
$PROGID_CorDebug = "ComPlusDebug.CorDebug"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_EmbeddedCLRCorDebug = GUID$("{211F1254-BC7E-4AF5-B9AA-067308D83DD1}")
$CLSID_CorDebug = GUID$("{6FEF44D0-39E7-4C77-BE8E-C9F8CF988630}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICorDebug = GUID$("{3D6F5F61-7538-11D3-8D5B-00104B35E7EF}")
$IID_ICorDebug2 = GUID$("{ECCCCF2E-B286-4b3e-A983-860A8793D105}")
$IID_ICorDebugAppDomain = GUID$("{3D6F5F63-7538-11D3-8D5B-00104B35E7EF}")
$IID_ICorDebugAppDomain2 = GUID$("{096E81D5-ECDA-4202-83F5-C65980A9EF75}")
$IID_ICorDebugAppDomainEnum = GUID$("{63CA1B24-4359-4883-BD57-13F815F58744}")
$IID_ICorDebugArrayValue = GUID$("{0405B0DF-A660-11D2-BD02-0000F80849BD}")
$IID_ICorDebugAssembly = GUID$("{DF59507C-D47A-459E-BCE2-6427EAC8FD06}")
$IID_ICorDebugAssembly2 = GUID$("{426D1F9E-6DD4-44C8-AEC7-26CDBAF4E398}")
$IID_ICorDebugAssemblyEnum = GUID$("{4A2A1EC9-85EC-4BFB-9F15-A89FDFE0FE83}")
$IID_ICorDebugBlockingObjectEnum = GUID$("{976A6278-134A-4A81-81A3-8F277943F4C3}")
$IID_ICorDebugBoxValue = GUID$("{CC7BCAFC-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugBreakpoint = GUID$("{CC7BCAE8-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugBreakpointEnum = GUID$("{CC7BCB03-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugChain = GUID$("{CC7BCAEE-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugChainEnum = GUID$("{CC7BCB08-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugClass = GUID$("{CC7BCAF5-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugClass2 = GUID$("{B008EA8D-7AB1-43F7-BB20-FBB5A04038AE}")
$IID_ICorDebugCode = GUID$("{CC7BCAF4-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugCode2 = GUID$("{5F696509-452F-4436-A3FE-4D11FE7E2347}")
$IID_ICorDebugCodeEnum = GUID$("{55E96461-9645-45E4-A2FF-0367877ABCDE}")
$IID_ICorDebugContext = GUID$("{CC7BCB00-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugController = GUID$("{3D6F5F62-7538-11D3-8D5B-00104B35E7EF}")
$IID_ICorDebugDataTarget = GUID$("{FE06DC28-49FB-4636-A4A3-E80DB4AE116C}")
$IID_ICorDebugEditAndContinueSnapshot = GUID$("{6DC3FA01-D7CB-11D2-8A95-0080C792E5D8}")
$IID_ICorDebugEditAndContinueErrorInfo = GUID$("{8D600D41-F4F6-4cb3-B7EC-7BD164944036}")
$IID_ICorDebugEnum = GUID$("{CC7BCB01-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugErrorInfoEnum = GUID$("{F0E18809-72B5-11D2-976F-00A0C9B4D50C}")
$IID_ICorDebugEval = GUID$("{CC7BCAF6-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugEval2 = GUID$("{FB0D9CE7-BE66-4683-9D32-A42A04E2FD91}")
$IID_ICorDebugFrame = GUID$("{CC7BCAEF-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugFrameEnum = GUID$("{CC7BCB07-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugFunction = GUID$("{CC7BCAF3-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugFunction2 = GUID$("{EF0C490B-94C3-4E4D-B629-DDC134C532D8}")
$IID_ICorDebugFunctionBreakpoint = GUID$("{CC7BCAE9-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugGenericValue = GUID$("{CC7BCAF8-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugHandleValue = GUID$("{029596E8-276B-46A1-9821-732E96BBB00B}")
$IID_ICorDebugHeapValue = GUID$("{CC7BCAFA-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugHeapValue2 = GUID$("{E3AC4D6C-9CB7-43E6-96CC-B21540E5083C}")
$IID_ICorDebugHeapValue3 = GUID$("{A69ACAD8-2374-46E9-9FF8-B1F14120D296}")
$IID_ICorDebugILFrame = GUID$("{03E26311-4F76-11D3-88C6-006097945418}")
$IID_ICorDebugILFrame2 = GUID$("{5D88A994-6C30-479B-890F-BCEF88B129A5}")
$IID_ICorDebugInternalFrame = GUID$("{B92CC7F7-9D2D-45C4-BC2B-621FCC9DFBF4}")
$IID_ICorDebugInternalFrame2 = GUID$("{C0815BDC-CFAB-447E-A779-C116B454EB5B}")
$IID_ICorDebugManagedCallback = GUID$("{3D6F5F60-7538-11D3-8D5B-00104B35E7EF}")
$IID_ICorDebugManagedCallback2 = GUID$("{250E5EEA-DB5C-4C76-B6F3-8C46F12E3203}")
$IID_ICorDebugManagedCallback3 = GUID$("{264EA0FC-2591-49AA-868E-835E6515323F}")
$IID_ICorDebugMDA = GUID$("{CC726F2F-1DB7-459B-B0EC-05F01D841B42}")
$IID_ICorDebugMetaDataLocator = GUID$("{7CEF8BA9-2EF7-42BF-973F-4171474F87D9}")
$IID_ICorDebugModule = GUID$("{DBA2D8C1-E5C5-4069-8C13-10A7C6ABF43D}")
$IID_ICorDebugModule2 = GUID$("{7FCC5FB5-49C0-41DE-9938-3B88B5B9ADD7}")
$IID_ICorDebugModule3 = GUID$("{86F012BF-FF15-4372-BD30-B6F11CAAE1DD}")
$IID_ICorDebugModuleBreakpoint = GUID$("{CC7BCAEA-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugModuleEnum = GUID$("{CC7BCB09-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugNativeFrame = GUID$("{03E26314-4F76-11D3-88C6-006097945418}")
$IID_ICorDebugNativeFrame2 = GUID$("{35389FF1-3684-4C55-A2EE-210F26C60E5E}")
$IID_ICorDebugObjectEnum = GUID$("{CC7BCB02-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugObjectValue = GUID$("{18AD3D6E-B7D2-11D2-BD04-0000F80849BD}")
$IID_ICorDebugObjectValue2 = GUID$("{49E4A320-4A9B-4ECA-B105-229FB7D5009F}")
$IID_ICorDebugProcess = GUID$("{3D6F5F64-7538-11D3-8D5B-00104B35E7EF}")
$IID_ICorDebugProcess2 = GUID$("{AD1B3588-0EF0-4744-A496-AA09A9F80371}")
$IID_ICorDebugProcess3 = GUID$("{2EE06488-C0D4-42B1-B26D-F3795EF606FB}")
$IID_ICorDebugProcessEnum = GUID$("{CC7BCB05-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugReferenceValue = GUID$("{CC7BCAF9-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugRegisterSet = GUID$("{CC7BCB0B-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugRegisterSet2 = GUID$("{6DC7BA3F-89BA-4459-9EC1-9D60937B468D}")
$IID_ICorDebugRemote = GUID$("{D5EBB8E2-7BBE-4C1D-98A6-A3C04CBDEF64}")
$IID_ICorDebugRemoteTarget = GUID$("{C3ED8383-5A49-4CF5-B4B7-01864D9E582D}")
$IID_ICorDebugRuntimeUnwindableFrame = GUID$("{879CAC0A-4A53-4668-B8E3-CB8473CB187F}")
$IID_ICorDebugStackWalk = GUID$("{A0647DE9-55DE-4816-929C-385271C64CF7}")
$IID_ICorDebugStepper = GUID$("{CC7BCAEC-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugStepper2 = GUID$("{C5B6E9C3-E7D1-4A8E-873B-7F047F0706F7}")
$IID_ICorDebugStepperEnum = GUID$("{CC7BCB04-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugStringValue = GUID$("{CC7BCAFD-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugThread = GUID$("{938C6D66-7FB6-4F69-B389-425B8987329B}")
$IID_ICorDebugThread2 = GUID$("{2BD956D9-7B07-4BEF-8A98-12AA862417C5}")
$IID_ICorDebugThread3 = GUID$("{F8544EC3-5E4E-46C7-8D3E-A52B8405B1F5}")
$IID_ICorDebugThread4 = GUID$("{1A1F204B-1C66-4637-823F-3EE6C744A69C}")
$IID_ICorDebugThreadEnum = GUID$("{CC7BCB06-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugType = GUID$("{D613F0BB-ACE1-4C19-BD72-E4C08D5DA7F5}")
$IID_ICorDebugTypeEnum = GUID$("{10F27499-9DF2-43CE-8333-A321D7C99CB4}")
$IID_ICorDebugUnmanagedCallback = GUID$("{5263E909-8CB5-11D3-BD2F-0000F80849BD}")
$IID_ICorDebugValue = GUID$("{CC7BCAF7-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugValue2 = GUID$("{5E0B54E7-D88A-4626-9420-A691E0A78B49}")
$IID_ICorDebugValueBreakpoint = GUID$("{CC7BCAEB-8A68-11D2-983C-0000F808342D}")
$IID_ICorDebugValueEnum = GUID$("{CC7BCB0A-8A68-11D2-983C-0000F808342D}")

'#if 0
'typedef UINT32 mdToken;
'typedef mdToken mdModule;
'typedef SIZE_T mdScope;
'typedef mdToken mdTypeDef;
'typedef mdToken mdSourceFile;
'typedef mdToken mdMemberRef;
'typedef mdToken mdMethodDef;
'typedef mdToken mdFieldDef;
'typedef mdToken mdSignature;
'typedef ULONG CorElementType;
'typedef SIZE_T PCCOR_SIGNATURE;
'typedef SIZE_T LPDEBUG_EVENT;
'typedef SIZE_T LPSTARTUPINFOW;
'typedef SIZE_T LPPROCESS_INFORMATION;
'#endif
'typedef /* [wire_marshal] */ void *HPROCESS;
'typedef /* [wire_marshal] */ void *HTHREAD;
'typedef UINT64 TASKID;
'typedef DWORD CONNID;

#IF NOT %DEF(%COR_IL_MAP)
%COR_IL_MAP = 1
' // Size = 12 bytes
TYPE COR_IL_MAP DWORD
   oldOffset AS DWORD   ' ULONG32
   newOffset AS DWORD   ' ULONG32
   fAccurate AS LONG    ' BOOL
END TYPE
#ENDIF   ' //_COR_IL_MAP

#IF NOT %DEF(%COR_DEBUG_IL_TO_NATIVE_MAP)
%COR_DEBUG_IL_TO_NATIVE_MAP = 1

' enum CorDebugIlToNativeMappingTypes
%CORDEBUG_NO_MAPPING = -1
%CORDEBUG_PROLOG     = -2
%CORDEBUG_EPILOG     = -3

' // Size = 12 bytes
TYPE COR_DEBUG_IL_TO_NATIVE_MAP DWORD
   ilOffset          AS DWORD   ' ULONG32
   nativeStartOffset AS DWORD   ' ULONG32
   nativeEndOffset   AS DWORD   ' ULONG32
END TYPE
#ENDIF   ' // _COR_DEBUG_IL_TO_NATIVE_MAP_

'#define REMOTE_DEBUGGING_DLL_ENTRY L"Software\\Microsoft\\.NETFramework\\Debugger\\ActivateRemoteDebugging"
$REMOTE_DEBUGGING_DLL_ENTRY = "Software\Microsoft\.NETFramework\Debugger\ActivateRemoteDebugging"

' enum CorDebugJITCompilerFlags
%CORDEBUG_JIT_DEFAULT              = &H1
%CORDEBUG_JIT_DISABLE_OPTIMIZATION = &H3
%CORDEBUG_JIT_ENABLE_ENC           = &H7

' enum CorDebugJITCompilerFlagsDecprecated
%CORDEBUG_JIT_TRACK_DEBUG_INFO = &H1

'typedef ULONG64 CORDB_ADDRESS;
'typedef ULONG64 CORDB_REGISTER;

' enum CorDebugBlockingReason
%BLOCKING_NONE                     = 0
%BLOCKING_MONITOR_CRITICAL_SECTION = &H1
%BLOCKING_MONITOR_EVENT            = &H2

TYPE CorDebugBlockingObject
   pBlockingObject AS DWORD PTR   ' ICorDebugValue *
   dwTimeout       AS DWORD       ' DWORD
   blockingReason  AS LONG        ' CorDebugBlockingReason enum
END TYPE

' ########################################################################################
' Interface name = ICorDebugDataTarget
' IID = {FE06DC28-49FB-4636-A4A3-E80DB4AE116C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugDataTarget_INTERFACE_DEFINED)
   %ICorDebugDataTarget_INTERFACE_DEFINED = 1

' enum CorDebugPlatform
%CORDB_PLATFORM_WINDOWS_X86   = 0
%CORDB_PLATFORM_WINDOWS_AMD64 = %CORDB_PLATFORM_WINDOWS_X86   + 1
%CORDB_PLATFORM_WINDOWS_IA64  = %CORDB_PLATFORM_WINDOWS_AMD64 + 1
%CORDB_PLATFORM_MAC_PPC       = %CORDB_PLATFORM_WINDOWS_IA64  + 1
%CORDB_PLATFORM_MAC_X86       = %CORDB_PLATFORM_MAC_PPC       + 1

INTERFACE ICorDebugDataTarget $IID_ICorDebugDataTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPlatform ( _                               ' VTable offset = 12
     BYREF pTargetPlatform AS LONG _                    ' __out CorDebugPlatform *pTargetPlatform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadVirtual ( _                               ' VTable offset = 16
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYVAL pBuffer AS BYTE PTR _                        ' __out BYTE *pBuffer
   , BYVAL bytesRequested AS DWORD _                    ' __in ULONG32 bytesRequested
   , BYREF pBytesRead AS DWORD _                        ' __out ULONG32 *pBytesRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadContext ( _                          ' VTable offset = 20
     BYVAL dwThreadID AS DWORD _                        ' __in DWORD dwThreadID
   , BYVAL contextFlags AS DWORD _                      ' __in ULONG32 contextFlags
   , BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYVAL pContext AS BYTE PTR _                       ' __out BYTE *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugDataTarget_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugMetaDataLocator
' IID = {7CEF8BA9-2EF7-42BF-973F-4171474F87D9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugDataTarget_INTERFACE_DEFINED)
   %ICorDebugDataTarget_INTERFACE_DEFINED = 1

INTERFACE ICorDebugMetaDataLocator $IID_ICorDebugMetaDataLocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMetaData ( _                               ' VTable offset = 12
     BYREF wszImagePath AS WSTRINGZ _                   ' __in LPCWSTR wszImagePath
   , BYVAL dwImageTimeStamp AS DWORD _                  ' __in DWORD dwImageTimeStamp
   , BYVAL dwImageSize AS DWORD _                       ' __in DWORD dwImageSize
   , BYVAL cchPathBuffer AS DWORD _                     ' __in ULONG32 cchPathBuffer
   , BYREF pcchPathBuffer AS DWORD _                    ' __out ULONG32 *pcchPathBuffer
   , BYREF wszPathBuffer AS WSTRINGZ _                  ' __out_ecount_part(cchPathBuffer, *pcchPathBuffer) WCHAR wszPathBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugDataTarget_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugManagedCallback
' IID = {3D6F5F60-7538-11D3-8D5B-00104B35E7EF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugManagedCallback_INTERFACE_DEFINED)
    %ICorDebugManagedCallback_INTERFACE_DEFINED = 1

' enum CorDebugStepReason
%CORDEBUG_STEP_NORMAL            = 0
%CORDEBUG_STEP_RETURN            = %CORDEBUG_STEP_NORMAL            + 1
%CORDEBUG_STEP_CALL              = %CORDEBUG_STEP_RETURN            + 1
%CORDEBUG_STEP_EXCEPTION_FILTER  = %CORDEBUG_STEP_CALL              + 1
%CORDEBUG_STEP_EXCEPTION_HANDLER = %CORDEBUG_STEP_EXCEPTION_FILTER  + 1
%CORDEBUG_STEP_INTERCEPT         = %CORDEBUG_STEP_EXCEPTION_HANDLER + 1
%CORDEBUG_STEP_EXIT              = %CORDEBUG_STEP_INTERCEPT         + 1

' enum LoggingLevelEnum
%CORDEBUG_LTraceLevel0  = 0
%CORDEBUG_LTraceLevel1  = %CORDEBUG_LTraceLevel0  + 1
%CORDEBUG_LTraceLevel2  = %CORDEBUG_LTraceLevel1  + 1
%CORDEBUG_LTraceLevel3  = %CORDEBUG_LTraceLevel2  + 1
%CORDEBUG_LTraceLevel4  = %CORDEBUG_LTraceLevel3  + 1
%CORDEBUG_LStatusLevel0 = 20
%CORDEBUG_LStatusLevel1 = %CORDEBUG_LStatusLevel0 + 1
%CORDEBUG_LStatusLevel2 = %CORDEBUG_LStatusLevel1 + 1
%CORDEBUG_LStatusLevel3 = %CORDEBUG_LStatusLevel2 + 1
%CORDEBUG_LStatusLevel4 = %CORDEBUG_LStatusLevel3 + 1
%CORDEBUG_LWarningLevel = 40
%CORDEBUG_LErrorLevel   = 50
%CORDEBUG_LPanicLevel   = 100

' enum LogSwitchCallReason
%CORDEBUG_SWITCH_CREATE   = 0
%CORDEBUG_SWITCH_MODIFY   = %CORDEBUG_SWITCH_CREATE + 1
%CORDEBUG_SWITCH_DELETE   = %CORDEBUG_SWITCH_MODIFY + 1


INTERFACE ICorDebugManagedCallback $IID_ICorDebugManagedCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Breakpoint ( _                                ' VTable offset = 12
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pBreakpoint AS ICorDebugBreakpoint _         ' __in ICorDebugBreakpoint *pBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StepComplete ( _                              ' VTable offset = 16
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pStepper AS ICorDebugStepper _               ' __in ICorDebugStepper *pStepper
   , BYVAL reason AS LONG _                             ' __in CorDebugStepReason reason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Break ( _                                     ' VTable offset = 20
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL thread AS ICorDebugThread _                  ' __in ICorDebugThread *thread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Exception ( _                                 ' VTable offset = 24
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL unhandled AS LONG _                          ' __in BOOL unhandled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EvalComplete ( _                              ' VTable offset = 28
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pEval AS ICorDebugEval _                     ' __in ICorDebugEval *pEval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EvalException ( _                             ' VTable offset = 32
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pEval AS ICorDebugEval _                     ' __in ICorDebugEval *pEval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateProcess ( _                             ' VTable offset = 36
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExitProcess ( _                               ' VTable offset = 40
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateThread ( _                              ' VTable offset = 44
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL thread AS ICorDebugThread _                  ' __in ICorDebugThread *thread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExitThread ( _                                ' VTable offset = 48
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL thread AS ICorDebugThread _                  ' __in ICorDebugThread *thread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadModule ( _                                ' VTable offset = 52
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pModule AS ICorDebugModule _                 ' __in ICorDebugModule *pModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadModule ( _                              ' VTable offset = 56
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pModule AS ICorDebugModule _                 ' __in ICorDebugModule *pModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadClass ( _                                 ' VTable offset = 60
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL c AS ICorDebugClass _                        ' __in ICorDebugClass *c
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadClass ( _                               ' VTable offset = 64
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL c AS ICorDebugClass _                        ' __in ICorDebugClass *c
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebuggerError ( _                             ' VTable offset = 68
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL errorHR AS LONG _                            ' __in HRESULT errorHR
   , BYVAL errorCode AS DWORD _                         ' __in DWORD errorCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogMessage ( _                                ' VTable offset = 72
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL lLevel AS LONG _                             ' __in LONG lLevel
   , BYREF pLogSwitchName AS WSTRINGZ _                 ' __in WCHAR *pLogSwitchName
   , BYREF pMessage AS WSTRINGZ _                       ' __in WCHAR *pMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LogSwitch ( _                                 ' VTable offset = 76
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL lLevel AS LONG _                             ' __in LONG lLevel
   , BYVAL ulReason AS DWORD _                          ' __in ULONG ulReason
   , BYREF pLogSwitchName AS WSTRINGZ _                 ' __in WCHAR *pLogSwitchName
   , BYREF pParentName AS WSTRINGZ _                    ' __in WCHAR *pParentName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAppDomain ( _                           ' VTable offset = 80
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExitAppDomain ( _                             ' VTable offset = 84
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadAssembly ( _                              ' VTable offset = 88
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pAssembly AS ICorDebugAssembly _             ' __in ICorDebugAssembly *pAssembly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadAssembly ( _                            ' VTable offset = 92
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pAssembly AS ICorDebugAssembly _             ' __in ICorDebugAssembly *pAssembly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ControlCTrap ( _                              ' VTable offset = 96
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NameChange ( _                                ' VTable offset = 100
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateModuleSymbols ( _                       ' VTable offset = 104
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pModule AS ICorDebugModule _                 ' __in ICorDebugModule *pModule
   , BYVAL pSymbolStream AS IStream _                   ' __in IStream *pSymbolStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EditAndContinueRemap ( _                      ' VTable offset = 108
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pFunction AS ICorDebugFunction _             ' __in ICorDebugFunction *pFunction
   , BYVAL fAccurate AS LONG _                          ' __in BOOL fAccurate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BreakpointSetError ( _                        ' VTable offset = 112
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pBreakpoint AS ICorDebugBreakpoint _         ' __in ICorDebugBreakpoint *pBreakpoint
   , BYVAL dwError AS DWORD _                           ' __in DWORD dwError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugManagedCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugManagedCallback3
' IID = {264EA0FC-2591-49AA-868E-835E6515323F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugManagedCallback3_INTERFACE_DEFINED)
    %ICorDebugManagedCallback3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugManagedCallback3 $IID_ICorDebugManagedCallback3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CustomNotification ( _                        ' VTable offset = 12
     BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugManagedCallback3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugManagedCallback2
' IID = {250E5EEA-DB5C-4C76-B6F3-8C46F12E3203}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugManagedCallback2_INTERFACE_DEFINED)
    %ICorDebugManagedCallback2_INTERFACE_DEFINED = 1

' enum CorDebugExceptionCallbackType
%CORDEBUG_DEBUG_EXCEPTION_FIRST_CHANCE        = 1
%CORDEBUG_DEBUG_EXCEPTION_USER_FIRST_CHANCE   = 2
%CORDEBUG_DEBUG_EXCEPTION_CATCH_HANDLER_FOUND = 3
%CORDEBUG_DEBUG_EXCEPTION_UNHANDLED           = 4

' enum CorDebugExceptionFlags
%CORDEBUG_DEBUG_EXCEPTION_CAN_BE_INTERCEPTED = &H1

' enum CorDebugExceptionUnwindCallbackType
%CORDEBUG_DEBUG_EXCEPTION_UNWIND_BEGIN = 1
%CORDEBUG_DEBUG_EXCEPTION_INTERCEPTED  = 2

INTERFACE ICorDebugManagedCallback2 $IID_ICorDebugManagedCallback2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FunctionRemapOpportunity ( _                  ' VTable offset = 12
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pOldFunction AS ICorDebugFunction _          ' __in ICorDebugFunction *pOldFunction
   , BYVAL pNewFunction AS ICorDebugFunction _          ' __in ICorDebugFunction *pNewFunction
   , BYVAL oldILOffset AS DWORD _                       ' __in ULONG32 oldILOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateConnection ( _                          ' VTable offset = 16
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL dwConnectionId AS DWORD _                    ' __in CONNID dwConnectionId
   , BYREF pConnName AS WSTRINGZ _                      ' __in WCHAR *pConnName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeConnection ( _                          ' VTable offset = 20
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL dwConnectionId AS DWORD _                    ' __in CONNID dwConnectionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyConnection ( _                         ' VTable offset = 24
     BYVAL pProcess AS ICorDebugProcess _               ' __in ICorDebugProcess *pProcess
   , BYVAL dwConnectionId AS DWORD _                    ' __in CONNID dwConnectionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Exception ( _                                 ' VTable offset = 28
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pFrame AS ICorDebugFrame _                   ' __in ICorDebugFrame *pFrame
   , BYVAL nOffset AS DWORD _                           ' __in ULONG32 nOffset
   , BYVAL dwEventType AS LONG _                        ' __in CorDebugExceptionCallbackType dwEventType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExceptionUnwind ( _                           ' VTable offset = 32
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL dwEventType AS LONG _                        ' __in CorDebugExceptionUnwindCallbackType dwEventType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FunctionRemapComplete ( _                     ' VTable offset = 36
     BYVAL pAppDomain AS ICorDebugAppDomain _           ' __in ICorDebugAppDomain *pAppDomain
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pFunction AS ICorDebugFunction _             ' __in ICorDebugFunction *pFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MDANotification ( _                           ' VTable offset = 40
     BYVAL pController AS ICorDebugController _         ' __in ICorDebugController *pController
   , BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYVAL pMDA AS ICorDebugMDA _                       ' __in ICorDebugMDA *pMDA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugManagedCallback2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugUnmanagedCallback
' IID = {5263E909-8CB5-11D3-BD2F-0000F80849BD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugUnmanagedCallback_INTERFACE_DEFINED)
    %ICorDebugUnmanagedCallback_INTERFACE_DEFINED = 1

INTERFACE ICorDebugUnmanagedCallback $IID_ICorDebugUnmanagedCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DebugEvent ( _                                ' VTable offset = 12
     BYVAL pDebugEvent AS DWORD _                       ' __in LPDEBUG_EVENT pDebugEvent
   , BYVAL fOutOfBand AS LONG _                         ' __in BOOL fOutOfBand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugUnmanagedCallback_INTERFACE_DEFINED__ */

' enum CorDebugCreateProcessFlags
%CORDEBUG_DEBUG_NO_SPECIAL_OPTIONS = 0

' enum CorDebugHandleType
%CORDEBUG_HANDLE_STRONG                  = 1
%CORDEBUG_HANDLE_WEAK_TRACK_RESURRECTION = 2

' ########################################################################################
' Interface name = ICorDebug
' IID = {3D6F5F61-7538-11D3-8D5B-00104B35E7EF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebug_INTERFACE_DEFINED)
    %ICorDebug_INTERFACE_DEFINED = 1

INTERFACE ICorDebug $IID_ICorDebug

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetManagedHandler ( _                         ' VTable offset = 20
     BYVAL pCallback AS ICorDebugManagedCallback _      ' __in ICorDebugManagedCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnmanagedHandler ( _                       ' VTable offset = 24
     BYVAL pCallback AS ICorDebugUnmanagedCallback _    ' __in ICorDebugUnmanagedCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateProcess ( _                             ' VTable offset = 28
     BYREF lpApplicationName AS WSTRINGZ _              ' __in LPCWSTR lpApplicationName
   , BYREF lpCommandLine AS WSTRINGZ _                  ' __in LPWSTR lpCommandLine
   , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES *lpProcessAttributes
   , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES *lpThreadAttributes
   , BYVAL bInheritHandles AS LONG _                    ' __in BOOL bInheritHandles
   , BYVAL dwCreationFlags AS DWORD _                   ' __in DWORD dwCreationFlags
   , BYVAL lpEnvironment AS DWORD _                     ' __in PVOID *lpEnvironment
   , BYREF lpCurrentDirectory AS WSTRINGZ _             ' __in LPCWSTR lpCurrentDirectory
   , BYVAL lpStartupInfo AS DWORD _                     ' __in LPSTARTUPINFOW lpStartupInfo
   , BYVAL lpProcessInformation AS DWORD _              ' __in LPPROCESS_INFORMATION lpProcessInformation
   , BYVAL debuggingFlags AS DWORD _                    ' __in CorDebugCreateProcessFlags debuggingFlags
   , BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebugActiveProcess ( _                        ' VTable offset = 32
     BYVAL id AS DWORD _                                ' __in DWORD id
   , BYVAL win32Attach AS LONG _                        ' __in BOOL win32Attach
   , BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateProcesses ( _                        ' VTable offset = 36
     BYREF ppProcess AS ICorDebugProcessEnum _          ' __out ICorDebugProcessEnum **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 40
     BYVAL dwProcessId AS DWORD _                       ' __in DWORD dwProcessId
   , BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanLaunchOrAttach ( _                         ' VTable offset = 44
     BYVAL dwProcessId AS DWORD _                       ' __in DWORD dwProcessId
   , BYVAL win32DebuggingEnabled AS LONG _              ' __in BOOL win32DebuggingEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebug_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugRemoteTarget
' IID = C3ED8383-5A49-4CF5-B4B7-01864D9E582D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugRemoteTarget_INTERFACE_DEFINED)
    %ICorDebugRemoteTarget_INTERFACE_DEFINED = 1

INTERFACE ICorDebugRemoteTarget $IID_ICorDebugRemoteTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHostName ( _                               ' VTable offset = 12
     BYVAL cchHostName AS DWORD _                       ' __in ULONG32 cchHostName
   , BYREF pcchHostName AS DWORD _                      ' __out ULONG32 *pcchHostName
   , BYREF szHostName AS WSTRINGZ _                     ' __out_ecount_part_opt(cchHostName, *pcchHostName) WCHAR szHostName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugRemoteTarget_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugRemote
' IID = D5EBB8E2-7BBE-4C1D-98A6-A3C04CBDEF64
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugRemote_INTERFACE_DEFINED)
    %ICorDebugRemote_INTERFACE_DEFINED = 1

INTERFACE ICorDebugRemote $IID_ICorDebugRemote

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateProcessEx ( _                           ' VTable offset = 12
     BYVAL pRemoteTarget AS ICorDebugRemoteTarget _     ' __in ICorDebugRemoteTarget *pRemoteTarget
   , BYREF lpApplicationName AS WSTRINGZ _              ' __in LPCWSTR lpApplicationName
   , BYREF lpCommandLine AS WSTRINGZ _                  ' __in LPWSTR lpCommandLine
   , BYREF lpProcessAttributes AS SECURITY_ATTRIBUTES _ ' __in LPSECURITY_ATTRIBUTES lpProcessAttributes
   , BYREF lpThreadAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpThreadAttributes
   , BYVAL bInheritHandles AS LONG _                    ' __in BOOL bInheritHandles
   , BYVAL dwCreationFlags AS DWORD _                   ' __in DWORD dwCreationFlags
   , BYVAL lpEnvironment AS DWORD _                     ' __in PVOID lpEnvironment
   , BYREF lpCurrentDirectory AS WSTRINGZ _             ' __in LPCWSTR lpCurrentDirectory
   , BYREF lpStartupInfo AS STARTUPINFOW _              ' __in LPSTARTUPINFOW lpStartupInfo
   , BYREF lpProcessInformation AS PROCESS_INFORMATION _ ' __in LPPROCESS_INFORMATION lpProcessInformation
   , BYVAL debuggingFlags AS DWORD _                    ' __in CorDebugCreateProcessFlags debuggingFlags
   , BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebugActiveProcessEx ( _                      ' VTable offset = 16
     BYVAL pRemoteTarget AS ICorDebugRemoteTarget _     ' __in ICorDebugRemoteTarget *pRemoteTarget
   , BYVAL dwProcessId AS DWORD _                       ' __in DWORD dwProcessId
   , BYVAL fWin32Attach AS LONG _                       ' __in BOOL fWin32Attach
   , BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugRemote_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE COR_VERSION DWORD
   dwMajor    AS DWORD   ' DWORD
   dwMinor    AS DWORD   ' DWORD
   dwBuild    AS DWORD   ' DWORD
   dwSubBuild AS DWORD   ' DWORD
END TYPE

' ########################################################################################
' Interface name = ICorDebug
' IID = ECCCCF2E-B286-4b3e-A983-860A8793D105
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebug2_INTERFACE_DEFINED)
    %ICorDebug2_INTERFACE_DEFINED = 1

' enum CorDebugInterfaceVersion
%CorDebugInvalidVersion                = 0
%CorDebugVersion_1_0                   = %CorDebugInvalidVersion + 1
%ver_ICorDebugManagedCallback          = %CorDebugVersion_1_0
%ver_ICorDebugUnmanagedCallback        = %CorDebugVersion_1_0
%ver_ICorDebug                         = %CorDebugVersion_1_0
%ver_ICorDebugController               = %CorDebugVersion_1_0
%ver_ICorDebugAppDomain                = %CorDebugVersion_1_0
%ver_ICorDebugAssembly                 = %CorDebugVersion_1_0
%ver_ICorDebugProcess                  = %CorDebugVersion_1_0
%ver_ICorDebugBreakpoint               = %CorDebugVersion_1_0
%ver_ICorDebugFunctionBreakpoint       = %CorDebugVersion_1_0
%ver_ICorDebugModuleBreakpoint         = %CorDebugVersion_1_0
%ver_ICorDebugValueBreakpoint          = %CorDebugVersion_1_0
%ver_ICorDebugStepper                  = %CorDebugVersion_1_0
%ver_ICorDebugRegisterSet              = %CorDebugVersion_1_0
%ver_ICorDebugThread                   = %CorDebugVersion_1_0
%ver_ICorDebugChain                    = %CorDebugVersion_1_0
%ver_ICorDebugFrame                    = %CorDebugVersion_1_0
%ver_ICorDebugILFrame                  = %CorDebugVersion_1_0
%ver_ICorDebugNativeFrame              = %CorDebugVersion_1_0
%ver_ICorDebugModule                   = %CorDebugVersion_1_0
%ver_ICorDebugFunction                 = %CorDebugVersion_1_0
%ver_ICorDebugCode                     = %CorDebugVersion_1_0
%ver_ICorDebugClass                    = %CorDebugVersion_1_0
%ver_ICorDebugEval                     = %CorDebugVersion_1_0
%ver_ICorDebugValue                    = %CorDebugVersion_1_0
%ver_ICorDebugGenericValue             = %CorDebugVersion_1_0
%ver_ICorDebugReferenceValue           = %CorDebugVersion_1_0
%ver_ICorDebugHeapValue                = %CorDebugVersion_1_0
%ver_ICorDebugObjectValue              = %CorDebugVersion_1_0
%ver_ICorDebugBoxValue                 = %CorDebugVersion_1_0
%ver_ICorDebugStringValue              = %CorDebugVersion_1_0
%ver_ICorDebugArrayValue               = %CorDebugVersion_1_0
%ver_ICorDebugContext                  = %CorDebugVersion_1_0
%ver_ICorDebugEnum                     = %CorDebugVersion_1_0
%ver_ICorDebugObjectEnum               = %CorDebugVersion_1_0
%ver_ICorDebugBreakpointEnum           = %CorDebugVersion_1_0
%ver_ICorDebugStepperEnum              = %CorDebugVersion_1_0
%ver_ICorDebugProcessEnum              = %CorDebugVersion_1_0
%ver_ICorDebugThreadEnum               = %CorDebugVersion_1_0
%ver_ICorDebugFrameEnum                = %CorDebugVersion_1_0
%ver_ICorDebugChainEnum                = %CorDebugVersion_1_0
%ver_ICorDebugModuleEnum               = %CorDebugVersion_1_0
%ver_ICorDebugValueEnum                = %CorDebugVersion_1_0
%ver_ICorDebugCodeEnum                 = %CorDebugVersion_1_0
%ver_ICorDebugTypeEnum                 = %CorDebugVersion_1_0
%ver_ICorDebugErrorInfoEnum            = %CorDebugVersion_1_0
%ver_ICorDebugAppDomainEnum            = %CorDebugVersion_1_0
%ver_ICorDebugAssemblyEnum             = %CorDebugVersion_1_0
%ver_ICorDebugEditAndContinueErrorInfo = %CorDebugVersion_1_0
%ver_ICorDebugEditAndContinueSnapshot  = %CorDebugVersion_1_0
%CorDebugVersion_1_1                   = %CorDebugVersion_1_0 + 1
%CorDebugVersion_2_0                   = %CorDebugVersion_1_1 + 1
%ver_ICorDebugManagedCallback2         = %CorDebugVersion_2_0
%ver_ICorDebugAppDomain2               = %CorDebugVersion_2_0
%ver_ICorDebugAssembly2                = %CorDebugVersion_2_0
%ver_ICorDebugProcess2                 = %CorDebugVersion_2_0
%ver_ICorDebugStepper2                 = %CorDebugVersion_2_0
%ver_ICorDebugRegisterSet2             = %CorDebugVersion_2_0
%ver_ICorDebugThread2                  = %CorDebugVersion_2_0
%ver_ICorDebugILFrame2                 = %CorDebugVersion_2_0
%ver_ICorDebugInternalFrame            = %CorDebugVersion_2_0
%ver_ICorDebugModule2                  = %CorDebugVersion_2_0
%ver_ICorDebugFunction2                = %CorDebugVersion_2_0
%ver_ICorDebugCode2                    = %CorDebugVersion_2_0
%ver_ICorDebugClass2                   = %CorDebugVersion_2_0
%ver_ICorDebugValue2                   = %CorDebugVersion_2_0
%ver_ICorDebugEval2                    = %CorDebugVersion_2_0
%ver_ICorDebugObjectValue2             = %CorDebugVersion_2_0
%CorDebugVersion_4_0                   = %CorDebugVersion_2_0 + 1
%ver_ICorDebugThread3                  = %CorDebugVersion_4_0
%ver_ICorDebugThread4                  = %CorDebugVersion_4_0
%ver_ICorDebugStackWalk                = %CorDebugVersion_4_0
%ver_ICorDebugNativeFrame2             = %CorDebugVersion_4_0
%ver_ICorDebugInternalFrame2           = %CorDebugVersion_4_0
%ver_ICorDebugRuntimeUnwindableFrame   = %CorDebugVersion_4_0
%ver_ICorDebugHeapValue3               = %CorDebugVersion_4_0
%ver_ICorDebugBlockingObjectEnum       = %CorDebugVersion_4_0
%CorDebugLatestVersion                 = %CorDebugVersion_4_0

INTERFACE ICorDebug2 $IID_ICorDebug2

   INHERIT IUnknown

   ' This interface has no methods

END INTERFACE

#ENDIF   ' /* __ICorDebug2_INTERFACE_DEFINED__ */


' enum CorDebugThreadState
%CORDEBUG_THREAD_RUN = 0
%CORDEBUG_THREAD_SUSPEND = %CORDEBUG_THREAD_RUN + 1


' ########################################################################################
' Interface name = ICorDebugController
' IID = {3D6F5F62-7538-11D3-8D5B-00104B35E7EF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugController_INTERFACE_DEFINED)
    %ICorDebugController_INTERFACE_DEFINED = 1

INTERFACE ICorDebugController $IID_ICorDebugController

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 12
     BYVAL dwTimeoutIgnored AS DWORD _                  ' __in DWORD dwTimeoutIgnored
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYVAL fIsOutOfBand AS LONG _                       ' __in BOOL fIsOutOfBand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 20
     BYREF pbRunning AS LONG _                          ' __out BOOL *pbRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasQueuedCallbacks ( _                        ' VTable offset = 24
     BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYREF pbQueued AS LONG _                           ' __out BOOL *pbQueued
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateThreads ( _                          ' VTable offset = 28
     BYREF ppThreads AS ICorDebugThreadEnum _           ' __out ICorDebugThreadEnum **ppThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllThreadsDebugState ( _                   ' VTable offset = 32
     BYVAL state AS LONG _                              ' __in CorDebugThreadState state
   , BYVAL pExceptThisThread AS ICorDebugThread _       ' __in ICorDebugThread *pExceptThisThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 40
     BYVAL exitCode AS DWORD _                          ' __in UINT exitCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanCommitChanges ( _                          ' VTable offset = 44
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 48
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugController_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugAppDomain
' IID = {3D6F5F63-7538-11D3-8D5B-00104B35E7EF}
' Inherited interface = ICorDebugController
' ########################################################################################

#IF NOT %DEF(%ICorDebugAppDomain_INTERFACE_DEFINED)
    %ICorDebugAppDomain_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAppDomain $IID_ICorDebugAppDomain

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugController Methods
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 12
     BYVAL dwTimeoutIgnored AS DWORD _                  ' __in DWORD dwTimeoutIgnored
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYVAL fIsOutOfBand AS LONG _                       ' __in BOOL fIsOutOfBand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 20
     BYREF pbRunning AS LONG _                          ' __out BOOL *pbRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasQueuedCallbacks ( _                        ' VTable offset = 24
     BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYREF pbQueued AS LONG _                           ' __out BOOL *pbQueued
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateThreads ( _                          ' VTable offset = 28
     BYREF ppThreads AS ICorDebugThreadEnum _           ' __out ICorDebugThreadEnum **ppThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllThreadsDebugState ( _                   ' VTable offset = 32
     BYVAL state AS LONG _                              ' __in CorDebugThreadState state
   , BYVAL pExceptThisThread AS ICorDebugThread _       ' __in ICorDebugThread *pExceptThisThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 40
     BYVAL exitCode AS DWORD _                          ' __in UINT exitCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanCommitChanges ( _                          ' VTable offset = 44
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 48
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugAppDomain Methods
   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 52
     BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateAssemblies ( _                       ' VTable offset = 56
     BYREF ppAssemblies AS ICorDebugAssemblyEnum _      ' __out ICorDebugAssemblyEnum **ppAssemblies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModuleFromMetaDataInterface ( _            ' VTable offset = 60
     BYVAL pIMetaData AS IUnknown _                     ' __in IUnknown *pIMetaData
   , BYREF ppModule AS ICorDebugModule _                ' __out ICorDebugModule **ppModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateBreakpoints ( _                      ' VTable offset = 64
     BYREF ppBreakpoints AS ICorDebugBreakpointEnum _   ' __out ICorDebugBreakpointEnum **ppBreakpoints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateSteppers ( _                         ' VTable offset = 68
     BYREF ppSteppers AS ICorDebugStepperEnum _         ' __out ICorDebugStepperEnum **ppSteppers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAttached ( _                                ' VTable offset = 72
     BYREF pbAttached AS LONG _                         ' __out BOOL *pbAttached
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 76
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 80
     BYREF ppObject AS ICorDebugValue _                 ' __out ICorDebugValue **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Attach ( _                                    ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 88
     BYREF pId AS DWORD _                               ' __out ULONG32 *pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAppDomain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugAppDomain2
' IID = {096E81D5-ECDA-4202-83F5-C65980A9EF75}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugAppDomain2_INTERFACE_DEFINED)
    %ICorDebugAppDomain2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAppDomain2 $IID_ICorDebugAppDomain2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetArrayOrPointerType ( _                     ' VTable offset = 12
     BYVAL elementType AS DWORD _                       ' __in CorElementType elementType
   , BYVAL nRank AS DWORD _                             ' __in ULONG32 nRank
   , BYVAL pTypeArg AS ICorDebugType _                  ' __in ICorDebugType *pTypeArg
   , BYREF ppType AS ICorDebugType _                    ' __out ICorDebugType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionPointerType ( _                    ' VTable offset = 16
     BYVAL nTypeArgs AS DWORD _                         ' __inULONG32  nTypeArgs
   , BYREF ppTypeArgs AS ICorDebugType _                ' __in ICorDebugType **ppTypeArgs
   , BYREF ppType AS ICorDebugType _                    ' __out ICorDebugType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAppDomain2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICorDebugAssembly
' IID = {DF59507C-D47A-459E-BCE2-6427EAC8FD06}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugAssembly_INTERFACE_DEFINED)
    %ICorDebugAssembly_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAssembly $IID_ICorDebugAssembly

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 12
     BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppDomain ( _                              ' VTable offset = 16
     BYREF ppAppDomain AS ICorDebugAppDomain _          ' __out ICorDebugAppDomain **ppAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateModules ( _                          ' VTable offset = 20
     BYREF ppModules AS ICorDebugModuleEnum _           ' __out ICorDebugModuleEnum **ppModules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodeBase ( _                               ' VTable offset = 24
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out  WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 28
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out  WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAssembly_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugAssembly2
' IID = {426D1F9E-6DD4-44C8-AEC7-26CDBAF4E398}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugAssembly2_INTERFACE_DEFINED)
    %ICorDebugAssembly2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAssembly2 $IID_ICorDebugAssembly2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsFullyTrusted ( _                            ' VTable offset = 12
     BYREF pbFullyTrusted AS LONG _                     ' __out BOOL *pbFullyTrusted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAssembly2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugProcess
' IID = {3D6F5F64-7538-11D3-8D5B-00104B35E7EF}
' Inherited interface = ICorDebugController
' ########################################################################################

#IF NOT %DEF(%ICorDebugProcess_INTERFACE_DEFINED)
    %ICorDebugProcess_INTERFACE_DEFINED = 1

INTERFACE ICorDebugProcess $IID_ICorDebugProcess

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugController Methods
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 12
     BYVAL dwTimeoutIgnored AS DWORD _                  ' __in DWORD dwTimeoutIgnored
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Continue ( _                                  ' VTable offset = 16
     BYVAL fIsOutOfBand AS LONG _                       ' __in BOOL fIsOutOfBand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 20
     BYREF pbRunning AS LONG _                          ' __out BOOL *pbRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasQueuedCallbacks ( _                        ' VTable offset = 24
     BYVAL pThread AS ICorDebugThread _                 ' __in ICorDebugThread *pThread
   , BYREF pbQueued AS LONG _                           ' __out BOOL *pbQueued
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateThreads ( _                          ' VTable offset = 28
     BYREF ppThreads AS ICorDebugThreadEnum _           ' __out ICorDebugThreadEnum **ppThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllThreadsDebugState ( _                   ' VTable offset = 32
     BYVAL state AS LONG _                              ' __in CorDebugThreadState state
   , BYVAL pExceptThisThread AS ICorDebugThread _       ' __in ICorDebugThread *pExceptThisThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 40
     BYVAL exitCode AS DWORD _                          ' __in UINT exitCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanCommitChanges ( _                          ' VTable offset = 44
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 48
     BYVAL cSnapshots AS DWORD _                        ' __in ULONG cSnapshots
   , BYREF pSnapshots AS ICorDebugEditAndContinueSnapshot _ ' __in ICorDebugEditAndContinueSnapshot **pSnapshots
   , BYREF pError AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum **pError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugProcess Methods
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 52
     BYREF pdwProcessId AS DWORD _                      ' __out DWORD *pdwProcessId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 56
     BYREF phProcessHandle AS DWORD _                   ' __out HPROCESS *phProcessHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThread ( _                                 ' VTable offset = 60
     BYVAL dwThreadId AS DWORD _                        ' __in DWORD dwThreadId
   , BYREF ppThread AS ICorDebugThread _                ' __out ICorDebugThread **ppThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateObjects ( _                          ' VTable offset = 64
     BYREF ppObjects AS ICorDebugObjectEnum _           ' __out ICorDebugObjectEnum **ppObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTransitionStub ( _                          ' VTable offset = 68
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYREF pbTransitionStub AS LONG _                   ' __out BOOL *pbTransitionStub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsOSSuspended ( _                             ' VTable offset = 72
     BYVAL threadID AS DWORD _                          ' __in DWORD threadID
   , BYREF pbSuspended AS LONG _                        ' __out BOOL *pbSuspended
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadContext ( _                          ' VTable offset = 76
     BYVAL threadID AS DWORD _                          ' __in DWORD threadID
   , BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYVAL context AS ICorDebugProcess _                ' __inout ICorDebugProcess context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThreadContext ( _                          ' VTable offset = 80
     BYVAL threadID AS DWORD _                          ' __in DWORD threadID
   , BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYVAL context AS ICorDebugProcess _                ' __in ICorDebugProcess context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadMemory ( _                                ' VTable offset = 84
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYVAL size AS DWORD _                              ' __in DWORD size
   , BYREF buffer AS BYTE _                             ' __out BYTE buffer[  ]
   , BYREF read AS DWORD _                              ' __out SIZE_T *read
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteMemory ( _                               ' VTable offset = 88
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYVAL size AS DWORD _                              ' __in DWORD size
   , BYREF buffer AS BYTE _                             ' __in BYTE buffer[  ]
   , BYREF written AS DWORD _                           ' __out SIZE_T *written
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearCurrentException ( _                     ' VTable offset = 92
     BYVAL threadID AS DWORD _                          ' __in DWORD threadID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableLogMessages ( _                         ' VTable offset = 96
     BYVAL fOnOff AS LONG _                             ' __in BOOL fOnOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyLogSwitch ( _                           ' VTable offset = 100
     BYREF pLogSwitchName AS WSTRINGZ _                 ' __in WCHAR *pLogSwitchName
   , BYVAL lLevel AS LONG _                             ' __in LONG lLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateAppDomains ( _                       ' VTable offset = 104
     BYREF ppAppDomains AS ICorDebugAppDomainEnum _     ' __out ICorDebugAppDomainEnum **ppAppDomains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 108
     BYREF ppObject AS ICorDebugValue _                 ' __out ICorDebugValue **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThreadForFiberCookie ( _                      ' VTable offset = 112
     BYVAL fiberCookie AS DWORD _                       ' __in DWORD fiberCookie
   , BYREF ppThread AS ICorDebugThread _                ' __out ICorDebugThread **ppThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelperThreadID ( _                         ' VTable offset = 116
     BYREF pThreadID AS DWORD _                         ' __out DWORD *pThreadID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugProcess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugProcess2
' IID = {AD1B3588-0EF0-4744-A496-AA09A9F80371}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugProcess2_INTERFACE_DEFINED)
    %ICorDebugProcess2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugProcess2 $IID_ICorDebugProcess2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThreadForTaskID ( _                        ' VTable offset = 12
     BYVAL taskid AS QUAD _                             ' __in TASKID taskid
   , BYREF ppThread AS ICorDebugThread2 _               ' __out ICorDebugThread2 **ppThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 16
     BYREF version AS COR_VERSION _                     ' __out COR_VERSION *version
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnmanagedBreakpoint ( _                    ' VTable offset = 20
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYVAL bufsize AS DWORD _                           ' __in ULONG32 bufsize
   , BYREF buffer AS BYTE _                             ' __out BYTE buffer[  ]
   , BYREF bufLen AS DWORD _                            ' __out ULONG32 *bufLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearUnmanagedBreakpoint ( _                  ' VTable offset = 24
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDesiredNGENCompilerFlags ( _               ' VTable offset = 28
     BYVAL pdwFlags AS DWORD _                          ' __in DWORD pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesiredNGENCompilerFlags ( _               ' VTable offset = 32
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferenceValueFromGCHandle ( _             ' VTable offset = 36
     BYVAL handle AS DWORD _                            ' __in UINT_PTR handle
   , BYREF pOutValue AS ICorDebugReferenceValue _       ' __out ICorDebugReferenceValue **pOutValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugProcess2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugProcess3
' IID = 2EE06488-C0D4-42B1-B26D-F3795EF606FB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugProcess3_INTERFACE_DEFINED)
    %ICorDebugProcess3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugProcess3 $IID_ICorDebugProcess3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetEnableCustomNotification ( _               ' VTable offset = 12
     BYVAL pClass AS ICorDebugClass _                   ' __in ICorDebugClass *pClass
   , BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugProcess3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugBreakpoint
' IID = {CC7BCAE8-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugBreakpoint_INTERFACE_DEFINED)
    %ICorDebugBreakpoint_INTERFACE_DEFINED = 1

INTERFACE ICorDebugBreakpoint $IID_ICorDebugBreakpoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYVAL bActive AS LONG _                            ' __in BOOL bActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 16
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugBreakpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugFunctionBreakpoint
' IID = {CC7BCAE9-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugBreakpoint
' ########################################################################################

#IF NOT %DEF(%ICorDebugFunctionBreakpoint_INTERFACE_DEFINED)
    %ICorDebugFunctionBreakpoint_INTERFACE_DEFINED = 1

INTERFACE ICorDebugFunctionBreakpoint $IID_ICorDebugFunctionBreakpoint

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugBreakpoint Methods
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYVAL bActive AS LONG _                            ' __in BOOL bActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 16
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugFunctionBreakpoint Methods
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOffset ( _                                 ' VTable offset = 24
     BYREF pnOffset AS DWORD _                          ' __out ULONG32 *pnOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugFunctionBreakpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugModuleBreakpoint
' IID = {CC7BCAEA-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugBreakpoint
' ########################################################################################

#IF NOT %DEF(%ICorDebugModuleBreakpoint_INTERFACE_DEFINED)
    %ICorDebugModuleBreakpoint_INTERFACE_DEFINED = 1

INTERFACE ICorDebugModuleBreakpoint $IID_ICorDebugModuleBreakpoint

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugBreakpoint Methods
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYVAL bActive AS LONG _                            ' __in BOOL bActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 16
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugModuleBreakpoint Methods
   ' =====================================================================================
   METHOD GetModule ( _                                 ' VTable offset = 20
     BYREF ppModule AS ICorDebugModule _                ' __out ICorDebugModule **ppModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugModuleBreakpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugValueBreakpoint
' IID = {CC7BCAEB-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugBreakpoint
' ########################################################################################

#IF NOT %DEF(%ICorDebugValueBreakpoint_INTERFACE_DEFINED)
    %ICorDebugValueBreakpoint_INTERFACE_DEFINED = 1

INTERFACE ICorDebugValueBreakpoint $IID_ICorDebugValueBreakpoint

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugBreakpoint Methods
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYVAL bActive AS LONG _                            ' __in BOOL bActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 16
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugValueBreakpoint Methods
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugValueBreakpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugStepper
' IID = {CC7BCAEC-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugStepper_INTERFACE_DEFINED)
    %ICorDebugStepper_INTERFACE_DEFINED = 1

' enum CorDebugIntercept
%CORDEBUG_INTERCEPT_NONE             = 0
%CORDEBUG_INTERCEPT_CLASS_INIT       = &H1
%CORDEBUG_INTERCEPT_EXCEPTION_FILTER = &H2
%CORDEBUG_INTERCEPT_SECURITY         = &H4
%CORDEBUG_INTERCEPT_CONTEXT_POLICY   = &H8
%CORDEBUG_INTERCEPT_INTERCEPTION     = &H10
%CORDEBUG_INTERCEPT_ALL              = &Hffff

' enum CorDebugUnmappedStop
%CORDEBUG_STOP_NONE            = 0
%CORDEBUG_STOP_PROLOG          = &H1
%CORDEBUG_STOP_EPILOG          = &H2
%CORDEBUG_STOP_NO_MAPPING_INFO = &H4
%CORDEBUG_STOP_OTHER_UNMAPPED  = &H8
%CORDEBUG_STOP_UNMANAGED       = &H10
%CORDEBUG_STOP_ALL             = &Hffff

' // Size = 8 bytes
TYPE COR_DEBUG_STEP_RANGE DWORD
   startOffset AS DWORD   ' ULONG32
   endOffset   AS DWORD   ' ULONG32
END TYPE

INTERFACE ICorDebugStepper $IID_ICorDebugStepper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 12
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterceptMask ( _                          ' VTable offset = 20
     BYVAL mask AS LONG _                               ' __in CorDebugIntercept mask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnmappedStopMask ( _                       ' VTable offset = 24
     BYVAL mask AS LONG _                               ' __in CorDebugUnmappedStop mask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Step ( _                                      ' VTable offset = 28
     BYVAL bStepIn AS LONG _                            ' __in BOOL bStepIn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StepRange ( _                                 ' VTable offset = 32
     BYVAL bStepIn AS LONG _                            ' __in BOOL bStepIn
   , BYREF ranges AS COR_DEBUG_STEP_RANGE _             ' __in COR_DEBUG_STEP_RANGE *ranges
   , BYVAL cRangeCount AS DWORD _                       ' __in ULONG32 cRangeCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StepOut ( _                                   ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRangeIL ( _                                ' VTable offset = 40
     BYVAL bIL AS LONG _                                ' __in BOOL bIL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugStepper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugStepper2
' IID = {C5B6E9C3-E7D1-4A8E-873B-7F047F0706F7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugStepper2_INTERFACE_DEFINED)
    %ICorDebugStepper2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugStepper2 $IID_ICorDebugStepper2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetJMC ( _                                    ' VTable offset = 12
     BYVAL fIsJMCStepper AS LONG _                      ' __in BOOL fIsJMCStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugStepper2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugRegisterSet
' IID = {CC7BCB0B-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugRegisterSet_INTERFACE_DEFINED)
    %ICorDebugRegisterSet_INTERFACE_DEFINED = 1

' enum CorDebugRegister
%CORDEBUG_REGISTER_INSTRUCTION_POINTER = 0
%CORDEBUG_REGISTER_STACK_POINTER       = %CORDEBUG_REGISTER_INSTRUCTION_POINTER + 1
%CORDEBUG_REGISTER_FRAME_POINTER       = %CORDEBUG_REGISTER_STACK_POINTER       + 1
%CORDEBUG_REGISTER_X86_EIP             = 0
%CORDEBUG_REGISTER_X86_ESP             = %CORDEBUG_REGISTER_X86_EIP             + 1
%CORDEBUG_REGISTER_X86_EBP             = %CORDEBUG_REGISTER_X86_ESP             + 1
%CORDEBUG_REGISTER_X86_EAX             = %CORDEBUG_REGISTER_X86_EBP             + 1
%CORDEBUG_REGISTER_X86_ECX             = %CORDEBUG_REGISTER_X86_EAX             + 1
%CORDEBUG_REGISTER_X86_EDX             = %CORDEBUG_REGISTER_X86_ECX             + 1
%CORDEBUG_REGISTER_X86_EBX             = %CORDEBUG_REGISTER_X86_EDX             + 1
%CORDEBUG_REGISTER_X86_ESI             = %CORDEBUG_REGISTER_X86_EBX             + 1
%CORDEBUG_REGISTER_X86_EDI             = %CORDEBUG_REGISTER_X86_ESI             + 1
%CORDEBUG_REGISTER_X86_FPSTACK_0       = %CORDEBUG_REGISTER_X86_EDI             + 1
%CORDEBUG_REGISTER_X86_FPSTACK_1       = %CORDEBUG_REGISTER_X86_FPSTACK_0       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_2       = %CORDEBUG_REGISTER_X86_FPSTACK_1       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_3       = %CORDEBUG_REGISTER_X86_FPSTACK_2       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_4       = %CORDEBUG_REGISTER_X86_FPSTACK_3       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_5       = %CORDEBUG_REGISTER_X86_FPSTACK_4       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_6       = %CORDEBUG_REGISTER_X86_FPSTACK_5       + 1
%CORDEBUG_REGISTER_X86_FPSTACK_7       = %CORDEBUG_REGISTER_X86_FPSTACK_6       + 1
%CORDEBUG_REGISTER_AMD64_RIP           = 0
%CORDEBUG_REGISTER_AMD64_RSP           = %CORDEBUG_REGISTER_AMD64_RIP           + 1
%CORDEBUG_REGISTER_AMD64_RBP           = %CORDEBUG_REGISTER_AMD64_RSP           + 1
%CORDEBUG_REGISTER_AMD64_RAX           = %CORDEBUG_REGISTER_AMD64_RBP           + 1
%CORDEBUG_REGISTER_AMD64_RCX           = %CORDEBUG_REGISTER_AMD64_RAX           + 1
%CORDEBUG_REGISTER_AMD64_RDX           = %CORDEBUG_REGISTER_AMD64_RCX           + 1
%CORDEBUG_REGISTER_AMD64_RBX           = %CORDEBUG_REGISTER_AMD64_RDX           + 1
%CORDEBUG_REGISTER_AMD64_RSI           = %CORDEBUG_REGISTER_AMD64_RBX           + 1
%CORDEBUG_REGISTER_AMD64_RDI           = %CORDEBUG_REGISTER_AMD64_RSI           + 1
%CORDEBUG_REGISTER_AMD64_R8            = %CORDEBUG_REGISTER_AMD64_RDI           + 1
%CORDEBUG_REGISTER_AMD64_R9            = %CORDEBUG_REGISTER_AMD64_R8            + 1
%CORDEBUG_REGISTER_AMD64_R10           = %CORDEBUG_REGISTER_AMD64_R9            + 1
%CORDEBUG_REGISTER_AMD64_R11           = %CORDEBUG_REGISTER_AMD64_R10           + 1
%CORDEBUG_REGISTER_AMD64_R12           = %CORDEBUG_REGISTER_AMD64_R11           + 1
%CORDEBUG_REGISTER_AMD64_R13           = %CORDEBUG_REGISTER_AMD64_R12           + 1
%CORDEBUG_REGISTER_AMD64_R14           = %CORDEBUG_REGISTER_AMD64_R13           + 1
%CORDEBUG_REGISTER_AMD64_R15           = %CORDEBUG_REGISTER_AMD64_R14           + 1
%CORDEBUG_REGISTER_AMD64_XMM0          = %CORDEBUG_REGISTER_AMD64_R15           + 1
%CORDEBUG_REGISTER_AMD64_XMM1          = %CORDEBUG_REGISTER_AMD64_XMM0          + 1
%CORDEBUG_REGISTER_AMD64_XMM2          = %CORDEBUG_REGISTER_AMD64_XMM1          + 1
%CORDEBUG_REGISTER_AMD64_XMM3          = %CORDEBUG_REGISTER_AMD64_XMM2          + 1
%CORDEBUG_REGISTER_AMD64_XMM4          = %CORDEBUG_REGISTER_AMD64_XMM3          + 1
%CORDEBUG_REGISTER_AMD64_XMM5          = %CORDEBUG_REGISTER_AMD64_XMM4          + 1
%CORDEBUG_REGISTER_AMD64_XMM6          = %CORDEBUG_REGISTER_AMD64_XMM5          + 1
%CORDEBUG_REGISTER_AMD64_XMM7          = %CORDEBUG_REGISTER_AMD64_XMM6          + 1
%CORDEBUG_REGISTER_AMD64_XMM8          = %CORDEBUG_REGISTER_AMD64_XMM7          + 1
%CORDEBUG_REGISTER_AMD64_XMM9          = %CORDEBUG_REGISTER_AMD64_XMM8          + 1
%CORDEBUG_REGISTER_AMD64_XMM10         = %CORDEBUG_REGISTER_AMD64_XMM9          + 1
%CORDEBUG_REGISTER_AMD64_XMM11         = %CORDEBUG_REGISTER_AMD64_XMM10         + 1
%CORDEBUG_REGISTER_AMD64_XMM12         = %CORDEBUG_REGISTER_AMD64_XMM11         + 1
%CORDEBUG_REGISTER_AMD64_XMM13         = %CORDEBUG_REGISTER_AMD64_XMM12         + 1
%CORDEBUG_REGISTER_AMD64_XMM14         = %CORDEBUG_REGISTER_AMD64_XMM13         + 1
%CORDEBUG_REGISTER_AMD64_XMM15         = %CORDEBUG_REGISTER_AMD64_XMM14         + 1
%CORDEBUG_REGISTER_IA64_BSP            = %CORDEBUG_REGISTER_FRAME_POINTER
%CORDEBUG_REGISTER_IA64_R0             = %CORDEBUG_REGISTER_IA64_BSP            + 1
%CORDEBUG_REGISTER_IA64_F0             = %CORDEBUG_REGISTER_IA64_R0             + 128

INTERFACE ICorDebugRegisterSet $IID_ICorDebugRegisterSet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRegistersAvailable ( _                     ' VTable offset = 12
     BYREF pAvailable AS QUAD _                         ' __out ULONG64 *pAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisters ( _                              ' VTable offset = 16
     BYVAL mask AS QUAD _                               ' __in ULONG64 mask
   , BYVAL regCount AS DWORD _                          ' __in ULONG32 regCount
   , BYREF regBuffer AS QUAD _                          ' __out CORDB_REGISTER regBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRegisters ( _                              ' VTable offset = 20
     BYVAL mask AS QUAD _                               ' __in ULONG64 mask
   , BYVAL regCount AS DWORD _                          ' __in ULONG32 regCount
   , BYREF regBuffer AS QUAD _                          ' __in CORDB_REGISTER regBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadContext ( _                          ' VTable offset = 24
     BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYREF context AS BYTE _                            ' __inout BYTE context[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThreadContext ( _                          ' VTable offset = 28
     BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYREF context AS BYTE _                            ' __in BYTE context[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugRegisterSet_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugRegisterSet2
' IID = 6DC7BA3F-89BA-4459-9EC1-9D60937B468D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugRegisterSet2_INTERFACE_DEFINED)
    %ICorDebugRegisterSet2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugRegisterSet2 $IID_ICorDebugRegisterSet2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRegistersAvailable ( _                     ' VTable offset = 12
     BYVAL numChunks AS DWORD _                         ' __in ULONG32 numChunks
   , BYREF availableRegChunks AS BYTE _                 ' __out BYTE availableRegChunks[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisters ( _                              ' VTable offset = 16
     BYVAL maskCount AS DWORD _                         ' __in ULONG32 maskCount
   , BYREF mask AS BYTE _                               ' __in BYTE mask[  ]
   , BYVAL regCount AS DWORD _                          ' __in ULONG32 regCount
   , BYREF regBuffer AS QUAD _                          ' __out CORDB_REGISTER regBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRegisters ( _                              ' VTable offset = 20
     BYVAL maskCount AS DWORD _                         ' __in ULONG32 maskCount
   , BYREF mask AS BYTE _                               ' __in BYTE mask[  ]
   , BYVAL regCount AS DWORD _                          ' __in ULONG32 regCount
   , BYREF regBuffer AS QUAD _                          ' __in CORDB_REGISTER regBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugRegisterSet2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugThread
' IID = {938C6D66-7FB6-4F69-B389-425B8987329B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugThread_INTERFACE_DEFINED)
    %ICorDebugThread_INTERFACE_DEFINED = 1

' enum CorDebugUserState
%CORDEBUG_USER_STOP_REQUESTED    = &H1
%CORDEBUG_USER_SUSPEND_REQUESTED = &H2
%CORDEBUG_USER_BACKGROUND        = &H4
%CORDEBUG_USER_UNSTARTED         = &H8
%CORDEBUG_USER_STOPPED           = &H10
%CORDEBUG_USER_WAIT_SLEEP_JOIN   = &H20
%CORDEBUG_USER_SUSPENDED         = &H40
%CORDEBUG_USER_UNSAFE_POINT      = &H80

INTERFACE ICorDebugThread $IID_ICorDebugThread

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 12
     BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 16
     BYREF pdwThreadId AS DWORD _                       ' __out DWORD *pdwThreadId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHandle ( _                                 ' VTable offset = 20
     BYREF phThreadHandle AS DWORD _                    ' __out HTHREAD *phThreadHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppDomain ( _                              ' VTable offset = 24
     BYREF ppAppDomain AS ICorDebugAppDomain _          ' __out ICorDebugAppDomain **ppAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDebugState ( _                             ' VTable offset = 28
     BYVAL state AS LONG _                              ' __in CorDebugThreadState state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDebugState ( _                             ' VTable offset = 32
     BYREF pState AS LONG _                             ' __out CorDebugThreadState *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserState ( _                              ' VTable offset = 36
     BYREF pState AS LONG _                             ' __out CorDebugUserState *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentException ( _                       ' VTable offset = 40
     BYREF ppExceptionObject AS ICorDebugValue _        ' __out ICorDebugValue **ppExceptionObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearCurrentException ( _                     ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 48
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateChains ( _                           ' VTable offset = 52
     BYREF ppChains AS ICorDebugChainEnum _             ' __out ICorDebugChainEnum **ppChains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveChain ( _                            ' VTable offset = 56
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveFrame ( _                            ' VTable offset = 60
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterSet ( _                            ' VTable offset = 64
     BYREF ppRegisters AS ICorDebugRegisterSet _        ' __out ICorDebugRegisterSet **ppRegisters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEval ( _                                ' VTable offset = 68
     BYREF ppEval AS ICorDebugEval _                    ' __out ICorDebugEval **ppEval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 72
     BYREF ppObject AS ICorDebugValue _                 ' __out ICorDebugValue **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugThread_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugThread2
' IID = {2BD956D9-7B07-4BEF-8A98-12AA862417C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugThread2_INTERFACE_DEFINED)
    %ICorDebugThread2_INTERFACE_DEFINED = 1

' // Size = 20 bytes
TYPE COR_ACTIVE_FUNCTION DWORD
   pAppDomain AS DWORD PTR   ' ICorDebugAppDomain *
   pModule    AS DWORD PTR   ' ICorDebugModule *
   pFunction  AS DWORD PTR   ' ICorDebugFunction2 *
   ilOffset   AS DWORD       ' ULONG32
   flags      AS DWORD       ' ULONG32
END TYPE

INTERFACE ICorDebugThread2 $IID_ICorDebugThread2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetActiveFunctions ( _                        ' VTable offset = 12
     BYVAL cFunctions AS DWORD _                        ' __in ULONG32 cFunctions
   , BYREF pcFunctions AS DWORD _                       ' __out ULONG32 *pcFunctions
   , BYVAL pFunctions AS ICorDebugThread2 _             ' __inout ICorDebugThread2 pFunctions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectionID ( _                           ' VTable offset = 16
     BYREF pdwConnectionId AS DWORD _                   ' __out CONNID *pdwConnectionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTaskID ( _                                 ' VTable offset = 20
     BYREF pTaskId AS QUAD _                            ' __out TASKID *pTaskId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolatileOSThreadID ( _                     ' VTable offset = 24
     BYREF pdwTid AS DWORD _                            ' __out DWORD *pdwTid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InterceptCurrentException ( _                 ' VTable offset = 28
     BYVAL pFrame AS ICorDebugFrame _                   ' __in ICorDebugFrame *pFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugThread2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugThread3
' IID = F8544EC3-5E4E-46C7-8D3E-A52B8405B1F5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugThread3_INTERFACE_DEFINED)
    %ICorDebugThread3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugThread3 $IID_ICorDebugThread3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateStackWalk ( _                           ' VTable offset = 12
     BYREF ppStackWalk AS ICorDebugStackWalk _          ' __out ICorDebugStackWalk **ppStackWalk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveInternalFrames ( _                   ' VTable offset = 16
     BYVAL cInternalFrames AS DWORD _                   ' __in ULONG32 cInternalFrames
   , BYREF pcInternalFrames AS DWORD _                  ' __out ULONG32 *pcInternalFrames
   , BYREF ppInternalFrames AS ICorDebugInternalFrame2 _ ' __inout ICorDebugInternalFrame2 *ppInternalFrames[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugThread3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugThread4
' IID = 1A1F204B-1C66-4637-823F-3EE6C744A69C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugThread4_INTERFACE_DEFINED)
    %ICorDebugThread3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugThread4 $IID_ICorDebugThread4

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HasUnhandledException ( _                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlockingObjects ( _                        ' VTable offset = 16
     BYREF ppBlockingObjectEnum AS ICorDebugBlockingObjectEnum _ ' __out ICorDebugBlockingObjectEnum **ppBlockingObjectEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentCustomDebuggerNotification ( _      ' VTable offset = 20
     BYREF ppNotificationObject AS ICorDebugValue _     ' __out ICorDebugValue **ppNotificationObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugThread4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugStackWalk
' IID = A0647DE9-55DE-4816-929C-385271C64CF7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugStackWalk_INTERFACE_DEFINED)
    %ICorDebugStackWalk_INTERFACE_DEFINED = 1

' enum CorDebugSetContextFlag
%SET_CONTEXT_FLAG_ACTIVE_FRAME = &H1???
%SET_CONTEXT_FLAG_UNWIND_FRAME = &H2???

INTERFACE ICorDebugStackWalk $IID_ICorDebugStackWalk

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 12
     BYVAL contextFlags AS DWORD _                      ' __in ULONG32 contextFlags
   , BYVAL contextBufSize AS DWORD _                    ' __in ULONG32 contextBufSize
   , BYREF contextSize AS DWORD _                       ' __out ULONG32 *contextSize
   , BYREF contextBuf AS BYTE _                         ' __out BYTE contextBuf[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContext ( _                                ' VTable offset = 16
     BYVAL flag AS DWORD _                              ' __in CorDebugSetContextFlag flag
   , BYVAL contextSize AS DWORD _                       ' __in ULONG32 contextSize
   , BYREF context AS BYTE _                            ' __in BYTE context[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrame ( _                                  ' VTable offset = 24
     BYREF pFrame AS ICorDebugFrame _                   ' __out ICorDebugFrame **pFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugStackWalk_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugChain
' IID = {CC7BCAEE-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugChain_INTERFACE_DEFINED)
    %ICorDebugChain_INTERFACE_DEFINED = 1

' enum CorDebugChainReason
%CORDEBUG_CHAIN_NONE             = 0
%CORDEBUG_CHAIN_CLASS_INIT       = &H1
%CORDEBUG_CHAIN_EXCEPTION_FILTER = &H2
%CORDEBUG_CHAIN_SECURITY         = &H4
%CORDEBUG_CHAIN_CONTEXT_POLICY   = &H8
%CORDEBUG_CHAIN_INTERCEPTION     = &H10
%CORDEBUG_CHAIN_PROCESS_START    = &H20
%CORDEBUG_CHAIN_THREAD_START     = &H40
%CORDEBUG_CHAIN_ENTER_MANAGED    = &H80
%CORDEBUG_CHAIN_ENTER_UNMANAGED  = &H100
%CORDEBUG_CHAIN_DEBUGGER_EVAL    = &H200
%CORDEBUG_CHAIN_CONTEXT_SWITCH   = &H400
%CORDEBUG_CHAIN_FUNC_EVAL        = &H800

INTERFACE ICorDebugChain $IID_ICorDebugChain

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThread ( _                                 ' VTable offset = 12
     BYREF ppThread AS ICorDebugThread _                ' __out ICorDebugThread **ppThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 16
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 20
     BYREF ppContext AS ICorDebugContext _              ' __out ICorDebugContext **ppContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 24
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 28
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrevious ( _                               ' VTable offset = 32
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNext ( _                                   ' VTable offset = 36
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsManaged ( _                                 ' VTable offset = 40
     BYREF pManaged AS LONG _                           ' __out BOOL *pManaged
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateFrames ( _                           ' VTable offset = 44
     BYREF ppFrames AS ICorDebugFrameEnum _             ' __out ICorDebugFrameEnum **ppFrames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveFrame ( _                            ' VTable offset = 48
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterSet ( _                            ' VTable offset = 52
     BYREF ppRegisters AS ICorDebugRegisterSet _        ' __out ICorDebugRegisterSet **ppRegisters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReason ( _                                 ' VTable offset = 56
     BYREF pReason AS LONG _                            ' __out CorDebugChainReason *pReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugChain_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugFrame
' IID = {CC7BCAEF-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugFrame_INTERFACE_DEFINED)
    %ICorDebugFrame_INTERFACE_DEFINED = 1

INTERFACE ICorDebugFrame $IID_ICorDebugFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChain ( _                                  ' VTable offset = 12
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 16
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionToken ( _                          ' VTable offset = 24
     BYREF pToken AS DWORD _                            ' __out mdMethodDef *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 32
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 36
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 40
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugInternalFrame
' IID = {B92CC7F7-9D2D-45C4-BC2B-621FCC9DFBF4}
' Inherited interface = ICorDebugFrame
' ########################################################################################

#IF NOT %DEF(%ICorDebugInternalFrame_INTERFACE_DEFINED)
    %ICorDebugInternalFrame_INTERFACE_DEFINED = 1

' enum CorDebugInternalFrameType
%CORDEBUG_STUBFRAME_NONE                 = 0
%CORDEBUG_STUBFRAME_M2U                  = &H1
%CORDEBUG_STUBFRAME_U2M                  = &H2
%CORDEBUG_STUBFRAME_APPDOMAIN_TRANSITION = &H3
%CORDEBUG_STUBFRAME_LIGHTWEIGHT_FUNCTION = &H4
%CORDEBUG_STUBFRAME_FUNC_EVAL            = &H5
%CORDEBUG_STUBFRAME_INTERNALCALL         = &H6
%CORDEBUG_STUBFRAME_CLASS_INIT           = &H7
%CORDEBUG_STUBFRAME_EXCEPTION            = &H8
%CORDEBUG_STUBFRAME_SECURITY             = &H9
%CORDEBUG_STUBFRAME_JIT_COMPILATION      = &Ha

INTERFACE ICorDebugInternalFrame $IID_ICorDebugInternalFrame

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugFrame Methods
   ' =====================================================================================
   METHOD GetChain ( _                                  ' VTable offset = 12
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 16
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionToken ( _                          ' VTable offset = 24
     BYREF pToken AS DWORD _                            ' __out mdMethodDef *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 32
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 36
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 40
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugInternalFrame Methods
   ' =====================================================================================
   METHOD GetFrameType ( _                              ' VTable offset = 44
     BYREF pType AS LONG _                              ' __out CorDebugInternalFrameType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugInternalFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugInternalFrame2
' IID = C0815BDC-CFAB-447E-A779-C116B454EB5B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugInternalFrame2_INTERFACE_DEFINED)
    %ICorDebugInternalFrame2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugInternalFrame2 $IID_ICorDebugInternalFrame2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 12
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCloserToLeaf ( _                            ' VTable offset = 16
     BYVAL pFrameToCompare AS ICorDebugFrame _          ' __in ICorDebugFrame *pFrameToCompare
   , BYREF pIsCloser AS LONG _                          ' __out BOOL *pIsCloser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugInternalFrame2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugILFrame
' IID = {03E26311-4F76-11D3-88C6-006097945418}
' Inherited interface = ICorDebugFrame
' ########################################################################################

#IF NOT %DEF(%ICorDebugILFrame_INTERFACE_DEFINED)
    %ICorDebugILFrame_INTERFACE_DEFINED = 1

' enum CorDebugMappingResult
%CORDEBUG_MAPPING_PROLOG           = &H1
%CORDEBUG_MAPPING_EPILOG           = &H2
%CORDEBUG_MAPPING_NO_INFO          = &H4
%CORDEBUG_MAPPING_UNMAPPED_ADDRESS = &H8
%CORDEBUG_MAPPING_EXACT            = &H10
%CORDEBUG_MAPPING_APPROXIMATE      = &H20

INTERFACE ICorDebugILFrame $IID_ICorDebugILFrame

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugFrame Methods
   ' =====================================================================================
   METHOD GetChain ( _                                  ' VTable offset = 12
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 16
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionToken ( _                          ' VTable offset = 24
     BYREF pToken AS DWORD _                            ' __out mdMethodDef *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 32
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 36
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 40
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugILFrame Methods
   ' =====================================================================================
   METHOD GetIP ( _                                     ' VTable offset = 44
     BYREF pnOffset AS DWORD _                          ' __out ULONG32 *pnOffset
   , BYREF pMappingResult AS LONG _                     ' __out CorDebugMappingResult *pMappingResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIP ( _                                     ' VTable offset = 48
     BYVAL nOffset AS DWORD _                           ' __in ULONG32 nOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateLocalVariables ( _                   ' VTable offset = 52
     BYREF ppValueEnum AS ICorDebugValueEnum _          ' __out ICorDebugValueEnum **ppValueEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalVariable ( _                          ' VTable offset = 56
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateArguments ( _                        ' VTable offset = 60
     BYREF ppValueEnum AS ICorDebugValueEnum _          ' __out ICorDebugValueEnum **ppValueEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetArgument ( _                               ' VTable offset = 64
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackDepth ( _                             ' VTable offset = 68
     BYREF pDepth AS DWORD _                            ' __out ULONG32 *pDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackValue ( _                             ' VTable offset = 72
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanSetIP ( _                                  ' VTable offset = 76
     BYVAL nOffset AS DWORD _                           ' __in ULONG32 nOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugILFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugILFrame2
' IID = {5D88A994-6C30-479B-890F-BCEF88B129A5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugILFrame2_INTERFACE_DEFINED)
    %ICorDebugILFrame2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugILFrame2 $IID_ICorDebugILFrame2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RemapFunction ( _                             ' VTable offset = 12
     BYVAL newILOffset AS DWORD _                       ' __in ULONG32 newILOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateTypeParameters ( _                   ' VTable offset = 16
     BYREF ppTyParEnum AS ICorDebugTypeEnum _           ' __out ICorDebugTypeEnum **ppTyParEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugILFrame2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugNativeFrame
' IID = {03E26314-4F76-11D3-88C6-006097945418}
' Inherited interface = ICorDebugFrame
' ########################################################################################

#IF NOT %DEF(%ICorDebugNativeFrame_INTERFACE_DEFINED)
    %ICorDebugNativeFrame_INTERFACE_DEFINED = 1

INTERFACE ICorDebugNativeFrame $IID_ICorDebugNativeFrame

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugFrame Methods
   ' =====================================================================================
   METHOD GetChain ( _                                  ' VTable offset = 12
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 16
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionToken ( _                          ' VTable offset = 24
     BYREF pToken AS DWORD _                            ' __out mdMethodDef *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 32
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 36
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 40
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugNativeFrame Methods
   ' =====================================================================================
   METHOD GetIP ( _                                     ' VTable offset = 44
     BYREF pnOffset AS DWORD _                          ' __out ULONG32 *pnOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIP ( _                                     ' VTable offset = 48
     BYVAL nOffset AS DWORD _                           ' __in ULONG32 nOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterSet ( _                            ' VTable offset = 52
     BYREF ppRegisters AS ICorDebugRegisterSet _        ' __out ICorDebugRegisterSet **ppRegisters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalRegisterValue ( _                     ' VTable offset = 56
     BYVAL reg AS LONG _                                ' __in CorDebugRegister reg
   , BYVAL cbSigBlob AS DWORD _                         ' __in ULONG cbSigBlob
   , BYVAL pvSigBlob AS DWORD _                         ' __in PCCOR_SIGNATURE pvSigBlob
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalDoubleRegisterValue ( _               ' VTable offset = 60
     BYVAL highWordReg AS LONG _                        ' __in CorDebugRegister highWordReg
   , BYVAL lowWordReg AS LONG _                         ' __in CorDebugRegister lowWordReg
   , BYVAL cbSigBlob AS DWORD _                         ' __in ULONG cbSigBlob
   , BYVAL pvSigBlob AS DWORD _                         ' __in PCCOR_SIGNATURE pvSigBlob
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalMemoryValue ( _                       ' VTable offset = 64
     BYVAL address AS QUAD _                            ' __in CORDB_ADDRESS address
   , BYVAL cbSigBlob AS DWORD _                         ' __in ULONG cbSigBlob
   , BYVAL pvSigBlob AS DWORD _                         ' __in PCCOR_SIGNATURE pvSigBlob
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalRegisterMemoryValue ( _               ' VTable offset = 68
     BYVAL highWordReg AS LONG _                        ' __in CorDebugRegister highWordReg
   , BYVAL lowWordAddress AS QUAD _                     ' __in CORDB_ADDRESS lowWordAddress
   , BYVAL cbSigBlob AS DWORD _                         ' __in ULONG cbSigBlob
   , BYVAL pvSigBlob AS DWORD _                         ' __in PCCOR_SIGNATURE pvSigBlob
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalMemoryRegisterValue ( _               ' VTable offset = 72
     BYVAL highWordAddress AS QUAD _                    ' __in CORDB_ADDRESS highWordAddress
   , BYVAL lowWordRegister AS LONG _                    ' __in CorDebugRegister lowWordRegister
   , BYVAL cbSigBlob AS DWORD _                         ' __in ULONG cbSigBlob
   , BYVAL pvSigBlob AS DWORD _                         ' __in PCCOR_SIGNATURE pvSigBlob
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanSetIP ( _                                  ' VTable offset = 76
     BYVAL nOffset AS DWORD _                           ' __in ULONG32 nOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugNativeFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugNativeFrame2
' IID = 35389FF1-3684-4C55-A2EE-210F26C60E5E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugNativeFrame2_INTERFACE_DEFINED)
    %ICorDebugNativeFrame2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugNativeFrame2 $IID_ICorDebugNativeFrame2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsChild ( _                                   ' VTable offset = 12
     BYREF pIsChild AS LONG _                           ' __out BOOL *pIsChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsMatchingParentFrame ( _                     ' VTable offset = 16
     BYVAL pPotentialParentFrame AS ICorDebugNativeFrame2 _ ' __in ICorDebugNativeFrame2 *pPotentialParentFrame
   , BYREF pIsParent AS LONG _                          ' __out BOOL *pIsParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackParameterSize ( _                     ' VTable offset = 20
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugNativeFrame2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugModule3
' IID = 86F012BF-FF15-4372-BD30-B6F11CAAE1DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugModule3_INTERFACE_DEFINED)
    %ICorDebugModule3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugModule3 $IID_ICorDebugModule3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateReaderForInMemorySymbols ( _            ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObj AS IUnknown _                          ' __out void **ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugModule3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugRuntimeUnwindableFrame
' IID = 879CAC0A-4A53-4668-B8E3-CB8473CB187F
' Inherited interface = ICorDebugFrame
' ########################################################################################

#IF NOT %DEF(%ICorDebugRuntimeUnwindableFrame_INTERFACE_DEFINED)
    %ICorDebugRuntimeUnwindableFrame_INTERFACE_DEFINED = 1

INTERFACE ICorDebugRuntimeUnwindableFrame $IID_ICorDebugRuntimeUnwindableFrame

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugFrame methods
   ' =====================================================================================
   METHOD GetChain ( _                                  ' VTable offset = 12
     BYREF ppChain AS ICorDebugChain _                  ' __out ICorDebugChain **ppChain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 16
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 20
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionToken ( _                          ' VTable offset = 24
     BYREF pToken AS DWORD _                            ' __out mdMethodDef *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackRange ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   , BYREF pEnd AS QUAD _                               ' __out CORDB_ADDRESS *pEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaller ( _                                 ' VTable offset = 32
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallee ( _                                 ' VTable offset = 36
     BYREF ppFrame AS ICorDebugFrame _                  ' __out ICorDebugFrame **ppFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStepper ( _                             ' VTable offset = 40
     BYREF ppStepper AS ICorDebugStepper _              ' __out ICorDebugStepper **ppStepper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugRuntimeUnwindableFrame methods
   ' =====================================================================================
   ' This interface has not additional methods
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugRuntimeUnwindableFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugModule
' IID = {DBA2D8C1-E5C5-4069-8C13-10A7C6ABF43D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugModule_INTERFACE_DEFINED)
    %ICorDebugModule_INTERFACE_DEFINED = 1

INTERFACE ICorDebugModule $IID_ICorDebugModule

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProcess ( _                                ' VTable offset = 12
     BYREF ppProcess AS ICorDebugProcess _              ' __out ICorDebugProcess **ppProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaseAddress ( _                            ' VTable offset = 16
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAssembly ( _                               ' VTable offset = 20
     BYREF ppAssembly AS ICorDebugAssembly _            ' __out ICorDebugAssembly **ppAssembly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 24
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableJITDebugging ( _                        ' VTable offset = 28
     BYVAL bTrackJITInfo AS LONG _                      ' __in BOOL bTrackJITInfo
   , BYVAL bAllowJitOpts AS LONG _                      ' __in BOOL bAllowJitOpts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableClassLoadCallbacks ( _                  ' VTable offset = 32
     BYVAL bClassLoadCallbacks AS LONG _                ' __in BOOL bClassLoadCallbacks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionFromToken ( _                      ' VTable offset = 36
     BYVAL methodDef AS DWORD _                         ' __in mdMethodDef methodDef
   , BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionFromRVA ( _                        ' VTable offset = 40
     BYVAL rva AS QUAD _                                ' __in CORDB_ADDRESS rva
   , BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClassFromToken ( _                         ' VTable offset = 44
     BYVAL typeDef AS DWORD _                           ' __in mdTypeDef typeDef
   , BYREF ppClass AS ICorDebugClass _                  ' __out ICorDebugClass **ppClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 48
     BYREF ppBreakpoint AS ICorDebugModuleBreakpoint _  ' __out ICorDebugModuleBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditAndContinueSnapshot ( _                ' VTable offset = 52
     BYREF ppEditAndContinueSnapshot AS ICorDebugEditAndContinueSnapshot _ ' __out ICorDebugEditAndContinueSnapshot **ppEditAndContinueSnapshot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetaDataInterface ( _                      ' VTable offset = 56
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppObj AS IUnknown _                          ' __out IUnknown **ppObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 60
     BYREF pToken AS DWORD _                            ' __out mdModule *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDynamic ( _                                 ' VTable offset = 64
     BYREF pDynamic AS LONG _                           ' __out BOOL *pDynamic
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlobalVariableValue ( _                    ' VTable offset = 68
     BYVAL fieldDef AS DWORD _                          ' __in mdFieldDef fieldDef
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 72
     BYREF pcBytes AS DWORD _                           ' __out ULONG32 *pcBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInMemory ( _                                ' VTable offset = 76
     BYREF pInMemory AS LONG _                          ' __out BOOL *pInMemory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugModule_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugModule2
' IID = {7FCC5FB5-49C0-41DE-9938-3B88B5B9ADD7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugModule2_INTERFACE_DEFINED)
    %ICorDebugModule2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugModule2 $IID_ICorDebugModule2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetJMCStatus ( _                              ' VTable offset = 12
     BYVAL bIsJustMyCode AS LONG _                      ' __in BOOL bIsJustMyCode
   , BYVAL cTokens AS DWORD _                           ' __in ULONG32 cTokens
   , BYREF pTokens AS DWORD _                           ' __in mdToken pTokens[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyChanges ( _                              ' VTable offset = 16
     BYVAL cbMetadata AS DWORD _                        ' __in ULONG cbMetadata
   , BYREF pbMetadata AS BYTE _                         ' __in BYTE pbMetadata[  ]
   , BYVAL cbIL AS DWORD _                              ' __in ULONG cbIL
   , BYREF pbIL AS BYTE _                               ' __in BYTE pbIL[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetJITCompilerFlags ( _                       ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJITCompilerFlags ( _                       ' VTable offset = 24
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveAssembly ( _                           ' VTable offset = 28
     BYVAL tkAssemblyRef AS DWORD _                     ' __in mdToken tkAssemblyRef
   , BYREF ppAssembly AS ICorDebugAssembly _            ' __out ICorDebugAssembly **ppAssembly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugModule2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugFunction
' IID = {CC7BCAF3-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugFunction_INTERFACE_DEFINED)
    %ICorDebugFunction_INTERFACE_DEFINED = 1

INTERFACE ICorDebugFunction $IID_ICorDebugFunction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetModule ( _                                 ' VTable offset = 12
     BYREF ppModule AS ICorDebugModule _                ' __out ICorDebugModule **ppModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClass ( _                                  ' VTable offset = 16
     BYREF ppClass AS ICorDebugClass _                  ' __out ICorDebugClass **ppClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 20
     BYREF pMethodDef AS DWORD _                        ' __out mdMethodDef *pMethodDef
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetILCode ( _                                 ' VTable offset = 24
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeCode ( _                             ' VTable offset = 28
     BYREF ppCode AS ICorDebugCode _                    ' __out ICorDebugCode **ppCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 32
     BYREF ppBreakpoint AS ICorDebugFunctionBreakpoint _ ' __out ICorDebugFunctionBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocalVarSigToken ( _                       ' VTable offset = 36
     BYREF pmdSig AS DWORD _                            ' __out mdSignature *pmdSig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentVersionNumber ( _                   ' VTable offset = 40
     BYREF pnCurrentVersion AS DWORD _                  ' __out ULONG32 *pnCurrentVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugFunction_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugFunction2
' IID = {EF0C490B-94C3-4E4D-B629-DDC134C532D8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugFunction2_INTERFACE_DEFINED)
    %ICorDebugFunction2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugFunction2 $IID_ICorDebugFunction2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetJMCStatus ( _                              ' VTable offset = 12
     BYVAL bIsJustMyCode AS LONG _                      ' __in BOOL bIsJustMyCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJMCStatus ( _                              ' VTable offset = 16
     BYREF pbIsJustMyCode AS LONG _                     ' __out BOOL *pbIsJustMyCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateNativeCode ( _                       ' VTable offset = 20
     BYREF ppCodeEnum AS ICorDebugCodeEnum _            ' __out ICorDebugCodeEnum **ppCodeEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 24
     BYREF pnVersion AS DWORD _                         ' __out ULONG32 *pnVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugFunction2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugCode
' IID = {CC7BCAF4-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugCode_INTERFACE_DEFINED)
    %ICorDebugCode_INTERFACE_DEFINED = 1

INTERFACE ICorDebugCode $IID_ICorDebugCode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsIL ( _                                      ' VTable offset = 12
     BYREF pbIL AS LONG _                               ' __out BOOL *pbIL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 16
     BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pStart AS QUAD _                             ' __out CORDB_ADDRESS *pStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 24
     BYREF pcBytes AS DWORD _                           ' __out ULONG32 *pcBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 28
     BYVAL offset AS DWORD _                            ' __in ULONG32 offset
   , BYREF ppBreakpoint AS ICorDebugFunctionBreakpoint _ ' __out ICorDebugFunctionBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCode ( _                                   ' VTable offset = 32
     BYVAL startOffset AS DWORD _                       ' __in ULONG32 startOffset
   , BYVAL endOffset AS DWORD _                         ' __in ULONG32 endOffset
   , BYVAL cBufferAlloc AS DWORD _                      ' __in ULONG32 cBufferAlloc
   , BYVAL buffer AS ICorDebugCode _                    ' __out ICorDebugCode buffer
   , BYREF pcBufferSize AS DWORD _                      ' __out ULONG32 *pcBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionNumber ( _                          ' VTable offset = 36
     BYREF nVersion AS DWORD _                          ' __out ULONG32 *nVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetILToNativeMapping ( _                      ' VTable offset = 40
     BYVAL cMap AS DWORD _                              ' __in ULONG32 cMap
   , BYREF pcMap AS DWORD _                             ' __out ULONG32 *pcMap
   , BYVAL map AS ICorDebugCode _                       ' __out ICorDebugCode map
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnCRemapSequencePoints ( _                 ' VTable offset = 44
     BYVAL cMap AS DWORD _                              ' __in ULONG32 cMap
   , BYREF pcMap AS DWORD _                             ' __out ULONG32 *pcMap
   , BYVAL offsets AS ICorDebugCode _                   ' __out ICorDebugCode offsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugCode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugCode2
' IID = {CC7BCAF4-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugCode2_INTERFACE_DEFINED)
    %ICorDebugCode2_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE CodeChunkInfo QWORD
   startAddr AS QUAD    ' CORDB_ADDRESS
   length    AS DWORD   ' ULONG32
END TYPE

INTERFACE ICorDebugCode2 $IID_ICorDebugCode2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCodeChunks ( _                             ' VTable offset = 12
     BYVAL cbufSize AS DWORD _                          ' __in ULONG32 cbufSize
   , BYREF pcnumChunks AS DWORD _                       ' __out ULONG32 *pcnumChunks
   , BYREF chunks AS CodeChunkInfo _                    ' __out CodeChunkInfo chunks[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompilerFlags ( _                          ' VTable offset = 16
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugCode2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugClass
' IID = {CC7BCAF5-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugClass_INTERFACE_DEFINED)
    %ICorDebugClass_INTERFACE_DEFINED = 1

INTERFACE ICorDebugClass $IID_ICorDebugClass

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetModule ( _                                 ' VTable offset = 12
     BYREF pModule AS ICorDebugModule _                 ' __out ICorDebugModule **pModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 16
     BYREF pTypeDef AS DWORD _                          ' __out mdTypeDef *pTypeDef
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStaticFieldValue ( _                       ' VTable offset = 20
     BYVAL fieldDef AS DWORD _                          ' __in mdFieldDef fieldDef
   , BYVAL pFrame AS ICorDebugFrame _                   ' __in ICorDebugFrame *pFrame
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugClass_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugClass2
' IID = {B008EA8D-7AB1-43F7-BB20-FBB5A04038AE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugClass2_INTERFACE_DEFINED)
    %ICorDebugClass2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugClass2 $IID_ICorDebugClass2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParameterizedType ( _                      ' VTable offset = 12
     BYVAL elementType AS DWORD _                       ' __in CorElementType elementType
   , BYVAL nTypeArgs AS DWORD _                         ' __in ULONG32 nTypeArgs
   , BYREF ppTypeArgs AS ICorDebugType _                ' __in ICorDebugType **ppTypeArgs
   , BYREF ppType AS ICorDebugType _                    ' __out ICorDebugType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetJMCStatus ( _                              ' VTable offset = 16
     BYVAL bIsJustMyCode AS LONG _                      ' __in BOOL bIsJustMyCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugClass2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugEval
' IID = {CC7BCAF6-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugEval_INTERFACE_DEFINED)
    %ICorDebugEval_INTERFACE_DEFINED = 1

INTERFACE ICorDebugEval $IID_ICorDebugEval

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallFunction ( _                              ' VTable offset = 12
     BYVAL pFunction AS ICorDebugFunction _             ' __in ICorDebugFunction *pFunction
   , BYVAL nArgs AS DWORD _                             ' __in ULONG32 nArgs
   , BYREF ppArgs AS ICorDebugValue _                   ' __in ICorDebugValue **ppArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewObject ( _                                 ' VTable offset = 16
     BYVAL pConstructor AS ICorDebugFunction _          ' __in ICorDebugFunction *pConstructor
   , BYVAL nArgs AS DWORD _                             ' __in ULONG32 nArgs
   , BYREF ppArgs AS ICorDebugValue _                   ' __in ICorDebugValue **ppArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewObjectNoConstructor ( _                    ' VTable offset = 20
     BYVAL pClass AS ICorDebugClass _                   ' __in ICorDebugClass *pClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewString ( _                                 ' VTable offset = 24
     BYREF string AS WSTRINGZ _                         ' __in LPCWSTR string
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewArray ( _                                  ' VTable offset = 28
     BYVAL elementType AS DWORD _                       ' __in CorElementType elementType
   , BYVAL pElementClass AS ICorDebugClass _            ' __in ICorDebugClass *pElementClass
   , BYVAL rank AS DWORD _                              ' __in ULONG32 rank
   , BYREF dims AS DWORD _                              ' __in ULONG32 *dims
   , BYREF lowBounds AS DWORD _                         ' __in ULONG32 *lowBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 32
     BYREF pbActive AS LONG _                           ' __out BOOL *pbActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 40
     BYREF ppResult AS ICorDebugValue _                 ' __out ICorDebugValue **ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThread ( _                                 ' VTable offset = 44
     BYREF ppThread AS ICorDebugThread _                ' __out ICorDebugThread **ppThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateValue ( _                               ' VTable offset = 48
     BYVAL elementType AS DWORD _                       ' __in CorElementType elementType
   , BYVAL pElementClass AS ICorDebugClass _            ' __in ICorDebugClass *pElementClass
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugEval_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugEval2
' IID = {FB0D9CE7-BE66-4683-9D32-A42A04E2FD91}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugEval2_INTERFACE_DEFINED)
    %ICorDebugEval2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugEval2 $IID_ICorDebugEval2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallParameterizedFunction ( _                 ' VTable offset = 12
     BYVAL pFunction AS ICorDebugFunction _             ' __in ICorDebugFunction *pFunction
   , BYVAL nTypeArgs AS DWORD _                         ' __in ULONG32 nTypeArgs
   , BYREF ppTypeArgs AS ICorDebugType _                ' __in ICorDebugType **ppTypeArgs
   , BYVAL nArgs AS DWORD _                             ' __in ULONG32 nArgs
   , BYREF ppArgs AS ICorDebugValue _                   ' __in ICorDebugValue **ppArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateValueForType ( _                        ' VTable offset = 16
     BYVAL pType AS ICorDebugType _                     ' __in ICorDebugType *pType
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewParameterizedObject ( _                    ' VTable offset = 20
     BYVAL pConstructor AS ICorDebugFunction _          ' __in ICorDebugFunction *pConstructor
   , BYVAL nTypeArgs AS DWORD _                         ' __in ULONG32 nTypeArgs
   , BYREF ppTypeArgs AS ICorDebugType _                ' __in ICorDebugType **ppTypeArgs
   , BYVAL nArgs AS DWORD _                             ' __in ULONG32 nArgs
   , BYREF ppArgs AS ICorDebugValue _                   ' __in ICorDebugValue **ppArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewParameterizedObjectNoConstructor ( _       ' VTable offset = 24
     BYVAL pClass AS ICorDebugClass _                   ' __in ICorDebugClass *pClass
   , BYVAL nTypeArgs AS DWORD _                         ' __in ULONG32 nTypeArgs
   , BYREF ppTypeArgs AS ICorDebugType _                ' __in ICorDebugType **ppTypeArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewParameterizedArray ( _                     ' VTable offset = 28
     BYVAL pElementType AS ICorDebugType _              ' __in ICorDebugType *pElementType
   , BYVAL rank AS DWORD _                              ' __in ULONG32 rank
   , BYREF dims AS DWORD _                              ' __in ULONG32 *dims
   , BYREF lowBounds AS DWORD _                         ' __in ULONG32 *lowBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewStringWithLength ( _                       ' VTable offset = 32
     BYREF string AS WSTRINGZ _                         ' __in LPCWSTR string
   , BYVAL uiLength AS DWORD _                          ' __in UINT uiLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RudeAbort ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugEval2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugValue
' IID = {CC7BCAF7-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugValue_INTERFACE_DEFINED)
    %ICorDebugValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugValue $IID_ICorDebugValue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugValue2
' IID = {5E0B54E7-D88A-4626-9420-A691E0A78B49}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugValue2_INTERFACE_DEFINED)
    %ICorDebugValue2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugValue2 $IID_ICorDebugValue2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetExactType ( _                              ' VTable offset = 12
     BYREF ppType AS ICorDebugType _                    ' __out ICorDebugType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugValue2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugGenericValue
' IID = {CC7BCAF8-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugGenericValue_INTERFACE_DEFINED)
    %ICorDebugGenericValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugGenericValue $IID_ICorDebugGenericValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugGenericValue Methods
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 28
     BYVAL pTo AS DWORD _                               ' __out void *pTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 32
     BYVAL pFrom AS DWORD _                             ' __in void *pFrom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugGenericValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugReferenceValue
' IID = {CC7BCAF9-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugReferenceValue_INTERFACE_DEFINED)
    %ICorDebugReferenceValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugReferenceValue $IID_ICorDebugReferenceValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugReferenceValue Methods
   ' =====================================================================================
   METHOD IsNull ( _                                    ' VTable offset = 28
     BYREF pbNull AS LONG _                             ' __out BOOL *pbNull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 32
     BYREF pValue AS QUAD _                             ' __out CORDB_ADDRESS *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYVAL value AS QUAD _                              ' __in CORDB_ADDRESS value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Dereference ( _                               ' VTable offset = 40
     BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DereferenceStrong ( _                         ' VTable offset = 44
     BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugReferenceValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugHeapValue
' IID = {CC7BCAFA-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugHeapValue_INTERFACE_DEFINED)
    %ICorDebugHeapValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugHeapValue $IID_ICorDebugHeapValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugHeapValue Methods
   ' =====================================================================================
   METHOD IsValid ( _                                   ' VTable offset = 28
     BYREF pbValid AS LONG _                            ' __out BOOL *pbValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRelocBreakpoint ( _                     ' VTable offset = 32
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugHeapValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugHeapValue2
' IID = {E3AC4D6C-9CB7-43E6-96CC-B21540E5083C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugHeapValue2_INTERFACE_DEFINED)
    %ICorDebugHeapValue2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugHeapValue2 $IID_ICorDebugHeapValue2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateHandle ( _                              ' VTable offset = 12
     BYVAL type AS LONG _                               ' __in CorDebugHandleType type
   , BYREF ppHandle AS ICorDebugHandleValue _           ' __out ICorDebugHandleValue **ppHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugHeapValue2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugHeapValue3
' IID = A69ACAD8-2374-46E9-9FF8-B1F14120D296
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugHeapValue3_INTERFACE_DEFINED)
    %ICorDebugHeapValue3_INTERFACE_DEFINED = 1

INTERFACE ICorDebugHeapValue3 $IID_ICorDebugHeapValue3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThreadOwningMonitorLock ( _                ' VTable offset = 12
     BYREF ppThread AS ICorDebugThread _                ' __out ICorDebugThread **ppThread
   , BYREF pAcquisitionCount AS DWORD _                 ' __out DWORD *pAcquisitionCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitorEventWaitList ( _                   ' VTable offset = 16
     BYREF ppThreadEnum AS ICorDebugThreadEnum _        ' __out ICorDebugThreadEnum **ppThreadEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugHeapValue3_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugObjectValue
' IID = {18AD3D6E-B7D2-11D2-BD04-0000F80849BD}
' Inherited interface = ICorDebugValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugObjectValue_INTERFACE_DEFINED)
    %ICorDebugObjectValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugObjectValue $IID_ICorDebugObjectValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugObjectValue Methods
   ' =====================================================================================
   METHOD GetClass ( _                                  ' VTable offset = 28
     BYREF ppClass AS ICorDebugClass _                  ' __out ICorDebugClass **ppClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldValue ( _                             ' VTable offset = 32
     BYVAL pClass AS ICorDebugClass _                   ' __in ICorDebugClass *pClass
   , BYVAL fieldDef AS DWORD _                          ' __in mdFieldDef fieldDef
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVirtualMethod ( _                          ' VTable offset = 36
     BYVAL memberRef AS DWORD _                         ' __in mdMemberRef memberRef
   , BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 40
     BYREF ppContext AS ICorDebugContext _              ' __out ICorDebugContext **ppContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueClass ( _                              ' VTable offset = 44
     BYREF pbIsValueClass AS LONG _                     ' __out BOOL *pbIsValueClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetManagedCopy ( _                            ' VTable offset = 48
     BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFromManagedCopy ( _                        ' VTable offset = 52
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugObjectValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugObjectValue2
' IID = {49E4A320-4A9B-4ECA-B105-229FB7D5009F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugObjectValue2_INTERFACE_DEFINED)
    %ICorDebugObjectValue2_INTERFACE_DEFINED = 1

INTERFACE ICorDebugObjectValue2 $IID_ICorDebugObjectValue2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVirtualMethodAndType ( _                   ' VTable offset = 12
     BYVAL memberRef AS DWORD _                         ' __in mdMemberRef memberRef
   , BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   , BYREF ppType AS ICorDebugType _                    ' __out ICorDebugType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugObjectValue2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugBoxValue
' IID = {CC7BCAFC-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugHeapValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugBoxValue_INTERFACE_DEFINED)
    %ICorDebugBoxValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugBoxValue $IID_ICorDebugBoxValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugHeapValue Methods
   ' =====================================================================================
   METHOD IsValid ( _                                   ' VTable offset = 28
     BYREF pbValid AS LONG _                            ' __out BOOL *pbValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRelocBreakpoint ( _                     ' VTable offset = 32
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugBoxValue Methods
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 36
     BYREF ppObject AS ICorDebugObjectValue _           ' __out ICorDebugObjectValue **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugBoxValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugStringValue
' IID = {CC7BCAFD-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugHeapValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugStringValue_INTERFACE_DEFINED)
    %ICorDebugStringValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugStringValue $IID_ICorDebugStringValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugHeapValue Methods
   ' =====================================================================================
   METHOD IsValid ( _                                   ' VTable offset = 28
     BYREF pbValid AS LONG _                            ' __out BOOL *pbValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRelocBreakpoint ( _                     ' VTable offset = 32
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugStringValue Methods
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 36
     BYREF pcchString AS DWORD _                        ' __out ULONG32 *pcchString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 40
     BYVAL cchString AS DWORD _                         ' __in ULONG32 cchString
   , BYREF pcchString AS DWORD _                        ' __out ULONG32 *pcchString
   , BYREF szString AS WSTRINGZ _                       ' __out WCHAR szString[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugStringValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugArrayValue
' IID = {0405B0DF-A660-11D2-BD02-0000F80849BD}
' Inherited interface = ICorDebugHeapValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugArrayValue_INTERFACE_DEFINED)
    %ICorDebugArrayValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugArrayValue $IID_ICorDebugArrayValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugHeapValue Methods
   ' =====================================================================================
   METHOD IsValid ( _                                   ' VTable offset = 28
     BYREF pbValid AS LONG _                            ' __out BOOL *pbValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRelocBreakpoint ( _                     ' VTable offset = 32
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugArrayValue Methods
   ' =====================================================================================
   METHOD GetElementType ( _                            ' VTable offset = 36
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRank ( _                                   ' VTable offset = 40
     BYREF pnRank AS DWORD _                            ' __out ULONG32 *pnRank
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 44
     BYREF pnCount AS DWORD _                           ' __out ULONG32 *pnCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDimensions ( _                             ' VTable offset = 48
     BYVAL cdim AS DWORD _                              ' __in ULONG32 cdim
   , BYVAL dims AS ICorDebugArrayValue _                ' __out ICorDebugArrayValue dims
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasBaseIndicies ( _                           ' VTable offset = 52
     BYREF pbHasBaseIndicies AS LONG _                  ' __out BOOL *pbHasBaseIndicies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaseIndicies ( _                           ' VTable offset = 56
     BYVAL cdim AS DWORD _                              ' __in ULONG32 cdim
   , BYVAL indicies AS ICorDebugArrayValue _            ' __out ICorDebugArrayValue indicies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 60
     BYVAL cdim AS DWORD _                              ' __in ULONG32 cdim
   , BYVAL indices AS ICorDebugArrayValue _             ' __in ICorDebugArrayValue indices
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetElementAtPosition ( _                      ' VTable offset = 64
     BYVAL nPosition AS DWORD _                         ' __in ULONG32 nPosition
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugArrayValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugHandleValue
' IID = {029596E8-276B-46A1-9821-732E96BBB00B}
' Inherited interface = ICorDebugReferenceValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugHandleValue_INTERFACE_DEFINED)
    %ICorDebugHandleValue_INTERFACE_DEFINED = 1

INTERFACE ICorDebugHandleValue $IID_ICorDebugHandleValue

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugReferenceValue Methods
   ' =====================================================================================
   METHOD IsNull ( _                                    ' VTable offset = 28
     BYREF pbNull AS LONG _                             ' __out BOOL *pbNull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 32
     BYREF pValue AS QUAD _                             ' __out CORDB_ADDRESS *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYVAL value AS QUAD _                              ' __in CORDB_ADDRESS value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Dereference ( _                               ' VTable offset = 40
     BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DereferenceStrong ( _                         ' VTable offset = 44
     BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugHandleValue Methods
   ' =====================================================================================
   METHOD GetHandleType ( _                             ' VTable offset = 48
     BYREF pType AS LONG _                              ' __out CorDebugHandleType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Dispose ( _                                   ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugHandleValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugContext
' IID = {CC7BCB00-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugObjectValue
' ########################################################################################

#IF NOT %DEF(%ICorDebugContext_INTERFACE_DEFINED)
    %ICorDebugContext_INTERFACE_DEFINED = 1

INTERFACE ICorDebugContext $IID_ICorDebugContext

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugValue Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out CorElementType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS DWORD _                             ' __out ULONG32 *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAddress ( _                                ' VTable offset = 20
     BYREF pAddress AS QUAD _                           ' __out CORDB_ADDRESS *pAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBreakpoint ( _                          ' VTable offset = 24
     BYREF ppBreakpoint AS ICorDebugValueBreakpoint _   ' __out ICorDebugValueBreakpoint **ppBreakpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugObjectValue Methods
   ' =====================================================================================
   METHOD GetClass ( _                                  ' VTable offset = 28
     BYREF ppClass AS ICorDebugClass _                  ' __out ICorDebugClass **ppClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldValue ( _                             ' VTable offset = 32
     BYVAL pClass AS ICorDebugClass _                   ' __in ICorDebugClass *pClass
   , BYVAL fieldDef AS DWORD _                          ' __in mdFieldDef fieldDef
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVirtualMethod ( _                          ' VTable offset = 36
     BYVAL memberRef AS DWORD _                         ' __in mdMemberRef memberRef
   , BYREF ppFunction AS ICorDebugFunction _            ' __out ICorDebugFunction **ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 40
     BYREF ppContext AS ICorDebugContext _              ' __out ICorDebugContext **ppContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueClass ( _                              ' VTable offset = 44
     BYREF pbIsValueClass AS LONG _                     ' __out BOOL *pbIsValueClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetManagedCopy ( _                            ' VTable offset = 48
     BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFromManagedCopy ( _                        ' VTable offset = 52
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugContext Methods
   ' =====================================================================================

   ' his interface has not additional methods

END INTERFACE

#ENDIF   ' /* __ICorDebugContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugEnum
' IID = {CC7BCB01-8A68-11D2-983C-0000F808342D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugEnum_INTERFACE_DEFINED)
    %ICorDebugEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugEnum $IID_ICorDebugEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugObjectEnum
' IID = {CC7BCB02-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugObjectEnum_INTERFACE_DEFINED)
    %ICorDebugObjectEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugObjectEnum $IID_ICorDebugObjectEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugObjectEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL objects AS ICorDebugObjectEnum _             ' __out ICorDebugObjectEnum objects
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugObjectEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugBreakpointEnum
' IID = {CC7BCB03-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugBreakpointEnum_INTERFACE_DEFINED)
    %ICorDebugBreakpointEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugBreakpointEnum $IID_ICorDebugBreakpointEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugBreakpointEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL breakpoints AS ICorDebugBreakpointEnum _     ' __out ICorDebugBreakpointEnum breakpoints
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugBreakpointEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugStepperEnum
' IID = {CC7BCB04-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugStepperEnum_INTERFACE_DEFINED)
    %ICorDebugStepperEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugStepperEnum $IID_ICorDebugStepperEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugStepperEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL steppers AS ICorDebugStepperEnum _           ' __out ICorDebugStepperEnum steppers
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugStepperEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugProcessEnum
' IID = {CC7BCB05-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugProcessEnum_INTERFACE_DEFINED)
    %ICorDebugProcessEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugProcessEnum $IID_ICorDebugProcessEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugProcessEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL processes AS ICorDebugProcessEnum _          ' __out ICorDebugProcessEnum processes
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugProcessEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugThreadEnum
' IID = {CC7BCB06-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugThreadEnum_INTERFACE_DEFINED)
    %ICorDebugThreadEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugThreadEnum $IID_ICorDebugThreadEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugThreadEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL threads AS ICorDebugThreadEnum _             ' __out ICorDebugThreadEnum threads
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugThreadEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugFrameEnum
' IID = {CC7BCB07-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugFrameEnum_INTERFACE_DEFINED)
    %ICorDebugFrameEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugFrameEnum $IID_ICorDebugFrameEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugFrameEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL frames AS ICorDebugFrameEnum _               ' __out ICorDebugFrameEnum frames
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugFrameEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugChainEnum
' IID = {CC7BCB08-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugChainEnum_INTERFACE_DEFINED)
    %ICorDebugChainEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugChainEnum $IID_ICorDebugChainEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugChainEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL chains AS ICorDebugChainEnum _               ' __out ICorDebugChainEnum chains
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugChainEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugModuleEnum
' IID = {CC7BCB09-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugModuleEnum_INTERFACE_DEFINED)
    %ICorDebugModuleEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugModuleEnum $IID_ICorDebugModuleEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugModuleEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL modules AS ICorDebugModuleEnum _             ' __out ICorDebugModuleEnum modules
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugModuleEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugValueEnum
' IID = {CC7BCB0A-8A68-11D2-983C-0000F808342D}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugValueEnum_INTERFACE_DEFINED)
    %ICorDebugValueEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugValueEnum $IID_ICorDebugValueEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugValueEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL values AS ICorDebugValueEnum _               ' __out ICorDebugValueEnum values
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugValueEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugCodeEnum
' IID = {55E96461-9645-45E4-A2FF-0367877ABCDE}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugCodeEnum_INTERFACE_DEFINED)
    %ICorDebugCodeEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugCodeEnum $IID_ICorDebugCodeEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugCodeEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL values AS ICorDebugCodeEnum _                ' __out ICorDebugCodeEnum values
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugCodeEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugTypeEnum
' IID = {10F27499-9DF2-43CE-8333-A321D7C99CB4}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugTypeEnum_INTERFACE_DEFINED)
    %ICorDebugTypeEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugTypeEnum $IID_ICorDebugTypeEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugTypeEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL values AS ICorDebugTypeEnum _                ' __out ICorDebugTypeEnum values
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugTypeEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugType
' IID = {D613F0BB-ACE1-4C19-BD72-E4C08D5DA7F5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugType_INTERFACE_DEFINED)
    %ICorDebugType_INTERFACE_DEFINED = 1

INTERFACE ICorDebugType $IID_ICorDebugType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF ty AS DWORD _                                ' __out CorElementType *ty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClass ( _                                  ' VTable offset = 16
     BYREF ppClass AS ICorDebugClass _                  ' __out ICorDebugClass **ppClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateTypeParameters ( _                   ' VTable offset = 20
     BYREF ppTyParEnum AS ICorDebugTypeEnum _           ' __out ICorDebugTypeEnum **ppTyParEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstTypeParameter ( _                     ' VTable offset = 24
     BYREF value AS ICorDebugType _                     ' __out ICorDebugType **value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBase ( _                                   ' VTable offset = 28
     BYREF pBase AS ICorDebugType _                     ' __out ICorDebugType **pBase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStaticFieldValue ( _                       ' VTable offset = 32
     BYVAL fieldDef AS DWORD _                          ' __in mdFieldDef fieldDef
   , BYVAL pFrame AS ICorDebugFrame _                   ' __in ICorDebugFrame *pFrame
   , BYREF ppValue AS ICorDebugValue _                  ' __out ICorDebugValue **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRank ( _                                   ' VTable offset = 36
     BYREF pnRank AS DWORD _                            ' __out ULONG32 *pnRank
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugErrorInfoEnum
' IID = {F0E18809-72B5-11D2-976F-00A0C9B4D50C}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugErrorInfoEnum_INTERFACE_DEFINED)
    %ICorDebugErrorInfoEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugErrorInfoEnum $IID_ICorDebugErrorInfoEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugErrorInfoEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL errors AS ICorDebugErrorInfoEnum _           ' __out ICorDebugErrorInfoEnum errors
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugErrorInfoEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugAppDomainEnum
' IID = {63CA1B24-4359-4883-BD57-13F815F58744}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugAppDomainEnum_INTERFACE_DEFINED)
    %ICorDebugAppDomainEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAppDomainEnum $IID_ICorDebugAppDomainEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugAppDomainEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL values AS ICorDebugAppDomainEnum _           ' __out ICorDebugAppDomainEnum values
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAppDomainEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugAssemblyEnum
' IID = {4A2A1EC9-85EC-4BFB-9F15-A89FDFE0FE83}
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugAssemblyEnum_INTERFACE_DEFINED)
    %ICorDebugAssemblyEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugAssemblyEnum $IID_ICorDebugAssemblyEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum Methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugAssemblyEnum Methods
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYVAL values AS ICorDebugAssemblyEnum _            ' __out ICorDebugAssemblyEnum values
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugAssemblyEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugBlockingObjectEnum
' IID = 976A6278-134A-4A81-81A3-8F277943F4C3
' Inherited interface = ICorDebugEnum
' ########################################################################################

#IF NOT %DEF(%ICorDebugBlockingObjectEnum_INTERFACE_DEFINED)
    %ICorDebugBlockingObjectEnum_INTERFACE_DEFINED = 1

INTERFACE ICorDebugBlockingObjectEnum $IID_ICorDebugBlockingObjectEnum

   INHERIT IUnknown

   ' =====================================================================================
   ' ICorDebugEnum methods
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS ICorDebugEnum _                    ' __out ICorDebugEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 24
     BYREF pcelt AS DWORD _                             ' __out ULONG *pcelt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICorDebugBlockingObjectEnum method
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 28
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF values AS CorDebugBlockingObject _           ' __out CorDebugBlockingObject values[  ]
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugBlockingObjectEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugMDA
' IID = {CC726F2F-1DB7-459B-B0EC-05F01D841B42}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorDebugMDA_INTERFACE_DEFINED)
    %ICorDebugMDA_INTERFACE_DEFINED = 1

' enum CorDebugMDAFlags
%CORDEBUG_MDA_FLAG_SLIP = &H2

INTERFACE ICorDebugMDA $IID_ICorDebugMDA

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXML ( _                                    ' VTable offset = 20
     BYVAL cchName AS DWORD _                           ' __in ULONG32 cchName VT
   , BYREF pcchName AS DWORD _                          ' __out ULONG32 *pcchName
   , BYREF szName AS WSTRINGZ _                         ' __out WCHAR szName[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 24
     BYREF pFlags AS LONG _                             ' __in CorDebugMDAFlags *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOSThreadId ( _                             ' VTable offset = 28
     BYREF pOsTid AS DWORD _                            ' __out DWORD *pOsTid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugMDA_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugEditAndContinueErrorInfo
' IID = 8D600D41-F4F6-4cb3-B7EC-7BD164944036
' Inherited interface = IUnknown
' /* DEPRECATED */
' ########################################################################################

#IF NOT %DEF(%ICorDebugEditAndContinueErrorInfo_INTERFACE_DEFINED)
    %ICorDebugEditAndContinueErrorInfo_INTERFACE_DEFINED = 1

INTERFACE ICorDebugEditAndContinueErrorInfo $IID_ICorDebugEditAndContinueErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetModule ( _                                 ' VTable offset = 12
     BYREF ppModule AS ICorDebugModule _                ' __out ICorDebugModule **ppModule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToken ( _                                  ' VTable offset = 16
     BYREF pToken AS DWORD _                            ' __out mdToken *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorCode ( _                              ' VTable offset = 20
     BYREF pHr AS LONG _                                ' __out HRESULT *pHr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 24
     BYVAL cchString AS DWORD _                         ' __in ULONG32 cchString
   , BYREF pcchString AS DWORD _                        ' __out ULONG32 *pcchString
   , BYREF szString AS WSTRINGZ _                       ' __out WCHAR szString[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugEditAndContinueErrorInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorDebugEditAndContinueSnapshot
' IID = {6DC3FA01-D7CB-11D2-8A95-0080C792E5D8}
' Inherited interface = IUnknown
' /* DEPRECATED */
' ########################################################################################

#IF NOT %DEF(%ICorDebugEditAndContinueSnapshot_INTERFACE_DEFINED)
    %ICorDebugEditAndContinueSnapshot_INTERFACE_DEFINED = 1

INTERFACE ICorDebugEditAndContinueSnapshot $IID_ICorDebugEditAndContinueSnapshot

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CopyMetaData ( _                              ' VTable offset = 12
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pMvid AS GUID _                              ' __out GUID *pMvid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMvid ( _                                   ' VTable offset = 16
     BYREF pMvid AS GUID _                              ' __out GUID *pMvid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRoDataRVA ( _                              ' VTable offset = 20
     BYREF pRoDataRVA AS DWORD _                        ' __out ULONG32 *pRoDataRVA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRwDataRVA ( _                              ' VTable offset = 24
     BYREF pRwDataRVA AS DWORD _                        ' __out ULONG32 *pRwDataRVA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPEBytes ( _                                ' VTable offset = 28
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetILMap ( _                                  ' VTable offset = 32
     BYVAL mdFunction AS DWORD _                        ' __in mdToken mdFunction
   , BYVAL cMapSize AS DWORD _                          ' __in ULONG cMapSize
   , BYREF map AS COR_IL_MAP _                          ' __in COR_IL_MAP *map
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPESymbolBytes ( _                          ' VTable offset = 36
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream IStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorDebugEditAndContinueSnapshot_INTERFACE_DEFINED__ */
