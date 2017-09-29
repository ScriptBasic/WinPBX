' ########################################################################################
' Microsoft Windows
' File: Security.inc
' Contents: Toplevel include file for security aware components
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SECURITY_INC = 1

'// This file will go out and pull in all the header files that you need,
'// based on defines that you issue.  The following macros are used.
'//
'// SECURITY_KERNEL      Use the kernel interface, not the usermode
'//

'//
'// These are name that can be used to refer to the builtin packages
'//

'#ifndef NTLMSP_NAME_A
'#define NTLMSP_NAME_A            "NTLM"
'#define NTLMSP_NAME              L"NTLM"        // ntifs
'#endif // NTLMSP_NAME

#IF NOT %DEF($NTLMSP_NAME_A)
   $NTLMSP_NAME_A = "NTLM"
   $$NTLMSP_NAME_W = "NTLM"$$
   #IF %DEF(%UNICODE)
      MACRO NTLMSP_NAME = $$NTLMSP_NAME_W
   #ELSE
      MACRO NTLMSP_NAME = $NTLMSP_NAME_A
   #ENDIF
#ENDIF

'#ifndef MICROSOFT_KERBEROS_NAME_A
'#define MICROSOFT_KERBEROS_NAME_A   "Kerberos"
'#define MICROSOFT_KERBEROS_NAME_W   L"Kerberos"
'#ifdef WIN32_CHICAGO
'#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_A
'#else
'#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_W
'#endif
'#endif  // MICROSOFT_KERBEROS_NAME_A

#IF NOT %DEF($MICROSOFT_KERBEROS_NAME_A)
   $MICROSOFT_KERBEROS_NAME_A = "Kerberos"
   $$MICROSOFT_KERBEROS_NAME_W = "Kerberos"$$
   #IF %DEF(%UNICODE)
      MACRO MICROSOFT_KERBEROS_NAME = $$MICROSOFT_KERBEROS_NAME_W
   #ELSE
      MACRO MICROSOFT_KERBEROS_NAME = $MICROSOFT_KERBEROS_NAME_A
   #ENDIF
#ENDIF

'#ifndef NEGOSSP_NAME
'#define NEGOSSP_NAME_W  L"Negotiate"
'#define NEGOSSP_NAME_A  "Negotiate"

'#ifdef UNICODE
'#define NEGOSSP_NAME    NEGOSSP_NAME_W
'#else
'#define NEGOSSP_NAME    NEGOSSP_NAME_A
'#endif
'#endif // NEGOSSP_NAME

#IF NOT %DEF($NEGOSSP_NAME)
   $NEGOSSP_NAME_A = "Negotiate"
   $$NEGOSSP_NAME_W = "Negotiate"$$
   #IF %DEF(%UNICODE)
      MACRO NEGOSSP_NAME = $$NEGOSSP_NAME_W
   #ELSE
      MACRO NEGOSSP_NAME = $NEGOSSP_NAME_A
   #ENDIF
#ENDIF

'//
'// Include the master SSPI header file
'//

#INCLUDE ONCE "sspi.inc"

'#if defined(SECURITY_WIN32) || defined(SECURITY_KERNEL)
'#include <secext.h>
'#endif

#INCLUDE ONCE "secext.inc"

'//
'// Include the error codes:
'//

' NOTE: Do not include it. They are for 16-bit.
' These error codes (for 32-bit) are already defined in WinErr.inc

'#if ISSP_LEVEL == 16
'#include <issper16.h>
'#endif
