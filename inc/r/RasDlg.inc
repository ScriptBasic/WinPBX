' ########################################################################################
' Microsoft Windows
' File: RasDlg.inc
' Contents: Remote Access Common Dialog APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RASDLG_INC = 1

'#include <pshpack4.h>

#INCLUDE ONCE "ras.inc"


'/* RasPhonebookDlg API callback.
'*/
'typedef VOID (WINAPI* RASPBDLGFUNCW)( ULONG_PTR, DWORD, LPWSTR, LPVOID );
'typedef VOID (WINAPI* RASPBDLGFUNCA)( ULONG_PTR, DWORD, LPSTR, LPVOID );

%RASPBDEVENT_AddEntry    = 1
%RASPBDEVENT_EditEntry   = 2
%RASPBDEVENT_RemoveEntry = 3
%RASPBDEVENT_DialEntry   = 4
%RASPBDEVENT_EditGlobals = 5
%RASPBDEVENT_NoUser      = 6
%RASPBDEVENT_NoUserEdit  = 7

%RASNOUSER_SmartCard     = &H00000001???

'/* Defines the information passed in the 4th argument of RASPBDLGFUNC on
'** "NoUser" and "NoUserEdit" events.  Usage shown is for "NoUser".  For
'** "NoUserEdit", the timeout is ignored and the three strings are INs.
'*/
'#define RASNOUSERW struct tagRASNOUSERW
' // Size = 1072 bytes
TYPE tagRASNOUSERW   ' Must be 4 byte aligned
   dwSize      AS DWORD                   ' DWORD
   dwFlags     AS DWORD                   ' DWORD
   dwTimeoutMs AS DWORD                   ' DWORD
   szUserName  AS WSTRINGZ * %UNLEN + 1   ' WCHAR[UNLEN]
   szPassword  AS WSTRINGZ * %PWLEN + 1   ' WCHAR[PWLEN]
   szDomain    AS WSTRINGZ * %DNLEN + 1   ' WCHAR[DNLEN]
END TYPE

'#define RASNOUSERA struct tagRASNOUSERA
' // Size = 544 bytes
TYPE tagRASNOUSERA   ' Must be 4 byte aligned
   dwSize         AS DWORD                 ' DWORD
   dwFlags        AS DWORD                 ' DWORD
   dwTimeoutMs    AS DWORD                 ' DWORD
   szUserName     AS ASCIIZ * %UNLEN + 1   ' CHAR[UNLEN]
   szPassword     AS ASCIIZ * %PWLEN + 1   ' CHAR[PWLEN]
   szDomain       AS ASCIIZ * %DNLEN + 1   ' CHAR[DNLEN]
   alignment__(1) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagRASNOUSER = tagRASNOUSERW
#ELSE
   MACRO tagRASNOUSER = tagRASNOUSERA
#ENDIF

'/* RasPhonebookDlg API parameters.
'*/
%RASPBDFLAG_PositionDlg      = &H00000001???
%RASPBDFLAG_ForceCloseOnDial = &H00000002???
%RASPBDFLAG_NoUser           = &H00000010???
%RASPBDFLAG_UpdateDefaults   = &H80000000???

'#define RASPBDLGW struct tagRASPBDLGW
' // Size = 40 bytes
TYPE tagRASPBDLGW   ' Must be 4 byte aligned
   dwSize       AS DWORD   ' DWORD
   hwndOwner    AS DWORD   ' HWND
   dwFlags      AS DWORD   ' DWORD
   xDlg         AS LONG    ' LONG
   yDlg         AS LONG    ' LONG
   dwCallbackId AS DWORD   ' ULONG_PTR
   pCallback    AS DWORD   ' RASPBDLGFUNCW
   dwError      AS DWORD   ' DWORD
   reserved     AS DWORD   ' ULONG_PTR
   reserved2    AS DWORD   ' ULONG_PTR
END TYPE

