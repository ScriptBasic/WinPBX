' ########################################################################################
' Microsoft Windows
' File: esent.inc
' Contents: Types and constants that are exposed through the ESE API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ESENT_INC = 1

#INCLUDE ONCE "windows.inc"

'// JET_VERSION is similar to WINVER. It allows the most recent header to be used
'// against older targets. Supported versions are:
'// 0x0500  - Windows 2000
'// 0x0501  - Windows XP
'// 0x0502  - Windows 2003
'// 0x0600  - Windows Vista
'// 0x0601  - Windows 7

'#ifndef JET_VERSION
'#  ifdef WINVER
'#    define JET_VERSION WINVER
'#  else
'     // JET_VERSION has not been specified. Assume all functions are available.
'#    define JET_VERSION 0x0600
'#  endif
'#endif

#IF NOT %DEF(%JET_VERSION)
    #IF %DEF(%WINVER)
        %JET_VERSION = %WINVER
    #ELSE
        %JET_VERSION = &H0601
    #ENDIF
#ENDIF

'#IF _WIN64
'    typedef unsigned __int64 JET_API_PTR;
'#else
'    typedef unsigned long JET_API_PTR;
'#ENDIF

'typedef long JET_ERR;

'typedef JET_API_PTR JET_HANDLE;    /* backup file handle */
'typedef JET_API_PTR JET_INSTANCE;  /* Instance Identifier */
'typedef JET_API_PTR JET_SESID;     /* Session Identifier */
'typedef JET_API_PTR JET_TABLEID;   /* Table Identifier */
'#if ( JET_VERSION >= 0x0501 )
'typedef JET_API_PTR JET_LS;        /* Local Storage */
'#endif // JET_VERSION >= 0x0501

'typedef unsigned long JET_COLUMNID;   /* Column Identifier */

' // Size = 16 bytes
TYPE JET_INDEXID DWORD
   cbStruct   AS DWORD         ' unsigned long cbStruct
   rgbIndexId AS STRING * 12   ' unsigned char rgbIndexId[sizeof(JET_API_PTR)+sizeof(unsigned long)+sizeof(unsigned long)]
END TYPE

'typedef unsigned long JET_DBID;     /* Database Identifier */
'typedef unsigned long JET_OBJTYP;   /* Object Type */
'typedef unsigned long JET_COLTYP;   /* Column Type */
'typedef unsigned long JET_GRBIT;    /* Group of Bits */

'typedef unsigned long JET_SNP;      /* Status Notification Process */
'typedef unsigned long JET_SNT;      /* Status Notification Type */
'typedef double JET_DATESERIAL;      /* JET_coltypDateTime format */
'#if ( JET_VERSION >= 0x0501 )
'typedef unsigned long JET_CBTYP;    /* Callback Types */
'#endif // JET_VERSION >= 0x0501

'typedef JET_ERR (__stdcall *JET_PFNSTATUS)(JET_SESID sesid, JET_SNP snp, JET_SNT snt, void *pv);
'FUNCTION JET_PFNSTATUS (BYVAL sesid AS JET_SESID, BYVAL snp AS JET_SNP, BYVAL snt AS JET_SNT, BYVAL pv AS DWORD) AS JET_ERR

'/*   required to make RSTMAP RPC capable
'/**/
'#IF   MIDL_PASS
'#define   xRPC_STRING [string]
'#else
'#define   xRPC_STRING
'#if !defined(_NATIVE_WCHAR_T_DEFINED)
'typedef unsigned short WCHAR;
'#else
'typedef wchar_t WCHAR;
'#ENDIF
'#ENDIF

'typedef __nullterminated char *  JET_PSTR;    /* ASCII string (char *) null terminated */
'typedef __nullterminated const char *  JET_PCSTR;   /* const ASCII string (char *) null terminated */
'typedef __nullterminated WCHAR * JET_PWSTR;   /* Unicode string (char *) null terminated */
'typedef __nullterminated const WCHAR * JET_PCWSTR;  /* const Unicode string (char *) null terminated */

' // Size = 8 bytes
TYPE JET_RSTMAP_A DWORD              ' /* restore map */
   szDatabaseName    AS ASCIIZ PTR   ' xRPC_STRING char *szDatabaseName
   szNewDatabaseName AS ASCIIZ PTR   ' xRPC_STRING char *szNewDatabaseName
END TYPE

' // Size = 8 bytes
TYPE JET_RSTMAP_W DWORD                ' /* restore map */
   szDatabaseName    AS WSTRINGZ PTR   ' xRPC_STRING WCHAR *szDatabaseName
   szNewDatabaseName AS WSTRINGZ PTR   ' xRPC_STRING WCHAR *szNewDatabaseName
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_RSTMAP = JET_RSTMAP_W
#ELSE
   MACRO JET_RSTMAP = JET_RSTMAP_A
#ENDIF

'typedef struct tagCONVERT
'   {
'   char                 *szOldDll;
'   union
'      {
'      unsigned long      fFlags;
'      struct
'         {
'         unsigned long   fSchemaChangesOnly:1;
'         };
'      };
'   } JET_CONVERT;

' // Size = 4 bytes
UNION JET_CONVERT_UNION DWORD
   fFlags             AS DWORD              ' unsigned long fFlags
   fSchemaChangesOnly AS BIT * 1 IN DWORD   ' unsigned long fSchemaChangesOnly:1
END UNION

' // Size = 8 bytes
TYPE JET_CONVERT_A DWORD
   szOldDll AS ASCIIZ PTR   ' char *szOldDll
   JET_CONVERT_UNION
END TYPE

' // Size = 8 bytes
TYPE JET_CONVERT_W DWORD
   szOldDll AS WSTRINGZ PTR     ' WCHAR *szOldDll
   JET_CONVERT_UNION
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_CONVERT = JET_CONVERT_W
#ELSE
   MACRO JET_CONVERT = JET_CONVERT_A
#ENDIF

'//   Online defragmentation options
%JET_bitDefragmentBatchStart          = &H00000001???
%JET_bitDefragmentBatchStop           = &H00000002???
#IF %JET_VERSION >= &H0501
%JET_bitDefragmentAvailSpaceTreesOnly = &H00000040???   ' /* only defrag AvailExt trees */
#ENDIF ' // JET_VERSION >= &H0501

#IF %JET_VERSION >= &H0601
%JET_bitDefragmentNoPartialMerges     = &H00000080???   ' /* don't do partial merges during OLD */
%JET_bitDefragmentBTree               = &H00000100???   ' /* defrag one B-Tree (testing only) */
#ENDIF   ' // JET_VERSION >= 0x0601

#IF %JET_VERSION >= &H0501
   ' /* Callback-function types */

%JET_cbtypNull                        = &H00000000???
%JET_cbtypFinalize                    = &H00000001???   ' /* a finalizable column has gone to zero */
%JET_cbtypBeforeInsert                = &H00000002???   ' /* about to insert a record */
%JET_cbtypAfterInsert                 = &H00000004???   ' /* finished inserting a record */
%JET_cbtypBeforeReplace               = &H00000008???   ' /* about to modify a record */
%JET_cbtypAfterReplace                = &H00000010???   ' /* finished modifying a record */
%JET_cbtypBeforeDelete                = &H00000020???   ' /* about to delete a record */
%JET_cbtypAfterDelete                 = &H00000040???   ' /* finished deleting the record */
%JET_cbtypUserDefinedDefaultValue     = &H00000080???   ' /* calculating a user-defined default */
%JET_cbtypOnlineDefragCompleted       = &H00000100???   ' /* a call to JetDefragment2 has completed */
%JET_cbtypFreeCursorLS                = &H00000200???   ' /* the Local Storage associated with a cursor must be freed */
%JET_cbtypFreeTableLS                 = &H00000400???   ' /* the Local Storage associated with a table must be freed */

'   /* Callback-function prototype */

'typedef JET_ERR (__stdcall *JET_CALLBACK)(
'   JET_SESID      sesid,
'   JET_DBID       dbid,
'   JET_TABLEID    tableid,
'   JET_CBTYP      cbtyp,
'   void *         pvArg1,
'   void *         pvArg2,
'   void *         pvContext,
'   JET_API_PTR    ulUnused );

'FUNCTION JET_CALLBACK ( _
'   BYVAL sesid AS DWORD _
' , BYVAL dbid AS DWORD _
' , BYVAL tableid AS DWORD _
' , BYVAL cbtyp AS DWORD _
' , BYVAL pvArg1 AS DWORD _
' , BYVAL pvArg2 AS DWORD _
' , BYVAL pvContext AS DWORD _
' , BYVAL ulUnused AS DWORD _
' ) AS LONG

'END FUNCTION

#ENDIF ' // JET_VERSION >= 0x0501

'   /* Status Notification Structures */

' // Size = 12 bytes
TYPE JET_SNPROG DWORD    ' /* Status Notification Progress */
   cbStruct   AS DWORD   ' unsigned long /* Size of this structure */
   cunitDone  AS DWORD   ' unsigned long /* Number of units of work completed */
   cunitTotal AS DWORD   ' unsigned long /* Total number of units of work */
END TYPE

'typedef struct
'   {
'   unsigned long         cbStruct;

'   unsigned long         cbFilesizeLow;           //   file's current size (low DWORD)
'   unsigned long         cbFilesizeHigh;          //   file's current size (high DWORD)

'   unsigned long         cbFreeSpaceRequiredLow;  //   estimate of free disk space required for in-place upgrade (low DWORD)
'   unsigned long         cbFreeSpaceRequiredHigh; //   estimate of free disk space required for in-place upgrade (high DWORD)

'   unsigned long         csecToUpgrade;           //   estimate of time required, in seconds, for upgrade

'   union
'      {
'      unsigned long      ulFlags;
'      struct
'         {
'         unsigned long   fUpgradable:1;
'         unsigned long   fAlreadyUpgraded:1;
'         };
'      };
'   } JET_DBINFOUPGRADE;

' // Size = 4 bytes
TYPE JET_DBINFOUPGRADE_UNION_TYPE DWORD
   fUpgradable      AS BIT * 1 IN DWORD   ' unsigned long fUpgradable:1
   fAlreadyUpgraded AS BIT * 1            ' unsigned long fAlreadyUpgraded:1
END TYPE

' // Size = 4 bytes
UNION JET_DBINFOUPGRADE_UNION DWORD
   ulFlags AS DWORD                   ' unsigned long
   JET_DBINFOUPGRADE_UNION_TYPE
END UNION

' // Size = 28 bytes
TYPE JET_DBINFOUPGRADE DWORD
   cbStruct                AS DWORD   ' unsigned long
   cbFilesizeLow           AS DWORD   ' unsigned long // file's current size (low DWORD)
   cbFilesizeHigh          AS DWORD   ' unsigned long // file's current size (high DWORD)
   cbFreeSpaceRequiredLow  AS DWORD   ' unsigned long // estimate of free disk space required for in-place upgrade (low DWORD)
   cbFreeSpaceRequiredHigh AS DWORD   ' unsigned long // estimate of free disk space required for in-place upgrade (high DWORD)
   csecToUpgrade           AS DWORD   ' unsigned long // estimate of time required, in seconds, for upgrade
   JET_DBINFOUPGRADE_UNION
END TYPE

' // Size = 40 bytes
TYPE JET_OBJECTINFO DWORD
   cbStruct AS DWORD    ' unsigned long
   objtyp   AS DWORD    ' JET_OBJTYP
   dtCreate AS DOUBLE   ' JET_DATESERIAL //  Deprecated.
   dtUpdate AS DOUBLE   ' JET_DATESERIAL //  Deprecated.
   grbit    AS DWORD    ' JET_GRBIT
   flags    AS DWORD    ' unsigned long
   cRecord  AS DWORD    ' unsigned long
   cPage    AS DWORD    ' unsigned long
END TYPE

'   /* The following flags appear in the grbit field above */

%JET_bitTableInfoUpdatable   = &H00000001???
%JET_bitTableInfoBookmark    = &H00000002???
%JET_bitTableInfoRollback    = &H00000004???

'   /* The following flags occur in the flags field above */

%JET_bitObjectSystem         = &H80000000???  ' // Internal use only
%JET_bitObjectTableFixedDDL  = &H40000000???  ' // Table's DDL is fixed
%JET_bitObjectTableTemplate  = &H20000000???  ' // Table's DDL is inheritable (implies FixedDDL)
%JET_bitObjectTableDerived   = &H10000000???  ' // Table's DDL is inherited from a template table
#IF %JET_VERSION >= &H0501
%JET_bitObjectTableNoFixedVarColumnsInDerivedTables = &H04000000???  ' //   used in conjunction with JET_bitObjectTableTemplate
                                                    '  //   to disallow fixed/var columns in derived tables (so that
                                                    '  //   fixed/var columns may be added to the template in the future)
#ENDIF ' // JET_VERSION >= 0x0501

' // Size = 48 bytes
TYPE JET_OBJECTLIST DWORD
   cbStruct              AS DWORD   ' unsigned long
   tableid               AS DWORD   ' JET_TABLEID
   cRecord               AS DWORD   ' unsigned long
   columnidcontainername AS DWORD   ' JET_COLUMNID
   columnidobjectname    AS DWORD   ' JET_COLUMNID
   columnidobjtyp        AS DWORD   ' JET_COLUMNID
   columniddtCreate      AS DWORD   ' JET_COLUMNID //  XXX -- to be deleted
   columniddtUpdate      AS DWORD   ' JET_COLUMNID //  XXX -- to be deleted
   columnidgrbit         AS DWORD   ' JET_COLUMNID
   columnidflags         AS DWORD   ' JET_COLUMNID
   columnidcRecord       AS DWORD   ' JET_COLUMNID /* Level 2 info */
   columnidcPage         AS DWORD   ' JET_COLUMNID /* Level 2 info */
END TYPE

'#define cObjectInfoCols 9
%cObjectInfoCols = 9

' // Size = 68 bytes
TYPE JET_COLUMNLIST DWORD
   cbStruct                  AS DWORD   ' unsigned long
   tableid                   AS DWORD   ' JET_TABLEID
   cRecord                   AS DWORD   ' unsigned long
   columnidPresentationOrder AS DWORD   ' JET_COLUMNID
   columnidcolumnname        AS DWORD   ' JET_COLUMNID
   columnidcolumnid          AS DWORD   ' JET_COLUMNID
   columnidcoltyp            AS DWORD   ' JET_COLUMNID
   columnidCountry           AS DWORD   ' JET_COLUMNID
   columnidLangid            AS DWORD   ' JET_COLUMNID
   columnidCp                AS DWORD   ' JET_COLUMNID
   columnidCollate           AS DWORD   ' JET_COLUMNID
   columnidcbMax             AS DWORD   ' JET_COLUMNID
   columnidgrbit             AS DWORD   ' JET_COLUMNID
   columnidDefault           AS DWORD   ' JET_COLUMNID
   columnidBaseTableName     AS DWORD   ' JET_COLUMNID
   columnidBaseColumnName    AS DWORD   ' JET_COLUMNID
   columnidDefinitionName    AS DWORD   ' JET_COLUMNID
END TYPE

%cColumnInfoCols = 14

' // Size = 28 bytes
TYPE JET_COLUMNDEF DWORD FILL
   cbStruct AS DWORD   ' unsigned long
   columnid AS DWORD   ' JET_COLUMNID
   coltyp   AS DWORD   ' JET_COLTYP
   wCountry AS WORD    ' unsigned short
   langid   AS WORD    ' unsigned short
   cp       AS WORD    ' unsigned short
   wCollate AS WORD    ' unsigned short /* Must be 0 */
   cbMax    AS DWORD   ' unsigned long
   grbit    AS DWORD   ' JET_GRBIT
END TYPE

' // Size = 540 bytes
TYPE JET_COLUMNBASE_A DWORD FILL
   cbStruct         AS DWORD          ' unsigned long
   columnid         AS DWORD          ' JET_COLUMNID
   coltyp           AS DWORD          ' JET_COLTYP
   wCountry         AS WORD           ' unsigned short
   langid           AS WORD           ' unsigned short
   cp               AS WORD           ' unsigned short
   wFiller          AS WORD           ' unsigned short /* Must be 0 */
   cbMax            AS DWORD          ' unsigned long
   grbit            AS DWORD          ' JET_GRBIT
   szBaseTableName  AS ASCIIZ * 256   ' char szBaseTableName[256]
   szBaseColumnName AS ASCIIZ * 256   ' char szBaseColumnName[256]
END TYPE

' // Size = 1052 bytes
TYPE JET_COLUMNBASE_W DWORD FILL
   cbStruct         AS DWORD            ' unsigned long
   columnid         AS DWORD            ' JET_COLUMNID
   coltyp           AS DWORD            ' JET_COLTYP
   wCountry         AS WORD             ' unsigned short
   langid           AS WORD             ' unsigned short
   cp               AS WORD             ' unsigned short
   wFiller          AS WORD             ' unsigned short /* Must be 0 */
   cbMax            AS DWORD            ' unsigned long
   grbit            AS DWORD            ' JET_GRBIT
   szBaseTableName  AS WSTRINGZ * 256   ' WCHAR szBaseTableName[256]
   szBaseColumnName AS WSTRINGZ * 256   ' WCHAR szBaseColumnName[256]
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_COLUMNBASE = JET_COLUMNBASE_W
#ELSE
   MACRO JET_COLUMNBASE = JET_COLUMNBASE_A
#ENDIF

' // Size = 76 bytes
TYPE JET_INDEXLIST DWORD
   cbStruct            AS DWORD   ' unsigned long
   tableid             AS DWORD   ' JET_TABLEID
   cRecord             AS DWORD   ' unsigned long
   columnidindexname   AS DWORD   ' JET_COLUMNID
   columnidgrbitIndex  AS DWORD   ' JET_COLUMNID
   columnidcKey        AS DWORD   ' JET_COLUMNID
   columnidcEntry      AS DWORD   ' JET_COLUMNID
   columnidcPage       AS DWORD   ' JET_COLUMNID
   columnidcColumn     AS DWORD   ' JET_COLUMNID
   columnidiColumn     AS DWORD   ' JET_COLUMNID
   columnidcolumnid    AS DWORD   ' JET_COLUMNID
   columnidcoltyp      AS DWORD   ' JET_COLUMNID
   columnidCountry     AS DWORD   ' JET_COLUMNID
   columnidLangid      AS DWORD   ' JET_COLUMNID
   columnidCp          AS DWORD   ' JET_COLUMNID
   columnidCollate     AS DWORD   ' JET_COLUMNID
   columnidgrbitColumn AS DWORD   ' JET_COLUMNID
   columnidcolumnname  AS DWORD   ' JET_COLUMNID
   columnidLCMapFlags  AS DWORD   ' JET_COLUMNID
END TYPE

%cIndexInfoCols = 15

' // Size = 40 bytes
TYPE JET_COLUMNCREATE_A DWORD
   cbStruct     AS DWORD              ' unsigned long // size of this structure (for future expansion)
   szColumnName AS ASCIIZ PTR         ' char *        // column name
   coltyp       AS DWORD              ' JET_COLTYP    // column type
   cbMax        AS DWORD              ' unsigned long // the maximum length of this column (only relevant for binary and text columns)
   grbit        AS DWORD              ' JET_GRBIT     // column options
   pvDefault    AS DWORD              ' void *        // default value (NULL if none)
   cbDefault    AS DWORD              ' unsigned long // length of default value
   cp           AS DWORD              ' unsigned long // code page (for text columns only)
   columnid     AS DWORD              ' JET_COLUMNID  // returned column id
   err          AS LONG               ' JET_ERR       // returned error code
END TYPE

' // Size = 40 bytes
TYPE JET_COLUMNCREATE_W DWORD
   cbStruct     AS DWORD              ' unsigned long // size of this structure (for future expansion)
   szColumnName AS WSTRINGZ PTR       ' WCHAR *       // column name
   coltyp       AS DWORD              ' JET_COLTYP    // column type
   cbMax        AS DWORD              ' unsigned long // the maximum length of this column (only relevant for binary and text columns)
   grbit        AS DWORD              ' JET_GRBIT     // column options
   pvDefault    AS DWORD              ' void *        // default value (NULL if none)
   cbDefault    AS DWORD              ' unsigned long // length of default value
   cp           AS DWORD              ' unsigned long // code page (for text columns only)
   columnid     AS DWORD              ' JET_COLUMNID  // returned column id
   err          AS LONG               ' JET_ERR       // returned error code
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_COLUMNCREATE = JET_COLUMNCREATE_W
#ELSE
   MACRO JET_COLUMNCREATE = JET_COLUMNCREATE_A
#ENDIF

#IF %JET_VERSION >= &H0501
'//  This is the information needed to create a column with a user-defined default. It should be passed in using
'//  the pvDefault and cbDefault in a JET_COLUMNCREATE structure
' // Size = 16 bytes
TYPE JET_USERDEFINEDDEFAULT_A DWORD
   szCallback         AS ASCIIZ PTR   ' char *
   pbUserData         AS DWORD        ' unsigned char *
   cbUserData         AS DWORD        ' unsigned long
   szDependantColumns AS ASCIIZ PTR   ' char *
END TYPE

' // Size = 16 bytes
TYPE JET_USERDEFINEDDEFAULT_W DWORD
   szCallback         AS WSTRINGZ PTR   ' WCHAR *
   pbUserData         AS DWORD          ' unsigned char *
   cbUserData         AS DWORD          ' unsigned long
   szDependantColumns AS WSTRINGZ PTR   ' WCHAR *
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_USERDEFINEDDEFAULT = JET_USERDEFINEDDEFAULT_W
#ELSE
   MACRO JET_USERDEFINEDDEFAULT = JET_USERDEFINEDDEFAULT_A
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

' // Size = 12 bytes
TYPE JET_CONDITIONALCOLUMN_A DWORD
   cbStruct     AS DWORD           ' unsigned long // size of this structure (for future expansion)
   szColumnName AS ASCIIZ PTR      ' char *        // column that we are conditionally indexed on
   grbit        AS DWORD           ' JET_GRBIT     // conditional column options
END TYPE

' // Size = 12 bytes
TYPE JET_CONDITIONALCOLUMN_W DWORD
   cbStruct     AS DWORD           ' unsigned long // size of this structure (for future expansion)
   szColumnName AS WSTRINGZ PTR    ' WCHAR *       // column that we are conditionally indexed on
   grbit        AS DWORD           ' JET_GRBIT     // conditional column options
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_CONDITIONALCOLUMN = JET_CONDITIONALCOLUMN_W
#ELSE
   MACRO JET_CONDITIONALCOLUMN = JET_CONDITIONALCOLUMN_A
#ENDIF

' // Size = 8 bytes
TYPE JET_UNICODEINDEX DWORD
   lcid       AS DWORD   ' unsigned long
   dwMapFlags AS DWORD   ' unsigned long
END TYPE

#IF %JET_VERSION >= &H0502
' // Size = 20 bytes
TYPE JET_TUPLELIMITS DWORD
   chLengthMin  AS DWORD   ' unsigned long
   chLengthMax  AS DWORD   ' unsigned long
   chToIndexMax AS DWORD   ' unsigned long
#IF %JET_VERSION >= &H0600
   cchIncrement AS DWORD   ' unsigned long
   ichStart     AS DWORD   ' unsigned long
#ENDIF   ' // JET_VERSION >= 0x0600
END TYPE
#ENDIF ' // JET_VERSION >= 0x0502

#IF %JET_VERSION >= &H0601
'//   This structure describes some of the hints we can give to a given B-tree, be it a
'//   table, index, or the internal long values tree.
' // Size = 32 bytes
TYPE JET_SPACEHINTS DWORD
   cbStruct         AS DWORD   ' unsigned long //   size of this structure
   ulInitialDensity AS DWORD   ' unsigned long //   density at (append) layout.
   cbInitial        AS DWORD   ' unsigned long //   initial size (in bytes).

   grbit            AS DWORD   ' JET_GRBIT //   Combination of one or more flags from
                               ' //      JET_bitSpaceHints* flags
                               ' //      JET_bitCreateHints* flags
                               ' //      JET_bitRetrieveHints* flags
                               ' //      JET_bitUpdateHints* flags
                               ' //      JET_bitDeleteHints* flags
   ulMaintDensity   AS DWORD   ' unsigned long //   density to maintain at.
   ulGrowth         AS DWORD   ' unsigned long //   percent growth from:
                               ' //     last growth or initial size (possibly rounded to nearest native JET allocation size).
   cbMinExtent      AS DWORD   ' unsigned long //   This overrides ulGrowth if too small.
   cbMaxExtent      AS DWORD   ' unsigned long //   This caps ulGrowth.
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0601

'typedef struct tagJET_INDEXCREATE
'   {
'   unsigned long         cbStruct;            // size of this structure (for future expansion)
'   char                 *szIndexName;         // index name
'   char                 *szKey;               // index key
'   unsigned long         cbKey;               // length of key
'   JET_GRBIT             grbit;               // index options
'   unsigned long         ulDensity;           // index density

'   union
'      {
'      unsigned long      lcid;                // lcid for the index (if JET_bitIndexUnicode NOT specified)
'      JET_UNICODEINDEX  *pidxunicode;         // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
'      };

'   union
'      {
'      unsigned long      cbVarSegMac;         // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
'#ifdef JET_VERSION >= &H0502
'      JET_TUPLELIMITS   *ptuplelimits;        // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
'#endif // ! JET_VERSION >= &H0502
'      };
'   JET_CONDITIONALCOLUMN   *rgconditionalcolumn;   // pointer to conditional column structure
'   unsigned long         cConditionalColumn;      // number of conditional columns
'   JET_ERR               err;               // returned error code
'   } JET_INDEXCREATE;

' // Size = 4 bytes
UNION JET_INDEXCREATE_UNION_1 DWORD
   lcid        AS DWORD                  ' unsigned long      // lcid for the index (if JET_bitIndexUnicode NOT specified)
   pidxunicode AS JET_UNICODEINDEX PTR   ' JET_UNICODEINDEX * // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
END UNION

' // Size = 4 bytes
UNION JET_INDEXCREATE_UNION_2 DWORD
   cbVarSegMac  AS DWORD                 ' unsigned long     // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
#IF %JET_VERSION >= &H0502
   ptuplelimits AS JET_TUPLELIMITS PTR   ' JET_TUPLELIMITS * // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
#ENDIF ' // ! JET_VERSION >= 0x0502
END UNION

' // Size = 48 bytes
TYPE JET_INDEXCREATE_A DWORD
   cbStruct                AS DWORD                       ' unsigned long // size of this structure (for future expansion)
   szIndexName             AS ASCIIZ PTR                  ' char *        // index name
   szKey                   AS ASCIIZ PTR                  ' char *        // index key
   cbKey                   AS DWORD                       ' unsigned long // length of key
   grbit                   AS DWORD                       ' JET_GRBIT     // index options
   ulDensity               AS DWORD                       ' unsigned long // index density
   JET_INDEXCREATE_UNION_1
   JET_INDEXCREATE_UNION_2
   rgconditionalcolumn     AS JET_CONDITIONALCOLUMN_A PTR ' JET_CONDITIONALCOLUMN_A * // pointer to conditional column structure
   cConditionalColumn      AS DWORD                       ' unsigned long // number of conditional columns
   err                     AS LONG                        ' JET_ERR       // returned error code
#IF %JET_VERSION >= &H0600
   cbKeyMost               AS DWORD                       ' unsigned long // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
#ENDIF   ' // JET_VERSION >= 0x0600
END TYPE

'typedef struct tagJET_INDEXCREATE_W
'   {
'   unsigned long         cbStruct;            // size of this structure (for future expansion)
'   WCHAR               *szIndexName;         // index name
'   WCHAR               *szKey;               // index key definition
'   unsigned long         cbKey;               // size of key definition in szKey
'   JET_GRBIT            grbit;               // index options
'   unsigned long         ulDensity;            // index density

'   union
'      {
'      unsigned long      lcid;               // lcid for the index (if JET_bitIndexUnicode NOT specified)
'      JET_UNICODEINDEX   *pidxunicode;         // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
'      };

'   union
'      {
'      unsigned long      cbVarSegMac;         // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
'#if ( JET_VERSION >= 0x0502 )
'      JET_TUPLELIMITS      *ptuplelimits;         // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
'#endif // ! JET_VERSION >= 0x0502
'      };

'   JET_CONDITIONALCOLUMN_W   *rgconditionalcolumn;   // pointer to conditional column structure
'   unsigned long         cConditionalColumn;      // number of conditional columns
'   JET_ERR               err;               // returned error code
'#if ( JET_VERSION >= 0x0600 )
'   unsigned long         cbKeyMost;            // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
'#endif // JET_VERSION >= 0x0600
'   } JET_INDEXCREATE_W;

' // Size = 48 bytes
TYPE JET_INDEXCREATE_W DWORD
   cbStruct                AS DWORD                       ' unsigned long // size of this structure (for future expansion)
   szIndexName             AS WSTRINGZ PTR                ' WCHAR *       // index name
   szKey                   AS WSTRINGZ PTR                ' WCHAFR *      // index key
   cbKey                   AS DWORD                       ' unsigned long // length of key
   grbit                   AS DWORD                       ' JET_GRBIT     // index options
   ulDensity               AS DWORD                       ' unsigned long // index density
   JET_INDEXCREATE_UNION_1
   JET_INDEXCREATE_UNION_2
   rgconditionalcolumn     AS JET_CONDITIONALCOLUMN_W PTR ' JET_CONDITIONALCOLUMN_W * // pointer to conditional column structure
   cConditionalColumn      AS DWORD                       ' unsigned long // number of conditional columns
   err                     AS LONG                        ' JET_ERR       // returned error code
#IF %JET_VERSION >= &H0600
   cbKeyMost               AS DWORD                       ' unsigned long // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
#ENDIF   ' // JET_VERSION >= 0x0600
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_INDEXCREATE = JET_INDEXCREATE_W
#ELSE
   MACRO JET_INDEXCREATE = JET_INDEXCREATE_A
#ENDIF

#IF %JET_VERSION >= &H0601

'typedef struct tagJET_INDEXCREATE2_A
'   {
'   unsigned long         cbStruct;            // size of this structure (for future expansion)
'   char               *szIndexName;         // index name
'   char               *szKey;               // index key definition
'   unsigned long         cbKey;               // size of key definition in szKey
'   JET_GRBIT            grbit;               // index options
'   unsigned long         ulDensity;            // index density

'   union
'      {
'      unsigned long      lcid;               // lcid for the index (if JET_bitIndexUnicode NOT specified)
'      JET_UNICODEINDEX   *pidxunicode;         // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
'      };

'   union
'      {
'      unsigned long      cbVarSegMac;         // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
'      JET_TUPLELIMITS      *ptuplelimits;         // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
'      };

'   JET_CONDITIONALCOLUMN_A   *rgconditionalcolumn;   // pointer to conditional column structure
'   unsigned long         cConditionalColumn;      // number of conditional columns
'   JET_ERR               err;               // returned error code
'   unsigned long         cbKeyMost;            // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
'   JET_SPACEHINTS *        pSpacehints;         // space allocation, maintenance, and usage hints
'   } JET_INDEXCREATE2_A;

' // Size = 4 bytes
UNION JET_INDEXCREATE2_UNION_1 DWORD
   lcid        AS DWORD                  ' unsigned long      // lcid for the index (if JET_bitIndexUnicode NOT specified)
   pidxunicode AS JET_UNICODEINDEX PTR   ' JET_UNICODEINDEX * // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
END UNION

' // Size = 4 bytes
UNION JET_INDEXCREATE2_UNION_2 DWORD
   cbVarSegMac  AS DWORD                 ' unsigned long     // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
   ptuplelimits AS JET_TUPLELIMITS PTR   ' JET_TUPLELIMITS * // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
END UNION

' // Size = 52 bytes
TYPE JET_INDEXCREATE2_A DWORD
   cbStruct                AS DWORD                       ' unsigned long // size of this structure (for future expansion)
   szIndexName             AS ASCIIZ PTR                  ' char *        // index name
   szKey                   AS ASCIIZ PTR                  ' char *        // index key definition
   cbKey                   AS DWORD                       ' unsigned long // size of key definition in szKey
   grbit                   AS DWORD                       ' JET_GRBIT     // index options
   ulDensity               AS DWORD                       ' unsigned long // index density
   JET_INDEXCREATE2_UNION_1
   JET_INDEXCREATE2_UNION_2
   rgconditionalcolumn     AS JET_CONDITIONALCOLUMN_A PTR ' JET_CONDITIONALCOLUMN_A * // pointer to conditional column structure
   cConditionalColumn      AS DWORD                       ' unsigned long // number of conditional columns
   err                     AS LONG                        ' JET_ERR       // returned error code
   cbKeyMost               AS DWORD                       ' unsigned long // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
   pSpacehints             AS JET_SPACEHINTS PTR          ' JET_SPACEHINTS * pSpacehints // space allocation, maintenance, and usage hints
END TYPE

