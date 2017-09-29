' ########################################################################################
' Microsoft Windows
' File: WinReg.inc
' Contents: This module contains the function prototypes and constant, type and structure
' definitions for the Windows 32-Bit Registry API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINREG_INC = 1

#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "windows.inc"

'#ifndef WINVER
'#define WINVER 0x0500   // version 5.0
'#endif /* !WINVER */

'//
'// RRF - Registry Routine Flags (for RegGetValue)
'//

%RRF_RT_REG_NONE        = &H00000001???  ' // restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_SZ          = &H00000002???  ' // restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless RRF_NOEXPAND is specified)
%RRF_RT_REG_EXPAND_SZ   = &H00000004???  ' // restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify RRF_NOEXPAND or RegGetValue will fail with ERROR_INVALID_PARAMETER)
%RRF_RT_REG_BINARY      = &H00000008???  ' // restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_DWORD       = &H00000010???  ' // restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_MULTI_SZ    = &H00000020???  ' // restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)
%RRF_RT_REG_QWORD       = &H00000040???  ' // restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

%RRF_RT_DWORD           = %RRF_RT_REG_BINARY OR %RRF_RT_REG_DWORD  ' // restrict type to *32-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%RRF_RT_QWORD           = %RRF_RT_REG_BINARY OR %RRF_RT_REG_QWORD ' // restrict type to *64-bit* RRF_RT_REG_BINARY or RRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%RRF_RT_ANY             = &H0000ffff???                             ' // no type restriction

%RRF_NOEXPAND           = &H10000000???  ' // do not automatically expand environment strings if value is of type REG_EXPAND_SZ
%RRF_ZEROONFAILURE      = &H20000000???  ' // if pvData is not NULL, set content to all zeros on failure

'//
'// Flags for RegLoadAppKey
'//
%REG_PROCESS_APPKEY          = &H00000001???

'//
'// Flags for RegLoadMUIString
'//
%REG_MUI_STRING_TRUNCATE     = &H00000001???

'//
'// Requested Key access mask type.
'//

'typedef ACCESS_MASK REGSAM;
MACRO REGSAM = ACCESS_MASK

'//
'// Reserved Key Handles.
'//

%HKEY_CLASSES_ROOT                = &H80000000???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000000) )
%HKEY_CURRENT_USER                = &H80000001???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000001) )
%HKEY_LOCAL_MACHINE               = &H80000002???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000002) )
%HKEY_USERS                       = &H80000003???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000003) )
%HKEY_PERFORMANCE_DATA            = &H80000004???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000004) )
%HKEY_PERFORMANCE_TEXT            = &H80000050???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000050) )
%HKEY_PERFORMANCE_NLSTEXT         = &H80000060???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000060) )
'#if(WINVER >= 0x0400)
%HKEY_CURRENT_CONFIG              = &H80000005???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000005) )
%HKEY_DYN_DATA                    = &H80000006???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000006) )
%HKEY_DYNAMIC_DATA                = %HKEY_DYN_DATA  ' Not in Windows 7 SDK
%HKEY_CURRENT_USER_LOCAL_SETTINGS = &H80000007???   ' (( HKEY ) (ULONG_PTR)((LONG)0x80000007) )

' *** For compatibility with PowerBASIC's win32api.inc file ***
%HKCR = %HKEY_CLASSES_ROOT
%HKCU = %HKEY_CURRENT_USER
%HKLM = %HKEY_LOCAL_MACHINE
%HKU  = %HKEY_USERS
%HKPD = %HKEY_PERFORMANCE_DATA
%HKCC = %HKEY_CURRENT_CONFIG
%HKDD = %HKEY_DYN_DATA

'//
'// RegConnectRegistryEx supported flags
'//
'#define REG_SECURE_CONNECTION   1
%REG_SECURE_CONNECTION = 1

'/*NOINC*/
'#ifndef _PROVIDER_STRUCTS_DEFINED
'#define _PROVIDER_STRUCTS_DEFINED

%PROVIDER_KEEPS_VALUE_LENGTH = &H1

' // Size = 12 bytes
TYPE val_context DWORD
   valuelen      AS LONG    ' int    // the total length of this value
   value_context AS DWORD   ' LPVOID // provider's context
   val_buff_ptr  AS DWORD   ' LPVOID // where in the ouput buffer the value is.
END TYPE

' // Size = 16 bytes
TYPE PVALUEA DWORD                  ' // Provider supplied value/context.
   pv_valuename     AS ASCIIZ PTR   ' LPSTR // The value name pointer
   pv_valuelen      AS LONG         ' int
   pv_value_context AS DWORD        ' LPVOID
   pv_type          AS DWORD        ' DWORD
END TYPE

' // Size = 16 bytes
TYPE PVALUEW DWORD                     ' // Provider supplied value/context.
   pv_valuename     AS WSTRINGZ PTR    ' LPWSTR // The value name pointer
   pv_valuelen      AS LONG            ' int
   pv_value_context AS DWORD           ' LPVOID
   pv_type          AS DWORD           ' DWORD
END TYPE

' // PVALUE can't be used because it conflicts with several existing
' // pValue variables used as parameters in functions.

'typedef
'DWORD __cdecl
'QUERYHANDLER (LPVOID keycontext, PVALCONTEXT val_list, DWORD num_vals,
'          LPVOID outputbuffer, DWORD FAR *total_outlen, DWORD input_blen);

' // Size = 24 bytes
TYPE REG_PROVIDER DWORD
   pi_R0_1val     AS DWORD   ' PQUERYHANDLER
   pi_R0_allvals  AS DWORD   ' PQUERYHANDLER
   pi_R3_1val     AS DWORD   ' PQUERYHANDLER
   pi_R3_allvals  AS DWORD   ' PQUERYHANDLER
   pi_flags       AS DWORD   ' DWORD // capability flags (none defined yet).
   pi_key_context AS DWORD   ' LPVOID
END TYPE

' // Size = 16 bytes
TYPE VALENTA DWORD
   ve_valuename AS ASCIIZ PTR   ' LPSTR
   ve_valuelen  AS DWORD        ' DWORD
   ve_valueptr  AS DWORD        ' DWORD_PTR
   ve_type      AS DWORD        ' DWORD
