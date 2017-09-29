' ########################################################################################
' Microsoft Windows
' File: UIAutomationClient.inc
' Contents: UIAutomation Client interface definitions and related types and enums
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UIAUTOMATIONCLIENT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "UIAutomationCore.inc"

' enum TreeScope
%TreeScope_Element     = &H1
%TreeScope_Children    = &H2
%TreeScope_Descendants = &H4
%TreeScope_Parent      = &H8
%TreeScope_Ancestors   = &H10
%TreeScope_Subtree     = (%TreeScope_Element OR %TreeScope_Children) OR %TreeScope_Descendants

' enum PropertyConditionFlags
%PropertyConditionFlags_None       = 0
%PropertyConditionFlags_IgnoreCase = &H1

' enum AutomationElementMode
%AutomationElementMode_None = 0
%AutomationElementMode_Full = %AutomationElementMode_None + 1

'typedef void *UIA_HWND

'EXTERN_C const IID LIBID_UIAutomationClient

#IF NOT %DEF(%UIA_PatternIds_MODULE_DEFINED)
    %UIA_PatternIds_MODULE_DEFINED = 1

%UIA_InvokePatternId            = 10000&
%UIA_SelectionPatternId         = 10001&
%UIA_ValuePatternId             = 10002&
%UIA_RangeValuePatternId        = 10003&
%UIA_ScrollPatternId            = 10004&
%UIA_ExpandCollapsePatternId    = 10005&
%UIA_GridPatternId              = 10006&
%UIA_GridItemPatternId          = 10007&
%UIA_MultipleViewPatternId      = 10008&
%UIA_WindowPatternId            = 10009&
%UIA_SelectionItemPatternId     = 10010&
%UIA_DockPatternId              = 10011&
%UIA_TablePatternId             = 10012&
%UIA_TableItemPatternId         = 10013&
%UIA_TextPatternId              = 10014&
%UIA_TogglePatternId            = 10015&
%UIA_TransformPatternId         = 10016&
%UIA_ScrollItemPatternId        = 10017&
%UIA_LegacyIAccessiblePatternId = 10018&
%UIA_ItemContainerPatternId     = 10019&
%UIA_VirtualizedItemPatternId   = 10020&
%UIA_SynchronizedInputPatternId = 10021&

#ENDIF   ' /* __UIA_PatternIds_MODULE_DEFINED__ */

#IF NOT %DEF(%UIA_EventIds_MODULE_DEFINED)
    %UIA_EventIds_MODULE_DEFINED = 1

%UIA_ToolTipOpenedEventId                             = 20000&
%UIA_ToolTipClosedEventId                             = 20001&
%UIA_StructureChangedEventId                          = 20002&
%UIA_MenuOpenedEventId                                = 20003&
%UIA_AutomationPropertyChangedEventId                 = 20004&
%UIA_AutomationFocusChangedEventId                    = 20005&
%UIA_AsyncContentLoadedEventId                        = 20006&
%UIA_MenuClosedEventId                                = 20007&
%UIA_LayoutInvalidatedEventId                         = 20008&
%UIA_Invoke_InvokedEventId                            = 20009&
%UIA_SelectionItem_ElementAddedToSelectionEventId     = 20010&
%UIA_SelectionItem_ElementRemovedFromSelectionEventId = 20011&
%UIA_SelectionItem_ElementSelectedEventId             = 20012&
%UIA_Selection_InvalidatedEventId                     = 20013&
%UIA_Text_TextSelectionChangedEventId                 = 20014&
%UIA_Text_TextChangedEventId                          = 20015&
%UIA_Window_WindowOpenedEventId                       = 20016&
%UIA_Window_WindowClosedEventId                       = 20017&
%UIA_MenuModeStartEventId                             = 20018&
%UIA_MenuModeEndEventId                               = 20019&
%UIA_InputReachedTargetEventId                        = 20020&
%UIA_InputReachedOtherElementEventId                  = 20021&
%UIA_InputDiscardedEventId                            = 20022&

#ENDIF   ' /* __UIA_EventIds_MODULE_DEFINED__ */

#IF NOT %DEF(%UIA_PropertyIds_MODULE_DEFINED)
    %UIA_PropertyIds_MODULE_DEFINED = 1

%UIA_RuntimeIdPropertyId                           = 30000&
%UIA_BoundingRectanglePropertyId                   = 30001&
%UIA_ProcessIdPropertyId                           = 30002&
%UIA_ControlTypePropertyId                         = 30003&
%UIA_LocalizedControlTypePropertyId                = 30004&
%UIA_NamePropertyId                                = 30005&
%UIA_AcceleratorKeyPropertyId                      = 30006&
%UIA_AccessKeyPropertyId                           = 30007&
%UIA_HasKeyboardFocusPropertyId                    = 30008&
%UIA_IsKeyboardFocusablePropertyId                 = 30009&
%UIA_IsEnabledPropertyId                           = 30010&
%UIA_AutomationIdPropertyId                        = 30011&
%UIA_ClassNamePropertyId                           = 30012&
%UIA_HelpTextPropertyId                            = 30013&
%UIA_ClickablePointPropertyId                      = 30014&
%UIA_CulturePropertyId                             = 30015&
%UIA_IsControlElementPropertyId                    = 30016&
%UIA_IsContentElementPropertyId                    = 30017&
%UIA_LabeledByPropertyId                           = 30018&
%UIA_IsPasswordPropertyId                          = 30019&
%UIA_NativeWindowHandlePropertyId                  = 30020&
%UIA_ItemTypePropertyId                            = 30021&
%UIA_IsOffscreenPropertyId                         = 30022&
%UIA_OrientationPropertyId                         = 30023&
%UIA_FrameworkIdPropertyId                         = 30024&
%UIA_IsRequiredForFormPropertyId                   = 30025&
%UIA_ItemStatusPropertyId                          = 30026&
%UIA_IsDockPatternAvailablePropertyId              = 30027&
%UIA_IsExpandCollapsePatternAvailablePropertyId    = 30028&
%UIA_IsGridItemPatternAvailablePropertyId          = 30029&
%UIA_IsGridPatternAvailablePropertyId              = 30030&
%UIA_IsInvokePatternAvailablePropertyId            = 30031&
%UIA_IsMultipleViewPatternAvailablePropertyId      = 30032&
%UIA_IsRangeValuePatternAvailablePropertyId        = 30033&
%UIA_IsScrollPatternAvailablePropertyId            = 30034&
%UIA_IsScrollItemPatternAvailablePropertyId        = 30035&
%UIA_IsSelectionItemPatternAvailablePropertyId     = 30036&
%UIA_IsSelectionPatternAvailablePropertyId         = 30037&
%UIA_IsTablePatternAvailablePropertyId             = 30038&
%UIA_IsTableItemPatternAvailablePropertyId         = 30039&
%UIA_IsTextPatternAvailablePropertyId              = 30040&
%UIA_IsTogglePatternAvailablePropertyId            = 30041&
%UIA_IsTransformPatternAvailablePropertyId         = 30042&
%UIA_IsValuePatternAvailablePropertyId             = 30043&
%UIA_IsWindowPatternAvailablePropertyId            = 30044&
%UIA_ValueValuePropertyId                          = 30045&
%UIA_ValueIsReadOnlyPropertyId                     = 30046&
%UIA_RangeValueValuePropertyId                     = 30047&
%UIA_RangeValueIsReadOnlyPropertyId                = 30048&
%UIA_RangeValueMinimumPropertyId                   = 30049&
%UIA_RangeValueMaximumPropertyId                   = 30050&
%UIA_RangeValueLargeChangePropertyId               = 30051&
%UIA_RangeValueSmallChangePropertyId               = 30052&
%UIA_ScrollHorizontalScrollPercentPropertyId       = 30053&
%UIA_ScrollHorizontalViewSizePropertyId            = 30054&
%UIA_ScrollVerticalScrollPercentPropertyId         = 30055&
%UIA_ScrollVerticalViewSizePropertyId              = 30056&
%UIA_ScrollHorizontallyScrollablePropertyId        = 30057&
%UIA_ScrollVerticallyScrollablePropertyId          = 30058&
%UIA_SelectionSelectionPropertyId                  = 30059&
%UIA_SelectionCanSelectMultiplePropertyId          = 30060&
%UIA_SelectionIsSelectionRequiredPropertyId        = 30061&
%UIA_GridRowCountPropertyId                        = 30062&
%UIA_GridColumnCountPropertyId                     = 30063&
%UIA_GridItemRowPropertyId                         = 30064&
%UIA_GridItemColumnPropertyId                      = 30065&
%UIA_GridItemRowSpanPropertyId                     = 30066&
%UIA_GridItemColumnSpanPropertyId                  = 30067&
%UIA_GridItemContainingGridPropertyId              = 30068&
%UIA_DockDockPositionPropertyId                    = 30069&
%UIA_ExpandCollapseExpandCollapseStatePropertyId   = 30070&
%UIA_MultipleViewCurrentViewPropertyId             = 30071&
%UIA_MultipleViewSupportedViewsPropertyId          = 30072&
%UIA_WindowCanMaximizePropertyId                   = 30073&
%UIA_WindowCanMinimizePropertyId                   = 30074&
%UIA_WindowWindowVisualStatePropertyId             = 30075&
%UIA_WindowWindowInteractionStatePropertyId        = 30076&
%UIA_WindowIsModalPropertyId                       = 30077&
%UIA_WindowIsTopmostPropertyId                     = 30078&
%UIA_SelectionItemIsSelectedPropertyId             = 30079&
%UIA_SelectionItemSelectionContainerPropertyId     = 30080&
%UIA_TableRowHeadersPropertyId                     = 30081&
%UIA_TableColumnHeadersPropertyId                  = 30082&
%UIA_TableRowOrColumnMajorPropertyId               = 30083&
%UIA_TableItemRowHeaderItemsPropertyId             = 30084&
%UIA_TableItemColumnHeaderItemsPropertyId          = 30085&
%UIA_ToggleToggleStatePropertyId                   = 30086&
%UIA_TransformCanMovePropertyId                    = 30087&
%UIA_TransformCanResizePropertyId                  = 30088&
%UIA_TransformCanRotatePropertyId                  = 30089&
%UIA_IsLegacyIAccessiblePatternAvailablePropertyId = 30090&
%UIA_LegacyIAccessibleChildIdPropertyId            = 30091&
%UIA_LegacyIAccessibleNamePropertyId               = 30092&
%UIA_LegacyIAccessibleValuePropertyId              = 30093&
%UIA_LegacyIAccessibleDescriptionPropertyId        = 30094&
%UIA_LegacyIAccessibleRolePropertyId               = 30095&
%UIA_LegacyIAccessibleStatePropertyId              = 30096&
%UIA_LegacyIAccessibleHelpPropertyId               = 30097&
%UIA_LegacyIAccessibleKeyboardShortcutPropertyId   = 30098&
%UIA_LegacyIAccessibleSelectionPropertyId          = 30099&
%UIA_LegacyIAccessibleDefaultActionPropertyId      = 30100&
%UIA_AriaRolePropertyId                            = 30101&
%UIA_AriaPropertiesPropertyId                      = 30102&
%UIA_IsDataValidForFormPropertyId                  = 30103&
%UIA_ControllerForPropertyId                       = 30104&
%UIA_DescribedByPropertyId                         = 30105&
%UIA_FlowsToPropertyId                             = 30106&
%UIA_ProviderDescriptionPropertyId                 = 30107&
%UIA_IsItemContainerPatternAvailablePropertyId     = 30108&
%UIA_IsVirtualizedItemPatternAvailablePropertyId   = 30109&
%UIA_IsSynchronizedInputPatternAvailablePropertyId = 30110&

