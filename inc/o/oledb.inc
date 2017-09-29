' ########################################################################################
' Microsoft Windows
' File: oledb.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEDB_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "transact.inc"
#INCLUDE ONCE "oledbguid.inc"
#INCLUDE ONCE "accctrl.inc"

'#ifdef _WIN64
'#include <pshpack8.h>   // 8-byte structure packing
'#else
'#include <pshpack2.h>   // 2-byte structure packing
'#endif

'//
'// OLEDBVER
'//   OLE DB version number is 2.7 (0x0270); to force a particular version,
'//   #define OLEDBVER as required before including this file.
'//

'// If OLEDBVER is not defined, assume version 2.7
#IF NOT %DEF(%OLEDBVER)
    %OLEDBVER = &H0270
#ENDIF

'// Length of a non-character object, size
'typedef ULONG DBLENGTH;
'// Offset within a rowset
'typedef LONG DBROWOFFSET;
'// Number of rows
'typedef LONG DBROWCOUNT;
'typedef ULONG DBCOUNTITEM;
'// Ordinal (column number, etc.)
'typedef ULONG DBORDINAL;
'typedef LONG DB_LORDINAL;
'// Bookmarks
'typedef ULONG DBBKMARK;
'// Offset in the buffer
'typedef ULONG DBBYTEOFFSET;
'// Reference count of each row handle
'typedef ULONG DBREFCOUNT;
'// Parameters
'typedef ULONG DB_UPARAMS;
'typedef LONG DB_LPARAMS;
'// hash values corresponding to the elements (bookmarks)
'typedef DWORD DBHASHVALUE;
'// For reserve
'typedef DWORD DB_DWRESERVE;
'typedef LONG DB_LRESERVE;
'typedef ULONG DB_URESERVE;


#IF NOT %DEF(%DBStructureDefinitions_INTERFACE_DEFINED)
%DBStructureDefinitions_INTERFACE_DEFINED = 1

' // Size = 19 bytes
TYPE DB_NUMERIC BYTE
   precision AS BYTE   ' BYTE[1]
   scale     AS BYTE   ' BYTE[1]
   sign      AS BYTE   ' BYTE[1]
'   val(15)   AS BYTE   ' BYTE[16]
   val       AS STRING * 16
END TYPE

'typedef hyper LONGLONG;
'typedef MIDL_uhyper ULONGLONG;

' // Size = 8 bytes
TYPE DBVECTOR DWORD
   size AS DWORD   ' DBLENGTH
   ptr  AS DWORD   ' void *ptr
END TYPE

' // Size = 6 bytes
TYPE DBDATE WORD
   year  AS INTEGER   ' SHORT
   month AS WORD      ' USHORT
   day   AS WORD      ' USHORT
END TYPE

' // Size = 6 bytes
TYPE DBTIME WORD
   hour   AS WORD   ' USHORT
   minute AS WORD   ' USHORT
   second AS WORD   ' USHORT
END TYPE

' // Size = 16 bytes
TYPE DBTIMESTAMP WORD
   year     AS INTEGER   ' SHORT
   month    AS WORD      ' USHORT
   day      AS WORD      ' USHORT
   hour     AS WORD      ' USHORT
   minute   AS WORD      ' USHORT
   second   AS WORD      ' USHORT
   fraction AS DWORD     ' ULONG
END TYPE

'typedef signed char SBYTE;

' // Size = 4 bytes
TYPE DB_VARNUMERIC BYTE
   precision AS BYTE   ' BYTE
   scale     AS BYTE   ' SBYTE
   sign      AS BYTE   ' BYTE
   val(0)    AS BYTE   ' Variable-length array
END TYPE

' // Size = 40 bytes
TYPE SEC_OBJECT_ELEMENT DWORD
   guidObjectType AS GUID
   ObjectID       AS DBID
END TYPE

' // Size = 8 bytes
TYPE SEC_OBJECT DWORD
   cObjects   AS DWORD
   prgObjects AS SEC_OBJECT_ELEMENT PTR   ' SEC_OBJECT_ELEMENT *prgObjects [array]
END TYPE

' // Size = 12 bytes
TYPE DBIMPLICITSESSION DWORD
   pUnkOuter AS DWORD PTR   ' IUnknown *
   piid      AS GUID PTR    ' IID *
   pSession  AS DWORD PTR   ' IUnknown *
END TYPE

'typedef WORD DBTYPE;

' DBTYPEENUM
%DBTYPE_EMPTY       = 0??
%DBTYPE_NULL        = 1??
%DBTYPE_I2          = 2??
%DBTYPE_I4          = 3??
%DBTYPE_R4          = 4??
%DBTYPE_R8          = 5??
%DBTYPE_CY          = 6??
%DBTYPE_DATE        = 7??
%DBTYPE_BSTR        = 8??
%DBTYPE_IDISPATCH   = 9??
%DBTYPE_ERROR       = 10??
%DBTYPE_BOOL        = 11??
%DBTYPE_VARIANT     = 12??
%DBTYPE_IUNKNOWN    = 13??
%DBTYPE_DECIMAL     = 14??
%DBTYPE_UI1         = 17??
%DBTYPE_ARRAY       = &H2000??
%DBTYPE_BYREF       = &H4000??
%DBTYPE_I1          = 16??
%DBTYPE_UI2         = 18??
%DBTYPE_UI4         = 19??
%DBTYPE_I8          = 20??
%DBTYPE_UI8         = 21??
%DBTYPE_GUID        = 72??
%DBTYPE_VECTOR      = &H1000??
%DBTYPE_RESERVED    = &H8000??
%DBTYPE_BYTES       = 128??
%DBTYPE_STR         = 129??
%DBTYPE_WSTR        = 130??
%DBTYPE_NUMERIC     = 131??
%DBTYPE_UDT         = 132??
%DBTYPE_DBDATE      = 133??
%DBTYPE_DBTIME      = 134??
%DBTYPE_DBTIMESTAMP = 135??

'// Introduce some new DBTYPTE value to support 64bits ColumnsRowset
%DBTYPEFOR_DBLENGTH   = %DBTYPE_UI4
%DBTYPEFOR_DBROWCOUNT = %DBTYPE_I4
%DBTYPEFOR_DBORDINAL  = %DBTYPE_UI4

' DBTYPEENUM15
%DBTYPE_HCHAPTER    = 136??

' DBTYPEENUM20
%DBTYPE_FILETIME    = 64??
%DBTYPE_DBFILETIME  = 137??
%DBTYPE_PROPVARIANT = 138??
%DBTYPE_VARNUMERIC  = 139??

'typedef DWORD DBPART;

' DBPARTENUM
%DBPART_INVALID     = 0???
%DBPART_VALUE       = &H1???
%DBPART_LENGTH      = &H2???
%DBPART_STATUS      = &H4???

'typedef DWORD DBPARAMIO;

' DBPARAMIOENUM
%DBPARAMIO_NOTPARAM = 0???
%DBPARAMIO_INPUT    = &H1???
%DBPARAMIO_OUTPUT   = &H2???

'typedef DWORD DBBINDFLAG;

' DBBINDFLAGENUM
%DBBINDFLAG_HTML    = &H1???

'typedef DWORD DBMEMOWNER;

' DBMEMOWNERENUM
%DBMEMOWNER_CLIENTOWNED   = 0???
%DBMEMOWNER_PROVIDEROWNED = &H1???

' // Size = 20 bytes
TYPE DBOBJECT DWORD
   dwFlags AS DWORD   ' DWORD
   iid     AS GUID    ' IID
END TYPE

'typedef DWORD DBSTATUS;

' DBSTATUSENUM
%DBSTATUS_S_OK                 = 0???
%DBSTATUS_E_BADACCESSOR        = 1???
%DBSTATUS_E_CANTCONVERTVALUE   = 2???
%DBSTATUS_S_ISNULL             = 3???
%DBSTATUS_S_TRUNCATED          = 4???
%DBSTATUS_E_SIGNMISMATCH       = 5???
%DBSTATUS_E_DATAOVERFLOW       = 6???
%DBSTATUS_E_CANTCREATE         = 7???
%DBSTATUS_E_UNAVAILABLE        = 8???
%DBSTATUS_E_PERMISSIONDENIED   = 9???
%DBSTATUS_E_INTEGRITYVIOLATION = 10???
%DBSTATUS_E_SCHEMAVIOLATION    = 11???
%DBSTATUS_E_BADSTATUS          = 12???
%DBSTATUS_S_DEFAULT            = 13???

' DBSTATUSENUM20
%MDSTATUS_S_CELLEMPTY          = 14???
%DBSTATUS_S_IGNORE             = 15???

' DBSTATUSENUM21
%DBSTATUS_E_DOESNOTEXIST       = 16???
%DBSTATUS_E_INVALIDURL         = 17???
%DBSTATUS_E_RESOURCELOCKED     = 18???
%DBSTATUS_E_RESOURCEEXISTS     = 19???
%DBSTATUS_E_CANNOTCOMPLETE     = 20???
%DBSTATUS_E_VOLUMENOTFOUND     = 21???
%DBSTATUS_E_OUTOFSPACE         = 22???
%DBSTATUS_S_CANNOTDELETESOURCE = 23???
%DBSTATUS_E_READONLY           = 24???
%DBSTATUS_E_RESOURCEOUTOFSCOPE = 25???
%DBSTATUS_S_ALREADYEXISTS      = 26???

'typedef DWORD DBBINDURLFLAG;

' DBBINDURLFLAGENUM
%DBBINDURLFLAG_READ                 = &H1???
%DBBINDURLFLAG_WRITE                = &H2???
%DBBINDURLFLAG_READWRITE            = &H3???
%DBBINDURLFLAG_SHARE_DENY_READ      = &H4???
%DBBINDURLFLAG_SHARE_DENY_WRITE     = &H8???
%DBBINDURLFLAG_SHARE_EXCLUSIVE      = &Hc???
%DBBINDURLFLAG_SHARE_DENY_NONE      = &H10???
%DBBINDURLFLAG_ASYNCHRONOUS         = &H1000???
%DBBINDURLFLAG_COLLECTION           = &H2000???
%DBBINDURLFLAG_DELAYFETCHSTREAM     = &H4000???
%DBBINDURLFLAG_DELAYFETCHCOLUMNS    = &H8000???
%DBBINDURLFLAG_RECURSIVE            = &H400000???
%DBBINDURLFLAG_OUTPUT               = &H800000???
%DBBINDURLFLAG_WAITFORINIT          = &H1000000???
%DBBINDURLFLAG_OPENIFEXISTS         = &H2000000???
%DBBINDURLFLAG_OVERWRITE            = &H4000000???
%DBBINDURLFLAG_ISSTRUCTUREDDOCUMENT = &H8000000???

'typedef DWORD DBBINDURLSTATUS;

' DBBINDURLSTATUSENUM
%DBBINDURLSTATUS_S_OK                   = 0???
%DBBINDURLSTATUS_S_DENYNOTSUPPORTED     = &H1???
%DBBINDURLSTATUS_S_DENYTYPENOTSUPPORTED = &H4???
%DBBINDURLSTATUS_S_REDIRECTED           = &H8???

' DBSTATUSENUM25
%DBSTATUS_E_CANCELED      = 27???
%DBSTATUS_E_NOTCOLLECTION = 28???

' // Size = 8 bytes
TYPE DBBINDEXT DWORD
   pExtension  AS BYTE PTR   ' BYTE *
   ulExtension AS DWORD      ' DBCOUNTITEM
END TYPE

' // Size = 52 bytes
TYPE DBBINDING BYTE
   iOrdinal   AS DWORD           ' DBORDINAL
   obValue    AS DWORD           ' DBBYTEOFFSET
   obLength   AS DWORD           ' DBBYTEOFFSET
   obStatus   AS DWORD           ' DBBYTEOFFSET
   pTypeInfo  AS DWORD           ' ITypeInfo *
   pObject    AS DBOBJECT PTR    ' DBOBJECT *
   pBindExt   AS DBBINDEXT PTR   ' DBBINDEXT *
   dwPart     AS DWORD           ' DBPART
   dwMemOwner AS DWORD           ' DBMEMOWNER
   eParamIO   AS DWORD           ' DBPARAMIO
   cbMaxLen   AS DWORD           ' DBLENGTH
   dwFlags    AS DWORD           ' DWORD
   wType      AS WORD            ' DBTYPE
   bPrecision AS BYTE
   bScale     AS BYTE
END TYPE

'typedef DWORD DBROWSTATUS;

' DBROWSTATUSENUM
%DBROWSTATUS_S_OK                           = 0???
%DBROWSTATUS_S_MULTIPLECHANGES              = 2???
%DBROWSTATUS_S_PENDINGCHANGES               = 3???
%DBROWSTATUS_E_CANCELED                     = 4???
%DBROWSTATUS_E_CANTRELEASE                  = 6???
%DBROWSTATUS_E_CONCURRENCYVIOLATION         = 7???
%DBROWSTATUS_E_DELETED                      = 8???
%DBROWSTATUS_E_PENDINGINSERT                = 9???
%DBROWSTATUS_E_NEWLYINSERTED                = 10???
%DBROWSTATUS_E_INTEGRITYVIOLATION           = 11???
%DBROWSTATUS_E_INVALID                      = 12???
%DBROWSTATUS_E_MAXPENDCHANGESEXCEEDED       = 13???
%DBROWSTATUS_E_OBJECTOPEN                   = 14???
%DBROWSTATUS_E_OUTOFMEMORY                  = 15???
%DBROWSTATUS_E_PERMISSIONDENIED             = 16???
%DBROWSTATUS_E_LIMITREACHED                 = 17???
%DBROWSTATUS_E_SCHEMAVIOLATION              = 18???
%DBROWSTATUS_E_FAIL                         = 19???

' DBROWSTATUSENUM20
%DBROWSTATUS_S_NOCHANGE                     = 20???

' DBSTATUSENUM26
%DBSTATUS_S_ROWSETCOLUMN                    = 29???

'typedef ULONG_PTR HACCESSOR;

%DB_NULL_HACCESSOR    = &H0   ' // deprecated; use DB_INVALID_HACCESSOR instead
%DB_INVALID_HACCESSOR = &H0
'typedef ULONG_PTR HROW;

%DB_NULL_HROW = &H0
'typedef ULONG_PTR HWATCHREGION;

%DBWATCHREGION_NULL = 0
'typedef ULONG_PTR HCHAPTER;

%DB_NULL_HCHAPTER    = &H0
%DB_INVALID_HCHAPTER = &H0   ' // deprecated; use DB_NULL_HCHAPTER instead

' // Size = 12 bytes
TYPE DBFAILUREINFO DWORD
   hRow    AS DWORD   ' HROW
   iColumn AS DWORD   ' DBORDINAL
   failure AS DWORD   ' HRESULT
END TYPE

'typedef DWORD DBCOLUMNFLAGS;

' DBCOLUMNFLAGSENUM
%DBCOLUMNFLAGS_ISBOOKMARK                   = &H1???
%DBCOLUMNFLAGS_MAYDEFER                     = &H2???
%DBCOLUMNFLAGS_WRITE                        = &H4???
%DBCOLUMNFLAGS_WRITEUNKNOWN                 = &H8???
%DBCOLUMNFLAGS_ISFIXEDLENGTH                = &H10???
%DBCOLUMNFLAGS_ISNULLABLE                   = &H20???
%DBCOLUMNFLAGS_MAYBENULL                    = &H40???
%DBCOLUMNFLAGS_ISLONG                       = &H80???
%DBCOLUMNFLAGS_ISROWID                      = &H100???
%DBCOLUMNFLAGS_ISROWVER                     = &H200???
%DBCOLUMNFLAGS_CACHEDEFERRED                = &H1000???

' DBCOLUMNSFLAGSENUM20
%BCOLUMNFLAGS_SCALEISNEGATIVE               = &H4000???
%DBCOLUMNFLAGS_RESERVED                     = &H8000???

' DBCOLUMNFLAGSDEPRECATED
'%DBCOLUMNFLAGS_KEYCOLUMN                    = &H8000???

' DBCOLUMNSFLAGS15ENUM
%DBCOLUMNFLAGS_ISCHAPTER                    = &H2000???

' DBCOLUMNFLAGSENUM21
%DBCOLUMNFLAGS_ISROWURL                     = &H10000???
%DBCOLUMNFLAGS_ISDEFAULTSTREAM              = &H20000???
%DBCOLUMNFLAGS_ISCOLLECTION                 = &H40000???

' DBCOLUMNFLAGSENUM26
%DBCOLUMNFLAGS_ISSTREAM                     = &H80000???
%DBCOLUMNFLAGS_ISROWSET                     = &H100000???
%DBCOLUMNFLAGS_ISROW                        = &H200000???
%DBCOLUMNFLAGS_ROWSPECIFICCOLUMN            = &H400000???

' DBTABLESTATISTICSTYPE26
%DBSTAT_HISTOGRAM                           = &H1???
%DBSTAT_COLUMN_CARDINALITY                  = &H2???
%DBSTAT_TUPLE_CARDINALITY                   = &H4???

' // Size = 48 bytes
TYPE DBCOLUMNINFO BYTE
   pwszName     AS WSTRINGZ PTR   ' LPOLESTR
   pTypeInfo    AS DWORD          ' ITypeInfo
   iOrdinal     AS DWORD          ' DBORDINAL
   dwFlags      AS DWORD          ' DBCOLUMNFLAGS
   ulColumnSize AS DWORD          ' DBLENGTH
   wType        AS WORD           ' DBTYPE
   bPrecision   AS BYTE           ' BYTE
   bScale       AS BYTE           ' BYTE
   columnid     AS DBID           ' DBID
END TYPE

' DBBOOKMARK
%DBBMK_INVALID = 0
%DBBMK_FIRST   = %DBBMK_INVALID + 1
%DBBMK_LAST    = %DBBMK_FIRST   + 1

%STD_BOOKMARKLENGTH                         = 1
%DB_INVALIDCOLUMN                           = &Hffffffff   ' ULONG_MAX

