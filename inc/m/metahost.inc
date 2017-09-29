' ########################################################################################
' Microsoft Windows
' File: metahost.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%METAHOST_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mscoree.inc"

DECLARE FUNCTION CLRCreateInstance IMPORT "mscoree.dll" ALIAS "CLRCreateInstance" ( _
   BYREF clsid AS GUID _                                ' __in REFCLSID clsid
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppInterface AS IUnknown _                      ' __out LPVOID *ppInterface
 ) AS LONG                                              ' HRESULT

'EXTERN_C const IID LIBID_CLRMetaHost;

$CLSID_CLRStrongName = GUID$("{B79B0ACD-F5CD-409b-B5A5-A16244610B92}")
$IID_ICLRMetaHost = GUID$("{D332DB9E-B9B3-4125-8207-A14884F53216}")
$CLSID_CLRMetaHost = GUID$("{9280188d-0e8e-4867-b30c-7fa83884e8de}")
$IID_ICLRMetaHostPolicy = GUID$("{E2190695-77B2-492e-8E14-C4B3A7FDD593}")
$CLSID_CLRMetaHostPolicy = GUID$("{2ebcd49a-1b47-4a61-b13a-4a03701e594b}")
$IID_ICLRDebugging = GUID$("{d28f3c5a-9634-4206-a509-477552eefb10}")
$CLSID_CLRDebugging = GUID$("{bacc578d-fbdd-48a4-969f-02d932b74634}")
$IID_ICLRRuntimeInfo = GUID$("{BD39D1D2-BA2F-486a-89B0-B4B0CB466891}")
$IID_ICLRStrongName = GUID$("{9FD93CCF-3280-4391-B3A9-96E1CDE77C8D}")
$CLSID_CLRDebuggingLegacy = GUID$("{DF8395B5-A4BA-450b-A77C-A9A47762C520}")
$CLSID_CLRProfiling = GUID$("{bd097ed8-733e-43fe-8ed7-a95ff9a8448c}")
$IID_ICLRProfiling = GUID$("{b349abe3-b56f-4689-bfcd-76bf39d888ea}")
$IID_ICLRDebuggingLibraryProvider = GUID$("{3151c08d-4d09-4f9b-8838-2880bf18fe51}")

'typedef HRESULT ( __stdcall *CLRCreateInstanceFnPtr )(
'    REFCLSID clsid
'    REFIID riid
'    LPVOID *ppInterface);

'typedef HRESULT ( __stdcall *CreateInterfaceFnPtr )(
'    REFCLSID clsid
'    REFIID riid
'    LPVOID *ppInterface);

'typedef HRESULT ( __stdcall *CallbackThreadSetFnPtr )( void);

'typedef HRESULT ( __stdcall *CallbackThreadUnsetFnPtr )( void);

'typedef void ( __stdcall *RuntimeLoadedCallbackFnPtr )(
'    ICLRRuntimeInfo *pRuntimeInfo
'    CallbackThreadSetFnPtr pfnCallbackThreadSet
'    CallbackThreadUnsetFnPtr pfnCallbackThreadUnset);

' ########################################################################################
' ICLRMetaHost interface
' IID = D332DB9E-B9B3-4125-8207-A14884F53216
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRMetaHost_INTERFACE_DEFINED)
    %ICLRMetaHost_INTERFACE_DEFINED = 1

