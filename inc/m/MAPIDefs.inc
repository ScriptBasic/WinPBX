' ########################################################################################
' Microsoft Windows
' File: MAPIDEfs.inc
' Contents: Definitions used by MAPI clients and service providers
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIDEFS_INC = 1

#INCLUDE ONCE "ole2.inc"
#INCLUDE ONCE "mapiguid.inc"

'/* Array dimension for structures with variable-sized arrays at the end. */

#IF NOT %DEF(%MAPI_DIM)
%MAPI_DIM  = 1
#ENDIF

%MAPI_NT_SERVICE = &H00010000???  '  /* Provider is being loaded in an NT service */


'/* Simple data types */

'#if !defined (MIDL_PASS) /* MIDL doesn't want to see these */

'#if !defined(_NATIVE_WCHAR_T_DEFINED)
'typedef unsigned short      WCHAR;
'#endif

'typedef __nullterminated char FAR *      LPSTR;
'typedef __nullterminated const char FAR *   LPCSTR;

'typedef __nullterminated WCHAR FAR *      LPWSTR;
'typedef __nullterminated const WCHAR FAR *   LPCWSTR;

'#ifdef UNICODE
'typedef WCHAR              TCHAR;
'typedef LPWSTR             LPTSTR;
'typedef LPCWSTR            LPCTSTR;
'#else
'typedef char               TCHAR;
'typedef LPSTR              LPTSTR;
'typedef LPCSTR             LPCTSTR;
'#endif

'typedef BYTE FAR *         LPBYTE;
'#endif /* defined MIDL_PASS */

'typedef ULONG FAR *        LPULONG;

'#ifndef __LHANDLE
'#define __LHANDLE
'typedef ULONG_PTR   LHANDLE, FAR * LPLHANDLE;
'#endif

#IF NOT %DEF(%FILETIME_DEFINED)
%FILETIME_DEFINED = 1
' // Size = 8 bytes
TYPE FILETIME_STRUCT DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

' // To allow to use both DWORD's and a QUAD
' // Size = 8 bytes
UNION FILETIME DWORD
   FILETIME_STRUCT
   qDateTime AS QUAD
END UNION
#ENDIF

'/*
' *  This flag is used in many different MAPI calls to signify that
' *  the object opened by the call should be modifiable (MAPI_MODIFY).
' *  If the flag MAPI_MAX_ACCESS is set, the object returned should be
' *  returned at the maximum access level allowed.  An additional
' *  property available on the object (PR_ACCESS_LEVEL) uses the same
' *  MAPI_MODIFY flag to say just what this new access level is.
' */

%MAPI_MODIFY = &H00000001???

'/*
' *   The following flags are used to indicate to the client what access
' *   level is permissible in the object. They appear in PR_ACCESS in
' *   message and folder objects as well as in contents and associated
' *   contents tables
' */

%MAPI_ACCESS_MODIFY            = &H00000001???
%MAPI_ACCESS_READ              = &H00000002???
%MAPI_ACCESS_DELETE            = &H00000004???
%MAPI_ACCESS_CREATE_HIERARCHY  = &H00000008???
%MAPI_ACCESS_CREATE_CONTENTS   = &H00000010???
%MAPI_ACCESS_CREATE_ASSOCIATED = &H00000020???

'/*
' *   The MAPI_UNICODE flag is used in many different MAPI calls to signify
' *   that strings passed through the interface are in Unicode (a 16-bit
' *   character set). The default is an 8-bit character set.
' *
' *   The value fMapiUnicode can be used as the 'normal' value for
' *   that bit, given the application's default character set.
' */

%MAPI_UNICODE = &H80000000???

'#ifdef UNICODE
'#define fMapiUnicode         MAPI_UNICODE
'#else
'#define fMapiUnicode         0
'#endif

' Change to fMapiUnicode = %MAPI_UNICODE for Unicode version
'%fMapiUnicode = 0    ' // Unicode flag
'#IF %fMapiUnicode
'   MACRO LPTSTR = DWORD
'#ELSE
'   MACRO LPTSTR = ASCIIZ PTR
'#ENDIF

'/* successful HRESULT */
%hrSuccess = 0

'/* Recipient types */
#IF NOT %DEF(%MAPI_ORIG)             ' /* also defined in mapi.h */
%MAPI_ORIG      = 0                  '  /* Recipient is message originator          */
%MAPI_TO        = 1                  '  /* Recipient is a primary recipient         */
%MAPI_CC        = 2                  '  /* Recipient is a copy recipient            */
%MAPI_BCC       = 3                  '  /* Recipient is blind copy recipient        */
%MAPI_P1        = &H10000000???      ' /* Recipient is a P1 resend recipient        */
%MAPI_SUBMITTED = &H80000000???      ' /* Recipient is already processed            */
'/* #define MAPI_AUTHORIZE 4         recipient is a CMC authorizing user      */
'/*#define MAPI_DISCRETE 0x10000000 Recipient is a P1 resend recipient       */
#ENDIF

'/* Bit definitions for abFlags[0] of ENTRYID */
%MAPI_SHORTTERM       = &H80
%MAPI_NOTRECIP        = &H40
%MAPI_THISSESSION     = &H20
%MAPI_NOW             = &H10
%MAPI_NOTRESERVED     = &H08

'/* Bit definitions for abFlags[1] of ENTRYID */
%MAPI_COMPOUND        = &H80

'/* ENTRYID */
' // Size = 5 bytes
TYPE ENTRYID BYTE
   abFlags(3)        AS BYTE   ' BYTE abFlags[4]
   ab(%MAPI_DIM - 1) AS BYTE   ' BYTE ab[MAPI_DIM] [variable-length array]
END TYPE

'/* Byte-order-independent version of GUID (world-unique identifier) */
'typedef struct _MAPIUID
'{
'   BYTE ab[16];
'} MAPIUID, * LPMAPIUID;

' // Size = 16 bytes
TYPE MAPIUID BYTE
   ab AS STRING * 16                             ' BYTE [array]
END TYPE

'/* Note:  need to include C run-times (memory.h) to use this macro */

'#define IsEqualMAPIUID(lpuid1, lpuid2)   (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))

'/*
' * Constants for one-off entry ID:
' * The MAPIUID that identifies the one-off provider;
' * the flag that defines whether the embedded strings are Unicode;
' * the flag that specifies whether the recipient gets TNEF or not.
' */

$MAPI_ONE_OFF_UID = GUID$("{812B1FA4-BEA3-1019-9D6E-00DD010F5402}")
%MAPI_ONE_OFF_UNICODE      = &H8000??
%MAPI_ONE_OFF_NO_RICH_INFO = &H0001??

'/* Object type */

%MAPI_STORE     = &H00000001???   '/* Message Store */
%MAPI_ADDRBOOK  = &H00000002???   '/* Address Book */
%MAPI_FOLDER    = &H00000003???   '/* Folder */
%MAPI_ABCONT    = &H00000004???   '/* Address Book Container */
%MAPI_MESSAGE   = &H00000005???   '/* Message */
%MAPI_MAILUSER  = &H00000006???   '/* Individual Recipient */
%MAPI_ATTACH    = &H00000007???   '/* Attachment */
%MAPI_DISTLIST  = &H00000008???   '/* Distribution List Recipient */
%MAPI_PROFSECT  = &H00000009???   '/* Profile Section */
%MAPI_STATUS    = &H0000000A???   '/* Status Object */
%MAPI_SESSION   = &H0000000B???   '/* Session */
%MAPI_FORMINFO  = &H0000000C???   '/* Form Information */


'/*
' *   Maximum length of profile names and passwords, not including
' *   the null termination character.
' */
#IF NOT %DEF(%cchProfileNameMax)
%cchProfileNameMax = 64
%cchProfilePassMax = 64
#ENDIF


'/* Property Types */

%MV_FLAG         = &H1000???  '  /* Multi-value flag */

%PT_UNSPECIFIED  =  0???   '/* (Reserved for interface use) type doesn't matter to caller */
%PT_NULL         =  1???   '/* NULL property value */
%PT_I2           =  2???   '/* Signed 16-bit value */
%PT_LONG         =  3???   '/* Signed 32-bit value */
%PT_R4           =  4???   '/* 4-byte floating point */
%PT_DOUBLE       =  5???   '/* Floating point double */
%PT_CURRENCY     =  6???   '/* Signed 64-bit int (decimal w/   4 digits right of decimal pt) */
%PT_APPTIME      =  7???   '/* Application time */
%PT_ERROR        = 10???   '/* 32-bit error value */
%PT_BOOLEAN      = 11???   '/* 16-bit boolean (non-zero true) */
%PT_OBJECT       = 13???   '/* Embedded object in a property */
%PT_I8           = 20???   '/* 8-byte signed integer */
%PT_STRING8      = 30???   '/* Null terminated 8-bit character string */
%PT_UNICODE      = 31???   '/* Null terminated Unicode string */
%PT_SYSTIME      = 64???   '/* FILETIME 64-bit int w/ number of 100ns periods since Jan 1,1601 */
%PT_CLSID        = 72???   '/* OLE GUID */
%PT_BINARY       = 258???  '/* Uninterpreted (counted byte array) */
'/* Changes are likely to these numbers, and to their structures. */

'/* Alternate property type names for ease of use */
%PT_SHORT    = %PT_I2
%PT_I4       = %PT_LONG
%PT_FLOAT    = %PT_R4
%PT_R8       = %PT_DOUBLE
%PT_LONGLONG = %PT_I8

'/*
' *   The type of a MAPI-defined string property is indirected, so
' *   that it defaults to Unicode string on a Unicode platform and to
' *   String8 on an ANSI or DBCS platform.
' *
' *   Macros are defined here both for the property type, and for the
' *   field of the property value structure which should be
' *   dereferenced to obtain the string pointer.
' */

'#ifdef   UNICODE
'#define PT_TSTRING         PT_UNICODE
'#define PT_MV_TSTRING      (MV_FLAG|PT_UNICODE)
'#define LPSZ               lpszW
'#define LPPSZ              lppszW
'#define MVSZ               MVszW
'#else
'#define PT_TSTRING         PT_STRING8
'#define PT_MV_TSTRING      (MV_FLAG|PT_STRING8)
'#define LPSZ               lpszA
'#define LPPSZ              lppszA
'#define MVSZ               MVszA
'#endif

'#IF %fMapiUnicode
'   %PT_TSTRING = %PT_UNICODE
'   %PT_MV_TSTRING  = %MV_FLAG OR %PT_UNICODE
'#ELSE
'   %PT_TSTRING = %PT_STRING8
'   %PT_MV_TSTRING  = %MV_FLAG OR %PT_STRING8
'#ENDIF


'/* Property Tags
' *
' * By convention, MAPI never uses 0 or FFFF as a property ID.
' * Use as null values, initializers, sentinels, or what have you.
' */

%PROP_TYPE_MASK = &H0000FFFF???  ' /* Mask for Property type */

'#define PROP_TYPE(ulPropTag)   (((ULONG)(ulPropTag))&PROP_TYPE_MASK)

FUNCTION PROP_TYPE (BYVAL ulPropTag AS DWORD) AS DWORD
   FUNCTION = ulPropTag AND %PROP_TYPE_MASK
END FUNCTION

'#define PROP_ID(ulPropTag)      (((ULONG)(ulPropTag))>>16)

FUNCTION PROP_ID (BYVAL ulPropTag AS DWORD) AS DWORD
   SHIFT RIGHT ulPropTag, 16
   FUNCTION = ulPropTag
END FUNCTION

'#define PROP_TAG(ulPropType,ulPropID)   ((((ULONG)(ulPropID))<<16)|((ULONG)(ulPropType)))

FUNCTION PROP_TAG (BYVAL ulPropType AS DWORD, BYVAL ulPropID AS DWORD) AS DWORD
   SHIFT LEFT ulPropID, 16
   FUNCTION = ulPropID OR ulPropType
END FUNCTION

%PROP_ID_NULL = 0
%PROP_ID_INVALID = &HFFFF

'#define PR_NULL               PROP_TAG( PT_NULL, PROP_ID_NULL)
'MACRO PR_NULL = PROP_TAG(%PT_NULL, %PROP_ID_NULL)
%PR_NULL = 1

'#define CHANGE_PROP_TYPE(ulPropTag, ulPropType)   \
'                  (((ULONG)0xFFFF0000 & ulPropTag) | ulPropType)

FUNCTION CHANGE_PROP_TYPE (BYVAL ulPropTag AS DWORD, BYVAL ulPropType AS DWORD) AS DWORD
   ulPropTag = &HFFFF0000??? AND ulPropTag
   FUNCTION = ulPropTag OR ulPropType
END FUNCTION

'/* Multi-valued Property Types */

%PT_MV_I2       = %MV_FLAG OR %PT_I2
%PT_MV_LONG     = %MV_FLAG OR %PT_LONG
%PT_MV_R4       = %MV_FLAG OR %PT_R4
%PT_MV_DOUBLE   = %MV_FLAG OR %PT_DOUBLE
%PT_MV_CURRENCY = %MV_FLAG OR %PT_CURRENCY
%PT_MV_APPTIME  = %MV_FLAG OR %PT_APPTIME
%PT_MV_SYSTIME  = %MV_FLAG OR %PT_SYSTIME
%PT_MV_STRING8  = %MV_FLAG OR %PT_STRING8
%PT_MV_BINARY   = %MV_FLAG OR %PT_BINARY
%PT_MV_UNICODE  = %MV_FLAG OR %PT_UNICODE
%PT_MV_CLSID    = %MV_FLAG OR %PT_CLSID
%PT_MV_I8       = %MV_FLAG OR %PT_I8


