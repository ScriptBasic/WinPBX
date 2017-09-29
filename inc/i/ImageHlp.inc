' ########################################################################################
' Microsoft Windows
' File: imagehlp.inc
' Contents: Prototypes and constants required for the image help routines
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Make sure DbgHelp.inc is not included.
#IF NOT %DEF(%DBGHELP_INC)

#IF NOT %DEF(%IMAGEHLP_INC)
    %IMAGEHLP_INC = 1

'#if _MSC_VER > 1020
'#pragma once
'#endif


'// As a general principal always call the 64 bit version
'// of every API, if a choice exists.  The 64 bit version
'// works great on 32 bit platforms, and is forward
'// compatible to 64 bit platforms.

'#ifdef _WIN64
'#ifndef _IMAGEHLP64
'#define _IMAGEHLP64
'#endif
'#endif

'// For those without specstrings.h
'// Since there are different versions of this header, I need to
'// individually test each item and define it if it is not around.

'#ifndef __in
' #define __in
'#endif
'#ifndef __out
' #define __out
'#endif
'#ifndef __inout
' #define __inout
'#endif
'#ifndef __in_opt
' #define __in_opt
'#endif
'#ifndef __out_opt
' #define __out_opt
'#endif
'#ifndef __inout_opt
' #define __inout_opt
'#endif
'#ifndef __in_ecount
' #define __in_ecount(x)
'#endif
'#ifndef __out_ecount
' #define __out_ecount(x)
'#endif
'#ifndef __inout_ecount
' #define __inout_ecount(x)
'#endif
'#ifndef __in_bcount
' #define __in_bcount(x)
'#endif
'#ifndef __out_bcount
' #define __out_bcount(x)
'#endif
'#ifndef __inout_bcount
' #define __inout_bcount(x)
'#endif
'#ifndef __out_xcount
' #define __out_xcount(x)
'#endif
'#ifndef __deref_opt_out
' #define __deref_opt_out
'#endif
'#ifndef __deref_out
' #define __deref_out
'#endif
'#ifndef __out_ecount_opt
' #define __out_ecount_opt(x)
'#endif
'#ifndef __in_bcount_opt
' #define __in_bcount_opt(x)
'#endif
'#ifndef __out_bcount_opt
' #define __out_bcount_opt(x)
'#endif
'#ifndef __deref_out_opt
' #define __deref_out_opt
'#endif

'#ifndef WINTRUST_H
'#include <wintrust.h>
'#endif

#INCLUDE ONCE "wintrust.inc"

'#ifdef __cplusplus
'extern "C" {
'#endif

'#ifdef _IMAGEHLP_SOURCE_
' #define IMAGEAPI __stdcall
' #define DBHLP_DEPRECIATED
'#else
' #define IMAGEAPI DECLSPEC_IMPORT __stdcall
' #if (_MSC_VER >= 1300) && !defined(MIDL_PASS)
'  #define DBHLP_DEPRECIATED   __declspec(deprecated)
' #else
'  #define DBHLP_DEPRECIATED
' #endif
'#endif

'#define DBHLPAPI IMAGEAPI

%IMAGE_SEPARATION = 64*1024

'// Observant readers may notice that 2 new fields,
'// 'fReadOnly' and 'Version' have been added to
'// the LOADED_IMAGE structure after 'fDOSImage'.
'// This does not change the size of the structure
'// from previous headers.  That is because while
'// 'fDOSImage' is a byte, it is padded by the
'// compiler to 4 bytes.  So the 2 new fields are
'// slipped into the extra space.

'typedef struct _LOADED_IMAGE {
'    PSTR                  ModuleName;
'    HANDLE                hFile;
'    PUCHAR                MappedAddress;
'#ifdef _IMAGEHLP64
'    PIMAGE_NT_HEADERS64   FileHeader;
'#else
'    PIMAGE_NT_HEADERS32   FileHeader;
'#endif
'    PIMAGE_SECTION_HEADER LastRvaSection;
'    ULONG                 NumberOfSections;
'    PIMAGE_SECTION_HEADER Sections;
'    ULONG                 Characteristics;
'    BOOLEAN               fSystemImage;
'    BOOLEAN               fDOSImage;
'    BOOLEAN               fReadOnly;
'    UCHAR                 Version;
'    LIST_ENTRY            Links;
'    ULONG                 SizeOfImage;
'} LOADED_IMAGE, *PLOADED_IMAGE;

' // Size = 48 bytes
TYPE LOADED_IMAGE BYTE
   ModuleName       AS ASCIIZ PTR                 ' PSTR
   hFile            AS DWORD                      ' HANDLE
   MappedAddress    AS BYTE PTR                   ' PUCHAR
   FileHeader       AS IMAGE_NT_HEADERS PTR       ' PIMAGE_NT_HEADERS32
   LastRvaSection   AS IMAGE_SECTION_HEADER PTR   ' PIMAGE_SECTION_HEADER
   NumberOfSections AS DWORD                      ' ULONG
   Sections         AS IMAGE_SECTION_HEADER PTR   ' PIMAGE_SECTION_HEADER
   Characteristics  AS DWORD                      ' ULONG
   fSystemImage     AS BYTE                       ' BOOLEAN
   fDOSImage        AS BYTE                       ' BOOLEAN
   fReadOnly        AS BYTE                       ' BOOLEAN
   Version          AS BYTE                       ' UCHAR
   Links            AS LIST_ENTRY                 ' LIST_ENTRY
   SizeOfImage      AS DWORD                      ' ULONG
END TYPE

%MAX_SYM_NAME           = 2000

DECLARE FUNCTION BindImage IMPORT "ImageHlp.dll" ALIAS "BindImage" ( _
   BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
 , BYREF DllPath AS ASCIIZ _                            ' __in PCSTR DllPath
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 ) AS LONG                                              ' BOOL

' enum IMAGEHLP_STATUS_REASON
%BindOutOfMemory           = 0???
%BindRvaToVaFailed         = 1???
%BindNoRoomInImage         = 2???
%BindImportModuleFailed    = 3???
%BindImportProcedureFailed = 4???
%BindImportModule          = 5???
%BindImportProcedure       = 6???
%BindForwarder             = 7???
%BindForwarderNOT          = 8???
%BindImageModified         = 9???
%BindExpandFileHeaders     = 10???
%BindImageComplete         = 11???
%BindMismatchedSymbols     = 12???
%BindSymbolsNotUpdated     = 13???
%BindImportProcedure32     = 14???
%BindImportProcedure64     = 15???
%BindForwarder32           = 16???
%BindForwarder64           = 17???
%BindForwarderNOT32        = 18???
%BindForwarderNOT64        = 19???

'typedef
'BOOL
'(__stdcall *PIMAGEHLP_STATUS_ROUTINE)(
'    __in IMAGEHLP_STATUS_REASON Reason,
'    __in PCSTR ImageName,
'    __in PCSTR DllName,
'    __in ULONG_PTR Va,
'    __in ULONG_PTR Parameter
'    );

'FUNCTION IMAGEHLP_STATUS_ROUTINE ( _
'   BYVAL Reason AS DWORD _                              ' __in IMAGEHLP_STATUS_REASON Reason
' , BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
' , BYREF DllName AS ASCIIZ _                            ' __in PCSTR DllName
' , BYVAL Va AS DWORD _                                  ' __in ULONG_PTR Va
' , BYVAL Parameter AS DWORD _                           ' __in ULONG_PTR Parameter
' ) AS LONG                                              ' BOOL

'typedef
'BOOL
'(__stdcall *PIMAGEHLP_STATUS_ROUTINE32)(
'    __in IMAGEHLP_STATUS_REASON Reason,
'    __in PCSTR ImageName,
'    __in PCSTR DllName,
'    __in ULONG Va,
'    __in ULONG_PTR Parameter
'    );

'FUNCTION IMAGEHLP_STATUS_ROUTINE32 ( _
'   BYVAL Reason AS DWORD _                              ' __in IMAGEHLP_STATUS_REASON Reason
' , BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
' , BYREF DllName AS ASCIIZ _                            ' __in PCSTR DllName
' , BYVAL Va AS DWORD _                                  ' __in ULONG_PTR Va
' , BYVAL Parameter AS DWORD _                           ' __in ULONG_PTR Parameter
' ) AS LONG                                              ' BOOL

'typedef
'BOOL
'(__stdcall *PIMAGEHLP_STATUS_ROUTINE64)(
'    __in IMAGEHLP_STATUS_REASON Reason,
'    __in PCSTR ImageName,
'    __in PCSTR DllName,
'    __in ULONG64 Va,
'    __in ULONG_PTR Parameter
'    );

'FUNCTION IMAGEHLP_STATUS_ROUTINE64 ( _
'   BYVAL Reason AS DWORD _                              ' __in IMAGEHLP_STATUS_REASON Reason
' , BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
' , BYREF DllName AS ASCIIZ _                            ' __in PCSTR DllName
' , BYVAL Va AS QUAD _                                   ' __in ULONG64 Va
' , BYVAL Parameter AS DWORD _                           ' __in ULONG_PTR Parameter
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION BindImageEx IMPORT "ImageHlp.dll" ALIAS "BindImageEx" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
 , BYREF DllPath AS ASCIIZ _                            ' __in PCSTR DllPath
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , OPTIONAL BYVAL StatusRoutine AS DWORD _              ' __in_opt PIMAGEHLP_STATUS_ROUTINE StatusRoutine
 ) AS LONG                                              ' BOOL

%BIND_NO_BOUND_IMPORTS  = &H00000001???
%BIND_NO_UPDATE         = &H00000002???
%BIND_ALL_IMAGES        = &H00000004???
%BIND_CACHE_IMPORT_DLLS = &H00000008???      ' // Cache dll's across
                                             ' //  calls to BindImageEx
                                             ' //  (same as NT 3.1->NT 4.0)
%BIND_REPORT_64BIT_VA   = &H00000010???

