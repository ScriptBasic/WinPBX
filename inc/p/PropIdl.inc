' ########################################################################################
' Microsoft Windows
' File: propidl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROPIDL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oaidl.inc"

' // Size = 20 bytes
TYPE VERSIONEDSTREAM DWORD
   guidVersion AS GUID        ' GUID guidVersion
   pStream     AS DWORD PTR   ' IStream *pStream
END TYPE

'// Flags for IPropertySetStorage::Create
%PROPSETFLAG_DEFAULT             = 0
%PROPSETFLAG_NONSIMPLE           = 1
%PROPSETFLAG_ANSI                = 2
'//   (This flag is only supported on StgCreatePropStg & StgOpenPropStg
%PROPSETFLAG_UNBUFFERED          = 4
'//   (This flag causes a version-1 property set to be created
%PROPSETFLAG_CASE_SENSITIVE      = 8
'// Flags for the reservied PID_BEHAVIOR property
%PROPSET_BEHAVIOR_CASE_SENSITIVE = 1

' // Size = 8 bytes
TYPE CAC DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS BYTE PTR   ' /* [size_is] */ CHAR *pElems
END TYPE

' // Size = 8 bytes
TYPE CAUB DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS BYTE PTR   ' /* [size_is] */ UCHAR *pElems
END TYPE

' // Size = 8 bytes
TYPE CAI DWORD
   cElems AS DWORD         ' ULONG cElems
   pElems AS INTEGER PTR   ' /* [size_is] */ SHORT *pElems
END TYPE

' // Size = 8 bytes
TYPE CAUI DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS WORD PTR   ' /* [size_is] */ USHORT *pElems
END TYPE

' // Size = 8 bytes
TYPE CAL DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS LONG PTR   ' /* [size_is] */ LONG *pElems
END TYPE

' // Size = 8 bytes
TYPE CAUL DWORD
   cElems AS DWORD       ' ULONG cElems
   pElems AS DWORD PTR   ' /* [size_is] */ ULONG *pElems
END TYPE

' // Size = 8 bytes
TYPE CAFLT DWORD
   cElems AS DWORD        ' ULONG cElems
   pElems AS SINGLE PTR   ' /* [size_is] */ FLOAT *pElems
END TYPE

' // Size = 8 bytes
TYPE CADBL DWORD
   cElems AS DWORD        ' ULONG cElems
   pElems AS DOUBLE PTR   ' /* [size_is] */ DOUBLE *pElems
END TYPE

' // Size = 8 bytes
TYPE CACY DWORD
   cElems AS DWORD     ' ULONG cElems
   pElems AS CUR PTR   ' /* [size_is] */ CY *pElems
END TYPE

' // Size = 8 bytes
TYPE CADATE DWORD
   cElems AS DWORD        ' ULONG cElems
   pElems AS DOUBLE PTR   ' /* [size_is] */ DATE *pElems
END TYPE

' // Size = 8 bytes
TYPE CABSTR DWORD
   cElems AS DWORD        ' ULONG cElems
   pElems AS STRING PTR   ' /* [size_is] */ BSTR *pElems
END TYPE

' // Size = 8 bytes
TYPE CABSTRBLOB DWORD
   cElems AS DWORD          ' ULONG cElems
   pElems AS BSTRBLOB PTR   ' /* [size_is] */ BSTRBLOB *pElems
END TYPE

' // Size = 8 bytes
TYPE CABOOL DWORD
   cElems AS DWORD         ' ULONG cElems
   pElems AS INTEGER PTR   ' /* [size_is] */ VARIANT_BOOL *pElems
END TYPE

' // Size = 8 bytes
TYPE CASCODE DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS LONG PTR   ' /* [size_is] */ SCODE *pElems
END TYPE

' // Size = 8 bytes
TYPE CAPROPVARIANT DWORD
   cElems AS DWORD       ' ULONG cElems
   pElems AS DWORD PTR   ' /* [size_is] */ PROPVARIANT *pElems
   ' // Should be PROPVARIANT PTR, but PB doesn't support forward references to structures
END TYPE

' // Size = 8 bytes
TYPE CAH DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS QUAD PTR   ' /* [size_is] */ LARGE_INTEGER *pElems
END TYPE

' // Size = 8 bytes
TYPE CAUH DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS QUAD PTR   ' /* [size_is] */ ULARGE_INTEGER *pElems
END TYPE

' // Size = 8 bytes
TYPE CALPSTR DWORD
   cElems AS DWORD        ' ULONG cElems
   pElems AS ASCIIZ PTR   ' /* [size_is] */ LPSTR *pElems
END TYPE

