' ########################################################################################
' Microsoft Windows
' File: MSDelta.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'/* Copyright (c) Microsoft Corporation.  All rights reserved. */

'/** Delta Compression Engine API. */

#INCLUDE THIS ONCE
%MSDELTA_INC = 1

#INCLUDE ONCE "windows.inc"

'/** For crypto algorithm identifiers, ALG_ID. */
#INCLUDE ONCE "wincrypt.inc"

'/** Default size limit for source and target files and buffers. */
%DELTA_FILE_SIZE_LIMIT          = ( 32 * 1024 * 1024 )

'/** Default size limit for options files and buffers. */
%DELTA_OPTIONS_SIZE_LIMIT       = ( 128 * 1024 * 1024 )

'/** Type for input memory blocks. */
' // Size = 4 bytes
UNION DELTA_INPUT_UNION DWORD
   lpcStart AS DWORD   ' /** Start of memory block, if it is not Editable. */
   lpStart  AS DWORD   ' /** Start of memory block, if it is Editable. */
END UNION

' // Size = 12 bytes
TYPE DELTA_INPUT DWORD
   DELTA_INPUT_UNION
   uSize    AS DWORD   ' SIZE_T /** Size of memory block in bytes. */
   Editable AS LONG    ' BOOL   /** TRUE if caller allows msdelta to edit this memory block, FALSE otherwise. */
END TYPE

'/** Type for output memory blocks. */
' // Size = 8 bytes
TYPE DELTA_OUTPUT DWORD
   lpStart AS DWORD   ' LPVOID /** Start of memory block. */
   uSize   AS DWORD   ' SIZE_T /** Size of memory block in bytes. */
END TYPE

'typedef __int64 DELTA_FILE_TYPE;

'/** Raw file type. */
%DELTA_FILE_TYPE_RAW                 = &H00000001&&

'/** File type for I386 Portable Executable files. */
%DELTA_FILE_TYPE_I386                = &H00000002&&

'/** File type for for IA64 Portable Executable files. */
%DELTA_FILE_TYPE_IA64                = &H00000004&&

'/** File type for AMD64 Portable Executable files. */
%DELTA_FILE_TYPE_AMD64               = &H00000008&&


'/** File type set that treats any file as raw. */
%DELTA_FILE_TYPE_SET_RAW_ONLY        = %DELTA_FILE_TYPE_RAW

'/** File type set that distinguishes I386, IA64 and AMD64 Portable Executable file and treats others as raw. */
%DELTA_FILE_TYPE_SET_EXECUTABLES     = %DELTA_FILE_TYPE_RAW OR _
                                       %DELTA_FILE_TYPE_I386 OR _
                                       %DELTA_FILE_TYPE_IA64 OR _
                                       %DELTA_FILE_TYPE_AMD64

'/** Type for msdelta flags. */
'typedef __int64 DELTA_FLAG_TYPE;

'/** No flags. */
%DELTA_FLAG_NONE                     = &H00000000&&

'/** Allow application of legacy PA19 deltas by mspatcha.dll. */
%DELTA_APPLY_FLAG_ALLOW_PA19         = &H00000001&&

'/** Transform E8 pieces (relative calls in x86) of target file . */
%DELTA_FLAG_E8                       = &H00000001&&   ' /* flags[ 0 ] */

'/** Mark non-executable parts of source PE. */
%DELTA_FLAG_MARK                     = &H00000002&&   ' /* flags[ 1 ] */

'/** Transform imports of source PE. */
%DELTA_FLAG_IMPORTS                  = &H00000004&&   ' /* flags[ 2 ] */

'/** Transform exports of source PE. */
%DELTA_FLAG_EXPORTS                  = &H00000008&&   ' /* flags[ 3 ] */

'/** Transform resources of source PE. */
%DELTA_FLAG_RESOURCES                = &H00000010&&   ' /* flags[ 4 ] */

'/** Transform relocations of source PE. */
%DELTA_FLAG_RELOCS                   = &H00000020&&   ' /* flags[ 5 ] */

'/** Smash lock prefixes of source PE. */
%DELTA_FLAG_I386_SMASHLOCK           = &H00000040&&   ' /* flags[ 6 ] */

