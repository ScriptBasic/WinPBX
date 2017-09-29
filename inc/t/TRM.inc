' ########################################################################################
' File: TRM.INC
' Contents: Include file for the Tsunami Record Manager (TRM.DLL), version 2.5
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TRM_INC = 1

%CASE_SENSITIVE = 1
%NO_DUPLICATES  = 2
%NO_COMPRESSION = 4
%BINARY_KEY     = 8

%KEY_ONLY       = 4096
%REBUILD_IDS    = 2

' ========================================================================================
' Error codes
' ========================================================================================

%TRM_SUCCESSFUL     = 0      ' // No error
%TRM_NOTTSUNAMIFILE = 1      ' // Not a Tsunami file
%TRM_IOERROR        = 2      ' // I/O error
%TRM_FILENOTOPEN    = 3      ' // File not open
%TRM_KEYNOTFOUND    = 4      ' // Key not found
%TRM_DUPLICATEKEY   = 5      ' // Duplicate key
%TRM_INVALIDKEY     = 6      ' // Invalid key
%TRM_FILECORRUPT    = 7      ' // File corrupt
%TRM_NOCURRENTPOS   = 8      ' // No current position
%TRM_ENDOFFILE      = 9      ' // End of file
%TRM_INVPAGESIZE    = 10     ' // Invalid page size
%TRM_INVNOKEYSEGS   = 11     ' // Invalid number of key segments
%TRM_INVFILEDEFSTR  = 12     ' // Invalid file definition string
%TRM_INVKEYSEGPOS   = 13     ' // Invalid key segment position
%TRM_INVKEYSEGLEN   = 14     ' // Invalid key segment length
%TRM_INCKEYSEGDEF   = 15     ' // Inconsistent key segment definitions
%TRM_INVRECORDLEN   = 20     ' // Invalid record length
%TRM_INVRECORDADDR  = 21     ' // Invalid record address
%TRM_LOSTRECORDPOS  = 22     ' // Lost record position
%TRM_ACCESSDENIED   = 30     ' // Access denied
%TRM_FILEEXISTS     = 31     ' // File already exists
%TRM_NOMOREFILEHDLS = 32     ' // No more file handles
%TRM_MAXFILESOPEN   = 33     ' // Maximum files opened
%TRM_ACCELACCDENIED = 40     ' // Acceleration access denied
%TRM_ACCELCACHEERR  = 41     ' // Acceration cache error
%TRM_ACCESSFILEDEN  = 46     ' // Access to file denied
%TRM_DATABUFTOSMALL = 50     ' // Data buffer too small
%TRM_TIMEOUT        = 99     ' // Timeout

' ========================================================================================
' Tsunami 2.5 offers three APIs: A string-based API and two pointer-based APIs.
' The following 38 declarations represent the string-based API...
' ========================================================================================

