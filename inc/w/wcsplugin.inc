' ########################################################################################
' Microsoft Windows
' File: wcsplugin.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCSPLUGIN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

'//+-------------------------------------------------------------------------
'//
'//  Copyright (c) Microsoft Corporation.  All rights reserved.
'//
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE XYZColorF DWORD
   X AS SINGLE   ' FLOAT
   Y AS SINGLE   ' FLOAT
   Z AS SINGLE   ' FLOAT
END TYPE

' // Size = 12 bytes
TYPE JChColorF DWORD
   J AS SINGLE   ' FLOAT
   C AS SINGLE   ' FLOAT
   h AS SINGLE   ' FLOAT
END TYPE

' // Size = 12 bytes
TYPE JabColorF DWORD
   J AS SINGLE   ' FLOAT
   a AS SINGLE   ' FLOAT
   b AS SINGLE   ' FLOAT
END TYPE

' // Size = 12 bytes
TYPE GamutShellTriangle DWORD
   aVertexIndex(2) AS DWORD   ' UINT[3]
END TYPE

' // Size = 24 bytes
TYPE GamutShell DWORD
   JMin       AS SINGLE                   ' FLOAT
   JMax       AS SINGLE                   ' FLOAT
   cVertices  AS DWORD                    ' UINT
   cTriangles AS DWORD                    ' UINT
   pVertices  AS JabColorF PTR            ' JabColorF *
   pTriangles AS GamutShellTriangle PTR   ' GamutShellTriangle *
END TYPE

' // Size = 96 bytes
TYPE PrimaryJabColors DWORD
   red     AS JabColorF
   yellow  AS JabColorF
   green   AS JabColorF
   cyan    AS JabColorF
   blue    AS JabColorF
   magenta AS JabColorF
   black   AS JabColorF
   white   AS JabColorF
END TYPE

' // Size = 96 bytes
TYPE PrimaryXYZColors DWORD
   red     AS XYZColorF
   yellow  AS XYZColorF
   green   AS XYZColorF
   cyan    AS XYZColorF
   blue    AS XYZColorF
   magenta AS XYZColorF
   black   AS XYZColorF
   white   AS XYZColorF
END TYPE

' // Size = 24 bytes
TYPE GamutBoundaryDescription DWORD
   pPrimaries      AS PrimaryJabColors PTR   ' PrimaryJabColors *
   cNeutralSamples AS DWORD                  ' UINT
   pNeutralSamples AS JabColorF PTR          ' JabColorF *
   pReferenceShell AS GamutShell PTR         ' GamutShell *
   pPlausibleShell AS GamutShell PTR         ' GamutShell *
   pPossibleShell  AS GamutShell PTR         ' GamutShell *
END TYPE

' // Size = 8 bytes
TYPE BlackInformation DWORD
   fBlackOnly  AS LONG     ' BOOL
   blackWeight AS SINGLE   ' FLOAT
END TYPE

' ########################################################################################
' IDeviceModelPlugIn interface
' IID = 1CD63475-07C4-46FE-A903-D655316D11FD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeviceModelPlugIn_INTERFACE_DEFINED)
    %IDeviceModelPlugIn_INTERFACE_DEFINED = 1

$IID_IDeviceModelPlugIn = GUID$("{1CD63475-07C4-46FE-A903-D655316D11FD}")

