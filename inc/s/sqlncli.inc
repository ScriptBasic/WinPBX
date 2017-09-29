' ########################################################################################
' Microsoft Windows
' File: sqlncli.inc
' Contents: SQL Native Client OLEDB provider and ODBC driver specific definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQLNCLI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "oledb.inc"
#INCLUDE ONCE "sqloledb.inc"
#INCLUDE ONCE "odbcss.inc"

'//----------------------------------------------------------------------------
'// Provider-specific Class Ids
'//

$CLSID_SQLNCLI                = GUID$("{85ECAFCC-BDD9-4B03-97A8-FA65CBE3859B}")
$CLSID_SQLNCLI_ERROR          = GUID$("{E8BC0A7A-EA71-4263-8CDA-94F388B8ED10}")
$CLSID_SQLNCLI_ENUMERATOR     = GUID$("{4898AD37-FE05-42DF-92F9-E857DDFEE730}")

'//----------------------------------------------------------------------------
'// Provider-specific Interface Ids
'//

$IID_ISSAbort                 = GUID$("{5CF4CA15-EF21-11d0-97E7-00C04FC2AD98}")
$IID_IBCPSession              = GUID$("{88352D80-42D1-42f0-A170-AB0F8B45B939}")
$IID_ISSCommandWithParameters = GUID$("{EEC30162-6087-467C-B995-7C523CE96561}")
$IID_ISSAsynchStatus          = GUID$("{1FF1F743-8BB0-4c00-ACC4-C10E43B08FC1}")

'//-------------------------------------------------------------------
'// define SQL Server spefific types...
'//-------------------------------------------------------------------
'typedef enum DBTYPEENUM EOledbTypes;
'#define DBTYPE_XML               ((EOledbTypes) 141) // introduced in SQL 2005
%DBTYPE_XML               = 141??   ' // introduced in SQL 2005


' ########################################################################################
' IBCPSession interface
' IID = 88352D80-42D1-42f0-A170-AB0F8B45B939
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBCPSession_INTERFACE_DEFINED)
    %IBCPSession_INTERFACE_DEFINED = 1

