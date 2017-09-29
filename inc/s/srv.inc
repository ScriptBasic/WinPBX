' ########################################################################################
' Microsoft Windows
' File: srv.inc
' Contents: Open Data Services
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'// Avoid double inclusion
#INCLUDE THIS ONCE
%SRV_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "odbcss.inc"

'// ODS uses pack(4) on all CPU types
'#pragma pack(4)

'//------------------------------------------------------------
'// Formats of data types
'#if !defined(DBTYPEDEFS) // Do not conflict with DBLIB definitions
'#if !defined(MAXNUMERICLEN) // Do not conflict with ODBC definitions

'#define DBTYPEDEFS

'typedef unsigned char DBBOOL;
'typedef unsigned char DBBYTE;
'typedef unsigned char DBTINYINT;
'typedef short DBSMALLINT;
'typedef unsigned short DBUSMALLINT;
'typedef long DBINT;
'typedef char DBCHAR;
'typedef unsigned char DBBINARY;
'typedef unsigned char DBBIT;
'typedef double DBFLT8;

'typedef struct srv_datetime
'{   // Format for SRVDATETIME
'    long dtdays;            // number of days since 1/1/1900
'    unsigned long dttime;   // number 300th second since mid
'} DBDATETIME;

'typedef struct srv_money
'{      // Format for SRVMONEY
'    long mnyhigh;
'    unsigned long mnylow;
'} DBMONEY;

'typedef float DBFLT4;
'typedef long DBMONEY4;

'typedef struct dbdatetime4
'{   // Format for SRVDATETIM4
'    unsigned short numdays; // number of days since 1/1/1900
'    unsigned short nummins; // number of minutes sicne midnight
'} DBDATETIM4;

'#define MAXNUMERICLEN   16
'typedef struct dbnumeric
'{   // Format for SRVNUMERIC,SRVNUMERICN,SRVDECIMAL,SRVDECIMALN
'   BYTE precision;
'   BYTE scale;
'   BYTE sign;
'   BYTE val[MAXNUMERICLEN];
'} DBNUMERIC;
'typedef DBNUMERIC DBDECIMAL;

'#endif  // #if !defined(MAXNUMERICLEN)
'#endif  // #if !defined( DBTYPEDEFS )

'//------------------------------------------------------------
'// Constants used by APIs

'// Type Tokens
%SRV_TDS_NULL           = &H1f?
%SRV_TDS_TEXT           = &H23?
%SRV_TDS_GUID           = &H24?
%SRV_TDS_VARBINARY      = &H25?
%SRV_TDS_INTN           = &H26?
%SRV_TDS_VARCHAR        = &H27?
%SRV_TDS_BINARY         = &H2d?
%SRV_TDS_IMAGE          = &H22?
%SRV_TDS_CHAR           = &H2f?
%SRV_TDS_INT1           = &H30?
%SRV_TDS_BIT            = &H32?
%SRV_TDS_INT2           = &H34?
%SRV_TDS_DECIMAL        = &H37?
%SRV_TDS_INT4           = &H38?
%SRV_TDS_DATETIM4       = &H3a?
%SRV_TDS_FLT4           = &H3b?
%SRV_TDS_MONEY          = &H3c?
%SRV_TDS_DATETIME       = &H3d?
%SRV_TDS_FLT8           = &H3e?
%SRV_TDS_NUMERIC        = &H3f?
%SRV_TDS_SSVARIANT      = &H62?
%SRV_TDS_NTEXT          = &H63?
%SRV_TDS_BITN           = &H68?
%SRV_TDS_DECIMALN       = &H6a?
%SRV_TDS_NUMERICN       = &H6c?
%SRV_TDS_FLTN           = &H6d?
%SRV_TDS_MONEYN         = &H6e?
%SRV_TDS_DATETIMN       = &H6f?
%SRV_TDS_MONEY4         = &H7a?
%SRV_TDS_INT8           = &H7f?
%SRV_TDS_BIGVARBINARY   = &HA5?
%SRV_TDS_BIGVARCHAR     = &HA7?
%SRV_TDS_BIGBINARY      = &HAD?
%SRV_TDS_BIGCHAR        = &HAF?
%SRV_TDS_NVARCHAR       = &He7?
%SRV_TDS_NCHAR          = &Hef?

