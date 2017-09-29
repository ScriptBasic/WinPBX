' ########################################################################################
' Microsoft Windows
' File: sqloledb.inc
' Contents: Provider Specific definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQLOLEDB_INC = 1

#INCLUDE ONCE "oledb.inc"

'//----------------------------------------------------------------------------
'// Provider-specific Class Ids
'#IF %DEF(%DBINITCONSTANTS)

$CLSID_SQLOLEDB                        = GUID$("{0C7FF16C-38E3-11d0-97AB-00C04FC2AD98}")
$CLSID_SQLOLEDB_ERROR                  = GUID$("{C0932C62-38E5-11d0-97AB-00C04FC2AD98}")
$CLSID_SQLOLEDB_ENUMERATOR             = GUID$("{DFA22B8E-E68D-11d0-97E4-00C04FC2AD98}")

'//----------------------------------------------------------------------------
'// Provider-specific Interface Ids
$IID_ISQLServerErrorInfo               = GUID$("{5CF4CA12-EF21-11D0-97E7-00004FC2AD98}")
$IID_IRowsetFastLoad                   = GUID$("{5CF4CA13-EF21-11D0-97E7-00C04FC2AD98}")
$IID_IUMSInitialize                    = GUID$("{5CF4CA14-EF21-11D0-97E7-00C04FC2AD98}")
$IID_ISchemaLock                       = GUID$("{4C2389FB-2511-11d4-B258-00C04F7971CE}")
$DBGUID_MSSQLXML                       = GUID$("{5D531CB2-E6ED-11D2-B252-00C04F681B71}")
$DBGUID_XPATH                          = GUID$("{EC2A4293-E898-11D2-B1B7-00C04F680C56}")
'// This IID_ICommandStream definition is available in later versions of
'// UUID.LIB.  It is also already an extern defined in oledb.h.
'//
'#if _MSC_VER < 1300
'$IID_ICommandStream                    = GUID$("{0C733ABF-2A1C-11CE-ADE5-00AA0044773D}")
'#endif // _MSC_VER
$IID_ISQLXMLHelper                     = GUID$("{D22A7678-F860-40CD-A567-1563DEB46D49}")

'//----------------------------------------------------------------------------
'// Provider-specific schema rowsets
$DBSCHEMA_LINKEDSERVERS                = GUID$("{9093CAF4-2EAC-11D1-9809-00C04FC2AD98}")

'#ENDIF   ' // DBINITCONSTANTS

%CRESTRICTIONS_DBSCHEMA_LINKEDSERVERS = 1

'//----------------------------------------------------------------------------
'// Provider-specific property sets
'#ifdef DBINITCONSTANTS
$DBPROPSET_SQLSERVERDATASOURCE         = GUID$("{28EFAEE4-2D2C-11D1-9807-00C04FC2AD98}")
$DBPROPSET_SQLSERVERDATASOURCEINFO     = GUID$("{DF10CB94-35F6-11D2-9C54-00C04F7971D3}")
$DBPROPSET_SQLSERVERDBINIT             = GUID$("{5CF4CA10-EF21-11D0-97E7-00C04FC2AD98}")
$DBPROPSET_SQLSERVERROWSET             = GUID$("{5CF4CA11-EF21-11D0-97E7-00C04FC2AD98}")
$DBPROPSET_SQLSERVERSESSION            = GUID$("{28EFAEE5-2D2C-11D1-9807-00C04FC2AD98}")
$DBPROPSET_SQLSERVERCOLUMN             = GUID$("{3B63FB5E-3FBB-11D3-9F29-00C04F8EE9DC}")
$DBPROPSET_SQLSERVERSTREAM             = GUID$("{9F79C073-8A6D-4BCA-A8A8-C9B79A9B962D}")
'#endif // DBINITCONSTANTS


'//This is a guid candidate : ;
'//----------------------------------------------------------------------------
'// Provider-specific columns for IColumnsRowset

