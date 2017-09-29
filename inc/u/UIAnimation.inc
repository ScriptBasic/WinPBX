' ########################################################################################
' Microsoft Windows
' File: UIAnimation.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: UIAnimation
' Version: 1.0, Locale ID = 0
' Documentation string: UIAnimation 1.0 Type Library
' Library GUID: {44CA24DB-1A92-4149-BAB5-FB14D64B401E}
' ########################################################################################

#INCLUDE THIS ONCE
%UIANIMARION_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "unknwn.inc"

' /* Type library */
' uuid(44CA24DB-1A92-4149-BAB5-FB14D64B401E),
' version(1.0),
' helpstring("UIAnimation 1.0 Type Library")
$LIBID_UIAnimation = GUID$("{44CA24DB-1A92-4149-BAB5-FB14D64B401E}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_UIAnimationManager = GUID$("{4C1FC63A-695C-47E8-A339-1A194BE3D0B8}")
$CLSID_UIAnimationTimer = GUID$("{BFCD4A0C-06B6-4384-B768-0DAA792C380E}")
$CLSID_UIAnimationTransitionFactory = GUID$("{8A9B1CDD-FCD7-419C-8B44-42FD17DB1887}")
$CLSID_UIAnimationTransitionLibrary = GUID$("{1D6322AD-AA85-4EF5-A828-86D71067D145}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IUIAnimationInterpolator = GUID$("{7815CBBA-DDF7-478C-A46C-7B6C738B7978}")
$IID_IUIAnimationManager = GUID$("{9169896C-AC8D-4E7D-94E5-67FA4DC2F2E8}")
$IID_IUIAnimationManagerEventHandler = GUID$("{783321ED-78A3-4366-B574-6AF607A64788}")
$IID_IUIAnimationPriorityComparison = GUID$("{83FA9B74-5F86-4618-BC6A-A2FAC19B3F44}")
$IID_IUIAnimationStoryboard = GUID$("{A8FF128F-9BF9-4AF1-9E67-E5E410DEFB84}")
$IID_IUIAnimationStoryboardEventHandler = GUID$("{3D5C9008-EC7C-4364-9F8A-9AF3C58CBAE6}")
$IID_IUIAnimationTimer = GUID$("{6B0EFAD1-A053-41D6-9085-33A689144665}")
$IID_IUIAnimationTimerClientEventHandler = GUID$("{BEDB4DB6-94FA-4BFB-A47F-EF2D9E408C25}")
$IID_IUIAnimationTimerEventHandler = GUID$("{274A7DEA-D771-4095-ABBD-8DF7ABD23CE3}")
$IID_IUIAnimationTimerUpdateHandler = GUID$("{195509B7-5D5E-4E3E-B278-EE3759B367AD}")
$IID_IUIAnimationTransition = GUID$("{DC6CE252-F731-41CF-B610-614B6CA049AD}")
$IID_IUIAnimationTransitionFactory = GUID$("{FCD91E03-3E3B-45AD-BBB1-6DFC8153743D}")
$IID_IUIAnimationTransitionLibrary = GUID$("{CA5A14B1-D24F-48B8-8FE4-C78169BA954E}")
$IID_IUIAnimationVariable = GUID$("{8CEEB155-2849-4CE5-9448-91FF70E1E4D9}")
$IID_IUIAnimationVariableChangeHandler = GUID$("{6358B7BA-87D2-42D5-BF71-82E919DD5862}")
$IID_IUIAnimationVariableIntegerChangeHandler = GUID$("{BB3E1550-356E-44B0-99DA-85AC6017865E}")

'typedef DOUBLE UI_ANIMATION_SECONDS;

%UI_ANIMATION_SECONDS_EVENTUALLY       = -1

' enum UI_ANIMATION_UPDATE_RESULT
%UI_ANIMATION_UPDATE_NO_CHANGE         = 0
%UI_ANIMATION_UPDATE_VARIABLES_CHANGED = 1

' enum UI_ANIMATION_MANAGER_STATUS
%UI_ANIMATION_MANAGER_IDLE             = 0
%UI_ANIMATION_MANAGER_BUSY             = 1

' enum UI_ANIMATION_MODE
%UI_ANIMATION_MODE_DISABLED            = 0
%UI_ANIMATION_MODE_SYSTEM_DEFAULT      = 1
%UI_ANIMATION_MODE_ENABLED             = 2


' ########################################################################################
' IUIAnimationManager interface
' IID = 9169896C-AC8D-4E7D-94E5-67FA4DC2F2E8
' Inherited interface = IUnknown
' Defines the animation manager, which provides a central interface for creating and
' managing UI animations.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationManager_INTERFACE_DEFINED)
    %IUIAnimationManager_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationManager $IID_IUIAnimationManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateAnimationVariable ( _                   ' VTable offset = 12
     BYVAL initialValue AS DOUBLE _                     ' __in DOUBLE initialValue
   ) AS IUIAnimationVariable                            ' __retval_out IUIAnimationVariable **variable
   ' =====================================================================================
   METHOD ScheduleTransition ( _                        ' VTable offset = 16
     BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL transition AS IUIAnimationTransition _       ' __in IUIAnimationTransition *transition
   , BYVAL timeNow AS DOUBLE _                          ' __in UI_ANIMATION_SECONDS timeNow
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD CreateStoryboard ( _                          ' VTable offset = 20
   ) AS IUIAnimationStoryboard                          ' __retval_out IUIAnimationStoryboard **storyboard
   ' =====================================================================================
   METHOD FinishAllStoryboards ( _                      ' VTable offset = 24
     BYVAL completionDeadline AS DOUBLE _               ' __in UI_ANIMATION_SECONDS completionDeadline
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD AbandonAllStoryboards ( _                     ' VTable offset = 28
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 32
     BYVAL timeNow AS DOUBLE _                          ' __in UI_ANIMATION_SECONDS timeNow
   , OPTIONAL BYREF updateResult AS LONG _              ' __out_opt UI_ANIMATION_UPDATE_RESULT *updateResult [defaultvalue = 0]
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetVariableFromTag ( _                        ' VTable offset = 36
     BYVAL object AS IUnknown _                         ' __in_opt IUnknown *object
   , BYVAL id AS DWORD _                                ' __in UINT32 id
   ) AS IUIAnimationVariable                            ' __retval_out IUIAnimationVariable **variable
   ' =====================================================================================
   METHOD GetStoryboardFromTag ( _                      ' VTable offset = 40
     BYVAL object AS IUnknown _                         ' __in_opt IUnknown *object
   , BYVAL id AS DWORD _                                ' __in UINT32 id
   ) AS IUIAnimationStoryboard                          ' __retval_out IUIAnimationStoryboard **storyboard
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' __retval_out UI_ANIMATION_MANAGER_STATUS *status
   ' =====================================================================================
   METHOD SetAnimationMode ( _                          ' VTable offset = 48
     BYVAL mode AS LONG _                               ' __in UI_ANIMATION_MODE mode
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 52
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 56
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetManagerEventHandler ( _                    ' VTable offset = 60
     OPTIONAL BYVAL handler AS IUIAnimationManagerEventHandler _ ' __in_opt IUIAnimationManagerEventHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetCancelPriorityComparison ( _               ' VTable offset = 64
     OPTIONAL BYVAL comparison AS IUIAnimationPriorityComparison _ ' __in_opt IUIAnimationPriorityComparison *comparison
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetTrimPriorityComparison ( _                 ' VTable offset = 68
     OPTIONAL BYVAL comparison AS IUIAnimationPriorityComparison _ ' __in_opt IUIAnimationPriorityComparison *comparison
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetCompressPriorityComparison ( _             ' VTable offset = 72
     OPTIONAL BYVAL comparison AS IUIAnimationPriorityComparison _ ' __in_opt IUIAnimationPriorityComparison *comparison
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetConcludePriorityComparison ( _             ' VTable offset = 76
     OPTIONAL BYVAL comparison AS IUIAnimationPriorityComparison _ ' __in_opt IUIAnimationPriorityComparison *comparison
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultLongestAcceptableDelay ( _          ' VTable offset = 80
     BYVAL delay AS DOUBLE _                            ' __in UI_ANIMATION_SECONDS delay
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 84
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationManager_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_ROUNDING_MODE
%UI_ANIMATION_ROUNDING_NEAREST = 0
%UI_ANIMATION_ROUNDING_FLOOR   = 1
%UI_ANIMATION_ROUNDING_CEILING = 2

' ########################################################################################
' IUIAnimationVariable interface
' IID = 8CEEB155-2849-4ce5-9448-91FF70E1E4D9
' Inherited interface = IUnknown
' Defines an animation variable, which represents a value that can be animated.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationVariable_INTERFACE_DEFINED)
    %IUIAnimationVariable_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationVariable $IID_IUIAnimationVariable

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 12
   ) AS DOUBLE                                          ' __retval_out DOUBLE *value
   ' =====================================================================================
   METHOD GetFinalValue ( _                             ' VTable offset = 16
   ) AS DOUBLE                                          ' __retval_out DOUBLE *finalValue
   ' =====================================================================================
   METHOD GetPreviousValue ( _                          ' VTable offset = 20
   ) AS DOUBLE                                          ' __retval_out DOUBLE *previousValue
   ' =====================================================================================
   METHOD GetIntegerValue ( _                           ' VTable offset = 24
   ) AS LONG                                            ' __retval_out INT32 *value
   ' =====================================================================================
   METHOD GetFinalIntegerValue ( _                      ' VTable offset = 28
   ) AS LONG                                            ' __retval_out INT32 *finalValue
   ' =====================================================================================
   METHOD GetPreviousIntegerValue ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out INT32 *previousValue
   ' =====================================================================================
   METHOD GetCurrentStoryboard ( _                      ' VTable offset = 36
   ) AS IUIAnimationStoryboard                          ' __retval_out IUIAnimationStoryboard **storyboard
   ' =====================================================================================
   METHOD SetLowerBound ( _                             ' VTable offset = 40
     BYREF bound AS DOUBLE _                            ' __in DOUBLE bound
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetUpperBound ( _                             ' VTable offset = 44
     BYREF bound AS DOUBLE _                            ' __in DOUBLE bound
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetRoundingMode ( _                           ' VTable offset = 48
     BYVAL mode AS LONG _                               ' __in UI_ANIMATION_ROUNDING_MODE mode
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetTag ( _                                    ' VTable offset = 52
     BYVAL object AS IUnknown _                         ' __in_opt IUnknown *object
   , BYVAL id AS DWORD _                                ' __in UINT32 id
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 56
     OPTIONAL BYREF object AS IUnknown _                ' __out_opt IUnknown **object
   , OPTIONAL BYREF id AS DWORD _                       ' __out_opt UINT32 *id
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetVariableChangeHandler ( _                  ' VTable offset = 60
     OPTIONAL BYVAL handler AS IUIAnimationVariableChangeHandler _ ' __in_opt IUIAnimationVariableChangeHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetVariableIntegerChangeHandler ( _           ' VTable offset = 64
     OPTIONAL BYVAL handler AS IUIAnimationVariableIntegerChangeHandler _ ' __in_opt IUIAnimationVariableIntegerChangeHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationVariable_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_STORYBOARD_STATUS
%UI_ANIMATION_STORYBOARD_BUILDING              = 0
%UI_ANIMATION_STORYBOARD_SCHEDULED             = 1
%UI_ANIMATION_STORYBOARD_CANCELLED             = 2
%UI_ANIMATION_STORYBOARD_PLAYING               = 3
%UI_ANIMATION_STORYBOARD_TRUNCATED             = 4
%UI_ANIMATION_STORYBOARD_FINISHED              = 5
%UI_ANIMATION_STORYBOARD_READY                 = 6
%UI_ANIMATION_STORYBOARD_INSUFFICIENT_PRIORITY = 7

' enum UI_ANIMATION_SCHEDULING_RESULT
%UI_ANIMATION_SCHEDULING_UNEXPECTED_FAILURE    = 0
%UI_ANIMATION_SCHEDULING_INSUFFICIENT_PRIORITY = 1
%UI_ANIMATION_SCHEDULING_ALREADY_SCHEDULED     = 2
%UI_ANIMATION_SCHEDULING_SUCCEEDED             = 3
%UI_ANIMATION_SCHEDULING_DEFERRED              = 4

'typedef struct __MIDL___MIDL_itf_UIAnimation_0000_0002_0003
'    {
'    int _;
'    }    *UI_ANIMATION_KEYFRAME;

' Defines a keyframe, which represents a time offset within a storyboard.
' This structure should be treated as a handle. It is returned as an output parameter by
' some methods and should be used only as a parameter passed back to other methods as an
' input parameter.
' UI_ANIMATION_KEYFRAME_STORYBOARD_START represents the implicit keyframe at the start of
' every storyboard.

TYPE UI_ANIMATION_KEYFRAME
   m_ AS LONG   ' int
END TYPE

'#define   UI_ANIMATION_KEYFRAME_STORYBOARD_START   ( ( UI_ANIMATION_KEYFRAME  )-1 )
%UI_ANIMATION_KEYFRAME_STORYBOARD_START = -1

%UI_ANIMATION_REPEAT_INDEFINITELY = -1

' ########################################################################################
' IUIAnimationStoryboard interface
' IID = A8FF128F-9BF9-4AF1-9E67-E5E410DEFB84
' Inherited interface = IUnknown
' Defines a storyboard, which combines animation variables and transitions to define an animation.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationStoryboard_INTERFACE_DEFINED)
    %IUIAnimationStoryboard_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationStoryboard $IID_IUIAnimationStoryboard

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AddTransition ( _                             ' VTable offset = 12
     BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL transition AS IUIAnimationTransition _       ' __in IUIAnimationTransition *transition
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD AddKeyframeAtOffset ( _                       ' VTable offset = 16
     BYVAL existingKeyframe AS LONG _                   ' __in UI_ANIMATION_KEYFRAME existingKeyframe
   , BYVAL offset AS DOUBLE _                           ' __in UI_ANIMATION_SECONDS offset
   ) AS LONG                                            ' __retval_out UI_ANIMATION_KEYFRAME *keyframe
   ' =====================================================================================
   METHOD AddKeyframeAfterTransition ( _                ' VTable offset = 20
     BYVAL transition AS IUIAnimationTransition _       ' __in IUIAnimationTransition *transition
   ) AS LONG                                            ' __retval_out UI_ANIMATION_KEYFRAME *keyframe
   ' =====================================================================================
   METHOD AddTransitionAtKeyframe ( _                   ' VTable offset = 24
     BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL transition AS IUIAnimationTransition _       ' __in IUIAnimationTransition *transition
   , BYVAL startKeyframe AS LONG _                      ' __in UI_ANIMATION_KEYFRAME startKeyframe
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD AddTransitionBetweenKeyframes ( _             ' VTable offset = 28
     BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL transition AS IUIAnimationTransition _       ' __in IUIAnimationTransition *transition
   , BYVAL startKeyframe AS LONG _                      ' __in UI_ANIMATION_KEYFRAME startKeyframe
   , BYVAL endKeyframe AS LONG _                        ' __in UI_ANIMATION_KEYFRAME endKeyframe
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD RepeatBetweenKeyframes ( _                    ' VTable offset = 32
     BYVAL startKeyframe AS LONG _                      ' __in UI_ANIMATION_KEYFRAME startKeyframe
   , BYVAL endKeyframe AS LONG _                        ' __in UI_ANIMATION_KEYFRAME endKeyframe
   , BYVAL repetitionCount AS LONG _                    ' __in INT32 repetitionCount
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD HoldVariable ( _                              ' VTable offset = 36
     BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetLongestAcceptableDelay ( _                 ' VTable offset = 40
     BYVAL delay AS DOUBLE _                            ' __in UI_ANIMATION_SECONDS delay
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Schedule ( _                                  ' VTable offset = 44
     BYVAL timeNow AS DOUBLE _                          ' __in UI_ANIMATION_SECONDS timeNow
   , OPTIONAL BYREF schedulingResult AS LONG _          ' __out_opt UI_ANIMATION_SCHEDULING_RESULT *schedulingResult [defaultvalue = 0]
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Conclude ( _                                  ' VTable offset = 48
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Finish ( _                                    ' VTable offset = 52
     BYVAL completionDeadline AS DOUBLE _               ' __in UI_ANIMATION_SECONDS completionDeadline
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Abandon ( _                                   ' VTable offset = 56
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetTag ( _                                    ' VTable offset = 60
     BYVAL object AS IUnknown _                         ' __in_opt IUnknown *object
   , BYVAL id AS DWORD _                                ' __in UINT32 id
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetTag ( _                                    ' VTable offset = 64
     OPTIONAL BYREF object AS IUnknown _                ' __out_opt IUnknown **object
   , OPTIONAL BYREF id AS DWORD _                       ' __out_opt UINT32 *id
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 68
   ) AS LONG                                            ' __retval_out UI_ANIMATION_MANAGER_STATUS *status
   ' =====================================================================================
   METHOD GetElapsedTime ( _                            ' VTable offset = 72
     BYREF elapsedTime AS DOUBLE _                      ' __out UI_ANIMATION_SECONDS *elapsedTime
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetStoryboardEventHandler ( _                 ' VTable offset = 76
     OPTIONAL BYVAL handler AS IUIAnimationStoryboardEventHandler _ '__in_opt IUIAnimationStoryboardEventHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationStoryboard_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationTransition interface
' IID = DC6CE252-F731-41CF-B610-614B6CA049AD
' Inherited interface = IUnknown
' Defines a transition, which determines how an animation variable changes over time.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTransition_INTERFACE_DEFINED)
    %IUIAnimationTransition_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTransition $IID_IUIAnimationTransition

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetInitialValue ( _                           ' VTable offset = 12
     BYVAL value AS DOUBLE _                            ' __in DOUBLE value
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetInitialVelocity ( _                        ' VTable offset = 16
     BYVAL velocity AS DOUBLE _                         ' __in DOUBLE velocity
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD IsDurationKnown ( _                           ' VTable offset = 20
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 24
   ) AS LONG                                            ' __retval_out UI_ANIMATION_SECONDS *duration
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTransition_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationManagerEventHandler interface
' IID = 783321ED-78A3-4366-B574-6AF607A64788
' Inherited interface = IUnknown
' Client applications implement an IUIAnimationManagerEventHandler handler to receive
' status updates from an animation manager. Use IUIAnimationManager.SetManagerEventHandler
' to set this handler.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationManagerEventHandler_INTERFACE_DEFINED)
    %IUIAnimationManagerEventHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationManagerEventHandler $IID_IUIAnimationManagerEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnManagerStatusChanged ( _                    ' VTable offset = 12
     BYVAL newStatus AS LONG _                          ' __in UI_ANIMATION_MANAGER_STATUS newStatus
   , BYVAL previousStatus AS LONG _                     ' __in UI_ANIMATION_MANAGER_STATUS previousStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationManagerEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationVariableChangeHandler interface
' IID = 6358B7BA-87D2-42D5-BF71-82E919DD5862
' Inherited interface = IUnknown
' Client applications implement an IUIAnimationVariableChangeHandler handler to receive
' notifications when the value of an animation variable changes. To set this handler for
' an animation variable, use IUIAnimationVariable.SetVariableChangeHandler.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationVariableChangeHandler_INTERFACE_DEFINED)
    %IUIAnimationVariableChangeHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationVariableChangeHandler $IID_IUIAnimationVariableChangeHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnValueChanged ( _                            ' VTable offset = 12
     BYVAL storyboard AS IUIAnimationStoryboard _       ' __in IUIAnimationStoryboard *storyboard
   , BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL newValue AS DOUBLE _                         ' __in DOUBLE newValue
   , BYVAL previousValue AS DOUBLE _                    ' __in DOUBLE previousValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationVariableChangeHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationVariableIntegerChangeHandler interface
' IID = BB3E1550-356E-44B0-99DA-85AC6017865E
' Inherited interface = IUnknown
' Client applications implement an IUIAnimationVariableIntegerChangeHandler handler to
' receive notifications when the value of an animation variable changes. To set this
' handler for an animation variable, use IUIAnimationVariable.SetVariableIntegerChangeHandler.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationVariableIntegerChangeHandler_INTERFACE_DEFINED)
    %IUIAnimationVariableIntegerChangeHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationVariableIntegerChangeHandler $IID_IUIAnimationVariableIntegerChangeHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnIntegerValueChanged ( _                     ' VTable offset = 12
     BYVAL storyboard AS IUIAnimationStoryboard _       ' __in IUIAnimationStoryboard *storyboard
   , BYVAL variable AS IUIAnimationVariable _           ' __in IUIAnimationVariable *variable
   , BYVAL newValue AS LONG _                           ' __in INT32 newValue
   , BYVAL previousValue AS LONG _                      ' __in INT32 previousValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationVariableIntegerChangeHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationStoryboardEventHandler interface
' IID = 3D5C9008-EC7C-4364-9F8A-9AF3C58CBAE6
' Inherited interface = IUnknown
' Client applications implement an IUIAnimationStoryboardEventHandler handler to receive
' status and update events for a storyboard. Use IUIAnimationStoryboard.SetStoryboardEventHandler
' to set this handler for a storyboard.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationStoryboardEventHandler_INTERFACE_DEFINED)
    %IUIAnimationStoryboardEventHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationStoryboardEventHandler $IID_IUIAnimationStoryboardEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStoryboardStatusChanged ( _                 ' VTable offset = 12
     BYVAL storyboard AS IUIAnimationStoryboard _       ' __in IUIAnimationStoryboard *storyboard
   , BYVAL newStatus AS LONG _                          ' __in UI_ANIMATION_STORYBOARD_STATUS newStatus
   , BYVAL previousStatus AS LONG _                     ' __in UI_ANIMATION_STORYBOARD_STATUS previousStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStoryboardUpdated ( _                       ' VTable offset = 16
     BYVAL storyboard AS IUIAnimationStoryboard _       ' __in IUIAnimationStoryboard *storyboard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationStoryboardEventHandler_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_PRIORITY_EFFECT
%UI_ANIMATION_PRIORITY_EFFECT_FAILURE = 0
%UI_ANIMATION_PRIORITY_EFFECT_DELAY   = 1

' ########################################################################################
' IUIAnimationPriorityComparison interface
' IID = 83FA9B74-5F86-4618-BC6A-A2FAC19B3F44
' Inherited interface = IUnknown
' Client applications implement one or more IUIAnimationPriorityComparison handlers to
' define how scheduling conflicts are resolved. To register these handlers, use
' IUIAnimationManager.SetCancelPriorityComparison, IUIAnimationManager.SetCompressPriorityComparison,
' IUIAnimationManager.SetConcludePriorityComparison, and/or IUIAnimationManager.SetTrimPriorityComparison.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationPriorityComparison_INTERFACE_DEFINED)
    %IUIAnimationPriorityComparison_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationPriorityComparison $IID_IUIAnimationPriorityComparison

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HasPriority ( _                               ' VTable offset = 12
     BYVAL scheduledStoryboard AS IUIAnimationStoryboard _ ' __in IUIAnimationStoryboard *scheduledStoryboard
   , BYVAL newStoryboard AS IUIAnimationStoryboard _    ' __in IUIAnimationStoryboard *newStoryboard
   , BYVAL priorityEffect AS LONG _                     ' __in UI_ANIMATION_PRIORITY_EFFECT priorityEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationPriorityComparison_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_SLOPE
%UI_ANIMATION_SLOPE_INCREASING = 0
%UI_ANIMATION_SLOPE_DECREASING = 1

' ########################################################################################
' IUIAnimationTransitionLibrary interface
' IID = CA5A14B1-D24F-48B8-8FE4-C78169BA954E
' Inherited interface = IUnknown
' Defines a library of standard transitions.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTransitionLibrary_INTERFACE_DEFINED)
    %IUIAnimationTransitionLibrary_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTransitionLibrary $IID_IUIAnimationTransitionLibrary

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateInstantaneousTransition ( _             ' VTable offset = 12
     BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateConstantTransition ( _                  ' VTable offset = 16
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateDiscreteTransition ( _                  ' VTable offset = 20
     BYVAL delay AS DOUBLE _                            ' __in UI_ANIMATION_SECONDS delay
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   , BYVAL hold AS DOUBLE _                             ' __in UI_ANIMATION_SECONDS hold
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateLinearTransition ( _                    ' VTable offset = 24
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateLinearTransitionFromSpeed ( _           ' VTable offset = 28
     BYVAL speed AS DOUBLE _                            ' __in DOUBLE speed
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateSinusoidalTransitionFromVelocity ( _    ' VTable offset = 32
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   , BYVAL period AS DOUBLE _                           ' __in UI_ANIMATION_SECONDS period
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateSinusoidalTransitionFromRange ( _       ' VTable offset = 36
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   , BYVAL minimumValue AS DOUBLE _                     ' __in DOUBLE minimumValue
   , BYVAL maximumValue AS DOUBLE _                     ' __in DOUBLE maximumValue
   , BYVAL period AS DOUBLE _                           ' __in UI_ANIMATION_SECONDS period
   , BYVAL slope AS LONG _                              ' __in UI_ANIMATION_SLOPE slope
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateAccelerateDecelerateTransition ( _      ' VTable offset = 40
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   , BYVAL accelerationRatio AS DOUBLE _                ' __in DOUBLE accelerationRatio
   , BYVAL decelerationRatio AS DOUBLE _                ' __in DOUBLE decelerationRatio
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateReversalTransition ( _                  ' VTable offset = 44
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateCubicTransition ( _                     ' VTable offset = 48
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   , BYVAL finalVelocity AS DOUBLE _                    ' __in DOUBLE finalVelocity
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateSmoothStopTransition ( _                ' VTable offset = 52
     BYVAL maximumDuration AS DOUBLE _                  ' __in UI_ANIMATION_SECONDS maximumDuration
   , BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================
   METHOD CreateParabolicTransitionFromAcceleration ( _ ' VTable offset = 56
     BYVAL finalValue AS DOUBLE _                       ' __in DOUBLE finalValue
   , BYVAL finalVelocity AS DOUBLE _                    ' __in DOUBLE finalVelocity
   , BYVAL acceleration AS DOUBLE _                     ' __in DOUBLE acceleration
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTransitionLibrary_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_DEPENDENCIES
%UI_ANIMATION_DEPENDENCY_NONE                = 0
%UI_ANIMATION_DEPENDENCY_INTERMEDIATE_VALUES = &H1
%UI_ANIMATION_DEPENDENCY_FINAL_VALUE         = &H2
%UI_ANIMATION_DEPENDENCY_FINAL_VELOCITY      = &H4
%UI_ANIMATION_DEPENDENCY_DURATION            = &H8

'DEFINE_ENUM_FLAG_OPERATORS(UI_ANIMATION_DEPENDENCIES);

' ########################################################################################
' IUIAnimationInterpolator interface
' IID = 7815CBBA-DDF7-478C-A46C-7B6C738B7978
' Inherited interface = IUnknown
' Defines methods for creating a custom interpolator.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationInterpolator_INTERFACE_DEFINED)
    %IUIAnimationInterpolator_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationInterpolator $IID_IUIAnimationInterpolator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetInitialValueAndVelocity ( _                ' VTable offset = 12
     BYVAL initialValue AS DOUBLE _                     ' __in DOUBLE initialValue
   , BYVAL initialVelocity AS DOUBLE _                  ' __in DOUBLE initialVelocity
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetDuration ( _                               ' VTable offset = 16
     BYVAL duration AS DOUBLE _                         ' __in UI_ANIMATION_SECONDS duration
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 20
   ) AS DOUBLE                                          ' __retval_out UI_ANIMATION_SECONDS *duration
   ' =====================================================================================
   METHOD GetFinalValue ( _                             ' VTable offset = 24
   ) AS DOUBLE                                          ' __retval_out DOUBLE *value
   ' =====================================================================================
   METHOD InterpolateValue ( _                          ' VTable offset = 28
     BYVAL offset AS DOUBLE _                           ' __in UI_ANIMATION_SECONDS offset
   ) AS DOUBLE                                          ' __retval_out DOUBLE *value
   ' =====================================================================================
   METHOD InterpolateVelocity ( _                       ' VTable offset = 32
     BYVAL offset AS DOUBLE _                           ' __in UI_ANIMATION_SECONDS offset
   ) AS DOUBLE                                          ' __retval_out DOUBLE *velocity
   ' =====================================================================================
   METHOD GetDependencies ( _                           ' VTable offset = 36
     BYREF initialValueDependencies AS LONG _           ' __out UI_ANIMATION_DEPENDENCIES *initialValueDependencies
   , BYREF initialVelocityDependencies AS LONG _        ' __out UI_ANIMATION_DEPENDENCIES *initialVelocityDependencies
   , BYREF durationDependencies AS LONG _               ' __out UI_ANIMATION_DEPENDENCIES *durationDependencies
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationInterpolator_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationTransitionFactory interface
' IID = FCD91E03-3E3B-45AD-BBB1-6DFC8153743D
' Inherited interface = IUnknown
' Defines methods for creating transitions from custom interpolators.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTransitionFactory_INTERFACE_DEFINED)
    %IUIAnimationTransitionFactory_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTransitionFactory $IID_IUIAnimationTransitionFactory

   INHERIT IAutomation

   ' =====================================================================================
   METHOD CreateTransition ( _                          ' VTable offset = 12
     BYVAL interpolator AS IUIAnimationInterpolator _   ' __in IUIAnimationInterpolator *interpolator
   ) AS IUIAnimationTransition                          ' __retval_out IUIAnimationTransition **transition
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTransitionFactory_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_IDLE_BEHAVIOR
%UI_ANIMATION_IDLE_BEHAVIOR_CONTINUE = 0
%UI_ANIMATION_IDLE_BEHAVIOR_DISABLE  = 1

' ########################################################################################
' IUIAnimationTimer interface
' IID = 6B0EFAD1-A053-41D6-9085-33A689144665
' Inherited interface = IUnknown
' Defines an animation timer, which provides services for managing animation timing.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTimer_INTERFACE_DEFINED)
    %IUIAnimationTimer_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTimer $IID_IUIAnimationTimer

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetTimerUpdateHandler ( _                     ' VTable offset = 12
     BYVAL updateHandler AS IUIAnimationTimerUpdateHandler _ ' __in_opt IUIAnimationTimerUpdateHandler *updateHandler
   , BYVAL idleBehavior AS LONG _                       ' __in UI_ANIMATION_IDLE_BEHAVIOR idleBehavior
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetTimerEventHandler ( _                      ' VTable offset = 16
     OPTIONAL BYVAL handler AS IUIAnimationTimerEventHandler _   ' __in_opt IUIAnimationTimerEventHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 20
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD Disable ( _                                   ' VTable offset = 24
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD IsEnabled ( _                                 ' VTable offset = 28
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 32
     BYREF seconds AS DOUBLE _                          ' __out UI_ANIMATION_SECONDS *seconds
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD SetFrameRateThreshold ( _                     ' VTable offset = 36
     BYVAL framesPerSecond AS DWORD _                   ' __in UINT32 framesPerSecond
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTimer_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationTimerUpdateHandler interface
' IID = 195509B7-5D5E-4E3E-B278-EE3759B367AD
' Inherited interface = IUnknown
' Defines methods for handling timing update events.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTimerUpdateHandler_INTERFACE_DEFINED)
    %IUIAnimationTimerUpdateHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTimerUpdateHandler $IID_IUIAnimationTimerUpdateHandler

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnUpdate ( _                                  ' VTable offset = 12
     BYVAL timeNow AS DOUBLE _                          ' __in UI_ANIMATION_SECONDS timeNow
   ) AS LONG                                            ' __retval_out UI_ANIMATION_UPDATE_RESULT *result
   ' =====================================================================================
   METHOD SetTimerClientEventHandler ( _                ' VTable offset = 16
     BYVAL handler AS IUIAnimationTimerClientEventHandler _ ' __in IUIAnimationTimerClientEventHandler *handler
   )                                                    ' HRESULT
   ' =====================================================================================
   METHOD ClearTimerClientEventHandler ( _              ' VTable offset = 20
   )                                                    ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTimerUpdateHandler_INTERFACE_DEFINED__ */

' enum UI_ANIMATION_TIMER_CLIENT_STATUS
%UI_ANIMATION_TIMER_CLIENT_IDLE = 0
%UI_ANIMATION_TIMER_CLIENT_BUSY = 1

' ########################################################################################
' IUIAnimationTimerClientEventHandler interface
' IID = BEDB4DB6-94FA-4BFB-A47F-EF2D9E408C25
' Inherited interface = IUnknown
' Client applications generally do not need to implement this interface unless they are
' creating a timer component similar to IUIAnimationTimer.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTimerClientEventHandler_INTERFACE_DEFINED)
    %IUIAnimationTimerClientEventHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTimerClientEventHandler $IID_IUIAnimationTimerClientEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTimerClientStatusChanged ( _                ' VTable offset = 12
     BYVAL newStatus AS LONG _                          ' __in UI_ANIMATION_TIMER_CLIENT_STATUS newStatus
   , BYVAL previousStatus AS LONG _                     ' __in UI_ANIMATION_TIMER_CLIENT_STATUS previousStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTimerClientEventHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' IUIAnimationTimerEventHandler interface
' IID = 274A7DEA-D771-4095-ABBD-8DF7ABD23CE3
' Inherited interface = IUnknown
' Client applications implement an IUIAnimationTimerEventHandler handler to receive timer
' events. Use IUIAnimationTimer.SetTimerEventHandler to set this handler.
' ########################################################################################

#IF NOT %DEF(%IUIAnimationTimerEventHandler_INTERFACE_DEFINED)
    %IUIAnimationTimerEventHandler_INTERFACE_DEFINED = 1

INTERFACE IUIAnimationTimerEventHandler $IID_IUIAnimationTimerEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnPreUpdate ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPostUpdate ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRenderingTooSlow ( _                        ' VTable offset = 20
     BYVAL framesPerSecond AS DWORD _                   ' __in UINT32 framesPerSecond
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUIAnimationTimerEventHandler_INTERFACE_DEFINED__ */
