' ########################################################################################
' Microsoft Windows
' File: MAPICode.inc
' Contents: Status Codes returned by MAPI routines
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPICODE_INC = 1

'/* Define S_OK and ITF_* */

#INCLUDE ONCE "winerror.inc"

'/*
' *   MAPI Status codes follow the style of OLE 2.0 sCodes as defined in the
' *   OLE 2.0 Programmer's Reference and header file scode.h (Windows 3.x)
' *   or winerror.h (Windows NT and Windows 95).
' *
' */

'/*  On Windows 3.x, status codes have 32-bit values as follows:
' *
' *   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
' *   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
' *  +-+---------------------+-------+-------------------------------+
' *  |S|       Context       | Facil |               Code            |
' *  +-+---------------------+-------+-------------------------------+
' *
' *  where
' *
' *      S - is the severity code
' *
' *          0 - SEVERITY_SUCCESS
' *          1 - SEVERITY_ERROR
' *
' *      Context - context info
' *
' *      Facility - is the facility code
' *
' *         0x0 - FACILITY_NULL      generally useful errors ([SE]_*)
' *         0x1 - FACILITY_RPC      remote procedure call errors (RPC_E_*)
' *         0x2 - FACILITY_DISPATCH late binding dispatch errors
' *         0x3 - FACILITY_STORAGE  storage errors (STG_E_*)
' *         0x4 - FACILITY_ITF      interface-specific errors
' *
' *      Code - is the facility's status code
' *
' *
' */

'/*
' *   On Windows NT 3.5 and Windows 95, scodes are 32-bit values
' *   laid out as follows:
' *
' *     3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
' *     1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
' *    +-+-+-+-+-+---------------------+-------------------------------+
' *    |S|R|C|N|r|    Facility         |               Code            |
' *    +-+-+-+-+-+---------------------+-------------------------------+
' *
' *    where
' *
' *       S - Severity - indicates success/fail
' *
' *           0 - Success
' *           1 - Fail (COERROR)
' *
' *       R - reserved portion of the facility code, corresponds to NT's
' *           second severity bit.
' *
' *       C - reserved portion of the facility code, corresponds to NT's
' *           C field.
' *
' *       N - reserved portion of the facility code. Used to indicate a
' *           mapped NT status value.
' *
' *       r - reserved portion of the facility code. Reserved for internal
' *           use. Used to indicate HRESULT values that are not status
' *           values, but are instead message ids for display strings.
' *
' *       Facility - is the facility code
' *         FACILITY_NULL                    0x0
' *         FACILITY_RPC                     0x1
' *         FACILITY_DISPATCH                0x2
' *         FACILITY_STORAGE                 0x3
' *         FACILITY_ITF                     0x4
' *         FACILITY_WIN32                   0x7
' *         FACILITY_WINDOWS                 0x8
' *
' *       Code - is the facility's status code
' *
' */



'/*
' *    We can't use OLE 2.0 macros to build sCodes because the definition has
' *   changed and we wish to conform to the new definition.
' */
'#define MAKE_MAPI_SCODE(sev,fac,code) \
'    ((SCODE) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )

FUNCTION MAKE_MAPI_SCODE (BYVAL sev AS DWORD, BYVAL fac AS DWORD, BYVAL code AS DWORD) AS LONG
   SHIFT LEFT sev, 31
   SHIFT LEFT fac, 16
   FUNCTION = BITS(LONG, sev OR fac OR code)
END FUNCTION

'/* The following two macros are used to build OLE 2.0 style sCodes */

'#define MAKE_MAPI_E( err )   (MAKE_MAPI_SCODE( 1, FACILITY_ITF, err ))

FUNCTION MAKE_MAPI_E (BYVAL errn AS DWORD) AS DWORD
   FUNCTION = MAKE_MAPI_SCODE(1, %FACILITY_ITF, errn)
END FUNCTION

'#define MAKE_MAPI_S( warn )   (MAKE_MAPI_SCODE( 0, FACILITY_ITF, warn ))