'/* Alternate property type names for ease of use */
%PT_MV_SHORT    = %PT_MV_I2
%PT_MV_I4       = %PT_MV_LONG
%PT_MV_FLOAT    = %PT_MV_R4
%PT_MV_R8       = %PT_MV_DOUBLE
%PT_MV_LONGLONG = %PT_MV_I8

'/*
' *   Property type reserved bits
' *
' *   MV_INSTANCE is used as a flag in table operations to request
' *   that a multi-valued property be presented as a single-valued
' *   property appearing in multiple rows.
' */

%MV_INSTANCE   = &H2000
%MVI_FLAG      = %MV_FLAG OR %MV_INSTANCE
'#define MVI_PROP(tag)   ((tag) | MVI_FLAG)

FUNCTION MVI_PROP (BYVAL tag AS DWORD) AS DWORD
   FUNCTION = tag OR %MVI_FLAG
END FUNCTION

'/* --------------- */
'/* Data Structures */
'/* --------------- */

'/* Property Tag Array */

' // Size = 8 bytes
TYPE SPropTagArray DWORD
   cValues AS DWORD                     ' ULONG
   aulPropTag(%MAPI_DIM - 1) AS DWORD   ' ULONG [variable-length array]
END TYPE


'/* -------------- */
'/* Property Value */
'/* -------------- */

'typedef struct _SPropValue   SPropValue;


'/* 32-bit CURRENCY definition stolen from oaidl.h */
'/* 16-bit CURRENCY definition stolen from variant.h */

'#ifndef _tagCY_DEFINED
'#define _tagCY_DEFINED
'#define _CY_DEFINED
'#if (defined (WIN16) || defined (DOS)) && !defined (_VARIANT_H_)
'typedef struct FARSTRUCT tagCY {
'#ifdef _MAC
'        long      Hi;
'        long Lo;
'#else
'        unsigned long Lo;
'        long      Hi;
'#endif
'} CY;
'#elif defined (_WIN32)
'/* real definition that makes the C++ compiler happy */
'typedef union tagCY {
'    struct {
'#ifdef _MAC
'        long      Hi;
'        long Lo;
'#else
'        unsigned long Lo;
'        long      Hi;
'#endif
'    };
'    LONGLONG int64;
'} CY;
'#endif /* 16-bit vs 32-bit definition */
'#endif
'         /* size is 8 */
'typedef CY CURRENCY;

#IF NOT %DEF(%CY_DEFINED)
    %CY_DEFINED = 1
TYPE tagCY_STRUCT
   Lo AS DWORD
   Hi AS LONG
END TYPE
UNION tagCY
   tagCY_STRUCT
   int64 AS QUAD
END UNION
MACRO tagCURRENCY_DEFINED = tagCY
#ENDIF

' // Size = 8 bytes
TYPE SBinary DWORD
   cb  AS DWORD                                  ' ULONG
   lpb AS BYTE PTR                               ' LPBYTE
END TYPE

' // Size = 8 bytes
TYPE SShortArray DWORD
   cValues AS DWORD                              ' ULONG
   lpi     AS INTEGER PTR                        ' short int *
END TYPE

' // Size = 8 bytes
TYPE SGuidArray DWORD
   cValues AS DWORD                              ' ULONG
   lpguid  AS GUID PTR                           ' GUID *
END TYPE

' // Size = 8 bytes
TYPE SRealArray DWORD
   cValues AS DWORD                              ' ULONG
   lpflt   AS SINGLE PTR                         ' float *
END TYPE

' // Size = 8 bytes
TYPE SLongArray DWORD
   cValues AS DWORD                              ' ULONG
   lpl     AS LONG PTR                           ' LONG *
END TYPE

' // Size = 8 bytes
TYPE SLargeIntegerArray DWORD
   cValues AS DWORD                              ' ULONG
   lpli    AS QUAD PTR                           ' LARGE_INTEGER *
END TYPE

' // Size = 8 bytes
TYPE SDateTimeArray DWORD
   cValues AS DWORD                              ' ULONG
   lpft    AS FILETIME PTR                       ' FILETIME *
END TYPE

' // Size = 8 bytes
TYPE SAppTimeArray DWORD
   cValues AS DWORD                              ' ULONG
   lpat    AS DOUBLE PTR                         ' double *
END TYPE

' // Size = 8 bytes
TYPE SCurrencyArray DWORD
   cValues AS DWORD                              ' ULONG
   lpcur   AS CUR PTR                            ' CURRENCY *
END TYPE

' // Size = 8 bytes
TYPE SBinaryArray DWORD
   cValues AS DWORD                              ' ULONG
   lpbin   AS SBinary PTR                        ' SBinary *
END TYPE

' // Size = 8 bytes
TYPE SDoubleArray DWORD
   cValues AS DWORD                              ' ULONG
   lpdbl   AS DOUBLE PTR                         ' double *
END TYPE

' // Size = 8 bytes
TYPE SWStringArray DWORD
   cValues AS DWORD                              ' ULONG
   lppszW  AS DWORD                              ' LPWSTR * (unicode)
END TYPE

' // Size = 8 bytes
TYPE SLPSTRArray DWORD
   cValues AS DWORD                              ' ULONG
   lppszA  AS ASCIIZ PTR                         ' LPSTR *
END TYPE

'typedef union _PV
'{
'   short int            i;         /* case PT_I2 */
'   LONG                 l;         /* case PT_LONG */
'   ULONG                ul;        /* alias for PT_LONG */
'   float                flt;       /* case PT_R4 */
'   double               dbl;       /* case PT_DOUBLE */
'   unsigned short int   b;         /* case PT_BOOLEAN */
'   CURRENCY             cur;       /* case PT_CURRENCY */
'   double               at;        /* case PT_APPTIME */
'   FILETIME             ft;        /* case PT_SYSTIME */
'   LPSTR                lpszA;     /* case PT_STRING8 */
'   SBinary              bin;       /* case PT_BINARY */
'   LPWSTR               lpszW;     /* case PT_UNICODE */
'   LPGUID               lpguid;    /* case PT_CLSID */
'   LARGE_INTEGER        li;        /* case PT_I8 */
'   SShortArray          MVi;       /* case PT_MV_I2 */
'   SLongArray           MVl;       /* case PT_MV_LONG */
'   SRealArray           MVflt;     /* case PT_MV_R4 */
'   SDoubleArray         MVdbl;     /* case PT_MV_DOUBLE */
'   SCurrencyArray       MVcur;     /* case PT_MV_CURRENCY */
'   SAppTimeArray        MVat;      /* case PT_MV_APPTIME */
'   SDateTimeArray       MVft;      /* case PT_MV_SYSTIME */
'   SBinaryArray         MVbin;     /* case PT_MV_BINARY */
'   SLPSTRArray          MVszA;     /* case PT_MV_STRING8 */
'   SWStringArray        MVszW;     /* case PT_MV_UNICODE */
'   SGuidArray           MVguid;    /* case PT_MV_CLSID */
'   SLargeIntegerArray   MVli;      /* case PT_MV_I8 */
'   SCODE                err;       /* case PT_ERROR */
'   LONG                 x;         /* case PT_NULL, PT_OBJECT (no usable value) */
'} __UPV;

'typedef struct _SPropValue
'{
'   ULONG      ulPropTag;
'   ULONG      dwAlignPad;
'   union _PV  Value;
'} SPropValue, * LPSPropValue;

' // Size = 8 bytes
UNION SPropValue_UNION
   i      AS INTEGER                  ' short int
   l      AS LONG                     ' LONG
   ul     AS DWORD                    ' ULONG
   flt    AS SINGLE                   ' float
   dbl    AS DOUBLE                   ' double
   b      AS WORD                     ' unsigned short int
   cur    AS CUR                      ' CURRENCY
   at     AS DOUBLE                   ' double
   ft     AS FILETIME                 ' FILETIME
   lpszA  AS ASCIIZ PTR               ' LPSTR
   bin    AS SBinary                  ' byte [array]
   lpszW  AS WSTRINGZ PTR             ' LPWSTR
   lpguid AS GUID PTR                 ' LPGUID
   li     AS QUAD                     ' LARGE_INTEGER
   MVi    AS SShortArray              ' SShortArray
   MVl    AS SLongArray               ' SLongArray
   MVflt  AS SRealArray               ' SRealArray
   MVdbl  AS SDoubleArray             ' SDoubleArray
   MVcur  AS SCurrencyArray           ' SCurrencyArray
   MVat   AS SAppTimeArray            ' SAppTimeArray
   MVft   AS SDateTimeArray           ' SDateTimeArray
   MVbin  AS SBinaryArray             ' SBinaryArray
   MVszA  AS SLPSTRArray              ' SLPSTRArray
   MVszW  AS SWStringArray            ' SWStringArray
   MVguid AS SGuidArray               ' SGuidArray
   MVli   AS SLargeIntegerArray       ' SLargeIntegerArray
   err    AS DWORD                    ' SCODE
   x      AS LONG                     ' LONG
END UNION

' // Size = 16 bytes
TYPE SPropValue DWORD
   ulPropTag  AS DWORD                ' ULONG
   dwAlignPad AS DWORD                ' ULONG
   Value      AS SPropValue_UNION
END TYPE


'/* --------------------------------------------- */
'/* Property Problem and Property Problem Arrays */
'/* --------------------------------------------- */

' // Size = 12 bytes
TYPE SPropProblem DWORD
   ulIndex   AS DWORD                            ' ULONG
   ulPropTag AS DWORD                            ' ULONG
   scode     AS LONG                             ' SCODE
END TYPE

'typedef struct _SPropProblemArray
'{
'   ULONG         cProblem;
'   SPropProblem   aProblem[MAPI_DIM];
'} SPropProblemArray, * LPSPropProblemArray;

' // Size = 16 bytes
TYPE SPropProblemArray DWORD
   cProblem                AS DWORD             ' ULONG
   aProblem(%MAPI_DIM - 1) AS SPropProblem      ' SPropProblem [variable-length array]
END TYPE

'/*
' *   ENTRYLIST
' */

'typedef SBinaryArray ENTRYLIST, *LPENTRYLIST;

' // Size = 8 bytes
TYPE ENTRYLIST DWORD
   cValues AS DWORD                              ' ULONG
   lpbin   AS SBinary PTR                        ' SBinary *
END TYPE


'/*
' *   FLATENTRYLIST
' *   MTSID
' *   FLATMTSIDLIST
' */

' // Size = 8 bytes
TYPE FLATENTRY DWORD
   cb AS DWORD                                   ' ULONG
   abEntry(%MAPI_DIM - 1) AS BYTE                ' BYTE [variable-length array]
END TYPE

' // Size = 12 bytes
TYPE FLATENTRYLIST DWORD
   cEntries  AS DWORD                            ' ULONG
   cbEntries AS DWORD                            ' ULONG
   abEntries(%MAPI_DIM - 1) AS BYTE              ' BYTE [variable-length array]
END TYPE

' // Size = 8 bytes
TYPE MTSID DWORD
   cb AS DWORD                                   ' ULONG
   ab(%MAPI_DIM - 1) AS BYTE                     ' BYTE [variable-length array]
END TYPE

' // Size = 12 bytes
TYPE FLATMTSIDLIST DWORD
   cMTSIDs AS DWORD                              ' ULONG
   cbMTSIDs AS DWORD                             ' ULONG
   abMTSIDs(%MAPI_DIM - 1) AS BYTE               ' BYTE [variable-length array]
END TYPE


'/* ------------------------------ */
'/* ADRENTRY, ADRLIST */

' // Size = 12 bytes
TYPE ADRENTRY DWORD
   ulReserved1 AS DWORD                          ' ULONG
   cValues     AS DWORD                          ' ULONG
   rgPropVals  AS SPropValue PTR                 ' LPSPropValue
END TYPE

' // Size = 16 bytes
TYPE ADRLIST DWORD
   cEntries AS DWORD                             ' ULONG
   aEntries(%MAPI_DIM - 1) AS ADRENTRY           ' ADRENTRY [variable-length array]
END TYPE

'/* ------------------------------ */
'/* SRow, SRowSet */

' // Size = 12 bytes
TYPE SRow DWORD
   ulAdrEntryPad AS DWORD                        ' ULONG          ' /* Pad so SRow's can map to ADRENTRY's */
   cValues       AS DWORD                        ' ULONG          ' /* Count of property values */
   lpProps       AS SPropValue PTR               ' LPSPropValue   ' /* Property value array */
END TYPE

' // Size = 16 bytes
TYPE SRowSet DWORD
   cRows AS DWORD                                ' ULONG
   aRow(%MAPI_DIM - 1) AS SRow                   ' SRow [variable-length array]
END TYPE


'/* MAPI Allocation Routines ------------------------------------------------ */

'typedef SCODE (STDMETHODCALLTYPE ALLOCATEBUFFER)(
'   ULONG         cbSize,
'   LPVOID *   lppBuffer
');

'typedef SCODE (STDMETHODCALLTYPE ALLOCATEMORE)(
'   ULONG         cbSize,
'   LPVOID         lpObject,
'   LPVOID *   lppBuffer
');

'typedef ULONG (STDAPICALLTYPE FREEBUFFER)(
'   LPVOID         lpBuffer
');


'/* Extended MAPI Error Information ----------------------------------------- */

' // Size = 20 bytes
TYPE MAPIERROR DWORD
   ulVersion       AS DWORD        ' ULONG
   lpszError       AS ASCIIZ PTR   ' LPTSTR
   lpszComponent   AS ASCIIZ PTR   ' LPTSTR
   ulLowLevelError AS DWORD        ' ULONG
   ulContext       AS DWORD        ' ULONG
