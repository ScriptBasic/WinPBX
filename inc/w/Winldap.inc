' ########################################################################################
' Microsoft Windows
' File: Winldap.inc
' Contents: LDAP client 32 API header file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINLDAP_INC = 1

'/*++

'Copyright (c) 1996-1999  Microsoft Corporation

'Module Name:

'    winldap.h   LDAP client 32 API header file

'Abstract:

'   This module is the header file for the 32 bit LDAP client API for
'   Windows NT and Windows 95.  This API is based on RFC 1823 with some
'   enhancements for LDAP v3.

'   Notes about Unicode support :

'   If you have UNICODE defined at compile time, you'll pull in the unicode
'   versions of the calls.  Note that your executable may then not work with
'   other implementations of the LDAP API that don't support Unicode.  If
'   UNICODE is not defined, then we define the LDAP calls without the trailing
'   'A' (as in ldap_bind rather than ldap_bindA) so that your app may work
'   with other implementations that don't support Unicode.

'   The import library has all three forms of the call present... ldap_bindW,
'   ldap_bindA, and ldap_bind.  ldap_bindA simply calls ldap_bind.  ldap_bind
'   simply converts the arguments to unicode and calls ldap_bindW.  The
'   reason this is done is because we have to put UTF-8 on the wire, so if
'   we converted from Unicode to single byte, we'd loose information.  Since
'   all core processing is done in Unicode, nothing is lost.

'Updates :

'   11/01/96  Modified for new API RFC draft.

'Environments :

'    Win32 user mode

'--*/

'//
'//  Only pull in this header file once... controlled by LDAP_CLIENT_DEFINED
'//  variable.
'//

'#ifndef LDAP_CLIENT_DEFINED
'#define LDAP_CLIENT_DEFINED

#INCLUDE ONCE "windows.inc"

'#ifndef BASETYPES
'#include <windef.h>
'#endif
#INCLUDE ONCE "windef.inc"

'#ifndef _SCHNLSP_H_
'#include <schnlsp.h>
'#endif
#INCLUDE ONCE "schnlsp.inc"

'#if !defined(_WINLDAP_)
'#define WINLDAPAPI DECLSPEC_IMPORT
'#else
'//#define WINLDAPAPI __declspec(dllexport)
'#define WINLDAPAPI
'#endif

'#ifndef LDAPAPI
'#define LDAPAPI __cdecl
'#endif

'//
'//  The #define LDAP_UNICODE controls if we map the undecorated calls to
'//  their unicode counterparts or just leave them defined as the normal
'//  single byte entry points.
'//
'//  If you want to write a UNICODE enabled application, you'd normally
'//  just have UNICODE defined and then we'll default to using all LDAP
'//  Unicode calls.
'//

'#ifndef LDAP_UNICODE
'#ifdef UNICODE
'#define LDAP_UNICODE 1
'#else
'#define LDAP_UNICODE 0
'#endif
'#endif

'//
'//  Global constants
'//

%LDAP_PORT              = 389
%LDAP_SSL_PORT          = 636
%LDAP_GC_PORT           = 3268
%LDAP_SSL_GC_PORT       = 3269

'//
'// The default version of the API is 2. If required, the user MUST set the
'// version to 3 using the LDAP_OPT_VERSION option.
'//

%LDAP_VERSION1          = 1
%LDAP_VERSION2          = 2
%LDAP_VERSION3          = 3
%LDAP_VERSION           = %LDAP_VERSION2

'//
'//  All tags are CCFTTTTT.
'//               CC        Tag Class 00 = universal
'//                                   01 = application wide
'//                                   10 = context specific
'//                                   11 = private use
'//
'//                 F       Form 0 primitive
'//                              1 constructed
'//
'//                  TTTTT  Tag Number
'//

'//
'// LDAP v2 & v3 commands.
'//

%LDAP_BIND_CMD           = &H60&  ' // application + constructed
%LDAP_UNBIND_CMD         = &H42&  ' // application + primitive
%LDAP_SEARCH_CMD         = &H63&  ' // application + constructed
%LDAP_MODIFY_CMD         = &H66&  ' // application + constructed
%LDAP_ADD_CMD            = &H68&  ' // application + constructed
%LDAP_DELETE_CMD         = &H4a&  ' // application + primitive
%LDAP_MODRDN_CMD         = &H6c&  ' // application + constructed
%LDAP_COMPARE_CMD        = &H6e&  ' // application + constructed
%LDAP_ABANDON_CMD        = &H50&  ' // application + primitive
%LDAP_SESSION_CMD        = &H71&  ' // not in base LDAP protocol
%LDAP_EXTENDED_CMD       = &H77&  ' // application + constructed

'//
'// Responses/Results for LDAP v2 & v3
'//

%LDAP_RES_BIND           = &H61&  ' // application + constructed
%LDAP_RES_SEARCH_ENTRY   = &H64&  ' // application + constructed
%LDAP_RES_SEARCH_RESULT  = &H65&  ' // application + constructed
%LDAP_RES_MODIFY         = &H67&  ' // application + constructed
%LDAP_RES_ADD            = &H69&  ' // application + constructed
%LDAP_RES_DELETE         = &H6b&  ' // application + constructed
%LDAP_RES_MODRDN         = &H6d&  ' // application + constructed
%LDAP_RES_COMPARE        = &H6f&  ' // application + constructed
%LDAP_RES_SESSION        = &H72&  ' // not in base LDAP protocol
%LDAP_RES_REFERRAL       = &H73&  ' // application + constructed
%LDAP_RES_EXTENDED       = &H78&  ' // application + constructed

%LDAP_RES_ANY            = -1&

%LDAP_INVALID_CMD        = &Hff&
%LDAP_INVALID_RES        = &Hff&


'//
'// We'll make the error codes compatible with reference implementation
'//

' enum LDAP_RETCODE
%LDAP_SUCCESS                    = &H00&
%LDAP_OPERATIONS_ERROR           = &H01&
%LDAP_PROTOCOL_ERROR             = &H02&
%LDAP_TIMELIMIT_EXCEEDED         = &H03&
%LDAP_SIZELIMIT_EXCEEDED         = &H04&
%LDAP_COMPARE_FALSE              = &H05&
%LDAP_COMPARE_TRUE               = &H06&
%LDAP_AUTH_METHOD_NOT_SUPPORTED  = &H07&
%LDAP_STRONG_AUTH_REQUIRED       = &H08&
%LDAP_REFERRAL_V2                = &H09&
%LDAP_PARTIAL_RESULTS            = &H09&
%LDAP_REFERRAL                   = &H0a&
%LDAP_ADMIN_LIMIT_EXCEEDED       = &H0b&
%LDAP_UNAVAILABLE_CRIT_EXTENSION = &H0c&
%LDAP_CONFIDENTIALITY_REQUIRED   = &H0d&
%LDAP_SASL_BIND_IN_PROGRESS      = &H0e&

%LDAP_NO_SUCH_ATTRIBUTE          = &H10&
%LDAP_UNDEFINED_TYPE             = &H11&
%LDAP_INAPPROPRIATE_MATCHING     = &H12&
%LDAP_CONSTRAINT_VIOLATION       = &H13&
%LDAP_ATTRIBUTE_OR_VALUE_EXISTS  = &H14&
%LDAP_INVALID_SYNTAX             = &H15&

%LDAP_NO_SUCH_OBJECT             = &H20&
%LDAP_ALIAS_PROBLEM              = &H21&
%LDAP_INVALID_DN_SYNTAX          = &H22&
%LDAP_IS_LEAF                    = &H23&
%LDAP_ALIAS_DEREF_PROBLEM        = &H24&

%LDAP_INAPPROPRIATE_AUTH         = &H30&
%LDAP_INVALID_CREDENTIALS        = &H31&
%LDAP_INSUFFICIENT_RIGHTS        = &H32&
%LDAP_BUSY                       = &H33&
%LDAP_UNAVAILABLE                = &H34&
%LDAP_UNWILLING_TO_PERFORM       = &H35&
%LDAP_LOOP_DETECT                = &H36&
%LDAP_SORT_CONTROL_MISSING       = &H3C&
%LDAP_OFFSET_RANGE_ERROR         = &H3D&

%LDAP_NAMING_VIOLATION           = &H40&
%LDAP_OBJECT_CLASS_VIOLATION     = &H41&
%LDAP_NOT_ALLOWED_ON_NONLEAF     = &H42&
%LDAP_NOT_ALLOWED_ON_RDN         = &H43&
%LDAP_ALREADY_EXISTS             = &H44&
%LDAP_NO_OBJECT_CLASS_MODS       = &H45&
%LDAP_RESULTS_TOO_LARGE          = &H46&
%LDAP_AFFECTS_MULTIPLE_DSAS      = &H47&

%LDAP_VIRTUAL_LIST_VIEW_ERROR    = &H4c&

%LDAP_OTHER                      = &H50&
%LDAP_SERVER_DOWN                = &H51&
%LDAP_LOCAL_ERROR                = &H52&
%LDAP_ENCODING_ERROR             = &H53&
%LDAP_DECODING_ERROR             = &H54&
%LDAP_TIMEOUT                    = &H55&
%LDAP_AUTH_UNKNOWN               = &H56&
%LDAP_FILTER_ERROR               = &H57&
%LDAP_USER_CANCELLED             = &H58&
%LDAP_PARAM_ERROR                = &H59&
%LDAP_NO_MEMORY                  = &H5a&
%LDAP_CONNECT_ERROR              = &H5b&
%LDAP_NOT_SUPPORTED              = &H5c&
%LDAP_NO_RESULTS_RETURNED        = &H5e&
%LDAP_CONTROL_NOT_FOUND          = &H5d&
%LDAP_MORE_RESULTS_TO_RETURN     = &H5f&

%LDAP_CLIENT_LOOP                = &H60&
%LDAP_REFERRAL_LIMIT_EXCEEDED    = &H61&

'//
'//  Bind methods.  We support the following methods :
'//
'//      Simple         Clear text password... try not to use as it's not secure.
'//
'//      MSN            MSN (Microsoft Network) authentication. This package
'//                     may bring up UI to prompt the user for MSN credentials.
'//
'//      DPA            Normandy authentication... new MSN authentication.  Same
'//                     usage as MSN.
'//
'//      NTLM           NT domain authentication.  Use NULL credentials and
'//                     we'll try to use default logged in user credentials.
'//
'//      Sicily         Negotiate with the server for any of: MSN, DPA, NTLM
'//                     Should be used for LDAPv2 servers only.
'//
'//      Negotiate      Use GSSAPI Negotiate package to negotiate security
'//                     package of either Kerberos v5 or NTLM (or any other
'//                     package the client and server negotiate).  Pass in
'//                     NULL credentials to specify default logged in user.
'//                     If Negotiate package is not installed on server or
'//                     client, this will fall back to Sicily negotiation.
'//
'//  For all bind methods except for Simple, you may pass in a
'//  SEC_WINNT_AUTH_IDENTITY_W (defined in rpcdce.h) or the newer
'//  SEC_WINNT_AUTH_IDENTITY_EXW (defined in secext.h) to specify alternate
'//  credentials.
'//
'//  All bind methods other than simple are synchronous only calls.
'//  Calling the asynchronous bind call for any of these messages will
'//  return LDAP_PARAM_ERROR.
'//
'//  Using any other method besides simple will cause WLDAP32 to pull in
'//  the SSPI security DLLs (SECURITY.DLL etc).
'//
'//  On non-Simple methods, if you specify NULL credentials, we'll attempt to use
'//  the default logged in user.
'//

%LDAP_AUTH_SIMPLE                = &H80&
%LDAP_AUTH_SASL                  = &H83&   ' // don't use... should go away

%LDAP_AUTH_OTHERKIND             = &H86&

'// The SICILY type covers package negotiation to MSN servers.
'// Each of the supported types can also be specified without
'// doing the package negotiation, assuming the caller knows
'// what the server supports.

%LDAP_AUTH_SICILY                = %LDAP_AUTH_OTHERKIND OR &H0200

%LDAP_AUTH_MSN                   = %LDAP_AUTH_OTHERKIND OR &H0800
%LDAP_AUTH_NTLM                  = %LDAP_AUTH_OTHERKIND OR &H1000
%LDAP_AUTH_DPA                   = %LDAP_AUTH_OTHERKIND OR &H2000

'// This will cause the client to use the GSSAPI negotiation
'// package to determine the most appropriate authentication type.
'// This type should be used when talking to NT5.

%LDAP_AUTH_NEGOTIATE             = %LDAP_AUTH_OTHERKIND OR &H0400

'// backward compatible %for older constant name.

%LDAP_AUTH_SSPI                  = %LDAP_AUTH_NEGOTIATE

'//
'// uses the DIGEST-MD5 mechanism.
'//

%LDAP_AUTH_DIGEST                = %LDAP_AUTH_OTHERKIND OR &H4000

'// The external auth mechanism is used upon setting up an SSL/TLS connection
'// to denote that the server must use the client cert credentials presented
'// at the outset of the SSL/TLS connection.


%LDAP_AUTH_EXTERNAL              = %LDAP_AUTH_OTHERKIND OR &H0020

'//
'//  Client applications typically don't have to encode/decode LDAP filters,
'//  but if they do, we define the operators here.
'//
'//  Filter types.

%LDAP_FILTER_AND         = &Ha0&    ' // context specific + constructed - SET OF Filters.
%LDAP_FILTER_OR          = &Ha1&    ' // context specific + constructed - SET OF Filters.
%LDAP_FILTER_NOT         = &Ha2&    ' // context specific + constructed - Filter
%LDAP_FILTER_EQUALITY    = &Ha3&    ' // context specific + constructed - AttributeValueAssertion.
%LDAP_FILTER_SUBSTRINGS  = &Ha4&    ' // context specific + constructed - SubstringFilter
%LDAP_FILTER_GE          = &Ha5&    ' // context specific + constructed - AttributeValueAssertion.
%LDAP_FILTER_LE          = &Ha6&    ' // context specific + constructed - AttributeValueAssertion.
%LDAP_FILTER_PRESENT     = &H87&    ' // context specific + primitive   - AttributeType.
%LDAP_FILTER_APPROX      = &Ha8&    ' // context specific + constructed - AttributeValueAssertion.
%LDAP_FILTER_EXTENSIBLE  = &Ha9&    ' // context specific + constructed - MatchingRuleAssertion.

' //  Substring filter types

%LDAP_SUBSTRING_INITIAL  = &H80&   ' // class context specific
%LDAP_SUBSTRING_ANY      = &H81&   ' // class context specific
%LDAP_SUBSTRING_FINAL    = &H82&   ' // class context specific

'//
'//  Possible values for ld_deref field.
'//      "Never"     - never deref aliases.  return only the alias.
'//      "Searching" - only deref aliases when searching, not when locating
'//                    the base object of a search.
'//      "Finding"   - dereference the alias when locating the base object but
'//                    not during a search.
'//      "Always"    - always dereference aliases.
'//

%LDAP_DEREF_NEVER       = 0
%LDAP_DEREF_SEARCHING   = 1
%LDAP_DEREF_FINDING     = 2
%LDAP_DEREF_ALWAYS      = 3

'//  Special values for ld_sizelimit :

%LDAP_NO_LIMIT          = 0

'//  Flags for ld_options field :

