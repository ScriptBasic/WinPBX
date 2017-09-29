' ########################################################################################
' Microsoft Windows
' File: bthsdpdef.inc
' Contents: Bluetooth Application Development Structures
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BTHSDPDEF_INC = 1

' // Size = 16 bytes
TYPE SDP_LARGE_INTEGER_16 QWORD
   LowPart  AS QUAD   ' ULONGLONG
   HighPart AS QUAD   ' LONGLONG
END TYPE

' // Size = 16 bytes
TYPE SDP_ULARGE_INTEGER_16 QWORD
   LowPart  AS QUAD   ' ULONGLONG
   HighPart AS QUAD   ' ULONGLONG
END TYPE

' enum NodeContainerType
%NodeContainerTypeSequence    = 0
%NodeContainerTypeAlternative = 1

'typedef USHORT SDP_ERROR, *PSDP_ERROR;

' enum SDP_TYPE
MACRO SDP_TYPE_ENUM = LONG
%SDP_TYPE_NIL         = &H00
%SDP_TYPE_UINT        = &H01
%SDP_TYPE_INT         = &H02
%SDP_TYPE_UUID        = &H03
%SDP_TYPE_STRING      = &H04
%SDP_TYPE_BOOLEAN     = &H05
%SDP_TYPE_SEQUENCE    = &H06
%SDP_TYPE_ALTERNATIVE = &H07
%SDP_TYPE_URL         = &H08
%SDP_TYPE_CONTAINER   = &H20

'//  9 - 31 are reserved

'// allow for a little easier type checking / sizing for integers and UUIDs
'// ((SDP_ST_XXX & 0xF0) >> 4) == SDP_TYPE_XXX
'// size of the data (in bytes) is encoded as ((SDP_ST_XXX & 0xF0) >> 8)

' enum SDP_SPECIFICTYPE
MACRO SDP_SPECIFICTYPE_ENUM = LONG
%SDP_ST_NONE          = &H0000

%SDP_ST_UINT8         = &H0010
%SDP_ST_UINT16        = &H0110
%SDP_ST_UINT32        = &H0210
%SDP_ST_UINT64        = &H0310
%SDP_ST_UINT128       = &H0410

%SDP_ST_INT8          = &H0020
%SDP_ST_INT16         = &H0120
%SDP_ST_INT32         = &H0220
%SDP_ST_INT64         = &H0320
%SDP_ST_INT128        = &H0420

%SDP_ST_UUID16        = &H0130
%SDP_ST_UUID32        = &H0220
%SDP_ST_UUID128       = &H0430

' // Size = 4 bytes
TYPE SdpAttributeRange WORD
   minAttribute AS WORD   ' USHORT
   maxAttribute AS WORD   ' USHORT
END TYPE

' // Size = 16 bytes
UNION SdpQueryUuidUnion
   uuid128 AS GUID    ' GUID
   uuid32  AS DWORD   ' ULONG
   uuid16  AS WORD    ' USHORT
END UNION

' // Size = 20 bytes
TYPE SdpQueryUuid DWORD
  SdpQueryUuidUnion
  uuidType AS WORD
END TYPE
