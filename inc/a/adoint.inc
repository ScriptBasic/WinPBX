' ########################################################################################
' Microsoft Windows
' File: adoint.inc
' Library name: ADODB
' Contents: Microsoft ActiveX Data Objects 2.8 Library
' Version: 2.8, Locale ID = 0
' Library GUID: {2A75196C-D9EB-4129-B803-931327F72D5C}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADOINT_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {00000507-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOCommand28 = "ADODB.Command.2.8"
' CLSID = {00000514-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOConnection28 = "ADODB.Connection.2.8"
' CLSID = {0000050B-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOParameter28 = "ADODB.Parameter.2.8"
' CLSID = {00000560-0000-0010-8000-00AA006D2EA4}
$PROGID_ADORecord28 = "ADODB.Record.2.8"
' CLSID = {00000535-0000-0010-8000-00AA006D2EA4}
$PROGID_ADORecordset28 = "ADODB.Recordset.2.8"
' CLSID = {00000566-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOStream28 = "ADODB.Stream.2.8"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {00000507-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOCommand = "ADODB.Command"
' CLSID = {00000514-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOConnection = "ADODB.Connection"
' CLSID = {0000050B-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOParameter = "ADODB.Parameter"
' CLSID = {00000560-0000-0010-8000-00AA006D2EA4}
$PROGID_ADORecord = "ADODB.Record"
' CLSID = {00000535-0000-0010-8000-00AA006D2EA4}
$PROGID_ADORecordset = "ADODB.Recordset"
' CLSID = {00000566-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOStream = "ADODB.Stream"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ADOCommand                = GUID$("{00000507-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOConnection             = GUID$("{00000514-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOParameter              = GUID$("{0000050B-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADORecord                 = GUID$("{00000560-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADORecordset              = GUID$("{00000535-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOStream                 = GUID$("{00000566-0000-0010-8000-00AA006D2EA4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ADOCommandConstruction      = GUID$("{00000517-0000-0010-8000-00AA006D2EA4}")
$IID_ADOConnectionConstruction   = GUID$("{00000551-0000-0010-8000-00AA006D2EA4}")
$IID_ADOConnectionConstruction15 = GUID$("{00000516-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordConstruction       = GUID$("{00000567-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordsetConstruction    = GUID$("{00000283-0000-0010-8000-00AA006D2EA4}")
$IID_ADOStreamConstruction       = GUID$("{00000568-0000-0010-8000-00AA006D2EA4}")
$IID_ADOCommand15                = GUID$("{00000508-0000-0010-8000-00AA006D2EA4}")
$IID_ADOCommand25                = GUID$("{0000054E-0000-0010-8000-00AA006D2EA4}")
$IID_ADOConnection15             = GUID$("{00000515-0000-0010-8000-00AA006D2EA4}")
$IID_ADOConnectionEvents         = GUID$("{00000400-0000-0010-8000-00AA006D2EA4}")
$IID_ADOConnectionEventsVt       = GUID$("{00000402-0000-0010-8000-00AA006D2EA4}")
$IID_ADOError                    = GUID$("{00000500-0000-0010-8000-00AA006D2EA4}")
$IID_ADOErrors                   = GUID$("{00000501-0000-0010-8000-00AA006D2EA4}")
$IID_ADOField                    = GUID$("{00000569-0000-0010-8000-00AA006D2EA4}")
$IID_ADOField15                  = GUID$("{00000505-0000-0010-8000-00AA006D2EA4}")
$IID_ADOField20                  = GUID$("{0000054C-0000-0010-8000-00AA006D2EA4}")
$IID_ADOFields                   = GUID$("{00000564-0000-0010-8000-00AA006D2EA4}")
$IID_ADOFields15                 = GUID$("{00000506-0000-0010-8000-00AA006D2EA4}")
$IID_ADOFields20                 = GUID$("{0000054D-0000-0010-8000-00AA006D2EA4}")
$IID_ADOParameters               = GUID$("{0000050D-0000-0010-8000-00AA006D2EA4}")
$IID_ADOProperties               = GUID$("{00000504-0000-0010-8000-00AA006D2EA4}")
$IID_ADOProperty                 = GUID$("{00000503-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordset15              = GUID$("{0000050E-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordset20              = GUID$("{0000054F-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordset21              = GUID$("{00000555-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordsetEvents          = GUID$("{00000266-0000-0010-8000-00AA006D2EA4}")
$IID_ADORecordsetEventsVt        = GUID$("{00000403-0000-0010-8000-00AA006D2EA4}")
$IID__ADO                        = GUID$("{00000534-0000-0010-8000-00AA006D2EA4}")
$IID__ADOCollection              = GUID$("{00000512-0000-0010-8000-00AA006D2EA4}")
$IID__ADOCommand                 = GUID$("{B08400BD-F9D1-4D02-B856-71D5DBA123E9}")
$IID__ADOConnection              = GUID$("{00000550-0000-0010-8000-00AA006D2EA4}")
$IID__ADODynaCollection          = GUID$("{00000513-0000-0010-8000-00AA006D2EA4}")
$IID__ADOParameter               = GUID$("{0000050C-0000-0010-8000-00AA006D2EA4}")
$IID__ADORecord                  = GUID$("{00000562-0000-0010-8000-00AA006D2EA4}")
$IID__ADORecordset               = GUID$("{00000556-0000-0010-8000-00AA006D2EA4}")
$IID__ADOStream                  = GUID$("{00000565-0000-0010-8000-00AA006D2EA4}")

' ========================================================================================
' CursorTypeEnum enum
' IID: {0000051B-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adOpenUnspecified                                      = -1
%adOpenForwardOnly                                      = 0
%adOpenKeyset                                           = 1
%adOpenDynamic                                          = 2
%adOpenStatic                                           = 3

' ========================================================================================
' CursorOptionEnum enum
' IID: {0000051C-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adHoldRecords                                          = &H100
%adMovePrevious                                         = &H200
%adAddNew                                               = &H1000400
%adDelete                                               = &H1000800
%adUpdate                                               = &H1008000
%adBookmark                                             = &H2000
%adApproxPosition                                       = &H4000
%adUpdateBatch                                          = &H10000
%adResync                                               = &H20000
%adNotify                                               = &H40000
%adFind                                                 = &H80000
%adSeek                                                 = &H400000
%adIndex                                                = &H800000

' ========================================================================================
' LockTypeEnum enum
' IID: {0000051D-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adLockUnspecified                                      = -1
%adLockReadOnly                                         = 1
%adLockPessimistic                                      = 2
%adLockOptimistic                                       = 3
%adLockBatchOptimistic                                  = 4

' ========================================================================================
' ExecuteOptionEnum enum
' IID: {0000051E-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adOptionUnspecified                                    = -1
%adAsyncExecute                                         = &H10
%adAsyncFetch                                           = &H20
%adAsyncFetchNonBlocking                                = &H40
%adExecuteNoRecords                                     = &H80
%adExecuteStream                                        = &H400
%adExecuteRecord                                        = &H800

' ========================================================================================
' ConnectOptionEnum enum
' IID: {00000541-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adConnectUnspecified                                   = -1
%adAsyncConnect                                         = &H10

' ========================================================================================
' ObjectStateEnum enum
' IID: {00000532-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adStateClosed                                          = 0
%adStateOpen                                            = &H1
%adStateConnecting                                      = &H2
%adStateExecuting                                       = &H4
%adStateFetching                                        = &H8

' ========================================================================================
' CursorLocationEnum enum
' IID: {0000052F-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adUseNone                                              = 1
%adUseServer                                            = 2
%adUseClient                                            = 3
%adUseClientBatch                                       = 3

' ========================================================================================
' DataTypeEnum enum
' IID: {0000051F-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adEmpty                                                = 0
%adTinyInt                                              = 16
%adSmallInt                                             = 2
%adInteger                                              = 3
%adBigInt                                               = 20
%adUnsignedTinyInt                                      = 17
%adUnsignedSmallInt                                     = 18
%adUnsignedInt                                          = 19
%adUnsignedBigInt                                       = 21
%adSingle                                               = 4
%adDouble                                               = 5
%adCurrency                                             = 6
%adDecimal                                              = 14
%adNumeric                                              = 131
%adBoolean                                              = 11
%adError                                                = 10
%adUserDefined                                          = 132
%adVariant                                              = 12
%adIDispatch                                            = 9
%adIUnknown                                             = 13
%adGUID                                                 = 72
%adDate                                                 = 7
%adDBDate                                               = 133
%adDBTime                                               = 134
%adDBTimeStamp                                          = 135
%adBSTR                                                 = 8
%adChar                                                 = 129
%adVarChar                                              = 200
%adLongVarChar                                          = 201
%adWChar                                                = 130
%adVarWChar                                             = 202
%adLongVarWChar                                         = 203
%adBinary                                               = 128
%adVarBinary                                            = 204
%adLongVarBinary                                        = 205
%adChapter                                              = 136
%adFileTime                                             = 64
%adPropVariant                                          = 138
%adVarNumeric                                           = 139
%adArray                                                = &H2000

' ========================================================================================
' FieldAttributeEnum enum
' IID: {00000525-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adFldUnspecified                                       = -1
%adFldMayDefer                                          = &H2
%adFldUpdatable                                         = &H4
%adFldUnknownUpdatable                                  = &H8
%adFldFixed                                             = &H10
%adFldIsNullable                                        = &H20
%adFldMayBeNull                                         = &H40
%adFldLong                                              = &H80
%adFldRowID                                             = &H100
%adFldRowVersion                                        = &H200
%adFldCacheDeferred                                     = &H1000
%adFldIsChapter                                         = &H2000
%adFldNegativeScale                                     = &H4000
%adFldKeyColumn                                         = &H8000
%adFldIsRowURL                                          = &H10000
%adFldIsDefaultStream                                   = &H20000
%adFldIsCollection                                      = &H40000

' ========================================================================================
' EditModeEnum enum
' IID: {00000526-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adEditNone                                             = 0
%adEditInProgress                                       = &H1
%adEditAdd                                              = &H2
%adEditDelete                                           = &H4

' ========================================================================================
' RecordStatusEnum enum
' IID: {00000527-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adRecOK                                                = 0
%adRecNew                                               = &H1
%adRecModified                                          = &H2
%adRecDeleted                                           = &H4
%adRecUnmodified                                        = &H8
%adRecInvalid                                           = &H10
%adRecMultipleChanges                                   = &H40
%adRecPendingChanges                                    = &H80
%adRecCanceled                                          = &H100
%adRecCantRelease                                       = &H400
%adRecConcurrencyViolation                              = &H800
%adRecIntegrityViolation                                = &H1000
%adRecMaxChangesExceeded                                = &H2000
%adRecObjectOpen                                        = &H4000
%adRecOutOfMemory                                       = &H8000
%adRecPermissionDenied                                  = &H10000
%adRecSchemaViolation                                   = &H20000
%adRecDBDeleted                                         = &H40000

' ========================================================================================
' GetRowsOptionEnum enum
' IID: {00000542-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adGetRowsRest                                          = -1

' ========================================================================================
' PositionEnum enum
' IID: {00000528-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adPosUnknown                                           = -1
%adPosBOF                                               = -2
%adPosEOF                                               = -3

' ========================================================================================
' BookmarkEnum enum
' ========================================================================================

%adBookmarkCurrent                                      = 0
%adBookmarkFirst                                        = 1
%adBookmarkLast                                         = 2

' ========================================================================================
' MarshalOptionsEnum enum
' IID: {00000540-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adMarshalAll                                           = 0
%adMarshalModifiedOnly                                  = 1

' ========================================================================================
' AffectEnum enum
' IID: {00000543-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adAffectCurrent                                        = 1
%adAffectGroup                                          = 2
%adAffectAll                                            = 3
%adAffectAllChapters                                    = 4

' ========================================================================================
' ResyncEnum enum
' IID: {00000544-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adResyncUnderlyingValues                               = 1
%adResyncAllValues                                      = 2

' ========================================================================================
' CompareEnum enum
' IID: {00000545-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adCompareLessThan                                      = 0
%adCompareEqual                                         = 1
%adCompareGreaterThan                                   = 2
%adCompareNotEqual                                      = 3
%adCompareNotComparable                                 = 4

' ========================================================================================
' FilterGroupEnum enum
' IID: {00000546-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adFilterNone                                           = 0
%adFilterPendingRecords                                 = 1
%adFilterAffectedRecords                                = 2
%adFilterFetchedRecords                                 = 3
%adFilterPredicate                                      = 4
%adFilterConflictingRecords                             = 5

' ========================================================================================
' SearchDirection enum
' IID: {00000547-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adSearchForward                                        = 1
%adSearchBackward                                       = -1

' ========================================================================================
' PersistFormatEnum enum
' IID: {00000548-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adPersistADTG                                          = 0
%adPersistXML                                           = 1

' ========================================================================================
' StringFormatEnum enum
' IID: {00000549-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adClipString                                           = 2

' ========================================================================================
' ConnectPromptEnum enum
' IID: {00000520-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adPromptAlways                                         = 1
%adPromptComplete                                       = 2
%adPromptCompleteRequired                               = 3
%adPromptNever                                          = 4

' ========================================================================================
' ConnectModeEnum enum
' IID: {00000521-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adModeUnknown                                          = 0
%adModeRead                                             = 1
%adModeWrite                                            = 2
%adModeReadWrite                                        = 3
%adModeShareDenyRead                                    = 4
%adModeShareDenyWrite                                   = 8
%adModeShareExclusive                                   = &HC
%adModeShareDenyNone                                    = &H10
%adModeRecursive                                        = &H400000

' ========================================================================================
' RecordCreateOptionsEnum enum
' IID: {00000570-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adCreateCollection                                     = &H2000
%adCreateStructDoc                                      = &H80000000
%adCreateNonCollection                                  = 0
%adOpenIfExists                                         = &H2000000
%adCreateOverwrite                                      = &H4000000
%adFailIfNotExists                                      = -1

' ========================================================================================
' RecordOpenOptionsEnum enum
' IID: {00000571-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adOpenRecordUnspecified                                = -1
%adOpenSource                                           = &H800000
%adOpenOutput                                           = &H800000
%adOpenAsync                                            = &H1000
%adDelayFetchStream                                     = &H4000
%adDelayFetchFields                                     = &H8000
%adOpenExecuteCommand                                   = &H10000

' ========================================================================================
' IsolationLevelEnum enum
' IID: {00000523-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adXactUnspecified                                      = &HFFFFFFFF
%adXactChaos                                            = &H10
%adXactReadUncommitted                                  = &H100
%adXactBrowse                                           = &H100
%adXactCursorStability                                  = &H1000
%adXactReadCommitted                                    = &H1000
%adXactRepeatableRead                                   = &H10000
%adXactSerializable                                     = &H100000
%adXactIsolated                                         = &H100000

' ========================================================================================
' XactAttributeEnum enum
' IID: {00000524-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adXactCommitRetaining                                  = &H20000
%adXactAbortRetaining                                   = &H40000
%adXactAsyncPhaseOne                                    = &H80000
%adXactSyncPhaseOne                                     = &H100000

' ========================================================================================
' PropertyAttributesEnum enum
' IID: {00000529-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adPropNotSupported                                     = 0
%adPropRequired                                         = &H1
%adPropOptional                                         = &H2
%adPropRead                                             = &H200
%adPropWrite                                            = &H400

' ========================================================================================
' ErrorValueEnum enum
' IID: {0000052A-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adErrProviderFailed          = &HBB8   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbb8)
%adErrInvalidArgument         = &HBB9   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbb9)
%adErrOpeningFile             = &HBBA   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbba)
%adErrReadFile                = &HBBB   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbbb)
%adErrWriteFile               = &HBBC   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbbc)
%adErrNoCurrentRecord         = &HBCD   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xbcd)
%adErrIllegalOperation        = &HC93   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xc93)
%adErrCantChangeProvider      = &HC94   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xc94)
%adErrInTransaction           = &HCAE   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xcae)
%adErrFeatureNotAvailable     = &HCB3   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xcb3)
%adErrItemNotFound            = &HCC1   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xcc1)
%adErrObjectInCollection      = &HD27   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xd27)
%adErrObjectNotSet            = &HD5C   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xd5c)
%adErrDataConversion          = &HD5D   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xd5d)
%adErrObjectClosed            = &HE78   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe78)
%adErrObjectOpen              = &HE79   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe79)
%adErrProviderNotFound        = &HE7A   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7a)
%adErrBoundToCommand          = &HE7B   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7b)
%adErrInvalidParamInfo        = &HE7C   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7c)
%adErrInvalidConnection       = &HE7D   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7d)
%adErrNotReentrant            = &HE7E   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7e)
%adErrStillExecuting          = &HE7F   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe7f)
%adErrOperationCancelled      = &HE80   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe80)
%adErrStillConnecting         = &HE81   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe81)
%adErrInvalidTransaction      = &HE82   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe82)
%adErrNotExecuting            = &HE83   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe83)
%adErrUnsafeOperation         = &HE84   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe84)
%adwrnSecurityDialog          = &HE85   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe85)
%adwrnSecurityDialogHeader    = &HE86   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe86)
%adErrIntegrityViolation      = &HE87   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe87)
%adErrPermissionDenied        = &HE88   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe88)
%adErrDataOverflow            = &HE89   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe89)
%adErrSchemaViolation         = &HE8A   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8a)
%adErrSignMismatch            = &HE8B   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8b)
%adErrCantConvertvalue        = &HE8C   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8c)
%adErrCantCreate              = &HE8D   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8d)
%adErrColumnNotOnThisRow      = &HE8E   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8e)
%adErrURLDoesNotExist         = &HE8F   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe8f)
%adErrTreePermissionDenied    = &HE90   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe90)
%adErrInvalidURL              = &HE91   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe91)
%adErrResourceLocked          = &HE92   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe92)
%adErrResourceExists          = &HE93   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe93)
%adErrCannotComplete          = &HE94   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe94)
%adErrVolumeNotFound          = &HE95   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe95)
%adErrOutOfSpace              = &HE96   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe96)
%adErrResourceOutOfScope      = &HE97   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe97)
%adErrUnavailable             = &HE98   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe98)
%adErrURLNamedRowDoesNotExist = &HE99   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe99)
%adErrDelResOutOfScope        = &HE9A   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9a)
%adErrPropInvalidColumn       = &HE9B   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9b)
%adErrPropInvalidOption       = &HE9C   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9c)
%adErrPropInvalidValue        = &HE9D   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9d)
%adErrPropConflicting         = &HE9E   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9e)
%adErrPropNotAllSettable      = &HE9F   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xe9f)
%adErrPropNotSet              = &HEA0   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea0)
%adErrPropNotSettable         = &HEA1   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea1)
%adErrPropNotSupported        = &HEA2   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea2)
%adErrCatalogNotSet           = &HEA3   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea3)
%adErrCantChangeConnection    = &HEA4   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea4)
%adErrFieldsUpdateFailed      = &HEA5   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea5)
%adErrDenyNotSupported        = &HEA6   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea6)
%adErrDenyTypeNotSupported    = &HEA7   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea7)
%adErrProviderNotSpecified    = &HEA9   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xea9)
%adErrConnectionStringTooLong = &HEAA   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_CONTROL,  0xeaa)