FUNCTION MAKE_MAPI_S (BYVAL warn AS DWORD) AS DWORD
   FUNCTION = MAKE_MAPI_SCODE(0, %FACILITY_ITF, warn)
END FUNCTION

#IF NOT %DEF(%SUCCESS_SUCCESS)
%SUCCESS_SUCCESS     = 0&
#ENDIF

'/* General errors (used by more than one MAPI object) */

%MAPI_E_CALL_FAILED                      = %E_FAIL
%MAPI_E_NOT_ENOUGH_MEMORY                = %E_OUTOFMEMORY
%MAPI_E_INVALID_PARAMETER                = %E_INVALIDARG
%MAPI_E_INTERFACE_NOT_SUPPORTED          = %E_NOINTERFACE
%MAPI_E_NO_ACCESS                        = %E_ACCESSDENIED

%MAPI_E_NO_SUPPORT           = &H80040102&   ' (-2147221246)   // MAKE_MAPI_E(0x102)
%MAPI_E_BAD_CHARWIDTH        = &H80040103&   ' (-2147221245)   // MAKE_MAPI_E(0x103)
%MAPI_E_STRING_TOO_LONG      = &H80040105&   ' (-2147221243)   // MAKE_MAPI_E(0x105)
%MAPI_E_UNKNOWN_FLAGS        = &H80040106&   ' (-2147221242)   // MAKE_MAPI_E(0x106)
%MAPI_E_INVALID_ENTRYID      = &H80040107&   ' (-2147221241)   // MAKE_MAPI_E(0x107)
%MAPI_E_INVALID_OBJECT       = &H80040108&   ' (-2147221240)   // MAKE_MAPI_E(0x108)
%MAPI_E_OBJECT_CHANGED       = &H80040109&   ' (-2147221239)   // MAKE_MAPI_E(0x109)
%MAPI_E_OBJECT_DELETED       = &H8004010a&   ' (-2147221238)   // MAKE_MAPI_E(0x10A)
%MAPI_E_BUSY                 = &H8004010b&   ' (-2147221237)   // MAKE_MAPI_E(0x10B)
%MAPI_E_NOT_ENOUGH_DISK      = &H8004010d&   ' (-2147221235)   // MAKE_MAPI_E(0x10D)
%MAPI_E_NOT_ENOUGH_RESOURCES = &H8004010e&   ' (-2147221234)   // MAKE_MAPI_E(0x10E)
%MAPI_E_NOT_FOUND            = &H8004010f&   ' (-2147221233)   // MAKE_MAPI_E(0x10F)
%MAPI_E_VERSION              = &H80040110&   ' (-2147221232)   // MAKE_MAPI_E(0x110)
%MAPI_E_LOGON_FAILED         = &H80040111&   ' (-2147221231)   // MAKE_MAPI_E(0x111)
%MAPI_E_SESSION_LIMIT        = &H80040112&   ' (-2147221230)   // MAKE_MAPI_E(0x112)
%MAPI_E_USER_CANCEL          = &H80040113&   ' (-2147221229)   // MAKE_MAPI_E(0x113)
%MAPI_E_UNABLE_TO_ABORT      = &H80040114&   ' (-2147221228)   // MAKE_MAPI_E(0x114)
%MAPI_E_NETWORK_ERROR        = &H80040115&   ' (-2147221227)   // MAKE_MAPI_E(0x115)
%MAPI_E_DISK_ERROR           = &H80040116&   ' (-2147221226)   // MAKE_MAPI_E(0x116)
%MAPI_E_TOO_COMPLEX          = &H80040117&   ' (-2147221225)   // MAKE_MAPI_E(0x117)
%MAPI_E_BAD_COLUMN           = &H80040118&   ' (-2147221224)   // MAKE_MAPI_E(0x118)
%MAPI_E_EXTENDED_ERROR       = &H80040119&   ' (-2147221223)   // MAKE_MAPI_E(0x119)
%MAPI_E_COMPUTED             = &H8004011a&   ' (-2147221222)   // MAKE_MAPI_E(0x11A)
%MAPI_E_CORRUPT_DATA         = &H8004011b&   ' (-2147221221)   // MAKE_MAPI_E(0x11B)
%MAPI_E_UNCONFIGURED         = &H8004011c&   ' (-2147221220)   // MAKE_MAPI_E(0x11C)
%MAPI_E_FAILONEPROVIDER      = &H8004011d&   ' (-2147221219)   // MAKE_MAPI_E(0x11D)
%MAPI_E_UNKNOWN_CPID         = &H8004011e&   ' (-2147221218)   // MAKE_MAPI_E(0x11E)
%MAPI_E_UNKNOWN_LCID         = &H8004011f&   ' (-2147221217)   // MAKE_MAPI_E(0x11F)

