' ########################################################################################
' Microsoft Windows
' File: VerError.inc
' Contents: Definitions of data structures, needed to report verifier errors
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VERERROR_INC = 1

'#ifndef _VER_RAW_STRUCT_FOR_IDL_
'#ifndef _JIT64_PEV_
'#include "corhdr.h"
'#include "openum.h"
'#include "corerror.h"
'#endif ' // !_JIT64_PEV_

' // Set these flags if the error info fields are valid.

%VER_ERR_FATAL       = &H80000000&   ' // Cannot Continue
%VER_ERR_OFFSET      = &H00000001&
%VER_ERR_OPCODE      = &H00000002&
%VER_ERR_OPERAND     = &H00000004&
%VER_ERR_TOKEN       = &H00000008&
%VER_ERR_EXCEP_NUM_1 = &H00000010&
%VER_ERR_EXCEP_NUM_2 = &H00000020&
%VER_ERR_STACK_SLOT  = &H00000040&
%VER_ERR_ITEM_1      = &H00000080&
%VER_ERR_ITEM_2      = &H00000100&
%VER_ERR_ITEM_F      = &H00000200&
%VER_ERR_ITEM_E      = &H00000400&
%VER_ERR_TYPE_1      = &H00000800&
%VER_ERR_TYPE_2      = &H00001000&
%VER_ERR_TYPE_F      = &H00002000&
%VER_ERR_TYPE_E      = &H00004000&
%VER_ERR_ADDL_MSG    = &H00008000&

%VER_ERR_SIG_MASK    = &H07000000&   ' // Enum
%VER_ERR_METHOD_SIG  = &H01000000&
%VER_ERR_LOCAL_SIG   = &H02000000&
%VER_ERR_FIELD_SIG   = &H03000000&
%VER_ERR_CALL_SIG    = &H04000000&

%VER_ERR_OPCODE_OFFSET = %VER_ERR_OPCODE OR %VER_ERR_OFFSET

%VER_ERR_LOCAL_VAR   = %VER_ERR_LOCAL_SIG
%VER_ERR_ARGUMENT    = %VER_ERR_METHOD_SIG

%VER_ERR_ARG_RET     = &HFFFFFFFE&       ' // The Argument # is return
%VER_ERR_NO_ARG      = &HFFFFFFFF&       ' // Argument # is not valid
%VER_ERR_NO_LOC      = %VER_ERR_NO_ARG   ' // Local # is not valid

' // Size = 8 bytes
TYPE VerItem DWORD
   dwFlags AS DWORD      ' DWORD // BYREF / BOXED etc.. see veritem.hpp
   pv      AS DWORD PTR  ' void* // TypeHandle / MethodDesc * etc.
END TYPE

' // This structure is used to fully define a verification error.
' // Verification error codes are found in CorError.h
' // The error resource strings are found in src/dlls/mscorrc/mscor.rc

'typedef struct VerErrorStruct
'{
'   DWORD   dwFlags;            ' // VER_ERR_XXX

'    union {
'#ifndef _JIT64_PEV_
'        OPCODE  opcode;
'#endif ' // !_JIT64_PEV_
'        unsigned long padding1; ' // to match with idl generated struct size
'    };

'    union {
'        DWORD   dwOffset;       ' // #of bytes from start of method
'        long    uOffset;        ' // for backward compat with Metadata validator
'    };

'    union {
'        mdToken         token;
'        mdToken         Token;  ' // for backward compat with metadata validator
'        BYTE           bCallConv;
'        CorElementType  elem;
'        DWORD           dwStackSlot; ' // positon in the Stack
'        unsigned long   padding2;    ' // to match with idl generated struct size
'    };

'    union {
'        _VerItem sItem1;
'        _VerItem sItemFound;
'        WCHAR* wszType1;
'        WCHAR* wszTypeFound;
'        DWORD dwException1;      ' // Exception Record #
'        DWORD dwVarNumber;       ' // Variable #
'        DWORD dwArgNumber;       ' // Argument #
'        DWORD dwOperand;        ' // Operand for the opcode
'        WCHAR* wszAdditionalMessage; ' // message from getlasterror
'    };

'    union {
'        _VerItem sItem2;
'        _VerItem sItemExpected;
'        WCHAR* wszType2;
'        WCHAR* wszTypeExpected;
'        DWORD dwException2;           ' // Exception Record #
'    };

'} VerError;

'#else

' // Assert that sizeof(_VerError) == sizeof(VerError) in Verifier.cpp
'typedef struct tag_VerError
'{
'    unsigned long flags;            ' // DWORD
'    unsigned long opcode;           ' // OPCODE, padded to ulong
'    unsigned long uOffset;          ' // DWORD
'    unsigned long Token;            ' // mdToken
'    unsigned long item1_flags;      ' // _VerItem.DWORD
'    int           *item1_data;      ' // _VerItem.PVOID
'    unsigned long item2_flags;      ' // _VerItem.DWORD
'    int           *item2_data;      ' // _VerItem.PVOID
'}  _VerError;
'#endif

' // Size = 32 bytes
TYPE VerError DWORD
   Flags       AS DWORD        ' // DWORD
   opcode      AS DWORD        ' // OPCODE, padded to ulong
   uOffset     AS DWORD        ' // DWORD
   Token       AS DWORD        ' // mdToken
   item1_flags AS DWORD        ' // _VerItem.DWORD
   item1_data  AS DWORD PTR    ' // _VerItem.PVOID
   item2_flags AS DWORD        ' // _VerItem.DWORD
   item2_data  AS DWORD PTR    ' // _VerItem.PVOID
END TYPE
