' ########################################################################################
' Microsoft Windows
' File: fusion.inc
' Contents: Fusion Interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUSION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"

' enum ASM_CACHE_FLAGS
%ASM_CACHE_ZAP      = &H1???
%ASM_CACHE_GAC      = &H2???
%ASM_CACHE_DOWNLOAD = &H4???
%ASM_CACHE_ROOT     = &H8???

' enum PEKIND
%peNone    = 0???
%peMSIL    = &H1???
%peI386    = &H2???
%peIA64    = &H3???
%peAMD64   = &H4???
%peInvalid = &Hffffffff???

' ########################################################################################
' Interface name = IAssemblyCache
' IID = E707DCDE-D1CD-11D2-BAB9-00C04F8ECEAE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyCache_INTERFACE_DEFINED)
    %IAssemblyCache_INTERFACE_DEFINED = 1

$FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID = GUID$("{8CEDC215-AC4B-488B-93C0-A50A49CB2FB8}")
$FUSION_REFCOUNT_FILEPATH_GUID = GUID$("{B02F9D65-FB77-4F7A-AFA5-B391309F11C9}")
$FUSION_REFCOUNT_OPAQUE_STRING_GUID = GUID$("{2EC93463-B0C3-45E1-8364-327E96AEA856}")
' // this GUID cannot be used for installing into GAC.
$FUSION_REFCOUNT_MSI_GUID = GUID$("{25DF0FC1-7F97-4070-ADD7-4B13BBFD7CB8}")
$FUSION_REFCOUNT_OSINSTALL_GUID = GUID$("{D16D444C-56D8-11D5-882D-0080C847B195}")

' // Size = 32 bytes
TYPE FUSION_INSTALL_REFERENCE DWORD
   cbSize              AS DWORD          ' DWORD
   dwFlags             AS DWORD          ' DWORD
   guidScheme          AS GUID           ' GUID
   szIdentifier        AS WSTRINGZ PTR   ' LPCWSTR
   szNonCannonicalData AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 24 bytes
TYPE ASSEMBLY_INFO QWORD FILL
   cbAssemblyInfo            AS DWORD          ' ULONG
   dwAssemblyFlags           AS DWORD          ' DWORD
   uliAssemblySizeInKB       AS QUAD           ' ULARGE_INTEGER
   pszCurrentAssemblyPathBuf AS WSTRINGZ PTR   ' LPWSTR
   cchBuf                    AS DWORD          ' ULONG
END TYPE

%IASSEMBLYCACHE_INSTALL_FLAG_REFRESH       = &H00000001???
%IASSEMBLYCACHE_INSTALL_FLAG_FORCE_REFRESH = &H00000002???

%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED            = 1
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE           = 2
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED    = 3
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING         = 4
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_HAS_INSTALL_REFERENCES = 5
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_REFERENCE_NOT_FOUND    = 6

%QUERYASMINFO_FLAG_VALIDATE        = &H00000001???
%QUERYASMINFO_FLAG_GETSIZE         = &H00000002???
%ASSEMBLYINFO_FLAG_INSTALLED       = &H00000001???
%ASSEMBLYINFO_FLAG_PAYLOADRESIDENT = &H00000002???

$IID_IAssemblyCache = GUID$("{E707DCDE-D1CD-11D2-BAB9-00C04F8ECEAE}")