%LDAP_OPT_DNS                = &H00000001???  ' // utilize DN & DNS
%LDAP_OPT_CHASE_REFERRALS    = &H00000002???  ' // chase referrals
%LDAP_OPT_RETURN_REFS        = &H00000004???  ' // return referrals to calling app

'//
'//  LDAP structure per connection
'//

'#if !defined(_WIN64)
'#pragma pack(push, 4)
'#endif

'typedef struct ldap {

'    struct {

'        UINT_PTR sb_sd;

'        UCHAR Reserved1[(10*sizeof(ULONG))+1];

'        ULONG_PTR sb_naddr;   // notzero implies CLDAP available

'        UCHAR Reserved2[(6*sizeof(ULONG))];

'    } ld_sb;

'    //
'    //  Following parameters MAY match up to reference implementation of LDAP
'    //

'    PCHAR   ld_host;
'    ULONG   ld_version;
'    UCHAR   ld_lberoptions;

'    //
'    //  Safe to assume that these parameters are in same location as
'    //  reference implementation of LDAP API.
'    //

'    ULONG   ld_deref;

'    ULONG   ld_timelimit;
'    ULONG   ld_sizelimit;

'    ULONG   ld_errno;
'    PCHAR   ld_matched;
'    PCHAR   ld_error;
'    ULONG   ld_msgid;

'    UCHAR Reserved3[(6*sizeof(ULONG))+1];

'    //
'    //  Following parameters may match up to reference implementation of LDAP API.
'    //

'    ULONG   ld_cldaptries;
'    ULONG   ld_cldaptimeout;
'    ULONG   ld_refhoplimit;
'    ULONG   ld_options;

'} LDAP, * PLDAP;

' // Size = 76 bytes
TYPE ld_sb DWORD
   sb_sd              AS DWORD   ' UINT_PTR
   Reserevd1(10*4)    AS BYTE    ' UCHAR Reserved1[(10*sizeof(ULONG))+1];
   sb_naddr           AS DWORD   ' ULONG_PTR // notzero implies CLDAP available
   Reserevd2((6*4)-1) AS BYTE    ' UCHAR Reserved2[(6*sizeof(ULONG))];
END TYPE

' // Size = 160 bytes
TYPE ldap DWORD
   ld_sb
   ld_host         AS ASCIIZ PTR   ' PCHAR
   ld_version      AS DWORD        ' ULONG
   ld_lberoptions  AS BYTE         ' UCHAR
   ld_deref        AS DWORD        ' ULONG
   ld_timelimit    AS DWORD        ' ULONG
   ld_sizelimit    AS DWORD        ' ULONG
   ld_errno        AS DWORD        ' ULONG
   ld_matched      AS ASCIIZ PTR   ' PCHAR
   ld_error        AS ASCIIZ PTR   ' PCHAR
   ld_msgid        AS DWORD        ' ULONG
   Reserved3(6*4)  AS BYTE         ' UCHAR Reserved3[(6*sizeof(ULONG))+1];
   ld_cldaptries   AS DWORD        ' ULONG
   ld_cldaptimeout AS DWORD        ' ULONG
   ld_refhoplimit  AS DWORD        ' ULONG
   ld_options      AS DWORD        ' ULONG
END TYPE

'//
'//  Our timeval structure is a bit different from the reference implementation
'//  since Win32 defines a _timeval structure that is different from the LDAP
'//  one.
'//

' // Size = 8 bytes
TYPE l_timeval DWORD
   tv_sec  AS LONG   ' LONG
   tv_usec AS LONG   ' LONG
END TYPE

MACRO LDAP_TIMEVAL = l_timeval

'//
'//  The berval structure is used to pass in any arbitrary octet string.  It
'//  is useful for attributes that cannot be represented using a null
'//  terminated string.
'//

#IF NOT %DEF(%BERVAL_DEFINED)
%BERVAL_DEFINED = 1
' // Size = 8 bytes
TYPE berval DWORD
   bv_len AS DWORD      ' ULONG
   bv_val AS BYTE PTR   ' PUCHAR
END TYPE
#ENDIF

MACRO LDAP_BERVAL = berval

'//
'//  The following structure has to be compatible with reference implementation.
'//
' // Size = 44 bytes
TYPE ldapmsg
   lm_msgid             AS DWORD         ' ULONG // message number for given connection
   lm_msgtype           AS DWORD         ' ULONG // message type of the form LDAP_RES_xxx
   lm_ber               AS DWORD         ' PVOID // ber form of message
   lm_chain             AS ldapmsg PTR   ' struct ldapmsg * // pointer to next result value
   lm_next              AS ldapmsg PTR   ' struct ldapmsg * // pointer to next message
   lm_time              AS DWORD         ' ULONG
   Connection           AS ldap PTR      ' PLDAP // connection from which we received response
   Request              AS DWORD         ' PVOID // owning request (opaque structure)
   lm_returncode        AS DWORD         ' ULONG // server's return code
   lm_referral          AS WORD          ' USHORT // index of referral within ref table
   lm_chased            AS BYTE          ' BOOLEAN // has referral been chased already?
   lm_eom               AS BYTE          ' BOOLEAN // is this the last entry for this message?
   ConnectionReferenced AS BYTE          ' BOOLEAN // is the Connection still valid?
   alignment__(2)       AS BYTE          ' // To keep DWORD alignment
END TYPE

MACRO LDAPMessage = ldapmsg

'//
'//  Controls... there are three types :
'//
'//   1) those passed to the server
'//   2) those passed to the client and handled by the client API
'//   3) those returned by the server
'//

' // Size = 16 bytes
TYPE ldapcontrolA DWORD
   ldctl_oid        AS ASCIIZ PTR   ' PCHAR
   ldctl_value      AS berval       ' struct berval
   ldctl_iscritical AS BYTE         ' BOOLEAN
END TYPE

' // Size = 16 bytes
TYPE ldapcontrolW DWORD
   ldctl_oid        AS WSTRINGZ PTR   ' PWCHAR
   ldctl_value      AS berval         ' struct berval
   ldctl_iscritical AS BYTE           ' BOOLEAN
END TYPE

#IF %DEF(%UNICODE)
   MACRO LDAPControl = ldapcontrolW
#ELSE
   MACRO LDAPControl = ldapcontrolA
#ENDIF

'//
'//  Client controls section : these are the client controls that wldap32.dll
'//  supports.
'//
'//  If you specify LDAP_CONTROL_REFERRALS in a control, the value field should
'//  point to a ULONG of the following flags :
'//
'//      LDAP_CHASE_SUBORDINATE_REFERRALS
'//      LDAP_CHASE_EXTERNAL_REFERRALS
'//

$$LDAP_CONTROL_REFERRALS_W = "1.2.840.113556.1.4.616"$$
$LDAP_CONTROL_REFERRALS    = "1.2.840.113556.1.4.616"

'//
'//  Values required for Modification command  These are options for the
'//  mod_op field of LDAPMod structure
'//

%LDAP_MOD_ADD            = &H00???
%LDAP_MOD_DELETE         = &H01???
%LDAP_MOD_REPLACE        = &H02???
%LDAP_MOD_BVALUES        = &H80???  ' // AND in this flag if berval structure used

' // Size = 4 bytes
UNION ldapmodW_mod_vals_UNION DWORD
   modv_strvals AS WSTRINGZ PTR   ' PWCHAR *
   modv_bvals   AS berval PTR     ' struct berval **
END UNION

' // Size = 12 bytes
TYPE ldapmodW DWORD
   mod_op   AS DWORD          ' ULONG
   mod_type AS WSTRINGZ PTR   ' PWCHAR
   mod_vals AS ldapmodW_mod_vals_UNION
END TYPE

' // Size = 4 bytes
UNION ldapmodA_mod_vals_UNION DWORD
   modv_strvals AS ASCIIZ PTR   ' PCHAR *
   modv_bvals   AS berval PTR   ' struct berval **
END UNION

' // Size = 12 bytes
TYPE ldapmodA DWORD
   mod_op   AS DWORD        ' ULONG
   mod_type AS ASCIIZ PTR   ' PWCHAR
   mod_vals AS ldapmodA_mod_vals_UNION
END TYPE

#IF %DEF(%UNICODE)
   MACRO LDAPMod = LDAPModW
#ELSE
   MACRO LDAPMod = LDAPModA
#ENDIF

'#if !defined(_WIN64)
'#pragma pack(pop)
'#endif

'//
'//  macros compatible with reference implementation...
'//

'#define LDAP_IS_CLDAP( ld ) ( (ld)->ld_sb.sb_naddr > 0 )
'#define mod_values      mod_vals.modv_strvals
'#define mod_bvalues     mod_vals.modv_bvals
'#define NAME_ERROR(n)   ((n & 0xf0) == 0x20)

MACRO LDAP_IS_CLDAP(ld) = (ld.ld_sb.sb_naddr > 0)
MACRO mod_values = mod_vals.modv_strvals
MACRO mod_bvalues = mod_vals.modv_bvals
MACRO NAME_ERROR(n)  = ((n AND &Hf0) = &H20)

'//
'//  function definitions for LDAP API
'//

'//
'//  Create a connection block to an LDAP server.  HostName can be NULL, in
'//  which case we'll try to go off and find the "default" LDAP server.
'//
'//  Note that if we have to go off and find the default server, we'll pull
'//  in NETAPI32.DLL and ADVAPI32.DLL.
'//
'//  If it returns NULL, an error occurred.  Pick up error code with
'//     GetLastError().
'//
'//  ldap_open actually opens the connection at the time of the call,
'//  whereas ldap_init only opens the connection when an operation is performed
'//  that requires it.
'//
'//  multi-thread: ldap_open*, ldap_init*, and ldap_sslinit* calls are safe.
'//

DECLARE FUNCTION ldap_openW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_openW" ( _
   BYREF HostName AS WSTRINGZ _                         ' __in const PWCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

DECLARE FUNCTION ldap_openA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_openA" ( _
   BYREF HostName AS ASCIIZ _                           ' __in const PCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

#IF %DEF(%UNICODE)
   MACRO ldap_open = ldap_openW
#ELSE
   MACRO ldap_open = ldap_openA
#ENDIF

DECLARE FUNCTION ldap_initW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_initW" ( _
   BYREF HostName AS WSTRINGZ _                         ' __in const PWCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

DECLARE FUNCTION ldap_initA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_initA" ( _
   BYREF HostName AS ASCIIZ _                           ' __in const PCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

#IF %DEF(%UNICODE)
   MACRO ldap_init = ldap_initW
#ELSE
   MACRO ldap_init = ldap_initA
#ENDIF

DECLARE FUNCTION ldap_sslinitW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sslinitW" ( _
   BYREF HostName AS WSTRINGZ _                         ' __in const PWCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 , BYVAL secure AS LONG _                               ' __in int   secure
 ) AS DWORD                                             ' LDAP*

DECLARE FUNCTION ldap_sslinitA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sslinitA" ( _
   BYREF HostName AS ASCIIZ _                           ' __in const PCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 , BYVAL secure AS LONG _                               ' __in int   secure
 ) AS DWORD                                             ' LDAP*

#IF %DEF(%UNICODE)
   MACRO ldap_sslinit = ldap_sslinitW
#ELSE
   MACRO ldap_sslinit = ldap_sslinitA
#ENDIF

'//
'//  when calling ldap_init, you can call ldap_connect explicitly to have the
'//  library contact the server.  This is useful for checking for server
'//  availability.  This call is not required however, since the other functions
'//  will call it internally if it hasn't already been called.
'//

DECLARE FUNCTION ldap_connect CDECL IMPORT "Wldap32.dll" ALIAS "ldap_connect" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF timeout AS l_timeval _                         ' __in struct l_timeval *timeout
 ) AS DWORD                                             ' ULONG

'//
'//  This is similar to ldap_open except it creates a connection block for
'//  UDP based Connectionless LDAP services.  No TCP session is maintained.
'//
'//  If it returns NULL, an error occurred.  Pick up error code with
'//     GetLastError().
'//
'//  multi-thread: cldap_open* calls are safe.
'//

DECLARE FUNCTION cldap_openW CDECL IMPORT "Wldap32.dll" ALIAS "cldap_openW" ( _
   BYREF HostName AS WSTRINGZ _                         ' __in const PWCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

DECLARE FUNCTION cldap_openA CDECL IMPORT "Wldap32.dll" ALIAS "cldap_openA" ( _
   BYREF HostName AS ASCIIZ _                           ' __in const PCHAR HostName
 , BYVAL PortNumber AS DWORD _                          ' __in ULONG PortNumber
 ) AS DWORD                                             ' LDAP*

#IF %DEF(%UNICODE)
   MACRO cldap_open = cldap_openW
#ELSE
   MACRO cldap_open = cldap_openA
#ENDIF

'//
'//  Call unbind when you're done with the connection, it will free all
'//  resources associated with the connection.
'//
'//  There is no ldap_close... use ldap_unbind even if you haven't called
'//  ldap_bind on the connection.
'//
'//  multi-thread: ldap_unbind* calls are safe EXCEPT don't use the LDAP *
'//                stucture after it's been freed.
'//

DECLARE FUNCTION ldap_unbind CDECL IMPORT "Wldap32.dll" ALIAS "ldap_unbind" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_unbind_s CDECL IMPORT "Wldap32.dll" ALIAS "ldap_unbind_s" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 ) AS DWORD                                             ' ULONG

'//
'//  Calls to get and set options on connection blocks... use them rather
'//  than modifying the LDAP block directly.
'//
'//
'//  multi-thread: ldap_get_option is safe
'//  multi-thread: ldap_set_option is not safe in that it affects the
'//                connection as a whole.  beware if threads share connections.

DECLARE FUNCTION ldap_get_optionA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_option" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL option AS LONG _                               ' int option
 , BYREF outvalue AS ANY _                              ' void *outvalue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_get_optionW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_optionW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL option AS LONG _                               ' int option
 , BYREF outvalue AS ANY _                              ' void *outvalue
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_get_option = ldap_get_optionW
#ELSE
   MACRO ldap_get_option = ldap_get_optionA
#ENDIF

DECLARE FUNCTION ldap_set_optionA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_set_option" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL option AS LONG _                               ' int option
 , BYREF invalue AS ANY _                               ' const void *invalue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_set_optionW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_set_optionW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL option AS LONG _                               ' int option
 , BYREF invalue AS ANY _                               ' const void *invalue
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_set_option = ldap_set_optionW
#ELSE
   MACRO ldap_set_option = ldap_set_optionA
#ENDIF

'//
'//  These are the values to pass to ldap_get/set_option :
'//

%LDAP_OPT_API_INFO           = &H00&
%LDAP_OPT_DESC               = &H01&
%LDAP_OPT_DEREF              = &H02&
%LDAP_OPT_SIZELIMIT          = &H03&
%LDAP_OPT_TIMELIMIT          = &H04&
%LDAP_OPT_THREAD_FN_PTRS     = &H05&
%LDAP_OPT_REBIND_FN          = &H06&
%LDAP_OPT_REBIND_ARG         = &H07&
%LDAP_OPT_REFERRALS          = &H08&
%LDAP_OPT_RESTART            = &H09&

%LDAP_OPT_SSL                = &H0a&
%LDAP_OPT_IO_FN_PTRS         = &H0b&
%LDAP_OPT_CACHE_FN_PTRS      = &H0d&
%LDAP_OPT_CACHE_STRATEGY     = &H0e&
%LDAP_OPT_CACHE_ENABLE       = &H0f&
%LDAP_OPT_REFERRAL_HOP_LIMIT = &H10&

