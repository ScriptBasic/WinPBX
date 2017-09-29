' ########################################################################################
' Microsoft Windows
' File: PatchApi.inc
' Contents: Interface for creating and applying patches to files
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PATCHAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'//  The following constants can be combined and used as the OptionFlags
'//  parameter in the patch creation apis.
'//

%PATCH_OPTION_USE_BEST           = &H00000000???  ' // auto choose best (slower)

%PATCH_OPTION_USE_LZX_BEST       = &H00000003???  ' // auto choose best of LZX A/B (but not large)
%PATCH_OPTION_USE_LZX_A          = &H00000001???  ' // normal
%PATCH_OPTION_USE_LZX_B          = &H00000002???  ' // better on some x86 binaries
%PATCH_OPTION_USE_LZX_LARGE      = &H00000004???  ' // better support for large files (requires 5.1 or higher applyer)

%PATCH_OPTION_NO_BINDFIX         = &H00010000???  ' // PE bound imports
%PATCH_OPTION_NO_LOCKFIX         = &H00020000???  ' // PE smashed locks
%PATCH_OPTION_NO_REBASE          = &H00040000???  ' // PE rebased image
%PATCH_OPTION_FAIL_IF_SAME_FILE  = &H00080000???  ' // don't create if same
%PATCH_OPTION_FAIL_IF_BIGGER     = &H00100000???  ' // fail if patch is larger than simply compressing new file (slower)
%PATCH_OPTION_NO_CHECKSUM        = &H00200000???  ' // PE checksum zero
%PATCH_OPTION_NO_RESTIMEFIX      = &H00400000???  ' // PE resource timestamps
%PATCH_OPTION_NO_TIMESTAMP       = &H00800000???  ' // don't store new file timestamp in patch
%PATCH_OPTION_SIGNATURE_MD5      = &H01000000???  ' // use MD5 instead of CRC (reserved for future support)
%PATCH_OPTION_INTERLEAVE_FILES   = &H40000000???  ' // better support for large files (requires 5.2 or higher applyer)
%PATCH_OPTION_RESERVED1          = &H80000000???  ' // (used internally)

%PATCH_OPTION_VALID_FLAGS        = &HC0FF0007???

' //
' //  The following flags are used with PATCH_OPTION_DATA SymbolOptionFlags:
' //

%PATCH_SYMBOL_NO_IMAGEHLP        = &H00000001???  ' // don't use imagehlp.dll
%PATCH_SYMBOL_NO_FAILURES        = &H00000002???  ' // don't fail patch due to imagehlp failures
%PATCH_SYMBOL_UNDECORATED_TOO    = &H00000004???  ' // after matching decorated symbols, try to match remaining by undecorated names
%PATCH_SYMBOL_RESERVED1          = &H80000000???  ' // (used internally)

' //
' //  The following flags are used with PATCH_OPTION_DATA ExtendedOptionFlags:
' //

%PATCH_TRANSFORM_PE_RESOURCE_2   = &H00000100???  ' // better handling of PE resources (requires 5.2 or higher applyer)
%PATCH_TRANSFORM_PE_IRELOC_2     = &H00000200???  ' // better handling of PE stripped relocs (requires 5.2 or higher applyer)


' //
' //  The following constants can be combined and used as the ApplyOptionFlags
' //  parameter in the patch apply and test apis.
' //

%APPLY_OPTION_FAIL_IF_EXACT      = &H00000001???  ' // don't copy new file
%APPLY_OPTION_FAIL_IF_CLOSE      = &H00000002???  ' // differ by rebase, bind
%APPLY_OPTION_TEST_ONLY          = &H00000004???  ' // don't create new file
%APPLY_OPTION_VALID_FLAGS        = &H00000007???

' //
' //  In addition to standard Win32 error codes, the following error codes may
' //  be returned via GetLastError() when one of the patch APIs fails.
' //

%ERROR_PATCH_ENCODE_FAILURE          = &HC00E3101???  ' // create
%ERROR_PATCH_INVALID_OPTIONS         = &HC00E3102???  ' // create
%ERROR_PATCH_SAME_FILE               = &HC00E3103???  ' // create
%ERROR_PATCH_RETAIN_RANGES_DIFFER    = &HC00E3104???  ' // create
%ERROR_PATCH_BIGGER_THAN_COMPRESSED  = &HC00E3105???  ' // create
%ERROR_PATCH_IMAGEHLP_FAILURE        = &HC00E3106???  ' // create