INTERFACE IAssemblyCache $IID_IAssemblyCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UninstallAssembly ( _                         ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszAssemblyName AS WSTRINGZ _                ' __in LPCWSTR pszAssemblyName
   , BYREF pRefData AS FUSION_INSTALL_REFERENCE _       ' __in LPCFUSION_INSTALL_REFERENCE pRefData
   , BYREF pulDisposition AS DWORD _                    ' __out_opt ULONG *pulDisposition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAssemblyInfo ( _                         ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszAssemblyName AS WSTRINGZ _                ' __in LPCWSTR pszAssemblyName
   , BYREF pAsmInfo AS ASSEMBLY_INFO _                  ' __inout ASSEMBLY_INFO *pAsmInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAssemblyCacheItem ( _                   ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvReserved AS DWORD _                        ' __in PVOID pvReserved
   , BYREF ppAsmItem AS IAssemblyCacheItem _            ' __out IAssemblyCacheItem **ppAsmItem
   , BYREF pszAssemblyName AS WSTRINGZ _                ' __in_opt LPCWSTR pszAssemblyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAssemblyScavenger ( _                   ' VTable offset = 24
     BYREF ppUnkReserved AS IUnknown _                  ' __out IUnknown **ppUnkReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallAssembly ( _                           ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszManifestFilePath AS WSTRINGZ _            ' __in LPCWSTR pszManifestFilePath
   , BYREF pRefData AS FUSION_INSTALL_REFERENCE _       ' __in LPCFUSION_INSTALL_REFERENCE pRefData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyCache_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAssemblyCacheItem
' IID = 9E3AAEB4-D1CD-11D2-BAB9-00C04F8ECEAE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyCacheItem_INTERFACE_DEFINED)
    %IAssemblyCacheItem_INTERFACE_DEFINED = 1

%STREAM_FORMAT_COMPLIB_MODULE    = 0
%STREAM_FORMAT_COMPLIB_MANIFEST  = 1
%STREAM_FORMAT_WIN32_MODULE      = 2
%STREAM_FORMAT_WIN32_MANIFEST    = 4

%IASSEMBLYCACHEITEM_COMMIT_FLAG_REFRESH       = &H00000001
%IASSEMBLYCACHEITEM_COMMIT_FLAG_FORCE_REFRESH = &H00000002

%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_INSTALLED         = 1
%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_REFRESHED         = 2
%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_ALREADY_INSTALLED = 3

$IID_IAssemblyCacheItem = GUID$("{9E3AAEB4-D1CD-11D2-BAB9-00C04F8ECEAE}")

INTERFACE IAssemblyCacheItem $IID_IAssemblyCacheItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszStreamName AS WSTRINGZ _                  ' __in LPCWSTR pszStreamName
   , BYVAL dwFormat AS DWORD _                          ' __in DWORD dwFormat
   , BYVAL dwFormatFlags AS DWORD _                     ' __in DWORD dwFormatFlags
   , BYREF ppIStream AS IStream _                       ' __out IStream **ppIStream
   , BYVAL puliMaxSize AS QUAD _                        ' __in_opt ULARGE_INTEGER *puliMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulDisposition AS DWORD _                    ' __out_opt ULONG *pulDisposition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortItem ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyCacheItem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAssemblyName
' IID = CD193BC0-B4BC-11D2-9833-00C04FC31D2E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyName_INTERFACE_DEFINED)
    %IAssemblyName_INTERFACE_DEFINED = 1

' enum CREATE_ASM_NAME_OBJ_FLAGS
%CANOF_PARSE_DISPLAY_NAME         = &H1???
%CANOF_SET_DEFAULT_VALUES         = &H2???
%CANOF_VERIFY_FRIEND_ASSEMBLYNAME = &H4???
%CANOF_PARSE_FRIEND_DISPLAY_NAME  = %CANOF_PARSE_DISPLAY_NAME OR %CANOF_VERIFY_FRIEND_ASSEMBLYNAME

' enum ASM_NAME
%ASM_NAME_PUBLIC_KEY            = 0
%ASM_NAME_PUBLIC_KEY_TOKEN      = %ASM_NAME_PUBLIC_KEY            + 1
%ASM_NAME_HASH_VALUE            = %ASM_NAME_PUBLIC_KEY_TOKEN      + 1
%ASM_NAME_NAME                  = %ASM_NAME_HASH_VALUE            + 1
%ASM_NAME_MAJOR_VERSION         = %ASM_NAME_NAME                  + 1
%ASM_NAME_MINOR_VERSION         = %ASM_NAME_MAJOR_VERSION         + 1
%ASM_NAME_BUILD_NUMBER          = %ASM_NAME_MINOR_VERSION         + 1
%ASM_NAME_REVISION_NUMBER       = %ASM_NAME_BUILD_NUMBER          + 1
%ASM_NAME_CULTURE               = %ASM_NAME_REVISION_NUMBER       + 1
%ASM_NAME_PROCESSOR_ID_ARRAY    = %ASM_NAME_CULTURE               + 1
%ASM_NAME_OSINFO_ARRAY          = %ASM_NAME_PROCESSOR_ID_ARRAY    + 1
%ASM_NAME_HASH_ALGID            = %ASM_NAME_OSINFO_ARRAY          + 1
%ASM_NAME_ALIAS                 = %ASM_NAME_HASH_ALGID            + 1
%ASM_NAME_CODEBASE_URL          = %ASM_NAME_ALIAS                 + 1
%ASM_NAME_CODEBASE_LASTMOD      = %ASM_NAME_CODEBASE_URL          + 1
%ASM_NAME_NULL_PUBLIC_KEY       = %ASM_NAME_CODEBASE_LASTMOD      + 1
%ASM_NAME_NULL_PUBLIC_KEY_TOKEN = %ASM_NAME_NULL_PUBLIC_KEY       + 1
%ASM_NAME_CUSTOM                = %ASM_NAME_NULL_PUBLIC_KEY_TOKEN + 1
%ASM_NAME_NULL_CUSTOM           = %ASM_NAME_CUSTOM                + 1
%ASM_NAME_MVID                  = %ASM_NAME_NULL_CUSTOM           + 1
%ASM_NAME_FILE_MAJOR_VERSION    = %ASM_NAME_MVID                  + 1
%ASM_NAME_FILE_MINOR_VERSION    = %ASM_NAME_FILE_MAJOR_VERSION    + 1
%ASM_NAME_FILE_BUILD_NUMBER     = %ASM_NAME_FILE_MINOR_VERSION    + 1
%ASM_NAME_FILE_REVISION_NUMBER  = %ASM_NAME_FILE_BUILD_NUMBER     + 1
%ASM_NAME_RETARGET              = %ASM_NAME_FILE_REVISION_NUMBER  + 1
%ASM_NAME_SIGNATURE_BLOB        = %ASM_NAME_RETARGET              + 1
%ASM_NAME_CONFIG_MASK           = %ASM_NAME_SIGNATURE_BLOB        + 1
%ASM_NAME_ARCHITECTURE          = %ASM_NAME_CONFIG_MASK           + 1
%ASM_NAME_MAX_PARAMS            = %ASM_NAME_ARCHITECTURE          + 1

' enum ASM_DISPLAY_FLAGS
%ASM_DISPLAYF_VERSION               = &H1???
%ASM_DISPLAYF_CULTURE               = &H2???
%ASM_DISPLAYF_PUBLIC_KEY_TOKEN      = &H4???
%ASM_DISPLAYF_PUBLIC_KEY            = &H8???
%ASM_DISPLAYF_CUSTOM                = &H10???
%ASM_DISPLAYF_PROCESSORARCHITECTURE = &H20???
%ASM_DISPLAYF_LANGUAGEID            = &H40???
%ASM_DISPLAYF_RETARGET              = &H80???
%ASM_DISPLAYF_CONFIG_MASK           = &H100???
%ASM_DISPLAYF_MVID                  = &H200???
%ASM_DISPLAYF_FULL                  = %ASM_DISPLAYF_VERSION OR %ASM_DISPLAYF_CULTURE OR %ASM_DISPLAYF_PUBLIC_KEY_TOKEN OR %ASM_DISPLAYF_RETARGET OR %ASM_DISPLAYF_PROCESSORARCHITECTURE

' enum ASM_CMP_FLAGS
%ASM_CMPF_NAME             = &H1???
%ASM_CMPF_MAJOR_VERSION    = &H2???
%ASM_CMPF_MINOR_VERSION    = &H4???
%ASM_CMPF_BUILD_NUMBER     = &H8???
%ASM_CMPF_REVISION_NUMBER  = &H10???
%ASM_CMPF_VERSION          = %ASM_CMPF_MAJOR_VERSION OR %ASM_CMPF_MINOR_VERSION OR %ASM_CMPF_BUILD_NUMBER OR %ASM_CMPF_REVISION_NUMBER
%ASM_CMPF_PUBLIC_KEY_TOKEN = &H20???
%ASM_CMPF_CULTURE          = &H40???
%ASM_CMPF_CUSTOM           = &H80???
%ASM_CMPF_DEFAULT          = &H100???
%ASM_CMPF_RETARGET         = &H200???
%ASM_CMPF_ARCHITECTURE     = &H400???
%ASM_CMPF_CONFIG_MASK      = &H800???
%ASM_CMPF_MVID             = &H1000???
%ASM_CMPF_SIGNATURE        = &H2000???
%ASM_CMPF_IL_ALL           = %ASM_CMPF_NAME OR %ASM_CMPF_VERSION OR %ASM_CMPF_PUBLIC_KEY_TOKEN OR %ASM_CMPF_CULTURE
%ASM_CMPF_IL_NO_VERSION    = %ASM_CMPF_NAME OR %ASM_CMPF_PUBLIC_KEY_TOKEN OR %ASM_CMPF_CULTURE

$IID_IAssemblyName = GUID$("{CD193BC0-B4BC-11D2-9833-00C04FC31D2E}")

INTERFACE IAssemblyName $IID_IAssemblyName

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 12
     BYVAL PropertyId AS DWORD _                        ' __in DWORD PropertyId
   , BYVAL pvProperty AS DWORD _                        ' __in LPVOID pvProperty
   , BYVAL cbProperty AS DWORD _                        ' __in DWORD cbProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYVAL PropertyId AS DWORD _                        ' __in DWORD PropertyId
   , BYVAL pvProperty AS DWORD _                        ' __out LPVOID pvProperty
   , BYREF pcbProperty AS DWORD _                       ' __inout LPDWORD pcbProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finalize ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF szDisplayName AS WSTRINGZ _                  ' __out LPOLESTR szDisplayName
   , BYREF pccDisplayName AS DWORD _                    ' __inout LPDWORD pccDisplayName
   , BYVAL dwDisplayFlags AS DWORD _                    ' __in DWORD dwDisplayFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved ( _                                  ' VTable offset = 28
     BYREF refIID AS GUID _                             ' __in REFIID refIID
   , BYVAL pUnkReserved1 AS IUnknown _                  ' __in IUnknown *pUnkReserved1
   , BYVAL pUnkReserved2 AS IUnknown _                  ' __in IUnknown *pUnkReserved2
   , BYREF szReserved AS WSTRINGZ _                     ' __in LPCOLESTR szReserved
   , BYVAL llReserved AS QUAD _                         ' __in LONGLONG llReserved
   , BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   , BYVAL cbReserved AS DWORD _                        ' __in DWORD cbReserved
   , BYREF ppReserved AS DWORD _                        ' __out LPVOID *ppReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 32
     BYREF lpcwBuffer AS DWORD _                        ' __inout LPDWORD lpcwBuffer
   , BYVAL pwzName AS DWORD _                           ' __out WCHAR *pwzName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 36
     BYREF pdwVersionHi AS DWORD _                      ' __out LPDWORD pdwVersionHi
   , BYREF pdwVersionLow AS DWORD _                     ' __out LPDWORD pdwVersionLow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 40
     BYVAL pName AS IAssemblyName _                     ' __in IAssemblyName *pName
   , BYVAL dwCmpFlags AS DWORD _                        ' __in DWORD dwCmpFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 44
     BYREF pName AS IAssemblyName _                     ' __out IAssemblyName **pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAssemblyEnum
' IID = 21B8916C-F28E-11D2-A473-00C04F8EF448
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyEnum_INTERFACE_DEFINED)
    %IAssemblyEnum_INTERFACE_DEFINED = 1

