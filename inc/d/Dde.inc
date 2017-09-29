' ########################################################################################
' Microsoft Windows
' File: dde.inc
' Contents: Dynamic Data Exchange structures and definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DDE_INC = 1

#INCLUDE ONCE "windows.inc"
'#INCLUDE ONCE "windef.inc"
'#INCLUDE ONCE "winbase.inc"

'// begin_r_dde

'/* DDE window messages */

%WM_DDE_FIRST     = &H03E0
%WM_DDE_INITIATE  = %WM_DDE_FIRST
%WM_DDE_TERMINATE = %WM_DDE_FIRST + 1
%WM_DDE_ADVISE    = %WM_DDE_FIRST + 2
%WM_DDE_UNADVISE  = %WM_DDE_FIRST + 3
%WM_DDE_ACK       = %WM_DDE_FIRST + 4
%WM_DDE_DATA      = %WM_DDE_FIRST + 5
%WM_DDE_REQUEST   = %WM_DDE_FIRST + 6
%WM_DDE_POKE      = %WM_DDE_FIRST + 7
%WM_DDE_EXECUTE   = %WM_DDE_FIRST + 8
%WM_DDE_LAST      = %WM_DDE_FIRST + 8

'// end_r_dde

'/*----------------------------------------------------------------------------
'|       DDEACK structure
'|
'|   Structure of wStatus (LOWORD(lParam)) in WM_DDE_ACK message
'|       sent in response to a WM_DDE_DATA, WM_DDE_REQUEST, WM_DDE_POKE,
'|       WM_DDE_ADVISE, or WM_DDE_UNADVISE message.
'|
'----------------------------------------------------------------------------*/

'typedef struct {
'#ifndef _MAC
'   unsigned short bAppReturnCode:8,
'            reserved:6,
'            fBusy:1,
'            fAck:1;
'#else
'   unsigned short usFlags;
'#endif
'} DDEACK;

' // Size = 2 bytes
TYPE DDEACK WORD
   bAppReturnCode AS BIT * 8 IN WORD
   reserved       AS BIT * 6
   fBusy          AS BIT * 1
   fAck           AS BIT * 1
END TYPE

'/*----------------------------------------------------------------------------
'|       DDEADVISE structure
'|
'|   WM_DDE_ADVISE parameter structure for hOptions (LOWORD(lParam))
'|
'----------------------------------------------------------------------------*/

'typedef struct {
'#ifndef _MAC
'   unsigned short reserved:14,
'            fDeferUpd:1,
'            fAckReq:1;
'#else
'   unsigned short usFlags;
'#endif
'   short     cfFormat;
'} DDEADVISE;

' // Size = 4 bytes
TYPE DDEADVISE WORD
   reserved  AS BIT * 14 IN WORD
   fDeferUpd AS BIT * 1
   fAckReq   AS BIT * 1
   cfFormat  AS INTEGER
END TYPE


'/*----------------------------------------------------------------------------
'|       DDEDATA structure
'|
'|       WM_DDE_DATA parameter structure for hData (LOWORD(lParam)).
'|       The actual size of this structure depends on the size of
'|       the Value array.
'|
'----------------------------------------------------------------------------*/

'typedef struct {
'#ifndef _MAC
'   unsigned short unused:12,
'                  fResponse:1,
'                  fRelease:1,
'                  reserved:1,
'                  fAckReq:1;
'#else
'   unsigned short usFlags;
'#endif
'   short    cfFormat;
'   BYTE    Value[1];
'} DDEDATA;

' // Size = 6 bytes
TYPE DDEDATA WORD
   unused    AS BIT * 12 IN WORD
   fResponse AS BIT * 1
   fRelease  AS BIT * 1
   reserved  AS BIT * 1
   fAckReq   AS BIT * 1
   cfFormat  AS INTEGER
   Value(0) AS BYTE              ' any size array
END TYPE


'/*----------------------------------------------------------------------------
'|   DDEPOKE structure
'|
'|   WM_DDE_POKE parameter structure for hData (LOWORD(lParam)).
'|       The actual size of this structure depends on the size of
'|       the Value array.
'|
'----------------------------------------------------------------------------*/

'typedef struct {
'#ifndef _MAC
'   unsigned short unused:13,  /* Earlier versions of DDE.H incorrectly */
'                             /* 12 unused bits.                       */
'                  fRelease:1,
'                  fReserved:2;
'#else
'   unsigned short usFlags;
'#endif
'   short    cfFormat;
'   BYTE    Value[1];  /* This member was named rgb[1] in previous */
'                            /* versions of DDE.H                        */