DECLARE FUNCTION ReBaseImage IMPORT "ImageHlp.dll" ALIAS "ReBaseImage" ( _
   BYREF CurrentImageName AS ASCIIZ _                   ' __in PCSTR CurrentImageName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYVAL fReBase AS LONG _                              ' __in BOOL  fReBase               ' // TRUE if actually rebasing, false if only summing
 , BYVAL fRebaseSysfileOk AS LONG _                     ' __in BOOL  fRebaseSysfileOk      ' // TRUE is system images s/b rebased
 , BYVAL fGoingDown AS LONG _                           ' __in BOOL  fGoingDown            ' // TRUE if the image s/b rebased below the given base
 , BYVAL CheckImageSize AS DWORD _                      ' __in ULONG CheckImageSize        ' // Max size allowed  (0 if don't care)
 , BYREF OldImageSize AS DWORD _                        ' __out ULONG *OldImageSize        ' // Returned from the header
 , BYREF OldImageBase AS DWORD _                        ' __out ULONG_PTR *OldImageBase    ' // Returned from the header
 , BYREF NewImageSize AS DWORD _                        ' __out ULONG *NewImageSize        ' // Image size rounded to next separation boundary
 , BYREF NewImageBase AS DWORD _                        ' __inout ULONG_PTR *NewImageBase  ' // (in) Desired new address, (out) Next address (actual if going down)
 , BYVAL TimeStamp AS DWORD _                           ' __in ULONG TimeStamp             ' // new timestamp for image, if non-zero
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReBaseImage64 IMPORT "ImageHlp.dll" ALIAS "ReBaseImage64" ( _
   BYREF CurrentImageName AS ASCIIZ _                   ' __in PCSTR CurrentImageName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYVAL fReBase AS LONG _                              ' __in BOOL  fReBase               ' // TRUE if actually rebasing, false if only summing
 , BYVAL fRebaseSysfileOk AS LONG _                     ' __in BOOL  fRebaseSysfileOk      ' // TRUE is system images s/b rebased
 , BYVAL fGoingDown AS LONG _                           ' __in BOOL  fGoingDown            ' // TRUE if the image s/b rebased below the given base
 , BYVAL CheckImageSize AS DWORD _                      ' __in ULONG CheckImageSize        ' // Max size allowed  (0 if don't care)
 , BYREF OldImageSize AS DWORD _                        ' __out ULONG *OldImageSize        ' // Returned from the header
 , BYREF OldImageBase AS QUAD _                         ' __out ULONG64 *OldImageBase      ' // Returned from the header
 , BYREF NewImageSize AS DWORD _                        ' __out ULONG *NewImageSize        ' // Image size rounded to next separation boundary
 , BYREF NewImageBase AS QUAD _                         ' __inout ULONG64 *NewImageBase    ' // (in) Desired new address, (out) Next address (actual if going down)
 , BYVAL TimeStamp AS DWORD _                           ' __in ULONG TimeStamp             ' // new timestamp for image, if non-zero
 ) AS LONG                                              ' BOOL

'//
'// Define checksum return codes.
'//

%CHECKSUM_SUCCESS         = 0
%CHECKSUM_OPEN_FAILURE    = 1
%CHECKSUM_MAP_FAILURE     = 2
%CHECKSUM_MAPVIEW_FAILURE = 3
%CHECKSUM_UNICODE_FAILURE = 4

'// Define Splitsym flags.

%SPLITSYM_REMOVE_PRIVATE     = &H00000001???       ' // Remove CV types/symbols and Fixup debug
                                                   ' //  Used for creating .dbg files that ship
                                                   ' //  as part of the product.

%SPLITSYM_EXTRACT_ALL        = &H00000002???       ' // Extract all debug info from image.
                                                   ' //  Normally, FPO is left in the image
                                                   ' //  to allow stack traces through the code.
                                                   ' //  Using this switch is similar to linking
                                                   ' //  with -debug:none except the .dbg file
                                                   ' //  exists...

%SPLITSYM_SYMBOLPATH_IS_SRC  = &H00000004???       ' // The SymbolFilePath contains an alternate
                                                   ' //  path to locate the pdb.


'//
'// Define checksum function prototypes.
'//

DECLARE FUNCTION CheckSumMappedFile IMPORT "ImageHlp.dll" ALIAS "CheckSumMappedFile" ( _
   BYVAL BaseAddress AS DWORD _                         ' __in PVOID BaseAddress
 , BYVAL FileLength AS DWORD _                          ' __in DWORD FileLength
 , BYREF HeaderSum AS DWORD _                           ' __out PDWORD HeaderSum
 , BYREF CheckSum AS DWORD _                            ' __out PDWORD CheckSum
 ) AS DWORD                                             ' PIMAGE_NT_HEADERS

DECLARE FUNCTION MapFileAndCheckSumA IMPORT "ImageHlp.dll" ALIAS "MapFileAndCheckSumA" ( _
   BYREF Filename AS ASCIIZ _                           ' __in PCSTR Filename
 , BYREF HeaderSum AS DWORD _                           ' __out PDWORD HeaderSum
 , BYREF CheckSum AS DWORD _                            ' __out PDWORD CheckSum
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MapFileAndCheckSumW IMPORT "ImageHlp.dll" ALIAS "MapFileAndCheckSumW" ( _
   BYREF Filename AS WSTRINGZ _                         ' __in PCWSTR Filename
 , BYREF HeaderSum AS DWORD _                           ' __out PDWORD HeaderSum
 , BYREF CheckSum AS DWORD _                            ' __out PDWORD CheckSum
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO MapFileAndCheckSum  = MapFileAndCheckSumW
#ELSE
   MACRO MapFileAndCheckSum  = MapFileAndCheckSumA
#ENDIF

DECLARE FUNCTION GetImageConfigInformation IMPORT "ImageHlp.dll" ALIAS "GetImageConfigInformation" ( _
   BYREF LoadedImage AS LOADED_IMAGE _                  ' __in PLOADED_IMAGE LoadedImage
 , BYREF ImageConfigInformation AS IMAGE_LOAD_CONFIG_DIRECTORY _ ' __out PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetImageUnusedHeaderBytes IMPORT "ImageHlp.dll" ALIAS "GetImageUnusedHeaderBytes" ( _
   BYREF LoadedImage AS LOADED_IMAGE _                  ' __in PLOADED_IMAGE LoadedImage
 , BYREF SizeUnusedHeaderBytes AS DWORD _               ' __out PDWORD SizeUnusedHeaderBytes
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetImageConfigInformation IMPORT "ImageHlp.dll" ALIAS "SetImageConfigInformation" ( _
   BYREF LoadedImage AS LOADED_IMAGE _                  ' __in PLOADED_IMAGE LoadedImage
 , BYREF ImageConfigInformation AS IMAGE_LOAD_CONFIG_DIRECTORY _ ' __in PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
 ) AS LONG                                              ' BOOL

'// Image Integrity API's

%CERT_PE_IMAGE_DIGEST_DEBUG_INFO       = &H01?
%CERT_PE_IMAGE_DIGEST_RESOURCES        = &H02?
%CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO  = &H04?
%CERT_PE_IMAGE_DIGEST_NON_PE_INFO      = &H08?     ' // include data outside the PE image

%CERT_SECTION_TYPE_ANY                 = &HFF?     ' // Any Certificate type

'typedef PVOID DIGEST_HANDLE;

'typedef BOOL (WINAPI *DIGEST_FUNCTION) (DIGEST_HANDLE refdata, PBYTE pData, DWORD dwLength);

'FUNCTION DIGEST_FUNCTION ( _
'   BYVAL refdata AS DWORD _                 ' DIGEST_HANDLE refdata
' , BYVAL pData AS BYTE PTR _                ' PBYTE pData
' , BYVAL dwLength AS DWORD _                ' DWORD dwLength
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageGetDigestStream IMPORT "ImageHlp.dll" ALIAS "ImageGetDigestStream" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL DigestLevel AS DWORD _                         ' __in DWORD DigestLevel
 , BYVAL DigestFunction AS DWORD _                      ' __in DIGEST_FUNCTION DigestFunction
 , BYVAL DigestHandle AS DWORD _                        ' __in DIGEST_HANDLE DigestHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageAddCertificate IMPORT "ImageHlp.dll" ALIAS "ImageAddCertificate" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYREF Certificate AS WIN_CERTIFICATE _               ' __in LPWIN_CERTIFICATE Certificate
 , BYREF Index AS DWORD _                               ' __out PDWORD Index
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageRemoveCertificate IMPORT "ImageHlp.dll" ALIAS "ImageRemoveCertificate" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL Index AS DWORD _                               ' __in DWORD Index
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageEnumerateCertificates IMPORT "ImageHlp.dll" ALIAS "ImageEnumerateCertificates" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL TypeFilter AS WORD _                           ' __in WORD TypeFilter
 , BYREF CertificateCount AS DWORD _                    ' __out PDWORD CertificateCount
 , BYREF Indices AS DWORD _                             ' __inout PDWORD Indices
 , OPTIONAL BYVAL IndexCount AS DWORD _                 ' __in_opt DWORD IndexCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageGetCertificateData IMPORT "ImageHlp.dll" ALIAS "ImageGetCertificateData" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL CertificateIndex AS DWORD _                    ' __in DWORD CertificateIndex
 , BYREF Certificate AS WIN_CERTIFICATE _               ' __out LPWIN_CERTIFICATE Certificate
 , BYREF RequiredLength AS DWORD _                      ' __inout PDWORD RequiredLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageGetCertificateHeader IMPORT "ImageHlp.dll" ALIAS "ImageGetCertificateHeader" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , BYVAL CertificateIndex AS DWORD _                    ' __in DWORD CertificateIndex
 , BYREF Certificate AS WIN_CERTIFICATE _               ' __inout LPWIN_CERTIFICATE Certificate
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageLoad IMPORT "ImageHlp.dll" ALIAS "ImageLoad" ( _
   BYREF DllName AS ASCIIZ _                            ' __in PCSTR DllName
 , OPTIONAL BYREF DllPath AS ASCIIZ _                   ' __in_opt PCSTR DllPath
 ) AS DWORD                                             ' PLOADED_IMAGE

DECLARE FUNCTION ImageUnload IMPORT "ImageHlp.dll" ALIAS "ImageUnload" ( _
   BYREF LoadedImage AS LOADED_IMAGE _                  ' __inout PLOADED_IMAGE LoadedImage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MapAndLoad IMPORT "ImageHlp.dll" ALIAS "MapAndLoad" ( _
   BYREF ImageName AS ASCIIZ _                          ' __in PCSTR ImageName
 , BYREF DllPath AS ASCIIZ _                            ' __in_opt PCSTR DllPath
 , BYREF LoadedImage AS LOADED_IMAGE _                  ' __out PLOADED_IMAGE LoadedImage
 , BYVAL DotDll AS LONG _                               ' __in BOOL DotDll
 , BYVAL ReadOnly AS LONG _                             ' __in BOOL ReadOnly
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnMapAndLoad IMPORT "ImageHlp.dll" ALIAS "UnMapAndLoad" ( _
   BYREF LoadedImage AS LOADED_IMAGE _                  ' __inout PLOADED_IMAGE LoadedImage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TouchFileTimes IMPORT "ImageHlp.dll" ALIAS "TouchFileTimes" ( _
   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
 , OPTIONAL BYREF pSystemTime AS SYSTEMTIME _           ' __in_opt PSYSTEMTIME pSystemTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SplitSymbols IMPORT "ImageHlp.dll" ALIAS "SplitSymbols" ( _
   BYREF ImageName AS ASCIIZ _                          ' __inout PSTR ImageName
 , BYREF SymbolsPath AS ASCIIZ _                        ' __in PCSTR SymbolsPath
 , BYREF SymbolFilePath AS ASCIIZ _                     ' __inout PSTR SymbolFilePath
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UpdateDebugInfoFile IMPORT "ImageHlp.dll" ALIAS "UpdateDebugInfoFile" ( _
   BYREF ImageFileName AS ASCIIZ _                      ' __in PCSTR ImageFileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF DebugFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR DebugFilePath
 , BYREF NtHeaders AS IMAGE_NT_HEADERS _                ' __in PIMAGE_NT_HEADERS32 NtHeaders
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UpdateDebugInfoFileEx IMPORT "ImageHlp.dll" ALIAS "UpdateDebugInfoFileEx" ( _
   BYREF ImageFileName AS ASCIIZ _                      ' __in PCSTR ImageFileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF DebugFilePath AS ASCIIZ _                      ' __out PSTR DebugFilePath
 , BYREF NtHeaders AS IMAGE_NT_HEADERS _                ' __in PIMAGE_NT_HEADERS32 NtHeaders
 , BYVAL OldCheckSum AS DWORD _                         ' __in DWORD OldCheckSum
 ) AS LONG                                              ' BOOL


'// Error codes set by dbghelp functions.  Call GetLastError
'// to see them.
'// Dbghelp also sets error codes found in winerror.h

%ERROR_IMAGE_NOT_STRIPPED    = &H8800&  ' // the image is not stripped.  No dbg file available.
%ERROR_NO_DBG_POINTER        = &H8801&  ' // image is stripped but there is no pointer to a dbg file
%ERROR_NO_PDB_POINTER        = &H8802&  ' // image does not point to a pdb file

'typedef BOOL
'(CALLBACK *PFIND_DEBUG_FILE_CALLBACK)(
'    __in HANDLE FileHandle,
'    __in PCSTR FileName,
'    __in PVOID CallerData
'    );

'FUNCTION FIND_DEBUG_FILE_CALLBACK ( _
'   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
' , BYREF szFileName AS ASCIIZ _                         ' __in PCSTR FileName
' , BYVAL CallerData AS DWORD _                          ' __in PVOID CallerData
' ) AS LONG                                              ' BOOL

' Requires version 6.6 or later.
DECLARE FUNCTION SymFindDebugInfoFile IMPORT "ImageHlp.dll" ALIAS "SymFindDebugInfoFile" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF DebugFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR DebugFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_DEBUG_FILE_CALLBACK Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

'typedef BOOL
'(CALLBACK *PFIND_DEBUG_FILE_CALLBACKW)(
'    __in HANDLE FileHandle,
'    __in PCWSTR FileName,
'    __in PVOID  CallerData
'    );

'FUNCTION FIND_DEBUG_FILE_CALLBACKW ( _
'   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
' , BYREF wszFileName AS WSTRINGZ _                      ' __in PCWSTR FileName
' , BYVAL CallerData AS DWORD _                          ' __in PVOID CallerData
' ) AS LONG                                              ' BOOL

' Requires version 6.6 or later
DECLARE FUNCTION SymFindDebugInfoFileW IMPORT "ImageHlp.dll" ALIAS "SymFindDebugInfoFileW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF DebugFilePath AS DWORD _                       ' __out_ecount(MAX_PATH + 1) PWSTR DebugFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_DEBUG_FILE_CALLBACK Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindDebugInfoFile IMPORT "ImageHlp.dll" ALIAS "FindDebugInfoFile" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF DebugFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR DebugFilePath
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindDebugInfoFileEx IMPORT "ImageHlp.dll" ALIAS "FindDebugInfoFileEx" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF DebugFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR DebugFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_DEBUG_FILE_CALLBACK Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

' Does not exist.
DECLARE FUNCTION FindDebugInfoFileExW IMPORT "ImageHlp.dll" ALIAS "FindDebugInfoFileExW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF SymbolPath AS WSTRINGZ _                       ' __in PCWSTR SymbolPath
 , BYREF DebugFilePath AS DWORD _                       ' __out_ecount(MAX_PATH + 1) PWSTR DebugFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_DEBUG_FILE_CALLBACKW Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

'typedef BOOL
'(CALLBACK *PFINDFILEINPATHCALLBACK)(
'    PCSTR filename,
'    PVOID context
'    );

'FUNCTION FINDFILEINPATHCALLBACK ( _
'   BYREF szFileName AS ASCIIZ _                         ' PCSTR filename
' , BYVAL context AS DWORD _                             ' PVOID context
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFindFileInPath IMPORT "ImageHlp.dll" ALIAS "SymFindFileInPath" ( _
   BYVAL hprocess AS DWORD _                            ' __in HANDLE hprocess
 , BYREF SearchPath AS ASCIIZ _                         ' __in_opt PCSTR SearchPath
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYVAL id AS DWORD _                                  ' __in_opt PVOID id
 , BYVAL two AS DWORD _                                 ' __in DWORD two
 , BYVAL three AS DWORD _                               ' __in DWORD three
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF FoundFile AS ASCIIZ _                          ' __out_ecount(MAX_PATH + 1) PSTR FoundFile
 , OPTIONAL BYVAL callback AS DWORD _                   ' __in_opt PFINDFILEINPATHCALLBACK callback
 , OPTIONAL BYVAL context AS DWORD _                    ' __in_opt PVOID context
 ) AS LONG                                              ' BOOL


'typedef BOOL
'(CALLBACK *PFINDFILEINPATHCALLBACKW)(
'    __in PCWSTR filename,
'    __in PVOID context
'    );

'FUNCTION FINDFILEINPATHCALLBACKW ( _
'   BYREF wszFileName AS WSTRINGZ _                      ' PCWSTR filename
' , BYVAL context AS DWORD _                             ' PVOID context
' ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymFindFileInPathW IMPORT "ImageHlp.dll" ALIAS "SymFindFileInPathW" ( _
   BYVAL hprocess AS DWORD _                            ' __in HANDLE hprocess
 , BYREF SearchPath AS WSTRINGZ _                       ' __in_opt PCWSTR SearchPath
 , BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYVAL id AS DWORD _                                  ' __in_opt PVOID id
 , BYVAL two AS DWORD _                                 ' __in DWORD two
 , BYVAL three AS DWORD _                               ' __in DWORD three
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF FoundFile AS DWORD _                           ' __out_ecount(MAX_PATH + 1) PWSTR FoundFile
 , OPTIONAL BYVAL callback AS DWORD _                   ' __in_opt PFINDFILEINPATHCALLBACKW callback
 , OPTIONAL BYVAL context AS DWORD _                    ' __in_opt PVOID context
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PFIND_EXE_FILE_CALLBACK)(
'    __in HANDLE FileHandle,
'    __in PCSTR FileName,
'    __in_opt PVOID CallerData
'    );

'FUNCTION FIND_EXE_FILE_CALLBACK ( _
'   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
' , BYREF szFileName AS ASCIIZ _                         ' __in PCSTR FileName
' , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
' ) AS LONG                                              ' BOOL


' Requires version 6.6 or later.
DECLARE FUNCTION SymFindExecutableImageA IMPORT "ImageHlp.dll" ALIAS "SymFindExecutableImage" ( _
   BYVAL hprocess AS DWORD _                            ' __in HANDLE hprocess
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF ImageFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR ImageFilePath
 , BYVAL Callback AS DWORD _                            ' __in PFIND_EXE_FILE_CALLBACK Callback
 , BYVAL CallerData AS DWORD _                          ' __in PVOID CallerData
 ) AS DWORD                                             ' HANDLE

'typedef BOOL
'(CALLBACK *PFIND_EXE_FILE_CALLBACKW)(
'    __in HANDLE FileHandle,
'    __in PCWSTR FileName,
'    __in_opt PVOID CallerData
'    );

'FUNCTION FIND_EXE_FILE_CALLBACKW ( _
'   BYVAL FileHandle AS DWORD _                          ' __in HANDLE FileHandle
' , BYREF wszFileName AS WSTRINGZ _                      ' __in PCWSTR FileName
' , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
' ) AS LONG                                              ' BOOL

' Requires version 6.6 or later.
DECLARE FUNCTION SymFindExecutableImageW IMPORT "ImageHlp.dll" ALIAS "SymFindExecutableImageW" ( _
   BYVAL hprocess AS DWORD _                            ' __in HANDLE hprocess
 , BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF ImageFilePath AS DWORD _                       ' __out_ecount(MAX_PATH + 1) PWSTR ImageFilePath
 , BYVAL Callback AS DWORD _                            ' __in PFIND_EXE_FILE_CALLBACKW Callback
 , BYVAL CallerData AS DWORD _                          ' __in PVOID CallerData
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindExecutableImage IMPORT "ImageHlp.dll" ALIAS "FindExecutableImage" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF ImageFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR ImageFilePath
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindExecutableImageEx IMPORT "ImageHlp.dll" ALIAS "FindExecutableImageEx" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in PCSTR SymbolPath
 , BYREF ImageFilePath AS ASCIIZ _                      ' __out_ecount(MAX_PATH + 1) PSTR ImageFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_EXE_FILE_CALLBACK Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

' Does not exist.
DECLARE FUNCTION FindExecutableImageExW IMPORT "ImageHlp.dll" ALIAS "FindExecutableImageExW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF SymbolPath AS WSTRINGZ _                       ' __in PCWSTR SymbolPath
 , BYREF ImageFilePath AS WSTRINGZ _                    ' __out_ecount(MAX_PATH + 1) PWSTR ImageFilePath
 , OPTIONAL BYVAL Callback AS DWORD _                   ' __in_opt PFIND_EXE_FILE_CALLBACKW Callback
 , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION ImageNtHeader IMPORT "ImageHlp.dll" ALIAS "ImageNtHeader" ( _
   BYVAL Base AS DWORD _                                ' __in PVOID Base
 ) AS DWORD                                             ' PIMAGE_NT_HEADERS

DECLARE FUNCTION ImageDirectoryEntryToDataEx IMPORT "ImageHlp.dll" ALIAS "ImageDirectoryEntryToDataEx" ( _
   BYVAL Base AS DWORD _                                ' __in PVOID Base
 , BYVAL MappedAsImage AS BYTE _                        ' __in BOOLEAN MappedAsImage
 , BYVAL DirectoryEntry AS WORD _                       ' __in USHORT DirectoryEntry
 , BYREF Size AS DWORD _                                ' __out PULONG Size
 , OPTIONAL BYREF FoundHeader AS IMAGE_SECTION_HEADER _ ' __out_opt PIMAGE_SECTION_HEADER *FoundHeader
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION ImageDirectoryEntryToData IMPORT "ImageHlp.dll" ALIAS "ImageDirectoryEntryToData" ( _
   BYVAL Base AS DWORD _                                ' __in PVOID Base
 , BYVAL MappedAsImage AS BYTE _                        ' __in BOOLEAN MappedAsImage
 , BYVAL DirectoryEntry AS WORD _                       ' __in USHORT DirectoryEntry
 , BYREF Size AS DWORD _                                ' __out PULONG Size
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION ImageRvaToSection IMPORT "ImageHlp.dll" ALIAS "ImageRvaToSection" ( _
   BYREF NtHeaders AS IMAGE_NT_HEADERS _                ' __in PIMAGE_NT_HEADERS NtHeaders
 , BYVAL Base AS DWORD _                                ' __in PVOID Base
 , BYVAL Rva AS DWORD _                                 ' __in ULONG Rva
 ) AS DWORD                                             ' PIMAGE_SECTION_HEADER

DECLARE FUNCTION ImageRvaToVa IMPORT "ImageHlp.dll" ALIAS "ImageRvaToVa" ( _
   BYREF NtHeaders AS IMAGE_NT_HEADERS _                ' __in PIMAGE_NT_HEADERS NtHeaders
 , BYVAL Base AS DWORD _                                ' __in PVOID Base
 , BYVAL Rva AS DWORD _                                 ' __in ULONG Rva
 , OPTIONAL BYREF LastRvaSection AS IMAGE_SECTION_HEADER _ ' __in_opt OUT PIMAGE_SECTION_HEADER *LastRvaSection
 ) AS DWORD                                             ' PVOID

'#ifndef _WIN64
'// This api won't be ported to Win64 - Fix your code.

' // Size = 128 bytes
TYPE IMAGE_DEBUG_INFORMATION DWORD FILL
   List                                     AS LIST_ENTRY                      ' LIST_ENTRY
   ReservedSize                             AS DWORD                           ' DWORD
   ReservedMappedBase                       AS DWORD                           ' PVOID
   ReservedMachine                          AS WORD                            ' USHORT
   ReservedCharacteristics                  AS WORD                            ' USHORT
   ReservedCheckSum                         AS DWORD                           ' DWORD
   ImageBase                                AS DWORD                           ' DWORD
   SizeOfImage                              AS DWORD                           ' DWORD
   ReservedNumberOfSections                 AS DWORD                           ' DWORD
   ReservedSections                         AS IMAGE_SECTION_HEADER PTR        ' PIMAGE_SECTION_HEADER
   ReservedExportedNamesSize                AS DWORD                           ' DWORD
   ReservedExportedNames                    AS ASCIIZ PTR                      ' PSTR
   ReservedNumberOfFunctionTableEntries     AS DWORD                           ' DWORD
   ReservedFunctionTableEntries             AS IMAGE_FUNCTION_ENTRY PTR        ' PIMAGE_FUNCTION_ENTRY
   ReservedLowestFunctionStartingAddress    AS DWORD                           ' DWORD
   ReservedHighestFunctionEndingAddress     AS DWORD                           ' DWORD
   ReservedNumberOfFpoTableEntries          AS DWORD                           ' DWORD
   ReservedFpoTableEntries                  AS FPO_DATA PTR                    ' PFPO_DATA
   SizeOfCoffSymbols                        AS DWORD                           ' DWORD
   CoffSymbols                              AS IMAGE_COFF_SYMBOLS_HEADER PTR   ' PIMAGE_COFF_SYMBOLS_HEADER
   ReservedSizeOfCodeViewSymbols            AS DWORD                           ' DWORD
   ReservedCodeViewSymbols                  AS DWORD                           ' PVOID
   ImageFilePath                            AS ASCIIZ PTR                      ' PSTR
   ImageFileName                            AS ASCIIZ PTR                      ' PSTR
   ReservedDebugFilePath                    AS ASCIIZ PTR                      ' PSTR
   ReservedTimeDateStamp                    AS DWORD                           ' DWORD
   ReservedRomImage                         AS LONG                            ' BOOL
   ReservedDebugDirectory                   AS IMAGE_DEBUG_DIRECTORY PTR       ' PIMAGE_DEBUG_DIRECTORY
   ReservedNumberOfDebugDirectories         AS DWORD                           ' DWORD
   ReservedOriginalFunctionTableBaseAddress AS DWORD                           ' DWORD
   Reserved(1)                              AS DWORD                           ' DWORD[2]
END TYPE

DECLARE FUNCTION MapDebugInformation IMPORT "ImageHlp.dll" ALIAS "MapDebugInformation" ( _
   BYVAL FileHandle AS DWORD _                          ' __in_opt HANDLE FileHandle
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF SymbolPath AS ASCIIZ _                         ' __in_opt PCSTR SymbolPath
 , BYVAL ImageBase AS DWORD _                           ' __in ULONG ImageBase
 ) AS DWORD                                             ' PIMAGE_DEBUG_INFORMATION

DECLARE FUNCTION UnmapDebugInformation IMPORT "ImageHlp.dll" ALIAS "UnmapDebugInformation" ( _
   BYREF DebugInfo AS IMAGE_DEBUG_INFORMATION _         ' __out_xcount(unknown) PIMAGE_DEBUG_INFORMATION DebugInfo
 ) AS LONG                                              ' BOOL

'#endif

DECLARE FUNCTION SearchTreeForFile IMPORT "ImageHlp.dll" ALIAS "SearchTreeForFile" ( _
   BYREF RootPath AS ASCIIZ _                           ' __in PCSTR RootPath
 , BYREF InputPathName AS ASCIIZ _                      ' __in PCSTR InputPathName
 , BYREF OutputPathBuffer AS ASCIIZ _                   ' __out_ecount(MAX_PATH + 1) PSTR OutputPathBuffer
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SearchTreeForFileW IMPORT "ImageHlp.dll" ALIAS "SearchTreeForFileW" ( _
   BYREF RootPath AS WSTRINGZ _                         ' __in PCWSTR RootPath
 , BYREF InputPathName AS WSTRINGZ _                    ' __in PCWSTR InputPathName
 , BYREF OutputPathBuffer AS WSTRINGZ _                 ' __out_ecount(MAX_PATH + 1) PWSTR OutputPathBuffer
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PENUMDIRTREE_CALLBACK)(
'    __in PCSTR FilePath,
'    __in_opt PVOID CallerData
'    );

'FUNCTION ENUMDIRTREE_CALLBACK ( _
'   BYREF szFilePath AS ASCIIZ _                         ' __in PCSTR FilePath
' , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
' ) AS LONG                                              ' BOOL

' Requries version 6.0 or later.
DECLARE FUNCTION EnumDirTree IMPORT "ImageHlp.dll" ALIAS "EnumDirTree" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF RootPath AS ASCIIZ _                           ' __in PCSTR RootPath
 , BYREF InputPathName AS ASCIIZ _                      ' __in PCSTR InputPathName
 , OPTIONAL BYREF OutputPathBuffer AS ASCIIZ _          ' __out_ecount_opt(MAX_PATH + 1) PSTR OutputPathBuffer
 , OPTIONAL BYVAL cb AS DWORD _                         ' __in_opt PENUMDIRTREE_CALLBACK cb
 , OPTIONAL BYVAL data AS DWORD _                       ' __in_opt PVOID data
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PENUMDIRTREE_CALLBACKW)(
'    __in PCWSTR FilePath,
'    __in_opt PVOID CallerData
'    );

'FUNCTION ENUMDIRTREE_CALLBACKW ( _
'   BYREF wszFilePath AS WSTRINGZ _                      ' __in PCWSTR FilePath
' , OPTIONAL BYVAL CallerData AS DWORD _                 ' __in_opt PVOID CallerData
' ) AS LONG                                              ' BOOL

' Requries version 6.0 or later.
DECLARE FUNCTION EnumDirTreeW IMPORT "ImageHlp.dll" ALIAS "EnumDirTreeW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF RootPath AS WSTRINGZ _                         ' __in PCWSTR RootPath
 , BYREF InputPathName AS WSTRINGZ _                    ' __in PCWSTR InputPathName
 , OPTIONAL BYREF OutputPathBuffer AS WSTRINGZ _        ' __out_ecount_opt(MAX_PATH + 1) PWSTR OutputPathBuffer
 , OPTIONAL BYVAL cb AS DWORD _                         ' __in_opt PENUMDIRTREE_CALLBACK cb
 , OPTIONAL BYVAL data AS DWORD _                       ' __in_opt PVOID data
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MakeSureDirectoryPathExists IMPORT "ImageHlp.dll" ALIAS "MakeSureDirectoryPathExists" ( _
   BYREF DirPath AS ASCIIZ _                            ' __in PCSTR DirPath
 ) AS LONG                                              ' BOOL

'//
'// UnDecorateSymbolName Flags
'//

%UNDNAME_COMPLETE                 = &H0000???  ' // Enable full undecoration
%UNDNAME_NO_LEADING_UNDERSCORES   = &H0001???  ' // Remove leading underscores from MS extended keywords
%UNDNAME_NO_MS_KEYWORDS           = &H0002???  ' // Disable expansion of MS extended keywords
%UNDNAME_NO_FUNCTION_RETURNS      = &H0004???  ' // Disable expansion of return type for primary declaration
%UNDNAME_NO_ALLOCATION_MODEL      = &H0008???  ' // Disable expansion of the declaration model
%UNDNAME_NO_ALLOCATION_LANGUAGE   = &H0010???  ' // Disable expansion of the declaration language specifier
%UNDNAME_NO_MS_THISTYPE           = &H0020???  ' // NYI Disable expansion of MS keywords on the 'this' type for primary declaration
%UNDNAME_NO_CV_THISTYPE           = &H0040???  ' // NYI Disable expansion of CV modifiers on the 'this' type for primary declaration
%UNDNAME_NO_THISTYPE              = &H0060???  ' // Disable all modifiers on the 'this' type
%UNDNAME_NO_ACCESS_SPECIFIERS     = &H0080???  ' // Disable expansion of access specifiers for members
%UNDNAME_NO_THROW_SIGNATURES      = &H0100???  ' // Disable expansion of 'throw-signatures' for functions and pointers to functions
%UNDNAME_NO_MEMBER_TYPE           = &H0200???  ' // Disable expansion of 'static' or 'virtual'ness of members
%UNDNAME_NO_RETURN_UDT_MODEL      = &H0400???  ' // Disable expansion of MS model for UDT returns
%UNDNAME_32_BIT_DECODE            = &H0800???  ' // Undecorate 32-bit decorated names
%UNDNAME_NAME_ONLY                = &H1000???  ' // Crack only the name for primary declaration;
                                                                                                   ' //  return just [scope::]name.  Does expand template params
%UNDNAME_NO_ARGUMENTS             = &H2000???  ' // Don't undecorate arguments to function
%UNDNAME_NO_SPECIAL_SYMS          = &H4000???  ' // Don't undecorate special names (v-table, vcall, vector xxx, metatype, etc???

DECLARE FUNCTION UnDecorateSymbolName IMPORT "ImageHlp.dll" ALIAS "UnDecorateSymbolName" ( _
   BYREF name AS ASCIIZ _                               ' __in PCSTR name
 , BYREF outputString AS ASCIIZ _                       ' __out_ecount(maxStringLength) PSTR outputString
 , BYVAL maxStringLength AS DWORD _                     ' __in DWORD maxStringLength
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 ) AS DWORD                                             ' DWORD

' Does not exist.
DECLARE FUNCTION UnDecorateSymbolNameW IMPORT "ImageHlp.dll" ALIAS "UnDecorateSymbolNameW" ( _
   BYREF name AS WSTRINGZ _                             ' __in PCWSTR name
 , BYREF outputString AS WSTRINGZ _                     ' __out_ecount(maxStringLength) PWSTR outputString
 , BYVAL maxStringLength AS DWORD _                     ' __in DWORD maxStringLength
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 ) AS DWORD                                             ' DWORD

'//
'// these values are used for synthesized file types
'// that can be passed in as image headers instead of
'// the standard ones from ntimage.h
'//

%DBHHEADER_DEBUGDIRS     = &H1???
%DBHHEADER_CVMISC        = &H2???
%DBHHEADER_PDBGUID       = &H3???

' // Size = 20 bytes
TYPE MODLOAD_DATA DWORD
   ssize AS DWORD   ' DWORD // size of this struct
   ssig  AS DWORD   ' DWORD // signature identifying the passed data
   data  AS DWORD   ' PVOID // pointer to passed data
   size  AS DWORD   ' DWORD // size of passed data
   flags AS DWORD   ' DWORD // options
END TYPE

' // Size = 24 bytes
TYPE MODLOAD_CVMISC DWORD
   oCV     AS DWORD   ' DWORD // ofset to the codeview record
   cCV     AS DWORD   ' size_t // size of the codeview record
   oMisc   AS DWORD   ' DWORD // offset to the misc record
   cMisc   AS DWORD   ' size_t // size of the misc record
   dtImage AS DWORD   ' DWORD // datetime stamp of the image
   cImage  AS DWORD   ' DWORD // size of the image
END TYPE

' // Size = 20 bytes
TYPE MODLOAD_PDBGUID_PDBAGE DWORD
   PdbGuid AS GUID    ' GUID // Pdb Guid
   PdbAge  AS DWORD   ' DWORD // Pdb Age
END TYPE

'//
'// StackWalking API
'//

' enum ADDRESS_MODE
%AddrMode1616 = 0??
%AddrMode1632 = 1??
%AddrModeReal = 2??
%AddrModeFlat = 3??

' // Size = 16 bytes
TYPE ADDRESS64 DWORD
   Offset  AS QUAD   ' DWORD64
   Segment AS WORD   ' WORD
   Mode    AS WORD   ' ADDRESS_MODE
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define ADDRESS ADDRESS64
'#define LPADDRESS LPADDRESS64
'#else
'typedef struct _tagADDRESS {
'    DWORD         Offset;
'    WORD          Segment;
'    ADDRESS_MODE  Mode;
'} ADDRESS, *LPADDRESS;

' // Size = 12 bytes
TYPE ADDRESS DWORD
   Offset  AS DWORD   ' DWORD
   Segment AS WORD    ' WORD
   Mode    AS WORD    ' ADDRESS_MODE
END TYPE

'__inline
'void
'Address32To64(
'    __in LPADDRESS a32,
'    __out LPADDRESS64 a64
'    )
'{
'    a64->Offset = (ULONG64)(LONG64)(LONG)a32->Offset;
'    a64->Segment = a32->Segment;
'    a64->Mode = a32->Mode;
'}

MACRO Address32To64 (a32, a64)
   a64.Offset = a32.Offset
   a64.Segment = a32.Segment
   a64.Mode = a32.Mode
END MACRO

'__inline
'void
'Address64To32(
'    __in LPADDRESS64 a64,
'    __out LPADDRESS a32
'    )
'{
'    a32->Offset = (ULONG)a64->Offset;
'    a32->Segment = a64->Segment;
'    a32->Mode = a64->Mode;
'}

MACRO Address64To32 (a64, a32)
   a32.Offset = a64.Offset
   a32.Segment = a64.Segment
   a32.Mode = a64.Mode
END MACRO

'#endif

'//
'// This structure is included in the STACKFRAME structure,
'// and is used to trace through usermode callbacks in a thread's
'// kernel stack.  The values must be copied by the kernel debugger
'// from the DBGKD_GET_VERSION and WAIT_STATE_CHANGE packets.
'//

'//
'// New KDHELP structure for 64 bit system support.
'// This structure is preferred in new code.
'//
'typedef struct _KDHELP64 {

'    //
'    // address of kernel thread object, as provided in the
'    // WAIT_STATE_CHANGE packet.
'    //
'    DWORD64   Thread;

'    //
'    // offset in thread object to pointer to the current callback frame
'    // in kernel stack.
'    //
'    DWORD   ThCallbackStack;

'    //
'    // offset in thread object to pointer to the current callback backing
'    // store frame in kernel stack.
'    //
'    DWORD   ThCallbackBStore;

'    //
'    // offsets to values in frame:
'    //
'    // address of next callback frame
'    DWORD   NextCallback;

'    // address of saved frame pointer (if applicable)
'    DWORD   FramePointer;


'    //
'    // Address of the kernel function that calls out to user mode
'    //
'    DWORD64   KiCallUserMode;

'    //
'    // Address of the user mode dispatcher function
'    //
'    DWORD64   KeUserCallbackDispatcher;

'    //
'    // Lowest kernel mode address
'    //
'    DWORD64   SystemRangeStart;

'    //
'    // Address of the user mode exception dispatcher function.
'    // Added in API version 10.
'    //
'    DWORD64   KiUserExceptionDispatcher;

'    //
'    // Stack bounds, added in API version 11.
'    //
'    DWORD64   StackBase;
'    DWORD64   StackLimit;

'    DWORD64   Reserved[5];

'} KDHELP64, *PKDHELP64;

' // Size = 112 bytes
TYPE KDHELP64 QWORD FILL
   Thread                    AS QUAD    ' DWORD64
   ThCallbackStack           AS DWORD   ' DWORD
   ThCallbackBStore          AS DWORD   ' DWORD
   NextCallback              AS DWORD   ' DWORD
   FramePointer              AS DWORD   ' DWORD
   KiCallUserMode            AS QUAD    ' DWORD64
   KeUserCallbackDispatcher  AS QUAD    ' DWORD64
   SystemRangeStart          AS QUAD    ' DWORD64
   KiUserExceptionDispatcher AS QUAD    ' DWORD64
   StackBase                 AS QUAD    ' DWORD64
   StackLimit                AS QUAD    ' DWORD64
   Reserved(4)               AS QUAD    ' DWORD64[5]
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define KDHELP KDHELP64
'#define PKDHELP PKDHELP64
'#else
'typedef struct _KDHELP {

'    //
'    // address of kernel thread object, as provided in the
'    // WAIT_STATE_CHANGE packet.
'    //
'    DWORD   Thread;

'    //
'    // offset in thread object to pointer to the current callback frame
'    // in kernel stack.
'    //
'    DWORD   ThCallbackStack;

'    //
'    // offsets to values in frame:
'    //
'    // address of next callback frame
'    DWORD   NextCallback;

'    // address of saved frame pointer (if applicable)
'    DWORD   FramePointer;

'    //
'    // Address of the kernel function that calls out to user mode
'    //
'    DWORD   KiCallUserMode;

'    //
'    // Address of the user mode dispatcher function
'    //
'    DWORD   KeUserCallbackDispatcher;

'    //
'    // Lowest kernel mode address
'    //
'    DWORD   SystemRangeStart;

'    //
'    // offset in thread object to pointer to the current callback backing
'    // store frame in kernel stack.
'    //
'    DWORD   ThCallbackBStore;

'    //
'    // Address of the user mode exception dispatcher function.
'    // Added in API version 10.
'    //
'    DWORD   KiUserExceptionDispatcher;

'    //
'    // Stack bounds, added in API version 11.
'    //
'    DWORD   StackBase;
'    DWORD   StackLimit;

'    DWORD   Reserved[5];

'} KDHELP, *PKDHELP;

' // Size = 64 bytes
TYPE KDHELP DWORD
   Thread                    AS DWORD   ' DWORD
   ThCallbackStack           AS DWORD   ' DWORD
   ThCallbackBStore          AS DWORD   ' DWORD
   NextCallback              AS DWORD   ' DWORD
   FramePointer              AS DWORD   ' DWORD
   KiCallUserMode            AS DWORD   ' DWORD
   KeUserCallbackDispatcher  AS DWORD   ' DWORD
   SystemRangeStart          AS DWORD   ' DWORD
   KiUserExceptionDispatcher AS DWORD   ' DWORD
   StackBase                 AS DWORD   ' DWORD
   StackLimit                AS DWORD   ' DWORD
   Reserved(4)               AS DWORD   ' DWORD[5]
END TYPE

'__inline
'void
'KdHelp32To64(
'    __in PKDHELP p32,
'    __out PKDHELP64 p64
'    )
'{
'    p64->Thread = p32->Thread;
'    p64->ThCallbackStack = p32->ThCallbackStack;
'    p64->NextCallback = p32->NextCallback;
'    p64->FramePointer = p32->FramePointer;
'    p64->KiCallUserMode = p32->KiCallUserMode;
'    p64->KeUserCallbackDispatcher = p32->KeUserCallbackDispatcher;
'    p64->SystemRangeStart = p32->SystemRangeStart;
'    p64->KiUserExceptionDispatcher = p32->KiUserExceptionDispatcher;
'    p64->StackBase = p32->StackBase;
'    p64->StackLimit = p32->StackLimit;
'}

MACRO KdHelp32To64 (p32, p64)
   p64.Thread = p32.Thread
   p64.ThCallbackStack = p32.ThCallbackStack
   p64.NextCallback = p32.NextCallback
   p64.FramePointer = p32.FramePointer
   p64.KiCallUserMode = p32.KiCallUserMode
   p64.KeUserCallbackDispatcher = p32.KeUserCallbackDispatcher
   p64.SystemRangeStart = p32.SystemRangeStart
   p64.KiUserExceptionDispatcher = p32.KiUserExceptionDispatcher
   p64.StackBase = p32.StackBase
   p64.StackLimit = p32.StackLimit
END MACRO

'#endif

' // Size = 264 bytes
TYPE STACKFRAME64 QWORD FILL
   AddrPC         AS ADDRESS64   'ADDRESS64 // program counter
   AddrReturn     AS ADDRESS64   ' ADDRESS64 // return address
   AddrFrame      AS ADDRESS64   ' ADDRESS64 // frame pointer
   AddrStack      AS ADDRESS64   ' ADDRESS64 // stack pointer
   AddrBStore     AS ADDRESS64   ' ADDRESS64 // backing store pointer
   FuncTableEntry AS DWORD       ' PVOID // pointer to pdata/fpo or NULL
   Params(3)      AS QUAD        ' DWORD64[4] // possible arguments to the function
   Far            AS LONG        ' BOOL // WOW far call
   Virtual        AS LONG        ' BOOL // is this a virtual frame?
   Reserved(2)    AS QUAD        ' DWORD64[3]
   KdHelp         AS KDHELP64    ' KDHELP64
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define STACKFRAME STACKFRAME64
'#define LPSTACKFRAME LPSTACKFRAME64
'#else
' // Size = 164 bytes
TYPE STACKFRAME DWORD
   AddrPC         AS ADDRESS   ' ADDRESS // program counter
   AddrReturn     AS ADDRESS   ' ADDRESS // return address
   AddrFrame      AS ADDRESS   ' ADDRESS // frame pointer
   AddrStack      AS ADDRESS   ' ADDRESS // stack pointer
   FuncTableEntry AS DWORD     ' PVOID // pointer to pdata/fpo or NULL
   Params(3)      AS DWORD     ' DWORD[4] // possible arguments to the function
   Far            AS LONG      ' BOOL // WOW far call
   Virtual        AS LONG      ' BOOL // is this a virtual frame?
   Reserved(2)    AS DWORD     ' DWORD[3]
   KdHelp         AS KDHELP    ' KDHELP
   AddrBStore     AS ADDRESS   ' ADDRESS // backing store pointer
END TYPE
'#endif


'typedef
'BOOL
'(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE64)(
'    __in HANDLE hProcess,
'    __in DWORD64 qwBaseAddress,
'    __out_bcount(nSize) PVOID lpBuffer,
'    __in DWORD nSize,
'    __out LPDWORD lpNumberOfBytesRead
'    );

'FUNCTION READ_PROCESS_MEMORY_ROUTINE64 ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL qwBaseAddress AS QUAD _                        ' __in DWORD64 qwBaseAddress
' , BYREF lpBuffer AS DWORD _                            ' __out_bcount(nSize) PVOID lpBuffer
' , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
' , BYREF lpNumberOfBytesRead AS DWORD                   ' __out LPDWORD lpNumberOfBytesRead
' ) AS LONG                                              ' BOOL

'typedef
'PVOID
'(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE64)(
'    __in HANDLE ahProcess,
'    __in DWORD64 AddrBase
'    );

'FUNCTION FUNCTION_TABLE_ACCESS_ROUTINE64 ( _
'   BYVAL ahProcess AS DWORD _                           ' __in HANDLE ahProcess
' , BYVAL AddrBase AS QUAD _                             ' __in DWORD64 AddrBase
' ) AS DWORD                                             ' PVOID

'typedef
'DWORD64
'(__stdcall *PGET_MODULE_BASE_ROUTINE64)(
'    __in HANDLE hProcess,
'    __in DWORD64 Address
'    );

'FUNCTION GET_MODULE_BASE_ROUTINE64 ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
' ) AS QUAD                                              ' DWORD64

'typedef
'DWORD64
'(__stdcall *PTRANSLATE_ADDRESS_ROUTINE64)(
'    __in HANDLE hProcess,
'    __in HANDLE hThread,
'    __in LPADDRESS64 lpaddr
'    );

'FUNCTION TRANSLATE_ADDRESS_ROUTINE64 ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
' , BYREF lpaddr AS ADDRESS64 _                          ' __in LPADDRESS64 lpaddr
' ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION StackWalk64 IMPORT "ImageHlp.dll" ALIAS "StackWalk64" ( _
   BYVAL MachineType AS DWORD _                         ' __in DWORD MachineType
 , BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF StackFrame AS STACKFRAME64 _                   ' __inout LPSTACKFRAME64 StackFrame
 , BYREF ContextRecord AS ANY _                         ' __inout PVOID ContextRecord
 , OPTIONAL BYVAL ReadMemoryRoutine AS DWORD _          ' __in_opt PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine
 , OPTIONAL BYVAL FunctionTableAccessRoutine AS DWORD _ ' __in_opt PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine
 , OPTIONAL BYVAL GetModuleBaseRoutine AS DWORD _       ' __in_opt PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine
 , OPTIONAL BYVAL TranslateAddress AS DWORD _           ' __in_opt PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)

'#define PREAD_PROCESS_MEMORY_ROUTINE PREAD_PROCESS_MEMORY_ROUTINE64
'#define PFUNCTION_TABLE_ACCESS_ROUTINE PFUNCTION_TABLE_ACCESS_ROUTINE64
'#define PGET_MODULE_BASE_ROUTINE PGET_MODULE_BASE_ROUTINE64
'#define PTRANSLATE_ADDRESS_ROUTINE PTRANSLATE_ADDRESS_ROUTINE64

'#define StackWalk StackWalk64

'#else

'typedef
'BOOL
'(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE)(
'    __in HANDLE hProcess,
'    __in DWORD lpBaseAddress,
'    __out_bcount(nSize) PVOID lpBuffer,
'    __in DWORD nSize,
'    __out PDWORD lpNumberOfBytesRead
'    );

'FUNCTION READ_PROCESS_MEMORY_ROUTINE ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL qwBaseAddress AS DWORD _                       ' __in DWORD qwBaseAddress
' , BYREF lpBuffer AS DWORD _                            ' __out_bcount(nSize) PVOID lpBuffer
' , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
' , BYREF lpNumberOfBytesRead AS DWORD                   ' __out LPDWORD lpNumberOfBytesRead
' ) AS LONG                                              ' BOOL

'typedef
'PVOID
'(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE)(
'    __in HANDLE hProcess,
'    __in DWORD AddrBase
'    );

'FUNCTION FUNCTION_TABLE_ACCESS_ROUTINE ( _
'   BYVAL ahProcess AS DWORD _                           ' __in HANDLE ahProcess
' , BYVAL AddrBase AS DWORD _                            ' __in DWORD AddrBase
' ) AS DWORD                                             ' PVOID

'typedef
'DWORD
'(__stdcall *PGET_MODULE_BASE_ROUTINE)(
'    __in HANDLE hProcess,
'    __in DWORD Address
'    );

'FUNCTION GET_MODULE_BASE_ROUTINE ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL Address AS DWORD _                             ' __in DWORD Address
' ) AS DWORD                                             ' DWORD

'typedef
'DWORD
'(__stdcall *PTRANSLATE_ADDRESS_ROUTINE)(
'    __in HANDLE hProcess,
'    __in HANDLE hThread,
'    __out LPADDRESS lpaddr
'    );

'FUNCTION TRANSLATE_ADDRESS_ROUTINE ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
' , BYREF lpaddr AS ADDRESS _                            ' __in LPADDRESS lpaddr
' ) AS DWORD                                             ' DWORD

'BOOL
'IMAGEAPI
'StackWalk(
'    DWORD MachineType,
'    __in HANDLE hProcess,
'    __in HANDLE hThread,
'    __inout LPSTACKFRAME StackFrame,
'    __inout PVOID ContextRecord,
'    __in_opt PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine,
'    __in_opt PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,
'    __in_opt PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine,
'    __in_opt PTRANSLATE_ADDRESS_ROUTINE TranslateAddress
'    );

DECLARE FUNCTION StackWalk IMPORT "ImageHlp.dll" ALIAS "StackWalk" ( _
   BYVAL MachineType AS DWORD _                         ' __in DWORD MachineType
 , BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hThread AS DWORD _                             ' __in HANDLE hThread
 , BYREF StackFrame AS STACKFRAME _                     ' __inout LPSTACKFRAME StackFrame
 , BYREF ContextRecord AS ANY _                         ' __inout PVOID ContextRecord
 , OPTIONAL BYVAL ReadMemoryRoutine AS DWORD _          ' __in_opt PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine
 , OPTIONAL BYVAL FunctionTableAccessRoutine AS DWORD _ ' __in_opt PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine
 , OPTIONAL BYVAL GetModuleBaseRoutine AS DWORD _       ' __in_opt PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine
 , OPTIONAL BYVAL TranslateAddress AS DWORD _           ' __in_opt PTRANSLATE_ADDRESS_ROUTINE TranslateAddress
 ) AS LONG                                              ' BOOL

'#endif


%PI_VERSION_NUMBER = 11??

' // Size = 8 bytes
TYPE API_VERSION WORD
   MajorVersion AS WORD   ' USHORT
   MinorVersion AS WORD   ' USHORT
   Revision     AS WORD   ' USHORT
   Reserved     AS WORD   ' USHORT
END TYPE

DECLARE FUNCTION ImagehlpApiVersion IMPORT "ImageHlp.dll" ALIAS "ImagehlpApiVersion" ( _
 ) AS DWORD                                             ' LPAPI_VERSION

DECLARE FUNCTION ImagehlpApiVersionEx IMPORT "ImageHlp.dll" ALIAS "ImagehlpApiVersionEx" ( _
   BYREF AppVersion AS API_VERSION _                    ' __in LPAPI_VERSION AppVersion
 ) AS DWORD                                             ' LPAPI_VERSION

DECLARE FUNCTION GetTimestampForLoadedLibrary IMPORT "ImageHlp.dll" ALIAS "GetTimestampForLoadedLibrary" ( _
   BYVAL Module AS DWORD _                              ' __in HMODULE Module
 ) AS DWORD                                             ' DWORD

'//
'// typedefs for function pointers
'//
'typedef BOOL
'(CALLBACK *PSYM_ENUMMODULES_CALLBACK64)(
'    __in PCSTR ModuleName,
'    __in DWORD64 BaseOfDll,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMMODULES_CALLBACK64 ( _
'   BYREF ModuleName AS ASCIIZ _                         ' __in PCSTR ModuleName
' , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMMODULES_CALLBACKW64)(
'    __in PCWSTR ModuleName,
'    __in DWORD64 BaseOfDll,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMMODULES_CALLBACKW64 ( _
'   BYREF ModuleName AS WSTRINGZ _                       ' __in PCWSTR ModuleName
' , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PENUMLOADED_MODULES_CALLBACK64)(
'    __in PCSTR ModuleName,
'    __in DWORD64 ModuleBase,
'    __in ULONG ModuleSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION ENUMLOADED_MODULES_CALLBACK64 ( _
'   BYREF ModuleName AS ASCIIZ _                         ' __in PCSTR ModuleName
' , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
' , BYVAL ModuleSize AS DWORD _                          ' __in ULONG ModuleSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PENUMLOADED_MODULES_CALLBACKW64)(
'    __in PCWSTR ModuleName,
'    __in DWORD64 ModuleBase,
'    __in ULONG ModuleSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION ENUMLOADED_MODULES_CALLBACKW64 ( _
'   BYREF ModuleName AS WSTRINGZ _                       ' __in PCWSTR ModuleName
' , BYVAL ModuleBase AS QUAD _                           ' __in DWORD64 ModuleBase
' , BYVAL ModuleSize AS DWORD _                          ' __in ULONG ModuleSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64)(
'    __in PCSTR SymbolName,
'    __in DWORD64 SymbolAddress,
'    __in ULONG SymbolSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSYMBOLS_CALLBACK64 ( _
'   BYREF SymbolName AS ASCIIZ _                         ' __in PCSTR SymbolName
' , BYVAL SymbolAddress AS QUAD _                        ' __in DWORD64 SymbolAddress
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64W)(
'    __in PCWSTR SymbolName,
'    __in DWORD64 SymbolAddress,
'    __in ULONG SymbolSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSYMBOLS_CALLBACK64W ( _
'   BYREF SymbolName AS WSTRINGZ _                       ' __in PCWSTR SymbolName
' , BYVAL SymbolAddress AS QUAD _                        ' __in DWORD64 SymbolAddress
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYMBOL_REGISTERED_CALLBACK64)(
'    __in HANDLE hProcess,
'    __in ULONG ActionCode,
'    __in_opt ULONG64 CallbackData,
'    __in_opt ULONG64 UserContext
'    );

'FUNCTION SYMBOL_REGISTERED_CALLBACK64 ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL ActionCode AS DWORD _                          ' __in ULONG ActionCode
' , OPTIONAL BYVAL CallbackData AS QUAD _                ' __in_opt ULONG64 CallbackData
' , OPTIONAL BYVAL UserContext AS QUAD _                 ' __in_opt ULONG64 UserContext
' ) AS LONG                                              ' BOOL

'typedef
'PVOID
'(CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK)(
'    __in HANDLE hProcess,
'    __in DWORD AddrBase,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYMBOL_FUNCENTRY_CALLBACK ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL AddrBase AS DWORD _                            ' __in ULONG AddrBase
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS DWORD                                             ' PVOID

'typedef
'PVOID
'(CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK64)(
'    __in HANDLE hProcess,
'    __in ULONG64 AddrBase,
'    __in ULONG64 UserContext
'    );

'FUNCTION SYMBOL_FUNCENTRY_CALLBACK64 ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL AddrBase AS QUAD _                             ' __in ULONG64 AddrBase
' , OPTIONAL BYVAL UserContext AS QUAD _                 ' __in_opt ULONG64 UserContext
' ) AS DWORD                                             ' PVOID

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)

'#define PSYM_ENUMMODULES_CALLBACK PSYM_ENUMMODULES_CALLBACK64
'#define PSYM_ENUMSYMBOLS_CALLBACK PSYM_ENUMSYMBOLS_CALLBACK64
'#define PSYM_ENUMSYMBOLS_CALLBACKW PSYM_ENUMSYMBOLS_CALLBACK64W
'#define PENUMLOADED_MODULES_CALLBACK PENUMLOADED_MODULES_CALLBACK64
'#define PSYMBOL_REGISTERED_CALLBACK PSYMBOL_REGISTERED_CALLBACK64
'#define PSYMBOL_FUNCENTRY_CALLBACK PSYMBOL_FUNCENTRY_CALLBACK64

'#else

'typedef BOOL
'(CALLBACK *PSYM_ENUMMODULES_CALLBACK)(
'    __in PCSTR ModuleName,
'    __in ULONG BaseOfDll,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMMODULES_CALLBACK ( _
'   BYREF ModuleName AS ASCIIZ _                         ' __in PCSTR ModuleName
' , BYVAL BaseOfDll AS DWORD _                           ' __in ULONG BaseOfDll
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK)(
'    __in PCSTR SymbolName,
'    __in ULONG SymbolAddress,
'    __in ULONG SymbolSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSYMBOLS_CALLBACK ( _
'   BYREF SymbolName AS ASCIIZ _                         ' __in PCSTR SymbolName
' , BYVAL SymbolAddress AS DWORD _                       ' __in ULONG SymbolAddress
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACKW)(
'    __in PCWSTR SymbolName,
'    __in ULONG SymbolAddress,
'    __in ULONG SymbolSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSYMBOLS_CALLBACKW ( _
'   BYREF SymbolName AS WSTRINGZ _                       ' __in PCWSTR SymbolName
' , BYVAL SymbolAddress AS DWORD _                       ' __in ULONG SymbolAddress
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PENUMLOADED_MODULES_CALLBACK)(
'    __in PCSTR ModuleName,
'    __in ULONG ModuleBase,
'    __in ULONG ModuleSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION ENUMLOADED_MODULES_CALLBACK ( _
'   BYREF ModuleName AS ASCIIZ _                         ' __in PCSTR ModuleName
' , BYVAL BaseOfDll AS DWORD _                           ' __in ULONG BaseOfDll
' , BYVAL ModuleSize AS DWORD _                          ' __in ULONG ModuleSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYMBOL_REGISTERED_CALLBACK)(
'    __in HANDLE hProcess,
'    __in ULONG ActionCode,
'    __in_opt PVOID CallbackData,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYMBOL_REGISTERED_CALLBACK ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL ActionCode AS DWORD _                          ' __in ULONG ActionCode
' , OPTIONAL BYVAL CallbackData AS DWORD _               ' __in_opt PVOID CallbackData
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

''#endif


'// values found in SYMBOL_INFO.Tag
'//
'// This was taken from cvconst.h and should
'// not override any values found there.
'//
'// #define _NO_CVCONST_H_ if you don't
'// have access to that file...

'#ifdef _NO_CVCONST_H

'// DIA enums

' enum SymTagEnum
%SymTagNull             = 0???
%SymTagExe              = 1???
%SymTagCompiland        = 2???
%SymTagCompilandDetails = 3???
%SymTagCompilandEnv     = 4???
%SymTagFunction         = 5???
%SymTagBlock            = 6???
%SymTagData             = 7???
%SymTagAnnotation       = 8???
%SymTagLabel            = 9???
%SymTagPublicSymbol     = 10???
%SymTagUDT              = 11???
%SymTagEnum             = 12???
%SymTagFunctionType     = 13???
%SymTagPointerType      = 14???
%SymTagArrayType        = 15???
%SymTagBaseType         = 16???
%SymTagTypedef          = 17???
%SymTagBaseClass        = 18???
%SymTagFriend           = 19???
%SymTagFunctionArgType  = 20???
%SymTagFuncDebugStart   = 21???
%SymTagFuncDebugEnd     = 22???
%SymTagUsingNamespace   = 23???
%SymTagVTableShape      = 24???
%SymTagVTable           = 25???
%SymTagCustom           = 26???
%SymTagThunk            = 27???
%SymTagCustomType       = 28???
%SymTagManagedType      = 29???
%SymTagDimension        = 30???
%SymTagMax              = 31???

'#endif

'//
'// flags found in SYMBOL_INFO.Flags
'//

%SYMFLAG_VALUEPRESENT     = &H00000001???
%SYMFLAG_REGISTER         = &H00000008???
%SYMFLAG_REGREL           = &H00000010???
%SYMFLAG_FRAMEREL         = &H00000020???
%SYMFLAG_PARAMETER        = &H00000040???
%SYMFLAG_LOCAL            = &H00000080???
%SYMFLAG_CONSTANT         = &H00000100???
%SYMFLAG_EXPORT           = &H00000200???
%SYMFLAG_FORWARDER        = &H00000400???
%SYMFLAG_FUNCTION         = &H00000800???
%SYMFLAG_VIRTUAL          = &H00001000???
%SYMFLAG_THUNK            = &H00002000???
%SYMFLAG_TLSREL           = &H00004000???
%SYMFLAG_SLOT             = &H00008000???
%SYMFLAG_ILREL            = &H00010000???
%SYMFLAG_METADATA         = &H00020000???
%SYMFLAG_CLR_TOKEN        = &H00040000???

'// this resets SymNext/Prev to the beginning
'// of the module passed in the address field

%SYMFLAG_RESET            = &H80000000???

'//
'// symbol type enumeration
'//
' enum SYM_TYPE
%SymNone     = 0???
%SymCoff     = 1???
%SymCv       = 2???
%SymPdb      = 3???
%SymExport   = 4???
%SymDeferred = 5???
%SymSym      = 6???   ' // .sym file
%SymDia      = 7???
%SymVirtual  = 8???
%NumSymTypes = 9???

'//
'// symbol data structure
'//

' // Size in C++ = 32 bytes
TYPE IMAGEHLP_SYMBOL64 QWORD FILL
   SizeOfStruct  AS DWORD        ' DWORD // set to sizeof(IMAGEHLP_SYMBOL64)
   Address       AS QUAD         ' DWORD64 // virtual address including dll base address
   Size          AS DWORD        ' DWORD // estimated size of symbol, can be zero
   Flags         AS DWORD        ' DWORD // info about the symbols, see the SYMF defines
   MaxNameLength AS DWORD        ' DWORD // maximum size of symbol name in 'Name'
   Name          AS ASCIIZ * 1   ' CHAR // symbol name (null terminated string)
END TYPE

' // Size  in C++ = 2040 bytes
TYPE IMAGEHLP_SYMBOL64_PACKAGE
   sym  AS IMAGEHLP_SYMBOL64
   name AS ASCIIZ * (%MAX_SYM_NAME + 1)   ' CHAR name[MAX_SYM_NAME + 1];
END TYPE

' // Size in C++ = 32 bytes
TYPE IMAGEHLP_SYMBOLW64 QWORD FILL
   SizeOfStruct  AS DWORD          ' DWORD // set to sizeof(IMAGEHLP_SYMBOLW64)
   Address       AS QUAD           ' DWORD64 // virtual address including dll base address
   Size          AS DWORD          ' DWORD // estimated size of symbol, can be zero
   Flags         AS DWORD          ' DWORD // info about the symbols, see the SYMF defines
   MaxNameLength AS DWORD          ' DWORD // maximum size of symbol name in 'Name'
   Name          AS WSTRINGZ * 1   ' WCHAR // symbol name (null terminated string)
END TYPE

' // Size in C++ = 4040 bytes
TYPE IMAGEHLP_SYMBOLW64_PACKAGE QWORD FILL
   sym  AS IMAGEHLP_SYMBOLW64
   name AS WSTRINGZ * (%MAX_SYM_NAME + 1)   ' WCHAR name[MAX_SYM_NAME + 1];
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)

' #define IMAGEHLP_SYMBOL IMAGEHLP_SYMBOL64
' #define PIMAGEHLP_SYMBOL PIMAGEHLP_SYMBOL64
' #define IMAGEHLP_SYMBOL_PACKAGE IMAGEHLP_SYMBOL64_PACKAGE
' #define PIMAGEHLP_SYMBOL_PACKAGE PIMAGEHLP_SYMBOL64_PACKAGE
' #define IMAGEHLP_SYMBOLW IMAGEHLP_SYMBOLW64
' #define PIMAGEHLP_SYMBOLW PIMAGEHLP_SYMBOLW64
' #define IMAGEHLP_SYMBOLW_PACKAGE IMAGEHLP_SYMBOLW64_PACKAGE
' #define PIMAGEHLP_SYMBOLW_PACKAGE PIMAGEHLP_SYMBOLW64_PACKAGE

'#else

' // Size in C++ = 24 bytes
TYPE IMAGEHLP_SYMBOL DWORD
   SizeOfStruct  AS DWORD         ' DWORD // set to sizeof(IMAGEHLP_SYMBOL64)
   Address       AS DWORD         ' DWORD // virtual address including dll base address
   Size          AS DWORD         ' DWORD // estimated size of symbol, can be zero
   Flags         AS DWORD         ' DWORD // info about the symbols, see the SYMF defines
   MaxNameLength AS DWORD         ' DWORD // maximum size of symbol name in 'Name'
   Name          AS ASCIIZ * 1    ' CHAR // symbol name (null terminated string)
END TYPE

' // Size in C++ = 2028 bytes
TYPE IMAGEHLP_SYMBOL_PACKAGE DWORD
   sym  AS IMAGEHLP_SYMBOL
   name AS ASCIIZ * (%MAX_SYM_NAME + 1)   ' CHAR name[MAX_SYM_NAME + 1];
END TYPE

' // Size in C++ = 24 bytes
TYPE IMAGEHLP_SYMBOLW DWORD
   SizeOfStruct  AS DWORD          ' DWORD // set to sizeof(IMAGEHLP_SYMBOLW64)
   Address       AS DWORD          ' DWORD // virtual address including dll base address
   Size          AS DWORD          ' DWORD // estimated size of symbol, can be zero
   Flags         AS DWORD          ' DWORD // info about the symbols, see the SYMF defines
   MaxNameLength AS DWORD          ' DWORD // maximum size of symbol name in 'Name'
   Name          AS WSTRINGZ * 1   ' WCHAR // symbol name (null terminated string)
END TYPE

' // Size in C++ = 4028 bytes
TYPE IMAGEHLP_SYMBOLW_PACKAGE DWORD
   sym  AS IMAGEHLP_SYMBOLW
   name AS WSTRINGZ * (%MAX_SYM_NAME + 1)   ' WCHAR name[MAX_SYM_NAME + 1];
END TYPE

'#endif

'//
'// module data structure
'//

' // Size = 1672 bytes
TYPE IMAGEHLP_MODULE64   ' Must be 8 bytes aligned
   SizeOfStruct    AS DWORD                        ' DWORD // set to sizeof(IMAGEHLP_MODULE64)
   alignment__     AS DWORD                        ' // To keep 8 bytes alignment
   BaseOfImage     AS QUAD                         ' DWORD64 // base load address of module
   ImageSize       AS DWORD                        ' DWORD // virtual size of the loaded module
   TimeDateStamp   AS DWORD                        ' DWORD // date/time stamp from pe header
   CheckSum        AS DWORD                        ' DWORD // checksum from the pe header
   NumSyms         AS DWORD                        ' DWORD // number of symbols in the symbol table
   SymType         AS DWORD                        ' SYM_TYPE // type of symbols loaded
   ModuleName      AS ASCIIZ   * 32                ' CHAR // module name
   ImageName       AS ASCIIZ   * 256               ' CHAR // image name
   LoadedImageName AS ASCIIZ   * 256               ' CHAR // symbol file name
    ' // new elements: 07-Jun-2002
   LoadedPdbName   AS ASCIIZ   * 256               ' CHAR // pdb file name
   CVSig           AS DWORD                        ' DWORD // Signature of the CV record in the debug directories
   CVData          AS ASCIIZ   * (%MAX_PATH * 3)   ' CHAR // Contents of the CV record
   PdbSig          AS DWORD                        ' DWORD // Signature of PDB
   PdbSig70        AS GUID                         ' GUID // Signature of PDB (VC 7 and up)
   PdbAge          AS DWORD                        ' DWORD // DBI age of pdb
   PdbUnmatched    AS LONG                         ' BOOL // loaded an unmatched pdb
   DbgUnmatched    AS LONG                         ' BOOL // loaded an unmatched dbg
   LineNumbers     AS LONG                         ' BOOL // we have line number information
   GlobalSymbols   AS LONG                         ' BOOL // we have internal symbol information
   TypeInfo        AS LONG                         ' BOOL// we have type information
   ' // new elements: 17-Dec-2003
   SourceIndexed   AS LONG                         ' BOOL // pdb supports source server
   Publics         AS LONG                         ' BOOL // contains public symbols
END TYPE

' // Size = 3256 bytes
TYPE IMAGEHLP_MODULEW64
   SizeOfStruct    AS DWORD                        ' DWORD // set to sizeof(IMAGEHLP_MODULE64)
   alignment1__    AS DWORD                        ' // To keep 8 bytes alignment
   BaseOfImage     AS QUAD                         ' DWORD64 // base load address of module
   ImageSize       AS DWORD                        ' DWORD // virtual size of the loaded module
   TimeDateStamp   AS DWORD                        ' DWORD // date/time stamp from pe header
   CheckSum        AS DWORD                        ' DWORD // checksum from the pe header
   NumSyms         AS DWORD                        ' DWORD // number of symbols in the symbol table
   SymType         AS DWORD                        ' SYM_TYPE // type of symbols loaded
   ModuleName      AS WSTRINGZ * 32                ' WCHAR // module name
   ImageName       AS WSTRINGZ * 256               ' WCHAR // image name
   LoadedImageName AS WSTRINGZ * 256               ' WCHAR // symbol file name
    ' // new elements: 07-Jun-2002
   LoadedPdbName   AS WSTRINGZ * 256               ' WCHAR // pdb file name
   CVSig           AS DWORD                        ' DWORD // Signature of the CV record in the debug directories
   CVData          AS WSTRINGZ * (%MAX_PATH * 3)   ' WCHAR // Contents of the CV record
   PdbSig          AS DWORD                        ' DWORD // Signature of PDB
   alignment2__    AS DWORD                        ' // To keep 8 bytes alignment
   PdbSig70        AS GUID                         ' GUID // Signature of PDB (VC 7 and up)
   PdbAge          AS DWORD                        ' DWORD // DBI age of pdb
   PdbUnmatched    AS LONG                         ' BOOL // loaded an unmatched pdb
   DbgUnmatched    AS LONG                         ' BOOL // loaded an unmatched dbg
   LineNumbers     AS LONG                         ' BOOL // we have line number information
   GlobalSymbols   AS LONG                         ' BOOL // we have internal symbol information
   TypeInfo        AS LONG                         ' BOOL// we have type information
   ' // new elements: 17-Dec-2003
   SourceIndexed   AS LONG                         ' BOOL // pdb supports source server
   Publics         AS LONG                         ' BOOL // contains public symbols
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define IMAGEHLP_MODULE IMAGEHLP_MODULE64
'#define PIMAGEHLP_MODULE PIMAGEHLP_MODULE64
'#define IMAGEHLP_MODULEW IMAGEHLP_MODULEW64
'#define PIMAGEHLP_MODULEW PIMAGEHLP_MODULEW64
'#else

' // Size = 572 bytes
TYPE IMAGEHLP_MODULE DWORD
   SizeOfStruct    AS DWORD                        ' DWORD // set to sizeof(IMAGEHLP_MODULE64)
   BaseOfImage     AS DWORD                        ' DWORD // base load address of module
   ImageSize       AS DWORD                        ' DWORD // virtual size of the loaded module
   TimeDateStamp   AS DWORD                        ' DWORD // date/time stamp from pe header
   CheckSum        AS DWORD                        ' DWORD // checksum from the pe header
   NumSyms         AS DWORD                        ' DWORD // number of symbols in the symbol table
   SymType         AS DWORD                        ' SYM_TYPE // type of symbols loaded
   ModuleName      AS ASCIIZ   * 32                ' CHAR // module name
   ImageName       AS ASCIIZ   * 256               ' CHAR // image name
   LoadedImageName AS ASCIIZ   * 256               ' CHAR // symbol file name
END TYPE

' // Size = 1116 bytes
TYPE IMAGEHLP_MODULEW DWORD
   SizeOfStruct    AS DWORD                        ' DWORD // set to sizeof(IMAGEHLP_MODULE64)
   BaseOfImage     AS DWORD                        ' DWORD // base load address of module
   ImageSize       AS DWORD                        ' DWORD // virtual size of the loaded module
   TimeDateStamp   AS DWORD                        ' DWORD // date/time stamp from pe header
   CheckSum        AS DWORD                        ' DWORD // checksum from the pe header
   NumSyms         AS DWORD                        ' DWORD // number of symbols in the symbol table
   SymType         AS DWORD                        ' SYM_TYPE // type of symbols loaded
   ModuleName      AS WSTRINGZ * 32                ' WCHAR // module name
   ImageName       AS WSTRINGZ * 256               ' WCHAR // image name
   LoadedImageName AS WSTRINGZ * 256               ' WCHAR // symbol file name
END TYPE

'#endif

'//
'// source file line data structure
'//

' // Size = 24 bytes
TYPE IMAGEHLP_LINE64 DWORD
   SizeOfStruct AS DWORD        ' DWORD // set to sizeof(IMAGEHLP_LINE64)
   Key          AS DWORD        ' PVOID // internal
   LineNumber   AS DWORD        ' DWORD // line number in file
   FileName     AS ASCIIZ PTR   ' PCHAR // full filename
   Address      AS QUAD         ' DWORD64 // first instruction of line
END TYPE

' // Size = 24 bytes
TYPE IMAGEHLP_LINEW64 DWORD
   SizeOfStruct AS DWORD          ' DWORD // set to sizeof(IMAGEHLP_LINE64)
   Key          AS DWORD          ' PVOID // internal
   LineNumber   AS DWORD          ' DWORD // line number in file
   FileName     AS WSTRINGZ PTR   ' PWSTR // full filename
   Address      AS QUAD           ' DWORD64 // first instruction of line
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define IMAGEHLP_LINE IMAGEHLP_LINE64
'#define PIMAGEHLP_LINE PIMAGEHLP_LINE64
'#else

' // Size = 20 bytes
TYPE IMAGEHLP_LINE DWORD
   SizeOfStruct AS DWORD        ' DWORD // set to sizeof(IMAGEHLP_LINE64)
   Key          AS DWORD        ' PVOID // internal
   LineNumber   AS DWORD        ' DWORD // line number in file
   FileName     AS ASCIIZ PTR   ' PCHAR // full filename
   Address      AS DWORD        ' DWORD // first instruction of line
END TYPE

'typedef struct _IMAGEHLP_LINEW {
'    DWORD    SizeOfStruct;           // set to sizeof(IMAGEHLP_LINE64)
'    PVOID    Key;                    // internal
'    DWORD    LineNumber;             // line number in file
'    PCHAR    FileName;               // full filename  *** wrong ***
'    DWORD64  Address;                // first instruction of line  *** wrong ***
'} IMAGEHLP_LINEW, *PIMAGEHLP_LINEW;

' // Size = 24 bytes
TYPE IMAGEHLP_LINEW DWORD
   SizeOfStruct AS DWORD          ' DWORD // set to sizeof(IMAGEHLP_LINE64)
   Key          AS DWORD          ' PVOID // internal
   LineNumber   AS DWORD          ' DWORD // line number in file
   FileName     AS WSTRINGZ PTR   ' PWSTR // full filename
   Address      AS QUAD           ' DWORD64 // first instruction of line
END TYPE

'#endif

'//
'// source file structure
'//

' // Size = 16 bytes
TYPE SOURCEFILE QWORD
   ModBase  AS QUAD         ' DWORD64 // base address of loaded module
   FileName AS ASCIIZ PTR   ' PCHAR // full filename of source
END TYPE

' // Size = 16 bytes
TYPE SOURCEFILEW QWORD
   ModBase  AS QUAD           ' DWORD64 // base address of loaded module
   FileName AS WSTRINGZ PTR   ' PWSTR // full filename of source
END TYPE

'//
'// data structures used for registered symbol callbacks
'//

%CBA_DEFERRED_SYMBOL_LOAD_START          = &H00000001???
%CBA_DEFERRED_SYMBOL_LOAD_COMPLETE       = &H00000002???
%CBA_DEFERRED_SYMBOL_LOAD_FAILURE        = &H00000003???
%CBA_SYMBOLS_UNLOADED                    = &H00000004???
%CBA_DUPLICATE_SYMBOL                    = &H00000005???
%CBA_READ_MEMORY                         = &H00000006???
%CBA_DEFERRED_SYMBOL_LOAD_CANCEL         = &H00000007???
%CBA_SET_OPTIONS                         = &H00000008???
%CBA_EVENT                               = &H00000010???
%CBA_DEFERRED_SYMBOL_LOAD_PARTIAL        = &H00000020???
%CBA_DEBUG_INFO                          = &H10000000???
%CBA_SRCSRV_INFO                         = &H20000000???
%CBA_SRCSRV_EVENT                        = &H40000000???

' // Size = 24 bytes
TYPE IMAGEHLP_CBA_READ_MEMORY   ' Must be 8 bytes aligned
   addr        AS QUAD        ' DWORD64 // address to read from
   buf         AS DWORD       ' PVOID // buffer to read to
   bytes       AS DWORD       ' DWORD // amount of bytes to read
   bytesread   AS DWORD PTR   ' DWORD* // pointer to store amount of bytes read
   alignment__ AS DWORD       ' // To keep 8 bytes alignment
END TYPE

' enum
%sevInfo    = 0???
%sevProblem = 1???
%sevAttn    = 2???
%sevFatal   = 3???
'sevMax  // unused

%EVENT_SRCSPEW_START = 100???
%EVENT_SRCSPEW       = 100???
%EVENT_SRCSPEW_END   = 199???

' // Size = 16 bytes
TYPE IMAGEHLP_CBA_EVENT DWORD
   severity AS DWORD        ' DWORD // values from sevInfo to sevFatal
   code     AS DWORD        ' DWORD // numerical code IDs the error
   desc     AS ASCIIZ PTR   ' PCHAR // may contain a text description of the error
   object   AS DWORD        ' PVOID // value dependant upon the error code
END TYPE

' // Size = 16 bytes
TYPE IMAGEHLP_CBA_EVENTW DWORD
   severity AS DWORD          ' DWORD // values from sevInfo to sevFatal
   code     AS DWORD          ' DWORD // numerical code IDs the error
   desc     AS WSTRINGZ PTR   ' PCWSTR // may contain a text description of the error
   object   AS DWORD          ' PVOID // value dependant upon the error code
END TYPE

' // Size = 296 bytes
TYPE IMAGEHLP_DEFERRED_SYMBOL_LOAD64 QWORD FILL
   SizeOfStruct  AS DWORD                ' DWORD // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD64)
   BaseOfImage   AS QUAD                 ' DWORD64 // base load address of module
   CheckSum      AS DWORD                ' DWORD // checksum from the pe header
   TimeDateStamp AS DWORD                ' DWORD // date/time stamp from pe header
   FileName      AS ASCIIZ * %MAX_PATH   ' CHAR // symbols file or image name
   Reparse       AS BYTE                 ' BOOLEAN // load failure reparse
   hFile         AS DWORD                ' HANDLE // file handle, if passed
   Flags         AS DWORD                ' DWORD
END TYPE

' // Size = 560 bytes
TYPE IMAGEHLP_DEFERRED_SYMBOL_LOADW64 QWORD FILL
   SizeOfStruct  AS DWORD                    ' DWORD // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD64)
   BaseOfImage   AS QUAD                     ' DWORD64 // base load address of module
   CheckSum      AS DWORD                    ' DWORD // checksum from the pe header
   TimeDateStamp AS DWORD                    ' DWORD // date/time stamp from pe header
   FileName      AS WSTRINGZ * %MAX_PATH     ' WCHAR // symbols file or image name
   Reparse       AS BYTE                     ' BOOLEAN // load failure reparse
   hFile         AS DWORD                    ' HANDLE // file handle, if passed
   Flags         AS DWORD                    ' DWORD
   alignment__   AS DWORD                    ' // To keep 8 bytes alignment
END TYPE

%DSLFLAG_MISMATCHED_PDB = &H1???
%DSLFLAG_MISMATCHED_DBG = &H2???

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define IMAGEHLP_DEFERRED_SYMBOL_LOAD IMAGEHLP_DEFERRED_SYMBOL_LOAD64
'#define PIMAGEHLP_DEFERRED_SYMBOL_LOAD PIMAGEHLP_DEFERRED_SYMBOL_LOAD64
'#else

' // Size = 284 bytes
TYPE IMAGEHLP_DEFERRED_SYMBOL_LOAD DWORD
   SizeOfStruct  AS DWORD                ' DWORD // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD64)
   BaseOfImage   AS DWORD                ' DWORD // base load address of module
   CheckSum      AS DWORD                ' DWORD // checksum from the pe header
   TimeDateStamp AS DWORD                ' DWORD // date/time stamp from pe header
   FileName      AS ASCIIZ * %MAX_PATH   ' CHAR // symbols file or image name
   Reparse       AS BYTE                 ' BOOLEAN // load failure reparse
   hFile         AS DWORD                ' HANDLE // file handle, if passed
END TYPE

'#endif

' // Size = 16 bytes
TYPE IMAGEHLP_DUPLICATE_SYMBOL64 DWORD
   SizeOfStruct   AS DWORD                   ' DWORD // set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL64)
   NumberOfDups   AS DWORD                   ' DWORD // number of duplicates in the Symbol array
   Symbol         AS IMAGEHLP_SYMBOL64 PTR   ' PIMAGEHLP_SYMBOL64 // array of duplicate symbols
   SelectedSymbol AS DWORD                   ' DWORD // symbol selected (-1 to start)
END TYPE

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define IMAGEHLP_DUPLICATE_SYMBOL IMAGEHLP_DUPLICATE_SYMBOL64
'#define PIMAGEHLP_DUPLICATE_SYMBOL PIMAGEHLP_DUPLICATE_SYMBOL64
'#else

' // Size = 16 bytes
TYPE IMAGEHLP_DUPLICATE_SYMBOL DWORD
   SizeOfStruct   AS DWORD                   ' DWORD // set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL64)
   NumberOfDups   AS DWORD                   ' DWORD // number of duplicates in the Symbol array
   Symbol         AS IMAGEHLP_SYMBOL PTR     ' PIMAGEHLP_SYMBOL // array of duplicate symbols
   SelectedSymbol AS DWORD                   ' DWORD // symbol selected (-1 to start)
END TYPE

'#endif

'// If dbghelp ever needs to display graphical UI, it will use this as the parent window.

' Requires version 6.0 or later.
DECLARE FUNCTION SymSetParentWindow IMPORT "ImageHlp.dll" ALIAS "SymSetParentWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

' Requires version 6.1 or later.
DECLARE FUNCTION SymSetHomeDirectory IMPORT "ImageHlp.dll" ALIAS "SymSetHomeDirectory" ( _
   BYVAL hProcess AS DWORD _                            ' __in_opt HANDLE hProcess
 , OPTIONAL BYREF dir AS ASCIIZ _                       ' __in_opt PCSTR dir
 ) AS DWORD                                             ' PCHAR

' Requires version 6.1 or later.
DECLARE FUNCTION SymSetHomeDirectoryW IMPORT "ImageHlp.dll" ALIAS "SymSetHomeDirectoryW" ( _
   BYVAL hProcess AS DWORD _                            ' __in_opt HANDLE hProcess
 , OPTIONAL BYREF dir AS WSTRINGZ _                     ' __in_opt PCWSTR dir
 ) AS DWORD                                             ' PWSTR

' Requires version 6.1 or later.
DECLARE FUNCTION SymGetHomeDirectory IMPORT "ImageHlp.dll" ALIAS "SymGetHomeDirectory" ( _
   BYVAL type AS DWORD _                                ' __in DWORD type
 , BYREF dir aS ASCIIZ _                                ' __out_ecount(size) PSTR dir
 , BYVAL size aS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' PCHAR

' Requires version 6.1 or later.
DECLARE FUNCTION SymGetHomeDirectoryW IMPORT "ImageHlp.dll" ALIAS "SymGetHomeDirectoryW" ( _
   BYVAL type AS DWORD _                                ' __in DWORD type
 , BYREF dir AS DWORD _                                 ' __out_ecount(size) PSWTR dir
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' PWSTR

' enum
%hdBase = 0   ' // root directory for dbghelp
%hdSym  = 1   ' // where symbols are stored
%hdSrc  = 2   ' // where source is stored
%hdMax  = 3   ' // end marker

' // Size = 8 bytes
TYPE OMAP DWORD
   rva   AS DWORD   ' ULONG
   rvaTo AS DWORD   ' ULONG
END TYPE

DECLARE FUNCTION SymGetOmaps IMPORT "ImageHlp.dll" ALIAS "SymGetOmaps" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
 , BYREF OmapTo AS OMAP _                               ' __out POMAP *OmapTo
 , BYREF cOmapTo AS QUAD _                              ' __out PDWORD64 cOmapTo
 , BYREF OmapFrom AS OMAP _                             ' __out POMAP *OmapFrom
 , BYREF cOmapFrom AS QUAD _                            ' __out PDWORD64 cOmapFrom
 ) AS LONG                                              ' BOOL

'//
'// options that are set/returned by SymSetOptions() & SymGetOptions()
'// these are used as a mask
'//
%SYMOPT_CASE_INSENSITIVE          = &H00000001???
%SYMOPT_UNDNAME                   = &H00000002???
%SYMOPT_DEFERRED_LOADS            = &H00000004???
%SYMOPT_NO_CPP                    = &H00000008???
%SYMOPT_LOAD_LINES                = &H00000010???
%SYMOPT_OMAP_FIND_NEAREST         = &H00000020???
%SYMOPT_LOAD_ANYTHING             = &H00000040???
%SYMOPT_IGNORE_CVREC              = &H00000080???
%SYMOPT_NO_UNQUALIFIED_LOADS      = &H00000100???
%SYMOPT_FAIL_CRITICAL_ERRORS      = &H00000200???
%SYMOPT_EXACT_SYMBOLS             = &H00000400???
%SYMOPT_ALLOW_ABSOLUTE_SYMBOLS    = &H00000800???
%SYMOPT_IGNORE_NT_SYMPATH         = &H00001000???
%SYMOPT_INCLUDE_32BIT_MODULES     = &H00002000???
%SYMOPT_PUBLICS_ONLY              = &H00004000???
%SYMOPT_NO_PUBLICS                = &H00008000???
%SYMOPT_AUTO_PUBLICS              = &H00010000???
%SYMOPT_NO_IMAGE_SEARCH           = &H00020000???
%SYMOPT_SECURE                    = &H00040000???
%SYMOPT_NO_PROMPTS                = &H00080000???
%SYMOPT_OVERWRITE                 = &H00100000???
%SYMOPT_IGNORE_IMAGEDIR           = &H00200000???
%SYMOPT_FLAT_DIRECTORY            = &H00400000???
%SYMOPT_FAVOR_COMPRESSED          = &H00800000???
%SYMOPT_ALLOW_ZERO_ADDRESS        = &H01000000???
%SYMOPT_DISABLE_SYMSRV_AUTODETECT = &H02000000???

%SYMOPT_DEBUG                     = &H80000000???

DECLARE FUNCTION SymSetOptions IMPORT "ImageHlp.dll" ALIAS "SymSetOptions" ( _
   BYVAL SymOptions AS DWORD _                          ' __in DWORD SymOptions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SymGetOptions IMPORT "ImageHlp.dll" ALIAS "SymGetOptions" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SymCleanup IMPORT "ImageHlp.dll" ALIAS "SymCleanup" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymMatchString IMPORT "ImageHlp.dll" ALIAS "SymMatchString" ( _
   BYREF string AS ASCIIZ _                             ' __in PCSTR string
 , BYREF expression AS ASCIIZ _                         ' __in PCSTR expression
 , BYVAL fCase AS LONG _                                ' __in BOOL fCase
 ) AS LONG                                              ' BOOL

' Requires version 6.2 or later.
DECLARE FUNCTION SymMatchStringA IMPORT "ImageHlp.dll" ALIAS "SymMatchStringA" ( _
   BYREF string AS ASCIIZ _                             ' __in PCSTR string
 , BYREF expression AS ASCIIZ _                         ' __in PCSTR expression
 , BYVAL fCase AS LONG _                                ' __in BOOL fCase
 ) AS LONG                                              ' BOOL

' Requires version 6.2 or later.
DECLARE FUNCTION SymMatchStringW IMPORT "ImageHlp.dll" ALIAS "SymMatchStringW" ( _
   BYREF string AS WSTRINGZ _                           ' __in PCWSTR string
 , BYREF expression AS WSTRINGZ _                       ' __in PCWSTR expression
 , BYVAL fCase AS LONG _                                ' __in BOOL fCase
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSOURCEFILES_CALLBACK)(
'    __in PSOURCEFILE pSourceFile,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSOURCEFILES_CALLBACK ( _
'   BYREF pSourceFile AS SOURCEFILE _                    ' __in PSOURCEFILE pSourceFile
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

'// for backwards compatibility - don't use this
'#define PSYM_ENUMSOURCFILES_CALLBACK PSYM_ENUMSOURCEFILES_CALLBACK

DECLARE FUNCTION SymEnumSourceFiles IMPORT "ImageHlp.dll" ALIAS "SymEnumSourceFiles" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL ModBase AS QUAD _                              ' __in ULONG64 ModBase
 , BYREF Mask AS ASCIIZ _                               ' __in_opt PCSTR Mask
 , BYVAL cbSrcFiles AS DWORD _                          ' __in PSYM_ENUMSOURCEFILES_CALLBACK cbSrcFiles
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMSOURCEFILES_CALLBACKW)(
'    __in PSOURCEFILEW pSourceFile,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMSOURCEFILES_CALLBACKW ( _
'   BYREF pSourceFile AS SOURCEFILEW _                   ' __in PSOURCEFILEW pSourceFile
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymEnumSourceFilesW IMPORT "ImageHlp.dll" ALIAS "SymEnumSourceFilesW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL ModBase AS QUAD _                              ' __in ULONG64 ModBase
 , BYREF Mask AS WSTRINGZ _                             ' __in_opt PCWSTR Mask
 , BYVAL cbSrcFiles AS DWORD _                          ' __in PSYM_ENUMSOURCEFILES_CALLBACKW cbSrcFiles
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumerateModules64 IMPORT "ImageHlp.dll" ALIAS "SymEnumerateModules64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PSYM_ENUMMODULES_CALLBACK64 EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymEnumerateModulesW64 IMPORT "ImageHlp.dll" ALIAS "SymEnumerateModulesW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PSYM_ENUMMODULES_CALLBACKW64 EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymEnumerateModules SymEnumerateModules64
'#else
DECLARE FUNCTION SymEnumerateModules IMPORT "ImageHlp.dll" ALIAS "SymEnumerateModules" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PSYM_ENUMMODULES_CALLBACK EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION EnumerateLoadedModulesEx IMPORT "ImageHlp.dll" ALIAS "EnumerateLoadedModulesEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumLoadedModulesCallback AS DWORD _           ' __in PENUMLOADED_MODULES_CALLBACK64 EnumLoadedModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumerateLoadedModulesExW IMPORT "ImageHlp.dll" ALIAS "EnumerateLoadedModulesExW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumLoadedModulesCallback AS DWORD _           ' __in PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumerateLoadedModules64 IMPORT "ImageHlp.dll" ALIAS "EnumerateLoadedModules64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PENUMLOADED_MODULES_CALLBACK64 EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION EnumerateLoadedModulesW64 IMPORT "ImageHlp.dll" ALIAS "EnumerateLoadedModulesW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PENUMLOADED_MODULES_CALLBACKW64 EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define EnumerateLoadedModules EnumerateLoadedModules64
'#else
DECLARE FUNCTION EnumerateLoadedModules IMPORT "ImageHlp.dll" ALIAS "EnumerateLoadedModules" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL EnumModulesCallback AS DWORD _                 ' __in PENUMLOADED_MODULES_CALLBACK EnumModulesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymFunctionTableAccess64 IMPORT "ImageHlp.dll" ALIAS "SymFunctionTableAccess64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL AddrBase AS QUAD _                             ' __in DWORD64 AddrBase
 ) AS DWORD                                             ' PVOID

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymFunctionTableAccess SymFunctionTableAccess64
'#else
DECLARE FUNCTION SymFunctionTableAccess IMPORT "ImageHlp.dll" ALIAS "SymFunctionTableAccess" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL AddrBase AS DWORD _                            ' __in DWORD AddrBase
 ) AS DWORD                                             ' PVOID
'#endif

DECLARE FUNCTION SymGetUnwindInfo IMPORT "ImageHlp.dll" ALIAS "SymGetUnwindInfo" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*Size) PVOID Buffer
 , BYREF Size AS DWORD _                                ' __inout PULONG Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetModuleInfo64 IMPORT "ImageHlp.dll" ALIAS "SymGetModuleInfo64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 , BYREF ModuleInfo AS IMAGEHLP_MODULE64 _              ' __out PIMAGEHLP_MODULE64 ModuleInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetModuleInfoW64 IMPORT "ImageHlp.dll" ALIAS "SymGetModuleInfoW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 , BYREF ModuleInfo AS IMAGEHLP_MODULEW64 _             ' __out PIMAGEHLP_MODULEW64 ModuleInfo
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetModuleInfo   SymGetModuleInfo64
'#define SymGetModuleInfoW  SymGetModuleInfoW64
'#else
DECLARE FUNCTION SymGetModuleInfo IMPORT "ImageHlp.dll" ALIAS "SymGetModuleInfo" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS DWORD _                              ' __in DWORD qwAddr
 , BYREF ModuleInfo AS IMAGEHLP_MODULE _                ' __out PIMAGEHLP_MODULE ModuleInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetModuleInfoW IMPORT "ImageHlp.dll" ALIAS "SymGetModuleInfoW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS DWORD _                              ' __in DWORD qwAddr
 , BYREF ModuleInfo AS IMAGEHLP_MODULEW _               ' __out PIMAGEHLP_MODULEW ModuleInfo
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymGetModuleBase64 IMPORT "ImageHlp.dll" ALIAS "SymGetModuleBase64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 ) AS QUAD                                              ' DWORD64

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetModuleBase SymGetModuleBase64
'#else
DECLARE FUNCTION SymGetModuleBase IMPORT "ImageHlp.dll" ALIAS "SymGetModuleBase" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS DWORD _                              ' __in DWORD qwAddr
 ) AS DWORD                                             ' DWORD
'#endif

' // Size = 552 bytes
TYPE SRCCODEINFO QWORD FILL
   SizeOfStruct AS DWORD                    ' DWORD // set to sizeof(SRCCODEINFO)
   Key          AS DWORD                    ' PVOID // not used
   ModBase      AS QUAD                     ' DWORD64 // base address of module this applies to
   Obj          AS ASCIIZ * %MAX_PATH + 1   ' CHAR // the object file within the module
   FileName     AS ASCIIZ * %MAX_PATH + 1   ' CHAR // full filename
   LineNumber   AS DWORD                    ' DWORD // line number in file
   Address      AS QUAD                     ' DWORD64 // first instruction of line
END TYPE

' // Size = 1072 bytes
TYPE SRCCODEINFOW QWORD FILL
   SizeOfStruct AS DWORD                       ' DWORD // set to sizeof(SRCCODEINFO)
   Key          AS DWORD                       ' PVOID // not used
   ModBase      AS QUAD                        ' DWORD64 // base address of module this applies to
   Obj          AS WSTRINGZ * %MAX_PATH + 1    ' WCHAR // the object file within the module
   FileName     AS WSTRINGZ * %MAX_PATH + 1    ' WCHAR // full filename
   LineNumber   AS DWORD                       ' DWORD // line number in file
   Address      AS QUAD                        ' DWORD64 // first instruction of line
END TYPE

'typedef BOOL
'(CALLBACK *PSYM_ENUMLINES_CALLBACK)(
'    __in PSRCCODEINFO LineInfo,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMLINES_CALLBACK ( _
'   BYREF LineInfo AS SRCCODEINFO _                      ' __in PSRCCODEINFO LineInfo
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

' Requires version 6.1 or later.
DECLARE FUNCTION SymEnumLines IMPORT "ImageHlp.dll" ALIAS "SymEnumLines" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Obj AS ASCIIZ _                                ' __in_opt PCSTR Obj
 , BYREF File AS ASCIIZ _                               ' __in_opt PCSTR File
 , BYVAL EnumLinesCallback AS DWORD _                   ' __in PSYM_ENUMLINES_CALLBACK EnumLinesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMLINES_CALLBACKW)(
'    __in PSRCCODEINFOW LineInfo,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMLINES_CALLBACKW ( _
'   BYREF LineInfo AS SRCCODEINFOW _                     ' __in PSRCCODEINFOW LineInfo
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymEnumLinesW IMPORT "ImageHlp.dll" ALIAS "SymEnumLinesW" ( _
   BYVAL hProcess aS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Obj AS WSTRINGZ _                              ' __in_opt PCWSTR Obj
 , BYREF File AS WSTRINGZ _                             ' __in_opt PCWSTR File
 , BYVAL EnumLinesCallback AS DWORD _                   ' __in PSYM_ENUMLINES_CALLBACKW EnumLinesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetLineFromAddr64 IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromAddr64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 , BYREF pdwDisplacement AS DWORD _                     ' __out PDWORD pdwDisplacement
 , BYREF Line64 AS IMAGEHLP_LINE64 _                    ' __out PIMAGEHLP_LINE64 Line64
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetLineFromAddrW64 IMPORT "DbgHelp.dll" ALIAS "SymGetLineFromAddrW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 , BYREF pdwDisplacement AS DWORD _                     ' __out PDWORD pdwDisplacement
 , BYREF Line AS IMAGEHLP_LINEW64 _                     ' __out PIMAGEHLP_LINEW64 Line
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSourceLines IMPORT "ImageHlp.dll" ALIAS "SymEnumSourceLines" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Obj AS ASCIIZ _                                ' __in_opt PCSTR Obj
 , BYREF File AS ASCIIZ _                               ' __in_opt PCSTR File
 , BYVAL Line AS DWORD _                                ' __in_opt DWORD Line
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL EnumLinesCallback AS DWORD _                   ' __in PSYM_ENUMLINES_CALLBACK EnumLinesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSourceLinesW IMPORT "ImageHlp.dll" ALIAS "SymEnumSourceLinesW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Obj AS WSTRINGZ _                              ' __in_opt PCWSTR Obj
 , BYREF File AS WSTRINGZ _                             ' __in_opt PCWSTR File
 , BYVAL Line AS DWORD _                                ' __in_opt DWORD Line
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL EnumLinesCallback AS DWORD _                   ' __in PSYM_ENUMLINES_CALLBACKW EnumLinesCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'// flags for SymEnumSourceLines

%ESLFLAG_FULLPATH        = &H1???
%ESLFLAG_NEAREST         = &H2???
%ESLFLAG_PREV            = &H4???
%ESLFLAG_NEXT            = &H8???

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetLineFromAddr SymGetLineFromAddr64
'#define SymGetLineFromAddrW SymGetLineFromAddrW64
'#else
DECLARE FUNCTION SymGetLineFromAddr IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromAddr" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE         hProcess
 , BYVAL dwAddr AS DWORD _                              ' __in  DWORD          dwAddr
 , BYREF pdwDisplacement AS DWORD _                     ' __out PDWORD         pdwDisplacement
 , BYREF Line AS IMAGEHLP_LINE _                        ' __out PIMAGEHLP_LINE Line
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetLineFromAddrW IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromAddrW" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE          hProcess
 , BYVAL dwAddr AS DWORD _                              ' __in  DWORD           dwAddr
 , BYREF pdwDisplacement AS DWORD _                     ' __out PDWORD          pdwDisplacement
 , BYREF Line AS IMAGEHLP_LINEW _                       ' __out PIMAGEHLP_LINEW Line
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymGetLineFromName64 IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromName64" ( _
   BYVAL hProcess AS DWORD _                            ' __in     HANDLE           hProcess
 , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR            ModuleName
 , BYREF FileName AS ASCIIZ _                           ' __in_opt PCSTR            FileName
 , BYVAL dwLineNumber AS DWORD _                        ' __in     DWORD            dwLineNumber
 , BYREF plDisplacement AS LONG _                       ' __out    PLONG            plDisplacement
 , BYREF Line AS IMAGEHLP_LINE64 _                      ' __inout  PIMAGEHLP_LINE64 Line
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetLineFromNameW64 IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromNameW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in     HANDLE            hProcess
 , BYREF ModuleName AS WSTRINGZ _                       ' __in_opt PCWSTR            ModuleName
 , BYREF FileName AS WSTRINGZ _                         ' __in_opt PCWSTR            FileName
 , BYVAL dwLineNumber AS DWORD _                        ' __in     DWORD             dwLineNumber
 , BYREF plDisplacement AS LONG _                       ' __out    PLONG             plDisplacement
 , BYREF Line AS IMAGEHLP_LINEW64 _                     ' __inout  PIMAGEHLP_LINEW64 Line
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetLineFromName SymGetLineFromName64
'#else
DECLARE FUNCTION SymGetLineFromName IMPORT "ImageHlp.dll" ALIAS "SymGetLineFromName" ( _
   BYVAL hProcess AS DWORD _                            ' __in     HANDLE         hProcess
 , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR          ModuleName
 , BYREF FileName AS ASCIIZ _                           ' __in_opt PCSTR          FileName
 , BYVAL dwLineNumber AS DWORD _                        ' __in     DWORD          dwLineNumber
 , BYREF plDisplacement AS LONG _                       ' __out    PLONG          plDisplacement
 , BYREF Line AS IMAGEHLP_LINE _                        ' __inout  PIMAGEHLP_LINE Line
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymGetLineNext64 IMPORT "ImageHlp.dll" ALIAS "SymGetLineNext64" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE           hProcess
 , BYREF Line AS IMAGEHLP_LINE64 _                      ' __inout PIMAGEHLP_LINE64 Line
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetLineNextW64 IMPORT "ImageHlp.dll" ALIAS "SymGetLineNextW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE            hProcess
 , BYREF Line AS IMAGEHLP_LINEW64 _                     ' __inout PIMAGEHLP_LINEW64 Line
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetLineNext SymGetLineNext64
'#else
DECLARE FUNCTION SymGetLineNext IMPORT "ImageHlp.dll" ALIAS "SymGetLineNext" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE         hProcess
 , BYREF Line AS IMAGEHLP_LINE _                        ' __inout PIMAGEHLP_LINE Line
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetLineNextW IMPORT "ImageHlp.dll" ALIAS "SymGetLineNextW" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE          hProcess
 , BYREF Line AS IMAGEHLP_LINEW _                       ' __inout PIMAGEHLP_LINEW Line
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymGetLinePrev64 IMPORT "ImageHlp.dll" ALIAS "SymGetLinePrev64" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE           hProcess
 , BYREF Line AS IMAGEHLP_LINE64 _                      ' __inout PIMAGEHLP_LINE64 Line
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetLinePrevW64 IMPORT "ImageHlp.dll" ALIAS "SymGetLinePrevW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE            hProcess
 , BYREF Line AS IMAGEHLP_LINEW64 _                     ' __inout PIMAGEHLP_LINEW64 Line
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetLinePrev SymGetLinePrev64
'#else
DECLARE FUNCTION SymGetLinePrev IMPORT "ImageHlp.dll" ALIAS "SymGetLinePrev" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE         hProcess
 , BYREF Line AS IMAGEHLP_LINE _                        ' __inout PIMAGEHLP_LINE Line
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetLinePrevW IMPORT "ImageHlp.dll" ALIAS "SymGetLinePrevW" ( _
   BYVAL hProcess AS DWORD _                            ' __in    HANDLE          hProcess
 , BYREF Line AS IMAGEHLP_LINEW _                       ' __inout PIMAGEHLP_LINEW Line
 ) AS LONG                                              ' BOOL
'#endif

' Does not exist in ImageHlp.dll; it exists in DbgHelp.dll
'DECLARE FUNCTION SymGetFileLineOffsets64 IMPORT "ImageHlp.dll" ALIAS "SymGetFileLineOffsets64" ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR ModuleName
' , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
' , BYREF Buffer AS QUAD _                               ' __out_ecount(BufferLines) PDWORD64 Buffer
' , BYVAL BufferLines AS DWORD _                         ' __in ULONG BufferLines
' ) AS DWORD                                             ' ULONG

DECLARE FUNCTION SymMatchFileName IMPORT "ImageHlp.dll" ALIAS "SymMatchFileName" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF Match AS ASCIIZ _                              ' __in PCSTR Match
 , BYREF FileNameStop AS DWORD _                        ' __deref_opt_out PSTR *FileNameStop
 , BYREF MatchStop as DWORD _                           ' __deref_opt_out PSTR *MatchStop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymMatchFileNameW IMPORT "ImageHlp.dll" ALIAS "SymMatchFileNameW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF Match AS WSTRINGZ _                            ' __in PCWSTR Match
 , OPTIONAL BYREF FileNameStop AS DWORD _               ' __deref_opt_out PWSTR *FileNameStop
 , OPTIONAL BYREF MatchStop AS DWORD _                  ' __deref_opt_out PWSTR *MatchStop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFile IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFile" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Params AS ASCIIZ _                             ' __in PCSTR Params
 , BYREF FileSpec AS ASCIIZ _                           ' __in PCSTR FileSpec
 , BYREF FilePath AS ASCIIZ _                           ' __out_ecount(Size) PSTR FilePath
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFileW IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFileW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF Params AS WSTRINGZ _                           ' __in PCWSTR Params
 , BYREF FileSpec AS WSTRINGZ _                         ' __in PCWSTR FileSpec
 , BYREF FilePath AS WSTRINGZ _                         ' __out_ecount(Size) PWSTR FilePath
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFileToken IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFileToken" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF FileSpec AS ASCIIZ _                           ' __in PCSTR FileSpec
 , BYREF Token AS ANY _                                 ' __deref_out PVOID *Token
 , BYREF Size AS DWORD _                                ' __out DWORD *Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFileTokenW IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFileTokenW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF FileSpec AS WSTRINGZ _                         ' __in PCWSTR FileSpec
 , BYREF Token AS ANY _                                 ' __deref_out PVOID *Token
 , BYREF Size AS DWORD _                                ' __out DWORD *Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFileFromToken IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFileFromToken" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Token AS DWORD _                               ' __in PVOID Token
 , BYREF Params AS ASCIIZ _                             ' __in PCSTR Params
 , BYREF FilePath AS ASCIIZ _                           ' __out_ecount(Size) PSTR FilePath
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceFileFromTokenW IMPORT "ImageHlp.dll" ALIAS "SymGetSourceFileFromTokenW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Token AS DWORD _                               ' __in PVOID Token
 , BYREF Params AS WSTRINGZ _                           ' __in PCWSTR Params
 , BYREF FilePath AS WSTRINGZ _                         ' __out_ecount(Size) PWSTR FilePath
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceVarFromToken IMPORT "ImageHlp.dll" ALIAS "SymGetSourceVarFromToken" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Token AS DWORD _                               ' __in PVOID Token
 , BYREF Params AS ASCIIZ _                             ' __in_opt PCSTR Params
 , BYREF VarName AS ASCIIZ _                            ' __in PCSTR VarName
 , BYREF Value AS ASCIIZ _                              ' __out_ecount(Size) PSTR Value
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSourceVarFromTokenW IMPORT "ImageHlp.dll" ALIAS "SymGetSourceVarFromTokenW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Token AS DWORD _                               ' __in PVOID Token
 , BYREF Params AS WSTRINGZ _                           ' __in_opt PCWSTR Params
 , BYREF VarName AS WSTRINGZ _                          ' __in PCWSTR VarName
 , BYVAL Value AS DWORD _                               ' __out_ecount(Size) PSTR Value
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 ) AS LONG                                              ' BOOL

'typedef BOOL (CALLBACK *PENUMSOURCEFILETOKENSCALLBACK)(__in PVOID token,  __in size_t size);
'FUNCTION ENUMSOURCEFILETOKENSCALLBACK (BYVAL token AS DWORD, BYVAL nsize AS DWORD) AS LONG

DECLARE FUNCTION SymEnumSourceFileTokens IMPORT "ImageHlp.dll" ALIAS "SymEnumSourceFileTokens" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYVAL Callback AS DWORD _                            ' __in PENUMSOURCEFILETOKENSCALLBACK Callback
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymInitializeA IMPORT "ImageHlp.dll" ALIAS "SymInitialize" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF UserSearchPath AS ASCIIZ _                     ' __in_opt PCSTR UserSearchPath
 , BYVAL fInvadeProcess AS LONG _                       ' __in BOOL fInvadeProcess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymInitializeW IMPORT "ImageHlp.dll" ALIAS "SymInitializeW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF UserSearchPath AS WSTRINGZ _                   ' __in_opt PCWSTR UserSearchPath
 , BYVAL fInvadeProcess AS LONG _                       ' __in BOOL fInvadeProcess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSearchPath IMPORT "ImageHlp.dll" ALIAS "SymGetSearchPath" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SearchPath AS ASCIIZ _                         ' __out_ecount(SearchPathLength) PSTR SearchPath
 , BYVAL SearchPathLength AS DWORD _                    ' __in DWORD SearchPathLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSearchPathW IMPORT "ImageHlp.dll" ALIAS "SymGetSearchPathW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SearchPath AS WSTRINGZ _                       ' __out_ecount(SearchPathLength) PWSTR SearchPath
 , BYVAL SearchPathLength AS DWORD _                    ' __in DWORD SearchPathLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSetSearchPath IMPORT "ImageHlp.dll" ALIAS "SymSetSearchPath" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , OPTIONAL BYREF SearchPath AS ASCIIZ _                ' __in_opt PCSTR SearchPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSetSearchPathW IMPORT "ImageHlp.dll" ALIAS "SymSetSearchPathW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , OPTIONAL BYREF SearchPath AS WSTRINGZ _              ' __in_opt PCWSTR SearchPath
 ) AS LONG                                              ' BOOL

%SLMFLAG_VIRTUAL     = &H1???
%SLMFLAG_ALT_INDEX   = &H2???
%SLMFLAG_NO_SYMBOLS  = &H4???

DECLARE FUNCTION SymLoadModuleEx IMPORT "ImageHlp.dll" ALIAS "SymLoadModuleEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hFile AS DWORD _                               ' __in_opt HANDLE hFile
 , BYREF ImageName AS ASCIIZ _                          ' __in_opt PCSTR ImageName
 , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR ModuleName
 , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
 , BYVAL DllSize AS DWORD _                             ' __in DWORD DllSize
 , OPTIONAL BYREF Data AS MODLOAD_DATA _                ' __in_opt PMODLOAD_DATA Data
 , OPTIONAL BYVAL Flags AS DWORD _                      ' __in_opt DWORD Flags
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION SymLoadModuleExW IMPORT "ImageHlp.dll" ALIAS "SymLoadModuleExW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hFile AS DWORD _                               ' __in_opt HANDLE hFile
 , BYREF ImageName AS WSTRINGZ _                        ' __in_opt PCWSTR ImageName
 , BYREF ModuleName AS WSTRINGZ _                       ' __in_opt PCWSTR ModuleName
 , BYREF BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
 , BYVAL DllSize AS DWORD _                             ' __in DWORD DllSize
 , OPTIONAL BYREF Data AS MODLOAD_DATA _                ' __in_opt PMODLOAD_DATA Data
 , OPTIONAL BYVAL Flags AS DWORD _                      ' __in_opt DWORD Flags
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION SymUnloadModule64 IMPORT "ImageHlp.dll" ALIAS "SymUnloadModule64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymUnloadModule SymUnloadModule64
'#else
DECLARE FUNCTION SymUnloadModule IMPORT "ImageHlp.dll" ALIAS "SymUnloadModule" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS DWORD _                           ' __in DWORD BaseOfDll
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymUnDName64 IMPORT "ImageHlp.dll" ALIAS "SymUnDName64" ( _
   BYREF sym AS IMAGEHLP_SYMBOL64 _                     ' __in PIMAGEHLP_SYMBOL64 sym  // Symbol to undecorate
 , BYREF UnDecName AS ASCIIZ _                          ' __out_ecount(UnDecNameLength) PSTR UnDecName   // Buffer to store undecorated name in
 , BYVAL UnDecNameLength AS DWORD _                     ' __in DWORD UnDecNameLength   // Size of the buffer
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymUnDName SymUnDName64
'#else
DECLARE FUNCTION SymUnDName IMPORT "ImageHlp.dll" ALIAS "SymUnDName" ( _
   BYREF sym AS IMAGEHLP_SYMBOL _                       ' __in PIMAGEHLP_SYMBOL sym  // Symbol to undecorate
 , BYREF UnDecName AS ASCIIZ _                          ' __out_ecount(UnDecNameLength) PSTR UnDecName   // Buffer to store undecorated name in
 , BYVAL UnDecNameLength AS DWORD _                     ' __in DWORD UnDecNameLength // Size of the buffer
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymRegisterCallback64 IMPORT "ImageHlp.dll" ALIAS "SymRegisterCallback64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL CallbackFunction AS DWORD _                    ' __in PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction
 , BYVAL UserContext AS QUAD _                          ' __in ULONG64 UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymRegisterCallbackW64 IMPORT "ImageHlp.dll" ALIAS "SymRegisterCallbackW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL CallbackFunction AS DWORD _                    ' __in PSYMBOL_REGISTERED_CALLBACK64W CallbackFunction
 , BYVAL UserContext AS QUAD _                          ' __in ULONG64 UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymRegisterFunctionEntryCallback64 IMPORT "ImageHlp.dll" ALIAS "SymRegisterFunctionEntryCallback64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL CallbackFunction AS DWORD _                    ' __in PSYMBOL_FUNCENTRY_CALLBACK64 CallbackFunction
 , BYVAL UserContext AS QUAD _                          ' __in ULONG64 UserContext
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymRegisterCallback SymRegisterCallback64
'#define SymRegisterFunctionEntryCallback SymRegisterFunctionEntryCallback64
'#else
DECLARE FUNCTION SymRegisterCallback IMPORT "ImageHlp.dll" ALIAS "SymRegisterCallback" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL CallbackFunction AS DWORD _                    ' __in PSYMBOL_REGISTERED_CALLBACK CallbackFunction
 , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymRegisterFunctionEntryCallback IMPORT "ImageHlp.dll" ALIAS "SymRegisterFunctionEntryCallback" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL CallbackFunction AS DWORD _                    ' __in PSYMBOL_FUNCENTRY_CALLBACK CallbackFunction
 , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
 ) AS LONG                                              ' BOOL
'#endif

' // Size = 258 bytes
TYPE IMAGEHLP_SYMBOL_SRC DWORD
   sizeofstruct AS DWORD                ' DWORD
   type         AS DWORD                ' DWORD
   file         AS ASCIIZ * %MAX_PATH   ' char
END TYPE

' // Size = 6 bytes
TYPE MODULE_TYPE_INFO WORD
   dataLength AS WORD   ' USHORT
   leaf       AS WORD   ' USHORT
   data(0)    AS BYTE   ' BYTE
END TYPE

' // Size in C++ = 88 bytes
TYPE SYMBOL_INFO QWORD FILL
   SizeOfStruct AS DWORD        ' ULONG
   TypeIndex    AS DWORD        ' ULONG // Type Index of symbol
   Reserved(1)  AS QUAD         ' ULONG64
   Index        AS DWORD        ' ULONG
   Size         AS DWORD        ' ULONG
   ModBase      AS QUAD         ' ULONG64 // Base Address of module comtaining this symbol
   Flags        AS DWORD        ' ULONG
   Value        AS QUAD         ' ULONG64 // Value of symbol, ValuePresent should be 1
   Address      AS QUAD         ' ULONG64 // Address of symbol including base address of module
   Register     AS DWORD        ' ULONG // register holding value or pointer to value
   Scope        AS DWORD        ' ULONG // scope of the symbol
   Tag          AS DWORD        ' ULONG // pdb classification
   NameLen      AS DWORD        ' ULONG // Actual length of name
   MaxNameLen   AS DWORD        ' ULONG
   Name         AS ASCIIZ * 1   ' CHAR // Name of symbol
END TYPE

' // Size in C++ = 2096 bytes
TYPE SYMBOL_INFO_PACKAGE QWORD FILL
   si   AS SYMBOL_INFO
   name AS ASCIIZ * (%MAX_SYM_NAME + 1)   ' CHAR name[MAX_SYM_NAME + 1]
END TYPE

' // Size in C++ = 88 bytes
TYPE SYMBOL_INFOW QWORD FILL
   SizeOfStruct AS DWORD          ' ULONG
   TypeIndex    AS DWORD          ' ULONG // Type Index of symbol
   Reserved(1)  AS QUAD           ' ULONG64
   Index        AS DWORD          ' ULONG
   Size         AS DWORD          ' ULONG
   ModBase      AS QUAD           ' ULONG64 // Base Address of module comtaining this symbol
   Flags        AS DWORD          ' ULONG
   Value        AS QUAD           ' ULONG64 // Value of symbol, ValuePresent should be 1
   Address      AS QUAD           ' ULONG64 // Address of symbol including base address of module
   Register     AS DWORD          ' ULONG // register holding value or pointer to value
   Scope        AS DWORD          ' ULONG // scope of the symbol
   Tag          AS DWORD          ' ULONG // pdb classification
   NameLen      AS DWORD          ' ULONG // Actual length of name
   MaxNameLen   AS DWORD          ' ULONG
   Name         AS WSTRINGZ * 1   ' CHAR // Name of symbol
END TYPE

' // Size in C++ = 4096 bytes
TYPE SYMBOL_INFO_PACKAGEW QWORD FILL
   si   AS SYMBOL_INFOW
   name AS WSTRINGZ * (%MAX_SYM_NAME + 1)   ' WCHAR name[MAX_SYM_NAME + 1]
END TYPE

' // Size = 128 bytes
TYPE IMAGEHLP_STACK_FRAME DWORD
   InstructionOffset  AS QUAD    ' ULONG64
   ReturnOffset       AS QUAD    ' ULONG64
   FrameOffset        AS QUAD    ' ULONG64
   StackOffset        AS QUAD    ' ULONG64
   BackingStoreOffset AS QUAD    ' ULONG64
   FuncTableEntry     AS QUAD    ' ULONG64
   Params(3)          AS QUAD    ' ULONG64
   Reserved(4)        AS QUAD    ' ULONG64
   Virtual            AS LONG    ' BOOL
   Reserved2          AS DWORD   ' ULONG
END TYPE

'typedef VOID IMAGEHLP_CONTEXT, *PIMAGEHLP_CONTEXT;

DECLARE FUNCTION SymSetContext IMPORT "ImageHlp.dll" ALIAS "SymSetContext" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF StackFrame AS IMAGEHLP_STACK_FRAME _           ' __in PIMAGEHLP_STACK_FRAME StackFrame
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PIMAGEHLP_CONTEXT Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSetScopeFromAddr IMPORT "ImageHlp.dll" ALIAS "SymSetScopeFromAddr" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in ULONG64 Address
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSetScopeFromIndex IMPORT "ImageHlp.dll" ALIAS "SymSetScopeFromIndex" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in DWORD Index
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMPROCESSES_CALLBACK)(
'    __in HANDLE hProcess,
'    __in PVOID UserContext
'    );

'FUNCTION SYM_ENUMPROCESSES_CALLBACK ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumProcesses IMPORT "ImageHlp.dll" ALIAS "SymEnumProcesses" ( _
   BYVAL EnumProcessesCallback AS DWORD _               ' __in PSYM_ENUMPROCESSES_CALLBACK EnumProcessesCallback
 , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromAddr IMPORT "ImageHlp.dll" ALIAS "SymFromAddr" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYREF Displacement AS QUAD _                         ' __out_opt PDWORD64 Displacement
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromAddrW IMPORT "ImageHlp.dll" ALIAS "SymFromAddrW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYREF Displacement AS QUAD _                         ' __out_opt PDWORD64 Displacement
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromToken IMPORT "ImageHlp.dll" ALIAS "SymFromToken" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in DWORD64 Base
 , BYVAL Token AS DWORD _                               ' __in DWORD Token
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromTokenW IMPORT "ImageHlp.dll" ALIAS "SymFromTokenW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in DWORD64 Base
 , BYVAL Token AS DWORD _                               ' __in DWORD Token
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymNext IMPORT "ImageHlp.dll" ALIAS "SymNext" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF si AS SYMBOL_INFO _                            ' __inout PSYMBOL_INFO si
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymNextW IMPORT "ImageHlp.dll" ALIAS "SymNextW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF siw AS SYMBOL_INFOW _                          ' __inout PSYMBOL_INFOW siw
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymPrev IMPORT "ImageHlp.dll" ALIAS "SymPrev" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF si AS SYMBOL_INFO _                            ' __inout PSYMBOL_INFO si
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymPrevW IMPORT "ImageHlp.dll" ALIAS "SymPrevW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF siw AS SYMBOL_INFOW _                          ' __inout PSYMBOL_INFOW siw
 ) AS LONG                                              ' BOOL

'// While SymFromName will provide a symbol from a name,
'// SymEnumSymbols can provide the same matching information
'// for ALL symbols with a matching name, even regular
'// expressions.  That way you can search across modules
'// and differentiate between identically named symbols.

DECLARE FUNCTION SymFromName IMPORT "ImageHlp.dll" ALIAS "SymFromName" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymFromNameW IMPORT "ImageHlp.dll" ALIAS "SymFromNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Name AS WSTRINGZ _                             ' __in PCWSTR Name
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

'typedef BOOL
'(CALLBACK *PSYM_ENUMERATESYMBOLS_CALLBACK)(
'    __in PSYMBOL_INFO pSymInfo,
'    __in ULONG SymbolSize,
'    __in_opt PVOID UserContext
'    );

'FUNCTION SYM_ENUMERATESYMBOLS_CALLBACK ( _
'   BYREF pSymInfo AS SYMBOL_INFO _                      ' __in PSYMBOL_INFO pSymInfo
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSymbols IMPORT "ImageHlp.dll" ALIAS "SymEnumSymbols" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Mask AS ASCIIZ _                               ' __in_opt PCSTR Mask
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

'FUNCTION SYM_ENUMERATESYMBOLS_CALLBACKW ( _
'   BYREF pSymInfo AS SYMBOL_INFOW _                     ' __in PSYMBOL_INFOW pSymInfo
' , BYVAL SymbolSize AS DWORD _                          ' __in ULONG SymbolSize
' , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSymbolsW IMPORT "ImageHlp.dll" ALIAS "SymEnumSymbolsW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Mask AS ASCIIZ _                               ' __in_opt PCSTR Mask
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSymbolsForAddr IMPORT "ImageHlp.dll" ALIAS "SymEnumSymbolsForAddr" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSymbolsForAddrW IMPORT "ImageHlp.dll" ALIAS "SymEnumSymbolsForAddrW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

%SYMSEARCH_MASKOBJS      = &H01???   ' // used internally to implement other APIs
%SYMSEARCH_RECURSE       = &H02???   ' // recurse scopes
%SYMSEARCH_GLOBALSONLY   = &H04???   ' // search only for global symbols

DECLARE FUNCTION SymSearch IMPORT "ImageHlp.dll" ALIAS "SymSearch" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYVAL SymTag AS DWORD _                              ' __in_opt DWORD SymTag
 , BYREF Mask AS ASCIIZ _                               ' __in_opt PCSTR Mask
 , BYVAL Address AS QUAD _                              ' __in_opt DWORD64 Address
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , BYVAL UserContext AS DWORD _                         ' __in_opt PVOID UserContext
 , BYVAL Options AS DWORD _                             ' __in DWORD Options
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSearchW IMPORT "ImageHlp.dll" ALIAS "SymSearchW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYVAL SymTag AS DWORD _                              ' __in_opt DWORD SymTag
 , BYREF Mask AS WSTRINGZ _                             ' __in_opt PCWSTR Mask
 , BYVAL Address AS QUAD _                              ' __in_opt DWORD64 Address
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , BYVAL UserContext AS DWORD _                         ' __in_opt PVOID UserContext
 , BYVAL Options AS DWORD _                             ' __in DWORD Options
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetScope IMPORT "ImageHlp.dll" ALIAS "SymGetScope" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetScopeW IMPORT "ImageHlp.dll" ALIAS "SymGetScopeW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromIndex IMPORT "ImageHlp.dll" ALIAS "SymFromIndex" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymFromIndexW IMPORT "ImageHlp.dll" ALIAS "SymFromIndexW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL Index AS DWORD _                               ' __in_opt DWORD Index
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

' enum IMAGEHLP_SYMBOL_TYPE_INFO
%TI_GET_SYMTAG                   = 0???
%TI_GET_SYMNAME                  = 1???
%TI_GET_LENGTH                   = 2???
%TI_GET_TYPE                     = 3???
%TI_GET_TYPEID                   = 4???
%TI_GET_BASETYPE                 = 5???
%TI_GET_ARRAYINDEXTYPEID         = 6???
%TI_FINDCHILDREN                 = 7???
%TI_GET_DATAKIND                 = 8???
%TI_GET_ADDRESSOFFSET            = 9???
%TI_GET_OFFSET                   = 10???
%TI_GET_VALUE                    = 11???
%TI_GET_COUNT                    = 12???
%TI_GET_CHILDRENCOUNT            = 13???
%TI_GET_BITPOSITION              = 14???
%TI_GET_VIRTUALBASECLASS         = 15???
%TI_GET_VIRTUALTABLESHAPEID      = 16???
%TI_GET_VIRTUALBASEPOINTEROFFSET = 17???
%TI_GET_CLASSPARENTID            = 18???
%TI_GET_NESTED                   = 19???
%TI_GET_SYMINDEX                 = 20???
%TI_GET_LEXICALPARENT            = 21???
%TI_GET_ADDRESS                  = 22???
%TI_GET_THISADJUST               = 23???
%TI_GET_UDTKIND                  = 24???
%TI_IS_EQUIV_TO                  = 25???
%TI_GET_CALLING_CONVENTION       = 26???
%TI_IS_CLOSE_EQUIV_TO            = 27???
%TI_GTIEX_REQS_VALID             = 28???
%TI_GET_VIRTUALBASEOFFSET        = 29???
%TI_GET_VIRTUALBASEDISPINDEX     = 30???
%TI_GET_IS_REFERENCE             = 31???
%TI_GET_INDIRECTVIRTUALBASECLASS = 32???
%IMAGEHLP_SYMBOL_TYPE_INFO_MAX   = 33???

' // Size = 12 bytes
TYPE TI_FINDCHILDREN_PARAMS DWORD
   Count      AS DWORD   ' ULONG
   Start      AS DWORD   ' ULONG
   ChildId(0) AS DWORD   ' ULONG
END TYPE

DECLARE FUNCTION SymGetTypeInfo IMPORT "ImageHlp.dll" ALIAS "SymGetTypeInfo" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL ModBase AS QUAD _                              ' __in DWORD64 ModBase
 , BYVAL TypeId AS DWORD _                              ' __in ULONG TypeId
 , BYVAL GetType AS DWORD _                             ' __in IMAGEHLP_SYMBOL_TYPE_INFO GetType
 , BYREF pInfo AS ANY _                                 ' __out PVOID pInfo
 ) AS LONG                                              ' BOOL

%IMAGEHLP_GET_TYPE_INFO_UNCACHED = &H00000001???
%IMAGEHLP_GET_TYPE_INFO_CHILDREN = &H00000002???

' // Size = 88 bytes
TYPE IMAGEHLP_GET_TYPE_INFO_PARAMS   ' Must be 8 bytes aligned
   SizeOfStruct   AS DWORD       ' ULONG
   Flags          AS DWORD       ' ULONG
   NumIds         AS DWORD       ' ULONG
   TypeIds        AS DWORD PTR   ' PULONG
   TagFilter      AS QUAD        ' ULONG64
   NumReqs        AS DWORD       ' ULONG
   ReqKinds       AS DWORD PTR   ' IMAGEHLP_SYMBOL_TYPE_INFO*
   ReqOffsets     AS DWORD PTR   ' PULONG_PTR
   ReqSizes       AS DWORD PTR   ' PULONG
   ReqStride      AS DWORD       ' ULONG_PTR
   BufferSize     AS DWORD       ' ULONG_PTR
   Buffer         AS DWORD       ' PVOID
   EntriesMatched AS DWORD       ' ULONG
   EntriesFilled  AS DWORD       ' ULONG
   alignment__    AS DWORD       ' // To keep 8 bytes alignment
   TagsFound      AS QUAD        ' ULONG64
   AllReqsValid   AS QUAD        ' ULONG64
   NumReqsValid   AS DWORD       ' ULONG
   ReqsValid      AS QUAD PTR    ' PULONG64
END TYPE

DECLARE FUNCTION SymGetTypeInfoEx IMPORT "ImageHlp.dll" ALIAS "SymGetTypeInfoEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL ModBase AS QUAD _                              ' __in DWORD64 ModBase
 , BYREF Params AS IMAGEHLP_GET_TYPE_INFO_PARAMS _      ' __inout PIMAGEHLP_GET_TYPE_INFO_PARAMS Params
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumTypes IMPORT "ImageHlp.dll" ALIAS "SymEnumTypes" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumTypesW IMPORT "ImageHlp.dll" ALIAS "SymEnumTypesW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumTypesByName IMPORT "DbgHelp.dll" ALIAS "SymEnumTypesByName" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF mask AS ASCIIZ _                               ' __in_opt PCSTR mask
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumTypesByNameW IMPORT "DbgHelp.dll" ALIAS "SymEnumTypesByNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF mask AS WSTRINGZ _                             ' __in_opt PCWSTR mask
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetTypeFromName IMPORT "ImageHlp.dll" ALIAS "SymGetTypeFromName" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYREF Symbol AS SYMBOL_INFO _                        ' __inout PSYMBOL_INFO Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetTypeFromNameW IMPORT "ImageHlp.dll" ALIAS "SymGetTypeFromNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS WSTRINGZ _                             ' __in PCWSTR Name
 , BYREF Symbol AS SYMBOL_INFOW _                       ' __inout PSYMBOL_INFOW Symbol
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymAddSymbolA IMPORT "ImageHlp.dll" ALIAS "SymAddSymbol" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymAddSymbolW IMPORT "ImageHlp.dll" ALIAS "SymAddSymbolW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS WSTRINGZ _                             ' __in PCWSTR Name
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL Size AS DWORD _                                ' __in DWORD Size
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymDeleteSymbolA IMPORT "ImageHlp.dll" ALIAS "SymDeleteSymbol" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymDeleteSymbolW IMPORT "ImageHlp.dll" ALIAS "SymDeleteSymbolW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYREF Name AS WSTRINGZ _                             ' __in PCWSTR Name
 , BYVAL Address AS QUAD _                              ' __in DWORD64 Address
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymRefreshModuleList IMPORT "ImageHlp.dll" ALIAS "SymRefreshModuleList" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymAddSourceStream IMPORT "ImageHlp.dll" ALIAS "SymAddSourceStream" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF StreamFile AS ASCIIZ _                         ' __in_opt PCSTR StreamFile
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount_opt(Size) PBYTE Buffer
 , BYVAL Size AS DWORD _                                ' __in size_t Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymAddSourceStreamA IMPORT "ImageHlp.dll" ALIAS "SymAddSourceStreamA" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF StreamFile AS ASCIIZ _                         ' __in_opt PCSTR StreamFile
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount_opt(Size) PBYTE Buffer
 , BYVAL Size AS DWORD _                                ' __in size_t Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymAddSourceStreamW IMPORT "ImageHlp.dll" ALIAS "SymAddSourceStreamW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL Base AS QUAD _                                 ' __in ULONG64 Base
 , BYREF StreamFile AS WSTRINGZ _                       ' __in_opt PCWSTR StreamFile
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount_opt(Size) PBYTE Buffer
 , BYVAL Size AS DWORD _                                ' __in size_t Size
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvIsStoreW IMPORT "ImageHlp.dll" ALIAS "SymSrvIsStoreW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF path AS WSTRINGZ _                             ' __in PCWSTR path
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvIsStore IMPORT "ImageHlp.dll" ALIAS "SymSrvIsStore" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF path AS ASCIIZ _                               ' __in PCSTR path
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvDeltaName IMPORT "ImageHlp.dll" ALIAS "SymSrvDeltaName" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SymPath AS ASCIIZ _                            ' __in_opt PCSTR SymPath
 , BYREF Type AS ASCIIZ _                               ' __in PCSTR Type
 , BYREF File1 AS ASCIIZ _                              ' __in PCSTR File1
 , BYREF File2 AS ASCIIZ _                              ' __in PCSTR File2
 ) AS DWORD                                             ' PCSTR

DECLARE FUNCTION SymSrvDeltaNameW IMPORT "ImageHlp.dll" ALIAS "SymSrvDeltaNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SymPath AS WSTRINGZ _                          ' __in_opt PCWSTR SymPath
 , BYREF Type AS WSTRINGZ _                             ' __in PCWSTR Type
 , BYREF File1 AS WSTRINGZ _                            ' __in PCWSTR File1
 , BYREF File2 AS WSTRINGZ _                            ' __in PCWSTR File2
 ) AS DWORD                                             ' PCWSTR

DECLARE FUNCTION SymSrvGetSupplement IMPORT "ImageHlp.dll" ALIAS "SymSrvGetSupplement" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SymPath AS ASCIIZ _                            ' __in_opt PCSTR SymPath
 , BYREF Node AS ASCIIZ _                               ' __in PCSTR Node
 , BYREF File AS ASCIIZ _                               ' __in PCSTR File
 ) AS DWORD                                             ' PCSTR

DECLARE FUNCTION SymSrvGetSupplementW IMPORT "ImageHlp.dll" ALIAS "SymSrvGetSupplementW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SymPath AS WSTRINGZ _                          ' __in_opt PCWSTR SymPath
 , BYREF Node AS WSTRINGZ _                             ' __in PCWSTR Node
 , BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 ) AS DWORD                                             ' PCWSTR

DECLARE FUNCTION SymSrvGetFileIndexes IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexes" ( _
   BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYREF Id AS GUID _                                   ' __out GUID *Id
 , BYREF Val1 AS DWORD _                                ' __out PDWORD Val1
 , BYREF Val2 AS DWORD _                                ' __out_opt PDWORD Val2
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvGetFileIndexesW IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexesW" ( _
   BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 , BYREF Id AS GUID _                                   ' __out GUID *Id
 , BYREF Val1 AS DWORD _                                ' __out PDWORD Val1
 , BYREF Val2 AS DWORD _                                ' __out_opt PDWORD Val2
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvGetFileIndexStringW IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexStringW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SrvPath AS WSTRINGZ _                          ' __in_opt PCWSTR SrvPath
 , BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 , BYREF Index AS WSTRINGZ _                            ' __out_ecount(Size) PWSTR Index
 , BYVAL Size AS DWORD _                                ' __in size_t Size
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvGetFileIndexString IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexString" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SrvPath AS ASCIIZ _                            ' __in_opt PCSTR SrvPath
 , BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYREF Index AS ASCIIZ _                              ' __out_ecount(Size) PSTR Index
 , BYVAL Size AS DWORD _                                ' __in size_t Size
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

' // Size = 828 bytes
TYPE SYMSRV_INDEX_INFO BYTE
   sizeofstruct AS DWORD                    ' DWORD
   file         AS ASCIIZ * %MAX_PATH + 1   ' char
   filller1_(2) AS BYTE                     ' // To keep alignment
   stripped     AS LONG                     ' BOOL
   timestamp    AS DWORD                    ' DWORD
   size         AS DWORD                    ' DWORD
   dbgfile      AS ASCIIZ * %MAX_PATH + 1   ' char
   filller2_(1) AS BYTE                     ' // To keep alignment
   pdbfile      AS ASCIIZ * %MAX_PATH + 1   ' char
   guid         AS GUID                     ' GUID
   sig          AS DWORD                    ' DWORD
   age          AS DWORD                    ' DWORD
END TYPE

' // Size = 1608 bytes
TYPE SYMSRV_INDEX_INFOW
   sizeofstruct AS DWORD                      ' DWORD
   file         AS WSTRINGZ * %MAX_PATH + 1   ' WCHAR
   filller1_(1) AS BYTE                       ' // To keep alignment
   stripped     AS LONG                       ' BOOL
   timestamp    AS DWORD                      ' DWORD
   size         AS DWORD                      ' DWORD
   dbgfile      AS WSTRINGZ * %MAX_PATH + 1   ' WCHAR
   pdbfile      AS WSTRINGZ * %MAX_PATH + 1   ' WCHAR
   guid         AS GUID                       ' GUID
   sig          AS DWORD                      ' DWORD
   age          AS DWORD                      ' DWORD
END TYPE

DECLARE FUNCTION SymSrvGetFileIndexInfo IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexInfo" ( _
   BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYREF Info AS SYMSRV_INDEX_INFO _                    ' __out PSYMSRV_INDEX_INFO Info
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvGetFileIndexInfoW IMPORT "ImageHlp.dll" ALIAS "SymSrvGetFileIndexInfoW" ( _
   BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 , BYREF Info AS SYMSRV_INDEX_INFOW _                   ' __out PSYMSRV_INDEX_INFOW Info
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymSrvStoreSupplement IMPORT "ImageHlp.dll" ALIAS "SymSrvStoreSupplement" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SrvPath AS ASCIIZ _                            ' __in_opt PCSTR SrvPath
 , BYREF Node AS ASCIIZ _                               ' __in PCSTR Node
 , BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' PCSTR

DECLARE FUNCTION SymSrvStoreSupplementW IMPORT "ImageHlp.dll" ALIAS "SymSrvStoreSupplementW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SrvPath AS WSTRINGZ _                          ' __in_opt PCWSTR SrvPath
 , BYREF Node AS WSTRINGZ _                             ' __in PCWSTR Node
 , BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' PCWSTR

DECLARE FUNCTION SymSrvStoreFile IMPORT "ImageHlp.dll" ALIAS "SymSrvStoreFile" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SrvPath AS ASCIIZ _                            ' __in_opt PCSTR SrvPath
 , BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' PCSTR

DECLARE FUNCTION SymSrvStoreFileW IMPORT "ImageHlp.dll" ALIAS "SymSrvStoreFileW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL SrvPath AS DWORD _                             ' __in_opt PCWSTR SrvPath
 , BYVAL File AS DWORD _                                ' __in PCWSTR File
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' PCWSTR

'// used by SymGetSymbolFile's "Type" parameter

' enum
%sfImage = 0???
%sfDbg   = 1???
%sfPdb   = 2???
%sfMpd   = 3???
%sfMax   = 4???

DECLARE FUNCTION SymGetSymbolFile IMPORT "ImageHlp.dll" ALIAS "SymGetSymbolFile" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SymPath AS ASCIIZ _                            ' __in_opt PCSTR SymPath
 , BYREF ImageFile AS ASCIIZ _                          ' __in PCSTR ImageFile
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYREF SymbolFile AS ASCIIZ _                         ' __out_ecount(cSymbolFile) PSTR SymbolFile
 , BYVAL cSymbolFile AS DWORD _                         ' __in size_t cSymbolFile
 , BYREF DbgFile AS ASCIIZ _                            ' __out_ecount(cDbgFile) PSTR DbgFile
 , BYVAL cDbgFile AS DWORD _                            ' __in size_t cDbgFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymGetSymbolFileW IMPORT "ImageHlp.dll" ALIAS "SymGetSymbolFileW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL SymPath AS DWORD _                             ' __in_opt PCWSTR SymPath
 , BYVAL ImageFile AS DWORD _                           ' __in PCWSTR ImageFile
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL SymbolFile AS DWORD _                          ' __out_ecount(cSymbolFile) PSTR SymbolFile
 , BYVAL cSymbolFile AS DWORD _                         ' __in size_t cSymbolFile
 , BYVAL DbgFile AS DWORD _                             ' __out_ecount(cDbgFile) PSTR DbgFile
 , BYVAL cDbgFile AS DWORD _                            ' __in size_t cDbgFile
 ) AS LONG                                              ' BOOL

'//
'// Full user-mode dump creation.
'//

'typedef BOOL (WINAPI *PDBGHELP_CREATE_USER_DUMP_CALLBACK)(
'    __in DWORD DataType,
'    __in PVOID* Data,
'    __out LPDWORD DataLength,
'    __in_opt PVOID UserData
'    );

'FUNCTION DBGHELP_CREATE_USER_DUMP_CALLBACK ( _
'   BYVAL DataType AS DWORD _                            ' __in DWORD DataType
' , BYVAL pData AS DWORD _                               ' __in PVOID* Data
' , BYREF DataLength AS DWORD _                          ' __out LPDWORD DataLength
' , OPTIONAL BYVAL UserData AS DWORD _                   ' __in_opt PVOID UserData
' ) AS LONG                                              ' BOOL

' Does not exist in ImageHlp.dll; it exist in DbhHelp.dll.
'DECLARE FUNCTION DbgHelpCreateUserDump IMPORT "ImageHlp.dll" ALIAS "DbgHelpCreateUserDump" ( _
'   BYREF FileName AS ASCIIZ _                           ' __in_opt LPCSTR FileName
' , BYVAL Callback AS DWORD _                            ' __in PDBGHELP_CREATE_USER_DUMP_CALLBACK Callback
' , OPTIONAL BYVAL UserData AS DWORD _                   ' __in_opt PVOID UserData
' ) AS LONG                                              ' BOOL

' Does not exist in ImageHlp.dll; it exist in DbhHelp.dll.
'DECLARE FUNCTION DbgHelpCreateUserDumpW IMPORT "ImageHlp.dll" ALIAS "DbgHelpCreateUserDumpW" ( _
'   BYVAL FileName AS WSTRINGZ _                         ' __in_opt LPCWSTR FileName
' , BYVAL Callback AS DWORD _                            ' __in PDBGHELP_CREATE_USER_DUMP_CALLBACK Callback
' , OPTIONAL BYVAL DWORD _                               ' __in_opt PVOID UserData
' ) AS LONG                                              ' BOOL

'// -----------------------------------------------------------------
'// The following 4 legacy APIs are fully supported, but newer
'// ones are recommended.  SymFromName and SymFromAddr provide
'// much more detailed info on the returned symbol.

DECLARE FUNCTION SymGetSymFromAddr64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymFromAddr64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS QUAD _                               ' __in DWORD64 qwAddr
 , BYREF pdwDisplacement AS QUAD _                      ' __out_opt PDWORD64 pdwDisplacement
 , BYREF Symbol AS IMAGEHLP_SYMBOL64 _                  ' __inout PIMAGEHLP_SYMBOL64  Symbol
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetSymFromAddr SymGetSymFromAddr64
'#else
DECLARE FUNCTION SymGetSymFromAddr IMPORT "ImageHlp.dll" ALIAS "SymGetSymFromAddr" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL qwAddr AS DWORD _                              ' __in DWORD qwAddr
 , BYREF pdwDisplacement AS DWORD _                     ' __out_opt PDWORD pdwDisplacement
 , BYREF Symbol AS IMAGEHLP_SYMBOL _                    ' __inout PIMAGEHLP_SYMBOL  Symbol
 ) AS LONG                                              ' BOOL
'#endif

'// While following two APIs will provide a symbol from a name,
'// SymEnumSymbols can provide the same matching information
'// for ALL symbols with a matching name, even regular
'// expressions.  That way you can search across modules
'// and differentiate between identically named symbols.

DECLARE FUNCTION SymGetSymFromName64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymFromName64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYREF Symbol AS IMAGEHLP_SYMBOL64 _                  ' __inout PIMAGEHLP_SYMBOL64 Symbol
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetSymFromName SymGetSymFromName64
'#else
DECLARE FUNCTION SymGetSymFromName IMPORT "ImageHlp.dll" ALIAS "SymGetSymFromName" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Name AS ASCIIZ _                               ' __in PCSTR Name
 , BYREF Symbol AS IMAGEHLP_SYMBOL _                    ' __inout PIMAGEHLP_SYMBOL Symbol
 ) AS LONG                                              ' BOOL
'#endif


'// Symbol server exports

'typedef BOOL (WINAPI *PSYMBOLSERVERPROC)(PCSTR, PCSTR, PVOID, DWORD, DWORD, PSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERPROCA)(PCSTR, PCSTR, PVOID, DWORD, DWORD, PSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERPROCW)(PCWSTR, PCWSTR, PVOID, DWORD, DWORD, PWSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERBYINDEXPROC)(PCSTR, PCSTR, PCSTR, PSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERBYINDEXPROCA)(PCSTR, PCSTR, PCSTR, PSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERBYINDEXPROCW)(PCWSTR, PCWSTR, PCWSTR, PWSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVEROPENPROC)(VOID);
'typedef BOOL (WINAPI *PSYMBOLSERVERCLOSEPROC)(VOID);
'typedef BOOL (WINAPI *PSYMBOLSERVERSETOPTIONSPROC)(UINT_PTR, ULONG64);
'typedef BOOL (WINAPI *PSYMBOLSERVERSETOPTIONSWPROC)(UINT_PTR, ULONG64);
'typedef BOOL (CALLBACK WINAPI *PSYMBOLSERVERCALLBACKPROC)(UINT_PTR action, ULONG64 data, ULONG64 context);
'typedef UINT_PTR (WINAPI *PSYMBOLSERVERGETOPTIONSPROC)();
'typedef BOOL (WINAPI *PSYMBOLSERVERPINGPROC)(PCSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERPINGPROCA)(PCSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERPINGPROCW)(PCWSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERGETVERSION)(LPAPI_VERSION);
'typedef BOOL (WINAPI *PSYMBOLSERVERDELTANAME)(PCSTR, PVOID, DWORD, DWORD, PVOID, DWORD, DWORD, PSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERDELTANAMEW)(PCWSTR, PVOID, DWORD, DWORD, PVOID, DWORD, DWORD, PWSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERGETSUPPLEMENT)(PCSTR, PCSTR, PCSTR, PSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERGETSUPPLEMENTW)(PCWSTR, PCWSTR, PCWSTR, PWSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERSTORESUPPLEMENT)(PCSTR, PCSTR, PCSTR, PSTR, size_t, DWORD);
'typedef BOOL (WINAPI *PSYMBOLSERVERSTORESUPPLEMENTW)(PCWSTR, PCWSTR, PCWSTR, PWSTR, size_t, DWORD);
'typedef BOOL (WINAPI *PSYMBOLSERVERGETINDEXSTRING)(PVOID, DWORD, DWORD, PSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERGETINDEXSTRINGW)(PVOID, DWORD, DWORD, PWSTR, size_t);
'typedef BOOL (WINAPI *PSYMBOLSERVERSTOREFILE)(PCSTR, PCSTR, PVOID, DWORD, DWORD, PSTR, size_t, DWORD);
'typedef BOOL (WINAPI *PSYMBOLSERVERSTOREFILEW)(PCWSTR, PCWSTR, PVOID, DWORD, DWORD, PWSTR, size_t, DWORD);
'typedef BOOL (WINAPI *PSYMBOLSERVERISSTORE)(PCSTR);
'typedef BOOL (WINAPI *PSYMBOLSERVERISSTOREW)(PCWSTR);
'typedef DWORD (WINAPI *PSYMBOLSERVERVERSION)();
'typedef BOOL (CALLBACK WINAPI *PSYMBOLSERVERMESSAGEPROC)(UINT_PTR action, ULONG64 data, ULONG64 context);

%SYMSRV_VERSION              = 2

%SSRVOPT_CALLBACK            = &H000001???
%SSRVOPT_DWORD               = &H000002???
%SSRVOPT_DWORDPTR            = &H000004???
%SSRVOPT_GUIDPTR             = &H000008???
%SSRVOPT_OLDGUIDPTR          = &H000010???
%SSRVOPT_UNATTENDED          = &H000020???
%SSRVOPT_NOCOPY              = &H000040???
%SSRVOPT_GETPATH             = &H000040???
%SSRVOPT_PARENTWIN           = &H000080???
%SSRVOPT_PARAMTYPE           = &H000100???
%SSRVOPT_SECURE              = &H000200???
%SSRVOPT_TRACE               = &H000400???
%SSRVOPT_SETCONTEXT          = &H000800???
%SSRVOPT_PROXY               = &H001000???
%SSRVOPT_DOWNSTREAM_STORE    = &H002000???
%SSRVOPT_OVERWRITE           = &H004000???
%SSRVOPT_RESETTOU            = &H008000???
%SSRVOPT_CALLBACKW           = &H010000???
%SSRVOPT_FLAT_DEFAULT_STORE  = &H020000???
%SSRVOPT_PROXYW              = &H040000???
%SSRVOPT_MESSAGE             = &H080000???
%SSRVOPT_SERVICE             = &H100000???   ' // deprecated
%SSRVOPT_FAVOR_COMPRESSED    = &H200000???
%SSRVOPT_STRING              = &H00400000???
%SSRVOPT_WINHTTP             = &H00800000???
%SSRVOPT_WININET             = &H01000000???

%SSRVOPT_MAX                 = &H01000000???

%SSRVOPT_RESET               = &HFFFFFFFF???   ' ((ULONG_PTR)-1)


%NUM_SSRVOPTS                = 30

%SSRVACTION_TRACE            = 1
%SSRVACTION_QUERYCANCEL      = 2
%SSRVACTION_EVENT            = 3
%SSRVACTION_EVENTW           = 4
%SSRVACTION_SIZE             = 5

%SYMSTOREOPT_COMPRESS        = &H01???
%SYMSTOREOPT_OVERWRITE       = &H02???
%SYMSTOREOPT_RETURNINDEX     = &H04???
%SYMSTOREOPT_POINTER         = &H08???
%SYMSTOREOPT_ALT_INDEX       = &H10???
%SYMSTOREOPT_UNICODE         = &H20???
%SYMSTOREOPT_PASS_IF_EXISTS  = &H40???

'#ifdef DBGHELP_TRANSLATE_TCHAR
' #define SymInitialize                     SymInitializeW
' #define SymAddSymbol                      SymAddSymbolW
' #define SymDeleteSymbol                   SymDeleteSymbolW
' #define SearchTreeForFile                 SearchTreeForFileW
' #define UnDecorateSymbolName              UnDecorateSymbolNameW
' #define SymGetLineFromName64              SymGetLineFromNameW64
' #define SymGetLineFromAddr64              SymGetLineFromAddrW64
' #define SymGetLineNext64                  SymGetLineNextW64
' #define SymGetLinePrev64                  SymGetLinePrevW64
' #define SymFromName                       SymFromNameW
' #define SymFindExecutableImage            SymFindExecutableImageW
' #define FindExecutableImageEx             FindExecutableImageExW
' #define SymSearch                         SymSearchW
' #define SymEnumLines                      SymEnumLinesW
' #define SymEnumSourceLines                SymEnumSourceLinesW
' #define SymGetTypeFromName                SymGetTypeFromNameW
' #define SymEnumSymbolsForAddr             SymEnumSymbolsForAddrW
' #define SymFromAddr                       SymFromAddrW
' #define SymMatchString                    SymMatchStringW
' #define SymEnumSourceFiles                SymEnumSourceFilesW
' #define SymEnumSymbols                    SymEnumSymbolsW
' #define SymLoadModuleEx                   SymLoadModuleExW
' #define SymSetSearchPath                  SymSetSearchPathW
' #define SymGetSearchPath                  SymGetSearchPathW
' #define EnumDirTree                       EnumDirTreeW
' #define SymFromToken                      SymFromTokenW
' #define SymFromIndex                      SymFromIndexW
' #define SymGetScope                       SymGetScopeW
' #define SymNext                           SymNextW
' #define SymPrev                           SymPrevW
' #define SymEnumTypes                      SymEnumTypesW
' #define SymRegisterCallback64             SymRegisterCallbackW64
' #define SymFindDebugInfoFile              SymFindDebugInfoFileW
' #define FindDebugInfoFileEx               FindDebugInfoFileExW
' #define SymFindFileInPath                 SymFindFileInPathW
' #define SymEnumerateModules64             SymEnumerateModulesW64
' #define SymSetHomeDirectory               SymSetHomeDirectoryW
' #define SymGetHomeDirectory               SymGetHomeDirectoryW
' #define SymGetSourceFile                  SymGetSourceFileW
' #define SymGetSourceFileToken             SymGetSourceFileTokenW
' #define SymGetSourceFileFromToken         SymGetSourceFileFromTokenW
' #define SymGetSourceVarFromToken          SymGetSourceVarFromTokenW
' #define SymGetSourceFileToken             SymGetSourceFileTokenW
' #define SymGetFileLineOffsets64           SymGetFileLineOffsetsW64
' #define SymFindFileInPath                 SymFindFileInPathW
' #define SymMatchFileName                  SymMatchFileNameW
' #define SymGetSourceFileFromToken         SymGetSourceFileFromTokenW
' #define SymGetSourceVarFromToken          SymGetSourceVarFromTokenW
' #define SymGetModuleInfo64                SymGetModuleInfoW64
' #define SymSrvIsStore                     SymSrvIsStoreW
' #define SymSrvDeltaName                   SymSrvDeltaNameW
' #define SymSrvGetSupplement               SymSrvGetSupplementW
' #define SymSrvStoreSupplement             SymSrvStoreSupplementW
' #define SymSrvGetFileIndexes              SymSrvGetFileIndexes
' #define SymSrvGetFileIndexString          SymSrvGetFileIndexStringW
' #define SymSrvStoreFile                   SymSrvStoreFileW
' #define SymGetSymbolFile                  SymGetSymbolFileW
' #define EnumerateLoadedModules64          EnumerateLoadedModulesW64
' #define SymSrvGetFileIndexInfo            SymSrvGetFileIndexInfoW

' #define IMAGEHLP_LINE64                   IMAGEHLP_LINEW64
' #define PIMAGEHLP_LINE64                  PIMAGEHLP_LINEW64
' #define SYMBOL_INFO                       SYMBOL_INFOW
' #define PSYMBOL_INFO                      PSYMBOL_INFOW
' #define SYMBOL_INFO_PACKAGE               SYMBOL_INFO_PACKAGEW
' #define PSYMBOL_INFO_PACKAGE              PSYMBOL_INFO_PACKAGEW
' #define FIND_EXE_FILE_CALLBACK            FIND_EXE_FILE_CALLBACKW
' #define PFIND_EXE_FILE_CALLBACK           PFIND_EXE_FILE_CALLBACKW
' #define SYM_ENUMERATESYMBOLS_CALLBACK     SYM_ENUMERATESYMBOLS_CALLBACKW
' #define PSYM_ENUMERATESYMBOLS_CALLBACK    PSYM_ENUMERATESYMBOLS_CALLBACKW
' #define SRCCODEINFO                       SRCCODEINFOW
' #define PSRCCODEINFO                      PSRCCODEINFOW
' #define SOURCEFILE                        SOURCEFILEW
' #define PSOURCEFILE                       PSOURCEFILEW
' #define SYM_ENUMSOURECFILES_CALLBACK      SYM_ENUMSOURCEFILES_CALLBACKW
' #define PSYM_ENUMSOURCEFILES_CALLBACK     PSYM_ENUMSOURECFILES_CALLBACKW
' #define IMAGEHLP_CBA_EVENT                IMAGEHLP_CBA_EVENTW
' #define PIMAGEHLP_CBA_EVENT               PIMAGEHLP_CBA_EVENTW
' #define PENUMDIRTREE_CALLBACK             PENUMDIRTREE_CALLBACKW
' #define IMAGEHLP_DEFERRED_SYMBOL_LOAD64   IMAGEHLP_DEFERRED_SYMBOL_LOADW64
' #define PIMAGEHLP_DEFERRED_SYMBOL_LOAD64  PIMAGEHLP_DEFERRED_SYMBOL_LOADW64
' #define PFIND_DEBUG_FILE_CALLBACK         PFIND_DEBUG_FILE_CALLBACKW
' #define PFINDFILEINPATHCALLBACK           PFINDFILEINPATHCALLBACKW
' #define IMAGEHLP_MODULE64                 IMAGEHLP_MODULEW64
' #define PIMAGEHLP_MODULE64                PIMAGEHLP_MODULEW64
' #define SYMSRV_INDEX_INFO                 SYMSRV_INDEX_INFOw
' #define PSYMSRV_INDEX_INFO                PSYMSRV_INDEX_INFOW

' #define PSYMBOLSERVERPROC                 PSYMBOLSERVERPROCW
' #define PSYMBOLSERVERPINGPROC             PSYMBOLSERVERPINGPROCW
'#endif
'++++++++++
'// -----------------------------------------------------------------
'// The following APIs exist only for backwards compatibility
'// with a pre-release version documented in an MSDN release.

'// You should use SymFindFileInPath if you want to maintain
'// future compatibility.

DECLARE FUNCTION FindFileInPath IMPORT "ImageHlp.dll" ALIAS "FindFileInPath" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SearchPath AS ASCIIZ _                         ' __in PCSTR SearchPath
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYVAL id AS DWORD _                                  ' __in PVOID id
 , BYVAL two AS DWORD _                                 ' __in DWORD two
 , BYVAL three AS DWORD _                               ' __in DWORD three
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF FilePath AS ASCIIZ _                           ' __out_ecount(MAX_PATH + 1) PSTR FilePath
 ) AS LONG                                              ' BOOL

'// You should use SymFindFileInPath if you want to maintain
'// future compatibility.

DECLARE FUNCTION FindFileInSearchPath IMPORT "ImageHlp.dll" ALIAS "FindFileInSearchPath" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF SearchPath AS ASCIIZ _                         ' __in PCSTR SearchPath
 , BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYVAL id AS DWORD _                                  ' __in PVOID id
 , BYVAL two AS DWORD _                                 ' __in DWORD two
 , BYVAL three AS DWORD _                               ' __in DWORD three
 , BYREF FilePath AS ASCIIZ _                           ' __out_ecount(MAX_PATH + 1) PSTR FilePath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumSym IMPORT "ImageHlp.dll" ALIAS "SymEnumSym" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumerateSymbols64 IMPORT "ImageHlp.dll" ALIAS "SymEnumerateSymbols64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK64 EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumerateSymbolsW64 IMPORT "ImageHlp.dll" ALIAS "SymEnumerateSymbolsW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK64W EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL


'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymEnumerateSymbols SymEnumerateSymbols64
'#define SymEnumerateSymbolsW SymEnumerateSymbolsW64
'#else
DECLARE FUNCTION SymEnumerateSymbols IMPORT "ImageHlp.dll" ALIAS "SymEnumerateSymbols" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SymEnumerateSymbolsW IMPORT "ImageHlp.dll" ALIAS "SymEnumerateSymbolsW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL BaseOfDll AS QUAD _                            ' __in ULONG64 BaseOfDll
 , BYVAL EnumSymbolsCallback AS DWORD _                 ' __in PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback
 , OPTIONAL BYVAL UserContext AS DWORD _                ' __in_opt PVOID UserContext
 ) AS LONG                                              ' BOOL