$IID_IAssemblyEnum = GUID$("{21B8916C-F28E-11D2-A473-00C04F8EF448}")

INTERFACE IAssemblyEnum $IID_IAssemblyEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNextAssembly ( _                           ' VTable offset = 12
     BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   , BYREF ppName AS IAssemblyName _                    ' __out IAssemblyName **ppName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
     BYREF ppEnum AS IAssemblyEnum _                    ' __out IAssemblyEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInstallReferenceItem
' IID = 582DAC66-E678-449F-ABA6-6FAAEC8A9394
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInstallReferenceItem_INTERFACE_DEFINED)
    %IInstallReferenceItem_INTERFACE_DEFINED = 1

$IID_IInstallReferenceItem = GUID$("{582DAC66-E678-449F-ABA6-6FAAEC8A9394}")

INTERFACE IInstallReferenceItem $IID_IInstallReferenceItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetReference ( _                              ' VTable offset = 12
     BYREF ppRefData AS FUSION_INSTALL_REFERENCE _      ' __out LPFUSION_INSTALL_REFERENCE *ppRefData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInstallReferenceItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInstallReferenceEnum
' IID = 56B1A988-7C0C-4AA2-8639-C3EB5A90226F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInstallReferenceEnum_INTERFACE_DEFINED)
    %IInstallReferenceEnum_INTERFACE_DEFINED = 1

$IID_IInstallReferenceEnum = GUID$("{56B1A988-7C0C-4AA2-8639-C3EB5A90226F}")

INTERFACE IInstallReferenceEnum $IID_IInstallReferenceEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetReference ( _                              ' VTable offset = 12
     BYREF ppRefItem AS IInstallReferenceItem _         ' __out IInstallReferenceItem **ppRefItem
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInstallReferenceEnum_INTERFACE_DEFINED__ */

' enum AssemblyComparisonResult
%ACR_Unknown                     = 0
%ACR_EquivalentFullMatch         = %ACR_Unknown                    + 1
%ACR_EquivalentWeakNamed         = %ACR_EquivalentFullMatch        + 1
%ACR_EquivalentFXUnified         = %ACR_EquivalentWeakNamed        + 1
%ACR_EquivalentUnified           = %ACR_EquivalentFXUnified        + 1
%ACR_NonEquivalentVersion        = %ACR_EquivalentUnified          + 1
%ACR_NonEquivalent               = %ACR_NonEquivalentVersion       + 1
%ACR_EquivalentPartialMatch      = %ACR_NonEquivalent              + 1
%ACR_EquivalentPartialWeakNamed  = %ACR_EquivalentPartialMatch     + 1
%ACR_EquivalentPartialUnified    = %ACR_EquivalentPartialWeakNamed + 1
%ACR_EquivalentPartialFXUnified  = %ACR_EquivalentPartialUnified   + 1
%ACR_NonEquivalentPartialVersion = %ACR_EquivalentPartialFXUnified + 1

'STDAPI CreateAssemblyConfigCookie(LPCWSTR wzConfigFilePath, struct AssemblyConfig **ppAssemblyConfigOut);
'STDAPI DestroyAssemblyConfigCookie(struct AssemblyConfig *pAssemblyConfig);

' Not exported
'STDAPI CompareAssemblyIdentity(LPCWSTR pwzAssemblyIdentity1, BOOL fUnified1, LPCWSTR pwzAssemblyIdentity2, BOOL fUnified2, BOOL *pfEquivalent, AssemblyComparisonResult *pResult);
'DECLARE FUNCTION CompareAssemblyIdentity IMPORT "fusion.dll" ALIAS "CompareAssemblyIdentity" ( _
'   BYREF pwzAssemblyIdentity1 AS WSTRINGZ _             ' __in LPCWSTR pwzAssemblyIdentity1
' , BYVAL fUnified1 AS LONG _                            ' __in BOOL fUnified1
' , BYREF pwzAssemblyIdentity2 AS WSTRINGZ _             ' __in LPCWSTR pwzAssemblyIdentity2
' , BYVAL fUnified2 AS LONG _                            ' __in BOOL fUnified2
' , BYREF pfEquivalent AS LONG _                         ' __out BOOL *pfEquivalent
' , BYREF pResult AS LONG _                              ' __out AssemblyComparisonResult *pResult
' ) AS LONG                                              ' HRESULT

'STDAPI CompareAssemblyIdentityWithConfig(LPCWSTR pwzAssemblyIdentity1, BOOL fUnified1, LPCWSTR pwzAssemblyIdentity2, BOOL fUnified2, struct AssemblyConfig *pAssemblyConfig, BOOL *pfEquivalent, AssemblyComparisonResult *pResult);

DECLARE FUNCTION CreateInstallReferenceEnum IMPORT "fusion.dll" ALIAS "CreateInstallReferenceEnum" ( _
   BYREF ppRefEnum AS IInstallReferenceEnum _           ' __out IInstallReferenceEnum **ppRefEnum
 , BYVAL pName AS IAssemblyName _                       ' __in IAssemblyName *pName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAssemblyEnum IMPORT "fusion.dll" ALIAS "CreateAssemblyEnum" ( _
   BYREF pEnum AS IAssemblyEnum _                       ' __out IAssemblyEnum **pEnum
 , BYVAL pUnkReserved AS IUnknown _                     ' __in IUnknown *pUnkReserved
 , BYVAL pName AS IAssemblyName _                       ' __in IAssemblyName *pName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAssemblyNameObject IMPORT "fusion.dll" ALIAS "CreateAssemblyNameObject" ( _
   BYREF ppAssemblyNameObj AS IAssemblyName _           ' __out LPASSEMBLYNAME *ppAssemblyNameObj
 , BYREF szAssemblyName AS WSTRINGZ _                   ' __in LPCWSTR szAssemblyName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAssemblyCache IMPORT "fusion.dll" ALIAS "CreateAssemblyCache" ( _
   BYREF ppAsmCache AS IAssemblyCache _                 ' __out IAssemblyCache **ppAsmCache
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetCachePath IMPORT "fusion.dll" ALIAS "GetCachePath" ( _
   BYVAL dwCacheFlags AS DWORD _                        ' __in ASM_CACHE_FLAGS dwCacheFlags
 , BYREF pwzCachePath AS WSTRINGZ _                     ' __in LPWSTR pwzCachePath
 , BYREF pcchPath AS DWORD _                            ' __inout PDWORD pcchPath
 ) AS LONG                                              ' HRESULT

' Not exported
'STDAPI GetAssemblyIdentityFromFile(LPCWSTR pwzFilePAth, REFIID riid, IUnknown **ppIdentity);
'DECLARE FUNCTION GetAssemblyIdentityFromFile IMPORT "fusion.dll" ALIAS "GetAssemblyIdentityFromFile" ( _
'   BYREF pwzFilePAth AS WSTRINGZ _                      ' __in LPCWSTR pwzFilePAth
' , BYREF riid AS GUID _                                 ' __in REFIID riid
' , BYREF ppIdentity AS IUnknown _                       ' __out IUnknown **ppIdentity
' ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ClearDownloadCache IMPORT "fusion.dll" ALIAS "ClearDownloadCache" ( _
 ) AS LONG                                              ' HRESULT
