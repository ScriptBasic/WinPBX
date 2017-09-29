' ########################################################################################
' Microsoft Windows
' File: qedit.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QEDIT_INC = 1

#INCLUDE ONCE "amstream.inc"
#INCLUDE ONCE "dxtrans.inc"

' enum DEXTERF
%DEXTERF_JUMP        = 0
%DEXTERF_INTERPOLATE = %DEXTERF_JUMP + 1

' // Size = 12 bytes
TYPE DEXTER_PARAM DWORD
   Name    AS DWORD   ' BSTR
   dispID  AS LONG    ' DISPID
   nValues AS LONG
END TYPE

' // Size = 32 bytes
TYPE DEXTER_VALUE   ' Must be 8 byte aligned
   v           AS VARIANTAPI   ' VARIANT
   rt          AS QUAD         ' REFERENCE_TIME
   dwInterp    AS DWORD
   alignment__ AS DWORD        ' // To keep 8 byte alignment
END TYPE

' enum __MIDL___MIDL_itf_qedit_0000_0004
%DEXTER_AUDIO_JUMP        = 0
%DEXTER_AUDIO_INTERPOLATE = %DEXTER_AUDIO_JUMP + 1

' // Size = 24 bytes
TYPE DEXTER_AUDIO_VOLUMEENVELOPE QWORD
   rtEnd   AS QUAD     ' REFERENCE_TIME
   dLevel  AS DOUBLE
   bMethod AS LONG
END TYPE

' enum __MIDL___MIDL_itf_qedit_0000_0006
%TIMELINE_INSERT_MODE_INSERT  = 1
%TIMELINE_INSERT_MODE_OVERLAY = 2

' enum TIMELINE_MAJOR_TYPE
%TIMELINE_MAJOR_TYPE_COMPOSITE  = 1
%TIMELINE_MAJOR_TYPE_TRACK      = 2
%TIMELINE_MAJOR_TYPE_SOURCE     = 4
%TIMELINE_MAJOR_TYPE_TRANSITION = 8
%TIMELINE_MAJOR_TYPE_EFFECT     = 16
%TIMELINE_MAJOR_TYPE_GROUP      = 128

' enum DEXTERF_TRACK_SEARCH_FLAGS
%DEXTERF_BOUNDING   = -1
%DEXTERF_EXACTLY_AT = 0
%DEXTERF_FORWARDS   = 1

' // Size = 76 bytes
TYPE SCompFmt0 DWORD
   nFormatId AS LONG
   MediaType AS AM_MEDIA_TYPE
END TYPE

' enum __MIDL___MIDL_itf_qedit_0000_0009
%RESIZEF_STRETCH = 0
%RESIZEF_CROP = %RESIZEF_STRETCH + 1
%RESIZEF_PRESERVEASPECTRATIO = %RESIZEF_CROP + 1
%RESIZEF_PRESERVEASPECTRATIO_NOLETTERBOX = %RESIZEF_PRESERVEASPECTRATIO + 1

' enum __MIDL___MIDL_itf_qedit_0000_0010
%CONNECTF_DYNAMIC_NONE    = 0
%CONNECTF_DYNAMIC_SOURCES = &H1
%CONNECTF_DYNAMIC_EFFECTS = &H2

' enum __MIDL___MIDL_itf_qedit_0000_0011
%SFN_VALIDATEF_CHECK       = &H1
%SFN_VALIDATEF_POPUP       = &H2
%SFN_VALIDATEF_TELLME      = &H4
%SFN_VALIDATEF_REPLACE     = &H8
%SFN_VALIDATEF_USELOCAL    = &H10
%SFN_VALIDATEF_NOFIND      = &H20
%SFN_VALIDATEF_IGNOREMUTED = &H40
%SFN_VALIDATEF_END         = %SFN_VALIDATEF_IGNOREMUTED + 1

' enum __MIDL___MIDL_itf_qedit_0000_0012
%DXTKEY_RGB       = 0
%DXTKEY_NONRED    = %DXTKEY_RGB       + 1
%DXTKEY_LUMINANCE = %DXTKEY_NONRED    + 1
%DXTKEY_ALPHA     = %DXTKEY_LUMINANCE + 1
%DXTKEY_HUE       = %DXTKEY_ALPHA     + 1

' enum __MIDL___MIDL_itf_qedit_0495_0001
%E_NOTINTREE                  = &H80040400
%E_RENDER_ENGINE_IS_BROKEN    = &H80040401
%E_MUST_INIT_RENDERER         = &H80040402
%E_NOTDETERMINED              = &H80040403
%E_NO_TIMELINE                = &H80040404
%S_WARN_OUTPUTRESET           = 40404

%DEX_IDS_BAD_SOURCE_NAME      = 1400
%DEX_IDS_BAD_SOURCE_NAME2     = 1401
%DEX_IDS_MISSING_SOURCE_NAME  = 1402
%DEX_IDS_UNKNOWN_SOURCE       = 1403
%DEX_IDS_INSTALL_PROBLEM      = 1404
%DEX_IDS_NO_SOURCE_NAMES      = 1405
%DEX_IDS_BAD_MEDIATYPE        = 1406
%DEX_IDS_STREAM_NUMBER        = 1407
%DEX_IDS_OUTOFMEMORY          = 1408
%DEX_IDS_DIBSEQ_NOTALLSAME    = 1409
%DEX_IDS_CLIPTOOSHORT         = 1410
%DEX_IDS_INVALID_DXT          = 1411
%DEX_IDS_INVALID_DEFAULT_DXT  = 1412
%DEX_IDS_NO_3D                = 1413
%DEX_IDS_BROKEN_DXT           = 1414
%DEX_IDS_NO_SUCH_PROPERTY     = 1415
%DEX_IDS_ILLEGAL_PROPERTY_VAL = 1416
%DEX_IDS_INVALID_XML          = 1417
%DEX_IDS_CANT_FIND_FILTER     = 1418
%DEX_IDS_DISK_WRITE_ERROR     = 1419
%DEX_IDS_INVALID_AUDIO_FX     = 1420
%DEX_IDS_CANT_FIND_COMPRESSOR = 1421
%DEX_IDS_TIMELINE_PARSE       = 1426
%DEX_IDS_GRAPH_ERROR          = 1427
%DEX_IDS_GRID_ERROR           = 1428
%DEX_IDS_INTERFACE_ERROR      = 1429

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_qeditDxtAlphaSetter1    = "qedit.DxtAlphaSetter.1"
$PROGID_qeditDxtCompositor1     = "qedit.DxtCompositor.1"
$PROGID_qeditDxtJpeg1           = "qedit.DxtJpeg.1"
$PROGID_qeditDxtKey1            = "qedit.DxtKey.1"
$PROGID_qeditMediaLocator1      = "qedit.MediaLocator.1"
$PROGID_qeditRenderEngine1      = "qedit.RenderEngine.1"
$PROGID_qeditSmartRenderEngine1 = "qedit.SmartRenderEngine.1"
$PROGID_qeditXml2Dex1           = "qedit.Xml2Dex.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