'#endif

'// use SymLoadModuleEx

DECLARE FUNCTION SymLoadModule64 IMPORT "ImageHlp.dll" ALIAS "SymLoadModule64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hFile AS DWORD _                               ' __in_opt HANDLE hFile
 , BYREF ImageName AS ASCIIZ _                          ' __in_opt PCSTR ImageName
 , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR ModuleName
 , BYVAL BaseOfDll AS QUAD _                            ' __in DWORD64 BaseOfDll
 , BYVAL SizeOfDll AS DWORD _                           ' __in DWORD SizeOfDll
 ) AS QUAD                                              ' DWORD64

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymLoadModule SymLoadModule64
'#else
DECLARE FUNCTION SymLoadModule IMPORT "ImageHlp.dll" ALIAS "SymLoadModule" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hFile AS DWORD _                               ' __in_opt HANDLE hFile
 , BYREF ImageName AS ASCIIZ _                          ' __in_opt PCSTR ImageName
 , BYREF ModuleName AS ASCIIZ _                         ' __in_opt PCSTR ModuleName
 , BYVAL BaseOfDll AS DWORD _                           ' __in DWORD BaseOfDll
 , BYVAL SizeOfDll AS DWORD _                           ' __in DWORD SizeOfDll
 ) AS QUAD                                              ' DWORD64
