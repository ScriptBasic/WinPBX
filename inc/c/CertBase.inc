' ########################################################################################
' Microsoft Windows
' File: CertBase.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTBASE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"

' // Size = 8 bytes
TYPE CERTTRANSBLOB DWORD
   cb AS DWORD      ' unsigned long
   pb AS BYTE PTR   ' BYTE *
END TYPE

' // Size = 20 bytes
TYPE CERTVIEWRESTRICTION
   ColumnIndex  AS DWORD      ' DWORD
   SeekOperator AS LONG       ' LONG
   SortOrder    AS LONG       ' LONG
   pbValue      AS BYTE PTR   ' BYTE *
   cbValue      AS DWORD      ' DWORD
END TYPE