'/** Transform relative jumps of source I386 (x86) PE. */
%DELTA_FLAG_I386_JMPS                = &H00000080&&   ' /* flags[ 7 ] */

'/** Transform relative calls of source I386 (x86) PE. */
%DELTA_FLAG_I386_CALLS               = &H00000100&&   ' /* flags[ 8 ] */

'/** Transform instructions of source AMD64 (x86-64) PE. */
%DELTA_FLAG_AMD64_DISASM             = &H00000200&&   ' /* flags[ 9 ] */

'/** Transform pdata of source AMD64 (x86-64) PE. */
%DELTA_FLAG_AMD64_PDATA              = &H00000400&&   ' /* flags[ 10 ] */

'/** Transform intstructions of source IA64 (Itanium) PE. */
%DELTA_FLAG_IA64_DISASM              = &H00000800&&   ' /* flags[ 11 ] */

'/** Transform pdata of source IA64 (Itanium) PE. */
%DELTA_FLAG_IA64_PDATA               = &H00001000&&   ' /* flags[ 12 ] */

'/** Unbind source PE. */
%DELTA_FLAG_UNBIND                   = &H00002000&&   ' /* flags[ 13 ] */

'/** Transform CLI instructions of source PE. */
%DELTA_FLAG_CLI_DISASM               = &H00004000&&   ' /* flags[ 14 ] */

'/** Transform CLI Metadata of source PE. */
%DELTA_FLAG_CLI_METADATA             = &H00008000&&   ' /* flags[ 15 ] */

'/** Transform headers of source PE. */
%DELTA_FLAG_HEADERS                  = &H00010000&&   ' /* flags[ 16 ] */

'/** Allow source or target file or buffer to exceed its default size limit. */
%DELTA_FLAG_IGNORE_FILE_SIZE_LIMIT   = &H00020000&&   ' /* flags[ 17 ] */

'/** Allow options buffer or file to exceeed its default size limit. */
%DELTA_FLAG_IGNORE_OPTIONS_SIZE_LIMIT = &H00040000&&   ' /* flags[ 18 ] */

%DELTA_DEFAULT_FLAGS_RAW             = %DELTA_FLAG_NONE

%DELTA_DEFAULT_FLAGS_I386            = %DELTA_FLAG_MARK OR _
                                       %DELTA_FLAG_IMPORTS OR _
                                       %DELTA_FLAG_EXPORTS OR _
                                       %DELTA_FLAG_RESOURCES OR _
                                       %DELTA_FLAG_RELOCS OR _
                                       %DELTA_FLAG_I386_SMASHLOCK OR _
                                       %DELTA_FLAG_I386_JMPS OR _
                                       %DELTA_FLAG_I386_CALLS OR _
                                       %DELTA_FLAG_UNBIND OR _
                                       %DELTA_FLAG_CLI_DISASM OR _
                                       %DELTA_FLAG_CLI_METADATA

%DELTA_DEFAULT_FLAGS_IA64            = %DELTA_FLAG_MARK OR _
                                       %DELTA_FLAG_IMPORTS OR _
                                       %DELTA_FLAG_EXPORTS OR _
                                       %DELTA_FLAG_RESOURCES OR _
                                       %DELTA_FLAG_RELOCS OR _
                                       %DELTA_FLAG_IA64_DISASM OR _
                                       %DELTA_FLAG_IA64_PDATA OR _
                                       %DELTA_FLAG_UNBIND OR _
                                       %DELTA_FLAG_CLI_DISASM OR _
                                       %DELTA_FLAG_CLI_METADATA

%DELTA_DEFAULT_FLAGS_AMD64           = %DELTA_FLAG_MARK OR _
                                       %DELTA_FLAG_IMPORTS OR _
                                       %DELTA_FLAG_EXPORTS OR _
                                       %DELTA_FLAG_RESOURCES OR _
                                       %DELTA_FLAG_RELOCS OR _
                                       %DELTA_FLAG_AMD64_DISASM OR _
                                       %DELTA_FLAG_AMD64_PDATA OR _
                                       %DELTA_FLAG_UNBIND OR _
                                       %DELTA_FLAG_CLI_DISASM OR _
                                       %DELTA_FLAG_CLI_METADATA