'// Datatypes
'// Also: values of symbol parameter to srv_symbol when type = SRV_DATATYPE
%SRVNULL         = %SRV_TDS_NULL
%SRVTEXT         = %SRV_TDS_TEXT
%SRVGUID         = %SRV_TDS_GUID
%SRVVARBINARY    = %SRV_TDS_VARBINARY
%SRVINTN         = %SRV_TDS_INTN
%SRVVARCHAR      = %SRV_TDS_VARCHAR
%SRVBINARY       = %SRV_TDS_BINARY
%SRVIMAGE        = %SRV_TDS_IMAGE
%SRVCHAR         = %SRV_TDS_CHAR
%SRVINT1         = %SRV_TDS_INT1
%SRVBIT          = %SRV_TDS_BIT
%SRVINT2         = %SRV_TDS_INT2
%SRVDECIMAL      = %SRV_TDS_DECIMAL
%SRVINT4         = %SRV_TDS_INT4
%SRVDATETIM4     = %SRV_TDS_DATETIM4
%SRVFLT4         = %SRV_TDS_FLT4
%SRVMONEY        = %SRV_TDS_MONEY
%SRVDATETIME     = %SRV_TDS_DATETIME
%SRVFLT8         = %SRV_TDS_FLT8
%SRVNUMERIC      = %SRV_TDS_NUMERIC
%SRVSSVARIANT    = %SRV_TDS_SSVARIANT
%SRVNTEXT        = %SRV_TDS_NTEXT
%SRVBITN         = %SRV_TDS_BITN
%SRVDECIMALN     = %SRV_TDS_DECIMALN
%SRVNUMERICN     = %SRV_TDS_NUMERICN
%SRVFLTN         = %SRV_TDS_FLTN
%SRVMONEYN       = %SRV_TDS_MONEYN
%SRVDATETIMN     = %SRV_TDS_DATETIMN
%SRVMONEY4       = %SRV_TDS_MONEY4
%SRVINT8         = %SRV_TDS_INT8
%SRVBIGVARBINARY = %SRV_TDS_BIGVARBINARY
%SRVBIGVARCHAR   = %SRV_TDS_BIGVARCHAR
%SRVBIGBINARY    = %SRV_TDS_BIGBINARY
%SRVBIGCHAR      = %SRV_TDS_BIGCHAR
%SRVNVARCHAR     = %SRV_TDS_NVARCHAR
%SRVNCHAR        = %SRV_TDS_NCHAR

'// values for srv_symbol type parameter
%SRV_ERROR     = 0
%SRV_DONE      = 1
%SRV_DATATYPE  = 2
%SRV_EVENT     = 4

'// values for srv_symbol symbol parameter, when type = SRV_ERROR
%SRV_ENO_OS_ERR    = 0
%SRV_INFO          = 1
%SRV_FATAL_PROCESS = 10
%SRV_FATAL_SERVER  = 19

'// Types of server events
'// Also: values for srv_symbol symbol parameter, when type = SRV_EVENT
%SRV_CONTINUE           = 0
%SRV_LANGUAGE           = 1
%SRV_CONNECT            = 2
%SRV_RPC                = 3
%SRV_RESTART            = 4
%SRV_DISCONNECT         = 5
%SRV_ATTENTION          = 6
%SRV_SLEEP              = 7
%SRV_START              = 8
%SRV_STOP               = 9
%SRV_EXIT               = 10
%SRV_CANCEL             = 11
%SRV_SETUP              = 12
%SRV_CLOSE              = 13
%SRV_PRACK              = 14
%SRV_PRERROR            = 15
%SRV_ATTENTION_ACK      = 16
%SRV_CONNECT_V7         = 16    ' // TDS type for TDS 7 clients.  Overloaded with SRV_ATTENTION_ACK
%SRV_SKIP               = 17
%SRV_TRANSMGR           = 18
%SRV_PRELOGIN           = 19
%SRV_OLEDB              = 20
%SRV_INTERNAL_HANDLER   = 99
%SRV_PROGRAMMER_DEFINED = 100

'// values for srv_sfield field parameter
%SRV_SERVERNAME         = 0
%SRV_VERSION            = 6

'// Length to indicate string is null terminated
%SRV_NULLTERM  = -1

'// values of msgtype parameter to srv_sendmsg
%SRV_MSG_INFO   = 1
%SRV_MSG_ERROR  = 2

