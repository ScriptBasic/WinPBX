' ########################################################################################
' Microsoft Windows
' File: adomd.inc
' Library name: ADOMD
' Contents: Microsoft ActiveX Data Objects (Multi-dimensional) 2.8 Library
' Version: 2.8, Locale ID = 0
' Library GUID: {22813728-8BD3-11D0-B4EF-00A0C9138CA4}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADOMD_INC = 1

#INCLUDE ONCE "adoint.inc"

%TARGET_IS_NT40_OR_LATER = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {228136B0-8BD3-11D0-B4EF-00A0C9138CA4}
$PROGID_ADOMDCatalog27 = "ADOMD.Catalog.2.7"
' CLSID = {228136B8-8BD3-11D0-B4EF-00A0C9138CA4}
$PROGID_ADOMDCellset27 = "ADOMD.Cellset.2.7"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {228136B0-8BD3-11D0-B4EF-00A0C9138CA4}
$PROGID_ADOMDCatalog = "ADOMD.Catalog"
' CLSID = {228136B8-8BD3-11D0-B4EF-00A0C9138CA4}
$PROGID_ADOMDCellset = "ADOMD.Cellset"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ADOMDCatalog   = GUID$("{228136B0-8BD3-11D0-B4EF-00A0C9138CA4}")
$CLSID_ADOMDCellset   = GUID$("{228136B8-8BD3-11D0-B4EF-00A0C9138CA4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ADOMDAxes        = GUID$("{22813759-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDAxis        = GUID$("{22813732-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDCell        = GUID$("{2281372E-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDCubeDef     = GUID$("{DA16A34A-7B7A-46FD-AD9D-66DF1E699FA1}")
$IID_ADOMDCubeDef25   = GUID$("{2281373E-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDCubeDefs    = GUID$("{2281375D-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDDimension   = GUID$("{22813742-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDDimensions  = GUID$("{2281375C-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDHierarchies = GUID$("{2281375B-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDHierarchy   = GUID$("{22813746-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDICatalog    = GUID$("{228136B1-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDICellset    = GUID$("{2281372A-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDLevel       = GUID$("{2281373A-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDLevels      = GUID$("{22813758-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDCollection  = GUID$("{22813751-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDMember      = GUID$("{22813736-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDMembers     = GUID$("{22813757-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDPosition    = GUID$("{22813734-8BD3-11D0-B4EF-00A0C9138CA4}")
$IID_ADOMDPositions   = GUID$("{2281375A-8BD3-11D0-B4EF-00A0C9138CA4}")

' ========================================================================================
' MemberTypeEnum enum
' IID: {000002AE-0000-0010-8000-00AA006D2EA4}
' ========================================================================================

%adMemberUnknown                                        = 0
%adMemberRegular                                        = &H1
%adMemberAll                                            = &H2
%adMemberMeasure                                        = &H3
%adMemberFormula                                        = &H4

' ========================================================================================
' SchemaObjectTypeEnum enum
' IID: {C23BBD43-E494-4D00-B4D1-6C9A2CE17CE3}
' ========================================================================================

%adObjectTypeDimension                                  = 1
%adObjectTypeHierarchy                                  = 2
%adObjectTypeLevel                                      = 3
%adObjectTypeMember                                     = 4

' ########################################################################################
' Interface name = ICatalog
' IID = {228136B1-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDICatalog_INTERFACE_DEFINED)
    %ADOMDICatalog_INTERFACE_DEFINED = 1

INTERFACE ADOMDICatalog $IID_ADOMDICatalog

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1610743809> ( _ ' VTable offset = 32
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1610743809> ( _       ' VTable offset = 36
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1610743809> ( _       ' VTable offset = 40
   ) AS IDispatch                                       ' __retval_out IDispatch **ppConn
   ' =====================================================================================
   PROPERTY GET CubeDefs <0> ( _                        ' VTable offset = 44
   ) AS ADOMDCubeDefs                                   ' __retval_out CubeDefs **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICatalog_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICellset
' IID = {2281372A-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDICellset_INTERFACE_DEFINED)
    %ADOMDICellset_INTERFACE_DEFINED = 1

INTERFACE ADOMDICellset $IID_ADOMDICellset

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN idx AS DWORD _                            ' __in SAFEARRAY **idx
   ) AS ADOMDCell                                       ' __retval_out Cell **ppvObject
   ' =====================================================================================
   METHOD Open <1610743809> ( _                         ' VTable offset = 32
     OPTIONAL BYVAL DataSource AS VARIANT _             ' __opt_in VARIANT DataSource
   , OPTIONAL BYVAL ActiveConnection AS VARIANT _       ' __opt_in VARIANT ActiveConnection
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1610743810> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Source <1610743811> ( _          ' VTable offset = 40
     BYVAL pcmd AS IDispatch _                          ' __in IDispatch *pcmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Source <1610743811> ( _                 ' VTable offset = 44
     BYVAL bstrCmd AS WSTRING _                         ' __in BSTR bstrCmd
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source <1610743811> ( _                 ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvSource>
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1610743814> ( _ ' VTable offset = 52
     BYVAL pconn AS IDispatch _                         ' __in IDispatch *pconn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1610743814> ( _       ' VTable offset = 56
     BYVAL bstrConn AS WSTRING _                        ' __in BSTR bstrConn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1610743814> ( _       ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **ppConn
   ' =====================================================================================
   PROPERTY GET State <1610743817> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *plState
   ' =====================================================================================
   PROPERTY GET Axes <1610743818> ( _                   ' VTable offset = 68
   ) AS ADOMDAxes                                       ' __retval_out Axes **ppvObject
   ' =====================================================================================
   PROPERTY GET FilterAxis <1610743819> ( _             ' VTable offset = 72
   ) AS ADOMDAxis                                       ' __retval_out Axis **ppvObject
   ' =====================================================================================
   PROPERTY GET Properties <1610743820> ( _             ' VTable offset = 76
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICellset_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Cell
' IID = {2281372E-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDCell_INTERFACE_DEFINED)
    %ADOMDCell_INTERFACE_DEFINED = 1

INTERFACE ADOMDCell $IID_ADOMDCell

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Positions <1610743810> ( _              ' VTable offset = 36
   ) AS ADOMDPositions                                  ' __retval_out Positions **ppvObject
   ' =====================================================================================
   PROPERTY GET Properties <1610743811> ( _             ' VTable offset = 40
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET FormattedValue <1610743812> ( _         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET FormattedValue <1610743812> ( _         ' VTable offset = 48
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ordinal <1610743814> ( _                ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Cell_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Axis
' IID = {22813732-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDAxis_INTERFACE_DEFINED)
    %ADOMDAxis_INTERFACE_DEFINED = 1

INTERFACE ADOMDAxis $IID_ADOMDAxis

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET DimensionCount <1610743809> ( _         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET Positions <0> ( _                       ' VTable offset = 36
   ) AS ADOMDPositions                                  ' __retval_out Positions **ppvObject
   ' =====================================================================================
   PROPERTY GET Properties <1610743811> ( _             ' VTable offset = 40
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Axis_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Position
' IID = {22813734-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDPosition_INTERFACE_DEFINED)
    %ADOMDPosition_INTERFACE_DEFINED = 1

INTERFACE ADOMDPosition $IID_ADOMDPosition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Ordinal <1610743808> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET Members <0> ( _                         ' VTable offset = 32
   ) AS ADOMDMembers                                    ' __retval_out Members **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Position_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Member
' IID = {22813736-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDMember_INTERFACE_DEFINED)
    %ADOMDMember_INTERFACE_DEFINED = 1

INTERFACE ADOMDMember $IID_ADOMDMember

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET UniqueName <1610743809> ( _             ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Caption <0> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Parent <1610743812> ( _                 ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out Member **ppvObject
   ' =====================================================================================
   PROPERTY GET LevelDepth <1610743813> ( _             ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET LevelName <1610743814> ( _              ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Properties <1610743815> ( _             ' VTable offset = 56
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Type <1610743816> ( _                   ' VTable offset = 60
   ) AS LONG                                            ' __retval_out MemberTypeEnum *ptype
   ' =====================================================================================
   PROPERTY GET ChildCount <1610743817> ( _             ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY GET DrilledDown <1610743818> ( _            ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pf
   ' =====================================================================================
   PROPERTY GET ParentSameAsPrev <1610743819> ( _       ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pf
   ' =====================================================================================
   PROPERTY GET Children <1610743820> ( _               ' VTable offset = 76
   ) AS ADOMDMembers                                    ' __retval_out Members **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Member_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Level
' IID = {2281373A-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDLevel_INTERFACE_DEFINED)
    %ADOMDLevel_INTERFACE_DEFINED = 1

INTERFACE ADOMDLevel $IID_ADOMDLevel

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET UniqueName <1610743809> ( _             ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Caption <1610743810> ( _                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743811> ( _            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Depth <1610743812> ( _                  ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *pw
   ' =====================================================================================
   PROPERTY GET Properties <1610743813> ( _             ' VTable offset = 48
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Members <0> ( _                         ' VTable offset = 52
   ) AS ADOMDMembers                                    ' __retval_out Members **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Level_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = CubeDef25
' IID = {2281373E-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDCubeDef25_INTERFACE_DEFINED)
    %ADOMDCubeDef25_INTERFACE_DEFINED = 1

INTERFACE ADOMDCubeDef25 $IID_ADOMDCubeDef25

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Properties <1610743810> ( _             ' VTable offset = 36
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Dimensions <0> ( _                      ' VTable offset = 40
   ) AS ADOMDDimensions                                 ' __retval_out Dimensions **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF  '  /* __CubeDef25_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = CubeDef
' IID = {DA16A34A-7B7A-46FD-AD9D-66DF1E699FA1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = CubeDef25
' ########################################################################################

#IF NOT %DEF(%ADOMDCubeDef_INTERFACE_DEFINED)
    %ADOMDCubeDef_INTERFACE_DEFINED = 1

INTERFACE ADOMDCubeDef $IID_ADOMDCubeDef

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743809> ( _            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Properties <1610743810> ( _             ' VTable offset = 36
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Dimensions <0> ( _                      ' VTable offset = 40
   ) AS ADOMDDimensions                                 ' __retval_out Dimensions **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' CubeDef Methods
   ' =====================================================================================
   METHOD GetSchemaObject <1610809344> ( _              ' VTable offset = 44
     BYVAL eObjType AS LONG _                           ' __in SchemaObjectTypeEnum eObjType
   , BYVAL bsUniqueName AS WSTRING _                    ' __in BSTR bsUniqueName
   ) AS IDispatch                                       ' __retval_out IDispatch **ppObj
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CubeDef_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Dimension
' IID = {22813742-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDDimension_INTERFACE_DEFINED)
    %ADOMDDimension_INTERFACE_DEFINED = 1

INTERFACE ADOMDDimension $IID_ADOMDDimension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET UniqueName <1610743809> ( _             ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Properties <1610743811> ( _             ' VTable offset = 40
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Hierarchies <0> ( _                     ' VTable offset = 44
   ) AS ADOMDHierarchies                                ' __retval_out Hierarchies **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Dimension_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Hierarchy
' IID = {22813746-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDHierarchy_INTERFACE_DEFINED)
    %ADOMDHierarchy_INTERFACE_DEFINED = 1

INTERFACE ADOMDHierarchy $IID_ADOMDHierarchy

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET UniqueName <1610743809> ( _             ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610743810> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Properties <1610743811> ( _             ' VTable offset = 40
   ) AS ADOProperties                                   ' __retval_out Properties **ppvObject
   ' =====================================================================================
   PROPERTY GET Levels <0> ( _                          ' VTable offset = 44
   ) AS ADOMDLevels                                     ' __retval_out Levels **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Hierarchy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = MD_Collection
' IID = {22813751-8BD3-11D0-B4EF-00A0C9138CA4}
' Collection Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOMDCollection_INTERFACE_DEFINED)
    %ADOMDCollection_INTERFACE_DEFINED = 1

INTERFACE ADOMDCollection $IID_ADOMDCollection

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

END INTERFACE

#ENDIF   ' /* __MD_Collection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Members
' IID = {22813757-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDMembers_INTERFACE_DEFINED)
    %ADOMDMembers_INTERFACE_DEFINED = 1

INTERFACE ADOMDMembers $IID_ADOMDMembers

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Members Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDMember                                     ' __retval_out Member **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Members_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Levels
' IID = {22813758-8BD3-11D0-B4EF-00A0C9138CA4}
' Levels collection
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDLevels_INTERFACE_DEFINED)
    %ADOMDLevels_INTERFACE_DEFINED = 1

INTERFACE ADOMDLevels $IID_ADOMDLevels

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Levels Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDLevel                                      ' __retval_out Level **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Levels_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Axes
' IID = {22813759-8BD3-11D0-B4EF-00A0C9138CA4}
' Axes collection
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDAxes_INTERFACE_DEFINED)
    %ADOMDAxes_INTERFACE_DEFINED = 1

INTERFACE ADOMDAxes $IID_ADOMDAxes

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Axes Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDAxis                                       ' __retval_out Axis **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Axes_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Positions
' IID = {2281375A-8BD3-11D0-B4EF-00A0C9138CA4}
' Positions collection
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDPositions_INTERFACE_DEFINED)
    %ADOMDPositions_INTERFACE_DEFINED = 1

INTERFACE ADOMDPositions $IID_ADOMDPositions

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Positions Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDPosition                                   ' __retval_out Position **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Positions_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Hierarchies
' IID = {2281375B-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%Hierarchies_INTERFACE_DEFINED)
    %Hierarchies_INTERFACE_DEFINED = 1

INTERFACE ADOMDHierarchies $IID_ADOMDHierarchies

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Hierarchies Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDHierarchy                                  ' __retval_out Hierarchy **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Hierarchies_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Dimensions
' IID = {2281375C-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDDimensions_INTERFACE_DEFINED)
    %ADOMDDimensions_INTERFACE_DEFINED = 1

INTERFACE ADOMDDimensions $IID_ADOMDDimensions

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
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

   ' =====================================================================================
   ' Dimensions Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDDimension                                  ' __retval_out Dimension **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Dimensions_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = CubeDefs
' IID = {2281375D-8BD3-11D0-B4EF-00A0C9138CA4}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = MD_Collection
' ########################################################################################

#IF NOT %DEF(%ADOMDCubeDefs_INTERFACE_DEFINED)
    %ADOMDCubeDefs_INTERFACE_DEFINED = 1

INTERFACE ADOMDCubeDefs $IID_ADOMDCubeDefs

   INHERIT IDispatch

   ' =====================================================================================
   ' MD_Collection Methods
   ' =====================================================================================
   METHOD Refresh <1610743808> ( _                      ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ ( _                                  ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   PROPERTY GET Count <1610743810> ( _                  ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================

   ' =====================================================================================
   ' CubeDefs Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS ADOMDCubeDef                                    ' __retval_out CubeDef **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __CubeDefs_INTERFACE_DEFINED__ */