INTERFACE IBCPSession $IID_IBCPSession

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BCPColFmt ( _                                 ' VTable offset = 12
     BYVAL idxUserDataCol AS DWORD _                    ' __in DBORDINAL idxUserDataCol
   , BYVAL eUserDataType AS LONG _                      ' __in int eUserDataType
   , BYVAL cbIndicator AS LONG _                        ' __in int cbIndicator
   , BYVAL cbUserData AS LONG _                         ' __in int cbUserData
   , BYVAL pbUserDataTerm AS BYTE PTR _                 ' __in BYTE *pbUserDataTerm
   , BYVAL cbUserDataTerm AS LONG _                     ' __in int cbUserDataTerm
   , BYVAL idxServerCol AS DWORD _                      ' __in DBORDINAL idxServerCol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPColumns ( _                                ' VTable offset = 16
     BYVAL nColumns AS DWORD _                          ' __in DBCOUNTITEM nColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPControl ( _                                ' VTable offset = 20
     BYVAL eOption AS LONG _                            ' __in int eOption
   , BYVAL iValue AS DWORD _                            ' __in void *iValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPDone ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPExec ( _                                   ' VTable offset = 28
     BYREF pRowsCopied AS LONG _                        ' __out DBROWCOUNT *pRowsCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPInit ( _                                   ' VTable offset = 32
     BYREF pwszTable AS WSTRINGZ _                      ' __in const wchar_t *pwszTable
   , BYREF pwszDataFile AS WSTRINGZ _                   ' __in const wchar_t *pwszDataFile
   , BYREF pwszErrorFile AS WSTRINGZ _                  ' __in const wchar_t *pwszErrorFile
   , BYVAL eDirection AS LONG _                         ' __in int eDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPReadFmt ( _                                ' VTable offset = 36
     BYREF pwszFormatFile AS WSTRINGZ _                 ' __in const wchar_t *pwszFormatFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BCPWriteFmt ( _                               ' VTable offset = 40
     BYREF pwszFormatFile AS WSTRINGZ _                 ' __in const wchar_t *pwszFormatFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBCPSession_INTERFACE_DEFINED__ */


'#define ISOLATIONLEVEL_SNAPSHOT          ((ISOLATIONLEVEL)(0x01000000)) // Changes made in other transactions can not be seen.
%ISOLATIONLEVEL_SNAPSHOT          = &H01000000&   ' // Changes made in other transactions can not be seen.

'#define DBPROPVAL_TI_SNAPSHOT            0x01000000L
%DBPROPVAL_TI_SNAPSHOT            = &H01000000&


' ########################################################################################
' ISSAbort interface
' IID = 5CF4CA15-EF21-11D0-97E7-00C04FC2AD98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISSAbort_INTERFACE_DEFINED)
    %ISSAbort_INTERFACE_DEFINED = 1

INTERFACE ISSAbort $IID_ISSAbort

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISSAbort_INTERFACE_DEFINED__ */


' enum DBBINDFLAGENUM90
%DBBINDFLAG_OBJECT     = &H2???

' enum DBPROPFLAGSENUM90
%DBPROPFLAGS_PARAMETER = &H10000???

' // Size = 12 bytes
TYPE SSPARAMPROPS DWORD
   iOrdinal       AS DWORD           ' DBORDINAL
   cPropertySets  AS DWORD           ' ULONG
   rgPropertySets AS DBPROPSET PTR   ' DBPROPSET *
END TYPE


' ########################################################################################
' ISSCommandWithParameters interface
' IID = EEC30162-6087-467C-B995-7C523CE96561
' Inherited interface = ICommandWithParameters
' ########################################################################################

#IF NOT %DEF(%ISSCommandWithParameters_INTERFACE_DEFINED)
    %ISSCommandWithParameters_INTERFACE_DEFINED = 1

INTERFACE ISSCommandWithParameters $IID_ISSCommandWithParameters

   INHERIT IUnknown

   ' =====================================================================================
   ' ICommandWithParameters Methods
   ' =====================================================================================
   METHOD GetParameterInfo ( _                        ' VTable offset = 12
     BYREF pcParams AS DWORD _                        ' __inout DB_UPARAMS *pcParams
   , BYREF prgParamInfo AS DWORD _                    ' __out DBPARAMINFO **prgParamInfo
   , BYREF ppNamesBuffer AS DWORD _                   ' __out OLECHAR **ppNamesBuffer
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================
   METHOD MapParameterNames ( _                       ' VTable offset = 16
     BYVAL cParamNames AS DWORD _                     ' __in DB_UPARAMS cParamNames
   , BYREF rgParamNames AS WSTRINGZ _                 ' __in const OLECHAR *rgParamNames[  ]
   , BYREF rgParamOrdinals AS DWORD _                 ' __out DB_LPARAMS rgParamOrdinals[  ]
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================
   METHOD SetParameterInfo ( _                        ' VTable offset = 20
     BYVAL cParams AS DWORD _                         ' __in DB_UPARAMS cParams
   , BYREF rgParamOrdinals AS DWORD _                 ' __in const DB_UPARAMS rgParamOrdinals[  ]
   , BYREF rgParamBindInfo AS DBPARAMBINDINFO _       ' __in const DBPARAMBINDINFO rgParamBindInfo[  ]
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISSCommandWithParameters Methods
   ' =====================================================================================
   METHOD GetParameterProperties ( _                  ' VTable offset = 24
     BYREF pcParams AS DWORD _                        ' __inout DB_UPARAMS *pcParams
   , BYREF prgParamProperties AS DWORD _              ' __out SSPARAMPROPS **prgParamProperties
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================
   METHOD SetParameterProperties ( _                  ' VTable offset = 28
     BYVAL cParams AS DWORD _                         ' __in DB_UPARAMS cParams
   , BYVAL rgParamProperties AS DWORD _               ' __in SSPARAMPROPS rgParamProperties[  ]
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISSCommandWithParameters_INTERFACE_DEFINED__ */


' ########################################################################################
' ISSAsynchStatus interface
' IID = 1FF1F743-8BB0-4c00-ACC4-C10E43B08FC1
' Inherited interface = IDBAsynchStatus
' ########################################################################################

#IF NOT %DEF(%ISSAsynchStatus_INTERFACE_DEFINED)
    %ISSAsynchStatus_INTERFACE_DEFINED = 1

INTERFACE ISSAsynchStatus $IID_ISSAsynchStatus

   INHERIT IUnknown

   ' =====================================================================================
   ' IDBAsynchStatus Methods
   ' =====================================================================================
   METHOD Abort ( _                                   ' VTable offset = 12
     BYVAL hChapter AS DWORD _                        ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                      ' __in DBASYNCHOP eOperation
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                               ' VTable offset = 16
     BYVAL hChapter AS DWORD _                        ' __in HCHAPTER hChapter
   , BYVAL eOperation AS DWORD _                      ' __in DBASYNCHOP eOperation
   , BYREF pulProgress AS DWORD _                     ' __out DBCOUNTITEM *pulProgress
   , BYREF pulProgressMax AS DWORD _                  ' __out DBCOUNTITEM *pulProgressMax
   , BYREF peAsynchPhase AS DWORD _                   ' __out DBASYNCHPHASE *peAsynchPhase
   , BYREF ppwszStatusText AS DWORD _                 ' __out LPOLESTR *ppwszStatusText
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISSAsynchStatus Methods
   ' =====================================================================================
   METHOD WaitForAsynchCompletion ( _                 ' VTable offset = 20
     BYVAL dwMillisecTimeOut AS DWORD _               ' __in DWORD dwMillisecTimeOut
   ) AS LONG                                          ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISSAsynchStatus_INTERFACE_DEFINED__ */


'//----------------------------------------------------------------------------
'// Values for STATUS bitmask for DBSCHEMA_TABLES & DBSCHEMA_TABLES_INFO
%TABLE_HAS_UPDATE_INSTEAD_OF_TRIGGER     = &H00000001???   ' //table has IOT defined
%TABLE_HAS_DELETE_INSTEAD_OF_TRIGGER     = &H00000002???   ' //table has IOT defined
%TABLE_HAS_INSERT_INSTEAD_OF_TRIGGER     = &H00000004???   ' //table has IOT defined
%TABLE_HAS_AFTER_UPDATE_TRIGGER          = &H00000008???   ' //table has update trigger
%TABLE_HAS_AFTER_DELETE_TRIGGER          = &H00000010???   ' //table has delete trigger
%TABLE_HAS_AFTER_INSERT_TRIGGER          = &H00000020???   ' //table has insert trigger
%TABLE_HAS_CASCADE_UPDATE                = &H00000040???   ' //table has cascade update
%TABLE_HAS_CASCADE_DELETE                = &H00000080???   ' //table has cascade delete

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERDATASOURCE
%SSPROP_ENABLEBULKCOPY           = 3

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERDBINIT
%SSPROP_INIT_MARSCONNECTION              = 16
%SSPROP_INIT_ASYNCHCONNECTION            = 17
%SSPROP_INIT_FAILOVERPARTNER             = 18
%SSPROP_AUTH_OLD_PASSWORD                = 19
%SSPROP_INIT_DATATYPECOMPATIBILITY       = 20
%SSPROP_INIT_TRUST_SERVER_CERTIFICATE    = 21

'//-----------------------------------------------------------------------------
'// Values for SSPROP_INIT_DATATYPECOMPATIBILITY
%SSPROPVAL_DATATYPECOMPATIBILITY_SQL2000 = 80
%SSPROPVAL_DATATYPECOMPATIBILITY_DEFAULT = 0

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERSESSION
%SSPROP_ASYNCH_BULKCOPY         = 5

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERROWSET
%SSPROP_QP_NOTIFICATION_TIMEOUT = 17
%SSPROP_QP_NOTIFICATION_MSGTEXT = 18
%SSPROP_QP_NOTIFICATION_OPTIONS = 19
%SSPROP_NOCOUNT_STATUS          = 20
%SSPROP_COMPUTE_ID              = 21
%SSPROP_COLUMN_ID               = 22
%SSPROP_COMPUTE_BYLIST          = 23
%SSPROP_ISSAsynchStatus         = 24

'//-----------------------------------------------------------------------------
'// Values for SSPROP_QP_NOTIFICATION_TIMEOUT
%SSPROPVAL_DEFAULT_NOTIFICATION_TIMEOUT = 432000       ' /* in sec */
%SSPROPVAL_MAX_NOTIFICATION_TIMEOUT     = &H7FFFFFFF   ' /* in sec */
%MAX_NOTIFICATION_LEN                   = 2000         ' /* NVARCHAR [2000] for both ID & DELIVERY_QUEUE */

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERCOLUMN
%SSPROP_COL_UDT_CATALOGNAME                     = 31
%SSPROP_COL_UDT_SCHEMANAME                      = 32
%SSPROP_COL_UDT_NAME                            = 33
%SSPROP_COL_XML_SCHEMACOLLECTION_CATALOGNAME    = 34
%SSPROP_COL_XML_SCHEMACOLLECTION_SCHEMANAME     = 35
%SSPROP_COL_XML_SCHEMACOLLECTIONNAME            = 36

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERPARAMETER
%SSPROP_PARAM_XML_SCHEMACOLLECTION_CATALOGNAME   = 24
%SSPROP_PARAM_XML_SCHEMACOLLECTION_SCHEMANAME    = 25
%SSPROP_PARAM_XML_SCHEMACOLLECTIONNAME           = 26
%SSPROP_PARAM_UDT_CATALOGNAME                    = 27
%SSPROP_PARAM_UDT_SCHEMANAME                     = 28
%SSPROP_PARAM_UDT_NAME                           = 29

'//----------------------------------------------------------------------------
'// PropIds for DBPROPSET_SQLSERVERINDEX
%SSPROP_INDEX_XML                = 1

'//-----------------------------------------------------------------------------
'//
%BCP_TYPE_DEFAULT         = &H00
%BCP_TYPE_SQLTEXT         = &H23
%BCP_TYPE_SQLVARBINARY    = &H25
%BCP_TYPE_SQLINTN         = &H26
%BCP_TYPE_SQLVARCHAR      = &H27
%BCP_TYPE_SQLBINARY       = &H2d
%BCP_TYPE_SQLIMAGE        = &H22
%BCP_TYPE_SQLCHARACTER    = &H2f
%BCP_TYPE_SQLINT1         = &H30
%BCP_TYPE_SQLBIT          = &H32
%BCP_TYPE_SQLINT2         = &H34
%BCP_TYPE_SQLINT4         = &H38
%BCP_TYPE_SQLMONEY        = &H3c
%BCP_TYPE_SQLDATETIME     = &H3d
%BCP_TYPE_SQLFLT8         = &H3e
%BCP_TYPE_SQLFLTN         = &H6d
%BCP_TYPE_SQLMONEYN       = &H6e
%BCP_TYPE_SQLDATETIMN     = &H6f
%BCP_TYPE_SQLFLT4         = &H3b
%BCP_TYPE_SQLMONEY4       = &H7a
%BCP_TYPE_SQLDATETIM4     = &H3a
%BCP_TYPE_SQLDECIMAL      = &H6a
%BCP_TYPE_SQLNUMERIC      = &H6c
%BCP_TYPE_SQLUNIQUEID     = &H24
%BCP_TYPE_SQLBIGCHAR      = &Haf
%BCP_TYPE_SQLBIGVARCHAR   = &Ha7
%BCP_TYPE_SQLBIGBINARY    = &Had
%BCP_TYPE_SQLBIGVARBINARY = &Ha5
%BCP_TYPE_SQLBITN         = &H68
%BCP_TYPE_SQLNCHAR        = &Hef
%BCP_TYPE_SQLNVARCHAR     = &He7
%BCP_TYPE_SQLNTEXT        = &H63
%BCP_TYPE_SQLDECIMALN     = &H6a
%BCP_TYPE_SQLNUMERICN     = &H6c
%BCP_TYPE_SQLINT8         = &H7f
%BCP_TYPE_SQLVARIANT      = &H62
%BCP_TYPE_SQLUDT          = &Hf0
%BCP_TYPE_SQLXML          = &Hf1

%BCP_DIRECTION_IN           = 1
%BCP_DIRECTION_OUT          = 2

%BCP_OPTION_MAXERRS         = 1
%BCP_OPTION_FIRST           = 2
%BCP_OPTION_LAST            = 3
%BCP_OPTION_BATCH           = 4
%BCP_OPTION_KEEPNULLS       = 5
%BCP_OPTION_ABORT           = 6
%BCP_OPTION_KEEPIDENTITY    = 8
%BCP_OPTION_HINTSA          = 10
%BCP_OPTION_HINTSW          = 11
%BCP_OPTION_FILECP          = 12
%BCP_OPTION_UNICODEFILE     = 13
%BCP_OPTION_TEXTFILE        = 14
%BCP_OPTION_FILEFMT         = 15
%BCP_OPTION_FMTXML          = 16

%BCP_FILECP_ACP             = 0
%BCP_FILECP_OEMCP           = 1
%BCP_FILECP_RAW             = (-1)

'#IF %DEF(%UNICODE)
'%BCP_OPTION_HINTS           = %BCP_OPTION_HINTSW
'#ELSE
'%BCP_OPTION_HINTS           = %BCP_OPTION_HINTSA
'#ENDIF
%BCP_OPTION_HINTS           = %BCP_OPTION_HINTSA

%BCP_PREFIX_DEFAULT         = (-10)

%BCP_LENGTH_NULL            = (-1)
%BCP_LENGTH_VARIABLE        = (-10)
'//
'//-----------------------------------------------------------------------------


'//----------------------------------------------------------------------------
'// Provider-specific schema rowsets
'//

$DBSCHEMA_SQL_ASSEMBLIES            = GUID$("{7C1112C8-C2D3-4F6E-949A-983D38A58F46}")
$DBSCHEMA_SQL_ASSEMBLY_DEPENDENCIES = GUID$("{CB0F837B-974C-41B8-909D-649CAF45AD2F}")
$DBSCHEMA_SQL_USER_TYPES            = GUID$("{F1198BD8-A424-4EA3-8D4C-607EEE2BAB60}")
$DBSCHEMA_XML_COLLECTIONS           = GUID$("{56BFAD8C-6E8F-480D-91DE-3516D99A5D10}")

#IF NOT %DEF(%CRESTRICTIONS_DBSCHEMA_LINKEDSERVERS)
%CRESTRICTIONS_DBSCHEMA_LINKEDSERVERS   = 1
#ENDIF

#IF NOT %DEF(%CRESTRICTIONS_DBSCHEMA_ASSEMBLIES)
%CRESTRICTIONS_DBSCHEMA_SQL_ASSEMBLIES  = 4
#ENDIF

#IF NOT %DEF(%CRESTRICTIONS_DBSCHEMA_ASSEMBLY_DEPENDENCIES)
%CRESTRICTIONS_DBSCHEMA_SQL_ASSEMBLY_DEPENDENCIES = 4
#ENDIF

#IF NOT %DEF(%CRESTRICTIONS_DBSCHEMA_USER_TYPES)
%CRESTRICTIONS_DBSCHEMA_SQL_USER_TYPES  = 3
#ENDIF

#IF NOT %DEF(%CRESTRICTIONS_DBSCHEMA_XML_COLLECTIONS)
%CRESTRICTIONS_DBSCHEMA_XML_COLLECTIONS = 4
#ENDIF

'//----------------------------------------------------------------------------
'// Provider-specific property sets
'//

$DBPROPSET_SQLSERVERPARAMETER = GUID$("{FEE09128-A67D-47EA-8D40-24A1D4737E8D}")
$DBPROPSET_SQLSERVERINDEX     = GUID$("{E428B84E-A6B7-413A-9465-56232E0D2BEB}")
$DBPROPSET_PARAMETERALL       = GUID$("{2CD2B7D8-E7C2-4F6C-9B30-75E258461097}")


'//----------------------------------------------------------------------------
'// Provider-specific columns for IColumnsRowset
'//

$DBCOLUMN_SS_X_GUID = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}")

MACRO DBCOLUMN_BASESERVERNAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(104)
MACRO DBCOLUMN_SS_XML_SCHEMACOLLECTION_CATALOGNAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(105)
MACRO DBCOLUMN_SS_XML_SCHEMACOLLECTION_SCHEMANAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(106)
MACRO DBCOLUMN_SS_XML_SCHEMACOLLECTIONNAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(107)
MACRO DBCOLUMN_SS_UDT_CATALOGNAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(108)
MACRO DBCOLUMN_SS_UDT_SCHEMANAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(109)
MACRO DBCOLUMN_SS_UDT_NAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(110)
MACRO DBCOLUMN_SS_ASSEMBLY_TYPENAME = GUID$("{627BD890-ED54-11D2-B994-00C04F8CA82C}") & MKDWD$(%DBKIND_GUID_PROPID) & MKDWD$(111)


'// SQLSetConnectAttr driver specific defines.
'// Microsoft has 1200 thru 1249 reserved for Microsoft SQL Native Client driver usage.
'// Connection attributes
%SQL_COPT_SS_MARS_ENABLED                    = (%SQL_COPT_SS_BASE+24) ' // Multiple active result set per connection
%SQL_COPT_SS_FAILOVER_PARTNER                = (%SQL_COPT_SS_BASE+25) ' // Failover partner server
%SQL_COPT_SS_OLDPWD                          = (%SQL_COPT_SS_BASE+26) ' // Old Password, used when changing password during login
%SQL_COPT_SS_TXN_ISOLATION                   = (%SQL_COPT_SS_BASE+27) ' // Used to set/get any driver-specific or ODBC-defined TXN iso level
%SQL_COPT_SS_TRUST_SERVER_CERTIFICATE        = (%SQL_COPT_SS_BASE+28) ' // Trust server certificate
'%SQL_COPT_SS_MAX_USED                        = %SQL_COPT_SS_TRUST_SERVER_CERTIFICATE

'// SQLSetStmtAttr SQL Native Client driver specific defines.
'// Statement attributes
%SQL_SOPT_SS_QUERYNOTIFICATION_TIMEOUT       = (%SQL_SOPT_SS_BASE+8)  ' // Notification timeout
%SQL_SOPT_SS_QUERYNOTIFICATION_MSGTEXT       = (%SQL_SOPT_SS_BASE+9)  ' // Notification message text
%SQL_SOPT_SS_QUERYNOTIFICATION_OPTIONS       = (%SQL_SOPT_SS_BASE+10) ' // SQL service broker name
'%SQL_SOPT_SS_MAX_USED                        = %SQL_SOPT_SS_QUERYNOTIFICATION_OPTIONS

'// XML and CLR UDT type related metadata
%SQL_CA_SS_UDT_CATALOG_NAME                  = (%SQL_CA_SS_BASE+18) ' //  UDT catalog name
%SQL_CA_SS_UDT_SCHEMA_NAME                   = (%SQL_CA_SS_BASE+19) ' //  UDT schema name
%SQL_CA_SS_UDT_TYPE_NAME                     = (%SQL_CA_SS_BASE+20) ' //  UDT type name
%SQL_CA_SS_UDT_ASSEMBLY_TYPE_NAME            = (%SQL_CA_SS_BASE+21) ' //  Qualified name of the assembly containing the UDT class
%SQL_CA_SS_XML_SCHEMACOLLECTION_CATALOG_NAME = (%SQL_CA_SS_BASE+22) ' //  Name of the catalog that contains XML Schema collection
%SQL_CA_SS_XML_SCHEMACOLLECTION_SCHEMA_NAME  = (%SQL_CA_SS_BASE+23) ' //  Name of the schema that contains XML Schema collection
%SQL_CA_SS_XML_SCHEMACOLLECTION_NAME         = (%SQL_CA_SS_BASE+24) ' //  Name of the XML Schema collection
'%SQL_CA_SS_MAX_USED              = %SQL_CA_SS_BASE+25

'//SQL_COPT_SS_TRUST_SERVER_CERTIFICATE
%SQL_TRUST_SERVER_CERTIFICATE_NO    = 0&
%SQL_TRUST_SERVER_CERTIFICATE_YES   = 1&
'//SQL_COPT_SS_MARS_ENABLED
%SQL_MARS_ENABLED_NO                = 0&
%SQL_MARS_ENABLED_YES               = 1&
'/* SQL_TXN_ISOLATION_OPTION bitmasks */
%SQL_TXN_SS_SNAPSHOT                = &H00000020&

'// Driver specific SQL data type defines.
'// Microsoft has -150 thru -199 reserved for Microsoft SQL Native Client driver usage.
'#define SQL_SS_VARIANT                      (-150)
%SQL_SS_UDT                         = (-151)
%SQL_SS_XML                         = (-152)

'// New types for SQL 2005 and later servers
%SQLUDT                              = &Hf0
%SQLXML                              = &Hf1

'// SQL_SS_LENGTH_UNLIMITED is used to describe the max length of
'// VARCHAR(max), VARBINARY(max), NVARCHAR(max), and XML columns
%SQL_SS_LENGTH_UNLIMITED            = 0

'// ODBC BCP prototypes and defines
%BCPFMTXML              = 16  ' // Sets the format file type to xml

'// BCP functions
'CHAR* SQL_API bcp_gettypenameA (INT, DBBOOL);
DECLARE FUNCTION bcp_gettypename IMPORT "Odbcbcp.dll" ALIAS "bcp_gettypenameA" ( _
   BYVAL token AS LONG _                                ' __in INT token
 , BYVAL fIsMaxType AS BYTE _                           ' __in DBBOOL fIsMaxType
 ) AS DWORD                                             ' CHAR *

'WCHAR* SQL_API bcp_gettypenameW (INT, DBBOOL);
DECLARE FUNCTION bcp_gettypenameW IMPORT "Odbcbcp.dll" ALIAS "bcp_gettypenameW" ( _
   BYVAL token AS LONG _                                ' __in INT token
 , BYVAL fIsMaxType AS BYTE _                           ' __in DBBOOL fIsMaxType
 ) AS DWORD                                             ' WCHAR *
