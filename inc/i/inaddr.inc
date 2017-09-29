' ########################################################################################
' Microsoft Windows
' File: inaddr.inc
' Contents: Input Method Manager definitions
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%INADDR_INC = 1

'//
'// IPv4 Internet address
'// This is an 'on-wire' format structure.
'//
'typedef struct in_addr {
'        union {
'                struct { UCHAR s_b1,s_b2,s_b3,s_b4; } S_un_b;
'                struct { USHORT s_w1,s_w2; } S_un_w;
'                ULONG S_addr;
'        } S_un;
'#define s_addr  S_un.S_addr /* can be used for most tcp & ip code */
'#define s_host  S_un.S_un_b.s_b2    // host on imp
'#define s_net   S_un.S_un_b.s_b1    // network
'#define s_imp   S_un.S_un_w.s_w2    // imp
'#define s_impno S_un.S_un_b.s_b4    // imp #
'#define s_lh    S_un.S_un_b.s_b3    // logical host
'} IN_ADDR, *PIN_ADDR, FAR *LPIN_ADDR;

'#endif


#IF NOT %DEF(%s_addr)
    %s_addr = 1

' // Size = 4 bytes
TYPE S_un_b_type BYTE
   s_b1 AS BYTE
   s_b2 AS BYTE
   s_b3 AS BYTE
   s_b4 AS BYTE
END TYPE

' // Size = 4 bytes
TYPE S_un_w_type WORD
   s_w1 AS WORD
   s_w2 AS WORD
END TYPE

' // Size = 4 bytes
UNION S_un
   S_un_b AS S_un_b_type
   S_un_w AS S_un_w_type
   S_addr AS DWORD
   s AS STRING * 4
END UNION

' // Size = 4 bytes
UNION in_addr
   S_un
   S_un AS S_un
END UNION

' can be used for most tcp & ip code
MACRO s_addrm = S_un.S_addr

' host on imp
MACRO s_hostm = S_Un.S_un_b.s_b2

' network
MACRO s_netm = S_Un.S_un_b.s_b1

' imp
MACRO s_impm = S_un.S_un_w.s_w2

' imp #
MACRO s_impnom = S_un.S_un_b.s_b4

' logical host
MACRO s_lhm = S_un.S_un_b.s_b3

#ENDIF
