' ########################################################################################
' Microsoft Windows
' File: UIAutomationCore.inc
' Contents: UIAutomation interface definitions and related types and enums
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UIAUTOMATIONCORE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "oleacc.inc"

' enum NavigateDirection
%NavigateDirection_Parent          = 0
%NavigateDirection_NextSibling     = 1
%NavigateDirection_PreviousSibling = 2
%NavigateDirection_FirstChild      = 3
%NavigateDirection_LastChild       = 4

' enum ProviderOptions
%ProviderOptions_ClientSideProvider    = &H1
%ProviderOptions_ServerSideProvider    = &H2
%ProviderOptions_NonClientAreaProvider = &H4
%ProviderOptions_OverrideProvider      = &H8
%ProviderOptions_ProviderOwnsSetFocus  = &H10
%ProviderOptions_UseComThreading       = &H20

' enum StructureChangeType
%StructureChangeType_ChildAdded          = 0
%StructureChangeType_ChildRemoved        = %StructureChangeType_ChildAdded          + 1
%StructureChangeType_ChildrenInvalidated = %StructureChangeType_ChildRemoved        + 1
%StructureChangeType_ChildrenBulkAdded   = %StructureChangeType_ChildrenInvalidated + 1
%StructureChangeType_ChildrenBulkRemoved = %StructureChangeType_ChildrenBulkAdded   + 1
%StructureChangeType_ChildrenReordered   = %StructureChangeType_ChildrenBulkRemoved + 1

' enum OrientationType
%OrientationType_None       = 0
%OrientationType_Horizontal = 1
%OrientationType_Vertical   = 2

' enum DockPosition
%DockPosition_Top    = 0
%DockPosition_Left   = 1
%DockPosition_Bottom = 2
%DockPosition_Right  = 3
%DockPosition_Fill   = 4
%DockPosition_None   = 5

' enum ExpandCollapseState
%ExpandCollapseState_Collapsed         = 0
%ExpandCollapseState_Expanded          = 1
%ExpandCollapseState_PartiallyExpanded = 2
%ExpandCollapseState_LeafNode          = 3

' enum ScrollAmount
%ScrollAmount_LargeDecrement = 0
%ScrollAmount_SmallDecrement = 1
%ScrollAmount_NoAmount       = 2
%ScrollAmount_LargeIncrement = 3
%ScrollAmount_SmallIncrement = 4

' enum RowOrColumnMajor
%RowOrColumnMajor_RowMajor      = 0
%RowOrColumnMajor_ColumnMajor   = 1
%RowOrColumnMajor_Indeterminate = 2

' enum ToggleState
%ToggleState_Off           = 0
%ToggleState_On            = 1
%ToggleState_Indeterminate = 2

' enum WindowVisualState
%WindowVisualState_Normal    = 0
%WindowVisualState_Maximized = 1
%WindowVisualState_Minimized = 2

' enum SynchronizedInputType
%SynchronizedInputType_KeyUp          = &H1
%SynchronizedInputType_KeyDown        = &H2
%SynchronizedInputType_LeftMouseUp    = &H4
%SynchronizedInputType_LeftMouseDown  = &H8
%SynchronizedInputType_RightMouseUp   = &H10
%SynchronizedInputType_RightMouseDown = &H20

' enum WindowInteractionState
%WindowInteractionState_Running                 = 0
%WindowInteractionState_Closing                 = 1
%WindowInteractionState_ReadyForUserInteraction = 2
%WindowInteractionState_BlockedByModalWindow    = 3
%WindowInteractionState_NotResponding           = 4

' enum TextUnit
%TextUnit_Character = 0
%TextUnit_Format    = 1
%TextUnit_Word      = 2
%TextUnit_Line      = 3
%TextUnit_Paragraph = 4
%TextUnit_Page      = 5
%TextUnit_Document  = 6

' enum TextPatternRangeEndpoint
%TextPatternRangeEndpoint_Start = 0
%TextPatternRangeEndpoint_End   = 1

' enum SupportedTextSelection
%SupportedTextSelection_None     = 0
%SupportedTextSelection_Single   = 1
%SupportedTextSelection_Multiple = 2

' enum AnimationStyle
%AnimationStyle_None               = 0
%AnimationStyle_LasVegasLights     = 1
%AnimationStyle_BlinkingBackground = 2
%AnimationStyle_SparkleText        = 3
%AnimationStyle_MarchingBlackAnts  = 4
%AnimationStyle_MarchingRedAnts    = 5
%AnimationStyle_Shimmer            = 6
%AnimationStyle_Other              = -1

' enum BulletStyle
%BulletStyle_None               = 0
%BulletStyle_HollowRoundBullet  = 1
%BulletStyle_FilledRoundBullet  = 2
%BulletStyle_HollowSquareBullet = 3
%BulletStyle_FilledSquareBullet = 4
%BulletStyle_DashBullet         = 5
%BulletStyle_Other              = -1

' enum CapStyle
%CapStyle_None          = 0
%CapStyle_SmallCap      = 1
%CapStyle_AllCap        = 2
%CapStyle_AllPetiteCaps = 3
%CapStyle_PetiteCaps    = 4
%CapStyle_Unicase       = 5
%CapStyle_Titling       = 6
%CapStyle_Other         = -1

' enum FlowDirections
%FlowDirections_Default     = 0
%FlowDirections_RightToLeft = 1
%FlowDirections_BottomToTop = 2
%FlowDirections_Vertical    = 4