%ERROR_PATCH_DECODE_FAILURE          = &HC00E4101???  ' // apply
%ERROR_PATCH_CORRUPT                 = &HC00E4102???  ' // apply
%ERROR_PATCH_NEWER_FORMAT            = &HC00E4103???  ' // apply
%ERROR_PATCH_WRONG_FILE              = &HC00E4104???  ' // apply
%ERROR_PATCH_NOT_NECESSARY           = &HC00E4105???  ' // apply
%ERROR_PATCH_NOT_AVAILABLE           = &HC00E4106???  ' // apply

'typedef BOOL (CALLBACK PATCH_PROGRESS_CALLBACK)(
'    PVOID CallbackContext,
'    ULONG CurrentPosition,
'    ULONG MaximumPosition
'    );

'typedef PATCH_PROGRESS_CALLBACK *PPATCH_PROGRESS_CALLBACK;

'FUNCTION PATCH_PROGRESS_CALLBACK ( _
'   BYVAL CallbackContext AS DWORD _
' , BYVAL CurrentPosition AS DWORD _
' , BYVAL MaximumPosition AS DWORD _
' ) AS LONG

'typedef BOOL (CALLBACK PATCH_SYMLOAD_CALLBACK)(
'    IN ULONG  WhichFile,          ' // 0 for new file, 1 for first old file, etc
'    IN LPCSTR SymbolFileName,
'    IN ULONG  SymType,            ' // see SYM_TYPE in imagehlp.h
'    IN ULONG  SymbolFileCheckSum,
'    IN ULONG  SymbolFileTimeDate,
'    IN ULONG  ImageFileCheckSum,
'    IN ULONG  ImageFileTimeDate,
'    IN PVOID  CallbackContext
'    );

'typedef PATCH_SYMLOAD_CALLBACK *PPATCH_SYMLOAD_CALLBACK;

'FUNCTION PATCH_SYMLOAD_CALLBACK ( _
'   BYVAL WhichFile AS DWORD _
' , BYREF SymbolFileName AS ASCIIZ _
' , BYVAL SymType AS DWORD _
' , BYVAL SymbolFileCheckSum AS DWORD _
' , BYVAL SymbolFileTimeDate AS DWORD _
' , BYVAL ImageFileCheckSum AS DWORD _
' , BYVAL ImageFileTimeDate AS DWORD _
' , BYVAL CallbackContext AS DWORD _
' ) AS LONG

' // Size = 8 bytes
TYPE PATCH_IGNORE_RANGE DWORD
   OffsetInOldFile AS DWORD   ' ULONG
   LengthInBytes   AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE PATCH_RETAIN_RANGE DWORD
   OffsetInOldFile AS DWORD   ' ULONG
   LengthInBytes   AS DWORD   ' ULONG
   OffsetInNewFile AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
TYPE PATCH_OLD_FILE_INFO_A DWORD
   SizeOfThisStruct AS DWORD                    ' ULONG
   OldFileName      AS ASCIIZ PTR               ' LPCSTR
   IgnoreRangeCount AS DWORD                    ' ULONG // maximum 255
   IgnoreRangeArray AS PATCH_IGNORE_RANGE PTR   ' PPATCH_IGNORE_RANGE
   RetainRangeCount AS DWORD                    ' ULONG // maximum 255
   RetainRangeArray AS PATCH_RETAIN_RANGE PTR   ' PPATCH_RETAIN_RANGE
END TYPE

MACRO PATCH_OLD_FILE_INFO = PATCH_OLD_FILE_INFO_A

' // Size = 24 bytes
TYPE PATCH_OLD_FILE_INFO_W DWORD
   SizeOfThisStruct AS DWORD                    ' ULONG
   OldFileName      AS WSTRINGZ PTR             ' LPCWSTR
   IgnoreRangeCount AS DWORD                    ' ULONG // maximum 255
   IgnoreRangeArray AS PATCH_IGNORE_RANGE PTR   ' PPATCH_IGNORE_RANGE
   RetainRangeCount AS DWORD                    ' ULONG // maximum 255
   RetainRangeArray AS PATCH_RETAIN_RANGE PTR   ' PPATCH_RETAIN_RANGE