#ENDIF   ' /* __UIA_PropertyIds_MODULE_DEFINED__ */

#IF NOT %DEF(%UIA_TextAttributeIds_MODULE_DEFINED)
    %UIA_TextAttributeIds_MODULE_DEFINED = 1

%UIA_AnimationStyleAttributeId          = 40000&
%UIA_BackgroundColorAttributeId         = 40001&
%UIA_BulletStyleAttributeId             = 40002&
%UIA_CapStyleAttributeId                = 40003&
%UIA_CultureAttributeId                 = 40004&
%UIA_FontNameAttributeId                = 40005&
%UIA_FontSizeAttributeId                = 40006&
%UIA_FontWeightAttributeId              = 40007&
%UIA_ForegroundColorAttributeId         = 40008&
%UIA_HorizontalTextAlignmentAttributeId = 40009&
%UIA_IndentationFirstLineAttributeId    = 40010&
%UIA_IndentationLeadingAttributeId      = 40011&
%UIA_IndentationTrailingAttributeId     = 40012&
%UIA_IsHiddenAttributeId                = 40013&
%UIA_IsItalicAttributeId                = 40014&
%UIA_IsReadOnlyAttributeId              = 40015&
%UIA_IsSubscriptAttributeId             = 40016&
%UIA_IsSuperscriptAttributeId           = 40017&
%UIA_MarginBottomAttributeId            = 40018&
%UIA_MarginLeadingAttributeId           = 40019&
%UIA_MarginTopAttributeId               = 40020&
%UIA_MarginTrailingAttributeId          = 40021&
%UIA_OutlineStylesAttributeId           = 40022&
%UIA_OverlineColorAttributeId           = 40023&
%UIA_OverlineStyleAttributeId           = 40024&
%UIA_StrikethroughColorAttributeId      = 40025&
%UIA_StrikethroughStyleAttributeId      = 40026&
%UIA_TabsAttributeId                    = 40027&
%UIA_TextFlowDirectionsAttributeId      = 40028&
%UIA_UnderlineColorAttributeId          = 40029&
%UIA_UnderlineStyleAttributeId          = 40030&

#ENDIF   ' /* __UIA_TextAttributeIds_MODULE_DEFINED__ */

#IF NOT %DEF(%UIA_ControlTypeIds_MODULE_DEFINED)
    %UIA_ControlTypeIds_MODULE_DEFINED = 1

%UIA_ButtonControlTypeId      = 50000&
%UIA_CalendarControlTypeId    = 50001&
%UIA_CheckBoxControlTypeId    = 50002&
%UIA_ComboBoxControlTypeId    = 50003&
%UIA_EditControlTypeId        = 50004&
%UIA_HyperlinkControlTypeId   = 50005&
%UIA_ImageControlTypeId       = 50006&
%UIA_ListItemControlTypeId    = 50007&
%UIA_ListControlTypeId        = 50008&
%UIA_MenuControlTypeId        = 50009&
%UIA_MenuBarControlTypeId     = 50010&
%UIA_MenuItemControlTypeId    = 50011&
%UIA_ProgressBarControlTypeId = 50012&
%UIA_RadioButtonControlTypeId = 50013&
%UIA_ScrollBarControlTypeId   = 50014&
%UIA_SliderControlTypeId      = 50015&
%UIA_SpinnerControlTypeId     = 50016&
%UIA_StatusBarControlTypeId   = 50017&
%UIA_TabControlTypeId         = 50018&
%UIA_TabItemControlTypeId     = 50019&
%UIA_TextControlTypeId        = 50020&
%UIA_ToolBarControlTypeId     = 50021&
%UIA_ToolTipControlTypeId     = 50022&
%UIA_TreeControlTypeId        = 50023&
%UIA_TreeItemControlTypeId    = 50024&
%UIA_CustomControlTypeId      = 50025&
%UIA_GroupControlTypeId       = 50026&
%UIA_ThumbControlTypeId       = 50027&
%UIA_DataGridControlTypeId    = 50028&
%UIA_DataItemControlTypeId    = 50029&
%UIA_DocumentControlTypeId    = 50030&
%UIA_SplitButtonControlTypeId = 50031&
%UIA_WindowControlTypeId      = 50032&
%UIA_PaneControlTypeId        = 50033&
%UIA_HeaderControlTypeId      = 50034&
%UIA_HeaderItemControlTypeId  = 50035&
%UIA_TableControlTypeId       = 50036&
%UIA_TitleBarControlTypeId    = 50037&
%UIA_SeparatorControlTypeId   = 50038&

#ENDIF   ' /* __UIA_ControlTypeIds_MODULE_DEFINED__ */

' ########################################################################################
' IUIAutomationElement interface
' IID = D22108AA-8AC5-49A5-837B-37BBB3D7591E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationElement_INTERFACE_DEFINED)
    %IUIAutomationElement_INTERFACE_DEFINED = 1

$IID_IUIAutomationElement = GUID$("{D22108AA-8AC5-49A5-837B-37BBB3D7591E}")