'// values of status parameter to srv_senddone
'// Also: values for symbol parameters to srv_symbol when type = SRV_DONE
%SRV_DONE_FINAL         = &H0000??
%SRV_DONE_MORE          = &H0001??
%SRV_DONE_ERROR         = &H0002??
%SRV_DONE_COUNT         = &H0010??
%SRV_DONE_RPC_IN_BATCH  = &H0080??

'// return values of srv_paramstatus
%SRV_PARAMRETURN        = &H0001
%SRV_PARAMDEFAULT       = &H0002
%SRV_PARAMSORTORDER     = &H0004

'// return values of srv_rpcoptions
%SRV_RECOMPILE          = &H0001
%SRV_NOMETADATA         = &H0002

'// values of field parameter to srv_pfield
'//%SRV_LANGUAGE 1   already defined above
'//%SRV_EVENT    4   already defined above
%SRV_SPID                 = 10
%SRV_NETSPID              = 11
%SRV_TYPE                 = 12
%SRV_STATUS               = 13
%SRV_RMTSERVER            = 14
%SRV_HOST                 = 15
%SRV_USER                 = 16
%SRV_PWD                  = 17
%SRV_CPID                 = 18
%SRV_APPLNAME             = 19
%SRV_TDS                  = 20
%SRV_CLIB                 = 21
%SRV_LIBVERS              = 22
%SRV_ROWSENT              = 23
%SRV_BCPFLAG              = 24
%SRV_NATLANG              = 25
%SRV_PIPEHANDLE           = 26
%SRV_NETWORK_MODULE       = 27
%SRV_NETWORK_VERSION      = 28
%SRV_NETWORK_CONNECTION   = 29
%SRV_LSECURE              = 30
%SRV_SAXP                 = 31
%SRV_UNICODE_USER         = 33
%SRV_UNICODE_PWD          = 35
%SRV_SPROC_CODEPAGE       = 36
%SRV_MSGLCID              = 37
%SRV_INSTANCENAME         = 38
%SRV_HASHPWD              = 39
%SRV_UNICODE_CURRENTLOGIN = 40

'// return value of SRV_TDSVERSION macro
%SRV_TDS_NONE  = 0
%SRV_TDS_2_0   = 1
%SRV_TDS_3_4   = 2
%SRV_TDS_4_2   = 3
%SRV_TDS_6_0   = 4
%SRV_TDS_7_0   = 5

'// Return values from APIs
'typedef int SRVRETCODE;        // SUCCEED or FAIL
'#ifndef ODBCVER
'typedef int RETCODE;
'#endif

'#if !defined( SUCCEED )
'%SUCCEED    = 1   // Successful return value
'#endif

'#if !defined( FAIL )
'%FAIL       = 0   // Unsuccessful return value
'#endif

%SRV_DUPLICATE_HANDLER = 2  ' // additional return value for srv_pre/post_handle

'//------------------------------------------------
'//PreDeclare structures
'//
'struct srv_server;
'typedef struct srv_server SRV_SERVER;

'struct srv_config;
'typedef struct srv_config SRV_CONFIG;

'struct CXPData;
'typedef struct CXPData SRV_PROC;


'//------------------------------------------------
'//------------------------------------------------
'// ODS MACROs & APIs

'// Describing and sending a result set

DECLARE FUNCTION srv_describe CDECL IMPORT "Opends60.dll" ALIAS "srv_describe" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL colnumber AS LONG _                            ' int colnumber
 , BYREF column_name AS ASCIIZ _                        ' DBCHAR * column_name
 , BYVAL namelen AS LONG _                              ' int namelen
 , BYVAL desttype AS LONG _                             ' DBINT desttype
 , BYVAL destlen AS LONG _                              ' DBINT destlen
 , BYVAL srctype AS LONG _                              ' DBINT srctype
 , BYVAL srclen AS LONG _                               ' DBINT srclen
 , BYREF srcdata AS ANY _                               ' void * srcdata
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_setutype CDECL IMPORT "Opends60.dll" ALIAS "srv_setutype" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL column AS LONG _                               ' int column
 , BYVAL user_type AS LONG _                            ' DBINT user_type
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_setcoldata CDECL IMPORT "Opends60.dll" ALIAS "srv_setcoldata" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL column AS LONG _                               ' int column
 , BYREF data AS ANY _                                  ' void * data
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_setcollen CDECL IMPORT "Opends60.dll" ALIAS "srv_setcollen" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL column AS LONG _                               ' int column
 , BYVAL len AS LONG _                                  ' int len
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_sendrow CDECL IMPORT "Opends60.dll" ALIAS "srv_sendrow" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_senddone CDECL IMPORT "Opends60.dll" ALIAS "srv_senddone" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL status AS WORD _                               ' DBUSMALLINT status
 , BYVAL info AS WORD _                                 ' DBUSMALLINT info
 , BYVAL count AS LONG _                                ' DBINT count
 ) AS LONG                                              ' int