'#define RASPBDLGA struct tagRASPBDLGA
' // Size = 40 bytes
TYPE tagRASPBDLGA   ' Must be 4 byte aligned
   dwSize       AS DWORD   ' DWORD
   hwndOwner    AS DWORD   ' HWND
   dwFlags      AS DWORD   ' DWORD
   xDlg         AS LONG    ' LONG
   yDlg         AS LONG    ' LONG
   dwCallbackId AS DWORD   ' ULONG_PTR
   pCallback    AS DWORD   ' RASPBDLGFUNCA
   dwError      AS DWORD   ' DWORD
   reserved     AS DWORD   ' ULONG_PTR
   reserved2    AS DWORD   ' ULONG_PTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagRASPBDLG = tagRASPBDLGW
#ELSE
   MACRO tagRASPBDLG = tagRASPBDLGA
#ENDIF

'/* RasEntryDlg API parameters.
'*/
%RASEDFLAG_PositionDlg       = &H00000001???
%RASEDFLAG_NewEntry          = &H00000002???
'#if (WINVER < 0x600)
%RASEDFLAG_CloneEntry        = &H00000004???
'#endif // (WINVER < 0x600)
%RASEDFLAG_NoRename          = &H00000008???
%RASEDFLAG_ShellOwned        = &H40000000???
%RASEDFLAG_NewPhoneEntry     = &H00000010???
%RASEDFLAG_NewTunnelEntry    = &H00000020???
'#if (WINVER < 0x600)
%RASEDFLAG_NewDirectEntry    = &H00000040???
'#endif // (WINVER < 0x600)
%RASEDFLAG_NewBroadbandEntry = &H00000080???
%RASEDFLAG_InternetEntry     = &H00000100???
%RASEDFLAG_NAT               = &H00000200???
'#if (WINVER >= 0x600)
%RASEDFLAG_IncomingConnection = &H00000400???
'#endif

'#define RASENTRYDLGW struct tagRASENTRYDLGW
' // Size = 548 bytes
TYPE tagRASENTRYDLGW   ' Must be 4e byte aligned
   dwSize         AS DWORD                              ' DWORD
   hwndOwner      AS DWORD                              ' HWND
   dwFlags        AS DWORD                              ' DWORD
   xDlg           AS LONG                               ' LONG
   yDlg           AS LONG                               ' LONG
   szEntry        AS WSTRINGZ * %RAS_MaxEntryName + 1   ' WCHAR[RAS_MaxEntryName + 1]
   dwError        AS DWORD                              ' DWORD
   reserved       AS DWORD                              ' ULONG_PTR
   reserved2      AS DWORD                              ' ULONG_PTR
   alignment__(1) AS BYTE
END TYPE

'#define RASENTRYDLGA struct tagRASENTRYDLGA
' // Size = 292 bytes
TYPE tagRASENTRYDLGA   ' Must be 4 byte aligned
   dwSize         AS DWORD                            ' DWORD
   hwndOwner      AS DWORD                            ' HWND
   dwFlags        AS DWORD                            ' DWORD
   xDlg           AS LONG                             ' LONG
   yDlg           AS LONG                             ' LONG
   szEntry        AS ASCIIZ * %RAS_MaxEntryName + 1   ' CHAR[RAS_MaxEntryName + 1]
   dwError        AS DWORD                            ' DWORD
   reserved       AS DWORD                            ' ULONG_PTR
   reserved2      AS DWORD                            ' ULONG_PTR
   alignment__(2) AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagRASENTRYDLG = tagRASENTRYDLGW
#ELSE
   MACRO tagRASENTRYDLG = tagRASENTRYDLGA
#ENDIF

'/* RasDialDlg API parameters.
'*/
%RASDDFLAG_PositionDlg = &H00000001???
%RASDDFLAG_NoPrompt    = &H00000002???
%RASDDFLAG_LinkFailure = &H80000000???

