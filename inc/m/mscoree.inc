' ########################################################################################
' Microsoft Windows
' File: mscoree.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: mscoree
' Version: 2.0
' Documentation string: Common Language Runtime Execution Engine 2.0 Library
' Path: C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\mscoree.tlb
' Library GUID: {5477469E-83B1-11D2-8B49-00A0C9B7C9C4}
' ########################################################################################

#INCLUDE THIS ONCE
%MSCOREE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "gchost.inc"
#INCLUDE ONCE "ivalidator.inc"

'#ifndef USE_DEPRECATED_CLR_API_WITHOUT_WARNING
'#define DEPRECATED_CLR_API_MESG "This API has been deprecated. Refer to http://go.microsoft.com/fwlink/?LinkId=143720 for more details."
'#define DECLARE_DEPRECATED __declspec(deprecated(DEPRECATED_CLR_API_MESG))
'#define DEPRECATED_CLR_STDAPI EXTERN_C DECLARE_DEPRECATED HRESULT STDAPICALLTYPE
'#else // USE_DEPRECATED_CLR_API_WITHOUT_WARNING
'#define DECLARE_DEPRECATED
'#define DEPRECATED_CLR_STDAPI STDAPI
'#endif // !USE_DEPRECATED_CLR_API_WITHOUT_WARNING

%CLR_MAJOR_VERSION          = 4
%CLR_MINOR_VERSION          = 0
%CLR_BUILD_VERSION          = 30319
%CLR_ASSEMBLY_MAJOR_VERSION = 4
%CLR_ASSEMBLY_MINOR_VERSION = 0
%CLR_ASSEMBLY_BUILD_VERSION = 0

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {3F281000-E95A-11D2-886B-00C04F869F04}
$PROGID_CCWUComCallWrapper1 = "CCWU.ComCallWrapper.1"
' CLSID = {90F1A06E-7712-4762-86B5-7A5EBA6BDB02}
$PROGID_CLRMetaDataCLRRuntimeHost2 = "CLRMetaData.CLRRuntimeHost.2"
' CLSID = {CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}
$PROGID_CLRMetaDataCorRuntimeHost2 = "CLRMetaData.CorRuntimeHost.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {3F281000-E95A-11D2-886B-00C04F869F04}
$PROGID_CCWUComCallWrapper = "CCWU.ComCallWrapper"
' CLSID = {90F1A06E-7712-4762-86B5-7A5EBA6BDB02}
$PROGID_CLRMetaDataCLRRuntimeHost = "CLRMetaData.CLRRuntimeHost"
' CLSID = {CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}
$PROGID_CLRMetaDataCorRuntimeHost = "CLRMetaData.CorRuntimeHost"

' ========================================================================================
' CLSIDs (Class identifiers)
' ========================================================================================