' // Size = 8 bytes
TYPE CALPWSTR DWORD
   cElems AS DWORD          ' ULONG cElems
   pElems AS WSTRINGZ PTR   ' /* [size_is] */ LPWSTR *pElems
END TYPE

' // Size = 8 bytes
TYPE CAFILETIME DWORD
   cElems AS DWORD          ' ULONG cElems
   pElems AS FILETIME PTR   ' /* [size_is] */ FILETIME *pElems
END TYPE

' // Size = 8 bytes
TYPE CACLIPDATA DWORD
   cElems AS DWORD          ' ULONG cElems
   pElems AS CLIPDATA PTR   ' /* [size_is] */ CLIPDATA *pElems
END TYPE

' // Size = 8 bytes
TYPE CACLSID DWORD
   cElems AS DWORD      ' ULONG cElems
   pElems AS GUID PTR   ' /* [size_is] */ CLSID *pElems
END TYPE

'#ifdef MIDL_PASS
'// This is the PROPVARIANT padding layout for marshaling.
'typedef BYTE PROPVAR_PAD1;

'typedef BYTE PROPVAR_PAD2;

'typedef ULONG PROPVAR_PAD3;

'#else
'// This is the standard C layout of the structure.
'typedef WORD PROPVAR_PAD1;
'typedef WORD PROPVAR_PAD2;
'typedef WORD PROPVAR_PAD3;
'#define tag_inner_PROPVARIANT
'#endif

'#if !defined(_MSC_EXTENSIONS)

'struct tagPROPVARIANT;

'#else
'#ifndef MIDL_PASS
'struct tagPROPVARIANT {
'  union {
'#endif
'struct tag_inner_PROPVARIANT
'    {
'    VARTYPE vt;
'    PROPVAR_PAD1 wReserved1;
'    PROPVAR_PAD2 wReserved2;
'    PROPVAR_PAD3 wReserved3;
'    /* [switch_type] */ union
'        {
'         /* Empty union arm */
'        CHAR cVal;
'        UCHAR bVal;
'        SHORT iVal;
'        USHORT uiVal;
'        LONG lVal;
'        ULONG ulVal;
'        INT intVal;
'        UINT uintVal;
'        LARGE_INTEGER hVal;
'        ULARGE_INTEGER uhVal;
'        FLOAT fltVal;
'        DOUBLE dblVal;
'        VARIANT_BOOL boolVal;
'        _VARIANT_BOOL bool;
'        SCODE scode;
'        CY cyVal;
'        DATE date;
'        FILETIME filetime;
'        CLSID *puuid;
'        CLIPDATA *pclipdata;
'        BSTR bstrVal;
'        BSTRBLOB bstrblobVal;
'        BLOB blob;
'        LPSTR pszVal;
'        LPWSTR pwszVal;
'        IUnknown *punkVal;
'        IDispatch *pdispVal;
'        IStream *pStream;
'        IStorage *pStorage;
'        LPVERSIONEDSTREAM pVersionedStream;
'        LPSAFEARRAY parray;
'        CAC cac;
'        CAUB caub;
'        CAI cai;
'        CAUI caui;
'        CAL cal;
'        CAUL caul;
'        CAH cah;
'        CAUH cauh;
'        CAFLT caflt;
'        CADBL cadbl;
'        CABOOL cabool;
'        CASCODE cascode;
'        CACY cacy;
'        CADATE cadate;
'        CAFILETIME cafiletime;
'        CACLSID cauuid;
'        CACLIPDATA caclipdata;
'        CABSTR cabstr;
'        CABSTRBLOB cabstrblob;
'        CALPSTR calpstr;
'        CALPWSTR calpwstr;
'        CAPROPVARIANT capropvar;
'        CHAR *pcVal;
'        UCHAR *pbVal;
'        SHORT *piVal;
'        USHORT *puiVal;
'        LONG *plVal;
'        ULONG *pulVal;
'        INT *pintVal;
'        UINT *puintVal;
'        FLOAT *pfltVal;
'        DOUBLE *pdblVal;
'        VARIANT_BOOL *pboolVal;
'        DECIMAL *pdecVal;
'        SCODE *pscode;
'        CY *pcyVal;
'        DATE *pdate;
'        BSTR *pbstrVal;
'        IUnknown **ppunkVal;
'        IDispatch **ppdispVal;
'        LPSAFEARRAY *pparray;
'        PROPVARIANT *pvarVal;
'        } 	;
'    } ;
'#ifndef MIDL_PASS
'    DECIMAL decVal;
'  };
'};
'#endif

'#endif /* _MSC_EXTENSIONS */

'#ifdef MIDL_PASS
'// This is the LPPROPVARIANT definition for marshaling.
'typedef struct tag_inner_PROPVARIANT *LPPROPVARIANT;

'typedef const PROPVARIANT *REFPROPVARIANT;

'#else

'// This is the standard C layout of the PROPVARIANT.
'typedef struct tagPROPVARIANT * LPPROPVARIANT;

'#ifndef _REFPROPVARIANT_DEFINED
'#define _REFPROPVARIANT_DEFINED
'#ifdef __cplusplus
'#define REFPROPVARIANT const PROPVARIANT &
'#else
'#define REFPROPVARIANT const PROPVARIANT * __MIDL_CONST
'#endif
'#endif

'#endif // MIDL_PASS

' // Size = 8 bytes
UNION PROPVARIANTDATA
   cVal             AS BYTE                 ' CHAR [VT_I1]
   bVal             AS BYTE                 ' UCHAR [VT_UI1]
   iVal             AS INTEGER              ' SHORT [VT_I2]
   uiVal            AS WORD                 ' USHORT [VT_UI2]
   lVal             AS LONG                 ' LONG [VT_I4]
   ulVal            AS DWORD                ' ULONG [VT_UI4]
   intVal           AS LONG                 ' INT [VT_INT]
   uintVal          AS DWORD                ' UINT [VT_UINT]
   hVal             AS QUAD                 ' LARGE_INTEGER <record>
   uhVal            AS QUAD                 ' ULARGE_INTEGER <record>
   fltVal           AS SINGLE               ' FLOAT [VT_R4]
   dblVal           AS DOUBLE               ' DOUBLE [VT_R8]
   boolVal          AS INTEGER              ' VARIANT_BOOL [VT_BOOL]
   bool             AS INTEGER              ' _VARIANT_BOOL
   scode            AS LONG                 ' SCODE [VT_ERROR]
   cyVal            AS CUR                  ' CY [VT_CY]
   date             AS DOUBLE               ' DATE [VT_DATE]
   fileTime         AS FILETIME             ' FILETIME <record>
   puuid            AS GUID PTR             ' CLSID __RPC_FAR *puuid [*GUID <record>]
   pclipdata        AS CLIPDATA PTR         ' CLIPDATA __RPC_FAR *pclipdata [*CLIPDATA <record>]
   bstrVal          AS DWORD                ' BSTR [VT_BSTR <DYNAMIC UNICODE STRING>]
   bstrblobVal      AS BSTRBLOB             ' BSTRBLOB <record> [VT_BSTR_BLOB]
   blob             AS BLOB                 ' BLOB <record> [VT_BLOB, VT_BLOBOBJECT]
   pszVal           AS ASCIIZ PTR           ' LPSTR [VT_LPSTR <NULL TERMINATED ANSI STRING>]
   pwszVal          AS WSTRINGZ PTR         ' LPWSTR [VT_LPWSTR <NULL TERMINATED UNICODE STRING>]
   punkVal          AS DWORD PTR            ' IUnknown* [VT_UNKNOWN]
   pdispVal         AS DWORD PTR            ' IDispatch* [VT_DISPATCH]
   pStream          AS DWORD PTR            ' IStream __RPC_FAR *pStream [*IStream <interface>] [VT_STREAM, VT_STREAMED_OBJECT]
   pStorage         AS DWORD PTR            ' IStorage __RPC_FAR *pStorage [*IStorage <interface>] [VT_STORAGE, VT_STORED_OBJECT]
   pVersionedStream AS VersionedStream PTR  ' *VersionedStream <record> [VT_VERSIONED_STREAM]
   parray           AS SAFEARRAY PTR        ' LPSAFEARRAY [VT_ARRAY | VT_*, Version 1]
   cac              AS CAC                  ' CAC <record> [VT_VECTOR | VT_I1, Version 1]
   caub             AS CAUB                 ' CAUB <record> [VT_VECTOR | VT_UI1]
   cai              AS CAI                  ' CAI <record> [VT_VECTOR | VT_I2]
   caui             AS CAUI                 ' CAUI <record> [VT_VECTOR | VT_UI2]
   cal              AS CAL                  ' CAL <record> [VT_VECTOR | VT_I4]
   caul             AS CAUL                 ' CAUL <record> [VT_VECTOR | VT_UI4]
   cah              AS CAH                  ' CAH <record> [VT_VECTOR | VT_I8]
   cauh             AS CAUH                 ' CAUH <record> [VT_VECTOR | VT_UI8]
   caflt            AS CAFLT                ' CAFLT <record> [VT_VECTOR | VT_R4]
   cadbl            AS CADBL                ' CADBL <record> [VT_VECTOR | VT_R8]
   cabool           AS CABOOL               ' CABOOL <record> [VT_VECTOR | VT_BOOL]
   cascode          AS CASCODE              ' CASCODE <record> [VT_VECTOR | VT_ERROR]
   cacy             AS CACY                 ' CACY <record> [VT_VECTOR | VT_CY]
   cadate           AS CADATE               ' CADATE <record> [VT_VECTOR | VT_DATE]
   cafiletime       AS CAFILETIME           ' CAFILETIME <record> [VT_VECTOR | VT_FILETIME]
   cauuid           AS CACLSID              ' CACLSID <record> [VT_VECTOR | VT_CLSID]
   caclipdata       AS CACLIPDATA           ' CACLIPDATA <record> [VT_VECTOR | VT_CF]
   cabstr           AS CABSTR               ' CABSTR <record> [VT_VECTOR | VT_BSTR]
   cabstrblob       AS CABSTRBLOB           ' CABSTRBLOB <record> [VT_VECTOR | VT_BSTR_BLOB]
   calpstr          AS CALPSTR              ' CALPSTR <record> [VT_VECTOR | VT_LPSTR]
   calpwstr         AS CALPWSTR             ' CALPWSTR <record> [VT_VECTOR | VT_LPWSTR]
   cappropvar       AS CAPROPVARIANT        ' CAPROPVARIANT <record> [VT_VECTOR | VT_VARIANT]
   pcVal            AS BYTE PTR             ' CHAR* [VT_BYREF | VT_I1, Version 1]
   pbVal            AS BYTE PTR             ' UCHAR* [VT_BYREF | VT_UI1, Version 1]
   piVal            AS INTEGER PTR          ' SHORT* [VT_BYREF | VT_I2, Version 1]
   puiVal           AS WORD PTR             ' USHORT* [VT_BYREF | VT_UI2, Version 1]
   plVal            AS LONG PTR             ' LONG* [VT_BYREF | VT_I4, Version 1]
   pulVal           AS DWORD PTR            ' ULONG* [VT_BYREF | VT_UI4, Version 1]
   pintVal          AS LONG PTR             ' INT* [VT_BYREF | VT_INT, Version 1]
   puintVal         AS DWORD PTR            ' UINT* [VT_BYREF | VT_UINT, Version 1]
   pfltVal          AS SINGLE PTR           ' FLOAT* [VT_BYREF | VT_R4, Version 1]
   pdblVal          AS DOUBLE PTR           ' DOUBLE* [VT_BYREF | VT_R8, Version 1]
   pboolVal         AS INTEGER PTR          ' VARIANT_BOOL* [VT_BYREF | VT_BOOL, Version 1]
   pdecVal          AS DECIMAL PTR          ' DECIMAL* [VT_BYREF | VT_DECIMAL, Version 1]
   pscode           AS LONG PTR             ' SCODE* [VT_BYREF | VT_ERROR, Version 1]
   pcyVal           AS CUR PTR              ' CY* [VT_BYREF | VT_CY, Version 1]
   pdate            AS DOUBLE PTR           ' DATE* [VT_BYREF | VT_DATE, Version 1]
   pbstrVal         AS DWORD                ' BSTR* [VT_BYREF | VT_BSTR, Version 1]
   ppunkVal         AS DWORD PTR            ' IUnknown** [VT_BYREF | VT_UNKNOWN, Version 1]
   ppdispVal        AS DWORD PTR            ' IDispatch** [VT_BYREF | VT_DISPATCH, Version 1]
   pparray          AS SAFEARRAY PTR        ' LPSAFEARRAY* [VT_BYREF | VT_ARRAY, Version 1]
   pvarVal          AS DWORD                ' PROPVARIANT* [VT_BYREF | VT_VARIANT, Version 1]
END UNION

' // Size = 16 bytes
TYPE tag_inner_PROPVARIANT DWORD FILL
   vt               AS WORD   ' VARTYPE
   wReserved1       AS WORD
   wReserved2       AS WORD
   wReserved3       AS WORD
   PROPVARIANTDATA
END TYPE

' // Size = 16 bytes
UNION PROPVARIANT_UNION
   tag_inner_PROPVARIANT
   decVal AS DECIMAL
END UNION

' // Size = 16 bytes
TYPE PROPVARIANT
   PROPVARIANT_UNION
END TYPE

'// Reserved global Property IDs
%PID_DICTIONARY         = 0???
%PID_CODEPAGE           = &H1???
%PID_FIRST_USABLE       = &H2???
%PID_FIRST_NAME_DEFAULT = &HFFF???
%PID_LOCALE             = &H80000000???
%PID_MODIFY_TIME        = &H80000001???
' Declared with an underscore because there is a name conflict
' with another PID_SECURITY declared in MsiDefs.h with a different value
%PID_SECURITY_          = &H80000002???
%PID_BEHAVIOR           = &H80000003???
%PID_ILLEGAL            = &HFFFFFFFF???

'// Range which is read-only to downlevel implementations

%PID_MIN_READONLY       = &H80000000???
%PID_MAX_READONLY       = &HBFFFFFFF???

'// Property IDs for the DiscardableInformation Property Set

%PIDDI_THUMBNAIL        = &H00000002???  ' // VT_BLOB

'// Property IDs for the SummaryInformation Property Set

%PIDSI_TITLE            = &H00000002???   ' // VT_LPSTR
%PIDSI_SUBJECT          = &H00000003???   ' // VT_LPSTR
%PIDSI_AUTHOR           = &H00000004???   ' // VT_LPSTR
%PIDSI_KEYWORDS         = &H00000005???   ' // VT_LPSTR
%PIDSI_COMMENTS         = &H00000006???   ' // VT_LPSTR
%PIDSI_TEMPLATE         = &H00000007???   ' // VT_LPSTR
%PIDSI_LASTAUTHOR       = &H00000008???   ' // VT_LPSTR
%PIDSI_REVNUMBER        = &H00000009???   ' // VT_LPSTR
%PIDSI_EDITTIME         = &H0000000A???   ' // VT_FILETIME (UTC)
%PIDSI_LASTPRINTED      = &H0000000B???   ' // VT_FILETIME (UTC)
%PIDSI_CREATE_DTM       = &H0000000C???   ' // VT_FILETIME (UTC)
%PIDSI_LASTSAVE_DTM     = &H0000000D???   ' // VT_FILETIME (UTC)
%PIDSI_PAGECOUNT        = &H0000000E???   ' // VT_I4
%PIDSI_WORDCOUNT        = &H0000000F???   ' // VT_I4
%PIDSI_CHARCOUNT        = &H00000010???   ' // VT_I4
%PIDSI_THUMBNAIL        = &H00000011???   ' // VT_CF
%PIDSI_APPNAME          = &H00000012???   ' // VT_LPSTR
%PIDSI_DOC_SECURITY     = &H00000013???   ' // VT_I4

'// Property IDs for the DocSummaryInformation Property Set

%PIDDSI_CATEGORY        = &H00000002???    ' // VT_LPSTR
%PIDDSI_PRESFORMAT      = &H00000003???    ' // VT_LPSTR
%PIDDSI_BYTECOUNT       = &H00000004???    ' // VT_I4
%PIDDSI_LINECOUNT       = &H00000005???    ' // VT_I4
%PIDDSI_PARCOUNT        = &H00000006???    ' // VT_I4
%PIDDSI_SLIDECOUNT      = &H00000007???    ' // VT_I4
%PIDDSI_NOTECOUNT       = &H00000008???    ' // VT_I4
%PIDDSI_HIDDENCOUNT     = &H00000009???    ' // VT_I4
%PIDDSI_MMCLIPCOUNT     = &H0000000A???    ' // VT_I4
%PIDDSI_SCALE           = &H0000000B???    ' // VT_BOOL
%PIDDSI_HEADINGPAIR     = &H0000000C???    ' // VT_VARIANT | VT_VECTOR
%PIDDSI_DOCPARTS        = &H0000000D???    ' // VT_LPSTR | VT_VECTOR
%PIDDSI_MANAGER         = &H0000000E???    ' // VT_LPSTR
%PIDDSI_COMPANY         = &H0000000F???    ' // VT_LPSTR
%PIDDSI_LINKSDIRTY      = &H00000010???    ' // VT_BOOL

'//  FMTID_MediaFileSummaryInfo - Property IDs

%PIDMSI_EDITOR          = &H00000002???   ' // VT_LPWSTR
%PIDMSI_SUPPLIER        = &H00000003???   ' // VT_LPWSTR
%PIDMSI_SOURCE          = &H00000004???   ' // VT_LPWSTR
%PIDMSI_SEQUENCE_NO     = &H00000005???   ' // VT_LPWSTR
%PIDMSI_PROJECT         = &H00000006???   ' // VT_LPWSTR
%PIDMSI_STATUS          = &H00000007???   ' // VT_UI4
%PIDMSI_OWNER           = &H00000008???   ' // VT_LPWSTR
%PIDMSI_RATING          = &H00000009???   ' // VT_LPWSTR
%PIDMSI_PRODUCTION      = &H0000000A???   ' // VT_FILETIME (UTC)
%PIDMSI_COPYRIGHT       = &H0000000B???   ' // VT_LPWSTR

'//  PIDMSI_STATUS value definitions

' PIDMSI_STATUS_VALUE enum
%PIDMSI_STATUS_NORMAL     = 0
%PIDMSI_STATUS_NEW        = %PIDMSI_STATUS_NORMAL     + 1
%PIDMSI_STATUS_PRELIM     = %PIDMSI_STATUS_NEW        + 1
%PIDMSI_STATUS_DRAFT      = %PIDMSI_STATUS_PRELIM     + 1
%PIDMSI_STATUS_INPROGRESS = %PIDMSI_STATUS_DRAFT      + 1
%PIDMSI_STATUS_EDIT       = %PIDMSI_STATUS_INPROGRESS + 1
%PIDMSI_STATUS_REVIEW     = %PIDMSI_STATUS_EDIT       + 1
%PIDMSI_STATUS_PROOF      = %PIDMSI_STATUS_REVIEW     + 1
%PIDMSI_STATUS_FINAL      = %PIDMSI_STATUS_PROOF      + 1
%PIDMSI_STATUS_OTHER      = &H7FFF

%PRSPEC_INVALID = &HFFFFFFFF???
%PRSPEC_LPWSTR  = 0
%PRSPEC_PROPID  = 1

' // Size = 4 bytes
UNION PROPSPECDATA DWORD
   propid AS DWORD          ' PROPID
   lpwstr AS WSTRINGZ PTR   ' LPOLESTR
END UNION

' // Size = 8 bytes
TYPE PROPSPEC DWORD
   ulKind AS DWORD   ' ULONG
   PROPSPECDATA
END TYPE

' // Size = 12 bytes
TYPE STATPROPSTG DWORD  ' Must be DWORD aligned
   lpwstrName AS WSTRINGZ PTR   ' LPOLESTR
   propid     AS DWORD          ' PROPID
   vt         AS WORD           ' VARTYPE
END TYPE

'// Macros for parsing the OS Version of the Property Set Header
'#define PROPSETHDR_OSVER_KIND(dwOSVer)      HIWORD( (dwOSVer) )
'#define PROPSETHDR_OSVER_MAJOR(dwOSVer)     LOBYTE(LOWORD( (dwOSVer) ))
'#define PROPSETHDR_OSVER_MINOR(dwOSVer)     HIBYTE(LOWORD( (dwOSVer) ))
'#define PROPSETHDR_OSVERSION_UNKNOWN        0xFFFFFFFF

MACRO PROPSETHDR_OSVER_KIND(dwOSVer)  = HI(WORD,dwOSVer)
MACRO PROPSETHDR_OSVER_MAJOR(dwOSVer) = LO(BYTE,(LO(WORD,dwOSVer)))
MACRO PROPSETHDR_OSVER_MINOR(dwOSVer) = HI(BYTE,(LO(WORD,dwOSVer)))
MACRO PROPSETHDR_OSVERSION_UNKNOWN    = &HFFFFFFFF???

' // Size = 64 bytes
TYPE STATPROPSETSTG DWORD
   fmtid       AS GUID       ' FMTID
   clsid       AS GUID       ' CLSID
   grfFlags    AS DWORD      ' DWORD
   mtime       AS FILETIME   ' FILETIME
   ctime       AS FILETIME   ' FILETIME
   atime       AS FILETIME   ' FILETIME
   dwOSVersion AS DWORD      ' DWORD
END TYPE


' ########################################################################################
' IPropertyStorage interface
' IID = 00000138-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyStorage_INTERFACE_DEFINED)
    %IPropertyStorage_INTERFACE_DEFINED = 1

$IID_IPropertyStorage = GUID$("{00000138-0000-0000-C000-000000000046}")