' enum HorizontalTextAlignment
%HorizontalTextAlignment_Left      = 0
%HorizontalTextAlignment_Centered  = 1
%HorizontalTextAlignment_Right     = 2
%HorizontalTextAlignment_Justified = 3

' enum OutlineStyles
%OutlineStyles_None     = 0
%OutlineStyles_Outline  = 1
%OutlineStyles_Shadow   = 2
%OutlineStyles_Engraved = 4
%OutlineStyles_Embossed = 8

' enum TextDecorationLineStyle
%TextDecorationLineStyle_None            = 0
%TextDecorationLineStyle_Single          = 1
%TextDecorationLineStyle_WordsOnly       = 2
%TextDecorationLineStyle_Double          = 3
%TextDecorationLineStyle_Dot             = 4
%TextDecorationLineStyle_Dash            = 5
%TextDecorationLineStyle_DashDot         = 6
%TextDecorationLineStyle_DashDotDot      = 7
%TextDecorationLineStyle_Wavy            = 8
%TextDecorationLineStyle_ThickSingle     = 9
%TextDecorationLineStyle_DoubleWavy      = 11
%TextDecorationLineStyle_ThickWavy       = 12
%TextDecorationLineStyle_LongDash        = 13
%TextDecorationLineStyle_ThickDash       = 14
%TextDecorationLineStyle_ThickDashDot    = 15
%TextDecorationLineStyle_ThickDashDotDot = 16
%TextDecorationLineStyle_ThickDot        = 17
%TextDecorationLineStyle_ThickLongDash   = 18
%TextDecorationLineStyle_Other           = -1

'typedef int PROPERTYID;
'typedef int PATTERNID;
'typedef int EVENTID;
'typedef int TEXTATTRIBUTEID;
'typedef int CONTROLTYPEID;

' // Size = 32 bytes
TYPE UiaRect BYTE
   left   AS DOUBLE
   top    AS DOUBLE
   width  AS DOUBLE
   height AS DOUBLE
END TYPE

' // Size = 16 bytes
TYPE UiaPoint BYTE
   x AS DOUBLE
   y AS DOUBLE
END TYPE