END TYPE


'/* IMAPIAdviseSink Interface ----------------------------------------------- */

'/*
' *   Notification event types. The event types can be combined in a bitmask
' *   for filtering. Each one has a parameter structure associated with it:
' *
' *      fnevCriticalError      ERROR_NOTIFICATION
' *      fnevNewMail            NEWMAIL_NOTIFICATION
' *      fnevObjectCreated      OBJECT_NOTIFICATION
' *      fnevObjectDeleted      OBJECT_NOTIFICATION
' *      fnevObjectModified     OBJECT_NOTIFICATION
' *      fnevObjectCopied       OBJECT_NOTIFICATION
' *      fnevSearchComplete     OBJECT_NOTIFICATION
' *      fnevTableModified      TABLE_NOTIFICATION
' *      fnevStatusObjectModified ?
' *
' *      fnevExtended           EXTENDED_NOTIFICATION
' */

%fnevCriticalError         = &H00000001???
%fnevNewMail               = &H00000002???
%fnevObjectCreated         = &H00000004???
%fnevObjectDeleted         = &H00000008???
%fnevObjectModified        = &H00000010???
%fnevObjectMoved           = &H00000020???
%fnevObjectCopied          = &H00000040???
%fnevSearchComplete        = &H00000080???
%fnevTableModified         = &H00000100???
%fnevStatusObjectModified  = &H00000200???
%fnevReservedForMapi       = &H40000000???
%fnevExtended              = &H80000000???

'/* TABLE_NOTIFICATION event types passed in ulTableEvent */

%TABLE_CHANGED       = 1
%TABLE_ERROR         = 2
%TABLE_ROW_ADDED     = 3
%TABLE_ROW_DELETED   = 4
%TABLE_ROW_MODIFIED  = 5
%TABLE_SORT_DONE     = 6
%TABLE_RESTRICT_DONE = 7
%TABLE_SETCOL_DONE   = 8
%TABLE_RELOAD        = 9

'/* Event Structures */

' // Size = 20 bytes
TYPE ERROR_NOTIFICATION DWORD
   cbEntryID   AS DWORD           ' ULONG
   lpEntryID   AS ENTRYID   PTR   ' LPENTRYID
   scode       AS LONG            ' SCODE
   ulFlags     AS DWORD           ' ULONG
   lpMAPIError AS MAPIERROR PTR   ' LPMAPIERROR
END TYPE

' // Size = 28 bytes
TYPE NEWMAIL_NOTIFICATION DWORD
   cbEntryID        AS DWORD         ' ULONG
   lpEntryID        AS ENTRYID PTR   ' LPENTRYID
   cbParentID       AS DWORD         ' ULONG
   lpParentID       AS ENTRYID PTR   ' LPENTRYID
   ulFlags          AS DWORD         ' ULONG
   lpszMessageClass AS ASCIIZ  PTR   ' LPTSTR
   ulMessageFlags   AS DWORD         ' ULONG
END TYPE

' // Size = 40 bytes
TYPE OBJECT_NOTIFICATION DWORD
   cbEntryID      AS DWORD               ' ULONG
   lpEntryID      AS ENTRYID PTR         ' LPENTRYID
   ulObjType      AS DWORD               ' ULONG
   cbParentID     AS DWORD               ' ULONG
   lpParentID     AS ENTRYID PTR         ' LPENTRYID
   cbOldID        AS DWORD               ' ULONG
   lpOldID        AS ENTRYID PTR         ' LPENTRYID
   cbOldParentID  AS DWORD               ' ULONG
   lpOldParentID  AS ENTRYID PTR         ' LPENTRYID
   lpPropTagArray AS SPropTagArray PTR   ' LPSPropTagArray
END TYPE

' // Size = 56 bytes
TYPE TABLE_NOTIFICATION DWORD
   ulTableEvent AS DWORD        ' ULONG
   hResult      AS LONG         ' HRESULT
   propIndex    AS SPropValue   ' SPropValue
   propPrior    AS SPropValue   ' SPropValue
   row          AS SRow         ' SRow
   ulPad        AS DWORD        ' ULONG /* Force to 8-byte boundary */
END TYPE

' // Size = 12 bytes
TYPE EXTENDED_NOTIFICATION DWORD
   ulEvent           AS DWORD      ' ULONG
   cb                AS DWORD      ' ULONG
   pbEventParameters AS BYTE PTR   ' LPBYTE
END TYPE

' // Size = 16 bytes
TYPE STATUS_OBJECT_NOTIFICATION
   cbEntryID  AS DWORD            ' ULONG
   lpEntryID  AS ENTRYID PTR      ' LPENTRYID
   cValues    AS DWORD            ' ULONG
   lpPropVals AS SPropValue PTR   ' LPSPropValue [array]
END TYPE

'typedef struct _NOTIFICATION
'{
'   ULONG   ulEventType;      /* notification type, i.e. fnevSomething */
'   ULONG   ulAlignPad;         /* Force to 8-byte boundary */
'   union
'   {
'      ERROR_NOTIFICATION         err;
'      NEWMAIL_NOTIFICATION       newmail;
'      OBJECT_NOTIFICATION        obj;
'      TABLE_NOTIFICATION         tab;
'      EXTENDED_NOTIFICATION      ext;
'      STATUS_OBJECT_NOTIFICATION statobj;
'   } info;
'} NOTIFICATION, * LPNOTIFICATION;

' // Size = 56 bytes
UNION NOTIFICATION_UNION
   err     AS ERROR_NOTIFICATION
   newmail AS NEWMAIL_NOTIFICATION
   obj     AS OBJECT_NOTIFICATION
   tab     AS TABLE_NOTIFICATION
   ext     AS EXTENDED_NOTIFICATION
   statobj AS STATUS_OBJECT_NOTIFICATION
END UNION

' // Size = 64 bytes
TYPE NOTIFICATION   ' Must be 8 byte aligned
   ulEventType AS DWORD                ' ULONG
   ulAlignPad  AS DWORD                ' ULONG /* Force to 8-byte boundary *
   info        AS NOTIFICATION_UNION
END TYPE


'/* Interface used for registering and issuing notification callbacks. */

' ########################################################################################
' Interface name = IMAPIAdviseSink
' IID = {00020302-0000-0000-C000-000000000046}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IMAPIAdviseSink $IID_IMAPIAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNotify ( _                                  ' VTable offset = 12
     BYVAL cNotif AS DWORD _                            ' __in ULONG cNotif
   , BYREF lpNotifications AS NOTIFICATION _            ' __in LPNOTIFICATION lpNotifications
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================

END INTERFACE


'/* Callback function type for MAPIAllocAdviseSink */

'typedef long (STDAPICALLTYPE NOTIFCALLBACK) (
'   LPVOID           lpvContext,
'   ULONG            cNotification,
'   LPNOTIFICATION   lpNotifications);
'typedef NOTIFCALLBACK * LPNOTIFCALLBACK;

'FUNCTION NOTIFCALLBACK ( _
'   BYVAL DWORD _                            ' LPVOID         lpvContext
' , BYVAL DWORD _                            ' ULONG          cNotification
' , BYREF NOTIFICATION _                     ' LPNOTIFICATION lpNotifications
'   ) AS LONG                                ' long

'/*
' *   Message name for the 16-bit MAPI notififcation engine.
' *   This can be used in 16-bit applications to force processing
' *   of notification callbacks.
' */

$szMAPINotificationMsg = "MAPI Notify window message"


'/* IMAPIProgress Interface ------------------------------------------------- */

'/* Flag values for the progress indicator */

%MAPI_TOP_LEVEL = &H00000001???

' ########################################################################################
' Interface name = IMAPIProgress
' IID = {0002031F-0000-0000-C000-000000000046}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IMAPIProgress $IID_IMAPIProgress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Progress ( _                                  ' VTable offset = 12
     BYVAL ulValue AS DWORD _                           ' __in ULONG ulValue
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL ulTotal AS DWORD _                           ' __in ULONG ulTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 16
     BYREF lpulFlags AS DWORD _                         ' __out ULONG *lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMax ( _                                    ' VTable offset = 20
     BYREF lpulMax AS DWORD _                           ' __out ULONG *lpulMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMin ( _                                    ' VTable offset = 24
     BYREF lpulMin AS DWORD _                           ' __out ULONG *lpulMin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLimits ( _                                 ' VTable offset = 28
     BYREF lpulMin AS DWORD _                           ' __in LPULONG *lpulMin
   , BYREF lpulMax AS DWORD _                           ' __in LPULONG *lpulMax
   , BYREF lpulFlags AS DWORD _                         ' __in LPULONG *lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'/* IMAPIProp Interface ----------------------------------------------------- */

'/* GetLastError */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/*
' *  Version:
' */
%MAPI_ERROR_VERSION = &H00000000&

'/* GetPropList */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* GetProps */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* SaveChanges */

%KEEP_OPEN_READONLY  = &H00000001???
%KEEP_OPEN_READWRITE = &H00000002???
%FORCE_SAVE          = &H00000004???
'/* define MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */

'/* OpenProperty  - ulFlags */
'/******   MAPI_MODIFY            ((ULONG) 0x00000001) above */
%MAPI_CREATE   = &H00000002???
%STREAM_APPEND = &H00000004???
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */

'/* OpenProperty  - ulInterfaceOptions, IID_IMAPITable */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* CopyTo, CopyProps */

%MAPI_MOVE       = &H00000001???
%MAPI_NOREPLACE  = &H00000002???
%MAPI_DECLINE_OK = &H00000004???

#IF NOT %DEF(%MAPI_DIALOG)            ' /* also defined in mapi.h */
%MAPI_DIALOG     = &H00000008???
#ENDIF

#IF NOT %DEF(%MAPI_USE_DEFAULT)       ' /* also defined in mapi.h */
%MAPI_USE_DEFAULT      = &H00000040   ' /* Use default profile in logon */
#ENDIF

'/* Flags used in GetIDsFromNames  */
'/******   MAPI_CREATE            ((ULONG) 0x00000002) above */

'/* Flags used in GetNamesFromIDs  (bit fields) */
%MAPI_NO_STRINGS = &H00000001???
%MAPI_NO_IDS     = &H00000002???

'/*  Union discriminator  */
%MNID_ID     = 0
%MNID_STRING = 1

'typedef struct _MAPINAMEID
'{
'   LPGUID lpguid;
'   ULONG ulKind;
'   union {
'      LONG lID;
'      LPWSTR lpwstrName;
'   } Kind;

'} MAPINAMEID, * LPMAPINAMEID;

' // Size = 4 bytes
UNION MAPINAMEID_UNION
   lID        AS LONG           ' LONG
   lpwstrName AS WSTRINGZ PTR   ' LPWSTR (unicode)
END UNION

' // Size = 12 bytes
TYPE MAPINAMEID DWORD
   lpguid AS GUID PTR           ' LPGUID
   ulKind AS DWORD              ' ULONG
   Kind   AS MAPINAMEID_UNION
END TYPE

' ========================================================================================
' IMAPIProp interface
' $IID_IMAPIProp = GUID$("{00020303-0000-0000-C000-000000000046}")
' The IMAPIProp interface is implemented by all objects that support properties. It is
' used by clients, service providers, and MAPI to work with properties.
' ========================================================================================
INTERFACE IMAPIProp $IID_IMAPIProp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMAPITable Interface ---------------------------------------------------- */

'/* Table status */

%TBLSTAT_COMPLETE       = 0???
%TBLSTAT_QCHANGED       = 7???
%TBLSTAT_SORTING        = 9???
%TBLSTAT_SORT_ERROR     = 10???
%TBLSTAT_SETTING_COLS   = 11???
%TBLSTAT_SETCOL_ERROR   = 13???
%TBLSTAT_RESTRICTING    = 14???
%TBLSTAT_RESTRICT_ERROR = 15???

'/* Table Type */

%TBLTYPE_SNAPSHOT = 0???
%TBLTYPE_KEYSET   = 1???
%TBLTYPE_DYNAMIC  = 2???

'/* Sort order */

'/* bit 0: set if descending, clear if ascending */

%TABLE_SORT_ASCEND  = &H00000000???
%TABLE_SORT_DESCEND = &H00000001???
%TABLE_SORT_COMBINE = &H00000002???

'/* Data structures */

' // Size = 8 bytes
TYPE SSortOrder DWORD
   ulPropTag AS DWORD   ' ULONG  /* Column to sort on */
   ulOrder   AS DWORD   ' ULONG  /* Ascending, descending, combine to left */
END TYPE

' // Size = 20 bytes
TYPE SSortOrderSet DWORD
   cSorts      AS DWORD                 ' ULONG  /* Number of sort columns in aSort below*/
   cCategories AS DWORD                 ' ULONG  /* 0 for non-categorized, up to cSorts */
   cExpanded   AS DWORD                 ' ULONG  /* 0 if no categories start expanded, up to cExpanded */
   aSort(%MAPI_DIM - 1) AS SSortOrder   ' SSortOrder [variable-length array]  /* The sort orders */
END TYPE

'typedef ULONG       BOOKMARK;

%BOOKMARK_BEGINNING = 0???    '  /* Before first row */
%BOOKMARK_CURRENT   = 1???    '  /* Before current row */
%BOOKMARK_END       = 2???    '  /* After last row */

'/* Fuzzy Level */

%FL_FULLSTRING      = &H00000000???
%FL_SUBSTRING       = &H00000001???
%FL_PREFIX          = &H00000002???

%FL_IGNORECASE      = &H00010000???
%FL_IGNORENONSPACE  = &H00020000???
%FL_LOOSE           = &H00040000???

