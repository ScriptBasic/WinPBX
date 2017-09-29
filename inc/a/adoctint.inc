' ########################################################################################
' Microsoft Windows
' File: adoctint.inc
' Library name: ADOX
' Contents: Microsoft ADO Ext. 2.8 for DDL and Security
' Version: 2.8, Locale ID = 0
' Library GUID: {00000600-0000-0010-8000-00AA006D2EA4}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADOCTINT_INC = 1

#INCLUDE ONCE "adoint.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {00000602-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXCatalog28 = "ADOX.Catalog.2.8"
' CLSID = {0000061B-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXColumn28 = "ADOX.Column.2.8"
' CLSID = {00000615-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXGroup28 = "ADOX.Group.2.8"
' CLSID = {0000061E-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXIndex28 = "ADOX.Index.2.8"
' CLSID = {00000621-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXKey28 = "ADOX.Key.2.8"
' CLSID = {00000609-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXTable28 = "ADOX.Table.2.8"
' CLSID = {00000618-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXUser28 = "ADOX.User.2.8"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {00000602-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXCatalog = "ADOX.Catalog"
' CLSID = {0000061B-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXColumn = "ADOX.Column"
' CLSID = {00000615-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXGroup = "ADOX.Group"
' CLSID = {0000061E-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXIndex = "ADOX.Index"
' CLSID = {00000621-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXKey = "ADOX.Key"
' CLSID = {00000609-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXTable = "ADOX.Table"
' CLSID = {00000618-0000-0010-8000-00AA006D2EA4}
$PROGID_ADOXUser = "ADOX.User"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ADOXCatalog  = GUID$("{00000602-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXColumn   = GUID$("{0000061B-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXGroup    = GUID$("{00000615-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXIndex    = GUID$("{0000061E-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXKey      = GUID$("{00000621-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXTable    = GUID$("{00000609-0000-0010-8000-00AA006D2EA4}")
$CLSID_ADOXUser     = GUID$("{00000618-0000-0010-8000-00AA006D2EA4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ADOXColumns    = GUID$("{0000061D-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXGroups     = GUID$("{00000617-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXIndexes    = GUID$("{00000620-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXKeys       = GUID$("{00000623-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXProcedure  = GUID$("{00000625-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXProcedures = GUID$("{00000626-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXTables     = GUID$("{00000611-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXUsers      = GUID$("{0000061A-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXView       = GUID$("{00000613-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXViews      = GUID$("{00000614-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXCatalog    = GUID$("{00000603-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXColumn     = GUID$("{0000061C-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXGroup      = GUID$("{00000628-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXGroup25    = GUID$("{00000616-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXIndex      = GUID$("{0000061F-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXKey        = GUID$("{00000622-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXTable      = GUID$("{00000610-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXUser       = GUID$("{00000627-0000-0010-8000-00AA006D2EA4}")
$IID_ADOXUser25     = GUID$("{00000619-0000-0010-8000-00AA006D2EA4}")

' ========================================================================================
' RuleEnum enum
' ========================================================================================

%adRINone                                               = 0
%adRICascade                                            = 1
%adRISetNull                                            = 2
%adRISetDefault                                         = 3

' ========================================================================================
' KeyTypeEnum enum
' ========================================================================================

%adKeyPrimary                                           = 1
%adKeyForeign                                           = 2
%adKeyUnique                                            = 3

' ========================================================================================
' ActionEnum enum
' ========================================================================================

%adAccessGrant                                          = 1
%adAccessSet                                            = 2
%adAccessDeny                                           = 3
%adAccessRevoke                                         = 4

' ========================================================================================
' ColumnAttributesEnum enum
' ========================================================================================

%adColFixed                                             = 1
%adColNullable                                          = 2

' ========================================================================================
' SortOrderEnum enum
' ========================================================================================

%adSortAscending                                        = 1
%adSortDescending                                       = 2

' ========================================================================================
' RightsEnum enum
' ========================================================================================

%adRightNone                                            = 0
%adRightDrop                                            = &H100
%adRightExclusive                                       = &H200
%adRightReadDesign                                      = &H400
%adRightWriteDesign                                     = &H800
%adRightWithGrant                                       = &H1000
%adRightReference                                       = &H2000
%adRightCreate                                          = &H4000
%adRightInsert                                          = &H8000
%adRightDelete                                          = &H10000
%adRightReadPermissions                                 = &H20000
%adRightWritePermissions                                = &H40000
%adRightWriteOwner                                      = &H80000
%adRightMaximumAllowed                                  = &H2000000
%adRightFull                                            = &H10000000
%adRightExecute                                         = &H20000000
%adRightUpdate                                          = &H40000000
%adRightRead                                            = &H80000000

' ========================================================================================
' AllowNullsEnum enum
' ========================================================================================

%adIndexNullsAllow                                      = 0
%adIndexNullsDisallow                                   = 1
%adIndexNullsIgnore                                     = 2
%adIndexNullsIgnoreAny                                  = 4

' ========================================================================================
' ObjectTypeEnum enum
' ========================================================================================

%adPermObjProviderSpecific                              = -1
%adPermObjTable                                         = 1
%adPermObjColumn                                        = 2
%adPermObjDatabase                                      = 3
%adPermObjProcedure                                     = 4
%adPermObjView                                          = 5

' ========================================================================================
' InheritTypeEnum enum
' ========================================================================================

%adInheritNone                                          = 0
%adInheritObjects                                       = 1
%adInheritContainers                                    = 2
%adInheritBoth                                          = 3
%adInheritNoPropogate                                   = 4


#IF NOT %DEF(%ADOX_LIBRARY_DEFINED)
    %ADOX_LIBRARY_DEFINED = 1

' ########################################################################################
' Interface name = _Catalog
' IID = {00000603-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXCatalog_INTERFACE_DEFINED)
    %ADOXCatalog_INTERFACE_DEFINED = 1

INTERFACE ADOXCatalog $IID_ADOXCatalog

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Tables <0> ( _                          ' VTable offset = 28
   ) AS ADOXTables                                      ' __retval_out ADOXTables **ppvObject
   ' =====================================================================================
   PROPERTY GET ActiveConnection <1> ( _                ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET ActiveConnection <1> ( _                ' VTable offset = 36
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ActiveConnection <1> ( _         ' VTable offset = 40
     BYVAL pCon AS IDispatch _                          ' __in IDispatch *pCon
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Procedures <2> ( _                      ' VTable offset = 44
   ) AS ADOXProcedures                                  ' __retval_out ADOXProcedures **ppvObject
   ' =====================================================================================
   PROPERTY GET Views <3> ( _                           ' VTable offset = 48
   ) AS ADOXViews                                       ' __retval_out ADOXViews **ppvObject
   ' =====================================================================================
   PROPERTY GET Groups <4> ( _                          ' VTable offset = 52
   ) AS ADOXGroups                                      ' __retval_out ADOXGroups **ppvObject
   ' =====================================================================================
   PROPERTY GET Users <5> ( _                           ' VTable offset = 56
   ) AS ADOXUsers                                       ' __retval_out ADOXUsers **ppvObject
   ' =====================================================================================
   METHOD Create <6> ( _                                ' VTable offset = 60
     BYVAL ConnectString AS WSTRING _                   ' __in BSTR ConnectString
   ) AS VARIANT                                         ' __retval_out VARIANT *Connection
   ' =====================================================================================
   METHOD GetObjectOwner <7> ( _                        ' VTable offset = 64
     BYVAL ObjectName AS WSTRING _                      ' __in BSTR ObjectName
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   ) AS WSTRING                                         ' __retval_out BSTR *OwnerName
   ' =====================================================================================
   METHOD SetObjectOwner <8> ( _                        ' VTable offset = 68
     BYVAL ObjectName AS WSTRING _                      ' __in BSTR ObjectName
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , BYVAL UserName AS WSTRING _                        ' __in BSTR UserName
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Catalog_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Table
' IID = {00000610-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXTable_INTERFACE_DEFINED)
    %ADOXTable_INTERFACE_DEFINED = 1

INTERFACE ADOXTable $IID_ADOXTable

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Columns <0> ( _                         ' VTable offset = 28
   ) AS ADOXColumns                                     ' __retval_out ADOXColumns **ppvObject
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 36
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Indexes <3> ( _                         ' VTable offset = 44
   ) AS ADOXIndexes                                     ' __retval_out ADOXIndexes **ppvObject
   ' =====================================================================================
   PROPERTY GET Keys <4> ( _                            ' VTable offset = 48
   ) AS ADOXKeys                                        ' __retval_out ADOXKeys **ppvObject
   ' =====================================================================================
   PROPERTY GET Properties <5> ( _                      ' VTable offset = 52
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================
   PROPERTY GET DateCreated <6> ( _                     ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET DateModified <7> ( _                    ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET ParentCatalog <8> ( _                   ' VTable offset = 64
   ) AS ADOXCatalog                                     ' __retval_out _ADOXCatalog **ppvObject
   ' =====================================================================================
   PROPERTY SET ParentCatalog <8> ( _                   ' VTable offset = 68
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ParentCatalog <8> ( _            ' VTable offset = 72
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Table_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Group25
' IID = {00000616-0000-0010-8000-00AA006D2EA4}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXGroup25_INTERFACE_DEFINED)
    %ADOXGroup25_INTERFACE_DEFINED = 1

INTERFACE ADOXGroup25 $IID_ADOXGroup25

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPermissions <2> ( _                        ' VTable offset = 36
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   ) AS LONG                                            ' __retval_out RightsEnum *Rights
   ' =====================================================================================
   METHOD SetPermissions <3> ( _                        ' VTable offset = 40
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , BYVAL Action AS LONG _                             ' __in ActionEnum Action
   , BYVAL Rights AS LONG _                             ' __in RightsEnum Rights
   , OPTIONAL BYVAL Inherit AS LONG _                   ' __opt_in InheritTypeEnum Inherit = adInheritNone
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Users <4> ( _                           ' VTable offset = 44
   ) AS ADOXUsers                                       ' __retval_out ADOXUsers **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Group25_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Group
' IID = {00000628-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Group25
' ########################################################################################

#IF NOT %DEF(%ADOXGroup_INTERFACE_DEFINED)
    %ADOXGroup_INTERFACE_DEFINED = 1

INTERFACE ADOXGroup $IID_ADOXGroup

   INHERIT IDispatch

   ' =====================================================================================
   ' _Group25 Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPermissions <2> ( _                        ' VTable offset = 36
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   ) AS LONG                                            ' __retval_out RightsEnum *Rights
   ' =====================================================================================
   METHOD SetPermissions <3> ( _                        ' VTable offset = 40
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , BYVAL Action AS LONG _                             ' __in ActionEnum Action
   , BYVAL Rights AS LONG _                             ' __in RightsEnum Rights
   , OPTIONAL BYVAL Inherit AS LONG _                   ' __opt_in InheritTypeEnum Inherit = adInheritNone
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Users <4> ( _                           ' VTable offset = 44
   ) AS ADOXUsers                                       ' __retval_out ADOXUsers **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' Group Methods
   ' =====================================================================================
   PROPERTY GET Properties <5> ( _                      ' VTable offset = 48
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================
   PROPERTY GET ParentCatalog <6> ( _                   ' VTable offset = 52
   ) AS ADOXCatalog                                     ' __retval_out _ADOXCatalog **ppvObject
   ' =====================================================================================
   PROPERTY SET ParentCatalog <6> ( _                   ' VTable offset = 56
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ParentCatalog <6> ( _            ' VTable offset = 60
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Group_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _User25
' IID = {00000619-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXUser25_INTERFACE_DEFINED)
    %ADOXUser25_INTERFACE_DEFINED = 1

INTERFACE ADOXUser25 $IID_ADOXUser25

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPermissions <2> ( _                        ' VTable offset = 36
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   ) AS LONG                                            ' __retval_out RightsEnum *Rights
   ' =====================================================================================
   METHOD SetPermissions <3> ( _                        ' VTable offset = 40
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , BYVAL Action AS LONG _                             ' __in ActionEnum Action
   , BYVAL Rights AS LONG _                             ' __in RightsEnum Rights
   , OPTIONAL BYVAL Inherit AS LONG _                   ' __opt_in InheritTypeEnum Inherit = adInheritNone
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangePassword <4> ( _                        ' VTable offset = 44
     BYVAL OldPassword AS WSTRING _                     ' __in BSTR OldPassword
   , BYVAL NewPassword AS WSTRING _                     ' __in BSTR NewPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Groups <5> ( _                          ' VTable offset = 48
   ) AS ADOXGroups                                      ' __retval_out ADOXGroups **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __User25_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _User
' IID = {00000627-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _User25
' ########################################################################################

#IF NOT %DEF(%ADOXUser_INTERFACE_DEFINED)
   %ADOXUser_INTERFACE_DEFINED = 1

INTERFACE ADOXUser $IID_ADOXUser

   INHERIT IDispatch

   ' =====================================================================================
   ' _User25 Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPermissions <2> ( _                        ' VTable offset = 36
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   ) AS LONG                                            ' __retval_out RightsEnum *Rights
   ' =====================================================================================
   METHOD SetPermissions <3> ( _                        ' VTable offset = 40
     BYVAL Name AS VARIANT _                            ' __in VARIANT Name
   , BYVAL ObjectType AS LONG _                         ' __in ObjectTypeEnum ObjectType
   , BYVAL Action AS LONG _                             ' __in ActionEnum Action
   , BYVAL Rights AS LONG _                             ' __in RightsEnum Rights
   , OPTIONAL BYVAL Inherit AS LONG _                   ' __opt_in InheritTypeEnum Inherit = adInheritNone
   , OPTIONAL BYVAL ObjectTypeId AS VARIANT _           ' __opt_in VARIANT ObjectTypeId
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangePassword <4> ( _                        ' VTable offset = 44
     BYVAL OldPassword AS WSTRING _                     ' __in BSTR OldPassword
   , BYVAL NewPassword AS WSTRING _                     ' __in BSTR NewPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Groups <5> ( _                          ' VTable offset = 48
   ) AS ADOXGroups                                      ' __retval_out ADOXGroups **ppvObject
   ' =====================================================================================

   ' =====================================================================================
   ' User Methods
   ' =====================================================================================
   PROPERTY GET Properties <6> ( _                      ' VTable offset = 52
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================
   PROPERTY GET ParentCatalog <7> ( _                   ' VTable offset = 56
   ) AS ADOXCatalog                                     ' __retval_out _ADOXCatalog **ppvObject
   ' =====================================================================================
   PROPERTY SET ParentCatalog <7> ( _                   ' VTable offset = 60
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ParentCatalog <7> ( _            ' VTable offset = 64
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __User_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Column
' IID = {0000061C-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXColumn_INTERFACE_DEFINED)
    %ADOXColumn_INTERFACE_DEFINED = 1

INTERFACE ADOXColumn $IID_ADOXColumn

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Attributes <1> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out ColumnAttributesEnum *pVal
   ' =====================================================================================
   PROPERTY SET Attributes <1> ( _                      ' VTable offset = 40
     BYVAL newVal AS LONG _                             ' __in ColumnAttributesEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefinedSize <3> ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DefinedSize <3> ( _                     ' VTable offset = 48
     BYVAL DefinedSize AS LONG _                        ' __in long DefinedSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NumericScale <4> ( _                    ' VTable offset = 52
   ) AS BYTE                                            ' __retval_out BYTE *pVal
   ' =====================================================================================
   PROPERTY SET NumericScale <4> ( _                    ' VTable offset = 56
     BYVAL newVal AS BYTE _                             ' __in BYTE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <5> ( _                       ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Precision <5> ( _                       ' VTable offset = 64
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RelatedColumn <6> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RelatedColumn <6> ( _                   ' VTable offset = 72
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SortOrder <7> ( _                       ' VTable offset = 76
   ) AS LONG                                            ' __retval_out SortOrderEnum *pVal
   ' =====================================================================================
   PROPERTY SET SortOrder <7> ( _                       ' VTable offset = 80
     BYVAL pVal AS LONG _                               ' __in SortOrderEnum pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <8> ( _                            ' VTable offset = 84
   ) AS LONG                                            ' __retval_out DataTypeEnum *pVal
   ' =====================================================================================
   PROPERTY SET Type <8> ( _                            ' VTable offset = 88
     BYVAL newVal AS LONG _                             ' __in DataTypeEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <9> ( _                      ' VTable offset = 92
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================
   PROPERTY GET ParentCatalog <10> ( _                  ' VTable offset = 96
   ) AS ADOXCatalog                                     ' __retval_out _ADOXCatalog **ppvObject
   ' =====================================================================================
   PROPERTY SET ParentCatalog ( _                       ' VTable offset = 100
     BYVAL ppvObject AS ADOXCatalog _                   ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ParentCatalog ( _                ' VTable offset = 104
     BYVAL ADOXCatalog _                                ' __in _ADOXCatalog *ppvObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Column_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Index
' IID = {0000061F-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXIndex_INTERFACE_DEFINED)
    %ADOXIndex_INTERFACE_DEFINED = 1

INTERFACE ADOXIndex $IID_ADOXIndex

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Clustered <1> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Clustered <1> ( _                       ' VTable offset = 40
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IndexNulls <2> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out AllowNullsEnum *pVal
   ' =====================================================================================
   PROPERTY SET IndexNulls <2> ( _                      ' VTable offset = 48
     BYVAL newVal AS LONG _                             ' __in AllowNullsEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrimaryKey <3> ( _                      ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET PrimaryKey <3> ( _                      ' VTable offset = 56
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Unique <4> ( _                          ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Unique <4> ( _                          ' VTable offset = 64
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Columns <5> ( _                         ' VTable offset = 68
   ) AS ADOXColumns                                     ' __retval_out ADOXColumns **ppvObject
   ' =====================================================================================
   PROPERTY GET Properties <6> ( _                      ' VTable offset = 72
   ) AS ADOProperties                                   ' __retval_out ADOProperties **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Index_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _Key
' IID = {00000622-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXKey_INTERFACE_DEFINED)
    %ADOXKey_INTERFACE_DEFINED = 1

INTERFACE ADOXKey $IID_ADOXKey

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Name <0> ( _                            ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteRule <1> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out RuleEnum *pVal
   ' =====================================================================================
   PROPERTY SET DeleteRule <1> ( _                      ' VTable offset = 40
     BYVAL newVal AS LONG _                             ' __in RuleEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out KeyTypeEnum *pVal
   ' =====================================================================================
   PROPERTY SET Type <2> ( _                            ' VTable offset = 48
     BYVAL newVal AS LONG _                             ' __in KeyTypeEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RelatedTable <3> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RelatedTable <3> ( _                    ' VTable offset = 56
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateRule <4> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out RuleEnum *pVal
   ' =====================================================================================
   PROPERTY SET UpdateRule <4> ( _                      ' VTable offset = 64
     BYVAL newVal AS LONG _                             ' __in RuleEnum newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Columns <5> ( _                         ' VTable offset = 68
   ) AS ADOXColumns                                     ' __retval_out ADOXColumns **ppvObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Key_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = View
' IID = {00000613-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXView_INTERFACE_DEFINED)
    %ADOXView_INTERFACE_DEFINED = 1

INTERFACE ADOXView $IID_ADOXView

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Command <0> ( _                         ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET Command <0> ( _                         ' VTable offset = 32
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Command <0> ( _                  ' VTable offset = 36
     BYVAL pComm AS IDispatch _                         ' __in IDispatch *pComm
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DateCreated <2> ( _                     ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET DateModified <3> ( _                    ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __View_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Procedure
' IID = {00000625-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ADOXProcedure_INTERFACE_DEFINED)
    %ADOXProcedure_INTERFACE_DEFINED = 1

INTERFACE ADOXProcedure $IID_ADOXProcedure

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Command <0> ( _                         ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pVar
   ' =====================================================================================
   PROPERTY SET Command <0> ( _                         ' VTable offset = 32
     BYVAL newVal AS VARIANT _                          ' __in VARIANT newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Command <0> ( _                  ' VTable offset = 36
     BYVAL pComm AS IDispatch _                         ' __in IDispatch *pComm
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DateCreated <2> ( _                     ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET DateModified <3> ( _                    ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Procedure_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Tables
' IID = {00000611-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXTables_INTERFACE_DEFINED)
    %ADOXTables_INTERFACE_DEFINED = 1

INTERFACE ADOXTables $IID_ADOXTables

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Tables Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXTable                                       ' __retval_out ADOXTable **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Tables_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Columns
' IID = {0000061D-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXColumns_INTERFACE_DEFINED)
    %ADOXColumns_INTERFACE_DEFINED = 1

INTERFACE ADOXColumns $IID_ADOXColumns

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c)
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Columns Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXColumn                                      ' __retval_out ADOXColumn **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   , OPTIONAL BYVAL Type AS LONG _                      ' __opt_in DataTypeEnum Type = adVarWChar
   , OPTIONAL BYVAL DefinedSize AS LONG _               ' __opt_in long DefinedSize = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Columns_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Procedures
' IID = {00000626-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXProcedures_INTERFACE_DEFINED)
    %ADOXProcedures_INTERFACE_DEFINED = 1

INTERFACE ADOXProcedures $IID_ADOXProcedures

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Procedures Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXProcedure                                   ' __retval_out ADOXProcedure **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Command AS IDispatch _                       ' __in IDispatch *Command
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Procedures_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Views
' IID = {00000614-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXViews_INTERFACE_DEFINED)
    %ADOXViews_INTERFACE_DEFINED = 1

INTERFACE ADOXViews $IID_ADOXViews

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Views Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXView                                        ' __retval_out ADOXView **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Command AS IDispatch _                       ' __in IDispatch *Command
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL VARIANT _                                    ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Views_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Indexes
' IID = {00000620-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXIndexes_INTERFACE_DEFINED)
    %ADOXIndexes_INTERFACE_DEFINED = 1

INTERFACE ADOXIndexes $IID_ADOXIndexes

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Indexes Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXIndex                                       ' __retval_out ADOXIndex **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   , OPTIONAL BYVAL columns AS VARIANT _                ' __opt_in VARIANT columns
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Indexes_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Keys
' IID = {00000623-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXKeys_INTERFACE_DEFINED)
    %ADOXKeys_INTERFACE_DEFINED = 1

INTERFACE ADOXKeys $IID_ADOXKeys

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Keys Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXKey                                         ' __retval_out ADOXKey **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   , OPTIONAL BYVAL KeyTypeEnum AS LONG _               ' __opt_in KeyTypeEnum Type = adKeyPrimary
   , OPTIONAL BYVAL Column AS VARIANT _                 ' __opt_in VARIANT Column
   , OPTIONAL BYVAL RelatedADOTable AS WSTRING _        ' __opt_in BSTR RelatedADOTable = L""
   , OPTIONAL BYVAL RelatedADOColumn AS WSTRING _       ' __opt_in BSTR RelatedADOColumn = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Keys_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Users
' IID = {0000061A-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXUsers_INTERFACE_DEFINED)
    %ADOXUsers_INTERFACE_DEFINED = 1

INTERFACE ADOXUsers $IID_ADOXUsers

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Users Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXUser                                        ' __retval_out ADOXUser **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   , OPTIONAL BYVAL Password AS WSTRING _               ' __opt_in BSTR Password = L""
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Users_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = Groups
' IID = {00000617-0000-0010-8000-00AA006D2EA4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = _Collection
' ########################################################################################

#IF NOT %DEF(%ADOXGroups_INTERFACE_DEFINED)
    %ADOXGroups_INTERFACE_DEFINED = 1

INTERFACE ADOXGroups $IID_ADOXGroups

   INHERIT IDispatch

   ' =====================================================================================
   ' _Collection Methods
   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *c
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppvObject
   ' =====================================================================================
   METHOD Refresh <1610743810> ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' Groups Methods
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   ) AS ADOXGroup                                       ' __retval_out ADOXGroup **ppvObject
   ' =====================================================================================
   METHOD Append <1610809345> ( _                       ' VTable offset = 44
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610809346> ( _                       ' VTable offset = 48
     BYVAL Item AS VARIANT _                            ' __in VARIANT Item
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __Groups_INTERFACE_DEFINED__ */

#ENDIF   ' #IF NOT %DEF(%ADOX_LIBRARY_DEFINED)
