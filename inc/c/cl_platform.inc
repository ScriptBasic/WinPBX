'/**********************************************************************************
' * Copyright (c) 2008-2009 The Khronos Group Inc.
' *
' * Permission is hereby granted, free of charge, to any person obtaining a
' * copy of this software and/or associated documentation files (the
' * "Materials"), to deal in the Materials without restriction, including
' * without limitation the rights to use, copy, modify, merge, publish,
' * distribute, sublicense, and/or sell copies of the Materials, and to
' * permit persons to whom the Materials are furnished to do so, subject to
' * the following conditions:
' *
' * The above copyright notice and this permission notice shall be included
' * in all copies or substantial portions of the Materials.
' *
' * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
' * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
' * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
' * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
' * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
' * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
' * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
' **********************************************************************************/

'/* $Revision: 9283 $ on $Date: 2009-10-14 10:18:57 -0700 (Wed, 14 Oct 2009) $ */

#INCLUDE THIS ONCE
%CL_PLATFORM_INC = 1

%CL_API_SUFFIX__VERSION_1_0 = 1
%CL_EXTENSION_WEAK_LINK = 1

'#if (defined (WIN32) && (_MSC_VER))

'/* scalar types  */
'typedef signed   __int8         cl_char;
'typedef unsigned __int8         cl_uchar;
'typedef signed   __int16        cl_short;
'typedef unsigned __int16        cl_ushort;
'typedef signed   __int32        cl_int;
'typedef unsigned __int32        cl_uint;
'typedef signed   __int64        cl_long;
'typedef unsigned __int64        cl_ulong;

'typedef unsigned __int16        cl_half;
'typedef float                   cl_float;
'typedef double                  cl_double;


'/*
' * Vector types
' *
' *  Note:   OpenCL requires that all types be naturally aligned.
' *          This means that vector types must be naturally aligned.
' *          For example, a vector of four floats must be aligned to
' *          a 16 byte boundary (calculated as 4 * the natural 4-byte
' *          alignment of the float).  The alignment qualifiers here
' *          will only function properly if your compiler supports them
' *          and if you don't actively work to defeat them.  For example,
' *          in order for a cl_float4 to be 16 byte aligned in a struct,
' *          the start of the struct must itself be 16-byte aligned.
' *
' *          Maintaining proper alignment is the user's responsibility.
' */
'typedef signed   __int8         cl_char2[2];
'typedef signed   __int8         cl_char4[4];
'typedef signed   __int8         cl_char8[8];
'typedef signed   __int8         cl_char16[16];
'typedef unsigned __int8         cl_uchar2[2];
'typedef unsigned __int8         cl_uchar4[4];
'typedef unsigned __int8         cl_uchar8[8];
'typedef unsigned __int8         cl_uchar16[16];

'typedef signed   __int16        cl_short2[2];
'typedef signed   __int16        cl_short4[4];
'typedef signed   __int16        cl_short8[8];
'typedef signed   __int16        cl_short16[16];
'typedef unsigned __int16        cl_ushort2[2];
'typedef unsigned __int16        cl_ushort4[4];
'typedef unsigned __int16        cl_ushort8[8];
'typedef unsigned __int16        cl_ushort16[16];

'typedef signed   __int32        cl_int2[2];
'typedef signed   __int32        cl_int4[4];
'typedef signed   __int32        cl_int8[8];
'typedef signed   __int32        cl_int16[16];
'typedef unsigned __int32        cl_uint2[2];
'typedef unsigned __int32        cl_uint4[4];
'typedef unsigned __int32        cl_uint8[8];
'typedef unsigned __int32        cl_uint16[16];

'typedef signed   __int64        cl_long2[2];
'typedef signed   __int64        cl_long4[4];
'typedef signed   __int64        cl_long8[8];
'typedef signed   __int64        cl_long16[16];
'typedef unsigned __int64        cl_ulong2[2];
'typedef unsigned __int64        cl_ulong4[4];
'typedef unsigned __int64        cl_ulong8[8];
'typedef unsigned __int64        cl_ulong16[16];

'typedef float                   cl_float2[2];
'typedef float                   cl_float4[4];
'typedef float                   cl_float8[8];
'typedef float                   cl_float16[16];

