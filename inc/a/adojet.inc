' ########################################################################################
' Microsoft Windows
' File: adojet.inc
' Library name: JRO
' Contents: Microsoft Jet and Replication Objects 2.6 Library
' Version: 2.6, Locale ID = 0
' Path: C:\Archivos de programa\Archivos comunes\System\ado\msjro.dll
' Library GUID: {AC3B8B4C-B6CA-11D1-9F31-00C04FC29D52}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADOJET_INC = 1

#INCLUDE ONCE "adoint.inc"

%TARGET_IS_NT40_OR_LATER = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {DE88C160-FF2C-11D1-BB6F-00C04FAE22DA}
$PROGID_JROJetEngine26 = "JRO.JetEngine.2.6"
' CLSID = {D2D139E3-B6CA-11D1-9F31-00C04FC29D52}
$PROGID_JROReplica26 = "JRO.Replica.2.6"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {DE88C160-FF2C-11D1-BB6F-00C04FAE22DA}
$PROGID_JROJetEngine = "JRO.JetEngine"
' CLSID = {D2D139E3-B6CA-11D1-9F31-00C04FC29D52}
$PROGID_JROReplica = "JRO.Replica"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_JROJetEngine = GUID$("{DE88C160-FF2C-11D1-BB6F-00C04FAE22DA}")
$CLSID_JROReplica   = GUID$("{D2D139E3-B6CA-11D1-9F31-00C04FC29D52}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_JROFilter      = GUID$("{D2D139E1-B6CA-11D1-9F31-00C04FC29D52}")
$IID_JROFilters     = GUID$("{D2D139E2-B6CA-11D1-9F31-00C04FC29D52}")
$IID_JROIJetEngine  = GUID$("{9F63D980-FF25-11D1-BB6F-00C04FAE22DA}")
$IID_JROIReplica    = GUID$("{D2D139E0-B6CA-11D1-9F31-00C04FC29D52}")

#IF NOT %DEF(%JRO_LIBRARY_DEFINED)
    %JRO_LIBRARY_DEFINED = 1

' ========================================================================================
' ReplicaTypeEnum enum
' IID: {D2D139DF-B6CA-11D1-9F31-00C04FC29D52}
' ========================================================================================

%jrRepTypeNotReplicable                                 = 0
%jrRepTypeDesignMaster                                  = &H1
%jrRepTypeFull                                          = &H2
%jrRepTypePartial                                       = &H3

' ========================================================================================
' VisibilityEnum enum
' IID: {6877D21A-B6CE-11D1-9F31-00C04FC29D52}
' ========================================================================================

%jrRepVisibilityGlobal                                  = &H1
%jrRepVisibilityLocal                                   = &H2
%jrRepVisibilityAnon                                    = &H4

' ========================================================================================
' UpdatabilityEnum enum
' IID: {B42FBFF6-B6CF-11D1-9F31-00C04FC29D52}
' ========================================================================================

%jrRepUpdFull                                           = 0
%jrRepUpdReadOnly                                       = &H2

' ========================================================================================
' SyncTypeEnum enum
' IID: {60C05416-B6D0-11D1-9F31-00C04FC29D52}
' ========================================================================================

%jrSyncTypeExport                                       = &H1
%jrSyncTypeImport                                       = &H2
%jrSyncTypeImpExp                                       = &H3

' ========================================================================================
' SyncModeEnum enum
' IID: {5EBA3970-061E-11D2-BB77-00C04FAE22DA}
' ========================================================================================

%jrSyncModeIndirect                                     = &H1
%jrSyncModeDirect                                       = &H2
%jrSyncModeInternet                                     = &H3

' ========================================================================================
' FilterTypeEnum enum
' IID: {72769F94-BF78-11D1-AC4D-00C04FC29F8F}
' ========================================================================================

%jrFilterTypeTable                                      = &H1
%jrFilterTypeRelationship                               = &H2


' ########################################################################################
' Interface name = IReplica
' IID = {D2D139E0-B6CA-11D1-9F31-00C04FC29D52}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%JROIReplica_INTERFACE_DEFINED)
    %JROIReplica_INTERFACE_DEFINED = 1

INTERFACE JROIReplica $IID_JROIReplica

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1610743808> ( _ ' VTable offset = 28
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1610743808> ( _       ' VTable offset = 32
     BYVAL vConn AS VARIANT _                           ' __in VARIANT vConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1610743808> ( _       ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppconn
   ' =====================================================================================
   PROPERTY GET ConflictFunction <1610743811> ( _       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET ConflictFunction <1610743811> ( _       ' VTable offset = 44
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConflictTables <1610743813> ( _         ' VTable offset = 48
   ) AS ADORecordset                                    ' __retval_out _Recordset **pprset
   ' =====================================================================================
   PROPERTY GET DesignMasterId <1610743814> ( _         ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET DesignMasterId <1610743814> ( _         ' VTable offset = 56
     BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <1610743816> ( _               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET ReplicaId <1610743817> ( _              ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY GET ReplicaType <1610743818> ( _            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out ReplicaTypeEnum *pl
   ' =====================================================================================
   PROPERTY GET RetentionPeriod <1610743819> ( _        ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET RetentionPeriod <1610743819> ( _        ' VTable offset = 76
     BYVAL l AS LONG _                                  ' __in long l
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visibility <1610743821> ( _             ' VTable offset = 80
   ) AS LONG                                            ' __retval_out VisibilityEnum *pl
   ' =====================================================================================
   METHOD CreateReplica <1610743822> ( _                ' VTable offset = 84
     BYVAL replicaName AS WSTRING _                     ' __in BSTR replicaName
   , BYVAL description AS WSTRING _                     ' __in BSTR description
   , OPTIONAL BYVAL replicaType AS LONG _               ' __opt_in ReplicaTypeEnum replicaType = jrRepTypeFull
   , OPTIONAL BYVAL visibility AS LONG _                ' __opt_in VisibilityEnum visibility = jrRepVisibilityGlobal
   , OPTIONAL BYVAL priority AS LONG _                  ' __opt_in long priority = -1
   , OPTIONAL BYVAL updatability AS LONG _              ' __opt_in UpdatabilityEnum updatability = jrRepUpdFull
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectReplicability <1610743823> ( _       ' VTable offset = 88
     BYVAL objectName AS WSTRING _                      ' __in BSTR objectName
   , BYVAL objectType AS WSTRING _                      ' __in BSTR objectType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *replicability
   ' =====================================================================================
   METHOD SetObjectReplicability <1610743824> ( _       ' VTable offset = 92
     BYVAL objectName AS WSTRING _                      ' __in BSTR objectName
   , BYVAL objectType AS WSTRING _                      ' __in BSTR objectType
   , BYVAL replicability AS INTEGER _                   ' __in VARIANT_BOOL replicability
   )                                                    ' void
   ' =====================================================================================
   METHOD MakeReplicable <1610743825> ( _               ' VTable offset = 96
     OPTIONAL BYVAL connectionString AS WSTRING _       ' __opt_in BSTR connectionString = L""
   , OPTIONAL BYVAL columnTracking AS INTEGER _         ' __opt_in VARIANT_BOOL columnTracking = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD PopulatePartial <1610743826> ( _              ' VTable offset = 100
     BYVAL FullReplica AS WSTRING _                     ' __in BSTR FullReplica
   )                                                    ' void
   ' =====================================================================================
   METHOD Synchronize <1610743827> ( _                  ' VTable offset = 104
     BYVAL target AS WSTRING _                          ' __in BSTR target
   , OPTIONAL BYVAL syncType AS LONG _                  ' __opt_in SyncTypeEnum syncType = jrSyncTypeImpExp
   , OPTIONAL BYVAL syncMode AS LONG _                  ' __opt_in SyncModeEnum syncMode = jrSyncModeIndirect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Filters <1610743828> ( _                ' VTable offset = 108
   ) AS JROFilters                                      ' __retval_out Filters **ppFilters
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReplica_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Filter
' IID = {D2D139E1-B6CA-11D1-9F31-00C04FC29D52}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%JROFilter_INTERFACE_DEFINED)
    %JROFilter_INTERFACE_DEFINED = 1

INTERFACE JROFilter $IID_JROFilter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET TableName <1610743808> ( _              ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET FilterType <1610743809> ( _             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out FilterTypeEnum *ptype
   ' =====================================================================================
   PROPERTY GET FilterCriteria <1610743810> ( _         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Filter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Filters
' IID = {D2D139E2-B6CA-11D1-9F31-00C04FC29D52}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%JROFilters_INTERFACE_DEFINED)
    %JROFilters_INTERFACE_DEFINED = 1

INTERFACE JROFilters $IID_JROFilters

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Refresh <1610743808> ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   PROPERTY GET Count <1610743810> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS JROFilter                                       ' __retval_out Filter **ppvObject
   ' =====================================================================================
   METHOD Append <1610743812> ( _                       ' VTable offset = 44
     BYVAL tableName AS WSTRING _                       ' __in BSTR tableName
   , BYVAL filterType AS LONG _                         ' __in FilterTypeEnum filterType
   , BYVAL filterCriteria AS WSTRING _                  ' __in BSTR filterCriteria
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743813> ( _                       ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Filters_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IJetEngine
' IID = {9F63D980-FF25-11D1-BB6F-00C04FAE22DA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%JROIJetEngine_INTERFACE_DEFINED)
    %JROIJetEngine_INTERFACE_DEFINED = 1

INTERFACE JROIJetEngine $IID_JROIJetEngine

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CompactDatabase <1610743808> ( _              ' VTable offset = 28
     BYVAL SourceConnection AS WSTRING _                ' __in BSTR SourceConnection
   , BYVAL Destconnection AS WSTRING _                  ' __in BSTR Destconnection
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshCache <1610743809> ( _                 ' VTable offset = 32
     BYVAL Connection AS ADOCOnnection _                ' __in _Connection *Connection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IJetEngine_INTERFACE_DEFINED__ */

#ENDIF   ' __JRO_LIBRARY_DEFINED__
