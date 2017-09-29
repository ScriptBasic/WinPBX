' ########################################################################################
' Microsoft Windows
' File: DTSPipeline.inc
' Library name: DTSPipeline
' Version: 1.0, Locale ID = 0
' Library GUID: {BB92AA81-0996-4768-BE15-E47433F0204B}
' Path: C:\Archivos de programa\Microsoft SQL Server\90\DTS\Binn\DTSPipeline.dll
' Contents: DTSPipeline 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DTSPIPELINE_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "dts.inc"

$LIBID_DTSPipeline = GUID$("{BB92AA81-0996-4768-BE15-E47433F0204B}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {24AEBF41-43E9-49C6-9E16-4F8DDCE73FE6}
$PROGID_DTSBufferManager1 = "DTS.BufferManager.1"
' CLSID = {BF01D463-7089-41EE-8F05-0A6DC17CE633}
$PROGID_CManagedComponentWrapper1 = "DTS.ManagedComponentWrapper.1"
' CLSID = {C3BF9DC1-4715-4694-936F-D3CFDA9E42C5}
$PROGID_MainPipe1 = "DTS.Pipeline.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {24AEBF41-43E9-49C6-9E16-4F8DDCE73FE6}
$PROGID_DTSBufferManager = "DTS.BufferManager"
' CLSID = {BF01D463-7089-41EE-8F05-0A6DC17CE633}
$PROGID_CManagedComponentWrapper = "DTS.ManagedComponentWrapper"
' CLSID = {C3BF9DC1-4715-4694-936F-D3CFDA9E42C5}
$PROGID_MainPipe = "DTS.Pipeline"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DTSBufferManager = GUID$("{24AEBF41-43E9-49C6-9E16-4F8DDCE73FE6}")
$CLSID_CManagedComponentWrapper = GUID$("{BF01D463-7089-41EE-8F05-0A6DC17CE633}")
$CLSID_MainPipe = GUID$("{C3BF9DC1-4715-4694-936F-D3CFDA9E42C5}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDTSBLOBObject90 = GUID$("{FE5B9D3B-A6BB-4C3A-949F-84EB473EDBCA}")
$IID_IDTSBuffer90 = GUID$("{DF81E1A6-6D91-498A-8689-0BD75916697D}")
$IID_IDTSBufferManager90 = GUID$("{E6918F3C-06DC-46CC-AE4D-3AF12F5B0E25}")
$IID_IDTSComponentMetaData90 = GUID$("{D14BB312-213E-449A-9C38-42979B9548A0}")
$IID_IDTSComponentMetaDataCollection90 = GUID$("{9BE05B44-D46B-4879-9A50-ED3C72E5F347}")
$IID_IDTSComponentView90 = GUID$("{F9013912-2CEC-47C4-BF25-F9D404C4E88A}")
$IID_IDTSCustomProperty90 = GUID$("{5A78E6D8-6AE0-4D2B-81C1-4B990840B717}")
$IID_IDTSCustomPropertyCollection90 = GUID$("{1B718369-91F3-47A2-8234-CF0971E6E40C}")
$IID_IDTSDesigntimeComponent90 = GUID$("{76F19268-BCE0-4A23-95D1-F85AC738941D}")
$IID_IDTSExternalMetadataColumn90 = GUID$("{DF519267-8084-482A-94C7-2B8E6052E1FB}")
$IID_IDTSExternalMetadataColumnCollection90 = GUID$("{CC6D94F9-F447-4445-AB36-D786D7A21CB3}")
$IID_IDTSFriendlyEnum90 = GUID$("{32870502-FA13-4B2D-93D9-2F3A017DF045}")
$IID_IDTSFriendlyEnumCollection90 = GUID$("{72BA2210-2BBB-4A5C-8557-C32B4554605A}")
$IID_IDTSInput90 = GUID$("{212BA47D-840D-4004-9747-6FB6D80EE47B}")
$IID_IDTSInputCollection90 = GUID$("{3088ACDD-7F7A-41F1-AD2B-D672D105C9F1}")
$IID_IDTSInputColumn90 = GUID$("{CAB9C8F0-9362-472A-BDFF-8DE7D3E44DCF}")
$IID_IDTSInputColumnCollection90 = GUID$("{5A2058B3-DA54-45A2-BDEE-9FB9B4C5B1D7}")
$IID_IDTSManagedComponent90 = GUID$("{E5C32A7C-AFA2-49CA-AF4E-4952A0B76202}")
$IID_IDTSManagedComponentHost90 = GUID$("{C4C51533-E6CA-43F3-AE3A-32983E1EA33C}")
$IID_IDTSManagedComponentWrapper90 = GUID$("{025B7E3E-EAD0-4C51-AE5A-554FCB89995A}")
$IID_IDTSObject90 = GUID$("{F0F4367E-37B7-4056-8775-849B8078ED71}")
$IID_IDTSObjectModel90 = GUID$("{849596FD-555F-450D-942C-E4E39AF73583}")
$IID_IDTSOutput90 = GUID$("{5A3F4E89-4A68-4D16-A893-366A39AF9AE6}")
$IID_IDTSOutputCollection90 = GUID$("{43D798EF-C406-4CC3-B7DF-287A2057FB5D}")
$IID_IDTSOutputColumn90 = GUID$("{461B9938-BAAB-453E-AFE4-CAE695AED2FA}")
$IID_IDTSOutputColumnCollection90 = GUID$("{953A6134-3F6C-40AB-8C17-3E948EC9FF9B}")
$IID_IDTSPath90 = GUID$("{CBEA73B4-08DA-4FE7-A03A-829345CAEB84}")
$IID_IDTSPathCollection90 = GUID$("{054A07E8-BC68-4B40-8804-92066974535D}")
$IID_IDTSPersistenceComponent90 = GUID$("{3CF1B168-00E1-4818-8713-6CE11991732E}")
$IID_IDTSPipeline90 = GUID$("{9D0934EF-FA28-40F2-BF59-AB65C9E780D9}")
$IID_IDTSRuntimeComponent90 = GUID$("{AE9DA26D-2AFB-4217-8A4C-49CECC0620FE}")
$IID_IDTSRuntimeConnection90 = GUID$("{17AAAC2D-6852-4345-A9B2-7E0CD0472F52}")
$IID_IDTSRuntimeConnectionCollection90 = GUID$("{58EA6E8B-369E-4B58-B94A-421B5093F972}")
$IID_IDTSVirtualInput90 = GUID$("{B9A5E5EB-4BFC-48AF-95E9-6344C6794340}")
$IID_IDTSVirtualInputColumn90 = GUID$("{542A9F86-A45E-4B45-863D-45E74CCA88DB}")
$IID_IDTSVirtualInputColumnCollection90 = GUID$("{31804D52-79B6-48BD-8FC0-7FB53066DE70}")

'typedef ULONG DTPLENGTH;
'typedef DWORD DTPSTATUS;
'typedef /* [public] */ LONG DTP_HBUFFERTYPE;
'typedef /* [public] */ LONG DTP_HBUFFER;
'typedef /* [public] */ LONG DTP_HROW;
'typedef /* [public] */ LONG DTP_HCOL;

' ========================================================================================
' DTSPIPELINEVERSION enum
' ========================================================================================

%DTSPIPELINE_CURRENTVERSION                             = 0

' ========================================================================================
' DTPSTATUSENUM enum
' ========================================================================================

%DTPSTATUS_OK                                           = 0
%DTPSTATUS_BADACCESSOR                                  = 1
%DTPSTATUS_CANTCONVERTVALUE                             = 2
%DTPSTATUS_ISNULL                                       = 3
%DTPSTATUS_TRUNCATED                                    = 4
%DTPSTATUS_SIGNMISMATCH                                 = 5
%DTPSTATUS_DATAOVERFLOW                                 = 6
%DTPSTATUS_CANTCREATE                                   = 7
%DTPSTATUS_UNAVAILABLE                                  = 8
%DTPSTATUS_PERMISSIONDENIED                             = 9
%DTPSTATUS_INTEGRITYVIOLATION                           = 10
%DTPSTATUS_SCHEMAVIOLATION                              = 11
%DTPSTATUS_BADSTATUS                                    = 12
%DTPSTATUS_DEFAULT                                      = 13

' ========================================================================================
' DTSValidationStatus enum
' ========================================================================================

%VS_ISVALID                                             = 0
%VS_ISBROKEN                                            = 1
%VS_NEEDSNEWMETADATA                                    = 2
%VS_ISCORRUPT                                           = 3

' ========================================================================================
' DTSInsertPlacement enum
' ========================================================================================

%IP_BEFORE                                              = 0
%IP_AFTER                                               = 1

' ========================================================================================
' DTSObjectType enum
' ========================================================================================

%OT_UNSPECIFIED                                         = 0
%OT_SOURCEADAPTER                                       = 1
%OT_DESTINATIONADAPTER                                  = 2
%OT_TRANSFORM                                           = 4
%OT_COMPONENT                                           = 8
%OT_COMPONENTVIEWER                                     = 16
%OT_PATH                                                = 32
%OT_INPUT                                               = 64
%OT_VIRTUALINPUT                                        = 128
%OT_OUTPUT                                              = 256
%OT_INPUTCOLUMN                                         = 512
%OT_OUTPUTCOLUMN                                        = 1024
%OT_VIRTUALINPUTCOLUMN                                  = 2048
%OT_PROPERTY                                            = 4096
%OT_RUNTIMECONNECTION                                   = 8192
%OT_EXTERNALMETADATACOLUMN                              = 16384

' ========================================================================================
' DTSPersistenceFormat enum
' ========================================================================================

%PF_XML                                                 = 1
%PF_SQLSERVER                                           = 2

' ========================================================================================
' DTSBufferHandlePresetValues enum
' ========================================================================================

%H_ALL                                                  = -1

' ========================================================================================
' DTSBufferFlags enum
' ========================================================================================

%BUFF_NOOLEDB                                           = &H1
%BUFF_INIT                                              = &H2

' ========================================================================================
' DTSUsageType enum
' ========================================================================================

%UT_READONLY                                            = 0
%UT_READWRITE                                           = 1
%UT_IGNORED                                             = 2

' ========================================================================================
' DTSPersistState enum
' ========================================================================================

%PS_DEFAULT                                             = 0
%PS_PERSISTASHEX                                        = 1
%PS_PERSISTASCDATA                                      = 2

' ========================================================================================
' DTSRowDisposition enum
' ========================================================================================

%RD_NotUsed                                             = 0
%RD_IgnoreFailure                                       = 1
%RD_RedirectRow                                         = 2
%RD_FailComponent                                       = 4

' ========================================================================================
' DTSCustomPropertyExpressionType enum
' ========================================================================================

%CPET_NONE                                              = 0
%CPET_NOTIFY                                            = 1

' ========================================================================================
' tagBUFFER_WIRE_PACKET record <alias> BUFFER_WIRE_PACKET
' Number of members = 5
' ========================================================================================

' // Size = 20 bytes
TYPE BUFFER_WIRE_PACKET DWORD
   dwRowCount      AS DWORD       ' DWORD
   dwColCount      AS DWORD       ' DWORD
   ppvRowStarts    AS DWORD PTR   ' void*
   pColInfo        AS DWORD PTR   ' void*
   vbIsEndOfRowset AS INTEGER     ' VARIANT_BOOL
END TYPE

' ========================================================================================
' tagBUFFERCOL record <alias> DTP_BUFFCOL
' Number of members = 8
' ========================================================================================

' // Size = 32 bytes
TYPE DTP_BUFFCOL DWORD
   DataType      AS LONG   ' DataType enum
   lMaxLength    AS LONG   ' LONG
   lOffset       AS LONG   ' LONG
   lStatusOffset AS LONG   ' LONG
   lLengthOffset AS LONG   ' LONG
   lPrecision    AS LONG   ' LONG
   lScale        AS LONG   ' LONG
   lCodePage     AS LONG   ' LONG
END TYPE

' ########################################################################################
' Interface name = IDTSBufferNotify90
' IID = DF81E1A9-6D91-498A-8689-0BD75916697D
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBufferNotify90_INTERFACE_DEFINED)
    %IDTSBufferNotify90_INTERFACE_DEFINED = 1

$IID_IDTSBufferNotify90 = GUID$("{DF81E1A9-6D91-498A-8689-0BD75916697D}")

INTERFACE IDTSBufferNotify90 $IID_IDTSBufferNotify90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EndOfRowset ( _                               ' VTable offset = 12
     BYVAL pLastBuffer AS IDTSBuffer90 _                ' __in IDTSBuffer90 *pLastBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BufferFull ( _                                ' VTable offset = 16
     BYVAL pFullBuffer AS IDTSBuffer90 _                ' __in IDTSBuffer90 *pFullBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBufferNotify90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBLOBObject90
' IID = {FE5B9D3B-A6BB-4C3A-949F-84EB473EDBCA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBLOBObject90_INTERFACE_DEFINED)
    %IDTSBLOBObject90_INTERFACE_DEFINED = 1

INTERFACE IDTSBLOBObject90 $IID_IDTSBLOBObject90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Length <101> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plLength
   ' =====================================================================================
   PROPERTY SET SpoolThreshold <102> ( _                ' VTable offset = 32
     BYVAL plSpoolThreshold AS LONG _                   ' __in long plSpoolThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SpoolThreshold <102> ( _                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plSpoolThreshold
   ' =====================================================================================
   METHOD ResetData <103> ( _                           ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD AddData <104> ( _                             ' VTable offset = 44
     BYVAL lpData AS BYTE PTR _                         ' __in BYTE *lpData
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData <105> ( _                             ' VTable offset = 48
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL lpPointer AS BYTE PTR _                      ' __in BYTE *lpPointer
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   , BYREF lpdwWritten AS DWORD _                       ' __out DWORD *lpdwWritten
   )                                                    ' void
   ' =====================================================================================
   METHOD PutData <106> ( _                             ' VTable offset = 52
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL lpPointer AS BYTE PTR _                      ' __in BYTE *lpPointer
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   , BYREF lpdwRead AS DWORD _                          ' __out DWORD *lpdwRead
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStream <107> ( _                           ' VTable offset = 56
   ) AS IStream                                         ' __retval_out IStream **pIStream
   ' =====================================================================================
   METHOD SetFromStream <108> ( _                       ' VTable offset = 60
     BYVAL pISequentialStream AS ISequentialStream _    ' __in ISequentialStream *pISequentialStream
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBLOBObject90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSObject90
' IID = {F0F4367E-37B7-4056-8775-849B8078ED71}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSObject90_INTERFACE_DEFINED)
    %IDTSObject90_INTERFACE_DEFINED = 1

INTERFACE IDTSObject90 $IID_IDTSObject90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSObject90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSCustomProperty90
' IID = {5A78E6D8-6AE0-4D2B-81C1-4B990840B717}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSCustomProperty90_INTERFACE_DEFINED)
    %IDTSCustomProperty90_INTERFACE_DEFINED = 1

INTERFACE IDTSCustomProperty90 $IID_IDTSCustomProperty90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSCustomProperty90 Methods
   ' =====================================================================================
   PROPERTY GET Value <101> ( _                         ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvValue
   ' =====================================================================================
   PROPERTY SET Value <101> ( _                         ' VTable offset = 64
     BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET State <102> ( _                         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out enum DTSPersistState *pePropertyState
   ' =====================================================================================
   PROPERTY SET State <102> ( _                         ' VTable offset = 72
     BYVAL ePropertyState AS LONG _                     ' __in enum DTSPersistState ePropertyState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptionRequired <103> ( _            ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnryptionRequired
   ' =====================================================================================
   PROPERTY SET EncryptionRequired <103> ( _            ' VTable offset = 80
     BYVAL bEnryptionRequired AS INTEGER _              ' __in VARIANT_BOOL bEnryptionRequired
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeConverter <104> ( _                 ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTypeConverter
   ' =====================================================================================
   PROPERTY SET TypeConverter <104> ( _                 ' VTable offset = 88
     BYVAL bstrTypeConverter AS WSTRING _               ' __in BSTR bstrTypeConverter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UITypeEditor <105> ( _                  ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUITypeEditor
   ' =====================================================================================
   PROPERTY SET UITypeEditor <105> ( _                  ' VTable offset = 96
     BYVAL bstrUITypeEditor AS WSTRING _                ' __in BSTR bstrUITypeEditor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainsID <106> ( _                    ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbContainsID
   ' =====================================================================================
   PROPERTY SET ContainsID <106> ( _                    ' VTable offset = 104
     BYVAL bContainsID AS INTEGER _                     ' __in VARIANT_BOOL bContainsID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExpressionType <107> ( _                ' VTable offset = 108
   ) AS LONG                                            ' __retval_out enum DTSCustomPropertyExpressionType *peExpressionType
   ' =====================================================================================
   PROPERTY SET ExpressionType <107> ( _                ' VTable offset = 112
     BYVAL eExpressionType AS LONG _                    ' __in enum DTSCustomPropertyExpressionType eExpressionType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSCustomProperty90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSCustomPropertyCollection90
' IID = {1B718369-91F3-47A2-8234-CF0971E6E40C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSCustomPropertyCollection90_INTERFACE_DEFINED)
    %IDTSCustomPropertyCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSCustomPropertyCollection90 $IID_IDTSCustomPropertyCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSCustomPropertyCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSInputColumn90
' IID = {CAB9C8F0-9362-472A-BDFF-8DE7D3E44DCF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSInputColumn90_INTERFACE_DEFINED)
    %IDTSInputColumn90_INTERFACE_DEFINED = 1

INTERFACE IDTSInputColumn90 $IID_IDTSInputColumn90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSInputColumn90 Methods
   ' =====================================================================================
   PROPERTY GET DataType <101> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DataType *peDataType
   ' =====================================================================================
   PROPERTY GET Length <102> ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plLength
   ' =====================================================================================
   PROPERTY GET Precision <103> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrecision
   ' =====================================================================================
   PROPERTY GET Scale <104> ( _                         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plScale
   ' =====================================================================================
   PROPERTY GET UsageType <105> ( _                     ' VTable offset = 76
   ) AS LONG                                            ' [out][retval] DTSUsageType *peUsageType
   ' =====================================================================================
   PROPERTY SET UsageType <105> ( _                     ' VTable offset = 80
     BYVAL peUsageType AS LONG _                        ' __retval_out enum DTSUsageType *peUsageType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <107> ( _      ' VTable offset = 84
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   PROPERTY GET LineageID <108> ( _                     ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plLineageID
   ' =====================================================================================
   PROPERTY SET LineageID <108> ( _                     ' VTable offset = 92
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <115> ( _                      ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *plCodePage
   ' =====================================================================================
   PROPERTY GET IsValid <122> ( _                       ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsValid
   ' =====================================================================================
   PROPERTY GET SortKeyPosition <123> ( _               ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plSortKeyPosition
   ' =====================================================================================
   PROPERTY GET ComparisonFlags <124> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plComparisonFlags
   ' =====================================================================================
   PROPERTY GET UpstreamComponentName <125> ( _         ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUpstreamComponentName
   ' =====================================================================================
   PROPERTY GET ErrorRowDisposition <129> ( _           ' VTable offset = 116
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET ErrorRowDisposition <129> ( _           ' VTable offset = 120
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TruncationRowDisposition <130> ( _      ' VTable offset = 124
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET TruncationRowDisposition <130> ( _      ' VTable offset = 128
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorOrTruncationOperation <131> ( _    ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY SET ErrorOrTruncationOperation <131> ( _    ' VTable offset = 136
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExternalMetadataColumnID <132> ( _      ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long *plExternalMetadataColumnID
   ' =====================================================================================
   PROPERTY SET ExternalMetadataColumnID <132> ( _      ' VTable offset = 144
     BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD DescribeRedirectedErrorCode <133> ( _         ' VTable offset = 148
     BYVAL hrErrorCode AS LONG _                        ' __in HRESULT hrErrorCode
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSInputColumn90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSInputColumnCollection90
' IID = {5A2058B3-DA54-45A2-BDEE-9FB9B4C5B1D7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSInputColumnCollection90_INTERFACE_DEFINED)
    %IDTSInputColumnCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSInputColumnCollection90 $IID_IDTSInputColumnCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL LONG _                                       ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD GetInputColumnByLineageID <101> ( _           ' VTable offset = 80
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD GetInputColumnByName <102> ( _                ' VTable offset = 84
     BYVAL bstrComponentName AS WSTRING _               ' __in BSTR bstrComponentName
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSInputColumnCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSOutputColumn90
' IID = {461B9938-BAAB-453E-AFE4-CAE695AED2FA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSOutputColumn90_INTERFACE_DEFINED)
    %IDTSOutputColumn90_INTERFACE_DEFINED = 1

INTERFACE IDTSOutputColumn90 $IID_IDTSOutputColumn90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSOutputColumn90 Methods
   ' =====================================================================================
   PROPERTY GET DataType <101> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DataType *peDataType
   ' =====================================================================================
   PROPERTY GET Length <102> ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plLength
   ' =====================================================================================
   PROPERTY GET Precision <103> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrecision
   ' =====================================================================================
   PROPERTY GET Scale <104> ( _                         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plScale
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <106> ( _      ' VTable offset = 76
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   PROPERTY GET LineageID <107> ( _                     ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plLineageID
   ' =====================================================================================
   PROPERTY SET LineageID <107> ( _                     ' VTable offset = 84
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <108> ( _                      ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *plCodePage
   ' =====================================================================================
   PROPERTY GET SortKeyPosition <109> ( _               ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plSortKeyPosition
   ' =====================================================================================
   PROPERTY SET SortKeyPosition <109> ( _               ' VTable offset = 96
     BYVAL lSortKeyPosition AS LONG _                   ' long lSortKeyPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ComparisonFlags <110> ( _               ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *plComparisonFlags
   ' =====================================================================================
   PROPERTY SET ComparisonFlags <110> ( _               ' VTable offset = 104
     BYVAL lComparisonFlags AS LONG _                   ' long lComparisonFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SpecialFlags <112> ( _                  ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plSpecialFlags
   ' =====================================================================================
   PROPERTY SET SpecialFlags <112> ( _                  ' VTable offset = 112
     BYVAL lSpecialFlags AS LONG _                      ' long lSpecialFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDataTypeProperties <114> ( _               ' VTable offset = 116
     BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorRowDisposition <115> ( _           ' VTable offset = 120
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET ErrorRowDisposition <115> ( _           ' VTable offset = 124
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TruncationRowDisposition <116> ( _      ' VTable offset = 128
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET TruncationRowDisposition <116> ( _      ' VTable offset = 132
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorOrTruncationOperation <117> ( _    ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY SET ErrorOrTruncationOperation <117> ( _    ' VTable offset = 140
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExternalMetadataColumnID <118> ( _      ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *plExternalMetadataColumnID
   ' =====================================================================================
   PROPERTY SET ExternalMetadataColumnID <118> ( _      ' VTable offset = 148
     BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSOutputColumn90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSOutputColumnCollection90
' IID = {953A6134-3F6C-40AB-8C17-3E948EC9FF9B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSOutputColumnCollection90_INTERFACE_DEFINED)
    %IDTSOutputColumnCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSOutputColumnCollection90 $IID_IDTSOutputColumnCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD GetOutputColumnByLineageID <101> ( _          ' VTable offset = 80
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSOutputColumnCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVirtualInputColumn90
' IID = {542A9F86-A45E-4B45-863D-45E74CCA88DB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSVirtualInputColumn90_INTERFACE_DEFINED)
    %IDTSVirtualInputColumn90_INTERFACE_DEFINED = 1

INTERFACE IDTSVirtualInputColumn90 $IID_IDTSVirtualInputColumn90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSVirtualInputColumn90 Methods
   ' =====================================================================================
   PROPERTY GET DataType <101> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DataType *peDataType
   ' =====================================================================================
   PROPERTY GET Length <102> ( _                        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plLength
   ' =====================================================================================
   PROPERTY GET Precision <103> ( _                     ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrecision
   ' =====================================================================================
   PROPERTY GET Scale <104> ( _                         ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plScale
   ' =====================================================================================
   PROPERTY GET UsageType <105> ( _                     ' VTable offset = 76
   ) AS LONG                                            ' __retval_out enum DTSUsageType *peUsageType
   ' =====================================================================================
   PROPERTY GET LineageID <108> ( _                     ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plLineageID
   ' =====================================================================================
   PROPERTY GET SourceComponent <111> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSourceComponent
   ' =====================================================================================
   PROPERTY GET NewName <113> ( _                       ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNewName
   ' =====================================================================================
   PROPERTY SET NewName <113> ( _                       ' VTable offset = 92
     BYVAL bstrNewName AS WSTRING _                     ' __in BSTR bstrNewName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewDescription <114> ( _                ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNewDescription
   ' =====================================================================================
   PROPERTY SET NewDescription <114> ( _                ' VTable offset = 100
     BYVAL bstrNewDescription AS WSTRING _              ' __in BSTR bstrNewDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <115> ( _                      ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plCodePage
   ' =====================================================================================
   PROPERTY GET SortKeyPosition <122> ( _               ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plSortKeyPosition
   ' =====================================================================================
   PROPERTY GET ComparisonFlags <123> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *plComparisonFlags
   ' =====================================================================================
   PROPERTY GET UpstreamComponentName <124> ( _         ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUpstreamComponentName
   ' =====================================================================================
   METHOD DescribeRedirectedErrorCode <128> ( _         ' VTable offset = 120
     BYVAL hrErrorCode AS LONG _                        ' __in HRESULT hrErrorCode
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVirtualInputColumn90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVirtualInputColumnCollection90
' IID = {31804D52-79B6-48BD-8FC0-7FB53066DE70}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSVirtualInputColumnCollection90_INTERFACE_DEFINED)
    %IDTSVirtualInputColumnCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSVirtualInputColumnCollection90 $IID_IDTSVirtualInputColumnCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSVirtualInputColumn90                        ' __retval_out IDTSVirtualInputColumn90 **ppIDTSVirtualInputColumn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 40
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 44
     BYVAL LONG _                                       ' __in long lID
   ) AS IDTSVirtualInputColumn90                        ' __retval_out IDTSVirtualInputColumn90 **ppIDTSVirtualInputColumn
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 48
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSVirtualInputColumn90                        ' __retval_out IDTSVirtualInputColumn90 **ppIDTSVirtualInputColumn
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 56
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD GetVirtualInputColumnByLineageID <101> ( _    ' VTable offset = 60
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   ) AS IDTSVirtualInputColumn90                        ' __retval_out IDTSVirtualInputColumn90 **ppIDTSVirtualInputColumn
   ' =====================================================================================
   METHOD GetVirtualInputColumnByName <102> ( _         ' VTable offset = 64
     BYVAL bstrComponentName AS WSTRING _               ' __in BSTR bstrComponentName
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS IDTSVirtualInputColumn90                        ' __retval_out IDTSVirtualInputColumn90 **ppIDTSVirtualInputColumn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVirtualInputColumnCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSVirtualInput90
' IID = {B9A5E5EB-4BFC-48AF-95E9-6344C6794340}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSVirtualInput90_INTERFACE_DEFINED)
    %IDTSVirtualInput90_INTERFACE_DEFINED = 1

INTERFACE IDTSVirtualInput90 $IID_IDTSVirtualInput90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSVirtualInput90 Methods
   ' =====================================================================================
   PROPERTY GET VirtualInputColumnCollection <101> ( _  ' VTable offset = 60
   ) AS IDTSVirtualInputColumnCollection90              ' __retval_out IDTSVirtualInputColumnCollection90 **ppIDTSVirtualInputColumnCollection
   ' =====================================================================================
   METHOD SetUsageType <104> ( _                        ' VTable offset = 64
     BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   , BYVAL eUsageType AS LONG _                         ' __in enum DTSUsageType eUsageType
   ) AS LONG                                            ' __retval_out long *plAffectedColumnIndex
   ' =====================================================================================
   PROPERTY GET IsSorted <106> ( _                      ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsSorted
   ' =====================================================================================
   PROPERTY GET SourceLocale <107> ( _                  ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plSourceLocale
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSVirtualInput90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSInput90
' IID = {212BA47D-840D-4004-9747-6FB6D80EE47B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSInput90_INTERFACE_DEFINED)
    %IDTSInput90_INTERFACE_DEFINED = 1

INTERFACE IDTSInput90 $IID_IDTSInput90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSInput90 Methods
   ' =====================================================================================
   PROPERTY GET HasSideEffects <101> ( _                ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasSideEffects
   ' =====================================================================================
   PROPERTY SET HasSideEffects <101> ( _                ' VTable offset = 64
     BYVAL bHasSideEffects AS INTEGER _                 ' __in VARIANT_BOOL bHasSideEffects
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Buffer <103> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out DTP_HBUFFERTYPE *phBufferType
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <104> ( _      ' VTable offset = 72
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   METHOD GetVirtualInput <105> ( _                     ' VTable offset = 76
   ) AS IDTSVirtualInput90                              ' __retval_out IDTSVirtualInput90 **ppIDTSVirtualInput
   ' =====================================================================================
   PROPERTY GET InputColumnCollection <106> ( _         ' VTable offset = 80
   ) AS IDTSInputColumnCollection90                     ' __retval_out IDTSInputColumnCollection90 **ppIDTSInputColumnCollection
   ' =====================================================================================
   PROPERTY GET Dangling <107> ( _                      ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDangling
   ' =====================================================================================
   PROPERTY SET Dangling <107> ( _                      ' VTable offset = 88
     BYVAL bDangling AS INTEGER _                       ' __in VARIANT_BOOL bDangling
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAttached <110> ( _                    ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsAttached
   ' =====================================================================================
   PROPERTY GET IsSorted <111> ( _                      ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsSorted
   ' =====================================================================================
   PROPERTY GET SourceLocale <112> ( _                  ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *plSourceLocale
   ' =====================================================================================
   PROPERTY GET ErrorRowDisposition <113> ( _           ' VTable offset = 104
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET ErrorRowDisposition <113> ( _           ' VTable offset = 108
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TruncationRowDisposition <114> ( _      ' VTable offset = 112
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET TruncationRowDisposition <114> ( _      ' VTable offset = 116
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorOrTruncationOperation <115> ( _    ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY SET ErrorOrTruncationOperation <115> ( _    ' VTable offset = 124
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExternalMetadataColumnCollection <116> ( _ ' VTable offset = 128
   ) AS IDTSExternalMetadataColumnCollection90          ' __retval_out IDTSExternalMetadataColumnCollection90 **ppIDTSExternalMetadataColumnCollection
   ' =====================================================================================
   PROPERTY GET Component <117> ( _                     ' VTable offset = 132
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSInput90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSInputCollection90
' IID = {3088ACDD-7F7A-41F1-AD2B-D672D105C9F1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSInputCollection90_INTERFACE_DEFINED)
    %IDTSInputCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSInputCollection90 $IID_IDTSInputCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSInputCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSOutput90
' IID = {5A3F4E89-4A68-4D16-A893-366A39AF9AE6}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSOutput90_INTERFACE_DEFINED)
    %IDTSOutput90_INTERFACE_DEFINED = 1

INTERFACE IDTSOutput90 $IID_IDTSOutput90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSOutput90 Methods
   ' =====================================================================================
   PROPERTY GET ExclusionGroup <101> ( _                ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plExclusionGroup
   ' =====================================================================================
   PROPERTY SET ExclusionGroup <101> ( _                ' VTable offset = 64
     BYVAL lExclusionGroup AS LONG _                    ' __in long lExclusionGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SynchronousInputID <102> ( _            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plSynchronousInputID
   ' =====================================================================================
   PROPERTY SET SynchronousInputID <102> ( _            ' VTable offset = 72
     BYVAL lSynchronousInputID AS LONG _                ' __in long lSynchronousInputID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Buffer <103> ( _                        ' VTable offset = 76
   ) AS LONG                                            ' __retval_out DTP_HBUFFERTYPE *phBufferType
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <104> ( _      ' VTable offset = 80
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   PROPERTY GET DeleteOutputOnPathDetached <105> ( _    ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDeleteOutputOnPathDetached
   ' =====================================================================================
   PROPERTY SET DeleteOutputOnPathDetached <105> ( _    ' VTable offset = 88
     BYVAL bDeleteOutputOnPathDetached AS INTEGER _     ' __in VARIANT_BOOL bDeleteOutputOnPathDetached
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputColumnCollection <106> ( _        ' VTable offset = 92
   ) AS IDTSOutputColumnCollection90                    ' __retval_out IDTSOutputColumnCollection90 **ppIDTSOutputColumnCollection
   ' =====================================================================================
   PROPERTY GET HasSideEffects <107> ( _                ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbHasSideEffects
   ' =====================================================================================
   PROPERTY SET HasSideEffects <107> ( _                ' VTable offset = 100
     BYVAL bHasSideEffects AS INTEGER _                 ' __in VARIANT_BOOL bHasSideEffects
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsErrorOut <108> ( _                    ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsErrorOut
   ' =====================================================================================
   PROPERTY SET IsErrorOut <108> ( _                    ' VTable offset = 108
     BYVAL bIsErrorOut AS INTEGER _                     ' __in VARIANT_BOOL bIsErrorOut
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAttached <110> ( _                    ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsAttached
   ' =====================================================================================
   PROPERTY GET IsSorted <111> ( _                      ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsSorted
   ' =====================================================================================
   PROPERTY SET IsSorted <111> ( _                      ' VTable offset = 120
     BYVAL bIsSorted AS INTEGER _                       ' __in VARIANT_BOOL bIsSorted
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorRowDisposition <115> ( _           ' VTable offset = 124
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET ErrorRowDisposition <115> ( _           ' VTable offset = 128
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TruncationRowDisposition <116> ( _      ' VTable offset = 132
   ) AS LONG                                            ' __retval_out enum DTSRowDisposition *peDisposition
   ' =====================================================================================
   PROPERTY SET TruncationRowDisposition <116> ( _      ' VTable offset = 136
     BYVAL eDisposition AS LONG _                       ' __in enum DTSRowDisposition eDisposition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ErrorOrTruncationOperation <117> ( _    ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY SET ErrorOrTruncationOperation <117> ( _    ' VTable offset = 144
     BYVAL bstrValue AS WSTRING _                       ' __in BSTR bstrValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExternalMetadataColumnCollection <118> ( _ ' VTable offset = 148
   ) AS IDTSExternalMetadataColumnCollection90          ' __retval_out IDTSExternalMetadataColumnCollection90 **ppIDTSExternalMetadataColumnCollection
   ' =====================================================================================
   PROPERTY GET Component <119> ( _                     ' VTable offset = 152
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   PROPERTY GET Dangling <120> ( _                      ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDangling
   ' =====================================================================================
   PROPERTY SET Dangling <120> ( _                      ' VTable offset = 160
     BYVAL bDangling AS INTEGER _                       ' __in VARIANT_BOOL bDangling
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSOutput90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSOutputCollection90
' IID = {43D798EF-C406-4CC3-B7DF-287A2057FB5D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSOutputCollection90_INTERFACE_DEFINED)
    %IDTSOutputCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSOutputCollection90 $IID_IDTSOutputCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSOutputCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRuntimeConnection90
' IID = {17AAAC2D-6852-4345-A9B2-7E0CD0472F52}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSRuntimeConnection90_INTERFACE_DEFINED)
    %IDTSRuntimeConnection90_INTERFACE_DEFINED = 1

INTERFACE IDTSRuntimeConnection90 $IID_IDTSRuntimeConnection90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSRuntimeConnection90 Methods
   ' =====================================================================================
   PROPERTY GET ConnectionManagerID <101> ( _           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConnectionManagerID
   ' =====================================================================================
   PROPERTY SET ConnectionManagerID <101> ( _           ' VTable offset = 64
     BYVAL bstrConnectionManagerID AS WSTRING _         ' __in BSTR bstrConnectionManagerID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectionManager <102> ( _             ' VTable offset = 68
   ) AS IDTSConnectionManager90                         ' __retval_out IDTSConnectionManager90 **ppIDTSConnectionManager
   ' =====================================================================================
   PROPERTY SET ConnectionManager <102> ( _             ' VTable offset = 72
     BYVAL pIDTSConnectionManager AS IDTSConnectionManager90 _ ' __in IDTSConnectionManager90 *pIDTSConnectionManager
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseConnectionManager <103> ( _            ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSRuntimeConnection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRuntimeConnectionCollection90
' IID = {58EA6E8B-369E-4B58-B94A-421B5093F972}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSRuntimeConnectionCollection90_INTERFACE_DEFINED)
    %IDTSRuntimeConnectionCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSRuntimeConnectionCollection90 $IID_IDTSRuntimeConnectionCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSRuntimeConnection90                         ' __retval_out IDTSRuntimeConnection90 **ppIDTSRuntimeConnection
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSRuntimeConnection90                         ' __retval_out IDTSRuntimeConnection90 **ppIDTSRuntimeConnection
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSRuntimeConnection90                         ' __retval_out IDTSRuntimeConnection90 **ppIDTSRuntimeConnection
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSRuntimeConnection90                         ' __retval_out IDTSRuntimeConnection90 **ppIDTSRuntimeConnection
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSRuntimeConnection90                         ' __retval_out IDTSRuntimeConnection90 **ppIDTSRuntimeConnection
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSRuntimeConnectionCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSComponentMetaData90
' IID = {D14BB312-213E-449A-9C38-42979B9548A0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSComponentMetaData90_INTERFACE_DEFINED)
    %IDTSComponentMetaData90_INTERFACE_DEFINED = 1

INTERFACE IDTSComponentMetaData90 $IID_IDTSComponentMetaData90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSComponentMetaData90 Methods
   ' =====================================================================================
   PROPERTY GET ComponentClassID <101> ( _              ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *bstrComponentClassID
   ' =====================================================================================
   PROPERTY SET ComponentClassID <101> ( _              ' VTable offset = 64
     BYVAL bstrComponentClassID AS WSTRING _            ' __in BSTR bstrComponentClassID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputCollection <102> ( _               ' VTable offset = 68
   ) AS IDTSInputCollection90                           ' __retval_out IDTSInputCollection90 **ppIDTSInputCollection
   ' =====================================================================================
   PROPERTY GET OutputCollection <103> ( _              ' VTable offset = 72
   ) AS IDTSOutputCollection90                          ' __retval_out IDTSInputCollection90 **ppIDTSInputCollection
   ' =====================================================================================
   METHOD Instantiate <104> ( _                         ' VTable offset = 76
   ) AS IDTSDesigntimeComponent90                       ' __retval_out IDTSDesigntimeComponent90 **ppIDTSDesigntimeComponent
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <105> ( _      ' VTable offset = 80
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   METHOD PostLogMessage <110> ( _                      ' VTable offset = 84
     BYVAL bstrEventName AS WSTRING _                   ' __in BSTR bstrEventName
   , BYVAL bstrSourceName AS WSTRING _                  ' __in BSTR bstrSourceName
   , BYVAL bstrMessageText AS WSTRING _                 ' __in BSTR bstrMessageText
   , BYVAL dateStartTime AS DOUBLE _                    ' __in DATE dateStartTime
   , BYVAL dateEndTime AS DOUBLE _                      ' __in DATE dateEndTime
   , BYVAL lDataCode AS LONG _                          ' __in long lDataCode
   , BYREF DWORD _                                      ' __in SAFEARRAY * *psaDataBytes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RuntimeConnectionCollection <114> ( _   ' VTable offset = 88
   ) AS IDTSRuntimeConnectionCollection90               ' __retval_out IDTSRuntimeConnectionCollection90 **ppIDTSRuntimeConnectionCollection
   ' =====================================================================================
   METHOD RemoveInvalidInputColumns <115> ( _           ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD GetErrorDescription <116> ( _                 ' VTable offset = 96
     BYVAL hrError AS LONG _                            ' __in long hrError
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY GET AreInputColumnsValid <117> ( _          ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAreInputColumnsValid
   ' =====================================================================================
   PROPERTY GET LocaleID <118> ( _                      ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *plLocaleID
   ' =====================================================================================
   PROPERTY SET LocaleID <118> ( _                      ' VTable offset = 108
     BYVAL lLocaleID AS LONG _                          ' __in long lLocaleID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetComponentView <119> ( _                    ' VTable offset = 112
   ) AS IDTSComponentView90                             ' __retval_out IDTSComponentView90 **ppIDTSComponentView
   ' =====================================================================================
   METHOD Validate <120> ( _                            ' VTable offset = 116
   ) AS LONG                                            ' __retval_out enum DTSValidationStatus *peValidationStatus
   ' =====================================================================================
   METHOD IncrementPipelinePerfCounter <123> ( _        ' VTable offset = 120
     BYVAL dwCounterID AS DWORD _                       ' __in DWORD dwCounterID
   , BYVAL dwDifference AS DWORD _                      ' __in DWORD dwDifference
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsDefaultLocale <124> ( _               ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsDefault
   ' =====================================================================================
   PROPERTY GET UsesDispositions <125> ( _              ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbUsesDispositions
   ' =====================================================================================
   PROPERTY SET UsesDispositions <125> ( _              ' VTable offset = 132
     BYVAL bUsesDispositions AS INTEGER _               ' __in VARIANT_BOOL bUsesDispositions
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValidateExternalMetadata <126> ( _      ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbValidate
   ' =====================================================================================
   PROPERTY SET ValidateExternalMetadata <126> ( _      ' VTable offset = 140
     BYVAL bValidate AS INTEGER _                       ' __in VARIANT_BOOL bValidate
   )                                                    ' void
   ' =====================================================================================
   METHOD FireWarning <127> ( _                         ' VTable offset = 144
     BYVAL WarningCode AS LONG _                        ' __in long WarningCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   )                                                    ' void
   ' =====================================================================================
   METHOD FireInformation <128> ( _                     ' VTable offset = 148
     BYVAL InformationCode AS LONG _                    ' __in long InformationCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   METHOD FireError <129> ( _                           ' VTable offset = 152
     BYVAL ErrorCode AS LONG _                          ' __in long ErrorCode
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL HelpFile AS WSTRING _                        ' __in BSTR HelpFile
   , BYVAL HelpContext AS LONG _                        ' __in long HelpContext
   , BYREF pbCancel AS INTEGER _                        ' __out VARIANT_BOOL *pbCancel
   )                                                    ' void
   ' =====================================================================================
   METHOD FireCustomEvent <130> ( _                     ' VTable offset = 156
     BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
   , BYVAL EventText AS WSTRING _                       ' __in BSTR EventText
   , BYREF ppsaArguments AS DWORD _                     ' __in SAFEARRAY * *ppsaArguments
   , BYVAL SubComponent AS WSTRING _                    ' __in BSTR SubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <131> ( _                       ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *plVersion
   ' =====================================================================================
   PROPERTY SET Version <131> ( _                       ' VTable offset = 164
     BYVAL lVersion AS LONG _                           ' __in long lVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PipelineVersion <132> ( _               ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *plVersion
   ' =====================================================================================
   PROPERTY SET PipelineVersion <132> ( _               ' VTable offset = 172
     BYVAL lVersion AS LONG _                           ' __in long lVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContactInfo <133> ( _                   ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContactInfo
   ' =====================================================================================
   PROPERTY SET ContactInfo <133> ( _                   ' VTable offset = 180
     BYVAL bstrContactInfo AS WSTRING _                 ' __in BSTR bstrContactInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD FireProgress <134> ( _                        ' VTable offset = 184
     BYVAL bstrProgressDescription AS WSTRING _         ' __in BSTR bstrProgressDescription
   , BYVAL lPercentComplete AS LONG _                   ' __in long lPercentComplete
   , BYVAL lProgressCountLow AS LONG _                  ' __in long lProgressCountLow
   , BYVAL lProgressCountHigh AS LONG _                 ' __in long lProgressCountHigh
   , BYVAL bstrSubComponent AS WSTRING _                ' __in BSTR bstrSubComponent
   , BYREF pbFireAgain AS INTEGER _                     ' __inout VARIANT_BOOL *pbFireAgain
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSComponentMetaData90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSComponentView90
' IID = {F9013912-2CEC-47C4-BF25-F9D404C4E88A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSComponentView90_INTERFACE_DEFINED)
    %IDTSComponentView90_INTERFACE_DEFINED = 1

INTERFACE IDTSComponentView90 $IID_IDTSComponentView90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Commit <101> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel <102> ( _                              ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSComponentView90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSDesigntimeComponent90
' IID = {76F19268-BCE0-4A23-95D1-F85AC738941D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSDesigntimeComponent90_INTERFACE_DEFINED)
    %IDTSDesigntimeComponent90_INTERFACE_DEFINED = 1

INTERFACE IDTSDesigntimeComponent90 $IID_IDTSDesigntimeComponent90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ProvideComponentProperties <11> ( _           ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ReinitializeMetaData <12> ( _                 ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertOutputColumnAt <13> ( _                 ' VTable offset = 36
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnIndex AS LONG _                 ' __in long lOutputColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD DeleteOutputColumn <14> ( _                   ' VTable offset = 40
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDeletingInputColumn <15> ( _                ' VTable offset = 44
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetUsageType <16> ( _                         ' VTable offset = 48
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL pIDTSVirtualInputObject AS IDTSVirtualInput90 _ ' __in IDTSVirtualInput90 *pIDTSVirtualInputObject
   , BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   , BYVAL eUsageType AS LONG _                         ' __in enum DTSUsageType eUsageType
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD SetComponentProperty <17> ( _                 ' VTable offset = 52
     BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD SetInputProperty <18> ( _                     ' VTable offset = 56
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD SetOutputProperty <19> ( _                    ' VTable offset = 60
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD SetInputColumnProperty <20> ( _               ' VTable offset = 64
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD SetOutputColumnProperty <21> ( _              ' VTable offset = 68
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD InsertInput <22> ( _                          ' VTable offset = 72
     BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD InsertOutput <23> ( _                         ' VTable offset = 76
     BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD DeleteInput <24> ( _                          ' VTable offset = 80
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteOutput <25> ( _                         ' VTable offset = 84
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD OnInputPathDetached <26> ( _                  ' VTable offset = 88
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD OnInputPathAttached <27> ( _                  ' VTable offset = 92
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD OnOutputPathAttached <28> ( _                 ' VTable offset = 96
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD Validate <29> ( _                             ' VTable offset = 100
   ) AS LONG                                            ' __retval_out enum DTSValidationStatus *peValidationStatus
   ' =====================================================================================
   METHOD AcquireConnections <30> ( _                   ' VTable offset = 104
     BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   )                                                    ' void
   ' =====================================================================================
   METHOD ReleaseConnections <31> ( _                   ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD SetOutputColumnDataTypeProperties <32> ( _    ' VTable offset = 112
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   METHOD MapInputColumn <33> ( _                       ' VTable offset = 116
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD MapOutputColumn <34> ( _                      ' VTable offset = 120
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bMatch AS INTEGER _                          ' __in VARIANT_BOOL bMatch
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD DescribeRedirectedErrorCode <35> ( _          ' VTable offset = 124
     BYVAL hrErrorCode AS LONG _                        ' __in HRESULT hrErrorCode
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================
   METHOD GetEnumerationCollection <36> ( _             ' VTable offset = 128
     BYVAL bstrEnumName AS WSTRING _                    ' __in BSTR bstrEnumName
   ) AS IDTSFriendlyEnumCollection90                    ' __retval_out IDTSFriendlyEnumCollection90 **ppIDTSFriendlyEnumCollection
   ' =====================================================================================
   METHOD InsertExternalMetadataColumnAt <37> ( _       ' VTable offset = 132
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnIndex AS LONG _       ' __in long lExternalMetadataColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD DeleteExternalMetadataColumn <38> ( _         ' VTable offset = 136
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD SetExternalMetadataColumnProperty <39> ( _    ' VTable offset = 140
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYVAL vtValue AS VARIANT _                         ' __in VARIANT vtValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD SetExternalMetadataColumnDataTypeProperties <40> ( _ ' VTable offset = 144
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSDesigntimeComponent90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSRuntimeComponent90
' IID = {AE9DA26D-2AFB-4217-8A4C-49CECC0620FE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSRuntimeComponent90_INTERFACE_DEFINED)
    %IDTSRuntimeComponent90_INTERFACE_DEFINED = 1

INTERFACE IDTSRuntimeComponent90 $IID_IDTSRuntimeComponent90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD PrepareForExecute <12> ( _                    ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD PreExecute <13> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD PrimeOutput <14> ( _                          ' VTable offset = 36
     BYVAL lOutputs AS LONG _                           ' __in long lOutputs
   , BYREF lOutputIDs AS LONG _                         ' __in long lOutputIDs[  ]
   , BYREF pIDTSBufferOutputs AS IDTSBuffer90 _         ' __in IDTSBuffer90 *pIDTSBufferOutputs[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD ProcessInput <15> ( _                         ' VTable offset = 40
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL pIDTSBufferInput AS IDTSBuffer90 _           ' __in IDTSBuffer90 *pIDTSBufferInput
   )                                                    ' void
   ' =====================================================================================
   METHOD PostExecute <16> ( _                          ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Cleanup <17> ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ComponentMetaData <20> ( _              ' VTable offset = 52
     BYVAL pIDTSComponentMetaData AS IDTSComponentMetaData90 _ ' __in IDTSComponentMetaData90 *pIDTSComponentMetaData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET VariableDispenser <21> ( _              ' VTable offset = 56
     BYVAL pIDTSVariableDispenser AS IDTSVariableDispenser90 _  ' __in IDTSVariableDispenser90 *pIDTSVariableDispenser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BufferManager <22> ( _                  ' VTable offset = 60
     BYVAL pIDTSBufferManager AS IDTSBufferManager90 _  ' __in IDTSBufferManager90 *pIDTSBufferManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET EventInfos <23> ( _                     ' VTable offset = 64
     BYVAL pEventInfos AS IDTSEventInfos90 _            ' __in IDTSEventInfos90 *pEventInfos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ReferenceTracker <24> ( _               ' VTable offset = 68
     BYVAL pRefTracker AS IDTSObjectReferenceTracker90 _ ' __in IDTSObjectReferenceTracker90 *pRefTracker
   )                                                    ' void
   ' =====================================================================================
   METHOD PerformUpgrade <25> ( _                       ' VTable offset = 72
     BYVAL lPipelineVersion AS LONG _                   ' __in long lPipelineVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET LogEntryInfos <26> ( _                  ' VTable offset = 76
     BYVAL pLogEntryInfos AS IDTSLogEntryInfos90 _      ' __in IDTSLogEntryInfos90 *pLogEntryInfos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequiredProductLevel <27> ( _           ' VTable offset = 80
   ) AS LONG                                            ' __retval_out DTSProductLevel *peProductLevel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSRuntimeComponent90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedComponentWrapper90
' IID = {025B7E3E-EAD0-4C51-AE5A-554FCB89995A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSManagedComponentWrapper90_INTERFACE_DEFINED)
    %IDTSManagedComponentWrapper90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedComponentWrapper90 $IID_IDTSManagedComponentWrapper90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AddBLOBData ( _                               ' VTable offset = 12
     BYVAL pIDTSBuffer AS IDTSBuffer90 _                ' __in IDTSBuffer90 *pIDTSBuffer
   , BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF ppsaData AS DWORD _                          ' __in SAFEARRAY * *ppsaData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBLOBData ( _                               ' VTable offset = 16
     BYVAL pIDTSBuffer AS IDTSBuffer90 _                ' __in IDTSBuffer90 *pIDTSBuffer
   , BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *ppsaData
   ' =====================================================================================
   METHOD WrapperProvideComponentProperties ( _         ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperReinitializeMetaData ( _               ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperInsertOutputColumnAt ( _               ' VTable offset = 28
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnIndex AS LONG _                 ' __in long lOutputColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD WrapperDeleteOutputColumn ( _                 ' VTable offset = 32
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperOnDeletingInputColumn ( _              ' VTable offset = 36
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperSetUsageType ( _                       ' VTable offset = 40
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL pIDTSVirtualInputObject AS IDTSVirtualInput90 _ ' __in IDTSVirtualInput90 *pIDTSVirtualInputObject
   , BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   , BYVAL eUsageType AS LONG _                         ' __in enum DTSUsageType eUsageType
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD WrapperSetComponentProperty ( _               ' VTable offset = 44
     BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperSetInputProperty ( _                   ' VTable offset = 48
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperSetOutputProperty ( _                  ' VTable offset = 52
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperSetInputColumnProperty ( _             ' VTable offset = 56
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperSetOutputColumnProperty ( _            ' VTable offset = 60
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperInsertInput ( _                        ' VTable offset = 64
     BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD WrapperInsertOutput ( _                       ' VTable offset = 68
     BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD WrapperDeleteInput ( _                        ' VTable offset = 72
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperDeleteOutput ( _                       ' VTable offset = 76
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperOnInputPathDetached ( _                ' VTable offset = 80
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperOnInputPathAttached ( _                ' VTable offset = 84
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperOnOutputPathAttached ( _               ' VTable offset = 88
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperValidate ( _                           ' VTable offset = 92
   ) AS LONG                                            ' __retval_out enum DTSValidationStatus *peValidationStatus
   ' =====================================================================================
   METHOD WrapperAcquireConnections ( _                 ' VTable offset = 96
     BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperReleaseConnections ( _                 ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperSetOutputColumnDataTypeProperties ( _  ' VTable offset = 104
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperMapInputColumn ( _                     ' VTable offset = 108
     BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL ppIDTSExternalMetadataColumn AS LONG _       ' __in long lExternalMetadataColumnID
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD WrapperMapOutputColumn ( _                    ' VTable offset = 112
     BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bMatch AS INTEGER _                          ' __in VARIANT_BOOL bMatch
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD WrapperDescribeRedirectedErrorCode ( _        ' VTable offset = 116
     BYVAL hrErrorCode AS LONG _                        ' __in HRESULT hrErrorCode
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================
   METHOD WrapperInsertExternalMetadataColumnAt ( _     ' VTable offset = 120
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnIndex AS LONG _       ' __in long lExternalMetadataColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD WrapperDeleteExternalMetadataColumn ( _       ' VTable offset = 124
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD WrapperSetExternalMetadataColumnProperty ( _  ' VTable offset = 128
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYVAL vtValue AS VARIANT _                         ' __in VARIANT vtValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD WrapperSetExternalMetadataColumnDataTypeProperties ( _ ' VTable offset = 132
     BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedComponentWrapper90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedComponentHost90
' IID = {C4C51533-E6CA-43F3-AE3A-32983E1EA33C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSManagedComponentHost90_INTERFACE_DEFINED)
    %IDTSManagedComponentHost90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedComponentHost90 $IID_IDTSManagedComponentHost90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Instantiate ( _                               ' VTable offset = 12
     BYVAL bstrUserComponentTypeName AS WSTRING _       ' __in BSTR bstrUserComponentTypeName
   , BYVAL pComponentMetaData AS IDTSComponentMetaData90 _ ' __in IDTSComponentMetaData90 *pComponentMetaData
   , BYVAL pVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pVariableDispenser
   , BYVAL pBufferManager AS IDTSBufferManager90 _      ' __in IDTSBufferManager90 *pBufferManager
   , BYVAL pEventInfos AS IDTSEventInfos90 _            ' __in IDTSEventInfos90 *pEventInfos
   , BYVAL pRefTracker AS IDTSObjectReferenceTracker90 _ ' __in IDTSObjectReferenceTracker90 *pRefTracker
   , BYVAL pLogEntryInfos AS IDTSLogEntryInfos90 _      ' __in IDTSLogEntryInfos90 *pLogEntryInfos
   , BYREF LONG _                                       ' __out DTSProductLevel *peProductLevel
   )                                                    ' void
   ' =====================================================================================
   METHOD HostPrepareForExecute ( _                     ' VTable offset = 16
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostPreExecute ( _                            ' VTable offset = 20
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostPrimeOutput ( _                           ' VTable offset = 24
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputs AS LONG _                           ' __in long lOutputs
   , BYVAL psaOutputIDs AS DWORD _                      ' __in SAFEARRAY * psaOutputIDs
   , BYVAL psaBuffers AS DWORD _                        ' __in SAFEARRAY * psaBuffers
   , BYVAL ppBufferPacket AS DWORD _                    ' __in void *ppBufferPacket
   )                                                    ' void
   ' =====================================================================================
   METHOD HostProcessInput ( _                          ' VTable offset = 28
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL pDTSBuffer AS IDTSBuffer90 _                 ' __in IDTSBuffer90 *pDTSBuffer
   , BYVAL pBufferPacket AS DWORD _                     ' __in void *pBufferPacket
   )                                                    ' void
   ' =====================================================================================
   METHOD HostPostExecute ( _                           ' VTable offset = 32
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostCleanup ( _                               ' VTable offset = 36
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostCheckAndPerformUpgrade ( _                ' VTable offset = 40
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL LONG _                                       ' __in long lPipelineVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD HostProvideComponentProperties ( _            ' VTable offset = 44
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostReinitializeMetaData ( _                  ' VTable offset = 48
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostInsertOutputColumnAt ( _                  ' VTable offset = 52
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnIndex AS LONG _                 ' __in long lOutputColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSOutputColumn90                              ' __retval_out IDTSOutputColumn90 **ppIDTSOutputColumn
   ' =====================================================================================
   METHOD HostDeleteOutputColumn ( _                    ' VTable offset = 56
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostOnDeletingInputColumn ( _                 ' VTable offset = 60
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostSetUsageType ( _                          ' VTable offset = 64
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL pIDTSVirtualInputObject AS IDTSVirtualInput90 _ ' __in IDTSVirtualInput90 *pIDTSVirtualInputObject
   , BYVAL lLineageID AS LONG _                         ' __in long lLineageID
   , BYVAL eUsageType AS LONG _                         ' __in enum DTSUsageType eUsageType
   ) AS IDTSInputColumn90                               ' __retval_out IDTSInputColumn90 **ppIDTSInputColumn
   ' =====================================================================================
   METHOD HostSetComponentProperty ( _                  ' VTable offset = 68
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostSetInputProperty ( _                      ' VTable offset = 72
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostSetOutputProperty ( _                     ' VTable offset = 76
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostSetInputColumnProperty ( _                ' VTable offset = 80
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostSetOutputColumnProperty ( _               ' VTable offset = 84
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   , BYVAL vValue AS VARIANT _                          ' __in VARIANT vValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostInsertInput ( _                           ' VTable offset = 88
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   METHOD HostInsertOutput ( _                          ' VTable offset = 92
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL eInsertPlacement AS LONG _                   ' __in enum DTSInsertPlacement eInsertPlacement
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   METHOD HostDeleteInput ( _                           ' VTable offset = 96
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostDeleteOutput ( _                          ' VTable offset = 100
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostOnInputPathDetached ( _                   ' VTable offset = 104
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostOnInputPathAttached ( _                   ' VTable offset = 108
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostOnOutputPathAttached ( _                  ' VTable offset = 112
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostValidate ( _                              ' VTable offset = 116
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   ) AS LONG                                            ' __retval_out enum DTSValidationStatus *peValidationStatus
   ' =====================================================================================
   METHOD HostAcquireConnections ( _                    ' VTable offset = 120
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL pTransaction AS IUnknown _                   ' __in IUnknown *pTransaction
   )                                                    ' void
   ' =====================================================================================
   METHOD HostReleaseConnections ( _                    ' VTable offset = 124
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   )                                                    ' void
   ' =====================================================================================
   METHOD HostSetOutputColumnDataTypeProperties ( _     ' VTable offset = 128
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   METHOD HostMapInputColumn ( _                        ' VTable offset = 132
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lInputID AS LONG _                           ' __in long lInputID
   , BYVAL lInputColumnID AS LONG _                     ' __in long lInputColumnID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD HostMapOutputColumn ( _                       ' VTable offset = 136
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lOutputColumnID AS LONG _                    ' __in long lOutputColumnID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bMatch AS INTEGER _                          ' __in VARIANT_BOOL bMatch
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD HostDescribeRedirectedErrorCode ( _           ' VTable offset = 140
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL hrErrorCode AS LONG _                        ' __in HRESULT hrErrorCode
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDesc
   ' =====================================================================================
   METHOD HostInsertExternalMetadataColumnAt ( _        ' VTable offset = 144
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnIndex AS LONG _       ' __in long lExternalMetadataColumnIndex
   , BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out */ IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD HostDeleteExternalMetadataColumn ( _          ' VTable offset = 148
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   )                                                    ' void
   ' =====================================================================================
   METHOD HostSetExternalMetadataColumnProperty ( _     ' VTable offset = 152
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   , BYVAL vtValue AS VARIANT _                         ' __in VARIANT vtValue
   ) AS IDTSCustomProperty90                            ' __retval_out IDTSCustomProperty90 **ppIDTSCustomProperty
   ' =====================================================================================
   METHOD HostSetExternalMetadataColumnDataTypeProperties ( _ ' VTable offset = 156
     BYVAL pWrapper AS IDTSManagedComponentWrapper90 _  ' __in IDTSManagedComponentWrapper90 *pWrapper
   , BYVAL lID AS LONG _                                ' __in long lID
   , BYVAL lExternalMetadataColumnID AS LONG _          ' __in long lExternalMetadataColumnID
   , BYVAL eDataType AS LONG _                          ' __in DataType eDataType
   , BYVAL lLength AS LONG _                            ' __in long lLength
   , BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   , BYVAL lScale AS LONG _                             ' __in long lScale
   , BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostComponentMetaData ( _               ' VTable offset = 160
     BYVAL pIDTSComponentMetaData AS IDTSComponentMetaData90 _ ' __in IDTSComponentMetaData90 *pIDTSComponentMetaData
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostVariableDispenser ( _               ' VTable offset = 164
     BYVAL pIDTSVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pIDTSVariableDispenser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostBufferManager ( _                   ' VTable offset = 168
     BYVAL pIDTSBufferManager AS IDTSBufferManager90 _  ' __in IDTSBufferManager90 *pIDTSBufferManager
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostEventInfos ( _                      ' VTable offset = 172
     BYVAL pIDTSEventInfos AS IDTSEventInfos90 _        ' __in IDTSEventInfos90 *pIDTSEventInfos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostReferenceTracker ( _                ' VTable offset = 176
     BYVAL pIDTSObjectReferenceTracker AS IDTSObjectReferenceTracker90 _ ' __in IDTSObjectReferenceTracker90 *pIDTSObjectReferenceTracker
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET HostLogEntryInfos ( _                   ' VTable offset = 180
     BYVAL pIDTSLogEntryInfos AS IDTSLogEntryInfos90 _  ' __in IDTSLogEntryInfos90 *pIDTSLogEntryInfos
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedComponentHost90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSManagedComponent90
' IID = {E5C32A7C-AFA2-49CA-AF4E-4952A0B76202}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSManagedComponent90_INTERFACE_DEFINED)
    %IDTSManagedComponent90_INTERFACE_DEFINED = 1

INTERFACE IDTSManagedComponent90 $IID_IDTSManagedComponent90

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET InnerObject ( _                         ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out Iunknown **ppInnerObject
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSManagedComponent90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSComponentMetaDataCollection90
' IID = {9BE05B44-D46B-4879-9A50-ED3C72E5F347}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSComponentMetaDataCollection90_INTERFACE_DEFINED)
    %IDTSComponentMetaDataCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSComponentMetaDataCollection90 $IID_IDTSComponentMetaDataCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSComponentMetaData90                         ' __retval_out IDTSComponentMetaData90 **ppIDTSComponentMetaData
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSComponentMetaDataCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExternalMetadataColumnCollection90
' IID = {CC6D94F9-F447-4445-AB36-D786D7A21CB3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSExternalMetadataColumnCollection90_INTERFACE_DEFINED)
    %IDTSExternalMetadataColumnCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSExternalMetadataColumnCollection90 $IID_IDTSExternalMetadataColumnCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL VARIANT _                                    ' __in VARIANT Index
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSExternalMetadataColumn90                    ' __retval_out IDTSExternalMetadataColumn90 **ppIDTSExternalMetadataColumn
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   PROPERTY GET IsUsed <101> ( _                        ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsUsed
   ' =====================================================================================
   PROPERTY SET IsUsed <101> ( _                        ' VTable offset = 84
     BYVAL bIsUsed AS INTEGER _                         ' __in VARIANT_BOOL bIsUsed
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExternalMetadataColumnCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSExternalMetadataColumn90
' IID = {DF519267-8084-482A-94C7-2B8E6052E1FB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSExternalMetadataColumn90_INTERFACE_DEFINED)
    %IDTSExternalMetadataColumn90_INTERFACE_DEFINED = 1

INTERFACE IDTSExternalMetadataColumn90 $IID_IDTSExternalMetadataColumn90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSExternalMetadataColumn90 Methods
   ' =====================================================================================
   PROPERTY GET DataType <101> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DataType *peDataType
   ' =====================================================================================
   PROPERTY SET DataType <101> ( _                      ' VTable offset = 64
     BYVAL eDataType AS LONG _                          ' __in eDataType *DataType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Length <102> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plLength
   ' =====================================================================================
   PROPERTY SET Length <102> ( _                        ' VTable offset = 72
     BYVAL lLength AS LONG _                            ' __in long lLength
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Precision <103> ( _                     ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plPrecision
   ' =====================================================================================
   PROPERTY SET Precision <103> ( _                     ' VTable offset = 80
     BYVAL lPrecision AS LONG _                         ' __in long lPrecision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scale <104> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plScale
   ' =====================================================================================
   PROPERTY SET Scale <104> ( _                         ' VTable offset = 88
     BYVAL lScale AS LONG _                             ' __in long lScale
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CodePage <105> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plCodePage
   ' =====================================================================================
   PROPERTY SET CodePage <105> ( _                      ' VTable offset = 96
     BYVAL lCodePage AS LONG _                          ' __in long lCodePage
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomPropertyCollection <106> ( _      ' VTable offset = 100
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSExternalMetadataColumn90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSFriendlyEnumCollection90
' IID = {72BA2210-2BBB-4A5C-8557-C32B4554605A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSFriendlyEnumCollection90_INTERFACE_DEFINED)
    %IDTSFriendlyEnumCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSFriendlyEnumCollection90 $IID_IDTSFriendlyEnumCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSFriendlyEnum90                              ' __retval_out IDTSFriendlyEnum90 **ppIDTSFriendlyEnum
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET IsFlags <101> ( _                       ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsFlags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSFriendlyEnumCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSFriendlyEnum90
' IID = {32870502-FA13-4B2D-93D9-2F3A017DF045}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSFriendlyEnum90_INTERFACE_DEFINED)
    %IDTSFriendlyEnum90_INTERFACE_DEFINED = 1

INTERFACE IDTSFriendlyEnum90 $IID_IDTSFriendlyEnum90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFriendlyName
   ' =====================================================================================
   PROPERTY GET Value <101> ( _                         ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plEnumValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSFriendlyEnum90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPathCollection90
' IID = {054A07E8-BC68-4B40-8804-92066974535D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPathCollection90_INTERFACE_DEFINED)
    %IDTSPathCollection90_INTERFACE_DEFINED = 1

INTERFACE IDTSPathCollection90 $IID_IDTSPathCollection90

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   ) AS IDTSPath90                                      ' __retval_out IDTSPath90 **ppIDTSPath
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out IUnknown **ppIUnknownEnum
   ' =====================================================================================
   PROPERTY GET Count <13> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD New <14> ( _                                  ' VTable offset = 40
   ) AS IDTSPath90                                      ' __retval_out IDTSPath90 **ppIDTSPath
   ' =====================================================================================
   METHOD NewAt <15> ( _                                ' VTable offset = 44
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS IDTSPath90                                      ' __retval_out IDTSPath90 **ppIDTSPath
   ' =====================================================================================
   METHOD RemoveObjectByIndex <16> ( _                  ' VTable offset = 48
     BYVAL Index AS VARIANT _                           ' __in VARIANT Index
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveObjectByID <17> ( _                     ' VTable offset = 52
     BYVAL lID AS LONG _                                ' __in long lID
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAll <18> ( _                            ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD SetIndex <19> ( _                             ' VTable offset = 60
     BYVAL lOldIndex AS LONG _                          ' __in long lOldIndex
   , BYVAL lNewIndex AS LONG _                          ' __in long lNewIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD GetObjectByID <20> ( _                        ' VTable offset = 64
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSPath90                                      ' __retval_out IDTSPath90 **ppIDTSPath
   ' =====================================================================================
   METHOD GetObjectIndexByID <21> ( _                   ' VTable offset = 68
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================
   METHOD FindObjectByID <22> ( _                       ' VTable offset = 72
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSPath90                                      ' __retval_out IDTSPath90 **ppIDTSPath
   ' =====================================================================================
   METHOD FindObjectIndexByID <23> ( _                  ' VTable offset = 76
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS LONG                                            ' __retval_out long *plIndex
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPathCollection90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBuffer90
' IID = {DF81E1A6-6D91-498A-8689-0BD75916697D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDTSBuffer90_INTERFACE_DEFINED)
    %IDTSBuffer90_INTERFACE_DEFINED = 1

INTERFACE IDTSBuffer90 $IID_IDTSBuffer90

   INHERIT IAutomation

   ' =====================================================================================
   METHOD DirectRow ( _                                 ' VTable offset = 12
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveRow ( _                                   ' VTable offset = 16
     BYVAL hFrom AS LONG _                              ' __in DTP_HROW hFrom
   , BYVAL hTo AS LONG _                                ' __in DTP_HROW hTo
   )                                                    ' void
   ' =====================================================================================
   METHOD SwapRows ( _                                  ' VTable offset = 20
     BYVAL hOne AS LONG _                               ' __in DTP_HROW hOne
   , BYVAL hOther AS LONG _                             ' __in DTP_HROW hOther
   )                                                    ' void
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' __retval_out DTP_HBUFFERTYPE *phBufferType
   ' =====================================================================================
   METHOD LockData ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD UnlockData ( _                                ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRowCount ( _                               ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out DWORD *pdwRowCount
   ' =====================================================================================
   METHOD GetColumnCount ( _                            ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out DWORD *pdwColumnCount
   ' =====================================================================================
   METHOD GetColumnInfo ( _                             ' VTable offset = 44
     BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pCol AS DTP_BUFFCOL _                        ' __inout DTP_BUFFCOL *pCol
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBoundaryInfo ( _                           ' VTable offset = 48
     BYREF pdwCols AS DWORD _                           ' __out DWORD *pdwCols
   , BYREF pdwMaxRows AS DWORD _                        ' __out DWORD *pdwMaxRows
   )                                                    ' void
   ' =====================================================================================
   METHOD AddRow ( _                                    ' VTable offset = 52
     BYREF ppRowStart AS DWORD _                        ' __inout BYTE **ppRowStart
   ) AS LONG                                            ' __retval_out DTP_HROW *phRow
   ' =====================================================================================
   METHOD RemoveRow ( _                                 ' VTable offset = 56
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   )                                                    ' void
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out DTP_HBUFFER *phID
   ' =====================================================================================
   METHOD GetManager ( _                                ' VTable offset = 64
   ) AS IDTSBufferManager90                             ' __retval_out IDTSBufferManager90 **ppManager
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 68
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   ) AS DTP_VARIANT                                     ' __retval_out DTP_VARIANT *pData
   ' =====================================================================================
   METHOD GetDataByRef ( _                              ' VTable offset = 72
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   ) AS DTP_VARIANT                                     ' __retval_out DTP_VARIANT *pData
   ' =====================================================================================
   METHOD SetData ( _                                   ' VTable offset = 76
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pData AS DTP_VARIANT _                       ' __in PDTP_VARIANT pData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBLOBLength ( _                             ' VTable offset = 80
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pdwBytes AS DWORD _                          ' __out DWORD *pdwBytes
   )                                                    ' void
   ' =====================================================================================
   METHOD AddBLOBData ( _                               ' VTable offset = 84
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL lpData AS BYTE PTR _                         ' __in BYTE *lpData
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBLOBData ( _                               ' VTable offset = 88
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL lpPointer AS BYTE PTR _                      ' __in BYTE *lpPointer
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   , BYREF lpdwWritten AS DWORD _                       ' __out DWORD *lpdwWritten
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBLOBStream ( _                             ' VTable offset = 92
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   ) AS IStream                                         ' __retval_out IStream **pIStream
   ' =====================================================================================
   METHOD SetBLOBFromStream ( _                         ' VTable offset = 96
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL pIStream AS ISequentialStream _              ' __in ISequentialStream *pIStream
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetBLOBData ( _                             ' VTable offset = 100
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   )                                                    ' void
   ' =====================================================================================
   METHOD SetBLOBFromObject ( _                         ' VTable offset = 104
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL pIDTSBLOBObject AS IDTSBLOBObject90 _        ' __in IDTSBLOBObject90 *pIDTSBLOBObject
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBLOBObject ( _                             ' VTable offset = 108
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   ) AS IDTSBLOBObject90                                ' __retval_out IDTSBLOBObject90 **ppIDTSBLOBObject
   ' =====================================================================================
   METHOD IsNull ( _                                    ' VTable offset = 112
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pfNull AS INTEGER _                          ' __inout VARIANT_BOOL *pfNull
   )                                                    ' void
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 116
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYVAL dbStatus AS DWORD _                          ' __in DTPSTATUS dbStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 120
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pDBStatus AS DWORD _                         ' __out DTPSTATUS *pDBStatus
   )                                                    ' void
   ' =====================================================================================
   METHOD PrepareDataStatusForInsert ( _                ' VTable offset = 124
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEndOfRowset ( _                            ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD IsEndOfRowset ( _                             ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEOR
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 136
     BYVAL pOwner AS IDTSComponentMetaData90 _          ' __in IDTSComponentMetaData90 *pOwner
   ) AS IDTSBuffer90                                    ' __retval_out IDTSBuffer90 **ppNewBuffer
   ' =====================================================================================
   METHOD GetRowDataBytes ( _                           ' VTable offset = 140
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYREF plCB AS LONG _                               ' __out long *plCB
   , BYREF pData AS DWORD _                             ' __out BYTE **pData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRowStarts ( _                              ' VTable offset = 144
     BYVAL dwRowsRequested AS DWORD _                   ' __in DWORD dwRowsRequested
   , BYREF pbRowStarts AS DWORD _                       ' __out BYTE *pbRowStarts[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD DirectErrorRow ( _                            ' VTable offset = 148
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lErrorCode AS LONG _                         ' __in long lErrorCode
   , BYVAL lErrorColumn AS LONG _                       ' __in long lErrorColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD SetErrorInfo ( _                              ' VTable offset = 152
     BYVAL hRow AS LONG _                               ' __in DTP_HROW hRow
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   , BYVAL lErrorCode AS LONG _                         ' __in long lErrorCode
   , BYVAL lErrorColumn AS LONG _                       ' __in long lErrorColumn
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFlatMemory ( _                             ' VTable offset = 156
   ) AS DWORD                                           ' __retval_out BYTE **pBuffer
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBuffer90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSBufferManager90
' IID = {E6918F3C-06DC-46CC-AE4D-3AF12F5B0E25}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSBufferManager90_INTERFACE_DEFINED)
    %IDTSBufferManager90_INTERFACE_DEFINED = 1

INTERFACE IDTSBufferManager90 $IID_IDTSBufferManager90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RegisterBufferType <101> ( _                  ' VTable offset = 28
     BYVAL cCols AS LONG _                              ' __in int cCols
   , BYREF rgCols AS DTP_BUFFCOL _                      ' __in DTP_BUFFCOL rgCols[  ]
   , BYVAL lMaxRows AS LONG _                           ' __in LONG lMaxRows
   , BYVAL dwCreationFlags AS DWORD _                   ' __in DWORD dwCreationFlags
   ) AS LONG                                            ' __retval_out DTP_HBUFFERTYPE *phBufferType
   ' =====================================================================================
   METHOD RegisterLineageIDs <103> ( _                  ' VTable offset = 32
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   , BYVAL cCols AS LONG _                              ' __in int cCols
   , BYREF lLineageIDs AS LONG _                        ' __in long lLineageIDs[  ]
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateVirtualBuffer <108> ( _                 ' VTable offset = 36
     BYVAL hSourceBuffer AS LONG _                      ' __in DTP_HBUFFERTYPE hSourceBuffer
   , BYVAL lOutputID AS LONG _                          ' __in long lOutputID
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateFlatBuffer <112> ( _                    ' VTable offset = 40
     BYVAL lSize AS LONG _                              ' __in LONG lSize
   , BYVAL pOwner AS IDTSComponentMetaData90 _          ' __in IDTSComponentMetaData90 *pOwner
   ) AS IDTSBuffer90                                    ' __retval_out IDTSBuffer90 **ppBuffer
   ' =====================================================================================
   METHOD CreateBuffer <109> ( _                        ' VTable offset = 44
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   , BYVAL pOwner AS IDTSComponentMetaData90 _          ' __in IDTSComponentMetaData90 *pOwner
   ) AS IDTSBuffer90                                    ' __retval_out IDTSBuffer90 **ppBuffer
   ' =====================================================================================
   METHOD FindColumnByLineageID <121> ( _               ' VTable offset = 48
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   , BYVAL nLineageID AS LONG _                         ' __in LONG nLineageID
   ) AS LONG                                            ' __retval_out DTP_HCOL *pwColIndex
   ' =====================================================================================
   METHOD GetColumnInfo <122> ( _                       ' VTable offset = 52
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   , BYVAL hCol AS LONG _                               ' __in DTP_HCOL hCol
   , BYREF pCol AS DTP_BUFFCOL _                        ' __inout DTP_BUFFCOL *pCol
   )                                                    ' void
   ' =====================================================================================
   METHOD GetColumnCount <123> ( _                      ' VTable offset = 56
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   ) AS DWORD                                           ' __retval_out DWORD *pdwColumnCount
   ' =====================================================================================
   METHOD GetRowWidth <125> ( _                         ' VTable offset = 60
     BYVAL hBufferType AS LONG _                        ' __in DTP_HBUFFERTYPE hBufferType
   ) AS LONG                                            ' __retval_out long *plSizeInBytes
   ' =====================================================================================
   METHOD GetBLOBObject <130> ( _                       ' VTable offset = 64
     BYREF ppNewObject AS IDTSBLOBObject90 _            ' IDTSBLOBObject90 **ppNewObject
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSBufferManager90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSObjectModel90
' IID = {849596FD-555F-450D-942C-E4E39AF73583}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSObjectModel90_INTERFACE_DEFINED)
    %IDTSObjectModel90_INTERFACE_DEFINED = 1

INTERFACE IDTSObjectModel90 $IID_IDTSObjectModel90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD New <11> ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ComponentMetaDataCollection <12> ( _    ' VTable offset = 32
   ) AS IDTSComponentMetaDataCollection90               ' __retval_out IDTSComponentMetaDataCollection90 **ppIDTSComponentMetaDataCollection
   ' =====================================================================================
   PROPERTY GET PathCollection <13> ( _                 ' VTable offset = 36
   ) AS IDTSPathCollection90                            ' __retval_out IDTSPathCollection90 **ppIDTSPathCollection
   ' =====================================================================================
   METHOD GetObjectByID <14> ( _                        ' VTable offset = 40
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSObject90                                    ' __retval_out IDTSObject90 **ppIDTSObject
   ' =====================================================================================
   PROPERTY GET AutoGenerateIDForNewObjects <15> ( _    ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAutoGenerateIDForNewObjects
   ' =====================================================================================
   PROPERTY SET AutoGenerateIDForNewObjects <15> ( _    ' VTable offset = 48
     BYVAL bAutoGenerateIDForNewObjects AS INTEGER _    ' __in VARIANT_BOOL bAutoGenerateIDForNewObjects
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSObjectModel90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPath90
' IID = {CBEA73B4-08DA-4FE7-A03A-829345CAEB84}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObject90
' ########################################################################################

#IF NOT %DEF(%IDTSPath90_INTERFACE_DEFINED)
    %IDTSPath90_INTERFACE_DEFINED = 1

INTERFACE IDTSPath90 $IID_IDTSPath90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObject90 Methods
   ' =====================================================================================
   PROPERTY GET ID <11> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pID
   ' =====================================================================================
   PROPERTY SET ID <11> ( _                             ' VTable offset = 32
     BYVAL ID AS LONG _                                 ' __in long ID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <12> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDescription
   ' =====================================================================================
   PROPERTY SET Description <12> ( _                    ' VTable offset = 40
     BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <13> ( _                           ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET Name <13> ( _                           ' VTable offset = 48
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ObjectType <14> ( _                     ' VTable offset = 52
   ) AS LONG                                            ' __retval_out enum DTSObjectType *pType
   ' =====================================================================================
   PROPERTY GET IdentificationString <15> ( _           ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIdentificationString
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSPath90 Methods
   ' =====================================================================================
   PROPERTY GET StartPoint <101> ( _                    ' VTable offset = 60
   ) AS IDTSOutput90                                    ' __retval_out IDTSOutput90 **ppIDTSOutput
   ' =====================================================================================
   PROPERTY SET StartPoint <101> ( _                    ' VTable offset = 64
     BYVAL pIDTSOutput AS IDTSOutput90 _                ' __in IDTSOutput90 *pIDTSOutput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndPoint <102> ( _                      ' VTable offset = 68
   ) AS IDTSInput90                                     ' __retval_out IDTSInput90 **ppIDTSInput
   ' =====================================================================================
   PROPERTY SET EndPoint <102> ( _                      ' VTable offset = 72
     BYVAL pIDTSInput AS IDTSInput90 _                  ' __in IDTSInput90 *pIDTSInput
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachPathAndPropagateNotifications <104> ( _ ' VTable offset = 76
     BYVAL pIDTSOutput AS IDTSOutput90 _                ' __in IDTSOutput90 *pIDTSOutput
   , BYVAL pIDTSInput AS IDTSInput90 _                  ' __in IDTSInput90 *pIDTSInput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Visualized <105> ( _                    ' VTable offset = 80
     BYVAL bVisualized AS INTEGER _                     ' __in VARIANT_BOOL bVisualized
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPath90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPersistenceComponent90
' IID = {3CF1B168-00E1-4818-8713-6CE11991732E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDTSPersistenceComponent90_INTERFACE_DEFINED)
    %IDTSPersistenceComponent90_INTERFACE_DEFINED = 1

INTERFACE IDTSPersistenceComponent90 $IID_IDTSPersistenceComponent90

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Load <11> ( _                                 ' VTable offset = 28
     BYVAL pIDTSObjectModel AS IDTSObjectModel90 _      ' __in IDTSObjectModel90 *pIDTSObjectModel
   , BYVAL pIDTSCustomPropertyCollection AS IDTSCustomPropertyCollection90 _             ' __in IDTSCustomPropertyCollection90 *pIDTSCustomPropertyCollection
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <12> ( _                                 ' VTable offset = 32
     BYVAL pIDTSObjectModel AS IDTSObjectModel90 _      ' __in IDTSObjectModel90 *pIDTSObjectModel
   , BYVAL pIDTSCustomPropertyCollection AS IDTSCustomPropertyCollection90 _             ' __in IDTSCustomPropertyCollection90 *pIDTSCustomPropertyCollection
   )                                                    ' void
   ' =====================================================================================
   METHOD ProvidePersistenceProperties <13> ( _         ' VTable offset = 36
     BYVAL pIDTSCustomPropertyCollection AS IDTSCustomPropertyCollection90 _ ' __in IDTSCustomPropertyCollection90 *pIDTSCustomPropertyCollection
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPersistenceComponent90_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDTSPipeline90
' IID = {9D0934EF-FA28-40F2-BF59-AB65C9E780D9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDTSObjectModel90
' ########################################################################################

#IF NOT %DEF(%IDTSPipeline90_INTERFACE_DEFINED)
    %IDTSPipeline90_INTERFACE_DEFINED = 1

INTERFACE IDTSPipeline90 $IID_IDTSPipeline90

   INHERIT IDispatch

   ' =====================================================================================
   ' IDTSObjectModel90 Methods
   ' =====================================================================================
   METHOD New <11> ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ComponentMetaDataCollection <12> ( _    ' VTable offset = 32
   ) AS IDTSComponentMetaDataCollection90               ' __retval_out IDTSComponentMetaDataCollection90 **ppIDTSComponentMetaDataCollection
   ' =====================================================================================
   PROPERTY GET PathCollection <13> ( _                 ' VTable offset = 36
   ) AS IDTSPathCollection90                            ' __retval_out IDTSPathCollection90 **ppIDTSPathCollection
   ' =====================================================================================
   METHOD GetObjectByID <14> ( _                        ' VTable offset = 40
     BYVAL lID AS LONG _                                ' __in long lID
   ) AS IDTSObject90                                    ' __retval_out IDTSObject90 **ppIDTSObject
   ' =====================================================================================
   PROPERTY GET AutoGenerateIDForNewObjects <15> ( _    ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAutoGenerateIDForNewObjects
   ' =====================================================================================
   PROPERTY SET AutoGenerateIDForNewObjects <15> ( _    ' VTable offset = 48
     BYVAL bAutoGenerateIDForNewObjects AS INTEGER _    ' __in VARIANT_BOOL bAutoGenerateIDForNewObjects
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDTSPipeline90 Methods
   ' =====================================================================================
   PROPERTY GET PersistenceCustomPropertyCollection <115> ( _ ' VTable offset = 52
     BYVAL Format AS LONG _                             ' __in enum DTSPersistenceFormat Format
   ) AS IDTSCustomPropertyCollection90                  ' __retval_out IDTSCustomPropertyCollection90 **ppIDTSCustomPropertyCollection
   ' =====================================================================================
   PROPERTY GET BufferManager <116> ( _                 ' VTable offset = 56
   ) AS IDTSBufferManager90                             ' __retval_out IDTSBufferManager90 **ppBufferManager
   ' =====================================================================================
   PROPERTY SET DefaultBufferMaxRows <117> ( _          ' VTable offset = 60
     BYVAL lMaxRows AS LONG _                           ' __in LONG lMaxRows
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultBufferMaxRows <117> ( _          ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *plMaxRows
   ' =====================================================================================
   PROPERTY SET Events <118> ( _                        ' VTable offset = 68
     BYVAL pIDTSEvents AS IDTSComponentEvents90 _       ' __in IDTSComponentEvents90 *pIDTSEvents
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET VariableDispenser <119> ( _             ' VTable offset = 72
     BYVAL pIDTSVariableDispenser AS IDTSVariableDispenser90 _ ' __in IDTSVariableDispenser90 *pIDTSVariableDispenser
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET DefaultBufferSize <120> ( _             ' VTable offset = 76
     BYVAL lDefaultBufferSize AS LONG _                 ' __in LONG lDefaultBufferSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultBufferSize <120> ( _             ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *plDefaultBufferSize
   ' =====================================================================================
   PROPERTY SET BLOBTempStoragePath <121> ( _           ' VTable offset = 84
     BYVAL bstrBLOBTempStoragePath AS WSTRING _         ' __in BSTR bstrBLOBTempStoragePath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BLOBTempStoragePath <121> ( _           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBLOBTempStoragePath
   ' =====================================================================================
   PROPERTY SET BufferTempStoragePath <122> ( _         ' VTable offset = 92
     BYVAL bstrBufferTempStoragePath AS WSTRING _       ' __in BSTR bstrBufferTempStoragePath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BufferTempStoragePath <122> ( _         ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrBufferTempStoragePath
   ' =====================================================================================
   PROPERTY SET RunInOptimizedMode <124> ( _            ' VTable offset = 100
     BYVAL bRunInOptimizedMode AS INTEGER _             ' __in VARIANT_BOOL bRunInOptimizedMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RunInOptimizedMode <124> ( _            ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRunInOptimizedMode
   ' =====================================================================================
   PROPERTY SET EngineThreads <125> ( _                 ' VTable offset = 108
     BYVAL lEngineThreads AS LONG _                    ' __in LONG lEngineThreads
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EngineThreads <125> ( _                 ' VTable offset = 112
   ) AS LONG                                            ' __retval_out LONG *lEngineThreads
   ' =====================================================================================
   METHOD GetNextPasteID <126> ( _                      ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plNextID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDTSPipeline90_INTERFACE_DEFINED__ */