'#endif

DECLARE FUNCTION SymGetSymNext64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymNext64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOL64 _                  ' __inout PIMAGEHLP_SYMBOL64 Symbol
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetSymNextW64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymNextW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOLW64 _                 ' __inout PIMAGEHLP_SYMBOLW64 Symbol
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetSymNext SymGetSymNext64
'#define SymGetSymNextW SymGetSymNextW64
'#else
DECLARE FUNCTION SymGetSymNext IMPORT "ImageHlp.dll" ALIAS "SymGetSymNext" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOL _                    ' __inout PIMAGEHLP_SYMBOL Symbol
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetSymNextW IMPORT "ImageHlp.dll" ALIAS "SymGetSymNextW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOLW _                   ' __inout PIMAGEHLP_SYMBOLW Symbol
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION SymGetSymPrev64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymPrev64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOL64 _                  ' __inout PIMAGEHLP_SYMBOL64 Symbol
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetSymPrevW64 IMPORT "ImageHlp.dll" ALIAS "SymGetSymPrevW64" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOLW64 _                 ' __inout PIMAGEHLP_SYMBOLW64 Symbol
 ) AS LONG                                              ' BOOL

'#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
'#define SymGetSymPrev SymGetSymPrev64
'#define SymGetSymPrevW SymGetSymPrevW64
'#else
DECLARE FUNCTION SymGetSymPrev IMPORT "ImageHlp.dll" ALIAS "SymGetSymPrev" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOL _                    ' __inout PIMAGEHLP_SYMBOL Symbol
 ) AS LONG                                              ' BOOL

