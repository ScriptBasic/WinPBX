' ########################################################################################
' Microsoft Windows
' File: winsxs.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSXS_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"

'//---------------------------------------------------------------------------=
'// Fusion Interfaces for sxs assemblies.

%STREAM_FORMAT_COMPLIB_MODULE   = 0
%STREAM_FORMAT_COMPLIB_MANIFEST = 1
%STREAM_FORMAT_WIN32_MODULE     = 2
%STREAM_FORMAT_WIN32_MANIFEST   = 4

#IF NOT %DEF(%LPFUSION_DEFINED)
%LPFUSION_DEFINED = 1
%IASSEMBLYCACHEITEM_COMMIT_FLAG_REFRESH = &H00000001???
%QUERYASMINFO_FLAG_VALIDATE             = &H1???
%ASSEMBLYINFO_FLAG_INSTALLED            = &H00000001???
%ASSEMBLYINFO_FLAG_PAYLOADRESIDENT      = &H00000002???

' // Size = 24 bytes
TYPE ASSEMBLY_INFO   ' Must be 8 byte aligned
   cbAssemblyInfo            AS DWORD          ' ULONG
   dwAssemblyFlags           AS DWORD          ' DWORD
   uliAssemblySizeInKB       AS QUAD           ' ULARGE_INTEGER
   pszCurrentAssemblyPathBuf AS WSTRINGZ PTR   ' LPWSTR
   cchBuf                    AS DWORD          ' ULONG
END TYPE

%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED         = 1
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE        = 2
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED = 3
%IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING      = 4
%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_INSTALLED          = 1
%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_REFRESHED          = 2
%IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_ALREADY_INSTALLED  = 3

'// {8cedc215-ac4b-488b-93c0-a50a49cb2fb8}
'DEFINE_GUID(FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID, 0x8cedc215, 0xac4b, 0x488b, 0x93, 0xc0, 0xa5, 0x0a, 0x49, 0xcb, 0x2f, 0xb8);
$FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID = GUID$("{8cedc215-ac4b-488b-93c0-a50a49cb2fb8}")

'// {b02f9d65-fb77-4f7a-afa5-b391309f11c9}
'DEFINE_GUID(FUSION_REFCOUNT_FILEPATH_GUID, 0xb02f9d65, 0xfb77, 0x4f7a, 0xaf, 0xa5, 0xb3, 0x91, 0x30, 0x9f, 0x11, 0xc9);
$FUSION_REFCOUNT_FILEPATH_GUID = GUID$("{b02f9d65-fb77-4f7a-afa5-b391309f11c9}")

'// {2ec93463-b0c3-45e1-8364-327e96aea856}
'DEFINE_GUID(FUSION_REFCOUNT_OPAQUE_STRING_GUID, 0x2ec93463, 0xb0c3, 0x45e1, 0x83, 0x64, 0x32, 0x7e, 0x96, 0xae, 0xa8, 0x56);
$FUSION_REFCOUNT_OPAQUE_STRING_GUID = GUID$("{2ec93463-b0c3-45e1-8364-327e96aea856}")

' // Size = 32 bytes
TYPE FUSION_INSTALL_REFERENCE DWORD
   cbSize              AS DWORD          ' DWORD
   dwFlags             AS DWORD          ' DWORD
   guidScheme          AS GUID           ' GUID
   szIdentifier        AS WSTRINGZ PTR   ' LPCWSTR
   szNonCannonicalData AS WSTRINGZ PTR   ' LPCWSTR
END TYPE


' ########################################################################################
' IAssemblyName interface
' IID = CD193BC0-B4BC-11D2-9833-00C04FC31D2E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyName_INTERFACE_DEFINED)
    %IAssemblyName_INTERFACE_DEFINED = 1

$IID_IAssemblyName = GUID$("{CD193BC0-B4BC-11D2-9833-00C04FC31D2E}")

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
%ASM_NAME_MAX_PARAMS            = %ASM_NAME_MVID                  + 1

' enum ASM_BIND_FLAGS
%ASM_BINDF_FORCE_CACHE_INSTALL = &H1
%ASM_BINDF_RFS_INTEGRITY_CHECK = &H2
%ASM_BINDF_RFS_MODULE_CHECK    = &H4
%ASM_BINDF_BINPATH_PROBE_ONLY  = &H8
%ASM_BINDF_SHARED_BINPATH_HINT = &H10
%ASM_BINDF_PARENT_ASM_HINT     = &H20

' enum ASM_DISPLAY_FLAGS
%ASM_DISPLAYF_VERSION               = &H1
%ASM_DISPLAYF_CULTURE               = &H2
%ASM_DISPLAYF_PUBLIC_KEY_TOKEN      = &H4
%ASM_DISPLAYF_PUBLIC_KEY            = &H8
%ASM_DISPLAYF_CUSTOM                = &H10
%ASM_DISPLAYF_PROCESSORARCHITECTURE = &H20
%ASM_DISPLAYF_LANGUAGEID            = &H40