$PROGID_qeditDxtAlphaSetter     = "qedit.DxtAlphaSetter"
$PROGID_qeditDxtCompositor      = "qedit.DxtCompositor"
$PROGID_qeditDxtJpeg            = "qedit.DxtJpeg"
$PROGID_qeditDxtKey             = "qedit.DxtKey"
$PROGID_qeditMediaLocator       = "qedit.MediaLocator"
$PROGID_qeditRenderEngine       = "qedit.RenderEngine"
$PROGID_qeditSmartRenderEngine  = "qedit.SmartRenderEngine"
$PROGID_qeditXml2Dex            = "qedit.Xml2Dex"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AMTimeline              = GUID$("{78530B75-61F9-11D2-8CAD-00A024580902}")
$CLSID_AMTimelineComp          = GUID$("{74D2EC80-6233-11D2-8CAD-00A024580902}")
$CLSID_AMTimelineEffect        = GUID$("{74D2EC82-6233-11D2-8CAD-00A024580902}")
$CLSID_AMTimelineGroup         = GUID$("{F6D371E1-B8A6-11D2-8023-00C0DF10D434}")
$CLSID_AMTimelineObj           = GUID$("{78530B78-61F9-11D2-8CAD-00A024580902}")
$CLSID_AMTimelineSrc           = GUID$("{78530B7A-61F9-11D2-8CAD-00A024580902}")
$CLSID_AMTimelineTrack         = GUID$("{8F6C3C50-897B-11D2-8CFB-00A0C9441E20}")
$CLSID_AMTimelineTrans         = GUID$("{74D2EC81-6233-11D2-8CAD-00A024580902}")
$CLSID_AudMixer                = GUID$("{036A9790-C153-11D2-9EF7-006008039E37}")
$CLSID_ColorSource             = GUID$("{0CFDD070-581A-11D2-9EE6-006008039E37}")
$CLSID_MediaDet                = GUID$("{65BD0711-24D2-4FF7-9324-ED2E5D3ABAFA}")
$CLSID_NullRenderer            = GUID$("{C1F400A4-3F08-11D3-9F0B-006008039E37}")
$CLSID_PropertySetter          = GUID$("{ADF95821-DED7-11D2-ACBE-0080C75E246E}")
$CLSID_SampleGrabber           = GUID$("{C1F400A0-3F08-11D3-9F0B-006008039E37}")
$CLSID_DxtAlphaSetter          = GUID$("{506D89AE-909A-44F7-9444-ABD575896E35}")
$CLSID_DxtCompositor           = GUID$("{BB44391D-6ABD-422F-9E2E-385C9DFF51FC}")
$CLSID_DxtJpeg                 = GUID$("{DE75D012-7A65-11D2-8CEA-00A0C9441E20}")
$CLSID_DxtKey                  = GUID$("{C5B19592-145E-11D3-9F04-006008039E37}")
$CLSID_MediaLocator            = GUID$("{CC1101F2-79DC-11D2-8CE6-00A0C9441E20}")
$CLSID_RenderEngine            = GUID$("{64D8A8E0-80A2-11D2-8CF3-00A0C9441E20}")
$CLSID_SmartRenderEngine       = GUID$("{498B0949-BBE9-4072-98BE-6CCAEB79DC6F}")
$CLSID_Xml2Dex                 = GUID$("{18C628EE-962A-11D2-8D08-00A0C9441E20}")

$CLSID_VideoEffects1Category   = GUID$("{CC7BFB42-F175-11D1-A392-00E0291F3959}")
$CLSID_VideoEffects2Category   = GUID$("{CC7BFB43-F175-11D1-A392-00E0291F3959}")
$CLSID_AudioEffects1Category   = GUID$("{CC7BFB44-F175-11D1-A392-00E0291F3959}")
$CLSID_AudioEffects2Category   = GUID$("{CC7BFB45-F175-11D1-A392-00E0291F3959}")


' ########################################################################################
' Interface name = IPropertySetter
' IID = {AE9472BD-B0C3-11D2-8D24-00A0C9441E20}
' IPropertySetter Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertySetter_INTERFACE_DEFINED)
    %IPropertySetter_FWD_DEFINED = 1

$IID_IPropertySetter = GUID$("{AE9472BD-B0C3-11D2-8D24-00A0C9441E20}")