' Does not exist.
DECLARE FUNCTION SymGetSymPrevW IMPORT "ImageHlp.dll" ALIAS "SymGetSymPrevW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF Symbol AS IMAGEHLP_SYMBOLW _                   ' __inout PIMAGEHLP_SYMBOLW Symbol
 ) AS LONG                                              ' BOOL
'#endif


'// These values should not be used.
'// They have been replaced by SYMFLAG_ values.

%SYMF_OMAP_GENERATED   = &H00000001???
%SYMF_OMAP_MODIFIED    = &H00000002???
%SYMF_REGISTER         = &H00000008???
%SYMF_REGREL           = &H00000010???
%SYMF_FRAMEREL         = &H00000020???
%SYMF_PARAMETER        = &H00000040???
%SYMF_LOCAL            = &H00000080???
%SYMF_CONSTANT         = &H00000100???
%SYMF_EXPORT           = &H00000200???
%SYMF_FORWARDER        = &H00000400???
%SYMF_FUNCTION         = &H00000800???
%SYMF_VIRTUAL          = &H00001000???
%SYMF_THUNK            = &H00002000???
%SYMF_TLSREL           = &H00004000???

'// These values should also not be used.
'// They have been replaced by SYMFLAG_ values.

%IMAGEHLP_SYMBOL_INFO_VALUEPRESENT          = 1
%IMAGEHLP_SYMBOL_INFO_REGISTER              = %SYMF_REGISTER        ' // 0x0008
%IMAGEHLP_SYMBOL_INFO_REGRELATIVE           = %SYMF_REGREL          ' // 0x0010
%IMAGEHLP_SYMBOL_INFO_FRAMERELATIVE         = %SYMF_FRAMEREL        ' // 0x0020
%IMAGEHLP_SYMBOL_INFO_PARAMETER             = %SYMF_PARAMETER       ' // 0x0040
%IMAGEHLP_SYMBOL_INFO_LOCAL                 = %SYMF_LOCAL           ' // 0x0080
%IMAGEHLP_SYMBOL_INFO_CONSTANT              = %SYMF_CONSTANT        ' // 0x0100
%IMAGEHLP_SYMBOL_FUNCTION                   = %SYMF_FUNCTION        ' // 0x0800
%IMAGEHLP_SYMBOL_VIRTUAL                    = %SYMF_VIRTUAL         ' // 0x1000
%IMAGEHLP_SYMBOL_THUNK                      = %SYMF_THUNK           ' // 0x2000
%IMAGEHLP_SYMBOL_INFO_TLSRELATIVE           = %SYMF_TLSREL          ' // 0x4000


