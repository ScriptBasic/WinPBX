' ########################################################################################
' Microsoft Windows
' File: dbdaoint.inc
' Library name: Microsoft DAO 3.6 Object Library
' Version: 5.0, Locale ID = 0
' Library GUID: {00025E01-0000-0000-C000-000000000046}
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DBDAOINT_INC = 1

'/*
' DBDAOINT.H
' OLE DAO Interface.
'This is a part of the Microsoft Data Access Objects SDK library.
'See the dao*.hlp files for detailed information regarding the
'Microsoft Data Access Objects SDK product.
'*/

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {00000100-0000-0010-8000-00AA006D2EA4}
$PROGID_DAODBEngine36 = "DAO.DBEngine.36"
' CLSID = {00000104-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOField36 = "DAO.Field.36"
' CLSID = {00000106-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOGroup36 = "DAO.Group.36"
' CLSID = {00000105-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOIndex36 = "DAO.Index.36"
' CLSID = {00000101-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOPrivateDBEngine36 = "DAO.PrivateDBEngine.36"
' CLSID = {00000108-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOQueryDef36 = "DAO.QueryDef.36"
' CLSID = {00000109-0000-0010-8000-00AA006D2EA4}
$PROGID_DAORelation36 = "DAO.Relation.36"
' CLSID = {00000103-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOTableDef36 = "DAO.TableDef.36"
' CLSID = {00000107-0000-0010-8000-00AA006D2EA4}
$PROGID_DAOUser36 = "DAO.User.36"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DAODBEngine = GUID$("{00000100-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOField = GUID$("{00000104-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOGroup = GUID$("{00000106-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOIndex = GUID$("{00000105-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOPrivDBEngine = GUID$("{00000101-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOQueryDef = GUID$("{00000108-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAORelation = GUID$("{00000109-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOTableDef = GUID$("{00000103-0000-0010-8000-00AA006D2EA4}")
$CLSID_DAOUser = GUID$("{00000107-0000-0010-8000-00AA006D2EA4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DAOConnection = GUID$("{00000041-0000-0010-8000-00AA006D2EA4}")
$IID_DAOConnections = GUID$("{00000043-0000-0010-8000-00AA006D2EA4}")
$IID_DAOContainer = GUID$("{00000091-0000-0010-8000-00AA006D2EA4}")
$IID_DAOContainers = GUID$("{00000093-0000-0010-8000-00AA006D2EA4}")
$IID_DAODatabase = GUID$("{00000071-0000-0010-8000-00AA006D2EA4}")
$IID_DAODatabases = GUID$("{00000073-0000-0010-8000-00AA006D2EA4}")
$IID_DAODocument = GUID$("{00000099-0000-0010-8000-00AA006D2EA4}")
$IID_DAODocuments = GUID$("{0000009B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOError = GUID$("{00000023-0000-0010-8000-00AA006D2EA4}")
$IID_DAOErrors = GUID$("{00000025-0000-0010-8000-00AA006D2EA4}")
$IID_DAOFields = GUID$("{00000053-0000-0010-8000-00AA006D2EA4}")
$IID_DAOGroups = GUID$("{00000063-0000-0010-8000-00AA006D2EA4}")
$IID_DAOIndexes = GUID$("{0000005B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOIndexFields = GUID$("{0000005D-0000-0010-8000-00AA006D2EA4}")
$IID_DAOParameter = GUID$("{00000081-0000-0010-8000-00AA006D2EA4}")
$IID_DAOParameters = GUID$("{00000083-0000-0010-8000-00AA006D2EA4}")
$IID_DAOProperties = GUID$("{00000029-0000-0010-8000-00AA006D2EA4}")
$IID_DAOProperty = GUID$("{00000027-0000-0010-8000-00AA006D2EA4}")
$IID_DAOQueryDefs = GUID$("{0000007B-0000-0010-8000-00AA006D2EA4}")
$IID_DAORecordset = GUID$("{00000031-0000-0010-8000-00AA006D2EA4}")
$IID_DAORecordsets = GUID$("{00000033-0000-0010-8000-00AA006D2EA4}")
$IID_DAORelations = GUID$("{0000008B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOTableDefs = GUID$("{0000004B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOUsers = GUID$("{0000006B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOWorkspace = GUID$("{00000039-0000-0010-8000-00AA006D2EA4}")
$IID_DAOWorkspaces = GUID$("{0000003B-0000-0010-8000-00AA006D2EA4}")
$IID_DAOCollection = GUID$("{000000A0-0000-0010-8000-00AA006D2EA4}")
$IID_DAODAO = GUID$("{0000000A-0000-0010-8000-00AA006D2EA4}")
$IID_DAODBEngine = GUID$("{00000021-0000-0010-8000-00AA006D2EA4}")
$IID_DAODynaCollection = GUID$("{000000A2-0000-0010-8000-00AA006D2EA4}")
$IID_DAOField = GUID$("{00000051-0000-0010-8000-00AA006D2EA4}")
$IID_DAOGroup = GUID$("{00000061-0000-0010-8000-00AA006D2EA4}")
$IID_DAOIndex = GUID$("{00000059-0000-0010-8000-00AA006D2EA4}")
$IID_DAOQueryDef = GUID$("{00000079-0000-0010-8000-00AA006D2EA4}")
$IID_DAORelation = GUID$("{00000089-0000-0010-8000-00AA006D2EA4}")
$IID_DAOTableDef = GUID$("{00000049-0000-0010-8000-00AA006D2EA4}")
$IID_DAOUser = GUID$("{00000069-0000-0010-8000-00AA006D2EA4}")


' enum RecordsetTypeEnum
%dbOpenTable               = 1
%dbOpenDynaset             = 2
%dbOpenSnapshot            = 4
%dbOpenForwardOnly         = 8
%dbOpenDynamic             = 16

' enum EditModeEnum
%dbEditNone                = 0
%dbEditInProgress          = 1
%dbEditAdd                 = 2
%dbEditChanged             = 4
%dbEditDeleted             = 8
%dbEditNew                 = 16

' enum RecordsetOptionEnum
%dbDenyWrite               = &H1
%dbDenyRead                = &H2
%dbReadOnly                = &H4
%dbAppendOnly              = &H8
%dbInconsistent            = &H10
%dbConsistent              = &H20
%dbSQLPassThrough          = &H40
%dbFailOnError             = &H80
%dbForwardOnly             = &H100
%dbSeeChanges              = &H200
%dbRunAsync                = &H400
%dbExecDirect              = &H800

' enum LockTypeEnum
%dbPessimistic             = &H2
%dbOptimistic              = &H3
%dbOptimisticValue         = &H1
%dbOptimisticBatch         = &H5

' enum UpdateCriteriaEnum
%dbCriteriaKey             = &H1
%dbCriteriaModValues       = &H2
%dbCriteriaAllCols         = &H4
%dbCriteriaTimestamp       = &H8
%dbCriteriaDeleteInsert    = &H10
%dbCriteriaUpdate          = &H20

' enum FieldAttributeEnum
%dbFixedField              = &H1
%dbVariableField           = &H2
%dbAutoIncrField           = &H10
%dbUpdatableField          = &H20
%dbSystemField             = &H2000
%dbHyperlinkField          = &H8000
%dbDescending              = &H1

' enum DataTypeEnum
%dbBoolean                 = 1
%dbByte                    = 2
%dbInteger                 = 3
%dbLong                    = 4
%dbCurrency                = 5
%dbSingle                  = 6
%dbDouble                  = 7
%dbDate                    = 8
%dbBinary                  = 9
%dbText                    = 10
%dbLongBinary              = 11
%dbMemo                    = 12
%dbGUID                    = 15
%dbBigInt                  = 16
%dbVarBinary               = 17
%dbChar                    = 18
%dbNumeric                 = 19
%dbDecimal                 = 20
%dbFloat                   = 21
%dbTime                    = 22
%dbTimeStamp               = 23

' enum RelationAttributeEnum
%dbRelationUnique          = &H1
%dbRelationDontEnforce     = &H2
%dbRelationInherited       = &H4
%dbRelationUpdateCascade   = &H100
%dbRelationDeleteCascade   = &H1000
%dbRelationLeft            = &H1000000
%dbRelationRight           = &H2000000

' enum TableDefAttributeEnum
%dbAttachExclusive         = &H10000
%dbAttachSavePWD           = &H20000
%dbSystemObject            = &H80000002
%dbAttachedTable           = &H40000000
%dbAttachedODBC            = &H20000000
%dbHiddenObject            = &H1

' enum QueryDefTypeEnum
%dbQSelect                 = &H0
%dbQProcedure              = &HE0
%dbQAction                 = &HF0
%dbQCrosstab               = &H10
%dbQDelete                 = &H20
%dbQUpdate                 = &H30
%dbQAppend                 = &H40
%dbQMakeTable              = &H50
%dbQDDL                    = &H60
%dbQSQLPassThrough         = &H70
%dbQSetOperation           = &H80
%dbQSPTBulk                = &H90
%dbQCompound               = &HA0

' enum QueryDefStateEnum
%dbQPrepare                = 1
%dbQUnprepare              = 2

' enum DatabaseTypeEnum
%dbVersion10               = 1
%dbEncrypt                 = 2
%dbDecrypt                 = 4
%dbVersion11               = 8
%dbVersion20               = 16
%dbVersion30               = 32
%dbVersion40               = 64

' enum CollatingOrderEnum
%dbSortNeutral             = &H400
%dbSortArabic              = &H401
%dbSortCyrillic            = &H419
%dbSortCzech               = &H405
%dbSortDutch               = &H413
%dbSortGeneral             = &H409
%dbSortGreek               = &H408
%dbSortHebrew              = &H40D
%dbSortHungarian           = &H40E
%dbSortIcelandic           = &H40F
%dbSortNorwdan             = &H406
%dbSortPDXIntl             = &H409
%dbSortPDXNor              = &H406
%dbSortPDXSwe              = &H41D
%dbSortPolish              = &H415
%dbSortSpanish             = &H40A
%dbSortSwedFin             = &H41D
%dbSortTurkish             = &H41F
%dbSortJapanese            = &H411
%dbSortChineseSimplified   = &H804
%dbSortChineseTraditional  = &H404
%dbSortKorean              = &H412
%dbSortThai                = &H41E
%dbSortSlovenian           = &H424
%dbSortUndefined           = -1

' enum IdleEnum
%dbFreeLocks               = 1
%dbRefreshCache            = 8

' enum PermissionEnum
%dbSecNoAccess             = 0
%dbSecFullAccess           = &HFFFFF
%dbSecDelete               = &H10000
%dbSecReadSec              = &H20000
%dbSecWriteSec             = &H40000
%dbSecWriteOwner           = &H80000
%dbSecDBCreate             = &H1
%dbSecDBOpen               = &H2
%dbSecDBExclusive          = &H4
%dbSecDBAdmin              = &H8
%dbSecCreate               = &H1
%dbSecReadDef              = &H4
%dbSecWriteDef             = &H1000C
%dbSecRetrieveData         = &H14
%dbSecInsertData           = &H20
%dbSecReplaceData          = &H40
%dbSecDeleteData           = &H80

' enum SynchronizeTypeEnum
%dbRepExportChanges        = &H1
%dbRepImportChanges        = &H2
%dbRepImpExpChanges        = &H4
%dbRepSyncInternet         = &H10

' enum ReplicaTypeEnum
%dbRepMakeReadOnly         = &H2
%dbRepMakePartial          = &H1

' enum WorkspaceTypeEnum
%dbUseODBC                 = 1
%dbUseJet                  = 2

' enum CursorDriverEnum
%dbUseDefaultCursor        = -1
%dbUseODBCCursor           = 1
%dbUseServerCursor         = 2
%dbUseClientBatchCursor    = 3
%dbUseNoCursor             = 4

' enum DriverPromptEnum
%dbDriverPrompt            = 2
%dbDriverNoPrompt          = 1
%dbDriverComplete          = 0
%dbDriverCompleteRequired  = 3

' enum SetOptionEnum
%dbPageTimeout             = 6
%dbLockRetry               = 57
%dbMaxBufferSize           = 8
%dbUserCommitSync          = 58
%dbImplicitCommitSync      = 59
%dbExclusiveAsyncDelay     = 60
%dbSharedAsyncDelay        = 61
%dbMaxLocksPerFile         = 62
%dbLockDelay               = 63
%dbRecycleLVs              = 65
%dbFlushTransactionTimeout = 66

' enum ParameterDirectionEnum
%dbParamInput              = 1
%dbParamOutput             = 2
%dbParamInputOutput        = 3
%dbParamReturnValue        = 4

' enum UpdateTypeEnum
%dbUpdateBatch             = 4
%dbUpdateRegular           = 1
%dbUpdateCurrentRecord     = 2

' enum RecordStatusEnum
%dbRecordUnmodified        = 0
%dbRecordModified          = 1
%dbRecordNew               = 2
%dbRecordDeleted           = 3
%dbRecordDBDeleted         = 4

' enum CommitTransOptionsEnum
%dbForceOSFlush            = 1

' enum _DAOSuppHelp
%LogMessages               = 0
%KeepLocal                 = 0
%Replicable                = 0
%ReplicableBool            = 0
%V1xNullBehavior           = 0

$dbLangArabic             = ";LANGID=0x0401;CP=1256;COUNTRY=0"
$dbLangCzech              = ";LANGID=0x0405;CP=1250;COUNTRY=0"
$dbLangDutch              = ";LANGID=0x0413;CP=1252;COUNTRY=0"
$dbLangGeneral            = ";LANGID=0x0409;CP=1252;COUNTRY=0"
$dbLangGreek              = ";LANGID=0x0408;CP=1253;COUNTRY=0"
$dbLangHebrew             = ";LANGID=0x040D;CP=1255;COUNTRY=0"
$dbLangHungarian          = ";LANGID=0x040E;CP=1250;COUNTRY=0"
$dbLangIcelandic          = ";LANGID=0x040F;CP=1252;COUNTRY=0"
$dbLangNordic             = ";LANGID=0x041D;CP=1252;COUNTRY=0"
$dbLangNorwDan            = ";LANGID=0x0406;CP=1252;COUNTRY=0"
$dbLangPolish             = ";LANGID=0x0415;CP=1250;COUNTRY=0"
$dbLangCyrillic           = ";LANGID=0x0419;CP=1251;COUNTRY=0"
$dbLangSpanish            = ";LANGID=0x040A;CP=1252;COUNTRY=0"
$dbLangSwedFin            = ";LANGID=0x041D;CP=1252;COUNTRY=0"
$dbLangTurkish            = ";LANGID=0x041F;CP=1254;COUNTRY=0"
$dbLangJapanese           = ";LANGID=0x0411;CP=932;COUNTRY=0"
$dbLangChineseSimplified  = ";LANGID=0x0804;CP=936;COUNTRY=0"
$dbLangChineseTraditional = ";LANGID=0x0404;CP=950;COUNTRY=0"
$dbLangKorean             = ";LANGID=0x0412;CP=949;COUNTRY=0"
$dbLangThai               = ";LANGID=0x041E;CP=874;COUNTRY=0"
$dbLangSlovenian          = ";LANGID=0x0424;CP=1250;COUNTRY=0"


' ########################################################################################
' Interface name = _Collection
' IID = {000000A0-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DAOCollection_INTERFACE_DEFINED)
    %DAOCollection_INTERFACE_DEFINED = 1

INTERFACE DAOCollection $IID_DAOCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _DynaCollection
' IID = {000000A2-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAODynaCollection_INTERFACE_DEFINED)
    %DAODynaCollection_INTERFACE_DEFINED = 1

INTERFACE DAODynaCollection $IID_DAODynaCollection

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODynaCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _DAO
' IID = {0000000A-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DAODAO_INTERFACE_DEFINED)
    %DAODAO_INTERFACE_DEFINED = 1

INTERFACE DAODAO $IID_DAODAO

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODAO_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _DBEngine
' IID = {00000021-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAODBEngine_INTERFACE_DEFINED)
    %DAODBEngine_INTERFACE_DEFINED = 1

INTERFACE DAODBEngine $IID_DAODBEngine

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' DBEngine Methods
   ' =====================================================================================
   PROPERTY GET Version <1610809344> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET IniPath <1610809345> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET IniPath <1610809345> ( _                ' VTable offset = 40
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DefaultUser <1610809347> ( _            ' VTable offset = 44
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DefaultPassword <1610809348> ( _        ' VTable offset = 48
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoginTimeout <1610809349> ( _           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET LoginTimeout <1610809349> ( _           ' VTable offset = 56
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Workspaces <0> ( _                      ' VTable offset = 60
   ) AS DAOWorkspaces                                   ' __retval_out Workspaces** ppworks
   ' =====================================================================================
   PROPERTY GET Errors <1610809352> ( _                 ' VTable offset = 64
   ) AS DAOErrors                                       ' __retval_out Errors** pperrs
   ' =====================================================================================
   METHOD Idle <1610809353> ( _                         ' VTable offset = 68
     OPTIONAL BYVAL Action AS VARIANT _                 ' __in_opt VARIANT Action
   )                                                    ' void
   ' =====================================================================================
   METHOD CompactDatabase <1610809354> ( _              ' VTable offset = 72
     BYVAL SrcName AS WSTRING _                         ' __in BSTR SrcName
   , BYVAL DstName AS WSTRING _                         ' __in BSTR DstName
   , OPTIONAL BYVAL DstLocale AS VARIANT _              ' __in_opt VARIANT DstLocale
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL SrcLocale AS VARIANT _              ' __in_opt VARIANT SrcLocale
   )                                                    ' void
   ' =====================================================================================
   METHOD RepairDatabase <1610809355> ( _               ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterDatabase <1610809356> ( _             ' VTable offset = 80
     BYVAL Dsn AS WSTRING _                             ' __in BSTR Dsn
   , BYVAL Driver AS WSTRING _                          ' __in BSTR Driver
   , BYVAL Silent AS INTEGER _                          ' __in VARIANT_BOOL Silent
   , BYVAL Attributes AS WSTRING _                      ' __in BSTR Attributes
   )                                                    ' void
   ' =====================================================================================
   METHOD v30_CreateWorkspace_ <1610809357> ( _         ' VTable offset = 84
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL UserName AS WSTRING _                        ' __in BSTR UserName
   , BYVAL Password AS WSTRING _                        ' __in BSTR Password
   ) AS DAOWorkspace                                    ' __retval_out Workspace** ppwrk
   ' =====================================================================================
   METHOD OpenDatabase <1610809358> ( _                 ' VTable offset = 88
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL ReadOnly AS VARIANT _               ' __in_opt VARIANT ReadOnly
   , OPTIONAL BYVAL Connect AS VARIANT _                ' __in_opt VARIANT Connect
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================
   METHOD CreateDatabase <1610809359> ( _               ' VTable offset = 92
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Locale AS WSTRING _                          ' __in BSTR Locale
   , OPTIONAL BYVAL Option AS VARIANT _                 ' __in_opt VARIANT Option
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================
   METHOD FreeLocks <1610809360> ( _                    ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD BeginTrans <1610809361> ( _                   ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitTrans <1610809362> ( _                  ' VTable offset = 104
     OPTIONAL BYVAL Option AS LONG _                    ' __in_opt long Option defaultvalue = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Rollback <1610809363> ( _                     ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultWorkspace <1610809364> ( _          ' VTable offset = 112
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Password AS WSTRING _                        ' __in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDataAccessOption <1610809365> ( _          ' VTable offset = 116
     BYVAL Option AS INTEGER _                          ' __in short Option
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   METHOD ISAMStats <1610809366> ( _                    ' VTable offset = 120
     BYVAL StatNum AS LONG _                            ' __in long StatNum
   , OPTIONAL BYVAL Reset AS VARIANT _                  ' __in_opt VARIANT Reset
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET SystemDB <1610809367> ( _               ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET SystemDB <1610809367> ( _               ' VTable offset = 128
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateWorkspace <1610809369> ( _              ' VTable offset = 132
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL UserName AS WSTRING _                        ' __in BSTR UserName
   , BYVAL Password AS WSTRING _                        ' __in BSTR Password
   , OPTIONAL BYVAL UseType AS VARIANT _                ' __in_opt VARIANT UseType
   ) AS DAOWorkspace                                    ' __retval_out Workspace** ppwrk
   ' =====================================================================================
   METHOD OpenConnection <1610809370> ( _               ' VTable offset = 136
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL ReadOnly AS VARIANT _               ' __in_opt VARIANT ReadOnly
   , OPTIONAL BYVAL Connect AS VARIANT _                ' __in_opt VARIANT Connect
   ) AS DAOConnection                                   ' __retval_out Connection** ppconn
   ' =====================================================================================
   PROPERTY GET DefaultType <1610809371> ( _            ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long* Option
   ' =====================================================================================
   PROPERTY SET DefaultType <1610809371> ( _            ' VTable offset = 144
     BYVAL Option AS LONG _                             ' __in long Option
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOption <1610809373> ( _                    ' VTable offset = 148
     BYVAL Option AS LONG _                             ' __in long Option
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODBEngine_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Error
' IID = {00000023-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DAOError_INTERFACE_DEFINED)
    %DAOError_INTERFACE_DEFINED = 1

INTERFACE DAOError $IID_DAOError

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Number <1610743808> ( _                 ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Source <1610743809> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Description <0> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET HelpFile <1610743811> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET HelpContext <1610743812> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOError_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Errors
' IID = {00000025-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAOErrors_INTERFACE_DEFINED)
    %DAOErrors_INTERFACE_DEFINED = 1

INTERFACE DAOErrors $IID_DAOErrors

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Errors Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOError                                        ' __retval_out Error** pperr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOErrors_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Property
' IID = {00000027-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOProperty_INTERFACE_DEFINED)
    %DAOProperty_INTERFACE_DEFINED = 1

INTERFACE DAOProperty $IID_DAOProperty

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Property Methods
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT* pval
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 36
     BYVAL pval AS VARIANT _                            ' __in VARIANT pval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610809346> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809346> ( _                   ' VTable offset = 44
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610809348> ( _                   ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short* ptype
   ' =====================================================================================
   PROPERTY SET Type <1610809348> ( _                   ' VTable offset = 52
     BYVAL ptype AS INTEGER _                           ' __in short ptype
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Inherited <1610809350> ( _              ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Properties
' IID = {00000029-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOProperties_INTERFACE_DEFINED)
    %DAOProperties_INTERFACE_DEFINED = 1

INTERFACE DAOProperties $IID_DAOProperties

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Properties Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOProperty                                     ' __retval_out Property** ppprop
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Workspace
' IID = {00000039-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOWorkspace_INTERFACE_DEFINED)
    %DAOWorkspace_INTERFACE_DEFINED = 1

INTERFACE DAOWorkspace $IID_DAOWorkspace

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Workspace Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809344> ( _                   ' VTable offset = 36
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserName <1610809346> ( _               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET v30_UserName_ <1610809347> ( _          ' VTable offset = 44
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET v30_Password_ <1610809348> ( _          ' VTable offset = 48
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsolateODBCTrans <1610809349> ( _       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET IsolateODBCTrans <1610809349> ( _       ' VTable offset = 56
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Databases <0> ( _                       ' VTable offset = 60
   ) AS DAODatabases                                    ' __retval_out Databases** ppdbs
   ' =====================================================================================
   PROPERTY GET Users <1610809352> ( _                  ' VTable offset = 64
   ) AS DAOUsers                                        ' __retval_out Users** ppusrs
   ' =====================================================================================
   PROPERTY GET Groups <1610809353> ( _                 ' VTable offset = 68
   ) AS DAOGroups                                       ' __retval_out Groups** ppgrps
   ' =====================================================================================
   METHOD BeginTrans <1610809354> ( _                   ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitTrans <1610809355> ( _                  ' VTable offset = 76
     OPTIONAL BYVAL Options AS LONG _                   ' __in_opt long Options defaultvalue = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1610809356> ( _                        ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Rollback <1610809357> ( _                     ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenDatabase <1610809358> ( _                 ' VTable offset = 88
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL ReadOnly AS VARIANT _               ' __in_opt VARIANT ReadOnly
   , OPTIONAL BYVAL Connect AS VARIANT _                ' __in_opt VARIANT Connect
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================
   METHOD CreateDatabase <1610809359> ( _               ' VTable offset = 92
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Connect AS WSTRING _                         ' __in BSTR Connect
   , OPTIONAL BYVAL Option AS VARIANT _                 ' __in_opt VARIANT Option
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================
   METHOD CreateUser <1610809360> ( _                   ' VTable offset = 96
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL PID AS VARIANT _                    ' __in_opt VARIANT PID
   , OPTIONAL BYVAL Password AS VARIANT _               ' __in_opt VARIANT Password
   ) AS DAOUser                                         ' __retval_out User** ppusr
   ' =====================================================================================
   METHOD CreateGroup <1610809361> ( _                  ' VTable offset = 100
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL PID AS VARIANT _                    ' __in_opt VARIANT PID
   ) AS DAOGroup                                        ' __retval_out Group** ppgrp
   ' =====================================================================================
   METHOD OpenConnection <1610809362> ( _               ' VTable offset = 104
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL ReadOnly AS VARIANT _               ' __in_opt VARIANT ReadOnly
   , OPTIONAL BYVAL Connect AS VARIANT _                ' __in_opt VARIANT Connect
   ) AS DAOConnection                                   ' __retval_out Connection** ppconn
   ' =====================================================================================
   PROPERTY GET LoginTimeout <1610809363> ( _           ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long* pTimeout
   ' =====================================================================================
   PROPERTY SET LoginTimeout <1610809363> ( _           ' VTable offset = 112
     BYVAL LONG _                                       ' __in long pTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultCursorDriver <1610809365> ( _    ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long* pCursorType
   ' =====================================================================================
   PROPERTY SET DefaultCursorDriver <1610809365> ( _    ' VTable offset = 120
     BYVAL pCursorType AS LONG _                        ' __in long pCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hEnv <1610809367> ( _                   ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long* phEnv
   ' =====================================================================================
   PROPERTY GET Type <1610809368> ( _                   ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long* ptype
   ' =====================================================================================
   PROPERTY GET Connections <1610809369> ( _            ' VTable offset = 132
   ) AS DAOConnections                                  ' __retval_out Connections** ppcns
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOWorkspace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Workspaces
' IID = {0000003B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOWorkspaces_INTERFACE_DEFINED)
    %DAOWorkspaces_INTERFACE_DEFINED = 1

INTERFACE DAOWorkspaces $IID_DAOWorkspaces

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Workspaces Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOWorkspace                                    ' __retval_out Workspace** ppwrk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOWorkspaces_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Connection
' IID = {00000041-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DAOConnection_INTERFACE_DEFINED)
    %DAOConnection_INTERFACE_DEFINED = 1

INTERFACE DAOConnection $IID_DAOConnection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Connect <1610743809> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Database <1610743810> ( _               ' VTable offset = 36
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================
   PROPERTY GET hDbc <1610743811> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* phDbc
   ' =====================================================================================
   PROPERTY GET QueryTimeout <1610743812> ( _           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* pSeconds
   ' =====================================================================================
   PROPERTY SET QueryTimeout <1610743812> ( _           ' VTable offset = 48
     BYVAL pSeconds AS INTEGER _                        ' __in short pSeconds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transactions <1610743814> ( _           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET RecordsAffected <1610743815> ( _        ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* pRecords
   ' =====================================================================================
   PROPERTY GET StillExecuting <1610743816> ( _         ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStillExec
   ' =====================================================================================
   PROPERTY GET Updatable <1610743817> ( _              ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStillExec
   ' =====================================================================================
   PROPERTY GET QueryDefs <0> ( _                       ' VTable offset = 68
   ) AS DAOQueryDefs                                    ' __retval_out QueryDefs** ppqdfs
   ' =====================================================================================
   PROPERTY GET Recordsets <1610743819> ( _             ' VTable offset = 72
   ) AS DAORecordsets                                   ' __retval_out Recordsets** pprsts
   ' =====================================================================================
   METHOD Cancel <1610743820> ( _                       ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1610743821> ( _                        ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateQueryDef <1610743822> ( _               ' VTable offset = 84
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL SQLText AS VARIANT _                ' __in_opt VARIANT SQLText
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdf
   ' =====================================================================================
   METHOD Execute <1610743823> ( _                      ' VTable offset = 88
     BYVAL Query AS WSTRING _                           ' __in BSTR Query
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenRecordset <1610743824> ( _                ' VTable offset = 92
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL LockEdit AS VARIANT _               ' __in_opt VARIANT LockEdit
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Connections
' IID = {00000043-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAOConnections_INTERFACE_DEFINED)
    %DAOConnections_INTERFACE_DEFINED = 1

INTERFACE DAOConnections $IID_DAOConnections

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Errors Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOError                                        ' __retval_out Connection** ppconn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOConnections_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Database
' IID = {00000071-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAODatabase_INTERFACE_DEFINED)
    %DAODatabase_INTERFACE_DEFINED = 1

INTERFACE DAODatabase $IID_DAODatabase

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Database Methods
   ' =====================================================================================
   PROPERTY GET CollatingOrder <1610809344> ( _         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Connect <1610809345> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Name <1610809346> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET QueryTimeout <1610809347> ( _           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET QueryTimeout <1610809347> ( _           ' VTable offset = 48
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transactions <1610809349> ( _           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Updatable <1610809350> ( _              ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Version <1610809351> ( _                ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET RecordsAffected <1610809352> ( _        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET TableDefs <0> ( _                       ' VTable offset = 68
   ) AS DAOTableDefs                                    ' __retval_out TableDefs** pptdfs
   ' =====================================================================================
   PROPERTY GET QueryDefs <1610809354> ( _              ' VTable offset = 72
   ) AS DAOQueryDefs                                    ' __retval_out QueryDefs** ppqdfs
   ' =====================================================================================
   PROPERTY GET Relations <1610809355> ( _              ' VTable offset = 76
   ) AS DAORelations                                    ' __retval_out Relations** pprls
   ' =====================================================================================
   PROPERTY GET Containers <1610809356> ( _             ' VTable offset = 80
   ) AS DAOContainers                                   ' __retval_out Containers** ppctns
   ' =====================================================================================
   PROPERTY GET Recordsets <1610809357> ( _             ' VTable offset = 84
   ) AS DAORecordsets                                   ' __retval_out Recordsets** pprsts
   ' =====================================================================================
   METHOD Close <1610809358> ( _                        ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <1610809359> ( _                      ' VTable offset = 92
     BYVAL Query AS WSTRING _                           ' __in BSTR Query
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   )                                                    ' void
   ' =====================================================================================
   METHOD v30_OpenRecordset_ <1610809360> ( _           ' VTable offset = 96
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CreateProperty <1610809361> ( _               ' VTable offset = 100
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================
   METHOD CreateRelation <1610809362> ( _               ' VTable offset = 104
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Table AS VARIANT _                  ' __in_opt VARIANT Table
   , OPTIONAL BYVAL ForeignTable AS VARIANT _           ' __in_opt VARIANT ForeignTable
   , OPTIONAL BYVAL Attributes AS VARIANT _             ' __in_opt VARIANT Attributes
   ) AS DAORelation                                     '  __retval_out Relation** pprel
   ' =====================================================================================
   METHOD CreateTableDef <1610809363> ( _               ' VTable offset = 108
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Attributes AS VARIANT _             ' __in_opt VARIANT Attributes
   , OPTIONAL BYVAL SourceTableName AS VARIANT _        ' __in_opt VARIANT SourceTableName
   , OPTIONAL BYVAL Connect AS VARIANT _                ' __in_opt VARIANT Connect
   ) AS DAOTableDef                                     ' __retval_out TableDef** pptdf
   ' =====================================================================================
   METHOD BeginTrans <1610809364> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitTrans <1610809365> ( _                  ' VTable offset = 116
     OPTIONAL BYVAL Options AS LONG _                   ' __in_opt long Options defaultvalue = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Rollback <1610809366> ( _                     ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDynaset <1610809367> ( _                ' VTable offset = 124
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL Inconsistent AS VARIANT _           ' __in_opt VARIANT Inconsistent
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CreateQueryDef <1610809368> ( _               ' VTable offset = 128
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL SQLText AS VARIANT _                ' __in_opt VARIANT SQLText
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdf
   ' =====================================================================================
   METHOD CreateSnapshot <1610809369> ( _               ' VTable offset = 132
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD DeleteQueryDef <1610809370> ( _               ' VTable offset = 136
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecuteSQL <1610809371> ( _                   ' VTable offset = 140
     BYVAL SQL AS WSTRING _                             ' __in BSTR SQL
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   METHOD ListFields <1610809372> ( _                   ' VTable offset = 144
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD ListTables <1610809373> ( _                   ' VTable offset = 148
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD OpenQueryDef <1610809374> ( _                 ' VTable offset = 152
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdf
   ' =====================================================================================
   METHOD OpenTable <1610809375> ( _                    ' VTable offset = 156
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   PROPERTY GET ReplicaID <1610809376> ( _              ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET DesignMasterID <1610809377> ( _         ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET DesignMasterID <1610809377> ( _         ' VTable offset = 168
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   METHOD Synchronize <1610809379> ( _                  ' VTable offset = 172
     BYVAL DbPathName AS WSTRING _                      ' __in BSTR DbPathName
   , OPTIONAL BYVAL ExchangeType AS VARIANT _           ' __in_opt VARIANT ExchangeType
   )                                                    ' void
   ' =====================================================================================
   METHOD MakeReplica <1610809380> ( _                  ' VTable offset = 176
     BYVAL PathName AS WSTRING _                        ' __in BSTR PathName
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Connect <1610809345> ( _                ' VTable offset = 180
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   METHOD NewPassword <1610809382> ( _                  ' VTable offset = 184
     BYVAL bstrOld AS WSTRING _                         ' __in BSTR bstrOld
   , BYVAL bstrNew AS WSTRING _                         ' __in BSTR bstrNew
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenRecordset <1610809383> ( _                ' VTable offset = 188
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL LockEdit AS VARIANT _               ' __in_opt VARIANT LockEdit
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   PROPERTY GET Connection <1610809384> ( _             ' VTable offset = 192
   ) AS DAOConnection                                   ' __retval_out Connection** ppCn
   ' =====================================================================================
   METHOD PopulatePartial <1610809385> ( _              ' VTable offset = 196
     BYVAL DbPathName AS WSTRING _                      ' __in BSTR DbPathName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODatabase_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Databases
' IID = {00000073-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAODatabases_INTERFACE_DEFINED)
    %DAODatabases_INTERFACE_DEFINED = 1

INTERFACE DAODatabases $IID_DAODatabases

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Databases Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAODatabase                                     ' __retval_out Database** ppDb
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODatabases_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _TableDef
' IID = {00000049-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOTableDef_INTERFACE_DEFINED)
    %DAOTableDef_INTERFACE_DEFINED = 1

INTERFACE DAOTableDef $IID_DAOTableDef

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' TableDef Methods
   ' =====================================================================================
   PROPERTY GET Attributes <1610809344> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Attributes <1610809344> ( _             ' VTable offset = 36
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Connect <1610809346> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Connect <1610809346> ( _                ' VTable offset = 44
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DateCreated <1610809348> ( _            ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET LastUpdated <1610809349> ( _            ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET Name <1610809350> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809350> ( _                   ' VTable offset = 60
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceTableName <1610809352> ( _        ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET SourceTableName <1610809352> ( _        ' VTable offset = 68
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Updatable <1610809354> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET ValidationText <1610809355> ( _         ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ValidationText <1610809355> ( _         ' VTable offset = 80
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValidationRule <1610809357> ( _         ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ValidationRule <1610809357> ( _         ' VTable offset = 88
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordCount <1610809359> ( _            ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 96
   ) AS DAOFields                                       ' __retval_out Fields** ppflds
   ' =====================================================================================
   PROPERTY GET Indexes <1610809361> ( _                ' VTable offset = 100
   ) AS DAOIndexes                                      ' __retval_out Indexes** ppidxs
   ' =====================================================================================
   METHOD OpenRecordset <1610809362> ( _                ' VTable offset = 104
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD RefreshLink <1610809363> ( _                  ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateField <1610809364> ( _                  ' VTable offset = 112
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Size AS VARIANT _                   ' __in_opt VARIANT Size
   ) AS DAOField                                        ' __retval_out Field** ppfld
   ' =====================================================================================
   METHOD CreateIndex <1610809365> ( _                  ' VTable offset = 116
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   ) AS DAOIndex                                        ' __retval_out Index** ppidx
   ' =====================================================================================
   METHOD CreateProperty <1610809366> ( _               ' VTable offset = 120
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================
   PROPERTY GET ConflictTable <1610809367> ( _          ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET ReplicaFilter <1610809368> ( _          ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT* pFilter
   ' =====================================================================================
   PROPERTY SET ReplicaFilter <1610809368> ( _          ' VTable offset = 132
     BYVAL pFilter AS VARIANT _                         ' __in VARIANT pFilter
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOTableDef_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = TableDefs
' IID = {0000004B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOTableDefs_INTERFACE_DEFINED)
    %DAOTableDefs_INTERFACE_DEFINED = 1

INTERFACE DAOTableDefs $IID_DAOTableDefs

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' TableDefs Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOTableDef                                     ' __retval_out TableDef** pptdf
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOTableDefs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _QueryDef
' IID = {00000079-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOQueryDef_INTERFACE_DEFINED)
    %DAOQueryDef_INTERFACE_DEFINED = 1

INTERFACE DAOQueryDef $IID_DAOQueryDef

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' QueryDef Methods
   ' =====================================================================================
   PROPERTY GET DateCreated <1610809344> ( _            ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET LastUpdated <1610809345> ( _            ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET Name <1610809346> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809346> ( _                   ' VTable offset = 44
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ODBCTimeout <1610809348> ( _            ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET ODBCTimeout <1610809348> ( _            ' VTable offset = 52
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610809350> ( _                   ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short* pi
   ' =====================================================================================
   PROPERTY GET SQL <1610809351> ( _                    ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET SQL <1610809351> ( _                    ' VTable offset = 64
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Updatable <1610809353> ( _              ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Connect <1610809354> ( _                ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Connect <1610809354> ( _                ' VTable offset = 76
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReturnsRecords <1610809356> ( _         ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET ReturnsRecords <1610809356> ( _         ' VTable offset = 84
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordsAffected <1610809358> ( _        ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Fields <1610809359> ( _                 ' VTable offset = 92
   ) AS DAOFields                                       ' __retval_out Fields** ppflds
   ' =====================================================================================
   PROPERTY GET Parameters <0> ( _                      ' VTable offset = 96
   ) AS DAOParameters                                   ' __retval_out Parameters** ppprms
   ' =====================================================================================
   METHOD Close <1610809361> ( _                        ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD v30_OpenRecordset_ <1610809362> ( _           ' VTable offset = 104
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD v30__OpenRecordset_ <1610809363> ( _          ' VTable offset = 108
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD Copy_ <1610809364> ( _                        ' VTable offset = 112
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdf
   ' =====================================================================================
   METHOD Execute <1610809365> ( _                      ' VTable offset = 116
     OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   )                                                    ' void
   ' =====================================================================================
   METHOD Compare <1610809366> ( _                      ' VTable offset = 120
     BYVAL pQdef AS DAOQueryDef _                       ' __in QueryDef* pQdef
   , BYREF lps AS INTEGER _                             ' __in short* lps
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDynaset <1610809367> ( _                ' VTable offset = 124
     OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL Inconsistent AS VARIANT _           ' __in_opt VARIANT Inconsistent
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CreateSnapshot <1610809368> ( _               ' VTable offset = 128
     OPTIONAL BYVAL Options AS VARIANT _                           ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD ListParameters <1610809369> ( _               ' VTable offset = 132
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CreateProperty <1610809370> ( _               ' VTable offset = 136
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================
   METHOD OpenRecordset <1610809371> ( _                ' VTable offset = 140
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL LockEdit AS VARIANT _               ' __in_opt VARIANT LockEdit
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst)
   ' =====================================================================================
   METHOD OpenRecordset_ <1610809372> ( _               ' VTable offset = 144
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL LockEdit AS VARIANT _               ' __in_opt VARIANT LockEdit
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst)
   ' =====================================================================================
   METHOD Cancel <1610809373> ( _                       ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hStmt <1610809374> ( _                  ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long* phStmt
   ' =====================================================================================
   PROPERTY GET MaxRecords <1610809375> ( _             ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long* pMxRecs
   ' =====================================================================================
   PROPERTY SET MaxRecords <1610809375> ( _             ' VTable offset = 160
     BYVAL pMxRecs AS LONG _                            ' __in long pMxRecs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StillExecuting <1610809377> ( _         ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStillExec
   ' =====================================================================================
   PROPERTY GET CacheSize <1610809378> ( _              ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long* lCacheSize
   ' =====================================================================================
   PROPERTY SET CacheSize <1610809378> ( _              ' VTable offset = 172
     BYVAL lCacheSize AS LONG _                         ' __in long lCacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Prepare <1610809380> ( _                ' VTable offset = 176
   ) AS VARIANT                                         ' __retval_out VARIANT* pb
   ' =====================================================================================
   PROPERTY SET Prepare <1610809380> ( _                ' VTable offset = 180
     BYVAL pb AS VARIANT _                              ' __in VARIANT pb
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOQueryDef_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = QueryDefs
' IID = {0000007B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOQueryDefs_INTERFACE_DEFINED)
    %DAOQueryDefs_INTERFACE_DEFINED = 1

INTERFACE DAOQueryDefs $IID_DAOQueryDefs

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' QueryDefs Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdef
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOQueryDefs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Recordset
' IID = {00000031-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAORecordset_INTERFACE_DEFINED)
    %DAORecordset_INTERFACE_DEFINED = 1

INTERFACE DAORecordset $IID_DAORecordset

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset Methods
   ' =====================================================================================
   PROPERTY GET BOF <101> ( _                           ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Bookmark <102> ( _                      ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out SAFEARRAY(unsigned char)* ppsach
   ' =====================================================================================
   PROPERTY SET Bookmark <102> ( _                      ' VTable offset = 40
     BYVAL ppsach AS DWORD _                            ' __in SAFEARRAY(unsigned char)* ppsach
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bookmarkable <103> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET DateCreated <104> ( _                   ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET EOF <105> ( _                           ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Filter <106> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Filter <106> ( _                        ' VTable offset = 60
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <107> ( _                         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Index <107> ( _                         ' VTable offset = 68
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LastModified <108> ( _                  ' VTable offset = 72
   ) AS DWORD                                           ' __retval_out SAFEARRAY(unsigned char)* ppsa
   ' =====================================================================================
   PROPERTY GET LastUpdated <109> ( _                   ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET LockEdits <110> ( _                     ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET LockEdits <110> ( _                     ' VTable offset = 84
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <111> ( _                          ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET NoMatch <112> ( _                       ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Sort <113> ( _                          ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Sort <113> ( _                          ' VTable offset = 100
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transactions <114> ( _                  ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Type <115> ( _                          ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY GET RecordCount <116> ( _                   ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Updatable <117> ( _                     ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Restartable <118> ( _                   ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET ValidationText <119> ( _                ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET ValidationRule <120> ( _                ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET CacheStart <121> ( _                    ' VTable offset = 132
   ) AS DWORD                                           ' __retval_out SAFEARRAY(unsigned char)* ppsa
   ' =====================================================================================
   PROPERTY SET CacheStart <121> ( _                    ' VTable offset = 136
     BYVAL ppsa AS DWORD _                              ' __in SAFEARRAY(unsigned char)* ppsa
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheSize <122> ( _                     ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET CacheSize <122> ( _                     ' VTable offset = 144
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PercentPosition <123> ( _               ' VTable offset = 148
   ) AS SINGLE                                          ' __retval_out single* pd
   ' =====================================================================================
   PROPERTY SET PercentPosition <123> ( _               ' VTable offset = 152
     BYVAL pd AS SINGLE _                               ' __in single pd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsolutePosition <124> ( _              ' VTable offset = 156
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET AbsolutePosition <124> ( _              ' VTable offset = 160
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditMode <125> ( _                      ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out short* pi
   ' =====================================================================================
   PROPERTY GET ODBCFetchCount <126> ( _                ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET ODBCFetchDelay <127> ( _                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Parent <128> ( _                        ' VTable offset = 176
   ) AS DAODatabase                                     ' __retval_out Database** pdb
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 180
   ) AS DAOFields                                       ' __retval_out Fields** ppflds
   ' =====================================================================================
   PROPERTY GET Indexes <130> ( _                       ' VTable offset = 184
   ) AS DAOIndexes                                      ' __retval_out Indexes** ppidxs
   ' =====================================================================================
   METHOD v30_CancelUpdate_ <131> ( _                   ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD AddNew <132> ( _                              ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <133> ( _                               ' VTable offset = 196
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenRecordset <134> ( _                       ' VTable offset = 200
     OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD Delete <135> ( _                              ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   METHOD Edit <136> ( _                                ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFirst <137> ( _                           ' VTable offset = 212
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   METHOD FindLast <138> ( _                            ' VTable offset = 216
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   METHOD FindNext <139> ( _                            ' VTable offset = 220
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   METHOD FindPrevious <140> ( _                        ' VTable offset = 224
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <141> ( _                           ' VTable offset = 228
   )                                                    ' void
   ' =====================================================================================
   METHOD v30_MoveLast_ <142> ( _                       ' VTable offset = 232
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <143> ( _                            ' VTable offset = 236
   )                                                    ' void
   ' =====================================================================================
   METHOD MovePrevious <144> ( _                        ' VTable offset = 240
   )                                                    ' void
   ' =====================================================================================
   METHOD Seek <145> ( _                                ' VTable offset = 244
     BYVAL Comparison AS WSTRING _                      ' __in BSTR Comparison
   , BYVAL Key1 AS VARIANT _                            ' __in VARIANT Key1
   , OPTIONAL BYVAL Key2 AS VARIANT _                   ' __in_opt VARIANT Key2
   , OPTIONAL BYVAL Key3 AS VARIANT _                   ' __in_opt VARIANT Key3
   , OPTIONAL BYVAL Key4 AS VARIANT _                   ' __in_opt VARIANT Key4
   , OPTIONAL BYVAL Key5 AS VARIANT _                   ' __in_opt VARIANT Key5
   , OPTIONAL BYVAL Key6 AS VARIANT _                   ' __in_opt VARIANT Key6
   , OPTIONAL BYVAL Key7 AS VARIANT _                   ' __in_opt VARIANT Key7
   , OPTIONAL BYVAL Key8 AS VARIANT _                   ' __in_opt VARIANT Key8
   , OPTIONAL BYVAL Key9 AS VARIANT _                   ' __in_opt VARIANT Key9
   , OPTIONAL BYVAL Key10 AS VARIANT _                  ' __in_opt VARIANT Key10
   , OPTIONAL BYVAL Key11 AS VARIANT _                  ' __in_opt VARIANT Key11
   , OPTIONAL BYVAL Key12 AS VARIANT _                  ' __in_opt VARIANT Key12
   , OPTIONAL BYVAL Key13 AS VARIANT _                  ' __in_opt VARIANT Key13
   )                                                    ' void
   ' =====================================================================================
   METHOD v30_Update_ <146> ( _                         ' VTable offset = 248
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <147> ( _                               ' VTable offset = 252
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD Requery <148> ( _                             ' VTable offset = 256
     OPTIONAL BYVAL NewQueryDef AS VARIANT _            ' __in_opt VARIANT NewQueryDef
   )                                                    ' void
   ' =====================================================================================
   METHOD Move <149> ( _                                ' VTable offset = 260
     BYVAL Rows AS LONG _                               ' __in long Rows
   , OPTIONAL BYVAL StartBookmark AS VARIANT _          ' __in_opt VARIANT StartBookmark
   )                                                    ' void
   ' =====================================================================================
   METHOD FillCache <150> ( _                           ' VTable offset = 264
     OPTIONAL BYVAL Rows AS VARIANT _                   ' __in_opt VARIANT Rows
   , OPTIONAL BYVAL StartBookmark AS VARIANT _          ' __in_opt VARIANT StartBookmark
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateDynaset <151> ( _                       ' VTable offset = 268
     OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   , OPTIONAL BYVAL Inconsistent AS VARIANT _           ' __in_opt VARIANT Inconsistent
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CreateSnapshot <152> ( _                      ' VTable offset = 272
     OPTIONAL BYVAL Options AS VARIANT _                ' __in_opt VARIANT Options
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD CopyQueryDef <153> ( _                        ' VTable offset = 276
   ) AS DAOQueryDef                                     ' __retval_out QueryDef** ppqdf
   ' =====================================================================================
   METHOD ListFields <154> ( _                          ' VTable offset = 280
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD ListIndexes <155> ( _                         ' VTable offset = 284
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================
   METHOD GetRows <156> ( _                             ' VTable offset = 288
     OPTIONAL BYVAL NumRows AS VARIANT _                ' __in_opt VARIANT NumRows
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET Collect <-8> ( _                        ' VTable offset = 292
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY SET Collect <-8> ( _                        ' VTable offset = 296
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   , BYVAL pvar AS VARIANT _                            ' __in VARIANT pvar
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <157> ( _                              ' VTable offset = 300
   )                                                    ' void
   ' =====================================================================================
   METHOD NextRecordset <158> ( _                       ' VTable offset = 304
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET hStmt <159> ( _                         ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long* phStmt
   ' =====================================================================================
   PROPERTY GET StillExecuting <160> ( _                ' VTable offset = 312
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pStillExec
   ' =====================================================================================
   PROPERTY GET BatchSize <161> ( _                     ' VTable offset = 316
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET BatchSize <161> ( _                     ' VTable offset = 320
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BatchCollisionCount <162> ( _           ' VTable offset = 324
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET BatchCollisions <163> ( _               ' VTable offset = 328
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET Connection <164> ( _                    ' VTable offset = 332
   ) AS DAOConnection                                   ' __retval_out Connection** ppCn
   ' =====================================================================================
   PROPERTY SET putref_Connection <164> ( _             ' VTable offset = 336
     BYVAL ppCn AS DAOConnection _                      ' __in Connection* ppCn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordStatus <165> ( _                  ' VTable offset = 340
   ) AS INTEGER                                         ' __retval_out short* pi
   ' =====================================================================================
   PROPERTY GET UpdateOptions <166> ( _                 ' VTable offset = 344
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET UpdateOptions <166> ( _                 ' VTable offset = 348
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <167> ( _                        ' VTable offset = 352
     OPTIONAL BYVAL UpdateType AS LONG _                ' __in_opt long UpdateType defaultvalue = 1
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <168> ( _                              ' VTable offset = 356
     OPTIONAL BYVAL UpdateType AS LONG _                ' __in_opt long UpdateType defaultvalue = 1
   , OPTIONAL BYVAL Force AS INTEGER _                  ' __in_opt VARIANT_BOOL Force defaultvalue = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveLast <169> ( _                            ' VTable offset = 360
     OPTIONAL BYVAL Options AS LONG _                   ' __in_opt long Options defaultvalue = 0
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAORecordset_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Recordsets
' IID = {00000033-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAORecordsets_INTERFACE_DEFINED)
    %DAORecordsets_INTERFACE_DEFINED = 1

INTERFACE DAORecordsets $IID_DAORecordsets

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordsets Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAORecordset                                    ' __retval_out Recordset** pprst
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAORecordsets_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _Field
' IID = {00000051-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOField_INTERFACE_DEFINED)
    %DAOField_INTERFACE_DEFINED = 1

INTERFACE DAOField $IID_DAOField

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Field Methods
   ' =====================================================================================
   PROPERTY GET CollatingOrder <1610809344> ( _         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Type <1610809345> ( _                   ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET Type <1610809345> ( _                   ' VTable offset = 40
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610809347> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809347> ( _                   ' VTable offset = 48
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <1610809349> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Size <1610809349> ( _                   ' VTable offset = 56
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceField <1610809351> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET SourceTable <1610809352> ( _            ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 72
     BYVAL pvar AS VARIANT _                            ' __in VARIANT pvar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <1610809355> ( _             ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Attributes <1610809355> ( _             ' VTable offset = 80
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OrdinalPosition <1610809357> ( _        ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET OrdinalPosition <1610809357> ( _        ' VTable offset = 88
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValidationText <1610809359> ( _         ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ValidationText <1610809359> ( _         ' VTable offset = 96
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValidateOnSet <1610809361> ( _          ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET ValidateOnSet <1610809361> ( _          ' VTable offset = 104
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValidationRule <1610809363> ( _         ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ValidationRule <1610809363> ( _         ' VTable offset = 112
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultValue <1610809365> ( _           ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY SET DefaultValue <1610809365> ( _           ' VTable offset = 120
     BYVAL pvar AS VARIANT _                            ' __in VARIANT pvar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Required <1610809367> ( _               ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Required <1610809367> ( _               ' VTable offset = 128
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowZeroLength <1610809369> ( _        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET AllowZeroLength <1610809369> ( _        ' VTable offset = 136
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataUpdatable <1610809371> ( _          ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET ForeignName <1610809372> ( _            ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ForeignName <1610809372> ( _            ' VTable offset = 148
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   METHOD AppendChunk <1610809374> ( _                  ' VTable offset = 152
     BYVAL Val AS VARIANT _                             ' __in VARIANT Val
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChunk <1610809375> ( _                     ' VTable offset = 156
     BYVAL Offset AS LONG _                             ' __in long Offset
   , BYVAL Bytes AS LONG _                              ' __in long Bytes
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD v30_FieldSize_ <1610809376> ( _               ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   METHOD CreateProperty <1610809377> ( _               ' VTable offset = 164
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================
   PROPERTY GET CollectionIndex <1610809378> ( _        ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out short* i
   ' =====================================================================================
   PROPERTY GET OriginalValue <1610809379> ( _          ' VTable offset = 172
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET VisibleValue <1610809380> ( _           ' VTable offset = 176
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET FieldSize <1610809381> ( _              ' VTable offset = 180
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOField_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Fields
' IID = {00000053-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOFields_INTERFACE_DEFINED)
    %DAOFields_INTERFACE_DEFINED = 1

INTERFACE DAOFields $IID_DAOFields

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Fields Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOField                                        ' __retval_out Field** ppfld
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOFields_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _Index
' IID = {00000059-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOIndex_INTERFACE_DEFINED)
    %DAOIndex_INTERFACE_DEFINED = 1

INTERFACE DAOIndex $IID_DAOIndex

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Index Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809344> ( _                   ' VTable offset = 36
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Foreign <1610809346> ( _                ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY GET Unique <1610809347> ( _                 ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Unique <1610809347> ( _                 ' VTable offset = 48
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Clustered <1610809349> ( _              ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Clustered <1610809349> ( _              ' VTable offset = 56
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Required <1610809351> ( _               ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Required <1610809351> ( _               ' VTable offset = 64
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IgnoreNulls <1610809353> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET IgnoreNulls <1610809353> ( _            ' VTable offset = 72
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Primary <1610809355> ( _                ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Primary <1610809355> ( _                ' VTable offset = 80
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DistinctCount <1610809357> ( _          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY GET Fields <1610809358> ( _                 ' VTable offset = 88
   ) AS VARIANT                                         ' __retval_out VARIANT* pv
   ' =====================================================================================
   PROPERTY SET Fields <1610809358> ( _                 ' VTable offset = 92
     BYVAL pv AS VARIANT _                              ' __in VARIANT pv
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateField <1610809360> ( _                  ' VTable offset = 96
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Size AS VARIANT _                   ' __in_opt VARIANT Size
   ) AS DAOField                                        ' __retval_out Field** ppfld
   ' =====================================================================================
   METHOD CreateProperty <1610809361> ( _               ' VTable offset = 100
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOIndex_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Indexes
' IID = {0000005B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOIndexes_INTERFACE_DEFINED)
    %DAOIndexes_INTERFACE_DEFINED = 1

INTERFACE DAOIndexes $IID_DAOIndexes

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Indexes Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOIndex                                        ' __retval_out Index** ppidx
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOIndexes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Parameter
' IID = {00000081-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOParameter_INTERFACE_DEFINED)
    %DAOParameter_INTERFACE_DEFINED = 1

INTERFACE DAOParameter $IID_DAOParameter

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Parameter Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 40
     BYVAL pvar AS VARIANT _                            ' __in VARIANT pvar
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <1610809347> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* ps
   ' =====================================================================================
   PROPERTY SET Type <1610809347> ( _                   ' VTable offset = 48
     BYVAL ps AS INTEGER _                              ' __in short ps
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Direction <1610809349> ( _              ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* pOption
   ' =====================================================================================
   PROPERTY SET Direction <1610809349> ( _              ' VTable offset = 56
     BYVAL pOption AS INTEGER _                         ' __in short pOption
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOParameter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Parameters
' IID = {00000083-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAOParameters_INTERFACE_DEFINED)
    %DAOParameters_INTERFACE_DEFINED = 1

INTERFACE DAOParameters $IID_DAOParameters

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Parameters Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOParameter                                    ' __retval_out Parameter** ppprm
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOParameters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _User
' IID = {00000069-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOUser_INTERFACE_DEFINED)
    %DAOUser_INTERFACE_DEFINED = 1

INTERFACE DAOUser $IID_DAOUser

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' User Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809344> ( _                   ' VTable offset = 36
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PID <1610809346> ( _                    ' VTable offset = 40
     BYVAL rhs AS WSTRING _                             ' in] BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Password <1610809347> ( _               ' VTable offset = 44
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Groups <0> ( _                          ' VTable offset = 48
   ) AS DAOGroups                                       ' __retval_out Groups** ppgrps
   ' =====================================================================================
   METHOD NewPassword <1610809349> ( _                  ' VTable offset = 52
     BYVAL bstrOld AS WSTRING _                         ' __in BSTR bstrOld
   , BYVAL bstrNew AS WSTRING _                         ' __in BSTR bstrNew
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateGroup <1610809350> ( _                  ' VTable offset = 56
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL PID AS VARIANT _                    ' __in_opt VARIANT PID
   ) AS DAOGroup                                        ' __retval_out Group** ppgrp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOUser_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Users
' IID = {0000006B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOUsers_INTERFACE_DEFINED)
    %DAOUsers_INTERFACE_DEFINED = 1

INTERFACE DAOUsers $IID_DAOUsers

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Users Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOUser                                         ' __retval_out User** ppusr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOUsers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _Group
' IID = {00000061-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOGroup_INTERFACE_DEFINED)
    %DAOGroup_INTERFACE_DEFINED = 1

INTERFACE DAOGroup $IID_DAOGroup

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Group Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809344> ( _                   ' VTable offset = 36
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET PID <1610809346> ( _                    ' VTable offset = 40
     BYVAL rhs AS WSTRING _                             ' __in BSTR rhs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Users <0> ( _                           ' VTable offset = 44
   ) AS DAOUsers                                        ' __retval_out Users** ppusrs
   ' =====================================================================================
   METHOD CreateUser <1610809348> ( _                   ' VTable offset = 48
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL PID AS VARIANT _                    ' __in_opt VARIANT PID
   , OPTIONAL BYVAL Password AS VARIANT _               ' __in_opt VARIANT Password
   ) AS DAOUser                                         ' __retval_out User** ppusr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Groups
' IID = {00000063-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOGroups_INTERFACE_DEFINED)
    %DAOGroups_INTERFACE_DEFINED = 1

INTERFACE DAOGroups $IID_DAOGroups

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Groups Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOGroup                                        ' __retval_out Group** ppgrp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOGroups_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _Relation
' IID = {00000089-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAORelation_INTERFACE_DEFINED)
    %DAORelation_INTERFACE_DEFINED = 1

INTERFACE DAORelation $IID_DAORelation

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Relation Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Name <1610809344> ( _                   ' VTable offset = 36
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Table <1610809346> ( _                  ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Table <1610809346> ( _                  ' VTable offset = 44
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeignTable <1610809348> ( _           ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET ForeignTable <1610809348> ( _           ' VTable offset = 52
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <1610809350> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Attributes <1610809350> ( _             ' VTable offset = 60
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 64
   ) AS DAOFields                                       ' __retval_out Fields** ppflds
   ' =====================================================================================
   METHOD CreateField <1610809353> ( _                  ' VTable offset = 68
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Size AS VARIANT _                   ' __in_opt VARIANT Size
   ) AS DAOField                                        ' __retval_out Field** ppfld
   ' =====================================================================================
   PROPERTY GET PartialReplica <1610809354> ( _         ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfPartialReplica
   ' =====================================================================================
   PROPERTY SET PartialReplica <1610809354> ( _         ' VTable offset = 76
     BYVAL pfPartialReplica AS INTEGER _                ' __in VARIANT_BOOL pfPartialReplica
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAORelation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Relations
' IID = {0000008B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAORelations_INTERFACE_DEFINED)
    %DAORelations_INTERFACE_DEFINED = 1

INTERFACE DAORelations $IID_DAORelations

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Relations Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAORelation                                     ' __retval_out Relation** pprel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAORelations_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Container
' IID = {00000091-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAOContainer_INTERFACE_DEFINED)
    %DAOContainer_INTERFACE_DEFINED = 1

INTERFACE DAOContainer $IID_DAOContainer

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Container Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Owner <1610809345> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Owner <1610809345> ( _                  ' VTable offset = 40
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserName <1610809347> ( _               ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET UserName <1610809347> ( _               ' VTable offset = 48
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Permissions <1610809349> ( _            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Permissions <1610809349> ( _            ' VTable offset = 56
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Inherit <1610809351> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================
   PROPERTY SET Inherit <1610809351> ( _                ' VTable offset = 64
     BYVAL pb AS INTEGER _                              ' __in VARIANT_BOOL pb
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Documents <0> ( _                       ' VTable offset = 68
   ) AS DAODocuments                                    ' __retval_out Documents** ppdocs
   ' =====================================================================================
   PROPERTY GET AllPermissions <1610809354> ( _         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOContainer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Containers
' IID = {00000093-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAOContainers_INTERFACE_DEFINED)
    %DAOContainers_INTERFACE_DEFINED = 1

INTERFACE DAOContainers $IID_DAOContainers

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Containers Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAOContainer                                    ' __retval_out Container** ppctn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOContainers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Document
' IID = {00000099-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DAO
' ########################################################################################

#IF NOT %DEF(%DAODocument_INTERFACE_DEFINED)
    %DAODocument_INTERFACE_DEFINED = 1

INTERFACE DAODocument $IID_DAODocument

   INHERIT IDispatch

   ' =====================================================================================
   ' _DAO Methods
   ' =====================================================================================
   PROPERTY GET Properties <10> ( _                     ' VTable offset = 28
   ) AS DAOProperties                                   ' __retval_out Properties** ppprops
   ' =====================================================================================

   ' =====================================================================================
   ' Document Methods
   ' =====================================================================================
   PROPERTY GET Name <1610809344> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET Owner <1610809345> ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET Owner <1610809345> ( _                  ' VTable offset = 40
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Container <1610809347> ( _              ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY GET UserName <1610809348> ( _               ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstr
   ' =====================================================================================
   PROPERTY SET UserName <1610809348> ( _               ' VTable offset = 52
     BYVAL pbstr AS WSTRING _                           ' __in BSTR pbstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Permissions <1610809350> ( _            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   PROPERTY SET Permissions <1610809350> ( _            ' VTable offset = 60
     BYVAL pl AS LONG _                                 ' __in long pl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DateCreated <1610809352> ( _            ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET LastUpdated <1610809353> ( _            ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   PROPERTY GET AllPermissions <1610809354> ( _         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long* pl
   ' =====================================================================================
   METHOD CreateProperty <1610809355> ( _               ' VTable offset = 76
     OPTIONAL BYVAL Name AS VARIANT _                   ' __in_opt VARIANT Name
   , OPTIONAL BYVAL Type AS VARIANT _                   ' __in_opt VARIANT Type
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __in_opt VARIANT Value
   , OPTIONAL BYVAL DDL AS VARIANT _                    ' __in_opt VARIANT DDL
   ) AS DAOProperty                                     ' __retval_out Property** pprp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Documents
' IID = {0000009B-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%DAODocuments_INTERFACE_DEFINED)
    %DAODocuments_INTERFACE_DEFINED = 1

INTERFACE DAODocuments $IID_DAODocuments

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Documents Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS DAODocument                                     ' __retval_out Document** ppdoc
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAODocuments_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IndexFields
' IID = {0000005D-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%DAOIndexFields_INTERFACE_DEFINED)
    %DAOIndexFields_INTERFACE_DEFINED = 1

INTERFACE DAOIndexFields $IID_DAOIndexFields

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown** ppunk
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IndexFields Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     OPTIONAL BYVAL Item AS VARIANT _                   ' __in_opt VARIANT Item
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DAOIndexFields_INTERFACE_DEFINED__ */
