' ########################################################################################
' Microsoft Windows
' File: UIAutomationCoreAPI.inc
' Contents: UIAutomation core APIs, types and enums
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UIAUTOMATIONCOREAPI_INC = 1

#INCLUDE ONCE "oaidl.inc"   ' for tagVARIANT
#INCLUDE ONCE "UIAutomationCore.inc"

'// --------------------------------------------------------------------------
'//
'// General constants and types
'//
'// --------------------------------------------------------------------------

'// These are all in FACILITY_ITF
%UIA_E_ELEMENTNOTENABLED      = &H80040200&
%UIA_E_ELEMENTNOTAVAILABLE    = &H80040201&
%UIA_E_NOCLICKABLEPOINT       = &H80040202&
%UIA_E_PROXYASSEMBLYNOTLOADED = &H80040203&
'// The following are COR error codes, included here as a convenience
'// (equivalent codes are in <corerror.h>)
%UIA_E_INVALIDOPERATION       = &H80131509&   ' // COR_E_INVALIDOPERATION
%UIA_E_TIMEOUT                = &H80131505&   ' // COR_E_TIMEOUT

'// The following common managed exceptions are not represented here
'// since they already have standard COM  error codes assigned to them
'// by COM Interop:
'//   ArgumentException          E_INVALIDARG
'//   ArgumentNullException      - maps to ArgumentException

'// Other constants
%UiaAppendRuntimeId    = 3
%UiaRootObjectId       = -25

'DECLARE_HANDLE(HUIANODE);
'DECLARE_HANDLE(HUIAPATTERNOBJECT);
'DECLARE_HANDLE(HUIATEXTRANGE);
'DECLARE_HANDLE(HUIAEVENT);

' enum TreeScope
%TreeScope_Element     = &H1???
%TreeScope_Children    = &H2???
%TreeScope_Descendants = &H4???
%TreeScope_Parent      = &H8???
%TreeScope_Ancestors   = &H10???
%TreeScope_Subtree     = %TreeScope_Element OR %TreeScope_Children OR %TreeScope_Descendants

'// --------------------------------------------------------------------------
'//
'// Automation Identifier GUIDs
'//
'// --------------------------------------------------------------------------