'#include <pshpack4.h>

'#if defined(_MSC_VER)
'#if _MSC_VER >= 800
'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable:4200)    /* Zero length array */
'#pragma warning(disable:4201)    /* Nameless struct/union */
'#endif
'#endif

'#define MINIDUMP_SIGNATURE ('PMDM')
'#define MINIDUMP_VERSION   (42899)

%MINIDUMP_SIGNATURE = 1296321872   ' 'PMDM'
%MINIDUMP_VERSION   = 42899

'typedef DWORD RVA;
'typedef ULONG64 RVA64;

' // Size = 8 bytes
TYPE MINIDUMP_LOCATION_DESCRIPTOR DWORD
   DataSize AS DWORD   ' ULONG32
   Rva      AS DWORD   ' RVA
END TYPE

' // Size = 16 bytes
TYPE MINIDUMP_LOCATION_DESCRIPTOR64 QWORD
   DataSize AS QUAD    ' ULONG64
   Rva      AS DWORD   ' RVA
END TYPE

' // Size = 16 bytes
TYPE MINIDUMP_MEMORY_DESCRIPTOR
   StartOfMemoryRange AS QUAD   ' ULONG64
   Memory             AS MINIDUMP_LOCATION_DESCRIPTOR
END TYPE

'// DESCRIPTOR64 is used for full-memory minidumps where
'// all of the raw memory is laid out sequentially at the
'// end of the dump.  There is no need for individual RVAs
'// as the RVA is the base RVA plus the sum of the preceeding
'// data blocks.