DECLARE FUNCTION trm_Accelerate        IMPORT "TRM.DLL" ALIAS "trm_Accelerate"        (FileHandle AS LONG, CacheSize AS LONG) AS LONG
DECLARE FUNCTION trm_Close             IMPORT "TRM.DLL" ALIAS "trm_Close"             (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_CloseAll          IMPORT "TRM.DLL" ALIAS "trm_CloseAll"          () AS LONG
DECLARE FUNCTION trm_Count             IMPORT "TRM.DLL" ALIAS "trm_Count"             (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_Create            IMPORT "TRM.DLL" ALIAS "trm_Create"            (PathFileName AS STRING, FileDef AS STRING, OverWrite AS LONG) AS LONG
DECLARE FUNCTION trm_CurrKeyPos        IMPORT "TRM.DLL" ALIAS "trm_CurrKeyPos"        (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_Delete            IMPORT "TRM.DLL" ALIAS "trm_Delete"            (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_FileIsOpen        IMPORT "TRM.DLL" ALIAS "trm_FileIsOpen"        (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_FileSize          IMPORT "TRM.DLL" ALIAS "trm_FileSize"          (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_Flush             IMPORT "TRM.DLL" ALIAS "trm_Flush"             () AS LONG
DECLARE FUNCTION trm_GetByKeyPos       IMPORT "TRM.DLL" ALIAS "trm_GetByKeyPos"       (FileHandle AS LONG, KeyPos AS LONG) AS STRING
DECLARE FUNCTION trm_GetDirect         IMPORT "TRM.DLL" ALIAS "trm_GetDirect"         (FileHandle AS LONG, RecordPtr AS STRING) AS STRING
DECLARE FUNCTION trm_GetEqual          IMPORT "TRM.DLL" ALIAS "trm_GetEqual"          (FileHandle AS LONG, KeyNo AS LONG, KeyVal AS STRING) AS STRING
DECLARE FUNCTION trm_GetEqualOrGreater IMPORT "TRM.DLL" ALIAS "trm_GetEqualOrGreater" (FileHandle AS LONG, KeyNo AS LONG, KeyVal AS STRING) AS STRING
DECLARE FUNCTION trm_GetEqualOrLess    IMPORT "TRM.DLL" ALIAS "trm_GetEqualOrLess"    (FileHandle AS LONG, KeyNo AS LONG, KeyVal AS STRING) AS STRING
DECLARE FUNCTION trm_GetFileDef        IMPORT "TRM.DLL" ALIAS "trm_GetFileDef"        (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_GetFileVer        IMPORT "TRM.DLL" ALIAS "trm_GetFileVer"        (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_GetFirst          IMPORT "TRM.DLL" ALIAS "trm_GetFirst"          (FileHandle AS LONG, KeyNo AS LONG) AS STRING
DECLARE FUNCTION trm_GetGreater        IMPORT "TRM.DLL" ALIAS "trm_GetGreater"        (FileHandle AS LONG, KeyNo AS LONG, KeyVal AS STRING) AS STRING
DECLARE FUNCTION trm_GetLast           IMPORT "TRM.DLL" ALIAS "trm_GetLast"           (FileHandle AS LONG, KeyNo AS LONG) AS STRING
DECLARE FUNCTION trm_GetLess           IMPORT "TRM.DLL" ALIAS "trm_GetLess"           (FileHandle AS LONG, KeyNo AS LONG, KeyVal AS STRING) AS STRING
DECLARE FUNCTION trm_GetNext           IMPORT "TRM.DLL" ALIAS "trm_GetNext"           (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_GetPosition       IMPORT "TRM.DLL" ALIAS "trm_GetPosition"       (FileHandle AS LONG, Direction AS LONG) AS STRING
DECLARE FUNCTION trm_GetPrev           IMPORT "TRM.DLL" ALIAS "trm_GetPrev"           (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_Insert            IMPORT "TRM.DLL" ALIAS "trm_Insert"            (FileHandle AS LONG, Record AS STRING) AS LONG
DECLARE FUNCTION trm_Integrity         IMPORT "TRM.DLL" ALIAS "trm_Integrity"         (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_Open              IMPORT "TRM.DLL" ALIAS "trm_Open"              (PathFileName AS STRING, MultiUser AS LONG) AS LONG
DECLARE FUNCTION trm_Rebuild           IMPORT "TRM.DLL" ALIAS "trm_Rebuild"           (PathFileName AS STRING, SaveFile AS STRING, FileDef AS STRING) AS LONG
DECLARE FUNCTION trm_Recover           IMPORT "TRM.DLL" ALIAS "trm_Recover"           (PathFileName AS STRING, OutFile AS STRING, PageSize AS LONG, Compression AS LONG) AS LONG
DECLARE FUNCTION trm_Result            IMPORT "TRM.DLL" ALIAS "trm_Result"            (FileHandle AS LONG) AS LONG
DECLARE FUNCTION trm_SetKeyPath        IMPORT "TRM.DLL" ALIAS "trm_SetKeyPath"        (FileHandle AS LONG, KeyNo AS LONG) AS LONG
DECLARE FUNCTION trm_StepFirst         IMPORT "TRM.DLL" ALIAS "trm_StepFirst"         (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_StepLast          IMPORT "TRM.DLL" ALIAS "trm_StepLast"          (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_StepNext          IMPORT "TRM.DLL" ALIAS "trm_StepNext"          (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_StepPrev          IMPORT "TRM.DLL" ALIAS "trm_StepPrev"          (FileHandle AS LONG) AS STRING
DECLARE FUNCTION trm_TimeOut           IMPORT "TRM.DLL" ALIAS "trm_TimeOut"           (Limit AS LONG) AS LONG
DECLARE FUNCTION trm_Update            IMPORT "TRM.DLL" ALIAS "trm_Update"            (FileHandle AS LONG, Record AS STRING) AS LONG
DECLARE FUNCTION trm_Version           IMPORT "TRM.DLL" ALIAS "trm_Version"           () AS LONG

' The following two declarations represent Tsunami's two pointer-based APIs.

' They both accomplish the same thing... one passes seven long integers as parameters,
' while the other passes a seven-element UDT (structured variable) as it's sole parameter.

DECLARE FUNCTION trm     IMPORT "TRM.DLL" ALIAS "trm"     (Op AS LONG, File AS LONG, DataPtr AS LONG, DataLen AS LONG, KeyPtr AS LONG, KeyLen AS LONG, KeyNo AS LONG) AS LONG

DECLARE FUNCTION trm_udt IMPORT "TRM.DLL" ALIAS "trm_udt" (TRMudt AS ANY) AS LONG

' The following User Defined Type (structured) variable is only used
' with the pointer-based API that passes parameters in the UDT...

TYPE TRMtype
   op      AS LONG  ' Tsunami operation number
   file    AS LONG  ' Tsunami file handle
   dataptr AS LONG  ' Address of data buffer
   datalen AS LONG  ' Length of data buffer
   keyptr  AS LONG  ' Address of key buffer
   keylen  AS LONG  ' Length of key buffer
   keyno   AS LONG  ' Key number
END TYPE

' The following EQUATES (constants) represent the Tsunami
' operation codes (Op) used with the pointer-based APIs...

%Tsu_Accelerate        = 32
%Tsu_Close             =  1
%Tsu_CloseAll          = 28
%Tsu_Count             = 17
%Tsu_Create            = 14
%Tsu_CurrKeyPos        = 45
%Tsu_Delete            =  4
%Tsu_FileIsOpen        = 16
%Tsu_FileSize          = 18
%Tsu_Flush             = 29
%Tsu_GetByKeyPos       = 44
%Tsu_GetDirect         = 23
%Tsu_GetEqual          =  5
%Tsu_GetEqualOrGreater =  9
%Tsu_GetEqualOrLess    = 11
%Tsu_GetFileDef        = 36
%Tsu_GetFileVer        = 25
%Tsu_GetFirst          = 12
%Tsu_GetGreater        =  8
%Tsu_GetLast           = 13
%Tsu_GetLess           = 10
%Tsu_GetNext           =  6
%Tsu_GetPosition       = 22
%Tsu_GetPrev           =  7
%Tsu_Insert            =  2
%Tsu_Integrity         = 37
%Tsu_Open              =  0
%Tsu_Rebuild           = 38
%Tsu_Recover           = 39
%Tsu_SetKeyPath        = 30
%Tsu_StepFirst         = 33
%Tsu_StepLast          = 34
%Tsu_StepNext          = 24
%Tsu_StepPrev          = 35
%Tsu_TimeOut           = 31
%Tsu_Update            =  3
%Tsu_Version           = 26