$RuntimeId_Property_GUID                                   = GUID$("{a39eebfa-7fba-4c89-b4d4-b99e2de7d160}")
$BoundingRectangle_Property_GUID                           = GUID$("{7bbfe8b2-3bfc-48dd-b729-c794b846e9a1}")
$ProcessId_Property_GUID                                   = GUID$("{40499998-9c31-4245-a403-87320e59eaf6}")
$ControlType_Property_GUID                                 = GUID$("{ca774fea-28ac-4bc2-94ca-acec6d6c10a3}")
$LocalizedControlType_Property_GUID                        = GUID$("{8763404f-a1bd-452a-89c4-3f01d3833806}")
$Name_Property_GUID                                        = GUID$("{c3a6921b-4a99-44f1-bca6-61187052c431}")
$AcceleratorKey_Property_GUID                              = GUID$("{514865df-2557-4cb9-aeed-6ced084ce52c}")
$AccessKey_Property_GUID                                   = GUID$("{06827b12-a7f9-4a15-917c-ffa5ad3eb0a7}")
$HasKeyboardFocus_Property_GUID                            = GUID$("{cf8afd39-3f46-4800-9656-b2bf12529905}")
$IsKeyboardFocusable_Property_GUID                         = GUID$("{f7b8552a-0859-4b37-b9cb-51e72092f29f}")
$IsEnabled_Property_GUID                                   = GUID$("{2109427f-da60-4fed-bf1b-264bdce6eb3a}")
$AutomationId_Property_GUID                                = GUID$("{c82c0500-b60e-4310-a267-303c531f8ee5}")
$ClassName_Property_GUID                                   = GUID$("{157b7215-894f-4b65-84e2-aac0da08b16b}")
$HelpText_Property_GUID                                    = GUID$("{08555685-0977-45c7-a7a6-abaf5684121a}")
$ClickablePoint_Property_GUID                              = GUID$("{0196903b-b203-4818-a9f3-f08e675f2341}")
$Culture_Property_GUID                                     = GUID$("{e2d74f27-3d79-4dc2-b88b-3044963a8afb}")
$IsControlElement_Property_GUID                            = GUID$("{95f35085-abcc-4afd-a5f4-dbb46c230fdb}")
$IsContentElement_Property_GUID                            = GUID$("{4bda64a8-f5d8-480b-8155-ef2e89adb672}")
$LabeledBy_Property_GUID                                   = GUID$("{e5b8924b-fc8a-4a35-8031-cf78ac43e55e}")
$IsPassword_Property_GUID                                  = GUID$("{e8482eb1-687c-497b-bebc-03be53ec1454}")
$NewNativeWindowHandle_Property_GUID                       = GUID$("{5196b33b-380a-4982-95e1-91f3ef60e024}")
$ItemType_Property_GUID                                    = GUID$("{cdda434d-6222-413b-a68a-325dd1d40f39}")
$IsOffscreen_Property_GUID                                 = GUID$("{03c3d160-db79-42db-a2ef-1c231eede507}")
$Orientation_Property_GUID                                 = GUID$("{a01eee62-3884-4415-887e-678ec21e39ba}")
$FrameworkId_Property_GUID                                 = GUID$("{dbfd9900-7e1a-4f58-b61b-7063120f773b}")
$IsRequiredForForm_Property_GUID                           = GUID$("{4f5f43cf-59fb-4bde-a270-602e5e1141e9}")
$ItemStatus_Property_GUID                                  = GUID$("{51de0321-3973-43e7-8913-0b08e813c37f}")
$IsDockPatternAvailable_Property_GUID                      = GUID$("{2600a4c4-2ff8-4c96-ae31-8fe619a13c6c}")
$IsExpandCollapsePatternAvailable_Property_GUID            = GUID$("{929d3806-5287-4725-aa16-222afc63d595}")
$IsGridItemPatternAvailable_Property_GUID                  = GUID$("{5a43e524-f9a2-4b12-84c8-b48a3efedd34}")
$IsGridPatternAvailable_Property_GUID                      = GUID$("{5622c26c-f0ef-4f3b-97cb-714c0868588b}")
$IsInvokePatternAvailable_Property_GUID                    = GUID$("{4e725738-8364-4679-aa6c-f3f41931f750}")
$IsMultipleViewPatternAvailable_Property_GUID              = GUID$("{ff0a31eb-8e25-469d-8d6e-e771a27c1b90}")
$IsRangeValuePatternAvailable_Property_GUID                = GUID$("{fda4244a-eb4d-43ff-b5ad-ed36d373ec4c}")
$IsScrollPatternAvailable_Property_GUID                    = GUID$("{3ebb7b4a-828a-4b57-9d22-2fea1632ed0d}")
$IsScrollItemPatternAvailable_Property_GUID                = GUID$("{1cad1a05-0927-4b76-97e1-0fcdb209b98a}")
$IsSelectionItemPatternAvailable_Property_GUID             = GUID$("{8becd62d-0bc3-4109-bee2-8e6715290e68}")
$IsSelectionPatternAvailable_Property_GUID                 = GUID$("{f588acbe-c769-4838-9a60-2686dc1188c4}")
$IsTablePatternAvailable_Property_GUID                     = GUID$("{cb83575f-45c2-4048-9c76-159715a139df}")
$IsTableItemPatternAvailable_Property_GUID                 = GUID$("{eb36b40d-8ea4-489b-a013-e60d5951fe34}")
$IsTextPatternAvailable_Property_GUID                      = GUID$("{fbe2d69d-aff6-4a45-82e2-fc92a82f5917}")
$IsTogglePatternAvailable_Property_GUID                    = GUID$("{78686d53-fcd0-4b83-9b78-5832ce63bb5b}")
$IsTransformPatternAvailable_Property_GUID                 = GUID$("{a7f78804-d68b-4077-a5c6-7a5ea1ac31c5}")
$IsValuePatternAvailable_Property_GUID                     = GUID$("{0b5020a7-2119-473b-be37-5ceb98bbfb22}")
$IsWindowPatternAvailable_Property_GUID                    = GUID$("{e7a57bb1-5888-4155-98dc-b422fd57f2bc}")
$Value_Value_Property_GUID                                 = GUID$("{e95f5e64-269f-4a85-ba99-4092c3ea2986}")
$Value_IsReadOnly_Property_GUID                            = GUID$("{eb090f30-e24c-4799-a705-0d247bc037f8}")
$RangeValue_Value_Property_GUID                            = GUID$("{131f5d98-c50c-489d-abe5-ae220898c5f7}")
$RangeValue_IsReadOnly_Property_GUID                       = GUID$("{25fa1055-debf-4373-a79e-1f1a1908d3c4}")
$RangeValue_Minimum_Property_GUID                          = GUID$("{78cbd3b2-684d-4860-af93-d1f95cb022fd}")
$RangeValue_Maximum_Property_GUID                          = GUID$("{19319914-f979-4b35-a1a6-d37e05433473}")
$RangeValue_LargeChange_Property_GUID                      = GUID$("{a1f96325-3a3d-4b44-8e1f-4a46d9844019}")
$RangeValue_SmallChange_Property_GUID                      = GUID$("{81c2c457-3941-4107-9975-139760f7c072}")
$Scroll_HorizontalScrollPercent_Property_GUID              = GUID$("{c7c13c0e-eb21-47ff-acc4-b5a3350f5191}")
$Scroll_HorizontalViewSize_Property_GUID                   = GUID$("{70c2e5d4-fcb0-4713-a9aa-af92ff79e4cd}")
$Scroll_VerticalScrollPercent_Property_GUID                = GUID$("{6c8d7099-b2a8-4948-bff7-3cf9058bfefb}")
$Scroll_VerticalViewSize_Property_GUID                     = GUID$("{de6a2e22-d8c7-40c5-83ba-e5f681d53108}")
$Scroll_HorizontallyScrollable_Property_GUID               = GUID$("{8b925147-28cd-49ae-bd63-f44118d2e719}")
$Scroll_VerticallyScrollable_Property_GUID                 = GUID$("{89164798-0068-4315-b89a-1e7cfbbc3dfc}")
$Selection_Selection_Property_GUID                         = GUID$("{aa6dc2a2-0e2b-4d38-96d5-34e470b81853}")
$Selection_CanSelectMultiple_Property_GUID                 = GUID$("{49d73da5-c883-4500-883d-8fcf8daf6cbe}")
$Selection_IsSelectionRequired_Property_GUID               = GUID$("{b1ae4422-63fe-44e7-a5a5-a738c829b19a}")
$Grid_RowCount_Property_GUID                               = GUID$("{2a9505bf-c2eb-4fb6-b356-8245ae53703e}")
$Grid_ColumnCount_Property_GUID                            = GUID$("{fe96f375-44aa-4536-ac7a-2a75d71a3efc}")
$GridItem_Row_Property_GUID                                = GUID$("{6223972a-c945-4563-9329-fdc974af2553}")
$GridItem_Column_Property_GUID                             = GUID$("{c774c15c-62c0-4519-8bdc-47be573c8ad5}")
$GridItem_RowSpan_Property_GUID                            = GUID$("{4582291c-466b-4e93-8e83-3d1715ec0c5e}")
$GridItem_ColumnSpan_Property_GUID                         = GUID$("{583ea3f5-86d0-4b08-a6ec-2c5463ffc109}")
$GridItem_Parent_Property_GUID                             = GUID$("{9d912252-b97f-4ecc-8510-ea0e33427c72}")
$Dock_DockPosition_Property_GUID                           = GUID$("{6d67f02e-c0b0-4b10-b5b9-18d6ecf98760}")
$ExpandCollapse_ExpandCollapseState_Property_GUID          = GUID$("{275a4c48-85a7-4f69-aba0-af157610002b}")
$MultipleView_CurrentView_Property_GUID                    = GUID$("{7a81a67a-b94f-4875-918b-65c8d2f998e5}")
$MultipleView_SupportedViews_Property_GUID                 = GUID$("{8d5db9fd-ce3c-4ae7-b788-400a3c645547}")
$Window_CanMaximize_Property_GUID                          = GUID$("{64fff53f-635d-41c1-950c-cb5adfbe28e3}")
$Window_CanMinimize_Property_GUID                          = GUID$("{b73b4625-5988-4b97-b4c2-a6fe6e78c8c6}")
$Window_WindowVisualState_Property_GUID                    = GUID$("{4ab7905f-e860-453e-a30a-f6431e5daad5}")
$Window_WindowInteractionState_Property_GUID               = GUID$("{4fed26a4-0455-4fa2-b21c-c4da2db1ff9c}")
$Window_IsModal_Property_GUID                              = GUID$("{ff4e6892-37b9-4fca-8532-ffe674ecfeed}")
$Window_IsTopmost_Property_GUID                            = GUID$("{ef7d85d3-0937-4962-9241-b62345f24041}")
$SelectionItem_IsSelected_Property_GUID                    = GUID$("{f122835f-cd5f-43df-b79d-4b849e9e6020}")
$SelectionItem_SelectionContainer_Property_GUID            = GUID$("{a4365b6e-9c1e-4b63-8b53-c2421dd1e8fb}")
$Table_RowHeaders_Property_GUID                            = GUID$("{d9e35b87-6eb8-4562-aac6-a8a9075236a8}")
$Table_ColumnHeaders_Property_GUID                         = GUID$("{aff1d72b-968d-42b1-b459-150b299da664}")
$Table_RowOrColumnMajor_Property_GUID                      = GUID$("{83be75c3-29fe-4a30-85e1-2a6277fd106e}")
$TableItem_RowHeaderItems_Property_GUID                    = GUID$("{b3f853a0-0574-4cd8-bcd7-ed5923572d97}")
$TableItem_ColumnHeaderItems_Property_GUID                 = GUID$("{967a56a3-74b6-431e-8de6-99c411031c58}")
$Toggle_ToggleState_Property_GUID                          = GUID$("{b23cdc52-22c2-4c6c-9ded-f5c422479ede}")
$Transform_CanMove_Property_GUID                           = GUID$("{1b75824d-208b-4fdf-bccd-f1f4e5741f4f}")
$Transform_CanResize_Property_GUID                         = GUID$("{bb98dca5-4c1a-41d4-a4f6-ebc128644180}")
$Transform_CanRotate_Property_GUID                         = GUID$("{10079b48-3849-476f-ac96-44a95c8440d9}")
$ToolTipOpened_Event_GUID                                  = GUID$("{3f4b97ff-2edc-451d-bca4-95a3188d5b03}")
$ToolTipClosed_Event_GUID                                  = GUID$("{276d71ef-24a9-49b6-8e97-da98b401bbcd}")
$StructureChanged_Event_GUID                               = GUID$("{59977961-3edd-4b11-b13b-676b2a2a6ca9}")
$MenuOpened_Event_GUID                                     = GUID$("{ebe2e945-66ca-4ed1-9ff8-2ad7df0a1b08}")
$AutomationPropertyChanged_Event_GUID                      = GUID$("{2527fba1-8d7a-4630-a4cc-e66315942f52}")
$AutomationFocusChanged_Event_GUID                         = GUID$("{b68a1f17-f60d-41a7-a3cc-b05292155fe0}")
$AsyncContentLoaded_Event_GUID                             = GUID$("{5fdee11c-d2fa-4fb9-904e-5cbee894d5ef}")
$MenuClosed_Event_GUID                                     = GUID$("{3cf1266e-1582-4041-acd7-88a35a965297}")
$LayoutInvalidated_Event_GUID                              = GUID$("{ed7d6544-a6bd-4595-9bae-3d28946cc715}")
$Invoke_Invoked_Event_GUID                                 = GUID$("{dfd699f0-c915-49dd-b422-dde785c3d24b}")
$SelectionItem_ElementAddedToSelectionEvent_Event_GUID     = GUID$("{3c822dd1-c407-4dba-91dd-79d4aed0aec6}")
$SelectionItem_ElementRemovedFromSelectionEvent_Event_GUID = GUID$("{097fa8a9-7079-41af-8b9c-0934d8305e5c}")
$SelectionItem_ElementSelectedEvent_Event_GUID             = GUID$("{b9c7dbfb-4ebe-4532-aaf4-008cf647233c}")
$Selection_InvalidatedEvent_Event_GUID                     = GUID$("{cac14904-16b4-4b53-8e47-4cb1df267bb7}")
$Text_TextSelectionChangedEvent_Event_GUID                 = GUID$("{918edaa1-71b3-49ae-9741-79beb8d358f3}")
$Text_TextChangedEvent_Event_GUID                          = GUID$("{4a342082-f483-48c4-ac11-a84b435e2a84}")
$Window_WindowOpened_Event_GUID                            = GUID$("{d3e81d06-de45-4f2f-9633-de9e02fb65af}")
$Window_WindowClosed_Event_GUID                            = GUID$("{edf141f8-fa67-4e22-bbf7-944e05735ee2}")
$Invoke_Pattern_GUID                                       = GUID$("{d976c2fc-66ea-4a6e-b28f-c24c7546ad37}")
$Selection_Pattern_GUID                                    = GUID$("{66e3b7e8-d821-4d25-8761-435d2c8b253f}")
$Value_Pattern_GUID                                        = GUID$("{17faad9e-c877-475b-b933-77332779b637}")
$RangeValue_Pattern_GUID                                   = GUID$("{18b00d87-b1c9-476a-bfbd-5f0bdb926f63}")
$Scroll_Pattern_GUID                                       = GUID$("{895fa4b4-759d-4c50-8e15-03460672003c}")
$ExpandCollapse_Pattern_GUID                               = GUID$("{ae05efa2-f9d1-428a-834c-53a5c52f9b8b}")
$Grid_Pattern_GUID                                         = GUID$("{260a2ccb-93a8-4e44-a4c1-3df397f2b02b}")
$GridItem_Pattern_GUID                                     = GUID$("{f2d5c877-a462-4957-a2a5-2c96b303bc63}")
$MultipleView_Pattern_GUID                                 = GUID$("{547a6ae4-113f-47c4-850f-db4dfa466b1d}")
$Window_Pattern_GUID                                       = GUID$("{27901735-c760-4994-ad11-5919e606b110}")
$SelectionItem_Pattern_GUID                                = GUID$("{9bc64eeb-87c7-4b28-94bb-4d9fa437b6ef}")
$Dock_Pattern_GUID                                         = GUID$("{9cbaa846-83c8-428d-827f-7e6063fe0620}")
$Table_Pattern_GUID                                        = GUID$("{c415218e-a028-461e-aa92-8f925cf79351}")
$TableItem_Pattern_GUID                                    = GUID$("{df1343bd-1888-4a29-a50c-b92e6de37f6f}")
$Text_Pattern_GUID                                         = GUID$("{8615f05d-7de5-44fd-a679-2ca4b46033a8}")
$Toggle_Pattern_GUID                                       = GUID$("{0b419760-e2f4-43ff-8c5f-9457c82b56e9}")
$Transform_Pattern_GUID                                    = GUID$("{24b46fdb-587e-49f1-9c4a-d8e98b664b7b}")
$ScrollItem_Pattern_GUID                                   = GUID$("{4591d005-a803-4d5c-b4d5-8d2800f906a7}")
$Button_Control_GUID                                       = GUID$("{5a78e369-c6a1-4f33-a9d7-79f20d0c788e}")
$Calendar_Control_GUID                                     = GUID$("{8913eb88-00e5-46bc-8e4e-14a786e165a1}")
$CheckBox_Control_GUID                                     = GUID$("{fb50f922-a3db-49c0-8bc3-06dad55778e2}")
$ComboBox_Control_GUID                                     = GUID$("{54cb426c-2f33-4fff-aaa1-aef60dac5deb}")
$Edit_Control_GUID                                         = GUID$("{6504a5c8-2c86-4f87-ae7b-1abddc810cf9}")
$Hyperlink_Control_GUID                                    = GUID$("{8a56022c-b00d-4d15-8ff0-5b6b266e5e02}")
$Image_Control_GUID                                        = GUID$("{2d3736e4-6b16-4c57-a962-f93260a75243}")
$ListItem_Control_GUID                                     = GUID$("{7b3717f2-44d1-4a58-98a8-f12a9b8f78e2}")
$List_Control_GUID                                         = GUID$("{9b149ee1-7cca-4cfc-9af1-cac7bddd3031}")
$Menu_Control_GUID                                         = GUID$("{2e9b1440-0ea8-41fd-b374-c1ea6f503cd1}")
$MenuBar_Control_GUID                                      = GUID$("{cc384250-0e7b-4ae8-95ae-a08f261b52ee}")
$MenuItem_Control_GUID                                     = GUID$("{f45225d3-d0a0-49d8-9834-9a000d2aeddc}")
$ProgressBar_Control_GUID                                  = GUID$("{228c9f86-c36c-47bb-9fb6-a5834bfc53a4}")
$RadioButton_Control_GUID                                  = GUID$("{3bdb49db-fe2c-4483-b3e1-e57f219440c6}")
$ScrollBar_Control_GUID                                    = GUID$("{daf34b36-5065-4946-b22f-92595fc0751a}")
$Slider_Control_GUID                                       = GUID$("{b033c24b-3b35-4cea-b609-763682fa660b}")
$Spinner_Control_GUID                                      = GUID$("{60cc4b38-3cb1-4161-b442-c6b726c17825}")
$StatusBar_Control_GUID                                    = GUID$("{d45e7d1b-5873-475f-95a4-0433e1f1b00a}")
$Tab_Control_GUID                                          = GUID$("{38cd1f2d-337a-4bd2-a5e3-adb469e30bd3}")
$TabItem_Control_GUID                                      = GUID$("{2c6a634f-921b-4e6e-b26e-08fcb0798f4c}")
$Text_Control_GUID                                         = GUID$("{ae9772dc-d331-4f09-be20-7e6dfaf07b0a}")
$ToolBar_Control_GUID                                      = GUID$("{8f06b751-e182-4e98-8893-2284543a7dce}")
$ToolTip_Control_GUID                                      = GUID$("{05ddc6d1-2137-4768-98ea-73f52f7134f3}")
$Tree_Control_GUID                                         = GUID$("{7561349c-d241-43f4-9908-b5f091bee611}")
$TreeItem_Control_GUID                                     = GUID$("{62c9feb9-8ffc-4878-a3a4-96b030315c18}")
$Custom_Control_GUID                                       = GUID$("{f29ea0c3-adb7-430a-ba90-e52c7313e6ed}")
$Group_Control_GUID                                        = GUID$("{ad50aa1c-e8c8-4774-ae1b-dd86df0b3bdc}")
$Thumb_Control_GUID                                        = GUID$("{701ca877-e310-4dd6-b644-797e4faea213}")
$DataGrid_Control_GUID                                     = GUID$("{84b783af-d103-4b0a-8415-e73942410f4b}")
$DataItem_Control_GUID                                     = GUID$("{a0177842-d94f-42a5-814b-6068addc8da5}")
$Document_Control_GUID                                     = GUID$("{3cd6bb6f-6f08-4562-b229-e4e2fc7a9eb4}")
$SplitButton_Control_GUID                                  = GUID$("{7011f01f-4ace-4901-b461-920a6f1ca650}")
$Window_Control_GUID                                       = GUID$("{e13a7242-f462-4f4d-aec1-53b28d6c3290}")
$Pane_Control_GUID                                         = GUID$("{5c2b3f5b-9182-42a3-8dec-8c04c1ee634d}")
$Header_Control_GUID                                       = GUID$("{5b90cbce-78fb-4614-82b6-554d74718e67}")
$HeaderItem_Control_GUID                                   = GUID$("{e6bc12cb-7c8e-49cf-b168-4a93a32bebb0}")
$Table_Control_GUID                                        = GUID$("{773bfa0e-5bc4-4deb-921b-de7b3206229e}")
$TitleBar_Control_GUID                                     = GUID$("{98aa55bf-3bb0-4b65-836e-2ea30dbc171f}")
$Separator_Control_GUID                                    = GUID$("{8767eba3-2a63-4ab0-ac8d-aa50e23de978}")
$Text_AnimationStyle_Attribute_GUID                        = GUID$("{628209f0-7c9a-4d57-be64-1f1836571ff5}")
$Text_BackgroundColor_Attribute_GUID                       = GUID$("{fdc49a07-583d-4f17-ad27-77fc832a3c0b}")
$Text_BulletStyle_Attribute_GUID                           = GUID$("{c1097c90-d5c4-4237-9781-3bec8ba54e48}")
$Text_CapStyle_Attribute_GUID                              = GUID$("{fb059c50-92cc-49a5-ba8f-0aa872bba2f3}")
$Text_Culture_Attribute_GUID                               = GUID$("{c2025af9-a42d-4ced-a1fb-c6746315222e}")
$Text_FontName_Attribute_GUID                              = GUID$("{64e63ba8-f2e5-476e-a477-1734feaaf726}")
$Text_FontSize_Attribute_GUID                              = GUID$("{dc5eeeff-0506-4673-93f2-377e4a8e01f1}")
$Text_FontWeight_Attribute_GUID                            = GUID$("{6fc02359-b316-4f5f-b401-f1ce55741853}")
$Text_ForegroundColor_Attribute_GUID                       = GUID$("{72d1c95d-5e60-471a-96b1-6c1b3b77a436}")
$Text_HorizontalTextAlignment_Attribute_GUID               = GUID$("{04ea6161-fba3-477a-952a-bb326d026a5b}")
$Text_IndentationFirstLine_Attribute_GUID                  = GUID$("{206f9ad5-c1d3-424a-8182-6da9a7f3d632}")
$Text_IndentationLeading_Attribute_GUID                    = GUID$("{5cf66bac-2d45-4a4b-b6c9-f7221d2815b0}")
$Text_IndentationTrailing_Attribute_GUID                   = GUID$("{97ff6c0f-1ce4-408a-b67b-94d83eb69bf2}")
$Text_IsHidden_Attribute_GUID                              = GUID$("{360182fb-bdd7-47f6-ab69-19e33f8a3344}")
$Text_IsItalic_Attribute_GUID                              = GUID$("{fce12a56-1336-4a34-9663-1bab47239320}")
$Text_IsReadOnly_Attribute_GUID                            = GUID$("{a738156b-ca3e-495e-9514-833c440feb11}")
$Text_IsSubscript_Attribute_GUID                           = GUID$("{f0ead858-8f53-413c-873f-1a7d7f5e0de4}")
$Text_IsSuperscript_Attribute_GUID                         = GUID$("{da706ee4-b3aa-4645-a41f-cd25157dea76}")
$Text_MarginBottom_Attribute_GUID                          = GUID$("{7ee593c4-72b4-4cac-9271-3ed24b0e4d42}")
$Text_MarginLeading_Attribute_GUID                         = GUID$("{9e9242d0-5ed0-4900-8e8a-eecc03835afc}")
$Text_MarginTop_Attribute_GUID                             = GUID$("{683d936f-c9b9-4a9a-b3d9-d20d33311e2a}")
$Text_MarginTrailing_Attribute_GUID                        = GUID$("{af522f98-999d-40af-a5b2-0169d0342002}")
$Text_OutlineStyles_Attribute_GUID                         = GUID$("{5b675b27-db89-46fe-970c-614d523bb97d}")
$Text_OverlineColor_Attribute_GUID                         = GUID$("{83ab383a-fd43-40da-ab3e-ecf8165cbb6d}")
$Text_OverlineStyle_Attribute_GUID                         = GUID$("{0a234d66-617e-427f-871d-e1ff1e0c213f}")
$Text_StrikethroughColor_Attribute_GUID                    = GUID$("{bfe15a18-8c41-4c5a-9a0b-04af0e07f487}")
$Text_StrikethroughStyle_Attribute_GUID                    = GUID$("{72913ef1-da00-4f01-899c-ac5a8577a307}")
$Text_Tabs_Attribute_GUID                                  = GUID$("{2e68d00b-92fe-42d8-899a-a784aa4454a1}")
$Text_TextFlowDirections_Attribute_GUID                    = GUID$("{8bdf8739-f420-423e-af77-20a5d973a907}")
$Text_UnderlineColor_Attribute_GUID                        = GUID$("{bfa12c73-fde2-4473-bf64-1036d6aa0f45}")
$Text_UnderlineStyle_Attribute_GUID                        = GUID$("{5f3b21c0-ede4-44bd-9c36-3853038cbfeb}")