' ========================================================================================
' ParameterAttributesEnum enum
' IID: {0000052B-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adParamSigned                                          = &H10
%adParamNullable                                        = &H40
%adParamLong                                            = &H80

' ========================================================================================
' ParameterDirectionEnum enum
' IID: {0000052C-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adParamUnknown                                         = 0
%adParamInput                                           = &H1
%adParamOutput                                          = &H2
%adParamInputOutput                                     = &H3
%adParamReturnValue                                     = &H4

' ========================================================================================
' CommandTypeEnum enum
' IID: {0000052E-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adCmdUnspecified                                       = -1
%adCmdUnknown                                           = &H8
%adCmdText                                              = &H1
%adCmdTable                                             = &H2
%adCmdStoredProc                                        = &H4
%adCmdFile                                              = &H100
%adCmdTableDirect                                       = &H200

' ========================================================================================
' EventStatusEnum enum
' IID: {00000530-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adStatusOK                                             = &H1
%adStatusErrorsOccurred                                 = &H2
%adStatusCantDeny                                       = &H3
%adStatusCancel                                         = &H4
%adStatusUnwantedEvent                                  = &H5

' ========================================================================================
' EventReasonEnum enum
' IID: {00000531-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adRsnAddNew                                            = 1
%adRsnDelete                                            = 2
%adRsnUpdate                                            = 3
%adRsnUndoUpdate                                        = 4
%adRsnUndoAddNew                                        = 5
%adRsnUndoDelete                                        = 6
%adRsnRequery                                           = 7
%adRsnResynch                                           = 8
%adRsnClose                                             = 9
%adRsnMove                                              = 10
%adRsnFirstChange                                       = 11
%adRsnMoveFirst                                         = 12
%adRsnMoveNext                                          = 13
%adRsnMovePrevious                                      = 14
%adRsnMoveLast                                          = 15

' ========================================================================================
' SchemaEnum enum
' IID: {00000533-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adSchemaProviderSpecific                               = -1
%adSchemaAsserts                                        = 0
%adSchemaCatalogs                                       = 1
%adSchemaCharacterSets                                  = 2
%adSchemaCollations                                     = 3
%adSchemaColumns                                        = 4
%adSchemaCheckConstraints                               = 5
%adSchemaConstraintColumnUsage                          = 6
%adSchemaConstraintTableUsage                           = 7
%adSchemaKeyColumnUsage                                 = 8
%adSchemaReferentialContraints                          = 9
%adSchemaTableConstraints                               = 10
%adSchemaColumnsDomainUsage                             = 11
%adSchemaIndexes                                        = 12
%adSchemaColumnPrivileges                               = 13
%adSchemaTablePrivileges                                = 14
%adSchemaUsagePrivileges                                = 15
%adSchemaProcedures                                     = 16
%adSchemaSchemata                                       = 17
%adSchemaSQLLanguages                                   = 18
%adSchemaStatistics                                     = 19
%adSchemaTables                                         = 20
%adSchemaTranslations                                   = 21
%adSchemaProviderTypes                                  = 22
%adSchemaViews                                          = 23
%adSchemaViewColumnUsage                                = 24
%adSchemaViewTableUsage                                 = 25
%adSchemaProcedureParameters                            = 26
%adSchemaForeignKeys                                    = 27
%adSchemaPrimaryKeys                                    = 28
%adSchemaProcedureColumns                               = 29
%adSchemaDBInfoKeywords                                 = 30
%adSchemaDBInfoLiterals                                 = 31
%adSchemaCubes                                          = 32
%adSchemaDimensions                                     = 33
%adSchemaHierarchies                                    = 34
%adSchemaLevels                                         = 35
%adSchemaMeasures                                       = 36
%adSchemaProperties                                     = 37
%adSchemaMembers                                        = 38
%adSchemaTrustees                                       = 39
%adSchemaFunctions                                      = 40
%adSchemaActions                                        = 41
%adSchemaCommands                                       = 42
%adSchemaSets                                           = 43

' ========================================================================================
' FieldStatusEnum enum
' IID: {0000057E-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adFieldOK                                              = 0
%adFieldCantConvertValue                                = 2
%adFieldIsNull                                          = 3
%adFieldTruncated                                       = 4
%adFieldSignMismatch                                    = 5
%adFieldDataOverflow                                    = 6
%adFieldCantCreate                                      = 7
%adFieldUnavailable                                     = 8
%adFieldPermissionDenied                                = 9
%adFieldIntegrityViolation                              = 10
%adFieldSchemaViolation                                 = 11
%adFieldBadStatus                                       = 12
%adFieldDefault                                         = 13
%adFieldIgnore                                          = 15
%adFieldDoesNotExist                                    = 16
%adFieldInvalidURL                                      = 17
%adFieldResourceLocked                                  = 18
%adFieldResourceExists                                  = 19
%adFieldCannotComplete                                  = 20
%adFieldVolumeNotFound                                  = 21
%adFieldOutOfSpace                                      = 22
%adFieldCannotDeleteSource                              = 23
%adFieldReadOnly                                        = 24
%adFieldResourceOutOfScope                              = 25
%adFieldAlreadyExists                                   = 26
%adFieldPendingInsert                                   = &H10000
%adFieldPendingDelete                                   = &H20000
%adFieldPendingChange                                   = &H40000
%adFieldPendingUnknown                                  = &H80000
%adFieldPendingUnknownDelete                            = &H100000

' ========================================================================================
' SeekEnum enum
' IID: {00000552-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adSeekFirstEQ                                          = &H1
%adSeekLastEQ                                           = &H2
%adSeekAfterEQ                                          = &H4
%adSeekAfter                                            = &H8
%adSeekBeforeEQ                                         = &H10
%adSeekBefore                                           = &H20


#IF NOT %DEF(%COMMON_ADC_AND_ADO_PROPS)
    %COMMON_ADC_AND_ADO_PROPS = 1

' ========================================================================================
' ADCPROP_UPDATECRITERIA_ENUM enum
' IID: {0000054A-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adCriteriaKey                                          = 0
%adCriteriaAllCols                                      = 1
%adCriteriaUpdCols                                      = 2
%adCriteriaTimeStamp                                    = 3

' ========================================================================================
' ADCPROP_ASYNCTHREADPRIORITY_ENUM enum
' IID: {0000054B-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adPriorityLowest                                       = 1
%adPriorityBelowNormal                                  = 2
%adPriorityNormal                                       = 3
%adPriorityAboveNormal                                  = 4
%adPriorityHighest                                      = 5

' ========================================================================================
' ADCPROP_AUTORECALC_ENUM enum
' IID: {00000554-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adRecalcUpFront                                        = 0
%adRecalcAlways                                         = 1

' ========================================================================================
' ADCPROP_UPDATERESYNC_ENUM enum
' IID: {00000553-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adResyncNone                                           = 0
%adResyncAutoIncrement                                  = 1
%adResyncConflicts                                      = 2
%adResyncUpdates                                        = 4
%adResyncInserts                                        = 8
%adResyncAll                                            = 15

#ENDIF   ' /* _COMMON_ADC_AND_ADO_PROPS_ */

' ========================================================================================
' MoveRecordOptionsEnum enum
' IID: {00000573-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adMoveUnspecified                                      = -1
%adMoveOverWrite                                        = 1
%adMoveDontUpdateLinks                                  = 2
%adMoveAllowEmulation                                   = 4

' ========================================================================================
' CopyRecordOptionsEnum enum
' IID: {00000574-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adCopyUnspecified                                      = -1
%adCopyOverWrite                                        = 1
%adCopyAllowEmulation                                   = 4
%adCopyNonRecursive                                     = 2

' ========================================================================================
' StreamTypeEnum enum
' IID: {00000576-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adTypeBinary                                           = 1
%adTypeText                                             = 2

' ========================================================================================
' LineSeparatorEnum enum
' IID: {00000577-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adLF                                                   = 10
%adCR                                                   = 13
%adCRLF                                                 = -1

' ========================================================================================
' StreamOpenOptionsEnum enum
' IID: {0000057A-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adOpenStreamUnspecified                                = -1
%adOpenStreamAsync                                      = 1
%adOpenStreamFromRecord                                 = 4

' ========================================================================================
' StreamWriteEnum enum
' IID: {0000057B-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adWriteChar                                            = 0
%adWriteLine                                            = 1
%stWriteChar                                            = 0
%stWriteLine                                            = 1