'typedef struct tagJET_INDEXCREATE2_W
'   {
'   unsigned long         cbStruct;            // size of this structure (for future expansion)
'   WCHAR               *szIndexName;         // index name
'   WCHAR               *szKey;               // index key definition
'   unsigned long         cbKey;               // size of key definition in szKey
'   JET_GRBIT            grbit;               // index options
'   unsigned long         ulDensity;            // index density

'   union
'      {
'      unsigned long      lcid;               // lcid for the index (if JET_bitIndexUnicode NOT specified)
'      JET_UNICODEINDEX   *pidxunicode;         // pointer to JET_UNICODEINDEX struct (if JET_bitIndexUnicode specified)
'      };

'   union
'      {
'      unsigned long      cbVarSegMac;         // maximum length of variable length columns in index key (if JET_bitIndexTupleLimits specified)
'      JET_TUPLELIMITS      *ptuplelimits;         // pointer to JET_TUPLELIMITS struct (if JET_bitIndexTupleLimits specified)
'      };

'   JET_CONDITIONALCOLUMN_W   *rgconditionalcolumn;   // pointer to conditional column structure
'   unsigned long         cConditionalColumn;      // number of conditional columns
'   JET_ERR               err;               // returned error code
'   unsigned long         cbKeyMost;            // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
'   JET_SPACEHINTS *      pSpacehints;         // space allocation, maintenance, and usage hints
'   } JET_INDEXCREATE2_W;

' // Size = 52 bytes
TYPE JET_INDEXCREATE2_W DWORD
   cbStruct                AS DWORD                       ' unsigned long // size of this structure (for future expansion)
   szIndexName             AS WSTRINGZ PTR                ' WCHAR *       // index name
   szKey                   AS WSTRINGZ PTR                ' WCHAR *       // index key definition
   cbKey                   AS DWORD                       ' unsigned long // size of key definition in szKey
   grbit                   AS DWORD                       ' JET_GRBIT     // index options
   ulDensity               AS DWORD                       ' unsigned long // index density
   JET_INDEXCREATE2_UNION_1
   JET_INDEXCREATE2_UNION_2
   rgconditionalcolumn     AS JET_CONDITIONALCOLUMN_W PTR ' JET_CONDITIONALCOLUMN_W * // pointer to conditional column structure
   cConditionalColumn      AS DWORD                       ' unsigned long // number of conditional columns
   err                     AS LONG                        ' JET_ERR       // returned error code
   cbKeyMost               AS DWORD                       ' unsigned long // size of key preserved in index, e.g. without truncation (if JET_bitIndexKeyMost specified)
   pSpacehints             AS JET_SPACEHINTS PTR          ' JET_SPACEHINTS * pSpacehints // space allocation, maintenance, and usage hints
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_INDEXCREATE2 = JET_INDEXCREATE2_W
#ELSE
   MACRO JET_INDEXCREATE2 = JET_INDEXCREATE2_A
#ENDIF

#ENDIF

' // Note: Although esent.h specifies JET_VERSION >= &H0601, the two below structures must be available to other versions.

' // Size = 48 bytes
TYPE JET_TABLECREATE_A DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS ASCIIZ PTR             ' char *               // name of table to create.
   szTemplateTableName AS ASCIIZ PTR             ' char *               // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_A PTR ' JET_COLUMNCREATE_A * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE_A  PTR ' JET_INDEXCREATE_A *  // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   grbit               AS DWORD                  ' JET_GRBIT
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes).
END TYPE

' // Size = 48 bytes
TYPE JET_TABLECREATE_W DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS WSTRINGZ PTR           ' WCHAR *              // name of table to create.
   szTemplateTableName AS WSTRINGZ PTR           ' WCHAR *              // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_W PTR ' JET_COLUMNCREATE_W * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE_W  PTR ' JET_INDEXCREATE_W *  // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   grbit               AS DWORD                  ' JET_GRBIT
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes).
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_TABLECREATE = JET_TABLECREATE_W
#ELSE
   MACRO JET_TABLECREATE = JET_TABLECREATE_A
#ENDIF

'#ENDIF

#IF %JET_VERSION >= &H0501
' // Size = 56 bytes
TYPE JET_TABLECREATE2_A DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS ASCIIZ PTR             ' char *               // name of table to create.
   szTemplateTableName AS ASCIIZ PTR             ' char *               // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_A PTR ' JET_COLUMNCREATE_A * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE_A  PTR ' JET_INDEXCREATE_A *  // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   szCallback          AS ASCIIZ PTR             ' char*                // callback to use for this table
   cbtyp               AS DWORD                  ' JET_CBTYP            // when the callback should be called
   grbit               AS DWORD                  ' JET_GRBIT
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes+callbacks).
END TYPE

' // Size = 56 bytes
TYPE JET_TABLECREATE2_W DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS WSTRINGZ PTR           ' WCHAR *              // name of table to create.
   szTemplateTableName AS WSTRINGZ PTR           ' WCHAR *              // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_W PTR ' JET_COLUMNCREATE_W * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE_W  PTR ' JET_INDEXCREATE_W *  // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   szCallback          AS WSTRINGZ PTR           ' WCHAR*               // callback to use for this table
   cbtyp               AS DWORD                  ' JET_CBTYP            // when the callback should be called
   grbit               AS DWORD                  ' JET_GRBIT
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes+callbacks).
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_TABLECREATE2 = JET_TABLECREATE2_W
#ELSE
   MACRO JET_TABLECREATE2 = JET_TABLECREATE2_A
#ENDIF

#ENDIF  ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0601
' // Size = 68 bytes
TYPE JET_TABLECREATE3_A DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS ASCIIZ PTR             ' char *               // name of table to create.
   szTemplateTableName AS ASCIIZ PTR             ' char *               // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_A PTR ' JET_COLUMNCREATE_A * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE2_A PTR ' JET_INDEXCREATE2_A * // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   szCallback          AS ASCIIZ PTR             ' char*                // callback to use for this table
   cbtyp               AS DWORD                  ' JET_CBTYP            // when the callback should be called
   grbit               AS DWORD                  ' JET_GRBIT
   pSeqSpacehints      AS JET_SPACEHINTS PTR     ' JET_SPACEHINTS * pSeqSpacehints // space allocation, maintenance, and usage hints for default sequential index
   pLVSpacehints       AS JET_SPACEHINTS PTR     ' JET_SPACEHINTS * pLVSpacehints // space allocation, maintenance, and usage hints for Separated LV tree.
   cbSeparateLV        AS DWORD                  ' unsigned long cbSeparateLV // heuristic size to separate a intrinsic LV from the primary record
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes+callbacks).
END TYPE

' // Size = 68 bytes
TYPE JET_TABLECREATE3_W DWORD
   cbStruct            AS DWORD                  ' unsigned long        // size of this structure (for future expansion)
   szTableName         AS WSTRINGZ PTR           ' WCHAR *              // name of table to create.
   szTemplateTableName AS WSTRINGZ PTR           ' WCHAR *              // name of table from which to inherit base DDL
   ulPages             AS DWORD                  ' unsigned long        // initial pages to allocate for table.
   ulDensity           AS DWORD                  ' unsigned long        // table density.
   rgcolumncreate      AS JET_COLUMNCREATE_W PTR ' JET_COLUMNCREATE_W * // array of column creation info
   cColumns            AS DWORD                  ' unsigned long        // number of columns to create
   rgindexcreate       AS JET_INDEXCREATE2_W PTR ' JET_INDEXCREATE2_W * // array of index creation info
   cIndexes            AS DWORD                  ' unsigned long        // number of indexes to create
   szCallback          AS ASCIIZ PTR             ' char*                // callback to use for this table
   cbtyp               AS DWORD                  ' JET_CBTYP            // when the callback should be called
   grbit               AS DWORD                  ' JET_GRBIT
   pSeqSpacehints      AS JET_SPACEHINTS PTR     ' JET_SPACEHINTS * pSeqSpacehints // space allocation, maintenance, and usage hints for default sequential index
   pLVSpacehints       AS JET_SPACEHINTS PTR     ' JET_SPACEHINTS * pLVSpacehints // space allocation, maintenance, and usage hints for Separated LV tree.
   cbSeparateLV        AS DWORD                  ' unsigned long cbSeparateLV // heuristic size to separate a intrinsic LV from the primary record
   tableid             AS DWORD                  ' JET_TABLEID          // returned tableid.
   cCreated            AS DWORD                  ' unsigned long        // count of objects created (columns+table+indexes+callbacks).
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_TABLECREATE3 = JET_TABLECREATE3_W
#ELSE
   MACRO JET_TABLECREATE3 = JET_TABLECREATE3_A
#ENDIF

#ENDIF

#IF %JET_VERSION >= &H0600
' // Size = 36 bytes
TYPE JET_OPENTEMPORARYTABLE DWORD
   cbStruct     AS DWORD                  ' unsigned long // size of this structure (for future expansion)
   prgcolumndef AS JET_COLUMNDEF PTR      ' const JET_COLUMNDEF*
   ccolumn      AS DWORD                  ' unsigned long
   pidxunicode  AS JET_UNICODEINDEX PTR   ' JET_UNICODEINDEX*
   grbit        AS DWORD                  ' JET_GRBIT
   prgcolumnid  AS DWORD PTR              ' JET_COLUMNID*
   cbKeyMost    AS DWORD                  ' unsigned long
   cbVarSegMac  AS DWORD                  ' unsigned long
   tableid      AS DWORD                  ' JET_TABLEID
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0600

' // Size = 16 bytes
TYPE JET_RETINFO DWORD
   cbStruct           AS DWORD   ' unsigned long
   ibLongValue        AS DWORD   ' unsigned long
   itagSequence       AS DWORD   ' unsigned long
   columnidNextTagged AS DWORD   ' JET_COLUMNID
END TYPE

' // Size = 12 bytes
TYPE JET_SETINFO DWORD
   cbStruct     AS DWORD   ' unsigned long
   ibLongValue  AS DWORD   ' unsigned long
   itagSequence AS DWORD   ' unsigned long
END TYPE

' // Size = 16 bytes
TYPE JET_RECPOS DWORD
   cbStruct        AS DWORD   ' unsigned long
   centriesLT      AS DWORD   ' unsigned long
   centriesInRange AS DWORD   ' unsigned long
   centriesTotal   AS DWORD   ' unsigned long
END TYPE

' // Size = 16 bytes
TYPE JET_RECORDLIST DWORD
   cbStruct         AS DWORD   ' unsigned long
   tableid          AS DWORD   ' JET_TABLEID
   cRecord          AS DWORD   ' unsigned long
   columnidBookmark AS DWORD   ' JET_COLUMNID
END TYPE

' // Size = 12 bytes
TYPE JET_INDEXRANGE DWORD
   cbStruct AS DWORD   ' unsigned long
   tableid  AS DWORD   ' JET_TABLEID
   grbit    AS DWORD   ' JET_GRBIT
END TYPE


'#include <pshpack1.h>
%JET_MAX_COMPUTERNAME_LENGTH = 15

'typedef struct   {
'   char      bSeconds;            //   0 - 59
'   char      bMinutes;            //   0 - 59
'   char      bHours;              //   0 - 23
'   char      bDay;                //   1 - 31
'   char      bMonth;              //   1 - 12
'   char      bYear;               //   current year - 1900
'   union
'      {
'      char      bFiller1;
'      struct
'         {
'         unsigned char fTimeIsUTC:1;
'         unsigned char fUnused:7;
'         };
'      };
'   char      bFiller2;
'   } JET_LOGTIME;

' // Size = 1 byte
TYPE JET_LOGTIME_UNION_STRUCT BYTE
   fTimeIsUTC AS BIT * 1 IN BYTE   ' unsigned char
   fUnused    AS BIT * 7
END TYPE

' // Size = 1 byte
UNION JET_LOGTIME_UNION BYTE
   bFiller1   AS BYTE              ' char
   JET_LOGTIME_UNION_STRUCT
END UNION

' // Size = 8 bytes
TYPE JET_LOGTIME BYTE
   bSeconds AS BYTE   ' char //   0 - 60
   bMinutes AS BYTE   ' char //   0 - 60
   bHours   AS BYTE   ' char //   0 - 24
   bDay     AS BYTE   ' char //   1 - 31
   bMonth   AS BYTE   ' char //   0 - 11
   bYear    AS BYTE   ' char //   current year - 1900
   JET_LOGTIME_UNION
   bFiller2 AS BYTE   ' char
END TYPE

#IF %JET_VERSION >= &H0600
'// the JET_BKLOGTIME is an extention of JET_LOGTIME to be used
'// in the JET_BKINFO structure. They should have the same size for
'// compatibility reasons
'typedef struct   {
'   char      bSeconds;            //   0 - 59
'   char      bMinutes;            //   0 - 59
'   char      bHours;              //   0 - 23
'   char      bDay;                //   1 - 31
'   char      bMonth;              //   1 - 12
'   char      bYear;               //   current year - 1900
'   union
'      {
'      char      bFiller1;
'      struct
'         {
'         unsigned char fTimeIsUTC:1;
'         unsigned char fUnused:7;
'         };
'      };
'   union
'      {
'      char      bFiller2;
'      struct
'         {
'         unsigned char fOSSnapshot:1;
'         unsigned char fReserved:7;
'         };
'      };
'   } JET_BKLOGTIME;

' // Size = 1 byte
TYPE JET_BKLOGTIME_UNION_STRUCT_1 BYTE
   fTimeIsUTC AS BIT * 1 IN BYTE
   fUnused    AS BIT * 7
END TYPE

' // Size = 1 byte
TYPE JET_BKLOGTIME_UNION_STRUCT_2 BYTE
   fOSSnapshot AS BIT * 1 IN BYTE
   fReserved   AS BIT * 7
END TYPE

' // Size = 1 byte
UNION JET_BKLOGTIME_UNION_1 BYTE
   bFiller1 AS BYTE
   JET_BKLOGTIME_UNION_STRUCT_1
END UNION

' // Size = 1 byte
UNION JET_BKLOGTIME_UNION_2 BYTE
   bFiller2 AS BYTE
   JET_BKLOGTIME_UNION_STRUCT_2
END UNION

' // Size = 8 bytes
TYPE JET_BKLOGTIME BYTE
   bSeconds AS BYTE   ' char //   0 - 60
   bMinutes AS BYTE   ' char //   0 - 60
   bHours   AS BYTE   ' char //   0 - 24
   bDay     AS BYTE   ' char //   1 - 31
   bMonth   AS BYTE   ' char //   0 - 11
   bYear    AS BYTE   ' char //   current year - 1900
   JET_BKLOGTIME_UNION_1
   JET_BKLOGTIME_UNION_2
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0600

' // Size = 8 bytes
TYPE JET_LGPOS BYTE
   ib          AS WORD   ' unsigned short // must be the last so that lgpos can
   isec        AS WORD   ' unsigned short // index of disksec starting logsec
   lGeneration AS LONG   ' long           // generation of logsec
END TYPE                 '                // be casted to TIME.

' // Size = 28 bytes
TYPE JET_SIGNATURE BYTE
   ulRandom       AS DWORD         ' unsigned long // a random number
   logtimeCreate  AS JET_LOGTIME   ' JET_LOGTIME   // time db created, in logtime format
   szComputerName AS ASCIIZ * %JET_MAX_COMPUTERNAME_LENGTH + 1  ' char // where db is created
END TYPE

' // Size = 8 bytes
UNION JET_BKINFO_UNION BYTE
   logtimeMark   AS JET_LOGTIME
#IF %JET_VERSION >= &H0600
   bklogtimeMark AS JET_BKLOGTIME
#ENDIF   ' // JET_VERSION >= 0x0600
END UNION

' // Size = 24 bytes
TYPE JET_BKINFO BYTE
   lgposMark   AS JET_LGPOS     ' JET_LGPOS //   id for this backup
   JET_BKINFO_UNION
   genLow      AS DWORD         ' unsigned long
   genHigh     AS DWORD         ' unsigned long
END TYPE

'#include <poppack.h>

' // Size = 216 bytes
TYPE JET_DBINFOMISC DWORD
   ulVersion          AS DWORD           ' unsigned long // version of DAE the db created (see ulDAEVersion)
   ulUpdate           AS DWORD           ' unsigned long // used to track incremental database format updates that
                                         '               // are backward-compatible (see ulDAEUpdate)
   signDb             AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) signature of the db (incl. creation time).
   dbstate            AS DWORD           ' unsigned long // consistent/inconsistent state
   lgposConsistent    AS JET_LGPOS       ' JET_LGPOS     // null if in inconsistent state
   logtimeConsistent  AS JET_LOGTIME     ' JET_LOGTIME   // null if in inconsistent state
   logtimeAttach      AS JET_LOGTIME     ' JET_LOGTIME   // Last attach time.
   lgposAttach        AS JET_LGPOS       ' JET_LGPOS
   logtimeDetach      AS JET_LOGTIME     ' JET_LOGTIME   // Last detach time.
   lgposDetach        AS JET_LGPOS       ' JET_LGPOS
   signLog            AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) log signature for this attachments
   bkinfoFullPrev     AS JET_BKINFO      ' JET_BKINFO    // Last successful full backup.
   bkinfoIncPrev      AS JET_BKINFO      ' JET_BKINFO    // Last successful Incremental backup.
                                         '               // Reset when bkinfoFullPrev is set
   bkinfoFullCur      AS JET_BKINFO      ' JET_BKINFO    // current backup. Succeed if a
                                         '               // corresponding pat file generated.
   fShadowingDisabled AS DWORD           ' unsigned long
   fUpgradeDb         AS DWORD           ' unsigned long
'   // NT version information. This is needed to decide if an index need
'   // be recreated due to sort table changes.
   dwMajorVersion     AS DWORD           ' unsigned long /* OS version info                        */
   dwMinorVersion     AS DWORD           ' unsigned long
   dwBuildNumber      AS DWORD           ' unsigned long
   lSPNumber          AS LONG            ' long
   cbPageSize         AS DWORD           ' unsigned long // database page size (0 = 4k pages)
END TYPE

#IF %JET_VERSION >= &H0600
' // Size = 296 bytes
TYPE JET_DBINFOMISC2 DWORD
   ulVersion            AS DWORD           ' unsigned long // version of DAE the db created (see ulDAEVersion)
   ulUpdate             AS DWORD           ' unsigned long // used to track incremental database format updates that
                                           '               // are backward-compatible (see ulDAEUpdate)
   signDb               AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) signature of the db (incl. creation time).
   dbstate              AS DWORD           ' unsigned long // consistent/inconsistent state
   lgposConsistent      AS JET_LGPOS       ' JET_LGPOS     // null if in inconsistent state
   logtimeConsistent    AS JET_LOGTIME     ' JET_LOGTIME   // null if in inconsistent state
   logtimeAttach        AS JET_LOGTIME     ' JET_LOGTIME   // Last attach time.
   lgposAttach          AS JET_LGPOS       ' JET_LGPOS
   logtimeDetach        AS JET_LOGTIME     ' JET_LOGTIME   // Last detach time.
   lgposDetach          AS JET_LGPOS       ' JET_LGPOS
   signLog              AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) log signature for this attachments
   bkinfoFullPrev       AS JET_BKINFO      ' JET_BKINFO    // Last successful full backup.
   bkinfoIncPrev        AS JET_BKINFO      ' JET_BKINFO    // Last successful Incremental backup.
                                           '               // Reset when bkinfoFullPrev is set
   bkinfoFullCur        AS JET_BKINFO      ' JET_BKINFO    // current backup. Succeed if a
                                           '               // corresponding pat file generated.
   fShadowingDisabled   AS DWORD           ' unsigned long
   fUpgradeDb           AS DWORD           ' unsigned long
'   // NT version information. This is needed to decide if an index need
'   // be recreated due to sort table changes.
   dwMajorVersion       AS DWORD           ' unsigned long /* OS version info                        */
   dwMinorVersion       AS DWORD           ' unsigned long
   dwBuildNumber        AS DWORD           ' unsigned long
   lSPNumber            AS LONG            ' long
   cbPageSize           AS DWORD           ' unsigned long // database page size (0 = 4k pages)

   ' // new fields added on top of the above JET_DBINFOMISC
   genMinRequired       AS DWORD           ' unsigned long //   the minimum log generation required for replaying the logs. Typically the checkpoint generation
   genMaxRequired       AS DWORD           ' unsigned long //   the maximum log generation required for replaying the logs.
   logtimeGenMaxCreate  AS JET_LOGTIME     '               //   creation time of the genMax log file
   ulRepairCount        AS DWORD           ' unsigned long //   number of times repair has been called on this database
   logtimeRepair        AS JET_LOGTIME     '               //   the date of the last time that repair was run
   ulRepairCountOld     AS DWORD           ' unsigned long //   number of times ErrREPAIRAttachForRepair has been called on this database before the last defrag
   ulECCFixSuccess      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page
   logtimeECCFixSuccess AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a good page
   ulECCFixSuccessOld   AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page before last repair
   ulECCFixFail         AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page
   logtimeECCFixFail    AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a bad page
   ulECCFixFailOld      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page before last repair
   ulBadChecksum        AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found
   logtimeBadChecksum   AS JET_LOGTIME     '               //   the date of the last time that a non-correctable ECC/checksum error was found
   ulBadChecksumOld     AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found before last repair
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601
' // Size = 300 bytes
TYPE JET_DBINFOMISC3 DWORD
   ulVersion            AS DWORD           ' unsigned long // version of DAE the db created (see ulDAEVersion)
   ulUpdate             AS DWORD           ' unsigned long // used to track incremental database format updates that
                                           '               // are backward-compatible (see ulDAEUpdate)
   signDb               AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) signature of the db (incl. creation time).
   dbstate              AS DWORD           ' unsigned long // consistent/inconsistent state
   lgposConsistent      AS JET_LGPOS       ' JET_LGPOS     // null if in inconsistent state
   logtimeConsistent    AS JET_LOGTIME     ' JET_LOGTIME   // null if in inconsistent state
   logtimeAttach        AS JET_LOGTIME     ' JET_LOGTIME   // Last attach time.
   lgposAttach          AS JET_LGPOS       ' JET_LGPOS
   logtimeDetach        AS JET_LOGTIME     ' JET_LOGTIME   // Last detach time.
   lgposDetach          AS JET_LGPOS       ' JET_LGPOS
   signLog              AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) log signature for this attachments
   bkinfoFullPrev       AS JET_BKINFO      ' JET_BKINFO    // Last successful full backup.
   bkinfoIncPrev        AS JET_BKINFO      ' JET_BKINFO    // Last successful Incremental backup.
                                           '               // Reset when bkinfoFullPrev is set
   bkinfoFullCur        AS JET_BKINFO      ' JET_BKINFO    // current backup. Succeed if a
                                           '               // corresponding pat file generated.
   fShadowingDisabled   AS DWORD           ' unsigned long
   fUpgradeDb           AS DWORD           ' unsigned long
'   // NT version information. This is needed to decide if an index need
'   // be recreated due to sort table changes.
   dwMajorVersion       AS DWORD           ' unsigned long /* OS version info                        */
   dwMinorVersion       AS DWORD           ' unsigned long
   dwBuildNumber        AS DWORD           ' unsigned long
   lSPNumber            AS LONG            ' long
   cbPageSize           AS DWORD           ' unsigned long // database page size (0 = 4k pages)

   ' // new fields added on top of the above JET_DBINFOMISC
   genMinRequired       AS DWORD           ' unsigned long //   the minimum log generation required for replaying the logs. Typically the checkpoint generation
   genMaxRequired       AS DWORD           ' unsigned long //   the maximum log generation required for replaying the logs.
   logtimeGenMaxCreate  AS JET_LOGTIME     '               //   creation time of the genMax log file
   ulRepairCount        AS DWORD           ' unsigned long //   number of times repair has been called on this database
   logtimeRepair        AS JET_LOGTIME     '               //   the date of the last time that repair was run
   ulRepairCountOld     AS DWORD           ' unsigned long //   number of times ErrREPAIRAttachForRepair has been called on this database before the last defrag
   ulECCFixSuccess      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page
   logtimeECCFixSuccess AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a good page
   ulECCFixSuccessOld   AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page before last repair
   ulECCFixFail         AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page
   logtimeECCFixFail    AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a bad page
   ulECCFixFailOld      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page before last repair
   ulBadChecksum        AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found
   logtimeBadChecksum   AS JET_LOGTIME     '               //   the date of the last time that a non-correctable ECC/checksum error was found
   ulBadChecksumOld     AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found before last repair
   ' // new fields added on top of the above JET_DBINFOMISC2
   genCommitted         AS DWORD   ' unsigned long //   the maximum log generation committed to the database. Typically the current log generation
END TYPE

' // Size = 348 bytes
TYPE JET_DBINFOMISC4 DWORD
   ulVersion            AS DWORD           ' unsigned long // version of DAE the db created (see ulDAEVersion)
   ulUpdate             AS DWORD           ' unsigned long // used to track incremental database format updates that
                                           '               // are backward-compatible (see ulDAEUpdate)
   signDb               AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) signature of the db (incl. creation time).
   dbstate              AS DWORD           ' unsigned long // consistent/inconsistent state
   lgposConsistent      AS JET_LGPOS       ' JET_LGPOS     // null if in inconsistent state
   logtimeConsistent    AS JET_LOGTIME     ' JET_LOGTIME   // null if in inconsistent state
   logtimeAttach        AS JET_LOGTIME     ' JET_LOGTIME   // Last attach time.
   lgposAttach          AS JET_LGPOS       ' JET_LGPOS
   logtimeDetach        AS JET_LOGTIME     ' JET_LOGTIME   // Last detach time.
   lgposDetach          AS JET_LGPOS       ' JET_LGPOS
   signLog              AS JET_SIGNATURE   ' JET_SIGNATURE // (28 bytes) log signature for this attachments
   bkinfoFullPrev       AS JET_BKINFO      ' JET_BKINFO    // Last successful full backup.
   bkinfoIncPrev        AS JET_BKINFO      ' JET_BKINFO    // Last successful Incremental backup.
                                           '               // Reset when bkinfoFullPrev is set
   bkinfoFullCur        AS JET_BKINFO      ' JET_BKINFO    // current backup. Succeed if a
                                           '               // corresponding pat file generated.
   fShadowingDisabled   AS DWORD           ' unsigned long
   fUpgradeDb           AS DWORD           ' unsigned long
'   // NT version information. This is needed to decide if an index need
'   // be recreated due to sort table changes.
   dwMajorVersion       AS DWORD           ' unsigned long /* OS version info                        */
   dwMinorVersion       AS DWORD           ' unsigned long
   dwBuildNumber        AS DWORD           ' unsigned long
   lSPNumber            AS LONG            ' long
   cbPageSize           AS DWORD           ' unsigned long // database page size (0 = 4k pages)

   ' // new fields added on top of the above JET_DBINFOMISC
   genMinRequired       AS DWORD           ' unsigned long //   the minimum log generation required for replaying the logs. Typically the checkpoint generation
   genMaxRequired       AS DWORD           ' unsigned long //   the maximum log generation required for replaying the logs.
   logtimeGenMaxCreate  AS JET_LOGTIME     '               //   creation time of the genMax log file
   ulRepairCount        AS DWORD           ' unsigned long //   number of times repair has been called on this database
   logtimeRepair        AS JET_LOGTIME     '               //   the date of the last time that repair was run
   ulRepairCountOld     AS DWORD           ' unsigned long //   number of times ErrREPAIRAttachForRepair has been called on this database before the last defrag
   ulECCFixSuccess      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page
   logtimeECCFixSuccess AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a good page
   ulECCFixSuccessOld   AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a good page before last repair
   ulECCFixFail         AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page
   logtimeECCFixFail    AS JET_LOGTIME     '               //   the date of the last time that a one bit error was fixed and resulted in a bad page
   ulECCFixFailOld      AS DWORD           ' unsigned long //   number of times a one bit error was fixed and resulted in a bad page before last repair
   ulBadChecksum        AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found
   logtimeBadChecksum   AS JET_LOGTIME     '               //   the date of the last time that a non-correctable ECC/checksum error was found
   ulBadChecksumOld     AS DWORD           ' unsigned long //   number of times a non-correctable ECC/checksum error was found before last repair
   ' // new fields added on top of the above JET_DBINFOMISC2
   genCommitted         AS DWORD   ' unsigned long //   the maximum log generation committed to the database. Typically the current log generation
   ' // new fields added on top of the above JET_DBINFOMISC3
   bkinfoCopyPrev       AS JET_BKINFO      ' //   Last successful Copy backup
   bkinfoDiffPrev       AS JET_BKINFO      ' //   Last successful Differential backup, reset when bkinfoFullPrev is set
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0601

#IF %JET_VERSION >= &H0600
'//  JET performance counters accumulated by thread
'//
' // Size = 32 bytes
TYPE JET_THREADSTATS DWORD
   cbStruct        AS DWORD   ' unsigned long //  size of this struct
   cPageReferenced AS DWORD   ' unsigned long //  pages referenced
   cPageRead       AS DWORD   ' unsigned long //  pages read from disk
   cPagePreread    AS DWORD   ' unsigned long //  pages preread from disk
   cPageDirtied    AS DWORD   ' unsigned long //  clean pages modified
   cPageRedirtied  AS DWORD   ' unsigned long //  dirty pages modified
   cLogRecord      AS DWORD   ' unsigned long //  log records generated
   cbLogRecord     AS DWORD   ' unsigned long //  log record bytes generated
END TYPE

' // Size = 32 bytes
TYPE JET_RSTINFO_A DWORD
   cbStruct    AS DWORD              ' unsigned long
   rgrstmap    AS JET_RSTMAP_A PTR   ' JET_RSTMAP_A *
   crstmap     AS LONG               ' long
   lgposStop   AS JET_LGPOS
   logtimeStop AS JET_LOGTIME
   pfnStatus   AS DWORD              ' JET_PFNSTATUS
END TYPE

' // Size = 32 bytes
TYPE JET_RSTINFO_W DWORD
   cbStruct    AS DWORD              ' unsigned long
   rgrstmap    AS JET_RSTMAP_W PTR   ' JET_RSTMAP_W *
   crstmap     AS LONG               ' long
   lgposStop   AS JET_LGPOS
   logtimeStop AS JET_LOGTIME
   pfnStatus   AS DWORD              ' JET_PFNSTATUS
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_RSTINFO = JET_RSTINFO_W
#ELSE
   MACRO JET_RSTINFO = JET_RSTINFO_A
#ENDIF

#ENDIF   ' // JET_VERSION >= 0x0600

'/************************************************************************/
'/*************************     JET CONSTANTS    ************************/
'/************************************************************************/

#IF %JET_VERSION >= &H0501
'#define JET_instanceNil          (~(JET_INSTANCE)0)
%JET_instanceNil            = &HFFFFFFFF???
#ENDIF  ' // JET_VERSION >= 0x0501
'#define JET_sesidNil             (~(JET_SESID)0)
'#define JET_tableidNil           (~(JET_TABLEID)0)
'#define JET_bitNil               ((JET_GRBIT)0)
%JET_sesidNil               = &HFFFFFFFF???
%JET_tableidNil             = &HFFFFFFFF???
%JET_bitNil                 = 0

'   /* Max size of a bookmark */

%JET_cbBookmarkMost = 256
' Moved below because PB doesn't allow forward referencing of equates
'#if ( JET_VERSION >= 0x0601 )
'#define JET_cbBookmarkMostMost      JET_cbKeyMostMost
'#endif // JET_VERSION >= 0x0601

'   /* Max length of a object/column/index/property name */

#IF NOT %DEF(%JET_UNICODE)
    %JET_cbNameMost = 64
#ELSE
    %JET_cbNameMost = 128
#ENDIF

'   /* Max length of a "name.name.name..." construct */


#IF NOT %DEF(%JET_UNICODE)
    %JET_cbFullNameMost = 255
#ELSE
    %JET_cbFullNameMost = 510
#ENDIF

'   /* Max size of long-value (LongBinary or LongText) column chunk */

'//   #define JET_cbColumnLVChunkMost      ( JET_cbPage - 82 ) to the following:
'//   Get cbPage from GetSystemParameter.
'//    changed JET_cbColumnLVChunkMost reference to cbPage - JET_cbColumnLVPageOverhead

%JET_cbColumnLVPageOverhead = 82   ' // ONLY for small (<=8kiB) page, otherwise, query JET_paramLVChunkSizeMost

'   /* Max size of long-value (LongBinary or LongText) column default value */

%JET_cbLVDefaultValueMost = 255

'   /* Max size of non-long-value column data */

%JET_cbColumnMost = 255

'   /* Max size of a sort/index key */

' Moved below because PB doesn't allow forward referencing of equates
'#if ( JET_VERSION >= 0x0601 )
'#define JET_cbKeyMostMost            JET_cbKeyMost32KBytePage
'#define JET_cbKeyMost32KBytePage      JET_cbKeyMost8KBytePage
'#define JET_cbKeyMost16KBytePage      JET_cbKeyMost8KBytePage
'#endif // JET_VERSION >= 0x0601