%LDAP_OPT_PROTOCOL_VERSION   = &H11&       ' // known by two names.
%LDAP_OPT_VERSION            = &H11&
%LDAP_OPT_API_FEATURE_INFO   = &H15&

'//
'//  These are new ones that we've defined, not in current RFC draft.
'//

%LDAP_OPT_HOST_NAME          = &H30&
%LDAP_OPT_ERROR_NUMBER       = &H31&
%LDAP_OPT_ERROR_STRING       = &H32&
%LDAP_OPT_SERVER_ERROR       = &H33&
%LDAP_OPT_SERVER_EXT_ERROR   = &H34&
%LDAP_OPT_HOST_REACHABLE     = &H3E&

'//
'//  These options control the keep-alive logic.  Keep alives are sent as
'//  ICMP ping messages (which currently don't go through firewalls).
'//
'//  There are three values that control how this works :
'//  PING_KEEP_ALIVE : min number of seconds since we last received a response
'//                    from the server before we send a keep-alive ping
'//  PING_WAIT_TIME  : number of milliseconds we wait for the response to
'//                    come back when we send a ping
'//  PING_LIMIT      : number of unanswered pings we send before we close the
'//                    connection.
'//
'//  To disable the keep-alive logic, set any of the values (PING_KEEP_ALIVE,
'//  PING_LIMIT, or PING_WAIT_TIME) to zero.
'//
'//  The current default/min/max for these values are as follows :
'//
'//  PING_KEEP_ALIVE :  120/5/maxInt  seconds (may also be zero)
'//  PING_WAIT_TIME  :  2000/10/60000 milliseconds (may also be zero)
'//  PING_LIMIT      :  4/0/maxInt
'//

%LDAP_OPT_PING_KEEP_ALIVE    = &H36&
%LDAP_OPT_PING_WAIT_TIME     = &H37&
%LDAP_OPT_PING_LIMIT         = &H38&

'//
'//  These won't be in the RFC.  Only use these if you're going to be dependent
'//  on our implementation.
'//

%LDAP_OPT_DNSDOMAIN_NAME     = &H3B&   ' // return DNS name of domain
%LDAP_OPT_GETDSNAME_FLAGS    = &H3D&   ' // flags for DsGetDcName

%LDAP_OPT_PROMPT_CREDENTIALS = &H3F&   ' // prompt for creds? currently
                                       ' // only for DPA & NTLM if no creds
                                       ' // are loaded

%LDAP_OPT_AUTO_RECONNECT     = &H91&   ' // enable/disable autoreconnect
%LDAP_OPT_SSPI_FLAGS         = &H92&   ' // flags to pass to InitSecurityContext

'//
'// To retrieve information on an secure connection, a pointer to a
'// SecPkgContext_connectionInfo structure (defined in schannel.h) must be
'// passed in. On success, it is filled with relevent security information.
'//

%LDAP_OPT_SSL_INFO           = &H93&

'// backward compatible %for older constant name.

%LDAP_OPT_TLS                = %LDAP_OPT_SSL
%LDAP_OPT_TLS_INFO           = %LDAP_OPT_SSL_INFO

'//
'// Turing on either the sign or the encrypt option prior to binding using
'// LDAP_AUTH_NEGOTIATE will result in the ensuing LDAP session to be signed
'// or encrypted using Kerberos. Note that these options can't be used with SSL.
'//

%LDAP_OPT_SIGN               = &H95&
%LDAP_OPT_ENCRYPT            = &H96&

'//
'// The user can set a preferred SASL method prior to binding using LDAP_AUTH_NEGOTIATE
'// We will try to use this mechanism while binding. One example is "GSSAPI".
'//

%LDAP_OPT_SASL_METHOD        = &H97&

'//
'// Setting this option to LDAP_OPT_ON will instruct the library to only perform an
'// A-Record DNS lookup on the supplied host string. This option is OFF by default.
'//

%LDAP_OPT_AREC_EXCLUSIVE     = &H98&

'//
'// Retrieve the security context associated with the connection.
'//

%LDAP_OPT_SECURITY_CONTEXT   = &H99&

'//
'// Enable/Disable the built-in RootDSE cache. This option is ON by default.
'//

%LDAP_OPT_ROOTDSE_CACHE      = &H9a&

'//
'// Turns on TCP keep-alives.  This is separate from the ICMP ping keep-alive
'// mechanism (discussed above), and enables the keep-alive mechanism built into
'// the TCP protocol.  This has no effect when using connectionless (UDP) LDAP.
'// This option is OFF by default.
'//

%LDAP_OPT_TCP_KEEPALIVE     = &H40&


'//
'// Turns on support for fast concurrent binds (extended operation
'// 1.2.840.113556.1.4.1781).  This option can be set only on a fresh
'// (never bound/authenticated) connection.  Setting this option will
'// (1) switch the client into a mode where it supports simultaneous
'// simple binds on the connection, and (2) sends the extended operation
'// to the server to switch it into fast bind mode.  Only simple binds
'// are supported in this mode.
'//
%LDAP_OPT_FAST_CONCURRENT_BIND   = &H41&

%LDAP_OPT_SEND_TIMEOUT           = &H42&

'//
'// Flags to control the behavior of Schannel
'//
%LDAP_OPT_SCH_FLAGS              = &H43&

'//
'// List of local interface addresses (IPv4 or IPv6) that will be used for
'// socket bind when establishing a connecting.
'//
%LDAP_OPT_SOCKET_BIND_ADDRESSES  = &H44&

'//
'//  End of Microsoft only options
'//

%LDAP_OPT_ON                = 1   ' ((void *) 1)
%LDAP_OPT_OFF               = 0   ' ((void *) 0)

'//
'//  For chasing referrals, we extend this a bit for LDAP_OPT_REFERRALS.  If
'//  the value is not LDAP_OPT_ON or LDAP_OPT_OFF, we'll treat them as the
'//  following :
'//
'//  LDAP_CHASE_SUBORDINATE_REFERRALS  : chase subordinate referrals (or
'//                                      references) returned in a v3 search
'//  LDAP_CHASE_EXTERNAL_REFERRALS : chase external referrals. These are
'//                          returned possibly on any operation except bind.
'//
'//  If you OR these flags together, it's equivalent to setting referrals to
'//  LDAP_OPT_ON.
'//

%LDAP_CHASE_SUBORDINATE_REFERRALS    = &H00000020???
%LDAP_CHASE_EXTERNAL_REFERRALS       = &H00000040???

'//
'//  Bind is required as the first operation to v2 servers, not so for v3
'//  servers.  See above description of authentication methods.
'//
'//  multi-thread: bind calls are not safe in that it affects the
'//                connection as a whole.  beware if threads share connections
'//                and try to mulithread binds with other operations.

DECLARE FUNCTION ldap_simple_bindW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_simple_bindW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , OPTIONAL BYREF dn AS WSTRINGZ _                      ' __in_opt PWCHAR dn
 , OPTIONAL BYREF passwd AS WSTRINGZ _                  ' __in_opt PWCHAR passwd
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_simple_bindA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_simple_bindA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , OPTIONAL BYREF dn AS ASCIIZ _                        ' __in_opt PCHAR dn
 , OPTIONAL BYREF passwd AS ASCIIZ _                    ' __in_opt PCHAR passwd
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_simple_bind = ldap_simple_bindW
#ELSE
   MACRO ldap_simple_bind = ldap_simple_bindA
#ENDIF

DECLARE FUNCTION ldap_simple_bind_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_simple_bindW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , OPTIONAL BYREF dn AS WSTRINGZ _                      ' __in_opt PWCHAR dn
 , OPTIONAL BYREF passwd AS WSTRINGZ _                  ' __in_opt PWCHAR passwd
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_simple_bind_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_simple_bind_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , OPTIONAL BYREF dn AS ASCIIZ _                        ' __in_opt PCHAR dn
 , OPTIONAL BYREF passwd AS ASCIIZ _                    ' __in_opt PCHAR passwd
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_simple_bind_s = ldap_simple_bind_sW
#ELSE
   MACRO ldap_simple_bind_s = ldap_simple_bind_sA
#ENDIF

DECLARE FUNCTION ldap_bindW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_bindW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in_opt PWCHAR dn
 , BYREF cred AS WSTRINGZ _                             ' __in_opt PWCHAR cred
 , BYVAL method AS DWORD _                              ' __in ULONG method
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_bindA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_bindA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in_opt PCHAR dn
 , BYREF cred AS ASCIIZ _                               ' __in_opt PCHAR cred
 , BYVAL method AS DWORD _                              ' __in ULONG method
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_bind = ldap_bindW
#ELSE
   MACRO ldap_bind = ldap_bindA
#ENDIF

DECLARE FUNCTION ldap_bind_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_bind_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in_opt PWCHAR dn
 , BYREF cred AS WSTRINGZ _                             ' __in_opt PWCHAR cred
 , BYVAL method AS DWORD _                              ' __in ULONG method
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_bind_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_bind_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in_opt PCHAR dn
 , BYREF cred AS ASCIIZ _                               ' __in_opt PCHAR cred
 , BYVAL method AS DWORD _                              ' __in ULONG method
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_bind_s = ldap_bind_sW
#ELSE
   MACRO ldap_bind_s = ldap_bind_sA
#ENDIF

'//
'// The following functions can be used to pass in any arbitrary credentials
'// to the server. The application must be ready to interpret the response
'// sent back from the server.
'//

DECLARE FUNCTION ldap_sasl_bindA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sasl_bindA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF DistName AS ASCIIZ _                           ' __in  const PCHAR DistName
 , BYREF AuthMechanism AS ASCIIZ _                      ' __in  const PCHAR AuthMechanism
 , BYVAL cred AS berval PTR _                           ' __in  const BERVAL *cred
 , BYVAL ServerCtrls AS LDAPControlA PTR _              ' __in  PLDAPControlA *ServerCtrls
 , BYVAL ClientCtrls AS LDAPControlA PTR _              ' __in  PLDAPControlA *ClientCtrls
 , BYREF MessageNumber AS LONG _                        ' __out int *MessageNumber
 ) AS LONG                                              ' INT

DECLARE FUNCTION ldap_sasl_bindW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sasl_bindW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF DistName AS WSTRINGZ _                         ' __in  const PWCHAR DistName
 , BYREF AuthMechanism AS WSTRINGZ _                    ' __in  const PWCHAR AuthMechanism
 , BYVAL cred AS berval PTR _                           ' __in  const BERVAL *cred
 , BYVAL ServerCtrls AS LDAPControlW PTR _              ' __in  PLDAPControlW *ServerCtrls
 , BYVAL ClientCtrls AS LDAPControlW PTR _              ' __in  PLDAPControlW *ClientCtrls
 , BYREF MessageNumber AS LONG _                        ' __out int *MessageNumber
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO ldap_sasl_bind = ldap_sasl_bindW
#ELSE
   MACRO ldap_sasl_bind = ldap_sasl_bindA
#ENDIF

DECLARE FUNCTION ldap_sasl_bind_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sasl_bind_sA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF DistName AS ASCIIZ _                           ' __in  const PCHAR DistName
 , BYREF AuthMechanism AS ASCIIZ _                      ' __in  const PCHAR AuthMechanism
 , BYVAL cred AS berval PTR _                           ' __in  const BERVAL *cred
 , BYVAL ServerCtrls AS LDAPControlA PTR _              ' __in  PLDAPControlA *ServerCtrls
 , BYVAL ClientCtrls AS LDAPControlA PTR _              ' __in  PLDAPControlA *ClientCtrls
 , BYVAL ServerData AS berval PTR _                     ' __out PBERVAL *ServerData
 ) AS LONG                                              ' INT

DECLARE FUNCTION ldap_sasl_bind_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_sasl_bind_sW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF DistName AS WSTRINGZ _                         ' __in  const PWCHAR DistName
 , BYREF AuthMechanism AS WSTRINGZ _                    ' __in  const PWCHAR AuthMechanism
 , BYVAL cred AS berval PTR _                           ' __in  const BERVAL *cred
 , BYVAL ServerCtrls AS LDAPControlW PTR _              ' __in  PLDAPControlW *ServerCtrls
 , BYVAL ClientCtrls AS LDAPControlW PTR _              ' __in  PLDAPControlW *ClientCtrls
 , BYREF ServerData AS berval _                         ' __out PBERVAL *ServerData
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO ldap_sasl_bind_s = ldap_sasl_bind_sW
#ELSE
   MACRO ldap_sasl_bind_s = ldap_sasl_bind_sA
#ENDIF

'//
'//  Synchronous and asynch search routines.
'//
'//  filter follows RFC 1960 with the addition that '(' ')' '*' ' ' '\' and
'//   '\0' are all escaped with '\'
'//
'// Scope of search.  This corresponds to the "scope" parameter on search

%LDAP_SCOPE_BASE         = &H00???
%LDAP_SCOPE_ONELEVEL     = &H01???
%LDAP_SCOPE_SUBTREE      = &H02???

'//
'//  multi-thread: ldap_search calls are not safe in that the message number
'//                is returned rather than the return code.  You have to look
'//                at the connection block in an error case and the return code
'//                may be overwritten by another thread inbetween.
'//
'//                Use ldap_search_ext instead, as these are thread safe.
'//
'//                ldap_search_s and ldap_search_ext* calls are thread safe.
'//

DECLARE FUNCTION ldap_searchW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_searchW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF base AS WSTRINGZ _                             ' __in const PWCHAR base     // distinguished name or ""
 , BYVAL scope AS DWORD _                               ' __in ULONG scope           // LDAP_SCOPE_xxxx
 , BYREF filter AS WSTRINGZ _                           ' __in const PWCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in PWCHAR attrs[]        // pointer to an array of PWCHAR attribute names
 , BYVAL attrsonly AS DWORD _                           ' __in ULONG attrsonly       // boolean on whether to only return attr names
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_searchA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_searchA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF base AS ASCIIZ _                               ' __in const PCHAR base     // distinguished name or ""
 , BYVAL scope AS DWORD _                               ' __in ULONG scope          // LDAP_SCOPE_xxxx
 , BYREF filter AS ASCIIZ _                             ' __in const PCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in PCHAR attrs[]        // pointer to an array of PCHAR attribute names
 , BYVAL attrsonly AS DWORD _                           ' __in ULONG attrsonly      // boolean on whether to only return attr names
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_search = ldap_searchW
#ELSE
   MACRO ldap_search = ldap_searchA
#ENDIF

DECLARE FUNCTION ldap_search_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS WSTRINGZ _                             ' __in  const PWCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS WSTRINGZ _                           ' __in  const PWCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PWCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_search_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS ASCIIZ _                               ' __in  const PCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS ASCIIZ _                             ' __in  const PCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_search_s = ldap_search_sW
#ELSE
   MACRO ldap_search_s = ldap_search_sA
#ENDIF

DECLARE FUNCTION ldap_search_stW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_stW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS WSTRINGZ _                             ' __in  const PWCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYVAL filter AS DWORD _                              ' __in  const PWCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PWCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYREF timeout AS l_timeval _                         ' __in  struct l_timeval *timeout
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_search_stA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_stA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS ASCIIZ _                               ' __in  const PCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS ASCIIZ _                             ' __in  const PCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYREF timeout AS l_timeval _                         ' __in  struct l_timeval *timeout
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_search_st = ldap_search_stW
#ELSE
   MACRO ldap_search_st = ldap_search_stA