$SID_IsUIAutomationObject                                  = GUID$("{b96fdb85-7204-4724-842b-c7059dedb9d0}")

'// --------------------------------------------------------------------------
'//
'// Error handling
'//
'// --------------------------------------------------------------------------

DECLARE FUNCTION UiaGetErrorDescription IMPORT "uiautomationcore.dll" ALIAS "UiaGetErrorDescription" ( _
   BYREF pDescription AS WSTRING _                      ' __out BSTR * pDescription
 ) AS LONG                                              ' BOOL

'// --------------------------------------------------------------------------
'//
'// Conditions
'//
'// --------------------------------------------------------------------------

' enum ConditionType
%ConditionType_True     = 0
%ConditionType_False    = 1
%ConditionType_Property = 2
%ConditionType_And      = 3
%ConditionType_Or       = 4
%ConditionType_Not      = 5

' // Size = 4 bytes
TYPE UiaCondition DWORD
   ConditionType AS LONG   ' ConditionType
END TYPE

' enum PropertyConditionFlags
%PropertyConditionFlags_None       = &H00???
%PropertyConditionFlags_IgnoreCase = &H01???

' // Size = 32 bytes
TYPE UiaPropertyCondition   ' Must be 8 byte aligned
   ConditionType AS LONG         ' ConditionType
   PropertyId    AS LONG         ' PROPERTYID
   Value         AS tagVARIANT   ' VARIANT
   Flags         AS DWORD        ' PropertyConditionFlags
   alignment__   AS DWORD        ' // To keep 8 byte alignment