#IF %JET_VERSION >= &H0600
%JET_cbKeyMost8KBytePage = 2000
%JET_cbKeyMost4KBytePage = 1000
%JET_cbKeyMost2KBytePage = 500
%JET_cbKeyMostMin        = 255
#ENDIF   ' // JET_VERSION >= 0x0600

' Moved from above
#IF %JET_VERSION >= &H0601
%JET_cbKeyMost32KBytePage = %JET_cbKeyMost8KBytePage
%JET_cbKeyMostMost        = %JET_cbKeyMost32KBytePage
%JET_cbKeyMost16KBytePage = %JET_cbKeyMost8KBytePage
#ENDIF   ' // JET_VERSION >= 0x0601

' Moved from above
#IF %JET_VERSION >= &H0601
%JET_cbBookmarkMostMost = %JET_cbKeyMostMost
#ENDIF   ' // JET_VERSION >= 0x0601

%JET_cbKeyMost          = 255
%JET_cbLimitKeyMost     = 256           ' //   maximum key size when key is formed using a Limit grbit (eg. JET_bitStrLimit)
%JET_cbPrimaryKeyMost   = 255
%JET_cbSecondaryKeyMost = 255

'   /* Max number of components in a sort/index key */

#IF %JET_VERSION >= &H0600
    %JET_ccolKeyMost = 16
#ELSE   ' // !JET_VERSION >= 0x0600
    %JET_ccolKeyMost = 12
#ENDIF   ' // !JET_VERSION >= 0x0600

'//   maximum number of columns
#IF %JET_VERSION >= &H0501
%JET_ccolMost            = &H0000fee0
#ELSE
%JET_ccolMost            = &H00007ffe
#ENDIF ' // !JET_VERSION >= 0x0501
%JET_ccolFixedMost       = &H0000007f
%JET_ccolVarMost         = &H00000080
%JET_ccolTaggedMost      = (%JET_ccolMost - &H000000ff)

#IF %JET_VERSION >= &H0501
'//  event logging level (only on and off for now - will add more in the future)
%JET_EventLoggingDisable    =  0
#IF %JET_VERSION >= &H0601
%JET_EventLoggingLevelMin    = 1
%JET_EventLoggingLevelLow    = 25
%JET_EventLoggingLevelMedium = 50
%JET_EventLoggingLevelHigh   = 75
#ENDIF   ' // JET_VERSION >= 0x0601
%JET_EventLoggingLevelMax   = 100
#ENDIF  ' // JET_VERSION >= 0x0501

'//   system paramters
'//
'//   location parameters
'//
%JET_paramSystemPath                  = 0   ' //   path to check point file [".\\"]
%JET_paramTempPath                    = 1   ' //   path to the temporary database [".\\"]
%JET_paramLogFilePath                 = 2   ' //   path to the log file directory [".\\"]
%JET_paramBaseName                    = 3   ' //   base name for all DBMS object names ["edb"]
%JET_paramEventSource                 = 4   ' //   language independent process descriptor string [""]

'//   performance parameters
'//
%JET_paramMaxSessions                 = 5   ' //   maximum number of sessions [16]
%JET_paramMaxOpenTables               = 6   ' //   maximum number of open directories [300]
                                            ' //     need 1 for each open table index,
                                            ' //     plus 1 for each open table with no indexes,
                                            ' //     plus 1 for each table with long column data,
                                            ' //     plus a few more.
                                            ' //      for 4.1, 1/3 for regular table, 2/3 for index
%JET_paramPreferredMaxOpenTables      = 7   ' //   preferred maximum number of open directories [300]
#IF %JET_VERSION >= &H0600
%JET_paramCachedClosedTables          = 125 ' //   number of closed tables to cache the meta-data for
#ENDIF   ' // JET_VERSION >= 0x0600
%JET_paramMaxCursors                  = 8   ' //   maximum number of open cursors [1024]
%JET_paramMaxVerPages                 = 9   ' //   maximum version store size in 16kByte units [64]
%JET_paramPreferredVerPages           = 63  ' //   preferred version store size in 16kByte units [64 * 0.9]
#IF %JET_VERSION >= &H0501
%JET_paramGlobalMinVerPages           = 81  ' //   minimum version store size for all instances in 16kByte units [64]
%JET_paramVersionStoreTaskQueueMax    = 105 ' //   maximum number of tasks in the task queue before start dropping the tasks [32]
#ENDIF ' // JET_VERSION >= 0x0501
%JET_paramMaxTemporaryTables          = 10  ' //   maximum concurrent open temporary table/index creation [20]
%JET_paramLogFileSize                 = 11  ' //   log file size in kBytes [5120]
%JET_paramLogBuffers                  = 12  ' //   log buffers in 512 bytes [80]
%JET_paramWaitLogFlush                = 13  ' //   log flush wait time in milliseconds [0] DEFUNCT
%JET_paramLogCheckpointPeriod         = 14  ' //   checkpoint period in 512 bytes [1024] DEFUNCT
%JET_paramLogWaitingUserMax           = 15  ' //   maximum sessions waiting log flush [3] DEFUNCT
%JET_paramCommitDefault               = 16  ' //   default grbit for JetCommitTransaction [0]
%JET_paramCircularLog                 = 17  ' //   boolean flag for circular logging [0]
%JET_paramDbExtensionSize             = 18  ' //   database extension size in pages [256] DEFUNCT
%JET_paramPageTempDBMin               = 19  ' //   minimum size temporary database in pages [0] DEFUNCT
%JET_paramPageFragment                = 20  ' //   maximum disk extent considered fragment in pages [8] DEFUNCT
#IF %JET_VERSION >= &H0600
%JET_paramEnableFileCache             = 126 ' //  enable the use of the OS file cache for all managed files
%JET_paramVerPageSize                 = 128 ' //  the version store page size
%JET_paramConfiguration               = 129 ' //  RESETs all parameters to their default for a given configuration
%JET_paramEnableAdvanced              = 130 ' //  enables the modification of advanced settings
%JET_paramMaxColtyp                   = 131 ' //   maximum coltyp supported by this version of ESE
#ENDIF   ' // JET_VERSION >= 0x0600

'//  cache performance parameters
'//
%JET_paramBatchIOBufferMax            = 22  ' //   maximum batch I/O buffers in pages [64] DEFUNCT
%JET_paramCacheSize                   = 41  ' //   current cache size in pages [512]
%JET_paramCacheSizeMin                = 60  ' //   minimum cache size in pages [64]
%JET_paramCacheSizeMax                = 23  ' //   maximum cache size in pages [512]
%JET_paramCheckpointDepthMax          = 24  ' //   maximum checkpoint depth in bytes [20MB]
%JET_paramLRUKCorrInterval            = 25  ' //   time (usec) under which page accesses are correlated [128000], it was 10000
%JET_paramLRUKHistoryMax              = 26  ' //   maximum LRUK history records [1024] (proportional to cache size max) DEFUNCT
%JET_paramLRUKPolicy                  = 27  ' //   K-ness of LRUK page eviction algorithm (1...2) [2]
%JET_paramLRUKTimeout                 = 28  ' //   time (sec) after which cached pages are always evictable [100]
%JET_paramLRUKTrxCorrInterval         = 29  ' //   Not Used: time (usec) under which page accesses by the same transaction are correlated [5000000] DEFUNCT
%JET_paramOutstandingIOMax            = 30  ' //   maximum outstanding I/Os [64] DEFUNCT
%JET_paramStartFlushThreshold         = 31  ' //   evictable pages at which to start a flush [100] (proportional to CacheSizeMax)
%JET_paramStopFlushThreshold          = 32  ' //   evictable pages at which to stop a flush [400] (proportional to CacheSizeMax)
#IF %JET_VERSION >= &H0600
%JET_paramEnableViewCache             = 127 ' //  enable the use of memory mapped file I/O for database files
%JET_paramCheckpointIOMax             = 135 ' //  maxiumum number of pending flush writes
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0600
'// TableClass names
%JET_paramTableClass1Name  = 137   ' // name of tableclass1
%JET_paramTableClass2Name  = 138   ' // name of tableclass2
%JET_paramTableClass3Name  = 139   ' // name of tableclass3
%JET_paramTableClass4Name  = 140   ' // name of tableclass4
%JET_paramTableClass5Name  = 141   ' // name of tableclass5
%JET_paramTableClass6Name  = 142   ' // name of tableclass6
%JET_paramTableClass7Name  = 143   ' // name of tableclass7
%JET_paramTableClass8Name  = 144   ' // name of tableclass8
%JET_paramTableClass9Name  = 145   ' // name of tableclass9
%JET_paramTableClass10Name = 146   ' // name of tableclass10
%JET_paramTableClass11Name = 147   ' // name of tableclass11
%JET_paramTableClass12Name = 148   ' // name of tableclass12
%JET_paramTableClass13Name = 149   ' // name of tableclass13
%JET_paramTableClass14Name = 150   ' // name of tableclass14
%JET_paramTableClass15Name = 151   ' // name of tableclass15
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0600
'// Values for JET_paramIOPriority
%JET_IOPriorityNormal                 = 0   ' // default
%JET_IOPriorityLow                    = 1
%JET_paramIOPriority                  = 152 ' //   adjust IO priority per instance, anytime. Mainly for background recovery
                                            ' //  Doesn't affect pending IOs, just subsequent ones
#ENDIF   ' // JET_VERSION >= 0x0600

'//   debug only parameters
'//
%JET_paramRecovery                    = 34  ' //   enable recovery [-1]
%JET_paramEnableOnlineDefrag          = 35  ' //   enable online defrag [TRUE by default]

'//   Application specific parameter
'//
%JET_paramCheckFormatWhenOpenFail     = 44  ' //   JetInit may return JET_errDatabaseXXXformat instead of database corrupt when it is set
%JET_paramEnableTempTableVersioning   = 46  ' //   Enable versioning of temp tables (TRUE by default)
%JET_paramIgnoreLogVersion            = 47  ' //   Do not check the log version
%JET_paramDeleteOldLogs               = 48  ' //   Delete the log files if the version is old, after deleting may make database non-recoverable
%JET_paramEventSourceKey              = 49  ' //   Event source registration key value
%JET_paramNoInformationEvent          = 50  ' //   Disable logging information event [ FALSE by default ]
#IF %JET_VERSION >= &H0501
%JET_paramEventLoggingLevel           = 51  ' //   Set the type of information that goes to event log [ eventLoggingLevelMax by default ]
%JET_paramDeleteOutOfRangeLogs        = 52  ' //   Delete the log files that are not matching (generation wise) during soft recovery [false]
%JET_paramAccessDeniedRetryPeriod     = 53  ' //   Number of milliseconds to retry when about to fail with AccessDenied [10000 milliseconds]
#ENDIF ' // JET_VERSION >= 0x0501

'//   Index-checking parameters
'//
'//   Different versions of windows normalize unicode text in different ways. That means indexes built under one version of Windows may
'//   not work on other versions. Windows Server 2003 Beta 3 introduced GetNLSVersion() which can be used to determine the version of unicode normalization
'//   that the OS currently provides. Indexes built in server 2003 are flagged with the version of unicode normalization that they were
'//   built with (older indexes have no version information). Most unicode normalization changes consist of adding new characters -- codepoints
'//   which were previously undefined are defined and normalize differently. Thus, if binary data is stored in a unicode column it will normalize
'//   differently as new codepoints are defined.
'//
'//   As of Windows Server 2003 RC1 ESENT tracks unicode index entries that contain undefined codepoints. These can be used to fixup an index when the
'//   set of defined unicode characters changes.
'//
'//   These parameters control what happens when ESENT attaches to a database that was last used under a different build of the OS (the OS version
'//   is stamped in the database header).
'//
'//   If JET_paramEnableIndexChecking is TRUE JetAttachDatabase() will delete indexes if JET_bitDbDeleteCorruptIndexes or return an error if
'//   the grbit was not specified and there are indexes which need deletion. If it is set to FALSE then JetAttachDatabase() will succeed, even
'//   if there are potentially corrupt indexes.
'//
'//   If JET_paramEnableIndexCleanup is set, the internal fixup table will be used to fixup index entries. This may not fixup all index corruptions
'//   but will be transparent to the application.
'//

%JET_paramEnableIndexChecking       = 45  ' //   Enable checking OS version for indexes (FALSE by default)
#IF %JET_VERSION >= &H0502
%JET_paramEnableIndexCleanup        = 54  ' //   Enable cleanup of out-of-date index entries (TRUE by default)
#ENDIF ' // JET_VERSION >= 0x0502

'//                                    60   //   JET_paramCacheSizeMin defined above
'//                                    63   //   JET_paramPreferredVerPages defined above

%JET_paramDatabasePageSize          = 64  ' //   set database page size
#IF %JET_VERSION >= &H0501
%JET_paramDisableCallbacks          = 65  ' //   turn off callback resolution (for defrag/repair)
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0600
%JET_paramDisablePerfmon            = 107 ' //  disable perfmon support for this process
#ENDIF   ' // JET_VERSION >= 0x0600
#IF %JET_VERSION >= &H0501
#IF %JET_VERSION >= &H0600
%JET_paramEnablePersistedCallbacks  = 156 ' //  allow the database engine to resolve and use callbacks persisted in a database
#ENDIF   ' // JET_VERSION >= 0x0600

'//  Backup performance parameters
'//
%JET_paramBackupChunkSize           = 66  ' //   backup read size in pages
%JET_paramBackupOutstandingReads    = 67  ' //   backup maximum reads outstanding
%JET_paramSLVProviderEnable         = 68  ' //   Enable SLV Provider
'// begin_PubEsent
%JET_paramLogFileCreateAsynch       = 69  ' //   prepares next log file while logging to the current one to smooth response time [true]
#ENDIF   ' // JET_VERSION >= 0x0501
%JET_paramErrorToString             = 70  ' //   turns a JET_err into a string (taken from the comment in jet.h)
#IF %JET_VERSION >= &H0501
%JET_paramZeroDatabaseDuringBackup  = 71  ' //   Overwrite deleted records/LVs during backup [false]
#ENDIF ' // JET_VERSION >= 0x0501
%JET_paramUnicodeIndexDefault       = 72  ' //   default LCMapString() lcid and flags to use for CreateIndex() and unique multi-values check
                                          ' //      (pass JET_UNICODEINDEX structure for lParam)
#IF %JET_VERSION >= &H0501
%JET_paramRuntimeCallback           = 73  ' //   pointer to runtime-only callback function
#ENDIF ' // JET_VERSION >= 0x0501
%JET_paramCleanupMismatchedLogFiles = 77  ' //   instead of erroring out after a successful recovery with JET_errLogFileSizeMismatchDatabasesConsistent, ESE will silently delete the old log files and checkpoint file and continue operations
#IF %JET_VERSION >= &H0501
%JET_paramRecordUpgradeDirtyLevel   = 78  ' //   how aggresively should pages with their record format converted be flushed (0-3) [1]
'//                                    81   //   JET_paramGlobalMinVerPages defined above
%JET_paramOSSnapshotTimeout         = 82  ' //   timeout for the freeze period in msec [1000 * 20]
#ENDIF ' // JET_VERSION >= 0x0501

%JET_paramExceptionAction           = 98  ' //   what to do with exceptions generated within JET
%JET_paramEventLogCache             = 99  ' //   number of bytes of eventlog records to cache if service is not available [0]
#IF %JET_VERSION >= &H0501
%JET_paramCreatePathIfNotExist      = 100 ' //   create system/temp/log/log-failover paths if they do not exist
%JET_paramPageHintCacheSize         = 101 ' //   maximum size of the fast page latch hint cache in bytes [256kb]
%JET_paramOneDatabasePerSession     = 102 ' //   allow just one open user database per session [false]
%JET_paramMaxInstances              = 104 ' //   maximum number of instances per process [1 for ESENT, 16 for Exchange]

%JET_paramIndexTuplesLengthMin      = 110  ' //   for tuple indexes, minimum length of a tuple [3]
%JET_paramIndexTuplesLengthMax      = 111  ' //   for tuple indexes, maximum length of a tuple [10]
%JET_paramIndexTuplesToIndexMax     = 112  ' //   for tuple indexes, maximum number of characters in a given string to index [32767]
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0502
%JET_paramAlternateDatabaseRecoveryPath = 113  ' //   recovery-only - search for dirty-shutdown databases in specified location only
#ENDIF ' // JET_VERSION  >= 0x0502

#IF %JET_VERSION >= &H0600
%JET_paramIndexTupleIncrement       = 132  ' //   for tuple indexes, offset increment for each succesive tuple
%JET_paramIndexTupleStart           = 133  ' //   for tuple indexes, offset to start tuple indexing
%JET_paramKeyMost                   = 134  ' //   read only maximum settable key length before key trunctation occurs
%JET_paramLegacyFileNames           = 136  ' //   Legacy  file name characteristics to preserve ( JET_bitESE98FileNames | JET_bitEightDotThreeSoftCompat )
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601
%JET_paramWaypointLatency                                 = 153   ' //   The latency (in logs) behind the tip / highest committed log to defer database page flushes.
%JET_paramDefragmentSequentialBTrees                      = 160   ' // Turn on/off automatic sequential B-tree defragmentation
%JET_paramDefragmentSequentialBTreesDensityCheckFrequency = 161   ' // Determine how frequently B-tree density is checked
%JET_paramIOThrottlingTimeQuanta                          = 162   ' // Max time (in MS) that the I/O throttling mechanism gives a task to run for it to be considered 'completed'.
%JET_paramLVChunkSizeMost                                 = 163   ' // Max LV chuck size supported wrt the chosen page size (R/O)
%JET_paramMaxCoalesceReadSize                             = 164   ' // Max number of bytes that can be grouped for a coalesced read operation.
%JET_paramMaxCoalesceWriteSize                            = 165   ' // Max number of bytes that can be grouped for a coalesced write operation.
%JET_paramMaxCoalesceReadGapSize                          = 166   ' // Max number of bytes that can be gapped for a coalesced read IO operation.
%JET_paramMaxCoalesceWriteGapSize                         = 167   ' // Max number of bytes that can be gapped for a coalesced write IO operation.
#ENDIF   ' // JET_VERSION >= 0x0601

#IF %JET_VERSION >= &H0600
'   /* Flags for JET_paramLegacyFileNames */
%JET_bitESE98FileNames           = &H00000001???  ' //   Preserve the .log and .chk extension for compatibility reasons (i.e. Exchange)
%JET_bitEightDotThreeSoftCompat  = &H00000002???  ' //   Preserve the 8.3 naming syntax for as long as possible. (this should not be changed, w/o ensuring there are no log files)
#ENDIF   ' // JET_VERSION >= 0x0600

'   /* Flags for JetInit2, JetInit3 */

#IF %JET_VERSION >= &H0501
'// IGNORE_MISSING_ATTACH, ignoring hanging asserts for missing databases during recovery
%JET_bitReplayIgnoreMissingDB      = &H00000004???  ' /* ignore missing databases */
#ENDIF ' // JET_VERSION >= 0x0501
' // Note: Although esent.h specifies JET_VERSION >= &H0600, the equates below must be available to other versions.
'#IF %JET_VERSION >= &H0600
%JET_bitRecoveryWithoutUndo        = &H00000008???  ' //   perform recovery, but halt at the Undo phase
%JET_bitTruncateLogsAfterRecovery  = &H00000010???  ' //   on successful soft recovery, truncate log files
%JET_bitReplayMissingMapEntryDB    = &H00000020???  ' /* missing database map entry default to same location */
%JET_bitLogStreamMustExist         = &H00000040???  ' //   transaction logs must exist in the logfile directory (ie. cannot auto-start a new log stream)
'#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601
%JET_bitReplayIgnoreLostLogs       = &H00000080???   ' //   ignore logs lost from the end of the log stream
#ENDIF   ' // JET_VERSION >= 0x0601

   ' /* Flags for JetTerm2 */

%JET_bitTermComplete     = &H00000001???
%JET_bitTermAbrupt       = &H00000002???
%JET_bitTermStopBackup   = &H00000004???
#IF %JET_VERSION >= &H0601
%JET_bitTermDirty        = &H00000008???
#ENDIF   ' // JET_VERSION >= 0x0601

   ' /* Flags for JetIdle */

%JET_bitIdleFlushBuffers = &H00000001???
%JET_bitIdleCompact      = &H00000002???
%JET_bitIdleStatus       = &H00000004???

   ' /* Flags for JetEndSession */


   ' /* Flags for JetAttach/OpenDatabase */

%JET_bitDbReadOnly              = &H00000001???
%JET_bitDbExclusive             = &H00000002??? ' /* multiple opens allowed */
%JET_bitDbDeleteCorruptIndexes  = &H00000010??? ' /* delete indexes possibly corrupted by NT version upgrade */
#IF %JET_VERSION >= &H0502
%JET_bitDbDeleteUnicodeIndexes  = &H00000400??? ' /* delete all indexes with unicode columns */
#ENDIF ' // JET_VERSION >= &H0502
#IF %JET_VERSION >= &H0501
%JET_bitDbUpgrade               = &H00000200??? ' /* */
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JetDetachDatabase2 */

#IF %JET_VERSION >= &H0501
%JET_bitForceDetach                 = &H00000001???
%JET_bitForceCloseAndDetach         = (&H00000002??? OR %JET_bitForceDetach)
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JetCreateDatabase */

%JET_bitDbRecoveryOff            = &H00000008??? ' /* disable logging/recovery for this database */
%JET_bitDbShadowingOff           = &H00000080??? ' /* disable catalog shadowing */
#IF %JET_VERSION >= &H0501
%JET_bitDbOverwriteExisting      = &H00000200??? ' /* overwrite existing database with same name */
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JetBackup, JetBeginExternalBackup, JetBeginExternalBackupInstance, JetBeginSurrogateBackup */

%JET_bitBackupIncremental        = &H00000001???
%JET_bitBackupAtomic             = &H00000004???
#IF %JET_VERSION >= &H0501
%JET_bitBackupSnapshot           = &H00000010???
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JetEndExternalBackupInstance2, JetEndSurrogateBackup */

'/* Flags for JetEndExternalBackupInstance2 */
%JET_bitBackupEndNormal     = &H0001
%JET_bitBackupEndAbort      = &H0002
#IF %JET_VERSION >= &H0600
%JET_bitBackupTruncateDone  = &H0100
#ENDIF   ' // JET_VERSION >= 0x0600

   ' /* Database types */

%JET_dbidNil                     = &HFFFFFFFF???

   ' /* Flags for JetCreateTableColumnIndex */
%JET_bitTableCreateFixedDDL         = &H00000001???   ' /* DDL is fixed */
%JET_bitTableCreateTemplateTable    = &H00000002???   ' /* DDL is inheritable (implies FixedDDL) */
#IF %JET_VERSION >= &H0501
%JET_bitTableCreateNoFixedVarColumnsInDerivedTables   = &H00000004???
                                         ' //   used in conjunction with JET_bitTableCreateTemplateTable
                                         ' //   to disallow fixed/var columns in derived tables (so that
                                         ' //   fixed/var columns may be added to the template in the future)
#ENDIF ' // JET_VERSION >= 0x0501


   ' /* Flags for JetAddColumn, JetGetColumnInfo, JetOpenTempTable */

%JET_bitColumnFixed         = &H00000001???
%JET_bitColumnTagged        = &H00000002???
%JET_bitColumnNotNULL       = &H00000004???
%JET_bitColumnVersion       = &H00000008???
%JET_bitColumnAutoincrement = &H00000010???
%JET_bitColumnUpdatable     = &H00000020???   ' /* JetGetColumnInfo only */
%JET_bitColumnTTKey         = &H00000040???   ' /* JetOpenTempTable only */
%JET_bitColumnTTDescending  = &H00000080???   ' /* JetOpenTempTable only */
%JET_bitColumnMultiValued   = &H00000400???
%JET_bitColumnEscrowUpdate  = &H00000800???   ' /* escrow updated */
%JET_bitColumnUnversioned   = &H00001000???   ' /* for add column only - add column unversioned */
#IF %JET_VERSION >= &H0501
%JET_bitColumnMaybeNull          = &H00002000???   ' /* for retrieve column info of outer join where no match from the inner table */
%JET_bitColumnFinalize           = &H00004000???   ' /* this is a finalizable column (issue callback if escrow value equals 0) */
%JET_bitColumnUserDefinedDefault = &H00008000???   ' /* default value from a user-provided callback */
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0502
%JET_bitColumnDeleteOnZero       = &H00020000??? ' /* this is a finalizable column (delete record if escrow value equals 0) */
#ENDIF ' // JET_VERSION >= &H0502
#IF %JET_VERSION >= &H0601
%JET_bitColumnCompressed         = &H00080000??? ' /* data in the column can be compressed */
#ENDIF

#IF %JET_VERSION >= &H0501
'//   flags for JetDeleteColumn
%JET_bitDeleteColumnIgnoreTemplateColumns = &H00000001???  ' //   for derived tables, don't bother looking in template columns
#ENDIF ' // JET_VERSION >= 0x0501


   ' /* Flags for JetSetCurrentIndex */

%JET_bitMoveFirst               = &H00000000???
%JET_bitNoMove                  = &H00000002???

   ' /* Flags for JetMakeKey */

%JET_bitNewKey                  = &H00000001???
%JET_bitStrLimit                = &H00000002???
%JET_bitSubStrLimit             = &H00000004???
%JET_bitNormalizedKey           = &H00000008???
%JET_bitKeyDataZeroLength       = &H00000010???
#IF %JET_VERSION >= &H0501
%JET_bitFullColumnStartLimit    = &H00000100???
%JET_bitFullColumnEndLimit      = &H00000200???
%JET_bitPartialColumnStartLimit = &H00000400???
%JET_bitPartialColumnEndLimit   = &H00000800???
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JetSetIndexRange */

%JET_bitRangeInclusive          = &H00000001???
%JET_bitRangeUpperLimit         = &H00000002???
%JET_bitRangeInstantDuration    = &H00000004???
%JET_bitRangeRemove             = &H00000008???

   ' /* Flags for JetGetLock */

%JET_bitReadLock                = &H00000001???
%JET_bitWriteLock               = &H00000002???

   ' /* Constants for JetMove */

%JET_MoveFirst                 = &H80000000
%JET_MovePrevious              = -1
%JET_MoveNext                  = +1
%JET_MoveLast                  = &H7fffffff

   ' /* Flags for JetMove */

%JET_bitMoveKeyNE              = &H00000001???

   ' /* Flags for JetSeek */

%JET_bitSeekEQ                 = &H00000001???
%JET_bitSeekLT                 = &H00000002???
%JET_bitSeekLE                 = &H00000004???
%JET_bitSeekGE                 = &H00000008???
%JET_bitSeekGT                 = &H00000010???
%JET_bitSetIndexRange          = &H00000020???
#IF %JET_VERSION >= &H0502
%JET_bitCheckUniqueness        = &H00000040???   ' //   to be used with JET_bitSeekEQ only, returns JET_wrnUniqueKey if seek lands on a key which has no dupes
#ENDIF ' // JET_VERSION >= 0x0502

#IF %JET_VERSION >= &H0501
'   //   Flags for JetGotoSecondaryIndexBookmark
%JET_bitBookmarkPermitVirtualCurrency = &H00000001???  ' //   place cursor on relative position in index if specified bookmark no longer exists
#ENDIF ' // JET_VERSION >= 0x0501

   ' /* Flags for JET_CONDITIONALCOLUMN */
%JET_bitIndexColumnMustBeNull    = &H00000001???
%JET_bitIndexColumnMustBeNonNull = &H00000002???

   ' /* Flags for JET_INDEXRANGE */
%JET_bitRecordInIndex            = &H00000001???
%JET_bitRecordNotInIndex         = &H00000002???

   ' /* Flags for JetCreateIndex */

%JET_bitIndexUnique              = &H00000001???
%JET_bitIndexPrimary             = &H00000002???
%JET_bitIndexDisallowNull        = &H00000004???
%JET_bitIndexIgnoreNull          = &H00000008???
%JET_bitIndexIgnoreAnyNull       = &H00000020???
%JET_bitIndexIgnoreFirstNull     = &H00000040???
%JET_bitIndexLazyFlush           = &H00000080???
%JET_bitIndexEmpty               = &H00000100???  ' // don't attempt to build index, because all entries would evaluate to NULL (MUST also specify JET_bitIgnoreAnyNull)
%JET_bitIndexUnversioned         = &H00000200???
%JET_bitIndexSortNullsHigh       = &H00000400???  ' // NULL sorts after data for all columns in the index
%JET_bitIndexUnicode             = &H00000800???  ' // LCID field of JET_INDEXCREATE actually points to a JET_UNICODEINDEX struct to allow user-defined LCMapString() flags
#IF %JET_VERSION >= &H0501
%JET_bitIndexTuples              = &H00001000???  ' // index on substring tuples (text columns only)
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0502
%JET_bitIndexTupleLimits         = &H00002000???  ' // cbVarSegMac field of JET_INDEXCREATE actually points to a JET_TUPLELIMITS struct to allow custom tuple index limits (implies JET_bitIndexTuples)
#ENDIF ' // JET_VERSION >= 0x0502

#IF %JET_VERSION >= &H0600
%JET_bitIndexCrossProduct        = &H00004000???  ' // index over multiple multi-valued columns has full cross product
%JET_bitIndexKeyMost             = &H00008000???  ' // custom index key size set instead of default of 255 bytes
%JET_bitIndexDisallowTruncation  = &H00010000???  ' // fail update rather than truncate index keys
%JET_bitIndexNestedTable         = &H00020000???  ' // index over multiple multi-valued columns but only with values of same itagSequence
#ENDIF   ' // JET_VERSION >= 0x0600

   ' /* Flags for index key definition */

%JET_bitKeyAscending            = &H00000000???
%JET_bitKeyDescending           = &H00000001???

   ' /* Flags for JetOpenTable */

%JET_bitTableDenyWrite =              &H00000001???
%JET_bitTableDenyRead  =              &H00000002???
%JET_bitTableReadOnly  =              &H00000004???
%JET_bitTableUpdatable =              &H00000008???
%JET_bitTablePermitDDL =              &H00000010???   ' /*  override table flagged as FixedDDL (must be used with DenyRead) */
%JET_bitTableNoCache   =              &H00000020???   ' /*  don't cache the pages for this table */
%JET_bitTablePreread   =              &H00000040???   ' /*  assume the table is probably not in the buffer cache */
%JET_bitTableOpportuneRead =          &H00000080???   ' /* attempt to opportunely read physically adjacent leaf pages using larger physical IOs */
%JET_bitTableSequential =             &H00008000???   ' /*  assume the table will be scanned sequentially */

%JET_bitTableClassMask =              &H000F0000???   ' /*  table stats class mask  */
%JET_bitTableClassNone =              &H00000000???   ' /*  table belongs to no stats class (default)  */
%JET_bitTableClass1    =              &H00010000???   ' /*  table belongs to stats class 1  */
%JET_bitTableClass2    =              &H00020000???   ' /*  table belongs to stats class 2  */
%JET_bitTableClass3    =              &H00030000???   ' /*  table belongs to stats class 3  */
%JET_bitTableClass4    =              &H00040000???   ' /*  table belongs to stats class 4  */
%JET_bitTableClass5    =              &H00050000???   ' /*  table belongs to stats class 5  */
%JET_bitTableClass6    =              &H00060000???   ' /*  table belongs to stats class 6  */
%JET_bitTableClass7    =              &H00070000???   ' /*  table belongs to stats class 7  */
%JET_bitTableClass8    =              &H00080000???   ' /*  table belongs to stats class 8  */
%JET_bitTableClass9    =              &H00090000???   ' /*  table belongs to stats class 9  */
%JET_bitTableClass10   =              &H000A0000???   ' /*  table belongs to stats class 10  */
%JET_bitTableClass11   =              &H000B0000???   ' /*  table belongs to stats class 11  */
%JET_bitTableClass12   =              &H000C0000???   ' /*  table belongs to stats class 12  */
%JET_bitTableClass13   =              &H000D0000???   ' /*  table belongs to stats class 13  */
%JET_bitTableClass14   =              &H000E0000???   ' /*  table belongs to stats class 14  */
%JET_bitTableClass15   =              &H000F0000???   ' /*  table belongs to stats class 15  */

#IF %JET_VERSION >= &H0501
%JET_bitLSReset        =              &H00000001???   ' /*   reset LS value */
%JET_bitLSCursor       =              &H00000002???   ' /*   set/retrieve LS of table cursor */
%JET_bitLSTable        =              &H00000004???   ' /*   set/retrieve LS of table */

%JET_LSNil             =  0
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0601
   ' /* Flags for JetSetTableSequential */

%JET_bitPrereadForward      = &H00000001???   ' /*   Hint that the sequential traversal will be in the forward direction */
%JET_bitPrereadBackward     = &H00000002???   ' /*   Hint that the sequential traversal will be in the backward direction */
#ENDIF   ' // JET_VERSION >= 0x0601

   ' /* Flags for JetOpenTempTable */

