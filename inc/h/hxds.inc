' ########################################################################################
' Microsoft Windows
' File: hxds.inc
' Library name: MSHelpServices
' Version: 1.0, Locale ID = 0
' Library GUID: {31411197-A502-11D2-BBCA-00C04F8EC294}
' Path: C:\Archivos de programa\Archivos comunes\Microsoft Shared\Help\hxds.dll
' Contents: Microsoft Help Data Services 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HXDS_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {31411228-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegisterProtocol1 = "HxDS.HxRegisterProtocol.1"
' CLSID = {31411219-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegisterSession1 = "HxDS.HxRegisterSession.1"
' CLSID = {314111F0-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegistryWalker1 = "HxDs.HxRegistryWalker.1"
' CLSID = {31411198-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxSession1 = "HxDS.HxSession.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {31411228-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegisterProtocol = "HxDS.HxRegisterProtocol"
' CLSID = {31411219-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegisterSession = "HxDS.HxRegisterSession"
' CLSID = {314111F0-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxRegistryWalker = "HxDs.HxRegistryWalker"
' CLSID = {31411198-A502-11D2-BBCA-00C04F8EC294}
$PROGID_HxSession = "HxDS.HxSession"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_HxRegisterProtocol = GUID$("{31411228-A502-11D2-BBCA-00C04F8EC294}")
$CLSID_HxRegisterSession = GUID$("{31411219-A502-11D2-BBCA-00C04F8EC294}")
$CLSID_HxRegistryWalker = GUID$("{314111F0-A502-11D2-BBCA-00C04F8EC294}")
$CLSID_HxSession = GUID$("{31411198-A502-11D2-BBCA-00C04F8EC294}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumHxAttribute = GUID$("{314111AD-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxAttrName = GUID$("{314111D0-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxAttrValue = GUID$("{314111D6-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxRegFilter = GUID$("{3141121C-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxRegNamespace = GUID$("{314111F5-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxRegPlugIn = GUID$("{3141120C-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxRegTitle = GUID$("{31411204-A502-11D2-BBCA-00C04F8EC294}")
$IID_IEnumHxTopic = GUID$("{31411195-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttribute = GUID$("{314111A9-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttributeList = GUID$("{314111AB-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttrName = GUID$("{314111D2-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttrNameList = GUID$("{314111CE-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttrValue = GUID$("{314111D8-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxAttrValueList = GUID$("{314111D4-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxCancel = GUID$("{31411225-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxCollection = GUID$("{314111A1-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxFilters = GUID$("{314111E3-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxHierarchy = GUID$("{314111B2-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxIndex = GUID$("{314111CC-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxInitialize = GUID$("{314111AE-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxPlugIn = GUID$("{314111DA-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxQuery = GUID$("{31411193-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegFilter = GUID$("{31411221-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegFilterList = GUID$("{31411212-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegister = GUID$("{314111BC-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegisterProtocol = GUID$("{31411227-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegisterSession = GUID$("{31411218-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegisterSessionEvents = GUID$("{31411223-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegistryWalker = GUID$("{314111EF-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegNamespace = GUID$("{314111F1-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegNamespaceList = GUID$("{314111F3-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegPlugIn = GUID$("{3141120A-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegPlugInList = GUID$("{3141120B-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegTitle = GUID$("{31411202-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxRegTitleList = GUID$("{31411203-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxSample = GUID$("{314111E8-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxSampleCollection = GUID$("{314111E6-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxSession = GUID$("{31411192-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxSessionEvents = GUID$("{314111ED-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxTopic = GUID$("{31411196-A502-11D2-BBCA-00C04F8EC294}")
$IID_IHxTopicList = GUID$("{31411194-A502-11D2-BBCA-00C04F8EC294}")

' ========================================================================================
' HxSearchMeta
' IID: {31411237-A502-11D2-BBCA-00C04F8EC294}
' HxDs Search MetaData String Constant
' Note: Must be null-terminated unicode strings.
' ========================================================================================

$HxSearchMetaBegin                                      = "[SrchMeta["
$HxSearchMetaEnd                                        = "]SrchMeta]"
$HxSearchTocBegin                                       = "[Toc["
$HxSearchTocEnd                                         = "]Toc]"
$HxSearchInclBegin                                      = "[Incl["
$HxSearchInclEnd                                        = "]Incl]"
$HxSearchExclBegin                                      = "[Excl["
$HxSearchExclEnd                                        = "]Excl]"

' ========================================================================================
' HxHierarchyNodeType enum
' IID: {314111B6-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxHierarchy_Book                                       = 3            ' &H3
%HxHierarchy_BookPage                                   = 4            ' &H4
%HxHierarchy_Page                                       = 5            ' &H5
%HxHierarchy_Unknown                                    = 8            ' &H8

' ========================================================================================
' HxHierarchyPropId enum
' IID: {314111FA-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxHierarchyTocFont                                     = 0            ' &H0
%HxHierarchyTocFontSize                                 = 1            ' &H1
%HxHierarchyTocLangId                                   = 2            ' &H2
%HxHierarchyTocCharSet                                  = 3            ' &H3
%HxHierarchyTocId                                       = 4            ' &H4
%HxHierarchyTocFileVer                                  = 5            ' &H5
%HxHierarchyTocIconFile                                 = 6            ' &H6
%HxHierarchyTocParentNodeIcon                           = 7            ' &H7
%HxHierarchyTocIcon                                     = 8            ' &H8

' ========================================================================================
' HxTopicGetTitleType enum
' IID: {314111FB-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxTopicGetTOCTitle                                     = 0            ' &H0
%HxTopicGetRLTitle                                      = 1            ' &H1
%HxTopicGetHTMTitle                                     = 2            ' &H2

' ========================================================================================
' HxTopicGetTitleDefVal enum
' IID: {314111FC-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxTopicGetTitleFullURL                                 = 0            ' &H0
%HxTopicGetTitleFileName                                = 1            ' &H1
%HxTopicGetTitleNoDefault                               = 2            ' &H2

' ========================================================================================
' HxQueryPropId enum
' IID: {31411229-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxPropIdQueryFirst                                     = 0            ' &H0

' ========================================================================================
' HxTopicPropId enum
' IID: {3141122B-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxTopicPropIdFirst                                     = 0            ' &H0

' ========================================================================================
' HxHierarchy_PrintNode_Options enum
' IID: {3141122F-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxHierarchy_PrintNode_Option_Node                      = 0            ' &H0
%HxHierarchy_PrintNode_Option_Children                  = 1            ' &H1

' ========================================================================================
' HxQuery_Options enum
' IID: {314111E0-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxQuery_No_Option                                      = 0            ' &H0
%HxQuery_FullTextSearch_Title_Only                      = 1            ' &H1
%HxQuery_FullTextSearch_Enable_Stemming                 = 2            ' &H2
%HxQuery_FullTextSearch_SearchPrevious                  = 4            ' &H4
%HxQuery_KeywordSearch_CaseSensitive                    = 10           ' &HA
%HxQuery_KeywordSearch_AllowDuplicates                  = 16           ' &H10
%HxQuery_FullTextSearch_Wildcard_Preserve               = 128          ' &H80
%HxQuery_FullTextSearch_ReturnRanking                   = 256          ' &H100
%HxQuery_FullTextSearch_MinImprovements                 = 512          ' &H200

' ========================================================================================
' HxCollectionPropId enum
' IID: {314111FD-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxCollectionProp_NamespaceName                         = 1            ' &H1
%HxCollectionProp_Font                                  = 2            ' &H2
%HxCollectionProp_FontSize                              = 3            ' &H3
%HxCollectionProp_LangId                                = 4            ' &H4
%HxCollectionProp_CharSet                               = 5            ' &H5
%HxCollectionProp_Id                                    = 6            ' &H6
%HxCollectionProp_FileVer                               = 7            ' &H7
%HxCollectionProp_CopyRight                             = 8            ' &H8

' ========================================================================================
' HxRegFilterPropId enum
' IID: {3141121D-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxRegFilterName                                        = 0            ' &H0
%HxRegFilterQuery                                       = 1            ' &H1

' ========================================================================================
' HxIndexPropId enum
' IID: {31411200-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxIndexFont                                            = 0            ' &H0
%HxIndexFontSize                                        = 1            ' &H1
%HxIndexLangId                                          = 2            ' &H2
%HxIndexCharSet                                         = 3            ' &H3
%HxIndexTitleStr                                        = 4            ' &H4
%HxIndexIsVisible                                       = 5            ' &H5
%HxIndexId                                              = 6            ' &H6

' ========================================================================================
' HxSampleFileCopyOption enum
' IID: {3141122E-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxSampleFileCopyNoOption                               = 0            ' &H0
%HxSampleFileCopyOverwrite                              = 1            ' &H1
%HxSampleFileCopyFileOnly                               = 2            ' &H2

' ========================================================================================
' HxRegNamespacePropId enum
' IID: {31411208-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxRegNamespaceTitleList                                = 0            ' &H0
%HxRegNamespacePlugInList                               = 1            ' &H1
%HxRegNamespaceName                                     = 2            ' &H2
%HxRegNamespaceCollection                               = 3            ' &H3
%HxRegNamespaceDescription                              = 4            ' &H4
%HxRegNamespaceFilterList                               = 8            ' &H8

' ========================================================================================
' HxRegTitlePropId enum
' IID: {31411209-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxRegTitleFileName                                     = 0            ' &H0
%HxRegTitleIndexName                                    = 1            ' &H1
%HxRegTitleQueryName                                    = 2            ' &H2
%HxRegTitleId                                           = 3            ' &H3
%HxRegTitleLangId                                       = 4            ' &H4
%HxRegAttrQueryName                                     = 5            ' &H5
%HxRegTitleHxsMediaLoc                                  = 6            ' &H6
%HxRegTitleHxqMediaLoc                                  = 7            ' &H7
%HxRegTitleHxrMediaLoc                                  = 8            ' &H8
%HxRegTitleSampleMediaLoc                               = 9            ' &H9

' ========================================================================================
' HxRegPlugInPropId enum
' IID: {31411210-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxRegPlugInName                                        = 0            ' &H0

' ========================================================================================
' HxRegisterSession_InterfaceType enum
' IID: {31411230-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxRegisterSession_IHxRegister                          = 0            ' &H0
%HxRegisterSession_IHxFilters                           = 1            ' &H1
%HxRegisterSession_IHxPlugIn                            = 2            ' &H2

' ========================================================================================
' HxCancelStatus enum
' IID: {31411224-A502-11D2-BBCA-00C04F8EC294}
' ========================================================================================

%HxCancelStatus_Continue                                = 0            ' &H0
%HxCancelStatus_Cancel                                  = 1            ' &H1

' ########################################################################################
' Interface name = IHxHierarchy
' IID = {314111B2-A502-11D2-BBCA-00C04F8EC294}
' IHxHierarchy Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxHierarchy_INTERFACE_DEFINED)
    %IHxHierarchy_INTERFACE_DEFINED = 1

INTERFACE IHxHierarchy $IID_IHxHierarchy

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetRoot <66561> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* phRoot
   ' =====================================================================================
   METHOD GetParent <66562> ( _                         ' VTable offset = 32
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* phParent
   ' =====================================================================================
   METHOD GetSibling <66563> ( _                        ' VTable offset = 36
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* phSibling
   ' =====================================================================================
   METHOD GetFirstChild <66564> ( _                     ' VTable offset = 40
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* phChild
   ' =====================================================================================
   METHOD GetNextFromUrl <66565> ( _                    ' VTable offset = 44
     BYVAL pURL AS WSTRING _                            ' __in BSTR pURL
   ) AS LONG                                            ' __retval_out long* phNext
   ' =====================================================================================
   METHOD GetPrevFromUrl <66566> ( _                    ' VTable offset = 48
     BYVAL pURL AS WSTRING _                            ' __in BSTR pURL
   ) AS LONG                                            ' __retval_out long* phPrev
   ' =====================================================================================
   METHOD GetType <66567> ( _                           ' VTable offset = 52
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out HxHierarchyNodeType* pType
   ' =====================================================================================
   METHOD IsNew <66568> ( _                             ' VTable offset = 56
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbNew
   ' =====================================================================================
   METHOD HasChild <66569> ( _                          ' VTable offset = 60
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbChildren
   ' =====================================================================================
   METHOD GetSyncInfo <66570> ( _                       ' VTable offset = 64
     BYVAL pURL AS WSTRING _                            ' __in BSTR pURL
   ) AS DWORD                                           ' __retval_out SAFEARRAY(VARIANT)* pParents
   ' =====================================================================================
   METHOD GetTitle <66571> ( _                          ' VTable offset = 68
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTitle
   ' =====================================================================================
   METHOD GetImageIndexes <66572> ( _                   ' VTable offset = 72
     BYVAL hNode AS LONG _                              ' __in long hNode
   , BYREF pOpen AS LONG _                              ' __out long* pOpen
   ) AS LONG                                            ' __retval_out long* pClosed
   ' =====================================================================================
   METHOD GetURL <66573> ( _                            ' VTable offset = 76
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS WSTRING                                         ' __retval_out *pbstrURL VT_BSTR
   ' =====================================================================================
   METHOD OnNavigation <66574> ( _                      ' VTable offset = 80
     BYVAL pbstrURL AS WSTRING _                        ' __in BSTR pbstrURL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pbEnableSync
   ' =====================================================================================
   METHOD OnHierarchyNavigation <66575> ( _             ' VTable offset = 84
     BYVAL hNode AS LONG _                              ' __in long hNode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <66576> ( _                       ' VTable offset = 88
     BYVAL propid AS LONG _                             ' __in HxHierarchyPropId propid
   , BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD GetNextFromNode <66577> ( _                   ' VTable offset = 92
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* phNode
   ' =====================================================================================
   METHOD GetPrevFromNode <66578> ( _                   ' VTable offset = 96
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* phNode
   ' =====================================================================================
   METHOD GetTopic <66579> ( _                          ' VTable offset = 100
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS IHxTopic                                        ' __retval_out IHxTopic** ppIHxTopic
   ' =====================================================================================
   METHOD GetOpenImageIndex <66580> ( _                 ' VTable offset = 104
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* pOpen
   ' =====================================================================================
   METHOD GetClosedImageIndex <66581> ( _               ' VTable offset = 108
     BYVAL hNode AS LONG _                              ' __in long hNode
   ) AS LONG                                            ' __retval_out long* pClosed
   ' =====================================================================================
   METHOD PrintNode <66582> ( _                         ' VTable offset = 112
     BYVAL hwnd AS LONG _                               ' __in long hwnd
   , BYVAL hNode AS LONG _                              ' __in long hNode
   , BYVAL options AS LONG _                            ' __in HxHierarchy_PrintNode_Options options
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxHierarchy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxTopic
' IID = {31411196-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxTopic_INTERFACE_DEFINED)
    %IHxTopic_INTERFACE_DEFINED = 1

INTERFACE IHxTopic $IID_IHxTopic

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Title <68097> ( _                       ' VTable offset = 28
     BYVAL optType AS LONG _                            ' __in HxTopicGetTitleType optType
   , BYVAL optDef AS LONG _                             ' __in HxTopicGetTitleDefVal optDef
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET URL <68098> ( _                         ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Location <68099> ( _                    ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Rank <68100> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* pVal
   ' =====================================================================================
   PROPERTY GET Attributes <68101> ( _                  ' VTable offset = 44
   ) AS IHxAttributeList                                ' __retval_out IHxAttributeList **ppVal
   ' =====================================================================================
   METHOD GetInfo <68102> ( _                           ' VTable offset = 48
     BYREF pTitle AS WSTRING _                          ' __out BSTR *pTitle
   , BYREF pURL AS WSTRING _                            ' __out BSTR *pURL
   , BYREF pLocation AS WSTRING _                       ' __out BSTR *pLocation
   , BYREF pRank AS LONG _                              ' __out long* pRank
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <68103> ( _                       ' VTable offset = 52
     BYVAL propid AS LONG _                             ' __in HxTopicPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD SetProperty <68104> ( _                       ' VTable offset = 56
     BYVAL propid AS LONG _                             ' __in HxTopicPropId propid
   , BYVAL VARIANT _                                    ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   METHOD HasAttribute <68105> ( _                      ' VTable offset = 60
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfHasAttribute
   ' =====================================================================================
   METHOD HasAttrName <68106> ( _                       ' VTable offset = 64
     BYVAL Value AS WSTRING _                           ' __in BSTR Name
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfHasAttrName
   ' =====================================================================================
   METHOD HighlightDocument <68107> ( _                 ' VTable offset = 68
     BYVAL pIDispatch AS IDispatch _                    ' __in IDispatch *pIDispatch
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxTopic_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttributeList
' IID = {314111AB-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttributeList_INTERFACE_DEFINED)
    %IHxAttributeList_INTERFACE_DEFINED = 1

INTERFACE IHxAttributeList $IID_IHxAttributeList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <70400> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================
   METHOD ItemAt <70401> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxAttribute                                    ' __retval_out IHxAttribute **ppIHxAttribute
   ' =====================================================================================
   METHOD EnumAttribute <70402> ( _                     ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxAttribute                                ' __retval_out IEnumHxAttribute **ppIEnumHxAttribute
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **pIUnknown
   ' =====================================================================================
   METHOD Item <70403> ( _                              ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxAttribute                                    ' __retval_out IHxAttribute **ppIHxAttribute
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttributeList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttribute
' IID = {314111A9-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttribute_INTERFACE_DEFINED)
    %IHxAttribute_INTERFACE_DEFINED = 1

INTERFACE IHxAttribute $IID_IHxAttribute

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <69888> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD SetProperty <69889> ( _                       ' VTable offset = 32
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <69890> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Value <69891> ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET DisplayName <69892> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *pVal VT_BSTR
   ' =====================================================================================
   PROPERTY GET DisplayValue <69893> ( _                ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttribute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxAttribute
' IID = {314111AD-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxAttribute_INTERFACE_DEFINED)
    %IEnumHxAttribute_INTERFACE_DEFINED = 1

INTERFACE IEnumHxAttribute $IID_IEnumHxAttribute

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxAttribute AS IHxAttribute _             ' __out IHxAttribute** ppIHxAttribute
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxAttribute _                 ' __out IEnumHxAttribute** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxAttribute_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegister
' IID = {314111BC-A502-11D2-BBCA-00C04F8EC294}
' IHxRegister Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegister_INTERFACE_DEFINED)
    %IHxRegister_INTERFACE_DEFINED = 1

INTERFACE IHxRegister $IID_IHxRegister

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RegisterNamespace <66817> ( _                 ' VTable offset = 28
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrCollection AS WSTRING _                  ' __in BSTR bstrCollection
   , BYVAL bstrDescription AS WSTRING _                 ' __in BSTR bstrDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD IsNamespace <66818> ( _                       ' VTable offset = 32
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pf
   ' =====================================================================================
   METHOD GetCollection <66830> ( _                     ' VTable offset = 36
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   ) AS WSTRING                                         ' __retval_out BSTR* bstrCollection
   ' =====================================================================================
   METHOD GetDescription <66829> ( _                    ' VTable offset = 40
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   ) AS WSTRING                                         ' __retval_out BSTR* bstrDescription
   ' =====================================================================================
   METHOD RemoveNamespace <66819> ( _                   ' VTable offset = 44
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterHelpFile <66822> ( _                  ' VTable offset = 48
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrId AS WSTRING _                          ' __in BSTR bstrId
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , BYVAL bstrHelpFile AS WSTRING _                    ' __in BSTR bstrHelpFile
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterMedia <66823> ( _                     ' VTable offset = 52
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrFriendly AS WSTRING _                    ' __in BSTR bstrFriendly
   , BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS LONG                                            ' __retval_out long* pdwId
   ' =====================================================================================
   METHOD RemoveHelpFile <66825> ( _                    ' VTable offset = 56
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrId AS WSTRING _                          ' __in BSTR bstrId
   , BYVAL LangId AS LONG _                             ' __in long LangId
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterHelpFileSet <66831> ( _               ' VTable offset = 60
     BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrId AS WSTRING _                          ' __in BSTR bstrId
   , BYVAL LangId AS LONG _                             ' __in long LangId
   , BYVAL bstrHxs AS WSTRING _                         ' __in BSTR bstrHxs
   , BYVAL bstrHxi AS WSTRING _                         ' __in BSTR bstrHxi
   , BYVAL bstrHxq AS WSTRING _                         ' __in BSTR bstrHxq
   , BYVAL bstrHxr AS WSTRING _                         ' __in BSTR bstrHxr
   , BYVAL lHxsMediaId AS LONG _                        ' __in long lHxsMediaId
   , BYVAL lHxqMediaId AS LONG _                        ' __in long lHxqMediaId
   , BYVAL lHxrMediaId AS LONG _                        ' __in long lHxrMediaId
   , BYVAL lSampleMediaId AS LONG _                     ' __in long lSampleMediaId
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegister_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxIndex
' IID = {314111CC-A502-11D2-BBCA-00C04F8EC294}
' IHxIndex Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxIndex_INTERFACE_DEFINED)
    %IHxIndex_INTERFACE_DEFINED = 1

INTERFACE IHxIndex $IID_IHxIndex

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetSession <67072> ( _                        ' VTable offset = 28
   ) AS IHxSession                                      ' __retval_out IHxSession** ppIHxSession
   ' =====================================================================================
   PROPERTY GET Count <67073> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* piCount
   ' =====================================================================================
   METHOD GetStringFromSlot <67074> ( _                 ' VTable offset = 36
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   ) AS WSTRING                                         ' __retval_out BSTR* pbszLink
   ' =====================================================================================
   METHOD GetLevelFromSlot <67078> ( _                  ' VTable offset = 40
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   ) AS LONG                                            ' __retval_out long* piLevel
   ' =====================================================================================
   METHOD GetSlotFromString <67075> ( _                 ' VTable offset = 44
     BYVAL bszLink AS WSTRING _                         ' __in BSTR bszLink
   ) AS LONG                                            ' __retval_out long* piSlot
   ' =====================================================================================
   METHOD GetTopicsFromSlot <67076> ( _                 ' VTable offset = 48
     BYVAL uiSlot AS LONG _                             ' __in long uiSlot
   ) AS IHxTopicList                                    ' __retval_out IHxTopicList** ppIHxTopicList
   ' =====================================================================================
   METHOD GetTopicsFromString <67077> ( _               ' VTable offset = 52
     BYVAL bszLink AS WSTRING _                         ' __in BSTR bszLink
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IHxTopicList                                    ' __retval_out IHxTopicList** ppIHxTopicList
   ' =====================================================================================
   METHOD GetInfoFromSlot <67079> ( _                   ' VTable offset = 56
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   , BYREF piLevel AS LONG _                            ' __out long* piLevel
   ) AS WSTRING                                         ' __retval_out BSTR* pbszLink
   ' =====================================================================================
   METHOD GetProperty <67080> ( _                       ' VTable offset = 60
     BYVAL propid AS LONG _                             ' __in HxIndexPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD GetCrossRef <67081> ( _                       ' VTable offset = 64
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   ) AS WSTRING                                         ' __retval_out BSTR* pbszLink
   ' =====================================================================================
   METHOD GetFullStringFromSlot <67082> ( _             ' VTable offset = 68
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   , BYVAL sep AS WSTRING _                             ' __in BSTR sep
   ) AS WSTRING                                         ' __retval_out BSTR* pbszLink
   ' =====================================================================================
   METHOD GetCrossRefSlot <67083> ( _                   ' VTable offset = 72
     BYVAL iSlot AS LONG _                              ' __in long iSlot
   ) AS LONG                                            ' __retval_out long* piTargetSlot
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxIndex_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxSession
' IID = {31411192-A502-11D2-BBCA-00C04F8EC294}
' IHxSession Interface
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxSession_INTERFACE_DEFINED)
    %IHxSession_INTERFACE_DEFINED = 1

INTERFACE IHxSession $IID_IHxSession

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <65792> ( _                        ' VTable offset = 28
     BYVAL NameSpace AS WSTRING _                       ' __in BSTR NameSpace
   , BYVAL options AS LONG _                            ' __in long options
   )                                                    ' void
   ' =====================================================================================
   METHOD Query <65793> ( _                             ' VTable offset = 32
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL options AS LONG _                            ' __in long options
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   ) AS IHxTopicList                                    ' __retval_out IHxTopicList** ppIHxTopicList
   ' =====================================================================================
   METHOD QueryForTopic <65794> ( _                     ' VTable offset = 36
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL options AS LONG _                            ' __in long options
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   ) AS IHxTopic                                        ' __retval_out IHxTopic** ppIHxTopic
   ' =====================================================================================
   METHOD QueryForUrl <65795> ( _                       ' VTable offset = 40
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL options AS LONG _                            ' __in long options
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   ) AS WSTRING                                         ' __retval_out BSTR* pURL
   ' =====================================================================================
   METHOD GetNavigationInterface <65796> ( _            ' VTable offset = 44
     BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   , BYREF refiid AS GUID _                             ' __in GUID* refiid
   ) AS IDispatch                                       ' __retval_out IDispatch** ppIDispatch
   ' =====================================================================================
   METHOD GetNavigationObject <65797> ( _               ' VTable offset = 48
     BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   ) AS IDispatch                                       ' __retval_out IDispatch** pIDispatch
   ' =====================================================================================
   METHOD GetQueryObject <65798> ( _                    ' VTable offset = 52
     BYVAL NavDataMoniker AS WSTRING _                  ' __in BSTR NavDataMoniker
   , BYVAL FilterMoniker AS WSTRING _                   ' __in BSTR FilterMoniker
   ) AS IHxQuery                                        ' __retval_out IHxQuery** pIHxQuery
   ' =====================================================================================
   PROPERTY GET Collection <65799> ( _                  ' VTable offset = 56
   ) AS IHxCollection                                   ' __retval_out IHxCollection** ppIHxCollection
   ' =====================================================================================
   PROPERTY GET LangId <65803> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* piHelpLangId
   ' =====================================================================================
   PROPERTY SET LangId <65803> ( _                      ' VTable offset = 64
     BYVAL piHelpLangId AS INTEGER _                    ' __in short piHelpLangId
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFilterList <65805> ( _                     ' VTable offset = 68
   ) AS IHxRegFilterList                                ' __retval_out IHxRegFilterList** ppIHxRegFilterList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxSession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxTopicList
' IID = {31411194-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxTopicList_INTERFACE_DEFINED)
    %IHxTopicList_INTERFACE_DEFINED = 1

INTERFACE IHxTopicList $IID_IHxTopicList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxTopic                                        ' __retval_out IHxTopic** pIHxTopic
   ' =====================================================================================
   METHOD ItemAt <67584> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxTopic                                        ' __retval_out IHxTopic** pIHxTopic
   ' =====================================================================================
   METHOD EnumTopics <67585> ( _                        ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxTopic                                    ' __retval_out IEnumHxTopic** pIEnumHxTopic
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   PROPERTY GET Count <67586> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxTopicList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxTopic
' IID = {31411195-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxTopic_INTERFACE_DEFINED)
    %IEnumHxTopic_INTERFACE_DEFINED = 1

INTERFACE IEnumHxTopic $IID_IEnumHxTopic

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxTopic AS IHxTopic _                     ' __out IHxTopic** ppIHxTopic
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxTopic _                     ' __out IEnumHxTopic** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxTopic_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxQuery
' IID = {31411193-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxQuery_INTERFACE_DEFINED)
    %IHxQuery_INTERFACE_DEFINED = 1

INTERFACE IHxQuery $IID_IHxQuery

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Query <67328> ( _                             ' VTable offset = 28
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL options AS LONG _                            ' __in HxQuery_Options options
   ) AS IHxTopicList                                    ' __retval_out IHxTopicList** ppIHxTopicList
   ' =====================================================================================
   METHOD QueryForTopic <67329> ( _                     ' VTable offset = 32
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL options AS LONG _                            ' __in HxQuery_Options options
   ) AS IHxTopic                                        ' __retval_out IHxTopic** ppIHxTopic
   ' =====================================================================================
   METHOD QueryForUrl <67330> ( _                       ' VTable offset = 36
     BYVAL keywords AS WSTRING _                        ' __in BSTR keywords
   , BYVAL options AS LONG _                            ' __in HxQuery_Options options
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrURL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxQuery_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxCollection
' IID = {314111A1-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxCollection_INTERFACE_DEFINED)
    %IHxCollection_INTERFACE_DEFINED = 1

INTERFACE IHxCollection $IID_IHxCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <68352> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxCollectionPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD SetProperty <68353> ( _                       ' VTable offset = 32
     BYVAL propid AS LONG _                             ' __in HxCollectionPropId propid
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET URL <68354> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET AttributeNames <68357> ( _              ' VTable offset = 40
   ) AS IHxAttrNameList                                 ' __retval_out IHxAttrNameList** ppVal
   ' =====================================================================================
   PROPERTY GET Filters <68358> ( _                     ' VTable offset = 44
   ) AS IHxFilters                                      ' __retval_out IHxFilters** ppIHxFilters
   ' =====================================================================================
   PROPERTY GET Title <68359> ( _                       ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pTitle
   ' =====================================================================================
   METHOD MergeIndex <68360> ( _                        ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFilterTopicCount <68361> ( _               ' VTable offset = 56
     BYVAL bstrQuery AS WSTRING _                       ' __in BSTR bstrQuery
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttrNameList
' IID = {314111CE-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttrNameList_INTERFACE_DEFINED)
    %IHxAttrNameList_INTERFACE_DEFINED = 1

INTERFACE IHxAttrNameList $IID_IHxAttrNameList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <71168> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================
   METHOD ItemAt <71169> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxAttrName                                     ' __retval_out IHxAttrName** ppIHxAttrName
   ' =====================================================================================
   METHOD EnumAttrName <71170> ( _                      ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxAttrName                                 ' __retval_out IEnumHxAttrName** ppIEnumHxAttrName
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   METHOD Item <71171> ( _                              ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxAttrName                                     ' __retval_out IHxAttrName** ppIHxAttrName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttrNameList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttrName
' IID = {314111D2-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttrName_INTERFACE_DEFINED)
    %IHxAttrName_INTERFACE_DEFINED = 1

INTERFACE IHxAttrName $IID_IHxAttrName

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <70656> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD SetProperty <70657> ( _                       ' VTable offset = 32
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <70658> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET DisplayName <70659> ( _                 ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Flag <70660> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================
   PROPERTY GET AttributeValues <70661> ( _             ' VTable offset = 48
   ) AS IHxAttrValueList                                ' __retval_out IHxAttrValueList** ppVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttrName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttrValueList
' IID = {314111D4-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttrValueList_INTERFACE_DEFINED)
    %IHxAttrValueList_INTERFACE_DEFINED = 1

INTERFACE IHxAttrValueList $IID_IHxAttrValueList

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <71936> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================
   METHOD ItemAt <71937> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxAttrValue                                    ' __retval_out IHxAttrValue** ppIHxAttrValue
   ' =====================================================================================
   METHOD EnumAttrValue <71938> ( _                     ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxAttrValue                                ' __retval_out IEnumHxAttrValue** ppIEnumHxAttrValue
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   METHOD Item <71939> ( _                              ' VTable offset = 44
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxAttrValue                                    ' __retval_out IHxAttrValue** ppIHxAttrValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttrValueList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxAttrValue
' IID = {314111D8-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxAttrValue_INTERFACE_DEFINED)
    %IHxAttrValue_INTERFACE_DEFINED = 1

INTERFACE IHxAttrValue $IID_IHxAttrValue

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <71424> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD SetProperty <71425> ( _                       ' VTable offset = 32
     BYVAL propid AS LONG _                             ' __in HxQueryPropId propid
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value <71426> ( _                       ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET DisplayValue <71427> ( _                ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pVal
   ' =====================================================================================
   PROPERTY GET Flag <71428> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxAttrValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxAttrValue
' IID = {314111D6-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxAttrValue_INTERFACE_DEFINED)
    %IEnumHxAttrValue_INTERFACE_DEFINED = 1

INTERFACE IEnumHxAttrValue $IID_IEnumHxAttrValue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxAttrValue AS IHxAttrValue _             ' __out IHxAttrValue** ppIHxAttrValue
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxAttrValue _                 ' __out IEnumHxAttrValue** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxAttrValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxAttrName
' IID = {314111D0-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxAttrName_INTERFACE_DEFINED)
    %IEnumHxAttrName_INTERFACE_DEFINED = 1

INTERFACE IEnumHxAttrName $IID_IEnumHxAttrName

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxAttrName AS IHxAttrName _               ' __out IHxAttrName** ppIHxAttrName
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxAttrName _                  ' __out IEnumHxAttrName** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxAttrName_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxFilters
' IID = {314111E3-A502-11D2-BBCA-00C04F8EC294}
' IHxFilters Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxFilters_INTERFACE_DEFINED)
    %IHxFilters_INTERFACE_DEFINED = 1

INTERFACE IHxFilters $IID_IHxFilters

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Count <66048> ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   METHOD GetFilter <66049> ( _                         ' VTable offset = 32
     BYVAL iIndex AS LONG _                             ' __in long iIndex
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR* pbstrName
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrQuery
   ' =====================================================================================
   METHOD GetFilterName <66054> ( _                     ' VTable offset = 36
     BYVAL iIndex AS LONG _                             ' __in long iIndex
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   METHOD GetFilterQuery <66055> ( _                    ' VTable offset = 40
     BYVAL iIndex AS LONG _                             ' __in long iIndex
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrQuery
   ' =====================================================================================
   METHOD RegisterFilter <66050> ( _                    ' VTable offset = 44
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR bstrName
   , BYVAL bstrQuery AS WSTRING _                       ' __in BSTR bstrQuery
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFilter <66051> ( _                      ' VTable offset = 48
     BYVAL pbstrName AS WSTRING _                       ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD FindFilter <66052> ( _                        ' VTable offset = 52
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrQuery
   ' =====================================================================================
   METHOD SetNamespace <66053> ( _                      ' VTable offset = 56
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetCollectionFiltersFlag <66057> ( _          ' VTable offset = 60
     BYVAL vb AS INTEGER _                              ' __in VARIANT_BOOL vb
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxFilters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegFilterList
' IID = {31411212-A502-11D2-BBCA-00C04F8EC294}
' IHxRegFilterList Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegFilterList_INTERFACE_DEFINED)
    %IHxRegFilterList_INTERFACE_DEFINED = 1

INTERFACE IHxRegFilterList $IID_IHxRegFilterList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxRegFilter                                    ' __retval_out IHxRegFilter** ppIHxRegFilter
   ' =====================================================================================
   METHOD ItemAt <75776> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxRegFilter                                    ' __retval_out IHxRegFilter** ppIHxRegFilter
   ' =====================================================================================
   METHOD EnumRegFilter <75777> ( _                     ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxRegFilter                                ' __retval_out IEnumHxRegFilter** pIEnumHxRegFilter
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   PROPERTY GET Count <75778> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================
   METHOD FindFilter <75779> ( _                        ' VTable offset = 48
     BYVAL bstrFilterName AS WSTRING _                  ' __in BSTR bstrFilterName
   ) AS IHxRegFilter                                    ' __retval_out IHxRegFilter** ppIHxRegFilter
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegFilterList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegFilter
' IID = {31411221-A502-11D2-BBCA-00C04F8EC294}
' IHxRegFilter Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegFilter_INTERFACE_DEFINED)
    %IHxRegFilter_INTERFACE_DEFINED = 1

INTERFACE IHxRegFilter $IID_IHxRegFilter

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <75520> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxRegFilterPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxRegFilter
' IID = {3141121C-A502-11D2-BBCA-00C04F8EC294}
' IEnumHxRegFilter Interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxRegFilter_INTERFACE_DEFINED)
    %IEnumHxRegFilter_INTERFACE_DEFINED = 1

INTERFACE IEnumHxRegFilter $IID_IEnumHxRegFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxRegFilter AS IHxRegFilter _             ' __out IHxRegFilter** ppIHxRegFilter
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxRegFilter _                 ' __out IEnumHxRegFilter** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxRegFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxSampleCollection
' IID = {314111E6-A502-11D2-BBCA-00C04F8EC294}
' IHxSampleCollection Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxSampleCollection_INTERFACE_DEFINED)
    %IHxSampleCollection_INTERFACE_DEFINED = 1

INTERFACE IHxSampleCollection $IID_IHxSampleCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetSampleFromId <72448> ( _                   ' VTable offset = 28
     BYVAL bstrTopicUrl AS WSTRING _                    ' __in BSTR bstrTopicUrl
   , BYVAL bstrId AS WSTRING _                          ' __in BSTR bstrId
   , BYVAL bstrSFLName AS WSTRING _                     ' __in BSTR bstrSFLName
   ) AS IHxSample                                       ' __retval_out IHxSample** ppIHxSample
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxSampleCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxSample
' IID = {314111E8-A502-11D2-BBCA-00C04F8EC294}
' IHxSample Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxSample_INTERFACE_DEFINED)
    %IHxSample_INTERFACE_DEFINED = 1

INTERFACE IHxSample $IID_IHxSample

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SampleId <72704> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSampleId
   ' =====================================================================================
   PROPERTY GET LoadString <72705> ( _                  ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrLoadString
   ' =====================================================================================
   PROPERTY GET DestinationDir <72706> ( _              ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDestDir
   ' =====================================================================================
   PROPERTY GET ProjectFileExt <72707> ( _              ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrProjFileExt
   ' =====================================================================================
   PROPERTY GET FileCount <72709> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pcFile
   ' =====================================================================================
   METHOD GetFileNameAtIndex <72710> ( _                ' VTable offset = 48
     BYVAL index AS LONG _                              ' __in long index
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileName
   ' =====================================================================================
   METHOD CopyFileAtIndex <72711> ( _                   ' VTable offset = 52
     BYVAL index AS LONG _                              ' __in long index
   , BYVAL bstrDest AS WSTRING _                        ' __in BSTR bstrDest
   , BYVAL option AS LONG _                             ' __in HxSampleFileCopyOption option
   )                                                    ' void
   ' =====================================================================================
   METHOD ChooseDirectory <72713> ( _                   ' VTable offset = 56
     BYVAL bstrDefaultDir AS WSTRING _                  ' __in BSTR bstrDefaultDir
   , BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDestDir
   ' =====================================================================================
   METHOD GetFileTextAtIndex <72714> ( _                ' VTable offset = 60
     BYVAL index AS LONG _                              ' __in long index
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFileText
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxSample_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegistryWalker
' IID = {314111EF-A502-11D2-BBCA-00C04F8EC294}
' IHxRegistryWalker Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegistryWalker_INTERFACE_DEFINED)
    %IHxRegistryWalker_INTERFACE_DEFINED = 1

INTERFACE IHxRegistryWalker $IID_IHxRegistryWalker

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RegisteredNamespaceList <72960> ( _     ' VTable offset = 28
     BYVAL bstrStart AS WSTRING _                       ' __in BSTR bstrStart
   ) AS IHxRegNamespaceList                             ' __retval_out IHxRegNamespaceList** ppIHxRegNamespaceList
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegistryWalker_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegNamespaceList
' IID = {314111F3-A502-11D2-BBCA-00C04F8EC294}
' IHxRegNamespaceList Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegNamespaceList_INTERFACE_DEFINED)
    %IHxRegNamespaceList_INTERFACE_DEFINED = 1

INTERFACE IHxRegNamespaceList $IID_IHxRegNamespaceList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxRegNamespace                                 ' __retval_out IHxRegNamespace** pIHxRegNamespace
   ' =====================================================================================
   METHOD ItemAt <73472> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxRegNamespace                                 ' __retval_out IHxRegNamespace** pIHxRegNamespace
   ' =====================================================================================
   METHOD EnumRegNamespace <73473> ( _                  ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxRegNamespace                             ' __retval_out IEnumHxRegNamespace** pIEnumHxRegNamespace
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   PROPERTY GET Count <73474> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegNamespaceList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegNamespace
' IID = {314111F1-A502-11D2-BBCA-00C04F8EC294}
' IHxRegNamespace Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegNamespace_INTERFACE_DEFINED)
    %IHxRegNamespace_INTERFACE_DEFINED = 1

INTERFACE IHxRegNamespace $IID_IHxRegNamespace

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <73216> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   METHOD GetProperty <73217> ( _                       ' VTable offset = 32
     BYVAL propid AS LONG _                             ' __in HxRegNamespacePropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================
   METHOD IsTitle <73218> ( _                           ' VTable offset = 36
     BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pb
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxRegNamespace
' IID = {314111F5-A502-11D2-BBCA-00C04F8EC294}
' IEnumHxRegNamespace Interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxRegNamespace_INTERFACE_DEFINED)
    %IEnumHxRegNamespace_INTERFACE_DEFINED = 1

INTERFACE IEnumHxRegNamespace $IID_IEnumHxRegNamespace

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxRegNamespace AS IHxRegNamespace _       ' __out IHxRegNamespace** ppIHxRegNamespace
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxRegNamespace _              ' __out IEnumHxRegNamespace** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxRegNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegTitle
' IID = {31411202-A502-11D2-BBCA-00C04F8EC294}
' IHxRegTitle Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegTitle_INTERFACE_DEFINED)
    %IHxRegTitle_INTERFACE_DEFINED = 1

INTERFACE IHxRegTitle $IID_IHxRegTitle

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <73984> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxRegTitlePropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegTitle_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegTitleList
' IID = {31411203-A502-11D2-BBCA-00C04F8EC294}
' IHxRegTitleList Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegTitleList_INTERFACE_DEFINED)
    %IHxRegTitleList_INTERFACE_DEFINED = 1

INTERFACE IHxRegTitleList $IID_IHxRegTitleList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxRegTitle                                     ' __retval_out IHxRegTitle** ppIHxRegTitle
   ' =====================================================================================
   METHOD ItemAt <74240> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxRegTitle                                     ' __retval_out IHxRegTitle** ppIHxRegTitle
   ' =====================================================================================
   METHOD EnumRegTitle <74241> ( _                      ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxRegTitle                                 ' __retval_out IEnumHxRegTitle** pIEnumHxRegTitle
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** pIUnknown
   ' =====================================================================================
   PROPERTY GET Count <74242> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegTitleList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxRegTitle
' IID = {31411204-A502-11D2-BBCA-00C04F8EC294}
' IEnumHxRegTitle Interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxRegTitle_INTERFACE_DEFINED)
    %IEnumHxRegTitle_INTERFACE_DEFINED = 1

INTERFACE IEnumHxRegTitle $IID_IEnumHxRegTitle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxRegTitle AS IHxRegTitle _               ' __out IHxRegTitle** ppIHxRegTitle
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxRegTitle _                  ' __out IEnumHxRegTitle** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxRegTitle_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegPlugIn
' IID = {3141120A-A502-11D2-BBCA-00C04F8EC294}
' IHxRegPlugIn Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegPlugIn_INTERFACE_DEFINED)
    %IHxRegPlugIn_INTERFACE_DEFINED = 1

INTERFACE IHxRegPlugIn $IID_IHxRegPlugIn

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty <74752> ( _                       ' VTable offset = 28
     BYVAL propid AS LONG _                             ' __in HxRegPlugInPropId propid
   ) AS VARIANT                                         ' __retval_out VARIANT* pvar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegPlugIn_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegPlugInList
' IID = {3141120B-A502-11D2-BBCA-00C04F8EC294}
' IHxRegPlugInList Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegPlugInList_INTERFACE_DEFINED)
    %IHxRegPlugInList_INTERFACE_DEFINED = 1

INTERFACE IHxRegPlugInList $IID_IHxRegPlugInList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYVAL index AS VARIANT _                           ' __in VARIANT index
   ) AS IHxRegPlugIn                                    ' __retval_out IHxRegPlugIn** ppIHxRegPlugIn
   ' =====================================================================================
   METHOD ItemAt <75008> ( _                            ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in long index
   ) AS IHxRegPlugIn                                    ' __retval_out IHxRegPlugIn** ppIHxRegPlugIn
   ' =====================================================================================
   METHOD EnumRegPlugIn <75009> ( _                     ' VTable offset = 36
     BYVAL filter AS LONG _                             ' __in long filter
   , BYVAL options AS LONG _                            ' __in long options
   ) AS IEnumHxRegPlugIn                                ' __retval_out IEnumHxRegPlugIn** pIEnumHxRegPlugIn
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out **pIUnknown VT_UNKNOWN <IUnknown>
   ' =====================================================================================
   PROPERTY GET Count <75010> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long* pReturn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegPlugInList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumHxRegPlugIn
' IID = {3141120C-A502-11D2-BBCA-00C04F8EC294}
' IEnumHxRegPlugIn Interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumHxRegPlugIn_INTERFACE_DEFINED)
    %IEnumHxRegPlugIn_INTERFACE_DEFINED = 1

INTERFACE IEnumHxRegPlugIn $IID_IEnumHxRegPlugIn

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF ppIHxRegPlugIn AS IHxRegPlugIn _             ' __out IHxRegPlugIn** ppIHxRegPlugIn
   , BYREF pceltFetched AS DWORD _                      ' __out unsigned long* pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumHxRegPlugIn _                 ' __out IEnumHxRegPlugIn** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHxRegPlugIn_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegisterSession
' IID = {31411218-A502-11D2-BBCA-00C04F8EC294}
' IHxRegisterSession Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegisterSession_INTERFACE_DEFINED)
    %IHxRegisterSession_INTERFACE_DEFINED = 1

INTERFACE IHxRegisterSession $IID_IHxRegisterSession

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateTransaction <75265> ( _                 ' VTable offset = 28
     BYVAL bstrInToken AS WSTRING _                     ' __in BSTR bstrInToken
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrToken
   ' =====================================================================================
   METHOD PostponeTransaction <75268> ( _               ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrToken
   ' =====================================================================================
   METHOD ContinueTransaction <75269> ( _               ' VTable offset = 36
     BYVAL bstrToken AS WSTRING _                       ' __in BSTR bstrToken
   )                                                    ' void
   ' =====================================================================================
   METHOD CommitTransaction <75266> ( _                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD RevertTransaction <75267> ( _                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRegistrationObject <75270> ( _             ' VTable offset = 48
     BYVAL type AS LONG _                               ' __in HxRegisterSession_InterfaceType type
   ) AS IDispatch                                       ' __retval_out IDispatch** ppIDispatch
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegisterSession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxPlugIn
' IID = {314111DA-A502-11D2-BBCA-00C04F8EC294}
' IHxPlugIn Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxPlugIn_INTERFACE_DEFINED)
    %IHxPlugIn_INTERFACE_DEFINED = 1

INTERFACE IHxPlugIn $IID_IHxPlugIn

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RegisterHelpPlugIn <66304> ( _                ' VTable offset = 28
     BYVAL bstrProductNamespace AS WSTRING _            ' __in BSTR bstrProductNamespace
   , BYVAL bstrProductHxt AS WSTRING _                  ' __in BSTR bstrProductHxt
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrHxt AS WSTRING _                         ' __in BSTR bstrHxt
   , BYVAL bstrHxa AS WSTRING _                         ' __in BSTR bstrHxa
   , BYVAL options AS LONG _                            ' __in long options
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveHelpPlugIn <66305> ( _                  ' VTable offset = 32
     BYVAL bstrProductNamespace AS WSTRING _            ' __in BSTR bstrProductNamespace
   , BYVAL bstrProductHxt AS WSTRING _                  ' __in BSTR bstrProductHxt
   , BYVAL bstrNamespace AS WSTRING _                   ' __in BSTR bstrNamespace
   , BYVAL bstrHxt AS WSTRING _                         ' __in BSTR bstrHxt
   , BYVAL bstrHxa AS WSTRING _                         ' __in BSTR bstrHxa
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxPlugIn_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxInitialize
' IID = {314111AE-A502-11D2-BBCA-00C04F8EC294}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxInitialize_INTERFACE_DEFINED)
    %IHxInitialize_INTERFACE_DEFINED = 1

INTERFACE IHxInitialize $IID_IHxInitialize

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Initialize <72192> ( _                        ' VTable offset = 28
     BYVAL InitString AS WSTRING _                      ' __in BSTR InitString
   , BYVAL options AS LONG _                            ' __in long options
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET filter <72193> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pFilterMoniker
   ' =====================================================================================
   PROPERTY SET filter <72193> ( _                      ' VTable offset = 36
     BYVAL pFilterMoniker AS WSTRING _                  ' __in BSTR pFilterMoniker
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxInitialize_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxCancel
' IID = {31411225-A502-11D2-BBCA-00C04F8EC294}
' IHxCancel Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxCancel_INTERFACE_DEFINED)
    %IHxCancel_INTERFACE_DEFINED = 1

INTERFACE IHxCancel $IID_IHxCancel

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Cancel <76032> ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out HxCancelStatus* pbCancel
   ' =====================================================================================
   PROPERTY SET Cancel <76032> ( _                      ' VTable offset = 32
     BYVAL pbCancel AS LONG _                           ' __in HxCancelStatus pbCancel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxCancel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IHxRegisterProtocol
' IID = {31411227-A502-11D2-BBCA-00C04F8EC294}
' IHxRegisterProtocol Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IHxRegisterProtocol_INTERFACE_DEFINED)
    %IHxRegisterProtocol_INTERFACE_DEFINED = 1

INTERFACE IHxRegisterProtocol $IID_IHxRegisterProtocol

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Register <1610743808> ( _                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Unregister <1610743809> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHxRegisterProtocol_INTERFACE_DEFINED__ */
