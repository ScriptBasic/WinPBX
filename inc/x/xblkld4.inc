' ########################################################################################
' Microsoft Windows
' File: xblkld4.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SQLXMLBULKLOADLib
' Version: 4.0, Locale ID = 0
' Description: Microsoft SQLXML BulkLoad 4.0 Type Library
' Documentation string: Microsoft XML BulkLoad for SQL Server 4.0 Type Library
' Path: C:\Archivos de programa\Archivos comunes\System\Ole DB\xblkld4.dll
' Library GUID: {FDCA4B6C-605A-4B76-ADCE-68010C4A2581}
' ########################################################################################

#INCLUDE THIS ONCE
%XBLKLD4_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {1DB51355-B2CA-43CB-B045-1FAA42A724B2}
$PROGID_SQLXMLBulkLoad40 = "SQLXMLBulkLoad.SQLXMLBulkLoad.4.0"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {19AA7334-069C-437F-BFE4-CC9894DB8504}
$PROGID_SQLXMLBulkLoad = "SQLXMLBulkLoad.SQLXMLBulkLoad"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SQLXMLBulkLoad = GUID$("{1DB51355-B2CA-43CB-B045-1FAA42A724B2}")
$CLSID_SQLXMLBulkLoad4 = GUID$("{19AA7334-069C-437F-BFE4-CC9894DB8504}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISQLXMLBulkLoad = GUID$("{1380DD8D-DCB9-4A6E-9D53-EECDDF18DA85}")
$IID_ISQLXMLBulkLoad4 = GUID$("{88465BA7-AEEE-49A1-9499-4416287A0160}")

' ########################################################################################
' Interface name = ISQLXMLBulkLoad4
' IID = {88465BA7-AEEE-49A1-9499-4416287A0160}
' ISQLXMLBulkLoad4 Interface
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = ISQLXMLBulkLoad
' ########################################################################################

#IF NOT %DEF(%ISQLXMLBulkLoad4_INTERFACE_DEFINED)
    %ISQLXMLBulkLoad4_INTERFACE_DEFINED = 1

INTERFACE ISQLXMLBulkLoad4 $IID_ISQLXMLBulkLoad4

   INHERIT IDispatch

   ' =====================================================================================
   ' ISQLXMLBulkLoad Methods
   ' =====================================================================================
   PROPERTY GET ConnectionString <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrConnectionString
   ' =====================================================================================
   PROPERTY SET ConnectionString <1> ( _                ' VTable offset = 32
     BYVAL pbstrConnectionString AS WSTRING _           ' __in BSTR pbstrConnectionString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionCommand <2> ( _               ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppICommand
   ' =====================================================================================
   PROPERTY SET ConnectionCommand <2> ( _               ' VTable offset = 40
     BYVAL ppICommand AS IUnknown _                     ' __in IUnknown* ppICommand
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeepNulls <3> ( _                       ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfKeepNulls
   ' =====================================================================================
   PROPERTY SET KeepNulls <3> ( _                       ' VTable offset = 48
     BYVAL pfKeepNulls AS INTEGER _                     ' __in VARIANT_BOOL pfKeepNulls
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeepIdentity <4> ( _                    ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfKeepIdentity
   ' =====================================================================================
   PROPERTY SET KeepIdentity <4> ( _                    ' VTable offset = 56
     BYVAL pfKeepIdentity AS INTEGER _                  ' __in VARIANT_BOOL pfKeepIdentity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckConstraints <5> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfCheckConstraints
   ' =====================================================================================
   PROPERTY SET CheckConstraints <5> ( _                ' VTable offset = 64
     BYVAL pfCheckConstraints AS INTEGER _              ' __in VARIANT_BOOL pfCheckConstraints
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForceTableLock <6> ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfForceTableLock
   ' =====================================================================================
   PROPERTY SET ForceTableLock <6> ( _                  ' VTable offset = 72
     BYVAL pfForceTableLock AS INTEGER _                ' __in VARIANT_BOOL pfForceTableLock
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET XMLFragment <7> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfXMLFragment
   ' =====================================================================================
   PROPERTY SET XMLFragment <7> ( _                     ' VTable offset = 80
     BYVAL pfXMLFragment AS INTEGER _                   ' __in VARIANT_BOOL pfXMLFragment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transaction <8> ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfTransaction
   ' =====================================================================================
   PROPERTY SET Transaction <8> ( _                     ' VTable offset = 88
     BYVAL pfTransaction AS INTEGER _                   ' __in VARIANT_BOOL pfTransaction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IgnoreDuplicateKeys <9> ( _             ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfIgnoreDuplicateKeys
   ' =====================================================================================
   PROPERTY SET IgnoreDuplicateKeys <9> ( _             ' VTable offset = 96
     BYVAL pfIgnoreDuplicateKeys AS INTEGER _           ' __in VARIANT_BOOL pfIgnoreDuplicateKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BulkLoad <10> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfBulkLoad
   ' =====================================================================================
   PROPERTY SET BulkLoad <10> ( _                       ' VTable offset = 104
     BYVAL pfBulkLoad AS INTEGER _                      ' __in VARIANT_BOOL pfBulkLoad
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SchemaGen <11> ( _                      ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSchemaGen
   ' =====================================================================================
   PROPERTY SET SchemaGen <11> ( _                      ' VTable offset = 112
     BYVAL pfSchemaGen AS INTEGER _                     ' __in VARIANT_BOOL pfSchemaGen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SGDropTables <12> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfDropTables
   ' =====================================================================================
   PROPERTY SET SGDropTables <12> ( _                   ' VTable offset = 120
     BYVAL pfDropTables AS INTEGER _                    ' __in VARIANT_BOOL pfDropTables
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SGUseID <13> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfUseID
   ' =====================================================================================
   PROPERTY SET SGUseID <13> ( _                        ' VTable offset = 128
     BYVAL pfUseID AS INTEGER _                         ' __in VARIANT_BOOL pfUseID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorLogFile <14> ( _                   ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET ErrorLogFile <14> ( _                   ' VTable offset = 136
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TempFilePath <15> ( _                   ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTempFilePath
   ' =====================================================================================
   PROPERTY SET TempFilePath <15> ( _                   ' VTable offset = 144
     BYVAL pbstrTempFilePath AS WSTRING _               ' __in BSTR pbstrTempFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <16> ( _                              ' VTable offset = 148
     BYVAL bstrSchemaFile AS WSTRING _                  ' __in BSTR bstrSchemaFile
   , OPTIONAL BYVAL vDataFile AS VARIANT _              ' __opt_in VARIANT vDataFile
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ISQLXMLBulkLoad4 Methods
   ' =====================================================================================
   PROPERTY GET FireTriggers <17> ( _                   ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfFireTriggers
   ' =====================================================================================
   PROPERTY SET FireTriggers <17> ( _                   ' VTable offset = 156
     BYVAL pfFireTriggers AS INTEGER _                  ' __in VARIANT_BOOL pfFireTriggers
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLXMLBulkLoad4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISQLXMLBulkLoad
' IID = {1380DD8D-DCB9-4A6E-9D53-EECDDF18DA85}
' ISQLXMLBulkLoad Interface
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISQLXMLBulkLoad_INTERFACE_DEFINED)
    %ISQLXMLBulkLoad_INTERFACE_DEFINED = 1

INTERFACE ISQLXMLBulkLoad $IID_ISQLXMLBulkLoad

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConnectionString <1> ( _                ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrConnectionString
   ' =====================================================================================
   PROPERTY SET ConnectionString <1> ( _                ' VTable offset = 32
     BYVAL pbstrConnectionString AS WSTRING _           ' __in BSTR pbstrConnectionString
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionCommand <2> ( _               ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown** ppICommand
   ' =====================================================================================
   PROPERTY SET ConnectionCommand <2> ( _               ' VTable offset = 40
     BYVAL ppICommand AS IUnknown _                     ' __in IUnknown* ppICommand
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeepNulls <3> ( _                       ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfKeepNulls
   ' =====================================================================================
   PROPERTY SET KeepNulls <3> ( _                       ' VTable offset = 48
     BYVAL pfKeepNulls AS INTEGER _                     ' __in VARIANT_BOOL pfKeepNulls
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeepIdentity <4> ( _                    ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfKeepIdentity
   ' =====================================================================================
   PROPERTY SET KeepIdentity <4> ( _                    ' VTable offset = 56
     BYVAL pfKeepIdentity AS INTEGER _                  ' __in VARIANT_BOOL pfKeepIdentity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CheckConstraints <5> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfCheckConstraints
   ' =====================================================================================
   PROPERTY SET CheckConstraints <5> ( _                ' VTable offset = 64
     BYVAL pfCheckConstraints AS INTEGER _              ' __in VARIANT_BOOL pfCheckConstraints
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForceTableLock <6> ( _                  ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfForceTableLock
   ' =====================================================================================
   PROPERTY SET ForceTableLock <6> ( _                  ' VTable offset = 72
     BYVAL pfForceTableLock AS INTEGER _                ' __in VARIANT_BOOL pfForceTableLock
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET XMLFragment <7> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfXMLFragment
   ' =====================================================================================
   PROPERTY SET XMLFragment <7> ( _                     ' VTable offset = 80
     BYVAL pfXMLFragment AS INTEGER _                   ' __in VARIANT_BOOL pfXMLFragment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Transaction <8> ( _                     ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfTransaction
   ' =====================================================================================
   PROPERTY SET Transaction <8> ( _                     ' VTable offset = 88
     BYVAL pfTransaction AS INTEGER _                   ' __in VARIANT_BOOL pfTransaction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IgnoreDuplicateKeys <9> ( _             ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfIgnoreDuplicateKeys
   ' =====================================================================================
   PROPERTY SET IgnoreDuplicateKeys <9> ( _             ' VTable offset = 96
     BYVAL pfIgnoreDuplicateKeys AS INTEGER _           ' __in VARIANT_BOOL pfIgnoreDuplicateKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BulkLoad <10> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfBulkLoad
   ' =====================================================================================
   PROPERTY SET BulkLoad <10> ( _                       ' VTable offset = 104
     BYVAL pfBulkLoad AS INTEGER _                      ' __in VARIANT_BOOL pfBulkLoad
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SchemaGen <11> ( _                      ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfSchemaGen
   ' =====================================================================================
   PROPERTY SET SchemaGen <11> ( _                      ' VTable offset = 112
     BYVAL pfSchemaGen AS INTEGER _                     ' __in VARIANT_BOOL pfSchemaGen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SGDropTables <12> ( _                   ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfDropTables
   ' =====================================================================================
   PROPERTY SET SGDropTables <12> ( _                   ' VTable offset = 120
     BYVAL pfDropTables AS INTEGER _                    ' __in VARIANT_BOOL pfDropTables
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SGUseID <13> ( _                        ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfUseID
   ' =====================================================================================
   PROPERTY SET SGUseID <13> ( _                        ' VTable offset = 128
     BYVAL pfUseID AS INTEGER _                         ' __in VARIANT_BOOL pfUseID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorLogFile <14> ( _                   ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   PROPERTY SET ErrorLogFile <14> ( _                   ' VTable offset = 136
     BYVAL pbstrFileName AS WSTRING _                   ' __in BSTR pbstrFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TempFilePath <15> ( _                   ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTempFilePath
   ' =====================================================================================
   PROPERTY SET TempFilePath <15> ( _                   ' VTable offset = 144
     BYVAL pbstrTempFilePath AS WSTRING _               ' __in BSTR pbstrTempFilePath
   )                                                    ' void
   ' =====================================================================================
   METHOD Execute <16> ( _                              ' VTable offset = 148
     BYVAL bstrSchemaFile AS WSTRING _                  ' __in BSTR bstrSchemaFile
   , OPTIONAL BYVAL vDataFile AS VARIANT _              ' __opt_in VARIANT vDataFile
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISQLXMLBulkLoad_INTERFACE_DEFINED__ */