INTERFACE IUIAutomationElement $IID_IUIAutomationElement

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRuntimeId ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *runtimeId
   ' =====================================================================================
   METHOD FindFirst ( _                                 ' VTable offset = 20
     BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL condition AS IUIAutomationCondition _        ' __in IUIAutomationCondition *condition
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **found
   ' =====================================================================================
   METHOD FindAll ( _                                   ' VTable offset = 24
     BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL condition AS IUIAutomationCondition _        ' __in IUIAutomationCondition *condition
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **found
   ' =====================================================================================
   METHOD FindFirstBuildCache ( _                       ' VTable offset = 28
     BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL condition AS IUIAutomationCondition _        ' __in IUIAutomationCondition *condition
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **found
   ' =====================================================================================
   METHOD FindAllBuildCache ( _                         ' VTable offset = 32
     BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL condition AS IUIAutomationCondition _        ' __in IUIAutomationCondition *condition
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **found
   ' =====================================================================================
   METHOD BuildUpdatedCache ( _                         ' VTable offset = 36
     BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **updatedElement
   ' =====================================================================================
   METHOD GetCurrentPropertyValue ( _                   ' VTable offset = 40
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD GetCurrentPropertyValueEx ( _                 ' VTable offset = 44
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL ignoreDefaultValue AS LONG _                 ' __in BOOL ignoreDefaultValue
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD GetCachedPropertyValue ( _                    ' VTable offset = 48
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD GetCachedPropertyValueEx ( _                  ' VTable offset = 52
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL ignoreDefaultValue AS LONG _                 ' __in BOOL ignoreDefaultValue
   ) AS VARIANT                                         ' __retval_out VARIANT *retVal
   ' =====================================================================================
   METHOD GetCurrentPatternAs ( _                       ' VTable offset = 56
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out void **patternObject
   ' =====================================================================================
   METHOD GetCachedPatternAs ( _                        ' VTable offset = 60
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   ) AS IUnknown                                        ' __retval_out void **patternObject
   ' =====================================================================================
   METHOD GetCurrentPattern ( _                         ' VTable offset = 64
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   ) AS IUnknown                                        ' __retval_out IUnknown **patternObject
   ' =====================================================================================
   METHOD GetCachedPattern ( _                          ' VTable offset = 68
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   ) AS IUnknown                                        ' __retval_out IUnknown **patternObject
   ' =====================================================================================
   METHOD GetCachedParent ( _                           ' VTable offset = 72
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **parent
   ' =====================================================================================
   METHOD GetCachedChildren ( _                         ' VTable offset = 76
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **children
   ' =====================================================================================
   PROPERTY GET CurrentProcessId ( _                    ' VTable offset = 80
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentControlType ( _                  ' VTable offset = 84
   ) AS LONG                                            ' __retval_out CONTROLTYPEID *retVal
   ' =====================================================================================
   PROPERTY GET CurrentLocalizedControlType ( _         ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentName ( _                         ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentAcceleratorKey ( _               ' VTable offset = 96
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentAccessKey ( _                    ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentHasKeyboardFocus ( _             ' VTable offset = 104
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsKeyboardFocusable ( _          ' VTable offset = 108
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsEnabled ( _                    ' VTable offset = 112
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentAutomationId ( _                 ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentClassName ( _                    ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentHelpText ( _                     ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentCulture ( _                      ' VTable offset = 128
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsControlElement ( _             ' VTable offset = 132
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsContentElement ( _             ' VTable offset = 136
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsPassword ( _                   ' VTable offset = 140
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentNativeWindowHandle ( _           ' VTable offset = 144
   ) AS DWORD                                           ' __retval_out UIA_HWND *retVal
   ' =====================================================================================
   PROPERTY GET CurrentItemType ( _                     ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsOffscreen ( _                  ' VTable offset = 152
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentOrientation ( _                  ' VTable offset = 156
   ) AS LONG                                            ' __retval_out enum OrientationType *retVal
   ' =====================================================================================
   PROPERTY GET CurrentFrameworkId ( _                  ' VTable offset = 160
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsRequiredForForm ( _            ' VTable offset = 164
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentItemStatus ( _                   ' VTable offset = 168
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentBoundingRectangle ( _            ' VTable offset = 172
   ) AS RECT                                            ' __retval_out RECT *retVal
   ' =====================================================================================
   PROPERTY GET CurrentLabeledBy ( _                    ' VTable offset = 176
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================
   PROPERTY GET CurrentAriaRole ( _                     ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentAriaProperties ( _               ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsDataValidForForm ( _           ' VTable offset = 188
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentControllerFor ( _                ' VTable offset = 192
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CurrentDescribedBy ( _                  ' VTable offset = 196
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CurrentFlowsTo ( _                      ' VTable offset = 200
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CurrentProviderDescription ( _          ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedProcessId ( _                     ' VTable offset = 208
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedControlType ( _                   ' VTable offset = 212
   ) AS LONG                                            ' __retval_out CONTROLTYPEID *retVal
   ' =====================================================================================
   PROPERTY GET CachedLocalizedControlType ( _          ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedName ( _                          ' VTable offset = 220
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedAcceleratorKey ( _                ' VTable offset = 224
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedAccessKey ( _                     ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedHasKeyboardFocus ( _              ' VTable offset = 232
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsKeyboardFocusable ( _           ' VTable offset = 236
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsEnabled ( _                     ' VTable offset = 240
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedAutomationId ( _                  ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedClassName ( _                     ' VTable offset = 248
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedHelpText ( _                      ' VTable offset = 252
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedCulture ( _                       ' VTable offset = 256
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsControlElement ( _              ' VTable offset = 260
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsContentElement ( _              ' VTable offset = 264
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsPassword ( _                    ' VTable offset = 268
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedNativeWindowHandle ( _            ' VTable offset = 272
   ) AS DWORD                                           ' __retval_out UIA_HWND *retVal
   ' =====================================================================================
   PROPERTY GET CachedItemType ( _                      ' VTable offset = 276
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsOffscreen ( _                   ' VTable offset = 280
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedOrientation ( _                   ' VTable offset = 284
   ) AS LONG                                            ' __retval_out enum OrientationType *retVal
   ' =====================================================================================
   PROPERTY GET CachedFrameworkId ( _                   ' VTable offset = 288
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsRequiredForForm ( _             ' VTable offset = 292
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedItemStatus ( _                    ' VTable offset = 296
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedBoundingRectangle ( _             ' VTable offset = 300
   ) AS RECT                                            ' __retval_out RECT *retVal
   ' =====================================================================================
   PROPERTY GET CachedLabeledBy ( _                     ' VTable offset = 304
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================
   PROPERTY GET CachedAriaRole ( _                      ' VTable offset = 308
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedAriaProperties ( _                ' VTable offset = 312
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsDataValidForForm ( _            ' VTable offset = 316
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedControllerFor ( _                 ' VTable offset = 320
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CachedDescribedBy ( _                   ' VTable offset = 324
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CachedFlowsTo ( _                       ' VTable offset = 328
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CachedProviderDescription ( _           ' VTable offset = 332
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   METHOD GetClickablePoint ( _                         ' VTable offset = 336
     BYREF clickable AS POINT _                         ' __out POINT *clickable
   ) AS LONG                                            ' __retval_out BOOL *gotClickable
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationElement_MODULE_DEFINED__ */

' ########################################################################################
' IUIAutomationElementArray interface
' IID = 14314595-B4BC-4055-95F2-58F2E42C9855
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationElementArray_INTERFACE_DEFINED)
    %IUIAutomationElementArray_INTERFACE_DEFINED = 1

$IID_IUIAutomationElementArray = GUID$("{14314595-B4BC-4055-95F2-58F2E42C9855}")

INTERFACE IUIAutomationElementArray $IID_IUIAutomationElementArray

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Length ( _                              ' VTable offset = 12
   ) AS LONG                                            ' __retval_out int *length
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 16
     BYREF index AS LONG _                              ' __in int index
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationElementArray_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationCondition interface
' IID = 352FFBA8-0973-437C-A61F-F64CAFD81DF9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationCondition_INTERFACE_DEFINED)
    %IUIAutomationCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationCondition = GUID$("{352FFBA8-0973-437C-A61F-F64CAFD81DF9}")

INTERFACE IUIAutomationCondition $IID_IUIAutomationCondition

   INHERIT IUnknown

   ' This interface has not additional methods

END INTERFACE

#ENDIF   ' /* __IUIAutomationCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationBoolCondition interface
' IID = 1B4E1F2E-75EB-4D0B-8952-5A69988E2307
' Inherited interface = IUIAutomationCondition
' ########################################################################################

#IF NOT %DEF(%IUIAutomationBoolCondition_INTERFACE_DEFINED)
    %IUIAutomationBoolCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationBoolCondition = GUID$("{1B4E1F2E-75EB-4D0B-8952-5A69988E2307}")

INTERFACE IUIAutomationBoolCondition $IID_IUIAutomationBoolCondition

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET BooleanValue ( _                        ' VTable offset = 12
   ) AS LONG                                            ' __retval_out BOOL *boolVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationBoolCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationPropertyCondition interface
' IID = 99EBF2CB-5578-4267-9AD4-AFD6EA77E94B
' Inherited interface = IUIAutomationCondition
' ########################################################################################

#IF NOT %DEF(%IUIAutomationPropertyCondition_INTERFACE_DEFINED)
    %IUIAutomationPropertyCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationPropertyCondition = GUID$("{99EBF2CB-5578-4267-9AD4-AFD6EA77E94B}")

INTERFACE IUIAutomationPropertyCondition $IID_IUIAutomationPropertyCondition

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET PropertyId ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out PROPERTYID *propertyId
   ' =====================================================================================
   PROPERTY GET PropertyValue ( _                       ' VTable offset = 16
   ) AS VARIANT                                         ' __retval_out VARIANT *propertyValue
   ' =====================================================================================
   PROPERTY GET PropertyConditionFlags ( _              ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum PropertyConditionFlags *flags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationPropertyCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationAndCondition interface
' IID = A7D0AF36-B912-45FE-9855-091DDC174AEC
' Inherited interface = IUIAutomationCondition
' ########################################################################################

#IF NOT %DEF(%IUIAutomationAndCondition_INTERFACE_DEFINED)
    %IUIAutomationAndCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationAndCondition = GUID$("{A7D0AF36-B912-45FE-9855-091DDC174AEC}")

INTERFACE IUIAutomationAndCondition $IID_IUIAutomationAndCondition

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ChildCount ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out int *childCount
   ' =====================================================================================
   METHOD GetChildrenAsNativeArray ( _                  ' VTable offset = 16
     BYREF childArray AS IUIAutomationCondition _       ' __out IUIAutomationCondition ***childArray
   , BYREF childArrayCount AS LONG _                    ' __out int *childArrayCount
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *childArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationAndCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationOrCondition interface
' IID = 8753F032-3DB1-47B5-A1FC-6E34A266C712
' Inherited interface = IUIAutomationCondition
' ########################################################################################

#IF NOT %DEF(%IUIAutomationOrCondition_INTERFACE_DEFINED)
    %IUIAutomationOrCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationOrCondition = GUID$("{8753F032-3DB1-47B5-A1FC-6E34A266C712}")

INTERFACE IUIAutomationOrCondition $IID_IUIAutomationOrCondition

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ChildCount ( _                          ' VTable offset = 12
   ) AS LONG                                            ' __retval_out int *childCount
   ' =====================================================================================
   METHOD GetChildrenAsNativeArray ( _                  ' VTable offset = 16
     BYREF childArray AS IUIAutomationCondition _       ' __out IUIAutomationCondition ***childArray
   , BYREF childArrayCount AS LONG _                    ' __out int *childArrayCount
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *childArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationOrCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationNotCondition interface
' IID = F528B657-847B-498C-8896-D52B565407A1
' Inherited interface = IUIAutomationCondition
' ########################################################################################

#IF NOT %DEF(%IUIAutomationNotCondition_INTERFACE_DEFINED)
    %IUIAutomationNotCondition_INTERFACE_DEFINED = 1

$IID_IUIAutomationNotCondition = GUID$("{F528B657-847B-498C-8896-D52B565407A1}")

INTERFACE IUIAutomationNotCondition $IID_IUIAutomationNotCondition

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 12
   ) AS IUIAutomationNotCondition                       ' __retval_out IUIAutomationNotCondition **condition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationNotCondition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationCacheRequest interface
' IID = B32A92B5-BC25-4078-9C08-D7EE95C48E03
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationCacheRequest_INTERFACE_DEFINED)
    %IUIAutomationCacheRequest_INTERFACE_DEFINED = 1

$IID_IUIAutomationCacheRequest = GUID$("{B32A92B5-BC25-4078-9C08-D7EE95C48E03}")

INTERFACE IUIAutomationCacheRequest $IID_IUIAutomationCacheRequest

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AddProperty ( _                               ' VTable offset = 12
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPattern ( _                                ' VTable offset = 16
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 20
   ) AS IUIAutomationCacheRequest                       ' __retval_out IUIAutomationCacheRequest **clonedRequest
   ' =====================================================================================
   PROPERTY GET TreeScope ( _                           ' VTable offset = 24
   ) AS LONG                                            ' __retval_out enum TreeScope *scope
   ' =====================================================================================
   PROPERTY SET TreeScope ( _                           ' VTable offset = 28
     BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TreeFilter ( _                          ' VTable offset = 32
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **filter
   ' =====================================================================================
   PROPERTY SET TreeFilter ( _                          ' VTable offset = 36
     BYVAL filter AS IUIAutomationCondition _           ' __in IUIAutomationCondition *filter
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutomationElementMode ( _               ' VTable offset = 40
   ) AS LONG                                            ' __retval_out enum AutomationElementMode *mode
   ' =====================================================================================
   PROPERTY SET AutomationElementMode ( _               ' VTable offset = 44
     BYVAL mode AS LONG _                               ' __in enum AutomationElementMode mode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationCacheRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTreeWalker interface
' IID = 4042C624-389C-4AFC-A630-9DF854A541FC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTreeWalker_INTERFACE_DEFINED)
    %IUIAutomationTreeWalker_INTERFACE_DEFINED = 1

$IID_IUIAutomationTreeWalker = GUID$("{4042C624-389C-4AFC-A630-9DF854A541FC}")

INTERFACE IUIAutomationTreeWalker $IID_IUIAutomationTreeWalker

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetParentElement ( _                          ' VTable offset = 12
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **parent
   ' =====================================================================================
   METHOD GetFirstChildElement ( _                      ' VTable offset = 16
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **first
   ' =====================================================================================
   METHOD GetLastChildElement ( _                       ' VTable offset = 20
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **last
   ' =====================================================================================
   METHOD GetNextSiblingElement ( _                     ' VTable offset = 24
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **next
   ' =====================================================================================
   METHOD GetPreviousSiblingElement ( _                 ' VTable offset = 28
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **previous
   ' =====================================================================================
   METHOD NormalizeElement ( _                          ' VTable offset = 32
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **normalized
   ' =====================================================================================
   METHOD GetParentElementBuildCache ( _                ' VTable offset = 36
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **parent
   ' =====================================================================================
   METHOD GetFirstChildElementBuildCache ( _            ' VTable offset = 40
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **first
   ' =====================================================================================
   METHOD GetLastChildElementBuildCache ( _             ' VTable offset = 44
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **last
   ' =====================================================================================
   METHOD GetNextSiblingElementBuildCache ( _            ' VTable offset = 48
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **next
   ' =====================================================================================
   METHOD GetPreviousSiblingElementBuildCache ( _       ' VTable offset = 52
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **previous
   ' =====================================================================================
   METHOD NormalizeElementBuildCache ( _                ' VTable offset = 56
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **normalized
   ' =====================================================================================
   PROPERTY GET Condition ( _                           ' VTable offset = 60
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **condition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTreeWalker_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationEventHandler interface
' IID = 146C3C17-F12E-4E22-8C27-F894B9B79C69
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationEventHandler_INTERFACE_DEFINED)
    %IUIAutomationEventHandler_INTERFACE_DEFINED = 1

$IID_IUIAutomationEventHandler = GUID$("{146C3C17-F12E-4E22-8C27-F894B9B79C69}")

INTERFACE IUIAutomationEventHandler $IID_IUIAutomationEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandleAutomationEvent ( _                     ' VTable offset = 12
     BYVAL sender AS IUIAutomationElement _             ' __in IUIAutomationElement *sender
   , BYVAL eventId AS LONG _                            ' __in EVENTID eventId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationPropertyChangedEventHandler interface
' IID = 40CD37D4-C756-4B0C-8C6F-BDDFEEB13B50
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED)
    %IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED = 1

$IID_IUIAutomationPropertyChangedEventHandler = GUID$("{40CD37D4-C756-4B0C-8C6F-BDDFEEB13B50}")

INTERFACE IUIAutomationPropertyChangedEventHandler $IID_IUIAutomationPropertyChangedEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandlePropertyChangedEvent ( _                ' VTable offset = 12
     BYVAL sender AS IUIAutomationElement _             ' __in IUIAutomationElement *sender
   , BYVAL propertyId AS LONG _                         ' __in PROPERTYID eventId
   , BYVAL newValue AS VARIANT _                        ' __in VARIANT newValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationStructureChangedEventHandler interface
' IID = E81D1B4E-11C5-42F8-9754-E7036C79F054
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED)
    %IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED = 1

$IID_IUIAutomationStructureChangedEventHandler = GUID$("{E81D1B4E-11C5-42F8-9754-E7036C79F054}")

INTERFACE IUIAutomationStructureChangedEventHandler $IID_IUIAutomationStructureChangedEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandleStructureChangedEvent ( _               ' VTable offset = 12
     BYVAL sender AS IUIAutomationElement _             ' __in IUIAutomationElement *sender
   , BYVAL changeType AS LONG _                         ' __in enum StructureChangeType changeType
   , BYVAL runtimeId AS DWORD _                         ' __in SAFEARRAY * runtimeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationFocusChangedEventHandler interface
' IID = C270F6B5-5C69-4290-9745-7A7F97169468
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED)
    %IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED = 1

$IID_IUIAutomationFocusChangedEventHandler = GUID$("{C270F6B5-5C69-4290-9745-7A7F97169468}")

INTERFACE IUIAutomationFocusChangedEventHandler $IID_IUIAutomationFocusChangedEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HandleFocusChangedEvent ( _                   ' VTable offset = 12
     BYVAL sender AS IUIAutomationElement _             ' __in IUIAutomationElement *sender
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationInvokePattern interface
' IID = FB377FBE-8EA6-46D5-9C73-6499642D3059
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationInvokePattern_INTERFACE_DEFINED)
    %IUIAutomationInvokePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationInvokePattern = GUID$("{FB377FBE-8EA6-46D5-9C73-6499642D3059}")

INTERFACE IUIAutomationInvokePattern $IID_IUIAutomationInvokePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationInvokePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationDockPattern interface
' IID = FDE5EF97-1464-48F6-90BF-43D0948E86EC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationDockPattern_INTERFACE_DEFINED)
    %IUIAutomationDockPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationDockPattern = GUID$("{FDE5EF97-1464-48F6-90BF-43D0948E86EC}")

INTERFACE IUIAutomationDockPattern $IID_IUIAutomationDockPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetDockPosition ( _                           ' VTable offset = 12
     BYVAL dockPos AS LONG _                            ' __in enum DockPosition dockPos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentDockPosition ( _                 ' VTable offset = 16
   ) AS LONG                                            ' __retval_out enum DockPosition *retVal
   ' =====================================================================================
   PROPERTY GET CachedDockPosition ( _                  ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum DockPosition *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationDockPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationExpandCollapsePattern interface
' IID = 619BE086-1F4E-4EE4-BAFA-210128738730
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED)
    %IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationExpandCollapsePattern = GUID$("{619BE086-1F4E-4EE4-BAFA-210128738730}")

INTERFACE IUIAutomationExpandCollapsePattern $IID_IUIAutomationExpandCollapsePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Collapse ( _                                  ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentExpandCollapseState ( _          ' VTable offset = 24
   ) AS LONG                                            ' __retval_out enum ExpandCollapseState *retVal
   ' =====================================================================================
   PROPERTY GET CachedExpandCollapseState ( _           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out enum ExpandCollapseState *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationGridPattern interface
' IID = 414C3CDC-856B-4F5B-8538-3131C6302550
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationGridPattern_INTERFACE_DEFINED)
    %IUIAutomationGridPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationGridPattern = GUID$("{414C3CDC-856B-4F5B-8538-3131C6302550}")

INTERFACE IUIAutomationGridPattern $IID_IUIAutomationGridPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL row AS LONG _                                ' __in int row
   , BYVAL column AS LONG _                             ' __in int column
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   PROPERTY GET CurrentRowCount ( _                     ' VTable offset = 16
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentColumnCount ( _                  ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedRowCount ( _                      ' VTable offset = 24
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedColumnCount ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationGridPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationGridItemPattern interface
' IID = 78F8EF57-66C3-4E09-BD7C-E79B2004894D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationGridItemPattern_INTERFACE_DEFINED)
    %IUIAutomationGridItemPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationGridItemPattern = GUID$("{78F8EF57-66C3-4E09-BD7C-E79B2004894D}")

INTERFACE IUIAutomationGridItemPattern $IID_IUIAutomationGridItemPattern

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET CurrentContainingGrid ( _               ' VTable offset = 12
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================
   PROPERTY GET CurrentRow ( _                          ' VTable offset = 16
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentColumn ( _                       ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentRowSpan ( _                      ' VTable offset = 24
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CurrentColumnSpan ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedContainingGrid ( _                ' VTable offset = 32
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================
   PROPERTY GET CachedRow ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedColumn ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedRowSpan ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   PROPERTY GET CachedColumnSpan ( _                    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationGridItemPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationMultipleViewPattern interface
' IID = 8D253C91-1DC5-4BB5-B18F-ADE16FA495E8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationMultipleViewPattern_INTERFACE_DEFINED)
    %IUIAutomationMultipleViewPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationMultipleViewPattern = GUID$("{8D253C91-1DC5-4BB5-B18F-ADE16FA495E8}")

INTERFACE IUIAutomationMultipleViewPattern $IID_IUIAutomationMultipleViewPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetViewName ( _                               ' VTable offset = 12
     BYVAL view AS LONG _                               ' __in int view
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   METHOD SetCurrentView ( _                            ' VTable offset = 16
     BYVAL view AS LONG _                               ' __in int view
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCurrentView ( _                  ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   METHOD GetCurrentSupportedViews ( _                  ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *retVal
   ' =====================================================================================
   PROPERTY GET CachedCurrentView ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int *retVal
   ' =====================================================================================
   METHOD GetCachedSupportedViews ( _                   ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationMultipleViewPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationRangeValuePattern interface
' IID = 59213F4F-7346-49E5-B120-80555987A148
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationRangeValuePattern_INTERFACE_DEFINED)
    %IUIAutomationRangeValuePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationRangeValuePattern = GUID$("{59213F4F-7346-49E5-B120-80555987A148}")

INTERFACE IUIAutomationRangeValuePattern $IID_IUIAutomationRangeValuePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 12
     BYVAL val AS DOUBLE _                              ' __in double val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentValue ( _                        ' VTable offset = 16
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsReadOnly ( _                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentMaximum ( _                      ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentMinimum ( _                      ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentLargeChange ( _                  ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentSmallChange ( _                  ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedValue ( _                         ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsReadOnly ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedMaximum ( _                       ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedMinimum ( _                       ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedLargeChange ( _                   ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedSmallChange ( _                   ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationRangeValuePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationScrollPattern interface
' IID = 88F4D42A-E881-459D-A77C-73BBBB7E02DC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationScrollPattern_INTERFACE_DEFINED)
    %IUIAutomationScrollPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationScrollPattern = GUID$("{88F4D42A-E881-459D-A77C-73BBBB7E02DC}")

INTERFACE IUIAutomationScrollPattern $IID_IUIAutomationScrollPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Scroll ( _                                    ' VTable offset = 12
     BYVAL horizontalAmount AS LONG _                   ' __in enum ScrollAmount horizontalAmount
   , BYVAL verticalAmount AS LONG _                     ' __in enum ScrollAmount verticalAmount
   )                                                    ' void
   ' =====================================================================================
   METHOD SetScrollPercent ( _                          ' VTable offset = 16
     BYVAL horizontalPercent AS DOUBLE _                ' __in double horizontalPercent
   , BYVAL verticalPercent AS DOUBLE _                  ' __in double verticalPercent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentHorizontalScrollPercent ( _      ' VTable offset = 20
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentVerticalScrollPercent ( _        ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentHorizontalViewSize ( _           ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentVerticalViewSize ( _             ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CurrentHorizontallyScrollable ( _       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentVerticallyScrollable ( _         ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedHorizontalScrollPercent ( _       ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedVerticalScrollPercent ( _         ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedHorizontalViewSize ( _            ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedVerticalViewSize ( _              ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out double *retVal
   ' =====================================================================================
   PROPERTY GET CachedHorizontallyScrollable ( _        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedVerticallyScrollable ( _          ' VTable offset = 64
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationScrollPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationScrollItemPattern interface
' IID = B488300F-D015-4F19-9C29-BB595E3645EF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationScrollItemPattern_INTERFACE_DEFINED)
    %IUIAutomationScrollItemPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationScrollItemPattern = GUID$("{B488300F-D015-4F19-9C29-BB595E3645EF}")

INTERFACE IUIAutomationScrollItemPattern $IID_IUIAutomationScrollItemPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ScrollIntoView ( _                            ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationScrollItemPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationSelectionPattern interface
' IID = 5ED5202E-B2AC-47A6-B638-4B0BF140D78E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationSelectionPattern_INTERFACE_DEFINED)
    %IUIAutomationSelectionPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationSelectionPattern = GUID$("{5ED5202E-B2AC-47A6-B638-4B0BF140D78E}")

INTERFACE IUIAutomationSelectionPattern $IID_IUIAutomationSelectionPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCurrentSelection ( _                       ' VTable offset = 12
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CurrentCanSelectMultiple ( _            ' VTable offset = 16
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsSelectionRequired ( _          ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   METHOD GetCachedSelection ( _                        ' VTable offset = 24
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CachedCanSelectMultiple ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsSelectionRequired ( _           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationSelectionPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationSelectionItemPattern interface
' IID = A8EFA66A-0FDA-421A-9194-38021F3578EA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationSelectionItemPattern_INTERFACE_DEFINED)
    %IUIAutomationSelectionItemPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationSelectionItemPattern = GUID$("{A8EFA66A-0FDA-421A-9194-38021F3578EA}")

INTERFACE IUIAutomationSelectionItemPattern $IID_IUIAutomationSelectionItemPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Select ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD AddToSelection ( _                            ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromSelection ( _                       ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentIsSelected ( _                   ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentSelectionContainer ( _           ' VTable offset = 28
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================
   PROPERTY GET CachedIsSelected ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedSelectionContainer ( _            ' VTable offset = 36
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationSelectionItemPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationSynchronizedInputPattern interface
' IID = 2233BE0B-AFB7-448B-9FDA-3B378AA5EAE1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED)
    %IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationSynchronizedInputPattern = GUID$("{2233BE0B-AFB7-448B-9FDA-3B378AA5EAE1}")

INTERFACE IUIAutomationSynchronizedInputPattern $IID_IUIAutomationSynchronizedInputPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD StartListening ( _                            ' VTable offset = 12
     BYVAL inputType AS LONG _                          ' __in enum SynchronizedInputType inputType
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTablePattern interface
' IID = 620E691C-EA96-4710-A850-754B24CE2417
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTablePattern_INTERFACE_DEFINED)
    %IUIAutomationTablePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationTablePattern = GUID$("{620E691C-EA96-4710-A850-754B24CE2417}")

INTERFACE IUIAutomationTablePattern $IID_IUIAutomationTablePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCurrentRowHeaders ( _                      ' VTable offset = 12
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   METHOD GetCurrentColumnHeaders ( _                   ' VTable offset = 16
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CurrentRowOrColumnMajor ( _             ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum RowOrColumnMajor *retVal
   ' =====================================================================================
   PROPERTY GET GetCachedRowHeaders ( _                 ' VTable offset = 24
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET GetCachedColumnHeaders ( _              ' VTable offset = 28
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   PROPERTY GET CachedRowOrColumnMajor ( _              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out enum RowOrColumnMajor *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTablePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTableItemPattern interface
' IID = 0B964EB3-EF2E-4464-9C79-61D61737A27E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTableItemPattern_INTERFACE_DEFINED)
    %IUIAutomationTableItemPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationTableItemPattern = GUID$("{0B964EB3-EF2E-4464-9C79-61D61737A27E}")

INTERFACE IUIAutomationTableItemPattern $IID_IUIAutomationTableItemPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetCurrentRowHeaderItems ( _                  ' VTable offset = 12
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   METHOD GetCurrentColumnHeaderItems ( _               ' VTable offset = 16
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   METHOD GetCachedRowHeaderItems ( _                   ' VTable offset = 20
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================
   METHOD GetCachedColumnHeaderItems ( _                ' VTable offset = 24
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTableItemPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTogglePattern interface
' IID = 94CF8058-9B8D-4AB9-8BFD-4CD0A33C8C70
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTogglePattern_INTERFACE_DEFINED)
    %IUIAutomationTogglePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationTogglePattern = GUID$("{94CF8058-9B8D-4AB9-8BFD-4CD0A33C8C70}")

INTERFACE IUIAutomationTogglePattern $IID_IUIAutomationTogglePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Toggle ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD CurrentToggleState ( _                        ' VTable offset = 16
   ) AS LONG                                            ' __retval_out enum ToggleState *retVal
   ' =====================================================================================
   METHOD CachedToggleState ( _                         ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum ToggleState *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTogglePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTransformPattern interface
' IID = A9B55844-A55D-4EF0-926D-569C16FF89BB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTransformPattern_INTERFACE_DEFINED)
    %IUIAutomationTransformPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationTransformPattern = GUID$("{A9B55844-A55D-4EF0-926D-569C16FF89BB}")

INTERFACE IUIAutomationTransformPattern $IID_IUIAutomationTransformPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 12
     BYVAL x AS DOUBLE _                                ' __in double x
   , BYVAL y AS DOUBLE _                                ' __in double y
   )                                                    ' void
   ' =====================================================================================
   METHOD Resize ( _                                    ' VTable offset = 16
     BYVAL width AS DOUBLE _                            ' __in double width
   , BYVAL height AS DOUBLE _                           ' __in double height
   )                                                    ' void
   ' =====================================================================================
   METHOD Rotate ( _                                    ' VTable offset = 20
     BYVAL degrees AS DOUBLE _                          ' __in double degrees
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCanMove ( _                      ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentCanResize ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentCanRotate ( _                    ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedCanMove ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedCanResize ( _                     ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedCanRotate ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTransformPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationValuePattern interface
' IID = A94CD8B1-0844-4CD6-9D2D-640537AB39E9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationValuePattern_INTERFACE_DEFINED)
    %IUIAutomationValuePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationValuePattern = GUID$("{A94CD8B1-0844-4CD6-9D2D-640537AB39E9}")

INTERFACE IUIAutomationValuePattern $IID_IUIAutomationValuePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 12
     BYVAL val AS WSTRING _                             ' __in BSTR val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentValue ( _                        ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsReadOnly ( _                   ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedValue ( _                         ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsReadOnly ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationValuePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationWindowPattern interface
' IID = 0FAEF453-9208-43EF-BBB2-3B485177864F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationWindowPattern_INTERFACE_DEFINED)
    %IUIAutomationWindowPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationWindowPattern = GUID$("{0FAEF453-9208-43EF-BBB2-3B485177864F}")

INTERFACE IUIAutomationWindowPattern $IID_IUIAutomationWindowPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD WaitForInputIdle ( _                          ' VTable offset = 16
     BYVAL milliseconds AS LONG _                       ' __in int milliseconds
   ) AS LONG                                            ' __retval_out BOOL *success
   ' =====================================================================================
   METHOD SetWindowVisualState ( _                      ' VTable offset = 20
     BYVAL state AS LONG _                              ' __in enum WindowVisualState state
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentCanMaximize ( _                  ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentCanMinimize ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsModal ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentIsTopmost ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CurrentWindowVisualState ( _            ' VTable offset = 40
   ) AS LONG                                            ' __retval_out enum WindowVisualState *retVal
   ' =====================================================================================
   PROPERTY GET CurrentWindowInteractionState ( _       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out enum WindowInteractionState *retVal
   ' =====================================================================================
   PROPERTY GET CachedCanMaximize ( _                   ' VTable offset = 48
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedCanMinimize ( _                   ' VTable offset = 52
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsModal ( _                       ' VTable offset = 56
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedIsTopmost ( _                     ' VTable offset = 60
   ) AS LONG                                            ' __retval_out BOOL *retVal
   ' =====================================================================================
   PROPERTY GET CachedWindowVisualState ( _             ' VTable offset = 64
   ) AS LONG                                            ' __retval_out enum WindowVisualState *retVal
   ' =====================================================================================
   PROPERTY GET CachedWindowInteractionState ( _        ' VTable offset = 64
   ) AS LONG                                            ' __retval_out enum WindowInteractionState *retVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationWindowPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTextRange interface
' IID = A543CC6A-F4AE-494B-8239-C814481187A8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTextRange_INTERFACE_DEFINED)
    %IUIAutomationTextRange_INTERFACE_DEFINED = 1

$IID_IUIAutomationTextRange = GUID$("{A543CC6A-F4AE-494B-8239-C814481187A8}")

INTERFACE IUIAutomationTextRange $IID_IUIAutomationTextRange

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **clonedRange
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 16
     BYVAL range AS IUIAutomationTextRange _            ' __in IUIAutomationTextRange *range
   ) AS LONG                                            ' __retval_out BOOL *areSame
   ' =====================================================================================
   METHOD CompareEndpoints ( _                          ' VTable offset = 20
     BYVAL srcEndPoint AS LONG _                        ' __in enum TextPatternRangeEndpoint srcEndPoint
   , BYVAL range AS IUIAutomationTextRange _            ' __in IUIAutomationTextRange *range
   , BYVAL targetEndPoint AS LONG _                     ' __in enum TextPatternRangeEndpoint targetEndPoint
   ) AS LONG                                            ' __retval_out int *compValue
   ' =====================================================================================
   METHOD ExpandToEnclosingUnit ( _                     ' VTable offset = 24
     BYVAL textUnit AS LONG _                           ' __in enum TextUnit textUnit
   )                                                    ' void
   ' =====================================================================================
   METHOD FindAttribute ( _                             ' VTable offset = 28
     BYVAL attr AS LONG _                               ' __in TEXTATTRIBUTEID attr
   , BYVAL val AS VARIANT _                             ' __in VARIANT val
   , BYVAL backward AS LONG _                           ' __in BOOL backward
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **found
   ' =====================================================================================
   METHOD FindText ( _                                  ' VTable offset = 32
     BYVAL text AS WSTRING _                            ' __in BSTR text
   , BYVAL backward AS LONG _                           ' __in BOOL backward
   , BYVAL ignoreCase AS LONG _                         ' __in BOOL ignoreCase
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **found
   ' =====================================================================================
   METHOD GetAttributeValue ( _                         ' VTable offset = 36
     BYVAL attr AS LONG _                               ' __in TEXTATTRIBUTEID attr
   ) AS VARIANT                                         ' __retval_out VARIANT *value
   ' =====================================================================================
   METHOD GetBoundingRectangles ( _                     ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *boundingRects
   ' =====================================================================================
   METHOD GetEnclosingElement ( _                       ' VTable offset = 44
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **enclosingElement
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 48
     BYVAL maxLength AS LONG _                          ' __in int maxLength
   ) AS WSTRING                                         ' __retval_out BSTR *text
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 52
     BYVAL unit AS LONG _                               ' __in enum TextUnit unit
   , BYVAL count AS LONG _                              ' __in int count
   ) AS LONG                                            ' __retval_out int *moved
   ' =====================================================================================
   METHOD MoveEndpointByUnit ( _                        ' VTable offset = 56
     BYVAL endpoint AS LONG _                           ' __in enum TextPatternRangeEndpoint endpoint
   , BYVAL unit AS LONG _                               ' __in enum TextUnit unit
   , BYVAL count AS LONG _                              ' __in int count
   ) AS LONG                                            ' __retval_out int *moved
   ' =====================================================================================
   METHOD MoveEndpointByRange ( _                       ' VTable offset = 60
     BYVAL srcEndPoint AS LONG _                        ' __in enum TextPatternRangeEndpoint srcEndPoint
   , BYVAL range AS IUIAutomationTextRange _            ' __in IUIAutomationTextRange *range
   , BYVAL targetEndPoint AS LONG _                     ' __in enum TextPatternRangeEndpoint targetEndPoint
   )                                                    ' void
   ' =====================================================================================
   METHOD Select ( _                                    ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD AddToSelection ( _                            ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFromSelection ( _                       ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD ScrollIntoView ( _                            ' VTable offset = 76
     BYVAL alignToTop AS LONG _                         ' __in BOOL alignToTop
   )                                                    ' void
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 80
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray *children
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTextRange_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTextRangeArray interface
' IID = CE4AE76A-E717-4C98-81EA-47371D028EB6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTextRangeArray_INTERFACE_DEFINED)
    %IUIAutomationTextRangeArray_INTERFACE_DEFINED = 1

$IID_IUIAutomationTextRangeArray = GUID$("{CE4AE76A-E717-4C98-81EA-47371D028EB6}")

INTERFACE IUIAutomationTextRangeArray $IID_IUIAutomationTextRangeArray

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Length ( _                              ' VTable offset = 12
   ) AS LONG                                            ' __retval_out int *length
   ' =====================================================================================
   METHOD GetElement ( _                                ' VTable offset = 16
     BYVAL index AS LONG _                              ' __in int index
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **element
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTextRangeArray_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationTextPattern interface
' IID = 32EBA289-3583-42C9-9C59-3B6D9A1E9B6A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationTextPattern_INTERFACE_DEFINED)
    %IUIAutomationTextPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationTextPattern = GUID$("{32EBA289-3583-42C9-9C59-3B6D9A1E9B6A}")

INTERFACE IUIAutomationTextPattern $IID_IUIAutomationTextPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD RangeFromPoint ( _                            ' VTable offset = 12
     BYVAL pt AS POINT _                                ' __in POINT pt
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **range
   ' =====================================================================================
   METHOD RangeFromChild ( _                            ' VTable offset = 16
     BYVAL child AS IUIAutomationElement _              ' __in IUIAutomationElement *child
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **range
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 20
   ) AS IUIAutomationTextRangeArray                     ' __retval_out IUIAutomationTextRangeArray **ranges
   ' =====================================================================================
   METHOD GetVisibleRanges ( _                          ' VTable offset = 24
   ) AS IUIAutomationTextRangeArray                     ' __retval_out IUIAutomationTextRangeArray **ranges
   ' =====================================================================================
   PROPERTY GET DocumentRange ( _                       ' VTable offset = 28
   ) AS IUIAutomationTextRange                          ' __retval_out IUIAutomationTextRange **range
   ' =====================================================================================
   PROPERTY GET SupportedTextSelection ( _              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out enum SupportedTextSelection *supportedTextSelection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationTextPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationLegacyIAccessiblePattern interface
' IID = 828055AD-355B-4435-86D5-3B51C14A9B1B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED)
    %IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationLegacyIAccessiblePattern = GUID$("{828055AD-355B-4435-86D5-3B51C14A9B1B}")

INTERFACE IUIAutomationLegacyIAccessiblePattern $IID_IUIAutomationLegacyIAccessiblePattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Select ( _                                    ' VTable offset = 12
     BYVAL flagsSelect AS LONG _                        ' __in long flagsSelect
   )                                                    ' void
   ' =====================================================================================
   METHOD DoDefaultAction ( _                           ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 20
     BYREF szValue AS WSTRINGZ _                        ' __in LPCWSTR szValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentChildId ( _                      ' VTable offset = 24
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET CurrentName ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pszName
   ' =====================================================================================
   PROPERTY GET CurrentValue ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pszValue
   ' =====================================================================================
   PROPERTY GET CurrentDescription ( _                  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   PROPERTY GET CurrentRole ( _                         ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out DWORD *pdwRole
   ' =====================================================================================
   PROPERTY GET CurrentState ( _                        ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out DWORD *pdwState
   ' =====================================================================================
   PROPERTY GET CurrentHelp ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pszHelp
   ' =====================================================================================
   PROPERTY GET CurrentKeyboardShortcut ( _             ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pszKeyboardShortcut
   ' =====================================================================================
   PROPERTY GET GetCurrentSelection ( _                 ' VTable offset = 56
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **pvarSelectedChildren
   ' =====================================================================================
   PROPERTY GET CurrentDefaultAction ( _                ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pszDefaultAction
   ' =====================================================================================
   PROPERTY GET CachedChildId ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET CachedName ( _                          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pszName
   ' =====================================================================================
   PROPERTY GET CachedValue ( _                         ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pszValue
   ' =====================================================================================
   PROPERTY GET CachedDescription ( _                   ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   PROPERTY GET CachedRole ( _                          ' VTable offset = 80
   ) AS DWORD                                           ' __retval_out DWORD *pdwRole
   ' =====================================================================================
   PROPERTY GET CachedState ( _                         ' VTable offset = 84
   ) AS DWORD                                           ' __retval_out DWORD *pdwState
   ' =====================================================================================
   PROPERTY GET CachedHelp ( _                          ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pszHelp
   ' =====================================================================================
   PROPERTY GET CachedKeyboardShortcut ( _              ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pszKeyboardShortcut
   ' =====================================================================================
   PROPERTY GET GetCachedSelection ( _                  ' VTable offset = 96
   ) AS IUIAutomationElementArray                       ' __retval_out IUIAutomationElementArray **pvarSelectedChildren
   ' =====================================================================================
   PROPERTY GET CachedDefaultAction ( _                 ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pszDefaultAction
   ' =====================================================================================
   METHOD GetIAccessible ( _                            ' VTable offset = 104
   ) AS IAccessible                                     ' __retval_out IAccessible **ppAccessible
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationItemContainerPattern interface
' IID = C690FDB2-27A8-423C-812D-429773C9084E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationItemContainerPattern_INTERFACE_DEFINED)
    %IUIAutomationItemContainerPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationItemContainerPattern = GUID$("{C690FDB2-27A8-423C-812D-429773C9084E}")

INTERFACE IUIAutomationItemContainerPattern $IID_IUIAutomationItemContainerPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD FindItemByProperty ( _                        ' VTable offset = 12
     BYVAL pStartAfter AS IUIAutomationElement _        ' __in IUIAutomationElement *pStartAfter
   , BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **pFound
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationItemContainerPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationVirtualizedItemPattern interface
' IID = 6BA3D7A6-04CF-4F11-8793-A8D1CDE9969F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED)
    %IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED = 1

$IID_IUIAutomationVirtualizedItemPattern = GUID$("{6BA3D7A6-04CF-4F11-8793-A8D1CDE9969F}")

INTERFACE IUIAutomationVirtualizedItemPattern $IID_IUIAutomationVirtualizedItemPattern

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Realize ( _                                   ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationProxyFactory interface
' IID = 85B94ECD-849D-42B6-B94D-D6DB23FDF5A4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationProxyFactory_INTERFACE_DEFINED)
    %IUIAutomationProxyFactory_INTERFACE_DEFINED = 1

$IID_IUIAutomationProxyFactory = GUID$("{85B94ECD-849D-42B6-B94D-D6DB23FDF5A4}")

INTERFACE IUIAutomationProxyFactory $IID_IUIAutomationProxyFactory

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateProvider ( _                            ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in UIA_HWND hwnd
   , BYVAL idObject AS LONG _                           ' __in LONG idObject
   , BYVAL idChild AS LONG _                            ' __in LONG idChild
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **provider
   ' =====================================================================================
   PROPERTY GET ProxyFactoryId ( _                      ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *factoryId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationProxyFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationProxyFactoryEntry interface
' IID = D50E472E-B64B-490C-BCA1-D30696F9F289
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED)
    %IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED = 1

$IID_IUIAutomationProxyFactoryEntry = GUID$("{D50E472E-B64B-490C-BCA1-D30696F9F289}")

INTERFACE IUIAutomationProxyFactoryEntry $IID_IUIAutomationProxyFactoryEntry

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ProxyFactory ( _                        ' VTable offset = 12
   ) AS IUIAutomationProxyFactory                       ' __retval_out IUIAutomationProxyFactory **factory
   ' =====================================================================================
   PROPERTY GET ClassName ( _                           ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *className
   ' =====================================================================================
   PROPERTY GET ImageName ( _                           ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *className
   ' =====================================================================================
   PROPERTY GET AllowSubstringMatch ( _                 ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *allowSubstringMatch
   ' =====================================================================================
   PROPERTY GET CanCheckBaseClass ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *canCheckBaseClass
   ' =====================================================================================
   PROPERTY GET NeedsAdviseEvents ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *adviseEvents
   ' =====================================================================================
   PROPERTY SET ClassName ( _                           ' VTable offset = 36
     BYREF className AS WSTRINGZ _                      ' __in LPCWSTR className
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ImageName ( _                           ' VTable offset = 40
     BYREF imageName AS WSTRINGZ _                      ' __in LPCWSTR imageName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET AllowSubstringMatch ( _                 ' VTable offset = 44
     BYVAL allowSubstringMatch AS LONG _                ' __in BOOL allowSubstringMatch
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET CanCheckBaseClass ( _                   ' VTable offset = 48
     BYVAL canCheckBaseClass AS LONG _                  ' __in BOOL canCheckBaseClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET NeedsAdviseEvents ( _                   ' VTable offset = 52
     BYVAL adviseEvents AS LONG _                       ' __in BOOL adviseEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWinEventsForAutomationEvent ( _            ' VTable offset = 56
     BYVAL eventId AS LONG _                            ' __in EVENTID eventId
   , BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL winEvents AS DWORD _                         ' __in SAFEARRAY * winEvents
   )                                                    ' void
   ' =====================================================================================
   METHOD GetWinEventsForAutomationEvent ( _            ' VTable offset = 60
     BYVAL eventId AS LONG _                            ' __in EVENTID eventId
   , BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *winEvents
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomationProxyFactoryMapping interface
' IID = 09E31E18-872D-4873-93D1-1E541EC133FD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED)
    %IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED = 1

$IID_IUIAutomationProxyFactoryMapping = GUID$("{09E31E18-872D-4873-93D1-1E541EC133FD}")

INTERFACE IUIAutomationProxyFactoryMapping $IID_IUIAutomationProxyFactoryMapping

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out UINT *count
   ' =====================================================================================
   PROPERTY GET Table ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *table
   ' =====================================================================================
   METHOD GetEntry ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT index
   ) AS IUIAutomationProxyFactoryEntry                  ' __retval_out IUIAutomationProxyFactoryEntry **entry
   ' =====================================================================================
   METHOD SetTable ( _                                  ' VTable offset = 24
     BYVAL factoryList AS DWORD _                       ' __in SAFEARRAY * factoryList
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertEntries ( _                             ' VTable offset = 28
     BYVAL before AS DWORD _                            ' __in UINT before
   , BYVAL factoryList AS DWORD _                       ' __in SAFEARRAY * factoryList
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertEntry ( _                               ' VTable offset = 32
     BYVAL before AS DWORD _                            ' __in UINT before
   , BYVAL factory AS IUIAutomationProxyFactoryEntry _  ' __in IUIAutomationProxyFactoryEntry *factory
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveEntry ( _                               ' VTable offset = 36
     BYVAL before AS DWORD _                            ' __in UINT before
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearTable ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDefaultTable ( _                       ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAutomation interface
' IID = 30CBE57D-D9D0-452A-AB13-7AC5AC4825EE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomation_INTERFACE_DEFINED)
    %IUIAutomation_INTERFACE_DEFINED = 1

$IID_IUIAutomation = GUID$("{30CBE57D-D9D0-452A-AB13-7AC5AC4825EE}")

INTERFACE IUIAutomation $IID_IUIAutomation

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CompareElements ( _                           ' VTable offset = 12
     BYVAL el1 AS IUIAutomationElement _                ' __in IUIAutomationElement *el1
   , BYVAL el2 AS IUIAutomationElement _                ' __in IUIAutomationElement *el2
   ) AS LONG                                            ' __retval_out BOOL *areSame
   ' =====================================================================================
   METHOD CompareRuntimeIds ( _                         ' VTable offset = 16
     BYVAL runtimeId1 AS DWORD _                        ' __in SAFEARRAY * runtimeId1
   , BYVAL runtimeId2 AS DWORD _                        ' __in SAFEARRAY * runtimeId2
   ) AS LONG                                            ' __retval_out BOOL *areSame
   ' =====================================================================================
   METHOD GetRootElement ( _                            ' VTable offset = 20
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **root
   ' =====================================================================================
   METHOD ElementFromHandle ( _                         ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in UIA_HWND hwnd
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD ElementFromPoint ( _                          ' VTable offset = 28
     BYVAL pt AS POINT _                                ' __in POINT pt
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD GetFocusedElement ( _                         ' VTable offset = 32
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD GetRootElementBuildCache ( _                  ' VTable offset = 36
     BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **root
   ' =====================================================================================
   METHOD ElementFromHandleBuildCache ( _               ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in UIA_HWND hwnd
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD ElementFromPointBuildCache ( _                ' VTable offset = 44
     BYVAL pt AS POINT _                                ' __in POINT pt
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD GetFocusedElementBuildCache ( _               ' VTable offset = 48
     BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD CreateTreeWalker ( _                          ' VTable offset = 52
     BYVAL pCondition AS IUIAutomationCondition _       ' __in IUIAutomationCondition *pCondition
   ) AS IUIAutomationTreeWalker                         ' __retval_out IUIAutomationTreeWalker **walker
   ' =====================================================================================
   PROPERTY GET ControlViewWalker ( _                   ' VTable offset = 56
   ) AS IUIAutomationTreeWalker                         ' __retval_out IUIAutomationTreeWalker **walker
   ' =====================================================================================
   PROPERTY GET ContentViewWalker ( _                   ' VTable offset = 60
   ) AS IUIAutomationTreeWalker                         ' __retval_out IUIAutomationTreeWalker **walker
   ' =====================================================================================
   PROPERTY GET RawViewWalker ( _                       ' VTable offset = 64
   ) AS IUIAutomationTreeWalker                         ' __retval_out IUIAutomationTreeWalker **walker
   ' =====================================================================================
   PROPERTY GET RawViewCondition ( _                    ' VTable offset = 68
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **condition
   ' =====================================================================================
   PROPERTY GET ControlViewCondition ( _                ' VTable offset = 72
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **condition
   ' =====================================================================================
   PROPERTY GET ContentViewCondition ( _                ' VTable offset = 76
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **condition
   ' =====================================================================================
   METHOD CreateCacheRequest ( _                        ' VTable offset = 80
   ) AS IUIAutomationCacheRequest                       ' __retval_out IUIAutomationCacheRequest **cacheRequest
   ' =====================================================================================
   METHOD CreateTrueCondition ( _                       ' VTable offset = 84
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateFalseCondition ( _                      ' VTable offset = 88
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreatePropertyCondition ( _                   ' VTable offset = 92
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreatePropertyConditionEx ( _                 ' VTable offset = 96
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   , BYVAL flags AS LONG _                              ' __in enum PropertyConditionFlags flags
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateAndCondition ( _                        ' VTable offset = 100
     BYVAL condition1 AS IUIAutomationCondition _       ' __in IUIAutomationCondition *condition1
   , BYVAL condition2 AS IUIAutomationCondition _       ' __in IUIAutomationCondition *condition2
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateAndConditionFromArray ( _               ' VTable offset = 104
     BYVAL conditions AS DWORD _                        ' __in SAFEARRAY * conditions
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateAndConditionFromNativeArray ( _         ' VTable offset = 108
     BYREF conditions AS IUIAutomationCondition _       ' __in IUIAutomationCondition **conditions
   , BYVAL conditionCount AS LONG _                     ' __in int conditionCount
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateOrCondition ( _                         ' VTable offset = 112
     BYVAL condition1 AS IUIAutomationCondition _       ' __in IUIAutomationCondition *condition1
   , BYVAL condition2 AS IUIAutomationCondition _       ' __in IUIAutomationCondition *condition2
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateOrConditionFromArray ( _                ' VTable offset = 116
     BYVAL conditions AS DWORD _                        ' __in SAFEARRAY * conditions
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateOrConditionFromNativeArray ( _          ' VTable offset = 120
     BYREF conditions AS IUIAutomationCondition _       ' __in IUIAutomationCondition **conditions
   , BYVAL conditionCount AS LONG _                     ' __in int conditionCount
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD CreateNotCondition ( _                        ' VTable offset = 124
     BYVAL condition AS IUIAutomationCondition _        ' __in IUIAutomationCondition *condition
   ) AS IUIAutomationCondition                          ' __retval_out IUIAutomationCondition **newCondition
   ' =====================================================================================
   METHOD AddAutomationEventHandler ( _                 ' VTable offset = 128
     BYVAL eventId AS DWORD _                           ' __in EVENTID eventId
   , BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   , BYVAL handler AS IUIAutomationEventHandler _       ' __in IUIAutomationEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAutomationEventHandler ( _              ' VTable offset = 132
     BYVAL eventId AS DWORD _                           ' __in EVENTID eventId
   , BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL handler AS IUIAutomationEventHandler _       ' __in IUIAutomationEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyChangedEventHandlerNativeArray ( _ ' VTable offset = 136
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   , BYREF propertyArray AS DWORD _                     ' __in PROPERTYID *propertyArray
   , BYVAL propertyCount AS LONG _                      ' __in int propertyCount
   )                                                    ' void
   ' =====================================================================================
   METHOD AddPropertyChangedEventHandler ( _            ' VTable offset = 140
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   , BYVAL propertyArray AS DWORD _                     ' __in SAFEARRAY *propertyArray
   )                                                    ' void
   ' =====================================================================================
   METHOD RemovePropertyChangedEventHandler ( _         ' VTable offset = 144
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD AddStructureChangedEventHandler ( _           ' VTable offset = 148
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL scope AS LONG _                              ' __in enum TreeScope scope
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveStructureChangedEventHandler ( _        ' VTable offset = 152
     BYVAL element AS IUIAutomationElement _            ' __in IUIAutomationElement *element
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFocusChangedEventHandler ( _               ' VTable offset = 156
     BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   , BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveFocusChangedEventHandler ( _            ' VTable offset = 160
     BYVAL handler AS IUIAutomationPropertyChangedEventHandler _ ' __in IUIAutomationPropertyChangedEventHandler *handler
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveAllEventHandlers ( _                    ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD IntNativeArrayToSafeArray ( _                 ' VTable offset = 168
     BYREF array AS LONG _                              ' __in int *array
   , BYVAL arrayCount AS LONG _                         ' __in int arrayCount
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *safeArray
   ' =====================================================================================
   METHOD IntSafeArrayToNativeArray ( _                 ' VTable offset = 172
     BYVAL intArray AS DWORD _                          ' __in SAFEARRAY * intArray
   , BYREF array AS LONG _                              ' __out int **array
   , BYREF arrayCount AS LONG _                         ' __out int arrayCount
   )                                                    ' void
   ' =====================================================================================
   METHOD RectToVariant ( _                             ' VTable offset = 176
     BYVAL rc AS RECT _                                 ' __in RECT rc
   ) AS VARIANT                                         ' __retval_out VARIANT *var
   ' =====================================================================================
   METHOD VariantToRect ( _                             ' VTable offset = 180
     BYVAL var AS VARIANT _                             ' __in VARIANT var
   ) AS RECT                                            ' __retval_out RECT *rc
   ' =====================================================================================
   METHOD SafeArrayToRectNativeArray ( _                ' VTable offset = 184
     BYVAL rects AS DWORD _                             ' __in SAFEARRAY * rects
   , BYREF rectArray AS RECT _                          ' __out RECT **rectArray
   ) AS LONG                                            ' __retval_out int *rectArrayCount
   ' =====================================================================================
   METHOD CreateProxyFactoryEntry ( _                   ' VTable offset = 188
     BYVAL factory AS IUIAutomationProxyFactory _       ' __in IUIAutomationProxyFactory *factory
   ) AS IUIAutomationProxyFactoryEntry                  ' __retval_out IUIAutomationProxyFactoryEntry **factoryEntry
   ' =====================================================================================
   PROPERTY GET ProxyFactoryMapping ( _                 ' VTable offset = 192
   ) AS IUIAutomationProxyFactoryMapping                ' __retval_out IUIAutomationProxyFactoryMapping **factoryMapping
   ' =====================================================================================
   METHOD GetPropertyProgrammaticName ( _               ' VTable offset = 196
     BYVAL property AS LONG _                           ' __in PROPERTYID property
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   METHOD GetPatternProgrammaticName ( _                ' VTable offset = 200
     BYVAL pattern AS LONG _                            ' __in PROPERTYID pattern
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   METHOD PollForPotentialSupportedPatterns ( _         ' VTable offset = 204
     BYVAL pElement AS IUIAutomationElement _           ' __in IUIAutomationElement *pElement
   , BYREF patternIds AS DWORD _                        ' __out SAFEARRAY * *patternIds
   , BYREF patternNames AS DWORD _                      ' __out SAFEARRAY * *patternNames
   )                                                    ' void
   ' =====================================================================================
   METHOD PollForPotentialSupportedProperties ( _       ' VTable offset = 208
     BYVAL pElement AS IUIAutomationElement _           ' __in IUIAutomationElement *pElement
   , BYREF propertyIds AS DWORD _                       ' __out SAFEARRAY * *propertyIds
   , BYREF propertyNames AS DWORD _                     ' __out SAFEARRAY * *propertyNames
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckNotSupported ( _                         ' VTable offset = 212
     BYVAL value AS VARIANT _                           ' __in VARIANT value
   ) AS LONG                                            ' __retval_out BOOL *isNotSupported
   ' =====================================================================================
   PROPERTY GET ReservedNotSupportedValue ( _           ' VTable offset = 216
   ) AS IUnknown                                        ' __retval_out IUnknown **notSupportedValue
   ' =====================================================================================
   PROPERTY GET ReservedMixedAttributeValue ( _         ' VTable offset = 220
   ) AS IUnknown                                        ' __retval_out IUnknown **mixedAttributeValue
   ' =====================================================================================
   METHOD ElementFromIAccessible ( _                    ' VTable offset = 224
     BYVAL accessible AS IAccessible _                  ' __in IAccessible *accessible
   , BYVAL childId AS LONG _                            ' __in int childId
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================
   METHOD ElementFromIAccessibleBuildCache ( _          ' VTable offset = 228
     BYVAL accessible AS IAccessible _                  ' __in IAccessible *accessible
   , BYVAL childId AS LONG _                            ' __in int childId
   , BYVAL cacheRequest AS IUIAutomationCacheRequest _  ' __in IUIAutomationCacheRequest *cacheRequest
   ) AS IUIAutomationElement                            ' __retval_out IUIAutomationElement **element
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAutomation_INTERFACE_DEFINED__ */

$CLSID_CUIAutomation = GUID$("{FF48DBA4-60EF-4201-AA87-54103EEF594E}")