#ENDIF

DECLARE FUNCTION ldap_search_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS WSTRINGZ _                             ' __in  const PWCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS WSTRINGZ _                           ' __in  const PWCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PWCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYVAL TimeLimit AS DWORD _                           ' __in  ULONG TimeLimit
 , BYVAL SizeLimit AS DWORD _                           ' __in  ULONG SizeLimit
 , BYVAL MessageNumber AS DWORD _                       ' __in  ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_search_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS ASCIIZ _                               ' __in  const PCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS ASCIIZ _                             ' __in  const PCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYVAL TimeLimit AS DWORD _                           ' __in  ULONG TimeLimit
 , BYVAL SizeLimit AS DWORD _                           ' __in  ULONG SizeLimit
 , BYVAL MessageNumber AS DWORD _                       ' __in  ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_search_ext = ldap_search_extW
#ELSE
   MACRO ldap_search_ext = ldap_search_extA
#ENDIF

DECLARE FUNCTION ldap_search_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS WSTRINGZ _                             ' __in  const PWCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS WSTRINGZ _                           ' __in  const PWCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PWCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF timeout AS l_timeval _                         ' __in  truct l_timeval *timeout
 , BYVAL SizeLimit AS DWORD _                           ' __in  ULONG SizeLimit
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_search_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF base AS ASCIIZ _                               ' __in  const PCHAR base
 , BYVAL scope AS DWORD _                               ' __in  ULONG scope
 , BYREF filter AS ASCIIZ _                             ' __in  const PCHAR filter
 , BYVAL attrs AS DWORD _                               ' __in  PCHAR attrs[]
 , BYVAL attrsonly AS DWORD _                           ' __in  ULONG attrsonly
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF timeout AS l_timeval _                         ' __in  truct l_timeval *timeout
 , BYVAL SizeLimit AS DWORD _                           ' __in  ULONG SizeLimit
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_search_ext_s = ldap_search_ext_sW
#ELSE
   MACRO ldap_search_ext_s = ldap_search_ext_sA
#ENDIF

'//
'//  Extended API to check filter syntax.  Returns LDAP error code if syntax
'//  is invalid or LDAP_SUCCESS if it's ok.
'//

DECLARE FUNCTION ldap_check_filterW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_check_filterW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF SearchFilter AS WSTRINGZ _                     ' __in PWCHAR SearchFilter
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_check_filterA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_check_filterA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF SearchFilter AS ASCIIZ _                       ' __in PCHAR SearchFilter
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_check_filter = ldap_check_filterW
#ELSE
   MACRO ldap_check_filter = ldap_check_filterA
#ENDIF

'//
'//  modify an existing entry
'//

'//
'//  multi-thread: ldap_modify calls are not safe in that the message number
'//                is returned rather than the return code.  You have to look
'//                at the connection block in an error case and the return code
'//                may be overwritten by another thread inbetween.
'//
'//                Use ldap_modify_ext instead, as these are thread safe.
'//
'//                ldap_modify_s and ldap_modify_ext* calls are thread safe.
'//

DECLARE FUNCTION ldap_modifyW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modifyW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in PWCHAR dn
 , BYREF mods AS LDAPModW _                             ' __in LDAPModW *mods[]
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modifyA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modifyA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in PCHAR dn
 , BYREF mods AS LDAPModA _                             ' __in LDAPModA *mods[]
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modify = ldap_modifyW
#ELSE
   MACRO ldap_modify = ldap_modifyA
#ENDIF

DECLARE FUNCTION ldap_modify_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in PWCHAR dn
 , BYREF mods AS LDAPModW _                             ' __in LDAPModW *mods[]
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modify_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in PCHAR dn
 , BYREF mods AS LDAPModA _                             ' __in LDAPModA *mods[]
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modify_s = ldap_modify_sW
#ELSE
   MACRO ldap_modify_s = ldap_modify_sA
#ENDIF

DECLARE FUNCTION ldap_modify_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF mods AS LDAPModW _                             ' __in  LDAPModW *mods[]
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modify_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF mods AS LDAPModA _                             ' __in  LDAPModA *mods[]
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modify_ext = ldap_modify_extW
#ELSE
   MACRO ldap_modify_ext = ldap_modify_extA
#ENDIF

DECLARE FUNCTION ldap_modify_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF mods AS LDAPModW _                             ' __in  LDAPModW *mods[]
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modify_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modify_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF mods AS LDAPModA _                             ' __in  LDAPModA *mods[]
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modify_ext_s = ldap_modify_ext_sW
#ELSE
   MACRO ldap_modify_ext_s = ldap_modify_ext_sA
#ENDIF

'//
'//  modrdn and modrdn2 function both as RenameObject and MoveObject.
'//
'//  Note that to LDAP v2 servers, only rename within a given container
'//  is supported... therefore NewDistinguishedName is actually NewRDN.
'//  Here are some examples :
'//
'//  This works to both v2 and v3 servers :
'//
'//    DN = CN=Bob,OU=FOO,O=BAR
'//    NewDN = CN=Joe
'//
'//    result is: CN=Joe,OU=FOO,O=BAR
'//
'//  This works to only v3 and above servers :
'//
'//    DN = CN=Bob,OU=FOO,O=BAR
'//    NewDN = CN=Joe,OU=FOOBAR,O=BAR
'//
'//    result is: CN=Joe,OU=FOOBAR,O=BAR
'//
'//  If you try the second example to a v2 server, we'll send the whole
'//  NewDN over as the new RDN (rather than break up the parent OU and
'//  child).  The server will then give you back some unknown error.
'//

'//
'//  multi-thread: ldap_modrdn and ldap_modrdn2 calls are not safe in that
'//                the message number is returned rather than the return code.
'//                You have to look   at the connection block in an error case
'//                and the return code may be overwritten by another thread
'//                inbetween.
'//
'//                Use ldap_rename_ext instead, as these are thread safe.
'//

DECLARE FUNCTION ldap_modrdn2W CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn2W" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS WSTRINGZ _                ' __in const PWCHAR DistinguishedName
 , BYREF NewDistinguishedName AS WSTRINGZ _             ' __in const PWCHAR NewDistinguishedName
 , BYVAL DeleteOldRdn AS LONG _                         ' __in INT DeleteOldRdn
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modrdn2A CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn2A" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS ASCIIZ _                  ' __in const PCHAR DistinguishedName
 , BYREF NewDistinguishedName AS ASCIIZ _               ' __in const PCHAR NewDistinguishedName
 , BYVAL DeleteOldRdn AS LONG _                         ' __in INT DeleteOldRdn
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modrdn2 = ldap_modrdn2W
#ELSE
   MACRO ldap_modrdn2 = ldap_modrdn2A
#ENDIF

'//
'//  ldap_modrdn simply calls ldap_modrdn2 with a value of 1 for DeleteOldRdn.
'//

DECLARE FUNCTION ldap_modrdnW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdnW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS WSTRINGZ _                ' __in const PWCHAR DistinguishedName
 , BYREF NewDistinguishedName AS WSTRINGZ _             ' __in const PWCHAR NewDistinguishedName
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modrdnA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdnA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS ASCIIZ _                  ' __in const PCHAR DistinguishedName
 , BYREF NewDistinguishedName AS ASCIIZ _               ' __in const PCHAR NewDistinguishedName
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modrdn = ldap_modrdnW
#ELSE
   MACRO ldap_modrdn = ldap_modrdnA
#ENDIF

DECLARE FUNCTION ldap_modrdn2_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn2_sW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS WSTRINGZ _                ' __in const PWCHAR DistinguishedName
 , BYREF NewDistinguishedName AS WSTRINGZ _             ' __in const PWCHAR NewDistinguishedName
 , BYVAL DeleteOldRdn AS LONG _                         ' __in INT DeleteOldRdn
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modrdn2_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn2_sA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS ASCIIZ _                  ' __in const PCHAR DistinguishedName
 , BYREF NewDistinguishedName AS ASCIIZ _               ' __in const PCHAR NewDistinguishedName
 , BYVAL DeleteOldRdn AS LONG _                         ' __in INT DeleteOldRdn
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modrdn2_s = ldap_modrdn2_sW
#ELSE
   MACRO ldap_modrdn2_s = ldap_modrdn2_sA
#ENDIF

DECLARE FUNCTION ldap_modrdn_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn_sW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS WSTRINGZ _                ' __in const PWCHAR DistinguishedName
 , BYREF NewDistinguishedName AS WSTRINGZ _             ' __in const PWCHAR NewDistinguishedName
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_modrdn_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_modrdn_sA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYREF DistinguishedName AS ASCIIZ _                  ' __in const PCHAR DistinguishedName
 , BYREF NewDistinguishedName AS ASCIIZ _               ' __in const PCHAR NewDistinguishedName
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_modrdn_s = ldap_modrdn_sW
#ELSE
   MACRO ldap_modrdn_s = ldap_modrdn_sW
#ENDIF

'//
'//  Extended Rename operations.  These take controls and separate out the
'//  parent from the RDN, for clarity.
'//

DECLARE FUNCTION ldap_rename_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_rename_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF NewRDN AS WSTRINGZ _                           ' __in  const PWCHAR NewRDN
 , BYREF NewParent AS WSTRINGZ _                        ' __in_opt const PWCHAR NewParent
 , BYVAL DeleteOldRdn AS LONG _                         ' __in  INT DeleteOldRdn
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_rename_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_rename_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF NewRDN AS ASCIIZ _                             ' __in  const PCHAR NewRDN
 , BYREF NewParent AS ASCIIZ _                          ' __in_opt const PCHAR NewParent
 , BYVAL DeleteOldRdn AS LONG _                         ' __in  INT DeleteOldRdn
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_rename_ext = ldap_rename_extW
#ELSE
   MACRO ldap_rename_ext = ldap_rename_extA
#ENDIF

DECLARE FUNCTION ldap_rename_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_rename_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF NewRDN AS WSTRINGZ _                           ' __in  const PWCHAR NewRDN
 , BYREF NewParent AS WSTRINGZ _                        ' __in_opt const PWCHAR NewParent
 , BYVAL DeleteOldRdn AS LONG _                         ' __in  INT DeleteOldRdn
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_rename_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_rename_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF NewRDN AS ASCIIZ _                             ' __in  const PCHAR NewRDN
 , BYREF NewParent AS ASCIIZ _                          ' __in_opt const PCHAR NewParent
 , BYVAL DeleteOldRdn AS LONG _                         ' __in  INT DeleteOldRdn
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_rename_ext_s = ldap_rename_ext_sW
#ELSE
   MACRO ldap_rename_ext_s = ldap_rename_ext_sA
#ENDIF


'//
'//  Add an entry to the tree
'//

'//
'//  multi-thread: ldap_add calls are not safe in that the message number
'//                is returned rather than the return code.  You have to look
'//                at the connection block in an error case and the return code
'//                may be overwritten by another thread inbetween.
'//
'//                Use ldap_add_ext instead, as these are thread safe.
'//
'//                ldap_add_s and ldap_add_ext* calls are thread safe.
'//

DECLARE FUNCTION ldap_addW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_addW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in PWCHAR dn
 , BYREF attrs AS LDAPModW _                            ' __in LDAPModW *attrs[]
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_addA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_addA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in PCHAR dn
 , BYREF attrs AS LDAPModA _                            ' __in LDAPModA *attrs[]
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_add = ldap_addW
#ELSE
   MACRO ldap_add = ldap_addA
#ENDIF

DECLARE FUNCTION ldap_add_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in PWCHAR dn
 , BYREF attrs AS LDAPModW _                            ' __in LDAPModW *attrs[]
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_add_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in PCHAR dn
 , BYREF attrs AS LDAPModA _                            ' __in LDAPModA *attrs[]
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_add_s = ldap_add_sW
#ELSE
   MACRO ldap_add_s = ldap_add_sA
#ENDIF

DECLARE FUNCTION ldap_add_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF attrs AS LDAPModW _                            ' __in  LDAPModW attrs[]
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_add_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF attrs AS LDAPModA _                            ' __in  LDAPModA attrs[]
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_add_ext = ldap_add_extW
#ELSE
   MACRO ldap_add_ext = ldap_add_extA
#ENDIF

DECLARE FUNCTION ldap_add_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF attrs AS LDAPModW _                            ' __in  LDAPModW attrs[]
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_add_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_add_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF attrs AS LDAPModA _                            ' __in  LDAPModA attrs[]
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_add_ext_s = ldap_add_ext_sW
#ELSE
   MACRO ldap_add_ext_s = ldap_add_ext_sA
#ENDIF

'//
'//  Compare the attribute for a given entry to a known value.
'//

'//
'//  multi-thread: ldap_compare calls are not safe in that the message number
'//                is returned rather than the return code.  You have to look
'//                at the connection block in an error case and the return code
'//                may be overwritten by another thread inbetween.
'//
'//                Use ldap_compare_ext instead, as these are thread safe.
'//
'//                ldap_compare_s and ldap_compare_ext* calls are thread safe.
'//

DECLARE FUNCTION ldap_compareW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compareW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 , BYREF attr AS WSTRINGZ _                             ' __in const PWCHAR attr
 , BYREF value AS WSTRINGZ _                            ' __in PWCHAR value
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_compareA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compareA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 , BYREF attr AS ASCIIZ _                               ' __in const PCHAR attr
 , BYREF value AS ASCIIZ _                              ' __in PCHAR value
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_compare = ldap_compareW
#ELSE
   MACRO ldap_compare = ldap_compareA
#ENDIF

DECLARE FUNCTION ldap_compare_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 , BYREF attr AS WSTRINGZ _                             ' __in const PWCHAR attr
 , BYREF value AS WSTRINGZ _                            ' __in PWCHAR value
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_compare_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 , BYREF attr AS ASCIIZ _                               ' __in const PCHAR attr
 , BYREF value AS ASCIIZ _                              ' __in PCHAR value
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_compare_s = ldap_compare_sW
#ELSE
   MACRO ldap_compare_s = ldap_compare_sA
#ENDIF

'//
'//  Extended Compare operations.  These take controls and are thread safe.
'//  They also allow you to specify a bval structure for the data, so that it
'//  isn't translated from Unicode or ANSI to UTF8.  Allows for comparison of
'//  raw binary data.
'//
'//  Specify either Data or Value as not NULL.  If both are not NULL, the
'//  berval Data will be used.
'//

DECLARE FUNCTION ldap_compare_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF Attr AS WSTRINGZ _                             ' __in  const PWCHAR Attr
 , BYREF Value AS WSTRINGZ _                            ' __in_opt const PWCHAR Value // either value or Data is not null, not both
 , BYVAL Data AS berval PTR _                           ' __in_opt struct berval *Data
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_compare_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF Attr AS ASCIIZ _                               ' __in  const PCHAR Attr
 , BYREF Value AS ASCIIZ _                              ' __in_opt const PCHAR Value // either value or Data is not null, not both
 , BYVAL Data AS berval PTR _                           ' __in_opt struct berval *Data
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_compare_ext = ldap_compare_extW
#ELSE
   MACRO ldap_compare_ext = ldap_compare_extA
#ENDIF