INTERFACE IPropertySetter $IID_IPropertySetter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadXML ( _                                   ' VTable offset = 12
     BYVAL pxml AS IUnknown _                           ' __in IUnknown *pxml
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrintXML ( _                                  ' VTable offset = 16
     BYVAL pszXML AS DWORD _                            ' __out char *pszXML
   , BYVAL cbXML AS LONG _                              ' __in int cbXML
   , BYREF pcbPrinted AS LONG _                         ' __out int *pcbPrinted
   , BYVAL indent AS LONG _                             ' __in int indent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneProps ( _                                ' VTable offset = 20
     BYREF ppSetter AS IPropertySetter _                ' __out IPropertySetter **ppSetter
   , BYVAL rtStart AS QUAD _                            ' __in REFERENCE_TIME rtStart
   , BYVAL rtStop AS QUAD _                             ' __in REFERENCE_TIME rtStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddProp ( _                                   ' VTable offset = 24
     BYREF Param AS DEXTER_PARAM _                      ' __in DEXTER_PARAM Param
   , BYREF paValue AS DEXTER_VALUE _                    ' __in DEXTER_VALUE *paValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProps ( _                                  ' VTable offset = 28
     BYREF pcParams AS LONG _                           ' __out LONG *pcParams
   , BYREF paParam AS DEXTER_PARAM _                    ' __out DEXTER_PARAM **paParam
   , BYREF paValue AS DEXTER_VALUE _                    ' __out DEXTER_VALUE **paValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeProps ( _                                 ' VTable offset = 32
     BYVAL cParams AS LONG _                            ' __in LONG cParams
   , BYREF paParam AS DEXTER_PARAM _                    ' __in DEXTER_PARAM *paParam
   , BYREF paValue AS DEXTER_VALUE _                    ' __in DEXTER_VALUE *paValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearProps ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveToBlob ( _                                ' VTable offset = 40
     BYREF pcSize AS LONG _                             ' __out LONG *pcSize
   , BYREF ppb AS DWORD _                               ' __out BYTE **ppb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadFromBlob ( _                              ' VTable offset = 44
     BYVAL cSize AS LONG _                              ' __in LONG cSize
   , BYVAL pb AS BYTE PTR _                             ' __in BYTE *pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProps ( _                                  ' VTable offset = 48
     BYVAL pTarget AS IUnknown _                        ' __in IUnknown *pTarget
   , BYVAL rtNow AS QUAD _                              ' __in REFERENCE_TIME rtNow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrintXMLW ( _                                 ' VTable offset = 52
     BYREF pszXML AS DWORD _                            ' __out WCHAR *pszXML
   , BYVAL cchXML AS LONG _                             ' __in int cchXML
   , BYREF pcchPrinted AS LONG _                        ' __out int *pcchPrinted
   , BYVAL indent AS LONG _                             ' __in int indent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertySetter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDxtCompositor
' IID = {BB44391E-6ABD-422F-9E2E-385C9DFF51FC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDXEffect
' ########################################################################################

#IF NOT %DEF(%IDxtCompositor_INTERFACE_DEFINED)
    %IDxtCompositor_INTERFACE_DEFINED = 1

$IID_IDxtCompositor = GUID$("{BB44391E-6ABD-422F-9E2E-385C9DFF51FC}")

INTERFACE IDxtCompositor $IID_IDxtCompositor

   INHERIT IDispatch

   ' =====================================================================================
   ' IDXEffect Methods
   ' =====================================================================================
   PROPERTY GET Capabilities <10000> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Progress <10001> ( _                    ' VTable offset = 32
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Progress <10001> ( _                    ' VTable offset = 36
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepResolution <10002> ( _              ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY GET Duration <10003> ( _                    ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <10003> ( _                    ' VTable offset = 48
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDxtCompositor Methods
   ' =====================================================================================
   PROPERTY GET OffsetX <1> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET OffsetX <1> ( _                         ' VTable offset = 56
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OffsetY <2> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET OffsetY <2> ( _                         ' VTable offset = 64
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <3> ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Width <3> ( _                           ' VTable offset = 72
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <4> ( _                          ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Height <4> ( _                          ' VTable offset = 80
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SrcOffsetX <5> ( _                      ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SrcOffsetX <5> ( _                      ' VTable offset = 88
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SrcOffsetY <6> ( _                      ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SrcOffsetY <6> ( _                      ' VTable offset = 96
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SrcWidth <7> ( _                        ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SrcWidth <7> ( _                        ' VTable offset = 104
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SrcHeight <8> ( _                       ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SrcHeight <8> ( _                       ' VTable offset = 112
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDxtCompositor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDxtAlphaSetter
' IID = {4EE9EAD9-DA4D-43D0-9383-06B90C08B12B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDXEffect
' ########################################################################################

#IF NOT %DEF(%IDxtAlphaSetter_INTERFACE_DEFINED)
    %IDxtAlphaSetter_INTERFACE_DEFINED = 1

$IID_IDxtAlphaSetter = GUID$("{4EE9EAD9-DA4D-43D0-9383-06B90C08B12B}")

INTERFACE IDxtAlphaSetter $IID_IDxtAlphaSetter

   INHERIT IDispatch

   ' =====================================================================================
   ' IDXEffect Methods
   ' =====================================================================================
   PROPERTY GET Capabilities <10000> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Progress <10001> ( _                    ' VTable offset = 32
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Progress <10001> ( _                    ' VTable offset = 36
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepResolution <10002> ( _              ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY GET Duration <10003> ( _                    ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <10003> ( _                    ' VTable offset = 48
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDxtAlphaSetter Methods
   ' =====================================================================================
   PROPERTY GET Alpha <1> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Alpha <1> ( _                           ' VTable offset = 56
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AlphaRamp <2> ( _                       ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out double *pVal
   ' =====================================================================================
   PROPERTY SET AlphaRamp <2> ( _                       ' VTable offset = 64
     BYVAL newVal AS DOUBLE _                           ' __in double newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDxtAlphaSetter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDxtJpeg
' IID = {DE75D011-7A65-11D2-8CEA-00A0C9441E20}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDXEffect
' ########################################################################################

#IF NOT %DEF(%IDxtJpeg_INTERFACE_DEFINED)
    %IDxtJpeg_INTERFACE_DEFINED = 1

$IID_IDxtJpeg = GUID$("{DE75D011-7A65-11D2-8CEA-00A0C9441E20}")

INTERFACE IDxtJpeg $IID_IDxtJpeg

   INHERIT IDispatch

   ' =====================================================================================
   ' IDXEffect Methods
   ' =====================================================================================
   PROPERTY GET Capabilities <10000> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Progress <10001> ( _                    ' VTable offset = 32
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Progress <10001> ( _                    ' VTable offset = 36
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepResolution <10002> ( _              ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY GET Duration <10003> ( _                    ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <10003> ( _                    ' VTable offset = 48
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDxtJpeg Methods
   ' =====================================================================================
   PROPERTY GET MaskNum <1> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET MaskNum <1> ( _                         ' VTable offset = 56
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaskName <2> ( _                        ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET MaskName <2> ( _                        ' VTable offset = 64
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleX <3> ( _                          ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out double *pVal
   ' =====================================================================================
   PROPERTY SET ScaleX <3> ( _                          ' VTable offset = 72
     BYVAL newVal AS DOUBLE _                           ' __in double newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ScaleY <4> ( _                          ' VTable offset = 76
   ) AS DOUBLE                                          ' __retval_out double *pVal
   ' =====================================================================================
   PROPERTY SET ScaleY <4> ( _                          ' VTable offset = 80
     BYVAL DOUBLE _                                     ' __in double newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OffsetX <5> ( _                         ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET OffsetX <5> ( _                         ' VTable offset = 88
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OffsetY <6> ( _                         ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET OffsetY <6> ( _                         ' VTable offset = 96
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplicateX <7> ( _                      ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET ReplicateX <7> ( _                      ' VTable offset = 104
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReplicateY <8> ( _                      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET ReplicateY <8> ( _                      ' VTable offset = 112
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderColor <9> ( _                     ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET BorderColor <9> ( _                     ' VTable offset = 120
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderWidth <10> ( _                    ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET BorderWidth <10> ( _                    ' VTable offset = 128
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderSoftness <11> ( _                 ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET BorderSoftness <11> ( _                 ' VTable offset = 136
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD ApplyChanges <1610809366> ( _                 ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadDefSettings <1610809367> ( _              ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDxtJpeg_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDxtKey
' IID = {3255DE56-38FB-4901-B980-94B438010D7B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDXEffect
' ########################################################################################

#IF NOT %DEF(%IDxtKey_INTERFACE_DEFINED)
    %IDxtKey_INTERFACE_DEFINED = 1

$IID_IDxtKey = GUID$("{3255DE56-38FB-4901-B980-94B438010D7B}")

INTERFACE IDxtKey $IID_IDxtKey

   INHERIT IDispatch

   ' =====================================================================================
   ' IDXEffect Methods
   ' =====================================================================================
   PROPERTY GET Capabilities <10000> ( _                ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Progress <10001> ( _                    ' VTable offset = 32
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Progress <10001> ( _                    ' VTable offset = 36
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepResolution <10002> ( _              ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY GET Duration <10003> ( _                    ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <10003> ( _                    ' VTable offset = 48
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IDxtKey Methods
   ' =====================================================================================
   PROPERTY GET KeyType <1> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out int *pVal
   ' =====================================================================================
   PROPERTY SET KeyType <1> ( _                         ' VTable offset = 56
     BYVAL newVal AS LONG _                             ' int newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hue <2> ( _                             ' VTable offset = 60
   ) AS LONG                                            ' __retval_out int *pVal
   ' =====================================================================================
   PROPERTY SET Hue <2> ( _                             ' VTable offset = 64
     BYVAL newVal AS LONG _                             ' __in int newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Luminance <3> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out int *pVal
   ' =====================================================================================
   PROPERTY SET Luminance <3> ( _                       ' VTable offset = 72
     BYVAL newVal AS LONG _                             ' __in int newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RGB <4> ( _                             ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out DWORD *pVal
   ' =====================================================================================
   PROPERTY SET RGB <4> ( _                             ' VTable offset = 80
     BYVAL newVal AS DWORD _                            ' __in DWORD newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Similarity <5> ( _                      ' VTable offset = 84
   ) AS LONG                                            ' __retval_out int *pVal
   ' =====================================================================================
   PROPERTY SET Similarity <5> ( _                      ' VTable offset = 88
     BYVAL newVal AS LONG _                             ' __in int newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Invert <6> ( _                          ' VTable offset = 92
   ) AS LONG                                            ' __retval_out BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Invert <6> ( _                          ' VTable offset = 96
     BYVAL newVal AS LONG _                             ' __in BOOL newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDxtKey_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMediaLocator
' IID = {288581E0-66CE-11D2-918F-00C0DF10D434}
' IMediaLocator Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaLocator_INTERFACE_DEFINED)
    %IMediaLocator_INTERFACE_DEFINED = 1

$IID_IMediaLocator = GUID$("{288581E0-66CE-11D2-918F-00C0DF10D434}")

INTERFACE IMediaLocator $IID_IMediaLocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindMediaFile ( _                             ' VTable offset = 12
     BYVAL Input AS WSTRING _                           ' __in  BSTR Input
   , BYVAL FilterString AS WSTRING _                    ' __in  BSTR FilterString
   , BYREF pOutput AS WSTRING _                         ' __out BSTR *pOutput
   , BYVAL Flags AS LONG _                              ' __in  long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFoundLocation ( _                          ' VTable offset = 16
     BYVAL DirectoryName AS WSTRING _                   ' __in BSTR DirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaLocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMediaDet
' IID = {65BD0710-24D2-4FF7-9324-ED2E5D3ABAFA}
' IMediaDet Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaDet_INTERFACE_DEFINED)
    %IMediaDet_INTERFACE_DEFINED = 1

$IID_IMediaDet = GUID$("{65BD0710-24D2-4FF7-9324-ED2E5D3ABAFA}")

INTERFACE IMediaDet $IID_IMediaDet

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Filter ( _                              ' VTable offset = 12
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY SET Filter ( _                              ' VTable offset = 16
     BYVAL newVal AS IUnknown _                         ' __in IUnknown *newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutputStreams ( _                       ' VTable offset = 20
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentStream ( _                       ' VTable offset = 24
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentStream ( _                       ' VTable offset = 28
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StreamType ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out GUID *pVal
   ' =====================================================================================
   PROPERTY GET StreamTypeB ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET StreamLength ( _                        ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out double *pVal
   ' =====================================================================================
   PROPERTY GET Filename ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Filename ( _                            ' VTable offset = 48
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetBitmapBits ( _                             ' VTable offset = 52
     BYVAL StreamTime AS DOUBLE _                       ' __in  double StreamTime
   , BYREF pBufferSize AS LONG _                        ' __out long *pBufferSize
   , BYVAL pBuffer AS BYTE PTR _                        ' __in  char *pBuffer
   , BYVAL Width AS LONG _                              ' __in  long Width
   , BYVAL Height AS LONG _                             ' __in  long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteBitmapBits ( _                           ' VTable offset = 56
     BYVAL StreamTime AS DOUBLE _                       ' __in double StreamTime
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   , BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StreamMediaType ( _                     ' VTable offset = 60
   ) AS AM_MEDIA_TYPE                                   ' __retval_out AM_MEDIA_TYPE *pVal
   ' =====================================================================================
   METHOD GetSampleGrabber ( _                          ' VTable offset = 64
     BYREF ppVal AS ISampleGrabber _                    ' __out ISampleGrabber **ppVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrameRate ( _                           ' VTable offset = 68
   ) AS DOUBLE                                          ' __retval_out double *pVal
   ' =====================================================================================
   METHOD EnterBitmapGrabMode ( _                       ' VTable offset = 72
     BYVAL SeekTime AS DOUBLE _                         ' __in double SeekTime
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaDet_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGrfCache
' IID = {AE9472BE-B0C3-11D2-8D24-00A0C9441E20}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IGrfCache_INTERFACE_DEFINED)
    %IGrfCache_INTERFACE_DEFINED = 1

$IID_IGrfCache = GUID$("{AE9472BE-B0C3-11D2-8D24-00A0C9441E20}")

INTERFACE IGrfCache $IID_IGrfCache

   INHERIT IDispatch

   ' =====================================================================================
   METHOD AddFilter <1> ( _                             ' VTable offset = 28
     BYVAL ChainedCache AS IGrfCache _                  ' __in IGrfCache *ChainedCache
   , BYVAL ID AS QUAD _                                 ' __in LONGLONG ID
   , BYVAL pFilter AS IBaseFilter _                     ' __in const IBaseFilter *pFilter
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectPins ( _                               ' VTable offset = 32
     BYVAL ChainedCache AS IGrfCache _                  ' __in IGrfCache *ChainedCache
   , BYVAL PinID1 AS QUAD _                             ' __in LONGLONG PinID1
   , BYVAL pPin1 AS IPin _                              ' __in const IPin *pPin1
   , BYVAL PinID2 AS QUAD _                             ' __in LONGLONG PinID2
   , BYVAL pPin2 AS IPin _                              ' __in const IPin *pPin2
   )                                                    ' void
   ' =====================================================================================
   METHOD SetGraph ( _                                  ' VTable offset = 36
     BYVAL pGraph AS IGraphBuilder _                    ' __in const IGraphBuilder *pGraph
   )                                                    ' void
   ' =====================================================================================
   METHOD DoConnectionsNow ( _                          ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGrfCache_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRenderEngine
' IID = {6BEE3A81-66C9-11D2-918F-00C0DF10D434}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRenderEngine_INTERFACE_DEFINED)
    %IRenderEngine_INTERFACE_DEFINED = 1

$IID_IRenderEngine = GUID$("{6BEE3A81-66C9-11D2-918F-00C0DF10D434}")

INTERFACE IRenderEngine $IID_IRenderEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTimelineObject ( _                         ' VTable offset = 12
     BYVAL pTimeline AS IAMTimeline _                   ' __in IAMTimeline *pTimeline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimelineObject ( _                         ' VTable offset = 16
     BYREF ppTimeline AS IAMTimeline _                  ' __out IAMTimeline **ppTimeline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterGraph ( _                            ' VTable offset = 20
     BYREF ppFG AS IGraphBuilder _                      ' __out IGraphBuilder **ppFG
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilterGraph ( _                            ' VTable offset = 24
     BYVAL pFG AS IGraphBuilder _                       ' __in IGraphBuilder *pFG
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterestRange ( _                          ' VTable offset = 28
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterestRange2 ( _                         ' VTable offset = 32
     BYVAL Start AS DOUBLE _                            ' __in double Start
   , BYVAL Stop AS DOUBLE _                             ' __in double Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderRange ( _                            ' VTable offset = 36
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderRange2 ( _                           ' VTable offset = 40
     BYVAL Start AS DOUBLE _                            ' __in double Start
   , BYVAL Stop AS DOUBLE _                             ' __in double Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupOutputPin ( _                         ' VTable offset = 44
     BYVAL Group AS LONG _                              ' __in  long Group
   , BYREF ppRenderPin AS IPin _                        ' __out IPin **ppRenderPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScrapIt ( _                                   ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderOutputPins ( _                          ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorString ( _                           ' VTable offset = 56
     BYREF pVendorID AS WSTRING _                       ' __retval_out BSTR *pVendorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectFrontEnd ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSourceConnectCallback ( _                  ' VTable offset = 64
     BYVAL pCallback AS IGrfCache _                     ' __in IGrfCache *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDynamicReconnectLevel ( _                  ' VTable offset = 68
     BYVAL Level AS LONG _                              ' __in long Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoSmartRecompression ( _                      ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UseInSmartRecompressionGraph ( _              ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSourceNameValidation ( _                   ' VTable offset = 80
     BYVAL FilterString AS WSTRING _                    ' __in BSTR FilterString
   , BYVAL pOverride AS IMediaLocator _                 ' __in IMediaLocator *pOverride
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Decommit ( _                                  ' VTable offset = 88
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 92
     BYVAL Index AS LONG _                              ' __in  long Index
   , BYREF pReturn AS LONG _                            ' __out long *pReturn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRenderEngine_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRenderEngine2
' IID = {6BEE3A82-66C9-11D2-918F-00C0DF10D434}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRenderEngine2_INTERFACE_DEFINED)
    %IRenderEngine2_INTERFACE_DEFINED = 1

$IID_IRenderEngine2 = GUID$("{6BEE3A82-66C9-11D2-918F-00C0DF10D434}")

INTERFACE IRenderEngine2 $IID_IRenderEngine2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetResizerGUID ( _                            ' VTable offset = 12
     BYREF ResizerGuid AS GUID _                        ' __in GUID ResizerGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRenderEngine2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFindCompressorCB
' IID = {F03FA8DE-879A-4D59-9B2C-26BB1CF83461}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFindCompressorCB_INTERFACE_DEFINED)
    %IFindCompressorCB_INTERFACE_DEFINED = 1

$IID_IFindCompressorCB = GUID$("{F03FA8DE-879A-4D59-9B2C-26BB1CF83461}")

INTERFACE IFindCompressorCB $IID_IFindCompressorCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCompressor ( _                             ' VTable offset = 12
     BYREF pType AS AM_MEDIA_TYPE _                     ' __in  AM_MEDIA_TYPE *pType
   , BYREF pCompType AS AM_MEDIA_TYPE _                 ' __in  AM_MEDIA_TYPE *pCompType
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFindCompressorCB_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISmartRenderEngine
' IID = {F03FA8CE-879A-4D59-9B2C-26BB1CF83461}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISmartRenderEngine_INTERFACE_DEFINED)
    %ISmartRenderEngine_INTERFACE_DEFINED = 1

$IID_ISmartRenderEngine = GUID$("{F03FA8CE-879A-4D59-9B2C-26BB1CF83461}")

INTERFACE ISmartRenderEngine $IID_ISmartRenderEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGroupCompressor ( _                        ' VTable offset = 12
     BYVAL Group AS LONG _                              ' __in long Group
   , BYVAL pCompressor AS IBaseFilter _                 ' __in IBaseFilter *pCompressor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupCompressor ( _                        ' VTable offset = 16
     BYVAL Group AS LONG _                              ' __in  long Group
   , BYREF pCompressor AS IBaseFilter _                 ' __out IBaseFilter **pCompressor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFindCompressorCB ( _                       ' VTable offset = 20
     BYVAL pCallback AS IFindCompressorCB _             ' __in IFindCompressorCB *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISmartRenderEngine_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineObj
' IID = {78530B77-61F9-11D2-8CAD-00A024580902}
' IAMTimelineObj Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineObj_INTERFACE_DEFINED)
    %IAMTimelineObj_INTERFACE_DEFINED = 1

$IID_IAMTimelineObj = GUID$("{78530B77-61F9-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineObj $IID_IAMTimelineObj

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStartStop ( _                              ' VTable offset = 12
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartStop2 ( _                             ' VTable offset = 16
     BYREF pStart AS DOUBLE _                           ' __out REFTIME *pStart
   , BYREF pStop AS DOUBLE _                            ' __out REFTIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FixTimes ( _                                  ' VTable offset = 20
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FixTimes2 ( _                                 ' VTable offset = 24
     BYREF pStart AS DOUBLE _                           ' __out REFTIME *pStart
   , BYREF pStop AS DOUBLE _                            ' __out REFTIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStartStop ( _                              ' VTable offset = 28
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStartStop2 ( _                             ' VTable offset = 32
     BYVAL Start AS DOUBLE _                            ' __in REFTIME Start
   , BYVAL Stop AS DOUBLE _                             ' __in REFTIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertySetter ( _                         ' VTable offset = 36
     BYREF pVal AS IPropertySetter _                    ' __retval_out IPropertySetter **pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertySetter ( _                         ' VTable offset = 40
     BYVAL newVal AS IPropertySetter _                  ' __in IPropertySetter *newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubObject ( _                              ' VTable offset = 44
     BYREF pVal AS IUnknown _                           ' __retval_out IUnknown **pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubObject ( _                              ' VTable offset = 48
     BYVAL newVal AS IUnknown _                         ' __in IUnknown *newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubObjectGUID ( _                          ' VTable offset = 52
     BYREF newVal AS GUID _                             ' __in GUID newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubObjectGUIDB ( _                         ' VTable offset = 56
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubObjectGUID ( _                          ' VTable offset = 60
     BYREF pVal AS GUID _                               ' __out GUID *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubObjectGUIDB ( _                         ' VTable offset = 64
     BYREF pVal AS WSTRING _                            ' __retval_out BSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubObjectLoaded ( _                        ' VTable offset = 68
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimelineType ( _                           ' VTable offset = 72
     BYREF pVal AS LONG _                               ' __out TIMELINE_MAJOR_TYPE *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimelineType ( _                           ' VTable offset = 76
     BYVAL newVal AS LONG _                             ' __in TIMELINE_MAJOR_TYPE newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserID ( _                                 ' VTable offset = 80
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUserID ( _                                 ' VTable offset = 84
     BYVAL newVal AS LONG _                             ' __in long newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGenID ( _                                  ' VTable offset = 88
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserName ( _                               ' VTable offset = 92
     BYREF pVal AS WSTRING _                            ' __retval_out BSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUserName ( _                               ' VTable offset = 96
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUserData ( _                               ' VTable offset = 100
     BYVAL pData AS BYTE PTR _                          ' __in_out BYTE *pData
   , BYREF pSize AS LONG _                              ' __out long *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUserData ( _                               ' VTable offset = 104
     BYVAL pData AS BYTE PTR _                          ' __in BYTE *pData
   , BYVAL Size AS LONG _                               ' __in long Size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMuted ( _                                  ' VTable offset = 108
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMuted ( _                                  ' VTable offset = 112
     BYVAL newVal AS LONG _                             ' __in BOOL newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocked ( _                                 ' VTable offset = 116
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocked ( _                                 ' VTable offset = 120
     BYVAL newVal AS LONG _                             ' __in BOOL newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirtyRange ( _                             ' VTable offset = 124
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirtyRange2 ( _                            ' VTable offset = 128
     BYREF pStart AS DOUBLE _                           ' __out REFTIME *pStart
   , BYREF pStop AS DOUBLE _                            ' __out REFTIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirtyRange ( _                             ' VTable offset = 132
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirtyRange2 ( _                            ' VTable offset = 136
     BYVAL Start AS DOUBLE _                            ' __in REFTIME Start
   , BYVAL Stop AS DOUBLE _                             ' __in REFTIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearDirty ( _                                ' VTable offset = 140
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 144
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 148
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimelineNoRef ( _                          ' VTable offset = 152
     BYREF ppResult AS IAMTimeline _                    ' __out IAMTimeline **ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupIBelongTo ( _                         ' VTable offset = 156
     BYREF ppGroup AS IAMTimelineGroup _                ' __out IAMTimelineGroup **ppGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEmbedDepth ( _                             ' VTable offset = 160
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineObj_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineEffectable
' IID = {EAE58537-622E-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineEffectable_INTERFACE_DEFINED)
    %IAMTimelineEffectable_INTERFACE_DEFINED = 1

$IID_IAMTimelineEffectable = GUID$("{EAE58537-622E-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineEffectable $IID_IAMTimelineEffectable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EffectInsBefore ( _                           ' VTable offset = 12
     BYVAL pFX AS IAMTimelineObj _                      ' __in IAMTimelineObj *pFX
   , BYVAL priority AS LONG _                           ' __in long priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EffectSwapPriorities ( _                      ' VTable offset = 16
     BYVAL PriorityA AS LONG _                          ' __in long PriorityA
   , BYVAL PriorityB AS LONG _                          ' __in long PriorityB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EffectGetCount ( _                            ' VTable offset = 20
     BYREF pCount AS LONG _                             ' __in long *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffect ( _                                 ' VTable offset = 24
     BYREF ppFx AS IAMTimelineObj _                     ' __out IAMTimelineObj **ppFx
   , BYVAL Which AS LONG _                              ' __in long Which
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineEffectable_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineEffect
' IID = {BCE0C264-622D-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineEffect_INTERFACE_DEFINED)
    %IAMTimelineEffect_INTERFACE_DEFINED = 1

$IID_IAMTimelineEffect = GUID$("{BCE0C264-622D-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineEffect $IID_IAMTimelineEffect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EffectGetPriority ( _                         ' VTable offset = 12
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineEffect_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineTransable
' IID = {378FA386-622E-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineTransable_INTERFACE_DEFINED)
    %IAMTimelineTransable_INTERFACE_DEFINED = 1

$IID_IAMTimelineTransable = GUID$("{378FA386-622E-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineTransable $IID_IAMTimelineTransable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TransAdd ( _                                  ' VTable offset = 12
     BYVAL pTrans AS IAMTimelineObj _                   ' __in IAMTimelineObj *pTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransGetCount ( _                             ' VTable offset = 16
     BYREF pCount AS LONG _                             ' __out long *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTrans ( _                              ' VTable offset = 20
     BYREF ppTrans AS IAMTimelineObj _                  ' __out IAMTimelineObj **ppTrans
   , BYREF pInOut AS QUAD _                             ' __out REFERENCE_TIME *pInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextTrans2 ( _                             ' VTable offset = 24
     BYREF ppTrans AS IAMTimelineObj _                  ' __out IAMTimelineObj **ppTrans
   , BYREF pInOut AS DOUBLE _                           ' __out REFTIME *pInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransAtTime ( _                            ' VTable offset = 28
     BYREF ppObj AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppObj
   , BYVAL Time AS QUAD _                               ' __in REFERENCE_TIME Time
   , BYVAL SearchDirection AS LONG _                    ' __in long SearchDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransAtTime2 ( _                           ' VTable offset = 32
     BYREF ppObj AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppObj
   , BYVAL Time AS DOUBLE _                             ' __in REFTIME Time
   , BYVAL SearchDirection AS LONG _                    ' __in long SearchDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineTransable_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineSplittable
' IID = {A0F840A0-D590-11D2-8D55-00A0C9441E20}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineSplittable_INTERFACE_DEFINED)
    %IAMTimelineSplittable_INTERFACE_DEFINED = 1

$IID_IAMTimelineSplittable = GUID$("{A0F840A0-D590-11D2-8D55-00A0C9441E20}")

INTERFACE IAMTimelineSplittable $IID_IAMTimelineSplittable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SplitAt ( _                                   ' VTable offset = 12
     BYVAL Time AS QUAD _                               ' __in REFERENCE_TIME Time
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SplitAt2 ( _                                  ' VTable offset = 16
     BYVAL Time AS DOUBLE _                             ' __in REFTIME Time
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineSplittable_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineTrans
' IID = {BCE0C265-622D-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineTrans_INTERFACE_DEFINED)
    %IAMTimelineTrans_INTERFACE_DEFINED = 1

$IID_IAMTimelineTrans = GUID$("{BCE0C265-622D-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineTrans $IID_IAMTimelineTrans

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCutPoint ( _                               ' VTable offset = 12
     BYREF pTLTime AS QUAD _                            ' __out REFERENCE_TIME *pTLTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCutPoint2 ( _                              ' VTable offset = 16
     BYREF pTLTime AS DOUBLE _                          ' __out REFTIME *pTLTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCutPoint ( _                               ' VTable offset = 20
     BYVAL TLTime AS QUAD _                             ' __in REFERENCE_TIME TLTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCutPoint2 ( _                              ' VTable offset = 24
     BYVAL TLTime AS DOUBLE _                           ' __in REFTIME TLTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSwapInputs ( _                             ' VTable offset = 28
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSwapInputs ( _                             ' VTable offset = 32
     BYVAL pVal AS LONG _                               ' __in BOOL pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCutsOnly ( _                               ' VTable offset = 36
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCutsOnly ( _                               ' VTable offset = 40
     BYVAL pVal AS LONG _                               ' __in BOOL pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineTrans_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineSrc
' IID = {78530B79-61F9-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineSrc_INTERFACE_DEFINED)
    %IAMTimelineSrc_INTERFACE_DEFINED = 1

$IID_IAMTimelineSrc = GUID$("{78530B79-61F9-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineSrc $IID_IAMTimelineSrc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMediaTimes ( _                             ' VTable offset = 12
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTimes2 ( _                            ' VTable offset = 16
     BYREF pStart AS DOUBLE _                           ' __out REFTIME *pStart
   , BYREF pStop AS DOUBLE _                            ' __out REFTIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyStopTime ( _                            ' VTable offset = 20
     BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyStopTime2 ( _                           ' VTable offset = 24
     BYVAL Stop AS DOUBLE _                             ' __in REFTIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FixMediaTimes ( _                             ' VTable offset = 28
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FixMediaTimes2 ( _                            ' VTable offset = 32
     BYREF pStart AS DOUBLE _                           ' __out REFTIME *pStart
   , BYREF pStop AS DOUBLE _                            ' __out REFTIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTimes ( _                             ' VTable offset = 36
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTimes2 ( _                            ' VTable offset = 40
     BYVAL Start AS DOUBLE _                            ' __in REFTIME Start
   , BYVAL Stop AS DOUBLE _                             ' __in REFTIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaLength ( _                            ' VTable offset = 44
     BYVAL Length AS QUAD _                             ' __in REFERENCE_TIME Length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaLength2 ( _                           ' VTable offset = 48
     BYVAL Length AS DOUBLE _                           ' __in REFTIME Length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaLength ( _                            ' VTable offset = 52
     BYREF pLength AS QUAD _                            ' __out REFERENCE_TIME *pLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaLength2 ( _                           ' VTable offset = 56
     BYREF pLength AS DOUBLE _                          ' __out REFTIME *pLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaName ( _                              ' VTable offset = 60
     BYREF pVal AS WSTRING _                            '  __retval_out BSTR *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaName ( _                              ' VTable offset = 64
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SpliceWithNext ( _                            ' VTable offset = 68
     BYVAL pNext AS IAMTimelineObj _                    ' __in IAMTimelineObj *pNext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamNumber ( _                           ' VTable offset = 72
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamNumber ( _                           ' VTable offset = 76
     BYVAL Val AS LONG _                                ' __in long Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsNormalRate ( _                              ' VTable offset = 80
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultFPS ( _                             ' VTable offset = 84
     BYREF pFPS AS DOUBLE _                             ' __out double *pFPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFPS ( _                             ' VTable offset = 88
     BYVAL FPS AS DOUBLE _                              ' __in double FPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStretchMode ( _                            ' VTable offset = 92
     BYREF pnStretchMode AS LONG _                      ' __out int *pnStretchMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStretchMode ( _                            ' VTable offset = 96
     BYVAL nStretchMode AS LONG _                       ' __in int nStretchMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineSrc_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineTrack
' IID = {EAE58538-622E-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineTrack_INTERFACE_DEFINED)
    %IAMTimelineTrack_INTERFACE_DEFINED = 1

$IID_IAMTimelineTrack = GUID$("{EAE58538-622E-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineTrack $IID_IAMTimelineTrack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SrcAdd ( _                                    ' VTable offset = 12
     BYVAL pSource AS IAMTimelineObj _                  ' __in IAMTimelineObj *pSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextSrc ( _                                ' VTable offset = 16
     BYREF ppSrc AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppSrc
   , BYREF pInOut AS QUAD _                             ' __out REFERENCE_TIME *pInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextSrc2 ( _                               ' VTable offset = 20
     BYREF ppSrc AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppSrc
   , BYREF pInOut AS DOUBLE _                           ' __out REFTIME *pInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveEverythingBy ( _                          ' VTable offset = 24
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL MoveBy AS QUAD _                             ' __in REFERENCE_TIME MoveBy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveEverythingBy2 ( _                         ' VTable offset = 28
     BYVAL Start AS DOUBLE _                            ' __in REFTIME Start
   , BYVAL MoveBy AS DOUBLE _                           ' __in REFTIME MoveBy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourcesCount ( _                           ' VTable offset = 32
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AreYouBlank ( _                               ' VTable offset = 36
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSrcAtTime ( _                              ' VTable offset = 40
     BYREF ppSrc AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppSrc
   , BYVAL Time AS QUAD _                               ' __in REFERENCE_TIME Time
   , BYVAL SearchDirection AS LONG _                    ' __in long SearchDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSrcAtTime2 ( _                             ' VTable offset = 44
     BYREF ppSrc AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppSrc
   , BYVAL Time AS DOUBLE _                             ' __in REFTIME Time
   , BYVAL SearchDirection AS LONG _                    ' __in long SearchDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertSpace ( _                               ' VTable offset = 48
     BYVAL rtStart AS QUAD _                            ' __in REFERENCE_TIME rtStart
   , BYVAL rtEnd AS QUAD _                              ' __in REFERENCE_TIME rtEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertSpace2 ( _                              ' VTable offset = 52
     BYVAL rtStart AS DOUBLE _                          ' __in REFTIME rtStart
   , BYVAL rtEnd AS DOUBLE _                            ' __in REFTIME rtEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ZeroBetween ( _                               ' VTable offset = 56
     BYVAL rtStart AS QUAD _                            ' __in REFERENCE_TIME rtStart
   , BYVAL rtEnd AS QUAD _                              ' __in REFERENCE_TIME rtEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ZeroBetween2 ( _                              ' VTable offset = 60
     BYVAL rtStart AS DOUBLE _                          ' __in REFTIME rtStart
   , BYVAL rtEnd AS DOUBLE _                            ' __in REFTIME rtEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextSrcEx ( _                              ' VTable offset = 64
     BYVAL pLast AS IAMTimelineObj _                    ' __in IAMTimelineObj *pLast
   , BYREF ppNext AS IAMTimelineObj _                   ' __out IAMTimelineObj **ppNext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineTrack_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineVirtualTrack
' IID = {A8ED5F80-C2C7-11D2-8D39-00A0C9441E20}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineVirtualTrack_INTERFACE_DEFINED)
    %IAMTimelineVirtualTrack_INTERFACE_DEFINED = 1

$IID_IAMTimelineVirtualTrack = GUID$("{A8ED5F80-C2C7-11D2-8D39-00A0C9441E20}")

INTERFACE IAMTimelineVirtualTrack $IID_IAMTimelineVirtualTrack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TrackGetPriority ( _                          ' VTable offset = 12
     BYREF pPriority AS LONG _                          ' __out long *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackDirty ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineVirtualTrack_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineComp
' IID = {EAE58536-622E-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineComp_INTERFACE_DEFINED)
    %IAMTimelineComp_INTERFACE_DEFINED = 1

$IID_IAMTimelineComp = GUID$("{EAE58536-622E-11D2-8CAD-00A024580902}")

INTERFACE IAMTimelineComp $IID_IAMTimelineComp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD VTrackInsBefore ( _                           ' VTable offset = 12
     BYVAL pVirtualTrack AS IAMTimelineObj _            ' __in IAMTimelineObj *pVirtualTrack
   , BYVAL Priority AS LONG _                           ' __in long Priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VTrackSwapPriorities ( _                      ' VTable offset = 16
     BYVAL VirtualTrackA AS LONG _                      ' __in long VirtualTrackA
   , BYVAL VirtualTrackB AS LONG _                      ' __in long VirtualTrackB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VTrackGetCount ( _                            ' VTable offset = 20
     BYREF pVal AS LONG _                               ' __out long *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVTrack ( _                                 ' VTable offset = 24
     BYREF ppVirtualTrack AS IAMTimelineObj _           ' __out IAMTimelineObj **ppVirtualTrack
   , BYVAL Which AS LONG _                              ' __in long Which
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfType ( _                            ' VTable offset = 28
     BYREF pVal AS LONG _                               ' __out long *pVal
   , BYREF pValWithComps AS LONG _                      ' __out long *pValWithComps
   , BYVAL MajorType AS LONG _                          ' __in TIMELINE_MAJOR_TYPE MajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecursiveLayerOfType ( _                   ' VTable offset = 32
     BYREF ppVirtualTrack AS IAMTimelineObj _           ' __out IAMTimelineObj **ppVirtualTrack
   , BYVAL WhichLayer AS LONG _                         ' __in long WhichLayer
   , BYVAL Type AS LONG _                               ' __in TIMELINE_MAJOR_TYPE Type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecursiveLayerOfTypeI ( _                  ' VTable offset = 36
     BYREF ppVirtualTrack AS IAMTimelineObj _           ' __out IAMTimelineObj** ppVirtualTrack
   , BYREF pWhichLayer AS LONG _                        ' __out_in long *pWhichLayer
   , BYVAL Type AS LONG _                               ' __in TIMELINE_MAJOR_TYPE Type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextVTrack ( _                             ' VTable offset = 40
     BYVAL ppVirtualTrack AS IAMTimelineObj _           ' __in IAMTimelineObj *pVirtualTrack
   , BYREF ppNextVirtualTrack AS IAMTimelineObj _       ' __out IAMTimelineObj **ppNextVirtualTrack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineComp_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimelineGroup
' IID = {9EED4F00-B8A6-11D2-8023-00C0DF10D434}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimelineGroup_INTERFACE_DEFINED)
    %IAMTimelineGroup_INTERFACE_DEFINED = 1

$IID_IAMTimelineGroup = GUID$("{9EED4F00-B8A6-11D2-8023-00C0DF10D434}")

INTERFACE IAMTimelineGroup $IID_IAMTimelineGroup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTimeline ( _                               ' VTable offset = 12
     BYVAL pTimeline AS IAMTimeline _                   ' __in IAMTimeline *pTimeline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeline ( _                               ' VTable offset = 16
     BYREF ppTimeline AS IAMTimeline _                  ' __out IAMTimeline **ppTimeline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 20
     BYREF pPriority AS LONG _                          ' __out long *pPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaType ( _                              ' VTable offset = 24
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __out AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 28
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __in AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFPS ( _                              ' VTable offset = 32
     BYVAL FPS AS DOUBLE _                              ' __in double FPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFPS ( _                              ' VTable offset = 36
     BYREF pFPS AS DOUBLE _                             ' __out double *pFPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupName ( _                              ' VTable offset = 40
     BYVAL pGroupName AS WSTRING _                      ' __in BSTR pGroupName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupName ( _                              ' VTable offset = 44
     BYREF pGroupName AS WSTRING _                      ' __retval_out BSTR *pGroupName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreviewMode ( _                            ' VTable offset = 48
     BYVAL fPreview AS LONG _                           ' __in BOOL fPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreviewMode ( _                            ' VTable offset = 52
     BYREF pfPreview AS LONG _                          ' __out BOOL *pfPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTypeForVB ( _                         ' VTable offset = 56
     BYVAL Val AS LONG _                                ' __in long Val
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputBuffering ( _                        ' VTable offset = 60
     BYREF pnBuffer AS LONG _                           ' __out int *pnBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputBuffering ( _                        ' VTable offset = 64
     BYVAL nBuffer AS LONG _                            ' __in int nBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSmartRecompressFormat ( _                  ' VTable offset = 68
     BYREF pFormat AS LONG _                            ' __out long *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSmartRecompressFormat ( _                  ' VTable offset = 72
     BYREF ppFormat AS DWORD _                          ' __out long **ppFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSmartRecompressFormatSet ( _                ' VTable offset = 76
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRecompressFormatDirty ( _                   ' VTable offset = 80
     BYREF pVal AS LONG _                               ' __out BOOL *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRecompressFormatDirty ( _                ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecompFormatFromSource ( _                 ' VTable offset = 88
     BYVAL pSource AS IAMTimelineSrc _                  ' __in IAMTimelineSrc *pSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimelineGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimeline
' IID = {78530B74-61F9-11D2-8CAD-00A024580902}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimeline_INTERFACE_DEFINED)
    %IAMTimeline_INTERFACE_DEFINED = 1

$IID_IAMTimeline = GUID$("{78530B74-61F9-11D2-8CAD-00A024580902}")

INTERFACE IAMTimeline $IID_IAMTimeline

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateEmptyNode ( _                           ' VTable offset = 12
     BYREF ppObj AS IAMTimelineObj _                    ' __out IAMTimelineObj **ppObj
   , BYVAL Type AS LONG _                               ' __in TIMELINE_MAJOR_TYPE Type
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddGroup ( _                                  ' VTable offset = 16
     BYVAL pGroup AS IAMTimelineObj _                   ' __in IAMTimelineObj *pGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemGroupFromList ( _                          ' VTable offset = 20
     BYVAL pGroup AS IAMTimelineObj _                   ' __in IAMTimelineObj *pGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroup ( _                                  ' VTable offset = 24
     BYREF ppGroup AS IAMTimelineObj _                  ' __out IAMTimelineObj **ppGroup
   , BYVAL WhichGroup AS LONG _                         ' __in long WhichGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupCount ( _                             ' VTable offset = 28
     BYREF pCount AS LONG _                             ' __out long *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearAllGroups ( _                            ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInsertMode ( _                             ' VTable offset = 36
     BYREF pMode AS LONG _                              ' __out long *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInsertMode ( _                             ' VTable offset = 40
     BYVAL Mode AS LONG _                               ' __in long Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableTransitions ( _                         ' VTable offset = 44
     BYVAL fEnabled AS LONG _                           ' __in BOOL fEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TransitionsEnabled ( _                        ' VTable offset = 48
     BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableEffects ( _                             ' VTable offset = 52
     BYVAL fEnabled AS LONG _                           ' __in BOOL fEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EffectsEnabled ( _                            ' VTable offset = 56
     BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterestRange ( _                          ' VTable offset = 60
     BYVAL Start AS QUAD _                              ' __in REFERENCE_TIME Start
   , BYVAL Stop AS QUAD _                               ' __in REFERENCE_TIME Stop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 64
     BYREF pDuration AS QUAD _                          ' __out REFERENCE_TIME *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration2 ( _                              ' VTable offset = 68
     BYREF pDuration AS DOUBLE _                        ' __out double *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFPS ( _                             ' VTable offset = 72
     BYVAL FPS AS DOUBLE _                              ' __in double FPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultFPS ( _                             ' VTable offset = 76
     BYREF pFPS AS DOUBLE _                             ' __out double *pFPS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 80
     BYREF pDirty AS LONG _                             ' __out BOOL *pDirty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirtyRange ( _                             ' VTable offset = 84
     BYREF pStart AS QUAD _                             ' __out REFERENCE_TIME *pStart
   , BYREF pStop AS QUAD _                              ' __out REFERENCE_TIME *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCountOfType ( _                            ' VTable offset = 88
     BYVAL Group AS LONG _                              ' __in  long Group
   , BYREF pVal AS LONG _                               ' __out long *pVal
   , BYREF pValWithComps AS LONG _                      ' __out long *pValWithComps
   , BYVAL MajorType AS LONG _                          ' __in  TIMELINE_MAJOR_TYPE MajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateSourceNames ( _                       ' VTable offset = 92
     BYVAL ValidateFlags AS LONG _                      ' __in long ValidateFlags
   , BYVAL pOverride AS IMediaLocator _                 ' __in IMediaLocator *pOverride
   , BYVAL NotifyEventHandle AS LONG _                  ' __in LONG_PTR NotifyEventHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultTransition ( _                      ' VTable offset = 96
     BYREF pGuid AS GUID _                              ' __in GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultTransition ( _                      ' VTable offset = 100
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultEffect ( _                          ' VTable offset = 104
     BYREF pGuid AS GUID _                              ' __in GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultEffect ( _                          ' VTable offset = 108
     BYREF pGuid AS GUID _                              ' __out GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultTransitionB ( _                     ' VTable offset = 112
     BYVAL pGuid AS WSTRING _                           ' __in BSTR pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultTransitionB ( _                     ' VTable offset = 116
     BYREF pGuid AS WSTRING _                           ' __retval_out BSTR *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultEffectB ( _                         ' VTable offset = 120
     BYVAL pGuid AS WSTRING _                           ' __in BSTR pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultEffectB ( _                         ' VTable offset = 124
     BYREF pGuid AS WSTRING _                           ' __retval_out BSTR *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimeline_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXml2Dex
' IID = {18C628ED-962A-11D2-8D08-00A0C9441E20}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IXml2Dex_INTERFACE_DEFINED)
    %IXml2Dex_INTERFACE_DEFINED = 1

$IID_IXml2Dex = GUID$("{18C628ED-962A-11D2-8D08-00A0C9441E20}")

INTERFACE IXml2Dex $IID_IXml2Dex

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateGraphFromFile <1> ( _                   ' VTable offset = 28
     BYREF ppGraph AS IUnknown _                        ' __out IUnknown **ppGraph
   , BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteGrfFile <2> ( _                          ' VTable offset = 32
     BYVAL pGraph AS IUnknown _                         ' __in IUnknown *pGraph
   , BYVAL Filename AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteXMLFile <3> ( _                          ' VTable offset = 36
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL Filename AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadXMLFile <5> ( _                           ' VTable offset = 40
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL XMLName AS WSTRING _                         ' __in BSTR XMLName
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <6> ( _                                ' VTable offset = 44
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL dStart AS DOUBLE _                           ' __in double dStart
   , BYVAL dEnd AS DOUBLE _                             ' __in double dEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteXMLPart <7> ( _                          ' VTable offset = 48
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL dStart AS DOUBLE _                           ' __in double dStart
   , BYVAL dEnd AS DOUBLE _                             ' __in double dEnd
   , BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD PasteXMLFile <8> ( _                          ' VTable offset = 52
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL dStart AS DOUBLE _                           ' __in double dStart
   , BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyXML <9> ( _                               ' VTable offset = 56
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL dStart AS DOUBLE _                           ' __in double dStart
   , BYVAL dEnd AS DOUBLE _                             ' __in double dEnd
   )                                                    ' void
   ' =====================================================================================
   METHOD PasteXML <10> ( _                             ' VTable offset = 60
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL dStart AS DOUBLE _                           ' __in double dStart
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <11> ( _                                ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD ReadXML <12> ( _                              ' VTable offset = 68
     BYVAL pTimeline AS IUnknown _                      ' __in IUnknown *pTimeline
   , BYVAL pXML AS IUnknown _                           ' __in IUnknown *pXML
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteXML <13> ( _                             ' VTable offset = 72
     BYVAL pTimeline AS IUnknown _                      ' __in  IUnknown *pTimeline
   , BYREF pbstrXML AS WSTRING _                        ' __out BSTR *pbstrXML
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXml2Dex_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMErrorLog
' IID = {E43E73A2-0EFA-11D3-9601-00A0C9441E20}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMErrorLog_INTERFACE_DEFINED)
    %IAMErrorLog_INTERFACE_DEFINED = 1

$IID_IAMErrorLog = GUID$("{E43E73A2-0EFA-11D3-9601-00A0C9441E20}")

INTERFACE IAMErrorLog $IID_IAMErrorLog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LogError ( _                                  ' VTable offset = 12
     BYVAL Severity AS LONG _                           ' __in long Severity
   , BYVAL pErrorString AS WSTRING _                    ' __in BSTR pErrorString
   , BYVAL ErrorCode AS LONG _                          ' __in long ErrorCode
   , BYVAL hresult AS LONG _                            ' __in long hresult
   , BYREF pExtraInfo AS VARIANT _                      ' __in VARIANT *pExtraInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMErrorLog_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMSetErrorLog
' IID = {963566DA-BE21-4EAF-88E9-35704F8F52A1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMSetErrorLog_INTERFACE_DEFINED)
    %IAMSetErrorLog_INTERFACE_DEFINED = 1

$IID_IAMSetErrorLog = GUID$("{963566DA-BE21-4EAF-88E9-35704F8F52A1}")

INTERFACE IAMSetErrorLog $IID_IAMSetErrorLog

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ErrorLog ( _                            ' VTable offset = 12
   ) AS IAMErrorLog                                     ' __retval_out IAMErrorLog **pVal
   ' =====================================================================================
   PROPERTY SET ErrorLog ( _                            ' VTable offset = 16
     BYVAL newVal AS IAMErrorLog _                      ' __in IAMErrorLog *newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMSetErrorLog_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISampleGrabberCB
' IID = {0579154A-2B53-4994-B0D0-E773148EFF85}
' ISampleGrabberCB Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISampleGrabberCB_INTERFACE_DEFINED)
    %ISampleGrabberCB_INTERFACE_DEFINED = 1

$IID_ISampleGrabberCB = GUID$("{0579154A-2B53-4994-B0D0-E773148EFF85}")

INTERFACE ISampleGrabberCB $IID_ISampleGrabberCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SampleCB ( _                                  ' VTable offset = 12
     BYVAL SampleTime AS DOUBLE _                       ' __in double SampleTime
   , BYVAL pSample AS IMediaSample _                    ' __in IMediaSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BufferCB ( _                                  ' VTable offset = 16
     BYVAL SampleTime AS DOUBLE _                       ' __in double SampleTime
   , BYVAL pBuffer AS BYTE PTR _                        ' __in_out BYTE *pBuffer
   , BYVAL BufferLen AS LONG _                          ' __in long BufferLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISampleGrabberCB_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISampleGrabber
' IID = {6B652FFF-11FE-4FCE-92AD-0266B5D7C78F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISampleGrabber_INTERFACE_DEFINED)
    %ISampleGrabber_INTERFACE_DEFINED = 1

$IID_ISampleGrabber = GUID$("{6B652FFF-11FE-4FCE-92AD-0266B5D7C78F}")

INTERFACE ISampleGrabber $IID_ISampleGrabber

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOneShot ( _                                ' VTable offset = 12
     BYVAL OneShot AS LONG _                            ' __in BOOL OneShot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 16
     BYREF pType AS AM_MEDIA_TYPE _                     ' __in const AM_MEDIA_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectedMediaType ( _                     ' VTable offset = 20
     BYREF pType AS AM_MEDIA_TYPE _                     ' __out AM_MEDIA_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferSamples ( _                          ' VTable offset = 24
     BYVAL BufferThem AS LONG _                         ' __in BOOL BufferThem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentBuffer ( _                          ' VTable offset = 28
     BYREF pBufferSize AS LONG _                        ' __in_out long *pBufferSize
   , BYREF pBuffer AS LONG _                            ' __out long *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSample ( _                          ' VTable offset = 32
     BYREF ppSample AS IMediaSample _                   ' __retval_out IMediaSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallback ( _                               ' VTable offset = 36
     BYVAL pCallback AS ISampleGrabberCB _              ' __in ISampleGrabberCB *pCallback
   , BYVAL WhichMethodToCallback AS LONG _              ' __in long WhichMethodToCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISampleGrabber_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IResize
' IID = {4ADA63A0-72D5-11D2-952A-0060081840BC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResize_INTERFACE_DEFINED)
    %IResize_INTERFACE_DEFINED = 1

$IID_IResize = GUID$("{4ADA63A0-72D5-11D2-952A-0060081840BC}")

INTERFACE IResize $IID_IResize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Size ( _                                  ' VTable offset = 12
     BYREF piHeight AS LONG _                           ' __out int *piHeight
   , BYREF piWidth AS LONG _                            ' __out int *piWidth
   , BYREF pFlag AS LONG _                              ' __out long *pFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InputSize ( _                             ' VTable offset = 16
     BYREF piHeight AS LONG _                           ' __out int *piHeight
   , BYREF piWidth AS LONG _                            ' __out int *piWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Size ( _                                  ' VTable offset = 20
     BYVAL Height AS LONG _                             ' __in int Height
   , BYVAL Width AS LONG _                              ' __in int Width
   , BYVAL Flag AS LONG _                               ' __in long Flag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MediaType ( _                             ' VTable offset = 24
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __out AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MediaType ( _                             ' VTable offset = 28
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __in const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResize_INTERFACE_DEFINED__ */