'/* Restrictions */

'/* Restriction types */

%RES_AND            = &H00000000???
%RES_OR             = &H00000001???
%RES_NOT            = &H00000002???
%RES_CONTENT        = &H00000003???
%RES_PROPERTY       = &H00000004???
%RES_COMPAREPROPS   = &H00000005???
%RES_BITMASK        = &H00000006???
%RES_SIZE           = &H00000007???
%RES_EXIST          = &H00000008???
%RES_SUBRESTRICTION = &H00000009???
%RES_COMMENT        = &H0000000A???

'/* Relational operators. These apply to all property comparison restrictions. */

%RELOP_LT      = 0??? '   /* <  */
%RELOP_LE      = 1??? '   /* <= */
%RELOP_GT      = 2??? '   /* >  */
%RELOP_GE      = 3??? '   /* >= */
%RELOP_EQ      = 4??? '   /* == */
%RELOP_NE      = 5??? '   /* != */
%RELOP_RE      = 6??? '   /* LIKE (Regular expression) */

'/* Bitmask operators, for RES_BITMASK only. */

%BMR_EQZ       = 0??? '   /* ==0 */
%BMR_NEZ       = 1??? '   /* !=0 */

'/* Subobject identifiers for RES_SUBRESTRICTION only. See MAPITAGS.H. */

'/* #define PR_MESSAGE_RECIPIENTS  PROP_TAG(PT_OBJECT,0x0E12) */
'/* #define PR_MESSAGE_ATTACHMENTS PROP_TAG(PT_OBJECT,0x0E13) */

' // Size = 8 bytes
TYPE SAndRestriction DWORD
   cRes  AS DWORD                   ' ULONG
   lpRes AS DWORD                   ' LPSRestriction [array]
END TYPE

' // Size = 8 bytes
TYPE SOrRestriction DWORD
   cRes  AS DWORD                   ' ULONG
   lpRes AS DWORD                   ' LPSRestriction
END TYPE

' // Size = 8 bytes
TYPE SNotRestriction DWORD
   ulReserved AS DWORD              ' ULONG
   lpRes      AS DWORD              ' LPSRestriction
END TYPE

' // Size = 12 bytes
TYPE SContentRestriction DWORD
   ulFuzzyLevel AS DWORD            ' ULONG
   ulPropTag    AS DWORD            ' ULONG
   lpProp       AS SPropValue PTR   ' LPSPropValue
END TYPE

' // Size = 12 bytes
TYPE SBitMaskRestriction DWORD
   relBMR    AS DWORD               ' ULONG
   ulPropTag AS DWORD               ' PT_LONG
   ulMask    AS DWORD               ' ULONG
END TYPE

' // Size = 12 bytes
TYPE SPropertyRestriction DWORD
   relop     AS DWORD               ' ULONG
   ulPropTag AS DWORD               ' ULONG
   lpProp    AS SPropValue PTR      ' LPSPropValue
END TYPE

' // Size = 12 bytes
TYPE SComparePropsRestriction DWORD
   relop      AS DWORD              ' ULONG
   ulPropTag1 AS DWORD              ' ULONG
   ulPropTag2 AS DWORD              ' ULONG
END TYPE

' // Size = 12 bytes
TYPE SSizeRestriction DWORD
   relop     AS DWORD               ' ULONG
   ulPropTag AS DWORD               ' ULONG
   cb        AS DWORD               ' ULONG
END TYPE

' // Size = 12 bytes
TYPE SExistRestriction DWORD
   ulReserved1 AS DWORD             ' ULONG
   ulPropTag   AS DWORD             ' ULONG
   ulReserved2 AS DWORD             ' ULONG
END TYPE

' // Size = 8 bytes
TYPE SSubRestriction DWORD
   ulSubObject AS DWORD             ' ULONG
   lpRes       AS DWORD             ' LPSRestriction
END TYPE

' // Size = 12 bytes
TYPE SCommentRestriction DWORD
   cValues AS DWORD                 ' ULONG
   lpRes   AS DWORD                 ' LPSRestriction
   lpProp  AS DWORD                 ' LPSPropValue [array]
END TYPE

' // Size = 12 bytes
UNION SRestriction_UNION
   resCompareProps AS SComparePropsRestriction
   resAnd          AS SAndRestriction
   resOr           AS SOrRestriction
   resNot          AS SNotRestriction
   resContent      AS SContentRestriction
   resProperty     AS SPropertyRestriction
   resBitMask      AS SBitMaskRestriction
   resSize         AS SSizeRestriction
   resExist        AS SExistRestriction
   resSub          AS SSubRestriction
   resComment      AS SCommentRestriction
END UNION

' // Size = 16 bytes
TYPE SRestriction DWORD
   rt  AS DWORD                ' ULONG  /* Restriction type */
   res AS SRestriction_UNION
END TYPE

'/* SComparePropsRestriction is first in the union so that */
'/* static initializations of 3-value restriction work.    */

'/* Flags of the methods of IMAPITable */

'/* QueryColumn */

%TBL_ALL_COLUMNS      = &H00000001???

'/* QueryRows */
'/* Possible values for PR_ROW_TYPE (for categorization) */

%TBL_LEAF_ROW           = 1???
%TBL_EMPTY_CATEGORY     = 2???
%TBL_EXPANDED_CATEGORY  = 3???
%TBL_COLLAPSED_CATEGORY = 4???

'/* Table wait flag */

%TBL_NOWAIT        = &H00000001???
'/* alternative name for TBL_NOWAIT */
%TBL_ASYNC         = &H00000001???
%TBL_BATCH         = &H00000002???

'/* FindRow */

%DIR_BACKWARD      = &H00000001???

'/* Table cursor states */

%TBL_NOADVANCE     = &H00000001???