' // Size = 16 bytes
TYPE MINIDUMP_MEMORY_DESCRIPTOR64 QWORD
   StartOfMemoryRange AS QUAD   ' ULONG64
   DataSize           AS QUAD   ' ULONG64
END TYPE

' // Size = 4 bytes
UNION MINIDUMP_HEADER_UNION DWORD
   Reserved      AS DWORD   ' ULONG32
   TimeDateStamp AS DWORD   ' ULONG32
END UNION

' // Size = 32 bytes
TYPE MINIDUMP_HEADER DWORD
   Signature          AS   DWORD   ' ULONG32
   Version            AS   DWORD   ' ULONG32
   NumberOfStreams    AS   DWORD   ' ULONG32
   StreamDirectoryRva AS   DWORD   ' RVA
   CheckSum           AS   DWORD   ' ULONG32
   MINIDUMP_HEADER_UNION
   Flags              AS   QUAD    ' ULONG64
END TYPE

'//
'// The MINIDUMP_HEADER field StreamDirectoryRva points to
'// an array of MINIDUMP_DIRECTORY structures.
'//

' // Size = 12 bytes
TYPE MINIDUMP_DIRECTORY DWORD
   StreamType AS DWORD   ' ULONG32
   Location   AS MINIDUMP_LOCATION_DESCRIPTOR
END TYPE

' // Size = 4 bytes
TYPE MINIDUMP_STRING DWORD
   Length   AS DWORD   ' ULONG32 // Length in bytes of the string
   ' Buffer() AS WORD    ' WCHAR // Variable size buffer
END TYPE

'//
'// The MINIDUMP_DIRECTORY field StreamType may be one of the following types.
'// Types will be added in the future, so if a program reading the minidump
'// header encounters a stream type it does not understand it should ignore
'// the data altogether. Any tag above LastReservedStream will not be used by
'// the system and is reserved for program-specific information.
'//

' enum MINIDUMP_STREAM_TYPE
%UnusedStream                = 0???
%ReservedStream0             = 1???
%ReservedStream1             = 2???
%ThreadListStream            = 3???
%ModuleListStream            = 4???
%MemoryListStream            = 5???
%ExceptionStream             = 6???
%SystemInfoStream            = 7???
%ThreadExListStream          = 8???
%Memory64ListStream          = 9???
%CommentStreamA              = 10???
%CommentStreamW              = 11???
%HandleDataStream            = 12???
%FunctionTableStream         = 13???
%UnloadedModuleListStream    = 14???
%MiscInfoStream              = 15???
%MemoryInfoListStream        = 16???
%ThreadInfoListStream        = 17???
%HandleOperationListStream   = 18???
%TokenStream                 = 19???

%ceStreamNull                = &H8000???
%ceStreamSystemInfo          = &H8001???
%ceStreamException           = &H8002???
%ceStreamModuleList          = &H8003???
%ceStreamProcessList         = &H8004???
%ceStreamThreadList          = &H8005???
%ceStreamThreadContextList   = &H8006???
%ceStreamThreadCallStackList = &H8007???
%ceStreamMemoryVirtualList   = &H8008???
%ceStreamMemoryPhysicalList  = &H8009???
%ceStreamBucketParameters    = &H800A???
%ceStreamProcessModuleMap    = &H800B???
%ceStreamDiagnosisList       = &H800C???

%LastReservedStream          = &Hffff???


'//
'// The minidump system information contains processor and
'// Operating System specific information.
'//

'//
'// CPU information is obtained from one of two places.
'//
'//  1) On x86 computers, CPU_INFORMATION is obtained from the CPUID
'//     instruction. You must use the X86 portion of the union for X86
'//     computers.
'//
'//  2) On non-x86 architectures, CPU_INFORMATION is obtained by calling
'//     IsProcessorFeatureSupported().
'//

'typedef union _CPU_INFORMATION {

'    //
'    // X86 platforms use CPUID function to obtain processor information.
'    //

'    struct {

'        //
'        // CPUID Subfunction 0, register EAX (VendorId [0]),
'        // EBX (VendorId [1]) and ECX (VendorId [2]).
'        //

'        ULONG32 VendorId [ 3 ];

'        //
'        // CPUID Subfunction 1, register EAX
'        //

'        ULONG32 VersionInformation;

'        //
'        // CPUID Subfunction 1, register EDX
'        //

'        ULONG32 FeatureInformation;


'        //
'        // CPUID, Subfunction 80000001, register EBX. This will only
'        // be obtained if the vendor id is "AuthenticAMD".
'        //

'        ULONG32 AMDExtendedCpuFeatures;

'    } X86CpuInfo;

'    //
'    // Non-x86 platforms use processor feature flags.
'    //

'    struct {

'        ULONG64 ProcessorFeatures [ 2 ];

'    } OtherCpuInfo;

'} CPU_INFORMATION, *PCPU_INFORMATION;

' // Size = 24 bytes
TYPE CPU_INFORMATION_X86CpuInfo DWORD
   VendorId(2)            AS DWORD   ' ULONG32
   VersionInformation     AS DWORD   ' ULONG32
   FeatureInformation     AS DWORD   ' ULONG32
   AMDExtendedCpuFeatures AS DWORD   ' ULONG32
END TYPE

' // Size = 16 bytes
TYPE CPU_INFORMATION_OtherCpuInfo QWORD
   ProcessorFeatures(1) AS QUAD   ' ULONG64
END TYPE

' // Size = 24 bytes
UNION CPU_INFORMATION
   CPU_INFORMATION_X86CpuInfo
   CPU_INFORMATION_OtherCpuInfo
END UNION

'typedef struct _MINIDUMP_SYSTEM_INFO {

'    //
'    // ProcessorArchitecture, ProcessorLevel and ProcessorRevision are all
'    // taken from the SYSTEM_INFO structure obtained by GetSystemInfo( ).
'    //

'    USHORT ProcessorArchitecture;
'    USHORT ProcessorLevel;
'    USHORT ProcessorRevision;

'    union {
'        USHORT Reserved0;
'        struct {
'            UCHAR NumberOfProcessors;
'            UCHAR ProductType;
'        };
'    };

'    //
'    // MajorVersion, MinorVersion, BuildNumber, PlatformId and
'    // CSDVersion are all taken from the OSVERSIONINFO structure
'    // returned by GetVersionEx( ).
'    //

'    ULONG32 MajorVersion;
'    ULONG32 MinorVersion;
'    ULONG32 BuildNumber;
'    ULONG32 PlatformId;

'    //
'    // RVA to a CSDVersion string in the string table.
'    //

'    RVA CSDVersionRva;

'    union {
'        ULONG32 Reserved1;
'        struct {
'            USHORT SuiteMask;
'            USHORT Reserved2;
'        };
'    };

'    CPU_INFORMATION Cpu;

'} MINIDUMP_SYSTEM_INFO, *PMINIDUMP_SYSTEM_INFO;

' // Size = 2 bytes
TYPE MINIDUMP_SYSTEM_INFO_UNION_1_STRUCT BYTE
   NumberOfProcessors AS BYTE   ' UCHAR
   ProductType        AS BYTE   ' UCHAR
END TYPE

' // Size = 2 bytes
UNION MINIDUMP_SYSTEM_INFO_UNION_1 WORD FILL
   Reserved0 AS WORD   ' USHORT
   MINIDUMP_SYSTEM_INFO_UNION_1_STRUCT
END UNION

' // Size = 4 bytes
TYPE MINIDUMP_SYSTEM_INFO_UNION_2_STRUCT WORD
   SuiteMask AS WORD   ' USHORT
   Reserved2 AS WORD   ' USHORT
END TYPE

' // Size = 4 bytes
UNION MINIDUMP_SYSTEM_INFO_UNION_2 WORD
   Reserved1 AS DWORD   ' ULONG32
   MINIDUMP_SYSTEM_INFO_UNION_2_STRUCT
END UNION

' // Size = 56 bytes
TYPE MINIDUMP_SYSTEM_INFO WORD
   ProcessorArchitecture AS WORD    ' USHORT
   ProcessorLevel        AS WORD    ' USHORT
   ProcessorRevision     AS WORD    ' USHORT
   MINIDUMP_SYSTEM_INFO_UNION_1
   MajorVersion          AS DWORD   ' ULONG32
   MinorVersion          AS DWORD   ' ULONG32
   BuildNumber           AS DWORD   ' ULONG32
   PlatformId            AS DWORD   ' ULONG32
   CSDVersionRva         AS DWORD   ' RVA
   MINIDUMP_SYSTEM_INFO_UNION_2
   Cpu                   AS CPU_INFORMATION
END TYPE

'//
'// The minidump thread contains standard thread
'// information plus an RVA to the memory for this
'// thread and an RVA to the CONTEXT structure for
'// this thread.
'//


'//
'// ThreadId must be 4 bytes on all architectures.
'//

'C_ASSERT (sizeof ( ((PPROCESS_INFORMATION)0)->dwThreadId ) == 4);

' // Size = 48 bytes
TYPE MINIDUMP_THREAD DWORD
   ThreadId      AS DWORD   ' ULONG32
   SuspendCount  AS DWORD   ' ULONG32
   PriorityClass AS DWORD   ' ULONG32
   Priority      AS DWORD   ' ULONG32
   Teb           AS QUAD    ' ULONG64
   Stack         AS MINIDUMP_MEMORY_DESCRIPTOR
   ThreadContext AS MINIDUMP_LOCATION_DESCRIPTOR
END TYPE

'//
'// The thread list is a container of threads.
'//

' // Size = 4 bytes
TYPE MINIDUMP_THREAD_LIST DWORD
   NumberOfThreads AS DWORD   ' ULONG32
   ' Threads() AS MINIDUMP_THREAD
END TYPE

' // Size = 64 bytes
TYPE MINIDUMP_THREAD_EX DWORD
   ThreadId      AS DWORD   ' ULONG32
   SuspendCount  AS DWORD   ' ULONG32
   PriorityClass AS DWORD   ' ULONG32
   Priority      AS DWORD   ' ULONG32
   Teb           AS QUAD    ' ULONG64
   Stack         AS MINIDUMP_MEMORY_DESCRIPTOR
   ThreadContext AS MINIDUMP_LOCATION_DESCRIPTOR
   BackingStore  AS MINIDUMP_MEMORY_DESCRIPTOR
END TYPE

'//
'// The thread list is a container of threads.
'//

' // Size = 4 bytes
TYPE MINIDUMP_THREAD_EX_LIST DWORD
   NumberOfThreads AS DWORD   ' ULONG32
   ' Threads() AS MINIDUMP_THREAD_EX
END TYPE


'//
'// The MINIDUMP_EXCEPTION is the same as EXCEPTION on Win64.
'//

' // Size = 152 bytes
TYPE MINIDUMP_EXCEPTION DWORD
   ExceptionCode     AS DWORD   ' ULONG32
   ExceptionFlags    AS DWORD   ' ULONG32
   ExceptionRecord   AS QUAD    ' ULONG64
   ExceptionAddress  AS QUAD    ' ULONG64
   NumberParameters  AS DWORD   ' ULONG32
   unusedAlignment__ AS DWORD   ' ULONG32
   ExceptionInformation(%EXCEPTION_MAXIMUM_PARAMETERS - 1) AS QUAD   ' ULONG64
END TYPE


'//
'// The exception information stream contains the id of the thread that caused
'// the exception (ThreadId), the exception record for the exception
'// (ExceptionRecord) and an RVA to the thread context where the exception
'// occured.
'//

' // Size = 168 bytes
TYPE MINIDUMP_EXCEPTION_STREAM DWORD
   ThreadId        AS DWORD   ' ULONG32
   alignment__     AS DWORD   ' ULONG32
   ExceptionRecord AS MINIDUMP_EXCEPTION
   ThreadContext   AS MINIDUMP_LOCATION_DESCRIPTOR
END TYPE


'//
'// The MINIDUMP_MODULE contains information about a
'// a specific module. It includes the CheckSum and
'// the TimeDateStamp for the module so the module
'// can be reloaded during the analysis phase.
'//

' // Size = 108 bytes
TYPE MINIDUMP_MODULE DWORD
   BaseOfImage   AS QUAD    ' ULONG64
   SizeOfImage   AS DWORD   ' ULONG32
   CheckSum      AS DWORD   ' ULONG32
   TimeDateStamp AS DWORD   ' ULONG32
   ModuleNameRva AS DWORD   ' RVA
   VersionInfo   AS VS_FIXEDFILEINFO
   CvRecord      AS MINIDUMP_LOCATION_DESCRIPTOR
   MiscRecord    AS MINIDUMP_LOCATION_DESCRIPTOR
   Reserved0     AS QUAD    ' ULONG64 // Reserved for future use.
   Reserved1     AS QUAD    ' ULONG64 // Reserved for future use.
END TYPE


'//
'// The minidump module list is a container for modules.
'//

' // Size = 4 bytes
TYPE MINIDUMP_MODULE_LIST DWORD
   NumberOfModules AS DWORD   ' ULONG32
   ' Modules() AS MINIDUMP_MODULE
END TYPE


'//
'// Memory Ranges
'//

' // Size = 4 bytes
TYPE MINIDUMP_MEMORY_LIST DWORD
   NumberOfMemoryRanges AS DWORD   ' ULONG32
   ' MemoryRanges(0) AS MINIDUMP_MEMORY_DESCRIPTOR
END TYPE

' // Size = 16 bytes
TYPE MINIDUMP_MEMORY64_LIST QWORD
   NumberOfMemoryRanges AS QUAD   ' ULONG64
   BaseRva              AS QUAD   ' RVA64
   ' MemoryRanges() AS MINIDUMP_MEMORY_DESCRIPTOR64
END TYPE


'//
'// Support for user supplied exception information.
'//

' // Size = 12 bytes
TYPE MINIDUMP_EXCEPTION_INFORMATION DWORD
   ThreadId          AS DWORD                   ' DWORD
   ExceptionPointers AS EXCEPTION_POINTERS PTR
   ClientPointers    AS LONG                    ' BOOL
END TYPE

' // Size = 24 bytes
TYPE MINIDUMP_EXCEPTION_INFORMATION64 DWORD
   ThreadId        AS DWORD   ' DWORD
   ExceptionRecord AS QUAD    ' ULONG64
   ContextRecord   AS QUAD    ' ULONG64
   ClientPointers  AS LONG    ' BOOL
END TYPE


'//
'// Support for capturing system handle state at the time of the dump.
'//

'// Per-handle object information varies according to
'// the OS, the OS version, the processor type and
'// so on.  The minidump gives a minidump identifier
'// to each possible data format for identification
'// purposes but does not control nor describe the actual data.

' enum MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE
%MiniHandleObjectInformationNone    = 0???
%MiniThreadInformation1             = 1???
%MiniMutantInformation1             = 2???
%MiniMutantInformation2             = 3???
%MiniProcessInformation1            = 4???
%MiniProcessInformation2            = 5???
%MiniHandleObjectInformationTypeMax = 6???

' // Size = 12 bytes
TYPE MINIDUMP_HANDLE_OBJECT_INFORMATION DWORD
   NextInfoRva AS DWORD   ' RVA
   InfoType    AS DWORD   ' ULONG32
   SizeOfInfo  AS DWORD   ' ULONG32
   ' // Raw information follows.
END TYPE

' // Size = 32 bytes
TYPE MINIDUMP_HANDLE_DESCRIPTOR DWORD
   Handle        AS QUAD    ' ULONG64
   TypeNameRva   AS DWORD   ' RVA
   ObjectNameRva AS DWORD   ' RVA
   Attributes    AS DWORD   ' ULONG32
   GrantedAccess AS DWORD   ' ULONG32
   HandleCount   AS DWORD   ' ULONG32
   PointerCount  AS DWORD   ' ULONG32
