' ########################################################################################
' Microsoft Windows
' File: ntnls.inc
' Contents: NLS file formats and data types
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTNLS_INC = 1

%MAXIMUM_LEADBYTES = 12

' // Size = 44 bytes
TYPE CPTABLEINFO DWORD FILL
   CodePage                         AS WORD       ' USHORT // code page number
   MaximumCharacterSize             AS WORD       ' USHORT // max length (bytes) of a char
   DefaultChar                      AS WORD       ' USHORT // default character (MB)
   UniDefaultChar                   AS WORD       ' USHORT // default character (Unicode)
   TransDefaultChar                 AS WORD       ' USHORT // translation of default char (Unicode)
   TransUniDefaultChar              AS WORD       ' USHORT // translation of Unic default char (MB)
   DBCSCodePage                     AS WORD       ' USHORT // Non 0 for DBCS code pages
   LeadByte(%MAXIMUM_LEADBYTES - 1) AS BYTE       ' UCHAR[MAXIMUM_LEADBYTE] // lead byte ranges
   MultiByteTable                   AS WORD PTR   ' PUSHORT // pointer to MB translation table
   WideCharTable                    AS DWORD      ' PVOID // pointer to WC translation table
   DBCSRanges                       AS WORD PTR   ' PUSHORT // pointer to DBCS ranges
   DBCSOffsets                      AS WORD PTR   ' PUSHORT // pointer to DBCS offsets
END TYPE

' // Size = 96 bytes
TYPE NLSTABLEINFO DWORD FILL
   OemTableInfo   AS CPTABLEINFO
   AnsiTableInfo  AS CPTABLEINFO
   UpperCaseTable AS WORD PTR   ' PUSHORT // 844 format upcase table
   LowerCaseTable AS WORD PTR   ' PUSHORT // 844 format lower case table
END TYPE