'typedef double                  cl_double2[2];
'typedef double                  cl_double4[4];
'typedef double                  cl_double8[8];
'typedef double                  cl_double16[16];
'/* There are no vector types for half */

' PB doesn't support signed bytes
'typedef signed   __int8         cl_char2[2];
'typedef signed   __int8         cl_char4[4];
'typedef signed   __int8         cl_char8[8];
'typedef signed   __int8         cl_char16[16];

'typedef unsigned __int8         cl_uchar2[2];
' // Size = 2 bytes
TYPE cl_uchar2 BYTE
   b (0 TO 1) AS BYTE
END TYPE

'typedef unsigned __int8         cl_uchar4[4];
' // Size = 2 bytes
TYPE cl_uchar4 BYTE
   b (0 TO 3) AS BYTE
END TYPE

'typedef unsigned __int8         cl_uchar8[8];
' // Size = 2 bytes
TYPE cl_uchar8 BYTE
   b (0 TO 7) AS BYTE
END TYPE

'typedef unsigned __int8         cl_uchar16[16];
' // Size = 16 bytes
TYPE cl_uchar16
   b (0 TO 15) AS BYTE
END TYPE

'typedef signed   __int16        cl_short2[2];
' // Size = 4 bytes
TYPE cl_short2 BYTE
   i (0 TO 1) AS INTEGER
END TYPE

'typedef signed   __int16        cl_short4[4];
' // Size = 8 bytes
TYPE cl_short4 BYTE
   i (0 TO 3) AS INTEGER
END TYPE

'typedef signed   __int16        cl_short8[8];
' // Size = 16 bytes
TYPE cl_short8 BYTE
   i (0 TO 7) AS INTEGER
END TYPE

'typedef signed   __int16        cl_short16[16];
' // Size = 32 bytes
TYPE cl_short16 BYTE
   i (0 TO 15) AS INTEGER
END TYPE

'typedef unsigned __int16        cl_ushort2[2];
' // Size = 4 bytes
TYPE cl_ushort2 BYTE
   w (0 TO 1) AS WORD
END TYPE

'typedef unsigned __int16        cl_ushort4[4];
' // Size = 4 bytes
TYPE cl_ushort4 BYTE
   w (0 TO 3) AS WORD
END TYPE

'typedef unsigned __int16        cl_ushort8[8];
' // Size = 16 bytes
TYPE cl_ushort8 BYTE
   w (0 TO 7) AS WORD
END TYPE

'typedef unsigned __int16        cl_ushort16[16];
' // Size = 32 bytes
TYPE cl_ushort16 BYTE
   w (0 TO 15) AS WORD
END TYPE

'typedef signed   __int32        cl_int2[2];
' // Size = 8 bytes
TYPE cl_int2 BYTE
   l (0 TO 1) AS LONG
END TYPE

'typedef signed   __int32        cl_int4[4];
' // Size = 16 bytes
TYPE cl_int4 BYTE
   l (0 TO 3) AS LONG
END TYPE

'typedef signed   __int32        cl_int8[8];
' // Size = 32 bytes
TYPE cl_int8 BYTE
   l (0 TO 7) AS LONG
END TYPE

'typedef signed   __int32        cl_int16[16];
' // Size = 64 bytes
TYPE cl_int16 BYTE
   l (0 TO 15) AS LONG
END TYPE

'typedef unsigned __int32        cl_uint2[2];
' // Size = 8 bytes
TYPE cl_uint2 BYTE
   dw (0 TO 1) AS DWORD
END TYPE

'typedef unsigned __int32        cl_uint4[4];
' // Size = 16 bytes
TYPE cl_uint4 BYTE
   dw (0 TO 3) AS DWORD
END TYPE

'typedef unsigned __int32        cl_uint8[8];
' // Size = 32 bytes
TYPE cl_uint8 BYTE
   dw (0 TO 7) AS DWORD
END TYPE

'typedef unsigned __int32        cl_uint16[16];
' // Size = 64 bytes
TYPE cl_uint16 BYTE
   dw (0 TO 15) AS DWORD
END TYPE

'typedef signed   __int64        cl_long2[2];
' // Size = 16 bytes
TYPE cl_long2 BYTE
   q (0 TO 1) AS QUAD
END TYPE

'typedef signed   __int64        cl_long4[4];
' // Size = 32 bytes
TYPE cl_long4 BYTE
   q (0 TO 3) AS QUAD