'} DDEPOKE;

' // Size = 6 bytes
TYPE DDEPOKE WORD
   unused    AS BIT * 13 IN WORD
   fRelease  AS BIT * 1
   fREserved AS BIT * 2
   cfFormat  AS INTEGER
   Value(0) AS BYTE        ' any size array
END TYPE

'/*----------------------------------------------------------------------------
'The following typedef's were used in previous versions of the Windows SDK.
'They are still valid.  The above typedef's define exactly the same structures
'as those below.  The above typedef names are recommended, however, as they
'are more meaningful.

'Note that the DDEPOKE structure typedef'ed in earlier versions of DDE.H did
'not correctly define the bit positions.
'----------------------------------------------------------------------------*/

'typedef struct {
'#ifndef _MAC
'   unsigned short unused:13,
'                  fRelease:1,
'                  fDeferUpd:1,
'                  fAckReq:1;
'#else
'   unsigned short usFlags;
'#endif
'   short    cfFormat;
'} DDELN;

' // Size = 4 bytes
TYPE DDELN WORD
   unused    AS BIT * 13 IN WORD
   fRelease  AS BIT * 1
   fDeferUpd AS BIT * 1
   fAckReq   AS BIT * 1
   cfFormat  AS INTEGER
END TYPE

'typedef struct {
'#ifndef _MAC
'   unsigned short unused:12,
'                  fAck:1,
'                  fRelease:1,
'                  fReserved:1,
'                  fAckReq:1;
'#else
'   unsigned short usFlags;
'#endif
'   short    cfFormat;
'   BYTE    rgb[1];
'} DDEUP;

' // Size = 6 bytes
TYPE DDEUP WORD
   unused    AS BIT * 12 IN WORD
   fAck      AS BIT * 1
   fRelease  AS BIT * 1
   fReserved AS BIT * 1
   fAckReq   AS BIT * 1
   cfFormat  AS INTEGER
   rgb(0)    AS BYTE        ' any size array
END TYPE

'/*
' * DDE SECURITY
' */

DECLARE FUNCTION DdeSetQualityOfService IMPORT "USER32.DLL" ALIAS "DdeSetQualityOfService" ( _
   BYVAL hwndClient AS DWORD _                          ' __in  HWND hwndClient
 , BYREF pqosNew AS SECURITY_QUALITY_OF_SERVICE _       ' __in  CONST SECURITY_QUALITY_OF_SERVICE *pqosNew
 , BYREF pqosPrev AS SECURITY_QUALITY_OF_SERVICE _      ' __out PSECURITY_QUALITY_OF_SERVICE pqosPrev
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImpersonateDdeClientWindow IMPORT "USER32.DLL" ALIAS "ImpersonateDdeClientWindow" ( _
   BYVAL hWndClient AS DWORD _                          ' __in HWND hWndClient
 , BYVAL hWndServer AS DWORD _                          ' __in HWND hWndServer
 ) AS LONG                                              ' BOOL

'/*
' * DDE message packing APIs
' */

DECLARE FUNCTION PackDDElParam IMPORT "USER32.DLL" ALIAS "PackDDElParam" ( _
   BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL uiLo AS DWORD _                                ' __in UINT_PTR uiLo
 , BYVAL uiHi AS DWORD _                                ' __in UINT_PTR uiHi
 ) AS LONG                                              ' LPARAM

DECLARE FUNCTION UnpackDDElParam IMPORT "USER32.DLL" ALIAS "UnpackDDElParam" ( _
   BYVAL msg AS DWORD _                                 ' __in  UINT msg
 , BYVAL lParam AS LONG _                               ' __in  LPARAM lParam
 , BYREF puiLo AS DWORD _                               ' __out PUINT_PTR puiLo
 , BYREF puiHi AS DWORD _                               ' __out PUINT_PTR puiHi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreeDDElParam IMPORT "USER32.DLL" ALIAS "FreeDDElParam" ( _
   BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReuseDDElParam IMPORT "USER32.DLL" ALIAS "ReuseDDElParam" ( _
   BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL msgIn AS DWORD _                               ' __in UINT msgIn
 , BYVAL msgOut AS DWORD _                              ' __in UINT msgOut
 , BYVAL uiLo AS DWORD _                                ' __in UINT_PTR uiLo
 , BYVAL uiHi AS DWORD _                                ' __in UINT_PTR uiHi
 ) AS LONG                                              ' LPARAM