INTERFACE ICLRMetaHost $IID_ICLRMetaHost

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetRuntime ( _                                ' VTable offset = 12
     BYREF pwzVersion AS WSTRINGZ _                     ' __in LPCWSTR pwzVersion
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __out_retval LPVOID *ppRuntime
   ' =====================================================================================
   METHOD GetVersionFromFile ( _                        ' VTable offset = 16
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBuffer AS DWORD _                        ' __inout DWORD *pcchBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumerateInstalledRuntimes ( _                ' VTable offset = 20
   ) AS IEnumUnknown                                    ' __out_retval IEnumUnknown **ppEnumerator
   ' =====================================================================================
   METHOD EnumerateLoadedRuntimes ( _                   ' VTable offset = 24
     BYVAL hndProcess AS DWORD _                        ' __in HANDLE hndProcess
   ) AS IEnumUnknown                                    ' __out_retval IEnumUnknown **ppEnumerator
   ' =====================================================================================
   METHOD RequestRuntimeLoadedNotification ( _          ' VTable offset = 28
     BYVAL pCallbackFunction AS DWORD _                 ' __in RuntimeLoadedCallbackFnPtr pCallbackFunction
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryLegacyV2RuntimeBinding ( _               ' VTable offset = 32
     BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __out_retval LPVOID *ppUnk
   ' =====================================================================================
   METHOD ExitProcess ( _                               ' VTable offset = 36
     BYVAL iExitCode AS DWORD _                         ' __in INT32 iExitCode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRMetaHost_INTERFACE_DEFINED__ */


' enum METAHOST_POLICY_FLAGS
%METAHOST_POLICY_HIGHCOMPAT             = 0???
%METAHOST_POLICY_APPLY_UPGRADE_POLICY   = &H8???
%METAHOST_POLICY_EMULATE_EXE_LAUNCH     = &H10???
%METAHOST_POLICY_SHOW_ERROR_DIALOG      = &H20???
%METAHOST_POLICY_USE_PROCESS_IMAGE_PATH = &H40???
%METAHOST_POLICY_ENSURE_SKU_SUPPORTED   = &H80???

' enum METAHOST_CONFIG_FLAGS
%METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_UNSET = 0???
%METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_TRUE  = &H1???
%METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_FALSE = &H2???
%METAHOST_CONFIG_FLAGS_LEGACY_V2_ACTIVATION_POLICY_MASK  = &H3???

' ########################################################################################
' ICLRMetaHostPolicy interface
' IID = E2190695-77B2-492E-8E14-C4B3A7FDD593
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRMetaHostPolicy_INTERFACE_DEFINED)
    %ICLRMetaHostPolicy_INTERFACE_DEFINED = 1

INTERFACE ICLRMetaHostPolicy $IID_ICLRMetaHostPolicy

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetRequestedRuntime ( _                       ' VTable offset = 12
     BYVAL dwPolicyFlags AS DWORD _                     ' __in METAHOST_POLICY_FLAGS dwPolicyFlags
   , BYREF pwzBinary AS WSTRINGZ _                      ' __in LPCWSTR pwzBinary
   , BYVAL pCfgStream AS IStream _                      ' __in IStream *pCfgStream
   , BYREF pwzVersion AS WSTRINGZ _                     ' __inout LPWSTR pwzVersion
   , BYREF pcchVersion AS DWORD _                       ' __inout DWORD *pcchVersion
   , BYREF pwzImageVersion AS WSTRINGZ _                ' __out LPWSTR pwzImageVersion
   , BYREF pcchImageVersion AS DWORD _                  ' __inout DWORD *pcchImageVersion
   , BYREF pdwConfigFlags AS DWORD _                    ' __out DWORD *pdwConfigFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __out_retval LPVOID *ppRuntime
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRMetaHostPolicy_INTERFACE_DEFINED__ */

' ########################################################################################
' ICLRProfiling interface
' IID = B349ABE3-B56F-4689-BFCD-76BF39D888EA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRProfiling_INTERFACE_DEFINED)
    %ICLRProfiling_INTERFACE_DEFINED = 1

INTERFACE ICLRProfiling $IID_ICLRProfiling

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AttachProfiler ( _                            ' VTable offset = 12
     BYVAL dwProfileeProcessID AS DWORD _               ' __in DWORD dwProfileeProcessID
   , BYVAL dwMillisecondsMax AS DWORD _                 ' __in DWORD dwMillisecondsMax
   , BYREF pClsidProfiler AS GUID _                     ' __in const CLSID *pClsidProfiler
   , BYREF wszProfilerPath AS GUID _                    ' __in LPCWSTR wszProfilerPath
   , BYVAL pvClientData AS DWORD _                      ' __in void *pvClientData
   , BYVAL cbClientData AS DWORD _                      ' __in UINT cbClientData
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRProfiling_INTERFACE_DEFINED__ */

TYPE CLR_DEBUGGING_VERSION WORD
   wStructVersion AS WORD
   wMajor         AS WORD
   wMinor         AS WORD
   wBuild         AS WORD
   wRevision      AS WORD
END TYPE

' enum CLR_DEBUGGING_PROCESS_FLAGS
%CLR_DEBUGGING_MANAGED_EVENT_PENDING = 1???

' ########################################################################################
' ICLRDebuggingLibraryProvider interface
' IID = 3151C08D-4D09-4F9B-8838-2880BF18FE51
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRDebuggingLibraryProvider_INTERFACE_DEFINED)
    %ICLRDebuggingLibraryProvider_INTERFACE_DEFINED = 1

INTERFACE ICLRDebuggingLibraryProvider $IID_ICLRDebuggingLibraryProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ProvideLibrary ( _                            ' VTable offset = 12
     BYREF pwszFileName AS WSTRINGZ _                   ' __in const WCHAR *pwszFileName
   , BYVAL dwTimestamp AS DWORD _                       ' __in DWORD dwTimestamp
   , BYVAL dwSizeOfImage AS DWORD _                     ' __in DWORD dwSizeOfImage
   , BYREF phModule AS DWORD _                          ' __out HMODULE *phModule
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRDebuggingLibraryProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' ICLRDebugging interface
' IID = D28F3C5A-9634-4206-A509-477552EEFB10
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRDebugging_INTERFACE_DEFINED)
    %ICLRDebugging_INTERFACE_DEFINED = 1

INTERFACE ICLRDebugging $IID_ICLRDebugging

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OpenVirtualProcess ( _                        ' VTable offset = 12
     BYVAL moduleBaseAddress AS QUAD _                  ' __in ULONG64 moduleBaseAddress
   , BYVAL pDataTarget AS IUnknown _                    ' __in IUnknown *pDataTarget
   , BYVAL pLibraryProvider AS ICLRDebuggingLibraryProvider _ ' __in ICLRDebuggingLibraryProvider *pLibraryProvider
   , BYREF pMaxDebuggerSupportedVersion AS CLR_DEBUGGING_VERSION _ ' __in CLR_DEBUGGING_VERSION *pMaxDebuggerSupportedVersion
   , BYREF riidProcess AS GUID _                        ' __in REFIID riidProcess
   , BYREF ppProcess AS IUnknown _                      ' __out IUnknown **ppProcess
   , BYREF pVersion AS CLR_DEBUGGING_VERSION _          ' __inout CLR_DEBUGGING_VERSION *pVersion
   , BYREF pdwFlags AS DWORD _                          ' __out CLR_DEBUGGING_PROCESS_FLAGS *pdwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD CanUnloadNow ( _                              ' VTable offset = 16
     BYVAL hModule AS DWORD _                           ' __in HMODULE hModule
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRDebugging_INTERFACE_DEFINED__ */

' ########################################################################################
' ICLRRuntimeInfo interface
' IID = BD39D1D2-BA2F-486A-89B0-B4B0CB466891
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRRuntimeInfo_INTERFACE_DEFINED)
    %ICLRRuntimeInfo_INTERFACE_DEFINED = 1

INTERFACE ICLRRuntimeInfo $IID_ICLRRuntimeInfo

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetVersionString ( _                          ' VTable offset = 12
     BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBuffer AS DWORD _                        ' __inout DWORD *pcchBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRuntimeDirectory ( _                       ' VTable offset = 16
     BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBuffer AS DWORD _                        ' __inout DWORD *pcchBuffer
   )                                                    ' void
   ' =====================================================================================
   METHOD IsLoaded ( _                                  ' VTable offset = 20
     BYVAL hndProcess AS DWORD _                        ' __in HANDLE hndProcess
   ) AS LONG                                            ' __out_retval BOOL *pbLoaded
   ' =====================================================================================
   METHOD LoadErrorString ( _                           ' VTable offset = 24
     BYVAL iResourceID AS DWORD _                       ' __in UINT iResourceID
   , BYREF pwzBuffer AS WSTRINGZ _                      ' __out LPWSTR pwzBuffer
   , BYREF pcchBuffer AS DWORD _                        ' __inout DWORD *pcchBuffer
   , BYVAL iLocaleID AS LONG _                          ' __in LONG iLocaleID
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadLibrary ( _                               ' VTable offset = 28
     BYREF pwzDllName AS WSTRINGZ _                     ' __in LPCWSTR pwzDllName
   ) AS DWORD                                           ' __out_retval HMODULE *phndModule
   ' =====================================================================================
   METHOD GetProcAddress ( _                            ' VTable offset = 32
     BYREF pszProcName AS WSTRINGZ _                    ' __in LPCSTR pszProcName
   ) AS DWORD                                           ' __out_retval LPVOID *ppProc
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 36
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __out_retval LPVOID *ppUnk
   ' =====================================================================================
   METHOD IsLoadable ( _                                ' VTable offset = 40
   ) AS LONG                                            ' __out_retval BOOL *pbLoadable
   ' =====================================================================================
   METHOD SetDefaultStartupFlags ( _                    ' VTable offset = 44
     BYVAL dwStartupFlags AS DWORD _                    ' __in DWORD dwStartupFlags
   , BYREF pwzHostConfigFile AS WSTRINGZ _              ' __in LPCWSTR pwzHostConfigFile
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDefaultStartupFlags ( _                    ' VTable offset = 48
     BYREF pdwStartupFlags AS DWORD _                   ' __out DWORD *pdwStartupFlags
   , BYREF pwzHostConfigFile AS WSTRINGZ _              ' __out LPWSTR pwzHostConfigFile
   , BYREF pcchHostConfigFile AS DWORD _                ' __inout DWORD *pcchHostConfigFile
   )                                                    ' void
   ' =====================================================================================
   METHOD BindAsLegacyV2Runtime ( _                     ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD IsStarted ( _                                 ' VTable offset = 56
     BYREF pbStarted AS LONG _                          ' __out BOOL *pbStarted
   , BYREF pdwStartupFlags AS DWORD _                   ' __out DWORD *pdwStartupFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRRuntimeInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' ICLRStrongName interface
' IID = 9FD93CCF-3280-4391-B3A9-96E1CDE77C8D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICLRStrongName_INTERFACE_DEFINED)
    %ICLRStrongName_INTERFACE_DEFINED = 1

INTERFACE ICLRStrongName $IID_ICLRStrongName

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetHashFromAssemblyFile ( _                   ' VTable offset = 12
     BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   , BYREF piHashAlg AS DWORD _                         ' __inout unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHashFromAssemblyFileW ( _                  ' VTable offset = 16
     BYREF pszFilePath AS WSTRINGZ _                    ' __in LPCWSTR pszFilePath
   , BYREF piHashAlg AS DWORD _                         ' __inout unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHashFromBlob ( _                           ' VTable offset = 20
     BYVAL pbBlob AS BYTE PTR _                         ' __in BYTE *pbBlob
   , BYVAL cchBlob AS DWORD _                           ' __in DWORD cchBlob
   , BYREF piHashAlg AS DWORD _                         ' __inout unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHashFromFile ( _                           ' VTable offset = 24
     BYREF pszFilePath AS ASCIIZ _                      ' __in LPCSTR pszFilePath
   , BYREF piHashAlg AS DWORD _                         ' __in unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHashFromFileW ( _                          ' VTable offset = 28
     BYREF pszFilePath AS WSTRINGZ _                    ' __in LPCWSTR pszFilePath
   , BYREF piHashAlg AS DWORD _                         ' __in unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD GetHashFromHandle ( _                         ' VTable offset = 32
     BYVAL hFile AS DWORD _                             ' __in HANDLE hFile
   , BYREF piHashAlg AS DWORD _                         ' __in unsigned int *piHashAlg
   , BYVAL pbHash AS BYTE PTR _                         ' __out BYTE *pbHash
   , BYVAL cchHash AS DWORD _                           ' __in DWORD cchHash
   , BYREF pchHash AS DWORD _                           ' __out DWORD *pchHash
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameCompareAssemblies ( _               ' VTable offset = 36
     BYREF pwzAssembly1 AS WSTRINGZ _                   ' __in LPCWSTR pwzAssembly1
   , BYREF pwzAssembly2 AS WSTRINGZ _                   ' __in LPCWSTR pwzAssembly2
   ) AS DWORD                                           ' __out_retval DWORD *pdwResult
   ' =====================================================================================
   METHOD StrongNameFreeBuffer ( _                      ' VTable offset = 40
     BYVAL pbMemory AS BYTE _                           ' __in BYTE *pbMemory
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameGetBlob ( _                         ' VTable offset = 44
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYVAL pbBlob AS BYTE PTR _                         ' __inout BYTE *pbBlob
   , BYREF pcbBlob AS DWORD _                           ' __inout DWORD *pcbBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameGetBlobFromImage ( _                ' VTable offset = 48
     BYVAL pbBase AS BYTE PTR _                         ' __in BYTE *pbBase
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   , BYVAL pbBlob AS BYTE PTR _                         ' __out BYTE *pbBlob
   , BYREF pcbBlob AS DWORD _                           ' __inout DWORD *pcbBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameGetPublicKey ( _                    ' VTable offset = 52
     BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   , BYVAL pbKeyBlob AS BYTE PTR _                      ' __in BYTE *pbKeyBlob
   , BYVAL cbKeyBlob AS DWORD _                         ' __in ULONG cbKeyBlob
   , BYREF ppbPublicKeyBlob AS DWORD _                  ' __out BYTE **ppbPublicKeyBlob
   , BYREF pcbPublicKeyBlob AS DWORD _                  ' __out ULONG *pcbPublicKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameHashSize ( _                        ' VTable offset = 56
     BYVAL ulHashAlg AS DWORD _                         ' __in ULONG ulHashAlg
   ) AS DWORD                                           ' __out_retval DWORD *pcbSize
   ' =====================================================================================
   METHOD StrongNameKeyDelete ( _                       ' VTable offset = 60
     BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameKeyGen ( _                          ' VTable offset = 64
     BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppbKeyBlob AS DWORD _                        ' __out BYTE **ppbKeyBlob
   , BYREF pcbKeyBlob AS DWORD _                        ' __out ULONG *pcbKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameKeyGenEx ( _                        ' VTable offset = 68
     BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwKeySize AS DWORD _                         ' __in DWORD dwKeySize
   , BYREF ppbKeyBlob AS DWORD _                        ' __out BYTE **ppbKeyBlob
   , BYREF pcbKeyBlob AS DWORD _                        ' __out ULONG *pcbKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameKeyInstall ( _                      ' VTable offset = 72
     BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   , BYVAL pbKeyBlob AS BYTE PTR _                      ' __in BYTE *pbKeyBlob
   , BYVAL cbKeyBlob AS DWORD _                         ' __in ULONG cbKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameSignatureGeneration ( _             ' VTable offset = 76
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYREF pwzKeyContainer AS WSTRINGZ _                ' __in LPCWSTR pwzKeyContainer
   , BYVAL pbKeyBlob AS BYTE PTR _                      ' __in BYTE *pbKeyBlob
   , BYVAL cbKeyBlob AS DWORD _                         ' __in ULONG cbKeyBlob
   , BYREF ppbSignatureBlob AS DWORD _                  ' __out BYTE **ppbSignatureBlob
   , BYREF pcbSignatureBlob AS DWORD _                  ' __out ULONG *pcbSignatureBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameSignatureGenerationEx ( _           ' VTable offset = 80
     BYREF wszFilePath AS WSTRINGZ _                    ' __in LPCWSTR wszFilePath
   , BYREF wszKeyContainer AS WSTRINGZ _                ' __in LPCWSTR wszKeyContainer
   , BYVAL pbKeyBlob AS BYTE PTR _                      ' __in BYTE *pbKeyBlob
   , BYVAL cbKeyBlob AS DWORD _                         ' __in ULONG cbKeyBlob
   , BYREF ppbSignatureBlob AS DWORD _                  ' __out BYTE **ppbSignatureBlob
   , BYREF pcbSignatureBlob AS DWORD _                  ' __out ULONG *pcbSignatureBlob
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameSignatureSize ( _                   ' VTable offset = 84
     BYVAL pbPublicKeyBlob AS BYTE PTR _                ' __in BYTE *pbPublicKeyBlob
   , BYVAL cbPublicKeyBlob AS DWORD _                   ' __in ULONG cbPublicKeyBlob
   , BYREF pcbSize AS DWORD _                           ' __in DWORD *pcbSize
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameSignatureVerification ( _           ' VTable offset = 88
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYVAL dwInFlags AS DWORD _                         ' __in DWORD dwInFlags
   ) AS DWORD                                           ' __out_retval DWORD *pdwOutFlags
   ' =====================================================================================
   METHOD StrongNameSignatureVerificationEx ( _         ' VTable offset = 92
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYVAL fForceVerification AS BYTE _                 ' __in BOOLEAN fForceVerification
   ) AS BYTE                                            ' __out_retval BOOLEAN *pfWasVerified
   ' =====================================================================================
   METHOD StrongNameSignatureVerificationFromImage ( _  ' VTable offset = 96
     BYVAL pbBase AS BYTE PTR _                         ' __in BYTE *pbBase
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   , BYVAL dwInFlags AS DWORD _                         ' __in DWORD dwInFlags
   ) AS DWORD                                           ' __out_retval DWORD *pdwOutFlags
   ' =====================================================================================
   METHOD StrongNameTokenFromAssembly ( _               ' VTable offset = 100
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYREF ppbStrongNameToken AS DWORD _                ' __out BYTE **ppbStrongNameToken
   , BYREF pcbStrongNameToken AS DWORD _                ' __out ULONG *pcbStrongNameToken
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameTokenFromAssemblyEx ( _             ' VTable offset = 104
     BYREF pwzFilePath AS WSTRINGZ _                    ' __in LPCWSTR pwzFilePath
   , BYREF ppbStrongNameToken AS DWORD _                ' __out BYTE **ppbStrongNameToken
   , BYREF pcbStrongNameToken AS DWORD _                ' __out ULONG *pcbStrongNameToken
   , BYREF ppbPublicKeyBlob AS DWORD _                  ' __out BYTE **ppbPublicKeyBlob
   , BYREF pcbPublicKeyBlob AS DWORD _                  ' __out ULONG *pcbPublicKeyBlob
   )                                                    ' void
   ' =====================================================================================
   METHOD StrongNameTokenFromPublicKey ( _              ' VTable offset = 108
     BYVAL pbPublicKeyBlob AS BYTE PTR _                ' __in BYTE *pbPublicKeyBlob
   , BYVAL cbPublicKeyBlob AS DWORD _                   ' __in ULONG cbPublicKeyBlob
   , BYREF ppbStrongNameToken AS DWORD _                ' __out BYTE **ppbStrongNameToken
   , BYREF pcbStrongNameToken AS DWORD _                ' __out ULONG *pcbStrongNameToken
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICLRStrongName_INTERFACE_DEFINED__ */