'#ifdef DBINITCONSTANTS
MACRO DBCOLUMN_SS_COMPFLAGS      = GUID$("{627bd890-ed54-11d2-b994-00c04f8ca82c}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(100)
MACRO DBCOLUMN_SS_SORTID         = GUID$("{627bd890-ed54-11d2-b994-00c04f8ca82c}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(101)
MACRO DBCOLUMN_BASETABLEINSTANCE = GUID$("{627bd890-ed54-11d2-b994-00c04f8ca82c}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(102)
MACRO DBCOLUMN_SS_TDSCOLLATION   = GUID$("{627bd890-ed54-11d2-b994-00c04f8ca82c}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(103)
'#endif // DBINITCONSTANTS

'//----------------------------------------------------------------------------
'// PropIds for DBPROP_INIT_GENERALTIMEOUT
' Already defined in oledb.inc
'#IF %OLEDBVER >= &H0210
'%DBPROP_INIT_GENERALTIMEOUT          = &H11C&
'#ENDIF

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERDATASOURCE
%SSPROP_ENABLEFASTLOAD               = 2

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERDATASOURCEINFO
%SSPROP_UNICODELCID                  = 2
%SSPROP_UNICODECOMPARISONSTYLE       = 3
%SSPROP_COLUMNLEVELCOLLATION         = 4
%SSPROP_CHARACTERSET                 = 5
%SSPROP_SORTORDER                    = 6
%SSPROP_CURRENTCOLLATION             = 7

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERDBINIT
%SSPROP_INIT_CURRENTLANGUAGE         = 4
%SSPROP_INIT_NETWORKADDRESS          = 5
%SSPROP_INIT_NETWORKLIBRARY          = 6
%SSPROP_INIT_USEPROCFORPREP          = 7
%SSPROP_INIT_AUTOTRANSLATE           = 8
%SSPROP_INIT_PACKETSIZE              = 9
%SSPROP_INIT_APPNAME                 = 10
%SSPROP_INIT_WSID                    = 11
%SSPROP_INIT_FILENAME                = 12
%SSPROP_INIT_ENCRYPT                 = 13
%SSPROP_AUTH_REPL_SERVER_NAME        = 14
%SSPROP_INIT_TAGCOLUMNCOLLATION      = 15

'//-----------------------------------------------------------------------------
'// Values for SSPROP_USEPROCFORPREP
%SSPROPVAL_USEPROCFORPREP_OFF        = 0
%SSPROPVAL_USEPROCFORPREP_ON         = 1
%SSPROPVAL_USEPROCFORPREP_ON_DROP    = 2

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERSESSION
%SSPROP_QUOTEDCATALOGNAMES           = 2
%SSPROP_ALLOWNATIVEVARIANT           = 3
%SSPROP_SQLXMLXPROGID                = 4

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERROWSET
%SSPROP_MAXBLOBLENGTH                = 8
%SSPROP_FASTLOADOPTIONS              = 9
%SSPROP_FASTLOADKEEPNULLS            = 10
%SSPROP_FASTLOADKEEPIDENTITY         = 11
%SSPROP_CURSORAUTOFETCH              = 12
%SSPROP_DEFERPREPARE                 = 13
%SSPROP_IRowsetFastLoad              = 14

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERCOLUMN
%SSPROP_COL_COLLATIONNAME            = 14

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERSTREAM
%SSPROP_STREAM_MAPPINGSCHEMA         = 15
%SSPROP_STREAM_XSL                   = 16
%SSPROP_STREAM_BASEPATH              = 17
%SSPROP_STREAM_COMMANDTYPE           = 18
%SSPROP_STREAM_XMLROOT               = 19
%SSPROP_STREAM_FLAGS                 = 20
%SSPROP_STREAM_CONTENTTYPE           = 23

'//----------------------------------------------------------------------------
'// Possible values for SSPROP_STREAM_FLAGS
%STREAM_FLAGS_DISALLOW_URL           = &H00000001???
%STREAM_FLAGS_DISALLOW_ABSOLUTE_PATH = &H00000002???
%STREAM_FLAGS_DISALLOW_QUERY         = &H00000004???
%STREAM_FLAGS_DONTCACHEMAPPINGSCHEMA = &H00000008???
%STREAM_FLAGS_DONTCACHETEMPLATE      = &H00000010???
%STREAM_FLAGS_DONTCACHEXSL           = &H00000020???
%STREAM_FLAGS_DISALLOW_UPDATEGRAMS   = &H00000040???
%STREAM_FLAGS_RESERVED               = &HFFFF0000???

'// Values for SSPROPVAL_COMMANDTYPE

%SSPROPVAL_COMMANDTYPE_REGULAR       = 21
%SSPROPVAL_COMMANDTYPE_BULKLOAD      = 22

'//-------------------------------------------------------------------
'// Variant Access macros, similar to ole automation.
'//-------------------------------------------------------------------

'#define V_SS_VT(X)         ((X)->vt)
'#define V_SS_UNION(X, Y)   ((X)->Y)

'#define V_SS_UI1(X)           V_SS_UNION(X, bTinyIntVal)
'#define V_SS_I2(X)            V_SS_UNION(X, sShortIntVal)
'#define V_SS_I4(X)            V_SS_UNION(X, lIntVal)
'#define V_SS_I8(X)            V_SS_UNION(X, llBigIntVal)

'#define V_SS_R4(X)            V_SS_UNION(X, fltRealVal)
'#define V_SS_R8(X)            V_SS_UNION(X, dblFloatVal)
'#define V_SS_UI4(X)           V_SS_UNION(X, ulVal)

'#define V_SS_MONEY(X)         V_SS_UNION(X, cyMoneyVal)
'#define V_SS_SMALLMONEY(X)    V_SS_UNION(X, cyMoneyVal)

'#define V_SS_WSTRING(X)       V_SS_UNION(X, NCharVal)
'#define V_SS_WVARSTRING(X)    V_SS_UNION(X, NCharVal)

'#define V_SS_STRING(X)        V_SS_UNION(X, CharVal)
'#define V_SS_VARSTRING(X)     V_SS_UNION(X, CharVal)

'#define V_SS_BIT(X)           V_SS_UNION(X, fBitVal)
'#define V_SS_GUID(X)          V_SS_UNION(X, rgbGuidVal)

'#define V_SS_NUMERIC(X)       V_SS_UNION(X, numNumericVal)
'#define V_SS_DECIMAL(X)       V_SS_UNION(X, numNumericVal)

'#define V_SS_BINARY(X)        V_SS_UNION(X, BinaryVal)
'#define V_SS_VARBINARY(X)     V_SS_UNION(X, BinaryVal)

'#define V_SS_DATETIME(X)      V_SS_UNION(X, tsDateTimeVal)
'#define V_SS_SMALLDATETIME(X) V_SS_UNION(X, tsDateTimeVal)

'#define V_SS_UNKNOWN(X)   V_SS_UNION(X, UnknownType)

'//For next release.
'#define V_SS_IMAGE(X)   V_SS_UNION(X, ImageVal)
'#define V_SS_TEXT(X)    V_SS_UNION(X, TextVal)
'#define V_SS_NTEXT(X)   V_SS_UNION(X, NTextVal)

'//-------------------------------------------------------------------
'// define SQL Server Spefific Variant Type
'//-------------------------------------------------------------------
%DBTYPE_SQLVARIANT                   = 144??

' SQLVARENUM
%VT_SS_EMPTY                         = %DBTYPE_EMPTY
%VT_SS_NULL                          = %DBTYPE_NULL
%VT_SS_UI1                           = %DBTYPE_UI1
%VT_SS_I2                            = %DBTYPE_I2
%VT_SS_I4                            = %DBTYPE_I4
%VT_SS_I8                            = %DBTYPE_I8

' // Floats
%VT_SS_R4                            = %DBTYPE_R4
%VT_SS_R8                            = %DBTYPE_R8

' // Money
%VT_SS_MONEY                         = %DBTYPE_CY
%VT_SS_SMALLMONEY                    = 200??

' // Strings
%VT_SS_WSTRING                       = 201??
%VT_SS_WVARSTRING                    = 202??

%VT_SS_STRING                        = 203??
%VT_SS_VARSTRING                     = 204??

' // Bit
%VT_SS_BIT                           = %DBTYPE_BOOL

' // Guid
%VT_SS_GUID                          = %DBTYPE_GUID

' // Exact precision
%VT_SS_NUMERIC                       = %DBTYPE_NUMERIC
%VT_SS_DECIMAL                       = 205??

' // Datetime
%VT_SS_DATETIME                      = %DBTYPE_DBTIMESTAMP
%VT_SS_SMALLDATETIME                 = 206??

' // Binary
%VT_SS_BINARY                        = 207??
%VT_SS_VARBINARY                     = 208??

' // Future
%VT_SS_UNKNOWN                       = 209??

'typedef unsigned short SSVARTYPE;


'//Hungarian : ssv (Sql Server Variant)
'struct SSVARIANT
'   {
'      SSVARTYPE vt;
'      DWORD dwReserved1;
'      DWORD dwReserved2;
'        union
'            {
'         BYTE bTinyIntVal;
'         SHORT sShortIntVal;
'            LONG lIntVal;
'            LONGLONG llBigIntVal;

'            FLOAT fltRealVal;
'            DOUBLE dblFloatVal;

'         CY cyMoneyVal;

'         struct _NCharVal
'            {
'            SHORT sActualLength;
'            SHORT sMaxLength;
'            WCHAR * pwchNCharVal;
'            BYTE rgbReserved[5];
'            DWORD dwReserved;
'            WCHAR * pwchReserved;
'            } NCharVal;


'         struct _CharVal
'            {
'            SHORT sActualLength;
'            SHORT sMaxLength;
'            CHAR  * pchCharVal;
'            BYTE rgbReserved[5];
'            DWORD dwReserved;
'            WCHAR * pwchReserved;
'            } CharVal;

'         VARIANT_BOOL  fBitVal;
'         BYTE  rgbGuidVal [16];

'         DB_NUMERIC numNumericVal;

'         struct _BinaryVal
'            {
'            SHORT sActualLength;
'            SHORT sMaxLength;
'            BYTE  * prgbBinaryVal;
'            DWORD dwReserved;
'            } BinaryVal;

'         DBTIMESTAMP  tsDateTimeVal;

'         struct _UnknownType
'            {
'            DWORD dwActualLength;
'            BYTE rgMetadata [16];
'            BYTE * pUnknownData;
'            } UnknownType;

'         struct _BLOBType
'            {
'            DBOBJECT dbobj;
'            IUnknown * pUnk;
'            } BLOBType;
'         };

'    };

' // Size = 24 bytes
TYPE SSVARIANT_NCharVal DWORD FILL
   sActualLength  AS INTEGER
   sMaxLength     AS INTEGER
   pwchNCharVal   AS WORD PTR
   rgbReserved(4) AS BYTE
   dwReserved     AS DWORD
   pwchReserved   AS WORD PTR
END TYPE

' // Size = 24 bytes
TYPE SSVARIANT_CharVal DWORD FILL
   sActualLength  AS INTEGER
   sMaxLength     AS INTEGER
   pchCharVal     AS ASCIIZ PTR
   rgbReserved(4) AS BYTE
   dwReserved     AS DWORD
   pwchReserved   AS WORD PTR
END TYPE

' // Size = 12 bytes
TYPE SSVARIANT_BinaryVal DWORD FILL
   sActualLength AS INTEGER
   sMaxLength    AS INTEGER
   prgbBinaryVal AS BYTE PTR
   dwReserved    AS DWORD
END TYPE

' // Size = 24 bytes
TYPE SSVARIANT_UnknownType DWORD FILL
   dwActualLength AS DWORD
   rgMetadata(15) AS BYTE
   pUnknownData   AS BYTE PTR
END TYPE

' // Size = 24 bytes
TYPE SSVARIANT_BLOBType DWORD FILL
   dbobj AS DBOBJECT
   pUnk  AS DWORD
END TYPE

' // Size = 24 bytes
UNION SSVARIANT_UNION
   bTinyIntVal    AS BYTE
   sShortIntVal   AS INTEGER
   lIntVal        AS LONG
   llBigIntVal    AS QUAD
   fltRealVal     AS SINGLE
   dblFloatVal    AS DOUBLE
   cyMoneyVal     AS CUR
   NCharVal       AS SSVARIANT_NCharVal
   CharVal        AS SSVARIANT_CharVal
   fBitVal        AS INTEGER
   rgbGuidVal(15) AS BYTE
   numNumericVal  AS DB_NUMERIC
   BinaryVal      AS SSVARIANT_BinaryVal
   tsDateTimeVal  AS DBTIMESTAMP
   UnknownType    AS SSVARIANT_UnknownType
   BLOBType       AS SSVARIANT_BLOBType
END UNION

' //Hungarian : ssv (Sql Server Variant)
' // Size = 40 bytes
TYPE SSVARIANT DWORD   ' Must be 8 byte aligned
   vt          AS WORD
   dwReserved1 AS DWORD
   dwReserved2 AS DWORD
   alignment__ AS DWORD   ' // To keep 8 byte alignment
   SSVARIANT_UNION
END TYPE

'#if defined(__cplusplus) && !defined(CINTERFACE)

'//-----------------------------------------------------------------
'// Class Factory Interface used to initialize pointer to UMS.
'//
'interface IUMSInitialize : public IUnknown
'{
'public:
'    virtual HRESULT STDMETHODCALLTYPE Initialize (VOID * pUMS) = 0;
'};

' ########################################################################################
' IUMSInitialize interface
' IID = 5CF4CA14-EF21-11D0-97E7-00C04FC2AD98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUMSInitialize_INTERFACE_DEFINED)
    %IUMSInitialize_INTERFACE_DEFINED = 1

INTERFACE IUMSInitialize $IID_IUMSInitialize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pUMS AS DWORD _                              ' __in VOID * pUMS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUMSInitialize_INTERFACE_DEFINED__ */

'//-----------------------------------------------------------------
'// Interface used to communicate with UMS.
'//
'interface IUMS
'{
'public:
'   virtual VOID STDMETHODCALLTYPE SqlUmsSuspend (ULONG ticks) = 0;
'   virtual VOID STDMETHODCALLTYPE SqlUmsYield (ULONG ticks) = 0;
'   virtual VOID STDMETHODCALLTYPE SqlUmsSwitchPremptive () = 0;
'   virtual VOID STDMETHODCALLTYPE SqlUmsSwitchNonPremptive() = 0;
'   virtual BOOL STDMETHODCALLTYPE SqlUmsFIsPremptive() = 0;
'};

'#endif


'// the structure returned by  ISQLServerErrorInfo::GetSQLServerInfo
' // Size = 20 bytes
TYPE SSERRORINFO DWORD FILL
   pwszMessage   AS WSTRINGZ PTR   ' LPOLESTR
   pwszServer    AS WSTRINGZ PTR   ' LPOLESTR
   pwszProcedure AS WSTRINGZ PTR   ' LPOLESTR
   lNative       AS LONG
   bState        AS BYTE
   bClass        AS BYTE
   wLineNumber   AS WORD
END TYPE

' ########################################################################################
' ISQLServerErrorInfo interface
' IID = 5CF4CA12-EF21-11D0-97E7-00C04FC2AD98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISQLServerErrorInfo_INTERFACE_DEFINED)
    %ISQLServerErrorInfo_INTERFACE_DEFINED = 1

INTERFACE ISQLServerErrorInfo $IID_ISQLServerErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetErrorInfo ( _                              ' VTable offset = 12
     BYREF ppErrorInfo AS SSERRORINFO _                 ' __out SSERRORINFO **ppErrorInfo
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLServerErrorInfo_INTERFACE_DEFINED__ */

'#ifdef _WIN64
'typedef ULONG_PTR HACCESSOR;
'#else
'typedef ULONG HACCESSOR;
'#endif

' ########################################################################################
' IRowsetFastLoad interface
' IID = 5CF4CA13-EF21-11D0-97E7-00C04FC2AD98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetFastLoad_INTERFACE_DEFINED)
    %IRowsetFastLoad_INTERFACE_DEFINED = 1

INTERFACE IRowsetFastLoad $IID_IRowsetFastLoad

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertRow ( _                                 ' VTable offset = 12
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __in void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
     BYVAL fDone AS LONG _                              ' __in BOOL fDone
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetFastLoad_INTERFACE_DEFINED__ */

'typedef DWORD LOCKMODE;

' LOCKMODEENUM
%LOCKMODE_INVALID   = 0
%LOCKMODE_EXCLUSIVE = %LOCKMODE_INVALID   + 1
%LOCKMODE_SHARED    = %LOCKMODE_EXCLUSIVE + 1


' ########################################################################################
' ISchemaLock interface
' IID = 4C2389FB-2511-11d4-B258-00C04F7971CE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISchemaLock_INTERFACE_DEFINED)
    %ISchemaLock_INTERFACE_DEFINED = 1

INTERFACE ISchemaLock $IID_ISchemaLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSchemaLock ( _                             ' VTable offset = 12
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYVAL lmMode AS DWORD _                            ' __in LOCKMODE lmMode
   , BYREF phLockHandle AS DWORD _                      ' __out HANDLE *phLockHandle
   , BYREF pTableVersion AS QUAD _                      ' __out ULONGLONG *pTableVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseSchemaLock ( _                         ' VTable offset = 16
     BYVAL hLockHandle AS DWORD _                       ' __in HANDLE hLockHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISchemaLock_INTERFACE_DEFINED__ */