DECLARE FUNCTION ldap_compare_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYREF Attr AS WSTRINGZ _                             ' __in  const PWCHAR Attr
 , BYREF Value AS WSTRINGZ _                            ' __in_opt const PWCHAR Value // either value or Data is not null, not both
 , BYVAL Data AS berval PTR _                           ' __in_opt struct berval *Data
 , BYVAL ServerCotrols AS LDAPControlW PTR _            ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_compare_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_compare_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYREF Attr AS ASCIIZ _                               ' __in  const PCHAR Attr
 , BYREF Value AS ASCIIZ _                              ' __in_opt const PCHAR Value // either value or Data is not null, not both
 , BYVAL Data AS berval PTR _                           ' __in_opt struct berval *Data
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_compare_ext_s = ldap_compare_ext_sW
#ELSE
   MACRO ldap_compare_ext_s = ldap_compare_ext_sA
#ENDIF

'//
'//  Delete an object out of the tree
'//

'//
'//  multi-thread: ldap_delete calls are not safe in that the message number
'//                is returned rather than the return code.  You have to look
'//                at the connection block in an error case and the return code
'//                may be overwritten by another thread inbetween.
'//
'//                Use ldap_delete_ext instead, as these are thread safe.
'//
'//                ldap_delete_s and ldap_delete_ext* calls are thread safe.
'//


DECLARE FUNCTION ldap_deleteW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_deleteW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_deleteA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_deleteA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_delete = ldap_deleteW
#ELSE
   MACRO ldap_delete = ldap_deleteA
#ENDIF

DECLARE FUNCTION ldap_delete_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_delete_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_delete_s = ldap_delete_sW
#ELSE
   MACRO ldap_delete_s = ldap_delete_sA
#ENDIF

DECLARE FUNCTION ldap_delete_extW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_extW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_delete_extA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_extA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_delete_ext = ldap_delete_extW
#ELSE
   MACRO ldap_delete_ext = ldap_delete_extA
#ENDIF

DECLARE FUNCTION ldap_delete_ext_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_ext_sW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS WSTRINGZ _                               ' __in  const PWCHAR dn
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_delete_ext_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_delete_ext_sA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF dn AS ASCIIZ _                                 ' __in  const PCHAR dn
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_delete_ext_s = ldap_delete_ext_sW
#ELSE
   MACRO ldap_delete_ext_s = ldap_delete_ext_sA
#ENDIF

'//
'//  Give up on a request.  No guarentee that it got there as there is no
'//  response from the server.
'//

'//  multi-thread: ldap_abandon calls are thread safe

DECLARE FUNCTION ldap_abandon CDECL IMPORT "Wldap32.dll" ALIAS "ldap_abandon" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL msgid AS DWORD _                               ' __in ULONG msgid
 ) AS DWORD                                             ' ULONG

'//
'//  Possible values for "all" field in ldap_result.  We've enhanced it such
'//  that if someone passes in LDAP_MSG_RECEIVED, we'll pass all values we've
'//  received up to that point.
'//

%LDAP_MSG_ONE      = 0
%LDAP_MSG_ALL      = 1
%LDAP_MSG_RECEIVED = 2

'//
'//  Get a response from a connection.  One enhancement here is that ld can
'//  be null, in which case we'll return responses from any server.  Free
'//  responses here with ldap_msgfree.
'//
'//  For connection-less LDAP, you should pass in both a LDAP connection
'//  handle and a msgid.  This will ensure we know which request the app
'//  is waiting on a reply to.  ( we actively resend request until we get
'//  a response.)
'//

'//  multi-thread: ldap_result calls are thread safe

DECLARE FUNCTION ldap_result CDECL IMPORT "Wldap32.dll" ALIAS "ldap_result" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYVAL msgid AS DWORD _                               ' __in  ULONG msgid
 , BYVAL all AS DWORD _                                 ' __in  ULONG all
 , BYREF timeout AS l_timeval _                         ' __in  struct l_timeval *timeout
 , BYREF res AS DWORD _                                 ' __out LDAPMessage **res
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_msgfree CDECL IMPORT "Wldap32.dll" ALIAS "ldap_msgfree" ( _
   BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' ULONG

'//
'//  This parses a message and returns the error code.  It optionally frees
'//  the message by calling ldap_msgfree.
'//

'//  multi-thread: ldap_result2error call is thread safe

DECLARE FUNCTION ldap_result2error CDECL IMPORT "Wldap32.dll" ALIAS "ldap_result2error" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 , BYVAL freeit AS DWORD _                              ' __in ULONG freeit // boolean.. free the message?
 ) AS DWORD                                             ' ULONG


'//
'//  Similar to ldap_result2error, this parses responses from the server and
'//  returns the appropriate fields.  Use this one if you want to get at the
'//  referrals, matchingDNs, or server controls returned.
'//

'//  multi-thread: ldap_parse_result call is thread safe

DECLARE FUNCTION ldap_parse_resultW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_resultW" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in LDAPMessage *ResultMessage
 , BYREF ReturnCode AS DWORD _                          ' __out_opt ULONG *ReturnCode         // returned by server
 , BYREF MatchedDNs AS DWORD _                          ' __out_opt PWCHAR *MatchedDNs    // free with ldap_memfree
 , BYREF ErrorMessage AS DWORD _                        ' __out_opt PWCHAR *ErrorMessage  // free with ldap_memfree
 , BYREF Referrals AS DWORD _                           ' __out_opt PWCHAR *Referrals     // free with ldap_value_freeW
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __out_opt PLDAPControlW **ServerControls  // free with ldap_free_controlsW
 , BYVAL Freeit AS BYTE _                               ' __in BOOLEAN Freeit
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_parse_resultA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_resultA" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in LDAPMessage *ResultMessage
 , BYREF ReturnCode AS DWORD _                          ' __out_opt ULONG *ReturnCode         // returned by server
 , BYREF MatchedDNs AS DWORD _                          ' __out_opt PCHAR *MatchedDNs    // free with ldap_memfree
 , BYREF ErrorMessage AS DWORD _                        ' __out_opt PCHAR *ErrorMessage  // free with ldap_memfree
 , BYREF Referrals AS DWORD _                           ' __out_opt PCHAR *Referrals     // free with ldap_value_freeA
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __out_opt PLDAPControlA **ServerControls  // free with ldap_free_controlsA
 , BYVAL Freeit AS BYTE _                               ' __in BOOLEAN Freeit
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_parse_result = ldap_parse_resultW
#ELSE
   MACRO ldap_parse_result = ldap_parse_resultA
#ENDIF

DECLARE FUNCTION ldap_parse_extended_resultA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_extended_resultA" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in LDAPMessage *ResultMessage
 , BYREF ResultOID AS DWORD _                           ' __out_opt PCHAR *ResultOID    // free with ldap_memfree
 , BYREF ResultData AS DWORD _                          ' __out struct berval **ResultData   // free with ldap_memfree
 , BYVAL Freeit AS BYTE _                               ' __in BOOLEAN Freeit
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_parse_extended_resultW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_extended_resultW" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in LDAPMessage *ResultMessage
 , BYREF ResultOID AS DWORD _                           ' __out_opt PCWHAR *ResultOID    // free with ldap_memfree
 , BYREF ResultData AS DWORD _                          ' __out struct berval **ResultData   // free with ldap_memfree
 , BYVAL Freeit AS BYTE _                               ' __in BOOLEAN Freeit
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_parse_extended_result = ldap_parse_extended_resultW
#ELSE
   MACRO ldap_parse_extended_result = ldap_parse_extended_resultA
#ENDIF

DECLARE FUNCTION ldap_controls_freeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_controls_freeA" ( _
   BYVAL Controls AS LDAPControlA PTR _                 ' __in LDAPControlA **Controls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_controls_freeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_controls_freeW" ( _
   BYREF Controls AS LDAPControlW _                     ' __in LDAPControlW **Controls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_controls_free = ldap_controls_freeW
#ELSE
   MACRO ldap_controls_free = ldap_controls_freeA
#ENDIF

DECLARE FUNCTION ldap_control_freeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_control_freeA" ( _
   BYVAL Control AS LDAPControlA PTR _                  ' __in LDAPControlA *Control
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_control_freeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_control_freeW" ( _
   BYVAL Control AS LDAPControlW PTR _                  ' __in LDAPControlW **Control
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_control_free = ldap_control_freeW
#ELSE
   MACRO ldap_control_free = ldap_control_freeA
#ENDIF

'//
'// ldap_free_controls are old, use ldap_controls_free
'//

DECLARE FUNCTION ldap_free_controlsW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_free_controlsW" ( _
   BYVAL Controls AS LDAPControlW PTR _                 ' __in LDAPControlW **Controls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_free_controlsA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_free_controlsA" ( _
   BYVAL Control AS LDAPControlA PTR _                  ' __in LDAPControlA **Control
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_free_controls = ldap_free_controlsW
#ELSE
   MACRO ldap_free_controls = ldap_free_controlsA
#ENDIF

'//
'//  ldap_err2string returns a pointer to a string describing the error.  This
'//  string should not be freed.
'//

DECLARE FUNCTION ldap_err2stringW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_err2stringW" ( _
   BYVAL err AS DWORD _                                 ' __in ULONG err
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_err2stringA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_err2stringA" ( _
   BYVAL err AS DWORD _                                 ' __in ULONG err
 ) AS DWORD                                             ' PCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_err2string = ldap_err2stringW
#ELSE
   MACRO ldap_err2string = ldap_err2stringA
#ENDIF

'//
'//  ldap_perror does nothing and is here just for compatibility.
'//

DECLARE SUB ldap_perror CDECL IMPORT "Wldap32.dll" ALIAS "ldap_perror" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYREF msg AS ASCIIZ _                                ' __in const PCHAR msg
 )                                                      ' void

'//
'//  Return the first entry of a message.  It is freed when the message is
'//  freed so should not be freed explicitly.
'//

DECLARE FUNCTION ldap_first_entry CDECL IMPORT "Wldap32.dll" ALIAS "ldap_first_entry" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' LDAPMessage

'//
'//  Return the next entry of a message.  It is freed when the message is
'//  freed so should not be freed explicitly.
'//

DECLARE FUNCTION ldap_next_entry CDECL IMPORT "Wldap32.dll" ALIAS "ldap_next_entry" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' LDAPMessage

'//
'//  Count the number of search entries returned by the server in a response
'//  to a server request.
'//

DECLARE FUNCTION ldap_count_entries CDECL IMPORT "Wldap32.dll" ALIAS "ldap_count_entries" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' ULONG

'//
'//  A BerElement really maps out to a C++ class object that does BER encoding.
'//  Don't mess with it as it's opaque.
'//

' // Size = 4 bytes
TYPE BerElement DWORD
   opaque AS DWORD   ' PCHAR // this is an opaque structure used just for
                     '       // compatibility with reference implementation
END TYPE

'#define NULLBER ((BerElement *) 0)

'//
'//  For a given entry, return the first attribute.  The pointer returned is
'//  actually a buffer in the connection block (with allowances for
'//  multi-threaded apps) so it should not be freed.
'//

DECLARE FUNCTION ldap_first_attributeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_first_attributeW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYVAL ptr AS BerElement PTR _                        ' __inout BerElement *ptr
 ) AS DWORD                                             ' PCHAR

DECLARE FUNCTION ldap_first_attributeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_first_attributeA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYVAL ptr AS BerElement PTR _                        ' __inout BerElement *ptr
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_first_attribute = ldap_first_attributeW
#ELSE
   MACRO ldap_first_attribute = ldap_first_attributeA
#ENDIF

'//
'//  Return the next attribute... again, the attribute pointer should not be
'//  freed.
'//

DECLARE FUNCTION ldap_next_attributeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_next_attributeW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYVAL ptr AS BerElement PTR _                        ' __inout BerElement *ptr
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_next_attributeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_next_attributeA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYVAL ptr AS BerElement PTR _                        ' __inout BerElement *ptr
 ) AS DWORD                                             ' PCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_next_attribute = ldap_next_attributeW
#ELSE
   MACRO ldap_next_attribute = ldap_next_attributeA
#ENDIF


'//
'//  Get a given attribute's list of values.  This is used during parsing of
'//  a search response.  It returns a list of pointers to values, the list is
'//  null terminated.
'//
'//  If the values are generic octet strings and not null terminated strings,
'//  use ldap_get_values_len instead.
'//
'//  The returned value should be freed when your done with it by calling
'//  ldap_value_free.
'//

DECLARE FUNCTION ldap_get_valuesW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_valuesW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYREF attr AS WSTRINGZ _                             ' __in const PWCHAR attr
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_get_valuesA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_valuesA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 , BYREF attr AS ASCIIZ _                               ' __in const PCHAR attr
 ) AS DWORD                                             ' PCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_get_values = ldap_get_valuesW
#ELSE
   MACRO ldap_get_values = ldap_get_valuesA
#ENDIF

'//
'//  Get a given attribute's list of values.  This is used during parsing of
'//  a search response.  It returns a list of berval structures to values,
'//  the list is null terminated.
'//
'//  If the values are null terminated strings, it may be easier to process them
'//  by calling ldap_get_values instead.
'//
'//  The returned value should be freed when your done with it by calling
'//  ldap_value_free_len.
'//

DECLARE FUNCTION ldap_get_values_lenW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_values_lenW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYVAL Message AS LDAPMessage PTR _                   ' __in LDAPMessage *Message
 , BYREF attr AS WSTRINGZ _                             ' __in const PWCHAR attr
 ) AS DWORD                                             ' berval**

DECLARE FUNCTION ldap_get_values_lenA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_values_lenA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP *ExternalHandle
 , BYVAL Message AS LDAPMessage PTR _                   ' __in LDAPMessage *Message
 , BYREF attr AS ASCIIZ _                               ' __in const PCHAR attr
 ) AS DWORD                                             ' berval**

#IF %DEF(%UNICODE)
   MACRO ldap_get_values_len = ldap_get_values_lenW
#ELSE
   MACRO ldap_get_values_len = ldap_get_values_lenA
#ENDIF


'//
'//  Return the number of values in a list returned by ldap_get_values.
'//

DECLARE FUNCTION ldap_count_valuesW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_count_valuesW" ( _
   BYVAL vals AS DWORD _                                ' __in_opt PWCHAR *vals
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_count_valuesA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_count_valuesA" ( _
   BYVAL vals AS DWORD _                                ' __in_opt PCHAR *vals
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_count_values = ldap_count_valuesW
#ELSE
   MACRO ldap_count_values = ldap_count_valuesA
#ENDIF

'//
'//  Return the number of values in a list returned by ldap_get_values_len.
'//

DECLARE FUNCTION ldap_count_values_len CDECL IMPORT "Wldap32.dll" ALIAS "ldap_count_values_len" ( _
   BYVAL vals AS berval PTR _                           ' __in struct berval **vals
 ) AS DWORD                                             ' ULONG

'//
'//  Free structures returned by ldap_get_values.
'//

DECLARE FUNCTION ldap_value_freeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_value_freeW" ( _
   BYVAL vals AS WSTRINGZ PTR _                         ' __in PWCHAR *vals
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_value_freeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_value_freeA" ( _
   BYVAL vals AS ASCIIZ PTR _                           ' __in PCHAR *vals
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_value_free = ldap_value_freeW
#ELSE
   MACRO ldap_value_free = ldap_value_freeA
#ENDIF

'//
'//  Free structures returned by ldap_get_values_len.
'//

DECLARE FUNCTION ldap_value_free_len CDECL IMPORT "Wldap32.dll" ALIAS "ldap_value_free_len" ( _
   BYVAL vals AS berval PTR _                           ' __in struct berval **vals
 ) AS DWORD                                             ' ULONG