END TYPE

' // Size = 16 bytes
TYPE VALENTW DWORD
   ve_valuename AS WSTRINGZ PTR   ' LPWSTR
   ve_valuelen  AS DWORD          ' DWORD
   ve_valueptr  AS DWORD          ' DWORD_PTR
   ve_type      AS DWORD          ' DWORD
END TYPE

MACRO VALENT = VALENTA

'#endif // not(_PROVIDER_STRUCTS_DEFINED)
'/*INC*/

'#endif /* WINVER >= 0x0400 */

'//
'// Default values for parameters that do not exist in the Win 3.1
'// compatible APIs.
'//

'#define WIN31_CLASS                 NULL

'//
'// API Prototypes.
'//


DECLARE FUNCTION RegCloseKey IMPORT "ADVAPI32.DLL" ALIAS "RegCloseKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOverridePredefKey IMPORT "ADVAPI32.DLL" ALIAS "RegOverridePredefKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , OPTIONAL BYVAL hNewHKey AS DWORD _                   ' __in_opt HKEY hNewHKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOpenUserClassesRoot IMPORT "ADVAPI32.DLL" ALIAS "RegOpenUserClassesRoot" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY  phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOpenCurrentUser IMPORT "ADVAPI32.DLL" ALIAS "RegOpenCurrentUser" ( _
   BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LONG

DECLARE FUNCTION RegDisablePredefinedCache IMPORT "ADVAPI32.DLL" ALIAS "RegDisablePredefinedCache" ( _
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDisablePredefinedCacheEx IMPORT "ADVAPI32.DLL" ALIAS "RegDisablePredefinedCacheEx" ( _
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegConnectRegistryA IMPORT "ADVAPI32.DLL" ALIAS "RegConnectRegistryA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPCSTR lpMachineName
 , BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegConnectRegistryW IMPORT "ADVAPI32.DLL" ALIAS "RegConnectRegistryW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPCWSTR lpMachineName
 , BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegConnectRegistry = RegConnectRegistryW
#ELSE
   MACRO RegConnectRegistry = RegConnectRegistryA
#ENDIF

DECLARE FUNCTION RegConnectRegistryExA IMPORT "ADVAPI32.DLL" ALIAS "RegConnectRegistryExA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPCSTR lpMachineName
 , BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegConnectRegistryExW IMPORT "ADVAPI32.DLL" ALIAS "RegConnectRegistryExW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPCWSTR lpMachineName
 , BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegConnectRegistryEx = RegConnectRegistryExW
#ELSE
   MACRO RegConnectRegistryEx = RegConnectRegistryExA
#ENDIF

DECLARE FUNCTION RegCreateKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegCreateKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegCreateKey = RegCreateKeyW
#ELSE
   MACRO RegCreateKey = RegCreateKeyA
#ENDIF

DECLARE FUNCTION RegCreateKeyExA IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in LPCSTR lpSubKey
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYREF lpClass AS ASCIIZ _                            ' __in_opt LPSTR lpClass
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , OPTIONAL BYREF lpdwDisposition AS DWORD _            ' __out_opt LPDWORD lpdwDisposition
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegCreateKeyExW IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in LPCWSTR lpSubKey
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYREF lpClass AS WSTRINGZ _                          ' __in_opt LPWSTR lpClass
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , OPTIONAL BYREF lpdwDisposition AS DWORD _            ' __out_opt LPDWORD lpdwDisposition
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegCreateKeyEx = RegCreateKeyExW
#ELSE
   MACRO RegCreateKeyEx = RegCreateKeyExA
#ENDIF

DECLARE FUNCTION RegDeleteKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in LPCSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyW" ( _
   BYVAL hKey AS DWORD  _                               ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in LPCWSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteKey = RegDeleteKeyW
#ELSE
   MACRO RegDeleteKey = RegDeleteKeyA
#ENDIF

DECLARE FUNCTION RegCreateKeyTransactedA IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyTransactedA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in LPCSTR lpSubKey
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYREF lpClass AS ASCIIZ _                            ' __in_opt LPSTR lpClass
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , BYREF lpdwDisposition AS DWORD _                     ' __out_opt LPDWORD lpdwDisposition
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParemeter AS DWORD _                  ' __in PVOID pExtendedParemeter
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegCreateKeyTransactedW IMPORT "ADVAPI32.DLL" ALIAS "RegCreateKeyTransactedW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in LPCWSTR lpSubKey
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYREF lpClass AS WSTRINGZ _                          ' __in_opt LPWSTR lpClass
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , BYREF lpdwDisposition AS DWORD _                     ' __out_opt LPDWORD lpdwDisposition
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParemeter AS DWORD _                  ' __in PVOID  pExtendedParemeter
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegCreateKeyTransacted = RegCreateKeyTransactedW
#ELSE
   MACRO RegCreateKeyTransacted = RegCreateKeyTransactedA
#ENDIF

DECLARE FUNCTION RegDeleteKeyExA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in LPCSTR lpSubKey
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteKeyExW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in LPCWSTR lpSubKey
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteKeyEx = RegDeleteKeyExW
#ELSE
   MACRO RegDeleteKeyEx = RegDeleteKeyExA
#ENDIF

DECLARE FUNCTION RegDeleteKeyTransactedA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyTransactedA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in LPCSTR lpSubKey
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParameter AS DWORD _                  ' __in PVOID pExtendedParameter
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteKeyTransactedW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyTransactedW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in LPCWSTR lpSubKey
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParameter AS DWORD _                  ' __in PVOID pExtendedParameter
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteKeyTransacted = RegDeleteKeyTransactedW
#ELSE
   MACRO RegDeleteKeyTransacted = RegDeleteKeyTransactedA
#ENDIF

DECLARE FUNCTION RegDisableReflectionKey IMPORT "ADVAPI32.DLL" ALIAS "RegDisableReflectionKey" ( _
   BYVAL hBase AS DWORD _                               ' __in HKEY hBase
 ) AS LONG                                              ' LONG

DECLARE FUNCTION RegEnableReflectionKey IMPORT "ADVAPI32.DLL" ALIAS "RegEnableReflectionKey" ( _
   BYVAL hBase AS DWORD _                               ' __in HKEY hBase
 ) AS LONG                                              ' LONG

DECLARE FUNCTION RegQueryReflectionKey IMPORT "ADVAPI32.DLL" ALIAS "RegQueryReflectionKey" ( _
   BYVAL hBase AS DWORD _                               ' __in HKEY hBase
 , BYREF bIsReflectionDisabled AS LONG _                ' __out BOOL *bIsReflectionDisabled
 ) AS LONG                                              ' LONG

DECLARE FUNCTION RegDeleteValueA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteValueA" ( _
   BYVAL hKey AS DWORD  _                               ' __in HKEY hKey
 , OPTIONAL BYREF lpValueName AS ASCIIZ _               ' __in_opt LPCSTR lpValueName
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteValueW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , OPTIONAL BYREF lpValueName AS WSTRINGZ _             ' __in_opt LPCWSTR lpValueName
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteValue = RegDeleteValueW
#ELSE
   MACRO RegDeleteValue = RegDeleteValueA
#ENDIF

DECLARE FUNCTION RegEnumKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegEnumKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpName AS ASCIIZ _                             ' __out LPSTR lpName
 , BYVAL cchName AS DWORD _                             ' __in DWORD cchName
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegEnumKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegEnumKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpName AS WSTRINGZ _                           ' __out LPWSTR lpName
 , BYVAL cchName AS DWORD _                             ' __in DWORD cchName
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegEnumKey = RegEnumKeyW
#ELSE
   MACRO RegEnumKey = RegEnumKeyA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegEnumKeyExA LIB "AdvApi32.dll" ALIAS "RegEnumKeyExA" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS ASCIIZ, _
    lpcbName AS DWORD, lpReserved AS DWORD, lpClass AS ASCIIZ, _
    lpcbClass AS LONG, lpftLastWriteTime AS FILETIME) AS LONG
#ELSE
DECLARE FUNCTION RegEnumKeyExA IMPORT "ADVAPI32.DLL" ALIAS "RegEnumKeyExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpName AS ASCIIZ _                             ' __out LPSTR lpName
 , BYREF lpcchName AS DWORD _                           ' __inout LPDWORD lpcchName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpClass AS ASCIIZ _                   ' __inout LPSTR lpClass
 , OPTIONAL BYREF lpcchClass AS DWORD _                 ' __inout_opt LPDWORD lpcchClass
 , OPTIONAL BYREF lpftLastWriteTime AS FILETIME _       ' __out_opt PFILETIME lpftLastWriteTime
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegEnumKeyExW LIB "AdvApi32.dll" ALIAS "RegEnumKeyExW" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpName AS WSTRINGZ, _
    lpcbName AS DWORD, lpReserved AS DWORD, lpClass AS WSTRINGZ, _
    lpcbClass AS LONG, lpftLastWriteTime AS FILETIME) AS LONG