'#define RASDIALDLG struct tagRASDIALDLG
' // Size = 36 bytes
TYPE tagRASDIALDLG   ' Must be 4 byte aligned
   dwSize     AS DWORD   ' DWORD
   hwndOwner  AS DWORD   ' HWND
   dwFlags    AS DWORD   ' DWORD
   xDlg       AS LONG    ' LONG
   yDlg       AS LONG    ' LONG
   dwSubEntry AS DWORD   ' DWORD
   dwError    AS DWORD   ' DWORD
   reserved   AS DWORD   ' ULONG_PTR
   reserved2  AS DWORD   ' ULONG_PTR
END TYPE


' --- RASMONITORDLG is not supported after Windows 2000 ------------------------------------

'/* RasMonitorDlg API parameters.
'*/
#IF %WINVER <= &H500
%RASMDPAGE_Status            = 0
%RASMDPAGE_Summary           = 1
%RASMDPAGE_Preferences       = 2

%RASMDFLAG_PositionDlg       = &H00000001???
%RASMDFLAG_UpdateDefaults    = &H80000000???

'#define RASMONITORDLG struct tagRASMONITORDLG
' // Size = 36 bytes
TYPE tagRASMONITORDLG   ' Must be 4 byte aligned
   dwSize      AS DWORD   ' DWORD
   hwndOwner   AS DWORD   ' HWND
   dwFlags     AS DWORD   ' DWORD
   dwStartPage AS DWORD   ' DWORD
   xDlg        AS LONG    ' LONG
   yDlg        AS LONG    ' LONG
   dwError     AS DWORD   ' DWORD
   reserved    AS DWORD   ' ULONG_PTR
   reserved2   AS DWORD   ' ULONG_PTR
END TYPE

#ENDIF

' ------------------------------------------------------------------------------------------

#IF %WINVER >= &H500
'typedef BOOL (WINAPI *RasCustomDialDlgFn) (
'                            HINSTANCE hInstDll,
'                            DWORD dwFlags,
'                            LPWSTR lpszPhonebook,
'                            LPWSTR lpszEntry,
'                            LPWSTR lpszPhoneNumber,
'                            LPRASDIALDLG lpInfo,
'                            PVOID pvInfo
'                            );

'FUNCTION RasCustomDialDlgFn ( _
'   BYVAL hInstDll AS DWORD _                ' HINSTANCE hInstDll
' , BYVAL dwFlags AS DWORD _                 ' DWORD dwFlags
' , BYREF lpszPhonebook AS WSTRINGZ _        ' LPWSTR lpszPhonebook
' , BYREF lpszEntry AS WSTRINGZ _            ' LPWSTR lpszEntry
' , BYREF lpszPhoneNumber AS WSTRINGZ _      ' LPWSTR lpszPhoneNumber
' , BYREF lpInfo AS tagRASDIALDLG _          ' LPRASDIALDLG lpInfo
' , BYVAL pvInfo AS DWORD _                  ' PVOID pvInfo
' ) AS LONG                                              ' BOOL

'END FUNCTION

'typedef BOOL (WINAPI *RasCustomEntryDlgFn) (
'                            HINSTANCE hInstDll,
'                            LPWSTR lpszPhonebook,
'                            LPWSTR lpszEntry,
'                            LPRASENTRYDLG lpInfo,
'                            DWORD  dwFlags
'                            );

'FUNCTION RasCustomEntryDlgFn ( _
'   BYVAL hInstDll AS DWORD _                ' HINSTANCE hInstDll
' , BYREF lpszPhonebook AS WSTRINGZ _        ' LPWSTR lpszPhonebook
' , BYREF lpszEntry AS WSTRINGZ _            ' LPWSTR lpszEntry
' , BYREF lpInfo AS tagRASENTRYDLG _         ' LPRASENTRYDLG lpInfo
' , BYVAL dwFlags AS DWORD _                 ' DWORD dwFlags
' ) AS LONG                                              ' BOOL

