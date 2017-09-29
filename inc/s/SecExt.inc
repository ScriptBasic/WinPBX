' ########################################################################################
' Microsoft Windows
' File: SecExt.inc
' Contents: Security function prototypes for functions not part of the SSPI interface.
' This file should not be directly included - include security.inc instead.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SECEXT_INC = 1

'//
'// Extended Name APIs for ADS
'//


'typedef enum
'{
'    // Examples for the following formats assume a fictitous company
'    // which hooks into the global X.500 and DNS name spaces as follows.
'    //
'    // Enterprise root domain in DNS is
'    //
'    //      widget.com
'    //
'    // Enterprise root domain in X.500 (RFC 1779 format) is
'    //
'    //      O=Widget, C=US
'    //
'    // There exists the child domain
'    //
'    //      engineering.widget.com
'    //
'    // equivalent to
'    //
'    //      OU=Engineering, O=Widget, C=US
'    //
'    // There exists a container within the Engineering domain
'    //
'    //      OU=Software, OU=Engineering, O=Widget, C=US
'    //
'    // There exists the user
'    //
'    //      CN=John Doe, OU=Software, OU=Engineering, O=Widget, C=US
'    //
'    // And this user's downlevel (pre-ADS) user name is
'    //
'    //      Engineering\JohnDoe

'    // unknown name type
'    NameUnknown = 0,

'    // CN=John Doe, OU=Software, OU=Engineering, O=Widget, C=US
'    NameFullyQualifiedDN = 1,

'    // Engineering\JohnDoe
'    NameSamCompatible = 2,

'    // Probably "John Doe" but could be something else.  I.e. The
'    // display name is not necessarily the defining RDN.
'    NameDisplay = 3,


'    // String-ized GUID as returned by IIDFromString().
'    // eg: {4fa050f0-f561-11cf-bdd9-00aa003a77b6}
'    NameUniqueId = 6,

'    // engineering.widget.com/software/John Doe
'    NameCanonical = 7,

'    // someone@example.com
'    NameUserPrincipal = 8,

'    // Same as NameCanonical except that rightmost '/' is
'    // replaced with '\n' - even in domain-only case.
'    // eg: engineering.widget.com/software\nJohn Doe
'    NameCanonicalEx = 9,

'    // www/srv.engineering.com/engineering.com
'    NameServicePrincipal = 10,

'    // DNS domain name + SAM username
'    // eg: engineering.widget.com\JohnDoe
'    NameDnsDomain = 12

'} EXTENDED_NAME_FORMAT, * PEXTENDED_NAME_FORMAT ;

%NameUnknown          = 0
%NameFullyQualifiedDN = 1
%NameSamCompatible    = 2
%NameDisplay          = 3
%NameUniqueId         = 6
%NameCanonical        = 7
%NameUserPrincipal    = 8
%NameCanonicalEx      = 9
%NameServicePrincipal = 10
%NameDnsDomain        = 12

DECLARE FUNCTION GetUserNameExA IMPORT "SECUR32.DLL" ALIAS "GetUserNameExA" ( _
   BYVAL NameFormat AS LONG _                           ' __in EXTENDED_NAME_FORMAT NameFormat
 , BYREF lpNameBuffer AS ASCIIZ _                       ' __out LPSTR lpNameBuffer
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetUserNameExW IMPORT "SECUR32.DLL" ALIAS "GetUserNameExW" ( _
   BYVAL NameFormat AS LONG _                           ' __in EXTENDED_NAME_FORMAT NameFormat
 , BYREF lpNameBuffer AS WSTRINGZ _                     ' __out LPWSTR lpNameBuffer
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO GetUserNameEx = GetUserNameExW
#ELSE
   MACRO GetUserNameEx = GetUserNameExA
#ENDIF

DECLARE FUNCTION GetComputerObjectNameA IMPORT "SECUR32.DLL" ALIAS "GetComputerObjectNameA" ( _
   BYVAL NameFormat AS LONG _                           ' __in EXTENDED_NAME_FORMAT NameFormat
 , BYREF lpNameBuffer AS ASCIIZ _                       ' __out LPSTR lpNameBuffer
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetComputerObjectNameW IMPORT "SECUR32.DLL" ALIAS "GetComputerObjectNameW" ( _
   BYVAL NameFormat AS LONG _                           ' __in EXTENDED_NAME_FORMAT NameFormat
 , BYREF lpNameBuffer AS WSTRINGZ _                     ' __out LPWSTR lpNameBuffer
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO GetComputerObjectName = GetComputerObjectNameW
#ELSE
   MACRO GetComputerObjectName = GetComputerObjectNameA
#ENDIF

DECLARE FUNCTION TranslateNameA IMPORT "SECUR32.DLL" ALIAS "TranslateNameA" ( _
   BYREF lpAccountName AS ASCIIZ _                      ' __in LPCSTR lpAccountName
 , BYVAL AccountNameFormat AS LONG _                    ' __in EXTENDED_NAME_FORMAT AccountNameFormat
 , BYVAL DesiredNameFormat AS LONG _                    ' __in EXTENDED_NAME_FORMAT DesiredNameFormat
 , BYREF lpTranslatedName AS ASCIIZ _                   ' __out LPSTR lpTranslatedName
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION TranslateNameW IMPORT "SECUR32.DLL" ALIAS "TranslateNameW" ( _
   BYREF lpAccountName AS WSTRINGZ _                    ' __in LPCWSTR lpAccountName
 , BYVAL AccountNameFormat AS LONG _                    ' __in EXTENDED_NAME_FORMAT AccountNameFormat
 , BYVAL DesiredNameFormat AS LONG _                    ' __in EXTENDED_NAME_FORMAT DesiredNameFormat
 , BYREF lpTranslatedName AS WSTRINGZ _                 ' __out LPWSTR lpTranslatedName
 , BYREF nSize AS DWORD _                               ' __inout PULONG nSize
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO TranslateName = TranslateNameW
#ELSE
   MACRO TranslateName = TranslateNameA
#ENDIF
