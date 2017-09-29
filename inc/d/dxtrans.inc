' ########################################################################################
' Microsoft Windows
' File: dxtrans.inc
' Library name: DXTRANSLib
' Version: 1.1, Locale ID = 0
' Library GUID: {54314D1D-35FE-11D1-81A1-0000F87557DB}
' Path: C:\WINDOWS\system32\Dxtrans.dll
' Contents: Microsoft DirectX Transforms Core Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXTRANS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "comcat.inc"

#INCLUDE ONCE "servprov.inc"
#INCLUDE ONCE "ddraw.inc"
'#include <d3d.h>
'#include <d3drm.h>
#INCLUDE ONCE "urlmon.inc"

$LIBID_DXTRANSLib = GUID$("{54314D1D-35FE-11D1-81A1-0000F87557DB}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {385A91BC-1E8A-4E4A-A7A6-F4FC1E6CA1BD}
$PROGID_ObjectMicrosoftDXTFilter1 = "Object.Microsoft.DXTFilter.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {385A91BC-1E8A-4E4A-A7A6-F4FC1E6CA1BD}
$PROGID_ObjectMicrosoftDXTFilter = "Object.Microsoft.DXTFilter"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_DXGradient = GUID$("{C6365470-F667-11D1-9067-00C04FD9189D}")
$CLSID_DXSurface = GUID$("{0E890F83-5F79-11D1-9043-00C04FD9189D}")
$CLSID_DXSurfaceModifier = GUID$("{3E669F1D-9C23-11D1-9053-00C04FD9189D}")
$CLSID_DXTaskManager = GUID$("{4CB26C03-FF93-11D0-817E-0000F87557DB}")
$CLSID_DXTransformFactory = GUID$("{D1FE6762-FC48-11D0-883A-3C8B00C10000}")
$CLSID_DXTScale = GUID$("{555278E2-05DB-11D1-883A-3C8B00C10000}")
$CLSID_DXTFilter = GUID$("{385A91BC-1E8A-4E4A-A7A6-F4FC1E6CA1BD}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICSSFilterDispatch = GUID$("{9519152B-9484-4A6C-B6A7-4F25E92D6C6B}")
$IID_IDXBaseObject = GUID$("{17B59B2B-9CC8-11D1-9053-00C04FD9189D}")
$IID_IDXDCLock = GUID$("{0F619456-CF39-11D1-905E-00C04FD9189D}")
$IID_IDXGradient = GUID$("{B2024B51-EE77-11D1-9066-00C04FD9189D}")
$IID_IDXLookupTable = GUID$("{01BAFC7F-9E63-11D1-9053-00C04FD9189D}")
$IID_IDXSurface = GUID$("{B39FD73F-E139-11D1-9065-00C04FD9189D}")
$IID_IDXSurfaceFactory = GUID$("{144946F5-C4D4-11D1-81D1-0000F87557DB}")
$IID_IDXSurfaceModifier = GUID$("{9EA3B637-C37D-11D1-905E-00C04FD9189D}")
$IID_IDXTaskManager = GUID$("{254DBBC1-F922-11D0-883A-3C8B00C10000}")
$IID_IDXTransform = GUID$("{30A5FB78-E11F-11D1-9064-00C04FD9189D}")
$IID_IDXTransformFactory = GUID$("{6A950B2B-A971-11D1-81C8-0000F87557DB}")
$IID_IDXTScale = GUID$("{B39FD742-E139-11D1-9065-00C04FD9189D}")
$IID_IDXTScaleOutput = GUID$("{B2024B50-EE77-11D1-9066-00C04FD9189D}")

$IID_IDXSurfacePick = GUID$("{30A5FB79-E11F-11d1-9064-00C04FD9189D}")
$IID_IDXTBindHost = GUID$("{D26BCE55-E9DC-11d1-9066-00C04FD9189D}")
$IID_IDXSurfaceInit = GUID$("{9EA3B639-C37D-11d1-905E-00C04FD9189D}")
$IID_IDXARGBSurfaceInit = GUID$("{9EA3B63A-C37D-11d1-905E-00C04FD9189D}")
$IID_IDXARGBReadPtr = GUID$("{EAAAC2D6-C290-11d1-905D-00C04FD9189D}")
$IID_IDXARGBReadWritePtr = GUID$("{EAAAC2D7-C290-11d1-905D-00C04FD9189D}")
$IID_IDXEffect = GUID$("{E31FB81B-1335-11D1-8189-0000F87557DB}")
$IID_IDXRawSurface = GUID$("{09756C8A-D96A-11d1-9062-00C04FD9189D}")
$IID_IHTMLDXTransform = GUID$("{30E2AB7D-4FDD-4159-B7EA-DC722BF4ADE5}")

'//
'//   All GUIDs for DXTransform are declared in DXTGUID.C in the SDK include directory
'//
$DDPF_RGB1 = GUID$("{e436eb78-524f-11ce-9f53-0020af0ba770}")
$DDPF_RGB2 = GUID$("{BBF7D3F3-143F-11d1-B50A-0000F8756A10}")
$DDPF_RGB4 = GUID$("{e436eb79-524f-11ce-9f53-0020af0ba770}")
$DDPF_RGB8 = GUID$("{e436eb7a-524f-11ce-9f53-0020af0ba770}")
$DDPF_RGB332 = GUID$("{BBF7D3F6-143F-11d1-B50A-0000F8756A10}")
$DDPF_ARGB4444 = GUID$("{BBF7D3F7-143F-11d1-B50A-0000F8756A10}")
$DDPF_RGB565 = GUID$("{e436eb7b-524f-11ce-9f53-0020af0ba770}")
$DDPF_BGR565 = GUID$("{BBF7D3F9-143F-11d1-B50A-0000F8756A10}")
$DDPF_RGB555 = GUID$("{e436eb7c-524f-11ce-9f53-0020af0ba770}")
$DDPF_ARGB1555 = GUID$("{BBF7D3FB-143F-11d1-B50A-0000F8756A10}")
$DDPF_RGB24 = GUID$("{e436eb7d-524f-11ce-9f53-0020af0ba770}")
$DDPF_BGR24 = GUID$("{BBF7D3FD-143F-11d1-B50A-0000F8756A10}")
$DDPF_RGB32 = GUID$("{e436eb7e-524f-11ce-9f53-0020af0ba770}")
$DDPF_BGR32 = GUID$("{BBF7D3FF-143F-11d1-B50A-0000F8756A10}")
$DDPF_ABGR32 = GUID$("{BBF7D401-143F-11d1-B50A-0000F8756A10}")
$DDPF_ARGB32 = GUID$("{773c9ac0-3274-11d0-B724-00aa006c1A01}")
$DDPF_PMARGB32 = GUID$("{BBF7D403-143F-11d1-B50A-0000F8756A10}")
$DDPF_A1 = GUID$("{7846F94E-3915-11d1-99AA-0000F8756A10}")
$DDPF_A2 = GUID$("{7846F94F-3915-11d1-99AA-0000F8756A10}")
$DDPF_A4 = GUID$("{7846F950-3915-11d1-99AA-0000F8756A10}")
$DDPF_A8 = GUID$("{7846F951-3915-11d1-99AA-0000F8756A10}")
$DDPF_Z8 = GUID$("{7846F952-3915-11d1-99AA-0000F8756A10}")
$DDPF_Z16 = GUID$("{7846F953-3915-11d1-99AA-0000F8756A10}")
$DDPF_Z24 = GUID$("{7846F954-3915-11d1-99AA-0000F8756A10}")
$DDPF_Z32 = GUID$("{7846F955-3915-11d1-99AA-0000F8756A10}")

'//
'//   Component categories
'//
$CATID_DXImageTransform = GUID$("{C501EDBE-9E70-11d1-9053-00C04FD9189D}")
$CATID_DX3DTransform = GUID$("{C501EDBF-9E70-11d1-9053-00C04FD9189D}")
$CATID_DXAuthoringTransform = GUID$("{ACAC94FC-E5CF-11d1-9066-00C04FD9189D}")
$CATID_DXSurface = GUID$("{52BA7097-B52C-11d1-81CB-0000F87557DB}")

'//
'//   Service IDs
'//
$SID_SDirectDraw = GUID$("{618f8ad4-8b7a-11d0-8fcc-00004fd9189d}")
$SID_SDirect3DRM = GUID$("{2bc49361-8327-11cf-ac4a-0000c03825a1}")

'#define SID_SDXTaskManager CLSID_DXTaskManager
$SID_SDXTaskManager = $CLSID_DXTaskManager
'#define SID_SDXSurfaceFactory IID_IDXSurfaceFactory
$SID_SDXSurfaceFactory = $IID_IDXSurfaceFactory
'#define SID_SDXTransformFactory IID_IDXTransformFactory
$SID_SDXTransformFactory = $IID_IDXTransformFactory

'//
'//   DXTransforms Core Type Library Version Info
'//
%DXTRANS_TLB_MAJOR_VER = 1
%DXTRANS_TLB_MINOR_VER = 1


' ########################################################################################
' Interface name = IDXBaseObject
' IID = {17B59B2B-9CC8-11D1-9053-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXBaseObject_INTERFACE_DEFINED)
    %IDXBaseObject_INTERFACE_DEFINED = 1

INTERFACE IDXBaseObject $IID_IDXBaseObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGenerationId ( _                           ' VTable offset = 12
     BYREF pID AS DWORD _                               ' __out ULONG *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncrementGenerationId ( _                     ' VTable offset = 16
     BYVAL bRefresh AS LONG _                           ' __in BOOL bRefresh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectSize ( _                             ' VTable offset = 20
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXBaseObject_INTERFACE_DEFINED__ */


' enum DXBNDID
%DXB_X   = 0
%DXB_Y   = 1
%DXB_Z   = 2
%DXB_T   = 3

' enum DXBNDTYPE
%DXBT_DISCRETE     = 0
%DXBT_DISCRETE64   = %DXBT_DISCRETE + 1
%DXBT_CONTINUOUS   = %DXBT_DISCRETE64 + 1
%DXBT_CONTINUOUS64 = %DXBT_CONTINUOUS + 1

' // Size = 8 bytes
TYPE DXDBND DWORD
   Min AS LONG   ' long
   Max AS LONG   ' long
END TYPE

'typedef DXDBND DXDBNDS[ 4 ];

' // Size = 16 bytes
TYPE DXDBND64 QWORD
   Min AS QUAD   ' LONGLONG
   Max AS QUAD   ' LONGLONG
END TYPE

'typedef DXDBND64 DXDBNDS64[ 4 ];

' // Size = 8 bytes
TYPE DXCBND DWORD
   Min AS SINGLE   ' float
   Max AS SINGLE   ' float
END TYPE

'typedef DXCBND DXCBNDS[ 4 ];

' // Size = 16 bytes
TYPE DXCBND64 QWORD
   Min AS DOUBLE   ' double
   Max AS DOUBLE   ' double
END TYPE

'typedef DXCBND64 DXCBNDS64[ 4 ];

' // Size = 64 bytes
UNION DXBNDS_UNION
   D  (3) AS DXDBND     ' DXDBND D[ 4 ]
   LD (3) AS DXDBND64   ' DXDBND64 LD[ 4 ]
   C  (3) AS DXCBND     ' DXCBND C[ 4 ]
   LC (3) AS DXCBND64   ' DXCBND64 LC[ 4 ]
END UNION

' // Size = 72 bytes
TYPE DXBNDS QWORD FILL
   eType AS LONG   ' DXBNDTYPE <enum>
   DXBNDS_UNION
END TYPE

'typedef long DXDVEC[ 4 ];
'typedef LONGLONG DXDVEC64[ 4 ];
'typedef float DXCVEC[ 4 ];
'typedef double DXCVEC64[ 4 ];

' // Size = 32 bytes
UNION DXVEC_UNION
   D  (3) AS LONG     ' long D[ 4 ]
   LD (3) AS QUAD     ' LONGLONG LD[ 4 ]
   C  (3) AS SINGLE   ' float C[ 4 ]
   LC (3) AS DOUBLE   ' double LC[ 4 ]
END UNION

' // Size = 40 bytes
TYPE DXVEC QWORD FILL
   eType AS LONG   ' DXBNDTYPE <enum>
   DXVEC_UNION
END TYPE


' ########################################################################################
' Interface name = IDXTransformFactory
' IID = {6A950B2B-A971-11D1-81C8-0000F87557DB}
' Inherited interface = IServiceProvider
' ########################################################################################

#IF NOT %DEF(%IDXTransformFactory_INTERFACE_DEFINED)
    %IDXTransformFactory_INTERFACE_DEFINED = 1

INTERFACE IDXTransformFactory $IID_IDXTransformFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryService ( _                              ' VTable offset = 12
     BYREF guidService AS GUID _                                       ' __in REFGUID guidService
   , BYREF riid AS GUID _                                       ' __in REFIID riid
   , BYREF ppv AS IUnknown _                                   ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetService ( _                                ' VTable offset = 16
     BYREF guidService AS GUID _                                       ' __in REFGUID guidService
   , BYVAL pUnkService AS IUnknown _                                   ' __in IUnknown *pUnkService
   , BYVAL bWeakReference AS LONG _                                       ' __in BOOL bWeakReference
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTransform ( _                           ' VTable offset = 20
     BYREF punkInputs AS IUnknown _                     ' __in IUnknown **punkInputs
   , BYVAL ulNumInputs AS DWORD _                       ' __in ULONG ulNumInputs
   , BYREF punkOutputs AS IUnknown _                    ' __in IUnknown **punkOutputs
   , BYVAL ulNumOutputs AS DWORD _                      ' __in ULONG ulNumOutputs
   , BYVAL pInitProps AS IPropertyBag _                 ' __in IPropertyBag *pInitProps
   , BYVAL pErrLog AS IErrorLog _                       ' __in IErrorLog *pErrLog
   , BYREF TransCLSID AS GUID _                         ' __in REFCLSID TransCLSID
   , BYREF TransIID AS GUID _                           ' __in REFIID TransIID
   , BYREF ppTransform AS IUnknown _                    ' __out void **ppTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeTransform ( _                       ' VTable offset = 24
     BYVAL pTransform AS IDXTransform _                 ' __in IDXTransform *pTransform
   , BYREF punkInputs AS IUnknown _                     ' __in IUnknown **punkInputs
   , BYVAL ulNumInputs AS DWORD _                       ' __in ULONG ulNumInputs
   , BYREF punkOutputs AS IUnknown _                    ' __in IUnknown **punkOutputs
   , BYVAL ulNumOutputs AS DWORD _                      ' __in ULONG ulNumOutputs
   , BYVAL pInitProps AS IPropertyBag _                 ' __in IPropertyBag *pInitProps
   , BYVAL pErrLog AS IErrorLog _                       ' __in IErrorLog *pErrLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTransformFactory_INTERFACE_DEFINED__ */


' enum DXTMISCFLAGS
%DXTMF_BLEND_WITH_OUTPUT   = &H1???          ' 1L << 0
%DXTMF_DITHER_OUTPUT       = &H2???          ' 1L << 1
%DXTMF_OPTION_MASK         = &Hffff
%DXTMF_VALID_OPTIONS       = %DXTMF_BLEND_WITH_OUTPUT OR %DXTMF_DITHER_OUTPUT
%DXTMF_BLEND_SUPPORTED     = &H10000???      ' 1L << 16
%DXTMF_DITHER_SUPPORTED    = &H20000???      ' 1L << 17
%DXTMF_INPLACE_OPERATION   = &H1000000???    ' 1L << 24
%DXTMF_BOUNDS_SUPPORTED    = &H2000000???    ' 1L << 25
%DXTMF_PLACEMENT_SUPPORTED = &H4000000???    ' 1L << 26
%DXTMF_QUALITY_SUPPORTED   = &H8000000???    ' 1L << 27
%DXTMF_OPAQUE_RESULT       = &H10000000???   ' 1L << 28

' enum DXINOUTINFOFLAGS
%DXINOUTF_OPTIONAL   = &H1???   ' 1L << 0


' ########################################################################################
' Interface name = IDXTransform
' IID = {30A5FB78-E11F-11D1-9064-00C04FD9189D}
' Inherited interface = IDXBaseObject
' ########################################################################################

#IF NOT %DEF(%IDXTransform_INTERFACE_DEFINED)
    %IDXTransform_INTERFACE_DEFINED = 1

INTERFACE IDXTransform $IID_IDXTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGenerationId ( _                           ' VTable offset = 12
     BYREF pID AS DWORD _                               ' __out ULONG *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncrementGenerationId ( _                     ' VTable offset = 16
     BYVAL bRefresh AS LONG _                           ' __in BOOL bRefresh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectSize ( _                             ' VTable offset = 20
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Setup ( _                                     ' VTable offset = 24
     BYREF punkInputs AS IUnknown _                     ' __in IUnknown *const *punkInputs
   , BYVAL ulNumInputs AS DWORD _                       ' __in ULONG ulNumInputs
   , BYREF punkOutputs AS IUnknown _                    ' __in IUnknown *const *punkOutputs
   , BYVAL ulNumOutputs AS DWORD _                      ' __in ULONG ulNumOutputs
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 28
     BYREF pRequestID AS GUID _                         ' __in const GUID *pRequestID
   , BYREF pClipBnds AS DXBNDS _                        ' __in const DXBNDS *pClipBnds
   , BYREF pPlacement AS DXVEC _                        ' __in const DXVEC *pPlacement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapBoundsIn2Out ( _                           ' VTable offset = 32
     BYREF pInBounds AS DXBNDS _                        ' __in const DXBNDS *pInBounds
   , BYVAL ulNumInBnds AS DWORD _                       ' __in ULONG ulNumInBnds
   , BYVAL ulOutIndex AS DWORD _                        ' __in ULONG ulOutIndex
   , BYREF pOutBounds AS DXBNDS _                       ' __out DXBNDS *pOutBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapBoundsOut2In ( _                           ' VTable offset = 36
     BYVAL ulOutIndex AS DWORD _                        ' __in ULONG ulOutIndex
   , BYREF pOutBounds AS DXBNDS _                       ' __in const DXBNDS *pOutBounds
   , BYVAL ulInIndex AS DWORD _                         ' __in ULONG ulInIndex
   , BYREF pInBounds AS DXBNDS _                        ' __out DXBNDS *pInBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMiscFlags ( _                              ' VTable offset = 40
     BYVAL dwMiscFlags AS DWORD _                       ' __in DWORD dwMiscFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMiscFlags ( _                              ' VTable offset = 44
     BYREF pdwMiscFlags AS DWORD _                      ' __out DWORD *pdwMiscFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInOutInfo ( _                              ' VTable offset = 48
     BYVAL bIsOutput AS LONG _                          ' __in BOOL bIsOutput
   , BYVAL ulIndex AS DWORD _                           ' __in ULONG ulIndex
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF pIDs AS GUID _                               ' __out GUID *pIDs
   , BYREF pcIDs AS DWORD _                             ' __inout ULONG *pcIDs
   , BYREF ppUnkCurrentObject AS IUnknown _             ' __out IUnknown **ppUnkCurrentObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQuality ( _                                ' VTable offset = 52
     BYVAL fQuality AS SINGLE _                         ' __in float fQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQuality ( _                                ' VTable offset = 56
     BYREF fQuality AS SINGLE _                         ' __out float *fQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTransform_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXSurfacePick
' IID = {30A5FB79-E11F-11d1-9064-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXSurfacePick_INTERFACE_DEFINED)
    %IDXSurfacePick_INTERFACE_DEFINED = 1

INTERFACE IDXSurfacePick $IID_IDXSurfacePick

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PointPick ( _                                 ' VTable offset = 12
     BYREF pPoint AS DXVEC _                            ' __in const DXVEC *pPoint
   , BYREF pulInputSurfaceIndex AS DWORD _              ' __out ULONG *pulInputSurfaceIndex
   , BYREF pInputPoint AS DXVEC _                       ' __out DXVEC *pInputPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXSurfacePick_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXTBindHost
' IID = {D26BCE55-E9DC-11d1-9066-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXTBindHost_INTERFACE_DEFINED)
    %IDXTBindHost_INTERFACE_DEFINED = 1

INTERFACE IDXTBindHost $IID_IDXTBindHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBindHost ( _                               ' VTable offset = 12
     BYVAL pBindHost AS IBindHost _                     ' __in IBindHost *pBindHost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTBindHost_INTERFACE_DEFINED__ */


'typedef void __stdcall __stdcall DXTASKPROC(
'    void *pTaskData,
'    BOOL *pbContinueProcessing);

'typedef DXTASKPROC *PFNDXTASKPROC;

'typedef void __stdcall __stdcall DXAPCPROC(
'    DWORD dwData);

'typedef DXAPCPROC *PFNDXAPCPROC;

' // Size = 20 bytes
TYPE DXTMTASKINFO DWORD
   pfnTaskProc      AS DWORD      ' PFNDXTASKPROC // Pointer to function to execute
   pTaskData        AS DWORD      ' PVOID         // Pointer to argument data
   pfnCompletionAPC AS DWORD      ' PFNDXAPCPROC  // Pointer to completion APC proc
   dwCompletionData AS DWORD      ' DWORD         // Pointer to APC proc data
   pRequestID       AS GUID PTR   ' const GUID*   // Used to identify groups of tasks
END TYPE


' ########################################################################################
' Interface name = IDXTaskManager
' IID = {254DBBC1-F922-11D0-883A-3C8B00C10000}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXTaskManager_INTERFACE_DEFINED)
    %IDXTaskManager_INTERFACE_DEFINED = 1

INTERFACE IDXTaskManager $IID_IDXTaskManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryNumProcessors ( _                        ' VTable offset = 12
     BYREF pulNumProc AS DWORD _                        ' __out ULONG *pulNumProc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThreadPoolSize ( _                         ' VTable offset = 16
     BYVAL ulNumThreads AS DWORD _                      ' __in ULONG ulNumThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThreadPoolSize ( _                         ' VTable offset = 20
     BYREF pulNumThreads AS DWORD _                     ' __out ULONG *pulNumThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConcurrencyLimit ( _                       ' VTable offset = 24
     BYVAL ulNumThreads AS DWORD _                      ' __in ULONG ulNumThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConcurrencyLimit ( _                       ' VTable offset = 28
     BYREF pulNumThreads AS DWORD _                     ' __out ULONG *pulNumThreads
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScheduleTasks ( _                             ' VTable offset = 32
     BYREF TaskInfo AS DXTMTASKINFO _                   ' __in DXTMTASKINFO TaskInfo[  ]
   , BYVAL Events AS DWORD _                            ' __in HANDLE Events[  ]
   , BYREF TaskIDs AS DWORD _                           ' __out DWORD TaskIDs[  ]
   , BYVAL ulNumTasks AS DWORD _                        ' __in ULONG ulNumTasks
   , BYVAL ulWaitPeriod AS DWORD _                      ' __in ULONG ulWaitPeriod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TerminateTasks ( _                            ' VTable offset = 36
     BYREF TaskIDs AS DWORD _                           ' __in DWORD TaskIDs[  ]
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL ulTimeOut AS DWORD _                         ' __in ULONG ulTimeOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TerminateRequest ( _                          ' VTable offset = 40
     BYREF RequestID AS GUID _                          ' __in REFIID RequestID
   , BYVAL ulTimeOut AS DWORD _                         ' __in ULONG ulTimeOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTaskManager_INTERFACE_DEFINED__ */


' // Size = 4 bytes
TYPE DXBASESAMPLE BYTE
   Blue  AS BYTE
   Green AS BYTE
   Red   AS BYTE
   Alpha AS BYTE
END TYPE

' // Size = 4 bytes
TYPE DXSAMPLE BYTE
   Blue  AS BYTE
   Green AS BYTE
   Red   AS BYTE
   Alpha AS BYTE
END TYPE

' // Size = 4 bytes
TYPE DXPMSAMPLE BYTE
   Blue  AS BYTE
   Green AS BYTE
   Red   AS BYTE
   Alpha AS BYTE
END TYPE

' enum DXRUNTYPE
%DXRUNTYPE_CLEAR   = 0
%DXRUNTYPE_OPAQUE  = 1
%DXRUNTYPE_TRANS   = 2
%DXRUNTYPE_UNKNOWN = 3

%DX_MAX_RUN_INFO_COUNT = 128

'typedef struct DXRUNINFO
'{
'    ULONG   Type  : 2;   // Type
'    ULONG   Count : 30;  // Number of samples in run
'} DXRUNINFO;

' // Size = 4 bytes
TYPE DXRUNINFO DWORD
   Type  AS BIT * 2 IN DWORD
   Count AS BIT * 30
END TYPE

' enum DXSFCREATE
%DXSF_FORMAT_IS_CLSID    = &H1???   ' 1L << 0
%DXSF_NO_LAZY_DDRAW_LOCK = &H2???   ' 1L << 1

' enum DXBLTOPTIONS
%DXBOF_DO_OVER = &H1???   ' 1L << 0
%DXBOF_DITHER  = &H2???   ' 1L << 1


' ########################################################################################
' Interface name = IDXSurfaceFactory
' IID = {144946F5-C4D4-11D1-81D1-0000F87557DB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXSurfaceFactory_INTERFACE_DEFINED)
   %IDXSurfaceFactory_INTERFACE_DEFINED = 1

INTERFACE IDXSurfaceFactory $IID_IDXSurfaceFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 12
     BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL punkOuter AS IUnknown _                      ' __in IUnknown *punkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDXSurface AS IUnknown _                    ' __out void **ppDXSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFromDDSurface ( _                       ' VTable offset = 16
     BYVAL pDDrawSurface AS IUnknown _                  ' __in IUnknown *pDDrawSurface
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL punkOuter AS IUnknown _                      ' __in IUnknown *punkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDXSurface AS IUnknown _                    ' __out void **ppDXSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadImage ( _                                 ' VTable offset = 20
     BYREF pszFileName AS WSTRINGZ _                    ' __in const LPWSTR pszFileName
   , BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDXSurface AS IUnknown _                    ' __out void **ppDXSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadImageFromStream ( _                       ' VTable offset = 24
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppDXSurface AS IUnknown _                    ' __out void **ppDXSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopySurfaceToNewFormat ( _                    ' VTable offset = 28
     BYVAL pSrc AS IDXSurface _                         ' __in IDXSurface *pSrc
   , BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pDestFormatID AS GUID _                      ' __in const GUID *pDestFormatID
   , BYREF ppNewSurface AS IDXSurface _                 ' __out IDXSurface **ppNewSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateD3DRMTexture ( _                        ' VTable offset = 32
     BYVAL pSrc AS IDXSurface _                         ' __in IDXSurface *pSrc
   , BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYVAL pD3DRM3 AS IUnknown _                        ' __in IUnknown *pD3DRM3
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppTexture3 AS IUnknown _                     ' __out void **ppTexture3
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BitBlt ( _                                    ' VTable offset = 36
     BYVAL pDest AS IDXSurface _                        ' __in IDXSurface *pDest
   , BYREF pPlacement AS DXVEC _                        ' __in const DXVEC *pPlacement
   , BYVAL pSrc AS IDXSurface _                         ' __in IDXSurface *pSrc
   , BYREF pClipBounds AS DXBNDS _                      ' __in const DXBNDS *pClipBounds
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXSurfaceFactory_INTERFACE_DEFINED__ */


' enum DXSURFMODCOMPOP
%DXSURFMOD_COMP_OVER       = 0
%DXSURFMOD_COMP_ALPHA_MASK = 1
%DXSURFMOD_COMP_MAX_VALID  = 1


' ########################################################################################
' Interface name = IDXSurfaceModifier
' IID = {9EA3B637-C37D-11D1-905E-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXSurfaceModifier_INTERFACE_DEFINED)
    %IDXSurfaceModifier_INTERFACE_DEFINED = 1

INTERFACE IDXSurfaceModifier $IID_IDXSurfaceModifier

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFillColor ( _                              ' VTable offset = 12
     BYVAL Color AS DXSAMPLE _                          ' __in DXSAMPLE Color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFillColor ( _                              ' VTable offset = 16
     BYREF pColor AS DXSAMPLE _                         ' __out DXSAMPLE *pColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBounds ( _                                 ' VTable offset = 20
     BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackground ( _                             ' VTable offset = 24
     BYVAL pSurface AS IDXSurface _                     ' __in IDXSurface *pSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackground ( _                             ' VTable offset = 28
     BYREF ppSurface AS IDXSurface _                    ' __out IDXSurface **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositeOperation ( _                     ' VTable offset = 32
     BYVAL CompOp AS LONG _                             ' __in DXSURFMODCOMPOP CompOp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositeOperation ( _                     ' VTable offset = 36
     BYREF pCompOp AS LONG _                            ' __out DXSURFMODCOMPOP *pCompOp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetForeground ( _                             ' VTable offset = 40
     BYVAL pSurface AS IDXSurface _                     ' __in IDXSurface *pSurface
   , BYVAL bTile AS LONG _                              ' __in BOOL bTile
   , BYREF pOrigin AS POINT _                           ' __in const POINT *pOrigin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForeground ( _                             ' VTable offset = 44
     BYREF ppSurface AS IDXSurface _                    ' __out IDXSurface **ppSurface
   , BYREF pbTile AS LONG _                             ' __out BOOL *pbTile
   , BYREF pOrigin AS POINT _                           ' __out POINT *pOrigin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpacity ( _                                ' VTable offset = 48
     BYVAL Opacity AS SINGLE _                          ' __in float Opacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpacity ( _                                ' VTable offset = 52
     BYREF pOpacity AS SINGLE _                         ' __out float *pOpacity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLookup ( _                                 ' VTable offset = 56
     BYVAL pLookupTable AS IDXLookupTable _             ' __in IDXLookupTable *pLookupTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLookup ( _                                 ' VTable offset = 60
     BYREF ppLookupTable AS IDXLookupTable _            ' __out IDXLookupTable **ppLookupTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXSurfaceModifier_INTERFACE_DEFINED__ */

%DXPF_FLAGSMASK    = &HFFFF0000???
%DXPF_NONPREMULT   = &H10000???
%DXPF_TRANSPARENCY = &H20000???
%DXPF_TRANSLUCENCY = &H40000???
%DXPF_2BITERROR    = &H200000???
%DXPF_3BITERROR    = &H300000???
%DXPF_4BITERROR    = &H400000???
%DXPF_5BITERROR    = &H500000???
%DXPF_ERRORMASK    = &H700000???
%DXPF_NONSTANDARD  = 0???
%DXPF_PMARGB32     = 1 OR %DXPF_TRANSPARENCY OR %DXPF_TRANSLUCENCY
%DXPF_ARGB32       = 2 OR %DXPF_NONPREMULT OR %DXPF_TRANSPARENCY OR %DXPF_TRANSLUCENCY
%DXPF_ARGB4444     = 3 OR %DXPF_NONPREMULT OR %DXPF_TRANSPARENCY OR %DXPF_TRANSLUCENCY OR %DXPF_4BITERROR
%DXPF_A8           = 4 OR %DXPF_TRANSPARENCY OR %DXPF_TRANSLUCENCY
%DXPF_RGB32        = 5???
%DXPF_RGB24        = 6???
%DXPF_RGB565       = 7 OR %DXPF_3BITERROR
%DXPF_RGB555       = 8 OR %DXPF_3BITERROR
%DXPF_RGB8         = 9 OR %DXPF_5BITERROR
%DXPF_ARGB1555     = 10 OR %DXPF_TRANSPARENCY OR %DXPF_3BITERROR
%DXPF_RGB32_CK     = %DXPF_RGB32 OR %DXPF_TRANSPARENCY
%DXPF_RGB24_CK     = %DXPF_RGB24 OR %DXPF_TRANSPARENCY
%DXPF_RGB555_CK    = %DXPF_RGB555 OR %DXPF_TRANSPARENCY
%DXPF_RGB565_CK    = %DXPF_RGB565 OR %DXPF_TRANSPARENCY
%DXPF_RGB8_CK      = %DXPF_RGB8 OR %DXPF_TRANSPARENCY

' enum DXLOCKSURF
%DXLOCKF_READ             = 0
%DXLOCKF_READWRITE        = &H1       ' 1 << 0
%DXLOCKF_EXISTINGINFOONLY = &H2       ' 1 << 1
%DXLOCKF_WANTRUNINFO      = &H4       ' 1 << 2
%DXLOCKF_NONPREMULT       = &H10000   ' 1 << 16
%DXLOCKF_VALIDFLAGS       = %DXLOCKF_READWRITE OR %DXLOCKF_EXISTINGINFOONLY OR %DXLOCKF_WANTRUNINFO OR %DXLOCKF_NONPREMULT

' enum DXSURFSTATUS
%DXSURF_TRANSIENT  = &H1   ' 1 << 0
%DXSURF_READONLY   = &H2   ' 1 << 1
%DXSURF_VALIDFLAGS = %DXSURF_TRANSIENT OR %DXSURF_READONLY


' ########################################################################################
' Interface name = IDXSurface
' IID = {B39FD73F-E139-11D1-9065-00C04FD9189D}
' Inherited interface = IDXBaseObject
' ########################################################################################

#IF NOT %DEF(%IDXSurface_INTERFACE_DEFINED)
   %IDXSurface_INTERFACE_DEFINED = 1

INTERFACE IDXSurface $IID_IDXSurface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGenerationId ( _                           ' VTable offset = 12
     BYREF pID AS DWORD _                               ' __out ULONG *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncrementGenerationId ( _                     ' VTable offset = 16
     BYVAL bRefresh AS LONG _                           ' __in BOOL bRefresh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectSize ( _                             ' VTable offset = 20
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 24
     BYREF pFormatID AS GUID _                          ' __out GUID *pFormatID
   , BYREF pSampleFormatEnum AS LONG _                  ' __out DXSAMPLEFORMATENUM *pSampleFormatEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBounds ( _                                 ' VTable offset = 28
     BYREF pBounds AS DXBNDS _                          ' __out DXBNDS *pBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusFlags ( _                            ' VTable offset = 32
     BYREF pdwStatusFlags AS DWORD _                    ' __out DWORD *pdwStatusFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusFlags ( _                            ' VTable offset = 36
     BYVAL dwStatusFlags AS DWORD _                     ' __in DWORD dwStatusFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockSurface ( _                               ' VTable offset = 40
     BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   , BYVAL ulTimeOut AS DWORD _                         ' __in ULONG ulTimeOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppPointer AS IUnknown _                      ' __out void **ppPointer
   , BYREF pulGenerationId AS DWORD _                   ' __out ULONG *pulGenerationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectDrawSurface ( _                      ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSurface AS IUnknown _                      ' __out void **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 48
     BYREF pColorKey AS DXSAMPLE _                      ' __out DXSAMPLE *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 52
     BYVAL ColorKey AS DXSAMPLE _                       ' __in DXSAMPLE ColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockSurfaceDC ( _                             ' VTable offset = 56
     BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   , BYVAL ulTimeOut AS DWORD _                         ' __in ULONG ulTimeOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppDCLock AS IDXDCLock _                      ' __out IDXDCLock **ppDCLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppData ( _                                ' VTable offset = 60
     BYVAL dwAppData AS DWORD _                         ' __in DWORD_PTR dwAppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppData ( _                                ' VTable offset = 64
     BYREF pdwAppData AS DWORD _                        ' __out DWORD_PTR *pdwAppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXSurface_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXSurfaceInit
' IID = {9EA3B639-C37D-11d1-905E-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#If NOT %DEF(%IDXSurfaceInit_INTERFACE_DEFINED)
    %IDXSurfaceInit_INTERFACE_DEFINED = 1

INTERFACE IDXSurfaceInit $IID_IDXSurfaceInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitSurface ( _                               ' VTable offset = 12
     BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXSurfaceInit_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXARGBSurfaceInit
' IID = {9EA3B63A-C37D-11d1-905E-00C04FD9189D}
' Inherited interface = IDXSurfaceInit
' ########################################################################################

#IF NOT %DEF(%IDXARGBSurfaceInit_INTERFACE_DEFINED)
    %IDXARGBSurfaceInit_INTERFACE_DEFINED = 1

INTERFACE IDXARGBSurfaceInit $IID_IDXARGBSurfaceInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitSurface ( _                               ' VTable offset = 12
     BYVAL pDirectDraw AS IUnknown _                    ' __in IUnknown *pDirectDraw
   , BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYREF pBounds AS DXBNDS _                          ' __in const DXBNDS *pBounds
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitFromDDSurface ( _                         ' VTable offset = 16
     BYVAL pDDrawSurface AS IUnknown _                  ' __in IUnknown *pDDrawSurface
   , BYREF pFormatID AS GUID _                          ' __in const GUID *pFormatID
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitFromRawSurface ( _                        ' VTable offset = 20
     BYVAL pRawSurface AS IDXRawSurface _               ' __in IDXRawSurface *pRawSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXARGBSurfaceInit_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE DXNATIVETYPEINFO DWORD
   pCurrentData AS BYTE PTR   ' BYTE *
   pFirstByte   AS BYTE PTR   ' BYTE *
   lPitch       AS LONG       ' long
   dwColorKey   AS DWORD      ' DWORD
END TYPE

' // Size = 28 bytes
TYPE DXPACKEDRECTDESC DWORD
   pSamples    AS DXBASESAMPLE PTR   ' DXBASESAMPLE *
   bPremult    AS LONG               ' BOOL
   rect        AS RECT               ' RECT
   lRowPadding AS LONG               ' long
END TYPE

' // Size = 12 bytes
TYPE DXOVERSAMPLEDESC DWORD
   p     AS POINT        ' POINT
   Color AS DXPMSAMPLE   ' DXPMSAMPLE
END TYPE


' ########################################################################################
' Interface name = IDXARGBReadPtr
' IID = {EAAAC2D6-C290-11d1-905D-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXARGBReadPtr_INTERFACE_DEFINED)
    %IDXARGBReadPtr_INTERFACE_DEFINED = 1

INTERFACE IDXARGBReadPtr $IID_IDXARGBReadPtr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSurface AS IUnknown _                      ' __out void **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeType ( _                             ' VTable offset = 16
     BYREF pInfo AS DXNATIVETYPEINFO _                  ' __out DXNATIVETYPEINFO *pInfo
   ) AS LONG                                            ' DXSAMPLEFORMATENUM
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 20
     BYVAL cSamples AS LONG _                           ' __in long cSamples
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveToRow ( _                                 ' VTable offset = 24
     BYVAL y AS DWORD _                                 ' __in ULONG y
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveToXY ( _                                  ' VTable offset = 28
     BYVAL x AS DWORD _                                 ' __in ULONG x
   , BYVAL y AS DWORD _                                 ' __in ULONG y
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveAndGetRunInfo ( _                         ' VTable offset = 32
     BYVAL Row AS DWORD _                               ' __in ULONG Row
   , BYREF ppInfo AS DXRUNINFO _                        ' __out const DXRUNINFO **ppInfo
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================
   METHOD Unpack ( _                                    ' VTable offset = 36
     BYVAL pSamples AS DXSAMPLE _                       ' __in DXSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bMove AS LONG _                              ' __in BOOL bMove
   ) AS DXSAMPLE                                        ' DXSAMPLE *
   ' =====================================================================================
   METHOD UnpackPremult ( _                             ' VTable offset = 40
     BYVAL pSamples AS DXPMSAMPLE _                     ' __in DXPMSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bMove AS LONG _                              ' __in BOOL bMove
   ) AS DXPMSAMPLE                                      ' DXPMSAMPLE *
   ' =====================================================================================
   METHOD UnpackRect ( _                                ' VTable offset = 44
     BYREF pRectDesc AS DXPACKEDRECTDESC _              ' __in const DXPACKEDRECTDESC *pRectDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXARGBReadPtr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXARGBReadWritePtr
' IID = {EAAAC2D7-C290-11d1-905D-00C04FD9189D}
' Inherited interface = IDXARGBReadPtr
' ########################################################################################

#IF NOT %DEF(%IDXARGBReadWritePtr_INTERFACE_DEFINED)
    %IDXARGBReadWritePtr_INTERFACE_DEFINED = 1

INTERFACE IDXARGBReadWritePtr $IID_IDXARGBReadWritePtr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppSurface AS IUnknown _                      ' __out void **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeType ( _                             ' VTable offset = 16
     BYREF pInfo AS DXNATIVETYPEINFO _                  ' __out DXNATIVETYPEINFO *pInfo
   ) AS LONG                                            ' DXSAMPLEFORMATENUM
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 20
     BYVAL cSamples AS LONG _                           ' __in long cSamples
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveToRow ( _                                 ' VTable offset = 24
     BYVAL y AS DWORD _                                 ' __in ULONG y
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveToXY ( _                                  ' VTable offset = 28
     BYVAL x AS DWORD _                                 ' __in ULONG x
   , BYVAL y AS DWORD _                                 ' __in ULONG y
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveAndGetRunInfo ( _                         ' VTable offset = 32
     BYVAL Row AS DWORD _                               ' __in ULONG Row
   , BYREF ppInfo AS DXRUNINFO _                        ' __out const DXRUNINFO **ppInfo
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================
   METHOD Unpack ( _                                    ' VTable offset = 36
     BYVAL pSamples AS DXSAMPLE _                       ' __in DXSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bMove AS LONG _                              ' __in BOOL bMove
   ) AS DXSAMPLE                                        ' DXSAMPLE *
   ' =====================================================================================
   METHOD UnpackPremult ( _                             ' VTable offset = 40
     BYVAL pSamples AS DXPMSAMPLE _                     ' __in DXPMSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bMove AS LONG _                              ' __in BOOL bMove
   ) AS DXPMSAMPLE                                      ' DXPMSAMPLE *
   ' =====================================================================================
   METHOD UnpackRect ( _                                ' VTable offset = 44
     BYREF pRectDesc AS DXPACKEDRECTDESC _              ' __in const DXPACKEDRECTDESC *pRectDesc
   )                                                    ' void
   ' =====================================================================================
   METHOD PackAndMove ( _                               ' VTable offset = 48
     BYVAL pSamples AS DXSAMPLE _                       ' __in const DXSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   )                                                    ' void
   ' =====================================================================================
   METHOD PackPremultAndMove ( _                        ' VTable offset = 52
     BYVAL pSamples AS DXPMSAMPLE _                     ' __in const DXPMSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   )                                                    ' void
   ' =====================================================================================
   METHOD PackRect ( _                                  ' VTable offset = 56
     BYREF pRectDesc AS DXPACKEDRECTDESC _              ' __in const DXPACKEDRECTDESC *pRectDesc
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyAndMoveBoth ( _                           ' VTable offset = 60
     BYVAL pScratchBuffer AS DXBASESAMPLE _             ' __in DXBASESAMPLE *pScratchBuffer
   , BYVAL pSrc AS IDXARGBReadPtr _                     ' __in IDXARGBReadPtr *pSrc
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bIsOpaque AS LONG _                          ' __in BOOL bIsOpaque
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyRect ( _                                  ' VTable offset = 64
     BYVAL pScratchBuffer AS DXBASESAMPLE _             ' __in DXBASESAMPLE *pScratchBuffer
   , BYREF pDestRect AS RECT _                          ' __in const RECT *pDestRect
   , BYVAL pSrc AS IDXARGBReadPtr _                     ' __in IDXARGBReadPtr *pSrc
   , BYREF pSrcOrigin AS POINT _                        ' __in const POINT *pSrcOrigin
   , BYVAL bIsOpaque AS LONG _                          ' __in BOOL bIsOpaque
   )                                                    ' void
   ' =====================================================================================
   METHOD FillAndMove ( _                               ' VTable offset = 68
     BYVAL pScratchBuffer AS DXBASESAMPLE _             ' __in DXBASESAMPLE *pScratchBuffer
   , BYVAL SampVal AS DXPMSAMPLE _                      ' __in DXPMSAMPLE SampVal
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   , BYVAL bDoOver AS LONG _                            ' __in BOOL bDoOver
   )                                                    ' void
   ' =====================================================================================
   METHOD FillRect ( _                                  ' VTable offset = 72
     BYREF pRect AS RECT _                              ' __in const RECT *pRect
   , BYVAL SampVal AS DXPMSAMPLE _                      ' __in DXPMSAMPLE SampVal
   , BYVAL bDoOver AS LONG _                            ' __in BOOL bDoOver
   )                                                    ' void
   ' =====================================================================================
   METHOD OverSample ( _                                ' VTable offset = 76
     BYREF pOverDesc AS DXOVERSAMPLEDESC _              ' __in const DXOVERSAMPLEDESC *pOverDesc
   )                                                    ' void
   ' =====================================================================================
   METHOD OverArrayAndMove ( _                          ' VTable offset = 80
     BYVAL pScratchBuffer AS DXBASESAMPLE _             ' __in DXBASESAMPLE *pScratchBuffer
   , BYVAL pSrc AS DXPMSAMPLE _                         ' __in const DXPMSAMPLE *pSrc
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXARGBReadWritePtr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXDCLock
' IID = {0F619456-CF39-11D1-905E-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXDCLock_INTERFACE_DEFINED)
    %IDXDCLock_INTERFACE_DEFINED = 1

INTERFACE IDXDCLock $IID_IDXDCLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 12
   ) AS DWORD                                           ' HDC
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXDCLock_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXTScaleOutput
' IID = {B2024B50-EE77-11D1-9066-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXTScaleOutput_INTERFACE_DEFINED)
    %IDXTScaleOutput_INTERFACE_DEFINED = 1

INTERFACE IDXTScaleOutput $IID_IDXTScaleOutput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOutputSize ( _                             ' VTable offset = 12
     BYVAL OutSize AS SIZE _                            ' __in const SIZE OutSize
   , BYVAL bMaintainAspect AS LONG _                    ' __in BOOL bMaintainAspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTScaleOutput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXGradient
' IID = {B2024B51-EE77-11D1-9066-00C04FD9189D}
' Inherited interface = IDXTScaleOutput
' ########################################################################################

#IF NOT %DEF(%IDXGradient_INTERFACE_DEFINED)
    %IDXGradient_INTERFACE_DEFINED = 1

INTERFACE IDXGradient $IID_IDXGradient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOutputSize ( _                             ' VTable offset = 12
     BYVAL OutSize AS SIZE _                            ' __in const SIZE OutSize
   , BYVAL bMaintainAspect AS LONG _                    ' __in BOOL bMaintainAspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGradient ( _                               ' VTable offset = 16
     BYVAL StartColor AS DXSAMPLE _                     ' __in DXSAMPLE StartColor
   , BYVAL EndColor AS DXSAMPLE _                       ' __in DXSAMPLE EndColor
   , BYVAL bHorizontal AS LONG _                        ' __in BOOL bHorizontal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputSize ( _                             ' VTable offset = 20
     BYREF pOutSize AS SIZE _                           ' __out SIZE *pOutSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXGradient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXTScale
' IID = {B39FD742-E139-11D1-9065-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXTScale_INTERFACE_DEFINED)
    %IDXTScale_INTERFACE_DEFINED = 1

INTERFACE IDXTScale $IID_IDXTScale

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetScales ( _                                 ' VTable offset = 12
     BYREF Scales AS SINGLE _                           ' __in float Scales[ 2 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScales ( _                                 ' VTable offset = 16
     BYREF Scales AS SINGLE _                           ' __out float Scales[ 2 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleFitToSize ( _                            ' VTable offset = 20
     BYREF pClipBounds AS DXBNDS _                      ' __inout DXBNDS *pClipBounds
   , BYREF FitToSize AS SIZE _                          ' __in SIZE FitToSize
   , BYVAL bMaintainAspect AS LONG _                    ' __in BOOL bMaintainAspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXTScale_INTERFACE_DEFINED__ */


' enum DISPIDDXEFFECT
%DISPID_DXECAPABILITIES = 10000
%DISPID_DXEPROGRESS     = %DISPID_DXECAPABILITIES + 1
%DISPID_DXESTEP         = %DISPID_DXEPROGRESS     + 1
%DISPID_DXEDURATION     = %DISPID_DXESTEP         + 1
%DISPID_DXE_NEXT_ID     = %DISPID_DXEDURATION     + 1

' enum DXEFFECTTYPE
%DXTET_PERIODIC = &H1   ' 1 << 0
%DXTET_MORPH    = &H2   ' 1 << 1


' ########################################################################################
' Interface name = IDXEffect
' IID = {E31FB81B-1335-11D1-8189-0000F87557DB}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDXEffect_INTERFACE_DEFINED)
    %IDXEffect_INTERFACE_DEFINED = 1

INTERFACE IDXEffect $IID_IDXEffect

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Capabilities <10000> ( _                ' VTable offset = 28
   ) AS LONG                                            ' long *pVal
   ' =====================================================================================
   PROPERTY GET Progress <10001> ( _                    ' VTable offset = 32
   ) AS SINGLE                                          ' float *pVal
   ' =====================================================================================
   PROPERTY SET Progress <10001> ( _                    ' VTable offset = 36
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StepResolution <10002> ( _              ' VTable offset = 40
   ) AS SINGLE                                          ' float *pVal
   ' =====================================================================================
   PROPERTY GET Duration <10003> ( _                    ' VTable offset = 44
   ) AS SINGLE                                          ' float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <10003> ( _                    ' VTable offset = 48
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXEffect_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDXLookupTable
' IID = {01BAFC7F-9E63-11D1-9053-00C04FD9189D}
' Inherited interface = IDXBaseObject
' ########################################################################################

#IF NOT %DEF(%IDXLookupTable_INTERFACE_DEFINED)
    %IDXLookupTable_INTERFACE_DEFINED = 1

INTERFACE IDXLookupTable $IID_IDXLookupTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGenerationId ( _                           ' VTable offset = 12
     BYREF pID AS DWORD _                               ' __out ULONG *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncrementGenerationId ( _                     ' VTable offset = 16
     BYVAL bRefresh AS LONG _                           ' __in BOOL bRefresh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectSize ( _                             ' VTable offset = 20
     BYREF pcbSize AS DWORD _                           ' __out ULONG *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTables ( _                                 ' VTable offset = 24
     BYREF RedLUT AS BYTE _                             ' __out BYTE RedLUT[ 256 ]
   , BYREF GreenLUT AS BYTE _                           ' __out BYTE GreenLUT[ 256 ]
   , BYREF BlueLUT AS BYTE _                            ' __out BYTE BlueLUT[ 256 ]
   , BYREF AlphaLUT AS BYTE _                           ' __out BYTE AlphaLUT[ 256 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsChannelIdentity ( _                         ' VTable offset = 28
     BYREF pSampleBools AS DXBASESAMPLE _               ' __out DXBASESAMPLE *pSampleBools
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexValues ( _                            ' VTable offset = 32
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF pSample AS DXBASESAMPLE _                    ' __out DXBASESAMPLE *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyTables ( _                               ' VTable offset = 36
     BYREF pSamples AS DXSAMPLE _                       ' __inout DXSAMPLE *pSamples
   , BYVAL cSamples AS DWORD _                          ' __in ULONG cSamples
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXLookupTable_INTERFACE_DEFINED__ */


' // Size = 32 bytes
TYPE DXRAWSURFACEINFO DWORD
   pFirstByte   AS BYTE PTR           ' BYTE *
   lPitch       AS LONG               ' long
   Width        AS DWORD              ' ULONG
   Height       AS DWORD              ' ULONG
   pPixelFormat AS GUID PTR           ' const GUID *
   hdc          AS DWORD              ' HDC
   dwColorKey   AS DWORD              ' DWORD
   pPalette     AS DXBASESAMPLE PTR   ' DXBASESAMPLE *
END TYPE


' ########################################################################################
' Interface name = IDXRawSurface
' IID = {09756C8A-D96A-11d1-9062-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXRawSurface_INTERFACE_DEFINED)
    %IDXRawSurface_INTERFACE_DEFINED = 1

INTERFACE IDXRawSurface $IID_IDXRawSurface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurfaceInfo ( _                            ' VTable offset = 12
     BYREF pSurfaceInfo AS DXRAWSURFACEINFO _           ' __out DXRAWSURFACEINFO *pSurfaceInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXRawSurface_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IHTMLDXTransform
' IID = {30E2AB7D-4FDD-4159-B7EA-DC722BF4ADE5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHTMLDXTransform_INTERFACE_DEFINED)
    %IHTMLDXTransform_INTERFACE_DEFINED = 1

INTERFACE IHTMLDXTransform $IID_IHTMLDXTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHostUrl ( _                                ' VTable offset = 12
     BYVAL bstrHostUrl AS WSTRING _                     ' __in BSTR bstrHostUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHTMLDXTransform_INTERFACE_DEFINED__ */


' enum DXTFILTER_STATUS
%DXTFILTER_STATUS_Stopped = 0
%DXTFILTER_STATUS_Applied = %DXTFILTER_STATUS_Stopped + 1
%DXTFILTER_STATUS_Playing = %DXTFILTER_STATUS_Applied + 1
%DXTFILTER_STATUS_MAX     = %DXTFILTER_STATUS_Playing + 1

' enum DXTFILTER_DISPID
%DISPID_DXTFilter_Percent  = 1
%DISPID_DXTFilter_Duration = %DISPID_DXTFilter_Percent  + 1
%DISPID_DXTFilter_Enabled  = %DISPID_DXTFilter_Duration + 1
%DISPID_DXTFilter_Status   = %DISPID_DXTFilter_Enabled  + 1
%DISPID_DXTFilter_Apply    = %DISPID_DXTFilter_Status   + 1
%DISPID_DXTFilter_Play     = %DISPID_DXTFilter_Apply    + 1
%DISPID_DXTFilter_Stop     = %DISPID_DXTFilter_Play     + 1
%DISPID_DXTFilter_MAX      = %DISPID_DXTFilter_Stop     + 1


' ########################################################################################
' Interface name = ICSSFilterDispatch
' IID = {9519152B-9484-4A6C-B6A7-4F25E92D6C6B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICSSFilterDispatch_INTERFACE_DEFINED)
    %ICSSFilterDispatch_INTERFACE_DEFINED = 1

INTERFACE ICSSFilterDispatch $IID_ICSSFilterDispatch

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Percent <1> ( _                         ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Percent <1> ( _                         ' VTable offset = 32
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Duration <2> ( _                        ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float *pVal
   ' =====================================================================================
   PROPERTY SET Duration <2> ( _                        ' VTable offset = 40
     BYVAL newVal AS SINGLE _                           ' __in float newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <3> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfVal
   ' =====================================================================================
   PROPERTY SET Enabled <3> ( _                         ' VTable offset = 48
     BYVAL fVal AS INTEGER _                            ' __in VARIANT_BOOL fVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <4> ( _                          ' VTable offset = 52
   ) AS LONG                                            ' __retval_out DXTFILTER_STATUS *peVal
   ' =====================================================================================
   METHOD Apply <5> ( _                                 ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD Play <6> ( _                                  ' VTable offset = 60
     OPTIONAL BYVAL varDuration AS VARIANT _            ' __opt_in VARIANT varDuration
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <7> ( _                                  ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICSSFilterDispatch_INTERFACE_DEFINED__ */