%JET_bitTTIndexed              = &H00000001???   ' /* Allow seek */
%JET_bitTTUnique               = &H00000002???   ' /* Remove duplicates */
%JET_bitTTUpdatable            = &H00000004???   ' /* Allow updates */
%JET_bitTTScrollable           = &H00000008???   ' /* Allow backwards scrolling */
%JET_bitTTSortNullsHigh        = &H00000010???   ' /* NULL sorts after data for all columns in the index */
%JET_bitTTForceMaterialization = &H00000020???                  ' /* Forces temp. table to be materialized into a btree (allows for duplicate detection) */
#IF %JET_VERSION >= &H0501
%JET_bitTTErrorOnDuplicateInsertion = %JET_bitTTForceMaterialization
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0502
%JET_bitTTForwardOnly          = &H00000040???   ' /* Prevents temp. table from being materialized into a btree (and enables duplicate keys) */
#ENDIF ' // JET_VERSION >= 0x0502
#IF %JET_VERSION >= &H0601
%JET_bitTTIntrinsicLVsOnly     = &H00000080???   ' //   permit only intrinsic LV's (so materialisation is not required simply because a TT has an LV column)
#ENDIF   ' // JET_VERSION >= 0x0601

   ' /* Flags for JetSetColumn */

%JET_bitSetAppendLV                    = &H00000001???
%JET_bitSetOverwriteLV                 = &H00000004???   ' /* overwrite JET_coltypLong* byte range */
%JET_bitSetSizeLV                      = &H00000008???   ' /* set JET_coltypLong* size */
%JET_bitSetZeroLength                  = &H00000020???
%JET_bitSetSeparateLV                  = &H00000040???   ' /* force LV separation */
%JET_bitSetUniqueMultiValues           = &H00000080???   ' /* prevent duplicate multi-values */
%JET_bitSetUniqueNormalizedMultiValues = &H00000100???   ' /* prevent duplicate multi-values, normalizing all data before performing comparisons */
#IF %JET_VERSION >= &H0501
%JET_bitSetRevertToDefaultValue        = &H00000200???   ' /* if setting last tagged instance to NULL, revert to default value instead if one exists */
%JET_bitSetIntrinsicLV                 = &H00000400???   ' /* store whole LV in record without bursting or return an error */
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0601
%JET_bitSetCompressed                  = &H00020000???   ' /* attempt compression when storing the data */
%JET_bitSetUncompressed                = &H00010000???   ' /* don't attempt compression when storing the data */
#ENDIF

#IF %JET_VERSION >= &H0601
   ' /*   Space Hint Flags / JET_SPACEHINTS   */

'//   Generic
%JET_bitSpaceHintsUtilizeParentSpace       = &H00000001???   ' //   This changes the internal allocation policy to get space heirarchically from a B-Tree's immediate parent.
'//   Create
%JET_bitCreateHintAppendSequential         = &H00000002???   ' //   This bit will enable Append split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent).
%JET_bitCreateHintHotpointSequential       = &H00000004???   ' //   This bit will enable Hotpoint split behavior to grow according to the growth dynamics of the table (set by cbMinExtent, ulGrowth, cbMaxExtent).
'//   Retrieve
%JET_bitRetrieveHintReserve1               = &H00000008???   ' //   Reserved and ignored
%JET_bitRetrieveHintTableScanForward       = &H00000010???   ' //   By setting this the client indicates that forward sequential scan is the predominant usage pattern of this table.
%JET_bitRetrieveHintTableScanBackward      = &H00000020???   ' //   By setting this the client indicates that backwards sequential scan is the predominant usage pattern of this table.
%JET_bitRetrieveHintReserve2               = &H00000040???   ' //   Reserved and ignored
%JET_bitRetrieveHintReserve3               = &H00000080???   ' //   Reserved and ignored
'//   Update
'//%JET_bitUpdateReserved                   = &H00000000???   //   TBD.
'//   Delete / .grbitDelete
%JET_bitDeleteHintTableSequential          = &H00000100???   ' //   This means that the application expects this table to be cleaned up in-order sequentially (from lowest key to highest key)
#ENDIF   ' // JET_VERSION >= 0x0601

'   /*   Set column parameter structure for JetSetColumns */

' // Size = 28 bytes
TYPE JET_SETCOLUMN DWORD
   columnid     AS DWORD   ' JET_COLUMNID
   pvData       AS DWORD   ' const void *
   cbData       AS DWORD   ' unsigned long
   grbit        AS DWORD   ' JET_GRBIT
   ibLongValue  AS DWORD   ' unsigned long
   itagSequence AS DWORD   ' unsigned long
   err          AS LONG    ' JET_ERR
END TYPE

#IF %JET_VERSION >= &H0501
' // Size = 16 bytes
TYPE JET_SETSYSPARAM_A DWORD
   paramid AS DWORD        ' unsigned long
   lParam  AS DWORD        ' JET_API_PTR
   sz      AS ASCIIZ PTR   ' const char *
   err     AS LONG         ' JET_ERR
END TYPE

' // Size = 16 bytes
TYPE JET_SETSYSPARAM_W DWORD
   paramid AS DWORD           ' unsigned long
   lParam  AS DWORD           ' JET_API_PTR
   sz      AS WSTRINGZ PTR    ' const WCHAR *
   err     AS LONG            ' JET_ERR
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_SETSYSPARAM = JET_SETSYSPARAM_W
#ELSE
   MACRO JET_SETSYSPARAM = JET_SETSYSPARAM_A
#ENDIF

#ENDIF ' // JET_VERSION >= 0x0501

'   /* Options for JetPrepareUpdate */

%JET_prepInsert                   = 0
%JET_prepReplace                  = 2
%JET_prepCancel                   = 3
%JET_prepReplaceNoLock            = 4
%JET_prepInsertCopy               = 5
#IF %JET_VERSION >= &H0501
%JET_prepInsertCopyDeleteOriginal = 7  ' //   used for updating a record in the primary key; avoids the delete/insert process */
#ENDIF ' // JET_VERSION >= 0x0501

'   //   Flags for JetUpdate
#IF %JET_VERSION >= &H0502
%JET_bitUpdateCheckESE97Compatibility = &H00000001???  ' //   check whether record fits if represented in ESE97 database format
#ENDIF ' // JET_VERSION >= 0x0502

   ' /* Flags for JetEscrowUpdate */
%JET_bitEscrowNoRollback            = &H0001???

   ' /* Flags for JetRetrieveColumn */

%JET_bitRetrieveCopy                = &H00000001???
%JET_bitRetrieveFromIndex           = &H00000002???
%JET_bitRetrieveFromPrimaryBookmark = &H00000004???
%JET_bitRetrieveTag                 = &H00000008???
%JET_bitRetrieveNull                = &H00000010???   ' /*   for columnid 0 only */
%JET_bitRetrieveIgnoreDefault       = &H00000020???   ' /*   for columnid 0 only */
%JET_bitRetrieveLongId              = &H00000040???
%JET_bitRetrieveLongValueRefCount   = &H00000080???   ' /*  for testing use only */
#IF %JET_VERSION >= &H0600
%JET_bitRetrieveTuple               = &H00000800???   ' /* retrieve tuple fragment from index */
#ENDIF   ' // JET_VERSION >= 0x0600

'   /* Retrieve column parameter structure for JetRetrieveColumns */

' // Size = 36 bytes
TYPE JET_RETRIEVECOLUMN DWORD
   columnid           AS DWORD   ' JET_COLUMNID
   pvData             AS DWORD   ' void *
   cbData             AS DWORD   ' unsigned long
   cbActual           AS DWORD   ' unsigned long
   grbit              AS DWORD   ' JET_GRBIT
   ibLongValue        AS DWORD   ' unsigned long
   itagSequence       AS DWORD   ' unsigned long
   columnidNextTagged AS DWORD   ' JET_COLUMNID
   err                AS LONG    ' JET_ERR
END TYPE


#IF %JET_VERSION >= &H0501
'   /* Flags for JetEnumerateColumns */

%JET_bitEnumerateCopy           = %JET_bitRetrieveCopy
%JET_bitEnumerateIgnoreDefault  = %JET_bitRetrieveIgnoreDefault
%JET_bitEnumeratePresenceOnly   = &H00020000???
%JET_bitEnumerateTaggedOnly     = &H00040000???
%JET_bitEnumerateCompressOutput = &H00080000???
#IF %JET_VERSION >= &H0502
'// Available on Server 2003 SP1
%JET_bitEnumerateIgnoreUserDefinedDefault = &H00100000???
#ENDIF   ' // JET_VERSION >= 0x0502
#IF %JET_VERSION >= &H0601
%JET_bitEnumerateInRecordOnly  = &H00200000???
#ENDIF   ' // JET_VERSION >= 0x0601

'   /* Parameter structures for JetEnumerateColumns */

' // Size = 12 bytes
TYPE JET_ENUMCOLUMNID DWORD
   columnid      AS DWORD       ' JET_COLUMNID
   ctagSequence  AS DWORD       ' unsigned long
   rgtagSequence AS DWORD PTR   ' unsigned long*
END TYPE

' // Size = 16 bytes
TYPE JET_ENUMCOLUMNVALUE DWORD
   itagSequence AS DWORD   ' unsigned long
   err          AS LONG    ' JET_ERR
   cbData       AS DWORD   ' unsigned long
   pvData       AS DWORD   ' void*
END TYPE

'typedef struct {
'   JET_COLUMNID          columnid;
'   JET_ERR               err;
'   union {
'      struct { /* err != JET_wrnColumnSingleValue */
'         unsigned long         cEnumColumnValue;
'         JET_ENUMCOLUMNVALUE*   rgEnumColumnValue;
'      };
'      struct { /* err == JET_wrnColumnSingleValue */
'         unsigned long         cbData;
'         void*               pvData;
'      };
'   };
'} JET_ENUMCOLUMN;

' // Size = 8 bytes
TYPE JET_ENUMCOLUMN_UNION_TYPE_1 DWORD
   cEnumColumnValue  AS DWORD                     ' unsigned long
   rgEnumColumnValue AS JET_ENUMCOLUMNVALUE PTR   ' JET_ENUMCOLUMNVALUE*
END TYPE

' // Size = 8 bytes
TYPE JET_ENUMCOLUMN_UNION_TYPE_2 DWORD
   cbData AS DWORD   ' unsigned long
   pvData AS DWORD   ' void*
END TYPE

' // Size = 8 bytes
UNION JET_ENUMCOLUMN_UNION DWORD
   JET_ENUMCOLUMN_UNION_TYPE_1
   JET_ENUMCOLUMN_UNION_TYPE_2
END UNION

' // Size = 16 bytes
TYPE JET_ENUMCOLUMN DWORD
   columnid AS DWORD   ' JET_COLUMNID
   err      AS LONG    ' JET_ERR
   JET_ENUMCOLUMN_UNION
END TYPE

'   /* Realloc callback for JetEnumerateColumns */

'typedef void* (JET_API *JET_PFNREALLOC)( void* pvContext, void* pv, unsigned long cb );
'SUB JET_PFNREALLOC (BIVAL pvContext AS DWORD, BYVAL pv AS DWORD, BYVAL cb AS DWIRD)
'END SUB
#ENDIF '// JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
'   /* Flags for JetGetRecordSize */

%JET_bitRecordSizeInCopyBuffer         = &H00000001  ' //   use record in copy buffer
%JET_bitRecordSizeRunningTotal         = &H00000002  ' //   increment totals in output buffer instead of setting them
%JET_bitRecordSizeLocal                = &H00000004  ' //   ignore Long Values (and other data otherwise not in the same page as the record)

'   /* parameter structures for JetGetRecordSize */

' // Size = 64 bytes
TYPE JET_RECSIZE QWORD
   cbData              AS QUAD   ' unsigned __int64 //   user data in record
   cbLongValueData     AS QUAD   ' unsigned __int64  //   user data associated with the record but stored in the long-value tree (NOTE: does NOT count intrinsic long-values)
   cbOverhead          AS QUAD   ' unsigned __int64  //   record overhead
   cbLongValueOverhead AS QUAD   ' unsigned __int64  //   overhead of long-value data (NOTE: does not count intrinsic long-values)
   cNonTaggedColumns   AS QUAD   ' unsigned __int64  //   total number of fixed/variable columns
   cTaggedColumns      AS QUAD   ' unsigned __int64  //   total number of tagged columns
   cLongValues         AS QUAD   ' unsigned __int64  //   total number of values stored in the long-value tree for this record (NOTE: does NOT count intrinsic long-values)
   cMultiValues        AS QUAD   ' unsigned __int64  //   total number of values beyond the first for each column in the record
END TYPE

#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601
' // Size = 88 bytes
TYPE JET_RECSIZE2 QWORD
   cbData                    AS QUAD   ' unsigned __int64 //   user data in record
   cbLongValueData           AS QUAD   ' unsigned __int64 //   user data associated with the record but stored in the long-value tree (NOTE: does NOT count intrinsic long-values)
   cbOverhead                AS QUAD   ' unsigned __int64 //   record overhead
   cbLongValueOverhead       AS QUAD   ' unsigned __int64 //   overhead of long-value data (NOTE: does not count intrinsic long-values)
   cNonTaggedColumns         AS QUAD   ' unsigned __int64 //   total number of fixed/variable columns
   cTaggedColumns            AS QUAD   ' unsigned __int64 //   total number of tagged columns
   cLongValues               AS QUAD   ' unsigned __int64 //   total number of values stored in the long-value tree for this record (NOTE: does NOT count intrinsic long-values)
   cMultiValues              AS QUAD   ' unsigned __int64 //   total number of values beyond the first for each column in the record
   cCompressedColumns        AS QUAD   ' unsigned __int64 //   total number of columns which are compressed
   cbDataCompressed          AS QUAD   ' unsigned __int64 //   compressed size of user data in record (same as cbData if no intrinsic long-values are compressed)
   cbLongValueDataCompressed AS QUAD   ' unsigned __int64 // compressed size of user data in the long-value tree (same as cbLongValue data if no separated long values are compressed)
END TYPE
#ENDIF   ' // JET_VERSION >= 0x0601

'#pragma warning(pop)      //   nonstandard extension used : nameless struct/union


'   /* Flags for JetBeginTransaction2 */

#IF %JET_VERSION >= &H0501
%JET_bitTransactionReadOnly      = &H00000001???  ' /* transaction will not modify the database */
#ENDIF ' // JET_VERSION >= 0x0501

'   /* Flags for JetCommitTransaction */

%JET_bitCommitLazyFlush      = &H00000001???  ' /* lazy flush log buffers. */
%JET_bitWaitLastLevel0Commit = &H00000002???  ' /* wait for last level 0 commit record flushed */
#IF %JET_VERSION >= &H0502
%JET_bitWaitAllLevel0Commit  = &H00000008???  ' /* wait for all level 0 commits to be flushed */
#ENDIF ' // JET_VERSION >= 0x0502
#IF %JET_VERSION >= &H0601
%JET_bitForceNewLog          = &H00000010???
#ENDIF   ' // JET_VERSION >= 0x0601

'   /* Flags for JetRollback */

%JET_bitRollbackAll = &H00000001???

#IF %JET_VERSION >= &H0600
'   /* Flags for JetOSSnapshot APIs */

'   /* Flags for JetOSSnapshotPrepare */
%JET_bitIncrementalSnapshot   = &H00000001???  ' /* bit 0: full (0) or incremental (1) snapshot */
%JET_bitCopySnapshot          = &H00000002???  ' /* bit 1: normal (0) or copy (1) snapshot */
%JET_bitContinueAfterThaw     = &H00000004???  ' /* bit 2: end on thaw (0) or wait for [truncate +] end snapshot */
#IF %JET_VERSION >= &H0601
%JET_bitExplicitPrepare       = &H00000008???  ' /* bit 3: all instaces prepared by default (0) or no instance prepared by default (1)  */
#ENDIF   ' // JET_VERSION >= 0x0601

'   /* Flags for JetOSSnapshotTruncateLog & JetOSSnapshotTruncateLogInstance */
%JET_bitAllDatabasesSnapshot  = &H00000001???  ' /* bit 0: there are detached dbs in the instance (i.e. can't truncate logs) */

'   /* Flags for JetOSSnapshotEnd */
%JET_bitAbortSnapshot         = &H00000001???  ' /* snapshot process failed */
#ENDIF   ' // JET_VERSION >= 0x0600

'   /* Info parameter for JetGetDatabaseInfo and JetGetDatabaseFileInfo */

%JET_DbInfoFilename       = 0
%JET_DbInfoConnect        = 1
%JET_DbInfoCountry        = 2
#IF %JET_VERSION >= &H0501
%JET_DbInfoLCID           = 3
#ENDIF ' // JET_VERSION >= 0x0501
%JET_DbInfoLangid         = 3     ' // OBSOLETE: use JET_DbInfoLCID instead
%JET_DbInfoCp             = 4
%JET_DbInfoCollate        = 5
%JET_DbInfoOptions        = 6
%JET_DbInfoTransactions   = 7
%JET_DbInfoVersion        = 8
%JET_DbInfoIsam           = 9
%JET_DbInfoFilesize       = 10
%JET_DbInfoSpaceOwned     = 11
%JET_DbInfoSpaceAvailable = 12
%JET_DbInfoUpgrade        = 13
%JET_DbInfoMisc           = 14
#IF %JET_VERSION >= &H0501
%JET_DbInfoDBInUse        = 15
%JET_DbInfoPageSize       = 17
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0600
%JET_DbInfoFileType       = 19
#ENDIF   ' // JET_VERSION >= 0x0600

   ' /* Dbstates from JetGetDatabaseFileInfo */

%JET_dbstateJustCreated    = 1
%JET_dbstateDirtyShutdown  = 2
%JET_dbstateCleanShutdown  = 3
%JET_dbstateBeingConverted = 4
#IF %JET_VERSION >= &H0501
%JET_dbstateForceDetach    = 5
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
'   //   supported file types (returned from JetGetDatabaseFileInfo with JET_DbInfoFileType)
%JET_filetypeUnknown       = 0
%JET_filetypeDatabase      = 1
%JET_filetypeLog           = 3
%JET_filetypeCheckpoint    = 4
%JET_filetypeTempDatabase  = 5
#ENDIF   ' // JET_VERSION >= 0x0600

   ' /* Column data types */

%JET_coltypNil             = 0
%JET_coltypBit             = 1      ' /* True or False, Never NULL */
%JET_coltypUnsignedByte    = 2      ' /* 1-byte integer, unsigned */
%JET_coltypShort           = 3      ' /* 2-byte integer, signed */
%JET_coltypLong            = 4      ' /* 4-byte integer, signed */
%JET_coltypCurrency        = 5      ' /* 8 byte integer, signed */
%JET_coltypIEEESingle      = 6      ' /* 4-byte IEEE single precision */
%JET_coltypIEEEDouble      = 7      ' /* 8-byte IEEE double precision */
%JET_coltypDateTime        = 8      ' /* Integral date, fractional time */
%JET_coltypBinary          = 9      ' /* Binary data, < 255 bytes */
%JET_coltypText            = 10     ' /* ANSI text, case insensitive, < 255 bytes */
%JET_coltypLongBinary      = 11     ' /* Binary data, long value */
%JET_coltypLongText        = 12     ' /* ANSI text, long value */

#IF %JET_VERSION >= &H0600
%JET_coltypSLV             = 13     ' /* SLV's. Reserved. */
%JET_coltypUnsignedLong    = 14     ' /* 4-byte unsigned integer */
%JET_coltypLongLong        = 15     ' /* 8-byte signed integer */
%JET_coltypGUID            = 16     ' /* 16-byte globally unique identifier */
%JET_coltypUnsignedShort   = 17     ' /* 2-byte unsigned integer */
%JET_coltypMax             = 18     ' /* the number of column types  */
                                    ' /* used for validity tests and */
                                    ' /* array declarations.         */
#ELSEIF %JET_VERSION >= &H0501
%JET_coltypSLV             = 13     ' /* SLV's. Reserved. */
%JET_coltypMax             = 14     ' /* the number of column types  */
                                    ' /* used for validity tests and */
                                    ' /* array declarations.         */
#else // !JET_VERSION >= 0x0501
%JET_coltypMax             = 13     ' /* the number of column types  */
                                    ' /* used for validity tests and */
                                    ' /* array declarations.         */
#ENDIF   ' // !JET_VERSION >= 0x0501

   ' /* Info levels for JetGetObjectInfo */

%JET_ObjInfo                   = 0???
%JET_ObjInfoListNoStats        = 1???
%JET_ObjInfoList               = 2???
%JET_ObjInfoSysTabCursor       = 3???
%JET_ObjInfoListACM            = 4??? ' /* Blocked by JetGetObjectInfo */
%JET_ObjInfoNoStats            = 5???
%JET_ObjInfoSysTabReadOnly     = 6???
%JET_ObjInfoRulesLoaded        = 7???
%JET_ObjInfoMax                = 8???

   ' /* Info levels for JetGetTableInfo */

%JET_TblInfo                  = 0???
%JET_TblInfoName              = 1???
%JET_TblInfoDbid              = 2???
%JET_TblInfoMostMany          = 3???
%JET_TblInfoRvt               = 4???
%JET_TblInfoOLC               = 5???
%JET_TblInfoResetOLC          = 6???
%JET_TblInfoSpaceUsage        = 7???
%JET_TblInfoDumpTable         = 8???
%JET_TblInfoSpaceAlloc        = 9???
%JET_TblInfoSpaceOwned        = 10???            ' // OwnExt
%JET_TblInfoSpaceAvailable    = 11???        ' // AvailExt
%JET_TblInfoTemplateTableName = 12???

   ' /* Info levels for JetGetIndexInfo and JetGetTableIndexInfo */

%JET_IdxInfo                  = 0???
%JET_IdxInfoList              = 1???
%JET_IdxInfoSysTabCursor      = 2???
%JET_IdxInfoOLC               = 3???
%JET_IdxInfoResetOLC          = 4???
%JET_IdxInfoSpaceAlloc        = 5???
#IF %JET_VERSION >= &H0501
%JET_IdxInfoLCID              = 6???
#ENDIF ' // JET_VERSION >= 0x0501
%JET_IdxInfoLangid            = 6???     ' //   OBSOLETE: use JET_IdxInfoLCID instead
%JET_IdxInfoCount             = 7???
%JET_IdxInfoVarSegMac         = 8???
%JET_IdxInfoIndexId           = 9???
#IF %JET_VERSION >= &H0600
%JET_IdxInfoKeyMost           = 10???
#ENDIF   ' // JET_VERSION >= 0x0600
#IF %JET_VERSION >= &H0601
%JET_IdxInfoCreateIndex       = 11???    ' //   return a JET_INDEXCREATE structure suitable for use by JetCreateIndex2()
%JET_IdxInfoCreateIndex2      = 12???    ' //   return a JET_INDEXCREATE2 structure suitable for use by JetCreateIndex2()
#ENDIF   ' // JET_VERSION >= 0x0601

   ' /* Info levels for JetGetColumnInfo and JetGetTableColumnInfo */

%JET_ColInfo                  = 0???
%JET_ColInfoList              = 1???
%JET_ColInfoSysTabCursor      = 3???
%JET_ColInfoBase              = 4???
%JET_ColInfoListCompact       = 5???
#IF %JET_VERSION >= &H0501
%JET_ColInfoByColid           = 6???
%JET_ColInfoListSortColumnid  = 7???     ' //   same as JET_ColInfoList except PresentationOrder is set to columnid
                                         ' //   to force sorting by columnid
#ENDIF ' // JET_VERSION >= 0x0501
#IF %JET_VERSION >= &H0600
%JET_ColInfoBaseByColid       = 8???
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0600
' // Grbits for JET_GetColumnInfo and JetGetTableColumnInfo (OR together with the info level)
%JET_ColInfoGrbitNonDerivedColumnsOnly = &H80000000???  ' //   for lists, only return non-derived columns (if the table is derived from a template)
%JET_ColInfoGrbitMinimalInfo           = &H40000000???  ' //   for lists, only return the column name and columnid of each column
%JET_ColInfoGrbitSortByColumnid        = &H20000000???  ' //   for lists, sort returned column list by columnid (default is to sort list by column name)
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0600
' /* Info levels for JetGetInstanceMiscInfo, which is very different than JetGetInstanceInfo, as that retrieves a list of all instances */
%JET_InstanceMiscInfoLogSignature      = 0???
#ENDIF   ' // JET_VERSION >= 0x0600

   ' /* Engine Object Types */

%JET_objtypNil           = 0
%JET_objtypTable         = 1

   ' /* Compact Options */

%JET_bitCompactStats          = &H00000020???   ' /* Dump off-line compaction stats (only when progress meter also specified) */
%JET_bitCompactRepair         = &H00000040???   ' /* Don't preread and ignore duplicate keys */

   ' /* Status Notification Processes */

%JET_snpRepair                = 2
%JET_snpCompact               = 4
%JET_snpRestore               = 8
%JET_snpBackup                = 9
%JET_snpUpgrade               = 10
#IF %JET_VERSION >= &H0501
%JET_snpScrub                 = 11
%JET_snpUpgradeRecordFormat   = 12
#ENDIF ' // JET_VERSION >= 0x0501


   ' /* Status Notification Types */

%JET_sntBegin          = 5   ' /* callback for beginning of operation */
%JET_sntRequirements   = 7   ' /* callback for returning operation requirements */
%JET_sntProgress       = 0   ' /* callback for progress */
%JET_sntComplete       = 6   ' /* callback for completion of operation */
%JET_sntFail           = 3   ' /* callback for failure during progress */

   ' /* Exception action */

%JET_ExceptionMsgBox    = &H0001      ' /* Display message box on exception */
%JET_ExceptionNone      = &H0002      ' /* Do nothing on exceptions */


#IF %JET_VERSION >= &H0501
'   //   Online defragmentation options
%JET_OnlineDefragDisable         = &H0000     ' //   disable online defrag
%JET_OnlineDefragAllOBSOLETE     = &H0001     ' //   enable online defrag for everything (must be 1 for backward compatibility)
%JET_OnlineDefragDatabases       = &H0002     ' //   enable online defrag of databases
%JET_OnlineDefragSpaceTrees      = &H0004     ' //   enable online defrag of space trees
%JET_OnlineDefragAll             = &Hffff     ' //   enable online defrag for everything

#ENDIF ' // JET_VERSION >= 0x0501



' /**********************************************************************/
' /***********************     ERROR CODES     **************************/
' /**********************************************************************/

' /* The Error codes are not versioned with WINVER. */

' /* SUCCESS */

%JET_errSuccess                  = 0    ' /* Successful Operation */

' /* ERRORS */

%JET_wrnNyi                      = -1    ' /* Function Not Yet Implemented */

' /*   SYSTEM errors
' /**/
%JET_errRfsFailure               = -100  ' /* Resource Failure Simulator failure */
%JET_errRfsNotArmed              = -101  ' /* Resource Failure Simulator not initialized */
%JET_errFileClose                = -102  ' /* Could not close file */
%JET_errOutOfThreads             = -103  ' /* Could not start thread */
%JET_errTooManyIO                = -105  ' /* System busy due to too many IOs */
%JET_errTaskDropped              = -106  ' /* A requested async task could not be executed */
%JET_errInternalError            = -107  ' /* Fatal internal error */

'//   BUFFER MANAGER errors
'//
%JET_errDatabaseBufferDependenciesCorrupted  = -255   ' /* Buffer dependencies improperly set. Recovery failure */

' /*   DIRECTORY MANAGER errors
' /**/
%JET_wrnRemainingVersions          =  321  ' /* The version store is still active */
%JET_errPreviousVersion            = -322  ' /* Version already existed. Recovery failure */
%JET_errPageBoundary               = -323  ' /* Reached Page Boundary */
%JET_errKeyBoundary                = -324  ' /* Reached Key Boundary */
%JET_errBadPageLink                = -327  ' /* Database corrupted */
%JET_errBadBookmark                = -328  ' /* Bookmark has no corresponding address in database */
%JET_errNTSystemCallFailed         = -334  ' /* A call to the operating system failed */
%JET_errBadParentPageLink          = -338  ' /* Database corrupted */
%JET_errSPAvailExtCacheOutOfSync   = -340  ' // AvailExt cache doesn't match btree
%JET_errSPAvailExtCorrupted        = -341  ' // AvailExt space tree is corrupt
%JET_errSPAvailExtCacheOutOfMemory = -342  ' // Out of memory allocating an AvailExt cache node
%JET_errSPOwnExtCorrupted          = -343  ' // OwnExt space tree is corrupt
%JET_errDbTimeCorrupted            = -344  ' // Dbtime on current page is greater than global database dbtime
%JET_wrnUniqueKey                  = 345   ' // seek on non-unique index yielded a unique key
%JET_errKeyTruncated               = -346  ' // key truncated on index that disallows key truncation

' /*   RECORD MANAGER errors
' /**/
%JET_wrnSeparateLongValue          = 406  ' /* Column is a separated long-value */
%JET_wrnRecordFoundGreater         = 1039 ' %JET_wrnSeekNotEqual
%JET_wrnRecordFoundLess            = 1039 ' %JET_wrnSeekNotEqual
%JET_errColumnIllegalNull          = -1504 ' %JET_errNullInvalid
%JET_errKeyTooBig                  = -408  ' /* Key is too large */

' /*   LOGGING/RECOVERY errors
' /**/
%JET_errInvalidLoggedOperation     = -500  ' /* Logged operation cannot be redone */
%JET_errLogFileCorrupt             = -501  ' /* Log file is corrupt */
%JET_errNoBackupDirectory          = -503  ' /* No backup directory given */
%JET_errBackupDirectoryNotEmpty    = -504  ' /* The backup directory is not emtpy */
%JET_errBackupInProgress           = -505  ' /* Backup is active already */
%JET_errRestoreInProgress          = -506  ' /* Restore in progress */
%JET_errMissingPreviousLogFile     = -509  ' /* Missing the log file for check point */
%JET_errLogWriteFail               = -510  ' /* Failure writing to log file */
%JET_errLogDisabledDueToRecoveryFailure = -511 ' /* Try to log something after recovery faild */
%JET_errCannotLogDuringRecoveryRedo = -512   ' /* Try to log something during recovery redo */
%JET_errLogGenerationMismatch      = -513  ' /* Name of logfile does not match internal generation number */
%JET_errBadLogVersion              = -514  ' /* Version of log file is not compatible with Jet version */
%JET_errInvalidLogSequence         = -515  ' /* Timestamp in next log does not match expected */
%JET_errLoggingDisabled            = -516  ' /* Log is not active */
%JET_errLogBufferTooSmall          = -517  ' /* Log buffer is too small for recovery */
%JET_errLogSequenceEnd             = -519  ' /* Maximum log file number exceeded */
%JET_errNoBackup                   = -520  ' /* No backup in progress */
%JET_errInvalidBackupSequence      = -521  ' /* Backup call out of sequence */
%JET_errBackupNotAllowedYet        = -523  ' /* Cannot do backup now */
%JET_errDeleteBackupFileFail       = -524  ' /* Could not delete backup file */
%JET_errMakeBackupDirectoryFail    = -525  ' /* Could not make backup temp directory */
%JET_errInvalidBackup              = -526  ' /* Cannot perform incremental backup when circular logging enabled */
%JET_errRecoveredWithErrors        = -527  ' /* Restored with errors */
%JET_errMissingLogFile             = -528  ' /* Current log file missing */
%JET_errLogDiskFull                = -529  ' /* Log disk full */
%JET_errBadLogSignature            = -530  ' /* Bad signature for a log file */
%JET_errBadDbSignature             = -531  ' /* Bad signature for a db file */
%JET_errBadCheckpointSignature     = -532  ' /* Bad signature for a checkpoint file */
%JET_errCheckpointCorrupt          = -533  ' /* Checkpoint file not found or corrupt */
%JET_errMissingPatchPage           = -534  ' /* Patch file page not found during recovery */
%JET_errBadPatchPage               = -535  ' /* Patch file page is not valid */
%JET_errRedoAbruptEnded            = -536  ' /* Redo abruptly ended due to sudden failure in reading logs from log file */
%JET_errBadSLVSignature            = -537  ' /* Signature in SLV file does not agree with database */
%JET_errPatchFileMissing           = -538  ' /* Hard restore detected that patch file is missing from backup set */
%JET_errDatabaseLogSetMismatch     = -539  ' /* Database does not belong with the current set of log files */
%JET_errDatabaseStreamingFileMismatch  = -540 ' /* Database and streaming file do not match each other */
%JET_errLogFileSizeMismatch        = -541  ' /* actual log file size does not match JET_paramLogFileSize */
%JET_errCheckpointFileNotFound     = -542  ' /* Could not locate checkpoint file */
%JET_errRequiredLogFilesMissing    = -543  ' /* The required log files for recovery is missing. */
%JET_errSoftRecoveryOnBackupDatabase = -544  ' /* Soft recovery is intended on a backup database. Restore should be used instead */
%JET_errLogFileSizeMismatchDatabasesConsistent = -545  ' /* databases have been recovered, but the log file size used during recovery does not match JET_paramLogFileSize */
%JET_errLogSectorSizeMismatch      = -546  ' /* the log file sector size does not match the current volume's sector size */
%JET_errLogSectorSizeMismatchDatabasesConsistent = -547  ' /* databases have been recovered, but the log file sector size (used during recovery) does not match the current volume's sector size */
%JET_errLogSequenceEndDatabasesConsistent = -548 ' /* databases have been recovered, but all possible log generations in the current sequence are used; delete all log files and the checkpoint file and backup the databases before continuing */