'//
'//  Get the distinguished name for a given search entry.  It should be freed
'//  by calling ldap_memfree.
'//

DECLARE FUNCTION ldap_get_dnW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_dnW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_get_dnA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_dnA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 ) AS DWORD                                             ' PCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_get_dn = ldap_get_dnW
#ELSE
   MACRO ldap_get_dn = ldap_get_dnA
#ENDIF

'//
'//  When using ldap_explode_dn, you should free the returned string by
'//  calling ldap_value_free.
'//

DECLARE FUNCTION ldap_explode_dnW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_explode_dnW" ( _
   BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 , BYVAL notypes AS DWORD _                             ' __in ULONG notypes
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_explode_dnA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_explode_dnA" ( _
   BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 , BYVAL notypes AS DWORD _                             ' __in ULONG notypes
 ) AS DWORD                                             ' PWCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_explode_dn = ldap_explode_dnW
#ELSE
   MACRO ldap_explode_dn = ldap_explode_dnA
#ENDIF

'//
'//  When calling ldap_dn2ufn, you should free the returned string by calling
'//  ldap_memfree.
'//

DECLARE FUNCTION ldap_dn2ufnW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_dn2ufnW" ( _
   BYREF dn AS WSTRINGZ _                               ' __in const PWCHAR dn
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_dn2ufnA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_dn2ufnA" ( _
   BYREF dn AS ASCIIZ _                                 ' __in const PCHAR dn
 ) AS DWORD                                             ' PWCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_dn2ufn = ldap_dn2ufnW
#ELSE
   MACRO ldap_dn2ufn = ldap_dn2ufnA
#ENDIF

'//
'//  This is used to free strings back to the LDAP API heap.  Don't pass in
'//  values that you've gotten from ldap_open, ldap_get_values, etc.
'//

DECLARE FUNCTION ldap_memfreeW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_memfreeW" ( _
   BYVAL Block AS WSTRINGZ PTR _                        ' __in PWCHAR Block
 ) AS DWORD                                             ' PWCHAR

DECLARE FUNCTION ldap_memfreeA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_memfreeA" ( _
   BYVAL Block AS ASCIIZ PTR _                          ' __in PCHAR Block
 ) AS DWORD                                             ' PCHAR

#IF %DEF(%UNICODE)
   MACRO ldap_memfree = ldap_memfreeW
#ELSE
   MACRO ldap_memfree = ldap_memfreeA
#ENDIF

DECLARE SUB ber_bvfree CDECL IMPORT "Wldap32.dll" ALIAS "ber_bvfree" ( _
   BYVAL bv AS berval PTR _                             ' __in struct berval *bv
 )                                                      ' void

'//
'//  The function ldap_ufn2dn attempts to "normalize" a user specified DN
'//  to make it "proper".  It follows RFC 1781 (add CN= if not present,
'//  add OU= if none present, etc).  If it runs into any problems at all
'//  while normalizing, it simply returns a copy of what was passed in.
'//
'//  It allocates the output string from the LDAP memory pool.  If the pDn
'//  comes back as non-NULL, you should free it when you're done with a call
'//  to ldap_memfree.
'//

DECLARE FUNCTION ldap_ufn2dnW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_ufn2dnW" ( _
   BYREF ufn AS WSTRINGZ _                              ' __in const PWCHAR ufn
 , BYREF pDn AS DWORD _                                 ' __out PWCHAR *pDn
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_ufn2dnA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_ufn2dnA" ( _
   BYREF ufn AS ASCIIZ _                                ' __in const PCHAR ufn
 , BYREF pDn AS DWORD _                                 ' __out PCHAR *pDn
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_ufn2dn = ldap_ufn2dnW
#ELSE
   MACRO ldap_ufn2dn = ldap_ufn2dnA
#ENDIF

%LBER_USE_DER            = &H01???
%LBER_USE_INDEFINITE_LEN = &H02???
%LBER_TRANSLATE_STRINGS  = &H04???

'//
'//  Call to initialize the LDAP library.  Pass in a version structure with
'//  lv_size set to sizeof( LDAP_VERSION ), lv_major set to LAPI_MAJOR_VER1,
'//  and lv_minor set to LAPI_MINOR_VER1.  Return value will be either
'//  LDAP_SUCCESS if OK or LDAP_OPERATIONS_ERROR if can't be supported.
'//

%LAPI_MAJOR_VER1 = 1
%LAPI_MINOR_VER1 = 1

' // Size = 4 bytes
TYPE LDAP_VERSION_INFO DWORD
   lv_size  AS DWORD   ' ULONG
   lv_major AS DWORD   ' ULONG
   lv_minor AS DWORD   ' ULONG
END TYPE

DECLARE FUNCTION ldap_startup CDECL IMPORT "Wldap32.dll" ALIAS "ldap_startup" ( _
   BYREF version AS LDAP_VERSION_INFO _                 ' __in PLDAP_VERSION_INFO version
 , BYREF Instance AS DWORD _                            ' __out HANDLE *Instance
 ) AS DWORD                                             ' ULONG


'//
'// Calls to retrieve basic information about the API and specific implementations
'// being used. The caller has to pass the LDAP_OPT_API_INFO option along with
'// a pointer to the following structure to retrieve information about this library.
'// It is the caller's responsibility to free the individual strings and string
'// arrays in the structure using ldap_memfree() and ldap_value_free() respectively.
'//

%LDAP_API_INFO_VERSION     = 1
%LDAP_API_VERSION          = 2004
%LDAP_VERSION_MIN          = 2
%LDAP_VERSION_MAX          = 3
$LDAP_VENDOR_NAME          = "Microsoft Corporation."
$$LDAP_VENDOR_NAME_W       = "Microsoft Corporation."$$
%LDAP_VENDOR_VERSION       = 510

' // Size = 24 bytes
TYPE LDAPAPIInfoA DWORD
   ldapai_info_version     AS LONG         ' int /* version of this struct: LDAP_API_INFO_VERSION */
   ldapai_api_version      AS LONG         ' int /* revision of API supported */
   ldapai_protocol_version AS LONG         ' int /* highest LDAP version supported */
   ldapai_extensions       AS ASCIIZ PTR   ' char** /* names of API extensions */
   ldapai_vendor_name      AS ASCIIZ PTR   ' char /* name of supplier */
   ldapai_vendor_version   AS LONG         ' int /* supplier-specific version times 100 */
END TYPE

' // Size = 24 bytes
TYPE LDAPAPIInfoW DWORD
   ldapai_info_version     AS LONG           ' int /* version of this struct: LDAP_API_INFO_VERSION */
   ldapai_api_version      AS LONG           ' int /* revision of API supported */
   ldapai_protocol_version AS LONG           ' int /* highest LDAP version supported */
   ldapai_extensions       AS WSTRINGZ PTR   ' PWCHAR* /* names of API extensions */
   ldapai_vendor_name      AS WSTRINGZ PTR   ' PWCHAR /* name of supplier */
   ldapai_vendor_version   AS LONG           ' int /* supplier-specific version times 100 */
END TYPE

#IF %DEF(%UNICODE)
   MACRO LDAPAPIInfo = LDAPAPIInfoW
#ELSE
   MACRO LDAPAPIInfo = LDAPAPIInfoA
#ENDIF

%LDAP_FEATURE_INFO_VERSION = 1

' // Size = 12 bytes
TYPE LDAPAPIFeatureInfoA DWORD
   ldapaif_info_version AS LONG         ' int /* version of this struct : LDAP_FEATURE_INFO_VERSION */
   ldapaif_name         AS ASCIIZ PTR   ' char* /* name of supported feature */
   ldapaif_version      AS LONG         ' int /* revision of supported feature */
END TYPE

' // Size = 12 bytes
TYPE LDAPAPIFeatureInfoW DWORD
   ldapaif_info_version AS LONG           ' int /* version of this struct : LDAP_FEATURE_INFO_VERSION */
   ldapaif_name         AS WSTRINGZ PTR   ' PWCHAR /* name of supported feature */
   ldapaif_version      AS LONG           ' int /* revision of supported feature */
END TYPE

#IF %DEF(%UNICODE)
   MACRO LDAPAPIFeatureInfo = LDAPAPIFeatureInfoW
#ELSE
   MACRO LDAPAPIFeatureInfo = LDAPAPIFeatureInfoA
#ENDIF

'//
'//  ldap_cleanup unloads the library when the refcount of opens goes to zero.
'//  (i.e. if a DLL calls it within a program that is also using it, it won't
'//  free all resources)
'//

DECLARE FUNCTION ldap_cleanup CDECL IMPORT "Wldap32.dll" ALIAS "ldap_cleanup" ( _
   BYREF hInstance AS DWORD _                           ' __in HANDLE hInstance
 ) AS DWORD                                             ' ULONG

'//
'//  Extended API to support allowing opaque blobs of data in search filters.
'//  This API takes any filter element and converts it to a safe text string that
'//  can safely be passed in a search filter.
'//  An example of using this is :
'//
'//  filter is something like guid=4826BF6CF0123444
'//  this will put out on the wire guid of binary 0x4826BF6CF0123444
'//
'//  call ldap_escape_filter_element with sourceFilterElement pointing to
'//  raw data, sourceCount set appropriately to length of data.
'//
'//  if destFilterElement is NULL, then return value is length required for
'//  output buffer.
'//
'//  if destFilterElement is not NULL, then the function will copy the source
'//  into the dest buffer and ensure that it is of a safe format.
'//
'//  then simply insert the dest buffer into your search filter after the
'//  "attributetype=".
'//
'//  this will put out on the wire guid of binary 0x004826BF6CF000123444
'//
'//  Note : don't call this for attribute values that are really strings, as
'//  we won't do any conversion from what you passed in to UTF-8.  Should only
'//  be used for attributes that really are raw binary.
'//

DECLARE FUNCTION ldap_escape_filter_elementW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_escape_filter_elementW" ( _
   BYREF sourceFilterElement AS ASCIIZ _                ' __in  PCHAR sourceFilterElement
 , BYVAL sourceLength AS DWORD _                        ' __in  ULONG sourceLength
 , BYREF destFilterElement AS WSTRINGZ _                ' __out PWCHAR destFilterElement
 , BYVAL destLength AS DWORD _                          ' __in  ULONG destLength
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_escape_filter_elementA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_escape_filter_elementA" ( _
   BYREF sourceFilterElement AS ASCIIZ _                ' __in  PCHAR sourceFilterElement
 , BYVAL sourceLength AS DWORD _                        ' __in  ULONG sourceLength
 , BYREF destFilterElement AS ASCIIZ _                  ' __out PCHAR destFilterElement
 , BYVAL destLength AS DWORD _                          ' __in  ULONG destLength
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_escape_filter_element = ldap_escape_filter_elementW
#ELSE
   MACRO ldap_escape_filter_element = ldap_escape_filter_elementA
#ENDIF

'//
'//  Misc extensions for additional debugging.
'//
'//  Note that these do nothing on free builds.
'//

DECLARE FUNCTION ldap_set_dbg_flags CDECL IMPORT "Wldap32.dll" ALIAS "ldap_set_dbg_flags" ( _
   BYVAL NewFlags AS DWORD _                            ' __in ULONG NewFlags
 ) AS DWORD                                             ' ULONG

'typedef ULONG (_cdecl *DBGPRINT)( PCCH Format, ... );

'WINLDAPAPI VOID LDAPAPI ldap_set_dbg_routine( DBGPRINT DebugPrintRoutine );

'//
'//  These routines are possibly useful by other modules.  Note that Win95
'//  doesn't by default have the UTF-8 codepage loaded.  So a good way to
'//  convert from UTF-8 to Unicode.
'//


DECLARE FUNCTION LdapUTF8ToUnicode CDECL IMPORT "Wldap32.dll" ALIAS "LdapUTF8ToUnicode" ( _
   BYREF lpSrcStr AS ASCIIZ _                           ' __in  LPCSTR lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in  int cchSrc
 , BYREF lpDestStr AS WSTRINGZ _                        ' __out LPWSTR lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in  int cchDest
 ) AS LONG                                              ' INT

DECLARE FUNCTION LdapUnicodeToUTF8 CDECL IMPORT "Wldap32.dll" ALIAS "LdapUnicodeToUTF8" ( _
   BYVAL lpSrcStr AS DWORD _                            ' __in  LPCWSTR lpSrcStr
 , BYVAL cchSrc AS LONG _                               ' __in  int cchSrc
 , BYREF lpDestStr AS ASCIIZ _                          ' __out LPSTR lpDestStr
 , BYVAL cchDest AS LONG _                              ' __in  int cchDest
 ) AS LONG                                              ' INT

'//
'//  LDAPv3 features :
'//
'//  Sort Keys... these are used to ask the server to sort the results
'//  before sending the results back.  LDAPv3 only and optional to implement
'//  on the server side.  Check supportedControl for an OID of
'//  "1.2.840.113556.1.4.473" to see if the server supports it.
'//

$LDAP_SERVER_SORT_OID = "1.2.840.113556.1.4.473"
$$LDAP_SERVER_SORT_OID = "1.2.840.113556.1.4.473"$$

$LDAP_SERVER_RESP_SORT_OID = "1.2.840.113556.1.4.474"
$$LDAP_SERVER_RESP_SORT_OID = "1.2.840.113556.1.4.474"$$

'typedef struct ldapsearch LDAPSearch, *PLDAPSearch;

' // Size = 12 bytes
TYPE LDAPSortKeyW DWORD
   sk_attrtype     AS WSTRINGZ PTR   ' PWCHAR
   sk_matchruleoid AS WSTRINGZ PTR   ' PWCHAR
   sk_reverseorder AS BYTE           ' BOOLEAN
END TYPE

' // Size = 12 bytes
TYPE LDAPSortKeyA DWORD
   sk_attrtype     AS ASCIIZ PTR   ' PCHAR
   sk_matchruleoid AS ASCIIZ PTR   ' PCHAR
   sk_reverseorder AS BYTE         ' BOOLEAN
END TYPE


'//
'//  This API formats a list of sort keys into a search control.  Call
'//  ldap_control_free when you're finished with the control.
'//
'//  Use this one rather than ldap_encode_sort_control as this is per RFC.
'//

DECLARE FUNCTION ldap_create_sort_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_sort_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF SortKeys AS LDAPSortKeyA _                     ' __in  PLDAPSortKeyA *SortKeys
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR IsCritical
 , BYREF Control AS DWORD _                             ' __out PLDAPControlA *Control
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_create_sort_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_sort_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF SortKeys AS LDAPSortKeyW _                     ' __in  PLDAPSortKeyW *SortKeys
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR IsCritical
 , BYREF Control AS DWORD _                             ' __out PLDAPControlW *Control
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_create_sort_control = ldap_create_sort_controlW
#ELSE
   MACRO ldap_create_sort_control = ldap_create_sort_controlA
#ENDIF

'//
'//  This API parses the sort control returned by the server.  Use ldap_memfree
'//  to free the attribute value, if it's returned.
'//

