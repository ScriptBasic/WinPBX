' ########################################################################################
' Microsoft Windows
' File: MMCObj.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MMC20
' Version: 1.0, Locale ID = 0
' Description: Microsoft Management Console 2.0
' Path: C:\WINDOWS\system32\mmc.exe
' Library GUID: {8E80422B-CAC4-472B-B272-9635F1DFEF3B}
' ########################################################################################

#INCLUDE THIS ONCE
%MMCOBJ_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {49B2791A-B1AE-4C90-9B8E-E860BA07F889}
$PROGID_MMC_Application1 = "MMC20.Application.1"
' CLSID = {ADE6444B-C91F-4E37-92A4-5BB430A33340}
$PROGID_MMC_AppEventsDHTMLConnector1 = "NODEMGR.AppEventsDHTMLConnector.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {49B2791A-B1AE-4C90-9B8E-E860BA07F889}
$PROGID_MMC_Application = "MMC20.Application"
' CLSID = {ADE6444B-C91F-4E37-92A4-5BB430A33340}
$PROGID_MMC_AppEventsDHTMLConnector = "NODEMGR.AppEventsDHTMLConnector"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MMC_Application = GUID$("{49B2791A-B1AE-4C90-9B8E-E860BA07F889}")
$CLSID_MMC_AppEventsDHTMLConnector = GUID$("{ADE6444B-C91F-4E37-92A4-5BB430A33340}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_MMC_AppEvents = GUID$("{FC7A4252-78AC-4532-8C5A-563CFE138863}")
$IID_MMC_Column = GUID$("{FD1C5F63-2B16-4D06-9AB3-F45350B940AB}")
$IID_MMC_Columns = GUID$("{383D4D97-FC44-478B-B139-6323DC48611C}")
$IID_MMC_ContextMenu = GUID$("{DAB39CE0-25E6-4E07-8362-BA9C95706545}")
$IID_MMC_Document = GUID$("{225120D6-1E0F-40A3-93FE-1079E6A8017B}")
$IID_MMC_Extension = GUID$("{AD4D6CA6-912F-409B-A26E-7FD234AEF542}")
$IID_MMC_Extensions = GUID$("{82DBEA43-8CA4-44BC-A2CA-D18741059EC8}")
$IID_MMC_Frame = GUID$("{E5E2D970-5BB3-4306-8804-B0968A31C8E6}")
$IID_MMC_MenuItem = GUID$("{0178FAD1-B361-4B27-96AD-67C57EBF2E1D}")
$IID_MMC_Node = GUID$("{F81ED800-7839-4447-945D-8E15DA59CA55}")
$IID_MMC_Nodes = GUID$("{313B01DF-B22F-4D42-B1B8-483CDCF51D35}")
$IID_MMC_Properties = GUID$("{2886ABC2-A425-42B2-91C6-E25C0E04581C}")
$IID_MMC_Property = GUID$("{4600C3A5-E301-41D8-B6D0-EF2E4212E0CA}")
$IID_MMC_ScopeNamespace = GUID$("{EBBB48DC-1A3B-4D86-B786-C21B28389012}")
$IID_MMC_SnapIn = GUID$("{3BE910F6-3459-49C6-A1BB-41E6BE9DF3EA}")
$IID_MMC_SnapIns = GUID$("{2EF3DE1D-B12A-49D1-92C5-0B00798768F1}")
$IID_MMC_View = GUID$("{6EFC2DA2-B38C-457E-9ABB-ED2D189B8C38}")
$IID_MMC_Views = GUID$("{D6B8C29D-A1FF-4D72-AAB0-E381E9B9338D}")
$IID__MMC_AppEvents = GUID$("{DE46CBDD-53F5-4635-AF54-4FE71E923D3F}")
$IID__MMC_Application = GUID$("{A3AFB9CC-B653-4741-86AB-F0470EC1384C}")
$IID__MMC_EventConnector = GUID$("{C0BCCD30-DE44-4528-8403-A05A6A1CC8EA}")

' ########################################################################################
' Interface name = ISnapinProperties
' IID = {F7889DA9-4A02-4837-BF89-1A6F2A021010}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_ISnapinProperties_INTERFACE_DEFINED)
    %MMC_ISnapinProperties_INTERFACE_DEFINED = 1

$IID_MMC_ISnapinProperties = GUID$("{F7889DA9-4A02-4837-BF89-1A6F2A021010}")

' enum MMC_PROPERTY_ACTION
%MMC_PROPACT_DELETING    = 1
%MMC_PROPACT_CHANGING    = %MMC_PROPACT_DELETING + 1
%MMC_PROPACT_INITIALIZED = %MMC_PROPACT_CHANGING + 1

' // Size = 32 bytes
TYPE MMC_SNAPIN_PROPERTY QWORD
   pszPropName AS WSTRINGZ PTR     ' LPCOLESTR
   varValue    AS tagVARIANT       ' VARIANT
   eAction     AS DWORD            ' MMC_PROPERTY_ACTION
END TYPE

INTERFACE MMC_ISnapinProperties $IID_MMC_ISnapinProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pProperties AS MMC_Properties _              ' __in Properties *pProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPropertyNames ( _                        ' VTable offset = 16
     BYVAL pCallback AS MMC_ISnapinPropertiesCallback _ ' __in ISnapinPropertiesCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PropertiesChanged ( _                         ' VTable offset = 20
     BYVAL cProperties AS LONG _                        ' __in long cProperties
   , BYREF pProperties AS MMC_SNAPIN_PROPERTY _         ' __in MMC_SNAPIN_PROPERTY *pProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ISnapinProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISnapinPropertiesCallback
' IID = {A50FA2E5-7E61-45EB-A8D4-9A07B3E851A8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_ISnapinPropertiesCallback_INTERFACE_DEFINED)
    %MMC_ISnapinPropertiesCallback_INTERFACE_DEFINED = 1

$IID_MMC_ISnapinPropertiesCallback = GUID$("{A50FA2E5-7E61-45EB-A8D4-9A07B3E851A8}")

%MMC_PROP_CHANGEAFFECTSUI = &H1
%MMC_PROP_MODIFIABLE      = &H2
%MMC_PROP_REMOVABLE       = &H4
%MMC_PROP_PERSIST         = &H8

INTERFACE MMC_ISnapinPropertiesCallback $IID_MMC_ISnapinPropertiesCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddPropertyName ( _                           ' VTable offset = 12
     BYVAL pszPropName AS DWORD _                       ' __in LPCOLESTR pszPropName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ISnapinPropertiesCallback_INTERFACE_DEFINED__ */

#IF NOT %DEF(%MMC20_LIBRARY_DEFINED)
    %MMC20_LIBRARY_DEFINED = 1

' enum DocumentMode
%DocumentMode_Author   = 0
%DocumentMode_User     = %DocumentMode_Author + 1
%DocumentMode_User_MDI = %DocumentMode_User + 1
%DocumentMode_User_SDI = %DocumentMode_User_MDI + 1

' enum ListViewMode
%ListMode_Small_Icons = 0
%ListMode_Large_Icons = %ListMode_Small_Icons + 1
%ListMode_List        = %ListMode_Large_Icons + 1
%ListMode_Detail      = %ListMode_List + 1
%ListMode_Filtered    = %ListMode_Detail + 1

' enum ViewOptions
%ViewOption_Default          = 0
%ViewOption_ScopeTreeHidden  = &H1
%ViewOption_NoToolBars       = &H2
%ViewOption_NotPersistable   = &H4
%ViewOption_ActionPaneHidden = &H8

' enum ExportListOptions
%ExportListOptions_Default           = 0
%ExportListOptions_Unicode           = &H1
%ExportListOptions_TabDelimited      = &H2
%ExportListOptions_SelectedItemsOnly = &H4


' ########################################################################################
' Interface name = _Application
' IID = {A3AFB9CC-B653-4741-86AB-F0470EC1384C}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Application_INTERFACE_DEFINED)
    %MMC_Application_INTERFACE_DEFINED = 1

INTERFACE MMC_Application $IID__MMC_Application

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Help <2> ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Quit <3> ( _                                  ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Document <4> ( _                        ' VTable offset = 36
   ) AS MMC_Document                                    ' __retval_out Document **Document
   ' =====================================================================================
   METHOD Load <5> ( _                                  ' VTable offset = 40
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Frame <6> ( _                           ' VTable offset = 44
   ) AS MMC_Frame                                       ' __retval_out Frame **Frame
   ' =====================================================================================
   PROPERTY GET Visible <7> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Visible
   ' =====================================================================================
   METHOD Show <8> ( _                                  ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD Hide <9> ( _                                  ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserControl <10> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *UserControl
   ' =====================================================================================
   PROPERTY SET UserControl <10> ( _                    ' VTable offset = 64
     BYVAL UserControl AS LONG _                        ' __in long UserControl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VersionMajor <11> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *VersionMajor
   ' =====================================================================================
   PROPERTY GET VersionMinor <12> ( _                   ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *VersionMinor
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Application_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _AppEvents
' IID = {DE46CBDD-53F5-4635-AF54-4FE71E923D3F}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_AppEvents_INTERFACE_DEFINED)
    %MMC_AppEvents_INTERFACE_DEFINED = 1

INTERFACE MMC_AppEvents $IID__MMC_AppEvents

   INHERIT IDispatch

   ' =====================================================================================
   METHOD OnQuit <1> ( _                                ' VTable offset = 28
     BYVAL Application AS MMC_Application _             ' __in _Application *Application
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDocumentOpen <2> ( _                        ' VTable offset = 32
     BYVAL Document AS MMC_Document _                   ' __in Document *Document
   , BYVAL New AS LONG _                                ' __in long New
   )                                                    ' void
   ' =====================================================================================
   METHOD OnDocumentClose <3> ( _                       ' VTable offset = 36
     BYVAL Document AS MMC_Document _                   ' __in Document *Document
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSnapInAdded <4> ( _                         ' VTable offset = 40
     BYVAL Document AS MMC_Document _                   ' __in Document *Document
   , BYVAL SnapIn AS MMC_SnapIn _                       ' __in SnapIn *SnapIn
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSnapInRemoved <5> ( _                       ' VTable offset = 44
     BYVAL Document AS MMC_Document _                   ' __in Document *Document
   , BYVAL SnapIn AS MMC_SnapIn _                       ' __in SnapIn *SnapIn
   )                                                    ' void
   ' =====================================================================================
   METHOD OnNewView <6> ( _                             ' VTable offset = 48
     BYVAL View AS MMC_View _                           ' __in View *View
   )                                                    ' void
   ' =====================================================================================
   METHOD OnViewClose <7> ( _                           ' VTable offset = 52
     BYVAL View AS MMC_View _                           ' __in View *View
   )                                                    ' void
   ' =====================================================================================
   METHOD OnViewChange <8> ( _                          ' VTable offset = 56
     BYVAL View AS MMC_View _                           ' __in View *View
   , BYVAL NewOwnerNode AS MMC_Node _                   ' __in Node *NewOwnerNode
   )                                                    ' void
   ' =====================================================================================
   METHOD OnSelectionChange <9> ( _                     ' VTable offset = 60
     BYVAL View AS MMC_View _                           ' __in View *View
   , BYVAL NewNodes AS MMC_Nodes _                      ' __in Nodes *NewNodes
   )                                                    ' void
   ' =====================================================================================
   METHOD OnContextMenuExecuted <11> ( _                ' VTable offset = 64
     BYVAL MenuItem AS MMC_MenuItem _                   ' __in MenuItem *MenuItem
   )                                                    ' void
   ' =====================================================================================
   METHOD OnToolbarButtonClicked <12> ( _               ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD OnListUpdated <13> ( _                        ' VTable offset = 72
     BYVAL View AS MMC_View _                           ' __in View *View
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_AppEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _EventConnector
' IID = {C0BCCD30-DE44-4528-8403-A05A6A1CC8EA}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_EventConnector_INTERFACE_DEFINED)
    %MMC_EventConnector_INTERFACE_DEFINED = 1

INTERFACE MMC_EventConnector $IID__MMC_EventConnector

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ConnectTo <1> ( _                             ' VTable offset = 28
     BYVAL Application AS MMC_Application _             ' __in _Application *Application
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <2> ( _                            ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_EventConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Frame
' IID = {E5E2D970-5BB3-4306-8804-B0968A31C8E6}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Frame_INTERFACE_DEFINED)
    %MMC_Frame_INTERFACE_DEFINED = 1

INTERFACE MMC_Frame $IID_MMC_Frame

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Maximize <1> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Minimize <2> ( _                              ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Restore <3> ( _                               ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <4> ( _                             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out INT *Top
   ' =====================================================================================
   PROPERTY SET Top <4> ( _                             ' VTable offset = 44
     BYVAL Top AS LONG _                                ' __in INT Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Bottom <5> ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out INT *Bottom
   ' =====================================================================================
   PROPERTY SET Bottom <5> ( _                          ' VTable offset = 52
     BYVAL Bottom AS LONG _                             ' __in INT Bottom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <6> ( _                            ' VTable offset = 56
   ) AS LONG                                            ' __retval_out INT *Left
   ' =====================================================================================
   PROPERTY SET Left <6> ( _                            ' VTable offset = 60
     BYVAL Left AS LONG _                               ' __in INT Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Right <7> ( _                           ' VTable offset = 64
   ) AS LONG                                            ' __retval_out INT *Right
   ' =====================================================================================
   PROPERTY SET Right <7> ( _                           ' VTable offset = 68
     BYVAL Right AS LONG _                              ' __in INT Right
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Frame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Node
' IID = {F81ED800-7839-4447-945D-8E15DA59CA55}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Node_INTERFACE_DEFINED)
    %MMC_Node_INTERFACE_DEFINED = 1

INTERFACE MMC_Node $IID_MMC_Node

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Property <2> ( _                        ' VTable offset = 32
     BYVAL PropertyName AS WSTRING _                    ' __in BSTR PropertyName
   ) AS WSTRING                                         ' __retval_out BSTR *PropertyValue
   ' =====================================================================================
   PROPERTY GET Bookmark <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Bookmark
   ' =====================================================================================
   METHOD IsScopeNode <4> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *IsScopeNode
   ' =====================================================================================
   PROPERTY GET Nodetype <5> ( _                        ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Nodetype
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Node_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ScopeNamespace
' IID = {EBBB48DC-1A3B-4D86-B786-C21B28389012}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_ScopeNamespace_INTERFACE_DEFINED)
    %MMC_ScopeNamespace_INTERFACE_DEFINED = 1

INTERFACE MMC_ScopeNamespace $IID_MMC_ScopeNamespace

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetParent <1> ( _                             ' VTable offset = 28
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   ) AS MMC_Node                                        ' __retval_out Node **Parent
   ' =====================================================================================
   METHOD GetChild <2> ( _                              ' VTable offset = 32
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   ) AS MMC_Node                                        ' __retval_out Node **Child
   ' =====================================================================================
   METHOD GetNext <3> ( _                               ' VTable offset = 36
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   ) AS MMC_Node                                        ' __retval_out Node **Next
   ' =====================================================================================
   METHOD GetRoot <4> ( _                               ' VTable offset = 40
   ) AS MMC_Node                                        ' __retval_out Node **Root
   ' =====================================================================================
   METHOD Expand <5> ( _                                ' VTable offset = 44
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ScopeNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Document
' IID = {225120D6-1E0F-40A3-93FE-1079E6A8017B}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Document_INTERFACE_DEFINED)
    %MMC_Document_INTERFACE_DEFINED = 1

INTERFACE MMC_Document $IID_MMC_Document

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Save <1> ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveAs <2> ( _                                ' VTable offset = 32
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <3> ( _                                 ' VTable offset = 36
     BYVAL SaveChanges AS LONG _                        ' __in long SaveChanges
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Views <4> ( _                           ' VTable offset = 40
   ) AS MMC_Views                                       ' __retval_out Views **Views
   ' =====================================================================================
   PROPERTY GET SnapIns <5> ( _                         ' VTable offset = 44
   ) AS MMC_SnapIns                                     ' __retval_out SnapIns **SnapIns
   ' =====================================================================================
   PROPERTY GET ActiveView <6> ( _                      ' VTable offset = 48
   ) AS MMC_View                                        ' __retval_out View **View
   ' =====================================================================================
   PROPERTY GET Name <7> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY SET Name <7> ( _                            ' VTable offset = 56
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Location <8> ( _                        ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *Location
   ' =====================================================================================
   PROPERTY GET IsSaved <9> ( _                         ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *IsSaved
   ' =====================================================================================
   PROPERTY GET Mode <10> ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out DocumentMode *Mode
   ' =====================================================================================
   PROPERTY SET Mode <10> ( _                           ' VTable offset = 72
     BYVAL Mode AS LONG _                               ' __in DocumentMode Mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootNode <11> ( _                       ' VTable offset = 76
   ) AS MMC_Node                                        ' __retval_out Node **Node
   ' =====================================================================================
   PROPERTY GET ScopeNamespace <12> ( _                 ' VTable offset = 80
   ) AS MMC_ScopeNamespace                              ' __retval_out ScopeNamespace **ScopeNamespace
   ' =====================================================================================
   METHOD CreateProperties <13> ( _                     ' VTable offset = 84
   ) AS MMC_Properties                                  ' __retval_out Properties **Properties
   ' =====================================================================================
   PROPERTY GET Application <20> ( _                    ' VTable offset = 88
   ) AS MMC_Application                                 ' __retval_out _Application **Application
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Document_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SnapIn
' IID = {3BE910F6-3459-49C6-A1BB-41E6BE9DF3EA}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_SnapIn_INTERFACE_DEFINED)
    %MMC_SnapIn_INTERFACE_DEFINED = 1

INTERFACE MMC_SnapIn $IID_MMC_SnapIn

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Vendor <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *Vendor
   ' =====================================================================================
   PROPERTY GET Version <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Version
   ' =====================================================================================
   PROPERTY GET Extensions <4> ( _                      ' VTable offset = 40
   ) AS MMC_Extensions                                  ' __retval_out Extensions **Extensions
   ' =====================================================================================
   PROPERTY GET SnapinCLSID <5> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SnapinCLSID
   ' =====================================================================================
   PROPERTY GET Properties <6> ( _                      ' VTable offset = 48
   ) AS MMC_Properties                                  ' __retval_out Properties **Properties
   ' =====================================================================================
   METHOD EnableAllExtensions <7> ( _                   ' VTable offset = 52
     BYVAL Enable AS LONG _                             ' __in long Enable
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_SnapIn_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = SnapIns
' IID = {2EF3DE1D-B12A-49D1-92C5-0B00798768F1}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_SnapIns_INTERFACE_DEFINED)
    %MMC_SnapIns_INTERFACE_DEFINED = 1

INTERFACE MMC_SnapIns $IID_MMC_SnapIns

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS MMC_SnapIn                                      ' __retval_out SnapIn **SnapIn
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL SnapinNameOrCLSID AS WSTRING _               ' __in BSTR SnapinNameOrCLSID
   , OPTIONAL BYVAL ParentSnapin AS VARIANT _           ' __in_opt VARIANT ParentSnapin
   , OPTIONAL BYVAL Properties AS VARIANT _             ' __in_opt VARIANT Properties
   ) AS MMC_SnapIn                                      ' __retval_out SnapIn **SnapIn
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL SnapIn AS MMC_SnapIn _                       ' __in SnapIn *SnapIn
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_SnapIns_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Extension
' IID = {AD4D6CA6-912F-409B-A26E-7FD234AEF542}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Extension_INTERFACE_DEFINED)
    %MMC_Extension_INTERFACE_DEFINED = 1

INTERFACE MMC_Extension $IID_MMC_Extension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Vendor <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *Vendor
   ' =====================================================================================
   PROPERTY GET Version <3> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Version
   ' =====================================================================================
   PROPERTY GET Extensions <4> ( _                      ' VTable offset = 40
   ) AS MMC_Extensions                                  ' __retval_out Extensions **Extensions
   ' =====================================================================================
   PROPERTY GET SnapinCLSID <5> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *SnapinCLSID
   ' =====================================================================================
   METHOD EnableAllExtensions <6> ( _                   ' VTable offset = 48
     BYVAL Enable AS LONG _                             ' __in long Enable
   )                                                    ' void
   ' =====================================================================================
   METHOD Enable <7> ( _                                ' VTable offset = 52
     BYVAL Enable AS LONG _                             ' __in long Enable
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Extension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Extensions
' IID = {82DBEA43-8CA4-44BC-A2CA-D18741059EC8}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Extensions_INTERFACE_DEFINED)
    %MMC_Extensions_INTERFACE_DEFINED = 1

INTERFACE MMC_Extensions $IID_MMC_Extensions

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS MMC_Extension                                   ' __retval_out Extension **Extension
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Extensions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Columns
' IID = {383D4D97-FC44-478B-B139-6323DC48611C}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Columns_INTERFACE_DEFINED)
    %MMC_Columns_INTERFACE_DEFINED = 1

INTERFACE MMC_Columns $IID_MMC_Columns

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS MMC_Column                                      ' __retval_out Column **Column
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Columns_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Column
' IID = {FD1C5F63-2B16-4D06-9AB3-F45350B940AB}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Column_INTERFACE_DEFINED)
    %MMC_Column_INTERFACE_DEFINED = 1

INTERFACE MMC_Column $IID_MMC_Column

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Name <0> ( _                                  ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Width <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Width
   ' =====================================================================================
   PROPERTY SET Width <1> ( _                           ' VTable offset = 36
     BYVAL Width AS LONG _                              ' __in long Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayPosition <2> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *DisplayPosition
   ' =====================================================================================
   PROPERTY SET DisplayPosition <2> ( _                 ' VTable offset = 44
     BYVAL DisplayPosition AS LONG _                    ' __in long DisplayPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hidden <3> ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Hidden
   ' =====================================================================================
   PROPERTY SET Hidden <3> ( _                          ' VTable offset = 52
     BYVAL Hidden AS LONG _                             ' __in long Hidden
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAsSortColumn <4> ( _                       ' VTable offset = 56
     BYVAL SortOrder AS LONG _                          ' __in ColumnSortOrder SortOrder
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSortColumn <5> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *IsSortColumn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Column_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Views
' IID = {D6B8C29D-A1FF-4D72-AAB0-E381E9B9338D}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Views_INTERFACE_DEFINED)
    %MMC_Views_INTERFACE_DEFINED = 1

INTERFACE MMC_Views $IID_MMC_Views

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS MMC_View                                        ' __retval_out View **View
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   , OPTIONAL BYVAL ViewOptions AS LONG _               ' __in_opt ViewOptions ViewOptions [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Views_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = View
' IID = {6EFC2DA2-B38C-457E-9ABB-ED2D189B8C38}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_View_INTERFACE_DEFINED)
    %MMC_View_INTERFACE_DEFINED = 1

INTERFACE MMC_View $IID_MMC_View

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ActiveScopeNode <1> ( _                 ' VTable offset = 28
   ) AS MMC_Node                                        ' __retval_out Node **Node
   ' =====================================================================================
   PROPERTY SET ActiveScopeNode <1> ( _                 ' VTable offset = 32
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Selection <2> ( _                       ' VTable offset = 36
   ) AS MMC_Nodes                                       ' __retval_out Nodes **Nodes
   ' =====================================================================================
   PROPERTY GET ListItems <3> ( _                       ' VTable offset = 40
   ) AS MMC_Nodes                                       ' __retval_out Nodes **Nodes
   ' =====================================================================================
   METHOD SnapinScopeObject <4> ( _                     ' VTable offset = 44
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   ) AS IDispatch                                       ' __retval_out IDispatch **ScopeNodeObject
   ' =====================================================================================
   METHOD SnapinSelectionObject <5> ( _                 ' VTable offset = 48
   ) AS IDispatch                                       ' __retval_out IDispatch **SelectionObject
   ' =====================================================================================
   METHOD Is <9> ( _                                    ' VTable offset = 52
     BYVAL View AS MMC_View _                           ' __in View *View
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *TheSame
   ' =====================================================================================
   PROPERTY GET Document <10> ( _                       ' VTable offset = 56
   ) AS MMC_Document                                    ' __retval_out Document **Document
   ' =====================================================================================
   METHOD SelectAll <20> ( _                            ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD Select <21> ( _                               ' VTable offset = 64
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   )                                                    ' void
   ' =====================================================================================
   METHOD Deselect <22> ( _                             ' VTable offset = 68
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSelected <23> ( _                           ' VTable offset = 72
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   ) AS LONG                                            ' __retval_out long *IsSelected
   ' =====================================================================================
   METHOD DisplayScopeNodePropertySheet <40> ( _        ' VTable offset = 76
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplaySelectionPropertySheet <41> ( _        ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyScopeNode <42> ( _                        ' VTable offset = 84
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD CopySelection <43> ( _                        ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteScopeNode <44> ( _                      ' VTable offset = 92
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteSelection <45> ( _                      ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD RenameScopeNode <46> ( _                      ' VTable offset = 100
     BYVAL NewName AS WSTRING _                         ' __in BSTR NewName
   , OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD RenameSelectedItem <47> ( _                   ' VTable offset = 104
     BYVAL NewName AS WSTRING _                         ' __in BSTR NewName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScopeNodeContextMenu <48> ( _           ' VTable offset = 108
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   ) AS MMC_ContextMenu                                 ' __retval_out ContextMenu **ContextMenu
   ' =====================================================================================
   PROPERTY GET SelectionContextMenu <49> ( _           ' VTable offset = 112
   ) AS MMC_ContextMenu                                 ' __retval_out ContextMenu **ContextMenu
   ' =====================================================================================
   METHOD RefreshScopeNode <50> ( _                     ' VTable offset = 116
     OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshSelection <51> ( _                     ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecuteSelectionMenuItem <52> ( _             ' VTable offset = 124
     BYVAL MenuItemPath AS WSTRING _                    ' __in BSTR MenuItemPath
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecuteScopeNodeMenuItem <53> ( _             ' VTable offset = 128
     BYVAL MenuItemPath AS WSTRING _                    ' __in BSTR MenuItemPath
   , OPTIONAL BYVAL ScopeNode AS VARIANT _              ' __in_opt VARIANT ScopeNode
   )                                                    ' void
   ' =====================================================================================
   METHOD ExecuteShellCommand <54> ( _                  ' VTable offset = 132
     BYVAL Command AS WSTRING _                         ' __in BSTR Command
   , BYVAL Directory AS WSTRING _                       ' __in BSTR Directory
   , BYVAL Parameters AS WSTRING _                      ' __in BSTR Parameters
   , BYVAL WindowState AS WSTRING _                     ' __in BSTR WindowState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Frame <60> ( _                          ' VTable offset = 136
   ) AS MMC_Frame                                       ' __retval_out Frame **Frame
   ' =====================================================================================
   METHOD Close <61> ( _                                ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScopeTreeVisible <62> ( _               ' VTable offset = 144
   ) AS LONG                                            ' __retval_out long *Visible
   ' =====================================================================================
   PROPERTY SET ScopeTreeVisible <62> ( _               ' VTable offset = 148
     BYVAL Visible AS LONG _                            ' __in long Visible
   )                                                    ' void
   ' =====================================================================================
   METHOD Back <66> ( _                                 ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================
   METHOD Forward <67> ( _                              ' VTable offset = 156
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET StatusBarText <68> ( _                  ' VTable offset = 160
     BYVAL StatusBarText AS WSTRING _                   ' __in BSTR StatusBarText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Memento <69> ( _                        ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *Memento
   ' =====================================================================================
   METHOD ViewMemento <70> ( _                          ' VTable offset = 168
     BYVAL Memento AS WSTRING _                         ' __in BSTR Memento
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Columns <80> ( _                        ' VTable offset = 172
   ) AS MMC_Columns                                     ' __retval_out Columns **Columns
   ' =====================================================================================
   PROPERTY GET CellContents <81> ( _                   ' VTable offset = 176
     BYVAL Node AS MMC_Node _                           ' __in Node *Node
   , BYVAL Column AS LONG _                             ' __in long Column
   ) AS WSTRING                                         ' __retval_out BSTR *CellContents
   ' =====================================================================================
   METHOD ExportList <82> ( _                           ' VTable offset = 180
     BYVAL File AS WSTRING _                            ' __in BSTR File
   , OPTIONAL BYVAL exportoptions AS LONG _             ' __in_opt ExportListOptions exportoptions [default value = 0]
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ListViewMode <83> ( _                   ' VTable offset = 184
   ) AS LONG                                            ' __retval_out ListViewMode *Mode
   ' =====================================================================================
   PROPERTY SET ListViewMode <83> ( _                   ' VTable offset = 188
     BYVAL Mode AS LONG _                               ' __in ListViewMode Mode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ControlObject <100> ( _                 ' VTable offset = 192
   ) AS IDispatch                                       ' __retval_out IDispatch **Control
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_View_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Nodes
' IID = {313B01DF-B22F-4D42-B1B8-483CDCF51D35}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Nodes_INTERFACE_DEFINED)
    %MMC_Nodes_INTERFACE_DEFINED = 1

INTERFACE MMC_Nodes $IID_MMC_Nodes

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS MMC_Node                                        ' __retval_out Node **Node
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Nodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ContextMenu
' IID = {DAB39CE0-25E6-4E07-8362-BA9C95706545}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_ContextMenu_INTERFACE_DEFINED)
    %MMC_ContextMenu_INTERFACE_DEFINED = 1

INTERFACE MMC_ContextMenu $IID_MMC_ContextMenu

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL IndexOrPath AS VARIANT _                     ' __in VARIANT IndexOrPath
   ) AS MMC_MenuItem                                    ' __retval_out MenuItem **MenuItem
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ContextMenu_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = MenuItem
' IID = {0178FAD1-B361-4B27-96AD-67C57EBF2E1D}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_MenuItem_INTERFACE_DEFINED)
    %MMC_MenuItem_INTERFACE_DEFINED = 1

INTERFACE MMC_MenuItem $IID_MMC_MenuItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DisplayName <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *DisplayName
   ' =====================================================================================
   PROPERTY GET LanguageIndependentName <2> ( _         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *LanguageIndependentName
   ' =====================================================================================
   PROPERTY GET Path <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Path
   ' =====================================================================================
   PROPERTY GET LanguageIndependentPath <4> ( _         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *LanguageIndependentPath
   ' =====================================================================================
   METHOD Execute <5> ( _                               ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <6> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *Enabled
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_MenuItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Properties
' IID = {2886ABC2-A425-42B2-91C6-E25C0E04581C}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Properties_INTERFACE_DEFINED)
    %MMC_Properties_INTERFACE_DEFINED = 1

INTERFACE MMC_Properties $IID_MMC_Properties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **retval
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   ) AS MMC_Property                                    ' __retval_out Property **Property
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Remove <2> ( _                                ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Properties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = Property
' IID = {4600C3A5-E301-41D8-B6D0-EF2E4212E0CA}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MMC_Property_INTERFACE_DEFINED)
    %MMC_Property_INTERFACE_DEFINED = 1

INTERFACE MMC_Property $IID_MMC_Property

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_Property_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CAppEvents
' Interface name = AppEvents
' IID = {FC7A4252-78AC-4532-8C5A-563CFE138863}
' AppEvents Interface
' Attributes = 4096 [&H1000] [Dispatchable]
' ########################################################################################

'CLASS CAppEvents GUID$("{7DD15D11-3203-4A34-8E9F-D56BE13C23AF}") AS EVENT

'INTERFACE AppEventsImpl GUID$("{FC7A4252-78AC-4532-8C5A-563CFE138863}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnQuit <1> ( _
'     BYVAL pApplication AS MMC_Application _            ' __in Application *_Application
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDocumentOpen <2> ( _
'     BYVAL pDocument AS MMC_Document _                  ' __in Document *Document
'   , BYVAL lNew AS LONG _                               ' __in long New
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnDocumentClose <3> ( _
'     BYVAL pDocument AS MMC_Document _                  ' __in Document *Document
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnSnapInAdded <4> ( _
'     BYVAL pDocument AS MMC_Document _                  ' __in Document *Document
'   , BYVAL pSnapIn AS MMC_SnapIn _                      ' __in SnapIn *SnapIn
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnSnapInRemoved <5> ( _
'     BYVAL pDocument AS MMC_Document _                  ' __in Document *Document
'   , BYVAL pSnapIn AS MMC_SnapIn _                      ' __in SnapIn *SnapIn
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnNewView <6> ( _
'     BYVAL pView AS MMC_View _                          ' __in View *View
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnViewClose <7> ( _
'     BYVAL pView AS MMC_View _                          ' __in View *View
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnViewChange <8> ( _
'     BYVAL pView AS MMC_View _                          ' __in View *View
'   , BYVAL NewOwnerNode AS MMC_Node _                   ' __in Node *NewOwnerNode
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnSelectionChange <9> ( _
'     BYVAL pView AS MMC_View _                          ' __in View *View
'   , BYVAL NewNodes AS MMC_Nodes _                      ' __in Nodes *NewNodes
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnContextMenuExecuted <11> ( _
'     BYVAL pMenuItem AS MMC_MenuItem _                  ' __in MenuItem *MenuItem
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnToolbarButtonClicked <12>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OnListUpdated <13> ( _
'     BYVAL pView AS MMC_View _                          ' __in View *View
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

#ENDIF   ' #IF NOT %DEF(%MMC20_LIBRARY_DEFINED)
