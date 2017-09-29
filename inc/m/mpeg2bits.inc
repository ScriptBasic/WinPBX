' ########################################################################################
' Microsoft Windows
' File: Mpeg2Bits.inc
' Contents: This file defines the MPEG-2 section header bitfields
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEG2BITS_INC = 1

'#pragma once

'#pragma pack(push)
'#pragma pack(1)


'//
'// PID structure
'//

'#ifdef __midl

'typedef struct
'{
'    WORD Bits;
'} PID_BITS_MIDL;

'#else

'typedef struct
'{
'    WORD Reserved  :  3;
'    WORD ProgramId : 13;
'} PID_BITS, *PPID_BITS;

'#endif

' // Size = 2 bytes
TYPE PID_BITS BYTE
   Reserved  AS BIT * 3  IN WORD
   ProgramId AS BIT * 13
END TYPE


'//
'// Generic MPEG packet header structure
'//

'#ifdef __midl

'typedef struct
'{
'    WORD Bits;
'} MPEG_HEADER_BITS_MIDL;

'#else

'typedef struct
'{
'    WORD SectionLength          : 12;
'    WORD Reserved               :  2;
'    WORD PrivateIndicator       :  1;
'    WORD SectionSyntaxIndicator :  1;
'} MPEG_HEADER_BITS, *PMPEG_HEADER_BITS;

'#endif

' // Size = 2 bytes
TYPE MPEG_HEADER_BITS BYTE
   SectionLength          AS BIT * 12 IN WORD
   Reserved               AS BIT * 2
   PrivateIndicator       AS BIT * 1
   SectionSyntaxIndicator AS BIT * 1
END TYPE


'//
'// Long MPEG packet header structure
'//

'#ifdef __midl

'typedef struct
'{
'    BYTE Bits;
'} MPEG_HEADER_VERSION_BITS_MIDL;

'#else

'typedef struct
'{
'    BYTE CurrentNextIndicator : 1;
'    BYTE VersionNumber        : 5;
'    BYTE Reserved             : 2;
'} MPEG_HEADER_VERSION_BITS, *PMPEG_HEADER_VERSION_BITS;

'#endif

' // Size = 1 byte
TYPE MPEG_HEADER_VERSION_BITS BYTE
   CurrentNextIndicator AS BIT * 1 IN BYTE
   VersionNumber        AS BIT * 5
   Reserved             AS BIT * 2
END TYPE

'#pragma pack(pop)