END TYPE

' // Size = 24 bytes
TYPE PATCH_OLD_FILE_INFO_H DWORD
   SizeOfThisStruct AS DWORD                    ' ULONG
   OldFileHandle    AS DWORD                    ' HANDLE
   IgnoreRangeCount AS DWORD                    ' ULONG // maximum 255
   IgnoreRangeArray AS PATCH_IGNORE_RANGE PTR   ' PPATCH_IGNORE_RANGE
   RetainRangeCount AS DWORD                    ' ULONG // maximum 255
   RetainRangeArray AS PATCH_RETAIN_RANGE PTR   ' PPATCH_RETAIN_RANGE
END TYPE

' // Size = 12 bytes
TYPE PATCH_INTERLEAVE_MAP_RANGE DWORD
   OldOffset AS DWORD   ' ULONG
   OldLength AS DWORD   ' ULONG
   NewLength AS DWORD   ' ULONG // NewOffset implied by sum of previous NewLengths
END TYPE

' // Size = 16 bytes
TYPE PATCH_INTERLEAVE_MAP DWORD
   CountRanges AS DWORD   ' ULONG
   Range(0) AS PATCH_INTERLEAVE_MAP_RANGE   ' // Variable length (CountRanges)
END TYPE

' // Size = 36 bytes
TYPE PATCH_OPTION_DATA DWORD
   SizeOfThisStruct       AS DWORD                      ' ULONG
   SymbolOptionFlags      AS DWORD                      ' ULONG // PATCH_SYMBOL_xxx flags
   NewFileSymbolPath      AS ASCIIZ PTR                 ' LPCSTR // always ANSI, never Unicode
   OldFileSymbolPathArray AS ASCIIZ PTR                 ' LPCSTR* // array[ OldFileCount ]
   ExtendedOptionFlags    AS DWORD                      ' ULONG
   SymLoadCallback        AS DWORD                      ' PPATCH_SYMLOAD_CALLBACK
   SymLoadContext         AS DWORD                      ' PVOID
   InterleaveMapArray     AS PATCH_INTERLEAVE_MAP PTR   ' PPATCH_INTERLEAVE_MAP* // array[ OldFileCount ] (requires 5.2 or higher applyer)
   MaxLzxWindowSize       AS DWORD                      ' ULONG // limit memory requirements (requires 5.2 or higher applyer)
END TYPE

' //
' //  Note that PATCH_OPTION_DATA contains LPCSTR paths, and no LPCWSTR (Unicode)
' //  path argument is available, even when used with one of the Unicode APIs
' //  such as CreatePatchFileW.  This is because the underlying system services
' //  for symbol file handling (IMAGEHLP.DLL) only support ANSI file/path names.
' //

' //
' //  A note about PATCH_RETAIN_RANGE specifiers with multiple old files:
' //
' //  Each old version file must have the same RetainRangeCount, and the same
' //  retain range LengthInBytes and OffsetInNewFile values in the same order.
' //  Only the OffsetInOldFile values can differ between old files for retain
' //  ranges.
' //

' //
' //  The following prototypes are interface for creating patches from files.
' //