' DBPROPENUM
%DBPROP_ABORTPRESERVE                       = &H2&
%DBPROP_ACTIVESESSIONS                      = &H3&
%DBPROP_APPENDONLY                          = &Hbb&
%DBPROP_ASYNCTXNABORT                       = &Ha8&
%DBPROP_ASYNCTXNCOMMIT                      = &H4&
%DBPROP_AUTH_CACHE_AUTHINFO                 = &H5&
%DBPROP_AUTH_ENCRYPT_PASSWORD               = &H6&
%DBPROP_AUTH_INTEGRATED                     = &H7&
%DBPROP_AUTH_MASK_PASSWORD                  = &H8&
%DBPROP_AUTH_PASSWORD                       = &H9&
%DBPROP_AUTH_PERSIST_ENCRYPTED              = &Ha&
%DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO     = &Hb&
%DBPROP_AUTH_USERID                         = &Hc&
%DBPROP_BLOCKINGSTORAGEOBJECTS              = &Hd&
%DBPROP_BOOKMARKS                           = &He&
%DBPROP_BOOKMARKSKIPPED                     = &Hf&
%DBPROP_BOOKMARKTYPE                        = &H10&
%DBPROP_BYREFACCESSORS                      = &H78&
%DBPROP_CACHEDEFERRED                       = &H11&
%DBPROP_CANFETCHBACKWARDS                   = &H12&
%DBPROP_CANHOLDROWS                         = &H13&
%DBPROP_CANSCROLLBACKWARDS                  = &H15&
%DBPROP_CATALOGLOCATION                     = &H16&
%DBPROP_CATALOGTERM                         = &H17&
%DBPROP_CATALOGUSAGE                        = &H18&
%DBPROP_CHANGEINSERTEDROWS                  = &Hbc&
%DBPROP_COL_AUTOINCREMENT                   = &H1a&
%DBPROP_COL_DEFAULT                         = &H1b&
%DBPROP_COL_DESCRIPTION                     = &H1c&
%DBPROP_COL_FIXEDLENGTH                     = &Ha7&
%DBPROP_COL_NULLABLE                        = &H1d&
%DBPROP_COL_PRIMARYKEY                      = &H1e&
%DBPROP_COL_UNIQUE                          = &H1f&
%DBPROP_COLUMNDEFINITION                    = &H20&
%DBPROP_COLUMNRESTRICT                      = &H21&
%DBPROP_COMMANDTIMEOUT                      = &H22&
%DBPROP_COMMITPRESERVE                      = &H23&
%DBPROP_CONCATNULLBEHAVIOR                  = &H24&
%DBPROP_CURRENTCATALOG                      = &H25&
%DBPROP_DATASOURCENAME                      = &H26&
%DBPROP_DATASOURCEREADONLY                  = &H27&
%DBPROP_DBMSNAME                            = &H28&
%DBPROP_DBMSVER                             = &H29&
%DBPROP_DEFERRED                            = &H2a&
%DBPROP_DELAYSTORAGEOBJECTS                 = &H2b&
%DBPROP_DSOTHREADMODEL                      = &Ha9&
%DBPROP_GROUPBY                             = &H2c&
%DBPROP_HETEROGENEOUSTABLES                 = &H2d&
%DBPROP_IAccessor                           = &H79&
%DBPROP_IColumnsInfo                        = &H7a&
%DBPROP_IColumnsRowset                      = &H7b&
%DBPROP_IConnectionPointContainer           = &H7c&
%DBPROP_IConvertType                        = &Hc2&
%DBPROP_IRowset                             = &H7e&
%DBPROP_IRowsetChange                       = &H7f&
%DBPROP_IRowsetIdentity                     = &H80&
%DBPROP_IRowsetIndex                        = &H9f&
%DBPROP_IRowsetInfo                         = &H81&
%DBPROP_IRowsetLocate                       = &H82&
%DBPROP_IRowsetResynch                      = &H84&
%DBPROP_IRowsetScroll                       = &H85&
%DBPROP_IRowsetUpdate                       = &H86&
%DBPROP_ISupportErrorInfo                   = &H87&
%DBPROP_ILockBytes                          = &H88&
%DBPROP_ISequentialStream                   = &H89&
%DBPROP_IStorage                            = &H8a&
%DBPROP_IStream                             = &H8b&
%DBPROP_IDENTIFIERCASE                      = &H2e&
%DBPROP_IMMOBILEROWS                        = &H2f&
%DBPROP_INDEX_AUTOUPDATE                    = &H30&
%DBPROP_INDEX_CLUSTERED                     = &H31&
%DBPROP_INDEX_FILLFACTOR                    = &H32&
%DBPROP_INDEX_INITIALSIZE                   = &H33&
%DBPROP_INDEX_NULLCOLLATION                 = &H34&
%DBPROP_INDEX_NULLS                         = &H35&
%DBPROP_INDEX_PRIMARYKEY                    = &H36&
%DBPROP_INDEX_SORTBOOKMARKS                 = &H37&
%DBPROP_INDEX_TEMPINDEX                     = &Ha3&
%DBPROP_INDEX_TYPE                          = &H38&
%DBPROP_INDEX_UNIQUE                        = &H39&
%DBPROP_INIT_DATASOURCE                     = &H3b&
%DBPROP_INIT_HWND                           = &H3c&
%DBPROP_INIT_IMPERSONATION_LEVEL            = &H3d&
%DBPROP_INIT_LCID                           = &Hba&
%DBPROP_INIT_LOCATION                       = &H3e&
%DBPROP_INIT_MODE                           = &H3f&
%DBPROP_INIT_PROMPT                         = &H40&
%DBPROP_INIT_PROTECTION_LEVEL               = &H41&
%DBPROP_INIT_PROVIDERSTRING                 = &Ha0&
%DBPROP_INIT_TIMEOUT                        = &H42&
%DBPROP_LITERALBOOKMARKS                    = &H43&
%DBPROP_LITERALIDENTITY                     = &H44&
%DBPROP_MAXINDEXSIZE                        = &H46&
%DBPROP_MAXOPENROWS                         = &H47&
%DBPROP_MAXPENDINGROWS                      = &H48&
%DBPROP_MAXROWS                             = &H49&
%DBPROP_MAXROWSIZE                          = &H4a&
%DBPROP_MAXROWSIZEINCLUDESBLOB              = &H4b&
%DBPROP_MAXTABLESINSELECT                   = &H4c&
%DBPROP_MAYWRITECOLUMN                      = &H4d&
%DBPROP_MEMORYUSAGE                         = &H4e&
%DBPROP_MULTIPLEPARAMSETS                   = &Hbf&
%DBPROP_MULTIPLERESULTS                     = &Hc4&
%DBPROP_MULTIPLESTORAGEOBJECTS              = &H50&
%DBPROP_MULTITABLEUPDATE                    = &H51&
%DBPROP_NOTIFICATIONGRANULARITY             = &Hc6&
%DBPROP_NOTIFICATIONPHASES                  = &H52&
%DBPROP_NOTIFYCOLUMNSET                     = &Hab&
%DBPROP_NOTIFYROWDELETE                     = &Had&
%DBPROP_NOTIFYROWFIRSTCHANGE                = &Hae&
%DBPROP_NOTIFYROWINSERT                     = &Haf&
%DBPROP_NOTIFYROWRESYNCH                    = &Hb1&
%DBPROP_NOTIFYROWSETCHANGED                 = &Hd3&
%DBPROP_NOTIFYROWSETRELEASE                 = &Hb2&
%DBPROP_NOTIFYROWSETFETCHPOSITIONCHANGE     = &Hb3&
%DBPROP_NOTIFYROWUNDOCHANGE                 = &Hb4&
%DBPROP_NOTIFYROWUNDODELETE                 = &Hb5&
%DBPROP_NOTIFYROWUNDOINSERT                 = &Hb6&
%DBPROP_NOTIFYROWUPDATE                     = &Hb7&
%DBPROP_NULLCOLLATION                       = &H53&
%DBPROP_OLEOBJECTS                          = &H54&
%DBPROP_ORDERBYCOLUMNSINSELECT              = &H55&
%DBPROP_ORDEREDBOOKMARKS                    = &H56&
%DBPROP_OTHERINSERT                         = &H57&
%DBPROP_OTHERUPDATEDELETE                   = &H58&
%DBPROP_OUTPUTPARAMETERAVAILABILITY         = &Hb8&
%DBPROP_OWNINSERT                           = &H59&
%DBPROP_OWNUPDATEDELETE                     = &H5a&
%DBPROP_PERSISTENTIDTYPE                    = &Hb9&
%DBPROP_PREPAREABORTBEHAVIOR                = &H5b&
%DBPROP_PREPARECOMMITBEHAVIOR               = &H5c&
%DBPROP_PROCEDURETERM                       = &H5d&
%DBPROP_PROVIDERNAME                        = &H60&
%DBPROP_PROVIDEROLEDBVER                    = &H61&
%DBPROP_PROVIDERVER                         = &H62&
%DBPROP_QUICKRESTART                        = &H63&
%DBPROP_QUOTEDIDENTIFIERCASE                = &H64&
%DBPROP_REENTRANTEVENTS                     = &H65&
%DBPROP_REMOVEDELETED                       = &H66&
%DBPROP_REPORTMULTIPLECHANGES               = &H67&
%DBPROP_RETURNPENDINGINSERTS                = &Hbd&
%DBPROP_ROWRESTRICT                         = &H68&
%DBPROP_ROWSETCONVERSIONSONCOMMAND          = &Hc0&
%DBPROP_ROWTHREADMODEL                      = &H69&
%DBPROP_SCHEMATERM                          = &H6a&
%DBPROP_SCHEMAUSAGE                         = &H6b&
%DBPROP_SERVERCURSOR                        = &H6c&
%DBPROP_SESS_AUTOCOMMITISOLEVELS            = &Hbe&
%DBPROP_SQLSUPPORT                          = &H6d&
%DBPROP_STRONGIDENTITY                      = &H77&
%DBPROP_STRUCTUREDSTORAGE                   = &H6f&
%DBPROP_SUBQUERIES                          = &H70&
%DBPROP_SUPPORTEDTXNDDL                     = &Ha1&
%DBPROP_SUPPORTEDTXNISOLEVELS               = &H71&
%DBPROP_SUPPORTEDTXNISORETAIN               = &H72&
%DBPROP_TABLETERM                           = &H73&
%DBPROP_TBL_TEMPTABLE                       = &H8c&
%DBPROP_TRANSACTEDOBJECT                    = &H74&
%DBPROP_UPDATABILITY                        = &H75&
%DBPROP_USERNAME                            = &H76&

' DBPROPENUM15
%DBPROP_FILTERCOMPAREOPS                    = &Hd1&
%DBPROP_FINDCOMPAREOPS                      = &Hd2&
%DBPROP_IChapteredRowset                    = &Hca&
%DBPROP_IDBAsynchStatus                     = &Hcb&
%DBPROP_IRowsetFind                         = &Hcc&
%DBPROP_IRowsetView                         = &Hd4&
%DBPROP_IViewChapter                        = &Hd5&
%DBPROP_IViewFilter                         = &Hd6&
%DBPROP_IViewRowset                         = &Hd7&
%DBPROP_IViewSort                           = &Hd8&
%DBPROP_INIT_ASYNCH                         = &Hc8&
%DBPROP_MAXOPENCHAPTERS                     = &Hc7&
%DBPROP_MAXORSINFILTER                      = &Hcd&
%DBPROP_MAXSORTCOLUMNS                      = &Hce&
%DBPROP_ROWSET_ASYNCH                       = &Hc9&
%DBPROP_SORTONINDEX                         = &Hcf&

' DBPROPENUM20
%DBPROP_IMultipleResults                    = &Hd9&
%DBPROP_DATASOURCE_TYPE                     = &Hfb&
%MDPROP_AXES                                = &Hfc&
%MDPROP_FLATTENING_SUPPORT                  = &Hfd&
%MDPROP_MDX_JOINCUBES                       = &Hfe&
%MDPROP_NAMED_LEVELS                        = &Hff&
%MDPROP_RANGEROWSET                         = &H100&
%MDPROP_MDX_SLICER                          = &Hda&
%MDPROP_MDX_CUBEQUALIFICATION               = &Hdb&
%MDPROP_MDX_OUTERREFERENCE                  = &Hdc&
%MDPROP_MDX_QUERYBYPROPERTY                 = &Hdd&
%MDPROP_MDX_CASESUPPORT                     = &Hde&
%MDPROP_MDX_STRING_COMPOP                   = &He0&
%MDPROP_MDX_DESCFLAGS                       = &He1&
%MDPROP_MDX_SET_FUNCTIONS                   = &He2&
%MDPROP_MDX_MEMBER_FUNCTIONS                = &He3&
%MDPROP_MDX_NUMERIC_FUNCTIONS               = &He4&
%MDPROP_MDX_FORMULAS                        = &He5&
%MDPROP_MDX_AGGREGATECELL_UPDATE            = &He6&
%DBPROP_ACCESSORDER                         = &He7&
%DBPROP_BOOKMARKINFO                        = &He8&
%DBPROP_INIT_CATALOG                        = &He9&
%DBPROP_ROW_BULKOPS                         = &Hea&
%DBPROP_PROVIDERFRIENDLYNAME                = &Heb&
%DBPROP_LOCKMODE                            = &Hec&
%DBPROP_MULTIPLECONNECTIONS                 = &Hed&
%DBPROP_UNIQUEROWS                          = &Hee&
%DBPROP_SERVERDATAONINSERT                  = &Hef&
%DBPROP_STORAGEFLAGS                        = &Hf0&
%DBPROP_CONNECTIONSTATUS                    = &Hf4&
%DBPROP_ALTERCOLUMN                         = &Hf5&
%DBPROP_COLUMNLCID                          = &Hf6&
%DBPROP_RESETDATASOURCE                     = &Hf7&
%DBPROP_INIT_OLEDBSERVICES                  = &Hf8&
%DBPROP_IRowsetRefresh                      = &Hf9&
%DBPROP_SERVERNAME                          = &Hfa&
%DBPROP_IParentRowset                       = &H101&
%DBPROP_HIDDENCOLUMNS                       = &H102&
%DBPROP_PROVIDERMEMORY                      = &H103&
%DBPROP_CLIENTCURSOR                        = &H104&

%DBPROP_PROVIDERFILENAME                    = %DBPROP_PROVIDERNAME
%DBPROP_SERVER_NAME                         = %DBPROP_SERVERNAME

' DBPROPENUM21
%DBPROP_TRUSTEE_USERNAME                    = &Hf1&
%DBPROP_TRUSTEE_AUTHENTICATION              = &Hf2&
%DBPROP_TRUSTEE_NEWAUTHENTICATION           = &Hf3&
%DBPROP_IRow                                = &H107&
%DBPROP_IRowChange                          = &H108&
%DBPROP_IRowSchemaChange                    = &H109&
%DBPROP_IGetRow                             = &H10a&
%DBPROP_IScopedOperations                   = &H10b&
%DBPROP_IBindResource                       = &H10c&
%DBPROP_ICreateRow                          = &H10d&
%DBPROP_INIT_BINDFLAGS                      = &H10e&
%DBPROP_INIT_LOCKOWNER                      = &H10f&
%DBPROP_GENERATEURL                         = &H111&
%DBPROP_IDBBinderProperties                 = &H112&
%DBPROP_IColumnsInfo2                       = &H113&
%DBPROP_IRegisterProvider                   = &H114&
%DBPROP_IGetSession                         = &H115&
%DBPROP_IGetSourceRow                       = &H116&
%DBPROP_IRowsetCurrentIndex                 = &H117&
%DBPROP_OPENROWSETSUPPORT                   = &H118&
%DBPROP_COL_ISLONG                          = &H119&

' DBPROPENUM25
%DBPROP_COL_SEED                            = &H11a&
%DBPROP_COL_INCREMENT                       = &H11b&
%DBPROP_INIT_GENERALTIMEOUT                 = &H11c&
%DBPROP_COMSERVICES                         = &H11d&

' DBPROPENUM26
%DBPROP_OUTPUTSTREAM                        = &H11e&
%DBPROP_OUTPUTENCODING                      = &H11f&
%DBPROP_TABLESTATISTICS                     = &H120&
%DBPROP_SKIPROWCOUNTRESULTS                 = &H123&
%DBPROP_IRowsetBookmark                     = &H124&
%MDPROP_VISUALMODE                          = &H125&

' DBPROPENUMDEPRECATED
%DBPROP_IRowsetExactScroll                  = &H9a&
%DBPROP_MARSHALLABLE                        = &Hc5&
%DBPROP_FILTEROPS                           = &Hd0&

%DBPROPVAL_BMK_NUMERIC                      = &H00000001&
%DBPROPVAL_BMK_KEY                          = &H00000002&
%DBPROPVAL_CL_START                         = &H00000001&
%DBPROPVAL_CL_END                           = &H00000002&
%DBPROPVAL_CU_DML_STATEMENTS                = &H00000001&
%DBPROPVAL_CU_TABLE_DEFINITION              = &H00000002&
%DBPROPVAL_CU_INDEX_DEFINITION              = &H00000004&
%DBPROPVAL_CU_PRIVILEGE_DEFINITION          = &H00000008&
%DBPROPVAL_CD_NOTNULL                       = &H00000001&
%DBPROPVAL_CB_NULL                          = &H00000001&
%DBPROPVAL_CB_NON_NULL                      = &H00000002&
%DBPROPVAL_FU_NOT_SUPPORTED                 = &H00000001&
%DBPROPVAL_FU_COLUMN                        = &H00000002&
%DBPROPVAL_FU_TABLE                         = &H00000004&
%DBPROPVAL_FU_CATALOG                       = &H00000008&
%DBPROPVAL_GB_NOT_SUPPORTED                 = &H00000001&
%DBPROPVAL_GB_EQUALS_SELECT                 = &H00000002&
%DBPROPVAL_GB_CONTAINS_SELECT               = &H00000004&
%DBPROPVAL_GB_NO_RELATION                   = &H00000008&
%DBPROPVAL_HT_DIFFERENT_CATALOGS            = &H00000001&
%DBPROPVAL_HT_DIFFERENT_PROVIDERS           = &H00000002&
%DBPROPVAL_IC_UPPER                         = &H00000001&
%DBPROPVAL_IC_LOWER                         = &H00000002&
%DBPROPVAL_IC_SENSITIVE                     = &H00000004&
%DBPROPVAL_IC_MIXED                         = &H00000008&

%DBPROPVAL_LM_NONE                          = &H00000001&
%DBPROPVAL_LM_READ                          = &H00000002&
%DBPROPVAL_LM_INTENT                        = &H00000004&
%DBPROPVAL_LM_RITE                          = &H00000008&

%DBPROPVAL_NP_OKTODO                        = &H00000001&
%DBPROPVAL_NP_ABOUTTODO                     = &H00000002&
%DBPROPVAL_NP_SYNCHAFTER                    = &H00000004&
%DBPROPVAL_NP_FAILEDTODO                    = &H00000008&
%DBPROPVAL_NP_DIDEVENT                      = &H00000010&
%DBPROPVAL_NC_END                           = &H00000001&
%DBPROPVAL_NC_HIGH                          = &H00000002&
%DBPROPVAL_NC_LOW                           = &H00000004&
%DBPROPVAL_NC_START                         = &H00000008&
%DBPROPVAL_OO_BLOB                          = &H00000001&
%DBPROPVAL_OO_IPERSIST                      = &H00000002&
%DBPROPVAL_CB_DELETE                        = &H00000001&
%DBPROPVAL_CB_PRESERVE                      = &H00000002&
%DBPROPVAL_SU_DML_STATEMENTS                = &H00000001&
%DBPROPVAL_SU_TABLE_DEFINITION              = &H00000002&
%DBPROPVAL_SU_INDEX_DEFINITION              = &H00000004&
%DBPROPVAL_SU_PRIVILEGE_DEFINITION          = &H00000008&
%DBPROPVAL_SQ_CORRELATEDSUBQUERIES          = &H00000001&
%DBPROPVAL_SQ_COMPARISON                    = &H00000002&
%DBPROPVAL_SQ_EXISTS                        = &H00000004&
%DBPROPVAL_SQ_IN                            = &H00000008&
%DBPROPVAL_SQ_QUANTIFIED                    = &H00000010&
%DBPROPVAL_SS_ISEQUENTIALSTREAM             = &H00000001&
%DBPROPVAL_SS_ISTREAM                       = &H00000002&
%DBPROPVAL_SS_ISTORAGE                      = &H00000004&
%DBPROPVAL_SS_ILOCKBYTES                    = &H00000008&
%DBPROPVAL_TI_CHAOS                         = &H00000010&
%DBPROPVAL_TI_READUNCOMMITTED               = &H00000100&
%DBPROPVAL_TI_BROWSE                        = &H00000100&
%DBPROPVAL_TI_CURSORSTABILITY               = &H00001000&
%DBPROPVAL_TI_READCOMMITTED                 = &H00001000&
%DBPROPVAL_TI_REPEATABLEREAD                = &H00010000&
%DBPROPVAL_TI_SERIALIZABLE                  = &H00100000&
%DBPROPVAL_TI_ISOLATED                      = &H00100000&
%DBPROPVAL_TR_COMMIT_DC                     = &H00000001&
%DBPROPVAL_TR_COMMIT                        = &H00000002&
%DBPROPVAL_TR_COMMIT_NO                     = &H00000004&
%DBPROPVAL_TR_ABORT_DC                      = &H00000008&
%DBPROPVAL_TR_ABORT                         = &H00000010&
%DBPROPVAL_TR_ABORT_NO                      = &H00000020&
%DBPROPVAL_TR_DONTCARE                      = &H00000040&
%DBPROPVAL_TR_BOTH                          = &H00000080&
%DBPROPVAL_TR_NONE                          = &H00000100&
%DBPROPVAL_TR_OPTIMISTIC                    = &H00000200&
%DBPROPVAL_RT_FREETHREAD                    = &H00000001&
%DBPROPVAL_RT_APTMTTHREAD                   = &H00000002&
%DBPROPVAL_RT_SINGLETHREAD                  = &H00000004&
%DBPROPVAL_UP_CHANGE                        = &H00000001&
%DBPROPVAL_UP_DELETE                        = &H00000002&
%DBPROPVAL_UP_INSERT                        = &H00000004&
%DBPROPVAL_SQL_NONE                         = &H00000000&
%DBPROPVAL_SQL_ODBC_MINIMUM                 = &H00000001&
%DBPROPVAL_SQL_ODBC_CORE                    = &H00000002&
%DBPROPVAL_SQL_ODBC_EXTENDED                = &H00000004&
%DBPROPVAL_SQL_ANSI89_IEF                   = &H00000008&
%DBPROPVAL_SQL_ANSI92_ENTRY                 = &H00000010&
%DBPROPVAL_SQL_FIPS_TRANSITIONAL            = &H00000020&
%DBPROPVAL_SQL_ANSI92_INTERMEDIATE          = &H00000040&
%DBPROPVAL_SQL_ANSI92_FULL                  = &H00000080&
%DBPROPVAL_SQL_ESCAPECLAUSES                = &H00000100&
%DBPROPVAL_IT_BTREE                         = &H00000001&
%DBPROPVAL_IT_HASH                          = &H00000002&
%DBPROPVAL_IT_CONTENT                       = &H00000003&
%DBPROPVAL_IT_OTHER                         = &H00000004&
%DBPROPVAL_IN_DISALLOWNULL                  = &H00000001&
%DBPROPVAL_IN_IGNORENULL                    = &H00000002&
%DBPROPVAL_IN_IGNOREANYNULL                 = &H00000004&
%DBPROPVAL_TC_NONE                          = &H00000000&
%DBPROPVAL_TC_DML                           = &H00000001&
%DBPROPVAL_TC_DDL_COMMIT                    = &H00000002&
%DBPROPVAL_TC_DDL_IGNORE                    = &H00000004&
%DBPROPVAL_TC_ALL                           = &H00000008&
%DBPROPVAL_NP_OKTODO                        = &H00000001&
%DBPROPVAL_NP_ABOUTTODO                     = &H00000002&
%DBPROPVAL_NP_SYNCHAFTER                    = &H00000004&
%DBPROPVAL_OA_NOTSUPPORTED                  = &H00000001&
%DBPROPVAL_OA_ATEXECUTE                     = &H00000002&
%DBPROPVAL_OA_ATROWRELEASE                  = &H00000004&
%DBPROPVAL_MR_NOTSUPPORTED                  = &H00000000&
%DBPROPVAL_MR_SUPPORTED                     = &H00000001&
%DBPROPVAL_MR_CONCURRENT                    = &H00000002&
%DBPROPVAL_PT_GUID_NAME                     = &H00000001&
%DBPROPVAL_PT_GUID_PROPID                   = &H00000002&
%DBPROPVAL_PT_NAME                          = &H00000004&
%DBPROPVAL_PT_GUID                          = &H00000008&
%DBPROPVAL_PT_PROPID                        = &H00000010&
%DBPROPVAL_PT_PGUID_NAME                    = &H00000020&
%DBPROPVAL_PT_PGUID_PROPID                  = &H00000040&
%DBPROPVAL_NT_SINGLEROW                     = &H00000001&
%DBPROPVAL_NT_MULTIPLEROWS                  = &H00000002&

%DBPROPVAL_ASYNCH_INITIALIZE                = &H00000001&
%DBPROPVAL_ASYNCH_SEQUENTIALPOPULATION      = &H00000002&
%DBPROPVAL_ASYNCH_RANDOMPOPULATION          = &H00000004&
%DBPROPVAL_OP_EQUAL                         = &H00000001&
%DBPROPVAL_OP_RELATIVE                      = &H00000002&
%DBPROPVAL_OP_STRING                        = &H00000004&
%DBPROPVAL_CO_EQUALITY                      = &H00000001&
%DBPROPVAL_CO_STRING                        = &H00000002&
%DBPROPVAL_CO_CASESENSITIVE                 = &H00000004&
%DBPROPVAL_CO_CASEINSENSITIVE               = &H00000008&