'// Dealing with Extended Procedure parameters

DECLARE FUNCTION srv_rpcparams CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcparams" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paraminfo CDECL IMPORT "Opends60.dll" ALIAS "srv_paraminfo" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 , BYREF pbType AS BYTE _                               ' BYTE * pbType
 , BYREF pcbMaxLen AS DWORD _                           ' ULONG * pcbMaxLen
 , BYREF pcbActualLen AS DWORD _                        ' ULONG * pcbActualLen
 , BYVAL pbData AS BYTE PTR _                           ' BYTE * pbData
 , BYREF pfNull AS LONG _                               ' BOOL * pfNull
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paramsetoutput CDECL IMPORT "Opends60.dll" ALIAS "srv_paramsetoutput" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 , BYVAL pbData AS BYTE PTR _                           ' BYTE * pbData
 , BYVAL cbLen AS DWORD _                               ' ULONG cbLen
 , BYVAL fNull AS LONG _                                ' BOOL fNull
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paramdata CDECL IMPORT "Opends60.dll" ALIAS "srv_paramdata" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 ) AS DWORD                                             ' void*

DECLARE FUNCTION srv_paramlen CDECL IMPORT "Opends60.dll" ALIAS "srv_paramlen" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_parammaxlen CDECL IMPORT "Opends60.dll" ALIAS "srv_parammaxlen" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paramtype CDECL IMPORT "Opends60.dll" ALIAS "srv_paramtype" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paramset CDECL IMPORT "Opends60.dll" ALIAS "srv_paramset" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 , BYREF data AS ANY _                                  ' void * data
 , BYVAL len AS LONG _                                  ' int len
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_paramname CDECL IMPORT "Opends60.dll" ALIAS "srv_paramname" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL m AS LONG _                                    ' int n
 , BYREF len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_paramnumber CDECL IMPORT "Opends60.dll" ALIAS "srv_paramnumber" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYREF name AS ASCIIZ _                               ' DBCHAR * name
 , BYVAL namelen AS LONG _                              ' int namelen
 ) AS LONG                                              ' int

'//--------------------------------------------------------------
'//--------------------------------------------------------------
'// The rest of these APIs are still supported, in SQL Server 7.0,
'// but may not be supported after SQL Server 7.0

'// MACROs
'#define SRV_GETSERVER(a)      srv_getserver     ( a )
'#define SRV_GOT_ATTENTION(a)  srv_got_attention ( a )
'#define SRV_TDSVERSION(a)     srv_tdsversion     ( a )

DECLARE FUNCTION srv_getserver CDECL IMPORT "Opends60.dll" ALIAS "srv_getserver" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS DWORD                                             ' SRV_SERVER*

DECLARE FUNCTION srv_got_attention CDECL IMPORT "Opends60.dll" ALIAS "srv_got_attention" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' BOOL

'// Memory

DECLARE FUNCTION srv_alloc CDECL IMPORT "Opends60.dll" ALIAS "srv_alloc" ( _
   BYVAL ulSize AS LONG _                               ' long int ulSize
 ) AS DWORD                                             ' void*