END TYPE

' // Size = 40 bytes
TYPE MINIDUMP_HANDLE_DESCRIPTOR_2 DWORD
   Handle        AS QUAD    ' ULONG64
   TypeNameRva   AS DWORD   ' RVA
   ObjectNameRva AS DWORD   ' RVA
   Attributes    AS DWORD   ' ULONG32
   GrantedAccess AS DWORD   ' ULONG32
   HandleCount   AS DWORD   ' ULONG32
   PointerCount  AS DWORD   ' ULONG32
   ObjectInfoRva AS DWORD   ' RVA
   Reserved0     AS DWORD   ' ULONG32
END TYPE

'// The latest MINIDUMP_HANDLE_DESCRIPTOR definition.
'typedef MINIDUMP_HANDLE_DESCRIPTOR_2 MINIDUMP_HANDLE_DESCRIPTOR_N;
'typedef MINIDUMP_HANDLE_DESCRIPTOR_N *PMINIDUMP_HANDLE_DESCRIPTOR_N;

' // Size = 16 bytes
TYPE MINIDUMP_HANDLE_DATA_STREAM DWORD
   SizeOfHeader        AS DWORD   ' ULONG32
   SizeOfDescriptor    AS DWORD   ' ULONG32
   NumberOfDescriptors AS DWORD   ' ULONG32
   Reserved            AS DWORD   ' ULONG32
END TYPE

'// Some operating systems can track the last operations
'// performed on a handle.  For example, Application Verifier
'// can enable this for some versions of Windows.  The
'// handle operation list collects handle operations
'// known for the dump target.
'// Each entry is an AVRF_HANDLE_OPERATION.

' // Size = 16 bytes
TYPE MINIDUMP_HANDLE_OPERATION_LIST DWORD
   SizeOfHeader    AS DWORD   ' ULONG32
   SizeOfEntry     AS DWORD   ' ULONG32
   NumberOfEntries AS DWORD   ' ULONG32
   Reserved        AS DWORD   ' ULONG32
END TYPE


'//
'// Support for capturing dynamic function table state at the time of the dump.
'//

' // Size = 32 bytes
TYPE MINIDUMP_FUNCTION_TABLE_DESCRIPTOR DWORD
   MinimumAddress AS QUAD    ' ULONG64
   MaximumAddress AS QUAD    ' ULONG64
   BaseAddress    AS QUAD    ' ULONG64
   EntryCount     AS DWORD   ' ULONG32
   SizeOfAlignPad AS DWORD   ' ULONG32
END TYPE

' // Size = 24 bytes
TYPE MINIDUMP_FUNCTION_TABLE_STREAM DWORD
   SizeOfHeader           AS DWORD   ' ULONG32
   SizeOfDescriptor       AS DWORD   ' ULONG32
   SizeOfNativeDescriptor AS DWORD   ' ULONG32
   SizeOfFunctionEntry    AS DWORD   ' ULONG32
   NumberOfDescriptors    AS DWORD   ' ULONG32
   SizeOfAlignPad         AS DWORD   ' ULONG32
END TYPE


'//
'// The MINIDUMP_UNLOADED_MODULE contains information about a
'// a specific module that was previously loaded but no
'// longer is.  This can help with diagnosing problems where
'// callers attempt to call code that is no longer loaded.
'//

' // Size = 24 bytes
TYPE MINIDUMP_UNLOADED_MODULE DWORD
   BaseOfImage   AS QUAD    ' ULONG64
   SizeOfImage   AS DWORD   ' ULONG32
   CheckSum      AS DWORD   ' ULONG32
   TimeDateStamp AS DWORD   ' ULONG32
   ModuleNameRva AS DWORD   ' RVA
END TYPE


'//
'// The minidump unloaded module list is a container for unloaded modules.
'//

' // Size = 12 bytes
TYPE MINIDUMP_UNLOADED_MODULE_LIST DWORD
   SizeOfHeader    AS DWORD   ' ULONG32
   SizeOfEntry     AS DWORD   ' ULONG32
   NumberOfEntries AS DWORD   ' ULONG32
END TYPE


'//
'// The miscellaneous information stream contains a variety
'// of small pieces of information.  A member is valid if
'// it's within the available size and its corresponding
'// bit is set.
'//

%MINIDUMP_MISC1_PROCESS_ID           = &H00000001???
%MINIDUMP_MISC1_PROCESS_TIMES        = &H00000002???
%MINIDUMP_MISC1_PROCESSOR_POWER_INFO = &H00000004???
%MINIDUMP_MISC3_PROCESS_INTEGRITY     = &H00000010???
%MINIDUMP_MISC3_PROCESS_EXECUTE_FLAGS = &H00000020???
%MINIDUMP_MISC3_TIMEZONE              = &H00000040???
%MINIDUMP_MISC3_PROTECTED_PROCESS     = &H00000080???

' // Size = 24 bytes
TYPE MINIDUMP_MISC_INFO DWORD
   SizeOfInfo        AS DWORD   ' ULONG32
   Flags1            AS DWORD   ' ULONG32
   ProcessId         AS DWORD   ' ULONG32
   ProcessCreateTime AS DWORD   ' ULONG32
   ProcessUserTime   AS DWORD   ' ULONG32
   ProcessKernelTime AS DWORD   ' ULONG32
END TYPE

' // Size = 44 bytes
TYPE MINIDUMP_MISC_INFO_2 DWORD
   SizeOfInfo                AS DWORD   ' ULONG32
   Flags1                    AS DWORD   ' ULONG32
   ProcessId                 AS DWORD   ' ULONG32
   ProcessCreateTime         AS DWORD   ' ULONG32
   ProcessUserTime           AS DWORD   ' ULONG32
   ProcessKernelTime         AS DWORD   ' ULONG32
   ProcessorMaxMhz           AS DWORD   ' ULONG32
   ProcessorCurrentMhz       AS DWORD   ' ULONG32
   ProcessorMhzLimit         AS DWORD   ' ULONG32
   ProcessorMaxIdleState     AS DWORD   ' ULONG32
   ProcessorCurrentIdleState AS DWORD   ' ULONG32
END TYPE

'// The latest MINIDUMP_MISC_INFO definition.
'typedef MINIDUMP_MISC_INFO_2 MINIDUMP_MISC_INFO_N;
'typedef MINIDUMP_MISC_INFO_N* PMINIDUMP_MISC_INFO_N;

' // Size = 232 bytes
TYPE MINIDUMP_MISC_INFO_3 DWORD
   SizeOfInfo                AS DWORD   ' ULONG32
   Flags1                    AS DWORD   ' ULONG32
   ProcessId                 AS DWORD   ' ULONG32
   ProcessCreateTime         AS DWORD   ' ULONG32
   ProcessUserTime           AS DWORD   ' ULONG32
   ProcessKernelTime         AS DWORD   ' ULONG32
   ProcessorMaxMhz           AS DWORD   ' ULONG32
   ProcessorCurrentMhz       AS DWORD   ' ULONG32
   ProcessorMhzLimit         AS DWORD   ' ULONG32
   ProcessorMaxIdleState     AS DWORD   ' ULONG32
   ProcessorCurrentIdleState AS DWORD   ' ULONG32
   ProcessIntegrityLevel     AS DWORD   ' ULONG32
   ProcessExecuteFlags       AS DWORD   ' ULONG32
   ProtectedProcess          AS DWORD   ' ULONG32
   TimeZoneId                AS DWORD   ' ULONG32
   TimeZone                  AS TIME_ZONE_INFORMATION
END TYPE

'// The latest MINIDUMP_MISC_INFO definition.
'typedef MINIDUMP_MISC_INFO_3 MINIDUMP_MISC_INFO_N;
'typedef MINIDUMP_MISC_INFO_N* PMINIDUMP_MISC_INFO_N;

'//
'// The memory information stream contains memory region
'// description information.  This stream corresponds to
'// what VirtualQuery would return for the process the
'// dump was created for.
'//

TYPE MINIDUMP_MEMORY_INFO
   BaseAddress       AS QUAD    ' ULONG64
   AllocationBase    AS QUAD    ' ULONG64
   AllocationProtect AS DWORD   ' ULONG32
   alignment1__      AS DWORD   ' ULONG32
   RegionSize        AS QUAD    ' ULONG64
   State             AS DWORD   ' ULONG32
   Protect           AS DWORD   ' ULONG32
   Type              AS DWORD   ' ULONG32
   alignment2__      AS DWORD   ' ULONG32
END TYPE

TYPE MINIDUMP_MEMORY_INFO_LIST
   SizeOfHeader    AS DWORD   ' ULONG
   SizeOfEntry     AS DWORD   ' ULONG
   NumberOfEntries AS QUAD    ' ULONG64
END TYPE


'//
'// The memory information stream contains memory region
'// description information.  This stream corresponds to
'// what VirtualQuery would return for the process the
'// dump was created for.
'//

'// Thread dump writer status flags.
%MINIDUMP_THREAD_INFO_ERROR_THREAD    = &H00000001???
%MINIDUMP_THREAD_INFO_WRITING_THREAD  = &H00000002???
%MINIDUMP_THREAD_INFO_EXITED_THREAD   = &H00000004???
%MINIDUMP_THREAD_INFO_INVALID_INFO    = &H00000008???
%MINIDUMP_THREAD_INFO_INVALID_CONTEXT = &H00000010???
%MINIDUMP_THREAD_INFO_INVALID_TEB     = &H00000020???

' // Size = 64 bytes
TYPE MINIDUMP_THREAD_INFO QWORD FILL
   ThreadId     AS DWORD   ' ULONG32
   DumpFlags    AS DWORD   ' ULONG32
   DumpError    AS DWORD   ' ULONG32
   ExitStatus   AS DWORD   ' ULONG32
   CreateTime   AS QUAD    ' ULONG64
   ExitTime     AS QUAD    ' ULONG64
   KernelTime   AS QUAD    ' ULONG64
   UserTime     AS QUAD    ' ULONG64
   StartAddress AS QUAD    ' ULONG64
   Affinity     AS QUAD    ' ULONG64
END TYPE

' // Size = 12 bytes
TYPE MINIDUMP_THREAD_INFO_LIST DWORD
   SizeOfHeader    AS DWORD   ' ULONG
   SizeOfEntry     AS DWORD   ' ULONG
   NumberOfEntries AS DWORD   ' ULONG
END TYPE

'//
'// Support for token information.
'//
' // Size = 16 bytes
TYPE MINIDUMP_TOKEN_INFO_HEADER QWORD FILL
   TokenSize   AS DWORD   ' ULONG // The size of the token structure.
   TokenId     AS DWORD   ' ULONG // The PID in NtOpenProcessToken() call or TID in NtOpenThreadToken() call.
   TokenHandle AS QUAD    ' ULONG64 // The handle value returned.
END TYPE

' // Size = 16 bytes
TYPE MINIDUMP_TOKEN_INFO_LIST DWORD
   TokenListSize     AS DWORD   ' ULONG
   TokenListEntries  AS DWORD   ' ULONG
   ListHeaderSize    AS DWORD   ' ULONG
   ElementHeaderSize AS DWORD   ' ULONG
END TYPE

'//
'// Support for arbitrary user-defined information.
'//

' // Size = 12 bytes
TYPE MINIDUMP_USER_RECORD DWORD
   Type   AS DWORD   ' ULONG32
   Memory AS MINIDUMP_LOCATION_DESCRIPTOR
END TYPE

' // Size = 12 bytes
TYPE MINIDUMP_USER_STREAM DWORD
   Type       AS DWORD   ' ULONG32
   BufferSize AS DWORD   ' ULONG
   Buffer     AS DWORD   ' PVOID
END TYPE

' // Size = 8 bytes
TYPE MINIDUMP_USER_STREAM_INFORMATION DWORD
   UserStreamCount AS DWORD   ' ULONG
   UserStreamArray AS MINIDUMP_USER_STREAM PTR   ' PMINIDUMP_USER_STREAM
END TYPE

'//
'// Callback support.
'//

' enum MINIDUMP_CALLBACK_TYPE
%ModuleCallback               = 0???
%ThreadCallback               = 1???
%ThreadExCallback             = 2???
%IncludeThreadCallback        = 3???
%IncludeModuleCallback        = 4???
%MemoryCallback               = 5???
%CancelCallback               = 6???
%WriteKernelMinidumpCallback  = 7???
%KernelMinidumpStatusCallback = 8???
%RemoveMemoryCallback         = 9???
%IncludeVmRegionCallback      = 10???
%IoStartCallback              = 11???
%IoWriteAllCallback           = 12???
%IoFinishCallback             = 13???
%ReadMemoryFailureCallback    = 14???
%SecondaryFlagsCallback       = 15???

' // Size = 744 bytes
TYPE MINIDUMP_THREAD_CALLBACK DWORD
   ThreadId      AS DWORD     ' ULONG
   ThreadHandle  AS DWORD     ' HANDLE
   Context       AS CONTEXT
   SizeOfContext AS DWORD     ' ULONG
   StackBase     AS QUAD      ' ULONG64
   StackEnd      AS QUAD      ' ULONG64
END TYPE

' // Size = 760 bytes
TYPE MINIDUMP_THREAD_EX_CALLBACK DWORD
   ThreadId         AS DWORD     ' ULONG
   ThreadHandle     AS DWORD     ' HANDLE
   Context          AS CONTEXT
   SizeOfContext    AS DWORD     ' ULONG
   StackBase        AS QUAD      ' ULONG64
   StackEnd         AS QUAD      ' ULONG64
   BackingStoreBase AS QUAD      ' ULONG64
   BackingStoreEnd  AS QUAD      ' ULONG64
END TYPE

' // Size = 4 bytes
TYPE MINIDUMP_INCLUDE_THREAD_CALLBACK DWORD
   ThreadId AS DWORD   ' ULONG
END TYPE

' enum THREAD_WRITE_FLAGS
%ThreadWriteThread            = &H0001???
%ThreadWriteStack             = &H0002???
%ThreadWriteContext           = &H0004???
%ThreadWriteBackingStore      = &H0008???
%ThreadWriteInstructionWindow = &H0010???
%ThreadWriteThreadData        = &H0020???
%ThreadWriteThreadInfo        = &H0040???

' // Size = 92 bytes
TYPE MINIDUMP_MODULE_CALLBACK DWORD
   FullPath         AS WSTRINGZ PTR   ' PWCHAR
   BaseOfImage      AS QUAD           ' ULONG64
   SizeOfImage      AS DWORD          ' ULONG
   CheckSum         AS DWORD          ' ULONG
   TimeDateStamp    AS DWORD          ' ULONG
   VersionInfo      AS VS_FIXEDFILEINFO
   CvRecord         AS DWORD          ' PVOID
   SizeOfCvRecord   AS DWORD          ' ULONG
   MiscRecord       AS DWORD          ' PVOID
   SizeOfMiscRecord AS DWORD          ' ULONG
END TYPE

' // Size = 8 bytes
TYPE MINIDUMP_INCLUDE_MODULE_CALLBACK QWORD
   BaseOfImage AS QUAD   ' ULONG64
END TYPE

' enum MODULE_WRITE_FLAGS
%ModuleWriteModule        = &H0001???
%ModuleWriteDataSeg       = &H0002???
%ModuleWriteMiscRecord    = &H0004???
%ModuleWriteCvRecord      = &H0008???
%ModuleReferencedByMemory = &H0010???
%ModuleWriteTlsData       = &H0020???
%ModuleWriteCodeSegs      = &H0040???

' // Size = 20 bytes
TYPE MINIDUMP_IO_CALLBACK DWORD
   Handle      AS DWORD   ' HANDLE
   Offset      AS QUAD    ' ULONG64
   Buffer      AS DWORD   ' PVOID
   BufferBytes AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE MINIDUMP_READ_MEMORY_FAILURE_CALLBACK
   Offset        AS QUAD    ' ULONG64
   Bytes         AS DWORD   ' ULONG
   FailureStatus AS LONG    ' HRESULT
END TYPE

'typedef struct _MINIDUMP_CALLBACK_INPUT {
'    ULONG ProcessId;
'    HANDLE ProcessHandle;
'    ULONG CallbackType;
'    union {
'        HRESULT Status;
'        MINIDUMP_THREAD_CALLBACK Thread;
'        MINIDUMP_THREAD_EX_CALLBACK ThreadEx;
'        MINIDUMP_MODULE_CALLBACK Module;
'        MINIDUMP_INCLUDE_THREAD_CALLBACK IncludeThread;
'        MINIDUMP_INCLUDE_MODULE_CALLBACK IncludeModule;
'        MINIDUMP_IO_CALLBACK Io;
'        MINIDUMP_READ_MEMORY_FAILURE_CALLBACK ReadMemoryFailure;
'        ULONG SecondaryFlags;
'    };
'} MINIDUMP_CALLBACK_INPUT, *PMINIDUMP_CALLBACK_INPUT;

' // Size = 760 bytes bytes
UNION MINIDUMP_CALLBACK_INPUT_UNION DWORD
   Status            AS LONG    ' HRESULT
   Thread            AS MINIDUMP_THREAD_CALLBACK
   ThreadEx          AS MINIDUMP_THREAD_EX_CALLBACK
   Module            AS MINIDUMP_MODULE_CALLBACK
   IncludeThread     AS MINIDUMP_INCLUDE_THREAD_CALLBACK
   IncludeModule     AS MINIDUMP_INCLUDE_MODULE_CALLBACK
   Io                AS MINIDUMP_IO_CALLBACK
   ReadMemoryFailure AS MINIDUMP_READ_MEMORY_FAILURE_CALLBACK
   SecondaryFlags    AS DWORD   ' ULONG
END UNION

' // Size = 772 bytes bytes
TYPE MINIDUMP_CALLBACK_INPUT DWORD
   ProcessId     AS DWORD   ' ULONG
   ProcessHandle AS DWORD   ' HANDLE
   CallbackType  AS DWORD   ' ULONG
   MINIDUMP_CALLBACK_INPUT_UNION
END TYPE

' // Size = 12 bytes bytes
TYPE INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_1 DWORD
   MemoryBase AS QUAD    ' ULONG64
   MemorySize AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes bytes
TYPE INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_2 DWORD
   CheckCancel AS LONG   ' BOOL
   Cancel      AS LONG   ' BOOL
END TYPE

' // Size = 52 bytes bytes
TYPE INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_3 DWORD
   VmRegion AS MINIDUMP_MEMORY_INFO
   Continue AS LONG   ' BOOL
END TYPE

' // Size = 52 bytes bytes
UNION INIDUMP_CALLBACK_OUTPUT_UNION DWORD
   ModuleWriteFlags AS DWORD   ' ULONG
   ThreadWriteFlags AS DWORD   ' ULONG
   SecondaryFlags   AS DWORD   ' ULONG
   INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_1
   INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_2
   Handle           AS DWORD   ' HANDLE
   INIDUMP_CALLBACK_OUTPUT_UNION_STRUCT_3
   Status           AS LONG    ' HRESULT
END UNION

' // Size = 52 bytes bytes
TYPE MINIDUMP_CALLBACK_OUTPUT DWORD
   INIDUMP_CALLBACK_OUTPUT_UNION
END TYPE

'//
'// A normal minidump contains just the information
'// necessary to capture stack traces for all of the
'// existing threads in a process.
'//
'// A minidump with data segments includes all of the data
'// sections from loaded modules in order to capture
'// global variable contents.  This can make the dump much
'// larger if many modules have global data.
'//
'// A minidump with full memory includes all of the accessible
'// memory in the process and can be very large.  A minidump
'// with full memory always has the raw memory data at the end
'// of the dump so that the initial structures in the dump can
'// be mapped directly without having to include the raw
'// memory information.
'//
'// Stack and backing store memory can be filtered to remove
'// data unnecessary for stack walking.  This can improve
'// compression of stacks and also deletes data that may
'// be private and should not be stored in a dump.
'// Memory can also be scanned to see what modules are
'// referenced by stack and backing store memory to allow
'// omission of other modules to reduce dump size.
'// In either of these modes the ModuleReferencedByMemory flag
'// is set for all modules referenced before the base
'// module callbacks occur.
'//
'// On some operating systems a list of modules that were
'// recently unloaded is kept in addition to the currently
'// loaded module list.  This information can be saved in
'// the dump if desired.
'//
'// Stack and backing store memory can be scanned for referenced
'// pages in order to pick up data referenced by locals or other
'// stack memory.  This can increase the size of a dump significantly.
'//
'// Module paths may contain undesired information such as user names
'// or other important directory names so they can be stripped.  This
'// option reduces the ability to locate the proper image later
'// and should only be used in certain situations.
'//
'// Complete operating system per-process and per-thread information can
'// be gathered and stored in the dump.
'//
'// The virtual address space can be scanned for various types
'// of memory to be included in the dump.
'//
'// Code which is concerned with potentially private information
'// getting into the minidump can set a flag that automatically
'// modifies all existing and future flags to avoid placing
'// unnecessary data in the dump.  Basic data, such as stack
'// information, will still be included but optional data, such
'// as indirect memory, will not.
'//
'// When doing a full memory dump it's possible to store all
'// of the enumerated memory region descriptive information
'// in a memory information stream.
'//
'// Additional thread information beyond the basic thread
'// structure can be collected if desired.
'//
'// A minidump with code segments includes all of the code
'// and code-related sections from loaded modules in order
'// to capture executable content.
'//
'// MiniDumpWithoutAuxiliaryState turns off any secondary,
'// auxiliary-supported memory gathering.
'//
'// MiniDumpWithFullAuxiliaryState asks any present auxiliary
'// data providers to include all of their state in the dump.
'// The exact set of what is provided depends on the auxiliary.
'// This can be quite large.
'//

' enum MINIDUMP_TYPE
%MiniDumpNormal                         = &H00000000???
%MiniDumpWithDataSegs                   = &H00000001???
%MiniDumpWithFullMemory                 = &H00000002???
%MiniDumpWithHandleData                 = &H00000004???
%MiniDumpFilterMemory                   = &H00000008???
%MiniDumpScanMemory                     = &H00000010???
%MiniDumpWithUnloadedModules            = &H00000020???
%MiniDumpWithIndirectlyReferencedMemory = &H00000040???
%MiniDumpFilterModulePaths              = &H00000080???
%MiniDumpWithProcessThreadData          = &H00000100???
%MiniDumpWithPrivateReadWriteMemory     = &H00000200???
%MiniDumpWithoutOptionalData            = &H00000400???
%MiniDumpWithFullMemoryInfo             = &H00000800???
%MiniDumpWithThreadInfo                 = &H00001000???
%MiniDumpWithCodeSegs                   = &H00002000???
%MiniDumpWithoutAuxiliaryState          = &H00004000???
%MiniDumpWithFullAuxiliaryState         = &H00008000???
%MiniDumpWithPrivateWriteCopyMemory     = &H00010000???
%MiniDumpIgnoreInaccessibleMemory       = &H00020000???
%MiniDumpWithTokenInformation           = &H00040000???

%MiniDumpValidTypeFlags                 = &H0000ffff???

'//
'// In addition to the primary flags provided to
'// MiniDumpWriteDump there are additional, less
'// frequently used options queried via the secondary
'// flags callback.
'//
'// MiniSecondaryWithoutPowerInfo suppresses the minidump
'// query that retrieves processor power information for
'// MINIDUMP_MISC_INFO.
'//

' enum MINIDUMP_SECONDARY_FLAGS
%MiniSecondaryWithoutPowerInfo = &H00000001???

%MiniSecondaryValidFlags       = &H00000001???


'//
'// The minidump callback should modify the FieldsToWrite parameter to reflect
'// what portions of the specified thread or module should be written to the
'// file.
'//

'typedef
'BOOL
'(WINAPI * MINIDUMP_CALLBACK_ROUTINE) (
'    IN PVOID CallbackParam,
'    IN CONST PMINIDUMP_CALLBACK_INPUT CallbackInput,
'    IN OUT PMINIDUMP_CALLBACK_OUTPUT CallbackOutput
'    );

'FUNCTION MINIDUMP_CALLBACK_ROUTINE ( _
'   BYVAL CallbackParam AS DWORD _           ' __in PVOID CallbackParam
' , BYVAL CallbackInput AS DWORD _           ' __in IN CONST PMINIDUMP_CALLBACK_INPUT CallbackInput
' , BYREF CallbackOutput AS DWORD _          ' __inout PMINIDUMP_CALLBACK_OUTPUT CallbackOutput
' ) AS LONG                                              ' BOOL

' // Size = 8 bytes bytes
TYPE MINIDUMP_CALLBACK_INFORMATION DWORD
   CallbackRoutine AS DWORD   ' MINIDUMP_CALLBACK_ROUTINE
   CallbackParam   AS DWORD   ' PVOID
END TYPE


'//++
'//
'// PVOID
'// RVA_TO_ADDR(
'//     PVOID Mapping,
'//     ULONG Rva
'//     )
'//
'// Routine Description:
'//
'//     Map an RVA that is contained within a mapped file to it's associated
'//     flat address.
'//
'// Arguments:
'//
'//     Mapping - Base address of mapped file containing the RVA.
'//
'//     Rva - An Rva to fixup.
'//
'// Return Values:
'//
'//     A pointer to the desired data.
'//
'//--

'#define RVA_TO_ADDR(Mapping,Rva) ((PVOID)(((ULONG_PTR) (Mapping)) + (Rva)))

' Does not exist in ImageHlp.dll; it exist in DbgHelp.dll
'DECLARE FUNCTION MiniDumpWriteDump IMPORT "ImageHlp.dll" ALIAS "MiniDumpWriteDump" ( _
'   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
' , BYVAL ProcessId AS DWORD _                           ' __in DWORD ProcessId
' , BYVAL hFile AS DWORD _                               ' __in HANDLE hFile
' , BYVAL DumpType AS DWORD _                            ' __in MINIDUMP_TYPE DumpType
' , BYREF ExceptionParam AS MINIDUMP_EXCEPTION_INFORMATION _    ' __in const PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam OPTIONAL
' , BYREF UserStreamParam AS MINIDUMP_USER_STREAM_INFORMATION _ ' __in const PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam OPTIONAL
' , BYREF CallbackParam AS MINIDUMP_CALLBACK_INFORMATION _      ' __in const PMINIDUMP_CALLBACK_INFORMATION CallbackParam OPTIONAL
' ) AS LONG                                              ' BOOL

' Does not exist in ImageHlp.dll; it exist in DbgHelp.dll
'DECLARE FUNCTION MiniDumpReadDumpStream IMPORT "ImageHlp.dll" ALIAS "MiniDumpReadDumpStream" ( _
'   BYVAL BaseOfDump AS DWORD _                          ' __in PVOID BaseOfDump
' , BYVAL StreamNumber AS DWORD _                        ' __in ULONG StreamNumber
' , BYREF Dir AS MINIDUMP_DIRECTORY _                    ' __out PMINIDUMP_DIRECTORY * Dir OPTIONAL
' , BYREF StreamPointer AS ANY _                         ' __out PVOID * StreamPointer OPTIONAL
' , BYREF StreamSize AS DWORD _                          ' __out ULONG * StreamSize OPTIONAL
' ) AS LONG                                              ' BOOL

'#if defined(_MSC_VER)
'#if _MSC_VER >= 800
'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning(default:4200)    /* Zero length array */
'#pragma warning(default:4201)    /* Nameless struct/union */
'#endif
'#endif
'#endif

'#include <poppack.h>

'#ifdef __cplusplus
'}
'#endif

#ENDIF   ' #IF NOT %DEF(%IMAGEHLP_INC)

#ENDIF   ' #IF NOT %DEF(%DBGHELP_INC)