END TYPE

' // Size = 12 bytes
TYPE UiaAndOrCondition DWORD
   ConditionType AS LONG    ' ConditionType
   ppConditions  AS DWORD   ' UiaCondition ** ppConditions; // ptr to array-of-ptrs to conditions
   cConditions   AS DWORD   ' int
END TYPE

' // Size = 8 bytes
TYPE UiaNotCondition DWORD
   ConditionType AS LONG               ' ConditionType
   pCondition    AS UiaCondition PTR   ' UiaCondition *
END TYPE


'// --------------------------------------------------------------------------
'//
'// Cache request/response
'//
'// --------------------------------------------------------------------------

' enum AutomationElementMode
%AutomationElementMode_None = 0
%AutomationElementMode_Full = 1

' // Size = 28 bytes
TYPE UiaCacheRequest DWORD
   pViewCondition        AS UiaCondition PTR   ' UiaCondition *
   Scope                 AS DWORD              ' TreeScope
   pProperties           AS LONG PTR           ' PROPERTYID *
   cProperties           AS LONG               ' int
   pPatterns             AS LONG PTR           ' PATTERNID *
   cPatterns             AS LONG               ' int
   automationElementMode AS LONG               ' AutomationElementMode
END TYPE

DECLARE FUNCTION UiaHUiaNodeFromVariant IMPORT "uiautomationcore.dll" ALIAS "UiaHUiaNodeFromVariant" ( _
   BYREF pvar AS VARIANT _                              ' __in  VARIANT * pvar
 , BYREF phnode AS DWORD _                              ' __out HUIANODE *phnode
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaHPatternObjectFromVariant IMPORT "uiautomationcore.dll" ALIAS "UiaHPatternObjectFromVariant" ( _
   BYREF pvar AS VARIANT _                              ' __in  VARIANT * pvar
 , BYREF phobj AS DWORD _                               ' __out HUIAPATTERNOBJECT *phobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaHTextRangeFromVariant IMPORT "uiautomationcore.dll" ALIAS "UiaHTextRangeFromVariant" ( _
   BYREF pvar AS VARIANT _                              ' __in  VARIANT * pvar
 , BYREF phtextrange AS DWORD _                         ' __out HUIATEXTRANGE *phtextrange
 ) AS LONG                                              ' HRESULT

'// --------------------------------------------------------------------------
'//
'// UiaNode methods
'//
'// --------------------------------------------------------------------------

'// Used by UiaGetUpdatedCache
' enum NormalizeState
%NormalizeState_None   = 0   ' // Don't normalize
%NormalizeState_View   = 1   ' // Normalize against condition in UiaCacheRequest
%NormalizeState_Custom = 2   ' // Normalize against supplied condition

' // Size = 16 bytes
TYPE UiaFindParams DWORD
   MaxDepth       AS LONG               ' int
   FindFirst      AS LONG               ' BOOL
   ExcludeRoot    AS LONG               ' BOOL
   pFindCondition AS UiaCondition PTR   ' UiaCondition *
END TYPE

DECLARE FUNCTION UiaNodeRelease IMPORT "uiautomationcore.dll" ALIAS "UiaNodeRelease" ( _
   BYREF hnode AS DWORD _                               ' __in HUIANODE hnode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UiaGetPropertyValue IMPORT "uiautomationcore.dll" ALIAS "UiaGetPropertyValue" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYVAL propertyId AS LONG _                           ' __in  PROPERTYID propertyId
 , BYREF pValue AS VARIANT _                            ' __out VARIANT * pValue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaGetPatternProvider IMPORT "uiautomationcore.dll" ALIAS "UiaGetPatternProvider" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYVAL patternId AS LONG _                            ' __in  PATTERNID patternId
 , BYREF phobj AS DWORD _                               ' __out HUIAPATTERNOBJECT * phobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaGetRuntimeId IMPORT "uiautomationcore.dll" ALIAS "UiaGetRuntimeId" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYREF pruntimeId AS DWORD _                          ' __out SAFEARRAY ** pruntimeId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaSetFocus IMPORT "uiautomationcore.dll" ALIAS "UiaSetFocus" ( _
   BYVAL hnode AS DWORD _                               ' __in HUIANODE hnode
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaNavigate IMPORT "uiautomationcore.dll" ALIAS "UiaNavigate" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYVAL direction AS LONG _                            ' __in  NavigateDirection direction
 , BYREF pCondition AS UiaCondition _                   ' __in  UiaCondition * pCondition
 , BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYREF ppRequestedData AS DWORD _                     ' __out SAFEARRAY ** ppRequestedData
 , BYREF ppTreeStructure AS WSTRING _                   ' __out BSTR * ppTreeStructure
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaGetUpdatedCache IMPORT "uiautomationcore.dll" ALIAS "UiaGetUpdatedCache" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYVAL normalizeState AS LONG _                       ' __in  NormalizeState normalizeState
 , BYREF pNormalizeCondition AS UiaCondition _          ' __in  UiaCondition * pNormalizeCondition
 , BYREF ppRequestedData AS DWORD _                     ' __out SAFEARRAY ** ppRequestedData
 , BYREF ppTreeStructure AS WSTRING _                   ' __out BSTR * ppTreeStructure
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaFind IMPORT "uiautomationcore.dll" ALIAS "UiaFind" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYREF pParams AS UiaFindParams _                     ' __in  UiaFindParams * pParams
 , BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYREF ppRequestedData AS DWORD _                     ' __out SAFEARRAY ** ppRequestedData
 , BYREF ppOffsets AS DWORD _                           ' __out SAFEARRAY ** ppOffsets
 , BYREF ppTreeStructures AS DWORD _                    ' __out SAFEARRAY ** ppTreeStructures
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaNodeFromPoint IMPORT "uiautomationcore.dll" ALIAS "UiaNodeFromPoint" ( _
   BYVAL x AS DOUBLE _                                  ' __in  double x
 , BYVAL y AS DOUBLE _                                  ' __in  double y
 , BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYREF ppRequestedData AS DWORD _                     ' __out SAFEARRAY ** ppRequestedData
 , BYREF ppTreeStructure AS WSTRING _                   ' __out BSTR * ppTreeStructure
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaNodeFromFocus IMPORT "uiautomationcore.dll" ALIAS "UiaNodeFromFocus" ( _
   BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYREF ppRequestedData AS DWORD _                     ' __out SAFEARRAY ** ppRequestedData
 , BYREF ppTreeStructure AS WSTRING _                   ' __out BSTR * ppTreeStructure
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaNodeFromHandle IMPORT "uiautomationcore.dll" ALIAS "UiaNodeFromHandle" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF phnode AS DWORD _                              ' __out HUIANODE * phnode
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaNodeFromProvider IMPORT "uiautomationcore.dll" ALIAS "UiaNodeFromProvider" ( _
   BYVAL pProvider AS IRawElementProviderSimple _       ' __in  IRawElementProviderSimple * pProvider
 , BYREF phnode AS DWORD _                              ' __out HUIANODE * phnode
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaGetRootNode IMPORT "uiautomationcore.dll" ALIAS "UiaGetRootNode" ( _
   BYREF phnode AS DWORD _                              ' __out HUIANODE * phnode
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'inline void UiaRectSetEmpty(UiaRect & rc)
'{
'    rc.left = 0;
'    rc.top = 0;
'    rc.width = 0;
'    rc.height = 0;
'}

'inline bool UiaRectIsEmpty(const UiaRect & rc)
'{
'    return rc.width <= 0 || rc.height <= 0;
'}
'#endif

SUB UiaRectSetEmpty (BYREF rc AS UiaRect)
   rc.left  = 0
   rc.top    = 0
   rc.width  = 0
   rc.height = 0
END SUB

FUNCTION UiaRectIsEmpty(BYREF rc AS UiaRect) AS LONG
   FUNCTION = (rc.width <= 0 AND rc.height <= 0)
END FUNCTION


'// --------------------------------------------------------------------------
'//
'// Client-side provider support
'//
'// --------------------------------------------------------------------------

' enum ProviderType
%ProviderType_BaseHwnd      = 0
%ProviderType_Proxy         = 1
%ProviderType_NonClientArea = 2

DECLARE FUNCTION UiaProviderCallback IMPORT "uiautomationcore.dll" ALIAS "UiaProviderCallback" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL providerType AS LONG _                         ' __in ProviderType providerType
 ) AS DWORD                                             ' SAFEARRAY*

DECLARE SUB UiaRegisterProviderCallback IMPORT "uiautomationcore.dll" ALIAS "UiaRegisterProviderCallback" ( _
   BYVAL pCallback AS DWORD _                           ' __in UiaProviderCallback * pCallback
 )                                                      ' void

'// --------------------------------------------------------------------------
'//
'// Identifier mapping
'//
'// --------------------------------------------------------------------------

' enum AutomationIdentifierType
%AutomationIdentifierType_Property      = 0
%AutomationIdentifierType_Pattern       = 1
%AutomationIdentifierType_Event         = 2
%AutomationIdentifierType_ControlType   = 3
%AutomationIdentifierType_TextAttribute = 4

DECLARE FUNCTION UiaLookupId IMPORT "uiautomationcore.dll" ALIAS "UiaLookupId" ( _
   BYVAL type AS LONG _                                 ' __in AutomationIdentifierType type
 , BYREF pGuid AS GUID _                                ' __in const GUID* pGuid
 ) AS LONG                                              ' int

DECLARE FUNCTION UiaGetReservedNotSupportedValue IMPORT "uiautomationcore.dll" ALIAS "UiaGetReservedNotSupportedValue" ( _
   BYREF punkNotSupportedValue AS IUnknown _            ' __out IUnknown **punkNotSupportedValue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaGetReservedMixedAttributeValue IMPORT "uiautomationcore.dll" ALIAS "UiaGetReservedMixedAttributeValue" ( _
   BYREF punkMixedAttributeValue AS IUnknown _          ' __out IUnknown **punkMixedAttributeValue
 ) AS LONG                                              ' HRESULT

'// --------------------------------------------------------------------------
'//
'// Event methods
'//
'// --------------------------------------------------------------------------

'//
'// Event structs and enums
'//

' enum EventArgsType
%EventArgsType_Simple             = 0
%EventArgsType_PropertyChanged    = 1
%EventArgsType_StructureChanged   = 2
%EventArgsType_AsyncContentLoaded = 3
%EventArgsType_WindowClosed       = 4

' enum StructureChangeType
%StructureChangeType_ChildAdded          = 0
%StructureChangeType_ChildRemoved        = 1
%StructureChangeType_ChildrenInvalidated = 2
%StructureChangeType_ChildrenBulkAdded   = 3
%StructureChangeType_ChildrenBulkRemoved = 4
%StructureChangeType_ChildrenReordered   = 5

' enum AsyncContentLoadedState
%AsyncContentLoadedState_Beginning = 0
%AsyncContentLoadedState_Progress  = 1
%AsyncContentLoadedState_Completed = 2

' // Size = 8 bytes
TYPE UiaEventArgs DWORD
   Type    AS LONG   ' EventArgsType
   EventId AS LONG   ' int
END TYPE

' // Size = 48 bytes
TYPE UiaPropertyChangedEventArgs QWORD FILL   ' Must be 8 byte aligned
   Type       AS LONG         ' EventArgsType
   EventId    AS LONG         ' int
   PropertyId AS LONG         ' PROPERTYID
   OldValue   AS tagVARIANT   ' VARIANT
   NewValue   AS tagVARIANT   ' VARIANT
END TYPE

' // Size = 20 bytes
TYPE UiaStructureChangedEventArgs DWORD
   Type                AS LONG       ' EventArgsType
   EventId             AS LONG       ' int
   StructureChangeType AS LONG       ' StructureChangeType
   pRuntimeId          AS LONG PTR   ' int *
   cRuntimeIdLen       AS LONG       ' int
END TYPE

' // Size = 24 bytes
TYPE UiaAsyncContentLoadedEventArgs QWORD FILL   ' Must be 8 byte aligned
   Type                    AS LONG     ' EventArgsType
   EventId                 AS LONG     ' int
   AsyncContentLoadedState AS LONG     ' AsyncContentLoadedState
   PercentComplete         AS DOUBLE   ' double
END TYPE

' // Size = 16 bytes
TYPE UiaWindowClosedEventArgs DWORD
   Type          AS LONG       ' EventArgsType
   EventId       AS LONG       ' int
   pRuntimeId    AS LONG PTR   ' int *
   cRuntimeIdLen AS LONG       ' int
END TYPE

'//
'// Provider Event APIs
'//

DECLARE FUNCTION UiaClientsAreListening IMPORT "uiautomationcore.dll" ALIAS "UiaClientsAreListening" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UiaRaiseAutomationPropertyChangedEvent IMPORT "uiautomationcore.dll" ALIAS "UiaRaiseAutomationPropertyChangedEvent" ( _
   BYVAL pProvider AS IRawElementProviderSimple _       ' __in IRawElementProviderSimple * pProvider
 , BYVAL id AS LONG _                                   ' __in PROPERTYID id
 , BYVAL oldValue AS VARIANT _                          ' __in VARIANT oldValue
 , BYVAL newValue AS VARIANT _                          ' __in VARIANT newValue
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaRaiseAutomationEvent IMPORT "uiautomationcore.dll" ALIAS "UiaRaiseAutomationEvent" ( _
   BYVAL pProvider AS IRawElementProviderSimple _       ' __in IRawElementProviderSimple * pProvider
 , BYVAL id AS LONG _                                   ' __in EVENTID id
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaRaiseStructureChangedEvent IMPORT "uiautomationcore.dll" ALIAS "UiaRaiseStructureChangedEvent" ( _
   BYVAL pProvider AS IRawElementProviderSimple _       ' __in IRawElementProviderSimple * pProvider
 , BYVAL structureChangeType AS LONG _                  ' __in StructureChangeType structureChangeType
 , BYREF pRuntimeId AS LONG _                           ' __in int * pRuntimeId
 , BYVAL cRuntimeIdLen AS LONG _                        ' __in int cRuntimeIdLen
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaRaiseAsyncContentLoadedEvent IMPORT "uiautomationcore.dll" ALIAS "UiaRaiseAsyncContentLoadedEvent" ( _
   BYVAL pProvider AS IRawElementProviderSimple _       ' __in IRawElementProviderSimple * pProvider
 , BYVAL asyncContentLoadedState AS LONG _              ' __in AsyncContentLoadedState asyncContentLoadedState
 , BYVAL percentComplete AS DOUBLE _                    ' __in double percentComplete
 ) AS LONG                                              ' HRESULT

'//
'// Client Event APIs
'//

DECLARE SUB UiaEventCallback IMPORT "uiautomationcore.dll" ALIAS "UiaEventCallback" ( _
   BYREF pArgs AS UiaEventArgs _                        ' __in UiaEventArgs * pArgs
 , BYVAL pRequestedData AS DWORD _                      ' __in SAFEARRAY * pRequestedData
 , BYVAL pTreeStructure AS WSTRING _                    ' __in BSTR pTreeStructure
 )                                                      ' void

DECLARE FUNCTION UiaAddEvent IMPORT "uiautomationcore.dll" ALIAS "UiaAddEvent" ( _
   BYVAL hnode AS DWORD _                               ' __in  HUIANODE hnode
 , BYVAL eventId AS LONG _                              ' __in  EVENTID eventId
 , BYVAL pCallback AS DWORD _                           ' __in  UiaEventCallback * pCallback
 , BYVAL scope AS LONG _                                ' __in  TreeScope scope
 , BYREF pProperties AS LONG _                          ' __in  PROPERTYID * pProperties
 , BYVAL cProperties AS LONG _                          ' __in  int cProperties
 , BYREF pRequest AS UiaCacheRequest _                  ' __in  UiaCacheRequest * pRequest
 , BYREF phEvent AS DWORD _                             ' __out HUIAEVENT * phEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaRemoveEvent IMPORT "uiautomationcore.dll" ALIAS "UiaRemoveEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in HUIAEVENT hEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaEventAddWindow IMPORT "uiautomationcore.dll" ALIAS "UiaEventAddWindow" ( _
   BYVAL hEvent AS DWORD _                              ' __in HUIAEVENT hEvent
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaEventRemoveWindow IMPORT "uiautomationcore.dll" ALIAS "UiaEventRemoveWindow" ( _
   BYVAL hEvent AS DWORD _                              ' __in HUIAEVENT hEvent
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

'// --------------------------------------------------------------------------
'//
'// Pattern methods
'//
'// --------------------------------------------------------------------------

DECLARE FUNCTION DockPattern_SetDockPosition IMPORT "uiautomationcore.dll" ALIAS "DockPattern_SetDockPosition" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL dockPosition AS LONG _                         ' __in DockPosition dockPosition
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ExpandCollapsePattern_Collapse IMPORT "uiautomationcore.dll" ALIAS "ExpandCollapsePattern_Collapse" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ExpandCollapsePattern_Expand IMPORT "uiautomationcore.dll" ALIAS "ExpandCollapsePattern_Expand" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GridPattern_GetItem IMPORT "uiautomationcore.dll" ALIAS "GridPattern_GetItem" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYVAL row AS LONG _                                  ' __in  int row
 , BYVAL column AS LONG _                               ' __in  int column
 , BYREF pResult AS DWORD _                             ' __out HUIANODE * pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION InvokePattern_Invoke IMPORT "uiautomationcore.dll" ALIAS "InvokePattern_Invoke" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MultipleViewPattern_GetViewName IMPORT "uiautomationcore.dll" ALIAS "MultipleViewPattern_GetViewName" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYVAL viewId AS LONG _                               ' __in  int viewId
 , BYREF ppStr AS WSTRING _                             ' __out BSTR * ppStr
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MultipleViewPattern_SetCurrentView IMPORT "uiautomationcore.dll" ALIAS "MultipleViewPattern_SetCurrentView" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL viewId AS LONG _                               ' __in int viewId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RangeValuePattern_SetValue IMPORT "uiautomationcore.dll" ALIAS "RangeValuePattern_SetValue" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL val AS DOUBLE _                                ' __in double val
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ScrollItemPattern_ScrollIntoView IMPORT "uiautomationcore.dll" ALIAS "ScrollItemPattern_ScrollIntoView" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ScrollPattern_Scroll IMPORT "uiautomationcore.dll" ALIAS "ScrollPattern_Scroll" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL horizontalAmount AS LONG _                     ' __in ScrollAmount horizontalAmount
 , BYVAL verticalAmount AS LONG _                       ' __in ScrollAmount verticalAmount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ScrollPattern_SetScrollPercent IMPORT "uiautomationcore.dll" ALIAS "ScrollPattern_SetScrollPercent" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL horizontalAmount AS DOUBLE _                   ' __in double horizontalPercent
 , BYVAL verticalAmount AS DOUBLE _                     ' __in double verticalPercent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SelectionItemPattern_AddToSelection IMPORT "uiautomationcore.dll" ALIAS "SelectionItemPattern_AddToSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SelectionItemPattern_RemoveFromSelection IMPORT "uiautomationcore.dll" ALIAS "SelectionItemPattern_RemoveFromSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SelectionItemPattern_Select IMPORT "uiautomationcore.dll" ALIAS "SelectionItemPattern_Select" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TogglePattern_Toggle IMPORT "uiautomationcore.dll" ALIAS "TogglePattern_Toggle" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TransformPattern_Move IMPORT "uiautomationcore.dll" ALIAS "TransformPattern_Move" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TransformPattern_Resize IMPORT "uiautomationcore.dll" ALIAS "TransformPattern_Resize" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL width AS DOUBLE _                              ' __in double width
 , BYVAL height AS DOUBLE _                             ' __in double height
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TransformPattern_Rotate IMPORT "uiautomationcore.dll" ALIAS "TransformPattern_Rotate" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL degrees AS DOUBLE _                            ' __in double degrees
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ValuePattern_SetValue IMPORT "uiautomationcore.dll" ALIAS "ValuePattern_SetValue" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYREF pVal AS WSTRINGZ _                             ' __in LPCWSTR pVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WindowPattern_Close IMPORT "uiautomationcore.dll" ALIAS "WindowPattern_Close" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WindowPattern_SetWindowVisualState IMPORT "uiautomationcore.dll" ALIAS "WindowPattern_SetWindowVisualState" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 , BYVAL state AS LONG _                                ' __in WindowVisualState state
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WindowPattern_WaitForInputIdle IMPORT "uiautomationcore.dll" ALIAS "WindowPattern_WaitForInputIdle" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYVAL milliseconds AS LONG _                         ' __in  int milliseconds
 , BYREF pResult AS LONG _                              ' __out BOOL * pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_GetSelection IMPORT "uiautomationcore.dll" ALIAS "TextPattern_GetSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYREF pRetVal AS DWORD _                             ' __out SAFEARRAY** pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_GetVisibleRanges IMPORT "uiautomationcore.dll" ALIAS "TextPattern_GetVisibleRanges" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYREF pRetVal AS DWORD _                             ' __out SAFEARRAY** pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_RangeFromChild IMPORT "uiautomationcore.dll" ALIAS "TextPattern_RangeFromChild" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYVAL hnodeChild AS DWORD _                          ' __in  HUIANODE hnodeChild
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_RangeFromPoint IMPORT "uiautomationcore.dll" ALIAS "TextPattern_RangeFromPoint" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYVAL point AS UiaPoint _                            ' __in  UiaPoint point
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_get_DocumentRange IMPORT "uiautomationcore.dll" ALIAS "TextPattern_get_DocumentRange" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextPattern_get_SupportedTextSelection IMPORT "uiautomationcore.dll" ALIAS "TextPattern_get_SupportedTextSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIAPATTERNOBJECT hobj
 , BYREF pRetVal AS LONG _                              ' __out SupportedTextSelection* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_Clone IMPORT "uiautomationcore.dll" ALIAS "TextRange_Clone" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_Compare IMPORT "uiautomationcore.dll" ALIAS "TextRange_Compare" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL range AS DWORD _                               ' __in  HUIATEXTRANGE range
 , BYREF pRetVal AS LONG _                              ' __out BOOL* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_CompareEndpoints IMPORT "uiautomationcore.dll" ALIAS "TextRange_CompareEndpoints" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL endpoint AS LONG _                             ' __in  TextPatternRangeEndpoint endpoint
 , BYVAL targetRange AS DWORD _                         ' __in  HUIATEXTRANGE targetRange
 , BYVAL targetEndpoint AS LONG _                       ' __in  TextPatternRangeEndpoint targetEndpoint
 , BYREF pRetVal AS LONG _                              ' __out int* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_ExpandToEnclosingUnit IMPORT "uiautomationcore.dll" ALIAS "TextRange_ExpandToEnclosingUnit" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 , BYVAL unit AS LONG _                                 ' __in TextUnit unit
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_GetAttributeValue IMPORT "uiautomationcore.dll" ALIAS "TextRange_GetAttributeValue" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL attributeId AS LONG _                          ' __in  TEXTATTRIBUTEID attributeId
 , BYREF pRetVal AS VARIANT _                           ' __out VARIANT * pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_FindAttribute IMPORT "uiautomationcore.dll" ALIAS "TextRange_FindAttribute" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL attributeId AS LONG _                          ' __in  TEXTATTRIBUTEID attributeId
 , BYVAL val AS VARIANT _                               ' __in  VARIANT val
 , BYVAL backward AS LONG _                             ' __in  BOOL backward
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE * pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_FindText IMPORT "uiautomationcore.dll" ALIAS "TextRange_FindText" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL text AS WSTRING _                              ' __in  BSTR text
 , BYVAL backward AS LONG _                             ' __in  BOOL backward
 , BYVAL ignoreCase AS LONG _                           ' __in  BOOL ignoreCase
 , BYREF pRetVal AS DWORD _                             ' __out HUIATEXTRANGE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_GetBoundingRectangles IMPORT "uiautomationcore.dll" ALIAS "TextRange_GetBoundingRectangles" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYREF pRetVal AS DWORD _                             ' __out SAFEARRAY** pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_GetEnclosingElement IMPORT "uiautomationcore.dll" ALIAS "TextRange_GetEnclosingElement" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYREF pRetVal AS DWORD _                             ' __out HUIANODE* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_GetText IMPORT "uiautomationcore.dll" ALIAS "TextRange_GetText" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL maxLength AS LONG _                            ' __in  int maxLength
 , BYREF pRetVal AS WSTRING _                           ' __out BSTR* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_Move IMPORT "uiautomationcore.dll" ALIAS "TextRange_Move" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL unit AS LONG _                                 ' __in  TextUnit unit
 , BYVAL count AS LONG _                                ' __in  int count
 , BYREF pRetVal AS LONG _                              ' __out int* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_MoveEndpointByUnit IMPORT "uiautomationcore.dll" ALIAS "TextRange_MoveEndpointByUnit" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYVAL endpoint AS LONG _                             ' __in  TextPatternRangeEndpoint endpoint
 , BYVAL unit AS LONG _                                 ' __in  TextUnit unit
 , BYVAL count AS LONG _                                ' __in  int count
 , BYREF pRetVal AS LONG _                              ' __out int* pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_MoveEndpointByRange IMPORT "uiautomationcore.dll" ALIAS "TextRange_MoveEndpointByRange" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 , BYVAL endpoint AS LONG _                             ' __in TextPatternRangeEndpoint endpoint
 , BYVAL targetRange AS DWORD _                         ' __in HUIATEXTRANGE targetRange
 , BYVAL targetEndpoint AS LONG _                       ' __in TextPatternRangeEndpoint targetEndpoint
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_Select IMPORT "uiautomationcore.dll" ALIAS "TextRange_Select" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_AddToSelection IMPORT "uiautomationcore.dll" ALIAS "TextRange_AddToSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_RemoveFromSelection IMPORT "uiautomationcore.dll" ALIAS "TextRange_RemoveFromSelection" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_ScrollIntoView IMPORT "uiautomationcore.dll" ALIAS "TextRange_ScrollIntoView" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 , BYVAL alignToTop AS LONG _                           ' __in BOOL alignToTop
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TextRange_GetChildren IMPORT "uiautomationcore.dll" ALIAS "TextRange_GetChildren" ( _
   BYVAL hobj AS DWORD _                                ' __in  HUIATEXTRANGE hobj
 , BYREF pRetVal AS DWORD _                             ' __out SAFEARRAY** pRetVal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UiaPatternRelease IMPORT "uiautomationcore.dll" ALIAS "UiaPatternRelease" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIAPATTERNOBJECT hobj
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UiaTextRangeRelease IMPORT "uiautomationcore.dll" ALIAS "UiaTextRangeRelease" ( _
   BYVAL hobj AS DWORD _                                ' __in HUIATEXTRANGE hobj
 ) AS LONG                                              ' BOOL

'// --------------------------------------------------------------------------
'//
'// Provider methods
'//
'// --------------------------------------------------------------------------

DECLARE FUNCTION UiaReturnRawElementProvider IMPORT "uiautomationcore.dll" ALIAS "UiaReturnRawElementProvider" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL el AS IRawElementProviderSimple _              ' __in IRawElementProviderSimple * el
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION UiaHostProviderFromHwnd IMPORT "uiautomationcore.dll" ALIAS "UiaHostProviderFromHwnd" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pProvider AS IRawElementProviderSimple _       ' __out IRawElementProviderSimple ** pProvider
 ) AS LONG                                              ' HRESULT

'// --------------------------------------------------------------------------
'//
'// Other APIs...
'//
'// --------------------------------------------------------------------------

DECLARE FUNCTION UiaHasServerSideProvider IMPORT "uiautomationcore.dll" ALIAS "UiaHasServerSideProvider" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL
