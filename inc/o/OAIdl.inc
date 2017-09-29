' ########################################################################################
' Microsoft Windows
' File: OAIdl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OAIDL_INC = 1

#INCLUDE ONCE "wtypes.inc"

#IF NOT %DEF(%IOleAutomationTypes_INTERFACE_DEFINED)
    %IOleAutomationTypes_INTERFACE_DEFINED = 1

'typedef CY CURRENCY;

' // Size = 8 bytes
TYPE SAFEARRAYBOUND DWORD
   cElements AS DWORD   ' ULONG cElements
   lLbound   AS LONG    ' LONG lLbound
END TYPE

' SF_TYPE enum
%SF_ERROR    = %VT_ERROR
%SF_I1       = %VT_I1
%SF_I2       = %VT_I2
%SF_I4       = %VT_I4
%SF_I8       = %VT_I8
%SF_BSTR     = %VT_BSTR
%SF_UNKNOWN  = %VT_UNKNOWN
%SF_DISPATCH = %VT_DISPATCH
%SF_VARIANT  = %VT_VARIANT
%SF_RECORD   = %VT_RECORD
%SF_HAVEIID  = %VT_UNKNOWN OR %VT_RESERVED

' // Size = 24 bytes
TYPE SAFEARRAY DWORD FILL
   cDims        AS WORD             ' USHORT
   fFeatures    AS WORD             ' USHORT
   cbElements   AS DWORD            ' ULONG
   cLocks       AS DWORD            ' ULONG
   pvData       AS DWORD            ' PVOID
   rgsabound(0) AS SAFEARRAYBOUND   ' SAFEARRAYBOUND rgsabound[ 1 ]
END TYPE

%FADF_AUTO        = &H1???    ' An array that is allocated on the stack.
%FADF_STATIC      = &H2???    ' An array that is statically allocated.
%FADF_EMBEDDED    = &H4???    ' An array that is embedded in a structure.
%FADF_FIXEDSIZE   = &H10???   ' An array that may not be resized or reallocated.
%FADF_RECORD      = &H20???   ' An array containing records. When set there will be a pointer to the IRecordinfo interface at negative offset 4 in the array descriptor.
%FADF_HAVEIID     = &H40???   ' An array that has an IID identifying interface. When set there will be a guid at negative offset 16 in the safearray descriptor. Flag is set only when %FADF_DISPATCH or %FADF_UNKNOWN is also set.
%FADF_HAVEVARTYPE = &H80???   ' An array that has a VT type. When set there will be a VT tag at negative offset 4 in the array descriptor that specifies the element type.
%FADF_BSTR        = &H100???  ' An array of BSTRs.
%FADF_UNKNOWN     = &H200???  ' An array of IUnknown*.
%FADF_DISPATCH    = &H400???  ' An array of IDispatch*.
%FADF_VARIANT     = &H800???  ' An array of VARIANTs.
%FADF_RESERVED    = &HF008??? ' Bits reserved for future use.

'/* VARIANT STRUCTURE
' *
' *  VARTYPE vt;
' *  WORD wReserved1;
' *  WORD wReserved2;
' *  WORD wReserved3;
' *  union {
' *    LONGLONG       VT_I8
' *    LONG           VT_I4
' *    BYTE           VT_UI1
' *    SHORT          VT_I2
' *    FLOAT          VT_R4
' *    DOUBLE         VT_R8
' *    VARIANT_BOOL   VT_BOOL
' *    SCODE          VT_ERROR
' *    CY             VT_CY
' *    DATE           VT_DATE
' *    BSTR           VT_BSTR
' *    IUnknown *     VT_UNKNOWN
' *    IDispatch *    VT_DISPATCH
' *    SAFEARRAY *    VT_ARRAY
' *    BYTE *         VT_BYREF|VT_UI1
' *    SHORT *        VT_BYREF|VT_I2
' *    LONG *         VT_BYREF|VT_I4
' *    LONGLONG *     VT_BYREF|VT_I8
' *    FLOAT *        VT_BYREF|VT_R4
' *    DOUBLE *       VT_BYREF|VT_R8
' *    VARIANT_BOOL * VT_BYREF|VT_BOOL
' *    SCODE *        VT_BYREF|VT_ERROR
' *    CY *           VT_BYREF|VT_CY
' *    DATE *         VT_BYREF|VT_DATE
' *    BSTR *         VT_BYREF|VT_BSTR
' *    IUnknown **    VT_BYREF|VT_UNKNOWN
' *    IDispatch **   VT_BYREF|VT_DISPATCH
' *    SAFEARRAY **   VT_BYREF|VT_ARRAY
' *    VARIANT *      VT_BYREF|VT_VARIANT
' *    PVOID          VT_BYREF (Generic ByRef)
' *    CHAR           VT_I1
' *    USHORT         VT_UI2
' *    ULONG          VT_UI4
' *    ULONGLONG      VT_UI8
' *    INT            VT_INT
' *    UINT           VT_UINT
' *    DECIMAL *      VT_BYREF|VT_DECIMAL
' *    CHAR *         VT_BYREF|VT_I1
' *    USHORT *       VT_BYREF|VT_UI2
' *    ULONG *        VT_BYREF|VT_UI4
' *    ULONGLONG *    VT_BYREF|VT_UI8
' *    INT *          VT_BYREF|VT_INT
' *    UINT *         VT_BYREF|VT_UINT
' *  }
' */

'struct tagVARIANT
'    {
'    union
'        {
'        struct __tagVARIANT
'            {
'            VARTYPE vt;
'            WORD wReserved1;
'            WORD wReserved2;
'            WORD wReserved3;
'            union
'                {
'                LONGLONG llVal;
'                LONG lVal;
'                BYTE bVal;
'                SHORT iVal;
'                FLOAT fltVal;
'                DOUBLE dblVal;
'                VARIANT_BOOL boolVal;
'                _VARIANT_BOOL bool;
'                SCODE scode;
'                CY cyVal;
'                DATE date;
'                BSTR bstrVal;
'                IUnknown *punkVal;
'                IDispatch *pdispVal;
'                SAFEARRAY *parray;
'                BYTE *pbVal;
'                SHORT *piVal;
'                LONG *plVal;
'                LONGLONG *pllVal;
'                FLOAT *pfltVal;
'                DOUBLE *pdblVal;
'                VARIANT_BOOL *pboolVal;
'                _VARIANT_BOOL *pbool;
'                SCODE *pscode;
'                CY *pcyVal;
'                DATE *pdate;
'                BSTR *pbstrVal;
'                IUnknown **ppunkVal;
'                IDispatch **ppdispVal;
'                SAFEARRAY **pparray;
'                VARIANT *pvarVal;
'                PVOID byref;
'                CHAR cVal;
'                USHORT uiVal;
'                ULONG ulVal;
'                ULONGLONG ullVal;
'                INT intVal;
'                UINT uintVal;
'                DECIMAL *pdecVal;
'                CHAR *pcVal;
'                USHORT *puiVal;
'                ULONG *pulVal;
'                ULONGLONG *pullVal;
'                INT *pintVal;
'                UINT *puintVal;
'                struct __tagBRECORD
'                    {
'                    PVOID pvRecord;
'                    IRecordInfo *pRecInfo;
'                    }    __VARIANT_NAME_4;
'                }    __VARIANT_NAME_3;
'            }    __VARIANT_NAME_2;
'        DECIMAL decVal;
'        }    __VARIANT_NAME_1;
'    } ;

' // Size = 8 bytes
TYPE BRECORD DWORD
   pvRecord  AS DWORD
   pRecInfo  AS DWORD  ' IRecordInfo interface
END TYPE

' // Size = 8 bytes
UNION VARIANTDATA_UNION
   llVal                         AS QUAD            ' LONGLONG          // VT_I8
   lVal                          AS LONG            ' LONG              // VT_I4
   bVal                          AS BYTE            ' BYTE              // VT_UI1
   iVal                          AS INTEGER         ' SHORT             // VT_I2
   fltVal                        AS SINGLE          ' FLOAT             // VT_R4
   dblVal                        AS DOUBLE          ' DOUBLE            // VT_R8
   boolVal                       AS INTEGER         ' VARIANT_BOOL      // VT_BOOL
   bool                          AS INTEGER         ' _VARIANT_BOOL
   scode                         AS LONG            ' SCODE             // VT_ERROR
   cyVal                         AS CUR             ' CY                // VT_CY
   date                          AS DOUBLE          ' DATE              // VT_DATE
   bstrVal                       AS WSTRING PTR     ' BSTR              // VT_BSTR
   punkVal                       AS DWORD PTR       ' IUnknown*         // VT_UNKNOWN
   pdispVal                      AS DWORD PTR       ' IDispatch*        // VT_DISPATCH
   parray                        AS SAFEARRAY PTR   ' SAFEARRAY*        // VT_ARRAY
   pbVal                         AS BYTE PTR        ' BYTE*             // VT_BYREF|VT_UI1
   piVal                         AS INTEGER PTR     ' SHORT*            // VT_BYREF|VT_I2
   plVal                         AS LONG PTR        ' LONG*             // VT_BYREF|VT_I4
   pllVal                        AS QUAD PTR        ' LONGLONG*         // VT_BYREF|VT_I8
   pfltVal                       AS SINGLE PTR      ' FLOAT*            // VT_BYREF|VT_R4
   pdblVal                       AS DOUBLE PTR      ' DOUBLE*           // VT_BYREF|VT_R8
   pboolVal                      AS INTEGER PTR     ' VARIANT_BOOL*     // VT_BYREF|VT_BOOL
   pbool                         AS INTEGER PTR     ' _VARIANT_BOOL*
   pscode                        AS LONG PTR        ' SCODE*            // VT_BYREF|VT_ERROR
   pcyVal                        AS CUR PTR         ' CY*               // VT_BYREF|VT_CY
   pdate                         AS DOUBLE PTR      ' DATE*             // VT_BYREF|VT_DATE
   pbstrVal                      AS WSTRING PTR     ' BSTR*             // VT_BYREF|VT_BSTR
   ppunkVal                      AS DWORD PTR       ' IUnknown**        // VT_BYREF|VT_UNKNOWN
   ppdispVal                     AS DWORD PTR       ' IDispatch**       // VT_BYREF|VT_DISPATCH
   pparray                       AS SAFEARRAY PTR   ' SAFEARRAY**       // VT_BYREF|VT_ARRAY
   pvarVal                       AS VARIANT PTR     ' VARIANT*          // VT_BYREF|VT_VARIANT
   pByRef                        AS DWORD PTR       ' PVOID             // Generic BYREF (void*)
   cVal                          AS BYTE            ' CHAR              // VT_I1
   uiVal                         AS WORD            ' USHORT            // VT_UI2
   ulVal                         AS DWORD           ' ULONG             // VT_UI4
   intVal                        AS LONG            ' INT               // VT_INT
   uintVal                       AS DWORD           ' UINT              // VT_UINT
   pdecVal                       AS DECIMAL PTR     ' DECIMAL*          // VT_BYREF|VT_DECIMAL
   pcVal                         AS BYTE PTR        ' CHAR*             // VT_BYREF|VT_I1
   puiVal                        AS WORD PTR        ' USHORT*           // VT_BYREF|VT_UI2
   pulVal                        AS DWORD PTR       ' ULONG*            // VT_BYREF|VT_UI4
   pullVal                       AS QUAD PTR        ' ULONGLONG*        // VT_BYREF|VT_UI8
   pintVal                       AS LONG PTR        ' INT*              // VT_BYREF|VT_INT
   puintVal                      AS DWORD PTR       ' UINT*             // VT_BYREF|VT_UINT
   BRECORD                                          ' VT_RECORD
END UNION

' // Size = 16 bytes
TYPE tagVARIANT DWORD FILL
   vt         AS WORD  'VARTYPE
   wReserved1 AS WORD
   wReserved2 AS WORD
   wReserved3 AS WORD
   VARIANTDATA_UNION
END TYPE

' For backwards compatibility
' // Size = 16 bytes
TYPE VARIANTAPI DWORD FILL
   vt         AS WORD  'VARTYPE
   wReserved1 AS WORD
   wReserved2 AS WORD
   wReserved3 AS WORD
   vd         AS VARIANTDATA_UNION
END TYPE


'typedef LONG DISPID;
'typedef DISPID MEMBERID;
'typedef DWORD HREFTYPE;

' TYPEKIND enum
%TKIND_ENUM       = 0
%TKIND_RECORD     = %TKIND_ENUM + 1
%TKIND_MODULE     = %TKIND_RECORD + 1
%TKIND_INTERFACE  = %TKIND_MODULE + 1
%TKIND_DISPATCH   = %TKIND_INTERFACE + 1
%TKIND_COCLASS    = %TKIND_DISPATCH + 1
%TKIND_ALIAS      = %TKIND_COCLASS + 1
%TKIND_UNION      = %TKIND_ALIAS + 1
%TKIND_MAX        = %TKIND_UNION + 1

'typedef struct tagTYPEDESC
'    {
'    union
'        {
'        struct tagTYPEDESC *lptdesc;
'        struct tagARRAYDESC *lpadesc;
'        HREFTYPE hreftype;
'         /* Empty union arm */
'        }    DUMMYUNIONNAME;
'    VARTYPE vt;
'    }    TYPEDESC;

' // Size = 4 bytes
UNION TYPEDESCDATA DWORD
   lptdesc  AS DWORD    ' VT_PTR - the pointed-at type
   lpadesc  AS DWORD    ' VT_CARRAY
   hreftype AS DWORD    ' VT_USERDEFINED - this is used to get a TypeInfo for the UDT
END UNION

' // Size = 4 bytes
TYPE TYPEDESC DWORD     ' // Must be DWORD aligned
   TYPEDESCDATA
   vt AS WORD           ' VARTYPE
END TYPE

'typedef struct tagARRAYDESC
'    {
'    TYPEDESC tdescElem;
'    USHORT cDims;
'    /* [size_is] */ SAFEARRAYBOUND rgbounds[ 1 ];
'    }    ARRAYDESC;

' // Size = 20 bytes
TYPE ARRAYDESC DWORD               ' // Must be DWORD aligned
   tdescElem   AS TYPEDESC         ' Element type
   cDims       AS WORD             ' Dimension count
   rgbounds(0) AS SAFEARRAYBOUND   ' Variable length array containing one element for each dimension.
END TYPE

'typedef struct tagPARAMDESCEX
'    {
'    ULONG cBytes;
'    VARIANTARG varDefaultValue;
'    }    PARAMDESCEX;

'typedef struct tagPARAMDESCEX *LPPARAMDESCEX;

' // Size = 24 bytes
TYPE PARAMDESCEX   ' Must be 8 byte aligned
   cBytes          AS DWORD        ' size of this struct
   alignment__     AS DWORD        ' // To keep 8 byte alignment
   varDefaultValue AS tagVARIANT   ' default value of this parameter
END TYPE

'typedef struct tagPARAMDESC
'    {
'    LPPARAMDESCEX pparamdescex;
'    USHORT wParamFlags;
'    }    PARAMDESC;

'typedef struct tagPARAMDESC *LPPARAMDESC;

' // Size = 8 bytes
TYPE PARAMDESC DWORD                 ' // Must be DWORD aligned
   pparamdescex AS PARAMDESCEX PTR   ' valid if PARAMFLAG_FHASDEFAULT
   wParamFlags  AS WORD              ' IN, OUT, etc
END TYPE

%PARAMFLAG_NONE         = &H0??
%PARAMFLAG_FIN          = &H1??
%PARAMFLAG_FOUT         = &H2??
%PARAMFLAG_FLCID        = &H4??
%PARAMFLAG_FRETVAL      = &H8??
%PARAMFLAG_FOPT         = &H10??
%PARAMFLAG_FHASDEFAULT  = &H20??
%PARAMFLAG_FHASCUSTDATA = &H40??

'typedef struct tagIDLDESC
'    {
'    ULONG_PTR dwReserved;
'    USHORT wIDLFlags;
'    }    IDLDESC;

'typedef struct tagIDLDESC *LPIDLDESC;

' // Size = 8 bytes
TYPE IDLDESC DWORD       ' // Must be DWORD aligned
   dwReserved AS DWORD   ' Reserved; set to a null reference
   wIDLFlags  AS WORD    ' Indicates an IDLFLAG value describing the type
END TYPE

%IDLFLAG_NONE    = 0??   ' Whether the parameter passes or receives information is unspecified.
%IDLFLAG_FIN     = 1??   ' The parameter passes information from the caller to the callee.
%IDLFLAG_FOUT    = 2??   ' The parameter returns information from the callee to the caller.
%IDLFLAG_FLCID   = 4??   ' The parameter is the local identifier of a client application.
%IDLFLAG_FRETVAL = 8??   ' The parameter is the return value of the member.

'typedef struct tagELEMDESC {
'    TYPEDESC tdesc;             /* the type of the element */
'    union {
'        IDLDESC idldesc;        /* info for remoting the element */
'        PARAMDESC paramdesc;    /* info about the parameter */
'    } DUMMYUNIONNAME;
'} ELEMDESC, * LPELEMDESC;

' // Size = 8 bytes
UNION ELEMDESCUNION
   idldesc   AS IDLDESC     ' Info for remoting the element (backward compatibility)
   paramdesc AS PARAMDESC   ' info about the parameter
END UNION

' // Size = 16 bytes
TYPE ELEMDESC DWORD
   tdesc AS TYPEDESC         ' Type of the element
   ELEMDESCUNION
END TYPE

' // Size = 76 bytes
TYPE TYPEATTR DWORD FILL
   guid             AS GUID      ' The GUID of the type information
   lcid             AS DWORD     ' Locale of member names and doc strings
   dwReserved       AS DWORD
   memidConstructor AS LONG      ' ID of constructor, or MEMBERID_NIL if none
   memidDestructor  AS LONG      ' ID of destructor, or MEMBERID_NIL if none
   lpstrSchema      AS DWORD     ' Reserved for future use
   cbSizeInstance   AS DWORD     ' The size of an instance of this type
   typekind         AS DWORD     ' The kind of type this information describes
   cFuncs           AS WORD      ' Number of functions
   cVars            AS WORD      ' Number of variables/data members
   cImplTypes       AS WORD      ' Number of implemented interfaces
   cbSizeVft        AS WORD      ' The size of this type's VTBL
   cbAlignment      AS WORD      ' Byte alignment for an instance of this type
   wTypeFlags       AS WORD
   wMajorVerNum     AS WORD      ' Major version number
   wMinorVerNum     AS WORD      ' Minor version number
   tdescAlias       AS TYPEDESC  ' If TypeKind == TKIND_ALIAS, specifies the type for which this type is an alias.
   idldescType      AS IDLDESC   ' IDL attributes of the described type