END TYPE

'typedef signed   __int64        cl_long8[8];
' // Size = 64 bytes
TYPE cl_long8 BYTE
   q (0 TO 7) AS QUAD
END TYPE

'typedef signed   __int64        cl_long16[16];
' // Size = 128 bytes
TYPE cl_long16 BYTE
   q (0 TO 15) AS QUAD
END TYPE

' PB doesn't support unsigned quads
'typedef unsigned __int64        cl_ulong2[2];
'typedef unsigned __int64        cl_ulong4[4];
'typedef unsigned __int64        cl_ulong8[8];
'typedef unsigned __int64        cl_ulong16[16];

'typedef float                   cl_float2[2];
' // Size = 8 bytes
TYPE cl_float2 BYTE
   s (0 TO 1) AS SINGLE
END TYPE

'typedef float                   cl_float4[4];
' // Size = 16 bytes
TYPE cl_float4 BYTE
   s (0 TO 3) AS SINGLE
END TYPE

'typedef float                   cl_float8[8];
' // Size = 32 bytes
TYPE cl_float8 BYTE
   s (0 TO 7) AS SINGLE
END TYPE

'typedef float                   cl_float16[16];
' // Size = 64 bytes
TYPE cl_float16 BYTE
   s (0 TO 15) AS SINGLE
END TYPE

'typedef double                  cl_double2[2];
' // Size = 16 bytes
TYPE cl_double2 BYTE
   d (0 TO 1) AS DOUBLE
END TYPE

'typedef double                  cl_double4[4];
' // Size = 32 bytes
TYPE cl_double4 BYTE
   d (0 TO 3) AS DOUBLE
END TYPE

'typedef double                  cl_double8[8];
' // Size = 64 bytes
TYPE cl_double8 BYTE
   d (0 TO 7) AS DOUBLE
END TYPE

'typedef double                  cl_double16[16];
' // Size = 128 bytes
TYPE cl_double16 BYTE
   d (0 TO 15) AS DOUBLE
END TYPE

%CL_CHAR_BIT         = 8
%CL_SCHAR_MAX        = 127
%CL_SCHAR_MIN        = (-127-1)
%CL_CHAR_MAX         = %CL_SCHAR_MAX
%CL_CHAR_MIN         = %CL_SCHAR_MIN
%CL_UCHAR_MAX        = 255
%CL_SHRT_MAX         = 32767
%CL_SHRT_MIN         = (-32767-1)
%CL_USHRT_MAX        = 65535
%CL_INT_MAX          = 2147483647
%CL_INT_MIN          = (-2147483647-1)
%CL_UINT_MAX         = &Hffffffff???
%CL_LONG_MAX         = &H7FFFFFFFFFFFFFFF&&         ' ((cl_long) 0x7FFFFFFFFFFFFFFFLL)
%CL_LONG_MIN         = &H7FFFFFFFFFFFFFFF&& - 1&&   ' ((cl_long) -0x7FFFFFFFFFFFFFFFLL - 1LL)
' PB doesn't support unsigned quads
'#define CL_ULONG_MAX        ((cl_ulong) 0xFFFFFFFFFFFFFFFFULL)

%CL_FLT_DIG          = 6
%CL_FLT_MANT_DIG     = 24
%CL_FLT_MAX_10_EXP   = +38
%CL_FLT_MAX_EXP      = +128
%CL_FLT_MIN_10_EXP   = -37
%CL_FLT_MIN_EXP      = -125
%CL_FLT_RADIX        = 2
'#define CL_FLT_MAX          340282346638528859811704183484516925440.0f
'#define CL_FLT_MIN          1.175494350822287507969e-38f
'#define CL_FLT_EPSILON      0x1.0p-23f

%CL_DBL_DIG          = 15
%CL_DBL_MANT_DIG     = 53
%CL_DBL_MAX_10_EXP   = +308
%CL_DBL_MAX_EXP      = +1024
%CL_DBL_MIN_10_EXP   = -307
%CL_DBL_MIN_EXP      = -1021
%CL_DBL_RADIX        = 2
'#define CL_DBL_MAX          1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375 _
'                            16986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
'#define CL_DBL_MIN          2.225073858507201383090e-308
'#define CL_DBL_EPSILON      2.220446049250313080847e-16