'/** Maximal allowed size of hash in bytes. */
%DELTA_MAX_HASH_SIZE                 = 32

'/** Hash structure. */
' // Size = 36 bytes
TYPE DELTA_HASH BYTE
   HashSize AS DWORD                             ' DWORD /** Size of hash in bytes. Does not exceed DELTA_MAX_HASH_SIZE. */
   HashValue(%DELTA_MAX_HASH_SIZE - 1) AS BYTE   ' UCHAR /** Hash value. */
END TYPE

'/** Delta header information. */
' // Size = 80 bytes
TYPE DELTA_HEADER_INFO   ' Must be 8 byte aligned
   FileTypeSet     AS QUAD         ' DELTA_FILE_TYPE /** Used file type set. */
   FileType        AS QUAD         ' DELTA_FILE_TYPE /** Source file type. */
   Flags           AS QUAD         ' DELTA_FLAG_TYPE /** Delta flags. */
   TargetSize      AS DWORD        ' SIZE_T /** Size of target file in bytes. */
   TargetFileTime  AS FILETIME     ' /** Time of target file. */
   TargetHashAlgId AS DWORD        ' ALG_ID /** Algorithm used for hashing. */
   TargetHash      AS DELTA_HASH   ' /** Target hash. */
   alignment__     AS DWORD
END TYPE

'/**
' * Gets header information for a delta in memory.
' * @param Delta         Delta memory block.
' * @param lpHeaderInfo  Header information for given Delta.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaInfoB IMPORT "msdelta.dll" ALIAS "GetDeltaInfoB" ( _
   BYVAL Delta AS DELTA_INPUT _                        ' __in DELTA_INPUT Delta
 , BYREF lpHeaderInfo AS DELTA_HEADER_INFO _           ' __out LPDELTA_HEADER_INFO lpHeaderInfo
 ) AS LONG                                             ' BOOL

'/**
' * Gets header information for a delta accessed by ASCII file name.
' * @param lpDeltaName   Delta file name, ASCII.
' * @param lpHeaderInfo  Header information for given Delta.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaInfoA IMPORT "msdelta.dll" ALIAS "GetDeltaInfoA" ( _
   BYREF lpDeltaName AS ASCIIZ _                       ' __in LPCSTR lpDeltaName
 , BYREF lpHeaderInfo AS DELTA_HEADER_INFO _           ' __out LPDELTA_HEADER_INFO lpHeaderInfo
 ) AS LONG                                             ' BOOL

'/**
' * Gets header information for a delta accessed by Unicode file name.
' * @param lpDeltaName   Delta file name, Unicode.
' * @param lpHeaderInfo  Header information for given Delta.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaInfoW IMPORT "msdelta.dll" ALIAS "GetDeltaInfoW" ( _
   BYREF lpDeltaName AS WSTRINGZ _                     ' __in LPCWSTR lpDeltaName
 , BYREF lpHeaderInfo AS DELTA_HEADER_INFO _           ' __out LPDELTA_HEADER_INFO lpHeaderInfo
 ) AS LONG                                             ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetDeltaInfo = GetDeltaInfoW
#ELSE
   MACRO GetDeltaInfo = GetDeltaInfoA
#ENDIF

'/**
' * Applies a given delta to a given source file.
' * The resultant target file is put into allocated memory.
' * @param ApplyFlags    Apply-specific flags, such as DELTA_APPLY_FLAG_ALLOW_PA19.
' * @param Source        Source memory block.
' * @param Delta         Delta memory block.
' * @param lpTarget      Target memory block. Caller DeltaFree.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION ApplyDeltaB IMPORT "msdelta.dll" ALIAS "ApplyDeltaB" ( _
   BYVAL ApplyFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ApplyFlags
 , BYVAL Source AS DELTA_INPUT _                       ' __in DELTA_INPUT Source
 , BYVAL Delta AS DELTA_INPUT _                        ' __in DELTA_INPUT Delta
 , BYREF lpTarget AS DELTA_OUTPUT _                    ' __out LPDELTA_OUTPUT lpTarget
 ) AS LONG                                             ' BOOL