%DBPROPVAL_CO_CONTAINS                      = &H00000010&
%DBPROPVAL_CO_BEGINSWITH                    = &H00000020&
%DBPROPVAL_ASYNCH_BACKGROUNDPOPULATION      = &H00000008&
%DBPROPVAL_ASYNCH_PREPOPULATE               = &H00000010&
%DBPROPVAL_ASYNCH_POPULATEONDEMAND          = &H00000020&
%DBPROPVAL_LM_NONE                          = &H00000001&
%DBPROPVAL_LM_SINGLEROW                     = &H00000002&
%DBPROPVAL_SQL_SUBMINIMUM                   = &H00000200&
%DBPROPVAL_DST_TDP                          = &H00000001&
%DBPROPVAL_DST_MDP                          = &H00000002&
%DBPROPVAL_DST_TDPANDMDP                    = &H00000003&
%MDPROPVAL_AU_UNSUPPORTED                   = &H00000000&
%MDPROPVAL_AU_UNCHANGED                     = &H00000001&
%MDPROPVAL_AU_UNKNOWN                       = &H00000002&
%MDPROPVAL_MF_WITH_CALCMEMBERS              = &H00000001&
%MDPROPVAL_MF_WITH_NAMEDSETS                = &H00000002&
%MDPROPVAL_MF_CREATE_CALCMEMBERS            = &H00000004&
%MDPROPVAL_MF_CREATE_NAMEDSETS              = &H00000008&
%MDPROPVAL_MF_SCOPE_SESSION                 = &H00000010&
%MDPROPVAL_MF_SCOPE_GLOBAL                  = &H00000020&
%MDPROPVAL_MMF_COUSIN                       = &H00000001&
%MDPROPVAL_MMF_PARALLELPERIOD               = &H00000002&
%MDPROPVAL_MMF_OPENINGPERIOD                = &H00000004&
%MDPROPVAL_MMF_CLOSINGPERIOD                = &H00000008&
%MDPROPVAL_MNF_MEDIAN                       = &H00000001&
%MDPROPVAL_MNF_VAR                          = &H00000002&
%MDPROPVAL_MNF_STDDEV                       = &H00000004&
%MDPROPVAL_MNF_RANK                         = &H00000008&
%MDPROPVAL_MNF_AGGREGATE                    = &H00000010&
%MDPROPVAL_MNF_COVARIANCE                   = &H00000020&
%MDPROPVAL_MNF_CORRELATION                  = &H00000040&
%MDPROPVAL_MNF_LINREGSLOPE                  = &H00000080&
%MDPROPVAL_MNF_LINREGVARIANCE               = &H00000100&
%MDPROPVAL_MNF_LINREG2                      = &H00000200&
%MDPROPVAL_MNF_LINREGPOINT                  = &H00000400&
%MDPROPVAL_MNF_DRILLDOWNLEVEL               = &H00000800&
%MDPROPVAL_MNF_DRILLDOWNMEMBERTOP           = &H00001000&
%MDPROPVAL_MNF_DRILLDOWNMEMBERBOTTOM        = &H00002000&
%MDPROPVAL_MNF_DRILLDOWNLEVELTOP            = &H00004000&
%MDPROPVAL_MNF_DRILLDOWNLEVELBOTTOM         = &H00008000&
%MDPROPVAL_MNF_DRILLUPMEMBER                = &H00010000&
%MDPROPVAL_MNF_DRILLUPLEVEL                 = &H00020000&
%MDPROPVAL_MMF_COUSIN                       = &H00000001&
%MDPROPVAL_MMF_PARALLELPERIOD               = &H00000002&
%MDPROPVAL_MMF_OPENINGPERIOD                = &H00000004&
%MDPROPVAL_MMF_CLOSINGPERIOD                = &H00000008&
%MDPROPVAL_MSF_TOPPERCENT                   = &H00000001&
%MDPROPVAL_MSF_BOTTOMPERCENT                = &H00000002&
%MDPROPVAL_MSF_TOPSUM                       = &H00000004&
%MDPROPVAL_MSF_BOTTOMSUM                    = &H00000008&
%MDPROPVAL_MSF_PERIODSTODATE                = &H00000010&
%MDPROPVAL_MSF_LASTPERIODS                  = &H00000020&
%MDPROPVAL_MSF_YTD                          = &H00000040&
%MDPROPVAL_MSF_QTD                          = &H00000080&
%MDPROPVAL_MSF_MTD                          = &H00000100&
%MDPROPVAL_MSF_WTD                          = &H00000200&
%MDPROPVAL_MSF_DRILLDOWNMEMBBER             = &H00000400&
%MDPROPVAL_MSF_DRILLDOWNLEVEL               = &H00000800&
%MDPROPVAL_MSF_DRILLDOWNMEMBERTOP           = &H00001000&
%MDPROPVAL_MSF_DRILLDOWNMEMBERBOTTOM        = &H00002000&
%MDPROPVAL_MSF_DRILLDOWNLEVELTOP            = &H00004000&
%MDPROPVAL_MSF_DRILLDOWNLEVELBOTTOM         = &H00008000&
%MDPROPVAL_MSF_DRILLUPMEMBER                = &H00010000&
%MDPROPVAL_MSF_DRILLUPLEVEL                 = &H00020000&
%MDPROPVAL_MSF_TOGGLEDRILLSTATE             = &H00040000&

' // values FOR MDPROP_MDX_DESCFLAGS
%MDPROPVAL_MD_SELF                          = &H00000001&
%MDPROPVAL_MD_BEFORE                        = &H00000002&
%MDPROPVAL_MD_AFTER                         = &H00000004&

' // values FOR MDPROP_MDX_STRING_COMPOP
%MDPROPVAL_MSC_LESSTHAN                     = &H00000001&
%MDPROPVAL_MSC_GREATERTHAN                  = &H00000002&
%MDPROPVAL_MSC_LESSTHANEQUAL                = &H00000004&
%MDPROPVAL_MSC_GREATERTHANEQUAL             = &H00000008&
%MDPROPVAL_MC_SINGLECASE                    = &H00000001&
%MDPROPVAL_MC_SEARCHEDCASE                  = &H00000002&
%MDPROPVAL_MOQ_OUTERREFERENCE               = &H00000001&
%MDPROPVAL_MOQ_DATASOURCE_CUBE              = &H00000001&
%MDPROPVAL_MOQ_CATALOG_CUBE                 = &H00000002&
%MDPROPVAL_MOQ_SCHEMA_CUBE                  = &H00000004&
%MDPROPVAL_MOQ_CUBE_DIM                     = &H00000008&
%MDPROPVAL_MOQ_DIM_HIER                     = &H00000010&
%MDPROPVAL_MOQ_DIMHIER_LEVEL                = &H00000020&
%MDPROPVAL_MOQ_LEVEL_MEMBER                 = &H00000040&
%MDPROPVAL_MOQ_MEMBER_MEMBER                = &H00000080&
%MDPROPVAL_FS_FULL_SUPPORT                  = &H00000001&
%MDPROPVAL_FS_GENERATED_COLUMN              = &H00000002&
%MDPROPVAL_FS_GENERATED_DIMENSION           = &H00000003&
%MDPROPVAL_FS_NO_SUPPORT                    = &H00000004&
%MDPROPVAL_NL_NAMEDLEVELS                   = &H00000001&
%MDPROPVAL_NL_NUMBEREDLEVELS                = &H00000002&
%MDPROPVAL_MJC_SINGLECUBE                   = &H00000001&
%MDPROPVAL_MJC_MULTICUBES                   = &H00000002&
%MDPROPVAL_MJC_IMPLICITCUBE                 = &H00000004&
%MDPROPVAL_RR_NORANGEROWSET                 = &H00000001&
%MDPROPVAL_RR_READONLY                      = &H00000002&
%MDPROPVAL_RR_UPDATE                        = &H00000004&
%MDPROPVAL_MS_MULTIPLETUPLES                = &H00000001&
%MDPROPVAL_MS_SINGLETUPLE                   = &H00000002&
%DBPROPVAL_AO_SEQUENTIAL                    = &H00000000&
%DBPROPVAL_AO_SEQUENTIALSTORAGEOBJECTS      = &H00000001&
%DBPROPVAL_AO_RANDOM                        = &H00000002&
%DBPROPVAL_BD_ROWSET                        = &H00000000&
%DBPROPVAL_BD_INTRANSACTION                 = &H00000001&
%DBPROPVAL_BD_XTRANSACTION                  = &H00000002&
%DBPROPVAL_BD_REORGANIZATION                = &H00000003&

%BMK_DURABILITY_ROWSET                      = %DBPROPVAL_BD_ROWSET
%BMK_DURABILITY_INTRANSACTION               = %DBPROPVAL_BD_INTRANSACTION
%BMK_DURABILITY_XTRANSACTION                = %DBPROPVAL_BD_XTRANSACTION
%BMK_DURABILITY_REORGANIZATION              = %DBPROPVAL_BD_REORGANIZATION

%DBPROPVAL_BO_NOLOG                         = &H00000000&
%DBPROPVAL_BO_NOINDEXUPDATE                 = &H00000001&
%DBPROPVAL_BO_REFINTEGRITY                  = &H00000002&

'#if !defined(_WINBASE_)
%OF_READ                                    = &H00000000
%OF_WRITE                                   = &H00000001
%OF_READWRITE                               = &H00000002
%OF_SHARE_COMPAT                            = &H00000000
%OF_SHARE_EXCLUSIVE                         = &H00000010
%OF_SHARE_DENY_WRITE                        = &H00000020
%OF_SHARE_DENY_READ                         = &H00000030
%OF_SHARE_DENY_NONE                         = &H00000040
%OF_PARSE                                   = &H00000100
%OF_DELETE                                  = &H00000200
%OF_VERIFY                                  = &H00000400
%OF_CANCEL                                  = &H00000800
%OF_CREATE                                  = &H00001000
%OF_PROMPT                                  = &H00002000
%OF_EXIST                                   = &H00004000
%OF_REOPEN                                  = &H00008000
'#endif // !_WINBASE_

%DBPROPVAL_STGM_READ                        = %OF_READ
%DBPROPVAL_STGM_WRITE                       = %OF_WRITE
%DBPROPVAL_STGM_READWRITE                   = %OF_READWRITE
%DBPROPVAL_STGM_SHARE_DENY_NONE             = %OF_SHARE_DENY_NONE
%DBPROPVAL_STGM_SHARE_DENY_READ             = %OF_SHARE_DENY_READ
%DBPROPVAL_STGM_SHARE_DENY_WRITE            = %OF_SHARE_DENY_WRITE
%DBPROPVAL_STGM_SHARE_EXCLUSIVE             = %OF_SHARE_EXCLUSIVE

%DBPROPVAL_STGM_DIRECT                      = &H00010000&
%DBPROPVAL_STGM_TRANSACTED                  = &H00020000&
%DBPROPVAL_STGM_CREATE                      = %OF_CREATE
%DBPROPVAL_STGM_CONVERT                     = &H00040000&
%DBPROPVAL_STGM_FAILIFTHERE                 = &H00080000&
%DBPROPVAL_STGM_PRIORITY                    = &H00100000&
%DBPROPVAL_STGM_DELETEONRELEASE             = &H00200000&
%DBPROPVAL_GB_COLLATE                       = &H00000010&
%DBPROPVAL_CS_UNINITIALIZED                 = &H00000000&
%DBPROPVAL_CS_INITIALIZED                   = &H00000001&
%DBPROPVAL_CS_COMMUNICATIONFAILURE          = &H00000002&
%DBPROPVAL_RD_RESETALL                      = &Hffffffff&
%DBPROPVAL_OS_RESOURCEPOOLING               = &H00000001&
%DBPROPVAL_OS_TXNENLISTMENT                 = &H00000002&
%DBPROPVAL_OS_CLIENTCURSOR                  = &H00000004&
%DBPROPVAL_OS_ENABLEALL                     = &Hffffffff&
%DBPROPVAL_BI_CROSSROWSET                   = &H00000001&

%MDPROPVAL_NL_SCHEMAONLY                    = &H00000004&
%DBPROPVAL_OS_DISABLEALL                    = &H00000000&
%DBPROPVAL_OO_ROWOBJECT                     = &H00000004&
%DBPROPVAL_OO_SCOPED                        = &H00000008&
%DBPROPVAL_OO_DIRECTBIND                    = &H00000010&
%DBPROPVAL_DST_DOCSOURCE                    = &H00000004&
%DBPROPVAL_GU_NOTSUPPORTED                  = &H00000001&
%DBPROPVAL_GU_SUFFIX                        = &H00000002&
%DB_BINDFLAGS_DELAYFETCHCOLUMNS             = &H00000001&
%DB_BINDFLAGS_DELAYFETCHSTREAM              = &H00000002&
%DB_BINDFLAGS_RECURSIVE                     = &H00000004&
%DB_BINDFLAGS_OUTPUT                        = &H00000008&
%DB_BINDFLAGS_COLLECTION                    = &H00000010&
%DB_BINDFLAGS_OPENIFEXISTS                  = &H00000020&
%DB_BINDFLAGS_OVERWRITE                     = &H00000040&
%DB_BINDFLAGS_ISSTRUCTUREDDOCUMENT          = &H00000080&
%DBPROPVAL_ORS_TABLE                        = &H00000000&
%DBPROPVAL_ORS_INDEX                        = &H00000001&
%DBPROPVAL_ORS_INTEGRATEDINDEX              = &H00000002&
%DBPROPVAL_TC_DDL_LOCK                      = &H00000010&
%DBPROPVAL_ORS_STOREDPROC                   = &H00000004&
%DBPROPVAL_IN_ALLOWNULL                     = &H00000000&

%DBPROPVAL_OO_SINGLETON                     = &H00000020&
%DBPROPVAL_OS_AGR_AFTERSESSION              = &H00000008&
%DBPROPVAL_CM_TRANSACTIONS                  = &H00000001&

%DBPROPVAL_TS_CARDINALITY                   = &H00000001&
%DBPROPVAL_TS_HISTOGRAM                     = &H00000002&
%DBPROPVAL_ORS_HISTOGRAM                    = &H00000008&
%MDPROPVAL_VISUAL_MODE_DEFAULT              = &H00000000&
%MDPROPVAL_VISUAL_MODE_VISUAL               = &H00000001&
%MDPROPVAL_VISUAL_MODE_VISUAL_OFF           = &H00000002&

%DB_IMP_LEVEL_ANONYMOUS                     = &H00
%DB_IMP_LEVEL_IDENTIFY                      = &H01
%DB_IMP_LEVEL_IMPERSONATE                   = &H02
%DB_IMP_LEVEL_DELEGATE                      = &H03
%DBPROMPT_PROMPT                            = &H01
%DBPROMPT_COMPLETE                          = &H02
%DBPROMPT_COMPLETEREQUIRED                  = &H03
%DBPROMPT_NOPROMPT                          = &H04
%DB_PROT_LEVEL_NONE                         = &H00
%DB_PROT_LEVEL_CONNECT                      = &H01
%DB_PROT_LEVEL_CALL                         = &H02
%DB_PROT_LEVEL_PKT                          = &H03
%DB_PROT_LEVEL_PKT_INTEGRITY                = &H04
%DB_PROT_LEVEL_PKT_PRIVACY                  = &H05
%DB_MODE_READ                               = &H01
%DB_MODE_WRITE                              = &H02
%DB_MODE_READWRITE                          = &H03
%DB_MODE_SHARE_DENY_READ                    = &H04
%DB_MODE_SHARE_DENY_WRITE                   = &H08
%DB_MODE_SHARE_EXCLUSIVE                    = &H0c
%DB_MODE_SHARE_DENY_NONE                    = &H10
%DBCOMPUTEMODE_COMPUTED                     = &H01
%DBCOMPUTEMODE_DYNAMIC                      = &H02
%DBCOMPUTEMODE_NOTCOMPUTED                  = &H03
%DBPROPVAL_DF_INITIALLY_DEFERRED            = &H01
%DBPROPVAL_DF_INITIALLY_IMMEDIATE           = &H02
%DBPROPVAL_DF_NOT_DEFERRABLE                = &H03

' // Size = 12 bytes
TYPE DBPARAMS DWORD
   pData      AS DWORD   ' void *
   cParamSets AS DWORD   ' DB_UPARAMS
   hAccessor  AS DWORD   ' HACCESSOR
END TYPE

'typedef DWORD DBPARAMFLAGS;

' DBPARAMFLAGSENUM
%DBPARAMFLAGS_ISINPUT                       = &H1
%DBPARAMFLAGS_ISOUTPUT                      = &H2
%DBPARAMFLAGS_ISSIGNED                      = &H10
%DBPARAMFLAGS_ISNULLABLE                    = &H40
%DBPARAMFLAGS_ISLONG                        = &H80

' DBPARAMFLAGSENUM20
%DBPARAMFLAGS_SCALEISNEGATIVE               = &H100

' // Size = 24 bytes
TYPE DBPARAMINFO BYTE
   dwFlags     AS DWORD          ' DBPARAMFLAGS
   iOrdinal    AS DWORD          ' DBORDINAL
   pwszName    AS WSTRINGZ PTR   ' LPOLESTR
   pTypeInfo   AS DWORD          ' ITypeInfo *
   ulParamSize AS DWORD          ' DBLENGTH
   wType       AS WORD           ' DBTYPE
   bPrecision  AS BYTE           ' BYTE
   bScale      AS BYTE           ' BYTE
END TYPE

'typedef DWORD DBPROPID;

' // Size = 24 bytes
TYPE DBPROPIDSET DWORD
   rgPropertyIDs   AS DWORD   ' DBPROPID *
   cPropertyIDs    AS DWORD   ' ULONG
   guidPropertySet AS GUID    ' GUID
END TYPE

'typedef DWORD DBPROPFLAGS;

' DBPROPFLAGSENUM
%DBPROPFLAGS_NOTSUPPORTED                   = 0
%DBPROPFLAGS_COLUMN                         = &H1
%DBPROPFLAGS_DATASOURCE                     = &H2
%DBPROPFLAGS_DATASOURCECREATE               = &H4
%DBPROPFLAGS_DATASOURCEINFO                 = &H8
%DBPROPFLAGS_DBINIT                         = &H10
%DBPROPFLAGS_INDEX                          = &H20
%DBPROPFLAGS_ROWSET                         = &H40
%DBPROPFLAGS_TABLE                          = &H80
%DBPROPFLAGS_COLUMNOK                       = &H100
%DBPROPFLAGS_READ                           = &H200
%DBPROPFLAGS_WRITE                          = &H400
%DBPROPFLAGS_REQUIRED                       = &H800
%DBPROPFLAGS_SESSION                        = &H1000

' DBPROPFLAGSENUM21
%DBPROPFLAGS_TRUSTEE                        = &H2000

' DBPROPFLAGSENUM25
%DBPROPFLAGS_VIEW                           = &H4000

' DBPROPFLAGSENUM26
%DBPROPFLAGS_STREAM                         = &H8000

' // Size = 30 bytes
TYPE DBPROPINFO WORD
   pwszDescription AS WSTRINGZ PTR   ' LPOLESTR
   dwPropertyID    AS DWORD          ' DBPROPID
   dwFlags         AS DWORD          ' DBPROPFLAGS
   vtType          AS WORD           ' VARTYPE
   vValues         AS tagVARIANT     ' VARIANT
END TYPE

' // Size = 24 bytes
TYPE DBPROPINFOSET DWORD
   rgPropertyInfos AS DBPROPINFO PTR   ' PDBPROPINFO
   cPropertyInfos  AS DWORD            ' ULONG
   guidPropertySet AS GUID             ' GUID
END TYPE

'typedef DWORD DBPROPOPTIONS;

'// DBPROPOPTIONS_SETIFCHEAP is deprecated; use DBPROPOPTIONS_OPTIONAL instead.

' DBPROPOPTIONSENUM
%DBPROPOPTIONS_REQUIRED                     = 0
%DBPROPOPTIONS_SETIFCHEAP                   = &H1
'// DBPROPOPTIONS_SETIFCHEAP is deprecated; use DBPROPOPTIONS_OPTIONAL instead.
%DBPROPOPTIONS_OPTIONAL                     = &H1

'typedef DWORD DBPROPSTATUS;

' DBPROPSTATUSENUM
%DBPROPSTATUS_OK                            = 0
%DBPROPSTATUS_NOTSUPPORTED                  = 1
%DBPROPSTATUS_BADVALUE                      = 2
%DBPROPSTATUS_BADOPTION                     = 3
%DBPROPSTATUS_BADCOLUMN                     = 4
%DBPROPSTATUS_NOTALLSETTABLE                = 5
%DBPROPSTATUS_NOTSETTABLE                   = 6
%DBPROPSTATUS_NOTSET                        = 7
%DBPROPSTATUS_CONFLICTING                   = 8

' DBPROPSTATUSENUM21
%DBPROPSTATUS_NOTAVAILAVLE                  = 9

' // Size = 52 bytes
TYPE DBPROP DWORD
   dwPropertyID AS DWORD        ' DBPROPID
   dwOptions    AS DWORD        ' DBPROPOPTIONS
   dwStatus     AS DWORD        ' DBPROPSTATUS
   colid        AS DBID         ' DBID
   vValue       AS tagVARIANT   ' VARIANT
END TYPE

' // Size = 24 bytes
TYPE DBPROPSET DWORD
   rgProperties    AS DBPROP PTR   ' DBPROP *
   cProperties     AS DWORD        ' ULONG
   guidPropertySet AS GUID         ' GUID
END TYPE

%DBPARAMTYPE_INPUT                          = &H01
%DBPARAMTYPE_INPUTOUTPUT                    = &H02
%DBPARAMTYPE_OUTPUT                         = &H03
%DBPARAMTYPE_RETURNVALUE                    = &H04
%DB_PT_UNKNOWN                              = &H01
%DB_PT_PROCEDURE                            = &H02
%DB_PT_FUNCTION                             = &H03
%DB_REMOTE                                  = &H01
%DB_LOCAL_SHARED                            = &H02
%DB_LOCAL_EXCLUSIVE                         = &H03
%DB_COLLATION_ASC                           = &H01
%DB_COLLATION_DESC                          = &H02
%DB_UNSEARCHABLE                            = &H01
%DB_LIKE_ONLY                               = &H02
%DB_ALL_EXCEPT_LIKE                         = &H03
%DB_SEARCHABLE                              = &H04

