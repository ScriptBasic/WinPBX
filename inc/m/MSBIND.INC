' ########################################################################################
' Microsoft Windows
' File: MSBind.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSBind
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft Data Binding Collection VB 6.0 (SP4)
' Path: C:\WINDOWS\system32\MSBIND.DLL
' Library GUID: {56BF9020-7A2F-11D0-9482-00A0C91110ED}
' ########################################################################################

#INCLUDE THIS ONCE
%MSBIND_INC = 1

#INCLUDE ONCE "msstdfmt.inc"
#INCLUDE ONCE "msdatsrc.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_BindingCollection1 = "MSBind.BindingCollection.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Binding = GUID$("{3E60C551-7BD6-11D0-9482-00A0C91110ED}")
$CLSID_BindingCollection = GUID$("{59245250-7A2F-11D0-9482-00A0C91110ED}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DBinding = GUID$("{3E60C550-7BD6-11D0-9482-00A0C91110ED}")
$IID_DBindingCollection = GUID$("{57F12DA0-7A2F-11D0-9482-00A0C91110ED}")
$IID_DBindingCollectionEvents = GUID$("{2651DD90-DB42-11D1-B1CD-00A0C922E820}")

' ========================================================================================
' UpdateMode enum
' IID: {4BFADC70-4994-11D1-A3A8-00A0C90F26FA}
' Enum of Binding Collection UpdateModes
' ========================================================================================

%vbUsePropertyAttributes                                = 0            ' &H0
%vbUpdateWhenPropertyChanges                            = 1            ' &H1
%vbUpdateWhenRowChanges                                 = 2            ' &H2

' ########################################################################################
' Interface name = DBinding
' IID = {3E60C550-7BD6-11D0-9482-00A0C91110ED}
' Binding Object
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DBinding_INTERFACE_DEFINED)
    %DBinding_INTERFACE_DEFINED = 1

INTERFACE DBinding $IID_DBinding

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Object <1> ( _                          ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown** ppObject
   ' =====================================================================================
   PROPERTY SET putref_Object <1> ( _                   ' VTable offset = 32
     BYVAL ppObject AS IUnknown _                       ' __in IUnknown* ppObject
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataField <2> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDataField
   ' =====================================================================================
   PROPERTY SET DataField <2> ( _                       ' VTable offset = 40
     BYVAL pbstrDataField AS WSTRING _                  ' __in BSTR pbstrDataField
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PropertyName <3> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPropertyName
   ' =====================================================================================
   PROPERTY SET PropertyName <3> ( _                    ' VTable offset = 48
     BYVAL pbstrPropertyName AS WSTRING _               ' __in BSTR pbstrPropertyName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataChanged <4> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfDataChanged
   ' =====================================================================================
   PROPERTY SET DataChanged <4> ( _                     ' VTable offset = 56
     BYVAL pfDataChanged AS INTEGER _                   ' __in VARIANT_BOOL pfDataChanged
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataFormat <5> ( _                      ' VTable offset = 60
   ) AS IDataFormatDisp                                 ' __retval_out IDataFormatDisp** ppdf
   ' =====================================================================================
   PROPERTY SET putref_DataFormat <5> ( _               ' VTable offset = 64
     BYVAL ppdf AS IDataFormatDisp _                    ' __in IDataFormatDisp* ppdf
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Key <6> ( _                             ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrKey
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DBinding_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = DBindingCollection
' IID = {57F12DA0-7A2F-11D0-9482-00A0C91110ED}
' Binding Collection Object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DBindingCollection_INTERFACE_DEFINED)
    %DBindingCollection_INTERFACE_DEFINED = 1

INTERFACE DBindingCollection $IID_DBindingCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataSource <1> ( _                      ' VTable offset = 28
   ) AS DataSource                                      ' __retval_out DataSource** ppds
   ' =====================================================================================
   PROPERTY SET putref_DataSource <1> ( _               ' VTable offset = 32
     BYVAL ppds AS DataSource _                         ' __in DataSource* ppds
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataMember <5> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out DataMember* pdm
   ' =====================================================================================
   PROPERTY SET DataMember <5> ( _                      ' VTable offset = 40
     BYVAL pdm AS WSTRING _                             ' __in DataMember pdm
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 44
     BYVAL Object AS IDispatch _                        ' __in IDispatch* Object
   , OPTIONAL BYVAL PropertyName AS WSTRING _           ' __opt_in BSTR PropertyName [default value = ""]
   , OPTIONAL BYVAL DataField AS WSTRING _              ' __opt_in BSTR DataField [default value = ""]
   , OPTIONAL BYVAL IDataFormatDisp AS IDispatch _      ' __opt_in IDataFormatDisp* DataFormat [default value = NULL]
   , OPTIONAL BYVAL Key AS WSTRING _                    ' __opt_in BSTR Key [default value = ""]
   ) AS DBinding                                        ' __retval_out DBinding** ppbinding
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 48
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 52
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS DBinding                                        ' __retval_out DBinding** ppbinding
   ' =====================================================================================
   PROPERTY GET Count <4> ( _                           ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 60
   ) AS IUnknown                                        ' __retval_out IUnknown** ppNewEnum
   ' =====================================================================================
   METHOD Clear <6> ( _                                 ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UpdateMode <7> ( _                      ' VTable offset = 68
   ) AS LONG                                            ' __retval_out UpdateMode* plUM
   ' =====================================================================================
   PROPERTY SET UpdateMode <7> ( _                      ' VTable offset = 72
     BYVAL plUM AS LONG _                               ' __in UpdateMode plUM
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateControls <8> ( _                        ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __DBindingCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CDBindingCollectionEvents
' Interface name = DBindingCollectionEvents
' IID = {2651DD90-DB42-11D1-B1CD-00A0C922E820}
' Binding Collection Event Interface
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDBindingCollectionEvents GUID$("{2495CC66-E72E-49D6-BEFA-860778A07ACB}") AS EVENT

'INTERFACE DBindingCollectionEventsImpl GUID$("{2651DD90-DB42-11D1-B1CD-00A0C922E820}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD Error <300> ( _
'     BYVAL nError AS LONG _                             ' __in  long Error
'   , BYVAL Description AS WSTRING _                     ' __in  BSTR Description
'   , BYVAL Binding AS DBinding _                        ' __in  DBinding *Binding
'   , BYREF fCancelDisplay AS INTEGER _                  ' __out VARIANT_BOOL* fCancelDisplay
'   )                                                    ' VOID

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