'END FUNCTION

#ENDIF


'/* RAS common dialog API prototypes.
'*/

DECLARE FUNCTION RasPhonebookDlgA IMPORT "RASDLG.DLL" ALIAS "RasPhonebookDlgA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in LPSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in LPSTR lpszEntry
 , BYREF lpInfo AS tagRASPBDLGA _                       ' __in_out LPRASPBDLGA lpInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RasPhonebookDlgW IMPORT "RASDLG.DLL" ALIAS "RasPhonebookDlgW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in LPWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in LPWSTR lpszEntry
 , BYREF lpInfo AS tagRASPBDLGW _                       ' __in_out LPRASPBDLGW lpInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RasPhonebookDlg = RasPhonebookDlgW
#ELSE
   MACRO RasPhonebookDlg = RasPhonebookDlgA
#ENDIF

DECLARE FUNCTION RasEntryDlgA IMPORT "RASDLG.DLL" ALIAS "RasEntryDlgA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in LPSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in LPSTR lpszEntry
 , BYREF lpInfo AS tagRASENTRYDLGA _                    ' __in LPRASENTRYDLGA lpInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RasEntryDlgW IMPORT "RASDLG.DLL" ALIAS "RasEntryDlgW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in LPWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in LPWSTR lpszEntry
 , BYREF lpInfo AS tagRASENTRYDLGW _                    ' __in LPRASENTRYDLGW lpInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RasEntryDlg = RasEntryDlgW
#ELSE
   MACRO RasEntryDlg = RasEntryDlgA
#ENDIF

DECLARE FUNCTION RasDialDlgA IMPORT "RASDLG.DLL" ALIAS "RasDialDlgA" ( _
   BYREF lpszPhonebook AS ASCIIZ _                      ' __in LPSTR lpszPhonebook
 , BYREF lpszEntry AS ASCIIZ _                          ' __in LPSTR lpszEntry
 , BYREF lpszPhoneNumber AS ASCIIZ _                    ' __in LPSTR lpszPhoneNumber
 , BYREF lpInfo AS tagRASDIALDLG _                      ' __in LPRASDIALDLG lpInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RasDialDlgW IMPORT "RASDLG.DLL" ALIAS "RasDialDlgW" ( _
   BYREF lpszPhonebook AS WSTRINGZ _                    ' __in LPWSTR lpszPhonebook
 , BYREF lpszEntry AS WSTRINGZ _                        ' __in LPWSTR lpszEntry
 , BYREF lpszPhoneNumber AS WSTRINGZ _                  ' __in LPWSTR lpszPhoneNumber
 , BYREF lpInfo AS tagRASDIALDLG _                      ' __in LPRASDIALDLG lpInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RasDialDlg = RasDialDlgW
#ELSE
   MACRO RasDialDlg = RasDialDlgA
#ENDIF

' // This function is not supported after Windows 2000.
#IF %WINVER <= &H500
DECLARE FUNCTION RasMonitorDlgA IMPORT "RASDLG.DLL" ALIAS "RasMonitorDlgA" ( _
   BYREF lpszDeviceName AS ASCIIZ _                     ' __in LPSTR lpszDeviceName
 , BYREF lpInfo AS tagRASMONITORDLG _                   ' __in_out LPRASMONITORDLG lpInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RasMonitorDlgW IMPORT "RASDLG.DLL" ALIAS "RasMonitorDlgW" ( _
   BYREF lpszDeviceName AS WSTRINGZ _                   ' __in LPWSTR lpszDeviceName
 , BYREF lpInfo AS tagRASMONITORDLG _                   ' __in_out LPRASMONITORDLG lpInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RasMonitorDlg = RasMonitorDlgW
#ELSE
   MACRO RasMonitorDlg = RasMonitorDlgA
#ENDIF
#ENDIF

'#include <poppack.h>