' enum ASM_CMP_FLAGS
%ASM_CMPF_NAME             = &H1
%ASM_CMPF_MAJOR_VERSION    = &H2
%ASM_CMPF_MINOR_VERSION    = &H4
%ASM_CMPF_BUILD_NUMBER     = &H8
%ASM_CMPF_REVISION_NUMBER  = &H10
%ASM_CMPF_PUBLIC_KEY_TOKEN = &H20
%ASM_CMPF_CULTURE          = &H40
%ASM_CMPF_CUSTOM           = &H80
%ASM_CMPF_ALL              = (((((((%ASM_CMPF_NAME OR %ASM_CMPF_MAJOR_VERSION) OR %ASM_CMPF_MINOR_VERSION) OR %ASM_CMPF_REVISION_NUMBER) OR %ASM_CMPF_BUILD_NUMBER) OR %ASM_CMPF_PUBLIC_KEY_TOKEN) OR %ASM_CMPF_CULTURE) OR %ASM_CMPF_CUSTOM)
%ASM_CMPF_DEFAULT          = &H100

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
   , BYREF pvProperty AS DWORD _                        ' __out LPVOID pvProperty
   , BYREF pcbProperty AS DWORD _                       ' __inout DWORD pcbProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finalize ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF szDisplayName AS WSTRINGZ _                  ' __out LPWSTR szDisplayName
   , BYREF pccDisplayName AS DWORD _                    ' __inout LPDWORD pccDisplayName
   , BYVAL dwDisplayFlags AS DWORD _                    ' __in DWORD dwDisplayFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved ( _                                  ' VTable offset = 28
     BYREF refIID AS GUID _                             ' __in REFIID refIID
   , BYVAL pUnkReserved1 AS IUnknown _                  ' __in IUnknown *pUnkReserved1
   , BYVAL pUnkReserved2 AS IUnknown _                  ' __in IUnknown *pUnkReserved2
   , BYVAL szReserved AS DWORD _                        ' __in LPCOLESTR szReserved
   , BYVAL llReserved AS QUAD _                         ' __in LONGLONG llReserved
   , BYVAL pvReserved AS DWORD _                        ' __in LPVOID pvReserved
   , BYVAL cbReserved AS DWORD _                        ' __in DWORD cbReserved
   , BYREF ppReserved AS DWORD _                        ' __out LPVOID *ppReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 32
     BYREF lpcwBuffer AS DWORD _                        ' __inout LPDWORD lpcwBuffer
   , BYREF pwzName AS WSTRINGZ _                        ' __out LPWSTR pwzName
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
' IAssemblyCacheItem interface
' IID = 9E3AAEB4-D1CD-11D2-BAB9-00C04F8ECEAE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyCacheItem_INTERFACE_DEFINED)
    %IAssemblyCacheItem_INTERFACE_DEFINED = 1

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
   , BYREF puliMaxSize AS QUAD _                        ' __opt_out ULARGE_INTEGER *puliMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pulDisposition AS DWORD _                    ' __opt_out ULONG *pulDisposition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortItem ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssemblyCacheItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IAssemblyCache interface
' IID = E707DCDE-D1CD-11D2-BAB9-00C04F8ECEAE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssemblyCache_INTERFACE_DEFINED)
    %IAssemblyCache_INTERFACE_DEFINED = 1

$IID_IAssemblyCache = GUID$("{E707DCDE-D1CD-11D2-BAB9-00C04F8ECEAE}")

INTERFACE IAssemblyCache $IID_IAssemblyCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UninstallAssembly ( _                         ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszAssemblyName AS WSTRINGZ _                ' __in LPCWSTR pszAssemblyName
   , BYREF pRefData AS FUSION_INSTALL_REFERENCE _       ' __in LPCFUSION_INSTALL_REFERENCE pRefData
   , BYREF pulDisposition AS DWORD _                    ' __opt_out ULONG *pulDisposition
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
   , BYREF pszAssemblyName AS WSTRINGZ _                ' __opt_in LPCWSTR pszAssemblyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reserved ( _                                  ' VTable offset = 24
     BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
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


' enum CREATE_ASM_NAME_OBJ_FLAGS
%CANOF_PARSE_DISPLAY_NAME   = &H1???
%CANOF_SET_DEFAULT_VALUES   = &H2???

DECLARE FUNCTION CreateAssemblyNameObject IMPORT "Sxs.dll" ALIAS "CreateAssemblyNameObject" ( _
   BYREF ppAssemblyNameObj AS IAssemblyName _           ' __out LPASSEMBLYNAME *ppAssemblyNameObj
 , BYREF szAssemblyName AS WSTRINGZ _                   ' __in LPCWSTR szAssemblyName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateAssemblyCache IMPORT "Sxs.dll" ALIAS "CreateAssemblyCache" ( _
   BYREF ppAsmCache AS IAssemblyCache _                 ' __out IAssemblyCache **ppAsmCache
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

#ENDIF   ' #IF NOT %DEF(%LPFUSION_DEFINED)