%MDTREEOP_CHILDREN                          = &H01
%MDTREEOP_SIBLINGS                          = &H02
%MDTREEOP_PARENT                            = &H04
%MDTREEOP_SELF                              = &H08
%MDTREEOP_DESCENDANTS                       = &H10
%MDTREEOP_ANCESTORS                         = &H20
%MD_DIMTYPE_UNKNOWN                         = &H00
%MD_DIMTYPE_TIME                            = &H01
%MD_DIMTYPE_MEASURE                         = &H02
%MD_DIMTYPE_OTHER                           = &H03
%MDLEVEL_TYPE_UNKNOWN                       = &H0000
%MDLEVEL_TYPE_REGULAR                       = &H0000
%MDLEVEL_TYPE_ALL                           = &H0001
%MDLEVEL_TYPE_CALCULATED                    = &H0002
%MDLEVEL_TYPE_TIME                          = &H0004
%MDLEVEL_TYPE_RESERVED1                     = &H0008
%MDLEVEL_TYPE_TIME_YEARS                    = &H0014
%MDLEVEL_TYPE_TIME_HALF_YEAR                = &H0024
%MDLEVEL_TYPE_TIME_QUARTERS                 = &H0044
%MDLEVEL_TYPE_TIME_MONTHS                   = &H0084
%MDLEVEL_TYPE_TIME_WEEKS                    = &H0104
%MDLEVEL_TYPE_TIME_DAYS                     = &H0204
%MDLEVEL_TYPE_TIME_HOURS                    = &H0304
%MDLEVEL_TYPE_TIME_MINUTES                  = &H0404
%MDLEVEL_TYPE_TIME_SECONDS                  = &H0804
%MDLEVEL_TYPE_TIME_UNDEFINED                = &H1004
%MDMEASURE_AGGR_UNKNOWN                     = &H00
%MDMEASURE_AGGR_SUM                         = &H01
%MDMEASURE_AGGR_COUNT                       = &H02
%MDMEASURE_AGGR_MIN                         = &H03
%MDMEASURE_AGGR_MAX                         = &H04
%MDMEASURE_AGGR_AVG                         = &H05
%MDMEASURE_AGGR_VAR                         = &H06
%MDMEASURE_AGGR_STD                         = &H07
%MDMEASURE_AGGR_CALCULATED                  = &H7f
%MDPROP_MEMBER                              = &H01
%MDPROP_CELL                                = &H02
%MDMEMBER_TYPE_UNKNOWN                      = &H00
%MDMEMBER_TYPE_REGULAR                      = &H01
%MDMEMBER_TYPE_ALL                          = &H02
%MDMEMBER_TYPE_MEASURE                      = &H03
%MDMEMBER_TYPE_FORMULA                      = &H04
%MDMEMBER_TYPE_RESERVE1                     = &H05
%MDMEMBER_TYPE_RESERVE2                     = &H06
%MDMEMBER_TYPE_RESERVE3                     = &H07
%MDMEMBER_TYPE_RESERVE4                     = &H08
%MDDISPINFO_DRILLED_DOWN                    = &H00010000
%MDDISPINFO_PARENT_SAME_AS_PREV             = &H00020000

'typedef DWORD DBINDEX_COL_ORDER;

' DBINDEX_COL_ORDERENUM
%DBINDEX_COL_ORDER_ASC                      = 0
%DBINDEX_COL_ORDER_DESC                     = %DBINDEX_COL_ORDER_ASC               + 1

' // Size = 8 bytes
TYPE DBINDEXCOLUMNDESC DWORD
   pColumnID      AS DBID PTR   ' DBID *
   eIndexColOrder AS LONG       ' DBINDEX_COL_ORDER
END TYPE

' // Size = 52 bytes
TYPE DBCOLUMNDESC BYTE
   pwszTypeName   AS WSTRINGZ PTR    ' LPOLESTR
   pTypeInfo      AS DWORD           ' ITypeInfo *
   rgPropertySets AS DBPROPSET PTR   ' DBPROPSET *
   pclsid         AS GUID PTR        ' CLSID
   cPropertySets  AS DWORD           ' ULONG
   ulColumnSize   AS DWORD           ' DBLENGTH
   dbcid          AS DBID            ' DBID
   wType          AS WORD            ' DBTYPE
   bPrecision     AS BYTE            ' BYTE
   bScale         AS BYTE            ' BYTE
END TYPE

' // Size = 48 bytes
TYPE DBCOLUMNACCESS BYTE
   pData      AS DWORD   ' void *
   columnid   AS DBID    ' DBID
   cbDataLen  AS DWORD   ' DBLENGTH
   dwStatus   AS DWORD   ' DBSTATUS
   cbMaxLen   AS DWORD   ' DBLENGTH
   dwReserved AS DWORD   ' DB_DWRESERVE
   wType      AS WORD    ' DBTYPE
   bPrecision AS BYTE    ' BYTE
   bScale     AS BYTE    ' BYTE
END TYPE

'typedef DWORD DBCOLUMNDESCFLAGS;

' DBCOLUMNDESCFLAGSENUM
%DBCOLUMNDESCFLAGS_TYPENAME                 = &H1
%DBCOLUMNDESCFLAGS_ITYPEINFO                = &H2
%DBCOLUMNDESCFLAGS_PROPERTIES               = &H4
%DBCOLUMNDESCFLAGS_CLSID                    = &H8
%DBCOLUMNDESCFLAGS_COLSIZE                  = &H10
%DBCOLUMNDESCFLAGS_DBCID                    = &H20
%DBCOLUMNDESCFLAGS_WTYPE                    = &H40
%DBCOLUMNDESCFLAGS_PRECISION                = &H80
%DBCOLUMNDESCFLAGS_SCALE                    = &H100

'typedef DWORD DBEVENTPHASE;

' DBEVENTPHASEENUM
%DBEVENTPHASE_OKTODO                        = 0
%DBEVENTPHASE_ABOUTTODO                     = %DBEVENTPHASE_OKTODO                 + 1
%DBEVENTPHASE_SYNCHAFTER                    = %DBEVENTPHASE_ABOUTTODO              + 1
%DBEVENTPHASE_FAILEDTODO                    = %DBEVENTPHASE_SYNCHAFTER             + 1
%DBEVENTPHASE_DIDEVENT                      = %DBEVENTPHASE_FAILEDTODO             + 1

'typedef DWORD DBREASON;

' DBREASONENUM
%DBREASON_ROWSET_FETCHPOSITIONCHANGE        = 0
%DBREASON_ROWSET_RELEASE                    = %DBREASON_ROWSET_FETCHPOSITIONCHANGE + 1
%DBREASON_COLUMN_SET                        = %DBREASON_ROWSET_RELEASE             + 1
%DBREASON_COLUMN_RECALCULATED               = %DBREASON_COLUMN_SET                 + 1
%DBREASON_ROW_ACTIVATE                      = %DBREASON_COLUMN_RECALCULATED        + 1
%DBREASON_ROW_RELEASE                       = %DBREASON_ROW_ACTIVATE               + 1
%DBREASON_ROW_DELETE                        = %DBREASON_ROW_RELEASE                + 1
%DBREASON_ROW_FIRSTCHANGE                   = %DBREASON_ROW_DELETE                 + 1
%DBREASON_ROW_INSERT                        = %DBREASON_ROW_FIRSTCHANGE            + 1
%DBREASON_ROW_RESYNCH                       = %DBREASON_ROW_INSERT                 + 1
%DBREASON_ROW_UNDOCHANGE                    = %DBREASON_ROW_RESYNCH                + 1
%DBREASON_ROW_UNDOINSERT                    = %DBREASON_ROW_UNDOCHANGE             + 1
%DBREASON_ROW_UNDODELETE                    = %DBREASON_ROW_UNDOINSERT             + 1
%DBREASON_ROW_UPDATE                        = %DBREASON_ROW_UNDODELETE             + 1
%DBREASON_ROWSET_CHANGED                    = %DBREASON_ROW_UPDATE                 + 1

' DBREASONENUM15
%DBREASON_ROWPOSITION_CHANGED               = %DBREASON_ROWSET_CHANGED             + 1
%DBREASON_ROWPOSITION_CHAPTERCHANGED        = %DBREASON_ROWPOSITION_CHANGED        + 1
%DBREASON_ROWPOSITION_CLEARED               = %DBREASON_ROWPOSITION_CHAPTERCHANGED + 1
%DBREASON_ROW_ASYNCHINSERT                  = %DBREASON_ROWPOSITION_CLEARED        + 1

'typedef DWORD DBCOMPAREOP;

' DBCOMPAREOPSENUM
%DBCOMPAREOPS_LT                            = 0
%DBCOMPAREOPS_LE                            = 1
%DBCOMPAREOPS_EQ                            = 2
%DBCOMPAREOPS_GE                            = 3
%DBCOMPAREOPS_GT                            = 4
%DBCOMPAREOPS_BEGINSWITH                    = 5
%DBCOMPAREOPS_CONTAINS                      = 6
%DBCOMPAREOPS_NE                            = 7
%DBCOMPAREOPS_IGNORE                        = 8
%DBCOMPAREOPS_CASESENSITIVE                 = &H1000
%DBCOMPAREOPS_CASEINSENSITIVE               = &H2000

' DBCOMPAREOPSENUM20
%DBCOMPAREOPS_NOTBEGINSWITH                 = 9
%DBCOMPAREOPS_NOTCONTAINS                   = 10

'typedef DWORD DBASYNCHOP;

' DBASYNCHOPENENUM
%DBASYNCHOP_OPEN                            = 0

'typedef DWORD DBASYNCHPHASE;

' DBASYNCHPHASEENUM
%DBASYNCHPHASE_INITIALIZATION               = 0
%DBASYNCHPHASE_POPULATION                   = %DBASYNCHPHASE_INITIALIZATION        + 1
%DBASYNCHPHASE_COMPLETE                     = %DBASYNCHPHASE_POPULATION            + 1
%DBASYNCHPHASE_CANCELED                     = %DBASYNCHPHASE_COMPLETE              + 1

%DB_COUNTUNAVAILABLE                        = -1

'typedef DWORD DBSORT;

' DBSORTENUM
%DBSORT_ASCENDING                           = 0
%DBSORT_DESCENDING                          = %DBSORT_ASCENDING                    + 1

'typedef DWORD DBCOMMANDPERSISTFLAG;

' DBCOMMANDPERSISTFLAGENUM
%DBCOMMANDPERSISTFLAG_NOSAVE                = &H1

' DBCOMMANDPERSISTFLAGENUM21
%DBCOMMANDPERSISTFLAG_DEFAULT               = 0
%DBCOMMANDPERSISTFLAG_PERSISTVIEW           = &H2
%DBCOMMANDPERSISTFLAG_PERSISTPROCEDURE      = &H4

'typedef DWORD DBCONSTRAINTTYPE;

' DBCONSTRAINTTYPEENUM
%DBCONSTRAINTTYPE_UNIQUE                    = 0
%DBCONSTRAINTTYPE_FOREIGNKEY                = &H1
%DBCONSTRAINTTYPE_PRIMARYKEY                = &H2
%DBCONSTRAINTTYPE_CHECK                     = &H3

'typedef DWORD DBUPDELRULE;

' DBUPDELRULEENUM
%DBUPDELRULE_NOACTION                       = 0
%DBUPDELRULE_CASCADE                        = &H1
%DBUPDELRULE_SETNULL                        = &H2
%DBUPDELRULE_SETDEFAULT                     = &H3

'typedef DWORD DBMATCHTYPE;

' DBMATCHTYPEENUM
%DBMATCHTYPE_FULL                           = 0
%DBMATCHTYPE_NONE                           = &H1
%DBMATCHTYPE_PARTIAL                        = &H2

'typedef DWORD DBDEFERRABILITY;

' DBDEFERRABILITYENUM
%DBDEFERRABILITY_DEFERRED                   = &H1
%DBDEFERRABILITY_DEFERRABLE                 = &H2

' // Size = 56 bytes
TYPE DBCONSTRAINTDESC DWORD
   pConstraintID          AS DBID PTR        ' DBID *
   ConstraintType         AS DWORD           ' DBCONSTRAINTTYPE
   cColumns               AS DWORD           ' DBORDINAL
   rgColumnList           AS DBID PTR        ' DBID* [array]
   pReferencedTableID     AS DBID PTR        ' DBID
   cForeignKeyColumns     AS DWORD           ' DBORDINAL
   rgForeignKeyColumnList AS DBID PTR        ' DBID* [array]
   pwszConstraintText     AS WSTRINGZ PTR    ' OLECHAR
   UpdateRule             AS DWORD           ' DBUPDELRULE
   DeleteRule             AS DWORD           ' DBUPDELRULE
   MatchType              AS DWORD           ' DBMATCHTYPE
   Deferrability          AS DWORD           ' DBDEFERRABILITY
   cReserved              AS DWORD           ' DB_URESERVE
   rgReserved             AS DBPROPSET PTR   ' DBPROPSET * [array]
END TYPE

%MDFF_BOLD                                  = &H01
%MDFF_ITALIC                                = &H02
%MDFF_UNDERLINE                             = &H04
%MDFF_STRIKEOUT                             = &H08

' // Size = 24 bytes
TYPE MDAXISINFO DWORD
   cbSize               AS DWORD          ' DBLENGTH
   iAxis                AS DWORD          ' DBCOUNTITEM
   cDimensions          AS DWORD          ' DBCOUNTITEM
   cCoordinates         AS DWORD          ' DBCOUNTITEM
   rgcColumns           AS DWORD          ' DBORDINAL *
   rgpwszDimensionNames AS WSTRINGZ PTR   ' LPOLESTR *
END TYPE

'#define PMDAXISINFO_GETAT(rgAxisInfo, iAxis) ((MDAXISINFO *)(((BYTE *)(rgAxisInfo)) +((iAxis) * (rgAxisInfo)[0].cbSize)))
'#define MDAXISINFO_GETAT(rgAxisInfo, iAxis) (*PMDAXISINFO_GETAT((rgAxisInfo), (iAxis)))
%MDAXIS_COLUMNS  = &H00000000???
%MDAXIS_ROWS     = &H00000001???
%MDAXIS_PAGES    = &H00000002???
%MDAXIS_SECTIONS = &H00000003???
%MDAXIS_CHAPTERS = &H00000004???
%MDAXIS_SLICERS  = &Hffffffff???

' // Size = 56 bytes
TYPE RMTPACK DWORD
   pISeqStream   AS DWORD                ' ISequentialStream *
   cbData        AS DWORD                ' ULONG
   cBSTR         AS DWORD                ' ULONG
   rgBSTR        AS DWORD                ' BSTR * [array]
   cVARIANT      AS DWORD                ' ULONG
   rgVARIANT     AS tagVARIANT PTR       ' VARIANT * [array]
   cIDISPATCH    AS DWORD                ' ULONG
   rgIDISPATCH   AS DWORD PTR            ' IDispatch ** [array]
   cIUNKNOWN     AS DWORD                ' ULONG
   rgIUNKNOWN    AS DWORD PTR            ' IUnknown ** [array]
   cPROPVARIANT  AS DWORD                ' ULONG
   rgPROPVARIANT AS PROPVARIANT PTR      ' PROPVARIANT * [array]
   cArray        AS DWORD                ' ULONG
   rgArray       AS tagVARIANT PTR       ' VARIANT * [array]
END TYPE


#ENDIF   ' /* __DBStructureDefinitions_INTERFACE_DEFINED__ */


'//
'// IID values
'//