$CLSID_CorRuntimeHost = GUID$("{CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}")
$CLSID_TypeNameFactory = GUID$("{B81FF171-20F3-11D2-8DCC-00A0C9B00525}")
$CLSID_CLRRuntimeHost = GUID$("{90F1A06E-7712-4762-86B5-7A5EBA6BDB02}")
$CLSID_ComCallUnmarshal = GUID$("{3F281000-E95A-11D2-886B-00C04F869F04}")
$CLSID_ComCallUnmarshalV4 = GUID$("{45FB4600-E6E8-4928-B25E-50476FF79425}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IObjectHandle = GUID$("{C460E2B4-E199-412A-8456-84DC3E4838C3}")
$IID_IManagedObject = GUID$("{C3FCC19E-A970-11D2-8B5A-00A0C9B7C9C4}")
$IID_IApartmentCallback = GUID$("{178E5337-1528-4591-B1C9-1C6E484686D8}")
$IID_ICatalogServices = GUID$("{04C6BE1E-1DB1-4058-AB7A-700CCCFBF254}")
$IID_ICorRuntimeHost = GUID$("{CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}")
$IID_ICorThreadpool = GUID$("{84680D3A-B2C1-46E8-ACC2-DBC0A359159A}")
$IID_ICLRDebugManager = GUID$("{00DCAEC6-2AC0-43A9-ACF9-1E36C139B10D}")
$IID_ICLRErrorReportingManager = GUID$("{980D2F1A-BF79-4C08-812A-BB9778928F78}")
$IID_IHostMemoryNeededCallback = GUID$("{47EB8E57-0846-4546-AF76-6F42FCFC2649}")
$IID_IHostMalloc = GUID$("{1831991C-CC53-4A31-B218-04E910446479}")
$IID_IHostMemoryManager = GUID$("{7BC698D1-F9E3-4460-9CDE-D04248E9FA25}")
$IID_ICLRTask = GUID$("{28E66A4A-9906-4225-B231-9187C3EB8611}")
$IID_ICLRTask2 = GUID$("{28E66A4A-9906-4225-B231-9187C3EB8612}")
$IID_IHostTask = GUID$("{C2275828-C4B1-4B55-82C9-92135F74DF1A}")
$IID_ICLRTaskManager = GUID$("{4862EFBE-3AE5-44F8-8FEB-346190EE8A34}")
$IID_IHostTaskManager = GUID$("{997FF24C-43B7-4352-8667-0DC04FAFD354}")
$IID_IHostThreadpoolManager = GUID$("{983D50E2-CB15-466B-80FC-845DC6E8C5FD}")
$IID_ICLRIoCompletionManager = GUID$("{2D74CE86-B8D6-4C84-B3A7-9768933B3C12}")
$IID_ICLRGCManager = GUID$("{54D9007E-A8E2-4885-B7BF-F998DEEE4F2A}")
$IID_IHostIoCompletionManager = GUID$("{8BDE9D80-EC06-41D6-83E6-22580EFFCC20}")
$IID_IHostSyncManager = GUID$("{234330C7-5F10-4F20-9615-5122DAB7A0AC}")
$IID_IHostCrst = GUID$("{6DF710A6-26A4-4A65-8CD5-7237B8BDA8DC}")
$IID_IHostAutoEvent = GUID$("{50B0CFCE-4063-4278-9673-E5CB4ED0BDB8}")
$IID_IHostManualEvent = GUID$("{1BF4EC38-AFFE-4FB9-85A6-525268F15B54}")
$IID_IHostSemaphore = GUID$("{855EFD47-CC09-463A-A97D-16ACAB882661}")
$IID_ICLRSyncManager = GUID$("{55FF199D-AD21-48F9-A16C-F24EBBB8727D}")
$IID_ICLRAppDomainResourceMonitor = GUID$("{C62DE18C-2E23-4AEA-8423-B40C1FC59EAE}")
$IID_ICLRPolicyManager = GUID$("{7D290010-D781-45DA-A6F8-AA5D711A730E}")
$IID_IHostPolicyManager = GUID$("{7AE49844-B1E3-4683-BA7C-1E8212EA3B79}")
$IID_IHostGCManager = GUID$("{5D4EC34E-F248-457B-B603-255FAABA0D21}")
$IID_IActionOnCLREvent = GUID$("{607BE24B-D91B-4E28-A242-61871CE56E35}")
$IID_ICLROnEventManager = GUID$("{1D0E0132-E64F-493D-9260-025C0E32C175}")
$IID_ICLRRuntimeHost = GUID$("{90F1A06C-7712-4762-86B5-7A5EBA6BDB02}")
$IID_ICLRHostProtectionManager = GUID$("{89F25F5C-CEEF-43E1-9CFA-A68CE863AAAC}")
$IID_IHostAssemblyStore = GUID$("{7B102A88-3F7F-496D-8FA2-C35374E01AF3}")
$IID_IHostAssemblyManager = GUID$("{613DABD7-62B2-493E-9E65-C1E32A1E0C5E}")
$IID_IHostSecurityManager = GUID$("{75AD2468-A349-4D02-A764-76A68AEE0C4F}")
$IID_IHostSecurityContext = GUID$("{7E573CE4-0343-4423-98D7-6318348A1D3C}")
$IID_ICLRAssemblyIdentityManager = GUID$("{15F0A9DA-3FF6-4393-9DA9-FDFD284E6972}")
$IID_ICLRDomainManager = GUID$("{270D00A2-8E15-4D0B-ADEB-37BC3E47DF77}")
$IID_ITypeName = GUID$("{B81FF171-20F3-11D2-8DCC-00A0C9B00522}")
$IID_ICLRAssemblyReferenceList = GUID$("{1B2C9750-2E66-4BDA-8B44-0A642C5CD733}")
$IID_ICLRReferenceAssemblyEnum = GUID$("{D509CB5D-CF32-4876-AE61-67770CF91973}")
$IID_ICLRProbingAssemblyEnum = GUID$("{D0C5FB1F-416B-4F97-81F4-7AC7DC24DD5D}")
$IID_ICLRHostBindingPolicyManager = GUID$("{4B3545E7-1856-48C9-A8BA-24B21A753C09}")
$IID_ITypeNameBuilder = GUID$("{B81FF171-20F3-11D2-8DCC-00A0C9B00523}")
$IID_ITypeNameFactory = GUID$("{B81FF171-20F3-11D2-8DCC-00A0C9B00521}")

' ========================================================================================
' Functions
' ========================================================================================

' This function is deprecated. It is superseded by the ICLRRuntimeInfo::GetRuntimeDirectory method provided in the .NET Framework version 4.
DECLARE FUNCTION GetCORSystemDirectory IMPORT "mscoree.dll" ALIAS "GetCORSystemDirectory" ( _
   BYREF pbuffer AS WSTRINGZ _                          ' __out LPWSTR  pbuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYREF dwlength AS DWORD _                            ' __out DWORD*  dwlength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetCORVersion IMPORT "mscoree.dll" ALIAS "GetCORVersion" ( _
   BYREF pbuffer AS WSTRINGZ _                          ' __out LPWSTR  pbuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYREF dwlength AS DWORD _                            ' __out DWORD*  dwlength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetFileVersion IMPORT "mscoree.dll" ALIAS "GetFileVersion" ( _
   BYREF szFilename AS WSTRINGZ _                       ' __in  LPCWSTR szFilename
 , BYREF szBuffer AS WSTRINGZ _                         ' __inout LPWSTR szBuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYREF dwlength AS DWORD _                            ' __out DWORD*  dwlength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetCORRequiredVersion IMPORT "mscoree.dll" ALIAS "GetCORRequiredVersion" ( _
   BYREF pbuffer AS WSTRINGZ _                          ' __out LPWSTR pbuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD  cchBuffer
 , BYREF dwlength AS DWORD _                            ' __out DWORD* dwlength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetRequestedRuntimeInfo IMPORT "mscoree.dll" ALIAS "GetRequestedRuntimeInfo" ( _
   BYREF pExe AS WSTRINGZ _                             ' __in  LPCWSTR  pExe
 , BYREF pwszVersion AS WSTRINGZ _                      ' __in  LPCWSTR  pwszVersion
 , BYREF pConfigurationFile AS WSTRINGZ _               ' __in  LPCWSTR  pConfigurationFile
 , BYVAL startupFlags AS DWORD _                        ' __in  DWORD    startupFlags
 , BYVAL runtimeInfoFlags AS DWORD _                    ' __in  DWORD    runtimeInfoFlags
 , BYREF pDirectory AS WSTRINGZ _                       ' __out LPWSTR   pDirectory
 , BYVAL dwDirectory AS DWORD _                         ' __in  DWORD    dwDirectory
 , BYREF dwDirectoryLength AS DWORD _                   ' __out DWORD   *dwDirectoryLength
 , BYREF pVersion AS WSTRINGZ _                         ' __out LPWSTR   pVersion
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD    cchBuffer
 , BYREF dwlength AS DWORD _                            ' __out DWORD   *dwlength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetRequestedRuntimeVersion IMPORT "mscoree.dll" ALIAS "GetRequestedRuntimeVersion" ( _
   BYREF pExe AS WSTRINGZ _                             ' __in  LPWSTR  pExe
 , BYREF pVersion AS WSTRINGZ _                         ' __out LPWSTR  pVersion
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYREF pdwLength AS DWORD _                           ' __out DWORD  *pdwLength
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorBindToRuntimeHost IMPORT "mscoree.dll" ALIAS "CorBindToRuntimeHost" ( _
   BYREF pwszVersion AS WSTRINGZ _                      ' __in LPCWSTR       pwszVersion
 , BYREF pwszBuildFlavor AS WSTRINGZ _                  ' __in LPCWSTR       pwszBuildFlavor
 , BYREF pwszHostConfigFile AS WSTRINGZ _               ' __in LPCWSTR       pwszHostConfigFile
 , BYVAL pReserved AS DWORD _                           ' __in VOID*         pReserved
 , BYVAL startupFlags AS DWORD _                        ' __in DWORD         startupFlags
 , BYREF rclsid AS GUID _                               ' __in REFCLSID      rclsid
 , BYREF riid AS GUID _                                 ' __in REFIID        riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID FAR  *ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorBindToRuntimeEx IMPORT "mscoree.dll" ALIAS "CorBindToRuntimeEx" ( _
   BYREF pwszVersion AS WSTRINGZ _                      ' __in  LPWSTR    pwszVersion
 , BYREF pwszBuildFlavor AS WSTRINGZ _                  ' __in  LPWSTR    pwszBuildFlavor
 , BYVAL startupFlags AS DWORD _                        ' __in  DWORD     startupFlags
 , BYREF rclsid AS GUID _                               ' __in  REFCLSID  rclsid
 , BYREF riid AS GUID _                                 ' __in  REFIID    riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID FAR  *ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorBindToRuntimeByCfg IMPORT "mscoree.dll" ALIAS "CorBindToRuntimeByCfg" ( _
   BYVAL pCfgStream AS IStream _                        ' __in  IStream     *pCfgStream
 , BYVAL reserved AS DWORD _                            ' __in  DWORD        reserved
 , BYVAL startupFlags AS DWORD _                        ' __in  DWORD        startupFlags
 , BYREF rclsid AS GUID _                               ' __in  REFCLSID     rclsid
 , BYREF riid AS GUID _                                 ' __in  REFIID       riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID FAR  *ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorBindToRuntime IMPORT "mscoree.dll" ALIAS "CorBindToRuntime" ( _
   BYREF pwszVersion AS WSTRINGZ _                      ' __in  LPCWSTR     pwszVersion
 , BYREF pwszBuildFlavor AS WSTRINGZ _                  ' __in  LPCWSTR     pwszBuildFlavor
 , BYREF rclsid AS GUID _                               ' __in  REFCLSID    rclsid
 , BYREF riid AS GUID _                                 ' __in  REFIID      riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID FAR  *ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorBindToCurrentRuntime IMPORT "mscoree.dll" ALIAS "CorBindToCurrentRuntime" ( _
   BYREF pwszFileName AS WSTRINGZ _                     ' __in  LPCWSTR   pwszFileName
 , BYREF rclsid AS GUID _                               ' __in  REFCLSID  rclsid
 , BYREF riid AS GUID _                                 ' __in  REFIID    riid
 , BYREF ppv AS ANY _                                   ' __out LPVOID FAR  *ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
' Use COM activation to create an instance of the managed type, or use hosting
' (see .NET Framework 4 Hosting Interfaces).
DECLARE FUNCTION ClrCreateManagedInstance IMPORT "mscoree.dll" ALIAS "ClrCreateManagedInstance" ( _
   BYREF pTypeName AS WSTRINGZ _                        ' __in  LPCWSTR  pTypeName
 , BYREF riid AS GUID _                                 ' __in  REFIID   riid
 , BYREF ppObject AS ANY _                              ' __out void     **ppObject
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE SUB CorMarkThreadInThreadPool IMPORT "mscoree.dll" ALIAS "CorMarkThreadInThreadPool" ( _
 )                                                      ' void

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION RunDll32ShimW IMPORT "mscoree.dll" ALIAS "RunDll32ShimW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND        hwnd
 , BYVAL hinst AS DWORD _                               ' __in HINSTANCE   hinst
 , BYREF lpszCmdLine AS WSTRINGZ _                      ' __in LPCWSTR     lpszCmdLine
 , BYVAL nCmdShow AS LONG _                             ' __in int         nCmdShow
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
' Use the ICLRRuntimeInfo::LoadLibrary method instead.
DECLARE FUNCTION LoadLibraryShim IMPORT "mscoree.dll" ALIAS "LoadLibraryShim" ( _
   BYREF szDllName AS WSTRINGZ _                        ' __in  LPCWSTR  szDllName
 , BYREF szVersion AS WSTRINGZ _                        ' __in  LPCWSTR  szVersion
 , BYVAL pvReserved AS DWORD _                          ' __in  LPVOID   pvReserved
 , BYREF phModDll AS DWORD _                            ' __out HMODULE *phModDll
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CallFunctionShim IMPORT "mscoree.dll" ALIAS "CallFunctionShim" ( _
   BYREF szDllName AS WSTRINGZ _                        ' __in LPCWSTR     szDllName
 , BYREF szFunctionName AS ASCIIZ _                     ' __in LPCSTR      szFunctionName
 , BYVAL lpvArgument1 AS DWORD _                        ' __in LPVOID      lpvArgument1
 , BYVAL lpvArgument2 AS DWORD _                        ' __in LPVOID      lpvArgument2
 , BYREF szVersion AS WSTRINGZ _                        ' __in LPCWSTR     szVersion
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID      pvReserved
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetRealProcAddress IMPORT "mscoree.dll" ALIAS "GetRealProcAddress" ( _
   BYREF pwszProcName AS ASCIIZ _                       ' __in  LPCSTR  pwszProcName
 , BYREF ppv AS ANY _                                   ' __out VOID  **ppv
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
' Use the ICLRMetaHost::ExitProcess method instead
DECLARE SUB CorExitProcess IMPORT "mscoree.dll" ALIAS "CorExitProcess" ( _
   BYVAL exitCode AS LONG _                             ' int exitCode
 )                                                      ' void

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION LoadStringRC IMPORT "mscoree.dll" ALIAS "LoadStringRC" ( _
   BYVAL iResourceID AS DWORD _                         ' __in  UINT    iResourceID
 , BYREF szBuffer AS WSTRINGZ _                         ' __out LPWSTR  szBuffer
 , BYVAL iMax AS LONG _                                 ' __in  int     iMax
 , BYVAL bQuiet AS LONG _                               ' __in  int     bQuiet
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION LoadStringRCEx IMPORT "mscoree.dll" ALIAS "LoadStringRCEx" ( _
   BYVAL lcid AS DWORD _                                ' __in  LCID    lcid
 , BYVAL iResouceID AS DWORD _                          ' __in  UINT    iResouceID
 , BYREF szBuffer AS WSTRINGZ _                         ' __out LPWSTR  szBuffer
 , BYVAL iMax AS LONG _                                 ' __in  int     iMax
 , BYVAL bQuiet AS LONG _                               ' __in  int     bQuiet
 , BYREF pcwchUsed AS LONG _                            ' __out int    *pcwchUsed
 ) AS LONG                                              ' HRESULT

'typedef HRESULT (__stdcall *FLockClrVersionCallback) ();

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION LockClrVersion IMPORT "mscoree.dll" ALIAS "LockClrVersion" ( _
   BYVAL hostCallback AS DWORD _                        ' __in FLockClrVersionCallback   hostCallback
 , BYVAL pBeginHostSetup AS DWORD _                     ' __in FLockClrVersionCallback  *pBeginHostSetup
 , BYVAL pEndHostSetup AS DWORD _                       ' __in FLockClrVersionCallback  *pEndHostSetup
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CreateDebuggingInterfaceFromVersion IMPORT "mscoree.dll" ALIAS "CreateDebuggingInterfaceFromVersion" ( _
   BYVAL iDebuggerVersion AS LONG _                     ' __in  int      iDebuggerVersion
 , BYREF szDebuggeeVersion AS WSTRINGZ _                ' __in  LPCWSTR  szDebuggeeVersion
 , BYREF ppCordb AS IUnknown _                          ' __out IUnknown **ppCordb
 ) AS LONG                                              ' HRESULT

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION GetVersionFromProcess IMPORT "mscoree.dll" ALIAS "GetVersionFromProcess" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE  hProcess
 , BYREF pVersion AS WSTRINGZ _                         ' __out LPWSTR  pVersion
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD   cchBuffer
 , BYREF dwLength AS DWORD _                            ' __out DWORD  *dwLength
 ) AS LONG                                              ' HRESULT

' enum HOST_TYPE
%HOST_TYPE_DEFAULT   = 0
%HOST_TYPE_APPLAUNCH = &H1
%HOST_TYPE_CORFLAG   = &H2

' This function has been deprecated in the .NET Framework version 4.
DECLARE FUNCTION CorLaunchApplication IMPORT "mscoree.dll" ALIAS "CorLaunchApplication" ( _
   BYVAL dwClickOnceHost AS DWORD _                     ' __in  HOST_TYPE                dwClickOnceHost
 , BYREF pwzAppFullName AS WSTRINGZ _                   ' __in  LPCWSTR                  pwzAppFullName
 , BYVAL dwManifestPaths AS DWORD _                     ' __in  DWORD                    dwManifestPaths
 , BYREF ppwzManifestPaths AS WSTRINGZ _                ' __in  LPCWSTR                 *ppwzManifestPaths
 , BYVAL dwActivationData AS DWORD _                    ' __in  DWORD                    dwActivationData
 , BYREF ppwzActivationData AS WSTRINGZ _               ' __in  LPCWSTR                 *ppwzActivationData
 , BYREF lpProcessInformation AS PROCESS_INFORMATION _  ' __out LPPROCESS_INFORMATION    lpProcessInformation
 ) AS LONG                                              ' HRESULT

'typedef HRESULT ( __stdcall *FExecuteInAppDomainCallback )(
'    void *cookie);

'FUNCTION FExecuteInAppDomainCallback (BYVAL cookie AS DWORD) AS LONG

' enum STARTUP_FLAGS
%STARTUP_CONCURRENT_GC                         = &H1???
%STARTUP_LOADER_OPTIMIZATION_MASK              = &H6???       ' 0x3 << 1
%STARTUP_LOADER_OPTIMIZATION_SINGLE_DOMAIN     = &H2???       ' 0x1 << 1
%STARTUP_LOADER_OPTIMIZATION_MULTI_DOMAIN      = &H4???       ' 0x2 << 1
%STARTUP_LOADER_OPTIMIZATION_MULTI_DOMAIN_HOST = &H6???       ' 0x3 << 1
%STARTUP_LOADER_SAFEMODE                       = &H10???
%STARTUP_LOADER_SETPREFERENCE                  = &H100???
%STARTUP_SERVER_GC                             = &H1000???
%STARTUP_HOARD_GC_VM                           = &H2000???
%STARTUP_SINGLE_VERSION_HOSTING_INTERFACE      = &H4000???
%STARTUP_LEGACY_IMPERSONATION                  = &H10000???
%STARTUP_DISABLE_COMMITTHREADSTACK             = &H20000???
%STARTUP_ALWAYSFLOW_IMPERSONATION              = &H40000???
%STARTUP_TRIM_GC_COMMIT                        = &H80000???
%STARTUP_ETW                                   = &H100000???
%STARTUP_ARM                                   = &H400000???

' enum CLSID_RESOLUTION_FLAGS
%CLSID_RESOLUTION_DEFAULT    = 0???
%CLSID_RESOLUTION_REGISTERED = &H1???

' enum RUNTIME_INFO_FLAGS
%RUNTIME_INFO_UPGRADE_VERSION        = &H1???
%RUNTIME_INFO_REQUEST_IA64           = &H2???
%RUNTIME_INFO_REQUEST_AMD64          = &H4???
%RUNTIME_INFO_REQUEST_X86            = &H8???
%RUNTIME_INFO_DONT_RETURN_DIRECTORY  = &H10???
%RUNTIME_INFO_DONT_RETURN_VERSION    = &H20???
%RUNTIME_INFO_DONT_SHOW_ERROR_DIALOG = &H40???

' enum APPDOMAIN_SECURITY_FLAGS
%APPDOMAIN_SECURITY_DEFAULT                        = 0???
%APPDOMAIN_SECURITY_SANDBOXED                      = &H1???
%APPDOMAIN_SECURITY_FORBID_CROSSAD_REVERSE_PINVOKE = &H2???
%APPDOMAIN_FORCE_TRIVIAL_WAIT_OPERATIONS           = &H8???

DECLARE FUNCTION GetRequestedRuntimeVersionForCLSID IMPORT "mscoree.dll" ALIAS "GetRequestedRuntimeVersionForCLSID" ( _
   BYREF rclsid AS GUID _                               ' __in  REFCLSID   rclsid
 , BYREF pVersion AS WSTRINGZ _                         ' __in  LPWSTR     pVersion
 , BYVAL cchBuffer AS DWORD _                           ' __in  DWORD      cchBuffer
 , BYREF dwLength AS DWORD _                            ' __out DWORD*     dwLength
 , BYVAL dwResolutionFlags AS DWORD _                   ' __in  CLSID_RESOLUTION_FLAGS dwResolutionFlags
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IObjectHandle
' IID = {C460E2B4-E199-412A-8456-84DC3E4838C3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectHandle_INTERFACE_DEFINED)
    %IObjectHandle_INTERFACE_DEFINED = 1

INTERFACE IObjectHandle $IID_IObjectHandle

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Unwrap ( _                                    ' VTable offset = 12
   ) AS VARIANT                                         ' __retval_out VARIANT *ppv
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectHandle_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAppDomainBinding
' IID = {5C2B07A7-1E98-11D3-872F-00C04F79ED0D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppDomainBinding_INTERFACE_DEFINED)
    %IAppDomainBinding_INTERFACE_DEFINED = 1

$IID_IAppDomainBinding = GUID$("{5C2B07A7-1E98-11D3-872F-00C04F79ED0D}")

INTERFACE IAppDomainBinding $IID_IAppDomainBinding

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAppDomain ( _                               ' VTable offset = 12
     BYVAL pAppdomain AS IUnknown _                     ' __in IUnknown *pAppdomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppDomainBinding_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGCThreadControl
' IID = {F31D1788-C397-4725-87A5-6AF3472C2791}
' Control over threads blocked in GC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGCThreadControl_INTERFACE_DEFINED)
    %IGCThreadControl_INTERFACE_DEFINED = 1

$IID_IGCThreadControl = GUID$("{F31D1788-C397-4725-87A5-6AF3472C2791}")

INTERFACE IGCThreadControl $IID_IGCThreadControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadIsBlockingForSuspension ( _             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SuspensionStarting ( _                        ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SuspensionEnding ( _                          ' VTable offset = 20
     BYVAL Generation AS DWORD _                        ' __in DWORD Generation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGCThreadControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGCHostControl
' IID = {5513D564-8374-4CB9-AED9-0083F4160A1D}
' Request change in virtual memory for GC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGCHostControl_INTERFACE_DEFINED)
    %IGCHostControl_INTERFACE_DEFINED = 1

$IID_IGCHostControl = GUID$("{5513D564-8374-4CB9-AED9-0083F4160A1D}")

INTERFACE IGCHostControl $IID_IGCHostControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RequestVirtualMemLimit ( _                    ' VTable offset = 12
     BYVAL sztMaxVirtualMemMB AS DWORD _                ' __in SIZE_T sztMaxVirtualMemMB
   , BYREF psztNewMaxVirtualMemMB AS DWORD _            ' __inout SIZE_T *psztNewMaxVirtualMemMB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGCHostControl_INTERFACE_DEFINED__ */

'#if (_MSC_VER < 1300 || _WIN32_WINNT < 0x0500)
'typedef VOID ( __stdcall *WAITORTIMERCALLBACK )(
'    PVOID __MIDL_0011,
'    BOOL __MIDL_0012);

'#endif // (_MSC_VER < 1300 || _WIN32_WINNT < 0x0500)
'#ifdef __midl
'typedef DWORD ( __stdcall *LPTHREAD_START_ROUTINE )(
'    LPVOID lpThreadParameter);

'typedef VOID ( *LPOVERLAPPED_COMPLETION_ROUTINE )(
'    DWORD dwErrorCode,
'    DWORD dwNumberOfBytesTransfered,
'    LPVOID lpOverlapped);

'#endif // __midl
'typedef VOID ( __stdcall *PTLS_CALLBACK_FUNCTION )(
'    PVOID __MIDL_0016);


' ########################################################################################
' Interface name = ICorThreadpool
' IID = {84680D3A-B2C1-46E8-ACC2-DBC0A359159A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorThreadpool_INTERFACE_DEFINED)
    %ICorThreadpool_INTERFACE_DEFINED = 1

INTERFACE ICorThreadpool $IID_ICorThreadpool

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CorRegisterWaitForSingleObject ( _            ' VTable offset = 12
     BYVAL phNewWaitObject AS DWORD _                   ' __in HANDLE *phNewWaitObject
   , BYVAL hWaitObject AS DWORD _                       ' __in HANDLE hWaitObject
   , BYVAL Callback AS DWORD _                          ' __in WAITORTIMERCALLBACK Callback
   , BYVAL Context AS DWORD _                           ' __in PVOID Context
   , BYVAL timeout AS DWORD _                           ' __in ULONG timeout
   , BYVAL executeOnlyOnce AS LONG _                    ' __in BOOL executeOnlyOnce
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorUnregisterWait ( _                         ' VTable offset = 16
     BYVAL hWaitObject AS DWORD _                       ' __in HANDLE hWaitObject
   , BYVAL CompletionEvent AS DWORD _                   ' __in HANDLE CompletionEvent
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorQueueUserWorkItem ( _                      ' VTable offset = 20
     BYVAL Function AS DWORD _                          ' __in LPTHREAD_START_ROUTINE Function
   , BYVAL Context AS DWORD _                           ' __in PVOID Context
   , BYVAL executeOnlyOnce AS LONG _                    ' __in BOOL executeOnlyOnce
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorCreateTimer ( _                            ' VTable offset = 24
     BYVAL phNewTimer AS DWORD _                        ' __in HANDLE *phNewTimer
   , BYVAL Callback AS DWORD _                          ' __in WAITORTIMERCALLBACK Callback
   , BYVAL Parameter AS DWORD _                         ' __in PVOID Parameter
   , BYVAL DueTime AS DWORD _                           ' __in DWORD DueTime
   , BYVAL Period AS DWORD _                            ' __in DWORD Period
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorChangeTimer ( _                            ' VTable offset = 28
     BYVAL Timer AS DWORD _                             ' __in HANDLE Timer
   , BYVAL DueTime AS DWORD _                           ' __in ULONG DueTime
   , BYVAL Period AS DWORD _                            ' __in ULONG Period
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorDeleteTimer ( _                            ' VTable offset = 32
     BYVAL Timer AS DWORD _                             ' __in HANDLE Timer
   , BYVAL CompletionEvent AS DWORD _                   ' __in HANDLE CompletionEvent
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorBindIoCompletionCallback ( _               ' VTable offset = 36
     BYVAL fileHandle AS DWORD _                        ' __in HANDLE fileHandle
   , BYVAL callback AS DWORD _                          ' __in LPOVERLAPPED_COMPLETION_ROUTINE callback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorCallOrQueueUserWorkItem ( _                ' VTable offset = 40
     BYVAL Function AS DWORD _                          ' __in LPTHREAD_START_ROUTINE Function
   , BYVAL Context AS DWORD _                           ' __in PVOID Context
   , BYREF result AS LONG _                             ' __out BOOL *result
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorSetMaxThreads ( _                          ' VTable offset = 44
     BYVAL MaxWorkerThreads AS DWORD _                  ' __in DWORD MaxWorkerThreads
   , BYVAL MaxIOCompletionThreads AS DWORD _            ' __in DWORD MaxIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorGetMaxThreads ( _                          ' VTable offset = 48
     BYVAL MaxWorkerThreads AS DWORD _                  ' __out DWORD *MaxWorkerThreads
   , BYREF MaxIOCompletionThreads AS DWORD _            ' __out DWORD *MaxIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CorGetAvailableThreads ( _                    ' VTable offset = 52
     BYREF AvailableWorkerThreads AS DWORD _            ' __out DWORD *AvailableWorkerThreads
   , BYREF AvailableIOCompletionThreads AS DWORD _      ' __out DWORD *AvailableIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorThreadpool_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDebuggerThreadControl
' IID = {23D86786-0BB5-4774-8FB5-E3522ADD6246}
' Control over threads blocked in debugging services
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebuggerThreadControl_INTERFACE_DEFINED)
    %IDebuggerThreadControl_INTERFACE_DEFINED = 1

$IID_IDebuggerThreadControl = GUID$("{23D86786-0BB5-4774-8FB5-E3522ADD6246}")

INTERFACE IDebuggerThreadControl $IID_IDebuggerThreadControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadIsBlockingForDebugger ( _               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseAllRuntimeThreads ( _                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartBlockingForDebugger ( _                  ' VTable offset = 20
     BYVAL dwUnused AS DWORD _                          ' __in DWORD dwUnused
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebuggerThreadControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDebuggerInfo
' IID = {BF24142D-A47D-4D24-A66D-8C2141944E44}
' Information on the state of the debugging services
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDebuggerInfo_INTERFACE_DEFINED)
    %IDebuggerInfo_INTERFACE_DEFINED = 1

$IID_IDebuggerInfo = GUID$("{BF24142D-A47D-4D24-A66D-8C2141944E44}")

INTERFACE IDebuggerInfo $IID_IDebuggerInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsDebuggerAttached ( _                        ' VTable offset = 12
     BYREF pbAttached AS LONG _                         ' __out BOOL* pbAttached
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDebuggerInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICorConfiguration
' IID = {5C2B07A5-1E98-11D3-872F-00C04F79ED0D}
' Common Language Runtime Configuration Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorConfiguration_INTERFACE_DEFINED)
    %ICorConfiguration_INTERFACE_DEFINED = 1

$IID_ICorConfiguration = GUID$("{5C2B07A5-1E98-11D3-872F-00C04F79ED0D}")

INTERFACE ICorConfiguration $IID_ICorConfiguration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGCThreadControl ( _                        ' VTable offset = 12
     BYVAL pGCThreadControl AS IGCThreadControl _       ' __in IGCThreadControl *pGCThreadControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGCHostControl ( _                          ' VTable offset = 16
     BYVAL pGCHostControl AS IGCHostControl _           ' __in IGCHostControl *pGCHostControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDebuggerThreadControl ( _                  ' VTable offset = 20
     BYVAL pDebuggerThreadControl AS IDebuggerThreadControl _ ' __in IDebuggerThreadControl *pDebuggerThreadControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDebuggerSpecialThread ( _                  ' VTable offset = 24
     BYVAL dwSpecialThreadId AS DWORD _                 ' __in DWORD dwSpecialThreadId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorConfiguration_INTERFACE_DEFINED__ */


'typedef void *HDOMAINENUM;

' ########################################################################################
' Interface name = ICorRuntimeHost
' IID = {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}
' Common Language Runtime Hosting Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorRuntimeHost_INTERFACE_DEFINED)
    %ICorRuntimeHost_INTERFACE_DEFINED = 1

INTERFACE ICorRuntimeHost $IID_ICorRuntimeHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateLogicalThreadState ( _                  ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteLogicalThreadState ( _                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchInLogicalThreadState ( _                ' VTable offset = 20
     BYREF pFiberCookie AS DWORD _                      ' __in DWORD *pFiberCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchOutLogicalThreadState ( _               ' VTable offset = 24
     BYREF pFiberCookie AS DWORD _                      ' __out DWORD **pFiberCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocksHeldByLogicalThread ( _                  ' VTable offset = 28
     BYREF pCount AS DWORD _                            ' __out DWORD *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapFile ( _                                   ' VTable offset = 32
     BYVAL hFile AS DWORD _                             ' __in HANDLE hFile
   , BYREF hMapAddress AS DWORD _                       ' __out HMODULE *hMapAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConfiguration ( _                          ' VTable offset = 36
     BYREF pConfiguration AS ICorConfiguration _        ' __out ICorConfiguration **pConfiguration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDomain ( _                              ' VTable offset = 48
     BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   , BYVAL pIdentityArray AS IUnknown _                 ' __in IUnknown *pIdentityArray
   , BYREF pAppDomain AS IUnknown _                     ' __out IUnknown **pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultDomain ( _                          ' VTable offset = 52
     BYREF pAppDomain AS IUnknown _                     ' __out IUnknown **pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDomains ( _                               ' VTable offset = 56
     BYREF hEnum AS DWORD _                             ' __out HDOMAINENUM *hEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextDomain ( _                                ' VTable offset = 60
     BYVAL hEnum AS DWORD _                             ' __in HDOMAINENUM hEnum
   , BYREF pAppDomain AS IUnknown _                     ' __out IUnknown **pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseEnum ( _                                 ' VTable offset = 64
     BYVAL hEnum AS DWORD _                             ' __in HDOMAINENUM hEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDomainEx ( _                            ' VTable offset = 68
     BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   , BYVAL pSetup AS IUnknown _                         ' __in IUnknown *pSetup
   , BYVAL pEvidence AS IUnknown _                      ' __in IUnknown *pEvidence
   , BYREF pAppDomain AS IUnknown _                     ' __out IUnknown **pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDomainSetup ( _                         ' VTable offset = 72
     BYREF pAppDomainSetup AS IUnknown _                ' __out IUnknown **pAppDomainSetup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEvidence ( _                            ' VTable offset = 76
     BYREF pEvidence AS IUnknown _                      ' __out IUnknown **pEvidence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadDomain ( _                              ' VTable offset = 80
     BYVAL pAppDomain AS IUnknown _                     ' __in IUnknown *pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CurrentDomain ( _                             ' VTable offset = 84
     BYREF pAppDomain AS IUnknown _                     ' __out IUnknown **pAppDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorRuntimeHost_INTERFACE_DEFINED__ */

' enum EMemoryAvailable
%eMemoryAvailableLow     = 1
%eMemoryAvailableNeutral = 2
%eMemoryAvailableHigh    = 3

' enum EMemoryCriticalLevel
%eTaskCritical      = 0
%eAppDomainCritical = 1
%eProcessCritical   = 2

' enum WAIT_OPTION
%WAIT_MSGPUMP       = &H1
%WAIT_ALERTABLE     = &H2
%WAIT_NOTINDEADLOCK = &H4


' ########################################################################################
' Interface name = ICLRMemoryNotificationCallback
' IID = {CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRMemoryNotificationCallback_INTERFACE_DEFINED)
    %ICLRMemoryNotificationCallback_INTERFACE_DEFINED = 1

$IID_ICLRMemoryNotificationCallback = GUID$("{47EB8E57-0846-4546-AF76-6F42FCFC2649}")

INTERFACE ICLRMemoryNotificationCallback $IID_ICLRMemoryNotificationCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnMemoryNotification ( _                      ' VTable offset = 12
     BYVAL eMemoryAvailable AS LONG _                   ' __in EMemoryAvailable eMemoryAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRMemoryNotificationCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostMalloc
' IID = {1831991C-CC53-4A31-B218-04E910446479}
' Common Language Runtime Hosting Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostMalloc_INTERFACE_DEFINED)
    %IHostMalloc_INTERFACE_DEFINED = 1

INTERFACE IHostMalloc $IID_IHostMalloc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Alloc ( _                                     ' VTable offset = 12
     BYVAL cbSize AS DWORD _                            ' __in SIZE_T cbSize
   , BYVAL eCriticalLevel AS LONG _                     ' __in EMemoryCriticalLevel eCriticalLevel
   , BYREF ppMem AS DWORD _                             ' __out void **ppMem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DebugAlloc ( _                                ' VTable offset = 16
     BYVAL cbSize AS DWORD _                            ' __in SIZE_T cbSize
   , BYVAL eCriticalLevel AS LONG _                     ' __in EMemoryCriticalLevel eCriticalLevel
   , BYREF pszFileName AS ASCIIZ _                      ' __in char *pszFileName
   , BYVAL iLineNo AS LONG _                            ' __in int iLineNo
   , BYREF ppMem AS DWORD _                             ' __out void **ppMem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 20
     BYVAL pMem AS DWORD _                              ' __in void *pMem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostMalloc_INTERFACE_DEFINED__ */


' enum MALLOC_TYPE
%MALLOC_THREADSAFE = &H1
%MALLOC_EXECUTABLE = &H2


' ########################################################################################
' Interface name = IHostMemoryManager
' IID = {7BC698D1-F9E3-4460-9CDE-D04248E9FA25}
' Common Language Runtime Hosting Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostMemoryManager_INTERFACE_DEFINED)
    %IHostMemoryManager_INTERFACE_DEFINED = 1

INTERFACE IHostMemoryManager $IID_IHostMemoryManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateMalloc ( _                              ' VTable offset = 12
     BYVAL dwMallocType AS DWORD _                      ' __in DWORD dwMallocType
   , BYREF ppMalloc AS IHostMalloc _                    ' __out IHostMalloc **ppMalloc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VirtualAlloc ( _                              ' VTable offset = 16
     BYVAL pAddress AS DWORD _                          ' __in void *pAddress
   , BYVAL dwSize AS DWORD _                            ' __in SIZE_T dwSize
   , BYVAL flAllocationType AS DWORD _                  ' __in DWORD flAllocationType
   , BYVAL flProtect AS DWORD _                         ' __in DWORD flProtect
   , BYVAL eCriticalLevel AS LONG _                     ' __in EMemoryCriticalLevel eCriticalLevel
   , BYREF ppMem AS DWORD _                             ' __out void **ppMem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VirtualFree ( _                               ' VTable offset = 20
     BYVAL lpAddress AS DWORD _                         ' __in LPVOID lpAddress
   , BYREF dwSize AS DWORD _                            ' __in SIZE_T dwSize
   , BYVAL dwFreeType AS DWORD _                        ' __in DWORD dwFreeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VirtualQuery ( _                              ' VTable offset = 24
     BYVAL lpAddress AS DWORD _                         ' __in void *lpAddress
   , BYREF lpBuffer AS DWORD _                          ' __out void *lpBuffer
   , BYVAL dwLength AS DWORD _                          ' __in SIZE_T dwLength
   , BYREF pResult AS DWORD _                           ' __out SIZE_T *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VirtualProtect ( _                            ' VTable offset = 28
     BYVAL lpAddress AS DWORD _                         ' __in void *lpAddress
   , BYVAL dwSize AS DWORD _                            ' __in SIZE_T dwSize
   , BYVAL flNewProtect AS DWORD _                      ' __in DWORD flNewProtect
   , BYREF pflOldProtect AS DWORD _                     ' __out DWORD *pflOldProtect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemoryLoad ( _                             ' VTable offset = 32
     BYREF pMemoryLoad AS DWORD _                       ' __out DWORD *pMemoryLoad
   , BYREF pAvailableBytes AS DWORD _                   ' __out SIZE_T *pAvailableBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterMemoryNotificationCallback ( _        ' VTable offset = 36
     BYVAL pCallback AS DWORD _                         ' __in ICLRMemoryNotificationCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NeedsVirtualAddressSpace ( _                  ' VTable offset = 40
     BYVAL startAddress AS DWORD _                      ' __in LPVOID startAddress
   , BYVAL size AS DWORD _                              ' __in SIZE_T size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AcquiredVirtualAddressSpace ( _               ' VTable offset = 44
     BYVAL startAddress AS DWORD _                      ' __in LPVOID startAddress
   , BYVAL size AS DWORD _                              ' __in SIZE_T size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleasedVirtualAddressSpace ( _               ' VTable offset = 48
     BYVAL startAddress AS DWORD _                      ' __in LPVOID startAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostMemoryManager_INTERFACE_DEFINED__ */

'typedef UINT64 TASKID;
'typedef DWORD CONNID;


' ########################################################################################
' Interface name = ICLRTask
' IID = {28E66A4A-9906-4225-B231-9187C3EB8611}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRTask_INTERFACE_DEFINED)
    %ICLRTask_INTERFACE_DEFINED = 1

INTERFACE ICLRTask $IID_ICLRTask

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SwitchIn ( _                                  ' VTable offset = 12
     BYVAL threadHandle AS DWORD _                      ' __in HANDLE threadHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchOut ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemStats ( _                               ' VTable offset = 20
     BYREF memUsage AS COR_GC_THREAD_STATS _            ' __out COR_GC_THREAD_STATS *memUsage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
     BYVAL fFull AS LONG _                              ' __in BOOL fFull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExitTask ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RudeAbort ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NeedsPriorityScheduling ( _                   ' VTable offset = 40
     BYREF pbNeedsPriorityScheduling AS LONG _          ' __out BOOL *pbNeedsPriorityScheduling
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD YieldTask ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocksHeld ( _                                 ' VTable offset = 48
     BYREF pLockCount AS DWORD _                        ' __out SIZE_T *pLockCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTaskIdentifier ( _                         ' VTable offset = 52
     BYVAL asked AS QUAD _                              ' __in TASKID asked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRTask_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICLRTask2
' IID = 28E66A4A-9906-4225-B231-9187C3EB8612
' Inherited interface = ICLRTask
' ########################################################################################

#IF NOT %DEF(%ICLRTask2_INTERFACE_DEFINED)
    %ICLRTask2_INTERFACE_DEFINED = 1

INTERFACE ICLRTask2 $IID_ICLRTask2

   INHERIT IUnknown

   ' =====================================================================================
   ' ICLRTask methods
   ' =====================================================================================
   METHOD SwitchIn ( _                                  ' VTable offset = 12
     BYVAL threadHandle AS DWORD _                      ' __in HANDLE threadHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchOut ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemStats ( _                               ' VTable offset = 20
     BYREF memUsage AS COR_GC_THREAD_STATS _            ' __out COR_GC_THREAD_STATS *memUsage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
     BYVAL fFull AS LONG _                              ' __in BOOL fFull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExitTask ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RudeAbort ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NeedsPriorityScheduling ( _                   ' VTable offset = 40
     BYREF pbNeedsPriorityScheduling AS LONG _          ' __out BOOL *pbNeedsPriorityScheduling
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD YieldTask ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocksHeld ( _                                 ' VTable offset = 48
     BYREF pLockCount AS DWORD _                        ' __out SIZE_T *pLockCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTaskIdentifier ( _                         ' VTable offset = 52
     BYVAL asked AS QUAD _                              ' __in TASKID asked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICLRTask2 methods
   ' =====================================================================================
   METHOD BeginPreventAsyncAbort ( _                    ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndPreventAsyncAbort ( _                      ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRTask2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostTask
' IID = {C2275828-C4B1-4B55-82C9-92135F74DF1A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostTask_INTERFACE_DEFINED)
    %IHostTask_INTERFACE_DEFINED = 1

INTERFACE IHostTask $IID_IHostTask

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Alert ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Join ( _                                      ' VTable offset = 20
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 24
     BYVAL newPriority AS LONG _                        ' __in int newPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 28
     BYREF pPriority AS LONG _                          ' __out int *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCLRTask ( _                                ' VTable offset = 32
     BYVAL pCLRTask AS ICLRTask _                       ' __in ICLRTask *pCLRTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostTask_INTERFACE_DEFINED__ */

' enum ETaskType
%TT_DEBUGGERHELPER          = &H1
%TT_GC                      = &H2
%TT_FINALIZER               = &H4
%TT_THREADPOOL_TIMER        = &H8
%TT_THREADPOOL_GATE         = &H10
%TT_THREADPOOL_WORKER       = &H20
%TT_THREADPOOL_IOCOMPLETION = &H40
%TT_ADUNLOAD                = &H80
%TT_USER                    = &H100
%TT_THREADPOOL_WAIT         = &H200
%TT_UNKNOWN                 = &H80000000


' ########################################################################################
' Interface name = ICLRTaskManager
' IID = {4862EFBE-3AE5-44F8-8FEB-346190EE8A34}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRTaskManager_INTERFACE_DEFINED)
    %ICLRTaskManager_INTERFACE_DEFINED = 1

INTERFACE ICLRTaskManager $IID_ICLRTaskManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTask ( _                                ' VTable offset = 12
     BYREF pTask AS ICLRTask _                          ' __out ICLRTask **pTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTask ( _                            ' VTable offset = 16
     BYREF pTask AS ICLRTask _                          ' __out ICLRTask **pTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUILocale ( _                               ' VTable offset = 20
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocale ( _                                 ' VTable offset = 24
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTaskType ( _                        ' VTable offset = 28
     BYREF pTaskType AS LONG _                          ' __out ETaskType *pTaskType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRTaskManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostTaskManager
' IID = {997FF24C-43B7-4352-8667-0DC04FAFD354}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostTaskManager_INTERFACE_DEFINED)
    %IHostTaskManager_INTERFACE_DEFINED = 1

INTERFACE IHostTaskManager $IID_IHostTaskManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentTask ( _                            ' VTable offset = 12
     BYREF pTask AS IHostTask _                         ' __out IHostTask **pTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTask ( _                                ' VTable offset = 16
     BYVAL dwStackSize AS DWORD _                       ' __in DWORD dwStackSize
   , BYVAL pStartAddress AS DWORD _                     ' __in LPTHREAD_START_ROUTINE pStartAddress
   , BYVAL pParameter AS DWORD _                        ' __in PVOID pParameter
   , BYREF ppTask AS IHostTask _                        ' __out IHostTask **ppTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sleep ( _                                     ' VTable offset = 20
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SwitchToTask ( _                              ' VTable offset = 24
     BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUILocale ( _                               ' VTable offset = 28
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocale ( _                                 ' VTable offset = 32
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CallNeedsHostHook ( _                         ' VTable offset = 36
     BYVAL target AS DWORD _                            ' __in SIZE_T target
   , BYREF pbCallNeedsHostHook AS LONG _                ' __out BOOL *pbCallNeedsHostHook
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LeaveRuntime ( _                              ' VTable offset = 40
     BYVAL target AS DWORD _                            ' __in SIZE_T target
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnterRuntime ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReverseLeaveRuntime ( _                       ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReverseEnterRuntime ( _                       ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginDelayAbort ( _                           ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndDelayAbort ( _                             ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginThreadAffinity ( _                       ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndThreadAffinity ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStackGuarantee ( _                         ' VTable offset = 72
     BYVAL guarantee AS DWORD _                         ' __in ULONG guarantee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStackGuarantee ( _                         ' VTable offset = 76
     BYREF pGuarantee AS DWORD _                        ' __out ULONG *pGuarantee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCLRTaskManager ( _                         ' VTable offset = 80
     BYVAL ppManager AS ICLRTaskManager _               ' __in ICLRTaskManager *ppManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostTaskManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostThreadpoolManager
' IID = {63DF8730-DC81-4062-84A2-1FF943F59FDD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostThreadpoolManager_INTERFACE_DEFINED)
    %IHostThreadpoolManager_INTERFACE_DEFINED = 1

INTERFACE IHostThreadpoolManager $IID_IHostThreadpoolManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueueUserWorkItem ( _                         ' VTable offset = 12
     BYVAL Function AS DWORD _                          ' __in LPTHREAD_START_ROUTINE Function
   , BYVAL Context AS DWORD _                           ' __in PVOID Context
   , BYVAL Flags AS DWORD _                             ' __in ULONG Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxThreads ( _                             ' VTable offset = 16
     BYVAL dwMaxWorkerThreads AS DWORD _                ' __in DWORD dwMaxWorkerThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxThreads ( _                             ' VTable offset = 20
     BYREF pdwMaxWorkerThreads AS DWORD _               ' __out DWORD *pdwMaxWorkerThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableThreads ( _                       ' VTable offset = 24
     BYREF pdwAvailableWorkerThreads AS DWORD _         ' __out DWORD *pdwAvailableWorkerThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinThreads ( _                             ' VTable offset = 28
     BYVAL dwMinIOCompletionThreads AS DWORD _          ' __in DWORD dwMinIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinThreads ( _                             ' VTable offset = 32
     BYREF pdwMinIOCompletionThreads AS DWORD _         ' __out DWORD *pdwMinIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostThreadpoolManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRIoCompletionManager
' IID = {2D74CE86-B8D6-4C84-B3A7-9768933B3C12}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRIoCompletionManager_INTERFACE_DEFINED)
    %ICLRIoCompletionManager_INTERFACE_DEFINED = 1

INTERFACE ICLRIoCompletionManager $IID_ICLRIoCompletionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnComplete ( _                                ' VTable offset = 12
     BYVAL dwErrorCode AS DWORD _                       ' __in DWORD dwErrorCode
   , BYVAL NumberOfBytesTransferred AS DWORD _          ' __in DWORD NumberOfBytesTransferred
   , BYVAL pvOverlapped AS DWORD _                      ' __in void *pvOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRIoCompletionManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostIoCompletionManager
' IID = {8BDE9D80-EC06-41D6-83E6-22580EFFCC20}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostIoCompletionManager_INTERFACE_DEFINED)
    %IHostIoCompletionManager_INTERFACE_DEFINED = 1

INTERFACE IHostIoCompletionManager $IID_IHostIoCompletionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateIoCompletionPort ( _                    ' VTable offset = 12
     BYREF phPort AS DWORD _                            ' __out HANDLE *phPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseIoCompletionPort ( _                     ' VTable offset = 16
     BYVAL hPort AS DWORD _                             ' __in HANDLE hPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxThreads ( _                             ' VTable offset = 20
     BYVAL dwMaxIOCompletionThreads AS DWORD _          ' __in DWORD dwMaxIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxThreads ( _                             ' VTable offset = 24
     BYREF dwMaxIOCompletionThreads AS DWORD _          ' __in DWORD dwMaxIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableThreads ( _                       ' VTable offset = 28
     BYREF pdwAvailableIOCompletionThreads AS DWORD _   ' __out DWORD *pdwAvailableIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHostOverlappedSize ( _                     ' VTable offset = 32
     BYREF pcbSize AS DWORD _                           ' __out DWORD *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCLRIoCompletionManager ( _                 ' VTable offset = 36
     BYVAL pManager AS ICLRIoCompletionManager _        ' __in ICLRIoCompletionManager *pManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeHostOverlapped ( _                  ' VTable offset = 40
     BYVAL pvOverlapped AS DWORD _                      ' __in void *pvOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Bind ( _                                      ' VTable offset = 44
     BYVAL hPort AS DWORD _                             ' __in HANDLE hPort
   , BYVAL hHandle AS DWORD _                           ' __in HANDLE hHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinThreads ( _                             ' VTable offset = 48
     BYVAL dwMinIOCompletionThreads AS DWORD _          ' __in DWORD dwMinIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinThreads ( _                             ' VTable offset = 52
     BYREF pdwMinIOCompletionThreads AS DWORD _         ' __out DWORD *pdwMinIOCompletionThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostIoCompletionManager_INTERFACE_DEFINED__ */

' enum ESymbolReadingPolicy
%eSymbolReadingNever         = 0
%eSymbolReadingAlways        = 1
%eSymbolReadingFullTrustOnly = 2


' ########################################################################################
' Interface name = ICLRDebugManager
' IID = {00DCAEC6-2AC0-43A9-ACF9-1E36C139B10D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRDebugManager_INTERFACE_DEFINED)
    %ICLRDebugManager_INTERFACE_DEFINED = 1

INTERFACE ICLRDebugManager $IID_ICLRDebugManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginConnection ( _                           ' VTable offset = 12
     BYVAL dwConnectionId AS DWORD _                    ' __in CONNID dwConnectionId
   , BYREF szConnectionName AS WSTRINGZ _               ' __in wchar_t *szConnectionName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConnectionTasks ( _                        ' VTable offset = 16
     BYVAL id AS DWORD _                                ' __in CONNID id
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYREF ppCLRTask AS ICLRTask _                      ' __in ICLRTask **ppCLRTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndConnection ( _                             ' VTable offset = 20
     BYVAL dwConnectionId AS DWORD _                    ' __in CONNID dwConnectionId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDacl ( _                                   ' VTable offset = 24
     BYVAL pacl AS ACL PTR _                            ' __in PACL pacl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDacl ( _                                   ' VTable offset = 28
     BYREF pacl AS DWORD _                              ' __out PACL *pacl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDebuggerAttached ( _                        ' VTable offset = 32
     BYREF pbAttached AS LONG _                         ' __out BOOL *pbAttached
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSymbolReadingPolicy ( _                    ' VTable offset = 36
     BYVAL policy AS LONG _                             ' __in ESymbolReadingPolicy policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRDebugManager_INTERFACE_DEFINED__ */

' enum ECustomDumpFlavor
%DUMP_FLAVOR_Mini             = 0
%DUMP_FLAVOR_CriticalCLRState = 1
%DUMP_FLAVOR_NonHeapCLRState  = 2
%DUMP_FLAVOR_Default          = %DUMP_FLAVOR_Mini

' enum ECustomDumpItemKind
%DUMP_ITEM_None   = 0

'typedef /* [public] */ struct __MIDL___MIDL_itf_MSCOREE_0144_0003
'    {
'    ECustomDumpItemKind itemKind;
'    union
'        {
'        UINT_PTR pReserved;
'        }    ;
'    }    CustomDumpItem;

' // Size = 4 bytes
UNION CustomDumpItem_UNION DWORD
   pReserved AS DWORD
END UNION

' // Size = 8 bytes
TYPE CustomDumpItem DWORD
   itemKind AS LONG   ' ECustomDumpItemKind
   CustomDumpItem_UNION
END TYPE

'typedef struct _BucketParameters
'    {
'    BOOL fInited;
'    WCHAR pszEventTypeName[ 255 ];
'    WCHAR pszParams[ 10 ][ 255 ];
'    }    BucketParameters;

' // Size = 5616 bytes
TYPE BucketParameters DWORD
   fInited          AS LONG             ' BOOL
   pszEventTypeName AS WSTRINGZ * 255   ' WCHAR
   pszParams(9)     AS WSTRINGZ * 255   ' WCHAR[ 10 ][ 255 ];
END TYPE


' ########################################################################################
' Interface name = ICLRErrorReportingManager
' IID = {980D2F1A-BF79-4C08-812A-BB9778928F78}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRErrorReportingManager_INTERFACE_DEFINED)
    %ICLRErrorReportingManager_INTERFACE_DEFINED = 1

INTERFACE ICLRErrorReportingManager $IID_ICLRErrorReportingManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBucketParametersForCurrentException ( _    ' VTable offset = 12
     BYREF pParams AS BucketParameters _                ' __out BucketParameters *pParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginCustomDump ( _                           ' VTable offset = 16
     BYVAL dwFlavor AS DWORD _                          ' __in ECustomDumpFlavor dwFlavor
   , BYVAL dwNumItems AS DWORD _                        ' __in DWORD dwNumItems
   , BYREF items AS CustomDumpItem _                    ' __in CustomDumpItem *items
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndCustomDump ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRErrorReportingManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostCrst
' IID = {6DF710A6-26A4-4A65-8CD5-7237B8BDA8DC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostCrst_INTERFACE_DEFINED)
    %IHostCrst_INTERFACE_DEFINED = 1

INTERFACE IHostCrst $IID_IHostCrst

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Enter ( _                                     ' VTable offset = 12
     BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Leave ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TryEnter ( _                                  ' VTable offset = 20
     BYVAL option AS DWORD _                            ' __in DWORD option
   , BYREF pbSucceeded AS LONG _                        ' __out BOOL *pbSucceeded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpinCount ( _                              ' VTable offset = 24
     BYVAL dwSpinCount AS DWORD _                       ' __in DWORD dwSpinCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostCrst_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostAutoEvent
' IID = {B18E0B40-C089-4350-8328-066C668BCCC2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostAutoEvent_INTERFACE_DEFINED)
    %IHostAutoEvent_INTERFACE_DEFINED = 1

INTERFACE IHostAutoEvent $IID_IHostAutoEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 12
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostAutoEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostManualEvent
' IID = {1BF4EC38-AFFE-4FB9-85A6-525268F15B54}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostManualEvent_INTERFACE_DEFINED)
    %IHostManualEvent_INTERFACE_DEFINED = 1

INTERFACE IHostManualEvent $IID_IHostManualEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 12
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostManualEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostSemaphore
' IID = {855EFD47-CC09-463A-A97D-16ACAB882661}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostSemaphore_INTERFACE_DEFINED)
    %IHostSemaphore_INTERFACE_DEFINED = 1

INTERFACE IHostSemaphore $IID_IHostSemaphore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Wait ( _                                      ' VTable offset = 12
     BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL option AS DWORD _                            ' __in DWORD option
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseSemaphore ( _                          ' VTable offset = 16
     BYVAL lReleaseCount AS LONG _                      ' __in LONG lReleaseCount
   , BYREF lpPreviousCount AS LONG _                    ' __out LONG *lpPreviousCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostSemaphore_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRSyncManager
' IID = {55FF199D-AD21-48F9-A16C-F24EBBB8727D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRSyncManager_INTERFACE_DEFINED)
    %ICLRSyncManager_INTERFACE_DEFINED = 1

INTERFACE ICLRSyncManager $IID_ICLRSyncManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMonitorOwner ( _                           ' VTable offset = 12
     BYVAL Cookie AS DWORD _                            ' __in SIZE_T Cookie
   , BYREF ppOwnerHostTask AS IHostTask _               ' __out IHostTask **ppOwnerHostTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRWLockOwnerIterator ( _                 ' VTable offset = 16
     BYVAL Cookie AS DWORD _                            ' __in SIZE_T Cookie
   , BYREF pIterator AS DWORD _                         ' __out SIZE_T *pIterator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRWLockOwnerNext ( _                        ' VTable offset = 20
     BYVAL Iterator AS DWORD _                          ' __in SIZE_T Iterator
   , BYREF ppOwnerHostTask AS IHostTask _               ' __out IHostTask **ppOwnerHostTask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteRWLockOwnerIterator ( _                 ' VTable offset = 24
     BYVAL Iterator AS DWORD _                          ' __in SIZE_T Iterator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRSyncManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostSyncManager
' IID = {234330C7-5F10-4F20-9615-5122DAB7A0AC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostSyncManager_INTERFACE_DEFINED)
    %IHostSyncManager_INTERFACE_DEFINED = 1

INTERFACE IHostSyncManager $IID_IHostSyncManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCLRSyncManager ( _                         ' VTable offset = 12
     BYVAL pManager AS ICLRSyncManager _                ' __in ICLRSyncManager *pManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCrst ( _                                ' VTable offset = 16
     BYREF ppCrst AS IHostCrst _                        ' __out IHostCrst **ppCrst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCrstWithSpinCount ( _                   ' VTable offset = 20
     BYVAL dwSpinCount AS DWORD _                       ' __in DWORD dwSpinCount
   , BYREF ppCrst AS IHostCrst _                        ' __out IHostCrst **ppCrst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAutoEvent ( _                           ' VTable offset = 24
     BYREF ppEvent AS IHostAutoEvent _                  ' __out IHostAutoEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateManualEvent ( _                         ' VTable offset = 28
     BYVAL bInitialState AS LONG _                      ' __in BOOL bInitialState
   , BYREF ppEvent AS IHostManualEvent _                ' __out IHostManualEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMonitorEvent ( _                        ' VTable offset = 32
     BYVAL Cookie AS DWORD _                            ' __in SIZE_T Cookie
   , BYREF ppEvent AS IHostAutoEvent _                  ' __out IHostAutoEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRWLockWriterEvent ( _                   ' VTable offset = 36
     BYVAL Cookie AS DWORD _                            ' __in SIZE_T Cookie
   , BYREF ppEvent AS IHostAutoEvent _                  ' __out IHostAutoEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRWLockReaderEvent ( _                   ' VTable offset = 40
     BYVAL bInitialState AS LONG _                      ' __in BOOL bInitialState
   , BYVAL Cookie AS DWORD _                            ' __in SIZE_T Cookie
   , BYREF ppEvent AS IHostManualEvent _                ' __out IHostManualEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSemaphore ( _                           ' VTable offset = 44
     BYVAL dwInitial AS DWORD _                         ' __in DWORD dwInitial
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   , BYREF ppSemaphore AS IHostSemaphore _              ' __out IHostSemaphore **ppSemaphore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostSyncManager_INTERFACE_DEFINED__ */


' enum EClrOperation
%OPR_ThreadAbort                        = 0
%OPR_ThreadRudeAbortInNonCriticalRegion = %OPR_ThreadAbort                        + 1
%OPR_ThreadRudeAbortInCriticalRegion    = %OPR_ThreadRudeAbortInNonCriticalRegion + 1
%OPR_AppDomainUnload                    = %OPR_ThreadRudeAbortInCriticalRegion    + 1
%OPR_AppDomainRudeUnload                = %OPR_AppDomainUnload                    + 1
%OPR_ProcessExit                        = %OPR_AppDomainRudeUnload                + 1
%OPR_FinalizerRun                       = %OPR_ProcessExit                        + 1
%MaxClrOperation                        = %OPR_FinalizerRun                       + 1

' enum EClrFailure
%FAIL_NonCriticalResource = 0
%FAIL_CriticalResource    = %FAIL_NonCriticalResource + 1
%FAIL_FatalRuntime        = %FAIL_CriticalResource    + 1
%FAIL_OrphanedLock        = %FAIL_FatalRuntime        + 1
%FAIL_StackOverflow       = %FAIL_OrphanedLock        + 1
%FAIL_AccessViolation     = %FAIL_StackOverflow       + 1
%FAIL_CodeContract        = %FAIL_AccessViolation     + 1
%MaxClrFailure            = %FAIL_CodeContract        + 1

' enum EClrUnhandledException
%eRuntimeDeterminedPolicy = 0
%eHostDeterminedPolicy    = %eRuntimeDeterminedPolicy + 1

' enum EPolicyAction
%eNoAction            = 0
%eThrowException      = %eNoAction            + 1
%eAbortThread         = %eThrowException      + 1
%eRudeAbortThread     = %eAbortThread         + 1
%eUnloadAppDomain     = %eRudeAbortThread     + 1
%eRudeUnloadAppDomain = %eUnloadAppDomain     + 1
%eExitProcess         = %eRudeUnloadAppDomain + 1
%eFastExitProcess     = %eExitProcess         + 1
%eRudeExitProcess     = %eFastExitProcess     + 1
%eDisableRuntime      = %eRudeExitProcess     + 1
%MaxPolicyAction      = %eDisableRuntime      + 1


' ########################################################################################
' Interface name = ICLRPolicyManager
' IID = {7D290010-D781-45DA-A6F8-AA5D711A730E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRPolicyManager_INTERFACE_DEFINED)
    %ICLRPolicyManager_INTERFACE_DEFINED = 1

INTERFACE ICLRPolicyManager $IID_ICLRPolicyManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDefaultAction ( _                          ' VTable offset = 12
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeout ( _                                ' VTable offset = 16
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionOnTimeout ( _                        ' VTable offset = 20
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeoutAndAction ( _                       ' VTable offset = 24
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionOnFailure ( _                        ' VTable offset = 28
     BYVAL failure AS LONG _                            ' __in EClrFailure failure
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnhandledExceptionPolicy ( _               ' VTable offset = 32
     BYVAL policy AS LONG _                             ' __in EClrUnhandledException policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRPolicyManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostPolicyManager
' IID = {7AE49844-B1E3-4683-BA7C-1E8212EA3B79}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostPolicyManager_INTERFACE_DEFINED)
    %IHostPolicyManager_INTERFACE_DEFINED = 1

INTERFACE IHostPolicyManager $IID_IHostPolicyManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDefaultAction ( _                           ' VTable offset = 12
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTimeout ( _                                 ' VTable offset = 16
     BYVAL operation AS LONG _                          ' __in EClrOperation operation
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFailure ( _                                 ' VTable offset = 20
     BYVAL failure AS LONG _                            ' __in EClrOperation failure
   , BYVAL action AS LONG _                             ' __in EPolicyAction action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostPolicyManager_INTERFACE_DEFINED__ */


' enum EClrEvent
%Event_DomainUnload  = 0
%Event_ClrDisabled   = %Event_DomainUnload  + 1
%Event_MDAFired      = %Event_ClrDisabled   + 1
%Event_StackOverflow = %Event_MDAFired      + 1
%MaxClrEvent         = %Event_StackOverflow + 1

' // Size = 12 bytes
TYPE MDAInfo DWORD
   lpMDACaption AS WSTRINGZ PTR   ' LPCWSTR
   lpMDAMessage AS WSTRINGZ PTR   ' LPCWSTR
   lpStackTrace AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' enum StackOverflowType
%SO_Managed   = 0
%SO_ClrEngine = %SO_Managed   + 1
%SO_Other     = %SO_ClrEngine + 1

' // Size = 8 bytes
TYPE StackOverflowInfo DWORD
   soType         AS LONG                     ' StackOverflowType
   pExceptionInfo AS EXCEPTION_POINTERS PTR   ' EXCEPTION_POINTERS *
END TYPE


' ########################################################################################
' Interface name = IActionOnCLREvent
' IID = {607BE24B-D91B-4E28-A242-61871CE56E35}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActionOnCLREvent_INTERFACE_DEFINED)
    %IActionOnCLREvent_INTERFACE_DEFINED = 1

INTERFACE IActionOnCLREvent $IID_IActionOnCLREvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
     BYVAL event AS LONG _                              ' __in EClrEvent event
   , BYVAL data AS DWORD _                              ' __in PVOID data
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActionOnCLREvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLROnEventManager
' IID = {1D0E0132-E64F-493D-9260-025C0E32C175}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLROnEventManager_INTERFACE_DEFINED)
    %ICLROnEventManager_INTERFACE_DEFINED = 1

INTERFACE ICLROnEventManager $IID_ICLROnEventManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterActionOnEvent ( _                     ' VTable offset = 12
     BYVAL event AS LONG _                              ' __in EClrEvent event
   , BYVAL pAction AS IActionOnCLREvent _               ' __in IActionOnCLREvent *pAction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLROnEventManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostGCManager
' IID = {5D4EC34E-F248-457B-B603-255FAABA0D21}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostGCManager_INTERFACE_DEFINED)
    %IHostGCManager_INTERFACE_DEFINED = 1

INTERFACE IHostGCManager $IID_IHostGCManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadIsBlockingForSuspension ( _             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SuspensionStarting ( _                        ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SuspensionEnding ( _                          ' VTable offset = 20
     BYVAL Generation AS DWORD _                        ' __in DWORD Generation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostGCManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRGCManager
' IID = {54D9007E-A8E2-4885-B7BF-F998DEEE4F2A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRGCManager_INTERFACE_DEFINED)
    %ICLRGCManager_INTERFACE_DEFINED = 1

INTERFACE ICLRGCManager $IID_ICLRGCManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Collect ( _                                   ' VTable offset = 12
     BYVAL Generation AS LONG _                         ' __in LONG Generation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStats ( _                                  ' VTable offset = 16
     BYREF pStats AS COR_GC_STATS _                     ' __inout COR_GC_STATS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGCStartupLimits ( _                        ' VTable offset = 20
     BYVAL SegmentSize AS DWORD _                       ' __in DWORD SegmentSize
   , BYVAL MaxGen0Size AS DWORD _                       ' __in DWORD MaxGen0Size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRGCManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRAssemblyReferenceList
' IID = {1B2C9750-2E66-4BDA-8B44-0A642C5CD733}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRAssemblyReferenceList_INTERFACE_DEFINED)
    %ICLRAssemblyReferenceList_INTERFACE_DEFINED = 1

INTERFACE ICLRAssemblyReferenceList $IID_ICLRAssemblyReferenceList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsStringAssemblyReferenceInList ( _           ' VTable offset = 12
     BYREF pwzAssemblyName AS WSTRINGZ _                ' __in LPCWSTR pwzAssemblyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAssemblyReferenceInList ( _                 ' VTable offset = 16
     BYVAL pName AS IUnknown _                          ' __in IUnknown *pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRAssemblyReferenceList_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRReferenceAssemblyEnum
' IID = {D509CB5D-CF32-4876-AE61-67770CF91973}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRReferenceAssemblyEnum_INTERFACE_DEFINED)
    %ICLRReferenceAssemblyEnum_INTERFACE_DEFINED = 1

INTERFACE ICLRReferenceAssemblyEnum $IID_ICLRReferenceAssemblyEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 12
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBufferSize AS DWORD _                    ' __inout DWORD *pcchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRReferenceAssemblyEnum_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRProbingAssemblyEnum
' IID = {D0C5FB1F-416B-4F97-81F4-7AC7DC24DD5D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRProbingAssemblyEnum_INTERFACE_DEFINED)
    %ICLRProbingAssemblyEnum_INTERFACE_DEFINED = 1

INTERFACE ICLRProbingAssemblyEnum $IID_ICLRProbingAssemblyEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 12
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBufferSize AS DWORD _                    ' __inout DWORD *pcchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRProbingAssemblyEnum_INTERFACE_DEFINED__ */

' enum CLRAssemblyIdentityFlags
%CLR_ASSEMBLY_IDENTITY_FLAGS_DEFAULT = 0


' ########################################################################################
' Interface name = ICLRAssemblyIdentityManager
' IID = {15F0A9DA-3FF6-4393-9DA9-FDFD284E6972}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRAssemblyIdentityManager_INTERFACE_DEFINED)
    %ICLRAssemblyIdentityManager_INTERFACE_DEFINED = 1

INTERFACE ICLRAssemblyIdentityManager $IID_ICLRAssemblyIdentityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCLRAssemblyReferenceList ( _               ' VTable offset = 12
     BYREF ppwzAssemblyReferences AS WSTRINGZ _         ' __in LPCWSTR *ppwzAssemblyReferences
   , BYVAL dwNumOfReferences AS DWORD _                 ' __in DWORD dwNumOfReferences
   , BYREF ppReferenceList AS ICLRAssemblyReferenceList _ ' __out ICLRAssemblyReferenceList **ppReferenceList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindingIdentityFromFile ( _                ' VTable offset = 16
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBufferSize AS DWORD _                    ' __inout DWORD *pcchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindingIdentityFromStream ( _              ' VTable offset = 20
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYVAL pcchBufferSize AS DWORD _                    ' __inout DWORD *pcchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferencedAssembliesFromFile ( _           ' VTable offset = 24
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pExcludeAssembliesList AS ICLRAssemblyReferenceList _ ' __in ICLRAssemblyReferenceList *pExcludeAssembliesList
   , BYREF ppReferenceEnum AS ICLRReferenceAssemblyEnum _ ' __out ICLRReferenceAssemblyEnum **ppReferenceEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferencedAssembliesFromStream ( _         ' VTable offset = 28
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pExcludeAssembliesList AS ICLRAssemblyReferenceList _ ' __in ICLRAssemblyReferenceList *pExcludeAssembliesList
   , BYREF ppReferenceEnum AS ICLRReferenceAssemblyEnum _ ' __out ICLRReferenceAssemblyEnum **ppReferenceEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProbingAssembliesFromReference ( _         ' VTable offset = 32
     BYVAL dwMachineType AS DWORD _                     ' __in DWORD dwMachineType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pwzReferenceIdentity AS WSTRINGZ _           ' __in LPCWSTR pwzReferenceIdentity
   , BYREF ppProbingAssemblyEnum AS ICLRProbingAssemblyEnum _ ' __out ICLRProbingAssemblyEnum **ppProbingAssemblyEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsStronglyNamed ( _                           ' VTable offset = 36
     BYREF pwzAssemblyIdentity AS WSTRINGZ _            ' __in LPCWSTR pwzAssemblyIdentity
   , BYREF pbIsStronglyNamed AS LONG _                  ' __out BOOL *pbIsStronglyNamed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRAssemblyIdentityManager_INTERFACE_DEFINED__ */

' enum EHostBindingPolicyModifyFlags
%HOST_BINDING_POLICY_MODIFY_DEFAULT = 0
%HOST_BINDING_POLICY_MODIFY_CHAIN   = 1
%HOST_BINDING_POLICY_MODIFY_REMOVE  = 2
%HOST_BINDING_POLICY_MODIFY_MAX     = 3


' ########################################################################################
' Interface name = ICLRHostBindingPolicyManager
' IID = {4B3545E7-1856-48C9-A8BA-24B21A753C09}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRHostBindingPolicyManager_INTERFACE_DEFINED)
    %ICLRHostBindingPolicyManager_INTERFACE_DEFINED = 1

INTERFACE ICLRHostBindingPolicyManager $IID_ICLRHostBindingPolicyManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ModifyApplicationPolicy ( _                   ' VTable offset = 12
     BYREF pwzSourceAssemblyIdentity AS WSTRINGZ _      ' __in LPCWSTR pwzSourceAssemblyIdentity
   , BYREF pwzTargetAssemblyIdentity AS WSTRINGZ _      ' __in LPCWSTR pwzTargetAssemblyIdentity
   , BYVAL pbApplicationPolicy AS BYTE PTR _            ' __in BYTE *pbApplicationPolicy
   , BYVAL cbAppPolicySize AS DWORD _                   ' __in DWORD cbAppPolicySize
   , BYVAL dwPolicyModifyFlags AS DWORD _               ' __in DWORD dwPolicyModifyFlags
   , BYVAL pbNewApplicationPolicy AS BYTE PTR _         ' __out BYTE *pbNewApplicationPolicy
   , BYREF pcbNewAppPolicySize AS DWORD _               ' __inout DWORD *pcbNewAppPolicySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EvaluatePolicy ( _                            ' VTable offset = 16
     BYREF pwzReferenceIdentity AS WSTRINGZ _           ' __in LPCWSTR pwzReferenceIdentity
   , BYVAL pbApplicationPolicy AS BYTE PTR _            ' __in BYTE *pbApplicationPolicy
   , BYVAL cbAppPolicySize AS DWORD _                   ' __in DWORD cbAppPolicySize
   , BYREF pwzPostPolicyReferenceIdentity AS WSTRINGZ _ ' __out LPWSTR pwzPostPolicyReferenceIdentity
   , BYREF pcchPostPolicyReferenceIdentity AS DWORD _   ' __inout DWORD *pcchPostPolicyReferenceIdentity
   , BYREF pdwPoliciesApplied AS DWORD _                ' __out DWORD *pdwPoliciesApplied) = 0;
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRHostBindingPolicyManager_INTERFACE_DEFINED__ */


' enum EBindPolicyLevels
%ePolicyLevelNone         = 0
%ePolicyLevelRetargetable = &H1
%ePolicyUnifiedToCLR      = &H2
%ePolicyLevelApp          = &H4
%ePolicyLevelPublisher    = &H8
%ePolicyLevelHost         = &H10
%ePolicyLevelAdmin        = &H20
%ePolicyPortability       = &H40

' // Size = 16 bytes
TYPE AssemblyBindInfo DWORD
   dwAppDomainId        AS DWORD          ' DWORD
   lpReferencedIdentity AS WSTRINGZ PTR   ' LPCWSTR
   lpPostPolicyIdentity AS WSTRINGZ PTR   ' LPCWSTR
   ePolicyLevel         AS DWORD          ' DWORD
END TYPE

' // Size = 12 bytes
TYPE ModuleBindInfo DWORD
   dwAppDomainId      AS DWORD          ' DWORD
   lpAssemblyIdentity AS WSTRINGZ PTR   ' LPCWSTR
   lpModuleName       AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' enum HostApplicationPolicy
%HOST_APPLICATION_BINDING_POLICY = 1


' ########################################################################################
' Interface name = IHostAssemblyStore
' IID = {7B102A88-3F7F-496D-8FA2-C35374E01AF3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostAssemblyStore_INTERFACE_DEFINED)
    %IHostAssemblyStore_INTERFACE_DEFINED = 1

INTERFACE IHostAssemblyStore $IID_IHostAssemblyStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProvideAssembly ( _                           ' VTable offset = 12
     BYREF pBindInfo AS AssemblyBindInfo _              ' __in AssemblyBindInfo *pBindInfo
   , BYREF pAssemblyId AS QUAD _                        ' __out UINT64 *pAssemblyId
   , BYREF pContext AS QUAD _                           ' __out UINT64 *pContext
   , BYREF ppStmAssemblyImage AS IStream _              ' __out IStream **ppStmAssemblyImage
   , BYREF ppStmPDB AS IStream _                        ' __out IStream **ppStmPDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProvideModule ( _                             ' VTable offset = 16
     BYVAL pBindInfo AS ModuleBindInfo _                ' __in ModuleBindInfo *pBindInfo
   , BYREF pdwModuleId AS DWORD _                       ' __out DWORD *pdwModuleId
   , BYREF ppStmModuleImage AS IStream _                ' __out IStream **ppStmModuleImage
   , BYREF ppStmPDB AS IStream _                        ' __out IStream **ppStmPDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostAssemblyStore_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHostAssemblyManager
' IID = {613DABD7-62B2-493E-9E65-C1E32A1E0C5E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostAssemblyManager_INTERFACE_DEFINED)
    %IHostAssemblyManager_INTERFACE_DEFINED = 1

INTERFACE IHostAssemblyManager $IID_IHostAssemblyManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNonHostStoreAssemblies ( _                 ' VTable offset = 12
     BYREF ppReferenceList AS ICLRAssemblyReferenceList _ ' __out ICLRAssemblyReferenceList **ppReferenceList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAssemblyStore ( _                          ' VTable offset = 16
     BYREF ppAssemblyStore AS IHostAssemblyStore _      ' __out IHostAssemblyStore **ppAssemblyStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostAssemblyManager_INTERFACE_DEFINED__ */


DECLARE FUNCTION GetCLRIdentityManager IMPORT "mscoree.dll" ALIAS "GetCLRIdentityManager" ( _
   BYREF riid AS GUID _                                 ' __in  REFIID   riid
 , BYREF ppManager AS IUnknown _                        ' __out IUnknown **ppManager
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IHostControl
' IID = {02CA073C-7079-4860-880A-C2F7A449C991}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostControl_INTERFACE_DEFINED)
    %IHostControl_INTERFACE_DEFINED = 1

$IID_IHostControl = GUID$("{02CA073C-7079-4860-880A-C2F7A449C991}")

INTERFACE IHostControl $IID_IHostControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHostManager ( _                            ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObject AS IUnknown _                       ' __out void **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppDomainManager ( _                       ' VTable offset = 16
     BYVAL dwAppDomainID AS DWORD _                     ' __in DWORD dwAppDomainID
   , BYVAL pUnkAppDomainManager AS IUnknown _           ' __in IUnknown* pUnkAppDomainManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRControl
' IID = {9065597E-D1A1-4FB2-B6BA-7E1FCE230F61}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRControl_INTERFACE_DEFINED)
    %ICLRControl_INTERFACE_DEFINED = 1

$IID_ICLRControl = GUID$("{9065597E-D1A1-4FB2-B6BA-7E1FCE230F61}")

INTERFACE ICLRControl $IID_ICLRControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCLRManager ( _                             ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObject AS IUnknown _                       ' __out void **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppDomainManagerType ( _                   ' VTable offset = 16
     BYREF pwzAppDomainManagerAssembly AS WSTRINGZ _    ' __in LPCWSTR pwzAppDomainManagerAssembly
   , BYREF pwzAppDomainManagerType AS WSTRINGZ _        ' __in LPCWSTR pwzAppDomainManagerType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRRuntimeHost
' IID = {90F1A06C-7712-4762-86B5-7A5EBA6BDB02}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRRuntimeHost_INTERFACE_DEFINED)
    %ICLRRuntimeHost_INTERFACE_DEFINED = 1

INTERFACE ICLRRuntimeHost $IID_ICLRRuntimeHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHostControl ( _                            ' VTable offset = 20
     BYVAL pHostControl AS IHostControl _               ' __in IHostControl *pHostControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLRControl ( _                             ' VTable offset = 24
     BYREF pCLRControl AS ICLRControl _                 ' __out ICLRControl **pCLRControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadAppDomain ( _                           ' VTable offset = 28
     BYVAL dwAppDomainId AS DWORD _                     ' __in DWORD dwAppDomainId
   , BYVAL fWaitUntilDone AS LONG _                     ' __in BOOL fWaitUntilDone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MIDL_0010__ ( _                               ' VTable offset = 32
     BYVAL cookie AS DWORD _                            ' void* cookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecuteInAppDomain ( _                        ' VTable offset = 36
     BYVAL dwAppDomainId AS DWORD _                     ' __in DWORD dwAppDomainId
   , BYVAL FExecuteInAppDomainCallback AS DWORD _       ' __in FExecuteInAppDomainCallback pCallback
   , BYVAL cookie AS DWORD _                            ' __in void *cookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAppDomainId ( _                     ' VTable offset = 40
     BYREF pdwAppDomainId AS DWORD _                    ' __out DWORD *pdwAppDomainId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecuteApplication ( _                        ' VTable offset = 44
     BYREF pwzAppFullName AS WSTRINGZ _                 ' __in LPCWSTR pwzAppFullName
   , BYVAL dwManifestPaths AS DWORD _                   ' __in DWORD dwManifestPaths
   , BYREF ppwzManifestPaths AS DWORD _                 ' __in LPCWSTR *ppwzManifestPaths
   , BYVAL dwActivationData AS DWORD _                  ' __in DWORD dwActivationData
   , BYREF ppwzActivationData AS DWORD _                ' __in LPCWSTR *ppwzActivationData
   , BYREF pReturnValue AS LONG _                       ' __out int *pReturnValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecuteInDefaultAppDomain ( _                 ' VTable offset = 48
     BYREF pwzAssemblyPath AS WSTRINGZ _                ' __in LPCWSTR pwzAssemblyPath
   , BYREF pwzTypeName AS WSTRINGZ _                    ' __in LPCWSTR pwzTypeName
   , BYREF pwzMethodName AS WSTRINGZ _                  ' __in LPCWSTR pwzMethodName
   , BYREF pwzArgument AS WSTRINGZ _                    ' __in LPCWSTR pwzArgument
   , BYREF pReturnValue AS WSTRINGZ _                   ' __out DWORD *pReturnValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRRuntimeHost_INTERFACE_DEFINED__ */


' enum EApiCategories
%EAC_eNoChecks                 = 0
%EAC_eSynchronization          = &H1
%EAC_eSharedState              = &H2
%EAC_eExternalProcessMgmt      = &H4
%EAC_eSelfAffectingProcessMgmt = &H8
%EAC_eExternalThreading        = &H10
%EAC_eSelfAffectingThreading   = &H20
%EAC_eSecurityInfrastructure   = &H40
%EAC_eUI                       = &H80
%EAC_eMayLeakOnAbort           = &H100
%EAC_eAll                      = &H1ff


' ########################################################################################
' Interface name = ICLRHostProtectionManager
' IID = {89F25F5C-CEEF-43E1-9CFA-A68CE863AAAC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRHostProtectionManager_INTERFACE_DEFINED)
    %ICLRHostProtectionManager_INTERFACE_DEFINED = 1

INTERFACE ICLRHostProtectionManager $IID_ICLRHostProtectionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProtectedCategories ( _                    ' VTable offset = 12
     BYVAL categories AS LONG _                         ' __in EApiCategories categories
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEagerSerializeGrantSets ( _                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRHostProtectionManager_INTERFACE_DEFINED__ */

' enum EInitializeNewDomainFlags
%eInitializeNewDomainFlags_None = 0???
%eInitializeNewDomainFlags_NoSecurityChanges = &H2???

' ########################################################################################
' Interface name = ICLRDomainManager
' IID = 270D00A2-8E15-4D0B-ADEB-37BC3E47DF77
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRDomainManager_INTERFACE_DEFINED)
    %ICLRDomainManager_INTERFACE_DEFINED = 1

INTERFACE ICLRDomainManager $IID_ICLRDomainManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAppDomainManagerType ( _                   ' VTable offset = 12
     BYREF wszAppDomainManagerAssembly AS WSTRINGZ _    ' __in LPCWSTR wszAppDomainManagerAssembly
   , BYREF wszAppDomainManagerType AS WSTRINGZ _        ' __in LPCWSTR wszAppDomainManagerType
   , BYVAL dwInitializeDomainFlags AS DWORD _           ' __in EInitializeNewDomainFlags dwInitializeDomainFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertiesForDefaultAppDomain ( _          ' VTable offset = 12
     BYVAL nProperties AS DWORD _                       ' __in DWORD nProperties
   , BYREF pwszPropertyNames AS WSTRINGZ _              ' __in LPCWSTR *pwszPropertyNames
   , BYREF pwszPropertyValues AS WSTRINGZ _             ' __in LPCWSTR *pwszPropertyValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRDomainManager_INTERFACE_DEFINED__ */

#IF NOT %DEF(%MSCOREE_LIBRARY_DEFINED)
    %MSCOREE_LIBRARY_DEFINED  = 1

$LIBID_MSCOREE = GUID$("{5477469E-83B1-11D2-8B49-00A0C9B7C9C4}")

' ########################################################################################
' Interface name = ITypeName
' IID = {B81FF171-20F3-11D2-8DCC-00A0C9B00522}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeName_INTERFACE_DEFINED)
    %ITypeName_INTERFACE_DEFINED = 1

INTERFACE ITypeName $IID_ITypeName

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetNameCount ( _                              ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 16
     BYVAL count AS DWORD _                             ' __in DWORD count
   , BYREF rgbszNames AS WSTRING _                      ' __out BSTR *rgbszNames
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetTypeArgumentCount ( _                      ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetTypeArguments ( _                          ' VTable offset = 24
     BYVAL count AS DWORD _                             ' __in DWORD count
   , BYREF rgpArguments AS ITypeName _                  ' __out ITypeName **rgpArguments
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetModifierLength ( _                         ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetModifiers ( _                              ' VTable offset = 32
     BYVAL count AS DWORD _                             ' __in DWORD count
   , BYREF rgModifiers AS DWORD _                       ' __out DWORD *rgModifiers
   ) AS DWORD                                           ' __retval_out DWORD *pCount
   ' =====================================================================================
   METHOD GetAssemblyName ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *rgbszAssemblyNames
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeName_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITypeNameBuilder
' IID = {B81FF171-20F3-11D2-8DCC-00A0C9B00523}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeNameBuilder_INTERFACE_DEFINED)
    %ITypeNameBuilder_INTERFACE_DEFINED = 1

INTERFACE ITypeNameBuilder $IID_ITypeNameBuilder

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OpenGenericArguments ( _                      ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseGenericArguments ( _                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenGenericArgument ( _                       ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD CloseGenericArgument ( _                      ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD AddName ( _                                   ' VTable offset = 28
     BYREF szName AS WSTRINGZ _                         ' __in LPCWSTR szName
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPointer ( _                                ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD AddByRef ( _                                  ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSzArray ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD AddArray ( _                                  ' VTable offset = 44
     BYVAL rank AS DWORD _                              ' __in DWORD rank
   )                                                    ' void
   ' =====================================================================================
   METHOD AddAssemblySpec ( _                           ' VTable offset = 48
     BYREF szAssemblySpec AS WSTRINGZ _                 ' __in LPCWSTR szAssemblySpec
   )                                                    ' void
   ' =====================================================================================
   METHOD ToString ( _                                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pszStringRepresentation
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeNameBuilder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITypeNameFactory
' IID = {B81FF171-20F3-11D2-8DCC-00A0C9B00521}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeNameFactory_INTERFACE_DEFINED)
    %ITypeNameFactory_INTERFACE_DEFINED = 1

INTERFACE ITypeNameFactory $IID_ITypeNameFactory

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ParseTypeName ( _                             ' VTable offset = 12
     BYREF szName AS WSTRINGZ _                         ' __in LPCWSTR szName
   , BYREF pError AS DWORD _                            ' __out DWORD *pError
   ) AS ITypeName                                       ' __retval_out ITypeName **ppTypeName
   ' =====================================================================================
   METHOD GetTypeNameBuilder ( _                        ' VTable offset = 16
   ) AS ITypeNameBuilder                                ' __retval_out ITypeNameBuilder **ppTypeBuilder
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeNameFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IApartmentCallback
' IID = {178E5337-1528-4591-B1C9-1C6E484686D8}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApartmentCallback_INTERFACE_DEFINED)
    %IApartmentCallback_INTERFACE_DEFINED = 1

INTERFACE IApartmentCallback $IID_IApartmentCallback

   INHERIT IAutomation

   ' =====================================================================================
   METHOD DoCallback ( _                                ' VTable offset = 12
     BYVAL pFunc AS DWORD _                             ' __in SIZE_T pFunc
   , BYVAL pData AS DWORD _                             ' __in SIZE_T pData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApartmentCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IManagedObject
' IID = {C3FCC19E-A970-11D2-8B5A-00A0C9B7C9C4}
' Attributes = 256 [&H100] [Oleautomation]
' ########################################################################################

#IF NOT %DEF(%IManagedObject_INTERFACE_DEFINED)
    %IManagedObject_INTERFACE_DEFINED = 1

INTERFACE IManagedObject $IID_IManagedObject

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSerializedBuffer ( _                       ' VTable offset = 12
     BYREF pBSTR AS WSTRING _                           ' __out BSTR *pBSTR
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectIdentity ( _                         ' VTable offset = 16
     BYREF pBSTRGUID AS WSTRING _                       ' __out BSTR *pBSTRGUID
   , BYREF AppDomainID AS LONG _                        ' __out int *AppDomainID
   , BYREF pCCW AS LONG _                               ' __out int *pCCW
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManagedObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICatalogServices
' IID = {04C6BE1E-1DB1-4058-AB7A-700CCCFBF254}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICatalogServices_INTERFACE_DEFINED)
    %ICatalogServices_INTERFACE_DEFINED = 1

INTERFACE ICatalogServices $IID_ICatalogServices

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Autodone ( _                                  ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD NotAutodone ( _                               ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICatalogServices_INTERFACE_DEFINED__ */

#ENDIF   ' /* __MSCOREE_LIBRARY_DEFINED__ */

' enum EContextType
%EContextType_eCurrentContext    = 0
%EContextType_eRestrictedContext = &H1


' ########################################################################################
' Interface name = IHostSecurityContext
' IID = {7E573CE4-0343-4423-98D7-6318348A1D3C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostSecurityContext_INTERFACE_DEFINED)
    %IHostSecurityContext_INTERFACE_DEFINED = 1

INTERFACE IHostSecurityContext $IID_IHostSecurityContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Capture ( _                                   ' VTable offset = 12
     BYREF ppClonedContext AS IHostSecurityContext _    ' __out IHostSecurityContext **ppClonedContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostSecurityContext_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICLRControl
' IID = {9065597E-D1A1-4FB2-B6BA-7E1FCE230F61}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHostSecurityManager_INTERFACE_DEFINED)
    %IHostSecurityManager_INTERFACE_DEFINED = 1


INTERFACE IHostSecurityManager $IID_IHostSecurityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ImpersonateLoggedOnUser ( _                   ' VTable offset = 12
     BYVAL hToken AS DWORD _                            ' __in HANDLE hToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevertToSelf ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenThreadToken ( _                           ' VTable offset = 20
     BYVAL dwDesiredAccess AS DWORD _                   ' __in DWORD dwDesiredAccess
   , BYVAL bOpenAsSelf AS LONG _                        ' __in BOOL bOpenAsSelf
   , BYREF phThreadToken AS DWORD _                     ' __out HANDLE *phThreadToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThreadToken ( _                            ' VTable offset = 24
     BYVAL hToken AS DWORD _                            ' __in HANDLE hToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityContext ( _                        ' VTable offset = 28
     BYVAL eContextType AS LONG _                       ' __in EContextType eContextType
   , BYREF ppSecurityContext AS IHostSecurityContext _  ' __out IHostSecurityContext **ppSecurityContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSecurityContext ( _                        ' VTable offset = 32
     BYVAL eContextType AS LONG _                       ' __in EContextType eContextType
   , BYVAL pSecurityContext AS IHostSecurityContext _   ' __in IHostSecurityContext *pSecurityContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHostSecurityManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICLRAppDomainResourceMonitor
' IID = C62DE18C-2E23-4AEA-8423-B40C1FC59EAE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRAppDomainResourceMonitor_INTERFACE_DEFINED)
    %ICLRAppDomainResourceMonitor_INTERFACE_DEFINED = 1

INTERFACE ICLRAppDomainResourceMonitor $IID_ICLRAppDomainResourceMonitor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentAllocated ( _                       ' VTable offset = 12
     BYVAL dwAppDomainId AS DWORD _                     ' __in DWORD dwAppDomainId
   , BYREF pBytesAllocated AS QUAD _                    ' __out ULONGLONG *pBytesAllocated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSurvived ( _                        ' VTable offset = 16
     BYVAL dwAppDomainId AS DWORD _                     ' __in DWORD dwAppDomainId
   , BYREF pAppDomainBytesSurvived AS QUAD _            ' __out ULONGLONG *pAppDomainBytesSurvived
   , BYREF pTotalBytesSurvived AS QUAD _                ' __out ULONGLONG *pTotalBytesSurvived
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentCpuTime ( _                         ' VTable offset = 20
     BYVAL dwAppDomainId AS DWORD _                     ' __in DWORD dwAppDomainId
   , BYREF pMilliseconds AS QUAD _                      ' __out ULONGLONG *pMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRAppDomainResourceMonitor_INTERFACE_DEFINED__ */


' ########################################################################################
' *** Not included in mscoree.h ***
' ########################################################################################

$IID_ICorSvcBindToWorker = GUID$("{5C6FB596-4828-4ED5-B9DD-293DAD736FB5}")
$IID_ICorSvcDependencies = GUID$("{DDB34005-9BA3-4025-9554-F00A2DF5DBF5}")
$IID_ICorSvcLogger = GUID$("{D189FF1A-E266-4F13-9637-4B9522279FFC}")
$IID_ICorSvcRepository = GUID$("{D5346658-B5FD-4353-9647-07AD4783D5A0}")
$IID_ICorSvcSetPrivateAttributes = GUID$("{B18E0B40-C089-4350-8328-066C668BCCC2}")
$IID_ICorSvcWorker = GUID$("{D1047BC2-67C0-400C-A94C-E64446A67FBE}")
$IID_ICorSvcWorker2 = GUID$("{F3358A7D-0061-4776-880E-A2F21B9EF93E}")
$IID_ICorSvcPooledWorker = GUID$("{0631E7E2-6046-4FDE-8B6D-A09B64FDA6F3}")

' ########################################################################################
' Interface name = ICorSvcDependencies
' IID = {DDB34005-9BA3-4025-9554-F00A2DF5DBF5}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcDependencies_INTERFACE_DEFINED)
    %ICorSvcDependencies_INTERFACE_DEFINED = 1

INTERFACE ICorSvcDependencies $IID_ICorSvcDependencies

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetAssemblyDependencies ( _                   ' VTable offset = 12
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYREF pDependencies AS DWORD _                     ' __out SAFEARRAY(BSTR)* pDependencies
   , BYREF assemblyNGenSetting AS DWORD _               ' __out DWORD* assemblyNGenSetting
   , BYREF pNativeImageIdentity AS WSTRING _            ' __out BSTR* pNativeImageIdentity
   , BYREF pAssemblyDisplayName AS WSTRING _            ' __out BSTR* pAssemblyDisplayName
   , BYREF pDependencyLoadSetting AS DWORD _            ' __out SAFEARRAY(DWORD)* pDependencyLoadSetting
   , BYREF pDependencyNGenSetting AS DWORD _            ' __out SAFEARRAY(DWORD)* pDependencyNGenSetting
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcDependencies_INTERFACE_DEFINED__ */

' ========================================================================================
' OptimizationScenario enum
' ========================================================================================

%OptimizationScenario_ScenarioDefault                   = 0
%OptimizationScenario_ScenarioAll                       = 1
%OptimizationScenario_ScenarioDebug                     = 2
%OptimizationScenario_ScenarioProfile                   = 8
%OptimizationScenario_ScenarioTuningDataCollection      = 16
%OptimizationScenario_ScenarioLegacy                    = 32

' ========================================================================================
' PrivateOptimizationScenario enum
' ========================================================================================

%PrivateOptimizationScenario_ScenarioEmitFixups         = &H00010000
%PrivateOptimizationScenario_ScenarioProfileInfo        = &H00020000

' ========================================================================================
' _SvcWorkerPriority structure
' ========================================================================================

' // Size = 4 bytes
TYPE SvcWorkerPriority DWORD
   dwPriorityClass AS DWORD   ' DWORD
END TYPE

' ########################################################################################
' Interface name = ICorSvcWorker
' IID = {D1047BC2-67C0-400C-A94C-E64446A67FBE}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcWorker_INTERFACE_DEFINED)
    %ICorSvcWorker_INTERFACE_DEFINED = 1

INTERFACE ICorSvcWorker $IID_ICorSvcWorker

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 12
     BYVAL priority AS SvcWorkerPriority _              ' __in SvcWorkerPriority priority
   )                                                    ' void
   ' =====================================================================================
   METHOD OptimizeAssembly ( _                          ' VTable offset = 16
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   , BYVAL scenario AS LONG _                           ' __in OptimizationScenario scenario
   , BYVAL loadAlwaysList AS DWORD _                    ' __in SAFEARRAY(BSTR) loadAlwaysList
   , BYVAL loadSometimesList AS DWORD _                 ' __in SAFEARRAY(BSTR) loadSometimesList
   , BYVAL loadNeverList AS DWORD _                     ' __in SAFEARRAY(BSTR) loadNeverList
   , BYREF pNativeImageIdentity AS WSTRING _            ' __out BSTR* pNativeImageIdentity
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNativeImage ( _                         ' VTable offset = 20
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYVAL pNativeImage AS WSTRING _                    ' __in BSTR pNativeImage
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayNativeImages ( _                       ' VTable offset = 24
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCorSvcDependencies ( _                     ' VTable offset = 28
     BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   , BYVAL scenario AS LONG _                           ' __in OptimizationScenario scenario
   , BYREF pCorSvcDependencies AS ICorSvcDependencies _ ' __out ICorSvcDependencies** pCorSvcDependencies
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcWorker_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorSvcWorker2
' IID = {F3358A7D-0061-4776-880E-A2F21B9EF93E}
' Attributes = 256 [&H00000100] [Oleautomation]
' Inherited interface = ICorSvcWorker
' ########################################################################################

#IF NOT %DEF(%ICorSvcWorker2_INTERFACE_DEFINED)
    %ICorSvcWorker2_INTERFACE_DEFINED = 1

INTERFACE ICorSvcWorker2 $IID_ICorSvcWorker2

   INHERIT IAutomation

   ' =====================================================================================
   ' ICorSvcWorker Methods
   ' =====================================================================================
   METHOD SetPriority ( _                               ' VTable offset = 12
     BYVAL priority AS SvcWorkerPriority _              ' __in SvcWorkerPriority priority
   )                                                    ' void
   ' =====================================================================================
   METHOD OptimizeAssembly ( _                          ' VTable offset = 16
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   , BYVAL scenario AS LONG _                           ' __in OptimizationScenario scenario
   , BYVAL loadAlwaysList AS DWORD _                    ' __in SAFEARRAY(BSTR) loadAlwaysList
   , BYVAL loadSometimesList AS DWORD _                 ' __in SAFEARRAY(BSTR) loadSometimesList
   , BYVAL loadNeverList AS DWORD _                     ' __in SAFEARRAY(BSTR) loadNeverList
   , BYREF pNativeImageIdentity AS WSTRING _            ' __out BSTR* pNativeImageIdentity
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteNativeImage ( _                         ' VTable offset = 20
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYVAL pNativeImage AS WSTRING _                    ' __in BSTR pNativeImage
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayNativeImages ( _                       ' VTable offset = 24
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCorSvcDependencies ( _                     ' VTable offset = 28
     BYVAL pApplicationName AS WSTRING _                ' __in BSTR pApplicationName
   , BYVAL scenario AS LONG _                           ' __in OptimizationScenario scenario
   , BYREF pCorSvcDependencies AS ICorSvcDependencies _ ' __out ICorSvcDependencies** pCorSvcDependencies
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICorSvcWorker2 Method
   ' =====================================================================================
   METHOD CreatePdb ( _                                 ' VTable offset = 36
     BYVAL pAssemblyName AS WSTRING _                   ' __in BSTR pAssemblyName
   , BYVAL pAppBaseOrConfig AS WSTRING _                ' __in BSTR pAppBaseOrConfig
   , BYVAL scenario AS LONG _                           ' __in OptimizationScenario scenario
   , BYVAL pNativeImagePath AS WSTRING _                ' __in BSTR pNativeImagePath
   , BYVAL pPdbPath AS WSTRING _                        ' __in BSTR pPdbPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcWorker2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorSvcPooledWorker
' IID = {0631E7E2-6046-4FDE-8B6D-A09B64FDA6F3}
' Attributes = 256 [&H00000100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcPooledWorker_INTERFACE_DEFINED)
    %ICorSvcPooledWorker_INTERFACE_DEFINED = 1

INTERFACE ICorSvcPooledWorker $IID_ICorSvcPooledWorker

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CanReuseProcess ( _                           ' VTable offset = 12
     BYVAL scenario AS LONG _                           ' [in] scenario OptimizationScenario <alias> __MIDL___MIDL_itf_mscoree_tlb_0001_0009_0001
   , BYVAL pCorSvcLogger AS ICorSvcLogger _             ' [in] *pCorSvcLogger ICorSvcLogger <interface>
   , BYREF pCanContinue AS LONG _                       ' [out] *pCanContinue VT_I4 <Long>
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcPooledWorker_INTERFACE_DEFINED__ */

' ========================================================================================
' NGenPrivateAttributesFlags enum
' ========================================================================================

%DbgTypePdb = 1

' ========================================================================================
' _NGenPrivateAttributes structure
' ========================================================================================

' // Size = 12 bytes
TYPE NGenPrivateAttributes DWORD
   Flags    AS DWORD         ' DWORD
   ZapStats AS DWORD         ' DWORD
   DbgDir   AS WSTRING PTR   ' BSTR
END TYPE

' ########################################################################################
' Interface name = ICorSvcSetPrivateAttributes
' IID = {B18E0B40-C089-4350-8328-066C668BCCC2}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcSetPrivateAttributes_INTERFACE_DEFINED)
    %ICorSvcSetPrivateAttributes_INTERFACE_DEFINED = 1

INTERFACE ICorSvcSetPrivateAttributes $IID_ICorSvcSetPrivateAttributes

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetNGenPrivateAttributes ( _                  ' VTable offset = 12
     BYVAL ngenPrivateAttributes AS NGenPrivateAttributes _ ' __in NGenPrivateAttributes ngenPrivateAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcSetPrivateAttributes_INTERFACE_DEFINED__ */

' ========================================================================================
' RepositoryFlags enum
' ========================================================================================

%RepositoryDefault                                      = 0
%MoveFromRepository                                     = 1
%CopyToRepository                                       = 2

' ########################################################################################
' Interface name = ICorSvcRepository
' IID = {D5346658-B5FD-4353-9647-07AD4783D5A0}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcRepository_INTERFACE_DEFINED)
    %ICorSvcRepository_INTERFACE_DEFINED = 1

INTERFACE ICorSvcRepository $IID_ICorSvcRepository

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetRepository ( _                             ' VTable offset = 12
     BYVAL pRepositoryDir AS WSTRING _                  ' __in BSTR pRepositoryDir
   , BYVAL RepositoryFlags AS LONG _                    ' __in RepositoryFlags RepositoryFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcRepository_INTERFACE_DEFINED__ */

' ========================================================================================
' CorSvcLogLevel enum
' ========================================================================================

%LogLevel_Error                                         = 0
%LogLevel_Warning                                       = 1
%LogLevel_Success                                       = 2
%LogLevel_Info                                          = 3

' ########################################################################################
' Interface name = ICorSvcLogger
' IID = {D189FF1A-E266-4F13-9637-4B9522279FFC}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcLogger_INTERFACE_DEFINED)
    %ICorSvcLogger_INTERFACE_DEFINED = 1

INTERFACE ICorSvcLogger $IID_ICorSvcLogger

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Log ( _                                       ' VTable offset = 12
     BYVAL logLevel AS LONG _                           ' __in CorSvcLogLevel logLevel
   , BYVAL message AS WSTRING _                         ' __in BSTR message
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcLogger_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICorSvcBindToWorker
' IID = {5C6FB596-4828-4ED5-B9DD-293DAD736FB5}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICorSvcBindToWorker_INTERFACE_DEFINED)
    %ICorSvcBindToWorker_INTERFACE_DEFINED = 1

INTERFACE ICorSvcBindToWorker $IID_ICorSvcBindToWorker

   INHERIT IAutomation

   ' =====================================================================================
   METHOD BindToRuntimeWorker ( _                       ' VTable offset = 12
     BYVAL pRuntimePath AS WSTRING _                    ' __in BSTR pRuntimePath
   , BYVAL ParentProcessID AS DWORD _                   ' __in DWORD ParentProcessID
   , BYVAL pInterruptEventName AS WSTRING _             ' __in BSTR pInterruptEventName
   , BYVAL pCorSvcLogger AS ICorSvcLogger _             ' __in ICorSvcLogger* pCorSvcLogger
   , BYREF pCorSvcWorker AS ICorSvcWorker _             ' __out ICorSvcWorker** pCorSvcWorker
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICorSvcBindToWorker_INTERFACE_DEFINED__ */