DECLARE FUNCTION CreatePatchFileA IMPORT "mspatchc.dll" ALIAS "CreatePatchFileA" ( _
   BYREF OldFileName AS ASCIIZ _                        ' __in_opt LPCSTR OldFileName   // input file  (optional)
 , BYREF NewFileName AS ASCIIZ _                        ' __in     LPCSTR NewFileName   // input file  (required)
 , BYREF PatchFileName AS ASCIIZ _                      ' __in     LPCSTR PatchFileName // output file (required)
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG  OptionFlags
 , BYREF PATCH_OPTION_DATA _                            ' __in_opt PPATCH_OPTION_DATA OptionData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreatePatchFileW IMPORT "mspatchc.dll" ALIAS "CreatePatchFileW" ( _
   BYREF OldFileName AS WSTRINGZ _                      ' __in_opt LPCWSTR OldFileName   // input file  (optional)
 , BYREF NewFileName AS WSTRINGZ _                      ' __in     LPCWSTR NewFileName   // input file  (required)
 , BYREF PatchFileName AS WSTRINGZ _                    ' __in     LPCWSTR PatchFileName // output file (required)
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG   OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PPATCH_OPTION_DATA OptionData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreatePatchFile = CreatePatchFileW
#ELSE
   MACRO CreatePatchFile = CreatePatchFileA
#ENDIF

DECLARE FUNCTION CreatePatchFileByHandles IMPORT "mspatchc.dll" ALIAS "CreatePatchFileByHandles" ( _
   BYVAL OldFileHandle AS DWORD _                       ' __in_opt HANDLE OldFileHandle   // input file  (optional)
 , BYVAL NewFileHandle AS DWORD _                       ' __in     HANDLE NewFileHandle   // input file  (required)
 , BYVAL PatchFileHandle AS DWORD _                     ' __in     HANDLE PatchFileHandle // output file (required)
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG  OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PPATCH_OPTION_DATA OptionData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreatePatchFileExA IMPORT "mspatchc.dll" ALIAS "CreatePatchFileExA" ( _
   BYVAL OldFileCount AS DWORD _                        ' __in     ULONG                    OldFileCount     // maximum 255
 , BYREF OldFileInfoArray AS PATCH_OLD_FILE_INFO_A _    ' __in     PPATCH_OLD_FILE_INFO_A   OldFileInfoArray
 , BYREF NewFileName AS ASCIIZ _                        ' __in     LPCSTR                   NewFileName      // input file
 , BYREF PatchFileName AS ASCIIZ _                      ' __in     LPCSTR                   PatchFileName    // output file
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG                    OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PPATCH_OPTION_DATA       OptionData
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID                    CallbackContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreatePatchFileExW IMPORT "mspatchc.dll" ALIAS "CreatePatchFileExW" ( _
   BYVAL OldFileCount AS DWORD _                        ' __in     ULONG                    OldFileCount     // maximum 255
 , BYREF OldFileInfoArray AS PATCH_OLD_FILE_INFO_W _    ' __in     PPATCH_OLD_FILE_INFO_W   OldFileInfoArray
 , BYREF NewFileName AS WSTRINGZ _                      ' __in     LPCWSTR                  NewFileName      // input file
 , BYREF PatchFileName AS WSTRINGZ _                    ' __in     LPCWSTR                  PatchFileName    // output file
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG                    OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PPATCH_OPTION_DATA       OptionData
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID                    CallbackContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreatePatchFileEx = CreatePatchFileExW
#ELSE
   MACRO CreatePatchFileEx = CreatePatchFileExA
#ENDIF

DECLARE FUNCTION CreatePatchFileByHandlesEx IMPORT "mspatchc.dll" ALIAS "CreatePatchFileByHandlesEx" ( _
   BYVAL OldFileCount AS DWORD _                        ' __in     ULONG                    OldFileCount     // maximum 255
 , BYREF OldFileInfoArray AS PATCH_OLD_FILE_INFO_H _    ' __in     PPATCH_OLD_FILE_INFO_H   OldFileInfoArray
 , BYVAL NewFileHandle AS DWORD _                       ' __in     HANDLE                   NewFileHandle    // input file
 , BYVAL PatchFileHandle AS DWORD _                     ' __in     HANDLE                   PatchFileHandle  // output file
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG                    OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PPATCH_OPTION_DATA       OptionData
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID                    CallbackContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExtractPatchHeaderToFileA IMPORT "mspatchc.dll" ALIAS "ExtractPatchHeaderToFileA" ( _
   BYREF PatchFileName AS ASCIIZ _                      ' __in LPCSTR PatchFileName          // input file
 , BYREF PatchHeaderFileName AS ASCIIZ _                ' __in LPCSTR PatchHeaderFileName    // output file
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExtractPatchHeaderToFileW IMPORT "mspatchc.dll" ALIAS "ExtractPatchHeaderToFileW" ( _
   BYREF PatchFileName AS WSTRINGZ _                    ' __in LPCWSTR PatchFileName          // input file
 , BYREF PatchHeaderFileName AS WSTRINGZ _              ' __in LPCWSTR PatchHeaderFileName    // output file
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ExtractPatchHeaderToFile = ExtractPatchHeaderToFileW
#ELSE
   MACRO ExtractPatchHeaderToFile = ExtractPatchHeaderToFileA
#ENDIF

DECLARE FUNCTION ExtractPatchHeaderToFileByHandles IMPORT "mspatchc.dll" ALIAS "ExtractPatchHeaderToFileByHandles" ( _
   BYVAL PatchFileHandle AS DWORD _                     ' __in HANDLE PatchFileHandle          // input file
 , BYVAL PatchHeaderFileHandle AS DWORD _               ' __in HANDLE PatchHeaderFileHandle    // output file
 ) AS LONG                                              ' BOOL

' //
' //  The following prototypes are interface for creating new file from old file
' //  and patch file.  Note that it is possible for the TestApply API to succeed
' //  but the actual Apply to fail since the TestApply only verifies that the
' //  old file has the correct CRC without actually applying the patch.  The
' //  TestApply API only requires the patch header portion of the patch file,
' //  but its CRC must be corrected.
' //

DECLARE FUNCTION TestApplyPatchToFileA IMPORT "mspatcha.dll" ALIAS "TestApplyPatchToFileA" ( _
   BYREF PatchFileName AS ASCIIZ _                      ' __in LPCSTR PatchFileName
 , BYREF OldFileName AS ASCIIZ _                        ' __in LPCSTR OldFileName
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TestApplyPatchToFileW IMPORT "mspatcha.dll" ALIAS "TestApplyPatchToFileW" ( _
   BYREF PatchFileName AS WSTRINGZ _                    ' __in LPCWSTR PatchFileName
 , BYREF OldFileName AS WSTRINGZ _                      ' __in LPCWSTR OldFileName
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO TestApplyPatchToFile = TestApplyPatchToFileW
#ELSE
   MACRO TestApplyPatchToFile = TestApplyPatchToFileA
#ENDIF

DECLARE FUNCTION TestApplyPatchToFileByHandles IMPORT "mspatcha.dll" ALIAS "TestApplyPatchToFileByHandles" ( _
   BYVAL PatchFileHandle AS DWORD _                     ' __in HANDLE PatchFileHandle      // requires GENERIC_READ access
 , BYVAL OldFileHandle AS DWORD _                       ' __in HANDLE OldFileHandle        // requires GENERIC_READ access
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TestApplyPatchToFileByBuffers IMPORT "mspatcha.dll" ALIAS "TestApplyPatchToFileByBuffers" ( _
   BYVAL PatchFileBuffer AS BYTE PTR _                  ' __in      PBYTE  PatchFileBuffer     // not modified
 , BYVAL PatchFileSize AS DWORD _                       ' __in      ULONG  PatchFileSize
 , BYVAL OldFileBuffer AS BYTE PTR _                    ' __in      PBYTE  OldFileBuffer       // not modified
 , BYVAL OldFileSize AS DWORD _                         ' __in      ULONG  OldFileSize
 , BYREF NewFileSize AS DWORD _                         ' __out_opt ULONG* NewFileSize         // optional
 , BYVAL ApplyOptionFlags As DWORD _                    ' __in      ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ApplyPatchToFileA IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileA" ( _
   BYREF PatchFileName AS ASCIIZ _                      ' __in     LPCSTR PatchFileName      // input file (required)
 , BYREF OldFileName AS ASCIIZ _                        ' __in_opt LPCSTR OldFileName        // input file (optional)
 , BYREF NewFileName AS ASCIIZ _                        ' __in     LPCSTR NewFileName        // output file (required)
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ApplyPatchToFileW IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileW" ( _
   BYREF PatchFileName AS WSTRINGZ _                    ' __in     LPCWSTR PatchFileName      // input file (required)
 , BYREF OldFileName AS WSTRINGZ _                      ' __in_opt LPCWSTR OldFileName        // input file (optional)
 , BYREF NewFileName AS WSTRINGZ _                      ' __in     LPCWSTR NewFileName        // output file (required)
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG   ApplyOptionFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ApplyPatchToFile = ApplyPatchToFileW
#ELSE
   MACRO ApplyPatchToFile = ApplyPatchToFileA
#ENDIF

DECLARE FUNCTION ApplyPatchToFileByHandles IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileByHandles" ( _
   BYVAL PatchFileHandle AS DWORD _                     ' __in     HANDLE PatchFileHandle      // input file (required)  GENERIC_READ
 , BYVAL OldFileHandle AS DWORD _                       ' __in_opt HANDLE OldFileHandle        // input file (optional)  GENERIC_READ
 , BYVAL NewFileHandle AS DWORD _                       ' __in     HANDLE NewFileHandle        // output file (required) GENERIC_WRITE
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG  ApplyOptionFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ApplyPatchToFileExA IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileExA" ( _
   BYREF PatchFileName AS ASCIIZ _                      ' __in     LPCSTR PatchFileName      // input file (required)
 , BYREF OldFileName AS ASCIIZ _                        ' __in_opt LPCSTR OldFileName        // input file (optional)
 , BYREF NewFileName AS ASCIIZ _                        ' __in     LPCSTR NewFileName        // output file (required)
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG  ApplyOptionFlags
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID                    CallbackContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ApplyPatchToFileExW IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileExW" ( _
   BYVAL PatchFileName AS DWORD _                       ' __in     HANDLE PatchFileName      // input file (required)  GENERIC_READ
 , BYVAL OldFileName AS DWORD _                         ' __in_opt HANDLE OldFileName        // input file (optional)  GENERIC_READ
 , BYVAL NewFileName AS DWORD _                         ' __in     HANDLE NewFileName        // output file (required) GENERIC_WRITE
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG  ApplyOptionFlags
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID                    CallbackContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ApplyPatchToFileEx = ApplyPatchToFileExW
#ELSE
   MACRO ApplyPatchToFileEx = ApplyPatchToFileExA
#ENDIF

DECLARE FUNCTION ApplyPatchToFileByHandlesEx IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileByHandlesEx" ( _
   BYVAL PatchFileHandle AS DWORD _                     ' __in     HANDLE PatchFileHandle      // input file (required)  GENERIC_READ
 , BYVAL OldFileHandle AS DWORD _                       ' __in_opt HANDLE OldFileHandle        // input file (optional)  GENERIC_READ
 , BYVAL NewFileHandle AS DWORD _                       ' __in     HANDLE NewFileHandle        // output file (required) GENERIC_WRITE
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in     ULONG  ApplyOptionFlags
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID  CallbackContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ApplyPatchToFileByBuffers IMPORT "mspatcha.dll" ALIAS "ApplyPatchToFileByBuffers" ( _
   BYVAL PatchFileMapped AS BYTE PTR _                  ' __in        PBYTE  PatchFileMapped     // not modified
 , BYVAL PatchFileSize AS DWORD _                       ' __in        ULONG  PatchFileSize
 , BYVAL OldFileMapped AS BYTE PTR _                    ' __in        PBYTE  OldFileMapped       // not modified
 , BYVAL OldFileSize AS DWORD _                         ' __in        ULONG  OldFileSize
 , BYVAL NewFileBuffer AS BYTE PTR _                    ' __opt_inout PBYTE* NewFileBuffer       // caller-supplied or returned buffer
 , BYVAL NewFileBufferSize AS DWORD _                   ' __in        ULONG  NewFileBufferSize   // caller-supplied buffer size
 , BYREF NewFileActualSize AS DWORD _                   ' __out_opt   ULONG* NewFileActualSize   // actual or required size
 , BYREF NewFileTime AS FILETIME _                      ' __out_opt   FILETIME* NewFileTime      // optional
 , BYVAL ApplyOptionFlags AS DWORD _                    ' __in        ULONG  ApplyOptionFlags
 , BYVAL ProgressCallback AS DWORD _                    ' __in_opt    PPATCH_PROGRESS_CALLBACK ProgressCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt    PVOID  CallbackContext
 ) AS LONG                                              ' BOOL

' //
' //  If *NewFileBuffer is NULL, and APPLY_OPTION_TEST_ONLY is not specified,
' //  and the function succeeds (returns TRUE), and size of new file is non-zero,
' //  *NewFileBuffer will be set to a VirtualAlloc buffer of the required size,
' //  and it will be the caller's responsibility to VirtualFree this buffer.
' //  NewFileBufferSize is ignored when *NewFileBuffer is NULL.
' //
' //  If *NewFileBuffer is non-NULL, and APPLY_OPTION_TEST_ONLY is not specified,
' //  NewFileBufferSize specifies the size of caller-supplied *NewFileBuffer
' //  buffer.  If required size exceeds NewFileBufferSize, function will fail
' //  (return FALSE), *NewFileActualSize will be set to required size, and
' //  GetLastError will return ERROR_INSUFFICIENT_BUFFER.
' //
' //  If ApplyOptionFlags APPLY_OPTION_TEST_ONLY is specified, NewFileBuffer
' //  and NewFileBufferSize are ignored, and *NewFileActualSize will be set to
' //  required buffer size.  If APPLY_OPTION_TEST_ONLY is not specified, then
' //  NewFileBuffer must be non-NULL (*NewFileBuffer may be NULL).
' //
' //  NewFileTime is optional.  If non-NULL, the value returned will either be
' //  non-zero to indicate the new file time as specified in the patch, or zero
' //  to indicate that file time was not stored inside the patch.
' //


' //
' //  The following prototypes provide a unique patch "signature" for a given
' //  file.  Consider the case where you have a new foo.dll and the machines
' //  to be updated with the new foo.dll may have one of three different old
' //  foo.dll files.  Rather than creating a single large patch file that can
' //  update any of the three older foo.dll files, three separate smaller patch
' //  files can be created and identified according to the patch signature of the
' //  old file.  Then the patch applyer application can determine at runtime
' //  which of the three foo.dll patch files is necessary given the specific
' //  foo.dll to be updated.  If patch files are being downloaded over a slow
' //  network connection (internet over a modem), this signature scheme provides
' //  a mechanism for choosing the correct single patch file to download at
' //  application time thus decreasing total bytes necessary to download.
' //

DECLARE FUNCTION GetFilePatchSignatureA IMPORT "mspatcha.dll" ALIAS "GetFilePatchSignatureA" ( _
   BYREF FileName AS ASCIIZ _                           ' __in     LPCSTR FileName
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG  OptionFlags
 , BYVAL OptionData AS DWORD _                          ' __in_opt PVOID  OptionData
 , BYVAL IgnoreRangeCount AS DWORD _                    ' __in     ULONG  IgnoreRangeCount
 , BYREF IgnoreRangeArray AS PATCH_IGNORE_RANGE _       ' __in     PPATCH_IGNORE_RANGE IgnoreRangeArray
 , BYVAL RetainRangeCount AS DWORD _                    ' __in     ULONG  RetainRangeCount
 , BYREF RetainRangeArray AS PATCH_RETAIN_RANGE _       ' __in     PPATCH_RETAIN_RANGE RetainRangeArray
 , BYVAL SignatureBufferSize AS DWORD _                 ' __in     ULONG  SignatureBufferSize
 , BYREF SignatureBuffer AS ASCIIZ _                    ' __out    LPSTR  SignatureBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFilePatchSignatureW IMPORT "mspatcha.dll" ALIAS "GetFilePatchSignatureW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in     LPCWSTR FileName
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG   OptionFlags
 , BYVAL OptionData AS DWORD _                          ' __in_opt PVOID   OptionData
 , BYVAL IgnoreRangeCount AS DWORD _                    ' __in     ULONG   IgnoreRangeCount
 , BYREF IgnoreRangeArray AS PATCH_IGNORE_RANGE _       ' __in     PPATCH_IGNORE_RANGE IgnoreRangeArray
 , BYVAL RetainRangeCount AS DWORD _                    ' __in     ULONG   RetainRangeCount
 , BYREF RetainRangeArray AS PATCH_RETAIN_RANGE _       ' __in     PPATCH_RETAIN_RANGE RetainRangeArray
 , BYVAL SignatureBufferSize AS DWORD _                 ' __in     ULONG   SignatureBufferSize
 , BYREF SignatureBuffer AS WSTRINGZ _                  ' __out    LPWSTR  SignatureBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetFilePatchSignature = GetFilePatchSignatureW
#ELSE
   MACRO GetFilePatchSignature = GetFilePatchSignatureA
#ENDIF

DECLARE FUNCTION GetFilePatchSignatureByHandle IMPORT "mspatcha.dll" ALIAS "GetFilePatchSignatureByHandle" ( _
   BYVAL FileHandle AS DWORD _                          ' __in     HANDLE  FileHandle
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG   OptionFlags
 , BYVAL OptionData AS DWORD _                          ' __in_opt PVOID   OptionData
 , BYVAL IgnoreRangeCount AS DWORD _                    ' __in     ULONG   IgnoreRangeCount
 , BYREF IgnoreRangeArray AS PATCH_IGNORE_RANGE _       ' __in_opt PPATCH_IGNORE_RANGE IgnoreRangeArray
 , BYVAL RetainRangeCount AS DWORD _                    ' __in     ULONG   RetainRangeCount
 , BYREF RetainRangeArray AS PATCH_RETAIN_RANGE _       ' __in_opt PPATCH_RETAIN_RANGE RetainRangeArray
 , BYVAL SignatureBufferSize AS DWORD _                 ' __in     ULONG   SignatureBufferSize
 , BYREF SignatureBuffer AS ASCIIZ _                    ' __out    LPSTR   SignatureBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFilePatchSignatureByBuffer IMPORT "mspatcha.dll" ALIAS "GetFilePatchSignatureByBuffer" ( _
   BYVAL FileBufferWritable AS BYTE PTR _               ' __inout  PBYTE   FileBufferWritable   ' // modified!
 , BYVAL FileSize AS DWORD _                            ' __in     ULONG   FileSize
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG   OptionFlags
 , BYVAL OptionData AS DWORD _                          ' __in_opt PVOID   OptionData
 , BYVAL IgnoreRangeCount AS DWORD _                    ' __in     ULONG   IgnoreRangeCount
 , BYREF IgnoreRangeArray AS PATCH_IGNORE_RANGE _       ' __in_opt PPATCH_IGNORE_RANGE IgnoreRangeArray
 , BYVAL RetainRangeCount AS DWORD _                    ' __in     ULONG   RetainRangeCount
 , BYREF RetainRangeArray AS PATCH_RETAIN_RANGE _       ' __in_opt PPATCH_RETAIN_RANGE RetainRangeArray
 , BYVAL SignatureBufferSize AS DWORD _                 ' __in     ULONG   SignatureBufferSize
 , BYREF SignatureBuffer AS ASCIIZ _                    ' __out    LPSTR   SignatureBuffer
 ) AS LONG                                              ' BOOL

' //
' //  As an alternative to requesting the signature, some applications might use
' //  NormalizeFileForPatchSignature to render a stream that can be hashed
' //  by other means than CRC or MD5 provided by the signature APIs.  This API
' //  returns 0 for failure (GetLastError returns additional info), 1 to indicate
' //  the buffer did not require any modifications for normalization, or 2 to
' //  indicate that the buffer was modified in the process of normalization.
' //

DECLARE FUNCTION NormalizeFileForPatchSignature IMPORT "mspatcha.dll" ALIAS "NormalizeFileForPatchSignature" ( _
   BYVAL FileBuffer AS DWORD _                          ' __inout  PVOID FileBuffer       ' // modified!
 , BYVAL FileSize AS DWORD _                            ' __in     ULONG FileSize
 , BYVAL OptionFlags AS DWORD _                         ' __in     ULONG OptionFlags
 , BYREF OptionData AS PATCH_OPTION_DATA _              ' __in_opt PATCH_OPTION_DATA* OptionData
 , BYVAL NewFileCoffBase AS DWORD _                     ' __in     ULONG NewFileCoffBase
 , BYVAL NewFileCoffTime AS DWORD _                     ' __in     ULONG NewFileCoffTime
 , BYVAL IgnoreRangeCount AS DWORD _                    ' __in     ULONG IgnoreRangeCount
 , BYREF IgnoreRangeArray AS PATCH_IGNORE_RANGE _       ' __in_opt PPATCH_IGNORE_RANGE IgnoreRangeArray
 , BYVAL RetainRangeCount AS DWORD _                    ' __in     ULONG RetainRangeCount
 , BYREF RetainRangeArray AS PATCH_RETAIN_RANGE _       ' __in_opt PPATCH_RETAIN_RANGE RetainRangeArray
 ) AS LONG                                              ' INT