DECLARE FUNCTION srv_bmove CDECL IMPORT "Opends60.dll" ALIAS "srv_bmove" ( _
   BYREF from AS ANY _                                  ' void* from
 , BYREF to AS ANY _                                    ' void* to
 , BYVAL count AS LONG _                                ' long int count
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_bzero CDECL IMPORT "Opends60.dll" ALIAS "srv_bzero" ( _
   BYREF location AS ANY _                              ' void* location
 , BYVAL count AS LONG _                                ' long int count
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_free CDECL IMPORT "Opends60.dll" ALIAS "srv_free" ( _
   BYVAL ptr AS DWORD _                                 ' void * ptr
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_convert CDECL IMPORT "Opends60.dll" ALIAS "srv_convert" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL srctype AS LONG _                              ' int srctype
 , BYREF src AS ANY _                                   ' void * src
 , BYVAL srclen AS LONG _                               ' DBINT srclen
 , BYVAL desttype AS LONG _                             ' int desttype
 , BYREF dest AS ANY _                                  ' void * dest
 , BYVAL destlen AS LONG _                              ' DBINT destlen
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_getuserdata CDECL IMPORT "Opends60.dll" ALIAS "srv_getuserdata" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS DWORD                                             ' void*

DECLARE FUNCTION srv_getbindtoken CDECL IMPORT "Opends60.dll" ALIAS "srv_getbindtoken" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYREF token_buf AS ASCIIZ _                          ' char* token_buf
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_getdtcxact CDECL IMPORT "Opends60.dll" ALIAS "srv_getdtcxact" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYREF ppv AS ANY _                                   ' void ** ppv
 ) AS LONG                                              ' int

'typedef int (* EventHandler)(void *);

DECLARE FUNCTION srv_impersonate_client CDECL IMPORT "Opends60.dll" ALIAS "srv_impersonate_client" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_langcpy CDECL IMPORT "Opends60.dll" ALIAS "srv_langcpy" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL start AS LONG _                                ' long start
 , BYVAL nbytes AS LONG _                               ' long nbytes
 , BYREF buffer AS ASCIIZ _                             ' char* buffer
 ) AS LONG                                              ' long

DECLARE FUNCTION srv_langlen CDECL IMPORT "Opends60.dll" ALIAS "srv_langlen" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' long

DECLARE FUNCTION srv_langptr CDECL IMPORT "Opends60.dll" ALIAS "srv_langptr" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS DWORD                                             ' void*

DECLARE FUNCTION srv_log CDECL IMPORT "Opends60.dll" ALIAS "srv_log" ( _
   BYVAL server AS DWORD _                              ' SRV_SERVER * server
 , BYVAL datestamp AS LONG _                            ' BOOL         datestamp
 , BYREF msg AS ASCIIZ _                                ' char       * msg
 , BYVAL msglen AS LONG _                               ' int          msglen
 ) AS LONG _                                            ' int

DECLARE FUNCTION srv_paramstatus CDECL IMPORT "Opends60.dll" ALIAS "srv_paramstatus" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL n AS LONG _                                    ' int n
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_pfieldex CDECL IMPORT "Opends60.dll" ALIAS "srv_pfieldex" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL field AS LONG _                                ' int field
 , BYREF len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' void*

DECLARE FUNCTION srv_pfield CDECL IMPORT "Opends60.dll" ALIAS "srv_pfield" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL field AS LONG _                                ' int field
 , BYREF len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_returnval CDECL IMPORT "Opends60.dll" ALIAS "srv_returnval" ( _
   BYREF valuename AS ASCIIZ _                          ' char * valuename
 , BYVAL len AS LONG _                                  ' int  len
 , BYVAL status AS BYTE _                               ' BYTE status
 , BYVAL type AS LONG _                                 ' long int type
 , BYVAL maxlen AS LONG _                               ' long int maxlen
 , BYVAL datalen AS LONG _                              ' long int datalen
 , BYREF value AS ANY _                                 ' void * value
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_revert_to_self CDECL IMPORT "Opends60.dll" ALIAS "srv_revert_to_self" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_rpcdb CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcdb" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_rpcname CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcname" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_rpcnumber CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcnumber" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_rpcoptions CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcoptions" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS WORD                                              ' USHORT

DECLARE FUNCTION srv_rpcowner CDECL IMPORT "Opends60.dll" ALIAS "srv_rpcowner" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_wsendmsg CDECL IMPORT "Opends60.dll" ALIAS "srv_wsendmsg" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL msgnum AS LONG _                               ' long int msgnum
 , BYVAL msgclass AS BYTE _                             ' BYTE msgclass
 , BYREF message AS WSTRINGZ _                          ' WCHAR * message // message text
 , BYVAL msglen AS LONG _                               ' int msglen // length of message text
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_sendmsg CDECL IMPORT "Opends60.dll" ALIAS "srv_sendmsg" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL msgtype AS LONG _                              ' int msgtype
 , BYVAL msgnum AS LONG _                               ' long int msgnum
 , BYVAL msgclass AS BYTE _                             ' BYTE msgclass
 , BYVAL state AS BYTE _                                ' BYTE state
 , BYREF rpcname AS ASCIIZ _                            ' char * rpcname
 , BYVAL rpcnamelen AS LONG _                           ' int rpcnamelen
 , BYVAL linenum AS WORD _                              ' USHORT linenum
 , BYREF message AS ASCIIZ _                            ' char * message
 , BYVAL msglen AS LONG _                               ' int msglen
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_sendstatus CDECL IMPORT "Opends60.dll" ALIAS "srv_sendstatus" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL status AS LONG _                               ' long int status
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_setuserdata CDECL IMPORT "Opends60.dll" ALIAS "srv_setuserdata" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYREF ptr AS ANY _                                   ' void * ptr
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_sfield CDECL IMPORT "Opends60.dll" ALIAS "srv_sfield" ( _
   BYVAL server AS DWORD _                              ' SRV_SERVER * server
 , BYVAL field AS LONG _                                ' int field
 , BYREF len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_symbol CDECL IMPORT "Opends60.dll" ALIAS "srv_symbol" ( _
   BYVAL type AS LONG _                                 ' int type
 , BYVAL symbol AS LONG _                               ' int symbol
 , BYREF len AS LONG _                                  ' int * len
 ) AS DWORD                                             ' char*

DECLARE FUNCTION srv_tdsversion CDECL IMPORT "Opends60.dll" ALIAS "srv_tdsversion" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_willconvert CDECL IMPORT "Opends60.dll" ALIAS "srv_willconvert" ( _
   BYVAL srctype AS LONG _                              ' int srctype
 , BYVAL desttype AS LONG _                             ' int desttype
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION srv_terminatethread CDECL IMPORT "Opends60.dll" ALIAS "srv_terminatethread" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_sendstatistics CDECL IMPORT "Opends60.dll" ALIAS "srv_sendstatistics" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_clearstatistics CDECL IMPORT "Opends60.dll" ALIAS "srv_clearstatistics" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_message_handler CDECL IMPORT "Opends60.dll" ALIAS "srv_message_handler" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL errornum AS LONG _                             ' int errornum
 , BYVAL severity AS BYTE _                             ' BYTE severity
 , BYVAL state AS BYTE _                                ' BYTE state
 , BYVAL oserrnum AS LONG _                             ' int oserrnum
 , BYREF errtext AS ASCIIZ _                            ' char * errtext
 , BYVAL errtextlen AS LONG _                           ' int errtextlen
 , BYREF oserrtext AS ASCIIZ _                          ' char * oserrtext
 , BYVAL oserrtextlen AS LONG _                         ' int oserrtextlen
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_pre_handle CDECL IMPORT "Opends60.dll" ALIAS "srv_pre_handle" ( _
   BYVAL server AS DWORD _                              ' SRV_SERVER * server
 , BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL event AS LONG _                                ' long int event
 , BYVAL handler AS DWORD _                             ' EventHandler handler
 , BYVAL remove AS LONG _                               ' BOOL remove
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_post_handle CDECL IMPORT "Opends60.dll" ALIAS "srv_post_handle" ( _
   BYVAL server AS DWORD _                              ' SRV_SERVER * server
 , BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL event AS LONG _                                ' long int event
 , BYVAL handler AS DWORD _                             ' EventHandler handler
 , BYVAL remove AS LONG _                               ' BOOL remove
 ) AS LONG                                              ' int

DECLARE FUNCTION srv_IgnoreAnsiToOem CDECL IMPORT "Opends60.dll" ALIAS "srv_IgnoreAnsiToOem" ( _
   BYVAL srvproc AS DWORD _                             ' SRV_PROC * srvproc
 , BYVAL bTF AS LONG _                                  ' BOOL bTF
 ) AS LONG                                              ' int

'#pragma pack()

%SS_MAJOR_VERSION    = 7
%SS_MINOR_VERSION    = 00
%SS_LEVEL_VERSION    = 0000
$SS_MINIMUM_VERSION  = "7.00.00.0000"
'#define ODS_VERSION         ((SS_MAJOR_VERSION << 24)  | (SS_MINOR_VERSION << 16))
%ODS_VERSION         = 7000000

'//////////////////////////////////////////////////////////////////
'// Suggested implementation of __GetXpVersion
'//
'//__declspec(dllexport) ULONG __GetXpVersion()
'//   {
'//   return ODS_VERSION;
'//   }
'//////////////////////////////////////////////////////////////////
