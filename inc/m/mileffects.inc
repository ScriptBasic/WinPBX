' ########################################################################################
' Microsoft Windows
' File: mileffects.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MILEffects
' Version: 1.0, Locale ID = 0
' Library GUID: {5E90D980-A4B8-4F5D-B7C6-99B1452D03CD}
' ########################################################################################

#INCLUDE THIS ONCE
%MILEFFECTS_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "wincodec.inc"

'#if 0
'typedef DWORD MilPoint2D;
'typedef DWORD MilPointAndSizeD;
'typedef DWORD MilMatrix3x2D;
'#endif

#IF NOT %DEF(%MILTYPES_DEFINED)
%MILTYPES_DEFINED = 1

' // Size = 32 bytes
TYPE MilPointAndSizeD DWORD
   X      AS DOUBLE
   Y      AS DOUBLE
   Width  AS DOUBLE
   Height AS DOUBLE
END TYPE

' // Size = 16 bytes
TYPE MilPoint2D DWORD
   X AS DOUBLE
   Y AS DOUBLE
END TYPE

' // Size = 48 bytes
TYPE MilMatrix3x2D DWORD
   S_11 AS DOUBLE
   S_12 AS DOUBLE
   S_21 AS DOUBLE
   S_22 AS DOUBLE
   DX   AS DOUBLE
   DY   AS DOUBLE
END TYPE

MACRO MIL_2DPOINTD = MilPoint2D
MACRO MIL_RECTD = MilPointAndSizeD
MACRO MIL_MATRIX3X2D = MilMatrix3x2D

#ENDIF   ' // MILTYPES_DEFINED

'typedef MilPoint2D MIL_2DPOINTD;
'typedef MilPointAndSizeD MIL_RECTD;

'#ifndef MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF

'typedef MilMatrix3x2D MIL_MATRIX3X2D;

'#define MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
'#endif MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF


'#IF NOT %DEF(%MILEffects_LIBRARY_DEFINED__
'   %MILEffects_LIBRARY_DEFINED__

%MILBITMAPEFFECT_SDK_VERSION = &H01000000???

$CLSID_MILBitmapEffectGroup = GUID$("{AC9C1A9A-7E18-4F64-AC7E-47CF7F051E95}")
$CLSID_MILBitmapEffectBlur = GUID$("{A924DF87-225D-4373-8F5B-B90EC85AE3DE}")
$CLSID_MILBitmapEffectDropShadow = GUID$("{459A3FBE-D8AC-4692-874B-7A265715AA16}")
$CLSID_MILBitmapEffectOuterGlow = GUID$("{E2161BDD-7EB6-4725-9C0B-8A2A1B4F0667}")
$CLSID_MILBitmapEffectBevel = GUID$("{FD361DBE-6C9B-4DE0-8290-F6400C2737ED}")
$CLSID_MILBitmapEffectEmboss = GUID$("{CD299846-824F-47EC-A007-12AA767F2816}")

'extern STDMETHODIMP MILCreateBitmapEffectFactory(DWORD dwSDKVersion, IMILBitmapEffectFactory **ppFactory);
DECLARE FUNCTION MILCreateBitmapEffectFactory IMPORT "mileffects.dll" ALIAS "MILCreateBitmapEffectFactory" ( _
   BYVAL dwSDKVersion AS DWORD _                        ' __in  DWORD dwSDKVersion
 , BYREF IMILBitmapEffectFactory _                      ' __out IMILBitmapEffectFactory **ppFactory
 ) AS LONG                                              ' HRESULT

'typedef /* [public] */ REFGUID REFWICPixelFormatGUID;
'typedef /* [public] */ GUID WICPixelFormatGUID;

' // Size = 128 bytes
TYPE MILMatrixF DWORD
   m_11 AS DOUBLE
   m_12 AS DOUBLE
   m_13 AS DOUBLE
   m_14 AS DOUBLE
   m_21 AS DOUBLE
   m_22 AS DOUBLE
   m_23 AS DOUBLE
   m_24 AS DOUBLE
   m_31 AS DOUBLE
   m_32 AS DOUBLE
   m_33 AS DOUBLE
   m_34 AS DOUBLE
   m_41 AS DOUBLE
   m_42 AS DOUBLE
   m_43 AS DOUBLE
   m_44 AS DOUBLE
