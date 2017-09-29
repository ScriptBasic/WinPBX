' ########################################################################################
' Microsoft Windows
' File: VidCap.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VIDCAP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "strmif.inc"

'#include "ks.h"
'#ifndef _KS_
#IF NOT %DEF(%KS_INC)
' // Size = 16 bytes
TYPE KSTOPOLOGY_CONNECTION DWORD
   FromNode    AS DWORD   ' ULONG
   FromNodePin AS DWORD   ' ULONG
   ToNode      AS DWORD   ' ULONG
   ToNodePin   AS DWORD   ' ULONG
END TYPE
#ENDIF
'#endif

' ########################################################################################
' IKsTopologyInfo interface
' IID = 720D4AC0-7533-11D0-A5D6-28DB04C10000
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsTopologyInfo_INTERFACE_DEFINED)
    %IKsTopologyInfo_INTERFACE_DEFINED = 1

$IID_IKsTopologyInfo = GUID$("{720D4AC0-7533-11D0-A5D6-28DB04C10000}")

INTERFACE IKsTopologyInfo $IID_IKsTopologyInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_NumCategories ( _                         ' VTable offset = 12
     BYREF pdwNumCategories AS DWORD _                  ' __out DWORD *pdwNumCategories
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Category ( _                              ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pCategory AS GUID _                          ' __out GUID *pCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NumConnections ( _                        ' VTable offset = 20
     BYREF pdwNumConnections AS DWORD _                 ' __out DWORD *pdwNumConnections
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ConnectionInfo ( _                        ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pConnectionInfo AS KSTOPOLOGY_CONNECTION _   ' __out KSTOPOLOGY_CONNECTION *pConnectionInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NodeName ( _                              ' VTable offset = 28
     BYVAL dwNodeId AS DWORD _                          ' __in DWORD dwNodeId
   , BYREF pwchNodeName AS WSTRINGZ _                   ' __out_bcount_opt(dwBufSize) WCHAR *pwchNodeName
   , BYVAL dwBufSize AS DWORD _                         ' __in DWORD dwBufSize
   , BYREF pdwNameLen AS DWORD _                        ' __out DWORD *pdwNameLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NumNodes ( _                              ' VTable offset = 32
     BYREF pdwNumNodes AS DWORD _                       ' __out DWORD *pdwNumNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NodeType ( _                              ' VTable offset = 36
     BYVAL dwNodeId AS DWORD _                          ' __in DWORD dwNodeId
   , BYREF pNodeType AS GUID _                          ' __out GUID *pNodeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNodeInstance ( _                        ' VTable offset = 40
     BYVAL dwNodeId AS DWORD _                          ' __in DWORD dwNodeId
   , BYREF iid AS GUID _                                ' __in REFIID iid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsTopologyInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' ISelector interface
' IID = 1ABDAECA-68B6-4F83-9371-B413907C7B9F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISelector_INTERFACE_DEFINED)
    %ISelector_INTERFACE_DEFINED = 1

$IID_ISelector = GUID$("{1ABDAECA-68B6-4F83-9371-B413907C7B9F}")

INTERFACE ISelector $IID_ISelector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_NumSources ( _                            ' VTable offset = 12
     BYREF pdwNumSources AS DWORD _                     ' __out DWORD *pdwNumSources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SourceNodeId ( _                          ' VTable offset = 16
     BYREF pdwPinId AS DWORD _                          ' __out DWORD *pdwPinId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SourceNodeId ( _                          ' VTable offset = 20
     BYVAL dwPinId AS DWORD _                           ' __in DWORD dwPinId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISelector_INTERFACE_DEFINED__ */

' ########################################################################################
' ICameraControl interface
' IID = 2BA1785D-4D1B-44EF-85E8-C7F1D3F20184
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICameraControl_INTERFACE_DEFINED)
    %ICameraControl_INTERFACE_DEFINED = 1

$IID_ICameraControl = GUID$("{2BA1785D-4D1B-44EF-85E8-C7F1D3F20184}")

INTERFACE ICameraControl $IID_ICameraControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Exposure ( _                              ' VTable offset = 12
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Exposure ( _                              ' VTable offset = 16
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Exposure ( _                         ' VTable offset = 20
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Focus ( _                                 ' VTable offset = 24
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Focus ( _                                 ' VTable offset = 28
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Focus ( _                            ' VTable offset = 32
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Iris ( _                                  ' VTable offset = 36
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Iris ( _                                  ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Iris ( _                             ' VTable offset = 44
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Zoom ( _                                  ' VTable offset = 48
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Zoom ( _                                  ' VTable offset = 52
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Zoom ( _                             ' VTable offset = 56
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FocalLengths ( _                          ' VTable offset = 60
     BYREF plOcularFocalLength AS LONG _                ' __out long *plOcularFocalLength
   , BYREF plObjectiveFocalLengthMin AS LONG _          ' __out long *plObjectiveFocalLengthMin
   , BYREF plObjectiveFocalLengthMax AS LONG _          ' __out long *plObjectiveFocalLengthMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Pan ( _                                   ' VTable offset = 64
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Pan ( _                                   ' VTable offset = 68
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Pan ( _                              ' VTable offset = 72
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Tilt ( _                                  ' VTable offset = 76
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Tilt ( _                                  ' VTable offset = 80
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Tilt ( _                             ' VTable offset = 84
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PanTilt ( _                               ' VTable offset = 88
     BYREF pPanValue AS LONG _                          ' __out long *pPanValue
   , BYREF pTiltValue AS LONG _                         ' __out long *pTiltValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PanTilt ( _                               ' VTable offset = 92
     BYVAL PanValue AS LONG _                           ' __in long PanValue
   , BYVAL TiltValue AS LONG _                          ' __in long TiltValue
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Roll ( _                                  ' VTable offset = 96
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Roll ( _                                  ' VTable offset = 100
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Roll ( _                             ' VTable offset = 104
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ExposureRelative ( _                      ' VTable offset = 108
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ExposureRelative ( _                      ' VTable offset = 112
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_ExposureRelative ( _                 ' VTable offset = 116
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FocusRelative ( _                         ' VTable offset = 120
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_FocusRelative ( _                         ' VTable offset = 124
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_FocusRelative ( _                   ' VTable offset = 128
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IrisRelative ( _                          ' VTable offset = 132
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IrisRelative ( _                          ' VTable offset = 136
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_IrisRelative ( _                     ' VTable offset = 140
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ZoomRelative ( _                          ' VTable offset = 144
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ZoomRelative ( _                          ' VTable offset = 148
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_ZoomRelative ( _                     ' VTable offset = 152
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PanRelative ( _                           ' VTable offset = 156
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PanRelative ( _                           ' VTable offset = 160
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TiltRelative ( _                          ' VTable offset = 164
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TiltRelative ( _                          ' VTable offset = 168
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_TiltRelative ( _                     ' VTable offset = 172
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PanTiltRelative ( _                       ' VTable offset = 176
     BYREF pPanValue AS LONG _                          ' __out long *pPanValue
   , BYREF pTiltValue AS LONG _                         ' __out long *pTiltValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PanTiltRelative ( _                       ' VTable offset = 180
     BYVAL PanValue AS LONG _                           ' __in long PanValue
   , BYVAL TiltValue AS LONG _                          ' __in long TiltValue
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_PanRelative ( _                      ' VTable offset = 184
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RollRelative ( _                          ' VTable offset = 188
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RollRelative ( _                          ' VTable offset = 192
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_RollRelative ( _                     ' VTable offset = 196
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ScanMode ( _                              ' VTable offset = 200
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ScanMode ( _                              ' VTable offset = 204
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PrivacyMode ( _                           ' VTable offset = 208
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PrivacyMode ( _                           ' VTable offset = 212
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICameraControl_INTERFACE_DEFINED__ */

' ########################################################################################
' IVideoProcAmp interface
' IID = 4050560E-42A7-413a-85C2-09269A2D0F44
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVideoProcAmp_INTERFACE_DEFINED)
    %IVideoProcAmp_INTERFACE_DEFINED = 1

$IID_IVideoProcAmp = GUID$("{4050560E-42A7-413a-85C2-09269A2D0F44}")

INTERFACE IVideoProcAmp $IID_IVideoProcAmp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_BacklightCompensation ( _                 ' VTable offset = 12
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_BacklightCompensation ( _                 ' VTable offset = 16
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_BacklightCompensation ( _            ' VTable offset = 20
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Brightness ( _                            ' VTable offset = 24
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Brightness ( _                            ' VTable offset = 28
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Brightness ( _                       ' VTable offset = 32
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ColorEnable ( _                           ' VTable offset = 36
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ColorEnable ( _                           ' VTable offset = 40
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_ColorEnable ( _                      ' VTable offset = 44
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Contrast ( _                              ' VTable offset = 48
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Contrast ( _                              ' VTable offset = 52
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Contrast ( _                         ' VTable offset = 56
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Gamma ( _                                 ' VTable offset = 60
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Gamma ( _                                 ' VTable offset = 64
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Gamma ( _                            ' VTable offset = 68
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Saturation ( _                            ' VTable offset = 72
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Saturation ( _                            ' VTable offset = 76
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Saturation ( _                       ' VTable offset = 80
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Sharpness ( _                             ' VTable offset = 84
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Sharpness ( _                             ' VTable offset = 88
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Sharpness ( _                        ' VTable offset = 92
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WhiteBalance ( _                          ' VTable offset = 96
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WhiteBalance ( _                          ' VTable offset = 100
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_WhiteBalance ( _                     ' VTable offset = 104
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Gain ( _                                  ' VTable offset = 108
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Gain ( _                                  ' VTable offset = 112
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Gain ( _                             ' VTable offset = 116
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Hue ( _                                   ' VTable offset = 120
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Hue ( _                                   ' VTable offset = 124
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_Hue ( _                              ' VTable offset = 128
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DigitalMultiplier ( _                     ' VTable offset = 132
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DigitalMultiplier ( _                     ' VTable offset = 136
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_DigitalMultiplier ( _                ' VTable offset = 140
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PowerlineFrequency ( _                    ' VTable offset = 144
     BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pFlags AS LONG _                             ' __out long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PowerlineFrequency ( _                    ' VTable offset = 148
     BYVAL Value AS LONG _                              ' __in long Value
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_PowerlineFrequency ( _               ' VTable offset = 152
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WhiteBalanceComponent ( _                 ' VTable offset = 156
     BYREF pValue1 AS LONG _                            ' __out long *pValue1
   , BYREF pValue2 AS LONG _                            ' __out long *pValue2
   , BYREF pFlags AS LONG _                             ' __inout long *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WhiteBalanceComponent ( _                 ' VTable offset = 160
     BYVAL Value1 AS LONG _                             ' __in long Value1
   , BYVAL Value2 AS LONG _                             ' __in long Value2
   , BYVAL Flags AS LONG _                              ' __in long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getRange_WhiteBalanceComponent ( _            ' VTable offset = 164
     BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlag AS LONG _                          ' __out long *pCapsFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVideoProcAmp_INTERFACE_DEFINED__ */

' ########################################################################################
' IKsNodeControl interface
' IID = 11737C14-24A7-4bb5-81A0-0D003813B0C4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsNodeControl_INTERFACE_DEFINED)
    %IKsNodeControl_INTERFACE_DEFINED = 1

$IID_IKsNodeControl = GUID$("{11737C14-24A7-4bb5-81A0-0D003813B0C4}")

INTERFACE IKsNodeControl $IID_IKsNodeControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_NodeId ( _                                ' VTable offset = 12
     BYVAL dwNodeId AS DWORD _                          ' __in DWORD dwNodeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KsControl ( _                             ' VTable offset = 16
     BYVAL pKsControl AS DWORD _                        ' __in PVOID pKsControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsNodeControl_INTERFACE_DEFINED__ */