' ========================================================================================
' SaveOptionsEnum enum
' IID: {0000057C-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adSaveCreateNotExist                                   = 1
%adSaveCreateOverWrite                                  = 2

' ========================================================================================
' FieldEnum enum
' ========================================================================================

%adDefaultStream                                        = -1
%adRecordURL                                            = -2

' ========================================================================================
' StreamReadEnum enum
' ========================================================================================

%adReadAll                                              = -1
%adReadLine                                             = -2

' ========================================================================================
' RecordTypeEnum enum
' IID: {0000057D-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adSimpleRecord                                         = 0
%adCollectionRecord                                     = 1
%adStructDoc                                            = 2

' ########################################################################################
' Interface name = _Collection
' IID = {00000512-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOCollection_INTERFACE_DEFINED)
    %ADOCollection_INTERFACE_DEFINED = 1

INTERFACE ADOCollection $IID__ADOCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___ADOCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _DynaCollection
' IID = {00000513-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADODynaCollection_INTERFACE_DEFINED)
    %ADODynaCollection_INTERFACE_DEFINED = 1

INTERFACE ADODynaCollection $IID__ADODynaCollection

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch *Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___ADODynaCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _ADO
' IID = {00000534-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADO_INTERFACE_DEFINED)
    %ADO_INTERFACE_DEFINED = 1

INTERFACE ADO $IID__ADO

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___ADO_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Error
' IID = {00000500-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOError_INTERFACE_DEFINED)
    %ADOError_INTERFACE_DEFINED = 1

INTERFACE ADOError $IID_ADOError

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Number <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET Source <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <0> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET HelpFile <3> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET HelpContext <4> ( _                     ' VTable offset = 44
   ) AS LONG                                            '  __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET SQLState <5> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET NativeError <6> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Error_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Errors
' IID = {00000501-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOErrors_INTERFACE_DEFINED)
    %ADOErrors_INTERFACE_DEFINED = 1