'/* Flavors of E_ACCESSDENIED, used at logon */

%MAPI_E_PASSWORD_CHANGE_REQUIRED    = &H80040120&   ' (-2147221216)   // MAKE_MAPI_E(0x120)
%MAPI_E_PASSWORD_EXPIRED            = &H80040121&   ' (-2147221215)   // MAKE_MAPI_E(0x121)
%MAPI_E_INVALID_WORKSTATION_ACCOUNT = &H80040122&   ' (-2147221214)   // MAKE_MAPI_E(0x122)
%MAPI_E_INVALID_ACCESS_TIME         = &H80040123&   ' (-2147221213)   // MAKE_MAPI_E(0x123)
%MAPI_E_ACCOUNT_DISABLED            = &H80040124&   ' (-2147221212)   // MAKE_MAPI_E(0x124)

'/* MAPI base function and status object specific errors and warnings */

%MAPI_E_END_OF_SESSION          = &H80040200&  ' (-2147220992)   // MAKE_MAPI_E(0x200)
%MAPI_E_UNKNOWN_ENTRYID         = &H80040201&  ' (-2147220991)   // MAKE_MAPI_E(0x201)
%MAPI_E_MISSING_REQUIRED_COLUMN = &H80040202&  ' (-2147220990)   // MAKE_MAPI_E(0x202)
%MAPI_W_NO_SERVICE              = &H40302&     ' (262659)        // MAKE_MAPI_S(0x203)

'/* Property specific errors and warnings */

%MAPI_E_BAD_VALUE       = &H80040301&   ' (-2147220735)   // MAKE_MAPI_E(0x301)
%MAPI_E_INVALID_TYPE    = &H80040302&   ' (-2147220734)   // MAKE_MAPI_E(0x302)
%MAPI_E_TYPE_NO_SUPPORT = &H80040303&   ' (-2147220733)   // MAKE_MAPI_E(0x303)
%MAPI_E_UNEXPECTED_TYPE = &H80040304&   ' (-2147220732)   // MAKE_MAPI_E(0x304)
%MAPI_E_TOO_BIG         = &H80040305&   ' (-2147220731)   // MAKE_MAPI_E(0x305)
%MAPI_E_DECLINE_COPY    = &H80040306&   ' (-2147220730)   // MAKE_MAPI_E(0x306)
%MAPI_E_UNEXPECTED_ID   = &H80040307&   ' (-2147220729)   // MAKE_MAPI_E(0x307)

%MAPI_W_ERRORS_RETURNED = &H40380      ' (263040)   // MAKE_MAPI_S(0x380)

'/* Table specific errors and warnings */

%MAPI_E_UNABLE_TO_COMPLETE = &H80040400&   ' (-2147220480)   // MAKE_MAPI_E(0x400)
%MAPI_E_TIMEOUT            = &H80040401&   ' (-2147220479)   // MAKE_MAPI_E(0x401)
%MAPI_E_TABLE_EMPTY        = &H80040402&   ' (-2147220478)   // MAKE_MAPI_E(0x402)
%MAPI_E_TABLE_TOO_BIG      = &H80040403&   ' (-2147220477)   // MAKE_MAPI_E(0x403)

%MAPI_E_INVALID_BOOKMARK   = &H80040405&   ' (-2147220475)   // MAKE_MAPI_E(0x405)