END TYPE


' ########################################################################################
' IMILBitmapEffectConnectorInfo interface
' IID = F66D2E4B-B46B-42FC-859E-3DA0ECDB3C43
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectConnectorInfo_INTERFACE_DEFINED)
   %IMILBitmapEffectConnectorInfo_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectConnectorInfo = GUID$("{F66D2E4B-B46B-42FC-859E-3DA0ECDB3C43}")

INTERFACE IMILBitmapEffectConnectorInfo $IID_IMILBitmapEffectConnectorInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 12
     BYREF puiIndex AS DWORD _                          ' __retval_out ULONG *puiIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptimalFormat ( _                          ' VTable offset = 16
     BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberFormats ( _                          ' VTable offset = 20
     BYREF pulNumberFormats AS DWORD _                  ' __retval_out ULONG *pulNumberFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 24
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectConnectorInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectConnectionsInfo interface
' IID = 476B538A-C765-4237-BA4A-D6A880FF0CFC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectConnectionsInfo_INTERFACE_DEFINED)
   %IMILBitmapEffectConnectionsInfo_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectConnectionsInfo = GUID$("{476B538A-C765-4237-BA4A-D6A880FF0CFC}")

INTERFACE IMILBitmapEffectConnectionsInfo $IID_IMILBitmapEffectConnectionsInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberInputs ( _                           ' VTable offset = 12
     BYREF puiNumInputs AS DWORD _                      ' __retval_out ULONG *puiNumInputs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOutputs ( _                          ' VTable offset = 16
     BYREF puiNumOutputs AS DWORD _                     ' __retval_out ULONG *puiNumOutputs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputConnectorInfo ( _                     ' VTable offset = 20
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnectorInfo AS IMILBitmapEffectConnectorInfo _ ' __retval_out IMILBitmapEffectConnectorInfo **ppConnectorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputConnectorInfo ( _                    ' VTable offset = 24
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnectorInfo AS IMILBitmapEffectConnectorInfo _ ' __retval_out IMILBitmapEffectConnectorInfo **ppConnectorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectConnectionsInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectConnections interface
' IID = C2B5D861-9B1A-4374-89B0-DEC4874D6A81
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectConnections_INTERFACE_DEFINED)
   %IMILBitmapEffectConnections_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectConnections = GUID$("{C2B5D861-9B1A-4374-89B0-DEC4874D6A81}")

INTERFACE IMILBitmapEffectConnections $IID_IMILBitmapEffectConnections

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputConnector ( _                         ' VTable offset = 12
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnector AS IMILBitmapEffectInputConnector _ ' __retval_out IMILBitmapEffectInputConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputConnector ( _                        ' VTable offset = 16
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnector AS IMILBitmapEffectOutputConnector _ ' __retval_out IMILBitmapEffectOutputConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectConnections_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffect interface
' IID = 8A6FF321-C944-4A1B-9944-9954AF301258
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffect_INTERFACE_DEFINED)
   %IMILBitmapEffect_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffect = GUID$("{8A6FF321-C944-4A1B-9944-9954AF301258}")

INTERFACE IMILBitmapEffect $IID_IMILBitmapEffect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOutput ( _                                 ' VTable offset = 12
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYVAL pContext AS IMILBitmapEffectRenderContext _  ' __in IMILBitmapEffectRenderContext *pContext
   , BYREF ppBitmapSource AS IWICBitmapSource _         ' __retval_out IWICBitmapSource **ppBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentEffect ( _                           ' VTable offset = 16
     BYREF ppParentEffect AS IMILBitmapEffectGroup _    ' __retval_out IMILBitmapEffectGroup **ppParentEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputSource ( _                            ' VTable offset = 20
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYVAL pBitmapSource AS IWICBitmapSource _          ' __in IWICBitmapSource *pBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffect_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectImpl interface
' IID = CC2468F2-9936-47BE-B4AF-06B5DF5DBCBB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectImpl_INTERFACE_DEFINED)
   %IMILBitmapEffectImpl_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectImpl = GUID$("{CC2468F2-9936-47BE-B4AF-06B5DF5DBCBB}")

INTERFACE IMILBitmapEffectImpl $IID_IMILBitmapEffectImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsInPlaceModificationAllowed ( _              ' VTable offset = 12
     BYVAL pOutputConnector AS IMILBitmapEffectOutputConnector _ ' __in IMILBitmapEffectOutputConnector *pOutputConnector
   , BYREF pfModifyInPlace AS INTEGER _                 ' __retval_out VARIANT_BOOL *pfModifyInPlace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParentEffect ( _                           ' VTable offset = 16
     BYVAL pParentEffect AS IMILBitmapEffectGroup _     ' __in IMILBitmapEffectGroup *pParentEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputSource ( _                            ' VTable offset = 20
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppBitmapSource AS IWICBitmapSource _         ' __retval_out IWICBitmapSource **ppBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputSourceBounds ( _                      ' VTable offset = 24
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF pRect AS MIL_RECTD _                         ' __out MIL_RECTD *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputBitmapSource ( _                      ' VTable offset = 28
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYVAL pRenderContext AS IMILBitmapEffectRenderContext _ ' __in IMILBitmapEffectRenderContext *pRenderContext
   , BYREF pfModifyInPlace AS INTEGER _                 ' __in_out VARIANT_BOOL *pfModifyInPlace
   , BYREF ppBitmapSource AS IWICBitmapSource _         ' __retval_out IWICBitmapSource **ppBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputBitmapSource ( _                     ' VTable offset = 32
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYVAL pRenderContext AS IMILBitmapEffectRenderContext _ ' __in IMILBitmapEffectRenderContext *pRenderContext
   , BYREF pfModifyInPlace AS INTEGER _                 ' __in_out VARIANT_BOOL *pfModifyInPlace
   , BYREF ppBitmapSource AS IWICBitmapSource _         ' __retval_out IWICBitmapSource **ppBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 36
     BYVAL pInner AS IUnknown _                         ' __in IUnknown *pInner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectImpl_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectGroup interface
' IID = 2F952360-698A-4AC6-81A1-BCFDF08EB8E8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectGroup_INTERFACE_DEFINED)
   %IMILBitmapEffectGroup_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectGroup = GUID$("{2F952360-698A-4AC6-81A1-BCFDF08EB8E8}")

INTERFACE IMILBitmapEffectGroup $IID_IMILBitmapEffectGroup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInteriorInputConnector ( _                 ' VTable offset = 12
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnector AS IMILBitmapEffectOutputConnector _ ' __retval_out IMILBitmapEffectOutputConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInteriorOutputConnector ( _                ' VTable offset = 16
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF ppConnector AS IMILBitmapEffectInputConnector _ ' __retval_out IMILBitmapEffectInputConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 20
     BYVAL pEffect AS IMILBitmapEffect _                ' __in IMILBitmapEffect *pEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectGroupImpl interface
' IID = 78FED518-1CFC-4807-8B85-6B6E51398F62
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectGroupImpl_INTERFACE_DEFINED)
   %IMILBitmapEffectGroupImpl_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectGroupImpl = GUID$("{78FED518-1CFC-4807-8B85-6B6E51398F62}")

INTERFACE IMILBitmapEffectGroupImpl $IID_IMILBitmapEffectGroupImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Preprocess ( _                                ' VTable offset = 12
     BYVAL pContext AS IMILBitmapEffectRenderContext _  ' __in IMILBitmapEffectRenderContext *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberChildren ( _                         ' VTable offset = 16
     BYREF puiNumberChildren AS DWORD _                 ' __retval_out ULONG *puiNumberChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChildren ( _                               ' VTable offset = 20
     BYREF pChildren AS IMILBitmapEffects _             ' __retval_out IMILBitmapEffects **pChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectGroupImpl_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectRenderContext interface
' IID = 12A2EC7E-2D33-44B2-B334-1ABB7846E390
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectRenderContext_INTERFACE_DEFINED)
   %IMILBitmapEffectRenderContext_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectRenderContext = GUID$("{12A2EC7E-2D33-44B2-B334-1ABB7846E390}")

INTERFACE IMILBitmapEffectRenderContext $IID_IMILBitmapEffectRenderContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOutputPixelFormat ( _                      ' VTable offset = 12
     BYREF format AS GUID _                             ' __in REFWICPixelFormatGUID format
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputPixelFormat ( _                      ' VTable offset = 16
     BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUseSoftwareRenderer ( _                    ' VTable offset = 20
     BYVAL fSoftware AS INTEGER _                       ' __in VARIANT_BOOL fSoftware
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInitialTransform ( _                       ' VTable offset = 24
     BYREF pMatrix AS MILMatrixF _                      ' __in MILMatrixF *pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFinalTransform ( _                         ' VTable offset = 28
     BYREF pMatrix AS MILMatrixF _                      ' __out MILMatrixF *pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputDPI ( _                              ' VTable offset = 32
     BYVAL dblDpiX AS DOUBLE _                          ' __in double dblDpiX
   , BYVAL dblDpiY AS DOUBLE _                          ' __in double dblDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputDPI ( _                              ' VTable offset = 36
     BYREF pdblDpiX AS DOUBLE _                         ' __out double *pdblDpiX
   , BYREF pdblDpiY AS DOUBLE _                         ' __out double *pdblDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRegionOfInterest ( _                       ' VTable offset = 40
     BYREF pRect AS MIL_RECTD _                         ' __in MIL_RECTD *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectRenderContext_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectRenderContextImpl interface
' IID = 4D25ACCB-797D-4FD2-B128-DFFEFF84FCC3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectRenderContextImpl_INTERFACE_DEFINED)
   %IMILBitmapEffectRenderContextImpl_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectRenderContextImpl = GUID$("{4D25ACCB-797D-4FD2-B128-DFFEFF84FCC3}")

INTERFACE IMILBitmapEffectRenderContextImpl $IID_IMILBitmapEffectRenderContextImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUseSoftwareRenderer ( _                    ' VTable offset = 12
     BYREF pfSoftware AS INTEGER _                      ' __retval_out VARIANT_BOOL *pfSoftware
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 16
     BYREF pMatrix AS MILMatrixF _                      ' __in_out MILMatrixF *pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTransform ( _                           ' VTable offset = 20
     BYREF pMatrix AS MILMatrixF _                      ' __in MILMatrixF *pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputBounds ( _                           ' VTable offset = 24
     BYREF pRect AS MIL_RECTD _                         ' __in_out MIL_RECTD *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateOutputBounds ( _                        ' VTable offset = 28
     BYREF pRect AS MIL_RECTD _                         ' __in MIL_RECTD *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectRenderContextImpl_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectFactory interface
' IID = 33A9DF34-A403-4EC7-B07E-BC0682370845
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectFactory_INTERFACE_DEFINED)
   %IMILBitmapEffectFactory_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectFactory = GUID$("{33A9DF34-A403-4EC7-B07E-BC0682370845}")

INTERFACE IMILBitmapEffectFactory $IID_IMILBitmapEffectFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 12
     BYREF pguidEffect AS GUID _                        ' __in const GUID *pguidEffect
   , BYREF ppEffect AS IMILBitmapEffect _               ' __out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateContext ( _                             ' VTable offset = 16
     BYREF ppContext AS IMILBitmapEffectRenderContext _ ' __out IMILBitmapEffectRenderContext **ppContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEffectOuter ( _                         ' VTable offset = 20
     BYREF ppEffect AS IMILBitmapEffect _               ' __out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectFactory_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectPrimitive interface
' IID = 67E31025-3091-4DFC-98D6-DD494551461D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectPrimitive_INTERFACE_DEFINED)
   %IMILBitmapEffectPrimitive_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectPrimitive = GUID$("{67E31025-3091-4DFC-98D6-DD494551461D}")

INTERFACE IMILBitmapEffectPrimitive $IID_IMILBitmapEffectPrimitive

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOutput ( _                                 ' VTable offset = 12
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYVAL pContext AS IMILBitmapEffectRenderContext _  ' __in IMILBitmapEffectRenderContext *pContext
   , BYREF pfModifyInPlace AS INTEGER _                 ' __in_out VARIANT_BOOL *pfModifyInPlace
   , BYREF ppBitmapSource AS IWICBitmapSource _         ' __retval_out IWICBitmapSource **ppBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransformPoint ( _                            ' VTable offset = 16
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF p AS MIL_2DPOINTD _                          ' __in_out MIL_2DPOINTD *p
   , BYVAL fForwardTransform AS INTEGER _               ' __in VARIANT_BOOL fForwardTransform
   , BYVAL pContext AS IMILBitmapEffectRenderContext _  ' __in IMILBitmapEffectRenderContext *pContext
   , BYREF pfPointTransformed AS INTEGER _              ' __out VARIANT_BOOL *pfPointTransformed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransformRect ( _                             ' VTable offset = 20
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF p AS MIL_RECTD _                             ' __in_out MIL_RECTD *p
   , BYVAL fForwardTransform AS INTEGER _               ' __in VARIANT_BOOL fForwardTransform
   , BYVAL pContext AS IMILBitmapEffectRenderContext _  ' __in IMILBitmapEffectRenderContext *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasAffineTransform ( _                        ' VTable offset = 24
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF pfAffine AS INTEGER _                        ' __out VARIANT_BOOL *pfAffine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasInverseTransform ( _                       ' VTable offset = 28
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF pfHasInverse AS INTEGER _                    ' __out VARIANT_BOOL *pfHasInverse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAffineMatrix ( _                           ' VTable offset = 32
     BYVAL uiIndex AS DWORD _                           ' __in ULONG uiIndex
   , BYREF pMatrix AS MIL_MATRIX3X2D _                  ' __in_out MIL_MATRIX3X2D *pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectPrimitive_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectPrimitiveImpl interface
' IID = CE41E00B-EFA6-44E7-B007-DD042E3AE126
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectPrimitiveImpl_INTERFACE_DEFINED)
   %IMILBitmapEffectPrimitiveImpl_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectPrimitiveImpl = GUID$("{CE41E00B-EFA6-44E7-B007-DD042E3AE126}")

INTERFACE IMILBitmapEffectPrimitiveImpl $IID_IMILBitmapEffectPrimitiveImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 12
     BYVAL uiOutputIndex AS DWORD _                     ' __in ULONG uiOutputIndex
   , BYREF pfDirty AS INTEGER _                         ' __retval_out VARIANT_BOOL *pfDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsVolatile ( _                                ' VTable offset = 16
     BYVAL uiOutputIndex AS DWORD _                     ' __in ULONG uiOutputIndex
   , BYREF pfVolatile AS INTEGER _                      ' __retval_out VARIANT_BOOL *pfVolatile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectPrimitiveImpl_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffects interface
' IID = 51AC3DCE-67C5-448B-9180-AD3EABDDD5DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffects_INTERFACE_DEFINED)
   %IMILBitmapEffects_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffects = GUID$("{51AC3DCE-67C5-448B-9180-AD3EABDDD5DD}")

INTERFACE IMILBitmapEffects $IID_IMILBitmapEffects

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NewEnum_ ( _                                  ' VTable offset = 12
     BYREF ppiuReturn AS IUnknown _                     ' __retval_out IUnknown **ppiuReturn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Parent ( _                                ' VTable offset = 16
     BYREF ppEffect AS IMILBitmapEffectGroup _          ' __retval_out IMILBitmapEffectGroup **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 20
     BYVAL uindex AS DWORD _                            ' __in ULONG uindex
   , BYREF ppEffect AS IMILBitmapEffect _               ' __retval_out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Count ( _                                 ' VTable offset = 24
     BYREF puiCount AS DWORD _                          ' __retval_out ULONG *puiCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffects_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectConnector interface
' IID = F59567B3-76C1-4D47-BA1E-79F955E350EF
' Inherited interface = IMILBitmapEffectConnectorInfo
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectConnector_INTERFACE_DEFINED)
   %IMILBitmapEffectConnector_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectConnector = GUID$("{F59567B3-76C1-4D47-BA1E-79F955E350EF}")

INTERFACE IMILBitmapEffectConnector $IID_IMILBitmapEffectConnector

   INHERIT IUnknown

   ' =====================================================================================
   ' IMILBitmapEffectConnectorInfo Methods
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 12
     BYREF puiIndex AS DWORD _                          ' __retval_out ULONG *puiIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptimalFormat ( _                          ' VTable offset = 16
     BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberFormats ( _                          ' VTable offset = 20
     BYREF pulNumberFormats AS DWORD _                  ' __retval_out ULONG *pulNumberFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 24
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMILBitmapEffectConnector Methods
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
     BYREF pfConnected AS INTEGER _                     ' __retval_out VARIANT_BOOL *pfConnected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmapEffect ( _                           ' VTable offset = 32
     BYREF ppEffect AS IMILBitmapEffect _               ' __retval_out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectInputConnector interface
' IID = A9B4ECAA-7A3C-45E7-8573-F4B81B60DD6C
' Inherited interface = IMILBitmapEffectConnector
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectInputConnector_INTERFACE_DEFINED)
   %IMILBitmapEffectInputConnector_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectInputConnector = GUID$("{A9B4ECAA-7A3C-45E7-8573-F4B81B60DD6C}")

INTERFACE IMILBitmapEffectInputConnector $IID_IMILBitmapEffectInputConnector

   INHERIT IUnknown

   ' =====================================================================================
   ' IMILBitmapEffectConnectorInfo Methods
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 12
     BYREF puiIndex AS DWORD _                          ' __retval_out ULONG *puiIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptimalFormat ( _                          ' VTable offset = 16
     BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberFormats ( _                          ' VTable offset = 20
     BYREF pulNumberFormats AS DWORD _                  ' __retval_out ULONG *pulNumberFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 24
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMILBitmapEffectConnector Methods
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
     BYREF pfConnected AS INTEGER _                     ' __retval_out VARIANT_BOOL *pfConnected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmapEffect ( _                           ' VTable offset = 32
     BYREF ppEffect AS IMILBitmapEffect _               ' __retval_out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMILBitmapEffectInputConnector Methods
   ' =====================================================================================
   METHOD ConnectTo ( _                                 ' VTable offset = 36
     BYVAL pConnector AS IMILBitmapEffectOutputConnector _ ' __in IMILBitmapEffectOutputConnector *pConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnection ( _                             ' VTable offset = 40
     BYREF ppConnector AS IMILBitmapEffectOutputConnector _ ' __retval_out IMILBitmapEffectOutputConnector **ppConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectInputConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectOutputConnector interface
' IID = 92957AAD-841B-4866-82EC-8752468B07FD
' Inherited interface = IMILBitmapEffectConnector
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectOutputConnector_INTERFACE_DEFINED)
   %IMILBitmapEffectOutputConnector_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectOutputConnector = GUID$("{92957AAD-841B-4866-82EC-8752468B07FD}")

INTERFACE IMILBitmapEffectOutputConnector $IID_IMILBitmapEffectOutputConnector

   INHERIT IUnknown

   ' =====================================================================================
   ' IMILBitmapEffectConnectorInfo Methods
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 12
     BYREF puiIndex AS DWORD _                          ' __retval_out ULONG *puiIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptimalFormat ( _                          ' VTable offset = 16
     BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberFormats ( _                          ' VTable offset = 20
     BYREF pulNumberFormats AS DWORD _                  ' __retval_out ULONG *pulNumberFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 24
     BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pFormat AS GUID _                            ' __retval_out WICPixelFormatGUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMILBitmapEffectConnector Methods
   ' =====================================================================================
   METHOD IsConnected ( _                               ' VTable offset = 28
     BYREF pfConnected AS INTEGER _                     ' __retval_out VARIANT_BOOL *pfConnected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmapEffect ( _                           ' VTable offset = 32
     BYREF ppEffect AS IMILBitmapEffect _               ' __retval_out IMILBitmapEffect **ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMILBitmapEffectOutputConnector Methods
   ' =====================================================================================
   METHOD GetNumberConnections ( _                      ' VTable offset = 36
     BYREF puiNumberConnections AS DWORD _              ' __retval_out ULONG *puiNumberConnections
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnection ( _                             ' VTable offset = 40
     BYVAL DWORD _                                      ' __in ULONG uiIndex
   , BYREF ppConnection AS IMILBitmapEffectInputConnector _ ' __retval_out IMILBitmapEffectInputConnector **ppConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectOutputConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectOutputConnectorImpl interface
' IID = 21FAE777-8B39-4BFA-9F2D-F3941ED36913
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectOutputConnectorImpl_INTERFACE_DEFINED)
   %IMILBitmapEffectOutputConnectorImpl_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectOutputConnectorImpl = GUID$("{21FAE777-8B39-4BFA-9F2D-F3941ED36913}")

INTERFACE IMILBitmapEffectOutputConnectorImpl $IID_IMILBitmapEffectOutputConnectorImpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddBackLink ( _                               ' VTable offset = 12
     BYVAL pConnection AS IMILBitmapEffectInputConnector _ ' IMILBitmapEffectInputConnector *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveBackLink ( _                            ' VTable offset = 16
     BYVAL pConnection AS IMILBitmapEffectInputConnector _ ' IMILBitmapEffectInputConnector *pConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectOutputConnectorImpl_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectInteriorInputConnector interface
' IID = 20287E9E-86A2-4E15-953D-EB1438A5B842
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectInteriorInputConnector_INTERFACE_DEFINED)
   %IMILBitmapEffectInteriorInputConnector_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectInteriorInputConnector = GUID$("{20287E9E-86A2-4E15-953D-EB1438A5B842}")

INTERFACE IMILBitmapEffectInteriorInputConnector $IID_IMILBitmapEffectInteriorInputConnector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputConnector ( _                         ' VTable offset = 12
     BYREF pInputConnector AS IMILBitmapEffectInputConnector _ ' __retval_out IMILBitmapEffectInputConnector **pInputConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectInteriorInputConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectInteriorOutputConnector interface
' IID = 00BBB6DC-ACC9-4BFC-B344-8BEE383DFEFA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectInteriorOutputConnector_INTERFACE_DEFINED)
   %IMILBitmapEffectInteriorOutputConnector_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectInteriorOutputConnector = GUID$("{00BBB6DC-ACC9-4BFC-B344-8BEE383DFEFA}")

INTERFACE IMILBitmapEffectInteriorOutputConnector $IID_IMILBitmapEffectInteriorOutputConnector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOutputConnector ( _                        ' VTable offset = 12
     BYREF pOutputConnector AS IMILBitmapEffectOutputConnector _ ' __retval_out IMILBitmapEffectOutputConnector **pOutputConnector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectInteriorOutputConnector_INTERFACE_DEFINED__ */

' ########################################################################################
' IMILBitmapEffectEvents interface
' IID = 2E880DD8-F8CE-457B-8199-D60BB3D7EF98
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMILBitmapEffectEvents_INTERFACE_DEFINED)
   %IMILBitmapEffectEvents_INTERFACE_DEFINED = 1

$IID_IMILBitmapEffectEvents = GUID$("{2E880DD8-F8CE-457B-8199-D60BB3D7EF98}")

INTERFACE IMILBitmapEffectEvents $IID_IMILBitmapEffectEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PropertyChange ( _                            ' VTable offset = 12
     BYVAL pEffect AS IMILBitmapEffect _                ' __in IMILBitmapEffect *pEffect
   , BYVAL bstrPropertyName AS WSTRING _                ' __in BSTR bstrPropertyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DirtyRegion ( _                               ' VTable offset = 16
     BYVAL pEffect AS IMILBitmapEffect _                ' __in IMILBitmapEffect *pEffect
   , BYVAL pRect AS MIL_RECTD _                         ' __in MIL_RECTD *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMILBitmapEffectEvents_INTERFACE_DEFINED__ */

'#endif /* __MILEffects_LIBRARY_DEFINED__ */
