' ########################################################################################
' Microsoft Windows
' File: ifmib.inc
' Contents: Public definitions and structures for the non-TCP/IP specific parts of MIB-II.
' These definitions were previously in iprtrmib.h, which now includes this file.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IFMIB_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "ifdef.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

' // Serie = 4 bytes
TYPE MIB_IFNUMBER DWORD
   dwValue AS DWORD   ' DWORD
END TYPE

'//
'// $REVIEW: This has always been defined as 8.  However, this is not
'// sufficient for all media types.
'//

%MAXLEN_PHYSADDR        = 8
%MAXLEN_IFDESCR         = 256
%MAX_INTERFACE_NAME_LEN = 256

' // Serie = 860 bytes
TYPE MIB_IFROW DWORD
   wszName           AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN   ' WCHAR
   dwIndex           AS DWORD   ' IF_INDEX
   dwType            AS DWORD   ' IFTYPE
   dwMtu             AS DWORD   ' DWORD
   dwSpeed           AS DWORD   ' DWORD
   dwPhysAddrLen     AS DWORD   ' DWORD
   bPhysAddr(%MAXLEN_PHYSADDR - 1) AS BYTE   ' UCHAR
   dwAdminStatus     AS DWORD   ' DWORD
   dwOperStatus      AS DWORD   ' INTERNAL_IF_OPER_STATUS enum
   dwLastChange      AS DWORD   ' DWORD
   dwInOctets        AS DWORD   ' DWORD
   dwInUcastPkts     AS DWORD   ' DWORD
   dwInNUcastPkts    AS DWORD   ' DWORD
   dwInDiscards      AS DWORD   ' DWORD
   dwInErrors        AS DWORD   ' DWORD
   dwInUnknownProtos AS DWORD   ' DWORD
   dwOutOctets       AS DWORD   ' DWORD
   dwOutUcastPkts    AS DWORD   ' DWORD
   dwOutNUcastPkts   AS DWORD   ' DWORD
   dwOutDiscards     AS DWORD   ' DWORD
   dwOutErrors       AS DWORD   ' DWORD
   dwOutQLen         AS DWORD   ' DWORD
   dwDescrLen        AS DWORD   ' DWORD
   bDescr(%MAXLEN_IFDESCR - 1) AS BYTE   ' UCHAR
END TYPE

' // Serie = 864 bytes
TYPE MIB_IFTABLE DWORD
   dwNumEntries AS DWORD
   table(0)     AS MIB_IFROW   ' MIB_IFROW table[ANY_SIZE]
END TYPE

'#define SIZEOF_IFTABLE(X) (FIELD_OFFSET(MIB_IFTABLE,table[0]) + \
'                           ((X) * sizeof(MIB_IFROW)) + ALIGN_SIZE)