INTERFACE IPropertyStorage $IID_IPropertyStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadMultiple ( _                              ' VTable offset = 12
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[]
   , BYREF rgpropvar AS PROPVARIANT _                   ' __in PROPVARIANT rgpropvar[1]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteMultiple ( _                             ' VTable offset = 16
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[]
   , BYREF rgpropvar AS PROPVARIANT _                   ' __in const PROPVARIANT rgpropvar[]
   , BYVAL propidNameFirst AS DWORD _                   ' __in PROPID propidNameFirst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMultiple ( _                            ' VTable offset = 20
     BYVAL cpspec AS DWORD _                            ' __in ULONG cpspec
   , BYREF rgpspec AS PROPSPEC _                        ' __in const PROPSPEC rgpspec[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadPropertyNames ( _                         ' VTable offset = 24
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[]
   , BYREF rglpwstrName AS DWORD _                      ' __inout LPWSTR rglpwstrName[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WritePropertyNames ( _                        ' VTable offset = 28
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[]
   , BYREF rglpwstrName AS DWORD _                      ' __in LPWSTR const rglpwstrName[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeletePropertyNames ( _                       ' VTable offset = 32
     BYVAL cpropid AS DWORD _                           ' __in ULONG cpropid
   , BYREF rgpropid AS DWORD _                          ' __in const PROPID rgpropid[]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 36
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enum ( _                                      ' VTable offset = 44
     BYREF ppenum AS IEnumSTATPROPSTG _                 ' __out IEnumSTATPROPSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimes ( _                                  ' VTable offset = 48
     BYREF pctime AS FILETIME _                         ' __in const FILETIME* pctime
   , BYREF patime AS FILETIME _                         ' __in const FILETIME* patime
   , BYREF pmtime AS FILETIME _                         ' __in const FILETIME* pmtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClass ( _                                  ' VTable offset = 52
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 56
     BYREF pstatpsstg AS STATPROPSETSTG _               ' __out STATPROPSETSTG* pstatpsstg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertySetStorage interface
' IID = 0000013A-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertySetStorage_INTERFACE_DEFINED)
    %IPropertySetStorage_INTERFACE_DEFINED = 1

$IID_IPropertySetStorage = GUID$("{0000013A-0000-0000-C000-000000000046}")

INTERFACE IPropertySetStorage $IID_IPropertySetStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYREF pclsid AS GUID _                             ' __in const CLSID* pclsid
   , BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYREF ppProgStg AS IPropertyStorage _              ' __out IPropertyStorage** ppProgStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 16
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYREF ppPropStg AS IPropertyStorage _              ' __out IPropertyStorage** ppPropStg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 20
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enum ( _                                      ' VTable offset = 24
     BYREF ppenum AS IEnumSTATPROPSETSTG _              ' __out IEnumSTATPROPSETSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertySetStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumSTATPROPSTG interface
' IID = 00000139-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSTATPROPSTG_INTERFACE_DEFINED)
    %IEnumSTATPROPSTG_INTERFACE_DEFINED = 1

$IID_IEnumSTATPROPSTG = GUID$("{00000139-0000-0000-C000-000000000046}")

INTERFACE IEnumSTATPROPSTG $IID_IEnumSTATPROPSTG

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS STATPROPSTG _                       ' __out STATPROPSTG* rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
      BYVAL celt AS DWORD _                             ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumSTATPROPSTG _                 ' __out IEnumSTATPROPSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSTATPROPSTG_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumSTATPROPSETSTG interface
' IID = 0000013B-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSTATPROPSETSTG_INTERFACE_DEFINED)
    %IEnumSTATPROPSETSTG_INTERFACE_DEFINED = 1

$IID_IEnumSTATPROPSETSTG = GUID$("{0000013B-0000-0000-C000-000000000046}")


INTERFACE IEnumSTATPROPSETSTG $IID_IEnumSTATPROPSETSTG

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS STATPROPSETSTG _                    ' __out STATPROPSETSTG* rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumSTATPROPSETSTG _              ' __out IEnumSTATPROPSETSTG** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ */


DECLARE FUNCTION PropVariantCopy IMPORT "OLE32.DLL" ALIAS "PropVariantCopy" ( _
   BYREF pvarDest AS ANY _                              ' __out PROPVARIANT* pvarDest
 , BYREF pvarSrc AS ANY _                               ' __in const PROPVARIANT* pvarSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PropVariantClear IMPORT "OLE32.DLL" ALIAS "PropVariantClear" ( _
   BYREF pvar AS ANY _                                  ' __in PROPVARIANT* pvar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FreePropVariantArray IMPORT "OLE32.DLL" ALIAS "FreePropVariantArray" ( _
   BYVAL cVariants AS DWORD _                           ' __in ULONG cVariants
 , BYREF rgvars AS PROPVARIANT _                        ' __inout PROPVARIANT* rgvars [array]
 ) AS LONG                                              ' HRESULT

'#if defined(_MSC_EXTENSIONS)


'#define _PROPVARIANTINIT_DEFINED_
'#   ifdef __cplusplus
'inline void PropVariantInit (__out PROPVARIANT * pvar )
'{
'    memset ( pvar, 0, sizeof(PROPVARIANT) );
'}
'#   else
'#   define PropVariantInit(pvar) memset ( (pvar), 0, sizeof(PROPVARIANT) )
'#   endif

'#endif /* _MSC_EXTENSIONS */

%PROPVARIANTINIT_DEFINED = 1
' Note: PropVariantInit is not an exported function, but an inline macro:
'    PropVariantInit(p) memset((p), 0, sizeof(PROPVARIANT))")
' It is not needed with powerBASIC, that already initializes it, or you can use:
'    ZeroMemory(VARPTR(p), SIZEOF(PROPVARIANT))
SUB PropVariantinit (BYREF p AS PROPVARIANT)
   ZeroMemory(BYVAL VARPTR(p), SIZEOF(PROPVARIANT))
END SUB

#IF NOT %DEF(%STGCREATEPROPSTG_DEFINED)
    %STGCREATEPROPSTG_DEFINED = 1

DECLARE FUNCTION StgCreatePropStg IMPORT "OLE32.DLL" ALIAS "StgCreatePropStg" ( _
   BYVAL pUnk AS IUnknown _                             ' __in  IUnknown* pUnk
 , BYREF fmtid AS GUID _                                ' __in  REFFMTID fmtid
 , BYREF pclsid AS GUID _                               ' __in  const CLSID* pclsid
 , BYVAL grfFlags AS DWORD _                            ' __in  DWORD grfFlags
 , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
 , BYREF ppPropStg AS IPropertyStorage _                ' __out IPropertyStorage** ppPropStg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgOpenPropStg IMPORT "OLE32.DLL" ALIAS "StgOpenPropStg" ( _
   BYVAL pUnk AS IUnknown _                             ' __in  IUnknown* pUnk
 , BYREF fmtid AS GUID _                                ' __in  REFFMTID fmtid
 , BYVAL grfFlags AS DWORD _                            ' __in  DWORD grfFlags
 , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
 , BYREF ppPropStg AS IPropertyStorage _                ' __out IPropertyStorage** ppPropStg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StgCreatePropSetStg IMPORT "OLE32.DLL" ALIAS "StgCreatePropSetStg" ( _
   BYVAL pStorage AS IStorage _                         ' __in  IStorage* pStorage
 , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
 , BYREF ppPropSetStg AS IPropertySetStorage _          ' __out IPropertySetStorage** ppPropSetStg
 ) AS LONG                                              ' HRESULT

%CCH_MAX_PROPSTG_NAME    = 31

DECLARE FUNCTION FmtIdToPropStgName IMPORT "OLE32.DLL" ALIAS "FmtIdToPropStgName" ( _
   BYREF pfmtid AS GUID _                               ' __in const FMTID* pfmtid
 , BYREF oszName AS WSTRINGZ _                          ' __out LPOLESTR oszName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PropStgNameToFmtId IMPORT "OLE32.DLL" ALIAS "PropStgNameToFmtId" ( _
   BYREF oszName AS WSTRINGZ _                          ' __in const LPOLESTR oszName
 , BYREF pfmtid AS GUID _                               ' __out FMTID* pfmtid
 ) AS LONG                                              ' HRESULT

#IF NOT %DEF(%SERIALIZEDPROPERTYVALUE_DEFINED)
%SERIALIZEDPROPERTYVALUE_DEFINED = 1
' // Size = 8 bytes
TYPE SERIALIZEDPROPERTYVALUE DWORD
   dwType AS DWORD   ' DWORD
   rgb(0) AS BYTE    ' BYTE
END TYPE
#ENDIF

DECLARE FUNCTION StgConvertVariantToProperty IMPORT "OLE32.DLL" ALIAS "StgConvertVariantToProperty" ( _
   BYREF pvar AS ANY _                                  ' __in const PROPVARIANT* pvar
 , BYVAL CodePage AS WORD _                             ' __in USHORT CodePage
 , BYREF pprop AS ANY _                                 ' __out SERIALIZEDPROPERTYVALUE* pprop
 , BYREF pcb AS DWORD _                                 ' __inout ULONG* pcb
 , BYVAL pid AS DWORD _                                 ' __in PROPID pid
 , BYVAL fReserved AS BYTE _                            ' __reserved BOOLEAN fReserved
 , BYREF pcIndirect AS DWORD _                          ' __out_opt ULONG* pcIndirect
 ) AS DWORD                                             ' SERIALIZEDPROPERTYVALUE*

DECLARE FUNCTION StgConvertPropertyToVariant IMPORT "OLE32.DLL" ALIAS "StgConvertPropertyToVariant" ( _
   BYREF pprop AS ANY _                                 ' __in const SERIALIZEDPROPERTYVALUE* pprop
 , BYVAL CodePage AS WORD _                             ' __in USHORT CodePage
 , BYREF pvar AS ANY _                                  ' __out PROPVARIANT* pvar
 , BYVAL pma AS IUnknown _                              ' __in PMemoryAllocator* pma
 ) AS DWORD                                             ' SERIALIZEDPROPERTYVALUE*

#ENDIF   ' #IF NOT %DEF(%STGCREATEPROPSTG_DEFINED)