DECLARE FUNCTION ldap_parse_sort_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_sort_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL Control AS LDAPControlA PTR _                  ' __in  PLDAPControlA *Control
 , BYREF Result AS DWORD _                              ' __out ULONG *Result
 , BYREF Attribute AS DWORD _                           ' __out PCHAR *Attribute
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_parse_sort_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_sort_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL Control AS LDAPControlW PTR _                  ' __in  PLDAPControlW *Control
 , BYREF Result AS DWORD _                              ' __out ULONG *Result
 , BYREF Attribute AS DWORD _                           ' __out PWCHAR *Attribute
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_parse_sort_control = ldap_parse_sort_controlW
#ELSE
   MACRO ldap_parse_sort_control = ldap_parse_sort_controlA
#ENDIF


'//
'//  This API formats a list of sort keys into a search control.  Call
'//  ldap_memfree for both Control->ldctl_value.bv_val and
'//  Control->currentControl->ldctl_oid when you're finished with the control.
'//
'//  This is the old sort API that will be shortly pulled.  Please use
'//  ldap_create_sort_control defined above.
'//

DECLARE FUNCTION ldap_encode_sort_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_encode_sort_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF SortKeys AS LDAPSortKeyW _                     ' __in  PLDAPSortKeyW *SortKeys
 , BYREF Control AS DWORD _                             ' __out PLDAPControlW Control
 , BYVAL Criticality AS BYTE _                          ' __in  BOOLEAN Criticality
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_encode_sort_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_encode_sort_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF SortKeys AS LDAPSortKeyA _                     ' __in  PLDAPSortKeyA *SortKeys
 , BYREF Control AS DWORD _                             ' __out PLDAPControlA Control
 , BYVAL Criticality AS BYTE _                          ' __in  BOOLEAN Criticality
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_encode_sort_control = ldap_encode_sort_controlW
#ELSE
   MACRO ldap_encode_sort_control = ldap_encode_sort_controlA
#ENDIF

'//
'//  LDAPv3: This is the RFC defined API for the simple paging of results
'//  control.  Use ldap_control_free to free the control allocated by
'//  ldap_create_page_control.
'//

DECLARE FUNCTION ldap_create_page_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_page_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL PageSize AS DWORD _                            ' __in  ULONG PageSize
 , BYVAL Cookie AS berval PTR _                         ' __in  struct berval *Cookie
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR IsCritical
 , BYREF Control AS DWORD _                             ' __out PLDAPControlW *Control
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_create_page_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_page_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL PageSize AS DWORD _                            ' __in  ULONG PageSize
 , BYVAL Cookie AS berval PTR _                         ' __in  struct berval *Cookie
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR IsCritical
 , BYREF Control AS DWORD _                             ' __out PLDAPControlA *Control
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_create_page_control = ldap_create_page_controlW
#ELSE
   MACRO ldap_create_page_control = ldap_create_page_controlA
#ENDIF

DECLARE FUNCTION ldap_parse_page_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_page_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYREF TotalCount AS DWORD _                          ' __out ULONG *TotalCount
 , BYREF Cookie AS DWORD _                              ' __out struct berval **Cookie   // Use ber_bvfree to free
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_parse_page_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_page_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYREF TotalCount AS DWORD _                          ' __out ULONG *TotalCount
 , BYREF Cookie AS DWORD _                              ' __out struct berval **Cookie   // Use ber_bvfree to free
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_parse_page_control = ldap_parse_page_controlW
#ELSE
   MACRO ldap_parse_page_control = ldap_parse_page_controlA
#ENDIF

'//
'//  LDAPv3: This is the interface for simple paging of results.  To ensure
'//  that the server supports it, check the supportedControl property off of
'//  the root for an OID of 1.2.840.113556.1.4.319.  If it is there, then it
'//  supports this feature.
'//
'//  If you're going to specify sort keys, see section above on sort keys on
'//  now to tell if they're supported by the server.
'//
'//  You first call ldap_search_init_page.  If it returns a non-NULL LDAPSearch
'//  block, then it worked ok.  Otherwise call LdapGetLastError to find error.
'//
'//  With a valid LDAPSearch block (there are opaque), call ldap_get_next_page
'//  or ldap_get_next_page_s.  If you call ldap_get_next_page, you MUST call
'//  ldap_get_paged_count for each set of results that you get for that message.
'//  This allows the library to save off the cookie that the server sent to
'//  resume the search.
'//
'//  Other than calling ldap_get_paged_count, the results you get back from
'//  ldap_get_next_page can be treated as any other search result, and should
'//  be freed when you're done by calling ldap_msgfree.
'//
'//  When the end of the search is hit, you'll get a return code of
'//  LDAP_NO_RESULTS_RETURNED.  At this point, (or any point after LDAPSearch
'//  structure has been allocated), you call ldap_search_abandon_page.  You
'//  need to call this even after you get a return code of
'//  LDAP_NO_RESULTS_RETURNED.
'//
'//  If you call ldap_get_next_page_s, you don't need to call
'//  ldap_get_paged_count.
'//

$LDAP_PAGED_RESULT_OID_STRING = "1.2.840.113556.1.4.319"
$$LDAP_PAGED_RESULT_OID_STRING_W = "1.2.840.113556.1.4.319"$$

DECLARE FUNCTION ldap_search_init_pageW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_init_pageW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP          *ExternalHandle
 , BYREF DistinguishedName AS WSTRINGZ _                ' __in const PWCHAR   DistinguishedName
 , BYVAL ScopeOfSearch AS DWORD _                       ' __in ULONG          ScopeOfSearch
 , BYREF SearchFilter AS WSTRINGZ _                     ' __in const PWCHAR   SearchFilter
 , BYVAL AttributeList AS DWORD _                       ' __in PWCHAR         AttributeList[]
 , BYVAL AttributesOnly AS DWORD _                      ' __in ULONG          AttributesOnly
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in PLDAPControlW *ClientControls
 , BYVAL PageTimeLimit AS DWORD _                       ' __in ULONG          PageTimeLimit
 , BYVAL TotalSizeLimit AS DWORD _                      ' __in ULONG          TotalSizeLimit
 ) AS DWORD                                             ' PLDAPSearch

DECLARE FUNCTION ldap_search_init_pageA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_init_pageA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in LDAP          *ExternalHandle
 , BYREF DistinguishedName AS ASCIIZ _                  ' __in const PCHAR    DistinguishedName
 , BYVAL ScopeOfSearch AS DWORD _                       ' __in ULONG          ScopeOfSearch
 , BYREF SearchFilter AS ASCIIZ _                       ' __in const PCHAR    SearchFilter
 , BYVAL AttributeList AS DWORD _                       ' __in PCHAR          AttributeList[]
 , BYVAL AttributesOnly AS DWORD _                      ' __in ULONG          AttributesOnly
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in PLDAPControlA *ClientControls
 , BYVAL PageTimeLimit AS DWORD _                       ' __in ULONG          PageTimeLimit
 , BYVAL TotalSizeLimit AS DWORD _                      ' __in ULONG          TotalSizeLimit
 ) AS DWORD                                             ' PLDAPSearch

#IF %DEF(%UNICODE)
   MACRO ldap_search_init_page = ldap_search_init_pageW
#ELSE
   MACRO ldap_search_init_page = ldap_search_init_pageA
#ENDIF

DECLARE FUNCTION ldap_get_next_page CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_next_page" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP        *ExternalHandle
 , BYVAL SearchHandle AS DWORD _                        ' __in  PLDAPSearch  SearchHandle
 , BYVAL PageSize AS DWORD _                            ' __in  ULONG        PageSize
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG       *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_get_next_page_s CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_next_page_s" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP             *ExternalHandle
 , BYVAL SearchHandle AS DWORD _                        ' __in  PLDAPSearch       SearchHandle
 , BYREF timeout AS l_timeval _                         ' __in  struct l_timeval *timeout
 , BYVAL PageSize AS DWORD _                            ' __in  ULONG             PageSize
 , BYREF TotalCount AS DWORD _                          ' __out ULONG            *TotalCount
 , BYREF Results AS DWORD _                             ' __out LDAPMessage     **Results
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_get_paged_count CDECL IMPORT "Wldap32.dll" ALIAS "ldap_get_paged_count" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP             *ExternalHandle
 , BYVAL SearchBlock AS DWORD _                         ' __in  PLDAPSearch       SearchBlock
 , BYREF TotalCount AS DWORD _                          ' __out ULONG            *TotalCount
 , BYVAL Results AS LDAPMessage PTR _                   ' __in  PLDAPMessage      Results
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_search_abandon_page CDECL IMPORT "Wldap32.dll" ALIAS "ldap_search_abandon_page" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP             *ExternalHandle
 , BYVAL SearchBlock AS DWORD _                         ' __in  PLDAPSearch       SearchBlock
 ) AS DWORD                                             ' ULONG


'//
'// The Virtual List View (VLV) functions are used to simulate an address book
'// like client scenario where the user can request a small window of results
'// within a larger result set. The advantage of this method is that the client
'// does not have to store all of the results sent back from the server. This
'// also acts as a superset of simple paging.
'//

$LDAP_CONTROL_VLVREQUEST      = "2.16.840.1.113730.3.4.9"
$$LDAP_CONTROL_VLVREQUEST_W   = "2.16.840.1.113730.3.4.9"$$

$LDAP_CONTROL_VLVRESPONSE     = "2.16.840.1.113730.3.4.10"
$$LDAP_CONTROL_VLVRESPONSE_W  = "2.16.840.1.113730.3.4.10"$$

'//
'// This library supports the version 01 of the internet draft
'// draft-smith-ldap-c-api-ext-vlv-01.txt
'//

%LDAP_API_FEATURE_VIRTUAL_LIST_VIEW = 1001

%LDAP_VLVINFO_VERSION = 1

' // Size = 32 bytes
TYPE LDAPVLVInfo DWORD
   ldvlv_version      AS LONG         ' int // version of this struct (1)
   ldvlv_before_count AS DWORD        ' ULONG
   ldvlv_after_count  AS DWORD        ' ULONG
   ldvlv_offset       AS DWORD        ' ULONG // used if ldvlv_attrvalue is NULL
   ldvlv_count        AS DWORD        ' ULONG // used if ldvlv_attrvalue is NULL
   ldvlv_attrvalue    AS BERVAL PTR   ' PBERVAL
   ldvlv_context      AS BERVAL PTR   ' PBERVAL
   ldvlv_extradata    AS DWORD        ' PVOID* // for use by application
END TYPE

DECLARE FUNCTION ldap_create_vlv_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_vlv_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP          *ExternalHandle
 , BYREF VlvInfo AS LDAPVLVInfo _                       ' __in  PLDAPVLVInfo   VlvInfo
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR          IsCritical
 , BYVAL Control AS LDAPControlW PTR _                  ' __in  PLDAPControlW *Control
 ) AS LONG                                              ' INT

DECLARE FUNCTION ldap_create_vlv_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_create_vlv_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP          *ExternalHandle
 , BYREF VlvInfo AS LDAPVLVInfo _                       ' __in  PLDAPVLVInfo   VlvInfo
 , BYVAL IsCritical AS BYTE _                           ' __in  UCHAR          IsCritical
 , BYVAL Control AS LDAPControlA PTR _                  ' __in  PLDAPControlA *Control
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO ldap_create_vlv_control = ldap_create_vlv_controlW
#ELSE
   MACRO ldap_create_vlv_control = ldap_create_vlv_controlA
#ENDIF

DECLARE FUNCTION ldap_parse_vlv_controlW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_vlv_controlW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP          *ExternalHandle
 , BYVAL Control AS LDAPControlW PTR _                  ' __in  PLDAPControlW *Control
 , BYREF TargetPos AS DWORD _                           ' __out PULONG         TargetPos
 , BYREF ListCount AS DWORD _                           ' __out PULONG         ListCount
 , BYREF Context AS DWORD _                             ' __out PBERVAL       *Context
 , BYREF ErrCode AS LONG _                              ' __out PINT           ErrCode
 ) AS LONG                                              ' INT

DECLARE FUNCTION ldap_parse_vlv_controlA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_vlv_controlA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP          *ExternalHandle
 , BYVAL Control AS LDAPControlA PTR _                  ' __in  PLDAPControlA *Control
 , BYREF TargetPos AS DWORD _                           ' __out PULONG         TargetPos
 , BYREF ListCount AS DWORD _                           ' __out PULONG         ListCount
 , BYREF Context AS DWORD _                             ' __out PBERVAL       *Context
 , BYREF ErrCode AS LONG _                              ' __out PINT           ErrCode
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO ldap_parse_vlv_control = ldap_parse_vlv_controlW
#ELSE
   MACRO ldap_parse_vlv_control = ldap_parse_vlv_controlA
#ENDIF

'//
'// The StartTLS APIs are used for establishing Transport Layer Security on
'// the fly.
'//

$LDAP_START_TLS_OID       = "1.3.6.1.4.1.1466.20037"
$$LDAP_START_TLS_OID_W    = "1.3.6.1.4.1.1466.20037"$$

'//
'// This API is called by users to initiate Transport Level Security on an
'// LDAP connection. If the server accepts our proposal and initiates TLS,
'// this API will return LDAP_SUCCESS.
'//
'// If the server fails the request for whatever reason, the API returns LDAP_OTHER
'// and the ServerReturnValue will contain the error code from the server.
'//
'// It is possible that the server returns a referral - either in response to the
'// StartTLS request or during the subsequent encrypted session. For security
'// reasons, we have decided to NOT chase referrals by default. In the former case
'// the referral message is returned as an LDAPMessage to the user.
'//
'// The operation has a default timeout of about 30 seconds.
'//

DECLARE FUNCTION ldap_start_tls_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_start_tls_sW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP           *ExternalHandle
 , BYREF ServerReturnValue AS DWORD _                   ' __out PULONG          ServerReturnValue
 , BYREF result AS DWORD _                              ' __out LDAPMessage   **result
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW  *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW  *ClientControls
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_start_tls_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_start_tls_sA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP           *ExternalHandle
 , BYREF ServerReturnValue AS DWORD _                   ' __out PULONG          ServerReturnValue
 , BYREF result AS DWORD _                              ' __out LDAPMessage   **result
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA  *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA  *ClientControls
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_start_tls_s = ldap_start_tls_sW
#ELSE
   MACRO ldap_start_tls_s = ldap_start_tls_sA
#ENDIF

'//
'// This API is called by the user to stop Transport Level Security on an open
'// LDAP connection on which TLS has already been started.
'//
'// If the operation succeeds, the user can resume normal plaintext LDAP
'// operations on the connection.
'//
'// If the operation fails, the user MUST close the connection by calling
'// ldap_unbind as the TLS state of the connection will be indeterminate.
'//
'// The operation has a default timeout of about 30 seconds.
'//

DECLARE FUNCTION ldap_stop_tls_s CDECL IMPORT "Wldap32.dll" ALIAS "ldap_stop_tls_s" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 ) AS BYTE                                              ' BOOLEAN

'//
'// This OID is used in a Refresh Extended operation as defined in
'// RFC 2589: LDAP v3 Extensions for Dynamic Directory Services
'//

$LDAP_TTL_EXTENDED_OP_OID    = "1.3.6.1.4.1.1466.101.119.1"
$$LDAP_TTL_EXTENDED_OP_OID_W = "1.3.6.1.4.1.1466.101.119.1"$$