%MAPI_W_POSITION_CHANGED = &H40481&   ' (263297)   // MAKE_MAPI_S(0x481)
%MAPI_W_APPROX_COUNT     = &H40482&   ' (263298)   // MAKE_MAPI_S(0x482)

'/* Transport specific errors and warnings */

%MAPI_E_WAIT   = &H80040500&   ' (-2147220224)   // MAKE_MAPI_E(0x500)
%MAPI_E_CANCEL = &H80040501&   ' (-2147220223)   // MAKE_MAPI_E(0x501)
%MAPI_E_NOT_ME = &H80040502&   ' (-2147220222)   // MAKE_MAPI_E(0x502)

%MAPI_W_CANCEL_MESSAGE = &H40580&   ' (263552)   // MAKE_MAPI_S(0x580)

'/* Message Store, Folder, and Message specific errors and warnings */

%MAPI_E_CORRUPT_STORE   = &H80040600&   ' (-2147219968)   // MAKE_MAPI_E(0x600)
%MAPI_E_NOT_IN_QUEUE    = &H80040601&   ' (-2147219967)   // MAKE_MAPI_E(0x601)
%MAPI_E_NO_SUPPRESS     = &H80040602&   ' (-2147219966)   // MAKE_MAPI_E(0x602)
%MAPI_E_COLLISION       = &H80040604&   ' (-2147219964)   // MAKE_MAPI_E(0x604)
%MAPI_E_NOT_INITIALIZED = &H80040605&   ' (-2147219963)   // MAKE_MAPI_E(0x605)
%MAPI_E_NON_STANDARD    = &H80040606&   ' (-2147219962)   // MAKE_MAPI_E(0x606)
%MAPI_E_NO_RECIPIENTS   = &H80040607&   ' (-2147219961)   // MAKE_MAPI_E(0x607)
%MAPI_E_SUBMITTED       = &H80040608&   ' (-2147219960)   // MAKE_MAPI_E(0x608)
%MAPI_E_HAS_FOLDERS     = &H80040609&   ' (-2147219959)   // MAKE_MAPI_E(0x609)
%MAPI_E_HAS_MESSAGES    = &H8004060a&   ' (-2147219958)   // MAKE_MAPI_E(0x60A)
%MAPI_E_FOLDER_CYCLE    = &H8004060b&   ' (-2147219957)   // MAKE_MAPI_E(0x60B)

%MAPI_W_PARTIAL_COMPLETION = &H40680&   ' (263808)   // MAKE_MAPI_S(0x680)

'/* Address Book specific errors and warnings */

%MAPI_E_AMBIGUOUS_RECIP = &H80040700&   ' (-2147219712)   // MAKE_MAPI_E(0x700)

'/* The range 0x0800 to 0x08FF is reserved */

'/* Obsolete typing shortcut that will go away eventually. */
'#ifndef MakeResult
'#define MakeResult(_s)   ResultFromScode(_s)
'#endif

'/* We expect these to eventually be defined by OLE, but for now,
' * here they are.  When OLE defines them they can be much more
' * efficient than these, but these are "proper" and don't make
' * use of any hidden tricks.
' */
'#ifndef   HR_SUCCEEDED
'#define   HR_SUCCEEDED(_hr) SUCCEEDED((SCODE)(_hr))
'#define   HR_FAILED(_hr) FAILED((SCODE)(_hr))
'#endif

FUNCTION HR_SUCCEEDED (BYVAL hr AS LONG) AS LONG
   FUNCTION = -(hr >= 0)
END FUNCTION

FUNCTION HR_FAILED (BYVAL hr AS LONG) AS LONG
   FUNCTION = -(hr < 0)
END FUNCTION

