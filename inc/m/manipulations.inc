' ########################################################################################
' Microsoft Windows
' File: manipulations.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: ManipulationsLib
' Version: 1.0, Locale ID = 0
' Documentation string: Manipulations Library 1.0
' Library GUID: {935610B3-6F81-450F-85D5-42D3D26C5C11}
' ########################################################################################

#INCLUDE THIS ONCE
%MANIPULATIONS_INC = 1

$LIBID_ManipulationsLib = GUID$("{935610B3-6F81-450F-85D5-42D3D26C5C11}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_InertiaProcessor = GUID$("{ABB27087-4CE0-4E58-A0CB-E24DF96814BE}")
$CLSID_ManipulationProcessor = GUID$("{597D4FB0-47FD-4AFF-89B9-C6CFAE8CF08E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IInertiaProcessor = GUID$("{18B00C6D-C5EE-41B1-90A9-9D4A929095AD}")
$IID_IManipulationProcessor = GUID$("{A22AC519-8300-48A0-BEF4-F1BE8737DBA4}")
$IID__IManipulationEvents = GUID$("{4F62C8DA-9C53-4B22-93DF-927A862BBB03}")

' ========================================================================================
' MANIPULATION_PROCESSOR_MANIPULATIONS enum
' ========================================================================================

%MANIPULATION_NONE        = 0
%MANIPULATION_TRANSLATE_X = &H1
%MANIPULATION_TRANSLATE_Y = &H2
%MANIPULATION_SCALE       = &H4
%MANIPULATION_ROTATE      = &H8
%MANIPULATION_ALL         = &HF

'// Floating point constants.
'DECLSPEC_SELECTANY extern const float POSITIVE_INFINITY = ((float)(1e308 * 10));
'DECLSPEC_SELECTANY extern const float NEGATIVE_INFINITY = ((float)(-1e308 * 10));
'DECLSPEC_SELECTANY extern const float NaN = ((float)((1e308 * 10)*0.));
'typedef unsigned long MANIPULATOR_ID;

' ########################################################################################
' Interface name = IInertiaProcessor
' IID = {18B00C6D-C5EE-41B1-90A9-9D4A929095AD}
' IInertiaProcessor interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInertiaProcessor_INTERFACE_DEFINED)
    %IInertiaProcessor_INTERFACE_DEFINED = 1

INTERFACE IInertiaProcessor $IID_IInertiaProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_InitialOriginX ( _                        ' VTable offset = 12
     BYREF x AS SINGLE _                                ' __out FLOAT *x
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialOriginX ( _                        ' VTable offset = 16
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialOriginY ( _                        ' VTable offset = 20
     BYREF y AS SINGLE _                                ' __out FLOAT *y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialOriginY ( _                        ' VTable offset = 24
     BYVAL y AS SINGLE _                                ' __in FLOAT y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialVelocityX ( _                      ' VTable offset = 28
     BYREF x AS SINGLE _                                ' __out FLOAT *x
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialVelocityX ( _                      ' VTable offset = 32
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialVelocityY ( _                      ' VTable offset = 36
     BYREF y AS SINGLE _                                ' __out FLOAT *y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialVelocityY ( _                      ' VTable offset = 40
     BYVAL y AS SINGLE _                                ' __in FLOAT y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialAngularVelocity ( _                ' VTable offset = 44
     BYREF velocity AS SINGLE _                         ' __out FLOAT *velocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialAngularVelocity ( _                ' VTable offset = 48
     BYVAL velocity AS SINGLE _                         ' __in FLOAT velocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialExpansionVelocity ( _              ' VTable offset = 52
     BYREF velocity AS SINGLE _                         ' __out FLOAT *velocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialExpansionVelocity ( _              ' VTable offset = 56
     BYVAL velocity AS SINGLE _                         ' __in FLOAT velocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialRadius ( _                         ' VTable offset = 60
     BYREF radius AS SINGLE _                           ' __out FLOAT *radius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialRadius ( _                         ' VTable offset = 64
     BYVAL radius AS SINGLE _                           ' __in FLOAT radius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_BoundaryLeft ( _                          ' VTable offset = 68
     BYREF left AS SINGLE _                             ' __out FLOAT *left
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_BoundaryLeft ( _                          ' VTable offset = 72
     BYVAL left AS SINGLE _                             ' __in FLOAT left
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_BoundaryTop ( _                           ' VTable offset = 76
     BYREF top AS SINGLE _                              ' __out FLOAT *top
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_BoundaryTop ( _                           ' VTable offset = 80
     BYVAL top AS SINGLE _                              ' __in FLOAT top
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_BoundaryRight ( _                         ' VTable offset = 84
     BYREF right AS SINGLE _                            ' __out FLOAT *right
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_BoundaryRight ( _                         ' VTable offset = 88
     BYVAL right AS SINGLE _                            ' __in FLOAT right
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_BoundaryBottom ( _                        ' VTable offset = 92
     BYREF bottom AS SINGLE _                           ' __out FLOAT *bottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_BoundaryBottom ( _                        ' VTable offset = 96
     BYVAL bottom AS SINGLE _                           ' __in FLOAT bottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ElasticMarginLeft ( _                     ' VTable offset = 100
     BYREF left AS SINGLE _                             ' __out FLOAT *left
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ElasticMarginLeft ( _                     ' VTable offset = 104
     BYVAL left AS SINGLE _                             ' __in FLOAT left
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ElasticMarginTop ( _                      ' VTable offset = 108
     BYREF top AS SINGLE _                              ' __out FLOAT *top
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ElasticMarginTop ( _                      ' VTable offset = 112
     BYVAL top AS SINGLE _                              ' __in FLOAT top
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ElasticMarginRight ( _                    ' VTable offset = 116
     BYREF right AS SINGLE _                            ' __out FLOAT *right
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ElasticMarginRight ( _                    ' VTable offset = 120
     BYVAL right AS SINGLE _                            ' __in FLOAT right
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ElasticMarginBottom ( _                   ' VTable offset = 124
     BYREF bottom AS SINGLE _                           ' __out FLOAT *bottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ElasticMarginBottom ( _                   ' VTable offset = 128
     BYVAL bottom AS SINGLE _                           ' __in FLOAT bottom
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredDisplacement ( _                   ' VTable offset = 132
     BYREF displacement AS SINGLE _                     ' __out FLOAT *displacement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredDisplacement ( _                   ' VTable offset = 136
     BYVAL displacement AS SINGLE _                     ' __in FLOAT displacement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredRotation ( _                       ' VTable offset = 140
     BYREF rotation AS SINGLE _                         ' __out FLOAT *rotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredRotation ( _                       ' VTable offset = 144
     BYVAL rotation AS SINGLE _                         ' __in FLOAT rotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredExpansion ( _                      ' VTable offset = 148
     BYREF expansion AS SINGLE _                        ' __out FLOAT *expansion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredExpansion ( _                      ' VTable offset = 152
     BYVAL expansion AS SINGLE _                        ' __in FLOAT expansion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredDeceleration ( _                   ' VTable offset = 156
     BYREF deceleration AS SINGLE _                     ' __out FLOAT *deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredDeceleration ( _                   ' VTable offset = 160
     BYVAL deceleration AS SINGLE _                     ' __in FLOAT deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredAngularDeceleration ( _            ' VTable offset = 164
     BYREF deceleration AS SINGLE _                     ' __out FLOAT *deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredAngularDeceleration ( _            ' VTable offset = 168
     BYVAL deceleration AS SINGLE _                     ' __in FLOAT deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DesiredExpansionDeceleration ( _          ' VTable offset = 172
     BYREF deceleration AS SINGLE _                     ' __out FLOAT *deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DesiredExpansionDeceleration ( _          ' VTable offset = 176
     BYVAL deceleration AS SINGLE _                     ' __in FLOAT deceleration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InitialTimestamp ( _                      ' VTable offset = 180
     BYREF timestamp AS DWORD _                         ' __out FLOAT *timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InitialTimestamp ( _                      ' VTable offset = 184
     BYVAL timestamp AS DWORD _                         ' __in FLOAT timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 188
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Process ( _                                   ' VTable offset = 192
     BYREF completed AS LONG _                          ' __out BOOL *completed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessTime ( _                               ' VTable offset = 196
     BYVAL timestamp AS DWORD _                         ' __in DWORD timestamp
   , BYREF completed AS LONG _                          ' __out BOOL *completed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Complete ( _                                  ' VTable offset = 200
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompleteTime ( _                              ' VTable offset = 204
     BYVAL timestamp AS DWORD _                         ' __in DWORD timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInertiaProcessor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IManipulationProcessor
' IID = {A22AC519-8300-48A0-BEF4-F1BE8737DBA4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IManipulationProcessor_INTERFACE_DEFINED)
    %IManipulationProcessor_INTERFACE_DEFINED = 1

INTERFACE IManipulationProcessor $IID_IManipulationProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_SupportedManipulations ( _                ' VTable offset = 12
     BYREF manipulations AS LONG _                      ' __out MANIPULATION_PROCESSOR_MANIPULATIONS *manipulations
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SupportedManipulations ( _                ' VTable offset = 16
     BYVAL manipulations AS LONG _                      ' __in MANIPULATION_PROCESSOR_MANIPULATIONS manipulations
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PivotPointX ( _                           ' VTable offset = 20
     BYREF pivotPointX AS SINGLE _                      ' __out FLOAT *pivotPointX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PivotPointX ( _                           ' VTable offset = 24
     BYVAL pivotPointX AS SINGLE _                      ' __in FLOAT pivotPointX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PivotPointY ( _                           ' VTable offset = 28
     BYREF pivotPointY AS SINGLE _                      ' __out FLOAT *pivotPointY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PivotPointY ( _                           ' VTable offset = 32
     BYVAL pivotPointY AS SINGLE _                      ' __in FLOAT pivotPointY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PivotRadius ( _                           ' VTable offset = 36
     BYREF pivotRadius AS SINGLE _                      ' __out FLOAT *pivotRadius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PivotRadius ( _                           ' VTable offset = 40
     BYVAL pivotRadius AS SINGLE _                      ' __in FLOAT pivotRadius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompleteManipulation ( _                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessDown ( _                               ' VTable offset = 48
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessMove ( _                               ' VTable offset = 52
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUp ( _                                 ' VTable offset = 56
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessDownWithTime ( _                       ' VTable offset = 60
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL timestamp AS DWORD _                         ' __in DWORD timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessMoveWithTime ( _                       ' VTable offset = 64
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL timestamp AS DWORD _                         ' __in DWORD timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessUpWithTime ( _                         ' VTable offset = 68
     BYVAL manipulatorId AS DWORD _                     ' __in MANIPULATOR_ID manipulatorId
   , BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL timestamp AS DWORD _                         ' __in DWORD timestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVelocityX ( _                              ' VTable offset = 72
     BYREF velocityX AS SINGLE _                        ' __out FLOAT *velocityX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVelocityY ( _                              ' VTable offset = 76
     BYREF velocityY AS SINGLE _                        ' __out FLOAT *velocityY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExpansionVelocity ( _                      ' VTable offset = 80
     BYREF expansionVelocity AS SINGLE _                ' __out FLOAT *expansionVelocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAngularVelocity ( _                        ' VTable offset = 84
     BYREF angularVelocity AS SINGLE _                  ' __out FLOAT *angularVelocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MinimumScaleRotateRadius ( _              ' VTable offset = 88
     BYREF minRadius AS SINGLE _                        ' __out FLOAT *minRadius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MinimumScaleRotateRadius ( _              ' VTable offset = 92
     BYVAL minRadius AS SINGLE _                        ' __in FLOAT minRadius
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IManipulationProcessor_INTERFACE_DEFINED__ */

' ########################################################################################
' Class CIManipulationEvents
' Interface name = _IManipulationEvents
' IID = {4F62C8DA-9C53-4B22-93DF-927A862BBB03}
' ########################################################################################

'CLASS CIManipulationEvents GUID$("{7DE672A1-5BC7-4C47-83E5-8BDE8E3548C1}")

'INTERFACE IManipulationEventsImpl GUID$("{4F62C8DA-9C53-4B22-93DF-927A862BBB03}")

'  INHERIT IUnknown

'   ' =====================================================================================
'   METHOD ManipulationStarted ( _
'     BYVAL x AS SINGLE _                                ' __in FLOAT x
'   , BYVAL y AS SINGLE _                                ' __in FLOAT y
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ManipulationDelta ( _
'     BYVAL x AS SINGLE _                                ' __in FLOAT x
'   , BYVAL y AS SINGLE _                                ' __in FLOAT y
'   , BYVAL translationDeltaX AS SINGLE _                ' __in FLOAT translationDeltaX
'   , BYVAL translationDeltaY AS SINGLE _                ' __in FLOAT translationDeltaY
'   , BYVAL scaleDelta AS SINGLE _                       ' __in FLOAT scaleDelta
'   , BYVAL expansionDelta AS SINGLE _                   ' __in FLOAT expansionDelta
'   , BYVAL rotationDelta AS SINGLE _                    ' __in FLOAT rotationDelta
'   , BYVAL cumulativeTranslationX AS SINGLE _           ' __in FLOAT cumulativeTranslationX
'   , BYVAL cumulativeTranslationY AS SINGLE _           ' __in FLOAT cumulativeTranslationY
'   , BYVAL cumulativeScale AS SINGLE _                  ' __in FLOAT cumulativeScale
'   , BYVAL cumulativeExpansion AS SINGLE _              ' __in FLOAT cumulativeExpansion
'   , BYVAL cumulativeRotation AS SINGLE _               ' __in FLOAT cumulativeRotation
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ManipulationCompleted ( _
'     BYVAL x AS SINGLE _                                ' __in FLOAT x
'   , BYVAL y AS SINGLE _                                ' __in FLOAT y
'   , BYVAL cumulativeTranslationX AS SINGLE _           ' __in FLOAT cumulativeTranslationX
'   , BYVAL cumulativeTranslationY AS SINGLE _           ' __in FLOAT cumulativeTranslationY
'   , BYVAL cumulativeScale AS SINGLE _                  ' __in FLOAT cumulativeScale
'   , BYVAL cumulativeExpansion AS SINGLE _              ' __in FLOAT cumulativeExpansion
'   , BYVAL cumulativeRotation AS SINGLE _               ' __in FLOAT cumulativeRotation
'   ) AS LONG                                            ' HRESULT

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
