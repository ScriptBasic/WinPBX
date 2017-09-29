' ########################################################################################
' Microsoft Windows
' File: IACOM.inc
' Library name: COMINKANALYSISLib
' Version: 1.0, Locale ID = 0
' Library GUID: {1761E494-A3D0-4F8E-87C5-C09566B22972}
' Path: C:\Program Files\Common Files\Microsoft Shared\Ink\IACom.dll
' Contents: Microsoft Tablet PC COM InkAnalysis Library, version 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IACOM_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {3C3E7657-4F0C-3FC4-8A89-A5B0F7EB480A}
$PROGID_AnalysisRegion1 = "ComInkAnalysislib.AnalysisRegion.1"
' CLSID = {B4BAB526-5BA1-3C4D-AF21-CFDCD9AAF2D2}
$PROGID_InkAnalyzer1 = "ComInkAnalysislib.InkAnalyzer.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {3C3E7657-4F0C-3FC4-8A89-A5B0F7EB480A}
$PROGID_AnalysisRegion = "ComInkAnalysislib.AnalysisRegion"
' CLSID = {B4BAB526-5BA1-3C4D-AF21-CFDCD9AAF2D2}
$PROGID_InkAnalyzer = "ComInkAnalysislib.InkAnalyzer"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AnalysisRegion = GUID$("{3C3E7657-4F0C-3FC4-8A89-A5B0F7EB480A}")
$CLSID_InkAnalyzer = GUID$("{B4BAB526-5BA1-3C4D-AF21-CFDCD9AAF2D2}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAnalysisAlternate = GUID$("{5DB42FCE-8FDE-3E45-8C4A-224C89034F02}")
$IID_IAnalysisAlternates = GUID$("{4262DF99-1C25-3CF8-98CB-4528DE750F08}")
$IID_IAnalysisRegion = GUID$("{F76EBC66-ABEF-3248-AE9B-F20D4B9149FE}")
$IID_IAnalysisStatus = GUID$("{8E16FC8B-F1DC-38C9-BB8F-7EF7B0D6C5AE}")
$IID_IAnalysisWarning = GUID$("{B7BC3EF6-C944-33C5-8917-19BD3E0C8327}")
$IID_IAnalysisWarnings = GUID$("{304ADA62-DEC1-35BF-84AE-A61BB846ADD7}")
$IID_IContextLink = GUID$("{715389A8-84B1-3B52-98FC-E2CCCD27D4B9}")
$IID_IContextLinks = GUID$("{2914EB5A-8B3D-4381-A733-1509A2295394}")
$IID_IContextNode = GUID$("{160BC1B3-5997-3D3C-9E5A-E38BCB212047}")
$IID_IContextNodes = GUID$("{23A56238-A883-4393-B539-8C1E2996B7A2}")
$IID_IInkAnalysisRecognizer = GUID$("{BD5F33DF-BEBB-3D05-98AC-F0986D3BEF17}")
$IID_IInkAnalysisRecognizers = GUID$("{7C3B2C8F-1ADD-309A-9201-22C6E0DDA633}")
$IID_IInkAnalyzer = GUID$("{31F8B4AE-F970-3A72-8595-867D286E3B7B}")
$IID_IMatchesCriteriaCallBack = GUID$("{A11BEA2D-62F5-3DDC-AEFD-5BFED2ED43E9}")
$IID__IAnalysisEvents = GUID$("{67CCF9D3-FE75-338D-BB4B-FD0FF18C8258}")
$IID__IAnalysisProxyEvents = GUID$("{70049599-2E75-3FEC-A597-C8191105F4FB}")

' ========================================================================================
' StrokeType enum
' Special values used for specifying the Stroke Types.
' ========================================================================================

%StrokeType_Unclassified                                = 0
%StrokeType_Writing                                     = 1
%StrokeType_Drawing                                     = 2

' ========================================================================================
' ConfirmationType enum
' Special values used for specifying the Confirmation Types.
' ========================================================================================

%ConfirmationType_None                                  = 0
%ConfirmationType_NodeTypeAndProperties                 = 3
%ConfirmationType_TopBoundary                           = 4

' ========================================================================================
' ContextLinkDirection enum
' Special values used for specifying ContextLink directions.
' ========================================================================================

%ContextLinkDirection_LinksWith                         = 0
%ContextLinkDirection_LinksFrom                         = 1
%ContextLinkDirection_LinksTo                           = 2

' ========================================================================================
' AnalysisWarningCode enum
' Special values used for specifying AnalysisWarning Codes.
' ========================================================================================

%AnalysisWarningCode_Aborted                                   = 0
%AnalysisWarningCode_NoMatchingInkAnalysisRecognizerFound      = 1
%AnalysisWarningCode_FactoidNotSupported                       = 2
%AnalysisWarningCode_FactoidCoercionNotSupported               = 3
%AnalysisWarningCode_GuideNotSupported                         = 4
%AnalysisWarningCode_WordlistNotSupported                      = 5
%AnalysisWarningCode_WordModeNotSupported                      = 6
%AnalysisWarningCode_PartialDictionaryTermsNotSupported        = 7
%AnalysisWarningCode_TextRecognitionProcessFailed              = 8
%AnalysisWarningCode_AddInkToRecognizerFailed                  = 9
%AnalysisWarningCode_SetPrefixSuffixFailed                     = 10
%AnalysisWarningCode_InkAnalysisRecognizerInitializationFailed = 11
%AnalysisWarningCode_ConfirmedWithoutInkRecognition            = 12
%AnalysisWarningCode_BackgroundException                       = 13
%AnalysisWarningCode_ContextNodeLocationNotSet                 = 14
%AnalysisWarningCode_LanguageIdNotRespected                    = 15
%AnalysisWarningCode_EnableUnicodeCharacterRangesNotSupported  = 16
%AnalysisWarningCode_TopInkBreaksOnlyNotSupported              = 17
%AnalysisWarningCode_AnalysisAlreadyRunning                    = 18

' ========================================================================================
' InkAnalysisRecognizerCapabilities enum
' Spcial values used for identifying Recognizer Capabilities.
' ========================================================================================

%RC_None                                                = 0
%RC_DoNotCare                                           = &H1
%RC_Object                                              = &H2
%RC_FreeInput                                           = &H4
%RC_LinedInput                                          = &H8
%RC_BoxedInput                                          = &H10
%RC_CharacterAutoCompletionInput                        = &H20
%RC_RightAndDown                                        = &H40
%RC_LeftAndDown                                         = &H80
%RC_DownAndLeft                                         = &H100
%RC_DownAndRight                                        = &H200
%RC_ArbitraryAngle                                      = &H400
%RC_Lattice                                             = &H800
%RC_AdviseInkChange                                     = &H1000
%RC_StrokeReorder                                       = &H2000
%RC_Personalizable                                      = &H4000
%RC_PrefersArbitraryAngle                               = &H8000
%RC_PrefersParagraphBreaking                            = &H10000
%RC_PrefersSegmentationRecognition                      = &H20000

' ========================================================================================
' AnalysisModes enum
' Special values used for specifying the Analysis MOdes.
' ========================================================================================

%AnalysisModes_None                                     = 0
%AnalysisModes_AutomaticReconciliation                  = &H2
%AnalysisModes_StrokeCacheAutoCleanup                   = &H4
%AnalysisModes_Personalization                          = &H8
%AnalysisModes_Default                                  = &HD

' ========================================================================================
' RecognitionConfidence enum
' Special values used for specifying the Recognition Confidence.
' ========================================================================================

%RecognitionConfidence_Strong                           = 0
%RecognitionConfidence_Intermediate                     = 1
%RecognitionConfidence_Poor                             = 2
%RecognitionConfidence_Unknown                          = 3

' ========================================================================================
' SemanticType enum
' Special values used for specifying a node's semantic type.
' ========================================================================================

%SemanticType_None                                      = 0
%SemanticType_Underline                                 = 1
%SemanticType_Strikethrough                             = 2
%SemanticType_Highlight                                 = 3
%SemanticType_ScratchOut                                = 4
%SemanticType_VerticalRange                             = 5
%SemanticType_Callout                                   = 6
%SemanticType_Enclosure                                 = 7
%SemanticType_Comment                                   = 100
%SemanticType_Container                                 = 200
%SemanticType_Connector                                 = 201

' ========================================================================================
' InkAnalysisRecognizerGuide record
' ========================================================================================

' // Size = 44 bytes
TYPE InkAnalysisRecognizerGuide DWORD
   rectWritingBox AS RECT
   rectDrawnBox   AS RECT
   cRows          AS LONG   ' long
   cColumns       AS LONG   ' long
   midline        AS LONG   ' long
END TYPE

' ########################################################################################
' Interface name = IInkAnalyzer
' IID = {31F8B4AE-F970-3A72-8595-867D286E3B7B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInkAnalyzer_INTERFACE_DEFINED)
    %IInkAnalyzer_INTERFACE_DEFINED = 1

INTERFACE IInkAnalyzer $IID_IInkAnalyzer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDirtyRegion ( _                            ' VTable offset = 12
     BYREF ppDirtyRegion AS IAnalysisRegion _           ' __out IAnalysisRegion **ppDirtyRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirtyRegion ( _                            ' VTable offset = 16
     BYVAL pDirtyRegion AS IAnalysisRegion _            ' __in IAnalysisRegion *pDirtyRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeType ( _                             ' VTable offset = 20
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYVAL StrokeType AS LONG _                         ' __in StrokeType StrokeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokesType ( _                            ' VTable offset = 24
     BYVAL ulStrokeIdCount AS DWORD _                   ' __in ULONG ulStrokeIdCount
   , BYREF plStrokes AS LONG _                          ' __in LONG *plStrokes
   , BYVAL StrokeType AS LONG _                         ' __in StrokeType StrokeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeType ( _                             ' VTable offset = 28
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYREF pStrokeType AS LONG _                        ' __out *pStrokeType StrokeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokeLanguageId ( _                       ' VTable offset = 32
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYVAL lLanguageId AS LONG _                        ' __in LONG lLanguageId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokesLanguageId ( _                      ' VTable offset = 36
     BYVAL ulStrokeIdCount AS DWORD _                   ' __in ULONG ulStrokeIdCount
   , BYREF plStrokes AS LONG _                          ' __in LONG *plStrokes
   , BYVAL lStrokesLCID AS LONG _                       ' __in LONG lStrokesLCID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeLanguageId ( _                       ' VTable offset = 40
     BYVAL strokeId AS LONG _                           ' __in LONG strokeId
   , BYREF plLanguageId AS LONG _                       ' __out LONG *plLanguageId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootNode ( _                               ' VTable offset = 44
     BYREF ppRootNode AS IContextNode _                 ' __out IContextNode **ppRootNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackgroundAnalyze ( _                         ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Analyze ( _                                   ' VTable offset = 52
     BYREF ppStatus AS IAnalysisStatus _                ' __out IAnalysisStatus **ppStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAnalyzing ( _                               ' VTable offset = 56
     BYREF pbAnalyzing AS INTEGER _                     ' __out VARIANT_BOOL *pbAnalyzing
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconcile ( _                                 ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransactionalReconcile ( _                    ' VTable offset = 64
     BYVAL lTimeLimit AS LONG _                         ' __in LONG lTimeLimit
   , BYREF pbMoreToReconcile AS INTEGER _               ' __out VARIANT_BOOL *pbMoreToReconcile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 68
     BYREF ppAbortedRegion AS IAnalysisRegion _         ' __out IAnalysisRegion **ppAbortedRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInkAnalysisRecognizersByPriority ( _       ' VTable offset = 72
     BYREF ppInkAnalysisRecognizers AS IInkAnalysisRecognizers _ ' __out IInkAnalysisRecognizers **ppInkAnalysisRecognizers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecognizedString ( _                       ' VTable offset = 76
     BYREF pbstrRecognizedString AS WSTRING _           ' __out BSTR *pbstrRecognizedString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStroke ( _                                 ' VTable offset = 80
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYVAL ulStrokePacketDataCount AS DWORD _           ' __in ULONG ulStrokePacketDataCount
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo IContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStrokes ( _                                ' VTable offset = 84
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in LONG *pStrokePacketDescriptionGuids
   , BYREF pulPacketDataCountPerStroke AS DWORD _       ' __in ULONG *pulPacketDataCountPerStroke
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo IContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStrokeForLanguage ( _                      ' VTable offset = 88
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYVAL lStrokeLCID AS LONG _                        ' __in LONG lStrokeLCID
   , BYVAL ulStrokePacketDataCount AS DWORD _           ' __in ULONG ulStrokePacketDataCount
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo IContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStrokesForLanguage ( _                     ' VTable offset = 92
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plIdofStrokesToAdd AS LONG _                 ' __in LONG *plIdofStrokesToAdd
   , BYVAL lStrokesLCID AS LONG _                       ' __in LONG lStrokesLCID
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYREF pulPacketDataCountPerStroke AS DWORD _       ' __in ULONG *pulPacketDataCountPerStroke
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearStrokeData ( _                           ' VTable offset = 96
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStroke ( _                              ' VTable offset = 100
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStrokes ( _                             ' VTable offset = 104
     BYVAL ulStrokeIdCount AS DWORD _                   ' __in ULONG ulStrokeIdCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateStrokesData ( _                         ' VTable offset = 108
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYREF pulPacketDataCountPerStroke AS DWORD _       ' __in ULONG *pulPacketDataCountPerStroke
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysisModes ( _                          ' VTable offset = 112
     BYREF pAnalysisMode AS LONG _                      ' __out AnalysisModes *pAnalysisMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnalysisModes ( _                          ' VTable offset = 116
     BYVAL analysisMode AS LONG _                       ' __in AnalysisModes analysisMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAnalysisHint ( _                        ' VTable offset = 120
     BYREF ppAnalysisHint AS IContextNode _             ' __out IContextNode **ppAnalysisHint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAnalysisHint ( _                        ' VTable offset = 124
     BYVAL pHintToDelete AS IContextNode _              ' __in IContextNode *pHintToDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysisHints ( _                          ' VTable offset = 128
     BYREF ppAnalysisHints AS IContextNodes _           ' __out IContextNodes **ppAnalysisHints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysisHintsByName ( _                    ' VTable offset = 132
     BYVAL hintName AS WSTRING _                        ' __in BSTR hintName
   , BYREF ppAnalysisHints AS IContextNodes _           ' __out IContextNodes **ppAnalysisHints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateContextNodes ( _                        ' VTable offset = 136
     BYREF ppContextNodes AS IContextNodes _            ' __out IContextNodes **ppContextNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternatesForContextNodes ( _              ' VTable offset = 140
     BYVAL pContextNodes AS IContextNodes _             ' __in IContextNodes *pContextNodes
   , BYVAL ulMaximumAlternates AS DWORD _               ' __in ULONG ulMaximumAlternates
   , BYREF ppAlternates AS IAnalysisAlternates _        ' __out IAnalysisAlternates **ppAlternates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternatesForStrokes ( _                   ' VTable offset = 144
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokes AS LONG _                          ' __in LONG *plStrokes
   , BYVAL ulMaximumAlternates AS DWORD _               ' __in ULONG ulMaximumAlternates
   , BYREF ppAlternates AS IAnalysisAlternates _        ' __out IAnalysisAlternates **ppAlternates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 148
     BYREF ppAlternates AS IAnalysisAlternates _        ' __out IAnalysisAlternates **ppAlternates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyTopAlternate ( _                        ' VTable offset = 152
     BYVAL pAlternate AS IAnalysisAlternate _           ' __in IAnalysisAlternate *pAlternate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyTopAlternateWithConfirmation ( _        ' VTable offset = 156
     BYVAL alternate AS IAnalysisAlternate _            ' __in IAnalysisAlternate *alternate
   , BYVAL fconfirmAutomatically AS INTEGER _           ' __in VARIANT_BOOL fconfirmAutomatically
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCustomRecognizer ( _                    ' VTable offset = 160
     BYREF pInkAnalysisRecognizerId AS GUID _           ' __in *pInkAnalysisRecognizerId GUID <record>
   , BYREF ppContextNode AS IContextNode _              ' __out **ppContextNode IContextNode <interface>
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStrokeToCustomRecognizer ( _               ' VTable offset = 164
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYVAL ulStrokePacketDataCount AS DWORD _           ' __in ULONG ulStrokePacketDataCount
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYVAL pCustomRecognizer AS IContextNode _          ' __in IContextNode *pCustomRecognizer
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStrokesToCustomRecognizer ( _              ' VTable offset = 168
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYVAL ulStrokePacketDescriptionCount AS DWORD _    ' __in ULONG ulStrokePacketDescriptionCount
   , BYREF pStrokePacketDescriptionGuids AS GUID _      ' __in GUID *pStrokePacketDescriptionGuids
   , BYREF pulPacketDataCountPerStroke AS DWORD _       ' __in ULONG *pulPacketDataCountPerStroke
   , BYREF plStrokePacketData AS LONG _                 ' __in LONG *plStrokePacketData
   , BYVAL pCustomRecognizer AS IContextNode _          ' __in IContextNode *pCustomRecognizer
   , BYREF ppContextNodeStrokeAddedTo AS IContextNode _ ' __out IContextNode **ppContextNodeStrokeAddedTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNode ( _                                  ' VTable offset = 172
     BYREF pId AS GUID _                                ' __in GUID *pId
   , BYREF ppContextNodeFound AS IContextNode _         ' __out IContextNode **ppContextNodeFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindLeafNodes ( _                             ' VTable offset = 176
     BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindInkLeafNodesForStrokes ( _                ' VTable offset = 180
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindInkLeafNodes ( _                          ' VTable offset = 184
     BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNodesOfType ( _                           ' VTable offset = 188
     BYREF pNodeType AS GUID _                          ' __in GUID *pNodeType
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNodesOfTypeForStrokes ( _                 ' VTable offset = 192
     BYREF pNodeType AS GUID _                          ' __in GUID *pNodeType
   , BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNodesOfTypeInSubTree ( _                  ' VTable offset = 196
     BYREF pNodeType AS GUID _                          ' __in GUID *pNodeType
   , BYVAL pContextNodeToSearchFrom AS IContextNode _   ' __in IContextNode *pContextNodeToSearchFrom
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNodesWithCallBack ( _                     ' VTable offset = 200
     BYVAL pCriteria AS IMatchesCriteriaCallBack _      ' __in IMatchesCriteriaCallBack *pCriteria
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNodesWithCallBackInSubTree ( _            ' VTable offset = 204
     BYVAL pCriteria AS IMatchesCriteriaCallBack _      ' __in IMatchesCriteriaCallBack *pCriteria
   , BYVAL pContextNodeToSearchFrom AS IContextNode _   ' __in IContextNode *pContextNodeToSearchFrom
   , BYREF ppContextNodesFound AS IContextNodes _       ' __out IContextNodes **ppContextNodesFound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadResults ( _                               ' VTable offset = 208
     BYVAL ulDataSize AS DWORD _                        ' __in ULONG ulDataSize
   , BYREF pbSerializedData AS BYTE _                   ' __in BYTE *pbSerializedData
   , BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plOriginalStrokeIds AS LONG _                ' __in LONG *plOriginalStrokeIds
   , BYREF plModifiedStrokeIds AS LONG _                ' __in LONG *plModifiedStrokeIds
   , BYREF pfRetVal AS INTEGER _                        ' __out VARIANT_BOOL *pfRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveResults ( _                               ' VTable offset = 212
     BYVAL ulMappedStrokeIdsCount AS DWORD _            ' __in ULONG ulMappedStrokeIdsCount
   , BYREF plOriginalStrokeIds AS LONG _                ' __in LONG *plOriginalStrokeIds
   , BYREF plModifiedStrokeIds AS LONG _                ' __in LONG *plModifiedStrokeIds
   , BYREF pulSerializedDataSize AS DWORD _             ' __inout ULONG *pulSerializedDataSize
   , BYREF ppbSerializedData AS DWORD _                 ' __out BYTE **ppbSerializedData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveResultsForNodes ( _                       ' VTable offset = 216
     BYVAL ulMappedStrokeIdsCount AS DWORD _            ' __in ULONG ulMappedStrokeIdsCount
   , BYREF plOriginalStrokeIds AS LONG _                ' __in LONG *plOriginalStrokeIds
   , BYREF plModifiedStrokeIds AS LONG _                ' __in LONG *plModifiedStrokeIds
   , BYVAL pContextNodes AS IContextNodes _             ' __in IContextNodes *pContextNodes
   , BYREF pulSerializedDataSize AS DWORD _             ' __inout ULONG *pulSerializedDataSize
   , BYREF ppbSerializedData AS DWORD _                 ' __out BYTE **ppbSerializedData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveResultsForStrokes ( _                     ' VTable offset = 220
     BYVAL ulMappedStrokeIdsCount AS DWORD _            ' __in ULONG ulMappedStrokeIdsCount
   , BYREF plOriginalStrokeIds AS LONG _                ' __in LONG *plOriginalStrokeIds
   , BYREF plModifiedStrokeIds AS LONG _                ' __in LONG *plModifiedStrokeIds
   , BYVAL ulStrokeIdCount AS DWORD _                   ' __in ULONG ulStrokeIdCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYREF pulSerializedDataSize AS DWORD _             ' __inout ULONG *pulSerializedDataSize
   , BYREF ppbSerializedData AS DWORD _                 ' __out BYTE **ppbSerializedData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodesFromTextRange ( _                     ' VTable offset = 224
     BYREF plStart AS LONG _                            ' __inout LONG *plStart
   , BYREF plLength AS LONG _                           ' __inout LONG *plLength
   , BYREF ppContextNodes AS IContextNodes _            ' __out IContextNodes **ppContextNodes
   , BYVAL pNodesToSearch AS IContextNodes _            ' __in_opt IContextNodes *pNodesToSearch [default value = NOTHING]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextRangeFromNodes ( _                     ' VTable offset = 228
     BYREF plStart AS LONG _                            ' __out LONG *plStart
   , BYREF plLength AS LONG _                           ' __out LONG *plLength
   , BYVAL pNodesToSearch AS IContextNodes _            ' __in IContextNodes *pNodesToSearch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Search ( _                                    ' VTable offset = 232
     BYVAL bstrPhraseToMatch AS WSTRING _               ' __in BSTR bstrPhraseToMatch
   , BYREF pulSearchResultCount AS DWORD _              ' __inout ULONG *pulSearchResultCount
   , BYREF ppulStrokeCountPerResult AS DWORD _          ' __out ULONG **ppulStrokeCountPerResult
   , BYREF pulStrokeIdsCount AS DWORD _                 ' __inout ULONG *pulStrokeIdsCount
   , BYREF ppulStrokeIds AS DWORD _                     ' __out ULONG **ppulStrokeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SearchWithLanguageId ( _                      ' VTable offset = 236
     BYVAL bstrPhraseToMatch AS WSTRING _               ' __in BSTR bstrPhraseToMatch
   , BYVAL lSearchStringLanguageId AS LONG _            ' __in LONG lSearchStringLanguageId
   , BYREF pulSearchResultCount AS DWORD _              ' __inout ULONG *pulSearchResultCount
   , BYREF ppulStrokeCountPerResult AS DWORD _          ' __out ULONG **ppulStrokeCountPerResult
   , BYREF pulStrokeIdsCount AS DWORD _                 ' __inout ULONG *pulStrokeIdsCount
   , BYREF ppulStrokeIds AS DWORD _                     ' __out ULONG **ppulStrokeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInkAnalyzer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IContextNode
' IID = {160BC1B3-5997-3D3C-9E5A-E38BCB212047}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextNode_INTERFACE_DEFINED)
    %IContextNode_INTERFACE_DEFINED = 1

INTERFACE IContextNode $IID_IContextNode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 12
     BYREF pId AS GUID _                                ' __out GUID *pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
     BYREF pContextNodeType AS GUID _                   ' __out GUID *pContextNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocation ( _                               ' VTable offset = 20
     BYREF ppIAnalysisRegion AS IAnalysisRegion _       ' __out IAnalysisRegion **ppIAnalysisRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeName ( _                               ' VTable offset = 24
     BYREF pbstrContextNodeType AS WSTRING _            ' __out BSTR *pbstrContextNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocation ( _                               ' VTable offset = 28
     BYVAL pIAnalysisRegion AS IAnalysisRegion _        ' __in IAnalysisRegion *pIAnalysisRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentNode ( _                             ' VTable offset = 32
     BYREF ppParentContextNode AS IContextNode _        ' __out IContextNode **ppParentContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reparent ( _                                  ' VTable offset = 36
     BYVAL pNewParent AS IContextNode _                 ' __in IContextNode *pNewParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubNodes ( _                               ' VTable offset = 40
     BYREF ppSubContextNodes AS IContextNodes _         ' __out IContextNodes **ppSubContextNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSubNode ( _                             ' VTable offset = 44
     BYREF pNodeType AS GUID _                          ' __in GUID *pNodeType
   , BYREF ppContextNodeCreated AS IContextNode _       ' __out IContextNode **ppContextNodeCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePartiallyPopulatedSubNode ( _           ' VTable offset = 48
     BYREF pNodeType AS GUID _                          ' __in GUID *pNodeType
   , BYREF pNodeId AS GUID _                            ' __in GUID *pNodeId
   , BYVAL pNodeLocation AS IAnalysisRegion _           ' __in IAnalysisRegion *pNodeLocation
   , BYREF ppPartiallyPopulatedContextNodeCreated AS IContextNode _ ' __out IContextNode **ppPartiallyPopulatedContextNodeCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPartiallyPopulated ( _                     ' VTable offset = 52
     BYREF pfPartiallyPopulated AS INTEGER _            ' __out VARIANT_BOOL *pfPartiallyPopulated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPartiallyPopulated ( _                     ' VTable offset = 56
     BYVAL fPartiallyPopulated AS INTEGER _             ' __in VARIANT_BOOL fPartiallyPopulated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadPropertiesData ( _                        ' VTable offset = 60
     BYVAL cbPropertiesDataSize AS DWORD _              ' __in ULONG cbPropertiesDataSize
   , BYREF pbPropertiesData AS BYTE _                   ' __in BYTE *pbPropertiesData
   , BYREF pfSuccessful AS INTEGER _                    ' __out VARIANT_BOOL *pfSuccessful
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SavePropertiesData ( _                        ' VTable offset = 64
     BYREF pulPropertiesDataSize AS DWORD _             ' __inout ULONG *pulPropertiesDataSize
   , BYREF ppbPropertiesData AS DWORD _                 ' __out BYTE **ppbPropertiesData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteSubNode ( _                             ' VTable offset = 68
     BYVAL pContextNodeToDelete AS IContextNode _       ' __in IContextNode *pContextNodeToDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPropertyData ( _                           ' VTable offset = 72
     BYREF pPropertyDataId AS GUID _                    ' __in GUID *pPropertyDataId
   , BYVAL ulPropertyDataSize AS DWORD _                ' __in ULONG ulPropertyDataSize
   , BYREF pbPropertyData AS BYTE _                     ' __in BYTE *pbPropertyData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyData ( _                           ' VTable offset = 76
     BYREF pPropertyDataId AS GUID _                    ' __in GUID *pPropertyDataId
   , BYREF pulPropertyDataSize AS DWORD _               ' __inout ULONG *pulPropertyDataSize
   , BYREF ppbPropertyData AS DWORD _                   ' __out BYTE **ppbPropertyData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePropertyData ( _                        ' VTable offset = 80
     BYREF pPropertyDataId AS GUID _                    ' __in GUID *pPropertyDataId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDataIds ( _                        ' VTable offset = 84
     BYREF pulGuidCount AS DWORD _                      ' __inout ULONG *pulGuidCount
   , BYREF ppGuids AS GUID _                            ' __out GUID **ppGuids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContainsPropertyData ( _                      ' VTable offset = 88
     BYREF pPropertyDataId AS GUID _                    ' __in GUID *pPropertyDataId
   , BYREF pbContains AS INTEGER _                      ' __out VARIANT_BOOL *pbContains
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrokes ( _                                ' VTable offset = 92
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeIds ( _                              ' VTable offset = 96
     BYREF pulStrokeIdsCount AS DWORD _                 ' __inout ULONG *pulStrokeIdsCount
   , BYREF pplStrokes AS DWORD _                        ' __out LONG **pplStrokes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeCount ( _                            ' VTable offset = 100
     BYREF pulStrokeCount AS DWORD _                    ' __out ULONG *pulStrokeCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokePacketDataById ( _                   ' VTable offset = 104
     BYVAL strokeId AS LONG _                           ' __in LONG strokeId
   , BYREF pStrokePacketDataCount AS DWORD _            ' __inout ULONG *pStrokePacketDataCount
   , BYREF pplStrokePacketData AS DWORD _               ' __out LONG **pplStrokePacketData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokePacketDescriptionById ( _            ' VTable offset = 108
     BYVAL lStrokeId AS LONG _                          ' __in LONG lStrokeId
   , BYREF pulStrokePacketDescriptionCount AS DWORD _   ' __inout ULONG *pulStrokePacketDescriptionCount
   , BYREF ppStrokePacketDescriptionGuids AS GUID _     ' __out GUID **ppStrokePacketDescriptionGuids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveSubNodeToPosition ( _                     ' VTable offset = 112
     BYVAL pSubnodeToMove AS IContextNode _             ' __in IContextNode *pSubnodeToMove
   , BYVAL ulNewIndex AS DWORD _                        ' __in ULONG ulNewIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReparentStrokesByIdToNode ( _                 ' VTable offset = 116
     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
   , BYVAL pContextNodeDestination AS IContextNode _    ' __in IContextNode *pContextNodeDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Confirm ( _                                   ' VTable offset = 120
     BYVAL confirmedType AS LONG _                      ' __in ConfirmationType confirmedType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConfirmed ( _                               ' VTable offset = 124
     BYVAL confirmedType AS LONG _                      ' __in ConfirmationType confirmedType
   , BYREF pfTypeConfirmed AS INTEGER _                 ' __out VARIANT_BOOL *pfTypeConfirmed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextLinks ( _                           ' VTable offset = 128
     BYREF ppContextLinks AS IContextLinks _            ' __out IContextLinks **ppContextLinks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAlternateStringSupported ( _                ' VTable offset = 132
     BYVAL bstrAlternateString AS WSTRING _             ' __in BSTR bstrAlternateString
   , BYREF pfIsSupported AS INTEGER _                   ' __out VARIANT_BOOL *pfIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsStringSupported ( _                         ' VTable offset = 136
     BYREF pfIsSupported AS INTEGER _                   ' __retval_out VARIANT_BOOL *pfIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextNode_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IContextNodes
' IID = {23A56238-A883-4393-B539-8C1E2996B7A2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextNodes_INTERFACE_DEFINED)
    %IContextNodes_INTERFACE_DEFINED = 1

INTERFACE IContextNodes $IID_IContextNodes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextNode ( _                            ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppContextNode AS IContextNode _              ' __out IContextNode **ppContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddContextNode ( _                            ' VTable offset = 20
     BYVAL pContextNode AS IContextNode _               ' __in IContextNode *pContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveContextNode ( _                         ' VTable offset = 24
     BYVAL pContextNode AS IContextNode _               ' __in IContextNode *pContextNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextNodes_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisRegion
' IID = {F76EBC66-ABEF-3248-AE9B-F20D4B9149FE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisRegion_INTERFACE_DEFINED)
    %IAnalysisRegion_INTERFACE_DEFINED = 1

INTERFACE IAnalysisRegion $IID_IAnalysisRegion

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsEmpty ( _                                   ' VTable offset = 12
     BYREF pfIsEmpty AS INTEGER _                       ' __out VARIANT_BOOL *pfIsEmpty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeEmpty ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeInfinite ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInfinite ( _                                ' VTable offset = 24
     BYREF pfIsInfinite AS INTEGER _                    ' __out VARIANT_BOOL *pfIsInfinite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 28
     BYREF pClonedRegion AS IAnalysisRegion _           ' __out IAnalysisRegion **pClonedRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegionScans ( _                            ' VTable offset = 32
     BYREF pulRectCount AS DWORD _                      ' __out ULONG *pulRectCount
   , BYREF pRegionScans AS RECT _                       ' __out RECT **pRegionScans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnionRectangle ( _                            ' VTable offset = 36
     BYREF pRectangle AS RECT _                         ' __in RECT *pRectangle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnionRegion ( _                               ' VTable offset = 40
     BYVAL pRegionToUnion AS IAnalysisRegion _          ' __in IAnalysisRegion *pRegionToUnion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 44
     BYREF pBoundingRectangle AS RECT _                 ' __out RECT *pBoundingRectangle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IntersectRectangle ( _                        ' VTable offset = 48
     BYREF pIntersectingRectangle AS RECT _             ' __in RECT *pIntersectingRectangle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IntersectRegion ( _                           ' VTable offset = 52
     BYVAL pRegionToIntersect AS IAnalysisRegion _      ' __in IAnalysisRegion *pRegionToIntersect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IntersectsWith ( _                            ' VTable offset = 56
     BYREF pRectangle AS RECT _                         ' __in RECT *pRectangle
   , BYREF pfIsIntersecting AS INTEGER _                ' __out VARIANT_BOOL *pfIsIntersecting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExcludeRectangle ( _                          ' VTable offset = 60
     BYREF pExcludingRectangle AS RECT _                ' __in RECT *pExcludingRectangle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExcludeRegion ( _                             ' VTable offset = 64
     BYVAL pRegionToExclude AS IAnalysisRegion _        ' __in IAnalysisRegion *pRegionToExclude
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EqualsRegion ( _                              ' VTable offset = 68
     BYVAL pOtherRegion AS IAnalysisRegion _            ' __in IAnalysisRegion *pOtherRegion
   , BYREF pfRegionsEqual AS INTEGER _                  ' __out VARIANT_BOOL *pfRegionsEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisRegion_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IContextLink
' IID = {715389A8-84B1-3B52-98FC-E2CCCD27D4B9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextLink_INTERFACE_DEFINED)
    %IContextLink_INTERFACE_DEFINED = 1

INTERFACE IContextLink $IID_IContextLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDestinationNode ( _                        ' VTable offset = 12
     BYREF ppDstContextNodeId AS IContextNode _         ' __out IContextNode **ppDstContextNodeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceNode ( _                             ' VTable offset = 16
     BYREF ppSrcContextNodeId AS IContextNode _         ' __out IContextNode **ppSrcContextNodeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextLinkDirection ( _                   ' VTable offset = 20
     BYREF pContextLinkDirection AS LONG _              ' __out ContextLinkDirection *pContextLinkDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextLink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IContextLinks
' IID = {2914EB5A-8B3D-4381-A733-1509A2295394}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextLinks_INTERFACE_DEFINED)
    %IContextLinks_INTERFACE_DEFINED = 1

INTERFACE IContextLinks $IID_IContextLinks

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextLink ( _                            ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppContextLink AS IContextLink _              ' __out IContextLink **ppContextLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddContextLink ( _                            ' VTable offset = 20
     BYVAL pDestinationNode AS IContextNode _           ' __in IContextNode *pDestinationNode
   , BYVAL linkDirection AS LONG _                      ' __in ContextLinkDirection linkDirection
   , BYREF ppContextLinkToAdd AS IContextLink _         ' __out IContextLink **ppContextLinkToAdd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteContextLink ( _                         ' VTable offset = 24
     BYVAL pContextLinkToDelete AS IContextLink _       ' __in IContextLink *pContextLinkToDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextLinks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInkAnalysisRecognizer
' IID = {BD5F33DF-BEBB-3D05-98AC-F0986D3BEF17}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInkAnalysisRecognizer_INTERFACE_DEFINED)
    %IInkAnalysisRecognizer_INTERFACE_DEFINED = 1

INTERFACE IInkAnalysisRecognizer $IID_IInkAnalysisRecognizer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuid ( _                                   ' VTable offset = 16
     BYREF pId AS GUID _                                ' __out GUID *pId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendor ( _                                 ' VTable offset = 20
     BYREF pbstrVendor AS WSTRING _                     ' __out BSTR *pbstrVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 24
     BYREF pCapabilities AS LONG _                      ' __out InkAnalysisRecognizerCapabilities *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedProperties ( _                    ' VTable offset = 28
     BYREF pulPropertiesCount AS DWORD _                ' __inout ULONG *pulPropertiesCount
   , BYREF ppProperties AS GUID _                       ' __out GUID **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguages ( _                              ' VTable offset = 32
     BYREF pulLanguagesCount AS DWORD _                 ' __inout ULONG *pulLanguagesCount
   , BYREF ppulLanguages AS DWORD _                     ' __out ULONG **ppulLanguages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnicodeRanges ( _                          ' VTable offset = 36
     BYREF pulNumberOfRanges AS DWORD _                 ' __inout ULONG *pulNumberOfRanges
   , BYREF ppulLowUnicode AS DWORD _                    ' __out WCHAR **ppulLowUnicode
   , BYREF ppusUnicodeRangeLength AS DWORD _            ' __out USHORT **ppusUnicodeRangeLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAsHighestPriorityInkAnalysisRecognizer ( _  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInkAnalysisRecognizer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInkAnalysisRecognizers
' IID = {7C3B2C8F-1ADD-309A-9201-22C6E0DDA633}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInkAnalysisRecognizers_INTERFACE_DEFINED)
    %IInkAnalysisRecognizers_INTERFACE_DEFINED = 1

INTERFACE IInkAnalysisRecognizers $IID_IInkAnalysisRecognizers

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInkAnalysisRecognizer ( _                  ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppInkAnalysisRecognizer AS IInkAnalysisRecognizer _ ' __out IInkAnalysisRecognizer **ppInkAnalysisRecognizer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInkAnalysisRecognizers_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisAlternate
' IID = {5DB42FCE-8FDE-3E45-8C4A-224C89034F02}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisAlternate_INTERFACE_DEFINED)
    %IAnalysisAlternate_INTERFACE_DEFINED = 1

INTERFACE IAnalysisAlternate $IID_IAnalysisAlternate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAlternateNodes ( _                         ' VTable offset = 12
     BYREF ppAlternateNodes AS IContextNodes _          ' __out IContextNodes **ppAlternateNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecognizedString ( _                       ' VTable offset = 16
     BYREF pbstrRecognizedString AS WSTRING _           ' __out BSTR *pbstrRecognizedString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrokeIds ( _                              ' VTable offset = 20
     BYREF pulStrokeIdsCount AS DWORD _                 ' __inout ULONG *pulStrokeIdsCount
   , BYREF pplStrokeIds AS DWORD _                      ' __out LONG **pplStrokeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecognitionConfidence ( _                  ' VTable offset = 24
     BYREF pConfidence AS LONG _                        ' __out RecognitionConfidence *pConfidence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisAlternate_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisAlternates
' IID = {4262DF99-1C25-3CF8-98CB-4528DE750F08}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisAlternates_INTERFACE_DEFINED)
    %IAnalysisAlternates_INTERFACE_DEFINED = 1

INTERFACE IAnalysisAlternates $IID_IAnalysisAlternates

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysisAlternate ( _                      ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppAlternate AS IAnalysisAlternate _          ' __out IAnalysisAlternate **ppAlternate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisAlternates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisWarning
' IID = {B7BC3EF6-C944-33C5-8917-19BD3E0C8327}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisWarning_INTERFACE_DEFINED)
    %IAnalysisWarning_INTERFACE_DEFINED = 1

INTERFACE IAnalysisWarning $IID_IAnalysisWarning

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWarningCode ( _                            ' VTable offset = 12
     BYREF pWarningCode AS LONG _                       ' __out AnalysisWarningCode *pWarningCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeIds ( _                                ' VTable offset = 16
     BYREF pulNodeIdCount AS DWORD _                    ' __inout ULONG *pulNodeIdCount
   , BYREF ppNodeIds AS GUID _                          ' __out GUID **ppNodeIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHint ( _                                   ' VTable offset = 20
     BYREF pAnalysisHint AS IContextNode _              ' __out IContextNode **pAnalysisHint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundError ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisWarning_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisWarnings
' IID = {304ADA62-DEC1-35BF-84AE-A61BB846ADD7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisWarnings_INTERFACE_DEFINED)
    %IAnalysisWarnings_INTERFACE_DEFINED = 1

INTERFACE IAnalysisWarnings $IID_IAnalysisWarnings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pulCount AS DWORD _                          ' __out ULONG *pulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnalysisWarning ( _                        ' VTable offset = 16
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF ppIAnalysisWarning AS IAnalysisWarning _     ' __out IAnalysisWarning **ppIAnalysisWarning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisWarnings_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAnalysisStatus
' IID = {8E16FC8B-F1DC-38C9-BB8F-7EF7B0D6C5AE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAnalysisStatus_INTERFACE_DEFINED)
    %IAnalysisStatus_INTERFACE_DEFINED = 1

INTERFACE IAnalysisStatus $IID_IAnalysisStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSuccessful ( _                              ' VTable offset = 12
     BYREF pfSuccessful AS INTEGER _                    ' __out VARIANT_BOOL *pfSuccessful
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppliedChangesRegion ( _                   ' VTable offset = 16
     BYREF pAppliedChangesRegion AS IAnalysisRegion _   ' __out IAnalysisRegion **pAppliedChangesRegion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWarnings ( _                               ' VTable offset = 20
     BYREF ppAnalysisWarnings AS IAnalysisWarnings _    ' __out IAnalysisWarnings **ppAnalysisWarnings
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAnalysisStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMatchesCriteriaCallBack
' IID = {A11BEA2D-62F5-3DDC-AEFD-5BFED2ED43E9}
' IMatchesCriteriaCallBack Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMatchesCriteriaCallBack_INTERFACE_DEFINED)
    %IMatchesCriteriaCallBack_INTERFACE_DEFINED = 1

INTERFACE IMatchesCriteriaCallBack $IID_IMatchesCriteriaCallBack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EvaluateContextNode ( _                       ' VTable offset = 12
     BYVAL pContextNodeToEvaluate AS IContextNode _     ' __in IContextNode *pContextNodeToEvaluate
   , BYREF pbResult AS INTEGER _                        ' __out VARIANT_BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMatchesCriteriaCallBack_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CIAnalysisEvents
' Interface name = _IAnalysisEvents
' IID = {67CCF9D3-FE75-338D-BB4B-FD0FF18C8258}
' ########################################################################################

'CLASS CIAnalysisEvents GUID$("{7E399A35-0E05-4056-BFE7-37BE53AF4433}")

'INTERFACE IAnalysisEventsImpl GUID$("{67CCF9D3-FE75-338D-BB4B-FD0FF18C8258}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD ResultsUpdated ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pAnalysisStatus AS IAnalysisStatus _         ' __in IAnalysisStatus *pAnalysisStatus
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD IntermediateResultsUpdated ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pAnalysisStatus AS IAnalysisStatus _         ' __in IAnalysisStatus *pAnalysisStatus
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Activity () AS LONG

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD UpdateStrokesCache ( _
'     BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
'   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ReadyToReconcile () AS LONG

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS

' ########################################################################################
' Class CIAnalysisProxyEvents
' Interface name = _IAnalysisProxyEvents
' IID = {70049599-2E75-3FEC-A597-C8191105F4FB}
' _IAnalysisProxyEvents Interface
' Code generated by the TypeLib Browser 4.0.14 (c) 2010 by José Roca
' Date: 30 mar 2010   Time: 07:53:34
' ########################################################################################

'CLASS CIAnalysisProxyEvents GUID$("{08CFB278-5414-4783-B564-202AE867687F}")

'INTERFACE IAnalysisProxyEventsImpl GUID$("{70049599-2E75-3FEC-A597-C8191105F4FB}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD InkAnalyzerStateChanging ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodePropertiesUpdated ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextNodeUpdated AS IContextNode _        ' __in v *pContextNodeUpdated
'   , BYVAL ulPropertiesIdsCount AS DWORD _              ' __in ULONG ulPropertiesIdsCount
'   , BYREF pUpdatedProperties AS GUID _                 ' __in GUID *pUpdatedProperties
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PopulateContextNode ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextNodeToPopulate AS IContextNode _     ' __in IContextNode *pContextNodeToPopulate
'   , BYVAL bPopulateSubTree AS INTEGER _                ' __in VARIANT_BOOL bPopulateSubTree
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeCreated ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextNodeCreated AS IContextNode _        ' __in IContextNode *pContextNodeCreated
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeDeleting ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextNodeToBeDeleted AS IContextNode _    ' __in IContextNode *pContextNodeToBeDeleted
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeReparenting ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pNewParentContextNode AS IContextNode _      ' __in IContextNode *pNewParentContextNode
'   , BYVAL pContextNodeToBeReparented AS IContextNode _ ' __in IContextNode *pContextNodeToBeReparented
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeMovingToPosition ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pSubnodeToMove AS IContextNode _             ' __in IContextNode *pSubnodeToMove
'   , BYVAL pParentContextNode AS IContextNode _         ' __in IContextNode *pParentContextNode
'   , BYVAL ulNewIndex AS DWORD _                        ' __in ULONG ulNewIndex
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD StrokesReparented ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
'   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
'   , BYVAL pSourceContextNode AS IContextNode _         ' __in IContextNode *pSourceContextNode
'   , BYVAL pDestinationContextNode AS IContextNode _    ' __in IContextNode *pDestinationContextNode
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD NewStrokesLoaded ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL ulStrokeIdsCount AS DWORD _                  ' __in ULONG ulStrokeIdsCount
'   , BYREF plStrokeIds AS LONG _                        ' __in LONG *plStrokeIds
'   , BYVAL pNodeWithStrokes AS IContextNode _           ' __in IContextNode *pNodeWithStrokes
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeLinkAdding ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextLinkToBeAdded AS IContextLink _      ' __in IContextLink *pContextLinkToBeAdded
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ContextNodeLinkDeleting ( _
'     BYVAL pInkAnalyzer AS IInkAnalyzer _               ' __in IInkAnalyzer *pInkAnalyzer
'   , BYVAL pContextLinkToBeDeleted AS IContextLink _    ' __in IContextLink *pContextLinkToBeDeleted
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