'//
'//  These functions return subordinate referrals (references) that are returned
'//  in search responses.  There are two types of referrals.  External referrals
'//  where the naming context doesn't reside on the server (e.g. server says "I
'//  don't have the data, look over there") and Subordinate referrals (or
'//  references) where some data has been returned and the referrals are passed
'//  to other naming contexts below the current one (e.g. servers says "Here's
'//  some data from the tree I hold, go look here, there, and over there for
'//  more data that is further down in the tree.").
'//
'//  These routines handle the latter.  For external references, use
'//  ldap_parse_result.
'//
'//  Return the first reference from a message.  It is freed when the message is
'//  freed so should not be freed explicitly.
'//

DECLARE FUNCTION ldap_first_reference CDECL IMPORT "Wldap32.dll" ALIAS "ldap_first_reference" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' LDAPMessage

'//
'//  Return the next entry of a message.  It is freed when the message is
'//  freed so should not be freed explicitly.
'//

DECLARE FUNCTION ldap_first_reference CDECL IMPORT "Wldap32.dll" ALIAS "ldap_first_reference" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL entry AS LDAPMessage PTR _                     ' __in LDAPMessage *entry
 ) AS DWORD                                             ' LDAPMessage

'//
'//  Count the number of subordinate references returned by the server in a
'//  response to a search request.
'//

DECLARE FUNCTION ldap_count_references CDECL IMPORT "Wldap32.dll" ALIAS "ldap_count_references" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP *ld
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' LDAPMessage

'//
'//  We return the list of subordinate referrals in a search response message.
'//

DECLARE FUNCTION ldap_parse_referenceW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_referenceW" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in  LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in  LDAPMessage *ResultMessage
 , BYREF Referrals AS DWORD _                           ' __out PWCHAR **Referrals // free with ldap_value_freeW
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_parse_referenceA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_parse_referenceA" ( _
   BYVAL Connection AS LDAP PTR _                       ' __in  LDAP *Connection
 , BYVAL ResultMessage AS LDAPMessage PTR _             ' __in  LDAPMessage *ResultMessage
 , BYREF Referrals AS DWORD _                           ' __out PCHAR **Referrals // free with ldap_value_freeA
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_parse_reference = ldap_parse_referenceW
#ELSE
   MACRO ldap_parse_reference = ldap_parse_referenceA
#ENDIF

'//
'//  These APIs allow a client to send an extended request (free for all) to
'//  an LDAPv3 (or above) server.  The functionality is fairly open... you can
'//  send any request you'd like.  Note that since we don't know if you'll
'//  be receiving a single or multiple responses, you'll have to explicitly tell
'//  us when you're done with the request by calling ldap_close_extended_op.
'//
'//  These are thread safe.
'//

DECLARE FUNCTION ldap_extended_operationW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_extended_operationW" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF Oid AS WSTRINGZ _                              ' __in  const PWCHAR Oid
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_extended_operationA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_extended_operationA" ( _
   BYVAL ld AS LDAP PTR _                               ' __in  LDAP *ld
 , BYREF Oid AS ASCIIZ _                                ' __in  const PCHAR Oid
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF MessageNumber AS DWORD _                       ' __out ULONG *MessageNumber
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_extended_operation = ldap_extended_operationW
#ELSE
   MACRO ldap_extended_operation = ldap_extended_operationA
#ENDIF

DECLARE FUNCTION ldap_extended_operation_sA CDECL IMPORT "Wldap32.dll" ALIAS "ldap_extended_operation_sA" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF Oid AS ASCIIZ _                                ' __in  const PCHAR Oid
 , BYVAL Data AS berval PTR _                           ' __in  struct berval *Data
 , BYVAL ServerControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ServerControls
 , BYVAL ClientControls AS LDAPControlA PTR _           ' __in  PLDAPControlA *ClientControls
 , BYREF ReturnedOid AS DWORD _                         ' __out ULONG *ReturnedOid
 , BYREF ReturnedData AS DWORD _                        ' __out struct berval **ReturnedData
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ldap_extended_operation_sW CDECL IMPORT "Wldap32.dll" ALIAS "ldap_extended_operation_sW" ( _
   BYVAL ExternalHandle AS LDAP PTR _                   ' __in  LDAP *ExternalHandle
 , BYREF Oid AS WSTRINGZ _                              ' __in  const PWCHAR Oid
 , BYVAL Data AS berval PTR _                           ' __in  struct berval *Data
 , BYVAL ServerControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ServerControls
 , BYVAL ClientControls AS LDAPControlW PTR _           ' __in  PLDAPControlW *ClientControls
 , BYREF ReturnedOid AS DWORD _                         ' __out ULONG *ReturnedOid
 , BYREF ReturnedData AS DWORD _                        ' __out struct berval **ReturnedData
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ldap_extended_operation_s = ldap_extended_operation_sW
#ELSE
   MACRO ldap_extended_operation_s = ldap_extended_operation_sA
#ENDIF

DECLARE FUNCTION ldap_close_extended_op CDECL IMPORT "Wldap32.dll" ALIAS "ldap_close_extended_op" ( _
   BYVAL ld AS LDAP PTR _                               ' __in LDAP  *ld
 , BYVAL MessageNumber AS DWORD _                       ' __in ULONG  MessageNumber
 ) AS DWORD                                             ' ULONG

'//
'//  Some enhancements that will probably never make it into the RFC related
'//  to callouts to allow external caching of connections.
'//
'//  Call ldap_set_option( conn, LDAP_OPT_REFERRAL_CALLBACK, &referralRoutines )
'//  where referralRoutines is the address of an LDAP_REFERRAL_CALLBACK
'//  structure with your routines.  They may be NULL, in which case we'll
'//  obviously not make the calls.
'//
'//  Any connections that are created will inherit the current callbacks from
'//  the primary connection that the request was initiated on.
'//

%LDAP_OPT_REFERRAL_CALLBACK = &H70&

'//
'//  This first routine is called when we're about to chase a referral.  We
'//  callout to it to see if there is already a connection cached that we
'//  can use.  If so, the callback routine returns the pointer to the
'//  connection to use in ConnectionToUse.  If not, it sets
'//  *ConnectionToUse to NULL.
'//
'//  For a return code, it should return 0 if we should continue to chase the
'//  referral.  If it returns a non-zero return code, we'll treat that as the
'//  error code for chasing the referral.  This allows caching of host names
'//  that are not reachable, if we decide to add that in the future.
'//

'typedef ULONG (_cdecl QUERYFORCONNECTION)(
'    PLDAP       PrimaryConnection,
'    PLDAP       ReferralFromConnection,
'    PWCHAR      NewDN,
'    PCHAR       HostName,
'    ULONG       PortNumber,
'    PVOID       SecAuthIdentity,    // if null, use CurrentUser below
'    PVOID       CurrentUserToken,   // pointer to current user's LUID
'    PLDAP       *ConnectionToUse
'    );

'FUNCTION QUERYFORCONNECTION CDECL ( _
'   BYVAL PrimaryConnection AS LDAP PTR _                ' __in  PLDAP       PrimaryConnection
' , BYVAL ReferralFromConnection AS LDAP PTR _           ' __in  PLDAP       ReferralFromConnection
' , BYREF NewDN AS WSTRINGZ _                            ' __in  PWCHAR      NewDN
' , BYREF HostName AS ASCIIZ _                           ' __in  PCHAR       HostName
' , BYVAL PortNumber AS DWORD _                          ' __in  ULONG       PortNumber
' , BYVAL SecAuthIdentity AS DWORD _                     ' __in  PVOID       SecAuthIdentity // if null, use CurrentUser below
' , BYVAL CurrentUserToken AS DWORD _                    ' __in  PVOID       CurrentUserToken // pointer to current user's LUID
' , BYREF ConnectionToUse AS DWORD _                     ' __out PLDAP      *ConnectionToUse
' ) AS DWORD                                             ' ULONG

'//
'//  This next function is called when we've created a new connection while
'//  chasing a referral.  Note that it gets assigned the same callback functions
'//  as the PrimaryConnection.  If the return code is FALSE, then the call
'//  back function doesn't want to cache the connection and it will be
'//  destroyed after the operation is complete.  If TRUE is returned, we'll
'//  assume that the callee has taken ownership of the connection and it will
'//  not be destroyed after the operation is complete.
'//
'//  If the ErrorCodeFromBind field is not 0, then the bind operation to
'//  that server failed.
'//

'typedef BOOLEAN (_cdecl NOTIFYOFNEWCONNECTION) (
'    PLDAP       PrimaryConnection,
'    PLDAP       ReferralFromConnection,
'    PWCHAR      NewDN,
'    PCHAR       HostName,
'    PLDAP       NewConnection,
'    ULONG       PortNumber,
'    PVOID       SecAuthIdentity,    // if null, use CurrentUser below
'    PVOID       CurrentUser,        // pointer to current user's LUID
'    ULONG       ErrorCodeFromBind
'    );

'FUNCTION NOTIFYOFNEWCONNECTION CDECL ( _
'   BYVAL PrimaryConnection AS LDAP PTR _                ' __in PLDAP  PrimaryConnection
' , BYVAL ReferralFromConnection AS LDAP PTR _           ' __in PLDAP  ReferralFromConnection
' , BYREF NewDN AS WSTRINGZ _                            ' __in PWCHAR NewDN
' , BYREF HostName AS ASCIIZ _                           ' __in PCHAR  HostName
' , BYVAL NewConnection AS LDAP PTR _                    ' __in PLDAP  NewConnection
' , BYVAL PortNumber AS DWORD _                          ' __in ULONG  PortNumber
' , BYVAL SecAuthIdentity AS DWORD _                     ' __in PVOID  SecAuthIdentity // if null, use CurrentUser below
' , BYVAL CurrentUser AS DWORD _                         ' __in PVOID  CurrentUserToken // pointer to current user's LUID
' , BYVAL ErrorCodeFromBind AS DWORD _                   ' __in ULONG  ErrorCodeFromBind
' ) AS BYTE                                              ' BOOLEAN

'//
'//  This next function is called when we've successfully called off to the
'//  QueryForConnection call and received a connection OR when we called off
'//  to the NotifyOfNewConnection call and it returned TRUE.  We call this
'//  function when we're dereferencing the connection after we're done with it.
'//
'//  Return code is currently ignored, but the function should return
'//  LDAP_SUCCESS if all went well.
'//

'typedef ULONG (_cdecl DEREFERENCECONNECTION)(
'    PLDAP       PrimaryConnection,
'    PLDAP       ConnectionToDereference
'    );

'FUNCTION DEREFERENCECONNECTION CDECL ( _
'   BYVAL PrimaryConnection AS LDAP PTR _                ' __in  PLDAP       PrimaryConnection
' , BYVAL ConnectionToDereference AS LDAP PTR _          ' __in  PLDAP       ConnectionToDereference
' ) AS DWORD                                             ' ULONG

' // Size = 16 bytes
TYPE LdapReferralCallback DWORD
   SizeOfCallbacks    AS DWORD   ' ULONG // set to sizeof( LDAP_REFERRAL_CALLBACK )
   QueryForConnection AS DWORD   ' QUERYFORCONNECTION*
   NotifyRoutine      AS DWORD   ' NOTIFYOFNEWCONNECTION*
   DereferenceRoutine AS DWORD   ' DEREFERENCECONNECTION*
END TYPE

MACRO LDAP_REFERRAL_CALLBACK = LdapReferralCallback

'//
'//  Thread Safe way to get last error code returned by LDAP API is to call
'//  LdapGetLastError();
'//

DECLARE FUNCTION LdapGetLastError CDECL IMPORT "Wldap32.dll" ALIAS "LdapGetLastError" ( _
 ) AS DWORD                                             ' ULONG

'//
'//  Translate from LdapError to closest Win32 error code.
'//

DECLARE FUNCTION LdapMapErrorToWin32 CDECL IMPORT "Wldap32.dll" ALIAS "LdapMapErrorToWin32" ( _
   BYVAL LdapError AS DWORD _                           ' __in ULONG LdapError
 ) AS DWORD                                             ' ULONG

'//
'// This is an arrangement for specifying client certificates while establishing
'// an SSL connection.
'// Simply Call ldap_set_option( conn, LDAP_OPT_CLIENT_CERTIFICATE, &CertRoutine )
'// where CertRoutine is the address of your callback routine. If it is NULL,
'// we will obviously not make the call.
'//

%LDAP_OPT_CLIENT_CERTIFICATE    = &H80&

'//
'// This callback is invoked when the server demands a client certificate for
'// authorization. The application should examine the list of Certificate Authorities
'// the server trusts and supply an appropriate client certificate. wldap32.dll
'// subsequently passes these credentials to the SSL server as part of the
'// handshake. If the application desires that anonymous credentials be used,
'// it must return FALSE instead of a certificate. Any certificate must be freed
'// by the application after the connection has been completed. Note that the
'// application MUST perform an EXTERNAL bind subsequent to connection
'// establishment for these credentials to be used by the server.
'//

'typedef BOOLEAN (_cdecl QUERYCLIENTCERT) (
'    IN PLDAP Connection,
'    IN PSecPkgContext_IssuerListInfoEx trusted_CAs,
'    IN OUT PCCERT_CONTEXT *ppCertificate
'    );

'FUNCTION QUERYCLIENTCERT CDECL ( _
'   BYVAL Connection AS LDAP PTR _                          ' __in PLDAP Connection
' , BYREF trusted_CAs AS SecPkgContext_IssuerListInfoEx _   ' __in PSecPkgContext_IssuerListInfoEx trusted_CAs
' , BYREF ppCertificate AS CERT_CONTEXT _                   ' __in_out PCCERT_CONTEXT* ppCertificate
' ) AS BYTE                                                 ' BOOLEAN

'//
'// We are also giving an opportunity for the client to verify the certificate
'// of the server. The client registers a callback which is invoked after the
'// secure connection is setup. The server certificate is presented to the
'// client who invokes it and decides it it is acceptable. To register this
'// callback, simply call ldap_set_option( conn, LDAP_OPT_SERVER_CERTIFICATE, &CertRoutine )
'//

%LDAP_OPT_SERVER_CERTIFICATE    = &H81&

'//
'// This function is called after the secure connection has been established. The
'// certificate of the server is supplied for examination by the client. If the
'// client approves it, it returns TRUE else, it returns false and the secure
'// connection is torn down.
'//

'typedef BOOLEAN (_cdecl VERIFYSERVERCERT) (
'     PLDAP Connection,
'     PCCERT_CONTEXT* pServerCert
'     );

'FUNCTION VERIFYSERVERCERT CDECL ( _
'   BYVAL Connection AS LDAP PTR _                       ' __in PLDAP Connection
' , BYREF pServerCert AS CERT_CONTEXT _                  ' __in PCCERT_CONTEXT* pServerCert
' ) AS BYTE                                              ' BOOLEAN

'//
'//  Given an LDAP message, return the connection pointer where the message
'//  came from.  It can return NULL if the connection has already been freed.
'//

DECLARE FUNCTION ldap_conn_from_msg CDECL IMPORT "Wldap32.dll" ALIAS "ldap_conn_from_msg" ( _
   BYVAL PrimaryConn AS LDAP PTR _                      ' __in LDAP *PrimaryConn
 , BYVAL res AS LDAPMessage PTR _                       ' __in LDAPMessage *res
 ) AS DWORD                                             ' LDAP*

'//
'//  Do we reference the connection for each message so that we can safely get
'//  the connection pointer back by calling ldap_conn_from_msg?
'//

%LDAP_OPT_REF_DEREF_CONN_PER_MSG = &H94&

'#endif  // LDAP_CLIENT_DEFINED