END TYPE

'typedef struct tagDISPPARAMS
'    {
'    /* [size_is] */ VARIANTARG *rgvarg;
'    /* [size_is] */ DISPID *rgdispidNamedArgs;
'    UINT cArgs;
'    UINT cNamedArgs;
'    }    DISPPARAMS;

' PB internal definition
'TYPE DispParams
'   VariantArgs AS VARIANT PTR
'   NamedDispId AS LONG PTR
'   CountArgs   AS DWORD
'   CountNamed  AS DWORD
'END TYPE

' // Size = 16 bytes
TYPE tagDISPPARAMS DWORD
   rgvarg            AS tagVARIANT PTR   ' VARIANTARG *
   rgdispidNamedArgs AS LONG PTR         ' DISPID *
   cArgs             AS DWORD            ' UINT
   cNamedArgs        AS DWORD            ' UINT
END TYPE

'typedef struct tagEXCEPINFO
'    {
'    WORD wCode;
'    WORD wReserved;
'    BSTR bstrSource;
'    BSTR bstrDescription;
'    BSTR bstrHelpFile;
'    DWORD dwHelpContext;
'    ULONG_PTR pvReserved;
'    ULONG_PTR pfnDeferredFillIn;
'    SCODE scode;
'    }    EXCEPINFO;

' // Size = 32 bytes
TYPE EXCEPINFO DWORD FILL
   wCode             AS WORD         ' An error code describing the error.
   wReserved         AS WORD         ' Reserved
   bstrSource        AS WSTRING PTR  ' Source of the exception.
   bstrDescription   AS WSTRING PTR  ' Textual description of the error.
   bstrHelpFile      AS WSTRING PTR  ' Help file path.
   dwHelpContext     AS DWORD        ' Help context ID.
   pvReserved        AS DWORD        ' Reserved
   pfnDeferredFillIn AS DWORD        ' Pointer to function that fills in Help and description info.
   scode             AS LONG         ' An SCODE describing the error
END TYPE

' CALLCONV enum
%CC_FASTCALL   = 0
%CC_CDECL      = 1
%CC_MSCPASCAL  = %CC_CDECL + 1
%CC_PASCAL     = %CC_MSCPASCAL
%CC_MACPASCAL  = %CC_PASCAL + 1
%CC_STDCALL    = %CC_MACPASCAL + 1
%CC_FPFASTCALL = %CC_STDCALL + 1
%CC_SYSCALL    = %CC_FPFASTCALL + 1
%CC_MPWCDECL   = %CC_SYSCALL + 1
%CC_MPWPASCAL  = %CC_MPWCDECL + 1
%CC_MAX        = %CC_MPWPASCAL + 1

' FUNCKIND enum
%FUNC_VIRTUAL     = 0
%FUNC_PUREVIRTUAL = %FUNC_VIRTUAL + 1
%FUNC_NONVIRTUAL  = %FUNC_PUREVIRTUAL + 1
%FUNC_STATIC      = %FUNC_NONVIRTUAL + 1
%FUNC_DISPATCH    = %FUNC_STATIC + 1

' INVOKEKIND enum
%INVOKE_FUNC           = 1
%INVOKE_PROPERTYGET    = 2
%INVOKE_PROPERTYPUT    = 4
%INVOKE_PROPERTYPUTREF = 8

'typedef struct tagFUNCDESC
'    {
'    MEMBERID memid;
'    /* [size_is] */ SCODE *lprgscode;
'    /* [size_is] */ ELEMDESC *lprgelemdescParam;
'    FUNCKIND funckind;
'    INVOKEKIND invkind;
'    CALLCONV callconv;
'    SHORT cParams;
'    SHORT cParamsOpt;
'    SHORT oVft;
'    SHORT cScodes;
'    ELEMDESC elemdescFunc;
'    WORD wFuncFlags;
'    }    FUNCDESC;

' // Size = 52 bytes
TYPE FUNCDESC DWORD FILL
   memid             AS LONG           ' Function memberID
   lprgscode         AS LONG PTR       ' SCODE
   lprgelemdescParam AS ELEMDESC PTR   ' Pointer to an ELEMDESC structure
   funckind          AS DWORD          ' Specifies whether the function is virtual, static, or dispatch-only.
   invkind           AS DWORD          ' Invocation kind. Indicates if this is a property function, and if so, what kind.
   callconv          AS DWORD          ' Specifies the function's calling convention
   cParams           AS INTEGER        ' Count of total number of parameters
   cParamsOpt        AS INTEGER        ' Count of optional parameters
   oVft              AS INTEGER        ' For FUNC_VIRTUAL, specifies the offset in the VTBL
   cScodes           AS INTEGER        ' Count of permitted return values
   elemdescFunc      AS ELEMDESC       ' Contains the return type of the function
   wFuncFlags        AS WORD           ' Flags
   alignment__       AS WORD           ' // To keep DWORD alignment
END TYPE

' VARKIND enum
%VAR_PERINSTANCE = 0
%VAR_STATIC      = %VAR_PERINSTANCE + 1
%VAR_CONST       = %VAR_STATIC + 1
%VAR_DISPATCH    = %VAR_CONST + 1

%IMPLTYPEFLAG_FDEFAULT       = &H1??
%IMPLTYPEFLAG_FSOURCE        = &H2??
%IMPLTYPEFLAG_FRESTRICTED    = &H4??
%IMPLTYPEFLAG_FDEFAULTVTABLE = &H8??

'typedef struct tagVARDESC
'    {
'    MEMBERID memid;
'    LPOLESTR lpstrSchema;
'    union
'        {
'        ULONG oInst;
'        VARIANT *lpvarValue;
'        }    DUMMYUNIONNAME;
'    ELEMDESC elemdescVar;
'    WORD wVarFlags;
'    VARKIND varkind;
'    }    VARDESC;

' // Size = 4 bytes
UNION VARDESCDATA
   oInst      AS DWORD            ' VAR_PERINSTANCE, the offset of this variable within the instance.
   lpvarValue AS tagVARIANT PTR   ' VAR_CONST, the value of the constant.
END UNION

' // Size = 36 bytes
TYPE VARDESC DWORD                ' // Must be DWORD aligned
   memid       AS LONG            ' Variable memberID
   lpstrSchema AS WSTRINGZ PTR    ' Reserved for future use
   VARDESCDATA
   elemdescVar AS ELEMDESC        ' Contains the variable type
   wVarFlags   AS WORD            ' Flags
   varkind     AS DWORD           ' Kind of variable
END TYPE

' TYPEFLAGS enum
%TYPEFLAG_FAPPOBJECT        = &H1??
%TYPEFLAG_FCANCREATE        = &H2??
%TYPEFLAG_FLICENSED         = &H4??
%TYPEFLAG_FPREDECLID        = &H8??
%TYPEFLAG_FHIDDEN           = &H10??
%TYPEFLAG_FCONTROL          = &H20??
%TYPEFLAG_FDUAL             = &H40??
%TYPEFLAG_FNONEXTENSIBLE    = &H80??
%TYPEFLAG_FOLEAUTOMATION    = &H100??
%TYPEFLAG_FRESTRICTED       = &H200??
%TYPEFLAG_FAGGREGATABLE     = &H400??
%TYPEFLAG_FREPLACEABLE      = &H800??
%TYPEFLAG_FDISPATCHABLE     = &H1000??
%TYPEFLAG_FREVERSEBIND      = &H2000??
%TYPEFLAG_FPROXY            = &H4000??

' FUNCFLAGS enum
%FUNCFLAG_FRESTRICTED       = &H1??
%FUNCFLAG_FSOURCE           = &H2??
%FUNCFLAG_FBINDABLE         = &H4??
%FUNCFLAG_FREQUESTEDIT      = &H8??
%FUNCFLAG_FDISPLAYBIND      = &H10??
%FUNCFLAG_FDEFAULTBIND      = &H20??
%FUNCFLAG_FHIDDEN           = &H40??
%FUNCFLAG_FUSESGETLASTERROR = &H80??
%FUNCFLAG_FDEFAULTCOLLELEM  = &H100??
%FUNCFLAG_FUIDEFAULT        = &H200??
%FUNCFLAG_FNONBROWSABLE     = &H400??
%FUNCFLAG_FREPLACEABLE      = &H800??
%FUNCFLAG_FIMMEDIATEBIND    = &H1000??

' VARFLAGS enum
%VARFLAG_FREADONLY         = &H1??
%VARFLAG_FSOURCE           = &H2??
%VARFLAG_FBINDABLE         = &H4??
%VARFLAG_FREQUESTEDIT      = &H8??
%VARFLAG_FDISPLAYBIND      = &H10??
%VARFLAG_FDEFAULTBIND      = &H20??
%VARFLAG_FHIDDEN           = &H40??
%VARFLAG_FRESTRICTED       = &H80??
%VARFLAG_FDEFAULTCOLLELEM  = &H100??
%VARFLAG_FUIDEFAULT        = &H200??
%VARFLAG_FNONBROWSABLE     = &H400??
%VARFLAG_FREPLACEABLE      = &H800??
%VARFLAG_FIMMEDIATEBIND    = &H1000??