INTERFACE IDeviceModelPlugIn $IID_IDeviceModelPlugIn

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL bstrXml AS WSTRING _                         ' __in BSTR bstrXml
   , BYVAL cNumModels AS DWORD _                        ' __in UINT cNumModels
   , BYVAL iModelPosition AS DWORD _                    ' __in UINT iModelPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumChannels ( _                            ' VTable offset = 16
     BYREF pNumChannels AS DWORD _                      ' __out UINT *pNumChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceToColorimetricColors ( _                ' VTable offset = 20
     BYVAL cColors AS DWORD _                           ' __in UINT cColors
   , BYVAL cChannels AS DWORD _                         ' __in UINT cChannels
   , BYREF pDeviceValues AS SINGLE _                    ' __in const FLOAT *pDeviceValues
   , BYREF pXYZColors AS XYZColorF _                    ' __out XYZColorF *pXYZColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ColorimetricToDeviceColors ( _                ' VTable offset = 24
     BYVAL cColors AS DWORD _                           ' __in UINT cColors
   , BYVAL cChannels AS DWORD _                         ' __in UINT cChannels
   , BYREF pXYZColors AS XYZColorF _                    ' __in const XYZColorF *pXYZColors
   , BYREF pDeviceValues AS SINGLE _                    ' __out FLOAT *pDeviceValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ColorimetricToDeviceColorsWithBlack ( _       ' VTable offset = 28
     BYVAL cColors AS DWORD _                           ' __in UINT cColors
   , BYVAL cChannels AS DWORD _                         ' __in UINT cChannels
   , BYREF pXYZColors AS XYZColorF _                    ' __in const XYZColorF *pXYZColors
   , BYREF pBlackInformation AS BlackInformation _      ' __in const BlackInformation *pBlackInformation
   , BYREF pDeviceValues AS SINGLE _                    ' __out FLOAT *pDeviceValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransformDeviceModelInfo ( _               ' VTable offset = 32
     BYVAL iModelPosition AS DWORD _                    ' __in UINT iModelPosition
   , OPTIONAL BYVAL pIDeviceModelOther AS IDeviceModelPlugIn _ ' __in_opt IDeviceModelPlugIn *pIDeviceModelOther
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrimarySamples ( _                         ' VTable offset = 36
     BYREF pPrimaryColor AS PrimaryXYZColors _          ' __out PrimaryXYZColors *pPrimaryColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGamutBoundaryMeshSize ( _                  ' VTable offset = 40
     BYREF pNumVertices AS DWORD _                      ' __out UINT *pNumVertices
   , BYREF pNumTriangles AS DWORD _                     ' __out UINT *pNumTriangles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGamutBoundaryMesh ( _                      ' VTable offset = 44
     BYVAL cChannels AS DWORD _                         ' __in UINT cChannels
   , BYVAL cVertices AS DWORD _                         ' __in UINT cVertices
   , BYVAL cTriangles AS DWORD _                        ' __in UINT cTriangles
   , BYREF pVertices AS SINGLE _                        ' __out FLOAT *pVertices
   , BYREF pTriangles AS GamutShellTriangle _           ' __out GamutShellTriangle *pTriangles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNeutralAxisSize ( _                        ' VTable offset = 48
     BYREF pcColors AS DWORD _                          ' __out UINT *pcColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNeutralAxis ( _                            ' VTable offset = 52
     BYVAL cColors AS DWORD _                           ' __in UINT cColors
   , BYREF pXYZColors AS XYZColorF _                    ' __out XYZColorF *pXYZColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeviceModelPlugIn_INTERFACE_DEFINED__ */

' ########################################################################################
' IGamutMapModelPlugIn interface
' IID = 2DD80115-AD1E-41F6-A219-A4F4B583D1F9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGamutMapModelPlugIn_INTERFACE_DEFINED)
    %IGamutMapModelPlugIn_INTERFACE_DEFINED = 1

$IID_IGamutMapModelPlugIn = GUID$("{2DD80115-AD1E-41F6-A219-A4F4B583D1F9}")

INTERFACE IGamutMapModelPlugIn $IID_IGamutMapModelPlugIn

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL bstrXml AS WSTRING _                         ' __in BSTR bstrXml
   , BYVAL pSrcPlugIn AS IDeviceModelPlugIn _           ' __in_opt IDeviceModelPlugIn *pSrcPlugIn
   , BYVAL pDestPlugIn AS IDeviceModelPlugIn _          ' __in_opt IDeviceModelPlugIn *pDestPlugIn
   , BYREF pSrcGBD AS GamutBoundaryDescription _        ' __in GamutBoundaryDescription *pSrcGBD
   , BYREF pDestGBD AS GamutBoundaryDescription _       ' __in GamutBoundaryDescription *pDestGBD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SourceToDestinationAppearanceColors ( _       ' VTable offset = 16
     BYVAL cColors AS DWORD _                           ' __in UINT cColors
   , BYREF pInputColors AS JChColorF _                  ' __in const JChColorF *pInputColors
   , BYREF pOutputColors AS JChColorF _                 ' __out JChColorF *pOutputColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGamutMapModelPlugIn_INTERFACE_DEFINED__ */