' ========================================================================================
' Returns the name of the MAPI error code
' ========================================================================================
FUNCTION MapiErrorStr (BYVAL lError AS LONG) AS STRING

   LOCAL s AS STRING

   SELECT CASE AS LONG lError
      CASE %MAPI_E_INTERFACE_NOT_SUPPORTED : s = "MAPI_E_INTERFACE_NOT_SUPPORTED"
      CASE %MAPI_E_CALL_FAILED : s = "MAPI_E_CALL_FAILED"
      CASE %MAPI_E_NO_SUPPORT : s = "MAPI_E_NO_SUPPORT"
      CASE %MAPI_E_BAD_CHARWIDTH : s = "MAPI_E_BAD_CHARWIDTH"
      CASE %MAPI_E_STRING_TOO_LONG : s = "MAPI_E_STRING_TOO_LONG"
      CASE %MAPI_E_UNKNOWN_FLAGS : s = "MAPI_E_UNKNOWN_FLAGS"
      CASE %MAPI_E_INVALID_ENTRYID : s = "MAPI_E_INVALID_ENTRYID"
      CASE %MAPI_E_INVALID_OBJECT : s = "MAPI_E_INVALID_OBJECT"
      CASE %MAPI_E_OBJECT_CHANGED : s = "MAPI_E_OBJECT_CHANGED"
      CASE %MAPI_E_OBJECT_DELETED : s = "MAPI_E_OBJECT_DELETED"
      CASE %MAPI_E_BUSY : s = "MAPI_E_BUSY"
      CASE %MAPI_E_NOT_ENOUGH_DISK : s = "MAPI_E_NOT_ENOUGH_DISK"
      CASE %MAPI_E_NOT_ENOUGH_RESOURCES : s = "MAPI_E_NOT_ENOUGH_RESOURCES"
      CASE %MAPI_E_NOT_FOUND : s = "MAPI_E_NOT_FOUND"
      CASE %MAPI_E_VERSION : s = "MAPI_E_VERSION"
      CASE %MAPI_E_LOGON_FAILED : s = "MAPI_E_LOGON_FAILED"
      CASE %MAPI_E_SESSION_LIMIT : s = "MAPI_E_SESSION_LIMIT"
      CASE %MAPI_E_USER_CANCEL : s = "MAPI_E_USER_CANCEL"
      CASE %MAPI_E_UNABLE_TO_ABORT : s = "MAPI_E_UNABLE_TO_ABORT"
      CASE %MAPI_E_NETWORK_ERROR : s = "MAPI_E_NETWORK_ERROR"
      CASE %MAPI_E_DISK_ERROR : s = "MAPI_E_DISK_ERROR"
      CASE %MAPI_E_TOO_COMPLEX : s = "MAPI_E_TOO_COMPLEX"
      CASE %MAPI_E_BAD_COLUMN : s = "MAPI_E_BAD_COLUMN"
      CASE %MAPI_E_EXTENDED_ERROR : s = "MAPI_E_EXTENDED_ERROR"
      CASE %MAPI_E_COMPUTED : s = "MAPI_E_COMPUTED"
      CASE %MAPI_E_CORRUPT_DATA : s = "MAPI_E_CORRUPT_DATA"
      CASE %MAPI_E_UNCONFIGURED : s = "MAPI_E_UNCONFIGURED"
      CASE %MAPI_E_FAILONEPROVIDER : s = "MAPI_E_FAILONEPROVIDER"
      CASE %MAPI_E_UNKNOWN_CPID : s = "MAPI_E_UNKNOWN_CPID"
      CASE %MAPI_E_UNKNOWN_LCID : s = "MAPI_E_UNKNOWN_LCID"
      CASE %MAPI_E_PASSWORD_CHANGE_REQUIRED : s = "MAPI_E_PASSWORD_CHANGE_REQUIRED"
      CASE %MAPI_E_PASSWORD_EXPIRED : s = "MAPI_E_PASSWORD_EXPIRED"
      CASE %MAPI_E_INVALID_WORKSTATION_ACCOUNT : s = "MAPI_E_INVALID_WORKSTATION_ACCOUNT"
      CASE %MAPI_E_INVALID_ACCESS_TIME : s = "MAPI_E_INVALID_ACCESS_TIME"
      CASE %MAPI_E_ACCOUNT_DISABLED : s = "MAPI_E_ACCOUNT_DISABLED"
      CASE %MAPI_E_END_OF_SESSION : s = "MAPI_E_END_OF_SESSION"
      CASE %MAPI_E_UNKNOWN_ENTRYID : s = "MAPI_E_UNKNOWN_ENTRYID"
      CASE %MAPI_E_MISSING_REQUIRED_COLUMN : s = "MAPI_E_MISSING_REQUIRED_COLUMN"
      CASE %MAPI_E_BAD_VALUE : s = "MAPI_E_BAD_VALUE"
      CASE %MAPI_E_INVALID_TYPE : s = "MAPI_E_INVALID_TYPE"
      CASE %MAPI_E_TYPE_NO_SUPPORT : s = "MAPI_E_TYPE_NO_SUPPORT"
      CASE %MAPI_E_UNEXPECTED_TYPE : s = "MAPI_E_UNEXPECTED_TYPE"
      CASE %MAPI_E_TOO_BIG : s = "MAPI_E_TOO_BIG"
      CASE %MAPI_E_DECLINE_COPY : s = "MAPI_E_DECLINE_COPY"
      CASE %MAPI_E_UNEXPECTED_ID : s = "MAPI_E_UNEXPECTED_ID"
      CASE %MAPI_E_UNABLE_TO_COMPLETE : s = "MAPI_E_UNABLE_TO_COMPLETE"
      CASE %MAPI_E_TIMEOUT : s = "MAPI_E_TIMEOUT"
      CASE %MAPI_E_TABLE_EMPTY : s = "MAPI_E_TABLE_EMPTY"
      CASE %MAPI_E_TABLE_TOO_BIG : s = "MAPI_E_TABLE_TOO_BIG"
      CASE %MAPI_E_INVALID_BOOKMARK : s = "MAPI_E_INVALID_BOOKMARK"
      CASE %MAPI_E_WAIT : s = "MAPI_E_WAIT"
      CASE %MAPI_E_CANCEL : s = "MAPI_E_CANCEL"
      CASE %MAPI_E_NOT_ME : s = "MAPI_E_NOT_ME"
      CASE %MAPI_E_CORRUPT_STORE : s = "MAPI_E_CORRUPT_STORE"
      CASE %MAPI_E_NOT_IN_QUEUE : s = "MAPI_E_NOT_IN_QUEUE"
      CASE %MAPI_E_NO_SUPPRESS : s = "MAPI_E_NO_SUPPRESS"
      CASE %MAPI_E_COLLISION : s = "MAPI_E_COLLISION"
      CASE %MAPI_E_NOT_INITIALIZED : s = "MAPI_E_NOT_INITIALIZED"
      CASE %MAPI_E_NON_STANDARD : s = "MAPI_E_NON_STANDARD"
      CASE %MAPI_E_NO_RECIPIENTS : s = "MAPI_E_NO_RECIPIENTS"
      CASE %MAPI_E_SUBMITTED : s = "MAPI_E_SUBMITTED"
      CASE %MAPI_E_HAS_FOLDERS : s = "MAPI_E_HAS_FOLDERS"
      CASE %MAPI_E_HAS_MESSAGES : s = "MAPI_E_HAS_MESSAGES"
      CASE %MAPI_E_FOLDER_CYCLE : s = "MAPI_E_FOLDER_CYCLE"
      CASE %MAPI_E_AMBIGUOUS_RECIP : s = "MAPI_E_AMBIGUOUS_RECIP"
      CASE %MAPI_E_INVALID_PARAMETER : s = "MAPI_E_INVALID_PARAMETER"
      CASE %MAPI_E_NOT_ENOUGH_MEMORY : s = "MAPI_E_NOT_ENOUGH_MEMORY"
      CASE %MAPI_E_NO_ACCESS : s = "MAPI_E_NO_ACCESS"
      CASE ELSE
         s = "ERROR " & HEX$(lError) & " (" & LTRIM$(STR$(lError)) & ")"
   END SELECT

   FUNCTION = s

END FUNCTION
' ========================================================================================