'typedef struct tagCUSTDATAITEM
'    {
'    GUID guid;
'    VARIANTARG varValue;
'    }    CUSTDATAITEM;

' // Size = 32 bytes
TYPE CUSTDATAITEM DWORD
   guid     AS GUID         ' Unique identifier for this data item.
   varValue AS tagVARIANT   ' Value of this data item.
END TYPE

'typedef struct tagCUSTDATA
'    {
'    DWORD cCustData;
'    /* [size_is] */ LPCUSTDATAITEM prgCustData;
'    }    CUSTDATA;

' // Size = 8 bytes
TYPE CUSTDATA DWORD
   cCustData   AS DWORD              ' Number of custom data items in prgCustData.
   prgCustData AS CUSTDATAITEM PTR   ' Array of custom data items.
END TYPE

#ENDIF   ' /* __IOleAutomationTypes_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateTypeInfo interface
' IID = 00020405-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateTypeInfo_INTERFACE_DEFINED)
    %ICreateTypeInfo_INTERFACE_DEFINED = 1

$IID_ICreateTypeInfo = GUID$("{00020405-0000-0000-C000-000000000046}")

INTERFACE ICreateTypeInfo $IID_ICreateTypeInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGuid ( _                                   ' VTable offset = 12
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeFlags ( _                              ' VTable offset = 16
     BYVAL uTypeFlags AS DWORD _                        ' __in UINT uTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocString ( _                              ' VTable offset = 20
     BYREF pStrDoc AS WSTRINGZ _                        ' __in LPOLESTR pStrDoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpContext ( _                            ' VTable offset = 24
     BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVersion ( _                                ' VTable offset = 28
     BYVAL wMajorVerNum AS WORD _                       ' __in WORD wMajorVerNum
   , BYVAL wMinorVerNum AS WORD _                       ' __in WORD wMinorVerNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRefTypeInfo ( _                            ' VTable offset = 32
     BYVAL pTInfo AS ITypeInfo _                        ' __in ITypeInfo *pTInfo
   , BYREF phRefType AS DWORD _                         ' __out HREFTYPE *phRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFuncDesc ( _                               ' VTable offset = 36
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pFuncDesc AS FUNCDESC _                      ' __in FUNCDESC *pFuncDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddImplType ( _                               ' VTable offset = 40
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL hRefType AS DWORD _                          ' __in HREFTYPE hRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImplTypeFlags ( _                          ' VTable offset = 44
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL implTypeFlags AS LONG _                      ' __in INT implTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAlignMent ( _                              ' VTable offset = 48
     BYVAL cbAlignment AS WORD _                        ' __in WORD cbAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSchema ( _                                 ' VTable offset = 52
     BYREF pStrSchema AS WSTRINGZ _                     ' __in LPOLESTR pStrSchema
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddVarDesc ( _                                ' VTable offset = 56
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pVarDesc AS VARDESC _                        ' __in VARDESC *pVarDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncAndParamNames ( _                      ' VTable offset = 60
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF rgszNames AS WSTRING _                       ' __in LPOLESTR *rgszNames [array]
   , BYVAL cNames AS DWORD _                            ' __in UINT cNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarName ( _                                ' VTable offset = 64
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeDescAlias ( _                          ' VTable offset = 68
     BYREF pTDescAlias AS TYPEDESC _                    ' __in TYPEDESC *pTDescAlias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefineFuncAsDLLEntry ( _                      ' VTable offset = 72
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDllName AS WSTRINGZ _                      ' __in LPOLESTR szDllName
   , BYREF szProcName AS WSTRINGZ _                     ' __in LPOLESTR szProcName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncDocString ( _                          ' VTable offset = 76
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDocString AS WSTRINGZ _                    ' __in LPOLESTR szDocString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarDocString ( _                           ' VTable offset = 80
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDocString AS WSTRINGZ _                    ' __in LPOLESTR szDocString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncHelpContext ( _                        ' VTable offset = 84
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarHelpContext ( _                         ' VTable offset = 88
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMops ( _                                   ' VTable offset = 92
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL bstrMops AS DWORD _                          ' __in BSTR bstrMops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeIdldesc ( _                            ' VTable offset = 96
     BYREF pIdlDesc AS IDLDESC _                        ' __in IDLDESC *pIdlDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LayOut ( _                                    ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateTypeInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateTypeInfo2 interface
' IID = 0002040E-0000-0000-C000-000000000046
' Inherited interface = ICreateTypeInfo
' ########################################################################################

#IF NOT %DEF(%ICreateTypeInfo2_INTERFACE_DEFINED)
    %ICreateTypeInfo2_INTERFACE_DEFINED = 1

$IID_ICreateTypeInfo2 = GUID$("{0002040E-0000-0000-C000-000000000046}")

INTERFACE ICreateTypeInfo2 $IID_ICreateTypeInfo2

   INHERIT IUnknown

   ' =====================================================================================
   ' ICreateTypeInfo Methods
   ' =====================================================================================
   METHOD SetGuid ( _                                   ' VTable offset = 12
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeFlags ( _                              ' VTable offset = 16
     BYVAL uTypeFlags AS DWORD _                        ' __in UINT uTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocString ( _                              ' VTable offset = 20
     BYREF pStrDoc AS WSTRINGZ _                        ' __in LPOLESTR pStrDoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpContext ( _                            ' VTable offset = 24
     BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVersion ( _                                ' VTable offset = 28
     BYVAL wMajorVerNum AS WORD _                       ' __in WORD wMajorVerNum
   , BYVAL wMinorVerNum AS WORD _                       ' __in WORD wMinorVerNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRefTypeInfo ( _                            ' VTable offset = 32
     BYVAL pTInfo AS ITypeInfo _                        ' __in ITypeInfo *pTInfo
   , BYREF phRefType AS DWORD _                         ' __out HREFTYPE *phRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFuncDesc ( _                               ' VTable offset = 36
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pFuncDesc AS FUNCDESC _                      ' __in FUNCDESC *pFuncDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddImplType ( _                               ' VTable offset = 40
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL hRefType AS DWORD _                          ' __in HREFTYPE hRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImplTypeFlags ( _                          ' VTable offset = 44
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL implTypeFlags AS LONG _                      ' __in INT implTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAlignMent ( _                              ' VTable offset = 48
     BYVAL cbAlignment AS WORD _                        ' __in WORD cbAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSchema ( _                                 ' VTable offset = 52
     BYREF pStrSchema AS WSTRINGZ _                     ' __in LPOLESTR pStrSchema
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddVarDesc ( _                                ' VTable offset = 56
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pVarDesc AS VARDESC _                        ' __in VARDESC *pVarDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncAndParamNames ( _                      ' VTable offset = 60
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF rgszNames AS WSTRING _                       ' __in LPOLESTR *rgszNames [array]
   , BYVAL cNames AS DWORD _                            ' __in UINT cNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarName ( _                                ' VTable offset = 64
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeDescAlias ( _                          ' VTable offset = 68
     BYREF pTDescAlias AS TYPEDESC _                    ' __in TYPEDESC *pTDescAlias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefineFuncAsDLLEntry ( _                      ' VTable offset = 72
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDllName AS WSTRINGZ _                      ' __in LPOLESTR szDllName
   , BYREF szProcName AS WSTRINGZ _                     ' __in LPOLESTR szProcName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncDocString ( _                          ' VTable offset = 76
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDocString AS WSTRINGZ _                    ' __in LPOLESTR szDocString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarDocString ( _                           ' VTable offset = 80
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF szDocString AS WSTRINGZ _                    ' __in LPOLESTR szDocString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncHelpContext ( _                        ' VTable offset = 84
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarHelpContext ( _                         ' VTable offset = 88
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMops ( _                                   ' VTable offset = 92
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL bstrMops AS DWORD _                          ' __in BSTR bstrMops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypeIdldesc ( _                            ' VTable offset = 96
     BYREF pIdlDesc AS IDLDESC _                        ' __in IDLDESC *pIdlDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LayOut ( _                                    ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICreateTypeInfo2 Methods
   ' =====================================================================================
   METHOD DeleteFuncDesc ( _                            ' VTable offset = 104
     BYVAL index AS DWORD _                             ' __in UINT index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteFuncDescByMemId ( _                     ' VTable offset = 108
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS DWORD _                           ' __in INVOKEKIND invKind
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteVarDesc ( _                             ' VTable offset = 112
     BYVAL index AS DWORD _                             ' __in UINT index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteVarDescByMemId ( _                      ' VTable offset = 116
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteImplType ( _                            ' VTable offset = 120
     BYVAL index AS DWORD _                             ' __in UINT index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCustData ( _                               ' VTable offset = 124
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncCustData ( _                           ' VTable offset = 128
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParamCustData ( _                          ' VTable offset = 132
     BYVAL indexFunc AS DWORD _                         ' __in UINT indexFunc
   , BYVAL indexParam AS DWORD _                        ' __in UINT indexParam
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarCustData ( _                            ' VTable offset = 136
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImplTypeCustData ( _                       ' VTable offset = 140
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpStringContext ( _                      ' VTable offset = 144
     BYVAL dwHelpStringContext AS DWORD _               ' __in ULONG dwHelpStringContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFuncHelpStringContext ( _                  ' VTable offset = 148
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpStringContext AS DWORD _               ' __in ULONG dwHelpStringContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVarHelpStringContext ( _                   ' VTable offset = 152
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL dwHelpStringContext AS DWORD _               ' __in ULONG dwHelpStringContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invalidate ( _                                ' VTable offset = 156
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 160
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateTypeInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateTypeLib interface
' IID = 00020406-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateTypeLib_INTERFACE_DEFINED)
    %ICreateTypeLib_INTERFACE_DEFINED = 1

$IID_ICreateTypeLib = GUID$("{00020406-0000-0000-C000-000000000046}")

INTERFACE ICreateTypeLib $IID_ICreateTypeLib

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTypeInfo ( _                            ' VTable offset = 12
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   , BYVAL tkind AS DWORD _                             ' __in TYPEKIND tkind
   , BYREF ppCTInfo AS ICreateTypeInfo _                ' __out ICreateTypeInfo **ppCTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 16
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVersion ( _                                ' VTable offset = 20
     BYVAL wMajorVerNum AS WORD _                       ' __in WORD wMajorVerNum
   , BYVAL wMinorVerNum AS WORD _                       ' __in WORD wMinorVerNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGuid ( _                                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocString ( _                              ' VTable offset = 28
     BYREF szDoc AS WSTRINGZ _                          ' __in LPOLESTR szDoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpFileName ( _                           ' VTable offset = 32
     BYREF szHelpFileName AS WSTRINGZ _                 ' __in LPOLESTR szHelpFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpContext ( _                            ' VTable offset = 36
     BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLCID ( _                                   ' VTable offset = 40
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLibFlags ( _                               ' VTable offset = 44
     BYVAL uLibFlags AS DWORD _                         ' __in UINT uLibFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAllChanges ( _                            ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateTypeLib_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateTypeLib2 interface
' IID = 0002040F-0000-0000-C000-000000000046
' Inherited interface = ICreateTypeLib
' ########################################################################################

#IF NOT %DEF(%ICreateTypeLib2_INTERFACE_DEFINED)
    %ICreateTypeLib2_INTERFACE_DEFINED = 1

$IID_ICreateTypeLib2 = GUID$("{0002040F-0000-0000-C000-000000000046}")

INTERFACE ICreateTypeLib2 $IID_ICreateTypeLib2

   INHERIT IUnknown

   ' =====================================================================================
   ' ICreateTypeLib Methods
   ' =====================================================================================
   METHOD CreateTypeInfo ( _                            ' VTable offset = 12
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   , BYVAL tkind AS DWORD _                             ' __in TYPEKIND tkind
   , BYREF ppCTInfo AS ICreateTypeInfo _                ' __out ICreateTypeInfo **ppCTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetName ( _                                   ' VTable offset = 16
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVersion ( _                                ' VTable offset = 20
     BYVAL wMajorVerNum AS WORD _                       ' __in WORD wMajorVerNum
   , BYVAL wMinorVerNum AS WORD _                       ' __in WORD wMinorVerNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGuid ( _                                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDocString ( _                              ' VTable offset = 28
     BYREF szDoc AS WSTRINGZ _                          ' __in LPOLESTR szDoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpFileName ( _                           ' VTable offset = 32
     BYREF szHelpFileName AS WSTRINGZ _                 ' __in LPOLESTR szHelpFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpContext ( _                            ' VTable offset = 36
     BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLCID ( _                                   ' VTable offset = 40
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLibFlags ( _                               ' VTable offset = 44
     BYVAL uLibFlags AS DWORD _                         ' __in UINT uLibFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAllChanges ( _                            ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICreateTypeLib Methods
   ' =====================================================================================
   METHOD DeleteTypeInfo ( _                            ' VTable offset = 52
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCustData ( _                               ' VTable offset = 56
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYVAL pVarVal AS VARIANT _                         ' __in VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpStringContext ( _                      ' VTable offset = 60
     BYVAL dwHelpStringContext AS DWORD _               ' __in ULONG dwHelpStringContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpStringDll ( _                          ' VTable offset = 64
     BYREF szFileName AS WSTRINGZ _                     ' __in LPOLESTR szFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateTypeLib2_INTERFACE_DEFINED__ */


' ########################################################################################
' IDispatch interface
' IID = 00020400-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' NOTE: Renamed because of conflicts with the built-in PB definition.
' ########################################################################################

#IF NOT %DEF(%IDispatch_INTERFACE_DEFINED)
    %IDispatch_INTERFACE_DEFINED = 1

$IID_IDispatch = GUID$("{00020400-0000-0000-C000-000000000046}")

'/* DISPID reserved to indicate an "unknown" name */
'/* only reserved for data members (properties); reused as a method dispid below */
%DISPID_UNKNOWN                           = -1

'/* DISPID reserved for the "value" property */
%DISPID_VALUE                             = 0

'/* The following DISPID is reserved to indicate the param
' * that is the right-hand-side (or "put" value) of a PropertyPut
' */
%DISPID_PROPERTYPUT                       = -3

'/* DISPID reserved for the standard "NewEnum" method */
%DISPID_NEWENUM                           = -4

'/* DISPID reserved for the standard "Evaluate" method */
%DISPID_EVALUATE                          = -5

%DISPID_CONSTRUCTOR                       = -6

%DISPID_DESTRUCTOR                        = -7

%DISPID_COLLECT                           = -8

'/* The range -500 through -999 is reserved for Controls */
'/* The range 0x80010000 through 0x8001FFFF is reserved for Controls */
'/* The range -5000 through -5499 is reserved for ActiveX Accessability */
'/* The range -2000 through -2499 is reserved for VB5 */
'/* The range -3900 through -3999 is reserved for Forms */
'/* The range -5500 through -5550 is reserved for Forms */
'/* The remainder of the negative DISPIDs are reserved for future use */

INTERFACE COM_IDispatch $IID_IDispatch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTypeInfoCount ( _                          ' VTable offset = 12
     BYREF pctinfo AS DWORD _                           ' __out unsigned int *pctinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfo ( _                               ' VTable offset = 16
     BYVAL iTInfo AS DWORD _                            ' __in unsigned int iTInfo
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsOfNames ( _                             ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgszNames AS WSTRING _                       ' __in OLECHAR **rgszNames
   , BYVAL cNames AS DWORD _                            ' __in unsigned int cNames
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF rgDispId AS LONG _                           ' __out DISPID *rgDispId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 24
     BYVAL dispIdMember AS LONG _                       ' __in DISPID dispIdMember
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pDispParams AS DISPPARAMS _                  ' __in DISPPARAMS *pDispParams
   , BYREF pVarResult AS VARIANT _                      ' __out VARIANT *pVarResult
   , BYREF pExcepInfo AS EXCEPINFO _                    ' __out EXCEPINFO *pExcepInfo
   , BYREF puArgErr AS DWORD _                          ' __out unsigned int *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDispatch_INTERFACE_DEFINED__ */

' *** As built into the PowerBASIC compiler ***
' Note: GetIDsOfNames still uses AS STRING, instead of AS WSTRING, for the rgszNames parameter.
' Therefore, you must use a variable declared AS STRING and convert it to unicode with UCODE$.

'INTERFACE IDispatch $IID_IDispatch

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetTypeInfoCount ( _                          ' VTable offset = 12
'     BYREF pctinfo AS DWORD _                           ' __out unsigned int *pctinfo
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetTypeInfo ( _                               ' VTable offset = 16
'     BYVAL iTInfo AS DWORD _                            ' __in unsigned int iTInfo
'   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
'   , BYREF ppTInfo AS DWORD _                           ' __out ITypeInfo **ppTInfo
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetIDsOfNames ( _                             ' VTable offset = 20
'     BYREF riid AS GUID _                               ' __in REFIID riid
'   , BYREF rgszNames AS STRING _                        ' __in OLECHAR **rgszNames
'   , BYVAL cNames AS DWORD _                            ' __in unsigned int cNames
'   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
'   , BYREF rgDispId AS LONG _                           ' __out DISPID *rgDispId
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Invoke ( _                                    ' VTable offset = 24
'     BYVAL dispIdMember AS LONG _                       ' __in DISPID dispIdMember
'   , BYREF riid AS GUID _                               ' __in REFIID riid
'   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
'   , BYVAL wFlags AS DWORD _                            ' __in WORD wFlags
'   , BYREF pDispParams AS DISPPARAMS _                  ' __in DISPPARAMS *pDispParams
'   , BYREF pVarResult AS VARIANT _                      ' __out VARIANT *pVarResult
'   , BYVAL pExcepInfo AS DWORD _                        ' __out EXCEPINFO *pExcepInfo
'   , BYREF puArgErr AS DWORD _                          ' __out unsigned int *puArgErr
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IEnumVARIANT interface
' IID = 00000002-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumVARIANT_INTERFACE_DEFINED)
    %IEnumVARIANT_INTERFACE_DEFINED = 1

$IID_IEnumVARIANT = GUID$("{00020404-0000-0000-C000-000000000046}")

INTERFACE IEnumVARIANT $IID_IEnumVARIANT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF rgVar AS VARIANT _                           ' __out VARIANT *rgVar
   , BYREF pCeltFetched AS DWORD _                      ' __out unsigned long *pCeltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumVARIANT _                     ' __out IEnumVARIANT** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumVARIANT_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeComp interface
' IID = 00020403-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeComp_INTERFACE_DEFINED)
    %ITypeComp_INTERFACE_DEFINED = 1

' DESCKIND enum
%DESCKIND_NONE           = 0
%DESCKIND_FUNCDESC       = %DESCKIND_NONE + 1
%DESCKIND_VARDESC        = %DESCKIND_FUNCDESC + 1
%DESCKIND_TYPECOMP       = %DESCKIND_VARDESC + 1
%DESCKIND_IMPLICITAPPOBJ = %DESCKIND_TYPECOMP + 1
%DESCKIND_MAX            = %DESCKIND_IMPLICITAPPOBJ + 1

UNION BINDPTR
   lpfuncdesc AS FUNCDESC PTR   ' FUNCDESC FAR*
   lpvardesc  AS VARDESC PTR    ' VARDESC FAR*
   lptcomp    AS DWORD PTR      ' ITypeComp FAR*
END UNION

$IID_ITypeComp = GUID$("{00020403-0000-0000-C000-000000000046}")

INTERFACE ITypeComp $IID_ITypeComp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Bind ( _                                      ' VTable offset = 12
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   , BYREF pDescKindgs AS DWORD _                       ' __out DESCKIND *pDescKindgs
   , BYVAL pBindPtr AS BINDPTR PTR _                    ' __out BINDPTR *pBindPtr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindType ( _                                  ' VTable offset = 16
     BYREF szName AS WSTRINGZ _                         ' __in LPOLESTR szName
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   , BYREF ppTComp AS ITypeComp _                       ' __out ITypeComp **ppTComp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeComp_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeInfo interface
' IID = 00020401-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeInfo_INTERFACE_DEFINED)
    %ITypeInfo_INTERFACE_DEFINED = 1

$IID_ITypeInfo = GUID$("{00020401-0000-0000-C000-000000000046}")

INTERFACE ITypeInfo $IID_ITypeInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTypeAttr ( _                               ' VTable offset = 12
     BYREF ppTypeAttr AS DWORD _                        ' __out TYPEATTR **ppTypeAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeComp ( _                               ' VTable offset = 16
     BYREF ppTComp AS ITypeComp _                       ' __out ITypeComp **ppTComp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFuncDesc ( _                               ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppFuncDesc AS DWORD _                        ' __out FUNCDESC **ppFuncDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVarDesc ( _                                ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppVarDesc AS DWORD _                         ' __out VARDESC **ppVarDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 28
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF rgBstrNames AS WSTRING _                     ' __out BSTR *rgBstrNames
   , BYVAL cMaxNames AS DWORD _                         ' __in UINT cMaxNames
   , BYREF pcNames AS DWORD _                           ' __out UINT *pcNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRefTypeOfImplType ( _                      ' VTable offset = 32
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pRefType AS DWORD _                          ' __out HREFTYPE *pRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImplTypeFlags ( _                          ' VTable offset = 36
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pImplTypeFlags AS LONG _                     ' __out INT *pImplTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsOfNames ( _                             ' VTable offset = 40
     BYREF rgszNames AS WSTRING _                       ' __in LPOLESTR *rgszNames [array]
   , BYVAL cNames AS DWORD _                            ' __in UINT cNames
   , BYREF pMemId AS LONG _                             ' __out MEMBERID *pMemId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 44
     BYVAL pvInstance AS DWORD _                        ' __in PVOID pvInstance
   , BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pDispParams AS DISPPARAMS _                  ' __in_out DISPPARAMS *pDispParams
   , BYREF pVarResult AS VARIANT _                      ' __out VARIANT *pVarResult
   , BYREF pExcepInfo AS EXCEPINFO _                    ' __out EXCEPINFO *pExcepInfo
   , BYREF puArgErr AS DWORD _                          ' __out UINT *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation ( _                          ' VTable offset = 48
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pBstrDocString AS WSTRING _                  ' __out BSTR *pBstrDocString
   , BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   , BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDllEntry ( _                               ' VTable offset = 52
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS LONG _                            ' __in INVOKEKIND invKind
   , BYREF pBstrDllName AS WSTRING _                    ' __out BSTR *pBstrDllName
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pwOrdinal AS WORD _                          ' __out WORD *pwOrdinal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRefTypeInfo ( _                            ' VTable offset = 56
     BYVAL hRefType AS DWORD _                          ' __in HREFTYPE hRefType
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddressOfMember ( _                           ' VTable offset = 60
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS LONG _                            ' __in INVOKEKIND invKind
   , BYREF ppv AS DWORD _                               ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance( _                             ' VTable offset = 64
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out PVOID *ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMops ( _                                   ' VTable offset = 68
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF pBstrMops AS WSTRING _                       ' __out BSTR *pBstrMops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainingTypeLib ( _                      ' VTable offset = 72
     BYREF ppTLib AS ITypeLib _                         ' __out ITypeLib **ppTLib
   , BYREF pIndex AS DWORD _                            ' __out UINT *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseTypeAttr ( _                           ' VTable offset = 76
     BYVAL pTypeAttr AS TYPEATTR PTR _                  ' __in TYPEATTR *pTypeAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseFuncDesc ( _                           ' VTable offset = 80
     BYVAL pFuncDesc AS FUNCDESC PTR _                  ' __in FUNCDESC *pFuncDesc
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseVarDesc ( _                            ' VTable offset = 84
     BYVAL pVarDesc AS VARDESC PTR _                    ' __in VARDESC *pVarDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeInfo2 interface
' IID = 00020412-0000-0000-C000-000000000046
' Inherited interface = ITypeInfo
' ########################################################################################

#IF NOT %DEF(%ITypeInfo2_INTERFACE_DEFINED)
    %ITypeInfo2_INTERFACE_DEFINED = 1

$IID_ITypeInfo2 = GUID$("{00020412-0000-0000-C000-000000000046}")

INTERFACE ITypeInfo2 $IID_ITypeInfo2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITypeInfo Methods
   ' =====================================================================================
   METHOD GetTypeAttr ( _                               ' VTable offset = 12
     BYREF ppTypeAttr AS DWORD _                        ' __out TYPEATTR **ppTypeAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeComp ( _                               ' VTable offset = 16
     BYREF ppTComp AS ITypeComp _                       ' __out ITypeComp **ppTComp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFuncDesc ( _                               ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppFuncDesc AS DWORD _                        ' __out FUNCDESC **ppFuncDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVarDesc ( _                                ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppVarDesc AS DWORD _                         ' __out VARDESC **ppVarDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNames ( _                                  ' VTable offset = 28
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF rgBstrNames AS WSTRING _                     ' __out BSTR *rgBstrNames
   , BYVAL cMaxNames AS DWORD _                         ' __in UINT cMaxNames
   , BYREF pcNames AS DWORD _                           ' __out UINT *pcNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRefTypeOfImplType ( _                      ' VTable offset = 32
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pRefType AS DWORD _                          ' __out HREFTYPE *pRefType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImplTypeFlags ( _                          ' VTable offset = 36
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pImplTypeFlags AS LONG _                     ' __out INT *pImplTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDsOfNames ( _                             ' VTable offset = 40
     BYREF rgszNames AS WSTRING _                       ' __in LPOLESTR *rgszNames [array]
   , BYVAL cNames AS DWORD _                            ' __in UINT cNames
   , BYREF pMemId AS LONG _                             ' __out MEMBERID *pMemId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 44
     BYVAL pvInstance AS DWORD _                        ' __in PVOID pvInstance
   , BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL wFlags AS WORD _                             ' __in WORD wFlags
   , BYREF pDispParams AS DISPPARAMS _                  ' __in_out DISPPARAMS *pDispParams
   , BYREF pVarResult AS VARIANT _                      ' __out VARIANT *pVarResult
   , BYREF pExcepInfo AS EXCEPINFO _                    ' __out EXCEPINFO *pExcepInfo
   , BYREF puArgErr AS DWORD _                          ' __out UINT *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation ( _                          ' VTable offset = 48
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pBstrDocString AS WSTRING _                  ' __out BSTR *pBstrDocString
   , BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   , BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDllEntry ( _                               ' VTable offset = 52
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS LONG _                            ' __in INVOKEKIND invKind
   , BYREF pBstrDllName AS WSTRING _                    ' __out BSTR *pBstrDllName
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pwOrdinal AS WORD _                          ' __out WORD *pwOrdinal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRefTypeInfo ( _                            ' VTable offset = 56
     BYVAL hRefType AS DWORD _                          ' __in HREFTYPE hRefType
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddressOfMember ( _                           ' VTable offset = 60
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS LONG _                            ' __in INVOKEKIND invKind
   , BYREF ppv AS DWORD _                               ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance( _                             ' VTable offset = 64
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out PVOID *ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMops ( _                                   ' VTable offset = 68
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYREF pBstrMops AS WSTRING _                       ' __out BSTR *pBstrMops
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainingTypeLib ( _                      ' VTable offset = 72
     BYREF ppTLib AS ITypeLib _                         ' __out ITypeLib **ppTLib
   , BYREF pIndex AS DWORD _                            ' __out UINT *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseTypeAttr ( _                           ' VTable offset = 76
     BYVAL pTypeAttr AS TYPEATTR PTR _                  ' __in TYPEATTR *pTypeAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseFuncDesc ( _                           ' VTable offset = 80
     BYVAL pFuncDesc AS FUNCDESC PTR _                  ' __in FUNCDESC *pFuncDesc
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseVarDesc ( _                            ' VTable offset = 84
     BYVAL pVarDesc AS VARDESC PTR _                    ' __in VARDESC *pVarDesc
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITypeInfo2 Methods
   ' =====================================================================================
   METHOD GetTypeKind ( _                               ' VTable offset = 88
     BYREF pTypeKind AS DWORD _                         ' __out TYPEKIND *pTypeKind
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 92
     BYREF pTypeFlags AS DWORD _                        ' __out ULONG *pTypeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFuncIndexOfMemId ( _                       ' VTable offset = 96
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL invKind AS DWORD _                           ' __in INVOKEKIND invKind
   , BYVAL pFuncIndex AS DWORD _                        ' __out UINT *pFuncIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVarIndexOfMemId ( _                        ' VTable offset = 100
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL pVarIndex AS DWORD _                         ' __out UINT *pVarIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustData ( _                               ' VTable offset = 104
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFuncCustData ( _                           ' VTable offset = 108
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParamCustData ( _                          ' VTable offset = 112
     BYVAL indexFunc AS DWORD _                         ' __in UINT indexFunc
   , BYVAL indexParam AS DWORD _                        ' __in UINT indexParam
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVarCustData ( _                            ' VTable offset = 116
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImplTypeCustData ( _                       ' VTable offset = 120
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation2 ( _                         ' VTable offset = 124
     BYVAL memid AS LONG _                              ' __in MEMBERID memid
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pbstrHelpString AS WSTRING _                 ' __out BSTR *pbstrHelpString
   , BYREF pdwHelpStringContext AS DWORD _              ' __out DWORD *pdwHelpStringContext
   , BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllCustData ( _                            ' VTable offset = 128
     BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllFuncCustData ( _                        ' VTable offset = 132
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParamCustData ( _                       ' VTable offset = 136
     BYVAL indexFunc AS DWORD _                         ' __in UINT indexFunc
   , BYVAL indexParam AS DWORD _                        ' __in UINT indexParam
   , BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllVarCustData ( _                         ' VTable offset = 140
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllImplTypeCustData ( _                    ' VTable offset = 144
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeLib interface
' IID = 00020402-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeLib_INTERFACE_DEFINED)
    %ITypeLib_INTERFACE_DEFINED = 1

' SYSKIND enum
%SYS_WIN16 = 0
%SYS_WIN32 = 1
%SYS_MAC   = 2
%SYS_WIN64 = 3

' LIBFLAGS enum
%LIBFLAG_FRESTRICTED   = &H01??
%LIBFLAG_FCONTROL      = &H02??
%LIBFLAG_FHIDDEN       = &H04??
%LIBFLAG_FHASDISKIMAGE = &H08??

' // Size = 32 bytes
TYPE TLIBATTR
   guid         AS GUID     ' GUID
   lcid         AS DWORD    ' LCID
   syskind      AS LONG     ' SYSKIND
   wMajorVerNum AS WORD     ' WORD
   wMinorVerNum AS WORD     ' WORD
   wLibFlags    AS WORD     ' WORD
   alignment__  AS WORD     ' // To keep DWORD alignment
END TYPE

$IID_ITypeLib = GUID$("{00020402-0000-0000-C000-000000000046}")

INTERFACE ITypeLib $IID_ITypeLib

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTypeInfoCount ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetTypeInfo ( _                               ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfoType ( _                           ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pTKind AS DWORD _                            ' __out TYPEKIND *pTKind
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfoOfGuid ( _                         ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF ppTinfo AS ITypeInfo _                       ' __out ITypeInfo **ppTinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLibAttr ( _                                ' VTable offset = 28
     BYREF ppTLibAttr AS DWORD _                        ' __out TLIBATTR **ppTLibAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeComp ( _                               ' VTable offset = 32
     BYREF ppTComp AS ITypeComp _                       ' __out ITypeComp **ppTComp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation ( _                          ' VTable offset = 36
     BYVAL index AS LONG _                              ' __in INT index
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pBstrDocString AS WSTRING _                  ' __out BSTR *pBstrDocString
   , BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   , BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsName ( _                                    ' VTable offset = 40
     BYREF szNameBuf AS WSTRINGZ _                      ' __in_out LPOLESTR szNameBuf
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYREF pfName AS LONG _                             ' __out BOOL *pfName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindName ( _                                  ' VTable offset = 44
     BYREF szNameBuf AS WSTRINGZ _                      ' __in_out LPOLESTR szNameBuf
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   , BYREF rgMemId AS LONG _                            ' __out MEMBERID *rgMemId
   , BYREF pcFound AS DWORD _                           ' __in_out USHORT *pcFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseTLibAttr ( _                           ' VTable offset = 48
     BYVAL pTLibAttr AS DWORD _                         ' __in TLIBATTR *pTLibAttr
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeLib_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeLib2 interface
' IID = 00020411-0000-0000-C000-000000000046
' Inherited interface = ITypeLib
' ########################################################################################

#IF NOT %DEF(%ITypeLib2_INTERFACE_DEFINED)
    %ITypeLib2_INTERFACE_DEFINED = 1

$IID_ITypeLib2 = GUID$("{00020411-0000-0000-C000-000000000046}")

INTERFACE ITypeLib2 $IID_ITypeLib2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITypeLib Methods
   ' =====================================================================================
   METHOD GetTypeInfoCount ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetTypeInfo ( _                               ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfoType ( _                           ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pTKind AS DWORD _                            ' __out TYPEKIND *pTKind
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfoOfGuid ( _                         ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF ppTinfo AS ITypeInfo _                       ' __out ITypeInfo **ppTinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLibAttr ( _                                ' VTable offset = 28
     BYREF ppTLibAttr AS DWORD _                        ' __out TLIBATTR **ppTLibAttr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeComp ( _                               ' VTable offset = 32
     BYREF ppTComp AS ITypeComp _                       ' __out ITypeComp **ppTComp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation ( _                          ' VTable offset = 36
     BYVAL index AS LONG _                              ' __in INT index
   , BYREF pBstrName AS WSTRING _                       ' __out BSTR *pBstrName
   , BYREF pBstrDocString AS WSTRING _                  ' __out BSTR *pBstrDocString
   , BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   , BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsName ( _                                    ' VTable offset = 40
     BYREF szNameBuf AS WSTRINGZ _                      ' __in_out LPOLESTR szNameBuf
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYREF pfName AS LONG _                             ' __out BOOL *pfName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindName ( _                                  ' VTable offset = 44
     BYREF szNameBuf AS WSTRINGZ _                      ' __in_out LPOLESTR szNameBuf
   , BYVAL lHashVal AS DWORD _                          ' __in ULONG lHashVal
   , BYREF ppTInfo AS ITypeInfo _                       ' __out ITypeInfo **ppTInfo
   , BYREF rgMemId AS LONG _                            ' __out MEMBERID *rgMemId
   , BYREF pcFound AS DWORD _                           ' __in_out USHORT *pcFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseTLibAttr ( _                           ' VTable offset = 48
     BYVAL pTLibAttr AS DWORD _                         ' __in TLIBATTR *pTLibAttr
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ITypeLib2 Methods
   ' =====================================================================================
   METHOD GetCustData ( _                               ' VTable offset = 52
     BYREF guid AS GUID _                               ' __in REFGUID guid
   , BYREF pVarVal AS VARIANT _                         ' __out VARIANT *pVarVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLibStatistics ( _                          ' VTable offset = 56
     BYREF pcUniqueNames AS DWORD _                     ' __out ULONG *pcUniqueNames
   , BYREF pcchUniqueNames AS DWORD _                   ' __out ULONG *pcchUniqueNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentation2 ( _                         ' VTable offset = 60
     BYVAL index AS LONG _                              ' __in INT index
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pbstrHelpString AS WSTRING _                 ' __out BSTR *pbstrHelpString
   , BYREF pdwHelpStringContext AS DWORD _              ' __out DWORD *pdwHelpStringContext
   , BYREF pbstrHelpStringDll AS WSTRING _              ' __out BSTR *pbstrHelpStringDll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllCustData ( _                            ' VTable offset = 64
     BYREF pCustData AS CUSTDATA _                      ' __out CUSTDATA *pCustData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITypeLib2_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeChangeEvents interface
' IID = 00020410-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeChangeEvents_INTERFACE_DEFINED)
    %ITypeChangeEvents_INTERFACE_DEFINED = 1

$IID_ITypeChangeEvents = GUID$("{00020410-0000-0000-C000-000000000046}")

' enum CHANGEKIND
%CHANGEKIND_ADDMEMBER        = 0
%CHANGEKIND_DELETEMEMBER     = %CHANGEKIND_ADDMEMBER + 1
%CHANGEKIND_SETNAMES         = %CHANGEKIND_DELETEMEMBER + 1
%CHANGEKIND_SETDOCUMENTATION = %CHANGEKIND_SETNAMES + 1
%CHANGEKIND_GENERAL          = %CHANGEKIND_SETDOCUMENTATION + 1
%CHANGEKIND_INVALIDATE       = %CHANGEKIND_GENERAL + 1
%CHANGEKIND_CHANGEFAILED     = %CHANGEKIND_INVALIDATE + 1
%CHANGEKIND_MAX              = %CHANGEKIND_CHANGEFAILED + 1

'    MIDL_INTERFACE("00020410-0000-0000-C000-000000000046")
'    ITypeChangeEvents : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE RequestTypeChange(
'            __in CHANGEKIND changeKind,
'            __in ITypeInfo *pTInfoBefore,
'            __in LPOLESTR pStrName,
'            __out INT *pfCancel) = 0;

'        virtual HRESULT STDMETHODCALLTYPE AfterTypeChange(
'            __in CHANGEKIND changeKind,
'            __in ITypeInfo *pTInfoAfter,
'            __in LPOLESTR pStrName) = 0;

'    };

#ENDIF   ' /* __ITypeChangeEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' IErrorInfo interface
' IID = 1CF2B120-547D-101B-8E65-08002B2BD119
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IErrorInfo_INTERFACE_DEFINED)
    %IErrorInfo_INTERFACE_DEFINED = 1

$IID_IErrorInfo = GUID$("{1CF2B120-547D-101B-8E65-08002B2BD119}")

INTERFACE IErrorInfo $IID_IErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 12
     BYREF pGUID AS GUID _                              ' __out GUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSource ( _                                 ' VTable offset = 16
     BYREF pBstrSource AS WSTRING _                     ' __out BSTR *pBstrSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 20
     BYREF pBstrDescription AS WSTRING _                ' __out BSTR *pBstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelpFile ( _                               ' VTable offset = 24
     BYREF pBstrHelpFile AS WSTRING _                   ' __out BSTR *pBstrHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelpContext ( _                            ' VTable offset = 28
     BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IErrorInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateErrorInfo interface
' IID = 22F03340-547D-101B-8E65-08002B2BD119
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateErrorInfo_INTERFACE_DEFINED)
    %ICreateErrorInfo_INTERFACE_DEFINED = 1

$IID_ICreateErrorInfo = GUID$("{22F03340-547D-101B-8E65-08002B2BD119}")

INTERFACE ICreateErrorInfo $IID_ICreateErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in REFIID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSource ( _                                 ' VTable offset = 16
     BYREF szSource AS WSTRINGZ _                       ' __in LPCOLESTR szSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 20
     BYREF szDescription AS WSTRINGZ _                  ' __in LPCOLESTR szDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpFile ( _                               ' VTable offset = 24
     BYREF szHelpFile AS WSTRINGZ _                     ' __in LPCOLESTR szHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHelpContext ( _                            ' VTable offset = 28
     BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateErrorInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ISupportErrorInfo interface
' IID = DF0B3D60-548F-101B-8E65-08002B2BD119
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISupportErrorInfo_INTERFACE_DEFINED)
    %ISupportErrorInfo_INTERFACE_DEFINED = 1

$IID_ISupportErrorInfo = GUID$("{DF0B3D60-548F-101B-8E65-08002B2BD119}")

INTERFACE ISupportErrorInfo $IID_ISupportErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InterfaceSupportsErrorInfo ( _                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISupportErrorInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeFactory interface
' IID = 0000002E-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeFactory_INTERFACE_DEFINED)
    %ITypeFactory_INTERFACE_DEFINED = 1

$IID_ITypeFactory = GUID$("{0000002E-0000-0000-C000-000000000046}")

INTERFACE ITypeFactory $IID_ITypeFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateFromTypeInfo ( _                        ' VTable offset = 12
     BYREF pTypeInfo AS ITypeInfo _                     ' __in ITypeInfo *pTypeInfo
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out IUnknown **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __ITypeFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' ITypeMarshal interface
' IID = 0000002D-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITypeMarshal_INTERFACE_DEFINED)
    %ITypeMarshal_INTERFACE_DEFINED = 1

$IID_ITypeMarshal = GUID$("{0000002D-0000-0000-C000-000000000046}")

INTERFACE ITypeMarshal $IID_ITypeMarshal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Size ( _                                      ' VTable offset = 12
     BYVAL pvType AS DWORD _                            ' __in PVOID pvType
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in PVOID pvDestContext
   , BYREF pSize AS DWORD _                             ' __out ULONG *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Marshal ( _                                   ' VTable offset = 16
     BYVAL pvType AS DWORD _                            ' __in PVOID pvType
   , BYVAL dwDestContext AS DWORD _                     ' __in DWORD dwDestContext
   , BYVAL pvDestContext AS DWORD _                     ' __in PVOID pvDestContext
   , BYVAL cbBufferLength AS DWORD _                    ' __in ULONG cbBufferLength
   , BYVAL pBuffer AS BYTE PTR _                        ' __out BYTE *pBuffer
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmarshal ( _                                 ' VTable offset = 20
     BYREF pvType AS DWORD _                            ' __out PVOID pvType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cbBufferLength AS DWORD _                    ' __in ULONG cbBufferLength
   , BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 24
     BYVAL pvType AS DWORD _                            ' __in PVOID pvType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __ITypeMarshal_INTERFACE_DEFINED__ */


' ########################################################################################
' IRecordInfo interface
' IID = 0000002F-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRecordInfo_INTERFACE_DEFINED)
    %IRecordInfo_INTERFACE_DEFINED = 1

$IID_IRecordInfo = GUID$("{0000002F-0000-0000-C000-000000000046}")

INTERFACE IRecordInfo $IID_IRecordInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RecordInit ( _                                ' VTable offset = 12
     BYVAL pvNew AS DWORD _                             ' __out PVOID pvNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordClear ( _                               ' VTable offset = 16
     BYVAL pvExisting AS DWORD _                        ' __in PVOID pvExisting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordCopy ( _                                ' VTable offset = 20
     BYVAL pvExisting AS DWORD _                        ' __in  PVOID pvExisting
   , BYVAL pvNew AS DWORD _                             ' __out PVOID pvNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 24
     BYREF pguid AS GUID _                              ' __out GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 28
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeInfo ( _                               ' VTable offset = 36
     BYREF ppTypeInfo AS ITypeInfo _                    ' __out ITypeInfo **ppTypeInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetField ( _                                  ' VTable offset = 40
     BYVAL pvData AS DWORD _                            ' __in PVOID pvData
   , BYREF szFieldName AS WSTRINGZ _                    ' __in LPCOLESTR szFieldName
   , BYREF pvarField AS VARIANT _                       ' __out VARIANT *pvarField
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldNoCopy ( _                            ' VTable offset = 44
     BYVAL pvData AS DWORD _                            ' __in PVOID pvData
   , BYREF szFieldName AS WSTRINGZ _                    ' __in LPCOLESTR szFieldName
   , BYREF pvarField AS VARIANT _                       ' __out VARIANT *pvarField
   , BYREF ppvDataCArray AS DWORD _                     ' __out PVOID *ppvDataCArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutField ( _                                  ' VTable offset = 48
     BYVAL wFlags AS DWORD _                            ' __in ULONG wFlags
   , BYVAL pvData AS DWORD _                            ' __in_out PVOID pvData
   , BYREF szFieldName AS WSTRINGZ _                    ' __in LPCOLESTR szFieldName
   , BYVAL pvarField AS VARIANT _                       ' __in VARIANT *pvarField
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutFieldNoCopy ( _                            ' VTable offset = 52
     BYVAL wFlags AS DWORD _                            ' __in ULONG wFlags
   , BYVAL pvData AS DWORD _                            ' __in_out PVOID pvData
   , BYREF szFieldName AS WSTRINGZ _                    ' __in LPCOLESTR szFieldName
   , BYVAL pvarField AS VARIANT _                       ' __in VARIANT *pvarField
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFieldNames ( _                             ' VTable offset = 56
     BYREF pcNames AS DWORD _                           ' __in_out ULONG *pcNames
   , BYREF rgBstrNames AS WSTRING _                     ' __out BSTR *rgBstrNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsMatchingType ( _                            ' VTable offset = 60
     BYVAL pRecordInfo AS IRecordInfo _                 ' __in IRecordInfo *pRecordInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordCreate ( _                              ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordCreateCopy ( _                          ' VTable offset = 68
     BYVAL pvSource AS DWORD _                          ' __in PVOID pvSource
   , BYREF ppvDest AS DWORD _                           ' __inout PVOID *ppvDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordDestroy ( _                             ' VTable offset = 72
     BYVAL pvRecord AS DWORD _                          ' __in PVOID pvRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRecordInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IErrorLog interface
' IID = 3127CA40-446E-11CE-8135-00AA004BB851
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IErrorLog_INTERFACE_DEFINED)
    %IErrorLog_INTERFACE_DEFINED = 1

$IID_IErrorLog = GUID$("{3127CA40-446E-11CE-8135-00AA004BB851}")

INTERFACE IErrorLog $IID_IErrorLog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddError ( _                                  ' VTable offset = 12
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pExcepInfo AS EXCEPINFO _                    ' __in EXCEPINFO *pExcepInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __IErrorLog_INTERFACE_DEFINED__ */


' ########################################################################################
' IPropertyBag interface
' IID = 22F55882-280B-11d0-A8A9-00A0C90C2004
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyBag_INTERFACE_DEFINED)
    %IPropertyBag_INTERFACE_DEFINED = 1

$IID_IPropertyBag = GUID$("{55272A00-42CB-11CE-8135-00AA004BB851}")

INTERFACE IPropertyBag $IID_IPropertyBag

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in_out VARIANT *pVar
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in VARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '    /* __IPropertyBag_INTERFACE_DEFINED__ */

#INCLUDE ONCE "ole2.inc"
'/* header files for imported files */
#include ONCE "objidl.inc"