%JET_errStreamingDataNotLogged     = -549  ' /* Illegal attempt to replay a streaming file operation where the data wasn't logged. Probably caused by an attempt to roll-forward with circular logging enabled */

%JET_errDatabaseDirtyShutdown      = -550  ' /* Database was not shutdown cleanly. Recovery must first be run to properly complete database operations for the previous shutdown. */
%JET_errDatabaseInconsistent       = %JET_errDatabaseDirtyShutdown   ' /* OBSOLETE */
%JET_errConsistentTimeMismatch     = -551  ' /* Database last consistent time unmatched */
%JET_errDatabasePatchFileMismatch  = -552  ' /* Patch file is not generated from this backup */
%JET_errEndingRestoreLogTooLow     = -553  ' /* The starting log number too low for the restore */
%JET_errStartingRestoreLogTooHigh  = -554  ' /* The starting log number too high for the restore */
%JET_errGivenLogFileHasBadSignature = -555  ' /* Restore log file has bad signature */
%JET_errGivenLogFileIsNotContiguous = -556  ' /* Restore log file is not contiguous */
%JET_errMissingRestoreLogFiles     = -557  ' /* Some restore log files are missing */
%JET_wrnExistingLogFileHasBadSignature = 558  ' /* Existing log file has bad signature */
%JET_wrnExistingLogFileIsNotContiguous = 559  ' /* Existing log file is not contiguous */
%JET_errMissingFullBackup          = -560  ' /* The database miss a previous full backup befor incremental backup */
%JET_errBadBackupDatabaseSize      = -561  ' /* The backup database size is not in 4k */
%JET_errDatabaseAlreadyUpgraded    = -562  ' /* Attempted to upgrade a database that is already current */
%JET_errDatabaseIncompleteUpgrade  = -563  ' /* Attempted to use a database which was only partially converted to the current format= -- must restore from backup */
%JET_wrnSkipThisRecord             = 564  ' /* INTERNAL ERROR */
%JET_errMissingCurrentLogFiles     = -565  ' /* Some current log files are missing for continuous restore */

%JET_errDbTimeTooOld               = -566  ' /* dbtime on page smaller than dbtimeBefore in record */
%JET_errDbTimeTooNew               = -567  ' /* dbtime on page in advance of the dbtimeBefore in record */
%JET_errMissingFileToBackup        = -569  ' /* Some log or patch files are missing during backup */

%JET_errLogTornWriteDuringHardRestore  = -570   ' /* torn-write was detected in a backup set during hard restore */
%JET_errLogTornWriteDuringHardRecovery = -571   ' /* torn-write was detected during hard recovery (log was not part of a backup set) */
%JET_errLogCorruptDuringHardRestore    = -573   ' /* corruption was detected in a backup set during hard restore */
%JET_errLogCorruptDuringHardRecovery   = -574   ' /* corruption was detected during hard recovery (log was not part of a backup set) */

%JET_errMustDisableLoggingForDbUpgrade = -575   ' /* Cannot have logging enabled while attempting to upgrade db */

%JET_errBadRestoreTargetInstance       = -577   ' /* TargetInstance specified for restore is not found or log files don't match */
%JET_wrnTargetInstanceRunning          = 578    ' /* TargetInstance specified for restore is running */

%JET_errRecoveredWithoutUndo           = -579   ' /* Soft recovery successfully replayed all operations, but the Undo phase of recovery was skipped */

%JET_errDatabasesNotFromSameSnapshot   = -580   ' /* Databases to be restored are not from the same shadow copy backup */
%JET_errSoftRecoveryOnSnapshot         = -581   ' /* Soft recovery on a database from a shadow copy backup set */
%JET_errCommittedLogFilesMissing       = -582   ' /* One or more logs that were committed to this database, are missing.  These log files are required to maintain durable ACID semantics,
                                                '    but not required to maintain consistency if the JET_bitReplayIgnoreLostLogs bit is specified during recovery. */
%JET_errSectorSizeNotSupported         = -583   ' /* The physical sector size reported by the disk subsystem, is unsupported by ESE for a specific file type. */
%JET_errRecoveredWithoutUndoDatabasesConsistent = -584   ' /* Soft recovery successfully replayed all operations and intended to skip the Undo phase of recovery, but the Undo phase was not required */
%JET_wrnCommittedLogFilesLost          = 585    ' /* One or more logs that were committed to this database, were not recovered.  The database is still clean/consistent, as though the lost log's transactions were committed lazily (and lost). */
%JET_errCommittedLogFileCorrupt        = -586   ' /* One or more logs were found to be corrupt during recovery.  These log files are required to maintain durable ACID semantics,
                                                '    but not required to maintain consistency if the JET_bitIgnoreLostLogs bit and JET_paramDeleteOutOfRangeLogs is specified during recovery. */
%JET_wrnCommittedLogFilesRemoved       = 587    ' /* One or more logs that were committed to this database, were no recovered.  The database is still clean/consistent, as though the corrupted log's transactions were committed lazily (and lost). */

%JET_wrnDatabaseRepaired               = 595    ' /* Database corruption has been repaired */

%JET_errUnicodeTranslationBufferTooSmall = -601   ' /* Unicode translation buffer too small */
%JET_errUnicodeTranslationFail           = -602   ' /* Unicode normalization failed */
%JET_errUnicodeNormalizationNotSupported = -603   ' /* OS does not provide support for Unicode normalisation (and no normalisation callback was specified) */

%JET_errExistingLogFileHasBadSignature  = -610   ' /* Existing log file has bad signature */
%JET_errExistingLogFileIsNotContiguous  = -611   ' /* Existing log file is not contiguous */

%JET_errLogReadVerifyFailure        = -612  ' /* Checksum error in log file during backup */
%JET_errSLVReadVerifyFailure        = -613  ' /* Checksum error in SLV file during backup */

%JET_errCheckpointDepthTooDeep      = -614  ' //   too many outstanding generations between checkpoint and current generation

%JET_errRestoreOfNonBackupDatabase  = -615  ' //   hard recovery attempted on a database that wasn't a backup database


%JET_errInvalidGrbit               = -900  ' /* Invalid parameter */

%JET_errTermInProgress             = -1000 ' /* Termination in progress */
%JET_errFeatureNotAvailable        = -1001 ' /* API not supported */
%JET_errInvalidName                = -1002 ' /* Invalid name */
%JET_errInvalidParameter           = -1003 ' /* Invalid API parameter */
%JET_wrnColumnNull                 = 1004  ' /* Column is NULL-valued */
%JET_wrnBufferTruncated            = 1006  ' /* Buffer too small for data */
%JET_wrnDatabaseAttached           = 1007  ' /* Database is already attached */
%JET_errDatabaseFileReadOnly       = -1008 ' /* Tried to attach a read-only database file for read/write operations */
%JET_wrnSortOverflow               = 1009  ' /* Sort does not fit in memory */
%JET_errInvalidDatabaseId          = -1010 ' /* Invalid database id */
%JET_errOutOfMemory                = -1011 ' /* Out of Memory */
%JET_errOutOfDatabaseSpace         = -1012 ' /* Maximum database size reached */
%JET_errOutOfCursors               = -1013 ' /* Out of table cursors */
%JET_errOutOfBuffers               = -1014 ' /* Out of database page buffers */
%JET_errTooManyIndexes             = -1015 ' /* Too many indexes */
%JET_errTooManyKeys                = -1016 ' /* Too many columns in an index */
%JET_errRecordDeleted              = -1017 ' /* Record has been deleted */
%JET_errReadVerifyFailure          = -1018 ' /* Checksum error on a database page */
%JET_errPageNotInitialized         = -1019 ' /* Blank database page */
%JET_errOutOfFileHandles           = -1020 ' /* Out of file handles */
%JET_errDiskReadVerificationFailure = -1021 ' /* The OS returned ERROR_CRC from file IO */
%JET_errDiskIO                     = -1022 ' /* Disk IO error */
%JET_errInvalidPath                = -1023 ' /* Invalid file path */
%JET_errInvalidSystemPath          = -1024 ' /* Invalid system path */
%JET_errInvalidLogDirectory        = -1025 ' /* Invalid log directory */
%JET_errRecordTooBig               = -1026 ' /* Record larger than maximum size */
%JET_errTooManyOpenDatabases       = -1027 ' /* Too many open databases */
%JET_errInvalidDatabase            = -1028 ' /* Not a database file */
%JET_errNotInitialized             = -1029 ' /* Database engine not initialized */
%JET_errAlreadyInitialized         = -1030 ' /* Database engine already initialized */
%JET_errInitInProgress             = -1031 ' /* Database engine is being initialized */
%JET_errFileAccessDenied           = -1032 ' /* Cannot access file, the file is locked or in use */
%JET_errBufferTooSmall             = -1038 ' /* Buffer is too small */
%JET_wrnSeekNotEqual               = 1039 ' /* Exact match not found during seek */
%JET_errTooManyColumns             = -1040 ' /* Too many columns defined */
%JET_errContainerNotEmpty          = -1043 ' /* Container is not empty */
%JET_errInvalidFilename            = -1044 ' /* Filename is invalid */
%JET_errInvalidBookmark            = -1045 ' /* Invalid bookmark */
%JET_errColumnInUse                = -1046 ' /* Column used in an index */
%JET_errInvalidBufferSize          = -1047 ' /* Data buffer doesn't match column size */
%JET_errColumnNotUpdatable         = -1048 ' /* Cannot set column value */
%JET_errIndexInUse                 = -1051 ' /* Index is in use */
%JET_errLinkNotSupported           = -1052 ' /* Link support unavailable */
%JET_errNullKeyDisallowed          = -1053 ' /* Null keys are disallowed on index */
%JET_errNotInTransaction           = -1054 ' /* Operation must be within a transaction */
%JET_wrnNoErrorInfo                = 1055 ' /* No extended error information */
%JET_wrnNoIdleActivity             = 1058 ' /* No idle activity occured */
%JET_errTooManyActiveUsers         = -1059 ' /* Too many active database users */
%JET_errInvalidCountry             = -1061 ' /* Invalid or unknown country code */
%JET_errInvalidLanguageId          = -1062 ' /* Invalid or unknown language id */
%JET_errInvalidCodePage            = -1063 ' /* Invalid or unknown code page */
%JET_errInvalidLCMapStringFlags    = -1064 ' /* Invalid flags for LCMapString() */
%JET_errVersionStoreEntryTooBig    = -1065 ' /* Attempted to create a version store entry (RCE) larger than a version bucket */
%JET_errVersionStoreOutOfMemoryAndCleanupTimedOut = -1066 ' /* Version store out of memory (and cleanup attempt failed to complete) */
%JET_wrnNoWriteLock                = 1067 ' /* No write lock at transaction level 0 */
%JET_wrnColumnSetNull              = 1068 ' /* Column set to NULL-value */
%JET_errVersionStoreOutOfMemory    = -1069 ' /* Version store out of memory (cleanup already attempted) */
%JET_errCannotIndex                = -1071 ' /* Cannot index escrow column or SLV column */
%JET_errRecordNotDeleted           = -1072 ' /* Record has not been deleted */
%JET_errTooManyMempoolEntries      = -1073 ' /* Too many mempool entries requested */
%JET_errOutOfObjectIDs             = -1074 ' /* Out of btree ObjectIDs (perform offline defrag to reclaim freed/unused ObjectIds) */
%JET_errOutOfLongValueIDs          = -1075 ' /* Long-value ID counter has reached maximum value. (perform offline defrag to reclaim free/unused LongValueIDs) */
%JET_errOutOfAutoincrementValues   = -1076 ' /* Auto-increment counter has reached maximum value (offline defrag WILL NOT be able to reclaim free/unused Auto-increment values). */
%JET_errOutOfDbtimeValues          = -1077 ' /* Dbtime counter has reached maximum value (perform offline defrag to reclaim free/unused Dbtime values) */
%JET_errOutOfSequentialIndexValues = -1078 ' /* Sequential index counter has reached maximum value (perform offline defrag to reclaim free/unused SequentialIndex values) */

%JET_errRunningInOneInstanceMode   = -1080 ' /* Multi-instance call with single-instance mode enabled */
%JET_errRunningInMultiInstanceMode = -1081 ' /* Single-instance call with multi-instance mode enabled */
%JET_errSystemParamsAlreadySet     = -1082 ' /* Global system parameters have already been set */

%JET_errSystemPathInUse            = -1083 ' /* System path already used by another database instance */
%JET_errLogFilePathInUse           = -1084 ' /* Logfile path already used by another database instance */
%JET_errTempPathInUse              = -1085 ' /* Temp path already used by another database instance */
%JET_errInstanceNameInUse          = -1086 ' /* Instance Name already in use */

%JET_errInstanceUnavailable        = -1090 ' /* This instance cannot be used because it encountered a fatal error */
%JET_errDatabaseUnavailable        = -1091 ' /* This database cannot be used because it encountered a fatal error */
%JET_errInstanceUnavailableDueToFatalLogDiskFull = -1092 ' /* This instance cannot be used because it encountered a log-disk-full error performing an operation (likely transaction rollback) that could not tolerate failure */

%JET_errOutOfSessions             = -1101 ' /* Out of sessions */
%JET_errWriteConflict             = -1102 ' /* Write lock failed due to outstanding write lock */
%JET_errTransTooDeep              = -1103 ' /* Transactions nested too deeply */
%JET_errInvalidSesid              = -1104 ' /* Invalid session handle */
%JET_errWriteConflictPrimaryIndex = -1105 ' /* Update attempted on uncommitted primary index */
%JET_errInTransaction             = -1108 ' /* Operation not allowed within a transaction */
%JET_errRollbackRequired          = -1109 ' /* Must rollback current transaction= -- cannot commit or begin a new one */
%JET_errTransReadOnly             = -1110 ' /* Read-only transaction tried to modify the database */
%JET_errSessionWriteConflict      = -1111 ' /* Attempt to replace the same record by two diffrerent cursors in the same session */

%JET_errRecordTooBigForBackwardCompatibility = -1112 ' /* record would be too big if represented in a database format from a previous version of Jet */
%JET_errCannotMaterializeForwardOnlySort     = -1113 ' /* The temp table could not be created due to parameters that conflict with JET_bitTTForwardOnly */

%JET_errSesidTableIdMismatch     = -1114 ' /* This session handle can't be used with this table id */
%JET_errInvalidInstance          = -1115 ' /* Invalid instance handle */
%JET_errDirtyShutdown            = -1116 ' /* The instance was shutdown successfully but all the attached databases were left in a dirty state by request via JET_bitTermDirty */

%JET_errDatabaseDuplicate        = -1201 ' /* Database already exists */
%JET_errDatabaseInUse            = -1202 ' /* Database in use */
%JET_errDatabaseNotFound         = -1203 ' /* No such database */
%JET_errDatabaseInvalidName      = -1204 ' /* Invalid database name */
%JET_errDatabaseInvalidPages     = -1205 ' /* Invalid number of pages */
%JET_errDatabaseCorrupted        = -1206 ' /* Non database file or corrupted db */
%JET_errDatabaseLocked           = -1207 ' /* Database exclusively locked */
%JET_errCannotDisableVersioning  = -1208 ' /* Cannot disable versioning for this database */
%JET_errInvalidDatabaseVersion   = -1209 ' /* Database engine is incompatible with database */

' /*   The following error code are for NT clients only. It will return such error during
' *   JetInit if JET_paramCheckFormatWhenOpenFail is set.
' */
%JET_errDatabase200Format        = -1210 ' /* The database is in an older (200) format */
%JET_errDatabase400Format        = -1211 ' /* The database is in an older (400) format */
%JET_errDatabase500Format        = -1212 ' /* The database is in an older (500) format */

%JET_errPageSizeMismatch           = -1213 ' /* The database page size does not match the engine */
%JET_errTooManyInstances           = -1214 ' /* Cannot start any more database instances */
%JET_errDatabaseSharingViolation   = -1215 ' /* A different database instance is using this database */
%JET_errAttachedDatabaseMismatch   = -1216 ' /* An outstanding database attachment has been detected at the start or end of recovery, but database is missing or does not match attachment info */
%JET_errDatabaseInvalidPath        = -1217 ' /* Specified path to database file is illegal */
%JET_errDatabaseIdInUse            = -1218 ' /* A database is being assigned an id already in use */
%JET_errForceDetachNotAllowed      = -1219 ' /* Force Detach allowed only after normal detach errored out */
%JET_errCatalogCorrupted           = -1220 ' /* Corruption detected in catalog */
%JET_errPartiallyAttachedDB        = -1221 ' /* Database is partially attached. Cannot complete attach operation */
%JET_errDatabaseSignInUse          = -1222 ' /* Database with same signature in use */

%JET_errDatabaseCorruptedNoRepair  = -1224 ' /* Corrupted db but repair not allowed */

%JET_wrnTableEmpty               =  1301 ' /* Opened an empty table */
%JET_errTableLocked              = -1302 ' /* Table is exclusively locked */
%JET_errTableDuplicate           = -1303 ' /* Table already exists */
%JET_errTableInUse               = -1304 ' /* Table is in use, cannot lock */
%JET_errObjectNotFound           = -1305 ' /* No such table or object */
%JET_errDensityInvalid           = -1307 ' /* Bad file/index density */
%JET_errTableNotEmpty            = -1308 ' /* Table is not empty */
%JET_errInvalidTableId           = -1310 ' /* Invalid table id */
%JET_errTooManyOpenTables        = -1311 ' /* Cannot open any more tables (cleanup already attempted) */
%JET_errIllegalOperation         = -1312 ' /* Oper. not supported on table */
%JET_errTooManyOpenTablesAndCleanupTimedOut  = -1313 ' /* Cannot open any more tables (cleanup attempt failed to complete) */
%JET_errObjectDuplicate           = -1314 ' /* Table or object name in use */
%JET_errInvalidObject             = -1316 ' /* Object is invalid for operation */
%JET_errCannotDeleteTempTable     = -1317 ' /* Use CloseTable instead of DeleteTable to delete temp table */
%JET_errCannotDeleteSystemTable   = -1318 ' /* Illegal attempt to delete a system table */
%JET_errCannotDeleteTemplateTable = -1319 ' /* Illegal attempt to delete a template table */
%JET_errExclusiveTableLockRequired  = -1322 ' /* Must have exclusive lock on table. */
%JET_errFixedDDL                  = -1323 ' /* DDL operations prohibited on this table */
%JET_errFixedInheritedDDL         = -1324 ' /* On a derived table, DDL operations are prohibited on inherited portion of DDL */
%JET_errCannotNestDDL             = -1325 ' /* Nesting of hierarchical DDL is not currently supported. */
%JET_errDDLNotInheritable         = -1326 ' /* Tried to inherit DDL from a table not marked as a template table. */
%JET_wrnTableInUseBySystem        = 1327 ' /* System cleanup has a cursor open on the table */
%JET_errInvalidSettings           = -1328 ' /* System parameters were set improperly */
%JET_errClientRequestToStopJetService  = -1329   ' /* Client has requested stop service */
%JET_errCannotAddFixedVarColumnToDerivedTable  = -1330   ' /* Template table was created with NoFixedVarColumnsInDerivedTables */

'/*   DDL errors
'/**/
'// Note: Some DDL errors have snuck into other categories.
%JET_errIndexCantBuild            = -1401 ' /* Index build failed */
%JET_errIndexHasPrimary           = -1402 ' /* Primary index already defined */
%JET_errIndexDuplicate            = -1403 ' /* Index is already defined */
%JET_errIndexNotFound             = -1404 ' /* No such index */
%JET_errIndexMustStay             = -1405 ' /* Cannot delete clustered index */
%JET_errIndexInvalidDef           = -1406 ' /* Illegal index definition */
%JET_errInvalidCreateIndex        = -1409 ' /* Invalid create index description */
%JET_errTooManyOpenIndexes        = -1410 ' /* Out of index description blocks */
%JET_errMultiValuedIndexViolation = -1411 ' /* Non-unique inter-record index keys generated for a multivalued index */
%JET_errIndexBuildCorrupted       = -1412 ' /* Failed to build a secondary index that properly reflects primary index */
%JET_errPrimaryIndexCorrupted     = -1413 ' /* Primary index is corrupt. The database must be defragmented */
%JET_errSecondaryIndexCorrupted   = -1414 ' /* Secondary index is corrupt. The database must be defragmented */
%JET_wrnCorruptIndexDeleted       = 1415 ' /* Out of date index removed */
%JET_errInvalidIndexId            = -1416 ' /* Illegal index id */

%JET_errIndexTuplesSecondaryIndexOnly      = -1430   ' //   tuple index can only be on a secondary index
%JET_errIndexTuplesOneColumnOnly           = -1431   ' //   tuple index may only have one column in the index
%JET_errIndexTuplesNonUniqueOnly           = -1432   ' //   tuple index must be a non-unique index
%JET_errIndexTuplesTextColumnsOnly         = -1433   ' //   tuple index must be on a text column
%JET_errIndexTuplesVarSegMacNotAllowed     = -1434   ' //   tuple index does not allow setting cbVarSegMac
%JET_errIndexTuplesInvalidLimits           = -1435   ' //   invalid min/max tuple length or max characters to index specified
%JET_errIndexTuplesCannotRetrieveFromIndex = -1436   ' //   cannot call RetrieveColumn() with RetrieveFromIndex on a tuple index
%JET_errIndexTuplesKeyTooSmall             = -1437   ' //   specified key does not meet minimum tuple length

'/*   DML errors
'/**/
'// Note: Some DML errors have snuck into other categories.
'// Note: Some DDL errors have inappropriately snuck in here.
%JET_errColumnLong                = -1501 ' /* Column value is long */
%JET_errColumnNoChunk             = -1502 ' /* No such chunk in long value */
%JET_errColumnDoesNotFit          = -1503 ' /* Field will not fit in record */
%JET_errNullInvalid               = -1504 ' /* Null not valid */
%JET_errColumnIndexed             = -1505 ' /* Column indexed, cannot delete */
%JET_errColumnTooBig              = -1506 ' /* Field length is greater than maximum */
%JET_errColumnNotFound            = -1507 ' /* No such column */
%JET_errColumnDuplicate           = -1508 ' /* Field is already defined */
%JET_errMultiValuedColumnMustBeTagged  = -1509 ' /* Attempted to create a multi-valued column, but column was not Tagged */
%JET_errColumnRedundant           = -1510 ' /* Second autoincrement or version column */
%JET_errInvalidColumnType         = -1511 ' /* Invalid column data type */
%JET_wrnColumnMaxTruncated        =  1512 ' /* Max length too big, truncated */
%JET_errTaggedNotNULL             = -1514 ' /* No non-NULL tagged columns */
%JET_errNoCurrentIndex            = -1515 ' /* Invalid w/o a current index */
%JET_errKeyIsMade                 = -1516 ' /* The key is completely made */
%JET_errBadColumnId               = -1517 ' /* Column Id Incorrect */
%JET_errBadItagSequence           = -1518 ' /* Bad itagSequence for tagged column */
%JET_errColumnInRelationship      = -1519 ' /* Cannot delete, column participates in relationship */
%JET_wrnCopyLongValue             = 1520 ' /* Single instance column bursted */
%JET_errCannotBeTagged            = -1521 ' /* AutoIncrement and Version cannot be tagged */
%JET_errDefaultValueTooBig        = -1524 ' /* Default value exceeds maximum size */
%JET_errMultiValuedDuplicate      = -1525 ' /* Duplicate detected on a unique multi-valued column */
%JET_errLVCorrupted               = -1526 ' /* Corruption encountered in long-value tree */
%JET_errMultiValuedDuplicateAfterTruncation  = -1528 ' /* Duplicate detected on a unique multi-valued column after data was normalized, and normalizing truncated the data before comparison */
%JET_errDerivedColumnCorruption   = -1529 ' /* Invalid column in derived table */
%JET_errInvalidPlaceholderColumn  = -1530 ' /* Tried to convert column to a primary index placeholder, but column doesn't meet necessary criteria */
%JET_wrnColumnSkipped             = 1531 ' /* Column value(s) not returned because the corresponding column id or itagSequence requested for enumeration was null */
%JET_wrnColumnNotLocal            = 1532 ' /* Column value(s) not returned because they could not be reconstructed from the data at hand */
%JET_wrnColumnMoreTags            = 1533 ' /* Column values exist that were not requested for enumeration */
%JET_wrnColumnTruncated           = 1534 ' /* Column value truncated at the requested size limit during enumeration */
%JET_wrnColumnPresent             = 1535 ' /* Column values exist but were not returned by request */
%JET_wrnColumnSingleValue         = 1536 ' /* Column value returned in JET_COLUMNENUM as a result of JET_bitEnumerateCompressOutput */
%JET_wrnColumnDefault             = 1537  ' /* Column value(s) not returned because they were set to their default value(s) and JET_bitEnumerateIgnoreDefault was specified */
%JET_errColumnCannotBeCompressed  = -1538 ' /* Only JET_coltypLongText and JET_coltypLongBinary columns can be compressed */
%JET_wrnColumnNotInRecord         = 1539  ' /* Column value(s) not returned because they could not be reconstructed from the data in the record */

%JET_errRecordNotFound            = -1601 ' /* The key was not found */
%JET_errRecordNoCopy              = -1602 ' /* No working buffer */
%JET_errNoCurrentRecord           = -1603 ' /* Currency not on a record */
%JET_errRecordPrimaryChanged      = -1604 ' /* Primary key may not change */
%JET_errKeyDuplicate              = -1605 ' /* Illegal duplicate key */
%JET_errAlreadyPrepared           = -1607 ' /* Attempted to update record when record update was already in progress */
%JET_errKeyNotMade                = -1608 ' /* No call to JetMakeKey */
%JET_errUpdateNotPrepared         = -1609 ' /* No call to JetPrepareUpdate */
%JET_wrnDataHasChanged            = 1610 ' /* Data has changed */
%JET_errDataHasChanged            = -1611 ' /* Data has changed, operation aborted */
%JET_wrnKeyChanged                = 1618 ' /* Moved to new key */
%JET_errLanguageNotSupported      = -1619 ' /* Windows installation does not support language */
%JET_errDecompressionFailed       = -1620 ' /* Internal error: data could not be decompressed */

'/*   Sort Table errors
'/**/
%JET_errTooManySorts              = -1701 ' /* Too many sort processes */
%JET_errInvalidOnSort             = -1702 ' /* Invalid operation on Sort */

'/*   Other errors
'/**/
%JET_errTempFileOpenError         = -1803 ' /* Temp file could not be opened */
%JET_errTooManyAttachedDatabases  = -1805 ' /* Too many open databases */
%JET_errDiskFull                  = -1808 ' /* No space left on disk */
%JET_errPermissionDenied          = -1809 ' /* Permission denied */
%JET_errFileNotFound              = -1811 ' /* File not found */
%JET_errFileInvalidType           = -1812 ' /* Invalid file type */
%JET_wrnFileOpenReadOnly          = 1813 ' /* Database file is read only */
%JET_errAfterInitialization       = -1850 ' /* Cannot Restore after init. */
%JET_errLogCorrupted              = -1852 ' /* Logs could not be interpreted */
%JET_errInvalidOperation          = -1906 ' /* Invalid operation */
%JET_errAccessDenied              = -1907 ' /* Access denied */
%JET_wrnIdleFull                  = 1908 ' /* Idle registry full */
%JET_errTooManySplits             = -1909 ' /* Infinite split */
%JET_errSessionSharingViolation   = -1910 ' /* Multiple threads are using the same session */
%JET_errEntryPointNotFound        = -1911 ' /* An entry point in a DLL we require could not be found */
%JET_errSessionContextAlreadySet  = -1912 ' /* Specified session already has a session context set */
%JET_errSessionContextNotSetByThisThread  = -1913 ' /* Tried to reset session context, but current thread did not orignally set the session context */
%JET_errSessionInUse              = -1914 ' /* Tried to terminate session in use */

%JET_errRecordFormatConversionFailed  = -1915 ' /* Internal error during dynamic record format conversion */
%JET_errOneDatabasePerSession     = -1916 ' /* Just one open user database per session is allowed (JET_paramOneDatabasePerSession) */
%JET_errRollbackError             = -1917 ' /* error during rollback */

%JET_wrnDefragAlreadyRunning      = 2000 ' /* Online defrag already running on specified database */
%JET_wrnDefragNotRunning          = 2001 ' /* Online defrag not running on specified database */

%JET_wrnCallbackNotRegistered     = 2100 ' /* Unregistered a non-existant callback function */
%JET_errCallbackFailed            = -2101 ' /* A callback failed */
%JET_errCallbackNotResolved       = -2102 ' /* A callback function could not be found */

%JET_errSpaceHintsInvalid         = -2103 ' /* An element of the JET space hints structure was not correct or actionable. */

%JET_errOSSnapshotInvalidSequence  = -2401 ' /* OS Shadow copy API used in an invalid sequence */
%JET_errOSSnapshotTimeOut          = -2402 ' /* OS Shadow copy ended with time-out */
%JET_errOSSnapshotNotAllowed       = -2403 ' /* OS Shadow copy not allowed (backup or recovery in progress) */

%JET_errLSCallbackNotSpecified     = -3000 ' /* Attempted to use Local Storage without a callback function being specified */
%JET_errLSAlreadySet               = -3001 ' /* Attempted to set Local Storage for an object which already had it set */
%JET_errLSNotSet                   = -3002 ' /* Attempted to retrieve Local Storage from an object which didn't have it set */

' /** FILE AND DISK ERRORS
' **/
'//JET_errFileAccessDenied          = -1032
'//JET_errFileNotFound              = -1811
'//JET_errInvalidFilename           = -1044
%JET_errFileIOBeyondEOF            = -4001 ' /* a read was issued to a location beyond EOF (writes will expand the file) */
%JET_errFileIOAbort                = -4002 ' /* instructs the JET_ABORTRETRYFAILCALLBACK caller to abort the specified I/O */
%JET_errFileIORetry                = -4003 ' /* instructs the JET_ABORTRETRYFAILCALLBACK caller to retry the specified I/O */
%JET_errFileIOFail                 = -4004 ' /* instructs the JET_ABORTRETRYFAILCALLBACK caller to fail the specified I/O */
%JET_errFileCompressed             = -4005 ' /* read/write access is not supported on compressed files */


'#########################################################################################
'################################      PROTOTYPES      ###################################
'#########################################################################################

' ========================================================================================
' The JetInit function puts the database engine into a state where it can support
' application use of database files. The engine must already be properly configured for
' initialization using JetSetSystemParameter. Database crash recovery is performed
' automatically as a part of the initialization process.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetInit IMPORT "ESENT.DLL" ALIAS "JetInit" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE *pinstance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetInit2 function puts the database engine into a state where it can support
' application use of database files. The engine must already be properly configured for
' initialization using JetSetSystemParameter. Database crash recovery is performed
' automatically as a part of the initialization process.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetInit2 IMPORT "ESENT.DLL" ALIAS "JetInit2" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE *pinstance
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetInit3A IMPORT "ESENT.DLL" ALIAS "JetInit3A" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE *pinstance
 , BYREF prstInfo AS JET_RSTINFO_A _                    ' __in_opt JET_RSTINFO_A   *prstInfo
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT            grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetInit3W IMPORT "ESENT.DLL" ALIAS "JetInit3W" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE *pinstance
 , BYREF prstInfo AS JET_RSTINFO_W _                    ' __in_opt JET_RSTINFO_W   *prstInfo
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT            grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetInit3 = JetInit3W
#ENDIF
   MACRO JetInit3 = JetInit3A
#ENDIF ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateInstance function allocates a new instance of the database engine for use
' in a single process.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetCreateInstance IMPORT "ESENT.DLL" ALIAS "JetCreateInstance" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS ASCIIZ _                     ' __in_opt const tchar* szInstanceName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetCreateInstance2 function is used to allocate a new instance of the database
' engine for use in a single process, with a display name specified.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetCreateInstance2 IMPORT "ESENT.DLL" ALIAS "JetCreateInstance2" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS ASCIIZ _                     ' __in_opt JET_PCSTR szInstanceName
 , BYREF szDisplayName AS ASCIIZ _                      ' __in_opt JET_PCSTR szDisplayName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION < 0x0600
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateInstanceA IMPORT "ESENT.DLL" ALIAS "JetCreateInstanceA" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS ASCIIZ _                     ' __in_opt JET_PCSTR szInstanceName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateInstanceW IMPORT "ESENT.DLL" ALIAS "JetCreateInstanceW" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS WSTRINGZ _                   ' __in_opt JET_PCWSTR szInstanceName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateInstance = JetCreateInstanceW
#ELSE
   MACRO JetCreateInstance = JetCreateInstanceA
#ENDIF
' ========================================================================================
DECLARE FUNCTION JetCreateInstance2A IMPORT "ESENT.DLL" ALIAS "JetCreateInstance2A" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS ASCIIZ _                     ' __in_opt JET_PCSTR szInstanceName
 , BYREF szDisplayName AS ASCIIZ _                      ' __in_opt JET_PCSTR szDisplayName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateInstance2W IMPORT "ESENT.DLL" ALIAS "JetCreateInstance2W" ( _
   BYREF pinstance AS DWORD _                           ' __out JET_INSTANCE* pinstance
 , BYREF szInstanceName AS WSTRINGZ _                   ' __in_opt JET_PCWSTR szInstanceName
 , BYREF szDisplayName AS WSTRINGZ _                    ' __in_opt JET_PCWSTR szDisplayName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateInstance2 = JetCreateInstance2W
#ELSE
   MACRO JetCreateInstance2 = JetCreateInstance2A
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetGetInstanceMiscInfo IMPORT "ESENT.DLL" ALIAS "JetGetInstanceMiscInfo" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE            instance
 , BYREF pvResult AS ANY _                              ' __out_bcount( cbMax ) void * pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long           cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long           InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0600

' ========================================================================================
' The JetTerm function initiates the shutdown of an instance that has been initialized
' by JetInit. JetTerm can also be used to destroy an uninitialized instance that was
' created by JetCreateInstance.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetTerm IMPORT "ESENT.DLL" ALIAS "JetTerm" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetTerm2 function initiates the shutdown of an instance that has been initialized
' by JetInit. JetTerm2 can also destroy an uninitialized instance that was created by
' JetCreateInstance.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetTerm2 IMPORT "ESENT.DLL" ALIAS "JetTerm2" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetStopService function prepares an instance for termination.
' JetStopService is the legacy call when only one instance is allowed. In this case, the
' only active instance is the one being prepared for termination.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetStopService IMPORT "ESENT.DLL" ALIAS "JetStopService" () AS LONG
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetStopServiceInstance function prepares an instance for termination.
' Requires Windows or Vista Windows XP
' ========================================================================================
DECLARE FUNCTION JetStopServiceInstance IMPORT "ESENT.DLL" ALIAS "JetStopServiceInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetStopBackup function prevents any streaming backup-related activity from
' continuing on a specific running instance, thus ending the streaming backup in a
' predictable way.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetStopBackup IMPORT "ESENT.DLL" ALIAS "JetStopBackup" () AS LONG
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetStopBackupInstance function prevents streaming backup-related activity from
' continuing on a specific running instance, thus ending the streaming backup in a
' predictable way.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetStopBackupInstance IMPORT "ESENT.DLL" ALIAS "JetStopBackupInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetSystemParameter function is used to set the numerous configuration settings
' of the database engine.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetSystemParameter IMPORT "ESENT.DLL" ALIAS "JetSetSystemParameter" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE* pinstance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYVAL lParam AS DWORD _                              ' __in JET_API_PTR lParam
 , BYREF szParam AS ASCIIZ _                            ' __in_opt JET_PCSTR szParam
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetSystemParameterA IMPORT "ESENT.DLL" ALIAS "JetSetSystemParameterA" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE* pinstance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYVAL lParam AS DWORD _                              ' __in JET_API_PTR lParam
 , BYREF szParam AS ASCIIZ _                            ' __in_opt JET_PCSTR szParam
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetSystemParameterW IMPORT "ESENT.DLL" ALIAS "JetSetSystemParameterW" ( _
   BYREF pinstance AS DWORD _                           ' __inout_opt JET_INSTANCE* pinstance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYVAL lParam AS DWORD _                              ' __in JET_API_PTR lParam
 , BYREF szParam AS WSTRINGZ _                          ' __in_opt JET_PCWSTR szParam
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetSystemParameter = JetSetSystemParameterW
#ELSE
   MACRO JetSetSystemParameter = JetSetSystemParameterA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetSystemParameter function reads the numerous configuration settings of the
' database engine.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetSystemParameter IMPORT "ESENT.DLL" ALIAS "JetGetSystemParameter" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYREF plParam AS DWORD _                             ' __inout_opt JET_API_PTR* plParam
 , BYREF szParam AS ASCIIZ _                            ' __out_opt JET_PSTR szParam
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetSystemParameterA IMPORT "ESENT.DLL" ALIAS "JetGetSystemParameterA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYREF plParam AS DWORD _                             ' __inout_opt JET_API_PTR* plParam
 , BYREF szParam AS ASCIIZ _                            ' __out_opt JET_PSTR szParam
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetSystemParameterW IMPORT "ESENT.DLL" ALIAS "JetGetSystemParameterW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL paramid AS DWORD _                             ' __in unsigned long paramid
 , BYREF plParam AS DWORD _                             ' __inout_opt JET_API_PTR* plParam
 , BYREF szParam AS WSTRINGZ _                          ' __out_opt JET_PWSTR szParam
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetSystemParameter = JetGetSystemParameterW
#ELSE
   MACRO JetGetSystemParameter = JetGetSystemParameterA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetEnableMultiInstance function configures the database engine for use with
' multiple instances in the same process. An optional array of global system parameters
' is available to the first caller allowing for the change to multi-instance mode.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetEnableMultiInstance IMPORT "ESENT.DLL" ALIAS "JetEnableMultiInstance" ( _
   BYREF psetsysparam AS JET_SETSYSPARAM _              ' __in_opt [array] JET_SETSYSPARAM* psetsysparam
 , BYVAL csetsysparam AS DWORD _                        ' __in_opt unsigned long csetsysparam
 , BYVAL pcsetsucceed AS DWORD _                        ' __out_opt unsigned long* pcsetsucceed
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetEnableMultiInstanceA IMPORT "ESENT.DLL" ALIAS "JetEnableMultiInstanceA" ( _
   BYREF psetsysparam AS JET_SETSYSPARAM_A _            ' __in_opt [array] JET_SETSYSPARAM_A* psetsysparam
 , BYVAL csetsysparam AS DWORD _                        ' __in_opt unsigned long csetsysparam
 , BYVAL pcsetsucceed AS DWORD _                        ' __out_opt unsigned long* pcsetsucceed
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetEnableMultiInstanceW IMPORT "ESENT.DLL" ALIAS "JetEnableMultiInstanceW" ( _
   BYREF psetsysparam AS JET_SETSYSPARAM_W _            ' __in_opt [array] JET_SETSYSPARAM_W* psetsysparam
 , BYVAL csetsysparam AS DWORD _                        ' __in_opt unsigned long csetsysparam
 , BYVAL pcsetsucceed AS DWORD _                        ' __out_opt unsigned long* pcsetsucceed
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetEnableMultiInstance = JetEnableMultiInstanceW
#ELSE
   MACRO JetEnableMultiInstance = JetEnableMultiInstanceA
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetGetThreadStats IMPORT "ESENT.DLL" ALIAS "JetGetThreadStats" ( _
   BYREF pvResult AS ANY _                              ' __out_bcount( cbMax ) void * pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long           cbMax
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetBeginSession function starts a session and initializes and returns an ESE
' session handle (JET_SESID). Sessions control all access to the database and are used
' to control the scope of transactions. The session can be used to begin, commit, or
' abort transactions. The session is also used to attach, create, or open a database.
' The session is used as the context for all DDL and DML operations. To increase
' concurrency and parallel access to the database, multiple sessions can be begun.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetBeginSession IMPORT "ESENT.DLL" ALIAS "JetBeginSession" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL psesid AS DWORD _                              ' __out JET_SESID* psesid
 , BYREF szUserName AS ASCIIZ _                         ' __in_opt JET_PCSTR szUserName
 , BYREF szPassword AS ASCIIZ _                         ' __in_opt JET_PCSTR szPassword
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetBeginSessionA IMPORT "ESENT.DLL" ALIAS "JetBeginSessionA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL psesid AS DWORD _                              ' __out JET_SESID* psesid
 , BYREF szUserName AS ASCIIZ _                         ' __in_opt JET_PCSTR szUserName
 , BYREF szPassword AS ASCIIZ _                         ' __in_opt JET_PCSTR szPassword
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetBeginSessionW IMPORT "ESENT.DLL" ALIAS "JetBeginSessionW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL psesid AS DWORD _                              ' __out JET_SESID* psesid
 , BYREF szUserName AS WSTRINGZ _                       ' __in_opt JET_PCWSTR szUserName
 , BYREF szPassword AS WSTRINGZ _                       ' __in_opt JET_PCWSTR szPassword
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetBeginSession = JetBeginSessionW
#ELSE
   MACRO JetBeginSession = JetBeginSessionA
#ENDIF
#ENDIF

' ========================================================================================
' The JetDupSession function starts a session, and initializes and returns an ESE
' session handle (JET_SESID). Sessions control all access to the database and are used
' to control the scope of transactions. The session can be used to begin, commit, or
' abort transactions. The session is also used to attach, create, or open a database.
' The session is used as the context for all DDL and DML operations. To increase
' concurrency and parallel access to the database, multiple sessions can be begun.
' Note  This API will act in all ways as a JetBeginSession called on the instance of the
' session passed in. This function is not recommended, JetBeginSession is preferred.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDupSession IMPORT "ESENT.DLL" ALIAS "JetDupSession" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF psesid AS DWORD _                              ' __out JET_SESID* psesid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetEndSession function ends the session, and cleans up and deallocates any
' resources associated with the specified session.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetEndSession IMPORT "ESENT.DLL" ALIAS "JetEndSession" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGetVersion function retrieves the version of the database engine.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetVersion IMPORT "ESENT.DLL" ALIAS "JetGetVersion" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF pwVersion AS DWORD _                           ' __out unsigned long* pwVersion
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetIdle function is defunct, and should only be used for testing purposes. JetIdle
' can be used to perform idle cleanup tasks or check the version store status in ESE.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetIdle IMPORT "ESENT.DLL" ALIAS "JetIdle" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateDatabase function creates and attaches a database file to be used with
' the ESE database engine. Calling JetCreateDatabase2 with cpgDatabaseSizeMax set to
' zero is identical to calling JetCreateDatabase with szConnect set to NULL. Currently,
' up to seven databases can be created per instance.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateDatabase IMPORT "ESENT.DLL" ALIAS "JetCreateDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYREF szConnect AS ASCIIZ _                          ' __in_opt JET_PCSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateDatabaseA IMPORT "ESENT.DLL" ALIAS "JetCreateDatabaseA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYREF szConnect AS ASCIIZ _                          ' __in_opt JET_PCSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateDatabaseW IMPORT "ESENT.DLL" ALIAS "JetCreateDatabaseW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYREF szConnect AS WSTRINGZ _                        ' __in_opt JET_PCWSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateDatabase = JetCreateDatabaseW
#ELSE
   MACRO JetCreateDatabase = JetCreateDatabaseA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateDatabase2 function creates and attaches a database file to be used with
' the ESE database engine with a maximum database size specified. Calling
' JetCreateDatabase2 with cpgDatabaseSizeMax set to zero is identical to calling
' JetCreateDatabase with szConnect set to NULL. Currently up to seven databases can be
' created per instance.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateDatabase2 IMPORT "ESENT.DLL" ALIAS "JetCreateDatabase2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateDatabase2A IMPORT "ESENT.DLL" ALIAS "JetCreateDatabase2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateDatabase2W IMPORT "ESENT.DLL" ALIAS "JetCreateDatabase2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateDatabase2 = JetCreateDatabase2W
#ELSE
   MACRO JetCreateDatabase2 = JetCreateDatabase2A
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetAttachDatabase function attaches a database file for use with a database
' instance. In order to use the database, it will need to be subsequently opened with
' JetOpenDatabase.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetAttachDatabase IMPORT "ESENT.DLL" ALIAS "JetAttachDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetAttachDatabaseA IMPORT "ESENT.DLL" ALIAS "JetAttachDatabaseA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetAttachDatabaseW IMPORT "ESENT.DLL" ALIAS "JetAttachDatabaseW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetAttachDatabase = JetAttachDatabaseW
#ELSE
   MACRO JetAttachDatabase = JetAttachDatabaseA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetAttachDatabase2 function attaches a database file for use with a database
' instance and specifies a maximum size for that database. In order to use the database,
' it will need to be subsequently opened with JetOpenDatabase.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetAttachDatabase2 IMPORT "ESENT.DLL" ALIAS "JetAttachDatabase2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetAttachDatabase2A IMPORT "ESENT.DLL" ALIAS "JetAttachDatabase2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetAttachDatabase2W IMPORT "ESENT.DLL" ALIAS "JetAttachDatabase2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYVAL cpgDatabaseSizeMax AS DWORD _                  ' __in const unsigned long cpgDatabaseSizeMax
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetAttachDatabase2 = JetAttachDatabase2W
#ELSE
   MACRO JetAttachDatabase2 = JetAttachDatabase2A
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDetachDatabase function releases a database file that was previously attached
' to a database session.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDetachDatabase IMPORT "ESENT.DLL" ALIAS "JetDetachDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDetachDatabaseA IMPORT "ESENT.DLL" ALIAS "JetDetachDatabaseA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDetachDatabaseW IMPORT "ESENT.DLL" ALIAS "JetDetachDatabaseW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDetachDatabase = JetDetachDatabaseW
#ELSE
   MACRO JetDetachDatabase = JetDetachDatabaseA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDetachDatabase2 function releases a database file that was previously attached
' to a database session.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetDetachDatabase2 IMPORT "ESENT.DLL" ALIAS "JetDetachDatabase2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDetachDatabase2A IMPORT "ESENT.DLL" ALIAS "JetDetachDatabase2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDetachDatabase2W IMPORT "ESENT.DLL" ALIAS "JetDetachDatabase2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDetachDatabase2 = JetDetachDatabase2W
#ELSE
   MACRO JetDetachDatabase2 = JetDetachDatabase2A
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetObjectInfo function retrieves information about database objects. Currently,
' only tables are supported. JetGetTableInfo can be used to fetch more information than
' JetGetObjectInfo.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetObjectInfo IMPORT "ESENT.DLL" ALIAS "JetGetObjectInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYVAL objtyp AS DWORD _                              ' __in JET_OBJTYP objtyp
 , BYREF szContainerName AS ASCIIZ _                    ' __in_opt JET_PCSTR szContainerName
 , BYREF szObjectName AS ASCIIZ _                       ' __in_opt JET_PCSTR szObjectName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetObjectInfoA IMPORT "ESENT.DLL" ALIAS "JetGetObjectInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYVAL objtyp AS DWORD _                              ' __in JET_OBJTYP objtyp
 , BYREF szContainerName AS ASCIIZ _                    ' __in_opt JET_PCSTR szContainerName
 , BYREF szObjectName AS ASCIIZ _                       ' __in_opt JET_PCSTR szObjectName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetObjectInfoW IMPORT "ESENT.DLL" ALIAS "JetGetObjectInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYVAL objtyp AS DWORD _                              ' __in JET_OBJTYP objtyp
 , BYREF szContainerName AS WSTRINGZ _                  ' __in_opt JET_PCWSTR szContainerName
 , BYREF szObjectName AS WSTRINGZ _                     ' __in_opt JET_PCWSTR szObjectName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetObjectInfo = JetGetObjectInfoW
#ELSE
   MACRO JetGetObjectInfo = JetGetObjectInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetTableInfo function retrieves various pieces of information about a table in
' a database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetTableInfo IMPORT "ESENT.DLL" ALIAS "JetGetTableInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetTableInfoA IMPORT "ESENT.DLL" ALIAS "JetGetTableInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetTableInfoW IMPORT "ESENT.DLL" ALIAS "JetGetTableInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetTableInfo = JetGetTableInfoW
#ELSE
   MACRO JetGetTableInfo = JetGetTableInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateTable function creates an empty table in an ESE database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateTable IMPORT "ESENT.DLL" ALIAS "JetCreateTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYVAL lPages AS DWORD _                              ' __in unsigned long lPages
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateTableA IMPORT "ESENT.DLL" ALIAS "JetCreateTableA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYVAL lPages AS DWORD _                              ' __in unsigned long lPages
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateTableW IMPORT "ESENT.DLL" ALIAS "JetCreateTableW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 , BYVAL lPages AS DWORD _                              ' __in unsigned long lPages
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateTable = JetCreateTableW
#ELSE
   MACRO JetCreateTable = JetCreateTableA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateTableColumnIndex function creates a table in an ESE database with an
' initial set of indexes and an initial set of columns from an array of JET_TABLECREATE
' structures. The name JetCreateTableColumnIndex comes from the order of creation of the
' objects. It first creates a table, columns, and then finally indexes.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE _              ' __inout JET_TABLECREATE* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndexA IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndexA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE_A _            ' __inout JET_TABLECREATE_A* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndexW IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndexW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE_W _            ' __inout JET_TABLECREATE_W* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateTableColumnIndex = JetCreateTableColumnIndexW
#ELSE
   MACRO JetCreateTableColumnIndex = JetCreateTableColumnIndexA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateTableColumnIndex2 function creates a table in an ESE database with an
' initial set of indexes and an initial set of columns from an array of JET_TABLECREATE2
' structures The JET_TABLECREATE2 structure allows a callback function to be specified.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex2 IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE2 _             ' __inout JET_TABLECREATE2* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex2A IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE2_A _           ' __inout JET_TABLECREATE2_A* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex2W IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE2_W _           ' __inout JET_TABLECREATE2_W* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateTableColumnIndex2 = JetCreateTableColumnIndex2W
#ELSE
   MACRO JetCreateTableColumnIndex2 = JetCreateTableColumnIndex2A
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0600
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0601
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex3A IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex3A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE3_A _           ' __inout JET_TABLECREATE3_A* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateTableColumnIndex3W IMPORT "ESENT.DLL" ALIAS "JetCreateTableColumnIndex3W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF ptablecreate AS JET_TABLECREATE3_W _           ' __inout JET_TABLECREATE3_W* ptablecreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateTableColumnIndex3 = JetCreateTableColumnIndex3W
#ELSE
   MACRO JetCreateTableColumnIndex3 = JetCreateTableColumnIndex3A
#ENDIF
#ENDIF   ' // JET_VERSION >= 0x0601

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDeleteTable function deletes a table in an ESE database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDeleteTable IMPORT "ESENT.DLL" ALIAS "JetDeleteTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDeleteTableA IMPORT "ESENT.DLL" ALIAS "JetDeleteTableA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDeleteTableW IMPORT "ESENT.DLL" ALIAS "JetDeleteTableW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDeleteTable = JetDeleteTableW
#ELSE
   MACRO JetDeleteTable = JetDeleteTableA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetRenameTable function can be used to change the name of an existing table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRenameTable IMPORT "ESENT.DLL" ALIAS "JetRenameTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szName AS ASCIIZ _                             ' __in JET_PCSTR szName
 , BYREF szNameNew AS ASCIIZ _                          ' __in JET_PCSTR szNameNew
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetRenameTableA IMPORT "ESENT.DLL" ALIAS "JetRenameTableA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szName AS ASCIIZ _                             ' __in JET_PCSTR szName
 , BYREF szNameNew AS ASCIIZ _                          ' __in JET_PCSTR szNameNew
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetRenameTableW IMPORT "ESENT.DLL" ALIAS "JetRenameTableW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szName AS WSTRINGZ _                           ' __in JET_PCWSTR szName
 , BYREF szNameNew AS WSTRINGZ _                        ' __in JET_PCWSTR szNameNew
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetRenameTable = JetRenameTableW
#ELSE
   MACRO JetRenameTable = JetRenameTableA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetTableColumnInfo function retrieves information about a table column.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetTableColumnInfo IMPORT "ESENT.DLL" ALIAS "JetGetTableColumnInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetTableColumnInfoA IMPORT "ESENT.DLL" ALIAS "JetGetTableColumnInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetTableColumnInfoW IMPORT "ESENT.DLL" ALIAS "JetGetTableColumnInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetTableColumnInfo = JetGetTableColumnInfoW
#ELSE
   MACRO JetGetTableColumnInfo = JetGetTableColumnInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetColumnInfo function retrieves information about a column.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetColumnInfo IMPORT "ESENT.DLL" ALIAS "JetGetColumnInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetColumnInfoA IMPORT "ESENT.DLL" ALIAS "JetGetColumnInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetColumnInfoW IMPORT "ESENT.DLL" ALIAS "JetGetColumnInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetColumnInfo = JetGetColumnInfoW
#ELSE
   MACRO JetGetColumnInfo = JetGetColumnInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetAddColumn function adds a new column to an existing table in an ESE database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetAddColumn IMPORT "ESENT.DLL" ALIAS "JetAddColumn" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pcolumndef AS JET_COLUMNDEF _                  ' __in const JET_COLUMNDEF* pcolumndef
 , BYREF pvDefault AS ANY _                             ' __in_opt const void* pvDefault
 , BYVAL cbDefault AS DWORD _                           ' __in unsigned long cbDefault
 , BYREF pcolumnid AS DWORD _                           ' __in JET_COLUMNID* pcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetAddColumnA IMPORT "ESENT.DLL" ALIAS "JetAddColumnA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pcolumndef AS JET_COLUMNDEF _                  ' __in const JET_COLUMNDEF* pcolumndef
 , BYREF pvDefault AS ANY _                             ' __in_opt const void* pvDefault
 , BYVAL cbDefault AS DWORD _                           ' __in unsigned long cbDefault
 , BYREF pcolumnid AS DWORD _                           ' __in JET_COLUMNID* pcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetAddColumnW IMPORT "ESENT.DLL" ALIAS "JetAddColumnW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 , BYREF pcolumndef AS JET_COLUMNDEF _                  ' __in const JET_COLUMNDEF* pcolumndef
 , BYREF pvDefault AS ANY _                             ' __in_opt const void* pvDefault
 , BYVAL cbDefault AS DWORD _                           ' __in unsigned long cbDefault
 , BYREF pcolumnid AS DWORD _                           ' __in JET_COLUMNID* pcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetAddColumn = JetAddColumnW
#ELSE
   MACRO JetAddColumn = JetAddColumnA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDeleteColumn function deletes a column from an ESE database table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDeleteColumn IMPORT "ESENT.DLL" ALIAS "JetDeleteColumn" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDeleteColumnA IMPORT "ESENT.DLL" ALIAS "JetDeleteColumnA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDeleteColumnW IMPORT "ESENT.DLL" ALIAS "JetDeleteColumnW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDeleteColumn = JetDeleteColumnW
#ELSE
   MACRO JetDeleteColumn = JetDeleteColumnA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDeleteColumn2 function deletes a column from an ESE database table and enables
' a grbit option to be set.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetDeleteColumn2 IMPORT "ESENT.DLL" ALIAS "JetDeleteColumn2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetRenameColumn function can be used to change the name of an existing column on
' a table.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetRenameColumn IMPORT "ESENT.DLL" ALIAS "JetRenameColumn" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szName AS ASCIIZ _                             ' __in JET_PCSTR szName
 , BYREF szNameNew AS ASCIIZ _                          ' __in JET_PCSTR szNameNew
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDeleteColumn2A IMPORT "ESENT.DLL" ALIAS "JetDeleteColumn2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDeleteColumn2W IMPORT "ESENT.DLL" ALIAS "JetDeleteColumn2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDeleteColumn2 = JetDeleteColumn2W
#ELSE
   MACRO JetDeleteColumn2 = JetDeleteColumn2A
#ENDIF
' ========================================================================================
DECLARE FUNCTION JetRenameColumnA IMPORT "ESENT.DLL" ALIAS "JetRenameColumnA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szName AS ASCIIZ _                             ' __in JET_PCSTR szName
 , BYREF szNameNew AS ASCIIZ _                          ' __in JET_PCSTR szNameNew
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetRenameColumnW IMPORT "ESENT.DLL" ALIAS "JetRenameColumnW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szName AS WSTRINGZ _                           ' __in JET_PCWSTR szName
 , BYREF szNameNew AS WSTRINGZ _                        ' __in JET_PCWSTR szNameNew
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetRenameColumn = JetRenameColumnW
#ELSE
   MACRO JetRenameColumn = JetRenameColumnA
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetColumnDefaultValue function can be used to change the default value of an
' existing column.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetColumnDefaultValue IMPORT "ESENT.DLL" ALIAS "JetSetColumnDefaultValue" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvData AS ANY _                                ' __in const void* pvData
 , BYVAL cbData AS DWORD _                              ' __in const unsigned long cbData
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetColumnDefaultValueA IMPORT "ESENT.DLL" ALIAS "JetSetColumnDefaultValueA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF szColumnName AS ASCIIZ _                       ' __in JET_PCSTR szColumnName
 , BYREF pvData AS ANY _                                ' __in const void* pvData
 , BYVAL cbData AS DWORD _                              ' __in const unsigned long cbData
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetColumnDefaultValueW IMPORT "ESENT.DLL" ALIAS "JetSetColumnDefaultValueW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 , BYREF szColumnName AS WSTRINGZ _                     ' __in JET_PCWSTR szColumnName
 , BYREF pvData AS ANY _                                ' __in const void* pvData
 , BYVAL cbData AS DWORD _                              ' __in const unsigned long cbData
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetColumnDefaultValue = JetSetColumnDefaultValueW
#ELSE
   MACRO JetSetColumnDefaultValue = JetSetColumnDefaultValueA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetTableIndexInfo function retrieves information about an index.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetTableIndexInfo IMPORT "ESENT.DLL" ALIAS "JetGetTableIndexInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetTableIndexInfoA IMPORT "ESENT.DLL" ALIAS "JetGetTableIndexInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetTableIndexInfoW IMPORT "ESENT.DLL" ALIAS "JetGetTableIndexInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ _                      ' __in JET_PCWSTR szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetTableIndexInfo = JetGetTableIndexInfoW
#ELSE
   MACRO JetGetTableIndexInfo = JetGetTableIndexInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetIndexInfo function retrieves information about an index.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetIndexInfo IMPORT "ESENT.DLL" ALIAS "JetGetIndexInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in const tchar* szTableName
 , BYREF szIndexName AS ASCIIZ _                        ' __in const tchar* szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetIndexInfoA IMPORT "ESENT.DLL" ALIAS "JetGetIndexInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetIndexInfoW IMPORT "ESENT.DLL" ALIAS "JetGetIndexInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 , BYREF szIndexName AS WSTRINGZ _                      ' __in JET_PCWSTR szIndexName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbResult AS DWORD _                            ' __in unsigned long cbResult
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetIndexInfo = JetGetIndexInfoW
#ELSE
   MACRO JetGetIndexInfo = JetGetIndexInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateIndex function creates an index over data in an ESE database, which can
' be used to locate specific data quickly.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateIndex IMPORT "ESENT.DLL" ALIAS "JetCreateIndex" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF szKey AS ASCIIZ _                              ' __in const tchar* szKey
 , BYVAL cbKey AS DWORD _                               ' __in unsigned long cbKey
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateIndexA IMPORT "ESENT.DLL" ALIAS "JetCreateIndexA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF szKey AS ASCIIZ _                              ' __in JET_PCSTR szKey
 , BYVAL cbKey AS DWORD _                               ' __in unsigned long cbKey
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateIndexW IMPORT "ESENT.DLL" ALIAS "JetCreateIndexW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ  _                     ' __in JET_PCWSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF szKey AS ASCIIZ _                              ' __in JET_PCWSTR szKey
 , BYVAL cbKey AS DWORD _                               ' __in unsigned long cbKey
 , BYVAL lDensity AS DWORD _                            ' __in unsigned long lDensity
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateIndex = JetCreateIndexW
#ELSE
   MACRO JetCreateIndex = JetCreateIndexA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCreateIndex2 function creates indexes over data in an ESE database, which can
' be used to locate specific data quickly.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCreateIndex2 IMPORT "ESENT.DLL" ALIAS "JetCreateIndex2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pindexcreate AS JET_INDEXCREATE _              ' __in JET_INDEXCREATE* pindexcreate
 , BYVAL cIndexCreate AS DWORD _                        ' __in unsigned long cIndexCreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCreateIndex2A IMPORT "ESENT.DLL" ALIAS "JetCreateIndex2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pindexcreate AS JET_INDEXCREATE_A _            ' __in JET_INDEXCREATE_A* pindexcreate
 , BYVAL cIndexCreate AS DWORD _                        ' __in unsigned long cIndexCreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateIndex2W IMPORT "ESENT.DLL" ALIAS "JetCreateIndex2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pindexcreate AS JET_INDEXCREATE_W _            ' __in JET_INDEXCREATE_W* pindexcreate
 , BYVAL cIndexCreate AS DWORD _                        ' __in unsigned long cIndexCreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateIndex2 = JetCreateIndex2W
#ELSE
   MACRO JetCreateIndex2 = JetCreateIndex2A
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0601
' ========================================================================================
DECLARE FUNCTION JetCreateIndex3A IMPORT "ESENT.DLL" ALIAS "JetCreateIndex3A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pindexcreate AS JET_INDEXCREATE2_A _           ' __in JET_INDEXCREATE2_A* pindexcreate
 , BYVAL cIndexCreate AS DWORD _                        ' __in unsigned long cIndexCreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCreateIndex3W IMPORT "ESENT.DLL" ALIAS "JetCreateIndex3W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pindexcreate AS JET_INDEXCREATE2_W _           ' __in JET_INDEXCREATE2_W* pindexcreate
 , BYVAL cIndexCreate AS DWORD _                        ' __in unsigned long cIndexCreate
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCreateIndex3 = JetCreateIndex3W
#ELSE
   MACRO JetCreateIndex3 = JetCreateIndex3A
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDeleteIndex function deletes an index from a table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDeleteIndex IMPORT "ESENT.DLL" ALIAS "JetDeleteIndex" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDeleteIndexA IMPORT "ESENT.DLL" ALIAS "JetDeleteIndexA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in JET_PCSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDeleteIndexW IMPORT "ESENT.DLL" ALIAS "JetDeleteIndexW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ _                      ' __in JET_PCWSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDeleteIndex = JetDeleteIndexW
#ELSE
   MACRO JetDeleteIndex = JetDeleteIndexA
#ENDIF
#ENDIF

' ========================================================================================
' The JetBeginTransaction function causes a session to enter a transaction and create a
' new save point. This function can be called more than once on a single session to
' cause the creation of additional save points. These save points can be used to
' selectively keep or discard changes to the state of the database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetBeginTransaction IMPORT "ESENT.DLL" ALIAS "JetBeginTransaction" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetBeginTransaction2 function causes a session to enter a transaction and create a
' new save point. This function can be called more than once in a single session to create
' additional save points. These save points can be used to selectively to keep or discard
' changes to the database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetBeginTransaction2 IMPORT "ESENT.DLL" ALIAS "JetBeginTransaction2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetCommitTransaction function commits the changes made to the state of the
' database during the current save point and migrates them to the previous save point.
' If the outermost save point is committed then the changes made during that save point
' will be committed to the state of the database and the session will exit the
' transaction.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCommitTransaction IMPORT "ESENT.DLL" ALIAS "JetCommitTransaction" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetRollback function undoes the changes made to the state of the database and
' returns to the last save point. JetRollback will also close any cursors opened during
' the save point. If the outermost save point is undone, the session will exit the
' transaction.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRollback IMPORT "ESENT.DLL" ALIAS "JetRollback" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetDatabaseInfo function retrieves various types of information about the
' database. This API can be called while a database is attached or online (with
' JetGetDatabaseInfo) or while the database or database engine is offline (with
' JetGetDatabaseFileInfo).
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseInfo IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseInfoA IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseInfoA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseInfoW IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseInfoW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetDatabaseInfo = JetGetDatabaseInfoW
#ELSE
   MACRO JetGetDatabaseInfo = JetGetDatabaseInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetDatabaseFileInfo function retrieves various types of information about the
' database. This API can be called while a database is attached or online (with
' JetGetDatabaseInfo) or while the database or database engine is offline (with
' JetGetDatabaseFileInfo).
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseFileInfo IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseFileInfo" ( _
   BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseFileInfoA IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseFileInfoA" ( _
   BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetDatabaseFileInfoW IMPORT "ESENT.DLL" ALIAS "JetGetDatabaseFileInfoW" ( _
   BYREF szDatabaseName AS WSTRINGZ _                   ' __in JET_PCWSTR szDatabaseName
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetDatabaseFileInfo = JetGetDatabaseFileInfoW
#ELSE
   MACRO JetGetDatabaseFileInfo = JetGetDatabaseFileInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetOpenDatabasefunction opens a previously attached database, using the
' JetAttachDatabase or JetAttachDatabase2 functions, for use with a database session.
' This function can be called multiple times for the same database.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenDatabase IMPORT "ESENT.DLL" ALIAS "JetOpenDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYREF szConnect AS ASCIIZ _                          ' __in JET_PCSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetOpenDatabaseA IMPORT "ESENT.DLL" ALIAS "JetOpenDatabaseA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS ASCIIZ _                         ' __in JET_PCSTR szFilename
 , BYREF szConnect AS ASCIIZ _                          ' __in JET_PCSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOpenDatabaseW IMPORT "ESENT.DLL" ALIAS "JetOpenDatabaseW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szFilename AS WSTRINGZ _                       ' __in JET_PCWSTR szFilename
 , BYREF szConnect AS WSTRINGZ  _                       ' __in JET_PCWSTR szConnect
 , BYREF pdbid AS DWORD _                               ' __out JET_DBID* pdbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOpenDatabase = JetOpenDatabaseW
#ELSE
   MACRO JetOpenDatabase = JetOpenDatabaseA
#ENDIF
#ENDIF

' ========================================================================================
' The JetCloseDatabase function closes a database file that was previously opened with
' JetOpenDatabase.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCloseDatabase IMPORT "ESENT.DLL" ALIAS "JetCloseDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetOpenTable function opens a cursor on a previously created table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenTable IMPORT "ESENT.DLL" ALIAS "JetOpenTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYVAL pvParameters AS DWORD _                        ' __in const void* pvParameters
 , BYVAL cbParameters AS DWORD _                        ' __in unsigned long cbParameters,
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetOpenTableA IMPORT "ESENT.DLL" ALIAS "JetOpenTableA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYVAL pvParameters AS DWORD _                        ' __in const void* pvParameters
 , BYVAL cbParameters AS DWORD _                        ' __in unsigned long cbParameters,
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOpenTableW IMPORT "ESENT.DLL" ALIAS "JetOpenTableW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ  _                     ' __in JET_PCWSTR szTableName
 , BYVAL pvParameters AS DWORD _                        ' __in const void* pvParameters
 , BYVAL cbParameters AS DWORD _                        ' __in unsigned long cbParameters
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOpenTable = JetOpenTableW
#ELSE
   MACRO JetOpenTable = JetOpenTableA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetSetTableSequential function notifies the database engine that the application
' is scanning the entire current index that contains a given cursor. Consequently, the
' methods that are used to access the index data will be tuned to make this scenario as
' fast as possible.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetSetTableSequential IMPORT "ESENT.DLL" ALIAS "JetSetTableSequential" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetResetTableSequential function notifies the database engine that the application
' is no longer scanning the entire current index containing a given cursor. This call
' reverses a notification sent by JetSetTableSequential.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetResetTableSequential IMPORT "ESENT.DLL" ALIAS "JetResetTableSequential" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetCloseTable function closes an open table in a database. The table may be a
' temporary table or a normal table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCloseTable IMPORT "ESENT.DLL" ALIAS "JetCloseTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetDelete function deletes the current record in a database table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDelete IMPORT "ESENT.DLL" ALIAS "JetDelete" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetUpdate function performs an update operation including inserting a new row into
' a table or updating an existing row. Deleting a table row is performed by calling
' JetDelete.
' JetUpdate is the final step in performing an insert or an update. The update is begun
' by calling JetPrepareUpdate and then by calling JetSetColumn or JetSetColumns one or
' more times to set the record state. Finally, JetUpdate is called to complete the
' update operation. Indexes are updated only by JetUpdate or JetUpdate2, and not during
' JetSetColumn or JetSetColumns.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetUpdate IMPORT "ESENT.DLL" ALIAS "JetUpdate" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvBookmark AS ANY _                            ' __out void* pvBookmark
 , BYVAL cbBookmark AS DWORD _                          ' __in unsigned long cbBookmark
 , BYREF pcbActual AS DWORD _                           ' __in unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0502
' ========================================================================================
' The JetUpdate2 function performs an update operation including inserting a new row
' into a table or updating an existing row. This function contains a list of grbit
' options that can be set while performing an update. Deleting a table row is performed
' by calling JetDelete.
' Requires Windows Vista.
' ========================================================================================
DECLARE FUNCTION JetUpdate2 IMPORT "ESENT.DLL" ALIAS "JetUpdate2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvBookmark AS ANY _                            ' __out_opt void* pvBookmark
 , BYVAL cbBookmark AS DWORD _                          ' __in unsigned long cbBookmark
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= &H0502

' ========================================================================================
' The JetEscrowUpdate function performs an atomic addition operation on one column. This
' function allows multiple sessions to update the same record concurrently without
' conflicts.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetEscrowUpdate IMPORT "ESENT.DLL" ALIAS "JetEscrowUpdate" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL columnid AS DWORD _                            ' __in JET_COLUMNID columnid
 , BYREF pv AS ANY _                                    ' __out void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pvOld AS ANY _                                 ' __out_opt void* pvOld
 , BYVAL cbOldMax AS DWORD _                            ' __in unsigned long cbOldMax
 , BYREF pcbOldActual AS DWORD _                        ' __in unsigned long* pcbOldActual
 , BYVAL grbit AS DWORD _                               ' __out_opt JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetRetrieveColumn function retrieves a single column value from the current
' record. The record is that record associated with the index entry at the current
' position of the cursor. Alternatively, this function can retrieve a column from a
' record being created in the cursor copy buffer. This function can also retrieve column
' data from an index entry that references the current record. In addition to retrieving
' the actual column value, JetRetrieveColumn can also be used to retrieve the size of a
' column, before retrieving the column data itself so that application buffers can be
' sized appropriately.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRetrieveColumn IMPORT "ESENT.DLL" ALIAS "JetRetrieveColumn" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL columnid AS DWORD _                            ' __in JET_COLUMNID columnid
 , BYREF pvData AS ANY _                                ' __out_opt void* pvData
 , BYVAL cbData AS DWORD _                              ' __in unsigned long cbData
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF pretinfo AS JET_RETINFO _                      ' __inout_opt JET_RETINFO* pretinfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetRetrieveColumns function retrieves multiple column values from the current
' record in a single operation. An array of JET_RETRIEVECOLUMN structures is used to
' describe the set of column values to be retrieved, and to describe output buffers for
' each column value to be retrieved.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRetrieveColumns IMPORT "ESENT.DLL" ALIAS "JetRetrieveColumns" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pretrievecolumn AS JET_RETRIEVECOLUMN _        ' __inout_opt JET_RETRIEVECOLUMN* pretrievecolumn
 , BYVAL cretrievecolumn AS DWORD _                     ' __in unsigned long cretrievecolumn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetEnumerateColumns function efficiently retrieves a set of columns and their
' values from the current record of a cursor or the copy buffer of that cursor. The
' columns and values retrieved can be restricted by a list of column IDs, itagSequence
' numbers, and other characteristics. This column retrieval API is unique in that it
' returns information in dynamically allocated memory that is obtained using a
' user-provided realloc compatible callback. This new flexibility permits the efficient
' retrieval of column data with specific characteristics (such as size and multiplicity)
' that are unknown to the caller. This eliminates the need for the use of the discovery
' modes of JetRetrieveColumn to determine those characteristics in order to setup a
' final call to JetRetrieveColumn that will successfully retrieve the desired data.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetEnumerateColumns IMPORT "ESENT.DLL" ALIAS "JetEnumerateColumns" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL cEnumColumnId AS DWORD _                       ' __in unsigned long cEnumColumnId
 , BYREF rgEnumColumnId AS JET_ENUMCOLUMNID _           ' __in_opt JET_ENUMCOLUMNID* rgEnumColumnId
 , BYREF pcEnumColumn AS DWORD _                        ' __in unsigned long* pcEnumColumn
 , BYREF prgEnumColumn AS JET_ENUMCOLUMN _              ' __out JET_ENUMCOLUMN** prgEnumColumn
 , BYVAL pfnRealloc AS DWORD _                          ' __in JET_PFNREALLOC pfnRealloc
 , BYVAL pvReallocContext AS DWORD _                    ' __in void* pvReallocContext
 , BYVAL cbDataMost AS DWORD _                          ' __in unsigned long cbDataMost
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetGetRecordSize IMPORT "ESENT.DLL" ALIAS "JetGetRecordSize" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID        sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID      tableid
 , BYREF precsize AS JET_RECSIZE _                      ' __out JET_RECSIZE    *precsize
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT  grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601
' ========================================================================================
DECLARE FUNCTION JetGetRecordSize2 IMPORT "ESENT.DLL" ALIAS "JetGetRecordSize2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID        sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID      tableid
 , BYREF precsize AS JET_RECSIZE2 _                     ' __out JET_RECSIZE2   *precsize
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT  grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0601

' ========================================================================================
' The JetSetColumn function modifies a single column value in a modified record to be
' inserted or to update the current record. It can overwrite an existing value, add a
' new value to a sequence of values in a multi-valued column, remove a value from a
' sequence of values in a multi-valued column, or update all or part of a long value, a
' column of type JET_coltypLongText or JET_coltypeLongBinary.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetColumn IMPORT "ESENT.DLL" ALIAS "JetSetColumn" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL columnid AS DWORD _                            ' __in JET_COLUMNID columnid
 , BYREF pvData AS ANY _                                ' __in_opt const void* pvData
 , BYVAL cbData AS DWORD _                              ' __in unsigned long cbData
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF psetinfo AS JET_SETINFO _                      ' __in_opt JET_SETINFO* psetinfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetSetColumns function is similar in behavior to JetSetColumn but allows an
' application to set multiple column values in a single operation. An array of
' JET_SETCOLUMN structures is used to describe the set of column values to be set, and
' to describe input buffers for each column value to be set.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetColumns IMPORT "ESENT.DLL" ALIAS "JetSetColumns" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF psetcolumn AS JET_SETCOLUMN _                  ' __inout_opt JET_SETCOLUMN* psetcolumn
 , BYVAL csetcolumn AS DWORD _                          ' __in unsigned long csetcolumn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetPrepareUpdate function is the first operation in performing an update, for the
' purposes of inserting a new record or replacing an existing record with new values.
' Updates are done by calling JetPrepareUpdate, then calling JetSetColumn or
' JetSetColumns zero or more times and finally by calling JetUpdate to complete the
' operation. JetPrepareUpdate and JetUpdate set the boundaries for an update operation
' and are important in having only the final update state of a record entered into
' indexes. This is both more efficient, but also required in cases where data must match
' a valid state through more than on set column operation.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetPrepareUpdate IMPORT "ESENT.DLL" ALIAS "JetPrepareUpdate" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL prep AS DWORD _                                ' __in unsigned long prep
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGetRecordPosition function returns the fractional position of the current
' record in the current index in the form of a JET_RECPOS structure. This structure
' describes fractional positions in terms of an approximate number of index entries
' before the current record and an approximate total number of entries in the index.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetRecordPosition IMPORT "ESENT.DLL" ALIAS "JetGetRecordPosition" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF precpos AS JET_RECPOS _                        ' __out JET_RECPOS* precpos
 , BYVAL cbRecpos AS DWORD _                            ' __in unsigned long cbRecpos
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGotoPosition function moves a cursor to a new location that is a fraction of
' the way through the current index. The fraction is approximately equal to the
' following:
'    precpos.centriesLT/precpos.centriesTotal
' This operation is performed in response to user scroll box input that is received
' when the user attempts to show data that starts part way through a data set.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGotoPosition IMPORT "ESENT.DLL" ALIAS "JetGotoPosition" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF precpos AS JET_RECPOS _                        ' __in JET_RECPOS* precpos
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGetCursorInfo function is used to determine whether an update of the current
' record of a cursor will result in a write conflict, based on the current update status
' of the record. It is possible that a write conflict will ultimately be returned even if
' JetGetCursorInfo returns JET_errSuccess, because another session may update the record
' before the current session is able to update the same record.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetCursorInfo IMPORT "ESENT.DLL" ALIAS "JetGetCursorInfo" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvResult AS ANY _                              ' __out void* pvResult
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYVAL InfoLevel AS DWORD _                           ' __in unsigned long InfoLevel
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetDupCursor function duplicates an open cursor and returns a handle to the
' duplicated cursor. If the cursor that was duplicated was a read-only cursor then the
' duplicated cursor is also a read-only cursor. Any state related to constructing a
' search key or updating a record is not copied into the duplicated cursor. In addition,
' the location of the original cursor is not duplicated into the duplicated cursor. The
' duplicated cursor is always opened on the clustered index and its location is always
' on the first row of the table.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDupCursor IMPORT "ESENT.DLL" ALIAS "JetDupCursor" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetCurrentIndex function determines the name of the current index of a given
' cursor. This name is also used to later re-select that index as the current index
' using JetSetCurrentIndex. It can also be used to discover the properties of that index
' using JetGetTableIndexInfo.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetCurrentIndex IMPORT "ESENT.DLL" ALIAS "JetGetCurrentIndex" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in ET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __out JET_PSTR szIndexName
 , BYVAL cchIndexName AS DWORD _                        ' __in unsigned long cchIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetCurrentIndexA IMPORT "ESENT.DLL" ALIAS "JetGetCurrentIndexA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in ET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __out JET_PSTR szIndexName
 , BYVAL cchIndexName AS DWORD _                        ' __in unsigned long cchIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetCurrentIndexW IMPORT "ESENT.DLL" ALIAS "JetGetCurrentIndexW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in ET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ  _                     ' __out JET_PWSTR szIndexName
 , BYVAL cchIndexName AS DWORD _                        ' __in unsigned long cchIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetCurrentIndex = JetGetCurrentIndexW
#ELSE
   MACRO JetGetCurrentIndex = JetGetCurrentIndexA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetCurrentIndex function can be used to set the current index of a cursor. The
' current index of a cursor defines which records in a table are visible to that cursor
' and the order in which they appear by selecting the set of index entries to use to
' expose those records.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndexA IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndexA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndexW IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndexW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ _                      ' __in_opt JET_PCWSTR szIndexName
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetCurrentIndex = JetSetCurrentIndexW
#ELSE
   MACRO JetSetCurrentIndex = JetSetCurrentIndexA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetCurrentIndex2 function sets the current index of a cursor that defines which
' records in a table are visible to that cursor and the order in which they appear by
' selecting the set of index entries to use to expose those records.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex2 IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex2A IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex2W IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ  _                     ' __in_opt JET_PCWSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetCurrentIndex2 = JetSetCurrentIndex2W
#ELSE
   MACRO JetSetCurrentIndex2 = JetSetCurrentIndex2A
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetCurrentIndex3 function is used to set the current index of a cursor. The
' current index of a cursor defines which records in a table are visible to that cursor
' and the order in which they appear by selecting the set of index entries to use to
' expose those records.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex3 IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex3" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex3A IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex3A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex3W IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex3W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ  _                     ' __in_opt JET_PCWSTR szIndexName
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetCurrentIndex3 = JetSetCurrentIndex3W
#ELSE
   MACRO JetSetCurrentIndex3 = JetSetCurrentIndex3A
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetCurrentIndex4 function is used to set the current index of a cursor. The
' current index of a cursor defines which records in a table are visible to that cursor
' and the order in which they appear by selecting the set of index entries to use to
' expose those records.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex4 IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex4" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYREF pindexid AS JET_INDEXID _                      ' __in_opt JET_INDEXID* pindexid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex4A IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex4A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS ASCIIZ _                        ' __in_opt JET_PCSTR szIndexName
 , BYREF pindexid AS JET_INDEXID _                      ' __in_opt JET_INDEXID* pindexid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetCurrentIndex4W IMPORT "ESENT.DLL" ALIAS "JetSetCurrentIndex4W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF szIndexName AS WSTRINGZ _                      ' __in_opt JET_PCWSTR szIndexName
 , BYREF pindexid AS JET_INDEXID _                      ' __in_opt JET_INDEXID* pindexid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL itagSequence AS DWORD _                        ' __in unsigned long itagSequence
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetCurrentIndex4 = JetSetCurrentIndex4W
#ELSE
   MACRO JetSetCurrentIndex4 = JetSetCurrentIndex4A
#ENDIF
#ENDIF

' ========================================================================================
' The JetMove function positions a cursor at the start or end of an index and traverses
' the entries in that index either forward or backward. It is also possible to move the
' cursor forward or backward on the current index by a specified number of index
' entries. Another approach is to artificially limit the index entries that can be
' enumerated using JetMove by setting up an index range on the cursor using
' JetSetIndexRange.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetMove IMPORT "ESENT.DLL" ALIAS "JetMove" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL cRow AS LONG _                                 ' __in long cRow
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGetLock function provides a means to explicitly reserve the ability to update a
' row, write lock, or to explicitly prevent a row from being updated by any other
' session, read lock. Normally, row write locks are acquired implicitly as a result of
' updating rows. Read locks are usually not required because of record versioning.
' However, in some cases a transaction may desire to explicitly lock a row to enforce
' serialization, or to ensure that a subsequent operation will succeed by virtue that
' required locks have already been taken.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetLock IMPORT "ESENT.DLL" ALIAS "JetGetLock" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetMakeKey function constructs search keys that may then be used to find a set of
' entries in an index by some simple search criteria on their key column values. A
' search key is also one of the intrinsic properties of a cursor and is used by the
' JetSeek and JetSetIndexRange operations to locate index entries matching these search
' criteria on the current index of that cursor. A complete search key is built up in a
' series of JetMakeKey calls where each call is used to load the column value for the
' next key column of the current index of a cursor. It is also possible to load a
' previously constructed search key that has been retrieved from the cursor using
' JetRetrieveKey.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetMakeKey IMPORT "ESENT.DLL" ALIAS "JetMakeKey" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvData AS ANY _                                ' __in_opt const void* pvData
 , BYVAL cbData AS DWORD _                              ' __in unsigned long cbData
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetSeek function efficiently positions a cursor to an index entry that matches the
' search criteria specified by the search key in that cursor and the specified
' inequality. A search key must have been previously constructed using JetMakeKey.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSeek IMPORT "ESENT.DLL" ALIAS "JetSeek" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0601
' ========================================================================================
DECLARE FUNCTION JetPrereadKeys IMPORT "ESENT.DLL" ALIAS "JetPrereadKeys" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF rgpvKeys AS DWORD _                            ' __in_ecount(ckeys) const void ** rgpvKeys
 , BYREF rgcbKeys AS LONG _                             ' __in_ecount(ckeys) const unsigned long * rgcbKeys
 , BYVAL ckeys AS LONG _                                ' __in long ckeys
 , BYREF pckeysPreread AS LONG _                        ' __out_opt long * pckeysPreread
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0601

' ========================================================================================
' The JetGetBookmark function retrieves the bookmark for the record that is associated
' with the index entry at the current position of a cursor. This bookmark can then be
' used to reposition that cursor back to the same record using JetGotoBookmark.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetBookmark IMPORT "ESENT.DLL" ALIAS "JetGetBookmark" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvBookmark AS ANY _                            ' __out void* pvBookmark
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __in unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetGetSecondaryIndexBookmark function retrieves a special bookmark for the
' secondary index entry at the current position of a cursor. This bookmark can then be
' used to efficiently reposition that cursor back to the same index entry using
' JetGotoSecondaryIndexBookmark. This is most useful when repositioning on a secondary
' index that contains duplicate keys or that contains multiple index entries for the
' same record.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetSecondaryIndexBookmark IMPORT "ESENT.DLL" ALIAS "JetGetSecondaryIndexBookmark" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvSecondaryKey AS ANY _                        ' __out_opt void* pvSecondaryKey
 , BYVAL cbSecondaryKeyMax AS DWORD _                   ' __in unsigned long cbSecondaryKeyMax
 , BYREF pcbSecondaryKeyActual AS DWORD _               ' __out_opt unsigned long* pcbSecondaryKeyActual
 , BYREF pvPrimaryBookmark AS ANY _                     ' __out_opt void* pvPrimaryBookmark
 , BYVAL cbPrimaryBookmarkMax AS DWORD _                ' __in unsigned long cbPrimaryBookmarkMax
 , BYREF pcbPrimaryKeyActual AS DWORD _                 ' __out unsigned long* pcbPrimaryKeyActual
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetCompact function makes a copy of an existing database. The copy is compacted to
' a state optimal for usage. Data in the copied data will be packed according to the
' measures chosen for the indexes at index create. In this way, compacted data may be
' stored as densely as possible. Alternatively, compacted data may reserve space for
' subsequent record growth or index insertions.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCompact IMPORT "ESENT.DLL" ALIAS "JetCompact" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseSrc AS ASCIIZ _                      ' __in JET_PCSTR szDatabaseSrc
 , BYREF szDatabaseDest AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseDest
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 , BYREF pconvert AS JET_CONVERT _                      ' __in_opt JET_CONVERT* pconvert
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetCompactA IMPORT "ESENT.DLL" ALIAS "JetCompactA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseSrc AS ASCIIZ _                      ' __in JET_PCSTR szDatabaseSrc
 , BYREF szDatabaseDest AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseDest
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 , BYREF pconvert AS JET_CONVERT _                      ' __in_opt JET_CONVERT* pconvert
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetCompactW IMPORT "ESENT.DLL" ALIAS "JetCompactW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseSrc AS WSTRINGZ _                    ' __in JET_PCWSTR szDatabaseSrc
 , BYREF szDatabaseDest AS WSTRINGZ  _                  ' __in JET_PCWSTR szDatabaseDest
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 , BYREF pconvert AS JET_CONVERT _                      ' __in_opt JET_CONVERT* pconvert
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetCompact = JetCompactW
#ELSE
   MACRO JetCompact = JetCompactA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDefragment function starts and stops database defragmentation tasks that
' improves data organization within a database. This is done to limit database growth by
' using existing disk allocation more efficiently within the database. It can also
' reduce working set by ensuring that data is more closely packed. Lastly, it can
' improve application performance by speeding common operations through better data
' organization.
' Database defragmentation is an online operation and does not interrupt regular
' database activity, such as query operations or data updates. JetDefragment also does
' not make a copy of all existing data. Instead, it defragments a database in place.
' Lastly, JetDefragment recovers internal database space for re-use but does not release
' excess space to the operating system file system.
' The resulting format of the data can be much more efficient but is not generally
' optimal. Defragmentation is limited to releasing database pages for re-use which
' contain data that has already been logically deleted. Defragmentation also makes
' database pages available for re-use in some cases by combining data from two pages
' when it can fit on a single page.
' This operation is different from JetCompact which makes a copy of a read-only database
' into a highly optimal form.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetDefragment IMPORT "ESENT.DLL" ALIAS "JetDefragment" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __in_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __in_opt unsigned long* pcSeconds
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDefragmentA IMPORT "ESENT.DLL" ALIAS "JetDefragmentA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __in_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __in_opt unsigned long* pcSeconds
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDefragmentW IMPORT "ESENT.DLL" ALIAS "JetDefragmentW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ  _                     ' __in JET_PCWSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __in_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __in_opt unsigned long* pcSeconds
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDefragment = JetDefragmentW
#ELSE
   MACRO JetDefragment = JetDefragmentA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetDefragment2 function starts and stops database defragmentation tasks which
' improves data organization within a database, with a callback parameter available to
' report the progress of the defragmentation. This is done to limit database growth by
' using existing disk allocation more efficiently within the database. It can also
' reduce working set by ensuring that data is more closely packed. Lastly, it can
' improve application performance by speeding common operations through better data
' organization.
' JetDefragment2 also contains a callback function parameter that is used to report on
' the progress of the defragmentation process.
' Database defragmentation is an online operation and does not interrupt regular
' database activity such as query operations or data updates. JetDefragment2 also does
' not make a copy of all existing data. Instead, it defragments a database in place.
' Lastly, JetDefragment2 recovers internal database space for re-use but does not
' release excess space to the operating system file system.
' The resulting format of the data can be much more efficient but is not generally
' optimal. Defragmentation is limited to releasing database pages for re-use which
' contain data that has already been logically deleted. Defragmentation also makes
' database pages available for re-use in some cases by combining data from two pages
' when it can fit on a single page.
' This operation is different from JetCompact which makes a copy of a read-only database
' into a highly optimal form.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetDefragment2 IMPORT "ESENT.DLL" ALIAS "JetDefragment2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetDefragment3 function is reserved. Do not use the JetDefragment3 function.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetDefragment3 IMPORT "ESENT.DLL" ALIAS "JetDefragment3" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL pvContext AS DWORD _                           ' __in void* pvContext
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetDefragment2A IMPORT "ESENT.DLL" ALIAS "JetDefragment2A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDefragment2W IMPORT "ESENT.DLL" ALIAS "JetDefragment2W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYREF szTableName AS WSTRINGZ  _                     ' __in JET_PCWSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDefragment2 = JetDefragment2W
#ELSE
   MACRO JetDefragment2 = JetDefragment2A
#ENDIF
' ========================================================================================
DECLARE FUNCTION JetDefragment3A IMPORT "ESENT.DLL" ALIAS "JetDefragment3A" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYREF szTableName AS ASCIIZ _                        ' __in JET_PCSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL pvContext AS DWORD _                           ' __in void* pvContext
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetDefragment3W IMPORT "ESENT.DLL" ALIAS "JetDefragment3W" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS WSTRINGZ _                   ' __in JET_PCWSTR szDatabaseName
 , BYREF szTableName AS WSTRINGZ _                      ' __in JET_PCWSTR szTableName
 , BYREF pcPasses AS DWORD _                            ' __out_opt unsigned long* pcPasses
 , BYREF pcSeconds AS DWORD _                           ' __out_opt unsigned long* pcSeconds
 , BYVAL callback AS DWORD _                            ' __in JET_CALLBACK callback
 , BYVAL pvContext AS DWORD _                           ' __in void* pvContext
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetDefragment3 = JetDefragment3W
#ELSE
   MACRO JetDefragment3 = JetDefragment3A
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetSetDatabaseSize function sets the size of an unopened database file.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetDatabaseSize IMPORT "ESENT.DLL" ALIAS "JetSetDatabaseSize" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYVAL cpg AS DWORD _                                 ' __in unsigned long cpg
 , BYREF pcpgReal AS DWORD _                            ' __out unsigned long* pcpgReal
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetSetDatabaseSizeA IMPORT "ESENT.DLL" ALIAS "JetSetDatabaseSizeA" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS ASCIIZ _                     ' __in JET_PCSTR szDatabaseName
 , BYVAL cpg AS DWORD _                                 ' __in unsigned long cpg
 , BYREF pcpgReal AS DWORD _                            ' __out unsigned long* pcpgReal
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetSetDatabaseSizeW IMPORT "ESENT.DLL" ALIAS "JetSetDatabaseSizeW" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF szDatabaseName AS WSTRINGZ  _                  ' __in JET_PCWSTR szDatabaseName
 , BYVAL cpg AS DWORD _                                 ' __in unsigned long cpg
 , BYREF pcpgReal AS DWORD _                            ' __out unsigned long* pcpgReal
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetSetDatabaseSize = JetSetDatabaseSizeW
#ELSE
   MACRO JetSetDatabaseSize = JetSetDatabaseSizeA
#ENDIF
#ENDIF

' ========================================================================================
' The JetGrowDatabase function extends the size of a database that is currently open.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGrowDatabase IMPORT "ESENT.DLL" ALIAS "JetGrowDatabase" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL dbid AS DWORD _                                ' __in JET_DBID dbid
 , BYVAL cpg AS DWORD _                                 ' __in unsigned long cpg
 , BYREF pcpgReal AS DWORD _                            ' __out unsigned long* pcpgReal
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetSetSessionContext function associates a session with the current thread using
' the given context handle. This association overrides the default engine requirement
' that a transaction for a given session must occur entirely on the same thread.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetSessionContext IMPORT "ESENT.DLL" ALIAS "JetSetSessionContext" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL ulContext AS DWORD _                           ' __in JET_API_PTR ulContext
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetResetSessionContext function disassociates a session from the current thread.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetResetSessionContext IMPORT "ESENT.DLL" ALIAS "JetResetSessionContext" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGotoBookmark function positions a cursor to an index entry for the record that
' is associated with the specified bookmark. The bookmark can be used with any index
' defined over a table. The bookmark for a record can be retrieved using JetGetBookmark.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGotoBookmark IMPORT "ESENT.DLL" ALIAS "JetGotoBookmark" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvBookmark AS ANY _                            ' __in void* pvBookmark
 , BYVAL cbBookmark AS DWORD _                          ' __in unsigned long cbBookmark
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetGotoSecondaryIndexBookmark function positions a cursor to an index entry that
' is associated with the specified secondary index bookmark. The secondary index
' bookmark must be used with the same index over the same table from which it was
' originally retrieved. The secondary index bookmark for an index entry can be retrieved
' using JetGotoSecondaryIndexBookmark.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGotoSecondaryIndexBookmark IMPORT "ESENT.DLL" ALIAS "JetGotoSecondaryIndexBookmark" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvSecondaryKey AS ANY _                        ' __in void* pvSecondaryKey
 , BYVAL cbSecondaryKey AS DWORD _                      ' __in unsigned long cbSecondaryKey
 , BYREF pvPrimaryBookmark AS ANY _                     ' __in void* pvPrimaryBookmark
 , BYVAL cbPrimaryBookmark AS DWORD _                   ' __in unsigned long cbPrimaryBookmark
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetIntersectIndexes function computes the intersection between multiple sets of
' index entries from different secondary indices over the same table. This operation is
' useful for finding the set of records in a table that match two or more criteria that
' can be expressed using index ranges.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetIntersectIndexes IMPORT "ESENT.DLL" ALIAS "JetIntersectIndexes" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF rgindexrange AS JET_INDEXRANGE _               ' __in JET_INDEXRANGE* rgindexrange
 , BYVAL cindexrange AS DWORD _                         ' __in unsigned long cindexrange
 , BYREF precordlist AS JET_RECORDLIST _                ' __inout JET_RECORDLIST* precordlist
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetComputeStats function walks each index of a table to exactly compute the number
' of entries in an index, and the number of distinct keys in an index. This information,
' together with the number of database pages allocated for an index and the current time
' of the computation is stored in index metadata in the database. This data can be
' subsequently retrieved with information operations.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetComputeStats IMPORT "ESENT.DLL" ALIAS "JetComputeStats" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetOpenTempTable function creates a temporary table with a single index. A
' temporary table stores and retrieves records just like an ordinary table created
' using JetCreateTableColumnIndex. However, temporary tables are much faster than
' ordinary tables due to their volatile nature. They can also be used to very quickly
' sort and perform duplicate removal on record sets when accessed in a purely sequential
' manner.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenTempTable IMPORT "ESENT.DLL" ALIAS "JetOpenTempTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF prgcolumndef AS JET_COLUMNDEF _                ' __in const JET_COLUMNDEF* prgcolumndef
 , BYVAL ccolumn AS DWORD _                             ' __in unsigned long ccolumn
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 , BYREF prgcolumnid AS DWORD _                         ' __out JET_COLUMNID* prgcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetOpenTempTable2 function creates a temporary table with a single index that can
' be used to store and retrieve records just like an ordinary table created using
' JetCreateTableColumnIndex. This function also has a Locale ID that can be used to
' compare Unicode key column data in the temporary table. However, temporary tables are
' much faster than ordinary tables due to their volatile nature. They can also be used
' to very quickly sort and perform duplicate removal on record sets when accessed in a
' purely sequential manner.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenTempTable2 IMPORT "ESENT.DLL" ALIAS "JetOpenTempTable2" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF prgcolumndef AS JET_COLUMNDEF _                ' __in const JET_COLUMNDEF* prgcolumndef
 , BYVAL ccolumn AS DWORD _                             ' __in unsigned long ccolumn
 , BYVAL lcid AS DWORD _                                ' __in unsigned long lcid
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 , BYREF prgcolumnid AS DWORD _                         ' __out JET_COLUMNID* prgcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetOpenTempTable3 function creates a temporary table with a single index that can
' be used to store and retrieve records just like an ordinary table created using
' JetCreateTableColumnIndex. However, temporary tables are much faster than ordinary
' tables due to their volatile nature. They can also be used to very quickly sort and
' perform duplicate removal on record sets when accessed in a purely sequential manner.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenTempTable3 IMPORT "ESENT.DLL" ALIAS "JetOpenTempTable3" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF prgcolumndef AS JET_COLUMNDEF _                ' __in const JET_COLUMNDEF* prgcolumndef
 , BYVAL ccolumn AS DWORD _                             ' __in unsigned long ccolumn
 , BYREF pidxunicode AS JET_UNICODEINDEX _              ' __in_opt JET_UNICODEINDEX* pidxunicode
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYREF ptableid AS DWORD _                            ' __out JET_TABLEID* ptableid
 , BYREF prgcolumnid AS DWORD _                         ' __out JET_COLUMNID* prgcolumnid
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetOpenTemporaryTable IMPORT "ESENT.DLL" ALIAS "JetOpenTemporaryTable" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYREF popentemporarytable AS JET_OPENTEMPORARYTABLE _ ' __in JET_OPENTEMPORARYTABLE * popentemporarytable
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetBackup function creates a backup of the database while the database is online.
' This function is primarily for backwards compatibility with Windows 2000 and earlier
' database engines, where only one instance of a database is allowed. In this case, the
' active instance is the instance that is backed up.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetBackup IMPORT "ESENT.DLL" ALIAS "JetBackup" ( _
   BYREF szBackupPath AS ASCIIZ _                       ' __in JET_PCSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetBackupA IMPORT "ESENT.DLL" ALIAS "JetBackupA" ( _
   BYREF szBackupPath AS ASCIIZ _                       ' __in JET_PCSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetBackupW IMPORT "ESENT.DLL" ALIAS "JetBackupW" ( _
   BYREF szBackupPath AS WSTRINGZ _                     ' __in JET_PCWSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetBackup = JetBackupW
#ELSE
   MACRO JetBackup = JetBackupA
#ENDIF
#ENDIF   ' // JET_VERSION < 0x0600

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetBackupInstance function performs a streaming backup of an instance, including
' all the attached databases, to a directory. With multiple backup methods supported by
' the engine, this is the simplest and most encapsulated function.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetBackupInstance IMPORT "ESENT.DLL" ALIAS "JetBackupInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szBackupPath AS ASCIIZ _                       ' __in JET_PCSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetBackupInstanceA IMPORT "ESENT.DLL" ALIAS "JetBackupInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szBackupPath AS ASCIIZ _                       ' __in JET_PCSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetBackupInstanceW IMPORT "ESENT.DLL" ALIAS "JetBackupInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szBackupPath AS WSTRINGZ  _                    ' __in JET_PCWSTR szBackupPath
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 , BYVAL pfnStatus AS DWORD _                           ' __in JET_PFNSTATUS pfnStatus
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetBackupInstance = JetBackupInstanceW
#ELSE
   MACRO JetBackupInstance = JetBackupInstanceA
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0600
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetRestore function restores and recovers a streaming backup of an instance,
' including all the attached databases. This function is primarily for backwards
' compatibility with Windows 2000 and earlier database engines, where only one instance
' of a database is allowed. In this case, the active instance is the instance that is
' restored. With JetRestore, the location for the restored databases cannot be specified.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRestore IMPORT "ESENT.DLL" ALIAS "JetRestore" ( _
   BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetRestoreA IMPORT "ESENT.DLL" ALIAS "JetRestoreA" ( _
   BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetRestoreW IMPORT "ESENT.DLL" ALIAS "JetRestoreW" ( _
   BYREF sz AS WSTRINGZ _                               ' __in JET_PCWSTR sz
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetRestore = JetRestoreW
#ELSE
   MACRO JetRestore = JetRestoreA
#ENDIF
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetRestore2 restores and recovers a streaming backup of an instance, including all
' the attached databases. This function is primarily for backwards compatibility with
' Windows 2000 and earlier database engines, where only one instance of a database is
' allowed. In this case, the active instance is the instance that is restored.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRestore2 IMPORT "ESENT.DLL" ALIAS "JetRestore2" ( _
   BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYREF szDest AS ASCIIZ _                             ' __in_opt JET_PCSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetRestore2A IMPORT "ESENT.DLL" ALIAS "JetRestore2A" ( _
   BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYREF szDest AS ASCIIZ _                             ' __in_opt JET_PCSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetRestore2W IMPORT "ESENT.DLL" ALIAS "JetRestore2W" ( _
   BYVAL sz AS DWORD _                                  ' __in JET_PCWSTR sz
 , BYREF szDest AS WSTRINGZ  _                          ' __in_opt JET_PCWSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetRestore2 = JetRestore2W
#ELSE
   MACRO JetRestore2 = JetRestore2A
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetRestoreInstance function restores and recovers a streaming backup of an
' instance including all the attached databases. It is designed to work with a backup
' created with the JetBackupInstance function. This is the simplest and most
' encapsulated one restore function.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRestoreInstance IMPORT "ESENT.DLL" ALIAS "JetRestoreInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYREF szDest AS ASCIIZ _                             ' __in_opt JET_PCSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetRestoreInstanceA IMPORT "ESENT.DLL" ALIAS "JetRestoreInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF sz AS ASCIIZ _                                 ' __in JET_PCSTR sz
 , BYREF szDest AS ASCIIZ _                             ' __in_opt JET_PCSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetRestoreInstanceW IMPORT "ESENT.DLL" ALIAS "JetRestoreInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL sz AS DWORD _                                  ' __in JET_PCWSTR sz
 , BYREF szDest AS WSTRINGZ _                           ' __in_opt JET_PCSTR szDest
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetRestoreInstance = JetRestoreInstanceW
#ELSE
   MACRO JetRestoreInstance = JetRestoreInstanceA
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0600
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetSetIndexRange function temporarily limits the set of index entries that the
' cursor can walk using JetMove to those starting from the current index entry and
' ending at the index entry that matches the search criteria specified by the search key
' in that cursor and the specified bound criteria. A search key must have been
' previously constructed using JetMakeKey.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetSetIndexRange IMPORT "ESENT.DLL" ALIAS "JetSetIndexRange" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableidSrc AS DWORD _                          ' __in JET_TABLEID tableidSrc
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetIndexRecordCount function counts the number of entries in the current index
' from the current position forward. The current position is included in the count. The
' count can be greater than the total number of records in the table if the current
' index is over a multi-valued column and instances of the column have multiple-values.
' If the table is empty, then 0 will be returned for the count.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetIndexRecordCount IMPORT "ESENT.DLL" ALIAS "JetIndexRecordCount" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pcrec AS DWORD _                               ' __out unsigned long* pcrec
 , BYVAL crecMax AS DWORD _                             ' __in unsigned long crecMax
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetRetrieveKey function retrieves the key for the index entry at the current
' position of a cursor. Such keys are constructed by calls to JetMakeKey. The retrieved
' key can then be used to efficiently return that cursor to the same index entry by a
' call to JetSeek.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetRetrieveKey IMPORT "ESENT.DLL" ALIAS "JetRetrieveKey" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pvData AS ANY _                                ' __out void* pvData
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __in unsigned long* pcbActual
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetBeginExternalBackup function initiates an external backup while the engine and
' database is online and active. JetBeginExternalBackup is the first in a series of
' functions that must be called to execute a successful online (non-VSS based) backup.
' An external backup can be used to implement full, incremental, or differential backups.
' The backup will be fuzzy, in that the backup will be consistent to a single point in
' time in the transaction history, but controlling the exact point in time is not
' possible.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetBeginExternalBackup IMPORT "ESENT.DLL" ALIAS "JetBeginExternalBackup" ( _
   BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetBeginExternalBackupInstance function initiates an external backup while the
' engine and database are online and active.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetBeginExternalBackupInstance IMPORT "ESENT.DLL" ALIAS "JetBeginExternalBackupInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetAttachInfo function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database files that
' should become part of the backup file set. Only databases currently attached to the
' instance using JetAttachDatabase will be considered. These files may subsequently be
' opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetAttachInfo IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfo" ( _
   BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetAttachInfoA IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfoA" ( _
   BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetAttachInfoW IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfoW" ( _
   BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetAttachInfo = JetGetAttachInfoW
#ELSE
   MACRO JetGetAttachInfo = JetGetAttachInfoA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetAttachInfoInstance function is used during a backup initiated by
' JetBeginExternalBackupInstance to query an instance for the names of database files
' that should become part of the backup file set. Only databases that are currently
' attached to the instance using JetAttachDatabase will be considered. These files may
' subsequently be opened using JetOpenFileInstance and read using JetReadFileInstance.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetAttachInfoInstance IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfoInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
DECLARE FUNCTION JetGetAttachInfoInstanceA IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfoInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
DECLARE FUNCTION JetGetAttachInfoInstanceW IMPORT "ESENT.DLL" ALIAS "JetGetAttachInfoInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void *pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetAttachInfoInstance = JetGetAttachInfoInstanceW
#ELSE
   MACRO JetGetAttachInfoInstance = JetGetAttachInfoInstanceA
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetOpenFile function opens an attached database, database patch file, or
' transaction log file of an active instance for the purpose of performing a streaming
' fuzzy backup. The data from these files can subsequently be read through the returned
' handle using JetReadFile. The returned handle must be closed using JetCloseFile. An
' external backup of the instance must have been previously initiated using
' JetBeginExternalBackup.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetOpenFile IMPORT "ESENT.DLL" ALIAS "JetOpenFile" ( _
   BYREF szFileName AS ASCIIZ _                         ' __in JET_PCSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetOpenFileA IMPORT "ESENT.DLL" ALIAS "JetOpenFileA" ( _
   BYREF szFileName AS ASCIIZ _                         ' __in JET_PCSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOpenFileW IMPORT "ESENT.DLL" ALIAS "JetOpenFileW" ( _
   BYREF szFileName AS WSTRINGZ _                       ' __in JET_PCWSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOpenFile = JetOpenFileW
#ELSE
   MACRO JetOpenFile = JetOpenFileA
#ENDIF
#ENDIF

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetOpenFileInstance function opens an attached database, database patch file, or
' transaction log file of an active instance for the purpose of performing a streaming
' fuzzy backup. The data from these files can subsequently be read through the returned
' handle using JetReadFileInstance. The returned handle must be closed using
' JetCloseFileInstance. An external backup of the instance must have been previously
' initiated using JetBeginExternalBackupInstance.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetOpenFileInstance IMPORT "ESENT.DLL" ALIAS "JetOpenFileInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szFileName AS ASCIIZ _                         ' __in JET_PCSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetOpenFileInstanceA IMPORT "ESENT.DLL" ALIAS "JetOpenFileInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szFileName AS ASCIIZ _                         ' __in JET_PCSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOpenFileInstanceW IMPORT "ESENT.DLL" ALIAS "JetOpenFileInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF szFileName AS WSTRINGZ _                       ' __in JET_PCWSTR szFileName
 , BYREF phfFile AS DWORD _                             ' __out JET_HANDLE* phfFile
 , BYREF pulFileSizeLow AS DWORD _                      ' __out unsigned long* pulFileSizeLow
 , BYREF pulFileSizeHigh AS DWORD _                     ' __out unsigned long* pulFileSizeHigh
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOpenFileInstance = JetOpenFileInstanceW
#ELSE
   MACRO JetOpenFileInstance = JetOpenFileInstanceA
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetReadFile function retrieves the contents of a file opened with JetOpenFile.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetReadFile IMPORT "ESENT.DLL" ALIAS "JetReadFile" ( _
   BYVAL hfFile AS DWORD _                              ' __in JET_HANDLE hfFile
 , BYREF pv AS ANY _                                    ' __out void* pv
 , BYVAL cb AS DWORD _                                  ' __in unsigned long cb
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetReadFileInstance function retrieves the contents of a file opened with
' JetOpenFileInstance.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetReadFileInstance IMPORT "ESENT.DLL" ALIAS "JetReadFileInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL hfFile AS DWORD _                              ' __in JET_HANDLE hfFile
 , BYREF pv AS ANY _                                    ' __out void* pv
 , BYVAL cb AS DWORD _                                  ' __in unsigned long cb
 , BYREF pcb AS DWORD _                                 ' __out unsigned long* pcb
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetCloseFile function closes a file that was opened with JetOpenFile after the
' data from that file has been extracted using JetReadFile.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetCloseFile IMPORT "ESENT.DLL" ALIAS "JetCloseFile" ( _
   BYVAL hfFile AS DWORD _                              ' __in JET_HANDLE hfFile
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetCloseFileInstance function closes a file that was opened with
' JetOpenFileInstance after the data from that file has been extracted using
' JetReadFileInstance.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetCloseFileInstance IMPORT "ESENT.DLL" ALIAS "JetCloseFileInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL hfFile AS DWORD _                              ' __in JET_HANDLE hfFile
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetLogInfo function is used during a backup initiated by JetBeginExternalBackup
' to query an instance for the names of database patch files and transaction log files
' that should become part of the backup file set. These files may subsequently be opened
' using JetOpenFile and read using JetReadFile.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfo IMPORT "ESENT.DLL" ALIAS "JetGetLogInfo" ( _
   BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoA IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoA" ( _
   BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoW IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoW" ( _
   BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetLogInfo = JetGetLogInfoW
#ELSE
   MACRO JetGetLogInfo = JetGetLogInfoA
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0501

%JET_BASE_NAME_LENGTH = 3

' // Size = 16 bytes
TYPE JET_LOGINFO_A DWORD
   cbSize     AS DWORD
   ulGenLow   AS DWORD
   ulGenHigh  AS DWORD
   szBaseName AS ASCIIZ * %JET_BASE_NAME_LENGTH + 1
END TYPE

' // Size = 20 bytes
TYPE JET_LOGINFO_W DWORD
   cbSize     AS DWORD
   ulGenLow   AS DWORD
   ulGenHigh  AS DWORD
   szBaseName AS WSTRINGZ * %JET_BASE_NAME_LENGTH + 1
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_LOGINFO = JET_LOGINFO_W
#ELSE
   MACRO JET_LOGINFO = JET_LOGINFO_A
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetLogInfoInstance function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstance IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetLogInfoInstance2 function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstance2 IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstance2" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 , BYREF pLogInfo AS JET_LOGINFO _                      ' __inout_opt JET_LOGINFO* pLogInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetTruncateLogInfoInstance function is used during a backup that is initiated
' by JetBeginExternalBackup to query an instance for the names of the transaction log
' files that can be safely deleted after the backup has successfully completed.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetTruncateLogInfoInstance IMPORT "ESENT.DLL" ALIAS "JetGetTruncateLogInfoInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
' The JetGetLogInfoInstance function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstanceA IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetLogInfoInstance function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstanceW IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetLogInfoInstance = JetGetLogInfoInstanceW
#ELSE
   MACRO JetGetLogInfoInstance = JetGetLogInfoInstanceA
#ENDIF
' ========================================================================================
' The JetGetLogInfoInstance2 function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstance2A IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstance2A" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 , BYREF pLogInfo AS JET_LOGINFO_A _                    ' __inout_opt JET_LOGINFO_A* pLogInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetLogInfoInstance2 function is used during a backup initiated by
' JetBeginExternalBackup to query an instance for the names of database patch files and
' transaction log files that should become part of the backup file set. These files may
' subsequently be opened using JetOpenFile and read using JetReadFile.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLogInfoInstance2W IMPORT "ESENT.DLL" ALIAS "JetGetLogInfoInstance2W" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out_opt unsigned long* pcbActual
 , BYREF pLogInfo AS JET_LOGINFO_W _                    ' __inout_opt JET_LOGINFO_W* pLogInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetLogInfoInstance2 = JetGetLogInfoInstance2W
#ELSE
   MACRO JetGetLogInfoInstance2 = JetGetLogInfoInstance2A
#ENDIF
' ========================================================================================
' The JetGetTruncateLogInfoInstance function is used during a backup that is initiated
' by JetBeginExternalBackup to query an instance for the names of the transaction log
' files that can be safely deleted after the backup has successfully completed.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetTruncateLogInfoInstanceA IMPORT "ESENT.DLL" ALIAS "JetGetTruncateLogInfoInstanceA" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetTruncateLogInfoInstance function is used during a backup that is initiated
' by JetBeginExternalBackup to query an instance for the names of the transaction log
' files that can be safely deleted after the backup has successfully completed.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetTruncateLogInfoInstanceW IMPORT "ESENT.DLL" ALIAS "JetGetTruncateLogInfoInstanceW" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYREF pv AS ANY _                                    ' __out_opt void* pv
 , BYVAL cbMax AS DWORD _                               ' __in unsigned long cbMax
 , BYREF pcbActual AS DWORD _                           ' __out unsigned long* pcbActual
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetTruncateLogInfoInstance = JetGetTruncateLogInfoInstanceW
#ELSE
   MACRO JetGetTruncateLogInfoInstance = JetGetTruncateLogInfoInstanceA
#ENDIF
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetTruncateLog function is used during a backup that is initiated by
' JetBeginExternalBackup to delete any transaction log files that will no longer be
' needed once the current backup completes successfully.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetTruncateLog IMPORT "ESENT.DLL" ALIAS "JetTruncateLog" () AS LONG
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetTruncateLogInstance function is used during a backup initiated by
' JetBeginExternalBackup to delete any transaction log files that will no longer be
' needed once the current backup completes successfully.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetTruncateLogInstance IMPORT "ESENT.DLL" ALIAS "JetTruncateLogInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

' ========================================================================================
' The JetEndExternalBackup function ends an external backup session. This function is
' the last API element in a series of API elements that must be called to execute a
' successful online (non-VSS based) backup.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetEndExternalBackup IMPORT "ESENT.DLL" ALIAS "JetEndExternalBackup" () AS LONG
' ========================================================================================

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetEndExternalBackupInstance function ends an external backup session. This API is
' the last API in a series of APIs that must be called to execute a successful online
' (non-VSS based) backup.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetEndExternalBackupInstance IMPORT "ESENT.DLL" ALIAS "JetEndExternalBackupInstance" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetEndExternalBackupInstance2 function ends an external backup session. This API
' is the last API in a series of APIs that must be called to execute a successful online
' (non-VSS based) backup.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetEndExternalBackupInstance2 IMPORT "ESENT.DLL" ALIAS "JetEndExternalBackupInstance2" ( _
   BYVAL instance AS DWORD _                            ' __in JET_INSTANCE instance
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetExternalRestore function restores an external backup that was taken with the
' external backup APIs and specifies a range of log file numbers to replay during the
' restore process. This is known as hard recovery, which is similar to but different
' than than soft recovery as performed by the JetInit function.
' Requires Windows Vista, Windows XP, or Windows 2000 Professional.
' ========================================================================================
DECLARE FUNCTION JetExternalRestore IMPORT "ESENT.DLL" ALIAS "JetExternalRestore" ( _
   BYREF szCheckpointFilePath AS ASCIIZ _               ' __in JET_PSTR szCheckpointFilePath
 , BYREF szLogPath AS ASCIIZ _                          ' __in JET_PSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP _                       ' __in_opt JET_RSTMAP* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS ASCIIZ _                    ' __in JET_PSTR szBackupLogPath
 , BYVAL genLow AS LONG _                               ' __in long genLow
 , BYVAL genHigh AS LONG _                              ' __in long genHigh
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetExternalRestoreA IMPORT "ESENT.DLL" ALIAS "JetExternalRestoreA" ( _
   BYREF szCheckpointFilePath AS ASCIIZ _               ' __in JET_PSTR szCheckpointFilePath
 , BYREF szLogPath AS ASCIIZ _                          ' __in JET_PSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP_A _                     ' __in_opt JET_RSTMAP_A* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS ASCIIZ _                    ' __in JET_PSTR szBackupLogPath
 , BYVAL genLow AS LONG _                               ' __in long genLow
 , BYVAL genHigh AS LONG _                              ' __in long genHigh
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetExternalRestoreW IMPORT "ESENT.DLL" ALIAS "JetExternalRestoreW" ( _
   BYVAL szCheckpointFilePath AS DWORD _                ' __in JET_PWSTR szCheckpointFilePath
 , BYVAL szLogPath AS DWORD _                           ' __in JET_PWSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP_W _                     ' __in_opt JET_RSTMAP_W* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS WSTRINGZ _                  ' __in JET_PWSTR szBackupLogPath
 , BYVAL genLow AS LONG _                               ' __in long genLow
 , BYVAL genHigh AS LONG _                              ' __in long genHigh
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetExternalRestore = JetExternalRestoreW
#ELSE
   MACRO JetExternalRestore = JetExternalRestoreA
#ENDIF
#ENDIF   ' JET_VERSION < 0x0600

#IF %JET_VERSION >= &H0501
#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetExternalRestore2 function restores an external backup that was taken with the
' external backup APIs and provides checkpoints to use for circular logging operations.
' This is known as hard recovery, which is similar but different than soft recovery as
' performed by the JetInit function.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetExternalRestore2 IMPORT "ESENT.DLL" ALIAS "JetExternalRestore2" ( _
   BYREF szCheckpointFilePath AS ASCIIZ _               ' __in JET_PSTR szCheckpointFilePath
 , BYREF szLogPath AS ASCIIZ _                          ' __in JET_PSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP _                       ' __in_opt JET_RSTMAP* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS ASCIIZ _                    ' __in JET_PSTR szBackupLogPath
 , BYREF pLogInfo AS JET_LOGINFO _                      ' __inout JET_LOGINFO* pLogInfo
 , BYREF szTargetInstanceName AS ASCIIZ _               ' __in_opt JET_PSTR szTargetInstanceName,
 , BYREF szTargetInstanceLogPath AS ASCIIZ _            ' __in_opt JET_PSTR szTargetInstanceLogPath
 , BYREF szTargetInstanceCheckpointPath AS ASCIIZ _     ' __in_opt JET_PSTR szTargetInstanceCheckpointPath
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetExternalRestore2A IMPORT "ESENT.DLL" ALIAS "JetExternalRestore2A" ( _
   BYREF szCheckpointFilePath AS ASCIIZ _               ' __in JET_PSTR szCheckpointFilePath
 , BYREF szLogPath AS ASCIIZ _                          ' __in JET_PSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP_A _                     ' __in_opt JET_RSTMAP_A* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS ASCIIZ _                    ' __in JET_PSTR szBackupLogPath
 , BYREF pLogInfo AS JET_LOGINFO_A _                    ' __inout JET_LOGINFO_A* pLogInfo
 , BYREF szTargetInstanceName AS ASCIIZ _               ' __in_opt JET_PSTR szTargetInstanceName,
 , BYREF szTargetInstanceLogPath AS ASCIIZ _            ' __in_opt JET_PSTR szTargetInstanceLogPath
 , BYREF szTargetInstanceCheckpointPath AS ASCIIZ _     ' __in_opt JET_PSTR szTargetInstanceCheckpointPath
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetExternalRestore2W IMPORT "ESENT.DLL" ALIAS "JetExternalRestore2W" ( _
   BYREF szCheckpointFilePath AS WSTRINGZ _             ' __in JET_PWSTR szCheckpointFilePath
 , BYVAL szLogPath AS DWORD _                           ' __in JET_PWSTR szLogPath
 , BYREF rgrstmap AS JET_RSTMAP_W _                     ' __in_opt JET_RSTMAP_W* rgrstmap
 , BYVAL crstfilemap AS LONG _                          ' __in long crstfilemap
 , BYREF szBackupLogPath AS WSTRINGZ _                  ' __in JET_PWSTR szBackupLogPath
 , BYREF pLogInfo AS JET_LOGINFO_W _                    ' __inout JET_LOGINFO_W* pLogInfo
 , BYREF szTargetInstanceName AS WSTRINGZ _             ' __in_opt JET_PWSTR szTargetInstanceName,
 , BYREF szTargetInstanceLogPath AS WSTRINGZ _          ' __in_opt JET_PWSTR szTargetInstanceLogPath
 , BYREF szTargetInstanceCheckpointPath AS WSTRINGZ _   ' __in_opt JET_PWSTR szTargetInstanceCheckpointPath
 , BYVAL pfn AS DWORD _                                 ' __in JET_PFNSTATUS pfn
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetExternalRestore2 = JetExternalRestore2W
#ELSE
   MACRO JetExternalRestore2 = JetExternalRestore2A
#ENDIF
#ENDIF ' // JET_VERSION >= 0x0600
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0501
' ========================================================================================
' The JetRegisterCallback function allows the application to configure the database
' engine to issue notifications to the application for specific events. These
' notifications are associated with a specific table and remain in effect only until the
' instance containing the table is shut down using JetTerm.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetRegisterCallback IMPORT "ESENT.DLL" ALIAS "JetRegisterCallback" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL cbtyp AS DWORD _                               ' __in JET_CBTYP cbtyp
 , BYVAL pCallback AS DWORD _                           ' __in JET_CALLBACK pCallback
 , BYVAL pvContext AS DWORD _                           ' __in void* pvContext
 , BYREF phCallbackId AS DWORD _                        ' __out JET_HANDLE* phCallbackId
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetUnregisterCallback function enables the application to configure the database
' engine to stop issuing notifications to the application as previously requested
' through JetRegisterCallback.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetUnregisterCallback IMPORT "ESENT.DLL" ALIAS "JetUnregisterCallback" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL cbtyp AS DWORD _                               ' __in JET_CBTYP cbtyp
 , BYVAL hCallbackId AS DWORD _                         ' __in JET_HANDLE hCallbackId
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' // Size = 24 bytes
TYPE JET_INSTANCE_INFO_A DWORD
   hInstanceId           AS DWORD        ' JET_INSTANCE
   szInstanceName        AS ASCIIZ PTR   ' char *
   cDatabases            AS DWORD        ' JET_API_PTR
   szDatabaseFileName    AS ASCIIZ PTR   ' char **
   szDatabaseDisplayName AS ASCIIZ PTR   ' char **
   szDatabaseSLVFileName AS ASCIIZ PTR   ' char **
END TYPE

' // Size = 24 bytes
TYPE JET_INSTANCE_INFO_W DWORD
   hInstanceId           AS DWORD            ' JET_INSTANCE
   szInstanceName        AS WSTRINGZ PTR     ' WCHAR *
   cDatabases            AS DWORD            ' JET_API_PTR
   szDatabaseFileName    AS WSTRINGZ PTR     ' WCHAR **
   szDatabaseDisplayName AS WSTRINGZ PTR     ' WCHAR **
   szDatabaseSLVFileName AS WSTRINGZ PTR     ' WCHAR **
END TYPE

#IF %DEF(%UNICODE)
   MACRO JET_INSTANCE_INFO = JET_INSTANCE_INFO_W
#ELSE
   MACRO JET_INSTANCE_INFO = JET_INSTANCE_INFO_A
#ENDIF

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetGetInstanceInfo function retrieves information about the instances that are running.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetInstanceInfo IMPORT "ESENT.DLL" ALIAS "JetGetInstanceInfo" ( _
   BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO _          ' __out JET_INSTANCE_INFO** paInstanceInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
' The JetGetInstanceInfo function retrieves information about the instances that are running.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetInstanceInfoA IMPORT "ESENT.DLL" ALIAS "JetGetInstanceInfoA" ( _
   BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_A _        ' __out JET_INSTANCE_INFO_A** paInstanceInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
' The JetGetInstanceInfo function retrieves information about the instances that are running.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetInstanceInfoW IMPORT "ESENT.DLL" ALIAS "JetGetInstanceInfoW" ( _
   BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_W _        ' __out JET_INSTANCE_INFO_W** paInstanceInfo
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetGetInstanceInfo = JetGetInstanceInfoW
#ELSE
   MACRO JetGetInstanceInfo = JetGetInstanceInfoA
#ENDIF
#ENDIF   ' JET_VERSION >= 0x0600

' ========================================================================================
' The JetFreeBuffer function frees memory that was allocated by a database engine call.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetFreeBuffer IMPORT "ESENT.DLL" ALIAS "JetFreeBuffer" ( _
   BYVAL pbBuf AS DWORD _                               ' __in char* pbBuf
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetSetLS function enables the application to associate a context handle known as
' Local Storage with a cursor or the table associated with that cursor. This context
' handle can be used by the application to store auxiliary data that is associated with
' a cursor or table. The application is later notified using a runtime callback when the
' context handle must be released. This makes it possible to associate dynamically
' allocated state with a cursor or table.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetSetLS IMPORT "ESENT.DLL" ALIAS "JetSetLS" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYVAL ls AS DWORD _                                  ' __in JET_LS ls
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

' ========================================================================================
' The JetGetLS function enables the application to retrieve the context handle known as
' Local Storage that is associated with a cursor or the table associated with that
' cursor. This context handle must have been previously set using JetSetLS. JetGetLS can
' also be used to simultaneously fetch the current context handle for a cursor or table
' and reset that context handle.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetGetLS IMPORT "ESENT.DLL" ALIAS "JetGetLS" ( _
   BYVAL sesid AS DWORD _                               ' __in JET_SESID sesid
 , BYVAL tableid AS DWORD _                             ' __in JET_TABLEID tableid
 , BYREF pls AS DWORD _                                 ' __out JET_LS* pls
 , BYVAL grbit AS DWORD _                               ' __in JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

'typedef JET_API_PTR JET_OSSNAPID;     /* Snapshot Session Identifier */

' ========================================================================================
' The JetOSSnapshotPrepare function begins the preparations for a snapshot session. A
' snapshot session is a short time interval in which the engine does not issue any write
' IOs to disk, so that the engine can participate in a volume snapshot session (when
' driven by a snapshot writer).
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotPrepare IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotPrepare" ( _
   BYREF psnapId AS DWORD _                             ' __out JET_OSSNAPID* psnapId
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotPrepareInstance IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotPrepareInstance" ( _
   BYVAL psnapId AS DWORD _                             ' __in JET_OSSNAPID*   psnapId
 , BYVAL instance AS DWORD _                            ' __in JET_INSTANCE    instance
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' // JET_VERSION >= 0x0600

#IF %JET_VERSION < &H0600
' ========================================================================================
' The JetOSSnapshotFreeze function starts a snapshot. While the snapshot is in progress,
' no write-to-disk activity by the engine can take place.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotFreeze IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotFreeze" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO _          ' __out JET_INSTANCE_INFO** paInstanceInfo
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ELSE
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotFreezeA IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotFreezeA" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_A _        ' __out JET_INSTANCE_INFO_A** paInstanceInfo
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotFreezeW IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotFreezeW" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long* pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_W _        ' __out JET_INSTANCE_INFO_W** paInstanceInfo
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOSSnapshotFreeze = JetOSSnapshotFreezeW
#ELSE
   MACRO JetOSSnapshotFreeze = JetOSSnapshotFreezeA
#ENDIF
#ENDIF   ' JET_VERSION < 0x0600

' ========================================================================================
' The JetOSSnapshotThaw function notifies the engine that it can resume normal IO
' operations after a freeze period and a successful snapshot.
' Requires Windows Vista or Windows XP.
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotThaw IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotThaw" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= 0x0501

#IF %JET_VERSION >= &H0502
' ========================================================================================
' The JetOSSnapshotAbort function notifies the engine that it can resume normal IO
' operations after a freeze period ended with a failed snapshot.
' Requires Windows Vista.
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotAbort IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotAbort" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYVAL grbit As DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF ' // JET_VERSION >= &H0502

#IF %JET_VERSION >= &H0600
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotTruncateLog IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotTruncateLog" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotTruncateLogInstance IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotTruncateLogInstance" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYVAL instance AS DWORD _                            ' __in __in JET_INSTANCE  instance
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT    grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotGetFreezeInfoA IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotGetFreezeInfoA" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long * pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_A _        ' __deref_out_ecount( *pcInstanceInfo ) JET_INSTANCE_INFO_A ** paInstanceInfo
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotGetFreezeInfoW IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotGetFreezeInfoW" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYREF pcInstanceInfo AS DWORD _                      ' __out unsigned long * pcInstanceInfo
 , BYREF paInstanceInfo AS JET_INSTANCE_INFO_W _        ' __deref_out_ecount( *pcInstanceInfo ) JET_INSTANCE_INFO_W ** paInstanceInfo
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#IF %DEF(%UNICODE)
   MACRO JetOSSnapshotGetFreezeInfo = JetOSSnapshotGetFreezeInfoW
#ELSE
   MACRO JetOSSnapshotGetFreezeInfo = JetOSSnapshotGetFreezeInfoA
#ENDIF
' ========================================================================================
DECLARE FUNCTION JetOSSnapshotEnd IMPORT "ESENT.DLL" ALIAS "JetOSSnapshotEnd" ( _
   BYVAL snapId AS DWORD _                              ' __in const JET_OSSNAPID snapId
 , BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================
#ENDIF   ' JET_VERSION >= 0x0600

#IF %JET_VERSION >= &H0601

'//  Options for JetConfigureProcessForCrashDump

%JET_bitDumpMinimum                    = &H00000001???
'//  dump minimum includes cache minimum
%JET_bitDumpMaximum                    = &H00000002???
'//  dump maximum includes dump minimum
'//  dump maximum includes cache maximum
%JET_bitDumpCacheMinimum               = &H00000004???
'//  cache minimum includes pages that are latched
'//  cache minimum includes pages that are used for memory
'//  cache minimum includes pages that are flagged with errors
%JET_bitDumpCacheMaximum               = &H00000008???
'//  cache maximum includes cache minimum
'//  cache maximum includes the entire cache image
%JET_bitDumpCacheIncludeDirtyPages     = &H00000010???
'//  dump includes pages that are modified
%JET_bitDumpCacheIncludeCachedPages    = &H00000020???
'//  dump includes pages that contain valid data
%JET_bitDumpCacheIncludeCorruptedPages = &H00000040???
'//  dump includes pages that are corrupted (expensive to compute)

' ========================================================================================
DECLARE FUNCTION JetConfigureProcessForCrashDump IMPORT "ESENT.DLL" ALIAS "JetConfigureProcessForCrashDump" ( _
   BYVAL grbit AS DWORD _                               ' __in const JET_GRBIT grbit
 ) AS LONG                                              ' JET_ERR
' ========================================================================================

#ENDIF  ' // JET_VERSION >= 0x0601