INTERFACE ADOErrors $IID_ADOErrors

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Errors Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOError                                        ' __retval_out ADOError **ppvObject
   ' =====================================================================================
   METHOD Clear <1610809345> ( _                        ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Errors_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Command15
' IID = {00000508-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADOCommand15_INTERFACE_DEFINED)
    %ADOCommand15_INTERFACE_DEFINED = 1

INTERFACE ADOCommand15 $IID_ADOCommand15

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Command15 Methods
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1> ( _                ' VTable offset = 32
   ) AS ADOConnection                                   ' __retval_out _ADOConnection **ppvObject
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1> ( _         ' VTable offset = 36
     BYVAL pCon AS ADOConnection _                      ' __in _ADOConnection *pCon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1> ( _                ' VTable offset = 40
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandText <2> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET CommandText <2> ( _                     ' VTable offset = 48
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <3> ( _                  ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pl
   ' =====================================================================================
   PROPERTY SET CommandTimeout <3> ( _                  ' VTable offset = 56
     BYVAL Timeout AS LONG _                            ' __in LONG Timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Prepared <4> ( _                        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPrepared
   ' =====================================================================================
   PROPERTY SET Prepared <4> ( _                        ' VTable offset = 64
     BYVAL fPrepared AS INTEGER _                       ' __in VARIANT_BOOL fPrepared
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <5> ( _                               ' VTable offset = 68
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   , OPTIONAL BYREF Parameters AS VARIANT _             ' __opt_in VARIANT *Parameters
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = adCmdUnspecified
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppirs
   ' =====================================================================================
   METHOD CreateParameter <6> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL Name AS WSTRING _                   ' __opt_in BSTR Name = L""
   , OPTIONAL BYVAL Type AS LONG _                      ' __opt_in DataTypeEnum Type = adEmpty
   , OPTIONAL BYVAL Direction AS LONG _                 ' __opt_in ParameterDirectionEnum Direction = adParamInput
   , OPTIONAL BYVAL Size AS LONG _                      ' __opt_in ADO_LONGPTR Size = 0
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __opt_in VARIANT Value
   ) AS ADOParameter                                    ' __retval_out _ADOParameter **ppiprm
   ' =====================================================================================
   PROPERTY GET Parameters <0> ( _                      ' VTable offset = 76
   ) AS ADOParameters                                   ' __retval_out ADOParameters **ppvObject
   ' =====================================================================================
   PROPERTY SET CommandType <7> ( _                     ' VTable offset = 80
     BYVAL lCmdType AS LONG _                           ' __in CommandTypeEnum lCmdType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandType <7> ( _                     ' VTable offset = 84
   ) AS LONG                                            ' __retval_out CommandTypeEnum *plCmdType
   ' =====================================================================================
   PROPERTY GET Name <8> ( _                            ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <8> ( _                            ' VTable offset = 92
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Command15_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Command25
' IID = {0000054E-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Command15
' ########################################################################################

#IF NOT %DEF(%ADOCommand25_INTERFACE_DEFINED)
    %ADOCommand25_INTERFACE_DEFINED = 1

INTERFACE ADOCommand25 $IID_ADOCommand25

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Command15 Methods
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1> ( _                ' VTable offset = 32
   ) AS ADOConnection                                   ' __retval_out _ADOConnection **ppvObject
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1> ( _         ' VTable offset = 36
     BYVAL pCon AS ADOConnection _                      ' __in _ADOConnection *pCon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1> ( _                ' VTable offset = 40
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandText <2> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET CommandText <2> ( _                     ' VTable offset = 48
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <3> ( _                  ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pl
   ' =====================================================================================
   PROPERTY SET CommandTimeout <3> ( _                  ' VTable offset = 56
     BYVAL Timeout AS LONG _                            ' __in LONG Timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Prepared <4> ( _                        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPrepared
   ' =====================================================================================
   PROPERTY SET Prepared <4> ( _                        ' VTable offset = 64
     BYVAL fPrepared AS INTEGER _                       ' __in VARIANT_BOOL fPrepared
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <5> ( _                               ' VTable offset = 68
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   , OPTIONAL BYREF Parameters AS VARIANT _             ' __opt_in VARIANT *Parameters
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = adCmdUnspecified
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppirs
   ' =====================================================================================
   METHOD CreateParameter <6> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL Name AS WSTRING _                   ' __opt_in BSTR Name = L""
   , OPTIONAL BYVAL Type AS LONG _                      ' __opt_in DataTypeEnum Type = adEmpty
   , OPTIONAL BYVAL Direction AS LONG _                 ' __opt_in ParameterDirectionEnum Direction = adParamInput
   , OPTIONAL BYVAL Size AS LONG _                      ' __opt_in ADO_LONGPTR Size = 0
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __opt_in VARIANT Value
   ) AS ADOParameter                                    ' __retval_out _ADOParameter **ppiprm
   ' =====================================================================================
   PROPERTY GET Parameters <0> ( _                      ' VTable offset = 76
   ) AS ADOParameters                                   ' __retval_out ADOParameters **ppvObject
   ' =====================================================================================
   PROPERTY SET CommandType <7> ( _                     ' VTable offset = 80
     BYVAL lCmdType AS LONG _                           ' __in CommandTypeEnum lCmdType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandType <7> ( _                     ' VTable offset = 84
   ) AS LONG                                            ' __retval_out CommandTypeEnum *plCmdType
   ' =====================================================================================
   PROPERTY GET Name <8> ( _                            ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <8> ( _                            ' VTable offset = 92
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Command25 Methods
   ' =====================================================================================
   PROPERTY GET State <9> ( _                           ' VTable offset = 96
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD Cancel <10> ( _                               ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Command25_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _Command
' IID = {B08400BD-F9D1-4D02-B856-71D5DBA123E9}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Command25
' ########################################################################################

#IF NOT %DEF(%ADOCommand_INTERFACE_DEFINED)
    %ADOCommand_INTERFACE_DEFINED = 1

INTERFACE ADOCommand $IID__ADOCommand

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Command15 Methods
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1> ( _                ' VTable offset = 32
   ) AS ADOConnection _                                 ' __retval_out _ADOConnection **ppvObject
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1> ( _         ' VTable offset = 36
     BYVAL pCon AS ADOConnection _                      ' __in _ADOConnection *pCon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1> ( _                ' VTable offset = 40
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandText <2> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET CommandText <2> ( _                     ' VTable offset = 48
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <3> ( _                  ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *pl
   ' =====================================================================================
   PROPERTY SET CommandTimeout <3> ( _                  ' VTable offset = 56
     BYVAL Timeout AS LONG _                            ' __in LONG Timeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Prepared <4> ( _                        ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfPrepared
   ' =====================================================================================
   PROPERTY SET Prepared <4> ( _                        ' VTable offset = 64
     BYVAL fPrepared AS INTEGER _                       ' __in VARIANT_BOOL fPrepared
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <5> ( _                               ' VTable offset = 68
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   , OPTIONAL BYREF Parameters AS VARIANT _             ' __opt_in VARIANT *Parameters
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = adCmdUnspecified
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppirs
   ' =====================================================================================
   METHOD CreateParameter <6> ( _                       ' VTable offset = 72
     OPTIONAL BYVAL Name AS WSTRING _                   ' __opt_in BSTR Name = L""
   , OPTIONAL BYVAL Type AS LONG _                      ' __opt_in DataTypeEnum Type = adEmpty
   , OPTIONAL BYVAL Direction AS LONG _                 ' __opt_in ParameterDirectionEnum Direction = adParamInput
   , OPTIONAL BYVAL Size AS LONG _                      ' __opt_in ADO_LONGPTR Size = 0
   , OPTIONAL BYVAL Value AS VARIANT _                  ' __opt_in VARIANT Value
   ) AS ADOParameter                                    ' __retval_out _ADOParameter **ppiprm
   ' =====================================================================================
   PROPERTY GET Parameters <0> ( _                      ' VTable offset = 76
   ) AS ADOParameters                                   ' __retval_out ADOParameters **ppvObject
   ' =====================================================================================
   PROPERTY SET CommandType <7> ( _                     ' VTable offset = 80
     BYVAL lCmdType AS LONG _                           ' __in CommandTypeEnum lCmdType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandType <7> ( _                     ' VTable offset = 84
   ) AS LONG                                            ' __retval_out CommandTypeEnum *plCmdType
   ' =====================================================================================
   PROPERTY GET Name <8> ( _                            ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <8> ( _                            ' VTable offset = 92
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Command25 Methods
   ' =====================================================================================
   PROPERTY GET State <9> ( _                           ' VTable offset = 96
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD Cancel <10> ( _                               ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Command Methods
   ' =====================================================================================
   PROPERTY SET putref_CommandStream <11> ( _           ' VTable offset = 104
     BYVAL pStream AS IUnknown _                        ' __in IUnknown *pStream
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandStream <11> ( _                  ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvStream
   ' =====================================================================================
   PROPERTY SET Dialect <12> ( _                        ' VTable offset = 112
     BYVAL bstrDialect AS WSTRING _                     ' __in BSTR bstrDialect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Dialect <12> ( _                        ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDialect
   ' =====================================================================================
   PROPERTY SET NamedParameters <13> ( _                ' VTable offset = 120
     BYVAL fNamedParameters As INTEGER _                ' __in VARIANT_BOOL fNamedParameters
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NamedParameters <13> ( _                ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfNamedParameters
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Command_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ConnectionEventsVt
' IID = {00000402-0000-0010-8000-00AA006D2EA4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ADOConnectionEventsVt_INTERFACE_DEFINED)
    %ADOConnectionEventsVt_INTERFACE_DEFINED = 1

INTERFACE ADOConnectionEventsVt $IID_ADOConnectionEventsVt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InfoMessage ( _                               ' VTable offset = 12
     BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginTransComplete ( _                        ' VTable offset = 16
     BYVAL TransactionLevel AS LONG _                   ' __in LONG TransactionLevel
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitTransComplete ( _                       ' VTable offset = 20
     BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RollbackTransComplete ( _                     ' VTable offset = 24
     BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillExecute ( _                               ' VTable offset = 28
     BYREF Source AS WSTRING _                          ' __in_out BSTR *Source
   , BYREF CursorType AS LONG _                         ' __in_out CursorTypeEnum *CursorType
   , BYREF LockType AS LONG _                           ' __in_out LockTypeEnum *LockType
   , BYREF Options AS LONG _                            ' __in_out long *Options
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pCommand AS ADOCommand _                     ' __in _ADOCommand *pCommand
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExecuteComplete ( _                           ' __in VTable offset = 32
     BYVAL RecordsAffected AS LONG _                    ' __in LONG RecordsAffected
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pCommand AS ADOCommand _                     ' __in _ADOCommand *pCommand
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillConnect ( _                               ' VTable offset = 36
     BYREF ConnectionString AS WSTRING _                ' __in_out BSTR *ConnectionString
   , BYREF UserID AS WSTRING _                          ' __in_out BSTR *UserID
   , BYREF Password AS WSTRING _                        ' __in_out BSTR *Password
   , BYREF Options AS LONG _                            ' __in_out long *Options
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectComplete ( _                           ' VTable offset = 40
     BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 44
     BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pConnection AS ADOConnection _               ' __in _ADOConnection *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ConnectionEventsVt_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = RecordsetEventsVt
' IID = {00000403-0000-0010-8000-00AA006D2EA4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ADORecordsetEventsVt_INTERFACE_DEFINED)
    %ADORecordsetEventsVt_INTERFACE_DEFINED = 1

INTERFACE ADORecordsetEventsVt $IID_ADORecordsetEventsVt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD WillChangeField ( _                           ' VTable offset = 12
     BYVAL cFields AS LONG _                            ' __in LONG cFields
   , BYVAL Fields AS VARIANT _                          ' __in VARIANT Fields
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FieldChangeComplete ( _                       ' VTable offset = 16
     BYVAL cFields AS LONG _                            ' __in LONG cFields
   , BYVAL Fields AS VARIANT _                          ' __in VARIANT Fields
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillChangeRecord ( _                          ' VTable offset = 20
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYVAL cRecords AS LONG _                           ' __in LONG cRecords
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordChangeComplete ( _                      ' VTable offset = 24
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYVAL cRecords AS LONG _                           ' __in LONG cRecords
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 '  __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillChangeRecordset ( _                       ' VTable offset = 28
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordsetChangeComplete ( _                   ' VTable offset = 32
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillMove ( _                                  ' VTable offset = 36
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveComplete ( _                              ' VTable offset = 40
     BYVAL adReason AS LONG _                           ' __in EventReasonEnum adReason
   , BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndOfRecordset ( _                            ' VTable offset = 44
     BYREF fMoreData AS INTEGER _                       ' __in_out VARIANT_BOOL *fMoreData
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL ApRecordset AS ADORecordset _                ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FetchProgress ( _                             ' VTable offset = 48
     BYVAL Progress AS LONG _                           ' __in long Progress
   , BYVAL MaxProgress AS LONG _                        ' __in long MaxProgress
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FetchComplete ( _                             ' VTable offset = 52
     BYVAL pError AS ADOError _                         ' __in ADOError *pError
   , BYREF adStatus AS LONG _                           ' __in_out EventStatusEnum *adStatus
   , BYVAL pRecordset AS ADORecordset _                 ' __in _ADORecordset *pRecordset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __RecordsetEventsVt_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Connection15
' IID = {00000515-0000-0010-8000-00AA006D2EA4}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADOConnection15_INTERFACE_DEFINED)
    %ADOConnection15_INTERFACE_DEFINED = 1

INTERFACE ADOConnection15 $IID_ADOConnection15

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Connection15 Methods
   ' =====================================================================================
   PROPERTY GET ConnectionString <0> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET ConnectionString <0> ( _                ' VTable offset = 36
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <2> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *plTimeout
   ' =====================================================================================
   PROPERTY SET CommandTimeout <2> ( _                  ' VTable offset = 44
     BYVAL lTimeout AS LONG _                           ' __in LONG lTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionTimeout <3> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *plTimeout
   ' =====================================================================================
   PROPERTY SET ConnectionTimeout <3> ( _               ' VTable offset = 52
     BYVAL lTimeout AS LONG _                           ' __in LONG lTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <4> ( _                         ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD Close <5> ( _                                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <6> ( _                               ' VTable offset = 64
     BYVAL CommandText AS WSTRING _                     ' __in BSTR CommandText
   , OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = -1
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRset
   ' =====================================================================================
   METHOD BeginTrans <7> ( _                            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *TransactionLevel
   ' =====================================================================================
   METHOD CommitTrans <8> ( _                           ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD RollbackTrans <9> ( _                         ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <10> ( _                                 ' VTable offset = 80
     OPTIONAL BYVAL ConnectionString AS WSTRING _       ' __opt_in BSTR ConnectionString = L""
   , OPTIONAL BYVAL UserID AS WSTRING _                 ' __opt_in BSTR UserID = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Errors <11> ( _                         ' VTable offset = 84
   ) AS ADOErrors                                       ' __retval_out ADOErrors **ppvObject
   ' =====================================================================================
   PROPERTY GET DefaultDatabase <12> ( _                ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET DefaultDatabase <12> ( _                ' VTable offset = 92
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsolationLevel <13> ( _                 ' VTable offset = 96
   ) AS LONG                                            ' __retval_out IsolationLevelEnum *Level
   ' =====================================================================================
   PROPERTY SET IsolationLevel <13> ( _                 ' VTable offset = 100
     BYVAL Level AS LONG _                              ' __in IsolationLevelEnum Level
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <14> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plAttr
   ' =====================================================================================
   PROPERTY SET Attributes <14> ( _                     ' VTable offset = 108
     BYVAL lAttr AS LONG _                              ' __in long lAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <15> ( _                 ' VTable offset = 112
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc)
   ' =====================================================================================
   PROPERTY SET CursorLocation <15> ( _                 ' VTable offset = 116
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <16> ( _                           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out ConnectModeEnum *plMode
   ' =====================================================================================
   PROPERTY SET Mode <16> ( _                           ' VTable offset = 124
     BYVAL lMode AS LONG _                              ' __in ConnectModeEnum lMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Provider <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET Provider <17> ( _                       ' VTable offset = 132
     BYVAL Provider AS WSTRING _                        ' __in BSTR Provider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <18> ( _                          ' VTable offset = 136
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD OpenSchema <19> ( _                           ' VTable offset = 140
     BYVAL Schema AS LONG _                             ' __in SchemaEnum Schema
   , OPTIONAL BYVAL Restrictions AS VARIANT _           ' __opt_in VARIANT Restrictions
   , OPTIONAL BYVAL SchemaID AS VARIANT _               ' __opt_in VARIANT SchemaID
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **pprset
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Connection15_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Connection
' IID = {00000550-0000-0010-8000-00AA006D2EA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = Connection15
' ########################################################################################

#IF NOT %DEF(%ADOConnection_INTERFACE_DEFINED)
    %ADOConnection_INTERFACE_DEFINED = 1

INTERFACE ADOConnection $IID__ADOConnection

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Connection15 Methods
   ' =====================================================================================
   PROPERTY GET ConnectionString <0> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET ConnectionString <0> ( _                ' VTable offset = 36
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommandTimeout <2> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *plTimeout
   ' =====================================================================================
   PROPERTY SET CommandTimeout <2> ( _                  ' VTable offset = 44
     BYVAL lTimeout AS LONG _                           ' __in LONG lTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionTimeout <3> ( _               ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *plTimeout
   ' =====================================================================================
   PROPERTY SET ConnectionTimeout <3> ( _               ' VTable offset = 52
     BYVAL lTimeout AS LONG _                           ' __in LONG lTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <4> ( _                         ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD Close <5> ( _                                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <6> ( _                               ' VTable offset = 64
     BYVAL CommandText AS WSTRING _                     ' __in BSTR CommandText
   , OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = -1
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRset
   ' =====================================================================================
   METHOD BeginTrans <7> ( _                            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *TransactionLevel
   ' =====================================================================================
   METHOD CommitTrans <8> ( _                           ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD RollbackTrans <9> ( _                         ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <10> ( _                                 ' VTable offset = 80
     OPTIONAL BYVAL ConnectionString AS WSTRING _       ' __opt_in BSTR ConnectionString = L""
   , OPTIONAL BYVAL UserID AS WSTRING _                 ' __opt_in BSTR UserID = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in long Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Errors <11> ( _                         ' VTable offset = 84
   ) AS ADOErrors                                       ' __retval_out ADOErrors **ppvObject
   ' =====================================================================================
   PROPERTY GET DefaultDatabase <12> ( _                ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET DefaultDatabase <12> ( _                ' VTable offset = 92
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsolationLevel <13> ( _                 ' VTable offset = 96
   ) AS LONG                                            ' __retval_out IsolationLevelEnum *Level
   ' =====================================================================================
   PROPERTY SET IsolationLevel <13> ( _                 ' VTable offset = 100
     BYVAL Level AS LONG _                              ' __in IsolationLevelEnum Level
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <14> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plAttr
   ' =====================================================================================
   PROPERTY SET Attributes <14> ( _                     ' VTable offset = 108
     BYVAL lAttr AS LONG _                              ' __in long lAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <15> ( _                 ' VTable offset = 112
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc)
   ' =====================================================================================
   PROPERTY SET CursorLocation <15> ( _                 ' VTable offset = 116
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <16> ( _                           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out ConnectModeEnum *plMode
   ' =====================================================================================
   PROPERTY SET Mode <16> ( _                           ' VTable offset = 124
     BYVAL lMode AS LONG _                              ' __in ConnectModeEnum lMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Provider <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET Provider <17> ( _                       ' VTable offset = 132
     BYVAL Provider AS WSTRING _                        ' __in BSTR Provider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <18> ( _                          ' VTable offset = 136
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD OpenSchema <19> ( _                           ' VTable offset = 140
     BYVAL Schema AS LONG _                             ' __in SchemaEnum Schema
   , OPTIONAL BYVAL Schema AS VARIANT _                 ' __opt_in VARIANT Restrictions
   , OPTIONAL BYVAL SchemaID As VARIANT _               ' __opt_in VARIANT SchemaID
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **pprset
   ' =====================================================================================

   ' =====================================================================================
   ' Connection Methods
   ' =====================================================================================
   METHOD Cancel <21> ( _                               ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Connection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADOConnectionConstruction15
' IID = {00000516-0000-0010-8000-00AA006D2EA4}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ADOConnectionConstruction15_INTERFACE_DEFINED)
    %ADOConnectionConstruction15_INTERFACE_DEFINED = 1

INTERFACE ADOConnectionConstruction15 $IID_ADOConnectionConstruction15

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET DSO ( _                                 ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out IUnknown **ppDSO
   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out IUnknown **ppSession
   ' =====================================================================================
   METHOD WrapDSOandSession ( _                         ' VTable offset = 20
     BYVAL pDSO AS IUnknown _                           ' __in IUnknown *pDSO
   , BYVAL pSession AS IUnknown _                       ' __in IUnknown *pSession
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADOConnectionConstruction15_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADOConnectionConstruction
' IID = {00000551-0000-0010-8000-00AA006D2EA4}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ADOConnectionConstruction15
' ########################################################################################

#IF NOT %DEF(%ADOConnectionConstruction_INTERFACE_DEFINED)
    %ADOConnectionConstruction_INTERFACE_DEFINED = 1

INTERFACE ADOConnectionConstruction $IID_ADOConnectionConstruction

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET DSO ( _                                 ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out IUnknown **ppDSO
   ' =====================================================================================
   PROPERTY GET Session ( _                             ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out IUnknown **ppSession
   ' =====================================================================================
   METHOD WrapDSOandSession ( _                         ' VTable offset = 20
     BYVAL pDSO AS IUnknown _                           ' __in IUnknown *pDSO
   , BYVAL pSession AS IUnknown _                       ' __in IUnknown *pSession
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADOConnectionConstruction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Record
' IID = {00000562-0000-0010-8000-00AA006D2EA4}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADORecord_INTERFACE_DEFINED)
    %ADORecord_INTERFACE_DEFINED = 1

INTERFACE ADORecord $IID__ADORecord

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Record Methods
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1> ( _                ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1> ( _                ' VTable offset = 36
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1> ( _         ' VTable offset = 40
     BYVAL ACon AS ADOConnection _                      ' __in _ADOConnection *Con
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <2> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out ObjectStateEnum *pState
   ' =====================================================================================
   PROPERTY GET Source <3> ( _                          ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Source <3> ( _                          ' VTable offset = 52
     BYVAL Source AS WSTRING _                          ' __in BSTR Source
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Source <3> ( _                   ' VTable offset = 56
     BYVAL Source AS IDispatch _                        ' __in IDispatch *Source
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <4> ( _                            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out ConnectModeEnum *pMode
   ' =====================================================================================
   PROPERTY SET Mode <4> ( _                            ' VTable offset = 64
     BYVAL Mode AS LONG _                               ' __in ConnectModeEnum Mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParentURL <5> ( _                       ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrParentURL
   ' =====================================================================================
   METHOD MoveRecord <6> ( _                            ' VTable offset = 72
     OPTIONAL BYVAL Source AS WSTRING _                 ' __opt_in BSTR Source = L""
   , OPTIONAL BYVAL Destination AS WSTRING _            ' __opt_in BSTR Destination = L""
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in MoveRecordOptionsEnum Options = adMoveUnspecified
   , OPTIONAL BYVAL Async AS INTEGER _                  ' __opt_in VARIANT_BOOL Async = 0
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNewURL
   ' =====================================================================================
   METHOD CopyRecord <7> ( _                            ' VTable offset = 76
     OPTIONAL BYVAL Source AS WSTRING _                 ' __opt_in BSTR Source = L""
   , OPTIONAL BYVAL Destination AS WSTRING _            ' __opt_in BSTR Destination = L""
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   , OPTIONAL BYVAL Async AS LONG _                     ' __opt_in CopyRecordOptionsEnum Options = adCopyUnspecified
   , OPTIONAL BYVAL pbstrNewURL AS INTEGER _            ' __opt_in VARIANT_BOOL Async = 0
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNewURL
   ' =====================================================================================
   METHOD DeleteRecord <8> ( _                          ' VTable offset = 80
     OPTIONAL BYVAL Source AS WSTRING _                 ' __opt_in BSTR Source = L""
   , OPTIONAL BYVAL IAsync AS INTEGER _                 ' __opt_in VARIANT_BOOL Async = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <9> ( _                                  ' VTable offset = 84
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       '  __opt_in VARIANT ActiveConnection
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode = adModeUnknown
   , OPTIONAL BYVAL CreateOptions AS LONG _             ' __opt_in RecordCreateOptionsEnum CreateOptions = adFailIfNotExists
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in RecordOpenOptionsEnum Options = adOpenRecordUnspecified
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <10> ( _                                ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 92
   ) AS ADOFields                                       ' __retval_out ADOFields **ppFlds
   ' =====================================================================================
   PROPERTY GET RecordType <11> ( _                     ' VTable offset = 96
   ) AS LONG                                            ' __retval_out RecordTypeEnum *pType
   ' =====================================================================================
   METHOD GetChildren <12> ( _                          ' VTable offset = 100
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppRSet
   ' =====================================================================================
   METHOD Cancel <13> ( _                               ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Record_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Stream
' IID = {00000565-0000-0010-8000-00AA006D2EA4}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOStream_INTERFACE_DEFINED)
    %ADOStream_INTERFACE_DEFINED = 1

INTERFACE ADOStream $IID__ADOStream

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Size <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pSize
   ' =====================================================================================
   PROPERTY GET EOS <2> ( _                             ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pEOS
   ' =====================================================================================
   PROPERTY GET Position <3> ( _                        ' VTable offset = 36
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pPos
   ' =====================================================================================
   PROPERTY SET Position <3> ( _                        ' VTable offset = 40
     BYVAL Position AS LONG _                           ' __in ADO_LONGPTR Position
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <4> ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out StreamTypeEnum *pType
   ' =====================================================================================
   PROPERTY SET Type <4> ( _                            ' VTable offset = 48
     BYVAL Type AS LONG _                               ' __in StreamTypeEnum Type
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineSeparator <5> ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LineSeparatorEnum *pLS
   ' =====================================================================================
   PROPERTY SET LineSeparator <5> ( _                   ' VTable offset = 56
     BYVAL LineSeparator AS LONG _                      ' __in LineSeparatorEnum LineSeparator
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <6> ( _                           ' VTable offset = 60
   ) AS LONG                                            '  __retval_out ObjectStateEnum *pState
   ' =====================================================================================
   PROPERTY GET Mode <7> ( _                            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out ConnectModeEnum *pMode
   ' =====================================================================================
   PROPERTY SET Mode <7> ( _                            ' VTable offset = 68
     BYVAL Mode AS LONG _                               ' __in ConnectModeEnum Mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Charset <8> ( _                         ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCharset
   ' =====================================================================================
   PROPERTY SET Charset <8> ( _                         ' VTable offset = 76
     BYVAL Charset AS WSTRING _                         ' __in BSTR Charset
   )                                                    ' void
   ' =====================================================================================
   METHOD Read <9> ( _                                  ' VTable offset = 80
     OPTIONAL BYVAL NumBytes AS LONG _                  ' __opt_in long NumBytes
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD Open <10> ( _                                 ' VTable offset = 84
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL Mode AS LONG _                      ' __opt_in ConnectModeEnum Mode = adModeUnknown
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in StreamOpenOptionsEnum Options = adOpenStreamUnspecified
   , OPTIONAL BYVAL UserName AS WSTRING _               ' __opt_in BSTR UserName = L""
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <11> ( _                                ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD SkipLine <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Write <13> ( _                                ' VTable offset = 96
     BYVAL Buffer AS VARIANT _                          ' __in VARIANT Buffer
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEOS <14> ( _                               ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyTo <15> ( _                               ' VTable offset = 104
     BYVAL DestStream AS ADOStream _                    ' __in _ADOStream *DestStream
   , OPTIONAL BYVAL CharNumber AS LONG _                ' __opt_in ADO_LONGPTR CharNumber = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush <16> ( _                                ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveToFile <17> ( _                           ' VTable offset = 112
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   , OPTIONAL BYVAL SaveOptionsEnum AS LONG _           ' __opt_in SaveOptionsEnum Options = adSaveCreateNotExist
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadFromFile <18> ( _                         ' VTable offset = 116
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadText <19> ( _                             ' VTable offset = 120
     OPTIONAL BYVAL NumChars AS LONG _                  ' __opt_in long NumChars = -1
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD WriteText <20> ( _                            ' VTable offset = 124
     BYVAL Data AS WSTRING _                            ' __in BSTR Data
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in StreamWriteEnum Options = adWriteChar
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <21> ( _                               ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Stream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADORecordConstruction
' IID = {00000567-0000-0010-8000-00AA006D2EA4}
' Attributes = 4608 [&H1200] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADORecordConstruction_INTERFACE_DEFINED)
    %ADORecordConstruction_INTERFACE_DEFINED = 1

INTERFACE ADORecordConstruction $IID_ADORecordConstruction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Row <1610743808> ( _                    ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppRow
   ' =====================================================================================
   PROPERTY SET Row <1610743808> ( _                    ' VTable offset = 32
     BYVAL pRow AS IUnknown _                           ' __in IUnknown *pRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ParentRow <1610743810> ( _              ' VTable offset = 36
     BYVAL pRow AS IUnknown _                           ' __in IUnknown *pRow
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADORecordConstruction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADOStreamConstruction
' IID = {00000568-0000-0010-8000-00AA006D2EA4}
' Attributes = 4608 [&H1200] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOStreamConstruction_INTERFACE_DEFINED)
    %ADOStreamConstruction_INTERFACE_DEFINED = 1

INTERFACE ADOStreamConstruction $IID_ADOStreamConstruction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Stream <1610743808> ( _                 ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppStm
   ' =====================================================================================
   PROPERTY SET Stream <1610743808> ( _                 ' VTable offset = 32
     BYVAL pStm AS IUnknown _                           ' __in IUnknown *pStm
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADOStreamConstruction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADOCommandConstruction
' IID = {00000517-0000-0010-8000-00AA006D2EA4}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ADOCommandConstruction_INTERFACE_DEFINED)
    %ADOCommandConstruction_INTERFACE_DEFINED = 1

INTERFACE ADOCommandConstruction $IID_ADOCommandConstruction

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET OLEDBCommand ( _                        ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out IUnknown **ppOLEDBCommand
   ' =====================================================================================
   PROPERTY SET OLEDBCommand ( _                        ' VTable offset = 16
     BYVAL pOLEDBCommand AS IUnknown _                  ' __in IUnknown *pOLEDBCommand
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADOCommandConstruction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Recordset15
' IID = {0000050E-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADORecordset15_INTERFACE_DEFINED)
    %ADORecordset15_INTERFACE_DEFINED = 1

INTERFACE ADORecordset15 $IID_ADORecordset15

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset15 Methods
   ' =====================================================================================
   PROPERTY GET AbsolutePosition <1000> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePosition <1000> ( _             ' VTable offset = 36
     BYVAL Position AS LONG _                           ' __in PositionEnum_Param Position
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1001> ( _      ' VTable offset = 40
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1001> ( _             ' VTable offset = 44
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1001> ( _             ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET BOF <1002> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Bookmark <1003> ( _                     ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBookmark
   ' =====================================================================================
   PROPERTY SET Bookmark <1003> ( _                     ' VTable offset = 60
     BYVAL vBookmark AS VARIANT _                       ' __in VARIANT vBookmark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheSize <1004> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET CacheSize <1004> ( _                    ' VTable offset = 68
     BYVAL CacheSize AS LONG _                          ' __in long CacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorType <1005> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CursorTypeEnum *plCursorType
   ' =====================================================================================
   PROPERTY SET CursorType ( _                          ' VTable offset = 76
     BYVAL lCursorType AS LONG _                        ' __in CursorTypeEnum lCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOF <1006> ( _                          ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 84
   ) AS ADOFields                                       ' __retval_out ADOFields **ppvObject
   ' =====================================================================================
   PROPERTY GET LockType <1008> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LockTypeEnum *plLockType
   ' =====================================================================================
   PROPERTY SET LockType <1008> ( _                     ' VTable offset = 92
     BYVAL lLockType AS LONG _                          ' __in LockTypeEnum lLockType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRecords <1009> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *plMaxRecords
   ' =====================================================================================
   PROPERTY SET MaxRecords <1009> ( _                   ' VTable offset = 100
     BYVAL lMaxRecords AS LONG _                        ' __in ADO_LONGPTR lMaxRecords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordCount <1010> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY SET putref_Source <1011> ( _                ' VTable offset = 108
     BYVAL pcmd AS IDispatch _                          ' __in IDispatch *pcmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Source <1011> ( _                       ' VTable offset = 112
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1011> ( _                       ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSource
   ' =====================================================================================
   METHOD AddNew <1012> ( _                             ' VTable offset = 120
     OPTIONAL BYVAL FieldList AS VARIANT _              ' __opt_in VARIANT FieldList
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <1013> ( _                       ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1014> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1015> ( _                             ' VTable offset = 132
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectCurrent [hasdefault = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRows <1016> ( _                            ' VTable offset = 136
     OPTIONAL BYVAL Rows AS LONG _                      ' __opt_in long Rows = -1
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   , OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   METHOD Move <1017> ( _                               ' VTable offset = 140
     BYVAL NumRecords AS LONG _                         ' __in ADO_LONGPTR NumRecords
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <1018> ( _                           ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD MovePrevious <1019> ( _                       ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <1020> ( _                          ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveLast <1021> ( _                           ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1022> ( _                               ' VTable offset = 160
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       ' __opt_in VARIANT ActiveConnection
   , OPTIONAL BYVAL CursorType AS LONG _                ' __opt_in CursorTypeEnum CursorType = adOpenUnspecified
   , OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType = adLockUnspecified
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adCmdUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Requery <1023> ( _                            ' VTable offset = 164
     OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD xResync_ <1610809378> ( _                     ' VTable offset = 168
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1025> ( _                             ' VTable offset = 172
     OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsolutePage <1047> ( _                 ' VTable offset = 176
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePage <1047> ( _                 ' VTable offset = 180
     BYVAL Page AS LONG _                               ' __in PositionEnum_Param Page
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditMode <1026> ( _                     ' VTable offset = 184
   ) AS LONG                                            ' __retval_out EditModeEnum *pl
   ' =====================================================================================
   PROPERTY GET Filter <1030> ( _                       ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *Criteria
   ' =====================================================================================
   PROPERTY SET Filter <1030> ( _                       ' VTable offset = 192
     BYVAL Criteria AS VARIANT _                        ' __in VARIANT Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PageCount <1050> ( _                    ' VTable offset = 196
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET PageSize <1048> ( _                     ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET PageSize <1048> ( _                     ' VTable offset = 204
     BYVAL PageSize AS LONG _                           ' __in long PageSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sort <1031> ( _                         ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *Criteria
   ' =====================================================================================
   PROPERTY SET Sort <1031> ( _                         ' VTable offset = 212
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <1029> ( _                       ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET State <1054> ( _                        ' VTable offset = 220
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD xClone_ <1610809392> ( _                      ' VTable offset = 224
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD UpdateBatch <1035> ( _                        ' VTable offset = 228
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelBatch <1049> ( _                        ' VTable offset = 232
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <1051> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc
   ' =====================================================================================
   PROPERTY SET CursorLocation <1051> ( _               ' VTable offset = 240
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   METHOD NextRecordset <1052> ( _                      ' VTable offset = 244
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRs
   ' =====================================================================================
   METHOD Supports <1036> ( _                           ' VTable offset = 248
     BYVAL CursorOptions AS LONG _                      ' __in CursorOptionEnum CursorOptions
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Collect <-8> ( _                        ' VTable offset = 252
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Collect <-8> ( _                        ' VTable offset = 256
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarshalOptions <1053> ( _               ' VTable offset = 260
   ) AS LONG                                            ' __retval_out MarshalOptionsEnum *peMarshal
   ' =====================================================================================
   PROPERTY SET MarshalOptions <1053> ( _               ' VTable offset = 264
     BYVAL eMarshal AS LONG _                           ' __in MarshalOptionsEnum eMarshal
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <1058> ( _                               ' VTable offset = 268
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   , OPTIONAL BYVAL SkipRecords AS LONG _               ' __opt_in ADO_LONGPTR SkipRecords [hasdefault = 0]
   , OPTIONAL BYVAL SearchDirection AS LONG _           ' __opt_in SearchDirectionEnum SearchDirection = adSearchForward
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Recordset15_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Recordset20
' IID = {0000054F-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Recordset15
' ########################################################################################

#IF NOT %DEF(%ADORecordset20_INTERFACE_DEFINED)
    %ADORecordset20_INTERFACE_DEFINED = 1

INTERFACE ADORecordset20 $IID_ADORecordset20

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset15 Methods
   ' =====================================================================================
   PROPERTY GET AbsolutePosition <1000> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePosition <1000> ( _             ' VTable offset = 36
     BYVAL Position AS LONG _                           ' __in PositionEnum_Param Position
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1001> ( _      ' VTable offset = 40
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1001> ( _             ' VTable offset = 44
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1001> ( _             ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET BOF <1002> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Bookmark <1003> ( _                     ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBookmark
   ' =====================================================================================
   PROPERTY SET Bookmark <1003> ( _                     ' VTable offset = 60
     BYVAL vBookmark AS VARIANT _                       ' __in VARIANT vBookmark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheSize <1004> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET CacheSize <1004> ( _                    ' VTable offset = 68
     BYVAL CacheSize AS LONG _                          ' __in long CacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorType <1005> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CursorTypeEnum *plCursorType
   ' =====================================================================================
   PROPERTY SET CursorType <1005> ( _                   ' VTable offset = 76
     BYVAL lCursorType AS LONG _                        ' __in CursorTypeEnum lCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOF <1006> ( _                          ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 84
   ) AS ADOFields                                       ' __retval_out ADOFields **ppvObject
   ' =====================================================================================
   PROPERTY GET LockType <1008> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LockTypeEnum *plLockType
   ' =====================================================================================
   PROPERTY SET LockType <1008> ( _                     ' VTable offset = 92
     BYVAL lLockType AS LONG _                          ' __in LockTypeEnum lLockType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRecords <1009> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *plMaxRecords
   ' =====================================================================================
   PROPERTY SET MaxRecords <1009> ( _                   ' VTable offset = 100
     BYVAL lMaxRecords AS LONG _                        ' __in ADO_LONGPTR lMaxRecords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordCount <1010> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY SET putref_Source <1011> ( _                ' VTable offset = 108
     BYVAL pcmd AS IDispatch _                          ' __in IDispatch *pcmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Source <1011> ( _                       ' VTable offset = 112
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1011> ( _                       ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSource
   ' =====================================================================================
   METHOD AddNew <1012> ( _                             ' VTable offset = 120
     OPTIONAL BYVAL FieldList AS VARIANT _              ' __opt_in VARIANT FieldList
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <1013> ( _                       ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1014> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1015> ( _                             ' VTable offset = 132
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectCurrent [hasdefault = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRows <1016> ( _                            ' VTable offset = 136
     OPTIONAL BYVAL Rows AS LONG _                      ' __opt_in long Rows = -1
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   , OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   METHOD Move <1017> ( _                               ' VTable offset = 140
     BYVAL NumRecords AS LONG _                         ' __in ADO_LONGPTR NumRecords
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <1018> ( _                           ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD MovePrevious <1019> ( _                       ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <1020> ( _                          ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveLast <1021> ( _                           ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1022> ( _                               ' VTable offset = 160
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       ' __opt_in VARIANT ActiveConnection
   , OPTIONAL BYVAL CursorType AS LONG _                ' __opt_in CursorTypeEnum CursorType = adOpenUnspecified
   , OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType = adLockUnspecified
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adCmdUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Requery <1023> ( _                            ' VTable offset = 164
     OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD xResync_ <1610809378> ( _                     ' VTable offset = 168
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1025> ( _                             ' VTable offset = 172
     OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsolutePage <1047> ( _                 ' VTable offset = 176
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePage <1047> ( _                 ' VTable offset = 180
     BYVAL Page AS LONG _                               ' __in PositionEnum_Param Page
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditMode <1026> ( _                     ' VTable offset = 184
   ) AS LONG                                            ' __retval_out EditModeEnum *pl
   ' =====================================================================================
   PROPERTY GET Filter <1030> ( _                       ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *Criteria
   ' =====================================================================================
   PROPERTY SET Filter <1030> ( _                       ' VTable offset = 192
     BYVAL Criteria AS VARIANT _                        ' __in VARIANT Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PageCount <1050> ( _                    ' VTable offset = 196
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET PageSize <1048> ( _                     ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET PageSize <1048> ( _                     ' VTable offset = 204
     BYVAL PageSize AS LONG _                           ' __in long PageSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sort <1031> ( _                         ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *Criteria
   ' =====================================================================================
   PROPERTY SET Sort <1031> ( _                         ' VTable offset = 212
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <1029> ( _                       ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET State <1054> ( _                        ' VTable offset = 220
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD xClone_ <1610809392> ( _                      ' VTable offset = 224
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD UpdateBatch <1035> ( _                        ' VTable offset = 228
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelBatch <1049> ( _                        ' VTable offset = 232
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <1051> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc
   ' =====================================================================================
   PROPERTY SET CursorLocation <1051> ( _               ' VTable offset = 240
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   METHOD NextRecordset <1052> ( _                      ' VTable offset = 244
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRs
   ' =====================================================================================
   METHOD Supports <1036> ( _                           ' VTable offset = 248
     BYVAL CursorOptions AS LONG _                      ' __in CursorOptionEnum CursorOptions
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Collect <-8> ( _                        ' VTable offset = 252
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Collect <-8> ( _                        ' VTable offset = 256
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarshalOptions <1053> ( _               ' VTable offset = 260
   ) AS LONG                                            ' __retval_out MarshalOptionsEnum *peMarshal
   ' =====================================================================================
   PROPERTY SET MarshalOptions <1053> ( _               ' VTable offset = 264
     BYVAL eMarshal AS LONG _                           ' __in MarshalOptionsEnum eMarshal
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <1058> ( _                               ' VTable offset = 268
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   , OPTIONAL BYVAL SkipRecords AS LONG _               ' __opt_in ADO_LONGPTR SkipRecords
   , OPTIONAL BYVAL SearchDirection AS LONG _           ' __opt_in SearchDirectionEnum SearchDirection = adSearchForward
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset20 Methods
   ' =====================================================================================
   METHOD Cancel <1055> ( _                             ' VTable offset = 272
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <1056> ( _                   ' VTable offset = 276
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkDataSource
   ' =====================================================================================
   PROPERTY SET putref_DataSource <1056> ( _            ' VTable offset = 280
     BYVAL punkDataSource AS IUnknown _                 ' __in IUnknown *punkDataSource
   )                                                    ' void
   ' =====================================================================================
   METHOD xSave_ <1610874883> ( _                       ' VTable offset = 284
     OPTIONAL BYVAL FileName AS WSTRING _               ' __opt_in BSTR FileName = L""
   , OPTIONAL BYVAL PersistFormat AS LONG _             ' __opt_in PersistFormatEnum PersistFormat = adPersistADTG
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveCommand <1061> ( _                ' VTable offset = 288
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCmd
   ' =====================================================================================
   PROPERTY SET StayInSync <1063> ( _                   ' VTable offset = 292
     BYVAL bStayInSync AS INTEGER _                     ' __in VARIANT_BOOL bStayInSync
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StayInSync <1063> ( _                   ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbStayInSync
   ' =====================================================================================
   METHOD GetString <1062> ( _                          ' VTable offset = 300
     OPTIONAL BYVAL StringFormat AS LONG _              ' __opt_in StringFormatEnum StringFormat = adClipString
   , OPTIONAL BYVAL NumRows AS LONG _                   ' __opt_in long NumRows = -1
   , OPTIONAL BYVAL ColumnDelimeter AS WSTRING _        ' __opt_in BSTR ColumnDelimeter = L""
   , OPTIONAL BYVAL RowDelimeter AS WSTRING _           ' __opt_in BSTR RowDelimeter = L""
   , OPTIONAL BYVAL NullExpr AS WSTRING _               ' __opt_in BSTR NullExpr = L""
   ) AS WSTRING                                         ' __retval_out BSTR *pRetString
   ' =====================================================================================
   PROPERTY GET DataMember <1064> ( _                   ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDataMember
   ' =====================================================================================
   PROPERTY SET DataMember <1064> ( _                   ' VTable offset = 308
     BYVAL bstrDataMember AS WSTRING _                  ' __in BSTR bstrDataMember
   )                                                    ' void
   ' =====================================================================================
   METHOD CompareBookmarks <1065> ( _                   ' VTable offset = 312
     BYVAL Bookmark1 AS VARIANT _                       ' __in VARIANT Bookmark1
   , BYVAL Bookmark2 AS VARIANT _                       ' __in VARIANT Bookmark2
   ) AS LONG                                            ' __retval_out CompareEnum *pCompare
   ' =====================================================================================
   METHOD Clone <1034> ( _                              ' VTable offset = 316
     OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD Resync <1024> ( _                             ' VTable offset = 320
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   , OPTIONAL BYVAL ResyncValues AS LONG _              ' __opt_in ResyncEnum ResyncValues = adResyncAllValues
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Recordset20_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Recordset21
' IID = {00000555-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Recordset20
' ########################################################################################

#IF NOT %DEF(%ADORecordset21_INTERFACE_DEFINED)
    %ADORecordset21_INTERFACE_DEFINED = 1

INTERFACE ADORecordset21 $IID_ADORecordset21

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset15 Methods
   ' =====================================================================================
   PROPERTY GET AbsolutePosition <1000> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePosition <1000> ( _             ' VTable offset = 36
     BYVAL Position AS LONG _                           ' __in PositionEnum_Param Position
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1001> ( _      ' VTable offset = 40
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1001> ( _             ' VTable offset = 44
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1001> ( _             ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET BOF <1002> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Bookmark <1003> ( _                     ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBookmark
   ' =====================================================================================
   PROPERTY SET Bookmark <1003> ( _                     ' VTable offset = 60
     BYVAL vBookmark AS VARIANT _                       ' __in VARIANT vBookmark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheSize <1004> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET CacheSize <1004> ( _                    ' VTable offset = 68
     BYVAL CacheSize AS LONG _                          ' __in long CacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorType <1005> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CursorTypeEnum *plCursorType
   ' =====================================================================================
   PROPERTY SET CursorType ( _                          ' VTable offset = 76
     BYVAL lCursorType AS LONG _                        ' __in CursorTypeEnum lCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOF <1006> ( _                          ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 84
   ) AS ADOFields                                       ' __retval_out ADOFields **ppvObject
   ' =====================================================================================
   PROPERTY GET LockType <1008> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LockTypeEnum *plLockType
   ' =====================================================================================
   PROPERTY SET LockType <1008> ( _                     ' VTable offset = 92
     BYVAL lLockType AS LONG _                          ' __in LockTypeEnum lLockType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRecords <1009> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *plMaxRecords
   ' =====================================================================================
   PROPERTY SET MaxRecords <1009> ( _                   ' VTable offset = 100
     BYVAL lMaxRecords AS LONG _                        ' __in ADO_LONGPTR lMaxRecords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordCount <1010> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY SET putref_Source <1011> ( _                ' VTable offset = 108
     BYVAL pcmd AS IDispatch _                          ' __in IDispatch *pcmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Source <1011> ( _                       ' VTable offset = 112
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1011> ( _                       ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSource
   ' =====================================================================================
   METHOD AddNew <1012> ( _                             ' VTable offset = 120
     OPTIONAL BYVAL FieldList AS VARIANT _              ' __opt_in VARIANT FieldList
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <1013> ( _                       ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1014> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1015> ( _                             ' VTable offset = 132
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectCurrent [hasdefault = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRows <1016> ( _                            ' VTable offset = 136
     OPTIONAL BYVAL Rows AS LONG _                      ' __opt_in long Rows = -1
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   , OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   METHOD Move <1017> ( _                               ' VTable offset = 140
     BYVAL NumRecords AS LONG _                         ' __in ADO_LONGPTR NumRecords
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <1018> ( _                           ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD MovePrevious <1019> ( _                       ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <1020> ( _                          ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveLast <1021> ( _                           ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1022> ( _                               ' VTable offset = 160
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       ' __opt_in VARIANT ActiveConnection
   , OPTIONAL BYVAL CursorType AS LONG _                ' __opt_in CursorTypeEnum CursorType = adOpenUnspecified
   , OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType = adLockUnspecified
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adCmdUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Requery <1023> ( _                            ' VTable offset = 164
     OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD xResync_ <1610809378> ( _                     ' VTable offset = 168
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1025> ( _                             ' VTable offset = 172
     OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsolutePage <1047> ( _                 ' VTable offset = 176
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePage <1047> ( _                 ' VTable offset = 180
     BYVAL Page AS LONG _                               ' __in PositionEnum_Param Page
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditMode <1026> ( _                     ' VTable offset = 184
   ) AS LONG                                            ' __retval_out EditModeEnum *pl
   ' =====================================================================================
   PROPERTY GET Filter <1030> ( _                       ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *Criteria
   ' =====================================================================================
   PROPERTY SET Filter <1030> ( _                       ' VTable offset = 192
     BYVAL Criteria AS VARIANT _                        ' __in VARIANT Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PageCount <1050> ( _                    ' VTable offset = 196
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET PageSize <1048> ( _                     ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET PageSize <1048> ( _                     ' VTable offset = 204
     BYVAL PageSize AS LONG _                           ' __in long PageSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sort <1031> ( _                         ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *Criteria
   ' =====================================================================================
   PROPERTY SET Sort <1031> ( _                         ' VTable offset = 212
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <1029> ( _                       ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET State <1054> ( _                        ' VTable offset = 220
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD xClone_ <1610809392> ( _                      ' VTable offset = 224
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD UpdateBatch <1035> ( _                        ' VTable offset = 228
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelBatch <1049> ( _                        ' VTable offset = 232
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <1051> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc
   ' =====================================================================================
   PROPERTY SET CursorLocation <1051> ( _               ' VTable offset = 240
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   METHOD NextRecordset <1052> ( _                      ' VTable offset = 244
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRs
   ' =====================================================================================
   METHOD Supports <1036> ( _                           ' VTable offset = 248
     BYVAL CursorOptions AS LONG _                      ' __in CursorOptionEnum CursorOptions
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Collect <-8> ( _                        ' VTable offset = 252
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Collect <-8> ( _                        ' VTable offset = 256
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarshalOptions <1053> ( _               ' VTable offset = 260
   ) AS LONG                                            ' __retval_out MarshalOptionsEnum *peMarshal
   ' =====================================================================================
   PROPERTY SET MarshalOptions <1053> ( _               ' VTable offset = 264
     BYVAL eMarshal AS LONG _                           ' __in MarshalOptionsEnum eMarshal
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <1058> ( _                               ' VTable offset = 268
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   , OPTIONAL BYVAL SkipRecords AS LONG _               ' __opt_in ADO_LONGPTR SkipRecords
   , OPTIONAL BYVAL SearchDirection AS LONG _           ' __opt_in SearchDirectionEnum SearchDirection = adSearchForward
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset20 Methods
   ' =====================================================================================
   METHOD Cancel <1055> ( _                             ' VTable offset = 272
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <1056> ( _                   ' VTable offset = 276
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkDataSource
   ' =====================================================================================
   PROPERTY SET putref_DataSource <1056> ( _            ' VTable offset = 280
     BYVAL punkDataSource AS IUnknown _                 ' __in IUnknown *punkDataSource
   )                                                    ' void
   ' =====================================================================================
   METHOD xSave_ <1610874883> ( _                       ' VTable offset = 284
     OPTIONAL BYVAL FileName AS WSTRING _               ' __opt_in BSTR FileName = L""
   , OPTIONAL BYVAL PersistFormat AS LONG _             ' __opt_in PersistFormatEnum PersistFormat = adPersistADTG
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveCommand <1061> ( _                ' VTable offset = 288
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCmd
   ' =====================================================================================
   PROPERTY SET StayInSync <1063> ( _                   ' VTable offset = 292
     BYVAL bStayInSync AS INTEGER _                     ' __in VARIANT_BOOL bStayInSync
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StayInSync <1063> ( _                   ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbStayInSync
   ' =====================================================================================
   METHOD GetString <1062> ( _                          ' VTable offset = 300
     OPTIONAL BYVAL StringFormat AS LONG _              ' __opt_in StringFormatEnum StringFormat = adClipString
   , OPTIONAL BYVAL NumRows AS LONG _                   ' __opt_in long NumRows = -1
   , OPTIONAL BYVAL ColumnDelimeter AS WSTRING _        ' __opt_in BSTR ColumnDelimeter = L""
   , OPTIONAL BYVAL RowDelimeter AS WSTRING _           ' __opt_in BSTR RowDelimeter = L""
   , OPTIONAL BYVAL NullExpr AS WSTRING _               ' __opt_in BSTR NullExpr = L""
   ) AS WSTRING                                         ' __retval_out BSTR *pRetString
   ' =====================================================================================
   PROPERTY GET DataMember <1064> ( _                   ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDataMember
   ' =====================================================================================
   PROPERTY SET DataMember <1064> ( _                   ' VTable offset = 308
     BYVAL bstrDataMember AS WSTRING _                  ' __in BSTR bstrDataMember
   )                                                    ' void
   ' =====================================================================================
   METHOD CompareBookmarks <1065> ( _                   ' VTable offset = 312
     BYVAL Bookmark1 AS VARIANT _                       ' __in VARIANT Bookmark1
   , BYVAL Bookmark2 AS VARIANT _                       ' __in VARIANT Bookmark2
   ) AS LONG                                            ' __retval_out CompareEnum *pCompare
   ' =====================================================================================
   METHOD Clone <1034> ( _                              ' VTable offset = 316
     OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD Resync <1024> ( _                             ' VTable offset = 320
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   , OPTIONAL BYVAL ResyncValues AS LONG _              ' __opt_in ResyncEnum ResyncValues = adResyncAllValues
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset21 Methods
   ' =====================================================================================
   METHOD Seek <1066> ( _                               ' VTable offset = 324
     BYVAL KeyValues AS VARIANT _                       ' __in VARIANT KeyValues
   , OPTIONAL BYVAL SeekOption AS LONG _                ' __opt_in SeekEnum SeekOption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Index <1067> ( _                        ' VTable offset = 328
     BYVAL Index AS WSTRING _                           ' __in BSTR Index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <1067> ( _                        ' VTable offset = 332
   ) AS WSTRING                                         ' __retval_out *pbstrIndex /* *VT_BSTR */
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Recordset21_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Recordset
' IID = {00000556-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Recordset21
' ########################################################################################

#IF NOT %DEF(%ADORecordset_INTERFACE_DEFINED)
    %ADORecordset_INTERFACE_DEFINED = 1

INTERFACE ADORecordset $IID__ADORecordset

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset15 Methods
   ' =====================================================================================
   PROPERTY GET AbsolutePosition <1000> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePosition <1000> ( _             ' VTable offset = 36
     BYVAL Position AS LONG _                           ' __in PositionEnum_Param Position
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1001> ( _      ' VTable offset = 40
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1001> ( _             ' VTable offset = 44
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1001> ( _             ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET BOF <1002> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Bookmark <1003> ( _                     ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBookmark
   ' =====================================================================================
   PROPERTY SET Bookmark <1003> ( _                     ' VTable offset = 60
     BYVAL vBookmark AS VARIANT _                       ' __in VARIANT vBookmark
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CacheSize <1004> ( _                    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET CacheSize <1004> ( _                    ' VTable offset = 68
     BYVAL CacheSize AS LONG _                          ' __in long CacheSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorType <1005> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out CursorTypeEnum *plCursorType
   ' =====================================================================================
   PROPERTY SET CursorType ( _                          ' VTable offset = 76
     BYVAL lCursorType AS LONG _                        ' __in CursorTypeEnum lCursorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOF <1006> ( _                          ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Fields <0> ( _                          ' VTable offset = 84
   ) AS ADOFields                                       ' __retval_out ADOFields **ppvObject
   ' =====================================================================================
   PROPERTY GET LockType <1008> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LockTypeEnum *plLockType
   ' =====================================================================================
   PROPERTY SET LockType <1008> ( _                     ' VTable offset = 92
     BYVAL lLockType AS LONG _                          ' __in LockTypeEnum lLockType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxRecords <1009> ( _                   ' VTable offset = 96
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *plMaxRecords
   ' =====================================================================================
   PROPERTY SET MaxRecords <1009> ( _                   ' VTable offset = 100
     BYVAL lMaxRecords AS LONG _                        ' __in ADO_LONGPTR lMaxRecords
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordCount <1010> ( _                  ' VTable offset = 104
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY SET putref_Source <1011> ( _                ' VTable offset = 108
     BYVAL pcmd AS IDispatch _                          ' __in IDispatch *pcmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Source <1011> ( _                       ' VTable offset = 112
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1011> ( _                       ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSource
   ' =====================================================================================
   METHOD AddNew <1012> ( _                             ' VTable offset = 120
     OPTIONAL BYVAL FieldList AS VARIANT _              ' __opt_in VARIANT FieldList
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <1013> ( _                       ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1014> ( _                              ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1015> ( _                             ' VTable offset = 132
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectCurrent [hasdefault = 1]
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRows <1016> ( _                            ' VTable offset = 136
     OPTIONAL BYVAL Rows AS LONG _                      ' __opt_in long Rows = -1
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   , OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   METHOD Move <1017> ( _                               ' VTable offset = 140
     BYVAL NumRecords AS LONG _                         ' __in ADO_LONGPTR NumRecords
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveNext <1018> ( _                           ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD MovePrevious <1019> ( _                       ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveFirst <1020> ( _                          ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveLast <1021> ( _                           ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1022> ( _                               ' VTable offset = 160
     OPTIONAL BYVAL Source AS VARIANT _                 ' __opt_in VARIANT Source
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       ' __opt_in VARIANT ActiveConnection
   , OPTIONAL BYVAL CursorType AS LONG _                ' __opt_in CursorTypeEnum CursorType = adOpenUnspecified
   , OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType = adLockUnspecified
   , OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adCmdUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Requery <1023> ( _                            ' VTable offset = 164
     OPTIONAL BYVAL Options AS LONG _                   ' __opt_in LONG Options = adOptionUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD xResync_ <1610809378> ( _                     ' VTable offset = 168
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1025> ( _                             ' VTable offset = 172
     OPTIONAL BYVAL Fields AS VARIANT _                 ' __opt_in VARIANT Fields
   , OPTIONAL BYVAL Values AS VARIANT _                 ' __opt_in VARIANT Values
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AbsolutePage <1047> ( _                 ' VTable offset = 176
   ) AS LONG                                            ' __retval_out PositionEnum_Param *pl
   ' =====================================================================================
   PROPERTY SET AbsolutePage <1047> ( _                 ' VTable offset = 180
     BYVAL Page AS LONG _                               ' __in PositionEnum_Param Page
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EditMode <1026> ( _                     ' VTable offset = 184
   ) AS LONG                                            ' __retval_out EditModeEnum *pl
   ' =====================================================================================
   PROPERTY GET Filter <1030> ( _                       ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *Criteria
   ' =====================================================================================
   PROPERTY SET Filter <1030> ( _                       ' VTable offset = 192
     BYVAL VARIANT _                                    ' __in VARIANT Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PageCount <1050> ( _                    ' VTable offset = 196
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET PageSize <1048> ( _                     ' VTable offset = 200
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET PageSize <1048> ( _                     ' VTable offset = 204
     BYVAL PageSize AS LONG _                           ' __in long PageSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sort <1031> ( _                         ' VTable offset = 208
   ) AS WSTRING                                         ' __retval_out BSTR *Criteria
   ' =====================================================================================
   PROPERTY SET Sort <1031> ( _                         ' VTable offset = 212
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <1029> ( _                       ' VTable offset = 216
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET State <1054> ( _                        ' VTable offset = 220
   ) AS LONG                                            ' __retval_out LONG *plObjState
   ' =====================================================================================
   METHOD xClone_ <1610809392> ( _                      ' VTable offset = 224
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD UpdateBatch <1035> ( _                        ' VTable offset = 228
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelBatch <1049> ( _                        ' VTable offset = 232
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CursorLocation <1051> ( _               ' VTable offset = 236
   ) AS LONG                                            ' __retval_out CursorLocationEnum *plCursorLoc
   ' =====================================================================================
   PROPERTY SET CursorLocation <1051> ( _               ' VTable offset = 240
     BYVAL lCursorLoc AS LONG _                         ' __in CursorLocationEnum lCursorLoc
   )                                                    ' void
   ' =====================================================================================
   METHOD NextRecordset <1052> ( _                      ' VTable offset = 244
     OPTIONAL BYREF RecordsAffected AS VARIANT _        ' __opt_out VARIANT *RecordsAffected
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppiRs
   ' =====================================================================================
   METHOD Supports <1036> ( _                           ' VTable offset = 248
     BYVAL CursorOptions AS LONG _                      ' __in CursorOptionEnum CursorOptions
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pb
   ' =====================================================================================
   PROPERTY GET Collect <-8> ( _                        ' VTable offset = 252
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Collect <-8> ( _                        ' VTable offset = 256
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MarshalOptions <1053> ( _               ' VTable offset = 260
   ) AS LONG                                            ' __retval_out MarshalOptionsEnum *peMarshal
   ' =====================================================================================
   PROPERTY SET MarshalOptions <1053> ( _               ' VTable offset = 264
     BYVAL eMarshal AS LONG _                           ' __in MarshalOptionsEnum eMarshal
   )                                                    ' void
   ' =====================================================================================
   METHOD Find <1058> ( _                               ' VTable offset = 268
     BYVAL Criteria AS WSTRING _                        ' __in BSTR Criteria
   , OPTIONAL BYVAL SkipRecords AS LONG _               ' __opt_in ADO_LONGPTR SkipRecords
   , OPTIONAL BYVAL SearchDirection AS LONG _           ' __opt_in SearchDirectionEnum SearchDirection = adSearchForward
   , OPTIONAL BYVAL Start AS VARIANT _                  ' __opt_in VARIANT Start
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset20 Methods
   ' =====================================================================================
   METHOD Cancel <1055> ( _                             ' VTable offset = 272
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <1056> ( _                   ' VTable offset = 276
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunkDataSource
   ' =====================================================================================
   PROPERTY SET putref_DataSource <1056> ( _            ' VTable offset = 280
     BYVAL punkDataSource AS IUnknown _                 ' __in IUnknown *punkDataSource
   )                                                    ' void
   ' =====================================================================================
   METHOD xSave_ <1610874883> ( _                       ' VTable offset = 284
     OPTIONAL BYVAL FileName AS WSTRING _               ' __opt_in BSTR FileName = L""
   , OPTIONAL BYVAL PersistFormat AS LONG _             ' __opt_in PersistFormatEnum PersistFormat = adPersistADTG
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveCommand <1061> ( _                ' VTable offset = 288
   ) AS IDispatch                                       ' __retval_out IDispatch **ppCmd
   ' =====================================================================================
   PROPERTY SET StayInSync <1063> ( _                   ' VTable offset = 292
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL bStayInSync
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StayInSync <1063> ( _                   ' VTable offset = 296
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbStayInSync
   ' =====================================================================================
   METHOD GetString <1062> ( _                          ' VTable offset = 300
     OPTIONAL BYVAL StringFormat AS LONG _              ' __opt_in StringFormatEnum StringFormat = adClipString
   , OPTIONAL BYVAL NumRows AS LONG _                   ' __opt_in long NumRows = -1
   , OPTIONAL BYVAL ColumnDelimeter AS WSTRING _        ' __opt_in BSTR ColumnDelimeter = L""
   , OPTIONAL BYVAL NullExpr AS WSTRING _               ' __opt_in BSTR RowDelimeter = L""
   , OPTIONAL BYVAL pRetString AS WSTRING _             ' __opt_in BSTR NullExpr = L""
   ) AS WSTRING                                         ' __retval_out BSTR *pRetString
   ' =====================================================================================
   PROPERTY GET DataMember <1064> ( _                   ' VTable offset = 304
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDataMember
   ' =====================================================================================
   PROPERTY SET DataMember <1064> ( _                   ' VTable offset = 308
     BYVAL bstrDataMember AS WSTRING _                  ' __in BSTR bstrDataMember
   )                                                    ' void
   ' =====================================================================================
   METHOD CompareBookmarks <1065> ( _                   ' VTable offset = 312
     BYVAL Bookmark1 AS VARIANT _                       ' __in VARIANT Bookmark1
   , BYVAL Bookmark2 AS VARIANT _                       ' __in VARIANT Bookmark2
   ) AS LONG                                            ' __retval_out CompareEnum *pCompare
   ' =====================================================================================
   METHOD Clone <1034> ( _                              ' VTable offset = 316
     OPTIONAL BYVAL LockType AS LONG _                  ' __opt_in LockTypeEnum LockType
   ) AS ADORecordset                                    ' __retval_out _ADORecordset **ppvObject
   ' =====================================================================================
   METHOD Resync <1024> ( _                             ' VTable offset = 320
     OPTIONAL BYVAL AffectRecords AS LONG _             ' __opt_in AffectEnum AffectRecords = adAffectAll
   , OPTIONAL BYVAL ResyncValues AS LONG _              ' __opt_in ResyncEnum ResyncValues = adResyncAllValues
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset21 Methods
   ' =====================================================================================
   METHOD Seek <1066> ( _                               ' VTable offset = 324
     BYVAL KeyValues AS VARIANT _                       ' __in VARIANT KeyValues
   , OPTIONAL BYVAL SeekOption AS LONG _                ' __opt_in SeekEnum SeekOption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Index <1067> ( _                        ' VTable offset = 328
     BYVAL Index AS WSTRING _                           ' __in BSTR Index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Index <1067> ( _                        ' VTable offset = 332
   ) AS WSTRING                                         ' __retval_out *pbstrIndex /* *VT_BSTR */
   ' =====================================================================================

   ' =====================================================================================
   ' Recordset Methods
   ' =====================================================================================
   METHOD Save <1057> ( _                               ' VTable offset = 336
     OPTIONAL BYVAL Destination AS VARIANT _            ' __opt_in VARIANT Destination
   , OPTIONAL BYVAL PersistFormat AS LONG _             ' __opt_in PersistFormatEnum PersistFormat = adPersistADTG
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Recordset_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ADORecordsetConstruction
' IID = {00000283-0000-0010-8000-00AA006D2EA4}
' Attributes = 4608 [&H1200] [Restricted] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADORecordsetConstruction_INTERFACE_DEFINED)
    %ADORecordsetConstruction_INTERFACE_DEFINED = 1

INTERFACE ADORecordsetConstruction $IID_ADORecordsetConstruction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Rowset <1610743808> ( _                 ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppRowset
   ' =====================================================================================
   PROPERTY SET Rowset <1610743808> ( _                 ' VTable offset = 32
     BYVAL pRowset AS IUnknown _                        ' __in IUnknown *pRowset
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Chapter <1610743810> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *plChapter
   ' =====================================================================================
   PROPERTY SET Chapter <1610743810> ( _                ' VTable offset = 40
     BYVAL lChapter AS LONG _                           ' __in ADO_LONGPTR lChapter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowPosition <1610743812> ( _            ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **ppRowPos
   ' =====================================================================================
   PROPERTY SET RowPosition <1610743812> ( _            ' VTable offset = 48
     BYVAL pRowPos AS IUnknown _                        ' __in IUnknown *pRowPos
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ADORecordsetConstruction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Field15
' IID = {00000505-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADOField15_INTERFACE_DEFINED)
    %ADOField15_INTERFACE_DEFINED = 1

INTERFACE ADOField15 $IID_ADOField15

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Field15 Methods
   ' =====================================================================================
   PROPERTY GET ActualSize <1109> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Attributes <1114> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET DefinedSize <1103> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Name <1100> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Type <1102> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DataTypeEnum *pDataType
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 56
     BYVAL Val AS VARIANT _                             ' __in VARIANT Val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <1112> ( _                    ' VTable offset = 60
   ) AS BYTE                                            ' __retval_out BYTE *pbPrecision
   ' =====================================================================================
   PROPERTY GET NumericScale <1113> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out BYTE *pbNumericScale
   ' =====================================================================================
   METHOD AppendChunk <1107> ( _                        ' VTable offset = 68
     BYVAL Data AS VARIANT _                            ' __in VARIANT Data
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChunk <1108> ( _                           ' VTable offset = 72
     BYVAL Length AS LONG _                             ' __in long Length
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET OriginalValue <1104> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET UnderlyingValue <1105> ( _              ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Field15_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Field20
' IID = {0000054C-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADOField20_INTERFACE_DEFINED)
    %ADOField20_INTERFACE_DEFINED = 1

INTERFACE ADOField20 $IID_ADOField20

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Field20 Methods
   ' =====================================================================================
   PROPERTY GET ActualSize <1109> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Attributes <1114> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET DefinedSize <1103> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Name <1100> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Type <1102> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DataTypeEnum *pDataType
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 56
     BYVAL Val AS VARIANT _                             ' __in VARIANT Val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <1112> ( _                    ' VTable offset = 60
   ) AS BYTE                                            ' __retval_out BYTE *pbPrecision
   ' =====================================================================================
   PROPERTY GET NumericScale <1113> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out BYTE *pbNumericScale
   ' =====================================================================================
   METHOD AppendChunk <1107> ( _                        ' VTable offset = 68
     BYVAL Data AS VARIANT _                            ' __in VARIANT Data
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChunk <1108> ( _                           ' VTable offset = 72
     BYVAL Length AS LONG _                             ' __in long Length
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET OriginalValue <1104> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET UnderlyingValue <1105> ( _              ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET DataFormat <1115> ( _                   ' VTable offset = 84
   ) AS IUnknown                                        ' __retval_out IUnknown **ppiDF
   ' =====================================================================================
   PROPERTY SET putref_DataFormat <1115> ( _            ' VTable offset = 88
     BYVAL piDF AS IUnknown _                           ' __in IUnknown *piDF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Precision <1112> ( _                    ' VTable offset = 92
     BYVAL bPrecision AS BYTE _                         ' __in BYTE bPrecision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET NumericScale <1113> ( _                 ' VTable offset = 96
     BYVAL bScale AS BYTE _                             ' __in BYTE bScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Type <1102> ( _                         ' VTable offset = 100
     BYVAL DataType AS LONG _                           ' __in DataTypeEnum DataType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DefinedSize <1103> ( _                  ' VTable offset = 104
     BYVAL lSize AS LONG _                              ' __in ADO_LONGPTR lSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Attributes <1114> ( _                   ' VTable offset = 108
     BYVAL lAttributes AS LONG _                        ' __in long lAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Field20_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Field
' IID = {00000569-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Field20
' ########################################################################################

#IF NOT %DEF(%ADOField_INTERFACE_DEFINED)
    %ADOField_INTERFACE_DEFINED = 1

INTERFACE ADOField $IID_ADOField

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Field20 Methods
   ' =====================================================================================
   PROPERTY GET ActualSize <1109> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Attributes <1114> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET DefinedSize <1103> ( _                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   PROPERTY GET Name <1100> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Type <1102> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DataTypeEnum *pDataType
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 56
     BYVAL Val AS VARIANT _                             ' __in VARIANT Val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <1112> ( _                    ' VTable offset = 60
   ) AS BYTE                                            ' __retval_out BYTE *pbPrecision
   ' =====================================================================================
   PROPERTY GET NumericScale <1113> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out BYTE *pbNumericScale
   ' =====================================================================================
   METHOD AppendChunk <1107> ( _                        ' VTable offset = 68
     BYVAL Data AS VARIANT _                            ' __in VARIANT Data
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChunk <1108> ( _                           ' VTable offset = 72
     BYVAL Length AS LONG _                             ' __in long Length
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET OriginalValue <1104> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET UnderlyingValue <1105> ( _              ' VTable offset = 80
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET DataFormat <1115> ( _                   ' VTable offset = 84
   ) AS IUnknown                                        ' __retval_out IUnknown **ppiDF
   ' =====================================================================================
   PROPERTY SET putref_DataFormat <1115> ( _            ' VTable offset = 88
     BYVAL piDF AS IUnknown _                           ' __in IUnknown *piDF
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Precision <1112> ( _                    ' VTable offset = 92
     BYVAL bPrecision AS BYTE _                         ' __in BYTE bPrecision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET NumericScale <1113> ( _                 ' VTable offset = 96
     BYVAL bScale AS BYTE _                             ' __in BYTE bScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Type <1102> ( _                         ' VTable offset = 100
     BYVAL DataType AS LONG _                           ' __in DataTypeEnum DataType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DefinedSize <1103> ( _                  ' VTable offset = 104
     BYVAL lSize AS LONG _                              ' __in ADO_LONGPTR lSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Attributes <1114> ( _                   ' VTable offset = 108
     BYVAL lAttributes AS LONG _                        ' __in long lAttributes
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Field Methods
   ' =====================================================================================
   PROPERTY GET Status <1116> ( _                       ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *pFStatus
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Field_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Fields15
' IID = {00000506-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOFields15_INTERFACE_DEFINED)
    %ADOFields15_INTERFACE_DEFINED = 1

INTERFACE ADOFields15 $IID_ADOFields15

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Fields15 Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOField                                        ' __retval_out ADOField **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Fields15_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Fields20
' IID = {0000054D-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Fields15
' ########################################################################################

#IF NOT %DEF(%ADOFields20_INTERFACE_DEFINED)
    %ADOFields20_INTERFACE_DEFINED = 1

INTERFACE ADOFields20 $IID_ADOFields20

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Fields15 Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOField                                        ' __retval_out ADOField **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Fields20 Methods
   ' =====================================================================================
   METHOD Append_ <1610874880> ( _                      ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Type AS LONG _                               ' __in DataTypeEnum Type
   , OPTIONAL BYVAL DefinedSize AS LONG _               ' __opt_in ADO_LONGPTR DefinedSize = 0
   , OPTIONAL BYVAL Attrib AS LONG _                    ' __opt_in FieldAttributeEnum Attrib = adFldUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <4> ( _                                ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Fields20_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Fields
' IID = {00000564-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = Fields20
' ########################################################################################

#IF NOT %DEF(%ADOFields_INTERFACE_DEFINED)
    %ADOFields_INTERFACE_DEFINED = 1

INTERFACE ADOFields $IID_ADOFields

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Fields15 Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOField                                        ' __retval_out ADOField **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Fields20 Methods
   ' =====================================================================================
   METHOD Append_ <1610874880> ( _                      ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Type AS LONG _                               ' __in DataTypeEnum Type
   , OPTIONAL BYVAL DefinedSize AS LONG _               ' __opt_in ADO_LONGPTR DefinedSize = 0
   , OPTIONAL BYVAL Attrib AS LONG _                    ' __opt_in FieldAttributeEnum Attrib = adFldUnspecified
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <4> ( _                                ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Fields Methods
   ' =====================================================================================
   METHOD Append <3> ( _                                ' VTable offset = 52
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Type AS LONG _                               ' __in DataTypeEnum Type
   , OPTIONAL BYVAL DefinedSize AS LONG _               ' __opt_in ADO_LONGPTR DefinedSize = 0
   , OPTIONAL BYVAL Attrib AS LONG _                    ' __opt_in FieldAttributeEnum Attrib = adFldUnspecified
   , OPTIONAL BYVAL FieldValue AS VARIANT _             ' __opt_in VARIANT FieldValue
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <5> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Resync <6> ( _                                ' VTable offset = 60
     OPTIONAL BYVAL ResyncValues AS LONG _              ' __opt_in ResyncEnum ResyncValues = adResyncAllValues
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelUpdate <7> ( _                          ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Fields_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Parameter
' IID = {0000050C-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _ADO
' ########################################################################################

#IF NOT %DEF(%ADOParameter_INTERFACE_DEFINED)
    %ADOParameter_INTERFACE_DEFINED = 1

INTERFACE ADOParameter $IID__ADOParameter

   INHERIT IDispatch

   ' =====================================================================================
   ' _ADO Methods
   ' =====================================================================================
   PROPERTY GET Properties <500> ( _                    ' VTable offset = 28
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Parameter Methods
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 36
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 40
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 44
     BYVAL VARIANT _                                    ' __in VARIANT val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out DataTypeEnum *psDataType
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 52
     BYVAL sDataType AS LONG _                          ' __in DataTypeEnum sDataType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Direction <3> ( _                       ' VTable offset = 56
     BYVAL lParmDirection AS LONG _                     ' __in ParameterDirectionEnum lParmDirection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Direction <3> ( _                       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out ParameterDirectionEnum *plParmDirection
   ' =====================================================================================
   PROPERTY SET Precision <4> ( _                       ' VTable offset = 64
     BYVAL BYTE _                                       ' __in BYTE bPrecision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <4> ( _                       ' VTable offset = 68
   ) AS BYTE                                            ' __retval_out BYTE *pbPrecision
   ' =====================================================================================
   PROPERTY SET NumericScale <5> ( _                    ' VTable offset = 72
     BYVAL BYTE _                                       ' __in BYTE bScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumericScale <5> ( _                    ' VTable offset = 76
   ) AS BYTE                                            ' __retval_out BYTE *pbScale
   ' =====================================================================================
   PROPERTY SET Size <6> ( _                            ' VTable offset = 80
     BYVAL l AS LONG _                                  ' __in ADO_LONGPTR l
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <6> ( _                            ' VTable offset = 84
   ) AS LONG                                            ' __retval_out ADO_LONGPTR *pl
   ' =====================================================================================
   METHOD AppendChunk <7> ( _                           ' VTable offset = 88
     BYVAL VARIANT _                                    ' __in VARIANT Val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <8> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *plParmAttribs
   ' =====================================================================================
   PROPERTY SET Attributes <8> ( _                      ' VTable offset = 96
     BYVAL lParmAttribs AS LONG _                       ' __in LONG lParmAttribs
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___Parameter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Parameters
' IID = {0000050D-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _DynaCollection
' ########################################################################################

#IF NOT %DEF(%ADOParameters_INTERFACE_DEFINED)
    %ADOParameters_INTERFACE_DEFINED = 1

INTERFACE ADOParameters $IID_ADOParameters

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' _DynaCollection Methods
   ' =====================================================================================
   METHOD Append <1610809344> ( _                       ' VTable offset = 40
     BYVAL Object AS IDispatch _                        ' __in IDispatch *Object
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809345> ( _                       ' VTable offset = 44
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Parameters Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOParameter                                    ' __retval_out _ADOParameter **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Parameters_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Property
' IID = {00000503-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOProperty_INTERFACE_DEFINED)
    %ADOProperty_INTERFACE_DEFINED = 1

INTERFACE ADOProperty $IID_ADOProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pval
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL val AS VARIANT _                             ' __in VARIANT val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610743810> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Type <1610743811> ( _                   ' VTable offset = 40
   ) AS LONG                                            ' __retval_out DataTypeEnum *ptype
   ' =====================================================================================
   PROPERTY GET Attributes <1610743812> ( _             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plAttributes
   ' =====================================================================================
   PROPERTY SET Attributes <1610743812> ( _             ' VTable offset = 48
     BYVAL lAttributes AS LONG _                        ' __in long lAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Property_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Properties
' IID = {00000504-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOProperties_INTERFACE_DEFINED)
    %ADOProperties_INTERFACE_DEFINED = 1

INTERFACE ADOProperties $IID_ADOProperties

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <2> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Properties Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOProperty                                     ' __retval_out ADOProperty **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Properties_INTERFACE_DEFINED__ */