#ELSE
DECLARE FUNCTION RegEnumKeyExW IMPORT "ADVAPI32.DLL" ALIAS "RegEnumKeyExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpName AS WSTRINGZ _                           ' __out LPWSTR lpName
 , BYREF lpcchName AS DWORD _                           ' __inout LPDWORD lpcchName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpClass AS WSTRINGZ _                 ' __inout LPWSTR lpClass
 , OPTIONAL BYREF lpcchClass AS DWORD _                 ' __inout_opt LPDWORD lpcchClass
 , OPTIONAL BYREF lpftLastWriteTime AS FILETIME _       ' __out_opt PFILETIME lpftLastWriteTime
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RegEnumKeyEx = RegEnumKeyExW
#ELSE
   MACRO RegEnumKeyEx = RegEnumKeyExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegEnumValueA LIB "AdvApi32.dll" ALIAS "RegEnumValueA" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpValueName AS ASCIIZ, _
    lpcbValueName AS DWORD, lpReserved AS DWORD, lpType AS DWORD, _
    lpData AS ANY, lpcbData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegEnumValueA IMPORT "ADVAPI32.DLL" ALIAS "RegEnumValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpValueName AS ASCIIZ _                        ' __out LPSTR lpValueName
 , BYREF lpcchValueName AS DWORD _                      ' __inout LPDWORD lpcchValueName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpType AS DWORD _                     ' __out_opt LPDWORD lpType
 , OPTIONAL BYREF lpData AS ANY _                       ' __out LPBYTE lpData
 , OPTIONAL BYREF lpcbData AS DWORD _                   ' __inout_opt LPDWORD lpcbData
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegEnumValueW LIB "AdvApi32.dll" ALIAS "RegEnumValueW" _
    (BYVAL hKey AS DWORD, BYVAL dwIndex AS DWORD, lpValueName AS WSTRINGZ, _
    lpcbValueName AS DWORD, lpReserved AS DWORD, lpType AS DWORD, _
    lpData AS ANY, lpcbData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegEnumValueW IMPORT "ADVAPI32.DLL" ALIAS "RegEnumValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpValueName AS WSTRINGZ _                      ' __out LPWSTR lpValueName
 , BYREF lpcchValueName AS DWORD _                      ' __inout LPDWORD lpcchValueName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpType AS DWORD _                     ' __out_opt LPDWORD lpType
 , OPTIONAL BYREF lpData AS ANY _                       ' __out LPBYTE lpData
 , OPTIONAL BYREF lpcbData AS DWORD _                   ' __inout_opt LPDWORD lpcbData
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RegEnumValue = RegEnumValueW
#ELSE
   MACRO RegEnumValue = RegEnumValueA
#ENDIF

DECLARE FUNCTION RegFlushKey IMPORT "ADVAPI32.DLL" ALIAS "RegFlushKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegGetKeySecurity LIB "AdvApi32.dll" _
    ALIAS "RegGetKeySecurity" (BYVAL hKey AS DWORD, _
    BYVAL SecurityInformation AS LONG, _
    pSecurityDescriptor AS DWORD, lpcbSecurityDescriptor AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegGetKeySecurity IMPORT "ADVAPI32.DLL" ALIAS "RegGetKeySecurity" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF lpcbSecurityDescriptor AS DWORD _              ' __inout LPDWORD lpcbSecurityDescriptor
 ) AS LONG                                              ' LSTATUS
#ENDIF

DECLARE FUNCTION RegLoadKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegLoadKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYREF lpFile AS ASCIIZ _                             ' __in LPCSTR lpFile
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegLoadKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegLoadKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegLoadKey = RegLoadKeyW
#ELSE
   MACRO RegLoadKey = RegLoadKeyA
#ENDIF

DECLARE FUNCTION RegNotifyChangeKeyValue IMPORT "ADVAPI32.DLL" ALIAS "RegNotifyChangeKeyValue" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL bWatchSubtree AS LONG _                        ' __in BOOL bWatchSubtree
 , BYVAL dwNotifyFilter AS DWORD _                      ' __in DWORD dwNotifyFilter
 , BYVAL hEvent AS DWORD _                              ' __in_opt HANDLE hEvent
 , BYVAL fAsynchronous AS LONG _                        ' __in BOOL fAsynchronous
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOpenKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOpenKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegOpenKey = RegOpenKeyW
#ELSE
   MACRO RegOpenKey = RegOpenKeyA
#ENDIF

DECLARE FUNCTION RegOpenKeyExA IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYVAL ulOptions AS DWORD _                           ' __in_opt DWORD ulOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegOpenKeyExW IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYVAL ulOptions AS DWORD _                           ' __in_opt DWORD ulOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegOpenKeyEx = RegOpenKeyExW
#ELSE
   MACRO RegOpenKeyEx = RegOpenKeyExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegOpenKeyTransactedA LIB "AdvApi32.dll" _
    ALIAS "RegOpenKeyTransactedA" (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, _
    BYVAL ulOptions AS DWORD, BYVAL samDesired AS DWORD, phkResult AS DWORD, _
    BYVAL hTransaction AS DWORD, pExtendedParameter AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegOpenKeyTransactedA IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyTransactedA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYVAL ulOptions AS DWORD _                           ' __in_opt DWORD ulOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParemeter AS DWORD _                  ' __in PVOID pExtendedParemeter
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegOpenKeyTransactedW LIB "AdvApi32.dll" _
    ALIAS "RegOpenKeyTransactedW" (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, _
    BYVAL ulOptions AS DWORD, BYVAL samDesired AS DWORD, phkResult AS DWORD, _
    BYVAL hTransaction AS DWORD, pExtendedParameter AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegOpenKeyTransactedW IMPORT "ADVAPI32.DLL" ALIAS "RegOpenKeyTransactedW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYVAL ulOptions AS DWORD _                           ' __in_opt DWORD ulOptions
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYREF phkResult AS DWORD _                           ' __out PHKEY phkResult
 , BYVAL hTransaction AS DWORD _                        ' __in HANDLE hTransaction
 , BYVAL pExtendedParemeter AS DWORD _                  ' __in PVOID pExtendedParemeter
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RegOpenKeyTransacted = RegOpenKeyTransactedW
#ELSE
   MACRO RegOpenKeyTransacted = RegOpenKeyTransactedA
#ENDIF

DECLARE FUNCTION RegQueryInfoKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegQueryInfoKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpClass AS ASCIIZ _                            ' __out LPSTR lpClass
 , OPTIONAL BYREF lpcchClass AS DWORD _                 ' __inout_opt LPDWORD lpcchClass
 , OPTIONAL BYREF lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpcSubKeys AS DWORD _                 ' __out_opt LPDWORD lpcSubKeys
 , OPTIONAL BYREF lpcbMaxSubKeyLen AS DWORD _           ' __out_opt LPDWORD lpcbMaxSubKeyLen
 , OPTIONAL BYREF lpcbMaxClassLen AS DWORD _            ' __out_opt LPDWORD lpcbMaxClassLen
 , OPTIONAL BYREF lpcValues AS DWORD _                  ' __out_opt LPDWORD lpcValues
 , OPTIONAL BYREF lpcbMaxValueNameLen AS DWORD _        ' __out_opt LPDWORD lpcbMaxValueNameLen
 , OPTIONAL BYREF lpcbMaxValueLen AS DWORD _            ' __out_opt LPDWORD lpcbMaxValueLen
 , OPTIONAL BYREF lpcbSecurityDescriptor AS DWORD _     ' __out_opt LPDWORD lpcbSecurityDescriptor
 , OPTIONAL BYREF lpftLastWriteTime AS FILETIME _       ' __out_opt PFILETIME lpftLastWriteTime
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegQueryInfoKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegQueryInfoKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpClass AS WSTRINGZ _                          ' __out LPWSTR lpClass
 , OPTIONAL BYREF lpcchClass AS DWORD _                 ' __inout_opt LPDWORD lpcchClass
 , OPTIONAL BYREF lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpcSubKeys AS DWORD _                 ' __out_opt LPDWORD lpcSubKeys
 , OPTIONAL BYREF lpcbMaxSubKeyLen AS DWORD _           ' __out_opt LPDWORD lpcbMaxSubKeyLen
 , OPTIONAL BYREF lpcbMaxClassLen AS DWORD _            ' __out_opt LPDWORD lpcbMaxClassLen
 , OPTIONAL BYREF lpcValues AS DWORD _                  ' __out_opt LPDWORD lpcValues
 , OPTIONAL BYREF lpcbMaxValueNameLen AS DWORD _        ' __out_opt LPDWORD lpcbMaxValueNameLen
 , OPTIONAL BYREF lpcbMaxValueLen AS DWORD _            ' __out_opt LPDWORD lpcbMaxValueLen
 , OPTIONAL BYREF lpcbSecurityDescriptor AS DWORD _     ' __out_opt LPDWORD lpcbSecurityDescriptor
 , OPTIONAL BYREF lpftLastWriteTime AS FILETIME _       ' __out_opt PFILETIME lpftLastWriteTime
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegQueryInfoKey = RegQueryInfoKeyW
#ELSE
   MACRO RegQueryInfoKey = RegQueryInfoKeyA
#ENDIF

DECLARE FUNCTION RegQueryValueA IMPORT "ADVAPI32.DLL" ALIAS "RegQueryValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , OPTIONAL BYREF lpData AS ASCIIZ _                    ' __out_opt LPSTR lpData
 , OPTIONAL BYREF lpcbData AS LONG _                    ' __inout_opt PLONG lpcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegQueryValueW IMPORT "ADVAPI32.DLL" ALIAS "RegQueryValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , OPTIONAL BYREF lpData AS WSTRINGZ _                  ' __out_opt LPWSTR lpData
 , OPTIONAL BYREF lpcbData AS LONG _                    ' __inout_opt PLONG lpcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegQueryValue = RegQueryValueW
#ELSE
   MACRO RegQueryValue = RegQueryValueA
#ENDIF

'#if(WINVER >= 0x0400)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegQueryMultipleValuesA LIB "AdvApi32.dll" _
    ALIAS "RegQueryMultipleValuesA" (BYVAL hKey AS DWORD, _
    BYVAL pvallist AS VALENTA PTR, BYVAL numvals AS DWORD, _
    lpValueBuf AS ASCIIZ, pdwTotSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegQueryMultipleValuesA IMPORT "ADVAPI32.DLL" ALIAS "RegQueryMultipleValues" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF val_list AS VALENTA _                          ' __out PVALENTA val_list
 , BYVAL num_vals AS DWORD _                            ' __in DWORD num_vals
 , OPTIONAL BYREF lpValueBuf AS ASCIIZ _                ' __out_opt LPSTR lpValueBuf
 , OPTIONAL BYREF ldwTotsize AS DWORD _                 ' __inout_opt LPDWORD ldwTotsize
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegQueryMultipleValuesW LIB "AdvApi32.dll" _
    ALIAS "RegQueryMultipleValuesW" (BYVAL hKey AS DWORD, _
    BYVAL pvallist AS VALENTW PTR, BYVAL numvals AS DWORD, _
    lpValueBuf AS WSTRINGZ, pdwTotSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegQueryMultipleValuesW IMPORT "ADVAPI32.DLL" ALIAS "RegQueryMultipleValuesW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF val_list AS VALENTW _                          ' __out PVALENTW val_list
 , BYVAL num_vals AS DWORD _                            ' __in DWORD num_vals
 , OPTIONAL BYREF lpValueBuf AS WSTRINGZ _              ' __out_opt LPWSTR lpValueBuf
 , OPTIONAL BYREF ldwTotsize AS DWORD _                 ' __inout_opt LPDWORD ldwTotsize
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RegQueryMultipleValues = RegQueryMultipleValuesW
#ELSE
   MACRO RegQueryMultipleValues = RegQueryMultipleValuesA
#ENDIF

DECLARE FUNCTION RegQueryValueExA IMPORT "ADVAPI32.DLL" ALIAS "RegQueryValueExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , OPTIONAL BYREF lpValueName AS ASCIIZ _               ' __in_opt LPCSTR lpValueName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpType AS DWORD _                     ' __out_opt LPDWORD lpType
 , OPTIONAL BYREF lpData AS ANY _                       ' __out_opt LPBYTE lpData
 , OPTIONAL BYREF lpcbData AS DWORD _                   ' __inout_opt LPDWORD lpcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegQueryValueExW IMPORT "ADVAPI32.DLL" ALIAS "RegQueryValueExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , OPTIONAL BYREF lpValueName AS WSTRINGZ _             ' __in_opt LPCWSTR lpValueName
 , OPTIONAL BYVAL lpReserved AS DWORD _                 ' __in LPDWORD lpReserved
 , OPTIONAL BYREF lpType AS DWORD _                     ' __out_opt LPDWORD lpType
 , OPTIONAL BYREF lpData AS ANY _                       ' __out_opt LPBYTE lpData
 , OPTIONAL BYREF lpcbData AS DWORD _                   ' __inout_opt LPDWORD lpcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegQueryValueEx = RegQueryValueExW
#ELSE
   MACRO RegQueryValueEx = RegQueryValueExA
#ENDIF

DECLARE FUNCTION RegReplaceKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegReplaceKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYREF lpNewFile AS ASCIIZ _                          ' __in LPCSTR lpNewFile
 , BYREF lpOldFile AS ASCIIZ _                          ' __in LPCSTR lpOldFile
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegReplaceKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegReplaceKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYREF lpNewFile AS WSTRINGZ _                        ' __in LPCWSTR lpNewFile
 , BYREF lpOldFile AS WSTRINGZ _                        ' __in LPCWSTR lpOldFile
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegReplaceKey = RegReplaceKeyW
#ELSE
   MACRO RegReplaceKey = RegReplaceKeyA
#ENDIF

DECLARE FUNCTION RegRestoreKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegRestoreKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpFile AS ASCIIZ _                             ' __in LPCSTR lpFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegRestoreKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegRestoreKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegRestoreKey = RegRestoreKeyW
#ELSE
   MACRO RegRestoreKey = RegRestoreKeyA
#ENDIF

'#if(WINVER >= 0x0600)

DECLARE FUNCTION RegRenameKey IMPORT "ADVAPI32.DLL" ALIAS "RegRenameKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKeyName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpSubKeyName
 , BYREF lpNewKeyName AS WSTRINGZ _                     ' __in LPCWSTR lpNewKeyName
 ) AS LONG                                              ' LSTATUS

'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION RegSaveKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegSaveKeyA" ( _
   BYVAL hKey AS DWORD _                              ' __in HKEY hKey
 , BYREF lpFile AS ASCIIZ _                           ' __in LPCSTR lpFile
 , OPTIONAL BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _ ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegSaveKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegSaveKeyW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 , OPTIONAL BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _ ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegSaveKey = RegSaveKeyW
#ELSE
   MACRO RegSaveKey = RegSaveKeyA
#ENDIF

DECLARE FUNCTION RegSetKeySecurity IMPORT "ADVAPI32.DLL" ALIAS "RegSetKeySecurity" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegSetValueA IMPORT "ADVAPI32.DLL" ALIAS "RegSetValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF lpData AS ASCIIZ _                             ' __in LPCSTR lpData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegSetValueW IMPORT "ADVAPI32.DLL" ALIAS "RegSetValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF lpData AS WSTRINGZ _                           ' __in LPCWSTR lpData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegSetValue = RegSetValueW
#ELSE
   MACRO RegSetValue = RegSetValueA
#ENDIF

DECLARE FUNCTION RegSetValueExA IMPORT "ADVAPI32.DLL" ALIAS "RegSetValueExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpValueName AS ASCIIZ _                        ' __in_opt LPCSTR lpValueName
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF lpData AS ANY _                                ' __in CONST BYTE* lpData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegSetValueExW IMPORT "ADVAPI32.DLL" ALIAS "RegSetValueExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpValueName AS WSTRINGZ _                      ' __in_opt LPCWSTR lpValueName
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF lpData AS ANY _                                ' __in CONST BYTE* lpData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegSetValueEx = RegSetValueExW
#ELSE
   MACRO RegSetValueEx = RegSetValueExA
#ENDIF

DECLARE FUNCTION RegUnLoadKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegUnLoadKeyA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , OPTIONAL BYREF lpSubKey AS ASCIIZ _                  ' __in_opt LPCSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegUnLoadKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegUnLoadKeyW" ( _
   BYVAL hKey AS DWORD  _                               ' __in HKEY hKey
 , OPTIONAL BYREF lpSubKey AS WSTRINGZ _                ' __in_opt LPCWSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegUnLoadKey = RegUnLoadKeyW
#ELSE
   MACRO RegUnLoadKey = RegUnLoadKeyA
#ENDIF

'//
'// Utils wrappers
'//
'#if _WIN32_WINNT >= 0x0600

DECLARE FUNCTION RegDeleteKeyValueA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY   hKey
 , OPTIONAL BYREF lpSubKey AS ASCIIZ _                  ' __in_opt LPCSTR lpSubKey
 , OPTIONAL BYREF lpValueName AS ASCIIZ _               ' __in_opt LPCSTR lpValueName
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteKeyValueW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteKeyValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY    hKey
 , OPTIONAL BYREF lpSubKey AS WSTRINGZ _                ' __in_opt LPCWSTR lpSubKey
 , OPTIONAL BYREF lpValueName AS WSTRINGZ _             ' __in_opt LPCWSTR lpValueName
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteKeyValue = RegDeleteKeyValueW
#ELSE
   MACRO RegDeleteKeyValue = RegDeleteKeyValueA
#ENDIF

DECLARE FUNCTION RegSetKeyValueA IMPORT "ADVAPI32.DLL" ALIAS "RegSetKeyValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY    hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR  lpSubKey
 , BYREF lpValueName AS ASCIIZ _                        ' __in_opt LPCSTR  lpValueName
 , BYVAL dwType AS DWORD _                              ' __in     DWORD   dwType
 , BYREF lpData AS ANY _                                ' __in_opt LPCVOID lpData
 , BYVAL cbData AS DWORD _                              ' __in     DWORD   cbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegSetKeyValueW IMPORT "ADVAPI32.DLL" ALIAS "RegSetKeyValueW" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY    hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYREF lpValueName AS WSTRINGZ _                      ' __in_opt LPCWSTR lpValueName
 , BYVAL dwType AS DWORD _                              ' __in     DWORD   dwType
 , BYREF lpData AS ANY _                                ' __in_opt LPCVOID lpData
 , BYVAL cbData AS DWORD _                              ' __in     DWORD   cbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegSetKeyValue = RegSetKeyValueW
#ELSE
   MACRO RegSetKeyValue = RegSetKeyValueA
#ENDIF

DECLARE FUNCTION RegDeleteTreeA IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteTreeA" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY   hKey
 , OPTIONAL BYREF lpSubKey AS ASCIIZ _                  ' __in_opt LPCSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegDeleteTreeW IMPORT "ADVAPI32.DLL" ALIAS "RegDeleteTreeW" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY    hKey
 , OPTIONAL BYREF lpSubKey AS WSTRINGZ _                ' __in_opt LPCWSTR lpSubKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegDeleteTree = RegDeleteTreeW
#ELSE
   MACRO RegDeleteTree = RegDeleteTreeA
#ENDIF

DECLARE FUNCTION RegCopyTreeA IMPORT "ADVAPI32.DLL" ALIAS "RegCopyTreeA" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY   hKey
 , BYREF lpSubKey AS ASCIIZ _                           ' __in_opt LPCSTR lpSubKey
 , BYVAL hKeyDest AS DWORD _                            ' __in     HKEY   hKeyDest
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegCopyTreeW IMPORT "ADVAPI32.DLL" ALIAS "RegCopyTreeW" ( _
   BYVAL hKey AS DWORD _                                ' __in     HKEY    hKey
 , BYREF lpSubKey AS WSTRINGZ _                         ' __in_opt LPCWSTR lpSubKey
 , BYVAL hKeyDest AS DWORD _                            ' __in     HKEY    hKeyDest
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegCopyTree = RegCopyTreeW
#ELSE
   MACRO RegCopyTree = RegCopyTreeA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegGetValueA LIB "AdvApi32.dll" ALIAS "RegGetValueA" _
    (BYVAL hKey AS DWORD, lpSubKey AS ASCIIZ, lpValue AS ASCIIZ, _
    BYVAL dwFlags AS DWORD, pdwType AS DWORD, pvData AS DWORD, _
    pcbData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegGetValueA IMPORT "ADVAPI32.DLL" ALIAS "RegGetValueA" ( _
   BYVAL hKey AS DWORD _                                ' __in         HKEY    hkey
 , OPTIONAL BYREF lpSubKey AS ASCIIZ _                  ' __in_opt     LPCSTR  lpSubKey
 , OPTIONAL BYREF lpValue AS ASCIIZ _                   ' __in_opt     LPCSTR  lpValue
 , OPTIONAL BYVAL dwFlags AS DWORD _                    ' __in_opt     DWORD   dwFlags
 , OPTIONAL BYREF pdwType AS DWORD _                    ' __out_opt    LPDWORD pdwType
 , OPTIONAL BYREF pvData AS ANY _                       ' __out_opt    PVOID   pvData
 , OPTIONAL BYREF pcbData AS DWORD _                    ' __inout_opt LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegGetValueW LIB "AdvApi32.dll" ALIAS "RegGetValueW" _
    (BYVAL hKey AS DWORD, lpSubKey AS WSTRINGZ, lpValue AS WSTRINGZ, _
    BYVAL dwFlags AS DWORD, pdwType AS DWORD, pvData AS DWORD, _
    pcbData AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegGetValueW IMPORT "ADVAPI32.DLL" ALIAS "RegGetValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in         HKEY    hkey
 , OPTIONAL BYREF lpSubKey AS WSTRINGZ _                ' __in_opt     LPCWSTR lpSubKey
 , OPTIONAL BYREF lpValue AS WSTRINGZ _                 ' __in_opt     LPCWSTR lpValue
 , OPTIONAL BYVAL dwFlags AS DWORD _                    ' __in_opt     DWORD   dwFlags
 , OPTIONAL BYREF pdwType AS DWORD _                    ' __out_opt    LPDWORD pdwType
 , OPTIONAL BYREF pvData AS ANY _                       ' __out_opt    PVOID   pvData
 , OPTIONAL BYREF pcbData AS DWORD _                    ' __inout_opt  LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO RegGetValue = RegGetValueW
#ELSE
   MACRO RegGetValue = RegGetValueA
#ENDIF

DECLARE FUNCTION RegLoadMUIStringA IMPORT "ADVAPI32.DLL" ALIAS "RegLoadMUIStringA" ( _
   BYVAL hKey AS DWORD _                                ' __in      HKEY      hKey
 , BYREF pszValue AS ASCIIZ _                           ' __in_opt  LPCSTR    pszValue
 , BYREF pszOutBuf AS ASCIIZ _                          ' __out_opt LPSTR     pszOutBuf
 , BYVAL cbOutBuf AS DWORD _                            ' __in      DWORD     cbOutBuf
 , BYREF pcbData AS DWORD _                             ' __out_opt LPDWORD   pcbData
 , BYVAL Flags AS DWORD _                               ' __in      DWORD     Flags
 , OPTIONAL BYREF pszDirectory AS ASCIIZ _              ' __in_opt  LPCSTR    pszDirectory
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegLoadMUIStringW IMPORT "ADVAPI32.DLL" ALIAS "RegLoadMUIStringW" ( _
   BYVAL hKey AS DWORD _                                ' __in      HKEY      hKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in_opt  LPCWSTR   pszValue
 , BYREF pszOutBuf AS WSTRINGZ _                        ' __out_opt LPWSTR    pszOutBuf
 , BYVAL cbOutBuf AS DWORD _                            ' __in      DWORD     cbOutBuf
 , BYREF pcbData AS DWORD _                             ' __out_opt LPDWORD   pcbData
 , BYVAL Flags AS DWORD _                               ' __in      DWORD     Flags
 , OPTIONAL BYREF pszDirectory AS WSTRINGZ _            ' __in_opt  LPCWSTR   pszDirectory
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegLoadMUIString = RegLoadMUIStringW
#ELSE
   MACRO RegLoadMUIString = RegLoadMUIStringA
#ENDIF

DECLARE FUNCTION RegLoadAppKeyA IMPORT "ADVAPI32.DLL" ALIAS "RegLoadAppKeyA" ( _
   BYREF lpFile AS ASCIIZ _                             ' __in  LPCSTR  lpFile
 , BYREF phkResult AS DWORD _                           ' __out PHKEY   phkResult
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM  samDesired
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD   dwOptions
 , BYVAL Reserved AS DWORD _                            ' __in  DWORD   Reserved
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION RegLoadAppKeyW IMPORT "ADVAPI32.DLL" ALIAS "RegLoadAppKeyW" ( _
   BYREF lpFile AS WSTRINGZ _                           ' __in  LPCWSTR  lpFile
 , BYREF phkResult AS DWORD _                           ' __out PHKEY    phkResult
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM   samDesired
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD    dwOptions
 , BYVAL Reserved AS DWORD _                            ' __in  DWORD    Reserved
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO RegLoadAppKey = RegLoadAppKeyW
#ELSE
   MACRO RegLoadAppKey = RegLoadAppKeyA
#ENDIF

'#endif // _WIN32_WINNT >= 0x0600

'//
'// Remoteable System Shutdown APIs
'//

DECLARE FUNCTION InitiateSystemShutdownA IMPORT "ADVAPI32.DLL" ALIAS "InitiateSystemShutdownA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPSTR lpMachineName
 , BYREF lpMessage AS ASCIIZ _                          ' __in_opt LPSTR lpMessage
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL bForceAppsClosed AS LONG _                     ' __in BOOL bForceAppsClosed
 , BYVAL bRebootAfterShutdown AS LONG _                 ' __in BOOL bRebootAfterShutdown
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitiateSystemShutdownW IMPORT "ADVAPI32.DLL" ALIAS "InitiateSystemShutdownW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPWSTR lpMachineName
 , BYREF lpMessage AS WSTRINGZ _                        ' __in_opt LPWSTR lpMessage
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL bForceAppsClosed AS LONG _                     ' __in BOOL bForceAppsClosed
 , BYVAL bRebootAfterShutdown AS LONG _                 ' __in BOOL bRebootAfterShutdown
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InitiateSystemShutdown = InitiateSystemShutdownW
#ELSE
   MACRO InitiateSystemShutdown = InitiateSystemShutdownA
#ENDIF

DECLARE FUNCTION AbortSystemShutdownA IMPORT "ADVAPI32.DLL" ALIAS "AbortSystemShutdownA" ( _
   OPTIONAL BYREF lpMachineName AS ASCIIZ _             ' __in_opt LPSTR lpMachineName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AbortSystemShutdownW IMPORT "ADVAPI32.DLL" ALIAS "AbortSystemShutdownW" ( _
   OPTIONAL BYREF lpMachineName AS WSTRINGZ _           ' __in_opt LPWSTR lpMachineName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AbortSystemShutdown = AbortSystemShutdownW
#ELSE
   MACRO AbortSystemShutdown = AbortSystemShutdownA
#ENDIF

'//
'// defines for InitiateSystemShutdownEx reason codes
'//

#INCLUDE ONCE "reason.inc"

'//
'// Then for Historical reasons support some old symbols, internal only

%REASON_SWINSTALL    = %SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_INSTALLATION
%REASON_HWINSTALL    = %SHTDN_REASON_MAJOR_HARDWARE OR %SHTDN_REASON_MINOR_INSTALLATION
%REASON_SERVICEHANG  = %SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_HUNG
%REASON_UNSTABLE     = %SHTDN_REASON_MAJOR_SYSTEM OR %SHTDN_REASON_MINOR_UNSTABLE
%REASON_SWHWRECONF   = %SHTDN_REASON_MAJOR_SOFTWARE OR %SHTDN_REASON_MINOR_RECONFIG
%REASON_OTHER        = %SHTDN_REASON_MAJOR_OTHER OR %SHTDN_REASON_MINOR_OTHER
%REASON_UNKNOWN      = %SHTDN_REASON_UNKNOWN
%REASON_LEGACY_API   = %SHTDN_REASON_LEGACY_API
%REASON_PLANNED_FLAG = %SHTDN_REASON_FLAG_PLANNED

'//
'// MAX Shutdown TimeOut == 10 Years in seconds
'//
%MAX_SHUTDOWN_TIMEOUT = (10*365*24*60*60)

DECLARE FUNCTION InitiateSystemShutdownExA IMPORT "ADVAPI32.DLL" ALIAS "InitiateSystemShutdownExA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPSTR lpMachineName
 , BYREF lpMessage AS ASCIIZ _                          ' __in_opt LPSTR lpMessage
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL bForceAppsClosed AS LONG _                     ' __in BOOL bForceAppsClosed
 , BYVAL bRebootAfterShutdown AS LONG _                 ' __in BOOL bRebootAfterShutdown
 , BYVAL dwReason AS DWORD _                            ' __in DWORD dwReason
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitiateSystemShutdownExW IMPORT "ADVAPI32.DLL" ALIAS "InitiateSystemShutdownExW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPWSTR lpMachineName
 , BYREF lpMessage AS WSTRINGZ _                        ' __in_opt LPWSTR lpMessage
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYVAL bForceAppsClosed AS LONG _                     ' __in BOOL bForceAppsClosed
 , BYVAL bRebootAfterShutdown AS LONG _                 ' __in BOOL bRebootAfterShutdown
 , BYVAL dwReason AS DWORD _                            ' __in DWORD dwReason
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InitiateSystemShutdownEx = InitiateSystemShutdownExW
#ELSE
   MACRO InitiateSystemShutdownEx = InitiateSystemShutdownExA
#ENDIF

'//
'// Shutdown flags
'//

%SHUTDOWN_FORCE_OTHERS         = &H00000001???
%SHUTDOWN_FORCE_SELF           = &H00000002???
%SHUTDOWN_RESTART              = &H00000004???
%SHUTDOWN_POWEROFF             = &H00000008???
%SHUTDOWN_NOREBOOT             = &H00000010???
%SHUTDOWN_GRACE_OVERRIDE       = &H00000020???
%SHUTDOWN_INSTALL_UPDATES      = &H00000040???
%SHUTDOWN_RESTARTAPPS          = &H00000080???
%SHUTDOWN_SKIP_SVC_PRESHUTDOWN = &H00000100???

DECLARE FUNCTION InitiateShutdownA IMPORT "ADVAPI32.DLL" ALIAS "InitiateShutdownA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPSTR lpMachineName
 , BYREF lpMessage AS ASCIIZ _                          ' __in_opt LPSTR lpMessage
 , BYVAL dwGracePeriod AS DWORD _                       ' __in     DWORD dwGracePeriod
 , BYVAL dwShutdownFlags AS DWORD _                     ' __in     DWORD dwShutdownFlags
 , BYVAL dwReason AS DWORD _                            ' __in     DWORD dwReason
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InitiateShutdownW IMPORT "ADVAPI32.DLL" ALIAS "InitiateShutdownW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPWSTR lpMachineName
 , BYREF lpMessage AS WSTRINGZ _                        ' __in_opt LPWSTR lpMessage
 , BYVAL dwGracePeriod AS DWORD _                       ' __in     DWORD dwGracePeriod
 , BYVAL dwShutdownFlags AS DWORD _                     ' __in     DWORD dwShutdownFlags
 , BYVAL dwReason AS DWORD _                            ' __in     DWORD dwReason
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO InitiateShutdown = InitiateShutdownW
#ELSE
   MACRO InitiateShutdown = InitiateShutdownA
#ENDIF

DECLARE FUNCTION RegSaveKeyExA IMPORT "ADVAPI32.DLL" ALIAS "RegSaveKeyExA" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpFile AS ASCIIZ _                             ' __in LPCSTR lpFile
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' LONG

DECLARE FUNCTION RegSaveKeyExW IMPORT "ADVAPI32.DLL" ALIAS "RegSaveKeyExW" ( _
   BYVAL hKey AS DWORD _                                ' __in HKEY hKey
 , BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO RegSaveKeyEx = RegSaveKeyExW
#ELSE
   MACRO RegSaveKeyEx = RegSaveKeyExA
#ENDIF

' // Removed in Windows 7 SDK
'DECLARE FUNCTION Wow64Win32ApiEntry IMPORT "ADVAPI32.DLL" ALIAS "Wow64Win32ApiEntry" ( _
'   BYVAL dwFuncNumber AS DWORD _                        ' __in DWORD dwFuncNumber
' , BYVAL dwFlag AS DWORD _                              ' __in DWORD dwFlag
' , BYVAL dwRes AS DWORD _                               ' __in DWORD dwRes
' ) AS LONG                                              ' LONG