'/**
' * Applies a given delta to a given source file.
' * The resultant target file is put into caller-provided memory.
' * @param ApplyFlags    Apply-specific flags, such as DELTA_APPLY_FLAG_ALLOW_PA19.
' * @param Source        Source memory block.
' * @param Delta         Delta memory block.
' * @param lpTarget      Pointer to caller-allocated target memory block.
' * @param uTargetSize   Size of target memory block in bytes, caller needs to call GetDeltaInfo to obtain it.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION ApplyDeltaProvidedB IMPORT "msdelta.dll" ALIAS "ApplyDeltaProvidedB" ( _
   BYVAL ApplyFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ApplyFlags
 , BYVAL Source AS DELTA_INPUT _                       ' __in DELTA_INPUT Source
 , BYVAL Delta AS DELTA_INPUT _                        ' __in DELTA_INPUT Delta
 , BYVAL lpTarget AS DWORD _                           ' __inout_bcount( uTargetSize ) LPVOID lpTarget
 , BYVAL uTargetSize AS DWORD _                        ' __in SIZE_T uTargetSize
 ) AS LONG                                             ' BOOL

'/**
' * Applies a given delta to a given source file. The resultant target file is written to disk.
' * All files accessed by ASCII file names.
' * @param ApplyFlags    Apply-specific flags, such as DELTA_APPLY_FLAG_ALLOW_PA19.
' * @param lpSourceName  Source file name, ASCII.
' * @param lpDeltaName   Delta file name, ASCII.
' * @param lpTargetName  Target file name, ASCII.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION ApplyDelta IMPORT "msdelta.dll" ALIAS "ApplyDeltaA" ( _
   BYVAL ApplyFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ApplyFlags
 , BYREF lpSourceName AS ASCIIZ _                      ' __in LPCSTR lpSourceName
 , BYREF lpDeltaName AS ASCIIZ _                       ' __in LPCSTR lpDeltaName
 , BYREF lpTargetName AS ASCIIZ _                      ' __in LPCSTR lpTargetName
 ) AS LONG                                             ' BOOL

'/**
' * Applies a given delta to a given source file. The resultant target file is written to disk.
' * All files accessed by Unicode file names.
' * @param ApplyFlags    Apply-specific flags, such as DELTA_APPLY_FLAG_ALLOW_PA19.
' * @param lpSourceName  Source file name, Unicode.
' * @param lpDeltaName   Delta file name, Unicode.
' * @param lpTargetName  Target file name, Unicode.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION ApplyDeltaW IMPORT "msdelta.dll" ALIAS "ApplyDeltaW" ( _
   BYVAL ApplyFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ApplyFlags
 , BYVAL lpSourceName AS DWORD _                       ' __in LPCWSTR lpSourceName
 , BYVAL lpDeltaName AS DWORD _                        ' __in LPCWSTR lpDeltaName
 , BYVAL lpTargetName AS DWORD _                       ' __in LPCWSTR lpTargetName
 ) AS LONG                                             ' BOOL

'/**
' * Creates a delta from a given source file to a given target file in memory.
' * The resultant delta is put into allocated memory.
' * @param FileTypeSet   File type set.
' * @param SetFlags      Set these flags.
' * @param ResetFlags    Reset (supress) these flags.
' * @param Source        Source memory block.
' * @param Target        Target memory block.
' * @param SourceOptions Memory block with source-specific options.
' * @param TargetOptions Memory block with target-specific options.
' * @param GlobalOptions Memory block with global options.
' * @param lpTargetFileTime  Target file time to use, null to use current time.
' * @param HashAlgId     Algorithm for hashing.
' * @param lpDelta       Result delta memory block.
' * @return              TRUE if sucess, FALSE otherwise.
' */

