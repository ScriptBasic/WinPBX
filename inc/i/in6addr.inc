' ########################################################################################
' Microsoft Windows
' File: in6addr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IN6ADDR_INC = 1

#IF NOT %DEF(%s6_addr)
    %s6_addr = 1

'//
'// IPv6 Internet address (RFC 2553)
'// This is an 'on-wire' format structure.
'//
'typedef struct in6_addr {
'    union {
'        UCHAR       Byte[16];
'        USHORT      Word[8];
'    } u;
'} IN6_ADDR, *PIN6_ADDR, FAR *LPIN6_ADDR;

' // Size = 16 bytes
UNION IN6_ADDR_UNION BYTE
   Byte(15) AS BYTE
   Word(7)  AS WORD
   nByte(15) AS BYTE
   nWord(7)  AS WORD
END UNION
MACRO S6_un = IN6_ADDR_UNION

UNION IN6_ADDR_UNION_2 BYTE
   IN6_ADDR_UNION
   u AS IN6_ADDR_UNION
END UNION

' // Size = 16 bytes
TYPE in6_addr BYTE
   IN6_ADDR_UNION_2
END TYPE

'#define in_addr6 in6_addr
MACRO in_addr6 = in6_addr

'//
'// Defines to match RFC 2553.
'//
'#define _S6_un      u
'#define _S6_u8      Byte
'#define s6_addr     _S6_un._S6_u8

'//
'// Defines for our implementation.
'//
'#define s6_bytes    u.Byte
'#define s6_words    u.Word

MACRO s6_bytes = u.Byte
MACRO s6_words = u.Word

#ENDIF   ' #IF NOT %DEF(%s6_addr)