' ========================================================================================
' IMAPITable interface
' $IID_IMAPITable = GUID$("{00020301-0000-0000-C000-000000000046}")
' The IMAPITable interface is used to provide a read-only view of a table. IMAPITable is
' used by clients and service providers to manipulate the way a table appears.
' ========================================================================================
INTERFACE IMAPITable $IID_IMAPITable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 16
     BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 20
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF lpulTableStatus AS DWORD _                   ' __out ULONG * lpulTableStatus
   , BYREF lpulTableType AS DWORD _                     ' __out ULONG * lpulTableType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumns ( _                                ' VTable offset = 28
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryColumns ( _                              ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpPropTagArray AS DWORD _                    ' __out LPSPropTagArray * lpPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowCount ( _                               ' VTable offset = 36
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulCount AS DWORD _                         ' __out ULONG * lpulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SeekRow ( _                                   ' VTable offset = 40
     BYVAL bkOrigin AS DWORD _                          ' __in BOOKMARK bkOrigin
   , BYVAL lRowCount AS LONG _                          ' __in LONG lRowCount
   , BYREF lplRowsSought AS LONG _                      ' __inout LONG * lplRowsSought
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SeekRowApprox ( _                             ' VTable offset = 44
     BYVAL ulNumerator AS DWORD _                       ' __in ULONG ulNumerator
   , BYVAL ulDenominator AS DWORD _                     ' __in ULONG ulDenominator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPosition ( _                             ' VTable offset = 48
     BYREF lpulRow AS DWORD _                           ' __out ULONG * lpulRow
   , BYREF lpulNumerator AS DWORD _                     ' __out ULONG * lpulNumerator
   , BYREF lpulDenominator AS DWORD _                   ' __out ULONG * lpulDenominator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindRow ( _                                   ' VTable offset = 52
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL bkOrigin AS DWORD _                          ' __in BOOKMARK bkOrigin
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restrict ( _                                  ' VTable offset = 56
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBookmark ( _                            ' VTable offset = 60
     BYREF lpbkPosition AS DWORD _                      ' __in BOOKMARK * lpbkPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBookmark ( _                              ' VTable offset = 64
     BYVAL bkPosition AS DWORD _                        ' __in BOOKMARK bkPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SortTable ( _                                 ' VTable offset = 68
     BYVAL lpSortCriteria AS SSortOrderSet PTR _        ' __in LPSSortOrderSet lpSortCriteria
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySortOrder ( _                            ' VTable offset = 72
     BYREF lppSortCriteria AS DWORD _                   ' __out LPSSortOrderSet * lppSortCriteria
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryRows ( _                                 ' VTable offset = 76
     BYVAL lRowCount AS LONG _                          ' __in LONG lRowCount
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppRows AS DWORD _                           ' __out LPSRowSet * lppRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExpandRow ( _                                 ' VTable offset = 84
     BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL pbInstanceKey AS BYTE PTR _                  ' __in LPBYTE pbInstanceKey
   , BYVAL ulRowCount AS DWORD _                        ' __in ULONG ulRowCount
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppRows AS DWORD _                           ' __out LPSRowSet * lppRows
   , BYREF lpulMoreRows AS DWORD _                      ' __out ULONG * lpulMoreRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollapseRow ( _                               ' VTable offset = 88
     BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL pbInstanceKey AS BYTE PTR _                  ' __in LPBYTE pbInstanceKey
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulRowCount AS DWORD _                      ' __out ULONG * lpulRowCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForCompletion ( _                         ' VTable offset = 92
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulTimeout AS DWORD _                         ' __in ULONG ulTimeout
   , BYREF lpulTableStatus AS DWORD _                   ' __inout ULONG * lpulTableStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCollapseState ( _                          ' VTable offset = 96
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL lpbInstanceKey AS DWORD _                    ' __in ULONG lpbInstanceKey
   , BYREF lpcbCollapseState AS DWORD _                 ' __out ULONG * lpcbCollapseState
   , BYREF lppbCollapseState AS DWORD _                 ' __out LPBYTE * lppbCollapseState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCollapseState ( _                          ' VTable offset = 100
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbCollapseState AS DWORD _                   ' __in ULONG cbCollapseState
   , BYVAL pbCollapseState AS BYTE PTR _                ' __in LPBYTE pbCollapseState
   , BYREF lpbkLocation AS DWORD _                      ' __out BOOKMARK * lpbkLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ========================================================================================
' IABTable interface
' This interface is used for content tables of Microsoft® Windows® Address Book (WAB)
' containers and distribution lists. It is based in IMAPITable.
' ========================================================================================
INTERFACE IABTable $IID_IMAPITable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 16
     BYVAL ulEventMask AS DWORD _                       ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 20
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF lpulTableStatus AS DWORD _                   ' __out ULONG * lpulTableStatus
   , BYREF lpulTableType AS DWORD _                     ' __out ULONG * lpulTableType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumns ( _                                ' VTable offset = 28
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryColumns ( _                              ' VTable offset = 32
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpPropTagArray AS DWORD _                    ' __out LPSPropTagArray * lpPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowCount ( _                               ' VTable offset = 36
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulCount AS DWORD _                         ' __out ULONG * lpulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SeekRow ( _                                   ' VTable offset = 40
     BYVAL bkOrigin AS DWORD _                          ' __in BOOKMARK bkOrigin
   , BYVAL lRowCount AS LONG _                          ' __in LONG lRowCount
   , BYREF lplRowsSought AS LONG _                      ' __inout LONG * lplRowsSought
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SeekRowApprox ( _                             ' VTable offset = 44
     BYVAL ulNumerator AS DWORD _                       ' __in ULONG ulNumerator
   , BYVAL ulDenominator AS DWORD _                     ' __in ULONG ulDenominator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPosition ( _                             ' VTable offset = 48
     BYREF lpulRow AS DWORD _                           ' __out ULONG * lpulRow
   , BYREF lpulNumerator AS DWORD _                     ' __out ULONG * lpulNumerator
   , BYREF lpulDenominator AS DWORD _                   ' __out ULONG * lpulDenominator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindRow ( _                                   ' VTable offset = 52
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL bkOrigin AS DWORD _                          ' __in BOOKMARK bkOrigin
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restrict ( _                                  ' VTable offset = 56
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBookmark ( _                            ' VTable offset = 60
     BYREF lpbkPosition AS DWORD _                      ' __in BOOKMARK * lpbkPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBookmark ( _                              ' VTable offset = 64
     BYVAL bkPosition AS DWORD _                        ' __in BOOKMARK bkPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SortTable ( _                                 ' VTable offset = 68
     BYVAL lpSortCriteria AS SSortOrderSet PTR _        ' __in LPSSortOrderSet lpSortCriteria
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySortOrder ( _                            ' VTable offset = 72
     BYREF lppSortCriteria AS DWORD _                   ' __out LPSSortOrderSet * lppSortCriteria
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryRows ( _                                 ' VTable offset = 76
     BYVAL lRowCount AS LONG _                          ' __in LONG lRowCount
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppRows AS DWORD _                           ' __out LPSRowSet * lppRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExpandRow ( _                                 ' VTable offset = 84
     BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL pbInstanceKey AS BYTE PTR _                  ' __in LPBYTE pbInstanceKey
   , BYVAL ulRowCount AS DWORD _                        ' __in ULONG ulRowCount
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppRows AS DWORD _                           ' __out LPSRowSet * lppRows
   , BYREF lpulMoreRows AS DWORD _                      ' __out ULONG * lpulMoreRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollapseRow ( _                               ' VTable offset = 88
     BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL pbInstanceKey AS BYTE PTR _                  ' __in LPBYTE pbInstanceKey
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulRowCount AS DWORD _                      ' __out ULONG * lpulRowCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForCompletion ( _                         ' VTable offset = 92
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulTimeout AS DWORD _                         ' __in ULONG ulTimeout
   , BYREF lpulTableStatus AS DWORD _                   ' __inout ULONG * lpulTableStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCollapseState ( _                          ' VTable offset = 96
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbInstanceKey AS DWORD _                     ' __in ULONG cbInstanceKey
   , BYVAL lpbInstanceKey AS DWORD _                    ' __in ULONG lpbInstanceKey
   , BYREF lpcbCollapseState AS DWORD _                 ' __out ULONG * lpcbCollapseState
   , BYREF lppbCollapseState AS DWORD _                 ' __out LPBYTE * lppbCollapseState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCollapseState ( _                          ' VTable offset = 100
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbCollapseState AS DWORD _                   ' __in ULONG cbCollapseState
   , BYVAL pbCollapseState AS BYTE PTR _                ' __in LPBYTE pbCollapseState
   , BYREF lpbkLocation AS DWORD _                      ' __out BOOKMARK * lpbkLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IProfSect Interface ----------------------------------------------------- */

'/* Standard section for public profile properties */

$PS_PROFILE_PROPERTIES_INIT = GUID$("{9815AC08-AAB0-101A-8C93-08002B2A56C2}")

' ========================================================================================
' IProfSect interface (inherits from IMAPIProp)
' $IID_IProfSect = GUID$("{00020304-0000-0000-C000-000000000046}")
' The IProfSect interface is used to work with the properties of profile section objects.
' ========================================================================================
INTERFACE IProfSect $IID_IProfSect

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMAPIStatus Interface --------------------------------------------------- */

'/* Values for PR_RESOURCE_TYPE, _METHODS, _FLAGS */

%MAPI_STORE_PROVIDER        = 33???  ' /* Message Store */
%MAPI_AB                    = 34???  ' /* Address Book */
%MAPI_AB_PROVIDER           = 35???  ' /* Address Book Provider */
%MAPI_TRANSPORT_PROVIDER    = 36???  ' /* Transport Provider */
%MAPI_SPOOLER               = 37???  ' /* Message Spooler */
%MAPI_PROFILE_PROVIDER      = 38???  ' /* Profile Provider */
%MAPI_SUBSYSTEM             = 39???  ' /* Overall Subsystem Status */
%MAPI_HOOK_PROVIDER         = 40???  ' /* Spooler Hook */

%STATUS_VALIDATE_STATE      = &H00000001???
%STATUS_SETTINGS_DIALOG     = &H00000002???
%STATUS_CHANGE_PASSWORD     = &H00000004???
%STATUS_FLUSH_QUEUES        = &H00000008???

%STATUS_DEFAULT_OUTBOUND    = &H00000001???
%STATUS_DEFAULT_STORE       = &H00000002???
%STATUS_PRIMARY_IDENTITY    = &H00000004???
%STATUS_SIMPLE_STORE        = &H00000008???
%STATUS_XP_PREFER_LAST      = &H00000010???
%STATUS_NO_PRIMARY_IDENTITY = &H00000020???
%STATUS_NO_DEFAULT_STORE    = &H00000040???
%STATUS_TEMP_SECTION        = &H00000080???
%STATUS_OWN_STORE           = &H00000100???
'/****** HOOK_INBOUND         ((ULONG) 0x00000200) Defined in MAPIHOOK.H */
'/****** HOOK_OUTBOUND        ((ULONG) 0x00000400) Defined in MAPIHOOK.H */
%STATUS_NEED_IPM_TREE       = &H00000800???
%STATUS_PRIMARY_STORE       = &H00001000???
%STATUS_SECONDARY_STORE     = &H00002000???


'/*
' * PR_STATUS_CODE bit. Low 16 bits for common values; High 16 bits
' * for provider type-specific values. (DCR 304)
' */

%STATUS_AVAILABLE           = &H00000001???
%STATUS_OFFLINE             = &H00000002???
%STATUS_FAILURE             = &H00000004???

'/* Transport values of PR_STATUS_CODE */

%STATUS_INBOUND_ENABLED     = &H00010000???
%STATUS_INBOUND_ACTIVE      = &H00020000???
%STATUS_INBOUND_FLUSH       = &H00040000???
%STATUS_OUTBOUND_ENABLED    = &H00100000???
%STATUS_OUTBOUND_ACTIVE     = &H00200000???
%STATUS_OUTBOUND_FLUSH      = &H00400000???
%STATUS_REMOTE_ACCESS       = &H00800000???

'/* ValidateState flags */

%SUPPRESS_UI                = &H00000001???
%REFRESH_XP_HEADER_CACHE    = &H00010000???
%PROCESS_XP_HEADER_CACHE    = &H00020000???
%FORCE_XP_CONNECT           = &H00040000???
%FORCE_XP_DISCONNECT        = &H00080000???
%CONFIG_CHANGED             = &H00100000???
%ABORT_XP_HEADER_OPERATION  = &H00200000???
%SHOW_XP_SESSION_UI         = &H00400000???

'/* SettingsDialog flags */

%UI_READONLY                = &H00000001???

'/* FlushQueues flags */

%FLUSH_UPLOAD               = &H00000002???
%FLUSH_DOWNLOAD             = &H00000004???
%FLUSH_FORCE                = &H00000008???
%FLUSH_NO_UI                = &H00000010???
%FLUSH_ASYNC_OK             = &H00000020???

' ========================================================================================
' IMAPIStatus interface (inherits from  IMAPIProp)
' $IID_IMAPIStatus = GUID$("{00020305-0000-0000-C000-000000000046}")
' MAPI implements the IMAPIStatus interface to provide status information about the MAPI
' subsystem, the integrated address book and the MAPI spooler. A service provider
' implements IMAPIStatus to supply information about its own status.
' ========================================================================================
INTERFACE IMAPIStatus $IID_IMAPIStatus

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIStatus Methods
   ' =====================================================================================
   METHOD ValidateState ( _                             ' VTable offser = 56
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SettingsDialog ( _                            ' VTable offser = 60
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangePassword ( _                            ' VTable offser = 64
     BYREF lpOldPass AS ASCIIZ _                        ' __in LPTSTR lpOldPass
   , BYREF lpNewPass AS ASCIIZ _                        ' __in LPTSTR lpNewPass
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FlushQueues ( _                               ' VTable offser = 68
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL cbTargetTransport AS DWORD _                 ' __in ULONG cbTargetTransport
   , BYVAL lpTargetTransport AS ENTRYID PTR _           ' __in LPENTRYID lpTargetTransport
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMAPIContainer Interface ------------------------------------------------ */

'/* Flags for OpenEntry() */

'/****** MAPI_MODIFY            ((ULONG) 0x00000001) above */
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
%MAPI_BEST_ACCESS           = &H00000010???

'/* GetContentsTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
'/****** MAPI_ASSOCIATED         ((ULONG) 0x00000040) below */

'/* GetHierarchyTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */
%CONVENIENT_DEPTH           = &H00000001???
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */

'/* GetSearchCriteria */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */
%SEARCH_RUNNING             = &H00000001???
%SEARCH_REBUILD             = &H00000002???
%SEARCH_RECURSIVE           = &H00000004???
%SEARCH_FOREGROUND          = &H00000008???

'/* SetSearchCriteria */
%STOP_SEARCH                = &H00000001???
%RESTART_SEARCH             = &H00000002???
%RECURSIVE_SEARCH           = &H00000004???
%SHALLOW_SEARCH             = &H00000008???
%FOREGROUND_SEARCH          = &H00000010???
%BACKGROUND_SEARCH          = &H00000020???

' ========================================================================================
' IMAPIContainer interface (inherits from IMAPIProp)
' $IID_IMAPIContainer = GUID$("{0002030B-0000-0000-C000-000000000046}")
' The IMAPIContainer interface manages high-level operations on container objects such as
' address books, distribution lists, and folders. The IMAPIFolder, IABContainer, and
' IDistList interfaces are derived from IMAPIContainer.
' ========================================================================================
INTERFACE IMAPIContainer $IID_IMAPIContainer

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIContainer Methods
   ' =====================================================================================
   METHOD GetContentsTable ( _                          ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHierarchyTable ( _                         ' VTable offser = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 64
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSearchCriteria ( _                         ' VTable offser = 68
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL lpContainerList AS ENTRYLIST PTR _           ' __in LPENTRYLIST lpContainerList [array]
   , BYVAL ulSearchFlags AS DWORD _                     ' __in ULONG ulSearchFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchCriteria ( _                         ' VTable offser = 72
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppRestriction AS DWORD _                    ' __out LPSRestriction * lppRestriction
   , BYREF lppContainerList AS DWORD _                  ' __out LPENTRYLIST * lppContainerList
   , BYREF lpulSearchState AS DWORD _                   ' __out LONG * lpulSearchState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IABContainer Interface -------------------------------------------------- */

'/*
' *   IABContainer PR_CONTAINER_FLAGS values
' *   If AB_UNMODIFIABLE and AB_MODIFIABLE are both set, it means the container
' *   doesn't know if it's modifiable or not, and the client should
' *  try to modify the contents but we won't expect it to work.
' *   If the AB_RECIPIENTS flag is set and neither AB_MODIFIABLE or AB_UNMODIFIABLE
' *  bits are set, it is an error.
' */

' // Size = 8 bytes
TYPE FlagList DWORD
   cFlags AS DWORD                          ' ULONG
   ulFlags(%MAPI_DIM - 1) AS DWORD          ' ULONG [variable-length array]
END TYPE

'/*
' *  Container flags
' */
%AB_RECIPIENTS           = &H00000001???
%AB_SUBCONTAINERS        = &H00000002???
%AB_MODIFIABLE           = &H00000004???
%AB_UNMODIFIABLE         = &H00000008???
%AB_FIND_ON_OPEN         = &H00000010???
%AB_NOT_DEFAULT          = &H00000020???

'/* CreateEntry() */

%CREATE_CHECK_DUP_STRICT = &H00000001???
%CREATE_CHECK_DUP_LOOSE  = &H00000002???
%CREATE_REPLACE          = &H00000004???

'/* ResolveNames() - ulFlags */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* ResolveNames() - rgulFlags */
%MAPI_UNRESOLVED = &H00000000???
%MAPI_AMBIGUOUS  = &H00000001???
%MAPI_RESOLVED   = &H00000002???


' ========================================================================================
' IABContainer interface (inherits from IMAPIContainer)
' $IID_IABContainer = GUID$("{0002030D-0000-0000-C000-000000000046}")
' The IABContainer interface provides access to address book containers. MAPI and client
' applications call the methods of IABContainer to perform name resolution and to create,
' copy, and delete recipients.
' ========================================================================================
INTERFACE IABContainer $IID_IABContainer

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIContainer Methods
   ' =====================================================================================
   METHOD GetContentsTable ( _                          ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHierarchyTable ( _                         ' VTable offser = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 64
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSearchCriteria ( _                         ' VTable offser = 68
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL lpContainerList AS ENTRYLIST PTR _           ' __in LPENTRYLIST lpContainerList [array]
   , BYVAL ulSearchFlags AS DWORD _                     ' __in ULONG ulSearchFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchCriteria ( _                         ' VTable offser = 72
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppRestriction AS DWORD _                    ' __out LPSRestriction * lppRestriction
   , BYREF lppContainerList AS DWORD _                  ' __out LPENTRYLIST * lppContainerList
   , BYREF lpulSearchState AS DWORD _                   ' __out LONG * lpulSearchState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IABContainer Methods
   ' =====================================================================================
   METHOD CreateEntry ( _                               ' VTable offser = 76
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulCreateFlags AS DWORD _                     ' __in ULONG ulCreateFlags
   , BYREF lppMAPIPropEntry AS IMAPIProp _              ' __out LPMAPIPROP * lppMAPIPropEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyEntries ( _                               ' VTable offser = 80
     BYVAL lpEntries AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpEntries
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteEntries ( _                             ' VTable offser = 84
     BYVAL lpEntries AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpEntries
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveNames ( _                              ' VTable offser = 88
     BYVAL lpPropTagArray AS SpropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpAdrList AS ADRLIST PTR _                   ' __inout LPADRLIST lpAdrList
   , BYVAL lpFlagList AS DWORD _                        ' __inout LPFlagList lpFlagList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMailUser Interface ----------------------------------------------------- */

'/*  Any call which can create a one-off entryID (i.e. MAPISupport::CreateOneOff
'    or IAdrBook::CreateOneOff) can encode the value for PR_SEND_RICH_INFO by
'   passing in the following flag in the ulFlags parameter.  Setting this flag
'   indicates that PR_SEND_RICH_INFO will be FALSE.
'*/
%MAPI_SEND_NO_RICH_INFO = &H00010000???

'/* Values of PR_NDR_DIAG_CODE */

'#define MAPI_DIAG(_code)   ((LONG) _code)

%MAPI_DIAG_NO_DIAGNOSTIC             = -1&
%MAPI_DIAG_OR_NAME_UNRECOGNIZED      = 0&
%MAPI_DIAG_OR_NAME_AMBIGUOUS         = 1&
%MAPI_DIAG_MTS_CONGESTED             = 2&
%MAPI_DIAG_LOOP_DETECTED             = 3&
%MAPI_DIAG_RECIPIENT_UNAVAILABLE     = 4&
%MAPI_DIAG_MAXIMUM_TIME_EXPIRED      = 5&
%MAPI_DIAG_EITS_UNSUPPORTED          = 6&
%MAPI_DIAG_CONTENT_TOO_LONG          = 7&
%MAPI_DIAG_IMPRACTICAL_TO_CONVERT    = 8&
%MAPI_DIAG_PROHIBITED_TO_CONVERT     = 9&
%MAPI_DIAG_CONVERSION_UNSUBSCRIBED   = 10&
%MAPI_DIAG_PARAMETERS_INVALID        = 11&
%MAPI_DIAG_CONTENT_SYNTAX_IN_ERROR   = 12&
%MAPI_DIAG_LENGTH_CONSTRAINT_VIOLATD = 13&
%MAPI_DIAG_NUMBER_CONSTRAINT_VIOLATD = 14&
%MAPI_DIAG_CONTENT_TYPE_UNSUPPORTED  = 15&
%MAPI_DIAG_TOO_MANY_RECIPIENTS       = 16&
%MAPI_DIAG_NO_BILATERAL_AGREEMENT    = 17&
%MAPI_DIAG_CRITICAL_FUNC_UNSUPPORTED = 18&
%MAPI_DIAG_CONVERSION_LOSS_PROHIB    = 19&
%MAPI_DIAG_LINE_TOO_LONG             = 20&
%MAPI_DIAG_PAGE_TOO_LONG             = 21&
%MAPI_DIAG_PICTORIAL_SYMBOL_LOST     = 22&
%MAPI_DIAG_PUNCTUATION_SYMBOL_LOST   = 23&
%MAPI_DIAG_ALPHABETIC_CHARACTER_LOST = 24&
%MAPI_DIAG_MULTIPLE_INFO_LOSSES      = 25&
%MAPI_DIAG_REASSIGNMENT_PROHIBITED   = 26&
%MAPI_DIAG_REDIRECTION_LOOP_DETECTED = 27&
%MAPI_DIAG_EXPANSION_PROHIBITED      = 28&
%MAPI_DIAG_SUBMISSION_PROHIBITED     = 29&
%MAPI_DIAG_EXPANSION_FAILED          = 30&
%MAPI_DIAG_RENDITION_UNSUPPORTED     = 31&
%MAPI_DIAG_MAIL_ADDRESS_INCORRECT    = 32&
%MAPI_DIAG_MAIL_OFFICE_INCOR_OR_INVD = 33&
%MAPI_DIAG_MAIL_ADDRESS_INCOMPLETE   = 34&
%MAPI_DIAG_MAIL_RECIPIENT_UNKNOWN    = 35&
%MAPI_DIAG_MAIL_RECIPIENT_DECEASED   = 36&
%MAPI_DIAG_MAIL_ORGANIZATION_EXPIRED = 37&
%MAPI_DIAG_MAIL_REFUSED              = 38&
%MAPI_DIAG_MAIL_UNCLAIMED            = 39&
%MAPI_DIAG_MAIL_RECIPIENT_MOVED      = 40&
%MAPI_DIAG_MAIL_RECIPIENT_TRAVELLING = 41&
%MAPI_DIAG_MAIL_RECIPIENT_DEPARTED   = 42&
%MAPI_DIAG_MAIL_NEW_ADDRESS_UNKNOWN  = 43&
%MAPI_DIAG_MAIL_FORWARDING_UNWANTED  = 44&
%MAPI_DIAG_MAIL_FORWARDING_PROHIB    = 45&
%MAPI_DIAG_SECURE_MESSAGING_ERROR    = 46&
%MAPI_DIAG_DOWNGRADING_IMPOSSIBLE    = 47&

'/* Values of PR_DELIVERY_POINT (MH_T_DELIVERY_POINT) */

%MAPI_MH_DP_PUBLIC_UA  = 0???
%MAPI_MH_DP_PRIVATE_UA = 1???
%MAPI_MH_DP_MS         = 2???
%MAPI_MH_DP_ML         = 3???
%MAPI_MH_DP_PDAU       = 4???
%MAPI_MH_DP_PDS_PATRON = 5???
%MAPI_MH_DP_OTHER_AU   = 6???


' ========================================================================================
' IMailUser interface (inherits from IMAPIProp)
' $IID_IMailUser = GUID$("{0002030A-0000-0000-C000-000000000046}")
' The IMailUser interface is implemented by messaging user objects. IMailUser inherits
' from the IMAPIProp interface and has no unique methods of its own. The IMailUser
' interface provides access to the many properties that are associated with messaging users.
' ========================================================================================
INTERFACE IMailUser $IID_IMailUser

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IDistList Interface ----------------------------------------------------- */

' ========================================================================================
' IDistList interface (inherits from IMAPIContainer)
' $IID_IDistList = GUID$("{0002030E-0000-0000-C000-000000000046}")
' The IDistList interface is used to provide access to distribution lists in modifiable
' address book containers. IDistList can create, copy, and delete distribution lists, in
' addition to performing name resolution.
' The IDistList interface inherits from IMAPIContainer and includes the same methods
' as address book containers.
' ========================================================================================
INTERFACE IDistList $IID_IDistList

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIContainer Methods
   ' =====================================================================================
   METHOD GetContentsTable ( _                          ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHierarchyTable ( _                         ' VTable offser = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 64
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSearchCriteria ( _                         ' VTable offser = 68
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL lpContainerList AS ENTRYLIST PTR _           ' __in LPENTRYLIST lpContainerList [array]
   , BYVAL ulSearchFlags AS DWORD _                     ' __in ULONG ulSearchFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchCriteria ( _                         ' VTable offser = 72
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppRestriction AS DWORD _                    ' __out LPSRestriction * lppRestriction
   , BYREF lppContainerList AS DWORD _                  ' __out LPENTRYLIST * lppContainerList
   , BYREF lpulSearchState AS DWORD _                   ' __out LONG * lpulSearchState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDistList Methods
   ' =====================================================================================
   METHOD CreateEntry ( _                               ' VTable offser = 76
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulCreateFlags AS DWORD _                     ' __in ULONG ulCreateFlags
   , BYREF lppMAPIPropEntry AS IMAPIProp _              ' __out LPMAPIPROP * lppMAPIPropEntry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyEntries ( _                               ' VTable offser = 80
     BYVAL lpEntries AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpEntries
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteEntries ( _                             ' VTable offser = 84
     BYVAL lpEntries AS ENTRYLIST PTR _                 ' __in LPENTRYLIST lpEntries
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveNames ( _                              ' VTable offser = 88
     BYVAL lpPropTagArray AS SpropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpAdrList AS ADRLIST PTR _                   ' __inout LPADRLIST lpAdrList
   , BYVAL lpFlagList AS DWORD _                        ' __inout LPFlagList lpFlagList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMAPIFolder Interface --------------------------------------------------- */

'/* IMAPIFolder folder type (enum) */

%FOLDER_ROOT            = &H00000000???
%FOLDER_GENERIC         = &H00000001???
%FOLDER_SEARCH          = &H00000002???

'/* CreateMessage */
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
'/****** MAPI_ASSOCIATED         ((ULONG) 0x00000040) below */

'/* CopyMessages */

%MESSAGE_MOVE           = &H00000001???
%MESSAGE_DIALOG         = &H00000002???
'/****** MAPI_DECLINE_OK         ((ULONG) 0x00000004) above */

'/* CreateFolder */

%OPEN_IF_EXISTS         = &H00000001???
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* DeleteFolder */

%DEL_MESSAGES           = &H00000001???
%FOLDER_DIALOG          = &H00000002???
%DEL_FOLDERS            = &H00000004???

'/* EmptyFolder */
%DEL_ASSOCIATED         = &H00000008???

'/* CopyFolder */

%FOLDER_MOVE            = &H00000001???
'/****** FOLDER_DIALOG         ((ULONG) 0x00000002) above */
'/****** MAPI_DECLINE_OK         ((ULONG) 0x00000004) above */
%COPY_SUBFOLDERS        = &H00000010???
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */


'/* SetReadFlags */

'/****** SUPPRESS_RECEIPT      ((ULONG) 0x00000001) below */
'/****** FOLDER_DIALOG         ((ULONG) 0x00000002) above */
'/****** CLEAR_READ_FLAG         ((ULONG) 0x00000004) below */
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
'/******   GENERATE_RECEIPT_ONLY   ((ULONG) 0x00000010) below */
'/****** CLEAR_RN_PENDING      ((ULONG) 0x00000020) below */
'/****** CLEAR_NRN_PENDING      ((ULONG) 0x00000040) below */


'/* GetMessageStatus */

%MSGSTATUS_HIGHLIGHTED = &H00000001???
%MSGSTATUS_TAGGED      = &H00000002???
%MSGSTATUS_HIDDEN      = &H00000004???
%MSGSTATUS_DELMARKED   = &H00000008???

'/* Bits for remote message status */

%MSGSTATUS_REMOTE_DOWNLOAD = &H00001000???
%MSGSTATUS_REMOTE_DELETE   = &H00002000???

'/* SaveContentsSort */

%RECURSIVE_SORT         = &H00000002???

'/* PR_STATUS property */

%FLDSTATUS_HIGHLIGHTED  = &H00000001???
%FLDSTATUS_TAGGED       = &H00000002???
%FLDSTATUS_HIDDEN       = &H00000004???
%FLDSTATUS_DELMARKED    = &H00000008???

' ========================================================================================
' IMAPIFolder interface (inherits from IMAPIContainer)
' $IID_IMAPIFolder = GUID$("{0002030C-0000-0000-C000-000000000046}")
' The IMAPIFolder interface is used to perform operations on the messages and subfolders
' in a folder.
' ========================================================================================
INTERFACE IMAPIFolder $IID_IMAPIFolder

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIContainer Methods
   ' =====================================================================================
   METHOD GetContentsTable ( _                          ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHierarchyTable ( _                         ' VTable offser = 60
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 64
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSearchCriteria ( _                         ' VTable offser = 68
     BYREF lpRestriction AS SRestriction _              ' __in LPSRestriction lpRestriction
   , BYVAL lpContainerList AS ENTRYLIST PTR _           ' __in LPENTRYLIST lpContainerList [array]
   , BYVAL ulSearchFlags AS DWORD _                     ' __in ULONG ulSearchFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchCriteria ( _                         ' VTable offser = 72
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppRestriction AS DWORD _                    ' __out LPSRestriction * lppRestriction
   , BYREF lppContainerList AS DWORD _                  ' __out LPENTRYLIST * lppContainerList
   , BYREF lpulSearchState AS DWORD _                   ' __out LONG * lpulSearchState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMAPIFolder Methods
   ' =====================================================================================
   METHOD CreateMessage ( _                             ' VTable offser = 76
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMessage AS IMessage _                     ' __out LPMESSAGE * lppMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyMessages ( _                              ' VTable offser = 80
     BYVAL lpMsgList AS DWORD _                         ' __in LPENTRYLIST lpMsgList
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestFolder AS IUnknown _                   ' __in LPVOID lpDestFolder
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMessages ( _                            ' VTable offser = 84
     BYVAL lpMsgList AS DWORD _                         ' __in LPENTRYLIST lpMsgList
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFolder ( _                              ' VTable offser = 88
     BYVAL ulFolderType AS DWORD _                      ' __in ULONG ulFolderType
   , BYREF lpszFolderName AS ASCIIZ _                   ' __in LPTSTR lpszFolderName
   , BYREF lpszFolderComment AS ASCIIZ _                ' __in LPTSTR lpszFolderComment
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppFolder AS IMAPIFolder _                   ' __out LPMAPIFOLDER * lppFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyFolder ( _                                ' VTable offser = 92
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestFolder AS DWORD _                      ' __in LPVOID lpDestFolder
   , BYREF lpszNewFolderName AS ASCIIZ _                ' __in LPTSTR lpszNewFolderName
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteFolder ( _                              ' VTable offser = 96
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL IMAPIProgress _                              ' __in LPMAPIPROGRESS lpProgress
   , BYVAL lpProgress AS DWORD _                        ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReadFlags ( _                              ' VTable offser = 100
     BYVAL lpMsgList AS DWORD _                         ' __in LPENTRYLIST lpMsgList
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageStatus ( _                          ' VTable offser = 104
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulMessageStatus AS DWORD _                 ' __out ULONG * lpulMessageStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMessageStatus ( _                          ' VTable offser = 108
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulNewStatus AS DWORD _                       ' __in ULONG ulNewStatus
   , BYVAL ulNewStatusMask AS DWORD _                   ' __in ULONG ulNewStatusMask
   , BYREF lpulOldStatus AS DWORD _                     ' __out ULONG * lpulOldStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveContentsSort ( _                          ' VTable offser = 112
     BYVAL lpSortCriteria AS SSortOrderSet PTR _        ' __in LPSSortOrderSet lpSortCriteria
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EmptyFolder ( _                               ' VTable offser = 116
     BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMsgStore Interface ----------------------------------------------------- */

'/*  PR_STORE_SUPPORT_MASK bits */
%STORE_ENTRYID_UNIQUE   = &H00000001???
%STORE_READONLY         = &H00000002???
%STORE_SEARCH_OK        = &H00000004???
%STORE_MODIFY_OK        = &H00000008???
%STORE_CREATE_OK        = &H00000010???
%STORE_ATTACH_OK        = &H00000020???
%STORE_OLE_OK           = &H00000040???
%STORE_SUBMIT_OK        = &H00000080???
%STORE_NOTIFY_OK        = &H00000100???
%STORE_MV_PROPS_OK      = &H00000200???
%STORE_CATEGORIZE_OK    = &H00000400???
%STORE_RTF_OK           = &H00000800???
%STORE_RESTRICTION_OK   = &H00001000???
%STORE_SORT_OK          = &H00002000???
%STORE_PUBLIC_FOLDERS   = &H00004000???
%STORE_UNCOMPRESSED_RTF = &H00008000???

'/* PR_STORE_STATE bits, try not to collide with PR_STORE_SUPPORT_MASK */

%STORE_HAS_SEARCHES     = &H01000000???


'/* OpenEntry() */

'/****** MAPI_MODIFY            ((ULONG) 0x00000001) above */
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
'/****** MAPI_BEST_ACCESS      ((ULONG) 0x00000010) above */

'/* SetReceiveFolder() */

'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* GetReceiveFolder() */

'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* GetReceiveFolderTable() */

'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */

'/* StoreLogoff() */

%LOGOFF_NO_WAIT        = &H00000001???
%LOGOFF_ORDERLY        = &H00000002???
%LOGOFF_PURGE          = &H00000004???
%LOGOFF_ABORT          = &H00000008???
%LOGOFF_QUIET          = &H00000010???

%LOGOFF_COMPLETE       = &H00010000???
%LOGOFF_INBOUND        = &H00020000???
%LOGOFF_OUTBOUND       = &H00040000???
%LOGOFF_OUTBOUND_QUEUE = &H00080000???

'/* SetLockState() */

%MSG_LOCKED           = &H00000001???
%MSG_UNLOCKED         = &H00000000???

'/* Flag bits for PR_VALID_FOLDER_MASK */

%FOLDER_IPM_SUBTREE_VALID     = &H00000001???
%FOLDER_IPM_INBOX_VALID       = &H00000002???
%FOLDER_IPM_OUTBOX_VALID      = &H00000004???
%FOLDER_IPM_WASTEBASKET_VALID = &H00000008???
%FOLDER_IPM_SENTMAIL_VALID    = &H00000010???
%FOLDER_VIEWS_VALID           = &H00000020???
%FOLDER_COMMON_VIEWS_VALID    = &H00000040???
%FOLDER_FINDER_VALID          = &H00000080???


' ========================================================================================
' IMsgStore interface (inherits from IMAPIProp)
' $IID_IMsgStore = GUID$("{00020306-0000-0000-C000-000000000046}")
' The IMsgStore interface provides access to message store information and to messages
' and folders.
' ========================================================================================
INTERFACE IMsgStore $IID_IMsgStore

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMsgStore Methods
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offser = 56
     BYVAL lpEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulEventMask  AS DWORD _                      ' __in ULONG ulEventMask
   , BYVAL lpAdviseSink AS IMAPIAdviseSink _            ' __in LPMAPIADVISESINK lpAdviseSink
   , BYREF lpulConnection AS DWORD _                    ' __out ULONG * lpulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offser = 60
     BYVAL ulConnection AS DWORD _                      ' __in ULONG ulConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareEntryIDs ( _                           ' VTable offser = 64
     BYVAL cbEntryID1 AS DWORD _                        ' __in ULONG cbEntryID1
   , BYVAL lpEntryID1 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID1
   , BYVAL cbEntryID2 AS DWORD _                        ' __in ULONG cbEntryID2
   , BYVAL lpEntryID2 AS ENTRYID PTR _                  ' __in LPENTRYID lpEntryID2
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulResult AS DWORD _                        ' __out ULONG * lpulResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenEntry ( _                                 ' VTable offser = 68
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulObjType AS DWORD _                       ' __out ULONG * lpulObjType
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReceiveFolder ( _                          ' VTable offser = 72
     BYREF lpszMessageClass AS ASCIIZ _                 ' __in LPTSTR lpszMessageClass
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReceiveFolder ( _                          ' VTable offser = 76
     BYREF lpszMessageClass AS ASCIIZ _                 ' __in LPTSTR lpszMessageClass
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcbEntryID AS DWORD _                       ' __out ULONG * lpcbEntryID
   , BYREF lppEntryID AS DWORD _                        ' __out LPENTRYID * lppEntryID
   , BYREF lppszExplicitClass AS DWORD _                ' __out LPTSTR * lppszExplicitClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReceiveFolderTable ( _                     ' VTable offser = 80
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoreLogoff ( _                               ' VTable offser = 84
     BYREF lpulFlags AS DWORD _                         ' __inout ULONG * lpulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortSubmit ( _                               ' VTable offser = 88
     BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutgoingQueue ( _                          ' VTable offser = 92
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLockState ( _                              ' VTable offser = 96
     BYVAL lpMessage AS IMessage _                      ' __in LPMESSAGE lpMessage
   , BYVAL ulLockState AS DWORD _                       ' __in ULONG ulLockState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishedMsg ( _                               ' VTable offser = 100
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL cbEntryID AS DWORD _                         ' __in ULONG cbEntryID
   , BYVAL lpEntryID AS ENTRYID PTR _                   ' __in LPENTRYID lpEntryID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyNewMail ( _                             ' VTable offser = 104
     BYREF lpNotification AS NOTIFICATION _             ' __in LPNOTIFICATION lpNotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IMessage Interface ------------------------------------------------------ */

'/* SubmitMessage */

%FORCE_SUBMIT           = &H00000001???

'/* Flags defined in PR_MESSAGE_FLAGS */

%MSGFLAG_READ           = &H00000001???
%MSGFLAG_UNMODIFIED     = &H00000002???
%MSGFLAG_SUBMIT         = &H00000004???
%MSGFLAG_UNSENT         = &H00000008???
%MSGFLAG_HASATTACH      = &H00000010???
%MSGFLAG_FROMME         = &H00000020???
%MSGFLAG_ASSOCIATED     = &H00000040???
%MSGFLAG_RESEND         = &H00000080???
%MSGFLAG_RN_PENDING     = &H00000100???
%MSGFLAG_NRN_PENDING    = &H00000200???

'/* Flags defined in PR_SUBMIT_FLAGS */

%SUBMITFLAG_LOCKED      = &H00000001???
%SUBMITFLAG_PREPROCESS  = &H00000002???

'/* GetAttachmentTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* GetRecipientTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* ModifyRecipients */

'/* ((ULONG) 0x00000001 is not a valid flag on ModifyRecipients. */
%MODRECIP_ADD    = &H00000002???
%MODRECIP_MODIFY = &H00000004???
%MODRECIP_REMOVE = &H00000008???

'/* SetReadFlag */

%SUPPRESS_RECEIPT      = &H00000001???
%CLEAR_READ_FLAG       = &H00000004???
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) below */
%GENERATE_RECEIPT_ONLY = &H00000010???
%CLEAR_RN_PENDING      = &H00000020???
%CLEAR_NRN_PENDING     = &H00000040???

'/* DeleteAttach */

%ATTACH_DIALOG = &H00000001???

'/* PR_SECURITY values */
%SECURITY_SIGNED    = &H00000001???
%SECURITY_ENCRYPTED = &H00000002???

'/* PR_PRIORITY values */
%PRIO_URGENT    =  1&
%PRIO_NORMAL    =  0&
%PRIO_NONURGENT = -1&

'/* PR_SENSITIVITY values */
%SENSITIVITY_NONE                 = &H00000000???
%SENSITIVITY_PERSONAL             = &H00000001???
%SENSITIVITY_PRIVATE              = &H00000002???
%SENSITIVITY_COMPANY_CONFIDENTIAL = &H00000003???

'/* PR_IMPORTANCE values */
%IMPORTANCE_LOW    = 0&
%IMPORTANCE_NORMAL = 1&
%IMPORTANCE_HIGH   = 2&

' ========================================================================================
' IMessage interface (inherits from IMAPIProp
' $IID_IMessage = GUID$("{00020307-0000-0000-C000-000000000046}")
' The IMessage interface is used for managing messages, attachments, and recipients.
' ========================================================================================
INTERFACE IMessage $IID_IMessage

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMessage Methods
   ' =====================================================================================
   METHOD GetAttachmentTable ( _                        ' VTable offser = 56
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenAttach ( _                                ' VTable offser = 60
     BYVAL ulAttachmentNum AS DWORD _                   ' __in ULONG ulAttachmentNum
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppAttach AS IAttach _                       ' __out LPATTACH * lppAttach
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAttach ( _                              ' VTable offser = 64
     BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpulAttachmentNum AS DWORD _                 ' __out ULONG * lpulAttachmentNum
   , BYREF lppAttach AS IAttach _                       ' __out LPATTACH * lppAttach
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAttach ( _                              ' VTable offser = 68
     BYVAL ulAttachmentNum AS DWORD _                   ' __in ULONG ulAttachmentNum
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecipientTable ( _                         ' VTable offser = 72
     BYVAL ulFLags AS DWORD _                           ' __in ULONG ulFLags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyRecipients ( _                          ' VTable offser = 76
     BYVAL ulFLags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lpMods AS ADRLIST PTR _                      ' __in LPADRLIST lpMods
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SubmitMessage ( _                             ' VTable offser = 80
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReadFlag ( _                               ' VTable offser = 84
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* IAttach Interface ------------------------------------------------------- */

'/* IAttach attachment methods: PR_ATTACH_METHOD values */

%NO_ATTACHMENT         = &H00000000???
%ATTACH_BY_VALUE       = &H00000001???
%ATTACH_BY_REFERENCE   = &H00000002???
%ATTACH_BY_REF_RESOLVE = &H00000003???
%ATTACH_BY_REF_ONLY    = &H00000004???
%ATTACH_EMBEDDED_MSG   = &H00000005???
%ATTACH_OLE            = &H00000006???

' ========================================================================================
' IAttach interface (inherits from IMAPIProp)
' $IID_IAttachment = GUID$("{00020308-0000-0000-C000-000000000046}")
' The IAttach interface is used to maintain and provide access to the properties of
' attachments in messages. The IAttach interface has no unique methods of its own.
' ========================================================================================
INTERFACE IAttach $IID_IAttach

   INHERIT IUnknown

   ' =====================================================================================
   ' IMAPIProp Methods
   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offser = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveChanges ( _                               ' VTable offser = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offser = 20
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcValues AS DWORD _                         ' __out ULONG * lpcValues
   , BYREF lppPropArray AS DWORD _                      ' __out LPSPropValue * lppPropArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropList ( _                               ' VTable offser = 24
     BYVAL ulFlags AS DWORD _                           ' __in ulFlags
   , BYREF lppPropTagArray AS DWORD _                   ' __out LPSPropTagArray * lppPropTagArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProperty ( _                              ' VTable offser = 28
     BYVAL ulPropTag AS DWORD _                         ' __in ULONG ulPropTag
   , BYREF lpiid AS GUID _                              ' __in LPCIID lpiid
   , BYVAL ulInterfaceOptions AS DWORD _                ' __in ULONG ulInterfaceOptions
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppUnk AS IUnknown _                         ' __out LPUNKNOWN * lppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offser = 32
     BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYVAL lpPropArray AS SPropValue PTR _              ' __in LPSPropValue lpPropArray [array]
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProps ( _                               ' VTable offser = 36
     BYVAL lpPropTagArray AS SPropTagArray PTR _        ' __in LPSPropTagArray lpPropTagArray
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offser = 40
     BYVAL ciidExclude AS DWORD _                       ' __in ULONG ciidExclude
   , BYREF rgiidExclude AS GUID _                       ' __in LPCIID rgiidExclude
   , BYVAL lpExcludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpExcludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyProps ( _                                 ' VTable offser = 44
     BYVAL lpIncludeProps AS SPropTagArray PTR _        ' __in LPSPropTagArray lpIncludeProps
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL lpProgress AS IMAPIProgress _                ' __in LPMAPIPROGRESS lpProgress
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL lpDestObj AS DWORD _                         ' __in LPVOID lpDestObj
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL lppProblems AS SPropProblemArray PTR _       ' __inout LPSPropProblemArray * lppProblems [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamesFromIDs ( _                           ' VTable offser = 48
     BYVAL lppPropTags AS SPropTagArray PTR _           ' __inout LPSPropTagArray * lppPropTags
   , BYREF lpPropSetGuid AS GUID _                      ' __in LPGUID lpPropSetGuid
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpcPropNames AS DWORD _                      ' __out ULONG * lpcPropNames
   , BYREF lpppPropNames AS DWORD _                     ' __out LPMAPINAMEID * * lpppPropNames [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsFromNames ( _                           ' VTable offser = 52
     BYVAL cPropNames AS DWORD _                        ' __in ULONG cPropNames
   , BYVAL lppPropNames AS MAPINAMEID PTR _             ' __in LPMAPINAMEID * lppPropNames [array]
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppPropTags AS DWORD _                       ' __out LPSPropTagArray * lppPropTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* --------------------------------- */
'/* Address Book interface definition */

'/* ADRPARM ulFlags - top 4 bits used for versioning */

'#define GET_ADRPARM_VERSION(ulFlags)  (((ULONG)ulFlags) & 0xF0000000)

FUNCTION GET_ADRPARM_VERSION (BYVAL ulFlags AS DWORD) AS DWORD
   FUNCTION = ulFlags AND &HF0000000
END FUNCTION

'#define SET_ADRPARM_VERSION(ulFlags, ulVersion)  (((ULONG)ulVersion) | (((ULONG)ulFlags) & 0x0FFFFFFF))

FUNCTION SET_ADRPARM_VERSION (BYVAL ulFlags AS DWORD, BYVAL ulVersion AS DWORD) AS DWORD
   FUNCTION = ulVersion OR ulFlags AND &H0FFFFFFF
END FUNCTION

'/*  Current versions of ADRPARM  */
%ADRPARM_HELP_CTX = &H00000000???

'/*  ulFlags   - bit fields */
%DIALOG_MODAL     = &H00000001???
%DIALOG_SDI       = &H00000002???
%DIALOG_OPTIONS   = &H00000004???
%ADDRESS_ONE      = &H00000008???
%AB_SELECTONLY    = &H00000010???
%AB_RESOLVE       = &H00000020???

'/* --------------------------------- */
'/*  PR_DISPLAY_TYPEs                 */
'/*
' *  These standard display types are
' *  by default handled by MAPI.
' *  They have default icons associated
' *  with them.
' */

'/*  For address book contents tables */
%DT_MAILUSER         = &H00000000???
%DT_DISTLIST         = &H00000001???
%DT_FORUM            = &H00000002???
%DT_AGENT            = &H00000003???
%DT_ORGANIZATION     = &H00000004???
%DT_PRIVATE_DISTLIST = &H00000005???
%DT_REMOTE_MAILUSER  = &H00000006???

'/*  For address book hierarchy tables */
%DT_MODIFIABLE       = &H00010000???
%DT_GLOBAL           = &H00020000???
%DT_LOCAL            = &H00030000???
%DT_WAN              = &H00040000???
%DT_NOT_SPECIFIC     = &H00050000???

'/*  For folder hierarchy tables */
%DT_FOLDER           = &H01000000???
%DT_FOLDER_LINK      = &H02000000???
%DT_FOLDER_SPECIAL   = &H04000000???

'/*  Accelerator callback for DIALOG_SDI form of AB UI */
'typedef BOOL (STDMETHODCALLTYPE ACCELERATEABSDI)(ULONG ulUIParam,
'                                                 LPVOID lpvmsg);
'typedef ACCELERATEABSDI * LPFNABSDI;

'/*  Callback to application telling it that the DIALOG_SDI form of the */
'/*  AB UI has been dismissed.  This is so that the above LPFNABSDI     */
'/*  function doesn't keep being called.                                */
'typedef void (STDMETHODCALLTYPE DISMISSMODELESS)(ULONG ulUIParam,
'                                                 LPVOID lpvContext);
'typedef DISMISSMODELESS * LPFNDISMISS;

'/*
' * Prototype for the client function hooked to an optional button on
' * the address book dialog
' */

'typedef SCODE (STDMETHODCALLTYPE * LPFNBUTTON)(
'   ULONG            ulUIParam,
'   LPVOID           lpvContext,
'   ULONG            cbEntryID,
'   LPENTRYID        lpSelection,
'   ULONG            ulFlags
');


'/* Parameters for the address book dialog */
' // Do not use. Describes the display and behavior of the common address dialog box.
' // Size = 72 bytes
#IF %DEF(%UNICODE)
TYPE ADRPARM DWORD
   cbABContEntryID    AS DWORD              ' ULONG
   lpABContEntryID    AS DWORD              ' LPENTRYID
   ulFlags            AS DWORD              ' ULONG
   lpReserved         AS DWORD              ' LPVOID
   ulHelpContext      AS DWORD              ' ULONG
   lpszHelpFileName   AS WSTRINGZ PTR       ' LPTSTR
   lpfnABSDI          AS DWORD              ' LPFNABSDI
   lpfnDismiss        AS DWORD              ' LPFNDISMISS
   lpvDismissContext  AS DWORD              ' LPVOID
   lpszCaption        AS WSTRINGZ PTR       ' LPTSTR
   lpszNewEntryTitle  AS WSTRINGZ PTR       ' LPTSTR
   lpszDestWellsTitle AS WSTRINGZ PTR       ' LPTSTR
   cDestFields        AS DWORD              ' ULONG
   nDestFieldFocus    AS DWORD              ' ULONG
   lppszDestTitles    AS DWORD              ' LPTSTR * [array]
   lpulDestComps      AS DWORD              ' ULONG * [array]
   lpContRestriction  AS SRestriction PTR   ' LPSRestriction
   lpHierRestriction  AS SRestriction PTR   ' LPSRestriction
END TYPE
#ELSE
TYPE ADRPARM DWORD
   cbABContEntryID    AS DWORD              ' ULONG
   lpABContEntryID    AS DWORD              ' LPENTRYID
   ulFlags            AS DWORD              ' ULONG
   lpReserved         AS DWORD              ' LPVOID
   ulHelpContext      AS DWORD              ' ULONG
   lpszHelpFileName   AS ASCIIZ PTR         ' LPTSTR
   lpfnABSDI          AS DWORD              ' LPFNABSDI
   lpfnDismiss        AS DWORD              ' LPFNDISMISS
   lpvDismissContext  AS DWORD              ' LPVOID
   lpszCaption        AS ASCIIZ PTR         ' LPTSTR
   lpszNewEntryTitle  AS ASCIIZ PTR         ' LPTSTR
   lpszDestWellsTitle AS ASCIIZ PTR         ' LPTSTR
   cDestFields        AS DWORD              ' ULONG
   nDestFieldFocus    AS DWORD              ' ULONG
   lppszDestTitles    AS DWORD              ' LPTSTR * [array]
   lpulDestComps      AS DWORD              ' ULONG * [array]
   lpContRestriction  AS SRestriction PTR   ' LPSRestriction
   lpHierRestriction  AS SRestriction PTR   ' LPSRestriction
END TYPE
#ENDIF

'/* ------------ */
'/* Random flags */

'/* Flag for deferred error */
%MAPI_DEFERRED_ERRORS = &H00000008???

'/* Flag for creating and using Folder Associated Information Messages */
%MAPI_ASSOCIATED      = &H00000040???

'/* Flags for OpenMessageStore() */

%MDB_NO_DIALOG     = &H00000001???
%MDB_WRITE         = &H00000004???
'/****** MAPI_DEFERRED_ERRORS   ((ULONG) 0x00000008) above */
'/****** MAPI_BEST_ACCESS      ((ULONG) 0x00000010) above */
%MDB_TEMPORARY     = &H00000020???
%MDB_NO_MAIL       = &H00000080???

'/* Flags for OpenAddressBook */

%AB_NO_DIALOG      = &H00000001???

'/* IMAPIControl Interface -------------------------------------------------- */

'/* Interface used in controls (particularly the button) defined by */
'/* Display Tables. */

'/*  Flags for GetState */

%MAPI_ENABLED      = &H00000000???
%MAPI_DISABLED     = &H00000001???


' ========================================================================================
' IMAPIControl interface
' $IID_IMAPIControl = GUID$("{0002031B-0000-0000-C000-000000000046}")
' The IMAPIControl interface is used to enable and disable a button control and to perform
' tasks when a user of a client application clicks the enabled control. Service providers
' implement control objects to create custom buttons on dialog boxes, such as configuration
' property sheets, that are defined with display tables.
' ========================================================================================
INTERFACE IMAPIControl $IID_IMAPIControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 20
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF ulUIParam AS DWORD _                         ' __out ULONG * lpulState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/* Display Tables ---------------------------------------------------------- */

'/* Flags used in display tables - that is, PR_CONTROL_FLAGS */

%DT_MULTILINE      = &H00000001???
%DT_EDITABLE       = &H00000002???
%DT_REQUIRED       = &H00000004???
%DT_SET_IMMEDIATE  = &H00000008???
%DT_PASSWORD_EDIT  = &H00000010???
%DT_ACCEPT_DBCS    = &H00000020???
%DT_SET_SELECTION  = &H00000040???

'/* Display Table structures */

%DTCT_LABEL        = &H00000000???
%DTCT_EDIT         = &H00000001???
%DTCT_LBX          = &H00000002???
%DTCT_COMBOBOX     = &H00000003???
%DTCT_DDLBX        = &H00000004???
%DTCT_CHECKBOX     = &H00000005???
%DTCT_GROUPBOX     = &H00000006???
%DTCT_BUTTON       = &H00000007???
%DTCT_PAGE         = &H00000008???
%DTCT_RADIOBUTTON  = &H00000009???
%DTCT_MVLISTBOX    = &H0000000B???
%DTCT_MVDDLBX      = &H0000000C???

'/* Labels */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 8 bytes
TYPE DTBLLABEL DWORD
   ulbLpszLabelName AS DWORD   ' ULONG
   ulFlags          AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE DTBLEDIT DWORD
   ulbLpszCharsAllowed AS DWORD   ' ULONG
   ulFlags             AS DWORD   ' ULONG
   ulNumCharsAllowed   AS DWORD   ' ULONG
   ulPropTag           AS DWORD   ' ULONG
END TYPE

'/*  List Box  */
'/* Valid ulFlags:
' */
%MAPI_NO_HBAR      = &H00000001???
%MAPI_NO_VBAR      = &H00000002???

TYPE DTBLLBX
   ulFlags         AS DWORD   ' ULONG
   ulPRSetProperty AS DWORD   ' ULONG
   ulPRTableName   AS DWORD   ' ULONG
END TYPE

'/*  Combo Box   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */
' // Size = 20 bytes
TYPE DTBLCOMBOBOX DWORD
   ulbLpszCharsAllowed AS DWORD   ' ULONG
   ulFlags             AS DWORD   ' ULONG
   ulNumCharsAllowed   AS DWORD   ' ULONG
   ulPRPropertyName    AS DWORD   ' ULONG
   ulPRTableName       AS DWORD   ' ULONG
END TYPE

'/*  Drop Down   */
'/* Valid ulFlags:
' *   none
' */
' // Size = 16 bytes
TYPE DTBLDDLBX DWORD
   ulFlags             AS DWORD   ' ULONG
   ulPRDisplayProperty AS DWORD   ' ULONG
   ulPRSetProperty     AS DWORD   ' ULONG
   ulPRTableName       AS DWORD   ' ULONG
END TYPE

'/*  Check Box   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 12 bytes
TYPE DTBLCHECKBOX DWORD
   ulbLpszLabel     AS DWORD   ' ULONG
   ulFlags          AS DWORD   ' ULONG
   ulPRPropertyName AS DWORD   ' ULONG
END TYPE

'/*  Group Box   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 8 bytes
TYPE DTBLGROUPBOX DWORD
   ulbLpszLabel AS DWORD   ' ULONG
   ulFlags      AS DWORD   ' ULONG
END TYPE

'/*  Button control   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 12 bytes
TYPE DTBLBUTTON DWORD
   ulbLpszLabel AS DWORD   ' ULONG
   ulFlags      AS DWORD   ' ULONG
   ulPRControl  AS DWORD   ' ULONG
END TYPE

'/*  Pages   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 16 bytes
TYPE DTBLPAGE DWORD
   ulbLpszLabel     AS DWORD   ' ULONG
   ulFlags          AS DWORD   ' ULONG
   ulbLpszComponent AS DWORD   ' ULONG
   ulContext        AS DWORD   ' ULONG
END TYPE

'/*  Radio button   */
'/* Valid ulFlags:
' *   MAPI_UNICODE
' */

' // Size = 20 bytes
TYPE DTBLRADIOBUTTON DWORD
   ulbLpszLabel AS DWORD   ' ULONG
   ulFlags      AS DWORD   ' ULONG
   ulcButtons   AS DWORD   ' ULONG
   ulPropTag    AS DWORD   ' ULONG
   lReturnValue AS LONG    ' LONG
END TYPE

'/*  MultiValued listbox */
'/* Valid ulFlags:
' *   none
' */

' // Size = 8 bytes
TYPE DTBLMVLISTBOX DWORD
   ulFlags     AS DWORD   ' ULONG
   ulMVPropTag AS DWORD   ' ULONG
END TYPE


'/*  MultiValued dropdown */
'/* Valid ulFlags:
' *   none
' */

' // Size = 8 bytes
TYPE DTBLMVDDLBX DWORD
   ulFlags     AS DWORD   ' ULONG
   ulMVPropTag AS DWORD   ' ULONG
END TYPE


'/* IProviderAdmin Interface ---------------------------------------------- */

'/* Flags for ConfigureMsgService */

%UI_SERVICE                = &H00000002
%SERVICE_UI_ALWAYS         = &H00000002    '  /* Duplicate UI_SERVICE for consistency and compatibility */
%SERVICE_UI_ALLOWED        = &H00000010
%UI_CURRENT_PROVIDER_FIRST = &H00000004
'/* MSG_SERVICE_UI_READ_ONLY       0x00000008 - in MAPISPI.H */

'/* GetProviderTable() */
'/****** MAPI_UNICODE         ((ULONG) 0x80000000) above */

'/* Values for PR_RESOURCE_FLAGS in message service table */

' ========================================================================================
' IProviderAdmin interface
' $IID_IProviderAdmin = GUID$("{00020325-0000-0000-C000-000000000046}")
' The IProviderAdmin interface is used to work with service providers within a message service.
' ========================================================================================
INTERFACE IProviderAdmin $IID_IProviderAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastError ( _                              ' VTable offset = 12
     BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppMAPIError AS DWORD _                      ' __out LPMAPIERROR * lppMAPIError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProviderTable ( _                          ' VTable offset = 16
     BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppTable AS IMAPITable _                     ' __out LPMAPITABLE * lppTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateProvider ( _                            ' VTable offset = 20
     BYREF lpszProvider AS ASCIIZ _                     ' __in LPTSTR lpszProvider
   , BYVAL cValues AS DWORD _                           ' __in ULONG cValues
   , BYREF lpProps AS SPropValue _                      ' __in LPSPropValue lpProps [array]
   , BYVAL ulUIParam AS DWORD _                         ' __in ULONG ulUIParam
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lpUID AS GUID _                              ' __out MAPIUID * lpUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProvider ( _                            ' VTable offset = 24
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenProfileSection ( _                        ' VTable offset = 28
     BYREF lpUID AS GUID _                              ' __in LPMAPIUID lpUID
   , BYREF lpInterface AS GUID _                        ' __in LPCIID lpInterface
   , BYVAL ulFlags AS DWORD _                           ' __in ULONG ulFlags
   , BYREF lppProfSect AS IProfSect _                   ' __out LPPROFSECT * lppProfSect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