DECLARE FUNCTION CreateDeltaB IMPORT "msdelta.dll" ALIAS "CreateDeltaB" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL SetFlags AS QUAD _                            ' __in DELTA_FLAG_TYPE SetFlags
 , BYVAL ResetFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ResetFlags
 , BYVAL Source AS DELTA_INPUT _                       ' __in DELTA_INPUT Source
 , BYVAL Target AS DELTA_INPUT _                       ' __in DELTA_INPUT Target
 , BYVAL SourceOptions AS DELTA_INPUT _                ' __in DELTA_INPUT SourceOptions
 , BYVAL TargetOptions AS DELTA_INPUT _                ' __in DELTA_INPUT TargetOptions
 , BYVAL GlobalOptions AS DELTA_INPUT _                ' __in DELTA_INPUT GlobalOptions
 , BYREF lpTargetFileTime AS FILETIME _                ' __in_opt const FILETIME *lpTargetFileTime
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYREF lpDelta AS DELTA_OUTPUT _                     ' __out LPDELTA_OUTPUT lpDelta
 ) AS LONG                                             ' BOOL

'/**
' * Creates a delta from a given source file to a given target file. The resultant delta is written to disk
' * All files accessed by ASCII file names.
' * @param FileTypeSet   File type set.
' * @param SetFlags      Set these flags.
' * @param ResetFlags    Reset (supress) these flags.
' * @param lpSourceName  Source file name, ASCII.
' * @param lpTargetName  Target file name, ASCII.
' * @param lpSourceOptionsName   Name of file with source-specific options, ASCII.
' * @param lpTargetOptionsName   Name of file with target-specific options, ASCII.
' * @param GlobalOptions Memory block with global options.
' * @param lpTargetFileTime  Target file time to use, null to use actual target file time.
' * @param HashAlgId     Algorithm for hashing.
' * @param lpDeltaName   Result delta file name, ASCII.
' * @return              TRUE if sucess, FALSE otherwise.
' */

DECLARE FUNCTION CreateDelta IMPORT "msdelta.dll" ALIAS "CreateDeltaA" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL SetFlags AS QUAD _                            ' __in DELTA_FLAG_TYPE SetFlags
 , BYVAL ResetFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ResetFlags
 , BYREF lpSourceName AS ASCIIZ _                      ' __in LPCSTR lpSourceName
 , BYREF lpTargetName AS ASCIIZ _                      ' __in LPCSTR lpTargetName
 , BYREF lpSourceOptionsName AS ASCIIZ _               ' __in_opt LPCSTR lpSourceOptionsName
 , BYREF lpTargetOptionsName AS ASCIIZ _               ' __in_opt LPCSTR lpTargetOptionsName
 , BYVAL GlobalOptions AS DELTA_INPUT _                ' __in DELTA_INPUT GlobalOptions
 , BYREF lpTargetFileTime AS FILETIME _                ' __in_opt const FILETIME *lpTargetFileTime
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYREF lpDeltaName AS ASCIIZ _                       ' __in LPCSTR lpDeltaName
 ) AS LONG                                             ' BOOL

'/**
' * Creates a delta from a given source file to a given target file. The resultant delta is written to disk
' * All files accessed by Unicode file names.
' * @param FileTypeSet  File type set.
' * @param SetFlags      Set these flags.
' * @param ResetFlags    Reset (supress) these flags.
' * @param lpSourceName  Source file name, Unicode.
' * @param lpTargetName  Target file name, Unicode.
' * @param lpSourceOptionsName   Name of file with source-specific options, Unicode.
' * @param lpTargetOptionsName   Name of file with target-specific options, Unicode.
' * @param GlobalOptions Memory block with global options.
' * @param lpTargetFileTime  Target file time to use, null to use actual target file time.
' * @param HashAlgId     Algorithm for hashing.
' * @param lpDeltaName   Result delta file name, Unicode.
' * @return              TRUE if sucess, FALSE otherwise.
' */

DECLARE FUNCTION CreateDeltaW IMPORT "msdelta.dll" ALIAS "CreateDeltaW" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL SetFlags AS QUAD _                            ' __in DELTA_FLAG_TYPE SetFlags
 , BYVAL ResetFlags AS QUAD _                          ' __in DELTA_FLAG_TYPE ResetFlags
 , BYVAL lpSourceName AS DWORD _                       ' __in LPCWSTR lpSourceName
 , BYVAL lpTargetName AS DWORD _                       ' __in LPCWSTR lpTargetName
 , BYVAL lpSourceOptionsName AS DWORD _                ' __in_opt LPCWSTR lpSourceOptionsName
 , BYVAL lpTargetOptionsName AS DWORD _                ' __in_opt LPCWSTR lpTargetOptionsName
 , BYVAL GlobalOptions AS DELTA_INPUT _                ' __in DELTA_INPUT GlobalOptions
 , BYREF lpTargetFileTime AS FILETIME _                ' __in_opt const FILETIME *lpTargetFileTime
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYVAL lpDeltaName AS DWORD _                        ' __in LPCWSTR lpDeltaName
 ) AS LONG                                             ' BOOL