$IID_IAccessor                         = GUID$("{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IAlterIndex                       = GUID$("{0C733AA6-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IAlterTable                       = GUID$("{0C733AA5-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IBindResource                     = GUID$("{0C733AB1-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IChapteredRowset                  = GUID$("{0C733A93-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IColumnsInfo                      = GUID$("{0C733A11-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IColumnsInfo2                     = GUID$("{0C733AB8-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IColumnsRowset                    = GUID$("{0C733A10-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommand                          = GUID$("{0C733A63-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandPersist                   = GUID$("{0C733AA7-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandPrepare                   = GUID$("{0C733A26-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandProperties                = GUID$("{0C733A79-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandStream                    = GUID$("{0C733ABF-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandText                      = GUID$("{0C733A27-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICommandWithParameters            = GUID$("{0C733A64-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IConvertType                      = GUID$("{0C733A88-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ICreateRow                        = GUID$("{0C733AB2-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBAsynchNotify                   = GUID$("{0C733A96-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBAsynchStatus                   = GUID$("{0C733A95-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBBinderProperties               = GUID$("{0C733AB3-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBCreateCommand                  = GUID$("{0C733A1D-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBCreateSession                  = GUID$("{0C733A5D-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBDataSourceAdmin                = GUID$("{0C733A7A-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBInfo                           = GUID$("{0C733A89-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBInitialize                     = GUID$("{0C733A8B-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBProperties                     = GUID$("{0C733A8A-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IDBSchemaRowset                   = GUID$("{0C733A7B-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IErrorLookup                      = GUID$("{0C733A66-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IErrorRecords                     = GUID$("{0C733A67-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IGetDataSource                    = GUID$("{0C733A75-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IGetRow                           = GUID$("{0C733AAF-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IGetSession                       = GUID$("{0C733ABA-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IGetSourceRow                     = GUID$("{0C733ABB-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IIndexDefinition                  = GUID$("{0C733A68-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IMDDataset                        = GUID$("{A07CCCD1-8148-11D0-87BB-00C04FC33942}")
$IID_IMDFind                           = GUID$("{A07CCCD2-8148-11D0-87BB-00C04FC33942}")
$IID_IMDRangeRowset                    = GUID$("{0C733AA0-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IMultipleResults                  = GUID$("{0C733A90-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IObjectAccessControl              = GUID$("{0C733AA3-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IOpenRowset                       = GUID$("{0C733A69-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IParentRowset                     = GUID$("{0C733AAA-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IQuery                            = GUID$("{0C733A51-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IReadData                         = GUID$("{0C733A6A-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRegisterProvider                 = GUID$("{0C733AB9-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRow                              = GUID$("{0C733AB4-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowChange                        = GUID$("{0C733AB5-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowSchemaChange                  = GUID$("{0C733AAE-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowPosition                      = GUID$("{0C733A94-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowPositionChange                = GUID$("{0997A571-126E-11D0-9F8A-00A0C9A0631E}")
$IID_IRowset                           = GUID$("{0C733A7C-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetBookmark                   = GUID$("{0C733AC2-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetChange                     = GUID$("{0C733A05-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetChapterMember              = GUID$("{0C733AA8-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetCurrentIndex               = GUID$("{0C733ABD-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetExactScroll                = GUID$("{0C733A7F-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetFind                       = GUID$("{0C733A9D-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetIdentity                   = GUID$("{0C733A09-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetIndex                      = GUID$("{0C733A82-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetInfo                       = GUID$("{0C733A55-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetLocate                     = GUID$("{0C733A7D-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetNotify                     = GUID$("{0C733A83-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetRefresh                    = GUID$("{0C733AA9-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetResynch                    = GUID$("{0C733A84-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetScroll                     = GUID$("{0C733A7E-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetUpdate                     = GUID$("{0C733A6D-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IRowsetView                       = GUID$("{0C733A99-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IScopedOperations                 = GUID$("{0C733AB0-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ISecurityInfo                     = GUID$("{0C733AA4-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ISessionProperties                = GUID$("{0C733A85-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ISourcesRowset                    = GUID$("{0C733A1E-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ISQLErrorInfo                     = GUID$("{0C733A74-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ISupportErrorInfo                 = GUID$("{DF0B3D60-548F-101B-8E65-08002B2BD119}")
$IID_ITableCreation                    = GUID$("{0C733ABC-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITableDefinition                  = GUID$("{0C733A86-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITableDefinitionWithConstraints   = GUID$("{0C733AAB-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITransactionJoin                  = GUID$("{0C733A5E-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITransactionLocal                 = GUID$("{0C733A5F-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITransactionObject                = GUID$("{0C733A60-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITrusteeAdmin                     = GUID$("{0C733AA1-2A1C-11CE-ADE5-00AA0044773D}")
$IID_ITrusteeGroupAdmin                = GUID$("{0C733AA2-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IViewChapter                      = GUID$("{0C733A98-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IViewFilter                       = GUID$("{0C733A9B-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IViewRowset                       = GUID$("{0C733A97-2A1C-11CE-ADE5-00AA0044773D}")
$IID_IViewSort                         = GUID$("{0C733A9A-2A1C-11CE-ADE5-00AA0044773D}")


' ########################################################################################
' IAccessor interface
' IID = 0C733A8C-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccessor_INTERFACE_DEFINED)
    %IAccessor_INTERFACE_DEFINED = 1

'typedef DWORD DBACCESSORFLAGS;

' DBACCESSORFLAGSENUM
%DBACCESSOR_INVALID                         = 0???
%DBACCESSOR_PASSBYREF                       = &H1???
%DBACCESSOR_ROWDATA                         = &H2???
%DBACCESSOR_PARAMETERDATA                   = &H4???
%DBACCESSOR_OPTIMIZED                       = &H8???
%DBACCESSOR_INHERITED                       = &H10???

'typedef DWORD DBBINDSTATUS;

' DBBINDSTATUSENUM
%DBBINDSTATUS_OK                            = 0???
%DBBINDSTATUS_BADORDINAL                    = 1???
%DBBINDSTATUS_UNSUPPORTEDCONVERSION         = 2???
%DBBINDSTATUS_BADBINDINFO                   = 3???
%DBBINDSTATUS_BADSTORAGEFLAGS               = 4???
%DBBINDSTATUS_NOINTERFACE                   = 5???
%DBBINDSTATUS_MULTIPLESTORAGE               = 6???

INTERFACE IAccessor $IID_IAccessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefAccessor ( _                            ' VTable offset = 12
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYREF pcRefCount AS DWORD _                        ' __inout DBREFCOUNT *pcRefCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAccessor ( _                            ' VTable offset = 16
     BYVAL dwAccessorFlags AS DWORD _                   ' __in DBACCESSORFLAGS dwAccessorFlags
   , BYVAL cBindings AS DWORD _                         ' __in DBCOUNTITEM cBindings
   , BYREF rgBindings AS DBBINDING _                    ' __in const DBBINDING rgBindings[  ]
   , BYVAL cbRowSize AS DWORD _                         ' __in DBLENGTH cbRowSize
   , BYREF phAccessor AS DWORD _                        ' __out HACCESSOR *phAccessor
   , BYREF rgStatus AS DWORD _                          ' __out DBBINDSTATUS rgStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBindings ( _                               ' VTable offset = 20
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYREF pdwAccessorFlags AS DWORD _                  ' __out DBACCESSORFLAGS *pdwAccessorFlags
   , BYREF pcBindings AS DWORD _                        ' __inout DBCOUNTITEM *pcBindings
   , BYREF prgBindings AS DWORD _                       ' __out DBBINDING **prgBindings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseAccessor ( _                           ' VTable offset = 24
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYREF pcRefCount AS DWORD _                        ' __inout DBREFCOUNT *pcRefCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessor_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowset interface
' IID = 0C733A7C-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowset_INTERFACE_DEFINED)
    %IRowset_INTERFACE_DEFINED = 1

'typedef DWORD DBROWOPTIONS;

INTERFACE IRowset $IID_IRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefRows ( _                                ' VTable offset = 12
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextRows ( _                               ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseRows ( _                               ' VTable offset = 24
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowOptions AS DWORD _                      ' __in DBROWOPTIONS rgRowOptions[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartPosition ( _                           ' VTable offset = 28
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetInfo interface
' IID = 0C733A55-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetInfo_INTERFACE_DEFINED)
    %IRowsetInfo_INTERFACE_DEFINED = 1

INTERFACE IRowsetInfo $IID_IRowsetInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 12
     BYVAL cPropertyIDSets AS DWORD _                   ' __in const ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferencedRowset ( _                       ' VTable offset = 16
     BYVAL iOrdinal AS DWORD _                          ' __in DBORDINAL iOrdinal
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppReferencedRowset AS IUnknown _             ' __out IUnknown **ppReferencedRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecification ( _                          ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSpecification AS IUnknown _                ' __out IUnknown **ppSpecification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetLocate interface
' IID = 0C733A7D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowset
' ########################################################################################

#IF NOT %DEF(%IRowsetLocate_INTERFACE_DEFINED)
    %IRowsetLocate_INTERFACE_DEFINED = 1

'typedef DWORD DBCOMPARE;

' DBCOMPAREENUM
%DBCOMPARE_LT                               = 0
%DBCOMPARE_EQ                               = %DBCOMPARE_LT + 1
%DBCOMPARE_GT                               = %DBCOMPARE_EQ + 1
%DBCOMPARE_NE                               = %DBCOMPARE_GT + 1
%DBCOMPARE_NOTCOMPARABLE                    = %DBCOMPARE_NE + 1

INTERFACE IRowsetLocate $IID_IRowsetLocate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefRows ( _                                ' VTable offset = 12
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextRows ( _                               ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseRows ( _                               ' VTable offset = 24
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowOptions AS DWORD _                      ' __in DBROWOPTIONS rgRowOptions[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartPosition ( _                           ' VTable offset = 28
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 32
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cbBookmark1 AS DWORD _                       ' __in DBBKMARK cbBookmark1
   , BYVAL pBookmark1 AS BYTE PTR _                     ' __in const BYTE *pBookmark1
   , BYVAL cbBookmark2 AS DWORD _                       ' __in DBBKMARK cbBookmark2
   , BYVAL pBookmark2 AS BYTE PTR _                     ' __in const BYTE *pBookmark2
   , BYREF pComparison AS DWORD _                       ' __out DBCOMPARE *pComparison
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsAt ( _                                 ' VTable offset = 36
     BYVAL hReserved1 AS DWORD _                        ' __in HWATCHREGION hReserved1
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsByBookmark ( _                         ' VTable offset = 40
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rghRows AS DWORD _                           ' __out HROW rghRows[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Hash ( _                                      ' VTable offset = 44
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cBookmarks AS DWORD _                        ' __in DBBKMARK cBookmarks
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rgHashedValues AS DWORD _                    ' __out DBHASHVALUE rgHashedValues[  ]
   , BYREF rgBookmarkStatus AS DWORD _                  ' __out DBROWSTATUS rgBookmarkStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetLocate_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetResynch interface
' IID = 0C733A84-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetResynch_INTERFACE_DEFINED)
    %IRowsetResynch_INTERFACE_DEFINED = 1

INTERFACE IRowsetResynch $IID_IRowsetResynch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVisibleData ( _                            ' VTable offset = 12
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResynchRows ( _                               ' VTable offset = 16
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF pcRowsResynched AS DWORD _                   ' __out DBCOUNTITEM *pcRowsResynched
   , BYREF prghRowsResynched AS DWORD _                 ' __out HROW **prghRowsResynched
   , BYREF prgRowStatus AS DWORD _                      ' __out DBROWSTATUS **prgRowStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetResynch_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetScroll interface
' IID = 0C733A7E-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowsetLocate
' ########################################################################################

#IF NOT %DEF(%IRowsetScroll_INTERFACE_DEFINED)
    %IRowsetScroll_INTERFACE_DEFINED = 1

INTERFACE IRowsetScroll $IID_IRowsetScroll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefRows ( _                                ' VTable offset = 12
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextRows ( _                               ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseRows ( _                               ' VTable offset = 24
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowOptions AS DWORD _                      ' __in DBROWOPTIONS rgRowOptions[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartPosition ( _                           ' VTable offset = 28
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 32
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cbBookmark1 AS DWORD _                       ' __in DBBKMARK cbBookmark1
   , BYVAL pBookmark1 AS BYTE PTR _                     ' __in const BYTE *pBookmark1
   , BYVAL cbBookmark2 AS DWORD _                       ' __in DBBKMARK cbBookmark2
   , BYVAL pBookmark2 AS BYTE PTR _                     ' __in const BYTE *pBookmark2
   , BYREF pComparison AS DWORD _                       ' __out DBCOMPARE *pComparison
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsAt ( _                                 ' VTable offset = 36
     BYVAL hReserved1 AS DWORD _                        ' __in HWATCHREGION hReserved1
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsByBookmark ( _                         ' VTable offset = 40
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rghRows AS DWORD _                           ' __out HROW rghRows[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Hash ( _                                      ' VTable offset = 44
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cBookmarks AS DWORD _                        ' __in DBBKMARK cBookmarks
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rgHashedValues AS DWORD _                    ' __out DBHASHVALUE rgHashedValues[  ]
   , BYREF rgBookmarkStatus AS DWORD _                  ' __out DBROWSTATUS rgBookmarkStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApproximatePosition ( _                    ' VTable offset = 48
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYREF pulPosition AS DWORD _                       ' __out DBCOUNTITEM *pulPosition
   , BYREF pcRows AS DWORD _                            ' __out DBCOUNTITEM *pcRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsAtRatio ( _                            ' VTable offset = 52
     BYVAL hReserved1 AS DWORD _                        ' __in HWATCHREGION hReserved1
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL ulNumerator AS DWORD _                       ' __in DBCOUNTITEM ulNumerator
   , BYVAL ulDenominator AS DWORD _                     ' __in DBCOUNTITEM ulDenominator
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetScroll_INTERFACE_DEFINED__ */


' ########################################################################################
' IChapteredRowset interface
' IID = 0C733A93-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IChapteredRowset_INTERFACE_DEFINED)
    %IChapteredRowset_INTERFACE_DEFINED = 1

INTERFACE IChapteredRowset $IID_IChapteredRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefChapter ( _                             ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYREF pcRefCount AS DWORD _                        ' __out DBREFCOUNT *pcRefCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseChapter ( _                            ' VTable offset = 16
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYREF pcRefCount AS DWORD _                        ' __out DBREFCOUNT *pcRefCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChapteredRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetFind interface
' IID = 0C733A9D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetFind_INTERFACE_DEFINED)
    %IRowsetFind_INTERFACE_DEFINED = 1

INTERFACE IRowsetFind $IID_IRowsetFind

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindNextRow ( _                               ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pFindValue AS DWORD _                        ' __in void *pFindValue
   , BYVAL CompareOp AS DWORD _                         ' __in DBCOMPAREOP CompareOp
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __inout DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetFind_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowPosition interface
' IID = 0C733A94-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowPosition_INTERFACE_DEFINED)
    %IRowPosition_INTERFACE_DEFINED = 1

'typedef DWORD DBPOSITIONFLAGS;

' DBPOSITIONFLAGSENUM
%DBPOSITION_OK    = 0
%DBPOSITION_NOROW = %DBPOSITION_OK    + 1
%DBPOSITION_BOF   = %DBPOSITION_NOROW + 1
%DBPOSITION_EOF   = %DBPOSITION_BOF   + 1

INTERFACE IRowPosition $IID_IRowPosition

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ClearRowPosition ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowPosition ( _                            ' VTable offset = 16
     BYREF phChapter AS DWORD _                         ' __out HCHAPTER *phChapter
   , BYREF phRow AS DWORD _                             ' __out HROW *phRow
   , BYREF pdwPositionFlags AS DWORD _                  ' __out DBPOSITIONFLAGS *pdwPositionFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowset ( _                                 ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL pRowset AS IUnknown _                        ' __in IUnknown *pRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRowPosition ( _                            ' VTable offset = 32
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL dwPositionFlags AS DWORD _                   ' __in DBPOSITIONFLAGS dwPositionFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowPosition_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowPositionChange interface
' IID = 0997a571-126e-11d0-9f8a-00a0c9a0631e
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowPositionChange_INTERFACE_DEFINED)
    %IRowPositionChange_INTERFACE_DEFINED = 1

INTERFACE IRowPositionChange $IID_IRowPositionChange

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnRowPositionChange ( _                       ' VTable offset = 12
     BYVAL eReason AS DWORD _                           ' __in DBREASON eReason
   , BYVAL ePhase AS DWORD _                            ' __in DBEVENTPHASE ePhase
   , BYVAL fCantDeny AS LONG _                          ' __in BOOL fCantDeny
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowPositionChange_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewRowset interface
' IID = 0C733A97-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IViewRowset_INTERFACE_DEFINED)
    %IViewRowset_INTERFACE_DEFINED = 1

INTERFACE IViewRowset $IID_IViewRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSpecification ( _                          ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenViewRowset ( _                            ' VTable offset = 16
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewChapter interface
' IID = 0C733A98-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IViewChapter_INTERFACE_DEFINED)
    %IViewChapter_INTERFACE_DEFINED = 1

INTERFACE IViewChapter $IID_IViewChapter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSpecification ( _                          ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenViewChapter ( _                           ' VTable offset = 16
     BYVAL hSource AS DWORD _                           ' __in HCHAPTER hSource
   , BYREF phViewChapter AS DWORD _                     ' __out HCHAPTER *phViewChapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewChapter_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewSort interface
' IID = 0C733A9A-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IViewSort_INTERFACE_DEFINED)
    %IViewSort_INTERFACE_DEFINED = 1

INTERFACE IViewSort $IID_IViewSort

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSortOrder ( _                              ' VTable offset = 12
     BYREF pcValues AS DWORD _                          ' __out DBORDINAL *pcValues
   , BYREF prgColumns AS DWORD _                        ' __out DBORDINAL *prgColumns[  ]
   , BYREF prgOrders AS DWORD _                         ' __out DBSORT *prgOrders[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSortOrder ( _                              ' VTable offset = 16
     BYVAL cValues AS DWORD _                           ' __in DBORDINAL cValues
   , BYREF rgColumns AS DWORD _                         ' __in const DBORDINAL rgColumns[  ]
   , BYREF rgOrders AS DWORD _                          ' __in const DBSORT rgOrders[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewSort_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewFilter interface
' IID = 0C733A9B-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IViewFilter_INTERFACE_DEFINED)
    %IViewFilter_INTERFACE_DEFINED = 1

INTERFACE IViewFilter $IID_IViewFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFilter ( _                                 ' VTable offset = 12
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYREF pcRows AS DWORD _                            ' __out DBCOUNTITEM *pcRows
   , BYREF pCompareOps AS DWORD _                       ' __out DBCOMPAREOP *pCompareOps[  ]
   , BYVAL pCriteriaData AS DWORD _                     ' __out void *pCriteriaData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterBindings ( _                         ' VTable offset = 16
     BYREF pcBindings AS DWORD _                        ' __out DBCOUNTITEM *pcBindings
   , BYREF prgBindings AS DWORD _                       ' __out DBBINDING **prgBindings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 20
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF CompareOps AS DWORD _                        ' __in DBCOMPAREOP CompareOps[  ]
   , BYVAL pCriteriaData AS DWORD _                     ' __in void *pCriteriaData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IViewFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetView interface
' IID = 0C733A99-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetView_INTERFACE_DEFINED)
    %IRowsetView_INTERFACE_DEFINED = 1

INTERFACE IRowsetView $IID_IRowsetView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateView ( _                                ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppView AS IUnknown _                         ' __out IUnknown **ppView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetView ( _                                   ' VTable offset = 16
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF phChapterSource AS DWORD _                   ' __out HCHAPTER *phChapterSource
   , BYREF ppView AS IUnknown _                         ' __out IUnknown **ppView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetView_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetExactScroll interface
' IID = 0C733A7F-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowsetScroll
' ########################################################################################

#IF NOT %DEF(%IRowsetExactScroll_INTERFACE_DEFINED)
    %IRowsetExactScroll_INTERFACE_DEFINED = 1

INTERFACE IRowsetExactScroll $IID_IRowsetExactScroll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRefRows ( _                                ' VTable offset = 12
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextRows ( _                               ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseRows ( _                               ' VTable offset = 24
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowOptions AS DWORD _                      ' __in DBROWOPTIONS rgRowOptions[  ]
   , BYREF rgRefCounts AS DWORD _                       ' __out DBREFCOUNT rgRefCounts[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestartPosition ( _                           ' VTable offset = 28
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 32
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cbBookmark1 AS DWORD _                       ' __in DBBKMARK cbBookmark1
   , BYVAL pBookmark1 AS BYTE PTR _                     ' __in const BYTE *pBookmark1
   , BYVAL cbBookmark2 AS DWORD _                       ' __in DBBKMARK cbBookmark2
   , BYVAL pBookmark2 AS BYTE PTR _                     ' __in const BYTE *pBookmark2
   , BYREF pComparison AS DWORD _                       ' __out DBCOMPARE *pComparison
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsAt ( _                                 ' VTable offset = 36
     BYVAL hReserved1 AS DWORD _                        ' __in HWATCHREGION hReserved1
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsByBookmark ( _                         ' VTable offset = 40
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rghRows AS DWORD _                           ' __out HROW rghRows[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Hash ( _                                      ' VTable offset = 44
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cBookmarks AS DWORD _                        ' __in DBBKMARK cBookmarks
   , BYREF rgcbBookmarks AS DWORD _                     ' __in const DBBKMARK rgcbBookmarks[  ]
   , BYREF rgpBookmarks AS DWORD _                      ' __in const BYTE *rgpBookmarks[  ]
   , BYREF rgHashedValues AS DWORD _                    ' __out DBHASHVALUE rgHashedValues[  ]
   , BYREF rgBookmarkStatus AS DWORD _                  ' __out DBROWSTATUS rgBookmarkStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetApproximatePosition ( _                    ' VTable offset = 48
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYREF pulPosition AS DWORD _                       ' __out DBCOUNTITEM *pulPosition
   , BYREF pcRows AS DWORD _                            ' __out DBCOUNTITEM *pcRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowsAtRatio ( _                            ' VTable offset = 52
     BYVAL hReserved1 AS DWORD _                        ' __in HWATCHREGION hReserved1
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL ulNumerator AS DWORD _                       ' __in DBCOUNTITEM ulNumerator
   , BYVAL ulDenominator AS DWORD _                     ' __in DBCOUNTITEM ulDenominator
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF prghRows AS DWORD _                          ' __out HROW **prghRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExactPosition ( _                          ' VTable offset = 56
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYREF pulPosition AS DWORD _                       ' __out DBCOUNTITEM *pulPosition
   , BYREF pcRows AS DWORD _                            ' __out DBCOUNTITEM *pcRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetExactScroll_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetChange interface
' IID = 0C733A05-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetChange_INTERFACE_DEFINED)
    %IRowsetChange_INTERFACE_DEFINED = 1

INTERFACE IRowsetChange $IID_IRowsetChange

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeleteRows ( _                                ' VTable offset = 12
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __in void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertRow ( _                                 ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __in void *pData
   , BYREF phRow AS DWORD _                             ' __out HROW *phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetChange_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetUpdate interface
' IID = 0C733A6D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowsetChange
' ########################################################################################

#IF NOT %DEF(%IRowsetUpdate_INTERFACE_DEFINED)
    %IRowsetUpdate_INTERFACE_DEFINED = 1

'typedef DWORD DBPENDINGSTATUS;

' DBPENDINGSTATUSENUM
%DBPENDINGSTATUS_NEW        = &H1
%DBPENDINGSTATUS_CHANGED    = &H2
%DBPENDINGSTATUS_DELETED    = &H4
%DBPENDINGSTATUS_UNCHANGED  = &H8
%DBPENDINGSTATUS_INVALIDROW = &H10

INTERFACE IRowsetUpdate $IID_IRowsetUpdate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeleteRows ( _                                ' VTable offset = 12
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgRowStatus AS DWORD _                       ' __out DBROWSTATUS rgRowStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __in void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertRow ( _                                 ' VTable offset = 20
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __in void *pData
   , BYREF phRow AS DWORD _                             ' __out HROW *phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalData ( _                           ' VTable offset = 24
     BYVAL hRow AS DWORD _                                      ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                                      ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPendingRows ( _                            ' VTable offset = 28
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL dwRowStatus AS DWORD _                       ' __in DBPENDINGSTATUS dwRowStatus
   , BYREF pcPendingRows AS DWORD _                     ' __inout DBCOUNTITEM *pcPendingRows
   , BYREF prgPendingRows AS DWORD _                    ' __out HROW **prgPendingRows
   , BYREF prgPendingStatus AS DWORD _                  ' __out DBPENDINGSTATUS **prgPendingStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRowStatus ( _                              ' VTable offset = 32
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF rgPendingStatus AS DWORD _                   ' __out DBPENDINGSTATUS rgPendingStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Undo ( _                                      ' VTable offset = 36
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF pcRowsUndone AS DWORD _                      ' __inout DBCOUNTITEM *pcRowsUndone
   , BYREF prgRowsUndone AS DWORD _                     ' __out HROW **prgRowsUndone
   , BYREF prgRowStatus AS DWORD _                      ' __out DBROWSTATUS **prgRowStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 40
     BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYREF pcRows AS DWORD _                            ' __inout DBCOUNTITEM *pcRows
   , BYREF prgRows AS DWORD _                           ' __out HROW **prgRows
   , BYREF prgRowStatus AS DWORD _                      ' __out DBROWSTATUS **prgRowStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetUpdate_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetIdentity interface
' IID = 0C733A09-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetIdentity_INTERFACE_DEFINED)
    %IRowsetIdentity_INTERFACE_DEFINED = 1

INTERFACE IRowsetIdentity $IID_IRowsetIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSameRow ( _                                 ' VTable offset = 12
     BYVAL hThisRow AS DWORD _                          ' __in HROW hThisRow
   , BYVAL hThatRow AS DWORD _                          ' __in HROW hThatRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetIdentity_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetNotify interface
' IID = 0C733A83-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

'#IF NOT %DEF(%IRowsetNotify_INTERFACE_DEFINED)
'    %IRowsetNotify_INTERFACE_DEFINED = 1

'INTERFACE IRowsetNotify $IID_IRowsetNotify

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD OnFieldChange ( _                             ' VTable offset = 12
'     BYVAL pRowset AS IRowset _                         ' __in IRowset *pRowset
'   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
'   , BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
'   , BYREF rgColumns AS DWORD _                         ' __in DBORDINAL rgColumns[  ]
'   , BYVAL eReason AS DWORD _                           ' __in DBREASON eReason
'   , BYVAL ePhase AS DWORD _                            ' __in DBEVENTPHASE ePhase
'   , BYVAL fCantDeny AS LONG _                          ' __in BOOL fCantDeny
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnRowChange ( _                               ' VTable offset = 16
'     BYVAL pRowset AS IRowset _                         ' __in IRowset *pRowset
'   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
'   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
'   , BYVAL eReason AS DWORD                             ' __in DBREASON eReason
'   , BYVAL ePhase AS DWORD _                            ' __in DBEVENTPHASE ePhase
'   , BYVAL fCantDeny AS LONG _                          ' __in BOOL fCantDeny
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OnRowChange ( _                               ' VTable offset = 20
'     BYVAL pRowset AS IRowset _                         ' __in IRowset *pRowset
'   , BYVAL eReason AS DWORD _                           ' __in DBREASON eReason
'   , BYVAL ePhase AS DWORD _                            ' __in DBEVENTPHASE ePhase
'   , BYVAL fCantDeny AS LONG _                          ' __in BOOL fCantDeny
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IRowsetNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetIndex interface
' IID = 0C733A82-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetIndex_INTERFACE_DEFINED)
    %IRowsetIndex_INTERFACE_DEFINED = 1

'typedef DWORD DBSEEK;

' DBSEEKENUM
%DBSEEK_INVALID         = 0???
%DBSEEK_FIRSTEQ         = &H1???
%DBSEEK_LASTEQ          = &H2???
%DBSEEK_AFTEREQ         = &H4???
%DBSEEK_AFTER           = &H8???
%DBSEEK_BEFOREEQ        = &H10???
%DBSEEK_BEFORE          = &H20???

%DBSEEK_GE              = %DBSEEK_AFTEREQ
%DBSEEK_GT              = %DBSEEK_AFTER
%DBSEEK_LE              = %DBSEEK_BEFOREEQ
%DBSEEK_LT              = %DBSEEK_BEFORE

'typedef DWORD DBRANGE;

' DBRANGEENUM
%DBRANGE_INCLUSIVESTART = 0???
%DBRANGE_INCLUSIVEEND   = 0???
%DBRANGE_EXCLUSIVESTART = &H1???
%DBRANGE_EXCLUSIVEEND   = &H2???
%DBRANGE_EXCLUDENULLS   = &H4???
%DBRANGE_PREFIX         = &H8???
%DBRANGE_MATCH          = &H10???

' DBRANGEENUM20
%DBRANGE_MATCH_N_SHIFT  = &H18???
%DBRANGE_MATCH_N_MASK   = &Hff???

INTERFACE IRowsetIndex $IID_IRowsetIndex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIndexInfo ( _                              ' VTable offset = 12
     BYREF pcKeyColumns AS DWORD _                      ' __inout DBORDINAL *pcKeyColumns
   , BYREF prgIndexColumnDesc AS DWORD _                ' __out DBINDEXCOLUMNDESC **prgIndexColumnDesc
   , BYREF pcIndexPropertySets AS DWORD _               ' __inout ULONG *pcIndexPropertySets
   , BYREF prgIndexPropertySets AS DWORD _              ' __out DBPROPSET **prgIndexPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 16
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL cKeyValues AS DWORD _                        ' __in DBORDINAL cKeyValues
   , BYVAL pData AS DWORD _                             ' __in void *pData
   , BYVAL dwSeekOptions AS DWORD _                     ' __in DBSEEK dwSeekOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRange ( _                                  ' VTable offset = 20
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL cStartKeyColumns AS DWORD _                  ' __in DBORDINAL cStartKeyColumns
   , BYVAL pStartData AS DWORD _                        ' __in void *pStartData
   , BYVAL cEndKeyColumns AS DWORD _                    ' __in DBORDINAL cEndKeyColumns
   , BYVAL pEndData AS DWORD _                          ' __in void *pEndData
   , BYVAL dwRangeOptions AS DWORD _                    ' __in DBRANGE dwRangeOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetIndex_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommand interface
' IID = 0C733A63-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommand_INTERFACE_DEFINED)
    %ICommand_INTERFACE_DEFINED = 1

INTERFACE ICommand $IID_ICommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 16
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pParams AS DBPARAMS _                        ' __inout DBPARAMS *pParams
   , BYREF pcRowsAffected AS LONG _                     ' __out DBROWCOUNT *pcRowsAffected
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDBSession ( _                              ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSession AS IUnknown _                      ' __out IUnknown **ppSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IMultipleResults interface
' IID = 0C733A90-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultipleResults_INTERFACE_DEFINED)
    %IMultipleResults_INTERFACE_DEFINED = 1

'typedef DB_LRESERVE DBRESULTFLAG;

' enum DBRESULTFLAGENUM
%DBRESULTFLAG_DEFAULT = 0
%DBRESULTFLAG_ROWSET  = 1
%DBRESULTFLAG_ROW     = 2

INTERFACE IMultipleResults $IID_IMultipleResults

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL lResultFlag AS LONG _                        ' __in DBRESULTFLAG lResultFlag
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pcRowsAffected AS LONG _                     ' __out DBROWCOUNT *pcRowsAffected
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultipleResults_INTERFACE_DEFINED__ */


' ########################################################################################
' IConvertType interface
' IID = 0C733A88-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConvertType_INTERFACE_DEFINED)
    %IConvertType_INTERFACE_DEFINED = 1

'typedef DWORD DBCONVERTFLAGS;

' DBCONVERTFLAGSENUM
%DBCONVERTFLAGS_COLUMN                      = 0
%DBCONVERTFLAGS_PARAMETER                   = &H1

' DBCONVERTFLAGSENUM20
%DBCONVERTFLAGS_ISLONG                      = &H2
%DBCONVERTFLAGS_ISFIXEDLENGTH               = &H4
%DBCONVERTFLAGS_FROMVARIANT                 = &H8

INTERFACE IConvertType $IID_IConvertType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParameterInfo ( _                          ' VTable offset = 12
     BYVAL wFromType AS WORD _                          ' __in DBTYPE wFromType
   , BYVAL wToType AS WORD _                            ' __in DBTYPE wToType
   , BYVAL dwConvertFlags AS DWORD _                    ' __in DBCONVERTFLAGS dwConvertFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConvertType_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandPrepare interface
' IID = 0C733A26-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandPrepare_INTERFACE_DEFINED)
    %ICommandPrepare_INTERFACE_DEFINED = 1

INTERFACE ICommandPrepare $IID_ICommandPrepare

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Prepare ( _                                   ' VTable offset = 12
     BYVAL cExpectedRuns AS DWORD _                     ' __in ULONG cExpectedRuns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unprepare ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandPrepare_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandProperties interface
' IID = 0C733A79-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandProperties_INTERFACE_DEFINED)
    %ICommandProperties_INTERFACE_DEFINED = 1

INTERFACE ICommandProperties $IID_ICommandProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 12
     BYVAL cPropertyIDSets AS DWORD _                   ' __in const ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 16
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandText interface
' IID = 0C733A27-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = ICommand
' ########################################################################################

#IF NOT %DEF(%ICommandText_INTERFACE_DEFINED)
    %ICommandText_INTERFACE_DEFINED = 1

INTERFACE ICommandText $IID_ICommandText

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 16
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pParams AS DBPARAMS _                        ' __inout DBPARAMS *pParams
   , BYREF pcRowsAffected AS LONG _                     ' __out DBROWCOUNT *pcRowsAffected
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDBSession ( _                              ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSession AS IUnknown _                      ' __out IUnknown **ppSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandText ( _                            ' VTable offset = 24
     BYREF pguidDialect AS GUID _                       ' __inout GUID *pguidDialect
   , BYREF ppwszCommand AS DWORD _                      ' __out LPOLESTR *ppwszCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCommandText ( _                            ' VTable offset = 28
     BYREF rguidDialect AS GUID _                       ' __in REFGUID rguidDialect
   , BYREF pwszCommand AS WSTRINGZ _                    ' __in LPCOLESTR pwszCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandText_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandWithParameters interface
' IID = 0C733A64-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandWithParameters_INTERFACE_DEFINED)
    %ICommandWithParameters_INTERFACE_DEFINED = 1

' // Size = 18 bytes
TYPE DBPARAMBINDINFO BYTE
   pwszDataSourceType AS WSTRINGZ PTR   ' LPOLESTR
   pwszName           AS WSTRINGZ PTR   ' LPOLESTR
   ulParamSize        AS DWORD          ' DBLENGTH
   dwFlags            AS DWORD          ' DBPARAMFLAGS
   bPrecision         AS BYTE           ' BYTE
   bScale             AS BYTE           ' BYTE
END TYPE

INTERFACE ICommandWithParameters $IID_ICommandWithParameters

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParameterInfo ( _                          ' VTable offset = 12
     BYREF pcParams AS DWORD _                          ' __inout DB_UPARAMS *pcParams
   , BYREF prgParamInfo AS DWORD _                      ' __out DBPARAMINFO **prgParamInfo
   , BYREF ppNamesBuffer AS DWORD _                     ' __out OLECHAR **ppNamesBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapParameterNames ( _                         ' VTable offset = 16
     BYVAL cParamNames AS DWORD _                       ' __in DB_UPARAMS cParamNames
   , BYREF rgParamNames AS WSTRINGZ _                   ' __in const OLECHAR *rgParamNames[  ]
   , BYREF rgParamOrdinals AS DWORD _                   ' __out DB_LPARAMS rgParamOrdinals[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameterInfo ( _                          ' VTable offset = 20
     BYVAL cParams AS DWORD _                           ' __in DB_UPARAMS cParams
   , BYREF rgParamOrdinals AS DWORD _                   ' __in const DB_UPARAMS rgParamOrdinals[  ]
   , BYREF rgParamBindInfo AS DBPARAMBINDINFO _         ' __in const DBPARAMBINDINFO rgParamBindInfo[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandWithParameters_INTERFACE_DEFINED__ */


' ########################################################################################
' IColumnsRowset interface
' IID = 0C733A10-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IColumnsRowset_INTERFACE_DEFINED)
    %IColumnsRowset_INTERFACE_DEFINED = 1

INTERFACE IColumnsRowset $IID_IColumnsRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAvailableColumns ( _                       ' VTable offset = 12
     BYREF pcOptColumns AS DWORD _                      ' __inout DBORDINAL *pcOptColumns
   , BYREF prgOptColumns AS DWORD _                     ' __out DBID **prgOptColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnsRowset ( _                          ' VTable offset = 16
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL cOptColumns AS DWORD _                       ' __in DBORDINAL cOptColumns
   , BYREF rgOptColumns AS DBID _                       ' __in const DBID rgOptColumns[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppColRowset AS IUnknown _                    ' __out IUnknown **ppColRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IColumnsRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IColumnsInfo interface
' IID = 0C733A11-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IColumnsInfo_INTERFACE_DEFINED)
    %IColumnsInfo_INTERFACE_DEFINED = 1

INTERFACE IColumnsInfo $IID_IColumnsInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColumnInfo ( _                             ' VTable offset = 12
     BYREF pcColumns AS DWORD _                         ' __inout DBORDINAL *pcColumns
   , BYREF prgInfo AS DWORD _                           ' __out DBCOLUMNINFO **prgInfo
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapColumnIDs ( _                              ' VTable offset = 16
     BYVAL cColumnIDs AS DWORD _                        ' __in DBORDINAL cColumnIDs
   , BYREF rgColumnIDs AS DBID _                        ' __in const DBID rgColumnIDs[  ]
   , BYREF rgColumns AS DWORD _                         ' __out DBORDINAL rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IColumnsInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBCreateCommand interface
' IID = 0C733A1D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBCreateCommand_INTERFACE_DEFINED)
    %IDBCreateCommand_INTERFACE_DEFINED = 1

INTERFACE IDBCreateCommand $IID_IDBCreateCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateCommand ( _                             ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppCommand AS IUnknown _                      ' __out IUnknown **ppCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBCreateCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBCreateSession interface
' IID = 0C733A5D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBCreateSession_INTERFACE_DEFINED)
    %IDBCreateSession_INTERFACE_DEFINED = 1

INTERFACE IDBCreateSession $IID_IDBCreateSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateSession ( _                             ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDBSession AS IUnknown _                    ' __out IUnknown **ppDBSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBCreateSession_INTERFACE_DEFINED__ */


' ########################################################################################
' ISourcesRowset interface
' IID = 0C733A1E-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISourcesRowset_INTERFACE_DEFINED)
    %ISourcesRowset_INTERFACE_DEFINED = 1

'typedef DWORD DBSOURCETYPE;

' DBSOURCETYPEENUM
%DBSOURCETYPE_DATASOURCE                    = 1
%DBSOURCETYPE_ENUMERATOR                    = 2

' DBSOURCETYPEENUM20
%DBSOURCETYPE_DATASOURCE_TDP                = 1
%DBSOURCETYPE_DATASOURCE_MDP                = 3

' DBSOURCETYPEENUM25
%DBSOURCETYPE_BINDER                        = 4

INTERFACE ISourcesRowset $IID_ISourcesRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSourcesRowset ( _                          ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgProperties AS DBPROPSET _                  ' __inout DBPROPSET rgProperties[  ]
   , BYREF ppSourcesRowset AS IUnknown _                ' __out IUnknown **ppSourcesRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISourcesRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBProperties interface
' IID = 0C733A8A-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBProperties_INTERFACE_DEFINED)
    %IDBProperties_INTERFACE_DEFINED = 1

INTERFACE IDBProperties $IID_IDBProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 12
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyInfo ( _                           ' VTable offset = 16
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertyInfoSets AS DWORD _                ' __inout ULONG *pcPropertyInfoSets
   , BYREF prgPropertyInfoSets AS DWORD _               ' __out DBPROPINFOSET **prgPropertyInfoSets
   , BYREF ppDescBuffer AS DWORD _                      ' __out OLECHAR **ppDescBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 20
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBInitialize interface
' IID = 0C733A8B-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBInitialize_INTERFACE_DEFINED)
    %IDBInitialize_INTERFACE_DEFINED = 1

INTERFACE IDBInitialize $IID_IDBInitialize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Uninitialize ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBInitialize_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBInfo interface
' IID = 0C733A89-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBInfo_INTERFACE_DEFINED)
    %IDBInfo_INTERFACE_DEFINED = 1

'typedef DWORD DBLITERAL;

' DBLITERALENUM
%DBLITERAL_INVALID                          = 0
%DBLITERAL_BINARY_LITERAL                   = 1
%DBLITERAL_CATALOG_NAME                     = 2
%DBLITERAL_CATALOG_SEPARATOR                = 3
%DBLITERAL_CHAR_LITERAL                     = 4
%DBLITERAL_COLUMN_ALIAS                     = 5
%DBLITERAL_COLUMN_NAME                      = 6
%DBLITERAL_CORRELATION_NAME                 = 7
%DBLITERAL_CURSOR_NAME                      = 8
%DBLITERAL_ESCAPE_PERCENT                   = 9
%DBLITERAL_ESCAPE_UNDERSCORE                = 10
%DBLITERAL_INDEX_NAME                       = 11
%DBLITERAL_LIKE_PERCENT                     = 12
%DBLITERAL_LIKE_UNDERSCORE                  = 13
%DBLITERAL_PROCEDURE_NAME                   = 14
%DBLITERAL_QUOTE                            = 15
%DBLITERAL_SCHEMA_NAME                      = 16
%DBLITERAL_TABLE_NAME                       = 17
%DBLITERAL_TEXT_COMMAND                     = 18
%DBLITERAL_USER_NAME                        = 19
%DBLITERAL_VIEW_NAME                        = 20

%DBLITERAL_QUOTE_PREFIX                     = %DBLITERAL_QUOTE

' DBLITERALENUM20
%DBLITERAL_CUBE_NAME                        = 21
%DBLITERAL_DIMENSION_NAME                   = 22
%DBLITERAL_HIERARCHY_NAME                   = 23
%DBLITERAL_LEVEL_NAME                       = 24
%DBLITERAL_MEMBER_NAME                      = 25
%DBLITERAL_PROPERTY_NAME                    = 26
%DBLITERAL_SCHEMA_SEPARATOR                 = 27
%DBLITERAL_QUOTE_SUFFIX                     = 28

%DBLITERAL_ESCAPE_PERCENT_PREFIX            = %DBLITERAL_ESCAPE_PERCENT
%DBLITERAL_ESCAPE_UNDERSCORE_PREFIX         = %DBLITERAL_ESCAPE_UNDERSCORE

' DBLITERALENUM21
%DBLITERAL_ESCAPE_PERCENT_SUFFIX            = 29
%DBLITERAL_ESCAPE_UNDERSCORE_SUFFIX         = 30

' // Size = 24 bytes
TYPE DBLITERALINFO DWORD
   pwszLiteralValue         AS WSTRINGZ PTR   ' LPOLESTR
   pwszInvalidChars         AS WSTRINGZ PTR   ' LPOLESTR
   pwszInvalidStartingChars AS WSTRINGZ PTR   ' LPOLESTR
   lt                       AS DWORD          ' DBLITERAL
   fSupported               AS LONG           ' BOOL
   cchMaxLen                AS DWORD          ' ULONG
END TYPE

INTERFACE IDBInfo $IID_IDBInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetKeywords ( _                               ' VTable offset = 12
     BYREF ppwszKeywords AS DWORD _                     ' __out LPOLESTR *ppwszKeywords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLiteralInfo ( _                            ' VTable offset = 16
     BYVAL cLiterals AS DWORD _                         ' __in ULONG cLiterals
   , BYREF rgLiterals AS DWORD _                        ' __in const DBLITERAL rgLiterals[  ]
   , BYREF pcLiteralInfo AS DWORD _                     ' __inout ULONG *pcLiteralInfo
   , BYREF prgLiteralInfo AS DWORD _                    ' __out DBLITERALINFO **prgLiteralInfo
   , BYREF ppCharBuffer AS DWORD _                      ' __out OLECHAR **ppCharBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBDataSourceAdmin interface
' IID = 0C733A7A-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBDataSourceAdmin_INTERFACE_DEFINED)
    %IDBDataSourceAdmin_INTERFACE_DEFINED = 1

INTERFACE IDBDataSourceAdmin $IID_IDBDataSourceAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateDataSource ( _                          ' VTable offset = 12
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDBSession AS IUnknown _                    ' __out IUnknown **ppDBSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyDataSource ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationProperties ( _                     ' VTable offset = 20
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertyInfoSets AS DWORD _                ' __inout ULONG *pcPropertyInfoSets
   , BYREF prgPropertyInfoSets AS DWORD _               ' __out DBPROPINFOSET **prgPropertyInfoSets
   , BYREF ppDescBuffer AS DWORD _                      ' __out OLECHAR **ppDescBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyDataSource ( _                          ' VTable offset = 24
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __in DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBDataSourceAdmin_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBAsynchNotify interface
' IID = 0c733a96-2a1c-11ce-ade5-00aa0044773d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBAsynchNotify_INTERFACE_DEFINED)
    %IDBAsynchNotify_INTERFACE_DEFINED = 1

INTERFACE IDBAsynchNotify $IID_IDBAsynchNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnLowResource ( _                             ' VTable offset = 12
     BYVAL dwReserved AS DWORD _                        ' __in DB_DWRESERVE dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 16
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                        ' __in DBASYNCHOP eOperation
   , BYVAL ulProgress AS DWORD _                        ' __in DBCOUNTITEM ulProgress
   , BYVAL ulProgressMax AS DWORD _                     ' __in DBCOUNTITEM ulProgressMax
   , BYVAL eAsynchPhase AS DWORD _                      ' __in DBASYNCHPHASE eAsynchPhase
   , BYREF pwszStatusText AS WSTRINGZ _                 ' __in LPOLESTR pwszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStop ( _                                    ' VTable offset = 20
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                        ' __in DBASYNCHOP eOperation
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pwszStatusText AS WSTRINGZ _                 ' __in LPOLESTR pwszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBAsynchNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBAsynchStatus interface
' IID = 0C733A95-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBAsynchStatus_INTERFACE_DEFINED)
    %IDBAsynchStatus_INTERFACE_DEFINED = 1

INTERFACE IDBAsynchStatus $IID_IDBAsynchStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                        ' __in DBASYNCHOP eOperation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 16
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                        ' __in DBASYNCHOP eOperation
   , BYREF pulProgress AS DWORD _                       ' __out DBCOUNTITEM *pulProgress
   , BYREF pulProgressMax AS DWORD _                    ' __out DBCOUNTITEM *pulProgressMax
   , BYREF peAsynchPhase AS DWORD _                     ' __out DBASYNCHPHASE *peAsynchPhase
   , BYREF ppwszStatusText AS DWORD _                   ' __out LPOLESTR *ppwszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBAsynchStatus_INTERFACE_DEFINED__ */


' ########################################################################################
' ISessionProperties interface
' IID = 0C733A85-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISessionProperties_INTERFACE_DEFINED)
    %ISessionProperties_INTERFACE_DEFINED = 1

INTERFACE ISessionProperties $IID_ISessionProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 12
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 16
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISessionProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' IIndexDefinition interface
' IID = 0C733A68-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIndexDefinition_INTERFACE_DEFINED)
    %IIndexDefinition_INTERFACE_DEFINED = 1

INTERFACE IIndexDefinition $IID_IIndexDefinition

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateIndex ( _                               ' VTable offset = 12
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pIndexID AS DBID _                           ' __in DBID *pIndexID
   , BYVAL cIndexColumnDescs AS DWORD _                 ' __in DBORDINAL cIndexColumnDescs
   , BYREF rgIndexColumnDescs AS DBINDEXCOLUMNDESC _    ' __in const DBINDEXCOLUMNDESC rgIndexColumnDescs[  ]
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppIndexID AS DBID _                          ' __out DBID **ppIndexID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropIndex ( _                                 ' VTable offset = 16
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pIndexID AS DBID _                           ' __in DBID *pIndexID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIndexDefinition_INTERFACE_DEFINED__ */


' ########################################################################################
' ITableDefinition interface
' IID = 0C733A86-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITableDefinition_INTERFACE_DEFINED)
    %ITableDefinition_INTERFACE_DEFINED = 1

INTERFACE ITableDefinition $IID_ITableDefinition

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTable ( _                               ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYVAL cColumnDescs AS DWORD _                      ' __in DBORDINAL cColumnDescs
   , BYREF rgColumnDescs AS DBCOLUMNDESC _              ' __in const DBCOLUMNDESC rgColumnDescs[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppTableID AS DBID _                          ' __out DBID **ppTableID
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropTable ( _                                 ' VTable offset = 16
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddColumn ( _                                 ' VTable offset = 20
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnDesc AS DBCOLUMNDESC _                ' __inout DBCOLUMNDESC *pColumnDesc
   , BYREF ppColumnID AS DBID _                         ' __out DBID **ppColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropColumn ( _                                ' VTable offset = 24
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnID AS DBID _                          ' __in DBID *pColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITableDefinition_INTERFACE_DEFINED__ */


' ########################################################################################
' IOpenRowset interface
' IID = 0C733A69-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenRowset_INTERFACE_DEFINED)
    %IOpenRowset_INTERFACE_DEFINED = 1

INTERFACE IOpenRowset $IID_IOpenRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OpenRowset ( _                                ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pIndexID AS DBID _                           ' __in DBID *pIndexID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBSchemaRowset interface
' IID = 0C733A7B-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBSchemaRowset_INTERFACE_DEFINED)
    %IDBSchemaRowset_INTERFACE_DEFINED = 1

%CRESTRICTIONS_DBSCHEMA_ASSERTIONS                 = 3
%CRESTRICTIONS_DBSCHEMA_CATALOGS                   = 1
%CRESTRICTIONS_DBSCHEMA_CHARACTER_SETS             = 3
%CRESTRICTIONS_DBSCHEMA_COLLATIONS                 = 3
%CRESTRICTIONS_DBSCHEMA_COLUMNS                    = 4
%CRESTRICTIONS_DBSCHEMA_CHECK_CONSTRAINTS          = 3
%CRESTRICTIONS_DBSCHEMA_CONSTRAINT_COLUMN_USAGE    = 4
%CRESTRICTIONS_DBSCHEMA_CONSTRAINT_TABLE_USAGE     = 3
%CRESTRICTIONS_DBSCHEMA_KEY_COLUMN_USAGE           = 7
%CRESTRICTIONS_DBSCHEMA_REFERENTIAL_CONSTRAINTS    = 3
%CRESTRICTIONS_DBSCHEMA_TABLE_CONSTRAINTS          = 7
%CRESTRICTIONS_DBSCHEMA_COLUMN_DOMAIN_USAGE        = 4
%CRESTRICTIONS_DBSCHEMA_INDEXES                    = 5
%CRESTRICTIONS_DBSCHEMA_OBJECT_ACTIONS             = 1
%CRESTRICTIONS_DBSCHEMA_OBJECTS                    = 1
%CRESTRICTIONS_DBSCHEMA_COLUMN_PRIVILEGES          = 6
%CRESTRICTIONS_DBSCHEMA_TABLE_PRIVILEGES           = 5
%CRESTRICTIONS_DBSCHEMA_USAGE_PRIVILEGES           = 6
%CRESTRICTIONS_DBSCHEMA_PROCEDURES                 = 4
%CRESTRICTIONS_DBSCHEMA_SCHEMATA                   = 3
%CRESTRICTIONS_DBSCHEMA_SQL_LANGUAGES              = 0
%CRESTRICTIONS_DBSCHEMA_STATISTICS                 = 3
%CRESTRICTIONS_DBSCHEMA_TABLES                     = 4
%CRESTRICTIONS_DBSCHEMA_TRANSLATIONS               = 3
%CRESTRICTIONS_DBSCHEMA_PROVIDER_TYPES             = 2
%CRESTRICTIONS_DBSCHEMA_VIEWS                      = 3
%CRESTRICTIONS_DBSCHEMA_VIEW_COLUMN_USAGE          = 3
%CRESTRICTIONS_DBSCHEMA_VIEW_TABLE_USAGE           = 3
%CRESTRICTIONS_DBSCHEMA_PROCEDURE_PARAMETERS       = 4
%CRESTRICTIONS_DBSCHEMA_FOREIGN_KEYS               = 6
%CRESTRICTIONS_DBSCHEMA_PRIMARY_KEYS               = 3
%CRESTRICTIONS_DBSCHEMA_PROCEDURE_COLUMNS          = 4
%CRESTRICTIONS_DBSCHEMA_TABLES_INFO                = 4
%CRESTRICTIONS_MDSCHEMA_CUBES                      = 3
%CRESTRICTIONS_MDSCHEMA_DIMENSIONS                 = 5
%CRESTRICTIONS_MDSCHEMA_HIERARCHIES                = 6
%CRESTRICTIONS_MDSCHEMA_LEVELS                     = 7
%CRESTRICTIONS_MDSCHEMA_MEASURES                   = 5
%CRESTRICTIONS_MDSCHEMA_PROPERTIES                 = 9
%CRESTRICTIONS_MDSCHEMA_MEMBERS                    = 12
%CRESTRICTIONS_DBSCHEMA_TRUSTEE                    = 4
%CRESTRICTIONS_DBSCHEMA_TABLE_STATISTICS           = 7
%CRESTRICTIONS_DBSCHEMA_CHECK_CONSTRAINTS_BY_TABLE = 6
%CRESTRICTIONS_MDSCHEMA_FUNCTIONS                  = 4
%CRESTRICTIONS_MDSCHEMA_ACTIONS                    = 8
%CRESTRICTIONS_MDSCHEMA_COMMANDS                   = 5
%CRESTRICTIONS_MDSCHEMA_SETS                       = 5

INTERFACE IDBSchemaRowset $IID_IDBSchemaRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRowset ( _                                 ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF rguidSchema AS GUID _                        ' __in REFGUID rguidSchema
   , BYVAL cRestrictions AS DWORD _                     ' __in ULONG cRestrictions
   , BYREF rgRestrictions AS VARIANT _                  ' __in const VARIANT rgRestrictions[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSchemas ( _                                ' VTable offset = 16
     BYREF pcSchemas AS DWORD _                         ' __inout ULONG *pcSchemas
   , BYREF prgSchemas AS DWORD _                        ' __out GUID **prgSchemas
   , BYREF prgRestrictionSupport AS DWORD _             ' __out ULONG **prgRestrictionSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBSchemaRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IMDDataset interface
' IID = A07CCCD1-8148-11D0-87BB-00C04FC33942
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMDDataset_INTERFACE_DEFINED)
    %IMDDataset_INTERFACE_DEFINED = 1

INTERFACE IMDDataset $IID_IMDDataset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FreeAxisInfo ( _                              ' VTable offset = 12
     BYVAL cAxes AS DWORD _                             ' __in DBCOUNTITEM cAxes
   , BYREF rgAxisInfo AS MDAXISINFO _                   ' __in MDAXISINFO *rgAxisInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAxisInfo ( _                               ' VTable offset = 16
     BYREF pcAxes AS DWORD _                            ' __inout DBCOUNTITEM *pcAxes
   , BYREF prgAxisInfo AS DWORD _                       ' __out MDAXISINFO **prgAxisInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAxisRowset ( _                             ' VTable offset = 20
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL iAxis AS DWORD _                             ' __in DBCOUNTITEM iAxis
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCellData ( _                               ' VTable offset = 24
     BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL ulStartCell AS DWORD _                       ' __in DBORDINAL ulStartCell
   , BYVAL ulEndCell AS DWORD _                         ' __in DBORDINAL ulEndCell
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecification ( _                          ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSpecification AS IUnknown _                ' __out IUnknown **ppSpecification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMDDataset_INTERFACE_DEFINED__ */


' ########################################################################################
' IMDFind interface
' IID = A07CCCD2-8148-11D0-87BB-00C04FC33942
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMDFind_INTERFACE_DEFINED)
    %IMDFind_INTERFACE_DEFINED = 1


INTERFACE IMDFind $IID_IMDFind

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindCell ( _                                  ' VTable offset = 12
     BYVAL ulStartingOrdinal AS DWORD _                 ' __in DBORDINAL ulStartingOrdinal
   , BYVAL cMembers AS DWORD _                          ' __in DBCOUNTITEM cMembers
   , BYREF rgpwszMember AS WSTRINGZ _                   ' __in LPCOLESTR *rgpwszMember
   , BYREF pulCellOrdinal AS DWORD _                    ' __out DBORDINAL *pulCellOrdinal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindTuple ( _                                 ' VTable offset = 16
     BYVAL ulAxisIdentifier AS DWORD _                  ' __in ULONG ulAxisIdentifier
   , BYVAL ulStartingOrdinal AS DWORD _                 ' __in DBORDINAL ulStartingOrdinal
   , BYVAL cMembers AS DWORD _                          ' __in DBCOUNTITEM cMembers
   , BYREF rgpwszMember AS WSTRINGZ _                   ' __in LPCOLESTR *rgpwszMember
   , BYREF pulTupleOrdinal AS DWORD _                   ' __out ULONG *pulTupleOrdinal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMDFind_INTERFACE_DEFINED__ */


' ########################################################################################
' IMDRangeRowset interface
' IID = 0C733AA0-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMDRangeRowset_INTERFACE_DEFINED)
    %IMDRangeRowset_INTERFACE_DEFINED = 1

INTERFACE IMDRangeRowset $IID_IMDRangeRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRangeRowset ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL ulStartCell AS DWORD _                       ' __in DBORDINAL ulStartCell
   , BYVAL ulEndCell AS DWORD _                         ' __in DBORDINAL ulEndCell
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMDRangeRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IAlterTable interface
' IID = 0C733AA5-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAlterTable_INTERFACE_DEFINED)
    %IAlterTable_INTERFACE_DEFINED = 1

INTERFACE IAlterTable $IID_IAlterTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AlterColumn ( _                               ' VTable offset = 12
     BYREF pTableId AS DBID _                           ' __in DBID *pTableId
   , BYREF pColumnId AS DBID _                          ' __in DBID *pColumnId
   , BYVAL dwColumnDescFlags AS DWORD _                 ' __in DBCOLUMNDESCFLAGS dwColumnDescFlags
   , BYREF pColumnDesc AS DBCOLUMNDESC _                ' __in DBCOLUMNDESC *pColumnDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AlterTable ( _                                ' VTable offset = 16
     BYREF pTableId AS DBID _                           ' __in DBID *pTableId
   , BYREF pNewTableId AS DBID _                        ' __in DBID *pNewTableId
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAlterTable_INTERFACE_DEFINED__ */


' ########################################################################################
' IAlterIndex interface
' IID = 0C733AA6-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAlterIndex_INTERFACE_DEFINED)
    %IAlterIndex_INTERFACE_DEFINED = 1

INTERFACE IAlterIndex $IID_IAlterIndex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AlterIndex ( _                                ' VTable offset = 12
     BYREF pTableId AS DBID _                           ' __in DBID *pTableId
   , BYREF pIndexId AS DBID _                           ' __in DBID *pIndexId
   , BYREF pNewIndexId AS DBID _                        ' __in DBID *pNewIndexId
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAlterIndex_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetChapterMember interface
' IID = 0C733AA8-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetChapterMember_INTERFACE_DEFINED)
    %IRowsetChapterMember_INTERFACE_DEFINED = 1

INTERFACE IRowsetChapterMember $IID_IRowsetChapterMember

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsRowInChapter ( _                            ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetChapterMember_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandPersist interface
' IID = 0C733AA7-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandPersist_INTERFACE_DEFINED)
    %ICommandPersist_INTERFACE_DEFINED = 1

INTERFACE ICommandPersist $IID_ICommandPersist

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeleteCommand ( _                             ' VTable offset = 12
     BYREF pCommandID AS DBID _                         ' __in DBID *pCommandID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentCommand ( _                         ' VTable offset = 16
     BYREF ppCommandID AS DBID _                        ' __out DBID **ppCommandID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadCommand ( _                               ' VTable offset = 20
     BYREF pCommandID AS DBID _                         ' __in DBID *pCommandID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCommand ( _                               ' VTable offset = 24
     BYREF pCommandID AS DBID _                         ' __in DBID *pCommandID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandPersist_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetRefresh interface
' IID = 0C733AA9-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetRefresh_INTERFACE_DEFINED)
    %IRowsetRefresh_INTERFACE_DEFINED = 1

INTERFACE IRowsetRefresh $IID_IRowsetRefresh

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RefreshVisibleData ( _                        ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYVAL fOverWrite AS LONG _                         ' __in BOOL fOverWrite
   , BYREF pcRowsRefreshed AS DWORD _                   ' __out DBCOUNTITEM *pcRowsRefreshed
   , BYREF prghRowsRefreshed AS DWORD _                 ' __out HROW **prghRowsRefreshed
   , BYREF prgRowStatus AS DWORD _                      ' __out DBROWSTATUS **prgRowStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastVisibleData ( _                        ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetRefresh_INTERFACE_DEFINED__ */


' ########################################################################################
' IParentRowset interface
' IID = 0C733AAA-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IParentRowset_INTERFACE_DEFINED)
    %IParentRowset_INTERFACE_DEFINED = 1

INTERFACE IParentRowset $IID_IParentRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChildRowset ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL iOrdinal AS DWORD _                          ' __in DBORDINAL iOrdinal
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IParentRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IErrorRecords interface
' IID = 0C733A67-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IErrorRecords_INTERFACE_DEFINED)
    %IErrorRecords_INTERFACE_DEFINED = 1

%IDENTIFIER_SDK_MASK  = &HF0000000???
%IDENTIFIER_SDK_ERROR = &H10000000???

INTERFACE IErrorRecords $IID_IErrorRecords

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddErrorRecord ( _                            ' VTable offset = 12
     BYREF pErrorInfo AS ERRORINFO _                    ' __in ERRORINFO *pErrorInfo
   , BYVAL dwLookupID AS DWORD _                        ' __in DWORD dwLookupID
   , BYREF pdispparams AS DISPPARAMS _                  ' __in DISPPARAMS *pdispparams
   , BYVAL punkCustomError AS IUnknown _                ' __in IUnknown *punkCustomError
   , BYVAL dwDynamicErrorID AS DWORD _                  ' __in DWORD dwDynamicErrorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBasicErrorInfo ( _                         ' VTable offset = 16
     BYVAL ulRecordNum AS DWORD _                       ' __in ULONG ulRecordNum
   , BYREF pErrorInfo AS ERRORINFO _                    ' __out ERRORINFO *pErrorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomErrorObject ( _                      ' VTable offset = 20
     BYVAL ulRecordNum AS DWORD _                       ' __in ULONG ulRecordNum
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorInfo ( _                              ' VTable offset = 24
     BYVAL ulRecordNum AS DWORD _                       ' __in ULONG ulRecordNum
   , BYVAL lcid AS DWORD  _                             ' __in LCID lcid
   , BYREF ppErrorInfo AS IErrorInfo _                  ' __out IErrorInfo **ppErrorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorParameters ( _                        ' VTable offset = 28
     BYVAL ulRecordNum AS DWORD _                       ' __in ULONG ulRecordNum
   , BYREF pdispparams AS DISPPARAMS _                  ' __out DISPPARAMS *pdispparams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCount ( _                            ' VTable offset = 32
     BYREF pcRecords AS DWORD _                         ' __out ULONG *pcRecords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IErrorRecords_INTERFACE_DEFINED__ */


' ########################################################################################
' IErrorLookup interface
' IID = 0C733A66-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IErrorLookup_INTERFACE_DEFINED)
    %IErrorLookup_INTERFACE_DEFINED = 1

INTERFACE IErrorLookup $IID_IErrorLookup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetErrorDescription ( _                       ' VTable offset = 12
     BYVAL hrError AS DWORD _                           ' __in HRESULT hrError
   , BYVAL dwLookupID AS DWORD _                        ' __in DWORD dwLookupID
   , BYREF pdispparams AS DISPPARAMS _                  ' __in DISPPARAMS *pdispparams
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF pbstrSource AS WSTRING _                     ' __out BSTR *pbstrSource
   , BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelpInfo ( _                               ' VTable offset = 16
     BYVAL hrError AS DWORD _                           ' __in HRESULT hrError
   , BYVAL dwLookupID AS DWORD _                        ' __in DWORD dwLookupID
   , BYVAL lcid AS DWORD  _                             ' __in LCID lcid
   , BYREF pbstrHelpFile AS WSTRING _                   ' __out BSTR *pbstrHelpFile
   , BYREF pdwHelpContext AS DWORD _                    ' __out DWORD *pdwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseErrors ( _                             ' VTable offset = 20
     BYVAL dwDynamicErrorID AS DWORD _                  ' __in const DWORD dwDynamicErrorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IErrorLookup_INTERFACE_DEFINED__ */


' ########################################################################################
' ISQLErrorInfo interface
' IID = 0C733A74-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISQLErrorInfo_INTERFACE_DEFINED)
    %ISQLErrorInfo_INTERFACE_DEFINED = 1

INTERFACE ISQLErrorInfo $IID_ISQLErrorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSQLInfo ( _                                ' VTable offset = 12
     BYREF pbstrSQLState AS WSTRING _                   ' __out BSTR *pbstrSQLState
   , BYREF plNativeError AS LONG _                      ' __out LONG *plNativeError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLErrorInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IGetDataSource interface
' IID = 0C733A67-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetDataSource_INTERFACE_DEFINED)
    %IGetDataSource_INTERFACE_DEFINED = 1

INTERFACE IGetDataSource $IID_IGetDataSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDataSource ( _                             ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDataSource AS IUnknown _                   ' __out IUnknown **ppDataSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetDataSource_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionLocal interface
' IID = 0C733A5F-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = ITransaction
' ########################################################################################

#IF NOT %DEF(%ITransactionLocal_INTERFACE_DEFINED)
    %ITransactionLocal_INTERFACE_DEFINED = 1

INTERFACE ITransactionLocal $IID_ITransactionLocal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfTC AS DWORD _                             ' __in DWORD grfTC
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
     BYVAL pboidReason AS DWORD _                       ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL fAsync AS LONG _                             ' __in BOOL fAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionInfo ( _                        ' VTable offset = 20
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptionsObject ( _                          ' VTable offset = 12
     BYREF ppOptions AS ITransactionOptions _           ' __out ITransactionOptions **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartTransaction ( _                          ' VTable offset = 16
     BYVAL isoLevel AS LONG _                           ' __in ISOLEVEL isoLevel
   , BYVAL isoFlags AS DWORD _                          ' __in ULONG isoFlags
   , BYVAL pOtherOptions AS ITransactionOptions _       ' __in ITransactionOptions *pOtherOptions
   , BYREF pulTransactionLevel AS DWORD _               ' __out ULONG *pulTransactionLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionLocal_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionJoin interface
' IID = 0C733A5E-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionJoin_INTERFACE_DEFINED)
    %ITransactionJoin_INTERFACE_DEFINED = 1

INTERFACE ITransactionJoin $IID_ITransactionJoin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
     BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL grfTC AS DWORD _                             ' __in DWORD grfTC
   , BYVAL grfRM AS DWORD _                             ' __in DWORD grfRM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 16
     BYVAL pboidReason AS DWORD _                       ' __in BOID *pboidReason
   , BYVAL fRetaining AS LONG _                         ' __in BOOL fRetaining
   , BYVAL fAsync AS LONG _                             ' __in BOOL fAsync
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransactionInfo ( _                        ' VTable offset = 20
     BYREF pinfo AS XACTTRANSINFO _                     ' __out XACTTRANSINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptionsObject ( _                          ' VTable offset = 24
     BYREF ppOptions AS ITransactionOptions _           ' __out ITransactionOptions **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartTransaction ( _                          ' VTable offset = 28
     BYVAL punkTransactionCoord AS IUnknown _           ' __in IUnknown *punkTransactionCoord
   , BYVAL isoLevel AS LONG _                           ' __in ISOLEVEL isoLevel
   , BYVAL isoFlags AS DWORD _                          ' __in ULONG isoFlags
   , BYVAL pOtherOptions AS DWORD _                     ' __in ITransactionOptions *pOtherOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionJoin_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransactionObject interface
' IID = 0C733A60-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransactionObject_INTERFACE_DEFINED)
    %ITransactionObject_INTERFACE_DEFINED = 1

INTERFACE ITransactionObject $IID_ITransactionObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTransactionObject ( _                      ' VTable offset = 12
     BYVAL ulTransactionLevel AS DWORD _                ' __in ULONG ulTransactionLevel
   , BYREF ppTransactionObject AS ITransaction _        ' __out ITransaction **ppTransactionObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransactionObject_INTERFACE_DEFINED__ */


' ########################################################################################
' ITrusteeAdmin interface
' IID = 0C733AA1-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITrusteeAdmin_INTERFACE_DEFINED)
    %ITrusteeAdmin_INTERFACE_DEFINED = 1

INTERFACE ITrusteeAdmin $IID_ITrusteeAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CompareTrustees ( _                           ' VTable offset = 12
     BYREF pTrustee1 AS TRUSTEE_W _                     ' __in TRUSTEE_W *pTrustee1
   , BYREF pTrustee2 AS TRUSTEE_W _                     ' __in TRUSTEE_W *pTrustee2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTrustee ( _                             ' VTable offset = 16
     BYREF pTrustee AS TRUSTEE_W _                      ' __in TRUSTEE_W *pTrustee
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTrustee ( _                             ' VTable offset = 20
     BYREF pTrustee AS TRUSTEE_W _                      ' __in TRUSTEE_W *pTrustee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrusteeProperties ( _                      ' VTable offset = 24
     BYREF pTrustee AS TRUSTEE_W _                      ' __in TRUSTEE_W *pTrustee
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTrusteeProperties ( _                      ' VTable offset = 28
     BYREF pTrustee AS TRUSTEE_W _                      ' __in TRUSTEE_W *pTrustee
   , BYVAL cPropertyIDSets AS DWORD _                   ' __in const ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITrusteeAdmin_INTERFACE_DEFINED__ */


' ########################################################################################
' ITrusteeGroupAdmin interface
' IID = 0C733AA2-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITrusteeGroupAdmin_INTERFACE_DEFINED)
    %ITrusteeGroupAdmin_INTERFACE_DEFINED = 1

INTERFACE ITrusteeGroupAdmin $IID_ITrusteeGroupAdmin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddMember ( _                                 ' VTable offset = 12
     BYREF pMembershipTrustee AS TRUSTEE_W _            ' __in TRUSTEE_W *pMembershipTrustee
   , BYREF pMemberTrustee AS TRUSTEE_W _                ' __in TRUSTEE_W *pMemberTrustee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteMember ( _                              ' VTable offset = 16
     BYREF pMembershipTrustee AS TRUSTEE_W _            ' __in TRUSTEE_W *pMembershipTrustee
   , BYREF pMemberTrustee AS TRUSTEE_W _                ' __in TRUSTEE_W *pMemberTrustee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsMember ( _                                  ' VTable offset = 20
     BYREF pMembershipTrustee AS TRUSTEE_W _            ' __in TRUSTEE_W *pMembershipTrustee
   , BYREF pMemberTrustee AS TRUSTEE_W _                ' __in TRUSTEE_W *pMemberTrustee
   , BYREF pfStatus AS LONG _                           ' __out BOOL *pfStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMembers ( _                                ' VTable offset = 24
     BYREF pMembershipTrustee AS TRUSTEE_W _            ' __in TRUSTEE_W *pMembershipTrustee
   , BYREF pcMembers AS DWORD _                         ' __out ULONG *pcMembers
   , BYREF prgMembers AS DWORD _                        ' __out TRUSTEE_W **prgMembers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemberships ( _                            ' VTable offset = 28
     BYREF pTrustee AS TRUSTEE_W _                      ' __in TRUSTEE_W *pTrustee
   , BYREF pcMemberships AS DWORD _                     ' __out ULONG *pcMemberships
   , BYREF prgMemberships AS DWORD _                    ' __out TRUSTEE_W **prgMemberships
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITrusteeGroupAdmin_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectAccessControl interface
' IID = 0C733AA3-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectAccessControl_INTERFACE_DEFINED)
    %IObjectAccessControl_INTERFACE_DEFINED = 1

INTERFACE IObjectAccessControl $IID_IObjectAccessControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetObjectAccessRights ( _                     ' VTable offset = 12
     BYREF pObject AS SEC_OBJECT _                      ' __in SEC_OBJECT *pObject
   , BYREF pcAccessEntries AS DWORD _                   ' __inout ULONG *pcAccessEntries
   , BYREF prgAccessEntries AS EXPLICIT_ACCESS_W _      ' __inout EXPLICIT_ACCESS_W **prgAccessEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectOwner ( _                            ' VTable offset = 16
     BYREF pObject AS SEC_OBJECT _                      ' __in SEC_OBJECT *pObject
   , BYREF ppOwner AS TRUSTEE_W _                       ' __out TRUSTEE_W **ppOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsObjectAccessAllowed ( _                     ' VTable offset = 20
     BYREF pObject AS SEC_OBJECT _                      ' __in SEC_OBJECT *pObject
   , BYREF pAccessEntry AS EXPLICIT_ACCESS_W _          ' __in EXPLICIT_ACCESS_W *pAccessEntry
   , BYREF pfResult AS LONG _                           ' __out BOOL *pfResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjectAccessRights ( _                     ' VTable offset = 24
     BYREF pObject AS SEC_OBJECT _                      ' __in SEC_OBJECT *pObject
   , BYVAL cAccessEntries AS DWORD _                    ' __in ULONG cAccessEntries
   , BYREF prgAccessEntries AS EXPLICIT_ACCESS_W _      ' __inout EXPLICIT_ACCESS_W **prgAccessEntries
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetObjectOwner ( _                            ' VTable offset = 28
     BYREF pObject AS SEC_OBJECT _                      ' __in SEC_OBJECT *pObject
   , BYREF pOwner AS TRUSTEE_W _                        ' __in TRUSTEE_W *pOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectAccessControl_INTERFACE_DEFINED__ */


' ########################################################################################
' ISecurityInfo interface
' IID = 0C733AA4-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISecurityInfo_INTERFACE_DEFINED)
    %ISecurityInfo_INTERFACE_DEFINED = 1

' // Already defined in WinNT.inc
'typedef DWORD ACCESS_MASK;

' ACCESS_MASKENUM
%PERM_EXCLUSIVE        = &H200???
%PERM_READDESIGN       = &H400???
%PERM_WRITEDESIGN      = &H800???
%PERM_WITHGRANT        = &H1000???
%PERM_REFERENCE        = &H2000???
%PERM_CREATE           = &H4000???
%PERM_INSERT           = &H8000???
%PERM_DELETE           = &H10000???
%PERM_READCONTROL      = &H20000???
%PERM_WRITEPERMISSIONS = &H40000???
%PERM_WRITEOWNER       = &H80000???
%PERM_MAXIMUM_ALLOWED  = &H2000000???
%PERM_ALL              = &H10000000???
%PERM_EXECUTE          = &H20000000???
%PERM_READ             = &H80000000???
%PERM_UPDATE           = &H40000000???
%PERM_DROP             = &H100???
%PERM_DESIGN           = %PERM_WRITEDESIGN

INTERFACE ISecurityInfo $IID_ISecurityInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentTrustee ( _                         ' VTable offset = 12
     BYREF ppTrustee AS TRUSTEE_W _                     ' __out TRUSTEE_W **ppTrustee
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectTypes ( _                            ' VTable offset = 16
     BYREF cObjectTypes AS DWORD _                      ' __out ULONG *cObjectTypes
   , BYREF rgObjectTypes AS GUID _                      ' __out GUID **rgObjectTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPermissions ( _                            ' VTable offset = 20
     BYREF ObjectType AS GUID _                         ' __in GUID ObjectType
   , BYREF pPermissions AS ACCESS_MASK _                ' __out ACCESS_MASK *pPermissions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecurityInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' ITableCreation interface
' IID = 0C733ABC-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = ITableDefinition
' ########################################################################################

#IF NOT %DEF(%ITableCreation_INTERFACE_DEFINED)
    %ITableCreation_INTERFACE_DEFINED = 1

INTERFACE ITableCreation $IID_ITableCreation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTable ( _                               ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYVAL cColumnDescs AS DWORD _                      ' __in DBORDINAL cColumnDescs
   , BYREF rgColumnDescs AS DBCOLUMNDESC _              ' __in const DBCOLUMNDESC rgColumnDescs[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppTableID AS DBID _                          ' __out DBID **ppTableID
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropTable ( _                                 ' VTable offset = 16
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddColumn ( _                                 ' VTable offset = 20
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnDesc AS DBCOLUMNDESC _                ' __inout DBCOLUMNDESC *pColumnDesc
   , BYREF ppColumnID AS DBID _                         ' __out DBID **ppColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropColumn ( _                                ' VTable offset = 24
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnID AS DBID _                          ' __in DBID *pColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDefinition ( _                        ' VTable offset = 28
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pcColumnDescs AS DWORD _                     ' __out DBORDINAL *pcColumnDescs
   , BYREF prgColumnDescs AS DBCOLUMNDESC _             ' __out DBCOLUMNDESC *prgColumnDescs[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __out ULONG *pcPropertySets
   , BYREF prgPropertySets AS DBPROPSET _               ' __out DBPROPSET *prgPropertySets[  ]
   , BYREF pcConstraintDescs AS DWORD _                 ' __out ULONG *pcConstraintDescs
   , BYREF prgConstraintDescs AS DBCONSTRAINTDESC _     ' __out DBCONSTRAINTDESC *prgConstraintDescs[  ]
   , BYREF ppwszStringBuffer AS DWORD _                 ' __out OLECHAR **ppwszStringBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITableCreation_INTERFACE_DEFINED__ */


' ########################################################################################
' ITableDefinitionWithConstraints interface
' IID = 0C733AAB-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = ITableCreation
' ########################################################################################

#IF NOT %DEF(%ITableDefinitionWithConstraints_INTERFACE_DEFINED)
    %ITableDefinitionWithConstraints_INTERFACE_DEFINED = 1

INTERFACE ITableDefinitionWithConstraints $IID_ITableDefinitionWithConstraints

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTable ( _                               ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYVAL cColumnDescs AS DWORD _                      ' __in DBORDINAL cColumnDescs
   , BYREF rgColumnDescs AS DBCOLUMNDESC _              ' __in const DBCOLUMNDESC rgColumnDescs[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppTableID AS DBID _                          ' __out DBID **ppTableID
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropTable ( _                                 ' VTable offset = 16
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddColumn ( _                                 ' VTable offset = 20
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnDesc AS DBCOLUMNDESC _                ' __inout DBCOLUMNDESC *pColumnDesc
   , BYREF ppColumnID AS DBID _                         ' __out DBID **ppColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropColumn ( _                                ' VTable offset = 24
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pColumnID AS DBID _                          ' __in DBID *pColumnID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTableDefinition ( _                        ' VTable offset = 28
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pcColumnDescs AS DWORD _                     ' __out DBORDINAL *pcColumnDescs
   , BYREF prgColumnDescs AS DBCOLUMNDESC _             ' __out DBCOLUMNDESC *prgColumnDescs[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __out ULONG *pcPropertySets
   , BYREF prgPropertySets AS DBPROPSET _               ' __out DBPROPSET *prgPropertySets[  ]
   , BYREF pcConstraintDescs AS DWORD _                 ' __out ULONG *pcConstraintDescs
   , BYREF prgConstraintDescs AS DBCONSTRAINTDESC _     ' __out DBCONSTRAINTDESC *prgConstraintDescs[  ]
   , BYREF ppwszStringBuffer AS DWORD _                 ' __out OLECHAR **ppwszStringBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddConstraint ( _                             ' VTable offset = 32
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pConstraintDesc AS DBCONSTRAINTDESC _        ' __in DBCONSTRAINTDESC *pConstraintDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTableWithConstraints ( _                ' VTable offset = 36
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYVAL cColumnDescs AS DWORD _                      ' __in DBORDINAL cColumnDescs
   , BYREF rgColumnDescs AS DBCOLUMNDESC _              ' __inout DBCOLUMNDESC rgColumnDescs[  ]
   , BYVAL cConstraintDescs AS DWORD _                  ' __in ULONG cConstraintDescs
   , BYREF rgConstraintDescs AS DBCONSTRAINTDESC _      ' __in DBCONSTRAINTDESC rgConstraintDescs[  ]
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppTableID AS DBID _                          ' __out DBID **ppTableID
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropConstraint ( _                            ' VTable offset = 40
     BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pConstraintID AS DBID _                      ' __in DBID *pConstraintID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITableDefinitionWithConstraints_INTERFACE_DEFINED__ */


' ########################################################################################
' IRow interface
' IID = 0C733AB4-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRow_INTERFACE_DEFINED)
    %IRow_INTERFACE_DEFINED = 1

INTERFACE IRow $IID_IRow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColumns ( _                                ' VTable offset = 12
     BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
   , BYREF rgColumns AS DBCOLUMNACCESS _                ' __inout DBCOLUMNACCESS rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceRowset ( _                           ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   , BYREF phRow AS DWORD _                             ' __out HROW *phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 20
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pColumnID AS DBID _                          ' __in DBID *pColumnID
   , BYREF rguidColumnType AS GUID _                    ' __in REFGUID rguidColumnType
   , BYVAL dwBindFlags AS DWORD _                       ' __in DWORD dwBindFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRow_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowChange interface
' IID = 0C733AB5-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowChange_INTERFACE_DEFINED)
    %IRowChange_INTERFACE_DEFINED = 1

INTERFACE IRowChange $IID_IRowChange

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetColumns ( _                                ' VTable offset = 12
     BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
   , BYREF rgColumns AS DBCOLUMNACCESS _                ' __inout DBCOLUMNACCESS rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowChange_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowSchemaChange interface
' IID = 0C733AAE-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowChange
' ########################################################################################

#IF NOT %DEF(%IRowSchemaChange_INTERFACE_DEFINED)
    %IRowSchemaChange_INTERFACE_DEFINED = 1

INTERFACE IRowSchemaChange $IID_IRowSchemaChange

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetColumns ( _                                ' VTable offset = 12
     BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
   , BYREF rgColumns AS DBCOLUMNACCESS _                ' __inout DBCOLUMNACCESS rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteColumns ( _                             ' VTable offset = 16
     BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
   , BYREF rgColumnIDs AS DBID _                        ' __in const DBID rgColumnIDs[  ]
   , BYREF rgdwStatus AS DWORD _                        ' __inout DBSTATUS rgdwStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddColumns ( _                                ' VTable offset = 20
     BYVAL cColumns AS DWORD _                          ' __in DBORDINAL cColumns
   , BYREF rgNewColumnInfo AS DBCOLUMNINFO _            ' __in const DBCOLUMNINFO rgNewColumnInfo[  ]
   , BYREF rgColumns AS DBCOLUMNACCESS _                ' __inout DBCOLUMNACCESS rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowSchemaChange_INTERFACE_DEFINED__ */


' ########################################################################################
' IGetRow interface
' IID = 0C733AAF-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetRow_INTERFACE_DEFINED)
    %IGetRow_INTERFACE_DEFINED = 1

INTERFACE IGetRow $IID_IGetRow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRowFromHROW ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURLFromHROW ( _                            ' VTable offset = 16
     BYVAL hRow AS DWORD _                              ' __in HROW hRow
   , BYREF ppwszURL AS DWORD _                          ' __out LPOLESTR *ppwszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetRow_INTERFACE_DEFINED__ */


' ########################################################################################
' IBindResource interface
' IID = 0C733AB1-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBindResource_INTERFACE_DEFINED)
    %IBindResource_INTERFACE_DEFINED = 1

INTERFACE IBindResource $IID_IBindResource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Bind ( _                                      ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwBindURLFlags AS DWORD _                    ' __in DBBINDURLFLAG dwBindURLFlags
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pAuthenticate AS IAuthenticate _             ' __in IAuthenticate *pAuthenticate
   , BYREF pImplSession AS DBIMPLICITSESSION _          ' __inout DBIMPLICITSESSION *pImplSession
   , BYREF pdwBindStatus AS DWORD _                     ' __inout DBBINDURLSTATUS *pdwBindStatus
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBindResource_INTERFACE_DEFINED__ */


' ########################################################################################
' IScopedOperations interface
' IID = 0C733AB0-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IBindResource
' ########################################################################################

#IF NOT %DEF(%IScopedOperations_INTERFACE_DEFINED)
    %IScopedOperations_INTERFACE_DEFINED = 1

'typedef DWORD DBCOPYFLAGS;

' DBCOPYFLAGSENUM
%DBCOPY_ASYNC                               = &H100???
%DBCOPY_REPLACE_EXISTING                    = &H200???
%DBCOPY_ALLOW_EMULATION                     = &H400???
%DBCOPY_NON_RECURSIVE                       = &H800???
%DBCOPY_ATOMIC                              = &H1000???

'typedef DWORD DBMOVEFLAGS;

' DBMOVEFLAGSENUM
%DBMOVE_REPLACE_EXISTING                    = &H1???
%DBMOVE_ASYNC                               = &H100???
%DBMOVE_DONT_UPDATE_LINKS                   = &H200???
%DBMOVE_ALLOW_EMULATION                     = &H400???
%DBMOVE_ATOMIC                              = &H1000???

'typedef DWORD DBDELETEFLAGS;

' DBDELETEFLAGSENUM
%DBDELETE_ASYNC                             = &H100???
%DBDELETE_ATOMIC                            = &H1000???

INTERFACE IScopedOperations $IID_IScopedOperations

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Bind ( _                                      ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwBindURLFlags AS DWORD _                    ' __in DBBINDURLFLAG dwBindURLFlags
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pAuthenticate AS IAuthenticate _             ' __in IAuthenticate *pAuthenticate
   , BYREF pImplSession AS DBIMPLICITSESSION _          ' __inout DBIMPLICITSESSION *pImplSession
   , BYREF pdwBindStatus AS DWORD _                     ' __inout DBBINDURLSTATUS *pdwBindStatus
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 16
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgpwszSourceURLs AS WSTRINGZ _               ' __in LPCOLESTR rgpwszSourceURLs[  ]
   , BYREF rgpwszDestURLs AS WSTRINGZ _                 ' __in LPCOLESTR rgpwszDestURLs[  ]
   , BYVAL dwCopyFlags AS DWORD _                       ' __in DWORD dwCopyFlags
   , BYVAL pAuthenticate AS IAuthenticate _             ' __in IAuthenticate *pAuthenticate
   , BYREF rgdwStatus AS DWORD _                        ' __inout DBSTATUS rgdwStatus[  ]
   , BYREF rgpwszNewURLs AS WSTRINGZ _                  ' __out LPOLESTR rgpwszNewURLs[  ]
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 20
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgpwszSourceURLs AS WSTRINGZ _               ' __in LPCOLESTR rgpwszSourceURLs[  ]
   , BYREF rgpwszDestURLs AS WSTRINGZ _                 ' __in LPCOLESTR rgpwszDestURLs[  ]
   , BYVAL dwMoveFlags AS DWORD _                       ' __in DWORD dwMoveFlags
   , BYVAL pAuthenticate AS IAuthenticate _             ' __in IAuthenticate *pAuthenticate
   , BYREF rgdwStatus AS DWORD _                        ' __inout DBSTATUS rgdwStatus[  ]
   , BYREF rgpwszNewURLs AS WSTRINGZ _                  ' __out LPOLESTR rgpwszNewURLs[  ]
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 24
     BYVAL cRows AS DWORD _                             ' __in DBCOUNTITEM cRows
   , BYREF rgpwszURLs AS WSTRINGZ _                     ' __in LPCOLESTR rgpwszURLs[  ]
   , BYVAL dwDeleteFlags AS DWORD _                     ' __in DWORD dwDeleteFlags
   , BYREF rgdwStatus AS DWORD _                        ' __inout DBSTATUS rgdwStatus[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenRowset ( _                                ' VTable offset = 28
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pTableID AS DBID _                           ' __in DBID *pTableID
   , BYREF pIndexID AS DBID _                           ' __in DBID *pIndexID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   , BYREF ppRowset AS IUnknown _                       ' __out IUnknown **ppRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScopedOperations_INTERFACE_DEFINED__ */


' ########################################################################################
' ICreateRow interface
' IID = 0C733AB2-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateRow_INTERFACE_DEFINED)
    %ICreateRow_INTERFACE_DEFINED = 1

INTERFACE ICreateRow $IID_ICreateRow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateRow ( _                                 ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwBindURLFlags AS DWORD _                    ' __in DBBINDURLFLAG dwBindURLFlags
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pAuthenticate AS IAuthenticate _             ' __in IAuthenticate *pAuthenticate
   , BYREF pImplSession AS DBIMPLICITSESSION _          ' __inout DBIMPLICITSESSION *pImplSession
   , BYREF pdwBindStatus AS DWORD _                     ' __inout DBBINDURLSTATUS *pdwBindStatus
   , BYREF ppwszNewURL AS DWORD _                       ' __out LPOLESTR *ppwszNewURL
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateRow_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBBinderProperties interface
' IID = 0C733AB3-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IDBProperties
' ########################################################################################

#IF NOT %DEF(%IDBBinderProperties_INTERFACE_DEFINED)
    %IDBBinderProperties_INTERFACE_DEFINED = 1

INTERFACE IDBBinderProperties $IID_IDBBinderProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 12
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertySets AS DWORD _                    ' __inout ULONG *pcPropertySets
   , BYREF prgPropertySets AS DWORD _                   ' __out DBPROPSET **prgPropertySets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyInfo ( _                           ' VTable offset = 16
     BYVAL cPropertyIDSets AS DWORD _                   ' __in ULONG cPropertyIDSets
   , BYREF rgPropertyIDSets AS DBPROPIDSET _            ' __in const DBPROPIDSET rgPropertyIDSets[  ]
   , BYREF pcPropertyInfoSets AS DWORD _                ' __inout ULONG *pcPropertyInfoSets
   , BYREF prgPropertyInfoSets AS DWORD _               ' __out DBPROPINFOSET **prgPropertyInfoSets
   , BYREF ppDescBuffer AS DWORD _                      ' __out OLECHAR **ppDescBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 20
     BYVAL cPropertySets AS DWORD _                     ' __in ULONG cPropertySets
   , BYREF rgPropertySets AS DBPROPSET _                ' __inout DBPROPSET rgPropertySets[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBBinderProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' IColumnsInfo2 interface
' IID = 0C733AB8-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IColumnsInfo
' ########################################################################################

#IF NOT %DEF(%IColumnsInfo2_INTERFACE_DEFINED)
    %IColumnsInfo2_INTERFACE_DEFINED = 1

INTERFACE IColumnsInfo2 $IID_IColumnsInfo2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColumnInfo ( _                             ' VTable offset = 12
     BYREF pcColumns AS DWORD _                         ' __inout DBORDINAL *pcColumns
   , BYREF prgInfo AS DBCOLUMNINFO _                    ' __out DBCOLUMNINFO **prgInfo
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapColumnIDs ( _                              ' VTable offset = 16
     BYVAL cColumnIDs AS DWORD _                        ' __in DBORDINAL cColumnIDs
   , BYREF rgColumnIDs AS DBID _                        ' __in const DBID rgColumnIDs[  ]
   , BYREF rgColumns AS DWORD _                         ' __out DBORDINAL rgColumns[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRestrictedColumnInfo ( _                   ' VTable offset = 20
     BYVAL cColumnIDMasks AS DWORD _                    ' __in DBORDINAL cColumnIDMasks
   , BYREF rgColumnIDMasks AS DBID _                    ' __in const DBID rgColumnIDMasks[  ]
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pcColumns AS DWORD _                         ' __inout DBORDINAL *pcColumns
   , BYREF prgColumnIDs AS DWORD _                      ' __out DBID **prgColumnIDs
   , BYREF prgColumnInfo AS DWORD _                     ' __out DBCOLUMNINFO **prgColumnInfo
   , BYREF ppStringsBuffer AS DWORD _                   ' __out OLECHAR **ppStringsBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IColumnsInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' IRegisterProvider interface
' IID = 0C733AB9-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRegisterProvider_INTERFACE_DEFINED)
    %IRegisterProvider_INTERFACE_DEFINED = 1

INTERFACE IRegisterProvider $IID_IRegisterProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetURLMapping ( _                             ' VTable offset = 12
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwReserved AS DWORD _                        ' __in DB_DWRESERVE dwReserved
   , BYREF pclsidProvider AS GUID _                     ' __out CLSID *pclsidProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetURLMapping ( _                             ' VTable offset = 16
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwReserved AS DWORD _                        ' __in DB_DWRESERVE dwReserved
   , BYREF rclsidProvider AS GUID _                     ' __in REFCLSID rclsidProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterProvider ( _                        ' VTable offset = 20
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCOLESTR pwszURL
   , BYVAL dwReserved AS DWORD _                        ' __in DB_DWRESERVE dwReserved
   , BYREF rclsidProvider AS GUID _                     ' __in REFCLSID rclsidProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegisterProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' IGetSession interface
' IID = 0C733ABA-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetSession_INTERFACE_DEFINED)
    %IGetSession_INTERFACE_DEFINED = 1

INTERFACE IGetSession $IID_IGetSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSession ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSession AS IUnknown _                      ' __out IUnknown **ppSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetSession_INTERFACE_DEFINED__ */


' ########################################################################################
' IGetSourceRow interface
' IID = 0C733ABB-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetSourceRow_INTERFACE_DEFINED)
    %IGetSourceRow_INTERFACE_DEFINED = 1

INTERFACE IGetSourceRow $IID_IGetSourceRow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSourceRow ( _                              ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppRow AS IUnknown _                          ' __out IUnknown **ppRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetSourceRow_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetCurrentIndex interface
' IID = 0C733ABD-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetCurrentIndex_INTERFACE_DEFINED)
    %IRowsetCurrentIndex_INTERFACE_DEFINED = 1

INTERFACE IRowsetCurrentIndex $IID_IRowsetCurrentIndex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 12
     BYREF ppIndexID AS DBID _                          ' __out DBID **ppIndexID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndex ( _                                  ' VTable offset = 16
     BYREF pIndexID AS DBID _                           ' __in DBID *pIndexID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetCurrentIndex_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandStream interface
' IID = 0C733ABF-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandStream_INTERFACE_DEFINED)
    %ICommandStream_INTERFACE_DEFINED = 1

INTERFACE ICommandStream $IID_ICommandStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCommandStream ( _                          ' VTable offset = 12
     BYREF piid AS GUID _                               ' __out IID *piid
   , BYREF pguidDialect AS GUID _                       ' __inout GUID *pguidDialect
   , BYREF ppCommandStream AS IUnknown _                ' __out IUnknown **ppCommandStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCommandStream ( _                          ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rguidDialect AS GUID _                       ' __in REFGUID rguidDialect
   , BYVAL pCommandStream AS IUnknown _                 ' __in IUnknown *pCommandStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandStream_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetBookmark interface
' IID = 0C733AC2-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetBookmark_INTERFACE_DEFINED)
    %IRowsetBookmark_INTERFACE_DEFINED = 1

INTERFACE IRowsetBookmark $IID_IRowsetBookmark

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PositionOnBookmark ( _                        ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetBookmark_INTERFACE_DEFINED__ */

'#include <poppack.h>     // restore original structure packing