' enum UIAutomationType
%UIAutomationType_Int             = &H1
%UIAutomationType_Bool            = &H2
%UIAutomationType_String          = &H3
%UIAutomationType_Double          = &H4
%UIAutomationType_Point           = &H5
%UIAutomationType_Rect            = &H6
%UIAutomationType_Element         = &H7
%UIAutomationType_Array           = &H10000
%UIAutomationType_Out             = &H20000
%UIAutomationType_IntArray        = %UIAutomationType_Int      OR %UIAutomationType_Array
%UIAutomationType_BoolArray       = %UIAutomationType_Bool     OR %UIAutomationType_Array
%UIAutomationType_StringArray     = %UIAutomationType_String   OR %UIAutomationType_Array
%UIAutomationType_DoubleArray     = %UIAutomationType_Double   OR %UIAutomationType_Array
%UIAutomationType_PointArray      = %UIAutomationType_Point    OR %UIAutomationType_Array
%UIAutomationType_RectArray       = %UIAutomationType_Rect     OR %UIAutomationType_Array
%UIAutomationType_ElementArray    = %UIAutomationType_Element  OR %UIAutomationType_Array
%UIAutomationType_OutInt          = %UIAutomationType_Int      OR %UIAutomationType_Out
%UIAutomationType_OutBool         = %UIAutomationType_Bool     OR %UIAutomationType_Out
%UIAutomationType_OutString       = %UIAutomationType_String   OR %UIAutomationType_Out
%UIAutomationType_OutDouble       = %UIAutomationType_Double   OR %UIAutomationType_Out
%UIAutomationType_OutPoint        = %UIAutomationType_Point    OR %UIAutomationType_Out
%UIAutomationType_OutRect         = %UIAutomationType_Rect     OR %UIAutomationType_Out
%UIAutomationType_OutElement      = %UIAutomationType_Element  OR %UIAutomationType_Out
%UIAutomationType_OutIntArray     = (%UIAutomationType_Int     OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutBoolArray    = (%UIAutomationType_Bool    OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutStringArray  = (%UIAutomationType_String  OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutDoubleArray  = (%UIAutomationType_Double  OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutPointArray   = (%UIAutomationType_Point   OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutRectArray    = (%UIAutomationType_Rect    OR %UIAutomationType_Array) OR %UIAutomationType_Out
%UIAutomationType_OutElementArray = (%UIAutomationType_Element OR %UIAutomationType_Array) OR %UIAutomationType_Out

' // Size = 8 bytes
TYPE UIAutomationParameter DWORD
   type  AS LONG    ' enum UIAutomationType
   pData AS DWORD   ' void*
END TYPE

' // Size = 24 bytes
TYPE UIAutomationPropertyInfo DWORD
   guid              AS GUID           ' GUID
   pProgrammaticName AS WSTRINGZ PTR   ' LPCWSTR
   type              AS LONG           ' enum UIAutomationType
END TYPE

' // Size = 20 bytes
TYPE UIAutomationEventInfo DWORD
   guid              AS GUID           ' GUID
   pProgrammaticName AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 24 bytes
TYPE UIAutomationMethodInfo DWORD
   pProgrammaticName AS WSTRINGZ PTR   ' LPCWSTR
   doSetFocus        AS LONG           ' BOOL
   cInParameters     AS DWORD          ' UINT
   cOutParameters    AS DWORD          ' UINT
   pParameterTypes   AS LONG           ' enum UIAutomationType *
   pParameterNames   AS WSTRINGZ PTR   ' LPCWSTR *
END TYPE

' // Size = 80 bytes
TYPE UIAutomationPatternInfo DWORD
   guid                AS GUID                           ' GUID
   pProgrammaticName   AS WSTRINGZ PTR                   ' LPCWSTR
   providerInterfaceId AS GUID                           ' GUID
   clientInterfaceId   AS GUID                           ' GUID
   cProperties         AS DWORD                          ' UINT
   pProperties         AS UIAutomationPropertyInfo PTR   ' struct UIAutomationPropertyInfo *
   cMethods            AS DWORD                          ' UINT
   pMethods            AS UIAutomationMethodInfo PTR     ' struct UIAutomationMethodInfo *
   cEvents             AS DWORD                          ' UINT
   pEvents             AS UIAutomationEventInfo PTR      ' struct UIAutomationEventInfo *
   pPatternHandler     AS DWORD PTR                      ' IUIAutomationPatternHandler *
END TYPE

#IF NOT %DEF(%UIA_OtherConstants_MODULE_DEFINED)
    %UIA_OtherConstants_MODULE_DEFINED = 1

'const double UIA_ScrollPatternNoScroll   =   -1;
%UIA_ScrollPatternNoScroll = -1

#ENDIF   ' /* __UIA_OtherConstants_MODULE_DEFINED__ */

'EXTERN_C const IID LIBID_UIA;

' ########################################################################################
' IRawElementProviderSimple interface
' IID = D6DD68D1-86FD-4332-8666-9ABEDEA2D24C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRawElementProviderSimple_INTERFACE_DEFINED)
    %IRawElementProviderSimple_INTERFACE_DEFINED = 1

$IID_IRawElementProviderSimple = GUID$("{D6DD68D1-86FD-4332-8666-9ABEDEA2D24C}")

INTERFACE IRawElementProviderSimple $IID_IRawElementProviderSimple

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ProviderOptions ( _                     ' VTable offset = 12
   ) AS LONG                                            ' __retval_out enum ProviderOptions *pRetVal
   ' =====================================================================================
   METHOD GetPatternProvider ( _                        ' VTable offset = 16
     BYVAL patternId AS LONG _                          ' __in PATTERNID patternId
   ) AS IUnknown                                        ' __retval_out IUnknown **pRetVal
   ' =====================================================================================
   METHOD GetPropertyValue ( _                          ' VTable offset = 20
     BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================
   PROPERTY GET HostRawElementProvider ( _              ' VTable offset = 24
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRawElementProviderSimple_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAccessibleEx
' IID = F8B80ADA-2C44-48D0-89BE-5FF23C9CD875
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccessibleEx_INTERFACE_DEFINED)
    %IAccessibleEx_INTERFACE_DEFINED = 1

$IID_IAccessibleEx = GUID$("{F8B80ADA-2C44-48D0-89BE-5FF23C9CD875}")

INTERFACE IAccessibleEx $IID_IAccessibleEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetObjectForChild ( _                         ' VTable offset = 12
     BYVAL idChild AS LONG _                            ' __in long idChild
   ) AS IAccessibleEx                                   ' __retval_out IAccessibleEx **pRetVal
   ' =====================================================================================
   METHOD GetIAccessiblePair ( _                        ' VTable offset = 16
     BYREF ppAcc AS IAccessible _                       ' __out IAccessible **ppAcc
   , BYREF pidChild AS LONG _                           ' __out long *pidChild
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRuntimeId ( _                              ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD ConvertReturnedElement ( _                    ' VTable offset = 24
     BYVAL pIn AS IRawElementProviderSimple _           ' __in IRawElementProviderSimple *pIn
   , BYREF ppRetValOut AS IAccessibleEx _               ' __out IAccessibleEx **ppRetValOut
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IAccessibleEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawElementProviderFragmentRoot
' IID = 620CE2A5-AB8F-40A9-86CB-DE3C75599B58
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRawElementProviderFragmentRoot_INTERFACE_DEFINED)
    %IRawElementProviderFragmentRoot_INTERFACE_DEFINED = 1

$IID_IRawElementProviderFragmentRoot = GUID$("{620CE2A5-AB8F-40A9-86CB-DE3C75599B58}")

INTERFACE IRawElementProviderFragmentRoot $IID_IRawElementProviderFragmentRoot

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ElementProviderFromPoint ( _                  ' VTable offset = 12
     BYVAL x AS DOUBLE _                                ' __in double x
   , BYVAL y AS DOUBLE _                                ' __in double y
   ) AS IRawElementProviderFragment                     ' __retval_out IRawElementProviderFragment **pRetVal
   ' =====================================================================================
   METHOD GetFocus ( _                                  ' VTable offset = 16
   ) AS IRawElementProviderFragment                     ' __retval_out IRawElementProviderFragment **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRawElementProviderFragmentRoot_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawElementProviderFragment
' IID = F7063DA8-8359-439C-9297-BBC5299A7D87
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRawElementProviderFragment_INTERFACE_DEFINED)
    %IRawElementProviderFragment_INTERFACE_DEFINED = 1

$IID_IRawElementProviderFragment = GUID$("{F7063DA8-8359-439C-9297-BBC5299A7D87}")

INTERFACE IRawElementProviderFragment $IID_IRawElementProviderFragment

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Navigate ( _                                  ' VTable offset = 12
     BYVAL direction AS LONG _                          ' __in enum NavigateDirection direction
   ) AS IRawElementProviderFragment                     ' __retval_out IRawElementProviderFragment **pRetVal
   ' =====================================================================================
   METHOD GetRuntimeId ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   PROPERTY GET BoundingRectangle ( _                   ' VTable offset = 20
   ) AS UiaRect                                         ' __retval_out struct UiaRect *pRetVal
   ' =====================================================================================
   METHOD GetEmbeddedFragmentRoots ( _                  ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FragmentRoot ( _                        ' VTable offset = 32
   ) AS IRawElementProviderFragmentRoot                 ' __retval_out IRawElementProviderFragmentRoot **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRawElementProviderFragment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawElementProviderAdviseEvents
' IID = A407B27B-0F6D-4427-9292-473C7BF93258
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRawElementProviderAdviseEvents_INTERFACE_DEFINED)
    %IRawElementProviderAdviseEvents_INTERFACE_DEFINED = 1

$IID_IRawElementProviderAdviseEvents = GUID$("{A407B27B-0F6D-4427-9292-473C7BF93258}")

INTERFACE IRawElementProviderAdviseEvents $IID_IRawElementProviderAdviseEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdviseEventAdded ( _                          ' VTable offset = 12
     BYVAL eventId AS LONG _                            ' __in EVENTID eventId
   , BYVAL propertyIDs AS DWORD _                       ' __in SAFEARRAY * propertyIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseEventRemoved ( _                        ' VTable offset = 16
     BYVAL eventId AS LONG _                            ' __in EVENTID eventId
   , BYVAL propertyIDs AS DWORD _                       ' __in SAFEARRAY * propertyIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRawElementProviderAdviseEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRawElementProviderHwndOverride
' IID = 1D5DF27C-8947-4425-B8D9-79787BB460B8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRawElementProviderHwndOverride_INTERFACE_DEFINED)
    %IRawElementProviderHwndOverride_INTERFACE_DEFINED = 1

$IID_IRawElementProviderHwndOverride = GUID$("{1D5DF27C-8947-4425-B8D9-79787BB460B8}")

INTERFACE IRawElementProviderHwndOverride $IID_IRawElementProviderHwndOverride

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetOverrideProviderForHwnd ( _                ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRawElementProviderHwndOverride_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProxyProviderWinEventSink
' IID = 4FD82B78-A43E-46AC-9803-0A6969C7C183
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProxyProviderWinEventSink_INTERFACE_DEFINED)
    %IProxyProviderWinEventSink_INTERFACE_DEFINED = 1

$IID_IProxyProviderWinEventSink = GUID$("{4FD82B78-A43E-46AC-9803-0A6969C7C183}")

INTERFACE IProxyProviderWinEventSink $IID_IProxyProviderWinEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddAutomationPropertyChangedEvent ( _         ' VTable offset = 12
     BYVAL pProvider AS IRawElementProviderSimple _     ' __in IRawElementProviderSimple *pProvider
   , BYVAL id AS LONG _                                 ' __in PROPERTYID id
   , BYVAL newValue AS VARIANT _                        ' __in VARIANT newValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddAutomationEvent ( _                        ' VTable offset = 16
     BYVAL pProvider AS IRawElementProviderSimple _     ' __in IRawElementProviderSimple *pProvider
   , BYVAL id AS LONG _                                 ' __in EVENTID id
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStructureChangedEvent ( _                  ' VTable offset = 20
     BYVAL pProvider AS IRawElementProviderSimple _     ' __in IRawElementProviderSimple *pProvider
   , BYVAL structureChangeType AS LONG _                ' __in enum StructureChangeType structureChangeType
   , BYVAL runtimeId AS DWORD _                         ' __in SAFEARRAY * runtimeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProxyProviderWinEventSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProxyProviderWinEventHandler
' IID = 89592AD4-F4E0-43D5-A3B6-BAD7E111B435
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProxyProviderWinEventHandler_INTERFACE_DEFINED)
    %IProxyProviderWinEventHandler_INTERFACE_DEFINED = 1

$IID_IProxyProviderWinEventHandler = GUID$("{89592AD4-F4E0-43D5-A3B6-BAD7E111B435}")

INTERFACE IProxyProviderWinEventHandler $IID_IProxyProviderWinEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RespondToWinEvent ( _                         ' VTable offset = 12
     BYVAL idWinEvent AS DWORD _                        ' __in DWORD idWinEvent
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS LONG _                           ' __in LONG idObject
   , BYVAL idChild AS LONG _                            ' __in LONG idChild
   , BYVAL pSink AS IProxyProviderWinEventSink _        ' __in IProxyProviderWinEventSink *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProxyProviderWinEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDockProvider
' IID = 159BC72C-4AD3-485E-9637-D7052EDF0146
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDockProvider_INTERFACE_DEFINED)
    %IDockProvider_INTERFACE_DEFINED = 1

$IID_IDockProvider = GUID$("{159BC72C-4AD3-485E-9637-D7052EDF0146}")

INTERFACE IDockProvider $IID_IDockProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetDockPosition ( _                           ' VTable offset = 12
     BYVAL dockPosition AS LONG _                       ' __in enum DockPosition dockPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DockPosition ( _                        ' VTable offset = 16
   ) AS LONG                                            ' __retval_out enum DockPosition *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IDockProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IExpandCollapseProvider
' IID = D847D3A5-CAB0-4A98-8C32-ECB45C59AD24
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExpandCollapseProvider_INTERFACE_DEFINED)
    %IExpandCollapseProvider_INTERFACE_DEFINED = 1

$IID_IExpandCollapseProvider = GUID$("{D847D3A5-CAB0-4A98-8C32-ECB45C59AD24}")

INTERFACE IExpandCollapseProvider $IID_IExpandCollapseProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Collapse ( _                                  ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExpandCollapseState ( _                 ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum ExpandCollapseState *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IExpandCollapseProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGridProvider
' IID = B17D6187-0907-464B-A168-0EF17A1572B1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGridProvider_INTERFACE_DEFINED)
    %IGridProvider_INTERFACE_DEFINED = 1

$IID_IGridProvider = GUID$("{B17D6187-0907-464B-A168-0EF17A1572B1}")

INTERFACE IGridProvider $IID_IGridProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYVAL row AS LONG _                                ' __in int row
   , BYVAL column AS LONG _                             ' __in int column
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================
   PROPERTY GET RowCount ( _                            ' VTable offset = 16
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET ColumnCount ( _                         ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IGridProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IGridItemProvider
' IID = D02541F1-FB81-4D64-AE32-F520F8A6DBD1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGridItemProvider_INTERFACE_DEFINED)
    %IGridItemProvider_INTERFACE_DEFINED = 1

$IID_IGridItemProvider = GUID$("{D02541F1-FB81-4D64-AE32-F520F8A6DBD1}")

INTERFACE IGridItemProvider $IID_IGridItemProvider

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Row ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET Column ( _                              ' VTable offset = 16
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET RowSpan ( _                             ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET ColumnSpan ( _                          ' VTable offset = 24
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET ContainingGrid ( _                      ' VTable offset = 28
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IGridItemProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IInvokeProvider
' IID = 54FCB24B-E18E-47A2-B4D3-ECCBE77599A2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInvokeProvider_INTERFACE_DEFINED)
    %IInvokeProvider_INTERFACE_DEFINED = 1

$IID_IInvokeProvider = GUID$("{54FCB24B-E18E-47A2-B4D3-ECCBE77599A2}")

INTERFACE IInvokeProvider $IID_IInvokeProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IInvokeProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultipleViewProvider
' IID = 6278CAB1-B556-4A1A-B4E0-418ACC523201
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultipleViewProvider_INTERFACE_DEFINED)
    %IMultipleViewProvider_INTERFACE_DEFINED = 1

$IID_IMultipleViewProvider = GUID$("{6278CAB1-B556-4A1A-B4E0-418ACC523201}")

INTERFACE IMultipleViewProvider $IID_IMultipleViewProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetViewName ( _                               ' VTable offset = 12
     BYVAL viewId AS LONG _                             ' __in int viewId
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   METHOD SetCurrentView ( _                            ' VTable offset = 16
     BYVAL viewId AS LONG _                             ' __in int viewId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentView ( _                         ' VTable offset = 20
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   METHOD GetSupportedViews ( _                         ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IMultipleViewProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRangeValueProvider
' IID = 36DC7AEF-33E6-4691-AFE1-2BE7274B3D33
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRangeValueProvider_INTERFACE_DEFINED)
    %IRangeValueProvider_INTERFACE_DEFINED = 1

$IID_IRangeValueProvider = GUID$("{36DC7AEF-33E6-4691-AFE1-2BE7274B3D33}")

INTERFACE IRangeValueProvider $IID_IRangeValueProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 12
     BYVAL val AS DOUBLE _                              ' __in double val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 16
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET IsReadOnly ( _                          ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET Maximum ( _                             ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET Minimum ( _                             ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET LargeChange ( _                         ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET SmallChange ( _                         ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IRangeValueProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScrollItemProvider
' IID = 2360C714-4BF1-4B26-BA65-9B21316127EB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IScrollItemProvider_INTERFACE_DEFINED)
    %IScrollItemProvider_INTERFACE_DEFINED = 1

$IID_IScrollItemProvider = GUID$("{2360C714-4BF1-4B26-BA65-9B21316127EB}")

INTERFACE IScrollItemProvider $IID_IScrollItemProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ScrollIntoView ( _                            ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IScrollItemProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISelectionProvider
' IID = FB8B03AF-3BDF-48D4-BD36-1A65793BE168
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISelectionProvider_INTERFACE_DEFINED)
    %ISelectionProvider_INTERFACE_DEFINED = 1

$IID_ISelectionProvider = GUID$("{FB8B03AF-3BDF-48D4-BD36-1A65793BE168}")

INTERFACE ISelectionProvider $IID_ISelectionProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   PROPERTY GET CanSelectMultiple ( _                   ' VTable offset = 16
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET IsSelectionRequired ( _                 ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ISelectionProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScrollProvider
' IID = B38B8077-1FC3-42A5-8CAE-D40C2215055A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IScrollProvider_INTERFACE_DEFINED)
    %IScrollProvider_INTERFACE_DEFINED = 1

$IID_IScrollProvider = GUID$("{B38B8077-1FC3-42A5-8CAE-D40C2215055A}")

INTERFACE IScrollProvider $IID_IScrollProvider

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
   PROPERTY GET HorizontalScrollPercent ( _             ' VTable offset = 20
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET VerticalScrollPercent ( _               ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET HorizontalViewSize ( _                  ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET VerticalViewSize ( _                    ' VTable offset = 32
   ) AS DOUBLE                                          ' __retval_out double *pRetVal
   ' =====================================================================================
   PROPERTY GET HorizontallyScrollable ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET VerticallyScrollable ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IScrollProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISelectionItemProvider
' IID = 2ACAD808-B2D4-452D-A407-91FF1AD167B2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISelectionItemProvider_INTERFACE_DEFINED)
    %ISelectionItemProvider_INTERFACE_DEFINED = 1

$IID_ISelectionItemProvider = GUID$("{2ACAD808-B2D4-452D-A407-91FF1AD167B2}")

INTERFACE ISelectionItemProvider $IID_ISelectionItemProvider

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
   PROPERTY GET IsSelected ( _                          ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET SelectionContainer ( _                  ' VTable offset = 28
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ISelectionItemProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISynchronizedInputProvider
' IID = 29DB1A06-02CE-4CF7-9B42-565D4FAB20EE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISynchronizedInputProvider_INTERFACE_DEFINED)
    %ISynchronizedInputProvider_INTERFACE_DEFINED = 1

$IID_ISynchronizedInputProvider = GUID$("{29DB1A06-02CE-4CF7-9B42-565D4FAB20EE}")

INTERFACE ISynchronizedInputProvider $IID_ISynchronizedInputProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD StartListening ( _                            ' VTable offset = 12
      BYVAL inputType AS LONG _                         ' __in enum SynchronizedInputType inputType
   )                                                    ' void
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ISelectionItemProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITableProvider
' IID = 9C860395-97B3-490A-B52A-858CC22AF166
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITableProvider_INTERFACE_DEFINED)
    %ITableProvider_INTERFACE_DEFINED = 1

$IID_ITableProvider = GUID$("{9C860395-97B3-490A-B52A-858CC22AF166}")

INTERFACE ITableProvider $IID_ITableProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetRowHeaders ( _                             ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD GetColumnHeaders ( _                          ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   PROPERTY GET RowOrColumnMajor ( _                    ' VTable offset = 20
   ) AS LONG                                            ' __retval_out enum RowOrColumnMajor *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ITableProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITableItemProvider
' IID = B9734FA6-771F-4D78-9C90-2517999349CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITableItemProvider_INTERFACE_DEFINED)
    %ITableItemProvider_INTERFACE_DEFINED = 1

$IID_ITableItemProvider = GUID$("{B9734FA6-771F-4D78-9C90-2517999349CD}")

INTERFACE ITableItemProvider $IID_ITableItemProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetRowHeaderItems ( _                         ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD GetColumnHeaderItems ( _                      ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ITableItemProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IToggleProvider
' IID = 56D00BD0-C4F4-433C-A836-1A52A57E0892
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IToggleProvider_INTERFACE_DEFINED)
    %IToggleProvider_INTERFACE_DEFINED = 1

$IID_IToggleProvider = GUID$("{56D00BD0-C4F4-433C-A836-1A52A57E0892}")

INTERFACE IToggleProvider $IID_IToggleProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Toggle ( _                                    ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToggleState ( _                         ' VTable offset = 16
   ) AS LONG                                            ' __retval_out enum ToggleState *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IToggleProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITransformProvider
' IID = 6829DDC4-4F91-4FFA-B86F-BD3E2987CB4C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransformProvider_INTERFACE_DEFINED)
    %ITransformProvider_INTERFACE_DEFINED = 1

$IID_ITransformProvider = GUID$("{6829DDC4-4F91-4FFA-B86F-BD3E2987CB4C}")

INTERFACE ITransformProvider $IID_ITransformProvider

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
   PROPERTY GET CanMove ( _                             ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET CanResize ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET CanRotate ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ITransformProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IValueProvider
' IID = C7935180-6FB3-4201-B174-7DF73ADBF64A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IValueProvider_INTERFACE_DEFINED)
    %IValueProvider_INTERFACE_DEFINED = 1

$IID_IValueProvider = GUID$("{C7935180-6FB3-4201-B174-7DF73ADBF64A}")

INTERFACE IValueProvider $IID_IValueProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 12
     BYREF val AS WSTRINGZ _                            ' __in LPCWSTR val
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   PROPERTY GET IsReadOnly ( _                          ' VTable offset = 20
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IValueProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWindowProvider
' IID = 987DF77B-DB06-4D77-8F8A-86A9C3BB90B9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWindowProvider_INTERFACE_DEFINED)
    %IWindowProvider_INTERFACE_DEFINED = 1

$IID_IWindowProvider = GUID$("{987DF77B-DB06-4D77-8F8A-86A9C3BB90B9}")

INTERFACE IWindowProvider $IID_IWindowProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetVisualState ( _                            ' VTable offset = 12
     BYVAL state AS LONG _                              ' __in enum WindowVisualState state
   )                                                    ' void
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD WaitForInputIdle ( _                          ' VTable offset = 20
     BYVAL milliseconds AS LONG _                       ' __in int milliseconds
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET CanMaximize ( _                         ' VTable offset = 24
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET CanMinimize ( _                         ' VTable offset = 28
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET IsModal ( _                             ' VTable offset = 32
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   PROPERTY GET WindowVisualState ( _                   ' VTable offset = 36
   ) AS LONG                                            ' enum WindowVisualState *pRetVal
   ' =====================================================================================
   PROPERTY GET WindowInteractionState ( _              ' VTable offset = 40
   ) AS LONG                                            ' enum WindowVisualState *pRetVal
   ' =====================================================================================
   PROPERTY GET IsTopmost ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IWindowProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ILegacyIAccessibleProvider
' IID = E44C3566-915D-4070-99C6-047BFF5A08F5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ILegacyIAccessibleProvider_INTERFACE_DEFINED)
    %ILegacyIAccessibleProvider_INTERFACE_DEFINED = 1

$IID_ILegacyIAccessibleProvider = GUID$("{E44C3566-915D-4070-99C6-047BFF5A08F5}")

INTERFACE ILegacyIAccessibleProvider $IID_ILegacyIAccessibleProvider

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
   METHOD GetIAccessible ( _                            ' VTable offset = 24
   ) AS IAccessible                                     ' __retval_out IAccessible **ppAccessible
   ' =====================================================================================
   PROPERTY GET ChildId ( _                             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pszName
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pszValue
   ' =====================================================================================
   PROPERTY GET Description ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   PROPERTY GET Role ( _                                ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out DWORD *pdwRole
   ' =====================================================================================
   PROPERTY GET State ( _                               ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out DWORD *pdwState
   ' =====================================================================================
   PROPERTY GET Help ( _                                ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pszHelp
   ' =====================================================================================
   PROPERTY GET KeyboardShortcut ( _                    ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pszKeyboardShortcut
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pvarSelectedChildren
   ' =====================================================================================
   PROPERTY GET DefaultAction ( _                       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pszDefaultAction
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ILegacyIAccessibleProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IItemContainerProvider
' IID = E747770B-39CE-4382-AB30-D8FB3F336F24
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IItemContainerProvider_INTERFACE_DEFINED)
    %IItemContainerProvider_INTERFACE_DEFINED = 1

$IID_IItemContainerProvider = GUID$("{E747770B-39CE-4382-AB30-D8FB3F336F24}")

INTERFACE IItemContainerProvider $IID_IItemContainerProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD FindItemByProperty ( _                        ' VTable offset = 12
     BYVAL pStartAfter AS IRawElementProviderSimple _   ' __in IRawElementProviderSimple *pStartAfter
   , BYVAL propertyId AS LONG _                         ' __in PROPERTYID propertyId
   , BYVAL value AS VARIANT _                           ' __in VARIANT value
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pFound
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IItemContainerProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVirtualizedItemProvider
' IID = CB98B665-2D35-4FAC-AD35-F3C60D0C0B8B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVirtualizedItemProvider_INTERFACE_DEFINED)
    %IVirtualizedItemProvider_INTERFACE_DEFINED = 1

$IID_IVirtualizedItemProvider = GUID$("{CB98B665-2D35-4FAC-AD35-F3C60D0C0B8B}")

INTERFACE IVirtualizedItemProvider $IID_IVirtualizedItemProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Realize ( _                                   ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IVirtualizedItemProviderr_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITextRangeProvider
' IID = 5347AD7B-C355-46F8-AFF5-909033582F63
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextRangeProvider_INTERFACE_DEFINED)
    %ITextRangeProvider_INTERFACE_DEFINED = 1

$IID_ITextRangeProvider = GUID$("{5347AD7B-C355-46F8-AFF5-909033582F63}")

INTERFACE ITextRangeProvider $IID_ITextRangeProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 16
     BYVAL range AS ITextRangeProvider _                ' __in ITextRangeProvider *range
   ) AS LONG                                            ' __retval_out BOOL *pRetVal
   ' =====================================================================================
   METHOD CompareEndpoints ( _                          ' VTable offset = 20
     BYVAL endpoint AS LONG _                           ' __in enum TextPatternRangeEndpoint endpoint
   , BYVAL targetRange AS ITextRangeProvider _          ' __in ITextRangeProvider *targetRange
   , BYVAL targetEndpoint AS LONG _                     ' __in enum TextPatternRangeEndpoint targetEndpoint
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   METHOD ExpandToEnclosingUnit ( _                     ' VTable offset = 24
      BYVAL unit AS LONG _                              ' __in enum TextUnit unit
   )                                                    ' void
   ' =====================================================================================
   METHOD FindAttribute ( _                             ' VTable offset = 28
     BYVAL attributeId AS LONG _                        ' __in TEXTATTRIBUTEID attributeId
   , BYVAL val AS VARIANT _                             ' __in VARIANT val
   , BYVAL backward AS LONG _                           ' __in BOOL backward
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   METHOD FindText ( _                                  ' VTable offset = 32
     BYVAL text AS WSTRING _                            ' __in BSTR text
   , BYVAL backward AS LONG _                           ' __in BOOL backward
   , BYVAL ignoreCase AS LONG _                         ' __in BOOL ignoreCase
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   METHOD GetAttributeValue ( _                         ' VTable offset = 36
     BYVAL attributeId AS LONG _                        ' __in TEXTATTRIBUTEID attributeId
   ) AS VARIANT                                         ' __retval_out VARIANT *pRetVal
   ' =====================================================================================
   METHOD GetBoundingRectangles ( _                     ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD GetEnclosingElement ( _                       ' VTable offset = 44
   ) AS IRawElementProviderSimple                       ' __retval_out IRawElementProviderSimple **pRetVal
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 48
     BYVAL maxLength AS LONG _                          ' __in int maxLength
   ) AS WSTRING                                         ' __retval_out BSTR *pRetVal
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 52
     BYVAL unit AS LONG _                               ' __in enum TextUnit unit
   , BYVAL count AS LONG _                              ' __in int count
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   METHOD MoveEndpointByUnit ( _                        ' VTable offset = 56
     BYVAL endpoint AS LONG _                           ' __in enum TextPatternRangeEndpoint endpoint
   , BYVAL unit AS LONG _                               ' __in enum TextUnit unit
   , BYVAL count AS LONG _                              ' __in int count
   ) AS LONG                                            ' __retval_out int *pRetVal
   ' =====================================================================================
   METHOD MoveEndpointByRange ( _                       ' VTable offset = 60
     BYVAL endpoint AS LONG _                           ' __in enum TextPatternRangeEndpoint endpoint
   , BYVAL targetRange AS LONG _                        ' __in ITextRangeProvider *targetRange
   , BYVAL targetEndpoint AS LONG _                     ' __in enum TextPatternRangeEndpoint targetEndpoint
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
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ITextRangeProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITextProvider
' IID = 3589C92C-63F3-4367-99BB-ADA653B77CF2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITextProvider_INTERFACE_DEFINED)
    %ITextProvider_INTERFACE_DEFINED = 1

$IID_ITextProvider = GUID$("{3589C92C-63F3-4367-99BB-ADA653B77CF2}")

INTERFACE ITextProvider $IID_ITextProvider

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD GetVisibleRanges ( _                          ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out SAFEARRAY * *pRetVal
   ' =====================================================================================
   METHOD RangeFromChild ( _                            ' VTable offset = 20
     BYVAL childElement AS IRawElementProviderSimple _  ' __in IRawElementProviderSimple *childElement
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   METHOD RangeFromPoint ( _                            ' VTable offset = 24
     BYVAL point AS UiaPoint _                          ' __in struct UiaPoint point
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   PROPERTY GET DocumentRange ( _                       ' VTable offset = 28
   ) AS ITextRangeProvider                              ' __retval_out ITextRangeProvider **pRetVal
   ' =====================================================================================
   PROPERTY GET SupportedTextSelection ( _              ' VTable offset = 36
   ) AS LONG                                            ' __retval_out enum SupportedTextSelection *pRetVal
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __ITextProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIAutomationPatternInstance
' IID = C03A7FE4-9431-409F-BED8-AE7C2299BC8D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationPatternInstance_INTERFACE_DEFINED)
    %IUIAutomationPatternInstance_INTERFACE_DEFINED = 1

$IID_IUIAutomationPatternInstance = GUID$("{C03A7FE4-9431-409F-BED8-AE7C2299BC8D}")

INTERFACE IUIAutomationPatternInstance $IID_IUIAutomationPatternInstance

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 12
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYVAL cached AS LONG _                             ' __in BOOL cached
   , BYVAL type AS LONG _                               ' __in enum UIAutomationType type
   , BYREF pPtr AS DWORD _                              ' __out void *pPtr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CallMethod ( _                                ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pParams AS UIAutomationParameter _           ' __in const struct UIAutomationParameter *pParams
   , BYVAL cParams AS DWORD _                           ' __in UINT cParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IUIAutomationPatternInstance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIAutomationPatternHandler
' IID = D97022F3-A947-465E-8B2A-AC4315FA54E8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationPatternHandler_INTERFACE_DEFINED)
    %IUIAutomationPatternHandler_INTERFACE_DEFINED = 1

$IID_IUIAutomationPatternHandler = GUID$("{D97022F3-A947-465E-8B2A-AC4315FA54E8}")

INTERFACE IUIAutomationPatternHandler $IID_IUIAutomationPatternHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateClientWrapper ( _                       ' VTable offset = 12
     BYVAL pPatternInstance AS IUIAutomationPatternInstance _   ' __in IUIAutomationPatternInstance *pPatternInstance
   , BYREF pClientWrapper AS IUnknown _                 ' __out IUnknown **pClientWrapper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Dispatch_ ( _                                 ' VTable offset = 16
     BYVAL pTarget AS IUnknown _                        ' __in IUnknown *pTarget
   , BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF pParams AS UIAutomationParameter _           ' __in const struct UIAutomationParameter *pParams
   , BYVAL cParams AS DWORD _                           ' __in UINT cParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IUIAutomationPatternHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUIAutomationRegistrar
' IID = 8609C4EC-4A1A-4D88-A357-5A66E060E1CF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUIAutomationRegistrar_INTERFACE_DEFINED)
    %IUIAutomationRegistrar_INTERFACE_DEFINED = 1

$IID_IUIAutomationRegistrar = GUID$("{8609C4EC-4A1A-4D88-A357-5A66E060E1CF}")

INTERFACE IUIAutomationRegistrar $IID_IUIAutomationRegistrar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterProperty ( _                          ' VTable offset = 12
     BYREF property AS UIAutomationPropertyInfo _       ' __in const struct UIAutomationPropertyInfo *property
   , BYREF propertyId AS LONG _                         ' __out PROPERTYID *propertyId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterEvent ( _                             ' VTable offset = 16
     BYREF event AS UIAutomationEventInfo _             ' __in const struct UIAutomationEventInfo *event
   , BYREF eventId AS LONG _                            ' __out EVENTID *eventId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterPattern ( _                           ' VTable offset = 20
     BYREF pattern AS UIAutomationPatternInfo _         ' __in const struct UIAutomationPatternInfo *pattern
   , BYREF pPatternId AS LONG _                         ' __out PATTERNID *pPatternId
   , BYREF pPatternAvailablePropertyId AS LONG _        ' __out PROPERTYID *pPatternAvailablePropertyId
   , BYVAL propertyIdCount AS DWORD _                   ' __in UINT propertyIdCount
   , BYREF pPropertyIds AS LONG _                       ' __out PROPERTYID *pPropertyIds
   , BYVAL eventIdCount AS DWORD _                      ' __in UINT eventIdCount
   , BYREF pEventIds AS LONG _                          ' __out EVENTID *pEventIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IUIAutomationRegistrar_INTERFACE_DEFINED__ */

$CLSID_CUIAutomationRegistrar = GUID$("{6E29FABF-9977-42D1-8D0E-CA7E61AD87E6}")