'/**
' * Calculates a hash for normalized source file in memory.
' * Normalization is based on source file type,
' * which is determined automatically according to the given file type set.
' * @param FileTypeSet   File type set.
' * @param HashAlgId     Algorithm for hashing.
' * @param Source        Source memory block.
' * @param lpHash        Result hash.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaSignatureB IMPORT "msdelta.dll" ALIAS "GetDeltaSignatureB" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYVAL Source AS DELTA_INPUT _                       ' __in DELTA_INPUT Source
 , BYREF lpHash AS DELTA_HASH _                        ' __out LPDELTA_HASH lpHash
 ) AS LONG                                             ' BOOL

'/**
' * Calculates a hash for normalized source file accessed by ASCII file name.
' * Normalization is based on source file type,
' * which is determined automatically according to the given file type set.
' * @param FileTypeSet   File type set.
' * @param HashAlgId     Algorithm for hashing.
' * @param lpSourceName  Source file name, ASCII.
' * @param lpHash        Result hash.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaSignature IMPORT "msdelta.dll" ALIAS "GetDeltaSignatureA" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYREF lpSourceName AS ASCIIZ _                      ' __in LPCSTR lpSourceName
 , BYREF lpHash AS DELTA_HASH _                        ' __out LPDELTA_HASH lpHash
 ) AS LONG                                             ' BOOL

'/**
' * Calculates a hash for normalized source file accessed by Unicode file name.
' * Normalization is based on source file type,
' * which is determined automatically according to the given file type set.
' * @param FileTypeSet   File type set.
' * @param HashAlgId     Algorithm for hashing.
' * @param lpSourceName  Source file name, Unicode.
' * @param lpHash        Result hash.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION GetDeltaSignatureW IMPORT "msdelta.dll" ALIAS "GetDeltaSignatureW" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL HashAlgId AS DWORD _                          ' __in ALG_ID HashAlgId
 , BYVAL lpSourceName AS DWORD _                       ' __in LPCWSTR lpSourceName
 , BYREF lpHash AS DELTA_HASH _                        ' __out LPDELTA_HASH lpHash
 ) AS LONG                                             ' BOOL

'/**
' * Normalizes source buffer, normalization is  based on source file type, which is
' * determined automatically according to the given file type set.
' * @param FileTypeSet   File type set.
' * @param NormalizeFlags    Normalization flags.
' * @param NormalizeOptions  Normalization options.
' * @param lpSource      Pointer to source buffer.
' * @param uSourceSize   Size of source buffer in bytes.
' * @return              TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION DeltaNormalizeProvidedB IMPORT "msdelta.dll" ALIAS "DeltaNormalizeProvidedB" ( _
   BYVAL FileTypeSet AS QUAD _                         ' __in DELTA_FILE_TYPE FileTypeSet
 , BYVAL NormalizeFlags AS QUAD _                      ' __in DELTA_FLAG_TYPE NormalizeFlags
 , BYVAL NormalizeOptions AS DELTA_INPUT _             ' __in DELTA_INPUT NormalizeOptions
 , BYVAL lpSource AS DWORD _                           ' __inout_bcount( uSourceSize ) LPVOID lpSource
 , BYVAL uSourceSize AS DWORD _                        ' __in SIZE_T uSourceSize
 ) AS LONG                                             ' BOOL

'/**
' * Frees memory block allocated by msdelta.
' * @param lpMemory Pointer to memory block, previously allocated by msdelta.
' * @return TRUE if success, FALSE otherwise.
' */

DECLARE FUNCTION DeltaFree IMPORT "msdelta.dll" ALIAS "DeltaFree" ( _
   BYVAL lpMemory AS DWORD _                           ' __in LPVOID lpMemory
 ) AS LONG                                             ' BOOL
