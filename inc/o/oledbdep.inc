' ########################################################################################
' Microsoft Windows
' File: oledbdep.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEDBDEP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oledb.inc"

'#ifdef _WIN64
'#include <pshpack8.h>   // 8-byte structure packing
'#else
'#include <pshpack2.h>   // 2-byte structure packing
'#endif

#IF NOT %DEF(%DBStructureDefinitionsDep_INTERFACE_DEFINED)
%DBStructureDefinitionsDep_INTERFACE_DEFINED = 1

'#IF %DEF(%DBINITCONSTANTS)
$DB_PROPERTY_CHECK_OPTION              = GUID$("{C8B5220B-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_CONSTRAINT_CHECK_DEFERRED = GUID$("{C8B521F0-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_DROP_CASCADE              = GUID$("{C8B521F3-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_UNIQUE                    = GUID$("{C8B521F5-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_ON_COMMIT_PRESERVE_ROWS   = GUID$("{C8B52230-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_PRIMARY                   = GUID$("{C8B521FC-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_CLUSTERED                 = GUID$("{C8B521FF-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_NONCLUSTERED              = GUID$("{C8B52200-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_BTREE                     = GUID$("{C8B52201-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_HASH                      = GUID$("{C8B52202-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_FILLFACTOR                = GUID$("{C8B52203-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_INITIALSIZE               = GUID$("{C8B52204-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_DISALLOWNULL              = GUID$("{C8B52205-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_IGNORENULL                = GUID$("{C8B52206-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_IGNOREANYNULL             = GUID$("{C8B52207-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_SORTBOOKMARKS             = GUID$("{C8B52208-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_AUTOMATICUPDATE           = GUID$("{C8B52209-5CF3-11CE-ADE5-00AA0044773D}")
$DB_PROPERTY_EXPLICITUPDATE            = GUID$("{C8B5220A-5CF3-11CE-ADE5-00AA0044773D}")
'#ENDIF   ' // DBINITCONSTANTS

' DBPROPENUM25_DEPRECATED
%DBPROP_ICommandCost                        = &H8d&
%DBPROP_ICommandTree                        = &H8e&
%DBPROP_ICommandValidate                    = &H8f&
%DBPROP_IDBSchemaCommand                    = &H90&
%DBPROP_IProvideMoniker                     = &H7d&
%DBPROP_IQuery                              = &H92&
%DBPROP_IReadData                           = &H93&
%DBPROP_IRowsetAsynch                       = &H94&
%DBPROP_IRowsetCopyRows                     = &H95&
%DBPROP_IRowsetKeys                         = &H97&
%DBPROP_IRowsetNewRowAfter                  = &H98&
%DBPROP_IRowsetNextRowset                   = &H99&
%DBPROP_IRowsetWatchAll                     = &H9b&
%DBPROP_IRowsetWatchNotify                  = &H9c&
%DBPROP_IRowsetWatchRegion                  = &H9d&
%DBPROP_IRowsetWithParameters               = &H9e&

' DBREASONENUM25
%DBREASON_ROWSET_ROWSADDED                  = %DBREASON_ROW_ASYNCHINSERT           + 1
%DBREASON_ROWSET_POPULATIONCOMPLETE         = %DBREASON_ROWSET_ROWSADDED           + 1
%DBREASON_ROWSET_POPULATIONSTOPPED          = %DBREASON_ROWSET_POPULATIONCOMPLETE  + 1

#ENDIF   ' /* __DBStructureDefinitionsDep_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetNextRowset interface
' IID = 0C733A72-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetNextRowset_INTERFACE_DEFINED)
%IRowsetNextRowset_INTERFACE_DEFINED = 1

$IID_IRowsetNextRowset = GUID$("{0C733A72-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetNextRowset $IID_IRowsetNextRowset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNextRowset ( _                             ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppNextRowset AS IUnknown _                   ' __out IUnknown **ppNextRowset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetNextRowset_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetNewRowAfter interface
' IID = 0C733A71-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetNewRowAfter_INTERFACE_DEFINED)
%IRowsetNewRowAfter_INTERFACE_DEFINED = 1

$IID_IRowsetNewRowAfter = GUID$("{0C733A71-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetNewRowAfter $IID_IRowsetNewRowAfter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNewDataAfter ( _                           ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbbmPrevious AS DWORD _                      ' __in ULONG cbbmPrevious
   , BYVAL pbmPrevious AS BYTE PTR _                    ' __in const BYTE *pbmPrevious
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL pData AS BYTE PTR _                          ' __in BYTE *pData
   , BYREF phRow AS DWORD _                             ' __out HROW *phRow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetNewRowAfter_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetWithParameters interface
' IID = 0C733A6E-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetWithParameters_INTERFACE_DEFINED)
%IRowsetWithParameters_INTERFACE_DEFINED = 1

$IID_IRowsetWithParameters = GUID$("{0C733A6E-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetWithParameters $IID_IRowsetWithParameters

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetParameterInfo ( _                          ' VTable offset = 12
     BYREF pcParams AS DWORD _                          ' __inout DB_UPARAMS *pcParams
   , BYREF prgParamInfo AS DBPARAMINFO _                ' __out DBPARAMINFO **prgParamInfo
   , BYREF ppNamesBuffer AS DWORD _                     ' __out OLECHAR **ppNamesBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Requery ( _                                   ' VTable offset = 16
     BYREF pParams AS DBPARAMS _                        ' __in DBPARAMS *pParams
   , BYREF pulErrorParam AS DWORD _                     ' __out ULONG *pulErrorParam
   , BYREF phReserved AS DWORD _                        ' __out HCHAPTER *phReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetWithParameters_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetAsynch interface
' IID = 0C733A0F-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetAsynch_INTERFACE_DEFINED)
%IRowsetAsynch_INTERFACE_DEFINED = 1

$IID_IRowsetAsynch = GUID$("{0C733A0F-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetAsynch $IID_IRowsetAsynch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RatioFinished ( _                             ' VTable offset = 12
     BYREF pulDenominator AS DWORD _                    ' __out DBCOUNTITEM *pulDenominator
   , BYREF pulNumerator AS DWORD _                      ' __out DBCOUNTITEM *pulNumerator
   , BYREF pcRows AS DWORD _                            ' __out DBCOUNTITEM *pcRows
   , BYREF pfNewRows AS LONG _                          ' __out BOOL *pfNewRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetAsynch_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetKeys interface
' IID = 0C733A12-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetKeys_INTERFACE_DEFINED)
%IRowsetKeys_INTERFACE_DEFINED = 1

$IID_IRowsetKeys = GUID$("{0C733A12-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetKeys $IID_IRowsetKeys

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ListKeys ( _                                  ' VTable offset = 12
     BYREF pcColumns AS DWORD _                         ' __inout DBORDINAL *pcColumns
   , BYREF prgColumns AS DWORD _                        ' __out DBORDINAL **prgColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetKeys_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetWatchAll interface
' IID = 0C733A73-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetWatchAll_INTERFACE_DEFINED)
%IRowsetWatchAll_INTERFACE_DEFINED = 1

$IID_IRowsetWatchAll = GUID$("{0C733A73-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetWatchAll $IID_IRowsetWatchAll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Acknowledge ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopWatching ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetWatchAll_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetWatchNotify interface
' IID = 0C733A44-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetWatchNotify_INTERFACE_DEFINED)
%IRowsetWatchNotify_INTERFACE_DEFINED = 1

'typedef DWORD DBWATCHNOTIFY;

%DBWATCHNOTIFY_ROWSCHANGED     = 1
%DBWATCHNOTIFY_QUERYDONE       = 2
%DBWATCHNOTIFY_QUERYREEXECUTED = 3

$IID_IRowsetWatchNotify = GUID$("{0C733A44-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetWatchNotify $IID_IRowsetWatchNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChange ( _                                  ' VTable offset = 12
     BYVAL pRowset AS IRowset _                         ' __in IRowset *pRowset
   , BYVAL eChangeReason AS DWORD _                     ' __in DBWATCHNOTIFY eChangeReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetWatchNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetWatchRegion interface
' IID = 0C733A45-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IRowsetWatchAll
' ########################################################################################

#IF NOT %DEF(%IRowsetWatchRegion_INTERFACE_DEFINED)
%IRowsetWatchRegion_INTERFACE_DEFINED = 1

'typedef DWORD DBWATCHMODE;

' DBWATCHMODEENUM
%DBWATCHMODE_ALL    = &H1
%DBWATCHMODE_EXTEND = &H2
%DBWATCHMODE_MOVE   = &H4
%DBWATCHMODE_COUNT  = &H8

'typedef DWORD DBROWCHANGEKIND;

' DBROWCHANGEKINDENUM
%DBROWCHANGEKIND_INSERT = 0
%DBROWCHANGEKIND_DELETE = %DBROWCHANGEKIND_INSERT + 1
%DBROWCHANGEKIND_UPDATE = %DBROWCHANGEKIND_DELETE + 1
%DBROWCHANGEKIND_COUNT  = %DBROWCHANGEKIND_UPDATE + 1

' // Size = 16 bytes
TYPE DBROWWATCHCHANGE DWORD
   hRegion     AS DWORD   ' HWATCHREGION
   eChangeKind AS DWORD   ' DBROWCHANGEKIND
   hRow        AS DWORD   ' HROW
   iRow        AS DWORD   ' DBCOUNTITEM
END TYPE

$IID_IRowsetWatchRegion = GUID$("{0C733A45-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetWatchRegion $IID_IRowsetWatchRegion

   INHERIT IUnknown

   ' =====================================================================================
   ' IRowsetWatchAll methods
   ' =====================================================================================
   METHOD Acknowledge ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopWatching ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' IRowsetWatchRegion methods
   ' =====================================================================================
   METHOD CreateWatchRegion ( _                         ' VTable offset = 24
     BYVAL dwWatchMode AS DWORD _                       ' __in DBWATCHMODE dwWatchMode
   , BYREF phRegion AS DWORD _                          ' __out HWATCHREGION *phRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeWatchMode ( _                           ' VTable offset = 28
     BYVAL hRegion AS DWORD _                           ' __in HWATCHREGION hRegion
   , BYVAL dwWatchMode AS DWORD _                       ' __in DBWATCHMODE dwWatchMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteWatchRegion ( _                         ' VTable offset = 32
     BYVAL hRegion AS DWORD _                           ' __in HWATCHREGION hRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWatchRegionInfo ( _                        ' VTable offset = 36
     BYVAL hRegion AS DWORD _                           ' __in HWATCHREGION hRegion
   , BYREF pdwWatchMode AS DWORD _                      ' __out DBWATCHMODE *pdwWatchMode
   , BYREF phChapter AS DWORD _                         ' __out HCHAPTER *phChapter
   , BYREF pcbBookmark AS DWORD _                       ' __inout DBBKMARK *pcbBookmark
   , BYREF ppBookmark AS DWORD _                        ' __out BYTE **ppBookmark
   , BYREF pcRows AS LONG _                             ' __out DBROWCOUNT *pcRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 40
     BYREF pcChangesObtained AS DWORD _                 ' __inout DBCOUNTITEM *pcChangesObtained
   , BYREF prgChanges AS DBROWWATCHCHANGE _             ' __out DBROWWATCHCHANGE **prgChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShrinkWatchRegion ( _                         ' VTable offset = 44
     BYVAL hRegion AS DWORD _                           ' __in HWATCHREGION hRegion
   , BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in BYTE *pBookmark
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetWatchRegion_INTERFACE_DEFINED__ */


' ########################################################################################
' IRowsetCopyRows interface
' IID = 0C733A6B-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetCopyRows_INTERFACE_DEFINED)
%IRowsetCopyRows_INTERFACE_DEFINED = 1

'typedef WORD HSOURCE;

$IID_IRowsetCopyRows = GUID$("{0C733A6B-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IRowsetCopyRows $IID_IRowsetCopyRows

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CloseSource ( _                               ' VTable offset = 12
     BYVAL hSourceID AS DWORD _                         ' __in HSOURCE hSourceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyByHROWS ( _                               ' VTable offset = 16
     BYVAL hSourceID AS DWORD _                         ' __in HSOURCE hSourceID
   , BYVAL hReserved AS DWORD _                         ' __in HCHAPTER hReserved
   , BYVAL cRows AS LONG _                              ' __in DBROWCOUNT cRows
   , BYREF rghRows AS DWORD _                           ' __in const HROW rghRows[  ]
   , BYVAL bFlags AS DWORD _                            ' __in ULONG bFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefineSource ( _                              ' VTable offset = 20
     BYVAL pRowsetSource AS IRowset _                   ' __in const IRowset *pRowsetSource
   , BYVAL cColIds AS DWORD _                           ' __in const DBORDINAL cColIds
   , BYREF rgSourceColumns AS LONG _                    ' __in const DB_LORDINAL rgSourceColumns[  ]
   , BYREF rgTargetColumns AS LONG _                    ' __in const DB_LORDINAL rgTargetColumns[  ]
   , BYREF phSourceID AS DWORD _                        ' __out HSOURCE *phSourceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetCopyRows_INTERFACE_DEFINED__ */


' ########################################################################################
' IReadData interface
' IID = 0C733A6A-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReadData_INTERFACE_DEFINED)
%IReadData_INTERFACE_DEFINED = 1

$IID_IReadData = GUID$("{0C733A6A-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IReadData $IID_IReadData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadData ( _                                  ' VTable offset = 12
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   , BYVAL cbBookmark AS DWORD _                        ' __in DBBKMARK cbBookmark
   , BYVAL pBookmark AS BYTE PTR _                      ' __in const BYTE *pBookmark
   , BYVAL lRowsOffset AS LONG _                        ' __in DBROWOFFSET lRowsOffset
   , BYVAL hAccessor AS DWORD _                         ' __in HACCESSOR hAccessor
   , BYVAL cRows AS DWORD _                             ' __in DBROWCOUNT cRows
   , BYREF pcRowsObtained AS DWORD _                    ' __out DBCOUNTITEM *pcRowsObtained
   , BYREF ppFixedData AS DWORD _                       ' __inout BYTE **ppFixedData
   , BYREF pcbVariableTotal AS DWORD _                  ' __inout DBLENGTH *pcbVariableTotal
   , BYREF ppVariableData AS DWORD _                    ' __inout BYTE **ppVariableData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseChapter ( _                            ' VTable offset = 16
     BYVAL hChapter AS DWORD _                          ' __in HCHAPTER hChapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReadData_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandCost interface
' IID = 0C733A4E-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandCost_INTERFACE_DEFINED)
%ICommandCost_INTERFACE_DEFINED = 1

'typedef DWORD DBRESOURCEKIND;

' DBRESOURCEKINDENUM
%DBRESOURCE_INVALID  = 0
%DBRESOURCE_TOTAL    = 1
%DBRESOURCE_CPU      = 2
%DBRESOURCE_MEMORY   = 3
%DBRESOURCE_DISK     = 4
%DBRESOURCE_NETWORK  = 5
%DBRESOURCE_RESPONSE = 6
%DBRESOURCE_ROWS     = 7
%DBRESOURCE_OTHER    = 8

'typedef DWORD DBCOSTUNIT;

' DBCOSTUNITENUM
%DBUNIT_INVALID      = 0
%DBUNIT_WEIGHT       = &H1
%DBUNIT_PERCENT      = &H2
%DBUNIT_MAXIMUM      = &H4
%DBUNIT_MINIMUM      = &H8
%DBUNIT_MICRO_SECOND = &H10
%DBUNIT_MILLI_SECOND = &H20
%DBUNIT_SECOND       = &H40
%DBUNIT_MINUTE       = &H80
%DBUNIT_HOUR         = &H100
%DBUNIT_BYTE         = &H200
%DBUNIT_KILO_BYTE    = &H400
%DBUNIT_MEGA_BYTE    = &H800
%DBUNIT_GIGA_BYTE    = &H1000
%DBUNIT_NUM_MSGS     = &H2000
%DBUNIT_NUM_LOCKS    = &H4000
%DBUNIT_NUM_ROWS     = &H8000
%DBUNIT_OTHER        = &H10000

' // Size = 12 bytes
TYPE DBCOST DWORD
   eKind   AS DWORD
   dwUnits AS DWORD
   lValue  AS LONG
END TYPE

'typedef DWORD DBEXECLIMITS;

' DBEXECLIMITSENUM
%DBEXECLIMITS_ABORT   = 1
%DBEXECLIMITS_STOP    = 2
%DBEXECLIMITS_SUSPEND = 3

$IID_ICommandCost = GUID$("{0C733A4E-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ICommandCost $IID_ICommandCost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAccumulatedCost ( _                        ' VTable offset = 12
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYREF pcCostLimits AS DWORD _                      ' __inout ULONG *pcCostLimits
   , BYREF prgCostLimits AS DBCOST _                    ' __out DBCOST **prgCostLimits
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCostEstimate ( _                           ' VTable offset = 16
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYREF pcCostEstimates AS DWORD _                   ' __out ULONG *pcCostEstimates
   , BYREF prgCostEstimates AS DBCOST _                 ' __out DBCOST *prgCostEstimates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCostGoals ( _                              ' VTable offset = 20
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYREF pcCostGoals AS DWORD _                       ' __out ULONG *pcCostGoals
   , BYREF prgCostGoals AS DBCOST _                     ' __out DBCOST *prgCostGoals
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCostLimits ( _                             ' VTable offset = 24
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYREF pcCostLimits AS DWORD _                      ' __out ULONG *pcCostLimits
   , BYREF prgCostLimits AS DBCOST _                    ' __out DBCOST *prgCostLimits
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCostGoals ( _                              ' VTable offset = 28
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYVAL cCostGoals AS DWORD _                        ' __in ULONG cCostGoals
   , BYREF rgCostGoals AS DBCOST _                      ' __in const DBCOST rgCostGoals[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCostLimits ( _                             ' VTable offset = 32
     BYREF pwszRowsetName AS WSTRINGZ _                 ' __in LPCOLESTR pwszRowsetName
   , BYVAL cCostLimits AS DWORD _                       ' __in ULONG cCostLimits
   , BYREF prgCostLimits AS DBCOST _                    ' __in DBCOST *prgCostLimits
   , BYVAL dwExecutionFlags AS DWORD _                  ' __in DBEXECLIMITS dwExecutionFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandCost_INTERFACE_DEFINED__ */


' ########################################################################################
' ICommandValidate interface
' IID = 0C733A18-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandValidate_INTERFACE_DEFINED)
%ICommandValidate_INTERFACE_DEFINED = 1

$IID_ICommandValidate = GUID$("{0C733A18-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ICommandValidate $IID_ICommandValidate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ValidateCompletely ( _                        ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateSyntax ( _                            ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandValidate_INTERFACE_DEFINED__ */


' ########################################################################################
' ITableRename interface
' IID = 0C733A77-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITableRename_INTERFACE_DEFINED)
%ITableRename_INTERFACE_DEFINED = 1

$IID_ITableRename = GUID$("{0C733A77-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ITableRename $IID_ITableRename

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RenameColumn ( _                              ' VTable offset = 12
     BYREF pTableId AS DBID _                           ' __in DBID *pTableId
   , BYREF pOldColumnId AS DBID _                       ' __in DBID *pOldColumnId
   , BYREF pNewColumnId AS DBID _                       ' __in DBID *pNewColumnId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameTable ( _                               ' VTable offset = 16
     BYREF pOldTableId AS DBID _                        ' __in DBID *pOldTableId
   , BYREF pOldIndexId AS DBID _                        ' __in DBID *pOldIndexId
   , BYREF pNewTableId AS DBID _                        ' __in DBID *pNewTableId
   , BYREF pNewIndexId AS DBID _                        ' __in DBID *pNewIndexId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITableRename_INTERFACE_DEFINED__ */


' ########################################################################################
' IDBSchemaCommand interface
' IID = 0C733A50-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDBSchemaCommand_INTERFACE_DEFINED)
%IDBSchemaCommand_INTERFACE_DEFINED = 1

$IID_IDBSchemaCommand = GUID$("{0C733A50-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IDBSchemaCommand $IID_IDBSchemaCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCommand ( _                                ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF rguidSchema AS GUID _                        ' __in REFGUID rguidSchema
   , BYREF ppCommand AS ICommand _                      ' __out ICommand **ppCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSchemas ( _                                ' VTable offset = 16
     BYREF pcSchemas AS DWORD _                         ' __inout ULONG *pcSchemas
   , BYREF prgSchemas AS GUID _                         ' __out GUID **prgSchemas
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDBSchemaCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IProvideMoniker interface
' IID = 0C733A4D-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProvideMoniker_INTERFACE_DEFINED)
%IProvideMoniker_INTERFACE_DEFINED = 1

$IID_IProvideMoniker = GUID$("{0C733A4D-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE IProvideMoniker $IID_IProvideMoniker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMoniker ( _                                ' VTable offset = 12
     BYREF ppIMoniker AS IMoniker _                     ' __out IMoniker **ppIMoniker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProvideMoniker_INTERFACE_DEFINED__ */


'// IID_IRowsetExactScroll      = {0x0c733a7f,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetNextRowset       = {0x0c733a72,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetNewRowAfter      = {0x0c733a71,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetWithParameters   = {0x0c733a6e,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetAsynch           = {0x0c733a0f,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetKeys             = {0x0c733a12,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetWatchAll         = {0x0c733a73,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetWatchNotify      = {0x0c733a44,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetWatchRegion      = {0x0c733a45,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IRowsetCopyRows         = {0x0c733a6b,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IReadData               = {0x0c733a6a,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_ICommandCost            = {0x0c733a4e,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_ICommandTree            = {0x0c733a87,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_ICommandValidate        = {0x0c733a18,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IQuery                  = {0x0c733a51,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_ITableRename            = {0x0c733a77,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IDBSchemaCommand        = {0x0c733a50,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}
'// IID_IProvideMoniker         = {0x0c733a4d,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}}

'#include <poppack.h>   // restore original structure packing
